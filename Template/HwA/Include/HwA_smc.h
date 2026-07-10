/**
 * @file HwA_smc.h
 * @author Flagchip
 * @brief SMC hardware access layer
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
   *   0.1.0      2023-12-15     Flagchip084   N/A          First version for FC7300
   *   2.0.0      2024-10-12     Flagchip084   N/A          Change version and release
   *   2.1.0       2024-11-28    Flagchip0122   N/A          Add features for FC7300DQ
   ******************************************************************************** */

#ifndef _HWA_SMC_H_
#define _HWA_SMC_H_

#include "device_header.h"

#if SMC_INSTANCE_COUNT > 0U

/**
 * @defgroup HwA_smc
 * @ingroup module_driver_smc
 * @{
 */

/********* Local typedef ************/
/** @brief SMC stop mode control */
typedef enum
{
    SMC_STOP_MODE = 0U,
    SMC_STANDBY_MODE = 4U
} SMC_LpwModeCtrlType;

/** @brief SMC standby mode */
typedef enum
{
    SMC_CFG_STANDBY_0 = 0U,
    SMC_CFG_STANDBY_1 = 1U,
    SMC_CFG_STANDBY_2 = 2U,
    SMC_CFG_STANDBY_3 = 3U
} SMC_StandbyModeType;

#if SMC_CLOCKCONFIG_SUPPORT
/**
 * @brief SMC clock out source type
 *
 */
typedef enum
{
    SMC_CLKOUT_SCG_CLKOUT    = 0U,  /*!< SCG CLKOUT */
    SMC_CLKOUT_FOSC_DIVM_CLK = 2U,  /*!< FOSC DIVM CLK */
    SMC_CLKOUT_SLOW_CLK      = 3U,  /*!< SLOW CLK */
    SMC_CLKOUT_SIRC_DIVM_CLK = 4U,  /*!< SIRC DIVM CLK */
    SMC_CLKOUT_PLL1_DIVM_CLK = 5U,  /*!< PLL1 DIVM CLK */
    SMC_CLKOUT_FIRC_DIVM_CLK = 6U,  /*!< FIRC DIVM CLK */
    SMC_CLKOUT_CORE_CLK      = 7U,  /*!< CORE CLK */
    SMC_CLKOUT_PLL0_DIVM_CLK = 8U,  /*!< PLL0 DIVM CLK */
    SMC_CLKOUT_BUS_CLK       = 9U,  /*!< BUS CLK */
    SMC_CLKOUT_SIRC_128K_CLK = 10U, /*!< SIRC 128K CLK */
    SMC_CLKOUT_AON_CLK       = 12U, /*!< AON CLK */
    SMC_CLKOUT_RTC_CLK       = 14U  /*!< AON32K CLK */
} SMC_ClockOutSrcType;

/**
 * @brief SMC clock out divide ratio type
 *
 */
typedef enum
{
    SMC_CLKOUT_DIV_BY1 = 0U,       /*!< Divided by 1 */
    SMC_CLKOUT_DIV_BY2 = 1U,       /*!< Divided by 2 */
    SMC_CLKOUT_DIV_BY3 = 2U,       /*!< Divided by 3 */
    SMC_CLKOUT_DIV_BY4 = 3U,       /*!< Divided by 4 */
    SMC_CLKOUT_DIV_BY5 = 4U,       /*!< Divided by 5 */
    SMC_CLKOUT_DIV_BY6 = 5U,       /*!< Divided by 6 */
    SMC_CLKOUT_DIV_BY7 = 6U,       /*!< Divided by 7 */
    SMC_CLKOUT_DIV_BY8 = 7U        /*!< Divided by 8 */
} SMC_ClockOutDivType;

/**
 * @brief Data type for SMC_AONCLKSR[32KAONCLKSR], set AON32KCLK source clock
 *
 */
typedef enum
{
    SMC_AON32K_SIRCDIV_32K_CLK = 1U,  /*!< SMC_AONCLKSR[32KAONCLKSR], SIRCDIV_32K */
    SMC_AON32K_SOSC32K_CLK     = 2U,  /*!< SMC_AONCLKSR[32KAONCLKSR], SOSC32K */
    SMC_AON32K_SIRC32K_CLK     = 3U   /*!< SMC_AONCLKSR[32KAONCLKSR], SIRC32K */
} SMC_AON32KClkSrcType;

/**
 * @brief Data type for SMC_RTCCLKSEL[RTCCLKSEL], set RTCCLK source clock
 *
 */
typedef enum
{
    SMC_RTC_FOSCDIVL_CLK    = 0U,  /*!< SMC_RTCCLKSEL[RTCCLKSEL], FOSC_DIVL */
    SMC_RTC_SIRCDIV_32K_CLK = 1U,  /*!< SMC_RTCCLKSEL[RTCCLKSEL], SIRC_DIV */
    SMC_RTC_SOSC_CLK        = 2U,  /*!< SMC_RTCCLKSEL[RTCCLKSEL], SOSC */
    SMC_RTC_SIRC32K_CLK     = 3U   /*!< SMC_RTCCLKSEL[RTCCLKSEL], SIRC_32K */
} SMC_RTCClkSrcType;

/**
 * @brief Data type for SMC_AONCLKSR[AONCLKSR], set AONCLK source clock
 *
 */
typedef enum
{
    SMC_AON_SIRCDIV_128K_CLK = 0U,  /*!< SMC_AONCLKSR[AONCLKSR], SIRCDIV_128K */
    SMC_AON_SIRC32K_CLK      = 1U,  /*!< SMC_AONCLKSR[AONCLKSR], SIRC32K */
    SMC_AON_SIRCDIV_32K_CLK  = 2U,  /*!< SMC_AONCLKSR[AONCLKSR], SIRCDIV_32K */
    SMC_AON_SIRC32_1K_CLK    = 3U   /*!< SMC_AONCLKSR[AONCLKSR], SIRC32_1K */
} SMC_AONClkSrcType;
#endif

/********* Local inline function ************/
/**
 * @brief Clear stop mode control value
 *
 */
LOCAL_INLINE void SMC_HWA_ClearStopModeCtrl(void)
{
    SMC->PMCTRL &= ~(uint32_t)SMC_PMCTRL_STOP_MODE_MASK;
}

/**
 * @brief Set stop mode control
 *
 * @param eMode Stop mode control type
 */
LOCAL_INLINE void SMC_HWA_SetStopModeCtrl(SMC_LpwModeCtrlType eMode)
{
    SMC->PMCTRL = (uint32_t)eMode;
}

/**
 * @brief Clear standby mode
 *
 */
LOCAL_INLINE void SMC_HWA_ClearStandbyMode(void)
{
    SMC->STANDBY_CFG &= ~(uint32_t)SMC_STANDBY_CFG_OPTION_MASK;
}

/**
 * @brief Set standby mode
 *
 * @param eMode Standby mode type
 */
LOCAL_INLINE void SMC_HWA_SetStandbyMode(SMC_StandbyModeType eMode)
{
    SMC->STANDBY_CFG = (uint32_t)eMode;
}

#if SMC_CLOCKCONFIG_SUPPORT

#if SMC_TSTMP0CLOCK_CONFIG_SUPPORT
/**
 * @brief Set tstmp0 clock enable
 *
 */
LOCAL_INLINE void SMC_HWA_EnableTstmp0Clk(void)
{
    SMC->TSTMP0_CLK_CFG |= SMC_TSTMP0_CLK_CFG_EN_MASK;
}

/**
 * @brief Set tstmp0 clock disable
 *
 */
LOCAL_INLINE void SMC_HWA_DisableTstmp0Clk(void)
{
    SMC->TSTMP0_CLK_CFG &= ~(uint32_t)SMC_TSTMP0_CLK_CFG_EN_MASK;
}

/**
 * @brief Set TSTMP0_CLK_CFG reg
 *
 * @param u32Data Value to set
 */
LOCAL_INLINE void SMC_HWA_SetTstmp0_CLk_CfgReg(uint32_t u32Data)
{
    SMC->TSTMP0_CLK_CFG = u32Data;
}

