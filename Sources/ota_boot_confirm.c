#include <string.h>

#include "ota_boot_confirm.h"
#include "ota_config.h"
#include "ota_crc32.h"
#include "ota_flash.h"
#include "ota_partition.h"
#include "ota_rollback.h"

#define OTA_STATE_FLAG_PENDING       (0x50454E44UL) /* "PEND" */
#define OTA_STATE_FLAG_CONFIRMED     (0x434F4E46UL) /* "CONF" */

typedef struct
{
    uint32_t magic;
    uint32_t flag;
    uint32_t slot;
    uint32_t version;
    uint32_t boot_attempts;
    uint32_t crc32;
    uint32_t reserved[10];
} ota_boot_state_t;

static uint32_t ota_state_crc(const ota_boot_state_t *state)
{
    ota_boot_state_t tmp;

    tmp = *state;
    tmp.crc32 = 0UL;
    return ota_crc32_compute(&tmp, sizeof(tmp));
}

static ota_status_t ota_state_read(ota_boot_state_t *state)
{
    if (state == 0)
    {
        return OTA_ERR_PARAM;
    }

    if (ota_dflash_read_state(state, sizeof(*state)) != OTA_OK)
    {
        return OTA_ERR_FLASH;
    }

    if ((state->magic != OTA_STATE_MAGIC) || (state->crc32 != ota_state_crc(state)))
    {
        return OTA_ERR_STATE;
    }

    return OTA_OK;
}

static ota_status_t ota_state_write(ota_boot_state_t *state)
{
    if (state == 0)
    {
        return OTA_ERR_PARAM;
    }

    state->magic = OTA_STATE_MAGIC;
    state->crc32 = ota_state_crc(state);
    return ota_dflash_write_state(state, sizeof(*state));
}

ota_status_t ota_mark_pending_for_slot(ota_slot_t slot, uint32_t version)
{
    ota_boot_state_t state;

    if ((slot != OTA_SLOT_LOW) && (slot != OTA_SLOT_HIGH))
    {
        return OTA_ERR_PARAM;
    }

    (void)memset(&state, 0xFF, sizeof(state));
    state.magic = OTA_STATE_MAGIC;
    state.flag = OTA_STATE_FLAG_PENDING;
    state.slot = (uint32_t)slot;
    state.version = version;
    state.boot_attempts = 0UL;

    return ota_state_write(&state);
}

ota_status_t ota_mark_pending(void)
{
    ota_image_header_t header;
    ota_slot_t active = ota_get_active_slot();

    if ((ota_read_slot_header(active, &header) != OTA_OK) || (!ota_is_slot_valid(active)))
    {
        return OTA_ERR_INVALID_IMAGE;
    }

    return ota_mark_pending_for_slot(active, header.version);
}

ota_status_t ota_mark_confirmed(void)
{
    ota_boot_state_t state;
    ota_image_header_t header;
    ota_slot_t active = ota_get_active_slot();

    if ((ota_read_slot_header(active, &header) != OTA_OK) || (!ota_is_slot_valid(active)))
    {
        return OTA_ERR_INVALID_IMAGE;
    }

    if (ota_state_read(&state) != OTA_OK)
    {
        (void)memset(&state, 0xFF, sizeof(state));
    }

    state.flag = OTA_STATE_FLAG_CONFIRMED;
    state.slot = (uint32_t)active;
    state.version = header.version;
    state.boot_attempts = 0UL;

    return ota_state_write(&state);
}

ota_status_t ota_check_pending_and_rollback(void)
{
    ota_boot_state_t state;
    ota_slot_t active;

    if (ota_state_read(&state) != OTA_OK)
    {
        return OTA_OK;
    }

    if (state.flag != OTA_STATE_FLAG_PENDING)
    {
        return OTA_OK;
    }

    active = ota_get_active_slot();
    if ((ota_slot_t)state.slot != active)
    {
        /*
         * The pending record is stale or the hardware has already selected the
         * other image.  Leave it untouched; a successful self-test can confirm.
         */
        return OTA_OK;
    }

    if (state.boot_attempts == 0UL)
    {
        state.boot_attempts = 1UL;
        return ota_state_write(&state);
    }

    return ota_request_rollback_by_version_bump();
}
