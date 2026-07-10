/**
 * @file module_driver_fcuart.h
 * @author Flagchip
 * @brief FCUart driver type definition and API
 * @version 2.0.0
 * @date 2024-08-20
 *
 * SDK Version: 2.6.0
 *

 * @copyright Copyright (c) 2020-2024 Flagchip Semiconductors Co., Ltd.
 *
 */

/* ********************************************************************************
   *   Revision History:
   *
   *   Version     Date          Initials      CR#          Descriptions
   *   ---------   ----------    ------------  ----------   ---------------
   *   0.1.0       2023-12-15    Flagchip055   N/A          First version for FC7300
   *   2.0.0       2024-10-12    Flagchip112   N/A          Change version and release
   ******************************************************************************** */

#ifndef _DRIVER_MODULE_DRIVER_FCUART_H_
#define _DRIVER_MODULE_DRIVER_FCUART_H_

#include "HwA_fcuart.h"

#if FCUART_INSTANCE_COUNT > 0U

/**
 * @addtogroup module_driver_fcuart
 * @{
 */

/**
 * @name  FCUART API Service IDs
 * @brief Defines the service IDs for the FCUART module, which are used to identify different functions or services provided by the FCUART layer.
 *        These IDs are utilized when communicating with the FCUART module, enabling calls to or responses from various functions.
 * 
 * @{
 */
#define FCUART_INIT_ID                0U            /**< Initialization ID, used to initialize the FCUART module. */
#define FCUART_DEINIT_ID              1U            /**< Deinitialization ID, used to deinitialize the FCUART module. */
#define FCUART_SET_INTERRUPT_ID       2U            /**< Interrupt setting ID, used to set the interrupt status of the FCUART module. */
#define FCUART_SET_WAKEUP_ID          3U            /**< Wakeup ID, used to wake up the FCUART module. */
#define FCUART_GET_INTERRUPT_ID       4U            /**< Interrupt status ID, used to get the interrupt status of the FCUART module. */
#define FCUART_START_RECEIVE_ID       5U            /**< Receive start ID, used to start receiving data from the FCUART module. */
#define FCUART_ASSIGN_TXINTRRUPT_ID   6U            /**< Transmit interrupt assignment ID, used to assign the interrupt for transmitting data. */
#define FCUART_START_TRANSMIT_ID      7U            /**< Transmit start ID, used to start transmitting data from the FCUART module. */
#define FCUART_TRANSMIT_ID            8U            /**< Transmit data ID, used to transmit data to the FCUART module. */
#define FCUART_PRINTF_ID              9U            /**< Printf ID, used to print formatted data to the FCUART module. */
#define FCUART_GET_SATTUS_ID          10U           /**< Status get ID, used to get the status of the FCUART module. */
#define FCUART_RECEIVE_POLLING_ID     11U           /**< Receive polling ID, used to poll for received data from the FCUART module. */
#define FCUART_ERROR_POLLING_ID       12U           /**< Error polling ID, used to poll for errors in the FCUART module. */
#define FCUART_SET_LOOPMODE_ID        13U           /**< Loopback mode setting ID, used to set the loopback mode of the FCUART module. */
#define FCUART_STOP_RECEIVE_ID        14U           /**< Receive stop ID, used to stop receiving data from the FCUART module. */
#define FCUART_STOP_TRANSMIT_ID       15U           /**< Transmit stop ID, used to stop transmitting data from the FCUART module. */
#define FCUART_SENDDATA_9BITS         16U           /**< Send data with 9 bits ID, used to send data with 9 bits to the FCUART module. */
#define FCUART_GETDATA_9BITS          17U           /**< Receive data with 9 bits ID, used to receive data with 9 bits from the FCUART module. */
#define FCUART_SENDDATA_10BITS        18U           /**< Send data with 10 bits ID, used to send data with 10 bits to the FCUART module. */
#define FCUART_GETDATA_10BITS         19U           /**< Receive data with 10 bits ID, used to receive data with 10 bits from the FCUART module. */
#define FCUART_SETBITMODEANDPARITY    20U           /**< Set bit mode and parity ID, used to set the bit mode and parity of the FCUART module. */
/** @}*/

/**
 * @name  FCUART Dev Error Code
 * @brief Error Code of calling FCUART apis
 *
 * @{
 */
