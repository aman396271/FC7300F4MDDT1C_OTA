/**
 * @file module_driver_eftu_tim.h
 * @author flagchip
 * @brief eFTU tim driver type definition and API
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
   *   0.1.0       2023-12-15    Flagchip032   N/A          First version for FC7300
   *   2.0.0       2024-10-12    Flagchip070   N/A          Change version and release
   ******************************************************************************** */


#ifndef DRIVER_INCLUDE_MODULE_DRIVER_EFTU_TIM_H_
#define DRIVER_INCLUDE_MODULE_DRIVER_EFTU_TIM_H_

#include "hwa_eftu_tim.h"
#include "module_driver_eftu.h"

#if defined(EFTU_INSTANCE_COUNT) && (EFTU_INSTANCE_COUNT > 0)
#define EFTU_TIM_MODULE_ID  				2U

/**
 * @name  TIM API Service IDs
 *
 * @{
 */
#define EFTU_TIM_DETECT_ID											  	0U
#define EFTU_TIM_PWM_MEASUREMENT_ID										1U

/**
 * @name  TIM Dev Error Code
 * @brief Error Code of calling TIM apis
 *
 * @{
 */

#define EFTU_TIM_E_PARAM_CHANNEL				0U
#define EFTU_TIM_E_PARAM_INVALID_EDGE			1U
/** @}*/


typedef enum
{
    EFTU_TIM_INPUT_TIM_IN_X      =   0U,
    EFTU_TIM_INPUT_TIM_IN_X_1    =   1U,
    EFTU_TIM_INPUT_TIM_IN_AUX_IN =   2U,
}EFTU_TIM_ChnInputSelectType;

typedef enum
{
    EFTU_TIM_FILTERMODE_IMMEDIATEEDGEPROPAGATION 		= 0u,     	/**< \brief Immediate edge propagation mode */
    EFTU_TIM_FILTERMODE_INDIVIDUALDEGLITCHTIMEUPDOWN	= 1u,  		/**< \brief Individual deglitch time mode (Up Down) */
    EFTU_TIM_FILTERMODE_INDIVIDUALDEGLITCHTIMEHOLD		= 2u,    	/**< \brief Individual deglitch time mode (Hold) */
    EFTU_TIM_FILTERMODE_RESETCOUNTR     				= 3u,        /**< \brief Individual deglitch time mode (Reset)*/
} EFTU_TIM_FilterMode;

typedef enum
{
	EFTU_TIM_CH_0 = 0U,
	EFTU_TIM_CH_1 = 1U,
	EFTU_TIM_CH_2 = 2U,
	EFTU_TIM_CH_3 = 3U,
	EFTU_TIM_CH_4 = 4U,
	EFTU_TIM_CH_5 = 5U,
	EFTU_TIM_CH_6 = 6U,
	EFTU_TIM_CH_7 = 7U,
}EFTU_TIM_ChannelIndex;

typedef struct _EFTU_TIM_HandleType
{
	EFTU_InstanceType 		eInstance;

	EFTU_TIM_Type *pTim;
	struct
	{
		boolean			bGlitchIrqStatus;
		boolean         bEcntOverflowIrqStatus;
		boolean			bGprOverflowIrqStatus;
		boolean			bTimeOutIrqStatus;
		boolean    		bOverflowCntIrqStatus;
		boolean         bNewDataIrqStatus;

		uint32_t u32Gpr0Value;
		uint32_t u32Gpr1Value;
		uint32_t u32CntsValue;
		uint32_t u32CntValue;
		uint32_t u32DataCoherentStatus;

		void(*pTimChannelIrqCallback)(struct _EFTU_TIM_HandleType *pHandle,uint8_t u8TimChannelIndex);
	}tTimChnStatus[EFTU_TIM_CHANNEL_COUNT];

}EFTU_TIM_HandleType;


typedef struct
{
	boolean        			 bEnFilter;
    EFTU_TIM_FltSrcType   	 eFliterClock;							/*Filter clock */
    boolean                  bIrqOnGlitch;
    EFTU_TIM_FilterMode eRisingEdgeMode;
    EFTU_TIM_FilterMode eFallingEdgeMode;
    uint8_t                 u8RisingEdgeFilterTime;			/* in  Ticks*/
    uint8_t                 u8FallingEdgeFilterTime;			/* in  Ticks*/
}EFTU_TimFilterStruct;