/**
 * @brief Get TSTMP0_CLK_CFG reg
 *
 * @return uint32_t Register value
 */
LOCAL_INLINE uint32_t SMC_HWA_GetTstmp0_CLk_CfgReg(void)
{
    return SMC->TSTMP0_CLK_CFG;
}

/**
 * @brief Lock TSTMP0_CLK_CFG reg
 *
 */
LOCAL_INLINE void SMC_HWA_LockTstmp0_CLk_CfgReg(void)
{
    SMC->TSTMP0_CLK_CFG |= SMC_TSTMP0_CLK_CFG_LOCK_MASK;
}

/**
 * @brief Unlock TSTMP0_CLK_CFG reg
 *
 */
LOCAL_INLINE void SMC_HWA_UnlockTstmp0_CLk_CfgReg(void)
{
    SMC->TSTMP0_CLK_CFG &= ~(uint32_t)SMC_TSTMP0_CLK_CFG_LOCK_MASK;
}

#endif /* #if SMC_TSTMP0CLOCK_CONFIG_SUPPORT */

/**
 * @brief Set PMPORT register
 *
 * @param u32Data set value
 */
LOCAL_INLINE void SMC_HWA_SetPmportReg(uint32_t u32Data)
{
    SMC->PMPROT = u32Data;
}

/**
 * @brief Get the value of PGCTRL_PROT.
 *
 * @return uint32_t the value of PGCTRL_PROT.
 */
LOCAL_INLINE uint32_t SMC_HWA_GetPGCTRL_PROT(void)
{
    return ((SMC->PMPROT & SMC_PMPROT_PGCTRL_PROT_MASK) >> SMC_PMPROT_PGCTRL_PROT_SHIFT);
}

/**
 * @brief Set PGCTRL_PROT.
 *
 * @param uint32_t u32Value PGCTRL_PROT value.
 */
LOCAL_INLINE void SMC_HWA_SetPGCTRL_PROT(uint32_t u32Value)
{
    SMC->PMPROT = ((SMC->PMPROT & ~SMC_PMPROT_PGCTRL_PROT_MASK) | SMC_PMPROT_PGCTRL_PROT(u32Value));
}

/**
 * @brief Get the value of RAMRET_PROT.
 *
 * @return uint32_t the value of RAMRET_PROT.
 */
LOCAL_INLINE uint32_t SMC_HWA_GetRAMRET_PROT(void)
{
    return ((SMC->PMPROT & SMC_PMPROT_RAMRET_PROT_MASK) >> SMC_PMPROT_RAMRET_PROT_SHIFT);
}

/**
 * @brief Set RAMRET_PROT.
 *
 * @param uint32_t u32Value RAMRET_PROT value.
 */
LOCAL_INLINE void SMC_HWA_SetRAMRET_PROT(uint32_t u32Value)
{
    SMC->PMPROT = ((SMC->PMPROT & ~SMC_PMPROT_RAMRET_PROT_MASK) | SMC_PMPROT_RAMRET_PROT(u32Value));
}

/**
 * @brief Get the value of IOLOCK_PROT.
 *
 * @return uint32_t the value of IOLOCK_PROT.
 */
LOCAL_INLINE uint32_t SMC_HWA_GetIOLOCK_PROT(void)
{
    return ((SMC->PMPROT & SMC_PMPROT_IOLOCK_PROT_MASK) >> SMC_PMPROT_IOLOCK_PROT_SHIFT);
}

/**
 * @brief Set IOLOCK_PROT.
 *
 * @param uint32_t u32Value IOLOCK_PROT value.
 */
LOCAL_INLINE void SMC_HWA_SetIOLOCK_PROT(uint32_t u32Value)
{
    SMC->PMPROT = ((SMC->PMPROT & ~SMC_PMPROT_IOLOCK_PROT_MASK) | SMC_PMPROT_IOLOCK_PROT(u32Value));
}

/**
 * @brief Get the value of WAKEUP_PROT.
 *
 * @return uint32_t the value of WAKEUP_PROT.
 */
LOCAL_INLINE uint32_t SMC_HWA_GetWAKEUP_PROT(void)
{
    return ((SMC->PMPROT & SMC_PMPROT_WAKEUP_PROT_MASK) >> SMC_PMPROT_WAKEUP_PROT_SHIFT);
}

/**
 * @brief Set WAKEUP_PROT.
 *
 * @param uint32_t u32Value WAKEUP_PROT value.
 */
LOCAL_INLINE void SMC_HWA_SetWAKEUP_PROT(uint32_t u32Value)
{
    SMC->PMPROT = (SMC->PMPROT & ~SMC_PMPROT_WAKEUP_PROT_MASK) | SMC_PMPROT_WAKEUP_PROT(u32Value);
}

/**
 * @brief Get the value of STANDBY_CFG_PROT.
 *
 * @return uint32_t the value of STANDBY_CFG_PROT.
 */
LOCAL_INLINE uint32_t SMC_HWA_GetSTANDBY_CFG_PROT(void)
{
    return ((SMC->PMPROT & SMC_PMPROT_STANDBY_CFG_PROT_MASK) >> SMC_PMPROT_STANDBY_CFG_PROT_SHIFT);
}

/**
 * @brief Set STANDBY_CFG_PROT.
 *
 * @param uint32_t u32Value STANDBY_CFG_PROT value.
 */
LOCAL_INLINE void SMC_HWA_SetSTANDBY_CFG_PROT(uint32_t u32Value)
{
    SMC->PMPROT = ((SMC->PMPROT & ~SMC_PMPROT_STANDBY_CFG_PROT_MASK) | SMC_PMPROT_STANDBY_CFG_PROT(u32Value));
}

/**
 * @brief Get the value of PMCTRL_PROT.
 *
 * @return uint32_t the value of PMCTRL_PROT.
 */
LOCAL_INLINE uint32_t SMC_HWA_GetPMCTRL_PROT(void)
{
    return ((SMC->PMPROT & SMC_PMPROT_PMCTRL_PROT_MASK) >> SMC_PMPROT_PMCTRL_PROT_SHIFT);
}

/**
 * @brief Set PMCTRL_PROT.
 *
 * @param uint32_t u32Value PMCTRL_PROT value.
 */
LOCAL_INLINE void SMC_HWA_SetPMCTRL_PROT(uint32_t u32Value)
{
    SMC->PMPROT = ((SMC->PMPROT & ~SMC_PMPROT_PMCTRL_PROT_MASK) | SMC_PMPROT_PMCTRL_PROT(u32Value));
}

/**
 * @brief Set low power wakeup PADx configure source
 *
 * @param u8PadNum Low power PAD number
 * @param u8PadSrc Low power PAD source
 */
LOCAL_INLINE void SMC_HWA_SetLPWakeUpPadSrc(uint8_t u8PadNum, uint8_t u8PadSrc)
{
    SMC->WAKEUP = (((SMC->WAKEUP) & (~(SMC_WAKEUP_LP_WAKEUP_CFG0_MASK >> (4U * (uint32)u8PadNum)))) |
                    (SMC_WAKEUP_LP_WAKEUP_CFG0(u8PadSrc) >> (4U * (uint32)u8PadNum)));
}

/**
 * @brief Set low power wakeup PADx configure source polarity
 *
 * @param u8PadNum Low power PAD number
 * @param u8PadPolarity Low power PAD polarity
 */
LOCAL_INLINE void SMC_HWA_SetLPWakeUpPadPol(uint8_t u8PadNum, uint8_t u8PadPolarity)
{
    SMC->WAKEUP = (((SMC->WAKEUP) & (~(SMC_WAKEUP_LP_WAKEUP_POL0_MASK >> (uint32)u8PadNum))) |
                    (SMC_WAKEUP_LP_WAKEUP_POL0(u8PadPolarity) >> (uint32)u8PadNum));
}

/**
 * @brief Get the value of LP_WAKEUP_CFG0.
 *
 * @return uint32_t the value of LP_WAKEUP_CFG0.
 */
