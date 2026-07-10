/**
 * @file module_driver_smc.h
 * @author Flagchip
 * @brief SMC driver type definition and API
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
   *   0.1.0       2023-12-15    Flagchip085   N/A          First version for FC7300
   *   2.0.0       2024-10-12    Flagchip085   N/A          Change version and release
   ******************************************************************************** */

#ifndef _DRIVER_MODULE_DRIVER_SMC_H_
#define _DRIVER_MODULE_DRIVER_SMC_H_
#include "HwA_smc.h"

#if SMC_INSTANCE_COUNT > 0U

#include "HwA_pmc.h"
#include "HwA_cm7.h"
/**
 * @addtogroup module_driver_smc
 * @{
 */

/********* Dev Error Report ************/
#ifndef SMC_DEV_ERROR_REPORT
#define SMC_DEV_ERROR_REPORT    STD_OFF
#endif

#if SMC_DEV_ERROR_REPORT == STD_ON
#define SMC_ReportDevError(func, error) ReportDevError(SMC_MODULE_ID, func, error)
#endif

/**
 * @name  SMC API Service IDs
 * @{
 */
#define SMC_SET_CLOCK_OUT_ID      0x00U
#define SMC_SET_AONCLKSRC_ID      0x01U
#define SMC_GET_CLOCK_FREQ_ID     0x02U
/** @}*/

/**
 * @name  SMC Dev Error Code
 * @brief Error Code of calling SMC apis
 * @{
 */
#define SMC_E_PARAM_POINTER               0x01U
#define SMC_E_PARAM_OUT_RANGE             0x02U
/** @}*/

/********* Local defines ************/
#define SMC_AONCLK_128K       128000U
#define SMC_AONCLK_32K        32000U
#define SMC_AONCLK_SOSC_32K   32768U
#define SMC_AONCLK_1K         1000U
#define LP_WAKEUP_PAD_NUM     5U
#define SMC_TSTMP0_DUMMY_CYCLES_1M   4800U    /* 4 * 4 Source Clock Cycle =  4 * 4 * 300M/1M  */
#define SMC_TSTMP0_DUMMY_CYCLES_32K  150000U  /* 4 * 4 Source Clock Cycle =  4 * 4 * 300M/32K */
#define SMC_TSTMP0_DUMMY_CYCLES_250K 19200U   /* 4 * 4 Source Clock Cycle =  4 * 4 * 300M/250K */

/** @brief Smc return type. */
typedef enum
{
    SMC_STATUS_SUCCESS = 0U,
    SMC_STATUS_PARAM_INVALID = 1U
} SMC_StatusType;

/** @brief Smc mode */
typedef enum
{
    SMC_MODE_RUN = 0U,         /**< The MCU can run at full speed and the internal supply is fully regulated, that is, in run regulation */
    SMC_MODE_STOP,             /**< Core enters sleep mode and no other clock is gated. Only the core clock is gated. */
    SMC_MODE_WAIT,             /**< Both core and bus clocks are gated off. */
    SMC_MODE_STANBY_0,         /**< All clocks except some low-power clocks can keep on are gated off and the PD1 domain is powered off. please refer to reference manual for detail about standby mode 0. */
    SMC_MODE_STANBY_1,         /**< All clocks except some low-power clocks can keep on are gated off and the PD1 domain is powered off. please refer to reference manual for detail about standby mode 1. */
    SMC_MODE_STANBY_2,         /**< All clocks except some low-power clocks can keep on are gated off and the PD1 domain is powered off. please refer to reference manual for detail about standby mode 2. */
    SMC_MODE_STANBY_3          /**< All clocks except some low-power clocks can keep on are gated off and the PD1 domain is powered off. please refer to reference manual for detail about standby mode 3. */
} SMC_ModeType;

#if SMC_CLOCKCONFIG_SUPPORT
/**
 * @brief SMC clock source type for clock infomation querry
 *
 */
