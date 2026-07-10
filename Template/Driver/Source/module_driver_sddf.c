/**
 * @file module_driver_sddf.c
 * @author Flagchip
 * @brief Sigma Delta Digital Filter (SDDF) driver source code
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
 *   0.2.0       2023-02-07    Flagchip030   N/A          First version for FC7300
 ******************************************************************************** */

#include "module_driver_sddf.h"
#include "HwA_scm.h"
#if SDDF_INSTANCE_COUNT > 0u

#ifndef SDDF_DEV_ERROR_REPORT
#define SDDF_DEV_ERROR_REPORT    STD_OFF
#endif
#if SDDF_DEV_ERROR_REPORT == STD_ON
    #define SDDF_ReportDevError(func, error) ReportDevError(SDDF_MODULE_ID, func, error)
#endif

static SDDF_Type *const s_apSddfBase[SDDF_INSTANCE_COUNT] = SDDF_BASE_PTRS;

static uint32_t *s_apSddfChannelBuffer[SDDF_INSTANCE_COUNT][SDDF_CH_CNT] = {NULL};


void SDDFn_IRQHandler(SDDF_HandleType *pHandle)
{
    SDDF_InstanceType eInstance =pHandle->eInstance;
    SDDF_Type *const  pSddf     = s_apSddfBase[eInstance];
    uint8_t           u8Channel = 0U;
    while ((u8Channel < SDDF_CH_CNT) && (SDDF_HWA_GetNormalInterruptStatus(pSddf) != 0U))
    {
        if (SDDF_HWA_GetChannelZeroCrossDetectStatus(pSddf, u8Channel) == true)
        {
            SDDF_HWA_ClearChannelZeroCrossDetectStatus(pSddf, u8Channel);
            if (pHandle->tSettings.Notifications[u8Channel].pZeroCrossDetectNotify != NULL)
            {
                pHandle->tSettings.Notifications[u8Channel].pZeroCrossDetectNotify(SDDF_ZERO_CROSS_EVENT);
            }
        }
        if (SDDF_HWA_GetChannelFIFODataReadyStatus(pSddf, u8Channel) == true)
        {
            if (s_apSddfChannelBuffer[eInstance][u8Channel] != NULL)
            {
                uint8_t u8FIFODepth = (uint8_t)(SDDF_HWA_GetChannelFIFOWatermark(pSddf, u8Channel) + 1U);
                uint8_t u8FIFOIdx   = 0U;
                for (u8FIFOIdx = 0U; u8FIFOIdx < u8FIFODepth; u8FIFOIdx++)
                {
                    s_apSddfChannelBuffer[eInstance][u8Channel][u8FIFOIdx] = SDDF_HWA_GetChannelData(pSddf, u8Channel);
                }
                SDDF_HWA_ClearChannelFIFODataReadyStatus(pSddf, u8Channel);
                if (pHandle->tSettings.Notifications[u8Channel].pFIFOReadyNotify != NULL)
                {
                    pHandle->tSettings.Notifications[u8Channel].pFIFOReadyNotify(s_apSddfChannelBuffer[eInstance][u8Channel]);
                }
            }
        }
        if (SDDF_HWA_GetChannelConvCompleteStatus(pSddf, u8Channel) == true)
        {
            SDDF_HWA_ClearChannelConvCompleteStatus(pSddf, u8Channel);
            if (pHandle->tSettings.Notifications[u8Channel].pConvCompleteNotify != NULL)
            {
                pHandle->tSettings.Notifications[u8Channel].pConvCompleteNotify();
            }
        }
        u8Channel++;
    }
    u8Channel = 0U;
    while ((u8Channel < SDDF_CH_CNT) && (SDDF_HWA_GetAbnormalInterruptStatus0(pSddf) != 0U))
    {
        if (SDDF_HWA_GetChannelLowLimitStatus(pSddf, u8Channel) == true)
        {
            SDDF_HWA_ClearChannelLowLimitStatus(pSddf, u8Channel);
            if (pHandle->tSettings.Notifications[u8Channel].pLimitCheckNotify != NULL)
            {
                pHandle->tSettings.Notifications[u8Channel].pLimitCheckNotify(SDDF_LOW_LIMIT_EVENT);
            }
        }
        if (SDDF_HWA_GetChannelHighLimitStatus(pSddf, u8Channel) == true)
        {
            SDDF_HWA_ClearChannelHighLimitStatus(pSddf, u8Channel);
            if (pHandle->tSettings.Notifications[u8Channel].pLimitCheckNotify != NULL)
            {
                pHandle->tSettings.Notifications[u8Channel].pLimitCheckNotify(SDDF_HIGH_LIMIT_EVENT);
            }
        }
        if (SDDF_HWA_GetChannelWindowLimitStatus(pSddf, u8Channel) == true)
        {
            SDDF_HWA_ClearChannelWindowLimitStatus(pSddf, u8Channel);
            if (pHandle->tSettings.Notifications[u8Channel].pLimitCheckNotify != NULL)
            {
                pHandle->tSettings.Notifications[u8Channel].pLimitCheckNotify(SDDF_WINDOW_LIMIT_EVENT);
            }
        }
        if (SDDF_HWA_GetChannelShortCircuitDetectStatus(pSddf, u8Channel) == true)
        {
            SDDF_HWA_ClearChannelShortCircuitDetectStatus(pSddf, u8Channel);
            if (pHandle->tSettings.Notifications[u8Channel].pShortCircuitDetectNotify != NULL)
            {
                pHandle->tSettings.Notifications[u8Channel].pShortCircuitDetectNotify(SDDF_SHORT_CIRCUIT_EVENT);
            }
        }
        u8Channel++;
    }
    u8Channel = 0U;
    while ((u8Channel < SDDF_CH_CNT) && (SDDF_HWA_GetAbnormalInterruptStatus1(pSddf) != 0U))
    {
        if (SDDF_HWA_GetChannelClockAbsenceStatus(pSddf, u8Channel) == true)
        {
            SDDF_HWA_ClearChannelClockAbsenceStatus(pSddf, u8Channel);
            if (pHandle->tSettings.Notifications[u8Channel].pClockAbsenceDetectNotify != NULL)
            {
                pHandle->tSettings.Notifications[u8Channel].pClockAbsenceDetectNotify(SDDF_CLOCK_ABSENCE_EVENT);
            }
        }
        if (SDDF_HWA_GetChannelSaturationStatus(pSddf, u8Channel) == true)
        {
            SDDF_HWA_ClearChannelSaturationStatus(pSddf, u8Channel);
            if (pHandle->tSettings.Notifications[u8Channel].pDataSaturationNotify != NULL)
            {
                pHandle->tSettings.Notifications[u8Channel].pDataSaturationNotify();
            }
        }
        if (SDDF_HWA_GetChannelFIFOUnderflowStatus(pSddf, u8Channel) == true)
        {
            SDDF_HWA_ClearChannelFIFOUnderflowStatus(pSddf, u8Channel);
            if (pHandle->tSettings.Notifications[u8Channel].pUnderflowNotify != NULL)
            {
                pHandle->tSettings.Notifications[u8Channel].pUnderflowNotify();
            }
        }
        if (SDDF_HWA_GetChannelFIFOOverflowStatus(pSddf, u8Channel) == true)
        {
            SDDF_HWA_ClearChannelFIFOOverflowStatus(pSddf, u8Channel);
            if (pHandle->tSettings.Notifications[u8Channel].pOverflowNotify != NULL)
            {
                pHandle->tSettings.Notifications[u8Channel].pOverflowNotify();
            }
        }
        u8Channel++;
    }
}

