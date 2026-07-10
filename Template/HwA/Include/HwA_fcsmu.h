/**
 * @file        HwA_fcsmu.h
 * @author      Flagchip0100
 * @brief       FCSMU module register API
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

#ifndef _HWA_FCSMU_H_
#define _HWA_FCSMU_H_

#include "device_header.h"

#if (FCSMU_INSTANCE_COUNT > 0U)

#if defined(__cplusplus)
extern "C" {
#endif

/**
 * @defgroup HwA_fcsmu HwA_fcsmu
 * @ingroup module_driver_fcsmu
 * @{
 */

/*******************************************************************************
 * Local inline function
 ******************************************************************************/
/**
 * @brief Set the fcsmu CTRL register
 *
 * @param pFcsmu FCSMU Instance
 * @param u32Value The register value
 */
LOCAL_INLINE void FCSMU_HWA_SetCrtl(FCSMU_Type *const pFcsmu, uint32_t u32Value)
{
    pFcsmu->CTRL = u32Value;
}

/**
 * @brief Get the fcsmu CTRL register
 *
 * @param pFcsmu FCSMU Instance
 * @return CTRL register value
 */
LOCAL_INLINE uint32_t FCSMU_HWA_GetCtrl(const FCSMU_Type *const pFcsmu)
{
    return pFcsmu->CTRL;
}

/**
 * @brief Get the fcsmu CTRL register OPS
 *
 * @param pFcsmu FCSMU Instance
 * @return CTRL register OPS value
 */
LOCAL_INLINE uint32_t FCSMU_HWA_GetCtrlOps(const FCSMU_Type *const pFcsmu)
{
    return ((pFcsmu->CTRL & FCSMU_CTRL_OPS_MASK) >> FCSMU_CTRL_OPS_SHIFT);
}

/**
 * @brief Set the fcsmu OPRK register
 *
 * @param pFcsmu FCSMU Instance
 * @param u32Value The register value
 */
LOCAL_INLINE void FCSMU_HWA_SetOprk(FCSMU_Type *const pFcsmu, uint32_t u32Value)
{
    pFcsmu->OPRK = u32Value;
}

/**
 * @brief Set the fcsmu SOCTRL register
 *
 * @param pFcsmu FCSMU Instance
 * @param u32Value The register value
 */
LOCAL_INLINE void FCSMU_HWA_SetSoctrl(FCSMU_Type *const pFcsmu, uint32_t u32Value)
{
    pFcsmu->SOCTRL = u32Value;
}

/**
 * @brief Get the fcsmu SOCTRL register
 *
 * @param pFcsmu FCSMU Instance
 * @return SOCTRL register value
 */
LOCAL_INLINE uint32_t FCSMU_HWA_GetSoctrl(const FCSMU_Type *const pFcsmu)
{
    return pFcsmu->SOCTRL;
}

/**
 * @brief Set the fcsmu FCCR0 register
 *
 * @param pFcsmu FCSMU Instance
 * @param u32Value FCCR0 register value
 */
LOCAL_INLINE void FCSMU_HWA_SetFccr0(FCSMU_Type *const pFcsmu, uint32_t u32Value)
{
    pFcsmu->FCCR0 = u32Value;
}

/**
 * @brief Get the fcsmu FCCR0 register
 *
 * @param pFcsmu FCSMU Instance
 * @return FCCR0 register value
 */
LOCAL_INLINE uint32_t FCSMU_HWA_GetFccr0(const FCSMU_Type *const pFcsmu)
{
    return pFcsmu->FCCR0;
}

/**
 * @brief Set the fcsmu FRST0 register
 *
 * @param pFcsmu FCSMU Instance
 * @param u32Value FRST0 register value
 */
LOCAL_INLINE void FCSMU_HWA_SetFrst0(FCSMU_Type *const pFcsmu, uint32_t u32Value)
{
    pFcsmu->FRST0 = u32Value;
}

/**
 * @brief Get the fcsmu FRST0 register
 *
 * @param pFcsmu FCSMU Instance
 * @return FRST0 register value
 */
LOCAL_INLINE uint32_t FCSMU_HWA_GetFrst0(const FCSMU_Type *const pFcsmu)
{
    return pFcsmu->FRST0;
}

