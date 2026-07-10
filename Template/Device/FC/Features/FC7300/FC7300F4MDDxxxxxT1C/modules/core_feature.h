#ifndef _DEVICE_FEATURES_FC7300F4MDDxxxxxT1C_CORE_COMMON_H_
#define _DEVICE_FEATURES_FC7300F4MDDxxxxxT1C_CORE_COMMON_H_

/**
  * @brief Configuration of the Cortex-M4 Processor and Core Peripherals
  */
#define __MPU_PRESENT             1U       /*!< CM7 provides an MPU                           */
#define __NVIC_PRIO_BITS          3U       /*!< CM7 uses 4 Bits for the Priority Levels       */
#define __Vendor_SysTickConfig    0U       /*!< Set to 1 if different SysTick Config is used  */
#define __FPU_PRESENT             1U       /*!< FPU present                                   */
#define __ICACHE_PRESENT          1U       /*!< CM7 instruction cache present                 */
#define __DCACHE_PRESENT          1U       /*!< CM7 data cache present                        */

typedef enum
{
    /* Auxiliary constants */
    NotAvail_IRQn = -128, /**< Not available device specific interrupt */

    /* Core interrupts */
    NonMaskableInt_IRQn                = -14,   /**< Non Maskable Interrupt */
    HardFault_IRQn                     = -13,   /**< Cortex-M7 Hard Fault Interrupt */
    MemoryManagement_IRQn              = -12,   /**< Cortex-M7 Memory Management Interrupt */
    BusFault_IRQn                      = -11,   /**< Cortex-M7 Bus Fault Interrupt */
    UsageFault_IRQn                    = -10,   /**< Cortex-M7 Usage Fault Interrupt */
    SVCall_IRQn                        = -5,    /**< Cortex-M7 SV Call Interrupt */
    DebugMonitor_IRQn                  = -4,    /**< Cortex-M7 Debug Monitor Interrupt */
    PendSV_IRQn                        = -2,    /**< Cortex-M7 Pend SV Interrupt */
    SysTick_IRQn                       = -1,    /**< Cortex-M7 System Tick Interrupt */

    /* Device specific interrupts */
    DMA0_IRQn                          = 0U,     /**< DMA channel 0 transfer complete */
    DMA1_IRQn                          = 1U,     /**< DMA channel 1 transfer complete */
    DMA2_IRQn                          = 2U,     /**< DMA channel 2 transfer complete */
    DMA3_IRQn                          = 3U,     /**< DMA channel 3 transfer complete */
    DMA4_IRQn                          = 4U,     /**< DMA channel 4 transfer complete */
    DMA5_IRQn                          = 5U,     /**< DMA channel 5 transfer complete */
    DMA6_IRQn                          = 6U,     /**< DMA channel 6 transfer complete */
    DMA7_IRQn                          = 7U,     /**< DMA channel 7 transfer complete */
    DMA8_IRQn                          = 8U,     /**< DMA channel 8 transfer complete */
    DMA9_IRQn                          = 9U,     /**< DMA channel 9 transfer complete */
    DMA10_IRQn                         = 10U,    /**< DMA channel 10 transfer complete */
    DMA11_IRQn                         = 11U,    /**< DMA channel 11 transfer complete */
    DMA12_IRQn                         = 12U,    /**< DMA channel 12 transfer complete */
    DMA13_IRQn                         = 13U,    /**< DMA channel 13 transfer complete */
    DMA14_IRQn                         = 14U,    /**< DMA channel 14 transfer complete */
    DMA15_IRQn                         = 15U,    /**< DMA channel 15 transfer complete */
    DMA16_IRQn                         = 16U,    /**< DMA channel 16 transfer complete */
    DMA17_IRQn                         = 17U,    /**< DMA channel 17 transfer complete */
    DMA18_IRQn                         = 18U,    /**< DMA channel 18 transfer complete */
    DMA19_IRQn                         = 19U,    /**< DMA channel 19 transfer complete */
    DMA20_IRQn                         = 20U,    /**< DMA channel 20 transfer complete */
    DMA21_IRQn                         = 21U,    /**< DMA channel 21 transfer complete */
    DMA22_IRQn                         = 22U,    /**< DMA channel 22 transfer complete */
    DMA23_IRQn                         = 23U,    /**< DMA channel 23 transfer complete */
    DMA24_IRQn                         = 24U,    /**< DMA channel 24 transfer complete */
    DMA25_IRQn                         = 25U,    /**< DMA channel 25 transfer complete */
    DMA26_IRQn                         = 26U,    /**< DMA channel 26 transfer complete */
    DMA27_IRQn                         = 27U,    /**< DMA channel 27 transfer complete */
    DMA28_IRQn                         = 28U,    /**< DMA channel 28 transfer complete */
    DMA29_IRQn                         = 29U,    /**< DMA channel 29 transfer complete */
    DMA30_IRQn                         = 30U,    /**< DMA channel 30 transfer complete */
    DMA31_IRQn                         = 31U,    /**< DMA channel 31 transfer complete */
    DMA0_Error_IRQn                     = 32U,    /**< DMA error interrupt channels 0-31 */
    CPM0_IRQn                           = 33U,    /**< FPU etc. interrupt */
    FC0_IRQn                           = 34U,    /**< Flash Controller Command complete, time out etc. interrupt */
    PMC0_IRQn                       = 35U,    /**< HVD/LVD etc. interrupt */
    TMU0_IRQn                          = 36U,    /**< Temperature Monitor Unit interrupt */
    WDOG0_IRQn                         = 37U,    /**< interrupt request out before wdg reset out */
    WDOG1_IRQn                         = 38U,    /**< interrupt request out before wdg reset out */
    FCSMU0_IRQn                        = 40U,    /**< Fault Control and Safety Manage Unit */
    STCU0_IRQn                         = 41U,    /**< Safety Control Unit interrupt */
    ERM0_IRQn                           = 42U,    /**< ERM single or double bit error interrupt */
    MAM0_IRQn                          = 43U,    /**< Matrix Access Monitor interrupt */
    MAM1_IRQn                          = 44U,    /**< Matrix Access Monitor interrupt */
    CTI0_IRQn                          = 45U,    /**< CTI Interrupt */
    CTI1_IRQn                          = 46U,    /**< CTI Interrupt */
	RGM0_Pre_IRQn                       = 47U,    /**< RGM pre-reset Interrupt */
	RGM0_Exit_IRQn                     = 48U,    /**< RGM other cpu exit reset Interrupt */
    INTM0_IRQn                         = 49U,    /**< INTM timeout interrupt */
    ISM0_IRQn                          = 50U,    /**< ISM0 interrupt */
    MB0_IRQn                           = 51U,    /**< Mail Box interrupt */
    SCG0_IRQn                           = 52U,    /**< SCG bus interrupt request */
    CMU0_IRQn                          = 53U,    /**< CMU0 interrupt */
    CMU1_IRQn                          = 54U,    /**< CMU1 interrupt */
    CMU2_IRQn                          = 55U,    /**< CMU2 interrupt */
    CMU3_IRQn                          = 56U,    /**< CMU3 interrupt */
    TSTMP0_IRQn                       = 57U,    /**< TimerStamp interrupt */
    TSTMP1_IRQn                       = 58U,    /**< TimerStamp interrupt */
    TSTMP2_IRQn                       = 59U,    /**< TimerStamp interrupt */
    CMU4_IRQn                          = 60U,    /**< CMU4 interrupt */
    CORDIC0_IRQn                       = 61U,    /**< CORDIC Accelerator interrupt */
    HSM0_Error_IRQn                    = 62U,    /**< HSM error interrupt */
    FCPIT0_IRQn                        = 63U,    /**< FCPIT interrupt */
    RTC0_IRQn                           = 65U,    /**< RTC alarm or seconds interrupt */
    ENET_Tx0_IRQn                      = 66U,    /**< ENET TX Channel 0 Interrupt */
    ENET_Tx1_IRQn                      = 67U,    /**< ENET TX Channel 1 Interrupt */
    ENET_Rx0_IRQn                      = 68U,    /**< ENET RX Channel 0 Interrupt */
    ENET_Rx1_IRQn                      = 69U,    /**< ENET RX Channel 1 Interrupt */
    ENET_System_IRQn                   = 70U,    /**< ENET system interrupt */
    AONTIMER0_IRQn                     = 71U,    /**< AONTIMER interrupt request */
    SWI_IRQn                      = 72U,    /**< Software interrupt */
    FREQM0_IRQn                         = 74U,    /**< FREQM interrupt */
    PORTA_IRQn                         = 75U,    /**< PORTA Interrupt */
    PORTB_IRQn                         = 76U,    /**< PORTB Interrupt */
    PORTC_IRQn                         = 77U,    /**< PORTC Interrupt */
    PORTD_IRQn                         = 78U,    /**< PORTD Interrupt */
    PORTE_IRQn                         = 79U,    /**< PORTE Interrupt */
    PORTF_IRQn                         = 80U,    /**< PORTF Interrupt */
    PORTG_IRQn                         = 81U,    /**< PORTG Interrupt */
    PORTH_IRQn                         = 82U,    /**< PORTH Interrupt */
    PORTI_IRQn                         = 83U,    /**< PORTI Interrupt */
    FlexCAN0_IRQn                      = 84U,    /**< FLEXCAN interrupt(except error related interrupt) */
    FlexCAN1_IRQn                      = 85U,    /**< FLEXCAN interrupt(except error related interrupt) */
    FlexCAN2_IRQn                      = 86U,    /**< FLEXCAN interrupt(except error related interrupt) */
    FlexCAN3_IRQn                      = 87U,    /**< FLEXCAN interrupt(except error related interrupt) */
    FlexCAN4_IRQn                      = 88U,    /**< FLEXCAN interrupt(except error related interrupt) */
    FlexCAN5_IRQn                      = 89U,    /**< FLEXCAN interrupt(except error related interrupt) */
    FlexCAN6_IRQn                      = 90U,    /**< FLEXCAN interrupt(except error related interrupt) */
    FlexCAN7_IRQn                      = 91U,    /**< FLEXCAN interrupt(except error related interrupt) */
    FCIIC0_IRQn                        = 92U,    /**< FCIIC Interrupt */
    FCIIC1_IRQn                        = 93U,    /**< FCIIC Interrupt */
    FCSPI0_IRQn                        = 94U,    /**< FCSPI Interrupt */
    FCSPI1_IRQn                        = 95U,    /**< FCSPI Interrupt */
    FCSPI2_IRQn                        = 96U,    /**< FCSPI Interrupt */
    FCSPI3_IRQn                        = 97U,    /**< FCSPI Interrupt */
    FCSPI4_IRQn                        = 98U,    /**< FCSPI Interrupt */
    FCSPI5_IRQn                        = 99U,    /**< FCSPI Interrupt */
    FCUART0_IRQn                       = 100U,   /**< FCUART Interrupt */
    FCUART1_IRQn                       = 101U,   /**< FCUART Interrupt */
    FCUART2_IRQn                       = 102U,   /**< FCUART Interrupt */
    FCUART3_IRQn                       = 103U,   /**< FCUART Interrupt */
    FCUART4_IRQn                       = 104U,   /**< FCUART Interrupt */
    FCUART5_IRQn                       = 105U,   /**< FCUART Interrupt */
    FCUART6_IRQn                       = 106U,   /**< FCUART Interrupt */
    FCUART7_IRQn                       = 107U,   /**< FCUART Interrupt */
    FTU0_IRQn                          = 108U,   /**< FTU all source interrupt */
    FTU1_IRQn                          = 109U,   /**< FTU all source interrupt */
    FTU2_IRQn                          = 110U,   /**< FTU all source interrupt */
    FTU3_IRQn                          = 111U,   /**< FTU all source interrupt */
    FTU4_IRQn                          = 112U,   /**< FTU all source interrupt */
    FTU5_IRQn                          = 113U,   /**< FTU all source interrupt */
    FTU6_IRQn                          = 114U,   /**< FTU all source interrupt */
    FTU7_IRQn                          = 115U,   /**< FTU all source interrupt */
    CMP0_IRQn                          = 116U,   /**< CMP interrupt request */
    ADC0_IRQn                          = 117U,   /**< ADC interrupt request */
    ADC1_IRQn                          = 118U,   /**< ADC interrupt request */
    ADC2_IRQn                          = 119U,   /**< ADC interrupt request */
    ADC3_IRQn                          = 120U,   /**< ADC interrupt request */
    PTIMER0_IRQn                       = 121U,   /**< PTIMER interrupt */
    PTIMER1_IRQn                       = 122U,   /**< PTIMER interrupt */
    PTIMER2_IRQn                       = 123U,   /**< PTIMER interrupt */
    PTIMER3_IRQn                       = 124U,   /**< PTIMER interrupt */
    MSC0_IRQn                          = 125U,   /**< MSC interrupt */
    SENT0_IRQn                         = 128U,   /**< SENT all interrupt (fast or slow) */
    SENT1_IRQn                         = 129U,   /**< SENT all interrupt (fast or slow) */
    SSI0_IRQn                          = 130U,   /**< SSI interrupt OR interrupt */
    SDADC0_CH0_IRQn                    = 131U,   /**< SDADC channel 0 interrupt */
    SDADC0_CH1_IRQn                    = 132U,   /**< SDADC channel 1 interrupt */
    LU0_IRQn                           = 133U,   /**< LU interrupt */
    LU1_IRQn                           = 134U,   /**< LU interrupt */
    HSM0_Crypto_IRQn                   = 135U,   /**< Crypto interrupt */
    EFTU0_Error_IRQn                   = 136U,   /**< eFTU all error source interrupt */
    EFTU0_TIM0_3_IRQn                  = 137U,   /**< eFTU TIM 0-3 source interrupt */
    EFTU0_TIM4_7_IRQn                  = 138U,   /**< eFTU TIM 4-7 source interrupt */
    EFTU0_TOM0_7_IRQn                  = 139U,   /**< eFTU TOM 0-7 source interrupt */
    EFTU0_TOM8_15_IRQn                 = 140U,   /**< eFTU TOM 8-15 source interrupt */
    FlexCAN0_Error_IRQn                = 141U,   /**< FLEXCAN Error interrupt */
    FlexCAN1_Error_IRQn                = 142U,   /**< FLEXCAN Error interrupt */
    FlexCAN2_Error_IRQn                = 143U,   /**< FLEXCAN Error interrupt */
    FlexCAN3_Error_IRQn                = 144U,   /**< FLEXCAN Error interrupt */
    FlexCAN4_Error_IRQn                = 145U,   /**< FLEXCAN Error interrupt */
    FlexCAN5_Error_IRQn                = 146U,   /**< FLEXCAN Error interrupt */
    FlexCAN6_Error_IRQn                = 147U,   /**< FLEXCAN Error interrupt */
    FlexCAN7_Error_IRQn                = 148U,   /**< FLEXCAN Error interrupt */
    CRM0_IRQn                          = 149U,   /**< CAN Routing Module */
    LDI0_IRQn                          = 150U    /**< LED Driver Interface */

} IRQn_Type;
#if (__MPU_PRESENT == 1)
/** @defgroup CORTEX_MPU_Region_Initialization_Structure_definition MPU Region Initialization Structure Definition
  * @brief  MPU Region initialization structure
  * @{
  */
