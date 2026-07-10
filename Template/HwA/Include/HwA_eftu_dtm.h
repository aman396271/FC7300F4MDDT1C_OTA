/**
 * @file HwA_eftu_dtm.h
 * @author flagchip
 * @brief Hardware access layer for EFTU DTM
 * @version 2.0.0
 * @date 2024-08-20
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
   *   0.1.0      2023-12-15     Flagchip030   N/A          First version for FC7300
   *   2.0.0      2024-10-12     Flagchip070   N/A          Change version and release
   ******************************************************************************** */


#ifndef _HWA_EFTU_ATM_H_
#define _HWA_EFTU_ATM_H_
#include "device_header.h"

#if EFTU_INSTANCE_COUNT > 0U

/**
 * @defgroup HwA_eftu_tom HwA_eftu_dtm
 * @ingroup module_driver_eftu_dtm
 * @{
 */

/**
 * @brief Clock Resolution Selection
 *
 */
typedef enum
{
	EFTU_DTM_CLOCK_SRC_SYS_CLK	= 0u,   /* CLS_CLK resolution selected (cluster clock) */
	EFTU_DTM_CLOCK_SRC_CMU_CLK0,        /* CCM_CLK_RES[0] resolution selected */
	EFTU_DTM_CLOCK_SRC_CMU_CLK1,        /* CCM_CLK_RES[1] resolution selected */
	EFTU_DTM_CLOCK_SRC_CMU_CLK2,        /* CCM_CLK_RES[2] resolution selected */
} EFTU_DTM_ClockSourceType;

/**
 * @brief Selection of DTM Update and PSU_SHUT_OFF Reset Signal
 *
 */
typedef enum
{
	EFTU_DTM_SEL_FALLING_EDGE_ON_CURRENT	= 0U,   /* Select falling edge on current DTM channel 0 input */
	EFTU_DTM_SEL_RISING_EDGE_ON_CURRENT,            /* Select rising edge on current DTM channel 0 input */
	EFTU_DTM_SEL_FALLING_EDGE_ON_PRECEDING,         /* Select falling edge on preceding DTM channel 0 input */
	EFTU_DTM_SEL_RISING_EDGE_ON_PRECEDING,          /* Select rising edge on preceding DTM channel 0 input */
} EFTU_DTM_UpdateSourceType;

/**
 * @brief Selection of Output 1 
 *
 */
typedef enum
{
	EFTU_DTM_O1SEL_INV_DEAD_TIME_SIGNAL = 0U,       /* Inverse dead time signal selected */
	EFTU_DTM_O1SEL_SPECIAL_FUNTION                  /* Special function on output 1 selected (defined by
                                                       CH_CTRL1[O1F_0]) */
} EFTU_DTM_Output1SelectType;

/**
 * @brief Selection of Input 1
 *
 */
typedef enum
{
	EFTU_DTM_I1SEL_PSU_SHIFT		= 0U,           /* Signal PSU_SHIFT[0] selected */
	EFTU_DTM_I1SEL_PRE_DTM_COUT3_I,                 /* Signal DTM_COUT3_I from preceding DTM instance selected */
} EFTU_DTM_Input1SelectType;

/**
 * @brief Selection of Output 0 Control
 *
 */
typedef enum
{
	EFTU_DTM_OC_FUNCTIONAL		= 0U,           /* Functional output */
	EFTU_DTM_OC_CONSTANT,                       /* Constant output defined by CH_CTRL2[SL0_0] */
} EFTU_DTM_Output0ControlType;

/**
 * @brief Selection of Signal Level on Output
 *
 */
typedef enum
{
	EFTU_DTM_SL_LOW		= 0U,           /* Set Signal Level to 0 */
	EFTU_DTM_SL_HIGH                    /* Set Signal Level to 1 */
} EFTU_DTM_SignalLevelType;

/**
 * @brief Selection of Combinational Input
 *
 */
typedef enum
{
	EFTU_DTM_CIS_DTM_IN		= 0U,       /* Select the input DTM_IN[N] or DTM_IN_T[N] of the instance
                                           (CH_CTRL3[TSEL0_N] selects one of the two input signals) */
	EFTU_DTM_CIS_EDGE_TRIGG             /* Select internal signal EDGE_TRIGG_[N] */
} EFTU_DTM_CombInputSelectType;

/**
 * @brief Input Selection for Dead Time / Edge Trigger Generation
 *
 */
typedef enum
{
	EFTU_DTM_EDGE_TRIG_SEL_DTM_IN		= 0U,   /* Use DTM_IN[N] of the instance as input for dead time / edge trigger
                                                   generation */
	EFTU_DTM_EDGE_TRIG_SEL_DTM_IN_T             /* Use DTM_IN_T[N] of the instance as input for dead time / edge
                                                   trigger generation */
} EFTU_DTM_EdgeTrigSelectType;

/**
 * @brief Input Selection of Combinational Logic Path
 *
 */
typedef enum
{
	EFTU_DTM_COMB_INPUT_LOGIC_PATH_SEL_DTM_IN		= 0U,   /* Use DTM_IN[N] of the instance as input for combinational logic path */
	EFTU_DTM_COMB_INPUT_LOGIC_PATH_SEL_DTM_IN_T             /* Use DTM_IN_T[N] of the instance as input for combinational logic
                                                               path */
} EFTU_DTM_CombInputLogicPathSelectType;

/**
 * @brief Selection of PSU Input
 *
 */
typedef enum
{
	EFTU_DTM_PSU_IN_TIM_CH_IN = 0u,     /* TIM_CH_IN0 or TIM_CH_IN1 selected */
	EFTU_DTM_PSU_IN_DTM_AUX_IN,         /* DTM_AUX_IN selected */ 
} EFTU_DTM_PsuInputSelectType;

/**
 * @brief Selection of input signal to be used as shutoff signal
 *
 */
typedef enum
{
	EFTU_DTM_SHUTOFF_SEL_TIM_CH_IN0		= 0U,       /* TIM_CH_IN0 selected */
	EFTU_DTM_SHUTOFF_SEL_TIM_CH_IN1,                /* TIM_CH_IN1 selected */
	EFTU_DTM_SHUTOFF_SEL_DTM_AUX_IN2,               /* DTM_AUX_IN[2] of the instance selected (SoC special connection) */
	EFTU_DTM_SHUTOFF_SEL_DTM_AUX_IN3,               /* DTM_AUX_IN[3] of the instance selected (SoC special connection) */      
	EFTU_DTM_SHUTOFF_SEL_DTM_AUX_IN0,               /* DTM_AUX_IN[0] of the instance selected (SoC special connection) */
	EFTU_DTM_SHUTOFF_SEL_DTM_AUX_IN1,               /* DTM_AUX_IN[1] of the instance selected (SoC special connection) */
	EFTU_DTM_SHUTOFF_SEL_DTM_LOW,                   /* '0' selected */
	EFTU_DTM_SHUTOFF_SEL_DTM_HIGH                   /* '1' selected*/
} EFTU_DTM_ShutOffSignalType;

