/**
 * @file HwA_ldi.h
 * @author Flagchip
 * @brief LDI hardware access layer
 * @version 2.0.0
 * @date 2025-06-18
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
   *   0.1.0      2025-06-18     Flagchip0121   N/A         Init version
   ******************************************************************************** */

#ifndef _HWA_LDI_H_
#define _HWA_LDI_H_

#include "device_header.h"

#if LDI_INSTANCE_COUNT > 0U


#define LDI_SET_BIT(REG, BIT)     ((REG) |= (BIT))

#define LDI_CLEAR_BIT(REG, BIT)   ((REG) &= ~(BIT))

#define LDI_READ_BIT(REG, BIT)    ((REG) & (BIT))

#define LDI_CLEAR_REG(REG)        ((REG) = (0x0U))

#define LDI_WRITE_REG(REG, VAL)   ((REG) = (VAL))

#define LDI_READ_REG(REG)         ((REG))

#define LDI_MODIFY_REG(REG, CLEARMASK, SETMASK)  LDI_WRITE_REG((REG), (((LDI_READ_REG(REG)) & (~(CLEARMASK))) | (SETMASK)))

/**
 * @defgroup HwA_ldi HwA_ldi
 * @ingroup module_driver_ldi
 * @{
 */

/********* Local inline function ************/

/**
 * @brief Ldi clear all FIFO
 *
 * @param pLdi Ldi instance
 */
LOCAL_INLINE void LDI_HWA_ClearFIFO(LDI_Type *pLdi)
{
    LDI_SET_BIT(pLdi->CTRL, LDI_CTRL_CLR_FIFO3_MASK|LDI_CTRL_CLR_FIFO2_MASK|LDI_CTRL_CLR_FIFO1_MASK|LDI_CTRL_CLR_FIFO0_MASK);
}

/**
 * @brief Ldi clear all FIFO Status
 *
 * @param pLdi Ldi instance
 */
LOCAL_INLINE void LDI_HWA_ClearFIFOStatus(LDI_Type *pLdi)
{
    LDI_SET_BIT(pLdi->FSR, LDI_FSR_FF3_MASK|LDI_FSR_FU3_MASK|LDI_FSR_FF2_MASK|LDI_FSR_FU2_MASK|
                           LDI_FSR_FF1_MASK|LDI_FSR_FU1_MASK|LDI_FSR_FF0_MASK|LDI_FSR_FU0_MASK);
}

/**
 * @brief Ldi Set DDR Mode
 *
 * @param pLdi Ldi instance
 */
LOCAL_INLINE void LDI_HWA_SetDdrMode(LDI_Type *pLdi)
{
    LDI_CLEAR_BIT(pLdi->CTRL, LDI_CTRL_DDR_MASK);
}

/**
 * @brief Ldi Set SDR Mode
 *
 * @param pLdi Ldi instance
 */
LOCAL_INLINE void LDI_HWA_SetSdrMode(LDI_Type *pLdi)
{
    LDI_CLEAR_BIT(pLdi->CTRL, LDI_CTRL_DDR_MASK);
}

/**
 * @brief Ldi Set DDR delay
 *
 * @param pLdi Ldi instance
 */
LOCAL_INLINE void LDI_HWA_SetDdrDelay(LDI_Type *pLdi)
{
    LDI_SET_BIT(pLdi->CTRL, LDI_CTRL_DDRT_MASK);
}

/**
 * @brief Ldi Set SDR delay
 *
 * @param pLdi Ldi instance
 */
LOCAL_INLINE void LDI_HWA_SetSdrDelay(LDI_Type *pLdi)
{
    LDI_SET_BIT(pLdi->CTRL, LDI_CTRL_DCLK_INV_MASK);
}

/**
 * @brief Ldi config Ctrl register
 *
 * @param pLdi Ldi instance
 * @param u32LdiCtrlReg Register value
 */
LOCAL_INLINE void LDI_HWA_CfgCtrl(LDI_Type *pLdi, uint32_t u32LdiCtrlReg)
{
    LDI_WRITE_REG(pLdi->CTRL, u32LdiCtrlReg);
}

/**
 * @brief Ldi config clock Ctrl register
 *
 * @param pLdi Ldi instance
 * @param u32LdiClkCtrlReg Register value
 */
