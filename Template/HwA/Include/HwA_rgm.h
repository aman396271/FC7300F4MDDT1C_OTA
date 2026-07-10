/**
 * @file HwA_rgm.h
 * @author Flagchip
 * @brief RGM hardware access layer
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
   *   0.1.0      2023-12-15     Flagchip084   N/A          First version for FC7300
   *   2.0.0      2024-10-12     Flagchip084   N/A          Change version and release
   ******************************************************************************** */

#ifndef _HWA_RGM_H_
#define _HWA_RGM_H_

#include "device_header.h"

#if RGM_INSTANCE_COUNT > 0U

/**
 * @defgroup HwA_rgm HwA_rgm
 * @ingroup module_driver_rgm
 * @{
 */


/********* Local typedef ************/
/** @brief Rgm reset event */
typedef enum
{
    RGM_WAKEUP       = RGM_SRS_WAKEUP_MASK,     /**< Wakeup reset */
    RGM_LVD          = RGM_SRS_LVR_MASK,        /**< Low voltage reset */
    RGM_CLKERR1      = RGM_SRS_CLKERR1_MASK,    /**< Clock error 1 reset */
    RGM_CLKERR0      = RGM_SRS_CLKERR0_MASK,    /**< Clock error 0 reset */
    RGM_FSCMU        = RGM_SRS_FCSMU_MASK,      /**< FCSMU reset */
    RGM_HSMWDOG      = RGM_SRS_HSM_WDOG_MASK,   /**< HSM watchdog reset */
    RGM_PIN          = RGM_SRS_PIN_MASK,        /**< Pin reset */
    RGM_POR          = RGM_SRS_POR_MASK,        /**< Power on reset */
    RGM_JTAG         = RGM_SRS_JTAG_MASK,       /**< JTAG reset */
    RGM_SYSAP        = RGM_SRS_SYSAP_MASK,      /**< System AP reset */
#if RGM_WDG1_RIE_SUPPORT
    RGM_WDOG1        = RGM_SRS_WDOG1_MASK,      /**< Watchdog 1 reset */
#endif
    RGM_SACKERR      = RGM_SRS_SACKERR_MASK,    /**< SACKERR reset */
    RGM_CMU3         = RGM_SRS_CMU3_MASK,       /**< CMU3 reset */
    RGM_LBIST        = RGM_SRS_LBIST_MASK,      /**< LBIST reset */
    RGM_CPU_LOCKUP   = RGM_C0_SRS_C0_LOCKUP_MASK, /**< CPU lockup reset */
    RGM_CPU_SYSRST   = RGM_C0_SRS_C0_SYSRST_MASK, /**< CPU system core reset */
    RGM_CPU_WDOG     = RGM_C0_SRS_C0_WDOG_MASK,   /**< Watchdog 0 reset */
    RGM_CPU_INTM     = RGM_C0_SRS_C0_INTM_MASK,   /**< CPU interrupt monitor reset */
    RGM_CPU_SWRST    = RGM_C0_SRS_C0_SWRST_MASK,  /**< System software reset */
    RGM_FSMERR       = RGM_SRS_FSM_ERR_MASK,      /**< FSM error reset */
    RGM_PINRSTTOUT   = RGM_SRS_PINRST_TOUT_MASK,  /**< Pin reset timeout reset */
    RGM_SYSRSTTOUT   = RGM_SRS_SYSRST_TOUT_MASK   /**< System reset timeout reset */
} RGM_ResetEventType;

/** @brief Rgm reset interrupt delay cycles type. */
typedef enum
{
    RGM_8_CLOCK_CYCLES = 0U,  /**< 8 clock cycles */
    RGM_32_CLOCK_CYCLES,      /**< 32 clock cycles */
    RGM_128_CLOCK_CYCLES,     /**< 128 clock cycles */
    RGM_512_CLOCK_CYCLES      /**< 512 clock cycles */
} RGM_ResetDelayType;

/** @brief Rgm reset interrupt event manger */
typedef enum
{
    RGM_INT_CLKERR0      = RGM_SRIE_CLKERR0_RIE_MASK,   /**< Clock error 0 reset interrupt */
    RGM_INT_WDG          = RGM_SRIE_WDG_RIE_MASK,       /**< Watchdog reset interrupt */
#if RGM_PIN_RIE_SUPPORT
    RGM_INT_PIN          = RGM_SRIE_PIN_RIE_MASK,       /**< Pin reset interrupt */
#endif
    RGM_INT_JTAG         = RGM_SRIE_JTAG_RIE_MASK,      /**< JTAG reset interrupt */
    RGM_INT_CPULOC       = RGM_SRIE_CPULOC_RIE_MASK,    /**< CPU lockup reset interrupt */
    RGM_INT_SW           = RGM_SRIE_SW_RIE_MASK,        /**< Software reset interrupt */
    RGM_INT_SYSAP        = RGM_SRIE_SYSAP_RIE_MASK,     /**< System AP reset interrupt */
#if RGM_INTM_TOUT_RIE_SUPPORT
    RGM_INT_INTM_TOUT    = RGM_SRIE_INTM_TOUT_RIE_MASK, /**< Interrupt monitor timeout reset interrupt */
#endif
#if RGM_WDG1_RIE_SUPPORT
	RGM_INT_WDG1         = RGM_SRIE_WDOG1_RIE_MASK,     /**< Watchdog1 reset interrupt */
#endif
    RGM_INT_SACKERR      = RGM_SRIE_SACKERR_RIE_MASK,   /**< SACKERR reset interrupt */
	RGM_INT_ALL          = RGM_SRIE_ALL_RIE_MASK        /**< All reset interrupt */
} RGM_SysResetIntMangerType;

/** @brief Rgm CPU0,1,2,3 related interrupt event manger */
typedef enum
{
    RGM_CPU_INT_LOCKUP = RGM_C0_CFG_C0_LOCKUP_IE_MASK,  /**< CPU lockup reset */
    RGM_CPU_INT_SYSRST = RGM_C0_CFG_C0_SYSRST_IE_MASK,  /**< CPU system core reset */
    RGM_CPU_INT_WDOG   = RGM_C0_CFG_C0_WDOG_IE_MASK,    /**< Watchdog reset */
    RGM_CPU_INT_INTM   = RGM_C0_CFG_C0_INTM_IE_MASK,    /**< Interrupt monitor reset */
    RGM_CPU_INT_SWRST  = RGM_C0_CFG_C0_SWRST_IE_MASK    /**< Software reset */
} RGM_CoreResetIntMangerType;

