/**
 * @file module_driver_aontimer.c
 * @author Flagchip
 * @brief aontimer driver type definition and API
 * @version 2.0.0
 * @date 2024-08-20
 *
 * SDK Version: 2.6.0
 *

 * @copyright Copyright (c) 2020-2024 Flagchip Semiconductors Co., Ltd.
 *
 * @details
 */
/********************************************************************************
*   Revision History:
*
*   Version     Date          Initials       CR#          Descriptions
*   ---------   ----------    ------------   ----------   ---------------
*   0.2.0       2023-2-7     Flagchip076    N/A          First version for FC7300
*   2.0.0       2024-8-22    Flagchip120    N/A          SDK_2.0
********************************************************************************/
#include "module_driver_aontimer.h"
#include "module_driver_csc.h"

#if AONTIMER_INSTANCE_COUNT > 0U

#ifndef AONTIMER_DEV_ERROR_REPORT
#define AONTIMER_DEV_ERROR_REPORT	STD_OFF
#endif

#if AONTIMER_DEV_ERROR_REPORT == STD_ON
#define AONTIMER_ReportDevError(func, error) ReportDevError(AONTIMER_MODULE_ID, func, error)
#endif

/********* Local variable ************/
static AONTIMER_Type * const s_pAontimerBasePtrs[AONTIMER_INSTANCE_COUNT] = AONTIMER_BASE_PTRS;


/**
 * @brief Initialize aontimer instance
 *
 * @param pAontimerHandle the Aontimer instance to use
 * @param pInitStruct Aontimer Initialize structure
 */
void AONTIMER_Init(AONTIMER_HandleType* pAontimerHandle, const AONTIMER_InitType *const pInitStruct)
{
	AONTIMER_Type * const pAontimer = s_pAontimerBasePtrs[pAontimerHandle->eInstance];
#if AONTIMER_DEV_ERROR_REPORT == STD_ON
    uint32_t u32ClockFreq = 0U;
    bool bCSC0ClockValid = CSC0_GetCSC0ClockFreq(CSC0_AON_CLK, &u32ClockFreq);

    if ((uint32_t)pAontimerHandle->eInstance >= AONTIMER_INSTANCE_COUNT)
    {
        AONTIMER_ReportDevError(AONTIMER_INIT_ID, AONTIMER_E_PARAM_INSTANCE);
    }
    else if (NULL == pInitStruct)
    {
        AONTIMER_ReportDevError(AONTIMER_INIT_ID, AONTIMER_E_PARAM_POINTER);
    }
    else if (CSC_E_NOT_OK == bCSC0ClockValid)
    {
        AONTIMER_ReportDevError(AONTIMER_INIT_ID, AONTIMER_E_PARAM_CLOCK);
    }
    else if (0U == u32ClockFreq)
    {
        AONTIMER_ReportDevError(AONTIMER_INIT_ID, AONTIMER_E_PARAM_CLOCK);
    }
    else
    {
#endif
        /* Disable the Aontimer, and clear control register. */
        AONTIMER_HWA_ConfigModule(pAontimer, (uint32_t)0U);
        AONTIMER_HWA_ConfigModulePrescale(pAontimer, (uint32_t)0U);
#if AONTIMER_DEBUG_MODE_SUPPORT
        AONTIMER->CSR |= AONTIMER_CSR_DBGEN(pInitStruct->eDbgMode);
#endif
        if (AONTIMER_PULSE_MODE == pInitStruct->eMode)
        {
            AONTIMER_HWA_SelectClkSrcOnPulseMode(pAontimer, pInitStruct->ePulseClkSrc);
            AONTIMER_HWA_ConfigModulePolarity(pAontimer, pInitStruct->ePulsePol);
            AONTIMER_HWA_EnablePulseMode(pAontimer);
            AONTIMER_HWA_SetPrescale(pAontimer, pInitStruct->u8PulseFilterWidth);
        }
        else
        {
            AONTIMER_HWA_SetPrescale(pAontimer, pInitStruct->u8Prescaler);
        }
        if (pInitStruct->bBypassEn)
        {
            AONTIMER_HWA_EnableBypassMode(pAontimer);
        }
        else
        {
            AONTIMER_HWA_DisableBypassMode(pAontimer);
        }
        AONTIMER_HWA_SetModuleRunOnDebug(pAontimer);
        AONTIMER_HWA_SelectModuleClkSrc(pAontimer, pInitStruct->eClkSrc);
        AONTIMER_HWA_SetModuleCompareValue(pAontimer, (uint32_t)pInitStruct->u16StartValue);
        AONTIMER_HWA_DisableTimer(pAontimer);
        if (pInitStruct->bIntEn)
        {
            AONTIMER_HWA_EnableModuleInterrupt(pAontimer);
            pAontimerHandle->tSettings.pAontimerCallback = pInitStruct->pAontimerCallback;
        }
        else
        {
            AONTIMER_HWA_DisableModuleInterrupt(pAontimer);
            pAontimerHandle->tSettings.pAontimerCallback = NULL;
        }

#if AONTIMER_DEV_ERROR_REPORT == STD_ON        
    }
#endif
}

/**
 * @brief De-initialize aontimer instance
 *
 * @param pAontimerHandle the Aontimer instance to use
 */
