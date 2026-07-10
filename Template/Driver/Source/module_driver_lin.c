/**
 * @file module_driver_lin.h
 * @author Flagchip
 * @brief LIN (Local Interconnect Network) protocol driver implementation
 * @version 2.0.0
 * @date 2024-08-23
 *
 * SDK Version: 2.6.0
 *

 * @copyright Copyright (c) 2020-2024 Flagchip Semiconductors Co., Ltd.
 * @details This file provides low-level driver functions for LIN communication, including initialization,
 *          frame transmission/reception, sleep/wakeup management, and interrupt handling. Supports both
 *          master and slave node modes.
 */
/*********************************************************************************
*  Revision History:

*   Version     Date          Initials      CR#          Descriptions
*   ---------   ----------    ------------  ----------   ---------------
*   2.0.0       2024-08-23    Flagchip122   N/A          First version (Initial implementation of LIN protocol driver)
*********************************************************************************/

#include "module_driver_lin.h"

#if FCUART_INSTANCE_COUNT > 0U

#include "device_header.h"
#include "module_driver_fcuart.h"

/* ################################################################################## */
/* ####################################### Macro #################################### */
/**
 * @brief Enable/disable device error reporting feature.
 * @note When set to STD_ON, error reports will be generated using ReportDevError()
 */
#ifndef LIN_DEV_ERROR_REPORT
    #define LIN_DEV_ERROR_REPORT    STD_OFF
#endif

#if LIN_DEV_ERROR_REPORT == STD_ON
    /**
    * @brief Helper macro to report device errors.
    * @param func ID of the function where error occurred
    * @param error Specific error code
    */
    #define LIN_ReportDevError(func, error) ReportDevError(LIN_MODULE_ID, func, error)
#endif

/** UART Instance Number: Total available LIN controller instances */
#define LIN_INSTANCE_NUM FCUART_INSTANCE_COUNT

/* ################################################################################## */
/* ################################### type define ################################## */

/* ################################################################################## */
/* ################################ Local Variables ################################# */

/**
 * @brief Array of FCUART peripheral base addresses.
 * @details Used to access hardware registers of different LIN controller instances.
 */
static FCUART_Type *const s_aFCUART_InstanceTable[FCUART_INSTANCE_COUNT] = FCUART_BASE_PTRS;

/* ################################################################################## */
/* ########################### Local Prototype Functions ############################ */
#if LIN_DEV_ERROR_REPORT == STD_ON
    LOCAL_INLINE LIN_ReturnType LIN_AssertLinInit(LIN_HandleType *pLinHandle, LIN_ConfigType *pConfig);
    LOCAL_INLINE LIN_ReturnType LIN_AssertLinHandle(LIN_HandleType *pLinHandle);
    LOCAL_INLINE LIN_ReturnType LIN_AssertLinHwIndex(LIN_ConfigType *pConfig);
    LOCAL_INLINE LIN_ReturnType LIN_AssertLinPdu(LIN_PduType *pPdu);
    LOCAL_INLINE LIN_ReturnType LIN_AssertMasterApi(LIN_HandleType *pLinHandle, uint32_t u32ApiId);
#endif /* LIN_DEV_ERROR_REPORT == STD_ON */
LOCAL_INLINE void LIN_DelayFunctionClk(LIN_XferStateType *pXfer, uint32 u32Tick);
static void LIN_ResetLinController(LIN_XferStateType *pXfer, LIN_ConfigType *pCfg);

static LIN_ReturnType LIN_DrvCalBaudrate(LIN_HandleType *pLinHandle, LIN_BaudRateCfgType *pCfg);
LOCAL_INLINE uint8_t  BIT(uint8_t A, uint8_t B);
static uint8_t LIN_DrvMakeCheckSum(LIN_XferStateType *pXfer);
/* ################################################################################## */
/* ########################### Global Prototype Functions ########################### */

/* ################################################################################## */
/* ################################ Local Functions ################################# */

/**
 * @brief Extract specified bit from a byte.
 * @param A Source byte value
 * @param B Bit position to extract (0-7)
 * @return Value of the specified bit (0 or 1)
 */
LOCAL_INLINE uint8_t BIT(uint8_t A, uint8_t B)
{
    return (uint8_t)((A >> B) & (uint8_t)0x01U);
}

#if LIN_DEV_ERROR_REPORT == STD_ON
/**
 * @brief Validate LIN initialization parameters.
 * @param pLinHandle Pointer to LIN handle structure
 * @param pConfig Pointer to LIN configuration structure
 * @return LIN_RET_SUCCESS if parameters are valid, otherwise error code
 * @details Checks for non-null pointers
 */
LOCAL_INLINE LIN_ReturnType LIN_AssertLinInit(LIN_HandleType *pLinHandle, LIN_ConfigType *pConfig)
{
    LIN_ReturnType ret = LIN_RET_STATE_ERROR;
    if ((pLinHandle != NULL) && (pConfig != NULL))
    {
        ret = LIN_RET_SUCCESS;
    }
    return ret;
}
/**
 * @brief Validate LIN handle structure integrity.
 * @param pLinHandle Pointer to LIN handle structure
 * @return LIN_RET_SUCCESS if handle and its internal pointers are valid, otherwise error code
 * @details Checks if handle itself is non-null, and its internal configuration (pCfg) and transfer state (pXfer) pointers are non-null
 */
LOCAL_INLINE LIN_ReturnType LIN_AssertLinHandle(LIN_HandleType *pLinHandle)
{
    LIN_ReturnType ret = LIN_RET_STATE_ERROR;
    if (pLinHandle != NULL)
    {
        if ((pLinHandle->pCfg != NULL) && (pLinHandle->pXfer != NULL))
        {
            ret = LIN_RET_SUCCESS;
        }
    }
    return ret;
}
/**
 * @brief Validate LIN hardware index range.
 * @param pConfig Pointer to LIN configuration structure
 * @return LIN_RET_SUCCESS if hardware index is within valid range, otherwise error code
 * @details Checks if the hardware index in configuration (pCfg->u8LinHwIndex) is less than total available instances (LIN_INSTANCE_NUM)
 */
LOCAL_INLINE LIN_ReturnType LIN_AssertLinHwIndex(LIN_ConfigType *pConfig)
{
    LIN_ReturnType ret = LIN_RET_STATE_ERROR;
    if (pConfig->u8LinHwIndex < LIN_INSTANCE_NUM)
    {
        ret = LIN_RET_SUCCESS;
    }
    return ret;
}
/**
 * @brief Validate LIN PDU (Protocol Data Unit) pointer.
 * @param pPdu Pointer to LIN PDU structure
 * @return LIN_RET_SUCCESS if PDU pointer is non-null, otherwise error code
 */
LOCAL_INLINE LIN_ReturnType LIN_AssertLinPdu(LIN_PduType *pPdu)
{
    LIN_ReturnType ret = LIN_RET_STATE_ERROR;
    if (pPdu != NULL)
    {
        ret = LIN_RET_SUCCESS;
    }
    return ret;
}
/**
 * @brief Validate master node API call permission.
 * @param pLinHandle Pointer to LIN handle structure
 * @param u32ApiId ID of the API being called
 * @return LIN_RET_SUCCESS if API call is allowed for current node mode, otherwise error code
 * @details For slave nodes, only allows calls to APIs explicitly permitted (e.g., LIN_DRV_GOTO_SLEEP_ID is blocked)
 */
LOCAL_INLINE LIN_ReturnType LIN_AssertMasterApi(LIN_HandleType *pLinHandle, uint32_t u32ApiId)
{
    LIN_ReturnType ret = LIN_RET_SUCCESS;
    if (LIN_NODE_SLAVE == pLinHandle->pCfg->nodeMode)
    {
        if (LIN_DRV_GOTO_SLEEP_ID == u32ApiId)
        {
            ret = LIN_RET_STATE_ERROR;
        }
    }
    return ret;
}
#endif /* LIN_DEV_ERROR_REPORT == STD_ON */

/**
 * @brief Delay execution for specified clock cycles using assembly loop
 * @param pXfer Pointer to LIN transfer state structure (contains delay counter)
 * @param u32Tick Number of clock cycles to delay
 * @details Implements a simple delay using a decrement loop in assembly.
 *          The loop count is calculated based on the functional clock frequency ratio.
 *          Typical loop execution: 5-6 clock cycles per iteration.
 */
LOCAL_INLINE void LIN_DelayFunctionClk(LIN_XferStateType *pXfer, uint32 u32Tick)
{
    uint32 u32CountLimit = pXfer->xferDlyCnt * u32Tick / 4;
    /*range 4-7 clk, typical 5-6 clk per loop*/
    __asm volatile(
                "1: subs %[cnt], %[cnt], #1 \n\t"
                "   nop         \n\t"
                "   dsb         \n\t"
                "   bne 1b      \n\t"
                : [cnt] "+r"(u32CountLimit)
                :
                : "cc", "memory"
    );
}
/**
 * @brief Reset LIN controller to idle operational or sleep state
 * @param pXfer Pointer to LIN transfer state structure
 * @param pCfg Pointer to LIN configuration structure
 * @details
 */
