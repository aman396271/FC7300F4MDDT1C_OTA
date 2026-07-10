/**
 * @file HwA_sdadc.h
 * @author flagchip
 * @brief Hardware access layer for SDADC
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
   *   0.1.0      2023-12-15     Flagchip084   N/A          First version for FC7300
   *   2.0.0      2024-10-12     Flagchip084   N/A          Change version and release
   ******************************************************************************** */

#ifndef _HWA_SDADC_H_
#define _HWA_SDADC_H_

#include "device_header.h"

#if SDADC_INSTANCE_COUNT > 0U

#define SDADC_MSR_CHON_MASK            0x7u
#define SDADC_MSR_CHON_SHIFT           0u
#define SDADC_MSR_CHON_WIDTH           3u
#define SDADC_MSR_CHON(x)              (((uint32_t)(((uint32_t)(x))<<SDADC_MSR_CHON_SHIFT))&SDADC_MSR_CHON_MASK)

/**
 * @defgroup HwA_sdadc HwA_sdadc
 * @ingroup module_driver_sdadc
 * @{
 */
typedef struct
{
    __IO uint32_t CCR;    /**< Channel Control Register, offset: 0x0 */
    __IO uint32_t CDR;    /**< Channel Data Rate Register, offset: 0x4 */
    __IO uint32_t CFR;    /**< Channel Configuration Register, offset: 0x8 */
    __IO uint32_t CPR;    /**< Channel Protection Register, offset: 0xc */
    __IO uint32_t CBR;    /**< Channel Bias Register, offset: 0x10 */
    __IO uint32_t CLLMT;  /**< Channel Low Limit Register, offset: 0x14 */
    __IO uint32_t CHLMT;  /**< Channel High Limit Register, offset: 0x18 */
    __I uint32_t CRDATA;  /**< Channel Result Data Register, offset: 0x1c */
    __I uint32_t CMPDATA; /**< Channel Multi Purpose Data Register, offset: 0x20 */
} SDADC_ChannelRegType, *pSDADC_ChannelRegType;

#define SDADC_CHANNELCFGREG(base) ((pSDADC_ChannelRegType)((int)(&((SDADC_Type *)0)->CCR0) + (int)(base)))

/**
 * @brief Get the value of CLKO2_DIS.
 * Modulator Clock Output 2 Disable
 * 0b - CLKO2 is enabled when MEN is asserted.
 * 1b - CLKO2 is disabled.
 * @param pSdadc the base address of the SDADC instance.

 * @return uint32_t the value of CLKO2_DIS.
 */
LOCAL_INLINE uint32_t SDADC_HWA_GetCLKO2_DIS(const SDADC_Type *const pSdadc)
{
    uint32_t u32TmpVal = (pSdadc->CTRL & SDADC_CTRL_CLKO2_DIS_MASK) >> SDADC_CTRL_CLKO2_DIS_SHIFT;
    return u32TmpVal;
}

/**
 * @brief Set CLKO2_DIS.
 * Modulator Clock Output 2 Disable
 * 0b - CLKO2 is enabled when MEN is asserted.
 * 1b - CLKO2 is disabled.
 * @param pSdadc the base address of the SDADC instance.

 * @param uint32_t u32Value CLKO2_DIS value.
 */
LOCAL_INLINE void SDADC_HWA_SetCLKO2_DIS(SDADC_Type *const pSdadc, uint32_t u32Value)
{
    pSdadc->CTRL = (pSdadc->CTRL & ~SDADC_CTRL_CLKO2_DIS_MASK) | SDADC_CTRL_CLKO2_DIS(u32Value);
}

/**
 * @brief Get the value of CLKO1_DIS.
 * Modulator Clock Output 1 Disable
 * 0b - CLKO1 is enabled when MEN is asserted.
 * 1b - CLKO1 is disabled.
 * @param pSdadc the base address of the SDADC instance.

 * @return uint32_t the value of CLKO1_DIS.
 */
LOCAL_INLINE uint32_t SDADC_HWA_GetCLKO1_DIS(const SDADC_Type *const pSdadc)
{
    uint32_t u32TmpVal = (pSdadc->CTRL & SDADC_CTRL_CLKO1_DIS_MASK) >> SDADC_CTRL_CLKO1_DIS_SHIFT;
    return u32TmpVal;
}

/**
 * @brief Set CLKO1_DIS.
 * Modulator Clock Output 1 Disable
 * 0b - CLKO1 is enabled when MEN is asserted.
 * 1b - CLKO1 is disabled.
 * @param pSdadc the base address of the SDADC instance.

 * @param uint32_t u32Value CLKO1_DIS value.
 */
LOCAL_INLINE void SDADC_HWA_SetCLKO1_DIS(SDADC_Type *const pSdadc, uint32_t u32Value)
{
    pSdadc->CTRL = (pSdadc->CTRL & ~SDADC_CTRL_CLKO1_DIS_MASK) | SDADC_CTRL_CLKO1_DIS(u32Value);
}

/**
 * @brief Get the value of CLKO0_DIS.
 * Modulator Clock Output 0 Disable
 * 0b - CLKO0 is enabled when MEN is asserted.
 * 1b - CLKO0 is disabled.
 * @param pSdadc the base address of the SDADC instance.

 * @return uint32_t the value of CLKO0_DIS.
 */
LOCAL_INLINE uint32_t SDADC_HWA_GetCLKO0_DIS(const SDADC_Type *const pSdadc)
{
    uint32_t u32TmpVal = (pSdadc->CTRL & SDADC_CTRL_CLKO0_DIS_MASK) >> SDADC_CTRL_CLKO0_DIS_SHIFT;
    return u32TmpVal;
}

/**
 * @brief Set CLKO0_DIS.
 * Modulator Clock Output 0 Disable
 * 0b - CLKO0 is enabled when MEN is asserted.
 * 1b - CLKO0 is disabled.
 * @param pSdadc the base address of the SDADC instance.

 * @param uint32_t u32Value CLKO0_DIS value.
 */
LOCAL_INLINE void SDADC_HWA_SetCLKO0_DIS(SDADC_Type *const pSdadc, uint32_t u32Value)
{
    pSdadc->CTRL = (pSdadc->CTRL & ~SDADC_CTRL_CLKO0_DIS_MASK) | SDADC_CTRL_CLKO0_DIS(u32Value);
}

/**
 * @brief Get the value of PRESCALE.
 * PRE_DIV Divider Value
 * 00b - No prescale.
 * 01b - Divided by 2.
 * 10b - Divided by 4.
 * 11b - Divided by 8.
 * @param pSdadc the base address of the SDADC instance.

 * @return uint32_t the value of PRESCALE.
 */
LOCAL_INLINE uint32_t SDADC_HWA_GetPRESCALE(const SDADC_Type *const pSdadc)
{
    uint32_t u32TmpVal = (pSdadc->CTRL & SDADC_CTRL_PRESCALE_MASK) >> SDADC_CTRL_PRESCALE_SHIFT;
    return u32TmpVal;
}

/**
 * @brief Set PRESCALE.
 * PRE_DIV Divider Value
 * 00b - No prescale.
 * 01b - Divided by 2.
 * 10b - Divided by 4.
 * 11b - Divided by 8.
 * @param pSdadc the base address of the SDADC instance.

 * @param uint32_t u32Value PRESCALE value.
 */
LOCAL_INLINE void SDADC_HWA_SetPRESCALE(SDADC_Type *const pSdadc, uint32_t u32Value)
{
    pSdadc->CTRL = (pSdadc->CTRL & ~SDADC_CTRL_PRESCALE_MASK) | SDADC_CTRL_PRESCALE(u32Value);
}

/**
 * @brief Get the value of MCLK_DIV.
 * DIV Divider Value
 * The (MCLK_DIV+1) sets the clock divider ratio for DIV block.
 * The minimum value MCLK_DIV is 1.
 * @param pSdadc the base address of the SDADC instance.

 * @return uint32_t the value of MCLK_DIV.
 */
LOCAL_INLINE uint32_t SDADC_HWA_GetMCLK_DIV(const SDADC_Type *const pSdadc)
{
    uint32_t u32TmpVal = (pSdadc->CTRL & SDADC_CTRL_MCLK_DIV_MASK) >> SDADC_CTRL_MCLK_DIV_SHIFT;
    return u32TmpVal;
}

/**
 * @brief Set MCLK_DIV.
 * DIV Divider Value
 * The (MCLK_DIV+1) sets the clock divider ratio for DIV block.
 * The minimum value MCLK_DIV is 1.
 * @param pSdadc the base address of the SDADC instance.

 * @param uint32_t u32Value MCLK_DIV value.
 */
LOCAL_INLINE void SDADC_HWA_SetMCLK_DIV(SDADC_Type *const pSdadc, uint32_t u32Value)
{
    pSdadc->CTRL = (pSdadc->CTRL & ~SDADC_CTRL_MCLK_DIV_MASK) | SDADC_CTRL_MCLK_DIV(u32Value);
}

/**
 * @brief Get the value of MEN.
 * Main Enable
 * Setting this bit enables all Function block simultaneously if CHEN and corresponding enable bit are asserted.
 * 0b - All function blocks are disabled.
 * 1b - All function blocks are enabled simultaneously.
 * @param pSdadc the base address of the SDADC instance.

 * @return uint32_t the value of MEN.
 */
LOCAL_INLINE uint32_t SDADC_HWA_GetMEN(const SDADC_Type *const pSdadc)
{
    uint32_t u32TmpVal = (pSdadc->CTRL & SDADC_CTRL_MEN_MASK) >> SDADC_CTRL_MEN_SHIFT;
    return u32TmpVal;
}

/**
 * @brief Set MEN.
 * Main Enable
 * Setting this bit enables all Function block simultaneously if CHEN and corresponding enable bit are asserted.
 * 0b - All function blocks are disabled.
 * 1b - All function blocks are enabled simultaneously.
 * @param pSdadc the base address of the SDADC instance.

 * @param uint32_t u32Value MEN value.
 */
LOCAL_INLINE void SDADC_HWA_SetMEN(SDADC_Type *const pSdadc, uint32_t u32Value)
{
    pSdadc->CTRL = (pSdadc->CTRL & ~SDADC_CTRL_MEN_MASK) | SDADC_CTRL_MEN(u32Value);
}

/**
 * @brief Get the value of MENSEL.
 * Main Enable Selection
 * Setting this bit to select main enable(MEN) from an enable from external of SDADC IP. By this way, all SDADC in a system can share one main enable and can be enable at the same time.
 * 0b - Use internal MEN.
 * 1b - Use external MEN.
 * @param pSdadc the base address of the SDADC instance.

 * @return uint32_t the value of MENSEL.
 */
LOCAL_INLINE uint32_t SDADC_HWA_GetMENSEL(const SDADC_Type *const pSdadc)
{
    uint32_t u32TmpVal = (pSdadc->CTRL & SDADC_CTRL_MENSEL_MASK) >> SDADC_CTRL_MENSEL_SHIFT;
    return u32TmpVal;
}

/**
 * @brief Set MENSEL.
 * Main Enable Selection
 * Setting this bit to select main enable(MEN) from an enable from external of SDADC IP. By this way, all SDADC in a system can share one main enable and can be enable at the same time.
 * 0b - Use internal MEN.
 * 1b - Use external MEN.
 * @param pSdadc the base address of the SDADC instance.

 * @param uint32_t u32Value MENSEL value.
 */
LOCAL_INLINE void SDADC_HWA_SetMENSEL(SDADC_Type *const pSdadc, uint32_t u32Value)
{
    pSdadc->CTRL = (pSdadc->CTRL & ~SDADC_CTRL_MENSEL_MASK) | SDADC_CTRL_MENSEL(u32Value);
}

/**
 * @brief Get the value of RESET.
 * Software Reset
 * Used to reset all function blocks (filters, short circuit detect, etc) and all flags or status.
 * Note, to reset all function domain, RESET must keep high at least 3 div_clk1 cycles.
 * 0b - No reset.
 * 1b - All function blocks are reset and disabled.
 * @param pSdadc the base address of the SDADC instance.

 * @return uint32_t the value of RESET.
 */
LOCAL_INLINE uint32_t SDADC_HWA_GetRESET(const SDADC_Type *const pSdadc)
{
    uint32_t u32TmpVal = (pSdadc->CTRL & SDADC_CTRL_RESET_MASK) >> SDADC_CTRL_RESET_SHIFT;
    return u32TmpVal;
}

/**
 * @brief Set RESET.
 * Software Reset
 * Used to reset all function blocks (filters, short circuit detect, etc) and all flags or status.
 * Note, to reset all function domain, RESET must keep high at least 3 div_clk1 cycles.
 * 0b - No reset.
 * 1b - All function blocks are reset and disabled.
 * @param pSdadc the base address of the SDADC instance.

 * @param uint32_t u32Value RESET value.
 */
LOCAL_INLINE void SDADC_HWA_SetRESET(SDADC_Type *const pSdadc, uint32_t u32Value)
{
    pSdadc->CTRL = (pSdadc->CTRL & ~SDADC_CTRL_RESET_MASK) | SDADC_CTRL_RESET(u32Value);
}

/**
 * @brief Get the value of DBGM.
 * Software Debug Mode Request
 * This bit is writable only when MEN is asserted.
 * 0b - SDADC is in Normal Mode.
 * 1b - SDADC is in Debug Mode.
 * @param pSdadc the base address of the SDADC instance.

 * @return uint32_t the value of DBGM.
 */
LOCAL_INLINE uint32_t SDADC_HWA_GetDBGM(const SDADC_Type *const pSdadc)
{
    uint32_t u32TmpVal = (pSdadc->CTRL & SDADC_CTRL_DBGM_MASK) >> SDADC_CTRL_DBGM_SHIFT;
    return u32TmpVal;
}

/**
 * @brief Set DBGM.
 * Software Debug Mode Request
 * This bit is writable only when MEN is asserted.
 * 0b - SDADC is in Normal Mode.
 * 1b - SDADC is in Debug Mode.
 * @param pSdadc the base address of the SDADC instance.

 * @param uint32_t u32Value DBGM value.
 */
LOCAL_INLINE void SDADC_HWA_SetDBGM(SDADC_Type *const pSdadc, uint32_t u32Value)
{
    pSdadc->CTRL = (pSdadc->CTRL & ~SDADC_CTRL_DBGM_MASK) | SDADC_CTRL_DBGM(u32Value);
}

/**
 * @brief Get the value of DBGE.
 * Module Enable in Debug Mode
 * Enables/disables the SDADC operation in Debug mode.
 * 0b - SDADC is enabled in debug mode.
 * 1b - SDADC is disabled in debug mode. Need trigger again for new conversion.
 * @param pSdadc the base address of the SDADC instance.

 * @return uint32_t the value of DBGE.
 */
LOCAL_INLINE uint32_t SDADC_HWA_GetDBGE(const SDADC_Type *const pSdadc)
{
    uint32_t u32TmpVal = (pSdadc->CTRL & SDADC_CTRL_DBGE_MASK) >> SDADC_CTRL_DBGE_SHIFT;
    return u32TmpVal;
}

/**
 * @brief Set DBGE.
 * Module Enable in Debug Mode
 * Enables/disables the SDADC operation in Debug mode.
 * 0b - SDADC is enabled in debug mode.
 * 1b - SDADC is disabled in debug mode. Need trigger again for new conversion.
 * @param pSdadc the base address of the SDADC instance.

 * @param uint32_t u32Value DBGE value.
 */
LOCAL_INLINE void SDADC_HWA_SetDBGE(SDADC_Type *const pSdadc, uint32_t u32Value)
{
    pSdadc->CTRL = (pSdadc->CTRL & ~SDADC_CTRL_DBGE_MASK) | SDADC_CTRL_DBGE(u32Value);
}

/**
 * @brief Get the value of STRIG2.
 * Software Trigger for Filter Channel 2
 * @param pSdadc the base address of the SDADC instance.

 * @return uint32_t the value of STRIG2.
 */
LOCAL_INLINE uint32_t SDADC_HWA_GetSTRIG2(const SDADC_Type *const pSdadc)
{
    uint32_t u32TmpVal = (pSdadc->CTRL & SDADC_CTRL_STRIG2_MASK) >> SDADC_CTRL_STRIG2_SHIFT;
    return u32TmpVal;
}

/**
 * @brief Set STRIG2.
 * Software Trigger for Filter Channel 2
 * @param pSdadc the base address of the SDADC instance.

 * @param uint32_t u32Value STRIG2 value.
 */
LOCAL_INLINE void SDADC_HWA_SetSTRIG2(SDADC_Type *const pSdadc, uint32_t u32Value)
{
    pSdadc->CTRL = (pSdadc->CTRL & ~SDADC_CTRL_STRIG2_MASK) | SDADC_CTRL_STRIG2(u32Value);
}

/**
 * @brief Get the value of STRIG1.
 * Software Trigger for Filter Channel 1
 * @param pSdadc the base address of the SDADC instance.

 * @return uint32_t the value of STRIG1.
 */
LOCAL_INLINE uint32_t SDADC_HWA_GetSTRIG1(const SDADC_Type *const pSdadc)
{
    uint32_t u32TmpVal = (pSdadc->CTRL & SDADC_CTRL_STRIG1_MASK) >> SDADC_CTRL_STRIG1_SHIFT;
    return u32TmpVal;
}

/**
 * @brief Set STRIG1.
 * Software Trigger for Filter Channel 1
 * @param pSdadc the base address of the SDADC instance.

 * @param uint32_t u32Value STRIG1 value.
 */
LOCAL_INLINE void SDADC_HWA_SetSTRIG1(SDADC_Type *const pSdadc, uint32_t u32Value)
{
    pSdadc->CTRL = (pSdadc->CTRL & ~SDADC_CTRL_STRIG1_MASK) | SDADC_CTRL_STRIG1(u32Value);
}

/**
 * @brief Get the value of STRIG0.
 * Software Trigger for Filter Channel 0
 * @param pSdadc the base address of the SDADC instance.

 * @return uint32_t the value of STRIG0.
 */
LOCAL_INLINE uint32_t SDADC_HWA_GetSTRIG0(const SDADC_Type *const pSdadc)
{
    uint32_t u32TmpVal = (pSdadc->CTRL & SDADC_CTRL_STRIG0_MASK) >> SDADC_CTRL_STRIG0_SHIFT;
    return u32TmpVal;
}

/**
 * @brief Set STRIG0.
 * Software Trigger for Filter Channel 0
 * @param pSdadc the base address of the SDADC instance.

 * @param uint32_t u32Value STRIG0 value.
 */
LOCAL_INLINE void SDADC_HWA_SetSTRIG0(SDADC_Type *const pSdadc, uint32_t u32Value)
{
    pSdadc->CTRL = (pSdadc->CTRL & ~SDADC_CTRL_STRIG0_MASK) | SDADC_CTRL_STRIG0(u32Value);
}

/**
 * @brief Get the value of ZCDIE2.
 * Filter Channel 2 Zero Cross Detected Interrupt Enable
 * 0b - The interrupt is disabled.
 * 1b - The interrupt is enabled.
 * @param pSdadc the base address of the SDADC instance.

 * @return uint32_t the value of ZCDIE2.
 */
LOCAL_INLINE uint32_t SDADC_HWA_GetZCDIE2(const SDADC_Type *const pSdadc)
{
    uint32_t u32TmpVal = (pSdadc->NIER & SDADC_NIER_ZCDIE2_MASK) >> SDADC_NIER_ZCDIE2_SHIFT;
    return u32TmpVal;
}

/**
 * @brief Set ZCDIE2.
 * Filter Channel 2 Zero Cross Detected Interrupt Enable
 * 0b - The interrupt is disabled.
 * 1b - The interrupt is enabled.
 * @param pSdadc the base address of the SDADC instance.

 * @param uint32_t u32Value ZCDIE2 value.
 */
LOCAL_INLINE void SDADC_HWA_SetZCDIE2(SDADC_Type *const pSdadc, uint32_t u32Value)
{
    pSdadc->NIER = (pSdadc->NIER & ~SDADC_NIER_ZCDIE2_MASK) | SDADC_NIER_ZCDIE2(u32Value);
}

/**
 * @brief Get the value of ZCDIE1.
 * Filter Channel 1 Zero Cross Detected Interrupt Enable
 * 0b - The interrupt is disabled.
 * 1b - The interrupt is enabled.
 * @param pSdadc the base address of the SDADC instance.

 * @return uint32_t the value of ZCDIE1.
 */
LOCAL_INLINE uint32_t SDADC_HWA_GetZCDIE1(const SDADC_Type *const pSdadc)
{
    uint32_t u32TmpVal = (pSdadc->NIER & SDADC_NIER_ZCDIE1_MASK) >> SDADC_NIER_ZCDIE1_SHIFT;
    return u32TmpVal;
}

/**
 * @brief Set ZCDIE1.
 * Filter Channel 1 Zero Cross Detected Interrupt Enable
 * 0b - The interrupt is disabled.
 * 1b - The interrupt is enabled.
 * @param pSdadc the base address of the SDADC instance.

 * @param uint32_t u32Value ZCDIE1 value.
 */
LOCAL_INLINE void SDADC_HWA_SetZCDIE1(SDADC_Type *const pSdadc, uint32_t u32Value)
{
    pSdadc->NIER = (pSdadc->NIER & ~SDADC_NIER_ZCDIE1_MASK) | SDADC_NIER_ZCDIE1(u32Value);
}

/**
 * @brief Get the value of ZCDIE0.
 * Filter Channel 0Zero Cross Detected Interrupt Enable
 * 0b - The interrupt is disabled.
 * 1b - The interrupt is enabled.
 * @param pSdadc the base address of the SDADC instance.

 * @return uint32_t the value of ZCDIE0.
 */
LOCAL_INLINE uint32_t SDADC_HWA_GetZCDIE0(const SDADC_Type *const pSdadc)
{
    uint32_t u32TmpVal = (pSdadc->NIER & SDADC_NIER_ZCDIE0_MASK) >> SDADC_NIER_ZCDIE0_SHIFT;
    return u32TmpVal;
}

/**
 * @brief Set ZCDIE0.
 * Filter Channel 0Zero Cross Detected Interrupt Enable
 * 0b - The interrupt is disabled.
 * 1b - The interrupt is enabled.
 * @param pSdadc the base address of the SDADC instance.

 * @param uint32_t u32Value ZCDIE0 value.
 */
LOCAL_INLINE void SDADC_HWA_SetZCDIE0(SDADC_Type *const pSdadc, uint32_t u32Value)
{
    pSdadc->NIER = (pSdadc->NIER & ~SDADC_NIER_ZCDIE0_MASK) | SDADC_NIER_ZCDIE0(u32Value);
}

/**
 * @brief Get the value of FRDYIE2.
 * Filter Channel 2 FIFO Data Ready Interrupt Enable
 * 0b - The interrupt is disabled.
 * 1b - The interrupt is enabled.
 * @param pSdadc the base address of the SDADC instance.

 * @return uint32_t the value of FRDYIE2.
 */
LOCAL_INLINE uint32_t SDADC_HWA_GetFRDYIE2(const SDADC_Type *const pSdadc)
{
    uint32_t u32TmpVal = (pSdadc->NIER & SDADC_NIER_FRDYIE2_MASK) >> SDADC_NIER_FRDYIE2_SHIFT;
    return u32TmpVal;
}

/**
 * @brief Set FRDYIE2.
 * Filter Channel 2 FIFO Data Ready Interrupt Enable
 * 0b - The interrupt is disabled.
 * 1b - The interrupt is enabled.
 * @param pSdadc the base address of the SDADC instance.

 * @param uint32_t u32Value FRDYIE2 value.
 */
LOCAL_INLINE void SDADC_HWA_SetFRDYIE2(SDADC_Type *const pSdadc, uint32_t u32Value)
{
    pSdadc->NIER = (pSdadc->NIER & ~SDADC_NIER_FRDYIE2_MASK) | SDADC_NIER_FRDYIE2(u32Value);
}

/**
 * @brief Get the value of FRDYIE1.
 * Filter Channel 1 FIFO Data Ready Interrupt Enable
 * 0b - The interrupt is disabled.
 * 1b - The interrupt is enabled.
 * @param pSdadc the base address of the SDADC instance.

 * @return uint32_t the value of FRDYIE1.
 */
LOCAL_INLINE uint32_t SDADC_HWA_GetFRDYIE1(const SDADC_Type *const pSdadc)
{
    uint32_t u32TmpVal = (pSdadc->NIER & SDADC_NIER_FRDYIE1_MASK) >> SDADC_NIER_FRDYIE1_SHIFT;
    return u32TmpVal;
}

/**
 * @brief Set FRDYIE1.
 * Filter Channel 1 FIFO Data Ready Interrupt Enable
 * 0b - The interrupt is disabled.
 * 1b - The interrupt is enabled.
 * @param pSdadc the base address of the SDADC instance.

 * @param uint32_t u32Value FRDYIE1 value.
 */
LOCAL_INLINE void SDADC_HWA_SetFRDYIE1(SDADC_Type *const pSdadc, uint32_t u32Value)
{
    pSdadc->NIER = (pSdadc->NIER & ~SDADC_NIER_FRDYIE1_MASK) | SDADC_NIER_FRDYIE1(u32Value);
}

/**
 * @brief Get the value of FRDYIE0.
 * Filter Channel 0 FIFO Data Ready Interrupt Enable
 * 0b - The interrupt is disabled.
 * 1b - The interrupt is enabled.
 * @param pSdadc the base address of the SDADC instance.

 * @return uint32_t the value of FRDYIE0.
 */
LOCAL_INLINE uint32_t SDADC_HWA_GetFRDYIE0(const SDADC_Type *const pSdadc)
{
    uint32_t u32TmpVal = (pSdadc->NIER & SDADC_NIER_FRDYIE0_MASK) >> SDADC_NIER_FRDYIE0_SHIFT;
    return u32TmpVal;
}

/**
 * @brief Set FRDYIE0.
 * Filter Channel 0 FIFO Data Ready Interrupt Enable
 * 0b - The interrupt is disabled.
 * 1b - The interrupt is enabled.
 * @param pSdadc the base address of the SDADC instance.

 * @param uint32_t u32Value FRDYIE0 value.
 */
LOCAL_INLINE void SDADC_HWA_SetFRDYIE0(SDADC_Type *const pSdadc, uint32_t u32Value)
{
    pSdadc->NIER = (pSdadc->NIER & ~SDADC_NIER_FRDYIE0_MASK) | SDADC_NIER_FRDYIE0(u32Value);
}

/**
 * @brief Get the value of COCIE2.
 * Filter Channel 2 Conversion Complete Interrupt Enable
 * 0b - The interrupt is disabled.
 * 1b - The interrupt is enabled.
 * @param pSdadc the base address of the SDADC instance.

 * @return uint32_t the value of COCIE2.
 */
LOCAL_INLINE uint32_t SDADC_HWA_GetCOCIE2(const SDADC_Type *const pSdadc)
{
    uint32_t u32TmpVal = (pSdadc->NIER & SDADC_NIER_COCIE2_MASK) >> SDADC_NIER_COCIE2_SHIFT;
    return u32TmpVal;
}

/**
 * @brief Set COCIE2.
 * Filter Channel 2 Conversion Complete Interrupt Enable
 * 0b - The interrupt is disabled.
 * 1b - The interrupt is enabled.
 * @param pSdadc the base address of the SDADC instance.

 * @param uint32_t u32Value COCIE2 value.
 */
LOCAL_INLINE void SDADC_HWA_SetCOCIE2(SDADC_Type *const pSdadc, uint32_t u32Value)
{
    pSdadc->NIER = (pSdadc->NIER & ~SDADC_NIER_COCIE2_MASK) | SDADC_NIER_COCIE2(u32Value);
}

/**
 * @brief Get the value of COCIE1.
 * Filter Channel 1 Conversion Complete Interrupt Enable
 * 0b - The interrupt is disabled.
 * 1b - The interrupt is enabled.
 * @param pSdadc the base address of the SDADC instance.

 * @return uint32_t the value of COCIE1.
 */
LOCAL_INLINE uint32_t SDADC_HWA_GetCOCIE1(const SDADC_Type *const pSdadc)
{
    uint32_t u32TmpVal = (pSdadc->NIER & SDADC_NIER_COCIE1_MASK) >> SDADC_NIER_COCIE1_SHIFT;
    return u32TmpVal;
}

/**
 * @brief Set COCIE1.
 * Filter Channel 1 Conversion Complete Interrupt Enable
 * 0b - The interrupt is disabled.
 * 1b - The interrupt is enabled.
 * @param pSdadc the base address of the SDADC instance.

 * @param uint32_t u32Value COCIE1 value.
 */
LOCAL_INLINE void SDADC_HWA_SetCOCIE1(SDADC_Type *const pSdadc, uint32_t u32Value)
{
    pSdadc->NIER = (pSdadc->NIER & ~SDADC_NIER_COCIE1_MASK) | SDADC_NIER_COCIE1(u32Value);
}

/**
 * @brief Get the value of COCIE0.
 * Filter Channel 0 Conversion Complete Interrupt Enable
 * 0b - The interrupt is disabled.
 * 1b - The interrupt is enabled.
 * @param pSdadc the base address of the SDADC instance.

 * @return uint32_t the value of COCIE0.
 */
LOCAL_INLINE uint32_t SDADC_HWA_GetCOCIE0(const SDADC_Type *const pSdadc)
{
    uint32_t u32TmpVal = (pSdadc->NIER & SDADC_NIER_COCIE0_MASK) >> SDADC_NIER_COCIE0_SHIFT;
    return u32TmpVal;
}

/**
 * @brief Set COCIE0.
 * Filter Channel 0 Conversion Complete Interrupt Enable
 * 0b - The interrupt is disabled.
 * 1b - The interrupt is enabled.
 * @param pSdadc the base address of the SDADC instance.

 * @param uint32_t u32Value COCIE0 value.
 */
LOCAL_INLINE void SDADC_HWA_SetCOCIE0(SDADC_Type *const pSdadc, uint32_t u32Value)
{
    pSdadc->NIER = (pSdadc->NIER & ~SDADC_NIER_COCIE0_MASK) | SDADC_NIER_COCIE0(u32Value);
}

/**
 * @brief Get the value of HLMTIE2.
 * Filter Channel 2 High Limit Interrupt Enable
 * 0b - The interrupt is disabled.
 * 1b - The interrupt is enabled.
 * @param pSdadc the base address of the SDADC instance.

 * @return uint32_t the value of HLMTIE2.
 */
LOCAL_INLINE uint32_t SDADC_HWA_GetHLMTIE2(const SDADC_Type *const pSdadc)
{
    uint32_t u32TmpVal = (pSdadc->ABNIER0 & SDADC_ABNIER0_HLMTIE2_MASK) >> SDADC_ABNIER0_HLMTIE2_SHIFT;
    return u32TmpVal;
}

/**
 * @brief Set HLMTIE2.
 * Filter Channel 2 High Limit Interrupt Enable
 * 0b - The interrupt is disabled.
 * 1b - The interrupt is enabled.
 * @param pSdadc the base address of the SDADC instance.

 * @param uint32_t u32Value HLMTIE2 value.
 */
LOCAL_INLINE void SDADC_HWA_SetHLMTIE2(SDADC_Type *const pSdadc, uint32_t u32Value)
{
    pSdadc->ABNIER0 = (pSdadc->ABNIER0 & ~SDADC_ABNIER0_HLMTIE2_MASK) | SDADC_ABNIER0_HLMTIE2(u32Value);
}

/**
 * @brief Get the value of HLMTIE1.
 * Filter Channel 1 High Limit Interrupt Enable
 * 0b - The interrupt is disabled.
 * 1b - The interrupt is enabled.
 * @param pSdadc the base address of the SDADC instance.

 * @return uint32_t the value of HLMTIE1.
 */
LOCAL_INLINE uint32_t SDADC_HWA_GetHLMTIE1(const SDADC_Type *const pSdadc)
{
    uint32_t u32TmpVal = (pSdadc->ABNIER0 & SDADC_ABNIER0_HLMTIE1_MASK) >> SDADC_ABNIER0_HLMTIE1_SHIFT;
    return u32TmpVal;
}

/**
 * @brief Set HLMTIE1.
 * Filter Channel 1 High Limit Interrupt Enable
 * 0b - The interrupt is disabled.
 * 1b - The interrupt is enabled.
 * @param pSdadc the base address of the SDADC instance.

 * @param uint32_t u32Value HLMTIE1 value.
 */
LOCAL_INLINE void SDADC_HWA_SetHLMTIE1(SDADC_Type *const pSdadc, uint32_t u32Value)
{
    pSdadc->ABNIER0 = (pSdadc->ABNIER0 & ~SDADC_ABNIER0_HLMTIE1_MASK) | SDADC_ABNIER0_HLMTIE1(u32Value);
}

/**
 * @brief Get the value of HLMTIE0.
 * Filter Channel 0 High Limit Interrupt Enable
 * 0b - The interrupt is disabled.
 * 1b - The interrupt is enabled.
 * @param pSdadc the base address of the SDADC instance.

 * @return uint32_t the value of HLMTIE0.
 */
