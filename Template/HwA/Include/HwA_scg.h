/**
 * @file HwA_SCG.h
 * @author Flagchip
 * @brief SCG hardware access layer
 * @version 2.0.0
 * @date 2024-08-20
 *
 * SDK Version: 2.6.0
 *

 * @copyright Copyright (c) 2024 Flagchip Semiconductors Co., Ltd.
 *
 * @details
 */
/* ********************************************************************************
   *   Revision History:
   *
   *   Version     Date          Initials      CR#          Descriptions
   *   ---------   ----------    ------------  ----------   ---------------
   *   0.1.0      2023-12-15     Flagchip055   N/A          First version for FC7300
   *   2.0.0      2024-10-12     Flagchip055   N/A          Change version and release
   ******************************************************************************** */


#ifndef _HWA_SCG_H_
#define _HWA_SCG_H_

#include "device_header.h"

#if SCG_INSTANCE_COUNT > 0U

/**
 * @defgroup HwA_scg HwA_scg
 * @ingroup module_driver_scg
 * @{
 */

/********* macros ************/
/** @brief PLL related */
#define SCG_PLLCSR_LK_MASK 0x800000u
#define SCG_PLLCSR_EN_MASK 0x1u
#define SCG_PLLCSR_CMRE_MASK 0x20000u
#define SCG_PLLCSR_CMRE_SHIFT 17u
#define SCG_PLLCSR_CMRE(x) (((uint32_t)(((uint32_t)(x))<<SCG_PLLCSR_CMRE_SHIFT))&SCG_PLLCSR_CMRE_MASK)
#define SCG_PLLCSR_CM_MASK 0x10000u
#define SCG_PLLCSR_CM_SHIFT 16u
#define SCG_PLLCSR_CM(x) (((uint32_t)(((uint32_t)(x))<<SCG_PLLCSR_CM_SHIFT))&SCG_PLLCSR_CM_MASK)
#define SCG_PLLCSR_STEN_MASK 0x2u
#define SCG_PLLCSR_STEN_SHIFT 1u
#define SCG_PLLCSR_STEN(x) (((uint32_t)(((uint32_t)(x))<<SCG_PLLCSR_STEN_SHIFT))&SCG_PLLCSR_STEN_MASK)
#define SCG_PLLDIV_DIVL_EN_MASK 0x4000000u
#define SCG_PLLDIV_DIVL_MASK 0x70000u
#define SCG_PLLDIV_DIVL_SHIFT 16u
#define SCG_PLLDIV_DIVL(x) (((uint32_t)(((uint32_t)(x))<<SCG_PLLDIV_DIVL_SHIFT))&SCG_PLLDIV_DIVL_MASK)
#define SCG_PLLDIV_DIVM_EN_MASK 0x2000000u
#define SCG_PLLDIV_DIVM_MASK 0x700u
#define SCG_PLLDIV_DIVM_SHIFT 8u
#define SCG_PLLDIV_DIVM(x) (((uint32_t)(((uint32_t)(x))<<SCG_PLLDIV_DIVM_SHIFT))&SCG_PLLDIV_DIVM_MASK)
#define SCG_PLLDIV_DIVH_EN_MASK 0x1000000u
#define SCG_PLLDIV_DIVH_MASK 0x7u
#define SCG_PLLDIV_DIVH_SHIFT 0u
#define SCG_PLLDIV_DIVH(x) (((uint32_t)(((uint32_t)(x))<<SCG_PLLDIV_DIVH_SHIFT))&SCG_PLLDIV_DIVH_MASK)

#if SCG_PLL0_CLK2_SUPPORT
#define SCG_PLLCFG_MULT_MASK 0x3FF0000u
#define SCG_PLLCFG_MULT_SHIFT 16u
#define SCG_PLLCFG_MULT(x) (((uint32_t)(((uint32_t)(x))<<SCG_PLLCFG_MULT_SHIFT))&SCG_PLLCFG_MULT_MASK)
#else
#define SCG_PLLCFG_MULT_MASK 0x1FF0000u
#define SCG_PLLCFG_MULT_SHIFT 16u
#define SCG_PLLCFG_MULT(x) (((uint32_t)(((uint32_t)(x))<<SCG_PLLCFG_MULT_SHIFT))&SCG_PLLCFG_MULT_MASK)
#endif /* SCG_PLL0_CLK2_SUPPORT */

#define SCG_PLLCFG_PREDIV_MASK 0x1F00u
#define SCG_PLLCFG_PREDIV_SHIFT 8u
#define SCG_PLLCFG_PREDIV(x) (((uint32_t)(((uint32_t)(x))<<SCG_PLLCFG_PREDIV_SHIFT))&SCG_PLLCFG_PREDIV_MASK)
#define SCG_PLLCFG_PSTDIV_MASK 0x30u
#define SCG_PLLCFG_PSTDIV_SHIFT 4u
#define SCG_PLLCFG_PSTDIV(x) (((uint32_t)(((uint32_t)(x))<<SCG_PLLCFG_PSTDIV_SHIFT))&SCG_PLLCFG_PSTDIV_MASK)
#define SCG_PLLCFG_SOURCE_MASK 0x1u
#define SCG_PLLCFG_SOURCE_SHIFT 0u
#define SCG_PLLCFG_SOURCE(x) (((uint32_t)(((uint32_t)(x))<<SCG_PLLCFG_SOURCE_SHIFT))&SCG_PLLCFG_SOURCE_MASK)
#define SCG_PLLCFG_PSTDIV1_MASK 0xEu
#define SCG_PLLCFG_PSTDIV1_SHIFT 1u
#define SCG_PLLCFG_PSTDIV1(x) (((uint32_t)(((uint32_t)(x))<<SCG_PLLCFG_PSTDIV1_SHIFT))&SCG_PLLCFG_PSTDIV1_MASK)

#define _SCG_HWA_SetPllCsr(_pll_, val) SCG->_pll_##CSR = val
#define SCG_HWA_SetPllCsr(pll, val) _SCG_HWA_SetPllCsr(pll, val)

