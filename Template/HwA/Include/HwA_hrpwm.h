/**
 * @file HwA_hrpwm.h
 * @author Flagchip
 * @brief HRPWM hardware access layer
 * @version 2.0.0
 * @date 2024-11-06
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
   *   0.1.0      2023-12-15     Flagchip070   N/A          First version for FC7300
   *   2.0.0      2024-10-12     Flagchip070   N/A          Change version and release
   ******************************************************************************** */

#ifndef _HWA_HRPWM_H_
#define _HWA_HRPWM_H_
#include "device_header.h"

#if defined(HRPWM_INSTANCE_COUNT) && (HRPWM_INSTANCE_COUNT > 0U)

/**
 * @defgroup HwA_hrpwm HwA_hrpwm
 * @ingroup module_driver_hrpwm
 * @{
 */

/* Define the unlock write code for the HRPWM module, used to unlock HRPWM registers for configuration */
#define HRPWM_UNLOCK_WRITE_CODE			0x10248888U
/* Define the lock write code for the HRPWM module, used to lock HRPWM registers to protect configuration */
#define HRPWM_LOCK_WRITE_CODE			0x1024CAFEU

/**
 * @brief Enable or disable an HRPWM channel
 * 
 * @param pHrpwm Base address pointer of the HRPWM peripheral
 * @param u8Channel The HRPWM channel number to control
 * @param bEnable True to enable the channel, False to disable the channel
 */
LOCAL_INLINE void HRPWM_HWA_SetChannelEnable(HRPWM_Type * const pHrpwm, uint8_t u8Channel, bool bEnable)
{
    pHrpwm->EN_CTRL = (pHrpwm->EN_CTRL & (~(1U << u8Channel))) | ((uint32_t)bEnable << u8Channel);
}

/**
 * @brief Set bypass mode for an HRPWM channel
 *  
 * @param pHrpwm Base address pointer of the HRPWM peripheral
 * @param u8Channel The HRPWM channel number to control
 * @param bBypass True to enable bypass mode, False to disable bypass mode
 */
LOCAL_INLINE void HRPWM_HWA_SetChannelBypass(HRPWM_Type * const pHrpwm, uint8_t u8Channel, bool bBypass)
{
    pHrpwm->BYPASS_CTRL = (pHrpwm->BYPASS_CTRL & (~(1U << u8Channel))) | ((uint32_t)bBypass << u8Channel);
}

/**
 * @brief Set Fault bypass enable for an HRPWM channel
 *
 * @param pHrpwm Base address pointer of the HRPWM peripheral
 * @param u8Channel The HRPWM channel number to control
 * @param bBypass True to enable HRPWM fault, False to disable HRPWM fault
 */
LOCAL_INLINE void HRPWM_HWA_SetChannelFaultEnable(HRPWM_Type * const pHrpwm, uint8_t u8Channel, bool bBypass)
{
	pHrpwm->FAULT_BYPASS_CTRL = (pHrpwm->FAULT_BYPASS_CTRL & (~(1U << u8Channel))) | ((uint32_t)bBypass << u8Channel);
}

/**
 * @brief Enable or disable the internal LDO
 * 
 * @param pHrpwm Base address pointer of the HRPWM peripheral
 * @param bEnable True to enable the internal LDO, False to disable the internal LDO
 */
LOCAL_INLINE void HRPWM_HWA_SetInternalLDOEnable(HRPWM_Type * const pHrpwm, bool bEnable)
{
    pHrpwm->ANA_CTRL = (pHrpwm->ANA_CTRL & (~HRPWM_ANA_CTRL_PH_LDOEN_MASK)) | HRPWM_ANA_CTRL_PH_LDOEN(bEnable);
}

/**
 * @brief Set bypass mode for the internal LDO
 * 
 * @param pHrpwm Base address pointer of the HRPWM peripheral
 * @param bEnable True to enable LDO bypass mode, False to disable LDO bypass mode
 */
LOCAL_INLINE void HRPWM_HWA_SetInternalLDOBypass(HRPWM_Type * const pHrpwm, bool bEnable)
{
    pHrpwm->ANA_CTRL = (pHrpwm->ANA_CTRL & (~HRPWM_ANA_CTRL_PH_LDOBYPASSEN_MASK)) | HRPWM_ANA_CTRL_PH_LDOBYPASSEN(bEnable);
}

/**
 * @brief Enable or disable phase generation
 * 
 * @param pHrpwm Base address pointer of the HRPWM peripheral
 * @param bEnable True to enable phase generation, False to disable phase generation
 */
LOCAL_INLINE void HRPWM_HWA_SetPhaseGeneration(HRPWM_Type * const pHrpwm, bool bEnable)
{
    pHrpwm->ANA_CTRL = (pHrpwm->ANA_CTRL & (~HRPWM_ANA_CTRL_PH_EN_MASK)) | HRPWM_ANA_CTRL_PH_EN(bEnable);
}

/**
 * @brief Set the value of the ANA_CTRL register
 * 
 * @param pHrpwm Base address pointer of the HRPWM peripheral
 * @param u32Value The value to set for the ANA_CTRL register
 */
LOCAL_INLINE void HRPWM_HWA_SetANACtrl(HRPWM_Type * const pHrpwm, uint32_t u32Value)
{
    pHrpwm->ANA_CTRL = u32Value;
}

/**
 * @brief Get the value of the ANA_CTRL register
 * 
 * @param pHrpwm Base address pointer of the HRPWM peripheral
 * @return uint32_t The value of the ANA_CTRL register
 */
