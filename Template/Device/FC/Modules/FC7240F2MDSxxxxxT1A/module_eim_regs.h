#ifndef _MODULE_EIM_gmbhdijq195_REGS_H_EIM_H_
#define _MODULE_EIM_gmbhdijq195_REGS_H_EIM_H_

/* ----------------------------------------------------------------------------
   -- EIM Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup EIM_Peripheral_Access_Layer EIM Peripheral Access Layer
 * @{
 */

/** EIM - Size of Registers Arrays */

/** EIM - Register Layout Typedef */
#define EIM_CTRL_REG_COUNT 84
#define EIM_BUS_REG_COUNT 4

typedef struct {

  __IO uint32_t CR                            ; /* Configuration Register, offset: 0x0 */
       uint8_t  RESERVED_0[12];
  __IO uint32_t CTRL_REG[EIM_CTRL_REG_COUNT]  ; /* Channel N Control Register, offset: 0x10 */
       uint8_t  RESERVED_1[672];
  __IO uint32_t LOCKSTEP[4u]                  ; /* EIM CPU0 LOCKSTEP Error Injection Register, offset: 0x400 */
                                                /* EIM CPU1 LOCKSTEP Error Injection Register, offset: 0x404 */
                                                /* EIM DMA0 LOCKSTEP Error Injection Register, offset: 0x408 */
                                                /* EIM CPU2 LOCKSTEP Error Injection Register, offset: 0x40C */
       uint8_t  RESERVED_3[1008];
  __IO uint32_t BUS_REG[EIM_BUS_REG_COUNT]    ; /* Bus Register, offset: 0x800 */

} EIM_Type, *EIM_MemMapPtr;


/* EIM - Peripheral instance base addresses */
/** Peripheral EIM base address */
#define EIM_BASE                                 (0x40019000u)
/** Peripheral EIM base pointer */
#define EIM                                      ((EIM_Type *)EIM_BASE)
// need fill by yourself
///** Number of interrupt vector arrays for the EIM module. */
//#define EIM_IRQS_ARR_COUNT                       (1u)
///** Number of interrupt channels for the EIM module. */
//#define EIM_IRQS_CH_COUNT                        (1u)
///** Interrupt vectors for the EIM peripheral type */
//#define EIM_IRQS                                 {EIM_IRQn}


/* ----------------------------------------------------------------------------
   -- EIM Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup EIM_Register_Masks EIM Register Masks
 * @{
 */

/* CR Bit Fields */
#define EIM_CR_GEIEN_MASK              0x1u
#define EIM_CR_GEIEN_SHIFT             0u
#define EIM_CR_GEIEN_WIDTH             1u
#define EIM_CR_GEIEN(x)                (((uint32_t)(((uint32_t)(x))<<EIM_CR_GEIEN_SHIFT))&EIM_CR_GEIEN_MASK)
/* CR Reg Mask */
#define EIM_CR_MASK                    0x00000001u