#define _SCG_HWA_UnlockPllCsr(_pll_) SCG->_pll_##CSR &= ~(uint32_t)SCG_PLLCSR_LK_MASK
#define SCG_HWA_UnlockPllCsr(pll) _SCG_HWA_UnlockPllCsr(pll)

#define _SCG_HWA_LockPllCsr(_pll_) SCG->_pll_##CSR |= (uint32_t)SCG_PLLCSR_LK_MASK
#define SCG_HWA_LockPllCsr(pll) _SCG_HWA_LockPllCsr(pll)

#define _SCG_HWA_EnablePllClockMonitor(_pll_) SCG->_pll_##CSR |= (uint32_t)SCG_PLLCSR_CM_MASK
#define SCG_HWA_EnablePllClockMonitor(pll) _SCG_HWA_EnablePllClockMonitor(pll)

#define _SCG_HWA_EnablePllClockMonitorReset(_pll_) SCG->_pll_##CSR |= (uint32_t)SCG_PLLCSR_CMRE_MASK
#define SCG_HWA_EnablePllClockMonitorReset(pll) _SCG_HWA_EnablePllClockMonitorReset(pll)

#define _SCG_HWA_SetPllCfg(_pll_, val) SCG->_pll_##CFG = val
#define SCG_HWA_SetPllCfg(pll, val) _SCG_HWA_SetPllCfg(pll, val)

#define _SCG_HWA_SetPllDiv(_pll_, val) SCG->_pll_##DIV = val
#define SCG_HWA_SetPllDiv(pll, val) _SCG_HWA_SetPllDiv(pll, val)

#define _SCG_HWA_EnablePll(_pll_) SCG->_pll_##CSR |= (uint32_t)(SCG_PLLCSR_EN_MASK)
#define SCG_HWA_EnablePll(pll) _SCG_HWA_EnablePll(pll)

#define _SCG_HWA_EnablePllDiv(_pll_) SCG->_pll_##DIV |= (uint32_t)(SCG_PLLDIV_DIVL_EN_MASK | SCG_PLLDIV_DIVM_EN_MASK | SCG_PLLDIV_DIVH_EN_MASK)
#define SCG_HWA_EnablePllDiv(pll) _SCG_HWA_EnablePllDiv(pll)

#define _SCG_HWA_DisablePllDiv(_pll_) SCG->_pll_##DIV &= (~(uint32_t)(SCG_PLLDIV_DIVL_EN_MASK | SCG_PLLDIV_DIVM_EN_MASK | SCG_PLLDIV_DIVH_EN_MASK))
#define SCG_HWA_DisablePllDiv(pll) _SCG_HWA_DisablePllDiv(pll)

#define _SCG_HWA_GetPllMult(_pll_) ((uint16_t)(((uint32_t)(SCG->_pll_##CFG) & SCG_PLLCFG_MULT_MASK) >> SCG_PLLCFG_MULT_SHIFT))
#define SCG_HWA_GetPllMult(pll) _SCG_HWA_GetPllMult(pll)

#define _SCG_HWA_GetPllPrediv(_pll_) ((uint8_t)(((uint32_t)(SCG->_pll_##CFG) & SCG_PLLCFG_PREDIV_MASK) >> SCG_PLLCFG_PREDIV_SHIFT))
#define SCG_HWA_GetPllPrediv(pll) _SCG_HWA_GetPllPrediv(pll)

#define _SCG_HWA_GetPllPstdiv(_pll_) ((uint8_t)(((uint32_t)(SCG->_pll_##CFG) & SCG_PLLCFG_PSTDIV_MASK) >> SCG_PLLCFG_PSTDIV_SHIFT))
#define SCG_HWA_GetPllPstdiv(pll) _SCG_HWA_GetPllPstdiv(pll)

#define _SCG_HWA_GetPllPstdiv1(_pll_) ((uint8_t)(((uint32_t)(SCG->_pll_##CFG) & SCG_PLLCFG_PSTDIV1_MASK) >> SCG_PLLCFG_PSTDIV1_SHIFT))
#define SCG_HWA_GetPllPstdiv1(pll) _SCG_HWA_GetPllPstdiv1(pll)

#define _SCG_HWA_GetPllSrc(_pll_) ((uint8_t)(((uint32_t)(SCG->_pll_##CFG) & SCG_PLLCFG_SOURCE_MASK) >> SCG_PLLCFG_SOURCE_SHIFT))
#define SCG_HWA_GetPllSrc(pll) _SCG_HWA_GetPllSrc(pll)

/* Clock valid, locked and div related */
#define _SCG_HWA_GetPllLocked(_clock_) ((bool)((((uint32_t)SCG->_clock_##CSR & (uint32_t)SCG_##_clock_##CSR_PLLLK_MASK) != 0U) ? true : false))
#define SCG_HWA_GetPllLocked(_clock_) _SCG_HWA_GetPllLocked(_clock_)

#define _SCG_HWA_GetClockValid(_clock_) ((bool)((((uint32_t)SCG->_clock_##CSR & (uint32_t)SCG_##_clock_##CSR_VLD_MASK) != 0U) ? true : false))
#define SCG_HWA_GetClockValid(_clock_) _SCG_HWA_GetClockValid(_clock_)

#define _SCG_HWA_GetClockDiv(_clock_) (uint32_t)SCG->_clock_##DIV
#define SCG_HWA_GetClockDiv(_clock_) _SCG_HWA_GetClockDiv(_clock_)

#define _SCG_HWA_GetTrimLocked(_clock_) ((bool)((((uint32_t)SCG->_clock_##CSR & (uint32_t)SCG_##_clock_##CSR_TRLK_MASK) != 0U) ? true : false))
#define SCG_HWA_GetTrimLocked(_clock_) _SCG_HWA_GetTrimLocked(_clock_)