static void LIN_ResetLinController(LIN_XferStateType *pXfer, LIN_ConfigType *pCfg)
{
    uint32_t val;

    if ((LIN_CH_SLEEP_PENDING == pXfer->curChnState) || (LIN_CH_SLEEP == pXfer->curChnState))
    {
    	val = FCUART_CTRL_ORIE(0U) | FCUART_CTRL_NEIE(0U) | FCUART_CTRL_FEIE(0U) | \
    	              FCUART_CTRL_TE(0U) | FCUART_CTRL_RE(0U);
        FCUART_HWA_SetCtrl(pXfer->base, val);
        LIN_DelayFunctionClk(pXfer, 2U);
        FCUART_HWA_FlushTxRxFifo(pXfer->base);
        val = FCUART_CTRL_ORIE(0U) | FCUART_CTRL_NEIE(0U) | FCUART_CTRL_FEIE(0U) | \
              FCUART_CTRL_TE(1U) | FCUART_CTRL_RE(1U);
        FCUART_HWA_SetCtrl(pXfer->base, val);
        LIN_DelayFunctionClk(pXfer, 2U);
        (void)FCUART_HWA_GetData(pXfer->base);
        pXfer->curFrState = LIN_FRAME_SLEEP_STATE;
        pXfer->cntByte = 0U;
        FCUART_HWA_SetReceiveActiveInterrupt(pXfer->base, true);
    }
    else
    {
    	val = FCUART_CTRL_ORIE(0U) | FCUART_CTRL_NEIE(0U) | FCUART_CTRL_FEIE(0U) | \
    	              FCUART_CTRL_TE(0U) | FCUART_CTRL_RE(0U);
        FCUART_HWA_SetCtrl(pXfer->base, val);
        LIN_DelayFunctionClk(pXfer, 2U);
        FCUART_HWA_FlushTxRxFifo(pXfer->base);
        val = FCUART_CTRL_ORIE(1U) | FCUART_CTRL_NEIE(0U) | FCUART_CTRL_FEIE(1U) | \
              FCUART_CTRL_TE(1U) | FCUART_CTRL_RE(1U);
        FCUART_HWA_SetCtrl(pXfer->base, val);
        LIN_DelayFunctionClk(pXfer, 2U);
        FCUART_HWA_SetReceiveActiveInterrupt(pXfer->base, false);
        (void)FCUART_HWA_GetData(pXfer->base);
        pXfer->curFrState = LIN_FRAME_IDLE_STATE;
        if (LIN_NODE_SLAVE == pCfg->nodeMode)
        {
            FCUART_HWA_SetLinBreakDetectEnable(pXfer->base, true);
            FCUART_HWA_SetLinBreakDetectInterrupt(pXfer->base, true);
        }
        pXfer->cntByte = 0U;

    }
}

/**
 * @brief Calculate optimal baud rate configuration parameters
 * @param pLinHandle LIN handle structure containing configuration
 * @param pCfg Output parameter to store calculated baud rate settings
 * @return LIN_RET_SUCCESS on successful calculation
 * @details
 * - Iterates over possible oversampling ratios (16-32)
 * - For each ratio, calculates baud rate divider (SBR)
 * - Selects the combination with minimum deviation from target baud rate
 * - Stores results in pCfg->u16OvrSamp (oversampling ratio) and pCfg->u16SBR (divider)
 */
static LIN_ReturnType LIN_DrvCalBaudrate(LIN_HandleType *pLinHandle, LIN_BaudRateCfgType *pCfg)
{
    LIN_ReturnType ret = LIN_RET_SUCCESS;
    uint32_t clockFreq = pLinHandle->pCfg->funcClkFreq;
    uint32_t sbr = 1U;
    uint32_t osr = 1U;
    uint32_t sbrTmp;
    uint32_t index;
    uint32_t minDiff = 0xFFFFFFFFU;
    uint32_t baudDiff;
    uint32_t temp;

    for (index = 16U; index <= 32U; index++)
    {
        temp = pLinHandle->pCfg->baudRate * index;
        sbrTmp = (clockFreq + (temp >> 1U)) / temp;
        if (sbrTmp == 0U)
        {
            sbrTmp = 1U;
        }
        else if (sbrTmp >= 8192U)
        {
            continue;
        }
        else
        {
            /* do nothing */
        }

        temp = temp * sbrTmp;
        if (temp == clockFreq)
        {
            baudDiff = 0U;
            osr = index;
            sbr = sbrTmp;
            break;
        }
        else if (temp > clockFreq)
        {
            baudDiff = temp - clockFreq;
        }
        else
        {
            baudDiff = clockFreq - temp;
        }

        if (baudDiff < minDiff)
        {
            minDiff = baudDiff;
            osr = index;
            sbr = sbrTmp;
        }
    }
    pCfg->u16OvrSamp = (uint16_t)osr;
    pCfg->u16SBR = (uint16_t)sbr;
    ret = LIN_RET_SUCCESS;
    return ret;
}

/**
 * @brief Calculate LIN frame checksum
 * @param pXfer Transfer state structure containing PDU information
 * @return Calculated checksum byte
 * @details Implements LIN protocol checksum calculation:
 *          - Classic checksum: sum of data bytes only
 *          - Enhanced checksum: sum of PID + data bytes
 *          Uses inverted modulo 256 sum (two's complement)
 */
static uint8_t LIN_DrvMakeCheckSum(LIN_XferStateType *pXfer)
{
    uint16_t        u16Checksum = 0U;
    uint8_t         index    = 0U;

    if (LIN_ENHANCED_CS == pXfer->xferPdu.Cs)
    {
        u16Checksum = (uint16_t)(u16Checksum + pXfer->xferPdu.Pid);
    }

    for (index = 0U; index < pXfer->xferPdu.Dl; index++)
    {
        u16Checksum = (uint16_t)(u16Checksum + pXfer->xferPdu.SduPtr[index]);
        if (u16Checksum > 0xFFU)
        {
            u16Checksum = (uint16_t)(u16Checksum - 0xFFU);
        }
    }

    return (uint8_t)(~u16Checksum);
}

/**
 * @brief Initiate LIN header transmission (Master only)
 * @param pXfer Transfer state structure
 * @return LIN_RET_SUCCESS on success
 * @details
 * - Configures controller for transmission (enables TX/RX, error interrupts)
 * - Clears status register flags
 * - Flushes TX/RX FIFOs
 * - Sends break field to start frame transmission
 * - Enables transmission complete interrupt
 * - Updates state machine to BREAK_SEND_STATE
 * Note: Only valid for master nodes
 */
static LIN_ReturnType LIN_DrvSendHeader(LIN_XferStateType *pXfer)
{
    LIN_ReturnType    ret   = LIN_RET_SUCCESS;
    uint32_t       ctrlRegVal = 0U;
    uint32_t statRegVal;

    ctrlRegVal = FCUART_CTRL_ORIE(1U) | FCUART_CTRL_NEIE(0U) | FCUART_CTRL_FEIE(0U) | \
                 FCUART_CTRL_TE(0U) | FCUART_CTRL_RE(0U);
    FCUART_HWA_SetCtrl(pXfer->base, ctrlRegVal);

    LIN_DelayFunctionClk(pXfer, 2U);

    FCUART_HWA_FlushTxRxFifo(pXfer->base);

    ctrlRegVal = FCUART_CTRL_ORIE(1U) | FCUART_CTRL_NEIE(0U) | FCUART_CTRL_FEIE(0U) | \
                 FCUART_CTRL_TE(1U) | FCUART_CTRL_RE(1U);
    FCUART_HWA_SetCtrl(pXfer->base, ctrlRegVal);

    LIN_DelayFunctionClk(pXfer, 2U);
    /* clear register status flag */
    statRegVal = FCUART_HWA_GetSTAT(pXfer->base);
    FCUART_HWA_WriteClearSTAT(pXfer->base, statRegVal);

    /* Send a break filed to protocol. */
    FCUART_HWA_SendBreakField(pXfer->base);
    FCUART_HWA_EnableInterrupt(pXfer->base, FCUART_CTRL_TCIE_MASK);

    /* Update node state. */
    pXfer->curEventId   = LIN_NO_EVENT;
    pXfer->curFrState = LIN_FRAME_BREAK_SEND_STATE;

    return ret;
}

/**
 * @brief Prepare LIN frame response data for transmission
 * @param pXfer Transfer state structure (contains current transfer context)
 * @param pCfg LIN configuration structure (contains node mode)
 * @param pLinPdu Protocol Data Unit (PDU) containing frame information
 * @return Operation status:
 *         - LIN_RET_SUCCESS: Response data prepared successfully
 *         - LIN_RET_STATE_ERROR: Invalid node mode or PDU type
 * @details
 * - For master nodes: Copies PDU data to transfer buffer and calculates checksum
 * - Handles TX/RX response types:
 *   - LIN_FRAMERESPONSE_TX: Copy payload data and compute checksum
 *   - LIN_FRAMERESPONSE_RX: No action (wait for received data)
 *   - Other types: Ignored (slave-to-slave communication)
 * - Resets byte counter and clears current event ID
 */
