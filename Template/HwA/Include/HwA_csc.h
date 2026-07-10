/**
 * @file HwA_csc.h
 * @author flagchip
 * @brief Hardware access layer for CSC
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
   *   0.1.0      2023-12-15     Flagchip055   N/A          First version for FC7300
   *   2.0.0      2024-10-12     Flagchip055   N/A          Change version and release
   ******************************************************************************** */

#ifndef _HWA_CSC_H_
#define _HWA_CSC_H_

#include "device_header.h"

#if CSC0_INSTANCE_COUNT > 0U

/**
 * @defgroup HwA_csc HwA_csc
 * @ingroup module_driver_csc
 * @{
 */

/********* Local typedef ************/
/**
 * @brief CSC0 clock out divide ratio type
 *
 */
typedef enum
{
    CSC0_CLKOUT_DIV_BY1 = 0U,       /*!< Divided by 1 */
    CSC0_CLKOUT_DIV_BY2 = 1U,       /*!< Divided by 2 */
    CSC0_CLKOUT_DIV_BY3 = 2U,       /*!< Divided by 3 */
    CSC0_CLKOUT_DIV_BY4 = 3U,       /*!< Divided by 4 */
    CSC0_CLKOUT_DIV_BY5 = 4U,       /*!< Divided by 5 */
    CSC0_CLKOUT_DIV_BY6 = 5U,       /*!< Divided by 6 */
    CSC0_CLKOUT_DIV_BY7 = 6U,       /*!< Divided by 7 */
    CSC0_CLKOUT_DIV_BY8 = 7U        /*!< Divided by 8 */
} CSC0_ClockOutDivType;

/**
 * @brief CSC0 clock out source type
 *
 */
typedef enum
{
    CSC0_CLKOUT_SCG_CLKOUT    = 0U,  /*!< SCG CLKOUT */
    CSC0_CLKOUT_FOSC_DIVM_CLK = 2U,  /*!< FOSC DIVM CLK */
    CSC0_CLKOUT_SLOW_CLK      = 3U,  /*!< SLOW CLK */
    CSC0_CLKOUT_SIRC_DIVM_CLK = 4U,  /*!< SIRC DIVM CLK */
    CSC0_CLKOUT_PLL1_DIVM_CLK = 5U,  /*!< PLL1 DIVM CLK */
    CSC0_CLKOUT_FIRC_DIVM_CLK = 6U,  /*!< FIRC DIVM CLK */
    CSC0_CLKOUT_CORE_CLK      = 7U,  /*!< CORE CLK */
    CSC0_CLKOUT_PLL0_DIVM_CLK = 8U,  /*!< PLL0 DIVM CLK */
    CSC0_CLKOUT_BUS_CLK       = 9U,  /*!< BUS CLK */
    CSC0_CLKOUT_SIRC_128K_CLK = 10U, /*!< SIRC 128K CLK */
    CSC0_CLKOUT_AON_CLK       = 12U, /*!< AON CLK */
    CSC0_CLKOUT_RTC_CLK       = 14U  /*!< AON32K CLK */
} CSC0_ClockOutSrcType;

/**
 * @brief Data type for CSC0_AONCLKSR[32KAONCLKSEL], set AON32KCLK source clock
 *
 */
typedef enum
{
    CSC0_AON32K_SIRCDIV_32K_CLK = 1U,  /*!< CSC0_AONCLKSR[32KAONCLKSEL], SIRCDIV_32K */
    CSC0_AON32K_SOSC32K_CLK     = 2U,  /*!< CSC0_AONCLKSR[32KAONCLKSEL], SOSC32K */
    CSC0_AON32K_SIRC32K_CLK     = 3U   /*!< CSC0_AONCLKSR[32KAONCLKSEL], SIRC32K */
} CSC0_AON32KClkSrcType;

/**
 * @brief Data type for CSC0_RTCCLKSEL[RTCCLKSEL], set RTCCLK source clock
 *
 */
typedef enum
{
    CSC0_RTC_FOSCDIVL_CLK    = 0U,  /*!< CSC0_RTCCLKSEL[RTCCLKSEL], FOSC_DIVL */
    CSC0_RTC_SIRCDIV_32K_CLK = 1U,  /*!< CSC0_RTCCLKSEL[RTCCLKSEL], SIRC_DIV */
    CSC0_RTC_SOSC_CLK        = 2U,  /*!< CSC0_RTCCLKSEL[RTCCLKSEL], SOSC */
    CSC0_RTC_SIRC32K_CLK     = 3U   /*!< CSC0_RTCCLKSEL[RTCCLKSEL], SIRC_32K */
} CSC0_RTCClkSrcType;

/**
 * @brief Data type for CSC0_AONCLKSEL[AONCLKSEL], set AONCLK source clock
 *
 */