#define SCG_CLOCKDIV_DIVL_ACK_MASK 0x40000000u
#define SCG_CLOCKDIV_DIVM_ACK_MASK 0x20000000u
#define SCG_CLOCKDIV_DIVH_ACK_MASK 0x10000000u
#define SCG_CLOCKDIV_DIV_ACK_MASK 0x70000000u
#define SCG_CLOCKDIV_DIV_ACK_MASK_SHIFT 0x7u
#define SCG_CLOCKDIV_DIVL_ACK_SHIFT 30u
#define SCG_CLOCKDIV_DIVM_ACK_SHIFT 29u
#define SCG_CLOCKDIV_DIVH_ACK_SHIFT 28u
#define SCG_CLOCKDIV_DIV_ACK_SHIFT 28u

#define SCG_CLOCKDIV_DIVL_EN_MASK 0x4000000u
#define SCG_CLOCKDIV_DIVM_EN_MASK 0x2000000u
#define SCG_CLOCKDIV_DIVH_EN_MASK 0x1000000u
#define SCG_CLOCKDIV_DIVL_EN_SHIFT 26u
#define SCG_CLOCKDIV_DIVM_EN_SHIFT 25u
#define SCG_CLOCKDIV_DIVH_EN_SHIFT 24u

#define SCG_CLOCKDIV_DIVL_VAL_MASK 0x70000u
#define SCG_CLOCKDIV_DIVM_VAL_MASK 0x700u
#define SCG_CLOCKDIV_DIVH_VAL_MASK 0x7u
#define SCG_CLOCKDIV_DIVL_VAL_SHIFT 16u
#define SCG_CLOCKDIV_DIVM_VAL_SHIFT 8u
#define SCG_CLOCKDIV_DIVH_VAL_SHIFT 0u

#define SCG_CHECK_DIVL_ACK(reg_val)                   ((reg_val & SCG_CLOCKDIV_DIVL_ACK_MASK) >> SCG_CLOCKDIV_DIVL_ACK_SHIFT)
#define SCG_CHECK_DIVM_ACK(reg_val)                   ((reg_val & SCG_CLOCKDIV_DIVM_ACK_MASK) >> SCG_CLOCKDIV_DIVM_ACK_SHIFT)
#define SCG_CHECK_DIVH_ACK(reg_val)                   ((reg_val & SCG_CLOCKDIV_DIVH_ACK_MASK) >> SCG_CLOCKDIV_DIVH_ACK_SHIFT)
#define SCG_CHECK_DIV_ACK(reg_val)                    ((reg_val & SCG_CLOCKDIV_DIV_ACK_MASK) >> SCG_CLOCKDIV_DIV_ACK_SHIFT)
#define SCG_CHECK_DIVL_EN(reg_val)                    ((reg_val & SCG_CLOCKDIV_DIVL_EN_MASK) >> SCG_CLOCKDIV_DIVL_EN_SHIFT)
#define SCG_CHECK_DIVM_EN(reg_val)                    ((reg_val & SCG_CLOCKDIV_DIVM_EN_MASK) >> SCG_CLOCKDIV_DIVM_EN_SHIFT)
#define SCG_CHECK_DIVH_EN(reg_val)                    ((reg_val & SCG_CLOCKDIV_DIVH_EN_MASK) >> SCG_CLOCKDIV_DIVH_EN_SHIFT)
#define SCG_GET_DIVL_VAL(reg_val)                     ((0U == ((reg_val & SCG_CLOCKDIV_DIVL_VAL_MASK) >> SCG_CLOCKDIV_DIVL_VAL_SHIFT)) ? 1U : ((reg_val & SCG_CLOCKDIV_DIVL_VAL_MASK) >> SCG_CLOCKDIV_DIVL_VAL_SHIFT))
#define SCG_GET_DIVM_VAL(reg_val)                     ((0U == ((reg_val & SCG_CLOCKDIV_DIVM_VAL_MASK) >> SCG_CLOCKDIV_DIVM_VAL_SHIFT)) ? 1U : ((reg_val & SCG_CLOCKDIV_DIVM_VAL_MASK) >> SCG_CLOCKDIV_DIVM_VAL_SHIFT))
#define SCG_GET_DIVH_VAL(reg_val)                     ((0U == ((reg_val & SCG_CLOCKDIV_DIVH_VAL_MASK) >> SCG_CLOCKDIV_DIVH_VAL_SHIFT)) ? 1U : ((reg_val & SCG_CLOCKDIV_DIVH_VAL_MASK) >> SCG_CLOCKDIV_DIVH_VAL_SHIFT))
#define SCG_CALCULATE_DIVL_FREQ(clk_freq, reg_val)    (((1U == SCG_CHECK_DIVL_EN(reg_val)) && (clk_freq != UNKNOWN_CLOCK)) ? (uint32_t)clk_freq >> (uint8_t)(SCG_GET_DIVL_VAL(reg_val) - 1U) : (uint32_t)UNKNOWN_CLOCK)
#define SCG_CALCULATE_DIVM_FREQ(clk_freq, reg_val)    (((1U == SCG_CHECK_DIVM_EN(reg_val)) && (clk_freq != UNKNOWN_CLOCK)) ? (uint32_t)clk_freq >> (uint8_t)(SCG_GET_DIVM_VAL(reg_val) - 1U) : (uint32_t)UNKNOWN_CLOCK)
#define SCG_CALCULATE_DIVH_FREQ(clk_freq, reg_val)    (((1U == SCG_CHECK_DIVH_EN(reg_val)) && (clk_freq != UNKNOWN_CLOCK)) ? (uint32_t)clk_freq >> (uint8_t)(SCG_GET_DIVH_VAL(reg_val) - 1U) : (uint32_t)UNKNOWN_CLOCK)


/********* Local inline function   ************/

/**
 * @brief Get clock out configure register CLKOUTSEL value
 */
LOCAL_INLINE uint8_t SCG_HWA_GetClkOutSel(void)
{
    return (uint8_t)(((uint32_t)SCG->CLKOUTCFG & SCG_CLKOUTCFG_CLKOUTSEL_MASK) >> SCG_CLKOUTCFG_CLKOUTSEL_SHIFT);
}

