/**
 * @file module_driver_tmu.c
 * @author Flagchip
 * @brief TMU driver source code
 * @version 2.0.0
 * @date 2024-08-20
 *
 * SDK Version: 2.6.0
 *

 * @copyright Copyright (c) 2020-2024 Flagchip Semiconductors Co., Ltd.
 *
 * @details
 */
/*********************************************************************************
*   Revision History:
*
*   Version     Date          Initials      CR#          Descriptions
*   ---------   ----------    ------------  ----------   ---------------
*   0.1.0       2022-12-30    Flagchip074   N/A          First version for FC7xxx
*   0.2.0       2023-02-15    Flagchip074    N/A          FC7xxx release version
******************************************************************************** */

#include "module_driver_tmu.h"

#if TMU_INSTANCE_COUNT > 0U
#if TMU_SUPPORT_TV_ECMP
#include "module_driver_adc.h"
#endif
#include "module_driver_pcc.h"

#ifndef TMU_DEV_ERROR_REPORT
#define TMU_DEV_ERROR_REPORT    STD_OFF
#endif

#if TMU_DEV_ERROR_REPORT == STD_ON
#define TMU_ReportDevError(func, error) ReportDevError(TMU_MODULE_ID, func, error)
#endif


/********* Local Variables ************/
/** @brief TMU peripheral base pointers */
static TMU_Type *const s_apTmuBase[TMU_INSTANCE_COUNT] = TMU_BASE_PTRS;
#if TMU_SUPPORT_TV_ECMP
static ADC_Type *const s_apTmuAdcUsedBase[ADC_INSTANCE_COUNT] = ADC_BASE_PTRS;
#endif
/**
 * @brief TMU interrupt process
 *
 */
