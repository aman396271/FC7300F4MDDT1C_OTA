#ifndef _MODULE_MB_gmbhdijq186_REGS_H_MB_H_
#define _MODULE_MB_gmbhdijq186_REGS_H_MB_H_

/* ----------------------------------------------------------------------------
   -- MB Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup MB_Peripheral_Access_Layer MB Peripheral Access Layer
 * @{
 */

/** MB - Size of Registers Arrays */

/** MB - Register Layout Typedef */

typedef struct {
	struct
	{
		__I  uint32_t CCn_SEMA                   ; /* MB_CCn_SEMA, offset: 0x000 */
		__IO uint32_t CCn_SEMA_UNLK              ; /* CCn_SEMA_UNLK, offset: 0x004 */
		__O  uint32_t CCn_REQUEST                ; /* CCn_REQUEST, offset: 0x008 */
		__IO uint32_t CCn_DONE                   ; /* CCn_DONE, offset: 0x00C */
		__IO uint32_t CCn_DONE_MASK              ; /* MB_CCn_DONE_MASK, offset: 0x010 */
		__IO uint32_t CCn_DATA0                  ; /* CCn_DATA0, offset: 0x014 */
		__IO uint32_t CCn_DATA1                  ; /* CCn_DATA1, offset: 0x018 */
		__I  uint32_t CCn_STAT                   ; /* CCn_STAT, offset: 0x01C */
		__O  uint32_t CCn_CLR                    ; /* CCn_CLR, offset: 0x020 */
			 uint8_t  RESERVED_0[12];
	} CHANNEL[4];
	uint8_t  RESERVED_15[1856];
	struct
	{
		__IO uint32_t CCn_FLG                    ; /* CCn_FLG, offset: 0x800 */
		__IO uint32_t CCn_FLG_MASK               ; /* CCn_FLG_MASK, offset: 0x804 */
		__IO uint32_t CCn_INTEN                  ; /* CCn_INTEN, offset: 0x808 */
		__IO uint32_t CCn_FLG_STAT               ; /* CCn_FLG_STAT, offset: 0x80C */
		__IO uint32_t CCn_CTRL                   ; /* CCn_CTRL, offset: 0x810 */
		   	 uint8_t  RESERVED_18[12];
	} INTR[2];
} MB_Type, *MB_MemMapPtr;


/* MB - Peripheral instance base addresses */
/** Peripheral MB base address */
#define MB_BASE                                  (0x40058000u)
/** Peripheral MB base pointer */
#define MB                                       ((MB_Type *)MB_BASE)
// need fill by yourself
///** Number of interrupt vector arrays for the MB module. */
//#define MB_IRQS_ARR_COUNT                       (1u)
///** Number of interrupt channels for the MB module. */
//#define MB_IRQS_CH_COUNT                        (1u)
///** Interrupt vectors for the MB peripheral type */
//#define MB_IRQS                                  {MB0_IRQn}


/* ----------------------------------------------------------------------------
   -- MB Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup MB_Register_Masks MB Register Masks
 * @{
 */

/* CCn_SEMA Bit Fields */
#define MB_CCn_SEMA_LOCK_MASK          0x80000000u
#define MB_CCn_SEMA_LOCK_SHIFT         31u
#define MB_CCn_SEMA_LOCK_WIDTH         1u
#define MB_CCn_SEMA_LOCK(x)            (((uint32_t)(((uint32_t)(x))<<MB_CCn_SEMA_LOCK_SHIFT))&MB_CCn_SEMA_LOCK_MASK)
#define MB_CCn_SEMA_LOCK_MASTER_ID_MASK 0xF0u
#define MB_CCn_SEMA_LOCK_MASTER_ID_SHIFT 4u
#define MB_CCn_SEMA_LOCK_MASTER_ID_WIDTH 4u
#define MB_CCn_SEMA_LOCK_MASTER_ID(x)  (((uint32_t)(((uint32_t)(x))<<MB_CCn_SEMA_LOCK_MASTER_ID_SHIFT))&MB_CCn_SEMA_LOCK_MASTER_ID_MASK)
#define MB_CCn_SEMA_LOCK_MASTER_SEC_MASK 0x2u
#define MB_CCn_SEMA_LOCK_MASTER_SEC_SHIFT 1u
#define MB_CCn_SEMA_LOCK_MASTER_SEC_WIDTH 1u
#define MB_CCn_SEMA_LOCK_MASTER_SEC(x) (((uint32_t)(((uint32_t)(x))<<MB_CCn_SEMA_LOCK_MASTER_SEC_SHIFT))&MB_CCn_SEMA_LOCK_MASTER_SEC_MASK)
#define MB_CCn_SEMA_LOCK_MASTER_SUPERVISOR_MASK 0x1u
#define MB_CCn_SEMA_LOCK_MASTER_SUPERVISOR_SHIFT 0u
#define MB_CCn_SEMA_LOCK_MASTER_SUPERVISOR_WIDTH 1u
#define MB_CCn_SEMA_LOCK_MASTER_SUPERVISOR(x) (((uint32_t)(((uint32_t)(x))<<MB_CCn_SEMA_LOCK_MASTER_SUPERVISOR_SHIFT))&MB_CCn_SEMA_LOCK_MASTER_SUPERVISOR_MASK)
/* CC0_SEMA Reg Mask */
#define MB_CCn_SEMA_MASK               0x800000F3u

