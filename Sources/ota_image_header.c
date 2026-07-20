#include "ota_config.h"
#include "ota_crc32.h"
#include "ota_types.h"

/*
 * Fixed software header/version template.
 *
 * Both variants use the same logical address after hardware bank mapping:
 *   header VMA  = 0x011FF000, version VMA = 0x011FF000
 * APP A loads there physically. APP B's linker maps the same object to the
 * corresponding Bank1 LMA at 0x013FF000.
 *
 * A post-build packer must patch image_size, image_crc32 and header_crc32 for
 * the final downloadable binary.
 */
const ota_image_header_t g_ota_image_header __attribute__((section(".ota_header"), used)) =
{
    OTA_APP_VERSION,
    ~OTA_APP_VERSION,
    OTA_IMAGE_VALID_CODE_LO,
    OTA_IMAGE_VALID_CODE_HI,
    OTA_IMAGE_MAGIC,
    OTA_IMAGE_HEADER_VERSION,
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
