/**
 * @file module_driver_mb.c
 * @author flagchip
 * @brief Mailbox driver type definition and API
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
   *   0.1.0       2022-11-15    Flagchip070   N/A          First version for FC7300
   ******************************************************************************** */

#include "module_driver_mb.h"

#if MB_INSTANCE_COUNT > 0U

#ifndef MB_DEV_ERROR_REPORT
#define MB_DEV_ERROR_REPORT	STD_ON
#endif
#if MB_DEV_ERROR_REPORT == STD_ON
#define MB_ReportDevError(func, error) ReportDevError(MB_MODULE_ID, func, error)
#endif
/********* Local variable ************/

static const uint8_t s_aMasterIdTab[MB_INTR_CHANNEL_COUNT] = MB_MASTER_ID_TABLE;

/******* Local Function Prototype *********/
static void MB_GetMasterCoreStatus(MB_ReceiveType *pReceive);
static uint32_t MB_GetMasterCoreIndex(uint32_t u32MasterId);
/******* Local Function *********/
static void MB_GetMasterCoreStatus(MB_ReceiveType *pReceive)
{
	if (MB_HWA_GetSemaphore(pReceive->u8Channel, MB_CCn_SEMA_LOCK_MASTER_SEC_MASK))
	{
		pReceive->bSecure = true;
	}
	else
	{
		pReceive->bSecure = false;
	}
	if (MB_HWA_GetSemaphore(pReceive->u8Channel, MB_CCn_SEMA_LOCK_MASTER_SUPERVISOR_MASK))
	{
		pReceive->bSupervisor = true;
	}
	else
	{
		pReceive->bSupervisor = false;
	}
}

/**
 * @brief Convert core master id to index
 *
 * @param u32MasterId Core master ID
 *
 */
static uint32_t MB_GetMasterCoreIndex(uint32_t u32MasterId)
{
	uint32_t u32Index = 0;
	uint32_t u32Loop;
	for(u32Loop = 0; u32Loop < MB_INTR_CHANNEL_COUNT; u32Loop++)
	{
		if(s_aMasterIdTab[u32Loop] == u32MasterId)
		{
			u32Index = u32Loop;
			break;
		}
	}
	return u32Index;
}

/********* Global Functions ************/

/**
 * @brief Initialize the Mailbox
 * @param pMbHandle Mailbox processing handle
 * @param pInitConfig the configurations of the Mailbox
 *
 */
void MB_Init(MB_HandleType *pMbHandle, const MB_InitType *pInitConfig)
{
	/* Get Core Index*/
	pMbHandle->tStatus.u8CoreIndex = Cpm_HWA_GetCoreId();
	pMbHandle->tStatus.u8CoreIndex = pMbHandle->tStatus.u8CoreIndex >= MB_CORE_INDEX_HSM ? (pMbHandle->tStatus.u8CoreIndex + 1U) : pMbHandle->tStatus.u8CoreIndex;
	pMbHandle->tStatus.u8MasterId = s_aMasterIdTab[pMbHandle->tStatus.u8CoreIndex];
	/*Registering callback functions*/
	pMbHandle->tStatus.pRequestCallback = pInitConfig->pRequestCallback;
	pMbHandle->tStatus.pDoneCallback = pInitConfig->pDoneCallback;

	MB_HWA_UnlockIntrReg(pMbHandle->tStatus.u8CoreIndex, \
						MB_INTn_CTRL_FLG_LOCK_MASK | MB_INTn_CTRL_FLG_MASK_LOCK_MASK | MB_INTn_CTRL_INTEN_LOCK_MASK);

	/*Configure the event mask*/
	MB_HWA_ConfigFlagMask(pMbHandle->tStatus.u8CoreIndex, pInitConfig->u32EventMask);
	/*Clear interrupt flag*/
	MB_HWA_ClearFlag(pMbHandle->tStatus.u8CoreIndex, MB_INTn_FLG_MASK_MASK);
	/*Enable event interrupts */
	MB_HWA_ConfigIntrEnable(pMbHandle->tStatus.u8CoreIndex, pInitConfig->u32IntrMask);
	MB_HWA_LockIntrReg(	pMbHandle->tStatus.u8CoreIndex, \
						MB_INTn_CTRL_FLG_LOCK_MASK | MB_INTn_CTRL_FLG_MASK_LOCK_MASK | MB_INTn_CTRL_INTEN_LOCK_MASK);

}

/**
 * @brief De-initialize the Mailbox
 *
 * @param pMbHandle Mailbox processing handle
 */
