/**
 * @file module_driver_rgm.c
 * @author Flagchip
 * @brief RGM driver source code
 * @version 2.0.0
 * @date 2024-08-20
 *
 * SDK Version: 2.6.0
 *

 * @copyright Copyright (c) 2020-2024 Flagchip Semiconductors Co., Ltd.
 *
 * @details
 */
/********************************************************************************
*   Revision History:
*
*   Version     Date          Initials       CR#          Descriptions
*   ---------   ----------    ------------   ----------   ---------------
*   0.1.0       2022-12-30    Flagchip074    N/A          FC7xxx internal release version
*   0.2.0       2023-02-15    Flagchip074    N/A          FC7xxx release version
*   2.0.0       2024-10-15    Flagchip055    N/A          Modify software architecture
********************************************************************************/
#include "module_driver_rgm.h"
#if RGM_C3_SUPPORT
#include "module_driver_smc.h"
#else
#include "module_driver_csc.h"
#endif

#if RGM_INSTANCE_COUNT > 0U


#ifndef RGM_DEV_ERROR_REPORT
#define RGM_DEV_ERROR_REPORT    STD_OFF
#endif

#if RGM_DEV_ERROR_REPORT == STD_ON
#define RGM_ReportDevError(func, error) ReportDevError(RGM_MODULE_ID, func, error)
#endif


/**
 * @brief This api can get RGM_SRS register that indicate the source of the most recent reset.
 *
 * @return RGM->RGM_SRS register, bit 0-15,29-31 corresponding to RGM_ResetEventType, refer to reference manual for details.
 * @note Multiple flags can be set if multiple reset events occur at the same time
 */
uint32_t RGM_GetSystemLastResetFLag(void)
{
    return RGM_HWA_ReadLastResetFlag();
}

/**
 * @brief This api can get RGM_SSRS register that indicate all reset sources since the last POR or LVD that have not been cleared by software.
 *
 * @return RGM->RGM_SSRS register, bit 0-15,29-31 corresponding to RGM_ResetEventType, refer to reference manual for details.
 */
uint32_t RGM_GetSystemAllResetFlag(void)
{
    return RGM_HWA_ReadAllResetFlagBeforePOR();
}

/**
 * @brief This api can clear all reset flag of RGM_SSRS register which indicate all reset sources since the last POR or LVD that have not been cleared by software.
 *
 */
void RGM_ClearSystemAllResetFlagAfterPOR(void)
{
    RGM_HWA_ClearAllResetFlagAfterPOR();
}

/**
 * @brief Enable reset pin filter
 *
 * @param eClk Reset pin filter clock source
 * @param u8BusClockFilterWidth Bus clock filter width
 * @param bLpClkEn select whether enable reset pin filter using AON32clock in low power mode
 * @return RGM return type
 * @note If use AON32K clock, A reset signal whose length is less than 2 AON32K clock periods will be filtered
 */
RGM_StatusType RGM_EnableResetFilter(RGM_FilterClkSrc eClk, uint8_t u8BusClockFilterWidth, bool bLpClkEn)
{
    RGM_StatusType eRet = RGM_STATUS_SUCCESS;
    uint32_t u32Temp = 0U;
    (void)bLpClkEn;

    if(eClk > RGM_RESET_FILTER_BUS_CLOCK)
    {
        eRet = RGM_STATUS_PARAM_INVALID;
    }

    if (RGM_STATUS_SUCCESS == eRet)
    {
        /* Add robustness item */
        RGM_HWA_SetRstfltReg(0U);

        if (RGM_RESET_FILTER_BUS_CLOCK == eClk)
        {
            u32Temp = RGM_RSTFLT_RSTFLT_BUSW(u8BusClockFilterWidth);
            u32Temp|= RGM_RSTFLT_RSTFLT_BUS_MASK;
        }
        else
        {
            /* Do nothing */
        }

        RGM_HWA_SetRstfltReg(u32Temp);
    }
    return eRet;
}

/**
 * @brief Disable reset pin filter
 *
 * @param eClk Reset pin filter clock source
 * @param bLpClkEn select whether disable reset pin filter using AON32clock in low power mode
 * @return RGM return type
 */
RGM_StatusType RGM_DisableResetFilter(RGM_FilterClkSrc eClk, bool bLpClkEn)
{
    RGM_StatusType eRet = RGM_STATUS_SUCCESS;
    (void)bLpClkEn;

    if (eClk > RGM_RESET_FILTER_BUS_CLOCK)
    {
        eRet = RGM_STATUS_PARAM_INVALID;
    }
    if (RGM_STATUS_SUCCESS == eRet)
    {
        if (RGM_RESET_FILTER_BUS_CLOCK == eClk)
        {
            RGM_HWA_ClearBusClockFilterWidth();
            RGM_HWA_DisableBusClockFilter();
        }
    }
    return eRet;
}

