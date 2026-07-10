/**
 * @file HwA_adc.h
 * @author flagchip
 * @brief Hardware access layer for ADC
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
   *   0.1.0       2023-12-15    Flagchip030   N/A          First version for FC7300
   *   2.0.0       2024-10-12    Flagchip030   N/A          Change version and release
   ******************************************************************************** */

#ifndef _HWA_ADC_H_
#define _HWA_ADC_H_

#include "device_header.h"

#if ADC_INSTANCE_COUNT > 0U

/**
 * @defgroup HwA_adc HwA_adc
 * @ingroup module_driver_adc
 * @{
 */

/**
 * @brief Select the ADC Resolution
 *
 */
typedef enum
{
    ADC_RESOLUTION_12_BIT = 0U,  /*!< 12 bit resolution */
    ADC_RESOLUTION_10_BIT = 1U,  /*!< 10 bit resolution */
    ADC_RESOLUTION_8_BIT  = 2U   /*!< 8 bit resolution */
} ADC_ResolutionType;

/**
 * @brief Select the ADC result alignment
 *
 */
typedef enum
{
    ADC_ALIGN_RIGHT = 0U,   /*!< ADC result is aligned in right */
    ADC_ALIGN_LEFT  = 1U    /*!< ADC result is aligned in left */
} ADC_AlignType;

/**
 * @brief Select the ADC trigger mode
 *
 * @note This option is only valid in ADC single sequence mode and ADC continuous mode.
 * In ADC discontinuous mode, the ADC trigger mode is fixed as ADC_TRIGMODE_RISING_EDGE
 *
 */
typedef enum
{
    ADC_TRGMODE_SW                = 0U,  /*!< ADC is triggered by software */
    ADC_TRGMODE_RISING_EDGE       = 1U,  /*!< ADC is triggered by hardware trigger on rising edge */
    ADC_TRGMODE_FALLING_EDGE      = 2U,  /*!< ADC is triggered by hardware trigger on falling edge */
    ADC_TRGMODE_BOTH_EDGE         = 3U,  /*!< ADC is triggered by hardware trigger on both edges */
    ADC_TRGMODE_HIGH_VOLTAGE      = 4U,  /*!< ADC is triggered when hardware trigger is high voltage */
    ADC_TRGMODE_LOW_VOLTAGE       = 5U,  /*!< ADC is triggered when hardware trigger is low voltage */
    #if ADC_SUPPORT_INTERNAL_PERIODIC_TRG
    ADC_TRGMODE_INTERNAL_PERIODIC = 6U   /*!< ADC is triggered by internal generated periodic trigger */
    #endif
} ADC_TrgModeType;

/**
 * @brief Select the ADC sequence mode
 *
 */
typedef enum
{
    ADC_SEQMODE_SINGLE          = 0U,   /*!< ADC single sequence mode */
    ADC_SEQMODE_CONTINUOUS      = 1U,   /*!< ADC continuous mode */
    ADC_SEQMODE_DISCONTINUOUS_0 = 2U,   /*!< ADC discontinuous 0 mode */
    ADC_SEQMODE_DISCONTINUOUS_1 = 3U,   /*!< ADC discontinuous 1 mode */
#if ADC_SUPPORT_SG_MODE
    ADC_SEQMODE_GROUP           = 4U    /*!< ADC sequence group mode */
#endif
} ADC_SeqModeType;

/**
 * @brief Select the ADC overrun management mode
 *
 * To select whether the old data are preserved or overwritten by the new data when ADC
 * is overrun (The FIFO is full when new convertion result comes)
 *
 */
typedef enum
{
    ADC_OVERRUN_MODE_PRESERVE  = 0U, /*!< old data are preserved when ADC is overrun */
    ADC_OVERRUN_MODE_OVERWRITE = 1U  /*!< old data are overwritten when ADC is overrun */
} ADC_OverrunModeType;

#if ADC_SUPPORT_INTERNAL_REFERENCE
/**
 * @brief Select the ADC voltage reference source
 *
 */
typedef enum
{
    ADC_REF_INTERNAL = 0U,   /*!< select the internal voltage reference */
    ADC_REF_EXTERNAL = 1U    /*!< select the external voltage reference */
} ADC_RefType;
#endif

#if ADC_SUPPORT_SG_MODE
/**
 * @brief Select the priority of Trigger Latch Unit
 *
 */
typedef enum
{
    ADC_TRG_LATCH_UNIT_PRI_ROUND_ROBIN = 0U,   /*!< select the round robin scheduling priority */
    ADC_TRG_LATCH_UNIT_PRI_FIX         = 1U    /*!< select the fixed priority(0>1>2>3) */
} ADC_TrgLatchUnitPri;
#endif

/**
 * @brief Select the ADC hardware average samples
 *
 */
typedef enum
{
    ADC_AVERAGE_LEN_4  = 0U,  /*!< result average by 4 samples */
    ADC_AVERAGE_LEN_8  = 1U,  /*!< result average by 8 samples */
    ADC_AVERAGE_LEN_16 = 2U,  /*!< result average by 16 samples */
    ADC_AVERAGE_LEN_32 = 3U   /*!< result average by 32 samples */
} ADC_AverageLenType;

/**
 * @brief Set the ADC clock divider
 *
 * @note ADC clock divider is not available in FC7300F512K
 *
 */
typedef enum
{
    ADC_CLOCK_DIV_1 = 0U,
    ADC_CLOCK_DIV_2 = 1U,
    ADC_CLOCK_DIV_4 = 2U,
    ADC_CLOCK_DIV_8 = 3U
} ADC_ClockDivideType;

/**
 * @brief The trigger source of the ADC instance
 *
 * @note In ADC discontinuous 1 mode, the trigger source is from Ptimer
 * In ADC single and continuous mode, if hardware trigger is enabled, the trigger
 * source is from TRGSEL
 *
 */
typedef enum
{
    ADC_TRGSRC_PTIMER = 0U,         /**< Trigger source from PTIMER/TRGSEL with Ptimer */
    ADC_TRGSRC_TRGSEL = 2U,         /**< Trigger source from TRGSEL */
#if ADC_SUPPORT_SG_MODE
    ADC_TRGSRC_TRG_LATCH_UNIT = 3U  /**< Trigger source from Trigger Latch Unit */
#endif
} ADC_TrgSrcType;

/**
 * @brief Select the channel compare mode
 *
 * Select whether the channel compare is enabled on all channels or on the single
 * selected channel
 *
 */
typedef enum
{
    ADC_CMP_CHANNEL_ALL    = 0U,  /*!< Compare enabled in all channels */
    ADC_CMP_CHANNEL_SINGLE = 1U   /*!< Compare enabled in the specified channel */
} ADC_CmpChannelType;

/**
 * @brief Select the enhanced compare option
 *
 */
typedef enum
{
    ADC_ECMP_NOT_BETWEEN   = 0U,
    ADC_ECMP_OVER_HIGN     = 1U,
    ADC_ECMP_UNDER_LOW     = 2U,
    ADC_ECMP_BETWEEN       = 3U
} ADC_ECMPOption;

#if ADC_SUPPORT_ENHANCED_CMP_BLOCK
/**
 * @brief The ADC enhanced compare block Index
 *
 */
typedef enum
{
    ADC_ECMP0 = 0U,
    ADC_ECMP1 = 1U,
} ADC_ECMPIndex;
#endif

#if ADC_SUPPORT_FAST_CMP_BLOCK
typedef enum
{
    ADC_FCMP_REFMODE_SW    = 0U,
    ADC_FCMP_REFMODE_RAMP  = 1U,
    ADC_FCMP_REFMODE_ALT   = 2U
} ADC_FCmpRefMode;

typedef enum
{
    ADC_FCMP_RAMPDIR_UP    = 0U,
    ADC_FCMP_RAMPDIR_DOWN  = 1U
} ADC_FCmpRampDir;

typedef enum
{
    ADC_FCMP_RAMPTRGMODE_SW_AUTO  = 0U,
    ADC_FCMP_RAMPTRGMODE_SW_EXT   = 1U,
    ADC_FCMP_RAMPTRGMODE_EXT_AUTO = 2U
} ADC_FCmpRampTrgMode;


typedef enum
{
    ADC_FCMP_RAMPTRGPOL_RISING_OR_HIGH = 0U,
    ADC_FCMP_RAMPTRGPOL_FALLING_OR_LOW = 1U,
} ADC_FCmpRampTrgPolarity;

typedef enum
{
    ADC_FCMP_BFA_A1B0 = 0U,
    ADC_FCMP_BFA_A0B1 = 1U,
} ADC_FCmpBFLAction;
#endif

/**
 * @brief Select the channel compare mode
 *
 * Select whether the channel compare is enabled on all channels or on the single
 * selected channel
 *
 */
typedef enum
{
    ADC_ECMP_CHANNEL_ALL    = 0U,  /*!< Compare enabled in all channels */
    ADC_ECMP_CHANNEL_SINGLE = 1U   /*!< Compare enabled in the specified channel */
} ADC_ECmpChannelType;

#if ADC_SUPPORT_FAST_CMP_BLOCK
/**
 * @brief Check whether detect fast compare falling edge
 *
 * @param pAdc the base address of the ADC instance
 * @return true detect fast compare falling edge
 * @return false not detect fast compare falling edge
 */
LOCAL_INLINE bool ADC_HWA_GetFCRFFlag(const ADC_Type *const pAdc)
{
    uint32_t u32TmpVal = pAdc->INT_STATUS;
    u32TmpVal = (u32TmpVal & ADC_INT_STATUS_FCR_F_MASK) >> ADC_INT_STATUS_FCR_F_SHIFT;

    return (bool)((u32TmpVal != 0U) ? true : false);
}

/**
 * @brief Clear the fast compare falling edge flag
 *
 * @param pAdc the base address of the ADC instance
 */
LOCAL_INLINE void ADC_HWA_ClearFCRFFlag(ADC_Type *const pAdc)
{
    pAdc->INT_STATUS = ADC_INT_STATUS_FCR_F(1U);
}

/**
 * @brief Check whether detect fast compare rising edge
 *
 * @param pAdc the base address of the ADC instance
 * @return true detect fast compare rising edge
 * @return false not detect fast compare rising edge
 */
LOCAL_INLINE bool ADC_HWA_GetFCRRFlag(const ADC_Type *const pAdc)
{
    uint32_t u32TmpVal = pAdc->INT_STATUS;
    u32TmpVal = (u32TmpVal & ADC_INT_STATUS_FCR_R_MASK) >> ADC_INT_STATUS_FCR_R_SHIFT;

    return (bool)((u32TmpVal != 0U) ? true : false);
}

/**
 * @brief Clear the fast compare rising edge flag
 *
 * @param pAdc the base address of the ADC instance
 */
LOCAL_INLINE void ADC_HWA_ClearFCRRFlag(ADC_Type *const pAdc)
{
    pAdc->INT_STATUS = ADC_INT_STATUS_FCR_R(1U);
}

#endif

/**
 * @brief Check whether the data quantity in the FIFO is greater than watermark
 *
 * @param pAdc the base address of the ADC instance
 * @return true the ADC FIFO is ready
 * @return false the ADC FIFO is unready
 */
LOCAL_INLINE bool ADC_HWA_GetFIFOReadyFlag(const ADC_Type *const pAdc)
{
    uint32_t u32TmpVal = pAdc->INT_STATUS;
    u32TmpVal = (u32TmpVal & ADC_INT_STATUS_FIFO_RDY_MASK) >> ADC_INT_STATUS_FIFO_RDY_SHIFT;

    return (bool)((u32TmpVal != 0U) ? true : false);
}

/**
 * @brief Check whether the conversion result is in the comparing range
 *
 * @param pAdc the base address of the ADC instance
 * @return true the conversion result is in the comparing range
 * @return false the conversion result is not in the comparing range
 */
LOCAL_INLINE bool ADC_HWA_GetCmpFlag(const ADC_Type *const pAdc)
{
    uint32_t u32TmpVal = pAdc->INT_STATUS;
    u32TmpVal = (u32TmpVal & ADC_INT_STATUS_ACMP_MASK) >> ADC_INT_STATUS_ACMP_SHIFT;

    return (bool)((u32TmpVal != 0U) ? true : false);
}

/**
 * @brief Clear the compare flag
 *
 * @param pAdc the base address of the ADC instance
 */
LOCAL_INLINE void ADC_HWA_ClearCmpFlag(ADC_Type *const pAdc)
{
    pAdc->INT_STATUS = ADC_INT_STATUS_ACMP(1U);
}

/**
 * @brief Check whether the ADC FIFO is empty
 *
 * @param pAdc the base address of the ADC instance
 * @return true the ADC FIFO is empty
 * @return false the ADC FIFO is not empty
 */
