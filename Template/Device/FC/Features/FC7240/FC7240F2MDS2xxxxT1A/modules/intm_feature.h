#ifndef _DEVICE_FEATURES_FC7240F2MDS2_INTM_COMMON_H_
#define _DEVICE_FEATURES_FC7240F2MDS2_INTM_COMMON_H_


/************ INTM Features **************/
/** Number of instances of the INTM module. */
#define INTM_INSTANCE_COUNT                      (1u)



/** Array initializer of INTM peripheral base addresses */
#define INTM_BASE_ADDRS                          {INTM0_BASE}
/** Array initializer of INTM peripheral base pointers */
#define INTM_BASE_PTRS                           {INTM0}


#define INTERRUPT_INACTIVE_MODE_SUPPORT          STD_ON

/**
 * @brief The INTM instance
 *
 */
typedef enum
{
    INTM_INSTANCE_0   = 0U,
    INTM_INSTANCE_MAX,
} INTM_InstanceType;

#endif /* _DEVICE_FEATURES_FC7240F2MDS2_INTM_COMMON_H_ */
