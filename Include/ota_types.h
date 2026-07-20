#ifndef OTA_TYPES_H_
#define OTA_TYPES_H_

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

typedef enum
{
    OTA_SLOT_LOW = 0,
    OTA_SLOT_HIGH = 1,
    OTA_SLOT_INVALID = 0x7FFFFFFF
} ota_slot_t;

typedef enum
{
    OTA_OK = 0,
    OTA_ERR_PARAM = -1,
    OTA_ERR_RANGE = -2,
    OTA_ERR_ACTIVE_SLOT = -3,
    OTA_ERR_FLASH = -4,
    OTA_ERR_INVALID_IMAGE = -5,
    OTA_ERR_CRC = -6,
    OTA_ERR_VERSION = -7,
    OTA_ERR_STATE = -8,
    OTA_ERR_LOCKED = -9,
    OTA_ERR_NOT_SUPPORTED = -10,
    OTA_ERR_BUSY = -11,
    OTA_ERR_NOT_ENABLED = -12,
    OTA_ERR_SEQUENCE = -13,
    OTA_ERR_TIMEOUT = -14
} ota_status_t;

typedef struct
{
    uint32_t version;
    uint32_t version_inverted;
    uint32_t valid_code_lo;
    uint32_t valid_code_hi;
    uint32_t magic;
    uint32_t header_version;
    uint32_t image_size;
    uint32_t image_crc32;
    uint32_t build_timestamp;
    uint32_t valid_flag;
    uint32_t header_crc32;
    uint32_t reserved[21];
} ota_image_header_t;

typedef struct
{
    bool busy;
    ota_slot_t target_slot;
    uint32_t image_size;
    uint32_t received_bytes;
    uint32_t programmed_bytes;
} ota_update_progress_t;

#endif /* OTA_TYPES_H_ */
