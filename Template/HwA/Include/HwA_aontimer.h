/**
 * @file HwA_aontimer.h
 * @author Flagchip
 * @brief aontimer hardware access layer
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
   *   0.1.0       2023-12-15    Flagchip076   N/A          First version for FC7300
   *   2.0.0       2024-10-12    Flagchip076   N/A          Change version and release
   ******************************************************************************** */

#ifndef HWA_INCLUDE_HWA_AONTIMER_H_
#define HWA_INCLUDE_HWA_AONTIMER_H_

#include "device_header.h"

#if AONTIMER_INSTANCE_COUNT > 0U

/**
 * @defgroup HwA_aontimer HwA_aontimer
 * @ingroup module_driver_aontimer
 * @{
 *
 */

/********* Local typedef ************/
/**
 *  @brief The clock source of the pulse mode
 * 
 */
typedef enum
{

    AONTIMER_CLK0_PIN  = 0,                /*!< select the Aontimer_clk0 pin as pulse sourse*/
    AONTIMER_CLK1_PIN,                     /*!< select the Aontimer_clk1 pin as pulse sourse*/
    AONTIMER_CLK2_PIN,                     /*!< select the Aontimer_clk2 pin as pulse sourse*/
    AONTIMER_TRGSEL_OUTPUT,                /*!< select the tresel as pulse sourse*/

} AONTIMER_PulseClkSrcType;

/** 
 * @brief Aontimer clock source, please refer to Reference Manual chapter8.Aontimer for details. 
 *
 *  */
typedef enum
{
    AONTIMER_SIRC_1MHZ = 0U,  /*!< AONTIMER SIRC 1mhz clock */
    AONTIMER_RTC_CLK = 2U,    /*!< AONTIMER RTC clock  */
    AONTIMER_IRC_CLK = 3U     /*!< AONTIMER internal clock, which comes from PCC */
} AONTIMER_ClkSrcType;

/** 
 * @brief The polarity of pulse mode 
 * 
 * */
typedef enum
{
    AONTIMER_PulsePolarityType_HIGH = 0,        /*!< select the high polarity */
    AONTIMER_PulsePolarityType_LOW              /*!< select the low polarity */
} AONTIMER_PulsePolarityType;

/********* Local inline function ************/
/**
 * @brief Configure AONTIMER module
 *
 * @param pAontimer the base address of the pAontimer instance.
 * @param u32RegValue CSR register value
 */
LOCAL_INLINE void AONTIMER_HWA_ConfigModule(AONTIMER_Type *const pAontimer, uint32_t u32RegValue)
{
    pAontimer->CSR = u32RegValue;
}

/**
 * @brief Configure AONTIMER module prescale
 *
 * @param pAontimer the base address of the pAontimer instance.
 * @param u32RegValue PSR register value
 */
LOCAL_INLINE void AONTIMER_HWA_ConfigModulePrescale(AONTIMER_Type *const pAontimer, uint32_t u32RegValue)
{
    pAontimer->PSR = u32RegValue;
}

/**
 * @brief Set AONTIMER compare value
 *
 * @param pAontimer the base address of the pAontimer instance.
 * @param u32RegValue CMR register value
 */
LOCAL_INLINE void AONTIMER_HWA_SetModuleCompareValue(AONTIMER_Type *const pAontimer, uint32_t u32RegValue)
{
    pAontimer->CMR = u32RegValue;
}

/**
 * @brief Set AONTIMER current counter value
 *
 * @param pAontimer the base address of the pAontimer instance.
 * @param u32RegValue CNR register value
 */
LOCAL_INLINE void AONTIMER_HWA_SetModuleCounterValue(AONTIMER_Type *const pAontimer, uint32_t u32RegValue)
{
    pAontimer->CNR = u32RegValue;
}

/**
 * @brief Set AONTIMER module running on debug mode
 *
 * @param pAontimer the base address of the pAontimer instance.
 */
LOCAL_INLINE void AONTIMER_HWA_SetModuleRunOnDebug(AONTIMER_Type *const pAontimer)
{
    uint32_t u32RegValue = pAontimer->CSR;
    u32RegValue |= (uint32_t)AONTIMER_CSR_DBGEN_MASK;
    u32RegValue &= ~(uint32_t)AONTIMER_CSR_TCF_MASK;
    pAontimer->CSR = u32RegValue;
}

/**
 * @brief Enable AONTIMER module interrupt
 *
 * @param pAontimer the base address of the pAontimer instance.
 */
LOCAL_INLINE void AONTIMER_HWA_EnableModuleInterrupt(AONTIMER_Type *const pAontimer)
{
    uint32_t u32RegValue = pAontimer->CSR;
    u32RegValue |= (uint32_t)AONTIMER_CSR_TIE_MASK;
    u32RegValue &= ~(uint32_t)AONTIMER_CSR_TCF_MASK;
    pAontimer->CSR = u32RegValue;
}

