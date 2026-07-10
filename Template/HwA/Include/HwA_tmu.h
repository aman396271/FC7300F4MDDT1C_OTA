/**
 * @file HwA_tmu.h
 * @author Flagchip
 * @brief Hardware access layer for TMU
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
   *   0.1.0      2023-12-15     Flagchip074   N/A          First version for FC7300
   *   2.0.0      2024-10-12     Flagchip074   N/A          Change version and release
   ******************************************************************************** */

#ifndef _HWA_TMU_H
#define _HWA_TMU_H

#include "device_header.h"

#if TMU_INSTANCE_COUNT > 0U

/**
 * @defgroup HwA_tmu HwA_tmu
 * @ingroup module_driver_tmu
 * @{
 */

/**
 * @brief Select the TF_CTRL and TV_CTRL register is lock or not
 *
 */
typedef enum
{
    TMU_TF_TV_LOCK   = 0U,  /*!< TF_CTRL and TV_CTRL register is lock*/
    TMU_TF_TV_UNLOCK = 1U   /*!< TF_CTRL and TV_CTRL register is unlock*/
}TMU_LockType;

/**
 * @brief Select the Flag-based temperature sensor hysteresis control
 *
 */
typedef enum
{
    TMU_TF_HYSOFF_ON  = 0U,  /*!< Flag-based temperature sensor hysteresis is on*/
    TMU_TF_HYSOFF_OFF = 1U   /*!< Flag-based temperature sensor hysteresis is off*/
}TMU_HysteresisType;

/**
 * @brief Select the Flag-based temperature sensor filter control
 *
 */
typedef enum
{
    TMU_TF_FILT_BYP_BYPASSED  = 0U,  /*!< Flag-based temperature sensor filter is bypassed*/
    TMU_TF_FILT_BYP_ENABLED   = 1U   /*!< Flag-based temperature sensor filter is enabled*/
}TMU_bypassType;

/**
 * @brief Get the status of whether the temperature sensor register is locked
 *
 * @param pTmu the base address of the TMU instance
 * @return true Temperature register is locked(CTRL)
 * @return false Temperature register is unlocked(CTRL)
 */
LOCAL_INLINE TMU_LockType TMU_HWA_GetTemperatureLockStatus(const TMU_Type *const pTmu)
{
    uint32_t u32TmpVal = (pTmu->UNLOCK & TMU_UNLOCK_UNLOCK_MASK) >> TMU_UNLOCK_UNLOCK_SHIFT;
    return (TMU_LockType)u32TmpVal;
}

/**
 * @brief Set the status of whether the temperature sensor register is locked or not
 *
 * @param pTmu the base address of the TMU instance
 * @param eLockStatus Select the TF_CTRL and TV_CTRL register is lock or not
 */
LOCAL_INLINE void TMU_HWA_SetTemperatureLockStatus(TMU_Type *const pTmu,TMU_LockType eLockStatus)
{
    if((bool)eLockStatus)
    {
        pTmu->UNLOCK = 0xA5A50000U | TMU_UNLOCK_UNLOCK(eLockStatus);
    }else
    {
        pTmu->UNLOCK = TMU_UNLOCK_UNLOCK(eLockStatus);
    }
}

#if !TMU_SUPPORT_TV_ECMP
/**
 * @brief Get the Flag-based temperature sensor over 150 Celsius interrupt flag
 *
 * @param pTmu the base address of the TMU instance
 * @return true Temperature over 150 Celsius interrupt is enabled
 * @return false Temperature over 150 Celsius interrupt is disabled
 */
LOCAL_INLINE bool TMU_HWA_GetFlagTemperature150InterruptFlag(const TMU_Type *const pTmu)
{
    uint32_t u32TmpVal = (pTmu->TF_CTRL & TMU_TF_CTRL_TF_150F_IE_MASK) >> TMU_TF_CTRL_TF_150F_IE_SHIFT;
    return (bool)((u32TmpVal != 0U) ? true : false);
}