LOCAL_INLINE uint32_t SDADC_HWA_GetHLMTIE0(const SDADC_Type *const pSdadc)
{
    uint32_t u32TmpVal = (pSdadc->ABNIER0 & SDADC_ABNIER0_HLMTIE0_MASK) >> SDADC_ABNIER0_HLMTIE0_SHIFT;
    return u32TmpVal;
}

/**
 * @brief Set HLMTIE0.
 * Filter Channel 0 High Limit Interrupt Enable
 * 0b - The interrupt is disabled.
 * 1b - The interrupt is enabled.
 * @param pSdadc the base address of the SDADC instance.

 * @param uint32_t u32Value HLMTIE0 value.
 */
LOCAL_INLINE void SDADC_HWA_SetHLMTIE0(SDADC_Type *const pSdadc, uint32_t u32Value)
{
    pSdadc->ABNIER0 = (pSdadc->ABNIER0 & ~SDADC_ABNIER0_HLMTIE0_MASK) | SDADC_ABNIER0_HLMTIE0(u32Value);
}

/**
 * @brief Get the value of LLMTIE2.
 * Filter Channel 2 Low Limit Interrupt Enable
 * 0b - The interrupt is disabled.
 * 1b - The interrupt is enabled.
 * @param pSdadc the base address of the SDADC instance.

 * @return uint32_t the value of LLMTIE2.
 */
LOCAL_INLINE uint32_t SDADC_HWA_GetLLMTIE2(const SDADC_Type *const pSdadc)
{
    uint32_t u32TmpVal = (pSdadc->ABNIER0 & SDADC_ABNIER0_LLMTIE2_MASK) >> SDADC_ABNIER0_LLMTIE2_SHIFT;
    return u32TmpVal;
}

/**
 * @brief Set LLMTIE2.
 * Filter Channel 2 Low Limit Interrupt Enable
 * 0b - The interrupt is disabled.
 * 1b - The interrupt is enabled.
 * @param pSdadc the base address of the SDADC instance.

 * @param uint32_t u32Value LLMTIE2 value.
 */
LOCAL_INLINE void SDADC_HWA_SetLLMTIE2(SDADC_Type *const pSdadc, uint32_t u32Value)
{
    pSdadc->ABNIER0 = (pSdadc->ABNIER0 & ~SDADC_ABNIER0_LLMTIE2_MASK) | SDADC_ABNIER0_LLMTIE2(u32Value);
}

/**
 * @brief Get the value of LLMTIE1.
 * Filter Channel 1 Low Limit Interrupt Enable
 * 0b - The interrupt is disabled.
 * 1b - The interrupt is enabled.
 * @param pSdadc the base address of the SDADC instance.

 * @return uint32_t the value of LLMTIE1.
 */
LOCAL_INLINE uint32_t SDADC_HWA_GetLLMTIE1(const SDADC_Type *const pSdadc)
{
    uint32_t u32TmpVal = (pSdadc->ABNIER0 & SDADC_ABNIER0_LLMTIE1_MASK) >> SDADC_ABNIER0_LLMTIE1_SHIFT;
    return u32TmpVal;
}

/**
 * @brief Set LLMTIE1.
 * Filter Channel 1 Low Limit Interrupt Enable
 * 0b - The interrupt is disabled.
 * 1b - The interrupt is enabled.
 * @param pSdadc the base address of the SDADC instance.

 * @param uint32_t u32Value LLMTIE1 value.
 */
LOCAL_INLINE void SDADC_HWA_SetLLMTIE1(SDADC_Type *const pSdadc, uint32_t u32Value)
{
    pSdadc->ABNIER0 = (pSdadc->ABNIER0 & ~SDADC_ABNIER0_LLMTIE1_MASK) | SDADC_ABNIER0_LLMTIE1(u32Value);
}

/**
 * @brief Get the value of LLMTIE0.
 * Filter Channel 0 Low Limit Interrupt Enable
 * 0b - The interrupt is disabled.
 * 1b - The interrupt is enabled.
 * @param pSdadc the base address of the SDADC instance.

 * @return uint32_t the value of LLMTIE0.
 */
LOCAL_INLINE uint32_t SDADC_HWA_GetLLMTIE0(const SDADC_Type *const pSdadc)
{
    uint32_t u32TmpVal = (pSdadc->ABNIER0 & SDADC_ABNIER0_LLMTIE0_MASK) >> SDADC_ABNIER0_LLMTIE0_SHIFT;
    return u32TmpVal;
}

/**
 * @brief Set LLMTIE0.
 * Filter Channel 0 Low Limit Interrupt Enable
 * 0b - The interrupt is disabled.
 * 1b - The interrupt is enabled.
 * @param pSdadc the base address of the SDADC instance.

 * @param uint32_t u32Value LLMTIE0 value.
 */
LOCAL_INLINE void SDADC_HWA_SetLLMTIE0(SDADC_Type *const pSdadc, uint32_t u32Value)
{
    pSdadc->ABNIER0 = (pSdadc->ABNIER0 & ~SDADC_ABNIER0_LLMTIE0_MASK) | SDADC_ABNIER0_LLMTIE0(u32Value);
}

/**
 * @brief Get the value of WLMTIE2.
 * Filter Channel 2 Window Limit Interrupt Enable
 * 0b - The interrupt is disabled.
 * 1b - The interrupt is enabled.
 * @param pSdadc the base address of the SDADC instance.

 * @return uint32_t the value of WLMTIE2.
 */
LOCAL_INLINE uint32_t SDADC_HWA_GetWLMTIE2(const SDADC_Type *const pSdadc)
{
    uint32_t u32TmpVal = (pSdadc->ABNIER0 & SDADC_ABNIER0_WLMTIE2_MASK) >> SDADC_ABNIER0_WLMTIE2_SHIFT;
    return u32TmpVal;
}

/**
 * @brief Set WLMTIE2.
 * Filter Channel 2 Window Limit Interrupt Enable
 * 0b - The interrupt is disabled.
 * 1b - The interrupt is enabled.
 * @param pSdadc the base address of the SDADC instance.

 * @param uint32_t u32Value WLMTIE2 value.
 */
LOCAL_INLINE void SDADC_HWA_SetWLMTIE2(SDADC_Type *const pSdadc, uint32_t u32Value)
{
    pSdadc->ABNIER0 = (pSdadc->ABNIER0 & ~SDADC_ABNIER0_WLMTIE2_MASK) | SDADC_ABNIER0_WLMTIE2(u32Value);
}

/**
 * @brief Get the value of WLMTIE1.
 * Filter Channel 1 Window Limit Interrupt Enable
 * 0b - The interrupt is disabled.
 * 1b - The interrupt is enabled.
 * @param pSdadc the base address of the SDADC instance.

 * @return uint32_t the value of WLMTIE1.
 */
LOCAL_INLINE uint32_t SDADC_HWA_GetWLMTIE1(const SDADC_Type *const pSdadc)
{
    uint32_t u32TmpVal = (pSdadc->ABNIER0 & SDADC_ABNIER0_WLMTIE1_MASK) >> SDADC_ABNIER0_WLMTIE1_SHIFT;
    return u32TmpVal;
}

/**
 * @brief Set WLMTIE1.
 * Filter Channel 1 Window Limit Interrupt Enable
 * 0b - The interrupt is disabled.
 * 1b - The interrupt is enabled.
 * @param pSdadc the base address of the SDADC instance.

 * @param uint32_t u32Value WLMTIE1 value.
 */
LOCAL_INLINE void SDADC_HWA_SetWLMTIE1(SDADC_Type *const pSdadc, uint32_t u32Value)
{
    pSdadc->ABNIER0 = (pSdadc->ABNIER0 & ~SDADC_ABNIER0_WLMTIE1_MASK) | SDADC_ABNIER0_WLMTIE1(u32Value);
}

/**
 * @brief Get the value of WLMTIE0.
 * Filter Channel 0 Window Limit Interrupt Enable
 * 0b - The interrupt is disabled.
 * 1b - The interrupt is enabled.
 * @param pSdadc the base address of the SDADC instance.

 * @return uint32_t the value of WLMTIE0.
 */
LOCAL_INLINE uint32_t SDADC_HWA_GetWLMTIE0(const SDADC_Type *const pSdadc)
{
    uint32_t u32TmpVal = (pSdadc->ABNIER0 & SDADC_ABNIER0_WLMTIE0_MASK) >> SDADC_ABNIER0_WLMTIE0_SHIFT;
    return u32TmpVal;
}

/**
 * @brief Set WLMTIE0.
 * Filter Channel 0 Window Limit Interrupt Enable
 * 0b - The interrupt is disabled.
 * 1b - The interrupt is enabled.
 * @param pSdadc the base address of the SDADC instance.

 * @param uint32_t u32Value WLMTIE0 value.
 */
LOCAL_INLINE void SDADC_HWA_SetWLMTIE0(SDADC_Type *const pSdadc, uint32_t u32Value)
{
    pSdadc->ABNIER0 = (pSdadc->ABNIER0 & ~SDADC_ABNIER0_WLMTIE0_MASK) | SDADC_ABNIER0_WLMTIE0(u32Value);
}

/**
 * @brief Get the value of SCDIE2.
 * Filter Channel 2 Short Circuit Detected Interrupt Enable
 * 0b - The interrupt is disabled.
 * 1b - The interrupt is enabled.
 * @param pSdadc the base address of the SDADC instance.

 * @return uint32_t the value of SCDIE2.
 */
LOCAL_INLINE uint32_t SDADC_HWA_GetSCDIE2(const SDADC_Type *const pSdadc)
{
    uint32_t u32TmpVal = (pSdadc->ABNIER0 & SDADC_ABNIER0_SCDIE2_MASK) >> SDADC_ABNIER0_SCDIE2_SHIFT;
    return u32TmpVal;
}

/**
 * @brief Set SCDIE2.
 * Filter Channel 2 Short Circuit Detected Interrupt Enable
 * 0b - The interrupt is disabled.
 * 1b - The interrupt is enabled.
 * @param pSdadc the base address of the SDADC instance.

 * @param uint32_t u32Value SCDIE2 value.
 */
LOCAL_INLINE void SDADC_HWA_SetSCDIE2(SDADC_Type *const pSdadc, uint32_t u32Value)
{
    pSdadc->ABNIER0 = (pSdadc->ABNIER0 & ~SDADC_ABNIER0_SCDIE2_MASK) | SDADC_ABNIER0_SCDIE2(u32Value);
}

/**
 * @brief Get the value of SCDIE1.
 * Filter Channel 1 Short Circuit Detected Interrupt Enable
 * 0b - The interrupt is disabled.
 * 1b - The interrupt is enabled.
 * @param pSdadc the base address of the SDADC instance.

 * @return uint32_t the value of SCDIE1.
 */
LOCAL_INLINE uint32_t SDADC_HWA_GetSCDIE1(const SDADC_Type *const pSdadc)
{
    uint32_t u32TmpVal = (pSdadc->ABNIER0 & SDADC_ABNIER0_SCDIE1_MASK) >> SDADC_ABNIER0_SCDIE1_SHIFT;
    return u32TmpVal;
}

/**
 * @brief Set SCDIE1.
 * Filter Channel 1 Short Circuit Detected Interrupt Enable
 * 0b - The interrupt is disabled.
 * 1b - The interrupt is enabled.
 * @param pSdadc the base address of the SDADC instance.

 * @param uint32_t u32Value SCDIE1 value.
 */
LOCAL_INLINE void SDADC_HWA_SetSCDIE1(SDADC_Type *const pSdadc, uint32_t u32Value)
{
    pSdadc->ABNIER0 = (pSdadc->ABNIER0 & ~SDADC_ABNIER0_SCDIE1_MASK) | SDADC_ABNIER0_SCDIE1(u32Value);
}

/**
 * @brief Get the value of SCDIE0.
 * Filter Channel 0 Short Circuit Detected Interrupt Enable
 * 0b - The interrupt is disabled.
 * 1b - The interrupt is enabled.
 * @param pSdadc the base address of the SDADC instance.

 * @return uint32_t the value of SCDIE0.
 */
LOCAL_INLINE uint32_t SDADC_HWA_GetSCDIE0(const SDADC_Type *const pSdadc)
{
    uint32_t u32TmpVal = (pSdadc->ABNIER0 & SDADC_ABNIER0_SCDIE0_MASK) >> SDADC_ABNIER0_SCDIE0_SHIFT;
    return u32TmpVal;
}

/**
 * @brief Set SCDIE0.
 * Filter Channel 0 Short Circuit Detected Interrupt Enable
 * 0b - The interrupt is disabled.
 * 1b - The interrupt is enabled.
 * @param pSdadc the base address of the SDADC instance.

 * @param uint32_t u32Value SCDIE0 value.
 */
LOCAL_INLINE void SDADC_HWA_SetSCDIE0(SDADC_Type *const pSdadc, uint32_t u32Value)
{
    pSdadc->ABNIER0 = (pSdadc->ABNIER0 & ~SDADC_ABNIER0_SCDIE0_MASK) | SDADC_ABNIER0_SCDIE0(u32Value);
}

/**
 * @brief Get the value of SATIE2.
 * Filter Channel 2 Saturation Interrupt Enable
 * 0b - The interrupt is disabled.
 * 1b - The interrupt is enabled.
 * @param pSdadc the base address of the SDADC instance.

 * @return uint32_t the value of SATIE2.
 */
LOCAL_INLINE uint32_t SDADC_HWA_GetSATIE2(const SDADC_Type *const pSdadc)
{
    uint32_t u32TmpVal = (pSdadc->ABNIER1 & SDADC_ABNIER1_SATIE2_MASK) >> SDADC_ABNIER1_SATIE2_SHIFT;
    return u32TmpVal;
}

/**
 * @brief Set SATIE2.
 * Filter Channel 2 Saturation Interrupt Enable
 * 0b - The interrupt is disabled.
 * 1b - The interrupt is enabled.
 * @param pSdadc the base address of the SDADC instance.

 * @param uint32_t u32Value SATIE2 value.
 */
LOCAL_INLINE void SDADC_HWA_SetSATIE2(SDADC_Type *const pSdadc, uint32_t u32Value)
{
    pSdadc->ABNIER1 = (pSdadc->ABNIER1 & ~SDADC_ABNIER1_SATIE2_MASK) | SDADC_ABNIER1_SATIE2(u32Value);
}

/**
 * @brief Get the value of SATIE1.
 * Filter Channel 1 Saturation Interrupt Enable
 * 0b - The interrupt is disabled.
 * 1b - The interrupt is enabled.
 * @param pSdadc the base address of the SDADC instance.

 * @return uint32_t the value of SATIE1.
 */
LOCAL_INLINE uint32_t SDADC_HWA_GetSATIE1(const SDADC_Type *const pSdadc)
{
    uint32_t u32TmpVal = (pSdadc->ABNIER1 & SDADC_ABNIER1_SATIE1_MASK) >> SDADC_ABNIER1_SATIE1_SHIFT;
    return u32TmpVal;
}

/**
 * @brief Set SATIE1.
 * Filter Channel 1 Saturation Interrupt Enable
 * 0b - The interrupt is disabled.
 * 1b - The interrupt is enabled.
 * @param pSdadc the base address of the SDADC instance.

 * @param uint32_t u32Value SATIE1 value.
 */
LOCAL_INLINE void SDADC_HWA_SetSATIE1(SDADC_Type *const pSdadc, uint32_t u32Value)
{
    pSdadc->ABNIER1 = (pSdadc->ABNIER1 & ~SDADC_ABNIER1_SATIE1_MASK) | SDADC_ABNIER1_SATIE1(u32Value);
}

/**
 * @brief Get the value of SATIE0.
 * Filter Channel 0 Saturation Interrupt Enable
 * 0b - The interrupt is disabled.
 * 1b - The interrupt is enabled.
 * @param pSdadc the base address of the SDADC instance.

 * @return uint32_t the value of SATIE0.
 */
LOCAL_INLINE uint32_t SDADC_HWA_GetSATIE0(const SDADC_Type *const pSdadc)
{
    uint32_t u32TmpVal = (pSdadc->ABNIER1 & SDADC_ABNIER1_SATIE0_MASK) >> SDADC_ABNIER1_SATIE0_SHIFT;
    return u32TmpVal;
}

/**
 * @brief Set SATIE0.
 * Filter Channel 0 Saturation Interrupt Enable
 * 0b - The interrupt is disabled.
 * 1b - The interrupt is enabled.
 * @param pSdadc the base address of the SDADC instance.

 * @param uint32_t u32Value SATIE0 value.
 */
LOCAL_INLINE void SDADC_HWA_SetSATIE0(SDADC_Type *const pSdadc, uint32_t u32Value)
{
    pSdadc->ABNIER1 = (pSdadc->ABNIER1 & ~SDADC_ABNIER1_SATIE0_MASK) | SDADC_ABNIER1_SATIE0(u32Value);
}

/**
 * @brief Get the value of CADIE2.
 * Filter Channel 2 Clock Absence Interrupt Enable
 * 0b - The interrupt is disabled.
 * 1b - The interrupt is enabled.
 * @param pSdadc the base address of the SDADC instance.

 * @return uint32_t the value of CADIE2.
 */
LOCAL_INLINE uint32_t SDADC_HWA_GetCADIE2(const SDADC_Type *const pSdadc)
{
    uint32_t u32TmpVal = (pSdadc->ABNIER1 & SDADC_ABNIER1_CADIE2_MASK) >> SDADC_ABNIER1_CADIE2_SHIFT;
    return u32TmpVal;
}

/**
 * @brief Set CADIE2.
 * Filter Channel 2 Clock Absence Interrupt Enable
 * 0b - The interrupt is disabled.
 * 1b - The interrupt is enabled.
 * @param pSdadc the base address of the SDADC instance.

 * @param uint32_t u32Value CADIE2 value.
 */
LOCAL_INLINE void SDADC_HWA_SetCADIE2(SDADC_Type *const pSdadc, uint32_t u32Value)
{
    pSdadc->ABNIER1 = (pSdadc->ABNIER1 & ~SDADC_ABNIER1_CADIE2_MASK) | SDADC_ABNIER1_CADIE2(u32Value);
}

/**
 * @brief Get the value of CADIE1.
 * Filter Channel 1 Clock Absence Interrupt Enable
 * 0b - The interrupt is disabled.
 * 1b - The interrupt is enabled.
 * @param pSdadc the base address of the SDADC instance.

 * @return uint32_t the value of CADIE1.
 */
LOCAL_INLINE uint32_t SDADC_HWA_GetCADIE1(const SDADC_Type *const pSdadc)
{
    uint32_t u32TmpVal = (pSdadc->ABNIER1 & SDADC_ABNIER1_CADIE1_MASK) >> SDADC_ABNIER1_CADIE1_SHIFT;
    return u32TmpVal;
}

/**
 * @brief Set CADIE1.
 * Filter Channel 1 Clock Absence Interrupt Enable
 * 0b - The interrupt is disabled.
 * 1b - The interrupt is enabled.
 * @param pSdadc the base address of the SDADC instance.

 * @param uint32_t u32Value CADIE1 value.
 */
LOCAL_INLINE void SDADC_HWA_SetCADIE1(SDADC_Type *const pSdadc, uint32_t u32Value)
{
    pSdadc->ABNIER1 = (pSdadc->ABNIER1 & ~SDADC_ABNIER1_CADIE1_MASK) | SDADC_ABNIER1_CADIE1(u32Value);
}

/**
 * @brief Get the value of CADIE0.
 * Filter Channel 0 Clock Absence Interrupt Enable
 * 0b - The interrupt is disabled.
 * 1b - The interrupt is enabled.
 * @param pSdadc the base address of the SDADC instance.

 * @return uint32_t the value of CADIE0.
 */
LOCAL_INLINE uint32_t SDADC_HWA_GetCADIE0(const SDADC_Type *const pSdadc)
{
    uint32_t u32TmpVal = (pSdadc->ABNIER1 & SDADC_ABNIER1_CADIE0_MASK) >> SDADC_ABNIER1_CADIE0_SHIFT;
    return u32TmpVal;
}

/**
 * @brief Set CADIE0.
 * Filter Channel 0 Clock Absence Interrupt Enable
 * 0b - The interrupt is disabled.
 * 1b - The interrupt is enabled.
 * @param pSdadc the base address of the SDADC instance.

 * @param uint32_t u32Value CADIE0 value.
 */
LOCAL_INLINE void SDADC_HWA_SetCADIE0(SDADC_Type *const pSdadc, uint32_t u32Value)
{
    pSdadc->ABNIER1 = (pSdadc->ABNIER1 & ~SDADC_ABNIER1_CADIE0_MASK) | SDADC_ABNIER1_CADIE0(u32Value);
}

/**
 * @brief Get the value of FOVFIE2.
 * Filter Channel 2 FIFO Overflow Interrupt Enable
 * 0b - The interrupt is disabled.
 * 1b - The interrupt is enabled.
 * @param pSdadc the base address of the SDADC instance.

 * @return uint32_t the value of FOVFIE2.
 */
LOCAL_INLINE uint32_t SDADC_HWA_GetFOVFIE2(const SDADC_Type *const pSdadc)
{
    uint32_t u32TmpVal = (pSdadc->ABNIER1 & SDADC_ABNIER1_FOVFIE2_MASK) >> SDADC_ABNIER1_FOVFIE2_SHIFT;
    return u32TmpVal;
}

/**
 * @brief Set FOVFIE2.
 * Filter Channel 2 FIFO Overflow Interrupt Enable
 * 0b - The interrupt is disabled.
 * 1b - The interrupt is enabled.
 * @param pSdadc the base address of the SDADC instance.

 * @param uint32_t u32Value FOVFIE2 value.
 */
LOCAL_INLINE void SDADC_HWA_SetFOVFIE2(SDADC_Type *const pSdadc, uint32_t u32Value)
{
    pSdadc->ABNIER1 = (pSdadc->ABNIER1 & ~SDADC_ABNIER1_FOVFIE2_MASK) | SDADC_ABNIER1_FOVFIE2(u32Value);
}

/**
 * @brief Get the value of FOVFIE1.
 * Filter Channel 1 FIFO Overflow Interrupt Enable
 * 0b - The interrupt is disabled.
 * 1b - The interrupt is enabled.
 * @param pSdadc the base address of the SDADC instance.

 * @return uint32_t the value of FOVFIE1.
 */
LOCAL_INLINE uint32_t SDADC_HWA_GetFOVFIE1(const SDADC_Type *const pSdadc)
{
    uint32_t u32TmpVal = (pSdadc->ABNIER1 & SDADC_ABNIER1_FOVFIE1_MASK) >> SDADC_ABNIER1_FOVFIE1_SHIFT;
    return u32TmpVal;
}

/**
 * @brief Set FOVFIE1.
 * Filter Channel 1 FIFO Overflow Interrupt Enable
 * 0b - The interrupt is disabled.
 * 1b - The interrupt is enabled.
 * @param pSdadc the base address of the SDADC instance.

 * @param uint32_t u32Value FOVFIE1 value.
 */
LOCAL_INLINE void SDADC_HWA_SetFOVFIE1(SDADC_Type *const pSdadc, uint32_t u32Value)
{
    pSdadc->ABNIER1 = (pSdadc->ABNIER1 & ~SDADC_ABNIER1_FOVFIE1_MASK) | SDADC_ABNIER1_FOVFIE1(u32Value);
}

/**
 * @brief Get the value of FOVFIE0.
 * Filter Channel 0 FIFO Overflow Interrupt Enable
 * 0b - The interrupt is disabled.
 * 1b - The interrupt is enabled.
 * @param pSdadc the base address of the SDADC instance.

 * @return uint32_t the value of FOVFIE0.
 */
LOCAL_INLINE uint32_t SDADC_HWA_GetFOVFIE0(const SDADC_Type *const pSdadc)
{
    uint32_t u32TmpVal = (pSdadc->ABNIER1 & SDADC_ABNIER1_FOVFIE0_MASK) >> SDADC_ABNIER1_FOVFIE0_SHIFT;
    return u32TmpVal;
}

/**
 * @brief Set FOVFIE0.
 * Filter Channel 0 FIFO Overflow Interrupt Enable
 * 0b - The interrupt is disabled.
 * 1b - The interrupt is enabled.
 * @param pSdadc the base address of the SDADC instance.

 * @param uint32_t u32Value FOVFIE0 value.
 */
LOCAL_INLINE void SDADC_HWA_SetFOVFIE0(SDADC_Type *const pSdadc, uint32_t u32Value)
{
    pSdadc->ABNIER1 = (pSdadc->ABNIER1 & ~SDADC_ABNIER1_FOVFIE0_MASK) | SDADC_ABNIER1_FOVFIE0(u32Value);
}

/**
 * @brief Get the value of FUNFIE2.
 * Filter Channel 2 FIFO Underflow Interrupt Enable
 * 0b - The interrupt is disabled.
 * 1b - The interrupt is enabled.
 * @param pSdadc the base address of the SDADC instance.

 * @return uint32_t the value of FUNFIE2.
 */
LOCAL_INLINE uint32_t SDADC_HWA_GetFUNFIE2(const SDADC_Type *const pSdadc)
{
    uint32_t u32TmpVal = (pSdadc->ABNIER1 & SDADC_ABNIER1_FUNFIE2_MASK) >> SDADC_ABNIER1_FUNFIE2_SHIFT;
    return u32TmpVal;
}

/**
 * @brief Set FUNFIE2.
 * Filter Channel 2 FIFO Underflow Interrupt Enable
 * 0b - The interrupt is disabled.
 * 1b - The interrupt is enabled.
 * @param pSdadc the base address of the SDADC instance.

 * @param uint32_t u32Value FUNFIE2 value.
 */
LOCAL_INLINE void SDADC_HWA_SetFUNFIE2(SDADC_Type *const pSdadc, uint32_t u32Value)
{
    pSdadc->ABNIER1 = (pSdadc->ABNIER1 & ~SDADC_ABNIER1_FUNFIE2_MASK) | SDADC_ABNIER1_FUNFIE2(u32Value);
}

/**
 * @brief Get the value of FUNFIE1.
 * Filter Channel 1 FIFO Underflow Interrupt Enable
 * 0b - The interrupt is disabled.
 * 1b - The interrupt is enabled.
 * @param pSdadc the base address of the SDADC instance.

 * @return uint32_t the value of FUNFIE1.
 */
LOCAL_INLINE uint32_t SDADC_HWA_GetFUNFIE1(const SDADC_Type *const pSdadc)
{
    uint32_t u32TmpVal = (pSdadc->ABNIER1 & SDADC_ABNIER1_FUNFIE1_MASK) >> SDADC_ABNIER1_FUNFIE1_SHIFT;
    return u32TmpVal;
}

/**
 * @brief Set FUNFIE1.
 * Filter Channel 1 FIFO Underflow Interrupt Enable
 * 0b - The interrupt is disabled.
 * 1b - The interrupt is enabled.
 * @param pSdadc the base address of the SDADC instance.

 * @param uint32_t u32Value FUNFIE1 value.
 */
LOCAL_INLINE void SDADC_HWA_SetFUNFIE1(SDADC_Type *const pSdadc, uint32_t u32Value)
{
    pSdadc->ABNIER1 = (pSdadc->ABNIER1 & ~SDADC_ABNIER1_FUNFIE1_MASK) | SDADC_ABNIER1_FUNFIE1(u32Value);
}

/**
 * @brief Get the value of FUNFIE0.
 * Filter Channel 0 FIFO Underflow Interrupt Enable
 * 0b - The interrupt is disabled.
 * 1b - The interrupt is enabled.
 * @param pSdadc the base address of the SDADC instance.

 * @return uint32_t the value of FUNFIE0.
 */
LOCAL_INLINE uint32_t SDADC_HWA_GetFUNFIE0(const SDADC_Type *const pSdadc)
{
    uint32_t u32TmpVal = (pSdadc->ABNIER1 & SDADC_ABNIER1_FUNFIE0_MASK) >> SDADC_ABNIER1_FUNFIE0_SHIFT;
    return u32TmpVal;
}

/**
 * @brief Set FUNFIE0.
 * Filter Channel 0 FIFO Underflow Interrupt Enable
 * 0b - The interrupt is disabled.
 * 1b - The interrupt is enabled.
 * @param pSdadc the base address of the SDADC instance.

 * @param uint32_t u32Value FUNFIE0 value.
 */
LOCAL_INLINE void SDADC_HWA_SetFUNFIE0(SDADC_Type *const pSdadc, uint32_t u32Value)
{
    pSdadc->ABNIER1 = (pSdadc->ABNIER1 & ~SDADC_ABNIER1_FUNFIE0_MASK) | SDADC_ABNIER1_FUNFIE0(u32Value);
}

/**
 * @brief Get the value of ZCD2.
 * Filter Channel 2 Zero Cross Detected Flag
 * 0b - The flag is not asserted.
 * 1b - The flag is asserted.
 * @param pSdadc the base address of the SDADC instance.

 * @return uint32_t the value of ZCD2.
 */
LOCAL_INLINE uint32_t SDADC_HWA_GetZCD2(const SDADC_Type *const pSdadc)
{
    uint32_t u32TmpVal = (pSdadc->NISR & SDADC_NISR_ZCD2_MASK) >> SDADC_NISR_ZCD2_SHIFT;
    return u32TmpVal;
}

/**
 * @brief Clear ZCD2.
 * Filter Channel 2 Zero Cross Detected Flag
 * 0b - The flag is not asserted.
 * 1b - The flag is asserted.
 * @param pSdadc the base address of the SDADC instance.

 */
LOCAL_INLINE void SDADC_HWA_ClearZCD2(SDADC_Type *const pSdadc)
{
    pSdadc->NISR = SDADC_NISR_ZCD2(1);
}

/**
 * @brief Get the value of ZCD1.
 * Filter Channel 1 Zero Cross Detected Flag
 * 0b - The flag is not asserted.
 * 1b - The flag is asserted.
 * @param pSdadc the base address of the SDADC instance.

 * @return uint32_t the value of ZCD1.
 */
LOCAL_INLINE uint32_t SDADC_HWA_GetZCD1(const SDADC_Type *const pSdadc)
{
    uint32_t u32TmpVal = (pSdadc->NISR & SDADC_NISR_ZCD1_MASK) >> SDADC_NISR_ZCD1_SHIFT;
    return u32TmpVal;
}

/**
 * @brief Clear ZCD1.
 * Filter Channel 1 Zero Cross Detected Flag
 * 0b - The flag is not asserted.
 * 1b - The flag is asserted.
 * @param pSdadc the base address of the SDADC instance.

 */
LOCAL_INLINE void SDADC_HWA_ClearZCD1(SDADC_Type *const pSdadc)
{
    pSdadc->NISR = SDADC_NISR_ZCD1(1);
}

/**
 * @brief Get the value of ZCD0.
 * Filter Channel 0 Zero Cross Detected Flag
 * 0b - The flag is not asserted.
 * 1b - The flag is asserted.
 * @param pSdadc the base address of the SDADC instance.

 * @return uint32_t the value of ZCD0.
 */
LOCAL_INLINE uint32_t SDADC_HWA_GetZCD0(const SDADC_Type *const pSdadc)
{
    uint32_t u32TmpVal = (pSdadc->NISR & SDADC_NISR_ZCD0_MASK) >> SDADC_NISR_ZCD0_SHIFT;
    return u32TmpVal;
}

/**
 * @brief Clear ZCD0.
 * Filter Channel 0 Zero Cross Detected Flag
 * 0b - The flag is not asserted.
 * 1b - The flag is asserted.
 * @param pSdadc the base address of the SDADC instance.

 */
LOCAL_INLINE void SDADC_HWA_ClearZCD0(SDADC_Type *const pSdadc)
{
    pSdadc->NISR = SDADC_NISR_ZCD0(1);
}

/**
 * @brief Get the value of FRDY2.
 * Filter Channel 2 FIFO Data Ready Flag
 * 0b - The flag is not asserted.
 * 1b - The flag is asserted.
 * @param pSdadc the base address of the SDADC instance.

 * @return uint32_t the value of FRDY2.
 */
LOCAL_INLINE uint32_t SDADC_HWA_GetFRDY2(const SDADC_Type *const pSdadc)
{
    uint32_t u32TmpVal = (pSdadc->NISR & SDADC_NISR_FRDY2_MASK) >> SDADC_NISR_FRDY2_SHIFT;
    return u32TmpVal;
}

/**
 * @brief Clear FRDY2.
 * Filter Channel 2 FIFO Data Ready Flag
 * 0b - The flag is not asserted.
 * 1b - The flag is asserted.
 * @param pSdadc the base address of the SDADC instance.

 */
LOCAL_INLINE void SDADC_HWA_ClearFRDY2(SDADC_Type *const pSdadc)
{
    pSdadc->NISR = SDADC_NISR_FRDY2(1);
}

/**
 * @brief Get the value of FRDY1.
 * Filter Channel 1 FIFO Data Ready Flag
 * 0b - The flag is not asserted.
 * 1b - The flag is asserted.
 * @param pSdadc the base address of the SDADC instance.

 * @return uint32_t the value of FRDY1.
 */