/** @brief Rgm CPU0,1,2,3 software reset status */
typedef enum
{
    RGM_REEST_STATUS_UNDER_RESET = 0U,  /**< Under reset */
    RGM_REEST_STATUS_OUT_RESET          /**< Out of reset */
} RGM_CoreResetStatusType;

/** @brief Rgm CPU1,2,3 system reset enable flag */
typedef enum
{
    RGM_CPU_EN_LOCKUP  = RGM_C0_CFG_C0_LOCKUP_EN_MASK,  /**< Core lockup reset trigger system reset */
    RGM_CPU_EN_SYSRST  = RGM_C0_CFG_C0_SYSRST_EN_MASK,  /**< Core system core reset trigger system reset */
    RGM_CPU_EN_WDOG    = RGM_C0_CFG_C0_WDOG_EN_MASK,    /**< Core watchdog reset trigger system reset */
    RGM_CPU_EN_INTM    = RGM_C0_CFG_C0_INTM_EN_MASK,    /**< Core interrupt monitor reset trigger system reset */
    RGM_CPU_EN_SWRST   = RGM_C0_CFG_C0_SWRST_EN_MASK,   /**< Core software reset trigger system reset */
	RGM_CPU_EN_ALL     = 0x1F0000                       /**< Core All reset trigger system reset */
} RGM_CoreRstTrigSysRstMangerType;

/********* Local inline function ************/
/**
 * @brief Read last reset flag
 *
 * @return Last reset flag
 */
LOCAL_INLINE uint32_t RGM_HWA_ReadLastResetFlag(void)
{
    return (uint32_t)RGM->SRS;
}

/**
 * @brief Read all reset flag before POR,SSRS register is reset on POR only
 *
 * @return All reset flag before POR
 */
LOCAL_INLINE uint32_t RGM_HWA_ReadAllResetFlagBeforePOR(void)
{
    return (uint32_t)RGM->SSRS;
}

/**
 * @brief Set SSRS register
 *
 * @param u32Value SSRS register value
 */
LOCAL_INLINE void RGM_HWA_SetSsrsReg(uint32_t u32Value)
{
    RGM->SSRS = u32Value;
}

/**
 * @brief This api can clear all reset flag of SSRS register which indicate all reset sources since the last POR or LVD that have not been cleared by software.
 *
 */
LOCAL_INLINE void RGM_HWA_ClearAllResetFlagAfterPOR(void)
{
    RGM->SSRS = RGM_SSRS_ALLFLAG;
}

/**
 * @brief Read reset pin filter register
 *
 * @return Reset pin filter register
 */
LOCAL_INLINE uint32_t RGM_HWA_ReadResetPinFilterEnable(void)
{
    return (uint32_t)RGM->RSTFLT;
}

/**
 * @brief Set RSTFLT register
 *
 * @param u32Value RSTFLT register value
 */
LOCAL_INLINE void RGM_HWA_SetRstfltReg(uint32_t u32Value)
{
    RGM->RSTFLT = u32Value;
}

/**
 * @brief Set reset pin filter bus clock filter width
 *
 * @param u8Value Bus clock filter width value
 */
LOCAL_INLINE void RGM_HWA_SetBusClockFilterWidth(uint8_t u8Value)
{
    uint32_t u32RegValue = RGM->RSTFLT;
    RGM->RSTFLT = (u32RegValue & ~(uint32_t)RGM_RSTFLT_RSTFLT_BUSW_MASK) | RGM_RSTFLT_RSTFLT_BUSW(u8Value);
}

/**
 * @brief Enable reset pin filter bus clock
 *
 */
LOCAL_INLINE void RGM_HWA_EnableBusClockFilter(void)
{
    RGM->RSTFLT |= (uint32_t)RGM_RSTFLT_RSTFLT_BUS_MASK;
}

/**
 * @brief Enable reset pin filter AON32K clock
 *
 */
LOCAL_INLINE void RGM_HWA_EnableAon32kClockFilter(void)
{
    RGM->RSTFLT |= (uint32_t)RGM_RSTFLT_RSTFLT_AON_MASK;
}

/**
 * @brief Enable reset pin filter AON32K low power clock
 *
 */
LOCAL_INLINE void RGM_HWA_EnableAon32kLPClockFilter(void)
{
    RGM->RSTFLT |= (uint32_t)RGM_RSTFLT_RSTFLT_AON_LP_MASK;
}

/**
 * @brief Clear reset pin filter bus clock filter width
 *
 */
LOCAL_INLINE void RGM_HWA_ClearBusClockFilterWidth(void)
{
    RGM->RSTFLT &= ~(uint32_t)RGM_RSTFLT_RSTFLT_BUSW_MASK;
}

/**
 * @brief Disable reset pin filter bus clock
 *
 */
LOCAL_INLINE void RGM_HWA_DisableBusClockFilter(void)
{
    RGM->RSTFLT &= ~(uint32_t)RGM_RSTFLT_RSTFLT_BUS_MASK;
}

/**
 * @brief Disable reset pin filter AON32K clock
 *
 */
LOCAL_INLINE void RGM_HWA_DisableAon32kClockFilter(void)
{
    RGM->RSTFLT &= ~(uint32_t)RGM_RSTFLT_RSTFLT_AON_MASK;
}

/**
 * @brief Disable reset pin filter AON32K low power clock
 *
 */
LOCAL_INLINE void RGM_HWA_DisableAon32kLPClockFilter(void)
{
    RGM->RSTFLT &= ~(uint32_t)RGM_RSTFLT_RSTFLT_AON_LP_MASK;
}

/**
 * @brief Set SRIE register
 *
 * @param u32Value SRIE register value
 */
LOCAL_INLINE void RGM_HWA_SetSrieReg(uint32_t u32Value)
{
    RGM->SRIE = u32Value;
}

