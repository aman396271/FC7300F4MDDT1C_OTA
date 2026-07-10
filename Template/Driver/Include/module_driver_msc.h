/**
 * @file module_driver_msc.h
 * @author flagchip
 * @brief MSC driver type definition and API
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
   *   0.1.0       2023-12-15    Flagchip084   N/A          First version for FC7300
   *   2.0.0       2024-10-12    Flagchip084   N/A          Change version and release
   ******************************************************************************** */

#ifndef _DRIVER_MODULE_DRIVER_MSC_H_
#define _DRIVER_MODULE_DRIVER_MSC_H_

#include "HwA_msc.h"

#if MSC_INSTANCE_COUNT > 0U

/**
 * @addtogroup module_driver_msc
 * @{
*/

#ifndef MSC_DEV_ERROR_REPORT
#define MSC_DEV_ERROR_REPORT    STD_OFF
#endif
#if MSC_DEV_ERROR_REPORT == STD_ON
    #define MSC_ReportDevError(func, error) ReportDevError(MSC_MODULE_ID, func, error)
#endif

/**
* @name  MSC API Service IDs
*
* @{
*/
#define MSC_INIT_ID                             0x00U
#define MSC_DEINIT_ID                           0x01U
#define MSC_INIT_STRUCTURE_ID                   0x02U
#define MSC_INIT_INTERRUPT_ID                   0x03U
#define MSC_SEL_TRANSMITTING_SOURCE_ID          0x04U
#define MSC_SET_EMERGENCY_LOAD_ID               0x05U
#define MSC_SET_IO_CONTROL_ID                   0x06U
#define MSC_ENABLE_ID                           0x07U
#define MSC_DISABLE_ID                          0x08U
#define MSC_SET_DATA_FRAME_ID                   0x09U
#define MSC_SEND_DATA_FRAME_ID                  0x0AU
#define MSC_SEND_COMMAND_FRAME_ID               0x0BU
#define MSC_GET_RECEIVED_FRAME_ADDR_ID          0x0CU
#define MSC_GET_RECEIVED_FRAME_ID               0x0DU
#define MSC_GET_INTERRUPT_STATUS_ID             0x0EU
#define MSC_ENABLE_TRANSMIT_ID                  0x0FU
#define MSC_CLEAR_DATA_FRAME_INTERRUPT_FLAG_ID  0x10U
#define MSC_CLEAR_COMMAND_FRAME_INTERRUPT_FLAG_ID 0x11U
#define MSC_CLEAR_TIME_FRAME_INTERRUPT_FLAG_ID  0x12U
#define MSC_CLEAR_RECEIVE_INTERRUPT_FLAG_ID     0x13U
#define MSC_CLEAR_TIMEOUT_INTERRUPT_FLAG_ID     0x14U
/** @} */

/**
 * @name  FTU Dev Error Code
 * @brief Error Code of calling FTU apis
 *
 * @{
 */
#define MSC_E_PARAM_INSTANCE            0x01U
#define MSC_E_PARAM_RXINDEX             0x02U
#define MSC_E_PARAM_POINTER             0x03U
#define MSC_E_PARAM_BITLENGTH             0x04U
/** @}*/

#define MSC_INSTANCE_0  0U  /*!< MSC instance 0 is selected. */
#define MSC_INSTANCE_1  1U   /*!< MSC instance 1 is selected. */
typedef uint8_t MSC_InstanceType;

typedef enum
{
    MSC_RETURN_OK                 = 0x00U,   /*!< The SENT operation is succeeded */
    MSC_RETURN_E_NOT_OK           = 0x01U,   /*!< The SENT operation is failed */
    MSC_RETURN_E_PARAM            = 0x04U,   /*!< The SENT parameter is incorrect or out of range. */
} MSC_ReturnType;

typedef enum
{
    MSC_RDR0        = 0x0U,
    MSC_RDR1        = 0x1U,
    MSC_RDR2        = 0x2U,
    MSC_RDR3        = 0x3U,
    MSC_RDRx_COUNT  = 0x4U
} MSC_RDRxIndexType;

