/**
 * @file module_driver_eftu_dtm.c
 * @author flagchip
 * @brief EFTU_DTM driver source code
 * @version 2.0.0
 * @date 2024-11-07
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
   *   0.1.0       2024-11-07    Flagchip070   N/A          First version for FC7300
   *   2.6.0	   2026-01-23    Flagchip070   N/A          Fix phase shift channel POL issue
   ******************************************************************************** */

#include "module_driver_eftu_tom.h"

#if defined(EFTU_INSTANCE_COUNT) && (EFTU_INSTANCE_COUNT > 0)
#ifndef EFTU_TOM_DEV_ERROR_REPORT
#define EFTU_TOM_DEV_ERROR_REPORT	STD_OFF
#endif

#if EFTU_TOM_DEV_ERROR_REPORT == STD_ON
#define EftuTom_ReportDevError(func, error) ReportDevError(EFTU_TOM_MODULE_ID, func, error)
#endif

#define EFTU_TOM_CHANNEL(h)						(h)->tStatus.pTOM, (h)->tStatus.u8HwChannel

#define EFTU_TOM_CONFIG_CLOCK(h, c)				(h)->pCmuHandle->tStatus.fCmuClock[(h->eEftuInstance)][(c)->eClockSource]
#define EFTU_TOM_CONFIG_CLOCK_COUNT(h, c, t)	((uint32_t)((t) * EFTU_TOM_CONFIG_CLOCK(h, c) + 0.5f))
#define EFTU_TOM_HANDLE_CLOCK_COUNT(h, t)		((uint32_t)((t) * (h)->tStatus.fClock + 0.5f))

/******* Local Function Prototype *********/
static void EFTU_TOM_InitHwChannelStatus(EFTU_Tom_ChannelHandleType *pHandle);
#if EFTU_TOM_DEV_ERROR_REPORT == STD_ON
static bool EFTU_TOM_VerifyHandle(EFTU_Tom_ChannelHandleType *pHandle, uint32_t u32FuncId);
static bool EFTU_TOM_VerifyHandleWithMode(EFTU_Tom_ChannelHandleType *pHandle, uint32_t u32FuncId, EFTU_Tom_ModeType eMode);
static bool EFTU_TOM_CheckInited(EFTU_Tom_ChannelHandleType *pHandle, uint32_t u32FuncId);

/********* Local Functions ************/
/**
 * @brief Verify the validity of an EFTU_Tom channel handle.
 * 
 * @param pHandle Pointer to the EFTU_Tom channel handle.
 * @param u32FuncId The function ID of the higher-level function calling this validation function.
 * @return bool Returns TRUE if the handle is valid, otherwise returns FALSE.
 */
static bool EFTU_TOM_VerifyHandle(EFTU_Tom_ChannelHandleType *pHandle, uint32_t u32FuncId)
{
	bool bValid = TRUE;
    /* Check if the EFTU instance exceeds the maximum value */
	if (((uint32_t)pHandle->eEftuInstance) >= (uint32_t)EFTU_INSTANCE_COUNT)
	{
		EftuTom_ReportDevError(u32FuncId, EFTU_TOM_E_PARAM_INSTANCE);
		bValid = FALSE;
	}
    /* Check if the channel number is out of range */
	else if (pHandle->u8Channel >= (EFTU_TOM_CHANNEL_COUNT * 2U))
	{
		EftuTom_ReportDevError(u32FuncId, EFTU_TOM_E_PARAM_CHANNEL);
		bValid = FALSE;
	}

	return bValid;
}

/**
 * @brief Check if the EFTU_Tom channel has been initialized.
 * 
 * @param pHandle Pointer to the EFTU_Tom channel handle.
 * @param u32FuncId The function ID of the higher-level function calling this validation function.
 * @return bool Returns TRUE if the channel is initialized, otherwise returns FALSE.
 */
static bool EFTU_TOM_CheckInited(EFTU_Tom_ChannelHandleType *pHandle, uint32_t u32FuncId)
{
	bool bValid = FALSE;
	uint32_t u32Loop;
    /* Iterate through all EFTU instances to check if the channel is initialized */
	for (u32Loop = 0; u32Loop < EFTU_INSTANCE_COUNT; u32Loop++)
	{
		if (	((uint32_t)pHandle->tStatus.pTOM == (g_aEftuBaseAddress[u32Loop] + EFTU_TOM0_BASE))
			|| 	((uint32_t)pHandle->tStatus.pTOM == (g_aEftuBaseAddress[u32Loop] + EFTU_TOM1_BASE)))
		{
			bValid = TRUE;
			break;
		}
	}
    /* Log an error if the channel is not initialized */
	if (FALSE == bValid)
	{
		EftuTom_ReportDevError(u32FuncId, EFTU_TOM_E_UNINITED);
	}
	return bValid;
}


/**
 * @brief Verify the EFTU_Tom channel handle and mode.
 * 
 * @param pHandle Pointer to the EFTU_Tom channel handle.
 * @param u32FuncId The function ID of the higher-level function calling this validation function.
 * @param eMode The expected channel mode.
 * @return bool Returns TRUE if the handle is valid and the mode matches, otherwise returns FALSE.
 */
static bool EFTU_TOM_VerifyHandleWithMode(EFTU_Tom_ChannelHandleType *pHandle, uint32_t u32FuncId, EFTU_Tom_ModeType eMode)
{
	bool bValid = EFTU_TOM_VerifyHandle(pHandle, u32FuncId);
    /* If the handle is valid, further check if it is initialized */
	if (TRUE == bValid)
	{
		bValid = EFTU_TOM_CheckInited(pHandle, u32FuncId);

        /* Check if the channel mode matches the expected mode */
		if((TRUE == bValid) && pHandle->tStatus.eMode != eMode)
		{
			EftuTom_ReportDevError(u32FuncId, EFTU_TOM_E_CHANNEL_MODE);
			bValid = FALSE;
		}
	}
	return bValid;
}

#endif

/**
 * @brief Initialize hardware channel status
 *
 * @param pHandle Pointer to the channel handle, containing channel-related information
 */
static void EFTU_TOM_InitHwChannelStatus(EFTU_Tom_ChannelHandleType *pHandle)
{
    /**
     * Check if the channel number is within the range of the first TOM module
     */
    if (pHandle->u8Channel < EFTU_TOM_CHANNEL_COUNT)
    {
        /**
         * Set the base address of TOM module 0
         */
        pHandle->tStatus.pTOM = (EFTU_TOM_Type * )(g_aEftuBaseAddress[pHandle->eEftuInstance] + EFTU_TOM0_BASE);

        /**
         * Set the hardware channel number
         */
        pHandle->tStatus.u8HwChannel = pHandle->u8Channel;
    }
    else
    {
        /**
         * If the channel number is not within the range of the first TOM module,
         * set the base address of TOM module 1
         */
        pHandle->tStatus.pTOM = (EFTU_TOM_Type * )(g_aEftuBaseAddress[pHandle->eEftuInstance] + EFTU_TOM1_BASE);

        /**
         * Calculate and set the hardware channel number by subtracting the number of channels in the first TOM module
         */
        pHandle->tStatus.u8HwChannel = (uint8_t)(pHandle->u8Channel - EFTU_TOM_CHANNEL_COUNT);
    }
}

