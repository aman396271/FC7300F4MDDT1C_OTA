/**
 * @file module_driver_ptimer.c
 * @author flagchip
 * @brief PTIMER driver source code
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
   *   0.1.0       2022-04-20    Flagchip030   N/A          First version for FC7300
   ******************************************************************************** */
#include "module_driver_ptimer.h"

#if PTIMER_INSTANCE_COUNT > 0U

#if SCM_PTIMER_CHANNEL_SELECTION_SUPPORT
#include "HwA_scm.h"
#endif

#ifndef PTIMER_DEV_ERROR_REPORT
#define PTIMER_DEV_ERROR_REPORT    STD_OFF
#endif
#if PTIMER_DEV_ERROR_REPORT == STD_ON
#define PTIMER_ReportDevError(func, error) ReportDevError(PTIMER_MODULE_ID, func, error)
#endif

static PTIMER_Type *const s_apPtimerBase[PTIMER_INSTANCE_COUNT] = PTIMER_BASE_PTRS;

/**
 * @brief Initialize the Ptimer interrupt
 *
 * @note the interrupt delay value is buffered and will take effect only after called PTIMER_LoadValue()
 * function.
 *
 * @param PTIMER_HandleType the Ptimer handler pointer
 */
static void PTIMER_InitInterrupt(PTIMER_HandleType *PtimerHandle);

static void PTIMER_InitInterrupt(PTIMER_HandleType *PtimerHandle)
{
    PTIMER_Type *const pPtimer = s_apPtimerBase[PtimerHandle->eInstance];

    PTIMER_HWA_SetSeqErrIntEnableFlag(pPtimer, PtimerHandle->tSettings.bSeqErrIntEnable);
    PTIMER_HWA_SetInterruptDelay(pPtimer, PtimerHandle->tSettings.u16IntDelayPeriod);
    PTIMER_HWA_SetInterruptEnableFlag(pPtimer, PtimerHandle->tSettings.bDelayIntEnable);
}

void PTIMERn_IRQHandler(PTIMER_HandleType *PtimerHandle)
{
    PTIMER_Type *const pPtimer = s_apPtimerBase[PtimerHandle->eInstance];
    uint8_t u8Channel;
    if (PTIMER_HWA_GetInterruptFlag(pPtimer) == true)
    {
        PTIMER_HWA_ClearInterruptFlag(pPtimer);
        if ((PtimerHandle->tSettings).pIntNotify != NULL)
        {
            (PtimerHandle->tSettings).pIntNotify(PtimerHandle);
        }
    }

    for (u8Channel = 0U; (PtimerHandle->tSettings).u8ChnNum; u8Channel++)
    {
        if (PTIMER_HWA_GetChannelSequenceErrorFlag(pPtimer, u8Channel) == true)
        {
            PTIMER_HWA_ClearChannelSequenceErrorFlag(pPtimer, u8Channel);
            if ((PtimerHandle->tSettings).pSeqErrorNotify != NULL)
            {
                (PtimerHandle->tSettings).pSeqErrorNotify(PtimerHandle, u8Channel);
            }
        }
    }
}

