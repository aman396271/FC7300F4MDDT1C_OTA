#ifndef OTA_CONFIG_H_
#define OTA_CONFIG_H_

#include <stdint.h>

#include "device_header.h"
#include "ota_build_variant.h"

/*
 * FC7300 hardware OTA demo layout.
 *
 * The selected demo uses the F4MDD Bank0/1 hardware swap layout: two 2 MB
 * banks inside PFlash.  The software header/version word is placed in the last
 * PFlash sector of each 2 MB bank.
 *
 * OTAC0[51:32] / FMC->OTA_VER_LOC[0] is only a 20-bit offset inside a selected
 * 1 MB half.  To put the indicator at the tail of each 2 MB bank, configure
 * OTAC0[51:32] to OTA_NVR_VERSION_LOGICAL_OFFSET and select the high 1 MB half
 * in OTAC_HIGH0[7:0].  Firmware address calculations use
 * OTA_VERSION_LOGICAL_OFFSET, the effective 2 MB bank offset.
 *
 * If the customer NVR OTAC0/OTAC_HIGH0 uses another low/high range, update
 * these constants and the linker ASSERTs together.
 */
#define OTA_SLOT_LOW_BASE                 (PFLASH_ADDR_START)
#define OTA_SLOT_SIZE                     (0x00200000UL)
#define OTA_SLOT_HIGH_BASE                (OTA_SLOT_LOW_BASE + OTA_SLOT_SIZE)
#define OTA_SLOT_LOW_END                  (OTA_SLOT_LOW_BASE + OTA_SLOT_SIZE - 1UL)
#define OTA_SLOT_HIGH_END                 (OTA_SLOT_HIGH_BASE + OTA_SLOT_SIZE - 1UL)

#define OTA_HEADER_OFFSET                 (OTA_SLOT_SIZE - PFLASH_ERASE_SECTOR_SIZE)
#define OTA_HEADER_SIZE                   (0x80UL)
#define OTA_IMAGE_PAYLOAD_OFFSET          (0x00000000UL)
#define OTA_IMAGE_PAYLOAD_MAX_SIZE        (OTA_HEADER_OFFSET)

#define OTA_HEADER_LOGICAL_OFFSET         (OTA_HEADER_OFFSET)
#define OTA_VERSION_IN_HEADER_OFFSET      (0x00UL)
#define OTA_VERSION_LOGICAL_OFFSET        (OTA_HEADER_LOGICAL_OFFSET + OTA_VERSION_IN_HEADER_OFFSET)
#define OTA_NVR_VERSION_LOGICAL_OFFSET    (0x000FF000UL)
#define OTA_HARDWARE_ENABLE_CODE          (0x0AUL)

#define OTA_STATE_FLASH_ADDR              (DFLASH_ADDR_END + 1UL - DFLASH_ERASE_SECTOR_SIZE)
#define OTA_STATE_FLASH_SIZE              (DFLASH_ERASE_SECTOR_SIZE)

#define OTA_IMAGE_MAGIC                   (0x46435441UL) /* "FCTA" */
#define OTA_IMAGE_HEADER_VERSION          (0x00010000UL)
#define OTA_IMAGE_VALID_FLAG              (0xA5A55A5AUL)
#define OTA_IMAGE_VALID_CODE_LO           (0x88886666UL)
#define OTA_IMAGE_VALID_CODE_HI           (0xFC60FACEUL)
#define OTA_STATE_MAGIC                   (0x46435354UL) /* "FCST" */

/*
 * Direct active-slot invalidation is intentionally guarded.  It is useful on
 * an engineering bench, but it erases metadata from the currently selected
 * image and is not the preferred production rollback policy.
 */
#ifndef OTA_ALLOW_ACTIVE_INVALIDATE
#define OTA_ALLOW_ACTIVE_INVALIDATE       (0)
#endif

#endif /* OTA_CONFIG_H_ */