/**
 * @brief Get clock out configure register value
 */
LOCAL_INLINE uint32_t SCG_HWA_GetClkOutCfg(void)
{
    return SCG->CLKOUTCFG;
}

/********* Sosc Register interface ************/
/**
 * @brief Unlock SOSC CSR register
 *
 */
LOCAL_INLINE void SCG_HWA_UnlockSoscCsr(void)
{
    SCG->SOSCCSR &= ~(uint32_t)(SCG_SOSCCSR_LK_MASK);
}

/**
 * @brief Lock SOSC CSR register
 *
 */
LOCAL_INLINE void SCG_HWA_LockSoscCsr(void)
{
    SCG->SOSCCSR |= (uint32_t)(SCG_SOSCCSR_LK_MASK);
}

/**
 * @brief Enable SOSC clock monitor
 *
 */
LOCAL_INLINE void SCG_HWA_EnableSoscClockMonitor(void)
{
    SCG->SOSCCSR |= (uint32_t)(SCG_SOSCCSR_CM_MASK);
}

/**
 * @brief Enable SOSC clock monitor Reset
 *
 */
LOCAL_INLINE void SCG_HWA_EnableSoscClockMonitorReset(void)
{
    SCG->SOSCCSR |= (uint32_t)(SCG_SOSCCSR_CMRE_MASK);
}

/**
 * @brief Set SOSC enable
 */
LOCAL_INLINE void SCG_HWA_EnableSosc(void)
{
    SCG->SOSCCSR |= (uint32_t)SCG_SOSCCSR_EN_MASK;
}

/**
 * @brief Diable SOSC
 */
LOCAL_INLINE void SCG_HWA_DisableSosc(void)
{
    SCG->SOSCCSR &= ~(uint32_t)SCG_SOSCCSR_EN_MASK;
}

/**
 * @brief Set SOSC CFG register value
 *
 * @param u32CfgValue configured register value
 */
LOCAL_INLINE void SCG_HWA_SetSoscCfg(uint32_t u32CfgValue)
{
    SCG->SOSCCFG = u32CfgValue;
}

/**
 * @brief Set SOSC CSR register value
 *
 * @param u32CsrValue configured register value
 */
LOCAL_INLINE void SCG_HWA_SetSoscCsr(uint32_t u32CsrValue)
{
    SCG->SOSCCSR = u32CsrValue;
}

/**
 * @brief Get SOSC CSR register value
 *
 */
LOCAL_INLINE uint32_t SCG_HWA_GetSoscCsr(void)
{
    return (uint32_t)SCG->SOSCCSR;
}

/********* Fosc Register interface ************/
/**
 * @brief Enable FOSC
 */
LOCAL_INLINE void SCG_HWA_EnableFosc(void)
{
    SCG->FOSCCSR |= (uint32_t)SCG_FOSCCSR_EN_MASK;
}

/**
 * @brief Disable FOSC
 */
LOCAL_INLINE void SCG_HWA_DisableFosc(void)
{
    SCG->FOSCCSR &= ~SCG_FOSCCSR_EN_MASK;
}

/**
 * @brief Set FOSCCFG register value
 *
 * @param u32CfgValue configured register value
 */
LOCAL_INLINE void SCG_HWA_SetFoscCfg(uint32_t u32CfgValue)
{
    SCG->FOSCCFG = u32CfgValue;
}

/**
 * @brief Set FOSCCSR register value
 *
 * @param u32CsrValue configured register value
 */
LOCAL_INLINE void SCG_HWA_SetFoscCsr(uint32_t u32CsrValue)
{
    SCG->FOSCCSR = u32CsrValue;
}

/**
 * @brief Get FOSCCSR register value
 *
 */
LOCAL_INLINE uint32_t SCG_HWA_GetFoscCsr(void)
{
    return (uint32_t)SCG->FOSCCSR;
}

/**
 * @brief Unlock FOSC CSR register
 *
 */
LOCAL_INLINE void SCG_HWA_UnlockFoscCsr(void)
{
    SCG->FOSCCSR &= ~(uint32_t)(SCG_FOSCCSR_LK_MASK);
}

/**
 * @brief lock FOSC CSR register
 *
 */
LOCAL_INLINE void SCG_HWA_LockFoscCsr(void)
{
    SCG->FOSCCSR |= (uint32_t)(SCG_FOSCCSR_LK_MASK);
}

/**
 * @brief Enable FOSC clock monitor
 *
 */
LOCAL_INLINE void SCG_HWA_EnableFoscClockMonitor(void)
{
    SCG->FOSCCSR |= (uint32_t)(SCG_FOSCCSR_CM_MASK);
}

/**
 * @brief Enable FOSC clock monitor Reset
 *
 */
LOCAL_INLINE void SCG_HWA_EnableFoscClockMonitorReset(void)
{
    SCG->FOSCCSR |= (uint32_t)(SCG_FOSCCSR_CMRE_MASK);
}

/**
 * @brief enable FOSCDIV as user manual request sequence
 */
LOCAL_INLINE void SCG_HWA_EnableFoscDiv(void)
{
    SCG->FOSCDIV |= (uint32_t)(SCG_FOSCDIV_DIVL_EN_MASK
                               | SCG_FOSCDIV_DIVM_EN_MASK
                               | SCG_FOSCDIV_DIVH_EN_MASK);
}

/**
 * @brief Disable FOSCDIV as user manual request sequence
 */
LOCAL_INLINE void SCG_HWA_DiableFoscDiv(void)
{
    SCG->FOSCDIV &= ~(uint32_t)(SCG_FOSCDIV_DIVL_EN_MASK
                                | SCG_FOSCDIV_DIVM_EN_MASK
                                | SCG_FOSCDIV_DIVH_EN_MASK);
}

/**
 * @brief Set FOSCDIV register value
 *
 * @param u32DivValue configured register value
 */