/**
 * @brief Set the fcsmu FST0 register
 *
 * @param pFcsmu FCSMU Instance
 * @param u32Value FST0 register value
 */
LOCAL_INLINE void FCSMU_HWA_SetFst0(FCSMU_Type *const pFcsmu, uint32_t u32Value)
{
    pFcsmu->FST0 = u32Value;
}

/**
 * @brief Get the fcsmu FST0 register
 *
 * @param pFcsmu FCSMU Instance
 * @return FST0 register value
 */
LOCAL_INLINE uint32_t FCSMU_HWA_GetFst0(const FCSMU_Type *const pFcsmu)
{
    return pFcsmu->FST0;
}

/**
 * @brief Set the fcsmu FST_UNLK register
 *
 * @param pFcsmu FCSMU Instance
 * @param u32Value FST_UNLK register value
 */
LOCAL_INLINE void FCSMU_HWA_SetFstUnlk(FCSMU_Type *const pFcsmu, uint32_t u32Value)
{
    pFcsmu->FST_UNLK = u32Value;
}

/**
 * @brief Set the fcsmu FE0 register
 *
 * @param pFcsmu FCSMU Instance
 * @param u32Value FE0 register value
 */
LOCAL_INLINE void FCSMU_HWA_SetFe0(FCSMU_Type *const pFcsmu, uint32_t u32Value)
{
    pFcsmu->FE0 = u32Value;
}

/**
 * @brief Get the fcsmu FE0 register
 *
 * @param pFcsmu FCSMU Instance
 * @return FE0 register value
 */
LOCAL_INLINE uint32_t FCSMU_HWA_GetFe0(const FCSMU_Type *const pFcsmu)
{
    return pFcsmu->FE0;
}

/**
 * @brief Set the fcsmu WARNING_EN0 register
 *
 * @param pFcsmu FCSMU Instance
 * @param u32Value WARNING_EN0 register value
 */
LOCAL_INLINE void FCSMU_HWA_SetWarningEn0(FCSMU_Type *const pFcsmu, uint32_t u32Value)
{
    pFcsmu->WARNING_EN0 = u32Value;
}

/**
 * @brief Get the fcsmu WARNING_EN0 register
 *
 * @param pFcsmu FCSMU Instance
 * @return WARNING_EN0 register value
 */
LOCAL_INLINE uint32_t FCSMU_HWA_GetWarningEn0(const FCSMU_Type *const pFcsmu)
{
    return pFcsmu->WARNING_EN0;
}

/**
 * @brief Set the fcsmu WARNING_TO register
 *
 * @param pFcsmu FCSMU Instance
 * @param u32Value WARNING_TO register value
 */
LOCAL_INLINE void FCSMU_HWA_SetWarningTo(FCSMU_Type *const pFcsmu, uint32_t u32Value)
{
    pFcsmu->WARNING_TO = u32Value;
}

/**
 * @brief Get the fcsmu WARNING_TO register
 *
 * @param pFcsmu FCSMU Instance
 * @return WARNING_TO register value
 */
LOCAL_INLINE uint32_t FCSMU_HWA_GetWarningTo(const FCSMU_Type *const pFcsmu)
{
    return pFcsmu->WARNING_TO;
}

/**
 * @brief Set the fcsmu CFG_TO register
 *
 * @param pFcsmu FCSMU Instance
 * @param u32Value CFG_TO register value
 */
LOCAL_INLINE void FCSMU_HWA_SetCfgTo(FCSMU_Type *const pFcsmu, uint32_t u32Value)
{
    pFcsmu->CFG_TO = u32Value;
}

/**
 * @brief Get the fcsmu CFG_TO register
 *
 * @param pFcsmu FCSMU Instance
 * @return CFG_TO register value
 */
LOCAL_INLINE uint32_t FCSMU_HWA_GetCfgTo(const FCSMU_Type *const pFcsmu)
{
    return pFcsmu->CFG_TO;
}

/**
 * @brief Set the fcsmu SOUT_DIAG register
 *
 * @param pFcsmu FCSMU Instance
 * @param u32Value SOUT_DIAG register value
 */
