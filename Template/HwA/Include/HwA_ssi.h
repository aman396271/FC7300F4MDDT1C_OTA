/**
 * @file HwA_ssi.h
 * @author flagchip
 * @brief ssi hardware access layer
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
 *   2.0.0      2023-12-12     Flagchip054   N/A          First version for FC7300
 ******************************************************************************** */

#ifndef _HWA_SSI_H_
#define _HWA_SSI_H_
#include "device_header.h"

#if SSI_INSTANCE_COUNT > 0U

/**
 * @brief Enable Function Clock
 *
 * @param SSI instance value
 */
LOCAL_INLINE void SSI_HWA_Func_Enable(SSI_Type *pSsi)
{
    pSsi->GCR |= SSI_GCR_FUNC_EN_MASK;
}

/**
 * @brief Disable Function Clock
 *
 * @param SSI Pointer to the SSI_Type structure representing the SSI peripheral instance
 */
LOCAL_INLINE void SSI_HWA_Func_Disable(SSI_Type *pSsi)
{
    pSsi->GCR &= ~SSI_GCR_FUNC_EN_MASK;
}

/**
 * @brief Set Function Clock Divider
 *
 * @param SSI Pointer to the SSI_Type structure representing the SSI peripheral instance
 * @param u32Value devider
 */
LOCAL_INLINE void SSI_HWA_SetFuncDev(SSI_Type *pSsi, uint32_t u32Value)
{
    pSsi->GCR = (pSsi->GCR & ~SSI_GCR_FUNC_DIV_MASK) | SSI_GCR_FUNC_DIV(u32Value);
}

/**
 * @brief Get the value of the Global Status Register (GSR)
 *
 * This function reads the value of the Global Status Register (GSR) for the specified SSI peripheral.
 *
 * @param pSsi Pointer to the SSI_Type structure representing the SSI peripheral instance
 * @return The value of the Global Status Register (GSR)
 */
LOCAL_INLINE uint32_t SSI_HWA_GetGlobalStatus(SSI_Type *pSsi)
{
    return pSsi->GSR;
}

/**
 * @brief Get the value of the Global Error Status
 *
 * This function reads the value of the Global Error Status for the specified SSI peripheral.
 *
 * @param pSsi Pointer to the SSI_Type structure representing the SSI peripheral instance
 * @return The value of the Global Error Status
 */
LOCAL_INLINE uint32_t SSI_HWA_GetGlobalErrStatus(SSI_Type *pSsi)
{
	uint32_t u32ErrStatus;
	u32ErrStatus = pSsi->GSR & ~SSI_GSR_SPC_VLD_MASK;
    return u32ErrStatus;
}

/**
 * @brief Get the value of the SpcVld Status
 *
 * This function reads the value of the SpcVld Status for the specified SSI peripheral.
 *
 * @param pSsi Pointer to the SSI_Type structure representing the SSI peripheral instance
 * @return The value of the SpcVld Status
 */
LOCAL_INLINE uint32_t SSI_HWA_GetSpcVldStatus(SSI_Type *pSsi)
{
    return ((pSsi->GSR & SSI_GSR_SPC_VLD_MASK) >> SSI_GSR_SPC_VLD_SHIFT);
}

/**
 * @brief Get the value of the Wheel Stop Status
 *
 * This function reads the value of the Wheel Stop Status for the specified SSI peripheral.
 *
 * @param pSsi Pointer to the SSI_Type structure representing the SSI peripheral instance
 * @return The value of the SpcVld
 */
LOCAL_INLINE uint32_t SSI_HWA_GetWhlStopStatus(SSI_Type *pSsi)
{
    return ((pSsi->GSR & SSI_GSR_WHL_STOP_MASK) >> SSI_GSR_WHL_STOP_WIDTH);
}

/**
 * @brief Get the value of the Sensor Protocol Counter Timeout Status
 *
 * This function reads the value of the SPC Timeout Status for the specified SSI peripheral.
 *
 * @param pSsi Pointer to the SSI_Type structure representing the SSI peripheral instance
 * @return The value of the SpcTimeout Status
 */
LOCAL_INLINE uint32_t SSI_HWA_GetSpcTimeoutStatus(SSI_Type *pSsi)
{
    return ((pSsi->GSR & SSI_GSR_SPC_TIMEOUT_MASK) >> SSI_GSR_SPC_TIMEOUT_SHIFT);
}

/**
 * @brief Get the value of SPC Range Status
 *
 * This function reads the value of the SPC Range Status for the specified SSI peripheral.
 *
 * @param pSsi Pointer to the SSI_Type structure representing the SSI peripheral instance
 * @return The value of the SPC Range Status
 */
LOCAL_INLINE uint32_t SSI_HWA_GetSpcRangeErrStatus(SSI_Type *pSsi)
{
    return ((pSsi->GSR & SSI_GSR_SPC_RANGE_ERR_MASK) >> SSI_GSR_SPC_RANGE_ERR_SHIFT);
}

/**
 * @brief Get the value of Protocol Decoder Status
 *
 * This function reads the value of the Protocol Decoder Status for the specified SSI peripheral.
 *
 * @param pSsi Pointer to the SSI_Type structure representing the SSI peripheral instance
 * @return The value of the Protocol Decoder Status
 */
LOCAL_INLINE uint32_t SSI_HWA_GetDecodeErrStatus(SSI_Type *pSsi)
{
    return ((pSsi->GSR & SSI_GSR_DECODE_ERR_MASK) >> SSI_GSR_DECODE_ERR_SHIFT);
}