/* CCn_SEMA_UNLK Bit Fields */
#define MB_CCn_SEMA_UNLK_AUTO_CLEAR_EN1_MASK 0x2u
#define MB_CCn_SEMA_UNLK_AUTO_CLEAR_EN1_SHIFT 1u
#define MB_CCn_SEMA_UNLK_AUTO_CLEAR_EN1_WIDTH 1u
#define MB_CCn_SEMA_UNLK_AUTO_CLEAR_EN1(x) (((uint32_t)(((uint32_t)(x))<<MB_CCn_SEMA_UNLK_AUTO_CLEAR_EN1_SHIFT))&MB_CCn_SEMA_UNLK_AUTO_CLEAR_EN1_MASK)
#define MB_CCn_SEMA_UNLK_AUTO_CLEAR_EN0_MASK 0x1u
#define MB_CCn_SEMA_UNLK_AUTO_CLEAR_EN0_SHIFT 0u
#define MB_CCn_SEMA_UNLK_AUTO_CLEAR_EN0_WIDTH 1u
#define MB_CCn_SEMA_UNLK_AUTO_CLEAR_EN0(x) (((uint32_t)(((uint32_t)(x))<<MB_CCn_SEMA_UNLK_AUTO_CLEAR_EN0_SHIFT))&MB_CCn_SEMA_UNLK_AUTO_CLEAR_EN0_MASK)
/* CC0_SEMA_UNLK Reg Mask */
#define MB_CCn_SEMA_UNLK_MASK          0x00000003u

/* CCn_REQUEST Bit Fields */
#define MB_CCn_REQUEST_REQ1_MASK       0x2u
#define MB_CCn_REQUEST_REQ1_SHIFT      1u
#define MB_CCn_REQUEST_REQ1_WIDTH      1u
#define MB_CCn_REQUEST_REQ1(x)         (((uint32_t)(((uint32_t)(x))<<MB_CCn_REQUEST_REQ1_SHIFT))&MB_CCn_REQUEST_REQ1_MASK)
#define MB_CCn_REQUEST_REQ0_MASK       0x1u
#define MB_CCn_REQUEST_REQ0_SHIFT      0u
#define MB_CCn_REQUEST_REQ0_WIDTH      1u
#define MB_CCn_REQUEST_REQ0(x)         (((uint32_t)(((uint32_t)(x))<<MB_CCn_REQUEST_REQ0_SHIFT))&MB_CCn_REQUEST_REQ0_MASK)
/* CC0_REQUEST Reg Mask */
#define MB_CCn_REQUEST_MASK            0x00000003u

/* CCn_DONE Bit Fields */
#define MB_CCn_DONE_DONE1_MASK         0x2u
#define MB_CCn_DONE_DONE1_SHIFT        1u
#define MB_CCn_DONE_DONE1_WIDTH        1u
#define MB_CCn_DONE_DONE1(x)           (((uint32_t)(((uint32_t)(x))<<MB_CCn_DONE_DONE1_SHIFT))&MB_CCn_DONE_DONE1_MASK)
#define MB_CCn_DONE_DONE0_MASK         0x1u
#define MB_CCn_DONE_DONE0_SHIFT        0u
#define MB_CCn_DONE_DONE0_WIDTH        1u
#define MB_CCn_DONE_DONE0(x)           (((uint32_t)(((uint32_t)(x))<<MB_CCn_DONE_DONE0_SHIFT))&MB_CCn_DONE_DONE0_MASK)
/* CC0_DONE Reg Mask */
#define MB_CCn_DONE_MASK               0x00000003u

