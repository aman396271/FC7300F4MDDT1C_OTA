#ifndef _MODULE_CRM_gmbhdijq152_REGS_H_CRM_H_
#define _MODULE_CRM_gmbhdijq152_REGS_H_CRM_H_

/* ----------------------------------------------------------------------------
   -- CRM Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup CRM_Peripheral_Access_Layer CRM Peripheral Access Layer
 * @{
 */

/** CRM - Size of Registers Arrays */

/** CRM - Register Layout Typedef */

typedef struct {

  __IO uint32_t CH0_MATCH_ID0                 ; /* Channel n Match ID0 Register, offset: 0x0 */
  __IO uint32_t CH0_MATCH_ID1                 ; /* Channel n Match ID1 Register, offset: 0x4 */
       uint8_t  RESERVED_0[56];
  __IO uint32_t CH0_ROUTER_ID0                ; /* Channel n Router ID0 Register, offset: 0x40 */
  __IO uint32_t CH0_ROUTER_CS0                ; /* Channel n Router CS0 Register, offset: 0x44 */
  __IO uint32_t CH0_ROUTER_ID1                ; /* Channel n Router ID1 Register, offset: 0x48 */
  __IO uint32_t CH0_ROUTER_CS1                ; /* Channel n Router CS1 Register, offset: 0x4c */
       uint8_t  RESERVED_1[112];
  __IO uint32_t CH0_MATCH_MASK                ; /* Channel n Match Mask Register, offset: 0xc0 */
       uint8_t  RESERVED_2[28];
  __I  uint32_t CH0_MAP_CS                    ; /* Channel n Mapping CS Register, offset: 0xe0 */
  __I  uint32_t CH0_MAP_ID                    ; /* Channel n Mapping ID Register, offset: 0xe4 */
       uint8_t  RESERVED_3[24];
  __IO uint32_t CH1_MATCH_ID0                 ; /* Channel n Match ID0 Register, offset: 0x100 */
  __IO uint32_t CH1_MATCH_ID1                 ; /* Channel n Match ID1 Register, offset: 0x104 */
       uint8_t  RESERVED_4[56];
  __IO uint32_t CH1_ROUTER_ID0                ; /* Channel n Router ID0 Register, offset: 0x140 */
  __IO uint32_t CH1_ROUTER_CS0                ; /* Channel n Router CS0 Register, offset: 0x144 */
  __IO uint32_t CH1_ROUTER_ID1                ; /* Channel n Router ID1 Register, offset: 0x148 */
  __IO uint32_t CH1_ROUTER_CS1                ; /* Channel n Router CS1 Register, offset: 0x14c */
       uint8_t  RESERVED_5[112];
  __IO uint32_t CH1_MATCH_MASK                ; /* Channel n Match Mask Register, offset: 0x1c0 */
       uint8_t  RESERVED_6[28];
  __I  uint32_t CH1_MAP_CS                    ; /* Channel n Mapping CS Register, offset: 0x1e0 */
  __I  uint32_t CH1_MAP_ID                    ; /* Channel n Mapping ID Register, offset: 0x1e4 */
       uint8_t  RESERVED_7[24];
  __IO uint32_t CH2_MATCH_ID0                 ; /* Channel n Match ID0 Register, offset: 0x200 */
  __IO uint32_t CH2_MATCH_ID1                 ; /* Channel n Match ID1 Register, offset: 0x204 */
       uint8_t  RESERVED_8[56];
  __IO uint32_t CH2_ROUTER_ID0                ; /* Channel n Router ID0 Register, offset: 0x240 */
  __IO uint32_t CH2_ROUTER_CS0                ; /* Channel n Router CS0 Register, offset: 0x244 */
  __IO uint32_t CH2_ROUTER_ID1                ; /* Channel n Router ID1 Register, offset: 0x248 */
  __IO uint32_t CH2_ROUTER_CS1                ; /* Channel n Router CS1 Register, offset: 0x24c */
       uint8_t  RESERVED_9[112];
  __IO uint32_t CH2_MATCH_MASK                ; /* Channel n Match Mask Register, offset: 0x2c0 */
       uint8_t  RESERVED_10[28];
  __I  uint32_t CH2_MAP_CS                    ; /* Channel n Mapping CS Register, offset: 0x2e0 */
  __I  uint32_t CH2_MAP_ID                    ; /* Channel n Mapping ID Register, offset: 0x2e4 */
       uint8_t  RESERVED_11[24];
  __IO uint32_t CH3_MATCH_ID0                 ; /* Channel n Match ID0 Register, offset: 0x300 */
  __IO uint32_t CH3_MATCH_ID1                 ; /* Channel n Match ID1 Register, offset: 0x304 */
       uint8_t  RESERVED_12[56];
  __IO uint32_t CH3_ROUTER_ID0                ; /* Channel n Router ID0 Register, offset: 0x340 */
  __IO uint32_t CH3_ROUTER_CS0                ; /* Channel n Router CS0 Register, offset: 0x344 */
  __IO uint32_t CH3_ROUTER_ID1                ; /* Channel n Router ID1 Register, offset: 0x348 */
  __IO uint32_t CH3_ROUTER_CS1                ; /* Channel n Router CS1 Register, offset: 0x34c */
       uint8_t  RESERVED_13[112];
  __IO uint32_t CH3_MATCH_MASK                ; /* Channel n Match Mask Register, offset: 0x3c0 */
       uint8_t  RESERVED_14[28];
  __I  uint32_t CH3_MAP_CS                    ; /* Channel n Mapping CS Register, offset: 0x3e0 */
  __I  uint32_t CH3_MAP_ID                    ; /* Channel n Mapping ID Register, offset: 0x3e4 */
       uint8_t  RESERVED_15[1048];
  __IO uint32_t CANR_IEN                      ; /* CAN Router Register, offset: 0x800 */
  __IO uint32_t CANR_STATUS                   ; /* CAN Router Status Register, offset: 0x804 */
  __IO uint32_t CANR_CTRL                     ; /* CAN Router Control Register, offset: 0x808 */

} CRM_Type, *CRM_MemMapPtr;


