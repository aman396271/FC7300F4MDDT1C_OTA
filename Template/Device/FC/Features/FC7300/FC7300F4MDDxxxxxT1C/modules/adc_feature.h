#ifndef _DEVICE_FEATURES_FC7300F4MDDxxxxxT1C_ADC_COMMON_H_
#define _DEVICE_FEATURES_FC7300F4MDDxxxxxT1C_ADC_COMMON_H_

/************ ADC Features **************/

/** Number of instances of the ADC module. */
#define ADC_INSTANCE_COUNT                       (4u)
#define ADC_MAX_SEQUENCE_GROUP_CNT               (4U)
#define ADC_SAMPLE_TIME_OPTION_CNT               (4U)
#define ADC_ENHANCED_CMP_BLOCK_CNT               (2U)

/** Array initializer of ADC peripheral base addresses */
#define ADC_BASE_ADDRS                           {ADC0_BASE, ADC1_BASE, ADC2_BASE, ADC3_BASE}
/** Array initializer of ADC peripheral base pointers */
#define ADC_BASE_PTRS                            {ADC0, ADC1, ADC2, ADC3}

#define ADC_SUPPORT_SG_MODE                      (1u)
#define ADC_SUPPORT_SG_DMA_MODE                  (1u)
#define ADC_SUPPORT_GAIN_AND_OFFSET_CALIBRATION  (1u)
#define ADC_SUPPORT_CHANNEL_DIFFMODE_SET         (1u)
#define ADC_SUPPORT_INSTANCE_DIFFMODE_SET        (0u)
#define ADC_SUPPORT_SG_CMP_BLOCK                 (1u)
#define ADC_SUPPORT_SG_CMP_INSTANCE_START        (0u)
#define ADC_SUPPORT_ENHANCED_CMP_BLOCK           (1u)
#define ADC_SUPPORT_FAST_CMP_BLOCK               (0u)
#define ADC_SUPPORT_INTERNAL_REFERENCE           (1u)
#define ADC_SUPPORT_PERIOD_TRIGGER               (0u)
#define ADC_SUPPORT_GROUP_INJECTION              (1u)

#define ADC_IS_SUPPORT_SG_CMP_BLOCK(i)           \
    (i == 0 || i == 1 ? true : false)            \

#define ADC_GET_SUPPORTED_SEQUENCE_GROUP_CNT(i)  \
    (ADC_MAX_SEQUENCE_GROUP_CNT)                 \

#define ADC_IS_SUPPORT_ENHANCED_CMP_BLOCK(i)     true

#define ADC0_CHANNEL_VBG_BUFFER                  ADC_CHANNEL_INTERNAL_0
#define ADC0_CHANNEL_V25                         ADC_CHANNEL_INTERNAL_1
#define ADC0_CHANNEL_V11_PD1                     ADC_CHANNEL_INTERNAL_2
#define ADC0_CHANNEL_CMP0_DAC                    ADC_CHANNEL_INTERNAL_4
#define ADC0_CHANNEL_TEMPSENSOR_OUT              ADC_CHANNEL_INTERNAL_5

#define ADC1_CHANNEL_V11_PD0                     ADC_CHANNEL_INTERNAL_0
#define ADC1_CHANNEL_VREFH0                      ADC_CHANNEL_INTERNAL_1
#define ADC1_CHANNEL_VDDA0                       ADC_CHANNEL_INTERNAL_2
#define ADC1_CHANNEL_V15                         ADC_CHANNEL_INTERNAL_3
#define ADC1_CHANNEL_CMP0_DAC                    ADC_CHANNEL_INTERNAL_4
#define ADC1_CHANNEL_TEMPSENSOR_OUT              ADC_CHANNEL_INTERNAL_5

#define ADC2_CHANNEL_V11_PD1                     ADC_CHANNEL_INTERNAL_0
#define ADC2_CHANNEL_VREFH1                      ADC_CHANNEL_INTERNAL_1
#define ADC2_CHANNEL_VDDA1                       ADC_CHANNEL_INTERNAL_2
#define ADC2_CHANNEL_SDADC_VDDA_DIV2             ADC_CHANNEL_INTERNAL_3
#define ADC2_CHANNEL_SDADC_VBIAS                 ADC_CHANNEL_INTERNAL_4

#define ADC3_CHANNEL_V11_PD1                     ADC_CHANNEL_INTERNAL_0
#define ADC3_CHANNEL_VREFH1                      ADC_CHANNEL_INTERNAL_1
#define ADC3_CHANNEL_VDDA1                       ADC_CHANNEL_INTERNAL_2
#define ADC3_CHANNEL_SDADC_VDDA_DIV2             ADC_CHANNEL_INTERNAL_3
#define ADC3_CHANNEL_SDADC_VBIAS                 ADC_CHANNEL_INTERNAL_4

#endif /* _DEVICE_FEATURES_FC7300F4MDDxxxxxT1C_ADC_COMMON_H_ */