LOCAL_INLINE uint32_t SMC_HWA_GetLP_WAKEUP_CFG0(void)
{
    return ((SMC->WAKEUP & SMC_WAKEUP_LP_WAKEUP_CFG0_MASK) >> SMC_WAKEUP_LP_WAKEUP_CFG0_SHIFT);
}

/**
 * @brief Set LP_WAKEUP_CFG0.
 *
 * @param uint32_t u32Value LP_WAKEUP_CFG0 value.
 */
LOCAL_INLINE void SMC_HWA_SetLP_WAKEUP_CFG0(uint32_t u32Value)
{
    SMC->WAKEUP = ((SMC->WAKEUP & ~SMC_WAKEUP_LP_WAKEUP_CFG0_MASK) | SMC_WAKEUP_LP_WAKEUP_CFG0(u32Value));
}

/**
 * @brief Get the value of LP_WAKEUP_CFG1.
 *
 * @return uint32_t the value of LP_WAKEUP_CFG1.
 */
LOCAL_INLINE uint32_t SMC_HWA_GetLP_WAKEUP_CFG1(void)
{
    return ((SMC->WAKEUP & SMC_WAKEUP_LP_WAKEUP_CFG1_MASK) >> SMC_WAKEUP_LP_WAKEUP_CFG1_SHIFT);
}

/**
 * @brief Set LP_WAKEUP_CFG1.
 *
 * @param uint32_t u32Value LP_WAKEUP_CFG1 value.
 */
LOCAL_INLINE void SMC_HWA_SetLP_WAKEUP_CFG1(uint32_t u32Value)
{
    SMC->WAKEUP = ((SMC->WAKEUP & ~SMC_WAKEUP_LP_WAKEUP_CFG1_MASK) | SMC_WAKEUP_LP_WAKEUP_CFG1(u32Value));
}

/**
 * @brief Get the value of LP_WAKEUP_CFG2.
 *
 * @return uint32_t the value of LP_WAKEUP_CFG2.
 */
LOCAL_INLINE uint32_t SMC_HWA_GetLP_WAKEUP_CFG2(void)
{
    return ((SMC->WAKEUP & SMC_WAKEUP_LP_WAKEUP_CFG2_MASK) >> SMC_WAKEUP_LP_WAKEUP_CFG2_SHIFT);
}

/**
 * @brief Set LP_WAKEUP_CFG2.
 *
 * @param uint32_t u32Value LP_WAKEUP_CFG2 value.
 */
LOCAL_INLINE void SMC_HWA_SetLP_WAKEUP_CFG2(uint32_t u32Value)
{
    SMC->WAKEUP = ((SMC->WAKEUP & ~SMC_WAKEUP_LP_WAKEUP_CFG2_MASK) | SMC_WAKEUP_LP_WAKEUP_CFG2(u32Value));
}

/**
 * @brief Get the value of LP_WAKEUP_CFG3.
 *
 * @return uint32_t the value of LP_WAKEUP_CFG3.
 */
LOCAL_INLINE uint32_t SMC_HWA_GetLP_WAKEUP_CFG3(void)
{
    return ((SMC->WAKEUP & SMC_WAKEUP_LP_WAKEUP_CFG3_MASK) >> SMC_WAKEUP_LP_WAKEUP_CFG3_SHIFT);
}

/**
 * @brief Set LP_WAKEUP_CFG3.
 *
 * @param uint32_t u32Value LP_WAKEUP_CFG3 value.
 */
LOCAL_INLINE void SMC_HWA_SetLP_WAKEUP_CFG3(uint32_t u32Value)
{
    SMC->WAKEUP = ((SMC->WAKEUP & ~SMC_WAKEUP_LP_WAKEUP_CFG3_MASK) | SMC_WAKEUP_LP_WAKEUP_CFG3(u32Value));
}

/**
 * @brief Get the value of LP_WAKEUP_CFG4.
 *
 * @return uint32_t the value of LP_WAKEUP_CFG4.
 */
LOCAL_INLINE uint32_t SMC_HWA_GetLP_WAKEUP_CFG4(void)
{
    return ((SMC->WAKEUP & SMC_WAKEUP_LP_WAKEUP_CFG4_MASK) >> SMC_WAKEUP_LP_WAKEUP_CFG4_SHIFT);
}

/**
 * @brief Set LP_WAKEUP_CFG4.
 *
 * @param uint32_t u32Value LP_WAKEUP_CFG4 value.
 */
LOCAL_INLINE void SMC_HWA_SetLP_WAKEUP_CFG4(uint32_t u32Value)
{
    SMC->WAKEUP = ((SMC->WAKEUP & ~SMC_WAKEUP_LP_WAKEUP_CFG4_MASK) | SMC_WAKEUP_LP_WAKEUP_CFG4(u32Value));
}

/**
 * @brief Get the value of LP_WAKEUP_POL0.
 *
 * @return uint32_t the value of LP_WAKEUP_POL0.
 */
LOCAL_INLINE uint32_t SMC_HWA_GetLP_WAKEUP_POL0(void)
{
    return ((SMC->WAKEUP & SMC_WAKEUP_LP_WAKEUP_POL0_MASK) >> SMC_WAKEUP_LP_WAKEUP_POL0_SHIFT);
}

/**
 * @brief Set LP_WAKEUP_POL0.
 *
 * @param uint32_t u32Value LP_WAKEUP_POL0 value.
 */
LOCAL_INLINE void SMC_HWA_SetLP_WAKEUP_POL0(uint32_t u32Value)
{
    SMC->WAKEUP = ((SMC->WAKEUP & ~SMC_WAKEUP_LP_WAKEUP_POL0_MASK) | SMC_WAKEUP_LP_WAKEUP_POL0(u32Value));
}

/**
 * @brief Get the value of LP_WAKEUP_POL1.
 *
 * @return uint32_t the value of LP_WAKEUP_POL1.
 */
LOCAL_INLINE uint32_t SMC_HWA_GetLP_WAKEUP_POL1(void)
{
    return ((SMC->WAKEUP & SMC_WAKEUP_LP_WAKEUP_POL1_MASK) >> SMC_WAKEUP_LP_WAKEUP_POL1_SHIFT);
}

/**
 * @brief Set LP_WAKEUP_POL1.
 *
 * @param uint32_t u32Value LP_WAKEUP_POL1 value.
 */
LOCAL_INLINE void SMC_HWA_SetLP_WAKEUP_POL1(uint32_t u32Value)
{
    SMC->WAKEUP = ((SMC->WAKEUP & ~SMC_WAKEUP_LP_WAKEUP_POL1_MASK) | SMC_WAKEUP_LP_WAKEUP_POL1(u32Value));
}

/**
 * @brief Get the value of LP_WAKEUP_POL2.
 *
 * @return uint32_t the value of LP_WAKEUP_POL2.
 */
LOCAL_INLINE uint32_t SMC_HWA_GetLP_WAKEUP_POL2(void)
{
    return ((SMC->WAKEUP & SMC_WAKEUP_LP_WAKEUP_POL2_MASK) >> SMC_WAKEUP_LP_WAKEUP_POL2_SHIFT);
}

/**
 * @brief Set LP_WAKEUP_POL2.
 *
 * @param uint32_t u32Value LP_WAKEUP_POL2 value.
 */
LOCAL_INLINE void SMC_HWA_SetLP_WAKEUP_POL2(uint32_t u32Value)
{
    SMC->WAKEUP = ((SMC->WAKEUP & ~SMC_WAKEUP_LP_WAKEUP_POL2_MASK) | SMC_WAKEUP_LP_WAKEUP_POL2(u32Value));
}

/**
 * @brief Get the value of LP_WAKEUP_POL3.
 *
 * @return uint32_t the value of LP_WAKEUP_POL3.
 */
LOCAL_INLINE uint32_t SMC_HWA_GetLP_WAKEUP_POL3(void)
{
    return ((SMC->WAKEUP & SMC_WAKEUP_LP_WAKEUP_POL3_MASK) >> SMC_WAKEUP_LP_WAKEUP_POL3_SHIFT);
}

