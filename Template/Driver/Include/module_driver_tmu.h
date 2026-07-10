/**
 * @file module_driver_tmu.h
 * @author Flagchip
 * @brief TMU driver type definition and API
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
   *   0.1.0       2023-12-15    Flagchip074   N/A          First version for FC7300
   *   2.0.0       2024-10-12    Flagchip074   N/A          Change version and release
   ******************************************************************************** */

#ifndef _DRIVER_MODULE_DRIVER_TMU_H_
#define _DRIVER_MODULE_DRIVER_TMU_H_

#include "HwA_tmu.h"

#if TMU_INSTANCE_COUNT > 0U

#if defined(__cplusplus)
extern "C" {
#endif
/**
 * @addtogroup module_driver_tmu
 * @{
 */

/**
 * @name  TMU API Service IDs
 *
 * @{
 */
#define TMU_INIT_ID 0U
/** @}*/

/**
 * @name  TMU Dev Error Code
 * @brief Error Code of calling TMU apis
 *
 * @{
 */
#define TMU_E_PARAM_INSTANCE           0x01U
#define TMU_E_PARAM_POINTER            0x02U
/** @}*/

/** @brief  TMU instance declaration. */
typedef enum
{
    TMU_INSTANCE_0 = 0U,  /*!< TMU instance 0 is selected */
    TMU_INSTANCE_MAX
} TMU_InstanceType;

/**
 * @brief TMU operation return values
 *
 */
typedef enum
{
    TMU_STATUS_ERROR   = 0x0U,  /*!< The TMU operation is failed */
    TMU_STATUS_SUCCESS = 0x1U,  /*!< The TMU operation is succeed */
    TMU_STATUS_TIMEOUT = 0x2U   /*!< The TMU operation is failed because of time out */
} TMU_StatusType;

/**
 * @brief The structure of the TMU processing handle
 *
 */
typedef struct _TMU_HandleType
{
    TMU_InstanceType                   eIntance;              /**@  TMU instance */
#if TMU_SUPPORT_TV_ECMP
    uint8_t							   u8AdcIntanceUsed;      /**@  The ADC instance used for sampling the temperature sensor channel */
    uint8_t                            reserve[2];
#else
    uint8_t                            reserve[3];
#endif
    struct
    {
#if TMU_SUPPORT_TV_ECMP
    	void (*TMU_TempCompareFlag1InterruptCallback)(struct _TMU_HandleType *pHandle);     /**@  The Voltage-based temperature sensor Compare Flag 1 Interrupt callback. */
    	void (*TMU_TempCompareFlag0InterruptCallback)(struct _TMU_HandleType *pHandle);     /**@  The Voltage-based temperature sensor Compare Flag 0 Interrupt callback. */
#else
        void (*TMU_TempOver150InterruptCallback)(struct _TMU_HandleType *pHandle);     /**@  The Flag-based temperature sensor over 150 Celsius interrupt callback. */
        void (*TMU_TempOver125InterruptCallback)(struct _TMU_HandleType *pHandle);     /**@  The Flag-based temperature sensor over 125 Celsius interrupt callback. */
        void (*TMU_TempFlagReadyInterruptCallback)(struct _TMU_HandleType *pHandle);     /**@  The Flag-based temperature sensor ready interrupt callback. */
        void (*TMU_TempVoltageReadyInterruptCallback)(struct _TMU_HandleType *pHandle);     /**@  The Voltage-based temperature sensor ready interrupt callback. */
#endif
    } tSettings;
    struct
    {
#if TMU_SUPPORT_TV_ECMP
    	bool bVoltageTempCompareFlag1IntEn;         /*!< The Voltage-based temperature sensor Compare Flag 1 interrupt enable status */
    	bool bVoltageTempCompareFlag0IntEn;         /*!< The Voltage-based temperature sensor Compare Flag 0 interrupt enable status */
#else
        bool bTemperatureOver150IntEn;              /*!< The enable status of interrupt when Temperature over 150 Celsius */
        bool bTemperatureOver125IntEn;              /*!< The enable status of interrupt when Temperature over 125 Celsius */
        bool bFlagTempReadyIntEn;                   /*!< The enable status of interrupt when Flag-based temperature sensor ready */
        bool bVoltageTempReadyIntEn;                /*!< The enable status of interrupt when Voltage-based temperature sensor ready */
#endif
    } tStatus;
} TMU_HandleType;

/**
 * @brief Defines the temperature sensor configuration
 *
 * This structure is used to configure for Flag-based temperature sensor and Voltage-based temperature sensor
 *
 * Implements : TMU_InitType
 */
typedef struct
{
#if TMU_SUPPORT_TV_ECMP
    bool bVoltageTempCompareFlag1IntEn;         /*!< Enable interrupt when Temperature Compare Flag 1 is asserted */
    bool bVoltageTempCompareFlag0IntEn;         /*!< Enable interrupt when Temperature Compare Flag 0 is asserted */
#else
    bool bTemperatureOver150IntEn;              /*!< Enable interrupt when Temperature over 150 Celsius */
    bool bTemperatureOver125IntEn;              /*!< Enable interrupt when Temperature over 125 Celsius */
    bool bFlagTempReadyIntEn;                   /*!< Enable interrupt when Flag-based temperature sensor ready */
    TMU_HysteresisType eFlagTempHysteresisCon;  /*!< Flag-based temperature sensor hysteresis control (on,off) */
    TMU_bypassType eFlagTempFilterBypassCon;    /*!< Flag-based temperature sensor filter bypass control */

    bool bVoltageTempReadyIntEn;                /*!< Enable interrupt when Voltage-based temperature sensor ready */
#endif
#ifdef TMU_SUPPORT_STOP
#if !TMU_SUPPORT_TV_ECMP
    bool bFlagTempStopModeEn;                   /*!< Flag-based temperature sensor stop mode enable control */
#endif
    bool bVoltageTempStopModeEn;                /*!< Voltage-based temperature sensor stop mode enable control */
#endif
}TMU_InitType;

/** @brief TMU interrupt process */
void TMU_ProcessIRQHandler(TMU_HandleType* pTmuHandle);

/**
 * @brief Initialize the TMU instance
 *
 * @param pTmuHandle: TMU processing handle
 * @param pInitCfg: the configurations of the TMU instance
 */
void TMU_Init(TMU_HandleType* pTmuHandle, const TMU_InitType *const pInitCfg);

#if !TMU_SUPPORT_TV_ECMP
/**
 * @brief Enable the Flag-based temperature sensor
 *
 * @param pTmuHandle: TMU processing handle
 * @return TMU_StatusType TMU_STATUS_SUCCESS when enable successfully, others fail
 */
TMU_StatusType TMU_FlagTempEnable(TMU_HandleType* pTmuHandle);

/**
 * @brief Disable the Flag-based temperature sensor
 *
 * @param pTmuHandle: TMU processing handle
 * @return TMU_StatusType TMU_STATUS_SUCCESS when disable successfully, others fail
 */
TMU_StatusType TMU_FlagTempDisable(TMU_HandleType* pTmuHandle);
#endif

/**
 * @brief Enable the Voltage-based temperature sensor
 *
 * @param pTmuHandle: TMU processing handle
 * @return TMU_StatusType TMU_STATUS_SUCCESS when enable successfully, others fail
 */
TMU_StatusType TMU_VoltageTempEnable(TMU_HandleType* pTmuHandle);

/**
 * @brief Disable the Voltage-based temperature sensor
 *
 * @param pTmuHandle: TMU processing handle
 * @return TMU_StatusType TMU_STATUS_SUCCESS when disable successfully, others fail
 */
TMU_StatusType TMU_VoltageTempDisable(TMU_HandleType* pTmuHandle);

#if !TMU_SUPPORT_TV_ECMP
/**
 * @brief Check if cleaning flag is required
 *
 * @param pTmuHandle: TMU processing handle
 */
void TMU_TempOverClear(TMU_HandleType* pTmuHandle);
#endif

#ifdef TMU_SUPPORT_STOP
#if !TMU_SUPPORT_TV_ECMP
/**
 * @brief Set the Flag-based temperature sensor is enabled/disabled in stop mode
 *
 *@param pTmuHandle: TMU processing handle
 * @param bEnable: whether Flag-based temperature sensor is enabled in stop mode if TF_EN is active.
 */
void TMU_FlagTempSetStopMode(TMU_HandleType* pTmuHandle, bool bEnable);
#endif

/**
 * @brief Set the Voltage-based temperature sensor is enabled/disabled in stop mode
 *
 *@param pTmuHandle: TMU processing handle
 * @param bEnable: whether Voltage-based temperature sensor is enabled in stop mode if TV_EN is active.
 */
void TMU_VoltageTempSetStopMode(TMU_HandleType* pTmuHandle, bool bEnable);
#endif

#ifdef TMU_SUPPORT_TRIM
/**
 * @brief Get the temperature code from ADC
 *
 * @param pTmuHandle: TMU processing handle
 * @return uint32_t the value records the ADC conversion results for voltage-based temperature sensor result in 135 Celsius
 */
uint32_t TMU_GetTcode(TMU_HandleType* pTmuHandle);

/**
 * @brief Get the slope factor
 *
 * @param pTmuHandle: TMU processing handle
 * @return uint32_t the value records the slope factor for voltage-based temperature sensor
 */
uint32_t TMU_GetTslope(TMU_HandleType* pTmuHandle);
#endif
/** @}*/ /* module_driver_tmu */
#if defined(__cplusplus)
}
#endif

#endif /* #if TMU_INSTANCE_COUNT > 0U */

#endif