/**
 * @brief Set the Flag-based temperature sensor over 150 Celsius interrupt flag
 *
 * @param pTmu the base address of the TMU instance
 * @param bEnable whether to enable the temperature over 150 Celsius interrupt
 */
LOCAL_INLINE void TMU_HWA_SetFlagTemperature150InterruptFlag(TMU_Type *const pTmu,bool bEnable)
{
    pTmu->TF_CTRL = (pTmu->TF_CTRL & ~TMU_TF_CTRL_TF_150F_IE_MASK) | TMU_TF_CTRL_TF_150F_IE(bEnable);
}

/**
 * @brief Get the Flag-based temperature sensor over 125 Celsius interrupt flag
 *
 * @param pTmu the base address of the TMU instance
 * @return true Temperature over 125 Celsius interrupt is enabled
 * @return false Temperature over 125 Celsius interrupt is disabled
 */
LOCAL_INLINE bool TMU_HWA_GetFlagTemperature125InterruptFlag(const TMU_Type *const pTmu)
{
    uint32_t u32TmpVal = (pTmu->TF_CTRL & TMU_TF_CTRL_TF_125F_IE_MASK) >> TMU_TF_CTRL_TF_125F_IE_SHIFT;
    return (bool)((u32TmpVal != 0U) ? true : false);
}

/**
 * @brief Set the Flag-based temperature sensor over 125 Celsius interrupt flag
 *
 * @param pTmu the base address of the TMU instance
 * @param bEnable whether to enable the temperature over 125 Celsius interrupt
 */
LOCAL_INLINE void TMU_HWA_SetFlagTemperature125InterruptFlag(TMU_Type *const pTmu,bool bEnable)
{
    pTmu->TF_CTRL = (pTmu->TF_CTRL & ~TMU_TF_CTRL_TF_125F_IE_MASK) | TMU_TF_CTRL_TF_125F_IE(bEnable);
}

/**
 * @brief Get the Flag-based temperature sensor ready interrupt flag
 *
 * @param pTmu the base address of the TMU instance
 * @return true Temperature sensor ready interrupt is enabled
 * @return false Temperature sensor ready interrupt is disabled
 */
LOCAL_INLINE bool TMU_HWA_GetFlagTemperatureReadyInterruptFlag(const TMU_Type *const pTmu)
{
    uint32_t u32TmpVal = (pTmu->TF_CTRL & TMU_TF_CTRL_TF_RDYF_IE_MASK) >> TMU_TF_CTRL_TF_RDYF_IE_SHIFT;
    return (bool)((u32TmpVal != 0U) ? true : false);
}

/**
 * @brief Set the Flag-based temperature sensor over ready interrupt flag
 *
 * @param pTmu the base address of the TMU instance
 * @param bEnable whether to enable the temperature sensor ready interrupt
 */
LOCAL_INLINE void TMU_HWA_SetFlagTemperatureReadyInterruptFlag(TMU_Type *const pTmu,bool bEnable)
{
    pTmu->TF_CTRL = (pTmu->TF_CTRL & ~TMU_TF_CTRL_TF_RDYF_IE_MASK) | TMU_TF_CTRL_TF_RDYF_IE(bEnable);
}

/**
 * @brief Get the Flag-based temperature sensor hysteresis control status
 *
 * @param pTmu the base address of the TMU instance
 * @return true Temperature sensor Hysteresis is off
 * @return false Temperature sensor Hysteresis is on
 */
LOCAL_INLINE bool TMU_HWA_GetFlagTemperatureHysteresisStatus(const TMU_Type *const pTmu)
{
    uint32_t u32TmpVal = (pTmu->TF_CTRL & TMU_TF_CTRL_TF_HYSOFF_MASK) >> TMU_TF_CTRL_TF_HYSOFF_SHIFT;
    return (bool)((u32TmpVal != 0U) ? true : false);
}

/**
 * @brief Set the Flag-based temperature sensor hysteresis control status
 *
 * @param pTmu the base address of the TMU instance
 * @param bEnable whether to off(1)/on(0) the temperature sensor hysteresis
 */
