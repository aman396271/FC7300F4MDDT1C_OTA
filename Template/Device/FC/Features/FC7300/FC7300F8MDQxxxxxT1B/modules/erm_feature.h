#ifndef _DEVICE_FEATURES_FC7300F8MDQxxxxxT1B_ERM_COMMON_H_
#define _DEVICE_FEATURES_FC7300F8MDQxxxxxT1B_ERM_COMMON_H_

/**
 * @brief ERM Channel define
 * 
 */
#define ERM_CHANNEL_PFLASH0_ECC         1U      /* PFlash0 ECC Error */
#define ERM_CHANNEL_PFLASH1_ECC         2U      /* PFlash1 ECC Error */
#define ERM_CHANNEL_DFLASH_ECC          3U      /* DFlash ECC error */
#define ERM_CHANNEL_DMA0_ECC            4U      /* DMA0 ECC Error */
#define ERM_CHANNEL_DMA1_ECC            5U      /* DMA1 ECC Error */
#define ERM_CHANNEL_ROM_ECC             6U      /* ROM ECC Error */
#define ERM_CHANNEL_SYSRAM0_ECC         8U      /* SysRAM0 ECC ERROR */
#define ERM_CHANNEL_SYSRAM1_ECC         9U      /* SysRAM1 ECC ERROR */
#define ERM_CHANNEL_SYSRAM2_ECC         10U     /* SysRAM2 ECC ERROR */
#define ERM_CHANNEL_CPU0ITCM_ECC        11U     /* CPU0 ITCM ECC Error */
#define ERM_CHANNEL_CPU0DTCM0_ECC       12U     /* CPU0 DTCM0 ECC Error */
#define ERM_CHANNEL_CPU0DTCM1_ECC       13U     /* CPU0 DTCM1 ECC Error */
#define ERM_CHANNEL_CPU0ICACHE_ECC      14U     /* CPU0 ICACHE ECC Error */
#define ERM_CHANNEL_CPU0DCACHE_ECC      15U     /* CPU0 DCACHE ECC Error */
#define ERM_CHANNEL_CPU1ITCM_ECC        16U     /* CPU1 ITCMECC Error */
#define ERM_CHANNEL_CPU1DTCM0_ECC       17U     /* CPU1 DTCM0 ECC Error */
#define ERM_CHANNEL_CPU1DTCM1_ECC       18U     /* CPU1 DTCM1 ECC Error */
#define ERM_CHANNEL_CPU1ICACHE_ECC      19U     /* CPU1 ICACHE  ECC Error */
#define ERM_CHANNEL_CPU1DCACHE_ECC      20U     /* CPU1 DCACHE  ECC Error */
#define ERM_CHANNEL_CPU2ITCM_ECC        21U     /* CPU2 ITCMECC ECC Error */
#define ERM_CHANNEL_CPU2DTCM0_ECC       22U     /* CPU2 DTCM0 ECC Error */
#define ERM_CHANNEL_CPU2DTCM1_ECC       23U     /* CPU2 DTCM1 ECC Error */
#define ERM_CHANNEL_CPU2ICACHE_ECC      24U     /* CPU2 ICACHE ECC Error */
#define ERM_CHANNEL_CPU2DCACHE_ECC      25U     /* CPU2 DCACHE ECC Error */
#define ERM_CHANNEL_FLEXHSMDRAM_ECC     26U     /* FLEXHSM DRAM ECC Error */
#define ERM_CHANNEL_FLEXHSMIRAM_ECC     27U     /* FLEXHSM IRAM ECC Error */
#define ERM_CHANNEL_CPU3ITCM_ECC        28U     /* CPU3 ITCMECC ECC Error */
#define ERM_CHANNEL_CPU3DTCM0_ECC       29U     /* CPU3 DTCM0 ECC Error */
#define ERM_CHANNEL_CPU3DTCM1_ECC       30U     /* CPU3 DTCM1 ECC Error */
#define ERM_CHANNEL_CPU3ICACHE_ECC      31U     /* CPU3 ICACHE ECC Error */
#define ERM_CHANNEL_CPU3DCACHE_ECC      32U     /* CPU3 DCACHE ECC Error */

#define ERM_CR4_SR4_SUPPORT
#define ERM_CR_SR_COUNT_MAX     5U

#endif /* _DEVICE_FEATURES_FC7300F8MDQxxxxxT1B_ERM_COMMON_H_ */