/**
 * @brief This api can disable interrupt before an system reset appear.
 *
 * @param eResetInterrupt Reset event flag, like: RGM_INT_CLKERR0 | RGM_INT_FCSMU
 * @return RGM return type
 */
void RGM_DisableSystemResetInt(RGM_SysResetIntMangerType eResetInterrupt)
{
    RGM_HWA_DisableResetInterrupt(eResetInterrupt);
}

/**
 * @brief Generate software reset through cotex-m register
 *
 */
void RGM_GenerateSystemCoreReset(void)
{
    CM7_HWA_SystemCoreReset();
}

/**
 * @brief Generate software reset through RGM C0_RST register
 *
 */
void RGM_GenerateCpu0SwReset(void)
{
    RGM_HWA_CPU0_SystemSoftWareReset();
}

/**
 * @brief This api can disable interrupt before an CPU0 core related reset appear.
 *
 * @param eCPU0Interrupt Reset event flag, like: RGM_CPU_INT_SWRST | RGM_CPU_INT_SYSRST
 * @return RGM return type
 */
RGM_StatusType RGM_DisableCPU0CoreResetInt(RGM_CoreResetIntMangerType eCPU0Interrupt)
{
    RGM_StatusType eRet = RGM_STATUS_SUCCESS;
    if(eCPU0Interrupt > RGM_CPU_INT_SWRST)
    {
        eRet = RGM_STATUS_PARAM_INVALID;
    }
    if (RGM_STATUS_SUCCESS == eRet)
    {
        RGM_HWA_DisableCPU0InterruptFlag(eCPU0Interrupt);
    }
    return eRet;
}

/**
 * @brief Get the CPU0 exit reset flag
 *
 * @return RGM_CPU_OUT_RST_UNDER CPU0 is under reset
 * @return RGM_CPU_OUT_RST_OUT CPU0 is out of reset
 */
RGM_CoreResetStatusType RGM_GetCPU0OutResetFlag(void)
{
    return RGM_HWA_GetCPU0OutResetFlag();
}

/**
 * @brief This api can get RGM_C0_SRS register that indicate the source of the most recent CPU0 reset.
 *
 * @return RGM->RGM_C0_SRS register, bit 0-20 corresponding to RGM_ResetEventType, refer to reference manual for details.
 * @note Multiple flags can be set if multiple reset events occur at the same time
 */
uint32_t RGM_GetCPU0LastResetFLag(void)
{
    return RGM_HWA_ReadCPU0LastResetFlag();
}

/**
 * @brief This api can get RGM_C0_SSRS register that indicate all CPU0 reset sources since the last POR or LVD that have not been cleared by software.
 *
 * @returnRGM->RGM_C0_SSRS register, bit 0-20,29-31 corresponding to RGM_CPUResetEventType, refer to reference manual for details.
 */
uint32_t RGM_GetCPU0AllResetFlag(void)
{
    return RGM_HWA_ReadCPU0AllResetFlagBeforePOR();
}

/**
 * @brief This api can clear all reset flag of RGM_C0_SSRS register which indicate CPU0 all reset sources since the last POR or LVD that have not been cleared by software.
 *
 */
void RGM_ClearCPU0AllResetFlagAfterPOR(void)
{
    RGM_HWA_ClearC0AllResetFlagAfterPOR();
}

#if RGM_C1_SUPPORT
/**
 * @brief This api can configure the selected CPU1 core related reset as non system reset.
 *
 * @param eCPU1SystemReset Select the CPU1 core related reset need to be configured as non system reset
 * @return RGM return type
 */
RGM_StatusType RGM_DisableCPU1CoreSystemReset(RGM_CoreRstTrigSysRstMangerType eCPU1SystemReset)
{
    RGM_StatusType eRet = RGM_STATUS_SUCCESS;

    if ( (eCPU1SystemReset < RGM_CPU_EN_LOCKUP) || (eCPU1SystemReset > RGM_CPU_EN_SWRST) )
    {
        eRet = RGM_STATUS_PARAM_INVALID;
    }
    else
    {
        RGM_HWA_DisableCPU1SystemResetFlag(eCPU1SystemReset);
    }
    return eRet;
}

/**
 * @brief This api can disable interrupt before an CPU1 core related reset appear.
 *
 * @param eCPU1Interrupt Reset event flag, like: RGM_CPU_INT_SWRST | RGM_CPU_INT_SYSRST
 * @return RGM return type
 */