LOCAL_INLINE uint32_t SDADC_HWA_GetFRDY1(const SDADC_Type *const pSdadc)
{
    uint32_t u32TmpVal = (pSdadc->NISR & SDADC_NISR_FRDY1_MASK) >> SDADC_NISR_FRDY1_SHIFT;
    return u32TmpVal;
}

/**
 * @brief Clear FRDY1.
 * Filter Channel 1 FIFO Data Ready Flag
 * 0b - The flag is not asserted.
 * 1b - The flag is asserted.
 * @param pSdadc the base address of the SDADC instance.

 */
LOCAL_INLINE void SDADC_HWA_ClearFRDY1(SDADC_Type *const pSdadc)
{
    pSdadc->NISR = SDADC_NISR_FRDY1(1);
}

/**
 * @brief Get the value of FRDY0.
 * Filter Channel 0 FIFO Data Ready Flag
 * 0b - The flag is not asserted.
 * 1b - The flag is asserted.
 * @param pSdadc the base address of the SDADC instance.

 * @return uint32_t the value of FRDY0.
 */
LOCAL_INLINE uint32_t SDADC_HWA_GetFRDY0(const SDADC_Type *const pSdadc)
{
    uint32_t u32TmpVal = (pSdadc->NISR & SDADC_NISR_FRDY0_MASK) >> SDADC_NISR_FRDY0_SHIFT;
    return u32TmpVal;
}

/**
 * @brief Clear FRDY0.
 * Filter Channel 0 FIFO Data Ready Flag
 * 0b - The flag is not asserted.
 * 1b - The flag is asserted.
 * @param pSdadc the base address of the SDADC instance.

 */
LOCAL_INLINE void SDADC_HWA_ClearFRDY0(SDADC_Type *const pSdadc)
{
    pSdadc->NISR = SDADC_NISR_FRDY0(1);
}

/**
 * @brief Get the value of COC2.
 * Filter Channel 2 Conversion Complete Flag
 * 0b - The flag is not asserted.
 * 1b - The flag is asserted.
 * @param pSdadc the base address of the SDADC instance.

 * @return uint32_t the value of COC2.
 */
LOCAL_INLINE uint32_t SDADC_HWA_GetCOC2(const SDADC_Type *const pSdadc)
{
    uint32_t u32TmpVal = (pSdadc->NISR & SDADC_NISR_COC2_MASK) >> SDADC_NISR_COC2_SHIFT;
    return u32TmpVal;
}

/**
 * @brief Clear COC2.
 * Filter Channel 2 Conversion Complete Flag
 * 0b - The flag is not asserted.
 * 1b - The flag is asserted.
 * @param pSdadc the base address of the SDADC instance.

 */
LOCAL_INLINE void SDADC_HWA_ClearCOC2(SDADC_Type *const pSdadc)
{
    pSdadc->NISR = SDADC_NISR_COC2(1);
}

/**
 * @brief Get the value of COC1.
 * Filter Channel 1 Conversion Complete Flag
 * 0b - The flag is not asserted.
 * 1b - The flag is asserted.
 * @param pSdadc the base address of the SDADC instance.

 * @return uint32_t the value of COC1.
 */
LOCAL_INLINE uint32_t SDADC_HWA_GetCOC1(const SDADC_Type *const pSdadc)
{
    uint32_t u32TmpVal = (pSdadc->NISR & SDADC_NISR_COC1_MASK) >> SDADC_NISR_COC1_SHIFT;
    return u32TmpVal;
}

/**
 * @brief Clear COC1.
 * Filter Channel 1 Conversion Complete Flag
 * 0b - The flag is not asserted.
 * 1b - The flag is asserted.
 * @param pSdadc the base address of the SDADC instance.

 */
LOCAL_INLINE void SDADC_HWA_ClearCOC1(SDADC_Type *const pSdadc)
{
    pSdadc->NISR = SDADC_NISR_COC1(1);
}

/**
 * @brief Get the value of COC0.
 * Filter Channel 0 Conversion Complete Flag
 * 0b - The flag is not asserted.
 * 1b - The flag is asserted.
 * @param pSdadc the base address of the SDADC instance.

 * @return uint32_t the value of COC0.
 */
LOCAL_INLINE uint32_t SDADC_HWA_GetCOC0(const SDADC_Type *const pSdadc)
{
    uint32_t u32TmpVal = (pSdadc->NISR & SDADC_NISR_COC0_MASK) >> SDADC_NISR_COC0_SHIFT;
    return u32TmpVal;
}

/**
 * @brief Clear COC0.
 * Filter Channel 0 Conversion Complete Flag
 * 0b - The flag is not asserted.
 * 1b - The flag is asserted.
 * @param pSdadc the base address of the SDADC instance.

 */
LOCAL_INLINE void SDADC_HWA_ClearCOC0(SDADC_Type *const pSdadc)
{
    pSdadc->NISR = SDADC_NISR_COC0(1);
}

/**
 * @brief Get the value of HLMT2.
 * Filter Channel 2 High Limit Flag
 * 0b - The flag is not asserted.
 * 1b - The flag is asserted.
 * @param pSdadc the base address of the SDADC instance.

 * @return uint32_t the value of HLMT2.
 */
LOCAL_INLINE uint32_t SDADC_HWA_GetHLMT2(const SDADC_Type *const pSdadc)
{
    uint32_t u32TmpVal = (pSdadc->ABNISR0 & SDADC_ABNISR0_HLMT2_MASK) >> SDADC_ABNISR0_HLMT2_SHIFT;
    return u32TmpVal;
}

/**
 * @brief Clear HLMT2.
 * Filter Channel 2 High Limit Flag
 * 0b - The flag is not asserted.
 * 1b - The flag is asserted.
 * @param pSdadc the base address of the SDADC instance.

 */
LOCAL_INLINE void SDADC_HWA_ClearHLMT2(SDADC_Type *const pSdadc)
{
    pSdadc->ABNISR0 = SDADC_ABNISR0_HLMT2(1);
}

/**
 * @brief Get the value of HLMT1.
 * Filter Channel 1 High Limit Flag
 * 0b - The flag is not asserted.
 * 1b - The flag is asserted.
 * @param pSdadc the base address of the SDADC instance.

 * @return uint32_t the value of HLMT1.
 */
LOCAL_INLINE uint32_t SDADC_HWA_GetHLMT1(const SDADC_Type *const pSdadc)
{
    uint32_t u32TmpVal = (pSdadc->ABNISR0 & SDADC_ABNISR0_HLMT1_MASK) >> SDADC_ABNISR0_HLMT1_SHIFT;
    return u32TmpVal;
}

/**
 * @brief Clear HLMT1.
 * Filter Channel 1 High Limit Flag
 * 0b - The flag is not asserted.
 * 1b - The flag is asserted.
 * @param pSdadc the base address of the SDADC instance.

 */
LOCAL_INLINE void SDADC_HWA_ClearHLMT1(SDADC_Type *const pSdadc)
{
    pSdadc->ABNISR0 = SDADC_ABNISR0_HLMT1(1);
}

/**
 * @brief Get the value of HLMT0.
 * Filter Channel 0 High Limit Flag
 * 0b - The flag is not asserted.
 * 1b - The flag is asserted.
 * @param pSdadc the base address of the SDADC instance.

 * @return uint32_t the value of HLMT0.
 */
LOCAL_INLINE uint32_t SDADC_HWA_GetHLMT0(const SDADC_Type *const pSdadc)
{
    uint32_t u32TmpVal = (pSdadc->ABNISR0 & SDADC_ABNISR0_HLMT0_MASK) >> SDADC_ABNISR0_HLMT0_SHIFT;
    return u32TmpVal;
}

/**
 * @brief Clear HLMT0.
 * Filter Channel 0 High Limit Flag
 * 0b - The flag is not asserted.
 * 1b - The flag is asserted.
 * @param pSdadc the base address of the SDADC instance.

 */
LOCAL_INLINE void SDADC_HWA_ClearHLMT0(SDADC_Type *const pSdadc)
{
    pSdadc->ABNISR0 = SDADC_ABNISR0_HLMT0(1);
}

/**
 * @brief Get the value of LLMT2.
 * Filter Channel 2 Low Limit Flag
 * 0b - The flag is not asserted.
 * 1b - The flag is asserted.
 * @param pSdadc the base address of the SDADC instance.

 * @return uint32_t the value of LLMT2.
 */
LOCAL_INLINE uint32_t SDADC_HWA_GetLLMT2(const SDADC_Type *const pSdadc)
{
    uint32_t u32TmpVal = (pSdadc->ABNISR0 & SDADC_ABNISR0_LLMT2_MASK) >> SDADC_ABNISR0_LLMT2_SHIFT;
    return u32TmpVal;
}

/**
 * @brief Clear LLMT2.
 * Filter Channel 2 Low Limit Flag
 * 0b - The flag is not asserted.
 * 1b - The flag is asserted.
 * @param pSdadc the base address of the SDADC instance.

 */
LOCAL_INLINE void SDADC_HWA_ClearLLMT2(SDADC_Type *const pSdadc)
{
    pSdadc->ABNISR0 = SDADC_ABNISR0_LLMT2(1);
}

/**
 * @brief Get the value of LLMT1.
 * Filter Channel 1 Low Limit Flag
 * 0b - The flag is not asserted.
 * 1b - The flag is asserted.
 * @param pSdadc the base address of the SDADC instance.

 * @return uint32_t the value of LLMT1.
 */
LOCAL_INLINE uint32_t SDADC_HWA_GetLLMT1(const SDADC_Type *const pSdadc)
{
    uint32_t u32TmpVal = (pSdadc->ABNISR0 & SDADC_ABNISR0_LLMT1_MASK) >> SDADC_ABNISR0_LLMT1_SHIFT;
    return u32TmpVal;
}

/**
 * @brief Clear LLMT1.
 * Filter Channel 1 Low Limit Flag
 * 0b - The flag is not asserted.
 * 1b - The flag is asserted.
 * @param pSdadc the base address of the SDADC instance.

 */
LOCAL_INLINE void SDADC_HWA_ClearLLMT1(SDADC_Type *const pSdadc)
{
    pSdadc->ABNISR0 = SDADC_ABNISR0_LLMT1(1);
}

/**
 * @brief Get the value of LLMT0.
 * Filter Channel 0 Low Limit Flag
 * 0b - The flag is not asserted.
 * 1b - The flag is asserted.
 * @param pSdadc the base address of the SDADC instance.

 * @return uint32_t the value of LLMT0.
 */
LOCAL_INLINE uint32_t SDADC_HWA_GetLLMT0(const SDADC_Type *const pSdadc)
{
    uint32_t u32TmpVal = (pSdadc->ABNISR0 & SDADC_ABNISR0_LLMT0_MASK) >> SDADC_ABNISR0_LLMT0_SHIFT;
    return u32TmpVal;
}

/**
 * @brief Clear LLMT0.
 * Filter Channel 0 Low Limit Flag
 * 0b - The flag is not asserted.
 * 1b - The flag is asserted.
 * @param pSdadc the base address of the SDADC instance.

 */
LOCAL_INLINE void SDADC_HWA_ClearLLMT0(SDADC_Type *const pSdadc)
{
    pSdadc->ABNISR0 = SDADC_ABNISR0_LLMT0(1);
}

/**
 * @brief Get the value of WLMT2.
 * Filter Channel 2 Window Limit Flag
 * 0b - The flag is not asserted.
 * 1b - The flag is asserted.
 * @param pSdadc the base address of the SDADC instance.

 * @return uint32_t the value of WLMT2.
 */
LOCAL_INLINE uint32_t SDADC_HWA_GetWLMT2(const SDADC_Type *const pSdadc)
{
    uint32_t u32TmpVal = (pSdadc->ABNISR0 & SDADC_ABNISR0_WLMT2_MASK) >> SDADC_ABNISR0_WLMT2_SHIFT;
    return u32TmpVal;
}

/**
 * @brief Clear WLMT2.
 * Filter Channel 2 Window Limit Flag
 * 0b - The flag is not asserted.
 * 1b - The flag is asserted.
 * @param pSdadc the base address of the SDADC instance.

 */
LOCAL_INLINE void SDADC_HWA_ClearWLMT2(SDADC_Type *const pSdadc)
{
    pSdadc->ABNISR0 = SDADC_ABNISR0_WLMT2(1);
}

/**
 * @brief Get the value of WLMT1.
 * Filter Channel 1 Window Limit Flag
 * 0b - The flag is not asserted.
 * 1b - The flag is asserted.
 * @param pSdadc the base address of the SDADC instance.

 * @return uint32_t the value of WLMT1.
 */
LOCAL_INLINE uint32_t SDADC_HWA_GetWLMT1(const SDADC_Type *const pSdadc)
{
    uint32_t u32TmpVal = (pSdadc->ABNISR0 & SDADC_ABNISR0_WLMT1_MASK) >> SDADC_ABNISR0_WLMT1_SHIFT;
    return u32TmpVal;
}

/**
 * @brief Clear WLMT1.
 * Filter Channel 1 Window Limit Flag
 * 0b - The flag is not asserted.
 * 1b - The flag is asserted.
 * @param pSdadc the base address of the SDADC instance.

 */
LOCAL_INLINE void SDADC_HWA_ClearWLMT1(SDADC_Type *const pSdadc)
{
    pSdadc->ABNISR0 = SDADC_ABNISR0_WLMT1(1);
}

/**
 * @brief Get the value of WLMT0.
 * Filter Channel 0 Window Limit Flag
 * 0b - The flag is not asserted.
 * 1b - The flag is asserted.
 * @param pSdadc the base address of the SDADC instance.

 * @return uint32_t the value of WLMT0.
 */
LOCAL_INLINE uint32_t SDADC_HWA_GetWLMT0(const SDADC_Type *const pSdadc)
{
    uint32_t u32TmpVal = (pSdadc->ABNISR0 & SDADC_ABNISR0_WLMT0_MASK) >> SDADC_ABNISR0_WLMT0_SHIFT;
    return u32TmpVal;
}

/**
 * @brief Clear WLMT0.
 * Filter Channel 0 Window Limit Flag
 * 0b - The flag is not asserted.
 * 1b - The flag is asserted.
 * @param pSdadc the base address of the SDADC instance.

 */
LOCAL_INLINE void SDADC_HWA_ClearWLMT0(SDADC_Type *const pSdadc)
{
    pSdadc->ABNISR0 = SDADC_ABNISR0_WLMT0(1);
}

/**
 * @brief Get the value of SCD2.
 * Filter Channel 2 Short Circuit Detected Flag
 * 0b - The flag is not asserted.
 * 1b - The flag is asserted.
 * @param pSdadc the base address of the SDADC instance.

 * @return uint32_t the value of SCD2.
 */
LOCAL_INLINE uint32_t SDADC_HWA_GetSCD2(const SDADC_Type *const pSdadc)
{
    uint32_t u32TmpVal = (pSdadc->ABNISR0 & SDADC_ABNISR0_SCD2_MASK) >> SDADC_ABNISR0_SCD2_SHIFT;
    return u32TmpVal;
}

/**
 * @brief Clear SCD2.
 * Filter Channel 2 Short Circuit Detected Flag
 * 0b - The flag is not asserted.
 * 1b - The flag is asserted.
 * @param pSdadc the base address of the SDADC instance.

 */
LOCAL_INLINE void SDADC_HWA_ClearSCD2(SDADC_Type *const pSdadc)
{
    pSdadc->ABNISR0 = SDADC_ABNISR0_SCD2(1);
}

/**
 * @brief Get the value of SCD1.
 * Filter Channel 1 Short Circuit Detected Flag
 * 0b - The flag is not asserted.
 * 1b - The flag is asserted.
 * @param pSdadc the base address of the SDADC instance.

 * @return uint32_t the value of SCD1.
 */
LOCAL_INLINE uint32_t SDADC_HWA_GetSCD1(const SDADC_Type *const pSdadc)
{
    uint32_t u32TmpVal = (pSdadc->ABNISR0 & SDADC_ABNISR0_SCD1_MASK) >> SDADC_ABNISR0_SCD1_SHIFT;
    return u32TmpVal;
}

/**
 * @brief Clear SCD1.
 * Filter Channel 1 Short Circuit Detected Flag
 * 0b - The flag is not asserted.
 * 1b - The flag is asserted.
 * @param pSdadc the base address of the SDADC instance.

 */
LOCAL_INLINE void SDADC_HWA_ClearSCD1(SDADC_Type *const pSdadc)
{
    pSdadc->ABNISR0 = SDADC_ABNISR0_SCD1(1);
}

/**
 * @brief Get the value of SCD0.
 * Filter Channel 0 Short Circuit Detected Flag
 * 0b - The flag is not asserted.
 * 1b - The flag is asserted.
 * @param pSdadc the base address of the SDADC instance.

 * @return uint32_t the value of SCD0.
 */
LOCAL_INLINE uint32_t SDADC_HWA_GetSCD0(const SDADC_Type *const pSdadc)
{
    uint32_t u32TmpVal = (pSdadc->ABNISR0 & SDADC_ABNISR0_SCD0_MASK) >> SDADC_ABNISR0_SCD0_SHIFT;
    return u32TmpVal;
}

/**
 * @brief Clear SCD0.
 * Filter Channel 0 Short Circuit Detected Flag
 * 0b - The flag is not asserted.
 * 1b - The flag is asserted.
 * @param pSdadc the base address of the SDADC instance.

 */
LOCAL_INLINE void SDADC_HWA_ClearSCD0(SDADC_Type *const pSdadc)
{
    pSdadc->ABNISR0 = SDADC_ABNISR0_SCD0(1);
}

/**
 * @brief Get the value of SAT2.
 * Filter Channel 2 Saturation Flag
 * 0b - The flag is not asserted.
 * 1b - The flag is asserted.
 * @param pSdadc the base address of the SDADC instance.

 * @return uint32_t the value of SAT2.
 */
LOCAL_INLINE uint32_t SDADC_HWA_GetSAT2(const SDADC_Type *const pSdadc)
{
    uint32_t u32TmpVal = (pSdadc->ABNISR1 & SDADC_ABNISR1_SAT2_MASK) >> SDADC_ABNISR1_SAT2_SHIFT;
    return u32TmpVal;
}

/**
 * @brief Clear SAT2.
 * Filter Channel 2 Saturation Flag
 * 0b - The flag is not asserted.
 * 1b - The flag is asserted.
 * @param pSdadc the base address of the SDADC instance.

 */
LOCAL_INLINE void SDADC_HWA_ClearSAT2(SDADC_Type *const pSdadc)
{
    pSdadc->ABNISR1 = SDADC_ABNISR1_SAT2(1);
}

/**
 * @brief Get the value of SAT1.
 * Filter Channel 1 Saturation Flag
 * 0b - The flag is not asserted.
 * 1b - The flag is asserted.
 * @param pSdadc the base address of the SDADC instance.

 * @return uint32_t the value of SAT1.
 */
LOCAL_INLINE uint32_t SDADC_HWA_GetSAT1(const SDADC_Type *const pSdadc)
{
    uint32_t u32TmpVal = (pSdadc->ABNISR1 & SDADC_ABNISR1_SAT1_MASK) >> SDADC_ABNISR1_SAT1_SHIFT;
    return u32TmpVal;
}

/**
 * @brief Clear SAT1.
 * Filter Channel 1 Saturation Flag
 * 0b - The flag is not asserted.
 * 1b - The flag is asserted.
 * @param pSdadc the base address of the SDADC instance.

 */
LOCAL_INLINE void SDADC_HWA_ClearSAT1(SDADC_Type *const pSdadc)
{
    pSdadc->ABNISR1 = SDADC_ABNISR1_SAT1(1);
}

/**
 * @brief Get the value of SAT0.
 * Filter Channel 0 Saturation Flag
 * 0b - The flag is not asserted.
 * 1b - The flag is asserted.
 * @param pSdadc the base address of the SDADC instance.

 * @return uint32_t the value of SAT0.
 */
LOCAL_INLINE uint32_t SDADC_HWA_GetSAT0(const SDADC_Type *const pSdadc)
{
    uint32_t u32TmpVal = (pSdadc->ABNISR1 & SDADC_ABNISR1_SAT0_MASK) >> SDADC_ABNISR1_SAT0_SHIFT;
    return u32TmpVal;
}

/**
 * @brief Clear SAT0.
 * Filter Channel 0 Saturation Flag
 * 0b - The flag is not asserted.
 * 1b - The flag is asserted.
 * @param pSdadc the base address of the SDADC instance.

 */
LOCAL_INLINE void SDADC_HWA_ClearSAT0(SDADC_Type *const pSdadc)
{
    pSdadc->ABNISR1 = SDADC_ABNISR1_SAT0(1);
}

/**
 * @brief Get the value of CAD2.
 * Filter Channel 2 Clock Absence Flag
 * 0b - The flag is not asserted.
 * 1b - The flag is asserted.
 * @param pSdadc the base address of the SDADC instance.

 * @return uint32_t the value of CAD2.
 */
LOCAL_INLINE uint32_t SDADC_HWA_GetCAD2(const SDADC_Type *const pSdadc)
{
    uint32_t u32TmpVal = (pSdadc->ABNISR1 & SDADC_ABNISR1_CAD2_MASK) >> SDADC_ABNISR1_CAD2_SHIFT;
    return u32TmpVal;
}

/**
 * @brief Clear CAD2.
 * Filter Channel 2 Clock Absence Flag
 * 0b - The flag is not asserted.
 * 1b - The flag is asserted.
 * @param pSdadc the base address of the SDADC instance.

 */
LOCAL_INLINE void SDADC_HWA_ClearCAD2(SDADC_Type *const pSdadc)
{
    pSdadc->ABNISR1 = SDADC_ABNISR1_CAD2(1);
}

/**
 * @brief Get the value of CAD1.
 * Filter Channel 1 Clock Absence Flag
 * 0b - The flag is not asserted.
 * 1b - The flag is asserted.
 * @param pSdadc the base address of the SDADC instance.

 * @return uint32_t the value of CAD1.
 */
LOCAL_INLINE uint32_t SDADC_HWA_GetCAD1(const SDADC_Type *const pSdadc)
{
    uint32_t u32TmpVal = (pSdadc->ABNISR1 & SDADC_ABNISR1_CAD1_MASK) >> SDADC_ABNISR1_CAD1_SHIFT;
    return u32TmpVal;
}

/**
 * @brief Clear CAD1.
 * Filter Channel 1 Clock Absence Flag
 * 0b - The flag is not asserted.
 * 1b - The flag is asserted.
 * @param pSdadc the base address of the SDADC instance.

 */
LOCAL_INLINE void SDADC_HWA_ClearCAD1(SDADC_Type *const pSdadc)
{
    pSdadc->ABNISR1 = SDADC_ABNISR1_CAD1(1);
}

/**
 * @brief Get the value of CAD0.
 * Filter Channel 0 Clock Absence Flag
 * 0b - The flag is not asserted.
 * 1b - The flag is asserted.
 * @param pSdadc the base address of the SDADC instance.

 * @return uint32_t the value of CAD0.
 */
LOCAL_INLINE uint32_t SDADC_HWA_GetCAD0(const SDADC_Type *const pSdadc)
{
    uint32_t u32TmpVal = (pSdadc->ABNISR1 & SDADC_ABNISR1_CAD0_MASK) >> SDADC_ABNISR1_CAD0_SHIFT;
    return u32TmpVal;
}

/**
 * @brief Clear CAD0.
 * Filter Channel 0 Clock Absence Flag
 * 0b - The flag is not asserted.
 * 1b - The flag is asserted.
 * @param pSdadc the base address of the SDADC instance.

 */
LOCAL_INLINE void SDADC_HWA_ClearCAD0(SDADC_Type *const pSdadc)
{
    pSdadc->ABNISR1 = SDADC_ABNISR1_CAD0(1);
}

/**
 * @brief Get the value of FOVF2.
 * Filter Channel 2 FIFO Overflow Flag
 * 0b - The flag is not asserted.
 * 1b - The flag is asserted.
 * @param pSdadc the base address of the SDADC instance.

 * @return uint32_t the value of FOVF2.
 */
LOCAL_INLINE uint32_t SDADC_HWA_GetFOVF2(const SDADC_Type *const pSdadc)
{
    uint32_t u32TmpVal = (pSdadc->ABNISR1 & SDADC_ABNISR1_FOVF2_MASK) >> SDADC_ABNISR1_FOVF2_SHIFT;
    return u32TmpVal;
}

/**
 * @brief Clear FOVF2.
 * Filter Channel 2 FIFO Overflow Flag
 * 0b - The flag is not asserted.
 * 1b - The flag is asserted.
 * @param pSdadc the base address of the SDADC instance.

 */
LOCAL_INLINE void SDADC_HWA_ClearFOVF2(SDADC_Type *const pSdadc)
{
    pSdadc->ABNISR1 = SDADC_ABNISR1_FOVF2(1);
}

/**
 * @brief Get the value of FOVF1.
 * Filter Channel 1 FIFO Overflow Flag
 * 0b - The flag is not asserted.
 * 1b - The flag is asserted.
 * @param pSdadc the base address of the SDADC instance.

 * @return uint32_t the value of FOVF1.
 */
LOCAL_INLINE uint32_t SDADC_HWA_GetFOVF1(const SDADC_Type *const pSdadc)
{
    uint32_t u32TmpVal = (pSdadc->ABNISR1 & SDADC_ABNISR1_FOVF1_MASK) >> SDADC_ABNISR1_FOVF1_SHIFT;
    return u32TmpVal;
}

/**
 * @brief Clear FOVF1.
 * Filter Channel 1 FIFO Overflow Flag
 * 0b - The flag is not asserted.
 * 1b - The flag is asserted.
 * @param pSdadc the base address of the SDADC instance.

 */
LOCAL_INLINE void SDADC_HWA_ClearFOVF1(SDADC_Type *const pSdadc)
{
    pSdadc->ABNISR1 = SDADC_ABNISR1_FOVF1(1);
}

/**
 * @brief Get the value of FOVF0.
 * Filter Channel 0 FIFO Overflow flag
 * 0b - The flag is not asserted.
 * 1b - The flag is asserted.
 * @param pSdadc the base address of the SDADC instance.

 * @return uint32_t the value of FOVF0.
 */
LOCAL_INLINE uint32_t SDADC_HWA_GetFOVF0(const SDADC_Type *const pSdadc)
{
    uint32_t u32TmpVal = (pSdadc->ABNISR1 & SDADC_ABNISR1_FOVF0_MASK) >> SDADC_ABNISR1_FOVF0_SHIFT;
    return u32TmpVal;
}

/**
 * @brief Clear FOVF0.
 * Filter Channel 0 FIFO Overflow flag
 * 0b - The flag is not asserted.
 * 1b - The flag is asserted.
 * @param pSdadc the base address of the SDADC instance.

 */
LOCAL_INLINE void SDADC_HWA_ClearFOVF0(SDADC_Type *const pSdadc)
{
    pSdadc->ABNISR1 = SDADC_ABNISR1_FOVF0(1);
}

/**
 * @brief Get the value of FUNF2.
 * Filter Channel 2 FIFO underflow flag
 * 0b - The flag is not asserted.
 * 1b - The flag is asserted.
 * @param pSdadc the base address of the SDADC instance.

 * @return uint32_t the value of FUNF2.
 */
LOCAL_INLINE uint32_t SDADC_HWA_GetFUNF2(const SDADC_Type *const pSdadc)
{
    uint32_t u32TmpVal = (pSdadc->ABNISR1 & SDADC_ABNISR1_FUNF2_MASK) >> SDADC_ABNISR1_FUNF2_SHIFT;
    return u32TmpVal;
}

/**
 * @brief Clear FUNF2.
 * Filter Channel 2 FIFO underflow flag
 * 0b - The flag is not asserted.
 * 1b - The flag is asserted.
 * @param pSdadc the base address of the SDADC instance.

 */
LOCAL_INLINE void SDADC_HWA_ClearFUNF2(SDADC_Type *const pSdadc)
{
    pSdadc->ABNISR1 = SDADC_ABNISR1_FUNF2(1);
}

/**
 * @brief Get the value of FUNF1.
 * Filter Channel 1 FIFO Underflow Flag
 * 0b - The flag is not asserted.
 * 1b - The flag is asserted.
 * @param pSdadc the base address of the SDADC instance.

 * @return uint32_t the value of FUNF1.
 */
LOCAL_INLINE uint32_t SDADC_HWA_GetFUNF1(const SDADC_Type *const pSdadc)
{
    uint32_t u32TmpVal = (pSdadc->ABNISR1 & SDADC_ABNISR1_FUNF1_MASK) >> SDADC_ABNISR1_FUNF1_SHIFT;
    return u32TmpVal;
}

/**
 * @brief Clear FUNF1.
 * Filter Channel 1 FIFO Underflow Flag
 * 0b - The flag is not asserted.
 * 1b - The flag is asserted.
 * @param pSdadc the base address of the SDADC instance.

 */
LOCAL_INLINE void SDADC_HWA_ClearFUNF1(SDADC_Type *const pSdadc)
{
    pSdadc->ABNISR1 = SDADC_ABNISR1_FUNF1(1);
}

/**
 * @brief Get the value of FUNF0.
 * Filter Channel 0 FIFO Underflow Flag
 * 0b - The flag is not asserted.
 * 1b - The flag is asserted.
 * @param pSdadc the base address of the SDADC instance.

 * @return uint32_t the value of FUNF0.
 */
LOCAL_INLINE uint32_t SDADC_HWA_GetFUNF0(const SDADC_Type *const pSdadc)
{
    uint32_t u32TmpVal = (pSdadc->ABNISR1 & SDADC_ABNISR1_FUNF0_MASK) >> SDADC_ABNISR1_FUNF0_SHIFT;
    return u32TmpVal;
}

/**
 * @brief Clear FUNF0.
 * Filter Channel 0 FIFO Underflow Flag
 * 0b - The flag is not asserted.
 * 1b - The flag is asserted.
 * @param pSdadc the base address of the SDADC instance.

 */
LOCAL_INLINE void SDADC_HWA_ClearFUNF0(SDADC_Type *const pSdadc)
{
    pSdadc->ABNISR1 = SDADC_ABNISR1_FUNF0(1);
}

/**
 * @brief Get the value of CLKO2_RDY.
 * Modulator Clock Output 2 Ready Flag
 * Indicate the modulator clock 2 output is ready.
 * 0b - The clock is not ready.
 * 1b - The clock is ready.
 * @param pSdadc the base address of the SDADC instance.

 * @return uint32_t the value of CLKO2_RDY.
 */
LOCAL_INLINE uint32_t SDADC_HWA_GetCLKO2_RDY(const SDADC_Type *const pSdadc)
{
    uint32_t u32TmpVal = (pSdadc->MSR & SDADC_MSR_CLKO2_RDY_MASK) >> SDADC_MSR_CLKO2_RDY_SHIFT;
    return u32TmpVal;
}

/**
 * @brief Get the value of CLKO1_RDY.
 * Modulator Clock Output 1 Ready Flag
 * Indicate the modulator clock 1 output is ready.
 * 0b - The clock is not ready.
 * 1b - The clock is ready.
 * @param pSdadc the base address of the SDADC instance.

 * @return uint32_t the value of CLKO1_RDY.
 */
LOCAL_INLINE uint32_t SDADC_HWA_GetCLKO1_RDY(const SDADC_Type *const pSdadc)
{
    uint32_t u32TmpVal = (pSdadc->MSR & SDADC_MSR_CLKO1_RDY_MASK) >> SDADC_MSR_CLKO1_RDY_SHIFT;
    return u32TmpVal;
}

/**
 * @brief Get the value of CLKO0_RDY.
 * Modulator Clock Output 0 Ready Flag
 * Indicate the modulator clock 0 output is ready.
 * 0b - The clock is not ready.
 * 1b - The clock is ready.
 * @param pSdadc the base address of the SDADC instance.

 * @return uint32_t the value of CLKO0_RDY.
 */
LOCAL_INLINE uint32_t SDADC_HWA_GetCLKO0_RDY(const SDADC_Type *const pSdadc)
{
    uint32_t u32TmpVal = (pSdadc->MSR & SDADC_MSR_CLKO0_RDY_MASK) >> SDADC_MSR_CLKO0_RDY_SHIFT;
    return u32TmpVal;
}

/**
 * @brief Get the value of FIFO_EMPTY.
 * FIFO Empty Flag
 * bit 18-16 are for filter channel 2-0.
 * @param pSdadc the base address of the SDADC instance.

 * @return uint32_t the value of FIFO_EMPTY.
 */
LOCAL_INLINE uint32_t SDADC_HWA_GetFIFO_EMPTY(const SDADC_Type *const pSdadc)
{
    uint32_t u32TmpVal = (pSdadc->MSR & SDADC_MSR_FIFO_EMPTY_MASK) >> SDADC_MSR_FIFO_EMPTY_SHIFT;
    return u32TmpVal;
}

/**
 * @brief Get the value of CHRDY.
 * Filter Channel Ready Flag
 * bit 10-8 are for filter channel 2-0.
 * @param pSdadc the base address of the SDADC instance.

 * @return uint32_t the value of CHRDY.
 */
