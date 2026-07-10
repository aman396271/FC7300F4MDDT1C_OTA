
/**
 * @file module_driver_fcspi.h
 * @author Flagchip
 * @brief ADC driver type definition and API
 * @version 2.0.0
 * @date 2024-12-22
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
   *   2.0.0       2024-12-22    Flagchip071   N/A          First release
   ******************************************************************************** */

#ifndef _DRIVER_MODULE_DRIVER_FCSPI_H_
#define _DRIVER_MODULE_DRIVER_FCSPI_H_

#include "HwA_fcspi.h"

#if FCSPI_INSTANCE_COUNT > 0U
/**
 * @addtogroup module_driver_fcspi
 *
 * @{
 */

#include "module_driver_dma.h"

#define FCSPI_DEV_ERROR_REPORT  STD_ON

#if defined(__cplusplus)
extern "C" {
#endif

/**
 * @name  FCSPI API Service IDs
 *
 * @{
 */
#define FCSPI_INIT_ID                         0U
#define FCSPI_DEINIT_ID                       1U
#define FCSPI_TRANSMIT_ID                     3U
#define FCSPI_RECEIVE_ID                      4U
#define FCSPI_TRANSMITRECEIVE_ID              5U
#define FCSPI_TRANSMIT_IT_ID                  6U
#define FCSPI_RECEIVE_IT_ID                   7U
#define FCSPI_TRANSMITRECEIVE_IT_ID           8U
#define FCSPI_TRANSMIT_DMA_ID                 9U
#define FCSPI_RECEIVE_DMA_ID                  10U
#define FCSPI_TRANSMITRECEIVE_DMA_ID          11U
/** @}*/


/**
 * @name  FCSPI Dev Error Code
 * @brief Error Code of calling FCSPI apis
 *
 * @{
 */
#define FCSPI_E_PARAM_UNINIT            0x01U   /* API service called without module initialization */
#define FCSPI_E_PARAM_POINTER           0x02U   /* API service called with an unexpected value for the pointer */
#define FCSPI_E_PARAM_CONFIG            0x03U   /* API service called with unreasonable configuration */
/** @}*/

/**
 * @brief FCSPI states 
 *
 */
typedef enum {
    FCSPI_STATE_UNINIT     = 0x00U,    /*!< Peripheral not Initialized                         */
    FCSPI_STATE_IDLE       = 0x01U,    /*!< Peripheral Initialized and idle for use           */
    FCSPI_STATE_BUSY       = 0x02U,    /*!< an internal process is ongoing                     */
    FCSPI_STATE_BUSY_TX    = 0x03U,    /*!< Data Transmission process is ongoing               */
    FCSPI_STATE_BUSY_RX    = 0x04U,    /*!< Data Reception process is ongoing                  */
    FCSPI_STATE_BUSY_TX_RX = 0x05U,    /*!< Data Transmission and Reception process is ongoing */
    FCSPI_STATE_ERROR      = 0x06U,    /*!< SPI error state                                    */
    FCSPI_STATE_ABORT      = 0x07U     /*!< SPI abort is ongoing                               */
} FCSPI_StateType;

/**
 * @brief Return value of FCSPI API services.
 *
 */
typedef enum {
    FCSPI_STATUS_SUCCESS = 0x0U,  /*!< The FCSPI operation is succeed */
    FCSPI_STATUS_ERROR   = 0x1U,  /*!< The FCSPI operation is failed */
    FCSPI_STATUS_TIMEOUT = 0x2U   /*!< The FCSPI operation is failed because of time out */
} FCSPI_StatusType;

/**
 * @brief Data acess width according to differen frame size user configured.
 *
 */
typedef enum {
    FCSPI_DATA_ACCESS_8_BIT   = 0x0U,  /*!< Access FCSPI DATA register and Tx/Rx buffer by byte */
    FCSPI_DATA_ACCESS_16_BIT  = 0x1U,  /*!< Access FCSPI DATA register and Tx/Rx buffer by half word */
    FCSPI_DATA_ACCESS_32_BIT  = 0X2U   /*!< Access FCSPI DATA register and Tx/Rx buffer by word */
} FCSPI_DataAccessWidthType;

/**
 * @brief Configuration item: The user chooses what strategy to use for the chip selection signal(PCS).
 *
 */
typedef enum {
    FCSPI_PCS_HARDWARE_SEL    = 0x0U, /*!< PCS(CS,Chip Selecl) is automatically controlled by the FCSPI peripheral hardware. */
    FCSPI_PCS_GPIO_SEL        = 0x1U, /*!< User will chose a GPIO pin and manually change its level high and low 
                                           to simulate the PCS. */
    FCSPI_PCS_NONE            = 0x2U  /*!< No need PCS. */
} FCSPI_PcsModeType;

typedef enum{

    /* Indicates that the user wants the actual clock frequency to be 
       as close as possible to the configured value(Config.SckFreq)
       In this case, the duty cycle of the SCK signal wave may not be 50%. */
    FCSPI_SCK_FEATURE_PRECISE_FREQ   = 0x0,

    /* Indicates that the user expects that the duty cycle of the SCK signal must be 50%.
       In this case, the error between the actual SCK frequency and the configured value may be greater.*/
    FCSPI_SCK_FEATURE_50_DUTY_CYCLE  = 0x1,
} FCSPI_SckFeature;

/**
 * @brief The structure of the FCSPI processing handle
 *
 */
typedef struct _FCSPI_HandleType
{
    FCSPI_InstanceType        eInstance;          /**< FCSPIn base address */

    struct
    {
        FCSPI_MasterSlaveModeType Mode;           /**< Master or Slave mode */

        uint32_t                  SckFreq;        /**< Desired Frequency of 'SCK' */
        FCSPI_SckPolarityType     SckPolarity;    /**< SCK polarity */
        FCSPI_SckPhaseType        SckPhase;       /**< SCK phase */
        FCSPI_SckFeature          SckFeature;     /**< Whether the duty cycle of 'SCK' is required to be 50% or not */

        FCSPI_PcsModeType         PcsMode;        /**< PCS is controled by FCSPI hardware or user control GPIO pin to simulate PCS */
        bool                      PcsContinuousEnable;  /**< Whether 'PCS' is continuous in a transfer API service */
        struct
        {
            FCSPI_PcsSelType      PCSn;           /**< Select from FCSPIn_PCS0 ~ FCSPIn_PCS3 */
            FCSPI_PcsPolarityType PcsPolarity;    /**< Pcs Polarity */
        } HardwareSelect;

        uint32_t                  FrameSize;      /**< Bit count of one frame */
        FCSPI_DataFirstBitType    BitOrder;       /**< MSB or LSB */
        FCSPI_TransferWidthType   TransferWidth;    /**< Transfer width */
        uint32_t                  TxFifoWatermark;  /**< Tx FIFO watermark */
        uint32_t                  RxFifoWatermark;  /**< Rx FIFO watermark */
        FCSPI_PinConfigType       PinConfig;        /**< Configuration about 'SIN' and 'SOUT' pin */
        bool                      SckLoopbackEnable;  /**< Sck loopback enable or not */
        bool                      InternalPcsEnable;  /**< Internal PCS enable or not, only valid on slave mode */
        bool                      ByteSwapEnable;     /**< Byte Swap enable or not */

        uint32_t                  DelayPCS2SCK;       /**< This configuration item is a multiple:
                                                           How many times of
                                                           the time interval between the PCS signal assert to the first edge of SCK
                                                           is one cycle of SCK. */
        uint32_t                  DelayPCS2PCS;       /**< This configuration item is a multiple:
                                                           How many times of
                                                           the time interval between the PCS signal de-assert to the next frame PCS assert
                                                           is one cycle of SCK. */
        uint32_t                  DelaySCK2PCS;       /**< This configuration item is a multiple:
                                                           How many times of
                                                           the time interval between the last edge of SCK to the PCS de-assert
                                                           is one cycle of SCK. */
        void (*TansferStartNotification)(struct _FCSPI_HandleType *pFcspiHandle);  /**< callback to notify that transfer starts,only valid in non-blocking API service */
        void (*TansferEndNotification)(struct _FCSPI_HandleType *pFcspiHandle);    /**< callback to notify that transfer completes,only valid in non-blocking API service */
    } Config;

    /**
     * @brief FCSPI driver inner status
     *     tStatus must not be set by user
     *
     */
    struct
    {
        volatile FCSPI_StateType    state;
        uint32_t                    TR_CTRL;   /**< The current TR_CTRL value of SPI Instance */
        FCSPI_DataAccessWidthType   eAccessWidth;

        uint8_t                    *TxBuff;
        uint32_t                    TxSize;  /**< Bytes count of all send data.It is a reference value that usually does not change during transmission */
        uint32_t                    TxCnt;   /**< Bytes count of data that has been writen into TX FIFO.It is a state value that changes as the transfer progresses  */
        void                      (*TxIsr)(struct _FCSPI_HandleType *pFcspiHandle); /*!< function pointer for Tx ISR */

        uint8_t                    *RxBuff;
        uint32_t                    RxSize;  /**< Bytes count of all receive data.It is a reference value that usually does not change during transmission*/
        uint32_t                    RxCnt;   /**< Bytes count of data that has been read from RX FIFO,It is a state value that changes as the transfer progresses */
        void                      (*RxIsr)(struct _FCSPI_HandleType *pFcspiHandle); /*!< function pointer for Rx ISR */
    } tStatus;

} FCSPI_HandleType;

uint32_t FCSPI_LL_CaculateSckdivPrescale(uint32_t *Prescale, uint32_t *Sckdiv, uint32_t InputClkFreq, uint32_t TargetSckFreq);

/**
 * @brief Initialize FCSPI based on configurations in FCSPI_HandleType
 * 
 * @param pFcspiHandle pointer to a FCSPI_HandleType structure
 * 
 * @return FCSPI_StatusType 
 */
FCSPI_StatusType FCSPI_Init(FCSPI_HandleType *pFcspiHandle);

/**
 * @brief De-init FCSPI peripheral and 'tStatus' of FCSPI_HandleType structure
 * 
 * @param pFcspiHandle pointer to a FCSPI_HandleType structure
 * 
 * @return void 
 */
void FCSPI_DeInit(FCSPI_HandleType *pFcspiHandle);

/**
 * @brief Transmit data in blocking(polling) mode.
 * 
 * @param pFcspiHandle pointer to a FCSPI_HandleType structure
 * @param pData pointer to Tx data buffer.
 * @param Size Bytes count of data to be transmitted.
 * 
 * @return FCSPI_StatusType 
 */
FCSPI_StatusType FCSPI_Transmit(FCSPI_HandleType *pFcspiHandle, uint8_t *pData, uint32_t Size);

/**
 * @brief Receive data in blocking(polling) mode.
 * 
 * @param pFcspiHandle pointer to a FCSPI_HandleType structure
 * @param pRxData pointer to Rx data buffer.
 * @param Size Bytes count of data to be received.
 * 
 * @return FCSPI_StatusType 
 */
FCSPI_StatusType FCSPI_Receive(FCSPI_HandleType *pFcspiHandle, uint8_t *pRxData, uint32_t Size);

/**
 * @brief Transmit and receive data in blocking(polling) mode.
 * 
 * @param pFcspiHandle pointer to a FCSPI_HandleType structure
 * @param pTxData pointer to Tx data buffer.
 * @param pRxData pointer to Rx data buffer.
 * @param Size Bytes count of data to be transmitted and received.
 * 
 * @return FCSPI_StatusType 
 */
FCSPI_StatusType FCSPI_TransmitReceive(FCSPI_HandleType *pFcspiHandle, uint8_t *pTxData, uint8_t *pRxData, uint32_t Size);

/**
 * @brief Transmit data in interrupt mode(non-blocking).
 * 
 * @param pFcspiHandle pointer to a FCSPI_HandleType structure
 * @param pTxData pointer to Tx data buffer.
 * @param Size Bytes count of data to be transmitted.
 * 
 * @return FCSPI_StatusType 
 */
FCSPI_StatusType FCSPI_Transmit_IT(FCSPI_HandleType *pFcspiHandle, uint8_t *pTxData, uint32_t Size);

/**
 * @brief Receive data in interrupt mode(non-blocking).
 * 
 * @param pFcspiHandle pointer to a FCSPI_HandleType structure
 * @param pRxData pointer to Rx data buffer.
 * @param Size Bytes count of data to be received.
 * 
 * @return FCSPI_StatusType 
 */
FCSPI_StatusType FCSPI_Receive_IT(FCSPI_HandleType *pFcspiHandle, uint8_t *pRxData, uint32_t Size);

/**
 * @brief Transmit and receive data in interrupt mode(non-blocking).
 * 
 * @param pFcspiHandle pointer to a FCSPI_HandleType structure
 * @param pTxData pointer to Tx data buffer.
 * @param pRxData pointer to Rx data buffer.
 * @param Size Bytes count of data to be transmitted and received.
 * 
 * @return FCSPI_StatusType 
 */
FCSPI_StatusType FCSPI_TransmitReceive_IT(FCSPI_HandleType *pFcspiHandle, uint8_t *pTxData, uint8_t *pRxData, uint32_t Size);

/**
 * @brief Transmit data in DMA mode(non-blocking).
 * 
 * @param pFcspiHandle pointer to a FCSPI_HandleType structure
 * @param pTxData pointer to Tx data buffer.
 * @param Size Bytes count of data to be transmitted.
 * 
 * @return FCSPI_StatusType 
 */
FCSPI_StatusType FCSPI_Transmit_DMA(FCSPI_HandleType *pFcspiHandle, uint8_t *pTxData, uint32_t Size);

/**
 * @brief Receive data in DMA mode(non-blocking).
 * 
 * @param pFcspiHandle pointer to a FCSPI_HandleType structure
 * @param pRxData pointer to Rx data buffer.
 * @param Size Bytes count of data to be received.
 * 
 * @return FCSPI_StatusType 
 */
FCSPI_StatusType FCSPI_Receive_DMA(FCSPI_HandleType *pFcspiHandle, uint8_t *pRxData, uint32_t Size);

/**
 * @brief Transmit and receive data in DMA mode(non-blocking).
 * 
 * @param pFcspiHandle pointer to a FCSPI_HandleType structure
 * @param pTxData pointer to Tx data buffer.
 * @param pRxData pointer to Rx data buffer.
 * @param Size Bytes count of data to be transmitted and received.
 * 
 * @return FCSPI_StatusType 
 */
FCSPI_StatusType FCSPI_TransmitReceive_DMA(FCSPI_HandleType *pFcspiHandle, uint8_t *pTxData, uint8_t *pRxData, uint32_t Size);


/**
 * @brief The internal interrupt handler function for FCSPI instances.
 * 
 * @param pFcspiHandle pointer to a FCSPI_HandleType structure
 */
void FCSPIn_IRQHandler(FCSPI_HandleType *pFcspiHandle);

/**
 * @brief FCSPI callback of DMA channel triggered by Tx FIFO.
 * 
 * @param pFcspiHandle pointer to a FCSPI_HandleType structure
 */
void FCSPIn_DmaDoneCallback_Tx(void *pFcspiHandle);

/**
 * @brief FCSPI callback of DMA channel triggered by Rx FIFO.
 * 
 * @param pFcspiHandle pointer to a FCSPI_HandleType structure
 */
void FCSPIn_DmaDoneCallback_Rx(void *pFcspiHandle);

#if defined(__cplusplus)
}
#endif

/** @}*/
#endif
#endif /* _DRIVER_MODULE_DRIVER_FCSPI_H_ */