typedef enum
{
    SMC_AON32K_CLK    = 0U,  /*!< AON32K_CLK */
    SMC_RTC_CLK       = 1U,  /*!< RTC_CLK */
    SMC_AON_CLK       = 2U,  /*!< AON_CLK */
    SMC_CLKOUT_CLK    = 3U,  /*!< CLKOUT_CLK */
    SMC_END_OF_CLOCKS = 4U   /*!< End of SMC clocks */
} SMC_ClkSrcType;

/**
 * @brief Data type for register SMC_CLKOUT_CTRL,mainly focus on CLKOUT setting
 *
 */
typedef struct
{
    bool bEnable;                      /*!< SMC ClockOut enable */
    SMC_ClockOutSrcType  eClkOutSrc;  /*!< SMC ClockOut source select */
    SMC_ClockOutDivType  eDivider;    /*!< SMC ClockOut divide ratio */
} SMC_ClkoutType;

/**
 * @brief SMC_AONCLKSR clock source info
 *
 */
typedef struct
{
    SMC_AON32KClkSrcType eAon32KSel;  /*!< SMC 32 KHz Always-on Clock Source Select */
    SMC_RTCClkSrcType    eRtcSel;     /*!< SMC RTC Clock Source Select */
    SMC_AONClkSrcType    eAonSel;     /*!< SMC AON Clock Source Select */
} SMC_AONCLKSRType;

/**
 * @brief LP WakeUp Pad source
 */
typedef enum
{
    SMC_LPWAKEUP_PAD_DISABLE          = 0U,  /*!< Disable */
    SMC_LPWAKEUP_PAD_AONTIMER_TRIGGER = 1U,  /*!< AONTIMER Trigger */
    SMC_LPWAKEUP_PAD_RTC_ALARM        = 2U,  /*!< RTC Alarm(Interrupt) */
#if SMC_CMP0_LPWAKEUP_SUPPORT
    SMC_LPWAKEUP_PAD_CMP0_OUTPUT      = 3U,  /*!< CMP0 Output */
#endif /* SMC_CMP0_LPWAKEUP_SUPPORT */
#if SMC_ADC2_LPWAKEUP_SUPPORT
    SMC_LPWAKEUP_PAD_ADC1_CMP         = 4U,  /*!< ADC1 CMP */
    SMC_LPWAKEUP_PAD_ADC2_CMP         = 5U,  /*!< ADC2 CMP */
#else
    SMC_LPWAKEUP_PAD_ADC0_CMP         = 4U,  /*!< ADC0 CMP */
    SMC_LPWAKEUP_PAD_ADC1_CMP         = 5U,  /*!< ADC1 CMP */
#endif /* SMC_ADC2_LPWAKEUP_SUPPORT */
    SMC_LPWAKEUP_PAD_PMC_RPM_ENTRY    = 6U,  /*!< PMC RPM Entry */
    SMC_LPWAKEUP_PAD_WKU_INTERRUPT    = 7U,  /*!< WKU Interrupt */
    SMC_LPWAKEUP_PAD_TSTMP0_PWM_TRIGGER0 = 8U, /*!< TSTMP0 PWM TRIGGER0, use modulate 0 as posedge, modulate 1 as negedge */
    SMC_LPWAKEUP_PAD_TSTMP0_PWM_TRIGGER1 = 9U, /*!< TSTMP0 PWM TRIGGER1, use modulate 2 as posedge, modulate 3 as negedge */
    SMC_LPWAKEUP_PAD_TSTMP0_CH0_TRIGGER  = 10U, /*!< TSTMP0 CH0 TRIGGER  */
    SMC_LPWAKEUP_PAD_TSTMP0_CH1_TRIGGER  = 11U, /*!< TSTMP0 CH1 TRIGGER */
    SMC_LPWAKEUP_PAD_PMC_V11_EN          = 12U /*!< PMC V11 EN  */
} SMC_LPWakeUpPadSrcType;

/**
 * @brief LP WakeUp Pad polarity select
 */
typedef enum
{
    SMC_LPWAKEUP_PADPOL_KEEP  = 0U, /*!< Keep the LP_WAKEUP CFGx */
    SMC_LPWAKEUP_PADPOL_INVERT 	 /*!< Invert the LP_WAKEUP CFGx */
} SMC_LPWakeUpPadPolType;

