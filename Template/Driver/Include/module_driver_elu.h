/**
 * @file module_driver_lu.h
 * @author Flagchip
 * @brief LU driver type definition and API
 * @version 2.0.0
 * @date 2024-08-20
 *
 * SDK Version: 2.6.0
 *

 * @copyright Copyright (c) 2020-2024 Flagchip Semiconductors Co., Ltd.
 *
 * @details
 */
#ifndef _DRIVER_MODULE_DRIVER_ELU_H_
#define _DRIVER_MODULE_DRIVER_ELU_H_
#include "HwA_elu.h"

#if ELU_INSTANCE_COUNT > 0U

/**
 * @addtogroup module_driver_lu
 * @{
 */


/**
 * @name  CORDIC API Service IDs
 * @{
 */
#define LU_INIT_ID    0x00   /**< Service ID for LU initialization. */
#define LU_DEINIT_ID  0x01   /**< Service ID for LU deinitialization. */
/**
 * @}
 */

/**
 * @name  LU Dev Error Code
 * @{
 */
#define LU_E_PARAM_INSTANCE     0x01U   /**< Error code for invalid LU instance parameter. */
#define LU_E_PARAM_NULLPTR      0x02U   /**< Error code for null pointer parameter. */
/**
 * @}
 */

#define LU_AOI_IN_N_CFG_N(AoiIn, AoiInN, InNCfgNType) ((((uint32_t)(InNType) & 0x3U) << (((uint32_t)3U - (uint32_t)(AoiInN)) << 3U)) << (((uint32_t)3U - (uint32_t)(AoiIn)) << 3U))
#define LU_AOI_IN_N_CFG_N_MASK(AoiIn, AoiInN) (((uint32_t)0x3U << (((uint32_t)3U - (uint32_t)(AoiInN)) << 3U)) << (((uint32_t)3U - (uint32_t)(AoiIn)) << 3U))

#define LU_AOI_IN_CFG(AoiInN, CfgNType) ((((uint32_t)(CfgNType) & 0x3U) << (((uint32_t)3U - (uint32_t)(AoiInN)) << 1U)))
#define LU_AOI_IN_CFG_MASK(AoiInN) ((((uint32_t)0x3U) << (((uint32_t)3U - (uint32_t)(AoiInN)) << 1U)))

#define LU_AOI_IN_N_CFG(AoiIn, InNType) ((((uint32_t)(InNType) & 0xFFU) << (((uint32_t)3U - (uint32_t)(AoiIn)) << 3U)))
#define LU_AOI_IN_N_CFG_MASK(AoiIn) ((((uint32_t)0xFFU) << (((uint32_t)3U - (uint32_t)(AoiIn)) << 3U)))

#define LU_SYNC_CONTROL_INPUT_N(InputN, value) ((uint32_t)(value) << (InputN))

/** @brief LU instance */
typedef enum
{
    LU_INSTANCE_0 = 0U,
    LU_INSTANCE_1
} LU_InstanceType;

/** @brief LU return structure */
typedef enum
{
    LU_STATUS_SUCCESS = 0U,
    LU_STATUS_PARAM_INVALID = 1U
} LU_StatusType;

/** @brief LU output initialization value */
typedef enum
{
    LU_OUTPUT_INIT_ZERO = 0U,
    LU_OUTPUT_INIT_ONE,
    LU_OUTPUT_INIT_DISABLE
} LU_LG_FFOutputInitValueType;

/** @brief LU IN(n) configuration register type */
typedef struct
{
    LU_InputDType eInACfg;       /**< LUT IN A configuration */
    LU_InputDType eInBCfg;       /**< LUT IN B configuration */
    LU_InputDType eInCCfg;       /**< LUT IN C configuration */
    LU_InputDType eInDCfg;       /**< LUT IN D configuration */
} LU_LG_InPutConfigType;

/** @brief LU IN(n) configuration register type */
typedef struct
{
    LU_OutputDType eOut0ACfg;       /**< LU OUT 0A configuration */
    LU_OutputDType eOut0BCfg;       /**< LU OUT 0B configuration */
    LU_OutputDType eOut1ACfg;       /**< LU OUT 1A configuration */
    LU_OutputDType eOut1BCfg;       /**< LU OUT 1B configuration */
    LU_OutputDType eOut2ACfg;       /**< LU OUT 2A configuration */
    LU_OutputDType eOut2BCfg;       /**< LU OUT 2B configuration */
    LU_OutputDType eOut3ACfg;       /**< LU OUT 3A configuration */
    LU_OutputDType eOut3BCfg;       /**< LU OUT 3B configuration */
} LU_OutputConfigType;

