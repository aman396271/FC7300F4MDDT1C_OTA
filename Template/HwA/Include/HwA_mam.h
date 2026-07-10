/**
 * @file HwA_mam.h
 * @author Flagchip
 * @brief Hardware access layer for MAM
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
   *   0.1.0      2023-12-15     Flagchip054   N/A          First version for FC7300
   *   2.0.0      2024-10-12     Flagchip054   N/A          Change version and release
   *   2.5.0       2025-08-20    Flagchip0100  N/A          Add FC7300F4MDDxxxT1C support
   ******************************************************************************** */

#ifndef _HWA_MAM_H_
#define _HWA_MAM_H_
#include "device_header.h"

#if MAM_INSTANCE_COUNT > 0U

/**
 * @defgroup HwA_mam HwA_mam
 * @ingroup module_driver_mam
 * @{
 */

/**
 * @brief Set Mam module Matrix Configure register
 *
 * @param1 MAM base pointer
 *
 * @param2 u32Value Matrix Configure register value
 */
LOCAL_INLINE void Mam_HWA_SetMatrixCfg(MAM_Type *MAM,  uint32_t u32Value)
{
	MAM->MAXCFG = u32Value;
}

/**
 * @brief Read Mam module Ctrl register
 *
 * @param MAM base pointer
 *
 * @return Matrix Configure register value
 */
LOCAL_INLINE uint32_t Mam_HWA_GetMatrixCfg(MAM_Type *MAM)
{
    return (uint32_t)(MAM->MAXCFG);
}

/**
 * @brief Set Mam module Wdgctr register
 *
 * @param1 MAM base pointer
 *
 * @param2 u32Value Wdgctr register value
 */
LOCAL_INLINE void Mam_HWA_SetWdgCr(MAM_Type *MAM, uint32_t u32Value)
{
	MAM->WDGCR = u32Value;
}

/**
 * @brief Read Mam module Wdgctr register
 *
 * @param MAM base pointer
 *
 * @return Wdgctr register value
 */
LOCAL_INLINE uint32 Mam_HWA_GetWdgCr(MAM_Type *MAM)
{
	return MAM->WDGCR;
}

/**
 * @brief Set Mam module timeout control register
 *
 * @param1 MAM base pointer
 *
 * @param2 u32Value timeout control register value
 */
LOCAL_INLINE void Mam_HWA_SetWdgToCr(MAM_Type *MAM, uint32_t u32Value)
{
    MAM->TOCR = u32Value;
}

/**
 * @brief Read Mam module timeout control register
 *
 * @param MAM base pointer
 *
 * @return timeout control register value
 */
LOCAL_INLINE uint32 Mam_HWA_GetWdgToCr(MAM_Type *MAM)
{
    return MAM->TOCR;
}

#ifdef MAM_WDOG_DIV_SUPPORT
/**
 * @brief Set Mam module watchdog div register
 *
 * @param1 MAM base pointer
 *
 * @param2 u32Value watchdog div register value
 */
LOCAL_INLINE void Mam_HWA_SetWdgDiv(MAM_Type *MAM, uint32_t u32Value)
{
    MAM->WDGDIV = u32Value;
}

/**
 * @brief Read Mam module watchdog div register
 *
 * @param MAM base pointer
 *
 * @return watchdog div register value
 */
LOCAL_INLINE uint32 Mam_HWA_GetWdgDiv(MAM_Type *MAM)
{
    return MAM->WDGDIV;
}
#endif


/**
 * @brief Set Mam module ACR register
 *
 * @param1 MAM base pointer
 *
 * @param2 idx ACR register index
 *
 * @param3 u32Value ACR register value
 */
LOCAL_INLINE void Mam_HWA_Set_ACR(MAM_Type *MAM, uint32_t idx, uint32_t u32Value)
{
	MAM->ACR[idx] = u32Value;
}

/**
 * @brief Read Mam module ACR register
 *
 * @param1 MAM base pointer
 *
 * @param2 idx ACR register index
 *
 * @return ACR register value
 */
LOCAL_INLINE uint32_t Mam_HWA_Get_ACR(MAM_Type *MAM, uint32_t idx)
{
    return MAM->ACR[idx];
}

/**
 * @brief Set Mam module ACLR register
 *
 * @param1 MAM base pointer
 *
 * @param2 idx ACLR register index
 *
 * @param3 u32Value ACLR register value
 */
LOCAL_INLINE void Mam_HWA_Set_ACLR(MAM_Type *MAM, uint32_t idx, uint32_t u32Value)
{
	MAM->ACLR[idx] = u32Value;
}

/**
 * @brief Read Mam module ACLR register
 *
 * @param1 MAM base pointer
 *
 * @param2 idx ACLR register index
 *
 * @return ACLR register value
 */
