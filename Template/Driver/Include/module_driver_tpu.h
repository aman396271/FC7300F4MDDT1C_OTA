/**
 * @file module_driver_tpu.c
 * @author Flagchip099
 * @brief FC7xxx TPU driver source code
 * @version 2.0.0
 * @date 2024-1-12
 *
 * SDK Version: 2.6.0
 *

 * @copyright Copyright (c) 2024 Flagchip Semiconductors Co., Ltd.
 *
 */
/* ********************************************************************************
   *   Revision History:
   *
   *   Version     Date          Initials      CR#          Descriptions
   *   ---------   ----------    ------------  ----------   ---------------
   *   0.1.0       2023-12-15    Flagchip099   N/A          First version for FC7300
   *   2.0.0       2024-10-12    Flagchip099   N/A          Change version and release
   ******************************************************************************** */

#ifndef MODULE_DRIVER_TPU_H
#define MODULE_DRIVER_TPU_H

/* ----------------------------------------------------------------------------
   -- TPU_H Peripheral Access Layer
   ---------------------------------------------------------------------------- */

#include "HwA_tpuh.h"
#include "HwA_tpue.h"

#if TPU_INSTANCE_COUNT > 0U

#include "HwA_scm.h"

#define TPU_TCR1_MAXVALUE                                             0xFFFFFFU
#define TPU_CHANNEL_NUM                                                     32U

extern void RTT_Printf(char *fmt, ...);
#define DEBUG_INFO(str, ...) RTT_Printf(str, ##__VA_ARGS__)

/**
 * @brief TPU event callback function prototype
 *
 */
typedef void (*TPU_EventCallbackType)(void* arg);

typedef void (*TPU_TCR1OverflowCallbackType)(void* arg);

typedef void (*TPU_TCR2OverflowCallbackType)(void* arg);

typedef void (*TPU_HSACallbackType)(void* arg);

typedef enum
{
    TPU_DutyMeasurementActiveHigh   = 0x0U,
    TPU_DutyMeasurementActiveLow    = 0x1U,
    TPU_PeriodMeasurement           = 0x2U,
} TPU_MeasureModeType;

typedef enum
{
    TPU_CHANNEL_0  = 0U,
    TPU_CHANNEL_1  = 1U,
    TPU_CHANNEL_2  = 2U,
    TPU_CHANNEL_3  = 3U,
    TPU_CHANNEL_4  = 4U,
    TPU_CHANNEL_5  = 5U,
    TPU_CHANNEL_6  = 6U,
    TPU_CHANNEL_7  = 7U,
    TPU_CHANNEL_8  = 8U,
    TPU_CHANNEL_9  = 9U,
    TPU_CHANNEL_10 = 10U,
    TPU_CHANNEL_11 = 11U,
    TPU_CHANNEL_12 = 12U,
    TPU_CHANNEL_13 = 13U,
    TPU_CHANNEL_14 = 14U,
    TPU_CHANNEL_15 = 15U,
    TPU_CHANNEL_16 = 16U,
    TPU_CHANNEL_17 = 17U,
    TPU_CHANNEL_18 = 18U,
    TPU_CHANNEL_19 = 19U,
    TPU_CHANNEL_20 = 20U,
    TPU_CHANNEL_21 = 21U,
    TPU_CHANNEL_22 = 22U,
    TPU_CHANNEL_23 = 23U,
    TPU_CHANNEL_24 = 24U,
    TPU_CHANNEL_25 = 25U,
    TPU_CHANNEL_26 = 26U,
    TPU_CHANNEL_27 = 27U,
    TPU_CHANNEL_28 = 28U,
    TPU_CHANNEL_29 = 29U,
    TPU_CHANNEL_30 = 30U,
    TPU_CHANNEL_31 = 31U,
    TPU_CHANNEL_MAX = TPU_E_CH_COUNT
} TPU_ChannelType;

/** TPU_H - Register Layout Typedef */

/** @brief ETPU config type */

typedef struct
{
    TPUE_TimeBaseSelctionType eTBS1;                     /**< modulate 0 value */
    TPUE_TimeBaseSelctionType eTBS2;                     /**< modulate 1 value */
    bool bPwmUseTCR1;                                   /**< modulate 2 value */
    bool bPwmUseTCR2;                                   /**< modulate 3 value */
    uint32_t u32ActiveTime;
    uint32_t u32PeriodTime;
    bool bActiveHigh;
} TPU_PwmCfgType;

/**
 * @brief Structure defining the configuration parameters for a TPU capture module.
 *
 * This structure contains all necessary parameters to configure the operation of a TPU capture module,
 * including period time, measurement mode, input type, and timing details.
 */

