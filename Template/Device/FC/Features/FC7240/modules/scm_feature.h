#ifndef _DEVICE_FEATURES_FC7240_SCM_COMMON_H_
#define _DEVICE_FEATURES_FC7240_SCM_COMMON_H_

/************ SCM Features **************/
/** Number of instances of the SCM module. */
#define SCM_INSTANCE_COUNT                       (1u)

/** Array initializer of SCM peripheral base addresses */
#define SCM_BASE_ADDRS                           {SCM_BASE}
/** Array initializer of SCM peripheral base pointers */
#define SCM_BASE_PTRS                            {SCM}

#define SCM_SUBSYSPCC_SUPPORT		             (1u)

#endif /* _DEVICE_FEATURES_FC7240_SCM_COMMON_H_ */