/* CCn_DONE_MASK Bit Fields */
#define MB_CCn_DONE_MASK_DONE_MASTER_ID_MASK 0xF0000u
#define MB_CCn_DONE_MASK_DONE_MASTER_ID_SHIFT 16u
#define MB_CCn_DONE_MASK_DONE_MASTER_ID_WIDTH 4u
#define MB_CCn_DONE_MASK_DONE_MASTER_ID(x) (((uint32_t)(((uint32_t)(x))<<MB_CCn_DONE_MASK_DONE_MASTER_ID_SHIFT))&MB_CCn_DONE_MASK_DONE_MASTER_ID_MASK)
#define MB_CCn_DONE_MASK_DONE_MASK1_MASK 0x2u
#define MB_CCn_DONE_MASK_DONE_MASK1_SHIFT 1u
#define MB_CCn_DONE_MASK_DONE_MASK1_WIDTH 1u
#define MB_CCn_DONE_MASK_DONE_MASK1(x) (((uint32_t)(((uint32_t)(x))<<MB_CCn_DONE_MASK_DONE_MASK1_SHIFT))&MB_CCn_DONE_MASK_DONE_MASK1_MASK)
#define MB_CCn_DONE_MASK_DONE_MASK0_MASK 0x1u
#define MB_CCn_DONE_MASK_DONE_MASK0_SHIFT 0u
#define MB_CCn_DONE_MASK_DONE_MASK0_WIDTH 1u
#define MB_CCn_DONE_MASK_DONE_MASK0(x) (((uint32_t)(((uint32_t)(x))<<MB_CCn_DONE_MASK_DONE_MASK0_SHIFT))&MB_CCn_DONE_MASK_DONE_MASK0_MASK)
/* CC0_DONE_MASK Reg Mask */
#define MB_CCn_DONE_MASK_MASK          0x000F0003u

/* CCn_DATA0 Bit Fields */
#define MB_CCn_DATA0_DATA0_MASK        0xFFFFFFFFu
#define MB_CCn_DATA0_DATA0_SHIFT       0u
#define MB_CCn_DATA0_DATA0_WIDTH       32u
#define MB_CCn_DATA0_DATA0(x)          (((uint32_t)(((uint32_t)(x))<<MB_CCn_DATA0_DATA0_SHIFT))&MB_CCn_DATA0_DATA0_MASK)
/* CC0_DATA0 Reg Mask */
#define MB_CCn_DATA0_MASK              0xFFFFFFFFu

/* CCn_DATA1 Bit Fields */
#define MB_CCn_DATA1_DATA1_MASK        0xFFFFFFFFu
#define MB_CCn_DATA1_DATA1_SHIFT       0u
#define MB_CCn_DATA1_DATA1_WIDTH       32u
#define MB_CCn_DATA1_DATA1(x)          (((uint32_t)(((uint32_t)(x))<<MB_CCn_DATA1_DATA1_SHIFT))&MB_CCn_DATA1_DATA1_MASK)
/* CC0_DATA1 Reg Mask */
#define MB_CCn_DATA1_MASK              0xFFFFFFFFu

/* CCn_STAT Bit Fields */
#define MB_CCn_STAT_CURRENT_LOCK_STATUS_MASK 0x80000000u
#define MB_CCn_STAT_CURRENT_LOCK_STATUS_SHIFT 31u
#define MB_CCn_STAT_CURRENT_LOCK_STATUS_WIDTH 1u
#define MB_CCn_STAT_CURRENT_LOCK_STATUS(x) (((uint32_t)(((uint32_t)(x))<<MB_CCn_STAT_CURRENT_LOCK_STATUS_SHIFT))&MB_CCn_STAT_CURRENT_LOCK_STATUS_MASK)
#define MB_CCn_STAT_CURRENT_CPU_STATUS_MASK 0xFFFF00u
#define MB_CCn_STAT_CURRENT_CPU_STATUS_SHIFT 8u
#define MB_CCn_STAT_CURRENT_CPU_STATUS_WIDTH 16u
#define MB_CCn_STAT_CURRENT_CPU_STATUS(x) (((uint32_t)(((uint32_t)(x))<<MB_CCn_STAT_CURRENT_CPU_STATUS_SHIFT))&MB_CCn_STAT_CURRENT_CPU_STATUS_MASK)
#define MB_CCn_STAT_CURRENT_LOCK_MASTER_ID_MASK 0xF0u
#define MB_CCn_STAT_CURRENT_LOCK_MASTER_ID_SHIFT 4u
#define MB_CCn_STAT_CURRENT_LOCK_MASTER_ID_WIDTH 4u
#define MB_CCn_STAT_CURRENT_LOCK_MASTER_ID(x) (((uint32_t)(((uint32_t)(x))<<MB_CCn_STAT_CURRENT_LOCK_MASTER_ID_SHIFT))&MB_CCn_STAT_CURRENT_LOCK_MASTER_ID_MASK)
#define MB_CCn_STAT_CURRENT_LOCK_MASTER_SEC_MASK 0x2u
#define MB_CCn_STAT_CURRENT_LOCK_MASTER_SEC_SHIFT 1u
#define MB_CCn_STAT_CURRENT_LOCK_MASTER_SEC_WIDTH 1u
#define MB_CCn_STAT_CURRENT_LOCK_MASTER_SEC(x) (((uint32_t)(((uint32_t)(x))<<MB_CCn_STAT_CURRENT_LOCK_MASTER_SEC_SHIFT))&MB_CCn_STAT_CURRENT_LOCK_MASTER_SEC_MASK)
#define MB_CCn_STAT_CURRENT_LOCK_MASTER_SUPERVISOR_MASK 0x1u
#define MB_CCn_STAT_CURRENT_LOCK_MASTER_SUPERVISOR_SHIFT 0u
#define MB_CCn_STAT_CURRENT_LOCK_MASTER_SUPERVISOR_WIDTH 1u
#define MB_CCn_STAT_CURRENT_LOCK_MASTER_SUPERVISOR(x) (((uint32_t)(((uint32_t)(x))<<MB_CCn_STAT_CURRENT_LOCK_MASTER_SUPERVISOR_SHIFT))&MB_CCn_STAT_CURRENT_LOCK_MASTER_SUPERVISOR_MASK)
/* CC0_STAT Reg Mask */
#define MB_CCn_STAT_MASK               0x80FFFFF3u