/**
 * @brief Get SRIE register
 *
 * @return SRIE register value
 */
LOCAL_INLINE uint32_t RGM_HWA_GetSrieReg(void)
{
    return RGM->SRIE;
}

/**
 * @brief Set Reset delay
 *
 * @param eDelay Reset delay type
 */
LOCAL_INLINE void RGM_HWA_SetResetDelay(RGM_ResetDelayType eDelay)
{
    uint32_t u32RegValue = RGM->SRIE;
    RGM->SRIE = (u32RegValue & ~(uint32_t)RGM_SRIE_DELAY_MASK) | RGM_SRIE_DELAY(eDelay);
}

/**
 * @brief Enable global reset interrupt
 *
 */
LOCAL_INLINE void RGM_HWA_EnableGlobalResetInterrupt(void)
{
    RGM->SRIE |= (uint32_t)RGM_SRIE_GLOBAL_RIE_MASK;
}

/**
 * @brief Enable reset interrupt
 *
 * @param eResetInterrupt Reset interrupt type
 */
LOCAL_INLINE void RGM_HWA_EnableResetInterrupt(RGM_SysResetIntMangerType eResetInterrupt)
{
    RGM->SRIE |= (uint32_t)((uint32_t)eResetInterrupt & RGM_SRIE_ALL_RIE_MASK);
}

/**
 * @brief Disable reset interrupt
 *
 * @param eResetInterrupt Reset interrupt type
 */
LOCAL_INLINE void RGM_HWA_DisableResetInterrupt(RGM_SysResetIntMangerType eResetInterrupt)
{
    RGM->SRIE &= ~(uint32_t)((uint32_t)eResetInterrupt & RGM_SRIE_ALL_RIE_MASK);
}

/**
 * @brief Get enabling status of system reset
 *
 * @return Interrupt enabling status of system reset
 */
LOCAL_INLINE uint32_t RGM_HWA_GetResetInterrupt(void)
{
    return (uint32_t)(RGM->SRIE & RGM_SRIE_ALL_RIE_MASK);
}

/**
 * @brief Perform system core reset.
 *
 */
LOCAL_INLINE void CM7_HWA_SystemCoreReset(void)
{
    __DSB();

    uint32 u32Temp;
    u32Temp = SCB->AIRCR;
    u32Temp &= ~(uint32)(SCB_AIRCR_VECTKEY_Msk);
    u32Temp |= (uint32)((((uint32_t)(((uint32_t)(0x5FAU))<<SCB_AIRCR_VECTKEY_Pos))&SCB_AIRCR_VECTKEY_Msk) |
                        SCB_AIRCR_SYSRESETREQ_Msk | SCB_AIRCR_PRIGROUP_Msk);
    SCB->AIRCR = u32Temp;

    __DSB();
}

/**
 * @brief Set C0_CFG register
 *
 * @param u32Value C0_CFG register value
 */
LOCAL_INLINE void RGM_HWA_SetC0CfgReg(uint32_t u32Value)
{
    RGM->C0_CFG = u32Value;
}

/**
 * @brief Get C0_CFG register
 *
 * @return C0_CFG register value
 */
LOCAL_INLINE uint32_t RGM_HWA_GetC0CfgReg(void)
{
    return RGM->C0_CFG;
}

/**
 * @brief Enable CPU0 interrupt
 *
 * @param u32CPU0ResetInterrupt CPU0 related interrupt type
 */
LOCAL_INLINE void RGM_HWA_EnableCPU0InterruptFlag(uint32_t u32CPU0ResetInterrupt)
{
    RGM->C0_CFG |= (uint32_t)(u32CPU0ResetInterrupt & (RGM_C0_CFG_C0_SWRST_IE_MASK | RGM_C0_CFG_C0_INTM_IE_MASK | RGM_C0_CFG_C0_WDOG_IE_MASK |
                              RGM_C0_CFG_C0_SYSRST_IE_MASK | RGM_C0_CFG_C0_LOCKUP_IE_MASK));
}

/**
 * @brief Disable CPU0 interrupt
 *
 * @param u32CPU0ResetInterrupt CPU0 related interrupt type
 */
LOCAL_INLINE void RGM_HWA_DisableCPU0InterruptFlag(uint32_t u32CPU0ResetInterrupt)
{
    RGM->C0_CFG &= ~(uint32_t)(u32CPU0ResetInterrupt & (RGM_C0_CFG_C0_SWRST_IE_MASK | RGM_C0_CFG_C0_INTM_IE_MASK | RGM_C0_CFG_C0_WDOG_IE_MASK |
                               RGM_C0_CFG_C0_SYSRST_IE_MASK | RGM_C0_CFG_C0_LOCKUP_IE_MASK));
}

/**
 * @brief Get enabling status of CPU0 core related reset
 *
 * @return Interrupt enabling status of CPU0 core related reset
 */
LOCAL_INLINE uint32_t RGM_HWA_GetCPU0ResetInterrupt(void)
{
    return (uint32_t)(RGM->C0_CFG & (RGM_C0_CFG_C0_SWRST_IE_MASK | RGM_C0_CFG_C0_INTM_IE_MASK | RGM_C0_CFG_C0_WDOG_IE_MASK |
                                     RGM_C0_CFG_C0_SYSRST_IE_MASK | RGM_C0_CFG_C0_LOCKUP_IE_MASK));
}

/**
 * @brief Get the CPU0 exit reset flag
 *
 * @return RGM_CPU_OUT_RST_UNDER CPU0 is under reset
 * @return RGM_CPU_OUT_RST_OUT CPU0 is out of reset
 */
LOCAL_INLINE RGM_CoreResetStatusType RGM_HWA_GetCPU0OutResetFlag(void)
{
    uint8_t u8TmpVal = (uint8_t)(RGM->C0_RST & RGM_C0_RST_C0_OUT_OF_RST_MASK) >> RGM_C0_RST_C0_OUT_OF_RST_SHIFT;
    return (RGM_CoreResetStatusType)u8TmpVal;
}

/**
 * @brief Issue a CPU0 system software reset.
 *
 */
