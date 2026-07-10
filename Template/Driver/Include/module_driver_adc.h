/**
 * @file module_driver_adc.h
 * @author flagchip
 * @brief ADC driver type definition and API
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

#ifndef _DRIVER_MODULE_DRIVER_ADC_H_
#define _DRIVER_MODULE_DRIVER_ADC_H_

#include "HwA_adc.h"
#include "HwA_smc.h"

#if ADC_INSTANCE_COUNT > 0U


/**
 * @addtogroup module_driver_adc
 * @{
 */

#if defined(__cplusplus)
extern "C" {
#endif

/**
 * @name  ADC API Service IDs
 *
 * @{
 */
#define ADC_INIT_STRUCTURE_ID           0U
#define ADC_INIT_ID                     1U
#define ADC_DEINIT_ID                   2U
#define ADC_INIT_CHANNEL_ID             3U
#define ADC_INIT_CMP_STRUCTURE_ID       4U
#define ADC_INIT_CMP_ID                 5U
#define ADC_INIT_SG_STRUCTURE_ID        6U
#define ADC_INIT_SG_ID                  7U
#define ADC_ENABLE_ID                   8U
#define ADC_DISABLE_ID                  9U
#define ADC_START_ID                    10U
#define ADC_STOP_ID                     11U
#define ADC_RESET_ID                    12U
#define ADC_SG_CMP_STRUCTURE_ID         13U
#define ADC_SG_CMP_ID                   14U
#define ADC_INIT_ECMP_STRUCTURE_ID      15U
#define ADC_INIT_ECMP_ID                16U
#define ADC_INIT_FCMP_STRUCTURE_ID      17U
#define ADC_INIT_FCMP_ID                18U

/** @}*/

/**
 * @name  ADC Dev Error Code
 * @brief Error Code of calling ADC apis
 *
 * @{
 */
#define ADC_E_PARAM_INSTANCE            0x01U
#define ADC_E_PARAM_CHANNEL             0x02U
#define ADC_E_PARAM_POINTER             0x03U
#define ADC_E_PARAM_COUNT               0x04U
#define ADC_E_PARAM_INVALID             0x05U
#define ADC_E_PARAM_PHASE_SHIFT         0x06U
/** @}*/

/**
 * @brief The instance index of the ADC peripheral
 *
 */
typedef enum
{
    ADC_INSTANCE_0 = 0U,   /*!< ADC instance 0 is selected */
    ADC_INSTANCE_1 = 1U,   /*!< ADC instance 1 is selected */
    #if ADC_INSTANCE_COUNT > 2
    ADC_INSTANCE_2 = 2U,   /*!< ADC instance 2 is selected */
    #endif
    #if ADC_INSTANCE_COUNT > 3
    ADC_INSTANCE_3 = 3U,   /*!< ADC instance 3 is selected */
    #endif
    #if ADC_INSTANCE_COUNT > 4
    ADC_INSTANCE_4 = 4U,   /*!< ADC instance 4 is selected */
    #endif
    #if ADC_INSTANCE_COUNT > 5
    ADC_INSTANCE_5 = 5U    /*!< ADC instance 5 is selected */
    #endif
} ADC_InstanceType;

typedef enum
{
    ADC_SGCMP_S0_REF_TR_HT  = 0x00000001,
    ADC_SGCMP_S1_REF_TR_HT  = 0x00000002,
    ADC_SGCMP_S2_REF_TR_HT  = 0x00000004,
    ADC_SGCMP_S3_REF_TR_HT  = 0x00000008,
    ADC_SGCMP_S4_REF_TR_HT  = 0x00000010,
    ADC_SGCMP_S5_REF_TR_HT  = 0x00000020,
    ADC_SGCMP_S6_REF_TR_HT  = 0x00000040,
    ADC_SGCMP_S7_REF_TR_HT  = 0x00000080,
    ADC_SGCMP_S8_REF_TR_HT  = 0x00000100,
    ADC_SGCMP_S9_REF_TR_HT  = 0x00000200,
    ADC_SGCMP_S10_REF_TR_HT = 0x00000400,
    ADC_SGCMP_S11_REF_TR_HT = 0x00000800,
    ADC_SGCMP_S12_REF_TR_HT = 0x00001000,
    ADC_SGCMP_S13_REF_TR_HT = 0x00002000,
    ADC_SGCMP_S14_REF_TR_HT = 0x00004000,
    ADC_SGCMP_S15_REF_TR_HT = 0x00008000,
    ADC_SGCMP_S16_REF_TR_HT = 0x00010000,
    ADC_SGCMP_S17_REF_TR_HT = 0x00020000,
    ADC_SGCMP_S18_REF_TR_HT = 0x00040000,
    ADC_SGCMP_S19_REF_TR_HT = 0x00080000,
    ADC_SGCMP_S20_REF_TR_HT = 0x00100000,
    ADC_SGCMP_S21_REF_TR_HT = 0x00200000,
    ADC_SGCMP_S22_REF_TR_HT = 0x00400000,
    ADC_SGCMP_S23_REF_TR_HT = 0x00800000,
} ADC_SGCMPREFType;

typedef enum
{
    ADC_SGCMP_S0_ACT_LESS_OR_EQUAL  = 0x00000001,
    ADC_SGCMP_S1_ACT_LESS_OR_EQUAL  = 0x00000002,
    ADC_SGCMP_S2_ACT_LESS_OR_EQUAL  = 0x00000004,
    ADC_SGCMP_S3_ACT_LESS_OR_EQUAL  = 0x00000008,
    ADC_SGCMP_S4_ACT_LESS_OR_EQUAL  = 0x00000010,
    ADC_SGCMP_S5_ACT_LESS_OR_EQUAL  = 0x00000020,
    ADC_SGCMP_S6_ACT_LESS_OR_EQUAL  = 0x00000040,
    ADC_SGCMP_S7_ACT_LESS_OR_EQUAL  = 0x00000080,
    ADC_SGCMP_S8_ACT_LESS_OR_EQUAL  = 0x00000100,
    ADC_SGCMP_S9_ACT_LESS_OR_EQUAL  = 0x00000200,
    ADC_SGCMP_S10_ACT_LESS_OR_EQUAL = 0x00000400,
    ADC_SGCMP_S11_ACT_LESS_OR_EQUAL = 0x00000800,
    ADC_SGCMP_S12_ACT_LESS_OR_EQUAL = 0x00001000,
    ADC_SGCMP_S13_ACT_LESS_OR_EQUAL = 0x00002000,
    ADC_SGCMP_S14_ACT_LESS_OR_EQUAL = 0x00004000,
    ADC_SGCMP_S15_ACT_LESS_OR_EQUAL = 0x00008000,
    ADC_SGCMP_S16_ACT_LESS_OR_EQUAL = 0x00010000,
    ADC_SGCMP_S17_ACT_LESS_OR_EQUAL = 0x00020000,
    ADC_SGCMP_S18_ACT_LESS_OR_EQUAL = 0x00040000,
    ADC_SGCMP_S19_ACT_LESS_OR_EQUAL = 0x00080000,
    ADC_SGCMP_S20_ACT_LESS_OR_EQUAL = 0x00100000,
    ADC_SGCMP_S21_ACT_LESS_OR_EQUAL = 0x00200000,
    ADC_SGCMP_S22_ACT_LESS_OR_EQUAL = 0x00400000,
    ADC_SGCMP_S23_ACT_LESS_OR_EQUAL = 0x00800000,
} ADC_SGCMPACTType;

/**
 * @brief The channel selected for ADC conversion
 *
 */
typedef enum
{
    ADC_CHANNEL_0          = 0U,
    ADC_CHANNEL_1          = 1U,
    ADC_CHANNEL_2          = 2U,
    ADC_CHANNEL_3          = 3U,
    ADC_CHANNEL_4          = 4U,
    ADC_CHANNEL_5          = 5U,
    ADC_CHANNEL_6          = 6U,
    ADC_CHANNEL_7          = 7U,
    ADC_CHANNEL_8          = 8U,
    ADC_CHANNEL_9          = 9U,
    ADC_CHANNEL_10         = 10U,
    ADC_CHANNEL_11         = 11U,
    ADC_CHANNEL_12         = 12U,
    ADC_CHANNEL_13         = 13U,
    ADC_CHANNEL_14         = 14U,
    ADC_CHANNEL_15         = 15U,
    ADC_CHANNEL_16         = 16U,
    ADC_CHANNEL_17         = 17U,
    ADC_CHANNEL_18         = 18U,
    ADC_CHANNEL_19         = 19U,
    ADC_CHANNEL_20         = 20U,
    ADC_CHANNEL_21         = 21U,
    ADC_CHANNEL_22         = 22U,
    ADC_CHANNEL_23         = 23U,
    ADC_CHANNEL_24         = 24U,
    ADC_CHANNEL_25         = 25U,
    ADC_CHANNEL_26         = 26U,
    ADC_CHANNEL_27         = 27U,
    ADC_CHANNEL_28         = 28U,
    ADC_CHANNEL_29         = 29U,
    ADC_CHANNEL_30         = 30U,
    ADC_CHANNEL_31         = 31U,
    ADC_CHANNEL_INTERNAL_0 = 32U,
    ADC_CHANNEL_INTERNAL_1 = 33U,
    ADC_CHANNEL_INTERNAL_2 = 34U,
    ADC_CHANNEL_INTERNAL_3 = 35U,
    ADC_CHANNEL_INTERNAL_4 = 36U,
    ADC_CHANNEL_INTERNAL_5 = 37U
} ADC_ChannelType;

/**
 * @brief The channel selected for ADC conversion in differential mode
 *
 */
typedef enum
{
    ADC_CHANNEL_0_4        = 0U,
    ADC_CHANNEL_1_5        = 1U,
    ADC_CHANNEL_2_6        = 2U,
    ADC_CHANNEL_3_7        = 3U,
    ADC_CHANNEL_TEMPSENSOR = 37U
} ADC_DifferentialChannelType;

/**
 * @brief The ADC sample time option for selection
 *
 */
typedef enum
{
    ADC_SAMPLE_TIME_OPTION_0 = 0U,
    ADC_SAMPLE_TIME_OPTION_1 = 1U,
    ADC_SAMPLE_TIME_OPTION_2 = 2U,
    ADC_SAMPLE_TIME_OPTION_3 = 3U
} ADC_SampleTimeOptionType;

#if ADC_SUPPORT_SG_MODE
/**
 * @brief The ADC Sequence Group Index
 *
 */
typedef enum
{
    ADC_SG0 = 0U,
    ADC_SG1 = 1U,
    ADC_SG2 = 2U,
    ADC_SG3 = 3U
} ADC_SGIndex;
#endif

/**
 * @brief ADC operation return values
 *
 */
typedef enum
{
    ADC_STATUS_SUCCESS = 0x0U,  /*!< The ADC operation is succeed */
    ADC_STATUS_ERROR   = 0x1U,  /*!< The ADC operation is failed */
    ADC_STATUS_TIMEOUT = 0x2U   /*!< The ADC operation is failed because of time out */
} ADC_StatusType;

/**
 * @brief The structure of the ADC processing handle
 *
 **/
typedef struct _ADC_HandleType
{
    ADC_InstanceType eInstance;               /*!< ADC instance */

    struct
    {
        uint8_t u8ChannelCnt;                 /*!< number of channels */
        ADC_SeqModeType eSeqMode;             /*!< ADC sequence mode (single, continuous, discontinuous) */

        bool bConvCompleteIntEn;              /*!< Enable interrupt when conversion completed */

        void (*pConvCompleteNotify)(struct _ADC_HandleType *pHandle); /*!< Conversion complete interrupt callback */
        void (*pOverrunNotify)(struct _ADC_HandleType *pHandle);      /*!< Overrun interrupt callback */
        void (*pCmpNotify)(struct _ADC_HandleType *pHandle);          /*!< Cmp interrupt callback */
        #if ADC_SUPPORT_SG_MODE
        void (*SGConvCompleteNotify[ADC_MAX_SEQUENCE_GROUP_CNT])(struct _ADC_HandleType *pHandle);
        #endif
        #if ADC_SUPPORT_SG_CMP_BLOCK
        void (*pSGCmpNotify)(struct _ADC_HandleType *pHandle);        /*!< SGCMP interrupt callback */
        #endif
        #if ADC_SUPPORT_ENHANCED_CMP_BLOCK
        void (*pECmpHighNotify[ADC_ENHANCED_CMP_BLOCK_CNT])(struct _ADC_HandleType *pHandle);
        void (*pECmpLowNotify[ADC_ENHANCED_CMP_BLOCK_CNT])(struct _ADC_HandleType *pHandle);
        void (*pECmpWinNotify[ADC_ENHANCED_CMP_BLOCK_CNT])(struct _ADC_HandleType *pHandle);
        #endif

        uint32_t *pResultBuffer;                                      /*!< only used for mode 0~3 */
        #if ADC_SUPPORT_SG_MODE
        uint32_t *pSGResultBuffer[ADC_MAX_SEQUENCE_GROUP_CNT];            /*!< only used for mode 4 */
        #endif

        #if ADC_SUPPORT_FAST_CMP_BLOCK
        void (*pFCmpRisingNotify)(struct _ADC_HandleType *pHandle);      /*!< FCmp rising interrupt callback */
        void (*pFCmpFallingNotify)(struct _ADC_HandleType *pHandle);     /*!< FCmp falling interrupt callback */
        #endif
    } tSettings;
} ADC_HandleType;

/**
 * @brief Defines the converter configuration
 *
 * This structure is used to configure the ADC converter
 *
 * Implements : ADC_InitType
 */
typedef struct
{
    ADC_ResolutionType eResolution;      /*!< ADC eResolution (8,10,12 bit) */
    ADC_AlignType eAlign;                /*!< ADC alignment (left, right) */
    ADC_TrgModeType eTrgMode;            /*!< ADC trigger type (software, hardware) */
    #if ADC_SUPPORT_PERIOD_TRIGGER
    uint16_t u16PeriodTrgInterval;       /*!< The interval of periodic trigger */
    #endif
    bool bWaitEn;                        /*!< Whether to enable ADC wait conversion mode */
    #if ADC_SUPPORT_SG_MODE
    ADC_TrgLatchUnitPri eTrgLatchUnitPri;/*!< Select priority of Trigger Latch Unit */
    #endif
    #if ADC_SUPPORT_GAIN_AND_OFFSET_CALIBRATION
    bool bCalibrationEn;                 /*!< Whether to enable ADC calibration */
    int32_t s32CalibrationOffset;        /*!< ADC calibration offset value */
    int32_t s32CalibrationGain;          /*!< ADC calibration gain value */
    #endif
    #if ADC_SUPPORT_INSTANCE_DIFFMODE_SET
    bool bDifferentialModeEn;            /*!< Whether to enable ADC differential mode */
    #endif
    ADC_ClockDivideType eClockDivider;   /*!< ADC clock divider */
    ADC_SeqModeType eSeqMode;            /*!< ADC sequence mode (single, continuous, discontinuous) */
    bool bAutoDis;                       /*!< Whether to enable audo disable mode, only set this when adc in off state */
    ADC_OverrunModeType eOverrunMode;    /*!< Whether to preserve data when ADC overruns */
    #if ADC_SUPPORT_INTERNAL_REFERENCE
    ADC_RefType eVoltageRef;             /*!< Voltage reference used (external, internal) */
    #endif
    bool bAverageEn;                     /*!< Enable averaging functionality */
    ADC_AverageLenType eAverageLen;      /*!< Selection for number of samples used for averaging */
    uint8_t aSampleTimes[ADC_SAMPLE_TIME_OPTION_CNT];  /*!< ADC sample time options, range: 4 ~ 257 */
    bool bDmaEn;                         /*!< Enable DMA for the ADC */
    #if ADC_SUPPORT_GROUP_INJECTION
    bool bGroupInjectionEn;              /*!< Enable group injection mode */
    #endif

    /* ADC_INT_ENABLE */
    bool bConvCompleteIntEn;             /*!< Enable interrupt when conversion completed */
    bool bOverrunIntEn;                  /*!< Enable interrupt when overrun occured */

    void (*pConvCompleteNotify)(struct _ADC_HandleType *pHandle); /*!< Conversion complete interrupt callback */
    void (*pOverrunNotify)(struct _ADC_HandleType *pHandle);      /*!< Overrun interrupt callback */

    uint32_t *pResultBuffer;                                      /*!< only used for mode 0~3 */
} ADC_InitType;

/**
 * @brief The configuration option for the ADC channel
 *
 */
typedef struct
{
    ADC_ChannelType          eChannel;          /*!< Selected ADC channel */
    ADC_SampleTimeOptionType eSampleTimeOption; /*!< The sample time selection for the channel */
    #if ADC_SUPPORT_CHANNEL_DIFFMODE_SET
    bool                     bDiff;             /*!< Whether diff mode, if a channel do not support differential mode, ignore this */
    #endif
} ADC_ChannelCfgType;

#if ADC_SUPPORT_SG_MODE
/**
 * @brief The configuration option for the ADC sequence group
 *
 */
typedef struct
{
    bool    bSG0En;
    uint8_t u8SG0Len;              /*!< Sequence group length, is must be >= 0 */
    ADC_ChannelCfgType *aSG0Channels;
    bool bSG0ConvCompleteIntEn;    /*!< Enable interrupt when conversion completed */
    uint32_t *pSG0ResultBuffer;
    void (*pSG0ConvCompleteNotify)(struct _ADC_HandleType *pHandle);

    bool    bSG1En;
    uint8_t u8SG1Len;              /*!< Sequence group length, is must be >= 0 */
    ADC_ChannelCfgType *aSG1Channels;
    bool bSG1ConvCompleteIntEn;    /*!< Enable interrupt when conversion completed */
    uint32_t *pSG1ResultBuffer;
    void (*pSG1ConvCompleteNotify)(struct _ADC_HandleType *pHandle);

    bool    bSG2En;
    uint8_t u8SG2Len;              /*!< Sequence group length, is must be >= 0 */
    ADC_ChannelCfgType *aSG2Channels;
    bool bSG2ConvCompleteIntEn;    /*!< Enable interrupt when conversion completed */
    uint32_t *pSG2ResultBuffer;
    void (*pSG2ConvCompleteNotify)(struct _ADC_HandleType *pHandle);

    bool    bSG3En;
    uint8_t u8SG3Len;              /*!< Sequence group length, is must be >= 0 */
    ADC_ChannelCfgType *aSG3Channels;
    bool bSG3ConvCompleteIntEn;    /*!< Enable interrupt when conversion completed */
    uint32_t *pSG3ResultBuffer;
    void (*pSG3ConvCompleteNotify)(struct _ADC_HandleType *pHandle);

    #if ADC_SUPPORT_SG_DMA_MODE
    bool bSGDmaEn;                /*!< Enable sequence group DMA */
    uint8_t u8SGDMAIndex;         /*!< Sequence group DMA selection */
    #endif
} ADC_SGType;
#endif

/**
 * @brief Defines the hardware compare configuration
 *
 * This structure is used to configure the hardware compare feature for the ADC
 *
 * Implements : ADC_CmpType
 */
typedef struct
{
    bool bCmpEn;                         /*!< Enable hardware compare */
    bool bCmpIntEn;                      /*!< Enable interrupt when conversion result lays in the compare threshold */
    ADC_CmpChannelType eCmpChannelType;  /*!< 0 = Compare on all channels; 1 = Compare on the selected channel */
    uint8_t u8CmpChannelSel;             /*!< Compare channel selection */
    uint16_t u16CmpHighThres;            /*!< Compare high threshold */
    uint16_t u16CmpLowThres;             /*!< Compare low threshold */
    void (*pCmpNotify)(struct _ADC_HandleType *pHandle);          /*!< Cmp interrupt callback */
} ADC_CmpType;

#if ADC_SUPPORT_ENHANCED_CMP_BLOCK
/**
 * @brief Defines the hardware enhanced compare configuration
 *
 * This structure is used to configure the hardware compare feature for the ADC
 *
 * Implements : ADC_ECmpType
 */
typedef struct
{
    bool bECmpEn;                         /*!< Enable hardware compare */
    ADC_ECMPOption eECmpOption;           /*!< Compare option */
    ADC_ECmpChannelType eECmpChannelType; /*!< 0 = Compare on all channels; 1 = Compare on the selected channel */
    uint8_t u8ECmpChannelSel;             /*!< Compare channel selection */
    uint16_t u16ECmpHighThres;            /*!< Compare high threshold */
    uint16_t u16ECmpLowThres;             /*!< Compare low threshold */
    bool bECmpHighIntEn;                  /*!< Enable interrupt when conversion result lays in the compare threshold */
    bool bECmpLowIntEn;                   /*!< Enable interrupt when conversion result lays in the compare threshold */
    bool bECmpWinIntEn;                   /*!< Enable interrupt when conversion result lays in the compare threshold */
    void (*pECmpHighNotify)(struct _ADC_HandleType *pHandle);         /*!< ECmp interrupt callback */
    void (*pECmpLowNotify)(struct _ADC_HandleType *pHandle);          /*!< ECmp interrupt callback */
    void (*pECmpWinNotify)(struct _ADC_HandleType *pHandle);          /*!< ECmp interrupt callback */
} ADC_ECmpType;
#endif

#if ADC_SUPPORT_SG_CMP_BLOCK
/**
 * @brief Defines the sequence group compare configuration
 *
 * This structure is used to configure the sequence group compare feature for the ADC
 *
 * Implements : ADC_SGCmpType
 */
typedef struct
{
    bool bSGCmpEn;
    bool bSGCmpIntEn;
    uint32_t u32SGCmpREFSel;
    uint32_t u32SGCmpACTSel;
    void (*pSGCmpNotify)(struct _ADC_HandleType *pHandle);        /*!< SGCMP interrupt callback */
} ADC_SGCmpType;
#endif

#if ADC_SUPPORT_FAST_CMP_BLOCK
/**
 * @brief Defines the fast compare configuration
 *
 * This structure is used to configure the fast compare feature for the ADC
 *
 * Implements : ADC_FCmpType
 */
typedef struct
{
    bool bFCmpEn;                                    /*!< Enable fast compare */
    bool bFCmpPreSetResult;

    ADC_ChannelType          eFCmpChannel;           /*!< Selected HSADC channel */
    ADC_SampleTimeOptionType eFCmpSampleTimeOption;  /*!< The sample time selection for the channel */

    /* Basic reference settings */

    uint16_t u16FCmpRefValue;                        /*!< Fast compare reference value */
    uint16_t u16FCmpUpperDelta;
    uint16_t u16FCmpLowerDelta;

    /* Reference control settings */

    ADC_FCmpRefMode eFCmpRefMode;               /*!< Fast compare operation mode */
    ADC_FCmpRampDir eFCmpRampDir;
    ADC_FCmpRampTrgMode eFCmpRampTrgMode;
    ADC_FCmpRampTrgPolarity eFCmpRampTrgPol;    /*!< */
    uint8_t u8FCmpRampStep;
    uint16_t u16FCmpRampRefA;
    uint16_t u16FCmpRampRefB;

    /* Boundary flag control settings */

    bool bFCmpBFLEn;
    ADC_FCmpBFLAction eFCmpBFLAct;
    bool bFCmpBFLInvert;

    bool bFCmpFallingIntEn;
    bool bFCmpRisingIntEn;
    void (*pFCmpRisingNotify)(struct _ADC_HandleType *pHandle);      /*!< FCmp rising interrupt callback */
    void (*pFCmpFallingNotify)(struct _ADC_HandleType *pHandle);     /*!< FCmp falling interrupt callback */
} ADC_FCmpType;
#endif

/**
 * @name Initial Structure
 * @{
 *
 */

/**
 * @brief Provide the default values of ADC_InitType
 *
 * @param pInitCfg the structure to initialize
 */
void ADC_InitStructure(ADC_InitType *const pInitCfg);

/** @}*/

/**
 * @name Initialization Functions
 *
 */
/**
 * @{
 *
 */

/**
 * @brief Initialize the ADC instance
 *
 * @param pAdcHandle the ADC process handler
 * @param pInitCfg the configurations of the ADC instance
 */
void ADC_Init(ADC_HandleType *pAdcHandle, const ADC_InitType *const pInitCfg);

/**
 * @brief De-initialize the ADC instance
 *
 * Restore the ADC instance to its reset state
 *
 * @param pAdcHandle the ADC instance to de-init
 */
void ADC_DeInit(ADC_HandleType *pAdcHandle);

/**
 * @brief Configure the ADC sample channels
 *
 * @param pAdcHandle the ADC process handler
 * @param aChannels the channels to use
 * @param u8ChannelCnt the quantity of channels
 */
void ADC_InitChannel(ADC_HandleType *pAdcHandle, const ADC_ChannelCfgType aChannels[], const uint8_t u8ChannelCnt);

#if ADC_SUPPORT_SG_MODE

/**
 * @brief Provide the default values of ADC_SGType
 *
 * @param pSGType the structure to initialize
 */
void ADC_InitSGStrcuture(ADC_SGType *const pSGType);

/**
 * @brief Configure the Sequence groups
 *
 * @param pAdcHandle the ADC process handler
 * @param pSGType the sequence group config structure
 * @param u8SGIndex the sequence groups index to use
 */
void ADC_InitSG(ADC_HandleType *pAdcHandle, const ADC_SGType *const pSGType);
#endif

/**
 * @brief Provide the default values of ADC_CmpType
 *
 * @param pCmpCfg the structure to initialize
 */
void ADC_InitCmpStructure(ADC_CmpType *const pCmpCfg);

/**
 * @brief Configure the hardware compare feature of ADC
 *
 * @param pAdcHandle the ADC process handler
 * @param pCmpCfg the compare paremeters
 */
void ADC_InitCmp(ADC_HandleType *pAdcHandle, const ADC_CmpType *const pCmpCfg);

/** @}*/

/**
 * @name Operation functions
 * @{
 *
 */

/**
 * @brief Enable the ADC instance
 *
 * @param pAdcHandle the ADC process handler
 * @return ADC_StatusType whether ADC is enabled successfully
 */
ADC_StatusType ADC_Enable(const ADC_HandleType *pAdcHandle);

/**
 * @brief Disable the ADC instance
 *
 * @param pAdcHandle the ADC process handler
 * @return ADC_StatusType whether ADC is disabled successfully
 */
ADC_StatusType ADC_Disable(ADC_HandleType *pAdcHandle);

/**
 * @brief Start the ADC conversion
 *
 * If the ADC sequence mode is single or continuous, and the trigger mode is ADC_TRIGMODE_SW,
 * the adc conversion will start immediately. Otherwise, the ADC will wait for the trigger
 * signal to start the conversion
 *
 * @param pAdcHandle the ADC process handler
 */
void ADC_Start(const ADC_HandleType *pAdcHandle);

/**
 * @brief Stop the ADC conversion
 *
 * If the ADC sequence mode is single, it will stop the ongoing conversion. If no ongoing
 * conversion, it will have no effect. If the ADC sequence mode is continuous or discontinuous,
 * it will stop the ongoing conversion and meanwhile the further conversions.
 *
 * @param pAdcHandle the ADC process handler
 * @return ADC_StatusType whether ADC is stopped successfully
 */
ADC_StatusType ADC_Stop(const ADC_HandleType *pAdcHandle);

/**
 * @brief Reset the ADC hardware
 *
 * @param pAdcHandle the ADC process handler
 */
void ADC_Reset(const ADC_HandleType *pAdcHandle);

/**
 * @brief The internal interrupt handler function for ADC instances
 *
 * @param pAdcHandle the ADC process handler
 */
void ADCn_IRQHandler(ADC_HandleType *pAdcHandle);

#if ADC_SUPPORT_ENHANCED_CMP_BLOCK

/**
 * @brief Provide the default values of ADC_ECmpType
 *
 * @param pConfig the structure to initialize
 */
void ADC_InitECmpStructure(ADC_ECmpType *const pConfig);

/**
 * @brief Initialize the ADC enhanced compare feature
 *
 * @param pAdcHandle the ADC process handler
 * @param pConfig the structure used to initialize
 */
void ADC_InitECmp(ADC_HandleType *pAdcHandle, const ADC_ECmpType *const pConfig, const ADC_ECMPIndex u8Index);

#endif

#if ADC_SUPPORT_SG_CMP_BLOCK

/**
 * @brief Provide the default values of ADC_SGCmpType
 *
 * @param pConfig the structure to initialize
 */
void ADC_InitSGCmpStructure(ADC_SGCmpType *const pConfig);

/**
 * @brief Initialize the ADC sequence group compare feature
 *
 * @param pAdcHandle the ADC process handler
 * @param pConfig the structure used to initialize
 */
void ADC_InitSGCmp(ADC_HandleType *pAdcHandle, const ADC_SGCmpType *const pConfig);

#endif

#if ADC_SUPPORT_FAST_CMP_BLOCK
/**
 * @brief Provide the default values of ADC_FCmpType
 *
 * @param pConfig the structure to initialize
 */
void ADC_InitFCmpStructure(ADC_FCmpType *const pConfig);

/**
 * @brief Initialize the ADC fast compare feature
 *
 * @param pAdcHandle the ADC process handler
 * @param pConfig the structure used to initialize
 */
void ADC_InitFCmp(ADC_HandleType *pAdcHandle, const ADC_FCmpType *const pConfig);
#endif

/** @}*/

#if defined(__cplusplus)
}
#endif


/** @}*/ /* module_driver_adc */

#endif /* #if ADC_INSTANCE_COUNT > 0U */

#endif
