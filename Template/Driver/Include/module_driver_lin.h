/**
 * @file module_driver_lin.h
 * @author Flagchip
 * @brief LIN driver type definition and API
 * @version 2.0.0
 * @date 2024-08-23
 *
 * SDK Version: 2.6.0
 *

 * @copyright Copyright (c) 2024 Flagchip Semiconductors Co., Ltd.
 *
 */
/*********************************************************************************
*  Revision History:

*   Version     Date          Initials      CR#          Descriptions
*   ---------   ----------    ------------  ----------   ---------------
*   2.0.0       2024-08-23    Flagchip122   N/A          First version
*********************************************************************************/

#ifndef _DRIVER_MODULE_DRIVER_LIN_H_
#define _DRIVER_MODULE_DRIVER_LIN_H_

#include "HwA_fcuart.h"

#if FCUART_INSTANCE_COUNT > 0U

/**
 * @addtogroup module_driver_lin
 * @{
 */

#if defined(__cplusplus)
extern "C" {
#endif

/**
 * @name  LIN API Service IDs
 * @brief Defines the service IDs for the LIN API (used in development error reporting)
 * @{
 */
#define LIN_INIT_ID                             0U          /**< Initialize LIN instance */
#define LIN_DEINIT_ID                           1U          /**< De-initialize LIN instance */
#define LIN_GET_DEFAULT_CFG_ID                  2U          /**< Get default LIN configuration */
#define LIN_DRV_SEND_FRAME_ID                   3U          /**< Send LIN frame */
#define LIN_DRV_GOTO_SLEEP_ID                   4U          /**< Command LIN node to enter sleep mode */
#define LIN_DRV_GOTO_SLEEP_INTERNAL_ID          5U          /**< Internal sleep mode transition */
#define LIN_DRV_WAKEUP_ID                       6U          /**< Send wake-up signal to LIN bus */
#define LIN_DRV_WAKEUP_INTERNAL_ID              7U          /**< Internal wake-up mode transition */
#define LIN_DRV_GET_STATUS_ID                   8U          /**< Get current LIN node status */
#define LIN_DRV_ABORT_TRANSFER_ID               9U          /**< Abort LIN node transfer */
#define LIN_DRV_IRQ_HANDLE                      10U          /**< LIN interrupt service routine */
/** @}*/

/**
 * @name  LIN Dev Error Code
 * @brief Error codes for LIN API parameter validation
 * @{
 */
#define LIN_E_PARAM_INSTANCE               0x01U    /**< Invalid LIN hardware instance index */
#define LIN_E_PARAM_POINTER                0x02U    /**< NULL or invalid pointer parameter */
#define LIN_E_PARAM_ERROR_STATE            0x03U    /**< Node in invalid state for operation */
#define LIN_E_PARAM_ERROR_CALL             0x04U    /**< Invalid API call (e.g., slave node calling master-only API) */
/** @}*/

/**
 * @brief LIN API return status type
 */
typedef enum
{
    LIN_RET_SUCCESS     = 0x00U, /**< API executed successfully */
    LIN_RET_STATE_ERROR,         /**< API execution error (invalid node state) */
    LIN_RET_BUSY,                /**< Node is currently busy (e.g., transmitting) */
    LIN_RET_TIMEOUT,             /**< Operation timed out */
    LIN_RET_PARAM_ERROR,         /**< Invalid parameter provided */
    LIN_RET_NOT_INIT,            /**< LIN node has not been initialized */
    LIN_RET_USEED,               /**< LIN node is already in use */
    LIN_RET_NOT_START,           /**< LIN node has not been started */
    LIN_RET_UNSUPPORTED,         /**< Unsupported operation */
} LIN_ReturnType;

/**
 * @brief LIN node type (master or slave)
 */
typedef enum
{
    LIN_NODE_MASTER, /**< LIN Master node (initiates communication) */
    LIN_NODE_SLAVE,  /**< LIN Slave node (responds to master) */
} LIN_NodeType;

/**
 * @brief LIN event identifier types
 */
typedef enum
{
    LIN_NO_EVENT              = 0x00U,    /**< No event occurred */
    LIN_WAKEUP_SIGNAL,                  /**< Wake-up signal detected */
    LIN_RECV_BREAK_FIELD_OK,            /**< Break field received successfully */
    LIN_SYNC_ERROR,                     /**< Sync field validation failed */
    LIN_PID_ERROR,                      /**< PID validation failed */
    LIN_HEADER_OK,                      /**< Frame header received successfully */
    LIN_HEADER_ERROR,                   /**< Frame header reception failed */
    LIN_FRAME_ERROR,                    /**< Frame reception error */
    LIN_READBACK_ERROR,                 /**< Data readback mismatch */
    LIN_REPONSE_ERROR,                  /**< Response reception error */
    LIN_CHECKSUM_ERROR,                 /**< Checksum validation failed */
    LIN_TX_COMPLETED,                   /**< Transmission completed successfully */
    LIN_RX_COMPLETED,                   /**< Reception completed successfully */
    LIN_RX_OVERRUN,                     /**< RX buffer overrun occurred */
} LIN_EventIdType;

/**
 * @brief LIN frame processing state definitions (describes current frame processing phase)
 */
typedef enum
{
    LIN_FRAME_SLEEP_STATE          = 0x00U, /**< Frame processing in sleep state (no active communication) */
    LIN_FRAME_IDLE_STATE,                   /**< Frame processing idle (ready to start new transfer) */
    LIN_FRAME_BREAK_SEND_STATE,             /**< Sending break field (13-bit low signal) */
    LIN_FRAME_BREAK_RECV_STATE,             /**< Receiving break field (13-bit low signal) */
    LIN_FRAME_HEADER_SEND_STATE,            /**< Sending frame header (break + sync + PID) */
    LIN_FRAME_HEADER_RECV_STATE,            /**< Receiving frame header (break + sync + PID) */
    LIN_FRAME_RESPONSE_SEND_STATE,          /**< Sending frame response (data + checksum) */
    LIN_FRAME_RESPONSE_RECV_STATE,          /**< Receiving frame response (data + checksum) */
    LIN_FRAME_RESPONSE_SEND_OK_STATE,       /**< Response sent successfully (no errors detected) */
    LIN_FRAME_RESPONSE_RECV_OK_STATE,       /**< Response received successfully (no errors detected) */
} LIN_FrameStateType;

/**
 * @brief LIN node operational state definitions (describes overall node status)
 */
typedef enum
{
    LIN_NOT_OK              = 0x00U, /**< Node not initialized or in error state */
    LIN_TX_HEADER_OK,                 /**< Transmit header data ready for operation */
    LIN_TX_RESP_OK,                   /**< Transmit response data ready for operation */
    LIN_TX_HEADER_BUSY,               /**< Transmitting header  */
    LIN_TX_RESP_BUSY,                 /**< Transmitting response  */
    LIN_TX_HEADER_ERROR,              /**< Header transmission error occurred */
    LIN_TX_RESP_ERROR,                /**< Response transmission error occurred */
    LIN_RX_HEADER_OK,                 /**< Receive header data ready for operation */
    LIN_RX_RESP_OK,                   /**< Receive response ready for operation */
    LIN_RX_HEADER_BUSY,               /**< Receiving header */
    LIN_RX_RESP_BUSY,                 /**< Receiving response */
    LIN_RX_HEADER_ERROR,              /**< Header receive error occurred */
    LIN_RX_RESP_ERROR,                /**< Response receive error occurred */
    LIN_CALLBACK_ERROR,               /**< Expected callback not configured */
    LIN_CH_OPERATIONAL,               /**< Node in operational mode (active communication) */
    LIN_CH_SLEEP,                     /**< Node in sleep mode (low power) */
    LIN_CH_SLEEP_PENDING,             /**< Sleep mode transition pending (waiting for RX completion) */
} LIN_StatusType;

/**
 * @brief Callback function type to get time interval in microseconds
 * @param microseconds Pointer to store the time interval value (unit: microseconds)
 */
typedef void (*LIN_TimestampCallbackType)(uint64_t *microseconds);

/**
 * @brief Frame response types (specifies responsibility for frame response)
 * @details Determines if the node generates, receives, or ignores the frame response
 */
typedef enum
{
    LIN_FRAMERESPONSE_TX = 0,    /**< Response is generated by this node (transmit responsibility) */
    LIN_FRAMERESPONSE_RX,        /**< Response is received from another node (relevant to this node) */
    LIN_FRAMERESPONSE_IGNORE,    /**< Response is received from another node (irrelevant to this node) */
} LIN_FrameResponseType;

/**
 * @brief Checksum models for LIN frames
 * @details LIN protocol defines two checksum calculation methods:
 *          - Enhanced: Includes PID in checksum calculation
 *          - Classic: Excludes PID from checksum calculation
 */
typedef enum
{
    LIN_ENHANCED_CS = 0U,    /**< Enhanced checksum model (includes PID) */
    LIN_CLASSIC_CS,          /**< Classic checksum model (excludes PID) */
} LIN_FrameCsModelType;

/**
 * @brief Data length of LIN frame (number of data bytes in SDU)
 * @details Valid range: 0-8 bytes (per LIN protocol specification)
 */
typedef uint8 LIN_FrameDlType;

/**
 * @brief LIN protected identifier (PID) type
 * @details 8-bit value where bits 0-5 are the raw ID (0x00-0x3F), bits 6-7 are parity bits
 */
typedef uint8 LIN_FramePidType;

/**
 * @brief LIN Protocol Data Unit (PDU) structure
 * @details Contains all necessary information to process a LIN frame
 */
typedef struct
{
    LIN_FramePidType      Pid;     /**< LIN frame protected identifier (0x00-0x3F with parity) */
    LIN_FrameCsModelType  Cs;      /**< Checksum model to use (enhanced/classic) */
    LIN_FrameResponseType Drc;     /**< Response type (TX/RX/ignore) */
    LIN_FrameDlType       Dl;      /**< Data length (number of SDU bytes, 0-8) */
    uint8                *SduPtr;  /**< Pointer to SDU data buffer (must be >= Dl bytes) */
} LIN_PduType;

/**
 * @brief Baudrate configuration parameters
 * @details Contains hardware-specific settings for baudrate calculation
 */
typedef struct
{
    uint16_t u16OvrSamp;  /**< Oversampling ratio (number of samples per bit period) */
    uint16_t u16SBR;      /**< Baudrate scale factor (clock divider value) */
} LIN_BaudRateCfgType;

/**
 * @brief LIN driver callback function type
 * @param u8Lin LIN controller channel ID
 * @param event LIN event identifier (e.g., TX completed, RX error)
 * @param pdu Pointer to the processed Protocol Data Unit
 * @param checksum Pointer to the calculated/validated checksum value
 */
typedef void (*LIN_CallbackType)(uint8_t u8Lin, LIN_EventIdType event, LIN_PduType *pdu, uint8_t *checksum);

/**
 * @brief Runtime state of the LIN driver (maintained during operation)
 * @details Contains hardware context, current status, and temporary data buffers.
 *          Memory for this structure must be provided by the caller.
 */
typedef struct
{
    uint8_t               u8LinChannel;     /**< LIN controller channel ID */
    FCUART_Type          *base;             /**< Pointer to FCUART hardware instance (from HwA_fcuart.h) */
    __IO LIN_EventIdType  curEventId;       /**< Current LIN event ID (e.g., TX completed, RX error) */
    __IO LIN_FrameStateType curFrState;     /**< Current frame processing state (e.g., sending break field) */
    __IO LIN_StatusType   curChnState;      /**< Current channel operational state (e.g., operational, sleep) */
    uint8_t               sleepSignal;      /**< Transmit sleep signal flag */
    uint8_t               cntByte;          /**< Count of bytes transmitted/received in current frame */
    LIN_BaudRateCfgType   xferBrCfg;        /**< Baudrate configuration parameters (oversampling ratio and divider) */
    uint16_t              xferDlyCnt;       /**< Clock frequency division ratio (coreClkFreq / funcClkFreq) */
    uint8_t               xferBuff[8];      /**< Temporary buffer for frame data (max 8 bytes per LIN frame) */
    LIN_PduType           xferPdu;          /**< Current Protocol Data Unit (PID, checksum model, data pointer) */
    uint8_t               checkSum;         /**< Calculated/validated checksum byte for current frame */
    uint64_t              wakeupTime;       /**< Timestamp for wake-up signal detection (microseconds) */
} LIN_XferStateType;

/**
 * @brief LIN controller hardware configuration parameters
 * @details Contains initialization settings and user-provided callbacks.
 *          Memory for this structure must be provided by the caller.
 */
typedef struct
{
    LIN_XferStateType     xferState;        /**< Runtime state instance (driver internal state) */
    uint32_t              baudRate;         /**< LIN bus baudrate (default: 19200 bps) */
    uint32_t              funcClkFreq;      /**< LIN controller functional clock frequency (Hz) */
    uint32_t              coreClkFreq;      /**< LIN controller core clock frequency (Hz) */
    LIN_TimestampCallbackType timeCallback; /**< Callback to get time intervals (unit: microseconds) */
    LIN_NodeType          nodeMode;         /**< Node role (LIN_NODE_MASTER or LIN_NODE_SLAVE) */
    uint8_t               u8LinHwIndex;     /**< Hardware instance index (0 to FCUART_INSTANCE_COUNT-1) */
    LIN_CallbackType      callback;         /**< Event callback (invoked on frame completion/error) */
} LIN_ConfigType;

/**
 * @brief LIN driver handle structure (entry point for all API operations)
 * @details Connects configuration, runtime state, and hardware instance.
 */
typedef struct _LIN_HandleType
{
    uint8_t               u8LinChannel;     /**< LIN controller channel ID (matches u8LinHwIndex in LIN_ConfigType) */
    LIN_XferStateType    *pXfer;            /**< Pointer to LIN transfer state structure */
    LIN_ConfigType       *pCfg;             /**< Pointer to LIN configuration structure */
} LIN_HandleType;

/**
 * @name    API declaration for LIN driver.
 * @brief   LIN driver APIs
 * @{
 */

/**
 * @brief Initialize LIN controller instance.
 * @param pLinHandle Pointer to LIN handle structure (stores configuration and state)
 * @param pConfig Pointer to LIN configuration structure (contains node mode, baudrate, etc.)
 * @return Operation status:
 *         - LIN_RET_SUCCESS: Initialization succeeded
 *         - LIN_RET_ERROR: Baudrate configuration failed
 * @details Configures hardware registers and initializes transfer state:
 *          1. Validates input pointers and hardware index
 *          2. Resets hardware to default state
 *          3. Calculates and sets baudrate configuration (oversampling ratio and divider)
 *          4. Configures FIFO (TX/RX enable, depth) and watermark levels
 *          5. Sets control register (error interrupts, parity, mode)
 *          6. Initializes transfer state (buffer pointer, frame/channel state)
 *          7. Enables receive active interrupt and starts LIN controller
 */
LIN_ReturnType LIN_DrvInit(LIN_HandleType *pLinHandle, LIN_ConfigType *pConfig);

/**
 * @brief De-initialize LIN controller instance.
 * @param pLinHandle Pointer to LIN handle structure
 * @details
 * - Resets FCUART hardware to default state
 * - Clears internal pointers in LIN handle (pCfg, pXfer)
 * - Disables interrupts and stops TX/RX transfer
 * @note This function does not return a status; error checking is done via LIN_DEV_ERROR_REPORT
 */
void LIN_DrvDeInit(LIN_HandleType *pLinHandle);

/**
 * @brief Initialize default LIN node configuration parameters.
 * @param eNodeMode LIN node mode (LIN_NODE_MASTER or LIN_NODE_SLAVE)
 * @param pConfig Pointer to configuration structure to be initialized
 * @details Sets default values for:
 *          - nodeMode: Input node mode (master/slave)
 *          - baudRate: Default baudrate (19200 bps)
 *          - timeCallback: NULL (user must set if needed)
 *          - xferState: Initial state (LIN_NOT_OK, LIN_FRAME_SLEEP_STATE)
 * @note pConfig must be a valid pointer (checked via LIN_DEV_ERROR_REPORT)
 */
void LIN_DrvGetDefaultConfig(LIN_NodeType eNodeMode, LIN_ConfigType *pConfig);

/**
 * @brief Send a LIN frame over the bus (Master/Slave mode).
 * @param pLinHandle Pointer to LIN handle structure (contains configuration and state)
 * @param pLinPdu Pointer to Protocol Data Unit (PDU) containing frame information (PID, data, etc.)
 * @return Operation status:
 *         - LIN_RET_SUCCESS: Frame transmission initiated successfully
 *         - LIN_RET_STATE_ERROR: Node state is invalid for transmission
 *         - LIN_RET_ERROR: Parameter validation failed (via LIN_DEV_ERROR_REPORT)
 * @details
 * - Validates input parameters and node state
 * - For master nodes: Prepares response buffer and sends header
 * - Updates transfer state to LIN_TX_BUSY during transmission
 * - Slave nodes: No action (only master initiates frame transmission)
 */
LIN_ReturnType LIN_DrvSendFrame(LIN_HandleType *pLinHandle, LIN_PduType *pLinPdu);

/**
 * @brief Command LIN master node to initiate sleep mode sequence
 * @param pLinHandle Pointer to LIN handle structure (contains configuration and state)
 * @return Operation status:
 *         - LIN_RET_SUCCESS: Sleep sequence initiated successfully
 *         - LIN_RET_STATE_ERROR: Node state is invalid for sleep
 *         - LIN_RET_ERROR: Parameter validation failed (via LIN_DEV_ERROR_REPORT)
 * @details
 * - Validates input parameters and node state (must be operational)
 * - Constructs a sleep frame (PID=0x3C, 8-byte payload: 0x00 followed by 0xFFs)
 * - Sends header to start sleep sequence transmission
 * @note Only valid for master nodes (slave nodes cannot initiate sleep)
 */
LIN_ReturnType LIN_DrvGoToSleep(LIN_HandleType *pLinHandle);

/**
 * @brief Internal implementation to transition LIN node to sleep state
 * @param pLinHandle Pointer to LIN handle structure (contains configuration and state)
 * @return Operation status:
 *         - LIN_RET_SUCCESS: Sleep state transition completed
 *         - LIN_RET_STATE_ERROR: Node state is invalid for sleep
 *         - LIN_RET_ERROR: Parameter validation failed (via LIN_DEV_ERROR_REPORT)
 * @details
 * - Validates input parameters and node state (must be operational)
 * - Configures control register to disable error interrupts
 * - Flushes TX/RX FIFOs and clears data register
 * - Updates frame/channel state to LIN_FRAME_SLEEP_STATE and LIN_CH_SLEEP
 * - Enables receive active interrupt to detect wake-up signals
 */
LIN_ReturnType LIN_DrvGoToSleepInternal(LIN_HandleType *pLinHandle);

/**
 * @brief Send wake-up signal to LIN bus to rouse all nodes from sleep mode
 * @param pLinHandle Pointer to LIN handle structure (contains configuration and state)
 * @return Operation status:
 *         - LIN_RET_SUCCESS: Wake-up signal sent successfully
 *         - LIN_RET_NOT_INIT: LIN node is not initialized
 *         - LIN_RET_ERROR: Parameter validation failed (via LIN_DEV_ERROR_REPORT)
 * @details
 * - Validates input parameters and node state (must be initialized)
 * - Configures control register to enable error interrupts
 * - Disables receive active interrupt to focus on wake-up signal transmission
 * - Sends specific data (0x00 for baudrate >10000bps, 0xF8 otherwise) to generate 150us+ active level
 * - Updates node state to LIN_CH_OPERATIONAL and frame state to LIN_FRAME_IDLE_STATE
 * @note Master node sends signal; slave nodes enable break detection interrupt after wake-up
 */
LIN_ReturnType LIN_DrvWakeup(LIN_HandleType *pLinHandle);

/**
 * @brief Internal implementation to wake up LIN node from sleep state
 * @param pLinHandle Pointer to LIN handle structure (contains configuration and state)
 * @return Operation status:
 *         - LIN_RET_SUCCESS: Wake-up transition completed
 *         - LIN_RET_NOT_INIT: LIN node is not initialized
 *         - LIN_RET_ERROR: Parameter validation failed (via LIN_DEV_ERROR_REPORT)
 * @details
 * - Validates input parameters and node state (must be in sleep/sleep-pending state)
 * - Configures control register to enable error interrupts (ORIE, FEIE)
 * - Disables receive active interrupt to focus on operational mode
 * - Clears status register flags and flushes TX/RX FIFOs
 * - For slave nodes: Re-enables LIN break detection interrupt
 * - Updates node state to LIN_CH_OPERATIONAL and frame state to LIN_FRAME_IDLE_STATE
 */
LIN_ReturnType LIN_DrvWakeupInternal(LIN_HandleType *pLinHandle);

/**
 * @brief Get current LIN node operational status
 * @param pLinHandle Pointer to LIN handle structure
 * @return Current node state:
 *         - LIN_CH_SLEEP: Node in sleep mode
 *         - LIN_CH_OPERATIONAL: Node in active mode
 *         - LIN_TX_BUSY/LIN_RX_BUSY: Transmitting/receiving data
 * @details
 * - Converts internal transfer state (curChnState) to user-visible status
 * - Handles state transition from sleep-pending to sleep mode
 * - Validates handle and hardware index via LIN_DEV_ERROR_REPORT
 */
LIN_StatusType LIN_DrvGetStatus(LIN_HandleType *pLinHandle);

/**
 * @brief Abort ongoing LIN transfer and reset node to operational state
 * @param pLinHandle Pointer to LIN handle structure
 * @return Operation status:
 *         - LIN_RET_SUCCESS: Transfer aborted successfully
 *         - LIN_RET_STATE_ERROR: Invalid state for abort operation
 * @details
 * - Performs hardware-level abort operations including:
 *   • Disabling receive interrupts
 *   • Clearing status flags
 *   • Flushing Tx/Rx FIFOs
 * - For slave nodes, re-enables LIN break detection
 * - Resets internal state machines to operational/idle state
 * - Validates handle and hardware index via LIN_DEV_ERROR_REPORT
 */
LIN_ReturnType LIN_DrvAbortTransfer(LIN_HandleType *pLinHandle);

/**
 * @brief LIN controller interrupt service routine (ISR)
 * @param pLinHandle Pointer to LIN handle structure
 * @details
 * - Processes different types of interrupts based on hardware status:
 *   1. Wake-up interrupt: Handles LIN bus wake-up signal detection
 *   2. Transmission complete interrupt: Manages frame transmission completion
 *   3. Break detection interrupt: Processes LIN bus break field reception
 *   4. Data reception interrupt: Handles frame data reception
 *   5. Error handling: Invokes error handler for unrecognized interrupts
 * - Clears all interrupt flags after processing to prevent re-triggering
 */
void LIN_DrvIRQHandler(LIN_HandleType *pLinHandle);

/**
 * @brief Generate LIN PID parity bits according to LIN protocol specification
 * @param PID Input raw PID value (6-bit, without parity bits)
 * @return 8-bit PID value with parity bits (bits 6 and 7)
 * @details Calculates two parity bits:
 *          - P0 (bit 6): XOR of PID bits 0,1,2,4
 *          - P1 (bit 7): XOR of PID bits 1,3,4,5 (inverted)
 *          Combines raw PID with parity bits to form final 8-bit identifier
 */
uint8_t LIN_DrvParityMake(uint8_t PID);

/**
 * @brief Validate LIN PID parity bits according to LIN protocol specification
 * @param PID Input 8-bit PID value (with parity bits in bits 6 and 7)
 * @return Validated raw PID value (6-bit) or 0xFFU if parity check fails
 * @details Recalculates expected parity bits from input PID's data bits (0-5),
 *          compares with actual parity bits (6-7) in input PID:
 *          - If match: returns raw PID (bits 0-5)
 *          - If mismatch: returns 0xFFU (invalid PID)
 */
uint8_t LIN_DrvParityCheck(uint8_t PID);

/**@}*/

/** @}*/ /* module_driver_lin */
#if defined(__cplusplus)
}
#endif

#endif

#endif /* _DRIVER_MODULE_DRIVER_LIN_H_ */
