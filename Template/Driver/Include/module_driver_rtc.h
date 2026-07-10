/**
 * @file module_driver_rtc.h
 * @author Flagchip
 * @brief rtc driver type definition and API
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
   *   0.1.0       2023-12-15    Flagchip076   N/A          First version for FC7300
   *   2.0.0       2024-10-12    Flagchip076   N/A          Change version and release
   ******************************************************************************** */


#ifndef _DRIVER_MODULE_DRIVER_RTC_H_
#define _DRIVER_MODULE_DRIVER_RTC_H_

#include"HwA_rtc.h"

#if RTC_INSTANCE_COUNT > 0U

/**
 * @addtogroup module_driver_rtc
 * @{
 */

#define SECONDS_DAY     86400UL
#define SECONDS_HOUR    3600UL
#define SECONDS_MINUTE  60UL
#define MINUTES_HOUR    60UL
#define HOURS_DAY       24UL
#define DAYS_LEAP_YEAR  366UL
#define DAYS_COM_YEAR   365UL
#define START_YEAR      1970UL
#define END_YEAR        2099UL

/**
 * @name  RTC API Service IDs
 *
 * @{
 */
#define RTC_INIT_ID                     0U
#define RTC_DEINIT_ID                   1U
#define RTC_START_ID                    2U
#define RTC_STOP_ID                     3U
#define RTC_SET_COUNT_ID                4U
#define RTC_UPDATE_ALARM_ID             5U
#define RTC_CHECK_OVERFLOW_FLAF_ID      6U
#define RTC_GET_TIMEDATE_ID             7U
#define RTC_SET_TIMEDATE_ID             8U
#define RTC_GET_COMPENSATION_ID         9U
#define RTC_SET_COMPENSATION_ID         10U
#define RTC_INTE_PROC_ID                11U
#define RTC_IRQ_HANDER_ID               12U
/** @}*/


/**
 * @name  FTU Dev Error Code
 * @brief Error Code of calling RTC apis
 *
 * @{
 */
#define RTC_E_PARAM_INSTANCE   			0x01U
#define RTC_E_PARAM_CLOCK   			0x02U
#define RTC_E_PARAM_POINTER   			0x03U
#define RTC_E_PARAM_FORMAT              0x04U
/** @}*/

/**
 * @brief The instance index of the RTC peripheral
 *
 */
typedef enum
{
	RTC_INSTANCE_0 = 0U
} RTC_InstanceType;


/** @brief Rtc mode */
typedef enum
{
    RTC_ALARM_INT = 0U,
    RTC_SECOND_INT = 1U,
    RTC_OVERFLOW_INT = 2U
} RTC_IntEventType;

/**
 * @brief The structure of the RTC processing handle
 *
 */
typedef struct _RTC_HandleType
{
	RTC_InstanceType eInstance;		/*!< RTC instance*/
	uint32_t u32AlarmValue;
	struct
	{
		void (*pAlarmCallback)(struct _RTC_HandleType *pHandle);		/*!< Alarm interrupt callback */
		void (*pSecondCallback)(struct _RTC_HandleType *pHandle);		/*!< Second interrupt callback */
		void (*pOverflowCallback)(struct _RTC_HandleType *pHandle);		/*!< Overflow interrupt callback */
	} tSettings;
} RTC_HandleType;

/** @brief Rtc initialization type */
typedef struct
{
    uint32_t u32AlarmValue;                         /**< rtc alarm value */
    RTC_ClkoutSecIntFreqType eSecIntAndClkoutFreq;  /**< Select the RTC Seconds interrupt and the RTC_CLKOUT prescaler output frequency */
    bool bStableClkoutFreq;                         /**< Select the RTC Seconds interrupt and the RTC_CLKOUT prescaler output frequency or RTC_CLKOUT is from the 32.768 kHz clock. */
    bool bAlarmIntEn;                               /**< whether enable rtc alarm interrupt */
    bool bSecondIntEn;                            	/**< whether to use the second interrupt */
    bool bOverflowIntEn;                          	/**< overflow interrupt notification function pointer */
} RTC_InitType;

typedef struct
{
    uint16_t    u16Year;
    uint8_t     u8Month;
    uint8_t     u8Day;
    uint8_t     u8Hour;
    uint8_t     u8Minute;
    uint8_t     u8Second;
} RTC_TimeDate;

typedef struct
{
    uint8_t     u8Interval;
    uint8_t     u8Value;
}RTC_Compensation;


/* global functions */
/**
 * @brief Initialize Rtc instance
 *
 * @param pRtcHandle the RTC instance
 * @param pInitStruct Rtc initialization structure
 * @note This function could only write once after POR.
 */
void RTC_Init(RTC_HandleType* pRtcHandle, const RTC_InitType *const pInitStruct);

/**
 * @brief De-initialize Rtc instance
 *
 * @param pRtcHandle the RTC instance
 */
void RTC_Deinit(RTC_HandleType* pRtcHandle);

/**
 * @brief Rtc start
 *
 * @param pRtcHandle the RTC instance
 */
void RTC_Start(RTC_HandleType* pRtcHandle);

/**
 * @brief Rtc stop
 *
 * @param pRtcHandle the RTC instance
 */
void RTC_Stop(RTC_HandleType* pRtcHandle);

/**
 * @brief set count value
 *
 * @param pRtcHandle the RTC instance
 * @param u32CounetValue The count value to set.
 */
void RTC_SetCountValue(RTC_HandleType* pRtcHandle, uint32_t u32CounetValue);

/**
 * @brief Rtc alarm value
 *
 * @param pRtcHandle the RTC instance
 * @param u32AlarmValue Input value
 */
void RTC_UpdateAlarmValue(RTC_HandleType* pRtcHandle, const uint32_t u32AlarmValue);

/**
 * @brief Check RTC overflow flag
 *
 * @param pRtcHandle the RTC instance
 * @return Overflow flag
 */
uint32_t RTC_CheckOverflowFlag(RTC_HandleType* pRtcHandle);

/**
 * @brief Get time and date
 *
 * @param pRtcHandle the RTC instance
 * @param pTimeDate the structure of time and date
 */
void RTC_GetTimeDate(RTC_HandleType* pRtcHandle, RTC_TimeDate * const pTimeDate);

/**
 * @brief Set time and date
 *
 * @param pRtcHandle the RTC instance
 * @param pTimeDate the structure of time and date
 */
void RTC_SetTimeDate(RTC_HandleType* pRtcHandle, const RTC_TimeDate * const pTimeDate);

/**
 * @brief Get time and date compensation information.
 *
 * @param pRtcHandle the RTC instance
 * @param pCompensation the structure to compensate time accuracy
 */
void RTC_GetCompensation(RTC_HandleType* pRtcHandle, RTC_Compensation * const pCompensation);

/**
 * @brief Set time and date compensation value.
 *
 * @param pRtcHandle the RTC instance
 * @param pCompensation the structure to compensate time accuracy
 */
void RTC_SetCompensation(RTC_HandleType* pRtcHandle, const RTC_Compensation * const pCompensation);

/** @brief RTC common interrupt function
 *
 * @param pRtcHandle the RTC instance
 */
void Rtc_CommonProcessInterrupt(RTC_HandleType* pRtcHandle);

/** @}*/

#endif

#endif