#define FCUART_E_PARAM_INSTANCE               0x01U         /**< FCUART_E_PARAM_INSTANCE means instance parameter is invalid */
#define FCUART_E_PARAM_ERROR_STATE            0x02U         /**< FCUART_E_PARAM_ERROR_STATE means error state parameter is invalid */
#define FCUART_E_PARAM_POINTER                0x03U         /**< FCUART_E_PARAM_POINTER means pointer parameter is invalid */
/** @}*/

#define FCUART_FIFO_DEPTH          16U

/**
 * @name  Special_Characters Special Characters
 * @brief Special characters used in UART communication.
 * 
 * @{
 */
#define ESCAPE_CHARACTER   (char)0x5c       /**< Escape character */
#define ENTER              (uint8_t)0x0d    /**< Enter character */
#define NEW_LINE           (uint8_t)0x0a    /**< New line character */
#define SPACE              (uint8_t)0x20    /**< Space character */
#define FLOAT_ZERO         0.00000001       /**< Floating point zero */
/** @}*/

/**
 * @brief Define the type of integer representation for UART printing.
 * 
 */
typedef enum
{
    UART_PRINT_RADIX_BIN = 2U,
    UART_PRINT_RADIX_OCT = 8U,
    UART_PRINT_RADIX_DEC = 10U,
    UART_PRINT_RADIX_HEX = 16U
} UART_PrintIntType;

/**
 * @brief FCUART Operation Sequence
 *
 */
typedef enum
{
    FCUART_SEQUENCE_VAR_NOINIT,       /**< FCUART_SEQUENCE_DEINIT means fcuart variables data is not initialed                       */
    FCUART_SEQUENCE_DEINIT,           /**< FCUART_SEQUENCE_DEINIT means fcuart driver is not initialed                               */
    FCUART_SEQUENCE_NOTSTART_RECEIVE, /**< FCUART_SEQUENCE_NOTSTART_RECEIVE means fcuart driver initialed and write/erase is allowed */
    FCUART_SEQUENCE_START_RECEIVE     /**< FCUART_SEQUENCE_START_RECEIVE means fcuart driver started received                        */
} FCUART_SequenceType;

/**
 * @brief FCUART error status
 *
 */
typedef enum
{
    FCUART_ERROR_OK               = 0x00U,    /**< FCUART_ERROR_OK means no error                                      */
    FCUART_ERROR_INVALID_VERSION  = 0x01U,    /**< FCUART_ERROR_INVALID_VERSION means version is not same */
    FCUART_ERROR_FAILED           = 0x02U,    /**< FCUART_ERROR_FAILED means operation is failed                       */
    FCUART_ERROR_INVALID_PARAM    = 0x04U,    /**< FCUART_ERROR_INVALID_PARAM means parameters are invalid             */
    FCUART_ERROR_INVALID_SIZE     = 0x08U,    /**< FCUART_ERROR_INVALID_SIZE means size is invalid                     */
    FCUART_ERROR_INVALID_SEQUENCE = 0x10U,    /**< FCUART_ERROR_INVALID_SEQUENCE means sequence is error               */
    FCUART_ERROR_TIMEOUT          = 0x20U,    /**< FCUART_ERROR_TIMEOUT means operation is timeout                     */
}FCUART_ErrorTypeEnum;

/**
 * @brief UART fifo receive idle character number
 */
typedef enum
{
    FCUART_FIFO_RX_IDLE_DISABLE = 0U,       /**< The UART receive FIFO is idle and character reception is disabled. */
    FCUART_FIFO_RX_IDLE_CHARACTER_1,        /**< The UART receive FIFO is idle with a 1 character reception setting. */
    FCUART_FIFO_RX_IDLE_CHARACTER_2,        /**< The UART receive FIFO is idle with a 2 character reception setting. */
    FCUART_FIFO_RX_IDLE_CHARACTER_4,        /**< The UART receive FIFO is idle with a 4 character reception setting. */
    FCUART_FIFO_RX_IDLE_CHARACTER_8,        /**< The UART receive FIFO is idle with a 8 character reception setting. */
    FCUART_FIFO_RX_IDLE_CHARACTER_16,       /**< The UART receive FIFO is idle with a 16 character reception setting. */
    FCUART_FIFO_RX_IDLE_CHARACTER_32,       /**< The UART receive FIFO is idle with a 32 character reception setting. */
    FCUART_FIFO_RX_IDLE_CHARACTER_64        /**< The UART receive FIFO is idle with a 64 character reception setting. */
} FCUART_Fifo_RxIdleCharNumType;