typedef enum
{
    CSC0_AON_SIRCDIV_128K_CLK = 0U,  /*!< CSC0_AONCLKSEL[AONCLKSEL], SIRCDIV_128K */
    CSC0_AON_SIRC32K_CLK      = 1U,  /*!< CSC0_AONCLKSEL[AONCLKSEL], SIRC32K */
    CSC0_AON_SIRCDIV_32K_CLK  = 2U,  /*!< CSC0_AONCLKSEL[AONCLKSEL], SIRCDIV_32K */
    CSC0_AON_SIRC32_1K_CLK    = 3U   /*!< CSC0_AONCLKSEL[AONCLKSEL], SIRC32_1K */
} CSC0_AONClkSrcType;

#endif /* #if CSC0_INSTANCE_COUNT > 0U */

/********* Local inline function ************/
/****** Operation on CSC0_xxxRegister0 ******/
#if CSC0_INSTANCE_COUNT > 0U
/**
 * @brief Set stop mode register 0
 *
 */
LOCAL_INLINE void CSC0_HWA_Set_STOP_MODER0(uint32_t u32val)
{
    CSC0->STOP_MODER0 = u32val;
}

/**
 * @brief Get stop mode register 0
 * @return Register status
 */
LOCAL_INLINE uint32_t CSC0_HWA_Get_STOP_MODER0(void)
{
    return CSC0->STOP_MODER0;
}

/**
 * @brief Set stop request register 0
 *
 */
LOCAL_INLINE void CSC0_HWA_Set_STOP_REQR0(uint32_t u32val)
{
    CSC0->STOP_REQR0 = u32val;
}

/**
 * @brief Get stop request register 0
 * @return Register status
 */
LOCAL_INLINE uint32_t CSC0_HWA_Get_STOP_REQR0(void)
{
    return CSC0->STOP_REQR0;
}

/**
 * @brief Get stop ack status in register 0
 *
 * @return Register ack status
 */
LOCAL_INLINE uint32_t CSC0_HWA_Get_STOP_ACKR0(void)
{
    return CSC0->STOP_ACKR0;
}

/****** Operation on CSC0_xxxRegister1 ******/
/**
 * @brief Set stop mode register 1
 *
 */
LOCAL_INLINE void CSC0_HWA_Set_STOP_MODER1(uint32_t u32val)
{
    CSC0->STOP_MODER1 = u32val;
}

/**
 * @brief Get stop mode register 1
 * @return Register status
 */
LOCAL_INLINE uint32_t CSC0_HWA_Get_STOP_MODER1(void)
{
    return CSC0->STOP_MODER1;
}

/**
 * @brief Set stop request register 1
 *
 */
LOCAL_INLINE void CSC0_HWA_Set_STOP_REQR1(uint32_t u32val)
{
    CSC0->STOP_REQR1 = u32val;
}

/**
 * @brief Get stop request register 1
 * @return Register status
 */
LOCAL_INLINE uint32_t CSC0_HWA_Get_STOP_REQR1(void)
{
    return CSC0->STOP_REQR1;
}

/**
 * @brief Get stop ack status in register 1
 *
 * @return Register ack status
 */
LOCAL_INLINE uint32_t CSC0_HWA_Get_STOP_ACKR1(void)
{
    return CSC0->STOP_ACKR1;
}

/****** Operation on CSC0_xxxRegister2 ******/
/**
 * @brief Set stop mode register 2
 *
 */
LOCAL_INLINE void CSC0_HWA_Set_STOP_MODER2(uint32_t u32val)
{
    CSC0->STOP_MODER2 = u32val;
}

/**
 * @brief Get stop mode register 2
 * @return Register status
 */
LOCAL_INLINE uint32_t CSC0_HWA_Get_STOP_MODER2(void)
{
    return CSC0->STOP_MODER2;
}

/**
 * @brief Set stop request register 2
 *
 */
LOCAL_INLINE void CSC0_HWA_Set_STOP_REQR2(uint32_t u32val)
{
    CSC0->STOP_REQR2 = u32val;
}

/**
 * @brief Get stop request register 2
 * @return Register status
 */
LOCAL_INLINE uint32_t CSC0_HWA_Get_STOP_REQR2(void)
{
    return CSC0->STOP_REQR2;
}

/**
 * @brief Get stop ack status in register 2
 *
 * @return Register ack status
 */
LOCAL_INLINE uint32_t CSC0_HWA_Get_STOP_ACKR2(void)
{
    return CSC0->STOP_ACKR2;
}

/**
 * @brief Set CCM0 configure register
 *
 */
LOCAL_INLINE void CSC0_HWA_Set_CCM0_CFG(uint32_t u32val)
{
    CSC0->CCM0_CFG = u32val;
}

/**
 * @brief Get  CCM0 configure
 * @return Register status
 */
LOCAL_INLINE uint32_t CSC0_HWA_Get_CCM0_CFG(void)
{
    return CSC0->CCM0_CFG;
}

/**
 * @brief Set SCG MAM stall request register
 *
 */
LOCAL_INLINE void CSC0_HWA_Set_SCG_MAM_STALL(uint32_t u32val)
{
    CSC0->SCG_MAM_STALL = u32val;
}

/**
 * @brief Get SCG MAM stall request register
 * @return Register status
 */