LOCAL_INLINE void TMU_HWA_SetFlagTemperatureHysteresisStatus(TMU_Type *const pTmu,bool bEnable)
{
    pTmu->TF_CTRL = (pTmu->TF_CTRL & ~TMU_TF_CTRL_TF_HYSOFF_MASK) | TMU_TF_CTRL_TF_HYSOFF(bEnable);
}

/**
 * @brief Get the Flag-based temperature sensor startup counter
 *
 * @param pTmu the base address of the TMU instance
 * @return u32TmpVal count of the startup
 */
LOCAL_INLINE uint8_t TMU_HWA_GetFlagTemperatureCounter(const TMU_Type *const pTmu)
{
    uint32_t u32TmpVal = (pTmu->TF_CTRL & TMU_TF_CTRL_TF_START_CNT_MASK) >> TMU_TF_CTRL_TF_START_CNT_SHIFT;
    return (uint8_t)u32TmpVal;
}

/**
 * @brief Set the Flag-based temperature sensor startup counter
 *
 * @param pTmu the base address of the TMU instance
 * @param u8Counter the startup counter
 */
LOCAL_INLINE void TMU_HWA_SetFlagTemperatureCounter(TMU_Type *const pTmu,uint8_t u8Counter)
{
    pTmu->TF_CTRL = (pTmu->TF_CTRL & ~TMU_TF_CTRL_TF_START_CNT_MASK) | TMU_TF_CTRL_TF_START_CNT(u8Counter);
}

#ifdef TMU_SUPPORT_STOP
/**
 * @brief Configure the stop mode of the Flag-based temperature sensor
 *
 * @param pTmu the base address of the TMU instance
 * @param bEnable whether the Flag-based temperature sensor is run in stop mode
 */
LOCAL_INLINE void TMU_HWA_ConfigFlagTemperatureStopMode(TMU_Type *const pTmu,bool bEnable)
{
    pTmu->TF_CTRL = (pTmu->TF_CTRL & ~TMU_TF_CTRL_TF_STOP_EN_MASK) | TMU_TF_CTRL_TF_STOP_EN(bEnable);
}
#endif

/**
 * @brief Get the Flag-based temperature sensor filter bypass control status
 *
 * @param pTmu the base address of the TMU instance
 * @return true Temperature sensor Filter is enabled
 * @return false Temperature sensor Filter is bypassed
 */
LOCAL_INLINE bool TMU_HWA_GetFlagTemperatureFilterBypassStatus(const TMU_Type *const pTmu)
{
    uint32_t u32TmpVal = (pTmu->TF_CTRL & TMU_TF_CTRL_TF_FILT_BYP_MASK) >> TMU_TF_CTRL_TF_FILT_BYP_SHIFT;
    return (bool)((u32TmpVal != 0U) ? true : false);
}

/**
 * @brief Set the Flag-based temperature sensor filter bypass control status
 *
 * @param pTmu the base address of the TMU instance
 * @param bEnable whether the temperature sensor filter is enabled(1) or bypassed(0)
 */
LOCAL_INLINE void TMU_HWA_SetFlagTemperatureFilterBypassStatus(TMU_Type *const pTmu,bool bEnable)
{
    pTmu->TF_CTRL = (pTmu->TF_CTRL & ~TMU_TF_CTRL_TF_FILT_BYP_MASK) | TMU_TF_CTRL_TF_FILT_BYP(bEnable);
}

/**
 * @brief Get the Flag-based temperature sensor enable status
 *
 * @param pTmu the base address of the TMU instance
 * @return true Temperature sensor is on
 * @return false Temperature sensor is off
 */
LOCAL_INLINE bool TMU_HWA_GetFlagTemperatureEnableStatus(const TMU_Type *const pTmu)
{
    uint32_t u32TmpVal = (pTmu->TF_CTRL & TMU_TF_CTRL_TF_EN_MASK) >> TMU_TF_CTRL_TF_EN_SHIFT;
    return (bool)((u32TmpVal != 0U) ? true : false);
}

