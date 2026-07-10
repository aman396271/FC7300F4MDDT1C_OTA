/**
 * @file module_driver_wdog.h
 * @author Flagchip
 * @brief WDOG driver type definition and API
 * @version 2.0.0
 * @date 2024-08-20
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
   *   0.1.0       2023-12-15    Flagchip073   N/A          First version for FC7300
   *   2.0.0       2024-10-12    Flagchip073   N/A          Change version and release
   ******************************************************************************** */

#ifndef _DRIVER_MODULE_DRIVER_WDOG_H_
#define _DRIVER_MODULE_DRIVER_WDOG_H_
#include "HwA_wdog.h"

#if WDOG_INSTANCE_COUNT > 0U

/**
 * @addtogroup module_driver_wdog
 * @{
 */

/**
 * @name  WDOG API Service IDs
 *
 * @{
 */
#define WDOG_INIT_ID 0U
/** @}*/

/**
 * @name  WDOG Dev Error Code
 * @brief Error Code of calling WDOG apis
 *
 * @{
 */
#define WDOG_E_PARAM_INSTANCE           0x01U
#define WDOG_E_PARAM_TIMEOUT            0x02U
/** @}*/

/** @brief  WDOG initialization return values. */
typedef enum{
    WDOG_STATUS_SUCCESS         = 0x0U,  /**< The WDOG initialize is succeed */
    WDOG_STATUS_ERROR           = 0x1U,  /**< The WDOG initialize is error */
    WDOG_STATUS_ERROR_UNLOCK    = 0x2U,  /**< The WDOG initialize is error because unlock failed */
    WDOG_STATUS_ERROR_RECFG     = 0x3U   /**< The WDOG initialize is error because reconfigure failed */
} WDOG_StatusType;

/** @brief  WDOG clock instance declaration. */
typedef enum
{
    WDOG_INSTANCE_0 = 0U,  /*!< WDOG instance 0 is selected */
#if WDOG_INSTANCE_COUNT > 1
    WDOG_INSTANCE_1 = 1U,  /*!< WDOG instance 1 is selected */
#endif
#if WDOG_INSTANCE_COUNT > 2
    WDOG_INSTANCE_2 = 2U,  /*!< WDOG instance 2 is selected */
#endif
#if WDOG_INSTANCE_COUNT > 3
    WDOG_INSTANCE_3 = 3U,  /*!< WDOG instance 3 is selected */
#endif
    WDOG_INSTANCE_MAX      /*!< WDOG instance MAX number */
} WDOG_InstanceType;

/** @brief  WDOG clock source select, mapping with WDOG_CS[CLK_SEL] bit filed definition. */
typedef enum
{
    WDOG_BUS_CLK                        = 0x00U, /**< Bus clock */
    WDOG_AON_CLK                        = 0x01U, /**< AON clock, if choose this clock need to configure AON clock in SMISC setting */
    WDOG_FOSC_CLK                       = 0x02U, /**< FOSC clock */
    WDOG_SIRC_CLK                       = 0x03U  /**< SIRC clock */
} WDOG_ClkSelType;

/** @brief  WDOG test mode, mapping with WDOG_CS[TST] bit filed definition. */
typedef enum
{
    WDOG_TST_DISABLED                      = 0x00U, /**< Test mode disabled */
    WDOG_USER_MODE                         = 0x01U, /**< User mode enabled. (Test mode disabled.) */
    WDOG_TST_MODE_LOW                      = 0x02U, /**< Test mode enabled, only the low byte is used. */
    WDOG_TST_MODE_HIGH                     = 0x03U  /**< Test mode enabled, only the high byte is used. */
} WDOG_TestType;

/** @brief  WDOG delay time to generate the reset. */
typedef enum
{
    WDOG_REACTION_INT_128_CYCLE                  = 0x00U, /**< Enable the timeout interrupt, and the delay to generate the reset is configured to 128 bus clock cycles */
    WDOG_REACTION_INT_256_CYCLE                  = 0x01U, /**< Enable the timeout interrupt, and the delay to generate the reset is configured to 256 bus clock cycles */
    WDOG_REACTION_INT_512_CYCLE                  = 0x02U, /**< Enable the timeout interrupt, and the delay to generate the reset is configured to 512 bus clock cycles */
    WDOG_REACTION_INT_1024_CYCLE                 = 0x03U, /**< Enable the timeout interrupt, and the delay to generate the reset is configured to 1024 bus clock cycles */
    WDOG_REACTION_NO_INT                         = 0x04U  /**< Disable the timeout interrupt, and generate the reset immediately */
} WDOG_TimeoutReactionType;

