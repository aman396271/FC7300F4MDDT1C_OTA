/**
 * @file HwA_hsadc.h
 * @author flagchip
 * @brief Hardware access layer for HSADC
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
   *   0.1.0      2023-12-15     Flagchip126   N/A          First version for FC7300
   *   2.0.0      2024-10-12     Flagchip126   N/A          Change version and release
   ******************************************************************************** */

#ifndef _HWA_HSADC_H_
#define _HWA_HSADC_H_

#include "device_header.h"

#if HSADC_INSTANCE_COUNT > 0U

/**
 * @defgroup HwA_hsadc HwA_hsadc
 * @ingroup module_driver_hsadc
 * @{
 */

/**
 * @brief Select the HSADC result alignment
 *
 */
typedef enum
{
    HSADC_ALIGN_RIGHT = 0U,   /*!< HSADC result is aligned in right */
    HSADC_ALIGN_LEFT  = 1U    /*!< HSADC result is aligned in left */
} HSADC_AlignType;

/**
 * @brief Select the HSADC trigger mode
 *
 * @note This option is only valid in HSADC single sequence mode and HSADC continuous mode.
 * In HSADC discontinuous mode, the HSADC trigger mode is fixed as HSADC_TRIGMODE_RISING_EDGE
 *
 */
typedef enum
{
    HSADC_TRGMODE_SW                = 0U,  /*!< HSADC is triggered by software */
    HSADC_TRGMODE_RISING_EDGE       = 1U,  /*!< HSADC is triggered by hardware trigger on rising edge */
    HSADC_TRGMODE_FALLING_EDGE      = 2U,  /*!< HSADC is triggered by hardware trigger on falling edge */
    HSADC_TRGMODE_BOTH_EDGE         = 3U,  /*!< HSADC is triggered by hardware trigger on both edges */
    HSADC_TRGMODE_HIGH_VOLTAGE      = 4U,  /*!< HSADC is triggered when hardware trigger is high voltage */
    HSADC_TRGMODE_LOW_VOLTAGE       = 5U,  /*!< HSADC is triggered when hardware trigger is low voltage */
    HSADC_TRGMODE_INTERNAL_PERIODIC = 6U   /*!< HSADC is triggered by internal generated periodic trigger */
} HSADC_TrgModeType;

/**
 * @brief Select the HSADC sequence mode
 *
 */
typedef enum
{
    HSADC_SEQMODE_SINGLE          = 0U,   /*!< HSADC single sequence mode */
    HSADC_SEQMODE_CONTINUOUS      = 1U,   /*!< HSADC continuous mode */
    HSADC_SEQMODE_DISCONTINUOUS   = 2U,   /*!< HSADC discontinuous mode */
                                          /*!< 3 is reserved*/
	HSADC_SEQMODE_GROUP           = 4U    /*!< HSADC sequence group mode */
} HSADC_SeqModeType;

typedef enum
{
    HSADC_FAST_CMP_REFMODE_SW    = 0U,
    HSADC_FAST_CMP_REFMODE_RAMP  = 1U,
    HSADC_FAST_CMP_REFMODE_ALT   = 2U
} HSADC_FastCmpRefMode;

typedef enum
{
    HSADC_FAST_CMP_RAMPDIR_UP    = 0U,
    HSADC_FAST_CMP_RAMPDIR_DOWN  = 1U
} HSADC_FastCmpRampDir;

typedef enum
{
    HSADC_FAST_CMP_RAMPTRGMODE_SW_AUTO  = 0U,
    HSADC_FAST_CMP_RAMPTRGMODE_SW_EXT   = 1U,
    HSADC_FAST_CMP_RAMPTRGMODE_EXT_AUTO = 2U
} HSADC_FastCmpRampTrgMode;


typedef enum
{
    HSADC_FAST_CMP_RAMPTRGPOL_RISING_OR_HIGH = 0U,
    HSADC_FAST_CMP_RAMPTRGPOL_FALLING_OR_LOW = 1U,
} HSADC_FastCmpRampTrgPolarity;

typedef enum
{
    HSADC_FAST_CMP_BFA_A1B0 = 0U,
    HSADC_FAST_CMP_BFA_A0B1 = 1U,
} HSADC_FCmpBFLAction;

/**
 * @brief Select the HSADC overrun management mode
 *
 * To select whether the old data are preserved or overwritten by the new data when HSADC
 * is overrun (The FIFO is full when new convertion result comes)
 *
 */
typedef enum
{
    HSADC_OVERRUN_MODE_PRESERVE  = 0U, /*!< old data are preserved when HSADC is overrun */
    HSADC_OVERRUN_MODE_OVERWRITE = 1U  /*!< old data are overwritten when HSADC is overrun */
} HSADC_OvrModeType;

/**
 * @brief Select the priority of Trigger Latch Unit
 *
 */
typedef enum
{
    TRG_LATCH_UNIT_PRI_ROUND_ROBIN = 0U,   /*!< select the round robin scheduling priority */
    TRG_LATCH_UNIT_PRI_FIX         = 1U    /*!< select the fixed priority(0>1>2>3) */
} HSADC_TrgLatchUnitPri;

/**
 * @brief Select the HSADC hardware average samples
 *
 */
typedef enum
{
    HSADC_AVERAGE_LEN_4  = 0U,  /*!< result average by 4 samples */
    HSADC_AVERAGE_LEN_8  = 1U,  /*!< result average by 8 samples */
    HSADC_AVERAGE_LEN_16 = 2U,  /*!< result average by 16 samples */
    HSADC_AVERAGE_LEN_32 = 3U   /*!< result average by 32 samples */
} HSADC_AverageLenType;

/**
 * @brief Set the HSADC clock divider
 *
 * @note HSADC clock divider is not available in FC7300F512K
 *
 */
typedef enum
{
    HSADC_CLOCK_DIV_1 = 0U,
    HSADC_CLOCK_DIV_2 = 1U,
    HSADC_CLOCK_DIV_4 = 2U,
    HSADC_CLOCK_DIV_8 = 3U
} HSADC_ClockDivideType;

/**
 * @brief The trigger source of the HSADC instance
 *
 * @note In HSADC discontinuous 1 mode, the trigger source is from Ptimer
 * In HSADC single and continuous mode, if hardware trigger is enabled, the trigger
 * source is from TRGSEL
 *
 */
typedef enum
{
    HSADC_TRGSRC_TRGSEL = 2U,         /**< Trigger source from TRGSEL */
	HSADC_TRGSRC_TRIG_LATCH_UNIT = 3U /**< Trigger source from LATCH UNIT */
} HSADC_TrgSrcType;

/**
 * @brief Select the channel compare mode
 *
 * Select whether the channel compare is enabled on all channels or on the single
 * selected channel
 *
 */
typedef enum
{
    HSADC_CMP_CHANNEL_ALL    = 0U,  /*!< Compare enabled in all channels */
    HSADC_CMP_CHANNEL_SINGLE = 1U   /*!< Compare enabled in the specified channel */
} HSADC_CmpChannelType;

typedef enum
{
    FUNCTION_CLOCK_FROM_PCC = 0U,
    FUNCTION_CLOCK_FROM_PAD = 1U
} HSADC_FunctionClockType;

/**
 * @brief The HSADC Sequence Group Index
 *
 */
typedef enum
{
    HSADC_SEQ_GROUP_0 = 0U,
    HSADC_SEQ_GROUP_1 = 1U,
} HSADC_SeqGroupIndex;

/**
 * @brief Check whether detect fast compare falling edge
 *
 * @param pHsadc the base address of the HSADC instance
 * @return true detect fast compare falling edge
 * @return false not detect fast compare falling edge
 */
LOCAL_INLINE bool HSADC_HWA_GetFCRFFlag(const HSADC_Type *const pHsadc)
{
    uint32_t u32TmpVal = pHsadc->INT_STATUS;
    u32TmpVal = (u32TmpVal & HSADC_INT_STATUS_FCR_F_MASK) >> HSADC_INT_STATUS_FCR_F_SHIFT;

    return (bool)((u32TmpVal != 0U) ? true : false);
}

/**
 * @brief Clear the fast compare falling edge flag
 *
 * @param pHsadc the base address of the HSADC instance
 */
LOCAL_INLINE void HSADC_HWA_ClearFCRFFlag(HSADC_Type *const pHsadc)
{
    pHsadc->INT_STATUS = HSADC_INT_STATUS_FCR_F(1U);
}

/**
 * @brief Check whether detect fast compare rising edge
 *
 * @param pHsadc the base address of the HSADC instance
 * @return true detect fast compare rising edge
 * @return false not detect fast compare rising edge
 */
LOCAL_INLINE bool HSADC_HWA_GetFCRRFlag(const HSADC_Type *const pHsadc)
{
    uint32_t u32TmpVal = pHsadc->INT_STATUS;
    u32TmpVal = (u32TmpVal & HSADC_INT_STATUS_FCR_R_MASK) >> HSADC_INT_STATUS_FCR_R_SHIFT;

    return (bool)((u32TmpVal != 0U) ? true : false);
}

/**
 * @brief Clear the fast compare rising edge flag
 *
 * @param pHsadc the base address of the HSADC instance
 */
LOCAL_INLINE void HSADC_HWA_ClearFCRRFlag(HSADC_Type *const pHsadc)
{
    pHsadc->INT_STATUS = HSADC_INT_STATUS_FCR_R(1U);
}

/**
 * @brief Check whether the data quantity in the FIFO is greater than watermark
 *
 * @param pHsadc the base address of the HSADC instance
 * @return true the HSADC FIFO is ready
 * @return false the HSADC FIFO is unready
 */
LOCAL_INLINE bool HSADC_HWA_GetFIFOReadyFlag(const HSADC_Type *const pHsadc)
{
    uint32_t u32TmpVal = pHsadc->INT_STATUS;
    u32TmpVal = (u32TmpVal & HSADC_INT_STATUS_FIFO_RDY_MASK) >> HSADC_INT_STATUS_FIFO_RDY_SHIFT;

    return (bool)((u32TmpVal != 0U) ? true : false);
}

/**
 * @brief Check whether the conversion result is in the comparing range
 *
 * @param pHsadc the base address of the HSADC instance
 * @return true the conversion result is in the comparing range
 * @return false the conversion result is not in the comparing range
 */
LOCAL_INLINE bool HSADC_HWA_GetCmpFlag(const HSADC_Type *const pHsadc)
{
    uint32_t u32TmpVal = pHsadc->INT_STATUS;
    u32TmpVal = (u32TmpVal & HSADC_INT_STATUS_ACMP_MASK) >> HSADC_INT_STATUS_ACMP_SHIFT;

    return (bool)((u32TmpVal != 0U) ? true : false);
}

/**
 * @brief Clear the compare flag
 *
 * @param pHsadc the base address of the HSADC instance
 */
LOCAL_INLINE void HSADC_HWA_ClearCmpFlag(HSADC_Type *const pHsadc)
{
    pHsadc->INT_STATUS = HSADC_INT_STATUS_ACMP(1U);
}

/**
 * @brief Check whether the HSADC FIFO is empty
 *
 * @param pHsadc the base address of the HSADC instance
 * @return true the HSADC FIFO is empty
 * @return false the HSADC FIFO is not empty
 */