/**
 * @brief Selection of Shift
 *
 */
typedef enum
{
	EFTU_DTM_SHIFT_SELECT_CHANNEL1	= 0u,           /* Trigger signal for reloading DOWN COUNTER is IN_EDGE[0] of 
                                                       DTM channel [0]; PSU works on DTM channel 1*/
	EFTU_DTM_SHIFT_SELECT_CHANNEL2,                 /* Trigger signal for reloading DOWN COUNTER is IN_EDGE[1] of
                                                       DTM channel [1]; PSU works on DTM channel 2*/
	EFTU_DTM_SHIFT_SELECT_CHANNEL3,                 /* Trigger signal for reloading DOWN COUNTER is IN_EDGE[2] of
                                                       DTM channel [2]; PSU works on DTM channel 3*/
	EFTU_DTM_SHIFT_SELECT_CHANNEL0                  /* No loading of DOWN COUNTER (blanking window feature
                                                       deactivated); PSU works on DTM channel 0*/
} EFTU_DTM_ShiftSelectType;

/**
 * @brief Selection of TIM Input
 *
 */
typedef enum
{
	EFTU_DTM_TIM_SEL_TIM_IN0	= 0u,
	EFTU_DTM_TIM_SEL_TIM_IN1,
} EFTU_DTM_TimInputSelectType;

/**
 * @brief Selection of Channel deadtime trigger
 *
 */
typedef enum
{
	EFTU_DTM_CHDTV_TRIG_BY_FALLING_EDGE		= 0U,   /* Update of CHn_DTV triggered by falling edge */
	EFTU_DTM_CHDTV_TRIG_BY_RISING_EDGE              /* Update of CHn_DTV triggered by rising edge */
} EFTU_DTM_DeadTimeTrigSelectType;

/**
 * @brief Set the clock source for EFTU DTM
 * 
 * @param pDtm Pointer to the base address of the EFTU DTM, used to access the DTM controller registers
 * @param eClockSource The clock source type to be set, which is an enumerated value representing different clock source options
 */
LOCAL_INLINE void EFTU_DTM_HWA_SetClockSource(EFTU_DTM_Type * const pDtm, EFTU_DTM_ClockSourceType eClockSource)
{
	pDtm->CTRL = (pDtm->CTRL & (~(uint32_t)EFTU_DTM_CTRL_CLK_SEL_MASK)) | EFTU_DTM_CTRL_CLK_SEL(eClockSource);
}

/**
 * @brief Set the DTM update signal source
 * 
 * @param pDtm Pointer to the base address of the DTM module, used to access the DTM control register
 * @param eSignal The specified update signal source, which is an enumerated value representing different signal sources
 */
LOCAL_INLINE void EFTU_DTM_HWA_SetUpdateSignal(EFTU_DTM_Type * const pDtm, EFTU_DTM_UpdateSourceType eSignal)
{
	pDtm->CTRL = (pDtm->CTRL & (~(uint32_t)EFTU_DTM_CTRL_DTM_SEL_MASK)) | EFTU_DTM_CTRL_DTM_SEL(eSignal);
}

/**
 * @brief Set the update mode of the DTM
 * 
 * @param pDtm Pointer to the base address of the DTM module, used to access and modify DTM registers
 * @param u8UpdateMode The value of the update mode, which determines the operating mode of the DTM
 *                      000b - Asynchronous update
 *                      001b - Shutoff release by writing 1 to bit CTRL[SHUT_OFF_RST]
 *                      010b - Shutoff release by Select DTM Update and PSU_SHUT_OFF
 *                             Reset Signal
 *                      011b - Shutoff release by shutoff signal PSU_SHUT_OFF
 *                      100b - Signal IN_EDGE[0] (from channel 0) used to trigger update of
 *                             CH_CTRL2 with content of CH_CTRL2_SR
 *                      101b - Signal IN_EDGE[1] (from channel 1) used to trigger update of
 *                             CH_CTRL2 with content of CH_CTRL2_SR
 *                      110b - Signal IN_EDGE[2] (from channel 2) used to trigger update of
 *                             CH_CTRL2 with content of CH_CTRL2_SR
 *                      111b - Signal IN_EDGE[3] (from channel 3) used to trigger update of
 *                             CH_CTRL2 with content of CH_CTRL2_SR
 */
LOCAL_INLINE void EFTU_DTM_HWA_SetUpdateMode(EFTU_DTM_Type * const pDtm, uint8_t u8UpdateMode)
{
	pDtm->CTRL = (pDtm->CTRL & (~(uint32_t)EFTU_DTM_CTRL_UPD_MODE_MASK)) | EFTU_DTM_CTRL_UPD_MODE(u8UpdateMode);
}

/**
 * @brief Set Individual Shutoff Feature Enable
 * 
 * This function modifies the CH_SHUTOFF_EN bit in the CTRL register of the EFTU_DTM controller to enable or disable the channel shut-off feature.
 * 
 * @param pDtm Pointer to the base address of the EFTU_DTM module, used to access the module's registers
 * @param bEnable Boolean value specifying whether to enable the Individual Shutoff Feature Enable. If true, the feature is enabled; if false, it is disabled
 */
LOCAL_INLINE void EFTU_DTM_HWA_SetChannelShutOffEnable(EFTU_DTM_Type * const pDtm, bool bEnable)
{
	pDtm->CTRL = (pDtm->CTRL & (~(uint32_t)EFTU_DTM_CTRL_CH_SHUTOFF_EN_MASK)) | EFTU_DTM_CTRL_CH_SHUTOFF_EN(bEnable);
}

/**
 * @brief Set the shadow register update enable
 * 
 * @param pDtm Base address pointer to the EFTU_DTM controller for accessing its registers
 * @param bEnable Enable flag for shadow register updates, true to enable updates, false to disable updates
 */
LOCAL_INLINE void EFTU_DTM_HWA_SetShadowRegisterUpdateEnable(EFTU_DTM_Type * const pDtm, bool bEnable)
{
	pDtm->CTRL = (pDtm->CTRL & (~(uint32_t)EFTU_DTM_CTRL_SR_UPD_EN_MASK)) | EFTU_DTM_CTRL_SR_UPD_EN(bEnable);
}

/**
 * @brief Shut off reset
 * 
 * @param pDtm Base address pointer to the EFTU_DTM controller for accessing its registers
 */
LOCAL_INLINE void EFTU_DTM_HWA_ShutOffReset(EFTU_DTM_Type * const pDtm)
{
	pDtm->CTRL |= EFTU_DTM_CTRL_SHUT_OFF_RST_MASK;
}

/**
 * @brief Selects the output 1 source for EFTU DTM
 * 
 * @param pDtm Pointer to the base address of the EFTU DTM, used to access its registers
 * @param u8Channel Channel number, used to calculate the position of the control bits
 * @param eSelect Output 1 selection value, specifying the new output source
 */