/**
 * @brief UART CTRL register interrupt
 *
 */
typedef enum
{
    FCUART_INT_CTRL_ORIE = FCUART_CTRL_ORIE_MASK,       /**< FCUART_INT_CTRL_ORIE means Overrun Interrupt Enable */
    FCUART_INT_CTRL_NEIE = FCUART_CTRL_NEIE_MASK,       /**< FCUART_INT_CTRL_NEIE means Noise Error Interrupt Enable */
    FCUART_INT_CTRL_FEIE = FCUART_CTRL_FEIE_MASK,       /**< FCUART_INT_CTRL_FEIE means Framing Error Interrupt Enable */
    FCUART_INT_CTRL_PEIE = FCUART_CTRL_PEIE_MASK,       /**< FCUART_INT_CTRL_PEIE means Parity Error Interrupt Enable */
    FCUART_INT_CTRL_TIE  = FCUART_CTRL_TIE_MASK,        /**< FCUART_INT_CTRL_TIE means Transmit Interrupt Enable */
    FCUART_INT_CTRL_TCIE = FCUART_CTRL_TCIE_MASK,       /**< FCUART_INT_CTRL_TCIE means Transmit Complete Interrupt Enable */
    FCUART_INT_CTRL_RIE  = FCUART_CTRL_RIE_MASK,        /**< FCUART_INT_CTRL_RIE means Receive Interrupt Enable */
    FCUART_INT_CTRL_IIE  = FCUART_CTRL_IIE_MASK,        /**< FCUART_INT_CTRL_IIE means Idle Line Interrupt Enable*/
    FCUART_INT_CTRL_TE   = FCUART_CTRL_TE_MASK,         /**< FCUART_INT_CTRL_TE means Transmit Enable */
    FCUART_INT_CTRL_RE   = FCUART_CTRL_RE_MASK,         /**< FCUART_INT_CTRL_RE means Receive Enable */
    FCUART_INT_CTRL_M0IE = FCUART_CTRL_M0IE_MASK,       /**< FCUART_INT_CTRL_M0IE means Multi-Processor Mode Enable */
    FCUART_INT_CTRL_M1IE = FCUART_CTRL_M1IE_MASK        /**< FCUART_INT_CTRL_M1IE means Multi-Processor Mode Enable */
} FCUART_InterruptSel;

/**
 * @brief UART error status type
 *
 */
typedef enum
{
    FCUART_ERROR_NONE = 0x0000U,   /**< FCUART_ERROR_NONE    No Error,                            */
    FCUART_ERROR_RORF = 0x0001U,   /**< FCUART_ERROR_RORF    Receiver Overrun Flag,               */
    FCUART_ERROR_NF   = 0x0002U,   /**< FCUART_ERROR_NF      Noise Flag,                          */
    FCUART_ERROR_FEF  = 0x0004U,   /**< FCUART_ERROR_FEF     Frame Error Flag,                    */
    FCUART_ERROR_PEF  = 0x0008U,   /**< FCUART_ERROR_PEF     Parity Error Flag,                   */
    FCUART_ERROR_RPEF = 0x0010U,   /**< FCUART_ERROR_RPEF    Receive Data Parity Error Flag,      */
    FCUART_ERROR_TPEF = 0x0020U    /**< FCUART_ERROR_TPEF    Transmit Data Parity Error Flag,     */
}FCUART_ErrorStatusType;

/**
 * @brief UART idle character number
 */
typedef enum
{
    FCUART_IDLE_CHARCTER_1  = 0U,
    FCUART_IDLE_CHARCTER_2,
    FCUART_IDLE_CHARCTER_4,
    FCUART_IDLE_CHARCTER_8,
    FCUART_IDLE_CHARCTER_16,
    FCUART_IDLE_CHARCTER_32,
    FCUART_IDLE_CHARCTER_64,
    FCUART_IDLE_CHARCTER_128
} FCUART_IdleCharNumType;

/**
 * @brief UART idle type
 */
typedef enum
{
    FCUART_START_AFTER_STARTBIT = 0U,
    FCUART_START_AFTER_STOPBIT
} FCUART_IdleStartType;

/**
 * @brief UART transmit and receive data define
 *
 */
typedef struct
{
    uint8_t*            pDatas;         /**< Data buffer point, Must be initial with a array address */
    uint32_t            u32DataLen;     /**< data length                                             */
}FCUART_DataType;

/**
 * @brief The structure of the UART processing handle
 *
 */
