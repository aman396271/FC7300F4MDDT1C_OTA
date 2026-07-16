#include <string.h>

#include "ota_boot_confirm.h"
#include "ota_config.h"
#include "ota_demo.h"
#include "ota_partition.h"
#include "ota_rollback.h"
#include "ota_update.h"

void __attribute__((weak)) ota_demo_log(const char *msg)
{
    (void)msg;
}

static const char *ota_demo_slot_name(ota_slot_t slot)
{
    if (slot == OTA_SLOT_LOW)
    {
        return "LOW";
    }
    if (slot == OTA_SLOT_HIGH)
    {
        return "HIGH";
    }
    return "INVALID";
}

void ota_demo_init_on_boot(void)
{
    ota_status_t status;

    status = ota_check_pending_and_rollback();
    if (status == OTA_OK)
    {
        ota_demo_log("OTA boot check OK");
    }
    else
    {
        ota_demo_log("OTA boot check requested rollback or failed");
    }

    (void)ota_demo_slot_name(ota_get_active_slot());
}

ota_status_t ota_demo_get_info(ota_demo_info_t *info)
{
    ota_image_header_t header;

    if (info == 0)
    {
        return OTA_ERR_PARAM;
    }

    (void)memset(info, 0, sizeof(*info));
    info->active_slot = ota_get_active_slot();
    info->inactive_slot = ota_get_inactive_slot();
    info->fmc_ota_ctrl = ota_get_fmc_ota_ctrl();
    info->fmc_ota_ver_loc = ota_get_fmc_ota_version_location();
    info->fmc_ota_act_ver = ota_get_fmc_ota_active_version();
    info->ota_enabled = ota_is_hardware_ota_enabled() ? 1U : 0U;
    info->ota_locked = ota_is_hardware_ota_locked() ? 1U : 0U;
    info->low_hw_valid = ota_is_slot_hardware_valid(OTA_SLOT_LOW) ? 1U : 0U;
    info->high_hw_valid = ota_is_slot_hardware_valid(OTA_SLOT_HIGH) ? 1U : 0U;
    info->low_valid = ota_is_slot_valid(OTA_SLOT_LOW) ? 1U : 0U;
    info->high_valid = ota_is_slot_valid(OTA_SLOT_HIGH) ? 1U : 0U;

    if (ota_read_slot_header(OTA_SLOT_LOW, &header) == OTA_OK)
    {
        info->low_version = header.version;
    }
    if (ota_read_slot_header(OTA_SLOT_HIGH, &header) == OTA_OK)
    {
        info->high_version = header.version;
    }

    return OTA_OK;
}

ota_status_t ota_demo_install_package(const void *package, uint32_t len)
{
    ota_status_t status;

    status = ota_begin_update();
    if (status != OTA_OK)
    {
        return status;
    }

    status = ota_write_chunk(package, len);
    if (status != OTA_OK)
    {
        (void)ota_abort_update();
        return status;
    }

    return ota_finish_update();
}

ota_status_t ota_demo_write_package_half_and_stop(const void *package, uint32_t len)
{
    ota_status_t status;
    uint32_t half_len;

    status = ota_begin_update();
    if (status != OTA_OK)
    {
        return status;
    }

    half_len = len / 2UL;
    half_len &= ~(PFLASH_PROGRAM_PAGE_MIN_SIZE - 1UL);
    status = ota_write_chunk(package, half_len);

    /*
     * Keep the partially written inactive slot without writing the final header.
     * A real power cut would reset here.  The caller can reset the MCU manually
     * after this function returns.
     */
    return status;
}

ota_status_t ota_demo_handle_command(const char *cmd)
{
    if (cmd == 0)
    {
        return OTA_ERR_PARAM;
    }

    if (strcmp(cmd, "info") == 0)
    {
        ota_demo_info_t info;
        ota_status_t status = ota_demo_get_info(&info);
        if (status == OTA_OK)
        {
            ota_demo_log("OTA info captured");
        }
        return status;
    }

    if (strcmp(cmd, "confirm") == 0)
    {
        return ota_mark_confirmed();
    }

    if (strcmp(cmd, "pending") == 0)
    {
        return ota_mark_pending();
    }

    if (strcmp(cmd, "rollback") == 0)
    {
        return ota_request_rollback_by_version_bump();
    }

    if (strcmp(cmd, "invalidate_active") == 0)
    {
        return ota_request_rollback_by_invalidate_active();
    }

    if (strcmp(cmd, "force_low") == 0)
    {
        return ota_force_switch_by_fmc_register(OTA_SLOT_LOW);
    }

    if (strcmp(cmd, "force_high") == 0)
    {
        return ota_force_switch_by_fmc_register(OTA_SLOT_HIGH);
    }

    return OTA_ERR_PARAM;
}
