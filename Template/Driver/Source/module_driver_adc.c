/**
 * @file module_driver_adc.c
 * @author flagchip
 * @brief ADC driver source code
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
   *   0.1.0       2022-12-01    Flagchip030   N/A          First version for FC7300
   ******************************************************************************** */

#include "module_driver_adc.h"

#if ADC_INSTANCE_COUNT > 0U

#include "module_driver_scg.h"
#include "module_driver_pcc.h"

#ifndef ADC_DEV_ERROR_REPORT
    #define ADC_DEV_ERROR_REPORT    STD_OFF
#endif
#if ADC_DEV_ERROR_REPORT == STD_ON
    #define ADC_ReportDevError(func, error) ReportDevError(ADC_MODULE_ID, func, error)
#endif

/**
 * @name  ADC default values
 * @brief ADC default configuration parameters
 *
 * @{
 */
#define ADC_DEFAULT_SAMPLE_TIME_OPTION_0                  (0x04U)
#define ADC_DEFAULT_SAMPLE_TIME_OPTION_1                  (0x0AU)
#define ADC_DEFAULT_SAMPLE_TIME_OPTION_2                  (0x22U)
#define ADC_DEFAULT_SAMPLE_TIME_OPTION_3                  (0x82U)
#define ADC_DEFAULT_WATER_MARK                            (0x10U)
#define ADC_DEFAULT_CMP_HIGH_THRESHOLD                    (0x000U)
#define ADC_DEFAULT_CMP_LOW_THRESHOLD                     (0x200U)
/** @}*/

/********* Local Variables ************/

static ADC_Type *const s_apAdcBase[ADC_INSTANCE_COUNT] = ADC_BASE_PTRS;

/******* Local Function Prototype *********/

/********* Local Functions ************/

/***************ADC IRQ Functions*****************/
void ADCn_IRQHandler(ADC_HandleType *pAdcHandle)
{
    ADC_Type *const pAdc = s_apAdcBase[pAdcHandle->eInstance];
    uint8_t u8Index = 0;
    uint32_t u32UnusedFlags = 0;
    uint32_t u32RegVal = 0;
    bool bConvCompleted = false;

    #if ADC_SUPPORT_SG_MODE
    uint8_t u8SGIndex;
    uint8_t u8SGStart;
    uint8_t u8SGEnd;
    uint8_t u8BufferIndex;
    if (pAdcHandle->tSettings.eSeqMode == ADC_SEQMODE_GROUP)
    {
        for (u8SGIndex = 0U; u8SGIndex < ADC_GET_SUPPORTED_SEQUENCE_GROUP_CNT(pAdcHandle->eInstance); u8SGIndex++)
        {
            if (ADC_HWA_GetEndOfSGFlag(pAdc, u8SGIndex) && ADC_HWA_GetEndOfSGIntEnable(pAdc, u8SGIndex))
            {
                ADC_HWA_ClearEndOfSGFlag(pAdc, u8SGIndex);
                u8SGStart = ADC_HWA_GetSGStartPoint(pAdc, u8SGIndex);
                u8SGEnd = ADC_HWA_GetSGEndPoint(pAdc, u8SGIndex);
                u8BufferIndex = 0;
                for (u8Index = u8SGStart; u8Index < u8SGEnd + 1U; u8Index++)
                {
                    (pAdcHandle->tSettings).pSGResultBuffer[u8SGIndex][u8BufferIndex++] = ADC_HWA_GetChannelData(pAdc, u8Index);
                }
                if ((pAdcHandle->tSettings).SGConvCompleteNotify[u8SGIndex] != NULL)
                {
                    (pAdcHandle->tSettings).SGConvCompleteNotify[u8SGIndex](pAdcHandle);
                }
            }
        }
    } else
    #endif
    if (pAdcHandle->tSettings.eSeqMode == ADC_SEQMODE_DISCONTINUOUS_1)
    {
        bConvCompleted = false;
        for (u8Index = 0U; u8Index < (pAdcHandle->tSettings).u8ChannelCnt; u8Index++)
        {
            if (ADC_HWA_GetChannelCoCoFlag(pAdc, u8Index) == false)
            {
                break;
            }
            else if (ADC_HWA_GetChannelCoCoIntEnable(pAdc, u8Index) == true)
            {
                bConvCompleted = true;
            }
            else
            {}
        }
        if (bConvCompleted)
        {
            for (u8Index = 0U; u8Index < (pAdcHandle->tSettings).u8ChannelCnt; u8Index++)
            {
                ((pAdcHandle->tSettings).pResultBuffer)[u8Index] = ADC_HWA_GetChannelData(pAdc, u8Index);
            }
            if ((pAdcHandle->tSettings).pConvCompleteNotify != NULL)
            {
                (pAdcHandle->tSettings).pConvCompleteNotify(pAdcHandle);
            }
        }
    }
    else
    {
        if (ADC_HWA_GetFIFOReadyFlag(pAdc) && ADC_HWA_GetFIFOReadyIntEnable(pAdc))
        {
            for (u8Index = 0U; u8Index < (pAdcHandle->tSettings).u8ChannelCnt; u8Index++)
            {
                ((pAdcHandle->tSettings).pResultBuffer)[u8Index] = ADC_HWA_GetFIFOData(pAdc);
            }
            if ((pAdcHandle->tSettings).pConvCompleteNotify != NULL)
            {
                (pAdcHandle->tSettings).pConvCompleteNotify(pAdcHandle);
            }
        }
    }

    #if ADC_SUPPORT_ENHANCED_CMP_BLOCK
    if (ADC_IS_SUPPORT_ENHANCED_CMP_BLOCK(pAdcHandle->eInstance))  // Not all adc hardware support enhanced cmp interrupt, so this check is needed
    {
        for (u8Index = 0; u8Index < ADC_ENHANCED_CMP_BLOCK_CNT; u8Index++)
        {
            if (ADC_HWA_GetECMPHighFlag(pAdc, (ADC_ECMPIndex)u8Index) && ADC_HWA_GetECMPHighIntEnable(pAdc, (ADC_ECMPIndex)u8Index))
            {
                ADC_HWA_ClearECMPHighFlag(pAdc, (ADC_ECMPIndex)u8Index);
                if ((pAdcHandle->tSettings).pECmpHighNotify[u8Index] != NULL)
                {
                    (pAdcHandle->tSettings).pECmpHighNotify[u8Index](pAdcHandle);
                }
            }
            if (ADC_HWA_GetECMPLowFlag(pAdc, (ADC_ECMPIndex)u8Index) && ADC_HWA_GetECMPLowIntEnable(pAdc, (ADC_ECMPIndex)u8Index))
            {
                ADC_HWA_ClearECMPLowFlag(pAdc, (ADC_ECMPIndex)u8Index);
                if ((pAdcHandle->tSettings).pECmpLowNotify[u8Index] != NULL)
                {
                    (pAdcHandle->tSettings).pECmpLowNotify[u8Index](pAdcHandle);
                }
            }
            if (ADC_HWA_GetECMPWinFlag(pAdc, (ADC_ECMPIndex)u8Index) && ADC_HWA_GetECMPWinIntEnable(pAdc, (ADC_ECMPIndex)u8Index))
            {
                ADC_HWA_ClearECMPWinFlag(pAdc, (ADC_ECMPIndex)u8Index);
                if ((pAdcHandle->tSettings).pECmpWinNotify[u8Index] != NULL)
                {
                    (pAdcHandle->tSettings).pECmpWinNotify[u8Index](pAdcHandle);
                }
            }
        }
    }
    #endif

    #if ADC_SUPPORT_SG_CMP_BLOCK
    if (ADC_IS_SUPPORT_SG_CMP_BLOCK(pAdcHandle->eInstance))  // Not all adc hardware support sg cmp interrupt, so this check is needed
    {
        u8Index = pAdcHandle->eInstance - ADC_SUPPORT_SG_CMP_INSTANCE_START;
        if (SMC_HWA_ADCRES_GetSGCMP_FLAG(u8Index))
        {
            u32RegVal = SMC_HWA_GetADCCFG0(u8Index);
            u32RegVal |= SMC_ADC_CFG0_SGCMP_FLAG_CLR_MASK;
            SMC_HWA_SetADCCFG0(u8Index, u32RegVal);
            if ((pAdcHandle->tSettings).pSGCmpNotify != NULL)
            {
                (pAdcHandle->tSettings).pSGCmpNotify(pAdcHandle);
            }
        }
    }
    #endif

    #if ADC_SUPPORT_FAST_CMP_BLOCK
    if (ADC_IS_SUPPORT_FAST_CMP_BLOCK(pAdcHandle->eInstance))  // Not all adc hardware support fast cmp interrupt, so this check is needed
    {
        if (ADC_HWA_GetFCRFFlag(pAdc) && ADC_HWA_GetFCRFIntEnable(pAdc))
        {
            ADC_HWA_ClearFCRFFlag(pAdc);
            if ((pAdcHandle->tSettings).pFCmpFallingNotify != NULL)
            {
                (pAdcHandle->tSettings).pFCmpFallingNotify(pAdcHandle);
            }
        }
        if (ADC_HWA_GetFCRRFlag(pAdc) && ADC_HWA_GetFCRRIntEnable(pAdc))
        {
            ADC_HWA_ClearFCRRFlag(pAdc);
            if ((pAdcHandle->tSettings).pFCmpRisingNotify != NULL)
            {
                (pAdcHandle->tSettings).pFCmpRisingNotify(pAdcHandle);
            }
        }
    }
    #endif

    if (ADC_HWA_GetOverrunFlag(pAdc) && ADC_HWA_GetOverrunIntEnable(pAdc))
    {
        ADC_HWA_ClearOverrunFlag(pAdc);
        if ((pAdcHandle->tSettings).pOverrunNotify != NULL)
        {
            (pAdcHandle->tSettings).pOverrunNotify(pAdcHandle);
        }
    }

    if (ADC_HWA_GetCmpFlag(pAdc) && ADC_HWA_GetCmpIntEnable(pAdc))
    {
        ADC_HWA_ClearCmpFlag(pAdc);
        if ((pAdcHandle->tSettings).pCmpNotify != NULL)
        {
            (pAdcHandle->tSettings).pCmpNotify(pAdcHandle);
        }
    }

    /* Clear unused flags */
    u32UnusedFlags = ADC_INT_STATUS_ADRDY(1U) | ADC_INT_STATUS_EOSMP(1U) | \
                     ADC_INT_STATUS_EOC(1U);
    ADC_HWA_ClearFlags(pAdc, u32UnusedFlags);

    (void)u32RegVal;
}