/**
 * @brief Set the Flag-based temperature sensor enable status
 *
 * @param pTmu the base address of the TMU instance
 * @param bEnable whether the temperature sensor is on(1) or off(0)
 */
LOCAL_INLINE void TMU_HWA_SetFlagTemperatureEnableStatus(TMU_Type *const pTmu,bool bEnable)
{
    pTmu->TF_CTRL = (pTmu->TF_CTRL & ~TMU_TF_CTRL_TF_EN_MASK) | TMU_TF_CTRL_TF_EN(bEnable);
}

/**
 * @brief Check whether the temperature is over 150 Celsius
 *
 * @param pTmu the base address of the TMU instance
 * @return true the temperature is over 150 Celsius
 * @return false the temperature is not over 150 Celsius
 */
LOCAL_INLINE bool TMU_HWA_Get150Status(TMU_Type *const pTmu)
{
    uint32_t u32TmpVal = pTmu->TF_STATUS;
    u32TmpVal = (u32TmpVal & TMU_TF_STATUS_TF_150_MASK) >> TMU_TF_STATUS_TF_150_SHIFT;

    return (bool)((u32TmpVal != 0U) ? true : false);
}

/**
 * @brief Check whether the temperature is over 125 Celsius
 *
 * @param pTmu the base address of the TMU instance
 * @return true the temperature is over 125 Celsius
 * @return false the temperature is not over 125 Celsius
 */
LOCAL_INLINE bool TMU_HWA_Get125Status(TMU_Type *const pTmu)
{
    uint32_t u32TmpVal = pTmu->TF_STATUS;
    u32TmpVal = (u32TmpVal & TMU_TF_STATUS_TF_125_MASK) >> TMU_TF_STATUS_TF_125_SHIFT;

    return (bool)((u32TmpVal != 0U) ? true : false);
}

/**
 * @brief Check whether the flag for temperature over 150 Celsius is set
 *
 * @param pTmu the base address of the TMU instance
 * @return true the temperature has exceeded 150 Celsius since last time W1C
 * @return false the temperature has not exceeded 150 Celsius since TF is ready
 */
LOCAL_INLINE bool TMU_HWA_Get150Flag(TMU_Type *const pTmu)
{
    uint32_t u32TmpVal = pTmu->TF_STATUS;
    u32TmpVal = (u32TmpVal & TMU_TF_STATUS_TF_150F_MASK) >> TMU_TF_STATUS_TF_150F_SHIFT;

    return (bool)((u32TmpVal != 0U) ? true : false);
}

/**
 * @brief Clear the temperature over 150 Celsius flag
 *
 * @param pTmu the base address of the TMU instance
 */
LOCAL_INLINE void TMU_HWA_Clear150Flag(TMU_Type *const pTmu)
{
    pTmu->TF_STATUS = TMU_TF_STATUS_TF_150F(1U);
}

/**
 * @brief Check whether the flag for temperature over 125 Celsius is set
 *
 * @param pTmu the base address of the TMU instance
 * @return true the temperature has exceeded 125 Celsius since last time W1C
 * @return false the temperature has not exceeded 125 Celsius since TF is ready
 */
LOCAL_INLINE bool TMU_HWA_Get125Flag(TMU_Type *const pTmu)
{
    uint32_t u32TmpVal = pTmu->TF_STATUS;
    u32TmpVal = (u32TmpVal & TMU_TF_STATUS_TF_125F_MASK) >> TMU_TF_STATUS_TF_125F_SHIFT;

    return (bool)((u32TmpVal != 0U) ? true : false);
}

/**
 * @brief Clear the temperature over 125 Celsius flag
 *
 * @param pTmu the base address of the TMU instance
 */
LOCAL_INLINE void TMU_HWA_Clear125Flag(TMU_Type *const pTmu)
{
    pTmu->TF_STATUS = TMU_TF_STATUS_TF_125F(1U);
}