static LIN_ReturnType LIN_DrvSendResponse(LIN_XferStateType *pXfer, LIN_ConfigType *pCfg, LIN_PduType *pLinPdu)
{
    LIN_ReturnType ret   = LIN_RET_SUCCESS;
    uint8_t index;

    if (LIN_NODE_MASTER == pCfg->nodeMode)
    {
        pXfer->xferPdu.Cs = pLinPdu->Cs;
        pXfer->xferPdu.Drc = pLinPdu->Drc;
        pXfer->xferPdu.Dl    = pLinPdu->Dl;
        if (LIN_FRAMERESPONSE_TX == pXfer->xferPdu.Drc)
        {
            for (index = 0; index < pXfer->xferPdu.Dl; index++)
            {
                pXfer->xferPdu.SduPtr[index] = pLinPdu->SduPtr[index];
            }
            pXfer->checkSum = LIN_DrvMakeCheckSum(pXfer);
        }
        else if (LIN_FRAMERESPONSE_RX == pXfer->xferPdu.Drc)
        {
            /* do nothing */
        }
        else
        {
            /* slave to slave, ignore */
        }
        pXfer->cntByte = 0U;
        pXfer->curEventId = LIN_NO_EVENT;

    }
    else
    {
        /* salve node do nothing */
    }

    return ret;
}

/**
 * @brief Handle frame transmission completion interrupt.
 * @param pXfer Pointer to transfer state structure
 * @param pCfg Pointer to LIN configuration structure
 * @details Manages state transitions and hardware reset after frame transmission:
 *          - For slave nodes: Resets to idle state unless in sleep mode
 *          - For master nodes:
 *            - If in BREAK_SEND_STATE: Reads data to prevent overrun, delays for delimiter,
 *              configures FIFO watermark, sends sync byte (0x55) and PID, updates state to HEADER_SEND_STATE
 *            - Otherwise: Resets to idle state
 *          Clears transmission complete flag in status register
 */
static void LIN_DrvFrameTxHandle(LIN_XferStateType *pXfer, LIN_ConfigType *pCfg)
{
    if (LIN_NODE_SLAVE == pCfg->nodeMode)
    {
        if (LIN_FRAME_SLEEP_STATE == pXfer->curFrState)
        {
            /* need wakeup first */
        }
        else
        {
            LIN_ResetLinController(pXfer, pCfg);
        }
    }
    else
    {
        if (LIN_FRAME_BREAK_SEND_STATE == pXfer->curFrState)
        {
            /* receive data to avoid overrun error occurred */
            (void)FCUART_HWA_GetData(pXfer->base);
            /* need delay 0.1 delimiter (5~20us) !!!!!!! */
            LIN_DelayFunctionClk(pXfer, 100U);
            FCUART_HWA_SetRxWaterMark(pXfer->base, 1U);
            FCUART_HWA_SetData(pXfer->base, (uint32_t)0x55U);
            FCUART_HWA_SetData(pXfer->base, (uint32_t)pXfer->xferPdu.Pid);
            FCUART_HWA_DisableInterrupt(pXfer->base, (uint32_t)FCUART_CTRL_TCIE_MASK);
            FCUART_HWA_EnableInterrupt(pXfer->base, (uint32_t)FCUART_CTRL_RIE_MASK);
            pXfer->curFrState = LIN_FRAME_HEADER_SEND_STATE;
            pXfer->curChnState = LIN_TX_HEADER_BUSY;
        }
        else
        {
            LIN_ResetLinController(pXfer, pCfg);
        }
    }
    FCUART_HWA_WriteClearSTAT(pXfer->base, (uint32_t)FCUART_STAT_TCF_MASK);
}
/**
 * @brief Handle LIN break field reception interrupt.
 * @param pXfer Pointer to transfer state structure
 * @param pCfg Pointer to LIN configuration structure
 * @details Processes break field detection on LIN bus:
 *          - For slave nodes:
 *            - If in sleep mode: Clears event ID (no action)
 *            - If in idle mode: Reads data to clear frame error, disables break detection interrupt,
 *              enables receive interrupt, updates state to BREAK_RECV_STATE
 *            - Otherwise: Resets to idle state
 *          - For master nodes: Resets to idle state (break interrupt disabled)
 *          Clears break detect flag in status register
 */
static void LIN_DrvFrameRxBreakHandle(LIN_XferStateType *pXfer, LIN_ConfigType *pCfg)
{
    if (LIN_NODE_SLAVE == pCfg->nodeMode)
    {
        if (LIN_FRAME_SLEEP_STATE == pXfer->curFrState)
        {
            /* break field can also be used as wakeup signal */
            FCUART_HWA_SetReceiveDataInverse(pXfer->base, false);
            LIN_ResetLinController(pXfer, pCfg);
            pXfer->curEventId = LIN_WAKEUP_SIGNAL;
            pXfer->curChnState = LIN_CH_OPERATIONAL;
            if (NULL != pCfg->callback)
            {
                pCfg->callback(pXfer->u8LinChannel, pXfer->curEventId, &pXfer->xferPdu, &pXfer->checkSum);
            }
        }
        else if ((LIN_FRAME_IDLE_STATE == pXfer->curFrState))
        {
            /* receive break field will generate frame error */
            (void)FCUART_HWA_GetData(pXfer->base);
            FCUART_HWA_WriteClearSTAT(pXfer->base, (uint32_t)FCUART_STAT_FEF_MASK);
            FCUART_HWA_SetLinBreakDetectInterrupt(pXfer->base, false);
            FCUART_HWA_SetLinBreakDetectEnable(pXfer->base, false);
            FCUART_HWA_EnableInterrupt(pXfer->base, FCUART_CTRL_RIE_MASK);
            FCUART_HWA_SetRxWaterMark(pXfer->base, 1U);
            pXfer->curFrState = LIN_FRAME_BREAK_RECV_STATE;
            pXfer->curEventId = LIN_RECV_BREAK_FIELD_OK;
            pXfer->curChnState = LIN_RX_HEADER_BUSY;
            if (NULL != pCfg->callback)
            {
                pCfg->callback(pXfer->u8LinChannel, pXfer->curEventId, &pXfer->xferPdu, &pXfer->checkSum);
            }
        }
        else
        {
            /* shouldn't enter this branch */
            LIN_ResetLinController(pXfer, pCfg);
        }
    }
    else
    {
        /* in master mode, break interrupt disable */
        LIN_ResetLinController(pXfer, pCfg);
    }
    FCUART_HWA_WriteClearSTAT(pXfer->base, (uint32_t)FCUART_STAT_LBKDIF_MASK);
}

/**
 * @brief Handle header reception completion in data receive flow.
 * @param pXfer Pointer to transfer state structure
 * @param pCfg Pointer to LIN configuration structure
 * @details Configures FIFO and updates state after header reception:
 *          - For TX response type:
 *            - Sends payload data and checksum to FIFO
 *            - Sets FIFO watermark and updates state to RESPONSE_SEND_STATE
 *          - For RX response type:
 *            - Sets FIFO watermark based on payload length
 *            - Updates state to RESPONSE_RECV_STATE
 *          - Invalid response types: Reset to idle state
 */
static void LIN_DrvFrameRxData_HeaderRecvHandle(LIN_XferStateType *pXfer, LIN_ConfigType *pCfg)
{
    uint8_t index;
    if (LIN_FRAMERESPONSE_TX == pXfer->xferPdu.Drc)
    {
        for (index = 0; index < pXfer->xferPdu.Dl; index++)
        {
            FCUART_HWA_SetData(pXfer->base, (uint32_t)(pXfer->xferPdu.SduPtr[index]));
        }
        FCUART_HWA_SetData(pXfer->base, (uint32_t)pXfer->checkSum);
        FCUART_HWA_SetRxWaterMark(pXfer->base, pXfer->xferPdu.Dl);
        pXfer->curFrState = LIN_FRAME_RESPONSE_SEND_STATE;
        pXfer->curChnState = LIN_TX_RESP_BUSY;
    }
    else if (LIN_FRAMERESPONSE_RX == pXfer->xferPdu.Drc)
    {
        FCUART_HWA_SetRxWaterMark(pXfer->base, pXfer->xferPdu.Dl);
        pXfer->curFrState = LIN_FRAME_RESPONSE_RECV_STATE;
        pXfer->curChnState = LIN_RX_RESP_BUSY;
    }
    else
    {
        LIN_ResetLinController(pXfer, pCfg);
    }
}

/**
 * @brief Handle data reception during response transmission (TX mode)
 * @param pXfer Pointer to LIN transfer state structure
 * @param pCfg Pointer to LIN configuration structure
 * @param rxCnt Number of received bytes in FIFO
 * @details
 * - Validates received data against expected payload
 * - Updates FIFO watermark and continues transmission if more data is needed
 * - Checks checksum on final data byte
 * - Updates state to OK/error and triggers callback if validation passes
 * - Resets to idle state on validation failure
 */
