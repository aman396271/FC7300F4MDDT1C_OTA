/**
 * @file HwA_mb.h
 * @author flagchip
 * @brief Mailbox hardware access layer
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
   *   0.1.0      2023-12-15     Flagchip070   N/A          First version for FC7300
   *   2.0.0      2024-10-12     Flagchip070   N/A          Change version and release
   ******************************************************************************** */

#ifndef _HWA_MAILBOX_H_
#define _HWA_MAILBOX_H_
#include "device_header.h"

#if MB_INSTANCE_COUNT > 0U

/**
 * @defgroup HwA_mb HwA_mb
 * @ingroup module_driver_mb
 * @{
 */

/**
 * @brief The definition of mask all events
 *
 */
#define MB_EVENT_NONE			0u
/**
 * @brief The definition of receiving all events
 *
 */
#define MB_EVENT_ALL			0xFFFFFFFFu
/**
 * @brief The definition of receiving all request events
 *
 */
#define MB_EVENT_ALL_REQ		0x0000FFFFu
/**
 * @brief The definition of receiving all done events
 *
 */
#define MB_EVENT_ALL_DONE		0xFFFF0000u
/**
 * @brief The definition of request events on ch
 *
 */
#define MB_EVENT_REQ(ch)		(uint32_t)((uint32_t)1u << (ch))
/**
 * @brief The definition of done events on ch
 *
 */
#define MB_EVENT_DONE(ch)		(uint32_t)((uint32_t)1u << ((ch) + MB_INTn_FLG_MASK_DONE_FLAG_MASK_SHIFT))
/**
 * @brief The definition of issue to no core
 *
 */
#define MB_CORE_MASK_CORE_NONE	0u
/**
 * @brief The definition of issue to core 0
 *
 */
#define MB_CORE_MASK_CORE_0		1u
/**
 * @brief The definition of issue to core 1
 *
 */
#define MB_CORE_MASK_CORE_1		2u
/**
 * @brief The definition of issue to core 2
 *
 */
#define MB_CORE_MASK_CORE_2		4u
/**
 * @brief The definition of issue to HSM
 *
 */
#define MB_CORE_MASK_HSM		8u
/**
 * @brief The definition of issue to all cores
 *
 */
#define MB_CORE_MASK_ALL		0xFu
/**
 * @brief The definition of issue to core
 *
 */
#define MB_CORE_MASK(core)		(uint32_t)(1ul << (core))

/**
 * @brief Lock the MB_INTn registers
 *
 * @param u8CoreIndex the index of the core
 * @param u32Mask the lock bits
 */
LOCAL_INLINE void MB_HWA_LockIntrReg(uint8_t u8CoreIndex, uint32_t u32Mask)
{
	MB->INTR[u8CoreIndex].CCn_CTRL |= u32Mask;
}

/**
 * @brief Unlock the MB_INTn registers
 *
 * @param u8CoreIndex the index of the core
 * @param u32Mask the unlock bits
 */
LOCAL_INLINE void MB_HWA_UnlockIntrReg(uint8_t u8CoreIndex, uint32_t u32Mask)
{
	MB->INTR[u8CoreIndex].CCn_CTRL &= ~u32Mask;
}

/**
 * @brief Lock the MB_INTn_FLG
 *
 * @param u8CoreIndex the index of the core
 */
LOCAL_INLINE void MB_HWA_LockFlag(uint8_t u8CoreIndex)
{
	MB->INTR[u8CoreIndex].CCn_CTRL |= MB_INTn_CTRL_FLG_LOCK_MASK;
}

/**
 * @brief Unlock the MB_INTn_FLG
 *
 * @param u8CoreIndex the index of the core
 */
LOCAL_INLINE void MB_HWA_UnlockFlag(uint8_t u8CoreIndex)
{
	MB->INTR[u8CoreIndex].CCn_CTRL &= ~MB_INTn_CTRL_FLG_LOCK_MASK;
}

/**
 * @brief Lock the MB_INTn_FLG_MASK
 *
 * @param u8CoreIndex the index of the core
 */
LOCAL_INLINE void MB_HWA_LockFlagMask(uint8_t u8CoreIndex)
{
	MB->INTR[u8CoreIndex].CCn_CTRL |= MB_INTn_CTRL_FLG_MASK_LOCK_MASK;
}

/**
 * @brief Unlock the MB_INTn_FLG_MASK
 *
 * @param u8CoreIndex the index of the core
 */
