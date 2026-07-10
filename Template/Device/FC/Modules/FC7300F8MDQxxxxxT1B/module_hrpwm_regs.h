#ifndef _MODULE_HRPWM_gmbhdijq114_REGS_H_HRPWM_H_
#define _MODULE_HRPWM_gmbhdijq114_REGS_H_HRPWM_H_

/* ----------------------------------------------------------------------------
   -- HRPWM Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup HRPWM_Peripheral_Access_Layer HRPWM Peripheral Access Layer
 * @{
 */

/** HRPWM - Size of Registers Arrays */

/** HRPWM - Register Layout Typedef */

typedef struct {

  __IO uint32_t EN_CTRL                       ; /* PWM Channel Enable Register, offset: 0x00 */
  __IO uint32_t BYPASS_CTRL                   ; /* PWM Channel Bypass Control Register, offset: 0x04 */
  __IO uint32_t ANA_CTRL                      ; /* Analog Phase Generation Control Register, offset: 0x08 */
  __IO uint32_t FAULT_BYPASS_CTRL             ; /* Fault Bypass Control Register, offset: 0xC */
  __IO uint32_t LOCK_CTRL                     ; /* Register Write Lock Control Register, offset: 0x10 */
  __IO uint32_t FAULT_SW_CTRL_EN              ; /* Software Release Fault Enable Register, offset: 0x14 */
  __IO uint32_t FAULT_STATUS                  ; /* Channel Fault Status Register, offset: 0x18 */

} HRPWM_Type, *HRPWM_MemMapPtr;


/* HRPWM - Peripheral instance base addresses */
/** Peripheral HRPWM base address */
#define HRPWM_BASE                               (0x40478000u)
/** Peripheral HRPWM base pointer */
#define HRPWM                                    ((HRPWM_Type *)HRPWM_BASE)
// need fill by yourself
///** Number of interrupt vector arrays for the HRPWM module. */
//#define HRPWM_IRQS_ARR_COUNT                       (1u)
///** Number of interrupt channels for the HRPWM module. */
//#define HRPWM_IRQS_CH_COUNT                        (1u)
///** Interrupt vectors for the HRPWM peripheral type */
//#define HRPWM_IRQS                               {HRPWM_IRQn}


/* ----------------------------------------------------------------------------
   -- HRPWM Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup HRPWM_Register_Masks HRPWM Register Masks
 * @{
 */

/* EN_CTRL Bit Fields */
#define HRPWM_EN_CTRL_CHNL_ENABLE_MASK 0xFFu
#define HRPWM_EN_CTRL_CHNL_ENABLE_SHIFT 0u
#define HRPWM_EN_CTRL_CHNL_ENABLE_WIDTH 8u
#define HRPWM_EN_CTRL_CHNL_ENABLE(x)   (((uint32_t)(((uint32_t)(x))<<HRPWM_EN_CTRL_CHNL_ENABLE_SHIFT))&HRPWM_EN_CTRL_CHNL_ENABLE_MASK)
/* EN_CTRL Reg Mask */
#define HRPWM_EN_CTRL_MASK             0x000000FFu

/* BYPASS_CTRL Bit Fields */
#define HRPWM_BYPASS_CTRL_CHNL_BYPASS_MASK 0xFFu
#define HRPWM_BYPASS_CTRL_CHNL_BYPASS_SHIFT 0u
#define HRPWM_BYPASS_CTRL_CHNL_BYPASS_WIDTH 8u
#define HRPWM_BYPASS_CTRL_CHNL_BYPASS(x) (((uint32_t)(((uint32_t)(x))<<HRPWM_BYPASS_CTRL_CHNL_BYPASS_SHIFT))&HRPWM_BYPASS_CTRL_CHNL_BYPASS_MASK)
/* BYPASS_CTRL Reg Mask */
#define HRPWM_BYPASS_CTRL_MASK         0x000000FFu