void MB_DeInit(MB_HandleType *pMbHandle)
{
	MB_HWA_UnlockIntrReg(pMbHandle->tStatus.u8CoreIndex, \
						MB_INTn_CTRL_FLG_LOCK_MASK | MB_INTn_CTRL_FLG_MASK_LOCK_MASK | MB_INTn_CTRL_INTEN_LOCK_MASK);
	/*Disable all event interrupts and flag*/
	MB_HWA_ConfigFlagMask(pMbHandle->tStatus.u8CoreIndex, 0);
	MB_HWA_ConfigIntrEnable(pMbHandle->tStatus.u8CoreIndex, 0);
	/*Clear interrupt flag*/
	MB_HWA_ClearFlag(pMbHandle->tStatus.u8CoreIndex, MB_INTn_FLG_MASK_MASK);
	MB_HWA_LockIntrReg(pMbHandle->tStatus.u8CoreIndex, \
						MB_INTn_CTRL_FLG_LOCK_MASK | MB_INTn_CTRL_FLG_MASK_LOCK_MASK | MB_INTn_CTRL_INTEN_LOCK_MASK);
}

/**
 * @brief Attempt to acquire a Mailbox channel
 *
 * @param u32Channel the selected Mailbox channel
 * @return MB_StatusType whether the operation is successfully
 */
MB_StatusType MB_AcquireChannel(uint32_t u32Channel)
{
	MB_StatusType eStatus = MB_STATUS_SUCCESS;
#if MB_DEV_ERROR_REPORT == STD_ON
	if(u32Channel >= MB_COM_CHANNEL_COUNT)
	{
		eStatus = MB_STATUS_PARAM_ERROR;
		MB_ReportDevError(MB_LOCK_CHANNEL_ID, MB_E_PARAM_CHANNEL);
	}
	else
	{
#endif
		/*Read SEMA to lock the selected channel*/
		if(0u == MB_HWA_GetSemaphore(u32Channel, MB_CCn_SEMA_LOCK_MASK))
		{
			eStatus = MB_STATUS_LOCKED;
		}
#if MB_DEV_ERROR_REPORT == STD_ON
	}
#endif
	return eStatus;
}

/**
 * @brief Release a Mailbox channel
 *
 * @param pMbHandle Mailbox processing handle
 * @param u32Channel the selected Mailbox channel
 * @return MB_StatusType whether the operation is successfully
 */
MB_StatusType MB_ReleaseChannel(MB_HandleType *pMbHandle, uint32_t u32Channel)
{
	MB_StatusType eStatus = MB_STATUS_SUCCESS;
	uint32_t u32MasterId;
#if MB_DEV_ERROR_REPORT == STD_ON
	if(u32Channel >= MB_COM_CHANNEL_COUNT)
	{
		eStatus = MB_STATUS_PARAM_ERROR;
		MB_ReportDevError(MB_RECEIVE_CHANNEL_ID, MB_E_PARAM_CHANNEL);
	}
	else
	{
#endif
		/*Check the master core of the channel*/
		u32MasterId = MB_HWA_GetMasterID(u32Channel);
		if(u32MasterId == pMbHandle->tStatus.u8MasterId)
		{
			/*Release the selected channel*/
			MB_HWA_ReleaseChannel(u32Channel);
		}
		else
		{
			eStatus = MB_STATUS_FAILED;
		}
#if MB_DEV_ERROR_REPORT == STD_ON
	}
#endif
	return eStatus;
}

/**
 * @brief Software clears channel lock
 *
 * @param u32Channel the selected Mailbox channel
 * @return MB_StatusType whether the operation is successfully
 */
MB_StatusType MB_UnlockChannel(uint32_t u32Channel)
{
	MB_StatusType eStatus = MB_STATUS_SUCCESS;
#if MB_DEV_ERROR_REPORT == STD_ON
	if(u32Channel >= MB_COM_CHANNEL_COUNT)
	{
		eStatus = MB_STATUS_PARAM_ERROR;
		MB_ReportDevError(MB_UNLOCK_CHANNEL_ID, MB_E_PARAM_CHANNEL);
	}
	else
	{
#endif
		MB_HWA_UnlockChannel(u32Channel);
#if MB_DEV_ERROR_REPORT == STD_ON
	}
#endif
	return eStatus;
}

/**
 * @brief Launching a Mailbox request
 *
 * @param pMbHandle Mailbox processing handle
 * @param pRequest Configuration of the request
 * @return MB_StatusType whether the operation is successfully
 */