/**
 * @brief data type for register SMC_AONCLKSEL
 */
typedef struct
{
    uint8_t   u8LPWakeUpPadNum;                 /*!< SMC LP WakeUp Pad number */
    SMC_LPWakeUpPadSrcType eLpWakeUpPadSel;     /*!< SMC LP WakeUp Pad source select */
    SMC_LPWakeUpPadPolType eLpWakeUpPadPolSel;  /*!< SMC LP WakeUp Pad polarity select */
} SMC_LPWakeUpPadType;

#if SMC_SRAM2_RENTENTION_MODE_SUPPORT
/**
 * @brief SRAM2 block retention control
 */
typedef enum
{
    SMC_SRAM2_RETENTION_DISABLE = 0,      /*!< SRAM2 Block Retention 32KB */
    SMC_SRAM2_RETENTION_32KB    = 0x1U,   /*!< SRAM2 Block Retention 32KB */
    SMC_SRAM2_RETENTION_64KB    = 0x3U,   /*!< SRAM2 Block Retention 64KB */
    SMC_SRAM2_RETENTION_96KB    = 0x7U,   /*!< SRAM2 Block Retention 96KB */
    SMC_SRAM2_RETENTION_128KB   = 0xFU,   /*!< SRAM2 Block Retention 128KB */
    SMC_SRAM2_RETENTION_160KB   = 0x1FU,  /*!< SRAM2 Block Retention 160KB */
    SMC_SRAM2_RETENTION_192KB   = 0x3FU,  /*!< SRAM2 Block Retention 192KB */
    SMC_SRAM2_RETENTION_224KB   = 0x7FU,  /*!< SRAM2 Block Retention 224KB */
    SMC_SRAM2_RETENTION_256KB   = 0xFFU,  /*!< SRAM2 Block Retention 256KB */
    SMC_SRAM2_RETENTION_288KB   = 0x1FFU, /*!< SRAM2 Block Retention 288KB */
    SMC_SRAM2_RETENTION_320KB   = 0x3FFU, /*!< SRAM2 Block Retention 320KB */
    SMC_SRAM2_RETENTION_352KB   = 0x7FFU, /*!< SRAM2 Block Retention 352KB */
    SMC_SRAM2_RETENTION_384KB   = 0xFFFU  /*!< SRAM2 Block Retention 384KB */
} SMC_Sram2RentenCtrlType;
#endif /* SMC_SRAM2_RENTENTION_MODE_SUPPORT */

#if SMC_LP_GOOD_SUPPORT
/**
 * @brief Power good lock selection
 */
typedef enum
{
    SMC_PG_LOCK_PTE1  = 0U, /* PTE1 is locked for LP_GOOD function when PG_IOLOCK_EN is 1 */
    SMC_PG_LOCK_PTE22 = 1U, /* PTE22 is locked for LP_GOOD function when PG_IOLOCK_EN is 1 */
    SMC_PG_LOCK_PTE20 = 2U, /* PTE20 is locked for LP_GOOD function when PG_IOLOCK_EN is 1 */
    SMC_PG_LOCK_PTI20 = 3U  /* PTI20 is locked for LP_GOOD function when PG_IOLOCK_EN is 1 */
} SMC_PGLockSelType;

/**
 * @brief Power good polarity
 */
typedef enum
{
    SMC_PG_ACTIVE_POL_HIGH = 0U,  /* Level 1 is active of LP_GOOD pad */
    SMC_PG_ACTIVE_POL_LOW  = 1U   /* Level 0 is active of LP_GOOD pad */
} SMC_PGActivePolType;
#endif

/**
 * @brief Power good control
 */
typedef struct
{
#if SMC_LP_GOOD_SUPPORT
    bool    bEnable;                  /*!< SMC PG IO enable */
    SMC_PGLockSelType   ePGLockSel;   /*!< SMC PG IOLOCK selection */
    SMC_PGActivePolType ePGActivePol; /*!< SMC PG Active Polarity selection */
#endif
    uint16_t  u16RpmExitCnt;          /*!< SMC RPM exit count */
} SMC_PGCtrlType;

