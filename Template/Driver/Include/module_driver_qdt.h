/**
 * @file module_driver_qdt.h
 * @author Flagchip
 * @brief FC7xxx QDT driver type definition and API
 * @version 2.0.0
 * @date 2024-08-28
 *
 * SDK Version: 2.6.0
 *

 * @copyright Copyright (c) 2024 Flagchip Semiconductors Co., Ltd.
 *
 */

/* ********************************************************************************
   *   Revision History:
   *
   *   Version     Date          Initials      CR#          Descriptions
   *   ---------   ----------    ------------  ----------   ---------------
   *   0.1.0       2023-12-15    Flagchip113   N/A          First version for FC7300
   *   2.0.0       2024-10-12    Flagchip113   N/A          Change version and release
   ******************************************************************************** */

#ifndef _DRIVER_MODULE_DRIVER_QDT_H_
#define _DRIVER_MODULE_DRIVER_QDT_H_
 
#include "HwA_qdt.h"

#if QDT_INSTANCE_COUNT > 0U
#define QDT_DEV_ERROR_REPORT    STD_ON
/**
 * @name  SENT API Service IDs
 * @brief Defines the service IDs for the FCUART module, which are used to identify different functions or services provided by the SENT layer.
 *        These IDs are utilized when communicating with the SENT module, enabling calls to or responses from various functions.
 *
 * @{
 */
#define QDT_INIT_ID                            0U            /**< link to "QDT_Init" API. */
#define QDT_DEINIT_ID                          1U            /**< link to "QDT_Deinit" API. */
#define QDT_CHANNEL_INIT_ID                    2U            /**< link to "QDT_Channel_Init" API. */
#define QDT_RESTART_MEASUREMENT_ID             3U            /**< link to "QDT_ReStartMeasurement" API. */
#define QDT_GET_CHANNEL_FLAG_ID                4U            /**< link to "QDT_GetChannelFlag" API. */
#define QDT_CLEAR_CHANNEL_FLAG_ID              5U            /**< link to "QDT_ClearChannelFlag" API. */
#define QDT_GET_EDGE_NUMBER_ID                 6U            /**< link to "QDT_GetEdgeNumber" API. */
#define QDT_GET_CV_ID                          7U            /**< link to "QDT_GetCV" API. */
#define QDT_GET_REVCNT_ID                      8U            /**< link to "QDT_GetREVCNT" API. */
#define QDT_GET_REVCNT_HOLD_ID                 9U            /**< link to "QDT_GetREVCNT_HOLD" API. */
#define QDT_GET_POSCNT_ID                      10U           /**< link to "QDT_GetPOSCNT" API. */
#define QDT_GET_POSCNT_HOLD_ID                 11U           /**< link to "QDT_GetPOSCNT_HOLD" API. */
#define QDT_GET_POSDCNT_ID                     12U           /**< link to "QDT_GetPOSDCNT" API. */
#define QDT_GET_POSDCNT_HOLD_ID                13U           /**< link to "QDT_GetPOSDCNT_HOLD" API. */
#define QDT_GET_LECNT_ID                       14U           /**< link to "QDT_GetLECNT" API. */
#define QDT_GET_LECNT_HOLD_ID                  15U           /**< link to "QDT_GetLECNT_HOLD" API. */
#define QDT_GET_POSDTMRCNT_ID                  16U           /**< link to "QDT_GetPOSDTMRCNT" API. */
#define QDT_GET_POSDTMRCNT_HOLD_ID             17U           /**< link to "QDT_GetPOSDTMRCNT_HOLD" API. */
#define QDT_GET_SPEED_ID                       18U           /**< link to "QDT_GetSpeed" API. */

/** @}*/

/**
 * @name  SENT Dev Error Code
 * @brief Error Code of calling SENT apis
 *
 * @{
 */
#define QDT_E_PARAM_POINTER            0x01U         /**< The SENT pointer parameter is NULL. */
#define QDT_E_ALREADY_INIT             0x02U         /**< The SENT has been initialized. */
#define QDT_E_UNINIT                   0x03U         /**< The SENT is not initialized. */
#define QDT_E_PARAM_INSTANCE           0x04U         /**< The SENT instance number is out of range. */
#define QDT_E_PARAM_CHANNEL            0x05U         /**< The SENT channel number is out of range. */
#define QDT_E_PARAM_GENERAL            0x06U         /**< The SENT parameter is incorrect or out of range. */
#define QDT_E_PARAM_MODE               0x07U         /**< The SENT mode is incorrect. */
/** @}*/

/* ################################################################################## */
/* ################################### Type define ################################## */

/**
 * @brief QDT ISR callback function prototype
 *
 */
typedef void (*QDT_CallbackType)(void);