/* CRM - Peripheral instance base addresses */
/** Peripheral CRM base address */
#define CRM_BASE                                 (0x40444000u)
/** Peripheral CRM base pointer */
#define CRM                                      ((CRM_Type *)CRM_BASE)
// need fill by yourself
///** Number of interrupt vector arrays for the CRM module. */
//#define CRM_IRQS_ARR_COUNT                       (1u)
///** Number of interrupt channels for the CRM module. */
//#define CRM_IRQS_CH_COUNT                        (1u)
///** Interrupt vectors for the CRM peripheral type */
//#define CRM_IRQS                                 {CRM0_IRQn}


/* ----------------------------------------------------------------------------
   -- CRM Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup CRM_Register_Masks CRM Register Masks
 * @{
 */

/* CHn_MATCH_ID0 Bit Fields */
#define CRM_CHn_MATCH_ID0_ID_MASK      0xFFFFFFFFu
#define CRM_CHn_MATCH_ID0_ID_SHIFT     0u
#define CRM_CHn_MATCH_ID0_ID_WIDTH     32u
#define CRM_CHn_MATCH_ID0_ID(x)        (((uint32_t)(((uint32_t)(x))<<CRM_CHn_MATCH_ID0_ID_SHIFT))&CRM_CHn_MATCH_ID0_ID_MASK)
/* CH0_MATCH_ID0 Reg Mask */
#define CRM_CHn_MATCH_ID0_MASK         0xFFFFFFFFu

