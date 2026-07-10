/*
 * Hwa_eftu_spe.h
 *
 *  Created on: 2025年12月3日
 *      Author: qxw0076
 */

#ifndef TEMPLATE_HWA_INCLUDE_HWA_EFTU_SPE_H_
#define TEMPLATE_HWA_INCLUDE_HWA_EFTU_SPE_H_
#include "device_header.h"

#if (EFTU_INSTANCE_COUNT > 0U) && (EFTU_SPE_SUPPORT == STD_ON) && defined(EFTU_SPE_SUPPORT)

typedef enum
{
    EFTU_SPE_INSTANCE_0 = 0U,
    EFTU_SPE_INSTANCE_1 = 1U,
} EFTU_SPE_InstanceType;

typedef enum
{
    EFTU_SPE_UPDATETRIGGER_NIPD       = 0U,
    EFTU_SPE_UPDATETRIGGER_TOM        = 1U,
    EFTU_SPE_UPDATETRIGGER_NIPD_DELAY = 2U,
    EFTU_SPE_UPDATETRIGGER_TOM_DELAY  = 3U,
} EFTU_SPE_UpdateTriggerType;

typedef enum
{
    EFTU_SPE_EXUPDATETRIGGER_CH6_CM0 = 0U,
    EFTU_SPE_EXUPDATETRIGGER_CH7_CM0 = 1U,
    EFTU_SPE_EXUPDATETRIGGER_CH4_CM0 = 2U,
    EFTU_SPE_EXUPDATETRIGGER_CH5_CM0 = 3U,
} EFTU_SPE_UpdateExTriggerType;

typedef enum
{
    EFTU_SPE_REFTYPE_00 = 0U,
    EFTU_SPE_REFTYPE_01 = 1U,
    EFTU_SPE_REFTYPE_10 = 2U,
    EFTU_SPE_REFTYPE_11 = 3U,

} EFTU_SPE_RefSelectType;

typedef enum
{
    EFTU_SPE_OUT_REF_H   = 0U,
    EFTU_SPE_OUT_REF_L   = 1U,
    EFTU_SPE_OUT_CONST_0 = 2U,
    EFTU_SPE_OUT_CONST_1 = 3U,
} EFTU_SPE_PwmOutSelect;

typedef enum
{
    EFTU_SPE_HALL_INPUT_0 = 0u,
    EFTU_SPE_HALL_INPUT_1 = 1u,
} EFTU_SPE_HallLevel;

typedef struct
{
    EFTU_SPE_HallLevel eHallA_level;
    EFTU_SPE_HallLevel eHallB_level;
    EFTU_SPE_HallLevel eHallC_level;
    uint8              u8SpePtr;
    uint8              u8SpePtrBwd;
} EFTU_SPE_HallPattern;

typedef struct
{
    EFTU_SPE_PwmOutSelect ePwmoutpattern0;
    EFTU_SPE_PwmOutSelect ePwmoutpattern1;
    EFTU_SPE_PwmOutSelect ePwmoutpattern2;
    EFTU_SPE_PwmOutSelect ePwmoutpattern3;
    EFTU_SPE_PwmOutSelect ePwmoutpattern4;
    EFTU_SPE_PwmOutSelect ePwmoutpattern5;
} EFTU_SPE_OutPattern;

typedef enum
{
    CCM_CLK_RES_0 = 0U,
    CCM_CLK_RES_1 = 1U,
    CCM_CLK_RES_2 = 2U,
    CCM_CLK_RES_3 = 3U,
    CCM_CLK_RES_4 = 4U,
    CCM_CLK_RES_5 = 5U,
    CCM_CLK_RES_6 = 6U,
    CCM_CLK_RES_7 = 7U,
} EFTU_SPE_DelayClockSrc;

typedef enum
{
    DTM_AUX_IN0 = 0U,
    DTM_AUX_IN1 = 1U,
    DTM_AUX_IN2 = 2U,
    DTM_AUX_IN3 = 3U,
    DTM_AUX_IN4 = 4U,
    DTM_AUX_IN5 = 5U,
    DTM_AUX_IN6 = 6U,
    DTM_AUX_IN7 = 7U,
} EFTU_SPE_FastShutSrc;