LOCAL_INLINE void LDI_HWA_CfgClkCtrl(LDI_Type *pLdi, uint32_t u32LdiClkCtrlReg)
{
    LDI_WRITE_REG(pLdi->CTRL, u32LdiClkCtrlReg);
}

/**
 * @brief Ldi enable function clock reference
 *
 * @param pLdi Ldi instance
 */
LOCAL_INLINE void LDI_HWA_EnFuncClkRef(LDI_Type *pLdi)
{
    LDI_SET_BIT(pLdi->CLK_CTRL, LDI_CLK_CTRL_FCRE_MASK);
}

/**
 * @brief Ldi enable clock
 *
 * @param pLdi Ldi instance
 */
LOCAL_INLINE void LDI_HWA_EnableClk(LDI_Type *pLdi)
{
    LDI_SET_BIT(pLdi->CLK_CTRL, LDI_CLK_CTRL_FCE_MASK);
}

/**
 * @brief Ldi set DDR/SDR Prediv
 *
 * @param pLdi Ldi instance
 * @param u32DclkDivValue Dclk prediv
 */
LOCAL_INLINE void LDI_HWA_DdrSdrPrediv(LDI_Type *pLdi, uint32_t u32DclkDivValue)
{
    LDI_SET_BIT(pLdi->CLK_CTRL, u32DclkDivValue);
}

/**
 * @brief Ldi set gclk Prediv
 *
 * @param pLdi Ldi instance
 * @param u32DclkDivValue Gclk prediv
 */
LOCAL_INLINE void LDI_HWA_GCLKPrediv(LDI_Type *pLdi, uint32_t u32GclkDivValue)
{
    LDI_SET_BIT(pLdi->CLK_CTRL, LDI_CLK_CTRL_GCLKDIV(u32GclkDivValue));
}

/**
 * @brief Ldi set gclk source
 *
 * @param pLdi Ldi instance
 * @param u32GclkSrc Gclk source
 */
LOCAL_INLINE void LDI_HWA_GCLKSrc(LDI_Type *pLdi, uint32_t u32GclkSrc)
{
    LDI_SET_BIT(pLdi->CLK_CTRL, LDI_CLK_CTRL_GCLKMUX(u32GclkSrc));
}

/**
 * @brief Ldi set Spread Spectrum Mode
 *
 * @param pLdi Ldi instance
 * @param u32SpreadMode Spread Spectrum Mode
 */
LOCAL_INLINE void LDI_HWA_SetSpreadMode(LDI_Type *pLdi, uint32_t u32SpreadMode)
{
    LDI_SET_BIT(pLdi->CLK_CTRL, LDI_CLK_CTRL_SSM(u32SpreadMode));
}

/**
 * @brief Ldi set Spread Spectrum Direction
 *
 * @param pLdi Ldi instance
 * @param u32SpreadDirction Spread direction Mode
 */
LOCAL_INLINE void LDI_HWA_SetSpreadDirection(LDI_Type *pLdi, uint32_t u32SpreadDirction)
{
    LDI_SET_BIT(pLdi->CLK_CTRL, LDI_CLK_CTRL_SSD(u32SpreadDirction));
}

/**
 * @brief Ldi set clock config
 *
 * @param pLdi Ldi instance
 * @param u32Clkcfg Spread direction Mode
 */
LOCAL_INLINE void LDI_HWA_SetClkcfg(LDI_Type *pLdi, uint32_t u32Clkcfg)
{
    LDI_SET_BIT(pLdi->CLK_CTRL, u32Clkcfg);
}

/**
 * @brief Ldi Enable Fut
 *
 * @param pLdi Ldi instance
 */
LOCAL_INLINE void LDI_HWA_EnableFut(LDI_Type *pLdi)
{
    LDI_SET_BIT(pLdi->CLK_CTRL, LDI_CLK_CTRL_FUT_MASK);
}

/**
 * @brief Ldi config px ctrl register
 *
 * @param pLdi Ldi instance
 * @param u32LdiPxCtrlReg Px ctlr register value
 */
LOCAL_INLINE void LDI_HWA_CfgPxCtrl(LDI_Type *pLdi, uint32_t u32LdiPxCtrlReg)
{
    LDI_WRITE_REG(pLdi->PX_CTRL, u32LdiPxCtrlReg);
}

/**
 * @brief Ldi config px ctrl2 register
 *
 * @param pLdi Ldi instance
 * @param u32LdiPxCtrl2Reg Px ctlr register value
 */
