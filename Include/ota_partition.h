#ifndef OTA_PARTITION_H_
#define OTA_PARTITION_H_

#include <stdbool.h>
#include <stdint.h>

#include "ota_types.h"

ota_slot_t ota_get_active_slot(void);
ota_slot_t ota_get_inactive_slot(void);
uint32_t ota_get_slot_physical_base(ota_slot_t slot);
uint32_t ota_get_slot_access_base(ota_slot_t slot);
uint32_t ota_get_slot_base(ota_slot_t slot);
uint32_t ota_get_slot_end(ota_slot_t slot);
uint32_t ota_get_slot_header_addr(ota_slot_t slot);
uint32_t ota_get_slot_version_addr(ota_slot_t slot);
ota_status_t ota_read_slot_header(ota_slot_t slot, ota_image_header_t *header);
bool ota_is_slot_hardware_valid(ota_slot_t slot);
bool ota_is_slot_valid(ota_slot_t slot);
int ota_compare_version(uint32_t v1, uint32_t v2);
uint32_t ota_get_fmc_ota_ctrl(void);
uint32_t ota_get_fmc_ota_version_location(void);
uint32_t ota_get_fmc_ota_active_version(void);
bool ota_is_hardware_ota_enabled(void);
bool ota_is_hardware_ota_locked(void);

#endif /* OTA_PARTITION_H_ */