void SDDFn_CHnDMAHandler(SDDF_HandleType *pHandle, uint8_t u8Channel)
{
    SDDF_InstanceType eInstance =pHandle->eInstance;
    SDDF_Type *const  pSddf     = s_apSddfBase[eInstance];
    if (SDDF_HWA_GetChannelFIFODataReadyStatus(pSddf, u8Channel) == true)
    {
        SDDF_HWA_ClearChannelFIFODataReadyStatus(pSddf, u8Channel);
    }
    if (pHandle->tSettings.Notifications[u8Channel].pDMAReadyNotify != NULL)
    {
        pHandle->tSettings.Notifications[u8Channel].pDMAReadyNotify(s_apSddfChannelBuffer[eInstance][u8Channel]);
    }
}

void SDDF_DeInit(SDDF_HandleType *pHandle)
{
#if SDDF_DEV_ERROR_REPORT == STD_ON
    if (pHandle == NULL)
    {
        SDDF_ReportDevError(SDDF_DEINIT_ID, SDDF_E_PARAM_POINTER);
    }
    else if(pHandle->eInstance >= SDDF_INSTANCE_COUNT)
    {
        SDDF_ReportDevError(SDDF_DEINIT_ID, SDDF_E_PARAM_INSTANCE);
    }
    else
    {
#endif
    SDDF_InstanceType eInstance =pHandle->eInstance;
    SDDF_Type *const pSddf = s_apSddfBase[eInstance];
    SDDF_HWA_MainDisable(pSddf);
    SDDF_HWA_Reset(pSddf);
    SDDF_HWA_ClearNormalInterruptStatus(pSddf);
    SDDF_HWA_ClearAbnormalInterruptStatus0(pSddf);
    SDDF_HWA_ClearAbnormalInterruptStatus1(pSddf);
    SDDF_HWA_SetCtrl(pSddf, 0U);
#if SDDF_DEV_ERROR_REPORT == STD_ON
    }
#endif
}

void SDDF_Init(SDDF_HandleType *pHandle, const SDDF_InitConfigType *pInitCfg)
{
#if SDDF_DEV_ERROR_REPORT == STD_ON
    if (pHandle == NULL)
    {
        SDDF_ReportDevError(SDDF_INIT_ID, SDDF_E_PARAM_POINTER);
    }
    else if(pHandle->eInstance >= SDDF_INSTANCE_COUNT)
    {
        SDDF_ReportDevError(SDDF_INIT_ID, SDDF_E_PARAM_INSTANCE);
    }
    else if(pInitCfg == NULL)
    {
        SDDF_ReportDevError(SDDF_INIT_ID, SDDF_E_PARAM_POINTER);
    }
    else
    {
#endif
    SDDF_InstanceType eInstance =pHandle->eInstance;
    SDDF_Type *const pSddf = s_apSddfBase[eInstance];
    uint32_t         u32Ctrl;
    SDDF_DeInit(pHandle);
    u32Ctrl = SDDF_CTRL_PRESCALE(pInitCfg->ePreDiv) | SDDF_CTRL_MCLK_DIV(pInitCfg->u16Div);
    SDDF_HWA_SetCtrl(pSddf, u32Ctrl);
#if SDDF_DEV_ERROR_REPORT == STD_ON
    }
#endif
}

