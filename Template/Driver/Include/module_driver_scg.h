/**
 * @file module_driver_scg.h
 * @author Flagchip
 * @brief SCG driver type definition and API
 * @version 2.0.0
 * @date 2024-08-20
 *
 * SDK Version: 2.6.0
 *

 * @copyright Copyright (c) 2020-2024 Flagchip Semiconductors Co., Ltd.
 *
 */
/* ********************************************************************************
   *   Revision History:
   *
   *   Version     Date          Initials      CR#          Descriptions
   *   ---------   ----------    ------------  ----------   ---------------
   *   0.1.0       2023-12-15    Flagchip055   N/A          First version for FC7300
   *   2.0.0       2024-10-12    Flagchip055   N/A          Change version and release
   ******************************************************************************** */

#ifndef _DRIVER_MODULE_DRIVER_SCG_H_
#define _DRIVER_MODULE_DRIVER_SCG_H_

#include "HWA_scg.h"

#if SCG_INSTANCE_COUNT > 0U

/**
 * @addtogroup module_driver_scg
 * @{
 */
#ifndef SCG_DEV_ERROR_REPORT
#define SCG_DEV_ERROR_REPORT	STD_OFF
#endif

#if SCG_DEV_ERROR_REPORT == STD_ON
#define SCG_ReportDevError(func, error) ReportDevError(SCG_MODULE_ID, func, error)
#endif

/**
 * @name  SCG API Service IDs
 *
 */
#define SCG_SET_SIRC_ID   		  0x00U
#define SCG_ENABLE_SIRC32K_ID     0x01U
#define SCG_ENABLE_FIRC_ID   	  0x02U
#define SCG_ENABLE_FOSC_ID        0x03U
#define SCG_ENABLE_SOSC_ID        0x04U
#define SCG_ENABLE_PLL_ID  	      0x05U
#define SCG_SET_CLOCK_CTRL_ID     0x06U
#define SCG_SET_CLOCK_OUT_ID      0x07U
#define SCG_SWITCH_SYS_CLOCK_ID   0x08U
#define SCG_GET_SCG_CLOCK_FREQ_ID 0x09U
#define SCG_SCG_DEINIT_ID         0x0AU
#define SCG_SCG_INTERRUPT_INIT_ID 0x0BU
/** @}*/

/**
 * @name  SCG Dev Error Code
 * @brief Error Code of calling SCG apis
 *
 */
#define SCG_E_PARAM_POINTER        0x01U
#define SCG_E_PARAM_OUT_RANGE      0x02U
/** @}*/

/******************* Oscillator Values *******************/
/**
  * @brief Fast OSC frequency
  */
#ifndef FOSC_FREQUENCY
#define FOSC_FREQUENCY   24000000U
#endif

/**
  * @brief Slow OSC frequency
  */
#ifndef SOSC_FREQUENCY
#define SOSC_FREQUENCY   32768U
#endif

/**
  * @brief FTU input TCLK frequency
  */
#ifndef PCC_FTU_TCLK_FREQ
#define PCC_FTU_TCLK_FREQ   0U
#endif

#define UNKNOWN_CLOCK    0xFFFFFFFFU

#define SCG_CORE_CLOCK_SYMBOL CORE
#define SCG_BUS_CLOCK_SYMBOL BUS
#define SCG_SLOW_CLOCK_SYMBOL SLOW
#define SCG_SIRC_CLOCK_SYMBOL SIRC
#define SCG_SIRC32K_CLOCK_SYMBOL SIRC32K
#define SCG_FIRC_CLOCK_SYMBOL FIRC
#define SCG_FOSC_CLOCK_SYMBOL FOSC
#define SCG_SOSC_CLOCK_SYMBOL SOSC
#define SCG_PLL0_CLOCK_SYMBOL PLL0
#if SCG_PLL1_SUPPORT
#define SCG_PLL1_CLOCK_SYMBOL PLL1
#endif /* SCG_PLL1_SUPPORT */