LOCAL_INLINE void EFTU_DTM_HWA_SelectOutput1(EFTU_DTM_Type * const pDtm, uint8_t u8Channel, EFTU_DTM_Output1SelectType eSelect)
{
	u8Channel = (uint8_t)(u8Channel << 3U);
	pDtm->CH_CTRL1 = (pDtm->CH_CTRL1 & (~(((uint32_t)EFTU_DTM_CH_CTRL1_O1SEL_0_MASK) << u8Channel))) | (EFTU_DTM_CH_CTRL1_O1SEL_0(eSelect) << u8Channel);
}

/**
 * @brief Selects the input 1 for EFTU DTM
 * 
 * @param pDtm Pointer to the base address of the EFTU DTM, used to access DTM registers
 * @param u8Channel Channel number, used to calculate the bit position for the channel control
 * @param eSelect Input 1 selection value, specifying the new input source
 */
LOCAL_INLINE void EFTU_DTM_HWA_SelectInput1(EFTU_DTM_Type * const pDtm, uint8_t u8Channel, EFTU_DTM_Input1SelectType eSelect)
{
	u8Channel = (uint8_t)(u8Channel << 3U);
	pDtm->CH_CTRL1 = (pDtm->CH_CTRL1 & (~(((uint32_t)EFTU_DTM_CH_CTRL1_I1SEL_0_MASK) << u8Channel))) | (EFTU_DTM_CH_CTRL1_I1SEL_0(eSelect) << u8Channel);
}

/**
 * @brief Enable or disable the swap flag for a specific channel
 * 
 * @param pDtm Pointer to the base address of the EFTU_DTM module, used to access the module's registers
 * @param u8Channel Channel number, used to calculate the corresponding bit in the channel control register
 * @param bEnable Boolean value indicating whether to enable the data swap feature
 */
LOCAL_INLINE void EFTU_DTM_HWA_SetSwapEnable(EFTU_DTM_Type * const pDtm, uint8_t u8Channel, bool bEnable)
{
	u8Channel = (uint8_t)(u8Channel << 3U);
	pDtm->CH_CTRL1 = (pDtm->CH_CTRL1 & (~(((uint32_t)EFTU_DTM_CH_CTRL1_SWAP_0_MASK) << u8Channel))) | (EFTU_DTM_CH_CTRL1_SWAP_0(bEnable) << u8Channel);
}

/**
 * @brief Set the output 1 function for a specific channel of the EFTU DTM module
 * 
 * @param pDtm Pointer to the EFTU_DTM_Type structure, representing the base address of the EFTU DTM module
 * @param u8Channel The channel number to configure
 * @param u8Function The output 1 function selection value
 */
LOCAL_INLINE void EFTU_DTM_HWA_SetOutput1Function(EFTU_DTM_Type * const pDtm, uint8_t u8Channel, uint8_t u8Function)
{
	u8Channel = (uint8_t)(u8Channel << 3U);
	pDtm->CH_CTRL1 = (pDtm->CH_CTRL1 & (~(((uint32_t)EFTU_DTM_CH_CTRL1_O1F_0_MASK) << u8Channel))) | (EFTU_DTM_CH_CTRL1_O1F_0(u8Function) << u8Channel);
}

/**
 * @brief Enable or disable cross dead time
 * 
 * @param pDtm Base address pointer of the DTM module
 * @param u8Channel Channel number
 * @param bEnable True to enable cross dead time, false to disable
 */
LOCAL_INLINE void EFTU_DTM_HWA_SetCrossDeadTimeEnable(EFTU_DTM_Type * const pDtm, uint8_t u8Channel, bool bEnable)
{
    u8Channel = ((u8Channel & 0x2) << 3U);
    pDtm->CH_CTRL1 = (pDtm->CH_CTRL1 & (~(((uint32_t)EFTU_DTM_CH_CTRL1_XDT_EN_0_1_MASK) << u8Channel))) | (EFTU_DTM_CH_CTRL1_XDT_EN_0_1(bEnable) << u8Channel);
}

/**
 * @brief Enable or disable shift function
 * 
 * @param pDtm Base address pointer of the DTM module
 * @param u8Channel Channel number, supports only channel 1
 * @param bEnable True to enable shift function, false to disable
 */
LOCAL_INLINE void EFTU_DTM_HWA_SetShiftEnable(EFTU_DTM_Type * const pDtm, uint8_t u8Channel, bool bEnable)
{
    u8Channel = (uint8_t)((u8Channel - 1U) << 3U);
    pDtm->CH_CTRL1 = (pDtm->CH_CTRL1 & (~(((uint32_t)EFTU_DTM_CH_CTRL1_SH_EN_1_MASK) << u8Channel))) | (EFTU_DTM_CH_CTRL1_SH_EN_1(bEnable) << u8Channel);
}

/**
 * @brief Invert output 0 polarity
 *  
 * @param pDtm Base address pointer of the DTM module
 * @param u8Channel Channel number
 * @param bInvert True to invert the polarity of output 0, false to not invert
 */
LOCAL_INLINE void EFTU_DTM_HWA_InvertOutput0(EFTU_DTM_Type * const pDtm, uint8_t u8Channel, bool bInvert)
{
    u8Channel = (uint8_t)(u8Channel << 3U);
    pDtm->CH_CTRL2 = (pDtm->CH_CTRL2 & (~(((uint32_t)EFTU_DTM_CH_CTRL2_POL0_0_MASK) << u8Channel))) | (EFTU_DTM_CH_CTRL2_POL0_0(bInvert) << u8Channel);
}

/**
 * @brief Set output 0 control mode
 * 
 * @param pDtm Base address pointer of the DTM module
 * @param u8Channel Channel number
 * @param eCtrl Control mode for output 0
 */
LOCAL_INLINE void EFTU_DTM_HWA_SetOutput0Ctrl(EFTU_DTM_Type * const pDtm, uint8_t u8Channel, EFTU_DTM_Output0ControlType eCtrl)
{
    u8Channel = (uint8_t)(u8Channel << 3U);
    pDtm->CH_CTRL2 = (pDtm->CH_CTRL2 & (~(((uint32_t)EFTU_DTM_CH_CTRL2_OC0_0_MASK) << u8Channel))) | (EFTU_DTM_CH_CTRL2_OC0_0(eCtrl) << u8Channel);
}

/**
 * @brief Set output 0 signal level
 * 
 * @param pDtm Base address pointer of the DTM module
 * @param u8Channel Channel number
 * @param eLevel Signal level for output 0
 */
LOCAL_INLINE void EFTU_DTM_HWA_SetOutput0SignalLevel(EFTU_DTM_Type * const pDtm, uint8_t u8Channel, EFTU_DTM_SignalLevelType eLevel)
{
    u8Channel = (uint8_t)(u8Channel << 3U);
    pDtm->CH_CTRL2 = (pDtm->CH_CTRL2 & (~(((uint32_t)EFTU_DTM_CH_CTRL2_SL0_0_MASK) << u8Channel))) | (EFTU_DTM_CH_CTRL2_SL0_0(eLevel) << u8Channel);
}

