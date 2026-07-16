#ifndef OTA_SERVICE_H_
#define OTA_SERVICE_H_

#include <stdbool.h>
#include <stdint.h>

void ota_service_init(void);
void ota_service_poll(uint32_t now_ms);
bool ota_service_text_enabled(void);

#endif /* OTA_SERVICE_H_ */