void SDDF_ConfigClockOut(SDDF_HandleType *pHandle, const SDDF_ClockOutConfigType *pClockOutCfg)
{
#if SDDF_DEV_ERROR_REPORT == STD_ON
    if (pHandle == NULL)
    {
        SDDF_ReportDevError(SDDF_CFG_CLK_OUT_ID, SDDF_E_PARAM_POINTER);
    }
    else if(pHandle->eInstance >= SDDF_INSTANCE_COUNT)
    {
        SDDF_ReportDevError(SDDF_CFG_CLK_OUT_ID, SDDF_E_PARAM_INSTANCE);
    }
    else if(pClockOutCfg == NULL)
    {
        SDDF_ReportDevError(SDDF_CFG_CLK_OUT_ID, SDDF_E_PARAM_POINTER);
    }
    else
    {
#endif
    SDDF_InstanceType eInstance =pHandle->eInstance;
    SDDF_Type *const pSddf   = s_apSddfBase[eInstance];
    uint32_t         u32Ctrl = (SDDF_HWA_GetCtrl(pSddf) & ~(SDDF_CTRL_CLKO0_DIS_MASK | SDDF_CTRL_CLKO1_DIS_MASK | SDDF_CTRL_CLKO2_DIS_MASK)) |
                       SDDF_CTRL_CLKO0_DIS(!pClockOutCfg->bClockOut0Enable) | SDDF_CTRL_CLKO1_DIS(!pClockOutCfg->bClockOut1Enable) |
                       SDDF_CTRL_CLKO2_DIS(!pClockOutCfg->bClockOut2Enable);
    SDDF_HWA_SetCtrl(pSddf, u32Ctrl);
    //    SCM_HWA_SetClkOutSel_SDDF_CH0((SCM_SDDF_ClkOutSelType)pClockOutCfg->eClk0Src);
    //    SCM_HWA_SetClkOutSel_SDDF_CH1((SCM_SDDF_ClkOutSelType)pClockOutCfg->eClk1Src);
    //    SCM_HWA_SetClkOutSel_SDDF_CH2((SCM_SDDF_ClkOutSelType)pClockOutCfg->eClk2Src);
    //    SCM_HWA_SetClkOutSel_SDDF_CH3((SCM_SDDF_ClkOutSelType)pClockOutCfg->eClk3Src);
#if SDDF_DEV_ERROR_REPORT == STD_ON
    }
#endif
}

void SDDF_Enable(SDDF_HandleType *pHandle)
{
#if SDDF_DEV_ERROR_REPORT == STD_ON
    if (pHandle == NULL)
    {
        SDDF_ReportDevError(SDDF_ENABLE_ID, SDDF_E_PARAM_POINTER);
    }
    else if(pHandle->eInstance >= SDDF_INSTANCE_COUNT)
    {
        SDDF_ReportDevError(SDDF_ENABLE_ID, SDDF_E_PARAM_INSTANCE);
    }
    else
    {
#endif
    SDDF_InstanceType eInstance =pHandle->eInstance;
    SDDF_Type *const pSddf = s_apSddfBase[eInstance];
    SDDF_HWA_MainEnable(pSddf);
#if SDDF_DEV_ERROR_REPORT == STD_ON
    }
#endif
}

void SDDF_Disable(SDDF_HandleType *pHandle)
{
#if SDDF_DEV_ERROR_REPORT == STD_ON
    if (pHandle == NULL)
    {
        SDDF_ReportDevError(SDDF_DISABLE_ID, SDDF_E_PARAM_POINTER);
    }
    else if(pHandle->eInstance >= SDDF_INSTANCE_COUNT)
    {
        SDDF_ReportDevError(SDDF_DISABLE_ID, SDDF_E_PARAM_INSTANCE);
    }
    else
    {
#endif
    SDDF_InstanceType eInstance =pHandle->eInstance;
    SDDF_Type *const pSddf = s_apSddfBase[eInstance];
    SDDF_HWA_MainDisable(pSddf);
#if SDDF_DEV_ERROR_REPORT == STD_ON
    }
#endif
}

void SDDF_EnableDebugMode(SDDF_HandleType *pHandle, SDDF_DebugModuleEnableType eModuleEnable)
{
#if SDDF_DEV_ERROR_REPORT == STD_ON
    if (pHandle == NULL)
    {
        SDDF_ReportDevError(SDDF_EN_DBG_MODE_ID, SDDF_E_PARAM_POINTER);
    }
    else if(pHandle->eInstance >= SDDF_INSTANCE_COUNT)
    {
        SDDF_ReportDevError(SDDF_EN_DBG_MODE_ID, SDDF_E_PARAM_INSTANCE);
    }
    else
    {
#endif
    SDDF_InstanceType eInstance =pHandle->eInstance;
    SDDF_Type *const pSddf   = s_apSddfBase[eInstance];
    uint32_t         u32Ctrl = (SDDF_HWA_GetCtrl(pSddf) & ~(SDDF_CTRL_DBG_MODE_MASK | SDDF_CTRL_DBG_EN_MASK)) | SDDF_CTRL_DBG_MODE(true) | SDDF_CTRL_DBG_EN(eModuleEnable);
    SDDF_HWA_SetCtrl(pSddf, u32Ctrl);
#if SDDF_DEV_ERROR_REPORT == STD_ON
    }
#endif
}

void SDDF_DisableDebugMode(SDDF_HandleType *pHandle)
{
#if SDDF_DEV_ERROR_REPORT == STD_ON
    if (pHandle == NULL)
    {
        SDDF_ReportDevError(SDDF_DIS_DBG_MODE_ID, SDDF_E_PARAM_POINTER);
    }
    else if(pHandle->eInstance >= SDDF_INSTANCE_COUNT)
    {
        SDDF_ReportDevError(SDDF_DIS_DBG_MODE_ID, SDDF_E_PARAM_INSTANCE);
    }
    else
    {
#endif
    SDDF_InstanceType eInstance =pHandle->eInstance;
    SDDF_Type *const pSddf   = s_apSddfBase[eInstance];
    uint32_t         u32Ctrl = SDDF_HWA_GetCtrl(pSddf) & ~(SDDF_CTRL_DBG_MODE_MASK | SDDF_CTRL_DBG_EN_MASK);
    SDDF_HWA_SetCtrl(pSddf, u32Ctrl);
#if SDDF_DEV_ERROR_REPORT == STD_ON
    }
#endif
}