typedef struct
{
  uint8_t                Enable;                /*!< Specifies the status of the region.
                                                     This parameter can be a value of @ref CORTEX_MPU_Region_Enable                 */
  uint8_t                Number;                /*!< Specifies the number of the region to protect.
                                                     This parameter can be a value of @ref CORTEX_MPU_Region_Number                 */
  uint32_t               BaseAddress;           /*!< Specifies the base address of the region to protect.                           */

  uint8_t                Size;                  /*!< Specifies the size of the region to protect.
                                                     This parameter can be a value of @ref CORTEX_MPU_Region_Size                   */
  uint8_t                SubRegionDisable;      /*!< Specifies the number of the subregion protection to disable.
                                                     This parameter must be a number between Min_Data = 0x00 and Max_Data = 0xFF    */
  uint8_t                TypeExtField;          /*!< Specifies the TEX field level.
                                                     This parameter can be a value of @ref CORTEX_MPU_TEX_Levels                    */
  uint8_t                AccessPermission;      /*!< Specifies the region access permission type.
                                                     This parameter can be a value of @ref CORTEX_MPU_Region_Permission_Attributes  */
  uint8_t                DisableExec;           /*!< Specifies the instruction access status.
                                                     This parameter can be a value of @ref CORTEX_MPU_Instruction_Access            */
  uint8_t                IsShareable;           /*!< Specifies the shareability status of the protected region.
                                                     This parameter can be a value of @ref CORTEX_MPU_Access_Shareable              */
  uint8_t                IsCacheable;           /*!< Specifies the cacheable status of the region protected.
                                                     This parameter can be a value of @ref CORTEX_MPU_Access_Cacheable              */
  uint8_t                IsBufferable;          /*!< Specifies the bufferable status of the protected region.
                                                     This parameter can be a value of @ref CORTEX_MPU_Access_Bufferable             */
}MPU_Region_InitTypeDef;

