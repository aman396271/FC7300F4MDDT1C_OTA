/**
 * @file module_driver_stcu.c
 * @author Flagchip
 * @brief FC7xxx STCU driver type definition and API
 * @version 2.0.0
 * @date 2024-09-03
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
   *   0.1.0       2023-12-15    Flagchip054   N/A          First version for FC7300
   *   2.0.0       2024-10-12    Flagchip054   N/A          Change version and release
   ******************************************************************************** */

#ifndef _DRIVER_MODULE_DRIVER_STCU_H_
#define _DRIVER_MODULE_DRIVER_STCU_H_

#include "HwA_stcu.h"

/** @brief STCU self test status flag */
typedef enum
{
    STCU_SELFTEST_NONE            = 0x00U,       /**<! No any status flag. >*/
    STCU_SELFTEST_DONE            = 0x01U,       /**<! Self-test Done Flag. >*/
    STCU_SELFTEST_ABORT           = 0x02U,       /**<! Self-test Abort Flag. >*/
    STCU_SELFTEST_LBIST_ERROR     = 0x10U,       /**<! LBIST Error Flag. >*/
    STCU_SELFTEST_MBIST_ERROR     = 0x20U,       /**<! MBIST Error Flag. >*/
    STCU_SELFTEST_TIMEOUT_ERROR   = 0x40U,       /**<! Self-test Timeout Error Flag. >*/
    STCU_SELFTEST_NVRLOAD_ERROR   = 0x100U,      /**<! NVR Load Error Flag. >*/
    STCU_SELFTEST_SELFCHECK_ERROR = 0x200u       /**<! STCU Self Check Error Flag. >*/
}STCU_SelfTestStatusType;

/** @brief STCU interrupt flag */
typedef enum
{
    STCU_INTERRUPT_FLAG_NONE            = 0x00U,   /**<! No any Interrupt flag. >*/
	STCU_INTERRUPT_FLAG_SIZE_ERR        = 0x01U,   /**<! STCU Register Access Size Error IRQ Flag. >*/
	STCU_INTERRUPT_FLAG_SEQ_ERR         = 0x02U,   /**<! Illegal Register Access Sequence IRQ Flag. >*/
}STCU_InterruptFlagType;

/** @brief Hardware SRAM initialization mode. */
typedef enum
{
    STCU_INIT_RAM_MODE_POR_OR_WAKEUP4STANDBY0 = 0U,   /**<! After POR or wakeup from STANDBY0, Hardware SRAM initialization. >*/
    STCU_INIT_RAM_MODE_AFTER_WAKEUP4STANDBY1,         /**<! After wakeup from STANDBY1, Hardware SRAM initialization. >*/
    STCU_INIT_RAM_MODE_AFTER_WAKEUP4STANDBY2,         /**<! After wakeup from STANDBY2, Hardware SRAM initialization. >*/
    STCU_INIT_RAM_MODE_AFTER_WAKEUP4STANDBY3          /**<! After wakeup from STANDBY3, Hardware SRAM initialization. >*/
}STCU_InitRamModeType;

/** @brief Init Ram status flag. */
typedef enum
{
    STCU_HARDWARE_INIT_RAM_STATUS_NONE  = 0U,        /**<! No any SRAN Initialization flag. >*/
    STCU_HARDWARE_INIT_RAM_STATUS_DONE  = 1U,        /**<! Hardware SRAM Initialization Done Flag. >*/
    STCU_HARDWARE_INIT_RAM_STATUS_BUSY  = 2U,        /**<! Hardware SRAM Initialization Busy Flag. >*/
    STCU_HARDWARE_INIT_RAM_STATUS_ABORT = 4U         /**<! Hardware SRAM Initialization Abort Flag. >*/
}STCU_HardwareInitRamStatusType;

/** @brief LBIST status flag. */
typedef enum
{
    STCU_LBIST_STATUS_NONE   = 0U,       /**<! No any LBIST flag. >*/
    STCU_LBIST_STATUS_DONE   = 1U,       /**<! LBIST Done Flag. >*/
    STCU_LBIST_STATUS_FAILED = 2U        /**<! LBIST Fail Flag. >*/
}STCU_LbistStatusType;

/** @brief LBIST Clock Divider. */
typedef enum
{
    STCU_LBIST_CLK_DIVIDER_BY_2 = 1U,     /**<! LBIST clock is Divided by 2. >*/
    STCU_LBIST_CLK_DIVIDER_BY_3 = 2U,     /**<! LBIST clock is Divided by 3. >*/
    STCU_LBIST_CLK_DIVIDER_BY_4 = 3U,     /**<! LBIST clock is Divided by 4. >*/
}STCU_LbistClkDivType;

