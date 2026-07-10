#ifndef _DEVICE_FEATURES_FC7300F8MDQxxxxxT1B_WDOG_COMMON_H_
#define _DEVICE_FEATURES_FC7300F8MDQxxxxxT1B_WDOG_COMMON_H_

/************ WDOG Features **************/
/** Number of instances of the WDOG module. */
#define WDOG_INSTANCE_COUNT                      (4u)

/** Array initializer of WDOG peripheral base addresses */
#define WDOG_BASE_ADDRS                          {WDOG0_BASE, WDOG1_BASE, WDOG2_BASE, WDOG3_BASE}
/** Array initializer of WDOG peripheral base pointers */
#define WDOG_BASE_PTRS                           {WDOG0, WDOG1, WDOG2, WDOG3}

#define WDOG_SUPPORT_FASTCFG    (0u)


#endif /* _DEVICE_FEATURES_FC7300F8MDQxxxxxT1B_WDOG_COMMON_H_ */