typedef enum
{
    MSC_RFIE_DISABLE    = 0x0U, /*!< Interrupt generation disabled. */
    MSC_RFIE_MODE1      = 0x1U, /*!< The interrupt is generated when data is received and written into the RDRx. */
    MSC_RFIE_MODE2      = 0x2U, /*!< The interrupt is generated when received data is not equal to 0. */
    MSC_RFIE_MODE3      = 0x3U  /*!< The interrupt is generated when data is received and written into register RDR3. */
} MSC_RFIEModeType;

typedef enum
{
    MSC_DFIE_DISABLE    = 0x0U, /*!< Disable. */
    MSC_DFIE_MODE1      = 0x1U, /*!< Interrupt is generated when the last data bit has been shifted. */
    MSC_DFIE_MODE2      = 0x2U  /*!< Interrupt is generated when the first data bit has been shifted. */
} MSC_DFIEModeType;

typedef struct _MSC_HandleType
{
    MSC_InstanceType eInstance;
    uint8_t reserve0[3];
    struct
    {
        void (*pISRCallback)(const struct _MSC_HandleType *pMscHandle, const uint32_t u32Status);
        void (*pTOISRCallback)(const struct  _MSC_HandleType *pMscHandle);
        bool bToEnableFlag;
    } tSettings;

} MSC_HandleType;

/** @brief MSC interrupt configure structure. */
typedef struct
{
    bool bCFIntEnable;                  /*!< MSC_INCR[CFIE] bit, interrupt enable, if this bit asserted, command frame can lead the interrupt. */
    bool bTFIntEnable;                  /*!< MSC_INCR[TFIE] bit, interrupt enable, if this bit asserted, time frame can lead the interrupt. */
    MSC_RFIEModeType eRFIEMode;         /*!< Interrupt mode of RFIE. */
    MSC_DFIEModeType eDFIEMode;         /*!< Interrupt mode of DFIE. */
    bool bTOIntEnable;                  /*!< Enable the interrupt of timeout. */
    uint16_t u16TimeoutValue;           /*!< Timeout value of timeout interrupt. */
    void (*pISRCallback)(const MSC_HandleType *pMscHandle, const uint32_t u32Status);
    void (*pTOISRCallback)(const MSC_HandleType *pMscHandle);
} MSC_InterruptCfgType;

/**
 * @brief MSC Channel ISR callback function prototype
 *
 */
typedef void (*MSC_ISRCallbackType)(const MSC_HandleType *pMscHandle, const uint32_t u32Status);

typedef enum
{
    MSC_SDI_SEL_SDI0 = 0x0U,    /*!< SDI0 input is selected for SDI. */
    MSC_SDI_SEL_SDI1 = 0x1U,    /*!< SDI1 input is selected for SDI. */
    MSC_SDI_SEL_SDI2 = 0x2U,    /*!< SDI2 input is selected for SDI. */
    MSC_SDI_SEL_SDI3 = 0x3U,    /*!< SDI3 input is selected for SDI. */
    MSC_SDI_SEL_SDI4 = 0x4U,    /*!< SDI4 input is selected for SDI. */
    MSC_SDI_SEL_SDI5 = 0x5U,    /*!< SDI5 input is selected for SDI. */
    MSC_SDI_SEL_SDI6 = 0x6U,    /*!< SDI6 input is selected for SDI. */
    MSC_SDI_SEL_SDI7 = 0x7U     /*!< SDI7 input is selected for SDI. */
} MSC_SDISelectionType;

typedef enum
{
    MSC_ENC_SEL_EN0 = 0x0U, /*!< EN0 is selected for ENC. */
    MSC_ENC_SEL_EN1 = 0x1U, /*!< EN1 is selected for ENC. */
    MSC_ENC_SEL_EN2 = 0x2U, /*!< EN2 is selected for ENC. */
    MSC_ENC_SEL_EN3 = 0x3U  /*!< EN3 is selected for ENC. */
} MSC_ENCSelectionType;

typedef enum
{
    MSC_ENH_SEL_EN0 = 0x0U, /*!< EN0 is selected for ENH. */
    MSC_ENH_SEL_EN1 = 0x1U, /*!< EN1 is selected for ENH. */
    MSC_ENH_SEL_EN2 = 0x2U, /*!< EN2 is selected for ENH. */
    MSC_ENH_SEL_EN3 = 0x3U  /*!< EN3 is selected for ENH. */
} MSC_ENHSelectionType;