/**
 * @brief SMC mixed type
 */
typedef struct
{
#if SMC_SRAM2_RENTENTION_MODE_SUPPORT
    SMC_Sram2RentenCtrlType eRamRetenSel;  /*!< SMC SRAM2 block selection */
#endif /* SMC_SRAM2_RENTENTION_MODE_SUPPORT */
    SMC_PGCtrlType          tPGCtrlConifg; /*!< SMC PG control configuration */
} SMC_MixedUsedType;

#if SMC_SCG_WAKEUP_CONFIG_SUPPORT
/**
 * @brief SMC SCG wakeup source selection
 */
typedef enum
{
    SMC_SCG_WAKUP_SOURCE_DISABLED         = 0U,  /*!< SMC SCG wakeup source selection0 */
    SMC_SCG_WAKUP_SOURCE_AONTIMER         = 1U,  /*!< SMC SCG wakeup source selection1 */
#if SMC_SCG_WAKEUP_SRC_TSTMP_EXT_TRG_SUPPORT
    SMC_SCG_WAKUP_SOURCE_TSTMP_EXT_TRG0   = 2U,  /*!< SMC SCG wakeup source selection2 */
    SMC_SCG_WAKUP_SOURCE_TSTMP_EXT_TRG1   = 3U,  /*!< SMC SCG wakeup source selection3 */
#endif
#if SMC_SCG_WAKEUP_SRC_TSTMP_EDGE_TRG_SUPPORT
    SMC_SCG_WAKUP_SOURCE_TSTMP_EDGE_TRG2  = 2U,  /*!< SMC SCG wakeup source selection2 */
    SMC_SCG_WAKUP_SOURCE_TSTMP_EDGE_TRG3  = 3U,  /*!< SMC SCG wakeup source selection3 */
#endif
    SMC_SCG_WAKUP_SOURCE_RTC              = 4U,  /*!< SMC SCG wakeup source selection4 */
    SMC_SCG_WAKUP_SOURCE_AONDIV_CLOCK1    = 5U,  /*!< SMC SCG wakeup source selection5 */
    SMC_SCG_WAKUP_SOURCE_RGPIOC_GPIO_INT0 = 6U,  /*!< SMC SCG wakeup source selection6 */
    SMC_SCG_WAKUP_SOURCE_RGPIOC_GPIO_INT2 = 7U,  /*!< SMC SCG wakeup source selection7 */
    SMC_SCG_WAKUP_SOURCE_RGPIOC_GPIO_INT4 = 8U   /*!< SMC SCG wakeup source selection8 */
} SMC_SCGWakeUpSourceSelection;

/**
 * @brief SMC SCG wakeup polarity selection
 */
typedef enum
{
    SMC_SCG_WAKUP_POLARITY_NORMAL         = 0U,  /*!< SMC SCG wakeup polarity selection0 */
    SMC_SCG_WAKUP_POLARITY_REVERSED       = 1U,  /*!< SMC SCG wakeup polarity selection1 */
} SMC_SCGWakeUpPolaritySelection;

/**
 * @brief SMC SCG SIRC Trigger to ADC config
 */
typedef enum
{
    SMC_SCG_SIRC_TRIGGER_TO_ADCS_DISABLE  = 0U,  /*!< SMC SCG SIRC Trigger to ADC Disable */
#if SMC_SCG_WARKEUP_ADC1_AND_ADC2
    SMC_SCG_SIRC_TRIGGER_TO_ADC1          = 1U,  /*!< SMC SCG SIRC Trigger to ADC1 */
    SMC_SCG_SIRC_TRIGGER_TO_ADC2          = 2U,  /*!< SMC SCG SIRC Trigger to ADC2 */
    SMC_SCG_SIRC_TRIGGER_TO_ADC1_AND_ADC2 = 3U   /*!< SMC SCG SIRC Trigger to ADC1 and ADC2 */
#endif
#if SMC_SCG_WARKEUP_ADC0_AND_ADC1
    SMC_SCG_SIRC_TRIGGER_TO_ADC0          = 1U,  /*!< SMC SCG SIRC Trigger to ADC0 */
    SMC_SCG_SIRC_TRIGGER_TO_ADC1          = 2U,  /*!< SMC SCG SIRC Trigger to ADC1 */
    SMC_SCG_SIRC_TRIGGER_TO_ADC0_AND_ADC1 = 3U   /*!< SMC SCG SIRC Trigger to ADC0 and ADC1 */
#endif
} SMC_SCGSIRCTriggerToADCSelection;

