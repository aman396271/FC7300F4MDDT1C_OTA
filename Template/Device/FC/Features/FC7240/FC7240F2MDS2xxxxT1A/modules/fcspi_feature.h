#ifndef _DEVICE_FEATURES_FC7240F2MDS2_FCSPI_COMMON_H_
#define _DEVICE_FEATURES_FC7240F2MDS2_FCSPI_COMMON_H_


/************ FCSPI Features **************/
/** Number of instances of the FCSPI module. */
#define FCSPI_INSTANCE_COUNT                     (4u)

/** Array initializer of FCSPI peripheral base addresses */
#define FCSPI_BASE_ADDRS                         {FCSPI0_BASE, FCSPI1_BASE, FCSPI2_BASE, FCSPI3_BASE}
/** Array initializer of FCSPI peripheral base pointers */
#define FCSPI_BASE_PTRS                          {FCSPI0, FCSPI1, FCSPI2, FCSPI3}

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
    FCSPI_INSTANCE_3 = 3  /**< Select FCSPI3 */
} FCSPI_InstanceType;

#endif /* _DEVICE_FEATURES_FC7240F2MDS2_FCSPI_COMMON_H_ */
