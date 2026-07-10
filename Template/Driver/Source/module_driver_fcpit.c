/**
 * @file module_driver_fcpit.h
 * @author Flagchip
 * @brief FCPIT driver type definition and API
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
*   0.1.0       31/12/2022    Flagchip071    N/A          First version for FC7300
*   0.2.0       4/2/2022      Flagchip071    N/A          0.2.0 release
********************************************************************************/
#include "module_driver_fcpit.h"

#if FCPIT_INSTANCE_COUNT > 0U

#ifndef FCPIT_DEV_ERROR_REPORT
#define FCPIT_DEV_ERROR_REPORT	STD_ON
#endif

#if FCPIT_DEV_ERROR_REPORT == STD_ON
#define FCPIT_ReportDevError(func, error) ReportDevError(FCPIT_MODULE_ID, func, error)
#endif



static FCPIT_Type * s_pFcpitPtrs[FCPIT_INSTANCE_COUNT] = FCPIT_BASE_PTRS;

/* global functions */
/**
 * @brief Initialize Fcpit instance common feature.
 * @param pFcpitHandle Fcpit processing handle
 * @param pInitStruct Fcpit initialization structure
 */
void FCPIT_CommonInit(FCPIT_HandleType *pFcpitHandle,const FCPIT_CommonInitType * pInitStruct)
{
	FCPIT_Type *s_pFcpitPtr = s_pFcpitPtrs[pFcpitHandle->eInstance];
	/*Enable module clock*/
	FCPIT_HWA_EnableModule(s_pFcpitPtr);
	if (pInitStruct->bDebugEn)
	{
		FCPIT_HWA_SetChannelRunOnDebug(s_pFcpitPtr);
	}
	else
	{
		FCPIT_HWA_SetChannelStopOnDebug(s_pFcpitPtr);
	}

	if (pInitStruct->bLowPowerModeEn)
	{
		FCPIT_HWA_SetChannelRunOnLpm(s_pFcpitPtr);
	}
	else
	{
		FCPIT_HWA_SetChannelStopOnLpm(s_pFcpitPtr);
	}
	/*Send info to global handler*/
	pFcpitHandle->bDebugEn = pInitStruct->bDebugEn;
	pFcpitHandle->bLowPowerModeEn = pInitStruct->bLowPowerModeEn;
}


/* global functions */
/**
 * @brief Initialize Fcpit instance.
 * @param pFcpitHandle Fcpit processing handle
 * @param pInitStruct Fcpit initialization structure
 */
void FCPIT_ChannelInit(FCPIT_HandleType *pFcpitHandle,const FCPIT_ChannelInitType * pInitStruct)
{
#if FCPIT_DEV_ERROR_REPORT == STD_ON
	if ((uint32_t)pInitStruct->eFcpitChannel >= FCPIT_CHANNEL_MAX)
	{
		FCPIT_ReportDevError(FCPIT_CHANNEL_INIT_ID, FCPIT_E_PARAM_CHANNEL);
	}
	else
	{
#endif
		FCPIT_Type *s_pFcpitPtr = s_pFcpitPtrs[pFcpitHandle->eInstance];
		/*Enable module clock*/
		FCPIT_HWA_EnableModule(s_pFcpitPtr);

		/* w1c , clear channel interrupt flag*/
        FCPIT_HWA_ClearChannelsInterruptFlag(s_pFcpitPtr,(uint32_t)1U << (uint32_t)pInitStruct->eFcpitChannel);

        FCPIT_HWA_ConfigChannel(s_pFcpitPtr,pInitStruct->eFcpitChannel, (uint32_t)0U);

        /*config mode*/
        FCPIT_HWA_ConfigChannelMode(s_pFcpitPtr,pInitStruct->eFcpitChannel, pInitStruct->eMode);

        if ((pInitStruct->eFcpitChannel > FCPIT_CHANNEL_0) && (pInitStruct->bChainModeEn))
        {
            FCPIT_HWA_EnableChannelChainMode(s_pFcpitPtr,pInitStruct->eFcpitChannel);
        }
        /*config value*/
        FCPIT_HWA_SetChannelValue(s_pFcpitPtr,pInitStruct->eFcpitChannel, pInitStruct->u32TimerValue);

        /*Send info to global handler*/
        pFcpitHandle->tChannelStatus[(uint8_t)pInitStruct->eFcpitChannel].bChainModeEn = pInitStruct->bChainModeEn;
        pFcpitHandle->tChannelStatus[(uint8_t)pInitStruct->eFcpitChannel].eMode = pInitStruct->eMode;
        pFcpitHandle->tChannelStatus[(uint8_t)pInitStruct->eFcpitChannel].u32TimerValue = pInitStruct->u32TimerValue;

#if FCPIT_DEV_ERROR_REPORT == STD_ON
	}
#endif
}