LOCAL_INLINE uint32_t CSC0_HWA_Get_SCG_MAM_STALL(void)
{
    return CSC0->SCG_MAM_STALL;
}

/**
 * @brief Set cpu0 software interrupt register
 *
 */
LOCAL_INLINE void CSC0_HWA_Set_CPU0_INT(uint32_t u32val)
{
    CSC0->CPU0_INT = u32val;
}

/**
 * @brief Get cpu0 software interrupt register
 * @return Register status
 */
LOCAL_INLINE uint32_t CSC0_HWA_Get_CPU0_INT(void)
{
    return CSC0->CPU0_INT;
}

/**
 * @brief Enable cpu0 software interrupt
 *
 */
LOCAL_INLINE void CSC0_HWA_EnableCpu0SWInterrupt(void)
{
    CSC0->CPU0_INT |= (uint32_t)CSC0_CPU0_INT_SW_INT_MASK;
}

/**
 * @brief Disable cpu0 software interrupt
 *
 */
LOCAL_INLINE void CSC0_HWA_DisableCpu0SWInterrupt(void)
{
    CSC0->CPU0_INT &= ~(uint32_t)CSC0_CPU0_INT_SW_INT_MASK;
}

#if CSC0_CLOCKCONFIG_SUPPORT
/**
 * @brief Set clock out control register
 *
 */
LOCAL_INLINE void CSC0_HWA_Set_CLKOUT_CTRL(uint32_t u32val)
{
    CSC0->CLKOUT_CTRL = u32val;
}

/**
 * @brief Get clock out control register
 * @return Register status
 */
LOCAL_INLINE uint32_t CSC0_HWA_Get_CLKOUT_CTRL(void)
{
    return CSC0->CLKOUT_CTRL;
}

/**
 * @brief Enable CSC0 clock out
 *
 */
LOCAL_INLINE void CSC0_HWA_EnableClockOut(void)
{
    CSC0->CLKOUT_CTRL |= (uint32_t)CSC0_CLKOUT_CTRL_CLKOUT_EN_MASK;
}

/**
 * @brief Disable CSC0 clock out
 *
 */
LOCAL_INLINE void CSC0_HWA_DisableClockOut(void)
{
    CSC0->CLKOUT_CTRL &= ~(uint32_t)CSC0_CLKOUT_CTRL_CLKOUT_EN_MASK;
}

/**
 * @brief Get CLKOUT source Select
 *
 * @return CSC0_ClockOutSrcType CSC0 clock out source
 */
LOCAL_INLINE CSC0_ClockOutSrcType CSC0_HWA_GetClkOutSel(void)
{
    uint32_t u32RegVal = (CSC0->CLKOUT_CTRL & CSC0_CLKOUT_CTRL_CLKOUT_SEL_MASK) >> CSC0_CLKOUT_CTRL_CLKOUT_SEL_SHIFT;
    return (CSC0_ClockOutSrcType)u32RegVal;
}

/**
 * @brief Get CLKOUT CSC0 clock out divider
 *
 * @return CSC0_ClockOutDivType CSC0 clock out divider
 */
LOCAL_INLINE CSC0_ClockOutDivType CSC0_HWA_GetClkOutDiv(void)
{
    uint32_t u32RegVal = (CSC0->CLKOUT_CTRL & CSC0_CLKOUT_CTRL_CLKOUT_DIV_MASK) >> CSC0_CLKOUT_CTRL_CLKOUT_DIV_SHIFT;
    return (CSC0_ClockOutDivType)u32RegVal;
}

/**
 * @brief Set CLKOUTDIV
 *
 * @param eDivType CSC0 clock out devide ratio type
 */
LOCAL_INLINE void CSC0_HWA_SetClkOutDiv(CSC0_ClockOutDivType eDivType)
{
    uint32_t u32RegVal = CSC0->CLKOUT_CTRL;
    CSC0->CLKOUT_CTRL = ((u32RegVal & (~(uint32_t)CSC0_CLKOUT_CTRL_CLKOUT_DIV_MASK)) | CSC0_CLKOUT_CTRL_CLKOUT_DIV(eDivType));
}

/**
 * @brief Set CLKOUT Select
 *
 * @param eClkSrcType CSC0 clock out devide ratio type
 */
LOCAL_INLINE void CSC0_HWA_SetClkOutSel(CSC0_ClockOutSrcType eClkSrcType)
{
    uint32_t u32RegVal = CSC0->CLKOUT_CTRL;
    CSC0->CLKOUT_CTRL = ((u32RegVal & (~(uint32_t)CSC0_CLKOUT_CTRL_CLKOUT_SEL_MASK)) | CSC0_CLKOUT_CTRL_CLKOUT_SEL(eClkSrcType));
}

/**
 * @brief Lock CSC0_CLKOUT_CTRL register
 *
 */
LOCAL_INLINE void CSC0_HWA_LockCLKOUT_CTRL(void)
{
    CSC0->CLKOUT_CTRL |= (uint32_t)CSC0_CLKOUT_CTRL_LOCK_MASK;
}

/**
 * @brief Unlock CSC0_CLKOUT_CTRL register
 *
 */
