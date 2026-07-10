#ifndef _DEVICE_FEATURES_FC7300_RGM_COMMON_H_
#define _DEVICE_FEATURES_FC7300_RGM_COMMON_H_

/************ RGM Features **************/
/** Number of instances of the RGM module. */
#define RGM_INSTANCE_COUNT                       (1u)


/** Array initializer of RGM peripheral base addresses */
#define RGM_BASE_ADDRS                           {RGM_BASE}
/** Array initializer of RGM peripheral base pointers */
#define RGM_BASE_PTRS                            {RGM}


/************ FC7300 RGM Common Features **************/
#define RGM_SSRS_ALLFLAG  (0xE000E9FFu)

#endif /* _DEVICE_FEATURES_FC7300_RGM_COMMON_H_ */
