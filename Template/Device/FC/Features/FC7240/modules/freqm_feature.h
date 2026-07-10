#ifndef _DEVICE_FEATURES_FC7240_FREQM_COMMON_H_
#define _DEVICE_FEATURES_FC7240_FREQM_COMMON_H_

/************ FREQM Features **************/
/** Number of instances of the FREQM module. */
#define FREQM_INSTANCE_COUNT                    (1U)


/** Array initializer of FREQM peripheral base addresses */
#define FREQM_BASE_ADDRS                        {FREQM_BASE}
/** Array initializer of FREQM peripheral base pointers */
#define FREQM_BASE_PTRS                         {FREQM}

/**
 * @brief freqm measured clock define
 *
 */
#define FREQM_MES_SLOW_CLK              1U
#define FREQM_MES_PLL1_FB_CLK           2U
#define FREQM_MES_PLL0_FB_CLK           3U
#define FREQM_MES_SCG_CLKOUT            4U
#define FREQM_MES_RTC_CLK               5U
#define FREQM_MES_AON_CLK               6U
#define FREQM_MES_SIRC_128K_CLK         7U
#define FREQM_MES_PCC_FCPIT0            10U
#define FREQM_MES_PCC_FCSPI0            13U
#define FREQM_MES_PCC_FCSPI1            14U
#define FREQM_MES_PCC_FCSPI2            15U
#define FREQM_MES_PCC_FCUART0           17U
#define FREQM_MES_PCC_FCUART1           18U
#define FREQM_MES_PCC_FCUART2           19U
#define FREQM_MES_TRGSEL1_TRGSEL_CLK    21U
#define FREQM_MES_PCC_FTU0              22U
#define FREQM_MES_PCC_FTU1              23U
#define FREQM_MES_PCC_FTU2              25U
#define FREQM_MES_PCC_FTU3              26U
#define FREQM_MES_PCC_ADC0              27U
#define FREQM_MES_PCC_ADC1              29U
#define FREQM_MES_FOSC_DIVL_CLK         33U
#define FREQM_MES_SIRC_DIVL_CLK         34U
#define FREQM_MES_FIRC_DIVL_CLK         35U
#define FREQM_MES_PLL1_DIVL_CLK         37U
#define FREQM_MES_PLL0_DIVL_CLK         38U
#define FREQM_MES_FOSC_DIVM_CLK         41U
#define FREQM_MES_SIRC_DIVM_CLK         42U
#define FREQM_MES_FIRC_DIVM_CLK         43U
#define FREQM_MES_PLL1_DIVM_CLK         45U
#define FREQM_MES_PLL0_DIVM_CLK         46U
#define FREQM_MES_FOSC_DIVH_CLK         49U
#define FREQM_MES_SIRC_DIVH_CLK         50U
#define FREQM_MES_FIRC_DIVH_CLK         51U
#define FREQM_MES_PLL1_DIVH_CLK         53U
#define FREQM_MES_PLL0_DIVH_CLK         54U
#define FREQM_MES_PCC_SENT0             57U
#define FREQM_MES_PCC_FLEXCAN0          58U
#define FREQM_MES_PCC_FLEXCAN1          59U
#define FREQM_MES_PCC_MSC0              61U
#define FREQM_MES_PCC_TPU               62U

#endif /* _DEVICE_FEATURES_FC7240_FREQM_COMMON_H_ */