/* CHn_MATCH_ID1 Bit Fields */
#define CRM_CHn_MATCH_ID1_ID_MASK      0xFFFFFFFFu
#define CRM_CHn_MATCH_ID1_ID_SHIFT     0u
#define CRM_CHn_MATCH_ID1_ID_WIDTH     32u
#define CRM_CHn_MATCH_ID1_ID(x)        (((uint32_t)(((uint32_t)(x))<<CRM_CHn_MATCH_ID1_ID_SHIFT))&CRM_CHn_MATCH_ID1_ID_MASK)
/* CH0_MATCH_ID1 Reg Mask */
#define CRM_CHn_MATCH_ID1_MASK         0xFFFFFFFFu

/* CHn_ROUTER_ID0 Bit Fields */
#define CRM_CHn_ROUTER_ID0_ID_MASK     0xFFFFFFFFu
#define CRM_CHn_ROUTER_ID0_ID_SHIFT    0u
#define CRM_CHn_ROUTER_ID0_ID_WIDTH    32u
#define CRM_CHn_ROUTER_ID0_ID(x)       (((uint32_t)(((uint32_t)(x))<<CRM_CHn_ROUTER_ID0_ID_SHIFT))&CRM_CHn_ROUTER_ID0_ID_MASK)
/* CH0_ROUTER_ID0 Reg Mask */
#define CRM_CHn_ROUTER_ID0_MASK        0xFFFFFFFFu

/* CHn_ROUTER_CS0 Bit Fields */
#define CRM_CHn_ROUTER_CS0_CS_MASK     0xFFFFFFFFu
#define CRM_CHn_ROUTER_CS0_CS_SHIFT    0u
#define CRM_CHn_ROUTER_CS0_CS_WIDTH    32u
#define CRM_CHn_ROUTER_CS0_CS(x)       (((uint32_t)(((uint32_t)(x))<<CRM_CHn_ROUTER_CS0_CS_SHIFT))&CRM_CHn_ROUTER_CS0_CS_MASK)
/* CH0_ROUTER_CS0 Reg Mask */
#define CRM_CHn_ROUTER_CS0_MASK        0xFFFFFFFFu

/* CHn_ROUTER_ID1 Bit Fields */
#define CRM_CHn_ROUTER_ID1_ID_MASK     0xFFFFFFFFu
#define CRM_CHn_ROUTER_ID1_ID_SHIFT    0u
#define CRM_CHn_ROUTER_ID1_ID_WIDTH    32u
#define CRM_CHn_ROUTER_ID1_ID(x)       (((uint32_t)(((uint32_t)(x))<<CRM_CHn_ROUTER_ID1_ID_SHIFT))&CRM_CHn_ROUTER_ID1_ID_MASK)
/* CH0_ROUTER_ID1 Reg Mask */
#define CRM_CHn_ROUTER_ID1_MASK        0xFFFFFFFFu

/* CHn_ROUTER_CS1 Bit Fields */
#define CRM_CHn_ROUTER_CS1_CS_MASK     0xFFFFFFFFu
#define CRM_CHn_ROUTER_CS1_CS_SHIFT    0u
#define CRM_CHn_ROUTER_CS1_CS_WIDTH    32u
#define CRM_CHn_ROUTER_CS1_CS(x)       (((uint32_t)(((uint32_t)(x))<<CRM_CHn_ROUTER_CS1_CS_SHIFT))&CRM_CHn_ROUTER_CS1_CS_MASK)
/* CH0_ROUTER_CS1 Reg Mask */
#define CRM_CHn_ROUTER_CS1_MASK        0xFFFFFFFFu

/* CHn_MATCH_MASK Bit Fields */
#define CRM_CHn_MATCH_MASK_MSK_MASK    0xFFFFFFFFu
#define CRM_CHn_MATCH_MASK_MSK_SHIFT   0u
#define CRM_CHn_MATCH_MASK_MSK_WIDTH   32u
#define CRM_CHn_MATCH_MASK_MSK(x)      (((uint32_t)(((uint32_t)(x))<<CRM_CHn_MATCH_MASK_MSK_SHIFT))&CRM_CHn_MATCH_MASK_MSK_MASK)
/* CH0_MATCH_MASK Reg Mask */
#define CRM_CHn_MATCH_MASK_MASK        0xFFFFFFFFu