/**
 * @brief Set LP_WAKEUP_POL3.
 *
 * @param uint32_t u32Value LP_WAKEUP_POL3 value.
 */
LOCAL_INLINE void SMC_HWA_SetLP_WAKEUP_POL3(uint32_t u32Value)
{
    SMC->WAKEUP = ((SMC->WAKEUP & ~SMC_WAKEUP_LP_WAKEUP_POL3_MASK) | SMC_WAKEUP_LP_WAKEUP_POL3(u32Value));
}

/**
 * @brief Get the value of LP_WAKEUP_POL4.
 *
 * @return uint32_t the value of LP_WAKEUP_POL4.
 */
LOCAL_INLINE uint32_t SMC_HWA_GetLP_WAKEUP_POL4(void)
{
    return ((SMC->WAKEUP & SMC_WAKEUP_LP_WAKEUP_POL4_MASK) >> SMC_WAKEUP_LP_WAKEUP_POL4_SHIFT);
}

/**
 * @brief Set LP_WAKEUP_POL4.
 *
 * @param uint32_t u32Value LP_WAKEUP_POL4 value.
 */
LOCAL_INLINE void SMC_HWA_SetLP_WAKEUP_POL4(uint32_t u32Value)
{
    SMC->WAKEUP = ((SMC->WAKEUP & ~SMC_WAKEUP_LP_WAKEUP_POL4_MASK) | SMC_WAKEUP_LP_WAKEUP_POL4(u32Value));
}

/**
 * @brief Get IOLOCK register
 *
 * @return uint32 register value
 */
LOCAL_INLINE uint32 SMC_HWA_GetIolockReg(void)
{
    return SMC->IOLOCK;
}

/**
 * @brief Set IOLOCK register
 *
 * @param u32Data set value
 */
LOCAL_INLINE void SMC_HWA_SetIolockReg(uint32_t u32Data)
{
    SMC->IOLOCK = u32Data;
}

/**
 * @brief Get the value of IOLOCK_CTRL0.
 *
 * @return uint32_t the value of IOLOCK_CTRL0.
 */
LOCAL_INLINE uint32_t SMC_HWA_GetIOLOCK_CTRL0(void)
{
    return ((SMC->IOLOCK & SMC_IOLOCK_IOLOCK_CTRL0_MASK) >> SMC_IOLOCK_IOLOCK_CTRL0_SHIFT);
}

/**
 * @brief Set IOLOCK_CTRL0.
 *
 * @param uint32_t u8Value IOLOCK_CTRL0 value.
 */
LOCAL_INLINE void SMC_HWA_SetIOLOCK_CTRL0(uint32_t u8Value)
{
    SMC->IOLOCK = ((SMC->IOLOCK & ~SMC_IOLOCK_IOLOCK_CTRL0_MASK) | SMC_IOLOCK_IOLOCK_CTRL0(u8Value));
}

/**
 * @brief Get the value of IOLOCK_CTRL1.
 *
 * @return uint32_t the value of IOLOCK_CTRL1.
 */
LOCAL_INLINE uint32_t SMC_HWA_GetIOLOCK_CTRL1(void)
{
    return ((SMC->IOLOCK & SMC_IOLOCK_IOLOCK_CTRL1_MASK) >> SMC_IOLOCK_IOLOCK_CTRL1_SHIFT);
}

/**
 * @brief Set IOLOCK_CTRL1.
 *
 * @param uint32_t u8Value IOLOCK_CTRL1 value.
 */
LOCAL_INLINE void SMC_HWA_SetIOLOCK_CTRL1(uint32_t u8Value)
{
    SMC->IOLOCK = ((SMC->IOLOCK & ~SMC_IOLOCK_IOLOCK_CTRL1_MASK) | SMC_IOLOCK_IOLOCK_CTRL1(u8Value));
}

/**
 * @brief Get the value of IOLOCK_CTRL2.
 *
 * @return uint32_t the value of IOLOCK_CTRL2.
 */
LOCAL_INLINE uint32_t SMC_HWA_GetIOLOCK_CTRL2(void)
{
    return ((SMC->IOLOCK & SMC_IOLOCK_IOLOCK_CTRL2_MASK) >> SMC_IOLOCK_IOLOCK_CTRL2_SHIFT);
}

/**
 * @brief Set IOLOCK_CTRL2.
 *
 * @param uint32_t u32Value IOLOCK_CTRL2 value.
 */
LOCAL_INLINE void SMC_HWA_SetIOLOCK_CTRL2(uint32_t u32Value)
{
    SMC->IOLOCK = ((SMC->IOLOCK & ~SMC_IOLOCK_IOLOCK_CTRL2_MASK) | SMC_IOLOCK_IOLOCK_CTRL2(u32Value));
}

/**
 * @brief Get the value of IOLOCK_CTRL3.
 *
 * @return uint32_t the value of IOLOCK_CTRL3.
 */
LOCAL_INLINE uint32_t SMC_HWA_GetIOLOCK_CTRL3(void)
{
    return ((SMC->IOLOCK & SMC_IOLOCK_IOLOCK_CTRL3_MASK) >> SMC_IOLOCK_IOLOCK_CTRL3_SHIFT);
}

/**
 * @brief Set IOLOCK_CTRL3.
 *
 * @param uint32_t u32Value IOLOCK_CTRL3 value.
 */
LOCAL_INLINE void SMC_HWA_SetIOLOCK_CTRL3(uint32_t u32Value)
{
    SMC->IOLOCK = ((SMC->IOLOCK & ~SMC_IOLOCK_IOLOCK_CTRL3_MASK) | SMC_IOLOCK_IOLOCK_CTRL3(u32Value));
}

/**
 * @brief Get the value of IOLOCK_CTRL4.
 *
 * @return uint32_t the value of IOLOCK_CTRL4.
 */
LOCAL_INLINE uint32_t SMC_HWA_GetIOLOCK_CTRL4(void)
{
    return ((SMC->IOLOCK & SMC_IOLOCK_IOLOCK_CTRL4_MASK) >> SMC_IOLOCK_IOLOCK_CTRL4_SHIFT);
}

/**
 * @brief Set IOLOCK_CTRL4.
 *
 * @param uint32_t u32Value IOLOCK_CTRL4 value.
 */
LOCAL_INLINE void SMC_HWA_SetIOLOCK_CTRL4(uint32_t u32Value)
{
    SMC->IOLOCK = ((SMC->IOLOCK & ~SMC_IOLOCK_IOLOCK_CTRL4_MASK) | SMC_IOLOCK_IOLOCK_CTRL4(u32Value));
}

/**
 * @brief Get the value of RETEN.
 *
 * @return uint16_t the value of RETEN.
 */
LOCAL_INLINE uint16_t SMC_HWA_GetRETEN(void)
{
    return ((SMC->RAMRET & SMC_RAMRET_RETEN_MASK) >> SMC_RAMRET_RETEN_SHIFT);
}

/**
 * @brief Set RETEN.
 *
 * @param uint16_t u16Value RETEN value.
 */
LOCAL_INLINE void SMC_HWA_SetRETEN(uint16_t u16Value)
{
    SMC->RAMRET = ((SMC->RAMRET & ~SMC_RAMRET_RETEN_MASK) | SMC_RAMRET_RETEN(u16Value));
}

/**
 * @brief Set PGCTRL register
 *
 * @param u32Data set value
 */
LOCAL_INLINE void SMC_HWA_SetPgctrlReg(uint32_t u32Data)
{
    SMC->PGCTRL = u32Data;
}

/**
 * @brief Get the value of PG_LOCK_EN.
 *
 * @return uint32_t the value of PG_LOCK_EN.
 */
LOCAL_INLINE uint32_t SMC_HWA_GetPG_LOCK_EN(void)
{
    return ((SMC->PGCTRL & SMC_PGCTRL_PG_LOCK_EN_MASK) >> SMC_PGCTRL_PG_LOCK_EN_SHIFT);
}

/**
 * @brief Set PG_LOCK_EN.
 *
 * @param uint32_t u32Value PG_LOCK_EN value.
 */