typedef enum
{
    MSC_ENL_SEL_EN0 = 0x0U, /*!< EN0 is selected for ENL. */
    MSC_ENL_SEL_EN1 = 0x1U, /*!< EN1 is selected for ENL. */
    MSC_ENL_SEL_EN2 = 0x2U, /*!< EN2 is selected for ENL. */
    MSC_ENL_SEL_EN3 = 0x3U  /*!< EN3 is selected for ENL. */
} MSC_ENLSelectionType;

typedef enum
{
    MSC_FLC_ACTIVE_ON_FRAMES    = 0x0U, /*!< FCL is actived only during the active phases of frames. */
    MSC_FLC_ALWAYS_ACTIVE       = 0x1U  /*!< FCL is always active whether or not a downstream frame is transmitted currently.. */
} MSC_FCLControlType;

typedef enum
{
    MSC_INPUT_IDENTICAL     = 0x0U, /*!< SDI and SI signal polarities are identical. */
    MSC_INPUT_INVERTED      = 0x1U  /*!< SDI and SI signal polarities are inverted. */
} MSC_InputPolarityType;

typedef enum
{
    MSC_ENX_IDENTICAL   = 0x0U, /*!< Enx and ENL, ENH, ENC signal polarities are identical (high active). */
    MSC_ENX_INVERTED    = 0x1U  /*!< ENx and ENL, ENH, ENC signal polarities are inverted (low active). */
} MSC_ENxPolarityType;

typedef enum
{
    MSC_SO_IDENTICAL    = 0x0U, /*!< SOP and SO signal polarity is identical. */
    MSC_SO_INVERTED     = 0x1U  /*!< SOP and SO signal polarity is inverted. */
} MSC_SOPolarityType;

typedef enum
{
    MSC_FLC_IDENTICAL   = 0x0U, /*!< FCLP and FCL polarity is identical. */
    MSC_FLC_INVERTED    = 0x1U  /*!< FCLP and FCL polarity is inverted. */
} MSC_FCLpolarityType;

typedef struct
{
    MSC_SDISelectionType    eSDIsel;   /*!< SDI seletion. */
    MSC_ENCSelectionType    eENCSel;   /*!< ENC seletion. */
    MSC_ENHSelectionType    eENHSel;   /*!< ENH seletion. */
    MSC_ENLSelectionType    eENLSel;   /*!< ENL seletion. */
    MSC_FCLControlType      eFclCtrl;  /*!< FCL Control. */
    MSC_InputPolarityType   eSDIPol;   /*!< SDI Polarity. */
    MSC_ENxPolarityType     eENXPol;   /*!< ENX Polarity. */
    MSC_SOPolarityType      eSOPPol;   /*!< SO Polarity. */
    MSC_FCLpolarityType     eFCLPPol;  /*!< FCL Polarity. */
} MSC_IOControlInitType;

typedef enum
{
    MSC_TRANS_SOURCE_DATA_REG   = 0x0U, /*!< SSL[x] is taken from TCDAR.DL[x]. */
    MSC_TRANS_SOURCE_ALTIN      = 0x2U, /*!< SSL[x] is taken from the ALTINL input line x. */
    MSC_TRANS_SOURCE_ALTIN_INV  = 0x3U, /*!< SSL[x] is taken from the ALTINL input line x in inverted state. */
} MSC_TransSourceType;

typedef enum
{
    MSC_TRIGGER_MODE    = 0x00U,    /*!< Trigger work mode. */
    MSC_REPETITION_MODE = 0x01U     /*!< Repetition work mode. */
} MSC_WorkModeType;

typedef enum
{
    MSC_EVEN_PARITY     = 0x00U,    /*!< Reception even parity. */
    MSC_ODD_PARITY      = 0x01U     /*!< Reception odd parity. */
} MSC_ParityType;

