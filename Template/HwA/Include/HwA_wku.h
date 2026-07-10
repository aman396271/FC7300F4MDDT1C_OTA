/**
 * @file HwA_wku.h
 * @author Flagchip
 * @brief WKU hardware access layer
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
   *   0.1.0      2023-12-15     Flagchip084   N/A          First version for FC7300
   *   2.0.0      2024-10-12     Flagchip084   N/A          Change version and release
   ******************************************************************************** */
#ifndef _HWA_WKU_H_
#define _HWA_WKU_H_

#include "device_header.h"

#if WKU_INSTANCE_COUNT > 0U

/**
 * @defgroup HwA_wku HwA_wku
 * @ingroup module_driver_wku
 * @{
 */

/********* Local typedef ************/
#define WKU_MWR0    0x0000100U
#define WKU_MWR1    0x0010000U
#define WKU_MWR2    0x1000000U

/** @brief Wku input */
typedef enum
{
#if (WKU_GPIO_TYPE_0_SUPPORT || WKU_GPIO_TYPE_1_SUPPORT)
    WKU_INPUT_FCSPI0      = 0x000040U,
    WKU_INPUT_FCUART      = 0x000080U,
    WKU_INPUT_CMP0        = 0x000400U,
    WKU_INPUT_CMP1        = 0x000800U,
    WKU_INPUT_TSTMP0      = 0x002000U,
    WKU_INPUT_RTC_ALARM   = 0x004000U,
    WKU_INPUT_RTC_SECONDS = 0x008000U,
    WKU_INPUT_FCPIT0      = 0x010000U,
    WKU_INPUT_CMU0        = 0x020000U,
    WKU_INPUT_AONTIMER    = 0x040000U,
    WKU_INPUT_GPIOA       = 0x080000U,

#if WKU_GPIO_TYPE_0_SUPPORT
    WKU_INPUT_GPIOC       = 0x100000U,
    WKU_INPUT_GPIOE       = 0x200000U,
    WKU_INPUT_GPIOF       = 0x400000U,
    WKU_INPUT_GPIOG       = 0x800000U,
#else
    WKU_INPUT_GPIOC       = 0x200000U,
    WKU_INPUT_GPIOD       = 0x400000U,
    WKU_INPUT_GPIOE       = 0x800000U,
#endif /* WKU_GPIO_TYPE_0_SUPPORT */

#elif WKU_GPIO_TYPE_2_SUPPORT
    WKU_INPUT_GPIOB       = 0x000001U,
    WKU_INPUT_GPIOD       = 0x000002U,
    WKU_INPUT_GPIOF       = 0x000004U,
    WKU_INPUT_GPIOG       = 0x000008U,
    WKU_INPUT_GPIOH       = 0x000010U,
    WKU_INPUT_GPIOI       = 0x000020U,

#if WKU_GPIO_TYPE_2_ADC2_SUPPORT
    WKU_INPUT_ADC1_LPWAKE = 0x000100U,
    WKU_INPUT_ADC2_LPWAKE = 0x000200U,
#else
    WKU_INPUT_ADC0_LPWAKE = 0x000100U,
    WKU_INPUT_ADC1_LPWAKE = 0x000200U,
#endif /* WKU_GPIO_TYPE_2_ADC2_SUPPORT */

#if WKU_GPIO_TYPE_2_CMP0_SUPPORT
    WKU_INPUT_CMP0        = 0x000400U,
#endif /* WKU_GPIO_TYPE_2_CMP0_SUPPORT */

    WKU_INPUT_TSTMP0      = 0x002000U,
    WKU_INPUT_RTC_ALARM   = 0x004000U,
    WKU_INPUT_RTC_SECONDS = 0x008000U,
    WKU_INPUT_AONTIMER0   = 0x040000U,
    WKU_INPUT_GPIOA       = 0x080000U,
    WKU_INPUT_GPIOC       = 0x100000U,
    WKU_INPUT_GPIOE       = 0x200000U,
#else
    /* More supoort */
#endif /* (WKU_GPIO_TYPE_0_SUPPORT || WKU_GPIO_TYPE_1_SUPPORT) */
    WKU_INPUT_MAX = 0xFFFFFFU
} WKU_WakeupInputType;