LOCAL_INLINE void SMC_HWA_SetPG_LOCK_EN(uint32_t u32Value)
{
    SMC->PGCTRL = ((SMC->PGCTRL & ~SMC_PGCTRL_PG_LOCK_EN_MASK) | SMC_PGCTRL_PG_LOCK_EN(u32Value));
}

/**
 * @brief Get the value of PG_LOCK_SEL.
 *
 * @return uint32_t the value of PG_LOCK_SEL.
 */
LOCAL_INLINE uint32_t SMC_HWA_GetPG_LOCK_SEL(void)
{
    return ((SMC->PGCTRL & SMC_PGCTRL_PG_LOCK_SEL_MASK) >> SMC_PGCTRL_PG_LOCK_SEL_SHIFT);
}

/**
 * @brief Set PG_LOCK_SEL.
 *
 * @param uint32_t u32Value PG_LOCK_SEL value.
 */
LOCAL_INLINE void SMC_HWA_SetPG_LOCK_SEL(uint32_t u32Value)
{
    SMC->PGCTRL = ((SMC->PGCTRL & ~SMC_PGCTRL_PG_LOCK_SEL_MASK) | SMC_PGCTRL_PG_LOCK_SEL(u32Value));
}

/**
 * @brief Get the value of PG_POL.
 *
 * @return uint32_t the value of PG_POL.
 */
LOCAL_INLINE uint32_t SMC_HWA_GetPG_POL(void)
{
    return ((SMC->PGCTRL & SMC_PGCTRL_PG_POL_MASK) >> SMC_PGCTRL_PG_POL_SHIFT);
}

/**
 * @brief Set PG_POL.
 *
 * @param uint32_t u32Value PG_POL value.
 */
LOCAL_INLINE void SMC_HWA_SetPG_POL(uint32_t u32Value)
{
    SMC->PGCTRL = ((SMC->PGCTRL & ~SMC_PGCTRL_PG_POL_MASK) | SMC_PGCTRL_PG_POL(u32Value));
}

/**
 * @brief Get the value of PG_EN.
 *
 * @return uint32_t the value of PG_EN.
 */
LOCAL_INLINE uint32_t SMC_HWA_GetPG_EN(void)
{
    return ((SMC->PGCTRL & SMC_PGCTRL_PG_EN_MASK) >> SMC_PGCTRL_PG_EN_SHIFT);
}

/**
 * @brief Set PG_EN.
 *
 * @param uint32_t u32Value PG_EN value.
 */
LOCAL_INLINE void SMC_HWA_SetPG_EN(uint32_t u32Value)
{
    SMC->PGCTRL = ((SMC->PGCTRL & ~SMC_PGCTRL_PG_EN_MASK) | SMC_PGCTRL_PG_EN(u32Value));
}

/**
 * @brief Get the value of AON32KCLKSEL.
 *
 * @return uint32_t the value of AON32KCLKSEL.
 */
LOCAL_INLINE uint32_t SMC_HWA_GetAON32KCLKSEL(void)
{
    return ((SMC->AONCLKSR & SMC_AONCLKSR_AON32KCLKSEL_MASK) >> SMC_AONCLKSR_AON32KCLKSEL_SHIFT);
}

/**
 * @brief Set AON32KCLKSEL.
 *
 * @param uint32_t u32Value AON32KCLKSEL value.
 */
LOCAL_INLINE void SMC_HWA_SetAON32KCLKSEL(uint32_t u32Value)
{
    SMC->AONCLKSR = ((SMC->AONCLKSR & ~SMC_AONCLKSR_AON32KCLKSEL_MASK) | SMC_AONCLKSR_AON32KCLKSEL(u32Value));
}

/**
 * @brief Get the value of RTCCLKSEL.
 *
 * @return uint32_t the value of RTCCLKSEL.
 */
LOCAL_INLINE uint32_t SMC_HWA_GetRTCCLKSEL(void)
{
    return ((SMC->AONCLKSR & SMC_AONCLKSR_RTCCLKSEL_MASK) >> SMC_AONCLKSR_RTCCLKSEL_SHIFT);
}

/**
 * @brief Set RTCCLKSEL.
 *
 * @param uint32_t u32Value RTCCLKSEL value.
 */
LOCAL_INLINE void SMC_HWA_SetRTCCLKSEL(uint32_t u32Value)
{
    SMC->AONCLKSR = ((SMC->AONCLKSR & ~SMC_AONCLKSR_RTCCLKSEL_MASK) | SMC_AONCLKSR_RTCCLKSEL(u32Value));
}

/**
 * @brief Get the value of AONCLKSR.
 *
 * @return uint32_t the value of AONCLKSR.
 */
LOCAL_INLINE uint32_t SMC_HWA_GetAONCLKSR(void)
{
    return ((SMC->AONCLKSR & SMC_AONCLKSR_AONCLKSEL_MASK) >> SMC_AONCLKSR_AONCLKSEL_SHIFT);
}

/**
 * @brief Get the value of SIRCDIV32KEN.
 *
 * @param SMC the base address of the SMC instance.

 * @return uint32_t the value of SIRCDIV32KEN.
 */
LOCAL_INLINE uint32_t SMC_HWA_GetSIRCDIV32KEN(void)
{
    return ((SMC->AONCLKSR & SMC_AONCLKSR_SIRCDIV32KEN_MASK) >> SMC_AONCLKSR_SIRCDIV32KEN_SHIFT);
}

/**
 * @brief Set SIRCDIV32KEN.
 *
 * @param uint32_t u32Value SIRCDIV32KEN value.
 */
LOCAL_INLINE void SMC_HWA_SetSIRCDIV32KEN(uint32_t u32Value)
{
    SMC->AONCLKSR = ((SMC->AONCLKSR & ~SMC_AONCLKSR_SIRCDIV32KEN_MASK) | SMC_AONCLKSR_SIRCDIV32KEN(u32Value));
}

/**
 * @brief Get the value of AON1KCLKEN.
 * 
 * @return uint32_t the value of AON1KCLKEN.
 */
LOCAL_INLINE uint32_t SMC_HWA_GetAON1KCLKEN(void)
{
    return ((SMC->AONCLKSR & SMC_AONCLKSR_AON1KCLKEN_MASK) >> SMC_AONCLKSR_AON1KCLKEN_SHIFT);
}

/**
 * @brief Set AON1KCLKEN.
 *
 * @param uint32_t u32Value AON1KCLKEN value.
 */
LOCAL_INLINE void SMC_HWA_SetAON1KCLKEN(uint32_t u32Value)
{
    SMC->AONCLKSR = ((SMC->AONCLKSR & ~SMC_AONCLKSR_AON1KCLKEN_MASK) | SMC_AONCLKSR_AON1KCLKEN(u32Value));
}

/**
 * @brief Get the value of LOCK.
 *
 * @return uint32_t the value of LOCK.
 */
LOCAL_INLINE uint32_t SMC_HWA_GetAONCLKSRLOCK(void)
{
    return ((SMC->AONCLKSR & SMC_AONCLKSR_LOCK_MASK) >> SMC_AONCLKSR_LOCK_SHIFT);
}

/**
 * @brief Set LOCK.
 *
 * @param uint32_t u32Value LOCK value.
 */
LOCAL_INLINE void SMC_HWA_SetAONCLKSRLOCK(uint32_t u32Value)
{
    SMC->AONCLKSR = ((SMC->AONCLKSR & ~SMC_AONCLKSR_LOCK_MASK) | SMC_AONCLKSR_LOCK(u32Value));
}

/**
 * @brief Set SMC_AON32KCLK source clock
 *
 * @param SMC_AON32KClkSrcType SMC_AON32KCLK source type
 */
LOCAL_INLINE void SMC_HWA_SetAON32kClkSrc(SMC_AON32KClkSrcType eClkSrcType)
{
    uint32_t u32RegVal = SMC->AONCLKSR;
    SMC->AONCLKSR = ((u32RegVal & (~(uint32_t)SMC_AONCLKSR_AON32KCLKSEL_MASK)) | SMC_AONCLKSR_AON32KCLKSEL(eClkSrcType));
}

