/**
 * @file        module_driver_freqm.h
 * @author      Flagchip0100
 * @brief       FREQM module driver type definition and API
 * @version 2.0.0
 * @date        2024-08-20
 *
 * SDK Version: 2.6.0
 *

 * @copyright   Copyright 2020-2024 Flagchip Semiconductors Co., Ltd.
 */

/* ********************************************************************************
   *   Revision History:
   *
   *   Version     Date          Initials      CR#          Descriptions
   *   ---------   ----------    ------------  ----------   ---------------
   *   0.1.0       2023-12-15    Flagchip087   N/A          First version for FC7300
   *   2.0.0       2024-10-12    Flagchip087   N/A          Change version and release
   ******************************************************************************** */

#ifndef _DRIVER_MODULE_DRIVER_FREQM_H_
#define _DRIVER_MODULE_DRIVER_FREQM_H_

#include "HwA_freqm.h"

#if (FREQM_INSTANCE_COUNT > 0U)

#if defined(__cplusplus)
extern "C" {
#endif

/**
 * @addtogroup module_driver_freqm
 * @{
 */

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/**
 * @name  FREQM API Service IDs
 * @{
 */
#define FREQM_INIT_ID                   0x00U
#define FREQM_DEINIT_ID                 0x01U
#define FREQM_STARTMEASURE_ID           0x02U
#define FREQM_CLEARSTATUS_ID            0x03U
#define FREQM_COMMONIRQHANDLER_ID       0x04U
/**@}*/

/**
 * @name  FREQM Dev Error Code
 * @brief Error Code of calling FREQM apis
 * @{
 */
#define FREQM_E_PARAM_NULLPTR           0x01U
#define FREQM_E_PARAM_INSTANCE          0x02U
/**@}*/

/** 
 * @brief FREQM Instance type.
 * 
 */
typedef enum
{
    FREQM_INSTANCE_0   = 0U,
} FREQM_InstanceType;

/**
 * @brief FREQM operation return values.
 *
 */
typedef enum
{
    FREQM_STATUS_SUCCESS  = 0x0U,         /**< The FREQM status success */
    FREQM_STATUS_FAIL     = 0x1U,         /**< The FREQM status fail */
    FREQM_STATUS_TIMEOUT  = 0x2U,         /**< The FREQM status timeout */
} FREQM_StatusType;

/**
 * @brief The structure of the FREQM processing handle
 *
 */
typedef struct _FREQM_HandleType
{
    FREQM_InstanceType eInstance;         /**< FREQM instance*/
    uint8_t _aligned[3U];

    struct
    {
        void (*pMesCntStartCallback)(struct _FREQM_HandleType *pHandle, uint32_t u32Value);
        void (*pMesCntStopCallback)(struct _FREQM_HandleType *pHandle, uint32_t u32Value);
        void (*pRefCntStopCallback)(struct _FREQM_HandleType *pHandle);
        void (*pErrorCallback)(struct _FREQM_HandleType *pHandle);
    } tSettings;
} FREQM_HandleType;

/**
 * @brief FREQM configure structure.
 *
 */
typedef struct
{
    uint32_t    u32MesLen;
    uint32_t    u32RefTo;
    uint8_t     u8ClkSel;           /**< clock measure select, See freqm measured clock define */
    uint8_t     u8PredivVal;        /**< Frequency of the Reload Opportunities. Range is 0-31, */
    uint8_t     _aligned[2U];
} FREQM_CfgType;

/*******************************************************************************
 * API
 ******************************************************************************/

/**
 * @brief Initializes the FREQM module with the specified configuration.
 *
 * This function initializes the FREQM module with the given configuration settings, including the clock divider value,
 * the clock source to be measured, the measurement length, and the reference timeout.
 *
 * @param pHandle Pointer to the FREQM handle structure.
 * @param pInitStruct Pointer to the initialization structure containing the configuration settings.
 *
 * @return FREQM_StatusType Indicates the status of the initialization process (FREQM_STATUS_SUCCESS or FREQM_STATUS_FAIL).
 *
 * @note If any of the required pointers are NULL or the instance index is out of range, a device error will be reported,
 * and the function returns FREQM_STATUS_FAIL.
 */
FREQM_StatusType FREQM_Init(FREQM_HandleType *const pHandle, const FREQM_CfgType *const pInitStruct);

/**
 * @brief Deinitializes the FREQM module.
 *
 * This function deinitializes the specified FREQM module instance by resetting its configuration settings to default
 * values and disabling the counter event interrupt.
 *
 * @param pHandle Pointer to the FREQM handle structure.
 *
 * @return FREQM_StatusType Indicates the status of the deinitialization process (FREQM_STATUS_SUCCESS or FREQM_STATUS_FAIL).
 *
 * @note If the handle pointer is NULL or the instance index is out of range, a device error will be reported, and the
 * function returns FREQM_STATUS_FAIL.
 */
FREQM_StatusType FREQM_DeInit(FREQM_HandleType *pHandle);

/**
 * @brief Starts the frequency measurement process in the FREQM module.
 *
 * This function starts the frequency measurement process by resetting the measurement counter to zero.
 *
 * @param pHandle Pointer to the FREQM handle structure.
 *
 * @return FREQM_StatusType Indicates the status of the start measurement process (FREQM_STATUS_SUCCESS or FREQM_STATUS_FAIL).
 *
 * @note If the handle pointer is NULL or the instance index is out of range, a device error will be reported, and the function
 * returns FREQM_STATUS_FAIL.
 */
FREQM_StatusType FREQM_StartMeasure(FREQM_HandleType *pHandle);

/**
 * @brief Clears the status of the FREQM module.
 *
 * This function clears the status of the specified FREQM module instance by resetting the reference counter and waiting for
 * the counters to stop.
 *
 * @param pHandle Pointer to the FREQM handle structure.
 *
 * @return FREQM_StatusType Indicates the status of the clear status operation (FREQM_STATUS_SUCCESS or FREQM_STATUS_FAIL).
 *
 * @note If the handle pointer is NULL or the instance index is out of range, a device error will be reported, and the function
 * returns FREQM_STATUS_FAIL.
 */
FREQM_StatusType FREQM_ClearStatus(FREQM_HandleType *pHandle);

/**
 * @brief Handles common interrupts for the FREQM module.
 *
 * This function processes the common interrupts for the specified FREQM module instance. It checks the interrupt flags and calls
 * the appropriate callback functions based on the interrupt status.
 *
 * @param pHandle Pointer to the FREQM handle structure.
 *
 * @note If the handle pointer is NULL or the instance index is out of range, a device error will be reported.
 */
void FREQM_CommonIRQHandler(FREQM_HandleType *const pHandle);

/** @}*/ /* module_driver_freqm */

#if defined(__cplusplus)
}
#endif

#endif /* (FREQM_INSTANCE_COUNT > 0U) */

#endif /* _DRIVER_MODULE_DRIVER_FREQM_H_ */