/***************** Global Functions *********************/
void ADC_InitStructure(ADC_InitType *const pInitCfg)
{
    #if ADC_DEV_ERROR_REPORT == STD_ON
    if (pInitCfg == NULL)
    {
        ADC_ReportDevError(ADC_INIT_STRUCTURE_ID, ADC_E_PARAM_POINTER);
    }
    else
    {
    #endif

        pInitCfg->eResolution      = ADC_RESOLUTION_12_BIT;            /* 12 bit Resolution */
        pInitCfg->eAlign           = ADC_ALIGN_RIGHT;                  /* Align right */
        pInitCfg->eTrgMode         = ADC_TRGMODE_SW;                   /* Software trigger */
        #if ADC_SUPPORT_PERIOD_TRIGGER
        pInitCfg->u16PeriodTrgInterval = 0U;                           /* Periodic trigger interval set to 0 */
        #endif
        pInitCfg->bWaitEn          = false;                            /* Enable wait conversion mode */
        #if ADC_SUPPORT_SG_MODE
        pInitCfg->eTrgLatchUnitPri = ADC_TRG_LATCH_UNIT_PRI_ROUND_ROBIN;    /* Round Robin priority */
        #endif
        #if ADC_SUPPORT_GAIN_AND_OFFSET_CALIBRATION
        pInitCfg->bCalibrationEn       = false;
        pInitCfg->s32CalibrationOffset = 0U;
        pInitCfg->s32CalibrationGain   = 0U;
        #endif
        #if ADC_SUPPORT_INSTANCE_DIFFMODE_SET
        pInitCfg->bDifferentialModeEn  = false;
        #endif
        pInitCfg->eClockDivider     = ADC_CLOCK_DIV_1;
        pInitCfg->eSeqMode          = ADC_SEQMODE_SINGLE;                /* Single sequence mode */
        pInitCfg->bAutoDis          = false;                             /* Disable auto disable mode */
        pInitCfg->eOverrunMode      = ADC_OVERRUN_MODE_PRESERVE;         /* Old conversion data preserved when overrun occured */
        #if ADC_SUPPORT_INTERNAL_REFERENCE
        pInitCfg->eVoltageRef       = ADC_REF_INTERNAL;                  /* Use internal reference */
        #endif
        pInitCfg->bAverageEn        = false;                             /* Disable averaging functionality */
        pInitCfg->eAverageLen       = ADC_AVERAGE_LEN_4;                 /* Average by 4 samples if average is enabled */
        pInitCfg->aSampleTimes[0]   = ADC_DEFAULT_SAMPLE_TIME_OPTION_0;  /* Sample time option 0 is 4 ADC Clock */
        pInitCfg->aSampleTimes[1]   = ADC_DEFAULT_SAMPLE_TIME_OPTION_1;  /* Sample time option 1 is 10 ADC Clock */
        pInitCfg->aSampleTimes[2]   = ADC_DEFAULT_SAMPLE_TIME_OPTION_2;  /* Sample time option 2 is 34 ADC Clock */
        pInitCfg->aSampleTimes[3]   = ADC_DEFAULT_SAMPLE_TIME_OPTION_3;  /* Sample time option 3 is 130 ADC Clock */
        pInitCfg->bDmaEn            = false;                             /* Disable DMA for the ADC */
        #if ADC_SUPPORT_GROUP_INJECTION
        pInitCfg->bGroupInjectionEn = false;                             /* Disable group injection mode */
        #endif

        pInitCfg->bConvCompleteIntEn  = false;
        pInitCfg->bOverrunIntEn       = false;

        pInitCfg->pConvCompleteNotify = NULL;
        pInitCfg->pOverrunNotify      = NULL;

        pInitCfg->pResultBuffer       = NULL;

    #if ADC_DEV_ERROR_REPORT == STD_ON
    }
    #endif
}