/**
 * @brief Get the value of Protocol Interval Status
 *
 * This function reads the value of the Protocol Interval Status for the specified SSI peripheral.
 *
 * @param pSsi Pointer to the SSI_Type structure representing the SSI peripheral instance
 * @return The value of the Protocol Interval Status
 */
LOCAL_INLINE uint32_t SSI_HWA_GetIntervalErrStatus(SSI_Type *pSsi)
{
    return ((pSsi->GSR & SSI_GSR_INTERVAL_ERR_MASK) >> SSI_GSR_INTERVAL_ERR_SHIFT);
}

/**
 * @brief Get the value of Pulse Width Status
 *
 * This function reads the value of the Pulse Width Status for the specified SSI peripheral.
 *
 * @param pSsi Pointer to the SSI_Type structure representing the SSI peripheral instance
 * @return The value of the Pulse Width Status
 */
LOCAL_INLINE uint32_t SSI_HWA_GetPulseWdhErrStatus(SSI_Type *pSsi)
{
    return ((pSsi->GSR & SSI_GSR_PULSE_WIDTH_ERR_MASK) >> SSI_GSR_PULSE_WIDTH_ERR_SHIFT);
}

/**
 * @brief Get the value of Protocol Status
 *
 * This function reads the value of the Protocol Status for the specified SSI peripheral.
 *
 * @param pSsi Pointer to the SSI_Type structure representing the SSI peripheral instance
 * @return The value of Protocol Status
 */
LOCAL_INLINE uint32_t SSI_HWA_GetProtErrStatus(SSI_Type *pSsi)
{
    return ((pSsi->GSR & SSI_GSR_PROTOC_ERR_MASK) >> SSI_GSR_PROTOC_ERR_SHIFT);
}

/**
 * @brief Set the Lower Part of the Global Counter Window Register (GCWLR)
 *
 * This function sets the lower part of the Global Counter Window Register (GCWLR) for the specified
 * SSI peripheral.
 *
 * @param pSsi Pointer to the SSI_Type structure representing the SSI peripheral instance
 * @param u32Value The value to set in the lower part of the GCWLR register
 */
LOCAL_INLINE void SSI_HWA_SetGlobalCounterWindowsL(SSI_Type *pSsi, uint32_t u32Value)
{
    pSsi->GCWLR = (u32Value & SSI_GCWLR_WIN_L_MASK);
}

/**
 * @brief Set the High Part of the Global Counter Window Register (GCWHR)
 *
 * This function sets the High part of the Global Counter Window Register (GCWHR) for the specified
 * SSI peripheral.
 *
 * @param pSsi Pointer to the SSI_Type structure representing the SSI peripheral instance
 * @param u32Value The value to set in the High part of the GCWHR register
 */
LOCAL_INLINE void SSI_HWA_SetGlobalCounterWindowsH(SSI_Type *pSsi, uint32_t u32Value)
{
    pSsi->GCWHR = (u32Value & SSI_GCWHR_WIN_H_MASK);
}

/**
 * @brief Set the Global Protocol Configuration Register (GPCR)
 *
 * This function sets the Global Protocol Configuration Register (GPCR) for the specified SSI
 * peripheral.
 *
 * @param pSsi Pointer to the SSI_Type structure representing the SSI peripheral instance
 * @param u32Value The value to set in the GPCR register
 */
LOCAL_INLINE void SSI_HWA_SetGlobalProCfg(SSI_Type *pSsi, uint32_t u32Value)
{
    pSsi->GPCR = u32Value;
}

/**
 * @brief Set the AK Interrupt Error Threshold Configuration
 *
 * This function sets the AK Interrupt Error Threshold configuration in the Global Protocol
 * Configuration Register (GPCR) for the specified SSI peripheral.
 *
 * @param pSsi Pointer to the SSI_Type structure representing the SSI peripheral instance
 * @param u32Value The value to set for the AK Interrupt Error Threshold
 */
LOCAL_INLINE void SSI_HWA_SetAKIntErrThrCfg(SSI_Type *pSsi, uint32_t u32Value)
{
    pSsi->GPCR = (pSsi->GPCR &= ~SSI_GPCR_AK_IETH_MASK) | SSI_GPCR_AK_IETH(u32Value);
}

/**
 * @brief Set the AK Period Error Threshold Configuration
 *
 * This function sets the AK Period Error Threshold configuration in the Global Protocol
 * Configuration Register (GPCR) for the specified SSI peripheral.
 *
 * @param pSsi Pointer to the SSI_Type structure representing the SSI peripheral instance
 * @param u32Value The value to set for the AK Period Error Threshold
 */
LOCAL_INLINE void SSI_HWA_SetAKPerErrThrCfg(SSI_Type *pSsi, uint32_t u32Value)
{
    pSsi->GPCR = (pSsi->GPCR &= ~SSI_GPCR_AK_PETH_MASK) | SSI_GPCR_AK_PETH(u32Value);
}

/**
 * @brief Set the PWM Period Error Threshold Configuration
 *
 * This function sets the PWM Period Error Threshold configuration in the Global Protocol
 * Configuration Register (GPCR) for the specified SSI peripheral.
 *
 * @param pSsi Pointer to the SSI_Type structure representing the SSI peripheral instance
 * @param u32Value The value to set for the PWM Period Error Threshold
 */
LOCAL_INLINE void SSI_HWA_SetPwmPerErrThrCfg(SSI_Type *pSsi, uint32_t u32Value)
{
    pSsi->GPCR = (pSsi->GPCR &= ~SSI_GPCR_PWM_PETH_MASK) | SSI_GPCR_PWM_PETH(u32Value);
}

