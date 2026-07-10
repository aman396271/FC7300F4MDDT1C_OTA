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
#ifndef _DRIVER_MODULE_DRIVER_LU_H_
#define _DRIVER_MODULE_DRIVER_LU_H_
#include "HwA_lu.h"

#if LU_INSTANCE_COUNT > 0U

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

/** @brief LU IN type */
typedef enum
{
    LU_AOI_IN_0 = 0U,
    LU_AOI_IN_1,
    LU_AOI_IN_2,
    LU_AOI_IN_3,
} LU_AoiInType;

/** @brief LU IN(n) configuration type */
typedef enum
{
    LU_AOI_IN_N_A = 0U,
    LU_AOI_IN_N_B,
    LU_AOI_IN_N_C,
    LU_AOI_IN_N_D
} LU_AoiInNType;

/** @brief LU IN(n) configuration */
typedef enum
{
    FORCE_ITEM_AS_ZERO    = 0U,    /**< force item as logic zero */
    PASS_THROUGH_ITEM,             /**< pass through item */
    COMPLEMENT_ITEM,               /**< complement item */
    FORCE_ITEM_AS_ONE              /**< force item as logic one */
} LU_InModeType;

/** @brief LU output initialization value */
typedef enum
{
    LU_OUTPUT_INIT_ZERO = 0U,
    LU_OUTPUT_INIT_ONE,
    LU_OUTPUT_INIT_DISABLE
} LU_OutputInitValueType;

/** @brief LU IN(n) configuration register type */
typedef struct
{
    LU_InModeType eInNACfg;       /**< AOI IN(n) A configuration */
    LU_InModeType eInNBCfg;       /**< AOI IN(n) B configuration */
    LU_InModeType eInNCCfg;       /**< AOI IN(n) C configuration */
    LU_InModeType eInNDCfg;       /**< AOI IN(n) D configuration */
} LU_InConfigType;

/** @brief LU AOI IN(n) configuration type */
typedef struct
{
    LU_InConfigType tIn0Config;         /**< AOI IN0 configuration */
    LU_InConfigType tIn1Config;         /**< AOI IN1 configuration */
    LU_InConfigType tIn2Config;         /**< AOI IN2 configuration */
    LU_InConfigType tIn3Config;         /**< AOI IN3 configuration */
} LU_AoiConfigType;

/** @brief LU LG inputs synchronous control */
typedef struct
{
    bool bInputNA;        /**< LU IN(n) A sync control */
    bool bInputNB;        /**< LU IN(n) B sync control */
    bool bInputNC;        /**< LU IN(n) C sync control */
    bool bInputND;        /**< LU IN(n) D sync control */
} LU_InputsSyncCtrlType;

/** @brief LU initialization type */
typedef struct
{
    LU_LgType eLgNum;                              /**< LG number */
    LU_AoiConfigType tAoi0Config;                  /**< aoi0 configuration */
    LU_AoiConfigType tAoi1Config;                  /**< aoi1 configuration */
    LU_InputsSyncCtrlType tSyncCtrl;               /**< inputs sync control, when set, would sync input product with bus clock */
    LU_BypassModeType eAoiMode;                    /**< AOI mode */
    LU_ConfigModeType eFFMode;                     /**< flip-flop mode */
    LU_OutputInitValueType eFFInitValue;           /**< flip-flop initial value */
    LU_InputNType eFbMode;                         /**< feedback override control in JKFF mode */
    uint8_t u8Aoi0FiltCnt;                         /**< aoi0 input filter sample count */
    uint8_t u8Aoi0Period;                          /**< aoi0 input filter sample period */
    uint8_t u8Aoi1FiltCnt;                         /**< aoi1 input filter sample count */
    uint8_t u8Aoi1Period;                          /**< aoi1 input filter sample period */
} LU_ConfigType;

/* global functions */
/**
 * @brief Initialize LU instance
 *
 * @param eLu LU instance
 * @param pInitStruct LU initialization structure
 * @return LU return type
 */
LU_StatusType LU_Init(const LU_InstanceType eLu, const LU_ConfigType *const pInitStruct);

/**
 * @brief De-initialize LU instance
 *
 * @param eLu LU instance
 */
void LU_Deinit(const LU_InstanceType eLu);

/** @}*/ /* module_driver_lu */

#endif /* #if LU_INSTANCE_COUNT > 0U */
#endif