/**
 * @addtogroup module_driver_can
 * @{
 */

typedef enum
{
    QDT_READY  = 0u,
    QDT_INIT   = 1U,
    QDT_DEINIT = 2u
}QDT_StatusType;

/**
 * @brief QDT operation return values
 *
 */
typedef enum
{
    QDT_RETURN_OK                 = 0x00U,   /*!< The QDT operation is succeeded */
    QDT_RETURN_E_NOT_OK           = 0x01U,   /*!< The QDT operation is failed */
    QDT_RETURN_E_ALREADY_INIT     = 0x02U,   /*!< The QDT has been initialized. */
    QDT_RETURN_E_UNINIT           = 0x03U,   /*!< The QDT is not initialized */
    QDT_RETURN_E_PARAM            = 0x04U,   /*!< The QDT parameter is incorrect or out of range. */
	QDT_RETURN_E_SEQUENCE         = 0x05U,
	QDT_RETURN_E_MODE             = 0x60U
}Qdt_ReturnType;

typedef enum
{
    QDT_INSTANCE_0   = 0u,
    QDT_INSTANCE_1   = 1u,
    QDT_INSTANCE_2   = 2u,
    QDT_INSTANCE_3   = 3u,
    QDT_INSTANCE_MAX = 4u
}QDT_InstanceType;

/**
* @brief QDT clock source type
*
*/
typedef enum
{
    QDT_CLOCK_NONE =             0u,  /**< No clock selected. */
    QDT_CLOCK_INTERNAL_BUSCLK  = 1u,  /**< QDT input clock from bus clock. */
	QDT_CLOCK_INTERNAL_PCCCLK  = 2u,  /**< QDT input clock from pcc clock. PCC_SEL is not 0. */
    QDT_CLOCK_EXTERNAL_TCLK0   = 3u,  /**< External pin input clock from QDT_TCLK0 pin. Only valid when PCC_SEL is 0. */
    QDT_CLOCK_EXTERNAL_TCLK1   = 4u,  /**< External pin input clock from QDT_TCLK1 pin. Only valid when PCC_SEL is 0. */
    QDT_CLOCK_EXTERNAL_TCLK2   = 5u,  /**< External pin input clock from QDT_TCLK2 pin. Only valid when PCC_SEL is 0. */
}QDT_ClockSourceType;

typedef enum
{
    QDT_COUNTER_PRESCALE_DIV_1   = 0u,
    QDT_COUNTER_PRESCALE_DIV_2   = 1u,
    QDT_COUNTER_PRESCALE_DIV_4   = 2u,
    QDT_COUNTER_PRESCALE_DIV_8   = 3u,
    QDT_COUNTER_PRESCALE_DIV_16  = 4u,
    QDT_COUNTER_PRESCALE_DIV_32  = 5u,
    QDT_COUNTER_PRESCALE_DIV_64  = 6u,
    QDT_COUNTER_PRESCALE_DIV_128 = 7u
}QDT_CounterPrescaleType;

typedef enum
{
    QDT_FILTER_PRESCALE_DIV_1   = 0u,
    QDT_FILTER_PRESCALE_DIV_2   = 1u,
    QDT_FILTER_PRESCALE_DIV_3   = 2u,
    QDT_FILTER_PRESCALE_DIV_4   = 3u,
    QDT_FILTER_PRESCALE_DIV_5   = 4u,
    QDT_FILTER_PRESCALE_DIV_6   = 5u,
    QDT_FILTER_PRESCALE_DIV_7   = 6u,
    QDT_FILTER_PRESCALE_DIV_8   = 7u,
    QDT_FILTER_PRESCALE_DIV_9   = 8u,
    QDT_FILTER_PRESCALE_DIV_10  = 9u,
    QDT_FILTER_PRESCALE_DIV_11  = 10u,
    QDT_FILTER_PRESCALE_DIV_12  = 11u,
    QDT_FILTER_PRESCALE_DIV_13  = 12u,
    QDT_FILTER_PRESCALE_DIV_14  = 13u,
    QDT_FILTER_PRESCALE_DIV_15  = 14u,
    QDT_FILTER_PRESCALE_DIV_16  = 15u
}QDT_FilterPrescaleType;

typedef enum
{
    QDT_CHANNEL_0_PHA  = 0u,
    QDT_CHANNEL_1_PHB  = 1u,
    QDT_CHANNEL_2_PHZ  = 2u,
    QDT_CHANNEL_3_HOME = 3u,
    QDT_CHANNEL_MAX    = 4u
}QDT_ChannelIndexType;

