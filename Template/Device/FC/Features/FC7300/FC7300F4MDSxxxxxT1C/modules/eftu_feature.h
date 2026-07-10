#ifndef _DEVICE_FEATURES_FC7300F4MDSxxxxxT1C_EFTU_COMMON_H_
#define _DEVICE_FEATURES_FC7300F4MDSxxxxxT1C_EFTU_COMMON_H_
#define EFTU_INSTANCE_COUNT           (1U)
#define EFTU_CCM_INSTANCE_COUNT       (1u)
#define EFTU_CMU_INSTANCE_COUNT       (1u)
#define EFTU_TBU_INSTANCE_COUNT       (1u)
#define EFTU_TIM_INSTANCE_COUNT       (1u)
#define EFTU_TOM_INSTANCE_COUNT       (2u)
#define EFTU_DTM_INSTANCE_COUNT       (4u)
#define EFTU_TOM_CHANNEL_COUNT        (8u)
#define EFTU_TIM_CHANNEL_COUNT        (8u)
#define EFTU_CCM_DMA_REQ_ONE_INSTANCE (16u)
#define EFTU0_BASE                    (0x40476000u)

#define EFTU_ADDRESS_TAB              { EFTU0_BASE }
#define EFTU_CCM_BASE_OFFSET          (0x0u)
#define EFTU_TIM_BASE                 (0x800u)
#define EFTU_CMU_BASE                 (0x400u)
#define EFTU_TBU_BASE                 (0x500u)

#define EFTU_TOM0_BASE                (0x1000u)
#define EFTU_TOM1_BASE                (0x1800u)

#define EFTU_DTM0_BASE                (0x600u)
#define EFTU_DTM1_BASE                (0x680u)
#define EFTU_DTM2_BASE                (0x700u)
#define EFTU_DTM3_BASE                (0x780u)

#define EFTU_CCM_ADDRESS_TAB           \
    {                                  \
        (EFTU_CCM_Type *)(EFTU0_BASE), \
    }

#define EFTU_TIM_ADDRESS_TAB                           \
    {                                                  \
        (EFTU_TIM_Type *)(EFTU0_BASE + EFTU_TIM_BASE), \
    }

#define EFTU_EAC_SUPPORT        STD_ON
#define EFTU_HRPWM_SUPPORT      STD_OFF

#define EFTU_SPE_SUPPORT        STD_ON
#define EFTU_SPE_INSTANCE_COUNT (2u)
#define EFTU_SPE0_BASE          (0xE00u)
#define EFTU_SPE1_BASE          (0xE80u)

#endif /* _DEVICE_FEATURES_FC7300F4MDSxxxxxT1C_EFTU_COMMON_H_ */
