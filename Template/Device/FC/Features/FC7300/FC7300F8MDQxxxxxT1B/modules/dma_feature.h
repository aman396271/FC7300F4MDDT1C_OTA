#ifndef _DEVICE_FEATURES_FC7300F8MDQxxxxxT1B_DMA_COMMON_H_
#define _DEVICE_FEATURES_FC7300F8MDQxxxxxT1B_DMA_COMMON_H_


#define DMA_UME_COUNT                           2U
#define DMA_CHPRI_COUNT                         32U
#define DMA_CFG_COUNT                            32U

/** Number of instances of the DMA module. */
#define DMA_INSTANCE_COUNT                       (2u)

/** Array initializer of DMA peripheral base addresses */
#define DMA_BASE_ADDRS                           {DMA0_BASE, DMA1_BASE}
/** Array initializer of DMA peripheral base pointers */
#define DMA_BASE_PTRS                            {DMA0, DMA1}

#define DMA0_HAVE_LOCKSTEP

#endif /* _DEVICE_FEATURES_FC7300F8MDQxxxxxT1B_DMA_COMMON_H_ */