void ADC_Init(ADC_HandleType *pAdcHandle, const ADC_InitType *const pInitCfg)
{
    #if ADC_DEV_ERROR_REPORT == STD_ON
    if ((pAdcHandle == NULL) || (pInitCfg == NULL))
    {
        ADC_ReportDevError(ADC_INIT_ID, ADC_E_PARAM_POINTER);
    }
    else if (pAdcHandle->eInstance >= ADC_INSTANCE_COUNT)
    {
        ADC_ReportDevError(ADC_INIT_ID, ADC_E_PARAM_INSTANCE);
    }
    else
    {
    #endif

        ADC_Type *const pAdc = s_apAdcBase[pAdcHandle->eInstance];
        uint8_t u8SmprIndex;
        uint32_t u32TimeOut;
        uint32_t u32Cfg1;
        uint32_t u32Cfg2;
        uint32_t u32IntCfg;
        #if ADC_SUPPORT_GAIN_AND_OFFSET_CALIBRATION
        uint32_t u32Cal;
        #endif
        #if ADC_SUPPORT_SG_MODE
        bool bSGEnable = false;
        #endif
        ADC_TrgSrcType eTrgSrc;
        ADC_TrgModeType eTrgMode;
        uint32_t u32ClkDiv;
        uint32_t u32StartupCnt;
        uint32_t u32ClkFreq;
        PCC_ClkSrcType eClkName;

        switch (pInitCfg->eSeqMode)
        {
            #if ADC_SUPPORT_SG_MODE
            case ADC_SEQMODE_GROUP:
            {
                bSGEnable = true;
                eTrgSrc   = ADC_TRGSRC_TRG_LATCH_UNIT;
                eTrgMode  = ADC_TRGMODE_RISING_EDGE;
                u32IntCfg = 0u;
                break;
            }
            #endif
            case ADC_SEQMODE_DISCONTINUOUS_1:
            {
                eTrgSrc   = ADC_TRGSRC_PTIMER;
                eTrgMode  = ADC_TRGMODE_RISING_EDGE;
                u32IntCfg = ADC_INT_ENABLE_OVRIE(pInitCfg->bOverrunIntEn);
                break;
            }
            case ADC_SEQMODE_SINGLE:
            case ADC_SEQMODE_CONTINUOUS:
            case ADC_SEQMODE_DISCONTINUOUS_0:
            {
                eTrgSrc   = ADC_TRGSRC_TRGSEL;
                eTrgMode  = pInitCfg->eTrgMode;
                u32IntCfg = ADC_INT_ENABLE_OVRIE(pInitCfg->bOverrunIntEn) |
                            ADC_INT_ENABLE_FIFO_RDY_IE(pInitCfg->bConvCompleteIntEn);
                break;
            }
            default:
            {
                return;
            }
        }

        switch (pAdcHandle->eInstance)
        {
            case ADC_INSTANCE_0:
            {
                eClkName = PCC_CLK_ADC0;
                break;
            }

            case ADC_INSTANCE_1:
            {
                eClkName = PCC_CLK_ADC1;
                break;
            }
            #if ADC_INSTANCE_COUNT > 2u
            case ADC_INSTANCE_2:
            {
                eClkName = PCC_CLK_ADC2;
                break;
            }
            #endif
            #if ADC_INSTANCE_COUNT > 3u
            case ADC_INSTANCE_3:
            {
                eClkName = PCC_CLK_ADC3;
                break;
            }
            #endif
            #if ADC_INSTANCE_COUNT > 4u
            case ADC_INSTANCE_4:
            {
                eClkName = PCC_CLK_ADC4;
                break;
            }
            #endif
            #if ADC_INSTANCE_COUNT > 5u
            case ADC_INSTANCE_5:
            {
                eClkName = PCC_CLK_ADC5;
                break;
            }
            #endif
            default:
            {
                return;
            }
        }

        u32ClkDiv = 1U << pInitCfg->eClockDivider;
        u32ClkFreq = PCC_GetPccFunctionClock(eClkName);

        /* The start up count shall be around 5us */
        u32StartupCnt = u32ClkFreq / u32ClkDiv / 1000000U * 5U + 1U;
        if (u32StartupCnt < 2U)
        {
            u32StartupCnt = 2U;
        }
        else if (u32StartupCnt > 255U)
        {
            u32StartupCnt = 255U;
        }
        else
        {}

        /* Deinitialize the ADC before config it's registers, ADC_DeInit function will reset the registers */
        ADC_DeInit(pAdcHandle);

        u32Cfg1 = ADC_CFG1_OVRMOD(pInitCfg->eOverrunMode) |
                  #if ADC_SUPPORT_SG_MODE
                  ADC_CFG1_SEQGP_EN(bSGEnable)  |
                  #endif
                  ADC_CFG1_SEQ_LEN(0) |
                  ADC_CFG1_SEQ_MOD(pInitCfg->eSeqMode) |
                  ADC_CFG1_AUTO_DIS(pInitCfg->bAutoDis) |
                  ADC_CFG1_WAIT(pInitCfg->bWaitEn) |
                  #if ADC_SUPPORT_INSTANCE_DIFFMODE_SET
                  ADC_CFG1_DIFF(pInitCfg->bDifferentialModeEn) |
                  #endif
                  ADC_CFG1_TRIGSRC(eTrgSrc) |
                  ADC_CFG1_TRIGMODE(eTrgMode) |
                  ADC_CFG1_ALIGN(pInitCfg->eAlign) |
                  ADC_CFG1_RES(pInitCfg->eResolution) |
                  ADC_CFG1_DMAEN(pInitCfg->bDmaEn);
        ADC_HWA_SetConfig1(pAdc, u32Cfg1);

        u32Cfg2 = ADC_CFG2_FWMARK(ADC_DEFAULT_WATER_MARK) |
                  #if ADC_SUPPORT_GROUP_INJECTION
                  ADC_CFG2_SEQ_INJTEN(pInitCfg->bGroupInjectionEn) |
                  #endif
                  #if ADC_SUPPORT_SG_MODE
                  ADC_CFG2_TRG_PRI(pInitCfg->eTrgLatchUnitPri) |
                  ADC_CFG2_TRG_CLR(1U) |
                  #endif
                  ADC_CFG2_AVG_EN(pInitCfg->bAverageEn) |
                  ADC_CFG2_AVG_LEN(pInitCfg->eAverageLen) |
                  #if ADC_SUPPORT_INTERNAL_REFERENCE
                  ADC_CFG2_REF_EXT(pInitCfg->eVoltageRef) |
                  #endif
                  ADC_CFG2_STCNT(u32StartupCnt);
        ADC_HWA_SetConfig2(pAdc, u32Cfg2);

        #if ADC_SUPPORT_PERIOD_TRIGGER
        ADC_HWA_SetPeriodTriggerInterval(pAdc, pInitCfg->u16PeriodTrgInterval);
        #endif

        #if ADC_SUPPORT_GAIN_AND_OFFSET_CALIBRATION
        u32Cal = ADC_CAL_CAL_EN(pInitCfg->bCalibrationEn) |
                 ADC_CAL_OFFSET(pInitCfg->s32CalibrationOffset) |
                 ADC_CAL_GAIN(pInitCfg->s32CalibrationGain);
        ADC_HWA_SetCal(pAdc, u32Cal);
        #endif

        u32TimeOut = 15000000U;
        ADC_HWA_SetClockGatingEnable(pAdc, true);
        while ((ADC_HWA_GetClockGatingAck(pAdc) != true) && (u32TimeOut != 0))
        {
            u32TimeOut--;
        }
        if (ADC_HWA_GetClockGatingAck(pAdc) == true)
        {
            ADC_HWA_SetClockDivider(pAdc, pInitCfg->eClockDivider);
        }
        u32TimeOut = 15000000U;
        ADC_HWA_SetClockGatingEnable(pAdc, false);
        while ((ADC_HWA_GetClockGatingAck(pAdc) != false) && (u32TimeOut != 0))
        {
            u32TimeOut--;
        }

        for (u8SmprIndex = 0U; u8SmprIndex < ADC_SAMPLE_TIME_OPTION_CNT; u8SmprIndex++)
        {
            ADC_HWA_SetSampleTime(pAdc, u8SmprIndex, (uint8_t)(pInitCfg->aSampleTimes[u8SmprIndex] - 2U));
        }

        pAdcHandle->tSettings.eSeqMode            = pInitCfg->eSeqMode;
        pAdcHandle->tSettings.bConvCompleteIntEn  = pInitCfg->bConvCompleteIntEn;
        pAdcHandle->tSettings.pConvCompleteNotify = pInitCfg->pConvCompleteNotify;
        pAdcHandle->tSettings.pOverrunNotify      = pInitCfg->pOverrunNotify;
        pAdcHandle->tSettings.pResultBuffer       = pInitCfg->pResultBuffer;

        ADC_HWA_SetIntEnable(pAdc, u32IntCfg);

    #if ADC_DEV_ERROR_REPORT == STD_ON
    }
    #endif
}

