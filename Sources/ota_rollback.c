#include "ota_config.h"
#include "ota_crc32.h"
#include "ota_flash.h"
#include "ota_partition.h"
#include "ota_rollback.h"

static ota_status_t ota_rewrite_inactive_header_version(ota_slot_t target, uint32_t new_version)
{
    ota_image_header_t header;

    if ((ota_read_slot_header(target, &header) != OTA_OK) || (!ota_is_slot_valid(target)))
    {
        return OTA_ERR_INVALID_IMAGE;
    }

    header.version = new_version;
    header.version_inverted = ~new_version;
    header.valid_code_lo = OTA_IMAGE_VALID_CODE_LO;
    header.valid_code_hi = OTA_IMAGE_VALID_CODE_HI;
    header.header_crc32 = 0UL;
    header.header_crc32 = ota_crc32_compute(&header, sizeof(header));

    return ota_flash_program_header(target, &header);
}

ota_status_t ota_request_rollback_by_version_bump(void)
{
    ota_slot_t active = ota_get_active_slot();
    ota_slot_t target = ota_get_inactive_slot();
    ota_image_header_t active_header;

    if (!ota_is_slot_valid(target))
    {
        return OTA_ERR_INVALID_IMAGE;
    }

    if ((ota_read_slot_header(active, &active_header) != OTA_OK) || (!ota_is_slot_valid(active)))
    {
        return OTA_ERR_INVALID_IMAGE;
    }

    /*
     * Hardware OTA chooses by the version word configured in OTAC0[51:32].
     * The rollback target is the non-active valid image, so only its own
     * metadata sector is erased and rewritten with a higher version.
     */
    return ota_rewrite_inactive_header_version(target, active_header.version + 1UL);
}

ota_status_t ota_request_rollback_by_invalidate_active(void)
{
    ota_slot_t target = ota_get_inactive_slot();
    ota_slot_t active = ota_get_active_slot();

    if (!ota_is_slot_valid(target))
    {
        return OTA_ERR_INVALID_IMAGE;
    }

#if OTA_ALLOW_ACTIVE_INVALIDATE
    /*
     * This erases only the active slot metadata sector.  It intentionally does
     * not copy code or exchange version records.  Use it on an engineering
     * bench only after confirming reset/power behavior for the product.
     */
    return ota_flash_erase_header_sector(active, true);
#else
    (void)active;
    return OTA_ERR_NOT_SUPPORTED;
#endif
}

ota_status_t ota_force_switch_by_fmc_register(ota_slot_t target_slot)
{
    uint32_t ctrl;

    if ((target_slot != OTA_SLOT_LOW) && (target_slot != OTA_SLOT_HIGH))
    {
        return OTA_ERR_PARAM;
    }

    if (!ota_is_slot_valid(target_slot))
    {
        return OTA_ERR_INVALID_IMAGE;
    }

    ctrl = ota_get_fmc_ota_ctrl();
    if (!ota_is_hardware_ota_enabled())
    {
        return OTA_ERR_NOT_SUPPORTED;
    }

    if ((ctrl & FMC_OTA_CTRL_OTA_LOCK_MASK) != 0UL)
    {
        return OTA_ERR_LOCKED;
    }

    if (target_slot == OTA_SLOT_HIGH)
    {
        ctrl |= FMC_OTA_CTRL_OTA_ACTIVE_MASK;
    }
    else
    {
        ctrl &= ~FMC_OTA_CTRL_OTA_ACTIVE_MASK;
    }

    /*
     * Runtime active switching is lock-sensitive and may not be persistent
     * across reset depending on the NVR configuration.  Prefer version bump for
     * rollback and reserve this for diagnostics.
     */
    FMC0->OTA_CTRL[0] = ctrl;
    __DSB();
    __ISB();

    return OTA_OK;
}