LOCAL_INLINE bool HSADC_HWA_GetFIFOEmptyFlag(const HSADC_Type *const pHsadc)
{
    uint32_t u32TmpVal = pHsadc->INT_STATUS;
    u32TmpVal = (u32TmpVal & HSADC_INT_STATUS_EMPTY_MASK) >> HSADC_INT_STATUS_EMPTY_SHIFT;

    return (bool)((u32TmpVal != 0U) ? true : false);
}

/**
 * @brief Check whether the HSADC FIFO is full
 *
 * @param pHsadc the base address of the HSADC instance
 * @return true the HSADC FIFO is full
 * @return false the HSADC FIFO is not full
 */
LOCAL_INLINE bool HSADC_HWA_GetFIFOFullFlag(const HSADC_Type *const pHsadc)
{
    uint32_t u32TmpVal = pHsadc->INT_STATUS;
    u32TmpVal = (u32TmpVal & HSADC_INT_STATUS_FULL_MASK) >> HSADC_INT_STATUS_FULL_SHIFT;

    return (bool)((u32TmpVal != 0U) ? true : false);
}

/**
 * @brief Get the overrrun status of the HSADC instance
 *
 * @param pHsadc the base address of the HSADC instance
 * @return true the HSADC is in overrun status
 * @return false the HSADC is not overrun
 */
LOCAL_INLINE bool HSADC_HWA_GetOverrunFlag(const HSADC_Type *const pHsadc)
{
    uint32_t u32TmpVal = pHsadc->INT_STATUS;
    u32TmpVal = (u32TmpVal & HSADC_INT_STATUS_OVR_MASK) >> HSADC_INT_STATUS_OVR_SHIFT;

    return (bool)((u32TmpVal != 0U) ? true : false);
}

/**
 * @brief Clear the overrun flag of the HSADC instance
 *
 * @param pHsadc the base address of the HSADC instance
 */
LOCAL_INLINE void HSADC_HWA_ClearOverrunFlag(HSADC_Type *const pHsadc)
{
    pHsadc->INT_STATUS = HSADC_INT_STATUS_OVR(1U);
}

/**
 * @brief Check whether the HSADC conversion sequence is finished
 *
 * @param pHsadc the base address of the HSADC instance
 * @return true the HSADC conversion sequence is finished
 * @return false the HSADC conversion sequence is unfinished
 */
LOCAL_INLINE bool HSADC_HWA_GetEndOfSequenceFlag(const HSADC_Type *const pHsadc)
{
    uint32_t u32TmpVal = pHsadc->INT_STATUS;
    u32TmpVal = (u32TmpVal & HSADC_INT_STATUS_EOSEQ_MASK) >> HSADC_INT_STATUS_EOSEQ_SHIFT;

    return (bool)((u32TmpVal != 0U) ? true : false);
}

/**
 * @brief Clear the HSADC conversion sequence complete flag
 *
 * @param pHsadc the base address of the HSADC instance
 */
LOCAL_INLINE void HSADC_HWA_ClearEndOfSequenceFlag(HSADC_Type *const pHsadc)
{
    pHsadc->INT_STATUS = HSADC_INT_STATUS_EOSEQ(1U);
}

/**
 * @brief Check whether the current HSADC conversion is finished
 *
 * @param pHsadc the base address of the HSADC instance
 * @return true the current HSADC conversion is finished
 * @return false the current HSADC conversion is unfinished
 */
LOCAL_INLINE bool HSADC_HWA_GetEndOfConversionFlag(const HSADC_Type *const pHsadc)
{
    uint32_t u32TmpVal = pHsadc->INT_STATUS;
    u32TmpVal = (u32TmpVal & HSADC_INT_STATUS_EOC_MASK) >> HSADC_INT_STATUS_EOC_SHIFT;

    return (bool)((u32TmpVal != 0U) ? true : false);
}

/**
 * @brief Clear the HSADC single conversion complete flag
 *
 * @param pHsadc the base address of the HSADC instance
 */
LOCAL_INLINE void HSADC_HWA_ClearEndOfConversionFlag(HSADC_Type *const pHsadc)
{
    pHsadc->INT_STATUS = HSADC_INT_STATUS_EOC(1U);
}

/**
 * @brief Check whether the sampling phase of the current HSADC conversion is finished
 *
 * @param pHsadc the base address of the HSADC instance
 * @return true the sampling phase of the HSADC conversion is finished
 * @return false the sampling phase of the HSADC conversion is unfinished
 */
LOCAL_INLINE bool HSADC_HWA_GetEndOfSampleFlag(const HSADC_Type *const pHsadc)
{
    uint32_t u32TmpVal = pHsadc->INT_STATUS;
    u32TmpVal = (u32TmpVal & HSADC_INT_STATUS_EOSMP_MASK) >> HSADC_INT_STATUS_EOSMP_SHIFT;

    return (bool)((u32TmpVal != 0U) ? true : false);
}

/**
 * @brief Clear the HSADC sampling complete flag
 *
 * @param pHsadc the base address of the HSADC instance
 */
LOCAL_INLINE void HSADC_HWA_ClearEndOfSampleFlag(HSADC_Type *const pHsadc)
{
    pHsadc->INT_STATUS = HSADC_INT_STATUS_EOSMP(1U);
}

/**
 * @brief Check whether the HSADC instance is ready to operate
 *
 * @param pHsadc the base address of the HSADC instance
 * @return true the HSADC instance is ready for a new conversion
 * @return false the HSADC instance is unready
 */
LOCAL_INLINE bool HSADC_HWA_GetHSADCReadyFlag(const HSADC_Type *const pHsadc)
{
    uint32_t u32TmpVal = pHsadc->INT_STATUS;
    u32TmpVal = (u32TmpVal & HSADC_INT_STATUS_ADRDY_MASK) >> HSADC_INT_STATUS_ADRDY_SHIFT;

    return (bool)((u32TmpVal != 0U) ? true : false);
}

/**
 * @brief Clear the ready flag of the HSADC instance
 *
 * @param pHsadc the base address of the HSADC instance
 */
LOCAL_INLINE void HSADC_HWA_ClearHSADCReadyFlag(HSADC_Type *const pHsadc)
{
    pHsadc->INT_STATUS = HSADC_INT_STATUS_ADRDY(1U);
}

/**
 * @brief Get the fast compare falling edge interrupt
 * If enabled, HSADC interrupt is generated when detect fast compare falling edge
 * @param pHsadc the base address of the HSADC instance
 * @return true fast compare falling interrupt is enabled
 * @return false fast compare falling interrupt is disabled
 */
LOCAL_INLINE bool HSADC_HWA_GetFCRFIntEnable(const HSADC_Type *const pHsadc)
{
    uint32_t u32TmpVal = (pHsadc->INT_ENABLE & HSADC_INT_ENABLE_FCR_F_IE_MASK) >> HSADC_INT_ENABLE_FCR_F_IE_SHIFT;
    return (bool)((u32TmpVal != 0U) ? true : false);
}

/**
 * @brief Set the fast compare falling edge interrupt
 * If enabled, HSADC interrupt is generated when detect fast compare falling edge
 * @param pHsadc the base address of the HSADC instance
 * @param bEnable whether to enable the fast compare falling interrupt
 */
LOCAL_INLINE void HSADC_HWA_SetFCRFIntEnable(HSADC_Type *const pHsadc, bool bEnable)
{
    pHsadc->INT_ENABLE = (pHsadc->INT_ENABLE & ~HSADC_INT_ENABLE_FCR_F_IE_MASK) | HSADC_INT_ENABLE_FCR_F_IE(bEnable);
}

/**
 * @brief Get the fast compare rising edge interrupt
 * If enabled, ADC interrupt is generated when detect fast compare rising edge
 * @param pAdc the base address of the ADC instance
 * @return true fast compare rising interrupt is enabled
 * @return false fast compare rising interrupt is disabled
 */
LOCAL_INLINE bool HSADC_HWA_GetFCRRIntEnable(const HSADC_Type *const pHsadc)
{
    uint32_t u32TmpVal = (pHsadc->INT_ENABLE & HSADC_INT_ENABLE_FCR_R_IE_MASK) >> HSADC_INT_ENABLE_FCR_R_IE_SHIFT;
    return (bool)((u32TmpVal != 0U) ? true : false);
}

/**
 * @brief Set the fast compare rising edge interrupt
 * If enabled, HSADC interrupt is generated when detect fast compare rising edge
 * @param pHsadc the base address of the HSADC instance
 * @param bEnable whether to enable the fast compare rising interrupt
 */
LOCAL_INLINE void HSADC_HWA_SetFCRRIntEnable(HSADC_Type *const pHsadc, bool bEnable)
{
    pHsadc->INT_ENABLE = (pHsadc->INT_ENABLE & ~HSADC_INT_ENABLE_FCR_R_IE_MASK) | HSADC_INT_ENABLE_FCR_R_IE(bEnable);
}

/**
 * @brief Get the FIFO Ready interrupt flag
 * If enabled, HSADC interrupt is generated when the FIFO water mark is greater than FWMARK
 * @param pHsadc the base address of the HSADC instance
 * @return true HSADC FIFO Ready interrupt is enabled
 * @return false HSADC FIFO Ready interrupt is disabled
 */
LOCAL_INLINE bool HSADC_HWA_GetFIFOReadyIntEnable(const HSADC_Type *const pHsadc)
{
    uint32_t u32TmpVal = (pHsadc->INT_ENABLE & HSADC_INT_ENABLE_FIFO_RDY_IE_MASK) >> HSADC_INT_ENABLE_FIFO_RDY_IE_SHIFT;
    return (bool)((u32TmpVal != 0U) ? true : false);
}

/**
 * @brief Set the FIFO Ready interrupt flag
 * If enabled, HSADC interrupt is generated when the FIFO water mark is greater than FWMARK
 * @param pHsadc the base address of the HSADC instance
 * @param bEnable whether to enable the HSADC FIFO Ready interrupt
 */
LOCAL_INLINE void HSADC_HWA_SetFIFOReadyIntEnable(HSADC_Type *const pHsadc, bool bEnable)
{
    pHsadc->INT_ENABLE = (pHsadc->INT_ENABLE & ~HSADC_INT_ENABLE_FIFO_RDY_IE_MASK) | HSADC_INT_ENABLE_FIFO_RDY_IE(bEnable);
}

/**
 * @brief Get the Compare interrupt flag
 * If enabled, HSADC interrupt is generated when the HSADC conversion result is not within the compare threshold
 * @param pHsadc the base address of the HSADC instance
 * @return true HSADC Compare interrupt is enabled
 * @return false HSADC Compare interrupt is disabled
 */
LOCAL_INLINE bool HSADC_HWA_GetCmpIntEnable(const HSADC_Type *const pHsadc)
{
    uint32_t u32TmpVal = (pHsadc->INT_ENABLE & HSADC_INT_ENABLE_ACMP_IE_MASK) >> HSADC_INT_ENABLE_ACMP_IE_SHIFT;
    return (bool)((u32TmpVal != 0U) ? true : false);
}

/**
 * @brief Set the Compare interrupt flag
 * If enabled, HSADC interrupt is generated when the HSADC conversion result is not within the compare threshold
 * @param pHsadc the base address of the HSADC instance
 * @param bEnable whether to enable the HSADC Compare interrupt
 */
LOCAL_INLINE void HSADC_HWA_SetCmpIntEnable(HSADC_Type *const pHsadc, bool bEnable)
{
    pHsadc->INT_ENABLE = (pHsadc->INT_ENABLE & ~HSADC_INT_ENABLE_ACMP_IE_MASK) | HSADC_INT_ENABLE_ACMP_IE(bEnable);
}