void ADC_DeInit(ADC_HandleType *pAdcHandle)
{
    #if ADC_DEV_ERROR_REPORT == STD_ON
    if (pAdcHandle == NULL)
    {
        ADC_ReportDevError(ADC_DEINIT_ID, ADC_E_PARAM_POINTER);
    }
    else if (pAdcHandle->eInstance >= ADC_INSTANCE_COUNT)
    {
        ADC_ReportDevError(ADC_DEINIT_ID, ADC_E_PARAM_INSTANCE);
    }
    else
    {
    #endif

        ADC_Type *const pAdc = s_apAdcBase[pAdcHandle->eInstance];
        uint32_t u32TimeOut = 15000000U;
        if (ADC_HWA_GetStart(pAdc) == true)
        {
            ADC_HWA_Stop(pAdc);

            while ((ADC_HWA_GetStop(pAdc) == true) && (u32TimeOut != 0U))
            {
                u32TimeOut--;
            }
        }

        u32TimeOut = 15000000U;
        if (ADC_HWA_GetEnable(pAdc) == true)
        {
            ADC_HWA_Disable(pAdc);

            while ((ADC_HWA_GetEnable(pAdc) == true) && (u32TimeOut != 0U))
            {
                u32TimeOut--;
            }
        }

        /* Reset all registers to default values */

        ADC_HWA_Reset(pAdc);

    #if ADC_DEV_ERROR_REPORT == STD_ON
    }
    #endif
}

void ADC_InitChannel(ADC_HandleType *pAdcHandle, const ADC_ChannelCfgType aChannels[],
                     const uint8_t u8ChannelCnt)
{
    #if ADC_DEV_ERROR_REPORT == STD_ON
    if (pAdcHandle == NULL || aChannels == NULL)
    {
        ADC_ReportDevError(ADC_INIT_CHANNEL_ID, ADC_E_PARAM_POINTER);
    }
    else if (pAdcHandle->eInstance >= ADC_INSTANCE_COUNT)
    {
        ADC_ReportDevError(ADC_INIT_CHANNEL_ID, ADC_E_PARAM_INSTANCE);
    }
    else if (u8ChannelCnt >= ADC_SC_COUNT)
    {
        ADC_ReportDevError(ADC_INIT_CHANNEL_ID, ADC_E_PARAM_CHANNEL);
    }
    else if (u8ChannelCnt == 0u)
    {
        ADC_ReportDevError(ADC_INIT_CHANNEL_ID, ADC_E_PARAM_COUNT);
    }
    else
    {
    #endif

        ADC_Type *const pAdc = s_apAdcBase[pAdcHandle->eInstance];
        uint8_t u8ChnIndex;

        pAdcHandle->tSettings.u8ChannelCnt = u8ChannelCnt;

        for (u8ChnIndex = 0U; u8ChnIndex < u8ChannelCnt; u8ChnIndex++)
        {
            #if ADC_SUPPORT_CHANNEL_DIFFMODE_SET
            ADC_HWA_SetChannelDiffModeEnable(pAdc, u8ChnIndex, aChannels[u8ChnIndex].bDiff);
            #endif
            ADC_HWA_SetChannelSampleTimeIndex(pAdc, u8ChnIndex, aChannels[u8ChnIndex].eSampleTimeOption);
            ADC_HWA_SetChannelCoCoIntEnable(pAdc, u8ChnIndex, false);
            ADC_HWA_SetChannelInput(pAdc, u8ChnIndex, aChannels[u8ChnIndex].eChannel);
        }

        switch (pAdcHandle->tSettings.eSeqMode)
        {
            #if ADC_SUPPORT_SG_MODE
            case ADC_SEQMODE_GROUP:
            {
                /* TODO */
                break;
            }
            #endif
            case ADC_SEQMODE_DISCONTINUOUS_1:
            {
                ADC_HWA_SetChannelCoCoIntEnable(pAdc, (uint8_t)(u8ChannelCnt - 1U), (pAdcHandle->tSettings).bConvCompleteIntEn);
                break;
            }
            case ADC_SEQMODE_SINGLE:
            case ADC_SEQMODE_CONTINUOUS:
            case ADC_SEQMODE_DISCONTINUOUS_0:
            {
                ADC_HWA_SetSequenceLength(pAdc, (uint8_t)(u8ChannelCnt - 1U));
                ADC_HWA_SetFIFOWaterMark(pAdc, (uint8_t)(u8ChannelCnt - 1U));
                break;
            }
            default:
            {
                break;
            }
        }

    #if ADC_DEV_ERROR_REPORT == STD_ON
    }
    #endif
}

void ADC_InitCmpStructure(ADC_CmpType *const pCmpCfg)
{
    #if ADC_DEV_ERROR_REPORT == STD_ON
    if (pCmpCfg == NULL)
    {
        ADC_ReportDevError(ADC_INIT_CMP_STRUCTURE_ID, ADC_E_PARAM_POINTER);
    }
    else
    {
    #endif

        pCmpCfg->bCmpEn          = false;
        pCmpCfg->bCmpIntEn       = false;
        pCmpCfg->eCmpChannelType = ADC_CMP_CHANNEL_ALL;
        pCmpCfg->u8CmpChannelSel = 0U;
        pCmpCfg->u16CmpHighThres = ADC_DEFAULT_CMP_HIGH_THRESHOLD;
        pCmpCfg->u16CmpLowThres  = ADC_DEFAULT_CMP_LOW_THRESHOLD;
        pCmpCfg->pCmpNotify      = NULL;

    #if ADC_DEV_ERROR_REPORT == STD_ON
    }
    #endif
}

void ADC_InitCmp(ADC_HandleType *pAdcHandle, const ADC_CmpType *const pCmpCfg)
{
    #if ADC_DEV_ERROR_REPORT == STD_ON
    if ((pCmpCfg == NULL) || (pAdcHandle == NULL))
    {
        ADC_ReportDevError(ADC_INIT_CMP_ID, ADC_E_PARAM_POINTER);
    }
    else if ((pAdcHandle->eInstance) >= ADC_INSTANCE_COUNT)
    {
        ADC_ReportDevError(ADC_INIT_CMP_ID, ADC_E_PARAM_INSTANCE);
    }
    else
    {
    #endif

        ADC_Type *const pAdc = s_apAdcBase[pAdcHandle->eInstance];

        if (pCmpCfg->bCmpEn)
        {
            ADC_HWA_SetCmpChannel(pAdc, pCmpCfg->eCmpChannelType, pCmpCfg->u8CmpChannelSel);
            ADC_HWA_SetCmpThreshold(pAdc, pCmpCfg->u16CmpLowThres, pCmpCfg->u16CmpHighThres);
            ADC_HWA_SetCmpIntEnable(pAdc, pCmpCfg->bCmpIntEn);
            pAdcHandle->tSettings.pCmpNotify = pCmpCfg->pCmpNotify;
            ADC_HWA_SetCmpEnable(pAdc, true);
        }
        else
        {
            ADC_HWA_SetCmpEnable(pAdc, false);
        }

    #if ADC_DEV_ERROR_REPORT == STD_ON
    }
    #endif
}