void PTIMER_DeInit(PTIMER_HandleType *PtimerHandle)
{
#if PTIMER_DEV_ERROR_REPORT == STD_ON
    if (PtimerHandle == NULL)
    {
        PTIMER_ReportDevError(PTIMER_DEINIT_ID, PTIMER_E_PARAM_POINTER);
    }
    else if ((PtimerHandle->eInstance) >= PTIMER_INSTANCE_COUNT)
    {
        PTIMER_ReportDevError(PTIMER_DEINIT_ID, PTIMER_E_PARAM_INSTANCE);
    }
    else
    {
#endif

        PTIMER_Type *const pPtimer = s_apPtimerBase[PtimerHandle->eInstance];
        uint8_t u8Chn;

        /* Reset PTIMER Status Ctrl Register */
        PTIMER_HWA_SetStatusCtrl(pPtimer, 0U);
        /* Enable PTIMER */
        PTIMER_HWA_Enable(pPtimer);
        /* Reset PTIMER Max Cnt Register */
        PTIMER_HWA_SetMaxCount(pPtimer, 0xFFFFU);
        /* Reset PTIMER Int Dly Register */
        PTIMER_HWA_SetInterruptDelay(pPtimer, 0xFFFFU);

        for (u8Chn = 0U; u8Chn < PTIMER_DLY_CNT; u8Chn++)
        {
            PTIMER_HWA_SetChannelControl(pPtimer, u8Chn, false, false, false);
            PTIMER_HWA_ClearChannelCounterFlag(pPtimer, u8Chn);
            PTIMER_HWA_ClearChannelSequenceErrorFlag(pPtimer, u8Chn);
            PTIMER_HWA_SetChannelDelay(pPtimer, u8Chn, 0U);
        }

        /* For Pulse out trigger. */
        PTIMER_HWA_DisablePulseOut(pPtimer);
        PTIMER_HWA_SetPulseOutDelay(pPtimer, 0U, 0U);

        PTIMER_HWA_LoadValue(pPtimer);
        PTIMER_HWA_Disable(pPtimer);
        (PtimerHandle->tSettings).pSeqErrorNotify = NULL;
        (PtimerHandle->tSettings).pIntNotify      = NULL;
#if PTIMER_DEV_ERROR_REPORT == STD_ON
    }
#endif
}

void PTIMER_InitStructure(PTIMER_InitType *const pInitCfg)
{
#if PTIMER_DEV_ERROR_REPORT == STD_ON
    if (pInitCfg == NULL)
    {
        PTIMER_ReportDevError(PTIMER_INIT_STRUCTURE_ID, PTIMER_E_PARAM_POINTER);
    }
    else
    {
#endif
#if PTIMER_SUPPORT_DEBUG_MODE
        pInitCfg->bDebugDisable             = false;
#endif
        pInitCfg->bContinuousModeEnable     = false;
        pInitCfg->bDmaEnable                = false;
        pInitCfg->bInstanceBackToBackEnable = false;
        pInitCfg->eClkPreDiv                = PTIMER_PRE_DIVIDE_BY_1;
        pInitCfg->eClkPreMultFactor         = PTIMER_PRE_DIVIDER_MULTIPLY_BY_1;
        pInitCfg->eLoadValueMode            = PTIMER_LOAD_VAL_IMMEDIATELY;
        pInitCfg->eTriggerInput             = PTIMER_TRGSRC_SW;
        pInitCfg->bDelayIntEnable           = false;
        pInitCfg->bSeqErrIntEnable          = false;
        pInitCfg->u16IntDelayPeriod         = 58593U;
        pInitCfg->pSeqErrorNotify           = NULL;
        pInitCfg->pIntNotify                = NULL;
#if PTIMER_DEV_ERROR_REPORT == STD_ON
    }
#endif
}

