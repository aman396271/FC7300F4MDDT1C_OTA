/**
 * @file module_driver_ism.h
 * @author flagchip
 * @brief ISM driver type definition and API
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
   *   0.1.0       2023-12-15    Flagchip084   N/A          First version for FC7300
   *   2.0.0       2024-10-12    Flagchip084   N/A          Change version and release
   ******************************************************************************** */

#ifndef _DRIVER_MODULE_DRIVER_ISM_H_
#define _DRIVER_MODULE_DRIVER_ISM_H_

#include "HwA_ism.h"

#if ISM_INSTANCE_COUNT > 0U

/**
 * @addtogroup module_driver_ism
 * @{
 */

#define ISM_ECM_CHANNEL(x)  (1<<(x))
#define ISM_LAM_CHANNEL(x)  (1<<(x))
#define ISM_FPC_CHANNEL(x)  (1<<(x))




#define ECM_INSTANCE_COUNT (4U)

typedef enum
{
    ISM_INSTANCE_0 = 0U,  /*!< ISM instance 0 is selected. */
} ISM_InstanceType;


#define ISM_COMMON_INIT_ID 							0U
#define ISM_FPC_CONFIG_ID 							1U
#define ISM_FPC_ENABLE_ID 							2U
#define ISM_LAM_CONFIG_ID 							3U
#define ISM_LAM_ENABLE_ID 							4U
#define ISM_ECM_CONFIG_ID 							5U


#define ISM_STATUS_FUNCTION_ERROR			0x0U
#define ISM_E_PARAM_CHANNEL   			0x02U
#define ISM_E_PARAM_POINTER   			0x03U
#define ISM_E_PARAM_COUNT				0x04U
#define ISM_E_PARAM_INVALID				0x05U


typedef enum
{
    FPC_RISING_GLITCH_DETECTED = 0x01U,    /*!< PFC Rising Glitch Detected. */
    FPC_FALLING_GLITCH_DETECTED = 0x02U    /*!< PFC Falling Glitch Detected. */
} FPC_GlitchDetectType;


typedef struct _ISM_HandleType
{
	boolean bEnable;
	boolean bIntEnable;
	void(*pEventIsrCalllback)(struct _ISM_HandleType *pHandle,uint16_t u16Lamflags);
	void(*pEcmEventIsrCalllback)(struct _ISM_HandleType *pHandle,uint8_t u8EcmFlags);

	struct
	{
		uint32_t u32Value;
		uint32_t u32LamChannelRouter;
	}tEcmEventStatus[ECM_INSTANCE_COUNT];

	struct
	{
		bool bFpcChannelEn;
		bool bGlitchIntEnable;
		ISM_FPC_EdgeDetectModeType eFallingDetectMode;
		ISM_FPC_EdgeDelayModeType eFallingDelayNode;
		ISM_FPC_EdgeDetectModeType eRisingDetectMode;
		ISM_FPC_EdgeDelayModeType eRisingDelayNode;
		uint16_t u32ThresholdValue;
		void(*pFpcChannelCalllback)(struct _ISM_HandleType *pHandle,uint32_t u32channel);
	}tIsmFpcChannelStatus[FPC_INSTANCE_COUNT];

	struct
	{
		bool bLamChannelEn;
		bool bOvflIntEnable;
		uint8_t u8RcsSel;
		uint8_t u8MonSel;
		ISM_LAM_InvertEventWindowType eInvWin;
		ISM_LAM_EventWindowEdgeType eWinEdgSel;
		ISM_LAM_EventWindowSelectType eEvtWinSel;
		ISM_LAM_RunModeSelectType eRunMode;
		ISM_LAM_MonitorSourceType eMonSrcSel;
		ISM_LAM_InvertMonitorType eInvMon;
		ISM_LAM_InvertReferenceType eInvRef;
		uint32_t u32EvtCntThreshold;
		void(*pLamChannelOverCalllback)(struct _ISM_HandleType *pHandle,uint32_t u32channel);
	}tIsmLamChannelStatus[LAM_INSTANCE_COUNT];
}ISM_HandleType;

typedef struct
{
	uint8_t u8FpcIndex;
    bool bGlitchIntEnable;
    ISM_FPC_EdgeDetectModeType eFallingDetectMode;
    ISM_FPC_EdgeDelayModeType eFallingDelayNode;
    ISM_FPC_EdgeDetectModeType eRisingDetectMode;
    ISM_FPC_EdgeDelayModeType eRisingDelayNode;
    uint16_t u32ThresholdValue;
    void(*pFpcChannelCalllback)(ISM_HandleType *pHandle,uint32_t u32channel);
} ISM_FpcCfgType;

typedef struct
{
	uint8_t u8LamIndex;
    bool bOvflIntEnable;
    uint8_t u8RcsSel;
    uint8_t u8MonSel;
    ISM_LAM_InvertEventWindowType eInvWin;
    ISM_LAM_EventWindowEdgeType eWinEdgSel;
    ISM_LAM_EventWindowSelectType eEvtWinSel;
    ISM_LAM_RunModeSelectType eRunMode;
    ISM_LAM_MonitorSourceType eMonSrcSel;
    ISM_LAM_InvertMonitorType eInvMon;
    ISM_LAM_InvertReferenceType eInvRef;
    uint32_t u32EvtCntThreshold;
    void(*pLamChannelOverCalllback)(ISM_HandleType *pHandle,uint32_t u32channel);
} ISM_LamCfgType;