/**
 * @brief Initialize the EFTU Timer Channel
 *
 * @param pHandle Pointer to the timer channel handle, used to operate a specific timer channel
 * @param pConfig Pointer to the timer configuration structure, containing the configuration information for the timer
 */
void EFTU_TOM_InitTimerChannel(EFTU_Tom_ChannelHandleType *pHandle, EFTU_Tom_TimerConfigType *pConfig)
{
    /** In case the development error reporting feature is enabled, validate the handle */
#if EFTU_TOM_DEV_ERROR_REPORT == STD_ON
    bool bValid = EFTU_TOM_VerifyHandle(pHandle, EFTU_TOM_TIMER_INIT_ID);

    if (TRUE == bValid)
    {
        /** Check if the configured clock source is out of valid range */
        if (((uint32_t)pConfig->eClockSource) > (uint32_t)EFTU_TOM_CLK_SRC_CMU_CLK_7)
        {
            EftuTom_ReportDevError(EFTU_TOM_TIMER_INIT_ID, EFTU_TOM_E_CLOCK_SRC_INVALID);
        }
        /** Check if the configured timer count exceeds hardware limitations */
        else if ((EFTU_TOM_CONFIG_CLOCK_COUNT(pHandle, pConfig, pConfig->fTimeout)) > 0xFFFFFF)
        {
            EftuTom_ReportDevError(EFTU_TOM_TIMER_INIT_ID, EFTU_TOM_E_TIME_INVALID);
        }
        else
        {
#endif
            /** Initialize the hardware channel status */
            EFTU_TOM_InitHwChannelStatus(pHandle);

            /** Set the channel mode to timer mode */
            pHandle->tStatus.eMode = EFTU_TOM_MODE_TIMER;
            /** Set the CCU0 callback function */
            pHandle->tStatus.tCallback.pCcu0 = pConfig->pTimeoutCallback;
            /** Set the CCU1 callback function to NULL as it is not used in timer mode */
            pHandle->tStatus.tCallback.pCcu1 = NULL;
            /** Calculate and set the timer clock */
            pHandle->tStatus.fClock = EFTU_TOM_CONFIG_CLOCK(pHandle, pConfig);

            /** Set the hardware channel mode to PWM mode */
            EFTU_TOM_HWA_SetChannelMode(EFTU_TOM_CHANNEL(pHandle), EFTU_TOM_CHANNEL_MODE_PWM);
            /** Set the hardware channel clock source */
			EFTU_TOM_HWA_SetShadowClockSource(EFTU_TOM_CHANNEL(pHandle), (uint8_t)pConfig->eClockSource);
            /** Set the shadow register 0 value for timer counting */
            EFTU_TOM_HWA_SetShadowValue0(EFTU_TOM_CHANNEL(pHandle), (uint32_t)(pConfig->fTimeout * pHandle->tStatus.fClock + 0.5f));

            /** Enable the CCU0 interrupt */
            EFTU_TOM_HWA_EnableCCU0Interrupt(EFTU_TOM_CHANNEL(pHandle));

            /** Enable force update, set host trigger request, then disable force update */
            EFTU_TOM_HWA_EnableForceUpdate(EFTU_TOM_CHANNEL(pHandle));
            EFTU_TOM_HWA_SetHostTriggerRequest(pHandle->tStatus.pTOM);
            EFTU_TOM_HWA_DisableForceUpdate(EFTU_TOM_CHANNEL(pHandle));
#if EFTU_TOM_DEV_ERROR_REPORT == STD_ON
        }
    }
#endif
}

/**
 * @brief Start the timer channel.
 *
 * @param pHandle Pointer to the timer channel handle.
 */
void EFTU_TOM_StartTimerChannel(EFTU_Tom_ChannelHandleType *pHandle)
{
    /**
     * When device error reporting is enabled, verify the handle.
     */
#if EFTU_TOM_DEV_ERROR_REPORT == STD_ON
    if (TRUE == EFTU_TOM_VerifyHandleWithMode(pHandle, EFTU_TOM_START_TIMER_CHANNEL_ID, EFTU_TOM_MODE_TIMER))
    {
#endif
        /**
         * Enable the channel's update trigger functionality.
         */
        EFTU_TOM_HWA_EnableChannelOnUpdateTrig(EFTU_TOM_CHANNEL(pHandle));

        /**
         * Enable the timer channel.
         */
        EFTU_TOM_HWA_EnableChannel(EFTU_TOM_CHANNEL(pHandle));
#if EFTU_TOM_DEV_ERROR_REPORT == STD_ON
    }
#endif
}

/**
 * @brief Stops the timer channel.
 *
 * @param pHandle Pointer to the channel handle, used to identify and control a specific timer channel.
 */
void EFTU_TOM_StopTimerChannel(EFTU_Tom_ChannelHandleType *pHandle)
{
#if EFTU_TOM_DEV_ERROR_REPORT == STD_ON
    /**
     * Verify the handle if device error reporting is enabled.
     */
    if (TRUE == EFTU_TOM_VerifyHandleWithMode(pHandle, EFTU_TOM_STOP_TIMER_CHANNEL_ID, EFTU_TOM_MODE_TIMER))
    {
#endif
        /**
         * Disable the channel's update trigger to prevent it from being triggered during the stop process.
         */
        EFTU_TOM_HWA_DisableChannelOnUpdateTrig(EFTU_TOM_CHANNEL(pHandle));
        
        /**
         * Completely disable the channel to stop its operation.
         */
        EFTU_TOM_HWA_DisableChannel(EFTU_TOM_CHANNEL(pHandle));
#if EFTU_TOM_DEV_ERROR_REPORT == STD_ON
    }
#endif
}

/**
 * Function to initialize the PWM channel with the given configuration.
 *
 * @param pHandle Pointer to the EFTU TOM handle structure.
 * @param pConfig Pointer to the EFTU TOM configuration structure.
 * @return None
 */