/**
 * @brief Initialize Fcpit trigger configuration
 * @param pFcpitHandle Fcpit processing handle
 * @param pTrgStruct Fcpit trigger structure
 */
void FCPIT_InitTrigger(FCPIT_HandleType *pFcpitHandle,const FCPIT_TrggerType * pTrgStruct)
{
	FCPIT_Type *s_pFcpitPtr = s_pFcpitPtrs[pFcpitHandle->eInstance];
#if FCPIT_DEV_ERROR_REPORT == STD_ON
	if (NULL == pTrgStruct)
	{
		FCPIT_ReportDevError(FCPIT_INIT_TRIGGER_ID, FCPIT_E_PARAM_POINTER);
	}
	else if((uint32_t)0U == FCPIT_HWA_ReadModuleEnable(s_pFcpitPtr))
	{
		FCPIT_ReportDevError(FCPIT_INIT_TRIGGER_ID, FCPIT_STATUS_FUNCTION_ERROR);
	}
	else
	{
#endif

        if (pTrgStruct->bStartOnTrigger)
        {
            FCPIT_HWA_SetChannelStartOnTrig(s_pFcpitPtr,pTrgStruct->eFcpitChannel);
        }
        else
        {
            FCPIT_HWA_ClearChannelStartOnTrig(s_pFcpitPtr,pTrgStruct->eFcpitChannel);
        }

        if (pTrgStruct->bStopOnInterrupt)
        {
            FCPIT_HWA_SetChannelStopOnInterrupt(s_pFcpitPtr,pTrgStruct->eFcpitChannel);
        }
        else
        {
            FCPIT_HWA_ClearChannelStopOnInterrupt(s_pFcpitPtr,pTrgStruct->eFcpitChannel);
        }

        if (pTrgStruct->bReloadOnTrigger)
        {
            FCPIT_HWA_SetChannelReloadOnTrig(s_pFcpitPtr,pTrgStruct->eFcpitChannel);
        }
        else
        {
            FCPIT_HWA_ClearChannelReloadOnTrig(s_pFcpitPtr,pTrgStruct->eFcpitChannel);
        }

        if (FCPIT_TRIGGER_EXTERNAL != pTrgStruct->eTriggerSel)
        {
            FCPIT_HWA_SetChannelTriggerSrc(s_pFcpitPtr,pTrgStruct->eFcpitChannel);
            FCPIT_HWA_SelectChannelTrigger(s_pFcpitPtr,pTrgStruct->eFcpitChannel, pTrgStruct->eTriggerSel);
        }
        else
        {
            FCPIT_HWA_ClearChannelTriggerSrc(s_pFcpitPtr,pTrgStruct->eFcpitChannel);
            FCPIT_HWA_SelectChannelTrigger(s_pFcpitPtr,pTrgStruct->eFcpitChannel, pTrgStruct->eFcpitChannel);
        }
        /*Send info to global handler*/
        pFcpitHandle->tChannelStatus[(uint8_t)pTrgStruct->eFcpitChannel].bStartOnTrigger = pTrgStruct->bStartOnTrigger;
        pFcpitHandle->tChannelStatus[(uint8_t)pTrgStruct->eFcpitChannel].bStopOnInterrupt = pTrgStruct->bStopOnInterrupt;
        pFcpitHandle->tChannelStatus[(uint8_t)pTrgStruct->eFcpitChannel].bReloadOnTrigger = pTrgStruct->bReloadOnTrigger;
        pFcpitHandle->tChannelStatus[(uint8_t)pTrgStruct->eFcpitChannel].eTriggerSel = pTrgStruct->eTriggerSel;


#if FCPIT_DEV_ERROR_REPORT == STD_ON
	}
#endif
}

