#ifndef _DEVICE_FEATURES_FC7240_ERM_COMMON_H_
#define _DEVICE_FEATURES_FC7240_ERM_COMMON_H_

/************ ERM Features **************/
/** Number of instances of the ERM module. */
#define ERM_INSTANCE_COUNT                      (1U)


/** Array initializer of ERM peripheral base addresses */
#define ERM_BASE_ADDRS                          {ERM_BASE}
/** Array initializer of ERM peripheral base pointers */
#define ERM_BASE_PTRS                           {ERM}

/**
 * @brief ERM Channel define
 * 
 */
#define ERM_CHANNEL_PFLASH0_ECC         1U      /* PFlash0 ECC Error */
#define ERM_CHANNEL_DFLASH_ECC          3U      /* DFlash ECC error */
#define ERM_CHANNEL_DMACFG0_ECC         4U      /* DMACFG0 ECC Error */
#define ERM_CHANNEL_ROM_ECC             6U      /* ROM ECC Error */
#define ERM_CHANNEL_SYSRAM0_ECC         8U      /* SysRAM0 ECC ERROR */
#define ERM_CHANNEL_SYSRAM1_ECC         9U      /* SysRAM1 ECC ERROR */
#define ERM_CHANNEL_CPU0ITCM_ECC        11U     /* CPU0 ITCM ECC Error */
#define ERM_CHANNEL_CPU0DTCM0_ECC       12U     /* CPU0 DTCM0 ECC Error */
#define ERM_CHANNEL_CPU0DTCM1_ECC       13U     /* CPU0 DTCM1 ECC Error */
#define ERM_CHANNEL_CPU0ICACHE_ECC      14U     /* CPU0 ICACHE ECC Error */
#define ERM_CHANNEL_CPU0DCACHE_ECC      15U     /* CPU0 DCACHE ECC Error */
#define ERM_CHANNEL_HSMDRAM_ECC         26U     /* HSM DRAM ECC Error */
#define ERM_CHANNEL_HSMIRAM_ECC         27U     /* HSM IRAM ECC Error */

#define ERM_CR_SR_COUNT_MAX     4U

#endif /* _DEVICE_FEATURES_FC7240_ERM_COMMON_H_ */