void EFTU_TOM_InitPwmChannel(EFTU_Tom_ChannelHandleType *pHandle, EFTU_Tom_PwmConfigType *pConfig)
{
#if EFTU_TOM_DEV_ERROR_REPORT == STD_ON
	bool bValid = EFTU_TOM_VerifyHandle(pHandle, EFTU_TOM_PWM_INIT_ID);

	if (TRUE == bValid)
	{
		if (((uint32_t)pConfig->eClockSource) > (uint32_t)EFTU_TOM_CLK_SRC_CMU_CLK_7)
		{
			EftuTom_ReportDevError(EFTU_TOM_PWM_INIT_ID, EFTU_TOM_E_CLOCK_SRC_INVALID);
			bValid = FALSE;
		}
		else if ((TRUE == pConfig->bPhaseShiftEnable) && (TRUE == pConfig->bUpDownMode))
		{
			EftuTom_ReportDevError(EFTU_TOM_PWM_INIT_ID, EFTU_TOM_E_PARAM_INVALID);
			bValid = FALSE;
		}
#if defined(HRPWM_INSTANCE_COUNT) && (HRPWM_INSTANCE_COUNT > 0U)
		else if (	(TRUE == pConfig->bHrpwmSupport)
				&& 	(
							(pHandle->eEftuInstance != EFTU_INSTANCE_0)
						|| 	(pHandle->u8Channel >= 8U)
						||	(	fabsf(pHandle->pCmuHandle->fBusClock
									- EFTU_TOM_CONFIG_CLOCK(pHandle, pConfig))
								> 1.0f)
					)
				)
		{
				EftuTom_ReportDevError(EFTU_TOM_PWM_INIT_ID, EFTU_TOM_E_PARAM_INVALID);
				bValid = FALSE;
		}
#endif
		else if (FALSE == pConfig->bPhaseShiftEnable)
		{
			if (pConfig->fDuty > pConfig->fPeriod)
			{
				EftuTom_ReportDevError(EFTU_TOM_PWM_INIT_ID, EFTU_TOM_E_TIME_INVALID);
                bValid = FALSE;
			}
			else if (FALSE == pConfig->bUpDownMode)
			{
#if defined(HRPWM_INSTANCE_COUNT) && (HRPWM_INSTANCE_COUNT > 0U)
				if (FALSE == pConfig->bHrpwmSupport)
				{
#endif
					if (	(EFTU_TOM_CONFIG_CLOCK_COUNT(pHandle, pConfig, pConfig->fDuty) > 0xFFFFFF)
						||	(EFTU_TOM_CONFIG_CLOCK_COUNT(pHandle, pConfig, pConfig->fPeriod) > 0xFFFFFF))
					{
						EftuTom_ReportDevError(EFTU_TOM_PWM_INIT_ID, EFTU_TOM_E_TIME_INVALID);
						bValid = FALSE;
					}
#if defined(HRPWM_INSTANCE_COUNT) && (HRPWM_INSTANCE_COUNT > 0U)
				}
				else
				{
					if (	(EFTU_TOM_CONFIG_CLOCK_COUNT(pHandle, pConfig, pConfig->fDuty * 32.0f) > 0xFFFFFF)
						||	(EFTU_TOM_CONFIG_CLOCK_COUNT(pHandle, pConfig, pConfig->fPeriod * 32.0f) > 0xFFFFFF))
					{
						EftuTom_ReportDevError(EFTU_TOM_PWM_INIT_ID, EFTU_TOM_E_TIME_INVALID);
						bValid = FALSE;
					}
				}
#endif
			}
			else /* (TRUE == pConfig->bUpDownMode) */
			{
#if defined(HRPWM_INSTANCE_COUNT) && (HRPWM_INSTANCE_COUNT > 0U)
                /** Check for non-phase shift mode and validate PWM parameters */
				if (FALSE == pConfig->bHrpwmSupport)
				{
#endif
                    /** Validate ordinary PWM duty and period */
					if (	((EFTU_TOM_CONFIG_CLOCK_COUNT(pHandle, pConfig, pConfig->fDuty) >> 1U) > 0xFFFFFF)
						||	((EFTU_TOM_CONFIG_CLOCK_COUNT(pHandle, pConfig, pConfig->fPeriod - pConfig->fDuty) >> 1U) > 0xFFFFFF))
					{
						EftuTom_ReportDevError(EFTU_TOM_PWM_INIT_ID, EFTU_TOM_E_TIME_INVALID);
						bValid = FALSE;
					}
#if defined(HRPWM_INSTANCE_COUNT) && (HRPWM_INSTANCE_COUNT > 0U)
				}
				else
				{
                    /** Validate high-resolution PWM duty and period */
					if (	((EFTU_TOM_CONFIG_CLOCK_COUNT(pHandle, pConfig, pConfig->fDuty * 32.0f) >> 1U) > 0xFFFFFF)
						||	((EFTU_TOM_CONFIG_CLOCK_COUNT(pHandle, pConfig, (pConfig->fPeriod - pConfig->fDuty) * 32.0f) >> 1U) > 0xFFFFFF))
					{
						EftuTom_ReportDevError(EFTU_TOM_PWM_INIT_ID, EFTU_TOM_E_TIME_INVALID);
						bValid = FALSE;
					}
				}
#endif
			}
		}
		else /* if (TRUE == pConfig->bPhaseShiftEnable) */
		{
            /** Check for phase shift mode and validate PWM parameters */
#if defined(HRPWM_INSTANCE_COUNT) && (HRPWM_INSTANCE_COUNT > 0U)
			if (FALSE == pConfig->bHrpwmSupport)
			{
                /** Validate ordinary PWM phase shift, duty, and period */
				if (	(EFTU_TOM_CONFIG_CLOCK_COUNT(pHandle, pConfig, pConfig->fPhaseShift) > 0xFFFFFF)
					|| 	(EFTU_TOM_CONFIG_CLOCK_COUNT(pHandle, pConfig, pConfig->fPhaseShift + pConfig->fDuty) > 0xFFFFFF))
				{
					EftuTom_ReportDevError(EFTU_TOM_PWM_INIT_ID, EFTU_TOM_E_TIME_INVALID);
					bValid = FALSE;
				}
			}
			else
#endif
			{
                /** Validate high-resolution PWM phase shift, duty, and period */
				if 	(	(EFTU_TOM_CONFIG_CLOCK_COUNT(pHandle, pConfig, pConfig->fPhaseShift * 32.0f) > 0xFFFFFF)
					|| 	(EFTU_TOM_CONFIG_CLOCK_COUNT(pHandle, pConfig, (pConfig->fPhaseShift + pConfig->fDuty) * 32.0f) > 0xFFFFFF))
				{
					EftuTom_ReportDevError(EFTU_TOM_PWM_INIT_ID, EFTU_TOM_E_TIME_INVALID);
					bValid = FALSE;
				}
			}
		}
        /** If the configuration is valid, initialize the PWM channel */
		if (TRUE == bValid)
		{
#endif
			EFTU_TOM_InitHwChannelStatus(pHandle);
			pHandle->tStatus.eMode = EFTU_TOM_MODE_PWM;
			pHandle->tStatus.tPwm.eUpdateMode = pConfig->eUpdateMode;
			pHandle->tStatus.tPwm.bPhaseShiftEnable = pConfig->bPhaseShiftEnable;
			pHandle->tStatus.tPwm.bUpDownMode = pConfig->bUpDownMode;
#if defined(HRPWM_INSTANCE_COUNT) && (HRPWM_INSTANCE_COUNT > 0U)
			pHandle->tStatus.tPwm.bHrpwmSupport = pConfig->bHrpwmSupport;
#endif
			EFTU_TOM_HWA_SetChannelMode(EFTU_TOM_CHANNEL(pHandle), EFTU_TOM_CHANNEL_MODE_PWM);
#if defined(HRPWM_INSTANCE_COUNT) && (HRPWM_INSTANCE_COUNT > 0U)
			if (	(pHandle->eEftuInstance == EFTU_INSTANCE_0)
				&& 	(pHandle->u8Channel < 8U))
			{
				EFTU_TOM_HWA_SetHRPWMSupport(EFTU_TOM_CHANNEL(pHandle), pConfig->bHrpwmSupport);
			}
#endif
			pHandle->tStatus.fClock = EFTU_TOM_CONFIG_CLOCK(pHandle, pConfig);
			uint32_t u32Cm0, u32Cm1;
			if (TRUE == pConfig->bPhaseShiftEnable)
			{
                /** Set reset source and signal level for phase shift mode */
				EFTU_TOM_HWA_SetCCU0ResetSource(EFTU_TOM_CHANNEL(pHandle), EFTU_TOM_RESET_CN0_ON_TRIGGER);
				pHandle->tStatus.tPwm.fDuty = pConfig->fDuty;
				pHandle->tStatus.tPwm.fPeriodPhaseShift = pConfig->fPhaseShift;
#if defined(HRPWM_INSTANCE_COUNT) && (HRPWM_INSTANCE_COUNT > 0U)
				if (FALSE == pConfig->bHrpwmSupport)
				{
#endif
					u32Cm0 = EFTU_TOM_HANDLE_CLOCK_COUNT(pHandle, pConfig->fPhaseShift);
					u32Cm1 = EFTU_TOM_HANDLE_CLOCK_COUNT(pHandle, pConfig->fDuty + pConfig->fPhaseShift);
#if defined(HRPWM_INSTANCE_COUNT) && (HRPWM_INSTANCE_COUNT > 0U)
				}
				else
				{
					u32Cm0 = EFTU_TOM_HANDLE_CLOCK_COUNT(pHandle, pConfig->fPhaseShift * 32.0f);
					u32Cm1 = EFTU_TOM_HANDLE_CLOCK_COUNT(pHandle, pConfig->fDuty + pConfig->fPhaseShift * 32.0f);
				}
#endif
			}
			else
			{
                 /** Set reset source and signal level for non-phase shift mode */
				EFTU_TOM_HWA_SetCCU0ResetSource(EFTU_TOM_CHANNEL(pHandle), EFTU_TOM_RESET_CN0_ON_MATCHING_CM0);
				pHandle->tStatus.tPwm.fDuty = pConfig->fDuty;
				pHandle->tStatus.tPwm.fPeriodPhaseShift = pConfig->fPeriod;
				if (TRUE == pConfig->bUpDownMode)
				{
                    /** Configure up-down counting mode */
					EFTU_TOM_HWA_SetUpDownMode(EFTU_TOM_CHANNEL(pHandle), EFTU_TOM_UP_DOWN_MODE_UPDATE_CN0_REACH_0);
#if defined(HRPWM_INSTANCE_COUNT) && (HRPWM_INSTANCE_COUNT > 0U)
					if (FALSE == pConfig->bHrpwmSupport)
					{
#endif
						u32Cm0 = EFTU_TOM_HANDLE_CLOCK_COUNT(pHandle, pConfig->fPeriod) >> 1U;
						u32Cm1 = EFTU_TOM_HANDLE_CLOCK_COUNT(pHandle, pConfig->fPeriod - pConfig->fDuty) >> 1U;
#if defined(HRPWM_INSTANCE_COUNT) && (HRPWM_INSTANCE_COUNT > 0U)
					}
					else
					{
						u32Cm0 = EFTU_TOM_HANDLE_CLOCK_COUNT(pHandle, pConfig->fPeriod * 32.0f) >> 1U;
						u32Cm1 = EFTU_TOM_HANDLE_CLOCK_COUNT(pHandle, (pConfig->fPeriod - pConfig->fDuty) * 32.0f) >> 1U;
					}
#endif
				}
				else
				{
                    /** Configure up-mode counting mode */
					EFTU_TOM_HWA_SetUpDownMode(EFTU_TOM_CHANNEL(pHandle), EFTU_TOM_UP_MODE);
#if defined(HRPWM_INSTANCE_COUNT) && (HRPWM_INSTANCE_COUNT > 0U)
					if (FALSE == pConfig->bHrpwmSupport)
					{
#endif
						u32Cm0 = EFTU_TOM_HANDLE_CLOCK_COUNT(pHandle, pConfig->fPeriod);
						u32Cm1 = EFTU_TOM_HANDLE_CLOCK_COUNT(pHandle, pConfig->fDuty);
#if defined(HRPWM_INSTANCE_COUNT) && (HRPWM_INSTANCE_COUNT > 0U)
					}
					else
					{
						u32Cm0 = EFTU_TOM_HANDLE_CLOCK_COUNT(pHandle, pConfig->fPeriod * 32.0f);
						u32Cm1 = EFTU_TOM_HANDLE_CLOCK_COUNT(pHandle, pConfig->fDuty * 32.0f);
					}
#endif
				}
			}

			/** Configure clock source */
			EFTU_TOM_HWA_SetShadowClockSource(EFTU_TOM_CHANNEL(pHandle), (uint8_t)pConfig->eClockSource);
			EFTU_TOM_HWA_SetClockSource(EFTU_TOM_CHANNEL(pHandle), (uint8_t)pConfig->eClockSource);

            /** Configure shadow registers */
			EFTU_TOM_HWA_SetShadowInitialSignalLevel(EFTU_TOM_CHANNEL(pHandle), pConfig->eActiveLevel);
			EFTU_TOM_HWA_SetShadowValue0(EFTU_TOM_CHANNEL(pHandle), u32Cm0);
			EFTU_TOM_HWA_SetShadowValue1(EFTU_TOM_CHANNEL(pHandle), u32Cm1);
			if (EFTU_TOM_PWM_UPDATE_SYNC == pConfig->eUpdateMode)
			{
				EFTU_TOM_HWA_EnableChannelUpdate(EFTU_TOM_CHANNEL(pHandle));
			}

			/** Enable force update, set host trigger request, then disable force update */
			EFTU_TOM_HWA_EnableForceUpdate(EFTU_TOM_CHANNEL(pHandle));
			EFTU_TOM_HWA_SetHostTriggerRequest(pHandle->tStatus.pTOM);
			EFTU_TOM_HWA_DisableForceUpdate(EFTU_TOM_CHANNEL(pHandle));

            /** Configure and enable CCU0 interrupt if required */
			if (TRUE == pConfig->bCcu0IrqEnable)
			{
				pHandle->tStatus.tCallback.pCcu0 = pConfig->pCcu0Callback;
				EFTU_TOM_HWA_EnableCCU0Interrupt(EFTU_TOM_CHANNEL(pHandle));
			}
            /** Configure and enable CCU1 interrupt if required */
			if (TRUE == pConfig->bCcu1IrqEnable)
			{
				pHandle->tStatus.tCallback.pCcu1 = pConfig->pCcu1Callback;
				EFTU_TOM_HWA_EnableCCU1Interrupt(EFTU_TOM_CHANNEL(pHandle));
			}
#if EFTU_TOM_DEV_ERROR_REPORT == STD_ON
		}
	}
#endif
}

