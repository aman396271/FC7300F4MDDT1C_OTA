/**
 * @file module_driver_fcpit.h
 * @author Flagchip
 * @brief FCPIT driver type definition and API
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
   *   0.1.0       2023-12-15    Flagchip071   N/A          First version for FC7300
   *   2.0.0       2024-10-12    Flagchip071   N/A          Change version and release
   ******************************************************************************** */

#ifndef _DRIVER_MODULE_DRIVER_FCPIT_H_
#define _DRIVER_MODULE_DRIVER_FCPIT_H_
#include "HwA_fcpit.h"

#if FCPIT_INSTANCE_COUNT > 0U

/**
 * @addtogroup module_driver_fcpit
 * @{
 */


/**
 * @name  FCPIT API Service IDs
 *
 * @{
 */
#define FCPIT_COMMON_INIT_ID 							0U
#define FCPIT_CHANNEL_INIT_ID 							1U
#define FCPIT_INIT_TRIGGER_ID 							2U
#define FCPIT_DE_INIT_ID 								3U
#define FCPIT_INIT_INTERRUPT_ID 						4U
#define FCPIT_ENABLE_INTERRUPT_ID 						5U
#define FCPIT_DISABLE_INTERRUPT_ID 						6U
#define FCPIT_START_ID 									7U
#define FCPIT_STOP_ID 									8U
#define FCPIT_UPDATEVALUE_ID 							9U
#define FCPIT_UPDATEVALUE_IMMEDIATE_ID 					10U
# if FCPIT_SUPPORT_GET_CURRENT_VALUE == STD_ON
#define FCPIT_GET_CHANNELVALUE_ID 						11U
#endif
/** @}*/

/**
 * @name  FCPIT Dev Error Code
 * @brief Error Code of calling FCPIT apis
 *
 * @{
 */
#define FCPIT_STATUS_FUNCTION_ERROR			0x0U
#define FCPIT_E_PARAM_CHANNEL   			0x02U
#define FCPIT_E_PARAM_POINTER   			0x03U
#define FCPIT_E_PARAM_COUNT					0x04U
#define FCPIT_E_PARAM_INVALID				0x05U
/** @}*/


/** @brief FCPIT instance */
typedef enum
{
    FCPIT_INSTANCE_0,
#if FCPIT_INSTANCE_COUNT > 1u
    FCPIT_INSTANCE_1,
#endif
    FCPIT_INSTANCE_MAX
} FCPIT_InstanceType;


/** @brief Fcpit trigger source */
typedef enum
{
    FCPIT_TRIGGER_INTERNAL_0 = 0,
    FCPIT_TRIGGER_INTERNAL_1,
    FCPIT_TRIGGER_INTERNAL_2,
    FCPIT_TRIGGER_INTERNAL_3,
    FCPIT_TRIGGER_EXTERNAL,
	FCPIT_NO_TRIGGER
} FCPIT_TriggerSelectType;

/** @brief callback function type */
typedef void (*FCPIT_InterruptCallBackType)(void);

typedef struct
{
    FCPIT_ChannelType eFcpitChannel;            /**< Fcpit channel number */
    FCPIT_TriggerSelectType eTriggerSel;        /**< trigger source */
    bool bStartOnTrigger;                       /**< Fcpit timer start when triggered */
    bool bStopOnInterrupt;                      /**< Fcpit timer stop on interrupt */
    bool bReloadOnTrigger;                      /**< Fcpit timer reload when triggered */
} FCPIT_TrggerType;



typedef struct
{
	bool bDebugEn;                              /**< whether to use debug mode ,if enable this mode, the counter will stop when debugging. */
	bool bLowPowerModeEn;                       /**< Configure the timer channels to continue running or stop when the device enters the LPM mode */
}FCPIT_CommonInitType;

typedef struct _FCPIT_HandleType
{
	FCPIT_InstanceType eInstance;

	bool bDebugEn;                              /**< whether to use debug mode ,if enable this mode, the counter will stop when debugging. */
	bool bLowPowerModeEn;                       /**< Configure the timer channels to continue running or stop when the device enters the LPM mode */

	struct
	{
		FCPIT_TimerModeType eMode;                  /**< Fcpit counter mode */
		bool bChainModeEn;                          /**< whether to use chain mode, if use this mode, channel must not be the channel 0 */
		uint32_t u32TimerValue;                     /**< timer compare value, the range of value is related to the counter mode */
		bool bStartOnTrigger;                       /**< Fcpit timer start when triggered */
		bool bStopOnInterrupt;                      /**< Fcpit timer stop on interrupt */
		bool bReloadOnTrigger;                      /**< Fcpit timer reload when triggered */
		FCPIT_TriggerSelectType eTriggerSel;        /**< trigger source */

		bool bChannelIsrEn;                         /**< whether to use interrupt */
		void(*pChannelCallback)(struct _FCPIT_HandleType  *pHandle,uint32_t u32channel);
		bool bChannelStarted;
	}tChannelStatus[MAX_FCPIT_CHANNEL_NUM];

}FCPIT_HandleType;