/** @brief clock source of self-test. */
typedef enum
{
    STCU_CLK_SOURCE_FIRC = 0U,     /**<! FIRC clock source. >*/
	STCU_CLK_SOURCE_PLL  = 1U      /**<! PLL clock source. >*/
}STCU_ClkSourceType;

/** @brief Self-test Port Pull Selection. */
typedef enum
{
    STCU_PORT_PULL_DISABLE = 0U,   /**<! Disable self test port pull function. >*/
	STCU_PORT_PULL_DOWN,           /**<! self test port pull down. >*/
	STCU_PORT_PULL_UP              /**<! self test port pull up. >*/
}STCU_PortPullModeType;

/** @brief Stcu call back function type, the u32status should refer to "STCU_InterruptFlagType" */
typedef void (*Stcu_IRQCallback)(uint32_t u32Status);

typedef struct
{
    bool                  bLbistEn;            /**<! LBIST Enable >*/
	bool                  bMbistLPC;           /**<! MBIST Low Power Control Enable >*/
    bool                  bMbistEn;            /**<! MBIST Enable >*/
    bool                  bMbistFullTest;      /**<! MBIST Full test Enable >*/
    bool                  bMbistSramInit;      /**<! Enable SRAM initialization at the end of power on self-test. >*/
    bool                  bInterruptEn;        /**<! STCU Interrupt Enable >*/
    STCU_PortPullModeType ePortPullMode;       /**<! Self-test Port Pull Selection >*/
    STCU_ClkSourceType    eClkSource;          /**<! Select the clock source of self-test >*/
    STCU_LbistClkDivType  eLbistClkDivider;    /**<! LBIST Clock Divider Control. Note:A slower LBIST clock will cause less power consumption but a longer test time. >*/
    uint16_t              u16MaxTime;          /**<! The maximum time allowed for self-test execution.(unit : ms) >*/
    uint32_t              u32MbistSel;         /**<! Refer to "STCU_MbistSelType", use OR to select the MBIST range. */
    Stcu_IRQCallback      pIrqCallback;        /**<! Callback function for STCU IRQ >*/
}STCU_ConfigType;


typedef struct
{
    uint8_t                  initMode;        /**< RAM Initial Mode */
    uint8_t                  bLockAfterEn;     /**< Lock STCU after RAM Initial */
    uint32_t                 u32InitRamType;   /**< RAM Type, DTCM, ITCM, SRAM, refer to "STCU_InitRamType" and use OR to combine them */
}STCU_InitRamConfigType;


/**
 * \brief Init the STCU module
 *
 * \param pConfig the configuration structure
 */
void STCU_Init(STCU_ConfigType *pConfig);

/**
 * \brief Trigger to start Software self test
 *
 */
void STCU_StartSelfTest(void);

/**
 * \brief Check Software Trigger Self-test result
 *
 * \return refer to "STCU_SelfTestStatusType" enum.
 */
uint32_t STCU_CheckTriggerResult(void);

/**
 * \brief Initial RAM with hardware
 *
 * \param pConfig the configuration structure
 */
void STCU_StartRamInit(STCU_InitRamConfigType *pInitCfg);

/**
 * \brief Get status of RAM initialize action
 *
 * \return the status of ram initialize action, refer to "STCU_HardwareInitRamStatusType"
 */
uint32_t STCU_GetRamInitStatus(void);

/**
 * \brief Get if the LBIST test result is Fail
 *
 * \return true means LBIST fail. false means LBIST pass.
 */
bool STCU_GetLbistFailResult(void);
/**
 * \brief Get each MBIST Fail result
 *
 * \return refer to "STCU_MbistFailedType" enum.
 */
uint32_t STCU_GetMbistFailResult(void);

/**
 * \brief Get each done status of SRAM initialize
 *
 * \return the done status of SRAM initialize action, refer to "STCU_InitRamDoneType"
 */
uint32_t STCU_GetRamInitDoneStatus(void);

/**
 * \brief Set the LBIST Pattern value and expected misr value.
 *        The two value should be load from NVR, but also can reconfigure by this API.
 *        The expected misr value is calculated from pattern, so please make sure this two value is right, or the LBST would fail.
 *
 * \param u16Pattern the LBIST Pattern value
 * \param u16Pattern the LBIST expected misr value
 */
void STCU_LBIST_Set_Pattern_Misr(uint16_t u16Pattern, uint32_t u32ExpectedMisr);

/**
 * \brief Get LBIST actual MISR value, the value should be read and use DFT tool to decode it, if LBIST test resault is fail.
 *
 * \return the LBIST actual MISR value
 */
uint32_t STCU_GetLbistAcutalMisr(void);

/**
 * @brief STCU 0 interrupt handler
 *
 * @note This function should be called as/in STCU 0 interrupt handler
 */
void STCU0_IRQHandler(void);
#endif /* end of _DRIVER_MODULE_DRIVER_STCU_H_ */