/**
 * @brief De-initialize Fcpit instance.
 * @param pFcpitHandle Fcpit processing handle
 */
void FCPIT_Deinit(FCPIT_HandleType *pFcpitHandle)
{
	FCPIT_Type *s_pFcpitPtr = s_pFcpitPtrs[pFcpitHandle->eInstance];
    uint8_t u8Index;
    FCPIT_HWA_ConfigModule(s_pFcpitPtr,(uint32_t)FCPIT_MCR_M_CEN_MASK);
    /*clear flag*/
    FCPIT_HWA_ClearChannelsInterruptFlag(s_pFcpitPtr,(uint32_t)(FCPIT_MSR_TIF3_MASK | FCPIT_MSR_TIF2_MASK | FCPIT_MSR_TIF1_MASK |
                                                    FCPIT_MSR_TIF0_MASK));
    /*clear enable bit*/
    FCPIT_HWA_DisableChannelsInterrupt(s_pFcpitPtr,(uint32_t)0xFU);

    /*clear channel bit*/
    for (u8Index = 0U; u8Index < MAX_FCPIT_CHANNEL_NUM; u8Index++)
    {
        FCPIT_HWA_ConfigChannel(s_pFcpitPtr,(FCPIT_ChannelType)u8Index, (uint32_t)0U);
        FCPIT_HWA_SetChannelValue(s_pFcpitPtr,(FCPIT_ChannelType)u8Index, (uint32_t)0U);
        /*clear info to global handler*/
        pFcpitHandle->tChannelStatus[u8Index].eMode = FCPIT_CHANNEL_NOMODE;
		pFcpitHandle->tChannelStatus[u8Index].bChainModeEn= false;
		pFcpitHandle->tChannelStatus[u8Index].u32TimerValue = 0u;
		pFcpitHandle->tChannelStatus[u8Index].bStartOnTrigger = false;
		pFcpitHandle->tChannelStatus[u8Index].bStopOnInterrupt = false;
		pFcpitHandle->tChannelStatus[u8Index].bReloadOnTrigger = false;
		pFcpitHandle->tChannelStatus[u8Index].eTriggerSel = FCPIT_NO_TRIGGER;
		pFcpitHandle->tChannelStatus[u8Index].bChannelIsrEn = false;
		pFcpitHandle->tChannelStatus[u8Index].pChannelCallback = NULL;
		pFcpitHandle->tChannelStatus[u8Index].bChannelStarted = false;
    }
    FCPIT_HWA_ConfigModule(s_pFcpitPtr,(uint32_t)0U);
    pFcpitHandle->bDebugEn = false;
    pFcpitHandle->bLowPowerModeEn = false;

}

/**
 * @brief Initialize Fcpit interrupt functionality
 * @param pFcpitHandle Fcpit processing handle
 * @param pIntStruct Fcpit interrupt structure
 * @note this function will stop timer
 */