/**
 * @brief Set SMC_RTCCLK source clock
 *
 * @param SMC_RTCClkSrcType SMC_RTCCLK source type
 */
LOCAL_INLINE void SMC_HWA_SetRTCClkSrc(SMC_RTCClkSrcType eClkSrcType)
{
    uint32_t u32RegVal = SMC->AONCLKSR;
    SMC->AONCLKSR = ((u32RegVal & (~(uint32_t)SMC_AONCLKSR_RTCCLKSEL_MASK)) | SMC_AONCLKSR_RTCCLKSEL(eClkSrcType));
}

/**
 * @brief Set SMC_AONCLK source clock
 *
 * @param SMC_AONClkSrcType SMC_AONCLK source type
 */
LOCAL_INLINE void SMC_HWA_SetAONClkSrc(SMC_AONClkSrcType eClkSrcType)
{
    uint32_t u32RegVal = SMC->AONCLKSR;
    SMC->AONCLKSR = ((u32RegVal & (~(uint32_t)SMC_AONCLKSR_AONCLKSEL_MASK)) | SMC_AONCLKSR_AONCLKSEL(eClkSrcType));
}

/**
 * @brief Get AONCLKSR register status
 *
 * @return AONCLKSR register status
 */
LOCAL_INLINE uint32_t SMC_HWA_Get_AONCLKSR(void)
{
    return SMC->AONCLKSR;
}

/**
 * @brief Get the value of RPM_EXIT_CNT.
 *
 * @return uint16_t the value of RPM_EXIT_CNT.
 */
LOCAL_INLINE uint16_t SMC_HWA_GetRPM_EXIT_CNT(void)
{
    return ((SMC->PCU_CTRL & SMC_PCU_CTRL_RPM_EXIT_CNT_MASK) >> SMC_PCU_CTRL_RPM_EXIT_CNT_SHIFT);
}

/**
 * @brief Set RPM_EXIT_CNT.
 *
 * @param uint16_t u8Value RPM_EXIT_CNT value.
 */
LOCAL_INLINE void SMC_HWA_SetRPM_EXIT_CNT(uint16_t u16Value)
{
    SMC->PCU_CTRL = ((SMC->PCU_CTRL & ~SMC_PCU_CTRL_RPM_EXIT_CNT_MASK) | SMC_PCU_CTRL_RPM_EXIT_CNT(u16Value));
}

/**
 * @brief Get the value of LOCK.
 * 
 * @return uint32_t the value of LOCK.
 */
LOCAL_INLINE uint32_t SMC_HWA_GetPCULOCK(void)
{
    return ((SMC->PCU_CTRL & SMC_PCU_CTRL_LOCK_MASK) >> SMC_PCU_CTRL_LOCK_SHIFT);
}

/**
 * @brief Set LOCK.
 *
 * @param uint32_t u8Value LOCK value.
 */
LOCAL_INLINE void SMC_HWA_SetPCULOCK(uint32_t u32Value)
{
    SMC->PCU_CTRL = ((SMC->PCU_CTRL & ~SMC_PCU_CTRL_LOCK_MASK) | SMC_PCU_CTRL_LOCK(u32Value));
}

/**
 * @brief Get the value of PAD_ISO_HOLD.
 *
 * @return uint32_t the value of PAD_ISO_HOLD.
 */
LOCAL_INLINE uint32_t SMC_HWA_GetPAD_ISO_HOLD(void)
{
    return ((SMC->ISO_CTRL & SMC_ISO_CTRL_PAD_ISO_HOLD_MASK) >> SMC_ISO_CTRL_PAD_ISO_HOLD_SHIFT);
}

/**
 * @brief Set PAD_ISO_HOLD.
 *
 * @param uint32_t u32Value PAD_ISO_HOLD value.
 */
LOCAL_INLINE void SMC_HWA_SetPAD_ISO_HOLD(uint32_t u32Value)
{
    SMC->ISO_CTRL = ((SMC->ISO_CTRL & ~SMC_ISO_CTRL_PAD_ISO_HOLD_MASK) | SMC_ISO_CTRL_PAD_ISO_HOLD(u32Value));
}

/**
 * @brief Get the value of PAD_ISO_HOLD_CLR.
 * 
 * @return uint32_t the value of PAD_ISO_HOLD_CLR.
 */
LOCAL_INLINE uint32_t SMC_HWA_GetPAD_ISO_HOLD_CLR(void)
{
    return ((SMC->ISO_CTRL & SMC_ISO_CTRL_PAD_ISO_HOLD_CLR_MASK) >> SMC_ISO_CTRL_PAD_ISO_HOLD_CLR_SHIFT);
}

/**
 * @brief Set PAD_ISO_HOLD_CLR.
 *
 * @param uint32_t u32Value PAD_ISO_HOLD_CLR value.
 */
LOCAL_INLINE void SMC_HWA_SetPAD_ISO_HOLD_CLR(uint32_t u32Value)
{
    SMC->ISO_CTRL = ((SMC->ISO_CTRL & ~SMC_ISO_CTRL_PAD_ISO_HOLD_CLR_MASK) | SMC_ISO_CTRL_PAD_ISO_HOLD_CLR(u32Value));
}

/**
 * @brief Get the value of LOCK.
 *
 * @return uint32_t the value of LOCK.
 */
LOCAL_INLINE uint32_t SMC_HWA_GetISOLOCK(void)
{
    return ((SMC->ISO_CTRL & SMC_ISO_CTRL_LOCK_MASK) >> SMC_ISO_CTRL_LOCK_SHIFT);
}

/**
 * @brief Set LOCK.
 *
 * @param uint32_t u32Value LOCK value.
 */
LOCAL_INLINE void SMC_HWA_SetISOLOCK(uint32_t u32Value)
{
    SMC->ISO_CTRL = ((SMC->ISO_CTRL & ~SMC_ISO_CTRL_LOCK_MASK) | SMC_ISO_CTRL_LOCK(u32Value));
}

#if SMC_SCG_WAKEUP_CONFIG_SUPPORT
/**
 * @brief Get the value of SCG_WAKEUP_CFG.
 *
 * @return uint32_t the value of SCG_WAKEUP_CFG.
 */
LOCAL_INLINE uint32_t SMC_HWA_GetSCG_WAKEUP_CFG(void)
{
    return ((SMC->SCG_WAKEUP & SMC_SCG_WAKEUP_SCG_WAKEUP_CFG_MASK) >> SMC_SCG_WAKEUP_SCG_WAKEUP_CFG_SHIFT);
}

/**
 * @brief Set SCG_WAKEUP_CFG.
 *
 * @param uint32_t u32Value SCG_WAKEUP_CFG value.
 */
LOCAL_INLINE void SMC_HWA_SetSCG_WAKEUP_CFG(uint32_t u32Value)
{
    SMC->SCG_WAKEUP = ((SMC->SCG_WAKEUP & ~SMC_SCG_WAKEUP_SCG_WAKEUP_CFG_MASK) | SMC_SCG_WAKEUP_SCG_WAKEUP_CFG(u32Value));
}

/**
 * @brief Get the value of SCG_POL.
 *
 * @return uint32_t the value of SCG_POL.
 */
LOCAL_INLINE uint32_t SMC_HWA_GetSCG_POL(void)
{
    return ((SMC->SCG_WAKEUP & SMC_SCG_WAKEUP_SCG_POL_MASK) >> SMC_SCG_WAKEUP_SCG_POL_SHIFT);
}

/**
 * @brief Set SCG_POL.
 *
 * @param uint32_t u32Value SCG_POL value.
 */
LOCAL_INLINE void SMC_HWA_SetSCG_POL(uint32_t u32Value)
{
    SMC->SCG_WAKEUP = ((SMC->SCG_WAKEUP & ~SMC_SCG_WAKEUP_SCG_POL_MASK) | SMC_SCG_WAKEUP_SCG_POL(u32Value));
}

/**
 * @brief Get the value of SCG_TRGSEL.
 *
 * @return uint32_t the value of SCG_TRGSEL.
 */