/* CHn_MAP_ID Bit Fields */
#define CRM_CHn_MAP_ID_ID_MASK         0xFFFFFFFFu
#define CRM_CHn_MAP_ID_ID_SHIFT        0u
#define CRM_CHn_MAP_ID_ID_WIDTH        32u
#define CRM_CHn_MAP_ID_ID(x)           (((uint32_t)(((uint32_t)(x))<<CRM_CHn_MAP_ID_ID_SHIFT))&CRM_CHn_MAP_ID_ID_MASK)
/* CH0_MAP_ID Reg Mask */
#define CRM_CHn_MAP_ID_MASK            0xFFFFFFFFu

/* CHn_MAP_CS Bit Fields */
#define CRM_CHn_MAP_CS_CS_MASK         0xFFFFFFFFu
#define CRM_CHn_MAP_CS_CS_SHIFT        0u
#define CRM_CHn_MAP_CS_CS_WIDTH        32u
#define CRM_CHn_MAP_CS_CS(x)           (((uint32_t)(((uint32_t)(x))<<CRM_CHn_MAP_CS_CS_SHIFT))&CRM_CHn_MAP_CS_CS_MASK)
/* CH0_MAP_CS Reg Mask */
#define CRM_CHn_MAP_CS_MASK            0xFFFFFFFFu

/* CANR_IEN Bit Fields */
#define CRM_CANR_IEN_MAP_MULTI_IE_MASK 0x80000000u
#define CRM_CANR_IEN_MAP_MULTI_IE_SHIFT 31u
#define CRM_CANR_IEN_MAP_MULTI_IE_WIDTH 1u
#define CRM_CANR_IEN_MAP_MULTI_IE(x)   (((uint32_t)(((uint32_t)(x))<<CRM_CANR_IEN_MAP_MULTI_IE_SHIFT))&CRM_CANR_IEN_MAP_MULTI_IE_MASK)
#define CRM_CANR_IEN_MAP_NONE_IE_MASK  0x40000000u
#define CRM_CANR_IEN_MAP_NONE_IE_SHIFT 30u
#define CRM_CANR_IEN_MAP_NONE_IE_WIDTH 1u
#define CRM_CANR_IEN_MAP_NONE_IE(x)    (((uint32_t)(((uint32_t)(x))<<CRM_CANR_IEN_MAP_NONE_IE_SHIFT))&CRM_CANR_IEN_MAP_NONE_IE_MASK)
#define CRM_CANR_IEN_MAP_DONE_IE_MASK  0xF0000u
#define CRM_CANR_IEN_MAP_DONE_IE_SHIFT 16u
#define CRM_CANR_IEN_MAP_DONE_IE_WIDTH 4u
#define CRM_CANR_IEN_MAP_DONE_IE(x)    (((uint32_t)(((uint32_t)(x))<<CRM_CANR_IEN_MAP_DONE_IE_SHIFT))&CRM_CANR_IEN_MAP_DONE_IE_MASK)
#define CRM_CANR_IEN_BUSY_IE_MASK      0xF00u
#define CRM_CANR_IEN_BUSY_IE_SHIFT     8u
#define CRM_CANR_IEN_BUSY_IE_WIDTH     4u
#define CRM_CANR_IEN_BUSY_IE(x)        (((uint32_t)(((uint32_t)(x))<<CRM_CANR_IEN_BUSY_IE_SHIFT))&CRM_CANR_IEN_BUSY_IE_MASK)
#define CRM_CANR_IEN_MAP_SELF_IE_MASK  0xFu
#define CRM_CANR_IEN_MAP_SELF_IE_SHIFT 0u
#define CRM_CANR_IEN_MAP_SELF_IE_WIDTH 4u
#define CRM_CANR_IEN_MAP_SELF_IE(x)    (((uint32_t)(((uint32_t)(x))<<CRM_CANR_IEN_MAP_SELF_IE_SHIFT))&CRM_CANR_IEN_MAP_SELF_IE_MASK)
/* CANR_IEN Reg Mask */
#define CRM_CANR_IEN_MASK              0xC00F0F0Fu