LOCAL_INLINE void FCSMU_HWA_SetSoutDiag(FCSMU_Type *const pFcsmu, uint32_t u32Value)
{
    pFcsmu->SOUT_DIAG = u32Value;
}

/**
 * @brief Get the fcsmu SOUT_DIAG register
 *
 * @param pFcsmu FCSMU Instance
 * @return SOUT_DIAG register value
 */
LOCAL_INLINE uint32_t FCSMU_HWA_GetSoutDiag(const FCSMU_Type *const pFcsmu)
{
    return pFcsmu->SOUT_DIAG;
}

/**
 * @brief Get the fcsmu STATUS register
 *
 * @param pFcsmu FCSMU Instance
 * @return STATUS register value
 */
LOCAL_INLINE uint32_t FCSMU_HWA_GetStatus(const FCSMU_Type *const pFcsmu)
{
    return pFcsmu->STATUS;
}

/**
 * @brief Get the fcsmu STATUS register FIF value
 *
 * @param pFcsmu FCSMU Instance
 * @return STATUS register FIF value
 */
LOCAL_INLINE bool FCSMU_HWA_GetFaultState(const FCSMU_Type *const pFcsmu)
{
    return ((pFcsmu->STATUS & FCSMU_STATUS_FIF_MASK) == FCSMU_STATUS_FIF_MASK) ? true : false;
}

/**
 * @brief Get the fcsmu STATUS register STAT value
 *
 * @param pFcsmu FCSMU Instance
 * @return STATUS register STAT value
 */
LOCAL_INLINE uint32_t FCSMU_HWA_GetFcsmuState(const FCSMU_Type *const pFcsmu)
{
    return ((pFcsmu->STATUS & FCSMU_STATUS_STAT_MASK) >> FCSMU_STATUS_STAT_SHIFT);
}

/**
 * @brief Get the fcsmu NTW register
 *
 * @param pFcsmu FCSMU Instance
 * @return NTW register value
 */
LOCAL_INLINE uint32_t FCSMU_HWA_GetNtw(const FCSMU_Type *const pFcsmu)
{
    return pFcsmu->NTW;
}

/**
 * @brief Get the fcsmu WTF register
 *
 * @param pFcsmu FCSMU Instance
 * @return WTF register value
 */
LOCAL_INLINE uint32_t FCSMU_HWA_GetWtf(const FCSMU_Type *const pFcsmu)
{
    return pFcsmu->WTF;
}

/**
 * @brief Get the fcsmu NTF register
 *
 * @param pFcsmu FCSMU Instance
 * @return NTF register value
 */
LOCAL_INLINE uint32_t FCSMU_HWA_GetNtf(const FCSMU_Type *const pFcsmu)
{
    return pFcsmu->NTF;
}

/**
 * @brief Get the fcsmu FTW register
 *
 * @param pFcsmu FCSMU Instance
 * @return FTW register value
 */
LOCAL_INLINE uint32_t FCSMU_HWA_GetFtw(const FCSMU_Type *const pFcsmu)
{
    return pFcsmu->FTW;
}

/**
 * @brief Set the fcsmu INJECT register
 *
 * @param pFcsmu FCSMU Instance
 * @param u32Value INJECT register value
 */
LOCAL_INLINE void FCSMU_HWA_SetInject(FCSMU_Type *const pFcsmu, uint32_t u32Value)
{
    pFcsmu->INJECT = u32Value;
}

/**
 * @brief Get the fcsmu IRQ_STAT register
 *
 * @param pFcsmu FCSMU Instance
 * @return IRQ_STAT register value
 */
LOCAL_INLINE uint32_t FCSMU_HWA_GetIrqStat(const FCSMU_Type *const pFcsmu)
{
    return pFcsmu->IRQ_STAT;
}

/**
 * @brief Clear the fcsmu IRQ_STAT register
 *
 * @param pFcsmu FCSMU Instance
 */
LOCAL_INLINE void FCSMU_HWA_ClearCfgToIrq(FCSMU_Type *const pFcsmu)
{
    pFcsmu->IRQ_STAT = FCSMU_IRQ_STAT_CFG_TO_IRQ_MASK;
}

