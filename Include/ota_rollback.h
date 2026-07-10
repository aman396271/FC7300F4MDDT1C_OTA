#ifndef OTA_ROLLBACK_H_
#define OTA_ROLLBACK_H_

#include "ota_types.h"

ota_status_t ota_request_rollback_by_version_bump(void);
ota_status_t ota_request_rollback_by_invalidate_active(void);
ota_status_t ota_force_switch_by_fmc_register(ota_slot_t target_slot);

#endif /* OTA_ROLLBACK_H_ */
