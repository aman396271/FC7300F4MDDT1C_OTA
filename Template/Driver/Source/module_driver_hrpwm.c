/**
 * @file module_driver_hrpwm.c
 * @author flagchip
 * @brief HRPWM driver source code
 * @version 2.4.0
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
   *   2.4.0	   2025-07-02    Flagchip070   N/A          1. Fixed the issue that HRPWM_DisableChannel
   *                                                           will disable the entire HRPWM
   *                                                        2. Added HRPWM_DeInit
   *                                                        3. Modified Fault-related configurations
   ******************************************************************************** */

#include "module_driver_hrpwm.h"

#if defined(HRPWM_INSTANCE_COUNT) && (HRPWM_INSTANCE_COUNT > 0U)

#ifndef HRPWM_DEV_ERROR_REPORT
#define HRPWM_DEV_ERROR_REPORT	STD_ON
#endif

#if HRPWM_DEV_ERROR_REPORT == STD_ON
#define HRPWM_ReportDevError(func, error) ReportDevError(HRPWM_MODULE_ID, func, error)
#endif

/**
 * Initialize the HRPWM module's analog control settings.
 *
 * @param bUseInternalLDO Whether to use the internal LDO regulator.
 * @param bWaitReady Whether to wait for the module to be ready.
 *
 * This function configures the analog control register of the HRPWM module based on the parameters,
 * including enabling the phase generator and the LDO regulator. If required, it waits for the module to be ready.
 */
void HRPWM_Init(bool bUseInternalLDO, bool bWaitReady)
{
	uint32_t u32Temp = HRPWM_ANA_CTRL_PH_EN_MASK;
	if (TRUE == bUseInternalLDO)
	{
		u32Temp |= HRPWM_ANA_CTRL_PH_LDOEN_MASK;
	}
	HRPWM_HWA_SetANACtrl(HRPWM, u32Temp);
	if (TRUE == bWaitReady)
	{
		bool bReady;
		do
		{
			bReady = HRPWM_GetReady();
		} while (TRUE != bReady);
	}
}

/**
 * De-Initialize the HRPWM module.
 *
 * This function disable the HRPWM module, and recover all the HRPWM registers
 */
void HRPWM_DeInit(void)
{
	HRPWM_HWA_SetANACtrl(HRPWM, 0U);
	HRPWM_HWA_SetENCtrl(HRPWM, 0U);
	HRPWM_HWA_SetBypassCtrl(HRPWM, 0U);
	HRPWM_HWA_SetFltBypassCtrl(HRPWM, 0U);
	HRPWM_HWA_SetFltSWCtrl(HRPWM, 0U);
}

/**
 * Get the readiness status of the HRPWM module.
 *
 * @return Whether the module is ready.
 *
 * This function checks the lock and power OK bits in the analog control register to determine if the module is ready.
 */
bool HRPWM_GetReady(void)
{
	bool bReady;
	const uint32_t u32Mask = HRPWM_ANA_CTRL_PH_LOCK_MASK | HRPWM_ANA_CTRL_ANA_POWER_OK_MASK;
	uint32_t u32Temp = HRPWM_HWA_GetANACtrl(HRPWM);
	if ((u32Temp & u32Mask) != u32Mask)
	{
		bReady = FALSE;
	}
	else
	{
		bReady = TRUE;
	}
	return bReady;
}

/**
 * Enable the HRPWM output for a specified channel.
 *
 * @param u8Channel The channel number to enable.
 * @param eFaultRelease The fault release type.
 *
 * This function enables the HRPWM output for the specified channel, sets the fault release type, and checks if the channel number is valid.
 * If the channel number is invalid, it reports a development error.
 */
void HRPWM_EnableChannel(uint8_t u8Channel, HRPWM_FaultReleaseType eFaultRelease)
{
#if HRPWM_DEV_ERROR_REPORT == STD_ON
	if (u8Channel >= HRPWM_CHANNEL_COUNT)
	{
		HRPWM_ReportDevError(HRPWM_DISABLE_CHANNEL_ID, HRPWM_E_PARAM_CHANNEL);
	}
	else
	{
#endif
		HRPWM_HWA_SetChannelEnable(HRPWM, u8Channel, TRUE);
		HRPWM_HWA_SetChannelBypass(HRPWM, u8Channel, FALSE);
		if (HRPWM_FAULT_RELEASE_BY_EFTU_SIGNAL == eFaultRelease)
		{
			HRPWM_HWA_SetChannelFaultEnable(HRPWM, u8Channel, TRUE);
			HRPWM_HWA_SetSWFaultRelease(HRPWM, u8Channel, FALSE);
		}
		else if (HRPWM_FAULT_RELEASE_BY_SOFTWARE == eFaultRelease)
		{
			HRPWM_HWA_SetChannelFaultEnable(HRPWM, u8Channel, TRUE);
			HRPWM_HWA_SetSWFaultRelease(HRPWM, u8Channel, TRUE);
		}
		else
		{
			HRPWM_HWA_SetChannelFaultEnable(HRPWM, u8Channel, FALSE);
		}
#if HRPWM_DEV_ERROR_REPORT == STD_ON
	}
#endif
}

/**
 * Disable the HRPWM output for a specified channel.
 *
 * @param u8Channel The channel number to disable.
 *
 * This function disables the HRPWM output for the specified channel and checks if the channel number is valid.
 * If the channel number is invalid, it reports a development error.
 */
void HRPWM_DisableChannel(uint8_t u8Channel)
{
#if HRPWM_DEV_ERROR_REPORT == STD_ON
	if (u8Channel >= HRPWM_CHANNEL_COUNT)
	{
		HRPWM_ReportDevError(HRPWM_DISABLE_CHANNEL_ID, HRPWM_E_PARAM_CHANNEL);
	}
	else
	{
#endif
		HRPWM_HWA_SetChannelEnable(HRPWM, u8Channel, FALSE);
#if HRPWM_DEV_ERROR_REPORT == STD_ON
	}
#endif
}

/**
 * Bypass the HRPWM output for a specified channel.
 *
 * @param u8Channel The channel number to bypass.
 *
 * This function bypasses the HRPWM output for the specified channel and checks if the channel number is valid.
 * If the channel number is invalid, it reports a development error.
 */
void HRPWM_BypassChannel(uint8_t u8Channel)
{
#if HRPWM_DEV_ERROR_REPORT == STD_ON
	if (u8Channel >= HRPWM_CHANNEL_COUNT)
	{
		HRPWM_ReportDevError(HRPWM_BYPASS_CHANNEL_ID, HRPWM_E_PARAM_CHANNEL);
	}
	else
	{
#endif
		HRPWM_HWA_SetChannelEnable(HRPWM, u8Channel, TRUE);
		HRPWM_HWA_SetChannelBypass(HRPWM, u8Channel, TRUE);
#if HRPWM_DEV_ERROR_REPORT == STD_ON
	}
#endif
}

#endif /* defined(HRPWM_INSTANCE_COUNT) && (HRPWM_INSTANCE_COUNT > 0U) */