LOCAL_INLINE void SCG_HWA_SetFoscDiv(uint32_t u32DivValue)
{
    SCG->FOSCDIV = u32DivValue;
}

#if SCG_LP_WKPWDG_SUPPORT
/**
 * @brief Set Low Power Wakeup WDOG Register
 *
 * @param u8MSBVal Most Significant value, if OSC is 40M
 *                 and FOSC not valid after 1.8ms wakeup,
 *                 the chip will reset and RGM register will
 *                 report clock error reset reason.
 */
LOCAL_INLINE void SCG_HWA_SetWKPWDG(uint8_t u8MSBVal)
{
    SCG->WKPWDG = SCG_WKPWDG_MSB(u8MSBVal) | SCG_WKPWDG_EN_MASK;
}
#endif


/*********  Sirc Register interface  ************/
/**
 * @brief Set SIRCCSR register value
 *
 * @param u32CsrValue configured register value
 */
LOCAL_INLINE void SCG_HWA_SetSircCsr(uint32_t u32CsrValue)
{
    SCG->SIRCCSR = u32CsrValue;
}

/**
 * @brief Get SIRCCSR register value
 *
 */
LOCAL_INLINE uint32_t SCG_HWA_GetSircCsr(void)
{
    return (uint32_t)SCG->SIRCCSR;
}

/**
 * @brief Unlock SIRC CSR register
 *
 */
LOCAL_INLINE void SCG_HWA_UnlockSircCsr(void)
{
    SCG->SIRCCSR &= ~(uint32_t)SCG_SIRCCSR_LK_MASK;
}

/**
 * @brief Lock SIRC CSR register
 *
 */
LOCAL_INLINE void SCG_HWA_LockSircCsr(void)
{
    SCG->SIRCCSR |= (uint32_t)SCG_SIRCCSR_LK_MASK;
}

/**
 * @brief Enable SIRC clock monitor
 *
 */
LOCAL_INLINE void SCG_HWA_EnableSircClockMonitor(void)
{
    SCG->SIRCCSR |= (uint32_t)(SCG_SIRCCSR_CM_MASK);
}

/**
 * @brief Set SIRCDIV register value
 *
 * @param u32DivValue configured register value
 */
LOCAL_INLINE void SCG_HWA_SetSircDiv(uint32_t u32DivValue)
{
    SCG->SIRCDIV = u32DivValue;
}

/**
 * @brief Disable SIRCDIV as user manual request sequence
 */
LOCAL_INLINE void SCG_HWA_DiableSircDiv(void)
{
    SCG->SIRCDIV &= ~(uint32_t)(SCG_SIRCDIV_DIVL_EN_MASK
                                | SCG_SIRCDIV_DIVM_EN_MASK
                                | SCG_SIRCDIV_DIVH_EN_MASK);
}

/**
 * @brief enable FIRCDIV as user manual request sequence
 */
LOCAL_INLINE void SCG_HWA_EnableSircDiv(void)
{
    SCG->SIRCDIV |= (uint32_t)(SCG_SIRCDIV_DIVL_EN_MASK
                               | SCG_SIRCDIV_DIVM_EN_MASK
                               | SCG_SIRCDIV_DIVH_EN_MASK);
}

/**
 * @brief Set SIRCTCFG register value for SIRC Trim configure.
 *
 * @param u32TcfgValue configured register value
 */
LOCAL_INLINE void SCG_HWA_SetSircTcfg(uint32_t u32TcfgValue)
{
    SCG->SIRCTCFG = u32TcfgValue;
}

/*********  Sirc32k Register interface  ************/
/**
 * @brief Enable SIRC32KCSR register
 *
 */
LOCAL_INLINE void SCG_HWA_EnableSirc32kCsr(void)
{
    SCG->SIRC32KCSR |= (uint32_t)SCG_SIRC32KCSR_EN_MASK;
}

/**
 * @brief Disable SIRC32KCSR register
 *
 */
LOCAL_INLINE void SCG_HWA_DisableSirc32kCsr(void)
{
    SCG->SIRC32KCSR &= ~(uint32_t)SCG_SIRC32KCSR_EN_MASK;
}

/**
 * @brief Unlock SIRC32K CSR register
 */
LOCAL_INLINE void SCG_HWA_UnlockSirc32kCsr(void)
{
    SCG->SIRC32KCSR &= ~(uint32_t)(SCG_SIRC32KCSR_LK_MASK);
}

/**
 * @brief Lock SIRC32K CSR register
 */
LOCAL_INLINE void SCG_HWA_LockSirc32kCsr(void)
{
    SCG->SIRC32KCSR |= (uint32_t)(SCG_SIRC32KCSR_LK_MASK);
}

/********* Firc Register interface ************/
/**
 * @brief Get FIRC CSR register value.
 */
LOCAL_INLINE uint32_t SCG_HWA_GetFircCsr(void)
{
    return (uint32_t)SCG->FIRCCSR;
}

/**
 * @brief Enable FIRC.
 */
LOCAL_INLINE void SCG_HWA_EnableFirc(void)
{
    SCG->FIRCCSR |= (uint32_t)SCG_FIRCCSR_EN_MASK;
}

/**
 * @brief Unlock FIRC CSR register
 */
LOCAL_INLINE void SCG_HWA_UnlockFircCsr(void)
{
    SCG->FIRCCSR &= ~(uint32_t)(SCG_FIRCCSR_LK_MASK);
}

/**
 * @brief Lock FIRC CSR register
 */
LOCAL_INLINE void SCG_HWA_LockFircCsr(void)
{
    SCG->FIRCCSR |= (uint32_t)(SCG_FIRCCSR_LK_MASK);
}

/**
 * @brief Enable FIRC clock monitor
 *
 */
LOCAL_INLINE void SCG_HWA_EnableFircClockMonitor(void)
{
    SCG->FIRCCSR |= (uint32_t)(SCG_FIRCCSR_CM_MASK);
}

/**
 * @brief Disable FIRC.
 */
