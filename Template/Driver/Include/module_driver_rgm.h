/**
 * @file module_driver_rgm.h
 * @author Flagchip
 * @brief RGM driver type definition and API
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
   *   0.1.0       2023-12-15    Flagchip074   N/A          First version for FC7300
   *   2.0.0       2024-10-12    Flagchip074   N/A          Change version and release
   ******************************************************************************** */
#ifndef _DRIVER_MODULE_DRIVER_RGM_H_
#define _DRIVER_MODULE_DRIVER_RGM_H_

#include "HwA_rgm.h"

#if RGM_INSTANCE_COUNT > 0U

/**
 * @addtogroup module_driver_rgm
 * @{
 */

/**
 * @name  RGM API Service IDs
 *
 * @{
 */
#define RGM_INIT_ID              0x00U
/** @}*/

/**
 * @name  RGM Dev Error Code
 * @brief Error Code of calling RGM apis
 *
 * @{
 */
#define RGM_E_PARAM_DELAY_TIME            0x01U
#define RGM_E_PARAM_POINTER               0x02U

/** @}*/

/** @brief Rgm return type. */
typedef enum
{
    RGM_STATUS_SUCCESS = 0U,          /**< Return status success */
    RGM_STATUS_PARAM_INVALID  = 1U,   /**< Return status parameter invalid */
    RGM_STATUS_COREID_INVALID = 2U,   /**< Return status core id invalid */
    RGM_STATUS_CLOCK_INVALID          /**< Return status clock invalid */
} RGM_StatusType;

/** @brief Rgm reset pin filter clock type. */
typedef enum
{
    RGM_RESET_FILTER_DISABLE   = 0U, /**< Reset Pin Filter Disable */
    RGM_RESET_FILTER_BUS_CLOCK = 1U  /**< Reset Pin Filter Bus Clock */
} RGM_FilterClkSrc;

/**
 * @brief The structure of the SCG processing handle
 *
 */
typedef struct _RGM_HandleType
{
    void (*pRgmCpu0ResetInterruptNotify)(struct _RGM_HandleType *pHandle, uint32_t u32ResetReson);    /**< Cpu0 reset interrupt callback */
#if RGM_C1_SUPPORT
    void (*pRgmCpu1ResetInterruptNotify)(struct _RGM_HandleType *pHandle, uint32_t u32ResetReson);    /**< Cpu1 reset interrupt callback */
    void (*pRgmCpu0IntFromOtherCpuNotify)(struct _RGM_HandleType *pHandle, uint8_t u8CoreId);        /**< Cpu0 interrupt from other cpu callback */
#endif
#if RGM_C2_SUPPORT
    void (*pRgmCpu2ResetInterruptNotify)(struct _RGM_HandleType *pHandle, uint32_t u32ResetReson);    /**< Cpu2 reset interrupt callback */
    void (*pRgmCpu1IntFromOtherCpuNotify)(struct _RGM_HandleType *pHandle, uint8_t u8CoreId);        /**< Cpu1 interrupt from other cpu callback */
    void (*pRgmCpu2IntFromOtherCpuNotify)(struct _RGM_HandleType *pHandle, uint8_t u8CoreId);        /**< Cpu2 interrupt from other cpu callback */
#endif
#if RGM_C3_SUPPORT
    void (*pRgmCpu3ResetInterruptNotify)(struct _RGM_HandleType *pHandle, uint32_t u32ResetReson);    /**< Cpu3 reset interrupt callback */
    void (*pRgmCpu3IntFromOtherCpuNotify)(struct _RGM_HandleType *pHandle, uint8_t u8CoreId);        /**< Cpu3 interrupt from other cpu callback */
#endif
} RGM_HandleType;

