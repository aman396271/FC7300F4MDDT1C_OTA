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
    uint32_t header_bytes;
    uint32_t payload_bytes;
    uint32_t running_crc;
} ota_update_context_t;

static ota_update_context_t s_update;

static bool ota_header_basic_ok(const ota_image_header_t *header)
{
    if (header == 0)
    {
        return false;
    }

    if ((header->magic != OTA_IMAGE_MAGIC) ||
        (header->header_version != OTA_IMAGE_HEADER_VERSION) ||
        (header->version_inverted != (~header->version)) ||
        (header->valid_code_lo != OTA_IMAGE_VALID_CODE_LO) ||
        (header->valid_code_hi != OTA_IMAGE_VALID_CODE_HI) ||
        (header->valid_flag != OTA_IMAGE_VALID_FLAG) ||
        (header->image_size == 0UL) ||
        (header->image_size > OTA_IMAGE_PAYLOAD_MAX_SIZE))
    {
        return false;
    }

    return true;
}

static ota_status_t ota_update_accept_payload(const uint8_t *data, uint32_t len)
{
    uint32_t room;

    if (len == 0UL)
    {
        return OTA_OK;
    }

    if (!ota_header_basic_ok(&s_update.header))
    {
        return OTA_ERR_INVALID_IMAGE;
    }

    room = s_update.header.image_size - s_update.payload_bytes;
    if (len > room)
    {
        return OTA_ERR_RANGE;
    }

    if (((s_update.payload_bytes | len) & (PFLASH_PROGRAM_PAGE_MIN_SIZE - 1UL)) != 0UL)
    {
        /*
         * The public demo keeps the stream page-aligned.  A production
         * transport usually adds an internal staging buffer for arbitrary byte
         * counts; keeping this strict makes power-fail behavior easier to see.
         */
        return OTA_ERR_RANGE;
    }

    s_update.running_crc = ota_crc32_update(s_update.running_crc, data, len);
    if (ota_flash_program(s_update.target, s_update.payload_bytes, data, len) != OTA_OK)
    {
        return OTA_ERR_FLASH;
    }

    s_update.payload_bytes += len;
    return OTA_OK;
}

ota_status_t ota_begin_update(void)
{
    ota_status_t status;

    if (s_update.busy)
    {
        return OTA_ERR_BUSY;
    }

    (void)memset(&s_update, 0, sizeof(s_update));
    s_update.target = ota_get_inactive_slot();
    s_update.running_crc = ota_crc32_init();

    status = ota_flash_init();
    if (status != OTA_OK)
    {
        return status;
    }

    status = ota_flash_erase_slot(s_update.target);
    if (status != OTA_OK)
    {
        return status;
    }

    s_update.busy = true;
    return OTA_OK;
}

ota_status_t ota_write_chunk(const void *data, uint32_t len)
{
    const uint8_t *bytes = (const uint8_t *)data;
    uint32_t header_room;
    uint32_t copy_len;

    if ((!s_update.busy) || (data == 0))
    {
        return OTA_ERR_PARAM;
    }

    while (len > 0UL)
    {
        if (s_update.header_bytes < sizeof(s_update.header))
        {
            header_room = (uint32_t)sizeof(s_update.header) - s_update.header_bytes;
            copy_len = (len < header_room) ? len : header_room;
            (void)memcpy(&((uint8_t *)&s_update.header)[s_update.header_bytes], bytes, copy_len);
            s_update.header_bytes += copy_len;
            bytes += copy_len;
            len -= copy_len;

            if ((s_update.header_bytes == sizeof(s_update.header)) &&
                (!ota_header_basic_ok(&s_update.header)))
            {
                return OTA_ERR_INVALID_IMAGE;
            }
        }
        else
        {
            ota_status_t status = ota_update_accept_payload(bytes, len);
            if (status != OTA_OK)
            {
                return status;
            }
            len = 0UL;
        }
    }

    return OTA_OK;
}

ota_status_t ota_finish_update(void)
{
    ota_image_header_t header_to_flash;
    uint32_t saved_header_crc;
    ota_image_header_t active_header;
    ota_status_t status;

    if (!s_update.busy)
    {
        return OTA_ERR_PARAM;
    }

    if (s_update.header_bytes != sizeof(s_update.header))
    {
        return OTA_ERR_INVALID_IMAGE;
    }

    if (s_update.payload_bytes != s_update.header.image_size)
    {
        return OTA_ERR_INVALID_IMAGE;
    }

    if (ota_crc32_finish(s_update.running_crc) != s_update.header.image_crc32)
    {
        return OTA_ERR_CRC;
    }

    if ((ota_read_slot_header(ota_get_active_slot(), &active_header) == OTA_OK) &&
        ota_is_slot_valid(ota_get_active_slot()) &&
        (ota_compare_version(s_update.header.version, active_header.version) <= 0))
    {
        return OTA_ERR_VERSION;
    }

    header_to_flash = s_update.header;
    saved_header_crc = header_to_flash.header_crc32;
    header_to_flash.header_crc32 = 0UL;
    if (saved_header_crc != ota_crc32_compute(&header_to_flash, sizeof(header_to_flash)))
    {
        return OTA_ERR_INVALID_IMAGE;
    }
    header_to_flash.header_crc32 = saved_header_crc;

    /*
     * This is the power-fail boundary.  Until the header/version sector is
     * programmed, the target slot has payload bytes but no valid hardware OTA
     * version word and no valid software header.
     */
    status = ota_flash_program_header(s_update.target, &header_to_flash);
    if (status != OTA_OK)
    {
        return status;
    }

    status = ota_flash_verify_crc(s_update.target);
    if (status != OTA_OK)
    {
        return status;
    }

    status = ota_mark_pending_for_slot(s_update.target, header_to_flash.version);
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
