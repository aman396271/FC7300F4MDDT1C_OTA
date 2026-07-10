/**
 * @file HwA_rtc.h
 * @author Flagchip
 * @brief rtc hardware access layer
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
   *   0.1.0      2023-12-15     Flagchip076   N/A          First version for FC7300
   *   2.0.0      2024-10-12     Flagchip120   N/A          Change version and release
   ******************************************************************************** */

#ifndef HWA_INCLUDE_HWA_RTC_H_
#define HWA_INCLUDE_HWA_RTC_H_


#include "device_header.h"

#if RTC_INSTANCE_COUNT > 0U

/**
 * @defgroup HwA_rtc HwA_rtc
 * @ingroup module_driver_rtc
 * @{
 */

/********* Local typedef ************/

/**
 *  @brief in the second interrupt mode, this type indicates the interrupt frequency.
 * in the clkout mode , this type indicates the clkout frequency . 
 * 
 * */
typedef enum
{
    RTC_FREQ_1HZ = 0,                       /*!< Set  the RTC Seconds interrupt and the RTC_CLKOUT prescale output frequency to 1Hz */
    RTC_FREQ_2HZ,                           /*!< Set  the RTC Seconds interrupt and the RTC_CLKOUT prescale output frequency to 2Hz */
    RTC_FREQ_4HZ,                           /*!< Set  the RTC Seconds interrupt and the RTC_CLKOUT prescale output frequency to 4Hz */
    RTC_FREQ_8HZ,                           /*!< Set  the RTC Seconds interrupt and the RTC_CLKOUT prescale output frequency to 8Hz */
    RTC_FREQ_16HZ,                          /*!< Set  the RTC Seconds interrupt and the RTC_CLKOUT prescale output frequency to 16Hz */
    RTC_FREQ_32hZ,                          /*!< Set  the RTC Seconds interrupt and the RTC_CLKOUT prescale output frequency to 32Hz */
    RTC_FREQ_64HZ,                          /*!< Set  the RTC Seconds interrupt and the RTC_CLKOUT prescale output frequency to 64Hz */
    RTC_FREQ_128HZ                          /*!< Set  the RTC Seconds interrupt and the RTC_CLKOUT prescale output frequency to 128Hz */
} RTC_ClkoutSecIntFreqType;
/********* Local inline function ************/

/**
 * @brief Read second value
 *
 * @param pRtc the base address of the pRtc instance.
 * @return Second value
 */
LOCAL_INLINE uint32_t RTC_HWA_ReadSecondValue(RTC_Type *const pRtc)
{
    uint32_t u32SecondValue0, u32SecondValue1;
    do
    {
        u32SecondValue0 = pRtc->SR;
        u32SecondValue1 = pRtc->SR;
    }while (u32SecondValue0 != u32SecondValue1);
    return u32SecondValue0;
}

/**
 * @brief Read RTC SR overflow flag
 *
 * @param pRtc the base address of the pRtc instance.
 * @return true means Overflow flag is 1 ;false means Overflow flag is 0.
 */
LOCAL_INLINE bool RTC_HWA_ReadOverflowFlag(RTC_Type *const pRtc)
{
    return (bool)(((pRtc->STR & (uint32_t)RTC_STR_TOF_MASK)!=0u)? true:false);
}

/**
 * @brief Read RTC IER overflow enable bit
 *
 * @param pRtc the base address of the pRtc instance.
 * @return true means enable Overflow Interrupt ;false means disable Overflow Interrupt
 */
LOCAL_INLINE bool RTC_HWA_ReadOverflowEnable(RTC_Type *const pRtc)
{
    return  (bool)(((pRtc->IER & (uint32_t)RTC_IER_TOIE_MASK)!=0u) ? true:false);
}

/**
 * @brief Read RTC alarm flag
 *
 * @param pRtc the base address of the pRtc instance.
 * @return true means alarm flag is 1 ;false means alarm flag is 0.
 */
LOCAL_INLINE bool RTC_HWA_ReadAlarmFlag(RTC_Type *const pRtc)
{
    return (bool)(((pRtc->STR & (uint32_t)RTC_STR_TAF_MASK)!=0u)?true:false);
}

/**
 * @brief Read RTC alarm Enable
 *
 * @param pRtc the base address of the pRtc instance.
 * @return true means enable alarm Interrupt ;false means disable alarm Interrupt
 */
LOCAL_INLINE bool RTC_HWA_ReadAlarmEnable(RTC_Type *const pRtc)
{
    return (bool)(((pRtc->IER & (uint32_t)RTC_IER_TAIE_MASK)!=0u)?true:false);
}