LOCAL_INLINE uint32_t Mam_HWA_Get_ACLR(MAM_Type *MAM, uint32_t idx)
{
    return MAM->ACLR[idx];
}

#ifdef MAM_PORT_MONITOR_SUPPORT
/**
 * @brief Set the Check Control Register (CCLR) value
 * 
 * @param MAM Pointer to the MAM peripheral register structure
 * @param u32Value Value to write to the CCLR register
 *               - Each bit corresponds to a monitor port (0-31)
 *               - Setting a bit enables monitoring for that port
 *               - Clearing a bit disables monitoring for that port
 */
LOCAL_INLINE void Mam_HWA_Set_CCLR(MAM_Type *MAM, uint32_t u32Value)
{
    MAM->CCLR = u32Value;
}

/**
 * @brief Get the current Check Control Register (CCLR) value
 * 
 * @param MAM Pointer to the MAM peripheral register structure
 * @return uint32_t Current CCLR register value
 *               - Each bit represents the enabled state of a monitor port (0-31)
 *               - Bit set to 1: monitoring enabled for that port
 *               - Bit set to 0: monitoring disabled for that port
 */
LOCAL_INLINE uint32_t Mam_HWA_Get_CCLR(MAM_Type *MAM)
{
    return MAM->CCLR;
}
#endif

#ifdef MAM_SLAVE_PRIORITY_SUPPORT
/**
 * @brief Set the Priority Enable Register (PRI_EN) value
 * 
 * @param MAM Pointer to the MAM peripheral register structure
 * @param u32Value Priority enable configuration value
 *               - Each bit (0-31) enables/disables priority arbitration for a slave
 *               - Bit set to 1: priority arbitration enabled for corresponding slave
 *               - Bit set to 0: round-robin arbitration used for corresponding slave
 */
LOCAL_INLINE void Mam_HWA_Set_PRI_EN(MAM_Type *MAM, uint32_t u32Value)
{
    MAM->PRI_EN = MAM_PRIORITY_EN_KEY;
    MAM->PRI_EN = u32Value;
}

/**
 * @brief Get the current Priority Enable Register (PRI_EN) value
 * 
 * @param MAM Pointer to the MAM peripheral register structure
 * @return uint32_t Current PRI_EN register value
 *               - Each bit (0-31) represents priority enable state for a slave
 *               - Bit set to 1: priority arbitration enabled for corresponding slave
 *               - Bit set to 0: round-robin arbitration used for corresponding slave
 */
LOCAL_INLINE uint32_t Mam_HWA_Get_PRI_EN(MAM_Type *MAM)
{
    return MAM->PRI_EN;
}

/**
 * @brief Set Priority ID for Slave Group 0 (slaves 0-7)
 * 
 * @param MAM Pointer to the MAM peripheral register structure
 * @param u32Value Priority configuration value
 *               - Bits [3:0]: Priority master for slave 0
 *               - Bits [7:4]: Priority master for slave 1
 *               - ... up to Bits [31:28]: Priority master for slave 7
 */
LOCAL_INLINE void Mam_HWA_Set_PRI_ID_SLVGRP0(MAM_Type *MAM, uint32_t u32Value)
{
    MAM->PRI_ID_SLVGRP0 = u32Value;
}

/**
 * @brief Get current Priority ID for Slave Group 0 (slaves 0-7)
 * 
 * @param MAM Pointer to the MAM peripheral register structure
 * @return uint32_t Current priority configuration for slaves 0-7
 */
LOCAL_INLINE uint32_t Mam_HWA_Get_PRI_ID_SLVGRP0(MAM_Type *MAM)
{
    return MAM->PRI_ID_SLVGRP0;
}

/**
 * @brief Set Priority ID for Slave Group 1 (slaves 8-15)
 * 
 * @param MAM Pointer to the MAM peripheral register structure
 * @param u32Value Priority configuration value
 *               - Byte 0: Priority master for slave 8 (bits [7:0])
 *               - Byte 1: Priority master for slave 9 (bits [15:8])
 *               - ... up to Byte 7: Priority master for slave 15 (bits [63:56])
 */
LOCAL_INLINE void Mam_HWA_Set_PRI_ID_SLVGRP1(MAM_Type *MAM, uint32_t u32Value)
{
    MAM->PRI_ID_SLVGRP1 = u32Value;
}

/**
 * @brief Get current Priority ID for Slave Group 1 (slaves 8-15)
 * 
 * @param MAM Pointer to the MAM peripheral register structure
 * @return uint32_t Current priority configuration for slaves 8-15
 */
LOCAL_INLINE uint32_t Mam_HWA_Get_PRI_ID_SLVGRP1(MAM_Type *MAM)
{
    return MAM->PRI_ID_SLVGRP1;
}
#endif

/** @}*/

#endif /* #if MAM_INSTANCE_COUNT > 0U */

#endif
