#include "module_driver_eftu_spe.h"

#if (EFTU_INSTANCE_COUNT > 0U) && (EFTU_SPE_SUPPORT == STD_ON) && defined(EFTU_SPE_SUPPORT)

static EFTU_SPE_Type *const s_pEftuSpeBasePtrs[EFTU_SPE_INSTANCE_COUNT] = {
    (EFTU_SPE_Type *)(EFTU0_BASE + EFTU_SPE0_BASE),
    (EFTU_SPE_Type *)(EFTU0_BASE + EFTU_SPE1_BASE),
};

void Eftu_SPE_Init(EFTU_SPE_HandleType *pSpeHandle, EFTU_SPE_InitStruct *pSpeInitStruct)
{

    pSpeHandle->pgHallPatTable  = pSpeInitStruct->pHallPatTable;
    pSpeHandle->pgOutputPartten = pSpeInitStruct->pOutputPartten;
    pSpeHandle->egSpeInstance   = pSpeInitStruct->eSpeInstance;
    EFTU_SPE_Type *pSpe         = s_pEftuSpeBasePtrs[pSpeHandle->egSpeInstance];
    /*Fast Shut off Configuration*/
    if (pSpeInitStruct->tFastShutStruct->bFastShutEn == TRUE)
    {
        EFTU_SPE_SetFastshutSrc(pSpe, pSpeInitStruct->tFastShutStruct->eShutSrc);
        EFTU_SPE_ConfigShutoffLevel(pSpe, pSpeInitStruct->tFastShutStruct->u8Shutofflevel);
        EFTU_SPE_EnableFastShut(pSpe);
    }
    /*Trigger Configuration*/
    EFTU_SPE_SetUpdateTrigger(pSpe, pSpeInitStruct->tTriggerStruct->eUpdateTrigger);
    EFTU_SPE_SetExUpdateTrigger(pSpe, pSpeInitStruct->tTriggerStruct->eUpdateExTrigger);
    if (pSpeInitStruct->tTriggerStruct->bTriggerDelayEn == TRUE)
    {
        EFTU_SPE_SetDelayClkSrc(pSpe, pSpeInitStruct->tTriggerStruct->eDelayClkSrc);
        EFTU_SPE_SetDelaycount(pSpe, pSpeInitStruct->tTriggerStruct->u8Delaytime);
    }

    /*Input pattern  Configuration*/
    uint32 u32InputPattern = 0u;
    for (uint8 u8PatternIndex = 0u; u8PatternIndex < 6u; u8PatternIndex++)
    {

        uint8 u8Patterntemp = 1 << 0U |
                              ((pSpeInitStruct->pHallPatTable + u8PatternIndex)->eHallA_level << 1U |
                               (pSpeInitStruct->pHallPatTable + u8PatternIndex)->eHallB_level << 2U |
                               (pSpeInitStruct->pHallPatTable + u8PatternIndex)->eHallC_level << 3U);
        u32InputPattern |= u8Patterntemp << (4U * u8PatternIndex);
    }
    EFTU_SPE_ConfigPAT(pSpe, u32InputPattern);
    /*output pattern  Configuration*/

    for (uint8 u8PatternIndex = 0u; u8PatternIndex < 6u; u8PatternIndex++)
    {

        uint32 u32Patterntemp =
            ((pSpeInitStruct->pOutputPartten + u8PatternIndex)->ePwmoutpattern0 |
             (pSpeInitStruct->pOutputPartten + u8PatternIndex)->ePwmoutpattern1 << 2U |
             (pSpeInitStruct->pOutputPartten + u8PatternIndex)->ePwmoutpattern2 << 4U |
             (pSpeInitStruct->pOutputPartten + u8PatternIndex)->ePwmoutpattern3 << 6U |
             (pSpeInitStruct->pOutputPartten + u8PatternIndex)->ePwmoutpattern4 << 8U |
             (pSpeInitStruct->pOutputPartten + u8PatternIndex)->ePwmoutpattern5 << 10U);
        EFTU_SPE_ConfigOutPwm(pSpe, u32Patterntemp, u8PatternIndex);
    }

    uint32 u32OutPat6 = ((pSpeInitStruct->tOutputStopPat6)->ePwmoutpattern0 |
                         (pSpeInitStruct->tOutputStopPat6)->ePwmoutpattern1 << 2U |
                         (pSpeInitStruct->tOutputStopPat6)->ePwmoutpattern2 << 4U |
                         (pSpeInitStruct->tOutputStopPat6)->ePwmoutpattern3 << 6U |
                         (pSpeInitStruct->tOutputStopPat6)->ePwmoutpattern4 << 8U |
                         (pSpeInitStruct->tOutputStopPat6)->ePwmoutpattern5 << 10U);
    EFTU_SPE_ConfigOutPwm(pSpe, u32OutPat6, 6U);

    uint32 u32OutPat7 = ((pSpeInitStruct->tOutputStopPat7)->ePwmoutpattern0 |
                         (pSpeInitStruct->tOutputStopPat7)->ePwmoutpattern1 << 2U |
                         (pSpeInitStruct->tOutputStopPat7)->ePwmoutpattern2 << 4U |
                         (pSpeInitStruct->tOutputStopPat7)->ePwmoutpattern3 << 6U |
                         (pSpeInitStruct->tOutputStopPat7)->ePwmoutpattern4 << 8U |
                         (pSpeInitStruct->tOutputStopPat7)->ePwmoutpattern5 << 10U);
    EFTU_SPE_ConfigOutPwm(pSpe, u32OutPat7, 7U);

    /*Irq  Configuration*/
    EFTU_SPE_ConfigNewInputIrq(pSpe, pSpeInitStruct->bIrqOnNewInput);
    EFTU_SPE_ConfigDircIrq(pSpe, pSpeInitStruct->bIrqOnDirChange);
    EFTU_SPE_ConfigEipdIrq(pSpe, pSpeInitStruct->bIrqOnErrInput);
    EFTU_SPE_ConfigBieIrq(pSpe, pSpeInitStruct->bIrqOnBouncing);
    EFTU_SPE_ConfigRcmpIrq(pSpe, pSpeInitStruct->bIrqOnCntCompare);
    pSpeHandle->pSpeIrqCallback = pSpeInitStruct->pSpeIrqCallback;
}