LOCAL_INLINE void CSC0_HWA_UnlockCLKOUT_CTRL(void)
{
    CSC0->CLKOUT_CTRL &= ~(uint32_t)CSC0_CLKOUT_CTRL_LOCK_MASK;
}

/**
 * @brief Get CSC0_CLKOUT_CTRL register lock status
 *
 * @return Lock status
 */
LOCAL_INLINE uint32_t CSC0_HWA_CLKOUT_CTRL_GetLockStatus(void)
{
    return (CSC0->CLKOUT_CTRL & (uint32_t)CSC0_CLKOUT_CTRL_LOCK_MASK);
}

/**
 * @brief Set AONCLKSR register
 *
 */
LOCAL_INLINE void CSC0_HWA_Set_AONCLKSR(uint32_t u32val)
{
    CSC0->AONCLKSR = u32val;
}

/**
 * @brief Get AONCLKSR register status
 *
 * @return AONCLKSR register status
 */
LOCAL_INLINE uint32_t CSC0_HWA_Get_AONCLKSR(void)
{
    return CSC0->AONCLKSR;
}

/**
 * @brief Set CSC0_AON32KCLK source clock
 *
 * @param CSC0_AON32KClkSrcType CSC0_AON32KCLK source type
 */
LOCAL_INLINE void CSC0_HWA_SetAON32kClkSrc(CSC0_AON32KClkSrcType eClkSrcType)
{
    uint32_t u32RegVal = CSC0->AONCLKSR;
    CSC0->AONCLKSR = ((u32RegVal & (~(uint32_t)CSC0_AONCLKSR_AON32KCLKSEL_MASK)) | CSC0_AONCLKSR_AON32KCLKSEL(eClkSrcType));
}

/**
 * @brief Set CSC0_RTCCLK source clock
 *
 * @param CSC0_RTCClkSrcType CSC0_RTCCLK source type
 */
LOCAL_INLINE void CSC0_HWA_SetRTCClkSrc(CSC0_RTCClkSrcType eClkSrcType)
{
    uint32_t u32RegVal = CSC0->AONCLKSR;
    CSC0->AONCLKSR = ((u32RegVal & (~(uint32_t)CSC0_AONCLKSR_RTCCLKSEL_MASK)) | CSC0_AONCLKSR_RTCCLKSEL(eClkSrcType));
}

/**
 * @brief Set CSC0_AONCLK source clock
 *
 * @param CSC0_AONClkSrcType CSC0_AONCLK source type
 */
LOCAL_INLINE void CSC0_HWA_SetAONClkSrc(CSC0_AONClkSrcType eClkSrcType)
{
    uint32_t u32RegVal = CSC0->AONCLKSR;
    CSC0->AONCLKSR = ((u32RegVal & (~(uint32_t)CSC0_AONCLKSR_AONCLKSEL_MASK)) | CSC0_AONCLKSR_AONCLKSEL(eClkSrcType));
}

/**
 * @brief Enable CSC0_SIRCDIV32K clock out
 *
 */
LOCAL_INLINE void CSC0_HWA_EnableSIRCDIV_32KClkOut(void)
{
    CSC0->AONCLKSR |= (uint32_t)CSC0_AONCLKSR_SIRCDIV32KEN_MASK;
}

/**
 * @brief Disable CSC0_SIRCDIV32K clock out
 *
 */
LOCAL_INLINE void CSC0_HWA_DisableSIRCDIV_32KClkOut(void)
{
    CSC0->AONCLKSR &= ~(uint32_t)CSC0_AONCLKSR_SIRCDIV32KEN_MASK;
}

/**
 * @brief Enable CSC0_SIRC32_1K clock out
 *
 */
LOCAL_INLINE void CSC0_HWA_EnableSIRC32_1KClkOut(void)
{
    CSC0->AONCLKSR |= (uint32_t)CSC0_AONCLKSR_AON1KCLKEN_MASK;
}

/**
 * @brief Disable CSC0_SIRC32_1K clock out
 *
 */
LOCAL_INLINE void CSC0_HWA_DisableSIRC32_1KClkOut(void)
{
    CSC0->AONCLKSR &= ~(uint32_t)CSC0_AONCLKSR_AON1KCLKEN_MASK;
}

/**
 * @brief Lock CSC0_AONCLKSR register
 *
 */
LOCAL_INLINE void CSC0_HWA_LockAONCLKSR(void)
{
    CSC0->AONCLKSR |= (uint32_t)CSC0_AONCLKSR_LOCK_MASK;
}

/**
 * @brief Unlock CSC0_AONCLKSR register
 *
 */
LOCAL_INLINE void CSC0_HWA_UnlockAONCLKSR(void)
{
    CSC0->AONCLKSR &= ~(uint32_t)CSC0_AONCLKSR_LOCK_MASK;
}

/**
 * @brief Get CSC0_AONCLKSR register status
 *
 * @return Lock status
 */