LOCAL_INLINE void LDI_HWA_CfgPxCtrl2(LDI_Type *pLdi, uint32_t u32LdiPxCtrl2Reg)
{
    LDI_WRITE_REG(pLdi->PX_CTRL2, u32LdiPxCtrl2Reg);
}

/**
 * @brief Ldi config px status register
 *
 * @param pLdi Ldi instance
 * @param u32LdiPxStatusReg Px ctlr register value
 */
LOCAL_INLINE void LDI_HWA_CfgPxStatus(LDI_Type *pLdi, uint32_t u32LdiPxStatusReg)
{
    LDI_WRITE_REG(pLdi->PX_CTRL2, u32LdiPxStatusReg);
}

/**
 * @brief Ldi claer Tr size
 *
 * @param pLdi Ldi instance
 */
LOCAL_INLINE void LDI_HWA_ClearTrSize(LDI_Type *pLdi)
{
    LDI_SET_BIT(pLdi->PX_STATUS, LDI_PX_STATUS_TR_SIZE_MASK);
}

/**
 * @brief Ldi Enable channel
 *
 * @param pLdi Ldi instance
 */
LOCAL_INLINE void LDI_HWA_EnableChannel(LDI_Type *pLdi, uint32_t u32PinsMaskValue)
{
    LDI_SET_BIT(pLdi->PX_CTRL2, LDI_PX_CTRL2_PINS(u32PinsMaskValue));
}

/**
 * @brief Ldi enable interrupt
 *
 * @param pLdi Ldi instance
 */
LOCAL_INLINE void LDI_HWA_EnableInterrupt(LDI_Type *pLdi)
{
    LDI_WRITE_REG(pLdi->IRQ_EN, LDI_IRQ_EN_PX_UPDT_MASK);
}

/**
 * @brief Ldi disable interrupt
 *
 * @param pLdi Ldi instance
 */
LOCAL_INLINE void LDI_HWA_DisableInterrupt(LDI_Type *pLdi)
{
	LDI_CLEAR_BIT(pLdi->IRQ_EN, LDI_IRQ_EN_PX_UPDT_MASK | LDI_IRQ_EN_PX_DISP_MASK);
}

/**
 * @brief Ldi clear interrupt flag
 *
 * @param pLdi Ldi instance
 */
LOCAL_INLINE void LDI_HWA_ClearInterruptFlag(LDI_Type *pLdi)
{
    LDI_WRITE_REG(pLdi->IRQ_ST, LDI_IRQ_EN_PX_UPDT_MASK | LDI_IRQ_EN_PX_DISP_MASK);
}

/**
 * @brief Ldi config pixel display row configuration register
 *
 * @param pLdi Ldi instance
 * @param u32PxdRcfgReg Register value
 */
LOCAL_INLINE void LDI_HWA_CfgPxdRcfg(LDI_Type *pLdi, uint32_t u32PxdRcfgReg)
{
    LDI_WRITE_REG(pLdi->PXD_RCFG, u32PxdRcfgReg);
}

/**
 * @brief Ldi config pixel display gclk configuration register
 *
 * @param pLdi Ldi instance
 * @param u32PxdGcfgReg Register value
 */
LOCAL_INLINE void LDI_HWA_CfgPxdGcfg(LDI_Type *pLdi, uint32_t u32PxdGcfgReg)
{
    LDI_WRITE_REG(pLdi->PXD_GCFG, u32PxdGcfgReg);
}

/**
 * @brief Ldi config pixel display SOE configuration register
 *
 * @param pLdi Ldi instance
 * @param u32PxdScfgReg Register value
 */
LOCAL_INLINE void LDI_HWA_CfgPxdScfg(LDI_Type *pLdi, uint32_t u32PxdScfgReg)
{
    LDI_WRITE_REG(pLdi->PXD_SCFG, u32PxdScfgReg);
}

/**
 * @brief Ldi config pixel display DOE configuration register
 *
 * @param pLdi Ldi instance
 * @param u32PxdDcfgReg Register value
 */
LOCAL_INLINE void LDI_HWA_CfgPxdDcfg(LDI_Type *pLdi, uint32_t u32PxdDcfgReg)
{
    LDI_WRITE_REG(pLdi->PXD_DCFG, u32PxdDcfgReg);
}

/**
 * @brief Ldi config pixel display SDI configuration register
 *
 * @param pLdi Ldi instance
 * @param u32PxdIcfgReg Register value
 */
