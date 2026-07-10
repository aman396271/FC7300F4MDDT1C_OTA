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
   *   2.0.0       2024-11-07    Flagchip070   N/A          First version for FC7300
   ******************************************************************************** */

#include "module_driver_eftu_dtm.h"

#if defined(EFTU_INSTANCE_COUNT) && (EFTU_INSTANCE_COUNT > 0)

#ifndef EFTU_DTM_DEV_ERROR_REPORT
#define EFTU_DTM_DEV_ERROR_REPORT	STD_OFF
#endif

#if EFTU_DTM_DEV_ERROR_REPORT == STD_ON
#define EftuDtm_ReportDevError(func, error) ReportDevError(EFTU_DTM_MODULE_ID, func, error)
#endif

#define EFTU_DTM_CHANNEL(h)						(h)->tStatus.pDtm, (h)->tStatus.u8HwChannel
#define EFTU_DTM_CONFIG_CLOCK(h, c)				((c)->eClockSource == EFTU_DTM_CLOCK_SRC_SYS_CLK ? (h)->pCmuHandle->fBusClock : (h)->pCmuHandle->tStatus.fCmuClock[(h)->eEftuInstance][(c)->eClockSource - 1U])
#define EFTU_DTM_CONFIG_CLOCK_COUNT(h, c, t)	((uint32_t)((t) * EFTU_DTM_CONFIG_CLOCK(h, c) + 0.5f))
#define EFTU_DTM_HANDLE_CLOCK_COUNT(h, t)		((uint32_t)((t) * (h)->tStatus.fClock + 0.5f))

/******* Local Function Prototype *********/

static void EFTU_DTM_InitHwChannelStatus(EFTU_Dtm_ChannelHandleType *pHandle);
#if EFTU_DTM_DEV_ERROR_REPORT == STD_ON
static bool EFTU_DTM_CheckInited(EFTU_Dtm_ChannelHandleType *pHandle, uint32_t u32FuncId);
static bool EFTU_DTM_VerifyHandle(EFTU_Dtm_ChannelHandleType *pHandle, uint32_t u32FuncId, bool bCheckInited);

/********* Local Functions ************/
/**
 * @brief Check if the DTM (Data Transfer Manager) is initialized
 *
 * This function verifies whether the given DTM channel handle points to a valid DTM instance address.
 * If the DTM is not initialized, an error is reported.
 *
 * @param pHandle Pointer to the DTM channel handle containing status information
 * @param u32FuncId Function identifier used for error reporting
 * @return bool Returns true if the DTM is initialized, false otherwise
 */
static bool EFTU_DTM_CheckInited(EFTU_Dtm_ChannelHandleType *pHandle, uint32_t u32FuncId)
{
    /** Initialize the validity flag to FALSE */
    bool bValid = FALSE;
    /** Loop variable for iterating through DTM instances */
    uint32_t u32Loop;

    /** Iterate through all DTM instances */
    for (u32Loop = 0; u32Loop < EFTU_INSTANCE_COUNT; u32Loop++)
    {
        /** Check if the DTM address matches any valid DTM instance address */
        if (    ((uint32_t)pHandle->tStatus.pDtm == (g_aEftuBaseAddress[u32Loop] + EFTU_DTM0_BASE))
            ||  ((uint32_t)pHandle->tStatus.pDtm == (g_aEftuBaseAddress[u32Loop] + EFTU_DTM1_BASE))
            ||  ((uint32_t)pHandle->tStatus.pDtm == (g_aEftuBaseAddress[u32Loop] + EFTU_DTM2_BASE))
            ||  ((uint32_t)pHandle->tStatus.pDtm == (g_aEftuBaseAddress[u32Loop] + EFTU_DTM3_BASE)))
        {
            /** If the address matches, set the valid flag to TRUE and break the loop */
            bValid = TRUE;
            break;
        }
    }

    /** If no valid DTM instance address is found, report an uninitialized error */
    if (FALSE == bValid)
    {
        EftuDtm_ReportDevError(u32FuncId, EFTU_DTM_E_UNINITED);
    }

    /** Return the initialization status of the DTM */
    return bValid;
}