void TMU_ProcessIRQHandler(TMU_HandleType* pTmuHandle)
{
    TMU_Type *const pTmu = s_apTmuBase[pTmuHandle->eIntance];
#if TMU_SUPPORT_TV_ECMP
    ADC_Type *const pAdc = s_apTmuAdcUsedBase[pTmuHandle->u8AdcIntanceUsed];
    if (TMU_HWA_GetVoltageTemperatureCompare1InterruptEnableStatus(pTmu) == true)
    {
        if (TMU_HWA_GetVoltageTemperatureCompareFlag1(pTmu) == true)
        {
        	ADC_HWA_ClearECMPHighFlag(pAdc, ADC_ECMP1);
        	ADC_HWA_ClearECMPLowFlag(pAdc, ADC_ECMP1);
        	ADC_HWA_ClearECMPWinFlag(pAdc, ADC_ECMP1);
        	TMU_HWA_ClearVoltageTemperatureCompareFlag1(pTmu);
            if (pTmuHandle->tSettings.TMU_TempCompareFlag1InterruptCallback != NULL)
            {
                pTmuHandle->tSettings.TMU_TempCompareFlag1InterruptCallback(pTmuHandle);
            }
        }
    }
    if (TMU_HWA_GetVoltageTemperatureCompare0InterruptEnableStatus(pTmu) == true)
    {
        if (TMU_HWA_GetVoltageTemperatureCompareFlag0(pTmu) == true)
        {
        	ADC_HWA_ClearECMPHighFlag(pAdc, ADC_ECMP0);
        	ADC_HWA_ClearECMPLowFlag(pAdc, ADC_ECMP0);
        	ADC_HWA_ClearECMPWinFlag(pAdc, ADC_ECMP0);
        	TMU_HWA_ClearVoltageTemperatureCompareFlag0(pTmu);
            if (pTmuHandle->tSettings.TMU_TempCompareFlag0InterruptCallback != NULL)
            {
                pTmuHandle->tSettings.TMU_TempCompareFlag0InterruptCallback(pTmuHandle);
            }
        }
    }
#else
    if (TMU_HWA_GetFlagTemperature150InterruptFlag(pTmu) == true)
    {
        if (TMU_HWA_Get150Flag(pTmu) == true)
        {
            if (pTmuHandle->tSettings.TMU_TempOver150InterruptCallback != NULL)
            {
                pTmuHandle->tSettings.TMU_TempOver150InterruptCallback(pTmuHandle);
            }
            TMU_HWA_Clear150Flag(pTmu);
        }
    }
    if (TMU_HWA_GetFlagTemperature125InterruptFlag(pTmu) == true)
    {
        if (TMU_HWA_Get125Flag(pTmu) == true)
        {
            if (pTmuHandle->tSettings.TMU_TempOver125InterruptCallback != NULL)
            {
                pTmuHandle->tSettings.TMU_TempOver125InterruptCallback(pTmuHandle);
            }
            TMU_HWA_Clear125Flag(pTmu);
        }
    }
    if (TMU_HWA_GetFlagTemperatureReadyInterruptFlag(pTmu) == true)
    {
        if (TMU_HWA_GetFlagTemperatureReady(pTmu) == true)
        {
            if (pTmuHandle->tSettings.TMU_TempFlagReadyInterruptCallback != NULL)
            {
                pTmuHandle->tSettings.TMU_TempFlagReadyInterruptCallback(pTmuHandle);
            }
            TMU_HWA_SetTemperatureLockStatus(pTmu, TMU_TF_TV_UNLOCK);

            TMU_HWA_ClearFlagTemperatureReady(pTmu);
            TMU_HWA_SetTemperatureLockStatus(pTmu, TMU_TF_TV_LOCK);
        }
    }
    if (TMU_HWA_GetVoltageTemperatureReadyInterruptFlag(pTmu) == true)
    {
        if (TMU_HWA_GetVoltageTemperatureReady(pTmu) == true)
        {
            if (pTmuHandle->tSettings.TMU_TempVoltageReadyInterruptCallback != NULL)
            {
                pTmuHandle->tSettings.TMU_TempVoltageReadyInterruptCallback(pTmuHandle);
            }
            TMU_HWA_SetTemperatureLockStatus(pTmu, TMU_TF_TV_UNLOCK);

            TMU_HWA_ClearVoltageTemperatureReady(pTmu);
            TMU_HWA_SetTemperatureLockStatus(pTmu, TMU_TF_TV_LOCK);
        }
    }
#endif
}

/**
 * @brief Initialize the TMU instance
 *
 * @param pTmuHandle: TMU processing handle
 * @param pInitCfg: the configurations of the TMU instance
 */