LOCAL_INLINE bool ADC_HWA_GetFIFOEmptyFlag(const ADC_Type *const pAdc)
{
    uint32_t u32TmpVal = pAdc->INT_STATUS;
    u32TmpVal = (u32TmpVal & ADC_INT_STATUS_EMPTY_MASK) >> ADC_INT_STATUS_EMPTY_SHIFT;

    return (bool)((u32TmpVal != 0U) ? true : false);
}

/**
 * @brief Check whether the ADC FIFO is full
 *
 * @param pAdc the base address of the ADC instance
 * @return true the ADC FIFO is full
 * @return false the ADC FIFO is not full
 */
LOCAL_INLINE bool ADC_HWA_GetFIFOFullFlag(const ADC_Type *const pAdc)
{
    uint32_t u32TmpVal = pAdc->INT_STATUS;
    u32TmpVal = (u32TmpVal & ADC_INT_STATUS_FULL_MASK) >> ADC_INT_STATUS_FULL_SHIFT;

    return (bool)((u32TmpVal != 0U) ? true : false);
}

/**
 * @brief Get the overrrun status of the ADC instance
 *
 * @param pAdc the base address of the ADC instance
 * @return true the ADC is in overrun status
 * @return false the ADC is not overrun
 */
LOCAL_INLINE bool ADC_HWA_GetOverrunFlag(const ADC_Type *const pAdc)
{
    uint32_t u32TmpVal = pAdc->INT_STATUS;
    u32TmpVal = (u32TmpVal & ADC_INT_STATUS_OVR_MASK) >> ADC_INT_STATUS_OVR_SHIFT;

    return (bool)((u32TmpVal != 0U) ? true : false);
}

/**
 * @brief Clear the overrun flag of the ADC instance
 *
 * @param pAdc the base address of the ADC instance
 */
LOCAL_INLINE void ADC_HWA_ClearOverrunFlag(ADC_Type *const pAdc)
{
    pAdc->INT_STATUS = ADC_INT_STATUS_OVR(1U);
}

/**
 * @brief Check whether the ADC conversion sequence is finished
 *
 * @param pAdc the base address of the ADC instance
 * @return true the ADC conversion sequence is finished
 * @return false the ADC conversion sequence is unfinished
 */
LOCAL_INLINE bool ADC_HWA_GetEndOfSequenceFlag(const ADC_Type *const pAdc)
{
    uint32_t u32TmpVal = pAdc->INT_STATUS;
    u32TmpVal = (u32TmpVal & ADC_INT_STATUS_EOSEQ_MASK) >> ADC_INT_STATUS_EOSEQ_SHIFT;

    return (bool)((u32TmpVal != 0U) ? true : false);
}

/**
 * @brief Clear the ADC conversion sequence complete flag
 *
 * @param pAdc the base address of the ADC instance
 */
LOCAL_INLINE void ADC_HWA_ClearEndOfSequenceFlag(ADC_Type *const pAdc)
{
    pAdc->INT_STATUS = ADC_INT_STATUS_EOSEQ(1U);
}

/**
 * @brief Check whether the current ADC conversion is finished
 *
 * @param pAdc the base address of the ADC instance
 * @return true the current ADC conversion is finished
 * @return false the current ADC conversion is unfinished
 */
LOCAL_INLINE bool ADC_HWA_GetEndOfConversionFlag(const ADC_Type *const pAdc)
{
    uint32_t u32TmpVal = pAdc->INT_STATUS;
    u32TmpVal = (u32TmpVal & ADC_INT_STATUS_EOC_MASK) >> ADC_INT_STATUS_EOC_SHIFT;

    return (bool)((u32TmpVal != 0U) ? true : false);
}

/**
 * @brief Clear the ADC single conversion complete flag
 *
 * @param pAdc the base address of the ADC instance
 */
LOCAL_INLINE void ADC_HWA_ClearEndOfConversionFlag(ADC_Type *const pAdc)
{
    pAdc->INT_STATUS = ADC_INT_STATUS_EOC(1U);
}

/**
 * @brief Check whether the sampling phase of the current ADC conversion is finished
 *
 * @param pAdc the base address of the ADC instance
 * @return true the sampling phase of the ADC conversion is finished
 * @return false the sampling phase of the ADC conversion is unfinished
 */
LOCAL_INLINE bool ADC_HWA_GetEndOfSampleFlag(const ADC_Type *const pAdc)
{
    uint32_t u32TmpVal = pAdc->INT_STATUS;
    u32TmpVal = (u32TmpVal & ADC_INT_STATUS_EOSMP_MASK) >> ADC_INT_STATUS_EOSMP_SHIFT;

    return (bool)((u32TmpVal != 0U) ? true : false);
}

/**
 * @brief Clear the ADC sampling complete flag
 *
 * @param pAdc the base address of the ADC instance
 */
LOCAL_INLINE void ADC_HWA_ClearEndOfSampleFlag(ADC_Type *const pAdc)
{
    pAdc->INT_STATUS = ADC_INT_STATUS_EOSMP(1U);
}

/**
 * @brief Check whether the ADC instance is ready to operate
 *
 * @param pAdc the base address of the ADC instance
 * @return true the ADC instance is ready for a new conversion
 * @return false the ADC instance is unready
 */
LOCAL_INLINE bool ADC_HWA_GetADCReadyFlag(const ADC_Type *const pAdc)
{
    uint32_t u32TmpVal = pAdc->INT_STATUS;
    u32TmpVal = (u32TmpVal & ADC_INT_STATUS_ADRDY_MASK) >> ADC_INT_STATUS_ADRDY_SHIFT;

    return (bool)((u32TmpVal != 0U) ? true : false);
}

/**
 * @brief Clear the ready flag of the ADC instance
 *
 * @param pAdc the base address of the ADC instance
 */
LOCAL_INLINE void ADC_HWA_ClearADCReadyFlag(ADC_Type *const pAdc)
{
    pAdc->INT_STATUS = ADC_INT_STATUS_ADRDY(1U);
}

/**
 * @brief Clear the ready flag of the ADC instance
 *
 * @param pAdc the base address of the ADC instance
 */
LOCAL_INLINE void ADC_HWA_ClearFlags(ADC_Type *const pAdc, uint32_t u32Flags)
{
    pAdc->INT_STATUS = u32Flags;
}

#if ADC_SUPPORT_FAST_CMP_BLOCK
/**
 * @brief Get the fast compare falling edge interrupt
 * If enabled, ADC interrupt is generated when detect fast compare falling edge
 * @param pAdc the base address of the ADC instance
 * @return true fast compare falling interrupt is enabled
 * @return false fast compare falling interrupt is disabled
 */
LOCAL_INLINE bool ADC_HWA_GetFCRFIntEnable(const ADC_Type *const pAdc)
{
    uint32_t u32TmpVal = (pAdc->INT_ENABLE & ADC_INT_ENABLE_FCR_F_IE_MASK) >> ADC_INT_ENABLE_FCR_F_IE_SHIFT;
    return (bool)((u32TmpVal != 0U) ? true : false);
}

/**
 * @brief Set the fast compare falling edge interrupt
 * If enabled, ADC interrupt is generated when detect fast compare falling edge
 * @param pAdc the base address of the ADC instance
 * @param bEnable whether to enable the fast compare falling interrupt
 */
LOCAL_INLINE void ADC_HWA_SetFCRFIntEnable(ADC_Type *const pAdc, bool bEnable)
{
    pAdc->INT_ENABLE = (pAdc->INT_ENABLE & ~ADC_INT_ENABLE_FCR_F_IE_MASK) | ADC_INT_ENABLE_FCR_F_IE(bEnable);
}

/**
 * @brief Get the fast compare rising edge interrupt
 * If enabled, ADC interrupt is generated when detect fast compare rising edge
 * @param pAdc the base address of the ADC instance
 * @return true fast compare rising interrupt is enabled
 * @return false fast compare rising interrupt is disabled
 */
LOCAL_INLINE bool ADC_HWA_GetFCRRIntEnable(const ADC_Type *const pAdc)
{
    uint32_t u32TmpVal = (pAdc->INT_ENABLE & ADC_INT_ENABLE_FCR_R_IE_MASK) >> ADC_INT_ENABLE_FCR_R_IE_SHIFT;
    return (bool)((u32TmpVal != 0U) ? true : false);
}

/**
 * @brief Set the fast compare rising edge interrupt
 * If enabled, ADC interrupt is generated when detect fast compare rising edge
 * @param pAdc the base address of the ADC instance
 * @param bEnable whether to enable the fast compare rising interrupt
 */
LOCAL_INLINE void ADC_HWA_SetFCRRIntEnable(ADC_Type *const pAdc, bool bEnable)
{
    pAdc->INT_ENABLE = (pAdc->INT_ENABLE & ~ADC_INT_ENABLE_FCR_R_IE_MASK) | ADC_INT_ENABLE_FCR_R_IE(bEnable);
}
#endif

/**
 * @brief Get the FIFO Ready interrupt flag
 * If enabled, ADC interrupt is generated when the FIFO water mark is greater than FWMARK
 * @param pAdc the base address of the ADC instance
 * @return true ADC FIFO Ready interrupt is enabled
 * @return false ADC FIFO Ready interrupt is disabled
 */
LOCAL_INLINE bool ADC_HWA_GetFIFOReadyIntEnable(const ADC_Type *const pAdc)
{
    uint32_t u32TmpVal = (pAdc->INT_ENABLE & ADC_INT_ENABLE_FIFO_RDY_IE_MASK) >> ADC_INT_ENABLE_FIFO_RDY_IE_SHIFT;
    return (bool)((u32TmpVal != 0U) ? true : false);
}

/**
 * @brief Set the FIFO Ready interrupt flag
 * If enabled, ADC interrupt is generated when the FIFO water mark is greater than FWMARK
 * @param pAdc the base address of the ADC instance
 * @param bEnable whether to enable the ADC FIFO Ready interrupt
 */
LOCAL_INLINE void ADC_HWA_SetFIFOReadyIntEnable(ADC_Type *const pAdc, bool bEnable)
{
    pAdc->INT_ENABLE = (pAdc->INT_ENABLE & ~ADC_INT_ENABLE_FIFO_RDY_IE_MASK) | ADC_INT_ENABLE_FIFO_RDY_IE(bEnable);
}

/**
 * @brief Get the Compare interrupt flag
 * If enabled, ADC interrupt is generated when the ADC conversion result is not within the compare threshold
 * @param pAdc the base address of the ADC instance
 * @return true ADC Compare interrupt is enabled
 * @return false ADC Compare interrupt is disabled
 */
LOCAL_INLINE bool ADC_HWA_GetCmpIntEnable(const ADC_Type *const pAdc)
{
    uint32_t u32TmpVal = (pAdc->INT_ENABLE & ADC_INT_ENABLE_ACMP_IE_MASK) >> ADC_INT_ENABLE_ACMP_IE_SHIFT;
    return (bool)((u32TmpVal != 0U) ? true : false);
}

/**
 * @brief Set the Compare interrupt flag
 * If enabled, ADC interrupt is generated when the ADC conversion result is not within the compare threshold
 * @param pAdc the base address of the ADC instance
 * @param bEnable whether to enable the ADC Compare interrupt
 */
LOCAL_INLINE void ADC_HWA_SetCmpIntEnable(ADC_Type *const pAdc, bool bEnable)
{
    pAdc->INT_ENABLE = (pAdc->INT_ENABLE & ~ADC_INT_ENABLE_ACMP_IE_MASK) | ADC_INT_ENABLE_ACMP_IE(bEnable);
}

/**
 * @brief Get the Overrun interrupt flag
 * If enabled, ADC interrupt is generated when the ADC instance is overrun
 * @param pAdc the base address of the ADC instance
 * @return true ADC Overrun interrupt is enabled
 * @return false ADC Overrun interrupt is disabled
 */
LOCAL_INLINE bool ADC_HWA_GetOverrunIntEnable(const ADC_Type *const pAdc)
{
    uint32_t u32TmpVal = (pAdc->INT_ENABLE & ADC_INT_ENABLE_OVRIE_MASK) >> ADC_INT_ENABLE_OVRIE_SHIFT;
    return (bool)((u32TmpVal != 0U) ? true : false);
}

/**
 * @brief Set the Overrun interrupt flag
 * If enabled, ADC interrupt is generated when the ADC instance is overrun
 * @param pAdc the base address of the ADC instance
 * @param bEnable whether to enable the ADC Overrun interrupt
 */
LOCAL_INLINE void ADC_HWA_SetOverrunIntEnable(ADC_Type *const pAdc, bool bEnable)
{
    pAdc->INT_ENABLE = (pAdc->INT_ENABLE & ~ADC_INT_ENABLE_OVRIE_MASK) | ADC_INT_ENABLE_OVRIE(bEnable);
}