void FCPIT_InitInterrupt(FCPIT_HandleType *pFcpitHandle,const FCPIT_IntType * pIntStruct)
{
	FCPIT_Type *s_pFcpitPtr = s_pFcpitPtrs[pFcpitHandle->eInstance];
#if FCPIT_DEV_ERROR_REPORT == STD_ON
	if (NULL == pIntStruct)
	{
		FCPIT_ReportDevError(FCPIT_INIT_INTERRUPT_ID, FCPIT_E_PARAM_POINTER);
	}
	else if((uint32_t)0U == FCPIT_HWA_ReadModuleEnable(s_pFcpitPtr))
	{
		FCPIT_ReportDevError(FCPIT_INIT_INTERRUPT_ID, FCPIT_STATUS_FUNCTION_ERROR);
	}
	else
	{
#endif
        FCPIT_HWA_DisableChannel(s_pFcpitPtr,pIntStruct->eFcpitChannel);
        /* w1c , clear channel interrupt flag*/
        FCPIT_HWA_ClearChannelsInterruptFlag(s_pFcpitPtr,(uint32_t)1U << (uint32_t)pIntStruct->eFcpitChannel);
        if (pIntStruct->bChannelIsrEn)
        {
            FCPIT_HWA_EnableChannelsInterrupt(s_pFcpitPtr,(uint32_t)1U << (uint32_t)pIntStruct->eFcpitChannel);
            pFcpitHandle->tChannelStatus[pIntStruct->eFcpitChannel].pChannelCallback = pIntStruct->pChannelCallback;
        }
        else
        {
            FCPIT_HWA_DisableChannelsInterrupt(s_pFcpitPtr,(uint32_t)1U << (uint32_t)pIntStruct->eFcpitChannel);
            pFcpitHandle->tChannelStatus[pIntStruct->eFcpitChannel].pChannelCallback = NULL;
        }
        pFcpitHandle->tChannelStatus[pIntStruct->eFcpitChannel].bChannelIsrEn = pIntStruct->bChannelIsrEn;

#if FCPIT_DEV_ERROR_REPORT == STD_ON
	}
#endif
}

/**
 * @brief Enable Fcpit interrupt
 * @param pFcpitHandle Fcpit processing handle
 * @param eChannel Fcpit channel
 */
void FCPIT_EnableInterrupt(FCPIT_HandleType *pFcpitHandle,const FCPIT_ChannelType eChannel)
{
	FCPIT_Type *s_pFcpitPtr = s_pFcpitPtrs[pFcpitHandle->eInstance];
#if FCPIT_DEV_ERROR_REPORT == STD_ON
	if (FCPIT_CHANNEL_MAX <= eChannel)
	{
		FCPIT_ReportDevError(FCPIT_ENABLE_INTERRUPT_ID, FCPIT_E_PARAM_CHANNEL);
	}
	else if((uint32_t)0U == FCPIT_HWA_ReadModuleEnable(s_pFcpitPtr))
	{
		FCPIT_ReportDevError(FCPIT_ENABLE_INTERRUPT_ID, FCPIT_STATUS_FUNCTION_ERROR);
	}
	else
	{
#endif
        FCPIT_HWA_DisableChannel(s_pFcpitPtr,eChannel);
        /* w1c , clear channel interrupt flag*/
        FCPIT_HWA_ClearChannelsInterruptFlag(s_pFcpitPtr,(uint32_t)1U << (uint32_t)eChannel);
        FCPIT_HWA_EnableChannelsInterrupt(s_pFcpitPtr,(uint32_t)1U << (uint32_t)eChannel);
        FCPIT_HWA_EnableChannel(s_pFcpitPtr,eChannel);
        pFcpitHandle->tChannelStatus[(uint8_t)eChannel].bChannelIsrEn = true;

#if FCPIT_DEV_ERROR_REPORT == STD_ON
	}
#endif
}

/**
 * @brief Disable Fcpit interrupt
 * @param pFcpitHandle Fcpit processing handle
 * @param eChannel Fcpit channel
 */
void FCPIT_DisableInterrupt(FCPIT_HandleType *pFcpitHandle,const FCPIT_ChannelType eChannel)
{
	FCPIT_Type *s_pFcpitPtr = s_pFcpitPtrs[pFcpitHandle->eInstance];
#if FCPIT_DEV_ERROR_REPORT == STD_ON
	if (FCPIT_CHANNEL_MAX <= eChannel)
	{
		FCPIT_ReportDevError(FCPIT_DISABLE_INTERRUPT_ID, FCPIT_E_PARAM_CHANNEL);
	}
	else if((uint32_t)0U == FCPIT_HWA_ReadModuleEnable(s_pFcpitPtr))
	{
		FCPIT_ReportDevError(FCPIT_DISABLE_INTERRUPT_ID, FCPIT_STATUS_FUNCTION_ERROR);
	}
	else
	{
#endif
		FCPIT_HWA_DisableChannel(s_pFcpitPtr,eChannel);
        /* w1c , clear channel interrupt flag*/
        FCPIT_HWA_ClearChannelsInterruptFlag(s_pFcpitPtr,(uint32_t)1U << (uint32_t)eChannel);
        FCPIT_HWA_DisableChannelsInterrupt(s_pFcpitPtr,(uint32_t)1U << (uint32_t)eChannel);
        FCPIT_HWA_EnableChannel(s_pFcpitPtr,eChannel);

        pFcpitHandle->tChannelStatus[(uint8_t)eChannel].bChannelIsrEn = false;
#if FCPIT_DEV_ERROR_REPORT == STD_ON
	}
#endif
}

