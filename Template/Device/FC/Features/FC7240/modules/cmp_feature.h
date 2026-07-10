#ifndef _DEVICE_FEATURES_FC7240_CMP_COMMON_H_
#define _DEVICE_FEATURES_FC7240_CMP_COMMON_H_

/*********************** CMP Features ****************************/

/** Number of instances of the FLEXCAN module. */
#define CMP_INSTANCE_COUNT                      (2u)

/** Array initializer of CMP peripheral base addresses */
#define CMP_BASE_ADDRS                           {CMP0_BASE, CMP1_BASE}
/** Array initializer of CMP peripheral base pointers */
#define CMP_BASE_PTRS                            {CMP0, CMP1}

#define CMP_SUPPORT_CHANNELSCAN_MODE_FEATURE

#endif /* _DEVICE_FEATURES_FC7240_CMP_COMMON_H_ */
