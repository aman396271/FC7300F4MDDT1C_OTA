#ifndef _DEVICE_FEATURES_FC7240_CPM_COMMON_H_
#define _DEVICE_FEATURES_FC7240_CPM_COMMON_H_

/************ CPM Features **************/
/** Number of instances of the CPM module. */
#define CPM_INSTANCE_COUNT                       (1u)


/** Array initializer of CPM peripheral base addresses */
#define CPM_BASE_ADDRS                           {CPM_BASE}
/** Array initializer of CPM peripheral base pointers */
#define CPM_BASE_PTRS                            {CPM}

#define CPM_CONTAIN_CPUID                         STD_OFF

#endif /* _DEVICE_FEATURES_FC7240_CPM_COMMON_H_ */
