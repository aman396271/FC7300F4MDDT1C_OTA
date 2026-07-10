/**
 * @file module_driver_wku.h
 * @author Flagchip
 * @brief WKU driver type definition and API
 * @version 2.0.0
 * @date 2024-08-20
 *
 * SDK Version: 2.6.0
 *

 * @copyright Copyright (c) 2020-2024 Flagchip Semiconductors Co., Ltd.
 *
 * @details
 */

/* ********************************************************************************
   *   Revision History:
   *
   *   Version     Date          Initials      CR#          Descriptions
   *   ---------   ----------    ------------  ----------   ---------------
   *   0.1.0       2023-12-15    Flagchip085   N/A          First version for FC7300
   *   2.0.0       2024-10-12    Flagchip085   N/A          Change version and release
   ******************************************************************************** */

#ifndef _DRIVER_MODULE_DRIVER_WKU_H_
#define _DRIVER_MODULE_DRIVER_WKU_H_
#include "HwA_wku.h"

#if WKU_INSTANCE_COUNT > 0U

/**
 * @addtogroup module_driver_wku
 * @{
 */

/** @brief WKU return type. */
typedef enum
{
    WKU_STATUS_SUCCESS = 0U,
    WKU_STATUS_PARAM_INVALID = 1U
} WKU_StatusType;


/* global apis */
/**
 * @brief WKU Enable wakeup source for single input
 *
 * @param u32Input Number of input, WKU_WakeupInputType type is wakeup source definition
 * @return WKU return type
 */
WKU_StatusType WKU_EnableWakeupSource(const uint32_t u32Input);

/**
 * @brief WKU Disable wakeup source for single input
 *
 * @param u32Input Number of input, WKU_WakeupInputType type is wakeup source definition
 * @return WKU return type
 */
WKU_StatusType WKU_DisableWakeupSource(const uint32_t u32Input);

/**
 * @brief WKU get wakeup source
 *
 * @return output wakeup source
 */
uint32_t WKU_GetWakeupSources(void);

#if WKU_GPIO_TYPE_2_SUPPORT
/**
 * @brief WKU check wakeup flag
 * 
 * @param tWKUType 
 * @return Whether the wake flag bit is set
 */
bool WKU_CheckWakeupFlag(const WKU_WakeupInputType tWKUType);

/**
 * @brief WKU get all wakeup flags
 * 
 * @return Wakeup flag 
 */
uint32_t WKU_GetAllWakeupFlag(void);
#endif /*  WKU_GPIO_TYPE_2_SUPPORT */

/** @}*/ /* module_driver_wku */

#endif /* #if WKU_INSTANCE_COUNT > 0U */

#endif
