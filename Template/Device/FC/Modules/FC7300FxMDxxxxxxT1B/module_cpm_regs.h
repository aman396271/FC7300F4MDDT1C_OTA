#ifndef _MODULE_CPM_gmbhdijq277_REGS_H_CPM_H_
#define _MODULE_CPM_gmbhdijq277_REGS_H_CPM_H_

/* ----------------------------------------------------------------------------
   -- CPM Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup CPM_Peripheral_Access_Layer CPM Peripheral Access Layer
 * @{
 */

/** CPM - Size of Registers Arrays */

/** CPM - Register Layout Typedef */

typedef struct {

  __IO uint32_t FISCR                         ; /* FPU Interrupt Status and Control Register, offset: 0x0 */
  __IO uint32_t MISCR                         ; /* Miscellaneous Control Register, offset: 0x4 */
  uint8_t  RESERVED_0[24];
  __IO uint32_t TCMRCR                        ; /* TCM Retry Control Register, offset: 0x20 */

} CPM_Type, *CPM_MemMapPtr;


/* CPM - Peripheral instance base addresses */
/** Peripheral CPM base address */
#define CPM_BASE                                 (0xE0080000u)
/** Peripheral CPM base pointer */
#define CPM                                      ((CPM_Type *)CPM_BASE)
// need fill by yourself
///** Number of interrupt vector arrays for the CPM module. */
//#define CPM_IRQS_ARR_COUNT                       (1u)
///** Number of interrupt channels for the CPM module. */
//#define CPM_IRQS_CH_COUNT                        (1u)
///** Interrupt vectors for the CPM peripheral type */
//#define CPM_IRQS                                 {CPM0_IRQn}


/* ----------------------------------------------------------------------------
   -- CPM Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup CPM_Register_Masks CPM Register Masks
 * @{
 */