/**
 * @brief Set the PWM Reference Pulse Width
 *
 * This function sets the PWM Reference Pulse Width configuration in the Global Protocol
 * Configuration Register (GPCR) for the specified SSI peripheral.
 *
 * @param pSsi Pointer to the SSI_Type structure representing the SSI peripheral instance
 * @param u32Value The value to set for the PWM Reference Pulse Width
 */
LOCAL_INLINE void SSI_HWA_SetPwmRefPulseWidth(SSI_Type *pSsi, uint32_t u32Value)
{
    pSsi->GPCR = (pSsi->GPCR &= ~SSI_GPCR_REF_WIDTH_MASK) | SSI_GPCR_REF_WIDTH(u32Value);
}

/**
 * @brief Set the Sub-instance Control Register
 *
 * This function sets the Sub-instance Control Register (ICR) for a specified sub-instance index
 * in the SSI peripheral.
 *
 * @param pSsi Pointer to the SSI_Type structure representing the SSI peripheral instance
 * @param u8IcrIdx The index of the sub-instance control register to configure
 * @param u32Value The value to set for the Sub-instance Control Register
 */
LOCAL_INLINE void SSI_HWA_SetSubinsCtr(SSI_Type *pSsi, uint8_t u8IcrIdx, uint32_t u32Value)
{
    pSsi->SUB_INS[u8IcrIdx].ICR = u32Value;
}

/**
 * @brief Enable the Sub-instance
 *
 * This function enables the sub-instance by setting the enable bit in the Sub-instance Control
 * Register (ICR) for a specified sub-instance index in the SSI peripheral.
 *
 * @param pSsi Pointer to the SSI_Type structure representing the SSI peripheral instance
 * @param u8IcrIdx The index of the sub-instance control register to enable
 */
LOCAL_INLINE void SSI_HWA_Subins_Enable(SSI_Type *pSsi, uint8_t u8IcrIdx)
{
    pSsi->SUB_INS[u8IcrIdx].ICR |= SSI_ICR_SSI_EN_MASK;
}

/**
 * @brief Disable the Sub-instance
 *
 * This function Disable the sub-instance by setting the enable bit in the Sub-instance Control
 * Register (ICR) for a specified sub-instance index in the SSI peripheral.
 *
 * @param pSsi Pointer to the SSI_Type structure representing the SSI peripheral instance
 * @param u8IcrIdx The index of the sub-instance control register to enable
 */
LOCAL_INLINE void SSI_HWA_Subins_Disable(SSI_Type *pSsi, uint8_t u8IcrIdx)
{
    pSsi->SUB_INS[u8IcrIdx].ICR &= ~SSI_ICR_SSI_EN_MASK;
}

/**
 * @brief Set the Sub-instance Channel Switch
 *
 * This function sets the channel switch configuration in the Sub-instance Control Register (ICR)
 * for a specified sub-instance index in the SSI peripheral.
 *
 * @param pSsi Pointer to the SSI_Type structure representing the SSI peripheral instance
 * @param u8IcrIdx The index of the sub-instance control register to configure
 * @param u32Value The value to set for the channel switch configuration
 */
LOCAL_INLINE void SSI_HWA_SetSubinsChlSwitch(SSI_Type *pSsi, uint8_t u8IcrIdx, uint32_t u32Value)
{
    uint32_t u32RegVal          = pSsi->SUB_INS[u8IcrIdx].ICR;
    pSsi->SUB_INS[u8IcrIdx].ICR = (u32RegVal & ~SSI_ICR_CHL_SW_MASK) | SSI_ICR_CHL_SW(u32Value);
}

/**
 * @brief Enable Window Range Check for Sub-instance
 *
 * This function enables the window range check feature in the Sub-instance Control Register (ICR)
 * for a specified sub-instance index in the SSI peripheral.
 *
 * @param pSsi Pointer to the SSI_Type structure representing the SSI peripheral instance
 * @param u8IcrIdx The index of the sub-instance control register to configure
 */
LOCAL_INLINE void SSI_HWA_SubinsWinRangChk_Enable(SSI_Type *pSsi, uint8_t u8IcrIdx)
{
    pSsi->SUB_INS[u8IcrIdx].ICR |= SSI_ICR_RANG_CHK_EN_MASK;
}

/**
 * @brief Disable Window Range Check for Sub-instance
 *
 * This function Disable the window range check feature in the Sub-instance Control Register (ICR)
 * for a specified sub-instance index in the SSI peripheral.
 *
 * @param pSsi Pointer to the SSI_Type structure representing the SSI peripheral instance
 * @param u8IcrIdx The index of the sub-instance control register to configure
 */
LOCAL_INLINE void SSI_HWA_SubinsWinRangChk_Disable(SSI_Type *pSsi, uint8_t u8IcrIdx)
{
    pSsi->SUB_INS[u8IcrIdx].ICR &= ~SSI_ICR_RANG_CHK_EN_MASK;
}

/**
 * @brief Set the Sub-instance Channel Selection
 *
 * This function sets the channel selection configuration in the Sub-instance Control Register (ICR)
 * for a specified sub-instance index in the SSI peripheral.
 *
 * @param pSsi Pointer to the SSI_Type structure representing the SSI peripheral instance
 * @param u8IcrIdx The index of the sub-instance control register to configure
 * @param u32Value The value to set for the channel selection configuration
 */
LOCAL_INLINE void SSI_HWA_SetSubinsChlSel(SSI_Type *pSsi, uint8_t u8IcrIdx, uint8_t u8Value)
{
    uint32_t u32RegVal          = pSsi->SUB_INS[u8IcrIdx].ICR;
    pSsi->SUB_INS[u8IcrIdx].ICR = (u32RegVal & ~SSI_ICR_CHL_SEL_MASK) | SSI_ICR_CHL_SEL(u8Value);
}