/**
 * @brief Select AONTIMER module external clock source when timer configured to pulse mode
 *
 * @param pAontimer the base address of the pAontimer instance.
 * @param eClk Input counter clock source
 */
LOCAL_INLINE void AONTIMER_HWA_SelectClkSrcOnPulseMode(AONTIMER_Type *const pAontimer, AONTIMER_PulseClkSrcType eClk)
{
    uint32_t u32RegValue = pAontimer->CSR;
    u32RegValue |= (u32RegValue & ~(uint32_t)AONTIMER_CSR_TPS_MASK) | AONTIMER_CSR_TPS(eClk);
    u32RegValue &= ~(uint32_t)AONTIMER_CSR_TCF_MASK;
    pAontimer->CSR = u32RegValue;
}

/**
 * @brief Clear AONTIMER interrupt flags
 *
 * @param pAontimer the base address of the pAontimer instance.
 */
LOCAL_INLINE void AONTIMER_HWA_ClearInterruptFlag(AONTIMER_Type *const pAontimer)
{
    pAontimer->CSR |= (uint32_t)AONTIMER_CSR_TCF_MASK;
}

/**
 * @brief Set AONTIMER module polarity. Pulse counter input source is active-low, and the CNR increments on falling-edge.
 *
 * @param pAontimer the base address of the pAontimer instance.
 */
LOCAL_INLINE void AONTIMER_HWA_SetModulePolarity(AONTIMER_Type *const pAontimer)
{
    uint32_t u32RegValue = pAontimer->CSR;
    u32RegValue |= (uint32_t)AONTIMER_CSR_TPP_MASK;
    u32RegValue &= ~(uint32_t)AONTIMER_CSR_TCF_MASK;
    pAontimer->CSR = u32RegValue;
}

/**
 * @brief Configure AONTIMER module polarity. If ePol is 0:Pulse counter input source is active-high, and the CNR increments on rising-edge.
 *                                            If ePol is 1:Pulse counter input source is active-low, and the CNR increments on falling-edge.
 *
 * @param pAontimer the base address of the pAontimer instance.
 * @param ePol Polarity enumeration
 */
LOCAL_INLINE void AONTIMER_HWA_ConfigModulePolarity(AONTIMER_Type *const pAontimer, AONTIMER_PulsePolarityType ePol)
{
    uint32_t u32RegValue = pAontimer->CSR;
    u32RegValue |= AONTIMER_CSR_TPP(ePol);
    u32RegValue &= ~(uint32_t)AONTIMER_CSR_TCF_MASK;
    pAontimer->CSR = u32RegValue;
}

/**
 * @brief Enable AONTIMER module pulse mode
 *
 * @param pAontimer the base address of the pAontimer instance.
 */
LOCAL_INLINE void AONTIMER_HWA_EnablePulseMode(AONTIMER_Type *const pAontimer)
{
    uint32_t u32RegValue = pAontimer->CSR;
    u32RegValue |= (uint32_t)AONTIMER_CSR_TMS_MASK;
    u32RegValue &= ~(uint32_t)AONTIMER_CSR_TCF_MASK;
    pAontimer->CSR = u32RegValue;
}

/**
 * @brief Enable AONTIMER timer
 *
 * @param pAontimer the base address of the pAontimer instance.
 */
LOCAL_INLINE void AONTIMER_HWA_EnableTimer(AONTIMER_Type *const pAontimer)
{
    uint32_t u32RegValue = pAontimer->CSR;
    u32RegValue |= (uint32_t)AONTIMER_CSR_TEN_MASK;
    u32RegValue &= ~(uint32_t)AONTIMER_CSR_TCF_MASK;
    pAontimer->CSR = u32RegValue;
}

/**
 * @brief Set AONTIMER prescale
 *
 * @param pAontimer the base address of the pAontimer instance.
 * @param u8PrescalerValue Prescaler value,the range of the input value is :0~15, and the range of prescaler is :2^1 ~ 2^16.
 */
LOCAL_INLINE void AONTIMER_HWA_SetPrescale(AONTIMER_Type *const pAontimer, uint8_t u8PrescalerValue)
{
    uint32_t u32RegValue = pAontimer->PSR;
    pAontimer->PSR = ((u32RegValue & ~(uint32_t)AONTIMER_PSR_PRESCALE_MASK) | AONTIMER_PSR_PRESCALE(u8PrescalerValue));
}

/**
 * @brief If enable bypass mode, the timer will bypass the prescaler in timer counter mode or glitch filter in pulse mode
 *
 * @param pAontimer the base address of the pAontimer instance.
 */