/** @brief Rgm configure type */
typedef struct
{
    bool bResetfiltAonLp;                   /**< Reset Pin Filter using AON32K Clock in Low Power Mode */
#if RGM_C1_SUPPORT
    bool bCpu1RstIntSendCpu0En;             /**< Cpu1 reset interrupt to Cpu0 enable/disable */
    bool bCpu1RstTrigSysRstEn;              /**< Cpu1 reset generate system reset enable/disable */
    RGM_CoreRstTrigSysRstMangerType eCpu1Rst;  /**< Core reset trigger system reset event flag */
#endif
#if RGM_C2_SUPPORT
    bool bCpu1RstIntSendCpu2En;             /**< Cpu1 reset interrupt to Cpu2 enable/disable */
    bool bCpu2RstIntSendCpu0En;             /**< Cpu2 reset interrupt to Cpu0 enable/disable */
    bool bCpu2RstIntSendCpu1En;             /**< Cpu2 reset interrupt to Cpu1 enable/disable */
    bool bCpu2RstTrigSysRstEn;              /**< Cpu2 reset generate system reset enable/disable */
    RGM_CoreRstTrigSysRstMangerType eCpu2Rst;  /**< Core reset trigger system reset event flag */
#endif
#if RGM_C3_SUPPORT
    bool bCpu1RstIntSendCpu3En;             /**< Cpu1 reset interrupt to Cpu3 enable/disable */
    bool bCpu2RstIntSendCpu3En;             /**< Cpu2 reset interrupt to Cpu3 enable/disable */
    bool bCpu3RstIntSendCpu0En;             /**< Cpu3 reset interrupt to Cpu0 enable/disable */
    bool bCpu3RstIntSendCpu12En;             /**< Cpu3 reset interrupt to Cpu12 enable/disable */
    bool bCpu3RstTrigSysRstEn;              /**< Cpu3 reset generate system reset enable/disable */
    RGM_CoreRstTrigSysRstMangerType eCpu3Rst;  /**< Core reset trigger system reset event flag */
#endif
    uint8_t u8BusClockFilterWidth;          /**< Reset Pin Filter Bus Clock Width Configuration */
    RGM_FilterClkSrc  eFliterClkSrc;           /**< Reset Pin Filter Clock source */
    RGM_ResetDelayType eDelay;                   /**< Reset delay after interrupt assert */
    uint32_t u32SystemInterruptMask;           /**< System interrupt enable mask */
    uint32_t u32Cpu0InterruptMask;               /**< Core interrupt enable mask */
#if RGM_C1_SUPPORT
    uint32_t u32Cpu1InterruptMask;               /**< Core interrupt enable mask */
    void (*pRgmCpu1ResetInterruptNotify)(RGM_HandleType *pHandle, uint32_t u32ResetReson);    /**< Cpu1 reset interrupt callback */
    void (*pRgmCpu0IntFromOtherCpuNotify)(RGM_HandleType *pHandle, uint8_t u8CoreId);        /**< Cpu0 interrupt from other cpu callback */
#endif
#if RGM_C2_SUPPORT
    uint32_t u32Cpu2InterruptMask;               /**< Core interrupt enable mask */
    void (*pRgmCpu2ResetInterruptNotify)(RGM_HandleType *pHandle, uint32_t u32ResetReson);    /**< Cpu2 reset interrupt callback */
    void (*pRgmCpu1IntFromOtherCpuNotify)(RGM_HandleType *pHandle, uint8_t u8CoreId);        /**< Cpu1 interrupt from other cpu callback */
    void (*pRgmCpu2IntFromOtherCpuNotify)(RGM_HandleType *pHandle, uint8_t u8CoreId);        /**< Cpu2 interrupt from other cpu callback */
#endif
#if RGM_C3_SUPPORT
    uint32_t u32Cpu3InterruptMask;               /**< Core interrupt enable mask */
    void (*pRgmCpu3ResetInterruptNotify)(RGM_HandleType *pHandle, uint32_t u32ResetReson);    /**< Cpu3 reset interrupt callback */
    void (*pRgmCpu3IntFromOtherCpuNotify)(RGM_HandleType *pHandle, uint8_t u8CoreId);        /**< Cpu3 interrupt from other cpu callback */
#endif
    void (*pRgmCpu0ResetInterruptNotify)(RGM_HandleType *pHandle, uint32_t u32ResetReson);    /**< Cpu0 reset interrupt callback */
} RGM_ConfigType;

/**
 * @brief This api can get RGM_SRS register that indicate the source of the most recent reset.
 *
 * @return RGM->RGM_SRS register, bit 0-15,29-31 corresponding to RGM_ResetEventType, refer to reference manual for details.
 * @note Multiple flags can be set if multiple reset events occur at the same time
 */
uint32_t RGM_GetSystemLastResetFLag(void);

/**
 * @brief This api can get RGM_SSRS register that indicate all reset sources since the last POR or LVD that have not been cleared by software.
 *
 * @return RGM->RGM_SSRS register, bit 0-15,29-31 corresponding to RGM_ResetEventType, refer to reference manual for details.
 */
uint32_t RGM_GetSystemAllResetFlag(void);