/**
 * @brief Verify the validity of an EFTU_DTM channel handle.
 *
 * This function checks the validity of an EFTU_DTM channel handle, including the instance and channel number,
 * and optionally checks if the handle is initialized. If the handle is invalid, it reports the corresponding error.
 *
 * @param pHandle Pointer to the EFTU_DTM channel handle, containing eEftuInstance and u8Channel fields
 * @param u32FuncId Function identifier used for error reporting
 * @param bCheckInited Flag indicating whether to check the initialization status of the handle
 * @return true If the handle is valid and (if required) initialized
 * @return false If the handle is invalid or not initialized (if initialization check is required)
 */
static bool EFTU_DTM_VerifyHandle(EFTU_Dtm_ChannelHandleType *pHandle, uint32_t u32FuncId, bool bCheckInited)
{
    bool bValid = TRUE;

    /* Check if the eEftuInstance value is out of the valid range */
    if ((uint32_t)pHandle->eEftuInstance >= (uint32_t)EFTU_INSTANCE_COUNT)
    {
        EftuDtm_ReportDevError(u32FuncId, EFTU_DTM_E_PARAM_INSTANCE);
        bValid = FALSE;
    }
    /* Check if the channel number is out of the valid range */
    else if (pHandle->u8Channel >= (EFTU_DTM_CHn_DTV_COUNT * 4U))
    {
        EftuDtm_ReportDevError(u32FuncId, EFTU_DTM_E_PARAM_CHANNEL);
        bValid = FALSE;
    }

    /* If the handle is still valid so far and initialization check is required, perform the initialization check */
    if ((TRUE == bValid) && (TRUE == bCheckInited))
    {
        bValid = EFTU_DTM_CheckInited(pHandle, u32FuncId);
    }
    return bValid;
}
#endif

/**
 * @brief Initialize hardware channel status
 *
 * This function initializes the hardware status of the EFTU DTM (Data Transfer Manager) channel.
 * It primarily calculates and sets the DTM base address and hardware channel number in the handle.
 *
 * @param pHandle Pointer to the EFTU DTM channel handle, containing the information needed for initialization
 */
static void EFTU_DTM_InitHwChannelStatus(EFTU_Dtm_ChannelHandleType *pHandle)
{
    /** EFTU DTM channel base address table, containing the base address for each DTM channel */
    const uint32_t aDtmBaseTab[EFTU_DTM_CHn_DTV_COUNT] =
    {
        EFTU_DTM0_BASE, EFTU_DTM1_BASE, EFTU_DTM2_BASE, EFTU_DTM3_BASE
    };

    /** Calculate the DTM base address based on the EFTU instance base address and channel number */
    pHandle->tStatus.pDtm = (EFTU_DTM_Type *)(
            g_aEftuBaseAddress[pHandle->eEftuInstance] + aDtmBaseTab[pHandle->u8Channel / EFTU_DTM_CHn_DTV_COUNT]
    );

    /** Calculate and set the hardware channel number */
    pHandle->tStatus.u8HwChannel = pHandle->u8Channel % EFTU_DTM_CHn_DTV_COUNT;
}

/**
 * @brief Initialize EFTU DTM channel
 * 
 * This function initializes the configuration and status of an EFTU DTM channel. It sets up the clock source, output mode, dead time, etc., based on the provided configuration parameters.
 * 
 * @param pHandle Pointer to the channel handle, containing hardware information and status
 * @param pConfig Pointer to the channel configuration, containing configuration parameters
 */