/**
 * @brief Get the End of Sequence interrupt enable flag
 * If enabled, ADC interrupt is generated when the ADC sequence conversion is completed
 * @param pAdc the base address of the ADC instance
 * @return true ADC End of Sequence interrupt is enabled
 * @return false ADC End of Sequence interrupt is disabled
 */
LOCAL_INLINE bool ADC_HWA_GetEndOfSequenceIntEnable(const ADC_Type *const pAdc)
{
    uint32_t u32TmpVal = (pAdc->INT_ENABLE & ADC_INT_ENABLE_EOSEQIE_MASK) >> ADC_INT_ENABLE_EOSEQIE_SHIFT;
    return (bool)((u32TmpVal != 0U) ? true : false);
}

/**
 * @brief Set the End of Sequence interrupt enable flag
 * If enabled, ADC interrupt is generated when the ADC sequence conversion is completed
 * @param pAdc the base address of the ADC instance
 * @param bEnable whether to enable the ADC End of Sequence interrupt
 */
LOCAL_INLINE void ADC_HWA_SetEndOfSequenceIntEnable(ADC_Type *const pAdc, bool bEnable)
{
    pAdc->INT_ENABLE = (pAdc->INT_ENABLE & ~ADC_INT_ENABLE_EOSEQIE_MASK) | ADC_INT_ENABLE_EOSEQIE(bEnable);
}

/**
 * @brief Get the conversion complete interrupt enable flag
 * If enabled, ADC interrupt is generated when each ADC conversion is completed
 * @param pAdc the base address of the ADC instance
 * @return true the ADC End of Conversion interrupt is enabled
 * @return false the ADC End of Conversion interrupt is disabled
 */
LOCAL_INLINE bool ADC_HWAGetEndOfConversionIntEnable(const ADC_Type *const pAdc)
{
    uint32_t u32TmpVal = (pAdc->INT_ENABLE & ADC_INT_ENABLE_EOCIE_MASK) >> ADC_INT_ENABLE_EOCIE_SHIFT;
    return (bool)((u32TmpVal != 0U) ? true : false);
}

/**
 * @brief Set the conversion complete interrupt enable flag
 * If enabled, ADC interrupt is generated when each ADC conversion is completed
 * @param pAdc the base address of the ADC instance
 * @param bEnable whether to enable the conversion complete interrupt
 */
LOCAL_INLINE void ADC_HWA_SetEndOfConversionIntEnable(ADC_Type *const pAdc, bool bEnable)
{
    pAdc->INT_ENABLE = (pAdc->INT_ENABLE & ~ADC_INT_ENABLE_EOCIE_MASK) | ADC_INT_ENABLE_EOCIE(bEnable);
}

/**
 * @brief Get the sample complete interrupt enable flag
 * If enabled, ADC interrupt is generated when each ADC conversion finished the sampling phase
 * @param pAdc the base address of the ADC instance
 * @return true the sample complete interrupt is enabled
 * @return false the sample complete interrupt is disabled
 */
LOCAL_INLINE bool ADC_HWA_GetEndOfSampleIntEnable(const ADC_Type *const pAdc)
{
    uint32_t u32TmpVal = (pAdc->INT_ENABLE & ADC_INT_ENABLE_EOSMPIE_MASK) >> ADC_INT_ENABLE_EOSMPIE_SHIFT;
    return (bool)((u32TmpVal != 0U) ? true : false);
}

/**
 * @brief Set the sample complete interrupt enable flag
 * If enabled, ADC interrupt is generated when each ADC conversion finished the sampling phase
 * @param pAdc the base address of the ADC instance
 * @param bEnable whether to enable the sample complete interrupt
 */
LOCAL_INLINE void ADC_HWA_SetEndOfSampleIntEnable(ADC_Type *const pAdc, bool bEnable)
{
    pAdc->INT_ENABLE = (pAdc->INT_ENABLE & ~ADC_INT_ENABLE_EOSMPIE_MASK) | ADC_INT_ENABLE_EOSMPIE(bEnable);
}

/**
 * @brief Get the ADC ready interrupt enable flag
 * If enabled, ADC interrupt is generated when the ADC module is ready for conversion
 * @param pAdc the base address of the ADC instance
 * @return true the ADC ready interrupt is enabled
 * @return false the ADC ready interrupt is disabled
 */
LOCAL_INLINE bool ADC_HWA_GetADCReadyIntEnable(const ADC_Type *const pAdc)
{
    uint32_t u32TmpVal = (pAdc->INT_ENABLE & ADC_INT_ENABLE_ADRDYIE_MASK) >> ADC_INT_ENABLE_ADRDYIE_SHIFT;
    return (bool)((u32TmpVal != 0U) ? true : false);
}

/**
 * @brief Set the ADC ready interrupt enable flag
 * If enabled, ADC interrupt is generated when the ADC module is ready for conversion
 * @param pAdc the base address of the ADC instance
 * @param bEnable Whether to enable the ADC ready interrupt
 */
LOCAL_INLINE void ADC_HWA_SetADCReadyIntEnable(ADC_Type *const pAdc, bool bEnable)
{
    pAdc->INT_ENABLE = (pAdc->INT_ENABLE & ~ADC_INT_ENABLE_ADRDYIE_MASK) | ADC_INT_ENABLE_ADRDYIE(bEnable);
}

/**
 * @brief Get the interrupt enable config
 *
 * @param pAdc the base address of the ADC instance
 * @return uint32_t the interrupt enable config
 */
LOCAL_INLINE uint32_t ADC_HWA_GetIntEnable(const ADC_Type *const pAdc)
{
    return pAdc->INT_ENABLE;
}

/**
 * @brief Set the interrupt enable
 *
 * @param pAdc adc address point
 * @param u32IntCfg the interrupt enable config
 */
LOCAL_INLINE void ADC_HWA_SetIntEnable(ADC_Type *const pAdc, uint32_t u32IntCfg)
{
    pAdc->INT_ENABLE = u32IntCfg;
}

/**
 * @brief Reset the ADC hardware
 *
 * @param pAdc the base address of the ADC instance
 */
LOCAL_INLINE void ADC_HWA_Reset(ADC_Type *const pAdc)
{
    pAdc->CONTROL = ADC_CONTROL_ADRST(1U);
    pAdc->CONTROL = 0U;
}

/**
 * @brief Get whether ADC is in stopping status
 *
 * @param pAdc the base address of the ADC instance
 * @return true the ADC instance is stopping
 * @return false the ADC instance is not in stopping status
 */
LOCAL_INLINE bool ADC_HWA_GetStop(const ADC_Type *const pAdc)
{
    uint32_t u32TmpVal = pAdc->CONTROL;
    u32TmpVal = (u32TmpVal & ADC_CONTROL_ADSTP_MASK) >> ADC_CONTROL_ADSTP_SHIFT;

    return (bool)((u32TmpVal != 0U) ? true : false);
}

/**
 * @brief Stop the ADC conversion
 *
 * @param pAdc the base address of the ADC instance
 */
LOCAL_INLINE void ADC_HWA_Stop(ADC_Type *const pAdc)
{
    pAdc->CONTROL = ADC_CONTROL_ADSTP(1U);
}

/**
 * @brief Get the conversion start status of the ADC instance
 *
 * @param pAdc the base address of the ADC instance
 * @return true the conversion of the ADC instance is started
 * @return false the conversion of the ADC instance has not been started
 */
LOCAL_INLINE bool ADC_HWA_GetStart(const ADC_Type *const pAdc)
{
    uint32_t u32TmpVal = pAdc->CONTROL;
    u32TmpVal = (u32TmpVal & ADC_CONTROL_ADSTART_MASK) >> ADC_CONTROL_ADSTART_SHIFT;

    return (bool)((u32TmpVal != 0U) ? true : false);
}

/**
 * @brief Start the ADC conversion
 *
 * @param pAdc the base address of the ADC instance
 */
LOCAL_INLINE void ADC_HWA_Start(ADC_Type *const pAdc)
{
    pAdc->CONTROL = ADC_CONTROL_ADSTART(1U);
}

/**
 * @brief Get whether the ADC instance is in disable status
 *
 * @param pAdc the base address of the ADC instance
 * @return true the ADC instance is in disable status
 * @return false the ADC instance is not in disable status
 */
LOCAL_INLINE bool ADC_HWA_GetDisable(const ADC_Type *const pAdc)
{
    uint32_t u32TmpVal = pAdc->CONTROL;
    u32TmpVal = (u32TmpVal & ADC_CONTROL_ADDIS_MASK) >> ADC_CONTROL_ADDIS_SHIFT;

    return (bool)((u32TmpVal != 0U) ? true : false);
}

/**
 * @brief Disable the ADC instance
 *
 * @param pAdc the base address of the ADC instance
 */
LOCAL_INLINE void ADC_HWA_Disable(ADC_Type *const pAdc)
{
    pAdc->CONTROL = ADC_CONTROL_ADDIS(1U);
}

/**
 * @brief Get the enable status of the ADC instance
 *
 * @param pAdc the base address of the ADC instance
 * @return true the ADC instance is enabled
 * @return false the ADC instance has not been enabled
 */
LOCAL_INLINE bool ADC_HWA_GetEnable(const ADC_Type *const pAdc)
{
    uint32_t u32TmpVal = pAdc->CONTROL;
    u32TmpVal = (u32TmpVal & ADC_CONTROL_ADEN_MASK) >> ADC_CONTROL_ADEN_SHIFT;

    return (bool)((u32TmpVal != 0U) ? true : false);
}

/**
 * @brief Enable the ADC instance
 *
 * @param pAdc the base address of the ADC instance
 */
LOCAL_INLINE void ADC_HWA_Enable(ADC_Type *const pAdc)
{
    pAdc->CONTROL = ADC_CONTROL_ADEN(1U);
}

#if ADC_SUPPORT_INSTANCE_DIFFMODE_SET
/**
 * @brief Get whether the ADC is in differential mode
 *
 * @note Differential mode is only available in FC7300F2M
 *
 * @param pAdc the base address of the ADC instance
 * @return true the ADC is in differential mode
 * @return false the ADC is not in differential mode
 */
LOCAL_INLINE bool ADC_HWA_GetInstanceDiffModeEnable(const ADC_Type *const pAdc)
{
    uint32_t u32TmpVal = pAdc->CFG1;
    u32TmpVal = (u32TmpVal & ADC_CFG1_DIFF_MASK) >> ADC_CFG1_DIFF_SHIFT;

    return (bool)((u32TmpVal != 0U) ? true : false);
}

/**
 * @brief Set whether to enable the ADC differential mode
 *
 * @note
 *
 * @param pAdc the base address of the ADC instance
 * @param bEnable whether to enable the ADC differential mode
 */
LOCAL_INLINE void ADC_HWA_SetInstanceDiffModeEnable(ADC_Type *const pAdc, bool bEnable)
{
    pAdc->CFG1 = (pAdc->CFG1 & ~ADC_CFG1_DIFF_MASK) | ADC_CFG1_DIFF(bEnable);
}
#endif

/**
 * @brief Get the overrun management mode
 *
 * @param pAdc the base address of the ADC instance
 * @return ADC_OVERRUN_MODE_PRESERVE the conversion data is preserved when ADC is overrun
 * @return ADC_OVERRUN_MODE_OVERWRITE the conversion data is overwritten when ADC is overrun
 */
LOCAL_INLINE ADC_OverrunModeType ADC_HWA_GetOverrunManagementMode(const ADC_Type *const pAdc)
{
    uint32_t u32TmpVal = (pAdc->CFG1 & ADC_CFG1_OVRMOD_MASK) >> ADC_CFG1_OVRMOD_SHIFT;
    return (ADC_OverrunModeType)u32TmpVal;
}

/**
 * @brief Set the overrun management mode
 *
 * @param pAdc the base address of the ADC instance
 * @param eMode the overrun management for the ADC instance
 */
LOCAL_INLINE void ADC_HWA_SetOverrunManagementMode(ADC_Type *const pAdc, ADC_OverrunModeType eMode)
{
    pAdc->CFG1 = (pAdc->CFG1 & ~ADC_CFG1_OVRMOD_MASK) | ADC_CFG1_OVRMOD(eMode);
}

#if ADC_SUPPORT_SG_MODE
/**
 * @brief Get the sequence group mode state
 *
 * @param pAdc the base address of the ADC instance
 * @return the sequence group mode state
 */
LOCAL_INLINE bool ADC_HWA_GetSGEnable(const ADC_Type *const pAdc)
{
    uint32_t u32TmpVal = (pAdc->CFG1 & ADC_CFG1_SEQGP_EN_MASK) >> ADC_CFG1_SEQGP_EN_SHIFT;
    return u32TmpVal ? true : false;
}