/** @brief clock list for internal clock tree */
typedef enum
{
    /* Main clocks */
    SCG_CORE_CLK                       = 0U,       /**< Core clock                 */
    SCG_BUS_CLK                        = 1U,       /**< Bus clock                  */
    SCG_SLOW_CLK                       = 2U,       /**< Slow clock                 */

    /* Other internal clocks used by peripherals. */
    SCG_FOSC_CLK                       = 3U,       /**< FOSC clock                 */
    SCG_FIRC_CLK                       = 4U,       /**< FIRC clock                 */
    SCG_PLL0_CLK                       = 5U,       /**< PLL0 clock                 */

#if SCG_PLL1_SUPPORT
    SCG_PLL1_CLK                       = 6U,       /**< PLL1 clock                 */
#endif /* SCG_PLL1_SUPPORT */

    SCG_SIRC_CLK                       = 7U,       /**< SIRC clock                 */
    SCG_SIRC32K_CLK                    = 8U,       /**< SIRC32K clock              */
    SCG_SOSC_CLK                       = 9U,       /**< SOSC clock                 */
    SCG_SCG_CLKOUT_CLK                 = 10U,      /**< SCG CLK_OUT clock          */
    SCG_SIRCDIVH_CLK                   = 11U,      /**< SIRCDIVH functional clock  */
    SCG_SIRCDIVM_CLK                   = 12U,      /**< SIRCDIVM functional clock  */
    SCG_SIRCDIVL_CLK                   = 13U,      /**< SIRCDIVL functional clock  */
    SCG_FIRCDIVH_CLK                   = 14U,      /**< FIRCDIVH functional clock  */
    SCG_FIRCDIVM_CLK                   = 15U,      /**< FIRCDIVM functional clock  */
    SCG_FIRCDIVL_CLK                   = 16U,      /**< FIRCDIVL functional clock  */
    SCG_FOSCDIVH_CLK                   = 17U,      /**< FOSCDIVH functional clock  */
    SCG_FOSCDIVM_CLK                   = 18U,      /**< FOSCDIVM functional clock  */
    SCG_FOSCDIVL_CLK                   = 19U,      /**< FOSCDIVL functional clock  */
    SCG_PLL0DIVH_CLK                   = 20U,      /**< PLL0DIVH functional clock  */
    SCG_PLL0DIVM_CLK                   = 21U,      /**< PLL0DIVM functional clock  */
    SCG_PLL0DIVL_CLK                   = 22U,      /**< PLL0DIVL functional clock  */

#if SCG_PLL1_SUPPORT
    SCG_PLL1DIVH_CLK                   = 23U,      /**< PLL1DIVH functional clock  */
    SCG_PLL1DIVM_CLK                   = 24U,      /**< PLL1DIVM functional clock  */
    SCG_PLL1DIVL_CLK                   = 25U,      /**< PLL1DIVL functional clock  */
#endif /* SCG_PLL1_SUPPORT */

    SCG_NVMINIT_CLK                    = 26U,      /**< NVM initial clock source   */
    SCG_CMU4REF_CLK                    = 27U,      /**< CMU4 reference clock       */

#if SCG_PLLX_CLK1_SUPPORT
    SCG_PLL0CLK1_RESERVE0              = 28U,      /**< PLL0CLK1 reference clock   */
    SCG_PLL0CLK1_RESERVE1              = 29U,      /**< PLL0CLK1 reference clock   */
    SCG_PLL0CLK1_RESERVE2              = 30U,      /**< PLL0CLK1 reference clock   */
#if SCG_PLL1_SUPPORT
    SCG_PLL1CLK1_RESERVE0              = 31U,      /**< PLL1CLK1 reference clock   */
    SCG_PLL1CLK1_RESERVE1              = 32U,      /**< PLL1CLK1 reference clock   */
    SCG_PLL1CLK1_RESERVE2              = 33U,      /**< PLL1CLK1 reference clock   */
#endif /* SCG_PLL1_SUPPORT */
#endif /* SCG_PLLX_CLK1_SUPPORT */

#if SCG_PLL0_CLK2_SUPPORT
    SCG_PLL0CLK2_RESERVE0              = 34U,      /**< PLL0CLK2 reference clock   */
    SCG_PLL0CLK2_RESERVE1              = 35U,      /**< PLL0CLK2 reference clock   */
    SCG_PLL0CLK2_RESERVE2              = 36U,      /**< PLL0CLK2 reference clock   */
#endif /* SCG_PLL0_CLK2_SUPPORT */

    SCG_END_OF_CLOCKS                  = 37U       /**< End of SCG clocks          */
} SCG_ClkSrcType;

/**
 * @brief PLL clock type
 */
typedef enum
{
    SCG_PLL0 = 0U,    /**< PLL0 clock                 */
#if SCG_PLL1_SUPPORT
    SCG_PLL1 = 1U     /**< PLL1 clock                 */
#endif /* SCG_PLL1_SUPPORT */
} SCG_PllClkType;

/**
 * @brief indicate the clock function status
 *
 */
typedef enum
{
    SCG_STATUS_SUCCESS = 0U,          /**< function called success */
    SCG_STATUS_SEQUENCE_ERROR = 1U,   /**< function called report sequence error */
    SCG_STATUS_TIMEOUT = 2U,          /**< function called report timeout error */
    SCG_STATUS_IRC_ERROR = 3U,        /**< function called report internal clock error */
    SCG_STATUS_PARAM_ERROR = 4U       /**< function called report internal clock error */
} SCG_StatusType;