/**
 * @brief Check whether the Flag-based temperature sensor is ready
 *
 * @param pTmu the base address of the TMU instance
 * @return true the Flag-based temperature sensor is ready
 * @return false the Flag-based temperature sensor is not ready
 */
LOCAL_INLINE bool TMU_HWA_GetFlagTemperatureReady(TMU_Type *const pTmu)
{
    uint32_t u32TmpVal = pTmu->TF_STATUS;
    u32TmpVal = (u32TmpVal & TMU_TF_STATUS_TF_RDYF_MASK) >> TMU_TF_STATUS_TF_RDYF_SHIFT;

    return (bool)((u32TmpVal != 0U) ? true : false);
}

/**
 * @brief Clear the Flag-based temperature sensor ready flag
 *
 * @param pTmu the base address of the TMU instance
 */
LOCAL_INLINE void TMU_HWA_ClearFlagTemperatureReady(TMU_Type *const pTmu)
{
    pTmu->TF_STATUS = TMU_TF_STATUS_TF_RDYF(1U);
}

/**
 * @brief Get the Vlotage-based temperature sensor ready interrupt flag
 *
 * @param pTmu the base address of the TMU instance
 * @return true Temperature sensor ready interrupt is enabled
 * @return false Temperature sensor ready interrupt is disabled
 */
LOCAL_INLINE bool TMU_HWA_GetVoltageTemperatureReadyInterruptFlag(const TMU_Type *const pTmu)
{
    uint32_t u32TmpVal = (pTmu->TV_CTRL & TMU_TV_CTRL_TV_RDYF_IE_MASK) >> TMU_TV_CTRL_TV_RDYF_IE_SHIFT;
    return (bool)((u32TmpVal != 0U) ? true : false);
}

/**
 * @brief Set the Voltage-based temperature sensor over ready interrupt flag
 *
 * @param pTmu the base address of the TMU instance
 * @param bEnable whether to enable the temperature sensor ready interrupt
 */
LOCAL_INLINE void TMU_HWA_SetVoltageTemperatureReadyInterruptFlag(TMU_Type *const pTmu,bool bEnable)
{
    pTmu->TV_CTRL = (pTmu->TV_CTRL & ~TMU_TV_CTRL_TV_RDYF_IE_MASK) | TMU_TV_CTRL_TV_RDYF_IE(bEnable);
}

/**
 * @brief Get the Voltage-based temperature sensor startup counter
 *
 * @param pTmu the base address of the TMU instance
 * @return u32TmpVal count of the startup
 */
LOCAL_INLINE uint8_t TMU_HWA_GetVoltageTemperatureCounter(const TMU_Type *const pTmu)
{
    uint32_t u32TmpVal = (pTmu->TV_CTRL & TMU_TV_CTRL_TV_START_CNT_MASK) >> TMU_TV_CTRL_TV_START_CNT_SHIFT;
    return (uint8_t)u32TmpVal;
}

/**
 * @brief Set the Voltage-based temperature sensor startup counter
 *
 * @param pTmu the base address of the TMU instance
 * @param u8Counter the startup counter
 */
LOCAL_INLINE void TMU_HWA_SetVoltageTemperatureCounter(TMU_Type *const pTmu,uint8_t u8Counter)
{
    pTmu->TV_CTRL = (pTmu->TV_CTRL & ~TMU_TV_CTRL_TV_START_CNT_MASK) | TMU_TV_CTRL_TV_START_CNT(u8Counter);
}
#endif

#if TMU_SUPPORT_TV_ECMP
/**
 * @brief Get the Vlotage-based temperature sensor compare flag 1 interrupt enable status
 *
 * @param pTmu the base address of the TMU instance
 * @return true Temperature sensor compare flag 1 interrupt is enabled
 * @return false Temperature sensor compare flag 1 interrupt is disabled
 */
