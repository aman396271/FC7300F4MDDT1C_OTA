#ifndef OTA_FLASH_H_
#define OTA_FLASH_H_

#include <stddef.h>
#include <stdint.h>

#include "ota_types.h"

ota_status_t ota_flash_init(void);
ota_status_t ota_flash_erase_slot(ota_slot_t slot);
ota_status_t ota_flash_program(ota_slot_t slot, uint32_t offset, const void *data, uint32_t len);
ota_status_t ota_flash_read(ota_slot_t slot, uint32_t offset, void *data, uint32_t len);
ota_status_t ota_flash_verify_crc(ota_slot_t slot);
ota_status_t ota_flash_verify_payload_crc(ota_slot_t slot, uint32_t image_size, uint32_t expected_crc);
ota_status_t ota_flash_program_header(ota_slot_t slot, const ota_image_header_t *header);
ota_status_t ota_flash_erase_header_sector(ota_slot_t slot, bool allow_active_slot);
ota_status_t ota_dflash_write_state(const void *data, uint32_t len);
ota_status_t ota_dflash_read_state(void *data, uint32_t len);

#endif /* OTA_FLASH_H_ */