LOCAL_INLINE void MB_HWA_UnlockFlagMask(uint8_t u8CoreIndex)
{
	MB->INTR[u8CoreIndex].CCn_CTRL &= ~MB_INTn_CTRL_FLG_MASK_LOCK_MASK;
}

/**
 * @brief Lock the MB_INTn_INTEN
 *
 * @param u8CoreIndex the index of the core
 */
LOCAL_INLINE void MB_HWA_LockInten(uint8_t u8CoreIndex)
{
	MB->INTR[u8CoreIndex].CCn_CTRL |= MB_INTn_CTRL_INTEN_LOCK_MASK;
}

/**
 * @brief Unlock the MB_INTn_INTEN
 *
 * @param u8CoreIndex the index of the core
 */
LOCAL_INLINE void MB_HWA_UnlockInten(uint8_t u8CoreIndex)
{
	MB->INTR[u8CoreIndex].CCn_CTRL &= ~MB_INTn_CTRL_INTEN_LOCK_MASK;
}

/**
 * @brief Configure receive events of mailbox interrupt channel
 *
 * @param u8CoreIndex the index of the core
 * @param u32Mask configuration for receiving events
 */
LOCAL_INLINE void MB_HWA_ConfigFlagMask(uint8_t u8CoreIndex, uint32_t u32Mask)
{
	MB->INTR[u8CoreIndex].CCn_FLG_MASK = u32Mask;
}

/**
 * @brief Enable receive events of mailbox interrupt channel
 *
 * @param u8CoreIndex the index of the core
 * @param u32Mask indicates the events to be enabled
 */
LOCAL_INLINE void MB_HWA_EnableEvent(uint8_t u8CoreIndex, uint32_t u32Mask)
{
	MB->INTR[u8CoreIndex].CCn_FLG_MASK |= u32Mask;
}

/**
 * @brief Disable receive events of mailbox interrupt channel
 *
 * @param u8CoreIndex the index of the core
 * @param u32Mask indicates the events to be enabled
 */
LOCAL_INLINE void MB_HWA_DisableEvent(uint8_t u8CoreIndex, uint32_t u32Mask)
{
	MB->INTR[u8CoreIndex].CCn_FLG_MASK &= ~u32Mask;
}

/**
 * @brief Configure the interrupt of mailbox interrupt channel
 *
 * @param u8CoreIndex the index of the core
 * @param u32Mask configuration for interrupts
 */
LOCAL_INLINE void MB_HWA_ConfigIntrEnable(uint8_t u8CoreIndex, uint32_t u32Mask)
{
	MB->INTR[u8CoreIndex].CCn_INTEN = u32Mask;
}

/**
 * @brief Enable the interrupt of mailbox interrupt channel
 *
 * @param u8CoreIndex the index of the core
 * @param u32Mask indicates the interrupts to be enabled
 */
LOCAL_INLINE void MB_HWA_EnableIntr(uint8_t u8CoreIndex, uint32_t u32Mask)
{
	MB->INTR[u8CoreIndex].CCn_INTEN |= u32Mask;
}

/**
 * @brief Disable the interrupt of mailbox interrupt channel
 *
 * @param u8CoreIndex the index of the core
 * @param u32Mask indicates the interrupts to be disabled
 */
LOCAL_INLINE void MB_HWA_DisableIntr(uint8_t u8CoreIndex, uint32_t u32Mask)
{
	MB->INTR[u8CoreIndex].CCn_INTEN &= ~u32Mask;
}

/**
 * @brief Clear the flag of mailbox interrupt channel
 *
 * @param u8CoreIndex the index of the core
 * @param u32Mask indicates the flags to be cleared
 */
LOCAL_INLINE void MB_HWA_ClearFlag(uint8_t u8CoreIndex, uint32_t u32Mask)
{
	MB->INTR[u8CoreIndex].CCn_FLG = u32Mask;
}

/**
 * @brief Get the flag masks of mailbox interrupt channel
 *
 * @param u8CoreIndex the index of the core
 * @param u32Mask the mask to get
 * @return the flag masks of the mailbox interrupt channel
 */
LOCAL_INLINE uint32_t MB_HWA_GetFlagMask(uint8_t u8CoreIndex, uint32_t u32Mask)
{
	return MB->INTR[u8CoreIndex].CCn_FLG_MASK & u32Mask;
}

/**
 * @brief Get the flags of mailbox interrupt channel
 *
 * @param u8CoreIndex the index of the core
 * @param u32Mask the mask to get
 * @return the flags of the mailbox interrupt channel
 */
LOCAL_INLINE uint32_t MB_HWA_GetFlag(uint8_t u8CoreIndex, uint32_t u32Mask)
{
	return MB->INTR[u8CoreIndex].CCn_FLG & u32Mask;
}