/**
 * @brief Set the trigger output of the TOM channel.
 *
 * @param pHandle Pointer to the PWM channel handle, containing necessary channel information.
 * @param eTrigOutput Trigger outut selection.
 */
void EFTU_TOM_SetTrigOutput(EFTU_Tom_ChannelHandleType *pHandle, EFTU_TOM_TrigOutSelectionType eTrigOutput)
{
#if EFTU_TOM_DEV_ERROR_REPORT == STD_ON
    /* Verify the handle during development to ensure its validity. */
    if (TRUE == EFTU_TOM_VerifyHandle(pHandle, EFTU_TOM_SET_TRIG_OUT_ID))
    {
    	if ((uint8_t)eTrigOutput > (uint8_t)EFTU_TOM_TRIG_OUT_USE_TRIG_CCU0)
    	{
    		EftuTom_ReportDevError(EFTU_TOM_SET_TRIG_OUT_ID, EFTU_TOM_E_PARAM_INVALID);
    	}
    	else
    	{
#endif
    		EFTU_TOM_HWA_SetTriggerOut(EFTU_TOM_CHANNEL(pHandle), eTrigOutput);
#if EFTU_TOM_DEV_ERROR_REPORT == STD_ON
    	}
    }
#endif
}

/**
 * @brief Start the PWM channel.
 *
 * @param pHandle Pointer to the PWM channel handle, containing necessary channel information.
 * @param bImmediate Boolean value indicating whether to immediately start the PWM output.
 */