/**
 * @brief SCG registers CRC trigger mode
 */
typedef enum
{
    SCG_CRC_SOFTWARE_MODE = 0U,   /*!< SCG registers CRC software mode. */
    SCG_CRC_TRIGGER_MODE  = 1U    /*!< SCG registers CRC trigger mode. */
} SCG_CrcModeType;

/**
 * @brief indicate the CRC check result
 *
 */
typedef enum
{
    SCG_CRC_CHECK_SUCCESS = 0U,       /**< CRC check success *//**< SCG_CRC_CHECK_SUCCESS */
    SCG_CRC_CHECK_FAILED = 1U         /**< CRC check failed */ /**< SCG_CRC_CHECK_FAILED */
} SCG_CrcCheckResType;

/**
 * @brief SCG xxxIRC TRIMSRC type.
*/
typedef enum
{
    SCG_IRC_TRIMSRC_RESERVE0   = 0U,   /**< Clock Trim source reserve0  */
    SCG_IRC_TRIMSRC_RESERVE1   = 1U,   /**< Clock Trim source reserve1  */
    SCG_IRC_TRIMSRC_FOSC       = 2U,   /**< Clock Trim source FOSC      */
    SCG_IRC_TRIMSRC_SOSC       = 3U,   /**< Clock Trim source SOSC      */
} SCG_IrcTrimSrcType;

/**
 * @brief SCG_CCR [SCS]  to Select system clock source
 *
 */
typedef enum
{
    SCG_CLOCK_SRC_FOSC     = 1U,       /**< System OSC. */
#if SCG_SYSCLK_SEL_SIRC_SUPPORT
    SCG_CLOCK_SRC_SIRC     = 2U,       /**< Slow IRC. */
#endif
    SCG_CLOCK_SRC_FIRC     = 3U,       /**< Fast IRC.   */
    SCG_CLOCK_SRC_PLL0     = 6U,       /**< System PLL. */
    SCG_CLOCK_SRC_NONE     = 255U      /**< MAX value.  */
} SCG_ClockSrcType;

/**
 * @brief SCG_CCR [DIVCORE ]/ SCG_CCR [DIVBUS ]/ SCG_CCR [DIVSLOW ]  to Select system clock source.
 *
 */
typedef enum
{
    SCG_CLOCK_DIV_BY1   = 0U,     /**< Divided by 1.    */
    SCG_CLOCK_DIV_BY2   = 1U,     /**< Divided by 2.    */
    SCG_CLOCK_DIV_BY3   = 2U,     /**< Divided by 3.    */
    SCG_CLOCK_DIV_BY4   = 3U      /**< Divided by 4.    */
} SCG_ClockDivType;

/**
 * @brief SCG_ CLKOUTCFG [CLKOUTSEL]  to Select system clock source.
 */
typedef enum
{
    SCG_CLOCKOUT_SRC_OFF      = 0U,   /**< SCG OFF.   */
    SCG_CLOCKOUT_SRC_FOSC     = 1U,   /**< Fast OSC.   */
    SCG_CLOCKOUT_SRC_SIRC     = 2U,   /**< Slow IRC.   */
    SCG_CLOCKOUT_SRC_FIRC     = 3U,   /**< Fast IRC.   */
    SCG_CLOCKOUT_SRC_SOSC     = 4U,   /**< Slow OSC.   */
    SCG_CLOCKOUT_SRC_SIRC32K  = 7U,   /**< SIRC32K_CLK.*/
} SCG_ClockoutSrcType;

/**
 * @brief NVM clock source enumeration
 */
typedef enum
{
    SCG_NVMCLK_SRC_SIRC = 30u,   /**< NVM source choose SIRC.   */
    SCG_NVMCLK_SRC_FIRC = 31u   /**< NVM source choose FIRC.   */
} SCG_NvmClkSrcType;

/**
 * @brief CMU4 clock source enumeration
 */
typedef enum
{
    SCG_CMU4CLK_SRC_SIRC = 28u,   /**< NVM source choose SIRC.   */
    SCG_CMU4CLK_SRC_FOSC = 29u   /**< NVM source choose FORC.   */
} SCG_Cmu4ClkSrcType;

/** @brief [DIVL]/[DIVM]/[DIVH] bit field definition for SCG_SIRC/ SCG_FIRC/ SCG_FOSC/ SCG_PLL0 registers */
typedef enum
{
    SCG_ASYNC_CLOCK_DISABLE  = 0U,        /**< Clock output is disabled.  */
    SCG_ASYNCCLOCKDIV_BY1    = 1U,        /**< Divided by 1.              */
    SCG_ASYNCCLOCKDIV_BY2    = 2U,        /**< Divided by 2.              */
    SCG_ASYNCCLOCKDIV_BY4    = 3U,        /**< Divided by 4.              */
    SCG_ASYNCCLOCKDIV_BY8    = 4U,        /**< Divided by 8.              */
    SCG_ASYNCCLOCKDIV_BY16   = 5U,        /**< Divided by 16.             */
    SCG_ASYNCCLOCKDIV_BY32   = 6U,        /**< Divided by 32.             */
    SCG_ASYNCCLOCKDIV_BY64   = 7U         /**< Divided by 64.             */
} SCG_AsyncClockDivType;

