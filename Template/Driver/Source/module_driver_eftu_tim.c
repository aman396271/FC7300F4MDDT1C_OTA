/**
 * @file eftu_driver_tim.h
 * @author Flagchip
 * @brief FC7xxx eFTU TBU driver access layer
 * @version 2.0.0
 * @date
 *
 * SDK Version: 2.6.0
 *

 * @copyright Copyright (c) 2024 Flagchip Semiconductors Co., Ltd.
 *
 * @details
 */
#include "module_driver_eftu_tim.h"

#if defined(EFTU_INSTANCE_COUNT) && (EFTU_INSTANCE_COUNT > 0)
static EFTU_TIM_Type *const s_pEftuTimBasePtrs[EFTU_INSTANCE_COUNT] = EFTU_TIM_ADDRESS_TAB;

#ifndef TIM_DEV_ERROR_REPORT
    #define TIM_DEV_ERROR_REPORT    STD_ON
#endif

#if TIM_DEV_ERROR_REPORT == STD_ON
    #define TIM_ReportDevError(func, error) ReportDevError(EFTU_TIM_MODULE_ID, func, error)
#endif




/**
 * @brief Config Tim edge detect function
 * @param pTimHandle  Tim processing handle
 * @param pInitStruct  Tim Signal Detect InitStruct
 */
