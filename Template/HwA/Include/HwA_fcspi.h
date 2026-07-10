
#ifndef _HWA_FCSPI_H_
#define _HWA_FCSPI_H_

#include "device_header.h"

#define FCSPI_SET_BIT(REG, BIT)     ((REG) |= (BIT))

#define FCSPI_CLEAR_BIT(REG, BIT)   ((REG) &= ~(BIT))

#define FCSPI_READ_BIT(REG, BIT)    ((REG) & (BIT))

#define FCSPI_CLEAR_REG(REG)        ((REG) = (0x0))

#define FCSPI_WRITE_REG(REG, VAL)   ((REG) = (VAL))

#define FCSPI_READ_REG(REG)         ((REG))

#define FCSPI_MODIFY_REG(REG, CLEARMASK, SETMASK)  FCSPI_WRITE_REG((REG), (((FCSPI_READ_REG(REG)) & (~(CLEARMASK))) | (SETMASK)))




#if FCSPI_INSTANCE_COUNT > 0U

/**
 * @brief FCSPI Mode type, master or slave.
 */
typedef enum {
    FCSPI_MODE_SLAVE  = 0,
    FCSPI_MODE_MASTER = 1
} FCSPI_MasterSlaveModeType;

typedef enum {
    FCSPI_PCS_0 = 0, /**< Transfer using pcs_0 */
    FCSPI_PCS_1 = 1, /**< Transfer using pcs_1 */
    FCSPI_PCS_2 = 2, /**< Transfer using pcs_2 */
    FCSPI_PCS_3 = 3  /**< Transfer using pcs_3 */
} FCSPI_PcsSelType;

typedef enum {
    FCSPI_PCS_ACTIVE_LOW  = 0, /**< pcs use low level to select external device */
    FCSPI_PCS_ACTIVE_HIGH = 1  /**< pcs use high level to select external device */
} FCSPI_PcsPolarityType;

typedef enum {
    FCSPI_SIN_INPUT_SOUT_OUTPUT = 0, /**< SIN is configured as input pin and SOUT is configured as output pin */ 
    FCSPI_SIN_INPUT_OUTPUT      = 1, /**< SIN is configured as input and output pin */ 
    FCSPI_SOUT_INPUT_OUTPUT     = 2, /**< SOUT is configured as input and output pin */ 
    FCSPI_SOUT_INPUT_SIN_OUTPUT = 3  /**< SOUT is configured as input pin and SIN is configured as output pin */ 
} FCSPI_PinConfigType;

typedef enum {
    FCSPI_OUTPUT_RETAIN_LAST = 0, /**< SIN is configured as input pin and SOUT is configured as output pin */ 
    FCSPI_OUTPUT_TRISTATE    = 1
} FCSPI_OutputConfigType;

typedef enum {
    FCSPI_TRANSFER_WIDTH_1_BIT = 0, /**< 1-bit shift at a time, data out on SDO, in on SDI (normal mode) */
    FCSPI_TRANSFER_WIDTH_2_BIT = 1, /**< 2-bits shift out on SDO/SDI and in on SDO/SDI */
    FCSPI_TRANSFER_WIDTH_4_BIT = 2  /**< 4-bits shift out on SDO/SDI/PCS[3:2] and in on SDO/SDI/PCS[3:2] */
} FCSPI_TransferWidthType;

typedef enum
{
    FCSPI_MSB_FIRST = 0, /**< most significant bit first handle, from msb to lsb */
    FCSPI_LSB_FIRST = 1  /**< least significant bit first handle, from lsb to msb */
} FCSPI_DataFirstBitType;

typedef enum
{
    FCSPI_PRESCALE_DIV_1   = 0, /**< most significant bit first handle, from msb to lsb */
    FCSPI_PRESCALE_DIV_2   = 1,
    FCSPI_PRESCALE_DIV_4   = 2,
    FCSPI_PRESCALE_DIV_8   = 3,
    FCSPI_PRESCALE_DIV_16  = 4,
    FCSPI_PRESCALE_DIV_32  = 5,
    FCSPI_PRESCALE_DIV_64  = 6,
    FCSPI_PRESCALE_DIV_128 = 7
} FCSPI_PrescaleType;

