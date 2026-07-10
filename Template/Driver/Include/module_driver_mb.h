/**
 * @file module_driver_mb.h
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
   *   0.1.0       2023-12-15    Flagchip070   N/A          First version for FC7300
   *   2.0.0       2024-10-12    Flagchip070   N/A          Change version and release
   ******************************************************************************** */

#ifndef _DRIVER_MODULE_DRIVER_module_driver_mb_H_
#define _DRIVER_MODULE_DRIVER_module_driver_mb_H_

#include "HwA_mb.h"

#if MB_INSTANCE_COUNT > 0U

#if defined(__cplusplus)
extern "C" {
#endif

/**
 * @addtogroup module_driver_mb
 * @{
 */


/**
 * @brief Mailbox channel bit flag of security information
 *
 */
#define MB_CHANNEL_STATUS_SECURE		2u

/**
 * @brief Mailbox channel bit flag of processing information
 *
 */
#define MB_CHANNEL_STATUS_PRIVILEGED	1u

/**
 * @name  Mailbox channel bit mask
 * @brief Bit of channel indicate channel number
 *
 * @{
 */
#define MB_CHANNEL_MASK_NONE			0u
#define MB_CHANNEL_MASK_ALL				0xFFFFu
#define MB_CHANNEL_MASK(ch)				((uint32_t)(1ul << (ch)))
/** @}*/

/**
 * @name  MB API Service IDs
 *
 * @{
 */
#define MB_INIT_ID				0U
#define MB_DEINIT_ID			1U
#define MB_LOCK_CHANNEL_ID		2U
#define MB_RELEASE_CHANNEL_ID	3U
#define MB_SEND_REQUEST_ID		4U
#define MB_RECEIVE_CHANNEL_ID	5U
#define MB_UNLOCK_CHANNEL_ID	6U
#define MB_POLL_DONE_ID			7U
#define MB_DONE_CHANNEL_ID		8U
/** @}*/

/**
 * @name  MB Dev Error Code
 * @brief Error Code of calling MB apis
 *
 * @{
 */
#define MB_E_PARAM_CHANNEL   	0x02U
#define MB_E_PARAM_INVALID   	0x03U
#define MB_E_PARAM_POINTER   	0x04U
/** @}*/

/**
 * @brief Mailbox operation return values
 *
 */
typedef enum {
    MB_STATUS_SUCCESS 			= 0u,	/*!< The Mailbox operation is success */
    MB_STATUS_FAILED,					/*!< The Mailbox operation is failed */
	MB_STATUS_PARAM_ERROR,				/*!< The Mailbox operation is failed because of parameter error*/
	MB_STATUS_ALREADY_INITED,			/*!< The Mailbox operation is failed because of
											 Mailbox has already initialized*/
	MB_STATUS_UNINIT,					/*!< The Mailbox operation is failed because of
											 Mailbox has not initialized*/
	MB_STATUS_LOCKED,					/*!< The Mailbox channel is locked */
	MB_STATUS_NO_REQUEST,				/*!< No valid requests */
} MB_StatusType;

/**
 * @brief Configuration of a Mailbox request
 *
 */
typedef struct
{
	uint8_t 	u8Channel;				/*!< The selected Mailbox channel */
	uint8_t		u8TargetCoreIndex;		/*!< Target Core Index */
	bool		bAutoRelease;			/*!< Automatically clear the channel */
	uint32_t	aData[2];				/*!< Sending data */
} MB_RequestType;

/**
 * @brief Configuration of a receiving request
 *
 */
typedef struct
{
	uint8_t		u8Channel;				/*!< The selected Mailbox channel */
	uint8_t		u8MasterCoreIndex;		/*!< Buffer to store the master core index */
	bool		bSecure;				/*!< The master security information of the core that currently obtains the channel */
	bool		bSupervisor;			/*!< The master processing mode of the core that currently obtains the channel. */
	uint32_t	aData[2];				/*!< Buffer to store the receiving data */
} MB_ReceiveType;

typedef struct _MB_HandleType
{
	struct
	{
		uint8_t u8CoreIndex;
		uint8_t u8MasterId;
		void (*pRequestCallback)(struct _MB_HandleType *pHandle, MB_ReceiveType *pReceive);
		void (*pDoneCallback)(struct _MB_HandleType *pHandle, uint32_t u32Channel);
	} tStatus;
} MB_HandleType;

/**
 * @brief Configuration of the Mailbox
 *
 */
typedef struct
{
	uint32_t		u32EventMask;						/*!< Mask for the request events and done events */
	uint32_t		u32IntrMask;						/*!< Mask for enable the interrupts */
	void (*pRequestCallback)(MB_HandleType *pHandle, MB_ReceiveType *pReceive);	/*!< Callback of the request events */
	void (*pDoneCallback)(MB_HandleType *pHandle, uint32_t u32Channel);		/*!< Callback of the done events */
} MB_InitType;

/**
 * @brief Initialize the Mailbox
 * @param pMbHandle Mailbox processing handle
 * @param pInitConfig the configurations of the Mailbox
 *
 */
void MB_Init(MB_HandleType *pMbHandle, const MB_InitType *pInitConfig);
/**
 * @brief De-initialize the Mailbox
 *
 * @param pMbHandle Mailbox processing handle
 */
void MB_DeInit(MB_HandleType *pMbHandle);
/**
 * @brief Attempt to acquire a Mailbox channel
 *
 * @param u32Channel the selected Mailbox channel
 * @return MB_StatusType whether the operation is successfully
 */
MB_StatusType MB_AcquireChannel(uint32_t u32Channel);
/**
 * @brief Release a Mailbox channel
 *
 * @param pMbHandle Mailbox processing handle
 * @param u32Channel the selected Mailbox channel
 * @return MB_StatusType whether the operation is successfully
 */
MB_StatusType MB_ReleaseChannel(MB_HandleType *pMbHandle, uint32_t u32Channel);
/**
 * @brief Software clears channel lock
 *
 * @param u32Channel the selected Mailbox channel
 * @return MB_StatusType whether the operation is successfully
 */
MB_StatusType MB_UnlockChannel(uint32_t u32Channel);
/**
 * @brief Launching a Mailbox request
 *
 * @param pMbHandle Mailbox processing handle
 * @param pRequest Configuration of the request
 * @return MB_StatusType whether the operation is successfully
 */
MB_StatusType MB_SendRequest(MB_HandleType *pMbHandle, MB_RequestType *pRequest);
/**
 * @brief Attempt to receive a request from the selected channel
 *
 * @param pMbHandle Mailbox processing handle
 * @param pReceive Configuration of the receiving request
 * @return MB_StatusType whether the operation is successfully
 */
MB_StatusType MB_ReceiveChannel(MB_HandleType *pMbHandle, MB_ReceiveType *pReceive);
/**
 * @brief Issue a done event to the selected channel
 *
 * @param pMbHandle Mailbox processing handle
 * @param u32Channel the selected Mailbox channel
 * @param u8TargetCoreIndex the target core index
 * @return MB_StatusType whether the operation is successfully
 */
MB_StatusType MB_DoneChannel(MB_HandleType *pMbHandle, uint32_t u32Channel, uint8_t u8TargetCoreIndex);
/**
 * @brief Polling the done event of all channels
 *
 * @param pMbHandle Mailbox processing handle
 * @return uint32_t Done event from the communication channel
 */
uint32_t MB_PollDone(MB_HandleType *pMbHandle);
/**
 * @brief Interrupt IRQ handle of Mailbox
 * @param pMbHandle Mailbox processing handle
 */
void MB_IRQProcess(MB_HandleType *pMbHandle);
/** @}*/ /* module_driver_mb */
#if defined(__cplusplus)
}
#endif

#endif /* #if MB_INSTANCE_COUNT > 0U */

#endif