/** @brief SCG_ PLLCFG[PREDIV]  for PLL clock calculation. The pre-div value range is 0 ~ 31 */
typedef enum
{
    SCG_PLLPREDIV_BY1 = 0U,    /**< Divided by 1. */
    SCG_PLLPREDIV_BY2 = 1U,    /**< Divided by 2. */
    SCG_PLLPREDIV_BY3 = 2U,    /**< Divided by 3. */
    SCG_PLLPREDIV_BY4 = 3U,    /**< Divided by 4. */
    SCG_PLLPREDIV_BY5 = 4U,    /**< Divided by 5. */
    SCG_PLLPREDIV_BY6 = 5U,    /**< Divided by 6. */
    SCG_PLLPREDIV_BY7 = 6U,    /**< Divided by 7. */
    SCG_PLLPREDIV_BY8 = 7U,    /**< Divided by 8. */
    SCG_PLLPREDIV_BY9 = 8U,    /**< Divided by 9. */
    SCG_PLLPREDIV_BY10 = 9U,   /**< Divided by 10. */
    SCG_PLLPREDIV_BY11 = 10U,  /**< Divided by 11. */
    SCG_PLLPREDIV_BY12 = 11U,  /**< Divided by 12. */
    SCG_PLLPREDIV_BY13 = 12U,  /**< Divided by 13. */
    SCG_PLLPREDIV_BY14 = 13U,  /**< Divided by 14. */
    SCG_PLLPREDIV_BY15 = 14U,  /**< Divided by 15. */
    SCG_PLLPREDIV_BY16 = 15U,  /**< Divided by 16. */
    SCG_PLLPREDIV_BY17 = 16U,  /**< Divided by 17. */
    SCG_PLLPREDIV_BY18 = 17U,  /**< Divided by 18. */
    SCG_PLLPREDIV_BY19 = 18U,  /**< Divided by 19. */
    SCG_PLLPREDIV_BY20 = 19U,  /**< Divided by 20. */
    SCG_PLLPREDIV_BY21 = 20U,  /**< Divided by 21. */
    SCG_PLLPREDIV_BY22 = 21U,  /**< Divided by 22. */
    SCG_PLLPREDIV_BY23 = 22U,  /**< Divided by 23. */
    SCG_PLLPREDIV_BY24 = 23U,  /**< Divided by 24. */
    SCG_PLLPREDIV_BY25 = 24U,  /**< Divided by 25. */
    SCG_PLLPREDIV_BY26 = 25U,  /**< Divided by 26. */
    SCG_PLLPREDIV_BY27 = 26U,  /**< Divided by 27. */
    SCG_PLLPREDIV_BY28 = 27U,  /**< Divided by 28. */
    SCG_PLLPREDIV_BY29 = 28U,  /**< Divided by 29. */
    SCG_PLLPREDIV_BY30 = 29U,  /**< Divided by 30. */
    SCG_PLLPREDIV_BY31 = 30U,  /**< Divided by 31. */
    SCG_PLLPREDIV_BY32 = 31U   /**< Divided by 32. */
} SCG_PllPredivType;

/** @brief SCG_ PLLCFG[PSTDIV]  for PLL clock calculation */
typedef enum
{
    SCG_PLLPSTDIV_BY2 = 1U,
    SCG_PLLPSTDIV_BY4 = 2U,
    SCG_PLLPSTDIV_BY8 = 3U
} SCG_PllPstdivType;

#if SCG_PLLX_CLK1_SUPPORT
/** @brief SCG_ PLLCFG[PSTDIV1]  for PLL clock calculation */
typedef enum
{
    SCG_PLLPSTDIV1_BY2 = 0U,
    SCG_PLLPSTDIV1_BY4 = 1U,
    SCG_PLLPSTDIV1_BY6 = 2U,
    SCG_PLLPSTDIV1_BY8 = 3U,
    SCG_PLLPSTDIV1_BY10 = 4U,
    SCG_PLLPSTDIV1_BY12 = 5U,
    SCG_PLLPSTDIV1_BY14 = 6U,
    SCG_PLLPSTDIV1_BY16 = 7U
} SCG_PllPstdiv1Type;
#endif /* SCG_PLLX_CLK1_SUPPORT */