typedef struct _FCUART_HandleType
{
    FCUART_InstanceType eInstance;         /**< UART instance*/
    uint8_t _aligned[3];                   /**< Alignment bytes */

    struct
    {
        FCUART_DataType *tFCUART_RxMsg;                                                                         /**< check every pUart instance whether is used */
        FCUART_DataType *tFCUART_TxMsg;                                                                         /**< pUart instance transfer buffer */
        uint32_t u32FCUART_TransmitTimeout;                                                                     /**< check every pUart instance transmit timeout */
        FCUART_SequenceType eCurrentSequence;                                                                   /**< sequence table */
        uint8_t u8FCUART_UartUsed;                                                                              /**< check every pUart instance whether is used */
        void (*pFCUART_ErrorNotify)(struct _FCUART_HandleType *pUartHandle, uint32_t u32Error);                 /**< error notify callback function point */
        void (*pFCUART_RxNotify)(struct _FCUART_HandleType *pUartHandle, FCUART_DataType *pTxRxCfg);            /**< receive notify callback function point */
        void (*pFCUART_TxEmptyNotify)(struct _FCUART_HandleType *pUartHandle, FCUART_DataType *pTxRxCfg);       /**< Transfer empty notify callback function point */
        void (*pFCUART_TxCompleteNotify)(struct _FCUART_HandleType *pUartHandle, FCUART_DataType *pTxRxCfg);    /**< Transfer complete notify callback function point */
        void (*pFCUART_IdleNotify)(struct _FCUART_HandleType *pUartHandle);                                     /**< Idle notify callback function point */
    } tStatus;
} FCUART_HandleType;

/**
 * @brief FCUART error interrupt callback function type
 * 
 * This function type is used to define the callback function that is invoked when an error occurs in the FCUART module.
 * It combines the error status with the FCUART_ErrorStatusType to notify the user of specific error conditions.
 * This design allows users to perform custom operations when errors occur, enhancing the flexibility and error handling capabilities of UART communication.
 * 
 * @param pUartHandle Pointer to the UART handle structure containing configuration and state information.
 * @param u32Error The error code indicating the specific error that occurred.
 */
typedef void (*FCUART_ErrorInterrupt_CallBackType)(FCUART_HandleType *pUartHandle, uint32_t u32Error);

/**
 * @brief FCUART transmit/receive interrupt callback function type
 * 
 * This function type is used to define the callback function that is invoked when a transmission or reception operation completes.
 * It provides the UART handle and data configuration parameters to allow the user to process the transmitted or received data.
 * 
 * @param pUartHandle Pointer to the UART handle structure containing configuration and state information.
 * @param pTxRxCfg Pointer to the configuration structure for the transmitted or received data.
 */
typedef void (*FCUART_TxRxInterrupt_CallBackType)(FCUART_HandleType *pUartHandle, FCUART_DataType *pTxRxCfg);

/**
 * @brief FCUART idle interrupt callback function type
 * 
 * This function type is used to define the callback function that is invoked when the UART module enters an idle state.
 * It can be used to perform any necessary actions when there is no ongoing transmission or reception.
 * 
 * @param pUartHandle Pointer to the UART handle structure containing configuration and state information.
 */
typedef void (*FCUART_IdleInterrupt_CallBackType)(FCUART_HandleType *pUartHandle);

/**
 * @brief UART callback functions data define
 *
 */
typedef struct
{
    bool                                bEnErrorInterrupt;  /**< enable error interrupt                      */
    FCUART_ErrorInterrupt_CallBackType  pErrorNotify;       /**< error interrupt callback function address   */
    bool                                bEnRxInterrupt;     /**< enable receive interrupt                    */
    FCUART_DataType                     *pRxBuf;            /**< receive interrupt message buffer            */
    FCUART_TxRxInterrupt_CallBackType   pRxNotify;          /**< receive interrupt callback function address */
    bool                                bEnTxInterrupt;     /**< enable receive interrupt                    */
    FCUART_DataType                     *pTxBuf;            /**< transfer interrupt message buffer            */
    FCUART_TxRxInterrupt_CallBackType   pTxEmptyNotify;     /**< transfer empty interrupt callback function address */
    FCUART_TxRxInterrupt_CallBackType   pTxCompleteNotify;  /**< transfer complete interrupt callback function address */
    bool                                bEnIdleInterrupt;   /**< enable idle interrupt */
    FCUART_IdleInterrupt_CallBackType   pIdleNotify;        /**< idle interrupt callback function address */
} FCUART_InterruptType;