#if ADC_SUPPORT_SG_MODE

void ADC_InitSGStrcuture(ADC_SGType *const pSGType)
{
    #if ADC_DEV_ERROR_REPORT == STD_ON
    if (pSGType == NULL)
    {
        ADC_ReportDevError(ADC_INIT_SG_STRUCTURE_ID, ADC_E_PARAM_POINTER);
    }
    else
    {
    #endif

        pSGType->bSG0En                 = false;
        pSGType->u8SG0Len               = 0;
        pSGType->aSG0Channels           = NULL;
        pSGType->bSG0ConvCompleteIntEn  = false;
        pSGType->pSG0ResultBuffer       = NULL;
        pSGType->pSG0ConvCompleteNotify = NULL;

        pSGType->bSG1En                 = false;
        pSGType->u8SG1Len               = 0;
        pSGType->aSG1Channels           = NULL;
        pSGType->bSG1ConvCompleteIntEn  = false;
        pSGType->pSG1ResultBuffer       = NULL;
        pSGType->pSG1ConvCompleteNotify = NULL;

        pSGType->bSG2En                 = false;
        pSGType->u8SG2Len               = 0;
        pSGType->aSG2Channels           = NULL;
        pSGType->bSG2ConvCompleteIntEn  = false;
        pSGType->pSG2ResultBuffer       = NULL;
        pSGType->pSG2ConvCompleteNotify = NULL;

        pSGType->bSG3En                 = false;
        pSGType->u8SG3Len               = 0;
        pSGType->aSG3Channels           = NULL;
        pSGType->bSG3ConvCompleteIntEn  = false;
        pSGType->pSG3ResultBuffer       = NULL;
        pSGType->pSG3ConvCompleteNotify = NULL;

        #if ADC_SUPPORT_SG_DMA_MODE
        pSGType->bSGDmaEn          = false;
        pSGType->u8SGDMAIndex      = 0;
        #endif

    #if ADC_DEV_ERROR_REPORT == STD_ON
    }
    #endif
}

void ADC_InitSG(ADC_HandleType *pAdcHandle, const ADC_SGType *const pSGType)
{
    #if ADC_DEV_ERROR_REPORT == STD_ON
    if ((pSGType == NULL) || (pAdcHandle == NULL))
    {
        ADC_ReportDevError(ADC_INIT_SG_ID, ADC_E_PARAM_POINTER);
    }
    else if ((pAdcHandle->eInstance) >= ADC_INSTANCE_COUNT)
    {
        ADC_ReportDevError(ADC_INIT_SG_ID, ADC_E_PARAM_INSTANCE);
    }
    else
    {
    #endif

        ADC_Type *const pAdc = s_apAdcBase[pAdcHandle->eInstance];
        uint8_t u8ChnIndex;
        uint8_t u8SCnIndex;

        u8SCnIndex = 0;

        #if ADC_SUPPORT_SG_DMA_MODE
        uint32_t u32RegVal;
        if (pSGType->bSGDmaEn)
        {
            u32RegVal = ADC_HWA_GetConfig1(pAdc);
            u32RegVal &= ~ADC_CFG1_SGDMA_SEL_MASK;
            u32RegVal = ADC_CFG1_SGDMA_SEL(pSGType->u8SGDMAIndex) | ADC_CFG1_SGDMAEN(true);
            ADC_HWA_SetConfig1(pAdc, u32RegVal);
        }
        else
        {
            u32RegVal = ADC_HWA_GetConfig1(pAdc);
            u32RegVal &= ~(ADC_CFG1_SGDMA_SEL_MASK | ADC_CFG1_SGDMAEN_MASK);
            ADC_HWA_SetConfig1(pAdc, u32RegVal);
        }
        #endif

        if (pSGType->bSG0En)
        {
            ADC_HWA_SetSGStartEndPoint(pAdc, 0, 0, (uint8_t)(0 + pSGType->u8SG0Len - 1));
            ADC_HWA_SetEndOfSGIntEnable(pAdc, 0, pSGType->bSG0ConvCompleteIntEn);
            pAdcHandle->tSettings.pSGResultBuffer[0]  = pSGType->pSG0ResultBuffer;
            pAdcHandle->tSettings.SGConvCompleteNotify[0] = pSGType->pSG0ConvCompleteNotify;

            for (u8ChnIndex = 0U; u8ChnIndex < pSGType->u8SG0Len; u8ChnIndex++)
            {
                ADC_HWA_SetChannelSampleTimeIndex(pAdc, u8SCnIndex, pSGType->aSG0Channels[u8ChnIndex].eSampleTimeOption);
                ADC_HWA_SetChannelCoCoIntEnable(pAdc, u8SCnIndex, false);
                ADC_HWA_SetChannelInput(pAdc, u8SCnIndex, pSGType->aSG0Channels[u8ChnIndex].eChannel);
                u8SCnIndex++;
            }
        }
        else
        {
            ADC_HWA_SetSGStartEndPoint(pAdc, 0, 0, 0);
            ADC_HWA_SetEndOfSGIntEnable(pAdc, 0, false);
            pAdcHandle->tSettings.pSGResultBuffer[0]  = NULL;
            pAdcHandle->tSettings.SGConvCompleteNotify[0] = NULL;
        }

        if (pSGType->bSG1En)
        {
            ADC_HWA_SetSGStartEndPoint(pAdc, 1, u8SCnIndex, (uint8_t)(u8SCnIndex + pSGType->u8SG1Len - 1));
            ADC_HWA_SetEndOfSGIntEnable(pAdc, 1, pSGType->bSG1ConvCompleteIntEn);
            pAdcHandle->tSettings.pSGResultBuffer[1]  = pSGType->pSG1ResultBuffer;
            pAdcHandle->tSettings.SGConvCompleteNotify[1] = pSGType->pSG1ConvCompleteNotify;

            for (u8ChnIndex = 0U; u8ChnIndex < pSGType->u8SG1Len; u8ChnIndex++)
            {
                ADC_HWA_SetChannelSampleTimeIndex(pAdc, u8SCnIndex, pSGType->aSG1Channels[u8ChnIndex].eSampleTimeOption);
                ADC_HWA_SetChannelCoCoIntEnable(pAdc, u8SCnIndex, false);
                ADC_HWA_SetChannelInput(pAdc, u8SCnIndex, pSGType->aSG1Channels[u8ChnIndex].eChannel);
                u8SCnIndex++;
            }
        }
        else
        {
            ADC_HWA_SetSGStartEndPoint(pAdc, 1, 0, 0);
            ADC_HWA_SetEndOfSGIntEnable(pAdc, 1, false);
            pAdcHandle->tSettings.pSGResultBuffer[1]  = NULL;
            pAdcHandle->tSettings.SGConvCompleteNotify[1] = NULL;
        }

        if (ADC_GET_SUPPORTED_SEQUENCE_GROUP_CNT(pAdcHandle->eInstance) >= 2)
        {
            if (pSGType->bSG2En)
            {
                ADC_HWA_SetSGStartEndPoint(pAdc, 2, u8SCnIndex, (uint8_t)(u8SCnIndex + pSGType->u8SG2Len - 1));
                ADC_HWA_SetEndOfSGIntEnable(pAdc, 2, pSGType->bSG2ConvCompleteIntEn);
                pAdcHandle->tSettings.pSGResultBuffer[2]  = pSGType->pSG2ResultBuffer;
                pAdcHandle->tSettings.SGConvCompleteNotify[2] = pSGType->pSG2ConvCompleteNotify;

                for (u8ChnIndex = 0U; u8ChnIndex < pSGType->u8SG2Len; u8ChnIndex++)
                {
                    ADC_HWA_SetChannelSampleTimeIndex(pAdc, u8SCnIndex, pSGType->aSG2Channels[u8ChnIndex].eSampleTimeOption);
                    ADC_HWA_SetChannelCoCoIntEnable(pAdc, u8SCnIndex, false);
                    ADC_HWA_SetChannelInput(pAdc, u8SCnIndex, pSGType->aSG2Channels[u8ChnIndex].eChannel);
                    u8SCnIndex++;
                }
            }
            else
            {
                ADC_HWA_SetSGStartEndPoint(pAdc, 2, 0, 0);
                ADC_HWA_SetEndOfSGIntEnable(pAdc, 2, false);
                pAdcHandle->tSettings.pSGResultBuffer[2]  = NULL;
                pAdcHandle->tSettings.SGConvCompleteNotify[2] = NULL;
            }

            if (pSGType->bSG3En)
            {
                ADC_HWA_SetSGStartEndPoint(pAdc, 3, u8SCnIndex, (uint8_t)(u8SCnIndex + pSGType->u8SG3Len - 1));
                ADC_HWA_SetEndOfSGIntEnable(pAdc, 3, pSGType->bSG3ConvCompleteIntEn);
                pAdcHandle->tSettings.pSGResultBuffer[3]  = pSGType->pSG3ResultBuffer;
                pAdcHandle->tSettings.SGConvCompleteNotify[3] = pSGType->pSG3ConvCompleteNotify;

                for (u8ChnIndex = 0U; u8ChnIndex < pSGType->u8SG3Len; u8ChnIndex++)
                {
                    ADC_HWA_SetChannelSampleTimeIndex(pAdc, u8SCnIndex, pSGType->aSG3Channels[u8ChnIndex].eSampleTimeOption);
                    ADC_HWA_SetChannelCoCoIntEnable(pAdc, u8SCnIndex, false);
                    ADC_HWA_SetChannelInput(pAdc, u8SCnIndex, pSGType->aSG3Channels[u8ChnIndex].eChannel);
                    u8SCnIndex++;
                }
            }
            else
            {
                ADC_HWA_SetSGStartEndPoint(pAdc, 3, 0, 0);
                ADC_HWA_SetEndOfSGIntEnable(pAdc, 3, false);
                pAdcHandle->tSettings.pSGResultBuffer[3]  = NULL;
                pAdcHandle->tSettings.SGConvCompleteNotify[3] = NULL;
            }
        }

    #if ADC_DEV_ERROR_REPORT == STD_ON
    }
    #endif
}
#endif

