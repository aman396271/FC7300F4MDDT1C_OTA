#ifndef _DEVICE_FEATURES_FC7240_SMC_COMMON_H_
#define _DEVICE_FEATURES_FC7240_SMC_COMMON_H_

/************ SMC Features **************/
/** Number of instances of the SMC module. */
#define SMC_INSTANCE_COUNT                       (1u)


/** Array initializer of SMC peripheral base addresses */
#define SMC_BASE_ADDRS                           {SMC_BASE}
/** Array initializer of SMC peripheral base pointers */
#define SMC_BASE_PTRS                            {SMC}




#define SMC_CLOCKCONFIG_SUPPORT         (0u)
#define SMC_TSTMP0CLOCK_CONFIG_SUPPORT  (0u)
#define SMC_LP_GOOD_SUPPORT             (0u)
#define SMC_SCG_WAKEUP_CONFIG_SUPPORT   (0u)
#define SMC_SCG_WAKEUP_SRC_TSTMP_EXT_TRG_SUPPORT    (0u)
#define SMC_SCG_WAKEUP_SRC_TSTMP_EDGE_TRG_SUPPORT   (0u)
#define SMC_CMP0_LPWAKEUP_SUPPORT         (0u)
#define SMC_ADC2_LPWAKEUP_SUPPORT         (0u)
#define SMC_SRAM2_RENTENTION_MODE_SUPPORT (0u)

#define SMC_SCG_WARKEUP_ADC0_AND_ADC1   (0u)

#endif /* _DEVICE_FEATURES_FC7240_SMC_COMMON_H_ */