void PTIMER_Init(PTIMER_HandleType *PtimerHandle, const PTIMER_InitType *const pInitCfg)
{
#if PTIMER_DEV_ERROR_REPORT == STD_ON
    if (PtimerHandle == NULL || pInitCfg == NULL)
    {
        PTIMER_ReportDevError(PTIMER_INIT_ID, PTIMER_E_PARAM_POINTER);
    }
    else if ((PtimerHandle->eInstance) >= PTIMER_INSTANCE_COUNT)
    {
        PTIMER_ReportDevError(PTIMER_INIT_ID, PTIMER_E_PARAM_INSTANCE);
    }
    else
    {
#endif

        PTIMER_Type *const pPtimer = s_apPtimerBase[PtimerHandle->eInstance];

        PTIMER_DeInit(PtimerHandle);
#if PTIMER_SUPPORT_DEBUG_MODE
        PTIMER_HWA_DisableDebugMode(pPtimer,pInitCfg->bDebugDisable);
#endif
        PTIMER_HWA_SetLoadMode(pPtimer, pInitCfg->eLoadValueMode);
        PTIMER_HWA_SetDivPrescaler(pPtimer, pInitCfg->eClkPreDiv);
        PTIMER_HWA_SetTriggerSource(pPtimer, pInitCfg->eTriggerInput);
        PTIMER_HWA_SetDivMultiply(pPtimer, pInitCfg->eClkPreMultFactor);
        PTIMER_HWA_SetContinuoiusModeFlag(pPtimer, pInitCfg->bContinuousModeEnable);
        PTIMER_HWA_SetDMAEnableFlag(pPtimer, pInitCfg->bDmaEnable);

        (PtimerHandle->tSettings).pIntNotify        = pInitCfg->pIntNotify;
        (PtimerHandle->tSettings).pSeqErrorNotify   = pInitCfg->pSeqErrorNotify;
        (PtimerHandle->tSettings).bDelayIntEnable   = pInitCfg->bDelayIntEnable;
        (PtimerHandle->tSettings).bSeqErrIntEnable  = pInitCfg->bSeqErrIntEnable;
        (PtimerHandle->tSettings).u16IntDelayPeriod = pInitCfg->u16IntDelayPeriod;
        (PtimerHandle->tSettings).u8ChnNum          = 0U;
        PTIMER_InitInterrupt(PtimerHandle);
#if PTIMER_DEV_ERROR_REPORT == STD_ON
    }
#endif
}

void PTIMER_InitChannel(PTIMER_HandleType *PtimerHandle,
                        const PTIMER_ChannelCfgType aChannelCfg[], const uint8_t u8ChnNum)
{
#if PTIMER_DEV_ERROR_REPORT == STD_ON
    if ((aChannelCfg == NULL) || (PtimerHandle == NULL))
    {
        PTIMER_ReportDevError(PTIMER_INIT_CHANNEL_ID, PTIMER_E_PARAM_POINTER);
    }
    else if ((PtimerHandle->eInstance) >= PTIMER_INSTANCE_COUNT)
    {
        PTIMER_ReportDevError(PTIMER_INIT_CHANNEL_ID, PTIMER_E_PARAM_INSTANCE);
    }
    else if (u8ChnNum > PTIMER_DLY_CNT)
    {
        PTIMER_ReportDevError(PTIMER_INIT_CHANNEL_ID, PTIMER_E_PARAM_CHANNEL);
    }
    else
    {
#endif
        PTIMER_Type *const pPtimer = s_apPtimerBase[PtimerHandle->eInstance];

        uint8_t u8ChnIdx;

        for (u8ChnIdx = 0U; u8ChnIdx < u8ChnNum; u8ChnIdx++)
        {
            PTIMER_HWA_SetChannelControl(pPtimer, u8ChnIdx, aChannelCfg[u8ChnIdx].bPreTriggerEnable,
                                         aChannelCfg[u8ChnIdx].bPreTriggerOutputEnable, aChannelCfg[u8ChnIdx].bPreTriggerBackToBackEnable);
            PTIMER_HWA_SetChannelDelay(pPtimer, u8ChnIdx, aChannelCfg[u8ChnIdx].u16DelayCnt);
        }
        (PtimerHandle->tSettings).u8ChnNum = u8ChnNum;
#if PTIMER_DEV_ERROR_REPORT == STD_ON
    }
#endif
}

void PTIMER_SetPeriod(const PTIMER_HandleType *PtimerHandle, uint16_t u16PtimerPeriod)
{
#if PTIMER_DEV_ERROR_REPORT == STD_ON
    if (PtimerHandle == NULL)
    {
        PTIMER_ReportDevError(PTIMER_SET_PERIOD_ID, PTIMER_E_PARAM_POINTER);
    }
    else if ((PtimerHandle->eInstance) >= PTIMER_INSTANCE_COUNT)
    {
        PTIMER_ReportDevError(PTIMER_SET_PERIOD_ID, PTIMER_E_PARAM_INSTANCE);
    }
    else
    {
#endif

        PTIMER_Type *const pPtimer = s_apPtimerBase[PtimerHandle->eInstance];

        PTIMER_HWA_SetMaxCount(pPtimer, u16PtimerPeriod);
#if PTIMER_DEV_ERROR_REPORT == STD_ON
    }
#endif
}