/** @brief Fcpit interrupt structure */
typedef struct
{
    FCPIT_ChannelType eFcpitChannel;            /**< Fcpit channel number */
    bool bChannelIsrEn;                         /**< whether to use interrupt */
    void(*pChannelCallback)(struct _FCPIT_HandleType  *pHandle,uint32_t u32channel);     /**< interrupt notification function */
} FCPIT_IntType;

/** @brief Fcpit initialization type */
typedef struct
{
    FCPIT_ChannelType eFcpitChannel;            /**< Fcpit channel number */
    FCPIT_TimerModeType eMode;                  /**< Fcpit counter mode */
    bool bChainModeEn;                          /**< whether to use chain mode, if use this mode, channel must not be the channel 0 */
    uint32_t u32TimerValue;                     /**< timer compare value, the range of value is related to the counter mode */
} FCPIT_ChannelInitType;

/* global functions */
/**
 * @brief Initialize Fcpit instance common feature.
 * @param pFcpitHandle Fcpit processing handle
 * @param pInitStruct Fcpit initialization structure
 */
void FCPIT_CommonInit(FCPIT_HandleType *pFcpitHandle,const FCPIT_CommonInitType * pInitStruct);


/* global functions */
/**
 * @brief Initialize Fcpit instance.
 * @param pFcpitHandle Fcpit processing handle
 * @param pInitStruct Fcpit initialization structure
 */
void FCPIT_ChannelInit(FCPIT_HandleType *pFcpitHandle,const FCPIT_ChannelInitType * pInitStruct);

/**
 * @brief Initialize Fcpit trigger configuration
 * @param pFcpitHandle Fcpit processing handle
 * @param pTrgStruct Fcpit trigger structure
 */
void FCPIT_InitTrigger(FCPIT_HandleType *pFcpitHandle,const FCPIT_TrggerType * pTrgStruct);

/**
 * @brief De-initialize Fcpit instance.
 * @param pFcpitHandle Fcpit processing handle
 */
void FCPIT_Deinit(FCPIT_HandleType *pFcpitHandle);

/**
 * @brief Initialize Fcpit interrupt functionality
 * @param pFcpitHandle Fcpit processing handle
 * @param pIntStruct Fcpit interrupt structure
 * @note this function will stop timer
 */
void FCPIT_InitInterrupt(FCPIT_HandleType *pFcpitHandle,const FCPIT_IntType * pIntStruct);

/**
 * @brief Enable Fcpit interrupt
 * @param pFcpitHandle Fcpit processing handle
 * @param eChannel Fcpit channel
 */
void FCPIT_EnableInterrupt(FCPIT_HandleType *pFcpitHandle,const FCPIT_ChannelType eChannel);

/**
 * @brief Disable Fcpit interrupt
 * @param pFcpitHandle Fcpit processing handle
 * @param eChannel Fcpit channel
 */
void FCPIT_DisableInterrupt(FCPIT_HandleType *pFcpitHandle,const FCPIT_ChannelType eChannel);

/**
 * @brief Fcpit start timer
 * @param pFcpitHandle Fcpit processing handle
 * @param eChannel Fcpit channel
 */
void FCPIT_Start(FCPIT_HandleType *pFcpitHandle,const FCPIT_ChannelType eChannel);

/**
 * @brief Fcpit stop
 * @param pFcpitHandle Fcpit processing handle
 * @param eChannel Fcpit channel
 */
void FCPIT_Stop(FCPIT_HandleType *pFcpitHandle,const FCPIT_ChannelType eChannel);

/**
 * @brief Update Fcpit channel value
* @param pFcpitHandle Fcpit processing handle
 * @param eChannel Fcpit channel
 * @param u32ChannelValue in/Out value
 */
void FCPIT_UpdateChannelValue(FCPIT_HandleType *pFcpitHandle,const FCPIT_ChannelType eChannel, const uint32_t u32ChannelValue);

/**
 * @brief Immediately update Fcpit channel value
* @param pFcpitHandle Fcpit processing handle
 * @param eChannel Fcpit channel
 * @param u32ChannelValue in/Out value
 */
void FCPIT_ImmediateUpdateChannelValue(FCPIT_HandleType *pFcpitHandle,const FCPIT_ChannelType eChannel, const uint32_t u32ChannelValue);


#if (FCPIT_SUPPORT_GET_CURRENT_VALUE == STD_ON)
/**
 * @brief Get the  Fcpit channel value
* @param pFcpitHandle Fcpit processing handle
 * @param eChannel Fcpit channel
 * @param u32ChannelValue in/Out value
 */
void FCPIT_GetChannelValue(FCPIT_HandleType *pFcpitHandle,const FCPIT_ChannelType eChannel, uint32_t *u32ChannelValue);
#endif
/**
 * @brief fcpit interrupt function.
* @param pFcpitHandle Fcpit processing handle
 */
void FCPITn_IRQHandler(FCPIT_HandleType *pFcpitHandle);

/** @}*/ /* module_driver_fcpit */

#endif /* #if FCPIT_INSTANCE_COUNT > 0U */

#endif