/**
 * @brief The structure of the WDOG processing handle
 *
 */
typedef struct _WDOG_HandleType
{
    WDOG_InstanceType                   eIntance;              /**@  WDOG instance */
#if	WDOG_SUPPORT_FASTCFG
    bool                      			bFastCfgEnable;        /**@  The Fast Configuration state */
    uint8_t                             reserve[2];
#else
    uint8_t                             reserve[3];
#endif
    struct
    {
        void (*pISRCallback)(struct _WDOG_HandleType *pHandle);     /**@  The WDOG ISR callback function. */
    } tSettings;
} WDOG_HandleType;

/** @brief WDOG init module type, include register setting for WDOG_CS/WDOG_TIMEOUT/WDOG_WINDOW. */
typedef struct
{
    bool                      bWinEnable;         /**@  windowed watch dog mode */
    bool                      bPrescalerEnable;   /**@  fixed 256 prescaler from clock input */
    bool                      bInterruptEnable;   /**@  WDOG Interrupt,W1C bit */
    WDOG_ClkSelType           eClkSource;         /**@  WDOG clock source  */
    WDOG_TimeoutReactionType  eTimeoutReaction;   /**@  WDOG timeout reaction. */
    bool                      bEnable;            /**@  WDOG enable bit */
    WDOG_TestType             eTesttype;          /**@  WDOG_CS[TST] */
    bool                      bEnableInDebug;     /**@  WDOG_CS[DBG] */
    bool                      bEnableInWait;      /**@  WDOG_CS[WAIT] */
    bool                      bEnableInStop;      /**@  WDOG_CS[STOP] */
    uint16_t                  u16WindowValue;     /**@  The window value */
    uint16_t                  u16TimeoutValue;    /**@  The timeout value */
} WDOG_CfgType;

/**
 * @brief unlock the wdog before Watch dog reconfigure set.
 * @param pWdogHandle: WDOG processing handle
 */
void WDOG_Unlock(WDOG_HandleType* pWdogHandle);

/**
 * @brief feed the watch dog by writing typical CMD to counter.
 * @param pWdogHandle: WDOG processing handle
 */
void WDOG_Refresh(WDOG_HandleType* pWdogHandle);

/**
 * @brief Initialize the WDOG configuration setting.
 * @param pWdogHandle: WDOG processing handle
 * @param pWdogCfg: the configurations of the WDOG module
 * @return WDOG_StatusType initialization status
 */
WDOG_StatusType WDOG_Init(WDOG_HandleType* pWdogHandle, const WDOG_CfgType *const pWdogCfg);

/**
 * @brief Performs a self-test on the Watchdog Timer (WDOG) module.
 *
 * This function configures the WDOG module to perform a self-test based on the specified test mode.
 * It unlocks the WDOG registers, sets a timeout value, and configures the control and status register
 * to enable the WDOG, update its configuration, select the clock source, and set the test mode.
 *
 * @param pWdogHandle Pointer to the WDOG handle structure that contains the instance information.
 * @param eMode The test mode to be performed. This parameter determines the type of self-test to execute.
 *
 * @return void
 *
 * @note The function waits for the WDOG registers to be unlocked before proceeding with the configuration.
 *       The timeout value is set to the maximum value (0xFFFF) during the self-test.
 */
void WDOG_SelfTest(WDOG_HandleType* pWdogHandle, WDOG_TestType eMode);

/**
 * @brief De-initialize the WDOG instance
 * @param pWdogHandle: WDOG processing handle
 */
void WDOG_DeInit(WDOG_HandleType* pWdogHandle);

/**
 * @brief Wdg n interrupt process
 *
 * @param pWdogHandle: WDOG processing handle
 */
void WDOG_IRQHandler(WDOG_HandleType* pWdogHandle);
/** @}*/ /* module_driver_wdog */


#endif

#endif