void PTIMER_SetPulseOut(const PTIMER_HandleType *PtimerHandle, const PTIMER_PulseOutType *pPulseOutCfg)
{
#if PTIMER_DEV_ERROR_REPORT == STD_ON
    if ((pPulseOutCfg == NULL) || (PtimerHandle == NULL))
    {
        PTIMER_ReportDevError(PTIMER_SET_PULSE_OUT_ID, PTIMER_E_PARAM_POINTER);
    }
    else if ((PtimerHandle->eInstance) >= PTIMER_INSTANCE_COUNT)
    {
        PTIMER_ReportDevError(PTIMER_SET_PULSE_OUT_ID, PTIMER_E_PARAM_INSTANCE);
    }
    else
    {
#endif
        PTIMER_Type *const pPtimer = s_apPtimerBase[PtimerHandle->eInstance];

        PTIMER_HWA_SetPulseOutDelay(pPtimer, pPulseOutCfg->u32PulseOutDlyHighCnt, pPulseOutCfg->u32PulseOutDlyLowCnt);
#if PTIMER_DEV_ERROR_REPORT == STD_ON
    }
#endif
}

void PTIMER_LoadValue(const PTIMER_HandleType *PtimerHandle)
{
#if PTIMER_DEV_ERROR_REPORT == STD_ON
    if (PtimerHandle == NULL)
    {
        PTIMER_ReportDevError(PTIMER_LOAD_VALUE_ID, PTIMER_E_PARAM_POINTER);
    }
    else if ((PtimerHandle->eInstance) >= PTIMER_INSTANCE_COUNT)
    {
        PTIMER_ReportDevError(PTIMER_LOAD_VALUE_ID, PTIMER_E_PARAM_INSTANCE);
    }
    else
    {
#endif
        PTIMER_Type *const pPtimer = s_apPtimerBase[PtimerHandle->eInstance];
        PTIMER_HWA_LoadValue(pPtimer);
#if PTIMER_DEV_ERROR_REPORT == STD_ON
    }
#endif
}

void PTIMER_Enable(const PTIMER_HandleType *PtimerHandle)
{
#if PTIMER_DEV_ERROR_REPORT == STD_ON
    if (PtimerHandle == NULL)
    {
        PTIMER_ReportDevError(PTIMER_ENABLE_ID, PTIMER_E_PARAM_POINTER);
    }
    else if ((PtimerHandle->eInstance) >= PTIMER_INSTANCE_COUNT)
    {
        PTIMER_ReportDevError(PTIMER_ENABLE_ID, PTIMER_E_PARAM_INSTANCE);
    }
    else
    {
#endif
        PTIMER_Type *const pPtimer = s_apPtimerBase[PtimerHandle->eInstance];
        PTIMER_HWA_Enable(pPtimer);
#if PTIMER_DEV_ERROR_REPORT == STD_ON
    }
#endif
}

void PTIMER_Disable(const PTIMER_HandleType *PtimerHandle)
{
#if PTIMER_DEV_ERROR_REPORT == STD_ON
    if (PtimerHandle == NULL)
    {
        PTIMER_ReportDevError(PTIMER_DISABLE_ID, PTIMER_E_PARAM_POINTER);
    }
    else if ((PtimerHandle->eInstance) >= PTIMER_INSTANCE_COUNT)
    {
        PTIMER_ReportDevError(PTIMER_DISABLE_ID, PTIMER_E_PARAM_INSTANCE);
    }
    else
    {
#endif
        PTIMER_Type *const pPtimer = s_apPtimerBase[PtimerHandle->eInstance];
        PTIMER_HWA_Disable(pPtimer);
#if PTIMER_DEV_ERROR_REPORT == STD_ON
    }
#endif
}

