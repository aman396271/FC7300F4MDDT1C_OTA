#ifndef _DEVICE_FEATURES_FC7300F8MDQxxxxxT1B_CPM_COMMON_H_
#define _DEVICE_FEATURES_FC7300F8MDQxxxxxT1B_CPM_COMMON_H_


#define CPU_CORE_NUM                4U
#define COM_CPM_MISCR_BASE          0xE0080004UL
#define COM_CPM_MISCR_BASE_H        0xE008U
#define COM_CPM_MISCR_BASE_L        0x0004U
#define COM_CPM_LOCK_BASE           0xE0080020UL
#define COM_CPM_LOCK_BASE_OFFSET    0x1CU
#define COM_CPM_MISCR_CPU_ID_MASK   0x000E0000UL
#define COM_CPM_MISCR_CPU_ID_LENGTH 3U
#define COM_CPM_MISCR_CPU_ID_SHIFT  17U

typedef enum
{
    CPM_CPU_ID_CORE0 = 0U,
    CPM_CPU_ID_CORE1,
    CPM_CPU_ID_CORE2,
    CPM_CPU_ID_CORE3,
    CPM_CPU_ID_ERROR
} CpmCoreId;

/**
 * @brief Get Core ID
 *
 * @return Core ID
 */
__attribute__((always_inline)) static inline unsigned char Cpm_HWA_GetCoreId(void)
{
    register uint32 CoreId;
    CoreId = *((volatile unsigned int *)COM_CPM_MISCR_BASE);
    CoreId = (CoreId & 0xE0000) >> 17;

    return (unsigned char)CoreId;
}

#define CPM_ERRATA       STD_OFF

#endif /* _DEVICE_FEATURES_FC7300F8MDQxxxxxT1B_CPM_COMMON_H_ */
