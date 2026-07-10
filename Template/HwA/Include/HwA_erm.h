/**
 * @file        HwA_erm.h
 * @author      Flagchip0100
 * @brief       ERM Module Register API
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

#ifndef _HWA_ERM_H_
#define _HWA_ERM_H_

#include "device_header.h"

#if (ERM_INSTANCE_COUNT > 0U)

#if defined(__cplusplus)
extern "C" {
#endif

/**
 * @defgroup HwA_erm HwA_erm
 * @ingroup module_driver_erm
 * @{
 */

/*******************************************************************************
 * Local inline function
 ******************************************************************************/
/**
 * @brief  set erm configuration register.
 *
 * @param pErm ERM Instance.
 * @param u8Idx Control register index.
 * @param u32RegValue access control value.
 */
LOCAL_INLINE void ERM_HWA_SetCRn(ERM_Type *const pErm, uint8_t u8Idx, uint32_t u32RegValue)
{
#ifdef ERM_CR4_SR4_SUPPORT
    if (u8Idx == 4U)
    {
        pErm->CR4 = u32RegValue;
    }
    else
#endif
    {
        pErm->CR[u8Idx] = u32RegValue;
    }
}

/**
 * @brief  get ERM configuration register.
 *
 * @param pErm ERM Instance.
 * @param u8Idx Control register index.
 * @return ERM CRn value.
 */
LOCAL_INLINE uint32_t ERM_HWA_GetCRn(const ERM_Type *const pErm, uint8_t u8Idx)
{
    uint32_t u32Value = 0U;
#ifdef ERM_CR4_SR4_SUPPORT
    if (u8Idx == 4U)
    {
        u32Value = pErm->CR4;
    }
    else
#endif
    {
        u32Value = pErm->CR[u8Idx];
    }
    return u32Value;
}

/**
 * @brief  set erm status register.
 *
 * @param pErm ERM Instance.
 * @param u8Idx Status register index.
 * @param u32RegValue  access control value.
 */
LOCAL_INLINE void ERM_HWA_SetSRn(ERM_Type *const pErm, uint8_t u8Idx, uint32_t u32RegValue)
{
#ifdef ERM_CR4_SR4_SUPPORT
    if (u8Idx == 4U)
    {
        pErm->SR4 = u32RegValue;
    }
    else
#endif
    {
        pErm->SR[u8Idx] = u32RegValue;
    }
}

/**
 * @brief  get ERM status register.
 *
 * @param pErm ERM Instance.
 * @param u8Idx Status register index.
 * @return  ERM SRn value.
 */
LOCAL_INLINE uint32_t ERM_HWA_GetSRn(const ERM_Type *const pErm, uint8_t u8Idx)
{
    uint32_t u32Value = 0U;
#ifdef ERM_CR4_SR4_SUPPORT
    if (u8Idx == 4U)
    {
        u32Value = pErm->SR4;
    }
    else
#endif
    {
        u32Value = pErm->SR[u8Idx];
    }
    return u32Value;;
}

/**
 * @brief  get ERM error address register.
 *
 * @param pErm ERM Instance.
 * @param u8Idx Error address register index.
 * @return  ERM error address register value.
 */
LOCAL_INLINE uint32_t ERM_HWA_GetEARn(const ERM_Type *const pErm, uint8_t u8Idx)
{
    return pErm->EAR[u8Idx].value;
}



#if defined(__cplusplus)
}
#endif

/** @}*/ /* HwA_erm */

#endif /* (ERM_INSTANCE_COUNT > 0U) */

#endif /* _HWA_ERM_H_ */
