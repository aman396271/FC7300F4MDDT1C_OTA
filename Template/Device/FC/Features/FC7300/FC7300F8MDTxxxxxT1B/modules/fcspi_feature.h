#ifndef _DEVICE_FEATURES_FC7300F8MDTxxxxxT1B_FCSPI_COMMON_H_
#define _DEVICE_FEATURES_FC7300F8MDTxxxxxT1B_FCSPI_COMMON_H_

/************ FCSPI Features **************/
/** Number of instances of the FCSPI module. */


#define FCSPI_NOT_SUPPORT_CSEN_SAMPLE_2nd_EDGE

#define FCSPI_INSTANCE_COUNT                     (8u)

/* FCSPI - Peripheral instance base addresses */
/** Peripheral FCSPI0 base address */
#define FCSPI0_BASE                              (0x40062000u)
/** Peripheral FCSPI0 base pointer */
#define FCSPI0                                   ((FCSPI_Type *)FCSPI0_BASE)
/** Peripheral FCSPI1 base address */
#define FCSPI1_BASE                              (0x40063000u)
/** Peripheral FCSPI1 base pointer */
#define FCSPI1                                   ((FCSPI_Type *)FCSPI1_BASE)
/** Peripheral FCSPI2 base address */
#define FCSPI2_BASE                              (0x40064000u)
/** Peripheral FCSPI2 base pointer */
#define FCSPI2                                   ((FCSPI_Type *)FCSPI2_BASE)
/** Peripheral FCSPI3 base address */
#define FCSPI3_BASE                              (0x40065000u)
/** Peripheral FCSPI3 base pointer */
#define FCSPI3                                   ((FCSPI_Type *)FCSPI3_BASE)
/** Peripheral FCSPI4 base address */
#define FCSPI4_BASE                              (0x40470000u)
/** Peripheral FCSPI4 base pointer */
#define FCSPI4                                   ((FCSPI_Type *)FCSPI4_BASE)
/** Peripheral FCSPI5 base address */
#define FCSPI5_BASE                              (0x40471000u)
/** Peripheral FCSPI5 base pointer */
#define FCSPI5                                   ((FCSPI_Type *)FCSPI5_BASE)
/** Peripheral FCSPI6 base address */
#define FCSPI6_BASE                              (0x40448000u)
/** Peripheral FCSPI6 base pointer */
#define FCSPI6                                   ((FCSPI_Type *)FCSPI6_BASE)
/** Peripheral FCSPI7 base address */
#define FCSPI7_BASE                              (0x40449000u)
/** Peripheral FCSPI7 base pointer */
#define FCSPI7                                   ((FCSPI_Type *)FCSPI7_BASE)

/** Array initializer of FCSPI peripheral base addresses */
#define FCSPI_BASE_ADDRS                         {FCSPI0_BASE, FCSPI1_BASE, FCSPI2_BASE, FCSPI3_BASE, FCSPI4_BASE, FCSPI5_BASE, FCSPI6_BASE, FCSPI7_BASE}
/** Array initializer of FCSPI peripheral base pointers */
#define FCSPI_BASE_PTRS                          {FCSPI0, FCSPI1, FCSPI2, FCSPI3, FCSPI4, FCSPI5, FCSPI6, FCSPI7}

/**
 * @name FCSPI_InstanceType
 * @brief FCSpi hardware instances
 *
 * FCSpi consist of multiple hardware instances, for example, FCSPI0, FCSPI1...
 * Just as the enumeration type "FCSPI_InstanceType" definition shows.
 * We use variables of this type to indicate which hardware instance to use.
 * @{
 */
typedef enum {
    FCSPI_INSTANCE_0 = 0, /**< Select FCSPI0 */
    FCSPI_INSTANCE_1 = 1, /**< Select FCSPI1 */
    FCSPI_INSTANCE_2 = 2, /**< Select FCSPI2 */
    FCSPI_INSTANCE_3 = 3, /**< Select FCSPI3 */
    FCSPI_INSTANCE_4 = 4, /**< Select FCSPI4 */
    FCSPI_INSTANCE_5 = 5, /**< Select FCSPI5 */
    FCSPI_INSTANCE_6 = 6, /**< Select FCSPI6 */ 
    FCSPI_INSTANCE_7 = 7  /**< Select FCSPI7 */
} FCSPI_InstanceType;
/** @}*/


#endif /* _DEVICE_FEATURES_FC7300F8MDTxxxxxT1B_FCSPI_COMMON_H_ */