MB_StatusType MB_SendRequest(MB_HandleType *pMbHandle, MB_RequestType *pRequest)
{
	MB_StatusType eStatus;
#if MB_DEV_ERROR_REPORT == STD_ON
	if (pRequest == NULL)
	{
		eStatus = MB_STATUS_PARAM_ERROR;
		MB_ReportDevError(MB_SEND_REQUEST_ID, MB_E_PARAM_POINTER);
	}
	else if (pRequest->u8Channel >= MB_COM_CHANNEL_COUNT)
	{
		eStatus = MB_STATUS_PARAM_ERROR;
		MB_ReportDevError(MB_SEND_REQUEST_ID, MB_E_PARAM_CHANNEL);
	}
	else if (!MB_CORE_INDEX_VALID(pRequest->u8TargetCoreIndex))
	{
		eStatus = MB_STATUS_PARAM_ERROR;
		MB_ReportDevError(MB_SEND_REQUEST_ID, MB_E_PARAM_INVALID);
	}
	else
	{
#endif
		/*Read SEMA to lock the selected channel*/
		if(0u == MB_HWA_GetSemaphore((uint32_t)pRequest->u8Channel, MB_CCn_SEMA_LOCK_MASK))
		{
			eStatus = MB_STATUS_LOCKED;
		}
		else
		{
			uint32_t u32DoneMask = (uint32_t)(1U << pMbHandle->tStatus.u8CoreIndex);
			MB_HWA_ConfigDoneMasterId(pRequest->u8Channel, s_aMasterIdTab[pRequest->u8TargetCoreIndex]);
			MB_HWA_ConfigDoneMask(pRequest->u8Channel, u32DoneMask);
			if (pRequest->bAutoRelease)
			{
				MB_HWA_ConfigAutoUnlock(pRequest->u8Channel, u32DoneMask);
			}
			else
			{
				MB_HWA_ConfigAutoUnlock(pRequest->u8Channel, 0U);
			}
			MB_HWA_WriteData(pRequest->u8Channel, pRequest->aData);
			MB_HWA_ConfigRequest(pRequest->u8Channel, (uint32_t)(1U << pRequest->u8TargetCoreIndex));
			eStatus = MB_STATUS_SUCCESS;
		}
#if MB_DEV_ERROR_REPORT == STD_ON
	}
#endif
	return eStatus;
}

/**
 * @brief Attempt to receive a request from the selected channel
 *
 * @param pMbHandle Mailbox processing handle
 * @param pReceive Configuration of the receiving request
 * @return MB_StatusType whether the operation is successfully
 */
MB_StatusType MB_ReceiveChannel(MB_HandleType *pMbHandle, MB_ReceiveType *pReceive)
{
	MB_StatusType eStatus = MB_STATUS_SUCCESS;
	uint32_t u32Flag;
#if MB_DEV_ERROR_REPORT == STD_ON
	if (pReceive->u8Channel >= MB_COM_CHANNEL_COUNT)
	{
		eStatus = MB_STATUS_PARAM_ERROR;
		MB_ReportDevError(MB_RECEIVE_CHANNEL_ID, MB_E_PARAM_CHANNEL);
	}
	else
	{
#endif
		uint8_t u8CoreIndex = pMbHandle->tStatus.u8CoreIndex;
		u32Flag = MB_HWA_GetFlag(u8CoreIndex, MB_EVENT_REQ(pReceive->u8Channel));
		if(0u != u32Flag)
		{
			MB_HWA_UnlockFlag(u8CoreIndex);
			/* Clear events flag */
			MB_HWA_ClearFlag(u8CoreIndex, u32Flag);
			MB_HWA_LockFlag(u8CoreIndex);
			/* receiving data */
			MB_HWA_GetData(pReceive->u8Channel, pReceive->aData);
			/* get the security information and processing mode */
			MB_GetMasterCoreStatus(pReceive);
			/*get the master core index of the request*/
			volatile uint32 u32Rvalue = MB_HWA_GetMasterID(pReceive->u8Channel);

			uint32_t u32CoreIndex;
			__asm volatile("rbit %1,%0" : "=r"(u32Rvalue) : "r"(u32Rvalue));
			__asm volatile("clz %0,%1" : "=r"(u32CoreIndex) : "r"(u32Rvalue));
			pReceive->u8MasterCoreIndex = (uint8_t)(u32CoreIndex & 0x3);
		}
		else
		{
			eStatus = MB_STATUS_NO_REQUEST;
		}
#if MB_DEV_ERROR_REPORT == STD_ON
	}
#endif
	return eStatus;
}

/**
 * @brief Issue a done event to the selected channel
 *
 * @param pMbHandle Mailbox processing handle
 * @param u32Channel the selected Mailbox channel
 * @param u8TargetCoreIndex the target core index
 * @return MB_StatusType whether the operation is successfully
 */
