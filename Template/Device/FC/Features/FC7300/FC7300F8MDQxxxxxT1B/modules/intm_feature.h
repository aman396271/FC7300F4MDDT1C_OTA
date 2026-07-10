#ifndef _DEVICE_FEATURES_FC7300F8MDQxxxxxT1B_INTM_COMMON_H_
#define _DEVICE_FEATURES_FC7300F8MDQxxxxxT1B_INTM_COMMON_H_

/************ INTM Features **************/
/** Number of instances of the INTM module. */
#define INTM_INSTANCE_COUNT                      (4u)






/** Array initializer of INTM peripheral base addresses */
#define INTM_BASE_ADDRS                          {INTM0_BASE, INTM1_BASE, INTM2_BASE, INTM3_BASE}
/** Array initializer of INTM peripheral base pointers */
#define INTM_BASE_PTRS                           {INTM0, INTM1, INTM2, INTM3}


#define INTERRUPT_INACTIVE_MODE_SUPPORT          STD_ON

typedef enum
{
    INTM_INSTANCE_0   = 0U,
    INTM_INSTANCE_1,
    INTM_INSTANCE_2,
    INTM_INSTANCE_3,
    INTM_INSTANCE_MAX,
} INTM_InstanceType;

#endif /* _DEVICE_FEATURES_FC7300F8MDQxxxxxT1B_INTM_COMMON_H_ */