LOCAL_INLINE uint32_t SMC_HWA_GetSCG_TRGSEL(void)
{
    return ((SMC->SCG_WAKEUP & SMC_SCG_WAKEUP_SCG_TRGSEL_MASK) >> SMC_SCG_WAKEUP_SCG_TRGSEL_SHIFT);
}

/**
 * @brief Set SCG_TRGSEL.
 *
 * @param uint32_t u32Value SCG_TRGSEL value.
 */
LOCAL_INLINE void SMC_HWA_SetSCG_TRGSEL(uint32_t u32Value)
{
    SMC->SCG_WAKEUP = ((SMC->SCG_WAKEUP & ~SMC_SCG_WAKEUP_SCG_TRGSEL_MASK) | SMC_SCG_WAKEUP_SCG_TRGSEL(u32Value));
}

/**
 * @brief Get the value of LOCK.
 *
 * @return uint32_t the value of LOCK.
 */
LOCAL_INLINE uint32_t SMC_HWA_GetSCG_WAKEUPLOCK(void)
{
    return ((SMC->SCG_WAKEUP & SMC_SCG_WAKEUP_LOCK_MASK) >> SMC_SCG_WAKEUP_LOCK_SHIFT);
}

/**
 * @brief Set LOCK.
 *
 * @param uint32_t u32Value LOCK value.
 */
LOCAL_INLINE void SMC_HWA_SetSCG_WAKEUPLOCK(uint32_t u32Value)
{
    SMC->SCG_WAKEUP = ((SMC->SCG_WAKEUP & ~SMC_SCG_WAKEUP_LOCK_MASK) | SMC_SCG_WAKEUP_LOCK(u32Value));
}

/**
 * @brief Set SCG Wakeup config register.
 *
 * @param uint32_t u32Value scg wakeup register value.
 */
LOCAL_INLINE void SMC_HWA_SetSCG_WAKEUP_REG(uint32_t u32Value)
{
    SMC->SCG_WAKEUP = u32Value & SMC_SCG_WAKEUP_MASK;
}
#endif /* SMC_SCG_WAKEUP_CONFIG_SUPPORT */

/**
 * @brief Get the value of GPR_CCM_STANDBY_ABORT_DIS.
 *
 * @return uint32_t the value of GPR_CCM_STANDBY_ABORT_DIS.
 */
LOCAL_INLINE uint32_t SMC_HWA_GetGPR_CCM_STANDBY_ABORT_DIS(void)
{
    return ((SMC->CCM_LPCTRL & SMC_CCM_LPCTRL_GPR_CCM_STANDBY_ABORT_DIS_MASK) >> SMC_CCM_LPCTRL_GPR_CCM_STANDBY_ABORT_DIS_SHIFT);
}

/**
 * @brief Set GPR_CCM_STANDBY_ABORT_DIS.
 *
 * @param uint32_t u32Value GPR_CCM_STANDBY_ABORT_DIS value.
 */
LOCAL_INLINE void SMC_HWA_SetGPR_CCM_STANDBY_ABORT_DIS(uint32_t u32Value)
{
    SMC->CCM_LPCTRL = ((SMC->CCM_LPCTRL & ~SMC_CCM_LPCTRL_GPR_CCM_STANDBY_ABORT_DIS_MASK) | SMC_CCM_LPCTRL_GPR_CCM_STANDBY_ABORT_DIS(u32Value));
}

/**
 * @brief Get the value of LOCK.
 *
 * @return uint32_t the value of LOCK.
 */
LOCAL_INLINE uint32_t SMC_HWA_GetCCM_LPCTRLLOCK(void)
{
    return ((SMC->CCM_LPCTRL & SMC_CCM_LPCTRL_LOCK_MASK) >> SMC_CCM_LPCTRL_LOCK_SHIFT);
}

/**
 * @brief Set LOCK.
 *
 * @param uint32_t u32Value LOCK value.
 */
LOCAL_INLINE void SMC_HWA_SetCCM_LPCTRLLOCK(uint32_t u32Value)
{
    SMC->CCM_LPCTRL = ((SMC->CCM_LPCTRL & ~SMC_CCM_LPCTRL_LOCK_MASK) | SMC_CCM_LPCTRL_LOCK(u32Value));
}

/**
 * @brief Get the value of BANK0.
 *
 * @return uint32_t the value of BANK.
 */
LOCAL_INLINE uint32_t SMC_HWA_GetBANK0(void)
{
    return SMC->SW_BANK0;
}

/**
 * @brief Set BANK0.
 *
 * @param uint32_t u32Value BANK value.
 */
LOCAL_INLINE void SMC_HWA_SetBANK0(uint32_t u32Value)
{
    SMC->SW_BANK0 = u32Value;
}

/**
 * @brief Get the value of BANK1.
 *
 * @return uint32_t the value of BANK.
 */
LOCAL_INLINE uint32_t SMC_HWA_GetBANK1(void)
{
    return SMC->SW_BANK1;
}

/**
 * @brief Set BANK1.
 *
 * @param uint32_t u32Value BANK value.
 */
LOCAL_INLINE void SMC_HWA_SetBANK1(uint32_t u32Value)
{
    SMC->SW_BANK1 = u32Value;
}

/**
 * @brief Get the value of SGCMP_EN.
 *
 * @return uint32_t the value of SGCMP_EN.
 */
LOCAL_INLINE uint32_t SMC_HWA_ADCCFG0_GetSGCMP_EN(uint8_t Index)
{
    return ((SMC->ADC[Index].CFG0 & SMC_ADC_CFG0_SGCMP_EN_MASK) >> SMC_ADC_CFG0_SGCMP_EN_SHIFT);
}

/**
 * @brief Set SGCMP_EN.
 *
 * @param uint32_t u32Value SGCMP_EN value.
 */
LOCAL_INLINE void SMC_HWA_ADCCFG0_SetSGCMP_EN(uint8_t Index, uint32_t u32Value)
{
    SMC->ADC[Index].CFG0 = ((SMC->ADC[Index].CFG0 & ~SMC_ADC_CFG0_SGCMP_EN_MASK) | SMC_ADC_CFG0_SGCMP_EN(u32Value));
}

/**
 * @brief Get the value of SGCMP_IEN.
 *
 * @return uint32_t the value of SGCMP_IEN.
 */
LOCAL_INLINE uint32_t SMC_HWA_ADCCFG0_GetSGCMP_IEN(uint8_t Index)
{
    return ((SMC->ADC[Index].CFG0 & SMC_ADC_CFG0_SGCMP_IEN_MASK) >> SMC_ADC_CFG0_SGCMP_IEN_SHIFT);
}

/**
 * @brief Set SGCMP_IEN.
 *
 * @param uint32_t u32Value SGCMP_IEN value.
 */
LOCAL_INLINE void SMC_HWA_ADCCFG0_SetSGCMP_IEN(uint8_t Index, uint32_t u32Value)
{
    SMC->ADC[Index].CFG0 = ((SMC->ADC[Index].CFG0 & ~SMC_ADC_CFG0_SGCMP_IEN_MASK) | SMC_ADC_CFG0_SGCMP_IEN(u32Value));
}

/**
 * @brief Set SGCMP_FLAG_CLR.
 *
 */
LOCAL_INLINE void SMC_HWA_ADCCFG0_CLRSGCMPFLAG(uint8_t Index)
{
    SMC->ADC[Index].CFG0 |= SMC_ADC_CFG0_SGCMP_FLAG_CLR_MASK;
}

/**
 * @brief Get the value of SGCMP_REF_SEL.
 *
 * @return uint32_t the value of SGCMP_REF_SEL.
 */
LOCAL_INLINE uint32_t SMC_HWA_ADCCFG0_GetSGCMPREFSEL(uint8_t Index)
{
    return ((SMC->ADC[Index].CFG0 & SMC_ADC_CFG0_SGCMP_REF_SEL_MASK) >> SMC_ADC_CFG0_SGCMP_REF_SEL_SHIFT);
}

/**
 * @brief Set SGCMP_REF_SEL.
 *
 * @param uint32_t u32Value SGCMP_REF_SEL value.
 */