LOCAL_INLINE void RGM_HWA_CPU0_SystemSoftWareReset(void)
{
    RGM->C0_RST |= (uint32_t)RGM_C0_RST_C0_SWRST_MASK;
}

/**
 * @brief Read CPU0 last reset flag
 *
 * @return CPU0 last reset flag
 */
LOCAL_INLINE uint32_t RGM_HWA_ReadCPU0LastResetFlag(void)
{
    return (uint32_t)RGM->C0_SRS;
}

/**
 * @brief Read CPU0 all reset flag before POR,SSRS register is reset on POR only
 *
 * @return CPU0 all reset flag before POR
 */
LOCAL_INLINE uint32_t RGM_HWA_ReadCPU0AllResetFlagBeforePOR(void)
{
    return (uint32_t)RGM->C0_SSRS;
}

/**
 * @brief Set C0_SSRS register
 *
 * @param u32Value C0_SSRS register value
 */
LOCAL_INLINE void RGM_HWA_SetC0SsrsReg(uint32_t u32Value)
{
    RGM->C0_SSRS = u32Value;
}

/**
 * @brief This api can clear all reset flag of SSRGM_C0_SSRSRS register which indicate all reset sources since the last POR or LVD that have not been cleared by software.
 *
 */
LOCAL_INLINE void RGM_HWA_ClearC0AllResetFlagAfterPOR(void)
{
    RGM->C0_SSRS = (uint32_t)(RGM_SSRS_ALLFLAG|RGM_C0_SSRS_C0_SWRST_MASK|
    		                  RGM_C0_SSRS_C0_INTM_MASK|RGM_C0_SSRS_C0_WDOG_MASK|
							  RGM_C0_SSRS_C0_SYSRST_MASK|RGM_C0_SSRS_C0_LOCKUP_MASK);
}

#if RGM_C1_SUPPORT
/**
 * @brief Set C1_CFG register
 *
 * @param u32Value C1_CFG register value
 */
LOCAL_INLINE void RGM_HWA_SetC1CfgReg(uint32_t u32Value)
{
    RGM->C1_CFG = u32Value;
}

/**
 * @brief Get C1_CFG register
 *
 * @return C1_CFG register value
 */
LOCAL_INLINE uint32_t RGM_HWA_GetC1CfgReg(void)
{
    return RGM->C1_CFG;
}

/**
 * @brief Enable CPU1 reset to trigger system reset
 *
 * @param eCPU1SystemReset The CPU1 reset that triggers the system reset
 */
LOCAL_INLINE void RGM_HWA_EnableCPU1SystemResetFlag(RGM_CoreRstTrigSysRstMangerType eCPU1SystemReset)
{
    RGM->C1_CFG |= (uint32_t)((uint32_t)eCPU1SystemReset & (RGM_C1_CFG_C1_LOCKUP_EN_MASK | RGM_C1_CFG_C1_SYSRST_EN_MASK | RGM_C1_CFG_C1_WDOG_EN_MASK |
                              RGM_C1_CFG_C1_INTM_EN_MASK | RGM_C1_CFG_C1_SWRST_EN_MASK));
}

/**
 * @brief Disable CPU1 reset to trigger system reset
 *
 * @param eCPU1SystemReset The CPU1 reset that triggers the system reset
 */
LOCAL_INLINE void RGM_HWA_DisableCPU1SystemResetFlag(RGM_CoreRstTrigSysRstMangerType eCPU1SystemReset)
{
    RGM->C1_CFG &= ~(uint32_t)((uint32_t)eCPU1SystemReset & (RGM_C1_CFG_C1_LOCKUP_EN_MASK | RGM_C1_CFG_C1_SYSRST_EN_MASK | RGM_C1_CFG_C1_WDOG_EN_MASK |
                               RGM_C1_CFG_C1_INTM_EN_MASK | RGM_C1_CFG_C1_SWRST_EN_MASK));
}

/**
 * @brief Enable CPU1 interrupts
 *
 * @param u32CPU1ResetInterrupt CPU1 related interrupt type
 */
LOCAL_INLINE void RGM_HWA_EnableCPU1InterruptFlag(uint32_t u32CPU1ResetInterrupt)
{
    RGM->C1_CFG |= (uint32_t)(u32CPU1ResetInterrupt & (RGM_C1_CFG_C1_SWRST_IE_MASK | RGM_C1_CFG_C1_INTM_IE_MASK | RGM_C1_CFG_C1_WDOG_IE_MASK |
                              RGM_C1_CFG_C1_SYSRST_IE_MASK | RGM_C1_CFG_C1_LOCKUP_IE_MASK));
}

/**
 * @brief Disable CPU1 interrupts
 *
 * @param u32CPU1ResetInterrupt CPU1 related interrupt type
 */
LOCAL_INLINE void RGM_HWA_DisableCPU1InterruptFlag(uint32_t u32CPU1ResetInterrupt)
{
    RGM->C1_CFG &= ~(uint32_t)(u32CPU1ResetInterrupt & (RGM_C1_CFG_C1_SWRST_IE_MASK | RGM_C1_CFG_C1_INTM_IE_MASK | RGM_C1_CFG_C1_WDOG_IE_MASK |
                               RGM_C1_CFG_C1_SYSRST_IE_MASK | RGM_C1_CFG_C1_LOCKUP_IE_MASK));
}

/**
 * @brief Get the status of CPU1 core related reset configured as system reset
 *
 * @return CPU1 core related reset configured as system reset
 */
LOCAL_INLINE uint32_t RGM_HWA_GetCPU1SystemResetFlag(void)
{
    return (uint32_t)(RGM->C1_CFG & (RGM_C1_CFG_C1_LOCKUP_EN_MASK | RGM_C1_CFG_C1_SYSRST_EN_MASK | RGM_C1_CFG_C1_WDOG_EN_MASK |
                                     RGM_C1_CFG_C1_INTM_EN_MASK | RGM_C1_CFG_C1_SWRST_EN_MASK));
}

/**
 * @brief Get enabling status of CPU1 core related reset interrupt
 *
 * @return Interrupt enabling status of CPU1 core related reset
 */