void TMU_Init(TMU_HandleType* pTmuHandle, const TMU_InitType *const pInitCfg)
{
#if TMU_DEV_ERROR_REPORT == STD_ON
    if((pTmuHandle == NULL) || (pInitCfg == NULL))
    {
        TMU_ReportDevError(TMU_INIT_ID, TMU_E_PARAM_POINTER);
    }
    else if(pTmuHandle->eIntance >= TMU_INSTANCE_MAX)
    {
        TMU_ReportDevError(TMU_INIT_ID, TMU_E_PARAM_INSTANCE);
    }
    else
    {
#endif
        TMU_Type *const pTmu = s_apTmuBase[pTmuHandle->eIntance];
#if !TMU_SUPPORT_TV_ECMP
        uint32_t u32FlagCtrl;
        uint32_t u32VoltageCtrl;
        uint8_t u8FlagStartupCnt;
        uint8_t u8VoltageStartupCnt;

        PCC_ClkSrcType eAdcClkName = PCC_CLK_TMU0;
        uint32_t u32TmuClk;
        u32TmuClk = PCC_GetPccFunctionClock(eAdcClkName);

        u8FlagStartupCnt = (uint8_t)((u32TmuClk * 11U) / 127000000U + 1U);
        u8VoltageStartupCnt = (uint8_t)((u32TmuClk * 5U) / 127000000U + 1U);
        if (u8FlagStartupCnt > 15U)
        {
            u8FlagStartupCnt = 15U;
        }
        if (u8VoltageStartupCnt > 7U)
        {
            u8VoltageStartupCnt = 7U;
        }

        pTmuHandle->tStatus.bTemperatureOver125IntEn = pInitCfg->bTemperatureOver125IntEn;
        pTmuHandle->tStatus.bTemperatureOver150IntEn = pInitCfg->bTemperatureOver150IntEn;
        pTmuHandle->tStatus.bFlagTempReadyIntEn = pInitCfg->bFlagTempReadyIntEn;
        pTmuHandle->tStatus.bVoltageTempReadyIntEn = pInitCfg->bVoltageTempReadyIntEn;

        u32FlagCtrl = TMU_TF_CTRL_TF_HYSOFF(pInitCfg->eFlagTempHysteresisCon) |
                      TMU_TF_CTRL_TF_START_CNT(u8FlagStartupCnt) |
#ifdef TMU_SUPPORT_STOP
                      TMU_TF_CTRL_TF_STOP_EN(pInitCfg->bFlagTempStopModeEn) |
#endif
                      TMU_TF_CTRL_TF_FILT_BYP(pInitCfg->eFlagTempFilterBypassCon);
        TMU_HWA_SetFlagTempCtrl(pTmu, u32FlagCtrl);

        u32VoltageCtrl = TMU_TV_CTRL_TV_START_CNT(u8VoltageStartupCnt);
#else
        uint32_t u32VoltageCtrl = 0U;
        pTmuHandle->tStatus.bVoltageTempCompareFlag1IntEn = pInitCfg->bVoltageTempCompareFlag1IntEn;
        pTmuHandle->tStatus.bVoltageTempCompareFlag0IntEn = pInitCfg->bVoltageTempCompareFlag0IntEn;
#endif
#ifdef TMU_SUPPORT_STOP
        u32VoltageCtrl |= TMU_TV_CTRL_TV_STOP_EN(pInitCfg->bVoltageTempStopModeEn);
#endif

        TMU_HWA_SetVoltageTempCtrl(pTmu, u32VoltageCtrl);

        TMU_HWA_SetTemperatureLockStatus(pTmu, TMU_TF_TV_LOCK);
#if TMU_DEV_ERROR_REPORT == STD_ON
    }
#endif
}

#if !TMU_SUPPORT_TV_ECMP
/**
 * @brief Enable the Flag-based temperature sensor
 *
 * @param pTmuHandle: TMU processing handle
 * @return TMU_StatusType TMU_STATUS_SUCCESS when enable successfully, others fail
 */
TMU_StatusType TMU_FlagTempEnable(TMU_HandleType* pTmuHandle)
{
    TMU_StatusType eRet = TMU_STATUS_ERROR;
#if TMU_DEV_ERROR_REPORT == STD_ON
    if(pTmuHandle->eIntance >= TMU_INSTANCE_MAX)
    {
        TMU_ReportDevError(TMU_INIT_ID, TMU_E_PARAM_INSTANCE);
    }
    else
    {
#endif
        uint32_t u32TimeOut = 15000000U;
        TMU_Type *const pTmu = s_apTmuBase[pTmuHandle->eIntance];

        TMU_HWA_SetTemperatureLockStatus(pTmu, TMU_TF_TV_UNLOCK);
        TMU_HWA_SetFlagTemperature150InterruptFlag(pTmu, pTmuHandle->tStatus.bTemperatureOver150IntEn);
        TMU_HWA_SetFlagTemperature125InterruptFlag(pTmu, pTmuHandle->tStatus.bTemperatureOver125IntEn);
        TMU_HWA_SetFlagTemperatureEnableStatus(pTmu, true);
        while ((TMU_HWA_GetFlagTemperatureReady(pTmu) != true) && (u32TimeOut != 0U))
        {
            u32TimeOut--;
        }
        if (u32TimeOut != 0U)
        {
            TMU_HWA_SetFlagTemperatureReadyInterruptFlag(pTmu, pTmuHandle->tStatus.bFlagTempReadyIntEn);
            eRet = TMU_STATUS_SUCCESS;
        }
        else
        {
            eRet = TMU_STATUS_TIMEOUT;
        }
        TMU_HWA_SetTemperatureLockStatus(pTmu, TMU_TF_TV_LOCK);
#if TMU_DEV_ERROR_REPORT == STD_ON
    }
#endif
    return eRet;
}