/**
 * @brief Enable or disable dead time 0
 * 
 * @param pDtm Base address pointer of the DTM module
 * @param u8Channel Channel number
 * @param bEnable True to enable dead time 0, false to disable
 */
LOCAL_INLINE void EFTU_DTM_HWA_SetDeadTime0Enable(EFTU_DTM_Type * const pDtm, uint8_t u8Channel, bool bEnable)
{
    u8Channel = (uint8_t)(u8Channel << 3U);
    pDtm->CH_CTRL2 = (pDtm->CH_CTRL2 & (~(((uint32_t)EFTU_DTM_CH_CTRL2_DT0_0_MASK) << u8Channel))) | (EFTU_DTM_CH_CTRL2_DT0_0(bEnable) << u8Channel);
}

/**
 * @brief Inverts the output polarity of a specified channel.
 * 
 * @param pDtm Pointer to the EFTU DTM module register base.
 * @param u8Channel The channel number, indicating which channel's output polarity to invert.
 * @param bInvert A boolean value, true to invert the output polarity, false to keep it unchanged.
 */
LOCAL_INLINE void EFTU_DTM_HWA_InvertOutput1(EFTU_DTM_Type * const pDtm, uint8_t u8Channel, bool bInvert)
{
    u8Channel = (uint8_t)(u8Channel << 3U);
    pDtm->CH_CTRL2 = (pDtm->CH_CTRL2 & (~(((uint32_t)EFTU_DTM_CH_CTRL2_POL1_0_MASK) << u8Channel))) | (EFTU_DTM_CH_CTRL2_POL1_0(bInvert) << u8Channel);
}

/**
 * @brief Sets the control mode for output 1 of a specified channel.
 * 
 * @param pDtm Pointer to the EFTU DTM module register base.
 * @param u8Channel The channel number, indicating which channel's output 1 control mode to set.
 * @param eCtrl The control mode for output 1, specifying how the output should be controlled.
 */
LOCAL_INLINE void EFTU_DTM_HWA_SetOutput1Ctrl(EFTU_DTM_Type * const pDtm, uint8_t u8Channel, EFTU_DTM_Output0ControlType eCtrl)
{
    u8Channel = (uint8_t)(u8Channel << 3U);
    pDtm->CH_CTRL2 = (pDtm->CH_CTRL2 & (~(((uint32_t)EFTU_DTM_CH_CTRL2_OC1_0_MASK) << u8Channel))) | (EFTU_DTM_CH_CTRL2_OC1_0(eCtrl) << u8Channel);
}

/**
 * @brief Sets the signal level for output 1 of a specified channel.
 * 
 * @param pDtm Pointer to the EFTU DTM module register base.
 * @param u8Channel The channel number, indicating which channel's output 1 signal level to set.
 * @param eLevel The signal level for output 1, specifying the output signal level.
 */
LOCAL_INLINE void EFTU_DTM_HWA_SetOutput1SignalLevel(EFTU_DTM_Type * const pDtm, uint8_t u8Channel, EFTU_DTM_SignalLevelType eLevel)
{
    u8Channel = (uint8_t)(u8Channel << 3U);
    pDtm->CH_CTRL2 = (pDtm->CH_CTRL2 & (~(((uint32_t)EFTU_DTM_CH_CTRL2_SL1_0_MASK) << u8Channel))) | (EFTU_DTM_CH_CTRL2_SL1_0(eLevel) << u8Channel);
}

/**
 * @brief Enables or disables dead time insertion for output 1 of a specified channel.
 * 
 * @param pDtm Pointer to the EFTU DTM module register base.
 * @param u8Channel The channel number, indicating which channel's output 1 dead time insertion to control.
 * @param bEnable A boolean value, true to enable dead time insertion, false to disable it.
 */
LOCAL_INLINE void EFTU_DTM_HWA_SetDeadTime1Enable(EFTU_DTM_Type * const pDtm, uint8_t u8Channel, bool bEnable)
{
    u8Channel = (uint8_t)(u8Channel << 3U);
    pDtm->CH_CTRL2 = (pDtm->CH_CTRL2 & (~(((uint32_t)EFTU_DTM_CH_CTRL2_DT1_0_MASK) << u8Channel))) | (EFTU_DTM_CH_CTRL2_DT1_0(bEnable) << u8Channel);
}

/**
 * @brief Set the value of the Channel Control 2 register
 * 
 * @param pDtm Base address pointer of the EFTU_DTM module
 * @param u32Value Value to be written to the CH_CTRL2 register
 */
LOCAL_INLINE void EFTU_DTM_HWA_SetCHCTRL2(EFTU_DTM_Type * const pDtm, uint32_t u32Value)
{
    pDtm->CH_CTRL2 = u32Value;
}

/**
 * @brief Get the value of the Channel Control 2 register
 * 
 * @param pDtm Base address pointer of the EFTU_DTM module
 * @return uint32_t Current value of the CH_CTRL2 register
 */
LOCAL_INLINE uint32_t EFTU_DTM_HWA_GetCHCTRL2(EFTU_DTM_Type * const pDtm)
{
    return pDtm->CH_CTRL2;
}

/**
 * @brief Invert the polarity of Output 0
 * 
 * @param pDtm Base address pointer of the EFTU_DTM module
 * @param u8Channel Channel number
 * @param bInvert Whether to invert the output polarity, true for inversion, false for no inversion
 */
LOCAL_INLINE void EFTU_DTM_HWA_InvertOutput0Shadow(EFTU_DTM_Type * const pDtm, uint8_t u8Channel, bool bInvert)
{
    u8Channel = (uint8_t)(u8Channel << 3U);
    pDtm->CH_CTRL2_SR = (pDtm->CH_CTRL2_SR & (~(((uint32_t)EFTU_DTM_CH_CTRL2_SR_POL0_0_SR_MASK) << u8Channel))) | (EFTU_DTM_CH_CTRL2_SR_POL0_0_SR(bInvert) << u8Channel);
}

/**
 * @brief Set the control mode of Output 0
 * 
 * @param pDtm Base address pointer of the EFTU_DTM module
 * @param u8Channel Channel number
 * @param eCtrl Control mode of Output 0
 */
LOCAL_INLINE void EFTU_DTM_HWA_SetOutput0CtrlShadow(EFTU_DTM_Type * const pDtm, uint8_t u8Channel, EFTU_DTM_Output0ControlType eCtrl)
{
    u8Channel = (uint8_t)(u8Channel << 3U);
    pDtm->CH_CTRL2_SR = (pDtm->CH_CTRL2_SR & (~(((uint32_t)EFTU_DTM_CH_CTRL2_SR_OC0_0_SR_MASK) << u8Channel))) | (EFTU_DTM_CH_CTRL2_SR_OC0_0_SR(eCtrl) << u8Channel);
}