typedef struct
{
	boolean	 			bIrqOnTimeout;
	uint32_t 			u32Timeout;
	EFTU_TIM_ClockSrcType		eTimeOutClkSrc;
	EFTU_TIM_TimeOutEdgeType eTimeOutSensitiveEgde;
}EFTU_TimeoutConfigStruct;



typedef  struct
{
	EFTU_TIM_ChannelIndex	eChannelIndex;
	EFTU_TimFilterStruct		tFilterConfig;
	EFTU_TimeoutConfigStruct		tTimeouConfig;

	boolean	 			bIrqOnNewVal;
	boolean				bIrqOnCntOveflow;
	boolean				bIrqOnECntOveflow;
	boolean				bIrqOnGprDataOverflow;

	boolean 			bExtCapEn;

	EFTU_TIM_ChnInputSelectType  eInputSrc;
	EFTU_TIM_ClockSrcType		eTimClockSrc;
	EFTU_TIM_ActiveEdgeType 		eActiveEdge;
	void(*pTimChannelIrqCallback)(struct _EFTU_TIM_HandleType *pHandle,uint8_t u8TimChannelIndex);
}EFTU_TimSignalDetectConfigStruct;


typedef  struct
{
	EFTU_TIM_ChannelIndex	eChannelIndex;
	EFTU_TimFilterStruct		tFilterConfig;
	EFTU_TimeoutConfigStruct		tTimeouConfig;

	boolean	 			bIrqOnNewVal;
	boolean				bIrqOnCntOveflow;
	boolean				bIrqOnECntOveflow;
	boolean				bIrqOnGprDataOverflow;

	boolean 			bExtCapEn;
	boolean				bSwap_Capture;
	boolean				bImmStart;

	EFTU_TIM_ChnInputSelectType  eInputSrc;
	EFTU_TIM_ClockSrcType		eTimClockSrc;
	EFTU_TIM_ActiveEdgeType 		eActiveEdge;

	EFTU_TIM_TbuTs0ResType     eTimTbs0align;
	void(*pTimChannelIrqCallback)(struct _EFTU_TIM_HandleType *pHandle,uint8_t u8TimChannelIndex);
}EFTU_TimSignalMeasurementConfigStruct;


/**
 * @brief Config Tim edge detect function
 * @param pTimHandle  Tim processing handle
 * @param pInitStruct  Tim Signal Detect InitStruct
 */
void EFTU_Tim_EdgeDetectChannelInit(EFTU_TIM_HandleType *pTimHandle, const EFTU_TimSignalDetectConfigStruct *pInitStruct);

/**
 * @brief Config Tim signal measurement  function
 * @param pTimHandle  Tim processing handle
 * @param pInitStruct  Tim Signal measurement InitStruct
 */
void EFTU_Tim_PwmMeasurementInit(EFTU_TIM_HandleType *pTimHandle, const EFTU_TimSignalMeasurementConfigStruct *pInitStruct);

/**
 * @brief Enable Tim channel function
 * @param pTimHandle  Tim processing handle
 * @param eChannelIndex  Tim channel Index
 */
void EFTU_Tim_EnableChannel(EFTU_TIM_HandleType *pTimHandle,const EFTU_TIM_ChannelIndex eChannelIndex);

/**
 * @brief Disable Tim channel function
 * @param pTimHandle  Tim processing handle
 * @param eChannelIndex  Tim channel Index
 */
void EFTU_Tim_DisableChannel(EFTU_TIM_HandleType *pTimHandle,const EFTU_TIM_ChannelIndex eChannelIndex);

/**
 * @brief Update Tim channel capture value.
 * @param pTimHandle  Tim processing handle
 * @param eChannelIndex  Tim channel Index
 */
void EFTU_TimUpdateNewValue(EFTU_TIM_HandleType *pTimHandle,const EFTU_TIM_ChannelIndex eChannelIndex);

/**
 * @brief Tim Interrupt process.
 * @param pTimHandle  Tim processing handle
 * @param u8StartChannelIndex  Tim  Irq start channel Index
 */
void EFTU_TIM_IrqHandler(EFTU_TIM_HandleType *pTimHandle, uint8_t u8StartChannelIndex);

#endif /* defined(EFTU_INSTANCE_COUNT) && (EFTU_INSTANCE_COUNT > 0) */
#endif /* DRIVER_INCLUDE_MODULE_DRIVER_EFTU_TIM_H_ */