MB_StatusType MB_DoneChannel(MB_HandleType *pMbHandle, uint32_t u32Channel, uint8_t u8TargetCoreIndex)
{
	MB_StatusType eStatus = MB_STATUS_SUCCESS;
	uint32_t u32DoneMasterId, u32DoneMaskAllow;
#if MB_DEV_ERROR_REPORT == STD_ON
	if (u32Channel >= MB_COM_CHANNEL_COUNT)
	{
		eStatus = MB_STATUS_PARAM_ERROR;
		MB_ReportDevError(MB_DONE_CHANNEL_ID, MB_E_PARAM_CHANNEL);
	}
	else
	{
#endif
		/* Check the done master of the channel*/
		u32DoneMasterId = MB_HWA_GetDoneMasterId(u32Channel);
		if(u32DoneMasterId == pMbHandle->tStatus.u8MasterId)
		{
			/* Check if the done mask is allowed */
			uint32_t u32DoneMask = (uint32_t)(1U << u8TargetCoreIndex);
			u32DoneMaskAllow = MB_HWA_GetDoneMask(u32Channel);
			if((u32DoneMaskAllow & u32DoneMask) == u32DoneMask)
			{
				/* issue a done event */
				MB_HWA_SetDone(u32Channel, u32DoneMask);
			}
			else
			{
				eStatus = MB_STATUS_FAILED;
			}
		}
		else
		{
			eStatus = MB_STATUS_FAILED;
		}
#if MB_DEV_ERROR_REPORT == STD_ON
	}
#endif
	return eStatus;
}

/**
 * @brief Polling the done event of all channels
 *
 * @param pMbHandle Mailbox processing handle
 * @return uint32_t Done event from the communication channel
 */
uint32_t MB_PollDone(MB_HandleType *pMbHandle)
{
	uint32_t u32DoneFlag = 0;
	uint8_t u8CoreIndex = pMbHandle->tStatus.u8CoreIndex;
	u32DoneFlag = MB_HWA_GetFlag(u8CoreIndex, MB_EVENT_ALL_DONE);
	if(0u != u32DoneFlag)
	{
		MB_HWA_UnlockFlag(u8CoreIndex);
		/* Clear done flag */
		MB_HWA_ClearFlag(pMbHandle->tStatus.u8CoreIndex, u32DoneFlag);
		MB_HWA_LockFlag(u8CoreIndex);
		u32DoneFlag = u32DoneFlag >> MB_INTn_FLG_DONE_FLAG_SHIFT;
	}

	return u32DoneFlag;
}

/**
 * @brief Interrupt IRQ handle of Mailbox
 * @param pMbHandle Mailbox processing handle
 */
void MB_IRQProcess(MB_HandleType *pMbHandle)
{
	uint8_t u8CoreIndex = pMbHandle->tStatus.u8CoreIndex;
	uint32_t u32FlagStat = MB_HWA_GetFlagStat(u8CoreIndex, MB_INTn_FLG_STAT_MASK);
	uint32_t u32Index, u32MasterCore;

	MB_HWA_UnlockFlag(u8CoreIndex);
	MB_HWA_ClearFlag(u8CoreIndex, u32FlagStat);
	MB_HWA_LockFlag(u8CoreIndex);
	for(u32Index = 0; u32Index < MB_COM_CHANNEL_COUNT; u32Index++)
	{
		/* get the master core index of the channel*/
		u32MasterCore = MB_HWA_GetMasterID(u32Index);
		u32MasterCore = MB_GetMasterCoreIndex(u32MasterCore);
		if(0u != (u32FlagStat & ((uint32_t)1u << u32Index)))
		{
			/* request event */
			if(NULL != pMbHandle->tStatus.pRequestCallback)
			{
				MB_ReceiveType tReceive;
				tReceive.u8Channel = (uint8_t)u32Index;
				MB_GetMasterCoreStatus(&tReceive);
				tReceive.u8MasterCoreIndex = (uint8_t)u32MasterCore;
				MB_HWA_GetData(u32Index, tReceive.aData);
				/* call the request callback*/
				pMbHandle->tStatus.pRequestCallback(pMbHandle, &tReceive);
			}
		}
		if ((NULL != pMbHandle->tStatus.pDoneCallback) &&
				(0u != (u32FlagStat & ((uint32_t)1u << (u32Index + MB_INTn_FLG_DONE_FLAG_SHIFT)))))
		{
			pMbHandle->tStatus.pDoneCallback(pMbHandle, u32Index);
		}
	}
}

#endif /* #if MB_INSTANCE_COUNT > 0U */

