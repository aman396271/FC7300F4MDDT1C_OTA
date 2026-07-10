#ifndef _DEVICE_FEATURES_FC7240F2MDS2_TSTMP_COMMON_H_
#define _DEVICE_FEATURES_FC7240F2MDS2_TSTMP_COMMON_H_


/** Number of instances of the TSTMP module. */
#define TSTMP_INSTANCE_COUNT                     (2u)




/** Array initializer of TSTMP peripheral base addresses */
#define TSTMP_BASE_ADDRS                         {TSTMP0_BASE,TSTMP1_BASE}
/** Array initializer of TSTMP peripheral base pointers */
#define TSTMP_BASE_PTRS                          {TSTMP0,TSTMP1}

/**When running to the MODx_SETVAL value, the timer will generate an interrupt and will be zero,
 * then it will continue to run from zero.
 * */
#define  TSTMP_SUPPORT_MODULATE_SUPPOT 			STD_ON
#define  TSTMP_INSTANCE_NUM						(2U)

#endif /* _DEVICE_FEATURES_FC7240F2MDS2_TSTMP_COMMON_H_ */