/**
 * @brief UART initial data define
 *
 */
typedef struct
{
    FCUART_InterruptType           tInterruptCfg;      /**<interrupt configuration parameter                        */
    uint32_t                       u32ClkSrcHz;        /**< module clock hz                                         */
    FCUART_BitModeType             eBitMode;           /**< 8bits or 9bits                                          */
    bool                           bParityEnable;      /**< Parity Enable=1                                         */
    FCUART_ParityType              eParityType;        /**< parity type                                             */
    FCUART_StopBitNumType          eStopBit;           /**< stop bit num;                                           */
    bool                           bEnTxFifo;          /**< Enable Tx FIFO, 16 data words depth                     */
    uint8_t                        u8TxFifoWaterMark;  /**< Tx FIFO,When FIFO/buffer number equal or less than this
                                                            an interrupt or a DMA request will be generated         */
    bool                           bEnRxFifo;          /**< Enable Rx FIFO, 16 data words depth                     */
    uint8_t                        u8RxFifoWaterMark;  /**< Rx FIFO, When FIFO/buffer number greater than this
                                                            an interrupt or a DMA request will be generated         */
    FCUART_Fifo_RxIdleCharNumType  eFifoRxIdleCharNum; /**< Fifo Rx idle character number   */
    bool                           bEnTxEmptyDma;      /**< Enable transmit DMA                                     */
    bool                           bEnRxFullDma;       /**< Enable receiver full DMA                                */
    bool                           bEnRxIdleDma;       /**< Enable Rx Idle DMA                                      */
    FCUART_IdleCharNumType         eIdleCharNum;       /**< Idle character number                                   */
    FCUART_IdleStartType           eIdleStart;         /**< Idle character start type                               */
    uint32_t                       u32Baudrate;        /**< normal baud-rate                                        */
    uint32_t                       u32TransmitTimeout; /**< transmit timeout tick, default 3000U                    */
} FCUART_InitType;

/**
 * @brief UART WakeUp functions data define
 *
 */
typedef struct
{
    bool      bEnWakeup;           /**< enable wake-up   */
    uint32_t  u32WakeUpData;       /**< wake-up data  */

} FCUART_WakeupType;

/** @brief Errortype Define as uint8 */
typedef uint8_t  FCUART_ErrorType;

/**
 * @brief Initial UART variables Memory
 *
 */
void FCUART_InitStructure(FCUART_HandleType *pUartHandle);

/**
 * @brief This Function is used to initial UART instance
 *
 * @param pUartHandle The structure of the UART processing handle
 * @param pInitCfg contains clock, baud-rate, Bit Mode, parity and so on.
 * @return FCUART_ERROR_OK is ok, others are not ok
 */
FCUART_ErrorType FCUART_Init(FCUART_HandleType *pUartHandle, FCUART_InitType *pInitCfg);

/**
 * @brief This Function is used to de-initial UART instance
 *
 * @param pUartHandle The structure of the UART processing handle
 */
void FCUART_DeInit(FCUART_HandleType *pUartHandle);

/**
 * @brief This Function is used to set UART WakeUp
 *
 * @param pUartHandle The structure of the UART processing handle
 * @param pWakeupCfg contains UART wake-up parameters
 */
void FCUART_SetWakeup(FCUART_HandleType *pUartHandle, FCUART_WakeupType *pWakeupCfg);

/**
 * @brief This Function is used to start receiving
 *
 * @param pUartHandle The structure of the UART processing handle
 */
void FCUART_StartReceive(FCUART_HandleType *pUartHandle);

/**
 * @brief This Function is used to stop receiving
 *
 * @param pUartHandle The structure of the UART processing handle
 */
void FCUART_StopReceive(FCUART_HandleType *pUartHandle);

/**
 * @brief This Function is used to start transmit
 *
 * @param pUartHandle The structure of the UART processing handle
 */
void FCUART_StartTransmit(FCUART_HandleType *pUartHandle);

/**
 * @brief This Function is used to stop transmitting
 *
 * @param pUartHandle The structure of the UART processing handle
 */
void FCUART_StopTransmit(FCUART_HandleType *pUartHandle);

/**
 * @brief This Function is used to transmit UART data
 *
 * @param pUartHandle The structure of the UART processing handle
 * @param pUartData contains UART data and length
 * @return FCUART_ERROR_OK is ok, others are not ok
 */
