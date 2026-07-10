/**
 * @file module_driver_ssi.h
 * @author Flagchip
 * @brief ssi driver type definition and API
 * @version 2.1.0
 * @date 2024-12-26
 *
 * SDK Version: 2.6.0
 *

 * @copyright Copyright (c) 2020-2024 Flagchip Semiconductors Co., Ltd.
 *
 */

/* ********************************************************************************
 *   Revision History:
 *
 *   Version     Date          Initials      CR#          Descriptions
 *   ---------   ----------    ------------  ----------   ---------------
 *   2.1.0       2024-12-26    Flagchip054   N/A          First version for FC7300
 ******************************************************************************** */

#ifndef _DRIVER_MODULE_DRIVER_SSI_H_
#define _DRIVER_MODULE_DRIVER_SSI_H_

#include "HwA_ssi.h"

#if SSI_INSTANCE_COUNT > 0U

/**
 * @name  ADC API Service IDs
 *
 * @{
 */
#define SSI_SUBINS_INIT_ID      1U
#define SSI_INIT_INTERRUPT_ID   2U
#define SSI_CLOCK_DIV_ID        3U
#define SSI_WINDOW_ID           4U
/** @}*/

/**
 * @name  ADC Dev Error Code
 * @brief Error Code of calling ADC apis
 *
 * @{
 */
#define SSI_E_PARAM_INSTANCE    0x01U
#define SSI_E_PARAM_SUBINSTANCE 0x02U
#define SSI_E_PARAM_POINTER     0x03U
#define SSI_E_COMMON            0x04U
/** @}*/

/**
 * @brief SSI Error Information
 *
 */
typedef enum
{
    SSI_ERROR_OK,    /**< no error                             */
    SSI_ERROR_INDEX, /**< error index                        */
} SSI_ErrorType;

typedef struct
{
    uint32_t u32win_h; /* max value for window */
    uint32_t u32win_l; /* min value for window*/
} SSI_Window_CfgType;

/**
 * @brief SSI Sub-instance Initialization Configuration Structure
 *
 * This structure is used to configure and initialize a specific SSI sub-instance.
 */
typedef struct
{
    SSI_Sub_Ins_Index eIndex;            /**< Index of the sub-instance to initialize */
    bool              bEnErrorInterrupt; /**< Enable error interrupt for this sub-instance */
    bool              bEnVldInterrupt;   /**< Enable valid data interrupt for this sub-instance */
    uint8_t           RESERVED_0[1];     /**< Reserved for alignment or future use */
    uint32_t          u32FiltWidth;      /**< Filter width for input signal debouncing */
    const SSI_Common_CfgType *tCfg;      /**< Pointer to common configuration structure */
} SSI_Sub_Ins_InitType;

/**
 * @brief SSI State Type Enumeration
 *
 * This enumeration defines the possible operational states of the SSI module.
 */
typedef enum
{
    PTOT_ERROR  = 0, /**< Protocol error detected */
    WHLTIMEROUT = 1, /**< Wheel timer timeout occurred */
    WHLSTOP     = 2  /**< Wheel has stopped rotating */
} SSI_StateType;

/**
 * @brief SSI Data Information Structure
 *
 * This structure holds runtime data captured by the SSI module, such as wheel value,
 * PWM value, and active sub-instance index.
 */
typedef struct
{
    uint32_t          U32Whlval;   /**< Current wheel position value */
    uint32_t          U32Pwmval;   /**< Captured PWM value */
    uint32_t          U32HPCRval;  /**< HPCR (Hardware Position Capture Register) value */
    uint32_t          U32Mcodeval; /**< M-code value (used in AK protocol) */
    uint32_t          U32Mcodecnt; /**< M-code counter */
    uint8_t           U8StopFlag;
    SSI_Sub_Ins_Index tActiveIdx; /**< Index of the currently active sub-instance */
} SSI_DataInfType;

/**
 * @brief SSI Processing Handle Structure
 *
 * This structure represents the main handle for managing an SSI instance,
 * including callbacks for error and data valid notifications.
 */
typedef struct _SSI_HandleType
{
    SSI_InstanceType eInstance;    /**< SSI hardware instance identifier */
    SSI_DataInfType *tSSI_DataInf; /**< Pointer to data information structure */
    void (*pSSI_ErrorNotify)(struct _SSI_HandleType *pSSIHandle,
                             uint32_t                u32Error); /**< Error notification callback */
    void (*pSSI_VldNotify)(struct _SSI_HandleType *pSSIHandle,
                           SSI_Protocol_ModeType   tType); /**< Valid data notification callback */
} SSI_HandleType;

/**
 * @brief Configures the clock divider for the SSI module.
 *
 * This function sets the clock division factor to control the operating frequency
 * of the SSI module. It should be called before starting any SSI operations.
 *
 * @param[in] pSSIHandle Pointer to the SSI handle structure
 * @param[in] u32ClkDiv  Clock division value. The actual clock is derived from this value.
 */
void SSI_Clock_Div_Cfg(SSI_HandleType *pSSIHandle, uint32_t u32ClkDiv);

/**
 * @brief Configures the window range for valid signal detection.
 *
 * This function sets the high and low thresholds for the valid input signal window.
 * Signals outside this window may be considered invalid or noisy.
 *
 * @param[in] pSSIHandle     Pointer to the SSI handle structure
 * @param[in] U32windowCfg   Configuration structure containing window high/low values
 */
void SSI_Window_Cfg(SSI_HandleType *pSSIHandle, SSI_Window_CfgType *U32windowCfg);

/**
 * @brief  Configures the global protocol configuration for the SSI module.
 *
 * This function sets up the global protocol configuration register for the SSI peripheral
 * based on the provided configuration parameters.
 *
 * @param[in] pSSIHandle Pointer to the SSI handle structure that contains
 *                       the configuration information for the SSI module.
 * @param[in] u32GpcrCfg Global protocol configuration value to be set.
 *
 * @retval None
 *
 * @note This function performs register write operations and waits for completion.
 *
 * @attention The function includes error checking when SSI_DEV_ERROR_REPORT is enabled.
 *           It will report errors for invalid pointer or instance parameters.
 *
 * @pre The SSI instance must be properly initialized before calling this function.
 *
 * @post The global protocol configuration register is updated with the provided value.
 */

void SSI_GlobalPro_Cfg(SSI_HandleType *pSSIHandle, uint32_t u32GpcrCfg);

/**
 * @brief Initializes a sub-instance of the SSI module.
 *
 * This function initializes the specified SSI sub-instance with the provided configuration.
 *
 * @param[in] pSSIHandle Pointer to the SSI handle structure
 * @param[in] pInitCfg   Pointer to the initialization configuration structure
 *
 * @return Error code indicating the result of the initialization
 * @retval SSI_ERROR_OK        Initialization successful
 * @retval SSI_ERROR_INDEX     Invalid sub-instance index
 */
SSI_ErrorType SSI_Sub_Ins_Init(SSI_HandleType *pSSIHandle, SSI_Sub_Ins_InitType *pInitCfg);

/**
 * @brief Interrupt handler for SSI0 instance.
 *
 * This function handles the interrupt service routine for the SSI0 hardware instance.
 * It processes error and data valid interrupts.
 *
 * @param[in] pSSIHandle Pointer to the SSI handle structure
 */
void SSI_IRQHandler(SSI_HandleType *pSSIHandle);

#endif

#endif