/**
 * @brief Set the Sub-instance Protocol Selection
 *
 * This function sets the Protocol selection configuration in the Sub-instance Control Register
 * (ICR) for a specified sub-instance index in the SSI peripheral.
 *
 * @param pSsi Pointer to the SSI_Type structure representing the SSI peripheral instance
 * @param u8IcrIdx The index of the sub-instance control register to configure
 * @param u32Value The value to set for the Protocol selection configuration
 */
LOCAL_INLINE void SSI_HWA_SetSubinsProtSel(SSI_Type *pSsi, uint8_t u8IcrIdx, uint32_t u32Value)
{
    uint32_t u32RegVal = pSsi->SUB_INS[u8IcrIdx].ICR;
    pSsi->SUB_INS[u8IcrIdx].ICR = (u32RegVal & ~SSI_ICR_PROT_SEL_MASK) | SSI_ICR_PROT_SEL(u32Value);
}

/**
 * @brief Get the Sub-instance Protocol Selection
 *
 * This function Gets the Protocol selection configuration in the Sub-instance Control Register
 * (ICR) for a specified sub-instance index in the SSI peripheral.
 *
 * @param pSsi Pointer to the SSI_Type structure representing the SSI peripheral instance
 * @param u8IcrIdx The index of the sub-instance control register to configure
 * @return The value of the Sub-instance Protocol Selection
 */
LOCAL_INLINE uint32_t SSI_HWA_GetSubinsProtSel(SSI_Type *pSsi, uint8_t u8IcrIdx)
{
    return ((pSsi->SUB_INS[u8IcrIdx].ICR & SSI_ICR_PROT_SEL_MASK) >> SSI_ICR_PROT_SEL_SHIFT);
}

#if SSI_INTERNAL_CMP_SUPPORT == STD_ON
/**
 * @brief Enable internal cmp for Sub-instance
 *
 * This function enables the internal cmp in the Sub-instance Control Register (ICR)
 * for a specified sub-instance index in the SSI peripheral.
 *
 * @param pSsi Pointer to the SSI_Type structure representing the SSI peripheral instance
 * @param u8IcrIdx The index of the sub-instance control register to configure
 */
LOCAL_INLINE void SSI_HWA_SubinsIntCmp_Enable(SSI_Type *pSsi, uint8_t u8IcrIdx)
{
    pSsi->SUB_INS[u8IcrIdx].ICR |= SSI_ICR_CMP_EN_MASK;
}

/**
 * @brief Disable internal cmp for Sub-instance
 *
 * This function Disable the internal cmp in the Sub-instance Control Register (ICR)
 * for a specified sub-instance index in the SSI peripheral.
 *
 * @param pSsi Pointer to the SSI_Type structure representing the SSI peripheral instance
 * @param u8IcrIdx The index of the sub-instance control register to configure
 */
LOCAL_INLINE void SSI_HWA_SubinsIntCmp_Disable(SSI_Type *pSsi, uint8_t u8IcrIdx)
{
    pSsi->SUB_INS[u8IcrIdx].ICR &= ~SSI_ICR_CMP_EN_MASK;
}

/**
 * @brief Set the Sub-instance Resistance Select
 *
 * This function sets resistance select configuration in the Sub-instance Control Register (ICR)
 * for a specified sub-instance index in the SSI peripheral.
 *
 * @param pSsi Pointer to the SSI_Type structure representing the SSI peripheral instance
 * @param u8IcrIdx The index of the sub-instance control register to configure
 * @param u32Value The value to set for the resource selection configuration
 */
LOCAL_INLINE void SSI_HWA_SetSubinsResSel(SSI_Type *pSsi, uint8_t u8IcrIdx, uint32_t u32Value)
{
    uint32_t u32RegVal          = pSsi->SUB_INS[u8IcrIdx].ICR;
    pSsi->SUB_INS[u8IcrIdx].ICR = (u32RegVal & ~SSI_ICR_RES_SEL_MASK) | SSI_ICR_RES_SEL(u32Value);
}
#endif

/**
 * @brief Set the Sub-instance GPWM Polarity
 *
 * This function sets the GPWM polarity configuration in the Sub-instance Control Register (ICR)
 * for a specified sub-instance index in the SSI peripheral.
 *
 * @param pSsi Pointer to the SSI_Type structure representing the SSI peripheral instance
 * @param u8IcrIdx The index of the sub-instance control register to configure
 * @param u32Value The value to set for the GPWM polarity configuration
 */
LOCAL_INLINE void SSI_HWA_SetSubinsGpwmPola(SSI_Type *pSsi, uint8_t u8IcrIdx, uint32_t u32Value)
{
    uint32_t u32RegVal = pSsi->SUB_INS[u8IcrIdx].ICR;
    pSsi->SUB_INS[u8IcrIdx].ICR = (u32RegVal & ~SSI_ICR_GPWM_INV_MASK) | SSI_ICR_GPWM_INV(u32Value);
}

/**
 * @brief Set the Sub-instance GPWM Time Counter
 *
 * This function sets the GPWM time counter configuration in the Sub-instance Control Register (ICR)
 * for a specified sub-instance index in the SSI peripheral.
 *
 * @param pSsi Pointer to the SSI_Type structure representing the SSI peripheral instance
 * @param u8IcrIdx The index of the sub-instance control register to configure
 * @param u32Value The value to set for the GPWM time counter configuration
 */