void EFTU_Tim_EdgeDetectChannelInit(EFTU_TIM_HandleType *pTimHandle, const EFTU_TimSignalDetectConfigStruct *pInitStruct)
{
    EFTU_TIM_Type *pTim = s_pEftuTimBasePtrs[pTimHandle->eInstance];

    #if TIM_DEV_ERROR_REPORT == STD_ON
    if (EFTU_TIM_CH_7 < pInitStruct->eChannelIndex)
    {
        TIM_ReportDevError(EFTU_TIM_DETECT_ID, EFTU_TIM_E_PARAM_CHANNEL);
    }
    else
    #endif
    {
        /*FLT config*/
        if (pInitStruct->tFilterConfig.bEnFilter == TRUE)
        {
            EFTU_TIM_HWA_EnableFlt(pTim, (uint8_t)pInitStruct->eChannelIndex); /*enable Flt*/
            EFTU_TIM_HWA_SetChFltSrc(pTim, pInitStruct->tFilterConfig.eFliterClock, (uint8_t)pInitStruct->eChannelIndex);
            /*rise edge*/
            switch (pInitStruct->tFilterConfig.eRisingEdgeMode)
            {
                case EFTU_TIM_FILTERMODE_IMMEDIATEEDGEPROPAGATION:
                {
                    EFTU_TIM_HWA_DisableChFltRe(pTim, (uint8_t)pInitStruct->eChannelIndex);
                    EFTU_TIM_HWA_DisableChFltReCounter(pTim, (uint8_t)pInitStruct->eChannelIndex);
                    EFTU_TIM_HWA_DisableChFltReExbit(pTim, (uint8_t)pInitStruct->eChannelIndex);
                    break;
                }
                case EFTU_TIM_FILTERMODE_INDIVIDUALDEGLITCHTIMEUPDOWN:
                {
                    EFTU_TIM_HWA_EnableChFltRe(pTim, (uint8_t)pInitStruct->eChannelIndex);
                    EFTU_TIM_HWA_DisableChFltReCounter(pTim, (uint8_t)pInitStruct->eChannelIndex);
                    EFTU_TIM_HWA_DisableChFltReExbit(pTim, (uint8_t)pInitStruct->eChannelIndex);
                    break;
                }
                case EFTU_TIM_FILTERMODE_INDIVIDUALDEGLITCHTIMEHOLD:
                {
                    EFTU_TIM_HWA_EnableChFltRe(pTim, (uint8_t)pInitStruct->eChannelIndex);
                    EFTU_TIM_HWA_EnableChFltReCounter(pTim, (uint8_t)pInitStruct->eChannelIndex);
                    EFTU_TIM_HWA_DisableChFltReExbit(pTim, (uint8_t)pInitStruct->eChannelIndex);
                    break;
                }
                case EFTU_TIM_FILTERMODE_RESETCOUNTR:
                {
                    EFTU_TIM_HWA_EnableChFltRe(pTim, (uint8_t)pInitStruct->eChannelIndex);
                    EFTU_TIM_HWA_DisableChFltReCounter(pTim, (uint8_t)pInitStruct->eChannelIndex);
                    EFTU_TIM_HWA_EnableChFltReExbit(pTim, (uint8_t)pInitStruct->eChannelIndex);
                    break;
                }
                default:
                    break;
            }

            /*fall edge*/
            switch (pInitStruct->tFilterConfig.eFallingEdgeMode)
            {
                case EFTU_TIM_FILTERMODE_IMMEDIATEEDGEPROPAGATION:
                {
                    EFTU_TIM_HWA_DisableChFltFe(pTim, (uint8_t)pInitStruct->eChannelIndex);
                    EFTU_TIM_HWA_DisableChFltFeCounter(pTim, (uint8_t)pInitStruct->eChannelIndex);
                    EFTU_TIM_HWA_DisableChFltFeExbit(pTim, (uint8_t)pInitStruct->eChannelIndex);
                    break;
                }
                case EFTU_TIM_FILTERMODE_INDIVIDUALDEGLITCHTIMEUPDOWN:
                {
                    EFTU_TIM_HWA_EnableChFltFe(pTim, (uint8_t)pInitStruct->eChannelIndex);
                    EFTU_TIM_HWA_DisableChFltFeCounter(pTim, (uint8_t)pInitStruct->eChannelIndex);
                    EFTU_TIM_HWA_DisableChFltFeExbit(pTim, (uint8_t)pInitStruct->eChannelIndex);
                    break;
                }
                case EFTU_TIM_FILTERMODE_INDIVIDUALDEGLITCHTIMEHOLD:
                {
                    EFTU_TIM_HWA_EnableChFltFe(pTim, (uint8_t)pInitStruct->eChannelIndex);
                    EFTU_TIM_HWA_EnableChFltFeCounter(pTim, (uint8_t)pInitStruct->eChannelIndex);
                    EFTU_TIM_HWA_DisableChFltFeExbit(pTim, (uint8_t)pInitStruct->eChannelIndex);
                    break;
                }
                case EFTU_TIM_FILTERMODE_RESETCOUNTR:
                {
                    EFTU_TIM_HWA_EnableChFltFe(pTim, (uint8_t)pInitStruct->eChannelIndex);
                    EFTU_TIM_HWA_DisableChFltFeCounter(pTim, (uint8_t)pInitStruct->eChannelIndex);
                    EFTU_TIM_HWA_EnableChFltFeExbit(pTim, (uint8_t)pInitStruct->eChannelIndex);
                    break;
                }

            }
            EFTU_TIM_HWA_SetChFltReValue(pTim, pInitStruct->tFilterConfig.u8RisingEdgeFilterTime, (uint8_t)pInitStruct->eChannelIndex);
            EFTU_TIM_HWA_SetChFltFeValue(pTim, pInitStruct->tFilterConfig.u8FallingEdgeFilterTime, (uint8_t)pInitStruct->eChannelIndex);
            if (TRUE == pInitStruct->tFilterConfig.bIrqOnGlitch)
            {
                EFTU_TIM_HWA_EnIrq(pTim, EFTU_TIM_IRQ_GLITCHDET, (uint8_t)pInitStruct->eChannelIndex);
            }
        }

        /*Timeout configuration*/
        EFTU_TIM_HWA_SetTimeoutEdge(pTim, pInitStruct->tTimeouConfig.eTimeOutSensitiveEgde, (uint8_t)pInitStruct->eChannelIndex);
        EFTU_TIM_HWA_SetTduClk(pTim, pInitStruct->tTimeouConfig.eTimeOutClkSrc, (uint8_t)pInitStruct->eChannelIndex);
        EFTU_TOM_HWA_SetimeoutValue(pTim, pInitStruct->tTimeouConfig.u32Timeout, (uint8_t)pInitStruct->eChannelIndex);
        if (TRUE == pInitStruct->tTimeouConfig.bIrqOnTimeout)
        {
            EFTU_TIM_HWA_EnIrq(pTim, EFTU_TIM_IRQ_TODET, (uint8_t)pInitStruct->eChannelIndex);
        }


        /*F_IN() config*/
        switch (pInitStruct->eInputSrc)
        {
            case EFTU_TIM_INPUT_TIM_IN_X:
            {
                EFTU_TIM_HWA_ConfigLut(pTim, EFTU_TIM_LUT_DISABLE, (uint8_t)pInitStruct->eChannelIndex);
                EFTU_TIM_HWA_ClearVal(pTim, (uint8_t)pInitStruct->eChannelIndex);
                EFTU_TIM_HWA_ClearAuxMode(pTim, (uint8_t)pInitStruct->eChannelIndex);
                EFTU_TIM_HWA_ClearchCicrl(pTim, (uint8_t)pInitStruct->eChannelIndex);
                break;
            }
            case EFTU_TIM_INPUT_TIM_IN_X_1:
            {
                EFTU_TIM_HWA_ConfigLut(pTim, EFTU_TIM_LUT_DISABLE, (uint8_t)pInitStruct->eChannelIndex);
                EFTU_TIM_HWA_ClearVal(pTim, (uint8_t)pInitStruct->eChannelIndex);
                EFTU_TIM_HWA_ClearAuxMode(pTim, (uint8_t)pInitStruct->eChannelIndex);
                EFTU_TIM_HWA_SetchCicrl(pTim, (uint8_t)pInitStruct->eChannelIndex);
                break;
            }
            case EFTU_TIM_INPUT_TIM_IN_AUX_IN:
            {
                EFTU_TIM_HWA_ConfigLut(pTim, EFTU_TIM_LUT_DISABLE, (uint8_t)pInitStruct->eChannelIndex);
                EFTU_TIM_HWA_SetVal(pTim, (uint8_t)pInitStruct->eChannelIndex);
                EFTU_TIM_HWA_ClearAuxMode(pTim, (uint8_t)pInitStruct->eChannelIndex);
                break;
            }
            default:
                break;
        }


        /*Tim channel configuration*/
        EFTU_TIM_HWA_SetChannelMode(pTim, EFTU_TIM_MODE_INPUTEVENT, (uint8_t)pInitStruct->eChannelIndex);
        EFTU_TIM_HWA_SetChannelClockSrc(pTim, pInitStruct->eTimClockSrc, (uint8_t)pInitStruct->eChannelIndex);

        if (pInitStruct->bIrqOnNewVal == TRUE)
        {
            EFTU_TIM_HWA_EnIrq(pTim, EFTU_TIM_IRQ_NEWVAL, (uint8_t)pInitStruct->eChannelIndex);
        }
        if (pInitStruct->bIrqOnCntOveflow == TRUE)
        {
            EFTU_TIM_HWA_EnIrq(pTim, EFTU_TIM_IRQ_CNTOFL, (uint8_t)pInitStruct->eChannelIndex);
        }
        if (pInitStruct->bIrqOnECntOveflow == TRUE)
        {
            EFTU_TIM_HWA_EnIrq(pTim, EFTU_TIM_IRQ_ECNTOFL, (uint8_t)pInitStruct->eChannelIndex);
        }
        if (pInitStruct->bIrqOnGprDataOverflow == TRUE)
        {
            EFTU_TIM_HWA_EnIrq(pTim, EFTU_TIM_IRQ_GPR0OFL, (uint8_t)pInitStruct->eChannelIndex);
        }

        if (TRUE == pInitStruct->bExtCapEn)
        {
            EFTU_TIM_HWA_EnableExtCapture(pTim, pInitStruct->bExtCapEn, (uint8_t)pInitStruct->eChannelIndex);
        }

        if (EFTU_TIM_ACTIVE_BOTHEDGE == pInitStruct->eActiveEdge)
        {
            EFTU_TIM_HWA_EnIngnoreEdge(pTim, TRUE, (uint8_t)pInitStruct->eChannelIndex);
        }
        else
        {
            EFTU_TIM_HWA_ConfigActiveEdge(pTim, pInitStruct->eActiveEdge, (uint8_t)pInitStruct->eChannelIndex);
        }

        /*Update Global Status*/
        pTimHandle->pTim = pTim;
        pTimHandle->tTimChnStatus[pInitStruct->eChannelIndex].pTimChannelIrqCallback = pInitStruct->pTimChannelIrqCallback;


    }



}