static void LIN_DrvFrameRxData_ResponseSndHandle(LIN_XferStateType *pXfer, LIN_ConfigType *pCfg, uint8_t rxCnt)
{
    LIN_ReturnType ret = LIN_RET_SUCCESS;
    bool bFef;
    uint8_t data;
    while ((pXfer->cntByte < pXfer->xferPdu.Dl) && (rxCnt > 0U))
    {
        bFef = FCUART_HWA_GetDataWithFef(pXfer->base, &data);
        if ((bFef) || (data != pXfer->xferPdu.SduPtr[pXfer->cntByte]))
        {
            ret = LIN_RET_STATE_ERROR;
            break;
        }
        pXfer->cntByte++;
        rxCnt--;
    }

    if (LIN_RET_SUCCESS == ret)
    {
        if (rxCnt == 0U)
        {
            pXfer->curEventId = LIN_REPONSE_ERROR;
            pXfer->curChnState = LIN_TX_RESP_ERROR;
        }
        else
        {
            bFef = FCUART_HWA_GetDataWithFef(pXfer->base, &data);
            if (bFef)
            {
                pXfer->curEventId = LIN_FRAME_ERROR;
                pXfer->curChnState = LIN_TX_RESP_ERROR;
            }
            else if (pXfer->checkSum == data)
            {
                pXfer->curFrState = LIN_FRAME_RESPONSE_SEND_OK_STATE;
                if (1U == pXfer->sleepSignal)
                {
                    pXfer->curChnState = LIN_CH_SLEEP_PENDING;
                }
                else
                {
                    pXfer->curChnState = LIN_TX_RESP_OK;
                }
                pXfer->curEventId = LIN_TX_COMPLETED;
            }
            else
            {
                pXfer->curEventId = LIN_CHECKSUM_ERROR;
                pXfer->curChnState = LIN_TX_RESP_ERROR;
            }
        }
    }
    else
    {
        if (bFef)
        {
            pXfer->curEventId = LIN_FRAME_ERROR;
        }
        else
        {
            pXfer->curEventId = LIN_READBACK_ERROR;
        }
        pXfer->curChnState = LIN_TX_RESP_ERROR;
    }

    if (LIN_TX_RESP_BUSY == pXfer->curChnState)
    {
        /* do nothing */
    }
    else
    {
        if (NULL != pCfg->callback)
        {
            pCfg->callback(pXfer->u8LinChannel, pXfer->curEventId, &pXfer->xferPdu, &pXfer->checkSum);
        }

        LIN_ResetLinController(pXfer, pCfg);
    }
}

/**
 * @brief Handle data reception during response reception (RX mode)
 * @param pXfer Pointer to LIN transfer state structure
 * @param pCfg Pointer to LIN configuration structure
 * @param rxCnt Number of received bytes in FIFO
 * @details
 * - Reads received data into payload buffer
 * - Updates FIFO watermark for remaining data
 * - Checks checksum on final data byte
 * - Updates state to OK and triggers callback if reception completes
 * - Resets to idle state on reception failure
 */
static void LIN_DrvFrameRxData_ResponseRecvHandle(LIN_XferStateType *pXfer, LIN_ConfigType *pCfg, uint8_t rxCnt)
{
    bool bFef;
    uint8_t data;
    while ((pXfer->cntByte < pXfer->xferPdu.Dl) && (rxCnt > 0U))
    {
        bFef = FCUART_HWA_GetDataWithFef(pXfer->base, &data);
        if (bFef)
        {
            pXfer->curEventId = LIN_FRAME_ERROR;
            pXfer->curChnState = LIN_RX_RESP_ERROR;
            break;
        }
        else
        {
            pXfer->xferPdu.SduPtr[pXfer->cntByte] = data;
            pXfer->cntByte++;
            rxCnt--;
        }
    }


    if (LIN_RX_RESP_BUSY == pXfer->curChnState)
    {
        if (rxCnt == 0U)
        {
            pXfer->curEventId = LIN_REPONSE_ERROR;
            pXfer->curChnState = LIN_RX_RESP_ERROR;
        }
        else
        {
            bFef = FCUART_HWA_GetDataWithFef(pXfer->base, &data);
            if (bFef)
            {
                pXfer->curEventId = LIN_FRAME_ERROR;
                pXfer->curChnState = LIN_RX_RESP_ERROR;
            }
            else
            {
                pXfer->checkSum = data;
                pXfer->curFrState = LIN_FRAME_RESPONSE_RECV_OK_STATE;
                pXfer->curChnState = LIN_RX_RESP_OK;
                pXfer->curEventId = LIN_RX_COMPLETED;
            }
        }
    }

    if (LIN_RX_RESP_BUSY == pXfer->curChnState)
    {
        /* do nothing */
    }
    else
    {
        if (NULL != pCfg->callback)
        {
            pCfg->callback(pXfer->u8LinChannel, pXfer->curEventId, &pXfer->xferPdu, &pXfer->checkSum);
        }

        LIN_ResetLinController(pXfer, pCfg);
    }
}

/**
 * @brief Main handler for LIN data reception interrupts
 * @param pXfer Pointer to LIN transfer state structure
 * @param pCfg Pointer to LIN configuration structure
 * @details
 * - Checks current frame state to determine processing flow
 * - Handles break field reception (validates sync byte and PID)
 * - Handles header transmission (validates sync byte and PID)
 * - Delegates response transmission/reception to specific handlers
 * - Resets to idle state for unrecognized frame states
 * - Clears data reception flag in status register
 */
static void LIN_DrvFrameRxDataHandle(LIN_XferStateType *pXfer, LIN_ConfigType *pCfg)
{
    uint8_t rxCnt;
    uint8_t data;
    bool bFef;

    rxCnt = FCUART_HWA_GetFifoRxCount(pXfer->base);
    if (LIN_FRAME_SLEEP_STATE == pXfer->curFrState)
    {
        /* need wake-up first */
        pXfer->curEventId = LIN_NO_EVENT;
    }
    else if (LIN_FRAME_BREAK_RECV_STATE == pXfer->curFrState)
    {
        if (rxCnt >= 2U)
        {
            bFef = FCUART_HWA_GetDataWithFef(pXfer->base, &data);
            if (bFef)
            {
                pXfer->curEventId = LIN_FRAME_ERROR;
                pXfer->curChnState = LIN_RX_HEADER_ERROR;
            }
            else if (0x55U == data)
            {
                bFef = FCUART_HWA_GetDataWithFef(pXfer->base, &data);
                if (bFef)
                {
                    pXfer->curEventId = LIN_FRAME_ERROR;
                    pXfer->curChnState = LIN_RX_HEADER_ERROR;
                }
                else
                {
                    pXfer->xferPdu.Pid = data;
                    pXfer->curFrState = LIN_FRAME_HEADER_RECV_STATE;
                    pXfer->curEventId = LIN_HEADER_OK;
                    pXfer->curChnState = LIN_RX_HEADER_OK;
                }
            }
            else
            {
                pXfer->curEventId = LIN_SYNC_ERROR;
                pXfer->curChnState = LIN_RX_HEADER_ERROR;
            }
        }
        else
        {
            pXfer->curEventId = LIN_HEADER_ERROR;
            pXfer->curChnState = LIN_RX_HEADER_ERROR;
        }

        if (NULL != pCfg->callback)
        {
            pCfg->callback(pXfer->u8LinChannel, pXfer->curEventId, &pXfer->xferPdu, &pXfer->checkSum);
        }
        else
        {
            pXfer->curChnState = LIN_CALLBACK_ERROR;
        }

        if (LIN_RX_HEADER_OK == pXfer->curChnState)
        {
            LIN_DrvFrameRxData_HeaderRecvHandle(pXfer, pCfg);
        }
        else
        {
            LIN_ResetLinController(pXfer, pCfg);
        }

    }
    else if (LIN_FRAME_HEADER_SEND_STATE == pXfer->curFrState)
    {
        if (rxCnt >= 2U)
        {
            bFef = FCUART_HWA_GetDataWithFef(pXfer->base, &data);
            if (bFef)
            {
                pXfer->curEventId = LIN_FRAME_ERROR;
                pXfer->curChnState = LIN_TX_HEADER_ERROR;
            }
            else if (0x55U == data)
            {
                bFef = FCUART_HWA_GetDataWithFef(pXfer->base, &data);
                if (bFef)
                {
                    pXfer->curEventId = LIN_FRAME_ERROR;
                    pXfer->curChnState = LIN_TX_HEADER_ERROR;
                }
                else if (pXfer->xferPdu.Pid == data)
                {
                    pXfer->curEventId = LIN_HEADER_OK;
                    pXfer->curChnState = LIN_TX_HEADER_OK;
                }
                else
                {
                    pXfer->curEventId = LIN_PID_ERROR;
                    pXfer->curChnState = LIN_TX_HEADER_ERROR;
                }
            }
            else
            {
                pXfer->curEventId = LIN_SYNC_ERROR;
                pXfer->curChnState = LIN_TX_HEADER_ERROR;
            }
        }
        else
        {
            pXfer->curEventId = LIN_HEADER_ERROR;
            pXfer->curChnState = LIN_TX_HEADER_ERROR;
        }

        if (NULL != pCfg->callback)
        {
            pCfg->callback(pXfer->u8LinChannel, pXfer->curEventId, &pXfer->xferPdu, &pXfer->checkSum);
        }

        if (LIN_TX_HEADER_OK == pXfer->curChnState)
        {
            LIN_DrvFrameRxData_HeaderRecvHandle(pXfer, pCfg);
        }
        else
        {
            LIN_ResetLinController(pXfer, pCfg);
        }
    }
    else if (LIN_FRAME_RESPONSE_SEND_STATE == pXfer->curFrState)
    {
        LIN_DrvFrameRxData_ResponseSndHandle(pXfer, pCfg, rxCnt);
    }
    else if (LIN_FRAME_RESPONSE_RECV_STATE == pXfer->curFrState)
    {
        LIN_DrvFrameRxData_ResponseRecvHandle(pXfer, pCfg, rxCnt);
    }
    else
    {
        LIN_ResetLinController(pXfer, pCfg);
    }
    FCUART_HWA_WriteClearSTAT(pXfer->base, (uint32_t)FCUART_STAT_RDRFF_MASK);
}

