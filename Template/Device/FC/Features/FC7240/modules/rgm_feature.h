#ifndef _DEVICE_FEATURES_FC7240_RGM_COMMON_H_
#define _DEVICE_FEATURES_FC7240_RGM_COMMON_H_

/************ RGM Features **************/
/** Number of instances of the RGM module. */
#define RGM_INSTANCE_COUNT                       (1u)


/** Array initializer of RGM peripheral base addresses */
#define RGM_BASE_ADDRS                           {RGM_BASE}
/** Array initializer of RGM peripheral base pointers */
#define RGM_BASE_PTRS                            {RGM}



/************ FC7240 RGM Common Features **************/
#define RGM_C1_SUPPORT            (0u)
#define RGM_C2_SUPPORT            (0u)
#define RGM_C3_SUPPORT            (0u)
#define RGM_PIN_RIE_SUPPORT       (1u)
#define RGM_INTM_TOUT_RIE_SUPPORT (0u)
#define RGM_WDG1_RIE_SUPPORT      (1u)

#define RGM_ERR_003       (0u)

#define RGM_SSRS_ALLFLAG  (0xE000F9FFu)
#define RGM_SRIE_ALL_RIE_MASK (0x3FE8u)

#endif /* _DEVICE_FEATURES_FC7240_RGM_COMMON_H_ */