/**
 * @brief Config Tim signal measurement  function
 * @param pTimHandle  Tim processing handle
 * @param pInitStruct  Tim Signal measurement InitStruct
 */
void EFTU_Tim_PwmMeasurementInit(EFTU_TIM_HandleType *pTimHandle, const EFTU_TimSignalMeasurementConfigStruct *pInitStruct)
{
    EFTU_TIM_Type *pTim = s_pEftuTimBasePtrs[pTimHandle->eInstance];
    #if TIM_DEV_ERROR_REPORT == STD_ON
    if (EFTU_TIM_ACTIVE_BOTHEDGE == pInitStruct->eActiveEdge)
    {
        TIM_ReportDevError(EFTU_TIM_PWM_MEASUREMENT_ID, EFTU_TIM_E_PARAM_INVALID_EDGE);
    }
    else if (EFTU_TIM_CH_7 < pInitStruct->eChannelIndex)
    {
        TIM_ReportDevError(EFTU_TIM_PWM_MEASUREMENT_ID, EFTU_TIM_E_PARAM_CHANNEL);
    }
    else
    #endif
    {
        /*FLT config*/
        if (pInitStruct->tFilterConfig.bEnFilter == TRUE)
        {
            EFTU_TIM_HWA_EnableFlt(pTim, (uint8_t)pInitStruct->eChannelIndex); /*enable Flt*/
            EFTU_TIM_HWA_SetChFltSrc(pTim, pInitStruct->tFilterConfig.eFliterClock, (uint8_t)pInitStruct->eChannelIndex);
            /*rise edge*/
            switch (pInitStruct->tFilterConfig.eRisingEdgeMode)
            {
                case EFTU_TIM_FILTERMODE_IMMEDIATEEDGEPROPAGATION:
                {
                    EFTU_TIM_HWA_DisableChFltRe(pTim, (uint8_t)pInitStruct->eChannelIndex);
                    EFTU_TIM_HWA_DisableChFltReCounter(pTim, (uint8_t)pInitStruct->eChannelIndex);
                    EFTU_TIM_HWA_DisableChFltReExbit(pTim, (uint8_t)pInitStruct->eChannelIndex);
                    break;
                }
                case EFTU_TIM_FILTERMODE_INDIVIDUALDEGLITCHTIMEUPDOWN:
                {
                    EFTU_TIM_HWA_EnableChFltRe(pTim, (uint8_t)pInitStruct->eChannelIndex);
                    EFTU_TIM_HWA_DisableChFltReCounter(pTim, (uint8_t)pInitStruct->eChannelIndex);
                    EFTU_TIM_HWA_DisableChFltReExbit(pTim, (uint8_t)pInitStruct->eChannelIndex);
                    break;
                }
                case EFTU_TIM_FILTERMODE_INDIVIDUALDEGLITCHTIMEHOLD:
                {
                    EFTU_TIM_HWA_EnableChFltRe(pTim, (uint8_t)pInitStruct->eChannelIndex);
                    EFTU_TIM_HWA_EnableChFltReCounter(pTim, (uint8_t)pInitStruct->eChannelIndex);
                    EFTU_TIM_HWA_DisableChFltReExbit(pTim, (uint8_t)pInitStruct->eChannelIndex);
                    break;
                }
                case EFTU_TIM_FILTERMODE_RESETCOUNTR:
                {
                    EFTU_TIM_HWA_EnableChFltRe(pTim, (uint8_t)pInitStruct->eChannelIndex);
                    EFTU_TIM_HWA_DisableChFltReCounter(pTim, (uint8_t)pInitStruct->eChannelIndex);
                    EFTU_TIM_HWA_EnableChFltReExbit(pTim, (uint8_t)pInitStruct->eChannelIndex);
                    break;
                }
                default:
                    break;
            }

            /*fall edge*/
            switch (pInitStruct->tFilterConfig.eFallingEdgeMode)
            {
                case EFTU_TIM_FILTERMODE_IMMEDIATEEDGEPROPAGATION:
                {
                    EFTU_TIM_HWA_DisableChFltFe(pTim, (uint8_t)pInitStruct->eChannelIndex);
                    EFTU_TIM_HWA_DisableChFltFeCounter(pTim, (uint8_t)pInitStruct->eChannelIndex);
                    EFTU_TIM_HWA_DisableChFltFeExbit(pTim, (uint8_t)pInitStruct->eChannelIndex);
                    break;
                }
                case EFTU_TIM_FILTERMODE_INDIVIDUALDEGLITCHTIMEUPDOWN:
                {
                    EFTU_TIM_HWA_EnableChFltFe(pTim, (uint8_t)pInitStruct->eChannelIndex);
                    EFTU_TIM_HWA_DisableChFltFeCounter(pTim, (uint8_t)pInitStruct->eChannelIndex);
                    EFTU_TIM_HWA_DisableChFltFeExbit(pTim, (uint8_t)pInitStruct->eChannelIndex);
                    break;
                }
                case EFTU_TIM_FILTERMODE_INDIVIDUALDEGLITCHTIMEHOLD:
                {
                    EFTU_TIM_HWA_EnableChFltFe(pTim, (uint8_t)pInitStruct->eChannelIndex);
                    EFTU_TIM_HWA_EnableChFltFeCounter(pTim, (uint8_t)pInitStruct->eChannelIndex);
                    EFTU_TIM_HWA_DisableChFltFeExbit(pTim, (uint8_t)pInitStruct->eChannelIndex);
                    break;
                }
                case EFTU_TIM_FILTERMODE_RESETCOUNTR:
                {
                    EFTU_TIM_HWA_EnableChFltFe(pTim, (uint8_t)pInitStruct->eChannelIndex);
                    EFTU_TIM_HWA_DisableChFltFeCounter(pTim, (uint8_t)pInitStruct->eChannelIndex);
                    EFTU_TIM_HWA_EnableChFltFeExbit(pTim, (uint8_t)pInitStruct->eChannelIndex);
                    break;
                }

            }
            EFTU_TIM_HWA_SetChFltReValue(pTim, pInitStruct->tFilterConfig.u8RisingEdgeFilterTime, (uint8_t)pInitStruct->eChannelIndex);
            EFTU_TIM_HWA_SetChFltFeValue(pTim, pInitStruct->tFilterConfig.u8FallingEdgeFilterTime, (uint8_t)pInitStruct->eChannelIndex);
            if (TRUE == pInitStruct->tFilterConfig.bIrqOnGlitch)
            {
                EFTU_TIM_HWA_EnIrq(pTim, EFTU_TIM_IRQ_GLITCHDET, (uint8_t)pInitStruct->eChannelIndex);
            }
        }

        /*Timeout configuration*/
        EFTU_TIM_HWA_SetTimeoutEdge(pTim, pInitStruct->tTimeouConfig.eTimeOutSensitiveEgde, (uint8_t)pInitStruct->eChannelIndex);
        EFTU_TIM_HWA_SetTduClk(pTim, pInitStruct->tTimeouConfig.eTimeOutClkSrc, (uint8_t)pInitStruct->eChannelIndex);
        EFTU_TOM_HWA_SetimeoutValue(pTim, pInitStruct->tTimeouConfig.u32Timeout, (uint8_t)pInitStruct->eChannelIndex);
        if (TRUE == pInitStruct->tTimeouConfig.bIrqOnTimeout)
        {
            EFTU_TIM_HWA_EnIrq(pTim, EFTU_TIM_IRQ_TODET, (uint8_t)pInitStruct->eChannelIndex);
        }

        /*F_IN() config*/
        switch (pInitStruct->eInputSrc)
        {
            case EFTU_TIM_INPUT_TIM_IN_X:
            {
                EFTU_TIM_HWA_ConfigLut(pTim, EFTU_TIM_LUT_DISABLE, (uint8_t)pInitStruct->eChannelIndex);
                EFTU_TIM_HWA_ClearVal(pTim, (uint8_t)pInitStruct->eChannelIndex);
                EFTU_TIM_HWA_ClearAuxMode(pTim, (uint8_t)pInitStruct->eChannelIndex);
                EFTU_TIM_HWA_ClearchCicrl(pTim, (uint8_t)pInitStruct->eChannelIndex);
                break;
            }
            case EFTU_TIM_INPUT_TIM_IN_X_1:
            {
                EFTU_TIM_HWA_ConfigLut(pTim, EFTU_TIM_LUT_DISABLE, (uint8_t)pInitStruct->eChannelIndex);
                EFTU_TIM_HWA_ClearVal(pTim, (uint8_t)pInitStruct->eChannelIndex);
                EFTU_TIM_HWA_ClearAuxMode(pTim, (uint8_t)pInitStruct->eChannelIndex);
                EFTU_TIM_HWA_SetchCicrl(pTim, (uint8_t)pInitStruct->eChannelIndex);
                break;
            }
            case EFTU_TIM_INPUT_TIM_IN_AUX_IN:
            {
            	EFTU_TIM_HWA_UnLock(pTim);
                EFTU_TIM_HWA_ConfigLut(pTim, EFTU_TIM_LUT_DISABLE, (uint8_t)pInitStruct->eChannelIndex);
                EFTU_TIM_HWA_SetVal(pTim, (uint8_t)pInitStruct->eChannelIndex);
                EFTU_TIM_HWA_ClearAuxMode(pTim, (uint8_t)pInitStruct->eChannelIndex);
                EFTU_TIM_HWA_Lock(pTim);
                break;
            }
            default:
                break;
        }

        /*Tim channel configuration*/
        EFTU_TIM_HWA_SetChannelMode(pTim, EFTU_TIM_MODE_PWMMEASUREMENT, (uint8_t)pInitStruct->eChannelIndex);
        EFTU_TIM_HWA_SetTbu0BitFiled(pTim, pInitStruct->eTimTbs0align, (uint8_t)pInitStruct->eChannelIndex);
        EFTU_TIM_HWA_SetChannelClockSrc(pTim, pInitStruct->eTimClockSrc, (uint8_t)pInitStruct->eChannelIndex);

        EFTU_TIM_HWA_SetCntsSel(pTim, EFTU_TIM_CNTS_CNT, (uint8_t)pInitStruct->eChannelIndex);
        EFTU_TIM_HWA_SetGPR0Sel(pTim, EFTU_TIM_GPTSEL_CNTS_OR_CNT, (uint8_t)pInitStruct->eChannelIndex);
        EFTU_TIM_HWA_SetGPR1Sel(pTim, EFTU_TIM_GPTSEL_CNTS_OR_CNT, (uint8_t)pInitStruct->eChannelIndex);

        if (pInitStruct->bIrqOnNewVal == TRUE)
        {
            EFTU_TIM_HWA_EnIrq(pTim, EFTU_TIM_IRQ_NEWVAL, (uint8_t)pInitStruct->eChannelIndex);
        }
        if (pInitStruct->bIrqOnCntOveflow == TRUE)
        {
            EFTU_TIM_HWA_EnIrq(pTim, EFTU_TIM_IRQ_CNTOFL, (uint8_t)pInitStruct->eChannelIndex);
        }
        if (pInitStruct->bIrqOnECntOveflow == TRUE)
        {
            EFTU_TIM_HWA_EnIrq(pTim, EFTU_TIM_IRQ_ECNTOFL, (uint8_t)pInitStruct->eChannelIndex);
        }
        if (pInitStruct->bIrqOnGprDataOverflow == TRUE)
        {
            EFTU_TIM_HWA_EnIrq(pTim, EFTU_TIM_IRQ_GPR0OFL, (uint8_t)pInitStruct->eChannelIndex);
        }

        if (TRUE == pInitStruct->bExtCapEn)
        {
            EFTU_TIM_HWA_EnableExtCapture(pTim, pInitStruct->bExtCapEn, (uint8_t)pInitStruct->eChannelIndex);
        }
        EFTU_TIM_HWA_ConfigActiveEdge(pTim, pInitStruct->eActiveEdge, (uint8_t)pInitStruct->eChannelIndex);
        /*Update Global Status*/
        pTimHandle->pTim = pTim;
        pTimHandle->tTimChnStatus[pInitStruct->eChannelIndex].pTimChannelIrqCallback = pInitStruct->pTimChannelIrqCallback;
    }
}

