/**
 * @file        module_driver_cmu.h
 * @author      Flagchip0100
 * @brief       CMU Module driver type definition and API
 * @version 2.0.0
 * @date        2024-08-20
 *
 * SDK Version: 2.6.0
 *

 * @copyright   Copyright 2020-2024 Flagchip Semiconductors Co., Ltd.
 */

/* *******************************************************************************
 *   Revision History:
 *
 *   Version     Date          Initials       CR#          Descriptions
 *   ---------   ----------    ------------   ----------   ---------------
 *   0.1.0       2022-12-12    Flagchip084    N/A          FC7xxx release version
 *   0.2.0       2023-02-13    Flagchip084    N/A          FC7xxx release version
 *   2.0.0       2024-08-01    Flagchip0100   N/A          SDK2.0 release version
 ********************************************************************************/

#ifndef _DRIVER_MODULE_DRIVER_CMU_H_
#define _DRIVER_MODULE_DRIVER_CMU_H_

#include "HwA_cmu.h"

#if (CMU_INSTANCE_COUNT > 0U)

#if defined(__cplusplus)
extern "C" {
#endif

/**
 * @addtogroup module_driver_cmu
 * @{
 */

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/**
 * @name  CMU API Service IDs
 * @{
 */
#define CMU_INIT_ID                     0x00U
#define CMU_GET_DEFAULT_CONFIG_ID       0x01U
#define CMU_ENABLE_ID                   0x02U
#define CMU_DISABLE_ID                  0x03U
#define CMU_ENABLE_IRQ_ID               0x04U
#define CMU_DISABLE_IRQ_ID              0x05U
#define CMU_COMMONIRQHANDLER_ID         0x06U
#define CMU_ENABLE_LOWPOWER_MODE_ID     0x07U
#define CMU_CAL_MONITOR_WINDOW_ID       0x08U
#define CMU_GET_CURRENTCOUNT_ID         0x09U
#define CMU_GET_MINCOUNT_ID             0x0AU
#define CMU_GET_MAXCOUNT_ID             0x0BU
#define CMU_GET_INQTYPE_ID              0x0CU
/** @} */

/**
 * @name  CMU Dev Error Code
 * @brief Error Code of calling CMU apis
 * @{
 */
#define CMU_E_PARAM_NULLPTR             0x01U
#define CMU_E_PARAM_INSTANCE            0x02U
/** @} */

/** 
 * @brief CMU Instance type.
 * 
 */
typedef enum
{
    CMU_INSTANCE_0   = 0U,
    CMU_INSTANCE_1   = 1U,
    CMU_INSTANCE_2   = 2U,
    CMU_INSTANCE_3   = 3U,
    CMU_INSTANCE_4   = 4U,
} CMU_InstanceType;

/**
 * @brief CMU operation return values.
 *
 */
typedef enum
{
    CMU_STATUS_SUCCESS  = 0x0U,         /**< The CMU status success */
    CMU_STATUS_FAIL     = 0x1U,         /**< The CMU status fail */
} CMU_StatusType;

/**
 * @brief CMU Lowpower Mode type.
 *
 */
typedef enum
{
    CMU_STOP_MODE       = 0U,           /**< CMU enable in Stop Mode. */
    CMU_STANDBY_MODE    = 1U,           /**< CMU enable in Standby Mode. */
} CMU_LowpowerModeType;

/**
 * @brief CMU4 Reference clock type.
 *
 */
typedef enum
{
    CMU_CMU4_REF_CLK_NONE = 0U,         /**< Not Select Cmu4 Reference clock. */
    CMU_CMU4_REF_CLK_FOSC = 1U,         /**< Select the FOSC as Cmu4 Reference clock. */
    CMU_CMU4_REF_CLK_SIRC = 2U,         /**< Select the SIRC as Cmu4 Reference clock. */
} CMU_Cmu4ClkSrcType;

/**
 * @brief CMU interrupt mode type.
 *
 */
typedef enum
{
    CMU_INTERRUPT_NONE  = 0U,            /**< No CMU interrupt. */
    CMU_INTERRUPT_LOC   = 1U,            /**< CMU_ST[LOC] bit, Monitor clock is loss. */
    CMU_INTERRUPT_MIS   = 2U,            /**< CMU_ST[MIS] bit, Monitor clock is mismatched. */
} CMU_InterruptType;

/**
 * @brief CMU Reference clock div type.
 * 
 */
typedef enum
{
    CMU_REFCLK_NODIV      = 0U,         /**< Clock output is disabled. */
    CMU_REFCLK_DIV_BY2    = 1U,         /**< Divided by 2. */
    CMU_REFCLK_DIV_BY4    = 2U,         /**< Divided by 4. */
    CMU_REFCLK_DIV_BY8    = 3U,         /**< Divided by 8. */
    CMU_REFCLK_DIV_BY16   = 4U,         /**< Divided by 16. */
    CMU_REFCLK_DIV_BY32   = 5U,         /**< Divided by 32. */
    CMU_REFCLK_DIV_BY64   = 6U,         /**< Divided by 64. */
    CMU_REFCLK_DIV_BY128  = 7U          /**< Divided by 128. */
} CMU_RefClockDivType;

/**
 * @brief The structure of the CMU processing handle
 *
 */
typedef struct _CMU_HandleType
{
    CMU_InstanceType eInstance;         /**< CMU instance*/
    uint8_t _aligned[3U];

    struct
    {
        void (*pErrorCallback)(struct _CMU_HandleType *pHandle, const CMU_InterruptType eStatus);  /**< Error Callback function point */
    } tSettings;
} CMU_HandleType;

/** @brief CMU configure structure. */
typedef struct
{
    uint32_t u32RefClk;                 /**< Reference clock */
    uint32_t u32MonitorClk;             /**< Monitor clock */
    uint32_t u32RefWindow;              /**< CMU_REF_WINDOW[REF_WINDOW] bits, The sample window for the reference clock. */
    uint32_t u32MinMonitorCnts;         /**< CMU_MIN[MIN] bits, The minimum threshold for the monitor counter. */
    uint32_t u32MaxMonitorCnts;         /**< CMU_MAX[MAX] bits, The maximum threshold for the monitor counter. */
    uint32_t u32PerMonitorWindow;       /**< CMU_PERIOD[WINDOW] bits, Period Monitor mode WIDOW. */
    bool bIntEnable;                    /**< CMU_CTRL[IRQ_EN] bit, interrupt enable, if this bit asserted, either LOC or MIS asserted can lead the interrupt. */
    bool bLpen;                         /**< CMU_CTRL[LP_EN] bit, standby mode enable, need STOP_EN asserted. */
    bool bSten;                         /**< CMU_CTRL[STOP_EN] bit, stop mode enable. */
    bool bEnable;                       /**< CMU_CTRL[EN] bit, cmu enable. */
    bool bPerMonitorEnable;             /**< CMU_PERIOD[EN] bit, Period Monitor mode ENABLE. */
    CMU_RefClockDivType eDiv;           /**< Divider of reference clock. */
    uint8_t _aligned[2U];
} CMU_CfgType;

/*******************************************************************************
 * API
 ******************************************************************************/

/**
 * @brief Initializes a CMU configuration structure with default values
 *
 * This function configures the provided CMU configuration structure with a set of default settings,
 * including interrupt enable, low-power mode, clock divider, and more. If the passed configuration
 * structure pointer is NULL and error reporting is enabled, an error will be reported.
 *
 * @param pInitCfg Pointer to a CMU_CfgType structure that will be initialized with default configuration values
 *
 * @note The function checks for NULL pointer only if error reporting (`CMU_DEV_ERROR_REPORT`) is turned on.
 *       By default, it sets the structure fields to:
 *       - Interrupt Enable: true
 *       - Low Power Enable: false
 *       - Clock Monitor Enable: false
 *       - Module Enable: true
 *       - Peripheral Monitor Enable: false
 *       - Clock Divider: CMU_REFCLK_NODIV
 *       - Error Callback: NULL
 */
void CMU_GetDefaultConfig(CMU_CfgType *const pInitCfg);

/**
 * @brief Calculates monitor window values for the CMU based on the given configuration
 *
 * This function calculates the reference and monitor clock window values for the specified CMU instance.
 * It verifies input parameters, checks the clock status, and performs necessary calculations.
 * If any input is invalid or an error occurs, appropriate error reporting may be triggered.
 *
 * @param pInitCfg Pointer to a CMU configuration structure with user-defined settings
 *
 * @note Error reporting is enabled when `CMU_DEV_ERROR_REPORT` is set to `STD_ON`.
 */
void CMU_CaculateMonitorWindowsValue(CMU_CfgType *const pInitCfg);

/**
 * @brief Initializes the CMU module with the provided configuration
 *
 * This function initializes the Clock Monitor Unit (CMU) according to the specified configuration.
 * It performs parameter validation, initializes hardware registers, and sets up callback functions.
 * If any input is invalid, an error will be reported and the function will return `CMU_STATUS_FAIL`.
 *
 * @param pHandle Pointer to a CMU handle structure containing the instance information
 * @param pInitCfg Pointer to a constant CMU configuration structure with initialization settings
 *
 * @return Status of the initialization process
 *         - CMU_STATUS_SUCCESS: Initialization successful
 *         - CMU_STATUS_FAIL: Initialization failed due to an error or invalid parameter
 *
 * @note Error reporting is enabled when `CMU_DEV_ERROR_REPORT` is set to `STD_ON`.
 */
CMU_StatusType CMU_Init(CMU_HandleType *const pHandle, const CMU_CfgType *const pInitCfg);

/**
 * @brief Enables the Clock Monitor Unit (CMU) for the specified instance
 *
 * This function enables the CMU module for the given handle's instance. It performs parameter
 * validation and updates the control register to activate the CMU. If an error occurs or the
 * handle is invalid, an error report will be generated.
 *
 * @param pHandle Pointer to a CMU handle structure containing the instance information
 *
 * @note Error reporting is enabled when `CMU_DEV_ERROR_REPORT` is set to `STD_ON`.
 */
void CMU_Enable(CMU_HandleType *const pHandle);

/**
 * @brief Disables the Clock Monitor Unit (CMU) for the specified instance
 *
 * This function disables the CMU module for the given handle's instance. It performs parameter
 * validation, clears the control register flags for enabling and interrupts, and resets the
 * status. If an error occurs or the handle is invalid, an error report will be generated.
 *
 * @param pHandle Pointer to a CMU handle structure containing the instance information
 *
 * @note Error reporting is enabled when `CMU_DEV_ERROR_REPORT` is set to `STD_ON`.
 */
void CMU_Disable(CMU_HandleType *const pHandle);

/**
 * @brief Enables the Clock Monitor Unit (CMU) interrupt for the specified instance
 *
 * This function enables the interrupt for the CMU module associated with the given handle's instance.
 * It performs parameter validation and updates the control register to enable the interrupt.
 * If an error occurs or the handle is invalid, an error report will be generated.
 *
 * @param pHandle Pointer to a CMU handle structure containing the instance information
 *
 * @note Error reporting is enabled when `CMU_DEV_ERROR_REPORT` is set to `STD_ON`.
 */
void CMU_EnableInterrupt(CMU_HandleType *const pHandle);

/**
 * @brief Disables the Clock Monitor Unit (CMU) interrupt for the specified instance
 *
 * This function disables the interrupt for the CMU module associated with the given handle's instance.
 * It performs parameter validation and updates the control register to disable the interrupt.
 * If an error occurs or the handle is invalid, an error report will be generated.
 *
 * @param pHandle Pointer to a CMU handle structure containing the instance information
 *
 * @note Error reporting is enabled when `CMU_DEV_ERROR_REPORT` is set to `STD_ON`.
 */
void CMU_DisableInterrupt(CMU_HandleType *const pHandle);

/**
 * @brief Enables or disables low power mode on the CMU module.
 *
 * This function configures the CMU module to enter or exit low power mode based on the parameters provided.
 * It supports both standby and stop modes, and can optionally enable low power restart.
 *
 * @param pHandle Pointer to the CMU handle structure.
 * @param eMode The low power mode type to be set (CMU_STANDBY_MODE or CMU_STOP_MODE).
 * @param bModeEnable Boolean flag indicating whether to enable (true) or disable (false) the low power mode.
 * @param bRestartEnable Boolean flag indicating whether to enable (true) or disable (false) low power restart.
 *
 * @note If the handle pointer is NULL or the instance index is out of range, a device error will be reported.
 */
void CMU_LowPowerModeEnable(CMU_HandleType *const pHandle, CMU_LowpowerModeType eMode, bool bModeEnable, bool bRestartEnable);

/**
 * @brief Retrieves the current count from the CMU module.
 *
 * This function returns the current count value from the specified CMU module instance.
 *
 * @param pHandle Pointer to the CMU handle structure.
 *
 * @return uint32_t The current count value from the CMU module.
 *
 * @note If the handle pointer is NULL or the instance index is out of range, a device error will be reported.
 */
uint32_t CMU_GetCount(CMU_HandleType *const pHandle);

/**
 * @brief Retrieves the minimum count value from the CMU module.
 *
 * This function returns the minimum count value that the specified CMU module instance can support.
 *
 * @param pHandle Pointer to the CMU handle structure.
 *
 * @return uint32_t The minimum count value supported by the CMU module.
 *
 * @note If the handle pointer is NULL or the instance index is out of range, a device error will be reported.
 */
uint32_t CMU_GetMinCount(CMU_HandleType *const pHandle);

/**
 * @brief Retrieves the maximum count value from the CMU module.
 *
 * This function returns the maximum count value that the specified CMU module instance can support.
 *
 * @param pHandle Pointer to the CMU handle structure.
 *
 * @return uint32_t The maximum count value supported by the CMU module.
 *
 * @note If the handle pointer is NULL or the instance index is out of range, a device error will be reported.
 */
uint32_t CMU_GetMaxCount(CMU_HandleType *const pHandle);

/**
 * @brief Sets the reference clock source for CMU4.
 *
 * This function configures the CMU4 reference clock source to either the Fast Oscillator Clock (FOSC) or the Slow Internal RC Oscillator Clock (SIRC).
 *
 * @param eSrc The CMU4 clock source type (CMU_CMU4_REF_CLK_FOSC or CMU_CMU4_REF_CLK_SIRC).
 *
 * @note The function clears the current CMU4 clock setting before applying the new source.
 */
void CMU_SetCmu4RefSrc(CMU_Cmu4ClkSrcType eSrc);

/**
 * @brief Retrieves the interrupt type of the CMU (Clock Monitor Unit) module.
 *
 * This function reads the status register of the CMU module to determine if a LOC (Loss of Clock) 
 * or MIS (Mismatch) interrupt has occurred.
 *
 * @param pHandle Pointer to the CMU module handle. The handle contains information about the CMU instance.
 *
 * @return CMU_InterruptType The current interrupt type, which can be one of the following:
 *         - CMU_INTERRUPT_NONE: No interrupt has occurred.
 *         - CMU_INTERRUPT_LOC: A LOC interrupt has occurred.
 *         - CMU_INTERRUPT_MIS: A MIS interrupt has occurred.
 *
 * @note If device error reporting is enabled (CMU_DEV_ERROR_REPORT == STD_ON),
 *       the function will report an error if the handle pointer is NULL or if the instance number is invalid.
 */
CMU_InterruptType CMU_GetInterruptType(CMU_HandleType *const pHandle);

/**
 * @brief Common Clock Monitor Unit (CMU) Interrupt Service Routine (ISR)
 *
 * This ISR handles common interrupt scenarios for the CMU module associated with the given handle.
 * It retrieves the current interrupt status, performs error handling as needed, and calls
 * the registered error callback function if present. Additionally, it addresses a specific
 * hardware erratum (ERR_CMU_001). After processing, the ISR clears the status flags.
 *
 * @param pHandle Pointer to a CMU handle structure containing the instance information
 *
 * @note This function assumes that the CMU interrupt has already occurred and is being serviced.
 * @note Error reporting and handling are performed based on the interrupt status.
 */
void CMU_CommonIRQHandler(CMU_HandleType *const pHandle);

/** @}*/ /* module_driver_cmu */

#if defined(__cplusplus)
}
#endif

#endif /* (CMU_INSTANCE_COUNT > 0U) */

#endif /* _DRIVER_MODULE_DRIVER_CMU_H_ */