/**
 * @brief Disable the Flag-based temperature sensor
 *
 * @param pTmuHandle: TMU processing handle
 * @return TMU_StatusType TMU_STATUS_SUCCESS when disable successfully, others fail
 */
TMU_StatusType TMU_FlagTempDisable(TMU_HandleType* pTmuHandle)
{
    TMU_StatusType eRet = TMU_STATUS_ERROR;
#if TMU_DEV_ERROR_REPORT == STD_ON
    if(pTmuHandle->eIntance >= TMU_INSTANCE_MAX)
    {
        TMU_ReportDevError(TMU_INIT_ID, TMU_E_PARAM_INSTANCE);
    }
    else
    {
#endif
        uint32_t u32TimeOut = 15000000U;
        TMU_Type *const pTmu = s_apTmuBase[pTmuHandle->eIntance];

        TMU_HWA_SetTemperatureLockStatus(pTmu, TMU_TF_TV_UNLOCK);
        /* Before clearing the flag-enable bit, the bit TF_RDYF_IE, TF_150F_IE, and TF_125F_IE must be cleared first. */
        TMU_HWA_SetFlagTemperature150InterruptFlag(pTmu, false);
        TMU_HWA_SetFlagTemperature125InterruptFlag(pTmu, false);
        TMU_HWA_SetFlagTemperatureReadyInterruptFlag(pTmu, false);
        TMU_HWA_SetFlagTemperatureEnableStatus(pTmu, false);
        TMU_HWA_ClearFlagTemperatureReady(pTmu);
        while ((TMU_HWA_GetFlagTemperatureEnableStatus(pTmu) == true) && (u32TimeOut != 0U))
        {
            u32TimeOut--;
        }
        if (u32TimeOut != 0U)
        {
            eRet = TMU_STATUS_SUCCESS;
        }
        else
        {
            eRet = TMU_STATUS_TIMEOUT;
        }
        TMU_HWA_SetTemperatureLockStatus(pTmu, TMU_TF_TV_LOCK);
#if TMU_DEV_ERROR_REPORT == STD_ON
    }
#endif
    return eRet;
}
#endif

/**
 * @brief Enable the Voltage-based temperature sensor
 *
 * @param pTmuHandle: TMU processing handle
 * @return TMU_StatusType TMU_STATUS_SUCCESS when enable successfully, others fail
 */
TMU_StatusType TMU_VoltageTempEnable(TMU_HandleType* pTmuHandle)
{
    TMU_StatusType eRet = TMU_STATUS_ERROR;
#if TMU_DEV_ERROR_REPORT == STD_ON
    if(pTmuHandle->eIntance >= TMU_INSTANCE_MAX)
    {
        TMU_ReportDevError(TMU_INIT_ID, TMU_E_PARAM_INSTANCE);
    }
    else
    {
#endif
        uint32_t u32TimeOut = 15000000U;
        TMU_Type *const pTmu = s_apTmuBase[pTmuHandle->eIntance];

        TMU_HWA_SetTemperatureLockStatus(pTmu, TMU_TF_TV_UNLOCK);
        TMU_HWA_SetVoltageTemperatureEnableStatus(pTmu, true);
        while ((TMU_HWA_GetVoltageTemperatureReady(pTmu) != true) && (u32TimeOut != 0U))
        {
            u32TimeOut--;
        }
        if (u32TimeOut != 0U)
        {
#if !TMU_SUPPORT_TV_ECMP
            TMU_HWA_SetVoltageTemperatureReadyInterruptFlag(pTmu, pTmuHandle->tStatus.bVoltageTempReadyIntEn);
#endif
            eRet = TMU_STATUS_SUCCESS;
        }
        else
        {
            eRet = TMU_STATUS_TIMEOUT;
        }
        TMU_HWA_SetTemperatureLockStatus(pTmu, TMU_TF_TV_LOCK);
#if TMU_DEV_ERROR_REPORT == STD_ON
    }
#endif
    return eRet;
}