typedef enum
{
    FCSPI_SCK_SAMPLE_FIRST_EDGE  = 0, /**< sample on first edge of sck active polarity, change on second */
    FCSPI_SCK_SAMPLE_SECOND_EDGE = 1  /**< sample on second edge of sck active polarity, change on first */
} FCSPI_SckPhaseType;

typedef enum
{
    FCSPI_SCK_IDLE_LOW  = 0, /**< sck is high level when active (idles low). */
    FCSPI_SCK_IDLE_HIGH = 1  /**< sck is low level when active (idles high). */
} FCSPI_SckPolarityType;

/********* Local inline function ************/

/**
 * @brief Manipulate CTRL.M_EN to enable/disable FCSPI.
 *
 * @param pFCSPI  FCSPI instance, e.g. FCSPI0, FCSPI1.
 */
LOCAL_INLINE void FCSPI_HWA_EnableModule(FCSPI_Type *pFCSPI, bool enable)
{
    enable ? FCSPI_WRITE_REG(pFCSPI->CTRL, 1) : FCSPI_WRITE_REG(pFCSPI->CTRL, 0);
}

LOCAL_INLINE void FCSPI_HWA_EnableDebugMode(FCSPI_Type *pFCSPI, bool enable)
{
    enable ? FCSPI_SET_BIT(pFCSPI->CTRL, FCSPI_CTRL_DBG_EN_MASK) : FCSPI_CLEAR_BIT(pFCSPI->CTRL, FCSPI_CTRL_DBG_EN_MASK);
}

LOCAL_INLINE bool FCSPI_HWA_IsEnabled(FCSPI_Type *pFCSPI)
{
   return FCSPI_READ_BIT(pFCSPI->CTRL, FCSPI_CTRL_M_EN_MASK);
}

LOCAL_INLINE void FCSPI_HWA_ResetRxFIFO(FCSPI_Type *pFCSPI)
{
    FCSPI_SET_BIT(pFCSPI->CTRL, FCSPI_CTRL_RST_RF_MASK);
}

LOCAL_INLINE void FCSPI_HWA_ResetTxFIFO(FCSPI_Type *pFCSPI)
{
    FCSPI_SET_BIT(pFCSPI->CTRL, FCSPI_CTRL_RST_TF_MASK);
}

/**
 * @brief Set the FCSPI INT_EN register value for enable or disable some interrupts.
 *
 * @param pFCSPI  FCSPI instance, e.g. FCSPI0, FCSPI1.
 * @param u32Value the value write to the register.
 */
LOCAL_INLINE void FCSPI_HWA_EnableInterrupts(FCSPI_Type *pFCSPI, uint32_t IntsMask, bool enable)
{
    if (true == enable)
    {
        FCSPI_SET_BIT(pFCSPI->INT_EN, IntsMask);
    }
    else
    {
        FCSPI_CLEAR_BIT(pFCSPI->INT_EN, IntsMask);
    }
}

LOCAL_INLINE bool FCSPI_HWA_IsEnabledInterrupt(FCSPI_Type *pFCSPI, uint32_t IntMask)
{
    return FCSPI_READ_BIT(pFCSPI->INT_EN, IntMask);
}

/**
 * @brief Enable or disable the DMA feature by setting the FCSPI DMA_EN register value.
 *
 * @param pFCSPI  FCSPI instance, e.g. FCSPI0, FCSPI1.
 * @param u32Value the value write to the register.
 */
LOCAL_INLINE void FCSPI_HWA_EnableRxDMA(FCSPI_Type *pFCSPI, bool enable)
{
    enable ? FCSPI_SET_BIT(pFCSPI->DMA_EN, FCSPI_DMA_EN_RFDE_MASK) : FCSPI_CLEAR_BIT(pFCSPI->DMA_EN, FCSPI_DMA_EN_RFDE_MASK);
}

LOCAL_INLINE bool FCSPI_HWA_IsEnabledRxDMA(FCSPI_Type *pFCSPI)
{
    return FCSPI_READ_BIT(pFCSPI->DMA_EN, FCSPI_DMA_EN_RFDE_MASK);
}