/**
 * @brief Get the result of flag & inten of mailbox interrupt channel
 *
 * @param u8CoreIndex the index of the core
 * @param u32Mask the mask to get
 * @return the result of flag & inten of the mailbox interrupt channel
 */
LOCAL_INLINE uint32_t MB_HWA_GetFlagStat(uint8_t u8CoreIndex, uint32_t u32Mask)
{
	return MB->INTR[u8CoreIndex].CCn_FLG_STAT & u32Mask;
}

/**
 * @brief Get the master ID of the currently obtained channel
 *
 * @param u32Channel the index of the channel
 * @return the master ID
 */
LOCAL_INLINE uint32_t MB_HWA_GetMasterID(uint32_t u32Channel)
{
	return (MB->CHANNEL[u32Channel].CCn_STAT & MB_CCn_STAT_CURRENT_LOCK_MASTER_ID_MASK) >> MB_CCn_STAT_CURRENT_LOCK_MASTER_ID_SHIFT;
}

/**
 * @brief Send data to the mailbox channel
 *
 * @param u32Channel the index of the channel
 * @param pData the buffer to be written
 */
LOCAL_INLINE void MB_HWA_WriteData(uint32_t u32Channel, uint32_t *pData)
{
	MB->CHANNEL[u32Channel].CCn_DATA0 = pData[0];
	MB->CHANNEL[u32Channel].CCn_DATA1 = pData[1];
}

/**
 * @brief Receive data from the mailbox channel
 *
 * @param u32Channel the index of the channel
 * @param pData the buffer to receive data
 */
LOCAL_INLINE void MB_HWA_GetData(uint32_t u32Channel, uint32_t *pData)
{
	pData[0] = MB->CHANNEL[u32Channel].CCn_DATA0;
	pData[1] = MB->CHANNEL[u32Channel].CCn_DATA1;
}

/**
 * @brief Get the automatically clear status of the mailbox channel
 *
 * @param u32Channel the index of the channel
 * @param u8CoreIndex the index of the core
 * @return automatically clear the channel lock enable bit
 */
LOCAL_INLINE uint32_t MB_HWA_GetAutoClear(uint32_t u32Channel, uint8_t u8CoreIndex)
{
	return MB->CHANNEL[u32Channel].CCn_SEMA_UNLK & ((uint32_t)1u << u8CoreIndex);
}

/**
 * @brief Release the mailbox channel
 *
 * @param u32Channel the index of the channel
 */
LOCAL_INLINE void MB_HWA_ReleaseChannel(uint32_t u32Channel)
{
	MB->CHANNEL[u32Channel].CCn_DONE = MB_MASTER_DONE_CODE;
}

/**
 * @brief Software clears channel lock
 *
 * @param u32Channel the index of the channel
 */
LOCAL_INLINE void MB_HWA_UnlockChannel(uint32_t u32Channel)
{
	MB->CHANNEL[u32Channel].CCn_CLR = MB_FORCE_UNLOCK_CODE;
}

/**
 * @brief Issue a done event
 *
 * @param u32Channel the index of the channel
 * @param u32DoneMask the cores to issue
 */
LOCAL_INLINE void MB_HWA_SetDone(uint32_t u32Channel, uint32_t u32DoneMask)
{
	MB->CHANNEL[u32Channel].CCn_DONE |= (u32DoneMask & MB_CCn_DONE_MASK);
}

/**
 * @brief Get the Communication Channel Semaphore Register
 *
 * @param u32Channel the index of the channel
 * @return Channel Lock Acquisition
 */
LOCAL_INLINE uint32_t MB_HWA_GetSemaphore(uint32_t u32Channel, uint32_t u32Mask)
{
	return MB->CHANNEL[u32Channel].CCn_SEMA & u32Mask;
}

/**
 * @brief Configure the master ID of the core that generates a done event
 *
 * @param u32Channel the index of the channel
 * @param u32MasterId master ID
 */
LOCAL_INLINE void MB_HWA_ConfigDoneMasterId(uint32_t u32Channel, uint32_t u32MasterId)
{
	MB->CHANNEL[u32Channel].CCn_DONE_MASK = (MB->CHANNEL[u32Channel].CCn_DONE_MASK & (~MB_CCn_DONE_MASK_DONE_MASTER_ID_MASK)) \
											| 	MB_CCn_DONE_MASK_DONE_MASTER_ID(u32MasterId);
}

