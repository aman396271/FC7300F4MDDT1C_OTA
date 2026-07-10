#ifndef _DEVICE_FEATURES_FC7300F8MDTxxxxxT1B_TSTMP_COMMON_H_
#define _DEVICE_FEATURES_FC7300F8MDTxxxxxT1B_TSTMP_COMMON_H_
/*********************** TSTMP Features ****************************/


/** Number of instances of the TSTMP module. */
#define TSTMP_INSTANCE_COUNT                     (4u)





/** Array initializer of TSTMP peripheral base addresses */
#define TSTMP_BASE_ADDRS                         {TSTMP0_BASE,TSTMP1_BASE,TSTMP2_BASE,TSTMP3_BASE}
/** Array initializer of TSTMP peripheral base pointers */
#define TSTMP_BASE_PTRS                          {TSTMP0,TSTMP1,TSTMP2,TSTMP3}

/**When running to the MODx_SETVAL value, the timer will generate an interrupt and will be zero,
 * then it will continue to run from zero.
 * */
#define  TSTMP_SUPPORT_MODULATE_SUPPOT 			STD_ON
#define  TSTMP_INSTANCE_NUM						(4U)
#endif
