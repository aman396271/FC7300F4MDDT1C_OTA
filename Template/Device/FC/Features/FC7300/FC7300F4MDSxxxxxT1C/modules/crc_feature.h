#ifndef _DEVICE_FEATURES_FC7300F4MDSxxxxxT1C_CRC_COMMON_H_
#define _DEVICE_FEATURES_FC7300F4MDSxxxxxT1C_CRC_COMMON_H_

/************ CRC Features **************/
/** Whether Crc 8-bit is supported in Crc */
#define CRC_8_BIT_HARDWARE_SUPPORT               (1u)

/** Number of instances of the CRC module. */
#define CRC_INSTANCE_COUNT                       (1u)


/** Array initializer of CRC peripheral base addresses */
#define CRC_BASE_ADDRS                           {CRC0_BASE}
/** Array initializer of CRC peripheral base pointers */
#define CRC_BASE_PTRS                            {CRC0}

/**
 * @brief Enumeration for CRC module instances.
 *
 * This enum defines the available instances of the CRC module in the system.
 * Each instance corresponds to a physical CRC peripheral.
 */
typedef enum
{
    CRC_INSTANCE_0 = 0U,
} Crc_InstanceType;

#endif /* _DEVICE_FEATURES_FC7300F4MDSxxxxxT1C_CRC_COMMON_H_ */