void EFTU_TOM_StartPwmChannel(EFTU_Tom_ChannelHandleType *pHandle, bool bImmediate)
{
#if EFTU_TOM_DEV_ERROR_REPORT == STD_ON
    /* Verify the handle during development to ensure its validity. */
    if (TRUE == EFTU_TOM_VerifyHandle(pHandle, EFTU_TOM_START_TIMER_CHANNEL_ID))
    {
#endif
        /* Enable the channel's update trigger, which is a necessary condition for starting the PWM output. */
        EFTU_TOM_HWA_EnableChannelOnUpdateTrig(EFTU_TOM_CHANNEL(pHandle));

		EFTU_TOM_HWA_EnableChannelOutputOnUpdateTrig(EFTU_TOM_CHANNEL(pHandle));
        
        /* If immediate start is required, enable the channel. */
        if (TRUE == bImmediate)
        {
            /* Set the host trigger request, which is another necessary condition for starting the PWM output. */
            EFTU_TOM_HWA_SetHostTriggerRequest(pHandle->tStatus.pTOM);
        }
        
#if EFTU_TOM_DEV_ERROR_REPORT == STD_ON
    }
#endif
}

/**
 * @brief Stop the PWM channel.
 *
 * @param pHandle Pointer to the PWM channel handle, containing necessary channel information.
 * @param bImmediate Boolean value indicating whether to immediately stop the PWM output.
 */
void EFTU_TOM_StopPwmChannel(EFTU_Tom_ChannelHandleType *pHandle, bool bImmediate)
{
#if EFTU_TOM_DEV_ERROR_REPORT == STD_ON
    /* Verify the handle during development to ensure its validity. */
    if (TRUE == EFTU_TOM_VerifyHandle(pHandle, EFTU_TOM_START_TIMER_CHANNEL_ID))
    {
#endif
        /* Disable the channel's update trigger, which is a necessary condition for stopping the PWM output. */
        EFTU_TOM_HWA_DisableChannelOnUpdateTrig(EFTU_TOM_CHANNEL(pHandle));
        EFTU_TOM_HWA_DisableChannelOutputOnUpdateTrig(EFTU_TOM_CHANNEL(pHandle));
        /* If immediate stop is required, disable the channel. */
        if (TRUE == bImmediate)
        {
        	EFTU_TOM_HWA_SetHostTriggerRequest(pHandle->tStatus.pTOM);
        }
#if EFTU_TOM_DEV_ERROR_REPORT == STD_ON
    }
#endif
}

/**
 * @brief Update the PWM period and duty cycle
 *
 * @param pHandle Pointer to the channel handle, containing channel status and configuration information
 * @param fPeriod New PWM period in seconds
 * @param fDuty New PWM duty cycle in seconds
 * @param bUpdate Flag indicating whether to immediately update the hardware registers
 */
