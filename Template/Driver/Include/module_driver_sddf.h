/**
 * @file module_driver_sddf.h
 * @author Flagchip
 * @brief Sigma Delta Digital Filter (SDDF) driver type definition and API
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
   *   0.1.0       2023-12-15    Flagchip030   N/A          First version for FC7300
   *   2.0.0       2024-10-12    Flagchip030   N/A          Change version and release
   ******************************************************************************** */

#ifndef _DRIVER_MODULE_DRIVER_SDDF_H_
#define _DRIVER_MODULE_DRIVER_SDDF_H_

#include "HwA_sddf.h"

#if SDDF_INSTANCE_COUNT > 0U

#include "module_driver_dma.h"

#if defined(__cplusplus)
extern "C" {
#endif
/**
 * @addtogroup module_driver_sddf
 * @{
 */

/**
 * @name  SDDF Dev Error Code
 * @brief Error Code of calling SDDF apis
 *
 * @{
 */
#define SDDF_E_PARAM_INSTANCE            0x01U
#define SDDF_E_PARAM_CHANNEL             0x02U
#define SDDF_E_PARAM_POINTER             0x03U
#define SDDF_E_PARAM_MAIN_FILTER         0x04U
#define SDDF_E_PARAM_AUX_FILTER          0x05U
/** @} */

/**
 * @name  SDDF API Service IDs
 *
 * @{
 */
#define SDDF_INIT_ID                             0x00U
#define SDDF_DEINIT_ID                           0x01U
#define SDDF_CFG_CLK_OUT_ID                      0x02U
#define SDDF_ENABLE_ID                           0x03U
#define SDDF_DISABLE_ID                          0x04U
#define SDDF_EN_DBG_MODE_ID                      0x05U
#define SDDF_DIS_DBG_MODE_ID                     0x06U
#define SDDF_INIT_CH_ID                          0x07U
#define SDDF_CH_ENABLE_ID                        0x08U
#define SDDF_CH_DISABLE_ID                       0x09U
#define SDDF_CFG_CH_INT_ID                       0x0AU
#define SDDF_CFG_CH_DMA_ID                       0x0BU
#define SDDF_CFG_CH_CLK_ABS_DET_ID               0x0CU
#define SDDF_CFG_CH_SHORT_CIR_DET_ID             0x0DU
#define SDDF_CFG_CH_LIM_CHK_ID                   0x0EU
#define SDDF_CFG_CH_ZERO_CROSS_DET_ID            0x0FU
#define SDDF_GEN_CH_SW_TRIG_ID                   0x10U
#define SDDF_GET_CH_FIFO_DATA_ID                 0x11U
/** @} */

/**
 * @brief The instance index of the SDDF peripheral
 *
 */
typedef enum
{
    SDDF_INSTANCE_0 = 0U /*!< SDDF instance 0 is selected */
} SDDF_InstanceType;

/**
 * @brief The event detected by SDDF detectors
 *
 */
typedef enum
{
    SDDF_CLOCK_ABSENCE_EVENT = 0U, /**< Clock absence event is detected */
    SDDF_SHORT_CIRCUIT_EVENT = 1U, /**< Short circuit event is detected */
    SDDF_LOW_LIMIT_EVENT     = 2U, /**< The result exceeds low limit */
    SDDF_HIGH_LIMIT_EVENT    = 3U, /**< The result exceeds high limit */
    SDDF_WINDOW_LIMIT_EVENT  = 4U, /**< The result is out of the limit window */
    SDDF_ZERO_CROSS_EVENT    = 5U  /**< Zero cross event is detected */
} SDDF_DetectEventType;

/**
 * @brief Select the clock output source
 *
 */
typedef enum
{
    SDDF_CLOCK_OUT_DISABLED = 0U, /**< The clock output is disabled */
    SDDF_CLOCK_OUT_0        = 1U, /**< The clock output channel uses CLOCK_OUT_0 */
    SDDF_CLOCK_OUT_1        = 2U, /**< The clock output channel uses CLOCK_OUT_1 */
    SDDF_CLOCK_OUT_2        = 3U  /**< The clock output channel uses CLOCK_OUT_2 */
} SDDF_ClockOutType;

/**
 * @brief Select the clock channel for SDDF external clock input
 *
 */
typedef enum
{
    SDDF_CLOCK_INPUT_CLK0 = 0U, /**< Clock channel 0 is used as clock input */
    SDDF_CLOCK_INPUT_CLK1 = 1U, /**< Clock channel 1 is used as clock input */
    SDDF_CLOCK_INPUT_CLK2 = 2U, /**< Clock channel 2 is used as clock input */
    SDDF_CLOCK_INPUT_CLK3 = 3U  /**< Clock channel 3 is used as clock input */
} SDDF_ClcokInputType;

/**
 * @brief The general callback function prototype for SDDF interrupt
 *
 */
typedef void (*SDDF_GeneralCallbackType)(void);

/**
 * @brief Function prototype for SDDF FIFO ready interrupt
 *
 */
typedef void (*SDDF_FIFOReadyCallbackType)(const uint32_t *const pData);

/**
 * @brief Function prototype for SDDF event detect interrupt
 *
 */
typedef void (*SDDF_EventDetectCallbackType)(const SDDF_DetectEventType eEvent);

typedef struct
{
    SDDF_GeneralCallbackType pConvCompleteNotify;
    SDDF_FIFOReadyCallbackType pFIFOReadyNotify;
    SDDF_GeneralCallbackType pDataSaturationNotify;
    SDDF_GeneralCallbackType pUnderflowNotify;
    SDDF_GeneralCallbackType pOverflowNotify;
    SDDF_FIFOReadyCallbackType pDMAReadyNotify;
    SDDF_EventDetectCallbackType pClockAbsenceDetectNotify;
    SDDF_EventDetectCallbackType pShortCircuitDetectNotify;
    SDDF_EventDetectCallbackType pLimitCheckNotify;
    SDDF_EventDetectCallbackType pZeroCrossDetectNotify;
} SDDF_ChannelNotificationType;

typedef struct _SDDF_HandleType
{
    SDDF_InstanceType eInstance;
    uint8_t reserve0[3];
    struct
    {
        SDDF_ChannelNotificationType Notifications[SDDF_CH_CNT];
    } tSettings;

} SDDF_HandleType;

/**
 * @brief The init configuration for SDDF instance
 *
 */
typedef struct
{
    SDDF_PreDivType ePreDiv; /**< The pre-divider ratio for SDDF function clock */
    uint16_t u16Div;         /**< The clock divider for SDDF clock out */
} SDDF_InitConfigType;

/**
 * @brief The clock out configuration for SDDF
 *
 */
typedef struct
{
    bool bClockOut0Enable;      /**< Whether to enable clock out 0 */
    bool bClockOut1Enable;      /**< Whether to enable clock out 1 */
    bool bClockOut2Enable;      /**< Whether to enable clock out 2 */
    SDDF_ClockOutType eClk0Src; /**< The clock source for clock channel 0 */
    SDDF_ClockOutType eClk1Src; /**< The clock source for clock channel 1 */
    SDDF_ClockOutType eClk2Src; /**< The clock source for clock channel 2 */
    SDDF_ClockOutType eClk3Src; /**< The clock source for clock channel 3 */
} SDDF_ClockOutConfigType;

/**
 * @brief The configuration for main filter
 *
 */
typedef struct
{
    SDDF_MainFilterOrderType eFilterOrder; /**< The filter order of the main filter, the recommended filter order
                                                is often 1 order higher than the order of the delta-sigma ADC */
    uint16_t u16OverSamplingRate;          /**< The oversampling rate of main filter, lower range: 3,
                                                higher range depends on the filter order to keep the filter
                                                result not exceed 32bit.
                                                If filter order is 5th, higher range is 72;
                                                If filter order is 4th, higher range is 203;
                                                Otherwise higher range is 511 */
    SDDF_MainFilterConvModeType eConvMode; /**< The conversion mode of the main filter */
    SDDF_MainFilterShiftType eShift;       /**< Main filter shift to get correct 24 bit precision
                                                the effective width of main filter raw data is
                                                W_MCIC = ceiling[log2(OversamplingRate + 1)^FilterOrder]+1-ResultFormat
                                                And thus: Shift = 24 - W_MCIC, positive means shift left, negetive means
                                                shift right */
    int32_t s32Bias;                       /**< Bias offset for dedicated channel main filter; used for sign adjustment
                                                and compensation. The main filter data after shift, will substract this
                                                bias value*/
} SDDF_MainFilterConfigType;

/**
 * @brief The configuration for auxiliary filter
 *
 */
typedef struct
{
    SDDF_AuxFilterOrderType eFilterOrder; /**< The filter order of the auxiliary filter */
    uint16_t u16OverSamplingRate;         /**< The oversampling rate of auxiliary filter */
    SDDF_AuxFilterConvModeType eConvMode; /**< The conversion mode of the auxiliary filter */
} SDDF_AuxFilterConfigType;

/**
 * @brief The configuration of the SDDF channel
 *
 */
typedef struct
{
    SDDF_TriggerEventType eTriggerEvent;                    /**< The trigger event type of the channel */
    SDDF_TriggerSrcType eTriggerSrc;                        /**< The trigger source of the channel */
    SDDF_ClockEdgeType eInputClockEdge;                     /**< The input clock edge used by the channel */
    SDDF_ClcokInputType eInputClockSrc;                     /**< The input clock source used by the channel */
    SDDF_BitFormatType eBitFormat;                          /**< The bit format of the channel */
    SDDF_ResultFormatType eResultFormat;                    /**< The result format (signed or unsigned) of the channel */
    bool bFIFOEnable;                                       /**< Whether to enable result FIFO */
    uint8_t u8FIFOWatermark;                                /**< The result FIFO watermark */
    bool bMainFilterEnable;                                 /**< Whether to enable main filter of the channel */
    const SDDF_MainFilterConfigType *pMainFilterConfig;     /**< The pointer of the main filter configuration */
    bool bAuxiliaryFilterEnable;                            /**< Whether to enable auxiliary filter of the channel */
    const SDDF_AuxFilterConfigType *pAuxiliaryFilterConfig; /**< The pointer of the auxiliary filter configuraion */
} SDDF_ChannelConfigType;

/**
 * @brief The configuration of the clock absence detect
 *
 */
typedef struct
{
    bool bClockAbsenceDetectEnable;                         /**< Whether to enable clock absence detect */
    uint8_t u8ClockAbsenceDetectThreshold;                  /**< The clock absence detector limitation threshold */
    bool bClockAbsenceDetectIntEnable;                      /**< Whether to enable clock absence detect interrupt */
    SDDF_EventDetectCallbackType pClockAbsenceDetectNotify; /**< The callback function for clock absence detect interrupt */
    bool bClockAbsenceDetectBreakEnable;                    /**< Whether to enable clock absence detect break signal */
} SDDF_ClockAbsenceDetectConfigType;

/**
 * @brief The configuration of the short circuit detect
 *
 */
typedef struct
{
    bool bShortCircuitDetectEnable;                          /**< Whether to enable short circuit detect */
    SDDF_ShortCircuitOptionType eShortCircuitDetectOption;   /**< Short circuit detect counting option */
    SDDF_ShortCircuitDetectModeType eShortCircuitDetectMode; /**< Short circuit detect converion mode */
    uint8_t u8ShortCircuitDetectThreshold;                   /**< Short circuit detect counter threshold */
    bool bShortCircuitDetectIntEnable;                       /**< Whether to enable short circuit detect interrupt */
    SDDF_EventDetectCallbackType
    pShortCircuitDetectNotify;  /**< The callback function for short circuit detect interrupt */
    bool bShortCircuitDetectBreakEnable;                     /**< Whether to enable short circuit detect break signal */
} SDDF_ShortCircuitDetectConfigType;

/**
 * @brief The configuration of the limit detect
 *
 */
typedef struct
{
    bool bLimitCheckEnable;                         /**< Whether to enable limit detect */
    SDDF_ChannelLimitOptionType eLimitCheckOption;  /**< Limit detect option */
    SDDF_InputSrcType eLimitCheckInputSrc;          /**< The result source of limit detect */
    uint32_t u32LowLimit;                           /**< The lower threshold of limit detect */
    uint32_t u32HighLimit;                          /**< The higher threshold of limit detect */
    bool bLowLimitIntEnable;                        /**< Whether to enable low limit detect interrupt */
    bool bHighLimitIntEnable;                       /**< Whether to enable high limit detect interrupt */
    bool bWindowLimitIntEnable;                     /**< Whether to enable window limit detect interrupt */
    SDDF_EventDetectCallbackType pLimitCheckNotify; /**< The callback function for limit detect interupt */
    bool bLowLimitBreakEnable;                      /**< Whether to enable low limit detect break signal */
    bool bHighLimitBreakEnable;                     /**< Whether to enable high limit detect break signal */
    bool bWindowLimitBreakEnable;                   /**< Whether to enable window limit detect break signal */
} SDDF_LimitCheckConfigType;

/**
 * @brief The configuration of the zero cross detect
 *
 */
typedef struct
{
    bool bZeroCrossDetectEnable;                         /**< Whether to enable zero cross detect */
    SDDF_InputSrcType eZeroCrossDetectInputSrc;          /**< The result source of zero cross detect */
    bool bZeroCrossDetectIntEnable;                      /**< Whether to enable zero cross detect interrupt */
    SDDF_EventDetectCallbackType pZeroCrossDetectNotify; /**< The callback function for zero cross detect interrupt */
} SDDF_ZeroCrossDetectConfigType;

/**
 * @brief The result related interrupt configuraion of the SDDF channel
 *
 */
typedef struct
{
    bool bConversionCompleteIntEnable;               /**< Whether to enable conversion complete interrupt */
    SDDF_GeneralCallbackType pConvCompleteNotify;    /**< The callback function of conversion complete interrupt */
    bool bFIFOReadyIntEnable;                        /**< Whether to enable FIFO ready interrupt */
    uint32_t *pResultBuffer;                         /**< When FIFO ready interrupt is enabled, you shall provide the
                                                          result buffer to store the conversion results */
    SDDF_FIFOReadyCallbackType pFIFOReadyNotify;     /**< The callback function of FIFO ready interrupt */
    bool bDataSaturationIntEnable;                   /**< Whether to enable interrupt for result data saturation*/
    SDDF_GeneralCallbackType pDataSaturationNotify;  /**< The callback function of result data saturation interrupt */
    bool bUnderflowIntEnable;                        /**< Whether to enable interrupt for FIFO underflow */
    SDDF_GeneralCallbackType pUnderflowNotify;       /**< The callback function of FIFO underflow interrupt */
    bool bOverflowIntEnable;                         /**< Whether to enable interrupt for FIFO overflow */
    SDDF_GeneralCallbackType pOverflowNotify;        /**< The callback function of FIFO overflow interrupt */
} SDDF_ChannelInterruptConfigType;

/**
 * @brief The DMA configuration of the SDDF channel
 *
 */
typedef struct
{
    bool bDMAEnable;                            /**< Whether to enable DMA for the SDDF channel */
    DMA_HandleType *pDmahandle;              /**< The DMA instance used to transfer the SDDF conversion results */
    DMA_ChannelType eDmaChannel;                /**< The DMA channel used to transfer the SDDF conversion results */
    uint8_t u8ChannelPriority;                  /**< The DMA channel priority, higher value means higher priority.
                                                     The priority for different channels must be unique. Default priority
                                                     value is same the channel number */
    uint32_t *pResultBuffer;                    /**< When channel DMA is enabled, you shall provide the result buffer to
                                                     store the conversion results */
    SDDF_FIFOReadyCallbackType pDMAReadyNotify; /**< The callback function when DMA transfer completed */
} SDDF_ChannelDMAConfigType;

/**
 * @brief De-initialize the SDDF instance
 *
 * @param eInstance the SDDF instance to de-initialize
 */
void SDDF_DeInit(SDDF_HandleType *pHandle);

/**
 * @brief Initialize the SDDF instance
 *
 * @param eInstance the SDDF instance to initialize
 * @param pInitCfg the configuration of the SDDF instance
 */
void SDDF_Init(SDDF_HandleType *pHandle, const SDDF_InitConfigType *pInitCfg);

/**
 * @brief Configure the SDDF clock out
 *
 * @param eInstance the SDDF instance to configure
 * @param pClockOutCfg the configuration of the SDDF clock out
 */
void SDDF_ConfigClockOut(SDDF_HandleType *pHandle, const SDDF_ClockOutConfigType *pClockOutCfg);

/**
 * @brief Enable the SDDF instance
 *
 * @param eInstance the SDDF instance to enable
 */
void SDDF_Enable(SDDF_HandleType *pHandle);

/**
 * @brief Disable the SDDF instance
 *
 * @param eInstance the SDDF instance to disable
 */
void SDDF_Disable(SDDF_HandleType *pHandle);

/**
 * @brief Enable the debug mode of the SDDF instance
 *
 * @note This function shall be called after the SDDF instance is enabled
 *
 * @param eInstance the SDDF instance to enable debug mode
 * @param eModuleEnable whether the SDDF instance is enabled during debug mode
 */
void SDDF_EnableDebugMode(SDDF_HandleType *pHandle, SDDF_DebugModuleEnableType eModuleEnable);

/**
 * @brief Disable the debug mode of the SDDF instance
 *
 * @note This function shall be called after the SDDF instance is enabled
 *
 * @param eInstance the SDDF instance to disable debug mode
 */
void SDDF_DisableDebugMode(SDDF_HandleType *pHandle);

/**
 * @brief Initialize the selected SDDF channel
 *
 * @param eInstance the SDDF instance to use
 * @param u8Channel the SDDF channel to configure
 * @param pChannelCfg the configuration of the SDDF channel
 */
void SDDF_InitChannel(SDDF_HandleType *pHandle, uint8_t u8Channel, const SDDF_ChannelConfigType *pChannelCfg);

/**
 * @brief Enable the conversion of the selected SDDF channel
 *
 * @param eInstance the SDDF instance to use
 * @param u8Channel the SDDF channel to enable
 */
void SDDF_ChannelEnable(SDDF_HandleType *pHandle, uint8_t u8Channel);

/**
 * @brief Disable the conversion of the selected SDDF channel
 *
 * @param eInstance the SDDF instance to use
 * @param u8Channel the SDDF channel to disable
 */
void SDDF_ChannelDisable(SDDF_HandleType *pHandle, uint8_t u8Channel);

/**
 * @brief Configure the interrupt for the selected SDDF channel
 *
 * @param eInstance the SDDF instance to use
 * @param u8Channel the SDDF channel to configure
 * @param pIntCfg the interrupt configuration
 */
void SDDF_ConfigChannelInterrupt(SDDF_HandleType *pHandle, uint8_t u8Channel,
                                 const SDDF_ChannelInterruptConfigType *pIntCfg);

/**
 * @brief Configure the DMA for the selected the SDDF channel
 *
 * @param eInstance the SDDF instance to use
 * @param u8Channel the SDDF channel to configure
 * @param pDMACfg the DMA configuration
 */
void SDDF_ConfigChannelDMA(SDDF_HandleType *pHandle, uint8_t u8Channel, const SDDF_ChannelDMAConfigType *pDMACfg, DMA_TransferCompleteCallbackType pDmaCallback);

/**
 * @brief Configure the clock absence detect (CAD) for the selected SDDF channel
 *
 * @param eInstance the SDDF instance to use
 * @param u8Channel the SDDF channel to configure
 * @param pConfig the clock absence detect configuration
 */
void SDDF_ConfigChannelClockAbsenceDetect(SDDF_HandleType *pHandle, uint8_t u8Channel,
                                          SDDF_ClockAbsenceDetectConfigType *pConfig);

/**
 * @brief Configure the short circuit detect (SCD) for the selected SDDF channel
 *
 * @param eInstance the SDDF instance to use
 * @param u8Channel the SDDF channel to configure
 * @param pConfig the short circuit detect configuration
 */
void SDDF_ConfigChannelShortCircuitDetect(SDDF_HandleType *pHandle, uint8_t u8Channel,
                                          SDDF_ShortCircuitDetectConfigType *pConfig);

/**
 * @brief Configure the limit check for the selected SDDF channel
 *
 * @param eInstance the SDDF instance to use
 * @param u8Channel the SDDF channel to configure
 * @param pConfig the limit check configuration
 */
void SDDF_ConfigChannelLimitCheck(SDDF_HandleType *pHandle, uint8_t u8Channel, SDDF_LimitCheckConfigType *pConfig);

/**
 * @brief Configure the zero cross detect (ZCD) for the selected SDDF channel
 *
 * @param eInstance the SDDF instance to use
 * @param u8Channel the SDDF channel to configure
 * @param pConfig the zero cross detect configuration
 */
void SDDF_ConfigChannelZeroCrossDetect(SDDF_HandleType *pHandle, uint8_t u8Channel,
                                       SDDF_ZeroCrossDetectConfigType *pConfig);

/**
 * @brief Generate software trigger for the selected SDDF channel
 *
 * @param eInstance the SDDF instance to use
 * @param u8Channel the SDDF channel to generate software trigger
 */
void SDDF_GenerateChannelSwTrigger(SDDF_HandleType *pHandle, uint8_t u8Channel);

/**
 * @brief Get the channel data for the SDDF channel
 *
 * @param eInstance the SDDF instance to use
 * @param u8Channel the SDDF channel to get result
 * @return uint32_t the conversion result of the SDDF channel
 */
uint32_t SDDF_GetChannelFIFOData(SDDF_HandleType *pHandle, uint8_t u8Channel);

void SDDFn_IRQHandler(SDDF_HandleType *pHandle);

void SDDFn_CHnDMAHandler(SDDF_HandleType *pHandle, uint8_t u8Channel);

/** @}*/ /* module_driver_sddf */
#if defined(__cplusplus)
}
#endif

#endif /* #if SDDF_INSTANCE_COUNT > 0U */

#endif /* _DRIVER_MODULE_DRIVER_SDDF_H_ */