LOCAL_INLINE void FCSPI_HWA_EnableTxDMA(FCSPI_Type *pFCSPI, bool enable)
{
    enable ? FCSPI_SET_BIT(pFCSPI->DMA_EN, FCSPI_DMA_EN_TFDE_MASK) : FCSPI_CLEAR_BIT(pFCSPI->DMA_EN, FCSPI_DMA_EN_TFDE_MASK);
}

LOCAL_INLINE bool FCSPI_HWA_IsEnabledTxDMA(FCSPI_Type *pFCSPI)
{
    return FCSPI_READ_BIT(pFCSPI->DMA_EN, FCSPI_DMA_EN_TFDE_MASK);
}

/**
 * @brief Software reset FCSPI. This operation can be done regardless of whether the module is enabled or not(CTRL.M_EN).
 *
 * @param pFCSPI  FCSPI instance, e.g. FCSPI0, FCSPI1.
 */
LOCAL_INLINE void FCSPI_HWA_SoftwareReset(FCSPI_Type *pFCSPI)
{
	/* Disable DMA before software reset */
	FCSPI_HWA_EnableRxDMA(pFCSPI, false);
	FCSPI_HWA_EnableTxDMA(pFCSPI, false);
	/* Disable all SPI interrupt before software reset */
	FCSPI_HWA_EnableInterrupts(pFCSPI, FCSPI_INT_EN_MASK, false);
	/* Disable module before software reset */
	FCSPI_HWA_EnableModule(pFCSPI, false);
	/* software reset */
    FCSPI_SET_BIT(pFCSPI->CTRL, FCSPI_CTRL_SW_RST_MASK);
    FCSPI_CLEAR_BIT(pFCSPI->CTRL, FCSPI_CTRL_SW_RST_MASK);
}

/**
 * @brief Set the FCSPI to master mode.
 *
 * @param pFCSPI  FCSPI instance, e.g. FCSPI0, FCSPI1.
 */
LOCAL_INLINE void FCSPI_HWA_SetMasterMode(FCSPI_Type *pFCSPI)
{
    FCSPI_SET_BIT(pFCSPI->CFG1, FCSPI_CFG1_MASTER_MASK);
}

/**
 * @brief Set FCSPI to slave mode.
 *
 * @param pFCSPI  FCSPI instance, e.g. FCSPI0, FCSPI1.
 */
LOCAL_INLINE void FCSPI_HWA_SetSlaveMode(FCSPI_Type *pFCSPI)
{
    FCSPI_CLEAR_BIT(pFCSPI->CFG1, FCSPI_CFG1_MASTER_MASK);
}

/**
 * @brief Check the current mode status, master or slave.
 *
 * @param pFCSPI  FCSPI instance, e.g. FCSPI0, FCSPI1.
 * @return the mode type of FCSPI, FCSPI_MODE_MASTER or FCSPI_MODE_SLAVE
 */
LOCAL_INLINE FCSPI_MasterSlaveModeType FCSPI_HWA_GetMode(FCSPI_Type *pFCSPI)
{
    return (FCSPI_MasterSlaveModeType)(FCSPI_READ_BIT(pFCSPI->CFG1, FCSPI_CFG1_MASTER_MASK));
}

LOCAL_INLINE void FCSPI_HWA_ClearStatus(FCSPI_Type *pFCSPI, uint32_t u32StatusMask)
{
    FCSPI_WRITE_REG(pFCSPI->STATUS, u32StatusMask);
}

/**
 * @brief Clear FCSPI STATUS register for certain function.
 *
 * @param pFCSPI  FCSPI instance, e.g. FCSPI0, FCSPI1.
 * @param u32Value the value write to the register.
 */
LOCAL_INLINE uint32_t FCSPI_HWA_GetStatus(FCSPI_Type *pFCSPI, uint32_t u32FlagBitMask)
{
    return FCSPI_READ_BIT(pFCSPI->STATUS, u32FlagBitMask);
}