/**
 * @brief Fcpit start timer
 * @param pFcpitHandle Fcpit processing handle
 * @param eChannel Fcpit channel
 */
void FCPIT_Start(FCPIT_HandleType *pFcpitHandle,const FCPIT_ChannelType eChannel)
{
	FCPIT_Type *s_pFcpitPtr = s_pFcpitPtrs[pFcpitHandle->eInstance];
#if FCPIT_DEV_ERROR_REPORT == STD_ON
	if (FCPIT_CHANNEL_MAX <= eChannel)
	{
		FCPIT_ReportDevError(FCPIT_START_ID, FCPIT_E_PARAM_CHANNEL);
	}
	else if((uint32_t)0U == FCPIT_HWA_ReadModuleEnable(s_pFcpitPtr))
	{
		FCPIT_ReportDevError(FCPIT_START_ID, FCPIT_STATUS_FUNCTION_ERROR);
	}
	else
	{
#endif
		FCPIT_HWA_EnableChannel(s_pFcpitPtr,eChannel);
         pFcpitHandle->tChannelStatus[(uint8_t)eChannel].bChannelStarted = true;
#if FCPIT_DEV_ERROR_REPORT == STD_ON
	}
#endif
}

/**
 * @brief Fcpit stop
 * @param pFcpitHandle Fcpit processing handle
 * @param eChannel Fcpit channel
 */
void FCPIT_Stop(FCPIT_HandleType *pFcpitHandle,const FCPIT_ChannelType eChannel)
{
	FCPIT_Type *s_pFcpitPtr = s_pFcpitPtrs[pFcpitHandle->eInstance];
#if FCPIT_DEV_ERROR_REPORT == STD_ON
	if (FCPIT_CHANNEL_MAX <= eChannel)
	{
		FCPIT_ReportDevError(FCPIT_STOP_ID, FCPIT_E_PARAM_CHANNEL);
	}
	else if((uint32_t)0U == FCPIT_HWA_ReadModuleEnable(s_pFcpitPtr))
	{
		FCPIT_ReportDevError(FCPIT_STOP_ID, FCPIT_STATUS_FUNCTION_ERROR);
	}
	else
	{
#endif
		FCPIT_HWA_DisableChannel(s_pFcpitPtr,eChannel);
		pFcpitHandle->tChannelStatus[(uint8_t)eChannel].bChannelStarted = false;
#if FCPIT_DEV_ERROR_REPORT == STD_ON
	}
#endif
}

/**
 * @brief Immediately update Fcpit channel value
* @param pFcpitHandle Fcpit processing handle
 * @param eChannel Fcpit channel
 * @param u32ChannelValue in/Out value
 */
void FCPIT_ImmediateUpdateChannelValue(FCPIT_HandleType *pFcpitHandle,const FCPIT_ChannelType eChannel, const uint32_t u32ChannelValue)
{
	FCPIT_Type *s_pFcpitPtr = s_pFcpitPtrs[pFcpitHandle->eInstance];
#if FCPIT_DEV_ERROR_REPORT == STD_ON
	if (FCPIT_CHANNEL_MAX <= eChannel)
	{
		FCPIT_ReportDevError(FCPIT_STOP_ID, FCPIT_E_PARAM_CHANNEL);
	}
	else if((uint32_t)0U == FCPIT_HWA_ReadModuleEnable(s_pFcpitPtr))
	{
		FCPIT_ReportDevError(FCPIT_STOP_ID, FCPIT_STATUS_FUNCTION_ERROR);
	}
	else
	{
#endif
		FCPIT_HWA_DisableChannel(s_pFcpitPtr,eChannel);
        FCPIT_HWA_SetChannelValue(s_pFcpitPtr,eChannel, u32ChannelValue);
        FCPIT_HWA_EnableChannel(s_pFcpitPtr,eChannel);
    	pFcpitHandle->tChannelStatus[(uint8_t)eChannel].u32TimerValue = u32ChannelValue;
#if FCPIT_DEV_ERROR_REPORT == STD_ON
	}
#endif
}