LOCAL_INLINE uint32_t SDADC_HWA_GetCHRDY(const SDADC_Type *const pSdadc)
{
    uint32_t u32TmpVal = (pSdadc->MSR & SDADC_MSR_CHRDY_MASK) >> SDADC_MSR_CHRDY_SHIFT;
    return u32TmpVal;
}

/**
 * @brief Get the value of CHON2.
 * Filter Channel 2 Conversion Ongoing Flag
 * 0b - The conversion is not ongoing.
 * 1b - The conversion is ongoing.
 * @param pSdadc the base address of the SDADC instance.

 * @return uint32_t the value of CHON2.
 */
LOCAL_INLINE uint32_t SDADC_HWA_GetCHON2(const SDADC_Type *const pSdadc)
{
    uint32_t u32TmpVal = (pSdadc->MSR & SDADC_MSR_CHON2_MASK) >> SDADC_MSR_CHON2_SHIFT;
    return u32TmpVal;
}

/**
 * @brief Get the value of CHON1.
 * Filter Channel 1 Conversion Ongoing Flag
 * 0b - The conversion is not ongoing.
 * 1b - The conversion is ongoing.
 * @param pSdadc the base address of the SDADC instance.

 * @return uint32_t the value of CHON1.
 */
LOCAL_INLINE uint32_t SDADC_HWA_GetCHON1(const SDADC_Type *const pSdadc)
{
    uint32_t u32TmpVal = (pSdadc->MSR & SDADC_MSR_CHON1_MASK) >> SDADC_MSR_CHON1_SHIFT;
    return u32TmpVal;
}

/**
 * @brief Get the value of CHON0.
 * Filter Channel 0 Conversion Ongoing Flag
 * 0b - The conversion is not ongoing.
 * 1b - The conversion is ongoing.
 * @param pSdadc the base address of the SDADC instance.

 * @return uint32_t the value of CHON0.
 */
LOCAL_INLINE uint32_t SDADC_HWA_GetCHON0(const SDADC_Type *const pSdadc)
{
    uint32_t u32TmpVal = (pSdadc->MSR & SDADC_MSR_CHON0_MASK) >> SDADC_MSR_CHON0_SHIFT;
    return u32TmpVal;
}

/**
 * @brief Get the value of CHON.
 * Filter Channel ON Flag
 * bit 10-8 are for filter channel 2-0.
 * @param pSdadc the base address of the SDADC instance.

 * @return uint32 the value of CHON.
 */
LOCAL_INLINE uint32 SDADC_HWA_GetCHON(const SDADC_Type *const pSdadc)
{
    uint32 u32TmpVal = (pSdadc->MSR & SDADC_MSR_CHON_MASK) >> SDADC_MSR_CHON_SHIFT;
    return u32TmpVal;
}

/**
 * @brief Get the value of the Channel Configuration Register (CCR) for a specified channel.
 *
 * This function retrieves the value of the Channel Configuration Register (CCR) for a given channel
 * in the SDADC instance.
 *
 * @param pSdadc the base address of the SDADC instance.
 * @param u8Channel the channel number for which the CCR value is to be retrieved.
 *
 * @return uint32_t the value of the CCR for the specified channel.
 */
LOCAL_INLINE uint32_t SDADC_HWA_GetCCRn(const SDADC_Type *const pSdadc, uint8_t u8Channel)
{
    return SDADC_CHANNELCFGREG(pSdadc)[u8Channel].CCR;
}

/**
 * @brief Set the value of the Channel Configuration Register (CCR) for a specified channel.
 *
 * This function sets the value of the Channel Configuration Register (CCR) for a given channel
 * in the SDADC instance.
 *
 * @param pSdadc the base address of the SDADC instance.
 * @param u8Channel the channel number for which the CCR value is to be set.
 * @param u32Value the value to be set in the CCR register.
 */
LOCAL_INLINE void SDADC_HWA_SetCCRn(const SDADC_Type *const pSdadc, uint8_t u8Channel, uint32_t u32Value)
{
    SDADC_CHANNELCFGREG(pSdadc)[u8Channel].CCR = u32Value;
}

/**
 * @brief Get the value of LMT_SEL.
 * Limit Check Input Selection
 * Select the input from Main Filter or Auxiliary Filter.
 * 0b - Auxiliary Filter.
 * 1b - Main Filter.
 * @param pSdadc the base address of the SDADC instance.
 * @param u8Channel SDADC Channel.
 * @return uint32_t the value of LMT_SEL.
 */
LOCAL_INLINE uint32_t SDADC_HWA_GetLMT_SEL(const SDADC_Type *const pSdadc, uint8_t u8Channel)
{
    uint32_t u32TmpVal = (SDADC_CHANNELCFGREG(pSdadc)[u8Channel].CCR & SDADC_CCR_LMT_SEL_MASK) >> SDADC_CCR_LMT_SEL_SHIFT;
    return u32TmpVal;
}

/**
 * @brief Get the value of ZCD_SEL.
 * Zero Cross Check Input Selection
 * Select the input from Main Filter or Auxiliary Filter.
 * 0b - Auxiliary Filter.
 * 1b - Main Filter.
 * @param pSdadc the base address of the SDADC instance.
 * @param u8Channel SDADC Channel.
 * @return uint32_t the value of ZCD_SEL.
 */
LOCAL_INLINE uint32_t SDADC_HWA_GetZCD_SEL(const SDADC_Type *const pSdadc, uint8_t u8Channel)
{
    uint32_t u32TmpVal = (SDADC_CHANNELCFGREG(pSdadc)[u8Channel].CCR & SDADC_CCR_ZCD_SEL_MASK) >> SDADC_CCR_ZCD_SEL_SHIFT;
    return u32TmpVal;
}

/**
 * @brief Get the value of DBG_SEL.
 * Debug Output Selection
 * Select which data is output when read debug register
 * 0100b - Instantaneous Primary Filter shifted 24bit Data.
 * 0110b - Instantaneous HPF Output Data.
 * 1000b - Instantaneous GAIN Output Data.
 * 1010b - Instantaneous Secondary Filter CIC Data.
 * 1110b - Instantaneous Primary Filter offset removed 24bit Data.
 * others - Reserved.
 * @param pSdadc the base address of the SDADC instance.
 * @param u8Channel SDADC Channel.
 * @return uint32_t the value of DBG_SEL.
 */
LOCAL_INLINE uint32_t SDADC_HWA_GetDBG_SEL(const SDADC_Type *const pSdadc, uint8_t u8Channel)
{
    uint32_t u32TmpVal = (SDADC_CHANNELCFGREG(pSdadc)[u8Channel].CCR & SDADC_CCR_DBG_SEL_MASK) >> SDADC_CCR_DBG_SEL_SHIFT;
    return u32TmpVal;
}

/**
 * @brief Get the value of INTG_EN.
 * Integration Enable
 * Enable the integration block.
 * 0b - Disabled and bypassed.
 * 1b - Enabled.
 * @param pSdadc the base address of the SDADC instance.
 * @param u8Channel SDADC Channel.
 * @return uint32_t the value of INTG_EN.
 */
LOCAL_INLINE uint32_t SDADC_HWA_GetINTG_EN(const SDADC_Type *const pSdadc, uint8_t u8Channel)
{
    uint32_t u32TmpVal = (SDADC_CHANNELCFGREG(pSdadc)[u8Channel].CCR & SDADC_CCR_INTG_EN_MASK) >> SDADC_CCR_INTG_EN_SHIFT;
    return u32TmpVal;
}

/**
 * @brief Get the value of RECT_EN.
 * Rectification Enable
 * Enable the rectification block.
 * 0b - Disabled and bypassed.
 * 1b - Enabled.
 * @param pSdadc the base address of the SDADC instance.
 * @param u8Channel SDADC Channel.
 * @return uint32_t the value of RECT_EN.
 */
LOCAL_INLINE uint32_t SDADC_HWA_GetRECT_EN(const SDADC_Type *const pSdadc, uint8_t u8Channel)
{
    uint32_t u32TmpVal = (SDADC_CHANNELCFGREG(pSdadc)[u8Channel].CCR & SDADC_CCR_RECT_EN_MASK) >> SDADC_CCR_RECT_EN_SHIFT;
    return u32TmpVal;
}

/**
 * @brief Get the value of FIFO_EN.
 * FIFO Enable
 * 0b - FIFO is disabled for the channel.
 * 1b - FIFO is enabled for the channel.
 * @param pSdadc the base address of the SDADC instance.
 * @param u8Channel SDADC Channel.
 * @return uint32_t the value of FIFO_EN.
 */
LOCAL_INLINE uint32_t SDADC_HWA_GetFIFO_EN(const SDADC_Type *const pSdadc, uint8_t u8Channel)
{
    uint32_t u32TmpVal = (SDADC_CHANNELCFGREG(pSdadc)[u8Channel].CCR & SDADC_CCR_FIFO_EN_MASK) >> SDADC_CCR_FIFO_EN_SHIFT;
    return u32TmpVal;
}

/**
 * @brief Get the value of LMT_EN.
 * Limit Enable
 * 0b - Limit check is disabled for the Main or Auxiliary Filter.
 * 1b - Limit check is enabled for the Main or Auxiliary Filter.
 * @param pSdadc the base address of the SDADC instance.
 * @param u8Channel SDADC Channel.
 * @return uint32_t the value of LMT_EN.
 */
LOCAL_INLINE uint32_t SDADC_HWA_GetLMT_EN(const SDADC_Type *const pSdadc, uint8_t u8Channel)
{
    uint32_t u32TmpVal = (SDADC_CHANNELCFGREG(pSdadc)[u8Channel].CCR & SDADC_CCR_LMT_EN_MASK) >> SDADC_CCR_LMT_EN_SHIFT;
    return u32TmpVal;
}

/**
 * @brief Get the value of ZCD_EN.
 * Zero Cross Detect Enable
 * 0b - Zero cross detection is disabled for the Main or Auxiliary Filter.
 * 1b - Zero cross detection is enabled for the Main or Auxiliary Filter.
 * @param pSdadc the base address of the SDADC instance.
 * @param u8Channel SDADC Channel.
 * @return uint32_t the value of ZCD_EN.
 */
LOCAL_INLINE uint32_t SDADC_HWA_GetZCD_EN(const SDADC_Type *const pSdadc, uint8_t u8Channel)
{
    uint32_t u32TmpVal = (SDADC_CHANNELCFGREG(pSdadc)[u8Channel].CCR & SDADC_CCR_ZCD_EN_MASK) >> SDADC_CCR_ZCD_EN_SHIFT;
    return u32TmpVal;
}

/**
 * @brief Get the value of CAD_EN.
 * Clock Absence Detect Enable
 * 0b - Clock absence detection is disabled for the channel.
 * 1b - Clock absence detection is enabled for the channel.
 * @param pSdadc the base address of the SDADC instance.
 * @param u8Channel SDADC Channel.
 * @return uint32_t the value of CAD_EN.
 */
LOCAL_INLINE uint32_t SDADC_HWA_GetCAD_EN(const SDADC_Type *const pSdadc, uint8_t u8Channel)
{
    uint32_t u32TmpVal = (SDADC_CHANNELCFGREG(pSdadc)[u8Channel].CCR & SDADC_CCR_CAD_EN_MASK) >> SDADC_CCR_CAD_EN_SHIFT;
    return u32TmpVal;
}

/**
 * @brief Get the value of SCD_EN.
 * Short Circuit Detect Enable
 * 0b - Short current detection is disabled for the channel.
 * 1b - Short current detection is enabled for the channel.
 * @param pSdadc the base address of the SDADC instance.
 * @param u8Channel SDADC Channel.
 * @return uint32_t the value of SCD_EN.
 */
LOCAL_INLINE uint32_t SDADC_HWA_GetSCD_EN(const SDADC_Type *const pSdadc, uint8_t u8Channel)
{
    uint32_t u32TmpVal = (SDADC_CHANNELCFGREG(pSdadc)[u8Channel].CCR & SDADC_CCR_SCD_EN_MASK) >> SDADC_CCR_SCD_EN_SHIFT;
    return u32TmpVal;
}

/**
 * @brief Get the value of DMA_EN.
 * DMA Enable
 * 0b - DMA is disabled for the channel.
 * 1b - DMA is enabled for the channel.
 * @param pSdadc the base address of the SDADC instance.
 * @param u8Channel SDADC Channel.
 * @return uint32_t the value of DMA_EN.
 */
LOCAL_INLINE uint32_t SDADC_HWA_GetDMA_EN(const SDADC_Type *const pSdadc, uint8_t u8Channel)
{
    uint32_t u32TmpVal = (SDADC_CHANNELCFGREG(pSdadc)[u8Channel].CCR & SDADC_CCR_DMA_EN_MASK) >> SDADC_CCR_DMA_EN_SHIFT;
    return u32TmpVal;
}

/**
 * @brief Get the value of AF_EN.
 * Auxiliary Filter Enable
 * 0b - The Auxiliary Filter is disabled for the channel.
 * 1b - The Auxiliary Filter is enabled for the channel.
 * @param pSdadc the base address of the SDADC instance.
 * @param u8Channel SDADC Channel.
 * @return uint32_t the value of AF_EN.
 */
LOCAL_INLINE uint32_t SDADC_HWA_GetAF_EN(const SDADC_Type *const pSdadc, uint8_t u8Channel)
{
    uint32_t u32TmpVal = (SDADC_CHANNELCFGREG(pSdadc)[u8Channel].CCR & SDADC_CCR_AF_EN_MASK) >> SDADC_CCR_AF_EN_SHIFT;
    return u32TmpVal;
}

/**
 * @brief Get the value of MF_EN.
 * Main Filter Enable
 * 0b - The Main Filter is disabled for the channel.
 * 1b - The Main Filter is enabled for the channel.
 * @param pSdadc the base address of the SDADC instance.
 * @param u8Channel SDADC Channel.
 * @return uint32_t the value of MF_EN.
 */
LOCAL_INLINE uint32_t SDADC_HWA_GetMF_EN(const SDADC_Type *const pSdadc, uint8_t u8Channel)
{
    uint32_t u32TmpVal = (SDADC_CHANNELCFGREG(pSdadc)[u8Channel].CCR & SDADC_CCR_MF_EN_MASK) >> SDADC_CCR_MF_EN_SHIFT;
    return u32TmpVal;
}

/**
 * @brief Get the value of CH_EN.
 * Channel Enable
 * 0b - The channel is disabled.
 * 0b - The channel is enabled.
 * @param pSdadc the base address of the SDADC instance.
 * @param u8Channel SDADC Channel.
 * @return uint32_t the value of CH_EN.
 */
LOCAL_INLINE uint32_t SDADC_HWA_GetCH_EN(const SDADC_Type *const pSdadc, uint8_t u8Channel)
{
    uint32_t u32TmpVal = (SDADC_CHANNELCFGREG(pSdadc)[u8Channel].CCR & SDADC_CCR_CH_EN_MASK) >> SDADC_CCR_CH_EN_SHIFT;
    return u32TmpVal;
}

/**
 * @brief Set the value of CH_EN.
 * Channel Enable
 * 0b - The channel is disabled.
 * 0b - The channel is enabled.
 * @param pSdadc the base address of the SDADC instance.
 * @param u8Channel SDADC Channel.
 * @param u8Enable SDADC Channel Channel Enable.
 * @return uint32_t the value of CH_EN.
 */
LOCAL_INLINE void SDADC_HWA_SetCH_EN(const SDADC_Type *const pSdadc, uint8_t u8Channel, uint8_t u8Enable)
{
    SDADC_CHANNELCFGREG(pSdadc)[u8Channel].CCR = (SDADC_CHANNELCFGREG(pSdadc)[u8Channel].CCR & ~SDADC_CCR_CH_EN_MASK) | SDADC_CCR_CH_EN(u8Enable);
}

/**
 * @brief Get the value of AFCM.
 * Auxiliary Filter Conversion Mode
 * 0b - Always on.
 * 1b - Follow Main Filter mode (trigger).
 * @param pSdadc the base address of the SDADC instance.
 * @param u8Channel SDADC Channel.
 * @return uint32_t the value of AFCM.
 */
LOCAL_INLINE uint32_t SDADC_HWA_GetAFCM(const SDADC_Type *const pSdadc, uint8_t u8Channel)
{
    uint32_t u32TmpVal = (SDADC_CHANNELCFGREG(pSdadc)[u8Channel].CDR & SDADC_CDR_AFCM_MASK) >> SDADC_CDR_AFCM_SHIFT;
    return u32TmpVal;
}

/**
 * @brief Get the value of AFORD.
 * Auxiliary Filter Order
 * 00b - Reserved.
 * 01b - First order filter.
 * 10b - Second order filter.
 * 11b - Third order filter.
 * @param pSdadc the base address of the SDADC instance.
 * @param u8Channel SDADC Channel.
 * @return uint32_t the value of AFORD.
 */
LOCAL_INLINE uint32_t SDADC_HWA_GetAFORD(const SDADC_Type *const pSdadc, uint8_t u8Channel)
{
    uint32_t u32TmpVal = (SDADC_CHANNELCFGREG(pSdadc)[u8Channel].CDR & SDADC_CDR_AFORD_MASK) >> SDADC_CDR_AFORD_SHIFT;
    return u32TmpVal;
}

/**
 * @brief Get the value of AFOSR.
 * Auxiliary Filter Oversampling Rate
 * The oversampling rate = (AFOSR + 1).
 * The lower valid value of AFOSR is 3.
 * The higher is depended on AFORD, in order to keep the internal CIC raw result not exceeding 24bit. If AFORD = 3, the maximum value is 202, else the maximum value is 511.
 * @param pSdadc the base address of the SDADC instance.
 * @param u8Channel SDADC Channel.
 * @return uint32_t the value of AFOSR.
 */
LOCAL_INLINE uint32_t SDADC_HWA_GetAFOSR(const SDADC_Type *const pSdadc, uint8_t u8Channel)
{
    uint32_t u32TmpVal = (SDADC_CHANNELCFGREG(pSdadc)[u8Channel].CDR & SDADC_CDR_AFOSR_MASK) >> SDADC_CDR_AFOSR_SHIFT;
    return u32TmpVal;
}

/**
 * @brief Get the value of MFCM.
 * Main Filter Conversion Mode
 * 00b - Single mode. One conversion following a triggering event (edge or level).
 * 01b - Continuous conversion mode. Multiple conversions following a triggering event, and the next trigger will cancel and restart conversion.
 * 10b - Always conversion mode. Multiple conversions following the first trigger, and the next trigger will be ignored.
 * 11b - Reserved.
 * @param pSdadc the base address of the SDADC instance.
 * @param u8Channel SDADC Channel.
 * @return uint32_t the value of MFCM.
 */
LOCAL_INLINE uint32_t SDADC_HWA_GetMFCM(const SDADC_Type *const pSdadc, uint8_t u8Channel)
{
    uint32_t u32TmpVal = (SDADC_CHANNELCFGREG(pSdadc)[u8Channel].CDR & SDADC_CDR_MFCM_MASK) >> SDADC_CDR_MFCM_SHIFT;
    return u32TmpVal;
}

/**
 * @brief Get the value of MFORD.
 * Main Filter Order
 * 000b - Reserved.
 * 001b - First order filter.
 * 010b - Second order filter.
 * 011b - Third order filter.
 * 100b - Fourth order filter.
 * 101b - Fifth order filter.
 * 110,111 - Reserved.
 * @param pSdadc the base address of the SDADC instance.
 * @param u8Channel SDADC Channel.
 * @return uint32_t the value of MFORD.
 */
LOCAL_INLINE uint32_t SDADC_HWA_GetMFORD(const SDADC_Type *const pSdadc, uint8_t u8Channel)
{
    uint32_t u32TmpVal = (SDADC_CHANNELCFGREG(pSdadc)[u8Channel].CDR & SDADC_CDR_MFORD_MASK) >> SDADC_CDR_MFORD_SHIFT;
    return u32TmpVal;
}

/**
 * @brief Get the value of MFOSR.
 * Main Filter Oversampling Rate
 * The oversampling rate = (MFOSR + 1).
 * The lower valid of MFOSR value is 3.
 * The higher is depended on MFORD, in order to keep the internal CIC raw result not exceeding 32bit. If MFORD = 4, the maximum value is 203. If MFORD = 5, the maximum value is 72, else the maximum value is 511.
 * @param pSdadc the base address of the SDADC instance.
 * @param u8Channel SDADC Channel.
 * @return uint32_t the value of MFOSR.
 */
LOCAL_INLINE uint32_t SDADC_HWA_GetMFOSR(const SDADC_Type *const pSdadc, uint8_t u8Channel)
{
    uint32_t u32TmpVal = (SDADC_CHANNELCFGREG(pSdadc)[u8Channel].CDR & SDADC_CDR_MFOSR_MASK) >> SDADC_CDR_MFOSR_SHIFT;
    return u32TmpVal;
}

/**
 * @brief Get the value of SYNC_TRGEN.
 * Synced Trigger Select Enable
 * 0b - Synced trigger is selected on the channel itself.
 * 1b - Synced trigger is selected on the channel defined by SYNC_TRGSEL.
 * @param pSdadc the base address of the SDADC instance.
 * @param u8Channel SDADC Channel.
 * @return uint32_t the value of SYNC_TRGEN.
 */
LOCAL_INLINE uint32_t SDADC_HWA_GetCFR_SYNC_TRGEN(const SDADC_Type *const pSdadc, uint8_t u8Channel)
{
    uint32_t u32TmpVal = (SDADC_CHANNELCFGREG(pSdadc)[u8Channel].CFR & SDADC_CFR_SYNC_TRGEN_MASK) >> SDADC_CFR_SYNC_TRGEN_SHIFT;
    return u32TmpVal;
}

/**
 * @brief Get the value of TRGLVL.
 * Trigger Level type
 * 0b - Trigger is edge event. Next edge event will cancel the current conversion, and re-start in single or continuous mode.
 * 1b - Trigger is level event. De-assert cancels the current conversion, and stop filter function in single or continuous mode.
 * @param pSdadc the base address of the SDADC instance.
 * @param u8Channel SDADC Channel.
 * @return uint32_t the value of TRGLVL.
 */
LOCAL_INLINE uint32_t SDADC_HWA_GetTRGLVL(const SDADC_Type *const pSdadc, uint8_t u8Channel)
{
    uint32_t u32TmpVal = (SDADC_CHANNELCFGREG(pSdadc)[u8Channel].CFR & SDADC_CFR_TRGLVL_MASK) >> SDADC_CFR_TRGLVL_SHIFT;
    return u32TmpVal;
}

/**
 * @brief Get the value of SYNC_TRGSEL.
 * Synced Trigger Select
 * Each will detect and sync the trigger input as a synced trigger, this bits can select to use the synced trigger from which channel. By this bits, two or more channels can share the same synced trigger and trigger to start at the same time.
 * 000b - select the trigger from the channel 0.
 * 001b - select the trigger from the channel 1.
 * 010b - select the trigger from the channel 2.
 * ...
 * @param pSdadc the base address of the SDADC instance.
 * @param u8Channel SDADC Channel.
 * @return uint32_t the value of SYNC_TRGSEL.
 */
LOCAL_INLINE uint32_t SDADC_HWA_GetSYNC_TRGSEL(const SDADC_Type *const pSdadc, uint8_t u8Channel)
{
    uint32_t u32TmpVal = (SDADC_CHANNELCFGREG(pSdadc)[u8Channel].CFR & SDADC_CFR_SYNC_TRGSEL_MASK) >> SDADC_CFR_SYNC_TRGSEL_SHIFT;
    return u32TmpVal;
}

/**
 * @brief Get the value of TRGSEL.
 * Trigger Select
 * 0b - Software trigger is selected.
 * 1b - Hardware trigger is selected.
 * @param pSdadc the base address of the SDADC instance.
 * @param u8Channel SDADC Channel.
 * @return uint32_t the value of TRGSEL.
 */
LOCAL_INLINE uint32_t SDADC_HWA_GetTRGSEL(const SDADC_Type *const pSdadc, uint8_t u8Channel)
{
    uint32_t u32TmpVal = (SDADC_CHANNELCFGREG(pSdadc)[u8Channel].CFR & SDADC_CFR_TRGSEL_MASK) >> SDADC_CFR_TRGSEL_SHIFT;
    return u32TmpVal;
}

/**
 * @brief Get the value of CLKEDG.
 * Input Clock Edge Select
 * This bits select the effective edge of the modulator clock recovery to generate mclk. When using on chip modulator, only posedge is supported.
 * 01b - Posedge.
 * 10b - Negedge.
 * 11b - Both edge.
 * 00b - Reserved.
 * @param pSdadc the base address of the SDADC instance.
 * @param u8Channel SDADC Channel.
 * @return uint32_t the value of CLKEDG.
 */
LOCAL_INLINE uint32_t SDADC_HWA_GetCLKEDG(const SDADC_Type *const pSdadc, uint8_t u8Channel)
{
    uint32_t u32TmpVal = (SDADC_CHANNELCFGREG(pSdadc)[u8Channel].CFR & SDADC_CFR_CLKEDG_MASK) >> SDADC_CFR_CLKEDG_SHIFT;
    return u32TmpVal;
}

/**
 * @brief Get the value of CLKSEL.
 * Input Clock Select
 * This bits select the clock source for the clock recovery to generate mclk.
 * 00b - Reserved.
 * 01b - Internal generated function clock div_clk1 selected, used for the case where MA is using div_clk0 as its function clock. The clock recovery is worked in sync mode.
 * 10b - Internal generated function clock div_clk2 selected, used for the case where MA is using div_clk1 as its function clock. The clock recovery is worked in sync mode.
 * 11b - Modulator clock from external modulator selected. The clock recovery is worked in async mode.
 * @param pSdadc the base address of the SDADC instance.
 * @param u8Channel SDADC Channel.
 * @return uint32_t the value of CLKSEL.
 */
LOCAL_INLINE uint32_t SDADC_HWA_GetCFRCLKSEL(const SDADC_Type *const pSdadc, uint8_t u8Channel)
{
    uint32_t u32TmpVal = (SDADC_CHANNELCFGREG(pSdadc)[u8Channel].CFR & SDADC_CFR_CLKSEL_MASK) >> SDADC_CFR_CLKSEL_SHIFT;
    return u32TmpVal;
}

/**
 * @brief Get the value of IBFMT.
 * Input Bit Format
 * 00b - External one bit stream.
 * 01b - External Manchester code, CLKEDG will determine rise or fall decoder.
 * 10b - Reserved.
 * 11b - Reserved.
 * @param pSdadc the base address of the SDADC instance.
 * @param u8Channel SDADC Channel.
 * @return uint32_t the value of IBFMT.
 */
LOCAL_INLINE uint32_t SDADC_HWA_GetIBFMT(const SDADC_Type *const pSdadc, uint8_t u8Channel)
{
    uint32_t u32TmpVal = (SDADC_CHANNELCFGREG(pSdadc)[u8Channel].CFR & SDADC_CFR_IBFMT_MASK) >> SDADC_CFR_IBFMT_SHIFT;
    return u32TmpVal;
}

/**
 * @brief Get the value of FWMK.
 * FIFO Water Mark
 * Controls the watermark of the FIFO used to set FRDYn. When the number of results in the FIFO is greater than FWMK value, the FRDYn flag will be set. A DMA request or interrupt can also be generated if related DMA_EN and FRDYIE bit-field is set.
 * @param pSdadc the base address of the SDADC instance.
 * @param u8Channel SDADC Channel.
 * @return uint32_t the value of FWMK.
 */
LOCAL_INLINE uint32_t SDADC_HWA_GetFWMK(const SDADC_Type *const pSdadc, uint8_t u8Channel)
{
    uint32_t u32TmpVal = (SDADC_CHANNELCFGREG(pSdadc)[u8Channel].CFR & SDADC_CFR_FWMK_MASK) >> SDADC_CFR_FWMK_SHIFT;
    return u32TmpVal;
}

/**
 * @brief Get the value of CUTOFF.
 * Cutoff Frequency Setting for High Pass Filter(HPF)
 * HPF can only be enabled when RDFMT=0.
 * 000b - HPF is disabled
 * 001b - HPF is enabled and setting the cutoff frequency to rate 1(lowest cutoff frequency)
 * ��
 * 111b - HPF is enabled and setting the cutoff frequency to rate 7.(highest cutoff frequency)
 * @param pSdadc the base address of the SDADC instance.
 * @param u8Channel SDADC Channel.
 * @return uint32_t the value of CUTOFF.
 */
LOCAL_INLINE uint32_t SDADC_HWA_GetCUTOFF(const SDADC_Type *const pSdadc, uint8_t u8Channel)
{
    uint32_t u32TmpVal = (SDADC_CHANNELCFGREG(pSdadc)[u8Channel].CFR & SDADC_CFR_CUTOFF_MASK) >> SDADC_CFR_CUTOFF_SHIFT;
    return u32TmpVal;
}

/**
 * @brief Get the value of RDFMT.
 * Result Data Format
 * 0b - Left justified, signed, for the case where input bitstream is signed
 * 1b - Left justified, unsigned, for the case where input bitstream is unsigned
 * @param pSdadc the base address of the SDADC instance.
 * @param u8Channel SDADC Channel.
 * @return uint32_t the value of RDFMT.
 */
LOCAL_INLINE uint32_t SDADC_HWA_GetRDFMT(const SDADC_Type *const pSdadc, uint8_t u8Channel)
{
    uint32_t u32TmpVal = (SDADC_CHANNELCFGREG(pSdadc)[u8Channel].CFR & SDADC_CFR_RDFMT_MASK) >> SDADC_CFR_RDFMT_SHIFT;
    return u32TmpVal;
}

/**
 * @brief Get the value of MFSHIFT.
 * Main Filter Shift to Get Correct 24 bit Precision
 * Main Filter CIC raw result is always 32bit width. The user should program MFSHIFT for cut-off and shift left/right to get 24bit result.
 * MFSHIFT[4] = 1 means left shift, and MFSHIFT[4] = 0 means right shift.
 * MFSHIFT[3:0] is the shift length.
 * @param pSdadc the base address of the SDADC instance.
 * @param u8Channel SDADC Channel.
 * @return uint32_t the value of MFSHIFT.
 */
LOCAL_INLINE uint32_t SDADC_HWA_GetMFSHIFT(const SDADC_Type *const pSdadc, uint8_t u8Channel)
{
    uint32_t u32TmpVal = (SDADC_CHANNELCFGREG(pSdadc)[u8Channel].CFR & SDADC_CFR_MFSHIFT_MASK) >> SDADC_CFR_MFSHIFT_SHIFT;
    return u32TmpVal;
}

/**
 * @brief Get the value of the Channel Protection Register (CPR) for a specified channel.
 *
 * This function retrieves the value of the Channel Protection Register (CPR) for a given channel
 * in the SDADC instance.
 *
 * @param pSdadc the base address of the SDADC instance.
 * @param u8Channel the channel number for which the CPR value is to be retrieved.
 *
 * @return uint32_t the value of the CPR for the specified channel.
 */
LOCAL_INLINE uint32_t SDADC_HWA_GetCPRn(const SDADC_Type *const pSdadc, uint8_t u8Channel)
{
    return SDADC_CHANNELCFGREG(pSdadc)[u8Channel].CPR;
}

/**
 * @brief Set the value of the Channel Protection Register (CPR) for a specified channel.
 *
 * This function sets the value of the Channel Protection Register (CPR) for a given channel
 * in the SDADC instance.
 *
 * @param pSdadc the base address of the SDADC instance.
 * @param u8Channel the channel number for which the CPR value is to be set.
 * @param u32Value the value to be set in the CPR register.
 */
LOCAL_INLINE void SDADC_HWA_SetCPRn(const SDADC_Type *const pSdadc, uint8_t u8Channel, uint32_t u32Value)
{
    SDADC_CHANNELCFGREG(pSdadc)[u8Channel].CPR = u32Value;
}

/**
 * @brief Get the value of HLMT_BKEN.
 * Break Signal Enable for High Limit Event
 * 0b - The Break signal is not enabled.
 * 1b - The Break signal is enabled.
 * @param pSdadc the base address of the SDADC instance.
 * @param u8Channel SDADC Channel.
 * @return uint32_t the value of HLMT_BKEN.
 */
LOCAL_INLINE uint32_t SDADC_HWA_GetHLMT_BKEN(const SDADC_Type *const pSdadc, uint8_t u8Channel)
{
    uint32_t u32TmpVal = (SDADC_CHANNELCFGREG(pSdadc)[u8Channel].CPR & SDADC_CPR_HLMT_BKEN_MASK) >> SDADC_CPR_HLMT_BKEN_SHIFT;
    return u32TmpVal;
}

/**
 * @brief Get the value of WLMT_BKEN.
 * Break Signal Enabled for Window Limit Event
 * 0b - The Break signal is not enabled.
 * 1b - The Break signal is enabled.
 * @param pSdadc the base address of the SDADC instance.
 * @param u8Channel SDADC Channel.
 * @return uint32_t the value of WLMT_BKEN.
 */
