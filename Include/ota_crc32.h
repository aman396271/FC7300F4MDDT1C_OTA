#ifndef OTA_CRC32_H_
#define OTA_CRC32_H_

#include <stddef.h>
#include <stdint.h>

uint32_t ota_crc32_init(void);
uint32_t ota_crc32_update(uint32_t crc, const void *data, size_t len);
uint32_t ota_crc32_finish(uint32_t crc);
uint32_t ota_crc32_compute(const void *data, size_t len);

#endif /* OTA_CRC32_H_ */