/**
 * @brief Enable Tim channel function
 * @param pTimHandle  Tim processing handle
 * @param eChannelIndex  Tim channel Index
 */
void EFTU_Tim_EnableChannel(EFTU_TIM_HandleType *pTimHandle, const EFTU_TIM_ChannelIndex eChannelIndex)
{
    EFTU_TIM_Type *pTim = s_pEftuTimBasePtrs[pTimHandle->eInstance];
    EFTU_TIM_HWA_EnableChannel(pTim, (uint8_t)eChannelIndex);
}

/**
 * @brief Disable Tim channel function
 * @param pTimHandle  Tim processing handle
 * @param eChannelIndex  Tim channel Index
 */
void EFTU_Tim_DisableChannel(EFTU_TIM_HandleType *pTimHandle, const EFTU_TIM_ChannelIndex eChannelIndex)
{
    EFTU_TIM_Type *pTim = s_pEftuTimBasePtrs[pTimHandle->eInstance];
    EFTU_TIM_HWA_DisableChannel(pTim, (uint8_t)eChannelIndex);
}


/**
 * @brief Update Tim channel capture value.
 * @param pTimHandle  Tim processing handle
 * @param eChannelIndex  Tim channel Index
 */
void EFTU_TimUpdateNewValue(EFTU_TIM_HandleType *pTimHandle, const EFTU_TIM_ChannelIndex eChannelIndex)
{
    EFTU_TIM_Type *pTim = s_pEftuTimBasePtrs[pTimHandle->eInstance];
    pTimHandle->tTimChnStatus[eChannelIndex].bNewDataIrqStatus = FALSE;
    pTimHandle->tTimChnStatus[eChannelIndex].bNewDataIrqStatus = EFTU_TIM_HWA_GetTimeOutEvent(pTim, eChannelIndex);
    if (pTimHandle->tTimChnStatus[eChannelIndex].bNewDataIrqStatus == TRUE)
    {
        pTimHandle->tTimChnStatus[eChannelIndex].u32CntsValue = EFTU_TIM_HWA_GetCntsCnt(pTim, eChannelIndex);
        pTimHandle->tTimChnStatus[eChannelIndex].u32CntValue = EFTU_TIM_HWA_GetChCnt(pTim, eChannelIndex);
        pTimHandle->tTimChnStatus[eChannelIndex].u32Gpr0Value = EFTU_TIM_HWA_GetChGPR0(pTim, eChannelIndex);
        pTimHandle->tTimChnStatus[eChannelIndex].u32Gpr1Value = EFTU_TIM_HWA_GetChGPR1(pTim, eChannelIndex);
        pTimHandle->tTimChnStatus[eChannelIndex].u32DataCoherentStatus = EFTU_TIM_HWA_GetChGPR0Ecnt(pTim, eChannelIndex);
        EFTU_TIM_HWA_ClearNewValFlag(pTim, eChannelIndex);
    }
}