/* CANR_STATUS Bit Fields */
#define CRM_CANR_STATUS_MAP_MULTI_FLAG_MASK 0x80000000u
#define CRM_CANR_STATUS_MAP_MULTI_FLAG_SHIFT 31u
#define CRM_CANR_STATUS_MAP_MULTI_FLAG_WIDTH 1u
#define CRM_CANR_STATUS_MAP_MULTI_FLAG(x) (((uint32_t)(((uint32_t)(x))<<CRM_CANR_STATUS_MAP_MULTI_FLAG_SHIFT))&CRM_CANR_STATUS_MAP_MULTI_FLAG_MASK)
#define CRM_CANR_STATUS_MAP_NONE_FLAG_MASK 0x40000000u
#define CRM_CANR_STATUS_MAP_NONE_FLAG_SHIFT 30u
#define CRM_CANR_STATUS_MAP_NONE_FLAG_WIDTH 1u
#define CRM_CANR_STATUS_MAP_NONE_FLAG(x) (((uint32_t)(((uint32_t)(x))<<CRM_CANR_STATUS_MAP_NONE_FLAG_SHIFT))&CRM_CANR_STATUS_MAP_NONE_FLAG_MASK)
#define CRM_CANR_STATUS_MAP_DONE_FLAG_MASK 0xF0000u
#define CRM_CANR_STATUS_MAP_DONE_FLAG_SHIFT 16u
#define CRM_CANR_STATUS_MAP_DONE_FLAG_WIDTH 4u
#define CRM_CANR_STATUS_MAP_DONE_FLAG(x) (((uint32_t)(((uint32_t)(x))<<CRM_CANR_STATUS_MAP_DONE_FLAG_SHIFT))&CRM_CANR_STATUS_MAP_DONE_FLAG_MASK)
#define CRM_CANR_STATUS_BUSY_FLAG_MASK 0xF00u
#define CRM_CANR_STATUS_BUSY_FLAG_SHIFT 8u
#define CRM_CANR_STATUS_BUSY_FLAG_WIDTH 4u
#define CRM_CANR_STATUS_BUSY_FLAG(x)   (((uint32_t)(((uint32_t)(x))<<CRM_CANR_STATUS_BUSY_FLAG_SHIFT))&CRM_CANR_STATUS_BUSY_FLAG_MASK)
#define CRM_CANR_STATUS_MAP_SELF_FLAG_MASK 0xFu
#define CRM_CANR_STATUS_MAP_SELF_FLAG_SHIFT 0u
#define CRM_CANR_STATUS_MAP_SELF_FLAG_WIDTH 4u
#define CRM_CANR_STATUS_MAP_SELF_FLAG(x) (((uint32_t)(((uint32_t)(x))<<CRM_CANR_STATUS_MAP_SELF_FLAG_SHIFT))&CRM_CANR_STATUS_MAP_SELF_FLAG_MASK)
/* CANR_STATUS Reg Mask */
#define CRM_CANR_STATUS_MASK           0xC00F0F0Fu

/* CANR_CTRL Bit Fields */
#define CRM_CANR_CTRL_CH_EN_MASK       0xFu
#define CRM_CANR_CTRL_CH_EN_SHIFT      0u
#define CRM_CANR_CTRL_CH_EN_WIDTH      4u
#define CRM_CANR_CTRL_CH_EN(x)         (((uint32_t)(((uint32_t)(x))<<CRM_CANR_CTRL_CH_EN_SHIFT))&CRM_CANR_CTRL_CH_EN_MASK)
/* CANR_CTRL Reg Mask */
#define CRM_CANR_CTRL_MASK             0x0000000Fu


/*!
 * @}
 */ /* end of group CRM_Register_Masks */

/*!
 * @}
 */ /* end of group CRM_Peripheral_Access_Layer */

#endif