/********* Local inline function ************/
/**
 * @brief Enable wakeup source
 *
 * @param eWakeup Wakeup source type
 */
LOCAL_INLINE void WKU_HWA_EnableWakeupSource(const WKU_WakeupInputType eWakeup)
{
    if (eWakeup < WKU_MWR0)
    {
        WKU->MWER0 |= (uint32_t)eWakeup;
    }
    else if ((eWakeup < WKU_MWR1) && (eWakeup >= WKU_MWR0))
    {
        WKU->MWER1 |= ((uint32_t)eWakeup >> 8U);
    }
    else
    {
        WKU->MWER2 |= ((uint32_t)eWakeup >> 16U);
    }
}

/**
 * @brief Disable wakeup source
 *
 * @param eWakeup Wakeup source type
 */
LOCAL_INLINE void WKU_HWA_DisableWakeupSource(const WKU_WakeupInputType eWakeup)
{
    if (eWakeup < WKU_MWR0)
    {
        WKU->MWER0 &= ((~((uint32_t)eWakeup)) & (uint32_t)0xFF);
    }
    else if ((eWakeup < WKU_MWR1) && (eWakeup >= WKU_MWR0))
    {
        WKU->MWER1 &= ((~(uint32_t)((uint32_t)eWakeup >> 8U)) & (uint32_t)0xFF);
    }
    else
    {
        WKU->MWER2 &= ((~(uint32_t)((uint32_t)eWakeup >> 16U)) & (uint32_t)0xFF);
    }
}

/**
 * @brief Read WKU wakeup source
 *
 * @return WKU wakeup source value
 */
LOCAL_INLINE uint32_t WKU_HWA_ReadWakeupSource(void)
{
    uint32_t u32WakeupSource = 0U;

    u32WakeupSource = (uint32_t)(WKU->MWER0);
    u32WakeupSource |= (uint32_t)((uint32_t)(WKU->MWER1) << 8U);
    u32WakeupSource |= (uint32_t)((uint32_t)(WKU->MWER2) << 16U);

    return u32WakeupSource;
}

#if WKU_GPIO_TYPE_2_SUPPORT
/**
 * @brief Get wakeup flag
 * 
 * @param eWakeup 
 * @return 
 */
LOCAL_INLINE bool WKU_HWA_CheckWakeupFlag(const WKU_WakeupInputType eWakeup)
{
    uint32_t u32WakeupFlag = 0U;

    if (eWakeup < WKU_MWR0)
    {
        u32WakeupFlag = WKU->MWFR0 & (((uint32_t)eWakeup) & (uint32_t)0xFF);
    }
    else if ((eWakeup < WKU_MWR1) && (eWakeup >= WKU_MWR0))
    {
        u32WakeupFlag = WKU->MWFR1 & (((uint32_t)((uint32_t)eWakeup >> 8U)) & (uint32_t)0xFF);
    }
    else
    {
        u32WakeupFlag = WKU->MWFR2 & (((uint32_t)((uint32_t)eWakeup >> 16U)) & (uint32_t)0xFF);
    }

    if (u32WakeupFlag != 0U)
    {
        return true;
    }
    else
    {
        return false;
    }
}

/**
 * @brief Get all wakeup flag
 * 
 * @param void 
 * @return
 */
LOCAL_INLINE uint32_t WKU_HWA_GetAllWakeupFlag(void)
{
    uint32_t u32WakeupFlag = 0U;

    u32WakeupFlag = (uint32_t)(WKU->MWFR0);
    u32WakeupFlag |= (uint32_t)((uint32_t)(WKU->MWFR1) << 8U);
    u32WakeupFlag |= (uint32_t)((uint32_t)(WKU->MWFR2) << 16U);

    return u32WakeupFlag;
}
#endif /* WKU_GPIO_TYPE_2_SUPPORT */

/** @}*/

#endif /* #if WKU_INSTANCE_COUNT > 0U */

#endif /* #ifndef _HWA_WKU_H_ */
