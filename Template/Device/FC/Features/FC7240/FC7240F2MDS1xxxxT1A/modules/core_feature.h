#ifndef _DEVICE_FEATURES_FC7240F2MDS1_CORE_COMMON_H_
#define _DEVICE_FEATURES_FC7240F2MDS1_CORE_COMMON_H_

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
    DMA0_Error_IRQn                     = 16U,    /**< DMA error interrupt channels 0-63 */
    CPM0_IRQn                           = 17U,    /**< FPU etc. interrupt */
    FC0_IRQn                            = 18U,    /**< Flash Controller Command complete, time out etc. interrupt  */
    PMC0_IRQn                          = 19U,    /**< HVD/LVD etc. interrupt */
    TMU0_IRQn                           = 20U,    /**< Temperature Monitor Unit interrupt */
    WDOG0_IRQn                         = 21U,    /**< Interrupt request out before wdg0 reset out */
    WDOG1_IRQn                         = 22U,    /**< Interrupt request out before wdg1 reset out */
    FCSMU0_IRQn                        = 23U,    /**< Fault Control and Safety Manage Unit */
    STCU0_IRQn                         = 24U,    /**< Safety Control Unit interrupt */
    ERM0_fault_IRQn                     = 25U,    /**< ERM single- or double-bit error interrupt */
    MAM0_IRQn                          = 26U,    /**< Matrix Access Monitor interrupt */
    RGM0_Pre_IRQn                       = 27U,    /**< RGM pre-reset Interrupt */
    INTM0_IRQn                         = 28U,    /**< INTM0 timeout interrupt */
    ISM0_IRQn                          = 29U,    /**< ISM0 interrupt */
    MB0_IRQn                            = 30U,    /**< Mail Box interrupt */
    SCG0_IRQn                           = 31U,    /**< SCG bus interrupt request  */
    CMU0_IRQn                          = 32U,    /**< CMU0 interrupt */
    CMU1_IRQn                          = 33U,    /**< CMU1 interrupt */
    CMU2_IRQn                          = 34U,    /**< CMU2 interrupt */
    CMU3_IRQn                          = 35U,    /**< CMU3 interrupt */
    CMU4_IRQn                          = 36U,    /**< CMU4 interrupt */
    TSTMP0_IRQn                        = 37U,    /**< TimerStamp0 interrupt */
    TSTMP1_IRQn                        = 38U,    /**< TimerStamp1 interrupt */
    CORDIC0_IRQn                        = 39U,    /**< CORDIC Accelerator interrupt */
    HSM0_ERR_IRQn                          = 40U,    /**< HSM error interrupt */
    FCPIT0_IRQn                        = 41U,    /**< FCPIT interrupt */
    RTC0_IRQn                           = 42U,    /**< RTC alarm or seconds interrupt */
    AONTIMER0_IRQn                      = 43U,    /**< AONTIMER interrupt request */
    SWI_IRQn                           = 44U,    /**< Software interrupt  */
    FREQM0_IRQn                         = 45U,    /**< FREQM interrupt */
    ADC0_IRQn                          = 46U,    /**< ADC0 interrupt request */
    ADC1_IRQn                          = 47U,    /**< ADC1 interrupt request */
    PTIMER0_IRQn                       = 48U,    /**< PTIMER0 interrupt */
    PTIMER1_IRQn                       = 49U,    /**< PTIMER1 interrupt */
    FlexCAN0_IRQn                      = 50U,    /**< FLEXCAN0 interrupt */
    FlexCAN1_IRQn                      = 51U,    /**< FLEXCAN1 interrupt */
    FlexCAN2_IRQn                      = 52U,    /**< FLEXCAN2 interrupt */
    FlexCAN3_IRQn                      = 53U,    /**< FLEXCAN3 interrupt */
    FCIIC0_IRQn                        = 54U,    /**< FCIIC0 Interrupt */
    FCIIC1_IRQn                        = 55U,    /**< FCIIC1 Interrupt */
    FCSPI0_IRQn                        = 56U,    /**< FCSPI0 Interrupt */
    FCSPI1_IRQn                        = 57U,    /**< FCSPI1 Interrupt */
    FCSPI2_IRQn                        = 58U,    /**< FCSPI2 Interrupt */
    FCSPI3_IRQn                        = 59U,    /**< FCSPI3 Interrupt */
    FCSPI4_IRQn                        = 60U,    /**< FCSPI4 Interrupt */
    FCSPI5_IRQn                        = 61U,    /**< FCSPI5 Interrupt */
    FCUART0_IRQn                       = 62U,    /**< FCUART0 Interrupt */
    FCUART1_IRQn                       = 63U,    /**< FCUART1 Interrupt */
    FCUART2_IRQn                       = 64U,    /**< FCUART2 Interrupt */
    FCUART3_IRQn                       = 65U,    /**< FCUART3 Interrupt */
    FCUART4_IRQn                       = 66U,    /**< FCUART4 Interrupt */
    FCUART5_IRQn                       = 67U,    /**< FCUART5 Interrupt */
    FCUART6_IRQn                       = 68U,    /**< FCUART6 Interrupt */
    FCUART7_IRQn                       = 69U,    /**< FCUART7 Interrupt */
    FTU0_IRQn                          = 70U,    /**< FTU0 all source interrupt */
    FTU1_IRQn                          = 71U,    /**< FTU1 all source interrupt */
    FTU2_IRQn                          = 72U,    /**< FTU2 all source interrupt */
    FTU3_IRQn                          = 73U,    /**< FTU3 all source interrupt */
    FTU4_IRQn                          = 74U,    /**< FTU4 all source interrupt */
    FTU5_IRQn                          = 75U,    /**< FTU5 all source interrupt */
    FTU6_IRQn                          = 76U,    /**< FTU6 all source interrupt */
    FTU7_IRQn                          = 77U,    /**< FTU7 all source interrupt */
    CMP0_IRQn                          = 78U,    /**< CMP0 all source interrupt */
    CMP1_IRQn                          = 79U,    /**< CMP1 all source interrupt */
    PORTA_IRQn                         = 80U,    /**< Port A pin detect interrupt */
    PORTB_IRQn                         = 81U,    /**< Port B pin detect interrupt */
    PORTC_IRQn                         = 82U,    /**< Port C pin detect interrupt */
    PORTD_IRQn                         = 83U,    /**< Port D pin detect interrupt */
    PORTE_IRQn                         = 84U,    /**< Port E pin detect interrupt */
    MSC0_IRQn                          = 85U,    /**< MSC Interrupt */
    SENT0_IRQn                         = 86U,    /**< SENT all interrupt (fast or slow) */
    TPU0_CH0_7_IRQn                    = 87U,    /**< TPU0 CH0-7 interrupt */
    TPU0_CH8_15_IRQn                   = 88U,    /**< TPU0 CH8-15 interrupt */
    TPU0_CH16_23_IRQn                  = 89U,    /**< TPU0 CH16-23 interrupt */
    TPU0_CH24_31_IRQn                  = 90U,    /**< TPU0 CH24-31 interrupt */
    HSM0_IRQn                          = 91U,    /**< HSM crypto interrupt */
    IRQn_MAX                           = 92U
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
