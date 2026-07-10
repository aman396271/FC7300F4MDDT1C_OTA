/**
 * @file module_driver_mb.h
 * @author flagchip
 * @brief Mailbox-SEMA driver type definition and API
 * @version 2.0.0
 * @date 2024-08-20
 *
 * SDK Version: 2.6.0
 *

 * @copyright Copyright (c) 2020-2024 Flagchip Semiconductors Co., Ltd.
 *
 * @details
 */
/* ********************************************************************************
   *   Revision History:
   *
   *   Version     Date          Initials      CR#          Descriptions
   *   ---------   ----------    ------------  ----------   ---------------
   *   0.1.0       2023-12-15    Flagchip070   N/A          First version for FC7300
   *   2.0.0       2024-10-12    Flagchip070   N/A          Change version and release
   ******************************************************************************** */

#ifndef _DRIVER_MODULE_DRIVER_module_driver_sema_H_
#define _DRIVER_MODULE_DRIVER_module_driver_sema_H_

#include "HwA_mb.h"

#if (MB_INSTANCE_COUNT > 0U) && defined(MB_SEMA_EXSIST)

#if defined(__cplusplus)
extern "C" {
#endif

/**
 * @addtogroup module_driver_sema
 * @{
 */

typedef enum
{
	SEMA_STATUS_SUCCESS,
	SEMA_STATUS_FAILED,
	SEMA_STATUS_ERROR,
	SEMA_STATUS_INVALID_MASTER_ID,
	SEMA_STATUS_NO_SEMA,
	SEMA_STATUS_NO_CHECK_VALUE,
	SEMA_STATUS_RESOURCE_LOCKED,
} SEMA_StatusType;

typedef struct
{
	struct
	{
		bool bLockProtect;
	} tStatus;
} Sema_HandleType;

typedef struct
{
	uint8_t u8ResourceID;
	uint8_t u8MasterIdx;
	bool 	bErrorKey;
	bool	bErrorStatus;
} Sema_ErrorStatusType;

void SEMA_Init(Sema_HandleType *pSemaHandle, bool bLockProtect);
SEMA_StatusType SEMA_ResourceGet(Sema_HandleType *pSemaHandle, uint8_t u8ResourceID);
SEMA_StatusType SEMA_ResourceRelease(Sema_HandleType *pSemaHandle, uint8_t u8ResourceID);
void SEMA_GetErrorStatus(Sema_HandleType *pSemaHandle, Sema_ErrorStatusType *pErrorStatus);
#define SEMA_DeInit(h)							MB_HWA_SoftwareResetSema()
#define SEMA_ReleaseAllRource(h, master_idx)	MB_HWA_ReleaseAllSema(master_idx)
#define SEMA_ClearError(h)						MB_HWA_ClearErrorStatus()
/** @}*/ /* module_driver_sema */
#if defined(__cplusplus)
}
#endif

#endif /* #if (MB_INSTANCE_COUNT > 0U) && defined(MB_SEMA_EXSIST) */

#endif
