#ifndef OTA_UPDATE_H_
#define OTA_UPDATE_H_

#include <stdint.h>

#include "ota_types.h"

ota_status_t ota_begin_update(const ota_image_header_t *header);
ota_status_t ota_write_chunk(const void *data, uint32_t len);
ota_status_t ota_finish_update(void);
ota_status_t ota_abort_update(void);
ota_slot_t ota_update_target_slot(void);
void ota_update_get_progress(ota_update_progress_t *progress);

#endif /* OTA_UPDATE_H_ */
