/**
 * @file module_driver_eftu_tom.h
 * @author flagchip
 * @brief eFTU tom driver type definition and API
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

#ifndef _DRIVER_FC500_DRIVER_EFTU_TOM_H_
#define _DRIVER_FC500_DRIVER_EFTU_TOM_H_

#include "HwA_eftu_tom.h"
#if defined(EFTU_INSTANCE_COUNT) && (EFTU_INSTANCE_COUNT > 0U)

/**
 * @addtogroup module_driver_eftu_tom
 * @{
 */

#include "module_driver_eftu.h"
#include "module_driver_eftu_cmu.h"

#if defined(__cplusplus)
extern "C" {
#endif

/**
 * @name  EFTU_TOM API Service IDs
 *
 * @{
 */
#define EFTU_TOM_TIMER_INIT_ID				0U
#define EFTU_TOM_START_TIMER_CHANNEL_ID		1U
#define EFTU_TOM_STOP_TIMER_CHANNEL_ID		2U
#define EFTU_TOM_PWM_INIT_ID				3U
#define EFTU_TOM_START_PWM_CHANNEL_ID		4U
#define EFTU_TOM_STOP_PWM_CHANNEL_ID		5U
#define EFTU_TOM_UPDATE_PWM_PERIOD_ID		6U
#define EFTU_TOM_UPDATE_PWM_DUTY_ID			7U
#define EFTU_TOM_UPDATE_PWM_PHASESHIFT_ID	8U
#define EFTU_TOM_SYNC_UPDATE_ID				9U
#define EFTU_TOM_SET_TRIG_OUT_ID			10U
/** @}*/

/**
 * @name  EFTU_TOM Dev Error Code
 * @brief Error Code of calling EFTU_TOM apis
 *
 * @{
 */
#define EFTU_TOM_E_PARAM_INSTANCE  			0x00U
#define EFTU_TOM_E_PARAM_CHANNEL   			0x01U
#define EFTU_TOM_E_CLOCK_SRC_INVALID		0x02U
#define EFTU_TOM_E_TIME_INVALID				0x03U
#define EFTU_TOM_E_PARAM_INVALID			0x04U
#define EFTU_TOM_E_UNINITED					0x05U
#define EFTU_TOM_E_CHANNEL_MODE				0x06U
#define EFTU_TOM_E_PWM_MODE					0x07U
/** @}*/

/**
 * @brief Defines the operating modes for the EFTU Tom module.
 * 
 */
typedef enum
{
    EFTU_TOM_MODE_TIMER,    /**< Timer mode */
    EFTU_TOM_MODE_PWM,      /**< PWM mode */
} EFTU_Tom_ModeType;

/**
 * @brief Defines the update modes for the EFTU Tom module in PWM mode.
 * 
 */
typedef enum
{
    EFTU_TOM_PWM_UPDATE_IMMDIATELY,    /**< Immediate update of PWM period */
    EFTU_TOM_PWM_UPDATE_SYNC,          /**< Synchronous update of PWM period */
} EFTU_Tom_PwmUpdateModeType;

/**
 * @brief Enum for EFTU Tom Clock Source Types
 *
 */
typedef enum
{
    EFTU_TOM_CLK_SRC_CMU_CLK_0,
    EFTU_TOM_CLK_SRC_CMU_CLK_1,
    EFTU_TOM_CLK_SRC_CMU_CLK_2,
    EFTU_TOM_CLK_SRC_CMU_CLK_3,
    EFTU_TOM_CLK_SRC_CMU_CLK_4,
    EFTU_TOM_CLK_SRC_CMU_CLK_5,
    EFTU_TOM_CLK_SRC_CMU_CLK_6,
    EFTU_TOM_CLK_SRC_CMU_CLK_7,
} EFTU_Tom_ClockSourceType;

/**
 * @brief EFTU_Tom_HandleType is a structure used for configuring and operating an EFTU TOM channel.
 * 
 */
typedef struct _EFTU_Tom_HandleType
{
    EFTU_InstanceType    eEftuInstance;    /**< EFTU instance, identifies the EFTU device to which the TOM channel belongs */
    uint8_t              u8Channel;         /**< Channel number, specifies the specific TOM channel */
    EFTU_CMU_HandleType  *pCmuHandle;       /**< CMU handle, used to access and configure CMU-related functions */
    struct
    {
        EFTU_Tom_ModeType     eMode;         /**< TOM channel mode, determines the working mode of the channel */
        float                 fClock;        /**< Channel clock frequency, used to calculate and configure timing parameters of the TOM channel */
        EFTU_TOM_Type         *pTOM;         /**< TOM register base address, used to directly access TOM hardware registers */
        uint8_t               u8HwChannel;    /**< Hardware channel number, identifies the specific channel inside the TOM */
        union
        {
            struct
            {
                bool                        bPhaseShiftEnable;     /**< Phase shift enable, determines whether phase shift functionality is enabled */
                EFTU_Tom_PwmUpdateModeType  eUpdateMode;           /**< PWM update mode, determines the update method of the PWM signal */
                bool                        bUpDownMode;           /**< Up-down count mode enable, determines the counting method of the counter */
#if defined(HRPWM_INSTANCE_COUNT) && (HRPWM_INSTANCE_COUNT > 0U)
                bool                        bHrpwmSupport;         /**< High-resolution PWM support enable, determines whether high-resolution PWM is supported */
#endif
                float                       fDuty;                 /**< PWM duty cycle, determines the high-level time ratio of the PWM signal */
                float                       fPeriodPhaseShift;     /**< Period phase shift, determines the phase shift amount of the PWM signal */
            } tPwm;
        };
        struct
        {
            void (*pCcu0)(struct _EFTU_Tom_HandleType *pHandle);    /**< CCU0 interrupt callback function pointer, used to handle CCU0 interrupts */
            void (*pCcu1)(struct _EFTU_Tom_HandleType *pHandle);    /**< CCU1 interrupt callback function pointer, used to handle CCU1 interrupts */
        } tCallback;
    } tStatus;
} EFTU_Tom_ChannelHandleType;

/**
 * @brief EFTU_Tom_TimerConfigType is a structure used for configuring the EFTU TOM timer.
 * 
 */
typedef struct
{
    EFTU_Tom_ClockSourceType  eClockSource;                         /**< Timer clock source, determines the counting reference of the timer */
    float                     fTimeout;                             /**< Timeout value, determines the target count value of the timer */
    void (*pTimeoutCallback)(EFTU_Tom_ChannelHandleType *pHandle);  /**< Timeout callback function pointer, used to handle timer timeout events */
} EFTU_Tom_TimerConfigType;

/**
 * @brief EFTU_Tom_PwmConfigType is a structure used for configuring the EFTU TOM PWM functionality.
 * 
 */
typedef struct
{
    bool            bPhaseShiftEnable;          /**< Phase shift enable, determines whether phase shift functionality is enabled */
    EFTU_Tom_ClockSourceType  eClockSource;     /**< PWM clock source, determines the generation reference of the PWM signal */
    float           fDuty;                      /**< PWM duty cycle, determines the high-level time ratio of the PWM signal */
    union
    {
        float fPhaseShift;    /**< Phase shift amount, determines the phase shift value of the PWM signal */
        float fPeriod;        /**< PWM period, determines the repetition period of the PWM signal */
    };
    EFTU_Tom_PwmUpdateModeType  eUpdateMode;           /**< PWM update mode, determines the update method of the PWM signal */
    EFTU_TOM_SignalLevelType    eActiveLevel;          /**< PWM signal active level, determines the polarity of the PWM signal */
    bool                        bUpDownMode;           /**< Up-down count mode enable, determines the counting method of the counter */
    bool                        bCcu0IrqEnable;        /**< CCU0 interrupt enable, determines whether CCU0 interrupts are enabled */
    bool                        bCcu1IrqEnable;        /**< CCU1 interrupt enable, determines whether CCU1 interrupts are enabled */
#if defined(HRPWM_INSTANCE_COUNT) && (HRPWM_INSTANCE_COUNT > 0U)
    bool                        bHrpwmSupport;         /**< High-resolution PWM support enable, determines whether high-resolution PWM is supported */
#endif
    void (*pCcu0Callback)(EFTU_Tom_ChannelHandleType *pHandle);    /**< CCU0 interrupt callback function pointer, used to handle CCU0 interrupts */
    void (*pCcu1Callback)(EFTU_Tom_ChannelHandleType *pHandle);    /**< CCU1 interrupt callback function pointer, used to handle CCU1 interrupts */
} EFTU_Tom_PwmConfigType;

void EFTU_TOM_InitTimerChannel(EFTU_Tom_ChannelHandleType *pHandle, EFTU_Tom_TimerConfigType *pConfig);
void EFTU_TOM_InitPwmChannel(EFTU_Tom_ChannelHandleType *pHandle, EFTU_Tom_PwmConfigType *pConfig);
void EFTU_TOM_StartTimerChannel(EFTU_Tom_ChannelHandleType *pHandle);
void EFTU_TOM_SetTrigOutput(EFTU_Tom_ChannelHandleType *pHandle, EFTU_TOM_TrigOutSelectionType eTrigOutput);
void EFTU_TOM_StopTimerChannel(EFTU_Tom_ChannelHandleType *pHandle);
void EFTU_TOM_StartPwmChannel(EFTU_Tom_ChannelHandleType *pHandle, bool bImmediate);
void EFTU_TOM_StopPwmChannel(EFTU_Tom_ChannelHandleType *pHandle, bool bImmediate);
void EFTU_TOM_UpdatePwmPeriodAndDuty(EFTU_Tom_ChannelHandleType *pHandle, float fPeriod, float fDuty, bool bUpdate);
void EFTU_TOM_UpdatePwmDuty(EFTU_Tom_ChannelHandleType *pHandle, float fDuty, bool bUpdate);
void EFTU_TOM_UpdatePwmPhaseShfit(EFTU_Tom_ChannelHandleType *pHandle, float fPhaseShift, bool bUpdate);
void EFTU_TOM_SyncUpdate(EFTU_InstanceType eEftuInstance, uint16_t u16UpdateMask);
void EFTUn_TOM_IRQHandler(EFTU_Tom_ChannelHandleType *pHandle);

#if defined(__cplusplus)
}
#endif
/** @}*/ /* module_driver_eftu_tom */
#endif  /* defined(EFTU_INSTANCE_COUNT) && (EFTU_INSTANCE_COUNT > 0) */
#endif  /* _DRIVER_FC500_DRIVER_EFTU_TOM_H_ */