void Eftu_SPE_SetCmd(EFTU_SPE_HandleType *pSpeHandle, EFTU_SPE_ControlCmd eSpeCmd)
{
    EFTU_SPE_Type *pSpe = s_pEftuSpeBasePtrs[pSpeHandle->egSpeInstance];
    EFTU_SPE_SetCmd(pSpe, eSpeCmd);
}

void Eftu_SPE_SoftwareTrigger(EFTU_SPE_HandleType *pSpeHandle)
{
    EFTU_SPE_Type *pSpe = s_pEftuSpeBasePtrs[pSpeHandle->egSpeInstance];
    EFTU_SPE_SoftWareTrigger(pSpe);
}

void Eftu_SPE_Start(EFTU_SPE_HandleType *pSpeHandle, EFTU_SPE_RotationType eRationType)
{
    EFTU_SPE_Type *pSpe = s_pEftuSpeBasePtrs[pSpeHandle->egSpeInstance];
    EFTU_SPE_EnableHallInput(pSpe);
    uint8  u8InputNip       = EFTU_SPE_GetNip(pSpe);
    uint32 u32HallTable     = EFTU_SPE_GetHallPattern(pSpe);
    uint8  u8InputHallIndex = 0U;
    for (u8InputHallIndex = 0U; u8InputHallIndex < 6U; u8InputHallIndex++)
    {
        if (u8InputNip == ((u32HallTable >> (1 + 4 * u8InputHallIndex)) & 0x7U))
        {
            EFTU_SPE_SetPatPtr(
                pSpe,
                (EFTU_SPE_OutPatternType)((pSpeHandle->pgHallPatTable + u8InputHallIndex)->u8SpePtr));
            EFTU_SPE_SetPatPtrBwd(
                pSpe,
                (EFTU_SPE_OutPatternType)((pSpeHandle->pgHallPatTable + u8InputHallIndex)->u8SpePtrBwd));
            break;
        }
    }
    EFTU_SPE_ConfigAip(pSpe, u8InputNip);
    uint8 u8PatHallPipIndex = 0U;
    if (eRationType == EFTU_SPE_FOWARD)
    {
        if (u8InputHallIndex == 0U)
        {
            u8PatHallPipIndex = 5U;
        }
        else
        {
            u8PatHallPipIndex = u8InputHallIndex - 1U;
        }
        uint8 u8PatHallPipValue =
            ((pSpeHandle->pgHallPatTable + u8PatHallPipIndex)->eHallA_level << 0U |
             (pSpeHandle->pgHallPatTable + u8PatHallPipIndex)->eHallB_level << 1U |
             (pSpeHandle->pgHallPatTable + u8PatHallPipIndex)->eHallC_level << 2U);
        EFTU_SPE_ConfigPip(pSpe, u8PatHallPipValue);
        EFTU_SPE_SetCmd(pSpe, EFTU_SPE_OUT_PAT_PTR);
    }
    else
    {
        if (u8InputHallIndex == 5U)
        {
            u8PatHallPipIndex = 0U;
        }
        else
        {
            u8PatHallPipIndex = u8InputHallIndex + 1U;
        }
        uint8 u8PatHallPipValue =
            ((pSpeHandle->pgHallPatTable + u8PatHallPipIndex)->eHallA_level << 0U |
             (pSpeHandle->pgHallPatTable + u8PatHallPipIndex)->eHallB_level << 1U |
             (pSpeHandle->pgHallPatTable + u8PatHallPipIndex)->eHallC_level << 2U);
        EFTU_SPE_ConfigPip(pSpe, u8PatHallPipValue);
        EFTU_SPE_SetCmd(pSpe, EFTU_SPE_OUT_PPAT_PTR_BWD);
    }
    EFTU_SPE_Enable(pSpe);
    EFTU_SPE_SoftWareTrigger(pSpe);
}