LOCAL_INLINE uint32_t RGM_HWA_GetCPU1ResetInterrupt(void)
{
    return (uint32_t)(RGM->C1_CFG & (RGM_C1_CFG_C1_SWRST_IE_MASK | RGM_C1_CFG_C1_INTM_IE_MASK | RGM_C1_CFG_C1_WDOG_IE_MASK |
                                     RGM_C1_CFG_C1_SYSRST_IE_MASK | RGM_C1_CFG_C1_LOCKUP_IE_MASK));
}

/**
 * @brief Get the CPU1 exit reset flag
 *
 * @return RGM_CPU_OUT_RST_UNDER CPU1 is under reset
 * @return RGM_CPU_OUT_RST_OUT CPU1 is out of reset
 */
LOCAL_INLINE RGM_CoreResetStatusType RGM_HWA_GetCPU1OutResetFlag(void)
{
    uint8_t u8TmpVal = (uint8_t)(RGM->C1_RST & RGM_C1_RST_C1_OUT_OF_RST_MASK) >> RGM_C1_RST_C1_OUT_OF_RST_SHIFT;
    return (RGM_CoreResetStatusType)u8TmpVal;
}

/**
 * @brief Issue a CPU1 system software reset.
 *
 */
LOCAL_INLINE void RGM_HWA_CPU1_SystemSoftWareReset(void)
{
    RGM->C1_RST |= (uint32_t)RGM_C1_RST_C1_SWRST_MASK;
}

/**
 * @brief Read CPU1 last reset flag
 *
 * @return CPU1 last reset flag
 */
LOCAL_INLINE uint32_t RGM_HWA_ReadCPU1LastResetFlag(void)
{
    return (uint32_t)RGM->C1_SRS;
}

/**
 * @brief Release CPU1. After writing, this bit will be locked
 *
 */
LOCAL_INLINE void RGM_HWA_ReleaseCPU1(void)
{
    RGM->C1_RLS |= (uint32_t)RGM_C1_RLS_C1_RELEASE_MASK;
}

/**
 * @brief Get the CPU1 reset interrupt flag
 *
 * @return true CPU1 reset interrupt happens
 * @return false CPU1 reset interrupt not happened or cleared
 */
LOCAL_INLINE bool RGM_HWA_GetCPU1IntFlag(void)
{
    uint32_t u32TmpVal = (RGM->C1_RIC & RGM_C1_RIC_C1_RIC_RST_MASK) >> RGM_C1_RIC_C1_RIC_RST_SHIFT;
    return (bool)((u32TmpVal != 0U) ? true : false);
}

/**
 * @brief Clear the CPU1 reset interrupt flag
 *
 */
LOCAL_INLINE void RGM_HWA_ClearCPU1IntFlag(void)
{
    RGM->C1_RIC |= (uint32_t)RGM_C1_RIC_C1_RIC_RST_MASK;
}

/**
 * @brief Set whether to enable CPU1 reset interrupt to CPU0
 *
 * @param bEnable whether to enable CPU1 reset interrupt to CPU0
 */
LOCAL_INLINE void RGM_HWA_SetC1IntToC0EnableFlag(bool bEnable)
{
    RGM->C1_RIC = (RGM->C1_RIC & ~RGM_C1_RIC_C1_RIC_TOC0_MASK) | RGM_C1_RIC_C1_RIC_TOC0(bEnable);
}

/**
 * @brief Read CPU1 all reset flag before POR,SSRS register is reset on POR only
 *
 * @return CPU1 all reset flag before POR
 */
LOCAL_INLINE uint32_t RGM_HWA_ReadCPU1AllResetFlagBeforePOR(void)
{
    return (uint32_t)RGM->C1_SSRS;
}

/**
 * @brief Set C1_SSRS register
 *
 * @param u32Value C1_SSRS register value
 */
LOCAL_INLINE void RGM_HWA_SetC1SsrsReg(uint32_t u32Value)
{
    RGM->C1_SSRS = u32Value;
}

/**
 * @brief This api can clear all reset flag of SSRGM_C1_SSRSRS register which indicate all reset sources since the last POR or LVD that have not been cleared by software.
 *
 */
LOCAL_INLINE void RGM_HWA_ClearC1AllResetFlagAfterPOR(void)
{
    RGM->C1_SSRS = (uint32_t)(RGM_SSRS_ALLFLAG|RGM_C1_SSRS_C1_SWRST_MASK|
                              RGM_C1_SSRS_C1_INTM_MASK|RGM_C1_SSRS_C1_WDOG_MASK|
			                  RGM_C1_SSRS_C1_SYSRST_MASK|RGM_C1_SSRS_C1_LOCKUP_MASK);
}
#endif

#if RGM_C2_SUPPORT

/**
 * @brief Set C2_CFG register
 *
 * @param u32Value C2_CFG register value
 */
LOCAL_INLINE void RGM_HWA_SetC2CfgReg(uint32_t u32Value)
{
    RGM->C2_CFG = u32Value;
}

/**
 * @brief Get C2_CFG register
 *
 * @return C2_CFG register value
 */
LOCAL_INLINE uint32_t RGM_HWA_GetC2CfgReg(void)
{
    return RGM->C2_CFG;
}

/**
 * @brief Enable CPU2 reset to trigger system reset
 *
 * @param eCPU2SystemReset The CPU2 reset that triggers the system reset
 */
LOCAL_INLINE void RGM_HWA_EnableCPU2SystemResetFlag(RGM_CoreRstTrigSysRstMangerType eCPU2SystemReset)
{
    RGM->C2_CFG |= (uint32_t)((uint32_t)eCPU2SystemReset & (RGM_C2_CFG_C2_LOCKUP_EN_MASK | RGM_C2_CFG_C2_SYSRST_EN_MASK | RGM_C2_CFG_C2_WDOG_EN_MASK |
                              RGM_C2_CFG_C2_INTM_EN_MASK | RGM_C2_CFG_C2_SWRST_EN_MASK));
}

/**
 * @brief Disable CPU2 reset to trigger system reset
 *
 * @param eCPU2SystemReset The CPU2 reset that triggers the system reset
 */