void SDDF_InitChannel(SDDF_HandleType *pHandle, uint8_t u8Channel, const SDDF_ChannelConfigType *pChannelCfg)
{
#if SDDF_DEV_ERROR_REPORT == STD_ON
    if (pHandle == NULL)
    {
        SDDF_ReportDevError(SDDF_INIT_CH_ID, SDDF_E_PARAM_POINTER);
    }
    else if(pHandle->eInstance >= SDDF_INSTANCE_COUNT)
    {
        SDDF_ReportDevError(SDDF_INIT_CH_ID, SDDF_E_PARAM_INSTANCE);
    }
    else if(u8Channel >= SDDF_CH_CNT)
    {
        SDDF_ReportDevError(SDDF_INIT_CH_ID, SDDF_E_PARAM_CHANNEL);
    }
    else if(pChannelCfg == NULL)
    {
        SDDF_ReportDevError(SDDF_INIT_CH_ID, SDDF_E_PARAM_POINTER);
    }
    else if(pChannelCfg->bMainFilterEnable && pChannelCfg->pMainFilterConfig==NULL)
    {
        SDDF_ReportDevError(SDDF_INIT_CH_ID, SDDF_E_PARAM_MAIN_FILTER);
    }
    else if(pChannelCfg->bAuxiliaryFilterEnable && pChannelCfg->pAuxiliaryFilterConfig == NULL)
    {
        SDDF_ReportDevError(SDDF_INIT_CH_ID, SDDF_E_PARAM_AUX_FILTER);
    }
    else
    {
#endif
    SDDF_InstanceType eInstance =pHandle->eInstance;
    SDDF_Type *const pSddf = s_apSddfBase[eInstance];
    uint32_t         u32ChannelConfig;
    uint32_t         u32ChannelDataRate;
    u32ChannelConfig = SDDF_CFR_TRGLVL(pChannelCfg->eTriggerEvent) | SDDF_CFR_TRGSEL(pChannelCfg->eTriggerSrc) | SDDF_CFR_CLKEDG(pChannelCfg->eInputClockEdge) |
                       SDDF_CFR_CLKSEL(SDDF_CLOCK_SRC_EXTERNAL_MODULATOR_CLOCK) | SDDF_CFR_IBFMT(pChannelCfg->eBitFormat) | SDDF_CFR_RDFMT(pChannelCfg->eResultFormat) |
                       SDDF_CFR_FWMK(pChannelCfg->u8FIFOWatermark - 1U);
    SDDF_HWA_SetChannelConfig(pSddf, u8Channel, u32ChannelConfig);
    switch (u8Channel)
    {
        case 0U:
            {
                // SCM_HWA_SetClkInSel_SDDF_CH0((SCM_SDDF_ClkInSelType)pChannelCfg->eInputClockSrc);
                break;
            }
        case 1U:
            {
                // SCM_HWA_SetClkInSel_SDDF_CH1((SCM_SDDF_ClkInSelType)pChannelCfg->eInputClockSrc);
                break;
            }
        case 2U:
            {
                // SCM_HWA_SetClkInSel_SDDF_CH2((SCM_SDDF_ClkInSelType)pChannelCfg->eInputClockSrc);
                break;
            }
        case 3U:
            {
                // SCM_HWA_SetClkInSel_SDDF_CH3((SCM_SDDF_ClkInSelType)pChannelCfg->eInputClockSrc);
                break;
            }
        default:
            break;
    }
    SDDF_HWA_SetChannelFIFOEnableFlag(pSddf, u8Channel, pChannelCfg->bFIFOEnable);
    if (pChannelCfg->bMainFilterEnable == true)
    {
        const SDDF_MainFilterConfigType *pMainCfg = pChannelCfg->pMainFilterConfig;
        u32ChannelDataRate                        = (SDDF_HWA_GetChannelDataRate(pSddf, u8Channel) & ~(SDDF_CDR_MFOSR_MASK | SDDF_CDR_MFORD_MASK | SDDF_CDR_MFCM_MASK)) |
                             SDDF_CDR_MFOSR(pMainCfg->u16OverSamplingRate) | SDDF_CDR_MFORD(pMainCfg->eFilterOrder) | SDDF_CDR_MFCM(pMainCfg->eConvMode);
        SDDF_HWA_SetChannelDataRate(pSddf, u8Channel, u32ChannelDataRate);
        SDDF_HWA_SetChannelMainFilterShift(pSddf, u8Channel, pMainCfg->eShift);
        SDDF_HWA_SetChannelBias(pSddf, u8Channel, pMainCfg->s32Bias);
        SDDF_HWA_SetChannelMainFilterEnableFlag(pSddf, u8Channel, true);
    }
    else
    {
        SDDF_HWA_SetChannelMainFilterEnableFlag(pSddf, u8Channel, false);
    }
    if (pChannelCfg->bAuxiliaryFilterEnable == true)
    {
        const SDDF_AuxFilterConfigType *pAuxCfg = pChannelCfg->pAuxiliaryFilterConfig;
        u32ChannelDataRate                      = (SDDF_HWA_GetChannelDataRate(pSddf, u8Channel) & ~(SDDF_CDR_AFOSR_MASK | SDDF_CDR_AFORD_MASK | SDDF_CDR_AFCM_MASK)) |
                             SDDF_CDR_AFOSR(pAuxCfg->u16OverSamplingRate) | SDDF_CDR_AFORD(pAuxCfg->eFilterOrder) | SDDF_CDR_AFCM(pAuxCfg->eConvMode);
        SDDF_HWA_SetChannelDataRate(pSddf, u8Channel, u32ChannelDataRate);
        SDDF_HWA_SetChannelAuxiliaryFilterEnableFlag(pSddf, u8Channel, true);
    }
    else
    {
        SDDF_HWA_SetChannelAuxiliaryFilterEnableFlag(pSddf, u8Channel, false);
    }
#if SDDF_DEV_ERROR_REPORT == STD_ON
    }
#endif
}

void SDDF_ChannelEnable(SDDF_HandleType *pHandle, uint8_t u8Channel)
{
#if SDDF_DEV_ERROR_REPORT == STD_ON
    if (pHandle == NULL)
    {
        SDDF_ReportDevError(SDDF_CH_ENABLE_ID, SDDF_E_PARAM_POINTER);
    }
    else if(pHandle->eInstance >= SDDF_INSTANCE_COUNT)
    {
        SDDF_ReportDevError(SDDF_CH_ENABLE_ID, SDDF_E_PARAM_INSTANCE);
    }
    else if(u8Channel >= SDDF_CH_CNT)
    {
        SDDF_ReportDevError(SDDF_CH_ENABLE_ID, SDDF_E_PARAM_CHANNEL);
    }
    else
    {
#endif
    SDDF_InstanceType eInstance =pHandle->eInstance;
    SDDF_Type *const pSddf = s_apSddfBase[eInstance];
    SDDF_HWA_SetChannelEnableFlag(pSddf, u8Channel, true);
#if SDDF_DEV_ERROR_REPORT == STD_ON
    }
#endif
}