/* CCn_CLR Bit Fields */
#define MB_CCn_CLR_SOFTWARE_CLEAR_LOCK_MASK 0xFFFFFFFFu
#define MB_CCn_CLR_SOFTWARE_CLEAR_LOCK_SHIFT 0u
#define MB_CCn_CLR_SOFTWARE_CLEAR_LOCK_WIDTH 32u
#define MB_CCn_CLR_SOFTWARE_CLEAR_LOCK(x) (((uint32_t)(((uint32_t)(x))<<MB_CCn_CLR_SOFTWARE_CLEAR_LOCK_SHIFT))&MB_CCn_CLR_SOFTWARE_CLEAR_LOCK_MASK)
/* CC0_CLR Reg Mask */
#define MB_CCn_CLR_MASK                0xFFFFFFFFu

/* INTn_FLG Bit Fields */
#define MB_INTn_FLG_DONE_FLAG_MASK     0xF0000u
#define MB_INTn_FLG_DONE_FLAG_SHIFT    16u
#define MB_INTn_FLG_DONE_FLAG_WIDTH    4u
#define MB_INTn_FLG_DONE_FLAG(x)       (((uint32_t)(((uint32_t)(x))<<MB_INTn_FLG_DONE_FLAG_SHIFT))&MB_INTn_FLG_DONE_FLAG_MASK)
#define MB_INTn_FLG_REQ_FLAG_MASK      0xFu
#define MB_INTn_FLG_REQ_FLAG_SHIFT     0u
#define MB_INTn_FLG_REQ_FLAG_WIDTH     4u
#define MB_INTn_FLG_REQ_FLAG(x)        (((uint32_t)(((uint32_t)(x))<<MB_INTn_FLG_REQ_FLAG_SHIFT))&MB_INTn_FLG_REQ_FLAG_MASK)
/* INT0_FLG Reg Mask */
#define MB_INTn_FLG_MASK               0x000F000Fu

/* INTn_FLG_MASK Bit Fields */
#define MB_INTn_FLG_MASK_DONE_FLAG_MASK_MASK 0xF0000u
#define MB_INTn_FLG_MASK_DONE_FLAG_MASK_SHIFT 16u
#define MB_INTn_FLG_MASK_DONE_FLAG_MASK_WIDTH 4u
#define MB_INTn_FLG_MASK_DONE_FLAG_MASK(x) (((uint32_t)(((uint32_t)(x))<<MB_INTn_FLG_MASK_DONE_FLAG_MASK_SHIFT))&MB_INTn_FLG_MASK_DONE_FLAG_MASK_MASK)
#define MB_INTn_FLG_MASK_REQ_FLAG_MASK_MASK 0xFu
#define MB_INTn_FLG_MASK_REQ_FLAG_MASK_SHIFT 0u
#define MB_INTn_FLG_MASK_REQ_FLAG_MASK_WIDTH 4u
#define MB_INTn_FLG_MASK_REQ_FLAG_MASK(x) (((uint32_t)(((uint32_t)(x))<<MB_INTn_FLG_MASK_REQ_FLAG_MASK_SHIFT))&MB_INTn_FLG_MASK_REQ_FLAG_MASK_MASK)
/* INT0_FLG_MASK Reg Mask */
#define MB_INTn_FLG_MASK_MASK          0x000F000Fu