/**
 * @brief Set the sequence group mode state
 *
 * @param pAdc the base address of the ADC instance
 * @param the sequence group mode state
 */
LOCAL_INLINE void ADC_HWA_SetSGEnable(ADC_Type *const pAdc, bool bEnable)
{
    pAdc->CFG1 = (pAdc->CFG1 & ~ADC_CFG1_SEQGP_EN_MASK) | ADC_CFG1_SEQGP_EN(bEnable);
}
#endif

/**
 * @brief Get the sequence length of the ADC conversion sequence
 *
 * @param pAdc the base address of the ADC instance
 * @return uint8_t the sequence length of the ADC conversion sequence
 */
LOCAL_INLINE uint8_t ADC_HWA_GetSequenceLength(const ADC_Type *const pAdc)
{
    uint32_t u32TmpVal = pAdc->CFG1;
    u32TmpVal = (u32TmpVal & ADC_CFG1_SEQ_LEN_MASK) >> ADC_CFG1_SEQ_LEN_SHIFT;

    return (uint8_t)u32TmpVal;
}

/**
 * @brief Set the sequence length of the ADC conversion sequence
 *
 * @param pAdc the base address of the ADC instance
 * @param u8SequenceLength the sequence length of the ADC conversion sequence
 */
LOCAL_INLINE void ADC_HWA_SetSequenceLength(ADC_Type *const pAdc, uint8_t u8SequenceLength)
{
    pAdc->CFG1 = (pAdc->CFG1 & ~ADC_CFG1_SEQ_LEN_MASK) | ADC_CFG1_SEQ_LEN(u8SequenceLength);
}

/**
 * @brief Get the ADC sequence mode
 *
 * @param pAdc the base address of the ADC instance
 * @return ADC_SeqModeType the sequence mode the the ADC instance
 */
LOCAL_INLINE ADC_SeqModeType ADC_HWA_GetSequenceMode(const ADC_Type *const pAdc)
{
    uint32_t u32TmpVal = pAdc->CFG1;
    u32TmpVal = (u32TmpVal & ADC_CFG1_SEQ_MOD_MASK) >> ADC_CFG1_SEQ_MOD_SHIFT;

    return (ADC_SeqModeType)u32TmpVal;
}

/**
 * @brief Set the ADC sequence mode
 *
 * @param pAdc the base address of the ADC instance
 * @param eSequenceMode the sequence mode the the ADC instance
 */
LOCAL_INLINE void ADC_HWA_SetSequenceMode(ADC_Type *const pAdc, ADC_SeqModeType eSequenceMode)
{
    pAdc->CFG1 = (pAdc->CFG1 & ~ADC_CFG1_SEQ_MOD_MASK) | ADC_CFG1_SEQ_MOD(eSequenceMode);
}

/**
 * @brief Get whether auto disable is enabled
 *
 * @note Auto disable mode is only available in FC7300F2M
 *
 * @param pAdc the base address of the ADC instance
 * @return true  auto disable mode is enabled
 * @return false auto disable mode is disabled
 */
LOCAL_INLINE bool ADC_HWA_GetAutoDisableModeEnable(const ADC_Type *const pAdc)
{
    uint32_t u32TmpVal = pAdc->CFG1;
    u32TmpVal = (u32TmpVal & ADC_CFG1_AUTO_DIS_MASK) >> ADC_CFG1_AUTO_DIS_SHIFT;

    return (bool)((u32TmpVal != 0U) ? true : false);
}

/**
 * @brief Set whether to enable auto disable mode
 *
 * @note Auto disable mode is only available in FC7300F2M
 *
 * @param pAdc the base address of the ADC instance
 * @param bEnable whether to enable auto disable mode
 */
LOCAL_INLINE void ADC_HWA_SetAutoDisableModeEnable(ADC_Type *const pAdc, bool bEnable)
{
    pAdc->CFG1 = (pAdc->CFG1 & ~ADC_CFG1_AUTO_DIS_MASK) | ADC_CFG1_AUTO_DIS(bEnable);
}

/**
 * @brief Get whether the wait conversion mode is enabled
 *
 * @param pAdc the base address of the ADC instance
 * @return true the wait conversion mode is enabled
 * @return false the wait conversion mode is disabled
 */
LOCAL_INLINE bool ADC_HWA_GetWaitConversionModeEnable(const ADC_Type *const pAdc)
{
    uint32_t u32TmpVal = (pAdc->CFG1 & ADC_CFG1_WAIT_MASK) >> ADC_CFG1_WAIT_SHIFT;
    return (bool)((u32TmpVal != 0U) ? true : false);
}

/**
 * @brief Set the wait conversion mode
 *
 * @param pAdc the base address of the ADC instance
 * @param bEnable whether to enable the wait conversion mode
 */
LOCAL_INLINE void ADC_HWA_SetWaitConversionModeEnable(ADC_Type *const pAdc, bool bEnable)
{
    pAdc->CFG1 = (pAdc->CFG1 & ~ADC_CFG1_WAIT_MASK) | ADC_CFG1_WAIT(bEnable);
}

/**
 * @brief Get the trigger source the the ADC instance
 *
 * @param pAdc the base address of the ADC instance
 * @return ADC_TrigSrcType the trigger source of the ADC instance
 */
LOCAL_INLINE ADC_TrgSrcType ADC_HWA_GetTriggerSource(const ADC_Type *const pAdc)
{
    uint32_t u32TmpVal = pAdc->CFG1;
    u32TmpVal = (u32TmpVal & ADC_CFG1_TRIGSRC_MASK) >> ADC_CFG1_TRIGSRC_SHIFT;

    return (ADC_TrgSrcType)u32TmpVal;
}

/**
 * @brief Set the trigger source the the ADC instance
 *
 * @param pAdc the base address of the ADC instance
 * @param eTriggerSource the trigger source of the ADC instance
 */
LOCAL_INLINE void ADC_HWA_SetTriggerSource(ADC_Type *const pAdc, ADC_TrgSrcType eTrgSource)
{
    pAdc->CFG1 = (pAdc->CFG1 & ~ADC_CFG1_TRIGSRC_MASK) | ADC_CFG1_TRIGSRC(eTrgSource);
}

/**
 * @brief Get the trigger mode of the ADC instance
 *
 * @param pAdc the base address of the ADC instance
 * @return ADC_TrigModeType the trigger mode if the ADC instance
 */
LOCAL_INLINE ADC_TrgModeType ADC_HWA_GetTriggerMode(const ADC_Type *const pAdc)
{
    uint32_t u32TmpVal = pAdc->CFG1;
    u32TmpVal = (u32TmpVal & ADC_CFG1_TRIGMODE_MASK) >> ADC_CFG1_TRIGMODE_SHIFT;

    return (ADC_TrgModeType)u32TmpVal;
}

/**
 * @brief Set the trigger mode of the ADC instance
 *
 * @param pAdc the base address of the ADC instance
 * @param eTriggerMode the trigger mode if the ADC instance
 */
LOCAL_INLINE void ADC_HWA_SetTriggerMode(ADC_Type *const pAdc, ADC_TrgModeType eTrgMode)
{
    pAdc->CFG1 = (pAdc->CFG1 & ~ADC_CFG1_TRIGMODE_MASK) | ADC_CFG1_TRIGMODE(eTrgMode);
}

/**
 * @brief Get the data align mode
 *
 * @param pAdc the base address of the ADC instance
 * @return ADC_ALIGN_RIGHT the conversion data is aligned right
 * @return ADC_ALIGN_LEFT the conversion is aligned left
 */
LOCAL_INLINE ADC_AlignType ADC_HWA_GetDataAlignment(const ADC_Type *const pAdc)
{
    uint32_t u32TmpVal = (pAdc->CFG1 & ADC_CFG1_ALIGN_MASK) >> ADC_CFG1_ALIGN_SHIFT;
    return (ADC_AlignType)u32TmpVal;
}

/**
 * @brief Set the data align mode
 *
 * @param pAdc the base address of the ADC instance
 * @param eAlign the data align mode
 */
LOCAL_INLINE void ADC_HWA_SetDataAlignment(ADC_Type *const pAdc, ADC_AlignType eAlign)
{
    pAdc->CFG1 = (pAdc->CFG1 & ~ADC_CFG1_ALIGN_MASK) | ADC_CFG1_ALIGN(eAlign);
}

/**
 * @brief Get the ADC resolution of the ADC instance
 *
 * @param pAdc the base address of the ADC instance
 * @return ADC_ResolutionType the resolution of the ADC instance
 */
LOCAL_INLINE ADC_ResolutionType ADC_HWA_GetDataResolution(const ADC_Type *const pAdc)
{
    uint32_t u32TmpVal = (pAdc->CFG1 & ADC_CFG1_RES_MASK) >> ADC_CFG1_RES_SHIFT;
    return (ADC_ResolutionType)u32TmpVal;
}

/**
 * @brief Set the resolution of the ADC instance
 *
 * @param pAdc the base address of the ADC instance
 * @param eResolution the resolution of the ADC instance
 */
LOCAL_INLINE void ADC_HWA_SetDataResolution(ADC_Type *const pAdc, ADC_ResolutionType eResolution)
{
    pAdc->CFG1 = (pAdc->CFG1 & ~ADC_CFG1_RES_MASK) | ADC_CFG1_RES(eResolution);
}

/**
 * @brief Get whether DMA for the ADC instance is enabled
 *
 * @param pAdc the base address of the ADC instance
 * @return true DMA is enabled for the ADC instance
 * @return false DMA is disabled for the ADC instance
 */
LOCAL_INLINE bool ADC_HWA_GetDMAEnable(const ADC_Type *const pAdc)
{
    uint32_t u32TmpVal = (pAdc->CFG1 & ADC_CFG1_DMAEN_MASK) >> ADC_CFG1_DMAEN_SHIFT;
    return (bool)((u32TmpVal != 0U) ? true : false);
}

/**
 * @brief Enable or disable the DMA for the ADC instance
 *
 * @param pAdc the base address of the ADC instance
 * @param bEnable whether to enable the DMA for the ADC instance
 */
LOCAL_INLINE void ADC_HWA_SetDMAEnable(ADC_Type *const pAdc, bool bEnable)
{
    pAdc->CFG1 = (pAdc->CFG1 & ~ADC_CFG1_DMAEN_MASK) | ADC_CFG1_DMAEN(bEnable);
}

/**
 * @brief Get the ADC_CFG1 config
 *
 * @param pAdc the base address of the ADC instance
 * @return uint32_t the ADC_CFG1 config
 */
LOCAL_INLINE uint32_t ADC_HWA_GetConfig1(const ADC_Type *const pAdc)
{
    return pAdc->CFG1;
}

/**
 * @brief Set the ADC_CFG1 config
 *
 * @param pAdc the base address of the ADC instance
 * @param u32Config the ADC_CFG1 config
 */
LOCAL_INLINE void ADC_HWA_SetConfig1(ADC_Type *const pAdc, uint32_t u32Config)
{
    pAdc->CFG1 = u32Config;
}

/**
 * @brief Get the FIFO water mark settings for the ADC instance
 *
 * @param pAdc the base address of the ADC instance
 * @return uint8_t the ADC FIFO water mark setting
 */
LOCAL_INLINE uint8_t ADC_HWA_GetFIFOWaterMark(const ADC_Type *const pAdc)
{
    uint32_t u32TmpVal = (pAdc->CFG2 & ADC_CFG2_FWMARK_MASK) >> ADC_CFG2_FWMARK_SHIFT;
    return (uint8_t)u32TmpVal;
}

/**
 * @brief Set the FIFO water mark for the ADC instance
 *
 * @param pAdc the base address of the ADC instance
 * @param u8WaterMark the ADC FIFO water mark setting
 */
LOCAL_INLINE void ADC_HWA_SetFIFOWaterMark(ADC_Type *const pAdc, uint8_t u8WaterMark)
{
    pAdc->CFG2 = (pAdc->CFG2 & ~ADC_CFG2_FWMARK_MASK) | ADC_CFG2_FWMARK(u8WaterMark);
}

#if ADC_SUPPORT_SG_MODE
/**
 * @brief Get the priority of Trigger Latch
 *
 * @param pAdc the base address of the ADC instance
 */
LOCAL_INLINE uint8_t ADC_HWA_GetTriggerLatchUnitPriority(const ADC_Type *const pAdc)
{
    uint32_t u32TmpVal = (pAdc->CFG2 & ADC_CFG2_TRG_PRI_MASK) >> ADC_CFG2_TRG_PRI_SHIFT;
    return (uint8_t)u32TmpVal;
}

/**
 * @brief Set the priority of Trigger Latch
 *
 * @param pAdc the base address of the ADC instance
 * @param eTrgLatchUnitPri the priority of Trigger Latch Unit setting
 */