/* CTRL_REG Bit Fields */
#define EIM_CTRL_REG_DWP_LOCK_MASK     0x80000000u
#define EIM_CTRL_REG_DWP_LOCK_SHIFT    31u
#define EIM_CTRL_REG_DWP_LOCK_WIDTH    1u
#define EIM_CTRL_REG_DWP_LOCK(x)       (((uint32_t)(((uint32_t)(x))<<EIM_CTRL_REG_DWP_LOCK_SHIFT))&EIM_CTRL_REG_DWP_LOCK_MASK)
#define EIM_CTRL_REG_DWP_MASK          0x70000000u
#define EIM_CTRL_REG_DWP_SHIFT         28u
#define EIM_CTRL_REG_DWP_WIDTH         3u
#define EIM_CTRL_REG_DWP(x)            (((uint32_t)(((uint32_t)(x))<<EIM_CTRL_REG_DWP_SHIFT))&EIM_CTRL_REG_DWP_MASK)
#define EIM_CTRL_REG_BUS_SEL_MASK      0x30u
#define EIM_CTRL_REG_BUS_SEL_SHIFT     4u
#define EIM_CTRL_REG_BUS_SEL_WIDTH     2u
#define EIM_CTRL_REG_BUS_SEL(x)        (((uint32_t)(((uint32_t)(x))<<EIM_CTRL_REG_BUS_SEL_SHIFT))&EIM_CTRL_REG_BUS_SEL_MASK)
#define EIM_CTRL_REG_ATTREIE_MASK      0x8u
#define EIM_CTRL_REG_ATTREIE_SHIFT     3u
#define EIM_CTRL_REG_ATTREIE_WIDTH     1u
#define EIM_CTRL_REG_ATTREIE(x)        (((uint32_t)(((uint32_t)(x))<<EIM_CTRL_REG_ATTREIE_SHIFT))&EIM_CTRL_REG_ATTREIE_MASK)
#define EIM_CTRL_REG_ADDREIE_MASK      0x4u
#define EIM_CTRL_REG_ADDREIE_SHIFT     2u
#define EIM_CTRL_REG_ADDREIE_WIDTH     1u
#define EIM_CTRL_REG_ADDREIE(x)        (((uint32_t)(((uint32_t)(x))<<EIM_CTRL_REG_ADDREIE_SHIFT))&EIM_CTRL_REG_ADDREIE_MASK)
#define EIM_CTRL_REG_DATA1EIE_MASK     0x2u
#define EIM_CTRL_REG_DATA1EIE_SHIFT    1u
#define EIM_CTRL_REG_DATA1EIE_WIDTH    1u
#define EIM_CTRL_REG_DATA1EIE(x)       (((uint32_t)(((uint32_t)(x))<<EIM_CTRL_REG_DATA1EIE_SHIFT))&EIM_CTRL_REG_DATA1EIE_MASK)
#define EIM_CTRL_REG_DATA0EIE_MASK     0x1u
#define EIM_CTRL_REG_DATA0EIE_SHIFT    0u
#define EIM_CTRL_REG_DATA0EIE_WIDTH    1u
#define EIM_CTRL_REG_DATA0EIE(x)       (((uint32_t)(((uint32_t)(x))<<EIM_CTRL_REG_DATA0EIE_SHIFT))&EIM_CTRL_REG_DATA0EIE_MASK)
/* CTRL_REG0 Reg Mask */
#define EIM_CTRL_REG_MASK              0xF000003Fu

