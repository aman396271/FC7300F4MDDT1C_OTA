#ifndef _DEVICE_FEATURES_FC7300F4MDSxxxxxT1B_CORE_COMMON_H_
#define _DEVICE_FEATURES_FC7300F4MDSxxxxxT1B_CORE_COMMON_H_

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
    NotAvail_IRQn                      = -128,       /**< Not available device specific interrupt */

    /* Core interrupts */
    NonMaskableInt_IRQn                = -14,   /**< Non Maskable Interrupt */
    HardFault_IRQn                     = -13,   /**< Cortex-M4 SV Hard Fault Interrupt */
    MemoryManagement_IRQn              = -12,   /**< Cortex-M4 Memory Management Interrupt */
    BusFault_IRQn                      = -11,   /**< Cortex-M4 Bus Fault Interrupt */
    UsageFault_IRQn                    = -10,   /**< Cortex-M4 Usage Fault Interrupt */
    SVCall_IRQn                        = -5,    /**< Cortex-M4 SV Call Interrupt */
    DebugMonitor_IRQn                  = -4,    /**< Cortex-M4 Debug Monitor Interrupt */
    PendSV_IRQn                        = -2,    /**< Cortex-M4 Pend SV Interrupt */
    SysTick_IRQn                       = -1,    /**< Cortex-M4 System Tick Interrupt */

    /* FC7xxx Device specific interrupts */
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
    DMA16_IRQn                         = 16U,    /**<  DMA channel 16 transfer complete */
    DMA17_IRQn                         = 17U,    /**<  DMA channel 17 transfer complete */
    DMA18_IRQn                         = 18U,    /**<  DMA channel 18 transfer complete */
    DMA19_IRQn                         = 19U,    /**<  DMA channel 19 transfer complete */
    DMA20_IRQn                         = 20U,    /**<  DMA channel 20 transfer complete */
    DMA21_IRQn                         = 21U,    /**<  DMA channel 21 transfer complete */
    DMA22_IRQn                         = 22U,    /**<  DMA channel 22 transfer complete */
    DMA23_IRQn                         = 23U,    /**<  DMA channel 23 transfer complete */
    DMA24_IRQn                         = 24U,    /**<  DMA channel 24 transfer complete */
    DMA25_IRQn                         = 25U,    /**<  DMA channel 25 transfer complete */
    DMA26_IRQn                         = 26U,    /**<  DMA channel 26 transfer complete */
    DMA27_IRQn                         = 27U,    /**<  DMA channel 27 transfer complete */
    DMA28_IRQn                         = 28U,    /**<  DMA channel 28 transfer complete */
    DMA29_IRQn                         = 29U,    /**<  DMA channel 29 transfer complete */
    DMA30_IRQn                         = 30U,    /**<  DMA channel 30 transfer complete */
    DMA31_IRQn                         = 31U,    /**<  DMA channel 31 transfer complete */
    DMA0_Error_IRQn                     = 32U,    /**<  DMA error interrupt channels 0-63 */
    CPM0_IRQn                           = 33U,    /**<  FPU etc. interrupt */
    FC0_IRQn                            = 34U,    /**<  FC Command complete */
    PMC0_IRQn                       = 35U,    /**<  PMC Low voltage detect interrupt */
    TMU0_IRQn                           = 36U,    /**<  Temperature Monitor Unit interrupt */
    WDOG0_IRQn                         = 37U,    /**<  interrupt request out before wdg reset out */
    WDOG1_IRQn                         = 38U,    /**<  interrupt request out before wdg reset out */
    WDOG2_IRQn                         = 39U,    /**<  interrupt request out before wdg reset out */
    FCSMU0_IRQn                        = 40U,    /**<  Fault Control and Safety Manage Unit */
    STCU0_IRQn                         = 41U,    /**<  Safety Control Unit interrupt */
    ERM0_fault_IRQn                     = 42U,    /**<  ERM single/double bit error correction */
    MAM0_IRQn                          = 43U,    /**<  Matrix Access Monitor interrupt */
    MAM1_IRQn                          = 44U,    /**<  Matrix Access Monitor interrupt */
    MAM2_IRQn                          = 45U,    /**<  Matrix Access Monitor interrupt */
    RESERVED_62_IRQn                   = 46U,    /**<  Reserved */
    RGM0_Pre_IRQn                       = 47U,    /**<  RGM pre-reset Interrupt */
    RGM0_Exit_IRQn                     = 48U,    /**<  RGM other CPU exit reset Interrupt */
    INTM0_IRQn                         = 49U,    /**<   INTM alarm interrupt */
    ISM0_IRQn                          = 50U,    /**<  ISM0 interrupt */
    MB0_IRQn                            = 51U,    /**<  Mail Box interrupt */
    SCG0_IRQn                           = 52U,    /**<  SCG bus interrupt request */
    CMU0_IRQn                          = 53U,    /**<  CMU0 interrupt */
    CMU1_IRQn                          = 54U,    /**<  CMU1 interrupt */
    CMU2_IRQn                          = 55U,    /**<  CMU2 interrupt */
    CMU3_IRQn                          = 56U,    /**<  CMU3 interrupt */
    TSTMP0_IRQn                        = 57U,    /**<  TimerStamp0 interrupt */
    TSTMP1_IRQn                        = 58U,    /**<  TimerStamp1 interrupt */
    TSTMP2_IRQn                        = 59U,    /**<  TimerStamp2 interrupt */
    TSTMP3_IRQn                        = 60U,    /**<  TimerStamp3 interrupt */
    CORDIC0_IRQn                        = 61U,    /**<  CORDIC Accelerator interrupt */
    HSM0_IRQn                          = 62U,    /**<  Crypto interrupt */
    FCPIT0_IRQn                        = 63U,    /**<  FCPIT0 interrupt */
    FCPIT1_IRQn                        = 64U,    /**<  FCPIT0 interrupt */
    RTC0_IRQn                           = 65U,    /**<  RTC alarm or seconds interrupt  */
    ENET_Tx0_IRQn                      = 66U,    /**<  ENET 1588 Timer Interrupt - synchronous */
    ENET_Tx1_IRQn                      = 67U,    /**<  ENET Data transfer done */
    ENET_Rx0_IRQn                      = 68U,    /**<  ENET Receive Buffer Done for Ring/Queue 0 */
    ENET_Rx1_IRQn                      = 69U,    /**<  ENET Receive Buffer Done for Ring/Queue 0 */
    ENET_System_IRQn                   = 70U,    /**<  ENET System interrupt */
    AONTIMER0_IRQn                      = 71U,    /**<  AONTIMER interrupt request */
    SWI_IRQn                           = 72U,    /**<  Software interrupt */
    OSPI0_IRQn                          = 73U,    /**<  All OSPI interrupts */
    FREQM0_IRQn                         = 74U,    /**<  FREQM interrupt */
    PORTA_IRQn                         = 75U,    /**<  Port A pin detect interrupt */
    PORTB_IRQn                         = 76U,    /**<  Port B pin detect interrupt */
    PORTC_IRQn                         = 77U,    /**<  Port C pin detect interrupt */
    PORTD_IRQn                         = 78U,    /**<  Port D pin detect interrupt */
    PORTE_IRQn                         = 79U,    /**<  Port E pin detect interrupt */
    PORTF_IRQn                         = 80U,    /**<  Port F pin detect interrupt */
    PORTG_IRQn                         = 81U,    /**<  Port G pin detect interrupt */
    PORTH_IRQn                         = 82U,    /**<  Port H pin detect interrupt */
    PORTI_IRQn                         = 83U,    /**<  Port I pin detect interrupt */
    FlexCAN0_IRQn                      = 84U,    /**<  CAN0 Interrupt */
    FlexCAN1_IRQn                      = 85U,    /**<  CAN1 Interrupt */
    FlexCAN2_IRQn                      = 86U,    /**<  CAN2 Interrupt */
    FlexCAN3_IRQn                      = 87U,    /**<  CAN3 Interrupt */
    FlexCAN4_IRQn                      = 88U,    /**<  CAN4 Interrupt */
    FlexCAN5_IRQn                      = 89U,    /**<  CAN5 Interrupt */
    FlexCAN6_IRQn                      = 90U,    /**<  CAN6 Interrupt */
    FlexCAN7_IRQn                      = 91U,    /**<  CAN7 Interrupt */
    FCIIC0_IRQn                        = 92U,    /**<  FCIIC0 Interrupt */
    FCIIC1_IRQn                        = 93U,    /**<  FCIIC1 Interrupt */
    FCSPI0_IRQn                        = 94U,    /**<  FCSPI0 Interrupt */
    FCSPI1_IRQn                        = 95U,    /**<  FCSPI1 Interrupt */
    FCSPI2_IRQn                        = 96U,    /**<  FCSPI2 Interrupt */
    FCSPI3_IRQn                        = 97U,    /**<  FCSPI0 Interrupt */
    FCSPI4_IRQn                        = 98U,    /**<  FCSPI1 Interrupt */
    FCSPI5_IRQn                        = 99U,    /**<  FCSPI2 Interrupt */
    FCUART0_IRQn                       = 100,    /**<  FCUART0 Transmit / Receive Interrupt */
    FCUART1_IRQn                       = 101U,   /**<  FCUART1 Transmit / Receive  Interrupt */
    FCUART2_IRQn                       = 102U,   /**<  FCUART2 Transmit / Receive  Interrupt */
    FCUART3_IRQn                       = 103U,   /**<  FCUART3 Transmit / Receive Interrupt */
    FCUART4_IRQn                       = 104U,   /**<  FCUART4 Transmit / Receive  Interrupt */
    FCUART5_IRQn                       = 105U,   /**<  FCUART5 Transmit / Receive  Interrupt */
    FCUART6_IRQn                       = 106U,   /**<  FCUART6 Transmit / Receive Interrupt */
    FCUART7_IRQn                       = 107U,   /**<  FCUART7 Transmit / Receive  Interrupt */
    FCUART8_IRQn                       = 108U,   /**<  FCUART8 Transmit / Receive  Interrupt */
    FCUART9_IRQn                       = 109U,   /**<  FCUART9 Transmit / Receive Interrupt */
    FCUART10_IRQn                      = 110U,   /**<  FCUART10 Transmit / Receive  Interrupt */
    FCUART11_IRQn                      = 111U,   /**<  FCUART11 Transmit / Receive  Interrupt */
    FCUART12_IRQn                      = 112U,   /**<  FCUART12 Transmit / Receive  Interrupt */
    FCUART13_IRQn                      = 113U,   /**<  FCUART13 Transmit / Receive  Interrupt */
    FCUART14_IRQn                      = 114U,   /**<  FCUART14 Transmit / Receive Interrupt */
    FCUART15_IRQn                      = 115U,   /**<  FCUART15 Transmit / Receive  Interrupt */
    FTU0_IRQn                          = 116U,   /**<  FTU0 all source interrupt */
    FTU1_IRQn                          = 117U,   /**<  FTU1 all source interrupt */
    FTU2_IRQn                          = 118U,   /**<  FTU2 all source interrupt */
    FTU3_IRQn                          = 119U,   /**<  FTU3 all source interrupt */
    FTU4_IRQn                          = 120U,   /**<  FTU4 all source interrupt */
    FTU5_IRQn                          = 121U,   /**<  FTU5 all source interrupt */
    FTU6_IRQn                          = 122U,   /**<  FTU6 all source interrupt */
    FTU7_IRQn                          = 123U,   /**<  FTU7 all source interrupt */
    FTU8_IRQn                          = 124U,   /**<  FTU4 all source interrupt */
    FTU9_IRQn                          = 125U,   /**<  FTU5 all source interrupt */
    FTU10_IRQn                         = 126U,   /**<  FTU6 all source interrupt */
    FTU11_IRQn                         = 127U,   /**<  FTU7 all source interrupt */
    CMP0_IRQn                          = 128U,   /**<  CMP0 interrupt request  */
    CMP1_IRQn                          = 129U,   /**<  CMP1 interrupt request  */
    CMP2_IRQn                          = 130U,   /**<  CMP2 interrupt request  */
    ADC0_IRQn                          = 131U,   /**<  ADC0 interrupt request. */
    ADC1_IRQn                          = 132U,   /**<  ADC1 interrupt request. */
    ADC2_IRQn                          = 133U,   /**<  ADC2 interrupt request. */
    ADC3_IRQn                          = 134U,   /**<  ADC3 interrupt request. */
    PTIMER0_IRQn                       = 135U,   /**<  PTIMER0 interrupt */
    PTIMER1_IRQn                       = 136U,   /**<  PTIMER1 interrupt */
    PTIMER2_IRQn                       = 137U,   /**<  PTIMER2 interrupt */
    PTIMER3_IRQn                       = 138U,   /**<  PTIMER3 interrupt */
    SDDF0_IRQn                         = 139U,   /**<  SD Digital Filter interrupt request */
    MSC0_IRQn                          = 140U,   /**<  MSC interrupt */
    MSC1_IRQn                          = 141U,   /**<  MSC interrupt */
    FlexCAN8_IRQn                      = 142U,   /**<  CAN6 Interrupt */
    FlexCAN9_IRQn                      = 143U,   /**<  CAN7 Interrupt */
    SENT0_IRQn                         = 144U,   /**<  SENT all interrupt (fast or slow) */
    SENT1_IRQn                         = 145U,   /**<  SENT all interrupt (fast or slow) */
    FCSPI6_IRQn                        = 146U,   /**<  FCSPI6 Interrupt */
    FCSPI7_IRQn                        = 147U,   /**<  FCSPI7 Interrupt */
    FCUART16_IRQn                 = 148U,   /**<  FCUART16 Transmit / Receive Interrupt */
    FCUART17_IRQn                 = 149U,   /**<  FCUART17 Transmit / Receive  Interrupt */
    CTI0_IRQn                          = 150U,   /**<  CTI Interrupt */
    CTI1_IRQn                          = 151U,   /**<  CTI Interrupt */
    CTI2_IRQn                          = 152U,   /**<  CTI Interrupt */
    CMU4_IRQn                          = 153U,   /**<  CMU4 Interrupt */
    IRQn_MAX                           = 154U
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