ADC_StatusType ADC_Enable(const ADC_HandleType *pAdcHandle)
{
    ADC_StatusType eRet = ADC_STATUS_SUCCESS;
    #if ADC_DEV_ERROR_REPORT == STD_ON
    if (pAdcHandle == NULL)
    {
        ADC_ReportDevError(ADC_ENABLE_ID, ADC_E_PARAM_POINTER);
        eRet = ADC_STATUS_ERROR;
    }
    else if ((pAdcHandle->eInstance) >= ADC_INSTANCE_COUNT)
    {
        ADC_ReportDevError(ADC_ENABLE_ID, ADC_E_PARAM_INSTANCE);
        eRet = ADC_STATUS_ERROR;
    }
    else
    {
    #endif

        uint32_t u32TimeOut = 15000000U;
        ADC_Type *const pAdc = s_apAdcBase[pAdcHandle->eInstance];

        ADC_HWA_Enable(pAdc);
        while ((ADC_HWA_GetADCReadyFlag(pAdc) != true) && (u32TimeOut != 0U))
        {
            u32TimeOut--;
        }
        if (u32TimeOut != 0U)
        {
            ADC_HWA_ClearADCReadyFlag(pAdc);
            eRet = ADC_STATUS_SUCCESS;
        }
        else
        {
            eRet = ADC_STATUS_TIMEOUT;
        }

    #if ADC_DEV_ERROR_REPORT == STD_ON
    }
    #endif

    return eRet;
}

ADC_StatusType ADC_Disable(ADC_HandleType *pAdcHandle)
{
    ADC_StatusType eRet = ADC_STATUS_SUCCESS;
    #if ADC_DEV_ERROR_REPORT == STD_ON
    if (pAdcHandle == NULL)
    {
        ADC_ReportDevError(ADC_DISABLE_ID, ADC_E_PARAM_POINTER);
    }
    else if ((pAdcHandle->eInstance) >= ADC_INSTANCE_COUNT)
    {
        ADC_ReportDevError(ADC_DISABLE_ID, ADC_E_PARAM_INSTANCE);
    }
    else
    {
    #endif

        uint32_t u32TimeOut = 15000000U;
        ADC_Type *const pAdc = s_apAdcBase[pAdcHandle->eInstance];

        if (ADC_HWA_GetStart(pAdc) == true)
        {
            eRet = ADC_Stop(pAdcHandle);
        }

        if (eRet == ADC_STATUS_SUCCESS)
        {
            ADC_HWA_Disable(pAdc);
            while ((ADC_HWA_GetEnable(pAdc) == true) && (u32TimeOut != 0U))
            {
                u32TimeOut--;
            }
            if (u32TimeOut != 0U)
            {
                eRet = ADC_STATUS_SUCCESS;
            }
            else
            {
                eRet = ADC_STATUS_TIMEOUT;
            }
        }

    #if ADC_DEV_ERROR_REPORT == STD_ON
    }
    #endif

    return eRet;
}

void ADC_Start(const ADC_HandleType *pAdcHandle)
{
    #if ADC_DEV_ERROR_REPORT == STD_ON
    if (pAdcHandle == NULL)
    {
        ADC_ReportDevError(ADC_START_ID, ADC_E_PARAM_POINTER);
    }
    else if ((pAdcHandle->eInstance) >= ADC_INSTANCE_COUNT)
    {
        ADC_ReportDevError(ADC_START_ID, ADC_E_PARAM_INSTANCE);
    }
    else
    {
    #endif

        ADC_Type *const pAdc = s_apAdcBase[pAdcHandle->eInstance];
        ADC_HWA_Start(pAdc);

    #if ADC_DEV_ERROR_REPORT == STD_ON
    }
    #endif
}

ADC_StatusType ADC_Stop(const ADC_HandleType *pAdcHandle)
{
    ADC_StatusType eRet = ADC_STATUS_ERROR;
    #if ADC_DEV_ERROR_REPORT == STD_ON
    if (pAdcHandle == NULL)
    {
        ADC_ReportDevError(ADC_STOP_ID, ADC_E_PARAM_POINTER);
    }
    else if ((pAdcHandle->eInstance) >= ADC_INSTANCE_COUNT)
    {
        ADC_ReportDevError(ADC_STOP_ID, ADC_E_PARAM_INSTANCE);
    }
    else
    {
    #endif

        uint32_t u32TimeOut = 15000000U;
        ADC_Type *const pAdc = s_apAdcBase[pAdcHandle->eInstance];

        ADC_HWA_Stop(pAdc);

        while ((ADC_HWA_GetStop(pAdc) == true) && (u32TimeOut != 0U))
        {
            u32TimeOut--;
        }
        if (u32TimeOut != 0U)
        {
            eRet = ADC_STATUS_SUCCESS;
        }
        else
        {
            eRet = ADC_STATUS_TIMEOUT;
        }

    #if ADC_DEV_ERROR_REPORT == STD_ON
    }
    #endif

    return eRet;
}