/**
 * @brief Set the signal level of Output 0
 * 
 * @param pDtm Base address pointer of the EFTU_DTM module
 * @param u8Channel Channel number
 * @param eLevel Signal level of Output 0
 */
LOCAL_INLINE void EFTU_DTM_HWA_SetOutput0SignalLevelShadow(EFTU_DTM_Type * const pDtm, uint8_t u8Channel, EFTU_DTM_SignalLevelType eLevel)
{
    u8Channel = (uint8_t)(u8Channel << 3U);
    pDtm->CH_CTRL2_SR = (pDtm->CH_CTRL2_SR & (~(((uint32_t)EFTU_DTM_CH_CTRL2_SR_SL0_0_SR_MASK) << u8Channel))) | (EFTU_DTM_CH_CTRL2_SR_SL0_0_SR(eLevel) << u8Channel);
}

/**
 * @brief Set the enable state of Dead Time 0
 * 
 * @param pDtm Base address pointer of the EFTU_DTM module
 * @param u8Channel Channel number
 * @param bEnable Enable state of Dead Time 0, true for enabled, false for disabled
 */
LOCAL_INLINE void EFTU_DTM_HWA_SetDeadTime0EnableShadow(EFTU_DTM_Type * const pDtm, uint8_t u8Channel, bool bEnable)
{
    u8Channel = (uint8_t)(u8Channel << 3U);
    pDtm->CH_CTRL2_SR = (pDtm->CH_CTRL2_SR & (~(((uint32_t)EFTU_DTM_CH_CTRL2_SR_DT0_0_SR_MASK) << u8Channel))) | (EFTU_DTM_CH_CTRL2_SR_DT0_0_SR(bEnable) << u8Channel);
}

/**
 * @brief Invert the polarity of Output 1
 * 
 * @param pDtm Base address pointer of the EFTU_DTM module
 * @param u8Channel Channel number
 * @param bInvert Whether to invert the output polarity, true for inversion, false for no inversion
 */
LOCAL_INLINE void EFTU_DTM_HWA_InvertOutput1Shadow(EFTU_DTM_Type * const pDtm, uint8_t u8Channel, bool bInvert)
{
    u8Channel = (uint8_t)(u8Channel << 3U);
    pDtm->CH_CTRL2_SR = (pDtm->CH_CTRL2_SR & (~(((uint32_t)EFTU_DTM_CH_CTRL2_SR_POL1_0_SR_MASK) << u8Channel))) | (EFTU_DTM_CH_CTRL2_SR_POL1_0_SR(bInvert) << u8Channel);
}

/**
 * @brief Set the output 1 control shadow register for a DTM channel
 * 
 * This function sets the output 1 control shadow register (CH_CTRL2_SR) bits for a specific DTM channel,
 * controlling the behavior of the output signal.
 * 
 * @param pDtm Pointer to the base address of the DTM module
 * @param u8Channel Channel number to select the specific DTM channel
 * @param eCtrl Output control selection, specifying the behavior of the output signal
 */
LOCAL_INLINE void EFTU_DTM_HWA_SetOutput1CtrlShadow(EFTU_DTM_Type * const pDtm, uint8_t u8Channel, EFTU_DTM_Output0ControlType eCtrl)
{
    u8Channel = (uint8_t)(u8Channel << 3U);
    pDtm->CH_CTRL2_SR = (pDtm->CH_CTRL2_SR & (~(((uint32_t)EFTU_DTM_CH_CTRL2_SR_OC1_0_SR_MASK) << u8Channel))) | (EFTU_DTM_CH_CTRL2_SR_OC1_0_SR(eCtrl) << u8Channel);
}

/**
 * @brief Set the output 1 signal level shadow register for a DTM channel
 * 
 * This function sets the output 1 signal level shadow register (CH_CTRL2_SR) bits for a specific DTM channel,
 * defining the signal level of the output.
 * 
 * @param pDtm Pointer to the base address of the DTM module
 * @param u8Channel Channel number to select the specific DTM channel
 * @param eLevel Signal level selection, specifying the level of the output signal
 */
LOCAL_INLINE void EFTU_DTM_HWA_SetOutput1SignalLevelShadow(EFTU_DTM_Type * const pDtm, uint8_t u8Channel, EFTU_DTM_SignalLevelType eLevel)
{
    u8Channel = (uint8_t)(u8Channel << 3U);
    pDtm->CH_CTRL2_SR = (pDtm->CH_CTRL2_SR & (~(((uint32_t)EFTU_DTM_CH_CTRL2_SR_SL1_0_SR_MASK) << u8Channel))) | (EFTU_DTM_CH_CTRL2_SR_SL1_0_SR(eLevel) << u8Channel);
}

/**
 * @brief Set the dead time 1 enable shadow register for a DTM channel
 * 
 * @param pDtm Pointer to the base address of the DTM module
 * @param u8Channel Channel number to select the specific DTM channel
 * @param bEnable Dead time enable selection, true to enable, false to disable
 */
LOCAL_INLINE void EFTU_DTM_HWA_SetDeadTime1EnableShadow(EFTU_DTM_Type * const pDtm, uint8_t u8Channel, bool bEnable)
{
    u8Channel = (uint8_t)(u8Channel << 3U);
    pDtm->CH_CTRL2_SR = (pDtm->CH_CTRL2_SR & (~(((uint32_t)EFTU_DTM_CH_CTRL2_SR_DT1_0_SR_MASK) << u8Channel))) | (EFTU_DTM_CH_CTRL2_SR_DT1_0_SR(bEnable) << u8Channel);
}

/**
 * @brief Directly set the CH_CTRL2_SR register value for a DTM channel
 * 
 * @param pDtm Pointer to the base address of the DTM module
 * @param u32Value Value to set the CH_CTRL2_SR register
 */
LOCAL_INLINE void EFTU_DTM_HWA_SetCTRL2SR(EFTU_DTM_Type * const pDtm, uint32_t u32Value)
{
    pDtm->CH_CTRL2_SR = u32Value;
}

/**
 * @brief Get the CH_CTRL2_SR register value for a DTM channel
 * 
 * @param pDtm Pointer to the base address of the DTM module
 * @return uint32_t Value of the CH_CTRL2_SR register
 */
LOCAL_INLINE uint32_t EFTU_DTM_HWA_GetCTRL2SR(EFTU_DTM_Type * const pDtm)
{
    return pDtm->CH_CTRL2_SR;
}

/**
 * @brief Set the polarity of the comb input signal for a DTM channel
 * 
 * @param pDtm Pointer to the base address of the DTM module
 * @param u8Channel Channel number to select the specific DTM channel
 * @param bInvert Polarity selection, true to invert, false to not invert
 */