void Eftu_SPE_Stop(EFTU_SPE_HandleType *pSpeHandle, EFTU_SPE_StopType eStopOutPattern)
{
    EFTU_SPE_Type *pSpe = s_pEftuSpeBasePtrs[pSpeHandle->egSpeInstance];
    if (eStopOutPattern == EFTU_SPE_STOP_PATTERN_6)
    {
        EFTU_SPE_SetCmd(pSpe, EFTU_SPE_OUT_PAT_6);
        EFTU_SPE_SoftWareTrigger(pSpe);
    }
    else
    {
        EFTU_SPE_SetCmd(pSpe, EFTU_SPE_OUT_PAT_7);
        EFTU_SPE_SoftWareTrigger(pSpe);
    }
}

void Eftu_SPE_DeInit(EFTU_SPE_HandleType *pSpeHandle)
{
    EFTU_SPE_Type *pSpe = s_pEftuSpeBasePtrs[pSpeHandle->egSpeInstance];
    EFTU_SPE_Disable(pSpe);
    EFTU_SPE_DisableHallInput(pSpe);
    EFTU_SPE_ConfigNewInputIrq(pSpe, false);
    EFTU_SPE_ConfigDircIrq(pSpe, false);
    EFTU_SPE_ConfigEipdIrq(pSpe, false);
    EFTU_SPE_ConfigBieIrq(pSpe, false);
    EFTU_SPE_ConfigRcmpIrq(pSpe, false);
    pSpeHandle->pSpeIrqCallback = NULL_PTR;

    EFTU_SPE_DisableFastShut(pSpe);
    EFTU_SPE_SetFastshutSrc(pSpe, DTM_AUX_IN0);
    EFTU_SPE_ConfigShutoffLevel(pSpe, 0U);

    EFTU_SPE_SetUpdateTrigger(pSpe, EFTU_SPE_UPDATETRIGGER_NIPD);
    EFTU_SPE_SetExUpdateTrigger(pSpe, EFTU_SPE_EXUPDATETRIGGER_CH6_CM0);
    EFTU_SPE_SetDelayClkSrc(pSpe, CCM_CLK_RES_0);
    EFTU_SPE_SetDelaycount(pSpe, 0);

    EFTU_SPE_ConfigPAT(pSpe, 0U);

    for (uint8 u8PatternIndex = 0u; u8PatternIndex < 6u; u8PatternIndex++)
    {
        EFTU_SPE_ConfigOutPwm(pSpe, 0U, u8PatternIndex);
    }

    EFTU_SPE_SetCmd(pSpe, EFTU_SPE_OUT_PAT_PTR);
    EFTU_SPE_SetPatPtr(pSpe, (EFTU_SPE_OutPatternType)0U);
    EFTU_SPE_SetPatPtrBwd(pSpe, (EFTU_SPE_OutPatternType)0U);
    EFTU_SPE_ConfigAip(pSpe, 0u);
    EFTU_SPE_ConfigPip(pSpe, 0u);
}