/** @brief LU LG inputs synchronous control */
typedef struct
{
    bool bInputASync;        /**< LU IN A sync control */
    bool bInputBSync;        /**< LU IN B sync control */
    bool bInputCSync;        /**< LU IN C sync control */
    bool bInputDSync;        /**< LU IN D sync control */
} LU_LG_InputSyncCtrlType;

/** @brief LU_Handle type */
typedef struct _LU_HandleType
{
    LU_InstanceType eInstance;

    struct
    {
        uint32_t u32DATA0;                             /** direct access to DU_DATA0 Register */
        uint32_t u32DATA1;                             /** direct access to DU_DATA1 Register */
        uint32_t u32DATA2;                             /** direct access to DU_DATA2 Register */
        uint32_t u32DATA3;                             /** direct access to DU_DATA3 Register */
        uint32_t u32DATA4;                             /** direct access to DU_DATA4 Register */
        uint32_t u32DATA5;                             /** direct access to DU_DATA5 Register */
        uint32_t u32DATA6;                             /** direct access to DU_DATA6 Register */
        uint32_t u32DATA7;                             /** direct access to DU_DATA7 Register */

        void(*pDuInterruptCallback)(struct _LU_HandleType  *pHandle);
        void(*(pLgInterruptCallback[4]))(struct _LU_HandleType  *pHandle);
    }Lu_Status;
}LU_HandleType;

/** @brief Lg configuration type */
typedef struct
{
    bool bEnableInterrupt;                         /**< Enable lg interrupt or not, only lg_outa support */
    bool bGenerateDMARequest;                      /**< Generation of DMA request, only lg_outb support */
    uint8_t u8Lut0FiltCnt;                         /**< Lut0 input filter sample count */
    uint8_t u8Lut0Period;                          /**< Lut0 input filter sample period */
    uint8_t u8Lut1FiltCnt;                         /**< Lut1 input filter sample count */
    uint8_t u8Lut1Period;                          /**< Lut1 input filter sample period */
    uint16_t u16LUT0Position;                      /**< Specifies the LUT0 positions */
    uint16_t u16LUT1Position;                      /**< Specifies the LUT1 positions */
    LU_LG_InPutConfigType tLgInputConfig;          /**< LG configuration */
    LU_LG_InputSyncCtrlType tSyncCtrl;             /**< inputs sync control, when set, would sync input product with bus clock */
    LU_LG_BypassModeType eLutMode;                 /**< Lut mode */
    LU_LG_ConfigModeType eFFMode;                  /**< flip-flop mode */
    LU_LG_FFOutputInitValueType eFFInitValue;      /**< flip-flop initial value */
    LU_LG_InputNType eFbMode;                      /**< feedback override control in JKFF mode */
    void(*pLgInterruptCallback)(struct _LU_HandleType  *pHandle);
} LU_LG_ConfigType;

/** @brief DU_INCR configuration type */
typedef struct
{
    uint32_t u32InitialVal;                        /** increments data by 1 from an initial value (DU_DATA0) until reaches a final value (DU_DATA1) */
    uint32_t u32FinalVal;
    LU_DU_CaptureModeType eCaptureEdge;
}LU_DU_INCR_ConfigType;

/** @brief DU_DECR configuration type */
typedef struct
{
    uint32_t u32InitialVal;                       /** decrements data from an initial value (DU_DATA0) until it reaches "0" */
    LU_DU_CaptureModeType eCaptureEdge;
}LU_DU_DECR_ConfigType;

/** @brief DU_INCR_WRAP configuration type */
typedef struct
{
    uint32_t u32InitialVal;                        /** increments data by 1 from an initial value (DU_DATA0) until reaches a final value (DU_DATA1) */
    uint32_t u32FinalVal;                          /** INCR_Wrap wraps around to DU_DATA0 */
    LU_DU_CaptureModeType eCaptureEdge;
}LU_DU_INCR_WRAP_ConfigType;

/** @brief DU_DECR_WRAP configuration type */
typedef struct
{
    uint32_t u32InitialVal;                       /** decrements data from an initial value (DU_DATA0) until it reaches "0" */
    LU_DU_CaptureModeType eCaptureEdge;
}LU_DU_DECR_WRAP_ConfigType;                      /** DECR_Wrap wraps around to DU_DATA1 */