LOCAL_INLINE void SMC_HWA_ADCCFG0_SetSGCMP_REF_SEL(uint8_t Index, uint32_t u32Value)
{
    SMC->ADC[Index].CFG0 = ((SMC->ADC[Index].CFG0 & ~SMC_ADC_CFG0_SGCMP_REF_SEL_MASK) | SMC_ADC_CFG0_SGCMP_REF_SEL(u32Value));
}

/**
 * @brief Get ADC_CFG0.
 *
 * @return uint32_t the value of ADC_CFG0.
 */
LOCAL_INLINE uint32_t SMC_HWA_GetADCCFG0(uint8_t Index)
{
    return SMC->ADC[Index].CFG0;
}

/**
 * @brief Set ADC_CFG0.
 *
 * @param uint32_t u32Value ADC_CFG0 value.
 */
LOCAL_INLINE void SMC_HWA_SetADCCFG0(uint8_t Index, uint32_t u32Value)
{
    SMC->ADC[Index].CFG0 = u32Value;
}

/**
 * @brief Get the value of SGCMP_ACT_SEL.
 *
 * @return uint32_t the value of SGCMP_ACT_SEL.
 */
LOCAL_INLINE uint32_t SMC_HWA_ADCCFG1_GetSGCMP_ACT_SEL(uint8_t Index)
{
    return ((SMC->ADC[Index].CFG1 & SMC_ADC_CFG1_SGCMP_ACT_SEL_MASK) >> SMC_ADC_CFG1_SGCMP_ACT_SEL_SHIFT);
}

/**
 * @brief Set SGCMP_ACT_SEL.
 *
 * @param uint32_t u32Value SGCMP_ACT_SEL value.
 */
LOCAL_INLINE void SMC_HWA_ADCCFG1_SetSGCMP_ACT_SEL(uint8_t Index, uint32_t u32Value)
{
    SMC->ADC[Index].CFG1 = ((SMC->ADC[Index].CFG1 & ~SMC_ADC_CFG1_SGCMP_ACT_SEL_MASK) | SMC_ADC_CFG1_SGCMP_ACT_SEL(u32Value));
}

/**
 * @brief Get ADC_CFG1.
 *
 * @return uint32_t the value of ADC_CFG1.
 */
LOCAL_INLINE uint32_t SMC_HWA_GetADCCFG1(uint8_t Index)
{
    return SMC->ADC[Index].CFG1;
}

/**
 * @brief Set ADC_CFG1.
 *
 * @param uint32_t u32Value ADC_CFG1 value.
 */
LOCAL_INLINE void SMC_HWA_SetADCCFG1(uint8_t Index, uint32_t u32Value)
{
    SMC->ADC[Index].CFG1 = u32Value;
}

/**
 * @brief Get the value of SGCMP_ON.
 *
 * @return uint32_t the value of SGCMP_ON.
 */
LOCAL_INLINE uint32_t SMC_HWA_ADCRES_GetSGCMP_ON(uint8_t Index)
{
    return ((SMC->ADC[Index].RES & SMC_ADC_RES_SGCMP_ON_MASK) >> SMC_ADC_RES_SGCMP_ON_SHIFT);
}

/**
 * @brief Get the value of SGCMP_FLAG.
 *
 * @return uint32_t the value of SGCMP_FLAG.
 */
LOCAL_INLINE uint32_t SMC_HWA_ADCRES_GetSGCMP_FLAG(uint8_t Index)
{
    return ((SMC->ADC[Index].RES & SMC_ADC_RES_SGCMP_FLAG_MASK) >> SMC_ADC_RES_SGCMP_FLAG_SHIFT);
}

/**
 * @brief Get the value of SGCMP_RES.
 *
 * @return uint32_t the value of SGCMP_RES.
 */
LOCAL_INLINE uint32_t SMC_HWA_ADCRES_GetSGCMP_RES(uint8_t Index)
{
    return ((SMC->ADC[Index].RES & SMC_ADC_RES_SGCMP_RES_MASK) >> SMC_ADC_RES_SGCMP_RES_SHIFT);
}

/**
 * @brief Set clock out control register
 *
 * @param u32val the value to be set
 */
LOCAL_INLINE void SMC_HWA_Set_CLKOUT_CTRL(uint32_t u32val)
{
    SMC->CLKOUT_CTRL = u32val;
}

/**
 * @brief Get clock out control register
 *
 * @return Register status
 */
LOCAL_INLINE uint32_t SMC_HWA_Get_CLKOUT_CTRL(void)
{
    return SMC->CLKOUT_CTRL;
}

/**
 * @brief Enable SMC clock out
 *
 */
LOCAL_INLINE void SMC_HWA_EnableClockOut(void)
{
    SMC->CLKOUT_CTRL |= (uint32_t)SMC_CLKOUT_CTRL_EN_MASK;
}

/**
 * @brief Disable SMC clock out
 *
 */
LOCAL_INLINE void SMC_HWA_DisableClockOut(void)
{
    SMC->CLKOUT_CTRL &= ~(uint32_t)SMC_CLKOUT_CTRL_EN_MASK;
}

/**
 * @brief Get CLKOUT source Select
 *
 * @return SMC_ClockOutSrcType SMC clock out source
 */
LOCAL_INLINE SMC_ClockOutSrcType SMC_HWA_GetClkOutSel(void)
{
    uint32_t u32RegVal = (SMC->CLKOUT_CTRL & SMC_CLKOUT_CTRL_SEL_MASK) >> SMC_CLKOUT_CTRL_SEL_SHIFT;
    return (SMC_ClockOutSrcType)u32RegVal;
}

/**
 * @brief Get CLKOUT SMC clock out divider
 *
 * @return SMC_ClockOutDivType SMC clock out divider
 */
LOCAL_INLINE SMC_ClockOutDivType SMC_HWA_GetClkOutDiv(void)
{
    uint32_t u32RegVal = (SMC->CLKOUT_CTRL & SMC_CLKOUT_CTRL_DIV_MASK) >> SMC_CLKOUT_CTRL_DIV_SHIFT;
    return (SMC_ClockOutDivType)u32RegVal;
}

/**
 * @brief Set CLKOUTDIV
 *
 * @param eDivType SMC clock out devide ratio type
 */
LOCAL_INLINE void SMC_HWA_SetClkOutDiv(SMC_ClockOutDivType eDivType)
{
    uint32_t u32RegVal = SMC->CLKOUT_CTRL;
    SMC->CLKOUT_CTRL = ((u32RegVal & (~(uint32_t)SMC_CLKOUT_CTRL_DIV_MASK)) | SMC_CLKOUT_CTRL_DIV(eDivType));
}

/**
 * @brief Set CLKOUT Select
 *
 * @param eClkSrcType SMC clock out devide ratio type
 */
LOCAL_INLINE void SMC_HWA_SetClkOutSel(SMC_ClockOutSrcType eClkSrcType)
{
    uint32_t u32RegVal = SMC->CLKOUT_CTRL;
    SMC->CLKOUT_CTRL = ((u32RegVal & (~(uint32_t)SMC_CLKOUT_CTRL_SEL_MASK)) | SMC_CLKOUT_CTRL_SEL(eClkSrcType));
}

/**
 * @brief Lock SMC_CLKOUT_CTRL register
 *
 */
LOCAL_INLINE void SMC_HWA_LockCLKOUT_CTRL(void)
{
    SMC->CLKOUT_CTRL |= (uint32_t)SMC_CLKOUT_CTRL_LOCK_MASK;
}

/**
 * @brief Get SMC_CLKOUT_CTRL register lock status
 *
 * @return Lock status
 */
LOCAL_INLINE uint32_t SMC_HWA_CLKOUT_CTRL_GetLockStatus(void)
{
    return (SMC->CLKOUT_CTRL & (uint32_t)SMC_CLKOUT_CTRL_LOCK_MASK);
}
/** @}*/
#endif /* #if SMC_CLOCKCONFIG_SUPPORT */
#endif /* #if SMC_INSTANCE_COUNT > 0U */

#endif /* #ifndef _HWA_SMC_H_ */