/**
 * @brief Update Fcpit channel value
* @param pFcpitHandle Fcpit processing handle
 * @param eChannel Fcpit channel
 * @param u32ChannelValue in/Out value
 */
void FCPIT_UpdateChannelValue(FCPIT_HandleType *pFcpitHandle,const FCPIT_ChannelType eChannel, const uint32_t u32ChannelValue)
{
	FCPIT_Type *s_pFcpitPtr = s_pFcpitPtrs[pFcpitHandle->eInstance];
#if FCPIT_DEV_ERROR_REPORT == STD_ON
	if (FCPIT_CHANNEL_MAX <= eChannel)
	{
		FCPIT_ReportDevError(FCPIT_STOP_ID, FCPIT_E_PARAM_CHANNEL);
	}
	else if((uint32_t)0U == FCPIT_HWA_ReadModuleEnable(s_pFcpitPtr))
	{
		FCPIT_ReportDevError(FCPIT_STOP_ID, FCPIT_STATUS_FUNCTION_ERROR);
	}
	else
	{
#endif

		FCPIT_HWA_SetChannelValue(s_pFcpitPtr,eChannel, u32ChannelValue);
        pFcpitHandle->tChannelStatus[(uint8_t)eChannel].u32TimerValue = u32ChannelValue;
#if FCPIT_DEV_ERROR_REPORT == STD_ON
	}
#endif
}



/**
 * @brief fcpit interrupt function.
* @param pFcpitHandle Fcpit processing handle
 */
void FCPITn_IRQHandler(FCPIT_HandleType *pFcpitHandle)
{
	FCPIT_Type *s_pFcpitPtr = s_pFcpitPtrs[pFcpitHandle->eInstance];
    uint32_t u32TifValue = FCPIT_HWA_ReadEnableInterruptFlag(s_pFcpitPtr) & FCPIT_HWA_ReadInterruptFlag(s_pFcpitPtr);

    if (u32TifValue & FCPIT_MSR_TIF0_MASK)
    {
    	if(pFcpitHandle->tChannelStatus[0].pChannelCallback != NULL)
    	{
    		pFcpitHandle->tChannelStatus[0].pChannelCallback(pFcpitHandle,0U);
    	}
        FCPIT_HWA_ClearChannelsInterruptFlag(s_pFcpitPtr,(uint32_t)FCPIT_MSR_TIF0_MASK);
    }
    if (u32TifValue & FCPIT_MSR_TIF1_MASK)
    {
    	if(pFcpitHandle->tChannelStatus[1].pChannelCallback != NULL)
		{
			pFcpitHandle->tChannelStatus[1].pChannelCallback(pFcpitHandle,1U);
		}
        FCPIT_HWA_ClearChannelsInterruptFlag(s_pFcpitPtr,(uint32_t)FCPIT_MSR_TIF1_MASK);
    }
    if (u32TifValue & FCPIT_MSR_TIF2_MASK)
    {
    	if(pFcpitHandle->tChannelStatus[2].pChannelCallback != NULL)
		{
			pFcpitHandle->tChannelStatus[2].pChannelCallback(pFcpitHandle,2U);
		}
        FCPIT_HWA_ClearChannelsInterruptFlag(s_pFcpitPtr,(uint32_t)FCPIT_MSR_TIF2_MASK);
    }
    if (u32TifValue & FCPIT_MSR_TIF3_MASK)
    {
    	if(pFcpitHandle->tChannelStatus[3].pChannelCallback != NULL)
		{
			pFcpitHandle->tChannelStatus[3].pChannelCallback(pFcpitHandle,3U);
		}
        FCPIT_HWA_ClearChannelsInterruptFlag(s_pFcpitPtr,(uint32_t)FCPIT_MSR_TIF3_MASK);
    }

}


#endif /* #if FCPIT_INSTANCE_COUNT > 0U */