/**
 * @brief Handle LIN controller error conditions
 * @param pXfer Pointer to LIN transfer state structure (contains current frame/channel state)
 * @param pCfg Pointer to LIN configuration structure (contains callback functions)
 * @details
 * - In sleep state: Reads data register to clear error flags
 * - In operational state:
 *   - Detects overrun errors (FCUART_STAT_RORF_MASK) and sets event ID to LIN_RX_OVERRUN
 *   - Detects frame errors (when not in break send/recv/idle states) and sets event ID to LIN_FRAME_ERROR
 * - Triggers user callback with error event ID if errors occur
 * - Resets controller to idle state after error handling
 * - Clears error flags in status register
 */
static void LIN_DrvErrorHandle(LIN_XferStateType *pXfer, LIN_ConfigType *pCfg)
{
    uint32_t u32Stat;
    uint8_t err = 0U;

    if (LIN_FRAME_SLEEP_STATE == pXfer->curFrState)
    {
        /* read data register to clear error */
        (void)FCUART_HWA_GetData(pXfer->base);
    }
    else
    {
        u32Stat = FCUART_HWA_GetSTAT(pXfer->base);
        if (u32Stat & FCUART_STAT_RORF_MASK)
        {
            pXfer->curEventId = LIN_RX_OVERRUN;
            err = 1U;
        }
        else if (u32Stat & FCUART_STAT_FEF_MASK)
        {
            if ((LIN_FRAME_BREAK_SEND_STATE != pXfer->curFrState) &&
                (LIN_FRAME_IDLE_STATE != pXfer->curFrState))
            {
                /* may receive new break field during last frame reception */
                pXfer->curEventId = LIN_FRAME_ERROR;
                err = 1U;
            }
        }
        else
        {
            /* do nothing */
        }

        if (err)
        {
            if ((LIN_FRAME_IDLE_STATE == pXfer->curFrState) ||
                (LIN_FRAME_BREAK_RECV_STATE == pXfer->curFrState) ||
                (LIN_FRAME_HEADER_RECV_STATE == pXfer->curFrState) ||
                (LIN_FRAME_RESPONSE_SEND_OK_STATE == pXfer->curFrState) ||
                (LIN_FRAME_RESPONSE_RECV_OK_STATE == pXfer->curFrState))
            {
                pXfer->curChnState = LIN_RX_HEADER_ERROR;
            }
            else if ((LIN_FRAME_BREAK_SEND_STATE == pXfer->curFrState) ||
                     (LIN_FRAME_HEADER_SEND_STATE == pXfer->curFrState))
            {
                pXfer->curChnState = LIN_TX_HEADER_ERROR;
            }
            else if (LIN_FRAME_RESPONSE_SEND_STATE == pXfer->curFrState)
            {
                pXfer->curChnState = LIN_TX_RESP_ERROR;
            }
            else if (LIN_FRAME_RESPONSE_RECV_STATE == pXfer->curFrState)
            {
                pXfer->curChnState = LIN_RX_RESP_ERROR;
            }
            else
            {
                /* do nothing */
            }

            if (NULL != pCfg->callback)
            {
                pCfg->callback(pXfer->u8LinChannel, pXfer->curEventId, &pXfer->xferPdu, &pXfer->checkSum);
            }

            /* Error occurred, enter IDLE state. */
            LIN_ResetLinController(pXfer, pCfg);
        }
    }
    (void)pCfg;
}


/**
 * @brief Handle LIN wake-up signal detection and timing calculation
 * @param pXfer Pointer to LIN transfer state structure (stores wake-up timestamp)
 * @param pCfg Pointer to LIN configuration structure (contains time callback function)
 * @details
 * - Step 1: On first receive active interrupt (low level on RX pin):
 *   - Records timestamp using user-provided time callback
 *   - Enables data inversion to detect rising edge
 * - Step 2: On second receive active interrupt (rising edge):
 *   - Disables data inversion
 *   - Recalculates timestamp and checks if interval > 150us (valid wake-up signal)
 *   - If valid: Resets to idle state, sets event ID to LIN_WAKEUP_SIGNAL, and triggers callback
 *   - If invalid: Clears stored timestamp
 * - Requires user to provide time callback via pCfg->timeCallback for accurate timing
 */
static void LIN_DrvWakeupHandle(LIN_XferStateType *pXfer, LIN_ConfigType *pCfg)
{
    uint64_t timestamp;
    /* Step 1, record the first receive active time. */
    if (false == FCUART_HWA_GetReceiveDataInverse(pXfer->base))
    {
        /* Call the user time value call function. */
        if (NULL != pCfg->timeCallback)
        {
            pCfg->timeCallback(&timestamp);
            pXfer->wakeupTime = timestamp;
        }
        else
        {
            pXfer->wakeupTime = 0U;
        }

        /* Change the receive data inverse, and receive the next interrupt. */
        FCUART_HWA_SetReceiveDataInverse(pXfer->base, true);
    }
    /* Step 2. calculate the wake-up time. */
    else
    {
        FCUART_HWA_SetReceiveDataInverse(pXfer->base, false);

        /* Call the user time value call function. */
        if (NULL != pCfg->timeCallback)
        {
            pCfg->timeCallback(&timestamp);
            if (timestamp > pXfer->wakeupTime)
            {
                if ((timestamp - pXfer->wakeupTime) > 150U)
                {
                    pXfer->curEventId = LIN_WAKEUP_SIGNAL;
                    pXfer->curChnState = LIN_CH_OPERATIONAL;
                    if (NULL != pCfg->callback)
                    {
                        pCfg->callback(pXfer->u8LinChannel, pXfer->curEventId, &pXfer->xferPdu, &pXfer->checkSum);
                    }
                    LIN_ResetLinController(pXfer, pCfg);
                }
                else
                {
                    pXfer->wakeupTime = 0U;
                }
            }
            else
            {
                pXfer->wakeupTime = 0U;
            }
        }
        else
        {
            /* do nothing */
        }
    }
}

/* ################################################################################## */
/* ################################ Global Functions ################################ */

/**
 * @brief Generate LIN PID parity bits according to LIN protocol specification
 * @param PID Input raw PID value (6-bit, without parity bits)
 * @return 8-bit PID value with parity bits (bits 6 and 7)
 * @details Calculates two parity bits:
 *          - P0 (bit 6): XOR of PID bits 0,1,2,4
 *          - P1 (bit 7): XOR of PID bits 1,3,4,5 (inverted)
 *          Combines raw PID with parity bits to form final 8-bit identifier
 */
uint8_t LIN_DrvParityMake(uint8_t PID)
{
    uint8_t parity;
    uint8_t retVal;

    parity = (uint8_t)((((0xFFU & BIT(PID, 0U)) ^ (0xFFU & BIT(PID, 1U)) ^
                         (0xFFU & BIT(PID, 2U)) ^ (0xFFU & BIT(PID, 4U))) << 6U) |
                       ((0xFFU ^ (BIT(PID, 1U)) ^ (0xFFU & BIT(PID, 3U)) ^
                         (0xFFU & BIT(PID, 4U)) ^ (0xFFU & BIT(PID, 5U))) << 7U));

    /* Making parity bits */
    retVal = (uint8_t)(PID | parity);

    return retVal;
}

/**
 * @brief Validate LIN PID parity bits according to LIN protocol specification
 * @param PID Input 8-bit PID value (with parity bits in bits 6 and 7)
 * @return Validated raw PID value (6-bit) or 0xFFU if parity check fails
 * @details Recalculates expected parity bits from input PID's data bits (0-5),
 *          compares with actual parity bits (6-7) in input PID:
 *          - If match: returns raw PID (bits 0-5)
 *          - If mismatch: returns 0xFFU (invalid PID)
 */