/* CPU0_LOCKSTEP Bit Fields */
#define EIM_LOCKSTEP_DWP_LOCK_MASK 0x80000000u
#define EIM_LOCKSTEP_DWP_LOCK_SHIFT 31u
#define EIM_LOCKSTEP_DWP_LOCK_WIDTH 1u
#define EIM_LOCKSTEP_DWP_LOCK(x)  (((uint32_t)(((uint32_t)(x))<<EIM_LOCKSTEP_DWP_LOCK_SHIFT))&EIM_LOCKSTEP_DWP_LOCK_MASK)
#define EIM_LOCKSTEP_DWP_MASK     0x70000000u
#define EIM_LOCKSTEP_DWP_SHIFT    28u
#define EIM_LOCKSTEP_DWP_WIDTH    3u
#define EIM_LOCKSTEP_DWP(x)       (((uint32_t)(((uint32_t)(x))<<EIM_LOCKSTEP_DWP_SHIFT))&EIM_LOCKSTEP_DWP_MASK)
#define EIM_LOCKSTEP_LOCKSTEP_MON0_SET_MASK 0x8u
#define EIM_LOCKSTEP_LOCKSTEP_MON0_SET_SHIFT 3u
#define EIM_LOCKSTEP_LOCKSTEP_MON0_SET_WIDTH 1u
#define EIM_LOCKSTEP_LOCKSTEP_MON0_SET(x) (((uint32_t)(((uint32_t)(x))<<EIM_LOCKSTEP_LOCKSTEP_MON0_SET_SHIFT))&EIM_LOCKSTEP_LOCKSTEP_MON0_SET_MASK)
#define EIM_LOCKSTEP_LOCKSTEP_MON1_SET_MASK 0x4u
#define EIM_LOCKSTEP_LOCKSTEP_MON1_SET_SHIFT 2u
#define EIM_LOCKSTEP_LOCKSTEP_MON1_SET_WIDTH 1u
#define EIM_LOCKSTEP_LOCKSTEP_MON1_SET(x) (((uint32_t)(((uint32_t)(x))<<EIM_LOCKSTEP_LOCKSTEP_MON1_SET_SHIFT))&EIM_LOCKSTEP_LOCKSTEP_MON1_SET_MASK)
#define EIM_LOCKSTEP_LOCKSTEP_MON0_CLR_MASK 0x2u
#define EIM_LOCKSTEP_LOCKSTEP_MON0_CLR_SHIFT 1u
#define EIM_LOCKSTEP_LOCKSTEP_MON0_CLR_WIDTH 1u
#define EIM_LOCKSTEP_LOCKSTEP_MON0_CLR(x) (((uint32_t)(((uint32_t)(x))<<EIM_LOCKSTEP_LOCKSTEP_MON0_CLR_SHIFT))&EIM_LOCKSTEP_LOCKSTEP_MON0_CLR_MASK)
#define EIM_LOCKSTEP_LOCKSTEP_MON1_CLR_MASK 0x1u
#define EIM_LOCKSTEP_LOCKSTEP_MON1_CLR_SHIFT 0u
#define EIM_LOCKSTEP_LOCKSTEP_MON1_CLR_WIDTH 1u
#define EIM_LOCKSTEP_LOCKSTEP_MON1_CLR(x) (((uint32_t)(((uint32_t)(x))<<EIM_LOCKSTEP_LOCKSTEP_MON1_CLR_SHIFT))&EIM_LOCKSTEP_LOCKSTEP_MON1_CLR_MASK)
/* CPU0_LOCKSTEP Reg Mask */
#define EIM_LOCKSTEP_MASK         0xF000000Fu

/* DMA0_LOCKSTEP Bit Fields */
#define EIM_DMA0_LOCKSTEP_DWP_LOCK_MASK 0x80000000u
#define EIM_DMA0_LOCKSTEP_DWP_LOCK_SHIFT 31u
#define EIM_DMA0_LOCKSTEP_DWP_LOCK_WIDTH 1u
#define EIM_DMA0_LOCKSTEP_DWP_LOCK(x)  (((uint32_t)(((uint32_t)(x))<<EIM_DMA0_LOCKSTEP_DWP_LOCK_SHIFT))&EIM_DMA0_LOCKSTEP_DWP_LOCK_MASK)
#define EIM_DMA0_LOCKSTEP_DWP_MASK     0x70000000u
#define EIM_DMA0_LOCKSTEP_DWP_SHIFT    28u
#define EIM_DMA0_LOCKSTEP_DWP_WIDTH    3u
#define EIM_DMA0_LOCKSTEP_DWP(x)       (((uint32_t)(((uint32_t)(x))<<EIM_DMA0_LOCKSTEP_DWP_SHIFT))&EIM_DMA0_LOCKSTEP_DWP_MASK)
#define EIM_DMA0_LOCKSTEP_LOCKSTEP_MON0_SET_MASK 0x8u
#define EIM_DMA0_LOCKSTEP_LOCKSTEP_MON0_SET_SHIFT 3u
#define EIM_DMA0_LOCKSTEP_LOCKSTEP_MON0_SET_WIDTH 1u
#define EIM_DMA0_LOCKSTEP_LOCKSTEP_MON0_SET(x) (((uint32_t)(((uint32_t)(x))<<EIM_DMA0_LOCKSTEP_LOCKSTEP_MON0_SET_SHIFT))&EIM_DMA0_LOCKSTEP_LOCKSTEP_MON0_SET_MASK)
#define EIM_DMA0_LOCKSTEP_LOCKSTEP_MON1_SET_MASK 0x4u
#define EIM_DMA0_LOCKSTEP_LOCKSTEP_MON1_SET_SHIFT 2u
#define EIM_DMA0_LOCKSTEP_LOCKSTEP_MON1_SET_WIDTH 1u
#define EIM_DMA0_LOCKSTEP_LOCKSTEP_MON1_SET(x) (((uint32_t)(((uint32_t)(x))<<EIM_DMA0_LOCKSTEP_LOCKSTEP_MON1_SET_SHIFT))&EIM_DMA0_LOCKSTEP_LOCKSTEP_MON1_SET_MASK)
#define EIM_DMA0_LOCKSTEP_LOCKSTEP_MON0_CLR_MASK 0x2u
#define EIM_DMA0_LOCKSTEP_LOCKSTEP_MON0_CLR_SHIFT 1u
#define EIM_DMA0_LOCKSTEP_LOCKSTEP_MON0_CLR_WIDTH 1u
#define EIM_DMA0_LOCKSTEP_LOCKSTEP_MON0_CLR(x) (((uint32_t)(((uint32_t)(x))<<EIM_DMA0_LOCKSTEP_LOCKSTEP_MON0_CLR_SHIFT))&EIM_DMA0_LOCKSTEP_LOCKSTEP_MON0_CLR_MASK)
#define EIM_DMA0_LOCKSTEP_LOCKSTEP_MON1_CLR_MASK 0x1u
#define EIM_DMA0_LOCKSTEP_LOCKSTEP_MON1_CLR_SHIFT 0u
#define EIM_DMA0_LOCKSTEP_LOCKSTEP_MON1_CLR_WIDTH 1u
#define EIM_DMA0_LOCKSTEP_LOCKSTEP_MON1_CLR(x) (((uint32_t)(((uint32_t)(x))<<EIM_DMA0_LOCKSTEP_LOCKSTEP_MON1_CLR_SHIFT))&EIM_DMA0_LOCKSTEP_LOCKSTEP_MON1_CLR_MASK)
/* DMA0_LOCKSTEP Reg Mask */
#define EIM_DMA0_LOCKSTEP_MASK         0xF000000Fu