/**
 * @brief Read RTC second  interrupt Enable
 *
 * @param pRtc the base address of the pRtc instance.
 * @return true means enable second Interrupt ;false means disable second Interrupt
 */
LOCAL_INLINE bool RTC_HWA_ReadSecondEnable(RTC_Type *const pRtc)
{
    return (bool)(((pRtc->IER & (uint32_t)RTC_IER_TSIE_MASK)!=0u)?true:false);
}

/**
 * @brief Read RTC Compensation Interbal
 *
 * @param pRtc the base address of the pRtc instance.
 * @return Compensation Interbal
 */
LOCAL_INLINE uint8_t RTC_HWA_ReadCompInterval(RTC_Type *const pRtc)
{
    return (uint8_t)((pRtc->COMPR & (uint32_t)RTC_COMPR_CIC_MASK) >> RTC_COMPR_CIC_SHIFT);
}

/**
 * @brief Read RTC Compensation Value
 *
 * @param pRtc the base address of the pRtc instance.
 * @return Compensation Value
 */
LOCAL_INLINE uint8_t RTC_HWA_ReadCompValue(RTC_Type *const pRtc)
{
    return (uint8_t)((pRtc->COMPR & (uint32_t)RTC_COMPR_TCV_MASK) >> RTC_COMPR_TCV_SHIFT);
}

/**
 * @brief Sets the RTC compare interval.
 *
 * @param pRtc the base address of the pRtc instance.
 * @param u8Interval The compare interval reload value, in seconds.
 */
LOCAL_INLINE void RTC_HWA_SetCompInterval(RTC_Type *const pRtc, uint8_t u8Interval)
{
    pRtc->COMPR = ((pRtc->COMPR & ~RTC_COMPR_CIR_MASK) | (uint32_t)(u8Interval << RTC_COMPR_CIR_SHIFT));
}

/**
 * @brief Sets the RTC compare value.
 *
 * @param pRtc the base address of the pRtc instance.
 * @param u8Value The compare value, in ticks. 
 */
LOCAL_INLINE void RTC_HWA_SetCompValue(RTC_Type *const pRtc, uint8_t u8Value)
{
    pRtc->COMPR = ((pRtc->COMPR & ~RTC_COMPR_TCR_MASK) | (uint32_t)(u8Value << RTC_COMPR_TCR_SHIFT));
}

/**
 * @brief Set RTC prescaler register
 *
 * @param pRtc the base address of the pRtc instance.
 * @param u16Value PR register value
 */
LOCAL_INLINE void RTC_HWA_SetPrescalerCounterValue(RTC_Type *const pRtc, uint16_t u16Value)
{
    pRtc->PR = (uint32_t)u16Value;
    pRtc->PR = (uint32_t)u16Value;
}

/**
 * @brief Set RTC seconds register
 *
 * @param pRtc the base address of the pRtc instance.
 * @param u32Value SR register value
 */
LOCAL_INLINE void RTC_HWA_SetSecondCounterValue(RTC_Type *const pRtc, uint32_t u32Value)
{
    pRtc->SR = u32Value;
}

/**
 * @brief Set RTC alarm value
 *
 * @param pRtc the base address of the pRtc instance.
 * @param u32Value TAR register value
 */
LOCAL_INLINE void RTC_HWA_SetAlarmCounterValue(RTC_Type *const pRtc, uint32_t u32Value)
{
    pRtc->AR = u32Value;
}

/**
 * @brief Set RTC interrupt value
 *
 * @param pRtc the base address of the pRtc instance.
 * @param u32Value IER register value
 */
LOCAL_INLINE void RTC_HWA_SetInterruptValue(RTC_Type *const pRtc, uint32_t u32Value)
{
    pRtc->IER = u32Value;
}

/**
 * @brief Configure control register
 *
 * @param pRtc the base address of the pRtc instance.
 * @param u32Value Control value
 */
LOCAL_INLINE void RTC_HWA_ConfigControl(RTC_Type *const pRtc, uint32_t u32Value)
{
    pRtc->CR = u32Value;
}

/**
 * @brief Enable RTC time counter
 *
 * @param pRtc the base address of the pRtc instance.
 */
LOCAL_INLINE void RTC_HWA_EnableRtcCounter(RTC_Type *const pRtc)
{
    uint32_t u32RegValue = pRtc->STR;
    u32RegValue |= (uint32_t)RTC_STR_TCE_MASK;
    u32RegValue &= ~(uint32_t)0x8u;
    pRtc->STR = u32RegValue;
}

/**
 * @brief Set RTC_CLKOUT is from the 32.768 khz clock
 *
 * @param pRtc the base address of the pRtc instance.
 */
