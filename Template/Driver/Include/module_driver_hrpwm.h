/**
 * @file module_driver_hrpwm.h
 * @author flagchip
 * @brief HRPWM driver type definition and API
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
   *   0.1.0       2023-12-15    Flagchip070   N/A          First version for FC7300
   *   2.0.0       2024-10-12    Flagchip070   N/A          Change version and release
   ******************************************************************************** */

#ifndef _DRIVER_FC500_DRIVER_HRPWM_H_
#define _DRIVER_FC500_DRIVER_HRPWM_H_
#include "HwA_hrpwm.h"
#if defined(HRPWM_INSTANCE_COUNT) && (HRPWM_INSTANCE_COUNT > 0U)
/**
 * @addtogroup module_driver_hrpwm
 * @{
 */

#if defined(__cplusplus)
extern "C" {
#endif

/**
 * @name  EFTU_DTM API Service IDs
 *
 * @{
 */
#define HRPWM_INIT_CHANNEL_ID			0U
#define HRPWM_DISABLE_CHANNEL_ID		1U
#define HRPWM_BYPASS_CHANNEL_ID			2U
/** @}*/

/**
 * @name  EFTU_DTM Dev Error Code
 * @brief Error Code of calling EFTU_DTM apis
 *
 * @{
 */
#define HRPWM_E_PARAM_CHANNEL			0U
#define HRPWM_E_PARAM_INVALID			1U
/** @}*/


/**
 * @brief Selection of Fault Release by Software Control
 *
 */
typedef enum
{
	HRPWM_FAULT_RELEASE_BY_EFTU_SIGNAL,   			/* The fault bypass release occurs by a fault signal from EFTU,
                                                       without software. */
	HRPWM_FAULT_RELEASE_BY_SOFTWARE,                /* The fault bypass release occurs by software writing FAULT_STATUS. */
	HRPWM_FAULT_DISABLE,							/* The HRPWM fault disable */
} HRPWM_FaultReleaseType;

void HRPWM_Init(bool bUseInternalLDO, bool bWaitReady);
void HRPWM_DeInit(void);
bool HRPWM_GetReady(void);
void HRPWM_EnableChannel(uint8_t u8Channel, HRPWM_FaultReleaseType eFaultRelease);
void HRPWM_DisableChannel(uint8_t u8Channel);
void HRPWM_BypassChannel(uint8_t u8Channel);
#define HRPWM_SoftwareReleaseFault(m)	HRPWM_HWA_ClearFaultStatus(HRPWM, m)
#define HRPWM_GetFaultStatus()			HRPWM_HWA_GetFaultStatus(HRPWM)

#endif /* defined(HRPWM_INSTANCE_COUNT) && (HRPWM_INSTANCE_COUNT > 0U) */
#endif  /* _DRIVER_FC500_DRIVER_HRPWM_H_ */