/**
 * @brief Tim Interrupt process.
 * @param pTimHandle  Tim processing handle
 * @param u8StartChannelIndex  Tim  Irq start channel Index
 */
void EFTU_TIM_IrqHandler(EFTU_TIM_HandleType *pTimHandle, uint8_t u8StartChannelIndex)
{
    EFTU_TIM_Type *pTim = s_pEftuTimBasePtrs[pTimHandle->eInstance];
    for (uint8_t u8ChannelIndex = u8StartChannelIndex; u8ChannelIndex < u8StartChannelIndex + 4U; u8ChannelIndex++)
    {
        bool bIntFlag = FALSE;
        pTimHandle->tTimChnStatus[u8ChannelIndex].bGlitchIrqStatus = FALSE;
        pTimHandle->tTimChnStatus[u8ChannelIndex].bEcntOverflowIrqStatus = FALSE;
        pTimHandle->tTimChnStatus[u8ChannelIndex].bGprOverflowIrqStatus = FALSE;
        pTimHandle->tTimChnStatus[u8ChannelIndex].bTimeOutIrqStatus = FALSE;
        pTimHandle->tTimChnStatus[u8ChannelIndex].bOverflowCntIrqStatus = FALSE;
        pTimHandle->tTimChnStatus[u8ChannelIndex].bNewDataIrqStatus = FALSE;

        if ((EFTU_TIM_HWA_GetGlitchEvent(pTim, u8ChannelIndex)) && (EFTU_TIM_HWA_GetGlitchIrqEnable(pTim, u8ChannelIndex)))
        {
            pTimHandle->tTimChnStatus[u8ChannelIndex].bGlitchIrqStatus = TRUE;
            EFTU_TIM_HWA_ClearGlitchFlag(pTim, u8ChannelIndex);
            bIntFlag  = TRUE;
        }

        if ((EFTU_TIM_HWA_GetEcntEvent(pTim, u8ChannelIndex)) && (EFTU_TIM_HWA_GetEcntIrqEnable(pTim, u8ChannelIndex)))
        {
            pTimHandle->tTimChnStatus[u8ChannelIndex].bEcntOverflowIrqStatus = TRUE;
            EFTU_TIM_HWA_ClearEcntFlag(pTim, u8ChannelIndex);
            bIntFlag  = TRUE;
        }


        if ((EFTU_TIM_HWA_GetGprOverflowEvent(pTim, u8ChannelIndex)) && (EFTU_TIM_HWA_GetGprOverflowIrqEnable(pTim, u8ChannelIndex)))
        {
            pTimHandle->tTimChnStatus[u8ChannelIndex].bGprOverflowIrqStatus = TRUE;
            EFTU_TIM_HWA_ClearGprOverflowFlag(pTim, u8ChannelIndex);
            bIntFlag  = TRUE;
        }


        if ((EFTU_TIM_HWA_GetTimeOutEvent(pTim, u8ChannelIndex)) && (EFTU_TIM_HWA_GetTimeOutIrqEnable(pTim, u8ChannelIndex)))
        {
            pTimHandle->tTimChnStatus[u8ChannelIndex].bTimeOutIrqStatus = TRUE;
            EFTU_TIM_HWA_ClearTimeOutFlag(pTim, u8ChannelIndex);
            bIntFlag  = TRUE;
        }

        if ((EFTU_TIM_HWA_GetCntOverflowEvent(pTim, u8ChannelIndex)) && (EFTU_TIM_HWA_GetCntOverflowIrqEnable(pTim, u8ChannelIndex)))
        {
            pTimHandle->tTimChnStatus[u8ChannelIndex].bOverflowCntIrqStatus = TRUE;
            EFTU_TIM_HWA_ClearCntOverflowFlag(pTim, u8ChannelIndex);
            bIntFlag  = TRUE;
        }
        /*Update Data*/
        if ((EFTU_TIM_HWA_GetNewValEvent(pTim, u8ChannelIndex)) && (EFTU_TIM_HWA_GetNewValIrqEnable(pTim, u8ChannelIndex)))
        {
            pTimHandle->tTimChnStatus[u8ChannelIndex].bNewDataIrqStatus = TRUE;
            EFTU_TIM_HWA_ClearNewValFlag(pTim, u8ChannelIndex);
            bIntFlag  = TRUE;
            pTimHandle->tTimChnStatus[u8ChannelIndex].u32CntsValue = EFTU_TIM_HWA_GetCntsCnt(pTim, u8ChannelIndex);
            pTimHandle->tTimChnStatus[u8ChannelIndex].u32CntValue = EFTU_TIM_HWA_GetChCnt(pTim, u8ChannelIndex);
            pTimHandle->tTimChnStatus[u8ChannelIndex].u32Gpr0Value = EFTU_TIM_HWA_GetChGPR0(pTim, u8ChannelIndex);
            pTimHandle->tTimChnStatus[u8ChannelIndex].u32Gpr1Value = EFTU_TIM_HWA_GetChGPR1(pTim, u8ChannelIndex);
            pTimHandle->tTimChnStatus[u8ChannelIndex].u32DataCoherentStatus = EFTU_TIM_HWA_GetChGPR0Ecnt(pTim, u8ChannelIndex);
        }
        /*Call Notification Callback*/
        if ((bIntFlag  == TRUE) && (pTimHandle->tTimChnStatus[u8ChannelIndex].pTimChannelIrqCallback != NULL))
        {
            pTimHandle->tTimChnStatus[u8ChannelIndex].pTimChannelIrqCallback(pTimHandle, u8ChannelIndex);
        }

    }
}


#endif /* defined(EFTU_INSTANCE_COUNT) && (EFTU_INSTANCE_COUNT > 0) */