LOCAL_INLINE uint32_t CSC0_HWA_AONCLKSR_GetLockStaus(void)
{
    return (CSC0->AONCLKSR & (uint32_t)CSC0_AONCLKSR_LOCK_MASK);
}

/**
 * @brief Set PCU control register
 *
 */
LOCAL_INLINE void CSC0_HWA_Set_PCU_CTRL(uint32_t u32val)
{
    CSC0->PCU_CTRL = u32val;
}

/**
 * @brief Get PCU control register
 * @return Register status
 */
LOCAL_INLINE uint32_t CSC0_HWA_Get_PCU_CTRL(void)
{
    return CSC0->PCU_CTRL;
}

/**
 * @brief Get count of reduce power mode exit
 *
 *  @return count be got
 */
LOCAL_INLINE uint8_t CSC0_HWA_GetRpmExitCount(void)
{
    return (uint8_t)((CSC0->PCU_CTRL & (uint32_t)CSC0_PCU_CTRL_RPM_EXIT_CNT_MASK)>>CSC0_PCU_CTRL_RPM_EXIT_CNT_SHIFT);
}

/**
 * @brief Set CSC_CMU  control group register
 *
 * @param u32Value Value to be set
 */
LOCAL_INLINE void CSC0_HWA_Set_CMU_CTRL(uint32_t u32Value)
{
    CSC0->CMU_CTRL = u32Value;
}

/**
 * @brief Get CSC_CMU  control group register status
 *
 * @return register status
 */
LOCAL_INLINE uint32_t CSC0_HWA_Get_CMU_CTRL(void)
{
    return CSC0->CMU_CTRL;
}
#endif

/**
 * @brief Set multi CSC_SMU  control group 0
 *
 * @param u32Value Value to be set
 */
LOCAL_INLINE void CSC0_HWA_Set_SMU_CTRL0(uint32_t u32Value)
{
    CSC0->SMU_CTRL0 = u32Value;
}

/**
 * @brief Get CSC0_SMU_CTRL0 register status
 *
 * @return register status
 */
LOCAL_INLINE uint32_t CSC0_HWA_Get_SMU_CTRL0(void)
{
    return CSC0->SMU_CTRL0;
}

/**
 * @brief Set multi CSC_SMU  control group 1
 *
 * @param u32Value Value to be set
 */
LOCAL_INLINE void CSC0_HWA_Set_SMU_CTRL1(uint32_t u32Value)
{
    CSC0->SMU_CTRL1 = u32Value;
}

/**
 * @brief Get CSC0_SMU_CTRL1 register status
 *
 * @return register status
 */
LOCAL_INLINE uint32_t CSC0_HWA_Get_SMU_CTRL1(void)
{
    return CSC0->SMU_CTRL1;
}

/**
 * @brief Set multi CSC_SMU  control group 4
 *
 * @param u32Value Value to be set
 */
LOCAL_INLINE void CSC0_HWA_Set_SMU_CTRL4(uint32_t u32Value)
{
    CSC0->SMU_CTRL4 = u32Value;
}

/**
 * @brief Get CSC0_SMU_CTRL4 register status
 *
 * @return register status
 */
LOCAL_INLINE uint32_t CSC0_HWA_Get_SMU_CTRL4(void)
{
    return CSC0->SMU_CTRL4;
}

#if CSC0_SMU_CTRL5_SUPPORT
/**
 * @brief Set multi CSC_SMU  control group 5
 *
 * @param u32Value Value to be set
 */
LOCAL_INLINE void CSC0_HWA_Set_SMU_CTRL5(uint32_t u32Value)
{
    CSC0->SMU_CTRL5 = u32Value;
}

/**
 * @brief Get CSC0_SMU_CTRL5 register status
 *
 * @return register status
 */
LOCAL_INLINE uint32_t CSC0_HWA_Get_SMU_CTRL5(void)
{
    return CSC0->SMU_CTRL5;
}
#endif  /* CSC0_SMU_CTRL5_SUPPORT */

#if CSC0_LP_WAKEUP_SUPPORT
/**
 * @brief Set LP_WAKEUP register
 *
 * @param u32Value Value to be set
 */
LOCAL_INLINE void CSC0_HWA_Set_LP_WAKEUP(uint32_t u32Value)
{
    CSC0->LP_WAKEUP = u32Value;
}

/**
 * @brief Get LP_WAKEUP register status
 *
 * @return register status
 */
LOCAL_INLINE uint32_t CSC0_HWA_Get_LP_WAKEUP(void)
{
    return CSC0->LP_WAKEUP;
}
#endif  /* CSC0_LP_WAKEUP_SUPPORT */

#endif /* CSC0_INSTANCE_COUNT > 0U */

#if CSC1_INSTANCE_COUNT > 0U
/****** Operation on CSC1_xxxRegister0 ******/
/** @brief Set stop mode register 0
 *
 */
LOCAL_INLINE void CSC1_HWA_Set_STOP_MODER0(uint32_t u32val)
{
    CSC1->STOP_MODER0 = u32val;
}

/**
 * @brief Get stop mode register 0
 * @return Register status
 */