/** @brief DU_INCR_DECR configuration type */
typedef struct
{
    uint32_t u32InitialVal;                        /** INCR_DECR is a combination of INCR and DECR */
    uint32_t u32FinalVal;
}LU_DU_INCR_DECR_ConfigType;

/** @brief DU_INCR_DECR_WRAP configuration type */
typedef struct
{
    uint32_t u32InitialVal;                        /** INCR_DECR_Wrap has the same functionality as INCR_DECR with wrap around to DU_DATA0 on reaching the limits(DU_DATA1 or "0"). */
    uint32_t u32FinalVal;
}LU_DU_INCR_DECR_WRAP_ConfigType;

/** @brief DU_INCR_WRAP_MODE1 configuration type */
typedef struct
{
    uint32_t u32InitialVal;                        /** INCR_DECR_Wrap has the same functionality as INCR_DECR with wrap around to DU_DATA0 on reaching the limits(DU_DATA1 or "0"). */
    uint32_t u32MediumVal;
    uint32_t u32FinalVal;
    LU_DU_CaptureModeType eCaptureEdge;
}LU_DU_INCR_WRAP_MODE1_ConfigType;

/** @brief DU_INCR_DECR_WRAP_MODE1 configuration type */
typedef struct
{
    uint32_t u32InitialVal;                        /** INCR_DECR_Wrap_Mode1 is a combination of INCR and DECR */
    uint32_t u32MediumVal;
    uint32_t u32FinalVal;
    LU_DU_CaptureModeType eCaptureEdge;
}LU_DU_INCR_DECR_WRAP_MODE1_ConfigType;

/** @brief DU_SHIFT_IN_LEFT configuration type */
typedef struct
{
    bool bShiftInitCfg;                            /** The first trigger signal is sent or not*/
    bool bContinuousEnable;                        /** Enable continuous mode */
    uint32_t u32ShiftInBitCnt;                     /** Up to 96bit can be collected at a time and stored in DU_DATA4, DU_DATA6, DU_DATA5 in sequence  */
}LU_DU_SHIFT_IN_LEFT_ConfigType;

/** @brief DU_SHIFT_IN_RIGHT configuration type */
typedef struct
{
    bool bShiftInitCfg;                            /** The first trigger signal is sent or not*/
    bool bContinuousEnable;                        /** Enable continuous mode */
    uint32_t u32ShiftInBitCnt;                     /** Up to 96bit */
}LU_DU_SHIFT_IN_RIGHT_ConfigType;

/** @brief DU_SHIFT_OUT_LEFT configuration type */
typedef struct
{
    bool bShiftInitCfg;                            /** The first trigger signal is sent or not*/
    bool bContinuousEnable;                        /** Enable continuous mode */
    uint32_t u32ShiftInBitCnt;                     /** Up to 96bit can be collected at a time and stored in DU_DATA4, DU_DATA6, DU_DATA5 in sequence  */
    uint32_t u32ShiftData1;                        /** and DU_DATA1, DU_DATA0, and DU_DATA2 can be sent in sequence*/
    uint32_t u32ShiftData0;
    uint32_t u32ShiftData2;
}LU_DU_SHIFT_OUT_LEFT_ConfigType;

/** @brief DU_SHIFT_OUT_RIGHT configuration type */
typedef struct
{
    bool bShiftInitCfg;                            /** The first trigger signal is sent or not*/
    bool bContinuousEnable;                        /** Enable continuous mode */
    uint32_t u32ShiftInBitCnt;                     /** Up to 96bit can be collected at a time and stored in DU_DATA4, DU_DATA6, DU_DATA5 in sequence  */
    uint32_t u32ShiftData1;                        /** and DU_DATA1, DU_DATA0, and DU_DATA2 can be sent in sequence*/
    uint32_t u32ShiftData0;
    uint32_t u32ShiftData2;
}LU_DU_SHIFT_OUT_RIGHT_ConfigType;