LOCAL_INLINE void ADC_HWA_SetTriggerLatchUnitPriority(ADC_Type *const pAdc, ADC_TrgLatchUnitPri eTrgLatchUnitPri)
{
    pAdc->CFG2 = (pAdc->CFG2 & ~ADC_CFG2_TRG_CLR_MASK) | ADC_CFG2_TRG_CLR(eTrgLatchUnitPri);
}

/**
 * @brief Clear Latch Trigger in Trigger Latch Unit
 *
 * @param pAdc the base address of the ADC instance
 */
LOCAL_INLINE void ADC_HWA_ClearLatchTrigger(ADC_Type *const pAdc)
{
    uint32_t u32TmpVal = pAdc->CFG2;
    pAdc->CFG2 = u32TmpVal | ADC_CFG2_TRG_CLR(1);
}
#endif

/**
 * @brief Get whether hardware average is enabled
 *
 * @param pAdc the base address of the ADC instance
 * @return true hardware average is enabled
 * @return false hardware average is disabled
 */
LOCAL_INLINE bool ADC_HWA_GetAverageEnable(const ADC_Type *const pAdc)
{
    uint32_t u32TmpVal = (pAdc->CFG2 & ADC_CFG2_AVG_EN_MASK) >> ADC_CFG2_AVG_EN_SHIFT;
    return (bool)((u32TmpVal != 0U) ? true : false);
}

/**
 * @brief Enable or disable hardware average for the ADC instance
 *
 * @param pAdc the base address of the ADC instance
 * @param bEnable whether to enable the ADC hardware average
 */
LOCAL_INLINE void ADC_HWA_SetAverageEnable(ADC_Type *const pAdc, bool bEnable)
{
    pAdc->CFG2 = (pAdc->CFG2 & ~ADC_CFG2_AVG_EN_MASK) | ADC_CFG2_AVG_EN(bEnable);
}

/**
 * @brief Get the hardware average number
 *
 * @param pAdc the base address of the ADC instance
 * @return ADC_AverageType the hardware average number
 */
LOCAL_INLINE ADC_AverageLenType ADC_HWA_GetAverageNumber(const ADC_Type *const pAdc)
{
    uint32_t u32TmpVal = (pAdc->CFG2 & ADC_CFG2_AVG_LEN_MASK) >> ADC_CFG2_AVG_LEN_SHIFT;
    return (ADC_AverageLenType)u32TmpVal;
}

/**
 * @brief Set the hardware average number
 *
 * @param pAdc the base address of the ADC instance
 * @param eAverageNumber the hardware average number to set
 */
LOCAL_INLINE void ADC_HWA_SetAverageNumber(ADC_Type *const pAdc, ADC_AverageLenType eAverageNumber)
{
    pAdc->CFG2 = (pAdc->CFG2 & ~ADC_CFG2_AVG_LEN_MASK) | ADC_CFG2_AVG_LEN(eAverageNumber);
}
/**
 * @brief Whether clock gating is acknowledged
 *
 * @note This feature is only available in FC7300F2M
 *
 * @param pAdc the base address of the ADC instance
 * @return true ADC clock source is off after setting Clock Gating Enable Flag
 * @return false ADC clock source is on after clearing Clock Gating Enable Flag
 */
LOCAL_INLINE bool ADC_HWA_GetClockGatingAck(const ADC_Type *const pAdc)
{
    uint32_t u32TmpVal = (pAdc->CFG2 & ADC_CFG2_CG_ACK_MASK) >> ADC_CFG2_CG_ACK_SHIFT;
    return (bool)((u32TmpVal != 0U) ? true : false);
}

/**
 * @brief Get whether clock gating is enabled
 *
 * @note This feature is only available in FC7300F2M
 *
 * @param pAdc the base address of the ADC instance
 * @return true Clock gating is enabled, ADC clock is off
 * @return false Clock gating is disabled, ADC clock is on
 */
LOCAL_INLINE bool ADC_HWA_GetClockGatingEnable(const ADC_Type *const pAdc)
{
    uint32_t u32TmpVal = (pAdc->CFG2 & ADC_CFG2_CG_MASK) >> ADC_CFG2_CG_SHIFT;
    return (bool)((u32TmpVal != 0U) ? true : false);
}

/**
 * @brief Set whether to enable ADC clock gating
 *
 * @note This feature is only available in FC7300F2M
 *
 * @param pAdc the base address of the ADC instance
 * @param bEnable whether to enable ADC clock gating
 */
LOCAL_INLINE void ADC_HWA_SetClockGatingEnable(ADC_Type *const pAdc, bool bEnable)
{
    pAdc->CFG2 = (pAdc->CFG2 & ~ADC_CFG2_CG_MASK) | ADC_CFG2_CG(bEnable);
}

#if ADC_SUPPORT_INTERNAL_REFERENCE
/**
 * @brief Get the voltage reference of the ADC instance
 *
 * @param pAdc the base address of the ADC instance
 * @return ADC_REF_INTERNAL the ADC instance uses internal voltage reference
 * @return ADC_REF_EXTERNAL the ADC instance uses external voltage reference
 */
LOCAL_INLINE ADC_RefType ADC_HWA_GetVoltageReference(const ADC_Type *const pAdc)
{
    uint32_t u32TmpVal = (pAdc->CFG2 & ADC_CFG2_REF_EXT_MASK) >> ADC_CFG2_REF_EXT_SHIFT;
    return (ADC_RefType)u32TmpVal;
}

/**
 * @brief Set the voltage reference of the ADC instance
 *
 * @param pAdc the base address of the ADC instance
 * @param eRefSel the voltage reference of the ADC instance
 */
LOCAL_INLINE void ADC_HWA_SetVoltageReference(ADC_Type *const pAdc, ADC_RefType eRefSel)
{
    pAdc->CFG2 = (pAdc->CFG2 & ~ADC_CFG2_REF_EXT_MASK) | ADC_CFG2_REF_EXT(eRefSel);
}
#endif

/**
 * @brief Get the ADC clock divider
 *
 * @note This feature is only available in FC7300F2M
 *
 * @param pAdc the base address of the ADC instance
 * @return ADC_ClockDivideType the ADC clock divider
 */
LOCAL_INLINE ADC_ClockDivideType ADC_HWA_GetClockDivider(const ADC_Type *const pAdc)
{
    uint32_t u32TmpVal = (pAdc->CFG2 & ADC_CFG2_DIV_MASK) >> ADC_CFG2_DIV_SHIFT;
    return (ADC_ClockDivideType)u32TmpVal;
}

/**
 * @brief Set the ADC clock divider
 *
 * @note Before configuring DIV, must set CG and wait for CG_ACK=1.
 *       After configuring DIV, must clear CG and wait for CG_ACK=0.
 * @note This feature is only available in FC7300F2M
 *
 * @param pAdc the base address of the ADC instance
 * @param eDivider the ADC clock divider to set
 */
LOCAL_INLINE void ADC_HWA_SetClockDivider(ADC_Type *const pAdc, ADC_ClockDivideType eDivider)
{
    pAdc->CFG2 = (pAdc->CFG2 & ~ADC_CFG2_DIV_MASK) | ADC_CFG2_DIV(eDivider);
}

/**
 * @brief Get the ADC start up count
 *
 * @param pAdc the base address of the ADC instance
 * @return uint8_t the start count of the ADC instance
 */
LOCAL_INLINE uint8_t ADC_HWA_GetStartupCnt(const ADC_Type *const pAdc)
{
    uint32_t u32TmpVal = (pAdc->CFG2 & ADC_CFG2_STCNT_MASK) >> ADC_CFG2_STCNT_SHIFT;
    return (uint8_t)u32TmpVal;
}

/**
 * @brief Set the ADC start up count
 *
 * @param pAdc the base address of the ADC instance
 * @param u8StartupCnt the start count of the ADC instance
 */
LOCAL_INLINE void ADC_HWA_SetStartupCnt(ADC_Type *const pAdc, uint8_t u8StartupCnt)
{
    pAdc->CFG2 = (pAdc->CFG2 & ~ADC_CFG2_STCNT_MASK) | ADC_CFG2_STCNT(u8StartupCnt);
}

/**
 * @brief Get the ADC_CFG2 config
 *
 * @param pAdc the base address of the ADC instance
 * @return uint32_t the ADC_CFG2 config
 */
LOCAL_INLINE uint32_t ADC_HWA_GetConfig2(const ADC_Type *const pAdc)
{
    return pAdc->CFG2;
}

/**
 * @brief Set the ADC_CFG2 config
 *
 * @param pAdc the base address of the ADC instance
 * @param u32Config the ADC_CFG2 config
 */
LOCAL_INLINE void ADC_HWA_SetConfig2(ADC_Type *const pAdc, uint32_t u32Config)
{
    pAdc->CFG2 = u32Config;
}

/**
 * @brief Get the sample time of the ADC instance
 *
 * @param pAdc the base address of the ADC instance
 * @param u8Selection the sample time index, range 0~3
 * @return uint8_t the sample time of the selected index
 */
LOCAL_INLINE uint8_t ADC_HWA_GetSampleTime(ADC_Type *const pAdc, uint8_t u8Selection)
{
    uint32_t ret;
    ret = (pAdc->SMPR & (ADC_SMPR_SMP_OPT0_MASK << (8U * u8Selection))) >> (8U * u8Selection);
    return (uint8_t)ret;
}

/**
 * @brief Set the sample time of the ADC instance
 *
 * @param pAdc the base address of the ADC instance
 * @param u8Selection the sample time index, range 0~3
 * @param u8SampleTime the sample time of the selected index
 */
LOCAL_INLINE void ADC_HWA_SetSampleTime(ADC_Type *const pAdc, uint8_t u8Selection, uint8_t u8SampleTime)
{
    DEV_ASSERT(u8Selection < ADC_SAMPLE_TIME_OPTION_CNT);
    pAdc->SMPR = (pAdc->SMPR & ~(ADC_SMPR_SMP_OPT0_MASK << (8U * u8Selection))) |
                 (ADC_SMPR_SMP_OPT0(u8SampleTime) << (8U * u8Selection));
}

/**
 * @brief Set the ADC hardware compare channel
 *
 * @param pAdc the base address of the ADC instance
 * @param eChannelType whether the hardware compare enabled on single channel or all channels
 * @param u8ChannalNum if hardware compare is enabled on single channel, this specifies the channel number
 */
LOCAL_INLINE void ADC_HWA_SetCmpChannel(ADC_Type *const pAdc, ADC_CmpChannelType eChannelType,
                                              uint8_t u8ChannalNum)
{
    pAdc->CMP_CTRL = (pAdc->CMP_CTRL & (~ADC_CMP_CTRL_ACMPSGL_MASK) & (~ADC_CMP_CTRL_ACMPCH_MASK)) |
                     ADC_CMP_CTRL_ACMPSGL(eChannelType) | ADC_CMP_CTRL_ACMPCH(u8ChannalNum);
}

/**
 * @brief Get whether hardware compare is enabled
 *
 * @param pAdc the base address of the ADC instance
 * @return true hardware compare is enabled
 * @return false hardware compare is disabled
 */
LOCAL_INLINE bool ADC_HWA_GetCmpEnable(const ADC_Type *const pAdc)
{
    uint32_t u32TmpVal = (pAdc->CMP_CTRL & ADC_CMP_CTRL_ACMPEN_MASK) >> ADC_CMP_CTRL_ACMPEN_SHIFT;
    return (bool)((u32TmpVal != 0U) ? true : false);
}

/**
 * @brief Set to enable or disable the hardware compare
 *
 * @param pAdc the base address of the ADC instance
 * @param bEnable whether the ADC hardware compare is enabled
 */
LOCAL_INLINE void ADC_HWA_SetCmpEnable(ADC_Type *const pAdc, bool bEnable)
{
    pAdc->CMP_CTRL = (pAdc->CMP_CTRL & ~ADC_CMP_CTRL_ACMPEN_MASK) | ADC_CMP_CTRL_ACMPEN(bEnable);
}

/**
 * @brief Set the ADC hardware compare threshold
 *
 * @param pAdc the base address of the ADC instance
 * @param u16LowThres the lower threshold
 * @param u16HighThres the higher threshold
 */
LOCAL_INLINE void ADC_HWA_SetCmpThreshold(ADC_Type *const pAdc, uint16_t u16LowThres, uint16_t u16HighThres)
{
    pAdc->CMP_TR = ADC_CMP_TR_LT(u16LowThres) | ADC_CMP_TR_HT(u16HighThres);
}

#if ADC_SUPPORT_PERIOD_TRIGGER

/**
 * @brief Get the ADC period trigger interval
 *
 * @param pAdc the base address of the ADC instance
 * @return uint32_t the ADC period trigger interval
 */
