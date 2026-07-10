/**
 * @file module_driver_wku.c
 * @author Flagchip
 * @brief WKU driver type definition and API
 * @version 2.0.0
 * @date 2024-09-30
 *
 * SDK Version: 2.6.0
 *

 * @copyright Copyright (c) 2020-2024 Flagchip Semiconductors Co., Ltd.
 *
 * @details
 */
/********************************************************************************
*   Revision History:
*
*   Version     Date          Initials       CR#          Descriptions
*   ---------   ----------    ------------   ----------   ---------------
*   0.1.0       2022-11-21    Flagchip032    N/A          FC7300 First version
*   0.2.0       2023-02-13    Flagchip032    N/A          optimize WKU driver code
*   2.0.0       2024-09-30    Flagchip055    N/A          Update file structures
*   2.1.0       2024-11-27    Flagchip0122   N/A          Add features for FC7300DQ
********************************************************************************/
#include "module_driver_wku.h"

#if WKU_INSTANCE_COUNT > 0U

/**
 * @brief WKU Enable wakeup source for single input
 *
 * @param u32Input Number of input, WKU_WakeupInputType type is wakeup source definition
 * @return WKU return type
 */
WKU_StatusType WKU_EnableWakeupSource(const uint32_t u32Input)
{
    uint32_t u32TempValue = 0U;
    uint8_t u8Index = 0U;
    WKU_StatusType eRet = WKU_STATUS_SUCCESS;

    if (u32Input > (uint32_t)WKU_INPUT_MAX)
    {
        eRet = WKU_STATUS_PARAM_INVALID;
    }

    if (WKU_STATUS_SUCCESS == eRet)
    {
        u32TempValue = u32Input;
        while (u32TempValue)
        {
            if (1U == (u32TempValue & ((uint32_t)1)))
            {
                WKU_HWA_EnableWakeupSource((WKU_WakeupInputType)((uint32_t)1 << u8Index));
            }
            u32TempValue >>= 1U;
            u8Index++;
        }
    }

    return eRet;
}

/**
 * @brief WKU Disable wakeup source for single input
 *
 * @param u32Input Number of input, WKU_WakeupInputType type is wakeup source definition
 * @return WKU return type
 */
WKU_StatusType WKU_DisableWakeupSource(const uint32_t u32Input)
{
    uint32_t u32TempValue = 0U;
    uint8_t u8Index = 0U;
    WKU_StatusType eRet = WKU_STATUS_SUCCESS;

    if (u32Input > (uint32_t)WKU_INPUT_MAX)
    {
        eRet = WKU_STATUS_PARAM_INVALID;
    }

    if (WKU_STATUS_SUCCESS == eRet)
    {
        u32TempValue = u32Input;
        while (u32TempValue)
        {
            if (u32TempValue & ((uint32_t)1 << u8Index))
            {
                WKU_HWA_DisableWakeupSource((WKU_WakeupInputType)((uint32_t)1 << u8Index));
            }
            u32TempValue &= (uint32_t)~((uint32_t)1 << u8Index);
            u8Index++;
        }
    }

    return eRet;
}

/**
 * @brief WKU get wakeup source
 *
 * @return output wakeup source
 */
uint32_t WKU_GetWakeupSources(void)
{
    return WKU_HWA_ReadWakeupSource();
}

#if WKU_GPIO_TYPE_2_SUPPORT
/**
 * @brief WKU check wakeup flag
 * 
 * @param tWKUType
 * @return Whether the wake flag bit is set
 */
bool WKU_CheckWakeupFlag(const WKU_WakeupInputType tWKUType)
{
    return WKU_HWA_CheckWakeupFlag(tWKUType);
}

/**
 * @brief WKU get all wakeup flags
 * 
 * @return Wakeup flag
 */
uint32_t WKU_GetAllWakeupFlag(void)
{
    return WKU_HWA_GetAllWakeupFlag();
}
#endif /* WKU_GPIO_TYPE_2_SUPPORT */

#endif /* #if WKU_INSTANCE_COUNT > 0U */
