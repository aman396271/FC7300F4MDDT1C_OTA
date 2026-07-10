/**
 * @file        module_driver_fcsmu.h
 * @author      Flagchip0100
 * @brief       FCSMU module driver type definition and API
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
   *   0.1.0       2023-12-15    Flagchip084   N/A          First version for FC7300
   *   2.0.0       2024-10-12    Flagchip100   N/A          Change version and release
   ******************************************************************************** */

#ifndef _DRIVER_MODULE_DRIVER_FCSMU_H_
#define _DRIVER_MODULE_DRIVER_FCSMU_H_

#include "HwA_fcsmu.h"

#if (FCSMU_INSTANCE_COUNT > 0U)

#if defined(__cplusplus)
extern "C" {
#endif

/**
 * @addtogroup module_driver_fcsmu
 * @{
 */

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/**
 * @name  FCSMU API Service IDs
 * @{
 */
#define FCSMU_INIT_ID                   0x00U
#define FCSMU_DEINIT_ID                 0x01U
#define FCSMU_STATUSOUTPUTINIT_ID       0x02U
#define FCSMU_STATUSOUTPUTDEINIT_ID     0x03U
#define FCSMU_GETFAULTCHANNEL_ID        0x04U
#define FCSMU_CLEARFAULT_ID             0x05U
#define FCSMU_INJECTIONFAULT_ID         0x06U
#define FCSMU_CRCINIT_ID                0x07U
#define FCSMU_CRCDEINIT_ID              0x08U
#define FCSMU_CRCGEN_ID                 0x09U
#define FCSMU_CRCISBUSY_ID              0x0AU
#define FCSMU_CRCCLEARBUSY_ID           0x0BU
#define FCSMU_CRCGETRESULT_ID           0x0CU
#define FCSMU_COMMONIRQHANDLER_ID       0x0DU

/**@}*/

/**
 * @name  FCSMU Dev Error Code
 * @brief Error Code of calling FCSMU apis
 * @{
 */
#define FCSMU_E_PARAM_NULLPTR           0x01U
#define FCSMU_E_PARAM_INSTANCE          0x02U
/**@}*/

/**
 * @brief FCSMU operation status define.
 * @{
 */
#define FCSMU_OP_STATE_IDLE             0U      /**< FCSMU operation status idle */
#define FCSMU_OP_STATE_BUSY             1U      /**< FCSMU operation status busy */
#define FCSMU_OP_STATE_FAILED           2U      /**< FCSMU operation status failed */
#define FCSMU_OP_STATE_SUCCESSFUL       3U      /**< FCSMU operation status successful */
/**@}*/

/**
 * @brief FCSMU operation code define.
 * @{
 */
#define FCSMU_OP_CODE_NONE              0U      /**< FCSMU operation code none */
#define FCSMU_OP_CODE_MOVE_TO_CONFIG    1U      /**< FCSMU operation code move to configuration state */
#define FCSMU_OP_CODE_MOVE_TO_NORMAL    2U      /**< FCSMU operation code move to normal state */
#define FCSMU_OP_CODE_CLEAR_FAULT_INFO  13U     /**< FCSMU operation code clear fault channel information register */
#define FCSMU_OP_CODE_CLEAR_OPS_TO_IDLE 15U     /**< FCSMU operation code clear ops to idle */
/**@}*/

/**
 * @brief FCSMU SOUT Control define.
 * @{
 */
#define FCSMU_SOUT_CTRL_BY_FSM              0U      /**< SOUT is controlled by the FSM. */
#define FCSMU_SOUT_CTRL_KEEP_LOW            1U      /**< SOUT keeps low. */
#define FCSMU_SOUT_CTRL_BY_FSM2             2U      /**< SOUT is controlled by the FSM. */
#define FCSMU_SOUT_CTRL_KEEP_HIGH_THEN_FSM  3U      /**< SOUT keeps high until a fault occures on a channel, then controlled by FSM. */
/**@}*/

/**
 * @brief FCSMU SOUT Polarity Switch define.
 * @{
 */
#define FCSMU_SOUT_DEFAUT_POLARITY      0U      /**< Default polarity. */
#define FCSMU_SOUT_SWITCH_POLARITY      1U      /**< Switch polarity. */
/**@}*/

/**
 * @brief FCSMU SOUT Protocol define.
 * @{
 */
#define FCSMU_SOUT_PROTOCOL_DUAL_RAIL       0U
#define FCSMU_SOUT_PROTOCOL_TIME_SWITCH     1U
#define FCSMU_SOUT_PROTOCOL_BISTABLE        2U
#define FCSMU_SOUT_PROTOCOL_FAULT_TOGGLE    3U
#define FCSMU_SOUT_PROTOCOL_TIME_DUAL_RAIL  4U
#define FCSMU_SOUT_PROTOCOL_DIAG0           5U
#define FCSMU_SOUT_PROTOCOL_DIAG1           6U
#define FCSMU_SOUT_PROTOCOL_DIAG2           7U
/**@}*/

/**
 * @brief FCSMU state in state register define.
 * @{
 */
#define FCSMU_STATE_NORMAL              0U      /**< FCSMU state normal */
#define FCSMU_STATE_CONGIG              1U      /**< FCSMU state config */
#define FCSMU_STATE_WARN                2U      /**< FCSMU state warn */
#define FCSMU_STATE_FAULT               3U      /**< FCSMU state fault */
/**@}*/

/**
 * @brief FCSMU fault tolerance time define.
 * @{
 */
#define FCSMU_FAULT_TOLERANCE_TIME_1MS  0U
#define FCSMU_FAULT_TOLERANCE_TIME_2MS  1U
#define FCSMU_FAULT_TOLERANCE_TIME_5MS  2U
#define FCSMU_FAULT_TOLERANCE_TIME_10MS 3U
/**@}*/

/**
 * @brief FCSMU crc Status define.
 * @{
 */
#define FCSMU_CRC_STATE_IDLE            0U      /**< FCSMU crc status idle */
#define FCSMU_CRC_STATE_BUSY            1U      /**< FCSMU crc status busy */
/**@}*/

/**
 * @brief FCSMU crc mode define.
 * @{
 */
#define FCSMU_CRC_SW_MODE               0U      /**< FCSMU crc software mode. */
#define FCSMU_CRC_TRIGGER_MODE          1U      /**< FCSMU crc trigger mode. */
/**@}*/

/**
 * @brief FCSMU crc error request mode define.
 * @{
 */
#define FCSMU_CRC_ERROR_REQ_MODE_NONE   0U
#define FCSMU_CRC_ERROR_REQ_MODE_IRQ    1U
#define FCSMU_CRC_ERROR_REQ_MODE_RST    2U
/**@}*/


/**
 * @brief FCSMU Instance type.
 *
 */
typedef enum
{
    FCSMU_INSTANCE_0 = 0U,
} FCSMU_InstanceType;

/**
 * @brief FCSMU operation return values.
 *
 */
typedef enum
{
    FCSMU_STATUS_SUCCESS    = 0U,  /**< FCSMU operation is succeed. */
    FCSMU_STATUS_FAIL       = 1U,  /**< FCSMU operation is failed. */
    FCSMU_STATUS_TIMEOUT    = 2U,  /**< FCSMU operation is timeout. */
} FCSMU_StatusType;

/**
 * @brief FCSMU init configure structure.
 *
 */
typedef struct
{
    uint32_t u32FaultChannel;           /**< FCSMU fault channel. */
    uint32_t u32WarnTo;                 /**< FCSMU warning timeoout value. */
    uint32_t u32WarnChannel;            /**< FCSMU warning channel. */
    uint32_t u32WarnInterruptChannel;   /**< FCSMU warning interrupt channel. */
    uint32_t u32FaultInterruptChannel;  /**< FCSMU fault interrupt channel. */
    uint32_t u32FaultResetChannel;      /**< FCSMU fault reset channel. */
    uint32_t u32SoftwareClearedChannel; /**< FCSMU fault is Cleard by software. */
} FCSMU_InitCfgType;

/**
 * @brief FCSMU status output pin configure structure.
 *
 */
typedef struct
{
    bool bEnable;                       /**< Enable or disable status output. */
    bool bFastMode;                     /**< Enable or disable fast mode. */
    uint8_t u8SoutCtrl;                 /**< Configure Sout Control. */
    uint8_t u8Polarity;                 /**< Status output polarity. */
    uint32_t u32Protocal;               /**< Status output protocal. */
    uint32_t u32Delaytimer;             /**< Configure the safe mode request delay in cycles of CLKSAFE. */
    uint32_t u32Divder;                 /**< Configure the status output divider ratio. SOUT_freq = CLKSAFE_freq/((SOUT_DIV+1)*2*256)*/
    uint32_t u32SoutChannel;            /**< Configure the status output channel. */
    uint32_t u32SoutMinTmrInterval;     /**< Minimum SOUT Timer Interval */

    /* The following variables are only used for FC7300F8MDQ and FC7240 */
    bool bDivex;                        /**< Enable or disable SOUT Divider Extend Control. */
    bool bSoutMinTmr;                   /**< SOUT Minimum Timer Enable */
    uint8_t u8FttiTime;                 /**< Fault Tolerance Time */
    uint8_t _aligned;
} FCSMU_StatusOutputCfgType;

/**
 * @brief FCSMU CRC configure structure.
 *
 */
typedef struct
{
    uint16_t u16ErrorReqMode;
    uint16_t u16Mode;
} FCSMU_CrcCfgType;

/**
 * @brief The structure of the FCSMU processing handle
 *
 */
typedef struct _FCSMU_HandleType
{
    FCSMU_InstanceType eInstance;     /* FCSMU instance*/
    uint8_t _aligned[3U];
    struct {
        void (*pFaultCallback)(struct _FCSMU_HandleType *pHandle, uint32_t u32IrqChannel);
        void (*pWarningCallback)(struct _FCSMU_HandleType *pHandle, uint32_t u32IrqChannel);
        void (*pTimeoutCallback)(struct _FCSMU_HandleType *pHandle);
    } tSettings;
} FCSMU_HandleType;

/*******************************************************************************
 * API
 ******************************************************************************/

/**
 * @brief Initializes the FCSMU module.
 *
 * This function initializes the specified FCSMU module instance by transitioning the state to the configuration state,
 * configuring the module according to the provided initialization configuration, and then transitioning back to the normal state.
 *
 * @param pHandle Pointer to the FCSMU handle structure.
 * @param pInitCfg Pointer to the FCSMU initialization configuration structure.
 *
 * @return FCSMU_StatusType Indicates the status of the initialization process (FCSMU_STATUS_SUCCESS or FCSMU_STATUS_FAIL).
 *
 * @note If the handle pointer, initialization configuration pointer, or instance index is invalid,
 * a device error will be reported, and the function returns FCSMU_STATUS_FAIL.
 */
FCSMU_StatusType FCSMU_Init(FCSMU_HandleType *const pHandle, const FCSMU_InitCfgType *const pInitCfg);

/**
 * @brief Deinitializes the FCSMU module.
 *
 * This function deinitializes the specified FCSMU module instance by transitioning the state to the configuration state,
 * resetting the configuration settings, and then transitioning back to the normal state.
 *
 * @param pHandle Pointer to the FCSMU handle structure.
 *
 * @return FCSMU_StatusType Indicates the status of the deinitialization process (FCSMU_STATUS_SUCCESS or FCSMU_STATUS_FAIL).
 *
 * @note If the handle pointer or instance index is invalid, a device error will be reported, and the function returns FCSMU_STATUS_FAIL.
 */
FCSMU_StatusType FCSMU_Deinit(FCSMU_HandleType *const pHandle);

/**
 * @brief Initializes the status output configuration for the FCSMU module.
 *
 * This function initializes the status output configuration for the specified FCSMU module instance by transitioning the state
 * to the configuration state, setting the status output control register, and then transitioning back to the normal state.
 *
 * @param pHandle Pointer to the FCSMU handle structure.
 * @param pInitCfg Pointer to the FCSMU status output configuration structure.
 *
 * @return FCSMU_StatusType Indicates the status of the status output initialization process (FCSMU_STATUS_SUCCESS or FCSMU_STATUS_FAIL).
 *
 * @note If the handle pointer, initialization configuration pointer, or instance index is invalid, a device error will be reported,
 * and the function returns FCSMU_STATUS_FAIL.
 */
FCSMU_StatusType FCSMU_StatusOutputInit(FCSMU_HandleType *const pHandle, const FCSMU_StatusOutputCfgType *const pInitCfg);

/**
 * @brief Deinitializes the status output configuration for the FCSMU module.
 *
 * This function deinitializes the status output configuration for the specified FCSMU module instance by transitioning the state to the
 * configuration state, clearing the status output control register, and then transitioning back to the normal state.
 *
 * @param pHandle Pointer to the FCSMU handle structure.
 *
 * @return FCSMU_StatusType Indicates the status of the status output deinitialization process (FCSMU_STATUS_SUCCESS or FCSMU_STATUS_FAIL).
 *
 * @note If the handle pointer or instance index is invalid, a device error will be reported, and the function returns FCSMU_STATUS_FAIL.
 */
FCSMU_StatusType FCSMU_StatusOutputDeinit(FCSMU_HandleType *const pHandle);

/**
 * @brief Retrieves the fault channel for the specified FCSMU module.
 *
 * This function retrieves the fault channel for the specified FCSMU module instance.
 *
 * @param pHandle Pointer to the FCSMU handle structure.
 *
 * @return uint32_t The fault channel number.
 *
 * @note If the handle pointer or instance index is invalid, a device error will be reported.
 */
uint32_t FCSMU_GetFaultChannel(FCSMU_HandleType *const pHandle);

/**
 * @brief Clears the fault flag for the specified fault channel in the FCSMU module.
 *
 * This function clears the fault flag for the specified fault channel in the specified FCSMU module instance by unlocking the fault clear
 * mechanism, setting the fault channel to clear, and waiting for the operation to complete.
 *
 * @param pHandle Pointer to the FCSMU handle structure.
 * @param u32FaultChannel The fault channel whose fault flag should be cleared.
 *
 * @return FCSMU_StatusType Indicates the status of the fault flag clearing process (FCSMU_STATUS_SUCCESS or FCSMU_STATUS_TIMEOUT).
 *
 * @note If the handle pointer or instance index is invalid, a device error will be reported, and the function returns FCSMU_STATUS_FAIL.
 */
FCSMU_StatusType FCSMU_ClearFaultFlag(FCSMU_HandleType *const pHandle, uint32_t u32FaultChannel);

/**
 * @brief Injects a fault into the specified channel in the FCSMU module.
 *
 * This function injects a fault into the specified channel in the specified FCSMU module instance by setting the injection register.
 *
 * @param pHandle Pointer to the FCSMU handle structure.
 * @param u32ChannelIndex The channel index where the fault should be injected.
 *
 * @return FCSMU_StatusType Indicates the status of the fault injection process (FCSMU_STATUS_SUCCESS or FCSMU_STATUS_FAIL).
 *
 * @note If the handle pointer or instance index is invalid, a device error will be reported, and the function returns FCSMU_STATUS_FAIL.
 */
FCSMU_StatusType FCSMU_InjectionFault(FCSMU_HandleType *const pHandle, uint32_t u32ChannelIndex);

/**
 * @brief Initializes the CRC checker for the FCSMU module.
 *
 * This function initializes the CRC checker for the specified FCSMU module instance by generating a CRC, configuring the trigger mode
 * and error request mode, and enabling the CRC checker and error output.
 *
 * @param pHandle Pointer to the FCSMU handle structure.
 * @param pInitCfg Pointer to the FCSMU CRC configuration structure.
 *
 * @return FCSMU_StatusType Indicates the status of the CRC initialization process (FCSMU_STATUS_SUCCESS or FCSMU_STATUS_TIMEOUT).
 *
 * @note If the handle pointer, initialization configuration pointer, or instance index is invalid, a device error will be reported,
 * and the function returns FCSMU_STATUS_FAIL.
 */
FCSMU_StatusType FCSMU_CrcInit(FCSMU_HandleType *const pHandle, const FCSMU_CrcCfgType *const pInitCfg);

/**
 * @brief Deinitializes the CRC checker for the FCSMU module.
 *
 * This function deinitializes the CRC checker for the specified FCSMU module instance by clearing the CRC control register and the CRC error flag.
 *
 * @param pHandle Pointer to the FCSMU handle structure.
 *
 * @return FCSMU_StatusType Indicates the status of the CRC deinitialization process (FCSMU_STATUS_SUCCESS or FCSMU_STATUS_FAIL).
 *
 * @note If the handle pointer or instance index is invalid, a device error will be reported, and the function returns FCSMU_STATUS_FAIL.
 */
FCSMU_StatusType FCSMU_CrcDeinit(FCSMU_HandleType *const pHandle);

/**
 * @brief Generates a CRC for the specified FCSMU module.
 *
 * This function generates a CRC for the specified FCSMU module instance by initiating the CRC generation process.
 *
 * @param pHandle Pointer to the FCSMU handle structure.
 *
 * @return FCSMU_StatusType Indicates the status of the CRC generation process (FCSMU_STATUS_SUCCESS or FCSMU_STATUS_FAIL).
 *
 * @note If the handle pointer or instance index is invalid, a device error will be reported, and the function returns FCSMU_STATUS_FAIL.
 */
FCSMU_StatusType FCSMU_CrcGen(FCSMU_HandleType *const pHandle);

/**
 * @brief Checks if the CRC generation process is busy for the specified FCSMU module.
 *
 * This function checks if the CRC generation process is currently busy for the specified FCSMU module instance.
 *
 * @param pHandle Pointer to the FCSMU handle structure.
 *
 * @return bool Indicates whether the CRC generation process is busy (true) or not (false).
 *
 * @note If the handle pointer or instance index is invalid, a device error will be reported.
 */
bool FCSMU_CrcIsBusy(FCSMU_HandleType *const pHandle);

#ifdef FCSMU_CRC_CTRL_DONE_SUPPORT
/**
 * @brief Clears the busy flag for the CRC generation process in the specified FCSMU module.
 *
 * This function clears the busy flag for the CRC generation process in the specified FCSMU module instance.
 *
 * @param pHandle Pointer to the FCSMU handle structure.
 *
 * @note If the handle pointer or instance index is invalid, a device error will be reported.
 *
 * @note This function is specific to devices within the range FC7240F2MDS1P100T1A to FC7240F2MDS1P176T1A.
 */
void FCSMU_CrcClearBusy(FCSMU_HandleType *const pHandle);
#endif

/**
 * @brief Retrieves the result of the CRC calculation for the specified FCSMU module.
 *
 * This function retrieves the result of the CRC calculation for the specified FCSMU module instance.
 *
 * @param pHandle Pointer to the FCSMU handle structure.
 *
 * @return uint32_t The result of the CRC calculation.
 *
 * @note If the handle pointer or instance index is invalid, a device error will be reported.
 */
uint32_t FCSMU_CrcGetResult(FCSMU_HandleType *const pHandle);

/**
 * @brief Handles common interrupts for the FCSMU module.
 *
 * This static function handles common interrupts for the specified FCSMU module instance. It processes fault, warning, and configuration
 * timeout interrupts by retrieving relevant information and invoking appropriate callbacks.
 *
 * @param pHandle Pointer to the FCSMU handle structure.
 *
 * @note This function is intended for internal use only and should not be called directly.
 *
 * @note If the handle pointer or instance index is invalid, a device error will be reported.
 */
void FCSMU_CommonIRQHandler(FCSMU_HandleType *const pHandle);

/** @} */ /* module_driver_fcsmu. */

#if defined(__cplusplus)
}
#endif

#endif /* (FCSMU_INSTANCE_COUNT > 0U) */

#endif /* _DRIVER_MODULE_DRIVER_FCSMU_H_ */