void ADC_Reset(const ADC_HandleType *pAdcHandle)
{
    #if ADC_DEV_ERROR_REPORT == STD_ON
    if (pAdcHandle == NULL)
    {
        ADC_ReportDevError(ADC_RESET_ID, ADC_E_PARAM_POINTER);
    }
    else if ((pAdcHandle->eInstance) >= ADC_INSTANCE_COUNT)
    {
        ADC_ReportDevError(ADC_RESET_ID, ADC_E_PARAM_INSTANCE);
    }
    else
    {
    #endif

        ADC_Type *const pAdc = s_apAdcBase[pAdcHandle->eInstance];
        ADC_HWA_Reset(pAdc);

    #if ADC_DEV_ERROR_REPORT == STD_ON
    }
    #endif
}

#if ADC_SUPPORT_SG_CMP_BLOCK

void ADC_InitSGCmpStructure(ADC_SGCmpType *const pConfig)
{
    #if ADC_DEV_ERROR_REPORT == STD_ON
    if (pConfig == NULL)
    {
        ADC_ReportDevError(ADC_SG_CMP_STRUCTURE_ID, ADC_E_PARAM_POINTER);
    }
    else
    {
    #endif

        pConfig->bSGCmpEn       = false;
        pConfig->bSGCmpIntEn    = false;
        pConfig->u32SGCmpREFSel = 0U;
        pConfig->u32SGCmpACTSel = 0U;
        pConfig->pSGCmpNotify   = NULL;

    #if ADC_DEV_ERROR_REPORT == STD_ON
    }
    #endif
}

void ADC_InitSGCmp(ADC_HandleType *pAdcHandle, const ADC_SGCmpType *const pConfig)
{
    #if ADC_DEV_ERROR_REPORT == STD_ON
    if (pAdcHandle == NULL || pConfig == NULL)
    {
        ADC_ReportDevError(ADC_SG_CMP_ID, ADC_E_PARAM_POINTER);
    }
    else if (ADC_IS_SUPPORT_SG_CMP_BLOCK(pAdcHandle->eInstance))
    {
        ADC_ReportDevError(ADC_SG_CMP_ID, ADC_E_PARAM_INSTANCE);
    }
    else
    {
    #endif

        uint32_t u32RegVal = 0U;
        uint8_t index;

        index = pAdcHandle->eInstance - ADC_SUPPORT_SG_CMP_INSTANCE_START;

        if (pConfig->bSGCmpEn)
        {
            u32RegVal = SMC_ADC_CFG0_SGCMP_EN(true) | \
                        SMC_ADC_CFG0_SGCMP_IEN(pConfig->bSGCmpIntEn) | \
                        SMC_ADC_CFG0_SGCMP_REF_SEL(pConfig->u32SGCmpREFSel & 0x0FFFFFFFU);
            SMC_HWA_SetADCCFG0(index, u32RegVal);

            u32RegVal = SMC_ADC_CFG1_SGCMP_ACT_SEL(pConfig->u32SGCmpACTSel & 0x0FFFFFFFU);
            SMC_HWA_SetADCCFG1(index, u32RegVal);

            pAdcHandle->tSettings.pSGCmpNotify = pConfig->pSGCmpNotify;
        }
        else
        {
            SMC_HWA_SetADCCFG0(index, 0x0);
            SMC_HWA_SetADCCFG1(index, 0x0);
            pAdcHandle->tSettings.pSGCmpNotify = NULL;
        }

    #if ADC_DEV_ERROR_REPORT == STD_ON
    }
    #endif
}
#endif /* #if ADC_SUPPORT_SG_CMP_BLOCK */

#if ADC_SUPPORT_ENHANCED_CMP_BLOCK

void ADC_InitECmpStructure(ADC_ECmpType *const pConfig)
{
    #if ADC_DEV_ERROR_REPORT == STD_ON
    if (pConfig == NULL)
    {
        ADC_ReportDevError(ADC_INIT_ECMP_STRUCTURE_ID, ADC_E_PARAM_POINTER);
    }
    else
    {
    #endif

        pConfig->bECmpEn          = false;
        pConfig->eECmpChannelType = ADC_ECMP_CHANNEL_ALL;
        pConfig->u8ECmpChannelSel = 0U;
        pConfig->u16ECmpHighThres = 0U;
        pConfig->u16ECmpLowThres  = 0U;
        pConfig->bECmpHighIntEn   = false;
        pConfig->bECmpLowIntEn    = false;
        pConfig->bECmpWinIntEn    = false;
        pConfig->pECmpHighNotify  = NULL;
        pConfig->pECmpLowNotify   = NULL;
        pConfig->pECmpWinNotify   = NULL;

    #if ADC_DEV_ERROR_REPORT == STD_ON
    }
    #endif
}

void ADC_InitECmp(ADC_HandleType *pAdcHandle, const ADC_ECmpType *const pConfig, const ADC_ECMPIndex u8Index)
{
    #if ADC_DEV_ERROR_REPORT == STD_ON
    if (pAdcHandle == NULL || pConfig == NULL)
    {
        ADC_ReportDevError(ADC_INIT_ECMP_ID, ADC_E_PARAM_POINTER);
    }
    else if (ADC_IS_SUPPORT_ENHANCED_CMP_BLOCK(pAdcHandle->eInstance))
    {
        ADC_ReportDevError(ADC_INIT_ECMP_ID, ADC_E_PARAM_INSTANCE);
    }
    else
    {
    #endif

        ADC_Type *const pAdc = s_apAdcBase[pAdcHandle->eInstance];

        if (pConfig->bECmpEn)
        {
            ADC_HWA_SetECMPOption(pAdc, u8Index, pConfig->eECmpOption);
            ADC_HWA_SetECMPSGL(pAdc, u8Index, pConfig->eECmpChannelType);
            ADC_HWA_SetECMPChannel(pAdc, u8Index, pConfig->u8ECmpChannelSel);
            ADC_HWA_SetECMPHighIntEnable(pAdc, u8Index, pConfig->bECmpHighIntEn);
            ADC_HWA_SetECMPLowIntEnable(pAdc, u8Index, pConfig->bECmpLowIntEn);
            ADC_HWA_SetECMPWinIntEnable(pAdc, u8Index, pConfig->bECmpWinIntEn);
            ADC_HWA_SetECMPThreshold(pAdc, u8Index, pConfig->u16ECmpLowThres, pConfig->u16ECmpHighThres);
            ADC_HWA_SetECMPEnable(pAdc, u8Index, true);
            pAdcHandle->tSettings.pECmpHighNotify[u8Index] = pConfig->pECmpHighNotify;
            pAdcHandle->tSettings.pECmpLowNotify[u8Index]  = pConfig->pECmpLowNotify;
            pAdcHandle->tSettings.pECmpWinNotify[u8Index]  = pConfig->pECmpWinNotify;
        }
        else
        {
            ADC_HWA_SetECMPEnable(pAdc, u8Index, false);
        }

    #if ADC_DEV_ERROR_REPORT == STD_ON
    }
    #endif
}
#endif /* #if ADC_SUPPORT_ENHANCED_CMP_BLOCK */

