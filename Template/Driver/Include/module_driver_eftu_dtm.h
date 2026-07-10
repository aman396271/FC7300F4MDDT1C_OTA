/**
 * @file module_driver_eftu_dtm.h
 * @author flagchip
 * @brief eFTU dtm driver type definition and API
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
   *   0.1.0       2023-12-15    Flagchip032   N/A          First version for FC7300
   *   2.0.0       2024-10-12    Flagchip070   N/A          Change version and release
   ******************************************************************************** */


#ifndef _DRIVER_FC500_DRIVER_EFTU_DTM_H_
#define _DRIVER_FC500_DRIVER_EFTU_DTM_H_
#include "HwA_eftu_dtm.h"
#include "module_driver_eftu.h"
#include "module_driver_eftu_cmu.h"

#if defined(EFTU_INSTANCE_COUNT) && (EFTU_INSTANCE_COUNT > 0U)

/**
 * @addtogroup module_driver_eftu_dtm
 * @{
 */

#if defined(__cplusplus)
extern "C" {
#endif

/**
 * @name  EFTU_DTM API Service IDs
 *
 * @{
 */
#define EFTU_DTM_INIT_CHANNEL_ID			0U
#define EFTU_DTM_SET_CHANNEL_SHUTOFF_ID		1U
/** @}*/

/**
 * @name  EFTU_DTM Dev Error Code
 * @brief Error Code of calling EFTU_DTM apis
 *
 * @{
 */
#define EFTU_DTM_E_PARAM_INSTANCE  			0x00U
#define EFTU_DTM_E_PARAM_CHANNEL   			0x01U
#define EFTU_DTM_E_CLOCK_SRC_INVALID		0x02U
#define EFTU_DTM_E_TIME_INVALID				0x03U
#define EFTU_DTM_E_PARAM_INVALID			0x04U
#define EFTU_DTM_E_UNINITED					0x05U
/** @}*/

/**
 * @brief Defines the types of EFTU DTM input signals
 * 
 */
typedef enum
{
	EFTU_DTM_INPUT_SIG_DTM_IN		= 0U,   /* Indicates the input signal is DTM in*/
	EFTU_DTM_INPUT_SIG_LOW_LEVEL,           /* Indicates the input signal is in a low-level state */
	EFTU_DTM_INPUT_SIG_HIGH_LEVEL,          /* Indicates the input signal is in a high-level state */
} EFTU_Dtm_InputSignalType;

/**
 * @brief Define the signal types used for DTM (Drive Train Monitoring) shut-off functionality
 * 
 */
typedef enum
{
	EFTU_DTM_SHUTOFF_SIG_TIM_IN0				= 0U,
	EFTU_DTM_SHUTOFF_SIG_TIM_IN1,
	EFTU_DTM_SHUTOFF_SIG_HSADC0_COMPARE_OUT,		/* for DTM 0/1 AUX_IN2 */
	EFTU_DTM_SHUTOFF_SIG_HSADC1_COMPARE_OUT,		/* for DTM 0/1 AUX_IN3 */
	EFTU_DTM_SHUTOFF_SIG_HSADC2_COMPARE_OUT,		/* for DTM 2/3 AUX_IN2*/
	EFTU_DTM_SHUTOFF_SIG_HSADC3_COMPARE_OUT,		/* for DTM 2/3 AUX_IN3 */
	EFTU_DTM_SHUTOFF_SIG_EFTU_FLT0,					/* for DTM 0/1 AUX_IN0 */
	EFTU_DTM_SHUTOFF_SIG_EFTU_FLT1,					/* for DTM 2/3 AUX_IN0 */
	EFTU_DTM_SHUTOFF_SIG_SDADC0_PROTECT2,			/* for DTM 0/1 AUX_IN1 */
	EFTU_DTM_SHUTOFF_SIG_SDADC1_PROTECT2,			/* for DTM 2/3 AUX_IN1 */
} EFTU_Dtm_ShutOffSignalType;

/**
 * @brief Define the clear conditions for DTM shut-off functionality
 * 
 */
typedef enum
{
	EFTU_DTM_SHUTOFF_CLEAR_BY_SHUTOFF_RESET	= 0U,   /* Clear by shut-off reset */
	EFTU_DTM_SHUTOFF_CLEAR_BY_IN_FEDGE,             /* Clear by input signal rising edge */
	EFTU_DTM_SHUTOFF_CLEAR_BY_IN_REDGE,             /* Clear by input signal falling edge */
	EFTU_DTM_SHUTOFF_CLEAR_BY_PREV_IN_FEDGE,        /* Clear by previous input signal rising edge */
	EFTU_DTM_SHUTOFF_CLEAR_BY_PREV_IN_REDGE,        /* Clear by previous input signal falling edge */
	EFTU_DTM_SHUTOFF_CLEAR_BY_SHUTOFF_SIGNAL,       /* Clear by shut-off signal */
} EFTU_Dtm_ShutOffClearType;

/**
 * @brief Define the effect level for DTM shut-off signal
 *
 */
typedef enum
{
	EFTU_DTM_SHUTOFF_HIGH_EFFECT	= 0U,			/* Shutoff signal is high effectiveness */
	EFTU_DTM_SHUTOFF_LOW_EFFECT,					/* Shutoff signal is low effectiveness */
} EFTU_Dtm_ShutOffLevelType;

/**
 * @brief The EFTU_Dtm_HandleType structure defines the handle type for an EFTU DTM channel.
 * 
 */
typedef struct _EFTU_Dtm_HandleType
{
    EFTU_InstanceType        eEftuInstance;    /**< EFTU instance */
    uint8_t                  u8Channel;        /**< Channel number */
    EFTU_CMU_HandleType      *pCmuHandle;      /**< CMU handle */
    struct
    {
        EFTU_DTM_Type        *pDtm;            /**< DTM peripheral base address */
        uint8_t              u8HwChannel;      /**< Hardware channel number */
        float                fClock;           /**< Channel clock frequency */
#if defined(HRPWM_INSTANCE_COUNT) && (HRPWM_INSTANCE_COUNT > 0U)
        bool                 bHrpwmSupport;    /**< Whether HRPWM is supported */
#endif
    } tStatus;
} EFTU_Dtm_ChannelHandleType;

/**
 * @brief The EFTU_Dtm_OutputConfigType structure defines the output configuration type for EFTU DTM.
 * 
 */
typedef struct
{
    EFTU_Dtm_InputSignalType eInputSignal;     /**< Input signal */
    bool                     bInvertPol;       /**< Whether to invert the output polarity */
} EFTU_Dtm_OutputConfigType;

/**
 * @brief The EFTU_Dtm_ChannelConfigType structure defines the configuration type for an EFTU DTM channel.
 * 
 */
typedef struct
{
    EFTU_DTM_ClockSourceType eClockSource;     /**< Clock source */
    EFTU_Dtm_OutputConfigType tOutput;         /**< Forward output configuration */
    EFTU_Dtm_OutputConfigType tOutputN;        /**< Reverse output configuration */

    bool                     bRisingDeadTimeEnable; /**< Enable rising edge dead time */
    bool                     bFallingDeadTimeEnable;/**< Enable falling edge dead time */
    float                    fRisingDeadTime;    /**< Rising edge dead time */
    float                    fFallingDeadTime;   /**< Falling edge dead time */
    bool					 bSwapOutput;		/**< Falling edge dead time */
#if defined(HRPWM_INSTANCE_COUNT) && (HRPWM_INSTANCE_COUNT > 0U)
    bool                     bHRPwmSupport;      /**< Whether HRPWM is supported */
#endif
} EFTU_Dtm_ChannelConfigType;

/**
 * @brief The EFTU_Dtm_ShutOffConfigType structure defines the shutdown configuration type for EFTU DTM.
 * 
 */
typedef struct
{
    bool                        bEnable;           	/**< Enable shutdown functionality */
    EFTU_Dtm_ShutOffLevelType   eShutOffLevel; 		/**< Effect level of the shutdown signal */
    EFTU_Dtm_ShutOffSignalType  eShutOffSignal;  	/**< Shutdown signal */
    EFTU_Dtm_ShutOffClearType   eClearMode;       	/**< Clear mode */
    EFTU_DTM_SignalLevelType    eOutputLevel;      	/**< Forward output level */
    EFTU_DTM_SignalLevelType    eOutputNLevel;     	/**< Reverse output level */
} EFTU_Dtm_ShutOffConfigType;

void EFTU_DTM_InitChannel(EFTU_Dtm_ChannelHandleType *pHandle, EFTU_Dtm_ChannelConfigType *pConfig);
void EFTU_DTM_SetChannelShutOff(EFTU_Dtm_ChannelHandleType *pHandle, EFTU_Dtm_ShutOffConfigType *pConfig);
void EFTU_DTM_ClearShutOff(EFTU_Dtm_ChannelHandleType *pHandle);

#if defined(__cplusplus)
}
#endif
#endif  /* defined(EFTU_INSTANCE_COUNT) && (EFTU_INSTANCE_COUNT > 0) */
#endif  /* _DRIVER_FC500_DRIVER_EFTU_DTM_H_ */
