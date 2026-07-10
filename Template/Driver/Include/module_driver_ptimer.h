/**
 * @file module_driver_ptimer.h
 * @author flagchip
 * @brief PTIMER driver type definition and API
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

#ifndef _DRIVER_MODULE_DRIVER_PTIMER_H_
#define _DRIVER_MODULE_DRIVER_PTIMER_H_

#include "HwA_ptimer.h"

#if PTIMER_INSTANCE_COUNT > 0U

#if defined(__cplusplus)
extern "C" {
#endif
/**
 * @addtogroup module_driver_ptimer
 * @{
 */
/**
 * @name  FTU API Service IDs
 *
 * @{
 */

#define PTIMER_INIT_ID                  0U
#define PTIMER_INIT_CHANNEL_ID          1U
#define PTIMER_INIT_STRUCTURE_ID        2U
#define PTIMER_DEINIT_ID                3U
#define PTIMER_SET_PERIOD_ID            4U
#define PTIMER_SET_PULSE_OUT_ID         5U
#define PTIMER_LOAD_VALUE_ID            6U
#define PTIMER_ENABLE_ID                7U
#define PTIMER_DISABLE_ID               8U
#define PTIMER_PULSE_OUT_ID             9U
#define PTIMER_DISABLE_PULSE_OUT_ID     10U
#define PTIMER_GENERATE_SW_TRIGGER_ID   11U

/** @}*/

/**
 * @name  FTU Dev Error Code
 * @brief Error Code of calling FTU apis
 *
 * @{
 */
#define PTIMER_E_PARAM_INSTANCE   			0x01U
#define PTIMER_E_PARAM_CHANNEL   			0x02U
#define PTIMER_E_PARAM_POINTER   			0x03U
#define PTIMER_E_PARAM_DELAY_VALUE     		0x04U
/** @}*/

/**
 * @brief PTIMER Chanenl1 Selection Type
 *
 */
typedef enum
{
    PTIMER0_USED_FOR_ADC0  = 0U,
    PTIMER0_USED_FOR_ADC4,
    PTIMER3_USED_FOR_ADC3,
    PTIMER3_USED_FOR_ADC5
} PTIMER_ChannelSelectionType;

/**
 * @brief The instance index of the PTIMER peripheral
 *
 */
typedef enum
{
#if PTIMER_INSTANCE_COUNT > 1u
    PTIMER_INSTANCE_0 = 0U,
    PTIMER_INSTANCE_1 = 1U,
#endif
#if PTIMER_INSTANCE_COUNT > 2u
    PTIMER_INSTANCE_2 = 2U,
#endif
#if PTIMER_INSTANCE_COUNT > 3u
    PTIMER_INSTANCE_3 = 3U
#endif
} PTIMER_InstanceType;

/**
 * @brief Ptimer process handler
 *
 */
typedef struct _PTIMER_HandleType
{
    PTIMER_InstanceType eInstance;                          /*!< Ptimer instance*/
    uint8_t reserve0[3];
    struct
    {
        uint8_t u8ChnNum;
        uint8_t reserve1[3];
        void (*pSeqErrorNotify)(struct _PTIMER_HandleType *pHandler,uint8_t u8Channel); /*!< Ptimer sequence error callback */
        void (*pIntNotify)(struct _PTIMER_HandleType *pHandler);     /*!< Ptimer interrupt callback */
        bool bDelayIntEnable;                        /*!< Enable the interrupt for timer */
        bool bSeqErrIntEnable;                       /*!< Enable PTIMER Sequence Error Interrupt */
        uint16_t u16IntDelayPeriod;                  /*!< The period cnt */
    } tSettings;
} PTIMER_HandleType;

/**
 * @brief Ptimer instance initialization parameters
 *
 */
typedef struct
{
    PTIMER_LoadValueModeType eLoadValueMode;                /*!< Select the load mode */
    PTIMER_ClockPreDividerType eClkPreDiv;                  /*!< Select the prescaler divider */
    PTIMER_ClockPreDivMultiplyFactorType eClkPreMultFactor; /*!< Select multiplication factor for prescaler */
    PTIMER_TrgSrcType eTriggerInput;                        /*!< Select the trigger input source */
    bool bContinuousModeEnable;     /*!< Enable the continuous mode */
    bool bDmaEnable;                /*!< Enable the dma for timer */
    bool bInstanceBackToBackEnable; /*!< Enable the back to back mode with all of the PTIMER units as a ring */
    bool bDelayIntEnable;                        /*!< Enable the interrupt for timer */
    bool bSeqErrIntEnable;                       /*!< Enable PTIMER Sequence Error Interrupt */
#if PTIMER_SUPPORT_DEBUG_MODE
    bool bDebugDisable;                          /**< Allows ptimer continues to count in debug mode.*/
#endif
    uint16_t u16IntDelayPeriod;                  /*!< The period cnt */
    void (*pSeqErrorNotify)(struct _PTIMER_HandleType *pHandler,uint8_t u8Channel); /*!< Ptimer sequence error callback */
    void (*pIntNotify)(struct _PTIMER_HandleType *pHandler);     /*!< Ptimer interrupt callback */
} PTIMER_InitType;

/**
 * @brief Ptimer channel configuration parameters
 *
 */