/**
 * @brief This api can clear all reset flag of RGM_SSRS register which indicate all reset sources since the last POR or LVD that have not been cleared by software.
 *
 */
void RGM_ClearSystemAllResetFlagAfterPOR(void);

/**
 * @brief Enable reset pin filter
 *
 * @param eClk Reset pin filter clock source
 * @param u8BusClockFilterWidth Bus clock filter width
 * @param bLpClkEn select whether enable reset pin filter using AON32clock in low power mode
 * @return RGM return type
 * @note If use AON32K clock, A reset signal whose length is less than 2 AON32K clock periods will be filtered
 */
RGM_StatusType RGM_EnableResetFilter(RGM_FilterClkSrc eClk, uint8_t u8BusClockFilterWidth, bool bLpClkEn);

/**
 * @brief Disable reset pin filter
 *
 * @param eClk Reset pin filter clock source
 * @param bLpClkEn select whether disable reset pin filter using AON32clock in low power mode
 * @return RGM return type
 */
RGM_StatusType RGM_DisableResetFilter(RGM_FilterClkSrc eClk, bool bLpClkEn);

/**
 * @brief This api can enable interrupt before an system reset appear.
 *
 * @param eDelay Enumeration of delay cycles
 * @param eResetInterrupt Reset event flag, like: RGM_INT_CLKERR0 | RGM_INT_FCSMU
 * @return RGM return type
 *
 * @note Here is the interrupted master switch control
 */
RGM_StatusType RGM_EnableSystemResetInt(RGM_ResetDelayType eDelay, RGM_SysResetIntMangerType eResetInterrupt);

/**
 * @brief This api can disable interrupt before an system reset appear.
 *
 * @param eResetInterrupt Reset event flag, like: RGM_INT_CLKERR0 | RGM_INT_FCSMU
 * @return RGM return type
 */
void RGM_DisableSystemResetInt(RGM_SysResetIntMangerType eResetInterrupt);

/**
 * @brief Generate software reset through cotex-m register
 *
 */
void RGM_GenerateSystemCoreReset(void);

/**
 * @brief Generate software reset through RGM C0_RST register
 *
 */
void RGM_GenerateCpu0SwReset(void);

/**
 * @brief This api can disable interrupt before an CPU0 core related reset appear.
 *
 * @param eCPU0Interrupt Reset event flag, like: RGM_CPU_INT_SWRST | RGM_CPU_INT_SYSRST
 * @return RGM return type
 */
RGM_StatusType RGM_DisableCPU0CoreResetInt(RGM_CoreResetIntMangerType eCPU0Interrupt);

/**
 * @brief Get the CPU0 exit reset flag
 *
 * @return RGM_CPU_OUT_RST_UNDER CPU0 is under reset
 * @return RGM_CPU_OUT_RST_OUT CPU0 is out of reset
 */
RGM_CoreResetStatusType RGM_GetCPU0OutResetFlag(void);

/**
 * @brief This api can get RGM_C0_SRS register that indicate the source of the most recent CPU0 reset.
 *
 * @return RGM->RGM_C0_SRS register, bit 0-20 corresponding to RGM_ResetEventType, refer to reference manual for details.
 * @note Multiple flags can be set if multiple reset events occur at the same time
 */
uint32_t RGM_GetCPU0LastResetFLag(void);

/**
 * @brief This api can get RGM_C0_SSRS register that indicate all CPU0 reset sources since the last POR or LVD that have not been cleared by software.
 *
 * @returnRGM->RGM_C0_SSRS register, bit 0-20,29-31 corresponding to RGM_CPUResetEventType, refer to reference manual for details.
 */
uint32_t RGM_GetCPU0AllResetFlag(void);


/**
 * @brief This api can clear all reset flag of RGM_C0_SSRS register which indicate CPU0 all reset sources since the last POR or LVD that have not been cleared by software.
 *
 */
void RGM_ClearCPU0AllResetFlagAfterPOR(void);

#if RGM_C1_SUPPORT
/**
 * @brief This api can configure the selected CPU1 core related reset as a system reset.
 *
 * @param eCPU1SystemReset Select the CPU1 core related reset need to be configured as system reset
 * @return RGM return type
 */
RGM_StatusType RGM_EnableCPU1CoreSystemReset(RGM_CoreRstTrigSysRstMangerType eCPU1SystemReset);

/**
 * @brief This api can configure the selected CPU1 core related reset as non system reset.
 *
 * @param eCPU1SystemReset Select the CPU1 core related reset need to be configured as non system reset
 * @return RGM return type
 */