RGM_StatusType RGM_DisableCPU1CoreResetInt(RGM_CoreResetIntMangerType eCPU1Interrupt)
{
    RGM_StatusType eRet = RGM_STATUS_SUCCESS;

    if (eCPU1Interrupt > RGM_CPU_INT_SWRST)
    {
        eRet = RGM_STATUS_PARAM_INVALID;
    }
    else
    {
        RGM_HWA_DisableCPU1InterruptFlag(eCPU1Interrupt);
    }
    return eRet;
}

/**
 * @brief Get the CPU1 exit reset flag
 *
 * @return RGM_CPU_OUT_RST_UNDER CPU1 is under reset
 * @return RGM_CPU_OUT_RST_OUT CPU1 is out of reset
 */
RGM_CoreResetStatusType RGM_GetCPU1OutResetFlag(void)
{
    return RGM_HWA_GetCPU1OutResetFlag();
}

/**
 * @brief Generate software reset through RGM C1_RST register
 *
 */
void RGM_GenerateCpu1SwReset(void)
{
    RGM_HWA_CPU1_SystemSoftWareReset();
}

/**
 * @brief This api can get RGM_C1_SRS register that indicate the source of the most recent CPU1 reset.
 *
 * @return RGM->RGM_C1_SRS register, bit 0-20 corresponding to RGM_ResetEventType, refer to reference manual for details.
 * @note Multiple flags can be set if multiple reset events occur at the same time
 */
uint32_t RGM_GetCPU1LastResetFLag(void)
{
    return RGM_HWA_ReadCPU1LastResetFlag();
}

/**
 * @brief This api can release CPU1.
 *
 * @note After writing, this bit will be locked.
 */
void RGM_ReleaseCPU1(void)
{
    RGM_HWA_ReleaseCPU1();
}

/**
 * @brief This api can get RGM_C1_SSRS register that indicate all CPU1 reset sources since the last POR or LVD that have not been cleared by software.
 *
 * @returnRGM->RGM_C1_SSRS register, bit 0-20,29-31 corresponding to RGM_CPUResetEventType, refer to reference manual for details.
 */
uint32_t RGM_GetCPU1AllResetFlag(void)
{
    return RGM_HWA_ReadCPU1AllResetFlagBeforePOR();
}

/**
 * @brief This api can clear all reset flag of RGM_C1_SSRS register which indicate CPU1 all reset sources since the last POR or LVD that have not been cleared by software.
 *
 */
void RGM_ClearCPU1AllResetFlagAfterPOR(void)
{
    RGM_HWA_ClearC1AllResetFlagAfterPOR();
}
#endif

#if RGM_C2_SUPPORT
/**
 * @brief This api can configure the selected CPU2 core related reset as non system reset.
 *
 * @param eCPU2SystemReset Select the CPU2 core related reset need to be configured as non system reset
 * @return RGM return type
 */
RGM_StatusType RGM_DisableCPU2CoreSystemReset(RGM_CoreRstTrigSysRstMangerType eCPU2SystemReset)
{
    RGM_StatusType eRet = RGM_STATUS_SUCCESS;

    if ( (eCPU2SystemReset < RGM_CPU_EN_LOCKUP) || (eCPU2SystemReset > RGM_CPU_EN_SWRST) )
    {
        eRet = RGM_STATUS_PARAM_INVALID;
    }
    else
    {
        RGM_HWA_DisableCPU2SystemResetFlag(eCPU2SystemReset);
    }
    return eRet;
}

/**
 * @brief This api can disable interrupt before an CPU2 core related reset appear.
 *
 * @param eCPU2Interrupt Reset event flag, like: RGM_CPU_INT_SWRST | RGM_CPU_INT_SYSRST
 * @return RGM return type
 */
RGM_StatusType RGM_DisableCPU2CoreResetInt(RGM_CoreResetIntMangerType eCPU2Interrupt)
{
    RGM_StatusType eRet = RGM_STATUS_SUCCESS;

    if(eCPU2Interrupt > RGM_CPU_INT_SWRST)
    {
        eRet = RGM_STATUS_PARAM_INVALID;
    }
    if (RGM_STATUS_SUCCESS == eRet)
    {
        RGM_HWA_DisableCPU2InterruptFlag(eCPU2Interrupt);
    }
    return eRet;
}

/**
 * @brief Get the CPU2 exit reset flag
 *
 * @return RGM_CPU_OUT_RST_UNDER CPU2 is under reset
 * @return RGM_CPU_OUT_RST_OUT CPU2 is out of reset
 */