/**
 * @brief SMC SCG WAKEUP Register Lock Selection
 */
typedef enum
{
    SMC_SCG_WAKEUP_REG_UNLOCK  = 0U,  /*!< SMC SCG WAKEUP Register Unlock */
    SMC_SCG_WAKEUP_REG_LOCK    = 1U   /*!< SMC SCG WAKEUP Register Lock */
} SMC_SCGWakeUpRegLockSelection;

typedef struct
{
    SMC_SCGWakeUpSourceSelection eWakeUpSource;         /*!< SMC SCG Wakeup Source Selection */
    SMC_SCGWakeUpPolaritySelection eWakeUpPolarity;     /*!< SMC SCG Wakeup Polarity Selection */
    SMC_SCGSIRCTriggerToADCSelection eSircTriggerToAdc; /*!< SMC SCG SIRC Trigger to ADC Selection */
    SMC_SCGWakeUpRegLockSelection eRegLockSel;          /*!< SMC SCG WAKEUP Register Lock Selection */
} SMC_SCGWakeUpConfigType;
#endif

#if SMC_TSTMP0CLOCK_CONFIG_SUPPORT
/**
 * @brief SMC Tstmp0 clock divider
 */
typedef enum
{
    SMC_TSTMP0_CLOCK_DIV_BY1 = 0U,  /*!< SMC TSTMP0 Clock Divider By 1 */
    SMC_TSTMP0_CLOCK_DIV_BY2 = 1U,  /*!< SMC TSTMP0 Clock Divider By 2 */
    SMC_TSTMP0_CLOCK_DIV_BY3 = 2U,  /*!< SMC TSTMP0 Clock Divider By 3 */
    SMC_TSTMP0_CLOCK_DIV_BY4 = 3U,  /*!< SMC TSTMP0 Clock Divider By 4 */
    SMC_TSTMP0_CLOCK_DIV_BY5 = 4U,  /*!< SMC TSTMP0 Clock Divider By 5 */
    SMC_TSTMP0_CLOCK_DIV_BY6 = 5U,  /*!< SMC TSTMP0 Clock Divider By 6 */
    SMC_TSTMP0_CLOCK_DIV_BY7 = 6U,  /*!< SMC TSTMP0 Clock Divider By 7 */
    SMC_TSTMP0_CLOCK_DIV_BY8 = 7U   /*!< SMC TSTMP0 Clock Divider By 8 */
} SMC_Tstmp0ClkDivType;

/**
 * @brief SMC Tstmp0 clock source
 */
typedef enum
{
    SMC_TSTMP0_CLK_SRC_SIRCDIV_1M = 0U,  /*!< SMC TSTMP0 Clock Source SIRCDIV1M */
    SMC_TSTMP0_CLK_SRC_SIRC_32K   = 1U,  /*!< SMC TSTMP0 Clock Source SIRC_32K */
    SMC_TSTMP0_CLK_SRC_SOSC_32K   = 2U,  /*!< SMC TSTMP0 Clock Source SOSC_32K */
    SMC_TSTMP0_CLK_SRC_FOSC_DIVL  = 3U   /*!< SMC TSTMP0 Clock Source FOSC_DIVL */
} SMC_Tstmp0ClkSrcType;

/**
 * @brief SMC Tstmp0 clock configuration
 */
typedef struct
{
    SMC_Tstmp0ClkDivType eClkDiv;  /*!< SMC Tstmp0 clock divider */
    SMC_Tstmp0ClkSrcType eClkSrc;  /*!< SMC Tstmp0 clock source */
} SMC_Tmtmp0ClkConfigType;
 #endif /* #if SMC_TSTMP0CLOCK_CONFIG_SUPPORT */
