#ifndef _DEVICE_FEATURES_FC7300F8MDQxxxxxT1B_FLEXCAN_COMMON_H_
#define _DEVICE_FEATURES_FC7300F8MDQxxxxxT1B_FLEXCAN_COMMON_H_

/*********************** FLEXCAN Features ****************************/


/** Number of instances of the FLEXCAN module. */
#define FLEXCAN_INSTANCE_COUNT                  (14u)


/**
 * @brief The instance index of the CAN peripheral
 *
 */
typedef enum
{
    FLEXCAN_INSTANCE_0 = 0U,
    FLEXCAN_INSTANCE_1,
    FLEXCAN_INSTANCE_2,
    FLEXCAN_INSTANCE_3,
    FLEXCAN_INSTANCE_4,
    FLEXCAN_INSTANCE_5,
    FLEXCAN_INSTANCE_6,
    FLEXCAN_INSTANCE_7,
    FLEXCAN_INSTANCE_8,
    FLEXCAN_INSTANCE_9,
    FLEXCAN_INSTANCE_10,
    FLEXCAN_INSTANCE_11,
    FLEXCAN_INSTANCE_12,
    FLEXCAN_INSTANCE_13
} FLEXCAN_InstanceType;

/* Every CAN contains message buffer number */
#define FLEXCAN_MB_NUM_PTRS                     {96U,96U,96U,96U,96U,96U,96U,96U,32U,32U,32U,32U,32U,32U}
/* Number of instances of the FLEXCAN FD module. */
#define FLEXCAN_FD_SUPPORT_PTRS                 {1U,1U,1U,1U,1U,1U,1U,1U,0U,0U,0U,0U,0U,0U}
/* Support Gate */
#define FLEXCAN_GATE_BUFNUM_PTRS                {0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U}
/* Support pretend network */
#define FLEXCAN_PNET_SUPPORT_PTRS               {1U,1U,1U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U}

/* IFlag1...IFlagn, IMask1...IMaskn */
#define FLEXCAN_IFLAGMASK_NUM_PTRS              {3U,3U,3U,3U,3U,3U,3U,3U,1U,1U,1U,1U,1U,1U}
#define FLEXCAN_IFLAGMASK_NUM_MAX               3U

/* MBDSR0..MBDSRn */
#define FLEXCAN_FD_DATALEN_RANGE_NUM_PTRS       {3U,3U,3U,3U,3U,3U,3U,3U,1U,1U,1U,1U,1U,1U}
#define FLEXCAN_FD_DATALEN_RANGE_NUM_MAX        3U

/* Enhanced Rx FIFO */
#define FLEXCAN_ENHANCED_FIFO_ELEMENT_MAX_PTRS   {78U,78U,78U,78U,78U,78U,78U,78U,0U,0U,0U,0U,0U,0U}
#define FLEXCAN_ENHANCED_FIFO_DEPTH_PTRS         {20U,20U,20U,20U,20U,20U,20U,20U,0U,0U,0U,0U,0U,0U}

/*Error interrupt split */
#define FLEXCAN_INTERRUPT_ERROR_SPLIT STD_ON

#define FLEXCAN_LEGACY_FIFO_DEPTH                6U
#define FLEXCAN_LEGACY_FIFO_FILTER_START         6U
#define FLEXCAN_LEGACY_FIFO_ELEMENT_MAX          128U
#define FLEXCAN_LEGACY_FIFO_NUM_TABLE_LENGTH     16U
#define FLEXCAN_LEGACY_FIFO_PTRS  { \
                                /* RFFN[3:0]    Filter Num    MB for Legacy  */ \
                                {  0U,          8U,           8U  }, \
                                {  1U,          16U,          10U }, \
                                {  2U,          24U,          12U }, \
                                {  3U,          32U,          14U }, \
                                {  4U,          40U,          16U }, \
                                {  5U,          48U,          18U }, \
                                {  6U,          56U,          20U }, \
                                {  7U,          64U,          22U }, \
                                {  8U,          72U,          24U }, \
                                {  9U,          80U,          26U }, \
                                {  0xAU,        88U,          28U }, \
                                {  0XBU,        96U,          30U }, \
                                {  0XCU,        104U,         32U }, \
                                {  0XDU,        112U,         34U }, \
                                {  0XEU,        120U,         36U }, \
                                {  0XFU,        128U,         38U } \
                            }














/** Array initializer of FLEXCAN peripheral base addresses */
#define FLEXCAN_BASE_ADDRS                       {FLEXCAN0_BASE, FLEXCAN1_BASE, FLEXCAN2_BASE, FLEXCAN3_BASE, FLEXCAN4_BASE, FLEXCAN5_BASE,FLEXCAN6_BASE,FLEXCAN7_BASE,FLEXCAN8_BASE,FLEXCAN9_BASE,FLEXCAN10_BASE,FLEXCAN11_BASE,FLEXCAN12_BASE,FLEXCAN13_BASE}
/** Array initializer of FLEXCAN peripheral base pointers */
#define FLEXCAN_BASE_PTRS                        {FLEXCAN0, FLEXCAN1, FLEXCAN2, FLEXCAN3, FLEXCAN4, FLEXCAN5,FLEXCAN6,FLEXCAN7,FLEXCAN8,FLEXCAN9,FLEXCAN10,FLEXCAN11,FLEXCAN12,FLEXCAN13}


#define FLEXCAN_ERRATA_TRANSMIT_LIMIT           STD_ON
#define FLEXCAN_ERRATA_TRANSMIT_LM_LIST         {9U,17U,19U,27U,29U,37U,39U,47U,49U,57U,59U,67U,69U,77U,79U,87U}
#define FLEXCAN_ERRATA_TRANSMIT_LM_LIST_LEN     16U

#endif /* _DEVICE_FEATURES_FC7300F8MDQxxxxxT1B_FLEXCAN_COMMON_H_ */