/* BUS_REG Bit Fields */
#define EIM_BUS_REG_ATTR_MASK          0x1F000000u
#define EIM_BUS_REG_ATTR_SHIFT         24u
#define EIM_BUS_REG_ATTR_WIDTH         5u
#define EIM_BUS_REG_ATTR(x)            (((uint32_t)(((uint32_t)(x))<<EIM_BUS_REG_ATTR_SHIFT))&EIM_BUS_REG_ATTR_MASK)
#define EIM_BUS_REG_ADDR_MASK          0x1F0000u
#define EIM_BUS_REG_ADDR_SHIFT         16u
#define EIM_BUS_REG_ADDR_WIDTH         5u
#define EIM_BUS_REG_ADDR(x)            (((uint32_t)(((uint32_t)(x))<<EIM_BUS_REG_ADDR_SHIFT))&EIM_BUS_REG_ADDR_MASK)
#define EIM_BUS_REG_DATA1_MASK         0x7F00u
#define EIM_BUS_REG_DATA1_SHIFT        8u
#define EIM_BUS_REG_DATA1_WIDTH        7u
#define EIM_BUS_REG_DATA1(x)           (((uint32_t)(((uint32_t)(x))<<EIM_BUS_REG_DATA1_SHIFT))&EIM_BUS_REG_DATA1_MASK)
#define EIM_BUS_REG_DATA0_MASK         0x7Fu
#define EIM_BUS_REG_DATA0_SHIFT        0u
#define EIM_BUS_REG_DATA0_WIDTH        7u
#define EIM_BUS_REG_DATA0(x)           (((uint32_t)(((uint32_t)(x))<<EIM_BUS_REG_DATA0_SHIFT))&EIM_BUS_REG_DATA0_MASK)
/* BUS_REG0 Reg Mask */
#define EIM_BUS_REG_MASK               0x1F1F7F7Fu


/*!
 * @}
 */ /* end of group EIM_Register_Masks */

/*!
 * @}
 */ /* end of group EIM_Peripheral_Access_Layer */

#endif