LOCAL_INLINE void SSI_HWA_SetSubinsGpwmTimeCnt(SSI_Type *pSsi, uint8_t u8IcrIdx, uint32_t u32Value)
{
    uint32_t u32RegVal = pSsi->SUB_INS[u8IcrIdx].ICR;
    pSsi->SUB_INS[u8IcrIdx].ICR = (u32RegVal & ~SSI_ICR_GPWM_TOC_MASK) | SSI_ICR_GPWM_TOC(u32Value);
}

/**
 * @brief Enable the Sub-instance Filter
 *
 * This function enables the filter in the Sub-instance Filter Register (IFR)
 * for a specified sub-instance index in the SSI peripheral.
 *
 * @param pSsi Pointer to the SSI_Type structure representing the SSI peripheral instance
 * @param u8IfrIdx The index of the sub-instance filter register to configure
 */
LOCAL_INLINE void SSI_HWA_SubinsFilter_Enable(SSI_Type *pSsi, uint8_t u8IfrIdx)
{
    pSsi->SUB_INS[u8IfrIdx].IFR |= SSI_IFR_FLT_EN_MASK;
}

/**
 * @brief Disable the Sub-instance Filter
 *
 * This function disable the filter in the Sub-instance Filter Register (IFR)
 * for a specified sub-instance index in the SSI peripheral.
 *
 * @param pSsi Pointer to the SSI_Type structure representing the SSI peripheral instance
 * @param u8IfrIdx The index of the sub-instance filter register to configure
 */
LOCAL_INLINE void SSI_HWA_SubinsFilter_Disable(SSI_Type *pSsi, uint8_t u8IfrIdx)
{
    pSsi->SUB_INS[u8IfrIdx].IFR &= ~SSI_IFR_FLT_EN_MASK;
}

/**
 * @brief Set the Sub-instance Filter Width
 *
 * This function sets the filter width configuration in the Sub-instance Filter Register (IFR)
 * for a specified sub-instance index in the SSI peripheral.
 *
 * @param pSsi Pointer to the SSI_Type structure representing the SSI peripheral instance
 * @param u8IfrIdx The index of the sub-instance filter register to configure
 * @param u32Value The value to set for the filter width configuration
 */
LOCAL_INLINE void SSI_HWA_SetSubinsFilterWidth(SSI_Type *pSsi, uint8_t u8IfrIdx, uint32_t u32Value)
{
    uint32_t u32RegVal          = pSsi->SUB_INS[u8IfrIdx].IFR;
    pSsi->SUB_INS[u8IfrIdx].IFR = (u32RegVal & ~SSI_IFR_FLT_WIDTH_MASK) |
                                  SSI_IFR_FLT_WIDTH(u32Value);
}

/**
 * @brief Set the Sub-instance Interrupt Configuration
 *
 * This function sets the interrupt configuration in the Sub-instance Interrupt Control Register
 * (INTCR) for a specified sub-instance index in the SSI peripheral.
 *
 * @param pSsi Pointer to the SSI_Type structure representing the SSI peripheral instance
 * @param u8IntcrIdx The index of the sub-instance interrupt control register to configure
 * @param u32Value The value to set for the interrupt configuration
 */
LOCAL_INLINE void SSI_HWA_SetSubinsIntCfg(SSI_Type *pSsi, uint8_t u8IntcrIdx, uint32_t u32Value)
{
    pSsi->SUB_INS[u8IntcrIdx].INTCR = u32Value;
}

/**
 * @brief Set the Sub-instance Interrupt Configuration
 *
 * This function sets the interrupt configuration in the Sub-instance Interrupt Control Register
 * (INTCR) for a specified sub-instance index in the SSI peripheral.
 *
 * @param pSsi Pointer to the SSI_Type structure representing the SSI peripheral instance
 * @param u8IntcrIdx The index of the sub-instance interrupt control register to configure
 * @param u32Value The value to set for the interrupt configuration
 */
LOCAL_INLINE void SSI_HWA_SubinsErrInt_Enable(SSI_Type *pSsi, uint8_t u8IntcrIdx)
{
    pSsi->SUB_INS[u8IntcrIdx].INTCR |= 0xDE;
}

/**
 * @brief Enable Valid Interrupt in Sub-instance
 *
 * This function enables the valid interrupt in the Sub-instance Interrupt Control Register (INTCR)
 * for a specified sub-instance index in the SSI peripheral.
 *
 * @param pSsi Pointer to the SSI_Type structure representing the SSI peripheral instance
 * @param u8IntcrIdx The index of the sub-instance interrupt control register to configure
 */
LOCAL_INLINE void SSI_HWA_SubinsValidInt_Enable(SSI_Type *pSsi, uint8_t u8IntcrIdx)
{
    pSsi->SUB_INS[u8IntcrIdx].INTCR |= SSI_INTCR_VLD_INT_EN_MASK;
}
/**
 * @brief Disable Valid Interrupt in Sub-instance
 *
 * This function disables the valid interrupt in the Sub-instance Interrupt Control Register (INTCR)
 * for a specified sub-instance index in the SSI peripheral.
 *
 * @param pSsi Pointer to the SSI_Type structure representing the SSI peripheral instance
 * @param u8IntcrIdx The index of the sub-instance interrupt control register to configure
 */
LOCAL_INLINE void SSI_HWA_SubinsValidInt_Disable(SSI_Type *pSsi, uint8_t u8IntcrIdx)
{
    pSsi->SUB_INS[u8IntcrIdx].INTCR &= ~SSI_INTCR_VLD_INT_EN_MASK;
}

