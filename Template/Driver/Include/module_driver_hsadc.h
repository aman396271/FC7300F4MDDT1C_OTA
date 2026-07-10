/**
 * @file module_driver_hsadc.h
 * @author flagchip
 * @brief HSADC driver type definition and API
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
   *   0.1.0       2023-12-15    Flagchip0126   N/A          First version for FC7300
   *   2.0.0       2024-10-12    Flagchip0126   N/A          Change version and release
   ******************************************************************************** */

#ifndef _DRIVER_MODULE_DRIVER_HSADC_H_
#define _DRIVER_MODULE_DRIVER_HSADC_H_

#include "HwA_hsadc.h"

#if HSADC_INSTANCE_COUNT > 0U

/**
 * @addtogroup module_driver_hsadc
 * @{
 */

#if defined(__cplusplus)
extern "C" {
#endif

/**
 * @name  HSADC API Service IDs
 *
 * @{
 */
#define HSADC_INIT_STRUCTURE_ID             0U
#define HSADC_INIT_SG_STRUCTURE_ID          1U
#define HSADC_INIT_CMP_STRUCTURE_ID         2U
#define HSADC_INIT_FAST_CMP_STRUCTURE_ID    3U
#define HSADC_INIT_ID                       4U
#define HSADC_DEINIT_ID                     5U
#define HSADC_INIT_CHANNEL_ID               6U
#define HSADC_INIT_CMP_ID                   7U
#define HSADC_INIT_FAST_CMP_ID              8U
#define HSADC_INIT_SG_ID                    9U
#define HSADC_ENABLE_ID                     10U
#define HSADC_DISABLE_ID                    11U
#define HSADC_START_ID                      12U
#define HSADC_STOP_ID                       13U
#define HSADC_RESET_ID                      14U
#define HSADC_GET_FAST_CMP_RESULT_ID        15U
#define HSADC_GET_FAST_CMP_BOUNDARY_FLAG_ID 16U

#define HSADC_SC_START_INDEX                2U   /* The start index of regular channel in SC register */

/** @}*/

/**
 * @name  HSADC Dev Error Code
 * @brief Error Code of calling HSADC apis
 *
 * @{
 */
#define HSADC_E_PARAM_INSTANCE            0x01U
#define HSADC_E_PARAM_CHANNEL             0x02U
#define HSADC_E_PARAM_POINTER             0x03U
#define HSADC_E_PARAM_COUNT               0x04U
#define HSADC_E_PARAM_INVALID             0x05U
#define HSADC_E_PARAM_PHASE_SHIFT         0x06U

/** @}*/


/**
 * @name  HSADC0 Internal Channels
 * @brief Available internal HSADC channels for HSADC Instance 0
 *
 * @{
 */
#define HSADC0_CHANNEL_VBG_BUFFER                HSADC_CHANNEL_INTERNAL_0
#define HSADC0_CHANNEL_V25                       HSADC_CHANNEL_INTERNAL_1
/** @}*/

/**
 * @name  HSADC1 Internal channels
 * @brief Available internal HSADC channels for HSADC Instance 1
 *
 * @{
 */
#define HSADC1_CHANNEL_VBG_BUFFER                HSADC_CHANNEL_INTERNAL_0
#define HSADC1_CHANNEL_V25                       HSADC_CHANNEL_INTERNAL_1

/** @}*/

/**
 * @name HSADC2 Internal channels
 * @brief Available internal HSADC channels for HSADC instance 2
 *
 * @{
 */
#define HSADC2_CHANNEL_VBG_BUFFER                HSADC_CHANNEL_INTERNAL_0
#define HSADC2_CHANNEL_V25                       HSADC_CHANNEL_INTERNAL_1

/** @}*/

/**
 * @name HSADC3 Internal channels
 * @brief Available internal HSADC channels for HSADC instance 3
 *
 * @{
 */
#define HSADC3_CHANNEL_VBG_BUFFER                HSADC_CHANNEL_INTERNAL_0
#define HSADC3_CHANNEL_V25                       HSADC_CHANNEL_INTERNAL_1
/** @}*/

/**
 * @brief The instance index of the HSADC peripheral
 *
 */
typedef enum
{
    HSADC_INSTANCE_0 = 0U,  /*!< HSADC instance 0 is selected */
    HSADC_INSTANCE_1 = 1U,  /*!< HSADC instance 1 is selected */
    HSADC_INSTANCE_2 = 2U,  /*!< HSADC instance 2 is selected */
    HSADC_INSTANCE_3 = 3U   /*!< HSADC instance 3 is selected */
} HSADC_InstanceType;

/**
 * @brief The channel selected for HSADC conversion
 *
 */
typedef enum
{
    HSADC_CHANNEL_0                     = 0U,
    HSADC_CHANNEL_1                     = 1U,
    HSADC_CHANNEL_2                     = 2U,
    HSADC_CHANNEL_3                     = 3U,
    HSADC_CHANNEL_4                     = 4U,
    HSADC_CHANNEL_5                     = 5U,
    HSADC_CHANNEL_INTERNAL_0            = 6U,
    HSADC_CHANNEL_INTERNAL_1            = 7U,
    HSADC_CHANNEL_EXTEND_0              = 8U,
    HSADC_CHANNEL_EXTEND_1              = 9U,
    HSADC_CHANNEL_EXTEND_2              = 10U,
    HSADC_CHANNEL_EXTEND_3              = 11U,
    HSADC_CHANNEL_EXTEND_4              = 12U,
    HSADC_CHANNEL_EXTEND_5              = 13U,
    HSADC_CHANNEL_EXTEND_6              = 14U,
    HSADC_CHANNEL_EXTEND_7              = 15U,
    HSADC_CHANNEL_OFFSET_CALIBRATION    = 27U,
    HSADC_CHANNEL_GAIN_LOW_CALIBRATION  = 28U,
    HSADC_CHANNEL_GAIN_HIGH_CALIBRATION = 29U,
} HSADC_ChannelType;

/**
 * @brief The HSADC sample time option for selection
 *
 */
typedef enum
{
    HSADC_SAMPLE_TIME_OPTION_0 = 0U,
    HSADC_SAMPLE_TIME_OPTION_1 = 1U,
    HSADC_SAMPLE_TIME_OPTION_2 = 2U,
    HSADC_SAMPLE_TIME_OPTION_3 = 3U
} HSADC_SampleTimeOptionType;

/**
 * @brief HSADC operation return values
 *
 */
typedef enum
{
    HSADC_STATUS_SUCCESS = 0x0U,  /*!< The HSADC operation is succeed */
    HSADC_STATUS_ERROR   = 0x1U,  /*!< The HSADC operation is failed */
    HSADC_STATUS_TIMEOUT = 0x2U   /*!< The HSADC operation is failed because of time out */
} HSADC_StatusType;

/**
 * @brief The structure of the CMU processing handle
 * Implements : _HSADC_HandleType
 **/
typedef struct _HSADC_HandleType
{
    HSADC_InstanceType eInstance;         /*!< HSADC instance */

    struct
    {
        HSADC_SeqModeType eSeqMode;       /*!< HSADC sequence mode */
        uint8_t u8ChannelCnt;             /*!< Number of channels */

        bool bConvCompleteIntEn;                                          /*!< Enable interrupt when conversion completed */
        bool bOverrunIntEn;                                               /*!< Enable interrupt when overrun occured */
        bool bCmpIntEn;                                                   /*!< Enable interrupt when conversion result lays in the compare threshold */
        bool bSGConvCompleteIntEn;                                        /*!< Enable interrupt when sequence group conversion completed */

        void (*pConvCompleteNotify)(struct _HSADC_HandleType *pHandle);   /*!< Conversion complete interrupt Notify */
        void (*pOverrunNotify)(struct _HSADC_HandleType *pHandle);        /*!< Overrun interrupt Notify */
        void (*pCmpNotify)(struct _HSADC_HandleType *pHandle);            /*!< Compare interrupt Notify */
        void (*pSGConvCompleteNotify[HSADC_SEQ_GROUP_COUNT])(struct _HSADC_HandleType *pHandle);  /*!< Sequence group complete interrupt Notify */

        uint32_t *pResultBuffer;                                          /*!< Result buffer for eSeqMode != HSADC_SEQ_GROUP_MODE */
        uint32_t *pSGResultBuffer[HSADC_SEQ_GROUP_COUNT];                 /*!< Result buffer for eSeqMode == HSADC_SEQ_GROUP_MODE */

        bool bFastCmpFallingIntEn;
        bool bFastCmpRisingIntEn;
        void (*pFastCmpRisingNotify)(struct _HSADC_HandleType *pHandle);  /*!< FastCmp rising interrupt callback */
        void (*pFastCmpFallingNotify)(struct _HSADC_HandleType *pHandle); /*!< FastCmp falling interrupt callback */

    } tSettings;

} HSADC_HandleType;

/**
 * @brief Defines the converter configuration
 *
 * This structure is used to configure the HSADC converter
 *
 * Implements : HSADC_InitType
 */
typedef struct
{
    /* Basic Settings */

    HSADC_AlignType eAlign;                                 /*!< HSADC alignment (left, right) */
    HSADC_TrgModeType eTrgMode;                             /*!< HSADC trigger type */
    uint16_t u16PeriodTrgInterval;                          /*!< The interval of periodic trigger */
    bool bWaitEn;                                           /*!< Whether to enable HSADC wait conversion mode */
    HSADC_TrgLatchUnitPri eTrgLatchUnitPri;                 /*!< Select priority of Trigger Latch Unit */
    HSADC_SeqModeType eSeqMode;                             /*!< HSADC sequence mode */
    bool bAutoDis;                                          /*!< Whether to enable auto disable mode, only set this when adc in off state */
    HSADC_OvrModeType eOverrunMode;                         /*!< Whether to preserve data when HSADC overruns */
    bool bAverageEn;                                        /*!< Whether to enable averaging functionality */
    HSADC_AverageLenType eAverageLen;                       /*!< Number of samples used for averaging */
    uint8_t aSampleTimes[HSADC_SAMPLE_TIME_OPTION_COUNT];   /*!< HSADC sample time options, range: 6 ~ 255
                                                                 Total cycles = aSampleTimes[i] HSADC clock cycles if aSampleTimes[i] < 128, the minimum value is 6
                                                                 Total cycles = (128 + (aSampleTimes[i] - 128)*16) HSADC clock cycles if aSampleTimes[i] >= 128 */

    HSADC_FunctionClockType eFunctionClockSel;              /*!< Function clock selection */
    uint32_t u32ExtClkFreq;                                 /*!< External clock Frequency if FCLK_FROM_PAD */
    HSADC_ClockDivideType eClockDivider;                    /*!< HSADC clock divider */
    bool bCalibrationEn;                                    /*!< Whether to enable calibration compensation */
    bool bExecuteCalibration;                               /*!< Whether to execute calibration at initialization */
    bool bDmaEn;                                            /*!< Enable DMA for the HSADC */

    /* Interrupt Settings */

    bool bConvCompleteIntEn;                                         /*!< Enable interrupt when conversion completed */
    bool bOverrunIntEn;                                              /*!< Enable interrupt when overrun occured */
    void (*pConvCompleteNotify)(struct _HSADC_HandleType *pHandle);  /*!< Conversion complete interrupt Notify */
    void (*pOverrunNotify)(struct _HSADC_HandleType *pHandle);       /*!< Overrun interrupt Notify */

    /* Result buffer */

    uint32_t *pResultBuffer;                                         /*!< Result buffer for eSeqMode != HSADC_SEQ_GROUP_MODE */
} HSADC_InitType;

/**
 * @brief The configuration option for the HSADC channel
 *
 */
typedef struct
{
    HSADC_ChannelType          eChannel;          /*!< Selected HSADC channel */
    HSADC_SampleTimeOptionType eSampleTimeOption; /*!< The sample time selection for the channel */
} HSADC_ChannelCfgType;

/**
 * @brief The configuration option for the HSADC sequence group
 *
 * Implements : HSADC_SeqGroupType
 */
typedef struct
{
    bool    bSG0En;
    uint8_t u8SG0Len;             /*!< Sequence group 0 length, is must be >= 0 */
    HSADC_ChannelCfgType *aSG0Channels;
    bool bSG0ConvCompleteIntEn;   /*!< Enable interrupt when conversion completed */
    uint32_t *pSG0ResultBuffer;
    void (*pSG0ConvCompleteNotify)(struct _HSADC_HandleType *pHandle);

    bool    bSG1En;
    uint8_t u8SG1Len;             /*!< Sequence group 1 length, is must be >= 0 */
    HSADC_ChannelCfgType *aSG1Channels;
    bool bSG1ConvCompleteIntEn;
    uint32_t *pSG1ResultBuffer;
    void (*pSG1ConvCompleteNotify)(struct _HSADC_HandleType *pHandle);

    bool bSGDmaEn;                /*!< Enable sequence group DMA */
    uint8_t u8SGDMAIndex;         /*!< Sequence group DMA selection */
} HSADC_SGType;

/**
 * @brief Defines the hardware compare configuration
 *
 * This structure is used to configure the hardware compare feature for the HSADC
 *
 * Implements : HSADC_CmpType
 */
typedef struct
{
    bool bCmpEn;                                /*!< Enable hardware compare */
    HSADC_CmpChannelType eCmpChannelType;       /*!< 0 = Compare on all channels; 1 = Compare on the selected channel */
    HSADC_ChannelType u8CmpChannelSel;          /*!< Compare channel selection */
    uint16_t u16CmpHighThres;                   /*!< Compare high threshold */
    uint16_t u16CmpLowThres;                    /*!< Compare low threshold */

    bool bCmpIntEn;                                         /*!< Enable interrupt when conversion result lays in the compare threshold */
    void (*pCmpNotify)(struct _HSADC_HandleType *pHandle);  /*!< Compare interrupt Notify */
} HSADC_CmpType;

/**
 * @brief Defines the hardware fast compare configuration
 *
 * This structure is used to configure the hardware fast compare feature for the HSADC
 *
 * Implements : HSADC_FastCompareType
 */
typedef struct
{
    bool bFastCmpEn;                                    /*!< Enable fast compare */

    HSADC_ChannelType          eFastCmpChannel;                /*!< Selected HSADC channel */
    HSADC_SampleTimeOptionType eFastCmpSampleTimeOption;       /*!< The sample time selection for the channel */

    bool bFastCmpPreSetResult;
    bool bFastCmpDigitalModeEn;                         /*!< Enable digital comparator */
    bool bFastCmpSaveConvData;                          /*!< Enable conversion data saving. This option is valid only when fast compare work in digital mode. */

    /* Basic reference settings */

    uint16_t u16FastCmpRefValue;                        /*!< Fast compare reference value */
    uint16_t u16FastCmpUpperDelta;
    uint16_t u16FastCmpLowerDelta;

    /* Reference control settings */

    HSADC_FastCmpRefMode eFastCmpRefMode;               /*!< Fast compare operation mode */
    HSADC_FastCmpRampDir eFastCmpRampDir;
    HSADC_FastCmpRampTrgMode eFastCmpRampTrgMode;
    HSADC_FastCmpRampTrgPolarity eFastCmpRampTrgPol;    /*!< */
    uint8_t u8FastCmpRampStep;
    uint16_t u16FastCmpRampRefA;
    uint16_t u16FastCmpRampRefB;

    /* Boundary flag control settings */

    bool bFastCmpBFLEn;
    HSADC_FCmpBFLAction eFastCmpBFLAct;
    bool bFastCmpBFLInvert;

    bool bFastCmpFallingIntEn;
    bool bFastCmpRisingIntEn;
    void (*pFastCmpRisingNotify)(struct _HSADC_HandleType *pHandle);      /*!< FCmp rising interrupt callback */
    void (*pFastCmpFallingNotify)(struct _HSADC_HandleType *pHandle);     /*!< FCmp falling interrupt callback */
} HSADC_FastCmpType;

/**
 * @brief Provide the default values of HSADC_InitType
 *
 * @param pInitCfg the structure to initialize
 */
void HSADC_InitStructure(HSADC_InitType *const pInitCfg);

/**
 * @brief Provide the default values of HSADC_SeqGroupType
 *
 * @param pSeqGroupCfg the structure to initialize
 */
void HSADC_InitSGStructure(HSADC_SGType *const pSGCfg);

/**
 * @brief Provide the default values of HSADC_CmpType
 *
 * @param pCmpCfg the structure to initialize
 */
void HSADC_InitCmpStructure(HSADC_CmpType *const pCmpCfg);

/**
 * @brief Provide the default values of HSADC_FastCmpType
 *
 * @param pFastCmpCfg the structure to initialize
 */
void HSADC_InitFastCmpStructure(HSADC_FastCmpType *const pFastCmpCfg);

/**
 * @brief Initialize the HSADC instance
 *
 * @param pAdcHandle the HSADC instance to init
 * @param pInitCfg the configurations of the HSADC instance
 */
void HSADC_Init(HSADC_HandleType *pAdcHandle, const HSADC_InitType *const pInitCfg);

/**
 * @brief De-initialize the HSADC instance
 *
 * Restore the HSADC instance to its reset state
 *
 * @param pAdcHandle the HSADC instance to de-init
 */
void HSADC_DeInit(HSADC_HandleType *pAdcHandle);

/**
 * @brief Configure the HSADC sample channels
 *
 * @param pAdcHandle the HSADC instance to use
 * @param aChannels the channels to use
 * @param u8ChannelCnt the quantity of channels
 */
void HSADC_InitChannel(HSADC_HandleType *pAdcHandle, const HSADC_ChannelCfgType aChannels[],
                     const uint8_t u8ChannelCnt);

/**
 * @brief Configure the Sequence groups
 *
 * @param pAdcHandle the HSADC instance to use
 * @param pSGType the sequence group to use
 */
void HSADC_InitSG(HSADC_HandleType *pHsadcHandle, const HSADC_SGType *const pSGType);

/**
 * @brief Configure the hardware compare feature of HSADC
 *
 * @param pAdcHandle the HSADC instance to use
 * @param pCmpCfg the compare paremeters
 */
void HSADC_InitCmp(HSADC_HandleType *pAdcHandle, const HSADC_CmpType *const pCmpCfg);

/**
 * @brief Configure the hardware fast compare feature of HSADC
 *
 * @param pAdcHandle the HSADC instance to use
 * @param pFastCompareCfg the fast compare paremeters
 * 
 * @note Fast compare function can only work in continuous conversion mode or single coversion mode with
 *       periodic trigger and on a fixed channel to do continuous compare on a same channel.
 *       SEQ_LEN bits in CFG1 register must be configured as 0 when using fast compare function.
 */
void HSADC_InitFastCmp(HSADC_HandleType *pAdcHandle, const HSADC_FastCmpType *const pFastCmpCfg);

/**
 * @brief Enable the HSADC instance
 *
 * @param pAdcHandle the HSADC instance to enable
 * @return HSADC_StatusType whether HSADC is enabled successfully
 */
HSADC_StatusType HSADC_Enable(const HSADC_HandleType *pAdcHandle);

/**
 * @brief Disable the HSADC instance
 *
 * @param pAdcHandle the HSADC instance to disable
 * @return HSADC_StatusType whether HSADC is disabled successfully
 */
HSADC_StatusType HSADC_Disable(HSADC_HandleType *pAdcHandle);

/**
 * @brief Start the HSADC conversion
 *
 * If the HSADC sequence mode is single or continuous, and the trigger mode is HSADC_TRIGMODE_SW,
 * the adc conversion will start immediately. Otherwise, the HSADC will wait for the trigger
 * signal to start the conversion
 *
 * @param pAdcHandle the HSADC instance to start
 */
void HSADC_Start(const HSADC_HandleType *pAdcHandle);

/**
 * @brief Stop the HSADC conversion
 *
 * If the HSADC sequence mode is single, it will stop the ongoing conversion. If no ongoing
 * conversion, it will have no effect. If the HSADC sequence mode is continuous or discontinuous,
 * it will stop the ongoing conversion and meanwhile the further conversions.
 *
 * @param pAdcHandle the HSADC instance to stop
 * @return HSADC_StatusType whether HSADC is stopped successfully
 */
HSADC_StatusType HSADC_Stop(const HSADC_HandleType *pAdcHandle);

/**
 * @brief Reset the HSADC hardware
 *
 * @param pAdcHandle the HSADC instance to reset
 */
void HSADC_Reset(const HSADC_HandleType *pAdcHandle);

/**
 * @brief The internal interrupt handler function for HSADC instances
 *
 * @param pAdcHandle the HSADC process handler
 */
void HSADCn_IRQHandler(HSADC_HandleType *pAdcHandle);

/**
 * @brief Get fast compare result
 *
 * @param pAdcHandle the HSADC process handler
 *
 */
bool HSADC_GetFastCmpResult(const HSADC_HandleType *pHsadcHandle);

/**
 * @brief Get fast compare boundary flag
 *
 * @param pAdcHandle the HSADC process handler
 *
 */
bool HSADC_GetFastCmpBoundaryFlag(const HSADC_HandleType *pHsadcHandle);

/** @}*/

#if defined(__cplusplus)
}
#endif

/** @}*/ /* module_driver_adc */

#endif /* #if HSADC_INSTANCE_COUNT > 0U */

#endif