typedef struct
{
    uint16_t u16DelayCnt;                  /*!< Setting pre_trigger's delay cnt (delay time = u16DelayCnt* ptimer_clock_cnt). */
    bool bPreTriggerEnable;                /*!< Enable the pre_trigger. */
    bool bPreTriggerOutputEnable;          /*!< Enable the pre_trigger output.  */
    bool bPreTriggerBackToBackEnable;      /*!< Enable the back to back mode for ADC pre_trigger. */
} PTIMER_ChannelCfgType;

/**
 * @brief Ptimer pulse out configgurations
 *
 * When the Ptimer counter time reaches u32PulseOutDlyHighUs, the pulse-out goes high;
 * When the Ptimer counter time reaches u32PulseOutDlyLowUs, the pulse-out goes low.
 *
 */
typedef struct
{
    uint32_t u32PulseOutDlyHighCnt;  /*!< Delay cnt for pulse out to output high */
    uint32_t u32PulseOutDlyLowCnt;   /*!< Delay cnt for pulse out to output low */
} PTIMER_PulseOutType;

/**
 * @brief Provide the default values of PTIMER_InitType
 *
 * @param pInitCfg the structure to initialize
 */
void PTIMER_InitStructure(PTIMER_InitType *const pInitCfg);

/**
 * @brief Initialize the Ptimer instance
 *
 * @param eInstance the Ptimer instance to use
 * @param pInitCfg the Ptimer initialization parameters
 */
void PTIMER_Init(PTIMER_HandleType* PtimerHandle, const PTIMER_InitType *const pInitCfg);

/**
 * @brief De-initialize the Ptimer instance
 * Disable the Ptimer instance and reset the configurations to its reset values
 *
 * @param eInstance the Ptimer instance to use
 */
void PTIMER_DeInit(PTIMER_HandleType* PtimerHandle);

/**
 * @brief Initialize the Ptimer channels
 * 
 * @note the channel delay value is buffered and will take effect only after called PTIMER_LoadValue()
 * function.
 *
 * @param eInstance the Ptimer instance to use
 * @param aChannelCfg the array of channels to config
 * @param u8ChnNum the channel numbers in the channel array
 */
void PTIMER_InitChannel(PTIMER_HandleType* PtimerHandle,
                        const PTIMER_ChannelCfgType aChannelCfg[], const uint8_t u8ChnNum);

/**
 * @brief Set the Ptimer max counter period in microsecond
 * When the Ptimer counter reaches the period, it will return to zero
 *
 * @note the period parameter is buffered and will take effect only after called PTIMER_LoadValue()
 * function.
 * 
 * @param eInstance the Ptimer instance to use
 * @param u32PeriodUs the max counter period in microsecond
 */
void PTIMER_SetPeriod(const PTIMER_HandleType* PtimerHandle, uint16 u16PtimerPeriod);

/**
 * @brief Set the Ptimer pulse-out function
 *
 * @note the pulse-out delay values are buffered and will take effect only after called PTIMER_LoadValue()
 * function.
 * 
 * @param eInstance the Ptimer instance to use
 * @param pPulseOutCfg the pulse-out configuration
 */
void PTIMER_SetPulseOut(const PTIMER_HandleType* PtimerHandle, const PTIMER_PulseOutType *pPulseOutCfg);

/**
 * @brief Load the buffered values into register
 *
 * Some Ptimer registers are buffered and will only take effect after called
 * this function
 *
 * @param eInstance the Ptimer instance to use
 */
void PTIMER_LoadValue(const PTIMER_HandleType* PtimerHandle);

/**
 * @brief Enable the Ptimer instance
 *
 * @param eInstance the Ptimer instance to use
 */
void PTIMER_Enable(const PTIMER_HandleType* PtimerHandle);

/**
 * @brief Disable the Ptimer instance
 *
 * @param eInstance the Ptimer instance to use
 */
void PTIMER_Disable(const PTIMER_HandleType* PtimerHandle);

/**
 * @brief Enable the Ptimer pulse-out function
 *
 * @param eInstance the Ptimer instance to use
 */
void PTIMER_EnablePulseOut(const PTIMER_HandleType* PtimerHandle);

/**
 * @brief Disable the Ptimer pulse-out function
 *
 * @param eInstance the Ptimer instance to use
 */
void PTIMER_DisablePulseOut(const PTIMER_HandleType* PtimerHandle);

void PTIMER_SetInstance01BackToBackEnable(bool bEnable);

void PTIMER_SetInstance23BackToBackEnable(bool bEnable);

void PTIMERn_IRQHandler(PTIMER_HandleType *PtimerHandle);
/**
 * @brief Generate the software trigger signal for the Ptimer instance
 *
 * If the Ptimer trigger source is selected as PTIMER_TRGSRC_SW, call this function
 * will make the Ptimer instance to start.
 *
 * @param eInstance the Ptimer instance to use
 */
void PTIMER_GenerateSWTrigger(const PTIMER_HandleType *PtimerHandle);

/**
 * @brief Set PTIMER channel used for specific ADC instance
 *
 * @param selection the Ptimer channel selection type
 */
void PTIMER_ChannelSelection(PTIMER_ChannelSelectionType selection);
/** @}*/ /* module_driver_ptimer */

#if defined(__cplusplus)
}
#endif

#endif /* #if PTIMER_INSTANCE_COUNT > 0U */

#endif