LOCAL_INLINE uint16_t ADC_HWA_GetPeriodTriggerInterval(const ADC_Type *const pAdc)
{
    return ((pAdc->CFG3 & ADC_CFG3_PTRGIV_MASK) >> ADC_CFG3_PTRGIV_SHIFT);
}

/**
 * @brief Set the ADC period trigger interval
 *
 * @param pAdc the base address of the ADC instance
 * @param u16Interval the ADC period trigger interval
 */
LOCAL_INLINE void ADC_HWA_SetPeriodTriggerInterval(ADC_Type *const pAdc, uint16_t u16Interval)
{
    pAdc->CFG3 =  (pAdc->CFG3 & ~ADC_CFG3_PTRGIV_MASK) | ADC_CFG3_PTRGIV(u16Interval);
}

#endif

#if ADC_SUPPORT_SG_MODE
/**
 * @brief Get the end of sequence group flag
 *
 * @param pAdc the base address of the ADC instance
 * @param u8SGIndex the index of the sequence group
 * @param bool the sequence group interrupt flag
 */
LOCAL_INLINE bool ADC_HWA_GetEndOfSGFlag(ADC_Type *const pAdc, const uint8_t u8SGIndex)
{
    uint32_t u32TmpVal = (pAdc->SGCSR[u8SGIndex] & ADC_SGCSR_EOSG_MASK) >> ADC_SGCSR_EOSG_SHIFT;
    return u32TmpVal ? true : false;
}

/**
 * @brief Clear the end of sequence group flag
 *
 * @param pAdc the base address of the ADC instance
 * @param u8SGIndex the index of the sequence group
 */
LOCAL_INLINE void ADC_HWA_ClearEndOfSGFlag(ADC_Type *const pAdc, const uint8_t u8SGIndex)
{
    uint32_t u32TmpVal = pAdc->SGCSR[u8SGIndex];
    pAdc->SGCSR[u8SGIndex] = (u32TmpVal & ~ADC_SGCSR_EOSG_MASK) | ADC_SGCSR_EOSG(1U);
}

/**
 * @brief Set the sequence group end of sequence interrupt enable
 *
 * @param pAdc the base address of the ADC instance
 * @param u8SGIndex the index of the sequence group
 * @param bEnable the sequence group interrupt enable or disable
 */
LOCAL_INLINE void ADC_HWA_SetEndOfSGIntEnable(ADC_Type *const pAdc, const uint8_t u8SGIndex, const bool bEnable)
{
    uint32_t u32TmpVal = pAdc->SGCSR[u8SGIndex];
    pAdc->SGCSR[u8SGIndex] = (u32TmpVal & ~ADC_SGCSR_EOSGIE_MASK) | ADC_SGCSR_EOSGIE(bEnable);
}

/**
 * @brief Get the sequence group end of sequence interrupt enable
 *
 * @param pAdc the base address of the ADC instance
 * @param u8SGIndex the index of the sequence group
 * @param bEnable the sequence group interrupt enable or disable
 */
LOCAL_INLINE bool ADC_HWA_GetEndOfSGIntEnable(ADC_Type *const pAdc, const uint8_t u8SGIndex)
{
    uint32_t u32TmpVal = pAdc->SGCSR[u8SGIndex];
    u32TmpVal = (u32TmpVal & ADC_SGCSR_EOSGIE_MASK) >> ADC_SGCSR_EOSGIE_SHIFT;
    return u32TmpVal ? true : false;
}

/**
 * @brief Get the sequence group start point
 *
 * @param pAdc the base address of the ADC instance
 * @param u8SGIndex the index of the sequence group
 */
LOCAL_INLINE uint8_t ADC_HWA_GetSGStartPoint(ADC_Type *const pAdc, const uint8_t u8SGIndex)
{
    return (uint8_t)((pAdc->SGCSR[u8SGIndex] & ADC_SGCSR_SG_START_MASK) >> ADC_SGCSR_SG_START_SHIFT);
}

/**
 * @brief Get the sequence group end point
 *
 * @param pAdc the base address of the ADC instance
 * @param u8SGIndex the index of the sequence group
 */
LOCAL_INLINE uint8_t ADC_HWA_GetSGEndPoint(ADC_Type *const pAdc, const uint8_t u8SGIndex)
{
    return (uint8_t)((pAdc->SGCSR[u8SGIndex] & ADC_SGCSR_SG_END_MASK) >> ADC_SGCSR_SG_END_SHIFT);
}

/**
 * @brief Set the sequence group start point & end point
 *
 * @param pAdc the base address of the ADC instance
 * @param u8SGIndex the index of the sequence group
 * @param u8Start the sequence group start point
 * @param u8End the sequence group end point
 */
LOCAL_INLINE void ADC_HWA_SetSGStartEndPoint(ADC_Type *const pAdc, const uint8_t u8SGIndex, const uint8_t u8Start, const uint8_t u8End)
{
    uint32_t u32TmpVal = pAdc->SGCSR[u8SGIndex];
    u32TmpVal = (u32TmpVal & ~ADC_SGCSR_SG_END_MASK) | ADC_SGCSR_SG_END(u8End);
    u32TmpVal = (u32TmpVal & ~ADC_SGCSR_SG_START_MASK) | ADC_SGCSR_SG_START(u8Start);
    pAdc->SGCSR[u8SGIndex] = u32TmpVal;
}
#endif

#if ADC_SUPPORT_GAIN_AND_OFFSET_CALIBRATION
/**
 * @brief Set the ADC_CAL config
 *
 * @param pAdc the base address of the ADC instance
 * @param u32Cal the ADC_CAL config
 */
LOCAL_INLINE void ADC_HWA_SetCal(ADC_Type *const pAdc, uint32_t u32Cal)
{
    pAdc->CAL = u32Cal;
}
#endif

/**
 * @brief Get the conversion result FIFO data of the ADC instance
 *
 * @note only reslut data of ADC single mode and continuous mode will be stored
 * in FIFO register.
 *
 * @param pAdc the base address of the ADC instance
 * @return uint32_t the ADC conversion result
 */
LOCAL_INLINE uint32_t ADC_HWA_GetFIFOData(const ADC_Type *const pAdc)
{
    uint32_t u32TmpVal = pAdc->FIFO_DATA;
    u32TmpVal = (u32TmpVal & ADC_FIFO_DATA_FIFO_DATA_MASK) >> ADC_FIFO_DATA_FIFO_DATA_SHIFT;
    return (uint32_t)u32TmpVal;
}

#if ADC_SUPPORT_CHANNEL_DIFFMODE_SET
/**
 * @brief Get the differential mode state of the ADC channel
 *
 * @param pAdc the base address of the ADC instance
 * @param u8ChnIdx the index of the channel
 * @return bool the state of diff mode for ADC channel
 */
LOCAL_INLINE bool ADC_HWA_GetChannelDiffModeEnable(const ADC_Type *const pAdc, const uint8_t u8ChnIdx)
{
    uint32_t u32TmpVal = (pAdc->SC[u8ChnIdx] & ADC_SC_DIFF_MASK) >> ADC_SC_DIFF_SHIFT;
    return u32TmpVal ? true : false;
}

/**
 * @brief Set the differential mode state of the ADC channel
 *
 * @param pAdc the base address of the ADC instance
 * @param u8ChnIdx the index of the channel
 * @param bEnable the state of diff mode for ADC channel
 */
LOCAL_INLINE void ADC_HWA_SetChannelDiffModeEnable(ADC_Type *const pAdc, const uint8_t u8ChnIdx, const bool bEnable)
{
   pAdc->SC[u8ChnIdx] = (pAdc->SC[u8ChnIdx] & ~ADC_SC_DIFF_MASK) | ADC_SC_DIFF(bEnable);
}
#endif

/**
 * @brief Get the sample time index of the ADC channel
 *
 * @param pAdc the base address of the ADC instance
 * @param u8ChnIdx the index of the channel
 * @return uint8_t the sample time index of the ADC channel
 */
LOCAL_INLINE uint8_t ADC_HWA_GetChannelSampleTimeIndex(const ADC_Type *const pAdc, const uint8_t u8ChnIdx)
{
    uint32_t u32TmpVal = (pAdc->SC[u8ChnIdx] & ADC_SC_SMPSEL_MASK) >> ADC_SC_SMPSEL_SHIFT;
    return (uint8_t)u32TmpVal;
}

/**
 * @brief Set the sample time index of the ADC channel
 *
 * @param pAdc the base address of the ADC instance
 * @param u8ChnIdx the index of the channel
 * @param u8SmpSel the sample time index of the ADC channel
 */
LOCAL_INLINE void ADC_HWA_SetChannelSampleTimeIndex(ADC_Type *const pAdc, const uint8_t u8ChnIdx, uint8_t u8SmpSel)
{
    pAdc->SC[u8ChnIdx] = (pAdc->SC[u8ChnIdx] & ~ADC_SC_SMPSEL_MASK) | ADC_SC_SMPSEL(u8SmpSel);
}

/**
 * @brief Get the channel conversion complete status of the ADC instance
 *
 * @note this function is used only in ADC discontinuous mode to get the channel complete
 * status
 *
 * @param pAdc the base address of the ADC instance
 * @param u8ChnIdx the index of the channel
 * @return true the ADC conversion on the selected channel is completed
 * @return false the ADC conversion on the selected channel is not completed
 */
LOCAL_INLINE bool ADC_HWA_GetChannelCoCoFlag(const ADC_Type *const pAdc, const uint8_t u8ChnIdx)
{
    uint32_t u32TmpVal = pAdc->SC[u8ChnIdx];
    u32TmpVal = (u32TmpVal & ADC_SC_COCO_MASK) >> ADC_SC_COCO_SHIFT;

    return (bool)((u32TmpVal != 0U) ? true : false);
}

/**
 * @brief Check whether interrupt is enabled on the selected ADC channel
 *
 * @note this function is used only in ADC discontinuous mode to get the channel interrupt
 * settings
 *
 * @param pAdc the base address of the ADC instance
 * @param u8ChnIdx the index of the channel
 * @return true interrupt is enabled on the selected channel
 * @return false interrupt is disabled on the selected channel
 */
LOCAL_INLINE bool ADC_HWA_GetChannelCoCoIntEnable(const ADC_Type *const pAdc, const uint8_t u8ChnIdx)
{
    uint32_t u32TmpVal = pAdc->SC[u8ChnIdx];
    u32TmpVal = (u32TmpVal & ADC_SC_AIEN_MASK) >> ADC_SC_AIEN_SHIFT;

    return (bool)((u32TmpVal != 0U) ? true : false);
}

/**
 * @brief Set to enable or disable interrupt on the selected ADC channel
 *
 * @note this function is used only in ADC discontinuous mode to get the channel interrupt
 * settings
 *
 * @param pAdc the base address of the ADC instance
 * @param u8ChnIdx the index of the channel
 * @param bEnable whether to enable interrupt on the selected ADC channel
 */
LOCAL_INLINE void ADC_HWA_SetChannelCoCoIntEnable(ADC_Type *const pAdc, const uint8_t u8ChnIdx, bool bEnable)
{
    pAdc->SC[u8ChnIdx] = (pAdc->SC[u8ChnIdx] & ~ADC_SC_AIEN_MASK) | ADC_SC_AIEN(bEnable);
}

/**
 * @brief Get the input channel of the selected ADC channel
 *
 * @param pAdc the base address of the ADC instance
 * @param u8ChnIdx the index of the channel
 * @return uint8_t the hardware input channel
 */
LOCAL_INLINE uint8_t ADC_HWA_GetChannelInput(const ADC_Type *const pAdc, const uint8_t u8ChnIdx)
{
    uint32_t u32TmpVal = (pAdc->SC[u8ChnIdx] & ADC_SC_CHS_MASK) >> ADC_SC_CHS_SHIFT;
    return (uint8_t)u32TmpVal;
}

/**
 * @brief Set the input channel to the selected ADC channel
 *
 * @param pAdc the base address of the ADC instance
 * @param u8ChnIdx the index of the channel
 * @param u8InputChannel the hardware input channel
 */
LOCAL_INLINE void ADC_HWA_SetChannelInput(ADC_Type *const pAdc, const uint8_t u8ChnIdx, uint8_t u8InputChannel)
{
    pAdc->SC[u8ChnIdx] = (pAdc->SC[u8ChnIdx] & ~ADC_SC_CHS_MASK) | ADC_SC_CHS(u8InputChannel);
}

/**
 * @brief Get the conversion result data of the ADC instance
 *
 * @note only result data of ADC discontinuous mode will be stored in RESULTn register.
 *
 * @param pAdc the base address of the ADC instance
 * @param u8ChnIdx the index of the ADC channel
 * @return uint32_t the ADC conversion result
 */