LOCAL_INLINE uint32_t SDADC_HWA_GetWLMT_BKEN(const SDADC_Type *const pSdadc, uint8_t u8Channel)
{
    uint32_t u32TmpVal = (SDADC_CHANNELCFGREG(pSdadc)[u8Channel].CPR & SDADC_CPR_WLMT_BKEN_MASK) >> SDADC_CPR_WLMT_BKEN_SHIFT;
    return u32TmpVal;
}

/**
 * @brief Get the value of LLMT_BKEN.
 * Break Signal Enabled for Low Limit Event
 * 0b - The Break signal is not enabled.
 * 1b - The Break signal is enabled.
 * @param pSdadc the base address of the SDADC instance.
 * @param u8Channel SDADC Channel.
 * @return uint32_t the value of LLMT_BKEN.
 */
LOCAL_INLINE uint32_t SDADC_HWA_GetLLMT_BKEN(const SDADC_Type *const pSdadc, uint8_t u8Channel)
{
    uint32_t u32TmpVal = (SDADC_CHANNELCFGREG(pSdadc)[u8Channel].CPR & SDADC_CPR_LLMT_BKEN_MASK) >> SDADC_CPR_LLMT_BKEN_SHIFT;
    return u32TmpVal;
}

/**
 * @brief Get the value of SCD_BKEN.
 * Break Signal Enabled for Short Circuit Event
 * 0b - The Break signal is not enabled.
 * 1b - The Break signal is enabled.
 * @param pSdadc the base address of the SDADC instance.
 * @param u8Channel SDADC Channel.
 * @return uint32_t the value of SCD_BKEN.
 */
LOCAL_INLINE uint32_t SDADC_HWA_GetSCD_BKEN(const SDADC_Type *const pSdadc, uint8_t u8Channel)
{
    uint32_t u32TmpVal = (SDADC_CHANNELCFGREG(pSdadc)[u8Channel].CPR & SDADC_CPR_SCD_BKEN_MASK) >> SDADC_CPR_SCD_BKEN_SHIFT;
    return u32TmpVal;
}

/**
 * @brief Get the value of CAD_BKEN.
 * Break Signal Enabled for Clock Absence Event
 * 0b - The Break signal is not enabled.
 * 1b - The Break signal is enabled.
 * @param pSdadc the base address of the SDADC instance.
 * @param u8Channel SDADC Channel.
 * @return uint32_t the value of CAD_BKEN.
 */
LOCAL_INLINE uint32_t SDADC_HWA_GetCAD_BKEN(const SDADC_Type *const pSdadc, uint8_t u8Channel)
{
    uint32_t u32TmpVal = (SDADC_CHANNELCFGREG(pSdadc)[u8Channel].CPR & SDADC_CPR_CAD_BKEN_MASK) >> SDADC_CPR_CAD_BKEN_SHIFT;
    return u32TmpVal;
}

/**
 * @brief Get the value of LMTF_PROTEN.
 * Protection Singal Enabled for Limit Flag
 * The protection signal can be enabled and sent to TRGSEL for application protection function. LMTOPT can be used to select which limit flag(HLMT/LLMT/WLMT) is used as the protection source. This protection signal can only be cleared by W1C of related flag reigsters.
 * 0b - The Protection signal is not enabled.
 * 1b - The Protection signal is enabled.
 * @param pSdadc the base address of the SDADC instance.
 * @param u8Channel SDADC Channel.
 * @return uint32_t the value of LMTF_PROTEN.
 */
LOCAL_INLINE uint32_t SDADC_HWA_GetLMTF_PROTEN(const SDADC_Type *const pSdadc, uint8_t u8Channel)
{
    uint32_t u32TmpVal = (SDADC_CHANNELCFGREG(pSdadc)[u8Channel].CPR & SDADC_CPR_LMTF_PROTEN_MASK) >> SDADC_CPR_LMTF_PROTEN_SHIFT;
    return u32TmpVal;
}

/**
 * @brief Get the value of LMTR_PROTEN.
 * Protection Singal Enabled for Limit Result
 * The protection signal can be enabled and sent to TRGSEL for application protection function. LMTOPT can be used to select which limit result(high/low/window limit result) is used as the protection source. This protection signal will keep on if related condition keeps(keep high/keep low/keep in window) until the condition is not satisfied.
 * 0b - The Protection signal is not enabled.
 * 1b - The Protection signal is enabled.
 * @param pSdadc the base address of the SDADC instance.
 * @param u8Channel SDADC Channel.
 * @return uint32_t the value of LMTR_PROTEN.
 */
LOCAL_INLINE uint32_t SDADC_HWA_GetLMTR_PROTEN(const SDADC_Type *const pSdadc, uint8_t u8Channel)
{
    uint32_t u32TmpVal = (SDADC_CHANNELCFGREG(pSdadc)[u8Channel].CPR & SDADC_CPR_LMTR_PROTEN_MASK) >> SDADC_CPR_LMTR_PROTEN_SHIFT;
    return u32TmpVal;
}

/**
 * @brief Get the value of HYSTR_PROTEN.
 * Protection Singal Enabled for Limit Hysteresis Result
 * The protection signal can be enabled and sent to TRGSEL for application protection function. This protection signal is from the result of hysteresis comparator in limit detector and will keep on if related condition keeps(keep high/keep low) until the condition is not satisfied.
 * 0b - The Protection signal is not enabled.
 * 1b - The Protection signal is enabled.
 * @param pSdadc the base address of the SDADC instance.
 * @param u8Channel SDADC Channel.
 * @return uint32_t the value of HYSTR_PROTEN.
 */
LOCAL_INLINE uint32_t SDADC_HWA_GetHYSTR_PROTEN(const SDADC_Type *const pSdadc, uint8_t u8Channel)
{
    uint32_t u32TmpVal = (SDADC_CHANNELCFGREG(pSdadc)[u8Channel].CPR & SDADC_CPR_HYSTR_PROTEN_MASK) >> SDADC_CPR_HYSTR_PROTEN_SHIFT;
    return u32TmpVal;
}

/**
 * @brief Get the value of SCD_PROTEN.
 * Protection Singal Enabled for SCD Flag
 * The protection signal can be enabled and sent to TRGSEL for application protection function. This protection signal can only be cleared by W1C of related flag reigsters.
 * 0b - The Protection signal is not enabled.
 * 1b - The Protection signal is enabled.
 * @param pSdadc the base address of the SDADC instance.
 * @param u8Channel SDADC Channel.
 * @return uint32_t the value of SCD_PROTEN.
 */
LOCAL_INLINE uint32_t SDADC_HWA_GetSCD_PROTEN(const SDADC_Type *const pSdadc, uint8_t u8Channel)
{
    uint32_t u32TmpVal = (SDADC_CHANNELCFGREG(pSdadc)[u8Channel].CPR & SDADC_CPR_SCD_PROTEN_MASK) >> SDADC_CPR_SCD_PROTEN_SHIFT;
    return u32TmpVal;
}

/**
 * @brief Get the value of CAD_PROTEN.
 * Protection Singal Enabled for CAD Flag
 * The protection signal can be enabled and sent to TRGSEL for application protection function. This protection signal can only be cleared by W1C of related flag reigsters.
 * 0b - The Protection signal is not enabled.
 * 1b - The Protection signal is enabled.
 * @param pSdadc the base address of the SDADC instance.
 * @param u8Channel SDADC Channel.
 * @return uint32_t the value of CAD_PROTEN.
 */
LOCAL_INLINE uint32_t SDADC_HWA_GetCAD_PROTEN(const SDADC_Type *const pSdadc, uint8_t u8Channel)
{
    uint32_t u32TmpVal = (SDADC_CHANNELCFGREG(pSdadc)[u8Channel].CPR & SDADC_CPR_CAD_PROTEN_MASK) >> SDADC_CPR_CAD_PROTEN_SHIFT;
    return u32TmpVal;
}

/**
 * @brief Get the value of LMTAVT.
 * Limitation Result Activation Select
 * The conversion results are compared with HILMTn and LOLMTn in limit detector, and HILMTn and LOLMTn can define a hysteresis range ,  A compare result is set/clear and sent to system with configurable activation.
 * Note, When this hysteresis compare function is used in system, LMTOPTn need to be 00b to enable detect on exceed both high and low value.
 * 0b - The compare result is set only when the conversion result is larger than HILMTn and clear only when the conversion result is smaller than LOLMTn.
 * 1b - The compare result is clear only when the conversion result is larger than HILMTn and set only when the conversion result is smaller than LOLMTn.
 * @param pSdadc the base address of the SDADC instance.
 * @param u8Channel SDADC Channel.
 * @return uint32_t the value of LMTAVT.
 */
LOCAL_INLINE uint32_t SDADC_HWA_GetLMTAVT(const SDADC_Type *const pSdadc, uint8_t u8Channel)
{
    uint32_t u32TmpVal = (SDADC_CHANNELCFGREG(pSdadc)[u8Channel].CPR & SDADC_CPR_LMTAVT_MASK) >> SDADC_CPR_LMTAVT_SHIFT;
    return u32TmpVal;
}

/**
 * @brief Get the value of CADLMT.
 * Clock Absence Detector Limitation Threshold
 * The threshold value for the clock absence counter.
 * The counter indicates the number of cycles the modulator clock not detected. If this value is reached, a clock absence detector event will occur on the dedicated channel.
 * @param pSdadc the base address of the SDADC instance.
 * @param u8Channel SDADC Channel.
 * @return uint32_t the value of CADLMT.
 */
LOCAL_INLINE uint32_t SDADC_HWA_GetCADLMT(const SDADC_Type *const pSdadc, uint8_t u8Channel)
{
    uint32_t u32TmpVal = (SDADC_CHANNELCFGREG(pSdadc)[u8Channel].CPR & SDADC_CPR_CADLMT_MASK) >> SDADC_CPR_CADLMT_SHIFT;
    return u32TmpVal;
}

/**
 * @brief Get the value of LMTOPT.
 * Limitation Option
 * 00b - Limitation detect on exceed both high and low value.
 * 01b - Limitation detect on exceed high threshold value.
 * 10b - Limitation detect on exceed low threshold value.
 * 11b - Limitation detect on windowed value.
 * @param pSdadc the base address of the SDADC instance.
 * @param u8Channel SDADC Channel.
 * @return uint32_t the value of LMTOPT.
 */
LOCAL_INLINE uint32_t SDADC_HWA_GetLMTOPT(const SDADC_Type *const pSdadc, uint8_t u8Channel)
{
    uint32_t u32TmpVal = (SDADC_CHANNELCFGREG(pSdadc)[u8Channel].CPR & SDADC_CPR_LMTOPT_MASK) >> SDADC_CPR_LMTOPT_SHIFT;
    return u32TmpVal;
}

/**
 * @brief Get the value of SCDOPT.
 * Short Circuit Option
 * 00b - Count on both 0 and 1. Detect both high and low value.
 * 01b - Count on 1. Detect high value.
 * 10b - Count on 0. Detect low value.
 * 11b - Reserved.
 * @param pSdadc the base address of the SDADC instance.
 * @param u8Channel SDADC Channel.
 * @return uint32_t the value of SCDOPT.
 */
LOCAL_INLINE uint32_t SDADC_HWA_GetSCDOPT(const SDADC_Type *const pSdadc, uint8_t u8Channel)
{
    uint32_t u32TmpVal = (SDADC_CHANNELCFGREG(pSdadc)[u8Channel].CPR & SDADC_CPR_SCDOPT_MASK) >> SDADC_CPR_SCDOPT_SHIFT;
    return u32TmpVal;
}

/**
 * @brief Get the value of SCDCM.
 * Short Circuit Detect Conversion Mode
 * 0b - Always on when CHEN and MEN are asserted.
 * 1b - Only works when the any filter is in progress.
 * @param pSdadc the base address of the SDADC instance.
 * @param u8Channel SDADC Channel.
 * @return uint32_t the value of SCDCM.
 */
LOCAL_INLINE uint32_t SDADC_HWA_GetSCDCM(const SDADC_Type *const pSdadc, uint8_t u8Channel)
{
    uint32_t u32TmpVal = (SDADC_CHANNELCFGREG(pSdadc)[u8Channel].CPR & SDADC_CPR_SCDCM_MASK) >> SDADC_CPR_SCDCM_SHIFT;
    return u32TmpVal;
}

/**
 * @brief Get the value of SCDLMT.
 * Short Circuit Detector Limitation extension
 * The threshold value for short circuit detector counter.
 * The counter indicates the number of continuous received bit 0 or bit 1. If this value is reached, a short-circuit detector event will occur on the dedicated channel.
 * @param pSdadc the base address of the SDADC instance.
 * @param u8Channel SDADC Channel.
 * @return uint32_t the value of SCDLMT.
 */
LOCAL_INLINE uint32_t SDADC_HWA_GetSCDLMT(const SDADC_Type *const pSdadc, uint8_t u8Channel)
{
    uint32_t u32TmpVal = (SDADC_CHANNELCFGREG(pSdadc)[u8Channel].CPR & SDADC_CPR_SCDLMT_MASK) >> SDADC_CPR_SCDLMT_SHIFT;
    return u32TmpVal;
}

/**
 * @brief Get the value of BIAS.
 * Bias Value
 * Bias offset for dedicated channel main filter; used for sign adjustment and compensation. It's a signed data. The main filter data after shift, will subtract this bias value.
 * @param pSdadc the base address of the SDADC instance.
 * @param u8Channel SDADC Channel.
 * @return uint32_t the value of BIAS.
 */
LOCAL_INLINE uint32_t SDADC_HWA_GetBIAS(const SDADC_Type *const pSdadc, uint8_t u8Channel)
{
    uint32_t u32TmpVal = (SDADC_CHANNELCFGREG(pSdadc)[u8Channel].CBR & SDADC_CBR_BIAS_MASK) >> SDADC_CBR_BIAS_SHIFT;
    return u32TmpVal;
}

/**
 * @brief Set the value of BIAS.
 * Bias Value
 * Bias offset for dedicated channel main filter; used for sign adjustment and compensation. It's a signed data. The main filter data after shift, will subtract this bias value.
 * @param pSdadc the base address of the SDADC instance.
 * @param u8Channel SDADC Channel.
 * @param u32Value Bias value.
 * @return uint32_t the value of BIAS.
 */
LOCAL_INLINE void SDADC_HWA_SetBIAS(const SDADC_Type *const pSdadc, uint8_t u8Channel, uint32 u32Value)
{
    SDADC_CHANNELCFGREG(pSdadc)[u8Channel].CBR = (SDADC_CHANNELCFGREG(pSdadc)[u8Channel].CBR & ~SDADC_CBR_BIAS_MASK) | SDADC_CBR_BIAS(u32Value);
}

/**
 * @brief Get the value of LOLMT.
 * Low Limit Threshold
 * When the data value exceeds this value, a low limit event will occur. The limit value format (signed or unsigned) depends on RDFMT.
 * @param pSdadc the base address of the SDADC instance.
 * @param u8Channel SDADC Channel.
 * @return uint32_t the value of LOLMT.
 */
LOCAL_INLINE uint32_t SDADC_HWA_GetLOLMT(const SDADC_Type *const pSdadc, uint8_t u8Channel)
{
    uint32_t u32TmpVal = (SDADC_CHANNELCFGREG(pSdadc)[u8Channel].CLLMT & SDADC_CLLMT_LOLMT_MASK) >> SDADC_CLLMT_LOLMT_SHIFT;
    return u32TmpVal;
}

/**
 * @brief Get the value of HILMT.
 * High Limit Threshold
 * When data value exceeds this value, high limit event will occur. The limit value format (signed or unsigned) is depended on RDFMT
 * @param pSdadc the base address of the SDADC instance.
 * @param u8Channel SDADC Channel.
 * @return uint32_t the value of HILMT.
 */
LOCAL_INLINE uint32_t SDADC_HWA_GetHILMT(const SDADC_Type *const pSdadc, uint8_t u8Channel)
{
    uint32_t u32TmpVal = (SDADC_CHANNELCFGREG(pSdadc)[u8Channel].CHLMT & SDADC_CHLMT_HILMT_MASK) >> SDADC_CHLMT_HILMT_SHIFT;
    return u32TmpVal;
}

/**
 * @brief Get the value of RDATA.
 * Result Data
 * Read this register to get the conversion results. Bit[31] is sign bit if RDFMT is signed and only support 32bit read.
 * The data format may changed by TSRDM.
 * When TSRDM=2'b00, read CRDATA will pop data from FIFO. RDATA[31:8] is a 24-bit conversion results and RDATA[7:0] is 8'h00. At this case, CRDATA can only be read when FIFO is enabled and not empty.
 * When TSRDM=2'b01, read CRDATA will feedback latest conversion result and timestamp info, RDATA[31:16] is a cut and round 16-bit latest conversion result(update on last COC) and RDATA[15:0] is latest timestamp counter value. FIFO is not used.At this case, CRDATA can only be read at any time.
 * When TSRDM=2'b10, read CRDATA will pop data from FIFO and a timestamp info captured by trigger will also be included. RDATA[31:16] is a cut and round 16-bit result from FIFO and RDATA[15:0] is captured timestamp counter value. FIFO is used and gated by timestamp trigger. At this case, CRDATA can only be read when FIFO is enabled and not empty.
 * @param pSdadc the base address of the SDADC instance.
 * @param u8Channel SDADC Channel.
 * @return uint32_t the value of RDATA.
 */
LOCAL_INLINE uint32_t SDADC_HWA_GetRDATA(const SDADC_Type *const pSdadc, uint8_t u8Channel)
{
    uint32_t u32TmpVal = (SDADC_CHANNELCFGREG(pSdadc)[u8Channel].CRDATA & SDADC_CRDATA_RDATA_MASK) >> SDADC_CRDATA_RDATA_SHIFT;
    return u32TmpVal;
}

/**
 * @brief Get the value of MPDATA.
 * Multi Purpose Data
 * This register can be accessed by DBG_SEL.
 * @param pSdadc the base address of the SDADC instance.
 * @param u8Channel SDADC Channel.
 * @return uint32_t the value of MPDATA.
 */
LOCAL_INLINE uint32_t SDADC_HWA_GetMPDATA(const SDADC_Type *const pSdadc, uint8_t u8Channel)
{
    uint32_t u32TmpVal = (SDADC_CHANNELCFGREG(pSdadc)[u8Channel].CMPDATA & SDADC_CMPDATA_MPDATA_MASK) >> SDADC_CMPDATA_MPDATA_SHIFT;
    return u32TmpVal;
}

/**
 * @brief Get the value of SIGN.
 * Sign Signal for the PWM pattern
 * 0b - Positive values
 * 1b - Negative values
 * @param pSdadc the base address of the SDADC instance.

 * @return uint32_t the value of SIGN.
 */
LOCAL_INLINE uint32_t SDADC_HWA_GetSIGN(const SDADC_Type *const pSdadc)
{
    uint32_t u32TmpVal = (pSdadc->PWM_GEN & SDADC_PWM_GEN_SIGN_MASK) >> SDADC_PWM_GEN_SIGN_SHIFT;
    return u32TmpVal;
}

/**
 * @brief Get the value of PWM_CNT.
 * PWM Counter Value
 * Counts the 32 cycles for each PWM pattern step.(-16 to 15)
 * @param pSdadc the base address of the SDADC instance.

 * @return uint32_t the value of PWM_CNT.
 */
LOCAL_INLINE uint32_t SDADC_HWA_GetPWM_CNT(const SDADC_Type *const pSdadc)
{
    uint32_t u32TmpVal = (pSdadc->PWM_GEN & SDADC_PWM_GEN_PWM_CNT_MASK) >> SDADC_PWM_GEN_PWM_CNT_SHIFT;
    return u32TmpVal;
}

/**
 * @brief Get the value of PAT_CNT.
 * PWM Pattern Counter Value
 * Counts the 32 steps for each PWM pattern period.
 * @param pSdadc the base address of the SDADC instance.

 * @return uint32_t the value of PAT_CNT.
 */
LOCAL_INLINE uint32_t SDADC_HWA_GetPAT_CNT(const SDADC_Type *const pSdadc)
{
    uint32_t u32TmpVal = (pSdadc->PWM_GEN & SDADC_PWM_GEN_PAT_CNT_MASK) >> SDADC_PWM_GEN_PAT_CNT_SHIFT;
    return u32TmpVal;
}

/**
 * @brief Get the value of ON.
 * ON Status
 * 0b - PWM generator is stopped
 * 1b - PWM generator is ON
 * @param pSdadc the base address of the SDADC instance.

 * @return uint32_t the value of ON.
 */
LOCAL_INLINE uint32_t SDADC_HWA_GetON(const SDADC_Type *const pSdadc)
{
    uint32_t u32TmpVal = (pSdadc->PWM_GEN & SDADC_PWM_GEN_ON_MASK) >> SDADC_PWM_GEN_ON_SHIFT;
    return u32TmpVal;
}

/**
 * @brief Get the value of TRGSIGN_OEN.
 * Sign Signal Related Trigger Out Enable
 * 0b - disabled.
 * 1b - Related trigger is enabled and will be set once SIGN falling edge is got.
 * @param pSdadc the base address of the SDADC instance.

 * @return uint32_t the value of TRGSIGN_OEN.
 */
LOCAL_INLINE uint32_t SDADC_HWA_GetTRGSIGN_OEN(const SDADC_Type *const pSdadc)
{
    uint32_t u32TmpVal = (pSdadc->PWM_GEN & SDADC_PWM_GEN_TRGSIGN_OEN_MASK) >> SDADC_PWM_GEN_TRGSIGN_OEN_SHIFT;
    return u32TmpVal;
}

/**
 * @brief Set TRGSIGN_OEN.
 * Sign Signal Related Trigger Out Enable
 * 0b - disabled.
 * 1b - Related trigger is enabled and will be set once SIGN falling edge is got.
 * @param pSdadc the base address of the SDADC instance.

 * @param uint32_t u32Value TRGSIGN_OEN value.
 */
LOCAL_INLINE void SDADC_HWA_SetTRGSIGN_OEN(SDADC_Type *const pSdadc, uint32_t u32Value)
{
    pSdadc->PWM_GEN = (pSdadc->PWM_GEN & ~SDADC_PWM_GEN_TRGSIGN_OEN_MASK) | SDADC_PWM_GEN_TRGSIGN_OEN(u32Value);
}

/**
 * @brief Get the value of CLKSEL.
 * PWM Generator Clock selection
 * 00b - div_clk0
 * 01b - div_clk1
 * 10b - div_clk2
 * 11b - off
 * @param pSdadc the base address of the SDADC instance.

 * @return uint32_t the value of CLKSEL.
 */
LOCAL_INLINE uint32_t SDADC_HWA_GetPWMCLKSEL(const SDADC_Type *const pSdadc)
{
    uint32_t u32TmpVal = (pSdadc->PWM_GEN & SDADC_PWM_GEN_CLKSEL_MASK) >> SDADC_PWM_GEN_CLKSEL_SHIFT;
    return u32TmpVal;
}

/**
 * @brief Set CLKSEL.
 * PWM Generator Clock selection
 * 00b - div_clk0
 * 01b - div_clk1
 * 10b - div_clk2
 * 11b - off
 * @param pSdadc the base address of the SDADC instance.

 * @param uint32_t u32Value CLKSEL value.
 */
LOCAL_INLINE void SDADC_HWA_SetCLKSEL(SDADC_Type *const pSdadc, uint32_t u32Value)
{
    pSdadc->PWM_GEN = (pSdadc->PWM_GEN & ~SDADC_PWM_GEN_CLKSEL_MASK) | SDADC_PWM_GEN_CLKSEL(u32Value);
}

/**
 * @brief Get the value of BIT_REV.
 * Bit Reverse Mode
 * 0b - Normal mode, a triangle wave is used as PWM carrier.
 * 1b - Bit reverse mode. A bit reversed sawtooth wave is used as PWM carrier.
 * @param pSdadc the base address of the SDADC instance.

 * @return uint32_t the value of BIT_REV.
 */
LOCAL_INLINE uint32_t SDADC_HWA_GetBIT_REV(const SDADC_Type *const pSdadc)
{
    uint32_t u32TmpVal = (pSdadc->PWM_GEN & SDADC_PWM_GEN_BIT_REV_MASK) >> SDADC_PWM_GEN_BIT_REV_SHIFT;
    return u32TmpVal;
}

/**
 * @brief Set BIT_REV.
 * Bit Reverse Mode
 * 0b - Normal mode, a triangle wave is used as PWM carrier.
 * 1b - Bit reverse mode. A bit reversed sawtooth wave is used as PWM carrier.
 * @param pSdadc the base address of the SDADC instance.

 * @param uint32_t u32Value BIT_REV value.
 */
LOCAL_INLINE void SDADC_HWA_SetBIT_REV(SDADC_Type *const pSdadc, uint32_t u32Value)
{
    pSdadc->PWM_GEN = (pSdadc->PWM_GEN & ~SDADC_PWM_GEN_BIT_REV_MASK) | SDADC_PWM_GEN_BIT_REV(u32Value);
}

/**
 * @brief Get the value of POL.
 * PWM Generator Polarity
 * 0b - PWM generator output begin with +1
 * 1b - PWM generator output begin with -1
 * @param pSdadc the base address of the SDADC instance.

 * @return uint32_t the value of POL.
 */
LOCAL_INLINE uint32_t SDADC_HWA_GetPOL(const SDADC_Type *const pSdadc)
{
    uint32_t u32TmpVal = (pSdadc->PWM_GEN & SDADC_PWM_GEN_POL_MASK) >> SDADC_PWM_GEN_POL_SHIFT;
    return u32TmpVal;
}

/**
 * @brief Set POL.
 * PWM Generator Polarity
 * 0b - PWM generator output begin with +1
 * 1b - PWM generator output begin with -1
 * @param pSdadc the base address of the SDADC instance.

 * @param uint32_t u32Value POL value.
 */
LOCAL_INLINE void SDADC_HWA_SetPOL(SDADC_Type *const pSdadc, uint32_t u32Value)
{
    pSdadc->PWM_GEN = (pSdadc->PWM_GEN & ~SDADC_PWM_GEN_POL_MASK) | SDADC_PWM_GEN_POL(u32Value);
}

/**
 * @brief Get the value of PATTERN.
 * PWM Generator Pattern
 * Config this before set MEN. Clear the bits during PWM generator run will terminate the PWM generator outputs after completion of the current period(indicated by bit ON=0)
 * 00b - Stopped
 * 01b - Square wave
 * 10b - Triangle
 * 11b - Sine wave
 * @param pSdadc the base address of the SDADC instance.

 * @return uint32_t the value of PATTERN.
 */
LOCAL_INLINE uint32_t SDADC_HWA_GetPATTERN(const SDADC_Type *const pSdadc)
{
    uint32_t u32TmpVal = (pSdadc->PWM_GEN & SDADC_PWM_GEN_PATTERN_MASK) >> SDADC_PWM_GEN_PATTERN_SHIFT;
    return u32TmpVal;
}

/**
 * @brief Set PATTERN.
 * PWM Generator Pattern
 * Config this before set MEN. Clear the bits during PWM generator run will terminate the PWM generator outputs after completion of the current period(indicated by bit ON=0)
 * 00b - Stopped
 * 01b - Square wave
 * 10b - Triangle
 * 11b - Sine wave
 * @param pSdadc the base address of the SDADC instance.

 * @param uint32_t u32Value PATTERN value.
 */
LOCAL_INLINE void SDADC_HWA_SetPATTERN(SDADC_Type *const pSdadc, uint32_t u32Value)
{
    pSdadc->PWM_GEN = (pSdadc->PWM_GEN & ~SDADC_PWM_GEN_PATTERN_MASK) | SDADC_PWM_GEN_PATTERN(u32Value);
}

/**
 * @brief Get the value of TSVLD2.
 * Timestamp Valid Flag for Channel 2
 * Indicates timestamp inforamtion is captured, it will be cleared if CTSINFO reigister is readed.
 * 0b - The flag is not asserted.
 * 1b - The flag is asserted.
 * @param pSdadc the base address of the SDADC instance.

 * @return uint32_t the value of TSVLD2.
 */
LOCAL_INLINE uint32_t SDADC_HWA_GetTSVLD2(const SDADC_Type *const pSdadc)
{
    uint32_t u32TmpVal = (pSdadc->EXTIS & SDADC_EXTIS_TSVLD2_MASK) >> SDADC_EXTIS_TSVLD2_SHIFT;
    return u32TmpVal;
}

/**
 * @brief Clear TSVLD2.
 * Timestamp Valid Flag for Channel 2
 * Indicates timestamp inforamtion is captured, it will be cleared if CTSINFO reigister is readed.
 * 0b - The flag is not asserted.
 * 1b - The flag is asserted.
 * @param pSdadc the base address of the SDADC instance.

 */
LOCAL_INLINE void SDADC_HWA_ClearTSVLD2(SDADC_Type *const pSdadc)
{
    pSdadc->EXTIS = SDADC_EXTIS_TSVLD2(1);
}

/**
 * @brief Get the value of TSVLD1.
 * Timestamp Valid Flag for Channel 1
 * Indicates timestamp inforamtion is captured, it will be cleared if CTSINFO reigister is readed.
 * 0b - The flag is not asserted.
 * 1b - The flag is asserted.
 * @param pSdadc the base address of the SDADC instance.

 * @return uint32_t the value of TSVLD1.
 */
LOCAL_INLINE uint32_t SDADC_HWA_GetTSVLD1(const SDADC_Type *const pSdadc)
{
    uint32_t u32TmpVal = (pSdadc->EXTIS & SDADC_EXTIS_TSVLD1_MASK) >> SDADC_EXTIS_TSVLD1_SHIFT;
    return u32TmpVal;
}

/**
 * @brief Clear TSVLD1.
 * Timestamp Valid Flag for Channel 1
 * Indicates timestamp inforamtion is captured, it will be cleared if CTSINFO reigister is readed.
 * 0b - The flag is not asserted.
 * 1b - The flag is asserted.
 * @param pSdadc the base address of the SDADC instance.

 */
LOCAL_INLINE void SDADC_HWA_ClearTSVLD1(SDADC_Type *const pSdadc)
{
    pSdadc->EXTIS = SDADC_EXTIS_TSVLD1(1);
}

/**
 * @brief Get the value of TSVLD0.
 * Timestamp Valid Flag for Channel 0
 * Indicates timestamp inforamtion is captured, it will be cleared if CTSINFO reigister is readed.
 * 0b - The flag is not asserted.
 * 1b - The flag is asserted.
 * @param pSdadc the base address of the SDADC instance.

 * @return uint32_t the value of TSVLD0.
 */
LOCAL_INLINE uint32_t SDADC_HWA_GetTSVLD0(const SDADC_Type *const pSdadc)
{
    uint32_t u32TmpVal = (pSdadc->EXTIS & SDADC_EXTIS_TSVLD0_MASK) >> SDADC_EXTIS_TSVLD0_SHIFT;
    return u32TmpVal;
}

/**
 * @brief Clear TSVLD0.
 * Timestamp Valid Flag for Channel 0
 * Indicates timestamp inforamtion is captured, it will be cleared if CTSINFO reigister is readed.
 * 0b - The flag is not asserted.
 * 1b - The flag is asserted.
 * @param pSdadc the base address of the SDADC instance.

 */
LOCAL_INLINE void SDADC_HWA_ClearTSVLD0(SDADC_Type *const pSdadc)
{
    pSdadc->EXTIS = SDADC_EXTIS_TSVLD0(1);
}

/**
 * @brief Get the value of TSIGN_P2N2.
 * Trigger Sign Changed from 1 to 0 for Channel 2
 * Indicates TSIGN changed from 1 to 0 when RECT is on, this can be used as an INTG start trigger for a better angular evaluation.
 * 0b - TSIGN is not changed.
 * 1b - TSIGN is changed from 1 to 0.
 * @param pSdadc the base address of the SDADC instance.

 * @return uint32_t the value of TSIGN_P2N2.
 */
LOCAL_INLINE uint32_t SDADC_HWA_GetTSIGN_P2N2(const SDADC_Type *const pSdadc)
{
    uint32_t u32TmpVal = (pSdadc->EXTIS & SDADC_EXTIS_TSIGN_P2N2_MASK) >> SDADC_EXTIS_TSIGN_P2N2_SHIFT;
    return u32TmpVal;
}

/**
 * @brief Clear TSIGN_P2N2.
 * Trigger Sign Changed from 1 to 0 for Channel 2
 * Indicates TSIGN changed from 1 to 0 when RECT is on, this can be used as an INTG start trigger for a better angular evaluation.
 * 0b - TSIGN is not changed.
 * 1b - TSIGN is changed from 1 to 0.
 * @param pSdadc the base address of the SDADC instance.

 */
LOCAL_INLINE void SDADC_HWA_ClearTSIGN_P2N2(SDADC_Type *const pSdadc)
{
    pSdadc->EXTIS = SDADC_EXTIS_TSIGN_P2N2(1);
}

/**
 * @brief Get the value of TSIGN_P2N1.
 * Trigger Sign Changed from 1 to 0 for Channel 1
 * Indicates TSIGN changed from 1 to 0 when RECT is on, this can be used as an INTG start trigger for a better angular evaluation.
 * 0b - TSIGN is not changed.
 * 1b - TSIGN is changed from 1 to 0.
 * @param pSdadc the base address of the SDADC instance.

 * @return uint32_t the value of TSIGN_P2N1.
 */