/**
 * @brief Get the master ID of the core that generates a done event
 *
 * @param u32Channel the index of the channel
 * @return the master ID
 */
LOCAL_INLINE uint32_t MB_HWA_GetDoneMasterId(uint32_t u32Channel)
{
	return (MB->CHANNEL[u32Channel].CCn_DONE_MASK & MB_CCn_DONE_MASK_DONE_MASTER_ID_MASK) \
			>> MB_CCn_DONE_MASK_DONE_MASTER_ID_SHIFT;

}

/**
 * @brief Configure the mask of the done events
 *
 * @param u32Channel the index of the channel
 * @param u32DoneMask the cores to issue
 */
LOCAL_INLINE void MB_HWA_ConfigDoneMask(uint32_t u32Channel, uint32_t u32DoneMask)
{
	MB->CHANNEL[u32Channel].CCn_DONE_MASK = (MB->CHANNEL[u32Channel].CCn_DONE_MASK & (~MB_CCn_DONE_MASK)) | \
					(u32DoneMask & MB_CCn_DONE_MASK);
}

/**
 * @brief Get the mask of the done events
 *
 * @param u32Channel the index of the channel
 * @return the mask of the done events
 */
LOCAL_INLINE uint32_t MB_HWA_GetDoneMask(uint32_t u32Channel)
{
	return MB->CHANNEL[u32Channel].CCn_DONE_MASK & MB_CCn_DONE_MASK;
}

/**
 * @brief Configure the automatically clear of the lock enable bit
 *
 * @param u32Channel the index of the channel
 * @param u32AutoUnlockMask the automatically clear of the lock enable bit
 */
LOCAL_INLINE void MB_HWA_ConfigAutoUnlock(uint32_t u32Channel, uint32_t u32AutoUnlockMask)
{
	MB->CHANNEL[u32Channel].CCn_SEMA_UNLK = u32AutoUnlockMask & MB_CCn_SEMA_UNLK_MASK;
}

/**
 * @brief Issue request events
 *
 * @param u32Channel the index of the channel
 * @param u32RequestMask the cores to issue
 */
LOCAL_INLINE void MB_HWA_ConfigRequest(uint32_t u32Channel, uint32_t u32RequestMask)
{
	MB->CHANNEL[u32Channel].CCn_REQUEST = u32RequestMask & MB_CCn_REQUEST_MASK;
}

#ifdef MB_SEMA_EXSIST
/**
 * @brief Function to get the semaphore status
 * 
 * This function retrieves the status of a semaphore specified by the identifier u32Sema.
 * It accesses the SEMAn_STATUS array of a predefined MB object, which contains the status values of all semaphores.
 * 
 * @param u32Sema Semaphore identifier used to specify the semaphore whose status is to be retrieved.
 * @return uint32_t Returns the status value of the specified semaphore.
 * 
 */
LOCAL_INLINE uint32_t MB_HWA_GetSemaStatus(uint32_t u32Sema)
{
    return MB->SEMAn_STATUS[u32Sema];
}

/**
 * @brief  Get semaphore lock status
 * 
 * @param u32Sema  Semaphore identifier
 * 
 * @return bool    Returns the semaphore lock status
 * 
 * @note   This function checks the specific bit in the SEMAn_STATUS register to determine if the semaphore is locked
 */
LOCAL_INLINE bool MB_HWA_GetSemaLock(uint32_t u32Sema)
{
    return (bool)(MB->SEMAn_STATUS[u32Sema] & MB_SEMAn_STATUS_SEMA_FLG_MASK);
}
/**
 * @brief Get the master ID of a semaphore
 * 
 * @param u32Sema Semaphore identifier used to select the specific semaphore status register
 * @return uint8_t The master ID of the semaphore
 */
LOCAL_INLINE uint8_t MB_HWA_GetSemaMasterID(uint32_t u32Sema)
{
    return (uint8_t)((MB->SEMAn_STATUS[u32Sema] & MB_SEMAn_STATUS_SEMA_MID_MASK) >> MB_SEMAn_STATUS_SEMA_MID_SHIFT);
}

/**
 * @brief Get Semaphore Resource ID
 * 
 * @param u32Sema Semaphore index, indicating which semaphore register to use.
 * @return uint8_t Semaphore resource ID.
 */
LOCAL_INLINE uint8_t MB_HWA_GetSemaResourceID(uint32_t u32Sema)
{
    return (uint8_t)((MB->SEMAn_STATUS[u32Sema] & MB_SEMAn_STATUS_SEMA_RSRC_ID_MASK) >> MB_SEMAn_STATUS_SEMA_RSRC_ID_SHIFT);
}