/**
 * @brief Get the Overrun interrupt flag
 * If enabled, HSADC interrupt is generated when the HSADC instance is overrun
 * @param pHsadc the base address of the HSADC instance
 * @return true HSADC Overrun interrupt is enabled
 * @return false HSADC Overrun interrupt is disabled
 */
LOCAL_INLINE bool HSADC_HWA_GetOverrunIntEnable(const HSADC_Type *const pHsadc)
{
    uint32_t u32TmpVal = (pHsadc->INT_ENABLE & HSADC_INT_ENABLE_OVRIE_MASK) >> HSADC_INT_ENABLE_OVRIE_SHIFT;
    return (bool)((u32TmpVal != 0U) ? true : false);
}

/**
 * @brief Set the Overrun interrupt flag
 * If enabled, HSADC interrupt is generated when the HSADC instance is overrun
 * @param pHsadc the base address of the HSADC instance
 * @param bEnable whether to enable the HSADC Overrun interrupt
 */
LOCAL_INLINE void HSADC_HWA_SetOverrunIntEnable(HSADC_Type *const pHsadc, bool bEnable)
{
    pHsadc->INT_ENABLE = (pHsadc->INT_ENABLE & ~HSADC_INT_ENABLE_OVRIE_MASK) | HSADC_INT_ENABLE_OVRIE(bEnable);
}

/**
 * @brief Get the End of Sequence interrupt enable flag
 * If enabled, HSADC interrupt is generated when the HSADC sequence conversion is completed
 * @param pHsadc the base address of the HSADC instance
 * @return true HSADC End of Sequence interrupt is enabled
 * @return false HSADC End of Sequence interrupt is disabled
 */
LOCAL_INLINE bool HSADC_HWA_GetEndOfSequenceIntEnable(const HSADC_Type *const pHsadc)
{
    uint32_t u32TmpVal = (pHsadc->INT_ENABLE & HSADC_INT_ENABLE_EOSEQIE_MASK) >> HSADC_INT_ENABLE_EOSEQIE_SHIFT;
    return (bool)((u32TmpVal != 0U) ? true : false);
}

/**
 * @brief Set the End of Sequence interrupt enable flag
 * If enabled, HSADC interrupt is generated when the HSADC sequence conversion is completed
 * @param pHsadc the base address of the HSADC instance
 * @param bEnable whether to enable the HSADC End of Sequence interrupt
 */
LOCAL_INLINE void HSADC_HWA_SetEndOfSequenceIntEnable(HSADC_Type *const pHsadc, bool bEnable)
{
    pHsadc->INT_ENABLE = (pHsadc->INT_ENABLE & ~HSADC_INT_ENABLE_EOSEQIE_MASK) | HSADC_INT_ENABLE_EOSEQIE(bEnable);
}

/**
 * @brief Get the conversion complete interrupt enable flag
 * If enabled, HSADC interrupt is generated when each HSADC conversion is completed
 * @param pHsadc the base address of the HSADC instance
 * @return true the HSADC End of Conversion interrupt is enabled
 * @return false the HSADC End of Conversion interrupt is disabled
 */
LOCAL_INLINE bool HSADC_HWA_GetEndOfConversionIntEnable(const HSADC_Type *const pHsadc)
{
    uint32_t u32TmpVal = (pHsadc->INT_ENABLE & HSADC_INT_ENABLE_EOCIE_MASK) >> HSADC_INT_ENABLE_EOCIE_SHIFT;
    return (bool)((u32TmpVal != 0U) ? true : false);
}

/**
 * @brief Set the conversion complete interrupt enable flag
 * If enabled, HSADC interrupt is generated when each HSADC conversion is completed
 * @param pHsadc the base address of the HSADC instance
 * @param bEnable whether to enable the conversion complete interrupt
 */
LOCAL_INLINE void HSADC_HWA_SetEndOfConversionIntEnable(HSADC_Type *const pHsadc, bool bEnable)
{
    pHsadc->INT_ENABLE = (pHsadc->INT_ENABLE & ~HSADC_INT_ENABLE_EOCIE_MASK) | HSADC_INT_ENABLE_EOCIE(bEnable);
}

/**
 * @brief Get the sample complete interrupt enable flag
 * If enabled, HSADC interrupt is generated when each HSADC conversion finished the sampling phase
 * @param pHsadc the base address of the HSADC instance
 * @return true the sample complete interrupt is enabled
 * @return false the sample complete interrupt is disabled
 */
LOCAL_INLINE bool HSADC_HWA_GetEndOfSampleIntEnable(const HSADC_Type *const pHsadc)
{
    uint32_t u32TmpVal = (pHsadc->INT_ENABLE & HSADC_INT_ENABLE_EOSMPIE_MASK) >> HSADC_INT_ENABLE_EOSMPIE_SHIFT;
    return (bool)((u32TmpVal != 0U) ? true : false);
}

/**
 * @brief Set the sample complete interrupt enable flag
 * If enabled, HSADC interrupt is generated when each HSADC conversion finished the sampling phase
 * @param pHsadc the base address of the HSADC instance
 * @param bEnable whether to enable the sample complete interrupt
 */
LOCAL_INLINE void HSADC_HWA_SetEndOfSampleIntEnable(HSADC_Type *const pHsadc, bool bEnable)
{
    pHsadc->INT_ENABLE = (pHsadc->INT_ENABLE & ~HSADC_INT_ENABLE_EOSMPIE_MASK) | HSADC_INT_ENABLE_EOSMPIE(bEnable);
}

/**
 * @brief Get the HSADC ready interrupt enable flag
 * If enabled, HSADC interrupt is generated when the HSADC module is ready for conversion
 * @param pHsadc the base address of the HSADC instance
 * @return true the HSADC ready interrupt is enabled
 * @return false the HSADC ready interrupt is disabled
 */
LOCAL_INLINE bool HSADC_HWA_GetHSADCReadyIntEnable(const HSADC_Type *const pHsadc)
{
    uint32_t u32TmpVal = (pHsadc->INT_ENABLE & HSADC_INT_ENABLE_ADRDYIE_MASK) >> HSADC_INT_ENABLE_ADRDYIE_SHIFT;
    return (bool)((u32TmpVal != 0U) ? true : false);
}

/**
 * @brief Set the HSADC ready interrupt enable flag
 * If enabled, HSADC interrupt is generated when the HSADC module is ready for conversion
 * @param pHsadc the base address of the HSADC instance
 * @param bEnable Whether to enable the HSADC ready interrupt
 */
LOCAL_INLINE void HSADC_HWA_SetHSADCReadyIntEnable(HSADC_Type *const pHsadc, bool bEnable)
{
    pHsadc->INT_ENABLE = (pHsadc->INT_ENABLE & ~HSADC_INT_ENABLE_ADRDYIE_MASK) | HSADC_INT_ENABLE_ADRDYIE(bEnable);
}

/**
 * @brief Get the interrupt enable config
 *
 * @param pHsadc the base address of the HSADC instance
 * @return uint32_t the interrupt enable config
 */
LOCAL_INLINE uint32_t HSADC_HWA_GetIntEnable(const HSADC_Type *const pHsadc)
{
    return pHsadc->INT_ENABLE;
}

/**
 * @brief Set the interrupt enable
 *
 * @param u32IntCfg the interrupt enable config
 */
LOCAL_INLINE void HSADC_HWA_SetInterruptEnable(HSADC_Type *const pHsadc, uint32_t u32IntCfg)
{
    pHsadc->INT_ENABLE = u32IntCfg;
}

/**
 * @brief Select HSADC function clock
 *
 * @param pHsadc the base address of the HSADC instance
 * @note To ensure stability, we recommend that the ADSTART ADSTOP ADEN ADDIS
 *       bits must be 0 before executing this function.
 */
LOCAL_INLINE void HSADC_HWA_SetFClkSel(HSADC_Type *const pHsadc, const HSADC_FunctionClockType Type)
{
    uint32_t u32TmpVal = pHsadc->CTRL & HSADC_CTRL_FCLK_SEL_MASK;
    pHsadc->CTRL = u32TmpVal | HSADC_CTRL_ADRST(1U);
    pHsadc->CTRL = HSADC_CTRL_ADRST(1U) | HSADC_CTRL_FCLK_SEL(Type);
    pHsadc->CTRL = HSADC_CTRL_FCLK_SEL(Type);
}

/**
 * @brief Assert the HSADC hardware Reset bit
 *
 * @param pHsadc the base address of the HSADC instance
 */
LOCAL_INLINE void HSADC_HWA_Reset(HSADC_Type *const pHsadc)
{
    uint32_t u32TmpVal = pHsadc->CTRL;
    pHsadc->CTRL = u32TmpVal | HSADC_CTRL_ADRST(1U);
    pHsadc->CTRL = u32TmpVal & ~HSADC_CTRL_ADRST_MASK;
}

/**
 * @brief Get whether HSADC is in stopping status
 *
 * @param pHsadc the base address of the HSADC instance
 * @return true the HSADC instance is stopping
 * @return false the HSADC instance is not in stopping status
 */
LOCAL_INLINE bool HSADC_HWA_GetStop(const HSADC_Type *const pHsadc)
{
    uint32_t u32TmpVal = pHsadc->CTRL;
    u32TmpVal = (u32TmpVal & HSADC_CTRL_ADSTP_MASK) >> HSADC_CTRL_ADSTP_SHIFT;

    return (bool)((u32TmpVal != 0U) ? true : false);
}

/**
 * @brief Stop the HSADC conversion
 *
 * @param pHsadc the base address of the HSADC instance
 */
LOCAL_INLINE void HSADC_HWA_Stop(HSADC_Type *const pHsadc)
{
    uint32_t u32TmpVal = pHsadc->CTRL;
    pHsadc->CTRL = u32TmpVal | HSADC_CTRL_ADSTP(1U);
}

/**
 * @brief Get the conversion start status of the HSADC instance
 *
 * @param pHsadc the base address of the HSADC instance
 * @return true the conversion of the HSADC instance is started
 * @return false the conversion of the HSADC instance has not been started
 */
LOCAL_INLINE bool HSADC_HWA_GetStart(const HSADC_Type *const pHsadc)
{
    uint32_t u32TmpVal = pHsadc->CTRL;
    u32TmpVal = (u32TmpVal & HSADC_CTRL_ADSTART_MASK) >> HSADC_CTRL_ADSTART_SHIFT;

    return (bool)((u32TmpVal != 0U) ? true : false);
}

/**
 * @brief Start the HSADC conversion
 *
 * @param pHsadc the base address of the HSADC instance
 */
LOCAL_INLINE void HSADC_HWA_Start(HSADC_Type *const pHsadc)
{
    uint32_t u32TmpVal = pHsadc->CTRL;
    pHsadc->CTRL = (u32TmpVal | HSADC_CTRL_ADSTART(1U));
}

/**
 * @brief Get whether the HSADC instance is in disable status
 *
 * @param pHsadc the base address of the HSADC instance
 * @return true the HSADC instance is in disable status
 * @return false the HSADC instance is not in disable status
 */
LOCAL_INLINE bool HSADC_HWA_GetDisable(const HSADC_Type *const pHsadc)
{
    uint32_t u32TmpVal = pHsadc->CTRL;
    u32TmpVal = (u32TmpVal & HSADC_CTRL_ADDIS_MASK) >> HSADC_CTRL_ADDIS_SHIFT;

    return (bool)((u32TmpVal != 0U) ? true : false);
}