LOCAL_INLINE bool TMU_HWA_GetVoltageTemperatureCompare1InterruptEnableStatus(const TMU_Type *const pTmu)
{
    uint32_t u32TmpVal = (pTmu->TV_CTRL & TMU_TV_CTRL_TV_CMP1F_IE_MASK) >> TMU_TV_CTRL_TV_CMP1F_IE_SHIFT;
    return (bool)((u32TmpVal != 0U) ? true : false);
}

/**
 * @brief Get the Vlotage-based temperature sensor compare flag 0 interrupt enable status
 *
 * @param pTmu the base address of the TMU instance
 * @return true Temperature sensor compare flag 0 interrupt is enabled
 * @return false Temperature sensor compare flag 0 interrupt is disabled
 */
LOCAL_INLINE bool TMU_HWA_GetVoltageTemperatureCompare0InterruptEnableStatus(const TMU_Type *const pTmu)
{
    uint32_t u32TmpVal = (pTmu->TV_CTRL & TMU_TV_CTRL_TV_CMP0F_IE_MASK) >> TMU_TV_CTRL_TV_CMP0F_IE_SHIFT;
    return (bool)((u32TmpVal != 0U) ? true : false);
}

/**
 * @brief Set the Voltage-based temperature sensor compare flag 1 interrupt enable status
 *
 * @param pTmu the base address of the TMU instance
 * @param bEnable whether to enable the temperature sensor compare flag 1 interrupt
 */
LOCAL_INLINE void TMU_HWA_SetVoltageTemperatureCompare1InterruptEnableStatus(TMU_Type *const pTmu,bool bEnable)
{
    pTmu->TV_CTRL = (pTmu->TV_CTRL & ~TMU_TV_CTRL_TV_CMP1F_IE_MASK) | TMU_TV_CTRL_TV_CMP1F_IE(bEnable);
}

/**
 * @brief Set the Voltage-based temperature sensor compare flag 0 interrupt enable status
 *
 * @param pTmu the base address of the TMU instance
 * @param bEnable whether to enable the temperature sensor compare flag 0 interrupt
 */
LOCAL_INLINE void TMU_HWA_SetVoltageTemperatureCompare0InterruptEnableStatus(TMU_Type *const pTmu,bool bEnable)
{
    pTmu->TV_CTRL = (pTmu->TV_CTRL & ~TMU_TV_CTRL_TV_CMP0F_IE_MASK) | TMU_TV_CTRL_TV_CMP0F_IE(bEnable);
}
#endif

#ifdef TMU_SUPPORT_STOP
/**
 * @brief Configure the stop mode of the Voltage-based temperature sensor
 *
 * @param pTmu the base address of the TMU instance
 * @param bEnable whether the Voltage-based temperature sensor is run in stop mode
 */
LOCAL_INLINE void TMU_HWA_ConfigVoltageTemperatureStopMode(TMU_Type *const pTmu,bool bEnable)
{
    pTmu->TV_CTRL = (pTmu->TV_CTRL & ~TMU_TV_CTRL_TV_STOP_EN_MASK) | TMU_TV_CTRL_TV_STOP_EN(bEnable);
}
#endif

/**
 * @brief Get the Voltage-based temperature sensor enable status
 *
 * @param pTmu the base address of the TMU instance
 * @return true Temperature sensor is on
 * @return false Temperature sensor is off
 */
LOCAL_INLINE bool TMU_HWA_GetVoltageTemperatureEnableStatus(const TMU_Type *const pTmu)
{
    uint32_t u32TmpVal = (pTmu->TV_CTRL & TMU_TV_CTRL_TV_EN_MASK) >> TMU_TV_CTRL_TV_EN_SHIFT;
    return (bool)((u32TmpVal != 0U) ? true : false);
}

/**
 * @brief Set the Voltage-based temperature sensor enable status
 *
 * @param pTmu the base address of the TMU instance
 * @param bEnable whether the temperature sensor is on(1) or off(0)
 */
