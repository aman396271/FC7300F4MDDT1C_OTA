#ifndef _MODULE_SMC_gmbhdijq208_REGS_H_SMC_H_
#define _MODULE_SMC_gmbhdijq208_REGS_H_SMC_H_

/* ----------------------------------------------------------------------------
   -- SMC Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SMC_Peripheral_Access_Layer SMC Peripheral Access Layer
 * @{
 */

/** SMC - Size of Registers Arrays */

/** SMC - Register Layout Typedef */

typedef struct {

       uint8_t  RESERVED_0[12];
  __IO uint32_t PMCTRL                        ; /* Power Mode Control Register, offset: 0xc */
  __IO uint32_t STANDBY_CFG                   ; /* Standby Mode Configuration Register, offset: 0x10 */

} SMC_Type, *SMC_MemMapPtr;


/* SMC - Peripheral instance base addresses */
/** Peripheral SMC base address */
#define SMC_BASE                                 (0x40045000u)
/** Peripheral SMC base pointer */
#define SMC                                      ((SMC_Type *)SMC_BASE)
// need fill by yourself
///** Number of interrupt vector arrays for the SMC module. */
//#define SMC_IRQS_ARR_COUNT                       (1u)
///** Number of interrupt channels for the SMC module. */
//#define SMC_IRQS_CH_COUNT                        (1u)
///** Interrupt vectors for the SMC peripheral type */
//#define SMC_IRQS                                 {SMC_IRQn}


/* ----------------------------------------------------------------------------
   -- SMC Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SMC_Register_Masks SMC Register Masks
 * @{
 */

/* PMCTRL Bit Fields */
#define SMC_PMCTRL_STOP_MODE_MASK      0x7u
#define SMC_PMCTRL_STOP_MODE_SHIFT     0u
#define SMC_PMCTRL_STOP_MODE_WIDTH     3u
#define SMC_PMCTRL_STOP_MODE(x)        (((uint32_t)(((uint32_t)(x))<<SMC_PMCTRL_STOP_MODE_SHIFT))&SMC_PMCTRL_STOP_MODE_MASK)
/* PMCTRL Reg Mask */
#define SMC_PMCTRL_MASK                0x00000007u

/* STANDBY_CFG Bit Fields */
#define SMC_STANDBY_CFG_OPTION_MASK    0x3u
#define SMC_STANDBY_CFG_OPTION_SHIFT   0u
#define SMC_STANDBY_CFG_OPTION_WIDTH   2u
#define SMC_STANDBY_CFG_OPTION(x)      (((uint32_t)(((uint32_t)(x))<<SMC_STANDBY_CFG_OPTION_SHIFT))&SMC_STANDBY_CFG_OPTION_MASK)
/* STANDBY_CFG Reg Mask */
#define SMC_STANDBY_CFG_MASK           0x00000003u


/*!
 * @}
 */ /* end of group SMC_Register_Masks */

/*!
 * @}
 */ /* end of group SMC_Peripheral_Access_Layer */

#endif