LOCAL_INLINE void SCG_HWA_DisableFirc(void)
{
    SCG->FIRCCSR &= ~(uint32_t)SCG_FIRCCSR_EN_MASK;
}

/**
 * @brief Set FIRCCSR register value
 *
 * @param u32CsrValue configured register value
 */
LOCAL_INLINE void SCG_HWA_SetFircCsr(uint32_t u32CsrValue)
{
    SCG->FIRCCSR = u32CsrValue;
}

/**
 * @brief Set FIRCCFG register value
 *
 * @param u32CfgValue configured register value
 */
LOCAL_INLINE void SCG_HWA_SetFircCfg(uint32_t u32CfgValue)
{
    SCG->FIRCCFG = u32CfgValue;
}

/**
 * @brief Set FOSCDIV register value
 *
 * @param u32DivValue configured register value
 */
LOCAL_INLINE void SCG_HWA_SetFircDiv(uint32_t u32DivValue)
{
    SCG->FIRCDIV = u32DivValue;
}

/**
 * @brief Disable FIRCDIV as user manual request sequence
 */
LOCAL_INLINE void SCG_HWA_DiableFircDiv(void)
{
    SCG->FIRCDIV &= ~(uint32_t)(SCG_FIRCDIV_DIVL_EN_MASK
                                | SCG_FIRCDIV_DIVM_EN_MASK
                                | SCG_FIRCDIV_DIVH_EN_MASK);
}

/**
 * @brief enable FIRCDIV as user manual request sequence
 */
LOCAL_INLINE void SCG_HWA_EnableFircDiv(void)
{
    SCG->FIRCDIV |= (uint32_t)(SCG_FIRCDIV_DIVL_EN_MASK
                               | SCG_FIRCDIV_DIVM_EN_MASK
                               | SCG_FIRCDIV_DIVH_EN_MASK);
}

/**
 * @brief Set FIRCTCFG register value for FIRC clock trim configure.
 *
 * @param u32TcfgValue configured register value.
 */
LOCAL_INLINE void SCG_HWA_SetFircTcfg(uint32_t u32TcfgValue)
{
    SCG->FIRCTCFG = u32TcfgValue;
}

/********* System clock Register interface ************/
/**
 * @brief Set system clock CCR register value
 *
 * @param u32CcrValue configured register value
 */
LOCAL_INLINE void SCG_HWA_SetCCR(uint32_t u32CcrValue)
{
    SCG->CCR = u32CcrValue;
}

/**
 * @brief Set system clock CCR register value
 *
 */
LOCAL_INLINE uint32_t SCG_HWA_GetCCR(void)
{
    return SCG->CCR;
}

/**
 * @brief Set system clock CSR register value
 *
 */
LOCAL_INLINE uint32_t SCG_HWA_GetCSR(void)
{
    return SCG->CSR;
}

/********* Pll0 Register interface ************/
/**
 * @brief Get PLL0CSR register value.
 *
 * @return PLL0CSR register value.
 */
LOCAL_INLINE uint32_t SCG_HWA_GetPll0Csr(void)
{
    return SCG->PLL0CSR;
}

/**
 * @brief Get PLL0CFG register value.
 *
 * @return PLL0CFG register value.
 */
LOCAL_INLINE uint32_t SCG_HWA_GetPll0Cfg(void)
{
    return SCG->PLL0CFG;
}

/********* Pll1 Register interface ************/
#if SCG_PLL1_SUPPORT
/**
 * @brief Get PLL1CSR register value.
 *
 * @return PLL1CSR register value.
 */
LOCAL_INLINE uint32_t SCG_HWA_GetPll1Csr(void)
{
    return SCG->PLL1CSR;
}
#endif /* SCG_PLL1_SUPPORT */

/**
 * @brief Set system clock
 *
 * @param u8SystemCLock System clock value
 */
LOCAL_INLINE void SCG_HWA_SetSystemClock(uint8_t u8SystemCLock)
{
    SCG->CCR = ((SCG->CCR & ~(uint32_t)SCG_CCR_SCS_MASK) | SCG_CCR_SCS(u8SystemCLock));
}

/**
 * @brief Get system clock source. used to calculate system clock frequency at startup.
 *        used to check if the target clock soure successfully switched.
 * @return uint8_t. system clock source.
 */
LOCAL_INLINE uint8_t SCG_HWA_GetSysClkSrc(void)
{
    return (uint8_t)(((uint32_t)(SCG->CSR) & (uint32_t)SCG_CSR_SCS_MASK) >> SCG_CSR_SCS_SHIFT);
}

/**
 * @brief Get system clock valid status, use this status to check system clock update finished or not.
 * @return bool. true as updated; false as not updated.
 */
LOCAL_INLINE bool SCG_HWA_GetSysClkUPRD(void)
{
    return (bool)((((uint32_t)SCG->CSR & (uint32_t)SCG_CSR_CCR_UPRD_MASK) != 0U) ? true : false);
}

/**
 * @brief Get system clock Divcore. used to calculate core clock frequency at startup.
 * @return uint8_t. system clock Divcore.
 */
LOCAL_INLINE uint8_t SCG_HWA_GetSysClkDivCore(void)
{
    return (uint8_t)(((uint32_t)(SCG->CSR) & SCG_CSR_DIVCORE_MASK) >> SCG_CSR_DIVCORE_SHIFT);
}

/**
 * @brief Get system clock Divbus. used to calculate bus clock frequency at startup.
 * @return uint8_t. system clock Divbus.
 */
LOCAL_INLINE uint8_t SCG_HWA_GetSysClkDivBus(void)
{
    return (uint8_t)(((uint32_t)(SCG->CSR) & SCG_CSR_DIVBUS_MASK) >> SCG_CSR_DIVBUS_SHIFT);
}

/**
 * @brief Get system clock Divslow. used to calculate slow clock frequency at startup.
 * @return uint8_t. system clock Divslow.
 */