LOCAL_INLINE void TMU_HWA_SetVoltageTemperatureEnableStatus(TMU_Type *const pTmu,bool bEnable)
{
    pTmu->TV_CTRL = (pTmu->TV_CTRL & ~TMU_TV_CTRL_TV_EN_MASK) | TMU_TV_CTRL_TV_EN(bEnable);
}

/**
 * @brief Check whether the Voltage-based temperature sensor is ready
 *
 * @param pTmu the base address of the TMU instance
 * @return true the Voltage-based temperature sensor is ready
 * @return false the Voltage-based temperature sensor is not ready
 */
LOCAL_INLINE bool TMU_HWA_GetVoltageTemperatureReady(TMU_Type *const pTmu)
{
    uint32_t u32TmpVal = pTmu->TV_STATUS;
    u32TmpVal = (u32TmpVal & TMU_TV_STATUS_TV_RDYF_MASK) >> TMU_TV_STATUS_TV_RDYF_SHIFT;

    return (bool)((u32TmpVal != 0U) ? true : false);
}

#if TMU_SUPPORT_TV_ECMP
/**
 * @brief Get the Voltage-based temperature sensor compare status 1
 *
 * @param pTmu the base address of the TMU instance
 * @return true the real time status of ADC compare result 1 is assert
 * @return false the real time status of ADC compare result 1 is de-assert
 */
LOCAL_INLINE bool TMU_HWA_GetVoltageTemperatureCompareStatus1(TMU_Type *const pTmu)
{
    uint32_t u32TmpVal = pTmu->TV_STATUS;
    u32TmpVal = (u32TmpVal & TMU_TV_STATUS_TV_CMP1_MASK) >> TMU_TV_STATUS_TV_CMP1_SHIFT;

    return (bool)((u32TmpVal != 0U) ? true : false);
}

/**
 * @brief Get the Voltage-based temperature sensor compare status 0
 *
 * @param pTmu the base address of the TMU instance
 * @return true the real time status of ADC compare result 0 is assert
 * @return false the real time status of ADC compare result 0 is de-assert
 */
LOCAL_INLINE bool TMU_HWA_GetVoltageTemperatureCompareStatus0(TMU_Type *const pTmu)
{
    uint32_t u32TmpVal = pTmu->TV_STATUS;
    u32TmpVal = (u32TmpVal & TMU_TV_STATUS_TV_CMP0_MASK) >> TMU_TV_STATUS_TV_CMP0_SHIFT;

    return (bool)((u32TmpVal != 0U) ? true : false);
}

/**
 * @brief Get the Vlotage-based temperature sensor compare flag 1
 *
 * @param pTmu the base address of the TMU instance
 * @return true Temperature sensor compare flag 1 is asserted
 * @return false Temperature sensor compare flag 1 is not asserted
 */
LOCAL_INLINE bool TMU_HWA_GetVoltageTemperatureCompareFlag1(const TMU_Type *const pTmu)
{
    uint32_t u32TmpVal = pTmu->TV_STATUS;
    u32TmpVal = (u32TmpVal & TMU_TV_STATUS_TV_CMP1F_MASK) >> TMU_TV_STATUS_TV_CMP1F_SHIFT;

    return (bool)((u32TmpVal != 0U) ? true : false);
}

/**
 * @brief Get the Vlotage-based temperature sensor compare flag 0
 *
 * @param pTmu the base address of the TMU instance
 * @return true Temperature sensor compare flag 0 is asserted
 * @return false Temperature sensor compare flag 0 is not asserted
 */
LOCAL_INLINE bool TMU_HWA_GetVoltageTemperatureCompareFlag0(const TMU_Type *const pTmu)
{
    uint32_t u32TmpVal = pTmu->TV_STATUS;
    u32TmpVal = (u32TmpVal & TMU_TV_STATUS_TV_CMP0F_MASK) >> TMU_TV_STATUS_TV_CMP0F_SHIFT;

    return (bool)((u32TmpVal != 0U) ? true : false);
}

/**
 * @brief Clear the Vlotage-based temperature sensor compare flag 1
 *
 * @param pTmu the base address of the TMU instance
 */