void SDDF_ChannelDisable(SDDF_HandleType *pHandle, uint8_t u8Channel)
{
#if SDDF_DEV_ERROR_REPORT == STD_ON
    if (pHandle == NULL)
    {
        SDDF_ReportDevError(SDDF_CH_DISABLE_ID, SDDF_E_PARAM_POINTER);
    }
    else if(pHandle->eInstance >= SDDF_INSTANCE_COUNT)
    {
        SDDF_ReportDevError(SDDF_CH_DISABLE_ID, SDDF_E_PARAM_INSTANCE);
    }
    else if(u8Channel >= SDDF_CH_CNT)
    {
        SDDF_ReportDevError(SDDF_CH_DISABLE_ID, SDDF_E_PARAM_CHANNEL);
    }
    else
    {
#endif
    SDDF_InstanceType eInstance =pHandle->eInstance;
    SDDF_Type *const pSddf = s_apSddfBase[eInstance];
    SDDF_HWA_SetChannelEnableFlag(pSddf, u8Channel, false);
#if SDDF_DEV_ERROR_REPORT == STD_ON
    }
#endif
}

void SDDF_ConfigChannelInterrupt(SDDF_HandleType *pHandle, uint8_t u8Channel, const SDDF_ChannelInterruptConfigType *pIntCfg)
{
#if SDDF_DEV_ERROR_REPORT == STD_ON
    if (pHandle == NULL)
    {
        SDDF_ReportDevError(SDDF_CFG_CH_INT_ID, SDDF_E_PARAM_POINTER);
    }
    else if(pHandle->eInstance >= SDDF_INSTANCE_COUNT)
    {
        SDDF_ReportDevError(SDDF_CFG_CH_INT_ID, SDDF_E_PARAM_INSTANCE);
    }
    else if(u8Channel >= SDDF_CH_CNT)
    {
        SDDF_ReportDevError(SDDF_CFG_CH_INT_ID, SDDF_E_PARAM_CHANNEL);
    }
    else if(pIntCfg == NULL)
    {
        SDDF_ReportDevError(SDDF_CFG_CH_INT_ID, SDDF_E_PARAM_POINTER);
    }
    else
    {
#endif
    SDDF_InstanceType eInstance =pHandle->eInstance;
    SDDF_Type *const pSddf = s_apSddfBase[eInstance];
    if (pIntCfg->bConversionCompleteIntEnable == true)
    {
        SDDF_HWA_SetChannelConvCompleteIntEnableFlag(pSddf, u8Channel, true);
        pHandle->tSettings.Notifications[u8Channel].pConvCompleteNotify = pIntCfg->pConvCompleteNotify;
    }
    else
    {
        SDDF_HWA_SetChannelConvCompleteIntEnableFlag(pSddf, u8Channel, false);
        pHandle->tSettings.Notifications[u8Channel].pConvCompleteNotify = NULL;
    }
    if (pIntCfg->bFIFOReadyIntEnable == true)
    {
        SDDF_HWA_SetChannelFIFODataReadyIntEnableFlag(pSddf, u8Channel, true);
        pHandle->tSettings.Notifications[u8Channel].pFIFOReadyNotify = pIntCfg->pFIFOReadyNotify;
        s_apSddfChannelBuffer[eInstance][u8Channel]                       = pIntCfg->pResultBuffer;
    }
    else
    {
        SDDF_HWA_SetChannelFIFODataReadyIntEnableFlag(pSddf, u8Channel, true);
        pHandle->tSettings.Notifications[u8Channel].pFIFOReadyNotify = NULL;
        s_apSddfChannelBuffer[eInstance][u8Channel]                       = NULL;
    }
#if SDDF_DEV_ERROR_REPORT == STD_ON
    }
#endif
}