LOCAL_INLINE void RTC_HWA_SetClkoutFreqStable(RTC_Type *const pRtc)
{
    pRtc->CR |= (uint32_t)RTC_CR_CKPS_MASK;
}

/**
 * @brief Enable alarm interrupt
 *
 * @param pRtc the base address of the pRtc instance.
 * @param bEnable Indicates whether to enable the interrupt. true: Enable interrupt, false: Disable interrupt.
 */
LOCAL_INLINE void RTC_HWA_EnableAlarmInterrupt(RTC_Type *const pRtc,  bool bEnable)
{
    pRtc->IER = (pRtc->IER & ~(uint32_t)RTC_IER_TAIE_MASK) | RTC_IER_TAIE(bEnable);
}

/**
 * @brief Enable second interrupt
 *
 * @param pRtc the base address of the pRtc instance.
 * @param bEnable A boolean indicating whether to enable (true) or disable (false) the interrupt.
 */
LOCAL_INLINE void RTC_HWA_EnableSecondInterrupt(RTC_Type *const pRtc,  bool bEnable)
{
    pRtc->IER = (pRtc->IER & ~(uint32_t)RTC_IER_TSIE_MASK) | RTC_IER_TSIE(bEnable);
}

/**
 * @brief Enable overflow interrupt
 *
 * @param pRtc the base address of the pRtc instance.
 * @param bEnable Boolean value indicating whether to enable (true) or disable (false) the interrupt.
 */
LOCAL_INLINE void RTC_HWA_EnableOverflowInterrupt(RTC_Type *const pRtc,  bool bEnable)
{
    pRtc->IER = (pRtc->IER & ~(uint32_t)RTC_IER_TOIE_MASK) | RTC_IER_TOIE(bEnable);
}

/**
 * @brief Unlock lock/status/control/compensation register
 *
 * @param pRtc the base address of the pRtc instance.
 */
LOCAL_INLINE void RTC_HWA_UnlockStatusControlCompensationReg(RTC_Type *const pRtc)
{
    pRtc->LR |= (uint32_t)(RTC_LR_LRL_MASK | RTC_LR_STRL_MASK | RTC_LR_CRL_MASK | RTC_LR_CPL_MASK);
}

/**
 * @brief Set second interrupt and RTC_CLKOUT frequency
 *
 * @param pRtc the base address of the pRtc instance.
 * @param eFreq Frequency value
 */
LOCAL_INLINE void RTC_HWA_SetSecondAndClkoutFreq(RTC_Type *const pRtc, RTC_ClkoutSecIntFreqType eFreq)
{
	uint32_t u32RegValue = pRtc->IER;
	pRtc->IER &= ~(uint32_t)RTC_IER_TSIE_MASK;
	pRtc->IER = (u32RegValue & ~(uint32_t)RTC_IER_TSIC_MASK) | RTC_IER_TSIC(eFreq);
}

/**
 * @brief Disable RTC time counter
 *
 * @param pRtc the base address of the pRtc instance.
 */
LOCAL_INLINE void RTC_HWA_DisableRtcCounter(RTC_Type *const pRtc)
{
    pRtc->STR &= ~(uint32_t)(RTC_STR_TCE_MASK | 0x8u);
}

/**
 * @brief Set RTC_CLKOUT is from the prescaler output clock selected by IER[TSIC]
 *
 * @param pRtc the base address of the pRtc instance.
 */
LOCAL_INLINE void RTC_HWA_SetClkoutFromSelectFreq(RTC_Type *const pRtc)
{
    pRtc->CR &= ~(uint32_t)RTC_CR_CKPS_MASK;
}

/**
 * @brief Disable alarm interrupt
 *
 * @param pRtc the base address of the pRtc instance.
 */
LOCAL_INLINE void RTC_HWA_DisableAlarmInterrupt(RTC_Type *const pRtc)
{
    pRtc->IER &= ~(uint32_t)RTC_IER_TAIE_MASK;
}

/**
 * @brief Disable second interrupt
 *
 * @param pRtc the base address of the pRtc instance.
 */
LOCAL_INLINE void RTC_HWA_DisableSecondInterrupt(RTC_Type *const pRtc)
{
    pRtc->IER &= ~(uint32_t)RTC_IER_TSIE_MASK;
}

/**
 * @brief Disable overflow interrupt
 *
 * @param pRtc the base address of the pRtc instance.
 */
LOCAL_INLINE void RTC_HWA_DisableOverflowInterrupt(RTC_Type *const pRtc)
{
    pRtc->IER &= ~(uint32_t)RTC_IER_TOIE_MASK;
}

#endif

/** @}*/ /* HwA_RTC */
#endif /* HWA_INCLUDE_HWA_RTC_H_ */