LOCAL_INLINE uint32_t CSC1_HWA_Get_STOP_MODER0(void)
{
    return CSC1->STOP_MODER0;
}

/**
 * @brief Set stop request register 0
 *
 */
LOCAL_INLINE void CSC1_HWA_Set_STOP_REQR0(uint32_t u32val)
{
    CSC1->STOP_REQR0 = u32val;
}

/**
 * @brief Get stop request register 0
 * @return Register status
 */
LOCAL_INLINE uint32_t CSC1_HWA_Get_STOP_REQR0(void)
{
    return CSC1->STOP_REQR0;
}

/**
 * @brief Get stop ack status in register 0
 *
 * @return Register ack status
 */
LOCAL_INLINE uint32_t CSC1_HWA_Get_STOP_ACKR0(void)
{
    return CSC1->STOP_ACKR0;
}

/****** Operation on CSC1_xxxRegister1 ******/
/**
 * @brief Set stop mode register 1
 *
 */
LOCAL_INLINE void CSC1_HWA_Set_STOP_MODER1(uint32_t u32val)
{
    CSC1->STOP_MODER1 = u32val;
}

/**
 * @brief Get stop mode register 1
 * @return Register status
 */
LOCAL_INLINE uint32_t CSC1_HWA_Get_STOP_MODER1(void)
{
    return CSC1->STOP_MODER1;
}

/**
 * @brief Set stop request register 1
 *
 */
LOCAL_INLINE void CSC1_HWA_Set_STOP_REQR1(uint32_t u32val)
{
    CSC1->STOP_REQR1 = u32val;
}

/**
 * @brief Get stop request register 1
 * @return Register status
 */
LOCAL_INLINE uint32_t CSC1_HWA_Get_STOP_REQR1(void)
{
    return CSC1->STOP_REQR1;
}

/**
 * @brief Get stop ack status in register 1
 *
 * @return Register ack status
 */
LOCAL_INLINE uint32_t CSC1_HWA_Get_STOP_ACKR1(void)
{
    return CSC1->STOP_ACKR1;
}

/****** Operation on CSC1_xxxRegister2 ******/
/**
 * @brief Set stop mode register 2
 *
 */
LOCAL_INLINE void CSC1_HWA_Set_STOP_MODER2(uint32_t u32val)
{
    CSC1->STOP_MODER2 = u32val;
}

/**
 * @brief Get stop mode register 2
 * @return Register status
 */
LOCAL_INLINE uint32_t CSC1_HWA_Get_STOP_MODER2(void)
{
    return CSC1->STOP_MODER2;
}

/**
 * @brief Set stop request register 2
 *
 */
LOCAL_INLINE void CSC1_HWA_Set_STOP_REQR2(uint32_t u32val)
{
    CSC1->STOP_REQR2 = u32val;
}

/**
 * @brief Get stop request register 2
 * @return Register status
 */
LOCAL_INLINE uint32_t CSC1_HWA_Get_STOP_REQR2(void)
{
    return CSC1->STOP_REQR2;
}

/**
 * @brief Get stop ack status in register 2
 *
 * @return Register ack status
 */
LOCAL_INLINE uint32_t CSC1_HWA_Get_STOP_ACKR2(void)
{
    return CSC1->STOP_ACKR2;
}

/**
 * @brief Set CCM0 configure register
 *
 */
LOCAL_INLINE void CSC1_HWA_Set_CCM1_CFG(uint32_t u32val)
{
    CSC1->CCM1_CFG = u32val;
}

/**
 * @brief Get  CCM0 configure
 * @return Register status
 */
LOCAL_INLINE uint32_t CSC1_HWA_Get_CCM1_CFG(void)
{
    return CSC1->CCM1_CFG;
}

/**
 * @brief Set cpu0 software interrupt register
 *
 */
LOCAL_INLINE void CSC1_HWA_Set_CPU1_INT(uint32_t u32val)
{
    CSC1->CPU1_INT = u32val;
}

/**
 * @brief Get cpu1 software interrupt register
 * @return Register status
 */
LOCAL_INLINE uint32_t CSC1_HWA_Get_CPU1_INT(void)
{
    return CSC1->CPU1_INT;
}

/**
 * @brief Enable cpu1 software interrupt
 *
 */
LOCAL_INLINE void CSC1_HWA_EnableCpu1SWInterrupt(void)
{
    CSC1->CPU1_INT |= (uint32_t)CSC1_CPU1_INT_SW_INT_MASK;
}

/**
 * @brief Disable cpu1 software interrupt
 *
 */
LOCAL_INLINE void CSC1_HWA_DisableCpu1SWInterrupt(void)
{
    CSC1->CPU1_INT &= ~(uint32_t)CSC1_CPU1_INT_SW_INT_MASK;
}
#endif /* CSC1_INSTANCE_COUNT > 0U */

#if CSC2_INSTANCE_COUNT > 0U
/****** Operation on CSC2_xxxRegister0 ******/
/** @brief Set stop mode register 0
 *
 */
LOCAL_INLINE void CSC2_HWA_Set_STOP_MODER0(uint32_t u32val)
{
    CSC2->STOP_MODER0 = u32val;
}

