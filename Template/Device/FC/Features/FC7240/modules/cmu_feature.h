#ifndef _DEVICE_FEATURES_FC7240_CMU_COMMON_H_
#define _DEVICE_FEATURES_FC7240_CMU_COMMON_H_

/************ CMU Features **************/
/** Number of instances of the CMU module. */
#define CMU_INSTANCE_COUNT                      (5U)






/** Array initializer of CMU peripheral base addresses */
#define CMU_BASE_ADDRS                          {CMU0_BASE, CMU1_BASE, CMU2_BASE, CMU3_BASE, CMU4_BASE}
/** Array initializer of CMU peripheral base pointers */
#define CMU_BASE_PTRS                           {CMU0, CMU1, CMU2, CMU3, CMU4}

#define CMU_CTRL_LP_SUPPORT

#endif /* _DEVICE_FEATURES_FC7240_CMU_COMMON_H_ */