LOCAL_INLINE uint32_t SDADC_HWA_GetTSIGN_P2N1(const SDADC_Type *const pSdadc)
{
    uint32_t u32TmpVal = (pSdadc->EXTIS & SDADC_EXTIS_TSIGN_P2N1_MASK) >> SDADC_EXTIS_TSIGN_P2N1_SHIFT;
    return u32TmpVal;
}

/**
 * @brief Clear TSIGN_P2N1.
 * Trigger Sign Changed from 1 to 0 for Channel 1
 * Indicates TSIGN changed from 1 to 0 when RECT is on, this can be used as an INTG start trigger for a better angular evaluation.
 * 0b - TSIGN is not changed.
 * 1b - TSIGN is changed from 1 to 0.
 * @param pSdadc the base address of the SDADC instance.

 */
LOCAL_INLINE void SDADC_HWA_ClearTSIGN_P2N1(SDADC_Type *const pSdadc)
{
    pSdadc->EXTIS = SDADC_EXTIS_TSIGN_P2N1(1);
}

/**
 * @brief Get the value of TSIGN_P2N0.
 * Trigger Sign Changed from 1 to 0 for Channel 0
 * Indicates TSIGN changed from 1 to 0 when RECT is on, this can be used as an INTG start trigger for a better angular evaluation.
 * 0b - TSIGN is not changed.
 * 1b - TSIGN is changed from 1 to 0.
 * @param pSdadc the base address of the SDADC instance.

 * @return uint32_t the value of TSIGN_P2N0.
 */
LOCAL_INLINE uint32_t SDADC_HWA_GetTSIGN_P2N0(const SDADC_Type *const pSdadc)
{
    uint32_t u32TmpVal = (pSdadc->EXTIS & SDADC_EXTIS_TSIGN_P2N0_MASK) >> SDADC_EXTIS_TSIGN_P2N0_SHIFT;
    return u32TmpVal;
}

/**
 * @brief Clear TSIGN_P2N0.
 * Trigger Sign Changed from 1 to 0 for Channel 0
 * Indicates TSIGN changed from 1 to 0 when RECT is on, this can be used as an INTG start trigger for a better angular evaluation.
 * 0b - TSIGN is not changed.
 * 1b - TSIGN is changed from 1 to 0.
 * @param pSdadc the base address of the SDADC instance.

 */
LOCAL_INLINE void SDADC_HWA_ClearTSIGN_P2N0(SDADC_Type *const pSdadc)
{
    pSdadc->EXTIS = SDADC_EXTIS_TSIGN_P2N0(1);
}

/**
 * @brief Get the value of MCIC_COC2.
 * Filter Channel 2 Conversion Complete Flag for MCIC
 * Means MCIC data or rectification output or most recent accumulation data in Channel Integration Value Register is valid.
 * When integration is not enabled, this is the same as COC.
 * When integration is enabled and on, this is not the same as COC which is means integration output valid.
 * @param pSdadc the base address of the SDADC instance.

 * @return uint32_t the value of MCIC_COC2.
 */
LOCAL_INLINE uint32_t SDADC_HWA_GetMCIC_COC2(const SDADC_Type *const pSdadc)
{
    uint32_t u32TmpVal = (pSdadc->EXTIS & SDADC_EXTIS_MCIC_COC2_MASK) >> SDADC_EXTIS_MCIC_COC2_SHIFT;
    return u32TmpVal;
}

/**
 * @brief Clear MCIC_COC2.
 * Filter Channel 2 Conversion Complete Flag for MCIC
 * Means MCIC data or rectification output or most recent accumulation data in Channel Integration Value Register is valid.
 * When integration is not enabled, this is the same as COC.
 * When integration is enabled and on, this is not the same as COC which is means integration output valid.
 * @param pSdadc the base address of the SDADC instance.

 */
LOCAL_INLINE void SDADC_HWA_ClearMCIC_COC2(SDADC_Type *const pSdadc)
{
    pSdadc->EXTIS = SDADC_EXTIS_MCIC_COC2(1);
}

/**
 * @brief Get the value of MCIC_COC1.
 * Filter Channel 1 Conversion Complete Flag for MCIC
 * Means MCIC data or rectification output or most recent accumulation data in Channel Integration Value Register is valid.
 * When integration is not enabled, this is the same as COC.
 * When integration is enabled and on, this is not the same as COC which is means integration output valid.
 * @param pSdadc the base address of the SDADC instance.

 * @return uint32_t the value of MCIC_COC1.
 */
LOCAL_INLINE uint32_t SDADC_HWA_GetMCIC_COC1(const SDADC_Type *const pSdadc)
{
    uint32_t u32TmpVal = (pSdadc->EXTIS & SDADC_EXTIS_MCIC_COC1_MASK) >> SDADC_EXTIS_MCIC_COC1_SHIFT;
    return u32TmpVal;
}

/**
 * @brief Clear MCIC_COC1.
 * Filter Channel 1 Conversion Complete Flag for MCIC
 * Means MCIC data or rectification output or most recent accumulation data in Channel Integration Value Register is valid.
 * When integration is not enabled, this is the same as COC.
 * When integration is enabled and on, this is not the same as COC which is means integration output valid.
 * @param pSdadc the base address of the SDADC instance.

 */
LOCAL_INLINE void SDADC_HWA_ClearMCIC_COC1(SDADC_Type *const pSdadc)
{
    pSdadc->EXTIS = SDADC_EXTIS_MCIC_COC1(1);
}

/**
 * @brief Get the value of MCIC_COC0.
 * Filter channel 0 Conversion Complete Flag for MCIC.
 * Means MCIC data or rectification output or most recent accumulation data in Channel Integration Value Register is valid.
 * When integration is not enabled, this is the same as COC.
 * When integration is enabled and on, this is not the same as COC which is means integration output valid.
 * @param pSdadc the base address of the SDADC instance.

 * @return uint32_t the value of MCIC_COC0.
 */
LOCAL_INLINE uint32_t SDADC_HWA_GetMCIC_COC0(const SDADC_Type *const pSdadc)
{
    uint32_t u32TmpVal = (pSdadc->EXTIS & SDADC_EXTIS_MCIC_COC0_MASK) >> SDADC_EXTIS_MCIC_COC0_SHIFT;
    return u32TmpVal;
}

/**
 * @brief Clear MCIC_COC0.
 * Filter channel 0 Conversion Complete Flag for MCIC.
 * Means MCIC data or rectification output or most recent accumulation data in Channel Integration Value Register is valid.
 * When integration is not enabled, this is the same as COC.
 * When integration is enabled and on, this is not the same as COC which is means integration output valid.
 * @param pSdadc the base address of the SDADC instance.

 */
LOCAL_INLINE void SDADC_HWA_ClearMCIC_COC0(SDADC_Type *const pSdadc)
{
    pSdadc->EXTIS = SDADC_EXTIS_MCIC_COC0(1);
}

/**
 * @brief Get the value of SD_CAPVLD2.
 * Capture Valid Flag for channel 2
 * Indicates a new value in bitfield SD_CAP. This bit can be cleared by read related CSDRn register.
 * 0b - no new result available.
 * 1b - SD_CAP has been updated with a new captured value and has not been read.
 * @param pSdadc the base address of the SDADC instance.

 * @return uint32_t the value of SD_CAPVLD2.
 */
LOCAL_INLINE uint32_t SDADC_HWA_GetSD_CAPVLD2(const SDADC_Type *const pSdadc)
{
    uint32_t u32TmpVal = (pSdadc->EXTIS & SDADC_EXTIS_SD_CAPVLD2_MASK) >> SDADC_EXTIS_SD_CAPVLD2_SHIFT;
    return u32TmpVal;
}

/**
 * @brief Clear SD_CAPVLD2.
 * Capture Valid Flag for channel 2
 * Indicates a new value in bitfield SD_CAP. This bit can be cleared by read related CSDRn register.
 * 0b - no new result available.
 * 1b - SD_CAP has been updated with a new captured value and has not been read.
 * @param pSdadc the base address of the SDADC instance.

 */
LOCAL_INLINE void SDADC_HWA_ClearSD_CAPVLD2(SDADC_Type *const pSdadc)
{
    pSdadc->EXTIS = SDADC_EXTIS_SD_CAPVLD2(1);
}

/**
 * @brief Get the value of SD_CAPVLD1.
 * Capture Valid Flag for channel 1
 * Indicates a new value in bitfield SD_CAP. This bit can be cleared by read related CSDRn register.
 * 0b - no new result available.
 * 1b - SD_CAP has been updated with a new captured value and has not been read.
 * @param pSdadc the base address of the SDADC instance.

 * @return uint32_t the value of SD_CAPVLD1.
 */
LOCAL_INLINE uint32_t SDADC_HWA_GetSD_CAPVLD1(const SDADC_Type *const pSdadc)
{
    uint32_t u32TmpVal = (pSdadc->EXTIS & SDADC_EXTIS_SD_CAPVLD1_MASK) >> SDADC_EXTIS_SD_CAPVLD1_SHIFT;
    return u32TmpVal;
}

/**
 * @brief Clear SD_CAPVLD1.
 * Capture Valid Flag for channel 1
 * Indicates a new value in bitfield SD_CAP. This bit can be cleared by read related CSDRn register.
 * 0b - no new result available.
 * 1b - SD_CAP has been updated with a new captured value and has not been read.
 * @param pSdadc the base address of the SDADC instance.

 */
LOCAL_INLINE void SDADC_HWA_ClearSD_CAPVLD1(SDADC_Type *const pSdadc)
{
    pSdadc->EXTIS = SDADC_EXTIS_SD_CAPVLD1(1);
}

/**
 * @brief Get the value of SD_CAPVLD0.
 * Capture Valid Flag for channel 0
 * Indicates a new value in bitfield SD_CAP. This bit can be cleared by read related CSDRn register.
 * 0b - no new result available.
 * 1b - SD_CAP has been updated with a new captured value and has not been read.
 * @param pSdadc the base address of the SDADC instance.

 * @return uint32_t the value of SD_CAPVLD0.
 */
LOCAL_INLINE uint32_t SDADC_HWA_GetSD_CAPVLD0(const SDADC_Type *const pSdadc)
{
    uint32_t u32TmpVal = (pSdadc->EXTIS & SDADC_EXTIS_SD_CAPVLD0_MASK) >> SDADC_EXTIS_SD_CAPVLD0_SHIFT;
    return u32TmpVal;
}

/**
 * @brief Clear SD_CAPVLD0.
 * Capture Valid Flag for channel 0
 * Indicates a new value in bitfield SD_CAP. This bit can be cleared by read related CSDRn register.
 * 0b - no new result available.
 * 1b - SD_CAP has been updated with a new captured value and has not been read.
 * @param pSdadc the base address of the SDADC instance.

 */
LOCAL_INLINE void SDADC_HWA_ClearSD_CAPVLD0(SDADC_Type *const pSdadc)
{
    pSdadc->EXTIS = SDADC_EXTIS_SD_CAPVLD0(1);
}

/**
 * @brief Get the value of TSVLD_IE2.
 * Timestamp Valid Interrupt Enable for channel 2
 * 0b - The interrupt is disabled.
 * 1b - The interrupt is enabled.
 * @param pSdadc the base address of the SDADC instance.

 * @return uint32_t the value of TSVLD_IE2.
 */
LOCAL_INLINE uint32_t SDADC_HWA_GetTSVLD_IE2(const SDADC_Type *const pSdadc)
{
    uint32_t u32TmpVal = (pSdadc->EXTIE & SDADC_EXTIE_TSVLD_IE2_MASK) >> SDADC_EXTIE_TSVLD_IE2_SHIFT;
    return u32TmpVal;
}

/**
 * @brief Set TSVLD_IE2.
 * Timestamp Valid Interrupt Enable for channel 2
 * 0b - The interrupt is disabled.
 * 1b - The interrupt is enabled.
 * @param pSdadc the base address of the SDADC instance.

 * @param uint32_t u32Value TSVLD_IE2 value.
 */
LOCAL_INLINE void SDADC_HWA_SetTSVLD_IE2(SDADC_Type *const pSdadc, uint32_t u32Value)
{
    pSdadc->EXTIE = (pSdadc->EXTIE & ~SDADC_EXTIE_TSVLD_IE2_MASK) | SDADC_EXTIE_TSVLD_IE2(u32Value);
}

/**
 * @brief Get the value of TSVLD_IE1.
 * Timestamp Valid Interrupt Enable for channel 1
 * 0b - The interrupt is disabled.
 * 1b - The interrupt is enabled.
 * @param pSdadc the base address of the SDADC instance.

 * @return uint32_t the value of TSVLD_IE1.
 */
LOCAL_INLINE uint32_t SDADC_HWA_GetTSVLD_IE1(const SDADC_Type *const pSdadc)
{
    uint32_t u32TmpVal = (pSdadc->EXTIE & SDADC_EXTIE_TSVLD_IE1_MASK) >> SDADC_EXTIE_TSVLD_IE1_SHIFT;
    return u32TmpVal;
}

/**
 * @brief Set TSVLD_IE1.
 * Timestamp Valid Interrupt Enable for channel 1
 * 0b - The interrupt is disabled.
 * 1b - The interrupt is enabled.
 * @param pSdadc the base address of the SDADC instance.

 * @param uint32_t u32Value TSVLD_IE1 value.
 */
LOCAL_INLINE void SDADC_HWA_SetTSVLD_IE1(SDADC_Type *const pSdadc, uint32_t u32Value)
{
    pSdadc->EXTIE = (pSdadc->EXTIE & ~SDADC_EXTIE_TSVLD_IE1_MASK) | SDADC_EXTIE_TSVLD_IE1(u32Value);
}

/**
 * @brief Get the value of TSVLD_IE0.
 * Timestamp Valid Interrupt Enable for channel 0
 * 0b - The interrupt is disabled.
 * 1b - The interrupt is enabled.
 * @param pSdadc the base address of the SDADC instance.

 * @return uint32_t the value of TSVLD_IE0.
 */
LOCAL_INLINE uint32_t SDADC_HWA_GetTSVLD_IE0(const SDADC_Type *const pSdadc)
{
    uint32_t u32TmpVal = (pSdadc->EXTIE & SDADC_EXTIE_TSVLD_IE0_MASK) >> SDADC_EXTIE_TSVLD_IE0_SHIFT;
    return u32TmpVal;
}

/**
 * @brief Set TSVLD_IE0.
 * Timestamp Valid Interrupt Enable for channel 0
 * 0b - The interrupt is disabled.
 * 1b - The interrupt is enabled.
 * @param pSdadc the base address of the SDADC instance.

 * @param uint32_t u32Value TSVLD_IE0 value.
 */
LOCAL_INLINE void SDADC_HWA_SetTSVLD_IE0(SDADC_Type *const pSdadc, uint32_t u32Value)
{
    pSdadc->EXTIE = (pSdadc->EXTIE & ~SDADC_EXTIE_TSVLD_IE0_MASK) | SDADC_EXTIE_TSVLD_IE0(u32Value);
}

/**
 * @brief Get the value of TSIGN_P2N_IE2.
 * Trigger  Sign Changed from 1 to 0 Interrupt Enable for channel 2
 * 0b - The interrupt is disabled.
 * 1b - The interrupt is enabled.
 * @param pSdadc the base address of the SDADC instance.

 * @return uint32_t the value of TSIGN_P2N_IE2.
 */
LOCAL_INLINE uint32_t SDADC_HWA_GetTSIGN_P2N_IE2(const SDADC_Type *const pSdadc)
{
    uint32_t u32TmpVal = (pSdadc->EXTIE & SDADC_EXTIE_TSIGN_P2N_IE2_MASK) >> SDADC_EXTIE_TSIGN_P2N_IE2_SHIFT;
    return u32TmpVal;
}

/**
 * @brief Set TSIGN_P2N_IE2.
 * Trigger  Sign Changed from 1 to 0 Interrupt Enable for channel 2
 * 0b - The interrupt is disabled.
 * 1b - The interrupt is enabled.
 * @param pSdadc the base address of the SDADC instance.

 * @param uint32_t u32Value TSIGN_P2N_IE2 value.
 */
LOCAL_INLINE void SDADC_HWA_SetTSIGN_P2N_IE2(SDADC_Type *const pSdadc, uint32_t u32Value)
{
    pSdadc->EXTIE = (pSdadc->EXTIE & ~SDADC_EXTIE_TSIGN_P2N_IE2_MASK) | SDADC_EXTIE_TSIGN_P2N_IE2(u32Value);
}

/**
 * @brief Get the value of TSIGN_P2N_IE1.
 * Trigger  Sign Changed from 1 to 0 Interrupt Enable for channel 1
 * 0b - The interrupt is disabled.
 * 1b - The interrupt is enabled.
 * @param pSdadc the base address of the SDADC instance.

 * @return uint32_t the value of TSIGN_P2N_IE1.
 */
LOCAL_INLINE uint32_t SDADC_HWA_GetTSIGN_P2N_IE1(const SDADC_Type *const pSdadc)
{
    uint32_t u32TmpVal = (pSdadc->EXTIE & SDADC_EXTIE_TSIGN_P2N_IE1_MASK) >> SDADC_EXTIE_TSIGN_P2N_IE1_SHIFT;
    return u32TmpVal;
}

/**
 * @brief Set TSIGN_P2N_IE1.
 * Trigger  Sign Changed from 1 to 0 Interrupt Enable for channel 1
 * 0b - The interrupt is disabled.
 * 1b - The interrupt is enabled.
 * @param pSdadc the base address of the SDADC instance.

 * @param uint32_t u32Value TSIGN_P2N_IE1 value.
 */
LOCAL_INLINE void SDADC_HWA_SetTSIGN_P2N_IE1(SDADC_Type *const pSdadc, uint32_t u32Value)
{
    pSdadc->EXTIE = (pSdadc->EXTIE & ~SDADC_EXTIE_TSIGN_P2N_IE1_MASK) | SDADC_EXTIE_TSIGN_P2N_IE1(u32Value);
}

/**
 * @brief Get the value of TSIGN_P2N_IE0.
 * Trigger  Sign Changed from 1 to 0 Interrupt Enable for channel 0
 * 0b - The interrupt is disabled.
 * 1b - The interrupt is enabled.
 * @param pSdadc the base address of the SDADC instance.

 * @return uint32_t the value of TSIGN_P2N_IE0.
 */
LOCAL_INLINE uint32_t SDADC_HWA_GetTSIGN_P2N_IE0(const SDADC_Type *const pSdadc)
{
    uint32_t u32TmpVal = (pSdadc->EXTIE & SDADC_EXTIE_TSIGN_P2N_IE0_MASK) >> SDADC_EXTIE_TSIGN_P2N_IE0_SHIFT;
    return u32TmpVal;
}

/**
 * @brief Set TSIGN_P2N_IE0.
 * Trigger  Sign Changed from 1 to 0 Interrupt Enable for channel 0
 * 0b - The interrupt is disabled.
 * 1b - The interrupt is enabled.
 * @param pSdadc the base address of the SDADC instance.

 * @param uint32_t u32Value TSIGN_P2N_IE0 value.
 */
LOCAL_INLINE void SDADC_HWA_SetTSIGN_P2N_IE0(SDADC_Type *const pSdadc, uint32_t u32Value)
{
    pSdadc->EXTIE = (pSdadc->EXTIE & ~SDADC_EXTIE_TSIGN_P2N_IE0_MASK) | SDADC_EXTIE_TSIGN_P2N_IE0(u32Value);
}

/**
 * @brief Get the value of SD_CAPVLD_IE2.
 * Capture Valid Interrupt Enable for channel 2
 * 0b - The interrupt is disabled.
 * 1b - The interrupt is enabled.
 * @param pSdadc the base address of the SDADC instance.

 * @return uint32_t the value of SD_CAPVLD_IE2.
 */
LOCAL_INLINE uint32_t SDADC_HWA_GetSD_CAPVLD_IE2(const SDADC_Type *const pSdadc)
{
    uint32_t u32TmpVal = (pSdadc->EXTIE & SDADC_EXTIE_SD_CAPVLD_IE2_MASK) >> SDADC_EXTIE_SD_CAPVLD_IE2_SHIFT;
    return u32TmpVal;
}

/**
 * @brief Set SD_CAPVLD_IE2.
 * Capture Valid Interrupt Enable for channel 2
 * 0b - The interrupt is disabled.
 * 1b - The interrupt is enabled.
 * @param pSdadc the base address of the SDADC instance.

 * @param uint32_t u32Value SD_CAPVLD_IE2 value.
 */
LOCAL_INLINE void SDADC_HWA_SetSD_CAPVLD_IE2(SDADC_Type *const pSdadc, uint32_t u32Value)
{
    pSdadc->EXTIE = (pSdadc->EXTIE & ~SDADC_EXTIE_SD_CAPVLD_IE2_MASK) | SDADC_EXTIE_SD_CAPVLD_IE2(u32Value);
}

/**
 * @brief Get the value of SD_CAPVLD_IE1.
 * Capture Valid Interrupt Enable for channel 1
 * 0b - The interrupt is disabled.
 * 1b - The interrupt is enabled.
 * @param pSdadc the base address of the SDADC instance.

 * @return uint32_t the value of SD_CAPVLD_IE1.
 */
LOCAL_INLINE uint32_t SDADC_HWA_GetSD_CAPVLD_IE1(const SDADC_Type *const pSdadc)
{
    uint32_t u32TmpVal = (pSdadc->EXTIE & SDADC_EXTIE_SD_CAPVLD_IE1_MASK) >> SDADC_EXTIE_SD_CAPVLD_IE1_SHIFT;
    return u32TmpVal;
}

/**
 * @brief Set SD_CAPVLD_IE1.
 * Capture Valid Interrupt Enable for channel 1
 * 0b - The interrupt is disabled.
 * 1b - The interrupt is enabled.
 * @param pSdadc the base address of the SDADC instance.

 * @param uint32_t u32Value SD_CAPVLD_IE1 value.
 */
LOCAL_INLINE void SDADC_HWA_SetSD_CAPVLD_IE1(SDADC_Type *const pSdadc, uint32_t u32Value)
{
    pSdadc->EXTIE = (pSdadc->EXTIE & ~SDADC_EXTIE_SD_CAPVLD_IE1_MASK) | SDADC_EXTIE_SD_CAPVLD_IE1(u32Value);
}

/**
 * @brief Get the value of SD_CAPVLD_IE0.
 * Capture Valid Interrupt Enable for channel 0
 * 0b - The interrupt is disabled.
 * 1b - The interrupt is enabled.
 * @param pSdadc the base address of the SDADC instance.

 * @return uint32_t the value of SD_CAPVLD_IE0.
 */
LOCAL_INLINE uint32_t SDADC_HWA_GetSD_CAPVLD_IE0(const SDADC_Type *const pSdadc)
{
    uint32_t u32TmpVal = (pSdadc->EXTIE & SDADC_EXTIE_SD_CAPVLD_IE0_MASK) >> SDADC_EXTIE_SD_CAPVLD_IE0_SHIFT;
    return u32TmpVal;
}

/**
 * @brief Set SD_CAPVLD_IE0.
 * Capture Valid Interrupt Enable for channel 0
 * 0b - The interrupt is disabled.
 * 1b - The interrupt is enabled.
 * @param pSdadc the base address of the SDADC instance.

 * @param uint32_t u32Value SD_CAPVLD_IE0 value.
 */
LOCAL_INLINE void SDADC_HWA_SetSD_CAPVLD_IE0(SDADC_Type *const pSdadc, uint32_t u32Value)
{
    pSdadc->EXTIE = (pSdadc->EXTIE & ~SDADC_EXTIE_SD_CAPVLD_IE0_MASK) | SDADC_EXTIE_SD_CAPVLD_IE0(u32Value);
}

/**
 * @brief Get the value of INTG_STRIG2.
 * Integration Software Trigger for channel 2
 * Setting this bit will trigger to start of the integration when the integration is enabled.
 * Clearing this bit will stop integration. So it works like a level event.
 * @param pSdadc the base address of the SDADC instance.

 * @return uint32_t the value of INTG_STRIG2.
 */
LOCAL_INLINE uint32_t SDADC_HWA_GetINTG_STRIG2(const SDADC_Type *const pSdadc)
{
    uint32_t u32TmpVal = (pSdadc->EXTCTRL & SDADC_EXTCTRL_INTG_STRIG2_MASK) >> SDADC_EXTCTRL_INTG_STRIG2_SHIFT;
    return u32TmpVal;
}

/**
 * @brief Set INTG_STRIG2.
 * Integration Software Trigger for channel 2
 * Setting this bit will trigger to start of the integration when the integration is enabled.
 * Clearing this bit will stop integration. So it works like a level event.
 * @param pSdadc the base address of the SDADC instance.

 * @param uint32_t u32Value INTG_STRIG2 value.
 */
LOCAL_INLINE void SDADC_HWA_SetINTG_STRIG2(SDADC_Type *const pSdadc, uint32_t u32Value)
{
    pSdadc->EXTCTRL = (pSdadc->EXTCTRL & ~SDADC_EXTCTRL_INTG_STRIG2_MASK) | SDADC_EXTCTRL_INTG_STRIG2(u32Value);
}

/**
 * @brief Get the value of INTG_STRIG1.
 * Integration Software Trigger for channel 1
 * Setting this bit will trigger to start of the integration when the integration is enabled.
 * Clearing this bit will stop integration. So it works like a level event.
 * @param pSdadc the base address of the SDADC instance.

 * @return uint32_t the value of INTG_STRIG1.
 */
LOCAL_INLINE uint32_t SDADC_HWA_GetINTG_STRIG1(const SDADC_Type *const pSdadc)
{
    uint32_t u32TmpVal = (pSdadc->EXTCTRL & SDADC_EXTCTRL_INTG_STRIG1_MASK) >> SDADC_EXTCTRL_INTG_STRIG1_SHIFT;
    return u32TmpVal;
}

/**
 * @brief Set INTG_STRIG1.
 * Integration Software Trigger for channel 1
 * Setting this bit will trigger to start of the integration when the integration is enabled.
 * Clearing this bit will stop integration. So it works like a level event.
 * @param pSdadc the base address of the SDADC instance.

 * @param uint32_t u32Value INTG_STRIG1 value.
 */
LOCAL_INLINE void SDADC_HWA_SetINTG_STRIG1(SDADC_Type *const pSdadc, uint32_t u32Value)
{
    pSdadc->EXTCTRL = (pSdadc->EXTCTRL & ~SDADC_EXTCTRL_INTG_STRIG1_MASK) | SDADC_EXTCTRL_INTG_STRIG1(u32Value);
}

/**
 * @brief Get the value of INTG_STRIG0.
 * Integration Software Trigger for channel 0
 * Setting this bit will trigger to start of the integration when the integration is enabled.
 * Clearing this bit will stop integration. So it works like a level event.
 * @param pSdadc the base address of the SDADC instance.

 * @return uint32_t the value of INTG_STRIG0.
 */
LOCAL_INLINE uint32_t SDADC_HWA_GetINTG_STRIG0(const SDADC_Type *const pSdadc)
{
    uint32_t u32TmpVal = (pSdadc->EXTCTRL & SDADC_EXTCTRL_INTG_STRIG0_MASK) >> SDADC_EXTCTRL_INTG_STRIG0_SHIFT;
    return u32TmpVal;
}

/**
 * @brief Set INTG_STRIG0.
 * Integration Software Trigger for channel 0
 * Setting this bit will trigger to start of the integration when the integration is enabled.
 * Clearing this bit will stop integration. So it works like a level event.
 * @param pSdadc the base address of the SDADC instance.

 * @param uint32_t u32Value INTG_STRIG0 value.
 */
LOCAL_INLINE void SDADC_HWA_SetINTG_STRIG0(SDADC_Type *const pSdadc, uint32_t u32Value)
{
    pSdadc->EXTCTRL = (pSdadc->EXTCTRL & ~SDADC_EXTCTRL_INTG_STRIG0_MASK) | SDADC_EXTCTRL_INTG_STRIG0(u32Value);
}

/**
 * @brief Get the value of BIAS_ON.
 * Bias On Flag
 * 0b - Bias analog is not ready for using.
 * 1b - Bias analog is ready for using.
 * @param pSdadc the base address of the SDADC instance.
 * @return uint32_t the value of BIAS_ON.
 */
LOCAL_INLINE uint32_t SDADC_HWA_GetBIAS_ON(const SDADC_Type *const pSdadc)
{
    uint32_t u32TmpVal = (pSdadc->BACSR[0] & SDADC_BACSR_BIAS_ON_MASK) >> SDADC_BACSR_BIAS_ON_SHIFT;
    return u32TmpVal;
}

/**
 * @brief Get the value of BSTC.
 * Bias Start Time Control
 * Bias analog need a ~2us start time, this bits control number of div_clk1 cycles before BIAS_ON flag set after BIAS_EN set.
 * @param pSdadc the base address of the SDADC instance.
 * @return uint32_t the value of BSTC.
 */
LOCAL_INLINE uint32_t SDADC_HWA_GetBSTC(const SDADC_Type *const pSdadc)
{
    uint32_t u32TmpVal = (pSdadc->BACSR[0] & SDADC_BACSR_BSTC_MASK) >> SDADC_BACSR_BSTC_SHIFT;
    return u32TmpVal;
}

/**
 * @brief Set BSTC.
 * Bias Start Time Control
 * Bias analog need a ~2us start time, this bits control number of div_clk1 cycles before BIAS_ON flag set after BIAS_EN set.
 * @param pSdadc the base address of the SDADC instance.
 * @param uint32_t u32Value BSTC value.
 */
LOCAL_INLINE void SDADC_HWA_SetBSTC(SDADC_Type *const pSdadc, uint32_t u32Value)
{
    pSdadc->BACSR[0] = (pSdadc->BACSR[0] & ~SDADC_BACSR_BSTC_MASK) | SDADC_BACSR_BSTC(u32Value);
}

/**
 * @brief Get the value of VCM_BEN.
 * Common Mode Voltage Bias Enable
 * Enable common mode voltage for AC input of internal modulator analog.
 * 0b - Common mode voltage Bias is disabled.
 * 1b - Common mode voltage Bias is enabled.
 * @param pSdadc the base address of the SDADC instance.
 * @return uint32_t the value of VCM_BEN.
 */
LOCAL_INLINE uint32_t SDADC_HWA_GetVCM_BEN(const SDADC_Type *const pSdadc)
{
    uint32_t u32TmpVal = (pSdadc->BACSR[0] & SDADC_BACSR_VCM_BEN_MASK) >> SDADC_BACSR_VCM_BEN_SHIFT;
    return u32TmpVal;
}

/**
 * @brief Set VCM_BEN.
 * Common Mode Voltage Bias Enable
 * Enable common mode voltage for AC input of internal modulator analog.
 * 0b - Common mode voltage Bias is disabled.
 * 1b - Common mode voltage Bias is enabled.
 * @param pSdadc the base address of the SDADC instance.
 * @param uint32_t u32Value VCM_BEN value.
 */
LOCAL_INLINE void SDADC_HWA_SetVCM_BEN(SDADC_Type *const pSdadc, uint32_t u32Value)
{
    pSdadc->BACSR[0] = (pSdadc->BACSR[0] & ~SDADC_BACSR_VCM_BEN_MASK) | SDADC_BACSR_VCM_BEN(u32Value);
}

/**
 * @brief Get the value of HFVREF_EN.
 * Half VREFH output Enable to Related Internal Modulator Analog.
 * Bit 4 enable internal Half VREFH output to modulator analog for channel 0.
 * Bit 5 enable internal Half VREFH output to modulator analog for channel 1.
 * Bit 6 enable internal Half VREFH output to modulator analog for channel 2.
 * Bit 7 enable internal Half VREFH output to modulator analog for channel 3.
 * NOTE: Not all channels have internal modulator analog, if the channel has no internal modulator analog, related control bit is reserved.
 * @param pSdadc the base address of the SDADC instance.
 * @return uint32_t the value of HFVREF_EN.
 */
LOCAL_INLINE uint32_t SDADC_HWA_GetHFVREF_EN(const SDADC_Type *const pSdadc)
{
    uint32_t u32TmpVal = (pSdadc->BACSR[0] & SDADC_BACSR_HFVREF_EN_MASK) >> SDADC_BACSR_HFVREF_EN_SHIFT;
    return u32TmpVal;
}

/**
 * @brief Set HFVREF_EN.
 * Half VREFH output Enable to Related Internal Modulator Analog.
 * Bit 4 enable internal Half VREFH output to modulator analog for channel 0.
 * Bit 5 enable internal Half VREFH output to modulator analog for channel 1.
 * Bit 6 enable internal Half VREFH output to modulator analog for channel 2.
 * Bit 7 enable internal Half VREFH output to modulator analog for channel 3.
 * NOTE: Not all channels have internal modulator analog, if the channel has no internal modulator analog, related control bit is reserved.
 * @param pSdadc the base address of the SDADC instance.
 * @param uint32_t u32Value HFVREF_EN value.
 */