LOCAL_INLINE void FCSPI_HWA_EnableSckLoopback(FCSPI_Type *pFCSPI, bool enable)
{
    enable ? FCSPI_SET_BIT(pFCSPI->CFG1, FCSPI_CFG1_SCK_LB_MASK) : FCSPI_CLEAR_BIT(pFCSPI->CFG1, FCSPI_CFG1_SCK_LB_MASK);
}

LOCAL_INLINE void FCSPI_HWA_EnableInternalPcs(FCSPI_Type *pFCSPI, bool enable)
{
    enable ? FCSPI_SET_BIT(pFCSPI->CFG1, FCSPI_CFG1_INT_PCS_MASK) : FCSPI_CLEAR_BIT(pFCSPI->CFG1, FCSPI_CFG1_INT_PCS_MASK);
}

LOCAL_INLINE void FCSPI_HWA_SetPcsPolarity(FCSPI_Type *pFCSPI, FCSPI_PcsSelType PCSn, FCSPI_PcsPolarityType PcsPolarity)
{
    FCSPI_MODIFY_REG(pFCSPI->CFG1, FCSPI_CFG1_PCS_POL_MASK, (uint32_t)(PcsPolarity << PCSn) << FCSPI_CFG1_PCS_POL_SHIFT);
}

LOCAL_INLINE void FCSPI_HWA_SetPinConfig(FCSPI_Type *pFCSPI, FCSPI_PinConfigType PinCfg)
{
    FCSPI_MODIFY_REG(pFCSPI->CFG1, FCSPI_CFG1_PIN_CFG_MASK, (uint32_t)PinCfg << FCSPI_CFG1_PIN_CFG_SHIFT);
}

LOCAL_INLINE void FCSPI_HWA_SetOutputConfig(FCSPI_Type *pFCSPI, FCSPI_OutputConfigType OutputCfg)
{
    if (FCSPI_OUTPUT_RETAIN_LAST == OutputCfg) {
        FCSPI_CLEAR_BIT(pFCSPI->CFG1, FCSPI_CFG1_OUT_CFG_MASK);
    } else {
        FCSPI_SET_BIT(pFCSPI->CFG1, FCSPI_CFG1_OUT_CFG_MASK);
    }
}

LOCAL_INLINE void FCSPI_HWA_SetPcsConfig(FCSPI_Type *pFCSPI, bool Is4bitMode)
{
    Is4bitMode ? FCSPI_SET_BIT(pFCSPI->CFG1, FCSPI_CFG1_PCS_CFG_MASK) : FCSPI_CLEAR_BIT(pFCSPI->CFG1, FCSPI_CFG1_PCS_CFG_MASK);
}

LOCAL_INLINE void FCSPI_HWA_SetSCKDIV(FCSPI_Type *pFCSPI, uint8  u8Value)
{
    FCSPI_MODIFY_REG(pFCSPI->CLK_CFG, FCSPI_CLK_CFG_SCKDIV_MASK, (uint32_t)u8Value << FCSPI_CLK_CFG_SCKDIV_SHIFT);
}

LOCAL_INLINE void FCSPI_HWA_SetDelayPCSPCS(FCSPI_Type *pFCSPI, uint8  u8Value)
{
    FCSPI_MODIFY_REG(pFCSPI->CLK_CFG, FCSPI_CLK_CFG_PCSPCS_MASK, (uint32_t)u8Value << FCSPI_CLK_CFG_PCSPCS_SHIFT);
}

LOCAL_INLINE void FCSPI_HWA_SetDelayPCSSCK(FCSPI_Type *pFCSPI, uint8  u8Value)
{
    FCSPI_MODIFY_REG(pFCSPI->CLK_CFG, FCSPI_CLK_CFG_PCSSCK_MASK, (uint32_t)u8Value << FCSPI_CLK_CFG_PCSSCK_SHIFT);
}

LOCAL_INLINE void FCSPI_HWA_SetDelaySCKPCS(FCSPI_Type *pFCSPI, uint8  u8Value)
{
    FCSPI_MODIFY_REG(pFCSPI->CLK_CFG, FCSPI_CLK_CFG_SCKPCS_MASK, (uint32_t)u8Value << FCSPI_CLK_CFG_SCKPCS_SHIFT);
}