typedef enum
{
    EFTU_SPE_PAT0 = 0U,
    EFTU_SPE_PAT1 = 1U,
    EFTU_SPE_PAT2 = 2U,
    EFTU_SPE_PAT3 = 3U,
    EFTU_SPE_PAT4 = 4U,
    EFTU_SPE_PAT5 = 5U,
    EFTU_SPE_PAT6 = 6U,
    EFTU_SPE_PAT7 = 7U,
} EFTU_SPE_OutPatternType;

typedef enum
{
    EFTU_SPE_OUT_PAT_PTR      = 0U,
    EFTU_SPE_OUT_PPAT_PTR_BWD = 1U,
    EFTU_SPE_OUT_PAT_6        = 2U,
    EFTU_SPE_OUT_PAT_7        = 3U,
} EFTU_SPE_ControlCmd;

LOCAL_INLINE void EFTU_SPE_ConfigPAT(EFTU_SPE_Type *const pSpe, uint32 u32HallPta)
{
    pSpe->HALL_IN_PAT = u32HallPta;
}

LOCAL_INLINE void EFTU_SPE_ConfigOutPwm(EFTU_SPE_Type *const pSpe, uint32 u32OutPwm, uint8 u8Channel)
{
    pSpe->PWM_OUT_PAT[u8Channel] = u32OutPwm;
}

LOCAL_INLINE void EFTU_SPE_ConfigOutputDirect(EFTU_SPE_Type *const pSpe, uint32 u32Outpattern)
{
    pSpe->PWM_OUT_CTRL = u32Outpattern;
}

LOCAL_INLINE void EFTU_SPE_ConfigNewInputIrq(EFTU_SPE_Type *const pSpe, boolean bEnable)
{
    if (bEnable == true)
    {
        pSpe->IRQ_EN |= EFTU_SPE_IRQ_EN_NIPD_EN_MASK;
    }
    else
    {
        pSpe->IRQ_EN &= ~EFTU_SPE_IRQ_EN_NIPD_EN_MASK;
    }
}

LOCAL_INLINE void EFTU_SPE_ConfigDircIrq(EFTU_SPE_Type *const pSpe, boolean bEnable)
{
    if (bEnable == true)
    {
        pSpe->IRQ_EN |= EFTU_SPE_IRQ_EN_DCHG_EN_MASK;
    }
    else
    {
        pSpe->IRQ_EN &= ~EFTU_SPE_IRQ_EN_DCHG_EN_MASK;
    }
}

LOCAL_INLINE void EFTU_SPE_ConfigEipdIrq(EFTU_SPE_Type *const pSpe, boolean bEnable)
{
    if (bEnable == true)
    {
        pSpe->IRQ_EN |= EFTU_SPE_IRQ_EN_EIPD_EN_MASK;
    }
    else
    {
        pSpe->IRQ_EN &= ~EFTU_SPE_IRQ_EN_EIPD_EN_MASK;
    }
}

LOCAL_INLINE void EFTU_SPE_ConfigBieIrq(EFTU_SPE_Type *const pSpe, boolean bEnable)
{
    if (bEnable == true)
    {
        pSpe->IRQ_EN |= EFTU_SPE_IRQ_EN_BIE_EN_MASK;
    }
    else
    {
        pSpe->IRQ_EN &= ~EFTU_SPE_IRQ_EN_BIE_EN_MASK;
    }
}

LOCAL_INLINE void EFTU_SPE_ConfigRcmpIrq(EFTU_SPE_Type *const pSpe, boolean bEnable)
{
    if (bEnable == true)
    {
        pSpe->IRQ_EN |= EFTU_SPE_IRQ_EN_RCMP_EN_MASK;
    }
    else
    {
        pSpe->IRQ_EN &= ~EFTU_SPE_IRQ_EN_RCMP_EN_MASK;
    }
}