#if SCG_PLL0_CLK2_SUPPORT
/** @brief SCG_ PLL0ECFG[MULT_MUX]  for PLL clock calculation */
typedef enum
{
    SCG_PLL0_MULT_MUX_SEL_TYPICAL     = 0U,  /** Mult mux select typical value(9 bits). */
    SCG_PLL0_MULT_MUX_SEL_DOUBLE_MULT = 1U,  /** Mult mux select mult*2(9 bits). */
    SCG_PLL0_MULT_MUX_SEL_10_BITS     = 3U   /** Mult mux select mult(10 bits). */
} SCG_PllMultMuxSelType;
#endif /* SCG_PLL0_CLK2_SUPPORT */


/** @brief SCG_ PLLCFG[SOURCE] to Select PLL clock source */
typedef enum
{
    SCG_PLLSOURCE_FOSC = 0U,
    SCG_PLLSOURCE_FIRC = 1U,
} SCG_PllSourceType;

/** @brief SCG_ PLLCFG [MULT]  for PLL clock calculation. The mult value range is 96 ~ 512 */
typedef uint16_t SCG_PllMultiplyType;

/**
 * @brief The interrupt enable/disable mask of SCG
 */
typedef enum
{
    SCG_INTR_MASK_FIRC_CLK_ERR		= 1U,			/**< interrupt mask of FIRC clock error */
    SCG_INTR_MASK_SIRC_CLK_ERR		= (1U << 1),	/**< interrupt mask of SIRC clock error */
    SCG_INTR_MASK_FOSC_CLK_ERR		= (1U << 2),	/**< interrupt mask of FOSC clock error */
    SCG_INTR_MASK_SOSC_CLK_ERR		= (1U << 3),	/**< interrupt mask of SOSC clock error */
    SCG_INTR_MASK_PLL0_CLK_ERR		= (1U << 4),	/**< interrupt mask of PLL0 clock error */
    SCG_INTR_MASK_PLL1_CLK_ERR		= (1U << 5) 	/**< interrupt mask of PLL0 clock error */
} SCG_IntrMaskType;

/** @brief FOSC initial definition, include register SCG_FOSCCSR/SCG_FOSCDIV/SCG_FOSCCFG. */
typedef struct
{
    bool bLock;                       /**< SCG_FOSCCSR[LK] bit, Write to set the register can be written or not */
    bool bCm;                         /**< SCG_FOSCCSR[CM] bit, Clock Monitor is enable */
    bool bCmre;                       /**< SCG_FOSCCSR[CMRE] bit, Clock Monitor Reset Enable
                                           0 Generates interrupt, 1 Generates rese         */
    bool bSten;                       /**< SCG_FOSCCSR[STEN] bit, Clock Stop in Stop modes */
    bool bBypass;                     /**< SCG_FOSCCFG[BYPASS] bit, Configures FOSC for bypassing the internal oscillator.*/
    SCG_AsyncClockDivType eDivH;      /**< SCG_FOSCDIV[DIVH] bit field definition. */
    SCG_AsyncClockDivType eDivM;      /**< SCG_FOSCDIV[DIVM] bit field definition. */
    SCG_AsyncClockDivType eDivL;      /**< SCG_FOSCDIV[DIVL] bit field definition. */
    uint8_t u8Eocv;                   /**< SCG_FOSCCFG[EOCV] bit, end of count value */
} SCG_FoscType;

/** @brief SIRC initial definition, include register SCG_ SIRCCSR/ SCG_ SIRCDIV/ SCG_ SIRCTCCFG. */
typedef struct
{
    bool bLock;                        /**< SCG_SIRCCSR[LK] bit, Write to set the register can be written or not  */
    bool bCm;                          /**< SCG_SIRCCSR[CM] bit, SIRC Clock Monitor Enable */
    bool bTrEn;                        /**< SCG_SIRCCSR[TREN] bit, IRC software trim enable (auto trim) */
    bool bLpen;                        /**< SCG_SIRCCSR[LPEN] bit, Clock Stop Enable */
    bool bSten;                        /**< SCG_SIRCCSR[STEN] bit, Clock Standby Enable */
#if SCG_SIRC_LP_WAKEUP_SUPPORT
    bool bLpwken;                      /**< SCG_SIRCCSR[LPWKE] bit, Clock Wake up in Standby Mode */
#endif /* SCG_SIRC_LP_WAKEUP_SUPPORT */
    SCG_AsyncClockDivType eDivH;       /**< SCG_SIRCDIV[DIVH] bit field definition.*/
    SCG_AsyncClockDivType eDivM;       /**< SCG_SIRCDIV[DIVM] bit field definition.*/
    SCG_AsyncClockDivType eDivL;       /**< SCG_SIRCDIV[DIVL] bit field definition.*/
    uint8_t u8TrimSrc;                 /**< SCG_SIRCTCFG[TRIMSRC] IRC clock auto trim reference clock source select.*/
} SCG_SircType;