LOCAL_INLINE void FCSPI_HWA_SetWatermarkTx(FCSPI_Type *pFCSPI, uint8  u8Value)
{
    FCSPI_MODIFY_REG(pFCSPI->FIFO_WTM, FCSPI_FIFO_WTM_TXWATER_MASK, (uint32_t)u8Value & FCSPI_FIFO_WTM_TXWATER_MASK);
}

LOCAL_INLINE void FCSPI_HWA_SetWatermarkRx(FCSPI_Type *pFCSPI, uint8  u8Value)
{
    FCSPI_MODIFY_REG(pFCSPI->FIFO_WTM, FCSPI_FIFO_WTM_RXWATER_MASK,
    		         (uint32_t)(u8Value << FCSPI_FIFO_WTM_RXWATER_SHIFT) & FCSPI_FIFO_WTM_RXWATER_MASK);
}

LOCAL_INLINE uint32 FCSPI_HWA_GetTxFIFOCnt(FCSPI_Type *pFCSPI)
{
    return (FCSPI_READ_BIT(pFCSPI->FIFO_STATUS, FCSPI_FIFO_STATUS_TXCNT_MASK));
}

LOCAL_INLINE uint32 FCSPI_HWA_GetRxFIFOCnt(FCSPI_Type *pFCSPI)
{
    return (FCSPI_READ_BIT(pFCSPI->FIFO_STATUS, FCSPI_FIFO_STATUS_RXCNT_MASK) >> FCSPI_FIFO_STATUS_RXCNT_SHIFT);
}

LOCAL_INLINE void FCSPI_HWA_SetFrameSize(FCSPI_Type *pFCSPI, uint16 FrameSize)
{
    FCSPI_MODIFY_REG(pFCSPI->TR_CTRL, FCSPI_TR_CTRL_FRM_SZ_MASK, FrameSize - 1u);
}

LOCAL_INLINE void FCSPI_HWA_SetTransferWidth(FCSPI_Type *pFCSPI, FCSPI_TransferWidthType Width)
{
    FCSPI_MODIFY_REG(pFCSPI->TR_CTRL, FCSPI_TR_CTRL_WIDTH_MASK, ((uint32_t)Width << FCSPI_TR_CTRL_WIDTH_SHIFT) & FCSPI_TR_CTRL_WIDTH_MASK);
}

LOCAL_INLINE void FCSPI_HWA_EnableTxMask(FCSPI_Type *pFCSPI, bool enable)
{
    enable ? FCSPI_SET_BIT(pFCSPI->TR_CTRL, FCSPI_TR_CTRL_TX_MSK_MASK) : FCSPI_CLEAR_BIT(pFCSPI->TR_CTRL, FCSPI_TR_CTRL_TX_MSK_MASK);
}

LOCAL_INLINE void FCSPI_HWA_EnableRxMask(FCSPI_Type *pFCSPI, bool enable)
{
    enable ? FCSPI_SET_BIT(pFCSPI->TR_CTRL, FCSPI_TR_CTRL_RX_MSK_MASK) : FCSPI_CLEAR_BIT(pFCSPI->TR_CTRL, FCSPI_TR_CTRL_RX_MSK_MASK);
}

LOCAL_INLINE void FCSPI_HWA_EnableCTGO(FCSPI_Type *pFCSPI, bool enable)
{
    enable ? FCSPI_SET_BIT(pFCSPI->TR_CTRL, FCSPI_TR_CTRL_CT_GO_MASK) : FCSPI_CLEAR_BIT(pFCSPI->TR_CTRL, FCSPI_TR_CTRL_CT_GO_MASK);
}

LOCAL_INLINE void FCSPI_HWA_EnableCTEN(FCSPI_Type *pFCSPI, bool enable)
{
    enable ? FCSPI_SET_BIT(pFCSPI->TR_CTRL, FCSPI_TR_CTRL_CT_EN_MASK) : FCSPI_CLEAR_BIT(pFCSPI->TR_CTRL, FCSPI_TR_CTRL_CT_EN_MASK);
}

