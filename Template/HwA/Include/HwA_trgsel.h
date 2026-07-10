/**
 * @file HwA_trgsel.h
 * @author flagchip
 * @brief Hardware access layer for TrgSel
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
   *   0.1.0      2023-12-15     Flagchip030   N/A          First version for FC7300
   *   2.0.0      2024-10-12     Flagchip030   N/A          Change version and release
   ******************************************************************************** */

#ifndef _HWA_TRGSEL_H_
#define _HWA_TRGSEL_H_

#include "device_header.h"

#if TRGSEL_INSTANCE_COUNT > 0U

#define TRGSEL_REGSIZE 4U

/**
 * @defgroup HwA_trgsel HwA_trgsel
 * @ingroup module_driver_trgsel
 * @{
 */

/**
 * @brief Get the trigger source of the selected trigger target
 *
 * @param pTrgsel the base address of the TrgSel instance
 * @param u32TargetIndex the trigger target to get the trigger source
 * @return uint32_t the trigger source of the selected trigger target
 */
LOCAL_INLINE uint32_t TRGSEL_HWA_GetTargetTriggerSource(const TRGSEL_Type *const pTrgsel, uint32_t u32TargetIndex)
{
    uint32_t u32RegIdx = u32TargetIndex / TRGSEL_REGSIZE;
    uint32_t u32SelIdx = u32TargetIndex % TRGSEL_REGSIZE;

    uint32_t u32Tmp = pTrgsel->OUT_SEL[u32RegIdx];
    switch (u32SelIdx)
    {
        case 0U:
        {
            u32Tmp = (u32Tmp & TRGSEL_OUT_SEL_SEL_0_MASK) >> TRGSEL_OUT_SEL_SEL_0_SHIFT;
            break;
        }
        case 1U:
        {
            u32Tmp = (u32Tmp & TRGSEL_OUT_SEL_SEL_1_MASK) >> TRGSEL_OUT_SEL_SEL_1_SHIFT;
            break;
        }
        case 2U:
        {
            u32Tmp = (u32Tmp & TRGSEL_OUT_SEL_SEL_2_MASK) >> TRGSEL_OUT_SEL_SEL_2_SHIFT;
            break;
        }
        case 3U:
        {
            u32Tmp = (u32Tmp & TRGSEL_OUT_SEL_SEL_3_MASK) >> TRGSEL_OUT_SEL_SEL_3_SHIFT;
            break;
        }

        default:
            break;
    }

    return (uint32_t)u32Tmp;
}

/**
 * @brief Set the trigger source of the selected trigger target
 *
 * @param pTrgsel the base address of the TrgSel instance
 * @param u32TargetIndex the trigger target to set the trigger source
 * @param u32SourceIndex the selected trigger source to trig the target
 */
LOCAL_INLINE void TRGSEL_HWA_SetTargetTriggerSource(TRGSEL_Type *const pTrgsel, uint32_t u32TargetIndex,
        uint32_t u32SourceIndex)
{
    uint32_t u32RegIdx = u32TargetIndex / TRGSEL_REGSIZE;
    uint32_t u32SelIdx = u32TargetIndex % TRGSEL_REGSIZE;
    uint32_t u32Tmp = pTrgsel->OUT_SEL[u32RegIdx];

    switch (u32SelIdx)
    {
        case 0U:
        {
            u32Tmp = (u32Tmp & ~TRGSEL_OUT_SEL_SEL_0_MASK) | TRGSEL_OUT_SEL_SEL_0(u32SourceIndex);
            break;
        }
        case 1U:
        {
            u32Tmp = (u32Tmp & ~TRGSEL_OUT_SEL_SEL_1_MASK) | TRGSEL_OUT_SEL_SEL_1(u32SourceIndex);
            break;
        }
        case 2U:
        {
            u32Tmp = (u32Tmp & ~TRGSEL_OUT_SEL_SEL_2_MASK) | TRGSEL_OUT_SEL_SEL_2(u32SourceIndex);
            break;
        }
        case 3U:
        {
            u32Tmp = (u32Tmp & ~TRGSEL_OUT_SEL_SEL_3_MASK) | TRGSEL_OUT_SEL_SEL_3(u32SourceIndex);
            break;
        }

        default:
            break;
    }

    pTrgsel->OUT_SEL[u32RegIdx] = u32Tmp;
}

/**
 * @brief Get wether the trigger source of the selected target is locked
 *
 * @param pTrgsel the base address of the TrgSel instance
 * @param u32TargetIndex the trigger target to get the lock status
 * @return true the trigger source of the selected target cannot be modified
 * @return false the trigger source of the selected target can be modified
 */
LOCAL_INLINE bool TRGSEL_HWA_GetTargetLockStatus(const TRGSEL_Type *const pTrgsel, uint32_t u32TargetIndex)
{
    uint32_t u32RegIdx = u32TargetIndex / TRGSEL_REGSIZE;

    uint32_t u32Tmp = pTrgsel->OUT_SEL[u32RegIdx];
    u32Tmp = (u32Tmp & TRGSEL_OUT_SEL_LOCK_MASK) >> TRGSEL_OUT_SEL_LOCK_SHIFT;

    return (bool)((u32Tmp != 0U) ? true : false);
}

/**
 * @brief Lock the trigger source of the selected target
 *
 * @note The trigger target is grouped by four, so if you lock the trigger source of one target, the
 * adjacent three trigger targets in the same register group are also be locked. So please ensure the
 * trigger sources are not to be modified before lock the trigger target.
 *
 * @param pTrgsel the base address of the TrgSel instance
 * @param u32TargetIndex the trigger target to lock the trigger source
 */
LOCAL_INLINE void TRGSEL_HWA_LockTargetTriggerSource(TRGSEL_Type *const pTrgsel, uint32_t u32TargetIndex)
{
    uint32_t u32RegIdx = u32TargetIndex / TRGSEL_REGSIZE;

    pTrgsel->OUT_SEL[u32RegIdx] |= TRGSEL_OUT_SEL_LOCK_MASK;
}

/** @}*/

#endif /* #if TRGSEL_INSTANCE_COUNT > 0U */

#endif /* _HWA_TRGSEL_H_ */
