/**
 * @file        HwA_cmu.h
 * @author      Flagchip0100
 * @brief       CMU Module Register API
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
   *   0.1.0      2023-12-15     Flagchip100   N/A          First version for FC7300
   *   2.0.0      2024-10-12     Flagchip100   N/A          Change version and release
   ******************************************************************************** */

#ifndef _HWA_CMU_H_
#define _HWA_CMU_H_

#include "device_header.h"

#if (CMU_INSTANCE_COUNT > 0U)

#if defined(__cplusplus)
extern "C" {
#endif

/**
 * @defgroup HwA_cmu HwA_cmu
 * @ingroup module_driver_cmu
 * @{
 */

/*******************************************************************************
 * Local inline function
 ******************************************************************************/
/**
 * @brief Set Reference Window value.
 *
 * @param pCmu CMU Instance.
 * @param u32Temp Ref Window value.
 */
LOCAL_INLINE void CMU_HWA_SetRefWindow(CMU_Type *const pCmu, uint32_t u32Temp)
{
    pCmu->REF_WINDOW = u32Temp;
}

/**
 * @brief Set Minimun Counter value.
 *
 * @param pCmu CMU Instance.
 * @param u32Temp Min Count value.
 */
LOCAL_INLINE void CMU_HWA_SetMinCnts(CMU_Type *const pCmu, uint32_t u32Temp)
{
    pCmu->MIN = u32Temp;
}

/**
 * @brief Get Minimun Counter value.
 *
 * @param pCmu CMU Instance.
 * @return Min count value.
 */
LOCAL_INLINE uint32_t CMU_HWA_GetMinCnts(const CMU_Type *const pCmu)
{
    return (pCmu->MIN & CMU_MIN_MIN_MASK) >> CMU_MIN_MIN_SHIFT;
}

/**
 * @brief Set Maximun Counter value.
 *
 * @param pCmu CMU Instance.
 * @param u32Temp Max count value.
 */
LOCAL_INLINE void CMU_HWA_SetMaxCnts(CMU_Type *const pCmu, uint32_t u32Temp)
{
    pCmu->MAX = u32Temp;
}

/**
 * @brief Get Maximun Counter value.
 *
 * @param pCmu CMU Instance.
 * @return Max count value.
 */
LOCAL_INLINE uint32_t CMU_HWA_GetMaxCnts(const CMU_Type *const pCmu)
{
    return (pCmu->MAX & CMU_MAX_MAX_MASK) >> CMU_MAX_MAX_SHIFT;
}

/**
 * @brief Get Counter value.
 *
 * @param pCmu CMU Instance.
 * @return Counter value.
 */
LOCAL_INLINE uint32_t CMU_HWA_GetCount(const CMU_Type *const pCmu)
{
    return (pCmu->MON_CNT & CMU_MON_CNT_MON_CNT_MASK) >> CMU_MON_CNT_MON_CNT_SHIFT;
}

/**
 * @brief Set period window Counter.
 *
 * @param pCmu CMU Instance.
 * @param u32Temp Period value.
 */
LOCAL_INLINE void CMU_HWA_SetPeriodWindow(CMU_Type *const pCmu, uint32_t u32Temp)
{
    pCmu->PERIOD = (pCmu->PERIOD & ~((uint32_t)CMU_PERIOD_WINDOW_MASK)) | CMU_PERIOD_WINDOW(u32Temp);
}

/**
 * @brief Set period enble bit.
 *
 * @param pCmu CMU Instance.
 * @param bEnable Set enable bit.
 */
LOCAL_INLINE void CMU_HWA_SetPeriodEnable(CMU_Type *const pCmu, bool bEnable)
{
    pCmu->PERIOD = (pCmu->PERIOD & ~((uint32_t)CMU_PERIOD_EN_MASK)) | CMU_PERIOD_EN(bEnable);
}

/**
 * @brief Get period enble bit.
 *
 * @param pCmu CMU Instance.
 * @return Period mode enable bit.
 */
LOCAL_INLINE bool CMU_HWA_GetPeriodEnable(const CMU_Type *const pCmu)
{
    return ((pCmu->PERIOD & CMU_PERIOD_EN_MASK) == CMU_PERIOD_EN_MASK) ? true : false;
}

/**
 * @brief Set control register value.
 *
 * @param pCmu CMU Instance.
 * @param u32Temp Control value.
 */
LOCAL_INLINE void CMU_HWA_SetCtrl(CMU_Type *const pCmu, uint32_t u32Temp)
{
    pCmu->CTRL = u32Temp;
}

/**
 * @brief Get control register value.
 *
 * @param pCmu CMU Instance.
 * @return Control register value.
 */
LOCAL_INLINE uint32_t CMU_HWA_GetCtrl(const CMU_Type *const pCmu)
{
    return pCmu->CTRL;
}

/**
 * @brief Get status register value.
 *
 * @param pCmu CMU Instance.
 * @return Status register value.
 */
LOCAL_INLINE uint32_t CMU_HWA_GetST(const CMU_Type *const pCmu)
{
    return pCmu->ST;
}

/**
 * @brief Clear clock monitor status.
 *
 * @param pCmu CMU Instance.
 */
LOCAL_INLINE void CMU_HWA_ClsST(CMU_Type *const pCmu)
{
    pCmu->ST = CMU_ST_MIS_MASK | CMU_ST_LOC_MASK;
}

#ifdef CMU_CTRL_LP_SUPPORT
/**
 * @brief Enable Standby mode.
 *
 * @param pCmu CMU Instance.
 * @param bEnable Enable mode.
 */
LOCAL_INLINE void CMU_HWA_StanbyModeEnable(CMU_Type *const pCmu, bool bEnable)
{
    pCmu->CTRL = (pCmu->CTRL & ~((uint32_t)CMU_CTRL_LP_EN_MASK)) | CMU_CTRL_LP_EN(bEnable);
}
#endif

/**
 * @brief Enable Stop mode.
 *
 * @param pCmu CMU Instance.
 * @param bEnable Enable mode.
 */
LOCAL_INLINE void CMU_HWA_StopModeEnable(CMU_Type *const pCmu, bool bEnable)
{
    pCmu->CTRL = (pCmu->CTRL & ~((uint32_t)CMU_CTRL_STOP_EN_MASK)) | CMU_CTRL_STOP_EN(bEnable);
}

/**
 * @brief Enable Softeare Reset.
 *
 * @param pCmu CMU Instance.
 */
LOCAL_INLINE void CMU_HWA_SoftwareRST(CMU_Type *const pCmu)
{
    pCmu->CTRL |= CMU_CTRL_SW_RST_MASK;
}

/**
 * @brief Enable Software Reset.
 *
 * @param pCmu CMU Instance.
 * @return Software reset is done.
 */
LOCAL_INLINE bool CMU_HWA_GetSoftwareRST(const CMU_Type *const pCmu)
{
    return ((pCmu->CTRL & CMU_CTRL_SW_RST_MASK) == CMU_CTRL_SW_RST_MASK) ? true : false;
}

/**
 * @brief Enable low power restart mode.
 *
 * @param pCmu CMU Instance.
 * @param bEnable Enable mode.
 */
LOCAL_INLINE void CMU_HWA_LPRestartEnable(CMU_Type *const pCmu, bool bEnable)
{
    pCmu->CTRL = (pCmu->CTRL & ~((uint32_t)CMU_CTRL_RESTART_EN_MASK)) | CMU_CTRL_RESTART_EN(bEnable);
}

/** @}*/ /* HwA_cmu */

#if defined(__cplusplus)
}
#endif

#endif /* (CMU_INSTANCE_COUNT > 0U) */

#endif /* _HWA_CMU_H_ */