/* FISCR Bit Fields */
#define CPM_FISCR_FIXCE_MASK           0x200000u
#define CPM_FISCR_FIXCE_SHIFT          21u
#define CPM_FISCR_FIXCE_WIDTH          1u
#define CPM_FISCR_FIXCE(x)             (((uint32_t)(((uint32_t)(x))<<CPM_FISCR_FIXCE_SHIFT))&CPM_FISCR_FIXCE_MASK)
#define CPM_FISCR_FIDCE_MASK           0x100000u
#define CPM_FISCR_FIDCE_SHIFT          20u
#define CPM_FISCR_FIDCE_WIDTH          1u
#define CPM_FISCR_FIDCE(x)             (((uint32_t)(((uint32_t)(x))<<CPM_FISCR_FIDCE_SHIFT))&CPM_FISCR_FIDCE_MASK)
#define CPM_FISCR_FOFCE_MASK           0x80000u
#define CPM_FISCR_FOFCE_SHIFT          19u
#define CPM_FISCR_FOFCE_WIDTH          1u
#define CPM_FISCR_FOFCE(x)             (((uint32_t)(((uint32_t)(x))<<CPM_FISCR_FOFCE_SHIFT))&CPM_FISCR_FOFCE_MASK)
#define CPM_FISCR_FUFCE_MASK           0x40000u
#define CPM_FISCR_FUFCE_SHIFT          18u
#define CPM_FISCR_FUFCE_WIDTH          1u
#define CPM_FISCR_FUFCE(x)             (((uint32_t)(((uint32_t)(x))<<CPM_FISCR_FUFCE_SHIFT))&CPM_FISCR_FUFCE_MASK)
#define CPM_FISCR_FDZCE_MASK           0x20000u
#define CPM_FISCR_FDZCE_SHIFT          17u
#define CPM_FISCR_FDZCE_WIDTH          1u
#define CPM_FISCR_FDZCE(x)             (((uint32_t)(((uint32_t)(x))<<CPM_FISCR_FDZCE_SHIFT))&CPM_FISCR_FDZCE_MASK)
#define CPM_FISCR_FIOCE_MASK           0x10000u
#define CPM_FISCR_FIOCE_SHIFT          16u
#define CPM_FISCR_FIOCE_WIDTH          1u
#define CPM_FISCR_FIOCE(x)             (((uint32_t)(((uint32_t)(x))<<CPM_FISCR_FIOCE_SHIFT))&CPM_FISCR_FIOCE_MASK)
#define CPM_FISCR_FIXC_MASK            0x20u
#define CPM_FISCR_FIXC_SHIFT           5u
#define CPM_FISCR_FIXC_WIDTH           1u
#define CPM_FISCR_FIXC(x)              (((uint32_t)(((uint32_t)(x))<<CPM_FISCR_FIXC_SHIFT))&CPM_FISCR_FIXC_MASK)
#define CPM_FISCR_FIDC_MASK            0x10u
#define CPM_FISCR_FIDC_SHIFT           4u
#define CPM_FISCR_FIDC_WIDTH           1u
#define CPM_FISCR_FIDC(x)              (((uint32_t)(((uint32_t)(x))<<CPM_FISCR_FIDC_SHIFT))&CPM_FISCR_FIDC_MASK)
#define CPM_FISCR_FOFC_MASK            0x8u
#define CPM_FISCR_FOFC_SHIFT           3u
#define CPM_FISCR_FOFC_WIDTH           1u
#define CPM_FISCR_FOFC(x)              (((uint32_t)(((uint32_t)(x))<<CPM_FISCR_FOFC_SHIFT))&CPM_FISCR_FOFC_MASK)
#define CPM_FISCR_FUFC_MASK            0x4u
#define CPM_FISCR_FUFC_SHIFT           2u
#define CPM_FISCR_FUFC_WIDTH           1u
#define CPM_FISCR_FUFC(x)              (((uint32_t)(((uint32_t)(x))<<CPM_FISCR_FUFC_SHIFT))&CPM_FISCR_FUFC_MASK)
#define CPM_FISCR_FDZC_MASK            0x2u
#define CPM_FISCR_FDZC_SHIFT           1u
#define CPM_FISCR_FDZC_WIDTH           1u
#define CPM_FISCR_FDZC(x)              (((uint32_t)(((uint32_t)(x))<<CPM_FISCR_FDZC_SHIFT))&CPM_FISCR_FDZC_MASK)
#define CPM_FISCR_FIOC_MASK            0x1u
#define CPM_FISCR_FIOC_SHIFT           0u
#define CPM_FISCR_FIOC_WIDTH           1u
#define CPM_FISCR_FIOC(x)              (((uint32_t)(((uint32_t)(x))<<CPM_FISCR_FIOC_SHIFT))&CPM_FISCR_FIOC_MASK)
/* FISCR Reg Mask */
#define CPM_FISCR_MASK                 0x003F003Fu

/* MISCR Bit Fields */
#define CPM_MISCR_CPU_ID_MASK          0xE0000u
#define CPM_MISCR_CPU_ID_SHIFT         17u
#define CPM_MISCR_CPU_ID_WIDTH         3u
#define CPM_MISCR_CPU_ID(x)            (((uint32_t)(((uint32_t)(x))<<CPM_MISCR_CPU_ID_SHIFT))&CPM_MISCR_CPU_ID_MASK)
#define CPM_MISCR_AHBS_PRIORITY_MASK   0x1u
#define CPM_MISCR_AHBS_PRIORITY_SHIFT  0u
#define CPM_MISCR_AHBS_PRIORITY_WIDTH  1u
#define CPM_MISCR_AHBS_PRIORITY(x)     (((uint32_t)(((uint32_t)(x))<<CPM_MISCR_AHBS_PRIORITY_SHIFT))&CPM_MISCR_AHBS_PRIORITY_MASK)
/* MISCR Reg Mask */
#define CPM_MISCR_MASK                 0x000E0001u


/*!
 * @}
 */ /* end of group CPM_Register_Masks */

/*!
 * @}
 */ /* end of group CPM_Peripheral_Access_Layer */

#endif