/* ANA_CTRL Bit Fields */
#define HRPWM_ANA_CTRL_PH_LDOEN_MASK   0x40000000u
#define HRPWM_ANA_CTRL_PH_LDOEN_SHIFT  30u
#define HRPWM_ANA_CTRL_PH_LDOEN_WIDTH  1u
#define HRPWM_ANA_CTRL_PH_LDOEN(x)     (((uint32_t)(((uint32_t)(x))<<HRPWM_ANA_CTRL_PH_LDOEN_SHIFT))&HRPWM_ANA_CTRL_PH_LDOEN_MASK)
#define HRPWM_ANA_CTRL_PH_LDOBYPASSEN_MASK 0x20000000u
#define HRPWM_ANA_CTRL_PH_LDOBYPASSEN_SHIFT 29u
#define HRPWM_ANA_CTRL_PH_LDOBYPASSEN_WIDTH 1u
#define HRPWM_ANA_CTRL_PH_LDOBYPASSEN(x) (((uint32_t)(((uint32_t)(x))<<HRPWM_ANA_CTRL_PH_LDOBYPASSEN_SHIFT))&HRPWM_ANA_CTRL_PH_LDOBYPASSEN_MASK)
#define HRPWM_ANA_CTRL_PH_EN_MASK      0x10000000u
#define HRPWM_ANA_CTRL_PH_EN_SHIFT     28u
#define HRPWM_ANA_CTRL_PH_EN_WIDTH     1u
#define HRPWM_ANA_CTRL_PH_EN(x)        (((uint32_t)(((uint32_t)(x))<<HRPWM_ANA_CTRL_PH_EN_SHIFT))&HRPWM_ANA_CTRL_PH_EN_MASK)
#define HRPWM_ANA_CTRL_ANA_POWER_OK_MASK 0x2u
#define HRPWM_ANA_CTRL_ANA_POWER_OK_SHIFT 1u
#define HRPWM_ANA_CTRL_ANA_POWER_OK_WIDTH 1u
#define HRPWM_ANA_CTRL_ANA_POWER_OK(x) (((uint32_t)(((uint32_t)(x))<<HRPWM_ANA_CTRL_ANA_POWER_OK_SHIFT))&HRPWM_ANA_CTRL_ANA_POWER_OK_MASK)
#define HRPWM_ANA_CTRL_PH_LOCK_MASK    0x1u
#define HRPWM_ANA_CTRL_PH_LOCK_SHIFT   0u
#define HRPWM_ANA_CTRL_PH_LOCK_WIDTH   1u
#define HRPWM_ANA_CTRL_PH_LOCK(x)      (((uint32_t)(((uint32_t)(x))<<HRPWM_ANA_CTRL_PH_LOCK_SHIFT))&HRPWM_ANA_CTRL_PH_LOCK_MASK)
/* ANA_CTRL Reg Mask */
#define HRPWM_ANA_CTRL_MASK            0x70000003u

/* LOCK_CTRL Bit Fields */
#define HRPWM_LOCK_CTRL_UNLOCK_NUMBER_MASK 0xFFFFFFFFu
#define HRPWM_LOCK_CTRL_UNLOCK_NUMBER_SHIFT 0u
#define HRPWM_LOCK_CTRL_UNLOCK_NUMBER_WIDTH 32u
#define HRPWM_LOCK_CTRL_UNLOCK_NUMBER(x) (((uint32_t)(((uint32_t)(x))<<HRPWM_LOCK_CTRL_UNLOCK_NUMBER_SHIFT))&HRPWM_LOCK_CTRL_UNLOCK_NUMBER_MASK)
/* LOCK_CTRL Reg Mask */
#define HRPWM_LOCK_CTRL_MASK           0xFFFFFFFFu

/* FAULT_SW_CTRL_EN Bit Fields */
#define HRPWM_FAULT_SW_CTRL_EN_SW_CTRL_EN_MASK 0xFFu
#define HRPWM_FAULT_SW_CTRL_EN_SW_CTRL_EN_SHIFT 0u
#define HRPWM_FAULT_SW_CTRL_EN_SW_CTRL_EN_WIDTH 8u
#define HRPWM_FAULT_SW_CTRL_EN_SW_CTRL_EN(x) (((uint32_t)(((uint32_t)(x))<<HRPWM_FAULT_SW_CTRL_EN_SW_CTRL_EN_SHIFT))&HRPWM_FAULT_SW_CTRL_EN_SW_CTRL_EN_MASK)
/* FAULT_SW_CTRL_EN Reg Mask */
#define HRPWM_FAULT_SW_CTRL_EN_MASK    0x000000FFu

/* FAULT_STATUS Bit Fields */
#define HRPWM_FAULT_STATUS_CH_FAULT_STATUS_MASK 0xFFu
#define HRPWM_FAULT_STATUS_CH_FAULT_STATUS_SHIFT 0u
#define HRPWM_FAULT_STATUS_CH_FAULT_STATUS_WIDTH 8u
#define HRPWM_FAULT_STATUS_CH_FAULT_STATUS(x) (((uint32_t)(((uint32_t)(x))<<HRPWM_FAULT_STATUS_CH_FAULT_STATUS_SHIFT))&HRPWM_FAULT_STATUS_CH_FAULT_STATUS_MASK)
/* FAULT_STATUS Reg Mask */
#define HRPWM_FAULT_STATUS_MASK        0x000000FFu

/* FAULT_BYPASS_CTRL Bit Fields */
#define HRPWM_FAULT_BYPASS_CTRL_FAULT_BY_EN_MASK 0xFFu
#define HRPWM_FAULT_BYPASS_CTRL_FAULT_BY_EN_SHIFT 0u
#define HRPWM_FAULT_BYPASS_CTRL_FAULT_BY_EN_WIDTH 8u
#define HRPWM_FAULT_BYPASS_CTRL_FAULT_BY_EN(x) (((uint32_t)(((uint32_t)(x))<<HRPWM_FAULT_BYPASS_CTRL_FAULT_BY_EN_SHIFT))&HRPWM_FAULT_BYPASS_CTRL_FAULT_BY_EN_MASK)
/* FAULT_BYPASS_CTRL Reg Mask */
#define HRPWM_FAULT_BYPASS_CTRL_MASK   0x000000FFu


/*!
 * @}
 */ /* end of group HRPWM_Register_Masks */

/*!
 * @}
 */ /* end of group HRPWM_Peripheral_Access_Layer */

#endif