RGM_CoreResetStatusType RGM_GetCPU2OutResetFlag(void)
{
    return RGM_HWA_GetCPU2OutResetFlag();
}

/**
 * @brief Generate software reset through RGM C2_RST register
 *
 */
void RGM_GenerateCpu2SwReset(void)
{
    RGM_HWA_CPU2_SystemSoftWareReset();
}

/**
 * @brief This api can get RGM_C2_SRS register that indicate the source of the most recent CPU2 reset.
 *
 * @return RGM->RGM_C2_SRS register, bit 0-20 corresponding to RGM_ResetEventType, refer to reference manual for details.
 * @note Multiple flags can be set if multiple reset events occur at the same time
 */
uint32_t RGM_GetCPU2LastResetFLag(void)
{
    return RGM_HWA_ReadCPU2LastResetFlag();
}

/**
 * @brief This api can release CPU2.
 *
 * @note After writing, this bit will be locked.
 */
void RGM_ReleaseCPU2(void)
{
    RGM_HWA_ReleaseCPU2();
}

/**
 * @brief This api can get RGM_C2_SSRS register that indicate all CPU2 reset sources since the last POR or LVD that have not been cleared by software.
 *
 * @return RGM->RGM_C2_SSRS register, bit 0-20,29-31 corresponding to RGM_CPUResetEventType, refer to reference manual for details.
 */
uint32_t RGM_GetCPU2AllResetFlag(void)
{
    return RGM_HWA_ReadCPU2AllResetFlagBeforePOR();
}

/**
 * @brief This api can clear all reset flag of RGM_C2_SSRS register which indicate CPU2 all reset sources since the last POR or LVD that have not been cleared by software.
 *
 */
void RGM_ClearCPU2AllResetFlagAfterPOR(void)
{
    RGM_HWA_ClearC2AllResetFlagAfterPOR();
}
#endif

#if RGM_C3_SUPPORT
/**
 * @brief This api can configure the selected CPU3 core related reset as non system reset.
 *
 * @param eCPU3SystemReset Select the CPU3 core related reset need to be configured as non system reset
 * @return RGM return type
 */
RGM_StatusType RGM_DisableCPU3CoreSystemReset(RGM_CoreRstTrigSysRstMangerType eCPU3SystemReset)
{
    RGM_StatusType eRet = RGM_STATUS_SUCCESS;

    if ( (eCPU3SystemReset < RGM_CPU_EN_LOCKUP) || (eCPU3SystemReset > RGM_CPU_EN_SWRST) )
    {
        eRet = RGM_STATUS_PARAM_INVALID;
    }
    else
    {
        RGM_HWA_DisableCPU3SystemResetFlag(eCPU3SystemReset);
    }
    return eRet;
}

/**
 * @brief This api can disable interrupt before an CPU3 core related reset appear.
 *
 * @param eCPU3Interrupt Reset event flag, like: RGM_CPU_INT_SWRST | RGM_CPU_INT_SYSRST
 * @return RGM return type
 */
RGM_StatusType RGM_DisableCPU3CoreResetInt(RGM_CoreResetIntMangerType eCPU3Interrupt)
{
    RGM_StatusType eRet = RGM_STATUS_SUCCESS;

    if(eCPU3Interrupt > RGM_CPU_INT_SWRST)
    {
        eRet = RGM_STATUS_PARAM_INVALID;
    }
    if (RGM_STATUS_SUCCESS == eRet)
    {
        RGM_HWA_DisableCPU3InterruptFlag(eCPU3Interrupt);
    }
    return eRet;
}

/**
 * @brief Get the CPU3 exit reset flag
 *
 * @return RGM_CPU_OUT_RST_UNDER CPU3 is under reset
 * @return RGM_CPU_OUT_RST_OUT CPU3 is out of reset
 */
RGM_CoreResetStatusType RGM_GetCPU3OutResetFlag(void)
{
    return RGM_HWA_GetCPU3OutResetFlag();
}

/**
 * @brief Generate software reset through RGM C3_RST register
 *
 */
void RGM_GenerateCPU3SwReset(void)
{
    RGM_HWA_CPU3_SystemSoftWareReset();
}

/**
 * @brief This api can get RGM_C3_SRS register that indicate the source of the most recent CPU3 reset.
 *
 * @return RGM->RGM_C3_SRS register, bit 0-20 corresponding to RGM_ResetEventType, refer to reference manual for details.
 * @note Multiple flags can be set if multiple reset events occur at the same time
 */