LOCAL_INLINE uint8 EFTU_SPE_GetIrqFlag(EFTU_SPE_Type *const pSpe)
{
    return (uint8)((pSpe->IRQ_ST & EFTU_SPE_IRQ_ST_MASK));
}

LOCAL_INLINE uint8 EFTU_SPE_GetIrqnbleBit(EFTU_SPE_Type *const pSpe)
{
    return (uint8)((pSpe->IRQ_EN & EFTU_SPE_IRQ_EN_MASK));
}

LOCAL_INLINE void EFTU_SPE_ClearIrqMask(EFTU_SPE_Type *const pSpe, uint32 u32IrqMask)
{
    pSpe->IRQ_ST = u32IrqMask;
}

LOCAL_INLINE void EFTU_SPE_SetCmpcntValue(EFTU_SPE_Type *const pSpe, uint32 u32CmpValue)
{
    pSpe->REV_CMP = u32CmpValue;
}

LOCAL_INLINE void EFTU_SPE_SetIputcntValue(EFTU_SPE_Type *const pSpe, uint32 u32RevValue)
{
    pSpe->REV_CNT = u32RevValue;
}

LOCAL_INLINE void EFTU_SPE_SoftWareTrigger(EFTU_SPE_Type *const pSpe)
{
    pSpe->CMD |= EFTU_SPE_CMD_SW_UPD_TRG_MASK;
}

LOCAL_INLINE void EFTU_SPE_SetCmd(EFTU_SPE_Type *const pSpe, EFTU_SPE_ControlCmd eControlcmd)
{
    pSpe->CMD = ((pSpe->CMD & ~EFTU_SPE_CMD_CTRL_CMD_MASK) | (uint32)eControlcmd);
}

LOCAL_INLINE void EFTU_SPE_SetFastshutSrc(EFTU_SPE_Type *const pSpe, EFTU_SPE_FastShutSrc eFastShut)
{
    pSpe->CTRL2 = ((pSpe->CTRL2 & ~EFTU_SPE_CTRL2_FSOI_SEL_MASK) | EFTU_SPE_CTRL2_FSOI_SEL(eFastShut));
}

LOCAL_INLINE void EFTU_SPE_SetDelayClkSrc(EFTU_SPE_Type *const pSpe, EFTU_SPE_DelayClockSrc eClockSrc)
{
    pSpe->CTRL2 = ((pSpe->CTRL2 & ~EFTU_SPE_CTRL2_DTRG_CLK_SEL_MASK) |
                   EFTU_SPE_CTRL2_DTRG_CLK_SEL(eClockSrc));
}

LOCAL_INLINE void EFTU_SPE_SetDelaycount(EFTU_SPE_Type *const pSpe, uint8 u8cnt)
{
    pSpe->CTRL2 = ((pSpe->CTRL2 & ~EFTU_SPE_CTRL2_DTRG_VAL_MASK) | EFTU_SPE_CTRL2_DTRG_VAL(u8cnt));
}

LOCAL_INLINE void EFTU_SPE_SetPatPtrBwd(EFTU_SPE_Type *const pSpe, EFTU_SPE_OutPatternType ePtrBwd)
{
    pSpe->CTRL2 = ((pSpe->CTRL2 & ~EFTU_SPE_CTRL2_PTR_BWD_MASK) | EFTU_SPE_CTRL2_PTR_BWD(ePtrBwd));
}

LOCAL_INLINE void EFTU_SPE_Enable(EFTU_SPE_Type *const pSpe)
{
    pSpe->CTRL |= EFTU_SPE_CTRL_EN_MASK;
}

LOCAL_INLINE void EFTU_SPE_Disable(EFTU_SPE_Type *const pSpe)
{
    pSpe->CTRL &= ~EFTU_SPE_CTRL_EN_MASK;
}

LOCAL_INLINE void EFTU_SPE_EnableHallInput(EFTU_SPE_Type *const pSpe)
{
    pSpe->CTRL |= EFTU_SPE_CTRL_SIE_MASK;
}

