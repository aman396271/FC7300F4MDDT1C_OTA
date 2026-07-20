#ifndef OTA_BUILD_VARIANT_H_
#define OTA_BUILD_VARIANT_H_

#include "ota_build_selection.h"
#include "ota_version_autogen.h"

#define OTA_BUILD_VARIANT_A              0
#define OTA_BUILD_VARIANT_B              1

#if OTA_BUILD_VARIANT == OTA_BUILD_VARIANT_A
#define OTA_APP_LABEL                    "APP A"
#define OTA_APP_VERSION                  (OTA_VERSION_A)
#define OTA_LED_DELAY_MS                 (1000UL)
#define OTA_LED_LABEL                    "LED1/PTA26"
#elif OTA_BUILD_VARIANT == OTA_BUILD_VARIANT_B
#define OTA_APP_LABEL                    "APP B"
#define OTA_APP_VERSION                  (OTA_VERSION_B)
#define OTA_LED_DELAY_MS                 (200UL)
#define OTA_LED_LABEL                    "LED2/PTD31"
#else
#error Unsupported OTA_BUILD_VARIANT
#endif

/* Compatibility alias for older demo-only call sites. */
#define OTA_DEMO_VERSION                 (OTA_APP_VERSION)

#endif /* OTA_BUILD_VARIANT_H_ */