void EFTU_TOM_UpdatePwmPeriodAndDuty(EFTU_Tom_ChannelHandleType *pHandle, float fPeriod, float fDuty, bool bUpdate)
{
#if EFTU_TOM_DEV_ERROR_REPORT == STD_ON
    /**
     * Verify handle validity and mode
     */
    if (TRUE == EFTU_TOM_VerifyHandleWithMode(pHandle, EFTU_TOM_UPDATE_PWM_PERIOD_ID, EFTU_TOM_MODE_PWM))
    {
        /**
         * Check if phase shift is enabled, report error if true
         */
        if (TRUE == pHandle->tStatus.tPwm.bPhaseShiftEnable)
        {
            EftuTom_ReportDevError(EFTU_TOM_UPDATE_PWM_PERIOD_ID, EFTU_TOM_E_PWM_MODE);
        }
        /**
         * Check if duty cycle is greater than period, report error if true
         */
        else if (fDuty > fPeriod)
        {
            EftuTom_ReportDevError(EFTU_TOM_UPDATE_PWM_PERIOD_ID, EFTU_TOM_E_TIME_INVALID);
        }
        /**
         * Check if the calculated period exceeds the hardware counter range for different modes and configurations
         */
#if defined(HRPWM_INSTANCE_COUNT) && (HRPWM_INSTANCE_COUNT > 0U)
        else if(    ((FALSE == pHandle->tStatus.tPwm.bUpDownMode) && (FALSE == pHandle->tStatus.tPwm.bHrpwmSupport))
#else
        		else if(    (FALSE == pHandle->tStatus.tPwm.bUpDownMode)
#endif
        		&&  (EFTU_TOM_HANDLE_CLOCK_COUNT(pHandle, fPeriod) > 0xFFFFFF))
        {
            EftuTom_ReportDevError(EFTU_TOM_UPDATE_PWM_PERIOD_ID, EFTU_TOM_E_TIME_INVALID);
        }
#if defined(HRPWM_INSTANCE_COUNT) && (HRPWM_INSTANCE_COUNT > 0U)
        else if(    ((FALSE == pHandle->tStatus.tPwm.bUpDownMode) && (TRUE == pHandle->tStatus.tPwm.bHrpwmSupport))
                &&  (EFTU_TOM_HANDLE_CLOCK_COUNT(pHandle, fPeriod * 32.0f) > 0xFFFFFF))
        {
            EftuTom_ReportDevError(EFTU_TOM_UPDATE_PWM_PERIOD_ID, EFTU_TOM_E_TIME_INVALID);
        }
#endif
#if defined(HRPWM_INSTANCE_COUNT) && (HRPWM_INSTANCE_COUNT > 0U)
        else if(    ((TRUE == pHandle->tStatus.tPwm.bUpDownMode) && (FALSE == pHandle->tStatus.tPwm.bHrpwmSupport))
#else
		else if(    (TRUE == pHandle->tStatus.tPwm.bUpDownMode)
#endif
                &&  ((EFTU_TOM_HANDLE_CLOCK_COUNT(pHandle, fPeriod) >> 1U) > 0xFFFFFF))
        {
            EftuTom_ReportDevError(EFTU_TOM_UPDATE_PWM_PERIOD_ID, EFTU_TOM_E_TIME_INVALID);
        }
#if defined(HRPWM_INSTANCE_COUNT) && (HRPWM_INSTANCE_COUNT > 0U)
        else if(    ((TRUE == pHandle->tStatus.tPwm.bUpDownMode) && (TRUE == pHandle->tStatus.tPwm.bHrpwmSupport))
                &&  ((EFTU_TOM_HANDLE_CLOCK_COUNT(pHandle, fPeriod * 32.0f) >> 1U) > 0xFFFFFF))
        {
            EftuTom_ReportDevError(EFTU_TOM_UPDATE_PWM_PERIOD_ID, EFTU_TOM_E_TIME_INVALID);
        }
#endif
        else
        {
#endif
            uint32_t u32Cm0, u32Cm1;
            /**
             * Update the period and duty cycle values in the handle
             */
            pHandle->tStatus.tPwm.fPeriodPhaseShift = fPeriod;
            pHandle->tStatus.tPwm.fDuty = fDuty;
            /**
             * Calculate CM0 and CM1 values based on up/down count mode and HRPWM support
             */
            if (TRUE == pHandle->tStatus.tPwm.bUpDownMode)
            {
#if defined(HRPWM_INSTANCE_COUNT) && (HRPWM_INSTANCE_COUNT > 0U)
                if (FALSE == pHandle->tStatus.tPwm.bHrpwmSupport)
                {
#endif
                    u32Cm0 = EFTU_TOM_HANDLE_CLOCK_COUNT(pHandle, fPeriod) >> 1U;
                    u32Cm1 = EFTU_TOM_HANDLE_CLOCK_COUNT(pHandle, (fPeriod - fDuty)) >> 1U;
#if defined(HRPWM_INSTANCE_COUNT) && (HRPWM_INSTANCE_COUNT > 0U)
                }
                else
                {
                    u32Cm0 = EFTU_TOM_HANDLE_CLOCK_COUNT(pHandle, fPeriod * 32.0f) >> 1U;
                    u32Cm1 = EFTU_TOM_HANDLE_CLOCK_COUNT(pHandle, (fPeriod - fDuty) * 32.0f) >> 1U;
                }
#endif
            }
            else
            {
#if defined(HRPWM_INSTANCE_COUNT) && (HRPWM_INSTANCE_COUNT > 0U)
                if (FALSE == pHandle->tStatus.tPwm.bHrpwmSupport)
                {
#endif
                    u32Cm0 = EFTU_TOM_HANDLE_CLOCK_COUNT(pHandle, fPeriod);
                    u32Cm1 = EFTU_TOM_HANDLE_CLOCK_COUNT(pHandle, fDuty);
#if defined(HRPWM_INSTANCE_COUNT) && (HRPWM_INSTANCE_COUNT > 0U)
                }
                else
                {
                    u32Cm0 = EFTU_TOM_HANDLE_CLOCK_COUNT(pHandle, fPeriod * 32.0f);
                    u32Cm1 = EFTU_TOM_HANDLE_CLOCK_COUNT(pHandle, fDuty * 32.0f);
                }
#endif
            }
            /**
             * Write the calculated values to the hardware registers based on the update mode
             */
            if (EFTU_TOM_PWM_UPDATE_SYNC == pHandle->tStatus.tPwm.eUpdateMode)
            {
                EFTU_TOM_HWA_DisableChannelUpdate(EFTU_TOM_CHANNEL(pHandle));
                EFTU_TOM_HWA_SetShadowValue0(EFTU_TOM_CHANNEL(pHandle), u32Cm0);
                EFTU_TOM_HWA_SetShadowValue1(EFTU_TOM_CHANNEL(pHandle), u32Cm1);
                if (TRUE == bUpdate)
                {
                    EFTU_TOM_HWA_EnableChannelUpdate(EFTU_TOM_CHANNEL(pHandle));
                }
            }
            else
            {
                EFTU_TOM_HWA_SetCCU0Compare(EFTU_TOM_CHANNEL(pHandle), u32Cm0);
                EFTU_TOM_HWA_SetCCU1Counter(EFTU_TOM_CHANNEL(pHandle), u32Cm1);
            }
#if EFTU_TOM_DEV_ERROR_REPORT == STD_ON
        }
    }
#endif
}

/**
 * @brief Updates the PWM duty cycle for a given channel handle.
 * 
 * @param pHandle Pointer to the PWM channel handle structure containing the channel status and configuration.
 * @param fDuty The new duty cycle value to be set.
 * @param bUpdate A boolean flag indicating whether to immediately update the hardware.
 */
void EFTU_TOM_UpdatePwmDuty(EFTU_Tom_ChannelHandleType *pHandle, float fDuty, bool bUpdate)
{
#if EFTU_TOM_DEV_ERROR_REPORT == STD_ON
    /**
     * Verify the validity of the channel handle.
     */
	if (TRUE == EFTU_TOM_VerifyHandleWithMode(pHandle, EFTU_TOM_UPDATE_PWM_PERIOD_ID, EFTU_TOM_MODE_PWM))
	{
		bool bValid = TRUE;
        /**
         * Check if phase shift is enabled.
         */
		if (TRUE == pHandle->tStatus.tPwm.bPhaseShiftEnable)
		{
#if defined(HRPWM_INSTANCE_COUNT) && (HRPWM_INSTANCE_COUNT > 0U)
            /**
             * Check if HRPWM support is enabled.
             */
			if (FALSE == pHandle->tStatus.tPwm.bHrpwmSupport)
			{
#endif
                /**
                 * Ensure the new duty cycle plus phase shift does not exceed the counter range.
                 */
				if (EFTU_TOM_HANDLE_CLOCK_COUNT(pHandle, fDuty + pHandle->tStatus.tPwm.fPeriodPhaseShift) > 0xFFFFFF)
				{
					EftuTom_ReportDevError(EFTU_TOM_UPDATE_PWM_DUTY_ID, EFTU_TOM_E_TIME_INVALID);
					bValid = FALSE;
				}
#if defined(HRPWM_INSTANCE_COUNT) && (HRPWM_INSTANCE_COUNT > 0U)
			}
			else
			{
                /**
                 * Ensure the new duty cycle plus phase shift does not exceed the HRPWM counter range.
                 */
				if (EFTU_TOM_HANDLE_CLOCK_COUNT(pHandle, (fDuty + pHandle->tStatus.tPwm.fPeriodPhaseShift) * 32.0f) > 0xFFFFFF)
				{
					EftuTom_ReportDevError(EFTU_TOM_UPDATE_PWM_DUTY_ID, EFTU_TOM_E_TIME_INVALID);
					bValid = FALSE;
				}
			}
#endif
		}
        /**
         * Ensure the phase shift is not less than the duty cycle.
         */
		else if (pHandle->tStatus.tPwm.fPeriodPhaseShift < fDuty)
		{
			EftuTom_ReportDevError(EFTU_TOM_UPDATE_PWM_DUTY_ID, EFTU_TOM_E_TIME_INVALID);
			bValid = FALSE;
		}
		else
		{
            /**
             * Check if up-down mode is enabled.
             */
			if (TRUE == pHandle->tStatus.tPwm.bUpDownMode)
			{
#if defined(HRPWM_INSTANCE_COUNT) && (HRPWM_INSTANCE_COUNT > 0U)
                /**
                 * Ensure the new duty cycle does not exceed the counter range in up-down mode.
                 */
				if (FALSE == pHandle->tStatus.tPwm.bHrpwmSupport)
				{
#endif
					if ((EFTU_TOM_HANDLE_CLOCK_COUNT(pHandle, fDuty) >> 1U) > 0xFFFFFF)
					{
						EftuTom_ReportDevError(EFTU_TOM_UPDATE_PWM_DUTY_ID, EFTU_TOM_E_TIME_INVALID);
						bValid = FALSE;
					}
#if defined(HRPWM_INSTANCE_COUNT) && (HRPWM_INSTANCE_COUNT > 0U)
				}
				else
				{
					if ((EFTU_TOM_HANDLE_CLOCK_COUNT(pHandle, fDuty * 32.0f) >> 1U) > 0xFFFFFF)
					{
						EftuTom_ReportDevError(EFTU_TOM_UPDATE_PWM_DUTY_ID, EFTU_TOM_E_TIME_INVALID);
						bValid = FALSE;
					}
				}
#endif
			}
			else
			{
#if defined(HRPWM_INSTANCE_COUNT) && (HRPWM_INSTANCE_COUNT > 0U)
                /**
                 * Ensure the new duty cycle does not exceed the counter range.
                 */
				if (FALSE == pHandle->tStatus.tPwm.bHrpwmSupport)
				{
#endif
					if (EFTU_TOM_HANDLE_CLOCK_COUNT(pHandle, fDuty) > 0xFFFFFF)
					{
						EftuTom_ReportDevError(EFTU_TOM_UPDATE_PWM_DUTY_ID, EFTU_TOM_E_TIME_INVALID);
						bValid = FALSE;
					}
#if defined(HRPWM_INSTANCE_COUNT) && (HRPWM_INSTANCE_COUNT > 0U)
				}
				else
				{
					if (EFTU_TOM_HANDLE_CLOCK_COUNT(pHandle, fDuty * 32.0f) > 0xFFFFFF)
					{
						EftuTom_ReportDevError(EFTU_TOM_UPDATE_PWM_DUTY_ID, EFTU_TOM_E_TIME_INVALID);
						bValid = FALSE;
					}
				}
#endif
			}
		}

        /**
         * If all checks pass, update the PWM configuration.
         */
		if (TRUE == bValid)
		{
#endif
			uint32_t u32Cm1;
            /**
             * Update the duty cycle in the channel status.
             */
			pHandle->tStatus.tPwm.fDuty = fDuty;
            /**
             * Calculate the new counter value based on the configuration.
             */
			if (TRUE == pHandle->tStatus.tPwm.bPhaseShiftEnable)
			{
#if defined(HRPWM_INSTANCE_COUNT) && (HRPWM_INSTANCE_COUNT > 0U)
				if (FALSE == pHandle->tStatus.tPwm.bHrpwmSupport)
				{
#endif
					u32Cm1 = EFTU_TOM_HANDLE_CLOCK_COUNT(pHandle, fDuty + pHandle->tStatus.tPwm.fPeriodPhaseShift);
#if defined(HRPWM_INSTANCE_COUNT) && (HRPWM_INSTANCE_COUNT > 0U)
				}
				else
				{
					u32Cm1 = EFTU_TOM_HANDLE_CLOCK_COUNT(pHandle, (fDuty + pHandle->tStatus.tPwm.fPeriodPhaseShift) * 32.0f);
				}
#endif
			}
			else
			{
				if (TRUE == pHandle->tStatus.tPwm.bUpDownMode)
				{
#if defined(HRPWM_INSTANCE_COUNT) && (HRPWM_INSTANCE_COUNT > 0U)
					if (FALSE == pHandle->tStatus.tPwm.bHrpwmSupport)
					{
#endif
						u32Cm1 = EFTU_TOM_HANDLE_CLOCK_COUNT(pHandle, pHandle->tStatus.tPwm.fPeriodPhaseShift - fDuty) >> 1U;
#if defined(HRPWM_INSTANCE_COUNT) && (HRPWM_INSTANCE_COUNT > 0U)
					}
					else
					{
						u32Cm1 = EFTU_TOM_HANDLE_CLOCK_COUNT(pHandle, (pHandle->tStatus.tPwm.fPeriodPhaseShift - fDuty) * 32.0f) >> 1U;
					}
#endif
				}
				else
				{
#if defined(HRPWM_INSTANCE_COUNT) && (HRPWM_INSTANCE_COUNT > 0U)
					if (FALSE == pHandle->tStatus.tPwm.bHrpwmSupport)
					{
#endif
						u32Cm1 = EFTU_TOM_HANDLE_CLOCK_COUNT(pHandle, fDuty);
#if defined(HRPWM_INSTANCE_COUNT) && (HRPWM_INSTANCE_COUNT > 0U)
					}
					else
					{
						u32Cm1 = EFTU_TOM_HANDLE_CLOCK_COUNT(pHandle, fDuty * 32.0f);
					}
#endif
				}
			}

            /**
             * Update the hardware based on the update mode.
             */
			if (EFTU_TOM_PWM_UPDATE_SYNC == pHandle->tStatus.tPwm.eUpdateMode)
			{
                /**
                 * Update the hardware based on the update mode.
                 */
				EFTU_TOM_HWA_DisableChannelUpdate(EFTU_TOM_CHANNEL(pHandle));
				EFTU_TOM_HWA_SetShadowValue1(EFTU_TOM_CHANNEL(pHandle), u32Cm1);
				if (TRUE == bUpdate)
				{
					EFTU_TOM_HWA_EnableChannelUpdate(EFTU_TOM_CHANNEL(pHandle));
				}
			}
			else
			{
                /**
                 * Directly set the counter value.
                 */
				EFTU_TOM_HWA_SetCCU1Counter(EFTU_TOM_CHANNEL(pHandle), u32Cm1);
			}
#if EFTU_TOM_DEV_ERROR_REPORT == STD_ON
		}
	}
#endif
}

/**
 * @brief Update the PWM phase shift for a given channel.
 *
 * This function updates the phase shift of the PWM output for a specified channel. Before performing the update,
 * it checks the validity of the phase shift based on different conditions. It calculates the corresponding clock counts
 * based on whether the channel supports HRPWM (High-Resolution PWM) or not. Finally, it updates the PWM output either
 * synchronously or asynchronously based on the update mode.
 *
 * @param pHandle Pointer to the channel handle, containing configuration and status information.
 * @param fPhaseShift The phase shift value to be updated.
 * @param bUpdate Flag indicating whether to immediately update the channel configuration.
 */
void EFTU_TOM_UpdatePwmPhaseShfit(EFTU_Tom_ChannelHandleType *pHandle, float fPhaseShift, bool bUpdate)
{
#if EFTU_TOM_DEV_ERROR_REPORT == STD_ON
    /**
     * Verify the channel handle and ensure the channel is in the correct mode.
     */
    if (TRUE == EFTU_TOM_VerifyHandleWithMode(pHandle, EFTU_TOM_UPDATE_PWM_PERIOD_ID, EFTU_TOM_MODE_PWM))
    {
        /**
         * Check if phase shift is enabled.
         */
        if (TRUE != pHandle->tStatus.tPwm.bPhaseShiftEnable)
        {
            EftuTom_ReportDevError(EFTU_TOM_UPDATE_PWM_PHASESHIFT_ID, EFTU_TOM_E_PWM_MODE);
        }
        /**
         * For channels that do not support HRPWM, check if the sum of phase shift and duty cycle exceeds the maximum count.
         */
#if defined(HRPWM_INSTANCE_COUNT) && (HRPWM_INSTANCE_COUNT > 0U)
        else if (    (FALSE == pHandle->tStatus.tPwm.bHrpwmSupport)
                &&  (EFTU_TOM_HANDLE_CLOCK_COUNT(pHandle, fPhaseShift + pHandle->tStatus.tPwm.fDuty) > 0xFFFFFF))
#else
		else if (EFTU_TOM_HANDLE_CLOCK_COUNT(pHandle, fPhaseShift + pHandle->tStatus.tPwm.fDuty) > 0xFFFFFF)
#endif
        {
            EftuTom_ReportDevError(EFTU_TOM_UPDATE_PWM_PHASESHIFT_ID, EFTU_TOM_E_TIME_INVALID);
        }
#if defined(HRPWM_INSTANCE_COUNT) && (HRPWM_INSTANCE_COUNT > 0U)
        /**
         * For channels that support HRPWM, perform a similar check but multiply the count by 32.
         */
        else if (    (TRUE == pHandle->tStatus.tPwm.bHrpwmSupport)
                &&  (EFTU_TOM_HANDLE_CLOCK_COUNT(pHandle, (fPhaseShift + pHandle->tStatus.tPwm.fDuty) * 32.0f) > 0xFFFFFF))
        {
            EftuTom_ReportDevError(EFTU_TOM_UPDATE_PWM_PHASESHIFT_ID, EFTU_TOM_E_TIME_INVALID);
        }
#endif
        else
        {
#endif
            uint32_t u32Cm1, u32Cm0;
            /**
             * Update the phase shift value.
             */
            pHandle->tStatus.tPwm.fPeriodPhaseShift = fPhaseShift;
#if defined(HRPWM_INSTANCE_COUNT) && (HRPWM_INSTANCE_COUNT > 0U)
            /**
             * Calculate CM0 and CM1 values based on whether HRPWM is supported.
             */
            if (FALSE == pHandle->tStatus.tPwm.bHrpwmSupport)
            {
#endif
                u32Cm0 = EFTU_TOM_HANDLE_CLOCK_COUNT(pHandle, fPhaseShift);
                u32Cm1 = EFTU_TOM_HANDLE_CLOCK_COUNT(pHandle, pHandle->tStatus.tPwm.fDuty + fPhaseShift);
#if defined(HRPWM_INSTANCE_COUNT) && (HRPWM_INSTANCE_COUNT > 0U)
            }
            else
            {
                u32Cm0 = EFTU_TOM_HANDLE_CLOCK_COUNT(pHandle, fPhaseShift * 32.0f);
                u32Cm1 = EFTU_TOM_HANDLE_CLOCK_COUNT(pHandle, (pHandle->tStatus.tPwm.fDuty + fPhaseShift) * 32.0f);
            }
#endif
            /**
             * Update the PWM output based on the update mode.
             */
            if (EFTU_TOM_PWM_UPDATE_SYNC == pHandle->tStatus.tPwm.eUpdateMode)
            {
                EFTU_TOM_HWA_DisableChannelUpdate(EFTU_TOM_CHANNEL(pHandle));
                EFTU_TOM_HWA_SetShadowValue0(EFTU_TOM_CHANNEL(pHandle), u32Cm0);
                EFTU_TOM_HWA_SetShadowValue1(EFTU_TOM_CHANNEL(pHandle), u32Cm1);
                if (TRUE == bUpdate)
                {
                    EFTU_TOM_HWA_EnableChannelUpdate(EFTU_TOM_CHANNEL(pHandle));
                }
            }
            else
            {
                EFTU_TOM_HWA_SetCCU0Compare(EFTU_TOM_CHANNEL(pHandle), u32Cm0);
                EFTU_TOM_HWA_SetCCU1Counter(EFTU_TOM_CHANNEL(pHandle), u32Cm1);
            }
#if EFTU_TOM_DEV_ERROR_REPORT == STD_ON
        }
    }
#endif
}

/**
 * @brief Synchronizes and updates the control registers of the EFTU TOM module.
 *
 * This function updates the global control registers of the EFTU TOM module based on the update mask.
 * It processes the update mask to determine which configuration bits need to be updated and applies
 * the changes to the appropriate control registers.
 *
 * @param eEftuInstance The instance type of the EFTU device.
 * @param u16UpdateMask A 16-bit update mask where each bit represents a configuration item to be updated.
 */
void EFTU_TOM_SyncUpdate(EFTU_InstanceType eEftuInstance, uint16_t u16UpdateMask)
{
    uint32_t u32Mask = 0U, u32Loop;
    uint32_t u32TempMask;

    /* Build the mask for the updates */
    for (u32Loop = 0U; u32Loop < 16U; u32Loop++)
    {
        if (u16UpdateMask & (1U << u32Loop))
        {
            u32Mask |= (2U << (u32Loop << 1U));
        }
    }

    /* Process updates for TOM0 */
    u32TempMask = (u32Mask & 0xFFFFU) << EFTU_TOM_TGC_GLB_CTRL_UPEN_CTRL0_SHIFT;
    if (0U != u32TempMask)
    {
        EFTU_TOM_Type *pTOM = (EFTU_TOM_Type * )(g_aEftuBaseAddress[eEftuInstance] + EFTU_TOM0_BASE);
        uint32_t u32Value = EFTU_TOM_HWA_GetGlobalControl(pTOM);
        u32Value = (u32Value & 0x0000FFFF) | u32TempMask;
        EFTU_TOM_HWA_SetGlobalControl(pTOM, u32Value);
    }

    /* Process updates for TOM1 */
    u32TempMask = u32Mask & 0xFFFF0000;
    if (0U != u32TempMask)
    {
        EFTU_TOM_Type *pTOM = (EFTU_TOM_Type * )(g_aEftuBaseAddress[eEftuInstance] + EFTU_TOM1_BASE);
        uint32_t u32Value = EFTU_TOM_HWA_GetGlobalControl(pTOM);
        u32Value = (u32Value & 0x0000FFFF) | u32TempMask;
        EFTU_TOM_HWA_SetGlobalControl(pTOM, u32Value);
    }
}

/**
 * @brief Interrupt service routine for the EFTU TOM channel.
 *
 * This function handles the interrupt requests for the EFTU TOM channel. It retrieves the interrupt flags,
 * clears them, and then calls the appropriate callback functions if the corresponding interrupt flags are set
 * and the callbacks are not null.
 *
 * @param pHandle Pointer to the handle of the EFTU TOM channel.
 */
void EFTUn_TOM_IRQHandler(EFTU_Tom_ChannelHandleType *pHandle)
{
    uint32_t u32Flag = EFTU_TOM_HWA_GetInterruptFlag(EFTU_TOM_CHANNEL(pHandle));
    EFTU_TOM_HWA_ClearInterruptFlag(EFTU_TOM_CHANNEL(pHandle), u32Flag);

    /* Check and call CCU0 interrupt callback if set */
    if ((u32Flag & EFTU_TOM_CHn_IRQ_ST_CCU0TC_MASK) && (pHandle->tStatus.tCallback.pCcu0 != NULL))
    {
        pHandle->tStatus.tCallback.pCcu0(pHandle);
    }

    /* Check and call CCU1 interrupt callback if set */
    if ((u32Flag & EFTU_TOM_CHn_IRQ_ST_CCU1TC_MASK) && (pHandle->tStatus.tCallback.pCcu1 != NULL))
    {
        pHandle->tStatus.tCallback.pCcu1(pHandle);
    }
}

#endif /* defined(EFTU_INSTANCE_COUNT) && (EFTU_INSTANCE_COUNT > 0) */