typedef enum
{
    QDT_CHANNEL_NOT_USED            = 0u,
    QDT_CHANNEL_IC_MODE             = 1u,
    //In ICM mode, pair of channels are used to measure, Only need configure the even channel
    QDT_CHANNEL_ICDM_MODE           = 2u,
    QDT_CHANNEL_ICPM_MODE           = 3u,
    QDT_CHANNEL_ICENM_MODE          = 4u,
    QDT_CHANNEL_ICEXPENM_MODE       = 5u,
    QDT_CHANNEL_QUAD_MODE           = 6u
}QDT_ChannelModeType;

typedef enum
{
    QDT_CAPTURE_RISING_EDGE      = 0u,
    QDT_CAPTURE_FALLING_EDGE     = 1u,
    QDT_CAPTURE_BOTH_EDGE        = 2u
}QDT_CaptureEdgeType;

typedef enum
{
	QDT_CHANNEL_MATCH_POSCNT  = 0u,
	QDT_CHANNEL_MATCH_REVCNT  = 1u,
	QDT_CHANNEL_MATCH_DISABLE = 2u
}QDT_ChannelMatchType;

typedef struct
{
	//input
	uint32_t    u32ClkFreq;
	uint32_t    u32LecntLarge;
	uint32_t    u32Line;
	//output
	float    fSpeed;
}QDT_SpeedResultType;

typedef struct
{
    bool        bEnWDOG;
    bool        bEnWDOGFInt;
    uint16_t    u16Timeout;
    QDT_CallbackType pWDOGFCallback;
}QDT_WdogConfigType;

typedef struct
{
    bool    bEnCVSyncTriggerMode;  /**< True: Sync CV register with trigger mode. */
    bool    bEnSoftTriggerReset;   /**< True: Allow SW event to reset POSCNT, REVCNT and POSDCNT. FALSE: SW event will only reset the POSCNT. */
    bool    bEnHardTriggerInput;   /**< Enables hardware trigger to the synchronization and reset. */
    bool    bEnHardTriggerReset;   /**< True: Allow HW event to reset POSCNT, REVCNT and POSDCNT. FALSE: HW event will not reset any Counter. */
    bool    bEnHardTriggerUpdate;  /**< Allow the hardware trigger to cause an update of the POSCNTH, REVCNTH and POSDCNTH registers */
}QDT_SyncModeConfigType;

typedef struct
{
    bool                    bEnDebugMode;      /**< Debug Mode Enable. true is disable, true is enable. */
    bool                    bEnMatchPulse;     /**< true means Match Trigger pulses when a match occurs between the position counters (POS) and the corresponding channel value (CV )
                                                 false means Match Trigger pulses when the POSCNT, REVCNT, or POSDCNT are read. */
    QDT_ClockSourceType     eClkSrcSel;        /**< Select the QDT clock source. */
    QDT_CounterPrescaleType eCounterPrescale;     /**< Setting the prescale of QDT counter clock frequency. */
	QDT_FilterPrescaleType  eFilterPrescale;
    bool                    bEnTOFInt;   /**< Timer Overflow Interrupt Enable. true is disable, false is enable. */
    QDT_CallbackType        pTOFCallback;
    QDT_WdogConfigType      tWdgConfig;
    QDT_SyncModeConfigType  tSyncModeConfig;
}QDT_ConfigType;

typedef struct
{
    QDT_CaptureEdgeType eEdge;       /**< Select which edge to capture. */
    bool                bFromRevCNT; /**< FALSE: capture POSCNT into the CV register, TRUE: capture REVCNT into the CV register */
    bool                bResetPOSCNT;   /**< FALSE:QDT counter is not reset when the selected channel (n) input event is detected */
}QDT_IC_ConfigType;

typedef struct
{
    bool        bHighActive;      /**< Indicate high /low valid of input signal. */
    bool        bContinueMeasure; /**< indicates whether continue to measure. */
    bool        bStartWIthActive; /**< TRUE: the channel starts measuring after the first edge is detected.
                                       FALSE: the measurement starts immediately after activating the channel */
}QDT_ICDM_ConfigType;

typedef struct
{
    QDT_CaptureEdgeType   eEdge;  /**< please don't select both edge. */
    bool                  bContinueMeasure; /**< indicates whether continue to measure. */
    bool                  bStartWIthActive; /**< TRUE: the channel starts measuring after the first edge is detected.
                                       FALSE: the measurement starts immediately after activating the channel */
}QDT_ICPM_ConfigType;

typedef struct
{
    QDT_CaptureEdgeType  eEdge;       /**< Select which edge to capture. */
    uint32_t             u32StartPoint;
    uint32_t             u32EndPoint;
    bool                 bContinueMeasure; /**< indicates whether continue to measure. */
}QDT_ICENM_ConfigType;