LOCAL_INLINE uint32_t ADC_HWA_GetChannelData(const ADC_Type *const pAdc, const uint8_t u8ChnIdx)
{
    uint32_t u32TmpVal = pAdc->RESULT[u8ChnIdx];
    u32TmpVal = (u32TmpVal & ADC_RESULT_RESULT_MASK) >> ADC_RESULT_RESULT_SHIFT;

    return (uint32_t)u32TmpVal;
}

#if ADC_SUPPORT_ENHANCED_CMP_BLOCK
/**
 * @brief Set the enhanced comparator option
 *
 * @param pAdc the base address of the ADC instance
 * @param u8Index the index of the enhanced comparator block
 * @param eOption the option of the enhanced comparator
 * @return non
 */
LOCAL_INLINE void ADC_HWA_SetECMPOption(ADC_Type *const pAdc, const ADC_ECMPIndex u8Index, ADC_ECMPOption eOption)
{
    uint32_t u32TmpVal = pAdc->ECMP_CTRL[u8Index];
    u32TmpVal = (u32TmpVal & ~ADC_ECMP_CTRL_CMPOPT_MASK) | ADC_ECMP_CTRL_CMPOPT(eOption);
    pAdc->ECMP_CTRL[u8Index] = u32TmpVal;
}

/**
 * @brief Enabld/disable the enhanced comparator
 *
 * @param pAdc the base address of the ADC instance
 * @param u8Index the index of the enhanced comparator block
 * @param bEnable the option of the enhanced comparator
 * @return non
 */
LOCAL_INLINE void ADC_HWA_SetECMPEnable(ADC_Type *const pAdc, const ADC_ECMPIndex u8Index, bool bEnable)
{
    uint32_t u32TmpVal = pAdc->ECMP_CTRL[u8Index];
    u32TmpVal = (u32TmpVal & ~ADC_ECMP_CTRL_CMPEN_MASK) | ADC_ECMP_CTRL_CMPEN(bEnable);
    pAdc->ECMP_CTRL[u8Index] = u32TmpVal;
}

/**
 * @brief Set the enhanced comparator channel type selection
 *
 * @param pAdc the base address of the ADC instance
 * @param u8Index the index of the enhanced comparator block
 * @param eType the selection of channel type selection
 * @return non
 */
LOCAL_INLINE void ADC_HWA_SetECMPSGL(ADC_Type *const pAdc, const ADC_ECMPIndex u8Index, ADC_ECmpChannelType eType)
{
    uint32_t u32TmpVal = pAdc->ECMP_CTRL[u8Index];
    u32TmpVal = (u32TmpVal & ~ADC_ECMP_CTRL_CMPSGL_MASK) | ADC_ECMP_CTRL_CMPSGL(eType);
    pAdc->ECMP_CTRL[u8Index] = u32TmpVal;
}

/**
 * @brief Set the enhanced comparator channel selection
 *
 * @param pAdc the base address of the ADC instance
 * @param u8Index the index of the enhanced comparator block
 * @param u8Channel the selection of channel
 * @return non
 */
LOCAL_INLINE void ADC_HWA_SetECMPChannel(ADC_Type *const pAdc, const ADC_ECMPIndex u8Index, uint8_t u8Channel)
{
    uint32_t u32TmpVal = pAdc->ECMP_CTRL[u8Index];
    u32TmpVal = (u32TmpVal & ~ADC_ECMP_CTRL_CMPCH_MASK) | ADC_ECMP_CTRL_CMPCH(u8Channel);
    pAdc->ECMP_CTRL[u8Index] = u32TmpVal;
}

/**
 * @brief Get the enhanced comparator high flag
 *
 * @param pAdc the base address of the ADC instance
 * @param u8Index the index of the enhanced comparator block
 * @return bool the flag of enhanced comparator high
 */
LOCAL_INLINE bool ADC_HWA_GetECMPHighFlag(ADC_Type *const pAdc, const ADC_ECMPIndex u8Index)
{
    uint32_t u32TmpVal = pAdc->ECMP_STATUS;
    if (u8Index == ADC_ECMP0)
        u32TmpVal = (u32TmpVal & ADC_ECMP_STATUS_CMPH0_MASK);
    else if (u8Index == ADC_ECMP1)
        u32TmpVal = (u32TmpVal & ADC_ECMP_STATUS_CMPH1_MASK);
    return u32TmpVal ? true : false;
}

/**
 * @brief Get the enhanced comparator low flag
 *
 * @param pAdc the base address of the ADC instance
 * @param u8Index the index of the enhanced comparator block
 * @return bool the flag of enhanced comparator low
 */
LOCAL_INLINE bool ADC_HWA_GetECMPLowFlag(ADC_Type *const pAdc, const ADC_ECMPIndex u8Index)
{
    uint32_t u32TmpVal = pAdc->ECMP_STATUS;
    if (u8Index == ADC_ECMP0)
        u32TmpVal = (u32TmpVal & ADC_ECMP_STATUS_CMPL0_MASK);
    else if (u8Index == ADC_ECMP1)
        u32TmpVal = (u32TmpVal & ADC_ECMP_STATUS_CMPL1_MASK);
    return u32TmpVal ? true : false;
}

/**
 * @brief Get the enhanced comparator window flag
 *
 * @param pAdc the base address of the ADC instance
 * @param u8Index the index of the enhanced comparator block
 * @return bool the flag of enhanced comparator window
 */
LOCAL_INLINE bool ADC_HWA_GetECMPWinFlag(ADC_Type *const pAdc, const ADC_ECMPIndex u8Index)
{
    uint32_t u32TmpVal = pAdc->ECMP_STATUS;
    if (u8Index == ADC_ECMP0)
        u32TmpVal = (u32TmpVal & ADC_ECMP_STATUS_CMPW0_MASK);
    else if (u8Index == ADC_ECMP1)
        u32TmpVal = (u32TmpVal & ADC_ECMP_STATUS_CMPW1_MASK);
    return u32TmpVal ? true : false;
}

/**
 * @brief Clear the enhanced comparator high flag
 *
 * @param pAdc the base address of the ADC instance
 * @param u8Index the index of the enhanced comparator block
 * @return non
 */
LOCAL_INLINE void ADC_HWA_ClearECMPHighFlag(ADC_Type *const pAdc, const ADC_ECMPIndex u8Index)
{
    if (u8Index == ADC_ECMP0)
        pAdc->ECMP_STATUS = ADC_ECMP_STATUS_CMPH0_MASK;
    else if (u8Index == ADC_ECMP1)
        pAdc->ECMP_STATUS = ADC_ECMP_STATUS_CMPH1_MASK;
}

/**
 * @brief Clear the enhanced comparator low flag
 *
 * @param pAdc the base address of the ADC instance
 * @param u8Index the index of the enhanced comparator block
 * @return non
 */
LOCAL_INLINE void ADC_HWA_ClearECMPLowFlag(ADC_Type *const pAdc, const ADC_ECMPIndex u8Index)
{
    if (u8Index == ADC_ECMP0)
        pAdc->ECMP_STATUS = ADC_ECMP_STATUS_CMPL0_MASK;
    else if (u8Index == ADC_ECMP1)
        pAdc->ECMP_STATUS = ADC_ECMP_STATUS_CMPL1_MASK;
}

/**
 * @brief Clear the enhanced comparator window flag
 *
 * @param pAdc the base address of the ADC instance
 * @param u8Index the index of the enhanced comparator block
 * @return non
 */
LOCAL_INLINE void ADC_HWA_ClearECMPWinFlag(ADC_Type *const pAdc, const ADC_ECMPIndex u8Index)
{
    if (u8Index == ADC_ECMP0)
        pAdc->ECMP_STATUS = ADC_ECMP_STATUS_CMPW0_MASK;
    else if (u8Index == ADC_ECMP1)
        pAdc->ECMP_STATUS = ADC_ECMP_STATUS_CMPW1_MASK;
}

/**
 * @brief Set the enhanced comparator high interrupt enable
 *
 * @param pAdc the base address of the ADC instance
 * @param u8Index the index of the enhanced comparator block
 * @param bEnable the enable status of enhanced comparator high interrupt
 */
LOCAL_INLINE void ADC_HWA_SetECMPHighIntEnable(ADC_Type *const pAdc, const ADC_ECMPIndex u8Index, bool bEnable)
{
    uint32_t u32TmpVal = pAdc->ECMP_INT_EN;
    if (u8Index == ADC_ECMP0)
        u32TmpVal = (u32TmpVal & ~ADC_ECMP_INT_EN_CMPH_IE0_MASK) | ADC_ECMP_INT_EN_CMPH_IE0(bEnable);
    else if (u8Index == ADC_ECMP1)
        u32TmpVal = (u32TmpVal & ~ADC_ECMP_INT_EN_CMPH_IE1_MASK) | ADC_ECMP_INT_EN_CMPH_IE1(bEnable);
    pAdc->ECMP_INT_EN = u32TmpVal;
}

/**
 * @brief Get the enhanced comparator high interrupt enable status
 *
 * @param pAdc the base address of the ADC instance
 * @param u8Index the index of the enhanced comparator block
 * @return bool the enable status of enhanced comparator high interrupt
 */
LOCAL_INLINE bool ADC_HWA_GetECMPHighIntEnable(ADC_Type *const pAdc, const ADC_ECMPIndex u8Index)
{
    uint32_t u32TmpVal = pAdc->ECMP_INT_EN;
    if (u8Index == ADC_ECMP0)
        u32TmpVal = u32TmpVal & ADC_ECMP_INT_EN_CMPH_IE0_MASK;
    else if (u8Index == ADC_ECMP1)
        u32TmpVal = u32TmpVal & ADC_ECMP_INT_EN_CMPH_IE1_MASK;
    return u32TmpVal ? true : false;
}

/**
 * @brief Set the enhanced comparator low interrupt enable
 *
 * @param pAdc the base address of the ADC instance
 * @param u8Index the index of the enhanced comparator block
 * @param bEnable the enable status of enhanced comparator low interrupt
 */
LOCAL_INLINE void ADC_HWA_SetECMPLowIntEnable(ADC_Type *const pAdc, const ADC_ECMPIndex u8Index, bool bEnable)
{
    uint32_t u32TmpVal = pAdc->ECMP_INT_EN;
    if (u8Index == ADC_ECMP0)
        u32TmpVal = (u32TmpVal & ~ADC_ECMP_INT_EN_CMPL_IE0_MASK) | ADC_ECMP_INT_EN_CMPL_IE0(bEnable);
    else if (u8Index == ADC_ECMP1)
        u32TmpVal = (u32TmpVal & ~ADC_ECMP_INT_EN_CMPL_IE1_MASK) | ADC_ECMP_INT_EN_CMPL_IE1(bEnable);
    pAdc->ECMP_INT_EN = u32TmpVal;
}

/**
 * @brief Get the enhanced comparator low interrupt enable status
 *
 * @param pAdc the base address of the ADC instance
 * @param u8Index the index of the enhanced comparator block
 * @return bool the enable status of enhanced comparator low interrupt
 */
LOCAL_INLINE bool ADC_HWA_GetECMPLowIntEnable(ADC_Type *const pAdc, const ADC_ECMPIndex u8Index)
{
    uint32_t u32TmpVal = pAdc->ECMP_INT_EN;
    if (u8Index == ADC_ECMP0)
        u32TmpVal = u32TmpVal & ADC_ECMP_INT_EN_CMPL_IE0_MASK;
    else if (u8Index == ADC_ECMP1)
        u32TmpVal = u32TmpVal & ADC_ECMP_INT_EN_CMPL_IE1_MASK;
    return u32TmpVal ? true : false;
}

/**
 * @brief Set the enhanced comparator window interrupt enable
 *
 * @param pAdc the base address of the ADC instance
 * @param u8Index the index of the enhanced comparator block
 * @param bEnable the enable status of enhanced comparator window interrupt
 */
LOCAL_INLINE void ADC_HWA_SetECMPWinIntEnable(ADC_Type *const pAdc, const ADC_ECMPIndex u8Index, bool bEnable)
{
    uint32_t u32TmpVal = pAdc->ECMP_INT_EN;
    if (u8Index == ADC_ECMP0)
        u32TmpVal = (u32TmpVal & ~ADC_ECMP_INT_EN_CMPW_IE0_MASK) | ADC_ECMP_INT_EN_CMPW_IE0(bEnable);
    else if (u8Index == ADC_ECMP1)
        u32TmpVal = (u32TmpVal & ~ADC_ECMP_INT_EN_CMPW_IE1_MASK) | ADC_ECMP_INT_EN_CMPW_IE1(bEnable);
    pAdc->ECMP_INT_EN = u32TmpVal;
}

/**
 * @brief Get the enhanced comparator window interrupt enable status
 *
 * @param pAdc the base address of the ADC instance
 * @param u8Index the index of the enhanced comparator block
 * @return bool the enable status of enhanced comparator window interrupt
 */