/**
 * @brief Disable the Voltage-based temperature sensor
 *
 * @param pTmuHandle: TMU processing handle
 * @return TMU_StatusType TMU_STATUS_SUCCESS when disable successfully, others fail
 */
TMU_StatusType TMU_VoltageTempDisable(TMU_HandleType* pTmuHandle)
{
    TMU_StatusType eRet = TMU_STATUS_ERROR;
#if TMU_DEV_ERROR_REPORT == STD_ON
    if(pTmuHandle->eIntance >= TMU_INSTANCE_MAX)
    {
        TMU_ReportDevError(TMU_INIT_ID, TMU_E_PARAM_INSTANCE);
    }
    else
    {
#endif
        uint32_t u32TimeOut = 15000000U;
        TMU_Type *const pTmu = s_apTmuBase[pTmuHandle->eIntance];

        TMU_HWA_SetTemperatureLockStatus(pTmu, TMU_TF_TV_UNLOCK);
#if !TMU_SUPPORT_TV_ECMP
        /* Before clearing the Voltage-enable bit, the bit TV_RDYF_IE must be cleared first. */
        TMU_HWA_SetVoltageTemperatureReadyInterruptFlag(pTmu, false);
#endif
        TMU_HWA_SetVoltageTemperatureEnableStatus(pTmu, false);
#if !TMU_SUPPORT_TV_ECMP
        TMU_HWA_ClearVoltageTemperatureReady(pTmu);
#endif
        while ((TMU_HWA_GetVoltageTemperatureEnableStatus(pTmu) == true) && (u32TimeOut != 0U))
        {
            u32TimeOut--;
        }
        if (u32TimeOut != 0U)
        {
            eRet = TMU_STATUS_SUCCESS;
        }
        else
        {
            eRet = TMU_STATUS_TIMEOUT;
        }
        TMU_HWA_SetTemperatureLockStatus(pTmu, TMU_TF_TV_LOCK);
#if TMU_DEV_ERROR_REPORT == STD_ON
    }
#endif
    return eRet;
}

#if !TMU_SUPPORT_TV_ECMP
/**
 * @brief Check if cleaning flag is required
 *
 * @param pTmuHandle: TMU processing handle
 */
void TMU_TempOverClear(TMU_HandleType* pTmuHandle)
{
#if TMU_DEV_ERROR_REPORT == STD_ON
    if(pTmuHandle->eIntance >= TMU_INSTANCE_MAX)
    {
        TMU_ReportDevError(TMU_INIT_ID, TMU_E_PARAM_INSTANCE);
    }
    else
    {
#endif
    TMU_Type *const pTmu = s_apTmuBase[pTmuHandle->eIntance];
    if (TMU_HWA_Get150Flag(pTmu))
    {
        if (!TMU_HWA_Get150Status(pTmu))
        {
            TMU_HWA_Clear150Flag(pTmu);
        }
    }
    if (TMU_HWA_Get125Flag(pTmu))
    {
        if (!TMU_HWA_Get125Status(pTmu))
        {
            TMU_HWA_Clear125Flag(pTmu);
        }
    }
#if TMU_DEV_ERROR_REPORT == STD_ON
    }
#endif
}
#endif