uint32_t RGM_GetCPU3LastResetFLag(void)
{
    return RGM_HWA_ReadCPU3LastResetFlag();
}

/**
 * @brief This api can release CPU3.
 *
 * @note After writing, this bit will be locked.
 */
void RGM_ReleaseCPU3(void)
{
    RGM_HWA_ReleaseCPU3();
}

/**
 * @brief This api can get RGM_C3_SSRS register that indicate all CPU3 reset sources since the last POR or LVD that have not been cleared by software.
 *
 * @return RGM->RGM_C3_SSRS register, bit 0-20,29-31 corresponding to RGM_CPUResetEventType, refer to reference manual for details.
 */
uint32_t RGM_GetCPU3AllResetFlag(void)
{
    return RGM_HWA_ReadCPU3AllResetFlagBeforePOR();
}

/**
 * @brief This api can clear all reset flag of RGM_C3_SSRS register which indicate CPU3 all reset sources since the last POR or LVD that have not been cleared by software.
 *
 */
void RGM_ClearCPU3AllResetFlagAfterPOR(void)
{
    RGM_HWA_ClearC3AllResetFlagAfterPOR();
}
#endif

/**
 * @brief RGM Pre-interrupt entry
 *
 */
void RGM_Pre_UserIRQHandler(RGM_HandleType* pRgmHandle)
{
    uint8_t u8CoreId = Cpm_HWA_GetCoreId();

    /* Core0 trigger Pre-reset interrupt */
    if (0U == u8CoreId)
    {
        if (NULL != pRgmHandle->pRgmCpu0ResetInterruptNotify)
        {
            pRgmHandle->pRgmCpu0ResetInterruptNotify(pRgmHandle, RGM_GetCPU0LastResetFLag());
        }
    }
#if RGM_C1_SUPPORT
    /* Core1 trigger Pre-reset interrupt */
    else if (1U == u8CoreId)
    {
        if (NULL != pRgmHandle->pRgmCpu1ResetInterruptNotify)
        {
            pRgmHandle->pRgmCpu1ResetInterruptNotify(pRgmHandle, RGM_GetCPU1LastResetFLag());
        }
    }
#endif
#if RGM_C2_SUPPORT
    /* Core2 trigger Pre-reset interrupt */
    else if (2U == u8CoreId)
    {
        if (NULL != pRgmHandle->pRgmCpu2ResetInterruptNotify)
        {
            pRgmHandle->pRgmCpu2ResetInterruptNotify(pRgmHandle, RGM_GetCPU2LastResetFLag());
        }
    }
#endif
#if RGM_C3_SUPPORT
    /* Core3 trigger Pre-reset interrupt */
    else if (3U == u8CoreId)
    {
        if (NULL != pRgmHandle->pRgmCpu3ResetInterruptNotify)
        {
            pRgmHandle->pRgmCpu3ResetInterruptNotify(pRgmHandle, RGM_GetCPU3LastResetFLag());
        }
    }
#endif
    else
    {
        /* No deal with */
    }

}

#if (RGM_C1_SUPPORT || RGM_C2_SUPPORT || RGM_C3_SUPPORT)
/**
 * @brief RGM Other core interrupt entry
 *
 */