LOCAL_INLINE uint32_t HRPWM_HWA_GetANACtrl(HRPWM_Type * const pHrpwm)
{
    return pHrpwm->ANA_CTRL;
}

/**
 * @brief Check if the analog power is OK
 * 
 * @param pHrpwm Base address pointer of the HRPWM peripheral
 * @return true If the analog power is OK, otherwise false
 */
LOCAL_INLINE bool HRPWM_HWA_GetAnolagPowerOK(HRPWM_Type * const pHrpwm)
{
    return (bool)((pHrpwm->ANA_CTRL & HRPWM_ANA_CTRL_ANA_POWER_OK_MASK) >> HRPWM_ANA_CTRL_ANA_POWER_OK_SHIFT);
}

/**
 * @brief Check if phase generation is locked
 * 
 * @param pHrpwm Base address pointer of the HRPWM peripheral
 * @return true If phase generation is locked, otherwise false
 */
LOCAL_INLINE bool HRPWM_HWA_GetPhaseGenLock(HRPWM_Type * const pHrpwm)
{
    return (bool)pHrpwm->ANA_CTRL & HRPWM_ANA_CTRL_PH_LOCK_MASK;
}

/**
 * @brief Unlock HRPWM registers for write operations
 * 
 * @param pHrpwm Base address pointer of the HRPWM peripheral
 */
LOCAL_INLINE void HRPWM_HWA_UnlockRegisterWrite(HRPWM_Type * const pHrpwm)
{
    pHrpwm->LOCK_CTRL = HRPWM_UNLOCK_WRITE_CODE;
}

/**
 * @brief Lock HRPWM registers to prevent write operations
 * 
 * @param pHrpwm Base address pointer of the HRPWM peripheral
 */
LOCAL_INLINE void HRPWM_HWA_LockRegisterWrite(HRPWM_Type * const pHrpwm)
{
    pHrpwm->LOCK_CTRL = HRPWM_LOCK_WRITE_CODE;
}

/**
 * @brief Set fault software release mode
 * 
 * @param pHrpwm Base address pointer of the HRPWM peripheral
 * @param u8Channel The HRPWM channel number to configure
 * @param bSwRelease True: fault release by writing FAULT_STATUS, False: fault release without software
 */
LOCAL_INLINE void HRPWM_HWA_SetSWFaultRelease(HRPWM_Type * const pHrpwm, uint8_t u8Channel, bool bSwRelease)
{
    pHrpwm->FAULT_SW_CTRL_EN = (pHrpwm->FAULT_SW_CTRL_EN & (~(1U << u8Channel))) | ((uint32_t)bSwRelease << u8Channel);
}

/**
 * @brief Get fault status
 * 
 * @param pHrpwm Base address pointer of the HRPWM peripheral
 * @return uint8_t The current fault status
 */
LOCAL_INLINE uint8_t HRPWM_HWA_GetFaultStatus(HRPWM_Type * const pHrpwm)
{
    return (uint8_t)(pHrpwm->FAULT_STATUS & HRPWM_FAULT_STATUS_MASK);
}

/**
 * @brief Clear fault status
 * 
 * @param pHrpwm Base address pointer of the HRPWM peripheral
 * @param u8Mask The fault status mask to clear
 */
LOCAL_INLINE void HRPWM_HWA_ClearFaultStatus(HRPWM_Type * const pHrpwm, uint8_t u8Mask)
{
    pHrpwm->FAULT_STATUS = (uint32_t)u8Mask;
}

/**
 * @brief Set the value of the EN_CTRL register
 *
 * @param pHrpwm Base address pointer of the HRPWM peripheral
 * @param u32Value The value to set for the EN_CTRL register
 */
LOCAL_INLINE void HRPWM_HWA_SetENCtrl(HRPWM_Type * const pHrpwm, uint32_t u32Value)
{
    pHrpwm->EN_CTRL = u32Value;
}

/**
 * @brief Set the value of the BYPASS_CTRL register
 *
 * @param pHrpwm Base address pointer of the HRPWM peripheral
 * @param u32Value The value to set for the BYPASS_CTRL register
 */
LOCAL_INLINE void HRPWM_HWA_SetBypassCtrl(HRPWM_Type * const pHrpwm, uint32_t u32Value)
{
    pHrpwm->BYPASS_CTRL = u32Value;
}

/**
 * @brief Set the value of the FAULT_BYPASS_CTRL register
 *
 * @param pHrpwm Base address pointer of the HRPWM peripheral
 * @param u32Value The value to set for the FAULT_BYPASS_CTRL register
 */
LOCAL_INLINE void HRPWM_HWA_SetFltBypassCtrl(HRPWM_Type * const pHrpwm, uint32_t u32Value)
{
    pHrpwm->FAULT_BYPASS_CTRL = u32Value;
}

/**
 * @brief Set the value of the FAULT_SW_CTRL_EN register
 *
 * @param pHrpwm Base address pointer of the HRPWM peripheral
 * @param u32Value The value to set for the FAULT_SW_CTRL_EN register
 */
LOCAL_INLINE void HRPWM_HWA_SetFltSWCtrl(HRPWM_Type * const pHrpwm, uint32_t u32Value)
{
    pHrpwm->FAULT_SW_CTRL_EN = u32Value;
}

/** @}*/

#endif  /* defined(HRPWM_INSTANCE_COUNT) && (HRPWM_INSTANCE_COUNT > 0U) */
#endif  /* _HWA_HRPWM_H_ */