/**
 * @brief Set the fcsmu IRQ_EN register
 *
 * @param pFcsmu FCSMU Instance
 * @param bEnable IRQ_EN register value
 */
LOCAL_INLINE void FCSMU_HWA_EnableCfgToIrq(FCSMU_Type *const pFcsmu, bool bEnable)
{
    pFcsmu->IRQ_EN = FCSMU_IRQ_EN_CFG_TO_IEN(bEnable);
}

/**
 * @brief Set the fcsmu TEMP_UNLK register
 *
 * @param pFcsmu FCSMU Instance
 * @param u32Value TEMP_UNLK register value
 */
LOCAL_INLINE void FCSMU_HWA_SetTempUnlk(FCSMU_Type *const pFcsmu, uint32_t u32Value)
{
    pFcsmu->TEMP_UNLK = u32Value;
}

/**
 * @brief Set the fcsmu PERMNT_LOCK register
 *
 * @param pFcsmu FCSMU Instance
 * @param u32Value PERMNT_LOCK register value
 */
LOCAL_INLINE void FCSMU_HWA_SetPermntLock(FCSMU_Type *const pFcsmu, uint32_t u32Value)
{
    pFcsmu->PERMNT_LOCK = u32Value;
}

/**
 * @brief Set the fcsmu STMR register
 *
 * @param pFcsmu FCSMU Instance
 * @param u32Value STMR register value
 */
LOCAL_INLINE void FCSMU_HWA_SetStmr(FCSMU_Type *const pFcsmu, uint32_t u32Value)
{
    pFcsmu->STMR = u32Value;
}

/**
 * @brief Set the fcsmu WARNING_IEN0 register
 *
 * @param pFcsmu FCSMU Instance
 * @param u32Value WARNING_IEN0 register value
 */
LOCAL_INLINE void FCSMU_HWA_SetWarningIen0(FCSMU_Type *const pFcsmu, uint32_t u32Value)
{
    pFcsmu->WARNING_IEN0 = u32Value;
}

/**
 * @brief Set the fcsmu FAULT_IEN0 register
 *
 * @param pFcsmu FCSMU Instance
 * @param u32Value FAULT_IEN0 register value
 */
LOCAL_INLINE void FCSMU_HWA_SetFaultIen0(FCSMU_Type *const pFcsmu, uint32_t u32Value)
{
    pFcsmu->FAULT_IEN0 = u32Value;
}

/**
 * @brief Set the fcsmu SOUT_EN0 register
 *
 * @param pFcsmu FCSMU Instance
 * @param u32Value SOUT_EN0 register value
 */
LOCAL_INLINE void FCSMU_HWA_SetSoutEn0(FCSMU_Type *const pFcsmu, uint32_t u32Value)
{
    pFcsmu->SOUT_EN0 = u32Value;
}

/**
 * @brief Get the fcsmu WARNING_TMR register
 *
 * @param pFcsmu FCSMU Instance
 * @return WARNING_TMR register value
 */
LOCAL_INLINE uint32_t FCSMU_HWA_GetWarningTmr(const FCSMU_Type *const pFcsmu)
{
    return pFcsmu->WARNING_TMR;
}

/**
 * @brief Get the fcsmu SM_TMR register
 *
 * @param pFcsmu FCSMU Instance
 * @return SM_TMR register value
 */
LOCAL_INLINE uint32_t FCSMU_HWA_GetSafeModeTmr(const FCSMU_Type *const pFcsmu)
{
    return pFcsmu->SM_TMR;
}

/**
 * @brief Get the fcsmu CFG_TMR register
 *
 * @param pFcsmu FCSMU Instance
 * @return CFG_TMR register value
 */
LOCAL_INLINE uint32_t FCSMU_HWA_GetCfgTmr(const FCSMU_Type *const pFcsmu)
{
    return pFcsmu->CFG_TMR;
}

/**
 * @brief Get the fcsmu SOUT_TMR register
 *
 * @param pFcsmu FCSMU Instance
 * @return SOUT_TMR register value
 */
LOCAL_INLINE uint32_t FCSMU_HWA_GetSoutTmr(const FCSMU_Type *const pFcsmu)
{
    return pFcsmu->SOUT_TMR;
}