void AONTIMER_Deinit(AONTIMER_HandleType* pAontimerHandle)
{
	AONTIMER_Type * const pAontimer = s_pAontimerBasePtrs[pAontimerHandle->eInstance];
#if AONTIMER_DEV_ERROR_REPORT == STD_ON
    if ((uint32_t)pAontimerHandle->eInstance >= AONTIMER_INSTANCE_COUNT)
    {
        AONTIMER_ReportDevError(AONTIMER_INIT_ID, AONTIMER_E_PARAM_INSTANCE);
    }
    else
    {
#endif
        AONTIMER_HWA_ConfigModule(pAontimer, (uint32_t)0U);
        AONTIMER_HWA_ConfigModulePrescale(pAontimer, (uint32_t)0U);
        AONTIMER_HWA_SetModuleCompareValue(pAontimer, (uint32_t)0xFFFFFFFFU);
        pAontimerHandle->tSettings.pAontimerCallback = NULL;
        __NVIC_DisableIRQ(AONTIMER0_IRQn);
#if AONTIMER_DEV_ERROR_REPORT == STD_ON        
    }
#endif
}

/**
 * @brief Start Aontimer
 *
 * @param pAontimerHandle the Aontimer instance to use
 */
void AONTIMER_StartTimer(AONTIMER_HandleType* pAontimerHandle)
{
	AONTIMER_Type * const pAontimer = s_pAontimerBasePtrs[pAontimerHandle->eInstance];
#if AONTIMER_DEV_ERROR_REPORT == STD_ON
    if ((uint32_t)pAontimerHandle->eInstance >= AONTIMER_INSTANCE_COUNT)
    {
        AONTIMER_ReportDevError(AONTIMER_INIT_ID, AONTIMER_E_PARAM_INSTANCE);
    }
    else
    {
#endif
        AONTIMER_HWA_EnableTimer(pAontimer);
#if AONTIMER_DEV_ERROR_REPORT == STD_ON        
    }
#endif
}

/**
 * @brief Stop Aontimer
 *
 * @param pAontimerHandle the Aontimer instance to use
 */
void AONTIMER_StopTimer(AONTIMER_HandleType* pAontimerHandle)
{
	AONTIMER_Type * const pAontimer = s_pAontimerBasePtrs[pAontimerHandle->eInstance];
#if AONTIMER_DEV_ERROR_REPORT == STD_ON
    if ((uint32_t)pAontimerHandle->eInstance >= AONTIMER_INSTANCE_COUNT)
    {
        AONTIMER_ReportDevError(AONTIMER_INIT_ID, AONTIMER_E_PARAM_INSTANCE);
    }
    else
    {
#endif
        AONTIMER_HWA_DisableTimer(pAontimer);
#if AONTIMER_DEV_ERROR_REPORT == STD_ON        
    }
#endif
}

/**
 * @brief Update value of aontimer counter
 *
 * @param pAontimerHandle the Aontimer instance to use
 * @param u16StartValue input value, range : 0~65535
 */
void AONTIMER_UpdateCounterValue(AONTIMER_HandleType* pAontimerHandle, const uint16_t u16StartValue)
{
	AONTIMER_Type * const pAontimer = s_pAontimerBasePtrs[pAontimerHandle->eInstance];
#if AONTIMER_DEV_ERROR_REPORT == STD_ON
    if ((uint32_t)pAontimerHandle->eInstance >= AONTIMER_INSTANCE_COUNT)
    {
        AONTIMER_ReportDevError(AONTIMER_INIT_ID, AONTIMER_E_PARAM_INSTANCE);
    }
    else
    {
#endif
        if (0U == (AONTIMER->CSR & AONTIMER_CSR_TMS_MASK))
        {
            AONTIMER_HWA_DisableTimer(pAontimer);
            AONTIMER_HWA_SetModuleCompareValue(pAontimer, (uint32_t)u16StartValue);
            AONTIMER_HWA_EnableTimer(pAontimer);
        }
#if AONTIMER_DEV_ERROR_REPORT == STD_ON        
    }
#endif
}

/**
 * @brief Aontimer common interrupt handle function
 *
 * @param pAontimerHandle the Aontimer instance to use
 */
void Aontimer_CommonProcessInterrupt(AONTIMER_HandleType* pAontimerHandle)
{
	AONTIMER_Type * const pAontimer = s_pAontimerBasePtrs[pAontimerHandle->eInstance];
#if AONTIMER_DEV_ERROR_REPORT == STD_ON
    if ((uint32_t)pAontimerHandle->eInstance >= AONTIMER_INSTANCE_COUNT)
    {
        AONTIMER_ReportDevError(AONTIMER_INIT_ID, AONTIMER_E_PARAM_INSTANCE);
    }
    else
    {
#endif
        AONTIMER_HWA_DisableTimer(pAontimer);
        if (NULL != pAontimerHandle->tSettings.pAontimerCallback)
        {
            pAontimerHandle->tSettings.pAontimerCallback(pAontimerHandle);
        }
        AONTIMER_HWA_EnableTimer(pAontimer);
#if AONTIMER_DEV_ERROR_REPORT == STD_ON        
    }
#endif
}

#endif


