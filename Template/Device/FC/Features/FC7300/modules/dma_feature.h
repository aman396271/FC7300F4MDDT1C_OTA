#ifndef _DEVICE_FEATURES_FC7300_DMA_COMMON_H_
#define _DEVICE_FEATURES_FC7300_DMA_COMMON_H_

/************ DMA Features **************/

#define DMA_TYPE_FC7300                          0U
#define DMA_HW_TYPE                              DMA_TYPE_FC7300

#if (DMA_HW_TYPE == DMA_TYPE_FC7300)
#define DMA_HAVE_BACKDOOR
#define DMA_HAVE_GPR
#define DMA_HAVE_MONCHK

#define DTCM_ADDRESS_START              0x20000000UL
#define DTCM_ADDRESS_STOP               0x2001FFFFUL
#define DTCM0_BACKDOOR                  0x02000000UL
#define DTCM1_BACKDOOR                  0x02100000UL
#define DTCM2_BACKDOOR                  0x02200000UL

#define ITCM_ADDRESS_START              0x00000000UL
#define ITCM_ADDRESS_STOP               0x0000FFFFUL
#define ITCM0_BACKDOOR                  0x24000000UL
#define ITCM1_BACKDOOR                  0x24100000UL
#define ITCM2_BACKDOOR                  0x24200000UL

#endif

#endif /* _DEVICE_FEATURES_FC7300_DMA_COMMON_H_ */
