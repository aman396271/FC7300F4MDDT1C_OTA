/**
 * @file module_driver_sema.c
 * @author flagchip
 * @brief Mailbox-SEMA driver type definition and API
 * @version 2.0.0
 * @date 2024-09-14
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
   *   0.1.0       2024-09-14    Flagchip070   N/A          First version for FC7300
   *   2.4.0	   2025-07-04	 Flagchip070   N/A			Fixed variable name error
   ******************************************************************************** */

#include "module_driver_sema.h"

#if (MB_INSTANCE_COUNT > 0U) && defined(MB_SEMA_EXSIST)

#define SEMA_RSC_ERR_INV_MASTER_ID			0xFF800000u
#define SEMA_RSC_ERR_NO_CHECK_VALUE			0xFFC00000u
#define SEMA_RSC_ERR_NO_SEMA				0xFFE00000u
#define SEMA_RSC_ERR_ALREADY_LOCKED			0xFCFFE000u

#ifndef SEMA_DEV_ERROR_REPORT
#define SEMA_DEV_ERROR_REPORT	STD_ON
#endif
#if SEMA_DEV_ERROR_REPORT == STD_ON
#define SEMA_ReportDevError(func, error) ReportDevError(SEMA_MODULE_ID, func, error)
#endif

void SEMA_Init(Sema_HandleType *pSemaHandle, bool bLockProtect)
{
	pSemaHandle->tStatus.bLockProtect = bLockProtect;
	MB_HWA_ClearErrorStatus();
	if (true == bLockProtect)
	{
		MB_HWA_EnableSemaLockProtect();
	}
	else
	{
		MB_HWA_DisableSemaLockProtect();
	}
}

SEMA_StatusType SEMA_ResourceGet(Sema_HandleType *pSemaHandle, uint8_t u8ResourceID)
{
	SEMA_StatusType eStatus;
	if (true == pSemaHandle->tStatus.bLockProtect)
	{
		MB_HWA_UnlockResource(u8ResourceID);
	}

	uint32_t u32Status = MB_HWA_GetResource(u8ResourceID);
	u32Status &= (~MB_SEMA_RSRC_MASK);
	if (0u == u32Status)
	{
		eStatus = SEMA_STATUS_SUCCESS;
	}
	else if (SEMA_RSC_ERR_INV_MASTER_ID == u32Status)
	{
		eStatus = SEMA_STATUS_INVALID_MASTER_ID;
	}
	else if (SEMA_RSC_ERR_NO_CHECK_VALUE == u32Status)
	{
		eStatus = SEMA_STATUS_NO_CHECK_VALUE;
	}
	else if (SEMA_RSC_ERR_NO_SEMA == u32Status)
	{
		eStatus = SEMA_STATUS_NO_SEMA;
	}
	else if (SEMA_RSC_ERR_ALREADY_LOCKED == u32Status)
	{
		eStatus = SEMA_STATUS_RESOURCE_LOCKED;
	}
	else
	{
		eStatus = SEMA_STATUS_FAILED;
	}

	return eStatus;
}

SEMA_StatusType SEMA_ResourceRelease(Sema_HandleType *pSemaHandle, uint8_t u8ResourceID)
{
	PROCESS_UNUSED_VAR(pSemaHandle);
	MB_HWA_ClearErrorStatus();

	SEMA_StatusType eStatus;
	MB_HWA_ReleaseResource(u8ResourceID);
	uint32_t u32ErrStatus = MB_HWA_GetSemaErrorStatus();
	if (0U != (u32ErrStatus & MB_SEMA_ERROR_STATUS_SEMA_ERR_ST_MASK))
	{
		eStatus = SEMA_STATUS_FAILED;
	}
	else
	{
		eStatus = SEMA_STATUS_SUCCESS;
	}

	return eStatus;
}

void SEMA_GetErrorStatus(Sema_HandleType *pSemaHandle, Sema_ErrorStatusType *pErrorStatus)
{
	PROCESS_UNUSED_VAR(pSemaHandle);
	uint32_t u32ErrStatus = MB_HWA_GetSemaErrorStatus();
	pErrorStatus->u8ResourceID = 	(uint8_t)((u32ErrStatus & MB_SEMA_ERROR_STATUS_SEMA_ERR_RSRC_ID_MASK)
									>> MB_SEMA_ERROR_STATUS_SEMA_ERR_RSRC_ID_SHIFT);
	pErrorStatus->u8MasterIdx = 	(uint8_t)((u32ErrStatus & MB_SEMA_ERROR_STATUS_SEMA_ERR_MID_MASK)
									>> MB_SEMA_ERROR_STATUS_SEMA_ERR_MID_SHIFT);
	pErrorStatus->bErrorKey = 		(bool)((u32ErrStatus & MB_SEMA_ERROR_STATUS_SEMA_ERR_KEY_MASK)
									>> MB_SEMA_ERROR_STATUS_SEMA_ERR_KEY_SHIFT);
	pErrorStatus->bErrorStatus = 	(bool)(u32ErrStatus & MB_SEMA_ERROR_STATUS_SEMA_ERR_ST_MASK);
}

#endif /* (MB_INSTANCE_COUNT > 0U) && defined(MB_SEMA_EXSIST) */

