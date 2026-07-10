#ifndef _DEVICE_FEATURES_FC7240_PTIMER_COMMON_H_
#define _DEVICE_FEATURES_FC7240_PTIMER_COMMON_H_

/************ PTIMER Features **************/
/** Number of instances of the PTIMER module. */
#define PTIMER_INSTANCE_COUNT                    (2u)

/** Array initializer of PTIMER peripheral base addresses */
#define PTIMER_BASE_ADDRS                        {PTIMER0_BASE, PTIMER1_BASE, PTIMER2_BASE, PTIMER3_BASE}
/** Array initializer of PTIMER peripheral base pointers */
#define PTIMER_BASE_PTRS                         {PTIMER0, PTIMER1}

#define PTIMER_SUPPORT_DEBUG_MODE                (0u)

#endif /* _DEVICE_FEATURES_FC7240_PTIMER_COMMON_H_ */