LOCAL_INLINE void SDADC_HWA_SetHFVREF_EN(SDADC_Type *const pSdadc, uint32_t u32Value)
{
    pSdadc->BACSR[0] = (pSdadc->BACSR[0] & ~SDADC_BACSR_HFVREF_EN_MASK) | SDADC_BACSR_HFVREF_EN(u32Value);
}

/**
 * @brief Get the value of BIAS_EN.
 * Bias Analog Enable
 * 0b - Bias analog is disabled.
 * 1b - Bias analog is enabled.
 * @param pSdadc the base address of the SDADC instance.
 * @return uint32_t the value of BIAS_EN.
 */
LOCAL_INLINE uint32_t SDADC_HWA_GetBIAS_EN(const SDADC_Type *const pSdadc)
{
    uint32_t u32TmpVal = (pSdadc->BACSR[0] & SDADC_BACSR_BIAS_EN_MASK) >> SDADC_BACSR_BIAS_EN_SHIFT;
    return u32TmpVal;
}

/**
 * @brief Set BIAS_EN.
 * Bias Analog Enable
 * 0b - Bias analog is disabled.
 * 1b - Bias analog is enabled.
 * @param pSdadc the base address of the SDADC instance.
 * @param uint32_t u32Value BIAS_EN value.
 */
LOCAL_INLINE void SDADC_HWA_SetBIAS_EN(SDADC_Type *const pSdadc, uint32_t u32Value)
{
    pSdadc->BACSR[0] = (pSdadc->BACSR[0] & ~SDADC_BACSR_BIAS_EN_MASK) | SDADC_BACSR_BIAS_EN(u32Value);
}

/**
 * @brief Get the value of DSIGN.
 * Delayed Sign Signal
 * 0b - Positive values.
 * 1b - Negative values.
 * @param pSdadc the base address of the SDADC instance.
 * @param u8Channel SDADC Channel.
 * @return uint32_t the value of DSIGN.
 */
LOCAL_INLINE uint32_t SDADC_HWA_GetDSIGN(const SDADC_Type *const pSdadc, uint8_t u8Channel)
{
    uint32_t u32TmpVal = (pSdadc->CRTCSR[u8Channel] & SDADC_CRTCSR_DSIGN_MASK) >> SDADC_CRTCSR_DSIGN_SHIFT;
    return u32TmpVal;
}

/**
 * @brief Get the value of SSIGN.
 * Selected Sign Signal
 * 0b - Positive values.
 * 1b - Negative values.
 * @param pSdadc the base address of the SDADC instance.
 * @param u8Channel SDADC Channel.
 * @return uint32_t the value of SSIGN.
 */
LOCAL_INLINE uint32_t SDADC_HWA_GetSSIGN(const SDADC_Type *const pSdadc, uint8_t u8Channel)
{
    uint32_t u32TmpVal = (pSdadc->CRTCSR[u8Channel] & SDADC_CRTCSR_SSIGN_MASK) >> SDADC_CRTCSR_SSIGN_SHIFT;
    return u32TmpVal;
}

/**
 * @brief Get the value of SDON.
 * Sign Delay Counter on Flag
 * Indicates the activity of the sign delay counter.
 * 0b - Sign delay counter stopped.
 * 1b - Sign delay counter enabled.
 * @param pSdadc the base address of the SDADC instance.
 * @param u8Channel SDADC Channel.
 * @return uint32_t the value of SDON.
 */
LOCAL_INLINE uint32_t SDADC_HWA_GetSDON(const SDADC_Type *const pSdadc, uint8_t u8Channel)
{
    uint32_t u32TmpVal = (pSdadc->CRTCSR[u8Channel] & SDADC_CRTCSR_SDON_MASK) >> SDADC_CRTCSR_SDON_SHIFT;
    return u32TmpVal;
}

/**
 * @brief Get the value of TSIGN.
 * Sign Signal for Channel Trigger Output
 * This sign can be configured to some cycles before DSIGN, and can be used to generate channel trigger output, typically can be used to trigger integration so that it can start at the ZCD point
 * 0b - Positive values.
 * 1b - Negative values.
 * @param pSdadc the base address of the SDADC instance.
 * @param u8Channel SDADC Channel.
 * @return uint32_t the value of TSIGN.
 */
LOCAL_INLINE uint32_t SDADC_HWA_GetTSIGN(const SDADC_Type *const pSdadc, uint8_t u8Channel)
{
    uint32_t u32TmpVal = (pSdadc->CRTCSR[u8Channel] & SDADC_CRTCSR_TSIGN_MASK) >> SDADC_CRTCSR_TSIGN_SHIFT;
    return u32TmpVal;
}

/**
 * @brief Get the value of DLY_TRG.
 * Sign Delay Value for TSIGN Posedge
 * TSIGN is clear at DLY_TRG and set at DLY_NEG in CSDRn
 * @param pSdadc the base address of the SDADC instance.
 * @param u8Channel SDADC Channel.
 * @return uint32_t the value of DLY_TRG.
 */
LOCAL_INLINE uint32_t SDADC_HWA_GetDLY_TRG(const SDADC_Type *const pSdadc, uint8_t u8Channel)
{
    uint32_t u32TmpVal = (pSdadc->CRTCSR[u8Channel] & SDADC_CRTCSR_DLY_TRG_MASK) >> SDADC_CRTCSR_DLY_TRG_SHIFT;
    return u32TmpVal;
}

/**
 * @brief Get the value of CTRGSIGN_OEN.
 * Channel Sign Signal Related Trigger Out Enable
 * 0b - disabled.
 * 1b - Related trigger is enabled and will be set once TSIGN falling edge is got.
 * @param pSdadc the base address of the SDADC instance.
 * @param u8Channel SDADC Channel.
 * @return uint32_t the value of CTRGSIGN_OEN.
 */
LOCAL_INLINE uint32_t SDADC_HWA_GetCTRGSIGN_OEN(const SDADC_Type *const pSdadc, uint8_t u8Channel)
{
    uint32_t u32TmpVal = (pSdadc->CRTCSR[u8Channel] & SDADC_CRTCSR_CTRGSIGN_OEN_MASK) >> SDADC_CRTCSR_CTRGSIGN_OEN_SHIFT;
    return u32TmpVal;
}

/**
 * @brief Set the value of CTRGSIGN_OEN.
 * Channel Sign Signal Related Trigger Out Enable
 * 0b - disabled.
 * 1b - Related trigger is enabled and will be set once TSIGN falling edge is got.
 * @param pSdadc the base address of the SDADC instance.
 * @param u8Channel SDADC Channel.
 * @param u8Enable Value.
 */
LOCAL_INLINE void SDADC_HWA_SetCTRGSIGN_OEN(SDADC_Type *const pSdadc, uint8_t u8Channel, uint8_t u8Enable)
{
    pSdadc->CRTCSR[u8Channel] = (pSdadc->CRTCSR[u8Channel] & ~SDADC_CRTCSR_CTRGSIGN_OEN_MASK) | SDADC_CRTCSR_CTRGSIGN_OEN(u8Enable);
}

/**
 * @brief Get the value of SSCH.
 * Sign Signal From Channel Selection
 * Select the channel providing the sign signal if SSRC =01b
 * 0000b - From channel 0.
 * 0001b - From channel 1.
 * 0010b - From channel 2.
 * ...
 * @param pSdadc the base address of the SDADC instance.
 * @param u8Channel SDADC Channel.
 * @return uint32_t the value of SSCH.
 */
LOCAL_INLINE uint32_t SDADC_HWA_GetSSCH(const SDADC_Type *const pSdadc, uint8_t u8Channel)
{
    uint32_t u32TmpVal = (pSdadc->CRTCSR[u8Channel] & SDADC_CRTCSR_SSCH_MASK) >> SDADC_CRTCSR_SSCH_SHIFT;
    return u32TmpVal;
}

/**
 * @brief Get the value of SSRC.
 * Sign Source Selection
 * Select the sign signal to be delayed.
 * 00b - SDADC internal PWM generation block.
 * 01b - Sign of result of channel selected by SSCH.
 * 10b - External sign signal 0.
 * 11b - External sign signal 1.
 * @param pSdadc the base address of the SDADC instance.
 * @param u8Channel SDADC Channel.
 * @return uint32_t the value of SSRC.
 */
LOCAL_INLINE uint32_t SDADC_HWA_GetSSRC(const SDADC_Type *const pSdadc, uint8_t u8Channel)
{
    uint32_t u32TmpVal = (pSdadc->CRTCSR[u8Channel] & SDADC_CRTCSR_SSRC_MASK) >> SDADC_CRTCSR_SSRC_SHIFT;
    return u32TmpVal;
}

/**
 * @brief Get the value of DLY_NEG.
 * Sign Delay Value for Sign Negedge
 * Defines the content of SD_CNT to generate a positive delayed sign DSIGN
 * @param pSdadc the base address of the SDADC instance.
 * @param u8Channel SDADC Channel.
 * @return uint32_t the value of DLY_NEG.
 */
LOCAL_INLINE uint32_t SDADC_HWA_GetDLY_NEG(const SDADC_Type *const pSdadc, uint8_t u8Channel)
{
    uint32_t u32TmpVal = (pSdadc->CSDR[u8Channel] & SDADC_CSDR_DLY_NEG_MASK) >> SDADC_CSDR_DLY_NEG_SHIFT;
    return u32TmpVal;
}

/**
 * @brief Get the value of DLY_POS.
 * Sign Delay Value for Sign Posedge
 * Defines the content of SD_CNT to generate a negative delayed sign DSIGN
 * @param pSdadc the base address of the SDADC instance.
 * @param u8Channel SDADC Channel.
 * @return uint32_t the value of DLY_POS.
 */
LOCAL_INLINE uint32_t SDADC_HWA_GetDLY_POS(const SDADC_Type *const pSdadc, uint8_t u8Channel)
{
    uint32_t u32TmpVal = (pSdadc->CSDR[u8Channel] & SDADC_CSDR_DLY_POS_MASK) >> SDADC_CSDR_DLY_POS_SHIFT;
    return u32TmpVal;
}

/**
 * @brief Get the value of SD_CAP.
 * Sign Delay Capture Value
 * Indicates the results value counted between the negedge of SSIGN and the first received positive value
 * @param pSdadc the base address of the SDADC instance.
 * @param u8Channel SDADC Channel.
 * @return uint32_t the value of SD_CAP.
 */
LOCAL_INLINE uint32_t SDADC_HWA_GetSD_CAP(const SDADC_Type *const pSdadc, uint8_t u8Channel)
{
    uint32_t u32TmpVal = (pSdadc->CSDR[u8Channel] & SDADC_CSDR_SD_CAP_MASK) >> SDADC_CSDR_SD_CAP_SHIFT;
    return u32TmpVal;
}

/**
 * @brief Get the value of SD_CNT.
 * Sign Delay Counter
 * Counts the results values from the filter chain to delay the sign signal, this fild can only be checked after MCIC_COC assert.
 * @param pSdadc the base address of the SDADC instance.
 * @param u8Channel SDADC Channel.
 * @return uint32_t the value of SD_CNT.
 */
LOCAL_INLINE uint32_t SDADC_HWA_GetSD_CNT(const SDADC_Type *const pSdadc, uint8_t u8Channel)
{
    uint32_t u32TmpVal = (pSdadc->CSDR[u8Channel] & SDADC_CSDR_SD_CNT_MASK) >> SDADC_CSDR_SD_CNT_SHIFT;
    return u32TmpVal;
}

/**
 * @brief Get the value of NVALINT.
 * Number of Values to be Accumulated
 * NVALINT+1 defines a complete integration cycle
 * @param pSdadc the base address of the SDADC instance.
 * @param u8Channel SDADC Channel.
 * @return uint32_t the value of NVALINT.
 */
LOCAL_INLINE uint32_t SDADC_HWA_GetNVALINT(const SDADC_Type *const pSdadc, uint8_t u8Channel)
{
    uint32_t u32TmpVal = (pSdadc->CICFR[u8Channel] & SDADC_CICFR_NVALINT_MASK) >> SDADC_CICFR_NVALINT_SHIFT;
    return u32TmpVal;
}

/**
 * @brief Get the value of NVALDIS.
 * Number of Values discarded
 * Start the integration cycle after NVALDIS values
 * @param pSdadc the base address of the SDADC instance.
 * @param u8Channel SDADC Channel.
 * @return uint32_t the value of NVALDIS.
 */
LOCAL_INLINE uint32_t SDADC_HWA_GetNVALDIS(const SDADC_Type *const pSdadc, uint8_t u8Channel)
{
    uint32_t u32TmpVal = (pSdadc->CICFR[u8Channel] & SDADC_CICFR_NVALDIS_MASK) >> SDADC_CICFR_NVALDIS_SHIFT;
    return u32TmpVal;
}

/**
 * @brief Get the value of SYNC_TRGEN.
 * Synced Trigger Select Enable for Integration
 * 0b - Synced trigger is selected on the channel itself.
 * 1b - Synced trigger is selected on the channel defined by SYNC_TRGSEL.
 * @param pSdadc the base address of the SDADC instance.
 * @param u8Channel SDADC Channel.
 * @return uint32_t the value of SYNC_TRGEN.
 */
LOCAL_INLINE uint32_t SDADC_HWA_GetCICFR_SYNC_TRGEN(const SDADC_Type *const pSdadc, uint8_t u8Channel)
{
    uint32_t u32TmpVal = (pSdadc->CICFR[u8Channel] & SDADC_CICFR_SYNC_TRGEN_MASK) >> SDADC_CICFR_SYNC_TRGEN_SHIFT;
    return u32TmpVal;
}

/**
 * @brief Get the value of SYNC_TRGSEL.
 * Synced Trigger Select for Integration
 * Each will detect and sync the trigger input as a synced trigger, this bits can select to use the synced trigger from which channel. By this bits, two or more channels can share the same synced trigger and trigger to start at the same time.
 * 000b - select the trigger from the channel 0.
 * 001b - select the trigger from the channel 1.
 * 010b - select the trigger from the channel 2.
 * ...
 * @param pSdadc the base address of the SDADC instance.
 * @param u8Channel SDADC Channel.
 * @return uint32_t the value of SYNC_TRGSEL.
 */
LOCAL_INLINE uint32_t SDADC_HWA_GetCICFR_SYNC_TRGSEL(const SDADC_Type *const pSdadc, uint8_t u8Channel)
{
    uint32_t u32TmpVal = (pSdadc->CICFR[u8Channel] & SDADC_CICFR_SYNC_TRGSEL_MASK) >> SDADC_CICFR_SYNC_TRGSEL_SHIFT;
    return u32TmpVal;
}

/**
 * @brief Get the value of NVALREP.
 * Number of Integration Cycles
 * NVALREP+1 defines number of integration cycles to be counted by REPCNT if activated(EXTSTP=0)
 * @param pSdadc the base address of the SDADC instance.
 * @param u8Channel SDADC Channel.
 * @return uint32_t the value of NVALREP.
 */
LOCAL_INLINE uint32_t SDADC_HWA_GetNVALREP(const SDADC_Type *const pSdadc, uint8_t u8Channel)
{
    uint32_t u32TmpVal = (pSdadc->CICFR[u8Channel] & SDADC_CICFR_NVALREP_MASK) >> SDADC_CICFR_NVALREP_SHIFT;
    return u32TmpVal;
}

/**
 * @brief Get the value of ITRSEL.
 * Integration Trigger Select
 * 0b - Software trigger selected.
 * 1b - Hardware trigger dedicate to channel selected.
 * @param pSdadc the base address of the SDADC instance.
 * @param u8Channel SDADC Channel.
 * @return uint32_t the value of ITRSEL.
 */
LOCAL_INLINE uint32_t SDADC_HWA_GetITRSEL(const SDADC_Type *const pSdadc, uint8_t u8Channel)
{
    uint32_t u32TmpVal = (pSdadc->CICFR[u8Channel] & SDADC_CICFR_ITRSEL_MASK) >> SDADC_CICFR_ITRSEL_SHIFT;
    return u32TmpVal;
}

/**
 * @brief Get the value of HTRPOL.
 * Hardware Trigger Polarity
 * 0b - High and rising edge effective.
 * 1b - Low and falling edge effective.
 * @param pSdadc the base address of the SDADC instance.
 * @param u8Channel SDADC Channel.
 * @return uint32_t the value of HTRPOL.
 */
LOCAL_INLINE uint32_t SDADC_HWA_GetHTRPOL(const SDADC_Type *const pSdadc, uint8_t u8Channel)
{
    uint32_t u32TmpVal = (pSdadc->CICFR[u8Channel] & SDADC_CICFR_HTRPOL_MASK) >> SDADC_CICFR_HTRPOL_SHIFT;
    return u32TmpVal;
}

/**
 * @brief Get the value of FCRC.
 * Filter Chain Restart Control
 * 0b - Do not restart.
 * 1b - Restart the filter chain when an integration window starts.
 * @param pSdadc the base address of the SDADC instance.
 * @param u8Channel SDADC Channel.
 * @return uint32_t the value of FCRC.
 */
LOCAL_INLINE uint32_t SDADC_HWA_GetFCRC(const SDADC_Type *const pSdadc, uint8_t u8Channel)
{
    uint32_t u32TmpVal = (pSdadc->CICFR[u8Channel] & SDADC_CICFR_FCRC_MASK) >> SDADC_CICFR_FCRC_SHIFT;
    return u32TmpVal;
}

/**
 * @brief Get the value of EXTSTP.
 * Integration Stop Control
 * For Hardware trigger control only.
 * 0b - Internal control, stop integration after NVALREP+1 integration cycles, support both edge and level events.
 * 1b - External control, stop integration upon the inverse trigger event.
 * @param pSdadc the base address of the SDADC instance.
 * @param u8Channel SDADC Channel.
 * @return uint32_t the value of EXTSTP.
 */
LOCAL_INLINE uint32_t SDADC_HWA_GetEXTSTP(const SDADC_Type *const pSdadc, uint8_t u8Channel)
{
    uint32_t u32TmpVal = (pSdadc->CICFR[u8Channel] & SDADC_CICFR_EXTSTP_MASK) >> SDADC_CICFR_EXTSTP_SHIFT;
    return u32TmpVal;
}

/**
 * @brief Get the value of IOGT.
 * Integration Output Gating
 * Setting this bit will gate conversion complete flag and FIFO push when Integration is not on-going. conversion complete flag and FIFO push can only be effective when Integration is not on-going(INTON asserted)
 * 0b - Conversion complete flag and FIFO push always works.
 * 1b - Conversion complete flag and FIFO push can only work when Integration is not on-going(INTON asserted)
 * @param pSdadc the base address of the SDADC instance.
 * @param u8Channel SDADC Channel.
 * @return uint32_t the value of IOGT.
 */
LOCAL_INLINE uint32_t SDADC_HWA_GetIOGT(const SDADC_Type *const pSdadc, uint8_t u8Channel)
{
    uint32_t u32TmpVal = (pSdadc->CICFR[u8Channel] & SDADC_CICFR_IOGT_MASK) >> SDADC_CICFR_IOGT_SHIFT;
    return u32TmpVal;
}

/**
 * @brief Get the value of ISVAL.
 * Integration Shift value
 * 000b - Shift 0 bits
 * 001b - Shift 1 bits, for 2 values integration
 * 010b - Shift 2 bits, for 3-4 values integration
 * 011b - Shift 3 bits, for 5-8 values integration
 * 100b - Shift 4 bits, for 9-16 values integration
 * 101b - Shift 5 bits, for 17-32 values integration
 * 110b - Shift 6 bits, for 33-64 values integration
 * @param pSdadc the base address of the SDADC instance.
 * @param u8Channel SDADC Channel.
 * @return uint32_t the value of ISVAL.
 */
LOCAL_INLINE uint32_t SDADC_HWA_GetISVAL(const SDADC_Type *const pSdadc, uint8_t u8Channel)
{
    uint32_t u32TmpVal = (pSdadc->CICFR[u8Channel] & SDADC_CICFR_ISVAL_MASK) >> SDADC_CICFR_ISVAL_SHIFT;
    return u32TmpVal;
}

/**
 * @brief Get the value of INTGON.
 * Integration on Flag
 * Indicates the activity of the integration.
 * 0b - Integration stopped.
 * 1b - Integration enabled and on-going.
 * @param pSdadc the base address of the SDADC instance.
 * @param u8Channel SDADC Channel.
 * @return uint32_t the value of INTGON.
 */
LOCAL_INLINE uint32_t SDADC_HWA_GetINTGON(const SDADC_Type *const pSdadc, uint8_t u8Channel)
{
    uint32_t u32TmpVal = (pSdadc->CISR[u8Channel] & SDADC_CISR_INTGON_MASK) >> SDADC_CISR_INTGON_SHIFT;
    return u32TmpVal;
}

#ifdef SDADC_CISR_REPCNT_MASK
/**
 * @brief Get the value of REPCNT.
 * Repeat Integration Cycle Counter
 * Counts the number of integration cycles if activated (EXTSTP=0), this field can only be checked after COC assert.
 * @param pSdadc the base address of the SDADC instance.
 * @param u8Channel SDADC Channel.
 * @return uint32_t the value of REPCNT.
 */
LOCAL_INLINE uint32_t SDADC_HWA_GetREPCNT(const SDADC_Type *const pSdadc, uint8_t u8Channel)
{
    uint32_t u32TmpVal = (pSdadc->CISR[u8Channel] & SDADC_CISR_REPCNT_MASK) >> SDADC_CISR_REPCNT_SHIFT;
    return u32TmpVal;
}
#endif

#ifdef SDADC_CISR_VALCNT_MASK
/**
 * @brief Get the value of VALCNT.
 * Number of Values Counted
 * Counts the number of integrated values during discard cycle or during integration cycles, this fild can only be checked after MCIC_COC assert.
 * @param pSdadc the base address of the SDADC instance.
 * @param u8Channel SDADC Channel.
 * @return uint32_t the value of VALCNT.
 */
LOCAL_INLINE uint32_t SDADC_HWA_GetVALCNT(const SDADC_Type *const pSdadc, uint8_t u8Channel)
{
    uint32_t u32TmpVal = (pSdadc->CISR[u8Channel] & SDADC_CISR_VALCNT_MASK) >> SDADC_CISR_VALCNT_SHIFT;
    return u32TmpVal;
}
#endif

/**
 * @brief Get the value of INTVAL.
 * Results of most recent accumulation, this fild can only be checked after MCIC_COC assert.
 * @param pSdadc the base address of the SDADC instance.
 * @param u8Channel SDADC Channel.
 * @return uint32_t the value of INTVAL.
 */
LOCAL_INLINE uint32_t SDADC_HWA_GetINTVAL(const SDADC_Type *const pSdadc, uint8_t u8Channel)
{
    uint32_t u32TmpVal = (pSdadc->CIVAL[u8Channel] & SDADC_CIVAL_INTVAL_MASK) >> SDADC_CIVAL_INTVAL_SHIFT;
    return u32TmpVal;
}

/**
 * @brief Get the value of MASEL.
 * Modulator Analog Selection
 * 0b - External modulator analog is selected as channel input.
 * 1b - Internal modulator analog is selected as channel input.
 * @param pSdadc the base address of the SDADC instance.
 * @param u8Channel SDADC Channel.
 * @return uint32_t the value of MASEL.
 */
LOCAL_INLINE uint32_t SDADC_HWA_GetMASEL(const SDADC_Type *const pSdadc, uint8_t u8Channel)
{
    uint32_t u32TmpVal = (pSdadc->CMACSR[u8Channel] & SDADC_CMACSR_MASEL_MASK) >> SDADC_CMACSR_MASEL_SHIFT;
    return u32TmpVal;
}

/**
 * @brief Set MASEL.
 * Modulator Analog Selection
 * 0b - External modulator analog is selected as channel input.
 * 1b - Internal modulator analog is selected as channel input.
 * @param pSdadc the base address of the SDADC instance.
 * @param u8Channel SDADC Channel.
 * @param uint32_t u32Value MASEL value.
 */
LOCAL_INLINE void SDADC_HWA_SetMASEL(SDADC_Type *const pSdadc, uint8_t u8Channel, uint32_t u32Value)
{
    pSdadc->CMACSR[u8Channel] = (pSdadc->CMACSR[u8Channel] & ~SDADC_CMACSR_MASEL_MASK) | SDADC_CMACSR_MASEL(u32Value);
}

/**
 * @brief Get the value of MACLKSEL.
 * Internal Modulator Analog Clock Selection
 * 00b - Div_clk1 is selected as the clock, output bitstream is sampled on a clock with frequency of F_div_clk1/2.
 * 01b - Div_clk0 is selected as the clock, output bitstream is sampled on a clock with frequency of F_div_clk1/2.
 * 1*b - Reserved.
 * @param pSdadc the base address of the SDADC instance.
 * @param u8Channel SDADC Channel.
 * @return uint32_t the value of MACLKSEL.
 */
LOCAL_INLINE uint32_t SDADC_HWA_GetMACLKSEL(const SDADC_Type *const pSdadc, uint8_t u8Channel)
{
    uint32_t u32TmpVal = (pSdadc->CMACSR[u8Channel] & SDADC_CMACSR_MACLKSEL_MASK) >> SDADC_CMACSR_MACLKSEL_SHIFT;
    return u32TmpVal;
}

/**
 * @brief Set MACLKSEL.
 * Internal Modulator Analog Clock Selection
 * 00b - Div_clk1 is selected as the clock, output bitstream is sampled on a clock with frequency of F_div_clk1/2.
 * 01b - Div_clk0 is selected as the clock, output bitstream is sampled on a clock with frequency of F_div_clk1/2.
 * 1*b - Reserved.
 * @param pSdadc the base address of the SDADC instance.
 * @param u8Channel SDADC Channel.
 * @param uint32_t u32Value MACLKSEL value.
 */
LOCAL_INLINE void SDADC_HWA_SetMACLKSEL(SDADC_Type *const pSdadc, uint8_t u8Channel, uint32_t u32Value)
{
    pSdadc->CMACSR[u8Channel] = (pSdadc->CMACSR[u8Channel] & ~SDADC_CMACSR_MACLKSEL_MASK) | SDADC_CMACSR_MACLKSEL(u32Value);
}

/**
 * @brief Get the value of RSTSEL.
 * Modulator Analog Reset Cycle Selection
 * Select RSTSEL+1 mclk cycles for modulator analog reset after a channel conversion trigger. This is needed especially when the input mux(INMUX) is changed.
 * 0d - Modulator analog is not reset after a channel conversion trigger
 * 1d - Modulator analog is reset for 2 mclk cycles after a channel conversion trigger. Total 7 mclk cycle cycles needed for filters start to run after a channel conversion trigger.
 * 2d - Modulator analog is reset for 3 mclk cycles after a channel conversion trigger. Total 8 mclk cycle cycles needed for filters start to run after a channel conversion trigger.
 * ...
 * 8d - Modulator analog is reset for 9 mclk cycles after a channel conversion trigger. Total 14 mclk cycle cycles needed for filters start to run after a channel conversion trigger.
 * 9-15d - Modulator analog is reset for 10 mclk cycles after a channel conversion trigger. Total 15 mclk cycle cycles needed for filters start to run after a channel conversion trigger.
 * @param pSdadc the base address of the SDADC instance.
 * @param u8Channel SDADC Channel.
 * @return uint32_t the value of RSTSEL.
 */
LOCAL_INLINE uint32_t SDADC_HWA_GetRSTSEL(const SDADC_Type *const pSdadc, uint8_t u8Channel)
{
    uint32_t u32TmpVal = (pSdadc->CMACSR[u8Channel] & SDADC_CMACSR_RSTSEL_MASK) >> SDADC_CMACSR_RSTSEL_SHIFT;
    return u32TmpVal;
}

/**
 * @brief Set RSTSEL.
 * Modulator Analog Reset Cycle Selection
 * Select RSTSEL+1 mclk cycles for modulator analog reset after a channel conversion trigger. This is needed especially when the input mux(INMUX) is changed.
 * 0d - Modulator analog is not reset after a channel conversion trigger
 * 1d - Modulator analog is reset for 2 mclk cycles after a channel conversion trigger. Total 7 mclk cycle cycles needed for filters start to run after a channel conversion trigger.
 * 2d - Modulator analog is reset for 3 mclk cycles after a channel conversion trigger. Total 8 mclk cycle cycles needed for filters start to run after a channel conversion trigger.
 * ...
 * 8d - Modulator analog is reset for 9 mclk cycles after a channel conversion trigger. Total 14 mclk cycle cycles needed for filters start to run after a channel conversion trigger.
 * 9-15d - Modulator analog is reset for 10 mclk cycles after a channel conversion trigger. Total 15 mclk cycle cycles needed for filters start to run after a channel conversion trigger.
 * @param pSdadc the base address of the SDADC instance.
 * @param u8Channel SDADC Channel.
 * @param uint32_t u32Value RSTSEL value.
 */
LOCAL_INLINE void SDADC_HWA_SetRSTSEL(SDADC_Type *const pSdadc, uint8_t u8Channel, uint32_t u32Value)
{
    pSdadc->CMACSR[u8Channel] = (pSdadc->CMACSR[u8Channel] & ~SDADC_CMACSR_RSTSEL_MASK) | SDADC_CMACSR_RSTSEL(u32Value);
}

/**
 * @brief Get the value of DITHER_EN.
 * Dither Enable
 * This bit enable the dither to analog circuit to remove the idle tone.
 * 0b - Dither is disabled.
 * 1b - Dither is enabled.
 * @param pSdadc the base address of the SDADC instance.
 * @param u8Channel SDADC Channel.
 * @return uint32_t the value of DITHER_EN.
 */
LOCAL_INLINE uint32_t SDADC_HWA_GetDITHER_EN(const SDADC_Type *const pSdadc, uint8_t u8Channel)
{
    uint32_t u32TmpVal = (pSdadc->CMACSR[u8Channel] & SDADC_CMACSR_DITHER_EN_MASK) >> SDADC_CMACSR_DITHER_EN_SHIFT;
    return u32TmpVal;
}

/**
 * @brief Get the value of INCFGPV11.
 * Configuration of Positive Input Line with V11 from System
 * This bit have higher priority then INCFGP, this this bit is set, INCFGP is ignored.
 * 0b - Positive input from V11 disabled.
 * 1b - Positive input from V11 enabled.
 * @param pSdadc the base address of the SDADC instance.
 * @param u8Channel SDADC Channel.
 * @return uint32_t the value of INCFGPV11.
 */
LOCAL_INLINE uint32_t SDADC_HWA_GetINCFGPV11(const SDADC_Type *const pSdadc, uint8_t u8Channel)
{
    uint32_t u32TmpVal = (pSdadc->CMACSR[u8Channel] & SDADC_CMACSR_INCFGPV11_MASK) >> SDADC_CMACSR_INCFGPV11_SHIFT;
    return u32TmpVal;
}

/**
 * @brief Get the value of GAINSEL.
 * Gain Select of Analog Input Path
 * 00b - 1.
 * 01b - 2.
 * 10b - 4.
 * 11b - 8.
 * @param pSdadc the base address of the SDADC instance.
 * @param u8Channel SDADC Channel.
 * @return uint32_t the value of GAINSEL.
 */
LOCAL_INLINE uint32_t SDADC_HWA_GetGAINSEL(const SDADC_Type *const pSdadc, uint8_t u8Channel)
{
    uint32_t u32TmpVal = (pSdadc->CMACSR[u8Channel] & SDADC_CMACSR_GAINSEL_MASK) >> SDADC_CMACSR_GAINSEL_SHIFT;
    return u32TmpVal;
}

/**
 * @brief Set GAINSEL.
 * Gain Select of Analog Input Path
 * 00b - 1.
 * 01b - 2.
 * 10b - 4.
 * 11b - 8.
 * @param pSdadc the base address of the SDADC instance.
 * @param u8Channel SDADC Channel.
 * @param uint32_t u32Value GAINSEL value.
 */
LOCAL_INLINE void SDADC_HWA_SetGAINSEL(SDADC_Type *const pSdadc, uint8_t u8Channel, uint32_t u32Value)
{
    pSdadc->CMACSR[u8Channel] = (pSdadc->CMACSR[u8Channel] & ~SDADC_CMACSR_GAINSEL_MASK) | SDADC_CMACSR_GAINSEL(u32Value);
}

/**
 * @brief Get the value of CMENP.
 * Common Voltage Configuration of Positive Inputs
 * Defines the connection of respective negative input to the common mode voltage, bit n(0-3) controls if Pin n is connected to the common mode voltage.
 * 0b -  Is NOT connected to the common mode voltage.
 * 1b -  Is connected to the common mode voltage.
 * @param pSdadc the base address of the SDADC instance.
 * @param u8Channel SDADC Channel.
 * @return uint32_t the value of CMENP.
 */
LOCAL_INLINE uint32_t SDADC_HWA_GetCMENP(const SDADC_Type *const pSdadc, uint8_t u8Channel)
{
    uint32_t u32TmpVal = (pSdadc->CMACSR[u8Channel] & SDADC_CMACSR_CMENP_MASK) >> SDADC_CMACSR_CMENP_SHIFT;
    return u32TmpVal;
}

