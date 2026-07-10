/**
 * @file HwA_pmc.h
 * @author flagchip
 * @brief PMC register API
 * @version 2.0.0
 * @date 2024-08-20
 *
 * SDK Version: 2.6.0
 *

 * @copyright Copyright (c) 2020-2024 Flagchip Semiconductors Co., Ltd.
 *
 */
/* ********************************************************************************
   *   Revision History:
   *
   *   Version     Date          Initials      CR#          Descriptions
   *   ---------   ----------    ------------  ----------   ---------------
   *   0.1.0      2023-12-15     Flagchip095   N/A          First version for FC7300
   *   2.0.0      2024-10-12     Flagchip095   N/A          Change version and release
   ******************************************************************************** */
#ifndef HWA_INCLUDE_HWA_PMC_H_
#define HWA_INCLUDE_HWA_PMC_H_
#include "device_header.h"

#if PMC_INSTANCE_COUNT > 0U

/**
 * @defgroup HwA_pmc
 * @ingroup module_driver_pmc
 * @{
 */

/**
 * @brief get PMC LVCSR register
 *
 * @return uint32_t LVCSR register value
 */
LOCAL_INLINE uint32_t PMC_HWA_GetLVSCR(void)
{
    return (uint32)(PMC->LVSCR);
}

/**
 * @brief set PMC LVCSR register.
 *
 * This function configures the PMC LVCSR registe.
 *
 * @param u32Val Set PMC LVCSR register value.
 */
LOCAL_INLINE void PMC_HWA_SetLVSCR(uint32_t u32Val)
{
    PMC->LVSCR = u32Val;
}

/**
 * @brief get PMC CONFIG register
 *
 * @return uint32_t CONFIG register value
 */
LOCAL_INLINE uint32_t PMC_HWA_GetCONFIG(void)
{
    return (uint32)(PMC->CONFIG);
}

/**
 * @brief set PMC CONFIG register.
 *
 * This function configures the PMC CONFIG registe.
 *
 * @param u32LVSCRValue Set PMC CONFIG register value.
 */
LOCAL_INLINE void PMC_HWA_SetCONFIG(uint32_t u32Val)
{
    PMC->CONFIG = u32Val;
}

/**
 * @brief HWA Disable PMC interrupt
 *
 * @param the parameter of interrupt flag
 */
LOCAL_INLINE void PMC_HWA_DisableInterrupt(uint32 u32Val)
{
	PMC->CONFIG &= (~u32Val);
}

/**
 * @brief HWA Enable PMC interrupt
 *
 * @param the parameter of interrupt flag
 */
LOCAL_INLINE void Pmc_HWA_EnableInterrupt(uint32 u32Val)
{
    PMC->CONFIG |= u32Val;
}

/**
 * @brief Return Low Voltage Detect Interrupt Enable Flag
 *
 * @return 0: Low Voltage Detect Interrupt Disabled; 1: Low Voltage Detect Interrupt Enabled
 */
LOCAL_INLINE bool PMC_ReadLVDInterruptFlag(void)
{
    return (bool) ((PMC->CONFIG & PMC_CONFIG_LVD_IE_MASK) >> PMC_CONFIG_LVD_IE_SHIFT);
}

/**
 * @brief Return High Voltage Detect Interrupt Enable Flag
 *
 * @return 0: High Voltage Detect Interrupt Disabled; 1: High Voltage Detect Interrupt Enabled
 */
LOCAL_INLINE bool PMC_ReadHVDInterruptFlag(void)
{
    return (bool) ((PMC->CONFIG & PMC_CONFIG_HVD_IE_MASK) >> PMC_CONFIG_HVD_IE_SHIFT);
}

/** @}*/

#endif /* #if PMC_INSTANCE_COUNT > 0U */

#endif /* HWA_INCLUDE_HWA_PMC_H_ */
