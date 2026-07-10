#ifndef _DEVICE_FEATURES_FC7300F8MDTxxxxxT1B_CPM_COMMON_H_
#define _DEVICE_FEATURES_FC7300F8MDTxxxxxT1B_CPM_COMMON_H_


#define CPU_CORE_NUM                3U
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

    __asm volatile(
        "movw  r0, %[miscr_base_l]                                       \n"
        "movt  r0, %[miscr_base_h]                                       \n"
        "ldr   %[core_id], [r0]                                          \n"
        "add   r0, r0, %[lock_base_offset]                               \n"
        "ldr   r0, [r0]                                                  \n"
        "ubfx  %[core_id], %[core_id], %[cpu_id_shift], %[cpu_id_len]    \n"
        : [core_id]"=r"(CoreId)
        : [miscr_base_l]"i"(COM_CPM_MISCR_BASE_L),       [miscr_base_h]"i"(COM_CPM_MISCR_BASE_H),
          [lock_base_offset]"i"(COM_CPM_LOCK_BASE_OFFSET),
          [cpu_id_shift]"i"(COM_CPM_MISCR_CPU_ID_SHIFT), [cpu_id_len]"i"(COM_CPM_MISCR_CPU_ID_LENGTH)
        : "r0"
    );
    return (unsigned char)CoreId;
}

#define CPM_ERRATA       STD_ON

#endif /* _DEVICE_FEATURES_FC7300F8MDTxxxxxT1B_CPM_COMMON_H_ */