/**
 * @brief Disable the HSADC instance
 *
 * @param pHsadc the base address of the HSADC instance
 */
LOCAL_INLINE void HSADC_HWA_Disable(HSADC_Type *const pHsadc)
{
    uint32_t u32TmpVal = pHsadc->CTRL;
    pHsadc->CTRL = u32TmpVal | HSADC_CTRL_ADDIS(1U);
}

/**
 * @brief Get the enable status of the HSADC instance
 *
 * @param pHsadc the base address of the HSADC instance
 * @return true the HSADC instance is enabled
 * @return false the HSADC instance has not been enabled
 */
LOCAL_INLINE bool HSADC_HWA_GetEnable(const HSADC_Type *const pHsadc)
{
    uint32_t u32TmpVal = pHsadc->CTRL;
    u32TmpVal = (u32TmpVal & HSADC_CTRL_ADEN_MASK) >> HSADC_CTRL_ADEN_SHIFT;

    return (bool)((u32TmpVal != 0U) ? true : false);
}

/**
 * @brief Enable the HSADC instance
 *
 * @param pHsadc the base address of the HSADC instance
 */
LOCAL_INLINE void HSADC_HWA_Enable(HSADC_Type *const pHsadc)
{
    uint32_t u32TmpVal = pHsadc->CTRL;
    pHsadc->CTRL = u32TmpVal | HSADC_CTRL_ADEN(1U);
}

/**
 * @brief Get the overrun mode
 *
 * @param pHsadc the base address of the HSADC instance
 * @return HSADC_OVERRUN_MODE_PRESERVE the conversion data is preserved when HSADC is overrun
 * @return HSADC_OVERRUN_MODE_OVERWRITE the conversion data is overwritten when HSADC is overrun
 */
LOCAL_INLINE HSADC_OvrModeType HSADC_HWA_GetOverrunMode(const HSADC_Type *const pHsadc)
{
    uint32_t u32TmpVal = (pHsadc->CFG1 & HSADC_CFG1_OVRMOD_MASK) >> HSADC_CFG1_OVRMOD_SHIFT;
    return (HSADC_OvrModeType)u32TmpVal;
}

/**
 * @brief Set the overrun mode
 *
 * @param pHsadc the base address of the HSADC instance
 * @param eOvrMode the overrun mode for the HSADC instance
 */
LOCAL_INLINE void HSADC_HWA_SetOverrunMode(HSADC_Type *const pHsadc, HSADC_OvrModeType eOvrMode)
{
    pHsadc->CFG1 = (pHsadc->CFG1 & ~HSADC_CFG1_OVRMOD_MASK) | HSADC_CFG1_OVRMOD(eOvrMode);
}

/**
 * @brief Get the sequence group mode state
 *
 * @param pHsadc the base address of the HSADC instance
 * @return the sequence group mode state
 */
LOCAL_INLINE bool HSADC_HWA_GetSGEnable(const HSADC_Type *const pHsadc)
{
    uint32_t u32TmpVal = (pHsadc->CFG1 & HSADC_CFG1_SEQGP_EN_MASK) >> HSADC_CFG1_SEQ_LEN_SHIFT;
    return u32TmpVal ? true : false;
}

/**
 * @brief Set the sequence group mode state
 *
 * @param pHsadc the base address of the HSADC instance
 * @param the sequence group mode state
 */
LOCAL_INLINE void HSADC_HWA_SetSGEnable(HSADC_Type *const pHsadc, bool bEnable)
{
    pHsadc->CFG1 = (pHsadc->CFG1 & ~HSADC_CFG1_SEQGP_EN_MASK) | HSADC_CFG1_SEQGP_EN(bEnable);
}

/**
 * @brief Get the sequence length of the HSADC conversion sequence
 *
 * @param pHsadc the base address of the HSADC instance
 * @return uint8_t the sequence length of the HSADC conversion sequence
 */
LOCAL_INLINE uint8_t HSADC_HWA_GetSequenceLength(const HSADC_Type *const pHsadc)
{
    uint32_t u32TmpVal = pHsadc->CFG1;
    u32TmpVal = (u32TmpVal & HSADC_CFG1_SEQ_LEN_MASK) >> HSADC_CFG1_SEQ_LEN_SHIFT;

    return (uint8_t)u32TmpVal;
}

/**
 * @brief Set the sequence length of the HSADC conversion sequence
 *
 * @param pHsadc the base address of the HSADC instance
 * @param u8SequenceLength the sequence length of the HSADC conversion sequence
 */
LOCAL_INLINE void HSADC_HWA_SetSequenceLength(HSADC_Type *const pHsadc, uint8_t u8SequenceLength)
{
    pHsadc->CFG1 = (pHsadc->CFG1 & ~HSADC_CFG1_SEQ_LEN_MASK) | HSADC_CFG1_SEQ_LEN(u8SequenceLength);
}

/**
 * @brief Get the HSADC sequence mode
 *
 * @param pHsadc the base address of the HSADC instance
 * @return HSADC_SeqModeType the sequence mode the the HSADC instance
 */
LOCAL_INLINE HSADC_SeqModeType HSADC_HWA_GetSequenceMode(const HSADC_Type *const pHsadc)
{
    uint32_t u32TmpVal = pHsadc->CFG1;
    u32TmpVal = (u32TmpVal & HSADC_CFG1_SEQ_MOD_MASK) >> HSADC_CFG1_SEQ_MOD_SHIFT;

    return (HSADC_SeqModeType)u32TmpVal;
}

/**
 * @brief Set the HSADC sequence mode
 *
 * @param pHsadc the base address of the HSADC instance
 * @param eSequenceMode the sequence mode the the HSADC instance
 */
LOCAL_INLINE void HSADC_HWA_SetSequenceMode(HSADC_Type *const pHsadc, HSADC_SeqModeType eSequenceMode)
{
    pHsadc->CFG1 = (pHsadc->CFG1 & ~HSADC_CFG1_SEQ_MOD_MASK) | HSADC_CFG1_SEQ_MOD(eSequenceMode);
}

/**
 * @brief Get whether auto disable is enabled
 *
 * @note Auto disable mode is only available in FC7300F2M
 *
 * @param pHsadc the base address of the HSADC instance
 * @return true  auto disable mode is enabled
 * @return false auto disable mode is disabled
 */
LOCAL_INLINE bool HSADC_HWA_GetAutoDisableModeEnable(const HSADC_Type *const pHsadc)
{
    uint32_t u32TmpVal = pHsadc->CFG1;
    u32TmpVal = (u32TmpVal & HSADC_CFG1_AUTO_DIS_MASK) >> HSADC_CFG1_AUTO_DIS_SHIFT;

    return (bool)((u32TmpVal != 0U) ? true : false);
}

/**
 * @brief Set whether to enable auto disable mode
 *
 * @note Auto disable mode is only available in FC7300F2M
 *
 * @param pHsadc the base address of the HSADC instance
 * @param bEnable whether to enable auto disable mode
 */
LOCAL_INLINE void HSADC_HWA_SetAutoDisableModeEnable(HSADC_Type *const pHsadc, bool bEnable)
{
    pHsadc->CFG1 = (pHsadc->CFG1 & ~HSADC_CFG1_AUTO_DIS_MASK) | HSADC_CFG1_AUTO_DIS(bEnable);
}

/**
 * @brief Get whether the wait conversion mode is enabled
 *
 * @param pHsadc the base address of the HSADC instance
 * @return true the wait conversion mode is enabled
 * @return false the wait conversion mode is disabled
 */
LOCAL_INLINE bool HSADC_HWA_GetWaitConversionModeEnable(const HSADC_Type *const pHsadc)
{
    uint32_t u32TmpVal = (pHsadc->CFG1 & HSADC_CFG1_WAIT_MASK) >> HSADC_CFG1_WAIT_SHIFT;
    return (bool)((u32TmpVal != 0U) ? true : false);
}

/**
 * @brief Set the wait conversion mode
 *
 * @param pHsadc the base address of the HSADC instance
 * @param bEnable whether to enable the wait conversion mode
 */
LOCAL_INLINE void HSADC_HWA_SetWaitConversionModeEnable(HSADC_Type *const pHsadc, bool bEnable)
{
    pHsadc->CFG1 = (pHsadc->CFG1 & ~HSADC_CFG1_WAIT_MASK) | HSADC_CFG1_WAIT(bEnable);
}

/**
 * @brief Get the trigger source the the HSADC instance
 *
 * @param pHsadc the base address of the HSADC instance
 * @return HSADC_TrigSrcType the trigger source of the HSADC instance
 */
LOCAL_INLINE HSADC_TrgSrcType HSADC_HWA_GetTriggerSource(const HSADC_Type *const pHsadc)
{
    uint32_t u32TmpVal = pHsadc->CFG1;
    u32TmpVal = (u32TmpVal & HSADC_CFG1_TRIGSRC_MASK) >> HSADC_CFG1_TRIGSRC_SHIFT;

    return (HSADC_TrgSrcType)u32TmpVal;
}

/**
 * @brief Set the trigger source the the HSADC instance
 *
 * @param pHsadc the base address of the HSADC instance
 * @param eTriggerSource the trigger source of the HSADC instance
 */
LOCAL_INLINE void HSADC_HWA_SetTriggerSource(HSADC_Type *const pHsadc, HSADC_TrgSrcType eTrgSource)
{
    pHsadc->CFG1 = (pHsadc->CFG1 & ~HSADC_CFG1_TRIGSRC_MASK) | HSADC_CFG1_TRIGSRC(eTrgSource);
}

/**
 * @brief Get the trigger mode of the HSADC instance
 *
 * @param pHsadc the base address of the HSADC instance
 * @return HSADC_TrigModeType the trigger mode if the HSADC instance
 */
LOCAL_INLINE HSADC_TrgModeType HSADC_HWA_GetTriggerMode(const HSADC_Type *const pHsadc)
{
    uint32_t u32TmpVal = pHsadc->CFG1;
    u32TmpVal = (u32TmpVal & HSADC_CFG1_TRIGMODE_MASK) >> HSADC_CFG1_TRIGMODE_SHIFT;

    return (HSADC_TrgModeType)u32TmpVal;
}

/**
 * @brief Set the trigger mode of the HSADC instance
 *
 * @param pHsadc the base address of the HSADC instance
 * @param eTriggerMode the trigger mode if the HSADC instance
 */
LOCAL_INLINE void HSADC_HWA_SetTriggerMode(HSADC_Type *const pHsadc, HSADC_TrgModeType eTrgMode)
{
    pHsadc->CFG1 = (pHsadc->CFG1 & ~HSADC_CFG1_TRIGMODE_MASK) | HSADC_CFG1_TRIGMODE(eTrgMode);
}

/**
 * @brief Get the data align mode
 *
 * @param pHsadc the base address of the HSADC instance
 * @return HSADC_ALIGN_RIGHT the conversion data is aligned right
 * @return HSADC_ALIGN_LEFT the conversion is aligned left
 */
LOCAL_INLINE HSADC_AlignType HSADC_HWA_GetDataAlignment(const HSADC_Type *const pHsadc)
{
    uint32_t u32TmpVal = (pHsadc->CFG1 & HSADC_CFG1_ALIGN_MASK) >> HSADC_CFG1_ALIGN_SHIFT;
    return (HSADC_AlignType)u32TmpVal;
}