RGM_StatusType RGM_DisableCPU1CoreSystemReset(RGM_CoreRstTrigSysRstMangerType eCPU1SystemReset);

/**
 * @brief This api can disable interrupt before an CPU1 core related reset appear.
 *
 * @param eCPU1Interrupt Reset event flag, like: RGM_CPU_INT_SWRST | RGM_CPU_INT_SYSRST
 * @return RGM return type
 */
RGM_StatusType RGM_DisableCPU1CoreResetInt(RGM_CoreResetIntMangerType eCPU1Interrupt);

/**
 * @brief Get the CPU1 exit reset flag
 *
 * @return RGM_CPU_OUT_RST_UNDER CPU1 is under reset
 * @return RGM_CPU_OUT_RST_OUT CPU1 is out of reset
 */
RGM_CoreResetStatusType RGM_GetCPU1OutResetFlag(void);

/**
 * @brief Generate software reset through RGM C1_RST register
 *
 */
void RGM_GenerateCpu1SwReset(void);

/**
 * @brief This api can get RGM_C1_SRS register that indicate the source of the most recent CPU1 reset.
 *
 * @return RGM->RGM_C1_SRS register, bit 0-20 corresponding to RGM_ResetEventType, refer to reference manual for details.
 * @note Multiple flags can be set if multiple reset events occur at the same time
 */
uint32_t RGM_GetCPU1LastResetFLag(void);

/**
 * @brief This api can release CPU1.
 *
 * @note After writing, this bit will be locked.
 */
void RGM_ReleaseCPU1(void);

/**
 * @brief This api can get RGM_C1_SSRS register that indicate all CPU1 reset sources since the last POR or LVD that have not been cleared by software.
 *
 * @returnRGM->RGM_C1_SSRS register, bit 0-20,29-31 corresponding to RGM_CPUResetEventType, refer to reference manual for details.
 */
uint32_t RGM_GetCPU1AllResetFlag(void);

/**
 * @brief This api can clear all reset flag of RGM_C1_SSRS register which indicate CPU1 all reset sources since the last POR or LVD that have not been cleared by software.
 *
 */
void RGM_ClearCPU1AllResetFlagAfterPOR(void);
#endif

#if RGM_C2_SUPPORT
/**
 * @brief This api can configure the selected CPU2 core related reset as a system reset.
 *
 * @param eCPU2SystemReset Select the CPU2 core related reset need to be configured as system reset
 * @return RGM return type
 */
RGM_StatusType RGM_EnableCPU2CoreSystemReset(RGM_CoreRstTrigSysRstMangerType eCPU2SystemReset);

/**
 * @brief This api can configure the selected CPU2 core related reset as non system reset.
 *
 * @param eCPU2SystemReset Select the CPU2 core related reset need to be configured as non system reset
 * @return RGM return type
 */
RGM_StatusType RGM_DisableCPU2CoreSystemReset(RGM_CoreRstTrigSysRstMangerType eCPU2SystemReset);

/**
 * @brief This api can disable interrupt before an CPU2 core related reset appear.
 *
 * @param eCPU2Interrupt Reset event flag, like: RGM_CPU_INT_SWRST | RGM_CPU_INT_SYSRST
 * @return RGM return type
 */
RGM_StatusType RGM_DisableCPU2CoreResetInt(RGM_CoreResetIntMangerType eCPU2Interrupt);

/**
 * @brief Get the CPU2 exit reset flag
 *
 * @return RGM_CPU_OUT_RST_UNDER CPU2 is under reset
 * @return RGM_CPU_OUT_RST_OUT CPU2 is out of reset
 */
RGM_CoreResetStatusType RGM_GetCPU2OutResetFlag(void);

/**
 * @brief Generate software reset through RGM C2_RST register
 *
 */
void RGM_GenerateCpu2SwReset(void);

/**
 * @brief This api can get RGM_C2_SRS register that indicate the source of the most recent CPU2 reset.
 *
 * @return RGM->RGM_C2_SRS register, bit 0-20 corresponding to RGM_ResetEventType, refer to reference manual for details.
 * @note Multiple flags can be set if multiple reset events occur at the same time
 */
uint32_t RGM_GetCPU2LastResetFLag(void);

/**
 * @brief This api can release CPU2.
 *
 * @note After writing, this bit will be locked.
 */
void RGM_ReleaseCPU2(void);