/**
 * @brief Get the global semaphore status
 * 
 * @return uint16_t The current global semaphore status value
 */
LOCAL_INLINE uint16_t MB_HWA_GetSemaGlobalStatus(void)
{
    return (uint16_t)(MB->SEMA_GLOBAL_STATUS & MB_SEMA_GLOBAL_STATUS_MASK);
}

/**
 * @brief Enable semaphore lock protection
 * 
 */
LOCAL_INLINE void MB_HWA_EnableSemaLockProtect(void)
{
    MB->SEMA_CTRL &= ~MB_SEMA_CTRL_MASK;
}

/**
 * @brief Disable semaphore lock protection
 * 
 */
LOCAL_INLINE void MB_HWA_DisableSemaLockProtect(void)
{
    MB->SEMA_CTRL |= MB_SEMA_CTRL_MASK;
}

/**
 * @brief Get the SEMA error status register value
 * 
 * @return uint32_t The current value of the SEMA error status register
 */
LOCAL_INLINE uint32_t MB_HWA_ReadSemaErrorStatus(void)
{
    return MB->SEMA_ERROR_STATUS;
}

/**
 * @brief Get Semaphore Error Resource ID
 * 
 * @return uint8_t The value of the semaphore error resource ID
 */
LOCAL_INLINE uint8_t MB_HWA_GetSemaErrorResourceID(void)
{
    return (uint8_t)((MB->SEMA_ERROR_STATUS & MB_SEMA_ERROR_STATUS_SEMA_ERR_RSRC_ID_MASK) >> MB_SEMA_ERROR_STATUS_SEMA_ERR_RSRC_ID_SHIFT);
}

/**
 * @brief Get Semaphore Master ID
 * 
 * @return uint8_t The value of the semaphore error master ID
 */
LOCAL_INLINE uint8_t MB_HWA_GetSemaErrorMasterID(void)
{
    return (uint8_t)((MB->SEMA_ERROR_STATUS & MB_SEMA_ERROR_STATUS_SEMA_ERR_MID_MASK) >> MB_SEMA_ERROR_STATUS_SEMA_ERR_MID_SHIFT);
}

/**
 * @brief Get Semaphore Error Status
 * 
 * @return uint8_t The value of the semaphore error status
 */
LOCAL_INLINE uint32_t MB_HWA_GetSemaErrorStatus(void)
{
    return MB->SEMA_ERROR_STATUS;
}

/**
 * @brief Sets the software reset signal for the MB module
 * 
 */
LOCAL_INLINE void MB_HWA_SoftwareResetSema(void)
{
    MB->SEMA_SW_RESET = MB_SEMA_KEY_SW_RESET;
}

/**
 * @brief Release all semaphores
 * 
 * @param u8MasterId The Master Index used to identify the resource to be acquired, the value should be 0~4
 */
LOCAL_INLINE void MB_HWA_ReleaseAllSema(uint8_t u8MasterIdx)
{
    MB->SEMA_RELEASE = MB_SEMA_KEY_RELEASE_ALL | (uint32_t)(u8MasterIdx & 0x7u);
}

/**
 * @brief Acquire a resource by its ID
 * 
 * @param u32ResourceID The resource ID used to identify the resource to be acquired
 */
LOCAL_INLINE uint32_t MB_HWA_GetResource(uint32_t u32ResourceID)
{
    return MB->SEMA_RSRC[u32ResourceID];
}

/**
 * @brief Unlocks the specified resource
 * 
 * This function unlocks the resource identified by u32ResourceID by setting the associated semaphore key to an unlocked state.
 * 
 * @param u32ResourceID The resource identifier used to specify the resource to unlock
 */
LOCAL_INLINE void MB_HWA_UnlockResource(uint32_t u32ResourceID)
{
    MB->SEMA_RSRC[u32ResourceID] = MB_SEMA_KEY_UNLOCK;
}

LOCAL_INLINE void MB_HWA_ReleaseResource(uint32_t u32ResourceID)
{
	MB->SEMA_RSRC[u32ResourceID] = MB_SEMA_KEY_RELEASE;
}

/**
 * @brief Clear error status function
 * 
 * Sets the status flag for the specified resource ID to the key value that clears the error status.
 * 
 */
LOCAL_INLINE void MB_HWA_ClearErrorStatus(void)
{
    MB->SEMA_ERROR_STATUS = MB_SEMA_KEY_CLEAR_ERROR;
}
#endif

/** @}*/

#endif /* #if MB_INSTANCE_COUNT > 0U */

#endif