LOCAL_INLINE uint8_t SCG_HWA_GetSysClkDivSlow(void)
{
    return (uint8_t)(((uint32_t)(SCG->CSR) & SCG_CSR_DIVSLOW_MASK) >> SCG_CSR_DIVSLOW_SHIFT);
}

/*********  Clkout Register interface ************/
/**
 * @brief Select clock out source
 *
 * @param u8ClkOutSel Clock out select
 */
LOCAL_INLINE void SCG_HWA_SetClkOutSel(uint8_t u8ClkOutSel)
{
    SCG->CLKOUTCFG = ((SCG->CLKOUTCFG & ~(uint32_t)SCG_CLKOUTCFG_CLKOUTSEL_MASK) | SCG_CLKOUTCFG_CLKOUTSEL(u8ClkOutSel));
}

/**
 * @brief Set Nvm clock source
 *
 * @param u32NvmClkMask Nvm clock source mask
 */
LOCAL_INLINE void SCG_HWA_SetNvmClk(uint32_t u32NvmClkMask)
{
    SCG->CLKOUTCFG &= ~(uint32_t)(SCG_CLKOUTCFG_NVMCLK_FIRC_MASK | SCG_CLKOUTCFG_NVMCLK_SIRC_MASK);
    SCG->CLKOUTCFG |= u32NvmClkMask;
}

/**
 * @brief Set CMU4 clock source
 *
 * @param u32Cmu4ClkMask CMU4 clock source mask
 */
LOCAL_INLINE void SCG_HWA_SetCmu4Clk(uint32_t u32Cmu4ClkMask)
{
    SCG->CLKOUTCFG &= ~(uint32_t)(SCG_CLKOUTCFG_CMU4CLK_FOSC_MASK | SCG_CLKOUTCFG_CMU4CLK_SIRC_MASK);
    SCG->CLKOUTCFG |= u32Cmu4ClkMask;
}

/**
 * @brief Check and clear SIRC clock error
 *
 */
LOCAL_INLINE bool SCG_HWA_CheckAndClearSircClkErr(void)
{
    bool bFlag = false;
    if (SCG_SIRCCSR_ERR_MASK == (SCG->SIRCCSR & SCG_SIRCCSR_ERR_MASK))
    {
        SCG->SIRCCSR |= (uint32_t)SCG_SIRCCSR_ERR_MASK;
        bFlag = true;
    }
    return bFlag;
}

/**
 * @brief Check and clear SOSC clock error
 *
 */
LOCAL_INLINE bool SCG_HWA_CheckAndClearSoscClkErr(void)
{
    bool bFlag = false;
    if (SCG_SOSCCSR_ERR_MASK == (SCG->SOSCCSR & SCG_SOSCCSR_ERR_MASK))
    {
        SCG->SOSCCSR |= (uint32_t)SCG_SOSCCSR_ERR_MASK;
        bFlag = true;
    }
    return bFlag;
}

/**
 * @brief Check and clear FOSC clock error
 *
 */
LOCAL_INLINE bool SCG_HWA_CheckAndClearFoscClkErr(void)
{
    bool bFlag = false;
    if (SCG_FOSCCSR_ERR_MASK == (SCG->FOSCCSR & SCG_FOSCCSR_ERR_MASK))
    {
        SCG->FOSCCSR |= (uint32_t)SCG_FOSCCSR_ERR_MASK;
        bFlag = true;
    }
    return bFlag;
}

/**
 * @brief Check and clear PLL0 clock error
 *
 */
LOCAL_INLINE bool SCG_HWA_CheckAndClearPll0ClkErr(void)
{
    bool bFlag = false;
    if (SCG_PLL0CSR_ERR_MASK == (SCG->PLL0CSR & SCG_PLL0CSR_ERR_MASK))
    {
        SCG->PLL0CSR |= (uint32_t)SCG_PLL0CSR_ERR_MASK;
        bFlag = true;
    }
    return bFlag;
}

#if SCG_PLL1_SUPPORT
/**
 * @brief Check and clear PLL1 clock error
 *
 */
LOCAL_INLINE bool SCG_HWA_CheckAndClearPll1ClkErr(void)
{
    bool bFlag = false;
    if (SCG_PLL1CSR_ERR_MASK == (SCG->PLL1CSR & SCG_PLL1CSR_ERR_MASK))
    {
        SCG->PLL1CSR |= (uint32_t)SCG_PLL1CSR_ERR_MASK;
        bFlag = true;
    }
    return bFlag;
}
#endif /* SCG_PLL1_SUPPORT */

/**
 * @brief Check and clear FIRC clock error
 *
 */
LOCAL_INLINE bool SCG_HWA_CheckAndClearFircClkErr(void)
{
    bool bFlag = false;
    if (SCG_FIRCCSR_ERR_MASK == (SCG->FIRCCSR & SCG_FIRCCSR_ERR_MASK))
    {
        SCG->FIRCCSR |= (uint32)SCG_FIRCCSR_ERR_MASK;
        bFlag = (boolean)TRUE;
    }
    return bFlag;
}

#if SCG_PLLX_CLK1_SUPPORT
/**
 * @brief Enable PLL0CK1 output
 */
LOCAL_INLINE void SCG_HWA_EnablePLL0CLK1Output(void)
{
    SCG->PLL0CSR |= (uint32_t)SCG_PLL0CSR_CK1EN_MASK;
}

/**
 * @brief Disable PLL0CK1 output
 */
LOCAL_INLINE void SCG_HWA_DisablePLL0CLK1Output(void)
{
    SCG->PLL0CSR &= ~(uint32_t)SCG_PLL0CSR_CK1EN_MASK;
}

/**
 * @brief Enable PLL0 Force Off.
 */
LOCAL_INLINE void SCG_HWA_EnablePll0ForceOff(void)
{
    SCG->PLL0PDIS = 0xFC200001;
}

#if SCG_PLL1_SUPPORT
/**
 * @brief Enable PLL1CK1 output
 */