void RGM_Other_UserIRQHandler(RGM_HandleType* pRgmHandle)
{
    uint8_t u8CoreId = Cpm_HWA_GetCoreId();

    /* Core0 trigger other CPU reset interrupt */
    if (0U == u8CoreId)
    {
#if RGM_C1_SUPPORT
        if (RGM_HWA_GetCPU1IntFlag())
        {
            RGM_HWA_ClearCPU1IntFlag();

            if (NULL != pRgmHandle->pRgmCpu0IntFromOtherCpuNotify)
            {
                pRgmHandle->pRgmCpu0IntFromOtherCpuNotify(pRgmHandle, 1U);
            }
        }
#endif

#if RGM_C2_SUPPORT
        if (RGM_HWA_GetCPU2IntFlag())
        {
            RGM_HWA_ClearCPU2IntFlag();

            if (NULL != pRgmHandle->pRgmCpu0IntFromOtherCpuNotify)
            {
                pRgmHandle->pRgmCpu0IntFromOtherCpuNotify(pRgmHandle, 2U);
            }
        }
#endif

#if RGM_C3_SUPPORT
        if (RGM_HWA_GetCPU3IntFlag())
        {
            RGM_HWA_ClearCPU3IntFlag();

            if (NULL != pRgmHandle->pRgmCpu0IntFromOtherCpuNotify)
            {
                pRgmHandle->pRgmCpu0IntFromOtherCpuNotify(pRgmHandle, 3U);
            }
        }
#endif
    }
#if (RGM_C1_SUPPORT && RGM_C2_SUPPORT)
#if (RGM_C3_SUPPORT)
    /* Core1 trigger other CPU reset interrupt */
    else if (1U == u8CoreId)
    {
        if (RGM_HWA_GetCPU2IntFlag())
        {
            RGM_HWA_ClearCPU2IntFlag();

            if (NULL != pRgmHandle->pRgmCpu1IntFromOtherCpuNotify)
            {
                pRgmHandle->pRgmCpu1IntFromOtherCpuNotify(pRgmHandle, 2U);
            }
        }
        else if (RGM_HWA_GetCPU3IntFlag())
        {
            RGM_HWA_ClearCPU3IntFlag();

            if (NULL != pRgmHandle->pRgmCpu1IntFromOtherCpuNotify)
            {
                pRgmHandle->pRgmCpu1IntFromOtherCpuNotify(pRgmHandle, 3U);
            }
        }
        else
        {
            /* No deal with */
        }
    }
    /* Core2 trigger other CPU reset interrupt */
    else if (2U == u8CoreId)
    {
        if (RGM_HWA_GetCPU2IntFlag())
        {
            RGM_HWA_ClearCPU2IntFlag();

            if (NULL != pRgmHandle->pRgmCpu2IntFromOtherCpuNotify)
            {
                pRgmHandle->pRgmCpu2IntFromOtherCpuNotify(pRgmHandle, 1U);
            }
        }
        else if (RGM_HWA_GetCPU3IntFlag())
        {
            RGM_HWA_ClearCPU3IntFlag();

            if (NULL != pRgmHandle->pRgmCpu2IntFromOtherCpuNotify)
            {
                pRgmHandle->pRgmCpu2IntFromOtherCpuNotify(pRgmHandle, 3U);
            }
        }
        else
        {
            /* No deal with */
        }
    }
    /* Core3 trigger other CPU reset interrupt */
    else if (3U == u8CoreId)
    {
        if (RGM_HWA_GetCPU1IntFlag())
        {
            RGM_HWA_ClearCPU1IntFlag();

            if (NULL != pRgmHandle->pRgmCpu3IntFromOtherCpuNotify)
            {
                pRgmHandle->pRgmCpu3IntFromOtherCpuNotify(pRgmHandle, 1U);
            }
        }
        else if (RGM_HWA_GetCPU2IntFlag())
        {
            RGM_HWA_ClearCPU2IntFlag();

            if (NULL != pRgmHandle->pRgmCpu3IntFromOtherCpuNotify)
            {
                pRgmHandle->pRgmCpu3IntFromOtherCpuNotify(pRgmHandle, 2U);
            }
        }
        else
        {
            /* No deal with */
        }
    }
#else /* NOT RGM_C3_SUPPORT */
    /* Core1 trigger other CPU reset interrupt */
    else if (1U == u8CoreId)
    {
        RGM_HWA_ClearCPU2IntFlag();

        if (NULL != pRgmHandle->pRgmCpu1IntFromOtherCpuNotify)
        {
            pRgmHandle->pRgmCpu1IntFromOtherCpuNotify(pRgmHandle, 2U);
        }
    }
    /* Core2 trigger other CPU reset interrupt */
    else if (2U == u8CoreId)
    {
        RGM_HWA_ClearCPU1IntFlag();

        if (NULL != pRgmHandle->pRgmCpu2IntFromOtherCpuNotify)
        {
            pRgmHandle->pRgmCpu2IntFromOtherCpuNotify(pRgmHandle, 1U);
        }
    }
#endif
#endif
    else
    {
        /* No deal with */
    }

}
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
void RGM_Init(RGM_HandleType* pRgmHandle, RGM_ConfigType *pInitCfg)
{
    RGM_StatusType eRet = RGM_STATUS_SUCCESS;

#if RGM_DEV_ERROR_REPORT == STD_ON
    if ( NULL == pInitCfg )
    {
        RGM_ReportDevError(RGM_INIT_ID, RGM_E_PARAM_POINTER);
    }
    else
    {
#endif
        uint8_t u8CoreId = Cpm_HWA_GetCoreId();

        /* RGM system related register configured by core 0  */
        if(0U == u8CoreId)
        {
            eRet = RGM_EnableResetFilter(pInitCfg->eFliterClkSrc, pInitCfg->u8BusClockFilterWidth, pInitCfg->bResetfiltAonLp);

            if (RGM_STATUS_SUCCESS == eRet)
            {
                /* if any interrupt is enable, delay clock should be checked  */
                if ( (0U != pInitCfg->u32SystemInterruptMask) || (0U != pInitCfg->u32Cpu0InterruptMask) )
                {
                    /* ERR_RGM_002 when reset delay is enable core1 core2 must trigger system reset */
#if RGM_C3_SUPPORT
                    if( ( (0 != pInitCfg->u32SystemInterruptMask)|| (0 != pInitCfg->u32Cpu1InterruptMask)|| (0 != pInitCfg->u32Cpu2InterruptMask)|| (0 != pInitCfg->u32Cpu3InterruptMask)) &&
                            (true == pInitCfg->bCpu1RstTrigSysRstEn) && ( RGM_CPU_EN_ALL == pInitCfg->eCpu1Rst) &&
                            (true == pInitCfg->bCpu2RstTrigSysRstEn) && ( RGM_CPU_EN_ALL == pInitCfg->eCpu2Rst) &&
                            (true == pInitCfg->bCpu3RstTrigSysRstEn) && ( RGM_CPU_EN_ALL == pInitCfg->eCpu3Rst)
                      )
                    {
                        eRet = RGM_STATUS_SUCCESS;
                    }
                    else
                    {
                        eRet = RGM_STATUS_PARAM_INVALID;
                    }
#elif RGM_C2_SUPPORT
                    if( ( (0 != pInitCfg->u32SystemInterruptMask)|| (0 != pInitCfg->u32Cpu1InterruptMask)|| (0 != pInitCfg->u32Cpu2InterruptMask)) &&
                            (true == pInitCfg->bCpu1RstTrigSysRstEn) && ( RGM_CPU_EN_ALL == pInitCfg->eCpu1Rst) &&
                            (true == pInitCfg->bCpu2RstTrigSysRstEn) && ( RGM_CPU_EN_ALL == pInitCfg->eCpu2Rst)
                      )
                    {
                        eRet = RGM_STATUS_SUCCESS;
                    }
                    else
                    {
                        eRet = RGM_STATUS_PARAM_INVALID;
                    }
#elif RGM_C1_SUPPORT
                    if( ( (0 != pInitCfg->u32SystemInterruptMask)|| (0 != pInitCfg->u32Cpu1InterruptMask)) &&
                            (true == pInitCfg->bCpu1RstTrigSysRstEn) && ( RGM_CPU_EN_ALL == pInitCfg->eCpu1Rst)
                      )
                    {
                        eRet = RGM_STATUS_SUCCESS;
                    }
                    else
                    {
                        eRet = RGM_STATUS_PARAM_INVALID;
                    }
#endif

                    if (RGM_STATUS_SUCCESS == eRet)
                    {
                        RGM_HWA_DisableResetInterrupt(RGM_INT_ALL);
                        RGM_HWA_EnableResetInterrupt((RGM_SysResetIntMangerType)(pInitCfg->u32SystemInterruptMask));

                        /* Cpu0 RGM register configure */
                        RGM_HWA_DisableCPU0InterruptFlag((uint32_t)(RGM_CPU_INT_LOCKUP|RGM_CPU_INT_SYSRST|RGM_CPU_INT_WDOG|RGM_CPU_INT_INTM|RGM_CPU_INT_SWRST));
                        RGM_HWA_EnableCPU0InterruptFlag(pInitCfg->u32Cpu0InterruptMask);

                        /* RGM system register configure */
                        RGM_HWA_SetResetDelay(pInitCfg->eDelay);
                        RGM_HWA_EnableGlobalResetInterrupt();

                        pRgmHandle->pRgmCpu0ResetInterruptNotify = pInitCfg->pRgmCpu0ResetInterruptNotify;
#if RGM_C1_SUPPORT
                        pRgmHandle->pRgmCpu0IntFromOtherCpuNotify = pInitCfg->pRgmCpu0IntFromOtherCpuNotify;
#endif
                    }
                    else
                    {
                        RGM_HWA_SetSrieReg(0U);
                    }
                }
            }
        }
#if RGM_C1_SUPPORT
        if (1U == u8CoreId)
        {
#if RGM_ERR_003
            if (false == pInitCfg->bCpu1RstTrigSysRstEn)
            {
                eRet = RGM_STATUS_PARAM_INVALID;
            }
            else
            {
                /* do nothing here */
            }
#endif

            if (RGM_STATUS_SUCCESS == eRet)
            {
                if (0U != pInitCfg->u32Cpu1InterruptMask)
                {
                    /* Cpu1 RGM register configure */
                    RGM_HWA_DisableCPU1InterruptFlag((uint32_t)(RGM_CPU_INT_LOCKUP|RGM_CPU_INT_SYSRST|RGM_CPU_INT_WDOG|RGM_CPU_INT_INTM|RGM_CPU_INT_SWRST));
                    RGM_HWA_EnableCPU1InterruptFlag(pInitCfg->u32Cpu1InterruptMask);

                    /* Core reset interrupt send to other core */
                    RGM_HWA_SetC1IntToC0EnableFlag(pInitCfg->bCpu1RstIntSendCpu0En);
#if (RGM_C2_SUPPORT || RGM_C3_SUPPORT)
                    RGM_HWA_SetC1IntToC2EnableFlag(pInitCfg->bCpu1RstIntSendCpu2En);
#endif

                    RGM_HWA_DisableCPU1SystemResetFlag(RGM_CPU_EN_ALL);
                    if (true == pInitCfg->bCpu1RstTrigSysRstEn)
                    {
                        RGM_HWA_EnableCPU1SystemResetFlag(pInitCfg->eCpu1Rst);
                    }

                    pRgmHandle->pRgmCpu1ResetInterruptNotify = pInitCfg->pRgmCpu1ResetInterruptNotify;
#if (RGM_C2_SUPPORT || RGM_C3_SUPPORT)
                    pRgmHandle->pRgmCpu1IntFromOtherCpuNotify = pInitCfg->pRgmCpu1IntFromOtherCpuNotify;
#endif
                }
            }
        }
#endif
#if RGM_C2_SUPPORT
        if (2U == u8CoreId)
        {
            if (0U != pInitCfg->u32Cpu2InterruptMask)
            {
                /* Cpu2 RGM register configure */
                RGM_HWA_DisableCPU2InterruptFlag((uint32_t)(RGM_CPU_INT_LOCKUP|RGM_CPU_INT_SYSRST|RGM_CPU_INT_WDOG|RGM_CPU_INT_INTM|RGM_CPU_INT_SWRST));
                RGM_HWA_EnableCPU2InterruptFlag(pInitCfg->u32Cpu2InterruptMask);

                /* Core reset interrupt send to other core */
                RGM_HWA_SetC2IntToC0EnableFlag(pInitCfg->bCpu2RstIntSendCpu0En);
                RGM_HWA_SetC2IntToC1EnableFlag(pInitCfg->bCpu2RstIntSendCpu1En);

                RGM_HWA_DisableCPU2SystemResetFlag(RGM_CPU_EN_ALL);
                if (true == pInitCfg->bCpu2RstTrigSysRstEn)
                {
                    RGM_HWA_EnableCPU2SystemResetFlag(pInitCfg->eCpu2Rst);
                }

                pRgmHandle->pRgmCpu2ResetInterruptNotify = pInitCfg->pRgmCpu2ResetInterruptNotify;
                pRgmHandle->pRgmCpu2IntFromOtherCpuNotify = pInitCfg->pRgmCpu2IntFromOtherCpuNotify;
            }
        }
#endif
#if RGM_C3_SUPPORT
        if (3U == u8CoreId)
        {
            if (0U != pInitCfg->u32Cpu3InterruptMask)
            {
                /* Cpu3 RGM register configure */
                RGM_HWA_DisableCPU3InterruptFlag((uint32_t)(RGM_CPU_INT_LOCKUP|RGM_CPU_INT_SYSRST|RGM_CPU_INT_WDOG|RGM_CPU_INT_INTM|RGM_CPU_INT_SWRST));
                RGM_HWA_EnableCPU3InterruptFlag(pInitCfg->u32Cpu3InterruptMask);

                /* Core reset interrupt send to other core */
                RGM_HWA_SetC3IntToC0EnableFlag(pInitCfg->bCpu2RstIntSendCpu0En);
                RGM_HWA_SetC3IntToC12EnableFlag(pInitCfg->bCpu3RstIntSendCpu12En);

                RGM_HWA_DisableCPU3SystemResetFlag(RGM_CPU_EN_ALL);
                if (true == pInitCfg->bCpu3RstTrigSysRstEn)
                {
                    RGM_HWA_EnableCPU3SystemResetFlag(pInitCfg->eCpu3Rst);
                }

                pRgmHandle->pRgmCpu3ResetInterruptNotify = pInitCfg->pRgmCpu3ResetInterruptNotify;
                pRgmHandle->pRgmCpu3IntFromOtherCpuNotify = pInitCfg->pRgmCpu3IntFromOtherCpuNotify;
            }
        }
#endif

#if RGM_DEV_ERROR_REPORT == STD_ON
    }
#endif

}

#endif /* #if RGM_INSTANCE_COUNT > 0U */