LOCAL_INLINE void EFTU_DTM_InvertCombInput(EFTU_DTM_Type * const pDtm, uint8_t u8Channel, bool bInvert)
{
    u8Channel = (uint8_t)(u8Channel << 3U);
    pDtm->CH_CTRL3 = (pDtm->CH_CTRL3 & (~(((uint32_t)EFTU_DTM_CH_CTRL3_CII0_MASK) << u8Channel))) | (EFTU_DTM_CH_CTRL3_CII0(bInvert) << u8Channel);
}

/**
 * @brief Select the comb input signal source for a DTM channel
 * 
 * @param pDtm Pointer to the base address of the DTM module
 * @param u8Channel Channel number to select the specific DTM channel
 * @param eSelect Signal source selection, specifying the input signal to use
 */
LOCAL_INLINE void EFTU_DTM_SelectCombInput(EFTU_DTM_Type * const pDtm, uint8_t u8Channel, EFTU_DTM_CombInputSelectType eSelect)
{
    u8Channel = (uint8_t)(u8Channel << 3U);
    pDtm->CH_CTRL3 = (pDtm->CH_CTRL3 & (~(((uint32_t)EFTU_DTM_CH_CTRL3_CIS0_MASK) << u8Channel))) | (EFTU_DTM_CH_CTRL3_CIS0(eSelect) << u8Channel);
}

/**
 * @brief Select the edge trigger source for a DTM channel
 * 
 * @param pDtm Pointer to the base address of the DTM module
 * @param u8Channel Channel number to select the specific DTM channel
 * @param eSelect Trigger source selection, specifying the source of the trigger event
 */
LOCAL_INLINE void EFTU_DTM_SelectEdgeTrigGen(EFTU_DTM_Type * const pDtm, uint8_t u8Channel, EFTU_DTM_EdgeTrigSelectType eSelect)
{
    u8Channel = (uint8_t)(u8Channel << 3U);
    pDtm->CH_CTRL3 = (pDtm->CH_CTRL3 & (~(((uint32_t)EFTU_DTM_CH_CTRL3_TSEL0_0_MASK) << u8Channel))) | (EFTU_DTM_CH_CTRL3_TSEL0_0(eSelect) << u8Channel);
}

/**
 * @brief Select the comb input logic path for a DTM channel
 * 
 * @param pDtm Pointer to the base address of the DTM module
 * @param u8Channel Channel number to select the specific DTM channel
 * @param eSelect Logic path selection, specifying the logical processing of the input signal
 */
LOCAL_INLINE void EFTU_DTM_SelectCombInputLogicPath(EFTU_DTM_Type * const pDtm, uint8_t u8Channel, EFTU_DTM_CombInputLogicPathSelectType eSelect)
{
    u8Channel = (uint8_t)(u8Channel << 3U);
    pDtm->CH_CTRL3 = (pDtm->CH_CTRL3 & (~(((uint32_t)EFTU_DTM_CH_CTRL3_TSEL1_0_MASK) << u8Channel))) | (EFTU_DTM_CH_CTRL3_TSEL1_0(eSelect) << u8Channel);
}

/**
 * @brief Set the reload value for the DTM
 * 
 * @param pDtm Pointer to the base address of the DTM module
 * @param u16RelBlk Reload value, specifying the reload value of the counter
 */
LOCAL_INLINE void EFTU_DTM_HWA_SetReloadValueBlkWin(EFTU_DTM_Type * const pDtm, uint16_t u16RelBlk)
{
    pDtm->PS_CTRL = (pDtm->PS_CTRL & (~(uint32_t)EFTU_DTM_PS_CTRL_RELBLK_MASK)) | EFTU_DTM_PS_CTRL_RELBLK(u16RelBlk);
}

/**
 * @brief Select the power supply input source for the DTM
 * 
 * @param pDtm Pointer to the base address of the DTM module
 * @param eSelection Power supply input source selection, specifying the power supply input to use
 */
LOCAL_INLINE void EFTU_DTM_HWA_SelectPsuInput(EFTU_DTM_Type * const pDtm, EFTU_DTM_PsuInputSelectType eSelection)
{
    pDtm->PS_CTRL = (pDtm->PS_CTRL & (~(uint32_t)EFTU_DTM_PS_CTRL_PSU_IN_SEL_MASK)) | EFTU_DTM_PS_CTRL_PSU_IN_SEL(eSelection);
}

/**
 * @brief Inverts the input polarity
 * 
 * @param pDtm Base address pointer of the EFTU DTM
 * @param bInvert Whether to invert the input polarity, true for inversion, false for no inversion
 */
LOCAL_INLINE void EFTU_DTM_InvertInputPolarity(EFTU_DTM_Type * const pDtm, bool bInvert)
{
    pDtm->PS_CTRL = (pDtm->PS_CTRL & (~(uint32_t)EFTU_DTM_PS_CTRL_IN_POL_MASK)) | EFTU_DTM_PS_CTRL_IN_POL(bInvert);
}

/**
 * @brief Selects the timer input
 * 
 * @param pDtm Base address pointer of the EFTU DTM
 * @param eSelect Timer input selection parameter, see EFTU_DTM_TimInputSelectType definition
 */
LOCAL_INLINE void EFTU_DTM_HWA_SelectTimInput(EFTU_DTM_Type * const pDtm, EFTU_DTM_TimInputSelectType eSelect)
{
    pDtm->PS_CTRL = (pDtm->PS_CTRL & (~(uint32_t)EFTU_DTM_PS_CTRL_TIM_SEL_MASK)) | EFTU_DTM_PS_CTRL_TIM_SEL(eSelect);
}

/**
 * @brief Selects the shift operation
 * 
 * @param pDtm Base address pointer of the EFTU DTM
 * @param eSelect Shift selection parameter, see EFTU_DTM_ShiftSelectType definition
 */
LOCAL_INLINE void EFTU_DTM_HWA_SelectShift(EFTU_DTM_Type * const pDtm, EFTU_DTM_ShiftSelectType eSelect)
{
    pDtm->PS_CTRL = (pDtm->PS_CTRL & (~(uint32_t)EFTU_DTM_PS_CTRL_SHIFT_SEL_MASK)) | EFTU_DTM_PS_CTRL_SHIFT_SEL(eSelect);
}

/**
 * @brief Sets the rising edge dead time
 * 
 * @param pDtm Base address pointer of the EFTU DTM
 * @param u8Channel Channel number
 * @param u16DeadTime Dead time value
 */
LOCAL_INLINE void EFTU_DTM_HWA_SetRisingEdgeDeadTime(EFTU_DTM_Type * const pDtm, uint8_t u8Channel, uint16_t u16DeadTime)
{
    pDtm->CHn_DTV[u8Channel] = (pDtm->CHn_DTV[u8Channel] & (~(uint32_t)EFTU_DTM_CHn_DTV_DT_RISE_MASK)) | EFTU_DTM_CHn_DTV_DT_RISE(u16DeadTime);
}