/* INTn_INTEN Bit Fields */
#define MB_INTn_INTEN_DONE_INT_EN_MASK 0xF0000u
#define MB_INTn_INTEN_DONE_INT_EN_SHIFT 16u
#define MB_INTn_INTEN_DONE_INT_EN_WIDTH 4u
#define MB_INTn_INTEN_DONE_INT_EN(x)   (((uint32_t)(((uint32_t)(x))<<MB_INTn_INTEN_DONE_INT_EN_SHIFT))&MB_INTn_INTEN_DONE_INT_EN_MASK)
#define MB_INTn_INTEN_REQ_INT_EN_MASK  0xFu
#define MB_INTn_INTEN_REQ_INT_EN_SHIFT 0u
#define MB_INTn_INTEN_REQ_INT_EN_WIDTH 4u
#define MB_INTn_INTEN_REQ_INT_EN(x)    (((uint32_t)(((uint32_t)(x))<<MB_INTn_INTEN_REQ_INT_EN_SHIFT))&MB_INTn_INTEN_REQ_INT_EN_MASK)
/* INT0_INTEN Reg Mask */
#define MB_INTn_INTEN_MASK             0x000F000Fu

/* INTn_FLG_STAT Bit Fields */
#define MB_INTn_FLG_STAT_FLG_DONE_INT_STAT_MASK 0xF0000u
#define MB_INTn_FLG_STAT_FLG_DONE_INT_STAT_SHIFT 16u
#define MB_INTn_FLG_STAT_FLG_DONE_INT_STAT_WIDTH 4u
#define MB_INTn_FLG_STAT_FLG_DONE_INT_STAT(x) (((uint32_t)(((uint32_t)(x))<<MB_INTn_FLG_STAT_FLG_DONE_INT_STAT_SHIFT))&MB_INTn_FLG_STAT_FLG_DONE_INT_STAT_MASK)
#define MB_INTn_FLG_STAT_FLG_REQ_INT_STAT_MASK 0xFu
#define MB_INTn_FLG_STAT_FLG_REQ_INT_STAT_SHIFT 0u
#define MB_INTn_FLG_STAT_FLG_REQ_INT_STAT_WIDTH 4u
#define MB_INTn_FLG_STAT_FLG_REQ_INT_STAT(x) (((uint32_t)(((uint32_t)(x))<<MB_INTn_FLG_STAT_FLG_REQ_INT_STAT_SHIFT))&MB_INTn_FLG_STAT_FLG_REQ_INT_STAT_MASK)
/* INT0_FLG_STAT Reg Mask */
#define MB_INTn_FLG_STAT_MASK          0x000F000Fu

/* INTn_CTRL Bit Fields */
#define MB_INTn_CTRL_INTEN_LOCK_MASK   0x4u
#define MB_INTn_CTRL_INTEN_LOCK_SHIFT  2u
#define MB_INTn_CTRL_INTEN_LOCK_WIDTH  1u
#define MB_INTn_CTRL_INTEN_LOCK(x)     (((uint32_t)(((uint32_t)(x))<<MB_INTn_CTRL_INTEN_LOCK_SHIFT))&MB_INTn_CTRL_INTEN_LOCK_MASK)
#define MB_INTn_CTRL_FLG_MASK_LOCK_MASK 0x2u
#define MB_INTn_CTRL_FLG_MASK_LOCK_SHIFT 1u
#define MB_INTn_CTRL_FLG_MASK_LOCK_WIDTH 1u
#define MB_INTn_CTRL_FLG_MASK_LOCK(x)  (((uint32_t)(((uint32_t)(x))<<MB_INTn_CTRL_FLG_MASK_LOCK_SHIFT))&MB_INTn_CTRL_FLG_MASK_LOCK_MASK)
#define MB_INTn_CTRL_FLG_LOCK_MASK     0x1u
#define MB_INTn_CTRL_FLG_LOCK_SHIFT    0u
#define MB_INTn_CTRL_FLG_LOCK_WIDTH    1u
#define MB_INTn_CTRL_FLG_LOCK(x)       (((uint32_t)(((uint32_t)(x))<<MB_INTn_CTRL_FLG_LOCK_SHIFT))&MB_INTn_CTRL_FLG_LOCK_MASK)
/* INT0_CTRL Reg Mask */
#define MB_INTn_CTRL_MASK              0x00000007u


/*!
 * @}
 */ /* end of group MB_Register_Masks */

/*!
 * @}
 */ /* end of group MB_Peripheral_Access_Layer */

#endif