#endif /* #if SMC_CLOCKCONFIG_SUPPORT */

#if SCG_PLLX_CLK1_SUPPORT
/**
 * @brief SMC PLLx stop mode operation status
 */
typedef struct
{
    bool bPll0Clk1GateOff;      /*!< PLL0 Clk1 gate off status */
#if SCG_PLL0_CLK2_SUPPORT
    bool bPll0Clk2GateOff;      /*!< PLL0 Clk2 gate off status */
#endif /* SCG_PLL0_CLK2_SUPPORT */
#if SCG_PLL1_SUPPORT
    bool bPll1Clk1GateOff;      /*!< PLL1 Clk1 gate off status */
#endif /* SCG_PLL1_SUPPORT */
} SMC_PllStatusType;
#endif /* #if SCG_PLLX_CLK1_SUPPORT */



/* global functions */
/**
 * @brief Set system mode
 *
 * @param eMode MCU low power mode
 *
 */
void SMC_SetSystemMode(const SMC_ModeType eMode);

#if SMC_CLOCKCONFIG_SUPPORT
/**
 * @brief set always on clock source configuration include AON32K, RTC, AONCLK clock.
 *
 * @param pAonclkSrcType pointer to AONCLKSR instance for AON clock source configuration
 * @param bLockStatus to lock current register
 *
 * @return Set clock out operation success/failed
 */
SMC_StatusType SMC_SetAonClkSrc(const SMC_AONCLKSRType *const pAonclkSrcType, bool bLockStatus);

/**
 * @brief Report the clock source status and frequency configured in MCU run time.
 *        The clock frequency and status would change by clock set function.
 *
 * @param eClkkName: the SMC clock source to query
 * @param pFreq: frequency variable point to get the frequency value
 * @return true or false. This indicate the clock source status invalid or request clock source out of
 *         range.
 */
SMC_StatusType SMC_GetSMCClockFreq(const SMC_ClkSrcType eClkkName, uint32_t *const pFreq);

/**
 * @brief Configure the low power wakeup PAD output in SMC_LP_WAKEUP register
 *
 * @param SMC_LPWakeUpPadType the low power wakeup PAD source and polarity configuration
 */
void SMC_SetLPWakeUpPad(const SMC_LPWakeUpPadType* pLPWakeUpPad);

/**
 * @brief Configure SMC mixed used control
 *
 * @param SMC_MixedUsedType SMC mixed used control
 */
void SMC_SetMixedUsedConfiguration(const SMC_MixedUsedType* pMixedUsedConfig);

/**
 * @brief Set clock out
 *
 * @param pSmcClkOut Clock out setting
 * @param bLockStatus Lock status
 * @return Smc return type
 */
SMC_StatusType SMC_SetClockOut(const SMC_ClkoutType *const pSmcClkOut, bool bLockStatus);
#endif /* #if SMC_CLOCKCONFIG_SUPPORT */

#if SMC_SCG_WAKEUP_CONFIG_SUPPORT
/**
 * @brief Set scg wakup configuration.
 *
 * @param SMC_SCGWakeUpConfigType SCG wakeup configuration
 *
 */
void SMC_SetSCGWakeUpConfiguration(const SMC_SCGWakeUpConfigType *const pSCGWakeupConfig);
#endif

#if SMC_TSTMP0CLOCK_CONFIG_SUPPORT
/**
 * @brief Set tstmp0 clock configuration.
 *
 * @param SMC_Tmtmp0ClkConfigType Tstmp0 clock configuration
 *
 * @note  configuration sequence:
 *           1. Disable EN and wait for 4 clock cycles
 *           2. Set div and sel
 *           3. Enable EN and wait for 4 clock cycles
 *        if set lock bit, this register can be restored by POR
 */
void SMC_SetTstmp0ClockConfiguration(const SMC_Tmtmp0ClkConfigType *const pTstmp0ClkConfig);
#endif /* #if SMC_TSTMP0CLOCK_CONFIG_SUPPORT */

/** @}*/ /* module_driver_smc */

#endif /* #if SMC_INSTANCE_COUNT > 0U */

#endif