/**
 * @brief Set the data align mode
 *
 * @param pHsadc the base address of the HSADC instance
 * @param eAlign the data align mode
 */
LOCAL_INLINE void HSADC_HWA_SetDataAlignment(HSADC_Type *const pHsadc, HSADC_AlignType eAlign)
{
    pHsadc->CFG1 = (pHsadc->CFG1 & ~HSADC_CFG1_ALIGN_MASK) | HSADC_CFG1_ALIGN(eAlign);
}

/**
 * @brief Get SGDMA SEL for the HSADC instance
 *
 * @param pHsadc the base address of the HSADC instance
 * @return the SGDMA SEL for the HSADC instance
 */
LOCAL_INLINE uint8_t HSADC_HWA_GetSGDMASEL(const HSADC_Type *const pHsadc)
{
    return (pHsadc->CFG1 & HSADC_CFG1_SGDMA_SEL_MASK) >> HSADC_CFG1_SGDMA_SEL_SHIFT;
}

/**
 * @brief Set the SGDMA SEL for the HSADC instance
 *
 * @param pHsadc the base address of the HSADC instance
 * @param bEnable the SGDMA SEL for the HSADC instance
 */
LOCAL_INLINE void HSADC_HWA_SetSGDMASEL(HSADC_Type *const pHsadc, uint8_t index)
{
    pHsadc->CFG1 = (pHsadc->CFG1 & ~HSADC_CFG1_SGDMA_SEL_MASK) | HSADC_CFG1_SGDMA_SEL(index);
}

/**
 * @brief Get whether SGDMA for the HSADC instance is enabled
 *
 * @param pHsadc the base address of the HSADC instance
 * @return true SGDMA is enabled for the HSADC instance
 * @return false SGDMA is disabled for the HSADC instance
 */
LOCAL_INLINE bool HSADC_HWA_GetSGDMAEnable(const HSADC_Type *const pHsadc)
{
    uint32_t u32TmpVal = (pHsadc->CFG1 & HSADC_CFG1_SGDMAEN_MASK) >> HSADC_CFG1_SGDMAEN_SHIFT;
    return (bool)((u32TmpVal != 0U) ? true : false);
}

/**
 * @brief Enable or disable the SGDMA for the HSADC instance
 *
 * @param pHsadc the base address of the HSADC instance
 * @param bEnable whether to enable the SGDMA for the HSADC instance
 */
LOCAL_INLINE void HSADC_HWA_SetSGDMAEnable(HSADC_Type *const pHsadc, bool bEnable)
{
    pHsadc->CFG1 = (pHsadc->CFG1 & ~HSADC_CFG1_SGDMAEN_MASK) | HSADC_CFG1_DMAEN(bEnable);
}

/**
 * @brief Get whether DMA for the HSADC instance is enabled
 *
 * @param pHsadc the base address of the HSADC instance
 * @return true DMA is enabled for the HSADC instance
 * @return false DMA is disabled for the HSADC instance
 */
LOCAL_INLINE bool HSADC_HWA_GetDMAEnable(const HSADC_Type *const pHsadc)
{
    uint32_t u32TmpVal = (pHsadc->CFG1 & HSADC_CFG1_DMAEN_MASK) >> HSADC_CFG1_DMAEN_SHIFT;
    return (bool)((u32TmpVal != 0U) ? true : false);
}

/**
 * @brief Enable or disable the DMA for the HSADC instance
 *
 * @param pHsadc the base address of the HSADC instance
 * @param bEnable whether to enable the DMA for the HSADC instance
 */
LOCAL_INLINE void HSADC_HWA_SetDMAEnable(HSADC_Type *const pHsadc, bool bEnable)
{
    pHsadc->CFG1 = (pHsadc->CFG1 & ~HSADC_CFG1_DMAEN_MASK) | HSADC_CFG1_DMAEN(bEnable);
}

/**
 * @brief Get the HSADC_CFG1 config
 *
 * @param pHsadc the base address of the HSADC instance
 * @return uint32_t the HSADC_CFG1 config
 */
LOCAL_INLINE uint32_t HSADC_HWA_GetConfig1(const HSADC_Type *const pHsadc)
{
    return pHsadc->CFG1;
}

/**
 * @brief Set the HSADC_CFG1 config
 *
 * @param pHsadc the base address of the HSADC instance
 * @param u32Config the HSADC_CFG1 config
 */
LOCAL_INLINE void HSADC_HWA_SetConfig1(HSADC_Type *const pHsadc, uint32_t u32Config)
{
    pHsadc->CFG1 = u32Config;
}

/**
 * @brief Get the extend channel enable settings for the HSADC instance
 *
 * @param pHsadc the base address of the HSADC instance
 * @return bool the HSADC extend channel enable setting
 */
LOCAL_INLINE bool HSADC_HWA_GetExtChEnable(const HSADC_Type *const pHsadc)
{
    uint32_t u32TmpVal = (pHsadc->CFG2 & HSADC_CFG2_EXT_CH_EN_MASK) >> HSADC_CFG2_EXT_CH_EN_SHIFT;
    return u32TmpVal ? true : false;
}

/**
 * @brief Set the extend channel feature for the HSADC instance
 *
 * @param pHsadc the base address of the HSADC instance
 * @param bEnable the enable/disable flag
 */
LOCAL_INLINE void HSADC_HWA_SetExtChEnable(HSADC_Type *const pHsadc, bool bEnable)
{
    pHsadc->CFG2 = (pHsadc->CFG2 & ~HSADC_CFG2_EXT_CH_EN_MASK) | HSADC_CFG2_EXT_CH_EN(bEnable);
}

/**
 * @brief Get the FIFO water mark settings for the HSADC instance
 *
 * @param pHsadc the base address of the HSADC instance
 * @return uint8_t the HSADC FIFO water mark setting
 */
LOCAL_INLINE uint8_t HSADC_HWA_GetFIFOWaterMark(const HSADC_Type *const pHsadc)
{
    uint32_t u32TmpVal = (pHsadc->CFG2 & HSADC_CFG2_FWMARK_MASK) >> HSADC_CFG2_FWMARK_SHIFT;
    return (uint8_t)u32TmpVal;
}

/**
 * @brief Set the FIFO water mark for the HSADC instance
 *
 * @param pHsadc the base address of the HSADC instance
 * @param u8WaterMark the HSADC FIFO water mark setting
 */
LOCAL_INLINE void HSADC_HWA_SetFIFOWaterMark(HSADC_Type *const pHsadc, uint8_t u8WaterMark)
{
    pHsadc->CFG2 = (pHsadc->CFG2 & ~HSADC_CFG2_FWMARK_MASK) | HSADC_CFG2_FWMARK(u8WaterMark);
}

LOCAL_INLINE uint8_t HSADC_HWA_GetSmpSpare(const HSADC_Type *const pHsadc)
{
    uint32_t u32TmpVal = (pHsadc->CFG2 & HSADC_CFG2_SMP_SPARE_EN_MASK) >> HSADC_CFG2_SMP_SPARE_EN_SHIFT;
    return (uint8_t)u32TmpVal;
}

LOCAL_INLINE void HSADC_HWA_SetSmpSpare(HSADC_Type *const pHsadc, bool bEnable)
{
    pHsadc->CFG2 = (pHsadc->CFG2 & ~HSADC_CFG2_SMP_SPARE_EN_MASK) | HSADC_CFG2_SMP_SPARE_EN(bEnable);
}

/**
 * @brief Get the priority of Trigger Latch
 *
 * @param pHsadc the base address of the HSADC instance
 */
LOCAL_INLINE uint8_t HSADC_HWA_GetTriggerLatchUnitPriority(const HSADC_Type *const pHsadc)
{
    uint32_t u32TmpVal = (pHsadc->CFG2 & HSADC_CFG2_TRG_PRI_MASK) >> HSADC_CFG2_TRG_PRI_SHIFT;
    return (uint8_t)u32TmpVal;
}

/**
 * @brief Set the priority of Trigger Latch
 *
 * @param pHsadc the base address of the HSADC instance
 * @param eTrgLatchUnitPri the priority of Trigger Latch Unit setting
 */
LOCAL_INLINE void HSADC_HWA_SetTriggerLatchUnitPriority(HSADC_Type *const pHsadc, HSADC_TrgLatchUnitPri eTrgLatchUnitPri)
{
    pHsadc->CFG2 = (pHsadc->CFG2 & ~HSADC_CFG2_TRG_CLR_MASK) | HSADC_CFG2_TRG_CLR(eTrgLatchUnitPri);
}

/**
 * @brief Clear Latch Trigger in Trigger Latch Unit
 *
 * @param pHsadc the base address of the HSADC instance
 */
LOCAL_INLINE void HSADC_HWA_ClearLatchTrigger(HSADC_Type *const pHsadc)
{
    uint32_t u32TmpVal = pHsadc->CFG2;
    pHsadc->CFG2 = u32TmpVal | HSADC_CFG2_TRG_CLR(1);
}

/**
 * @brief Get whether hardware average is enabled
 *
 * @param pHsadc the base address of the HSADC instance
 * @return true hardware average is enabled
 * @return false hardware average is disabled
 */
LOCAL_INLINE bool HSADC_HWA_GetAverageEnable(const HSADC_Type *const pHsadc)
{
    uint32_t u32TmpVal = (pHsadc->CFG2 & HSADC_CFG2_AVG_EN_MASK) >> HSADC_CFG2_AVG_EN_SHIFT;
    return (bool)((u32TmpVal != 0U) ? true : false);
}

/**
 * @brief Enable or disable hardware average for the HSADC instance
 *
 * @param pHsadc the base address of the HSADC instance
 * @param bEnable whether to enable the HSADC hardware average
 */
LOCAL_INLINE void HSADC_HWA_SetAverageEnable(HSADC_Type *const pHsadc, bool bEnable)
{
    pHsadc->CFG2 = (pHsadc->CFG2 & ~HSADC_CFG2_AVG_EN_MASK) | HSADC_CFG2_AVG_EN(bEnable);
}

/**
 * @brief Get the hardware average number
 *
 * @param pHsadc the base address of the HSADC instance
 * @return HSADC_AverageType the hardware average number
 */
LOCAL_INLINE HSADC_AverageLenType HSADC_HWA_GetAverageNumber(const HSADC_Type *const pHsadc)
{
    uint32_t u32TmpVal = (pHsadc->CFG2 & HSADC_CFG2_AVG_LEN_MASK) >> HSADC_CFG2_AVG_LEN_SHIFT;
    return (HSADC_AverageLenType)u32TmpVal;
}

/**
 * @brief Set the hardware average number
 *
 * @param pHsadc the base address of the HSADC instance
 * @param eAverageNumber the hardware average number to set
 */
LOCAL_INLINE void HSADC_HWA_SetAverageNumber(HSADC_Type *const pHsadc, HSADC_AverageLenType eAverageNumber)
{
    pHsadc->CFG2 = (pHsadc->CFG2 & ~HSADC_CFG2_AVG_LEN_MASK) | HSADC_CFG2_AVG_LEN(eAverageNumber);
}
/**
 * @brief Whether clock gating is acknowledged
 *
 * @note This feature is only available in FC7300F2M
 *
 * @param pHsadc the base address of the HSADC instance
 * @return true HSADC clock source is off after setting Clock Gating Enable Flag
 * @return false HSADC clock source is on after clearing Clock Gating Enable Flag
 */