LOCAL_INLINE void RGM_HWA_DisableCPU2SystemResetFlag(RGM_CoreRstTrigSysRstMangerType eCPU2SystemReset)
{
    RGM->C2_CFG &= ~(uint32_t)((uint32_t)eCPU2SystemReset & (RGM_C2_CFG_C2_LOCKUP_EN_MASK | RGM_C2_CFG_C2_SYSRST_EN_MASK | RGM_C2_CFG_C2_WDOG_EN_MASK |
                               RGM_C2_CFG_C2_INTM_EN_MASK | RGM_C2_CFG_C2_SWRST_EN_MASK));
}

/**
 * @brief Enable CPU2 interrupt
 *
 * @param u32CPU2ResetInterrupt CPU2 related interrupt type
 */
LOCAL_INLINE void RGM_HWA_EnableCPU2InterruptFlag(uint32_t u32CPU2ResetInterrupt)
{
    RGM->C2_CFG |= (uint32_t)(u32CPU2ResetInterrupt & (RGM_C2_CFG_C2_SWRST_IE_MASK | RGM_C2_CFG_C2_INTM_IE_MASK | RGM_C2_CFG_C2_WDOG_IE_MASK |
                              RGM_C2_CFG_C2_SYSRST_IE_MASK | RGM_C2_CFG_C2_LOCKUP_IE_MASK));
}

/**
 * @brief Disable CPU2 interrupts
 *
 * @param u32CPU2ResetInterrupt CPU2 related interrupt type
 */
LOCAL_INLINE void RGM_HWA_DisableCPU2InterruptFlag(uint32_t u32CPU2ResetInterrupt)
{
    RGM->C2_CFG &= ~(uint32_t)(u32CPU2ResetInterrupt & (RGM_C2_CFG_C2_SWRST_IE_MASK | RGM_C2_CFG_C2_INTM_IE_MASK | RGM_C2_CFG_C2_WDOG_IE_MASK |
                               RGM_C2_CFG_C2_SYSRST_IE_MASK | RGM_C2_CFG_C2_LOCKUP_IE_MASK));
}

/**
 * @brief Get the status of CPU2 core related reset configured as system reset
 *
 * @return CPU2 core related reset configured as system reset
 */
LOCAL_INLINE uint32_t RGM_HWA_GetCPU2SystemResetFlag(void)
{
    return (uint32_t)(RGM->C2_CFG & (RGM_C2_CFG_C2_LOCKUP_EN_MASK | RGM_C2_CFG_C2_SYSRST_EN_MASK | RGM_C2_CFG_C2_WDOG_EN_MASK |
                                     RGM_C2_CFG_C2_INTM_EN_MASK | RGM_C2_CFG_C2_SWRST_EN_MASK));
}

/**
 * @brief Get enabling status of CPU2 core related reset interrupt
 *
 * @return Interrupt enabling status of CPU2 core related reset
 */
LOCAL_INLINE uint32_t RGM_HWA_GetCPU2ResetInterrupt(void)
{
    return (uint32_t)(RGM->C2_CFG & (RGM_C2_CFG_C2_SWRST_IE_MASK | RGM_C2_CFG_C2_INTM_IE_MASK | RGM_C2_CFG_C2_WDOG_IE_MASK |
                                     RGM_C2_CFG_C2_SYSRST_IE_MASK | RGM_C2_CFG_C2_LOCKUP_IE_MASK));
}

/**
 * @brief Get the CPU2 exit reset flag
 *
 * @return RGM_CPU_OUT_RST_UNDER CPU2 is under reset
 * @return RGM_CPU_OUT_RST_OUT CPU2 is out of reset
 */
LOCAL_INLINE RGM_CoreResetStatusType RGM_HWA_GetCPU2OutResetFlag(void)
{
    uint8_t u8TmpVal = (uint8_t)(RGM->C2_RST & RGM_C2_RST_C2_OUT_OF_RST_MASK) >> RGM_C2_RST_C2_OUT_OF_RST_SHIFT;
    return (RGM_CoreResetStatusType)u8TmpVal;
}

/**
 * @brief Issue a CPU2 software reset.
 *
 */
LOCAL_INLINE void RGM_HWA_CPU2_SystemSoftWareReset(void)
{
    RGM->C2_RST |= (uint32_t)RGM_C2_RST_C2_SWRST_MASK;
}

/**
 * @brief Read CPU2 last reset flag
 *
 * @return CPU2 last reset flag
 */
LOCAL_INLINE uint32_t RGM_HWA_ReadCPU2LastResetFlag(void)
{
    return (uint32_t)RGM->C2_SRS;
}

/**
 * @brief Release CPU2. After writing, this bit will be locked
 *
 */
LOCAL_INLINE void RGM_HWA_ReleaseCPU2(void)
{
    RGM->C2_RLS |= (uint32_t)RGM_C2_RLS_C2_RELEASE_MASK;
}

/**
 * @brief Get the CPU2 reset interrupt flag
 *
 * @return true CPU2 reset interrupt happens
 * @return false CPU2 reset interrupt not happened or cleared
 */
LOCAL_INLINE bool RGM_HWA_GetCPU2IntFlag(void)
{
    uint32_t u32TmpVal = (RGM->C2_RIC & RGM_C2_RIC_C2_RIC_RST_MASK) >> RGM_C2_RIC_C2_RIC_RST_SHIFT;
    return (bool)((u32TmpVal != 0U) ? true : false);
}

/**
 * @brief Clear the CPU2 reset interrupt flag
 *
 */
LOCAL_INLINE void RGM_HWA_ClearCPU2IntFlag(void)
{
    RGM->C2_RIC |= (uint32_t)RGM_C2_RIC_C2_RIC_RST_MASK;
}

/**
 * @brief Set whether to enable CPU2 reset interrupt to CPU0
 *
 */
LOCAL_INLINE void RGM_HWA_SetC2IntToC0EnableFlag(bool bEnable)
{
    RGM->C2_RIC = (RGM->C2_RIC & ~RGM_C2_RIC_C2_RIC_TOC0_MASK) | RGM_C2_RIC_C2_RIC_TOC0(bEnable);
}

/**
 * @brief Set whether to enable CPU2 reset interrupt to CPU1
 *
 */