typedef struct
{
    bool bLock;                        /**< SIRC32KCSR[LK] bit, Write to set the register can be written or not  */
} SCG_Sirc32kType;

/** @brief FIRC initial definition, include register SCG_ FIRCCSR/ SCG_ FIRCDIV/ SCG_ FIRCFG. */
typedef struct
{
    bool bLock;                        /**< SCG_FIRCCSR[VLD] bit, Read only, Clock is enabled and output clock is valid */
    bool bCm;                          /**< SCG_FIRCCSR[CM] bit, FIRC Clock Monitor Enable */
    bool bTrEn;                        /**< SCG_FIRCCSR[TREN] bit, IRC software trim enable (auto trim) */
    bool bSten;                        /**< SCG_FIRCCSR[STEN] bit, Clock Standby Enable */
    SCG_AsyncClockDivType eDivH;       /**< SCG_FIRCDIV[DIVH] bit field definition.*/
    SCG_AsyncClockDivType eDivM;       /**< SCG_FIRCDIV[DIVM] bit field definition.*/
    SCG_AsyncClockDivType eDivL;       /**< SCG_FIRCDIV[DIVL] bit field definition.*/
    uint8_t u8TrimSrc;                 /**< SCG_FIRCTCFG[TRIMSRC] IRC clock auto trim reference clock source select.*/
} SCG_FircType;

/** @brief SOSC definition, include register SCG_SOSCCFG. */
typedef struct
{
    bool bLock;                        /**< SCG_SOSCCSR[LK] bit, Write to set the register can be written or not.*/
    bool bBypass;                      /**< SCG_SOSCCSR[BYPASS] bit, Configures SOSC for bypassing the internal oscillator.*/
    bool bCm;                          /**< SCG_SOSCCSR[CM] bit,Clock Monitor enable.*/
    bool bCmre;                        /**< SCG_SOSCCSR[CMRE] bit, 1:Clock Monitor Reset, 0: interrupt*/
    bool bNoWait;                      /**< No wait SOSC valid when clock is enabled.*/
    uint8_t u8Eocv;                    /**< SCG_SOSCCFG[EOCV] bit, end of count value */
} SCG_SoscType;

/** @brief PLL definition, include register SCG_PLLCSR/ SCG_PLLDIV/SCG_PLL0CFG. */
typedef struct
{
    bool bLock;                        /**< SCG_PLLCSR[LK] bit, Write to set the register can be written or not.*/
    bool bCm;                          /**< SCG_PLLCSR[CM] bit,Clock Monitor enable.*/
    bool bCmre;                        /**< SCG_PLLCSR[CMRE] bit, 1:Clock Monitor Reset, 0: interrupt*/
    bool bSten;                        /**< SCG_PLLCSR[STEN] bit, Clock Standby Enable */
#if SCG_PLLX_CLK1_SUPPORT
    bool bPllx_Clk1En;                 /**< SCG_PLLCSR[CK1EN] bit, PLLx_CLK1 Output Enable */
#endif /* SCG_PLLX_CLK1_SUPPORT */
#if SCG_PLL0_CLK2_SUPPORT
    bool bPllx_ClkMuxExtraDiv2;        /**< SCG_PLLECFG[CK_MUX] bit, PLLx_CLK Additional 2 Frequency Division */
    bool bPllx_Clk1MuxExtraDiv2;       /**< SCG_PLLECFG[CK1_MUX] bit, PLLx_CLK1 Additional 2 Frequency Division */
    bool bPllx_Clk2En;                 /**< SCG_PLLCSR[CK2EN] bit, PLLx_CLK2 Output Enable */
    SCG_PllMultMuxSelType eSel;        /**< SCG_PLLECFG[MULT_MUX] bit field definition.*/
#endif /* SCG_PLL0_CLK2_SUPPORT */
    SCG_PllSourceType eSrc;            /**< SCG_PLLCFG[SOURCE] bit field definition.*/
    SCG_AsyncClockDivType eDivH;       /**< SCG_PLLDIV[DIVH] bit field definition.*/
    SCG_AsyncClockDivType eDivM;       /**< SCG_PLLDIV[DIVM] bit field definition.*/
    SCG_AsyncClockDivType eDivL;       /**< SCG_PLLDIV[DIVL] bit field definition.*/
    SCG_PllPredivType ePrediv;         /**< SCG_PLLCFG[PREDIV] bit field definition, the range is 0~31.*/
    SCG_PllPstdivType ePstDiv;         /**< SCG_PLLCFG[PSTDIV] bit field definition.*/
#if SCG_PLLX_CLK1_SUPPORT
    SCG_PllPstdiv1Type ePstDiv1;       /**< SCG_PLLCFG[PSTDIV1] bit field definition. */
#endif /* SCG_PLLX_CLK1_SUPPORT */
    SCG_PllMultiplyType u16Mult;       /**< SCG_PLLCFG[MULT] bit field definition, this value need to be greater than 95.*/
} SCG_PllType;