typedef struct
{
    uint32_t u32PeriodTime;   /**< Period time in milliseconds. */
    TPU_MeasureModeType eMeasureMode; /**< Measurement mode (continuous or single shot). */
    TPUE_IPACType eInputType; /**< Input type (e.g., AC, DC). */
    uint32_t u32SampleTime;   /**< Sample time in milliseconds. */
    uint32_t u32ActiveTime;   /**< Active time in milliseconds. */
    uint32_t LastTime;        /**< Last measured time. */
    uint32_t StartTime;       /**< Start time of the capture. */
} TPU_CaptureCfgType;

/**
 * @brief The interrupt configurations of the Tpu channel
 *
 */
typedef struct
{
    bool bEventIntEn; /*!< Enable interrupt after match */
    bool bTCR1OverFlowEventIntEn; /*!< Enable interrupt after TCR1 OverFlow */
    bool bTCR2OverFlowEventIntEn; /*!< Enable interrupt after TCR2 OverFlow */
    TPU_EventCallbackType pEventNotify; /*!< transfer complete notification */
    TPU_HSACallbackType pHSANotify; /*!< HSA notification */
    void *pEventdata;
    void *pHSAdata;
    void *pTCR1OVFdata;
    void *pTCR2OVFdata;
    TPU_TCR1OverflowCallbackType  pTCR1OverflowNotify;
    TPU_TCR2OverflowCallbackType  pTCR2OverflowNotify;
    TPUH_ChTrigCFGType eChTrigType;
} TPU_InterruptCfgType;

/**
 * @brief The structure of the TPU processing handle
 *
 */
typedef struct
{
    struct
    {
        struct
        {
            void *pEventdata[TPU_E_CH_COUNT];
            void *pHSAdata[TPU_E_CH_COUNT];
            void *pTCR1OVFdata;
            void *pTCR2OVFdata;
            void (*pTPU_EventCallback[TPU_E_CH_COUNT])(void *arg); /*!< channel event interrupt callback */
            void (*pTPU_HSACallback[TPU_E_CH_COUNT])(void *arg); /*!< channel hsa interrupt callback */
            void (*pTPU_TCR1OverFlowCallback)(void *arg);
            void (*pTPU_TCR2OverFlowCallback)(void *arg);
        } callback;
    } tSettings;
} TPU_InstanceHandleType;

typedef struct
{
    struct
    {
        uint8_t u8Channel;      /*!< TPU Channel*/
        TPU_InstanceHandleType *pInstance;
        TPU_PwmCfgType* pPwmcfg;
        TPU_CaptureCfgType* pCapcfg;
    } tSettings;
    struct
    {
        uint32_t u32PwmNextEdge;
        uint32_t u32PwmLastFrame;
        bool bMeasActivePeriodComplete;
    }tStatus;
} TPU_HandleType;

void TPU_InitChannelInterrupt(TPU_InstanceHandleType* pTpuInstanceHandle, TPU_HandleType* pTpuHandle, const TPU_InterruptCfgType *const pInterruptCfg);

void TPU_PwmModeInit(TPU_HandleType* pTpuHandle, const TPU_PwmCfgType *const p_etpu_config);

void TPU_PwmServiceReq(TPU_HandleType* pTpuHandle, uint32_t u32ActiveTime, uint32_t u32Period);

void TPU_CaptureModeInit(TPU_HandleType* pTpuHandle, const TPU_CaptureCfgType *const p_etpu_config);

void TPU_StartChannel(void);

void TPU_SetHSR(TPU_HandleType* pTpuHandle, uint8_t u8HSRIdx);

void TPU_SendHSR(TPU_HandleType* pTpuHandle);

uint8_t TPU_GetHSA(TPU_HandleType* pTpuHandle);

void TPU_InitChannelHSAInterrupt(TPU_InstanceHandleType* pTpuInstanceHandle, TPU_HandleType* pTpuHandle, const TPU_InterruptCfgType *const pInterruptCfg);

void TPU_EnableSubSystem(void);

void TPU_EnableEventTrigDma(TPU_HandleType* pTpuHandle);

void TPU_CaptureMeasPeriodServiceReq(TPU_HandleType* pTpuHandle, TPU_CaptureCfgType *p_etpu_config);

void TPU_CaptureMeasActivePeriodServiceReq(TPU_HandleType* pTpuHandle, TPU_CaptureCfgType *p_etpu_config);

void TPU_DeInit(void);

void TPU_Init(void);

void TPU_EnableFlexcoreTrigDma(TPU_HandleType* pTpuHandle);

void TPU_EnableEventTrigTrgSel(TPU_HandleType* pTpuHandle, const TPU_InterruptCfgType *const pInterruptCfg);

void TPU_Event_IRQHandler(TPU_InstanceHandleType* pTpuInstanceHandle, uint8_t u8MinChannel, uint8_t u8MaxChannel);

void TPU_Overflow_IRQHandler(TPU_InstanceHandleType* pTpuInstanceHandle);

/*!
 * @}
 */ /* end of group TPU_H_Peripheral_Access_Layer */

#endif

#endif  /* #ifndef MODULE_DRIVER_TPU_H */