void SDDF_ConfigChannelDMA(SDDF_HandleType *pHandle, uint8_t u8Channel, const SDDF_ChannelDMAConfigType *pDMACfg, DMA_TransferCompleteCallbackType pDmaCallback)
{
#if SDDF_DEV_ERROR_REPORT == STD_ON
    if (pHandle == NULL)
    {
        SDDF_ReportDevError(SDDF_CFG_CH_DMA_ID, SDDF_E_PARAM_POINTER);
    }
    else if(pHandle->eInstance >= SDDF_INSTANCE_COUNT)
    {
        SDDF_ReportDevError(SDDF_CFG_CH_DMA_ID, SDDF_E_PARAM_INSTANCE);
    }
    else if(u8Channel >= SDDF_CH_CNT)
    {
        SDDF_ReportDevError(SDDF_CFG_CH_DMA_ID, SDDF_E_PARAM_CHANNEL);
    }
    else if(pDMACfg == NULL)
    {
        SDDF_ReportDevError(SDDF_CFG_CH_DMA_ID, SDDF_E_PARAM_POINTER);
    }
    else
    {
#endif
    SDDF_InstanceType eInstance =pHandle->eInstance;
    SDDF_Type *const pSddf = s_apSddfBase[eInstance];
    if (pDMACfg->bDMAEnable == true)
    {
        DMA_ChannelCfgType tDmaCfg;
        uint8_t u8FIFODepth = (uint8_t)(SDDF_HWA_GetChannelFIFOWatermark(pSddf, u8Channel) + 1U);

        s_apSddfChannelBuffer[eInstance][u8Channel]                      = pDMACfg->pResultBuffer;
        pHandle->tSettings.Notifications[u8Channel].pDMAReadyNotify = pDMACfg->pDMAReadyNotify;

        tDmaCfg.pSrcBuffer            = &pSddf->CH[u8Channel].CRDATA;
        tDmaCfg.pDestBuffer           = pDMACfg->pResultBuffer;
        tDmaCfg.u32BlockSize          = 4U * u8FIFODepth;
        tDmaCfg.u16BlockCount         = 1U;
        tDmaCfg.eSrcIncMode           = DMA_INCREMENT_DISABLE;
        tDmaCfg.eDestIncMode          = DMA_INCREMENT_DATA_SIZE;
        tDmaCfg.eSrcDataSize          = DMA_TRANSFER_SIZE_4B;
        tDmaCfg.eDestDataSize         = DMA_TRANSFER_SIZE_4B;
        tDmaCfg.u8ChannelPriority     = pDMACfg->u8ChannelPriority;
        tDmaCfg.bSrcBlockOffsetEn     = false;
        tDmaCfg.bDestBlockOffsetEn    = false;
        tDmaCfg.s32BlockOffset        = 0;
        tDmaCfg.bSrcAddrLoopbackEn    = true;
        tDmaCfg.bDestAddrLoopbackEn   = true;
        tDmaCfg.bAutoStop             = false;
        tDmaCfg.bSrcCircularBufferEn  = false;
        tDmaCfg.u32SrcCircBufferSize  = DMA_CIRCULAR_BUFFER_SIZE_1B;
        tDmaCfg.bDestCircularBufferEn = false;
        tDmaCfg.u32DestCircBufferSize = DMA_CIRCULAR_BUFFER_SIZE_1B;
        if (u8Channel == 0U)
        {
            tDmaCfg.eTriggerSrc = DMA_REQ_SDDF_CH0;
        }
        else if (u8Channel == 1U)
        {
            tDmaCfg.eTriggerSrc = DMA_REQ_SDDF_CH1;
        }
        else if (u8Channel == 2U)
        {
            tDmaCfg.eTriggerSrc = DMA_REQ_SDDF_CH2;
        }
        else if (u8Channel == 3U)
        {
            tDmaCfg.eTriggerSrc = DMA_REQ_SDDF_CH3;
        }
        else {}
        tDmaCfg.bTransferCompleteIntEn = true;
		tDmaCfg.pTransferCompleteNotify = pDmaCallback;

//		tDmaCfg.bTransferErrorIntEn[0] = false;
//		tDmaCfg.pTransferErrorNotify[0] = NULL;

        SDDF_HWA_SetChannelDMAEnableFlag(pSddf, u8Channel, true);

        DMA_InitChannel(pDMACfg->pDmahandle, &tDmaCfg);
        DMA_InitChannelInterrupt(pDMACfg->pDmahandle, &tDmaCfg);
    }
    else
    {
        SDDF_HWA_SetChannelDMAEnableFlag(pSddf, u8Channel, false);
    }
#if SDDF_DEV_ERROR_REPORT == STD_ON
    }
#endif
}

void SDDF_ConfigChannelClockAbsenceDetect(SDDF_HandleType *pHandle, uint8_t u8Channel, SDDF_ClockAbsenceDetectConfigType *pConfig)
{
#if SDDF_DEV_ERROR_REPORT == STD_ON
    if (pHandle == NULL)
    {
        SDDF_ReportDevError(SDDF_CFG_CH_CLK_ABS_DET_ID, SDDF_E_PARAM_POINTER);
    }
    else if(pHandle->eInstance >= SDDF_INSTANCE_COUNT)
    {
        SDDF_ReportDevError(SDDF_CFG_CH_CLK_ABS_DET_ID, SDDF_E_PARAM_INSTANCE);
    }
    else if(u8Channel >= SDDF_CH_CNT)
    {
        SDDF_ReportDevError(SDDF_CFG_CH_CLK_ABS_DET_ID, SDDF_E_PARAM_CHANNEL);
    }
    else if(pConfig == NULL)
    {
        SDDF_ReportDevError(SDDF_CFG_CH_CLK_ABS_DET_ID, SDDF_E_PARAM_POINTER);
    }
    else
    {
#endif
    SDDF_InstanceType eInstance =pHandle->eInstance;
    SDDF_Type *const pSddf                = s_apSddfBase[eInstance];
    uint32_t         u32ChannelProtection = (SDDF_HWA_GetChannelProtectionConfig(pSddf, u8Channel) & ~(SDDF_CPR_CADLMT_MASK | SDDF_CPR_CAD_BKEN_MASK)) |
                                    SDDF_CPR_CADLMT(pConfig->u8ClockAbsenceDetectThreshold) | SDDF_CPR_CAD_BKEN(pConfig->bClockAbsenceDetectBreakEnable);
    SDDF_HWA_SetChannelProtectionConfig(pSddf, u8Channel, u32ChannelProtection);
    if (pConfig->bClockAbsenceDetectIntEnable == true)
    {
        SDDF_HWA_SetChannelClockAbsenceIntEnableFlag(pSddf, u8Channel, true);
        pHandle->tSettings.Notifications[u8Channel].pClockAbsenceDetectNotify = pConfig->pClockAbsenceDetectNotify;
    }
    else
    {
        SDDF_HWA_SetChannelClockAbsenceIntEnableFlag(pSddf, u8Channel, false);
        pHandle->tSettings.Notifications[u8Channel].pClockAbsenceDetectNotify = NULL;
    }
    SDDF_HWA_SetChannelClockAbsenceDetectEnableFlag(pSddf, u8Channel, pConfig->bClockAbsenceDetectEnable);
#if SDDF_DEV_ERROR_REPORT == STD_ON
    }
#endif
}