FCUART_ErrorType FCUART_Transmit(FCUART_HandleType *pUartHandle, FCUART_DataType *pUartData);


/**
 * @brief This Function is used to print ASCII char from UART
 *
 * @param pUartHandle The structure of the UART processing handle
 * @param fmt is char format
 * @return FCUART_ERROR_OK is ok, others are not ok
 */
FCUART_ErrorType FCUART_Printf(FCUART_HandleType *pUartHandle, char* fmt,...);

/**
 * @brief Get Stat Flag
 *
 * @param pUartHandle The structure of the UART processing handle
 * @param eStatusType  stat type
 * @return FCUART STAT status flag
 */
uint32_t FCUART_GetStatus(FCUART_HandleType *pUartHandle, FCUART_StatType eStatusType);

/**
 * @brief This Function is used to receive data when polling (not used when rx interrupt enabled)
 *
 * @param pUartHandle The structure of the UART processing handle
 * @param pRxMsg is data buffer address, and pDatas need to be initialed with external buffer
 * @return FCUART_ERROR_OK is ok, others are not ok
 */
FCUART_ErrorType FCUART_Receive_Polling(FCUART_HandleType *pUartHandle, FCUART_DataType *pRxMsg);


/**
 * @brief This Function is used to get error when polling (not used when error interrupt enabled)
 *
 * @param pUartHandle The structure of the UART processing handle
 * @param pErrorValue is error value
 */
void FCUART_Error_Polling(FCUART_HandleType *pUartHandle, uint32_t *pErrorValue);

/**
 * @brief This Function is used to enable fcuart loop mode
 *
 * @param pUartHandle The structure of the UART processing handle
 * @param bStatus  enable/disable status of loop mode
 *
 */
void FCUART_SetLoopMode(FCUART_HandleType *pUartHandle, bool bStatus);

/**
 * @brief This Function is used to deal with FCUART TxRx interrupt
 *
 * @param pUartHandle The structure of the UART processing handle
 *
 */
void FCUARTN_RxTx_IRQHandler(FCUART_HandleType *pUartHandle);

/**
 * @brief This Function is used to send 9 bits data
 *
 * @param pUartHandle The structure of the UART processing handle
 * @param u16Data  data to send
 *
 */
void FCUART_SendData_9Bits(FCUART_HandleType *pUartHandle, uint16_t u16Data);

/**
 * @brief This Function is used to Get 9 bits data
 *
 * @param pUartHandle The structure of the UART processing handle
 * @param pData  pointer to data
 *
 */
void FCUART_GetData_9Bits(FCUART_HandleType *pUartHandle, uint16_t *pData);

/**
 * @brief This Function is used to send 10 bits data
 *
 * @param pUartHandle The structure of the UART processing handle
 * @param u16Data  data to send
 *
 */
void FCUART_SendData_10Bits(FCUART_HandleType *pUartHandle, uint16_t u16Data);

/**
 * @brief This Function is used to Get 10 bits data
 *
 * @param pUartHandle The structure of the UART processing handle
 * @param pData  pointer to data
 *
 */
void FCUART_GetData_10Bits(FCUART_HandleType *pUartHandle, uint16_t *pData);

/**
 * @brief This Function is used to set bit mode,parity and stop bit
 *
 * @param pUartHandle The structure of the UART processing handle
 * @param eBitMode  bit mode
 * @param eStopBit stop bit number
 * @param eParityType parity type
 * @param bParityEnable if enable parity
 */
void FCUART_SetBitModeAndParity( FCUART_HandleType     *pUartHandle,
                                             FCUART_BitModeType    eBitMode,
                                             FCUART_StopBitNumType eStopBit,
                                             FCUART_ParityType     eParityType,
                                             bool                  bParityEnable
                                             );

/**
 * @brief This Function is used to Get current interrupt mode
 *
 * @param pUartHandle The structure of the UART processing handle
 * @param u32Data  Interrupt type to get
 * @return true/false
 *
 */
bool FCUART_GetInterruptMode(FCUART_HandleType *pUartHandle, uint32_t u32Data);

/**
 * @brief This Function is used to assign data to send through interrupt
 *
 * @param pUartHandle The structure of the UART processing handle
 * @param pData  data pointer
 * @param u32Length data length to send
 *
 */
void FCUART_AssignTxInterruptData(FCUART_HandleType *pUartHandle, uint8_t * pData, uint32_t u32Length);

/** @}*/
#endif

#endif