LOCAL_INLINE bool ADC_HWA_GetECMPWinIntEnable(ADC_Type *const pAdc, const ADC_ECMPIndex u8Index)
{
    uint32_t u32TmpVal = pAdc->ECMP_INT_EN;
    if (u8Index == ADC_ECMP0)
        u32TmpVal = u32TmpVal & ADC_ECMP_INT_EN_CMPW_IE0_MASK;
    else if (u8Index == ADC_ECMP1)
        u32TmpVal = u32TmpVal & ADC_ECMP_INT_EN_CMPW_IE1_MASK;
    return u32TmpVal ? true : false;
}

/**
 * @brief Set the enhanced comparator threshold
 *
 * @param pAdc the base address of the ADC instance
 * @param u8Index the index of the enhanced comparator block
 * @param u16LowThres the low threshold of the enhanced comparator
 * @param u16HighThres the high threshold of the enhanced comparator
 */
LOCAL_INLINE void ADC_HWA_SetECMPThreshold(ADC_Type *const pAdc, const ADC_ECMPIndex u8Index, uint16_t u16LowThres, uint16_t u16HighThres)
{
    uint32_t u32TmpVal = pAdc->ECMP_TR[u8Index];
    u32TmpVal = ADC_ECMP_TR_HT(u16HighThres) | ADC_ECMP_TR_LT(u16LowThres);
    pAdc->ECMP_TR[u8Index] = u32TmpVal;
}
#endif

#if ADC_SUPPORT_FAST_CMP_BLOCK
/**
 * @brief Get the fast compare enable
 *
 * @note
 *
 * @param pAdc the base address of the ADC instance
 * @return bool whether the ADC fast compare enable
 */
LOCAL_INLINE bool ADC_HWA_GetFCEnable(const ADC_Type *const pAdc)
{
    uint32_t u32TmpVal = (pAdc->FCMP_CTRL & ADC_FCMP_CTRL_FC_EN_MASK) >> ADC_FCMP_CTRL_FC_EN_SHIFT;
    return u32TmpVal ? true : false;
}

/**
 * @brief Set the fast compare reference of the ADC instance
 *
 * @note
 *
 * @param pAdc the base address of the ADC instance
 * @param enable whether the ADC fast compare enable
 * @return none
 */
LOCAL_INLINE void ADC_HWA_SetFCEnable(ADC_Type *const pAdc, bool enable)
{
    pAdc->FCMP_CTRL = (pAdc->FCMP_CTRL & ~ADC_FCMP_CTRL_FC_EN_MASK) | ADC_FCMP_CTRL_FC_EN(enable);
}

/**
 * @brief Set the fast compare control register
 *
 * @note
 *
 * @param pAdc the base address of the ADC instance
 * @param value control register value
 * @return none
 */
LOCAL_INLINE void ADC_HWA_SetFCCtrl(ADC_Type *const pAdc, uint32_t value)
{
    pAdc->FCMP_CTRL = value;
}

/**
 * @brief Get the fast compare reference of the ADC instance
 *
 * @note
 *
 * @param pAdc the base address of the ADC instance
 * @return int16_t the ADC fast compare reference
 */
LOCAL_INLINE int16_t ADC_HWA_GetFCRef(const ADC_Type *const pAdc)
{
    return (pAdc->FCREF & ADC_FCREF_FCREF_MASK) >> ADC_FCREF_FCREF_SHIFT;
}

/**
 * @brief Set the fast compare reference of the ADC instance
 *
 * @note
 *
 * @param pAdc the base address of the ADC instance
 * @param ref the index of the ADC channel
 * @return none
 */
LOCAL_INLINE void ADC_HWA_SetFCRef(ADC_Type *const pAdc, uint16_t ref)
{
    pAdc->FCREF = (pAdc->FCREF & ~ADC_FCREF_FCREF_MASK) | ADC_FCREF_FCREF(ref);
}

/**
 * @brief Get the fast compare ramp reference A of the ADC instance
 *
 * @note
 *
 * @param pAdc the base address of the ADC instance
 * @return int16_t the ADC fast compare ramp reference A
 */
LOCAL_INLINE int16_t ADC_HWA_GetFCRampRefA(const ADC_Type *const pAdc)
{
    return (pAdc->FCRAMP0 & ADC_FCRAMP0_FCREF_A_MASK) >> ADC_FCRAMP0_FCREF_A_SHIFT;
}

/**
 * @brief Set the fast compare ramp reference A of the ADC instance
 *
 * @note
 *
 * @param pAdc the base address of the ADC instance
 * @param ref the ADC fast compare ramp reference A
 * @return none
 */
LOCAL_INLINE void ADC_HWA_SetFCRampRefA(ADC_Type *const pAdc, uint16_t ref)
{
    pAdc->FCRAMP0 = (pAdc->FCRAMP0 & ~ADC_FCRAMP0_FCREF_A_MASK) | ADC_FCRAMP0_FCREF_A(ref);
}

/**
 * @brief Get the fast compare ramp step of the ADC instance
 *
 * @note
 *
 * @param pAdc the base address of the ADC instance
 * @return uint8_t the ADC fast compare ramp step
 */
LOCAL_INLINE uint8_t ADC_HWA_GetFCRampStep(const ADC_Type *const pAdc)
{
    return (pAdc->FCRAMP0 & ADC_FCRAMP0_RPSTEP_MASK) >> ADC_FCRAMP0_RPSTEP_SHIFT;
}

/**
 * @brief Set the fast compare ramp step
 *
 * @note
 *
 * @param pAdc the base address of the ADC instance
 * @param step the ADC fast compare ramp step
 * @return none
 */
LOCAL_INLINE void ADC_HWA_SetFCRampStep(ADC_Type *const pAdc, uint16_t step)
{
    pAdc->FCRAMP0 = (pAdc->FCRAMP0 & ~ADC_FCRAMP0_RPSTEP_MASK) | ADC_FCRAMP0_RPSTEP(step);
}

/**
 * @brief Set the fast compare ramp0 register
 *
 * @note
 *
 * @param pAdc the base address of the ADC instance
 * @param value the ADC fast compare ramp0 register value
 * @return none
 */
LOCAL_INLINE void ADC_HWA_SetFCRamp0(ADC_Type *const pAdc, uint32_t value)
{
    pAdc->FCRAMP0 = value;
}

/**
 * @brief Get the fast compare ramp reference B of the ADC instance
 *
 * @note
 *
 * @param pAdc the base address of the ADC instance
 * @return int16_t the ADC fast compare ramp reference B
 */
LOCAL_INLINE int16_t ADC_HWA_GetFCRampRefB(const ADC_Type *const pAdc)
{
    return (pAdc->FCRAMP1 & ADC_FCRAMP1_FCREF_B_MASK) >> ADC_FCRAMP1_FCREF_B_SHIFT;
}

/**
 * @brief Set the fast compare ramp reference B of the ADC instance
 *
 * @note
 *
 * @param pAdc the base address of the ADC instance
 * @param ref the ADC fast compare ramp reference B
 * @return none
 */
LOCAL_INLINE void ADC_HWA_SetFCRampRefB(ADC_Type *const pAdc, uint16_t ref)
{
    pAdc->FCRAMP1 = (pAdc->FCRAMP1 & ~ADC_FCRAMP1_FCREF_B_MASK) | ADC_FCRAMP1_FCREF_B(ref);
}

/**
 * @brief Get the fast compare ramp dir
 *
 * @note
 *
 * @param pAdc the base address of the ADC instance
 * @return ADC_FCmpRampDir the ADC fast compare ramp dir
 */
LOCAL_INLINE ADC_FCmpRampDir ADC_HWA_GetFCRampDir(const ADC_Type *const pAdc)
{
    uint32_t u32TmpVal = (pAdc->FCRAMP1 & ADC_FCRAMP1_RPDIR_MASK) >> ADC_FCRAMP1_RPDIR_SHIFT;
    return u32TmpVal ? ADC_FCMP_RAMPDIR_DOWN : ADC_FCMP_RAMPDIR_UP;
}

/**
 * @brief Set the fast compare ramp dir
 *
 * @note
 *
 * @param pAdc the base address of the ADC instance
 * @param dir the ADC fast compare ramp dir
 * @return none
 */
LOCAL_INLINE void ADC_HWA_SetFCRampDir(ADC_Type *const pAdc, ADC_FCmpRampDir dir)
{
    pAdc->FCRAMP1 = (pAdc->FCRAMP1 & ~ADC_FCRAMP1_RPDIR_MASK) | ADC_FCRAMP1_RPDIR(dir);
}

/**
 * @brief Set the fast compare ramp1 register
 *
 * @note
 *
 * @param pAdc the base address of the ADC instance
 * @param value the ADC fast compare ramp1 register value
 * @return none
 */
LOCAL_INLINE void ADC_HWA_SetFCRamp1(ADC_Type *const pAdc, uint32_t value)
{
    pAdc->FCRAMP1 = value;
}

/**
 * @brief Get the fast compare reference upper delta
 *
 * @note
 *
 * @param pAdc the base address of the ADC instance
 * @return uint16_t the ADC fast compare ref upper delta
 */
LOCAL_INLINE uint16_t ADC_HWA_GetFCRefDeltaP(const ADC_Type *const pAdc)
{
    return (pAdc->FCHYST & ADC_FCHYST_DELTAP_MASK) >> ADC_FCHYST_DELTAP_SHIFT;
}

/**
 * @brief Set the fast compare reference upper delta
 *
 * @note
 *
 * @param pAdc the base address of the ADC instance
 * @param delta the ADC fast compare ref upper delta
 * @return none
 */
LOCAL_INLINE void ADC_HWA_SetFCRefDeltaP(ADC_Type *const pAdc, uint16_t delta)
{
    pAdc->FCHYST = (pAdc->FCHYST & ~ADC_FCHYST_DELTAP_MASK) | ADC_FCHYST_DELTAP(delta);
}

/**
 * @brief Get the fast compare reference lower delta
 *
 * @note
 *
 * @param pAdc the base address of the ADC instance
 * @return uint16_t the ADC fast compare ref lower delta
 */
LOCAL_INLINE uint16_t ADC_HWA_GetFCRefDeltaN(const ADC_Type *const pAdc)
{
    return (pAdc->FCHYST & ADC_FCHYST_DELTAN_MASK) >> ADC_FCHYST_DELTAN_SHIFT;
}

/**
 * @brief Set the fast compare reference lower delta
 *
 * @note
 *
 * @param pAdc the base address of the ADC instance
 * @param delta the ADC fast compare ref lower delta
 * @return none
 */
LOCAL_INLINE void ADC_HWA_SetFCRefDeltaN(ADC_Type *const pAdc, uint16_t delta)
{
    pAdc->FCHYST = (pAdc->FCHYST & ~ADC_FCHYST_DELTAN_MASK) | ADC_FCHYST_DELTAN(delta);
}

/**
 * @brief Set the fast compare reference hysteresis
 *
 * @note
 *
 * @param pAdc the base address of the ADC instance
 * @param u32Hyst the ADC fast compare reference hysteresis
 * @return none
 */
LOCAL_INLINE void ADC_HWA_SetFCHysteresis(ADC_Type *const pAdc, uint32_t u32Hyst)
{
    pAdc->FCHYST = u32Hyst;
}

/**
 * @brief Get the fast compare result
 *
 * @note
 *
 * @param pAdc the base address of the ADC instance
 * @return bool fast compare result
 */
LOCAL_INLINE bool ADC_HWA_GetFCResult(ADC_Type *const pAdc)
{
    return (bool)((pAdc->FCBFR & ADC_FCBFR_FCR_MASK) >> ADC_FCBFR_FCR_SHIFT);
}

/**
 * @brief Get the fast compare boundary flag
 *
 * @note
 *
 * @param pAdc the base address of the ADC instance
 * @return bool fast compare boundary flag
 */
LOCAL_INLINE bool ADC_HWA_GetFCBoundaryFlag(ADC_Type *const pAdc)
{
    return (bool)((pAdc->FCBFR & ADC_FCBFR_BFL_MASK) >> ADC_FCBFR_BFL_SHIFT);
}
#endif  /* ADC_SUPPORT_FAST_CMP_BLOCK */

#if ADC_SUPPORT_GROUP_INJECTION
/**
 * @brief Trigger sequence group 0 injection
 *
 * @note
 *
 * @param pAdc the base address of the ADC instance
 */
LOCAL_INLINE void ADC_HWA_TriggerSG0Injection(ADC_Type *const pAdc)
{
    pAdc->CFG2 = pAdc->CFG2 | ADC_CFG2_STRIG_INJT_MASK;
}
#endif

/** @}*/

#endif /* #if ADC_INSTANCE_COUNT > 0U */

#endif /* _HWA_ADC_H_ */