LOCAL_INLINE void LDI_HWA_CfgPxdIcfg(LDI_Type *pLdi, uint32_t u32PxdIcfgReg)
{
    LDI_WRITE_REG(pLdi->PXD_ICFG, u32PxdIcfgReg);
}

/**
 * @brief Ldi config Fcr0 register
 *
 * @param pLdi Ldi instance
 * @param u32Fcr0Reg Register value
 */
LOCAL_INLINE void LDI_HWA_CfgFcr0(LDI_Type *pLdi, uint32_t u32Fcr0Reg)
{
    LDI_WRITE_REG(pLdi->FCR0, u32Fcr0Reg);
}

/**
 * @brief Ldi config Fcr1 register
 *
 * @param pLdi Ldi instance
 * @param u32Fcr1Reg Register value
 */
LOCAL_INLINE void LDI_HWA_CfgFcr1(LDI_Type *pLdi, uint32_t u32Fcr1Reg)
{
    LDI_WRITE_REG(pLdi->FCR1, u32Fcr1Reg);
}

/**
 * @brief Ldi config Fcr2 register
 *
 * @param pLdi Ldi instance
 * @param u32Fcr2Reg Register value
 */
LOCAL_INLINE void LDI_HWA_CfgFcr2(LDI_Type *pLdi, uint32_t u32Fcr2Reg)
{
    LDI_WRITE_REG(pLdi->FCR2, u32Fcr2Reg);
}

/**
 * @brief Ldi config Fcr3 register
 *
 * @param pLdi Ldi instance
 * @param u32Fcr3Reg Register value
 */
LOCAL_INLINE void LDI_HWA_CfgFcr3(LDI_Type *pLdi, uint32_t u32Fcr3Reg)
{
    LDI_WRITE_REG(pLdi->FCR3, u32Fcr3Reg);
}


/**
 * @brief Ldi set Tr size
 *
 * @param pLdi Ldi instance
 * @param u32TrSize Tr size
 */
LOCAL_INLINE void LDI_HWA_SetTrSize(LDI_Type *pLdi, uint32_t u32TrSize)
{
	LDI_WRITE_REG(pLdi->PX_STATUS, LDI_PX_STATUS_TR_SIZE(u32TrSize));
}

/**
 * @brief Ldi start update
 *
 * @param pLdi Ldi instance
 */
LOCAL_INLINE void LDI_HWA_UpdateStart(LDI_Type *pLdi)
{
    LDI_SET_BIT(pLdi->PX_STATUS, LDI_PX_STATUS_UP_START_MASK);
}

/**
 * @brief Ldi get update flag
 *
 * @param pLdi Ldi instance
 */
LOCAL_INLINE uint32_t LDI_HWA_GetUpdateFlag(LDI_Type *pLdi)
{
    return(LDI_READ_BIT(pLdi->IRQ_ST, LDI_IRQ_ST_PX_UPDT_MASK) >> LDI_IRQ_ST_PX_UPDT_SHIFT);
}

/**
 * @brief Ldi get fifo 0 filling level
 *
 * @param pLdi Ldi instance
 */
LOCAL_INLINE uint32_t LDI_HWA_GetCh0FifoFillLevel(LDI_Type *pLdi)
{
    return (LDI_READ_BIT(pLdi->FCR0, LDI_FCR0_FL_MASK ) >> LDI_FCR0_FL_SHIFT);
}

/**
 * @brief Ldi enable dma mode
 *
 * @param pLdi Ldi instance
 */
LOCAL_INLINE void LDI_HWA_EnableDma(LDI_Type *pLdi)
{
    LDI_SET_BIT(pLdi->CTRL, LDI_CTRL_EDME_MASK );
}

/**
 * @brief Ldi disable dma mode
 *
 * @param pLdi Ldi instance
 */
LOCAL_INLINE void LDI_HWA_DisableDma(LDI_Type *pLdi)
{
    LDI_CLEAR_BIT(pLdi->CTRL, LDI_CTRL_EDME_MASK );
}

/**
 * @brief Ldi config display
 *
 * @param pLdi Ldi instance
 */
LOCAL_INLINE void LDI_HWA_CfgDisplay(LDI_Type *pLdi)
{
    LDI_SET_BIT(pLdi->PX_STATUS, LDI_PX_STATUS_DISP_START_MASK);
}

/** @}*/

#endif

#endif /* #ifndef _HWA_LDI_H_ */