LOCAL_INLINE void EFTU_SPE_DisableHallInput(EFTU_SPE_Type *const pSpe)
{
    pSpe->CTRL &= ~EFTU_SPE_CTRL_SIE_MASK;
}

LOCAL_INLINE void EFTU_SPE_SetUpdateTrigger(EFTU_SPE_Type *const       pSpe,
                                            EFTU_SPE_UpdateTriggerType eUpdateTrigger)
{
    pSpe->CTRL = ((pSpe->CTRL & ~EFTU_SPE_CTRL_TRG_SEL_MASK) | EFTU_SPE_CTRL_TRG_SEL(eUpdateTrigger));
}

LOCAL_INLINE void EFTU_SPE_SetExUpdateTrigger(EFTU_SPE_Type *const         pSpe,
                                              EFTU_SPE_UpdateExTriggerType eExUpdateTrigger)
{
    pSpe->CTRL = ((pSpe->CTRL & ~EFTU_SPE_CTRL_TRG_ESEL_MASK) |
                  EFTU_SPE_CTRL_TRG_ESEL(eExUpdateTrigger));
}

LOCAL_INLINE void EFTU_SPE_SetPatPtr(EFTU_SPE_Type *const pSpe, EFTU_SPE_OutPatternType ePtr)
{
    pSpe->CTRL = ((pSpe->CTRL & ~EFTU_SPE_CTRL_PAT_PTR_MASK) | EFTU_SPE_CTRL_PAT_PTR(ePtr));
}

LOCAL_INLINE void EFTU_SPE_EnableFastShut(EFTU_SPE_Type *const pSpe)
{
    pSpe->CTRL |= EFTU_SPE_CTRL_FSOM_MASK;
}

LOCAL_INLINE void EFTU_SPE_DisableFastShut(EFTU_SPE_Type *const pSpe)
{
    pSpe->CTRL &= ~EFTU_SPE_CTRL_FSOM_MASK;
}

LOCAL_INLINE void EFTU_SPE_ConfigAip(EFTU_SPE_Type *const pSpe, uint8 u8Aip)
{
    pSpe->CTRL = ((pSpe->CTRL & ~EFTU_SPE_CTRL_AIP_MASK) | EFTU_SPE_CTRL_AIP(u8Aip));
}

LOCAL_INLINE void EFTU_SPE_ConfigPip(EFTU_SPE_Type *const pSpe, uint8 u8Pip)
{
    pSpe->CTRL = ((pSpe->CTRL & ~EFTU_SPE_CTRL_PIP_MASK) | EFTU_SPE_CTRL_PIP(u8Pip));
}

LOCAL_INLINE void EFTU_SPE_ConfigRefSel(EFTU_SPE_Type *const pSpe, EFTU_SPE_RefSelectType eRefSel)
{
    pSpe->CTRL = ((pSpe->CTRL & ~EFTU_SPE_CTRL_PIP_MASK) | EFTU_SPE_CTRL_REF_SEL(eRefSel));
}

LOCAL_INLINE void EFTU_SPE_ConfigShutoffLevel(EFTU_SPE_Type *const pSpe, uint8 u8Shutlevel)
{
    pSpe->CTRL = ((pSpe->CTRL & ~EFTU_SPE_CTRL_FSOL_MASK) | EFTU_SPE_CTRL_FSOL(u8Shutlevel));
}

LOCAL_INLINE uint8 EFTU_SPE_GetNip(EFTU_SPE_Type *const pSpe)
{
    return (uint8)((pSpe->CTRL & EFTU_SPE_CTRL_NIP_MASK) >> EFTU_SPE_CTRL_NIP_SHIFT);
}

LOCAL_INLINE uint32 EFTU_SPE_GetHallPattern(EFTU_SPE_Type *const pSpe)
{
    return pSpe->HALL_IN_PAT;
}

#endif /* (EFTU_INSTANCE_COUNT > 0U) && (EFTU_SPE_SUPPORT == STD_ON) && defined(EFTU_SPE_SUPPORT)*/

#endif /* TEMPLATE_HWA_INCLUDE_HWA_EFTU_SPE_H_ */