/** @brief Current system clock definition, include register SCG_CCR. */
typedef struct
{
    bool bSysClkMonitor;               /**< SCG_CCR[SYSCLK_CME], System Clock monitor bit this bit will be set 1 mandatory.*/
    SCG_ClockSrcType eSrc;             /**< SCG_CCR[SCS], System Clock Source.*/
    SCG_ClockDivType eDivSlow;         /**< SCG_CCR[DIVSLOW], Slow Clock Divide Ratio.*/
    SCG_ClockDivType eDivBus;          /**< SCG_CCR[DIVBUS], Bus Clock Divide Ratio.*/
    SCG_ClockDivType eDivCore;         /**< SCG_CCR[DIVCORE], Core Clock Divide Ratio.*/
} SCG_ClockCtrlType;

/**
 * @brief The structure of the SCG processing handle
 *
 */
typedef struct _SCG_HandleType
{
    void (*pFoscClkErrNotify)(struct _SCG_HandleType *pHandle);	/**< FOSC clock error interrupt callback */
    void (*pSircClkErrNotify)(struct _SCG_HandleType *pHandle);	/**< SIRC clock error interrupt callback */
    void (*pFircClkErrNotify)(struct _SCG_HandleType *pHandle);	/**< FIRC clock error interrupt callback */
    void (*pSoscClkErrNotify)(struct _SCG_HandleType *pHandle);	/**< SOSC clock error interrupt callback */
    void (*pPll0ClkErrNotify)(struct _SCG_HandleType *pHandle);	/**< Pll0 clock error interrupt callback */
    void (*pPll1ClkErrNotify)(struct _SCG_HandleType *pHandle);	/**< Pll0 clock error interrupt callback */
} SCG_HandleType;

/**
 * @brief The configuration option for the SCG interrupt
 *
 */
typedef struct
{
    uint32_t u32InterruptMask;								    /**< interrupt enable mask */
    void (*pFoscClkErrNotify)(struct _SCG_HandleType *pHandle);	/**< FOSC clock error interrupt callback */
    void (*pSircClkErrNotify)(struct _SCG_HandleType *pHandle);	/**< SIRC clock error interrupt callback */
    void (*pFircClkErrNotify)(struct _SCG_HandleType *pHandle);	/**< FIRC clock error interrupt callback */
    void (*pSoscClkErrNotify)(struct _SCG_HandleType *pHandle);	/**< SOSC clock error interrupt callback */
    void (*pPll0ClkErrNotify)(struct _SCG_HandleType *pHandle);	/**< Pll0 clock error interrupt callback */
    void (*pPll1ClkErrNotify)(struct _SCG_HandleType *pHandle);	/**< Pll0 clock error interrupt callback */
} SCG_InterruptType;

/**
 * @brief Enable SOSC
 *
 * @param pSoscConfig SOSC configuration
 * @return SCG_StatusType Function status
 */
SCG_StatusType SCG_EnableSOSC(const SCG_SoscType *const pSoscConfig);

/**
 * @brief Disable SOSC
 *
 * @return SCG_StatusType Funtion status
 */
SCG_StatusType SCG_DisableSOSC(void);

/**
 * @brief Get SOSC Valid status
 *
 * @return SCG_StatusType Function status
 */
SCG_StatusType SCG_GetSOSCValidStatus(void);

/**
 * @brief Enable FOSC clock with input configuration
 *
 * @param pFoscConfig FOSC configuration
 * @return SCG_StatusType function status
 */
SCG_StatusType SCG_EnableFOSC(const SCG_FoscType *const pFoscConfig);

/**
 * @brief Disable FOSC
 *
 * @return SCG_StatusType function status
 */
SCG_StatusType SCG_DisableFOSC(void);

/**
 * @brief Set SIRC configuration and configure SIRC DIV
 *
 * @param pSircConfig SIRC configuation
 * @return SCG_StatusType function status
 */
SCG_StatusType SCG_SetSIRC(const SCG_SircType *const pSircConfig);

/**
 * @brief Disable SIRC DIV and clear DIV configuration
 *
 * @return SCG_StatusType function status
 */
SCG_StatusType SCG_ClearSIRC(void);

/**
 * @brief Enable SIRC32K
 *
 * @param pSirc32kConfig SIRC32K configuration
 * @return SCG_StatusType function status
 */