uint8_t LIN_DrvParityCheck(uint8_t PID)
{
    uint8_t parity;
    uint8_t retVal;

    parity = (uint8_t)((((0xFFU & BIT(PID, 0U)) ^ (0xFFU & BIT(PID, 1U)) ^
                         (0xFFU & BIT(PID, 2U)) ^ (0xFFU & BIT(PID, 4U))) << 6U) |
                       ((0xFFU ^ (BIT(PID, 1U)) ^ (0xFFU & BIT(PID, 3U)) ^
                         (0xFFU & BIT(PID, 4U)) ^ (0xFFU & BIT(PID, 5U))) << 7U));

    /* If parity bits are incorrect */
    if ((PID & 0xC0U) != parity)
    {
        retVal = 0xFFU;
    }
    else
    {
        retVal = (uint8_t)(PID & 0x3FU);
    }

    return retVal;
}

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
LIN_ReturnType LIN_DrvInit(LIN_HandleType *pLinHandle, LIN_ConfigType *pConfig)
{
    LIN_ReturnType ret         = LIN_RET_SUCCESS;
    uint32_t       baudRegVal = 0U;
    uint32_t       ctrlRegVal = 0U;
    uint32_t       statRegVal = 0U;
    uint32_t       fifoRegVal = 0U;
    uint32_t       watermarkRegVal = 0U;
    LIN_ConfigType *pCfg;
    LIN_XferStateType *pXfer;

    #if LIN_DEV_ERROR_REPORT == STD_ON
    if (LIN_RET_SUCCESS != LIN_AssertLinInit(pLinHandle, pConfig))
    {
        LIN_ReportDevError(LIN_INIT_ID, LIN_E_PARAM_POINTER);
    }
    else if (LIN_RET_SUCCESS != LIN_AssertLinHwIndex(pConfig))
    {
        LIN_ReportDevError(LIN_INIT_ID, LIN_E_PARAM_INSTANCE);
    }
    else
    #endif
    {
        pLinHandle->pCfg = pConfig;
        pLinHandle->pXfer = &pConfig->xferState;
        pCfg = pLinHandle->pCfg;
        pXfer = pLinHandle->pXfer;

        pXfer->u8LinChannel = pLinHandle->u8LinChannel;
        pXfer->base = s_aFCUART_InstanceTable[pCfg->u8LinHwIndex];

        /* Reset the hardware LIN instance to expect state. */
        FCUART_HWA_SoftwareReset(pXfer->base);

        pXfer->xferDlyCnt = (uint16_t)(pCfg->coreClkFreq / pCfg->funcClkFreq);
        ret = LIN_DrvCalBaudrate(pLinHandle, &pXfer->xferBrCfg);
        pXfer->xferBrCfg.u16OvrSamp = (uint16_t)(pXfer->xferBrCfg.u16OvrSamp - 1U);
        baudRegVal = FCUART_BAUD_OVR_SAMP(pXfer->xferBrCfg.u16OvrSamp) |
                     FCUART_BAUD_BEDGE_SAMP(1U) | FCUART_BAUD_SBR(pXfer->xferBrCfg.u16SBR);
        FCUART_HWA_SetBaud(pXfer->base, baudRegVal);

        /* Set LIN break send and detect to 13 bits minimum. If in slave node, only enable detect feature. */
        statRegVal |= FCUART_STAT_BCGL(1U) | FCUART_STAT_LBKDE(0U);
        FCUART_HWA_WriteClearSTAT(pXfer->base, statRegVal);

        fifoRegVal = FCUART_FIFO_TXFEN(1U) | FCUART_FIFO_RXFEN(1U);
        FCUART_HWA_SetFifo(pXfer->base, fifoRegVal);

        watermarkRegVal = FCUART_WATERMARK_RXWATER(0U) | FCUART_WATERMARK_TXWATER(0U);
        FCUART_HWA_SetWaterMark(pXfer->base, watermarkRegVal);

        ctrlRegVal = FCUART_CTRL_ORIE(0U) | FCUART_CTRL_NEIE(0U) | FCUART_CTRL_FEIE(0U) |
                     FCUART_CTRL_BMSEL(0U) | FCUART_CTRL_PE(0U);
        FCUART_HWA_SetCtrl(pXfer->base, ctrlRegVal);

        /* Initialize the xfer state of LIN transfer. */
        pXfer->xferPdu.SduPtr     = pXfer->xferBuff;
        pXfer->curFrState   = LIN_FRAME_SLEEP_STATE;
        pXfer->curChnState     = LIN_CH_SLEEP;

        if (LIN_NODE_SLAVE == pCfg->nodeMode)
        {
            FCUART_HWA_SetLinBreakDetectEnable(pXfer->base, true);
            FCUART_HWA_SetLinBreakDetectInterrupt(pXfer->base, true);
        }
        /* need wakeup first */
        FCUART_HWA_SetReceiveActiveInterrupt(pXfer->base, true);

        FCUART_HWA_StartTransfer(pXfer->base);
    }

    return ret;
}

/**
 * @brief De-initialize LIN controller instance.
 * @param pLinHandle Pointer to LIN handle structure
 * @details
 * - Resets FCUART hardware to default state
 * - Clears internal pointers in LIN handle (pCfg, pXfer)
 * - Disables interrupts and stops TX/RX transfer
 * @note This function does not return a status; error checking is done via LIN_DEV_ERROR_REPORT
 */