/**
 * @brief Sets the falling edge dead time
 * 
 * @param pDtm Base address pointer of the EFTU DTM
 * @param u8Channel Channel number
 * @param u16DeadTime Dead time value
 */
LOCAL_INLINE void EFTU_DTM_HWA_SetFallingEdgeDeadTime(EFTU_DTM_Type * const pDtm, uint8_t u8Channel, uint16_t u16DeadTime)
{
    pDtm->CHn_DTV[u8Channel] = (pDtm->CHn_DTV[u8Channel] & (~(uint32_t)EFTU_DTM_CHn_DTV_DT_FALL_MASK)) | EFTU_DTM_CHn_DTV_DT_FALL(u16DeadTime);
}
#if defined(HRPWM_INSTANCE_COUNT) && (HRPWM_INSTANCE_COUNT > 0U)
/**
 * @brief Sets the HRPWM mode
 * 
 * @param pDtm Base address pointer of the EFTU DTM
 * @param u8Channel Channel number
 * @param bEnable Whether to enable HRPWM mode, true for enable, false for disable
 */
LOCAL_INLINE void EFTU_DTM_SetHRPWM(EFTU_DTM_Type * const pDtm, uint8_t u8Channel, bool bEnable)
{
    pDtm->CHn_DTV[u8Channel] = (pDtm->CHn_DTV[u8Channel] & (~(uint32_t)EFTU_DTM_CHn_DTV_HRES_MASK)) | EFTU_DTM_CHn_DTV_HRES(bEnable);
}
#endif
/**
 * @brief Sets the output 0 signal level
 * 
 * @param pDtm Base address pointer of the EFTU DTM
 * @param u8Channel Channel number
 * @param eLevel Signal level, see EFTU_DTM_SignalLevelType definition
 */
LOCAL_INLINE void EFTU_DTM_HWA_SetOutput0SignalLevelShadowShadow(EFTU_DTM_Type * const pDtm, uint8_t u8Channel, EFTU_DTM_SignalLevelType eLevel)
{
    u8Channel = (uint8_t)(u8Channel << 1U);
    pDtm->CH_CTRL2_SR = (pDtm->CH_CTRL2_SR & (~(((uint32_t)EFTU_DTM_CH_SR_SL0_0_SR_SR_MASK) << u8Channel))) | (EFTU_DTM_CH_SR_SL0_0_SR_SR(eLevel) << u8Channel);
}

/**
 * @brief Sets the output 1 signal level
 * 
 * @param pDtm Base address pointer of the EFTU DTM
 * @param u8Channel Channel number
 * @param eLevel Signal level, see EFTU_DTM_SignalLevelType definition
 */
LOCAL_INLINE void EFTU_DTM_HWA_SetOutput1SignalLevelShadowShadow(EFTU_DTM_Type * const pDtm, uint8_t u8Channel, EFTU_DTM_SignalLevelType eLevel)
{
    u8Channel = (uint8_t)(u8Channel << 1U);
    pDtm->CH_CTRL2_SR = (pDtm->CH_CTRL2_SR & (~(((uint32_t)EFTU_DTM_CH_SR_SL1_0_SR_SR_MASK) << u8Channel))) | (EFTU_DTM_CH_SR_SL1_0_SR_SR(eLevel) << u8Channel);
}

/**
 * @brief Selects the shut-off signal
 * 
 * @param pDtm Base address pointer of the EFTU DTM
 * @param u8Channel Channel number
 * @param eSignal Shut-off signal selection parameter, see EFTU_DTM_ShutOffSignalType definition
 */
LOCAL_INLINE void EFTU_DTM_HWA_SelectShutOffSignal(EFTU_DTM_Type * const pDtm, uint8_t u8Channel, EFTU_DTM_ShutOffSignalType eSignal)
{
    u8Channel = (uint8_t)(u8Channel << 3U);
    pDtm->CTRL2 = (pDtm->CTRL2 & (~(((uint32_t)EFTU_DTM_CTRL2_SHUTOFF_SEL_0_MASK) << u8Channel))) | (EFTU_DTM_CTRL2_SHUTOFF_SEL_0(eSignal) << u8Channel);
}

/**
 * @brief Inverts the shut-off signal
 * 
 * @param pDtm Base address pointer of the EFTU DTM
 * @param u8Channel Channel number
 * @param bInvert Whether to invert the shut-off signal polarity, true for inversion, false for no inversion
 */
LOCAL_INLINE void EFTU_DTM_HWA_InvertShutOffSignal(EFTU_DTM_Type * const pDtm, uint8_t u8Channel, bool bInvert)
{
    u8Channel = (uint8_t)(u8Channel << 3U);
    pDtm->CTRL2 = (pDtm->CTRL2 & (~(((uint32_t)EFTU_DTM_CTRL2_SHUTOFF_POL_0_MASK) << u8Channel))) | (EFTU_DTM_CTRL2_SHUTOFF_POL_0(bInvert) << u8Channel);
}

/**
 * @brief Sets the update mode of the internal SHUTOFF_SYNC_N signal
 * 
 * @param pDtm Base address pointer of the EFTU DTM
 * @param u8Channel Channel number
 * @param u8UpdateMode Update mode value
 *                      00b - Internal signal SHUTOFF_SYNC_0 is cleared; a set is not possible
 *                      01b - Signal PSU_SHUT_OFF[0] sets internal signal SHUTOFF_SYNC_0;
 *                            internal signal SHUTOFF_SYNC_0 is cleared depending on bit field
 *                            CTRL2[SHUT_OFF_RST_0]
 *                      10b - Signal PSU_SHUT_OFF[0] sets internal signal SHUTOFF_SYNC_0;
 *                            internal signal SHUTOFF_SYNC_0 is cleared by signal
 *                            DTM_PREV_IN0_REDGE or DTM_PREV_IN0_FEDGE or DTM_IN_REDGE
 *                            of channel 0 or DTM_IN_FEDGE of channel 0 defined by bit field
 *                            CTRL[DTM_SEL]
 *                      11b - Signal PSU_SHUT_OFF[0] =1 sets internal signal
 *                            SHUTOFF_SYNC_0; signal PSU_SHUT_OFF[0] =0 clears internal signal
 *                            SHUTOFF_SYNC_0
 */
LOCAL_INLINE void EFTU_DTM_HWA_SetShutOffSyncUpdateMode(EFTU_DTM_Type * const pDtm, uint8_t u8Channel, uint8_t u8UpdateMode)
{
    u8Channel = (uint8_t)(u8Channel << 3U);
    pDtm->CTRL2 = (pDtm->CTRL2 & (~(((uint32_t)EFTU_DTM_CTRL2_UPD_MODE_0_MASK) << u8Channel))) | (EFTU_DTM_CTRL2_UPD_MODE_0(u8UpdateMode) << u8Channel);
}

/**
 * @brief Clear of internal signal SHUTOFF_SYNC_
 * 
 * @param pDtm Base address pointer of the EFTU DTM
 * @param u8Channel Channel number
 */