LOCAL_INLINE void FCSPI_HWA_EnableByteSwap(FCSPI_Type *pFCSPI, bool enable)
{
    enable ? FCSPI_SET_BIT(pFCSPI->TR_CTRL, FCSPI_TR_CTRL_BYSW_MASK) : FCSPI_CLEAR_BIT(pFCSPI->TR_CTRL, FCSPI_TR_CTRL_BYSW_MASK);
}

LOCAL_INLINE void FCSPI_HWA_SetDataFirstBit(FCSPI_Type *pFCSPI, FCSPI_DataFirstBitType eFirstBit)
{
    if (FCSPI_MSB_FIRST == eFirstBit) {
        FCSPI_CLEAR_BIT(pFCSPI->TR_CTRL, FCSPI_TR_CTRL_LSBF_MASK);
    } else {
        FCSPI_SET_BIT(pFCSPI->TR_CTRL, FCSPI_TR_CTRL_LSBF_MASK);
    }
}

LOCAL_INLINE void FCSPI_HWA_SelectPCS(FCSPI_Type *pFCSPI, FCSPI_PcsSelType PCSn)
{
    FCSPI_MODIFY_REG(pFCSPI->TR_CTRL, FCSPI_TR_CTRL_PCS_MASK, (uint32_t)PCSn << FCSPI_TR_CTRL_PCS_SHIFT);
}

LOCAL_INLINE void FCSPI_HWA_SetPrescale(FCSPI_Type *pFCSPI, FCSPI_PrescaleType PrescaleValue)
{
    FCSPI_MODIFY_REG(pFCSPI->TR_CTRL, FCSPI_TR_CTRL_PRESCALE_MASK, ((uint32_t)PrescaleValue << FCSPI_TR_CTRL_PRESCALE_SHIFT) & FCSPI_TR_CTRL_PRESCALE_MASK);
}

LOCAL_INLINE void FCSPI_HWA_SetSckPhase(FCSPI_Type *pFCSPI, FCSPI_SckPhaseType SckPhase)
{
    if (FCSPI_SCK_SAMPLE_FIRST_EDGE == SckPhase) {
        FCSPI_CLEAR_BIT(pFCSPI->TR_CTRL, FCSPI_TR_CTRL_SCK_PHA_MASK);
    } else {
        FCSPI_SET_BIT(pFCSPI->TR_CTRL, FCSPI_TR_CTRL_SCK_PHA_MASK);
    }
}

LOCAL_INLINE void FCSPI_HWA_SetSckPolarity(FCSPI_Type *pFCSPI, FCSPI_SckPolarityType SckPolarity)
{
    if (FCSPI_SCK_IDLE_LOW == SckPolarity) {
        FCSPI_CLEAR_BIT(pFCSPI->TR_CTRL, FCSPI_TR_CTRL_SCK_POL_MASK);
    } else {
        FCSPI_SET_BIT(pFCSPI->TR_CTRL, FCSPI_TR_CTRL_SCK_POL_MASK);
    }
}

LOCAL_INLINE void FCSPI_HWA_WriteTxData(FCSPI_Type *pFCSPI, uint32 TxData)
{
    FCSPI_WRITE_REG(pFCSPI->TX_DATA, TxData);
}

LOCAL_INLINE bool FCSPI_HWA_GetFirstDataFlag(FCSPI_Type *pFCSPI)
{
    return (bool)FCSPI_READ_BIT(pFCSPI->RX_STATUS, FCSPI_RX_STATUS_FD_MASK);
}

LOCAL_INLINE bool FCSPI_HWA_IsRxFIFOEmpty(FCSPI_Type *pFCSPI)
{
    return (bool)(FCSPI_READ_BIT(pFCSPI->RX_STATUS, FCSPI_RX_STATUS_RX_EMPTY_MASK));
}

LOCAL_INLINE uint32 FCSPI_HWA_ReadRxData(FCSPI_Type *pFCSPI)
{
    return FCSPI_READ_REG(pFCSPI->RX_DATA);
}

/** @}*/

#endif /* #if FCSPI_INSTANCE_COUNT > 0U */

#endif /* #ifndef _HWA_FCPIT_H_ */