#if ADC_SUPPORT_FAST_CMP_BLOCK
void ADC_InitFCmpStructure(ADC_FCmpType *const pFCmpCfg)
{
    #if ADC_DEV_ERROR_REPORT == STD_ON
    if (pFCmpCfg == NULL)
    {
        ADC_ReportDevError(ADC_INIT_FCMP_STRUCTURE_ID, ADC_E_PARAM_POINTER);
    }
    else
    {
    #endif

        pFCmpCfg->bFCmpEn               = false;
        pFCmpCfg->eFCmpChannel          = ADC_CHANNEL_0;
        pFCmpCfg->eFCmpSampleTimeOption = ADC_SAMPLE_TIME_OPTION_0;
        pFCmpCfg->bFCmpPreSetResult     = false;
        pFCmpCfg->u16FCmpRefValue       = 0U;
        pFCmpCfg->u16FCmpUpperDelta     = 0U;
        pFCmpCfg->u16FCmpLowerDelta     = 0U;
        pFCmpCfg->eFCmpRefMode          = ADC_FCMP_REFMODE_SW;
        pFCmpCfg->eFCmpRampDir          = ADC_FCMP_RAMPDIR_UP;
        pFCmpCfg->eFCmpRampTrgMode      = ADC_FCMP_RAMPTRGMODE_SW_AUTO;
        pFCmpCfg->eFCmpRampTrgPol       = ADC_FCMP_RAMPTRGPOL_RISING_OR_HIGH;
        pFCmpCfg->u8FCmpRampStep        = 0U;
        pFCmpCfg->u16FCmpRampRefA       = 0U;
        pFCmpCfg->u16FCmpRampRefB       = 0U;
        pFCmpCfg->bFCmpBFLEn            = false;
        pFCmpCfg->eFCmpBFLAct           = ADC_FCMP_BFA_A1B0;
        pFCmpCfg->bFCmpBFLInvert        = false;
        pFCmpCfg->bFCmpFallingIntEn     = false;
        pFCmpCfg->bFCmpRisingIntEn      = false;
        pFCmpCfg->pFCmpRisingNotify     = NULL;
        pFCmpCfg->pFCmpFallingNotify    = NULL;

    #if ADC_DEV_ERROR_REPORT == STD_ON
    }
    #endif
}

void ADC_InitFCmp(ADC_HandleType *pAdcHandle, const ADC_FCmpType *const pFCmpCfg)
{
    #if ADC_DEV_ERROR_REPORT == STD_ON
    if ((pFCmpCfg == NULL) || (pAdcHandle == NULL))
    {
        ADC_ReportDevError(ADC_INIT_FCMP_ID, ADC_E_PARAM_POINTER);
    }
    else if (ADC_IS_SUPPORT_FAST_CMP_BLOCK(pAdcHandle->eInstance))
    {
        ADC_ReportDevError(ADC_INIT_FCMP_ID, ADC_E_PARAM_INSTANCE);
    }
    else
    {
    #endif
        ADC_Type *const pAdc = s_apAdcBase[pAdcHandle->eInstance];
        uint32_t u32FCCTRL;
        uint32_t u32FCHyst;
        uint32_t u32FCRamp0;
        uint32_t u32FCRamp1;

        bool bFCModALT = false;
        bool bFCRampCntEn = false;

        if (pFCmpCfg->bFCmpEn == true)
        {
            if (pFCmpCfg->eFCmpRefMode == ADC_FCMP_REFMODE_SW)
            {
                bFCModALT = false;
                bFCRampCntEn = false;
            }
            else if(pFCmpCfg->eFCmpRefMode == ADC_FCMP_REFMODE_RAMP)
            {
                bFCModALT = false;
                bFCRampCntEn = true;
            }
            else if(pFCmpCfg->eFCmpRefMode == ADC_FCMP_REFMODE_ALT)
            {
                bFCModALT = true;
                bFCRampCntEn = false;
            }
            else
            {
                bFCModALT = false;
                bFCRampCntEn = false;
            }

            /* Config fast compare channel */
            ADC_HWA_SetChannelSampleTimeIndex(pAdc, 0, pFCmpCfg->eFCmpSampleTimeOption);
            ADC_HWA_SetChannelCoCoIntEnable(pAdc, 0, false);
            ADC_HWA_SetChannelInput(pAdc, 0, pFCmpCfg->eFCmpChannel);
            ADC_HWA_SetSequenceLength(pAdc, 0U);
            ADC_HWA_SetFIFOWaterMark(pAdc, 0U);

            /* Disable fast compare function firstly. */
            ADC_HWA_SetFCEnable(pAdc, false);

            ADC_HWA_SetFCRef(pAdc, pFCmpCfg->u16FCmpRefValue);

            u32FCRamp0 = ((pFCmpCfg->u16FCmpRampRefA << 16) | pFCmpCfg->u8FCmpRampStep);
            ADC_HWA_SetFCRamp0(pAdc, u32FCRamp0);

            u32FCRamp1 = ((pFCmpCfg->u16FCmpRampRefB << 16) | pFCmpCfg->eFCmpRampDir);
            ADC_HWA_SetFCRamp1(pAdc, u32FCRamp1);

            u32FCHyst = ((pFCmpCfg->u16FCmpUpperDelta << 16) | pFCmpCfg->u16FCmpLowerDelta);
            ADC_HWA_SetFCHysteresis(pAdc, u32FCHyst);

            /* Just write fast compare ctrl register after setting other fast compare function registers. */
            u32FCCTRL = ADC_FCMP_CTRL_RPTRG_SEL(pFCmpCfg->eFCmpRampTrgMode) |
                        ADC_FCMP_CTRL_RPCNT_EN(bFCRampCntEn) |
                        ADC_FCMP_CTRL_ETRG_POL(pFCmpCfg->eFCmpRampTrgPol) |
                        ADC_FCMP_CTRL_FCMOD_ALT(bFCModALT) |
                        ADC_FCMP_CTRL_FC_EN(true); /* Enable fast compare function here. */
            ADC_HWA_SetFCCtrl(pAdc, u32FCCTRL);

            if (pFCmpCfg->bFCmpFallingIntEn)
            {
                ADC_HWA_SetFCRFIntEnable(pAdc, true);
                pAdcHandle->tSettings.pFCmpFallingNotify = pFCmpCfg->pFCmpFallingNotify;
            }
            else
            {
                ADC_HWA_SetFCRFIntEnable(pAdc, false);
                pAdcHandle->tSettings.pFCmpFallingNotify = NULL;
            }

            if (pFCmpCfg->bFCmpRisingIntEn)
            {
                ADC_HWA_SetFCRRIntEnable(pAdc, true);
                pAdcHandle->tSettings.pFCmpRisingNotify = pFCmpCfg->pFCmpRisingNotify;
            }
            else
            {
                ADC_HWA_SetFCRRIntEnable(pAdc, false);
                pAdcHandle->tSettings.pFCmpRisingNotify = NULL;
            }
        }
        else
        {
            ADC_HWA_SetFCEnable(pAdc, false);

            pAdcHandle->tSettings.pFCmpFallingNotify = NULL;
            pAdcHandle->tSettings.pFCmpRisingNotify  = NULL;
        }

    #if ADC_DEV_ERROR_REPORT == STD_ON
    }
    #endif
}

#endif /* #if ADC_SUPPORT_FAST_CMP_BLOCK */

#endif /* #if ADC_INSTANCE_COUNT > 0U */
