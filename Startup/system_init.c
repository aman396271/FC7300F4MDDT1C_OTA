/**
 * @file system_init.c
 * @author Flagchip
 * @brief interrupt configuration
 * @version 2.0.0
 * @date 2024-07-14
 *
 * @copyright Copyright (c) 2024 Flagchip Semiconductors Co., Ltd.
 *
 */

typedef unsigned int    uint32;
typedef unsigned short  uint16;
typedef unsigned char   uint8;

#define CORE_NUM                3U
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


#define SCB_CPACR     0xE000ED88
/* #define DATA_IN_DTCM */

#if defined(__GNUC__) || defined(__ghs__)
    extern uint32 __data_start__[];
    extern uint32 __data_end__[];
    extern uint32 __data_init_start__[];
    extern uint32 __bss_start__[];
    extern uint32 __bss_end__[];
#elif defined(__ICCARM__)
    #pragma section = ".data"
    #pragma section = ".data_init"
    #pragma section = ".bss"

    uint32 *const __data_start__             = (uint32 *)(__section_begin(".data"));
    uint32 *const __data_end__               = (uint32 *)(__section_end(".data"));
    uint32 *const __data_init_start__             = (uint32 *)(__section_begin(".data_init"));
    uint32 *const __bss_start__                  = (uint32 *)(__section_begin(".bss"));
    uint32 *const __bss_end__                    = (uint32 *)(__section_end(".bss"));
#endif

extern void data_init(void);
extern void system_init(void);

static void data_clear(uint32 *pHead, uint32 *pTail)
{
    while (pHead < pTail)
    {
        *pHead = 0U;
        pHead++;
    }
}

static void data_copy(uint32 *pHead, uint32 *pTail, uint32 *pSrc)
{
    while (pHead < pTail)
    {
        *pHead = *pSrc;
        pHead++;
        pSrc++;
    }
}

void data_init(void)
{
    /* data and bss is in sram, and only need to initial once */
    if (0U == Cpm_HWA_GetCoreId())
    {
        /* bss */
        data_clear(__bss_start__, __bss_end__);
        /* data */
        data_copy(__data_start__, __data_end__, __data_init_start__);
    }

}

void system_init(void)
{
    if (0U == Cpm_HWA_GetCoreId())
    {
        /* only power on reset or low power reset need to clear all ram */
        // if ( 0U != ((*(volatile uint32 *)0x40046008) & 0x82 ) )
        {
            /* ------------------ NVR must set ITCM initial auto enable ------------------ */
            /* disable AXBS/CPU0/1/ ECC */
            *(volatile uint32 *)0x40072020 = 0x0AAAAAAA;
            *(volatile uint32 *)0x40072024 = 0x000003AA;
            *(volatile uint32 *)0x40072028 = 0x00000AAA;
            *(volatile uint32 *)0x40072030 = 0x00000AAA;

            /* STCU PCC Enable*/
            *(volatile uint32 *)0x400241FC = 0x00800000;
            /* clear all itcm dtcm sram*/
            *(volatile uint32 *)0x4007f050 = 0x1FFF;
            *(volatile uint32 *)0x4007f048 = 1u;

            while (0 == ((*(volatile uint32 *)0x4007f04C) & 2u)); /* wait busy */
            while (0 == ((*(volatile uint32 *)0x4007f04C) & 1u)); /* wait done */

            /* enable AXBS/CPU0/1/ ECC */
            *(volatile uint32 *)0x40072020 = 0x0FFFFFFF;
            *(volatile uint32 *)0x40072024 = 0x000003FF;
            *(volatile uint32 *)0x40072028 = 0x00000FFF;
            *(volatile uint32 *)0x40072030 = 0x00000FFF;

        }

        /* disable wdog 0 */
        *(volatile uint32 *)0x40022004 = 0x08181982;
        while (0U == (0x800u & *(volatile uint32 *)0x40022000));
        *(volatile uint32 *)0x40022000 = 0x2920;
        *(volatile uint32 *)0x40022008 = 0xF000;
        while (0U == (0x400u & *(volatile uint32 *)0x40022000));
    }
    else if (1U == Cpm_HWA_GetCoreId())
    {
        /* disable wdog 1 */
        *(volatile uint32 *)0x40433004 = 0x08181982;

        while (0U == (0x800u & *(volatile uint32 *)0x40433000));
        *(volatile uint32 *)0x40433000 = 0x2920;
        *(volatile uint32 *)0x40433008 = 0xF000;
        while (0U == (0x400u & *(volatile uint32 *)0x40433000));
    }
    else
    {

    }

#if ((__FPU_PRESENT == 1) && (__FPU_USED == 1))
    *(volatile uint32*)0xE000ED88 = 0x00F00000u;    /* set CP10, CP11 Full Access */
#endif /* ((__FPU_PRESENT == 1) && (__FPU_USED == 1)) */

    asm volatile("mov pc, lr");
}