/**
 * @brief Set CMENP.
 * Common Voltage Configuration of Positive Inputs
 * Defines the connection of respective negative input to the common mode voltage, bit n(0-3) controls if Pin n is connected to the common mode voltage.
 * 0b -  Is NOT connected to the common mode voltage.
 * 1b -  Is connected to the common mode voltage.
 * @param pSdadc the base address of the SDADC instance.
 * @param u8Channel SDADC Channel.
 * @param uint32_t u32Value CMENP value.
 */
LOCAL_INLINE void SDADC_HWA_SetCMENP(SDADC_Type *const pSdadc, uint8_t u8Channel, uint32_t u32Value)
{
    pSdadc->CMACSR[u8Channel] = (pSdadc->CMACSR[u8Channel] & ~SDADC_CMACSR_CMENP_MASK) | SDADC_CMACSR_CMENP(u32Value);
}

/**
 * @brief Get the value of CMENM.
 * Common Voltage Configuration of Negative Inputs
 * Defines the connection of respective negative input to the common mode voltage, bit n(0-3) controls if Pin n is connected to the common mode voltage.
 * 0b -  Is NOT connected to the common mode voltage.
 * 1b -  Is connected to the common mode voltage.
 * @param pSdadc the base address of the SDADC instance.
 * @param u8Channel SDADC Channel.
 * @return uint32_t the value of CMENM.
 */
LOCAL_INLINE uint32_t SDADC_HWA_GetCMENM(const SDADC_Type *const pSdadc, uint8_t u8Channel)
{
    uint32_t u32TmpVal = (pSdadc->CMACSR[u8Channel] & SDADC_CMACSR_CMENM_MASK) >> SDADC_CMACSR_CMENM_SHIFT;
    return u32TmpVal;
}

/**
 * @brief Set CMENM.
 * Common Voltage Configuration of Negative Inputs
 * Defines the connection of respective negative input to the common mode voltage, bit n(0-3) controls if Pin n is connected to the common mode voltage.
 * 0b -  Is NOT connected to the common mode voltage.
 * 1b -  Is connected to the common mode voltage.
 * @param pSdadc the base address of the SDADC instance.
 * @param u8Channel SDADC Channel.
 * @param uint32_t u32Value CMENM value.
 */
LOCAL_INLINE void SDADC_HWA_SetCMENM(SDADC_Type *const pSdadc, uint8_t u8Channel, uint32_t u32Value)
{
    pSdadc->CMACSR[u8Channel] = (pSdadc->CMACSR[u8Channel] & ~SDADC_CMACSR_CMENM_MASK) | SDADC_CMACSR_CMENM(u32Value);
}

/**
 * @brief Get the value of INCFGP.
 * Configuration of Positive Input Line
 * 00b - From input Pin.
 * 01b - From VREFL.
 * 10b - From VREFH.
 * 11b - From VREFH/2.
 * @param pSdadc the base address of the SDADC instance.
 * @param u8Channel SDADC Channel.
 * @return uint32_t the value of INCFGP.
 */
LOCAL_INLINE uint32_t SDADC_HWA_GetINCFGP(const SDADC_Type *const pSdadc, uint8_t u8Channel)
{
    uint32_t u32TmpVal = (pSdadc->CMACSR[u8Channel] & SDADC_CMACSR_INCFGP_MASK) >> SDADC_CMACSR_INCFGP_SHIFT;
    return u32TmpVal;
}

/**
 * @brief Set INCFGP.
 * Configuration of Positive Input Line
 * 00b - From input Pin.
 * 01b - From VREFL.
 * 10b - From VREFH.
 * 11b - From VREFH/2.
 * @param pSdadc the base address of the SDADC instance.
 * @param u8Channel SDADC Channel.
 * @param uint32_t u32Value INCFGP value.
 */
LOCAL_INLINE void SDADC_HWA_SetINCFGP(SDADC_Type *const pSdadc, uint8_t u8Channel, uint32_t u32Value)
{
    pSdadc->CMACSR[u8Channel] = (pSdadc->CMACSR[u8Channel] & ~SDADC_CMACSR_INCFGP_MASK) | SDADC_CMACSR_INCFGP(u32Value);
}

/**
 * @brief Get the value of INCFGM.
 * Configuration of Negative Input Line
 * 00b - From input Pin.
 * 01b - From VREFL.
 * 10b - From VREFH.
 * 11b - From VREFH/2.
 * @param pSdadc the base address of the SDADC instance.
 * @param u8Channel SDADC Channel.
 * @return uint32_t the value of INCFGM.
 */
LOCAL_INLINE uint32_t SDADC_HWA_GetINCFGM(const SDADC_Type *const pSdadc, uint8_t u8Channel)
{
    uint32_t u32TmpVal = (pSdadc->CMACSR[u8Channel] & SDADC_CMACSR_INCFGM_MASK) >> SDADC_CMACSR_INCFGM_SHIFT;
    return u32TmpVal;
}

/**
 * @brief Set INCFGM.
 * Configuration of Negative Input Line
 * 00b - From input Pin.
 * 01b - From VREFL.
 * 10b - From VREFH.
 * 11b - From VREFH/2.
 * @param pSdadc the base address of the SDADC instance.
 * @param u8Channel SDADC Channel.
 * @param uint32_t u32Value INCFGM value.
 */
LOCAL_INLINE void SDADC_HWA_SetINCFGM(SDADC_Type *const pSdadc, uint8_t u8Channel, uint32_t u32Value)
{
    pSdadc->CMACSR[u8Channel] = (pSdadc->CMACSR[u8Channel] & ~SDADC_CMACSR_INCFGM_MASK) | SDADC_CMACSR_INCFGM(u32Value);
}

/**
 * @brief Get the value of INMUX.
 * Active Input Pin Selection
 * Indicates the active input pin selection for input MUX.
 * 00b - Input pin 0 selected.
 * 01b - Input pin 1 selected.
 * 10b - Input pin 2 selected.
 * 11b - Input pin 3 selected.
 * @param pSdadc the base address of the SDADC instance.
 * @param u8Channel SDADC Channel.
 * @return uint32_t the value of INMUX.
 */
LOCAL_INLINE uint32_t SDADC_HWA_GetINMUX(const SDADC_Type *const pSdadc, uint8_t u8Channel)
{
    uint32_t u32TmpVal = (pSdadc->CMACSR[u8Channel] & SDADC_CMACSR_INMUX_MASK) >> SDADC_CMACSR_INMUX_SHIFT;
    return u32TmpVal;
}

/**
 * @brief Get the value of INSEL.
 * Input Pin Selection
 * Defines the initial or permanent setting for the input MUX(bits INMUX) depending on the selected operating mode (bits INMOD).
 * @param pSdadc the base address of the SDADC instance.
 * @param u8Channel SDADC Channel.
 * @return uint32_t the value of INSEL.
 */
LOCAL_INLINE uint32_t SDADC_HWA_GetINSEL(const SDADC_Type *const pSdadc, uint8_t u8Channel)
{
    uint32_t u32TmpVal = (pSdadc->CMACSR[u8Channel] & SDADC_CMACSR_INSEL_MASK) >> SDADC_CMACSR_INSEL_SHIFT;
    return u32TmpVal;
}

/**
 * @brief Set INSEL.
 * Input Pin Selection
 * Defines the initial or permanent setting for the input MUX(bits INMUX) depending on the selected operating mode (bits INMOD).
 * @param pSdadc the base address of the SDADC instance.
 * @param u8Channel SDADC Channel.
 * @param uint32_t u32Value INSEL value.
 */
LOCAL_INLINE void SDADC_HWA_SetINSEL(SDADC_Type *const pSdadc, uint8_t u8Channel, uint32_t u32Value)
{
    pSdadc->CMACSR[u8Channel] = (pSdadc->CMACSR[u8Channel] & ~SDADC_CMACSR_INSEL_MASK) | SDADC_CMACSR_INSEL(u32Value);
}

/**
 * @brief Get the value of INMOD.
 * Input MUX Control Mode
 * 00b - Software control mode (INMUX follows INSEL).
 * 01b - Preset mode (load INMUX upon a channel conversion trigger).
 * 10b - Scan mode (decrement INMUX upon a channel conversion trigger, wrap around to INSEL).
 * 11b - Reserved.
 * @param pSdadc the base address of the SDADC instance.
 * @param u8Channel SDADC Channel.
 * @return uint32_t the value of INMOD.
 */
LOCAL_INLINE uint32_t SDADC_HWA_GetINMOD(const SDADC_Type *const pSdadc, uint8_t u8Channel)
{
    uint32_t u32TmpVal = (pSdadc->CMACSR[u8Channel] & SDADC_CMACSR_INMOD_MASK) >> SDADC_CMACSR_INMOD_SHIFT;
    return u32TmpVal;
}

/**
 * @brief Set INMOD.
 * Input MUX Control Mode
 * 00b - Software control mode (INMUX follows INSEL).
 * 01b - Preset mode (load INMUX upon a channel conversion trigger).
 * 10b - Scan mode (decrement INMUX upon a channel conversion trigger, wrap around to INSEL).
 * 11b - Reserved.
 * @param pSdadc the base address of the SDADC instance.
 * @param u8Channel SDADC Channel.
 * @param uint32_t u32Value INMOD value.
 */
LOCAL_INLINE void SDADC_HWA_SetINMOD(SDADC_Type *const pSdadc, uint8_t u8Channel, uint32_t u32Value)
{
    pSdadc->CMACSR[u8Channel] = (pSdadc->CMACSR[u8Channel] & ~SDADC_CMACSR_INMOD_MASK) | SDADC_CMACSR_INMOD(u32Value);
}

/**
 * @brief Get the value of OPT1.
 * Offset Option 1
 * This is an offset value provided by factory test for modulator analog input path gain=2.
 * User need read this field and left shift it by 8 bit to form a 24-bit offset and then write to related CBR register
 * @param pSdadc the base address of the SDADC instance.
 * @param u8Channel SDADC Channel.
 * @return uint32_t the value of OPT1.
 */
LOCAL_INLINE uint32_t SDADC_HWA_GetOffsetOPT1(const SDADC_Type *const pSdadc, uint8_t u8Channel)
{
    uint32_t u32TmpVal = (pSdadc->COFCAL[u8Channel] & SDADC_COFCAL_OPT1_MASK) >> SDADC_COFCAL_OPT1_SHIFT;
    return u32TmpVal;
}

/**
 * @brief Get the value of OPT0.
 * Offset Option 0
 * This is an offset value provided by factory test for modulator analog input path gain=1.
 * User need read this field and left shift it by 8 bit to form a 24-bit offset and then write to related CBR register
 * @param pSdadc the base address of the SDADC instance.
 * @param u8Channel SDADC Channel.
 * @return uint32_t the value of OPT0.
 */
LOCAL_INLINE uint32_t SDADC_HWA_GetOffsetOPT0(const SDADC_Type *const pSdadc, uint8_t u8Channel)
{
    uint32_t u32TmpVal = (pSdadc->COFCAL[u8Channel] & SDADC_COFCAL_OPT0_MASK) >> SDADC_COFCAL_OPT0_SHIFT;
    return u32TmpVal;
}

/**
 * @brief Get the value of OPT1.
 * Gain Option 1
 * This is a gain factor provided by factory test for modulator analog input path gain=2.
 * User need read this field and multiply it with gain correction factor 2^m and then write to related CGNR register
 * @param pSdadc the base address of the SDADC instance.
 * @param u8Channel SDADC Channel.
 * @return uint32_t the value of OPT1.
 */
LOCAL_INLINE uint32_t SDADC_HWA_GetGainOPT1(const SDADC_Type *const pSdadc, uint8_t u8Channel)
{
    uint32_t u32TmpVal = (pSdadc->CGNCAL[u8Channel] & SDADC_CGNCAL_OPT1_MASK) >> SDADC_CGNCAL_OPT1_SHIFT;
    return u32TmpVal;
}

/**
 * @brief Get the value of OPT0.
 * Gain Option 0
 * This is a gain factor provided by factory test for modulator analog input path gain=1.
 * User need read this field and multiply it with gain correction factor 2^m and then write to related CGNR register
 * @param pSdadc the base address of the SDADC instance.
 * @param u8Channel SDADC Channel.
 * @return uint32_t the value of OPT0.
 */
LOCAL_INLINE uint32_t SDADC_HWA_GetGainOPT0(const SDADC_Type *const pSdadc, uint8_t u8Channel)
{
    uint32_t u32TmpVal = (pSdadc->CGNCAL[u8Channel] & SDADC_CGNCAL_OPT0_MASK) >> SDADC_CGNCAL_OPT0_SHIFT;
    return u32TmpVal;
}

/**
 * @brief Get the value of GAIN_FAC.
 * Gain Factor
 * This bit field defines a gain factor(GAIN_FAC[17:0]/2^16, range is from 0 to 4) which is multiplied with the data after HPF to compensate the gain error caused by analog circuits or the gain mismatch when decimation factor is not 2^N, after compensation, the total gain from analog input to data from FIFO should be 1.
 * GAIN_FAC can be got from calibration, it should be in a suitable range, or the data output may be saturated.
 * When GAIN_FAC[17:0]=0, GAIN block is bypassed.
 * @param pSdadc the base address of the SDADC instance.
 * @param u8Channel SDADC Channel.
 * @return uint32_t the value of GAIN_FAC.
 */
LOCAL_INLINE uint32_t SDADC_HWA_GetGAIN_FAC(const SDADC_Type *const pSdadc, uint8_t u8Channel)
{
    uint32_t u32TmpVal = (pSdadc->CGNR[u8Channel] & SDADC_CGNR_GAIN_FAC_MASK) >> SDADC_CGNR_GAIN_FAC_SHIFT;
    return u32TmpVal;
}

/**
 * @brief Get the value of SYNC_TRGEN.
 * Synced Trigger Select Enable for Timestamp
 * 0b - Synced trigger is selected on the channel itself.
 * 1b - Synced trigger is selected on the channel defined by SYNC_TRGSEL.
 * @param pSdadc the base address of the SDADC instance.
 * @param u8Channel SDADC Channel.
 * @return uint32_t the value of SYNC_TRGEN.
 */
LOCAL_INLINE uint32_t SDADC_HWA_GetCTSCNT_SYNC_TRGEN(const SDADC_Type *const pSdadc, uint8_t u8Channel)
{
    uint32_t u32TmpVal = (pSdadc->CTSCNT[u8Channel] & SDADC_CTSCNT_SYNC_TRGEN_MASK) >> SDADC_CTSCNT_SYNC_TRGEN_SHIFT;
    return u32TmpVal;
}

/**
 * @brief Get the value of SYNC_TRGSEL.
 * Synced Trigger Select for Timestamp
 * Each will detect and sync the trigger input as a synced trigger, this bits can select to use the synced trigger from which channel. By this bits, two or more channels can share the same synced trigger and trigger to start at the same time.
 * 000b - Select the trigger from the channel 0.
 * 001b - Select the trigger from the channel 1.
 * 010b - Select the trigger from the channel 2.
 * ...
 * @param pSdadc the base address of the SDADC instance.
 * @param u8Channel SDADC Channel.
 * @return uint32_t the value of SYNC_TRGSEL.
 */
LOCAL_INLINE uint32_t SDADC_HWA_GetCTSCNT_SYNC_TRGSEL(const SDADC_Type *const pSdadc, uint8_t u8Channel)
{
    uint32_t u32TmpVal = (pSdadc->CTSCNT[u8Channel] & SDADC_CTSCNT_SYNC_TRGSEL_MASK) >> SDADC_CTSCNT_SYNC_TRGSEL_SHIFT;
    return u32TmpVal;
}

/**
 * @brief Get the value of TSRDM.
 * Timestamp Information Read Mode
 * 00b - Default mode, timestamp information can only be got by reading CTSINFOn register captured by trigger event. FIFO is used for conversion results only and can be pop from FIFO by reading CRDATAn.
 *
 * 01b - Direct mode. Timestamp information is saved in CRDATAn[15:0]. Conversion result is not saved in FIFO(FIFO pop and push are gated), it is cut, round to 16-bit and saved in CRDATAn[31:16] once conversion completes. In this mode, application can read conversion result and timestamp information at same time.
 *
 * 10b - FIFO gating mode. The FIFO is gated before the timestamp trigger event(none active trigger level), a timestamp trigger event(rising edge or falling edge) will capture the current timestamp and save it in TSTAMP[15:0] of CTSINFOn register and CRDATAn[15:0] is bypass to TSTAMP[15:0]. This trigger will also capture last conversion result and save it in FIFO, and then following conversion results are push to FIFO one by one until trigger level is not active again, the 24 bits result out from FIFO is cut/ round to 16 bits and sent to CRDATAn[31:16]. In this mode, application read CRDATAn will get both  conversion result and captured timestamp information at same time after the trigger.
 *
 * 11b - Reserved.
 * @param pSdadc the base address of the SDADC instance.
 * @param u8Channel SDADC Channel.
 * @return uint32_t the value of TSRDM.
 */
LOCAL_INLINE uint32_t SDADC_HWA_GetTSRDM(const SDADC_Type *const pSdadc, uint8_t u8Channel)
{
    uint32_t u32TmpVal = (pSdadc->CTSCNT[u8Channel] & SDADC_CTSCNT_TSRDM_MASK) >> SDADC_CTSCNT_TSRDM_SHIFT;
    return u32TmpVal;
}

/**
 * @brief Get the value of TSTRGM.
 * Timestamp Counter Trigger Mode
 * 00/11b - Trigger is ignored.
 * 01b - Rising edge effective. Trigger level low will gating conversion results push to FIFO if TSRDM is 2'b10. Trigger level high will allow conversion results push to FIFO if TSRDM is 2'b10.
 * 10b - Falling edge effective. Trigger level High will gating conversion results push to FIFO if TSRDM is 2'b10. Trigger level low will allow conversion results push to FIFO if TSRDM is 2'b10.
 * @param pSdadc the base address of the SDADC instance.
 * @param u8Channel SDADC Channel.
 * @return uint32_t the value of TSTRGM.
 */
LOCAL_INLINE uint32_t SDADC_HWA_GetTSTRGM(const SDADC_Type *const pSdadc, uint8_t u8Channel)
{
    uint32_t u32TmpVal = (pSdadc->CTSCNT[u8Channel] & SDADC_CTSCNT_TSTRGM_MASK) >> SDADC_CTSCNT_TSTRGM_SHIFT;
    return u32TmpVal;
}

/**
 * @brief Get the value of INMXCP.
 * Input Mux Setting Copy Enable
 * 0b - Disabled.
 * 1b - Copy INMUX from CMACSR to TSTAMP[15:14].
 * @param pSdadc the base address of the SDADC instance.
 * @param u8Channel SDADC Channel.
 * @return uint32_t the value of INMXCP.
 */
LOCAL_INLINE uint32_t SDADC_HWA_GetINMXCP(const SDADC_Type *const pSdadc, uint8_t u8Channel)
{
    uint32_t u32TmpVal = (pSdadc->CTSCNT[u8Channel] & SDADC_CTSCNT_INMXCP_MASK) >> SDADC_CTSCNT_INMXCP_SHIFT;
    return u32TmpVal;
}

/**
 * @brief Get the value of TS_EN.
 * Timestamp Counter Enable
 * 0b - Disabled.
 * 1b - Counting at the rate selected by TSCLKSEL.
 * @param pSdadc the base address of the SDADC instance.
 * @param u8Channel SDADC Channel.
 * @return uint32_t the value of TS_EN.
 */
LOCAL_INLINE uint32_t SDADC_HWA_GetTS_EN(const SDADC_Type *const pSdadc, uint8_t u8Channel)
{
    uint32_t u32TmpVal = (pSdadc->CTSCNT[u8Channel] & SDADC_CTSCNT_TS_EN_MASK) >> SDADC_CTSCNT_TS_EN_SHIFT;
    return u32TmpVal;
}

/**
 * @brief Get the value of TSCLKSEL.
 * Timestamp Counter Clock Selection
 * 00b - Modulator clock.
 * 01b - Modulator clock divided by 2.
 * 10b - Modulator clock divided by 4.
 * 11b - Modulator clock divided by 8.
 * @param pSdadc the base address of the SDADC instance.
 * @param u8Channel SDADC Channel.
 * @return uint32_t the value of TSCLKSEL.
 */
LOCAL_INLINE uint32_t SDADC_HWA_GetTSCLKSEL(const SDADC_Type *const pSdadc, uint8_t u8Channel)
{
    uint32_t u32TmpVal = (pSdadc->CTSCNT[u8Channel] & SDADC_CTSCNT_TSCLKSEL_MASK) >> SDADC_CTSCNT_TSCLKSEL_SHIFT;
    return u32TmpVal;
}

/**
 * @brief Get the value of TSCNT.
 * Timestamp Counter Value
 * TSCNT is clocked with the modulator clock and is cleared when a new result value has been generated.
 * @param pSdadc the base address of the SDADC instance.
 * @param u8Channel SDADC Channel.
 * @return uint32_t the value of TSCNT.
 */
LOCAL_INLINE uint32_t SDADC_HWA_GetTSCNT(const SDADC_Type *const pSdadc, uint8_t u8Channel)
{
    uint32_t u32TmpVal = (pSdadc->CTSCNT[u8Channel] & SDADC_CTSCNT_TSCNT_MASK) >> SDADC_CTSCNT_TSCNT_SHIFT;
    return u32TmpVal;
}

/**
 * @brief Get the value of TSDATA.
 * The Latest Captured Conversion Result
 * Copied from saved conversion result.
 * @param pSdadc the base address of the SDADC instance.
 * @param u8Channel SDADC Channel.
 * @return uint32_t the value of TSDATA.
 */
LOCAL_INLINE uint32_t SDADC_HWA_GetTSDATA(const SDADC_Type *const pSdadc, uint8_t u8Channel)
{
    uint32_t u32TmpVal = (pSdadc->CTSINFO[u8Channel] & SDADC_CTSINFO_TSDATA_MASK) >> SDADC_CTSINFO_TSDATA_SHIFT;
    return u32TmpVal;
}

/**
 * @brief Get the value of TSTAMP.
 * The Latest Captured Timestamp Value
 * Copy from timestamp counter TSCNT at the trigger event.
 * @param pSdadc the base address of the SDADC instance.
 * @param u8Channel SDADC Channel.
 * @return uint32_t the value of TSTAMP.
 */
LOCAL_INLINE uint32_t SDADC_HWA_GetTSTAMP(const SDADC_Type *const pSdadc, uint8_t u8Channel)
{
    uint32_t u32TmpVal = (pSdadc->CTSINFO[u8Channel] & SDADC_CTSINFO_TSTAMP_MASK) >> SDADC_CTSINFO_TSTAMP_SHIFT;
    return u32TmpVal;
}

/**
 * @brief Get the value of the Channel Configuration Register (CFR) for a specified channel.
 *
 * This function retrieves the value of the Channel Configuration Register (CFR) for a given channel
 * in the SDADC instance.
 *
 * @param pSdadc the base address of the SDADC instance.
 * @param u8Channel the channel number for which the CFR value is to be retrieved.
 *
 * @return uint32_t the value of the CFR for the specified channel.
 */
LOCAL_INLINE uint32_t SDADC_HWA_GetCFRn(const SDADC_Type *const pSdadc, uint8_t u8Channel)
{
    return SDADC_CHANNELCFGREG(pSdadc)[u8Channel].CFR;
}

/**
 * @brief Set the value of the Channel Configuration Register (CFR) for a specified channel.
 *
 * This function sets the value of the Channel Configuration Register (CFR) for a given channel
 * in the SDADC instance.
 *
 * @param pSdadc the base address of the SDADC instance.
 * @param u8Channel the channel number for which the CFR value is to be set.
 * @param u32Value the value to be set in the CFR register.
 */
LOCAL_INLINE void SDADC_HWA_SetCFRn(const SDADC_Type *const pSdadc, uint8_t u8Channel, uint32_t u32Value)
{
    SDADC_CHANNELCFGREG(pSdadc)[u8Channel].CFR = u32Value;
}

/**
 * @brief Get the value of the Channel Bias Register (CBR) for a specified channel.
 *
 * This function retrieves the value of the Channel Bias Register (CBR) for a given channel
 * in the SDADC instance.
 *
 * @param pSdadc the base address of the SDADC instance.
 * @param u8Channel the channel number for which the CBR value is to be retrieved.
 *
 * @return uint32_t the value of the CBR for the specified channel.
 */
LOCAL_INLINE uint32_t SDADC_HWA_GetCBRn(const SDADC_Type *const pSdadc, uint8_t u8Channel)
{
    return SDADC_CHANNELCFGREG(pSdadc)[u8Channel].CBR;
}

/**
 * @brief Set the value of the Channel Bias Register (CBR) for a specified channel.
 *
 * This function sets the value of the Channel Bias Register (CBR) for a given channel
 * in the SDADC instance.
 *
 * @param pSdadc the base address of the SDADC instance.
 * @param u8Channel the channel number for which the CBR value is to be set.
 * @param u32Value the value to be set in the CBR register.
 */
LOCAL_INLINE void SDADC_HWA_SetCBRn(const SDADC_Type *const pSdadc, uint8_t u8Channel, uint32_t u32Value)
{
    SDADC_CHANNELCFGREG(pSdadc)[u8Channel].CBR = u32Value;
}

/**
 * @brief Get the value of the Channel Low Limit Register (CLLMT) for a specified channel.
 *
 * This function retrieves the value of the Channel Low Limit Register (CLLMT) for a given channel
 * in the SDADC instance.
 *
 * @param pSdadc the base address of the SDADC instance.
 * @param u8Channel the channel number for which the CLLMT value is to be retrieved.
 *
 * @return uint32_t the value of the CLLMT for the specified channel.
 */
LOCAL_INLINE uint32_t SDADC_HWA_GetCLLMTn(const SDADC_Type *const pSdadc, uint8_t u8Channel)
{
    return SDADC_CHANNELCFGREG(pSdadc)[u8Channel].CLLMT;
}

/**
 * @brief Set the value of the Channel Low Limit Register (CLLMT) for a specified channel.
 *
 * This function sets the value of the Channel Low Limit Register (CLLMT) for a given channel
 * in the SDADC instance.
 *
 * @param pSdadc the base address of the SDADC instance.
 * @param u8Channel the channel number for which the CLLMT value is to be set.
 * @param u32Value the value to be set in the CLLMT register.
 */
LOCAL_INLINE void SDADC_HWA_SetCLLMTn(const SDADC_Type *const pSdadc, uint8_t u8Channel, uint32_t u32Value)
{
    SDADC_CHANNELCFGREG(pSdadc)[u8Channel].CLLMT = u32Value;
}

/**
 * @brief Get the value of the Channel High Limit Register (CHLMT) for a specified channel.
 *
 * This function retrieves the value of the Channel High Limit Register (CHLMT) for a given channel
 * in the SDADC instance.
 *
 * @param pSdadc the base address of the SDADC instance.
 * @param u8Channel the channel number for which the CHLMT value is to be retrieved.
 *
 * @return uint32_t the value of the CHLMT for the specified channel.
 */
LOCAL_INLINE uint32_t SDADC_HWA_GetCHLMTn(const SDADC_Type *const pSdadc, uint8_t u8Channel)
{
    return SDADC_CHANNELCFGREG(pSdadc)[u8Channel].CHLMT;
}

/**
 * @brief Set the value of the Channel High Limit Register (CHLMT) for a specified channel.
 *
 * This function sets the value of the Channel High Limit Register (CHLMT) for a given channel
 * in the SDADC instance.
 *
 * @param pSdadc the base address of the SDADC instance.
 * @param u8Channel the channel number for which the CHLMT value is to be set.
 * @param u32Value the value to be set in the CHLMT register.
 */
LOCAL_INLINE void SDADC_HWA_SetCHLMTn(const SDADC_Type *const pSdadc, uint8_t u8Channel, uint32_t u32Value)
{
    SDADC_CHANNELCFGREG(pSdadc)[u8Channel].CHLMT = u32Value;
}

/**
 * @brief Get the value of the Channel Result Data Register (CRDATA) for a specified channel.
 *
 * This function retrieves the value of the Channel Result Data Register (CRDATA) for a given channel
 * in the SDADC instance.
 *
 * @param pSdadc the base address of the SDADC instance.
 * @param u8Channel the channel number for which the CRDATA value is to be retrieved.
 *
 * @return uint32_t the value of the CRDATA for the specified channel.
 */
LOCAL_INLINE uint32_t SDADC_HWA_GetCRDATAn(const SDADC_Type *const pSdadc, uint8_t u8Channel)
{
    return SDADC_CHANNELCFGREG(pSdadc)[u8Channel].CRDATA;
}

/**
 * @brief Get the value of the Channel Multi Purpose Data Register (CMPDATA) for a specified channel.
 *
 * This function retrieves the value of the Channel Multi Purpose Data Register (CMPDATA) for a given channel
 * in the SDADC instance.
 *
 * @param pSdadc the base address of the SDADC instance.
 * @param u8Channel the channel number for which the CMPDATA value is to be retrieved.
 *
 * @return uint32_t the value of the CMPDATA for the specified channel.
 */
LOCAL_INLINE uint32_t SDADC_HWA_GetCMPDATAn(const SDADC_Type *const pSdadc, uint8_t u8Channel)
{
    return SDADC_CHANNELCFGREG(pSdadc)[u8Channel].CMPDATA;
}

/**
 * @brief Get the value of the Channel Data Rate Register (CDR) for a specified channel.
 *
 * This function retrieves the value of the Channel Data Rate Register (CDR) for a given channel
 * in the SDADC instance.
 *
 * @param pSdadc the base address of the SDADC instance.
 * @param u8Channel the channel number for which the CDR value is to be retrieved.
 *
 * @return uint32_t the value of the CDR for the specified channel.
 */
LOCAL_INLINE uint32_t SDADC_HWA_GetCDRn(const SDADC_Type *const pSdadc, uint8_t u8Channel)
{
    return SDADC_CHANNELCFGREG(pSdadc)[u8Channel].CDR;
}

/**
 * @brief Set the value of the Channel Data Rate Register (CDR) for a specified channel.
 *
 * This function sets the value of the Channel Data Rate Register (CDR) for a given channel
 * in the SDADC instance.
 *
 * @param pSdadc the base address of the SDADC instance.
 * @param u8Channel the channel number for which the CDR value is to be set.
 * @param u32Value the value to be set in the CDR register.
 */
LOCAL_INLINE void SDADC_HWA_SetCDRn(const SDADC_Type *const pSdadc, uint8_t u8Channel, uint32_t u32Value)
{
    SDADC_CHANNELCFGREG(pSdadc)[u8Channel].CDR = u32Value;
}

/**
 * @brief Set the value of NISR.
 * @param pSdadc the base address of the SDADC instance.
 * @param u32Value Set Value.
 */
LOCAL_INLINE void SDADC_HWA_SetNISR(SDADC_Type *const pSdadc, uint32 u32Value)
{
    pSdadc->NISR = u32Value & SDADC_NISR_MASK;
}

/**
 * @brief Set the value of ABNISR0.
 * @param pSdadc the base address of the SDADC instance.
 * @param u32Value Set Value.
 */
LOCAL_INLINE void SDADC_HWA_SetABNISR0(SDADC_Type *const pSdadc, uint32 u32Value)
{
    pSdadc->ABNISR0 = u32Value & SDADC_ABNISR0_MASK;
}

/**
 * @brief Set the value of ABNISR1.
 * @param pSdadc the base address of the SDADC instance.
 * @param u32Value Set Value.
 */
LOCAL_INLINE void SDADC_HWA_SetABNISR1(SDADC_Type *const pSdadc, uint32 u32Value)
{
    pSdadc->ABNISR1 = u32Value & SDADC_ABNISR1_MASK;
}

/**
 * @brief Set the value of EXTIS.
 * @param pSdadc the base address of the SDADC instance.
 * @param u32Value Set Value.
 */
LOCAL_INLINE void SDADC_HWA_SetEXTIS(SDADC_Type *const pSdadc, uint32 u32Value)
{
    pSdadc->EXTIS = u32Value & SDADC_EXTIS_MASK;
}


/**
 * @brief Set the value of DMA_EN.
 * Channel Enable
 * 0b - The channel dma is disabled.
 * 0b - The channel dma is enabled.
 * @param pSdadc the base address of the SDADC instance.
 * @param u8Channel SDADC Channel.
 * @param u8Enable SDADC Channel Channel Enable.
 * @return uint32_t the value of DMA_EN.
 */
LOCAL_INLINE void SDADC_HWA_SetDMA_EN(const SDADC_Type *const pSdadc, uint8_t u8Channel, uint8_t u8Enable)
{
    SDADC_CHANNELCFGREG(pSdadc)[u8Channel].CCR = (SDADC_CHANNELCFGREG(pSdadc)[u8Channel].CCR & ~SDADC_CCR_DMA_EN_MASK) | SDADC_CCR_DMA_EN(u8Enable);
}


/** @}*/

#endif /* #if SDADC_INSTANCE_COUNT > 0U */

#endif /* _HWA_SDADC_H_ */