LOCAL_INLINE bool HSADC_HWA_GetClockGatingAck(const HSADC_Type *const pHsadc)
{
    uint32_t u32TmpVal = (pHsadc->CFG2 & HSADC_CFG2_CG_ACK_MASK) >> HSADC_CFG2_CG_ACK_SHIFT;
    return (bool)((u32TmpVal != 0U) ? true : false);
}

/**
 * @brief Get whether clock gating is enabled
 *
 * @note This feature is only available in FC7300F2M
 *
 * @param pHsadc the base address of the HSADC instance
 * @return true Clock gating is enabled, HSADC clock is off
 * @return false Clock gating is disabled, HSADC clock is on
 */
LOCAL_INLINE bool HSADC_HWA_GetClockGatingEnable(const HSADC_Type *const pHsadc)
{
    uint32_t u32TmpVal = (pHsadc->CFG2 & HSADC_CFG2_CG_MASK) >> HSADC_CFG2_CG_SHIFT;
    return (bool)((u32TmpVal != 0U) ? true : false);
}

/**
 * @brief Set whether to enable HSADC clock gating
 *
 * @note This feature is only available in FC7300F2M
 *
 * @param pHsadc the base address of the HSADC instance
 * @param bEnable whether to enable HSADC clock gating
 */
LOCAL_INLINE void HSADC_HWA_SetClockGatingEnable(HSADC_Type *const pHsadc, bool bEnable)
{
    pHsadc->CFG2 = (pHsadc->CFG2 & ~HSADC_CFG2_CG_MASK) | HSADC_CFG2_CG(bEnable);
}

/**
 * @brief Get the HSADC clock divider
 *
 * @note This feature is only available in FC7300F2M
 *
 * @param pHsadc the base address of the HSADC instance
 * @return HSADC_ClockDivideType the HSADC clock divider
 */
LOCAL_INLINE HSADC_ClockDivideType HSADC_HWA_GetClockDivider(const HSADC_Type *const pHsadc)
{
    uint32_t u32TmpVal = (pHsadc->CFG2 & HSADC_CFG2_DIV_MASK) >> HSADC_CFG2_DIV_SHIFT;
    return (HSADC_ClockDivideType)u32TmpVal;
}

/**
 * @brief Set the HSADC clock divider
 *
 * @note Before configuring DIV, must set CG and wait for CG_ACK=1.
 *       After configuring DIV, must clear CG and wait for CG_ACK=0.
 * @note This feature is only available in FC7300F2M
 *
 * @param pHsadc the base address of the HSADC instance
 * @param eDivider the HSADC clock divider to set
 */
LOCAL_INLINE void HSADC_HWA_SetClockDivider(HSADC_Type *const pHsadc, HSADC_ClockDivideType eDivider)
{
    pHsadc->CFG2 = (pHsadc->CFG2 & ~HSADC_CFG2_DIV_MASK) | HSADC_CFG2_DIV(eDivider);
}

/**
 * @brief Get the HSADC start up count
 *
 * @param pHsadc the base address of the HSADC instance
 * @return uint8_t the start count of the HSADC instance
 */
LOCAL_INLINE uint8_t HSADC_HWA_GetStartupCnt(const HSADC_Type *const pHsadc)
{
    uint32_t u32TmpVal = (pHsadc->CFG2 & HSADC_CFG2_STCNT_MASK) >> HSADC_CFG2_STCNT_SHIFT;
    return (uint8_t)u32TmpVal;
}

/**
 * @brief Set the HSADC start up count
 *
 * @param pHsadc the base address of the HSADC instance
 * @param u8StartupCnt the start count of the HSADC instance
 */
LOCAL_INLINE void HSADC_HWA_SetStartupCnt(HSADC_Type *const pHsadc, uint8_t u8StartupCnt)
{
    pHsadc->CFG2 = (pHsadc->CFG2 & ~HSADC_CFG2_STCNT_MASK) | HSADC_CFG2_STCNT(u8StartupCnt);
}

/**
 * @brief Get the HSADC_CFG2 config
 *
 * @param pHsadc the base address of the HSADC instance
 * @return uint32_t the HSADC_CFG2 config
 */
LOCAL_INLINE uint32_t HSADC_HWA_GetConfig2(const HSADC_Type *const pHsadc)
{
    return pHsadc->CFG2;
}

/**
 * @brief Set the HSADC_CFG2 config
 *
 * @param pHsadc the base address of the HSADC instance
 * @param u32Config the HSADC_CFG2 config
 */
LOCAL_INLINE void HSADC_HWA_SetConfig2(HSADC_Type *const pHsadc, uint32_t u32Config)
{
    pHsadc->CFG2 = u32Config;
}

/**
 * @brief Get the sample time of the HSADC instance
 *
 * @param pHsadc the base address of the HSADC instance
 * @param u8Selection the sample time index, range 0~3
 * @return uint8_t the sample time of the selected index
 */
LOCAL_INLINE uint8_t HSADC_HWA_GetSampleTime(HSADC_Type *const pHsadc, uint8_t u8Selection)
{
    uint32_t ret;
    ret = (pHsadc->SMPR & (HSADC_SMPR_SMP_OPT0_MASK << (8U * u8Selection))) >> (8U * u8Selection);
    return (uint8_t)ret;
}

/**
 * @brief Set the sample time of the HSADC instance
 *
 * @param pHsadc the base address of the HSADC instance
 * @param u8Selection the sample time index, range 0~3
 * @param u8SampleTime the sample time of the selected index
 */
LOCAL_INLINE void HSADC_HWA_SetSampleTime(HSADC_Type *const pHsadc, uint8_t u8Selection, uint8_t u8SampleTime)
{
    DEV_ASSERT(u8Selection < HSADC_SAMPLE_TIME_OPTION_COUNT);
    pHsadc->SMPR = (pHsadc->SMPR & ~(HSADC_SMPR_SMP_OPT0_MASK << (8U * u8Selection))) |
                 (HSADC_SMPR_SMP_OPT0(u8SampleTime) << (8U * u8Selection));
}

/**
 * @brief Get whether hardware compare is enabled
 *
 * @param pHsadc the base address of the HSADC instance
 * @return true hardware compare is enabled
 * @return false hardware compare is disabled
 */
LOCAL_INLINE bool HSADC_HWA_GetCmpEnable(const HSADC_Type *const pHsadc)
{
    uint32_t u32TmpVal = (pHsadc->CMP_CTRL & HSADC_CMP_CTRL_ACMPEN_MASK) >> HSADC_CMP_CTRL_ACMPEN_SHIFT;
    return (bool)((u32TmpVal != 0U) ? true : false);
}

/**
 * @brief Set to enable or disable the hardware compare
 *
 * @param pHsadc the base address of the HSADC instance
 * @param bEnable whether the HSADC hardware compare is enabled
 */
LOCAL_INLINE void HSADC_HWA_SetCmpEnable(HSADC_Type *const pHsadc, bool bEnable)
{
    pHsadc->CMP_CTRL = (pHsadc->CMP_CTRL & ~HSADC_CMP_CTRL_ACMPEN_MASK) | HSADC_CMP_CTRL_ACMPEN(bEnable);
}

/**
 * @brief Set the HSADC hardware compare channel
 *
 * @param pHsadc the base address of the HSADC instance
 * @param eType whether the hardware compare enabled on single channel or all channels
 * @param u8ChannalNum if hardware compare is enabled on single channel, this specifies the channel number
 */
LOCAL_INLINE void HSADC_HWA_SetCmpChannel(HSADC_Type *const pHsadc, HSADC_CmpChannelType eType,
                                          uint8_t u8ChannalNum)
{
    pHsadc->CMP_CTRL = (pHsadc->CMP_CTRL & (~HSADC_CMP_CTRL_ACMPSGL_MASK) & (~HSADC_CMP_CTRL_ACMPCH_MASK)) |
                        HSADC_CMP_CTRL_ACMPSGL(eType) | HSADC_CMP_CTRL_ACMPCH(u8ChannalNum);
}

/**
 * @brief Set the HSADC hardware compare threshold
 *
 * @param pHsadc the base address of the HSADC instance
 * @param u16LowThres the lower threshold
 * @param u16HighThres the higher threshold
 */
LOCAL_INLINE void HSADC_HWA_SetCmpThreshold(HSADC_Type *const pHsadc, uint16_t u16LowThres, uint16_t u16HighThres)
{
    pHsadc->CMP_TR = HSADC_CMP_TR_LT(u16LowThres) | HSADC_CMP_TR_HT(u16HighThres);
}

/**
 * @brief Get the HSADC_CFG3 config
 *
 * @param pHsadc the base address of the HSADC instance
 * @return uint32_t the HSADC_CFG3 config
 */
LOCAL_INLINE uint32_t HSADC_HWA_GetConfig3(const HSADC_Type *const pHsadc)
{
    return pHsadc->CFG3;
}

/**
 * @brief Set the HSADC_CFG3 config
 *
 * @param pHsadc the base address of the HSADC instance
 * @param u32Config the HSADC_CFG3 config
 */
LOCAL_INLINE void HSADC_HWA_SetConfig3(HSADC_Type *const pHsadc, uint32_t u32Config)
{
    pHsadc->CFG3 = u32Config;
}

/**
 * @brief Get the end of sequence group flag
 *
 * @param pHsadc the base address of the HSADC instance
 * @param u8SeqGroupIndex the index of the sequence group
 * @param bool the sequence group interrupt flag
 */
LOCAL_INLINE bool HSADC_HWA_GetEndOfSGFlag(HSADC_Type *const pHsadc, const uint8_t u8SeqGroupIndex)
{
    uint32_t u32TmpVal = (pHsadc->SGCSR[u8SeqGroupIndex] & HSADC_SGCSR_EOSG_MASK) >> HSADC_SGCSR_EOSG_SHIFT;
    return u32TmpVal ? true : false;
}

/**
 * @brief Clear the end of sequence group flag
 *
 * @param pHsadc the base address of the HSADC instance
 * @param u8SeqGroupIndex the index of the sequence group
 */
LOCAL_INLINE void HSADC_HWA_ClearEndOfSGFlag(HSADC_Type *const pHsadc, const uint8_t u8SeqGroupIndex)
{
    uint32_t u32TmpVal = pHsadc->SGCSR[u8SeqGroupIndex];
    pHsadc->SGCSR[u8SeqGroupIndex] = (u32TmpVal & ~HSADC_SGCSR_EOSG_MASK) | HSADC_SGCSR_EOSG(1U);
}

/**
 * @brief Set the sequence group end of sequence interrupt enable
 *
 * @param pHsadc the base address of the HSADC instance
 * @param u8SeqGroupIndex the index of the sequence group
 * @param bEnable the sequence group interrupt enable or disable
 */
LOCAL_INLINE void HSADC_HWA_SetEndOfSGIntEnable(HSADC_Type *const pHsadc, const uint8_t u8SeqGroupIndex, const bool bEnable)
{
	uint32_t u32TmpVal = pHsadc->SGCSR[u8SeqGroupIndex];
    pHsadc->SGCSR[u8SeqGroupIndex] = (u32TmpVal & ~HSADC_SGCSR_EOSGIE_MASK) | HSADC_SGCSR_EOSGIE(bEnable);
}

/**
 * @brief Set the sequence group end of sequence interrupt enable
 *
 * @param pHsadc the base address of the HSADC instance
 * @param u8SeqGroupIndex the index of the sequence group
 * @return bool the sequence group interrupt enable or disable
 */
