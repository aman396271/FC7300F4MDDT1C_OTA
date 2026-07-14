#ifndef OTA_BUILD_VARIANT_H_
#define OTA_BUILD_VARIANT_H_

#include "ota_build_selection.h"

#define OTA_BUILD_VARIANT_A              0
#define OTA_BUILD_VARIANT_B              1

#if OTA_BUILD_VARIANT == OTA_BUILD_VARIANT_A
#define OTA_APP_LABEL                    "APP A"
#define OTA_DEMO_VERSION                 (0x00000001UL)
#define OTA_LED_DELAY_MS                 (1000UL)
#elif OTA_BUILD_VARIANT == OTA_BUILD_VARIANT_B
#define OTA_APP_LABEL                    "APP B"
#define OTA_DEMO_VERSION                 (0x00000002UL)
#define OTA_LED_DELAY_MS                 (200UL)
#else
#error Unsupported OTA_BUILD_VARIANT
#endif

#endif /* OTA_BUILD_VARIANT_H_ */