#define  MPU_HFNMI_PRIVDEF_NONE      ((uint32_t)0x00000000)
#define  MPU_HARDFAULT_NMI           ((uint32_t)0x00000002)
#define  MPU_PRIVILEGED_DEFAULT      ((uint32_t)0x00000004)
#define  MPU_HFNMI_PRIVDEF           ((uint32_t)0x00000006)
/**
  * @}
  */

/** @defgroup CORTEX_MPU_Region_Enable CORTEX MPU Region Enable
  * @{
  */
#define  MPU_REGION_ENABLE     ((uint8_t)0x01)
#define  MPU_REGION_DISABLE    ((uint8_t)0x00)
/**
  * @}
  */

/** @defgroup CORTEX_MPU_Instruction_Access CORTEX MPU Instruction Access
  * @{
  */
#define  MPU_INSTRUCTION_ACCESS_ENABLE      ((uint8_t)0x00)
#define  MPU_INSTRUCTION_ACCESS_DISABLE     ((uint8_t)0x01)
/**
  * @}
  */

/** @defgroup CORTEX_MPU_Access_Shareable CORTEX MPU Instruction Access Shareable
  * @{
  */
#define  MPU_ACCESS_SHAREABLE        ((uint8_t)0x01)
#define  MPU_ACCESS_NOT_SHAREABLE    ((uint8_t)0x00)
/**
  * @}
  */

