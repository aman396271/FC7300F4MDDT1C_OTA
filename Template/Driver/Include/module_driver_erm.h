/**
 * @file        module_driver_erm.h
 * @author      Flagchip0100
 * @brief       ERM Module driver type definition and API
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
   *   0.1.0       2023-12-15    Flagchip052   N/A          First version for FC7300
   *   2.0.0       2024-10-12    Flagchip052   N/A          Change version and release
   ******************************************************************************** */

#ifndef _DRIVER_MODULE_DRIVER_ERM_H_
#define _DRIVER_MODULE_DRIVER_ERM_H_

#include "HwA_erm.h"

#if (ERM_INSTANCE_COUNT > 0U)

#if defined(__cplusplus)
extern "C" {
#endif

/**
 * @addtogroup module_driver_erm
 * @{
 */

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/**
 * @name  ERM API Service IDs
 * @{
 */
#define ERM_INIT_ID                     0x00U
#define ERM_DEINIT_ID                   0x01U
#define ERM_COMMONIRQHANDLER_ID         0x02U
/**@}*/

/**
 * @name  ERM Dev Error Code
 * @brief Error Code of calling ERM apis
 * @{
 */
#define ERM_E_PARAM_NULLPTR             0x01U
#define ERM_E_PARAM_INSTANCE            0x02U
/**@}*/

/**
 * @brief ERM error interrupt define.
 * @{
 */
#define ERM_NON_CORRECTABLE_IRQ         1U      /**< select Non-correctable interrupt report */
#define ERM_SINGLE_CORRECTION_IRQ       2U      /**< select single correction interrupt report */
/**@}*/


/**
 * @brief ERM Instance type.
 *
 */
typedef enum
{
    ERM_INSTANCE_0   = 0U,
} ERM_InstanceType;


/**
 * @brief ERM operation return values.
 *
 */
typedef enum
{
    ERM_STATUS_SUCCESS = 0U,     /**< The ERM status success */
    ERM_STATUS_FAIL    = 1U,     /**< The ERM status fail */
} ERM_StatusType;

/**
 * @brief The structure of the ERM processing handle
 *
 */
typedef struct _ERM_HandleType
{
    ERM_InstanceType eInstance;     /**< CMU instance*/
    uint8_t _aligned[3U];

    struct
    {
        void (*pErrorCallback[ERM_EAR_REG_COUNT])(struct _ERM_HandleType *pHandle, uint8_t u8ErrorType, uint32_t u32Addr);
    } tSettings;
} ERM_HandleType;

/**
 * @brief The structure of the ERM Init configuration
 *
 */
typedef struct
{
    uint8_t u8Channel;      /**< ERM channel No, See ERM Channel define */
    uint8_t u8IntType;      /**< ERM Interrupt type, See ERM error interrupt define */
    uint8_t u8ErmEnable;    /**< Enable/Disable Erm channel interrupt */
    uint8_t _aligned[1U];
} ERM_CfgType;

/*******************************************************************************
 * API
 ******************************************************************************/

/**
 * @brief Initializes the Error Reporting Module (ERM) for the specified instance
 *
 * This function initializes the ERM module with the provided configuration structure.
 * It performs parameter validation, sets up the control register based on the configuration,
 * and clears the status. If an error occurs or the handle is invalid, an error report will
 * be generated, and the function will return a failure status.
 *
 * @param pHandle Pointer to an ERM handle structure containing the instance information
 * @param pInitCfg Pointer to an ERM configuration structure with desired settings
 *
 * @return Status of the initialization operation
 *         - ERM_STATUS_SUCCESS: Initialization successful
 *         - ERM_STATUS_FAIL: Initialization failed due to an error
 *
 * @note Error reporting is enabled when `ERM_DEV_ERROR_REPORT` is set to `STD_ON`.
 */
ERM_StatusType ERM_Init(ERM_HandleType *const pHandle, const ERM_CfgType *const pInitCfg);

/**
 * @brief Deinitializes the ERM module.
 *
 * This function deinitializes the specified ERM module instance by clearing its control and status registers.
 *
 * @param pHandle Pointer to the ERM handle structure.
 *
 * @return ERM_StatusType Indicates the status of the operation (ERM_STATUS_SUCCESS or ERM_STATUS_FAIL).
 *
 * @note If the handle pointer is NULL or the instance index is out of range, a device error will be reported, and the function returns ERM_STATUS_FAIL.
 */
ERM_StatusType ERM_DeInit(ERM_HandleType *const pHandle);

/**
 * @brief Handles common Error Reporting Module (ERM) interrupts and invokes error callbacks
 *
 * This function serves as the common interrupt handler for the ERM, checking for errors in various channels
 * (CTCM, DTCM, PFLASH, optionally DFLASH, and DMA) and invoking the error callback function when an error
 * is detected. It also clears the status flags after processing the interrupts.
 *
 * @param pHandle Pointer to an ERM handle structure containing the instance information and error callback
 *
 * @note This function is designed to be used within an interrupt context.
 * @note Support for DFLASH depends on the compile-time configuration `ERM_DFLASH_SUPPORT`.
 */
void ERM_CommonIRQHandler(ERM_HandleType *const pHandle);

/** @} */ /* module_driver_erm */

#if defined(__cplusplus)
}
#endif

#endif /* (ERM_INSTANCE_COUNT > 0U) */

#endif /* _DRIVER_MODULE_DRIVER_ERM_H_ */