LOCAL_INLINE void TMU_HWA_ClearVoltageTemperatureCompareFlag1(TMU_Type *const pTmu)
{
    pTmu->TV_STATUS  = TMU_TV_STATUS_TV_CMP1F(1U);
}

/**
 * @brief Clear the Vlotage-based temperature sensor compare flag 0
 *
 * @param pTmu the base address of the TMU instance
 */
LOCAL_INLINE void TMU_HWA_ClearVoltageTemperatureCompareFlag0(TMU_Type *const pTmu)
{
    pTmu->TV_STATUS  = TMU_TV_STATUS_TV_CMP0F(1U);
}

#endif

#if !TMU_SUPPORT_TV_ECMP
/**
 * @brief Clear the Voltage-based temperature sensor ready flag
 *
 * @param pTmu the base address of the TMU instance
 */
LOCAL_INLINE void TMU_HWA_ClearVoltageTemperatureReady(TMU_Type *const pTmu)
{
    pTmu->TV_STATUS = TMU_TV_STATUS_TV_RDYF(1U);
}

/**
 * @brief Get the TMU_TF_CTRL config
 *
 * @param pTmu the base address of the TMU instance
 * @return uint32_t the TMU_TF_CTRL config
 */
LOCAL_INLINE uint32_t TMU_HWA_GetFlagTempCtrl(const TMU_Type *const pTmu)
{
    return pTmu->TF_CTRL;
}

/**
 * @brief Set the TMU_TF_CTRL config
 *
 * @param pTmu the base address of the TMU instance
 * @param u32Config the TMU_TF_CTRL config
 */
LOCAL_INLINE void TMU_HWA_SetFlagTempCtrl(TMU_Type *const pTmu, uint32_t u32Config)
{
    pTmu->TF_CTRL = u32Config;
}
#endif

/**
 * @brief Get the TMU_TV_CTRL config
 *
 * @param pTmu the base address of the TMU instance
 * @return uint32_t the TMU_TV_CTRL config
 */
LOCAL_INLINE uint32_t TMU_HWA_GetVoltageTempCtrl(const TMU_Type *const pTmu)
{
    return pTmu->TV_CTRL;
}

/**
 * @brief Set the TMU_TV_CTRL config
 *
 * @param pTmu the base address of the TMU instance
 * @param u32Config the TMU_TV_CTRL config
 */
LOCAL_INLINE void TMU_HWA_SetVoltageTempCtrl(TMU_Type *const pTmu, uint32_t u32Config)
{
    pTmu->TV_CTRL = u32Config;
}

#ifdef TMU_SUPPORT_TRIM
/**
 * @brief Get the TV_TRIM_TV_TCODE value
 *
 * @param pTmu the base address of the TMU instance
 * @return uint32_t the TV_TRIM_TV_TCODE value
 */
LOCAL_INLINE uint32_t TMU_HWA_GetTemperatureCode(const TMU_Type *const pTmu)
{
    uint32_t u32TmpVal = pTmu->TV_TRIM;
    u32TmpVal = (u32TmpVal & TMU_TV_TRIM_TV_TCODE_MASK) >> TMU_TV_TRIM_TV_TCODE_SHIFT;
    return u32TmpVal;
}

/**
 * @brief Get the TV_TRIM_TV_SLOPE value
 *
 * @param pTmu the base address of the TMU instance
 * @return uint32_t the TV_TRIM_TV_SLOPE value
 */
LOCAL_INLINE uint32_t TMU_HWA_GetSlopeFactor(const TMU_Type *const pTmu)
{
    uint32_t u32TmpVal = pTmu->TV_TRIM;
    u32TmpVal = (u32TmpVal & TMU_TV_TRIM_TV_SLOPE_MASK) >> TMU_TV_TRIM_TV_SLOPE_SHIFT;
    return u32TmpVal;
}
#endif
/** @}*/

#endif /* #if TMU_INSTANCE_COUNT > 0U */

#endif /* _HWA_TMU_H_ */