void LIN_DrvDeInit(LIN_HandleType *pLinHandle)
{
    #if LIN_DEV_ERROR_REPORT == STD_ON
    if (LIN_RET_SUCCESS != LIN_AssertLinHandle(pLinHandle))
    {
        LIN_ReportDevError(LIN_DEINIT_ID, LIN_E_PARAM_POINTER);
    }
    else if (LIN_RET_SUCCESS != LIN_AssertLinHwIndex(pLinHandle->pCfg))
    {
        LIN_ReportDevError(LIN_DEINIT_ID, LIN_E_PARAM_INSTANCE);
    }
    else
    #endif
    {
        LIN_XferStateType *pXfer = pLinHandle->pXfer;

        /* Reset the FCUART instance. */
        FCUART_HWA_SoftwareReset(pXfer->base);

        /* Update LIN instance to initialize state. */
        pLinHandle->pCfg     = NULL;
        pLinHandle->pXfer    = NULL;
    }
}

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
void LIN_DrvGetDefaultConfig(LIN_NodeType eNodeMode, LIN_ConfigType *pConfig)
{
    #if LIN_DEV_ERROR_REPORT == STD_ON
    /* Check NUll ptr for bus error. */
    if (pConfig == NULL)
    {
        LIN_ReportDevError(LIN_GET_DEFAULT_CFG_ID, LIN_E_PARAM_POINTER);
    }
    else
    #endif
    {
        pConfig->nodeMode                     = eNodeMode; /**< Node mode as Master node or Slave node. 0: slave 1: master */
        pConfig->baudRate                     = 19200U;    /**< baudrate configurations for LIN protocol. */
        pConfig->timeCallback                 = NULL;      /**< Callback function to get time interval in nanoseconds */
        pConfig->xferState.curChnState        = LIN_NOT_OK;
        pConfig->xferState.curFrState         = LIN_FRAME_SLEEP_STATE;
    }
}

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
LIN_ReturnType LIN_DrvSendFrame(LIN_HandleType *pLinHandle, LIN_PduType *pLinPdu)
{
    LIN_ReturnType ret   = LIN_RET_SUCCESS;
    LIN_ConfigType *pCfg = pLinHandle->pCfg;
    LIN_XferStateType *pXfer = pLinHandle->pXfer;

    #if LIN_DEV_ERROR_REPORT == STD_ON
    if (LIN_RET_SUCCESS != LIN_AssertLinHandle(pLinHandle))
    {
        LIN_ReportDevError(LIN_DRV_SEND_FRAME_ID, LIN_E_PARAM_POINTER);
    }
    else if (LIN_RET_SUCCESS != LIN_AssertLinHwIndex(pLinHandle->pCfg))
    {
        LIN_ReportDevError(LIN_DRV_SEND_FRAME_ID, LIN_E_PARAM_INSTANCE);
    }
    else if (LIN_RET_SUCCESS != LIN_AssertLinPdu(pLinPdu))
    {
        LIN_ReportDevError(LIN_DRV_SEND_FRAME_ID, LIN_E_PARAM_POINTER);
    }
    else
    #endif
    {
        /* Check node state. */
        if ((pXfer->curChnState < LIN_TX_HEADER_OK) || (pXfer->curChnState > LIN_CH_OPERATIONAL))
        {
            ret = LIN_RET_STATE_ERROR;
        }
        else
        {
            pXfer->sleepSignal = 0U;
            /* Update node state. */
            pXfer->xferPdu.Pid = pLinPdu->Pid;
            pXfer->curEventId   = LIN_NO_EVENT;

            /* if master node, prepare send buffer first */
            ret = LIN_DrvSendResponse(pXfer, pCfg, pLinPdu);
            if ((LIN_RET_SUCCESS == ret) && (LIN_NODE_MASTER == pCfg->nodeMode))
            {
                (void)LIN_DrvSendHeader(pXfer);
                pXfer->curChnState  = LIN_TX_HEADER_BUSY;
            }
        }
    }
    return ret;
}

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
LIN_ReturnType LIN_DrvGoToSleep(LIN_HandleType *pLinHandle)
{
    LIN_ReturnType ret   = LIN_RET_SUCCESS;
    LIN_XferStateType *pXfer = pLinHandle->pXfer;
    uint8_t index;

    #if LIN_DEV_ERROR_REPORT == STD_ON
    if (LIN_RET_SUCCESS != LIN_AssertLinHandle(pLinHandle))
    {
        LIN_ReportDevError(LIN_DRV_GOTO_SLEEP_ID, LIN_E_PARAM_POINTER);
    }
    else if (LIN_RET_SUCCESS != LIN_AssertLinHwIndex(pLinHandle->pCfg))
    {
        LIN_ReportDevError(LIN_DRV_GOTO_SLEEP_ID, LIN_E_PARAM_INSTANCE);
    }
    else if (LIN_RET_SUCCESS != LIN_AssertMasterApi(pLinHandle, LIN_DRV_GOTO_SLEEP_ID))
    {
        LIN_ReportDevError(LIN_DRV_GOTO_SLEEP_ID, LIN_E_PARAM_ERROR_CALL);
    }
    else
    #endif
    {
        /* Check node state. */
        if ((pXfer->curChnState < LIN_TX_HEADER_OK) || (pXfer->curChnState > LIN_CH_OPERATIONAL))
        {
            ret = LIN_RET_STATE_ERROR;
        }
        else
        {
            /* Update node state. */
            pXfer->xferPdu.Pid = 0x3C;
            pXfer->xferPdu.Drc = LIN_FRAMERESPONSE_TX;
            pXfer->xferPdu.Dl = 8U;
            pXfer->xferPdu.SduPtr[0U] = 0x00U;
            for (index = 1U; index < pXfer->xferPdu.Dl; index++)
            {
                pXfer->xferPdu.SduPtr[index] = 0xFF;
            }
            pXfer->checkSum = 0x00U;

            pXfer->cntByte = 0U;
            pXfer->curEventId   = LIN_NO_EVENT;

            /* if master node, prepare send buffer first */
            ret = LIN_DrvSendHeader(pXfer);
            pXfer->sleepSignal = 1U;
            pXfer->curChnState = LIN_TX_HEADER_BUSY;

        }
    }
    return ret;
}

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
LIN_ReturnType LIN_DrvGoToSleepInternal(LIN_HandleType *pLinHandle)
{
    LIN_ReturnType ret   = LIN_RET_SUCCESS;
    LIN_XferStateType *pXfer = pLinHandle->pXfer;
    uint32_t ctrlRegVal;

    #if LIN_DEV_ERROR_REPORT == STD_ON
    if (LIN_RET_SUCCESS != LIN_AssertLinHandle(pLinHandle))
    {
        LIN_ReportDevError(LIN_DRV_GOTO_SLEEP_INTERNAL_ID, LIN_E_PARAM_POINTER);
    }
    else if (LIN_RET_SUCCESS != LIN_AssertLinHwIndex(pLinHandle->pCfg))
    {
        LIN_ReportDevError(LIN_DRV_GOTO_SLEEP_INTERNAL_ID, LIN_E_PARAM_INSTANCE);
    }
    else
    #endif
    {
        /* Check node state. */
        if ((pXfer->curChnState < LIN_TX_HEADER_OK) || (pXfer->curChnState > LIN_CH_OPERATIONAL))
        {
            ret = LIN_RET_STATE_ERROR;
        }
        else
        {
            ctrlRegVal = FCUART_CTRL_ORIE(0U) | FCUART_CTRL_NEIE(0U) | FCUART_CTRL_FEIE(0U) | \
                         FCUART_CTRL_TE(0U) | FCUART_CTRL_RE(0U);
            FCUART_HWA_SetCtrl(pXfer->base, ctrlRegVal);
            LIN_DelayFunctionClk(pXfer, 2U);
            FCUART_HWA_FlushTxRxFifo(pXfer->base);
            ctrlRegVal = FCUART_CTRL_ORIE(0U) | FCUART_CTRL_NEIE(0U) | FCUART_CTRL_FEIE(0U) | \
                         FCUART_CTRL_TE(1U) | FCUART_CTRL_RE(1U);
            FCUART_HWA_SetCtrl(pXfer->base, ctrlRegVal);
            LIN_DelayFunctionClk(pXfer, 2U);

            (void)FCUART_HWA_GetData(pXfer->base);

            pXfer->cntByte = 0U;
            pXfer->curEventId   = LIN_NO_EVENT;
            pXfer->curFrState = LIN_FRAME_SLEEP_STATE;
            pXfer->curChnState = LIN_CH_SLEEP;

            FCUART_HWA_SetReceiveActiveInterrupt(pXfer->base, true);
        }
    }
    return ret;
}

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
LIN_ReturnType LIN_DrvWakeup(LIN_HandleType *pLinHandle)
{
    LIN_ReturnType ret   = LIN_RET_SUCCESS;
    LIN_ConfigType *pCfg = pLinHandle->pCfg;
    LIN_XferStateType *pXfer = pLinHandle->pXfer;
    uint32_t ctrlRegVal;
    uint32_t statRegVal;

    #if LIN_DEV_ERROR_REPORT == STD_ON
    if (LIN_RET_SUCCESS != LIN_AssertLinHandle(pLinHandle))
    {
        LIN_ReportDevError(LIN_DRV_WAKEUP_ID, LIN_E_PARAM_POINTER);
    }
    else if (LIN_RET_SUCCESS != LIN_AssertLinHwIndex(pLinHandle->pCfg))
    {
        LIN_ReportDevError(LIN_DRV_WAKEUP_ID, LIN_E_PARAM_INSTANCE);
    }
    else
    #endif
    {

        /* Check node state. */
        if (LIN_NOT_OK == pXfer->curChnState)
        {
            ret = LIN_RET_NOT_INIT;
        }
        else if ((LIN_CH_SLEEP == pXfer->curChnState) || (LIN_CH_SLEEP_PENDING == pXfer->curChnState))
        {
            ctrlRegVal = FCUART_CTRL_ORIE(1U) | FCUART_CTRL_NEIE(0U) | FCUART_CTRL_FEIE(1U) | \
                         FCUART_CTRL_TE(0U) | FCUART_CTRL_RE(0U);
            FCUART_HWA_SetCtrl(pXfer->base, ctrlRegVal);
            LIN_DelayFunctionClk(pXfer, 2U);

            FCUART_HWA_FlushTxRxFifo(pXfer->base);

            ctrlRegVal = FCUART_CTRL_ORIE(1U) | FCUART_CTRL_NEIE(0U) | FCUART_CTRL_FEIE(1U) | \
                         FCUART_CTRL_TE(1U) | FCUART_CTRL_RE(1U);
            FCUART_HWA_SetCtrl(pXfer->base, ctrlRegVal);
            LIN_DelayFunctionClk(pXfer, 2U);

            FCUART_HWA_SetReceiveActiveInterrupt(pXfer->base, false);
            /* clear register status flag */
            statRegVal = FCUART_HWA_GetSTAT(pXfer->base);
            FCUART_HWA_WriteClearSTAT(pXfer->base, statRegVal);

            pXfer->sleepSignal = 0U;

            if (LIN_NODE_SLAVE == pCfg->nodeMode)
            {
                FCUART_HWA_SetLinBreakDetectEnable(pXfer->base, true);
                FCUART_HWA_SetLinBreakDetectInterrupt(pXfer->base, true);
            }

            if (pCfg->baudRate > 10000U)
            {
                /* Wakeup signal will be range from 400us to 800us depend on baudrate, 0x80U */
                FCUART_HWA_SetData(pXfer->base, 0x00U);
            }
            else
            {
                /* Wakeup signal will be range from 400us to 4ms depend on baudrate, 0xF8U */
                FCUART_HWA_SetData(pXfer->base, 0xF8U);
            }
            pXfer->curChnState = LIN_CH_OPERATIONAL;
            pXfer->curFrState = LIN_FRAME_IDLE_STATE;
            pXfer->curEventId = LIN_NO_EVENT;
        }
        else
        {
            /* already wake-up */
        }

    }
    return ret;
}

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
LIN_ReturnType LIN_DrvWakeupInternal(LIN_HandleType *pLinHandle)
{
    LIN_ReturnType ret   = LIN_RET_SUCCESS;
    LIN_XferStateType *pXfer = pLinHandle->pXfer;
    LIN_ConfigType *pCfg = pLinHandle->pCfg;
    uint32_t ctrlRegVal;
    uint32_t statRegVal;

    #if LIN_DEV_ERROR_REPORT == STD_ON
    if (LIN_RET_SUCCESS != LIN_AssertLinHandle(pLinHandle))
    {
        LIN_ReportDevError(LIN_DRV_WAKEUP_INTERNAL_ID, LIN_E_PARAM_POINTER);
    }
    else if (LIN_RET_SUCCESS != LIN_AssertLinHwIndex(pLinHandle->pCfg))
    {
        LIN_ReportDevError(LIN_DRV_WAKEUP_INTERNAL_ID, LIN_E_PARAM_INSTANCE);
    }
    else
    #endif
    {
        /* Check node state. */
        if (LIN_NOT_OK == pXfer->curChnState)
        {
            ret = LIN_RET_NOT_INIT;
        }
        else if ((LIN_CH_SLEEP == pXfer->curChnState) || (LIN_CH_SLEEP_PENDING == pXfer->curChnState))
        {
            ctrlRegVal = FCUART_CTRL_ORIE(1U) | FCUART_CTRL_NEIE(0U) | FCUART_CTRL_FEIE(1U) | \
                         FCUART_CTRL_TE(0U) | FCUART_CTRL_RE(0U);
            FCUART_HWA_SetCtrl(pXfer->base, ctrlRegVal);
            LIN_DelayFunctionClk(pXfer, 2U);

            FCUART_HWA_FlushTxRxFifo(pXfer->base);

            ctrlRegVal = FCUART_CTRL_ORIE(1U) | FCUART_CTRL_NEIE(0U) | FCUART_CTRL_FEIE(1U) | \
                         FCUART_CTRL_TE(1U) | FCUART_CTRL_RE(1U);
            FCUART_HWA_SetCtrl(pXfer->base, ctrlRegVal);
            LIN_DelayFunctionClk(pXfer, 2U);

            FCUART_HWA_SetReceiveActiveInterrupt(pXfer->base, false);
            /* clear register status flag */
            statRegVal = FCUART_HWA_GetSTAT(pXfer->base);
            FCUART_HWA_WriteClearSTAT(pXfer->base, statRegVal);



            if (LIN_NODE_SLAVE == pCfg->nodeMode)
            {
                FCUART_HWA_SetLinBreakDetectEnable(pXfer->base, true);
                FCUART_HWA_SetLinBreakDetectInterrupt(pXfer->base, true);
            }
            pXfer->curChnState = LIN_CH_OPERATIONAL;
            pXfer->curFrState = LIN_FRAME_IDLE_STATE;
            pXfer->curEventId = LIN_NO_EVENT;
        }
        else
        {
            /* already wake-up */
        }

    }
    return ret;
}

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
LIN_StatusType LIN_DrvGetStatus(LIN_HandleType *pLinHandle)
{
    LIN_StatusType status;
    LIN_XferStateType *pXfer = pLinHandle->pXfer;

    #if LIN_DEV_ERROR_REPORT == STD_ON
    if (LIN_RET_SUCCESS != LIN_AssertLinHandle(pLinHandle))
    {
        LIN_ReportDevError(LIN_DRV_GET_STATUS_ID, LIN_E_PARAM_POINTER);
    }
    else if (LIN_RET_SUCCESS != LIN_AssertLinHwIndex(pLinHandle->pCfg))
    {
        LIN_ReportDevError(LIN_DRV_GET_STATUS_ID, LIN_E_PARAM_INSTANCE);
    }
    else
    #endif
    {
        if (LIN_CH_SLEEP_PENDING == pXfer->curChnState)
        {
            pXfer->curChnState = LIN_CH_SLEEP;
        }
        status = pXfer->curChnState;

    }
    return status;
}

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
LIN_ReturnType LIN_DrvAbortTransfer(LIN_HandleType *pLinHandle)
{
    LIN_ReturnType ret   = LIN_RET_SUCCESS;
    LIN_XferStateType *pXfer = pLinHandle->pXfer;
    LIN_ConfigType *pCfg = pLinHandle->pCfg;
    uint32_t ctrlRegVal;
    uint32_t statRegVal;

    /* Error reporting section (conditionally compiled) */
    #if LIN_DEV_ERROR_REPORT == STD_ON
    if (LIN_RET_SUCCESS != LIN_AssertLinHandle(pLinHandle))
    {
        LIN_ReportDevError(LIN_DRV_ABORT_TRANSFER_ID, LIN_E_PARAM_POINTER);
    }
    else if (LIN_RET_SUCCESS != LIN_AssertLinHwIndex(pLinHandle->pCfg))
    {
        LIN_ReportDevError(LIN_DRV_ABORT_TRANSFER_ID, LIN_E_PARAM_INSTANCE);
    }
    else
    #endif
    {
        /* Validate current transfer state */
        if ((pXfer->curChnState < LIN_TX_HEADER_OK) || (pXfer->curChnState > LIN_CH_OPERATIONAL))
        {
            ret = LIN_RET_STATE_ERROR;
        }
        else
        {
            ctrlRegVal = FCUART_CTRL_ORIE(1U) | FCUART_CTRL_NEIE(0U) | FCUART_CTRL_FEIE(1U) | \
                         FCUART_CTRL_TE(0U) | FCUART_CTRL_RE(0U);
            FCUART_HWA_SetCtrl(pXfer->base, ctrlRegVal);
            LIN_DelayFunctionClk(pXfer, 2U);

            /* Flush hardware FIFOs */
            FCUART_HWA_FlushTxRxFifo(pXfer->base);

            ctrlRegVal = FCUART_CTRL_ORIE(1U) | FCUART_CTRL_NEIE(0U) | FCUART_CTRL_FEIE(1U) | \
                         FCUART_CTRL_TE(1U) | FCUART_CTRL_RE(1U);
            FCUART_HWA_SetCtrl(pXfer->base, ctrlRegVal);
            LIN_DelayFunctionClk(pXfer, 2U);

            /* Disable receive active interrupt */
            FCUART_HWA_SetReceiveActiveInterrupt(pXfer->base, false);

            /* Clear all pending status flags */
            statRegVal = FCUART_HWA_GetSTAT(pXfer->base);
            FCUART_HWA_WriteClearSTAT(pXfer->base, statRegVal);



            /* Special handling for slave nodes */
            if (LIN_NODE_SLAVE == pCfg->nodeMode)
            {
                /* Re-enable break detection for next frame */
                FCUART_HWA_SetLinBreakDetectEnable(pXfer->base, true);
                FCUART_HWA_SetLinBreakDetectInterrupt(pXfer->base, true);
            }

            /* Reset state machines */
            pXfer->curChnState = LIN_CH_OPERATIONAL;  // Set channel to operational
            pXfer->curFrState = LIN_FRAME_IDLE_STATE; // Reset frame state machine
            pXfer->curEventId = LIN_NO_EVENT;         // Clear pending events
        }
    }
    return ret;
}

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
void LIN_DrvIRQHandler(LIN_HandleType *pLinHandle)
{
    LIN_ConfigType *pCfg = pLinHandle->pCfg;
    LIN_XferStateType *pXfer = pLinHandle->pXfer;
    uint32_t u32Ctrl = FCUART_HWA_GetCtrl(pXfer->base);
    uint32_t u32Stat = FCUART_HWA_GetSTAT(pXfer->base);
    uint32_t u32Baud = FCUART_HWA_GetBaud(pXfer->base);

    #if LIN_DEV_ERROR_REPORT == STD_ON
    if (LIN_RET_SUCCESS != LIN_AssertLinHandle(pLinHandle))
    {
        LIN_ReportDevError(LIN_DRV_IRQ_HANDLE, LIN_E_PARAM_POINTER);
    }
    else if (LIN_RET_SUCCESS != LIN_AssertLinHwIndex(pLinHandle->pCfg))
    {
        LIN_ReportDevError(LIN_DRV_IRQ_HANDLE, LIN_E_PARAM_INSTANCE);
    }
    else
    #endif
    {
        /* Handle the wake-up feature by protocol. */
        if ((u32Baud & FCUART_BAUD_RIAEIE_MASK) && (u32Stat & FCUART_STAT_RPAEIF_MASK))
        {
            LIN_DrvWakeupHandle(pXfer, pCfg);
        }
        else if ((u32Ctrl & FCUART_CTRL_TCIE_MASK) && (u32Stat & FCUART_STAT_TCF))
        {
            LIN_DrvFrameTxHandle(pXfer, pCfg);
        }
        else if ((u32Baud & FCUART_BAUD_LBKDIE_MASK) && (u32Stat & FCUART_STAT_LBKDIF_MASK))
        {
            LIN_DrvFrameRxBreakHandle(pXfer, pCfg);
        }
        else if ((u32Ctrl & FCUART_CTRL_RIE_MASK) && (u32Stat & FCUART_STAT_RDRFF_MASK))
        {
            LIN_DrvFrameRxDataHandle(pXfer, pCfg);
        }
        /* Handle error status. */
        else
        {
            LIN_DrvErrorHandle(pXfer, pCfg);
        }

        /* read again to avoid set unexpected bits, clear all interrupt flag */
        u32Stat = FCUART_HWA_GetSTAT(pXfer->base);
        FCUART_HWA_WriteClearSTAT(pXfer->base, u32Stat);
    }
}

#endif
