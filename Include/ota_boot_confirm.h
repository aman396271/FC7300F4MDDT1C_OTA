#ifndef OTA_BOOT_CONFIRM_H_
#define OTA_BOOT_CONFIRM_H_

#include <stdint.h>

#include "ota_types.h"

ota_status_t ota_mark_pending(void);
ota_status_t ota_mark_pending_for_slot(ota_slot_t slot, uint32_t version);
ota_status_t ota_mark_confirmed(void);
ota_status_t ota_check_pending_and_rollback(void);

#endif /* OTA_BOOT_CONFIRM_H_ */