void EFTU_DTM_InitChannel(EFTU_Dtm_ChannelHandleType *pHandle, EFTU_Dtm_ChannelConfigType *pConfig)
{
#if EFTU_DTM_DEV_ERROR_REPORT == STD_ON
/** Perform parameter validity checks in development mode */
	bool bValid = EFTU_DTM_VerifyHandle(pHandle, EFTU_DTM_INIT_CHANNEL_ID, FALSE);
	if (TRUE == bValid)
	{
        /** Check if the clock source is valid */
		if (((uint32_t)pConfig->eClockSource) > (uint32_t)EFTU_DTM_CLOCK_SRC_CMU_CLK2)
		{
			EftuDtm_ReportDevError(EFTU_DTM_INIT_CHANNEL_ID, EFTU_DTM_E_CLOCK_SRC_INVALID);
		}
#if defined(HRPWM_INSTANCE_COUNT) && (HRPWM_INSTANCE_COUNT > 0U)
        /** Check if high-resolution PWM support is valid */
		else if (	(TRUE == pConfig->bHRPwmSupport)
				&& 	(	(pHandle->eEftuInstance != EFTU_INSTANCE_0)
					||	(pHandle->u8Channel >= 8U)
					||	(
							(pConfig->eClockSource != EFTU_DTM_CLOCK_SRC_SYS_CLK)
							&& (fabsf(pHandle->pCmuHandle->fBusClock - pHandle->pCmuHandle->tStatus.fCmuClock[pHandle->eEftuInstance][(uint32_t)pConfig->eClockSource - 1U]) > 1.0f)
						)
					)
				)
		{
			EftuDtm_ReportDevError(EFTU_DTM_INIT_CHANNEL_ID, EFTU_DTM_E_PARAM_INVALID);
		}
#endif
        /** Check if rising edge dead time is within range */
#if defined(HRPWM_INSTANCE_COUNT) && (HRPWM_INSTANCE_COUNT > 0U)
		else if (	((TRUE == pConfig->bRisingDeadTimeEnable) && (FALSE == pConfig->bHRPwmSupport))
#else
		else if (	(TRUE == pConfig->bRisingDeadTimeEnable)
#endif
				&& 	(EFTU_DTM_CONFIG_CLOCK_COUNT(pHandle, pConfig, pConfig->fRisingDeadTime) > 0x1FFFU))
		{
			EftuDtm_ReportDevError(EFTU_DTM_INIT_CHANNEL_ID, EFTU_DTM_E_TIME_INVALID);
		}
#if defined(HRPWM_INSTANCE_COUNT) && (HRPWM_INSTANCE_COUNT > 0U)
        /** Check if high-resolution PWM supported rising edge dead time is within range */
		else if (	((TRUE == pConfig->bRisingDeadTimeEnable) && (TRUE == pConfig->bHRPwmSupport))
				&& 	(EFTU_DTM_CONFIG_CLOCK_COUNT(pHandle, pConfig, pConfig->fRisingDeadTime * 32.0f) > 0x1FFFU))
		{
			EftuDtm_ReportDevError(EFTU_DTM_INIT_CHANNEL_ID, EFTU_DTM_E_TIME_INVALID);
		}
#endif
        /** Check if falling edge dead time is within range */
#if defined(HRPWM_INSTANCE_COUNT) && (HRPWM_INSTANCE_COUNT > 0U)
		else if (	((TRUE == pConfig->bFallingDeadTimeEnable) && (FALSE == pConfig->bHRPwmSupport))
#else
		else if (	(TRUE == pConfig->bFallingDeadTimeEnable)
#endif
				&& 	(EFTU_DTM_CONFIG_CLOCK_COUNT(pHandle, pConfig, pConfig->fFallingDeadTime) > 0x1FFFU))
		{
			EftuDtm_ReportDevError(EFTU_DTM_INIT_CHANNEL_ID, EFTU_DTM_E_TIME_INVALID);
		}
#if defined(HRPWM_INSTANCE_COUNT) && (HRPWM_INSTANCE_COUNT > 0U)
        /** Check if high-resolution PWM supported falling edge dead time is within range */
		else if (	((TRUE == pConfig->bFallingDeadTimeEnable) && (TRUE == pConfig->bHRPwmSupport))
				&& 	(EFTU_DTM_CONFIG_CLOCK_COUNT(pHandle, pConfig, pConfig->fFallingDeadTime * 32.0f) > 0x1FFFU))
		{
			EftuDtm_ReportDevError(EFTU_DTM_INIT_CHANNEL_ID, EFTU_DTM_E_TIME_INVALID);
		}
#endif
		else
		{
#endif
            /** Initialize hardware channel status */
			EFTU_DTM_InitHwChannelStatus(pHandle);
            /** Set the clock source for the channel */
			EFTU_DTM_HWA_SetClockSource(pHandle->tStatus.pDtm, pConfig->eClockSource);
            /** Calculate and store the channel's clock frequency */
			pHandle->tStatus.fClock = EFTU_DTM_CONFIG_CLOCK(pHandle, pConfig);
            /** Store the high-resolution PWM support flag */
#if defined(HRPWM_INSTANCE_COUNT) && (HRPWM_INSTANCE_COUNT > 0U)
			pHandle->tStatus.bHrpwmSupport = pConfig->bHRPwmSupport;
#endif
            /** Set the channel's output mode to inverted dead time signal */
			EFTU_DTM_HWA_SelectOutput1(EFTU_DTM_CHANNEL(pHandle), EFTU_DTM_O1SEL_INV_DEAD_TIME_SIGNAL);
			/** Set output swap */
			EFTU_DTM_HWA_SetSwapEnable(EFTU_DTM_CHANNEL(pHandle), pConfig->bSwapOutput);

			EFTU_DTM_SignalLevelType eLevel;
			uint32_t u32Shift = (uint32_t)(pHandle->tStatus.u8HwChannel) << 3U;
			uint32_t u32CHCtrl2 = EFTU_DTM_HWA_GetCHCTRL2(pHandle->tStatus.pDtm);
            /** Clear relevant bits in the channel control register */
			u32CHCtrl2 &= ~((	EFTU_DTM_CH_CTRL2_DT0_0_MASK 	| EFTU_DTM_CH_CTRL2_OC0_0_MASK
							| 	EFTU_DTM_CH_CTRL2_POL0_0_MASK 	| EFTU_DTM_CH_CTRL2_SL0_0_MASK
							|	EFTU_DTM_CH_CTRL2_DT1_0_MASK 	| EFTU_DTM_CH_CTRL2_OC1_0_MASK
							| 	EFTU_DTM_CH_CTRL2_POL1_0_MASK	| EFTU_DTM_CH_CTRL2_SL1_0_MASK) << u32Shift);
            /** Set input signal and output mode based on configuration */
			if (EFTU_DTM_INPUT_SIG_DTM_IN == pConfig->tOutput.eInputSignal)
			{
				if (pConfig->bRisingDeadTimeEnable)
				{
#if defined(HRPWM_INSTANCE_COUNT) && (HRPWM_INSTANCE_COUNT > 0U)
					if (FALSE == pConfig->bHRPwmSupport)
					{
#endif
						EFTU_DTM_HWA_SetRisingEdgeDeadTime(	EFTU_DTM_CHANNEL(pHandle),
								(uint16_t)EFTU_DTM_HANDLE_CLOCK_COUNT(pHandle, pConfig->fRisingDeadTime));
#if defined(HRPWM_INSTANCE_COUNT) && (HRPWM_INSTANCE_COUNT > 0U)
					}
					else
					{
						EFTU_DTM_HWA_SetRisingEdgeDeadTime(	EFTU_DTM_CHANNEL(pHandle),
								(uint16_t)EFTU_DTM_HANDLE_CLOCK_COUNT(pHandle, pConfig->fRisingDeadTime * 32.0f));
					}
#endif
				}
				u32CHCtrl2 |= 	(	EFTU_DTM_CH_CTRL2_DT0_0(pConfig->bRisingDeadTimeEnable)
								| 	EFTU_DTM_CH_CTRL2_OC0_0(EFTU_DTM_OC_FUNCTIONAL)
								|	EFTU_DTM_CH_CTRL2_POL0_0(pConfig->tOutput.bInvertPol)) << u32Shift;
			}
			else
			{
				if (EFTU_DTM_INPUT_SIG_LOW_LEVEL == pConfig->tOutput.eInputSignal)
				{
					eLevel = EFTU_DTM_SL_LOW;
				}
				else
				{
					eLevel = EFTU_DTM_SL_HIGH;
				}
				u32CHCtrl2 |= 	(	EFTU_DTM_CH_CTRL2_SL0_0(eLevel)
								|	EFTU_DTM_CH_CTRL2_OC0_0(EFTU_DTM_OC_CONSTANT)
								|	EFTU_DTM_CH_CTRL2_POL0_0(FALSE)) << u32Shift;
			}

            /** Set input signal and output mode based on configuration */
			if (EFTU_DTM_INPUT_SIG_DTM_IN == pConfig->tOutputN.eInputSignal)
			{
				if (pConfig->bFallingDeadTimeEnable)
				{
#if defined(HRPWM_INSTANCE_COUNT) && (HRPWM_INSTANCE_COUNT > 0U)
					if (FALSE == pConfig->bHRPwmSupport)
					{
#endif
						EFTU_DTM_HWA_SetFallingEdgeDeadTime(EFTU_DTM_CHANNEL(pHandle),
															(uint16_t)EFTU_DTM_HANDLE_CLOCK_COUNT(pHandle, pConfig->fFallingDeadTime));
#if defined(HRPWM_INSTANCE_COUNT) && (HRPWM_INSTANCE_COUNT > 0U)
					}
					else
					{
						EFTU_DTM_HWA_SetFallingEdgeDeadTime(EFTU_DTM_CHANNEL(pHandle),
															(uint16_t)EFTU_DTM_HANDLE_CLOCK_COUNT(pHandle, pConfig->fFallingDeadTime * 32.0f));
					}
#endif
				}
				u32CHCtrl2 |= 	(	EFTU_DTM_CH_CTRL2_DT1_0(pConfig->bFallingDeadTimeEnable)
								| 	EFTU_DTM_CH_CTRL2_OC1_0(EFTU_DTM_OC_FUNCTIONAL)
								|	EFTU_DTM_CH_CTRL2_POL1_0(pConfig->tOutputN.bInvertPol)) << u32Shift;
			}
			else
			{
				if (EFTU_DTM_INPUT_SIG_LOW_LEVEL == pConfig->tOutputN.eInputSignal)
				{
					eLevel = EFTU_DTM_SL_LOW;
				}
				else
				{
					eLevel = EFTU_DTM_SL_HIGH;
				}
				u32CHCtrl2 |= 	(	EFTU_DTM_CH_CTRL2_SL1_0(eLevel)
								|	EFTU_DTM_CH_CTRL2_OC1_0(EFTU_DTM_OC_CONSTANT)
								|	EFTU_DTM_CH_CTRL2_POL1_0(FALSE)) << u32Shift;
			}
            /** Update the channel control register */
			EFTU_DTM_HWA_SetCHCTRL2(pHandle->tStatus.pDtm, u32CHCtrl2);
#if defined(HRPWM_INSTANCE_COUNT) && (HRPWM_INSTANCE_COUNT > 0U)
            /** Set high-resolution PWM mode */
			if ((EFTU_INSTANCE_0 == pHandle->eEftuInstance) && (pHandle->u8Channel < 8U))
			{
				EFTU_DTM_SetHRPWM(EFTU_DTM_CHANNEL(pHandle), pConfig->bHRPwmSupport);
			}
#endif
#if EFTU_DTM_DEV_ERROR_REPORT == STD_ON
		}
	}
#endif
}

/**
 * @brief Set the shutdown configuration for an EFTU DTM channel
 * 
 * This function configures the shutdown behavior of an EFTU DTM channel, including the selection of the shutdown signal,
 * the polarity of the shutdown signal, and the clear mode after shutdown.
 * 
 * @param pHandle Pointer to the EFTU DTM channel handle, used to identify and operate a specific DTM channel
 * @param pConfig Pointer to a structure containing the shutdown configuration parameters, defining the shutdown signal,
 *                polarity, and clear mode
 */
void EFTU_DTM_SetChannelShutOff(EFTU_Dtm_ChannelHandleType *pHandle, EFTU_Dtm_ShutOffConfigType *pConfig)
{
    /** In case the development error reporting feature is enabled, validate the handle */
#if EFTU_DTM_DEV_ERROR_REPORT == STD_ON
	bool bValid = EFTU_DTM_VerifyHandle(pHandle, EFTU_DTM_SET_CHANNEL_SHUTOFF_ID, TRUE);

	if (TRUE == bValid)
	{
        /** Check the validity of the configuration parameters. If invalid, report a development error */
		if (	(TRUE == pConfig->bEnable)
			&& 	(
					(	((pHandle->u8Channel < 8U))
							&& 	(	(pConfig->eShutOffSignal == EFTU_DTM_SHUTOFF_SIG_HSADC2_COMPARE_OUT)
									|| 	(pConfig->eShutOffSignal == EFTU_DTM_SHUTOFF_SIG_HSADC3_COMPARE_OUT)
									||	(pConfig->eShutOffSignal == EFTU_DTM_SHUTOFF_SIG_EFTU_FLT1)
									||	(pConfig->eShutOffSignal == EFTU_DTM_SHUTOFF_SIG_SDADC1_PROTECT2)
						)
					)
					||
					(	((pHandle->u8Channel >= 8U))
						&& 	(	(pConfig->eShutOffSignal == EFTU_DTM_SHUTOFF_SIG_HSADC0_COMPARE_OUT)
							|| 	(pConfig->eShutOffSignal == EFTU_DTM_SHUTOFF_SIG_HSADC1_COMPARE_OUT)
							||	(pConfig->eShutOffSignal == EFTU_DTM_SHUTOFF_SIG_EFTU_FLT0)
							||	(pConfig->eShutOffSignal == EFTU_DTM_SHUTOFF_SIG_SDADC0_PROTECT2)
						)
					)
				)
			)
		{
			EftuDtm_ReportDevError(EFTU_DTM_SET_CHANNEL_SHUTOFF_ID, EFTU_DTM_E_PARAM_INVALID);
		}
		else
		{
#endif
            /** Calculate the shift amount for the control register based on the channel number */
			uint32_t u32Shift = (uint32_t)pHandle->tStatus.u8HwChannel << 3U;
            /** Get the current value of the CTRL2 register for the DTM */
			uint32_t u32Ctrl2 = EFTU_DTM_HWA_GetCTRL2(pHandle->tStatus.pDtm);
			uint32_t u32Temp = 0;
            /** Clear the control bits related to shutdown */
			u32Ctrl2 &= ~((		EFTU_DTM_CTRL2_SHUTOFF_SEL_0_MASK | EFTU_DTM_CTRL2_SHUTOFF_POL_0_MASK
							|	EFTU_DTM_CTRL2_UPD_MODE_0_MASK) << u32Shift);
            /** If the shutdown feature is enabled, set the appropriate shutdown signal and polarity */
			if (TRUE == pConfig->bEnable)
			{
				switch (pConfig->eShutOffSignal)
				{
				case EFTU_DTM_SHUTOFF_SIG_TIM_IN0:
					u32Temp |= EFTU_DTM_CTRL2_SHUTOFF_SEL_0(EFTU_DTM_SHUTOFF_SEL_TIM_CH_IN0);
					break;
				case EFTU_DTM_SHUTOFF_SIG_TIM_IN1:
					u32Temp |= EFTU_DTM_CTRL2_SHUTOFF_SEL_0(EFTU_DTM_SHUTOFF_SEL_TIM_CH_IN1);
					break;
				case EFTU_DTM_SHUTOFF_SIG_EFTU_FLT0:
				case EFTU_DTM_SHUTOFF_SIG_EFTU_FLT1:
					u32Temp |= EFTU_DTM_CTRL2_SHUTOFF_SEL_0(EFTU_DTM_SHUTOFF_SEL_DTM_AUX_IN0);
					break;
				case EFTU_DTM_SHUTOFF_SIG_SDADC0_PROTECT2:
				case EFTU_DTM_SHUTOFF_SIG_SDADC1_PROTECT2:
					u32Temp |= EFTU_DTM_CTRL2_SHUTOFF_SEL_0(EFTU_DTM_SHUTOFF_SEL_DTM_AUX_IN1);
					break;
				case EFTU_DTM_SHUTOFF_SIG_HSADC0_COMPARE_OUT:
				case EFTU_DTM_SHUTOFF_SIG_HSADC2_COMPARE_OUT:
					u32Temp |= EFTU_DTM_CTRL2_SHUTOFF_SEL_0(EFTU_DTM_SHUTOFF_SEL_DTM_AUX_IN2);
					break;
				case EFTU_DTM_SHUTOFF_SIG_HSADC1_COMPARE_OUT:
				case EFTU_DTM_SHUTOFF_SIG_HSADC3_COMPARE_OUT:
					u32Temp |= EFTU_DTM_CTRL2_SHUTOFF_SEL_0(EFTU_DTM_SHUTOFF_SEL_DTM_AUX_IN3);
					break;
                default:
                    break;
				}
                /** Set the polarity of the shutdown signal */
				u32Temp |= EFTU_DTM_CTRL2_SHUTOFF_POL_0(pConfig->eShutOffLevel);
                /** Set the clear mode after shutdown based on the configuration */
				switch (pConfig->eClearMode)
				{
				case EFTU_DTM_SHUTOFF_CLEAR_BY_SHUTOFF_RESET:
					u32Temp |= EFTU_DTM_CTRL2_UPD_MODE_0(1U);
					break;
				case EFTU_DTM_SHUTOFF_CLEAR_BY_IN_FEDGE:
					EFTU_DTM_HWA_SetUpdateSignal(pHandle->tStatus.pDtm, EFTU_DTM_SEL_FALLING_EDGE_ON_CURRENT);
					u32Temp |= EFTU_DTM_CTRL2_UPD_MODE_0(2U);
					break;
				case EFTU_DTM_SHUTOFF_CLEAR_BY_IN_REDGE:
					EFTU_DTM_HWA_SetUpdateSignal(pHandle->tStatus.pDtm, EFTU_DTM_SEL_RISING_EDGE_ON_CURRENT);
					u32Temp |= EFTU_DTM_CTRL2_UPD_MODE_0(2U);
					break;
				case EFTU_DTM_SHUTOFF_CLEAR_BY_PREV_IN_FEDGE:
					EFTU_DTM_HWA_SetUpdateSignal(pHandle->tStatus.pDtm, EFTU_DTM_SEL_FALLING_EDGE_ON_PRECEDING);
					u32Temp |= EFTU_DTM_CTRL2_UPD_MODE_0(2U);
					break;
				case EFTU_DTM_SHUTOFF_CLEAR_BY_PREV_IN_REDGE:
					EFTU_DTM_HWA_SetUpdateSignal(pHandle->tStatus.pDtm, EFTU_DTM_SEL_RISING_EDGE_ON_PRECEDING);
					u32Temp |= EFTU_DTM_CTRL2_UPD_MODE_0(2U);
					break;
				case EFTU_DTM_SHUTOFF_CLEAR_BY_SHUTOFF_SIGNAL:
					u32Temp |= EFTU_DTM_CTRL2_UPD_MODE_0(3U);
					break;
				}
                /** Get and modify the channel control register settings related to shutdown */
				uint32_t u32ChCtrl2SR = EFTU_DTM_HWA_GetCTRL2SR(pHandle->tStatus.pDtm);
				u32ChCtrl2SR &= ~((		EFTU_DTM_CH_CTRL2_SR_OC0_0_SR_MASK
									|	EFTU_DTM_CH_CTRL2_SR_OC1_0_SR_MASK
									|	EFTU_DTM_CH_CTRL2_SR_POL0_0_SR_MASK
									| 	EFTU_DTM_CH_CTRL2_SR_POL1_0_SR_MASK
									|	EFTU_DTM_CH_CTRL2_SR_SL0_0_SR_MASK
									|	EFTU_DTM_CH_CTRL2_SR_SL1_0_SR_MASK) << u32Shift);

				u32ChCtrl2SR |= (		EFTU_DTM_CH_CTRL2_SR_OC0_0_SR(EFTU_DTM_OC_CONSTANT)
									|	EFTU_DTM_CH_CTRL2_SR_OC1_0_SR(EFTU_DTM_OC_CONSTANT)
									| 	EFTU_DTM_CH_CTRL2_SR_POL0_0_SR(FALSE)
									|	EFTU_DTM_CH_CTRL2_SR_POL1_0_SR(FALSE)
									|	EFTU_DTM_CH_CTRL2_SR_SL0_0_SR(pConfig->eOutputLevel)
									|	EFTU_DTM_CH_CTRL2_SR_SL1_0_SR(pConfig->eOutputNLevel)) << u32Shift;
				EFTU_DTM_HWA_SetCTRL2SR(pHandle->tStatus.pDtm, u32ChCtrl2SR);
			}
            /** Apply the temporary variable's value to the CTRL2 register */
			u32Ctrl2 |= (u32Temp | EFTU_DTM_CTRL2_WR_EN_0_MASK) << u32Shift;
			EFTU_DTM_HWA_SetCTRL2(pHandle->tStatus.pDtm, u32Ctrl2);

            /** Enable Individual Shutoff Feature */
			EFTU_DTM_HWA_SetChannelShutOffEnable(pHandle->tStatus.pDtm, TRUE);
#if EFTU_DTM_DEV_ERROR_REPORT == STD_ON
		}
	}
#endif
}

/**
 * @brief Clears the shut-off state of the specified channel.
 *
 * This function clears the shut-off state for an EFTU DTM channel. Before performing this operation,
 * it may perform a development error report to ensure that the provided channel handle is valid.
 *
 * @param pHandle Pointer to the EFTU DTM channel handle
 */
void EFTU_DTM_ClearShutOff(EFTU_Dtm_ChannelHandleType *pHandle)
{
#if EFTU_DTM_DEV_ERROR_REPORT == STD_ON
    /* Validate the channel handle */
	bool bValid = EFTU_DTM_VerifyHandle(pHandle, EFTU_DTM_SET_CHANNEL_SHUTOFF_ID, TRUE);
    /* If the handle is valid, proceed to clear the shut-off state */
	if (TRUE == bValid)
	{
#endif
        /* Call the hardware access layer function to reset the shut-off synchronization state */
		EFTU_DTM_HWA_ResetShutOffSync(EFTU_DTM_CHANNEL(pHandle));
#if EFTU_DTM_DEV_ERROR_REPORT == STD_ON
	}
#endif

}

#endif /* defined(EFTU_INSTANCE_COUNT) && (EFTU_INSTANCE_COUNT > 0) */