typedef struct
{
	bool bIsmEnable;
    bool bIntEnable;
    void(*pEcmEventIsrCalllback)(ISM_HandleType *pHandle,uint8_t u8EcmFlags);
    void(*pEventIsrCalllback)(ISM_HandleType *pHandle,uint16_t u16Lamflags);
} ISM_InitCfgType;


/**
 * @brief Init the ISM.
 *
 * @param pIsmHandle Ism processing handle.
 * @param pInitConfig ISMInstance initial configuration.
 */
void ISM_CommonInit(ISM_HandleType *pIsmHandle,const ISM_InitCfgType *pInitConfig);


/**
 * @brief Config the FPC channel.
 *
 * @param pIsmHandle Ism processing handle.
 * @param u8FpcIndex FPC index.
 * @param pConfig FPC configuration.
 */
void ISM_FpcConfig(ISM_HandleType *pIsmHandle,uint8_t u8FpcIndex, const ISM_FpcCfgType *pConfig);

/**
 * @brief Enable FPC channel.
 *
 * @param pIsmHandle Ism processing handle.
 * @param u8FpcIndex FPC index.
 * @param bEnable Enable value.
 */
void ISM_FpcEnable(ISM_HandleType *pIsmHandle,uint8_t u8FpcIndex, bool bEnable);

/**
 * @brief Config the LAM channel.
 *
 * @param pIsmHandle Ism processing handle.
 * @param u8LamIndex LAM index.
 * @param pConfig LAM configuration.
 */
void ISM_LamConfig(ISM_HandleType *pIsmHandle,uint8_t u8LamIndex, const ISM_LamCfgType *pConfig);


/**
 * @brief Enable LAM Channel.
 *
 * @param pIsmHandle Ism processing handle.
 * @param u8LamIndex LAM index.
 * @param bEnable Enable value.
 */
void ISM_LamEnable(ISM_HandleType *pIsmHandle,uint8_t u8LamIndex, bool bEnable);

/**
 * @brief Enable LAM system event
 *
 * @param pIsmHandle Ism processing handle.
 * @param u8LamIndex Lam channel index.
 * @param u8EcmIndex Ecm channel index.
 * @param u8EventCount Threshold of the ECM channel counter value.
 */
void ISM_EcmEventConfig(ISM_HandleType *pIsmHandle,uint8_t u8LamIndex, uint8_t u8EcmIndex, uint8_t u8EventCount);


/**
 * @brief Get the channels mask of ECM that has event happened.
 *
 * @return  Channels mask.
 */
uint8_t ISM_GetEcmEventHappenedChannels(void);

/**
 * @brief Get the channels mask of LAM that has event happened.
 *
 * @return Channels mask.
 */
uint16_t ISM_GetLamEventHappenedChannels(void);

/**
 * @brief Clear the channels status of ECM that has event happened.
 *
 * @param u8Channels Channels mask.
 */
void ISM_ClearEcmEventHappenedChannels(uint8_t u8Channels);

/**
 * @brief  Clear the channels status of LAM that has event happened.
 *
 * @param u16Channels Channels mask.
 */
void ISM_ClearLamEventHappenedChannels(uint16_t u16Channels);


/**
 * @brief Enable ECM system event
 *
 * @param u32Channels Channel masks.
 * @param bEnable Enable value.
 */
void ISM_EnableEcmSystemEvent(uint32_t u32Channels, bool bEnable);

/**
 * @brief Enable LAM system event
 *
 * @param u32Channels Channel masks.
 * @param bEnable Enable value.
 */
void ISM_EnableLamSystemEvent(uint32_t u32Channels, bool bEnable);



/**
 * @brief Clears the value of the LAM counter.
 *
 * @param u32LamIndex Lam channel index.
 */
void ISM_ClearLamStatusCounter(uint8_t u8LamIndex);

/**
 * @brief Gets the value of the LAM counter when a LAM event is triggered.
 *
 * @param u32LamIndex Lam channel index.
 * @return Counter value.
 */
uint32_t  ISM_GetLamStatusCounter(uint8_t u8LamIndex);

/**
 * @brief Clears LAM Timer Overflow Flag.
 *
 * @param u32LamIndex Lam channel index.
 */
void ISM_ClearLamStatusOvfl(uint8_t u8LamIndex);

/**
 * @brief Gets LAM Timer Overflow Flag.
 *
 * @param u32LamIndex Lam channel index.
 * @return Overflow flag.
 */
bool ISM_GetLamStatusOvfl(uint8_t u8LamIndex);

/**
 * @param pIsmHandle Ism processing handle.
 * @brief ISM Interrupt Process Function.
 */
void ISMn_IRQHandler(ISM_HandleType *pIsmHandle);

/** @}*/ /* module_driver_ism. */

#endif /* #if ISM_INSTANCE_COUNT > 0U */

#endif
