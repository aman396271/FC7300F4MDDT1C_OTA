#ifndef _DEVICE_FEATURES_FC7300F4MDDxxxxxT1B_ERM_COMMON_H_
#define _DEVICE_FEATURES_FC7300F4MDDxxxxxT1B_ERM_COMMON_H_

/**
 * @brief ERM Channel define
 * 
 */
#define ERM_CHANNEL_PFLASH0_ECC         1U      /* PFlash0 ECC Error */
#define ERM_CHANNEL_DFLASH_ECC          3U      /* DFlash ECC error */
#define ERM_CHANNEL_DMACFG0_ECC         4U      /* DMACFG0 ECC Error */
#define ERM_CHANNEL_DMACFG1_ECC         5U      /* DMACFG1 ECC Error */
#define ERM_CHANNEL_ROM_ECC             6U      /* ROM ECC Error */
#define ERM_CHANNEL_SYSRAM0_ECC         8U      /* SysRAM0 ECC ERROR */
#define ERM_CHANNEL_SYSRAM1_ECC         9U      /* SysRAM1 ECC ERROR */
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

#define ERM_CR_SR_COUNT_MAX     4U

#endif /* _DEVICE_FEATURES_FC7300F4MDDxxxxxT1B_ERM_COMMON_H_ */