typedef enum
{
    MSC_RECEIVE_DISABLED        = 0x00U,    /*!< Receiving channel is disabled. */
    MSC_BAUDRATE_FMSC_DIV4      = 0x01U,    /*!< Baud rate=fmsc/4. */
    MSC_BAUDRATE_FMSC_DIV8      = 0x02U,    /*!< Baud rate=fmsc/8. */
    MSC_BAUDRATE_FMSC_DIV16     = 0x03U,    /*!< Baud rate=fmsc/16. */
    MSC_BAUDRATE_FMSC_DIV32     = 0x04U,    /*!< Baud rate=fmsc/32. */
    MSC_BAUDRATE_FMSC_DIV64     = 0x05U,    /*!< Baud rate=fmsc/64. */
    MSC_BAUDRATE_FMSC_DIV128    = 0x06U,    /*!< Baud rate=fmsc/128. */
    MSC_BAUDRATE_FMSC_DIV256    = 0x07U     /*!< Baud rate=fmsc/256. */
} MSC_ReceiveBaudRateType;

typedef enum
{
    MSC_FRAME_12_BIT = 0x00U,   /*!< 12-bit frame selected. */
    MSC_FRAME_16_BIT = 0x01U    /*!< 16-bit frame selected. */
} MSC_ReceiveFrameType;

typedef struct
{
    uint8_t u8PassiveLength;            /*!< Frame Passive length. */
    uint8_t u8PTFNumber;                /*!< The number of passive time frames that are inserted in repetition mode between two data frames. */
    MSC_WorkModeType eWorkMode;         /*!< MSC work mode. */
    uint8_t u8CommandBitLength;         /*!< Bit length of command frame. */
    bool    bSelSRH;                    /*!< Select SRH. */
    uint8_t u8SRHDataBitLength;         /*!< Bit length of SRH. */
    bool    bSelSRL;                    /*!< Select SRL. */
    uint8_t u8SRLDataBitLength;         /*!< Bit length of SRL. */
    bool    bDelayControl;              /*!< Hardware Receive Interrupt Delay Control. */
    MSC_ParityType  eParity;            /*!< Parity mode. */
    MSC_ReceiveBaudRateType eBaudRate;  /*!< Baudrate. */
    MSC_ReceiveFrameType eRsvFrameType; /*!< Frame type. */
} MSC_InitCfgType;

/**
 * @brief Initialize the MSC structure with the provided configuration.
 *
 * @param pInitConfig Pointer to the MSC initialization configuration structure.
 * @return MSC_ReturnType Returns MSC_RETURN_OK if the initialization is successful,
 *         otherwise returns an error code indicating the failure.
 */
MSC_ReturnType MSC_InitStructure(MSC_InitCfgType *pInitConfig);

/**
 * @brief Init the MSC.
 *
 * @param pMscHandle InstanceHandle
 * @param pInitConfig MSCInstance initial configuration.
 */
MSC_ReturnType MSC_Init(MSC_HandleType *pMscHandle, const MSC_InitCfgType *pInitConfig);

/**
 * @brief De-initialize the MSC.
 *
 * This function de-initializes the MSC module, resetting it to its default state.
 *
 * @param pMscHandle Pointer to the MSC handle structure.
 * @return MSC_ReturnType Returns MSC_RETURN_OK if de-initialization is successful,
 *         otherwise returns an error code indicating the failure.
 */
MSC_ReturnType MSC_DeInit(MSC_HandleType *pMscHandle);

/**
 * @brief Init the MSC interrupt.
 *
 * @param pMscHandle InstanceHandle
 * @param pInteruptConfig MSCInstance interrupt configuration.
 */
void MSC_initInterrupt(MSC_HandleType *pMscHandle, const MSC_InterruptCfgType *pInteruptConfig);

/**
 * @brief Select the transmitting sources.
 *
 * @param pMscHandle InstanceHandle
 * @param u32SourceMask Transmitting sources.
 * @param eSourceType Transmitting sources type.
 */
void MSC_SelTranmittingSource(const MSC_HandleType *pMscHandle, uint32_t u32SourceMask, MSC_TransSourceType eSourceType);

/**
 * @brief Set Emergency load value.
 *
 * @param pMscHandle InstanceHandle
 * @param u32Value Emergency load value.
 */
void MSC_SetEmergencyLoad(const MSC_HandleType *pMscHandle, uint32_t u32Value);