/** @defgroup CORTEX_MPU_Access_Cacheable CORTEX MPU Instruction Access Cacheable
  * @{
  */
#define  MPU_ACCESS_CACHEABLE         ((uint8_t)0x01)
#define  MPU_ACCESS_NOT_CACHEABLE     ((uint8_t)0x00)
/**
  * @}
  */

/** @defgroup CORTEX_MPU_Access_Bufferable CORTEX MPU Instruction Access Bufferable
  * @{
  */
#define  MPU_ACCESS_BUFFERABLE         ((uint8_t)0x01)
#define  MPU_ACCESS_NOT_BUFFERABLE     ((uint8_t)0x00)
/**
  * @}
  */

/** @defgroup CORTEX_MPU_TEX_Levels MPU TEX Levels
  * @{
  */
#define  MPU_TEX_LEVEL0    ((uint8_t)0x00)
#define  MPU_TEX_LEVEL1    ((uint8_t)0x01)
#define  MPU_TEX_LEVEL2    ((uint8_t)0x02)
/**
  * @}
  */

/** @defgroup CORTEX_MPU_Region_Size CORTEX MPU Region Size
  * @{
  */
#define   MPU_REGION_SIZE_32B      ((uint8_t)0x04)
#define   MPU_REGION_SIZE_64B      ((uint8_t)0x05)
#define   MPU_REGION_SIZE_128B     ((uint8_t)0x06)
#define   MPU_REGION_SIZE_256B     ((uint8_t)0x07)
#define   MPU_REGION_SIZE_512B     ((uint8_t)0x08)
#define   MPU_REGION_SIZE_1KB      ((uint8_t)0x09)
#define   MPU_REGION_SIZE_2KB      ((uint8_t)0x0A)
#define   MPU_REGION_SIZE_4KB      ((uint8_t)0x0B)
#define   MPU_REGION_SIZE_8KB      ((uint8_t)0x0C)
#define   MPU_REGION_SIZE_16KB     ((uint8_t)0x0D)
#define   MPU_REGION_SIZE_32KB     ((uint8_t)0x0E)
#define   MPU_REGION_SIZE_64KB     ((uint8_t)0x0F)
#define   MPU_REGION_SIZE_128KB    ((uint8_t)0x10)
#define   MPU_REGION_SIZE_256KB    ((uint8_t)0x11)
#define   MPU_REGION_SIZE_512KB    ((uint8_t)0x12)
#define   MPU_REGION_SIZE_1MB      ((uint8_t)0x13)
#define   MPU_REGION_SIZE_2MB      ((uint8_t)0x14)
#define   MPU_REGION_SIZE_4MB      ((uint8_t)0x15)
#define   MPU_REGION_SIZE_8MB      ((uint8_t)0x16)
#define   MPU_REGION_SIZE_16MB     ((uint8_t)0x17)
#define   MPU_REGION_SIZE_32MB     ((uint8_t)0x18)
#define   MPU_REGION_SIZE_64MB     ((uint8_t)0x19)
#define   MPU_REGION_SIZE_128MB    ((uint8_t)0x1A)
#define   MPU_REGION_SIZE_256MB    ((uint8_t)0x1B)
#define   MPU_REGION_SIZE_512MB    ((uint8_t)0x1C)
#define   MPU_REGION_SIZE_1GB      ((uint8_t)0x1D)
#define   MPU_REGION_SIZE_2GB      ((uint8_t)0x1E)
#define   MPU_REGION_SIZE_4GB      ((uint8_t)0x1F)
/**
  * @}
  */