LOCAL_INLINE void SCG_HWA_EnablePLL1CLK1Output(void)
{
    SCG->PLL1CSR |= (uint32_t)SCG_PLL1CSR_CK1EN_MASK;
}

/**
 * @brief Disable PLL1CK1 output
 */
LOCAL_INLINE void SCG_HWA_DisablePLL1CLK1Output(void)
{
    SCG->PLL1CSR &= ~(uint32_t)SCG_PLL1CSR_CK1EN_MASK;
}

/**
 * @brief Enable PLL1 Force Off.
 */
LOCAL_INLINE void SCG_HWA_EnablePll1ForceOff(void)
{
    SCG->PLL1PDIS = 0xFC200001;
}
#endif /* SCG_PLL1_SUPPORT */
#else
/**
 * @brief Set configuration register protection enable/disable .
 *
 * @param bEnable Enable/Disable protection
 */
LOCAL_INLINE void SCG_HWA_SetCfgRegProt(boolean bEnable)
{
    SCG->CFG = (SCG_CFG_PORT_LOCK_KEY(0x5A5A) | SCG_CFG_PORT_CFG_EN(bEnable));
}

/**
 * @brief Set PLL0 fast start enable/disable .
 *
 */
LOCAL_INLINE void SCG_HWA_EnablePll0FastStart(void)
{
    SCG->PLL0SCFG |= SCG_PLL0SCFG_FS_EN(1U);
}

/**
 * @brief Set PLL1 fast start enable/disable .
 *
 */
LOCAL_INLINE void SCG_HWA_EnablePll1FastStart(void)
{
    SCG->PLL1SCFG |= SCG_PLL1SCFG_FS_EN(1U);
}

#endif /* SCG_PLLX_CLK1_SUPPORT */

#if SCG_PLL0_CLK2_SUPPORT
/**
 * @brief Enable PLL0CK2 output
 */
LOCAL_INLINE void SCG_HWA_EnablePLL0CLK2Output(void)
{
    SCG->PLL0CSR |= (uint32_t)SCG_PLL0CSR_CK2EN_MASK;
}

/**
 * @brief Disable PLL0CK2 output
 */
LOCAL_INLINE void SCG_HWA_DisablePLL0CLK2Output(void)
{
    SCG->PLL0CSR &= ~(uint32_t)SCG_PLL0CSR_CK2EN_MASK;
}

/**
 * @brief Set PLL0ECFG register
 */
LOCAL_INLINE void SCG_HWA_SetPll0Ecfg(uint32_t u32Value)
{
    uint32 u32Temp;
	SCG->PLL0ECFG = u32Value;
	/* PLL0ECFG will active after PLL0CFG is written */
	u32Temp = SCG->PLL0CFG;
	SCG->PLL0CFG = u32Temp;
}

/**
 * @brief Get PLL0ECFG register value
 */
LOCAL_INLINE uint32_t SCG_HWA_GetPll0Ecfg(void)
{
    return SCG->PLL0ECFG;
}

#endif /* SCG_PLL0_CLK2_SUPPORT */

/*********  CRC Register interface ************/
/**
 * @brief Generate SCG register CRC value
 */
LOCAL_INLINE void SCG_HWA_GenCrcVal(void)
{
    SCG->CRCCSR |= (uint32_t)SCG_CRCCSR_GEN_MASK;
}

/**
 * @brief Enable SCG register CRC check
 */
LOCAL_INLINE void SCG_HWA_EnableCrcCheck(void)
{
    SCG->CRCCSR |= (uint32_t)SCG_CRCCSR_CHKEN_MASK;
}

/**
 * @brief Disable SCG register CRC check
 */
LOCAL_INLINE void SCG_HWA_DisableCrcCheck(void)
{
    SCG->CRCCSR &= ~(uint32_t)SCG_CRCCSR_CHKEN_MASK;
}

/**
 * @brief Enable SCG register CRC hardware trigger generate
 */
LOCAL_INLINE void SCG_HWA_EnableCrcTrigger(void)
{
    SCG->CRCCSR |= (uint32_t)SCG_CRCCSR_TRGEN_MASK;
}

/**
 * @brief Disable SCG register CRC hardware trigger generate
 */
LOCAL_INLINE void SCG_HWA_DisableCrcTrigger(void)
{
    SCG->CRCCSR &= ~(uint32_t)SCG_CRCCSR_TRGEN_MASK;
}

/**
 * @brief Enable SCG register CRC error output
 */
LOCAL_INLINE void SCG_HWA_EnableCrcErrorOutput(void)
{
    SCG->CRCCSR |= (uint32_t)SCG_CRCCSR_EOEN_MASK;
}

/**
 * @brief Disable SCG register CRC error output
 */
LOCAL_INLINE void SCG_HWA_DisableCrcErrorOutput(void)
{
    SCG->CRCCSR &= ~(uint32_t)SCG_CRCCSR_EOEN_MASK;
}

/**
 * @brief Get CRC busy status
 */
LOCAL_INLINE bool SCG_HWA_GetCrcBusyStatus(void)
{
    return (0U != (SCG->CRCCSR & (uint32_t)SCG_CRCCSR_BUSY_MASK));
}

/**
 * @brief Get CRC error status
 */
LOCAL_INLINE bool SCG_HWA_GetCrcErrorStatus(void)
{
    return (0U != (SCG->CRCCSR & (uint32_t)SCG_CRCCSR_ERR_MASK));
}

/**
 * @brief Clear CRC error flag
 */
LOCAL_INLINE void SCG_HWA_ClearCrcErrorFlag(void)
{
    SCG->CRCCSR |= (uint32_t)SCG_CRCCSR_ERR_MASK;
}

/**
 * @brief Get CRC result
 */
LOCAL_INLINE uint32_t SCG_HWA_GetCrcResult(void)
{
    return SCG->CRCRES;
}

/** @}*/ /* HwA_SCG */

#endif /* #if SCG_INSTANCE_COUNT > 0U */

#endif /* #ifndef _HWA_SCG_H_ */
