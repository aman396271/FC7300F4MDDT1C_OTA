/**
 * @file module_driver_dma.h
 * @author flagchip
 * @brief DMA driver type definition and API
 * @version 2.0.0
 * @date 2024-08-20
 *
 * SDK Version: 2.6.0
 *

 * @copyright Copyright (c) 2024 Flagchip Semiconductors Co., Ltd.
 *
 */
/* ********************************************************************************
   *   Revision History:
   *
   *   Version     Date          Initials      CR#          Descriptions
   *   ---------   ----------    ------------  ----------   ---------------
   *   0.1.0       2023-12-15    Flagchip073   N/A          First version for FC7300
   *   2.0.0       2024-10-12    Flagchip073   N/A          Change version and release
   ******************************************************************************** */

#ifndef _DRIVER_MODULE_DRIVER_DMA_H_
#define _DRIVER_MODULE_DRIVER_DMA_H_

#include "HwA_dma.h"

#if DMA_INSTANCE_COUNT > 0U

#include "HwA_dmamux.h"

#if defined(__cplusplus)
extern "C" {
#endif
/**
 * @addtogroup module_driver_dma
 * @{
 */

#define DMA_CHANNEL_INVALID   (0xFFU)

/**
 * @brief DMA transfer complete callback function prototype
 *
 */
typedef void (*DMA_TransferCompleteCallbackType)(void *arg);

/**
 * @brief DMA transfer error callback function prototype
 *
 */
typedef void (*DMA_TransferErrorCallbackType)(void *arg);

/**
 * @brief Available DMA Instances
 *
 */
typedef enum
{
    DMA_INSTANCE_0  = 0U,
    DMA_INSTANCE_1  = 1U,
    DMA_INSTANCE_MAX = DMA_INSTANCE_COUNT
} DMA_InstanceType;

/**
 * @brief Available DMA channels
 *
 */
typedef enum
{
    DMA_CHANNEL_0  = 0U,
    DMA_CHANNEL_1  = 1U,
    DMA_CHANNEL_2  = 2U,
    DMA_CHANNEL_3  = 3U,
    DMA_CHANNEL_4  = 4U,
    DMA_CHANNEL_5  = 5U,
    DMA_CHANNEL_6  = 6U,
    DMA_CHANNEL_7  = 7U,
    DMA_CHANNEL_8  = 8U,
    DMA_CHANNEL_9  = 9U,
    DMA_CHANNEL_10 = 10U,
    DMA_CHANNEL_11 = 11U,
    DMA_CHANNEL_12 = 12U,
    DMA_CHANNEL_13 = 13U,
    DMA_CHANNEL_14 = 14U,
    DMA_CHANNEL_15 = 15U,
    DMA_CHANNEL_16 = 16U,
    DMA_CHANNEL_17 = 17U,
    DMA_CHANNEL_18 = 18U,
    DMA_CHANNEL_19 = 19U,
    DMA_CHANNEL_20 = 20U,
    DMA_CHANNEL_21 = 21U,
    DMA_CHANNEL_22 = 22U,
    DMA_CHANNEL_23 = 23U,
    DMA_CHANNEL_24 = 24U,
    DMA_CHANNEL_25 = 25U,
    DMA_CHANNEL_26 = 26U,
    DMA_CHANNEL_27 = 27U,
    DMA_CHANNEL_28 = 28U,
    DMA_CHANNEL_29 = 29U,
    DMA_CHANNEL_30 = 30U,
    DMA_CHANNEL_31 = 31U,
    DMA_CHANNEL_MAX = DMA_CFG_COUNT
} DMA_ChannelType;

/**
 * @brief DMA operation return values
 *
 */
typedef enum
{
    DMA_STATUS_SUCCESS         = 0x00U,   /*!< The DMA operation is succeeded */
    DMA_STATUS_ERROR           = 0x01U,   /*!< The DMA operation is failed */
    DMA_STATUS_BUSY            = 0x02U,   /*!< The DMA operation is failed because DMA engine is busy */
    DMA_STATUS_TIMEOUT         = 0x03U,   /*!< The DMA operation is failed because operation time out */
    DMA_STATUS_UNSUPPORTED     = 0x04U,   /*!< The DMA configuration parameter is unsupported */
    DMA_STATUS_INVALID_ADDRESS = 0x05U,   /*!< The DMA source/destination address is invalid */
    DMA_STATUS_NO_RESOURCE     = 0x06U    /*!< The DMA operation is failed because there is no resource */
} DMA_StatusType;

/**
 * @brief DMA data increment size
 *
 * Specify the data increment size after DMA engine transferred a datum
 *
 */
typedef enum
{
    DMA_INCREMENT_DISABLE                 = 0x0U, /*!< The data address not increase */
    DMA_INCREMENT_DATA_SIZE               = 0x1U, /*!< The data address increase by the data size */
    DMA_INCREMENT_DATA_SIZE_4BYTE_ALIGNED = 0x2U  /*!< The data address increase by the data size,
                                                       and is 4 byte aligned */
} DMA_IncrementModeType;

/**
 * @brief The size of the circular buffer
 *
 * @note The start address of the circular buffer should be aligned by the circular
 * buffer size
 *
 */
typedef enum
{
    DMA_CIRCULAR_BUFFER_SIZE_1B    = 0x1U,
    DMA_CIRCULAR_BUFFER_SIZE_2B    = 0x2U,
    DMA_CIRCULAR_BUFFER_SIZE_4B    = 0x4U,
    DMA_CIRCULAR_BUFFER_SIZE_8B    = 0x8U,
    DMA_CIRCULAR_BUFFER_SIZE_16B   = 0x10U,
    DMA_CIRCULAR_BUFFER_SIZE_32B   = 0x20U,
    DMA_CIRCULAR_BUFFER_SIZE_64B   = 0x40U,
    DMA_CIRCULAR_BUFFER_SIZE_128B  = 0x80U,
    DMA_CIRCULAR_BUFFER_SIZE_256B  = 0x100U,
    DMA_CIRCULAR_BUFFER_SIZE_512B  = 0x200U,
    DMA_CIRCULAR_BUFFER_SIZE_1KB   = 0x400U,
    DMA_CIRCULAR_BUFFER_SIZE_2KB   = 0x800U,
    DMA_CIRCULAR_BUFFER_SIZE_4KB   = 0x1000U,
    DMA_CIRCULAR_BUFFER_SIZE_8KB   = 0x2000U,
    DMA_CIRCULAR_BUFFER_SIZE_16KB  = 0x4000U,
    DMA_CIRCULAR_BUFFER_SIZE_32KB  = 0x8000U,
    DMA_CIRCULAR_BUFFER_SIZE_64KB  = 0x10000U,
    DMA_CIRCULAR_BUFFER_SIZE_128KB = 0x20000U,
    DMA_CIRCULAR_BUFFER_SIZE_256KB = 0x40000U,
    DMA_CIRCULAR_BUFFER_SIZE_512KB = 0x80000U,
    DMA_CIRCULAR_BUFFER_SIZE_1MB   = 0x100000U,
    DMA_CIRCULAR_BUFFER_SIZE_2MB   = 0x200000U,
    DMA_CIRCULAR_BUFFER_SIZE_4MB   = 0x400000U,
    DMA_CIRCULAR_BUFFER_SIZE_8MB   = 0x800000U,
    DMA_CIRCULAR_BUFFER_SIZE_16MB  = 0x1000000U,
    DMA_CIRCULAR_BUFFER_SIZE_32MB  = 0x2000000U,
    DMA_CIRCULAR_BUFFER_SIZE_64MB  = 0x4000000U,
    DMA_CIRCULAR_BUFFER_SIZE_128MB = 0x8000000U,
    DMA_CIRCULAR_BUFFER_SIZE_256MB = 0x10000000U,
    DMA_CIRCULAR_BUFFER_SIZE_512MB = 0x20000000U,
    DMA_CIRCULAR_BUFFER_SIZE_1GB   = 0x40000000U,
    DMA_CIRCULAR_BUFFER_SIZE_2GB   = 0x80000000U,
} DMA_CircularBufferSizeType;

/**
 * @brief The eBufferRole of the circular buffer
 *
 */
typedef enum
{
    DMA_CIRCULAR_BUFFEER_ROLE_SOURCE      = 0x0U, /*!< The circular buffer is used as the data source */
    DMA_CIRCULAR_BUFFEER_ROLE_DESTINATION = 0x1U  /*!< The circular buffer is used as the data destination */
} DMA_CircularBufferRoleType;

/**
 * @name  DMA API Service IDs
 *
 * @{
 */
#define DMA_INIT_ID                        0U
#define DMA_INIT_CHANNEL_ID                1U
#define DMA_DEINIT_CHANNEL_ID              2U
#define DMA_INIT_CHANNEL_INT_ID            3U
#define DMA_CONFIG_CHAINED_TRANS_ID        4U
#define DMA_CONFIG_MODIFY_ADDR_ID          5U
#define DMA_CONFIG_START_CH_ID             6U
#define DMA_CONFIG_STOP_CH_ID              7U
#define DMA_CONFIG_GET_CH_REQ_SOURCE_ID    8U
#define DMA_CONFIG_GET_CH_STATUS_ID        9U
#define DMA_CONFIG_GET_MON_ID              10U
#define DMA_CONFIG_GET_STATUS_ID           11U
#define DMA_CONFIG_CLEAR_MON_ID            12U
#define DMA_CONFIG_DISABLE_MON_ID          13U
#define DMA_CONFIG_EN_MON_ID               14U
#define DMA_CONFIG_CANCEL_TRANS_ID         15U
/** @}*/

/**
 * @name  DMA Dev Error Code
 * @brief Error Code of calling DMA apis
 *
 * @{
 */
#define DMA_E_PARAM_CHCFG                   0x01U
#define DMA_E_PARAM_BLOCKCNT                0x02U
#define DMA_E_PARAM_BLOCKSIZE               0x03U
#define DMA_E_PARAM_DESTCIRCULARBUFSIZE     0x04U
#define DMA_E_PARAM_SRCCIRCULARBUFSIZE      0x05U
#define DMA_E_PARAM_INTERRUPTCFG            0x06U
#define DMA_E_PARAM_CHANNEL                 0x07U
#define DMA_E_PARAM_INSTANCE                0x08U
#define DMA_E_PARAM_INITCFG                 0x09U
#define DMA_E_PARAM_BLOCKSIZE_DATASIZE      0x0AU
/** @}*/

/**
 * @brief The configuration parameters of the DMA engine
 *
 */
typedef struct
{
    DMA_ArbitrationAlgorithmType eArbitrationAlgorithm; /*!< Channel Arbitration Algorithm */
    bool bHaltOnError;                                  /*!< Whether DMA halts when error occured */
    bool bGRP0HighPriority;                             /*!< Whether the priority of DMA group 0 channel is higher than group 1 channel*/
} DMA_InitType;

/**
 * @brief The structure of the DMA processing handle
 *
 */
typedef struct
{
    struct
    {
        /* tStatus can not be set by user */
        uint8_t u8DmaDumoUsedStatus[DMA_UMO_COUNT];
    } tStatus;
    struct
    {
        uint8_t u8Instance;     /*!< DMA Channel*/
        void (*pTransferErrorCallback[DMA_CFG_COUNT])(void *arg);          /*!< fault interrupt callback */
        void *errdata[DMA_CFG_COUNT];
    } tSettings;
} DMA_InstanceHandleType;

typedef struct _DMA_HandleType
{
    struct
    {
        uint8_t u8Channel;      /*!< DMA Channel*/
        DMA_InstanceHandleType *pInstance;
        struct
        {
            void *completedata;
            void (*pTransferCompleteCallback)(void *arg); /*!< channel interrupt callback */
        } callback;
    } tSettings;
} DMA_HandleType;



/**
 * @brief The configutation parameters of the DMA channel
 *
 * @note The u8ChannelPriority must be unique for different channels, the default is the channel number.
 * The u16BlockCount must be greater than 0.
 * @note When Circular buffer is enabled, the data address should be power of 2 aligned to the buffer size.
 * For example, if the circular buffer size is 32 byte, the data address should be 32 byte aligned. If the
 * circular buffer size is 40 byte, then the data address should be 64 byte aligned.
 *
 */
typedef struct
{
    const volatile void *pSrcBuffer;       /*!< the source address of the data */
    volatile void *pDestBuffer;            /*!< the destination address of the data */
    void *completedata;
    void *errdata;
    uint32_t u32BlockSize;                 /*!< the data size of one block in byte */
    uint16_t u16BlockCount;                /*!< the number of data blocks in one transfer */
    uint8_t u8ChannelPriority;             /*!< channel priority, greater number means higher priority */
    DMA_TransferSizeType eSrcDataSize;     /*!< source data size */
    DMA_TransferSizeType eDestDataSize;    /*!< destination data size */
    DMA_IncrementModeType eSrcIncMode;     /*!< source data address increment mode */
    DMA_IncrementModeType eDestIncMode;    /*!< destination data address increment mode */
    bool bSrcBlockOffsetEn;                /*!< whether to add a block offset to the source address after
                                                a block transfer */
    bool bDestBlockOffsetEn;               /*!< whether to add a block offset to the destination address after
                                                a block transfer */
    int32_t s32BlockOffset;                /*!< the signed address offset applied to the src/dest address
                                                after a block transfer */
    bool bSrcAddrLoopbackEn;               /*!< whether the source address return to the set value after transfer */
    bool bDestAddrLoopbackEn;              /*!< whether the destination address return to the set value after transfer */
    bool bAutoStop;                        /*!< whether the DMA channel transfer automatically stops after one
                                                transfer finishes when the channel is triggered by hardware */
    bool bSrcCircularBufferEn;             /*!< the source buffer of the DMA channel is a circular buffer */
    uint32_t u32SrcCircBufferSize;         /*!< the source circular buffer size in byte, the buffer size is suggested
                                                to be power of 2 aligned */
    bool bDestCircularBufferEn;            /*!< the destination buffer of the DMA channel is a circular buffer */
    uint32_t u32DestCircBufferSize;        /*!< the destination circular buffer size in byte, the buffer size is suggested
                                                to be power of 2 aligned */
    bool bInnerChannelChain;
    DMA_RequestSourceType eTriggerSrc;     /*!< Select the DMA channel trigger source, if the trigger source is
                                                DMA_REQ_DISABLED, the channel is triggered by software */
    bool bTransferCompleteIntEn; /*!< Enable interrupt after transfer complete */
    DMA_TransferCompleteCallbackType pTransferCompleteNotify; /*!< transfer complete notification */
    bool bTransferErrorIntEn;    /*!< Enable interrupt when transfer error occured */
    DMA_TransferErrorCallbackType pTransferErrorNotify;       /*!< transfer error notification */
} DMA_ChannelCfgType;

/**
 * @brief The parameters to configure the DMA channel as a circular buffer engine
 *
 */
typedef struct
{
    DMA_CircularBufferRoleType eBufferRole; /*!< the source or the destination address is a circular buffer */
    DMA_CircularBufferSizeType eBufferSize; /*!< the circular buffer size */
    bool bCircularBufferEn;                 /*!< enable the DMA channel as a circular buffer engine */
} DMA_CircularBufferType;

/**
 * @brief The paarameters to configure the DMA chainned transfer
 *
 */
typedef struct
{
    bool bChanelChainEn;      /*!< Whether to start the chained channel when the current completed */
    uint8_t u8ChainedChannel; /*!< The chained channel */
} DMA_ChainTransferType;

/**
 * @brief Initialize the DMA instance
 *
 * @param pDmaInstanceHandle DMA handle
 * @param pInitCfg the configuration of the DMA instance
 */
void DMA_Init(DMA_InstanceHandleType *pDmaInstanceHandle, const DMA_InitType *const pInitCfg);

/**
 * @brief De-initialize the DMA instance
 *
 * Disable the DMA and restore its configure values to default
 *
 * @param pDmaInstanceHandle DMA handle
 */
void DMA_DeInit(DMA_InstanceHandleType *pDmaInstanceHandle);

/**
 * @brief Initialize the DMA channel
 *
 * @param pDmaHandle the DMA channel to initialize
 * @param pChnCfg the configuration of the channel
 * @return DMA_StatusType whether the channel is initiallized successfully
 */
DMA_StatusType DMA_InitChannel(DMA_HandleType *pDmaHandle, const DMA_ChannelCfgType *const pChnCfg);

/**
 * @brief De-initialize the DMA channel
 *
 * @param pDmaHandle the DMA channel to de-initialize
 */
void DMA_DeinitChannel(DMA_HandleType *pDmaHandle);

/**
 * @brief Initialize the DMA channel interrupt
 *
 * @param pDmaHandle the DMA channel to use
 * @param pChnCfg the configuration of the DMA channel
 */
void DMA_InitChannelInterrupt(DMA_HandleType *pDmaHandle, const DMA_ChannelCfgType *const pChnCfg);

/**
 * @brief Config the DMA channel chained transfer
 *
 * @param pDmaHandle the DMA channel to use
 * @param pChainTransferCfg the parameters of the chained channel
 */
void DMA_ConfigChainedTransfer(DMA_HandleType *pDmaHandle,
                               const DMA_ChainTransferType *const pChainTransferCfg);

/**
 * @brief Modify the source and destination address of the DMA channel
 *
 * @note This function should be called when the DMA channel is not actively transferring
 *
 * @param pDmaHandle the channel to modify
 * @param pSrcBuffer the new source address of data, set NULL to remain unmodified
 * @param pDestBuffer the new destination address of data, set NULL to remain unmodified
 * @return DMA_StatusType whether the address is successfully modified
 */
DMA_StatusType DMA_ModifyAddress(DMA_HandleType *pDmaHandle, const volatile void *pSrcBuffer,
                                 const volatile void *pDestBuffer);

/**
 * @brief Start the DMA channel transfer
 *
 * If the trigger source for the DMA channel is DMA_REQ_DISABLED, the channel will start
 * immediately after called this function. Otherwise, the channel will start when the
 * trigger source is generated on the channel.
 *
 * @param pDmaHandle the DMA channel to start
 */
void DMA_StartChannel(DMA_HandleType *pDmaHandle);

/**
 * @brief Stop the DMA channel transfer
 *
 * If the trigger source for the DMA channel is DMA_REQ_DISABLED, the channel will stop
 * automatically after the transfer completed. Otherwise, you should call this function
 * manually if you do not want the DMA to be triggered when hardware request is generated.
 *
 * @note If there is ongoing transfer on the channel, the channel will be stopped after the
 * transfer completed.
 *
 * @param pDmaHandle the DMA channel to stop
 */
void DMA_StopChannel(DMA_HandleType *pDmaHandle);

/**
 * @brief Cancel the ongoing DMA transfer
 *
 * @param pDmaInstanceHandle DMA handle
 * @param bGenerateErr whether an error will be generated on the transferring channel
 * @return DMA_StatusType whether the transfer is stopped successfully
 */
DMA_StatusType DMA_CancelTransfer(DMA_InstanceHandleType *pDmaInstanceHandle, bool bGenerateErr);

#ifdef DMA_HAVE_MONCHK
/**
 * @brief Enable DMA Error Monitor checker function.
 *
 * @param u8Dma_Instance The selected DMA instance number.
 */
void DMA_EnableMonitorChecker(DMA_InstanceHandleType *pDmaInstanceHandle);

/**
 * @brief Disable DMA Error Monitor checker function.
 *
 * @param u8Dma_Instance The selected DMA instance number.
 */
void DMA_DisableMonitorChecker(DMA_InstanceHandleType *pDmaInstanceHandle);

/**
 * @brief Clear all DMA Error Monitor checker error bits.
 *
 * @param u8Dma_Instance The selected DMA instance number.
 */
void DMA_ClearMonitorCheckerAllError(DMA_InstanceHandleType *pDmaInstanceHandle);

/**
 * @brief Get DMA Monitor checker error status.
 *
 * @param u8Dma_Instance The selected DMA instance number.
 * @return uint32_t the error status for monitor checker.
 */
uint32_t DMA_GetMonitorCheckerErrStatus(DMA_InstanceHandleType *pDmaInstanceHandle);
#endif

/**
 * @brief Get the request source of the selected channel
 *
 * @param pDmaHandle the DMA channel to get the request source
 * @return DMA_RequestSourceType the request source of the selected channel
 */
DMA_RequestSourceType DMA_GetChannelRequestSrc(DMA_HandleType *pDmaHandle);

/**
 * @brief Get the status of the DMA engine
 *
 * @return DMA_RunningStatusType the status of the DMA engine
 */
DMA_RunningStatusType DMA_GetStatus(DMA_InstanceHandleType *pDmaInstanceHandle);

/**
 * @brief Get the status of the DMA channel
 *
 * @param pDmaHandle the DMA channel to get the status
 * @return DMA_RunningStatusType the status of the DMA channel
 */
DMA_RunningStatusType DMA_GetChannelStatus(DMA_HandleType *pDmaHandle);

/**
 * @brief The internal interrupt handler for DMA transfer complete
 *
 * @param pDmaHandle    the handle of the DMA complete interrpt
 */
void DMA_Transfer_Complete_IRQHandler(DMA_HandleType *pDmaHandle);

/**
 * @brief The internal interrupt handler for DMA error complete
 *
 * @param pDmaInstanceHandle    the handle of the DMA complete interrpt
 */
void DMA_ProcessErrorInterrupt(DMA_InstanceHandleType *pDmaInstanceHandle);

/** @}*/ /* module_driver_dma */
#if defined(__cplusplus)
}
#endif

#endif /* #if DMA_INSTANCE_COUNT > 0U */

#endif
