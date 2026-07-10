/**
 * @file        module_driver_eim.h
 * @author      Flagchip0100
 * @brief       FC7xxx EIM driver type definition and API
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

#ifndef _DRIVER_MODULE_DRIVER_EIM_H_
#define _DRIVER_MODULE_DRIVER_EIM_H_

#include "HwA_eim.h"

#if (EIM_INSTANCE_COUNT > 0U)

/**
 * @addtogroup module_driver_eim
 * @{
 */

#if defined(__cplusplus)
extern "C" {
#endif

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/**
 * @name  EIM API Service IDs
 * @{
 */
#define EIM_INIT_ID                     0x00U
#define EIM_DEINIT_ID                   0x01U
#define EIM_DISABLEINJECTION_ID         0x02U
/** @}*/

/**
 * @name  EIM Dev Error Code
 * @{
 */
#define EIM_E_PARAM_NULLPTR             0x01U
#define EIM_E_PARAM_INSTANCE            0x02U
/**@}*/

/** 
 * @name Define EIM monitor configuration type
 * @{
 */
#define EIM_LOCKSTEP_MONITOR0           0U      /**< Lockstep Monitor0 Error Injection */
#define EIM_LOCKSTEP_MONITOR1           1U      /**< Lockstep Monitor1 Error Injection */
/** @}*/

/**
 * @name Error injection bus select
 *
 */
#define EIM_BUSREG_0                    0U      /**< Sel bus REG0 to injection */
#define EIM_BUSREG_1                    1U      /**< Sel bus REG1 to injection */
#define EIM_BUSREG_2                    2U      /**< Sel bus REG2 to injection */
#define EIM_BUSREG_3                    3U      /**< Sel bus REG3 to injection */
/** @}*/


/**
 * @brief EIM Instance type.
 *
 */
typedef enum
{
    EIM_INSTANCE_0   = 0U,
} EIM_InstanceType;


/**
 * @brief EIM operation return values.
 *
 */
typedef enum
{
    EIM_STATUS_SUCCESS = 0U,     /*!< The EIM status success */
    EIM_STATUS_FAIL    = 1U,     /*!< The EIM status fail */
} EIM_StatusType;

/**
 * @brief The structure of the EIM processing handle
 *
 */
typedef struct _EIM_HandleType
{
    EIM_InstanceType eInstance;     /*!< EIM instance*/
    uint8_t _aligned[3U];
    struct {
        uint8_t u8EimChn;
        uint8_t _aligned[3U];
    } tStatus;
} EIM_HandleType;

/**
 * @brief Define the max EIM channels
 *
 */
typedef struct
{
    uint8_t u8EimChn;           /**< EIM channel No, See EIM channel number define and EIM lockstep channel define */
    uint8_t u8BusSelIdx;        /**< EIM error bus No, See Error injection bus sel */
    uint8_t u8Attreenable;      /**< EIM attribute error injection enable or not */
    uint8_t u8AttrPosition;     /**< EIM attribute error injection position */
    uint8_t u8Addreenable;      /**< EIM address error injection enable or not */
    uint8_t u8AddrePosition;    /**< EIM address error injection position */
    uint8_t u8Data0enable;      /**< EIM data0 error injection enable or not */
    uint8_t u8Data0Val;         /**< EIM data0 error injection position */
    uint8_t u8Data1enable;      /**< EIM data1 error injection enable or not */
    uint8_t u8Data1Val;         /**< EIM data1 error injection position */
    uint8_t u8MonNum;           /**< EIM monitor No, See EIM monitor configuration type */
    uint8_t u8DwpMode;          /**< EIM dwp mode, See EIM DWP mode */
} EIM_ChCfgType;

/*******************************************************************************
 * API
 ******************************************************************************/

/**
 * @brief Initializes the Error Injection Module(EIM) with provided configuration settings.
 *
 * This function sets up the EIM module according to the configuration specified in `pInitCfg`.
 * It configures the word channels (WORD0 and WORD1), enables the selected EIM channel, and activates
 * global error injection if supported. Error checking is performed to ensure valid pointers and EIM instance.
 *
 * @param pHandle A pointer to the EIM handle structure which identifies the EIM instance to initialize.
 * @param pInitCfg A pointer to the initialization configuration structure (`EIM_ChCfgType`) defining setup parameters for the EIM module.
 *
 * @return `EIM_STATUS_SUCCESS` if the initialization was successful, otherwise `EIM_STATUS_FAIL`.
 *
 * @note The error reporting macros are conditionally compiled based on `EIM_DEV_ERROR_REPORT` definition.
 */
EIM_StatusType EIM_Init(EIM_HandleType *const pHandle, const EIM_ChCfgType *const pInitCfg);

/**
 * @brief Deinitializes the Error Injection Module(EIM).
 *
 * This function disables the EIM module by clearing all channel configurations, disabling global error injection,
 * and resetting the word channel registers to their default state. Error checking is performed to ensure a valid EIM instance.
 *
 * @param pHandle A pointer to the EIM handle structure identifying the EIM instance to deinitialize.
 *
 * @note The error reporting macros are conditionally compiled based on `EIM_DEV_ERROR_REPORT` definition.
 */
void EIM_Deinit(EIM_HandleType *const pHandle);

/**
 * @brief Disables error injection in the EIM module.
 *
 * This function disables error injection in the specified EIM module instance. For lockstep channels, it sets the lockstep configuration.
 *
 * @param pHandle Pointer to the EIM handle structure.
 *
 * @note If the handle pointer is NULL or the instance index is out of range, a device error will be reported.
 */
void EIM_DisableInjection(EIM_HandleType *const pHandle);

/** @} */ /* module_driver_eim */

#if defined(__cplusplus)
}
#endif

#endif /* (EIM_INSTANCE_COUNT > 0U) */

#endif /* _DRIVER_MODULE_DRIVER_EIM_H_ */