/**
 * @brief Set the fcsmu CRC_CTRL register
 *
 * @param pFcsmu FCSMU Instance
 * @param u32Value CRC_CTRL register value
 */
LOCAL_INLINE void FCSMU_HWA_SetCrcCtrl(FCSMU_Type *const pFcsmu, uint32_t u32Value)
{
    pFcsmu->CRC_CTRL = u32Value;
}

/**
 * @brief Get the fcsmu CRC_CTRL register BUSY value
 *
 * @param pFcsmu FCSMU Instance
 * @return BUSY value
 */
LOCAL_INLINE bool FCSMU_HWA_GetCrcBusy(const FCSMU_Type *const pFcsmu)
{
    bool bRet = false;
#ifdef FCSMU_CRC_CTRL_DONE_SUPPORT
    bRet = ((pFcsmu->CRC_CTRL & FCSMU_CRC_CTRL_DONE_MASK) == FCSMU_CRC_CTRL_DONE_MASK) ? false : true;
#else
    bRet = ((pFcsmu->CRC_CTRL & FCSMU_CRC_CTRL_BUSY_MASK) == FCSMU_CRC_CTRL_BUSY_MASK) ? true : false;
#endif /* FCSMU_CRC_CTRL_DONE_SUPPORT */

    return bRet;
}

/**
 * @brief Get the fcsmu CRC_CTRL register EF value
 *
 * @param pFcsmu FCSMU Instance
 * @return EF value
 */
LOCAL_INLINE bool FCSMU_HWA_GetCrcErrorFlag(const FCSMU_Type *const pFcsmu)
{
    return ((pFcsmu->CRC_CTRL & FCSMU_CRC_CTRL_EF_MASK) == FCSMU_CRC_CTRL_EF_MASK) ? true : false;
}

/**
 * @brief Clear the fcsmu CRC_CTRL register EF
 *
 * @param pFcsmu FCSMU Instance
 */
LOCAL_INLINE void FCSMU_HWA_ClearCrcErrorFlag(FCSMU_Type *const pFcsmu)
{
    uint32_t u32RegValue = pFcsmu->CRC_CTRL;
    /* Reserve RW bits */
    u32RegValue = u32RegValue & (FCSMU_CRC_CTRL_EOEN_MASK |
                                 FCSMU_CRC_CTRL_CHKEN_MASK |
                                 FCSMU_CRC_CTRL_TRGEN_MASK);
    u32RegValue = u32RegValue | FCSMU_CRC_CTRL_EF_MASK;
    pFcsmu->CRC_CTRL = u32RegValue;
}

#ifdef FCSMU_CRC_CTRL_DONE_SUPPORT
/**
 * @brief Clear the fcsmu CRC_CTRL register DONE
 *
 * @param pFcsmu FCSMU Instance
 */
LOCAL_INLINE void FCSMU_HWA_ClearCrcDoneFlag(FCSMU_Type *const pFcsmu)
{
    uint32_t u32RegValue = pFcsmu->CRC_CTRL;
    /* Reserve RW bits */
    u32RegValue = u32RegValue & (FCSMU_CRC_CTRL_EOEN_MASK |
                                 FCSMU_CRC_CTRL_CHKEN_MASK |
                                 FCSMU_CRC_CTRL_TRGEN_MASK);
    u32RegValue = u32RegValue | FCSMU_CRC_CTRL_DONE_MASK;
    pFcsmu->CRC_CTRL = u32RegValue;
}
#endif

/**
 * @brief Set the fcsmu CRC_CTRL register
 *
 * @param pFcsmu FCSMU Instance
 * @param bEnable Enable or Disable CRC_CTRL register EOEN bit value
 */
LOCAL_INLINE void FCSMU_HWA_EnableErrorOutput(FCSMU_Type *const pFcsmu, bool bEnable)
{
    uint32_t u32RegValue = pFcsmu->CRC_CTRL;
    /* Reserve RW bits */
    u32RegValue = u32RegValue & (FCSMU_CRC_CTRL_CHKEN_MASK |
                                 FCSMU_CRC_CTRL_TRGEN_MASK);

    u32RegValue = (u32RegValue & ~FCSMU_CRC_CTRL_EOEN_MASK) | FCSMU_CRC_CTRL_EOEN(bEnable);
    pFcsmu->CRC_CTRL = u32RegValue;
}

