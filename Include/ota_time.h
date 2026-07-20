#ifndef OTA_TIME_H_
#define OTA_TIME_H_

#include <stdint.h>

void ota_time_init(uint32_t core_clock_hz);
uint32_t ota_time_now_ms(void);

#endif /* OTA_TIME_H_ */