/**
 * @brief Get stop mode register 0
 * @return Register status
 */
LOCAL_INLINE uint32_t CSC2_HWA_Get_STOP_MODER0(void)
{
    return CSC2->STOP_MODER0;
}

/**
 * @brief Set stop request register 0
 *
 */
LOCAL_INLINE void CSC2_HWA_Set_STOP_REQR0(uint32_t u32val)
{
    CSC2->STOP_REQR0 = u32val;
}

/**
 * @brief Get stop request register 0
 * @return Register status
 */
LOCAL_INLINE uint32_t CSC2_HWA_Get_STOP_REQR0(void)
{
    return CSC2->STOP_REQR0;
}

/**
 * @brief Get stop ack status in register 0
 *
 * @return Register ack status
 */
LOCAL_INLINE uint32_t CSC2_HWA_Get_STOP_ACKR0(void)
{
    return CSC2->STOP_ACKR0;
}

/****** Operation on CSC2_xxxRegister1 ******/
/**
 * @brief Set stop mode register 1
 *
 */
LOCAL_INLINE void CSC2_HWA_Set_STOP_MODER1(uint32_t u32val)
{
    CSC2->STOP_MODER1 = u32val;
}

/**
 * @brief Get stop mode register 1
 * @return Register status
 */
LOCAL_INLINE uint32_t CSC2_HWA_Get_STOP_MODER1(void)
{
    return CSC2->STOP_MODER1;
}

/**
 * @brief Set stop request register 1
 *
 */
LOCAL_INLINE void CSC2_HWA_Set_STOP_REQR1(uint32_t u32val)
{
    CSC2->STOP_REQR1 = u32val;
}

/**
 * @brief Get stop request register 1
 * @return Register status
 */
LOCAL_INLINE uint32_t CSC2_HWA_Get_STOP_REQR1(void)
{
    return CSC2->STOP_REQR1;
}

/**
 * @brief Get stop ack status in register 1
 *
 * @return Register ack status
 */
LOCAL_INLINE uint32_t CSC2_HWA_Get_STOP_ACKR1(void)
{
    return CSC2->STOP_ACKR1;
}

/****** Operation on CSC2_xxxRegister2 ******/
/**
 * @brief Set stop mode register 2
 *
 */
LOCAL_INLINE void CSC2_HWA_Set_STOP_MODER2(uint32_t u32val)
{
    CSC2->STOP_MODER2 = u32val;
}

/**
 * @brief Get stop mode register 2
 * @return Register status
 */
LOCAL_INLINE uint32_t CSC2_HWA_Get_STOP_MODER2(void)
{
    return CSC2->STOP_MODER2;
}

/**
 * @brief Set stop request register 2
 *
 */
LOCAL_INLINE void CSC2_HWA_Set_STOP_REQR2(uint32_t u32val)
{
    CSC2->STOP_REQR2 = u32val;
}

/**
 * @brief Get stop request register 2
 * @return Register status
 */
LOCAL_INLINE uint32_t CSC2_HWA_Get_STOP_REQR2(void)
{
    return CSC2->STOP_REQR2;
}

/**
 * @brief Get stop ack status in register 2
 *
 * @return Register ack status
 */
LOCAL_INLINE uint32_t CSC2_HWA_Get_STOP_ACKR2(void)
{
    return CSC2->STOP_ACKR2;
}

/**
 * @brief Set CCM0 configure register
 *
 */
LOCAL_INLINE void CSC2_HWA_Set_CCM2_CFG(uint32_t u32val)
{
    CSC2->CCM2_CFG = u32val;
}

/**
 * @brief Get  CCM0 configure
 * @return Register status
 */
LOCAL_INLINE uint32_t CSC2_HWA_Get_CCM2_CFG(void)
{
    return CSC2->CCM2_CFG;
}

/**
 * @brief Set cpu0 software interrupt register
 *
 */
LOCAL_INLINE void CSC2_HWA_Set_CPU2_INT(uint32_t u32val)
{
    CSC2->CPU2_INT = u32val;
}

/**
 * @brief Get cpu0 software interrupt register
 * @return Register status
 */
LOCAL_INLINE uint32_t CSC2_HWA_Get_CPU2_INT(void)
{
    return CSC2->CPU2_INT;
}

/**
 * @brief Enable cpu0 software interrupt
 *
 */
LOCAL_INLINE void CSC2_HWA_EnableCpu2SWInterrupt(void)
{
    CSC2->CPU2_INT |= (uint32_t)CSC2_CPU2_INT_SW_INT_MASK;
}

/**
 * @brief Disable cpu0 software interrupt
 *
 */
LOCAL_INLINE void CSC2_HWA_DisableCpu2SWInterrupt(void)
{
    CSC2->CPU2_INT &= ~(uint32_t)CSC2_CPU2_INT_SW_INT_MASK;
}
#endif /* CSC2_INSTANCE_COUNT > 0U */