void EFTU_SPE_IrqHandler(EFTU_SPE_HandleType *pSpeHandle)
{
    EFTU_SPE_Type *pSpe      = s_pEftuSpeBasePtrs[pSpeHandle->egSpeInstance];
    uint8          u8IntMask = EFTU_SPE_GetIrqFlag(pSpe);
    u8IntMask &= EFTU_SPE_GetIrqnbleBit(pSpe);
    bool bIntFlag = FALSE;

    if ((u8IntMask & EFTU_SPE_IRQ_ST_NIPD_ST_MASK) != 0U)
    {
        pSpeHandle->bNewInputIrqStatus = TRUE;
        bIntFlag                       = TRUE;
        EFTU_SPE_ClearIrqMask(pSpe, EFTU_SPE_IRQ_ST_NIPD_ST_MASK);
    }

    if ((u8IntMask & EFTU_SPE_IRQ_ST_DCHG_ST_MASK) != 0U)
    {
        pSpeHandle->bDirChangeIrqStatus = TRUE;
        bIntFlag                        = TRUE;
        EFTU_SPE_ClearIrqMask(pSpe, EFTU_SPE_IRQ_ST_DCHG_ST_MASK);
    }
    if ((u8IntMask & EFTU_SPE_IRQ_ST_EIPD_ST_MASK) != 0U)
    {
        pSpeHandle->bErrInputIrqStatus = TRUE;
        bIntFlag                       = TRUE;
        EFTU_SPE_ClearIrqMask(pSpe, EFTU_SPE_IRQ_ST_EIPD_ST_MASK);
    }

    if ((u8IntMask & EFTU_SPE_IRQ_ST_BIE_ST_MASK) != 0U)
    {
        pSpeHandle->bBouncingInputIrqStatus = TRUE;
        bIntFlag                            = TRUE;
        EFTU_SPE_ClearIrqMask(pSpe, EFTU_SPE_IRQ_ST_BIE_ST_MASK);
    }

    if ((u8IntMask & EFTU_SPE_IRQ_ST_RCMP_ST_MASK) != 0U)
    {
        pSpeHandle->bCntCompareIrqStatus = TRUE;
        bIntFlag                         = TRUE;
        EFTU_SPE_ClearIrqMask(pSpe, EFTU_SPE_IRQ_ST_RCMP_ST_MASK);
    }

    if (bIntFlag == TRUE)
    {
        pSpeHandle->pSpeIrqCallback(pSpeHandle);
    }
}

#endif
