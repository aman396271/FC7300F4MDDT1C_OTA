#include "ota_config.h"
#include "ota_crc32.h"
#include "ota_types.h"

/*
 * Fixed software header/version template.
 *
 * The linker places this object at the tail of the low 2 MB bank:
 *   OTA_SLOT_LOW_BASE + OTA_HEADER_OFFSET = 0x011FF000
 * and the version word at:
 *   OTA_SLOT_LOW_BASE + OTA_VERSION_LOGICAL_OFFSET = 0x011FF008
 *
 * A post-build packer must patch image_size, image_crc32 and header_crc32 for
 * the final downloadable binary.  The same binary may then be programmed at
 * the high 2 MB bank base while keeping the same VMA.
 */
const ota_image_header_t g_ota_image_header __attribute__((section(".ota_header"), used)) =
{
    OTA_IMAGE_MAGIC,
    OTA_IMAGE_HEADER_VERSION,
    OTA_DEMO_VERSION,
    ~OTA_DEMO_VERSION,
    OTA_IMAGE_VALID_CODE_LO,
    OTA_IMAGE_VALID_CODE_HI,
    OTA_IMAGE_PAYLOAD_MAX_SIZE,
    0xFFFFFFFFUL,
    0UL,
    OTA_IMAGE_VALID_FLAG,
    0xFFFFFFFFUL,
    {
        0xFFFFFFFFUL, 0xFFFFFFFFUL, 0xFFFFFFFFUL, 0xFFFFFFFFUL,
        0xFFFFFFFFUL, 0xFFFFFFFFUL, 0xFFFFFFFFUL, 0xFFFFFFFFUL,
        0xFFFFFFFFUL, 0xFFFFFFFFUL, 0xFFFFFFFFUL, 0xFFFFFFFFUL,
        0xFFFFFFFFUL, 0xFFFFFFFFUL, 0xFFFFFFFFUL, 0xFFFFFFFFUL,
        0xFFFFFFFFUL, 0xFFFFFFFFUL, 0xFFFFFFFFUL, 0xFFFFFFFFUL,
        0xFFFFFFFFUL
    }
};