/**
 * @brief Configure the MSC IO control.
 *
 * @param pMscHandle InstanceHandle
 * @param pIOConfig MSC IO control configuration.
 */
void MSC_SetIOControl(const MSC_HandleType *pMscHandle, const MSC_IOControlInitType *pIOConfig);

/**
 * @brief Enable MSC.
 *
 * @param pMscHandle InstanceHandle
 */
void MSC_Enable(const MSC_HandleType *pMscHandle);

/**
 * @brief Disable MSC.
 *
 * @param pMscHandle InstanceHandle
 */
void MSC_Disable(const MSC_HandleType *pMscHandle);

/**
 * @brief MSC set data frame.
 *
 * @param pMscHandle InstanceHandle
 * @param u32Data Data to be sent.
 */
void MSC_SetDataFrame(const MSC_HandleType *pMscHandle, uint32_t u32Data);

/**
 * @brief MSC send data frame.
 *
 * @param pMscHandle InstanceHandle
 */
void MSC_SendDataFrame(const MSC_HandleType *pMscHandle);

/**
 * @brief MSC send command frame.
 *
 * @param pMscHandle InstanceHandle
 * @param u32Command command to be sent.
 */
void MSC_SendCommandFrame(const MSC_HandleType *pMscHandle, uint32_t u32Command);

/**
 * @brief Get the msc received data address.
 *
 * @param pMscHandle InstanceHandle
 * @param eIndex Receive data register index.
 * @return uint8_t Receiverd data address.
 */
uint8_t MSC_GetReceivedFrameAddr(const MSC_HandleType *pMscHandle, MSC_RDRxIndexType eIndex);

/**
 * @brief Get the msc received data.
 *
 * @param pMscHandle InstanceHandle
 * @param eIndex Receive data register index.
 * @param pData Received data value.
 * @return MSC_ReceiveStatusType  Status of getting received data.
 */
MSC_ReceiveStatusType MSC_GetReceivedFrame(const MSC_HandleType *pMscHandle, MSC_RDRxIndexType eIndex, uint8_t *pData);

/**
 * @brief Get the msc interrupt status.
 *
 * @param pMscHandle InstanceHandle
 * @return uint32_t Interrupt status.
 */
uint32_t MSC_GetInterruptStatus(const MSC_HandleType *pMscHandle);

/**
 * @brief Get the msc interrupt status.
 *
 * @param pMscHandle InstanceHandle
 * @return uint32_t Interrupt status.
 */
uint32_t MSC_GetToInterruptStatus(const MSC_HandleType *pMscHandle);

/**
 * @brief Get the msc interrupt status.
 *
 * @param pMscHandle InstanceHandle
 * @param bEnable Enable transmit channel.
 */
void MSC_EnableTrasmit(const MSC_HandleType *pMscHandle, bool bEnable);

/**
 * @brief Clear the msc data frame interrupt flag.
 *
 * @param pMscHandle InstanceHandle
 */
void MSC_ClearDataFrameInterruptFlag(const MSC_HandleType *pMscHandle);

/**
 * @brief Clear the msc command frame interrupt flag.
 *
 * @param pMscHandle InstanceHandle
 */
void MSC_ClearCommandFrameInterruptFlag(const MSC_HandleType *pMscHandle);

/**
 * @brief Clear the msc time frame interrupt flag.
 *
 * @param pMscHandle InstanceHandle
 */
void MSC_ClearTimeFrameInterruptFlag(const MSC_HandleType *pMscHandle);

/**
 * @brief Clear the msc receive interrupt flag.
 *
 * @param pMscHandle InstanceHandle
 */
void MSC_ClearReceiveInterruptFlag(const MSC_HandleType *pMscHandle);

/**
 * @brief Clear the msc timeout interrupt flag.
 *
 * @param pMscHandle InstanceHandle
 */
void MSC_ClearTimeoutInterruptFlag(const MSC_HandleType *pMscHandle);

void MSCn_IRQHandler(const MSC_HandleType *pMscHandle);

/** @}*/ /* module_driver_msc. */

#endif /* #if MSC_INSTANCE_COUNT > 0U */

#endif
