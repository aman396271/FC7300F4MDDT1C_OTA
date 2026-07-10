/**
 * @file module_driver_ospi.h
 * @author Flagchip
 * @brief OSPI driver type definition and API
 * @version 2.0.0
 * @date 2024-08-20
 *
 * SDK Version: 2.6.0
 *

 * @copyright Copyright (c) 2020-2024 Flagchip Semiconductors Co., Ltd.
 *
 * @details
 */
/* ********************************************************************************
   *   Revision History:
   *
   *   Version     Date          Initials      CR#          Descriptions
   *   ---------   ----------    ------------  ----------   ---------------
   *   0.1.0       2023-12-15    Flagchip100   N/A          First version for FC7300
   *   2.0.0       2024-10-12    Flagchip122   N/A          Change version and release
   ******************************************************************************** */

#ifndef _DRIVER_MODULE_DRIVER_OSPI_H_
#define _DRIVER_MODULE_DRIVER_OSPI_H_

#include "HwA_ospi.h"

#if OSPI_INSTANCE_COUNT > 0U

/**
 * @addtogroup module_driver_ospi
 * @{
 */

#if defined(__cplusplus)
extern "C" {
#endif

/**
 * @name  Ospi API Service IDs
 * @brief These macros define the command IDs used for communication with the on-chip OSPI interface.
 *        Each ID corresponds to a specific operation that can be performed via the OSPI interface.
 *
 * @{
 */
#define OSPI_INIT_ID                        ((uint8) 0x00u)
#define OSPI_SET_FLASHCFG_ID                ((uint8) 0x01u)
#define OSPI_UPDATE_LUT_ID                  ((uint8) 0x02u)
#define OSPI_WRITE_FIFO_ID                  ((uint8) 0x03u)
#define OSPI_READ_FIFO_ID                   ((uint8) 0x04u)
#define OSPI_TRANSFER_BLOCKING_ID           ((uint8) 0x05u)
#define OSPI_TRANSFER_NONBLOCKING_ID        ((uint8) 0x06u)
/** @}*/

/**
 * @name  Ospi Dev Error Code
 * @brief Error Code of calling OSPI apis
 * @{
 */
#define OSPI_E_PARAM_POINTER            ((uint8)0x01u)
#define OSPI_E_PARAM_INVALID            ((uint8)0x02u)
/** @}*/

/**
 * @name    IO configurations IO configurations for the OSPI interface
 * @brief   IO configurations for the OSPI interface
 * @{
 */
#define SINGLE_IO               0x00    /**< Single I/O */
#define DUAL_IO                 0x01    /**< Dual I/O */
#define QUAD_IO                 0x02    /**< Quad I/O */
#define OCTAL_IO                0x03    /**< Octal I/O */
/** @}*/

/**
 * @name    OSPI command_set OSPI command set definitions
 * @brief   OSPI command set definitions
 * @{
 */
#define OSPI_CMD_STOP         0x0   /**< Stop command */
#define OSPI_CFG_DRV          0x1   /**< Configure drive strength */
#define OSPI_CFG_ADDR         0x2   /**< Configure address */
#define OSPI_CMD_DUMMY        0x3   /**< Configure dummy cycles */
#define OSPI_CFG_MODE8        0x4   /**< Configure mode 8 */
#define OSPI_CFG_MODE2        0x5   /**< Configure mode 2 */
#define OSPI_CFG_MODE4        0x6   /**< Configure mode 4 */
#define OSPI_READ_DRV         0x7   /**< Configure read drive strength */
#define OSPI_WRITE_DRV        0x8   /**< Configure write drive strength */
#define OSPI_CMD_END          0x9   /**< End command */
#define OSPI_CFG_ADDR_DDR     0xA   /**< Configure address DDR */
#define OSPI_CFG_MODE8_DDR    0xB   /**< Configure mode 8 DDR */
#define OSPI_CFG_MODE2_DDR    0xC   /**< Configure mode 2 DDR */
#define OSPI_CFG_MODE4_DDR    0xD   /**< Configure mode 4 DDR */
#define OSPI_READ_DRV_DDR     0xE   /**< Configure read drive strength DDR */
#define OSPI_WRITE_DRV_DDR    0xF   /**< Configure write drive strength DDR */
#define OSPI_CFG_DRV_DDR      0x11  /**< Configure drive strength DDR */
#define OSPI_CFG_CADDR        0x12  /**< Configure CADDR */
#define OSPI_CFG_CADDR_DDR    0x13  /**< Configure CADDR DDR */
/** @}*/


#define OSPI_FIFO_DEPTH_MAX         16      /**< OSPI FIFO depth */
#define OSPI_ONE_TRANSFER_SIZE_MAX  64      /**< OSPI one transfer size */

/**
 * @brief Status returned by OSPI APIs
 *
 */
typedef enum {
    OSPI_STATUS_SUCCESS = 0,    /*!< API execute successfully */
    OSPI_STATUS_PARAM_ERR,      /*!< parameter error */
    OSPI_STATUS_TIMEOUT
} OSPI_StatusType;

typedef enum
{
    OSPI_OPERATION_COMMAND, /*!< OSPI operation: Only command, both TX and Rx buffer are ignored. */
    OSPI_OPERATION_CONFIG,  /*!< OSPI operation: Configure device mode, the TX fifo size is fixed in LUT. */
    OSPI_OPERATION_READ,    /*!< OSPI operation: Read, only Rx Buffer is effective. */
    OSPI_OPERATION_WRITE,   /*!< OSPI operation: Read, only Tx Buffer is effective. */
} OSPI_OperationType;

/**
 * @brief The basic configuration option for the OSPI peripheral
 *
 */
typedef struct
{
    bool bDdrEn;
    OSPI_DqsSrcSelType   eDqsSrcSel;
    OSPI_ClockDivideType eClkDivider;
    OSPI_ClockMuxType    eClkMux;
    OSPI_EndianType      eEndian;
} OSPI_ConfigType;

/**
 * @brief Define the structure for OSPI device configuration.
 * 
 * This structure is used to configure the parameters of the OSPI (OctoSPI) interface.
 */
typedef struct
{
    uint32_t  u32FlashAddress;
    uint32_t  u32FlashTopAddress;
    uint8_t   u8FlashColAddressSpace;
    uint8_t   u8WordAddressable;
    uint8_t   u8CsHoldTime;
    uint8_t   u8CsSetupTime;
    uint8_t   u8DelayLine;
} OSPI_DeviceConfigType;

/**
 * @brief FlexSPI Transfer structure definition.
 *
 * This structure defines the parameters required for a FlexSPI transfer operation.
 *
 *
 */
typedef struct _flexspi_transfer
{
    uint32_t           deviceAddress;  /*!< Operation device address. */
    OSPI_OperationType cmdType;        /*!< Execution command type. */
    uint8_t            seqIndex;       /*!< Sequence ID for command. */
    uint32_t *         data;           /*!< Data buffer. */
    uint16_t           dataSize;       /*!< Data size in bytes. */
} OSPI_TransferType;

#define OSPI_LUT_SEQ(cmd0, pad0, op0, cmd1, pad1, op1)                                                              \
    (OSPI_LUT_INSTR0_CMD_NAME(cmd0) | OSPI_LUT_INSTR0_PAD_NUM(pad0) | OSPI_LUT_INSTR0_DRV_CMD(op0) | \
     OSPI_LUT_INSTR1_CMD_NAME(cmd1) | OSPI_LUT_INSTR1_PAD_NUM(pad1) | OSPI_LUT_INSTR1_DRV_CMD(op1))

/********* Global Functions ************/
/**
 * @brief Initialize OSPI configuration
 *
 * @param base OSPI peripheral base address
 * @param pConfig the basic configurations of the OSPI
 */
void OSPI_Init(OSPI_Type *base, const OSPI_ConfigType *const pConfig);

/**
 * @brief Get OSPI configuration
 *
 * @param config the basic configurations of the OSPI
 */
void OSPI_GetDefaultConfig(OSPI_ConfigType *config);

/**
 * @brief De-initialize the OSPI 
 *
 * @param base OSPI peripheral base address
 */
void OSPI_DeInit(OSPI_Type *base);

/**
 * @brief OSPI Config Flash Parameter
 *
 * @param base OSPI peripheral base address
 * @param pConfig the basic configurations of the OSPI
 */
void OSPI_FlashConfig(OSPI_Type *base, OSPI_DeviceConfigType *pConfig);

/**
 * @brief OSPI Config LUT
 *
 * @param base OSPI peripheral base address
 * @param index index to be written
 * @param cmd Command sequence array
 * @param count Number of sequences
 *
 */
void OSPI_UpdateLUT(OSPI_Type *base, uint32_t index, const uint32_t *cmd, uint32_t count);

/**
 * @brief OSPI Wait bus command transaction done
 *
 * @param base OSPI peripheral base address
 * @return OSPI_StatusType whether the operation is successfully
 */
OSPI_StatusType OSPI_Wait_Cmd_Done(OSPI_Type *base);

/**
 * @brief OSPI Wait bus command transaction done
 *
 * @param base OSPI peripheral base address
 * @return OSPI_StatusType whether the operation is successfully
 */
OSPI_StatusType OSPI_Wait_Bus_Idle(OSPI_Type *base);

/**
 * @brief OSPI write fifo，fifo size is 16words.
 *
 * @param base OSPI peripheral base address
 * @param u8SeqId the cmd id location in lut.
 * @param pBuf the write buffer start address.
 * @param u8Size fifo size to be written.
 * @return OSPI_StatusType whether the operation is successfully
 */
OSPI_StatusType OSPI_Write_Fifo(OSPI_Type *base, uint8_t u8SeqId, uint32_t *pBuf, uint16_t u16Size);

/**
 * @brief OSPI read fifo，fifo size is 16words.
 *
 * @param base OSPI peripheral base address
 * @param u8SeqId the cmd id location in lut.
 * @param pBuf the read buffer start address.
 * @param u8Size fifo size to be read.
 * @return OSPI_StatusType whether the operation is successfully
 */
OSPI_StatusType OSPI_Read_Fifo(OSPI_Type *base, uint8_t u8SeqId, uint32_t *pBuf, uint16_t u16Size);

/**
 * @brief OSPI blocking transfer data.
 *
 * @param base OSPI peripheral base address
 * @param xfer pointer to the transfer structure
 * @return OSPI_StatusType whether the operation is successfully
 */
OSPI_StatusType OSPI_TransferBlocking(OSPI_Type *base, OSPI_TransferType *xfer);

/**
 * @brief OSPI non-blocking transfer data.
 *
 * @param base OSPI peripheral base address
 * @param xfer pointer to the transfer structure
 * @return OSPI_StatusType whether the operation is successfully
 */
OSPI_StatusType OSPI_TransferNonBlocking(OSPI_Type *base, OSPI_TransferType *xfer);

/*!
 * @brief Gets OSPI IP rx fifo address for DMA transfer.
 *
 * @param base OSPI peripheral base address.
 * @return The rx fifo address.
 */
static inline uint32_t OSPI_GetRxFifoAddress(OSPI_Type *base)
{
    return OSPI_HWA_GetRFDRAddr(base);
}

/*!
 * @brief Enables or disables OSPI IP Rx FIFO DMA requests.
 *
 * @param base OSPI peripheral base address.
 * @param u8Enable Enable flag for receive DMA request. Pass true for enable, false for disable.
 */
static inline void OSPI_EnableRxDMA(OSPI_Type *base, uint8_t u8Enable)
{
    OSPI_HWA_SetRxDMA(base, u8Enable);
}

/*!
 * @brief Set OSPI Rx watermark value.
 *
 * @param base OSPI peripheral base address.
 * @param u8Value Rx watermark value.
 */
static inline void OSPI_SetRxWatermark(OSPI_Type *base, uint8_t u8Value)
{
    OSPI_HWA_SetRxFifoWaterMark(base, u8Value);
}

/*!
 * @brief Gets OSPI IP tx fifo address for DMA transfer.
 *
 * @param base OSPI peripheral base address.
 * @return The tx fifo address.
 */
static inline uint32_t OSPI_GetTxFifoAddress(OSPI_Type *base)
{
    return OSPI_HWA_GetTFDRAddr(base);
}

/*!
 * @brief Enables or disables OSPI IP Tx FIFO DMA requests.
 *
 * @param base OSPI peripheral base address.
 * @param u8Enable Enable flag for transmit DMA request. Pass true for enable, false for disable.
 */
static inline void OSPI_EnableTxDMA(OSPI_Type *base, uint8_t u8Enable)
{
    OSPI_HWA_SetTxDMA(base, u8Enable);
}

/*!
 * @brief Set OSPI Tx watermark value.
 *
 * @param base OSPI peripheral base address.
 * @param u8Value Tx watermark value.
 */
static inline void OSPI_SetTxWatermark(OSPI_Type *base, uint8_t u8Value)
{
    OSPI_HWA_SetTxFifoWaterMark(base, u8Value);
}

/**
 * @brief OSPI interrupt driver handler
 *
 * @param base OSPI peripheral base address
 */
void OSPI_DriverIRQHandler(OSPI_Type *base);

#if defined(__cplusplus)
}
#endif

/** @} */

#endif /* #if OSPI_INSTANCE_COUNT > 0U */
#endif /* _DRIVER_MODULE_DRIVER_OSPI_H_ */