/** @}*/
#if CSC3_INSTANCE_COUNT > 0U
/****** Operation on CSC3_xxxRegister0 ******/
/**
 * @brief Set stop mode register 0
 *
 */
LOCAL_INLINE void CSC3_HWA_Set_STOP_MODER0(uint32_t u32val)
{
    CSC3->STOP_MODER0 = u32val;
}

/**
 * @brief Get stop mode register 0
 * @return Register status
 */
LOCAL_INLINE uint32_t CSC3_HWA_Get_STOP_MODER0(void)
{
    return CSC2->STOP_MODER0;
}

/**
 * @brief Set stop request register 0
 *
 */
LOCAL_INLINE void CSC3_HWA_Set_STOP_REQR0(uint32_t u32val)
{
    CSC3->STOP_REQR0 = u32val;
}

/**
 * @brief Get stop request register 0
 * @return Register status
 */
LOCAL_INLINE uint32_t CSC3_HWA_Get_STOP_REQR0(void)
{
    return CSC3->STOP_REQR0;
}

/**
 * @brief Get stop ack status in register 0
 *
 * @return Register ack status
 */
LOCAL_INLINE uint32_t CSC3_HWA_Get_STOP_ACKR0(void)
{
    return CSC3->STOP_ACKR0;
}

/**
 * @brief Set stop mode register 1
 *
 */
LOCAL_INLINE void CSC3_HWA_Set_STOP_MODER1(uint32_t u32val)
{
    CSC3->STOP_MODER1 = u32val;
}

/**
 * @brief Get stop mode register 1
 * @return Register status
 */
LOCAL_INLINE uint32_t CSC3_HWA_Get_STOP_MODER1(void)
{
    return CSC3->STOP_MODER1;
}

/**
 * @brief Set stop request register 1
 *
 */
LOCAL_INLINE void CSC3_HWA_Set_STOP_REQR1(uint32_t u32val)
{
    CSC3->STOP_REQR1 = u32val;
}

/**
 * @brief Get stop request register 1
 * @return Register status
 */
LOCAL_INLINE uint32_t CSC3_HWA_Get_STOP_REQR1(void)
{
    return CSC3->STOP_REQR1;
}

/**
 * @brief Get stop ack status in register 1
 *
 * @return Register ack status
 */
LOCAL_INLINE uint32_t CSC3_HWA_Get_STOP_ACKR1(void)
{
    return CSC3->STOP_ACKR1;
}

/**
 * @brief Set stop mode register 2
 *
 */
LOCAL_INLINE void CSC3_HWA_Set_STOP_MODER2(uint32_t u32val)
{
    CSC3->STOP_MODER2 = u32val;
}

/**
 * @brief Get stop mode register 2
 * @return Register status
 */
LOCAL_INLINE uint32_t CSC3_HWA_Get_STOP_MODER2(void)
{
    return CSC2->STOP_MODER2;
}

/**
 * @brief Set stop request register 2
 *
 */
LOCAL_INLINE void CSC3_HWA_Set_STOP_REQR2(uint32_t u32val)
{
    CSC3->STOP_REQR2 = u32val;
}

/**
 * @brief Get stop request register 2
 * @return Register status
 */
LOCAL_INLINE uint32_t CSC3_HWA_Get_STOP_REQR2(void)
{
    return CSC3->STOP_REQR2;
}

/**
 * @brief Get stop ack status in register 2
 *
 * @return Register ack status
 */
LOCAL_INLINE uint32_t CSC3_HWA_Get_STOP_ACKR2(void)
{
    return CSC3->STOP_ACKR2;
}

/**
 * @brief Set CCM3 configure register
 *
 */
LOCAL_INLINE void CSC3_HWA_Set_CCM3_CFG(uint32_t u32val)
{
    CSC3->CCM3_CFG = u32val;
}

/**
 * @brief Get  CCM3 configure
 * @return Register status
 */
LOCAL_INLINE uint32_t CSC3_HWA_Get_CCM3_CFG(void)
{
    return CSC3->CCM3_CFG;
}

/**
 * @brief Set cpu0 software interrupt register
 *
 */
LOCAL_INLINE void CSC2_HWA_Set_CPU3_INT(uint32_t u32val)
{
    CSC3->CPU3_INT = u32val;
}

/**
 * @brief Get cpu0 software interrupt register
 * @return Register status
 */
LOCAL_INLINE uint32_t CSC2_HWA_Get_CPU3_INT(void)
{
    return CSC3->CPU3_INT;
}

/**
 * @brief Enable cpu0 software interrupt
 *
 */
LOCAL_INLINE void CSC2_HWA_EnableCpu3SWInterrupt(void)
{
    CSC3->CPU3_INT |= (uint32_t)CSC3_CPU3_INT_SW_INT_MASK;
}

/**
 * @brief Disable cpu0 software interrupt
 *
 */
LOCAL_INLINE void CSC2_HWA_DisableCpu3SWInterrupt(void)
{
    CSC3->CPU3_INT &= ~(uint32_t)CSC3_CPU3_INT_SW_INT_MASK;
}
#endif


#endif  /*#ifndef _HWA_CSC_H_*/