LOCAL_INLINE bool HSADC_HWA_GetEndOfSGIntEnable(HSADC_Type *const pHsadc, const uint8_t u8SeqGroupIndex)
{
	uint32_t u32TmpVal = pHsadc->SGCSR[u8SeqGroupIndex];
    u32TmpVal = (u32TmpVal & HSADC_SGCSR_EOSGIE_MASK);
    return u32TmpVal ? true : false;
}

/**
 * @brief Get the sequence group start point
 *
 * @param pHsadc the base address of the HSADC instance
 * @param u8SeqGroupIndex the index of the sequence group
 */
LOCAL_INLINE uint8_t HSADC_HWA_GetSGStartPoint(HSADC_Type *const pHsadc, const uint8_t u8SeqGroupIndex)
{
    return (uint8_t)((pHsadc->SGCSR[u8SeqGroupIndex] & HSADC_SGCSR_SG_START_MASK) >> HSADC_SGCSR_SG_START_SHIFT);
}

/**
 * @brief Get the sequence group end point
 *
 * @param pHsadc the base address of the HSADC instance
 * @param u8SeqGroupIndex the index of the sequence group
 */
LOCAL_INLINE uint8_t HSADC_HWA_GetSGEndPoint(HSADC_Type *const pHsadc, const uint8_t u8SeqGroupIndex)
{
    return (uint8_t)((pHsadc->SGCSR[u8SeqGroupIndex] & HSADC_SGCSR_SG_END_MASK) >> HSADC_SGCSR_SG_END_SHIFT);
}

/**
 * @brief Set the sequence group start and end point
 *
 * @param pHsadc the base address of the HSADC instance
 * @param u8SeqGroupIndex the index of the sequence group
 * @param u8Start the sequence group start point
 * @param u8End the sequence group end point
 */
LOCAL_INLINE void HSADC_HWA_SetSGStartEndPoint(HSADC_Type *const pHsadc, const uint8_t u8SeqGroupIndex, const uint8_t u8Start, const uint8_t u8End)
{
    uint32_t u32TmpVal = pHsadc->SGCSR[u8SeqGroupIndex];
    u32TmpVal = (u32TmpVal & ~HSADC_SGCSR_SG_END_MASK) | HSADC_SGCSR_SG_END(u8End);
    u32TmpVal = (u32TmpVal & ~HSADC_SGCSR_SG_START_MASK) | HSADC_SGCSR_SG_START(u8Start);
    pHsadc->SGCSR[u8SeqGroupIndex] = u32TmpVal;
}

LOCAL_INLINE void HSADC_HWA_SetOGCOffset(HSADC_Type *const pHsadc, uint16_t val)
{
    pHsadc->OGCR = (pHsadc->OGCR & ~HSADC_OGCR_OFFSET_MASK) | HSADC_OGCR_OFFSET(val);
}

LOCAL_INLINE void HSADC_HWA_SetOGCGain(HSADC_Type *const pHsadc, uint16_t val)
{
    pHsadc->OGCR = (pHsadc->OGCR & ~HSADC_OGCR_GAIN_MASK) | HSADC_OGCR_GAIN(val);
}

LOCAL_INLINE void HSADC_HWA_SetOGCEnable(HSADC_Type *const pHsadc, bool bEnable)
{
    pHsadc->OGCR = (pHsadc->OGCR & ~HSADC_OGCR_OGC_EN_MASK) | HSADC_OGCR_OGC_EN(bEnable);
}

/**
 * @brief Set the HSADC_CCAL config
 *
 * @param pHsadc the base address of the HSADC instance
 * @param u32Cal the HSADC_CCAL config
 */
LOCAL_INLINE void HSADC_HWA_SetCCal(HSADC_Type *const pHsadc, uint32_t u32CCal)
{
    pHsadc->CCAL = u32CCal;
}

/**
 * @brief Get the conversion result FIFO data of the HSADC instance
 *
 * @note only reslut data of HSADC single mode and continuous mode will be stored
 * in FIFO register.
 *
 * @param pHsadc the base address of the HSADC instance
 * @return uint32_t the HSADC conversion result
 */
LOCAL_INLINE uint32_t HSADC_HWA_GetFIFOData(const HSADC_Type *const pHsadc)
{
    uint32_t u32TmpVal = pHsadc->FIFO_DATA;
    u32TmpVal = (u32TmpVal & HSADC_FIFO_DATA_FIFO_DATA_MASK) >> HSADC_FIFO_DATA_FIFO_DATA_SHIFT;
    return (uint32_t)u32TmpVal;
}

/**
 * @brief Get the sample time index of the HSADC channel
 *
 * @param pHsadc the base address of the HSADC instance
 * @param u8ChnIdx the index of the channel
 * @return uint8_t the sample time index of the HSADC channel
 */
LOCAL_INLINE uint8_t HSADC_HWA_GetChannelSampleTimeIndex(const HSADC_Type *const pHsadc, const uint8_t u8ChnIdx)
{
    uint32_t u32TmpVal = (pHsadc->SC[u8ChnIdx] & HSADC_SC_SMPSEL_MASK) >> HSADC_SC_SMPSEL_SHIFT;
    return (uint8_t)u32TmpVal;
}

/**
 * @brief Set the sample time index of the HSADC channel
 *
 * @param pHsadc the base address of the HSADC instance
 * @param u8ChnIdx the index of the channel
 * @param u8SmpSel the sample time index of the HSADC channel
 */
LOCAL_INLINE void HSADC_HWA_SetChannelSampleTimeIndex(HSADC_Type *const pHsadc, const uint8_t u8ChnIdx, uint8_t u8SmpSel)
{
    pHsadc->SC[u8ChnIdx] = (pHsadc->SC[u8ChnIdx] & ~HSADC_SC_SMPSEL_MASK) | HSADC_SC_SMPSEL(u8SmpSel);
}

/**
 * @brief Get the channel conversion complete status of the HSADC instance
 *
 * @note this function is used only in HSADC discontinuous mode to get the channel complete
 * status
 *
 * @param pHsadc the base address of the HSADC instance
 * @param u8ChnIdx the index of the channel
 * @return true the HSADC conversion on the selected channel is completed
 * @return false the HSADC conversion on the selected channel is not completed
 */
LOCAL_INLINE bool HSADC_HWA_GetChannelCoCoFlag(const HSADC_Type *const pHsadc, const uint8_t u8ChnIdx)
{
    uint32_t u32TmpVal = pHsadc->SC[u8ChnIdx];
    u32TmpVal = (u32TmpVal & HSADC_SC_COCO_MASK) >> HSADC_SC_COCO_SHIFT;

    return (bool)((u32TmpVal != 0U) ? true : false);
}

/**
 * @brief Clear the channel conversion complete status of the HSADC instance
 *
 * @note this function is used only in HSADC sequence group mode to clear the channel complete
 * flag
 *
 * @param pHsadc the base address of the HSADC instance
 * @param u8ChnIdx the index of the channel
 * @return true the HSADC conversion on the selected channel is completed
 * @return false the HSADC conversion on the selected channel is not completed
 */
LOCAL_INLINE void HSADC_HWA_ClearChannelCoCoFlag(HSADC_Type *const pHsadc, uint8_t u8ChnIdx)
{
    uint32_t u32TmpVal = pHsadc->SC[u8ChnIdx];
    u32TmpVal = u32TmpVal | HSADC_SC_COCO_MASK;
    pHsadc->SC[u8ChnIdx] = u32TmpVal;
}

/**
 * @brief Check whether interrupt is enabled on the selected HSADC channel
 *
 * @note this function is used only in HSADC sequence group mode to get the channel interrupt
 * settings
 *
 * @param pHsadc the base address of the HSADC instance
 * @param u8ChnIdx the index of the channel
 * @return true interrupt is enabled on the selected channel
 * @return false interrupt is disabled on the selected channel
 */
LOCAL_INLINE bool HSADC_HWA_GetChannelCoCoIntEnable(const HSADC_Type *const pHsadc, const uint8_t u8ChnIdx)
{
    uint32_t u32TmpVal = pHsadc->SC[u8ChnIdx];
    u32TmpVal = (u32TmpVal & HSADC_SC_AIEN_MASK) >> HSADC_SC_AIEN_SHIFT;

    return (bool)((u32TmpVal != 0U) ? true : false);
}

/**
 * @brief Set to enable or disable interrupt on the selected HSADC channel
 *
 * @note this function is used only in HSADC sequence group mode to get the channel interrupt
 * settings
 *
 * @param pHsadc the base address of the HSADC instance
 * @param u8ChnIdx the index of the channel
 * @param bEnable whether to enable interrupt on the selected HSADC channel
 */
LOCAL_INLINE void HSADC_HWA_SetChannelCoCoIntEnable(HSADC_Type *const pHsadc, const uint8_t u8ChnIdx, bool bEnable)
{
    pHsadc->SC[u8ChnIdx] = (pHsadc->SC[u8ChnIdx] & ~HSADC_SC_AIEN_MASK) | HSADC_SC_AIEN(bEnable);
}

/**
 * @brief Get the input channel of the selected HSADC channel
 *
 * @param pHsadc the base address of the HSADC instance
 * @param u8ChnIdx the index of the channel
 * @return uint8_t the hardware input channel
 */
LOCAL_INLINE uint8_t HSADC_HWA_GetChannelInput(const HSADC_Type *const pHsadc, const uint8_t u8ChnIdx)
{
    uint32_t u32TmpVal = (pHsadc->SC[u8ChnIdx] & HSADC_SC_CHS_MASK) >> HSADC_SC_CHS_SHIFT;
    return (uint8_t)u32TmpVal;
}

/**
 * @brief Set the input channel to the selected HSADC channel
 *
 * @param pHsadc the base address of the HSADC instance
 * @param u8ChnIdx the index of the channel
 * @param u8InputChann the hardware input channel
 */
LOCAL_INLINE void HSADC_HWA_SetChannelInput(HSADC_Type *const pHsadc, const uint8_t u8ChnIdx, uint8_t u8InputChann)
{
    pHsadc->SC[u8ChnIdx] = (pHsadc->SC[u8ChnIdx] & ~HSADC_SC_CHS_MASK) | HSADC_SC_CHS(u8InputChann);
}

LOCAL_INLINE void HSADC_HWA_SetSCCfg(HSADC_Type *const pHsadc, const uint8_t u8ChnIdx, uint32_t val)
{
    pHsadc->SC[u8ChnIdx] = val;
}

/**
 * @brief Get the conversion result data of the HSADC instance
 *
 * @note only result data of HSADC discontinuous mode will be stored in RESULTn register.
 *
 * @param pHsadc the base address of the HSADC instance
 * @param u8ChnIdx the index of the HSADC channel
 * @return uint32_t the HSADC conversion result
 */
LOCAL_INLINE uint32_t HSADC_HWA_GetChannelData(const HSADC_Type *const pHsadc, const uint8_t u8ChnIdx)
{
    uint32_t u32TmpVal = pHsadc->RESULT[u8ChnIdx];
    u32TmpVal = (u32TmpVal & HSADC_RESULT_RESULT_MASK) >> HSADC_RESULT_RESULT_SHIFT;

    return (uint32_t)u32TmpVal;
}

LOCAL_INLINE uint16_t HSADC_HWA_GetResultCal(HSADC_Type *const pHsadc)
{
    return (uint16_t)((pHsadc->RESULT_CAL & HSADC_RESULT_CAL_DATA_MASK) >> HSADC_RESULT_CAL_DATA_SHIFT);
}