typedef struct
{
    QDT_CaptureEdgeType eEdge;       /**< Select which edge to capture. */
    uint8_t     u8ExpectedNum;
    bool        bContinueMeasure; /**< indicates whether continue to measure. */
}QDT_ICEXPENM_ConfigType;

typedef struct
{
	bool      bPHANormalPolarity;
	bool      bPHBNormalPolarity;
    bool      bEnPHAPHBMode;       /**< true: Phase A and phase B encoding mode. false: Count and direction encoding mode */
	uint8_t   u8PHAInputFilter;
	uint8_t   u8PHBInputFilter;
	uint32_t  u32PHACV;
	uint32_t  u32PHBCV;	
	QDT_ChannelMatchType  ePHAMatchType;
	QDT_ChannelMatchType  ePHBMatchType;
}QDT_QUAD_PHAB_ConfigType;

typedef struct
{
	uint8_t   u8InputFilter;
	uint32_t  u32CV;
	QDT_ChannelMatchType eMatchType;
}QDT_QUAD_PHZ_HOME_ConfigType;

typedef struct
{
    QDT_ChannelIndexType   eChannelIndex;
    QDT_ChannelModeType    eChannelMode;   /**< Select Channel operation mode. */
    bool                   bEnChannelInt;
    QDT_CallbackType       pChannelCallback;
    union
    {
        QDT_IC_ConfigType            tICConfig;
        QDT_ICDM_ConfigType          tICDMConfig;
        QDT_ICPM_ConfigType          tICPMConfig;
        QDT_ICENM_ConfigType         tICENMConfig;
        QDT_ICEXPENM_ConfigType      tICEXPENMConfig;
        QDT_QUAD_PHAB_ConfigType     tPHABQUADConfig;
        QDT_QUAD_PHZ_HOME_ConfigType tPHZHOMEQUADConfig;
    };
}QDT_Channel_ConfigType;

typedef struct
{
    QDT_InstanceType  eInstance;
    QDT_StatusType    eStatus;
    
    struct
    {
        QDT_CallbackType    pTOFCallback;
        QDT_CallbackType    pWDOGFCallback;
        QDT_CallbackType    achannelCallback[QDT_CHANNEL_MAX];
        QDT_ChannelModeType aChannelMode[QDT_CHANNEL_MAX];
    }tSetting;
}QDT_HandleType;

void QDT_Init(QDT_HandleType *pSentHandle, QDT_ConfigType *pConfig);

void QDT_Deinit(QDT_HandleType *pSentHandle);

void QDT_Channel_Init(QDT_HandleType *pSentHandle, QDT_Channel_ConfigType *pConfig);

void QDT_ReStartMeasurement(QDT_HandleType *pSentHandle, uint8_t u8Channel);

void QDT_GetChannelFlag(QDT_HandleType *pSentHandle, uint8_t u8Channel, bool *pSet);

void QDT_ClearChannelFlag(QDT_HandleType *pSentHandle, uint8_t u8Channel);

void QDT_GetEdgeNumber(QDT_HandleType *pSentHandle, uint8_t u8Channel, uint32_t *pNumber);

void QDT_GetCV(QDT_HandleType *pSentHandle, uint8_t u8Channel, uint32_t *pCV);

void QDT_GetREVCNT(QDT_HandleType *pSentHandle, uint32_t *pREVCNT);

void QDT_GetREVCNT_HOLD(QDT_HandleType *pSentHandle, uint32_t *pREVCNTH);

void QDT_GetPOSCNT(QDT_HandleType *pSentHandle, uint32_t *pPOSCNT);

void QDT_GetPOSCNT_HOLD(QDT_HandleType *pSentHandle, uint32_t *pPOSCNTH);

void QDT_GetPOSDCNT(QDT_HandleType *pSentHandle, uint32_t *pPOSDCNT);

void QDT_GetPOSDCNT_HOLD(QDT_HandleType *pSentHandle, uint32_t *pPOSDCNTH);

void QDT_GetLECNT(QDT_HandleType *pSentHandle, uint32_t *pLECNT);

void QDT_GetLECNT_HOLD(QDT_HandleType *pSentHandle, uint32_t *pLECNTH);

void QDT_GetPOSDTMRCNT(QDT_HandleType *pSentHandle, uint32_t *pPOSDTMRCNT);

void QDT_GetPOSDTMRCNT_HOLD(QDT_HandleType *pSentHandle, uint32_t *pPOSDTMRCNTH);

void QDT_GetSpeed(QDT_HandleType *pSentHandle, QDT_SpeedResultType *pSpeed);

void QDT_InterruptProcess(const QDT_HandleType *pSentHandle);

#endif

#endif /* _DRIVER_MODULE_DRIVER_QDT_H_ */