/**
 * @brief Enable Stop Interrupt in Sub-instance
 *
 * This function enables the Stop interrupt in the Sub-instance Interrupt Control Register (INTCR)
 * for a specified sub-instance index in the SSI peripheral.
 *
 * @param pSsi Pointer to the SSI_Type structure representing the SSI peripheral instance
 * @param u8IntcrIdx The index of the sub-instance interrupt control register to configure
 */
LOCAL_INLINE void SSI_HWA_SubinsStopInt_Enable(SSI_Type *pSsi, uint8_t u8IntcrIdx)
{
    pSsi->SUB_INS[u8IntcrIdx].INTCR |= SSI_INTCR_STOP_INT_EN_MASK;
}

/**
 * @brief Disable Stop Interrupt in Sub-instance
 *
 * This function disables the Stop interrupt in the Sub-instance Interrupt Control Register (INTCR)
 * for a specified sub-instance index in the SSI peripheral.
 *
 * @param pSsi Pointer to the SSI_Type structure representing the SSI peripheral instance
 * @param u8IntcrIdx The index of the sub-instance interrupt control register to configure
 */
LOCAL_INLINE void SSI_HWA_SubinsStopInt_Disable(SSI_Type *pSsi, uint8_t u8IntcrIdx)
{
    pSsi->SUB_INS[u8IntcrIdx].INTCR &= ~SSI_INTCR_STOP_INT_EN_MASK;
}

/**
 * @brief Enable Timeout Interrupt in Sub-instance
 *
 * This function enables the timeout interrupt in the Sub-instance Interrupt Control Register
 * (INTCR) for a specified sub-instance index in the SSI peripheral.
 *
 * @param pSsi Pointer to the SSI_Type structure representing the SSI peripheral instance
 * @param u8IntcrIdx The index of the sub-instance interrupt control register to configure
 */
LOCAL_INLINE void SSI_HWA_SubinsFTimeoutInt_Enable(SSI_Type *pSsi, uint8_t u8IntcrIdx)
{
    pSsi->SUB_INS[u8IntcrIdx].INTCR |= SSI_INTCR_TIMEOUT_INT_EN_MASK;
}

/**
 * @brief Disable Timeout Interrupt in Sub-instance
 *
 * This function disables the timeout interrupt in the Sub-instance Interrupt Control Register
 * (INTCR) for a specified sub-instance index in the SSI peripheral.
 *
 * @param pSsi Pointer to the SSI_Type structure representing the SSI peripheral instance
 * @param u8IntcrIdx The index of the sub-instance interrupt control register to configure
 */
LOCAL_INLINE void SSI_HWA_SubinsFTimeoutInt_Disable(SSI_Type *pSsi, uint8_t u8IntcrIdx)
{
    pSsi->SUB_INS[u8IntcrIdx].INTCR &= ~SSI_INTCR_TIMEOUT_INT_EN_MASK;
}

/**
 * @brief Enable Range Error Interrupt in Sub-instance
 *
 * This function enables the Range Error interrupt in the Sub-instance Interrupt Control Register
 * (INTCR) for a specified sub-instance index in the SSI peripheral.
 *
 * @param pSsi Pointer to the SSI_Type structure representing the SSI peripheral instance
 * @param u8IntcrIdx The index of the sub-instance interrupt control register to configure
 */
LOCAL_INLINE void SSI_HWA_SubinsRangeErrInt_Enable(SSI_Type *pSsi, uint8_t u8IntcrIdx)
{
    pSsi->SUB_INS[u8IntcrIdx].INTCR |= SSI_INTCR_RANGE_ERR_EN_MASK;
}

/**
 * @brief Disable Range Error Interrupt in Sub-instance
 *
 * This function disables the Range Error interrupt in the Sub-instance Interrupt Control Register
 * (INTCR) for a specified sub-instance index in the SSI peripheral.
 *
 * @param pSsi Pointer to the SSI_Type structure representing the SSI peripheral instance
 * @param u8IntcrIdx The index of the sub-instance interrupt control register to configure
 */
LOCAL_INLINE void SSI_HWA_SubinsRangeErrInt_Disable(SSI_Type *pSsi, uint8_t u8IntcrIdx)
{
    pSsi->SUB_INS[u8IntcrIdx].INTCR &= ~SSI_INTCR_RANGE_ERR_EN_MASK;
}

/**
 * @brief Enable Decode Error Interrupt in Sub-instance
 *
 * This function enables the Decode Error interrupt in the Sub-instance Interrupt Control Register
 * (INTCR) for a specified sub-instance index in the SSI peripheral.
 *
 * @param pSsi Pointer to the SSI_Type structure representing the SSI peripheral instance
 * @param u8IntcrIdx The index of the sub-instance interrupt control register to configure
 */
LOCAL_INLINE void SSI_HWA_SubinsDecodeErrInt_Enable(SSI_Type *pSsi, uint8_t u8IntcrIdx)
{
    pSsi->SUB_INS[u8IntcrIdx].INTCR |= SSI_INTCR_DECODE_ERR_EN_MASK;
}

/**
 * @brief Disable Decode Error Interrupt in Sub-instance
 *
 * This function disables the Decode Error interrupt in the Sub-instance Interrupt Control Register
 * (INTCR) for a specified sub-instance index in the SSI peripheral.
 *
 * @param pSsi Pointer to the SSI_Type structure representing the SSI peripheral instance
 * @param u8IntcrIdx The index of the sub-instance interrupt control register to configure
 */
LOCAL_INLINE void SSI_HWA_SubinsDecodeErrInt_Disable(SSI_Type *pSsi, uint8_t u8IntcrIdx)
{
    pSsi->SUB_INS[u8IntcrIdx].INTCR &= ~SSI_INTCR_DECODE_ERR_EN_MASK;
}