LOCAL_INLINE void RGM_HWA_SetC2IntToC1EnableFlag(bool bEnable)
{
    RGM->C2_RIC = (RGM->C2_RIC & ~RGM_C2_RIC_C2_RIC_TOC13_MASK) | RGM_C2_RIC_C2_RIC_TOC13(bEnable);
}

/**
 * @brief Set whether to enable CPU1 reset interrupt to CPU2
 *
 * @param bEnable whether to enable CPU1 reset interrupt to CPU2
 */
LOCAL_INLINE void RGM_HWA_SetC1IntToC2EnableFlag(bool bEnable)
{
    RGM->C1_RIC = (RGM->C1_RIC & ~RGM_C1_RIC_C1_RIC_TOC23_MASK) | RGM_C1_RIC_C1_RIC_TOC23(bEnable);
}

/**
 * @brief Read CPU2 all reset flag before POR,SSRS register is reset on POR only
 *
 * @return CPU2 all reset flag before POR
 */
LOCAL_INLINE uint32_t RGM_HWA_ReadCPU2AllResetFlagBeforePOR(void)
{
    return (uint32_t)RGM->C2_SSRS;
}

/**
 * @brief Set C2_SSRS register
 *
 * @param u32Value C2_SSRS register value
 */
LOCAL_INLINE void RGM_HWA_SetC2SsrsReg(uint32_t u32Value)
{
    RGM->C2_SSRS = u32Value;
}

/**
 * @brief This api can clear all reset flag of SSRGM_C2_SSRSRS register which indicate all reset sources since the last POR or LVD that have not been cleared by software.
 *
 */
LOCAL_INLINE void RGM_HWA_ClearC2AllResetFlagAfterPOR(void)
{
    RGM->C2_SSRS = (uint32_t)(RGM_SSRS_ALLFLAG|RGM_C2_SSRS_C2_SWRST_MASK|
                              RGM_C2_SSRS_C2_INTM_MASK|RGM_C2_SSRS_C2_WDOG_MASK|
                              RGM_C2_SSRS_C2_SYSRST_MASK|RGM_C2_SSRS_C2_LOCKUP_MASK);
}
#endif

#if RGM_C3_SUPPORT
/**
 * @brief Set PORSW Key register
 *
 * @param u32Value PORSW register value
 */
LOCAL_INLINE void RGM_HWA_SetPORSWKEY(uint32_t u32Value)
{
    RGM->PORSW = (RGM->PORSW & ~RGM_PORSW_KEY_MASK) | RGM_PORSW_KEY(u32Value);
}

/**
 * @brief Set PORSW SWE register
 *
 * @param u8Value PORSW SWE register value
 */
LOCAL_INLINE void RGM_HWA_SetPORSWSWE(uint8_t u8Value)
{
    RGM->PORSW = (RGM->PORSW & ~RGM_PORSW_SWE_MASK) | RGM_PORSW_SWE(u8Value);
}

/**
 * @brief Get PORSW SWE register
 *
 * @return PORSW SWE register value
 */
LOCAL_INLINE uint32_t RGM_HWA_GetPORSWSWE(void)
{
    uint32_t u32Value = (RGM->PORSW | RGM_PORSW_SWE_MASK) >> RGM_PORSW_SWE_SHIFT;
    return u32Value;
}

/**
 * @brief Set C3_CFG register
 *
 * @param u32Value C3_CFG register value
 */
LOCAL_INLINE void RGM_HWA_SetC3CfgReg(uint32_t u32Value)
{
    RGM->C3_CFG = u32Value;
}

/**
 * @brief Get C3_CFG register
 *
 * @return C3_CFG register value
 */
LOCAL_INLINE uint32_t RGM_HWA_GetC3CfgReg(void)
{
    return RGM->C3_CFG;
}

/**
 * @brief Enable CPU3 reset to trigger system reset
 *
 * @param eCPU3SystemReset The CPU3 reset that triggers the system reset
 */
LOCAL_INLINE void RGM_HWA_EnableCPU3SystemResetFlag(RGM_CoreRstTrigSysRstMangerType eCPU3SystemReset)
{
    RGM->C3_CFG |= (uint32_t)((uint32_t)eCPU3SystemReset & (RGM_C3_CFG_C3_LOCKUP_EN_MASK | RGM_C3_CFG_C3_SYSRST_EN_MASK | RGM_C3_CFG_C3_WDOG_EN_MASK |
                              RGM_C3_CFG_C3_INTM_EN_MASK | RGM_C3_CFG_C3_SWRST_EN_MASK));
}

/**
 * @brief Disable CPU3 reset to trigger system reset
 *
 * @param eCPU3SystemReset The CPU3 reset that triggers the system reset
 */
LOCAL_INLINE void RGM_HWA_DisableCPU3SystemResetFlag(RGM_CoreRstTrigSysRstMangerType eCPU3SystemReset)
{
    RGM->C3_CFG &= ~(uint32_t)((uint32_t)eCPU3SystemReset & (RGM_C3_CFG_C3_LOCKUP_EN_MASK | RGM_C3_CFG_C3_SYSRST_EN_MASK | RGM_C3_CFG_C3_WDOG_EN_MASK |
                               RGM_C3_CFG_C3_INTM_EN_MASK | RGM_C3_CFG_C3_SWRST_EN_MASK));
}

/**
 * @brief Enable CPU3 interrupt
 *
 * @param u32CPU3ResetInterrupt CPU3 related interrupt type
 */
LOCAL_INLINE void RGM_HWA_EnableCPU3InterruptFlag(uint32_t u32CPU3ResetInterrupt)
{
    RGM->C3_CFG |= (uint32_t)(u32CPU3ResetInterrupt & (RGM_C3_CFG_C3_SWRST_IE_MASK | RGM_C3_CFG_C3_INTM_IE_MASK | RGM_C3_CFG_C3_WDOG_IE_MASK |
                              RGM_C3_CFG_C3_SYSRST_IE_MASK | RGM_C3_CFG_C3_LOCKUP_IE_MASK));
}

/**
 * @brief Disable CPU3 interrupts
 *
 * @param u32CPU3ResetInterrupt CPU3 related interrupt type
 */
