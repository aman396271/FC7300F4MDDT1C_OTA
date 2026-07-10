/**
 * @file        HwA_eim.h
 * @author      Flagchip0100
 * @brief       EIM Module Register API
 * @version 2.0.0
 * @date        2024-08-20
 *
 * SDK Version: 2.6.0
 *

 * @copyright   Copyright 2020-2024 Flagchip Semiconductors Co., Ltd.
 */

/* ********************************************************************************
   *   Revision History:
   *
   *   Version     Date          Initials      CR#          Descriptions
   *   ---------   ----------    ------------  ----------   ---------------
   *   0.1.0      2023-12-15     Flagchip052   N/A          First version for FC7300
   *   2.0.0      2024-10-12     Flagchip100   N/A          Change version and release
   ******************************************************************************** */

#ifndef _HWA_EIM_H_
#define _HWA_EIM_H_

#include "device_header.h"

#if (EIM_INSTANCE_COUNT > 0U)

#if defined(__cplusplus)
extern "C" {
#endif

/**
 * @defgroup HwA_eim HwA_eim
 * @ingroup module_driver_eim
 * @{
 */

/*******************************************************************************
 * Local inline function
 ******************************************************************************/
/**
 * @brief Enable EIM Global Error Injection.
 *
 * @param pEim EIM Instance.
 */
LOCAL_INLINE void EIM_HWA_EnableGlobalErrorInjection(EIM_Type *const pEim)
{
    pEim->CR = EIM_CR_GEIEN(1U);
}

/**
 * @brief Disable EIM Global Error Injection.
 *
 * @param pEim EIM Instance.
 */
LOCAL_INLINE void EIM_HWA_DisableGlobalErrorInjection(EIM_Type *const pEim)
{
    pEim->CR = EIM_CR_GEIEN(0U);
}

/**
 * @brief  Get EIM channel N control register value.
 *
 * @param pEim EIM Instance.
 * @param u8Idx Control register index.
 * @return EIM channel N control register value.
 */
LOCAL_INLINE uint32_t EIM_HWA_GetCtrlRegn(const EIM_Type *const pEim, uint8_t u8Idx)
{
    return pEim->CTRL_REG[u8Idx];
}

/**
 * @brief Set EIM channel N control register value.
 *
 * @param pEim EIM Instance.
 * @param u8Idx Control register index.
 * @param u32Value Register value.
 */
LOCAL_INLINE void EIM_HWA_SetCtrlRegn(EIM_Type *const pEim, uint8_t u8Idx, uint32_t u32Value)
{
    pEim->CTRL_REG[u8Idx] = u32Value;
}

/**
 * @brief Get EIM_CTRL_REGn register DWP lock status.
 * 
 * @param pEim EIM Instance.
 * @param u8Idx Control register index.
 * @return Lock status.
 */
LOCAL_INLINE bool EIM_HWA_GetCtrlRegnDwpLockStatus(const EIM_Type *const pEim, uint8_t u8Idx)
{
    return ((pEim->CTRL_REG[u8Idx] & EIM_CTRL_REG_DWP_LOCK_MASK) != 0U) ? true : false;
}

/**
 * @brief  Set EIM_CTRL_REGn register DWP lock status.
 *
 * @param pEim EIM Instance.
 * @param u8Idx Control register index.
 * @param bEnable Enable or disable.
 */
LOCAL_INLINE void EIM_HWA_SetCtrlRegnDwpLock(EIM_Type *const pEim, uint8_t u8Idx, bool bEnable)
{
    pEim->CTRL_REG[u8Idx] = (pEim->CTRL_REG[u8Idx] & ~((uint32_t)EIM_CTRL_REG_DWP_LOCK_MASK)) | EIM_CTRL_REG_DWP_LOCK(bEnable);
}

/**
 * @brief  Set EIM_CTRL_REGn register DWP mode.
 *
 * @param pEim EIM Instance.
 * @param u8Idx Control register index.
 * @param u8DwpMode DWP mode.
 */
LOCAL_INLINE void EIM_HWA_SetCtrlRegnDwpMode(EIM_Type *const pEim, uint8_t u8Idx, uint8_t u8DwpMode)
{
    pEim->CTRL_REG[u8Idx] = (pEim->CTRL_REG[u8Idx] & ~((uint32_t)EIM_CTRL_REG_DWP_MASK)) | EIM_CTRL_REG_DWP(u8DwpMode);
}

/**
 * @brief  Set EIM LOCKSTEP error injection register.
 *
 * @param pEim EIM Instance.
 * @param u8Idx Control register index.
 * @param u32Value Register value.
 */
LOCAL_INLINE void EIM_HWA_SetLockstep(EIM_Type *const pEim, uint8_t u8Idx, uint32_t u32Value)
{
    pEim->LOCKSTEP[u8Idx] = u32Value;
}

/**
 * @brief  Get EIM bus n register value.
 *
 * @param pEim EIM Instance.
 * @param u8Idx Bus register index.
 * @return Register value.
 */
LOCAL_INLINE uint32_t EIM_HWA_GetBusRegn(const EIM_Type *const pEim, uint8_t u8Idx)
{
    return pEim->BUS_REG[u8Idx];
}

/**
 * @brief  Set EIM bus n register value.
 *
 * @param pEim EIM Instance.
 * @param u8Idx Control register index.
 * @param u32Value Register value.
 */
LOCAL_INLINE void EIM_HWA_SetBusRegn(EIM_Type *const pEim, uint8_t u8Idx, uint32_t u32Value)
{
    pEim->BUS_REG[u8Idx] = u32Value;
}

/** @}*/

#if defined(__cplusplus)
}
#endif

#endif /* (EIM_INSTANCE_COUNT > 0U) */

#endif /* _HWA_EIM_H_ */
