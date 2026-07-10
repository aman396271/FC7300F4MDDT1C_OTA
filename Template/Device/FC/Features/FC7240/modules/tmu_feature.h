#ifndef _DEVICE_FEATURES_FC7240_TMU_COMMON_H_
#define _DEVICE_FEATURES_FC7240_TMU_COMMON_H_

/************ TMU Features **************/
/** Number of instances of the TMU module. */
#define TMU_INSTANCE_COUNT                       (1u)


/** Array initializer of TMU peripheral base addresses */
#define TMU_BASE_ADDRS                           {TMU_BASE}
/** Array initializer of TMU peripheral base pointers */
#define TMU_BASE_PTRS                            {TMU}




#define TMU_SUPPORT_TRIM
#define TMU_SUPPORT_TV_ECMP    (0u)

#endif /* _DEVICE_FEATURES_FC7240_TMU_COMMON_H_ */