/** @brief DU_FLEX_MODE configuration type */
typedef struct
{
    uint32_t u32CTRL;                              /** direct access to DU_CTRL Register */
    uint32_t u32CFG;                               /** direct access to DU_CFG Register */
    uint32_t u32DATA0;                             /** direct access to DU_DATA0 Register */
    uint32_t u32DATA1;                             /** direct access to DU_DATA1 Register */
    uint32_t u32DATA2;                             /** direct access to DU_DATA2 Register */
    uint32_t u32DATA3;                             /** direct access to DU_DATA3 Register */
    uint32_t u32DATA4;                             /** direct access to DU_DATA4 Register */
    uint32_t u32DATA5;                             /** direct access to DU_DATA5 Register */
    uint32_t u32DATA6;                             /** direct access to DU_DATA6 Register */
    uint32_t u32DATA7;                             /** direct access to DU_DATA7 Register */
}LU_DU_FLEX_MODE_ConfigType;

/** @brief DU input configuration type */
typedef struct
{
    LU_DU_InputMuxType eDuInputASelect;
    LU_DU_InputMuxType eDuInputBSelect;
    LU_DU_InputMuxType eDuInputCSelect;
}LU_DU_Input_ConfigType;

typedef struct
{
    uint32_t u32MatchData;
    uint32_t u32MatchMask;
}LU_DU_MATCH_MODE_ConfigType;

/** @brief DU configuration type */
typedef struct
{
    bool bEnableMatchInterrupt;                         /**< Enable du interrupt or not */
    bool bEnableUnderflowInterrupt;                     /**< Enable du interrupt or not */
    bool bEnableOverflowInterrupt;                      /**< Enable du interrupt or not */
    bool bGenerateMatchDMARequest;                      /**< Generation of DMA request*/
    bool bGenerateUnderflowDMARequest;                  /**< Generation of DMA request*/
    bool bGenerateOverflowDMARequest;                   /**< Generation of DMA request*/
    LU_DU_OpcType eDuOperationCode;
    LU_DU_Input_ConfigType tDuInputSelect;
    void(*pDuInterruptCallback)(struct _LU_HandleType  *pHandle);

    union
    {
        LU_DU_INCR_ConfigType tINCR_Cfg;
        LU_DU_DECR_ConfigType tDECR_Cfg;
        LU_DU_INCR_WRAP_ConfigType tINCR_WRAP_Cfg;
        LU_DU_DECR_WRAP_ConfigType tDECR_WRAP_Cfg;
        LU_DU_INCR_DECR_ConfigType tINCR_DECR_Cfg;
        LU_DU_INCR_DECR_WRAP_ConfigType tINCR_DECR_WRAP_Cfg;
        LU_DU_INCR_WRAP_MODE1_ConfigType tINCR_WRAP_MODE1_Cfg;
        LU_DU_INCR_DECR_WRAP_MODE1_ConfigType tINCR_DECR_WRAP_MODE1_Cfg;
        LU_DU_SHIFT_IN_LEFT_ConfigType tSHIFT_IN_LEFT_Cfg;
        LU_DU_SHIFT_IN_RIGHT_ConfigType tSHIFT_IN_RIGHT_Cfg;
        LU_DU_SHIFT_OUT_LEFT_ConfigType tSHIFT_OUT_LEFT_Cfg;
        LU_DU_SHIFT_OUT_RIGHT_ConfigType tSHIFT_OUT_RIGHT_Cfg;
        LU_DU_FLEX_MODE_ConfigType tFlex_Mode_Cfg;
        LU_DU_MATCH_MODE_ConfigType tMatch_Mode_Cfg;
    }DU_OperationCfg;
} LU_DU_ConfigType;

/** @brief LU configuration type */
typedef struct
{
    LU_LG_ConfigType tLgCfg[LG_CNT];
    LU_DU_ConfigType tDuCfg;
    LU_OutputConfigType tLuOutCfg;
    LU_PrescalerType eLuClockPreScaler;
} LU_ConfigType;

/* global functions */
/**
 * @brief Initialize LU instance
 *
 * @param eLu LU instance
 * @param pInitStruct LU initialization structure
 * @return LU return type
 */
LU_StatusType LU_Init(LU_HandleType *pLuHandler, const LU_ConfigType *const pInitStruct);

/**
 * @brief De-initialize LU instance
 *
 * @param eLu LU instance
 */
void LU_Deinit(LU_HandleType *pLuHandler);

/**
 * @brief Lu interrupt function.
* @param pLuHandle Lu processing handle
 */
void LUn_IRQHandler(LU_HandleType *pLuHandle);

/** @}*/ /* module_driver_lu */

#endif /* #if LU_INSTANCE_COUNT > 0U */

#endif
