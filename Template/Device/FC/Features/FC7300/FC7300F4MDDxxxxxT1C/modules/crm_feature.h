#ifndef _DEVICE_FEATURES_FC7300F4MDDxxxxxT1C_CRM_H_
#define _DEVICE_FEATURES_FC7300F4MDDxxxxxT1C_CRM_H_

/*************************** CRM Module Configuration ****************************/

/**
 * @brief CRM Availability Definition
 * 
 * CRM is only available on FC7300F4MDDxxxT1C variants
 * FC7300F4MDSxxxT1C do not include this module
 */
#define CRM_MODULE_AVAILABLE                     STD_ON
/* CRM Instance Count */
#define CRM_INSTANCE_COUNT                       (1u)
/* CRM Channel Count */
#define CRM_CHANNEL_COUNT                        (4u)

/**
 * @brief CRM channel selection type
 */
typedef enum
{
    CRM_CH0 = 0U,   /**< Channel 0 */
    CRM_CH1 = 1U,   /**< Channel 1 */
    CRM_CH2 = 2U,   /**< Channel 2 */
    CRM_CH3 = 3U,   /**< Channel 3 */
    CRM_CHMAX = 4U    /**< Channel 3 */
} CRM_ChannelIndex;

/**
 * @brief CRM-FLEXCAN Channel Mapping
 * 
 * Defines which FLEXCAN instance is connected to each CRM channel
 */
#define CRM_CHANNEL_TO_FLEXCAN_MAPPING \
{ \
    FLEXCAN_INSTANCE_4,  /* CRM_CHANNEL_0 -> FLEXCAN4 */ \
    FLEXCAN_INSTANCE_5,  /* CRM_CHANNEL_1 -> FLEXCAN5 */ \
    FLEXCAN_INSTANCE_6,  /* CRM_CHANNEL_2 -> FLEXCAN6 */ \
    FLEXCAN_INSTANCE_7   /* CRM_CHANNEL_3 -> FLEXCAN7 */ \
}

/* Router Table Width per Channel */
#define CRM_ROUTER_TABLE_WIDTH                   (2u)

/**
 * @brief DMA Request to CRM Channel Mapping
 * 
 * Maps DMA request lines to their corresponding source CRM channels
 */
#define DMA_REQUEST_TO_CRM_CHANNEL \
{ \
    CRM_CHANNEL_0,  /* DMA_REQ_0  */ \
    CRM_CHANNEL_0,  /* DMA_REQ_1  */ \
    CRM_CHANNEL_0,  /* DMA_REQ_2  */ \
    CRM_CHANNEL_0,  /* DMA_REQ_3  */ \
    CRM_CHANNEL_1,  /* DMA_REQ_4  */ \
    CRM_CHANNEL_1,  /* DMA_REQ_5  */ \
    CRM_CHANNEL_1,  /* DMA_REQ_6  */ \
    CRM_CHANNEL_1,  /* DMA_REQ_7  */ \
    CRM_CHANNEL_2,  /* DMA_REQ_8  */ \
    CRM_CHANNEL_2,  /* DMA_REQ_9  */ \
    CRM_CHANNEL_2,  /* DMA_REQ_10 */ \
    CRM_CHANNEL_2,  /* DMA_REQ_11 */ \
    CRM_CHANNEL_3,  /* DMA_REQ_12 */ \
    CRM_CHANNEL_3,  /* DMA_REQ_13 */ \
    CRM_CHANNEL_3,  /* DMA_REQ_14 */ \
    CRM_CHANNEL_3   /* DMA_REQ_15 */ \
}

/**
 * @brief Destination Message Buffer Mapping
 * 
 * Specifies the target message buffer for each CRM channel
 */
#define CRM_CHANNEL_TO_DST_MB \
{ \
    0u,  /* CRM_CHANNEL_0 -> DST MB0 */ \
    1u,  /* CRM_CHANNEL_1 -> DST MB1 */ \
    2u,  /* CRM_CHANNEL_2 -> DST MB2 */ \
    3u   /* CRM_CHANNEL_3 -> DST MB3 */ \
}

/* Enhanced FIFO Element Count per CRM Channel */
#define CRM_ENHANCED_FIFO_ELEMENT_COUNT \
{ \
    FLEXCAN_ENHANCED_FIFO_ELEMENT_MAX_PTRS[4],  /* CH0 */ \
    FLEXCAN_ENHANCED_FIFO_ELEMENT_MAX_PTRS[5],  /* CH1 */ \
    FLEXCAN_ENHANCED_FIFO_ELEMENT_MAX_PTRS[6],  /* CH2 */ \
    FLEXCAN_ENHANCED_FIFO_ELEMENT_MAX_PTRS[7]   /* CH3 */ \
}

/* CAN FD Support per CRM Channel */
#define CRM_CHANNEL_FD_SUPPORT \
{ \
    FLEXCAN_FD_SUPPORT_PTRS[4],  /* CH0 */ \
    FLEXCAN_FD_SUPPORT_PTRS[5],  /* CH1 */ \
    FLEXCAN_FD_SUPPORT_PTRS[6],  /* CH2 */ \
    FLEXCAN_FD_SUPPORT_PTRS[7]   /* CH3 */ \
}

/* Message Buffer Count per CRM Channel */
#define CRM_CHANNEL_MB_COUNT \
{ \
    FLEXCAN_MB_NUM_PTRS[4],  /* CH0 */ \
    FLEXCAN_MB_NUM_PTRS[5],  /* CH1 */ \
    FLEXCAN_MB_NUM_PTRS[6],  /* CH2 */ \
    FLEXCAN_MB_NUM_PTRS[7]   /* CH3 */ \
}

/* Peripheral Base Address */
#define CRM_BASE                                (0x40444000u)

#endif /* _DEVICE_FEATURES_FC7300F4MDDxxxxxT1C_CRM_H_ */