/**
 * @brief Enable Interval Error Interrupt in Sub-instance
 *
 * This function enables the Interval Error interrupt in the Sub-instance Interrupt Control Register
 * (INTCR) for a specified sub-instance index in the SSI peripheral.
 *
 * @param pSsi Pointer to the SSI_Type structure representing the SSI peripheral instance
 * @param u8IntcrIdx The index of the sub-instance interrupt control register to configure
 */
LOCAL_INLINE void SSI_HWA_SubinsIntervalErrInt_Enable(SSI_Type *pSsi, uint8_t u8IntcrIdx)
{
    pSsi->SUB_INS[u8IntcrIdx].INTCR |= SSI_INTCR_INTERVAL_ERR_EN_MASK;
}

/**
 * @brief Disable Interval Error Interrupt in Sub-instance
 *
 * This function disables the Interval Error interrupt in the Sub-instance Interrupt Control
 * Register (INTCR) for a specified sub-instance index in the SSI peripheral.
 *
 * @param pSsi Pointer to the SSI_Type structure representing the SSI peripheral instance
 * @param u8IntcrIdx The index of the sub-instance interrupt control register to configure
 */
LOCAL_INLINE void SSI_HWA_SubinsIntervalErrInt_Disable(SSI_Type *pSsi, uint8_t u8IntcrIdx)
{
    pSsi->SUB_INS[u8IntcrIdx].INTCR &= ~SSI_INTCR_INTERVAL_ERR_EN_MASK;
}

/**
 * @brief Enable Pulse Width Error Interrupt in Sub-instance
 *
 * This function enables the Pulse Width Error interrupt in the Sub-instance Interrupt Control
 * Register (INTCR) for a specified sub-instance index in the SSI peripheral.
 *
 * @param pSsi Pointer to the SSI_Type structure representing the SSI peripheral instance
 * @param u8IntcrIdx The index of the sub-instance interrupt control register to configure
 */
LOCAL_INLINE void SSI_HWA_SubinsPulseWidthErrInt_Enable(SSI_Type *pSsi, uint8_t u8IntcrIdx)
{
    pSsi->SUB_INS[u8IntcrIdx].INTCR |= SSI_INTCR_PULSE_WIDTH_ERR_EN_MASK;
}

/**
 * @brief Disable Pulse Width Error Interrupt in Sub-instance
 *
 * This function disables the Pulse Width Error interrupt in the Sub-instance Interrupt Control
 * Register (INTCR) for a specified sub-instance index in the SSI peripheral.
 *
 * @param pSsi Pointer to the SSI_Type structure representing the SSI peripheral instance
 * @param u8IntcrIdx The index of the sub-instance interrupt control register to configure
 */

LOCAL_INLINE void SSI_HWA_SubinsPulseWidthErrInt_Disable(SSI_Type *pSsi, uint8_t u8IntcrIdx)
{
    pSsi->SUB_INS[u8IntcrIdx].INTCR &= ~SSI_INTCR_PULSE_WIDTH_ERR_EN_MASK;
}

/**
 * @brief Enable Protocol Error Interrupt in Sub-instance
 *
 * This function enables the Protocol Error interrupt in the Sub-instance Interrupt Control Register
 * (INTCR) for a specified sub-instance index in the SSI peripheral.
 *
 * @param pSsi Pointer to the SSI_Type structure representing the SSI peripheral instance
 * @param u8IntcrIdx The index of the sub-instance interrupt control register to configure
 */
LOCAL_INLINE void SSI_HWA_SubinsProtErrInt_Enable(SSI_Type *pSsi, uint8_t u8IntcrIdx)
{
    pSsi->SUB_INS[u8IntcrIdx].INTCR |= SSI_INTCR_PROTOC_ERR_INT_EN_MASK;
}

/**
 * @brief Disable Protocol Error Interrupt in Sub-instance
 *
 * This function disables the Protocol Error interrupt in the Sub-instance Interrupt Control
 * Register (INTCR) for a specified sub-instance index in the SSI peripheral.
 *
 * @param pSsi Pointer to the SSI_Type structure representing the SSI peripheral instance
 * @param u8IntcrIdx The index of the sub-instance interrupt control register to configure
 */
LOCAL_INLINE void SSI_HWA_SubinsProtErrInt_Disable(SSI_Type *pSsi, uint8_t u8IntcrIdx)
{
    pSsi->SUB_INS[u8IntcrIdx].INTCR &= ~SSI_INTCR_PROTOC_ERR_INT_EN_MASK;
}

/**
 * @brief Get Sensor Protocol Counter Value
 *
 * This function retrieves the counter value from the Sensor Protocol Control Register (SPCR)
 * for a specified sub-instance index in the SSI peripheral.
 *
 * @param pSsi Pointer to the SSI_Type structure representing the SSI peripheral instance
 * @param u8SpcrIdx The index of the sensor protocol control register to read
 * @return The counter value from the specified sensor protocol control register
 */
LOCAL_INLINE uint32_t SSI_HWA_GetSensorProtocolCnt(SSI_Type *pSsi, uint8_t u8SpcrIdx)
{
    return (pSsi->SUB_INS[u8SpcrIdx].SPCR & SSI_SPCR_CNT_MASK);
}

/**
 * @brief Get High Pulse Counter Value
 *
 * This function retrieves the high pulse counter value from the High Pulse Control Register (HPCR)
 * for a specified sub-instance index in the SSI peripheral.
 *
 * @param pSsi Pointer to the SSI_Type structure representing the SSI peripheral instance
 * @param u8HpcrIdx The index of the high pulse control register to read
 * @return The high pulse counter value from the specified high pulse control register
 */
