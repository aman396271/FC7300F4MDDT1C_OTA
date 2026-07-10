/**
 * @file module_driver_sdadc.h
 * @author flagchip
 * @brief SDADC driver source code
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
   *   0.1.0       2023-12-15    Flagchip0084   N/A          First version for FC7300
   *   2.0.0       2024-10-12    Flagchip0084   N/A          Change version and release
   ******************************************************************************** */

#ifndef _DRIVER_MODULE_DRIVER_SDADC_H_
#define _DRIVER_MODULE_DRIVER_SDADC_H_

#include "HwA_sdadc.h"

#if SDADC_INSTANCE_COUNT > 0U

#include "module_driver_dma.h"

#if defined(__cplusplus)
extern "C" {
#endif
/**
 * @addtogroup module_driver_sdadc
 * @{
 */

#ifndef SDADC_DEV_ERROR_REPORT
#define SDADC_DEV_ERROR_REPORT STD_ON
#endif

#if SDADC_DEV_ERROR_REPORT == STD_ON
#define SDADC_ReportDevError(func, error) ReportDevError(SDADC_MODULE_ID, func, error)
#else
#define SDADC_ReportDevError(func, error)
#endif

#define SDADC_MFSHIFT_LEFT       0x10U
#define SDADC_MFSHIFT_RIGHT      0x0U
#define SDADC_MFSHIFT_DATALENGTH 24U

#define SDADC_E_OK     (0U)    /*!< Return ok */
#define SDADC_E_NOT_OK (0xFFU) /*!< Return not ok */

typedef uint8_t SDADC_RetStatusType;

#define SDADC_INIT_ID                           0x00U
#define SDADC_DEINIT_ID                         0x01U
#define SDADC_MAIN_ENABLE_ID                    0x02U
#define SDADC_CHANNELSWTRIGGER_ID               0x03U
#define SDADC_CHANNELENABLE_ID                  0x04U
#define SDADC_CLEARCHANNELSWTRIGGER_ID          0x05U
#define SDADC_INTEGRATORSWTRIGGER_ID            0x06U
#define SDADC_ENABLETSIGNTRIGGEROUT_ID          0x07U
#define SDADC_GETCONVERSIONRESULT_ID            0x08U
#define SDADC_GETCAPTURETIMESTAMP_ID            0x09U
#define SDADC_GETSIGNDELAYCAPTURE_ID            0x0AU
#define SDADC_GETCHANNELREADY_ID                0x0BU
#define SDADC_GETCHANNELCONVERTING_ID           0x0CU
#define SDADC_GETCHANNELCONVERSIONCOMPLETE_ID   0x0DU
#define SDADC_GETCHANNELFIFOEMPTY_ID            0x0EU
#define SDADC_GETCHANNELFIFOREADY_ID            0x0FU
#define SDADC_CLEARCHANNELFIFOREADY_ID          0x10U
#define SDADC_CLEARCHANNELCONVERSIONCOMPLETE_ID 0x11U
#define SDADC_STARTPWMGENERATION_ID             0x12U
#define SDADC_STOPPWMGENERATION_ID              0x13U
#define SDADC_ENABLEPWMSIGNTRIGGEROUT_ID        0x14U
#define SDADC_SETINTERRUPPTENABLE_ID            0x15U

#define SDADC_E_PARAM_POINTER  0x00U
#define SDADC_E_PARAM_INSTANCE 0x01U
#define SDADC_E_PARAM_CHANNEL  0x02U

typedef uint8_t SDADC_ChannelMaskType;

#define SDADC_INSTANCE_0 0U, /*!< SDADC instance 0 is selected */
#define SDADC_INSTANCE_1 1U  /*!< SDADC instance 1 is selected */
typedef uint8_t SDADC_InstanceType;

typedef enum
{
    SDADC_TRGSIGN_OEN_DISABLED = 0x0, /**< 0x0 - disabled */
    SDADC_TRGSIGN_OEN_ENABLED  = 0x1  /**< 0x1 - Related trigger is enabled and will be set once SIGN falling edge is got */
} SDADC_TRGSignOENType;

typedef enum
{
    SDADC_PWM_CLKSEL_DIV_CLK0 = 0x0, /**< 0x0 - div_clk0 */
    SDADC_PWM_CLKSEL_DIV_CLK1 = 0x1, /**< 0x1 - div_clk1 */
    SDADC_PWM_CLKSEL_DIV_CLK2 = 0x2, /**< 0x2 - div_clk2 */
    SDADC_PWM_CLKSEL_OFF      = 0x3  /**< 0x3 - off */
} SDADC_PWM_CLKSELType;

typedef enum
{
    SDADC_BIT_REV_NORMAL  = 0x0, /**< 0x0 - Normal mode, a triangle wave is used as PWM carrier */
    SDADC_BIT_REV_REVERSE = 0x1  /**< 0x1 - Bit reverse mode. A bit reversed sawtooth wave is used as PWM carrier */
} SDADC_BitRevType;

typedef enum
{
    SDADC_PWM_POLARITY_POSITIVE = 0x0, /**< 0x0 - PWM generator output begin with +1 */
    SDADC_PWM_POLARITY_NEGATIVE = 0x1  /**< 0x1 - PWM generator output begin with -1 */
} SDADC_PWMPolarityType;

typedef enum
{
    SDADC_PWM_PATTERN_STOPPED  = 0x0, /**< 0x0 - Stopped */
    SDADC_PWM_PATTERN_SQUARE   = 0x1, /**< 0x1 - Square wave */
    SDADC_PWM_PATTERN_TRIANGLE = 0x2, /**< 0x2 - Triangle */
    SDADC_PWM_PATTERN_SINE     = 0x3  /**< 0x3 - Sine wave */
} SDADC_PWMPatternType;

/** @brief PRE_DIV Divider Value */
typedef enum
{
    SDADC_PRESCALE_NO_PRESCALE = 0x0, /**< 00b - No prescale */
    SDADC_PRESCALE_DIV_BY_2    = 0x1, /**< 01b - Divided by 2 */
    SDADC_PRESCALE_DIV_BY_4    = 0x2, /**< 10b - Divided by 4 */
    SDADC_PRESCALE_DIV_BY_8    = 0x3  /**< 11b - Divided by 8 */
} SDADC_PrescaleType;

/** @brief Main Enable Selection */
typedef enum
{
    SDADC_MENSEL_INTERNAL = 0x0, /**< 0b - Use internal MEN */
    SDADC_MENSEL_EXTERNAL = 0x1  /**< 1b - Use external MEN */
} SDADC_MENSELType;

typedef enum
{
    SDADC_FIFO_READY     = 0x0, /**< FIFO is ready for data */
    SDADC_FIFO_OVERFLOW  = 0x1, /**< FIFO has overflowed */
    SDADC_FIFO_UNDERFLOW = 0x2, /**< FIFO has underflowed */
} SDADC_FIFOIsrStatusType;

typedef enum
{
    SDADC_DET_ZERO_CROSS      = 0x0, /**< Zero crossing detected */
    SDADC_DET_HIGH_LMT_REACH  = 0x1, /**< High limit reached */
    SDADC_DET_LOW_LMT_REACH   = 0x2, /**< Low limit reached */
    SDADC_DET_WIN_LMT_REACH   = 0x3, /**< Window limit reached */
    SDADC_DET_SHORT_CIRCUIT   = 0x4, /**< Short circuit detected */
    SDADC_DET_DATA_SATURATION = 0x5, /**< Data saturation detected */
    SDADC_DET_CLK_ABSENCE     = 0x6, /**< Clock absence detected */
} SDADC_DetectIsrStatusType;

typedef enum
{
    SDADC_SEL_AUXILIARY = 0x0, /**< 0b - Auxiliary Filter */
    SDADC_SEL_MAIN      = 0x1  /**< 1b - Main Filter */
} SDADC_CICSelectionType;

/** @brief Auxiliary Filter Conversion Mode */
typedef enum
{
    SDADC_AFCM_ALWAYS_ON   = 0x0, /**< 0b - Always on */
    SDADC_AFCM_FOLLOW_MAIN = 0x1  /**< 1b - Follow Main Filter mode (trigger) */
} SDADC_AFCMType;

/** @brief Auxiliary Filter Order */
typedef enum
{
    SDADC_AFORD_RESERVED_00  = 0x0, /**< 00b - Reserved */
    SDADC_AFORD_FIRST_ORDER  = 0x1, /**< 01b - First order filter */
    SDADC_AFORD_SECOND_ORDER = 0x2, /**< 10b - Second order filter */
    SDADC_AFORD_THIRD_ORDER  = 0x3  /**< 11b - Third order filter */
} SDADC_AFORDType;

/** @brief Main Filter Conversion Mode */
typedef enum
{
    SDADC_MFCM_SINGLE_MODE = 0x0, /**< 00b - Single mode. One conversion following a triggering event (edge or level) */
    SDADC_MFCM_CONTINUOUS_MODE =
        0x1, /**< 01b - Continuous conversion mode. Multiple conversions following a triggering event, and the next trigger will cancel and restart conversion */
    SDADC_MFCM_ALWAYS_MODE = 0x2, /**< 10b - Always conversion mode. Multiple conversions following the first trigger, and the next trigger will be ignored */
    SDADC_MFCM_RESERVED_11 = 0x3  /**< 11b - Reserved */
} SDADC_MFCMType;

/** @brief Main Filter Order */
typedef enum
{
    SDADC_MFORD_RESERVED_000     = 0x0, /**< 000b - Reserved */
    SDADC_MFORD_FIRST_ORDER      = 0x1, /**< 001b - First order filter */
    SDADC_MFORD_SECOND_ORDER     = 0x2, /**< 010b - Second order filter */
    SDADC_MFORD_THIRD_ORDER      = 0x3, /**< 011b - Third order filter */
    SDADC_MFORD_FOURTH_ORDER     = 0x4, /**< 100b - Fourth order filter */
    SDADC_MFORD_FIFTH_ORDER      = 0x5, /**< 101b - Fifth order filter */
    SDADC_MFORD_RESERVED_110_111 = 0x6  /**< 110,111 - Reserved */
} SDADC_MFORDType;

/** @brief Limitation Result Activation Select */
typedef enum
{
    SDADC_LMTAVT_SET_ON_LARGER_CLEAR_ON_SMALLER =
        0x0, /**< 0b - The compare result is set only when the conversion result is larger than HILMTn and clear only when the conversion result is smaller than LOLMTn */
    SDADC_LMTAVT_CLEAR_ON_LARGER_SET_ON_SMALLER =
        0x1 /**< 1b - The compare result is clear only when the conversion result is larger than HILMTn and set only when the conversion result is smaller than LOLMTn */
} SDADC_LMTAVTType;

/** @brief Limitation Option */
typedef enum
{
    SDADC_LMTOPT_DETECT_BOTH_HIGH_AND_LOW = 0x0, /**< 00b - Limitation detect on exceed both high and low value */
    SDADC_LMTOPT_DETECT_HIGH_THRESHOLD    = 0x1, /**< 01b - Limitation detect on exceed high threshold value */
    SDADC_LMTOPT_DETECT_LOW_THRESHOLD     = 0x2, /**< 10b - Limitation detect on exceed low threshold value */
    SDADC_LMTOPT_DETECT_WINDOWED_VALUE    = 0x3  /**< 11b - Limitation detect on windowed value */
} SDADC_LMTOPTType;

/** @brief Short Circuit Option */
typedef enum
{
    SDADC_SCDOPT_COUNT_ON_BOTH_0_AND_1 = 0x0, /**< 00b - Count on both 0 and 1. Detect both high and low value */
    SDADC_SCDOPT_COUNT_ON_1            = 0x1, /**< 01b - Count on 1. Detect high value */
    SDADC_SCDOPT_COUNT_ON_0            = 0x2, /**< 10b - Count on 0. Detect low value */
    SDADC_SCDOPT_RESERVED              = 0x3  /**< 11b - Reserved */
} SDADC_SCDOPTType;

/** @brief Short Circuit Detect Conversion Mode */
typedef enum
{
    SDADC_SCDCM_ALWAYS_ON          = 0x0, /**< 0b - Always on when CHEN and MEN are asserted */
    SDADC_SCDCM_FILTER_IN_PROGRESS = 0x1  /**< 1b - Only works when the any filter is in progress */
} SDADC_SCDCMType;

/** @brief Synced Trigger Select Enable */
typedef enum
{
    SDADC_SYNC_TRGEN_SELF    = 0x0, /**< 0b - Synced trigger is selected on the channel itself */
    SDADC_SYNC_TRGEN_DEFINED = 0x1  /**< 1b - Synced trigger is selected on the channel defined by SYNC_TRGSEL */
} SDADC_SYNC_TRGENType;

/** @brief Trigger Level type */
typedef enum
{
    SDADC_TRGLVL_EDGE  = 0x0, /**< 0b - Trigger is edge event. Next edge event will cancel the current conversion, and re-start in single or continuous mode */
    SDADC_TRGLVL_LEVEL = 0x1  /**< 1b - Trigger is level event. De-assert cancels the current conversion, and stop filter function in single or continuous mode */
} SDADC_TRGLVLType;

/** @brief Hardware Trigger Polarity */
typedef enum
{
    SDADC_HTRPOL_HIGH_RISING = 0x0, /**< 0b - High and rising edge effective */
    SDADC_HTRPOL_LOW_FALLING = 0x1  /**< 1b - Low and falling edge effective */
} SDADC_HTRPOLType;

/** @brief Trigger Select */
typedef enum
{
    SDADC_TRGSEL_SOFTWARE = 0x0, /**< 0b - Software trigger is selected */
    SDADC_TRGSEL_HARDWARE = 0x1  /**< 1b - Hardware trigger is selected */
} SDADC_TRGSELType;

/** @brief Input Clock Edge Select */
typedef enum
{
    SDADC_CLKEDG_RESERVED  = 0x0, /**< 00b - Reserved */
    SDADC_CLKEDG_POSEDGE   = 0x1, /**< 01b - Posedge */
    SDADC_CLKEDG_NEGEDGE   = 0x2, /**< 10b - Negedge */
    SDADC_CLKEDG_BOTH_EDGE = 0x3  /**< 11b - Both edge */
} SDADC_CLKEDGType;

/** @brief Input Clock Select */
typedef enum
{
    SDADC_CLKSEL_RESERVED = 0x0, /**< 00b - Reserved */
    SDADC_CLKSEL_DIV_CLK1 = 0x1, /**< 01b - Internal generated function clock div_clk1 selected */
    SDADC_CLKSEL_DIV_CLK2 = 0x2, /**< 10b - Internal generated function clock div_clk2 selected */
    SDADC_CLKSEL_EXTERNAL = 0x3  /**< 11b - Modulator clock from external modulator selected */
} SDADC_CLKSELType;

/** @brief Input Bit Format */
typedef enum
{
    SDADC_IBFMT_ONE_BIT_STREAM  = 0x0, /**< 00b - External one bit stream */
    SDADC_IBFMT_MANCHESTER_CODE = 0x1, /**< 01b - External Manchester code, CLKEDG will determine rise or fall decoder */
} SDADC_IBFMTType;

/** @brief Result Data Format */
typedef enum
{
    SDADC_RDFMT_LEFT_JUSTIFIED_SIGNED   = 0x0, /**< 0b - Left justified, signed, for the case where input bitstream is signed */
    SDADC_RDFMT_LEFT_JUSTIFIED_UNSIGNED = 0x1  /**< 1b - Left justified, unsigned, for the case where input bitstream is unsigned */
} SDADC_RDFMTType;

/** @brief Channel Sign Signal Related Trigger Out Enable */
typedef enum
{
    SDADC_CTRGSIGN_OEN_DISABLED = 0x0, /**< 0b - disabled */
    SDADC_CTRGSIGN_OEN_ENABLED  = 0x1  /**< 1b - Related trigger is enabled and will be set once TSIGN falling edge is got */
} SDADC_CTRGSIGN_OENType;

/** @brief Sign Signal From Channel Selection */
typedef enum
{
    SDADC_SSCH_CH0 = 0x0, /**< 0000b - From channel 0 */
    SDADC_SSCH_CH1 = 0x1, /**< 0001b - From channel 1 */
    SDADC_SSCH_CH2 = 0x2, /**< 0010b - From channel 2 */
} SDADC_SSCHType;

/** @brief Sign Source Selection */
typedef enum
{
    SDADC_SSRC_INTERNAL_PWM      = 0x0, /**< 00b - SDADC internal PWM generation block */
    SDADC_SSRC_CHANNEL_SELECTED  = 0x1, /**< 01b - Sign of result of channel selected by SSCH */
    SDADC_SSRC_EXTERNAL_SIGNAL_0 = 0x2, /**< 10b - External sign signal 0 */
    SDADC_SSRC_EXTERNAL_SIGNAL_1 = 0x3  /**< 11b - External sign signal 1 */
} SDADC_SSRCType;

/** @brief Integration Stop Control */
typedef enum
{
    SDADC_EXTSTP_INTERNAL = 0x0, /**< 0b - Internal control, stop integration after NVALREP+1 integration cycles, support both edge and level events */
    SDADC_EXTSTP_EXTERNAL = 0x1  /**< 1b - External control, stop integration upon the inverse trigger event */
} SDADC_EXTSTPType;

/** @brief Integration Output Gating */
typedef enum
{
    SDADC_IOGT_ALWAYS_WORK                      = 0x0, /**< 0b - Conversion complete flag and FIFO push always works */
    SDADC_IOGT_ONLY_WHEN_INTEGRATION_ONGOING    = 0x1  /**< 1b - Conversion complete flag and FIFO push can only work when Integration is on-going(INTON asserted) */
} SDADC_IOGTType;

/** @brief Modulator Analog Selection */
typedef enum
{
    SDADC_MASEL_EXTERNAL = 0x0, /**< 0b - External modulator analog is selected as channel input */
    SDADC_MASEL_INTERNAL = 0x1  /**< 1b - Internal modulator analog is selected as channel input */
} SDADC_MASELType;

/** @brief Internal Modulator Analog Clock Selection */
typedef enum
{
    SDADC_MACLKSEL_DIV_CLK1 = 0x0, /**< 00b - Div_clk1 is selected as the clock */
    SDADC_MACLKSEL_DIV_CLK0 = 0x1, /**< 01b - Div_clk0 is selected as the clock */
    SDADC_MACLKSEL_RESERVED = 0x2  /**< 1*b - Reserved */
} SDADC_MACLKSELType;

/** @brief Dither Enable */
typedef enum
{
    SDADC_DITHER_EN_DISABLED = 0x0, /**< 0b - Dither is disabled */
    SDADC_DITHER_EN_ENABLED  = 0x1  /**< 1b - Dither is enabled */
} SDADC_DITHER_ENType;

/** @brief Configuration of Positive Input Line with V11 from System */
typedef enum
{
    SDADC_INCFGPV11_DISABLED = 0x0, /**< 0b - Positive input from V11 disabled */
    SDADC_INCFGPV11_ENABLED  = 0x1  /**< 1b - Positive input from V11 enabled */
} SDADC_INCFGPV11Type;

/** @brief Gain Select of Analog Input Path */
typedef enum
{
    SDADC_GAINSEL_1 = 0x0, /**< 00b - 1 */
    SDADC_GAINSEL_2 = 0x1, /**< 01b - 2 */
    SDADC_GAINSEL_4 = 0x2, /**< 10b - 4 */
    SDADC_GAINSEL_8 = 0x3  /**< 11b - 8 */
} SDADC_GAINSELType;

/** @brief Common Voltage Configuration of Positive Inputs */
typedef enum
{
    SDADC_CMENP_NOT_CONNECTED = 0x0, /**< 0b - Is NOT connected to the common mode voltage */
    SDADC_CMENP_CONNECTED     = 0x1  /**< 1b - Is connected to the common mode voltage */
} SDADC_CMENPType;

/** @brief Common Voltage Configuration of Negative Inputs */
typedef enum
{
    SDADC_CMENM_NOT_CONNECTED = 0x0, /**< 0b - Is NOT connected to the common mode voltage */
    SDADC_CMENM_CONNECTED     = 0x1  /**< 1b - Is connected to the common mode voltage */
} SDADC_CMENMType;

/** @brief Configuration of Positive Input Line */
typedef enum
{
    SDADC_INCFGP_FROM_PIN         = 0x0, /**< 00b - From input Pin */
    SDADC_INCFGP_FROM_VREFL       = 0x1, /**< 01b - From VREFL */
    SDADC_INCFGP_FROM_VREFH       = 0x2, /**< 10b - From VREFH */
    SDADC_INCFGP_FROM_VREFH_DIV_2 = 0x3  /**< 11b - From VREFH/2 */
} SDADC_INCFGPType;

/** @brief Configuration of Negative Input Line */
typedef enum
{
    SDADC_INCFGM_FROM_PIN         = 0x0, /**< 00b - From input Pin */
    SDADC_INCFGM_FROM_VREFL       = 0x1, /**< 01b - From VREFL */
    SDADC_INCFGM_FROM_VREFH       = 0x2, /**< 10b - From VREFH */
    SDADC_INCFGM_FROM_VREFH_DIV_2 = 0x3  /**< 11b - From VREFH/2 */
} SDADC_INCFGMType;

/** @brief Input Pin Selection */
typedef enum
{
    SDADC_INSEL_PIN_0 = 0x0, /**< 00b - Input pin 0 selected */
    SDADC_INSEL_PIN_1 = 0x1, /**< 01b - Input pin 1 selected */
    SDADC_INSEL_PIN_2 = 0x2, /**< 10b - Input pin 2 selected */
    SDADC_INSEL_PIN_3 = 0x3  /**< 11b - Input pin 3 selected */
} SDADC_INSELType;

/** @brief Input MUX Control Mode */
typedef enum
{
    SDADC_INMOD_SOFTWARE_CONTROL = 0x0, /**< 00b - Software control mode (INMUX follows INSEL) */
    SDADC_INMOD_PRESET_MODE      = 0x1, /**< 01b - Preset mode (load INMUX upon a channel conversion trigger) */
    SDADC_INMOD_SCAN_MODE        = 0x2, /**< 10b - Scan mode (decrement INMUX upon a channel conversion trigger, wrap around to INSEL) */
    SDADC_INMOD_RESERVED         = 0x3  /**< 11b - Reserved */
} SDADC_INMODType;

/** @brief Timestamp Information Read Mode */
typedef enum
{
    SDADC_TSRDM_DEFAULT_MODE     = 0x0, /**< 00b - Default mode */
    SDADC_TSRDM_DIRECT_MODE      = 0x1, /**< 01b - Direct mode */
    SDADC_TSRDM_FIFO_GATING_MODE = 0x2, /**< 10b - FIFO gating mode */
    SDADC_TSRDM_RESERVED         = 0x3  /**< 11b - Reserved */
} SDADC_TSRDMType;

/** @brief Timestamp Counter Trigger Mode */
typedef enum
{
    SDADC_TSTRGM_IGNORED      = 0x0, /**< 00/11b - Trigger is ignored */
    SDADC_TSTRGM_RISING_EDGE  = 0x1, /**< 01b - Rising edge effective */
    SDADC_TSTRGM_FALLING_EDGE = 0x2  /**< 10b - Falling edge effective */
} SDADC_TSTRGMType;

/** @brief Input Mux Setting Copy Enable */
typedef enum
{
    SDADC_INMXCP_DISABLED = 0x0, /**< 0b - Disabled */
    SDADC_INMXCP_ENABLED  = 0x1  /**< 1b - Copy INMUX from CMACSR to TSTAMP[15:14] */
} SDADC_INMXCPType;

/** @brief Timestamp Counter Enable */
typedef enum
{
    SDADC_TS_EN_DISABLED = 0x0, /**< 0b - Disabled */
    SDADC_TS_EN_ENABLED  = 0x1  /**< 1b - Counting at the rate selected by TSCLKSEL */
} SDADC_TS_ENType;

/** @brief Timestamp Counter Clock Selection */
typedef enum
{
    SDADC_TSCLKSEL_MODULATOR_CLOCK       = 0x0, /**< 00b - Modulator clock */
    SDADC_TSCLKSEL_MODULATOR_CLOCK_DIV_2 = 0x1, /**< 01b - Modulator clock divided by 2 */
    SDADC_TSCLKSEL_MODULATOR_CLOCK_DIV_4 = 0x2, /**< 10b - Modulator clock divided by 4 */
    SDADC_TSCLKSEL_MODULATOR_CLOCK_DIV_8 = 0x3  /**< 11b - Modulator clock divided by 8 */
} SDADC_TSCLKSELType;

typedef enum
{
    SDADC_GAIN_CMP_BYPASS         = 0x0, /**< 00b - Bypass gain compensation */
    SDADC_GAIN_CMP_INTERNAL_GAIN1 = 0x1, /**< 01b - use internal gain factor of gain 1 */
    SDADC_GAIN_CMP_INTERNAL_GAIN2 = 0x2, /**< 02b - use internal gain factor of gain 2 */
    SDADC_GAIN_CMP_EXTERNAL_GAIN  = 0x3  /**< 03b -  use external gain factor */
} SDADC_GainCompType;

typedef enum
{
    SDADC_COCI_INTERRUPT                   = 0,  /**< Conversion Complete Interrupt (COCI) */
    SDADC_FIFO_READY_INTERRUPT             = 1,  /**< FIFO Ready */
    SDADC_FIFO_OVERFLOW_INTERRUPT          = 2,  /**< FIFO Overflow */
    SDADC_FIFO_UNDERFLOW_INTERRUPT         = 3,  /**< FIFO Underflow */
    SDADC_ZERO_CROSS_DETECT_INTERRUPT      = 4,  /**< Zero Cross Detection */
    SDADC_HIGH_LIMIT_REACH_INTERRUPT       = 5,  /**< High Limit Reached */
    SDADC_LOW_LIMIT_REACH_INTERRUPT        = 6,  /**< Low Limit Reached */
    SDADC_WINDOW_LIMIT_REACH_INTERRUPT     = 7,  /**< Window Limit Reached */
    SDADC_SHORT_CIRCUIT_DETECT_INTERRUPT   = 8,  /**< Short Circuit Detection */
    SDADC_DATA_SATURATION_DETECT_INTERRUPT = 9,  /**< Data Saturation Detection */
    SDADC_CLOCK_ABSENCE_DETECT_INTERRUPT   = 10, /**< Clock Absence Detection */
    SDADC_SIGN_DELAY_CAPTURE_INTERRUPT     = 11, /**< Sign Delay Capture */
    SDADC_TSIGN_CHANGED_INTERRUPT          = 12, /**< TSign Changed */
    SDADC_TS_VALID_INTERRUPT               = 13, /**< TimeStamp Valid */
    SDADC_INTERRUPT_MAX                    = 14  /**< Maximum interrupt type */
} SDADC_InterruptType;

typedef struct _SDADC_HandleType
{
    SDADC_InstanceType eInstance; /*!< ADC instance */
    uint8_t            reserve0[3];

    struct
    {
        void (*pCOCISRCallback)(const struct _SDADC_HandleType *pSdadcHandle, uint8_t u8Channel); /**< Callback function for Conversion Complete Interrupt (COCI) */
        void (*pFIFOISRCallback)(const struct _SDADC_HandleType *pSdadcHandle, uint8_t u8Channel, SDADC_FIFOIsrStatusType eStatus); /**< Callback function for FIFO Interrupt */
        void (*pDetectISRCallback)(const struct _SDADC_HandleType *pSdadcHandle, uint8_t u8Channel,
                                   SDADC_DetectIsrStatusType eStatus);                                    /**< Callback function for Detection Interrupt */
        void (*pSignDelayISRCallback)(const struct _SDADC_HandleType *pSdadcHandle, uint8_t u8Channel);   /**< Callback function for Sign Delay Interrupt */
        void (*pTSignChangeISRCallback)(const struct _SDADC_HandleType *pSdadcHandle, uint8_t u8Channel); /**< Callback function for TSign Change Interrupt */
        void (*pTSValidISRCallback)(const struct _SDADC_HandleType *pSdadcHandle, uint8_t u8Channel);     /**< Callback function for TSign Valid Interrupt */
    } tSettings;

} SDADC_HandleType;

typedef struct
{
    SDADC_TRGSignOENType  eTrgSignOEN;  /**< Trigger signal output enable configuration */
    SDADC_PWM_CLKSELType  eClkSel;      /**< Clock selection for SDADC */
    SDADC_BitRevType      eBitRev;      /**< Bit reverse mode configuration */
    SDADC_PWMPolarityType ePwmPolarity; /**< PWM polarity configuration */
    SDADC_PWMPatternType  ePwmPattern;  /**< PWM pattern configuration */
} SDADC_PWMInitType;

typedef struct
{
    uint8_t u8COCIrqEnable;                  /**< Enable interrupt for Conversion Complete Interrupt (COCI) */
    uint8_t u8FIFOReadyIrqEnable;            /**< Enable interrupt for FIFO Ready */
    uint8_t u8FIFOOverFlowIrqEnable;         /**< Enable interrupt for FIFO Overflow */
    uint8_t u8FIFOUnderFlowIrqEnable;        /**< Enable interrupt for FIFO Underflow */
    uint8_t u8ZeroCrossDetectIrqEnable;      /**< Enable interrupt for Zero Cross Detection */
    uint8_t u8HighLimitReachIrqEnable;       /**< Enable interrupt for High Limit Reached */
    uint8_t u8LowLimitReachIrqEnable;        /**< Enable interrupt for Low Limit Reached */
    uint8_t u8WindowLimitReachIrqEnable;     /**< Enable interrupt for Window Limit Reached */
    uint8_t u8ShortCircuitDetectIrqEnable;   /**< Enable interrupt for Short Circuit Detection */
    uint8_t u8DataSaturationDetectIrqEnable; /**< Enable interrupt for Data Saturation Detection */
    uint8_t u8ClockAbsenceDetectIrqEnable;   /**< Enable interrupt for Clock Absence Detection */
    uint8_t u8SignDelayCaptureIrqEnable;     /**< Enable interrupt for Sign Delay Capture */
    uint8_t u8TSignChangedIrqEnable;         /**< Enable interrupt for TSign Changed */
    uint8_t u8TSValidIrqEnable;              /**< Enable interrupt for TimeStamp Valid */
} SDADC_IntInitType;

typedef struct
{
    SDADC_MACLKSELType  eMaClkSrc;                   /**< Internal modulator analog clock source selection */
    SDADC_DITHER_ENType eDitherEnable;               /**< Dither enable control */
    uint8_t             u8ResetCycle;                /**< Reset cycle configuration */
    SDADC_INCFGPV11Type ePosV11;                     /**< Positive input line V11 configuration */
    SDADC_GAINSELType   eGain;                       /**< Gain selection of analog input path */
    uint8_t             u8PosInputCommonVolModeMask; /**< Positive input common voltage mode mask */
    uint8_t             u8NegInputCommonVolModeMask; /**< Negative input common voltage mode mask */
    SDADC_INCFGPType    ePosInputSrc;                /**< Positive input line source configuration */
    SDADC_INCFGMType    eNegInputSrc;                /**< Negative input line source configuration */
    SDADC_INSELType     eInputSel;                   /**< Input pin selection */
    SDADC_INMODType     eInputSelMode;               /**< Input MUX control mode */
} SDADC_ModulatorCfgType;

typedef struct
{
    uint8_t                u8LmtCheckEnable;                /**< Enable limit check */
    SDADC_CICSelectionType eLmtCheckSrc;                    /**< Source for limit check */
    uint8_t                u8ZCDCheckEnable;                /**< Enable zero crossing detection check */
    SDADC_CICSelectionType eZCDCheckSrc;                    /**< Source for zero crossing detection check */
    uint8_t                u8ClkAbsenceCheckEnable;         /**< Enable clock absence detection check */
    uint8_t                u8ShortCircutCheckEnable;        /**< Enable short circuit detection check */
    uint8_t                u8HighLimitReachBreakEnable;     /**< Enable break on high limit reached */
    uint8_t                u8LowLimitReachBreakEnable;      /**< Enable break on low limit reached */
    uint8_t                u8WindowLimitReachBreakEnable;   /**< Enable break on window limit reached */
    uint8_t                u8ShortCircuitDetectBreakEnable; /**< Enable break on short circuit detection */
    uint8_t                u8ClockAbsenceDetectBreakEnable; /**< Enable break on clock absence detection */
    uint8_t                u8LMTFlagProtectionEnable;       /**< Enable limit flag protection */
    uint8_t                u8LMTResultProtectionEnable;     /**< Enable limit result protection */
    uint8_t                u8LMTHysteresisProtectionEnable; /**< Enable limit hysteresis protection */
    uint8_t                u8SCDFlagProtectionEnable;       /**< Enable short circuit detection flag protection */
    uint8_t                u8CADFlagProtectionEnable;       /**< Enable clock absence detection flag protection */
    SDADC_LMTAVTType       eLMTAvtType;                     /**< Limit activation type */
    uint8_t                u8ClkAbsenceCnt;                 /**< Clock absence count */
    SDADC_LMTOPTType       eLMTOptType;                     /**< Limit option type */
    SDADC_SCDOPTType       eSCDOptType;                     /**< Short circuit detection option type */
    SDADC_SCDCMType        eSCDCmtType;                     /**< Short circuit detection conversion mode type */
    uint8_t                u8SCDLmtCnt;                     /**< Short circuit detection limit count */
    uint32_t               u32HighLmt;                      /**< High limit value */
    uint32_t               u32LowLmt;                       /**< Low limit value */
} SDADC_DetectCfgType;
typedef struct
{
    uint8_t                u8SignDelayTsignPosEdge;  /**< Delay for TSIGN positive edge */
    SDADC_CTRGSIGN_OENType eChannelTrgSignOutEnable; /**< Related trigger is enabled and will be set once TSIGN falling edge is got. */
    SDADC_SSCHType         eSignSignalChSel;         /**< Sign signal channel selection */
    SDADC_SSRCType         eSignSignalSrcSel;        /**< Sign signal source selection */
    uint8_t                u8SignPosDelay;           /**< Positive sign delay */
    uint8_t                u8SignNegDelay;           /**< Negative sign delay */
} SDADC_RectCfgType;

typedef struct
{
    uint8_t              u8SyncTrgSel;           /**< Synchronized trigger selection */
    SDADC_SYNC_TRGENType eSyncSrc;               /**< Synchronized trigger source */
    SDADC_HTRPOLType     eHWTrgPolarity;         /**< Hardware trigger polarity */
    SDADC_TRGSELType     eTrgType;               /**< Trigger type */
    uint8_t              u8RestartFilterOnStart; /**< Restart filter on start */
    uint8_t              u8IntgratorCnt;         /**< Integrator count */
    uint8_t              u8IntgratorDiscardCnt;  /**< Integrator discard count */
    uint8_t              u8IntgratorRepeatCnt;   /**< Integrator repeat count */
    uint8_t              u8IntgratShiftValue;    /**< Integrator shift value */
    SDADC_EXTSTPType     eStopControl;           /**< Integration stop control */
    SDADC_IOGTType       eGateControl;           /**< Integration output gating control */
} SDADC_IntegrationCfgType;

typedef struct
{
    uint8_t                  u8IntgraterEnable;  /**< Integrator enable */
    SDADC_IntegrationCfgType tIntgraterCfg;      /**< Integrator configuration */
    uint8_t                  u8RectEnable;       /**< Rectifier enable */
    SDADC_RectCfgType        tRectCfg;           /**< Rectifier configuration */
    uint8_t                  u8MainFilterEnable; /**< Main filter enable */
    SDADC_MFCMType           eMainFilterMode;    /**< Main filter mode */
    SDADC_MFORDType          eMainOrder;         /**< Main filter order */
    uint16_t                 u16MainOSR;         /**< Main filter oversampling ratio */
    uint8_t                  u8AuxFilterEnable;  /**< Auxiliary filter enable */
    SDADC_AFCMType           eAuxFilterMode;     /**< Auxiliary filter mode */
    SDADC_AFORDType          eAuxOrder;          /**< Auxiliary filter order */
    uint16_t                 u16AuxOSR;          /**< Auxiliary filter oversampling ratio */
    SDADC_GainCompType       eGainCompMode;      /**< Gain compensation mode */
    uint32_t                 u32GainFactor;      /**< Gain factor */
    int32_t                  s32Offset;          /**< Offset */
    uint32_t                 u32DebugSel;        /**< Debug Selection */
} SDADC_FilterChainCfgType;

/** @brief SDADC Channel Initialization Structure */
typedef struct
{
    uint8_t              u8SyncTrgSel;            /**< Sync trigger selection */
    SDADC_SYNC_TRGENType eSyncSrc;                /**< Sync source type */
    SDADC_TRGLVLType     eTrgLevel;               /**< Trigger level type */
    SDADC_TRGSELType     eTrgType;                /**< Trigger type */
    SDADC_CLKSELType     eRcvClkSel;              /**< Receive clock selection */
    uint8_t              u8HPFCutOff;             /**< High-pass filter cut-off frequency */
    SDADC_MASELType      u8InternalModulator;     /**< Internal modulator selection */
    SDADC_CLKEDGType     eClkEdg;                 /**< Clock edge type */
    SDADC_IBFMTType      eInputBitFormat;         /**< Input bit format type */
    SDADC_RDFMTType      eResultFmt;              /**< Result data format type */
    uint8_t              u8FIFOEnable;            /**< FIFO enable */
    uint8_t              u8FIFOWaterMark;         /**< FIFO watermark level */
    uint8_t              u8DMAEnable;             /**< DMA enable */
    uint8_t              u8BiasPositiveInputMask; /**< Bias positive input mask */
    uint8_t              u8BiasNegativeInputMask; /**< Bias negative input mask */

    uint8_t              u8TsSyncTrgSel;        /**< Timestamp Sync trigger selection */
    SDADC_SYNC_TRGENType eTsSyncSrc;            /**< Timestamp Sync source type */
    SDADC_TSRDMType      eTsReadMode;           /**< Timestamp Information Read Mode */
    SDADC_TSTRGMType     eTsCounterTriggerMode; /**< Timestamp Counter Trigger Mode */
    SDADC_INMXCPType     eTsInputMuxCopy;       /**< Input Mux Setting Copy Enable */
    SDADC_TS_ENType      eTsCounterEnable;      /**< Timestamp Counter Enable */
    SDADC_TSCLKSELType   eTsCounterClkDiv;      /**< Timestamp Counter Clock Selection */

    SDADC_IntInitType         tIntCfg;         /**< Interrupt configuration */
    SDADC_ModulatorCfgType   *pModulatorCfg;   /**< Pointer to modulator configuration */
    SDADC_FilterChainCfgType *pFilterChainCfg; /**< Pointer to filter chain configuration */
    SDADC_DetectCfgType      *pDectectCfg;     /**< Pointer to detection configuration */
} SDADC_ChannelInitType;

/** @brief SDADC Initialization Structure */
typedef struct
{
    uint8_t            u8BiasEnable;  /**< Bias enable */
    SDADC_PrescaleType ePrescale;     /**< Prescale value for the clock */
    SDADC_MENSELType   eMenSel;       /**< Main enable selection type */
    uint8_t            u8CLKDiv;      /**< Clock divider value */
    uint8_t            u8Clk0Disable; /**< Clock 0 out disable */
    uint8_t            u8Clk1Disable; /**< Clock 1 out disable */
    uint8_t            u8Clk2Disable; /**< Clock 2 out disable */
    uint32_t           u32FunctionClk;

    SDADC_ChannelInitType *pChannelCfg[SDADC_CHANNEL_CNT]; /**< Array of pointers to channel configurations */
    SDADC_PWMInitType     *pPWMCfg;                        /**< Pointer to PWM configuration */

    void (*pCOCISRCallback)(const SDADC_HandleType *pSdadcHandle, uint8_t u8Channel); /**< Callback function for Conversion Complete Interrupt (COCI) */
    void (*pFIFOISRCallback)(const SDADC_HandleType *pSdadcHandle, uint8_t u8Channel, SDADC_FIFOIsrStatusType eStatus);     /**< Callback function for FIFO Interrupt */
    void (*pDetectISRCallback)(const SDADC_HandleType *pSdadcHandle, uint8_t u8Channel, SDADC_DetectIsrStatusType eStatus); /**< Callback function for Detection Interrupt */
    void (*pSignDelayISRCallback)(const SDADC_HandleType *pSdadcHandle, uint8_t u8Channel);                                 /**< Callback function for Sign Delay Interrupt */
    void (*pTSignChangeISRCallback)(const SDADC_HandleType *pSdadcHandle, uint8_t u8Channel);                               /**< Callback function for TSign Change Interrupt */
    void (*pTSValidISRCallback)(const SDADC_HandleType *pSdadcHandle, uint8_t u8Channel);                                   /**< Callback function for TSign Valid Interrupt */
} SDADC_InitType;

/**
 * @brief Initialize the SDADC configuration
 *
 * @param pInitCfg Pointer to the SDADC initialization configuration structure
 */
void SDADC_InitCfg(SDADC_InitType *pInitCfg);

/**
 * @brief Initialize the SDADC channel configuration
 *
 * @param pInitCfg Pointer to the SDADC channel initialization configuration structure
 */
void SDADC_InitChannelCfg(SDADC_ChannelInitType *pInitCfg);

/**
 * @brief Initialize the SDADC modulator configuration
 *
 * @param pInitCfg Pointer to the SDADC modulator initialization configuration structure
 */
void SDADC_InitModulatorCfg(SDADC_ModulatorCfgType *pInitCfg);

/**
 * @brief Initialize the SDADC PWM configuration
 *
 * @param pInitCfg Pointer to the SDADC PWM initialization configuration structure
 */
void SDADC_InitPwmCfg(SDADC_PWMInitType *pInitCfg);

/**
 * @brief Initialize the SDADC filter chain configuration
 *
 * @param pInitCfg Pointer to the SDADC filter chain initialization configuration structure
 */
void SDADC_InitFilterChainCfg(SDADC_FilterChainCfgType *pInitCfg);

/**
 * @brief Initialize the SDADC detection configuration
 *
 * @param pInitCfg Pointer to the SDADC detection initialization configuration structure
 */
void SDADC_InitDectCfg(SDADC_DetectCfgType *pInitCfg);

/**
 * @brief Initialize the SDADC with the given configuration
 *
 * @param pSdadcHandle Pointer to the SDADC handle structure
 * @param pInitCfg Pointer to the SDADC initialization configuration structure
 * @return SDADC_RetStatusType Return status of the initialization operation
 */
SDADC_RetStatusType SDADC_Init(SDADC_HandleType *pSdadcHandle, const SDADC_InitType *const pInitCfg);

/**
 * @brief Deinitialize the SDADC
 *
 * @param pSdadcHandle Pointer to the SDADC handle structure
 * @param RstHoldCount Number of cycles to hold the reset signal
 * @return SDADC_RetStatusType Return status of the deinitialization operation
 */
void SDADC_Deinit(SDADC_HandleType *pSdadcHandle, uint32_t RstHoldCount);

/**
 * @brief Enable or disable a specific SDADC channel
 *
 * @param pSdadcHandle Pointer to the SDADC handle structure
 * @param u8ChannelIndex Index of the channel to enable or disable
 * @param u8Enable Enable (1) or disable (0) the channel
 */
void SDADC_ChannelEnable(SDADC_HandleType *pSdadcHandle, uint8_t u8ChannelIndex, uint8_t u8Enable);

/**
 * @brief Enable or disable the main functionality of the SDADC
 *
 * @param pSdadcHandle Pointer to the SDADC handle structure
 * @param u8Enable Enable (1) or disable (0) the main functionality
 * @return SDADC_RetStatusType Return status of the main enable operation
 */
SDADC_RetStatusType SDADC_MainEnable(SDADC_HandleType *pSdadcHandle, uint8_t u8Enable);

/**
 * @brief Trigger the SDADC channels via software
 *
 * @param pSdadcHandle Pointer to the SDADC handle structure
 * @param u8ChannelMask Mask of the channels to trigger
 */
void SDADC_ChannelSWTrigger(SDADC_HandleType *pSdadcHandle, SDADC_ChannelMaskType u8ChannelMask);

/**
 * @brief Clear the software trigger status of specified SDADC channels
 *
 * This function clears the software trigger status for the SDADC channels
 * specified by the channel mask. This is useful to reset the trigger state
 * of the channels after a software trigger has been issued.
 *
 * @param pSdadcHandle Pointer to the SDADC handle structure
 * @param u8ChannelMask Mask of the channels to clear the software trigger status for
 */
void SDADC_ClearChannelSWTrigger(SDADC_HandleType *pSdadcHandle, SDADC_ChannelMaskType u8ChannelMask);
/**
 * @brief Trigger the SDADC integrator via software
 *
 * @param pSdadcHandle Pointer to the SDADC handle structure
 * @param u8ChannelMask Mask of the channels to trigger the integrator for
 */
void SDADC_IntegratorSWTrigger(SDADC_HandleType *pSdadcHandle, SDADC_ChannelMaskType u8ChannelMask);

/**
 * @brief Enable or disable the Pwm Sign trigger out for a specific SDADC channel
 *
 * @param pSdadcHandle Pointer to the SDADC handle structure
 * @param u8ChannelIndex Index of the channel to enable or disable the TSign trigger out for
 * @param u8Enable Enable (1) or disable (0) the TSign trigger out
 */
void SDADC_EnablePWMSignTriggerOut(SDADC_HandleType *pSdadcHandle, uint8_t u8Enable);

/**
 * @brief Enable or disable the TSign trigger out for a specific SDADC channel
 *
 * @param pSdadcHandle Pointer to the SDADC handle structure
 * @param u8ChannelIndex Index of the channel to enable or disable the TSign trigger out for
 * @param u8Enable Enable (1) or disable (0) the TSign trigger out
 */
void SDADC_EnableTSignTriggerOut(SDADC_HandleType *pSdadcHandle, uint8_t u8ChannelIndex, uint8_t u8Enable);

/**
 * @brief Get the conversion result of a specific SDADC channel
 *
 * @param pSdadcHandle Pointer to the SDADC handle structure
 * @param u8ChannelIndex Index of the channel to get the conversion result for
 * @param pData Pointer to store the conversion result
 * @return SDADC_RetStatusType Return status of the get conversion result operation
 */
SDADC_RetStatusType SDADC_GetConversionResult(SDADC_HandleType *pSdadcHandle, uint8_t u8ChannelIndex, uint32_t *pData);

/**
 * @brief Get the capture timestamp of a specific SDADC channel
 *
 * @param pSdadcHandle Pointer to the SDADC handle structure
 * @param u8ChannelIndex Index of the channel to get the capture timestamp for
 * @param pTimestamp Pointer to store the capture timestamp
 * @param pLastCov Pointer to store the last conversion information
 * @return SDADC_RetStatusType Return status of the get capture timestamp operation
 */
SDADC_RetStatusType SDADC_GetCaptureTimeStamp(SDADC_HandleType *pSdadcHandle, uint8_t u8ChannelIndex, uint16_t *pTimestamp, uint16_t *pLastCov);

/**
 * @brief Get the sign delay capture of a specific SDADC channel
 *
 * @param pSdadcHandle Pointer to the SDADC handle structure
 * @param u8ChannelIndex Index of the channel to get the sign delay capture for
 * @param pCapture Pointer to store the sign delay capture
 * @return SDADC_RetStatusType Return status of the get sign delay capture operation
 */
SDADC_RetStatusType SDADC_GetSignDelayCapture(SDADC_HandleType *pSdadcHandle, uint8_t u8ChannelIndex, uint8_t *pCapture);

/**
 * @brief Get the ready status of a specific SDADC channel
 *
 * @param pSdadcHandle Pointer to the SDADC handle structure
 * @param u8ChannelIndex Index of the channel to get the ready status for
 * @return uint8_t Ready status of the channel
 */
uint8_t SDADC_GetChannelReady(SDADC_HandleType *pSdadcHandle, uint8_t u8ChannelIndex);

/**
 * @brief Get the converting status of a specific SDADC channel
 *
 * @param pSdadcHandle Pointer to the SDADC handle structure
 * @param u8ChannelIndex Index of the channel to get the converting status for
 * @return uint8_t Converting status of the channel
 */
uint8_t SDADC_GetChannelConverting(SDADC_HandleType *pSdadcHandle, uint8_t u8ChannelIndex);

/**
 * @brief Get the conversion complete status of a specific SDADC channel
 *
 * @param pSdadcHandle Pointer to the SDADC handle structure
 * @param u8ChannelIndex Index of the channel to get the conversion complete status for
 * @return uint8_t Conversion complete status of the channel
 */
uint8_t SDADC_GetChannelConversionComplete(SDADC_HandleType *pSdadcHandle, uint8_t u8ChannelIndex);

/**
 * @brief Get the FIFO empty status of a specific SDADC channel
 *
 * @param pSdadcHandle Pointer to the SDADC handle structure
 * @param u8ChannelIndex Index of the channel to get the FIFO empty status for
 * @return uint8_t FIFO empty status of the channel
 */
uint8_t SDADC_GetChannelFIFOEmpty(SDADC_HandleType *pSdadcHandle, uint8_t u8ChannelIndex);

/**
 * @brief Get the FIFO ready status of a specific SDADC channel
 *
 * @param pSdadcHandle Pointer to the SDADC handle structure
 * @param u8ChannelIndex Index of the channel to get the FIFO ready status for
 * @return uint8_t FIFO ready status of the channel
 */
uint8_t SDADC_GetChannelFIFOReady(SDADC_HandleType *pSdadcHandle, uint8_t u8ChannelIndex);

/**
 * @brief Clear the FIFO ready status of a specific SDADC channel
 *
 * @param pSdadcHandle Pointer to the SDADC handle structure
 * @param u8ChannelIndex Index of the channel to clear the FIFO ready status for
 */
void SDADC_ClearChannelFIFOReady(SDADC_HandleType *pSdadcHandle, uint8_t u8ChannelIndex);

/**
 * @brief Clear the conversion complete status of a specific SDADC channel
 *
 * @param pSdadcHandle Pointer to the SDADC handle structure
 * @param u8ChannelIndex Index of the channel to clear the conversion complete status for
 */
void SDADC_ClearChannelConversionComplete(SDADC_HandleType *pSdadcHandle, uint8_t u8ChannelIndex);

/**
 * @brief Start PWM generation with the specified pattern
 *
 * @param pSdadcHandle Pointer to the SDADC handle structure
 * @param ePattern The PWM pattern to be generated
 * @return SDADC_RetStatusType Return status of the PWM generation start operation (SDADC_E_OK if successful, SDADC_E_NOT_OK otherwise)
 */
SDADC_RetStatusType SDADC_StartPwmGeneration(SDADC_HandleType *pSdadcHandle, SDADC_PWMPatternType ePattern);

/**
 * @brief Stop PWM generation
 *
 * @param pSdadcHandle Pointer to the SDADC handle structure
 * @return SDADC_RetStatusType Return status of the PWM generation stop operation (SDADC_E_OK if successful, SDADC_E_NOT_OK otherwise)
 */
SDADC_RetStatusType SDADC_StopPwmGeneration(SDADC_HandleType *pSdadcHandle);

/**
 * @brief Clear the integrator software trigger for the specified SDADC channels
 *
 * This function clears the integrator software trigger for the SDADC channels
 * specified by the channel mask.
 *
 * @param pSdadcHandle Pointer to the SDADC handle structure
 * @param u8ChannelMask Channel mask indicating which channels to clear the integrator trigger for
 *
 * @return void
 */
void SDADC_ClearIntegratorSWTrigger(SDADC_HandleType *pSdadcHandle, SDADC_ChannelMaskType u8ChannelMask);

/**
 * @brief Set the interrupt enable status for the specified SDADC interrupt type
 *
 * This function enables or disables the specified interrupt type for the given SDADC channel.
 * Before setting the interrupt enable status, the function clears the corresponding interrupt
 * status to ensure no pending interrupts are left unhandled.
 *
 * @param pSdadcHandle Pointer to the SDADC handle structure
 * @param u8ChannelIndex Index of the SDADC channel
 * @param eIntType Interrupt type to be configured (e.g., SDADC_COCI_INTERRUPT, SDADC_FIFO_READY_INTERRUPT, etc.)
 * @param u8Enable Enable or disable the interrupt (1 to enable, 0 to disable)
 *
 * @return void
 */
void SDADC_SetInterrupptEnable(SDADC_HandleType *pSdadcHandle, uint8_t u8ChannelIndex, SDADC_InterruptType eIntType, uint8_t u8Enable);

void SDADCn_IRQHandler(SDADC_HandleType *pSdadcHandle, uint8_t u8ChannelIndex);

/** @}*/ /* module_driver_sdadc */
#if defined(__cplusplus)
}
#endif

#endif /* #if SDADC_INSTANCE_COUNT > 0U */

#endif