void PTIMER_EnablePulseOut(const PTIMER_HandleType *PtimerHandle)
{
#if PTIMER_DEV_ERROR_REPORT == STD_ON
    if (PtimerHandle == NULL)
    {
        PTIMER_ReportDevError(PTIMER_PULSE_OUT_ID, PTIMER_E_PARAM_POINTER);
    }
    else if ((PtimerHandle->eInstance) >= PTIMER_INSTANCE_COUNT)
    {
        PTIMER_ReportDevError(PTIMER_PULSE_OUT_ID, PTIMER_E_PARAM_INSTANCE);
    }
    else
    {
#endif
        PTIMER_Type *const pPtimer = s_apPtimerBase[PtimerHandle->eInstance];
        PTIMER_HWA_EnablePulseOut(pPtimer);
#if PTIMER_DEV_ERROR_REPORT == STD_ON
    }
#endif
}

void PTIMER_DisablePulseOut(const PTIMER_HandleType *PtimerHandle)
{
#if PTIMER_DEV_ERROR_REPORT == STD_ON
    if (PtimerHandle == NULL)
    {
        PTIMER_ReportDevError(PTIMER_DISABLE_PULSE_OUT_ID, PTIMER_E_PARAM_POINTER);
    }
    else if ((PtimerHandle->eInstance) >= PTIMER_INSTANCE_COUNT)
    {
        PTIMER_ReportDevError(PTIMER_DISABLE_PULSE_OUT_ID, PTIMER_E_PARAM_INSTANCE);
    }
    else
    {
#endif

        PTIMER_Type *const pPtimer = s_apPtimerBase[PtimerHandle->eInstance];
        PTIMER_HWA_DisablePulseOut(pPtimer);
#if PTIMER_DEV_ERROR_REPORT == STD_ON
    }
#endif
}

void PTIMER_GenerateSWTrigger(const PTIMER_HandleType *PtimerHandle)
{
#if PTIMER_DEV_ERROR_REPORT == STD_ON
    if (PtimerHandle == NULL)
    {
        PTIMER_ReportDevError(PTIMER_GENERATE_SW_TRIGGER_ID, PTIMER_E_PARAM_POINTER);
    }
    else if ((PtimerHandle->eInstance) >= PTIMER_INSTANCE_COUNT)
    {
        PTIMER_ReportDevError(PTIMER_GENERATE_SW_TRIGGER_ID, PTIMER_E_PARAM_INSTANCE);
    }
    else
    {
#endif
        PTIMER_Type *const pPtimer = s_apPtimerBase[PtimerHandle->eInstance];
        PTIMER_HWA_GenerateSwTrigger(pPtimer);
#if PTIMER_DEV_ERROR_REPORT == STD_ON
    }
#endif
}

#if SCM_PTIMER_CHANNEL_SELECTION_SUPPORT
void PTIMER_ChannelSelection(PTIMER_ChannelSelectionType selection)
{
    uint32 regValue;
    regValue = SCM_HWA_Get_ADC_ROUTING2();
    if(PTIMER0_USED_FOR_ADC0 == selection)
        regValue &= ~SCM_ADC_ROUTING2_PTIMER0CH1_SEL(1u);
    if(PTIMER0_USED_FOR_ADC4 == selection)
        regValue |= SCM_ADC_ROUTING2_PTIMER0CH1_SEL(1u);
    if(PTIMER3_USED_FOR_ADC3 == selection)
        regValue &= SCM_ADC_ROUTING2_PTIMER3CH1_SEL(1u);
    if(PTIMER3_USED_FOR_ADC5 == selection)
        regValue |= SCM_ADC_ROUTING2_PTIMER3CH1_SEL(1u);
    SCM_HWA_Set_ADC_ROUTING2(regValue);
}
#endif

#endif /* #if PTIMER_INSTANCE_COUNT > 0U */