void SDDF_ConfigChannelShortCircuitDetect(SDDF_HandleType *pHandle, uint8_t u8Channel, SDDF_ShortCircuitDetectConfigType *pConfig)
{
#if SDDF_DEV_ERROR_REPORT == STD_ON
    if (pHandle == NULL)
    {
        SDDF_ReportDevError(SDDF_CFG_CH_SHORT_CIR_DET_ID, SDDF_E_PARAM_POINTER);
    }
    else if(pHandle->eInstance >= SDDF_INSTANCE_COUNT)
    {
        SDDF_ReportDevError(SDDF_CFG_CH_SHORT_CIR_DET_ID, SDDF_E_PARAM_INSTANCE);
    }
    else if(u8Channel >= SDDF_CH_CNT)
    {
        SDDF_ReportDevError(SDDF_CFG_CH_SHORT_CIR_DET_ID, SDDF_E_PARAM_CHANNEL);
    }
    else if(pConfig == NULL)
    {
        SDDF_ReportDevError(SDDF_CFG_CH_SHORT_CIR_DET_ID, SDDF_E_PARAM_POINTER);
    }
    else
    {
#endif
    SDDF_InstanceType eInstance =pHandle->eInstance;
    SDDF_Type *const pSddf = s_apSddfBase[eInstance];
    uint32_t         u32ChannelProtection =
        (SDDF_HWA_GetChannelProtectionConfig(pSddf, u8Channel) & ~(SDDF_CPR_SCDOPT_MASK | SDDF_CPR_SCDCM_MASK | SDDF_CPR_SCDLMT_MASK | SDDF_CPR_SCD_BKEN_MASK)) |
        SDDF_CPR_SCDOPT(pConfig->eShortCircuitDetectOption) | SDDF_CPR_SCDCM(pConfig->eShortCircuitDetectMode) | SDDF_CPR_SCDLMT(pConfig->u8ShortCircuitDetectThreshold) |
        SDDF_CPR_SCD_BKEN(pConfig->bShortCircuitDetectBreakEnable);
    SDDF_HWA_SetChannelProtectionConfig(pSddf, u8Channel, u32ChannelProtection);
    if (pConfig->bShortCircuitDetectIntEnable == true)
    {
        SDDF_HWA_SetChannelShortCircuitDetectIntEnableFlag(pSddf, u8Channel, true);
        pHandle->tSettings.Notifications[u8Channel].pShortCircuitDetectNotify = pConfig->pShortCircuitDetectNotify;
    }
    else
    {
        SDDF_HWA_SetChannelShortCircuitDetectIntEnableFlag(pSddf, u8Channel, false);
        pHandle->tSettings.Notifications[u8Channel].pShortCircuitDetectNotify = NULL;
    }
    SDDF_HWA_SetChannelShortCircuitDetectEnableFlag(pSddf, u8Channel, pConfig->bShortCircuitDetectEnable);
#if SDDF_DEV_ERROR_REPORT == STD_ON
    }
#endif
}

void SDDF_ConfigChannelLimitCheck(SDDF_HandleType *pHandle, uint8_t u8Channel, SDDF_LimitCheckConfigType *pConfig)
{
#if SDDF_DEV_ERROR_REPORT == STD_ON
    if (pHandle == NULL)
    {
        SDDF_ReportDevError(SDDF_CFG_CH_LIM_CHK_ID, SDDF_E_PARAM_POINTER);
    }
    else if(pHandle->eInstance >= SDDF_INSTANCE_COUNT)
    {
        SDDF_ReportDevError(SDDF_CFG_CH_LIM_CHK_ID, SDDF_E_PARAM_INSTANCE);
    }
    else if(u8Channel >= SDDF_CH_CNT)
    {
        SDDF_ReportDevError(SDDF_CFG_CH_LIM_CHK_ID, SDDF_E_PARAM_CHANNEL);
    }
        else if(pConfig == NULL)
    {
        SDDF_ReportDevError(SDDF_CFG_CH_LIM_CHK_ID, SDDF_E_PARAM_POINTER);
    }
    else
    {
#endif
    SDDF_InstanceType eInstance =pHandle->eInstance;
    SDDF_Type *const pSddf = s_apSddfBase[eInstance];
    uint32_t         u32ChannelProtection =
        (SDDF_HWA_GetChannelProtectionConfig(pSddf, u8Channel) & ~(SDDF_CPR_LMTOPT_MASK | SDDF_CPR_LLMT_BKEN_MASK | SDDF_CPR_HLMT_BKEN_MASK | SDDF_CPR_WLMT_BKEN_MASK)) |
        SDDF_CPR_LMTOPT(pConfig->eLimitCheckOption) | SDDF_CPR_LLMT_BKEN(pConfig->bLowLimitBreakEnable) | SDDF_CPR_HLMT_BKEN(pConfig->bHighLimitBreakEnable) |
        SDDF_CPR_WLMT_BKEN(pConfig->bWindowLimitBreakEnable);
    SDDF_HWA_SetChannelProtectionConfig(pSddf, u8Channel, u32ChannelProtection);
    SDDF_HWA_SetChannelLimitCheckInputSrc(pSddf, u8Channel, pConfig->eLimitCheckInputSrc);
    SDDF_HWA_SetChannelLowLimit(pSddf, u8Channel, pConfig->u32LowLimit);
    SDDF_HWA_SetChannelHighLimit(pSddf, u8Channel, pConfig->u32HighLimit);
    if ((pConfig->bLowLimitIntEnable == true) || (pConfig->bHighLimitIntEnable == true) || (pConfig->bWindowLimitBreakEnable == true))
    {
        uint32_t u32AbnormalIntEn0 = (SDDF_HWA_GetAbnormalInterruptEnable0(pSddf) &
                                      ~((SDDF_ABNIER0_LLMTIE0_MASK << u8Channel) | (SDDF_ABNIER0_HLMTIE0_MASK << u8Channel) | (SDDF_ABNIER0_WLMTIE0_MASK << u8Channel))) |
                                     (SDDF_ABNIER0_LLMTIE0(pConfig->bLowLimitIntEnable) << u8Channel) | (SDDF_ABNIER0_HLMTIE0(pConfig->bHighLimitIntEnable) << u8Channel) |
                                     (SDDF_ABNIER0_WLMTIE0(pConfig->bWindowLimitIntEnable) << u8Channel);
        SDDF_HWA_SetAbnormalInterruptEnable0(pSddf, u32AbnormalIntEn0);
        pHandle->tSettings.Notifications[u8Channel].pLimitCheckNotify = pConfig->pLimitCheckNotify;
    }
    else
    {
        uint32_t u32AbnormalIntEn0 = (SDDF_HWA_GetAbnormalInterruptEnable0(pSddf) &
                                      ~((SDDF_ABNIER0_LLMTIE0_MASK << u8Channel) | (SDDF_ABNIER0_HLMTIE0_MASK << u8Channel) | (SDDF_ABNIER0_WLMTIE0_MASK << u8Channel))) |
                                     (SDDF_ABNIER0_LLMTIE0(pConfig->bLowLimitIntEnable) << u8Channel) | (SDDF_ABNIER0_HLMTIE0(pConfig->bHighLimitIntEnable) << u8Channel) |
                                     (SDDF_ABNIER0_WLMTIE0(pConfig->bWindowLimitIntEnable) << u8Channel);
        SDDF_HWA_SetAbnormalInterruptEnable0(pSddf, u32AbnormalIntEn0);
        pHandle->tSettings.Notifications[u8Channel].pLimitCheckNotify = NULL;
    }
    SDDF_HWA_SetChannelLimitCheckEnableFlag(pSddf, u8Channel, pConfig->bLimitCheckEnable);
#if SDDF_DEV_ERROR_REPORT == STD_ON
    }
#endif
}