LOCAL_INLINE void RGM_HWA_DisableCPU3InterruptFlag(uint32_t u32CPU3ResetInterrupt)
{
    RGM->C3_CFG &= ~(uint32_t)(u32CPU3ResetInterrupt & (RGM_C3_CFG_C3_SWRST_IE_MASK | RGM_C3_CFG_C3_INTM_IE_MASK | RGM_C3_CFG_C3_WDOG_IE_MASK |
                               RGM_C3_CFG_C3_SYSRST_IE_MASK | RGM_C3_CFG_C3_LOCKUP_IE_MASK));
}

/**
 * @brief Get the status of CPU3 core related reset configured as system reset
 *
 * @return CPU3 core related reset configured as system reset
 */
LOCAL_INLINE uint32_t RGM_HWA_GetCPU3SystemResetFlag(void)
{
    return (uint32_t)(RGM->C3_CFG & (RGM_C3_CFG_C3_LOCKUP_EN_MASK | RGM_C3_CFG_C3_SYSRST_EN_MASK | RGM_C3_CFG_C3_WDOG_EN_MASK |
                                     RGM_C3_CFG_C3_INTM_EN_MASK | RGM_C3_CFG_C3_SWRST_EN_MASK));
}

/**
 * @brief Get enabling status of CPU3 core related reset interrupt
 *
 * @return Interrupt enabling status of CPU3 core related reset
 */
LOCAL_INLINE uint32_t RGM_HWA_GetCPU3ResetInterrupt(void)
{
    return (uint32_t)(RGM->C3_CFG & (RGM_C3_CFG_C3_SWRST_IE_MASK | RGM_C3_CFG_C3_INTM_IE_MASK | RGM_C3_CFG_C3_WDOG_IE_MASK |
                                     RGM_C3_CFG_C3_SYSRST_IE_MASK | RGM_C3_CFG_C3_LOCKUP_IE_MASK));
}

/**
 * @brief Get the CPU3 exit reset flag
 *
 * @return RGM_CPU_OUT_RST_UNDER CPU3 is under reset
 * @return RGM_CPU_OUT_RST_OUT CPU3 is out of reset
 */
LOCAL_INLINE RGM_CoreResetStatusType RGM_HWA_GetCPU3OutResetFlag(void)
{
    uint8_t u8TmpVal = (uint8_t)(RGM->C3_RST & RGM_C3_RST_C3_OUT_OF_RST_MASK) >> RGM_C3_RST_C3_OUT_OF_RST_SHIFT;
    return (RGM_CoreResetStatusType)u8TmpVal;
}

/**
 * @brief Issue a CPU3 software reset.
 *
 */
LOCAL_INLINE void RGM_HWA_CPU3_SystemSoftWareReset(void)
{
    RGM->C3_RST |= (uint32_t)RGM_C3_RST_C3_SWRST_MASK;
}

/**
 * @brief Read CPU3 last reset flag
 *
 * @return CPU3 last reset flag
 */
LOCAL_INLINE uint32_t RGM_HWA_ReadCPU3LastResetFlag(void)
{
    return (uint32_t)RGM->C3_SRS;
}

/**
 * @brief Release CPU3. After writing, this bit will be locked
 *
 */
LOCAL_INLINE void RGM_HWA_ReleaseCPU3(void)
{
    RGM->C3_RLS |= (uint32_t)RGM_C3_RLS_C3_RELEASE_MASK;
}

/**
 * @brief Get the CPU3 reset interrupt flag
 *
 * @return true CPU3 reset interrupt happens
 * @return false CPU3 reset interrupt not happened or cleared
 */
LOCAL_INLINE bool RGM_HWA_GetCPU3IntFlag(void)
{
    uint32_t u32TmpVal = (RGM->C3_RIC & RGM_C3_RIC_C3_RIC_RST_MASK) >> RGM_C3_RIC_C3_RIC_RST_SHIFT;
    return (bool)((u32TmpVal != 0U) ? true : false);
}

/**
 * @brief Clear the CPU3 reset interrupt flag
 *
 */
LOCAL_INLINE void RGM_HWA_ClearCPU3IntFlag(void)
{
    RGM->C3_RIC |= (uint32_t)RGM_C3_RIC_C3_RIC_RST_MASK;
}

/**
 * @brief Set whether to enable CPU3 reset interrupt to CPU1
 *
 */
LOCAL_INLINE void RGM_HWA_SetC3IntToC12EnableFlag(bool bEnable)
{
    RGM->C3_RIC = (RGM->C3_RIC & ~RGM_C3_RIC_C3_RIC_TOC12_MASK) | RGM_C3_RIC_C3_RIC_TOC12(bEnable);
}

/**
 * @brief Set whether to enable CPU3 reset interrupt to CPU0
 *
 */
LOCAL_INLINE void RGM_HWA_SetC3IntToC0EnableFlag(bool bEnable)
{
    RGM->C3_RIC = (RGM->C3_RIC & ~RGM_C3_RIC_C3_RIC_TOC0_MASK) | RGM_C3_RIC_C3_RIC_TOC0(bEnable);
}

/**
 * @brief Read CPU3 all reset flag before POR,SSRS register is reset on POR only
 *
 * @return CPU3 all reset flag before POR
 */
LOCAL_INLINE uint32_t RGM_HWA_ReadCPU3AllResetFlagBeforePOR(void)
{
    return (uint32_t)RGM->C3_SSRS;
}

/**
 * @brief Set C3_SSRS register
 *
 * @param u32Value C3_SSRS register value
 */
LOCAL_INLINE void RGM_HWA_SetC3SsrsReg(uint32_t u32Value)
{
    RGM->C3_SSRS = u32Value;
}

/**
 * @brief This api can clear all reset flag of SSRGM_C3_SSRSRS register which indicate all reset sources since the last POR or LVD that have not been cleared by software.
 *
 */
LOCAL_INLINE void RGM_HWA_ClearC3AllResetFlagAfterPOR(void)
{
    RGM->C3_SSRS = (uint32_t)0xE01FF9FFU;
}
#endif


/** @}*/

#endif /* #if RGM_INSTANCE_COUNT > 0U */

#endif /* #ifndef _HWA_RGM_H_ */
