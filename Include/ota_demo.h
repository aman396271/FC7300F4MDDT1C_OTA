#ifndef OTA_DEMO_H_
#define OTA_DEMO_H_

#include <stddef.h>
#include <stdint.h>

#include "ota_types.h"

typedef struct
{
    ota_slot_t active_slot;
    ota_slot_t inactive_slot;
    uint32_t fmc_ota_ctrl;
    uint32_t fmc_ota_ver_loc;
    uint32_t fmc_ota_act_ver;
    uint32_t low_version;
    uint32_t high_version;
    uint8_t low_hw_valid;
    uint8_t high_hw_valid;
    uint8_t low_valid;
    uint8_t high_valid;
    uint8_t ota_enabled;
    uint8_t ota_locked;
} ota_demo_info_t;

void ota_demo_init_on_boot(void);
ota_status_t ota_demo_get_info(ota_demo_info_t *info);
ota_status_t ota_demo_install_package(const void *package, uint32_t len);
ota_status_t ota_demo_write_package_half_and_stop(const void *package, uint32_t len);
ota_status_t ota_demo_handle_command(const char *cmd);
void ota_demo_log(const char *msg);

#endif /* OTA_DEMO_H_ */