void SDDF_ConfigChannelZeroCrossDetect(SDDF_HandleType *pHandle, uint8_t u8Channel, SDDF_ZeroCrossDetectConfigType *pConfig)
{
#if SDDF_DEV_ERROR_REPORT == STD_ON
    if (pHandle == NULL)
    {
        SDDF_ReportDevError(SDDF_CFG_CH_ZERO_CROSS_DET_ID, SDDF_E_PARAM_POINTER);
    }
    else if(pHandle->eInstance >= SDDF_INSTANCE_COUNT)
    {
        SDDF_ReportDevError(SDDF_CFG_CH_ZERO_CROSS_DET_ID, SDDF_E_PARAM_INSTANCE);
    }
    else if(u8Channel >= SDDF_CH_CNT)
    {
        SDDF_ReportDevError(SDDF_CFG_CH_ZERO_CROSS_DET_ID, SDDF_E_PARAM_CHANNEL);
    }
    else if(pConfig == NULL)
    {
        SDDF_ReportDevError(SDDF_CFG_CH_ZERO_CROSS_DET_ID, SDDF_E_PARAM_POINTER);
    }
    else
    {
#endif
    SDDF_InstanceType eInstance =pHandle->eInstance;
    SDDF_Type *const pSddf = s_apSddfBase[eInstance];
    SDDF_HWA_SetChannelZeroCrossCheckInputSrc(pSddf, u8Channel, pConfig->eZeroCrossDetectInputSrc);
    if (pConfig->bZeroCrossDetectIntEnable == true)
    {
        SDDF_HWA_SetChannelZeroCrossDetectIntEnableFlag(pSddf, u8Channel, true);
        pHandle->tSettings.Notifications[u8Channel].pZeroCrossDetectNotify = pConfig->pZeroCrossDetectNotify;
    }
    else
    {
        SDDF_HWA_SetChannelZeroCrossDetectIntEnableFlag(pSddf, u8Channel, false);
        pHandle->tSettings.Notifications[u8Channel].pZeroCrossDetectNotify = NULL;
    }
    SDDF_HWA_SetChannelZeroCrossDetectEnableFlag(pSddf, u8Channel, pConfig->bZeroCrossDetectEnable);
#if SDDF_DEV_ERROR_REPORT == STD_ON
    }
#endif
}

void SDDF_GenerateChannelSwTrigger(SDDF_HandleType *pHandle, uint8_t u8Channel)
{
#if SDDF_DEV_ERROR_REPORT == STD_ON
    if (pHandle == NULL)
    {
        SDDF_ReportDevError(SDDF_GEN_CH_SW_TRIG_ID, SDDF_E_PARAM_POINTER);
    }
    else if(pHandle->eInstance >= SDDF_INSTANCE_COUNT)
    {
        SDDF_ReportDevError(SDDF_GEN_CH_SW_TRIG_ID, SDDF_E_PARAM_INSTANCE);
    }
    else if(u8Channel >= SDDF_CH_CNT)
    {
        SDDF_ReportDevError(SDDF_GEN_CH_SW_TRIG_ID, SDDF_E_PARAM_CHANNEL);
    }
    else
    {
#endif
    SDDF_InstanceType eInstance =pHandle->eInstance;
    SDDF_Type *const pSddf = s_apSddfBase[eInstance];
    SDDF_HWA_GenerateChannelSwTrigger(pSddf, u8Channel);
#if SDDF_DEV_ERROR_REPORT == STD_ON
    }
#endif
}

uint32_t SDDF_GetChannelFIFOData(SDDF_HandleType *pHandle, uint8_t u8Channel)
{
    uint32_t ret = 0U;
#if SDDF_DEV_ERROR_REPORT == STD_ON
    if (pHandle == NULL)
    {
        SDDF_ReportDevError(SDDF_GET_CH_FIFO_DATA_ID, SDDF_E_PARAM_POINTER);
    }
    else if(pHandle->eInstance >= SDDF_INSTANCE_COUNT)
    {
        SDDF_ReportDevError(SDDF_GET_CH_FIFO_DATA_ID, SDDF_E_PARAM_INSTANCE);
    }
    else if(u8Channel >= SDDF_CH_CNT)
    {
        SDDF_ReportDevError(SDDF_GET_CH_FIFO_DATA_ID, SDDF_E_PARAM_CHANNEL);
    }
    else
    {
#endif
    SDDF_InstanceType eInstance =pHandle->eInstance;
    SDDF_Type *const pSddf = s_apSddfBase[eInstance];
    ret = SDDF_HWA_GetChannelData(pSddf, u8Channel);
#if SDDF_DEV_ERROR_REPORT == STD_ON
    }
#endif
    return ret;
}

#endif