/**
 * @brief Get the fast compare enable
 *
 * @note
 *
 * @param pHsadc the base address of the HSADC instance
 * @return bool whether the HSADC fast compare enable
 */
LOCAL_INLINE bool HSADC_HWA_GetFCEnable(const HSADC_Type *const pHsadc)
{
    uint32_t u32TmpVal = (pHsadc->FCMP_CTRL & HSADC_FCMP_CTRL_FC_EN_MASK) >> HSADC_FCMP_CTRL_FC_EN_SHIFT;
    return u32TmpVal ? true : false;
}

/**
 * @brief Set the fast compare reference of the HSADC instance
 *
 * @note
 *
 * @param pHsadc the base address of the HSADC instance
 * @param enable whether the HSADC fast compare enable
 * @return none
 */
LOCAL_INLINE void HSADC_HWA_SetFCEnable(HSADC_Type *const pHsadc, bool enable)
{
    pHsadc->FCMP_CTRL = (pHsadc->FCMP_CTRL & ~HSADC_FCMP_CTRL_FC_EN_MASK) | HSADC_FCMP_CTRL_FC_EN(enable);
}

/**
 * @brief Set the fast compare control register
 *
 * @note
 *
 * @param pHsadc the base address of the HSADC instance
 * @param value control register value
 * @return none
 */
LOCAL_INLINE void HSADC_HWA_SetFCCtrl(HSADC_Type *const pHsadc, uint32_t value)
{
    pHsadc->FCMP_CTRL = value;
}

/**
 * @brief Get the fast compare reference of the HSADC instance
 *
 * @note
 *
 * @param pHsadc the base address of the HSADC instance
 * @return int16_t the HSADC fast compare reference
 */
LOCAL_INLINE int16_t HSADC_HWA_GetFCRef(const HSADC_Type *const pHsadc)
{
    return (pHsadc->FCREF & HSADC_FCREF_FCREF_MASK) >> HSADC_FCREF_FCREF_SHIFT;
}

/**
 * @brief Set the fast compare reference of the HSADC instance
 *
 * @note
 *
 * @param pHsadc the base address of the HSADC instance
 * @param ref the index of the HSADC channel
 * @return none
 */
LOCAL_INLINE void HSADC_HWA_SetFCRef(HSADC_Type *const pHsadc, uint16_t ref)
{
    pHsadc->FCREF = (pHsadc->FCREF & ~HSADC_FCREF_FCREF_MASK) | HSADC_FCREF_FCREF(ref);
}

/**
 * @brief Get the fast compare ramp reference A of the HSADC instance
 *
 * @note
 *
 * @param pHsadc the base address of the HSADC instance
 * @return int16_t the HSADC fast compare ramp reference A
 */
LOCAL_INLINE int16_t HSADC_HWA_GetFCRampRefA(const HSADC_Type *const pHsadc)
{
    return (pHsadc->FCRAMP0 & HSADC_FCRAMP0_FCREF_A_MASK) >> HSADC_FCRAMP0_FCREF_A_SHIFT;
}

/**
 * @brief Set the fast compare ramp reference A of the HSADC instance
 *
 * @note
 *
 * @param pHsadc the base address of the HSADC instance
 * @param ref the HSADC fast compare ramp reference A
 * @return none
 */
LOCAL_INLINE void HSADC_HWA_SetFCRampRefA(HSADC_Type *const pHsadc, uint16_t ref)
{
    pHsadc->FCRAMP0 = (pHsadc->FCRAMP0 & ~HSADC_FCRAMP0_FCREF_A_MASK) | HSADC_FCRAMP0_FCREF_A(ref);
}

/**
 * @brief Get the fast compare ramp step of the HSADC instance
 *
 * @note
 *
 * @param pHsadc the base address of the HSADC instance
 * @return uint8_t the HSADC fast compare ramp step
 */
LOCAL_INLINE uint8_t HSADC_HWA_GetFCRampStep(const HSADC_Type *const pHsadc)
{
    return (pHsadc->FCRAMP0 & HSADC_FCRAMP0_RPSTEP_MASK) >> HSADC_FCRAMP0_RPSTEP_SHIFT;
}

/**
 * @brief Set the fast compare ramp step
 *
 * @note
 *
 * @param pHsadc the base address of the HSADC instance
 * @param step the HSADC fast compare ramp step
 * @return none
 */
LOCAL_INLINE void HSADC_HWA_SetFCRampStep(HSADC_Type *const pHsadc, uint16_t step)
{
    pHsadc->FCRAMP0 = (pHsadc->FCRAMP0 & ~HSADC_FCRAMP0_RPSTEP_MASK) | HSADC_FCRAMP0_RPSTEP(step);
}

/**
 * @brief Set the fast compare ramp0 register
 *
 * @note
 *
 * @param pHsadc the base address of the HSADC instance
 * @param value the HSADC fast compare ramp0 register value
 * @return none
 */
LOCAL_INLINE void HSADC_HWA_SetFCRamp0(HSADC_Type *const pHsadc, uint32_t value)
{
    pHsadc->FCRAMP0 = value;
}

/**
 * @brief Get the fast compare ramp reference B of the HSADC instance
 *
 * @note
 *
 * @param pHsadc the base address of the HSADC instance
 * @return int16_t the HSADC fast compare ramp reference B
 */
LOCAL_INLINE int16_t HSADC_HWA_GetFCRampRefB(const HSADC_Type *const pHsadc)
{
    return (pHsadc->FCRAMP1 & HSADC_FCRAMP1_FCREF_B_MASK) >> HSADC_FCRAMP1_FCREF_B_SHIFT;
}

/**
 * @brief Set the fast compare ramp reference B of the HSADC instance
 *
 * @note
 *
 * @param pHsadc the base address of the HSADC instance
 * @param ref the HSADC fast compare ramp reference B
 * @return none
 */
LOCAL_INLINE void HSADC_HWA_SetFCRampRefB(HSADC_Type *const pHsadc, uint16_t ref)
{
    pHsadc->FCRAMP1 = (pHsadc->FCRAMP1 & ~HSADC_FCRAMP1_FCREF_B_MASK) | HSADC_FCRAMP1_FCREF_B(ref);
}

/**
 * @brief Get the fast compare ramp dir
 *
 * @note
 *
 * @param pHsadc the base address of the HSADC instance
 * @return HSADC_FCmpRampDir the HSADC fast compare ramp dir
 */
LOCAL_INLINE HSADC_FastCmpRampDir HSADC_HWA_GetFCRampDir(const HSADC_Type *const pHsadc)
{
    uint32_t u32TmpVal = (pHsadc->FCRAMP1 & HSADC_FCRAMP1_RPDIR_MASK) >> HSADC_FCRAMP1_RPDIR_SHIFT;
    return u32TmpVal ? HSADC_FAST_CMP_RAMPDIR_DOWN : HSADC_FAST_CMP_RAMPDIR_UP;
}

/**
 * @brief Set the fast compare ramp dir
 *
 * @note
 *
 * @param pHsadc the base address of the HSADC instance
 * @param dir the HSADC fast compare ramp dir
 * @return none
 */
LOCAL_INLINE void HSADC_HWA_SetFCRampDir(HSADC_Type *const pHsadc, HSADC_FastCmpRampDir dir)
{
    pHsadc->FCRAMP1 = (pHsadc->FCRAMP1 & ~HSADC_FCRAMP1_RPDIR_MASK) | HSADC_FCRAMP1_RPDIR(dir);
}

/**
 * @brief Set the fast compare ramp1 register
 *
 * @note
 *
 * @param pHsadc the base address of the HSADC instance
 * @param value the HSADC fast compare ramp1 register value
 * @return none
 */
LOCAL_INLINE void HSADC_HWA_SetFCRamp1(HSADC_Type *const pHsadc, uint32_t value)
{
    pHsadc->FCRAMP1 = value;
}

/**
 * @brief Get the fast compare reference upper delta
 *
 * @note
 *
 * @param pHsadc the base address of the HSADC instance
 * @return uint16_t the HSADC fast compare ref upper delta
 */
LOCAL_INLINE uint16_t HSADC_HWA_GetFCRefDeltaP(const HSADC_Type *const pHsadc)
{
    return (pHsadc->FCHYST & HSADC_FCHYST_DELTAP_MASK) >> HSADC_FCHYST_DELTAP_SHIFT;
}

/**
 * @brief Set the fast compare reference upper delta
 *
 * @note
 *
 * @param pHsadc the base address of the HSADC instance
 * @param delta the HSADC fast compare ref upper delta
 * @return none
 */
LOCAL_INLINE void HSADC_HWA_SetFCRefDeltaP(HSADC_Type *const pHsadc, uint16_t delta)
{
    pHsadc->FCHYST = (pHsadc->FCHYST & ~HSADC_FCHYST_DELTAP_MASK) | HSADC_FCHYST_DELTAP(delta);
}

/**
 * @brief Get the fast compare reference lower delta
 *
 * @note
 *
 * @param pHsadc the base address of the HSADC instance
 * @return uint16_t the HSADC fast compare ref lower delta
 */
LOCAL_INLINE uint16_t HSADC_HWA_GetFCRefDeltaN(const HSADC_Type *const pHsadc)
{
    return (pHsadc->FCHYST & HSADC_FCHYST_DELTAN_MASK) >> HSADC_FCHYST_DELTAN_SHIFT;
}

/**
 * @brief Set the fast compare reference lower delta
 *
 * @note
 *
 * @param pHsadc the base address of the HSADC instance
 * @param delta the HSADC fast compare ref lower delta
 * @return none
 */
LOCAL_INLINE void HSADC_HWA_SetFCRefDeltaN(HSADC_Type *const pHsadc, uint16_t delta)
{
    pHsadc->FCHYST = (pHsadc->FCHYST & ~HSADC_FCHYST_DELTAN_MASK) | HSADC_FCHYST_DELTAN(delta);
}

/**
 * @brief Set the fast compare reference hysteresis
 *
 * @note
 *
 * @param pHsadc the base address of the HSADC instance
 * @param u32Hyst the HSADC fast compare reference hysteresis
 * @return none
 */
LOCAL_INLINE void HSADC_HWA_SetFCHysteresis(HSADC_Type *const pHsadc, uint32_t u32Hyst)
{
    pHsadc->FCHYST = u32Hyst;
}

/**
 * @brief Get the fast compare result
 *
 * @note
 *
 * @param pHsadc the base address of the HSADC instance
 * @return bool fast compare result
 */
LOCAL_INLINE bool HSADC_HWA_GetFCResult(HSADC_Type *const pHsadc)
{
    return (bool)((pHsadc->FCBFR & HSADC_FCBFR_FCR_MASK) >> HSADC_FCBFR_FCR_SHIFT);
}

/**
 * @brief Get the fast compare boundary flag
 *
 * @note
 *
 * @param pHsadc the base address of the HSADC instance
 * @return bool fast compare boundary flag
 */
LOCAL_INLINE bool HSADC_HWA_GetFCBoundaryFlag(HSADC_Type *const pHsadc)
{
    return (bool)((pHsadc->FCBFR & HSADC_FCBFR_BFL_MASK) >> HSADC_FCBFR_BFL_SHIFT);
}

/** @}*/

#endif /* #if HSADC_INSTANCE_COUNT > 0U */

#endif /* _HWA_HSADC_H_ */