/**
 * @brief This api can get RGM_C2_SSRS register that indicate all CPU2 reset sources since the last POR or LVD that have not been cleared by software.
 *
 * @return RGM->RGM_C2_SSRS register, bit 0-20,29-31 corresponding to RGM_CPUResetEventType, refer to reference manual for details.
 */
uint32_t RGM_GetCPU2AllResetFlag(void);

/**
 * @brief This api can clear all reset flag of RGM_C2_SSRS register which indicate CPU2 all reset sources since the last POR or LVD that have not been cleared by software.
 *
 */
void RGM_ClearCPU2AllResetFlagAfterPOR(void);
#endif

#if RGM_C3_SUPPORT
/**
 * @brief This api can configure the selected CPU3 core related reset as a system reset.
 *
 * @param eCPU3SystemReset Select the CPU3 core related reset need to be configured as system reset
 * @return RGM return type
 */
RGM_StatusType RGM_EnableCPU3CoreSystemReset(RGM_CoreRstTrigSysRstMangerType eCPU3SystemReset);

/**
 * @brief This api can configure the selected CPU3 core related reset as non system reset.
 *
 * @param eCPU3SystemReset Select the CPU3 core related reset need to be configured as non system reset
 * @return RGM return type
 */
RGM_StatusType RGM_DisableCPU3CoreSystemReset(RGM_CoreRstTrigSysRstMangerType eCPU3SystemReset);

/**
 * @brief This api can disable interrupt before an CPU3 core related reset appear.
 *
 * @param eCPU3Interrupt Reset event flag, like: RGM_CPU_INT_SWRST | RGM_CPU_INT_SYSRST
 * @return RGM return type
 */
RGM_StatusType RGM_DisableCPU3CoreResetInt(RGM_CoreResetIntMangerType eCPU3Interrupt);

/**
 * @brief Get the CPU3 exit reset flag
 *
 * @return RGM_CPU_OUT_RST_UNDER CPU3 is under reset
 * @return RGM_CPU_OUT_RST_OUT CPU3 is out of reset
 */
RGM_CoreResetStatusType RGM_GetCPU3OutResetFlag(void);

/**
 * @brief Generate software reset through RGM C3_RST register
 *
 */
void RGM_GenerateCPU3SwReset(void);

/**
 * @brief This api can get RGM_C3_SRS register that indicate the source of the most recent CPU3 reset.
 *
 * @return RGM->RGM_C3_SRS register, bit 0-20 corresponding to RGM_ResetEventType, refer to reference manual for details.
 * @note Multiple flags can be set if multiple reset events occur at the same time
 */
uint32_t RGM_GetCPU3LastResetFLag(void);

/**
 * @brief This api can release CPU3.
 *
 * @note After writing, this bit will be locked.
 */
void RGM_ReleaseCPU3(void);

/**
 * @brief This api can get RGM_C3_SSRS register that indicate all CPU3 reset sources since the last POR or LVD that have not been cleared by software.
 *
 * @return RGM->RGM_C3_SSRS register, bit 0-20,29-31 corresponding to RGM_CPUResetEventType, refer to reference manual for details.
 */
uint32_t RGM_GetCPU3AllResetFlag(void);

/**
 * @brief This api can clear all reset flag of RGM_C3_SSRS register which indicate CPU3 all reset sources since the last POR or LVD that have not been cleared by software.
 *
 */
void RGM_ClearCPU3AllResetFlagAfterPOR(void);
#endif

/**
 * @brief RGM Pre-interrupt entry
 *
 */
void RGM_Pre_UserIRQHandler(RGM_HandleType* pRgmHandle);


#if (RGM_C1_SUPPORT || RGM_C2_SUPPORT || RGM_C3_SUPPORT)
/**
 * @brief RGM Other core interrupt entry
 *
 */
void RGM_Other_UserIRQHandler(RGM_HandleType* pRgmHandle);
#endif

/**
 * @brief RGM initialize function
 *
 * @param pRgmHandle RGM handle
 * @param pInitCfg   Init pointer
 *
 * @note
 *         1. RGM system related register configured by core 0
 *         2. If core1/core2 use RGM, both core0 and core1/core2 need call RGM_Init
 *            and different pRgmHandle need be given
 */
void RGM_Init(RGM_HandleType* pRgmHandle, RGM_ConfigType *pInitCfg);

/** @}*/ /* module_driver_rgm */

#endif /* #if RGM_INSTANCE_COUNT > 0U */

#endif /* end of _DRIVER_MODULE_DRIVER_RGM_H_ */