LOCAL_INLINE uint32_t SSI_HWA_GetHighPulseCnt(SSI_Type *pSsi, uint8_t u8HpcrIdx)
{
    return (pSsi->SUB_INS[u8HpcrIdx].HPCR & SSI_HPCR_HPULSE_MASK);
}

/**
 * @brief Get AK Manchester Code Value
 *
 * This function retrieves the AK man Manchester value from the AK Protocol Register (AKPR)
 * for a specified sub-instance index in the SSI peripheral.
 *
 * @param pSsi Pointer to the SSI_Type structure representing the SSI peripheral instance
 * @param u8AkprIdx The index of the AK Protocol register to read
 * @return The AK Manchester code value from the specified AK Protocol register
 */
LOCAL_INLINE uint32_t SSI_HWA_GetAkMancodeVal(SSI_Type *pSsi, uint8_t u8AkprIdx)
{
    return (pSsi->SUB_INS[u8AkprIdx].AKPR & SSI_AKPR_MCODE_MASK);
}

/**
 * @brief Get AK Manchester Decode Counter Value
 *
 * This function retrieves the AK Manchester decode counter value from the AK Protocol Register
 * (AKPR) for a specified sub-instance index in the SSI peripheral. The counter value is extracted
 * and right-shifted by the appropriate number of bits to align it correctly.
 *
 * @param pSsi Pointer to the SSI_Type structure representing the SSI peripheral instance
 * @param u8AkprIdx The index of the AK Protocol register to read
 * @return The AK Manchester decode counter value from the specified AK Protocol register
 */
LOCAL_INLINE uint32_t SSI_HWA_GetAkManDecodeCnt(SSI_Type *pSsi, uint8_t u8AkprIdx)
{
    return ((pSsi->SUB_INS[u8AkprIdx].AKPR & SSI_AKPR_MCODE_CNT_MASK) >> SSI_AKPR_MCODE_CNT_SHIFT);
}

/**
 * @brief Get PWM Decode Value
 *
 * This function retrieves the PWM decode value from the PWM Protocol Register (PWMPR)
 * for a specified sub-instance index in the SSI peripheral.
 *
 * @param pSsi Pointer to the SSI_Type structure representing the SSI peripheral instance
 * @param u8PwmprIdx The index of the PWM Protocol register to read
 * @return The PWM decode value from the specified PWM Protocol register
 */
LOCAL_INLINE uint32_t SSI_HWA_GetPwmDecodeVal(SSI_Type *pSsi, uint8_t u8PwmprIdx)
{
    return (pSsi->SUB_INS[u8PwmprIdx].PWMPR & SSI_PWMPR_PCODE_MASK);
}

/**
 * @brief Unlock the MB_INTn registers
 *
 * @param u8CoreIndex the index of the core
 * @param u32Mask the unlock bits
 */
LOCAL_INLINE uint32_t SSI_HWA_GetStatusVal(SSI_Type *pSsi, uint8_t u8IsrIdx)
{
    uint32 u32Status = SSI_ISR_PROTOC_ERR(1) | SSI_ISR_PULSE_WIDTH_ERR(1) | SSI_ISR_INTERVAL_ERR(1) |
                    SSI_ISR_DECODE_ERR(1) | SSI_ISR_SPC_RANGE_ERR(1) | SSI_ISR_SPC_TIMEOUT_ERR(1) |
                    SSI_ISR_WHL_STOP(1) | SSI_ISR_SPC_VLD(1);
    return (pSsi->SUB_INS[u8IsrIdx].ISR & u32Status);
}

/**
 * @brief Unlock the MB_INTn registers
 *
 * @param u8CoreIndex the index of the core
 * @param u32Mask the unlock bits
 */
LOCAL_INLINE uint32_t SSI_HWA_GetIntCmpStatus(SSI_Type *pSsi, uint8_t u8IsrIdx)
{
    return ((pSsi->SUB_INS[u8IsrIdx].ISR & SSI_ISR_CMP_IOK_MASK) >> SSI_ISR_CMP_IOK_SHIFT);
}

/**
 * @brief Unlock the MB_INTn registers
 *
 * @param u8CoreIndex the index of the core
 * @param u32Mask the unlock bits
 */
LOCAL_INLINE void SSI_HWA_ClearSubStatus(SSI_Type *pSsi, uint8_t u8IsrIdx)
{
    uint32 u32Val = SSI_ISR_PROTOC_ERR(1) | SSI_ISR_PULSE_WIDTH_ERR(1) | SSI_ISR_INTERVAL_ERR(1) |
                    SSI_ISR_DECODE_ERR(1) | SSI_ISR_SPC_RANGE_ERR(1) | SSI_ISR_SPC_TIMEOUT_ERR(1) |
                    SSI_ISR_WHL_STOP(1) | SSI_ISR_SPC_VLD(1);
    pSsi->SUB_INS[u8IsrIdx].ISR |= u32Val;
}

/**
 * @brief Unlock the MB_INTn registers
 *
 * @param u8CoreIndex the index of the core
 * @param u32Mask the unlock bits
 */
LOCAL_INLINE void SSI_HWA_ClearSpcVldStatus(SSI_Type *pSsi, uint8_t u8IsrIdx)
{
    pSsi->SUB_INS[u8IsrIdx].ISR = SSI_ISR_SPC_VLD(1);
}

#endif /* #if SSI_INSTANCE_COUNT > 0U */

#endif