LOCAL_INLINE void EFTU_DTM_HWA_ResetShutOffSync(EFTU_DTM_Type * const pDtm, uint8_t u8Channel)
{
    pDtm->CTRL2 |= (EFTU_DTM_CTRL2_WR_EN_0_MASK | EFTU_DTM_CTRL2_SHUT_OFF_RST_0_MASK) << (u8Channel << 3U);
}

/**
 * @brief Sets the write enable
 * 
 * @param pDtm Base address pointer of the EFTU DTM
 * @param u8Channel Channel number
 * @param bEnable Whether to enable write operations, true for enable, false for disable
 */
LOCAL_INLINE void EFTU_DTM_HWA_SetWriteEnable(EFTU_DTM_Type * const pDtm, uint8_t u8Channel, bool bEnable)
{
    u8Channel = (uint8_t)(u8Channel << 3U);
    pDtm->CTRL2 = (pDtm->CTRL2 & (~(((uint32_t)EFTU_DTM_CTRL2_WR_EN_0_MASK) << u8Channel))) | (EFTU_DTM_CTRL2_WR_EN_0(bEnable) << u8Channel);
}

/**
 * @brief Sets the CTRL2 register value
 * 
 * @param pDtm Base address pointer of the EFTU DTM
 * @param u32Value Value to set for the CTRL2 register
 */
LOCAL_INLINE void EFTU_DTM_HWA_SetCTRL2(EFTU_DTM_Type * const pDtm, uint32_t u32Value)
{
    pDtm->CTRL2 = u32Value;
}

/**
 * @brief Gets the CTRL2 register value
 * 
 * @param pDtm Base address pointer of the EFTU DTM
 * @return The value of the CTRL2 register
 */
LOCAL_INLINE uint32_t EFTU_DTM_HWA_GetCTRL2(EFTU_DTM_Type * const pDtm)
{
    return pDtm->CTRL2;
}

/**
 * @brief Sets the Shadow value for rising edge dead time
 * 
 * @param pDtm Base address pointer of the EFTU DTM
 * @param u8Channel Channel number
 * @param u16DeadTime Dead time value
 */
LOCAL_INLINE void EFTU_DTM_HWA_SetRisingEdgeDeadTimeShadow(EFTU_DTM_Type * const pDtm, uint8_t u8Channel, uint16_t u16DeadTime)
{
    pDtm->CHn_DTV_SR[u8Channel] = (pDtm->CHn_DTV_SR[u8Channel] & (~(uint32_t)EFTU_DTM_CHn_DTV_SR_DT_RISE_SR_MASK)) | EFTU_DTM_CHn_DTV_SR_DT_RISE_SR(u16DeadTime);
}

/**
 * @brief Selects the rising dead time trigger
 * 
 * @param pDtm Base address pointer of the EFTU DTM
 * @param u8Channel Channel number
 * @param eSelect Trigger selection parameter, see EFTU_DTM_DeadTimeTrigSelectType definition
 */
LOCAL_INLINE void EFTU_DTM_HWA_SelectRisingDeadTimeTrigger(EFTU_DTM_Type * const pDtm, uint8_t u8Channel, EFTU_DTM_DeadTimeTrigSelectType eSelect)
{
    pDtm->CHn_DTV_SR[u8Channel] = (pDtm->CHn_DTV_SR[u8Channel] & (~(uint32_t)EFTU_DTM_CHn_DTV_SR_DT_RISE_UPD_FE0RE1_MASK)) | EFTU_DTM_CHn_DTV_SR_DT_RISE_UPD_FE0RE1(eSelect);
}

/**
 * @brief Sets the update rising dead time enable
 * 
 * @param pDtm Base address pointer of the EFTU DTM
 * @param u8Channel Channel number
 * @param bEnable Whether to enable the update, true for enable, false for disable
 */
LOCAL_INLINE void EFTU_DTM_HWA_SetUpdateRisingDeadTimeEnable(EFTU_DTM_Type * const pDtm, uint8_t u8Channel, bool bEnable)
{
    pDtm->CHn_DTV_SR[u8Channel] = (pDtm->CHn_DTV_SR[u8Channel] & (~(uint32_t)EFTU_DTM_CHn_DTV_SR_DT_RISE_UPD_EN_MASK)) | EFTU_DTM_CHn_DTV_SR_DT_RISE_UPD_EN(bEnable);
}

/**
 * @brief Sets the Shadow Value for Falling Edge Dead Time
 * 
 * @param pDtm Base address pointer of the EFTU DTM
 * @param u8Channel Channel number
 * @param u16DeadTime Dead time value
 */
LOCAL_INLINE void EFTU_DTM_HWA_SetFallingEdgeDeadTimeShadow(EFTU_DTM_Type * const pDtm, uint8_t u8Channel, uint16_t u16DeadTime)
{
	pDtm->CHn_DTV_SR[u8Channel] = (pDtm->CHn_DTV_SR[u8Channel] & (~(uint32_t)EFTU_DTM_CHn_DTV_SR_DT_FALL_SR_MASK)) | EFTU_DTM_CHn_DTV_SR_DT_FALL_SR(u16DeadTime);
}

/**
 * @brief Select the falling edge dead time trigger
 * 
 * @param pDtm Pointer to the base address of the DTM module
 * @param u8Channel Channel number
 * @param eSelect Trigger selection enum value
 */
LOCAL_INLINE void EFTU_DTM_HWA_SelectFallingDeadTimeTrigger(EFTU_DTM_Type * const pDtm, uint8_t u8Channel, EFTU_DTM_DeadTimeTrigSelectType eSelect)
{
    pDtm->CHn_DTV_SR[u8Channel] = (pDtm->CHn_DTV_SR[u8Channel] & (~(uint32_t)EFTU_DTM_CHn_DTV_SR_DT_FALL_UPD_FE0RE1_MASK)) | EFTU_DTM_CHn_DTV_SR_DT_FALL_UPD_FE0RE1(eSelect);
}

/**
 * @brief Set the update enable for falling edge dead time
 * 
 * @param pDtm Pointer to the base address of the DTM module
 * @param u8Channel Channel number
 * @param bEnable Boolean value to enable or disable the update
 */
LOCAL_INLINE void EFTU_DTM_HWA_SetUpdateFallingDeadTimeEnable(EFTU_DTM_Type * const pDtm, uint8_t u8Channel, bool bEnable)
{
    pDtm->CHn_DTV_SR[u8Channel] = (pDtm->CHn_DTV_SR[u8Channel] & (~(uint32_t)EFTU_DTM_CHn_DTV_SR_DT_FALL_UPD_EN_MASK)) | EFTU_DTM_CHn_DTV_SR_DT_FALL_UPD_EN(bEnable);
}
/** @}*/
#endif  /* EFTU_INSTANCE_COUNT > 0U */
#endif  /* _HWA_EFTU_ATM_H_ */
