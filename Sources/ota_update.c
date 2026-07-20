#include <string.h>

#include "ota_boot_confirm.h"
#include "ota_config.h"
#include "ota_crc32.h"
#include "ota_flash.h"
#include "ota_partition.h"
#include "ota_update.h"

typedef struct
{
    bool busy;
    ota_slot_t target;
    ota_image_header_t header;
    uint32_t received_bytes;
    uint32_t programmed_bytes;
    uint32_t running_crc;
    uint32_t staging_bytes;
    uint8_t staging[FLASH_PROGRAM_PAGE_MAX_SIZE];
} ota_update_context_t;

static ota_update_context_t s_update;

_Static_assert(sizeof(ota_image_header_t) == OTA_HEADER_SIZE, "OTA header size mismatch");
_Static_assert((FLASH_PROGRAM_PAGE_MAX_SIZE % PFLASH_PROGRAM_PAGE_MIN_SIZE) == 0U,
               "Flash staging size must be page aligned");

static bool ota_header_basic_ok(const ota_image_header_t *header)
{
    ota_image_header_t tmp;
    uint32_t saved_crc;

    if (header == 0)
    {
        return false;
    }

    if ((header->magic != OTA_IMAGE_MAGIC) ||
        (header->header_version != OTA_IMAGE_HEADER_VERSION) ||
        (header->version == 0UL) ||
        (header->version == 0xFFFFFFFFUL) ||
        (header->version_inverted != (~header->version)) ||
        (header->valid_code_lo != OTA_IMAGE_VALID_CODE_LO) ||
        (header->valid_code_hi != OTA_IMAGE_VALID_CODE_HI) ||
        (header->valid_flag != OTA_IMAGE_VALID_FLAG) ||
        (header->image_size == 0UL) ||
        (header->image_size > OTA_IMAGE_PAYLOAD_MAX_SIZE))
    {
        return false;
    }

    tmp = *header;
    saved_crc = tmp.header_crc32;
    tmp.header_crc32 = 0UL;
    return (saved_crc == ota_crc32_compute(&tmp, sizeof(tmp)));
}

static ota_status_t ota_update_flush_staging(bool finish)
{
    uint32_t write_len;
    ota_status_t status;

    if (s_update.staging_bytes == 0UL)
    {
        return OTA_OK;
    }

    if ((!finish) && (s_update.staging_bytes < sizeof(s_update.staging)))
    {
        return OTA_OK;
    }

    write_len = s_update.staging_bytes;
    if (finish)
    {
        write_len = (write_len + (PFLASH_PROGRAM_PAGE_MIN_SIZE - 1UL)) &
                    ~(PFLASH_PROGRAM_PAGE_MIN_SIZE - 1UL);
        (void)memset(&s_update.staging[s_update.staging_bytes],
                     0xFF,
                     write_len - s_update.staging_bytes);
    }

    status = ota_flash_program(
        s_update.target,
        s_update.programmed_bytes,
        s_update.staging,
        write_len);
    if (status != OTA_OK)
    {
        return status;
    }

    s_update.programmed_bytes += s_update.staging_bytes;
    s_update.staging_bytes = 0UL;
    return OTA_OK;
}

ota_status_t ota_begin_update(const ota_image_header_t *header)
{
    ota_image_header_t active_header;
    ota_slot_t active;
    ota_status_t status;

    if (s_update.busy)
    {
        return OTA_ERR_BUSY;
    }
    if (!ota_is_hardware_ota_enabled())
    {
        return OTA_ERR_NOT_ENABLED;
    }
    if (!ota_header_basic_ok(header))
    {
        return OTA_ERR_INVALID_IMAGE;
    }

    active = ota_get_active_slot();
    if ((ota_read_slot_header(active, &active_header) == OTA_OK) &&
        ota_is_slot_valid(active) &&
        (ota_compare_version(header->version, active_header.version) <= 0))
    {
        return OTA_ERR_VERSION;
    }

    (void)memset(&s_update, 0, sizeof(s_update));
    s_update.target = ota_get_inactive_slot();
    s_update.header = *header;
    s_update.running_crc = ota_crc32_init();

    status = ota_flash_init();
    if (status != OTA_OK)
    {
        return status;
    }

    status = ota_flash_erase_slot(s_update.target);
    if (status != OTA_OK)
    {
        s_update.target = OTA_SLOT_INVALID;
        return status;
    }

    s_update.busy = true;
    return OTA_OK;
}

ota_status_t ota_write_chunk(const void *data, uint32_t len)
{
    const uint8_t *bytes = (const uint8_t *)data;
    uint32_t copy_len;
    uint32_t room;
    ota_status_t status;

    if ((!s_update.busy) || ((data == 0) && (len != 0UL)))
    {
        return OTA_ERR_PARAM;
    }
    if (len > (s_update.header.image_size - s_update.received_bytes))
    {
        return OTA_ERR_RANGE;
    }

    while (len > 0UL)
    {
        room = (uint32_t)sizeof(s_update.staging) - s_update.staging_bytes;
        copy_len = (len < room) ? len : room;
        (void)memcpy(&s_update.staging[s_update.staging_bytes], bytes, copy_len);
        s_update.running_crc = ota_crc32_update(s_update.running_crc, bytes, copy_len);
        s_update.staging_bytes += copy_len;
        s_update.received_bytes += copy_len;
        bytes += copy_len;
        len -= copy_len;

        status = ota_update_flush_staging(false);
        if (status != OTA_OK)
        {
            return status;
        }
    }

    return OTA_OK;
}

ota_status_t ota_finish_update(void)
{
    ota_status_t status;

    if (!s_update.busy)
    {
        return OTA_ERR_PARAM;
    }
    if (s_update.received_bytes != s_update.header.image_size)
    {
        return OTA_ERR_INVALID_IMAGE;
    }
    if (ota_crc32_finish(s_update.running_crc) != s_update.header.image_crc32)
    {
        return OTA_ERR_CRC;
    }

    status = ota_update_flush_staging(true);
    if (status != OTA_OK)
    {
        return status;
    }

    /* Verify programmed payload before exposing a hardware-valid version. */
    status = ota_flash_verify_payload_crc(
        s_update.target,
        s_update.header.image_size,
        s_update.header.image_crc32);
    if (status != OTA_OK)
    {
        return status;
    }

    /* Record pending first; the 16-byte hardware indicator remains the commit. */
    status = ota_mark_pending_for_slot(s_update.target, s_update.header.version);
    if (status != OTA_OK)
    {
        return status;
    }

    status = ota_flash_program_header(s_update.target, &s_update.header);
    if (status != OTA_OK)
    {
        return status;
    }

    (void)memset(&s_update, 0, sizeof(s_update));
    s_update.target = OTA_SLOT_INVALID;
    return OTA_OK;
}

ota_status_t ota_abort_update(void)
{
    if (!s_update.busy)
    {
        return OTA_OK;
    }

    (void)memset(&s_update, 0, sizeof(s_update));
    s_update.target = OTA_SLOT_INVALID;
    return OTA_OK;
}

ota_slot_t ota_update_target_slot(void)
{
    return s_update.target;
}

void ota_update_get_progress(ota_update_progress_t *progress)
{
    if (progress == 0)
    {
        return;
    }

    progress->busy = s_update.busy;
    progress->target_slot = s_update.target;
    progress->image_size = s_update.header.image_size;
    progress->received_bytes = s_update.received_bytes;
    progress->programmed_bytes = s_update.programmed_bytes;
}