SCG_StatusType SCG_EnableSIRC32K(const SCG_Sirc32kType *const pSirc32kConfig);

/**
 * @brief Disable SIRC32K
 *
 * @return SCG_StatusType function status
 */
SCG_StatusType SCG_DisableSIRC32K(void);

/**
 * @brief Enable FIRC
 *
 * @param pFircConfig FIRC configuration
 * @return SCG_StatusType function status
 */
SCG_StatusType SCG_EnableFIRC(const SCG_FircType *const pFircConfig);

/**
 * @brief Disable FIRC
 *
 * @return SCG_StatusType function status
 */
SCG_StatusType SCG_DisableFIRC(void);

/**
 * @brief Enable PLL
 *
 * @param ePll PLL instance
 * @param pPllConfig PLL configuration
 * @return SCG_StatusType function status
 */
SCG_StatusType SCG_EnablePLL(const SCG_PllClkType ePll, const SCG_PllType *const pPllConfig);

/**
 * @brief Disable PLL
 *
 * @param ePll PLL instance
 * @return SCG_StatusType function status
 */
SCG_StatusType SCG_DisablePLL(const SCG_PllClkType ePll);

/**
 * @brief Switch system clock source
 *
 * @param eClock selected clock source
 * @return SCG_StatusType function status
 */
SCG_StatusType SCG_SwitchSystemClock(const SCG_ClockSrcType eClock);

/**
 * @brief Set system run time clock and related CORE/BUS/SLOW clock.
 *
 * @param pSysClkConfig pointer to the clockCtrlType structure data instance,which defined for system clock selection.
 * @return SCG_StatusType function status
 */
SCG_StatusType SCG_SetClkCtrl(const SCG_ClockCtrlType *const pSysClkConfig);

/**
 * @brief Get clock frequency
 *
 * @param eScgClockName Clock source type
 * @return uint32_t frequency value
 */
uint32_t SCG_GetScgClockFreq(const SCG_ClkSrcType eScgClockName);

/**
 * @brief Select clock out source
 *
 * @param eClkoutSel clock out source
 */
void SCG_SetClkOut(const SCG_ClockoutSrcType eClkoutSel);

/**
 * @brief Select NVM clock source
 *
 * @param eNvmClkSrc NVM clock source
 * @return uint32_t function status
 */
SCG_StatusType SCG_SetNvmClk(const SCG_NvmClkSrcType eNvmClkSrc);

/**
 * @brief Select CMU4 clock source
 *
 * @param eCmu4ClkSrc CMU4 clock source
 * @return SCG_StatusType function status
 */
SCG_StatusType SCG_SetCmu4Clk(const SCG_Cmu4ClkSrcType eCmu4ClkSrc);

/**
 * @brief Initializes the CRC module based on the specified mode.
 *
 * This function initializes the CRC module by first disabling and clearing any existing CRC-related configurations.
 * It then generates the original CRC value and waits for the CRC calculation to complete. If the operation times out,
 * the function returns a timeout status. If the initialization is successful, it enables the CRC trigger mode (if specified)
 * and enables CRC error output and CRC check.
 *
 * @param eMode The CRC mode to be initialized. Possible values are:
 *              - SCG_CRC_TRIGGER_MODE: Enables CRC trigger mode.
 *
 * @return SCG_StatusType Returns the status of the CRC initialization:
 *         - SCG_STATUS_SUCCESS: CRC initialization was successful.
 *         - SCG_STATUS_TIMEOUT: CRC initialization timed out.
 */
SCG_StatusType SCG_CrcInit(SCG_CrcModeType eMode);

/**
 * @brief Generates a CRC value using the SCG hardware accelerator.
 *
 * This function invokes the hardware accelerator to generate a CRC value.
 * It calls the `SCG_HWA_GenCrcVal()` function, which is responsible for
 * the actual CRC computation.
 *
 * @note This function assumes that the hardware accelerator is properly
 * initialized and configured before being called.
 *
 * @return void
 */
void SCG_CrcGenerate(void);

/**
 * @brief Clock source De-init
 *
 * @return SCG_StatusType function status
 */
SCG_StatusType SCG_Deinit(void);

/**
 * @brief  Set clock error interrupt.
 * @param pScgHandle: Scg handle
 * @param  pIntrStruct: pointer to interrupt configuration,
 */

void SCG_InterruptInit(SCG_HandleType* pScgHandle, const SCG_InterruptType *const pIntrStruct);

/**
 * @brief Clock error interrupt handler
 * @param pScgHandle: Scg handle
 */

void SCG_UserIRQHandler(SCG_HandleType* pScgHandle);

/** @}*/ /* module_driver_scg */

#endif /* #if SCG_INSTANCE_COUNT > 0U */

#endif