#ifdef TMU_SUPPORT_STOP
#if !TMU_SUPPORT_TV_ECMP
/**
 * @brief Set the Flag-based temperature sensor is enabled/disabled in stop mode
 *
 *@param pTmuHandle: TMU processing handle
 * @param bEnable: whether Flag-based temperature sensor is enabled in stop mode if TF_EN is active.
 */
void TMU_FlagTempSetStopMode(TMU_HandleType* pTmuHandle, bool bEnable)
{
#if TMU_DEV_ERROR_REPORT == STD_ON
    if(pTmuHandle->eIntance >= TMU_INSTANCE_MAX)
    {
        TMU_ReportDevError(TMU_INIT_ID, TMU_E_PARAM_INSTANCE);
    }
    else
    {
#endif
        TMU_Type *const pTmu = s_apTmuBase[pTmuHandle->eIntance];
        TMU_HWA_ConfigFlagTemperatureStopMode(pTmu, bEnable);
#if TMU_DEV_ERROR_REPORT == STD_ON
    }
#endif
}
#endif

/**
 * @brief Set the Voltage-based temperature sensor is enabled/disabled in stop mode
 *
 *@param pTmuHandle: TMU processing handle
 * @param bEnable: whether Voltage-based temperature sensor is enabled in stop mode if TV_EN is active.
 */
void TMU_VoltageTempSetStopMode(TMU_HandleType* pTmuHandle, bool bEnable)
{
#if TMU_DEV_ERROR_REPORT == STD_ON
    if(pTmuHandle->eIntance >= TMU_INSTANCE_MAX)
    {
        TMU_ReportDevError(TMU_INIT_ID, TMU_E_PARAM_INSTANCE);
    }
    else
    {
#endif
        TMU_Type *const pTmu = s_apTmuBase[pTmuHandle->eIntance];
        TMU_HWA_ConfigVoltageTemperatureStopMode(pTmu, bEnable);
#if TMU_DEV_ERROR_REPORT == STD_ON
    }
#endif
}
#endif

#ifdef TMU_SUPPORT_TRIM
/**
 * @brief Get the temperature code from ADC
 *
 * @param pTmuHandle: TMU processing handle
 * @return uint32_t the value records the ADC conversion results for voltage-based temperature sensor result in 135 Celsius
 */
uint32_t TMU_GetTcode(TMU_HandleType* pTmuHandle)
{
#if TMU_DEV_ERROR_REPORT == STD_ON
    if(pTmuHandle->eIntance >= TMU_INSTANCE_MAX)
    {
        TMU_ReportDevError(TMU_INIT_ID, TMU_E_PARAM_INSTANCE);
        return 0U;
    }
    else
    {
#endif
        TMU_Type *const pTmu = s_apTmuBase[pTmuHandle->eIntance];
        return TMU_HWA_GetTemperatureCode(pTmu);
#if TMU_DEV_ERROR_REPORT == STD_ON
    }
#endif

}

/**
 * @brief Get the slope factor
 *
 * @param pTmuHandle: TMU processing handle
 * @return uint32_t the value records the slope factor for voltage-based temperature sensor
 */
uint32_t TMU_GetTslope(TMU_HandleType* pTmuHandle)
{
#if TMU_DEV_ERROR_REPORT == STD_ON
    if(pTmuHandle->eIntance >= TMU_INSTANCE_MAX)
    {
        TMU_ReportDevError(TMU_INIT_ID, TMU_E_PARAM_INSTANCE);
        return 0U;
    }
    else
    {
#endif
        TMU_Type *const pTmu = s_apTmuBase[pTmuHandle->eIntance];
        return TMU_HWA_GetSlopeFactor(pTmu);
#if TMU_DEV_ERROR_REPORT == STD_ON
    }
#endif
}
#endif
#endif /* #if TMU_INSTANCE_COUNT > 0U */