LOCAL_INLINE void AONTIMER_HWA_EnableBypassMode(AONTIMER_Type *const pAontimer)
{
    pAontimer->PSR |= (uint32_t)AONTIMER_PSR_PBYP_MASK;
}

/**
 * @brief Select AONTIMER mdoule clock source
 *
 * @param pAontimer the base address of the pAontimer instance.
 * @param eClk Aontimer clock source
 */
LOCAL_INLINE void AONTIMER_HWA_SelectModuleClkSrc(AONTIMER_Type *const pAontimer, AONTIMER_ClkSrcType eClk)
{
    uint32_t u32RegValue = pAontimer->PSR;
    pAontimer->PSR = ((u32RegValue & ~(uint32_t)AONTIMER_PSR_PCS_MASK) | AONTIMER_PSR_PCS(eClk));
}

/**
 * @brief Set AONTIMER module stop on debug mode
 *
 * @param pAontimer the base address of the pAontimer instance.
 */
LOCAL_INLINE void AONTIMER_HWA_SetModuleStopOnDebug(AONTIMER_Type *const pAontimer)
{
    pAontimer->CSR &= ~(uint32_t)(AONTIMER_CSR_DBGEN_MASK | AONTIMER_CSR_TCF_MASK);
}


/**
 * @brief Disable AONTIMER module interrupt
 *
 * @param pAontimer the base address of the pAontimer instance.
 */
LOCAL_INLINE void AONTIMER_HWA_DisableModuleInterrupt(AONTIMER_Type *const pAontimer)
{
    pAontimer->CSR &= ~(uint32_t)(AONTIMER_CSR_TIE_MASK | AONTIMER_CSR_TCF_MASK);
}

/**
 * @brief Clear AONTIMER module mode
 *
 * @param pAontimer the base address of the pAontimer instance.
 */
LOCAL_INLINE void AONTIMER_HWA_ClearModuleMode(AONTIMER_Type *const pAontimer)
{
    pAontimer->CSR &= ~(uint32_t)(AONTIMER_CSR_TPS_MASK | AONTIMER_CSR_TCF_MASK);
}

/**
 * @brief Clear AONTIMER module polarity. Pulse counter input source is active-high, and the CNR increments on rising-edge.
 *
 * @param pAontimer the base address of the pAontimer instance.
 */
LOCAL_INLINE void AONTIMER_HWA_ClearModulePolarity(AONTIMER_Type *const pAontimer)
{
    pAontimer->CSR &= ~(uint32_t)(AONTIMER_CSR_TPP_MASK | AONTIMER_CSR_TCF_MASK);
}

/**
 * @brief Disable AONTIEMR module pulse mode
 *
 * @param pAontimer the base address of the pAontimer instance.
 */
LOCAL_INLINE void AONTIMER_HWA_DisablePulseMode(AONTIMER_Type *const pAontimer)
{
    pAontimer->CSR &= ~(uint32_t)(AONTIMER_CSR_TMS_MASK | AONTIMER_CSR_TCF_MASK);
}

/**
 * @brief Disable AONTIMER module timer
 *
 * @param pAontimer the base address of the pAontimer instance.
 */
LOCAL_INLINE void AONTIMER_HWA_DisableTimer(AONTIMER_Type *const pAontimer)
{
    pAontimer->CSR &= ~(uint32_t)(AONTIMER_CSR_TEN_MASK | AONTIMER_CSR_TCF_MASK);
}

/**
 * @brief Clear AONTIMER module prescaler
 *
 * @param pAontimer the base address of the pAontimer instance.
 */
LOCAL_INLINE void AONTIMER_HWA_ClearPrescale(AONTIMER_Type *const pAontimer)
{
    pAontimer->PSR &= ~(uint32_t)AONTIMER_PSR_PRESCALE_MASK;
}

/**
 * @brief If disable bypass mode, the timer will enable the prescaler in timer counter mode or glitch filter in pulse mode
 *
 * @param pAontimer the base address of the pAontimer instance.
 */
LOCAL_INLINE void AONTIMER_HWA_DisableBypassMode(AONTIMER_Type *const pAontimer)
{
    pAontimer->PSR &= ~(uint32_t)AONTIMER_PSR_PBYP_MASK;
}

/**
 * @brief Clear AONTIMER module clock source
 *
 * @param pAontimer the base address of the pAontimer instance.
 */
LOCAL_INLINE void AONTIMER_HWA_ClearModuleClkSrc(AONTIMER_Type *const pAontimer)
{
    pAontimer->PSR &= ~(uint32_t)AONTIMER_PSR_PCS_MASK;
}

/** @}*/ /* HwA_AONTIMER */

#endif /* #if AONTIMER_INSTANCE_COUNT > 0U */

#endif /* HWA_INCLUDE_HWA_AONTIMER_H_ */