/**
 * @brief Get the fcsmu CRC_CTRL register EOEN value
 *
 * @param pFcsmu FCSMU Instance
 * @return EOEN value
 */
LOCAL_INLINE bool FCSMU_HWA_GetCrcErrorOutputEnable(const FCSMU_Type *const pFcsmu)
{
    return ((pFcsmu->CRC_CTRL & FCSMU_CRC_CTRL_EOEN_MASK) == FCSMU_CRC_CTRL_EOEN_MASK) ? true : false;
}

/**
 * @brief Set the fcsmu CRC_CTRL register
 *
 * @param pFcsmu FCSMU Instance
 * @param bEnable CRC_CTRL register value
 */
LOCAL_INLINE void FCSMU_HWA_EnableCrcChecker(FCSMU_Type *const pFcsmu, bool bEnable)
{
    pFcsmu->CRC_CTRL = (pFcsmu->CRC_CTRL & ~FCSMU_CRC_CTRL_CHKEN_MASK) | FCSMU_CRC_CTRL_CHKEN(bEnable);
}

/**
 * @brief Get the fcsmu CRC_CTRL register CHKEN value
 *
 * @param pFcsmu FCSMU Instance
 * @return CHKEN value
 */
LOCAL_INLINE bool FCSMU_HWA_GetCrcCheckerEnable(const FCSMU_Type *const pFcsmu)
{
    return ((pFcsmu->CRC_CTRL & FCSMU_CRC_CTRL_CHKEN_MASK) == FCSMU_CRC_CTRL_CHKEN_MASK) ? true : false;
}

/**
 * @brief Set the fcsmu CRC_CTRL register
 *
 * @param pFcsmu FCSMU Instance
 * @param bEnable CRC_CTRL register value
 */
LOCAL_INLINE void FCSMU_HWA_EnableTrigger(FCSMU_Type *const pFcsmu, bool bEnable)
{
    pFcsmu->CRC_CTRL = (pFcsmu->CRC_CTRL & ~FCSMU_CRC_CTRL_TRGEN_MASK) | FCSMU_CRC_CTRL_TRGEN(bEnable);
}

/**
 * @brief Get the fcsmu CRC_CTRL register TRGEN value
 *
 * @param pFcsmu FCSMU Instance
 * @return TRGEN value
 */
LOCAL_INLINE bool FCSMU_HWA_GetTriggerEnable(const FCSMU_Type *const pFcsmu)
{
    return ((pFcsmu->CRC_CTRL & FCSMU_CRC_CTRL_TRGEN_MASK) == FCSMU_CRC_CTRL_TRGEN_MASK) ? true : false;
}

/**
 * @brief Set the fcsmu CRC_CTRL register
 *
 * @param pFcsmu FCSMU Instance
 */
LOCAL_INLINE void FCSMU_HWA_GenerateCrc(FCSMU_Type *const pFcsmu)
{
    uint32_t u32RegValue = pFcsmu->CRC_CTRL;
    /* Reserve RW bits */
    u32RegValue = u32RegValue & (FCSMU_CRC_CTRL_EOEN_MASK |
                                 FCSMU_CRC_CTRL_CHKEN_MASK |
                                 FCSMU_CRC_CTRL_TRGEN_MASK);
    u32RegValue = u32RegValue | FCSMU_CRC_CTRL_GEN(1U);
    pFcsmu->CRC_CTRL = u32RegValue;
}

/**
 * @brief Get the fcsmu CRC_RES register
 *
 * @param pFcsmu FCSMU Instance
 * @return CRC_RES register value
 */
LOCAL_INLINE uint32_t FCSMU_HWA_GetCrcResult(const FCSMU_Type *const pFcsmu)
{
    return pFcsmu->CRC_RES;
}


#if defined(__cplusplus)
}
#endif

/** @}*/

#endif /* (FCSMU_INSTANCE_COUNT > 0U) */

#endif /* _HWA_FCSMU_H_ */