/** @defgroup CORTEX_MPU_Region_Permission_Attributes CORTEX MPU Region Permission Attributes
  * @{
  */
#define  MPU_REGION_NO_ACCESS      ((uint8_t)0x00)
#define  MPU_REGION_PRIV_RW        ((uint8_t)0x01)
#define  MPU_REGION_PRIV_RW_URO    ((uint8_t)0x02)
#define  MPU_REGION_FULL_ACCESS    ((uint8_t)0x03)
#define  MPU_REGION_PRIV_RO        ((uint8_t)0x05)
#define  MPU_REGION_PRIV_RO_URO    ((uint8_t)0x06)
/**
  * @}
  */

/** @defgroup CORTEX_MPU_Region_Number CORTEX MPU Region Number
  * @{
  */
#define  MPU_REGION_NUMBER0    ((uint8_t)0x00)
#define  MPU_REGION_NUMBER1    ((uint8_t)0x01)
#define  MPU_REGION_NUMBER2    ((uint8_t)0x02)
#define  MPU_REGION_NUMBER3    ((uint8_t)0x03)
#define  MPU_REGION_NUMBER4    ((uint8_t)0x04)
#define  MPU_REGION_NUMBER5    ((uint8_t)0x05)
#define  MPU_REGION_NUMBER6    ((uint8_t)0x06)
#define  MPU_REGION_NUMBER7    ((uint8_t)0x07)
#if !defined(CORE_CM4)
#define  MPU_REGION_NUMBER8    ((uint8_t)0x08)
#define  MPU_REGION_NUMBER9    ((uint8_t)0x09)
#define  MPU_REGION_NUMBER10   ((uint8_t)0x0A)
#define  MPU_REGION_NUMBER11   ((uint8_t)0x0B)
#define  MPU_REGION_NUMBER12   ((uint8_t)0x0C)
#define  MPU_REGION_NUMBER13   ((uint8_t)0x0D)
#define  MPU_REGION_NUMBER14   ((uint8_t)0x0E)
#define  MPU_REGION_NUMBER15   ((uint8_t)0x0F)
#endif /* !defined(CORE_CM4) */

#endif /* __MPU_PRESENT */

#endif
