/**
 * @file module_driver_ospi.c
 * @author Flagchip
 * @brief OSPI driver type definition and API
 * @version 2.0.0
 * @date 2023-08-02
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
*   0.1.0       2023-01-30    Flagchip087   N/A          First version for FC7300
*   0.2.0       2023-08-02    Flagchip100    N/A          Adjust the OSPI driver framework.
*   0.3.0       2024-08-27    Flagchip122    N/A          FC7xxx sdk 2.0
******************************************************************************** */

#include "module_driver_ospi.h"

#if OSPI_INSTANCE_COUNT > 0U

/********* Local variable ************/
#define OSPI_LUT_KEY_VAL (0xFC03FC03UL)

#ifndef OSPI_DEV_ERROR_REPORT
#define OSPI_DEV_ERROR_REPORT    STD_OFF
#endif

#if OSPI_DEV_ERROR_REPORT == STD_ON
#define OSPI_ReportDevError(func, error) ReportDevError(OSPI_MODULE_ID, func, error)
#endif

/********* Global Functions ************/
/**
 * @brief Initialize OSPI configuration
 *
 * @param base OSPI peripheral base address
 * @param config the basic configurations of the OSPI
 */
void OSPI_Init(OSPI_Type *base, const OSPI_ConfigType *const pConfig)
{
#if OSPI_DEV_ERROR_REPORT == STD_ON
    if(pConfig == NULL_PTR )
    {
        OSPI_ReportDevError(OSPI_INIT_ID, OSPI_E_PARAM_POINTER);
    }
    else if((pConfig->bDdrEn == true) && (pConfig->eDqsSrcSel != DQS_EXTERNAL_PADINPUT))
    {
        OSPI_ReportDevError(OSPI_INIT_ID, OSPI_E_PARAM_INVALID);
    }
    else
    {
#endif

        OSPI_HWA_SetCtrlValue(base,CTRL_RST_VALUE);
        OSPI_HWA_SetSocCfgValue(base, 0U);
        OSPI_HWA_ModuleDisable(base);

        OSPI_HWA_InternalRefclkDiv(base, pConfig->eClkDivider);
        OSPI_HWA_InternalRefclkSource(base, pConfig->eClkMux);
        OSPI_HWA_EndianSelect(base, pConfig->eEndian);
        OSPI_HWA_PadIbeEnable(base);
        OSPI_HWA_InternalRefclkEnable(base);
        OSPI_HWA_DqsInvertedEnable(base);
        OSPI_HWA_DqsSource(base, pConfig->eDqsSrcSel);
        OSPI_HWA_DqsModeEnable(base);
        if (pConfig->eDqsSrcSel == DQS_EXTERNAL_PADINPUT)
        {
            if (pConfig->bDdrEn)
            {
                OSPI_HWA_DdrClkEnable(base);
                OSPI_HWA_DdrModeEnable(base);
            }
            OSPI_HWA_ObeTimRelaxEnable(base);

            OSPI_HWA_DqsOutEnable(base);
            OSPI_HWA_DqsLatEnable(base);

            OSPI_HWA_Dio3DefLow(base);
            OSPI_HWA_Dio2DefLow(base);

            OSPI_HWA_SetDataHoldTime(base, 1);
        }
        else if (pConfig->eDqsSrcSel == DQS_PAD_LOOPBACK)
        {
            OSPI_HWA_SetSampleDlyClkCycle(base, 0);
            OSPI_HWA_SelectRefClkEdge(base, 1);
        }
        else
        {
        }

        OSPI_HWA_ModuleEnable(base);
        OSPI_HWA_ClearTxFifo(base);

#if OSPI_DEV_ERROR_REPORT == STD_ON
    }
#endif
}

/**
 * @brief Get OSPI configuration
 *
 * @param config the basic configurations of the OSPI
 */
void OSPI_GetDefaultConfig(OSPI_ConfigType *config)
{
    config->bDdrEn      = true;
    config->eDqsSrcSel  = DQS_EXTERNAL_PADINPUT;
    config->eClkDivider = OSPI_CLOCK_DIV_4;
    config->eClkMux     = OSPI_MUX_PLL1;
    config->eEndian     = OSPI_LITTLE_ENDIAN;
}

/**
 * @brief De-initialize the OSPI 
 *
 * @param base OSPI peripheral base address
 */
void OSPI_DeInit(OSPI_Type *base)
{
    /* Set register to reset value */
    OSPI_HWA_SetCtrlValue(base, CTRL_RST_VALUE);
    OSPI_HWA_SetSocCfgValue(base, 0);
    OSPI_HWA_ModuleDisable(base);
}

/**
 * @brief OSPI Config Flash Parameter
 *
 * @param base OSPI peripheral base address
 * @param pConfig the basic configurations of the OSPI
 */
void OSPI_FlashConfig(OSPI_Type *base, OSPI_DeviceConfigType *pConfig)
{   
#if OSPI_DEV_ERROR_REPORT == STD_ON
    if(pConfig == NULL_PTR)
    {
        OSPI_ReportDevError(OSPI_SET_FLASHCFG_ID, OSPI_E_PARAM_POINTER);
    }
    else if( (pConfig->u8CsHoldTime > (uint8_t)16) ||
        (pConfig->u8CsSetupTime > (uint8_t)16) ||
        (pConfig->u8FlashColAddressSpace > (uint8_t)16) )
    {
        OSPI_ReportDevError(OSPI_SET_FLASHCFG_ID, OSPI_E_PARAM_INVALID);
    }
    else
    {
#endif
        OSPI_HWA_SetCsHoldTime(base, pConfig->u8CsHoldTime);
        OSPI_HWA_SetCsSetupTime(base, pConfig->u8CsSetupTime);
        OSPI_HWA_CfgDelayLine(base, pConfig->u8DelayLine);

        OSPI_HWA_SetFlashAddr(base, pConfig->u32FlashAddress);
        OSPI_HWA_SetFlashTopAddr(base, pConfig->u32FlashTopAddress);
        OSPI_HWA_SetFlashAddrMode(base, pConfig->u8WordAddressable);
        OSPI_HWA_SetColAddrSpace(base, pConfig->u8FlashColAddressSpace);
#if OSPI_DEV_ERROR_REPORT == STD_ON
    }
#endif
}

/**
 * @brief OSPI Config LUT
 *
 * @param base OSPI peripheral base address
 * @param index index to be written
 * @param cmd Command sequence array
 * @param count Number of sequences
 *
 */
void OSPI_UpdateLUT(OSPI_Type *base, uint32_t index, const uint32_t *cmd, uint32_t count)
{
#if OSPI_DEV_ERROR_REPORT == STD_ON
    if(cmd == NULL_PTR)
    {
        OSPI_ReportDevError(OSPI_UPDATE_LUT_ID, OSPI_E_PARAM_POINTER);
    }
    else if((count > 16U) || (index >3U))
    {
        OSPI_ReportDevError(OSPI_UPDATE_LUT_ID, OSPI_E_PARAM_INVALID);
    }
    else
    {
#endif
        uint8_t i = 0;
        volatile uint32_t *lutBase;

        /* Wait for bus idle before change flash configuration. */
        if (OSPI_Wait_Bus_Idle(base) != OSPI_STATUS_SUCCESS)
        {
            return;
        }

        /* Unlock LUT for update. */
        base->LUT_KEY = OSPI_LUT_KEY_VAL;
        base->LUT_CFG = 0x02;

        lutBase = &base->LUT[index*4];
        for (i = 0; i < count; i++)
        {
            *lutBase = *cmd;
            lutBase++;
            cmd++;
        }

        /* Lock LUT. */
        base->LUT_KEY = OSPI_LUT_KEY_VAL;
        base->LUT_CFG = 0x01;
#if OSPI_DEV_ERROR_REPORT == STD_ON
    }
#endif
}

/**
 * @brief OSPI Wait bus command transaction done
 *
 * @param base OSPI peripheral base address
 * @return OSPI_StatusType whether the operation is successfully
 */
OSPI_StatusType OSPI_Wait_Cmd_Done(OSPI_Type *base)
{
    OSPI_StatusType eRet = OSPI_STATUS_TIMEOUT;
    uint32_t timeout = 0xfffff;
    do
    {
        if ((OSPI_HWA_GetFlag(base) & OSPI_FLAG_BUSDF_MASK ) != (uint32_t)0)
        {
            OSPI_HWA_ClearFlag(base, OSPI_FLAG_BUSDF_MASK);
            eRet = OSPI_STATUS_SUCCESS;
            break;
        }
        timeout--;
    }
    while(timeout);

    return eRet;
}

/**
 * @brief OSPI Wait bus command transaction done
 *
 * @param base OSPI peripheral base address
 * @return OSPI_StatusType whether the operation is successfully
 */
OSPI_StatusType OSPI_Wait_Bus_Idle(OSPI_Type *base)
{
    OSPI_StatusType eRet = OSPI_STATUS_TIMEOUT;
    uint32_t timeout = 0xfffff;
    do
    {
        if ((OSPI_HWA_GetStatus(base) & OSPI_STATUS_BUSY_MASK) == (uint32_t)0)
        {
            eRet = OSPI_STATUS_SUCCESS;
            break;
        }
        timeout--;
    }
    while(timeout);

    return eRet;
}

/**
 * @brief OSPI write fifo，fifo size is 16words.
 *
 * @param base OSPI peripheral base address
 * @param u8SeqId the cmd id location in lut.
 * @param pBuf the write buffer start address.
 * @param u16Size fifo size to be written.
 * @return OSPI_StatusType whether the operation is successfully
 */
OSPI_StatusType OSPI_Write_Fifo(OSPI_Type *base, uint8_t u8SeqId, uint32_t *pBuf, uint16_t u16Size)
{
#if OSPI_DEV_ERROR_REPORT == STD_ON
    if(pBuf == NULL_PTR)
    {
        OSPI_ReportDevError(OSPI_WRITE_FIFO_ID, OSPI_E_PARAM_POINTER);
    }
    else if(u8SeqId > 3U)
    {
        OSPI_ReportDevError(OSPI_WRITE_FIFO_ID, OSPI_E_PARAM_INVALID);
    }
    else
    {
#endif
        OSPI_StatusType eRet = OSPI_STATUS_SUCCESS;
        uint8_t u8LoopI, u8LoopMax;

        /* Data Register is 32-bit, so loop should div 4 */
        u8LoopMax = (uint8_t)u16Size >> 2;
        for (u8LoopI = 0; u8LoopI < u8LoopMax; u8LoopI++)
        {
            OSPI_HWA_WriteTxData(base, pBuf[u8LoopI]);
        }
        OSPI_HWA_SetCmdIdSize(base, u8SeqId, u16Size);

        eRet = OSPI_Wait_Cmd_Done(base);
        if (eRet == OSPI_STATUS_SUCCESS)
        {
            eRet = OSPI_Wait_Bus_Idle(base);
        }

        return eRet;
#if OSPI_DEV_ERROR_REPORT == STD_ON
    }
#endif
}

/**
 * @brief OSPI read fifo，fifo size is 16words.
 *
 * @param base OSPI peripheral base address
 * @param u8SeqId the cmd id location in lut.
 * @param pBuf the read buffer start address.
 * @param u32Size fifo size to be read.
 * @return OSPI_StatusType whether the operation is successfully
 */
OSPI_StatusType OSPI_Read_Fifo(OSPI_Type *base, uint8_t u8SeqId, uint32_t *pBuf, uint16_t u16Size)
{
#if OSPI_DEV_ERROR_REPORT == STD_ON
    if(pBuf == NULL_PTR)
    {
        OSPI_ReportDevError(OSPI_READ_FIFO_ID, OSPI_E_PARAM_POINTER);
    }
    else if(u8SeqId > 3U)
    {
        OSPI_ReportDevError(OSPI_READ_FIFO_ID, OSPI_E_PARAM_INVALID);
    }
    else
    {
#endif
        OSPI_StatusType eRet = OSPI_STATUS_SUCCESS;
        uint8_t u8LoopI, u8LoopMax;

        OSPI_HWA_SetCmdIdSize(base, u8SeqId, u16Size);
        eRet = OSPI_Wait_Cmd_Done(base);

        if (eRet == OSPI_STATUS_SUCCESS)
        {
            u8LoopMax = OSPI_HWA_GetRxFifoFillLevel(base);
            for (u8LoopI = 0; u8LoopI < u8LoopMax; u8LoopI++)
            {
                pBuf[u8LoopI] = OSPI_HWA_ReadSecondaryRcvFifoReg(base);
            }
        }

        return eRet;
#if OSPI_DEV_ERROR_REPORT == STD_ON
    }
#endif
}

/**
 * @brief OSPI write sequence data.
 *
 * @param base OSPI peripheral base address
 * @param xfer pointer to the transfer structure
 * @return OSPI_StatusType whether the operation is successfully
 */
OSPI_StatusType OSPI_TransferBlocking(OSPI_Type *base, OSPI_TransferType *xfer)
{
#if OSPI_DEV_ERROR_REPORT == STD_ON
    if(xfer == NULL_PTR)
    {
        OSPI_ReportDevError(OSPI_TRANSFER_BLOCKING_ID, OSPI_E_PARAM_POINTER);
    }
    else
    {
#endif
        OSPI_StatusType eRet = OSPI_STATUS_SUCCESS;
        uint32_t u32TotalSize = xfer->dataSize;
        uint32_t u32BaseAddr  = xfer->deviceAddress;
        uint32_t u32LoopCounter = 0;
        uint32_t u32CurrentSize = 0;

        if (xfer->cmdType == OSPI_OPERATION_WRITE)
        {
            while (u32TotalSize > 0)
            {
                OSPI_HWA_SetFlashAddr(base, u32BaseAddr + u32LoopCounter * OSPI_ONE_TRANSFER_SIZE_MAX);
                u32CurrentSize = u32TotalSize > OSPI_ONE_TRANSFER_SIZE_MAX ? OSPI_ONE_TRANSFER_SIZE_MAX : u32TotalSize;
                eRet = OSPI_Write_Fifo(base, xfer->seqIndex, xfer->data + u32LoopCounter * OSPI_FIFO_DEPTH_MAX, (uint16_t)u32CurrentSize);

                if (eRet == OSPI_STATUS_SUCCESS)
                {
                    u32TotalSize -= u32CurrentSize;
                    u32LoopCounter++;
                }
                else
                {
                    break;
                }
            }
        }
        else if (xfer->cmdType == OSPI_OPERATION_READ)
        {
            while (u32TotalSize > 0)
            {
                OSPI_HWA_SetFlashAddr(base, u32BaseAddr + u32LoopCounter * OSPI_ONE_TRANSFER_SIZE_MAX);
                u32CurrentSize = u32TotalSize > OSPI_ONE_TRANSFER_SIZE_MAX ? OSPI_ONE_TRANSFER_SIZE_MAX : u32TotalSize;
                eRet = OSPI_Read_Fifo(base, xfer->seqIndex, xfer->data + u32LoopCounter * OSPI_FIFO_DEPTH_MAX, (uint16_t)u32CurrentSize);

                if (eRet == OSPI_STATUS_SUCCESS)
                {
                    u32TotalSize -= u32CurrentSize;
                    u32LoopCounter++;
                }
                else
                {
                    break;
                }
            }
        }
        else
        {

        }

        return eRet;
#if OSPI_DEV_ERROR_REPORT == STD_ON
    }
#endif
}

OSPI_StatusType OSPI_TransferNonBlocking(OSPI_Type *base, OSPI_TransferType *xfer)
{
#if OSPI_DEV_ERROR_REPORT == STD_ON
    if(xfer == NULL_PTR)
    {
        OSPI_ReportDevError(OSPI_TRANSFER_NONBLOCKING_ID, OSPI_E_PARAM_POINTER);
    }
    else
    {
#endif
        OSPI_StatusType eRet = OSPI_STATUS_SUCCESS;

        if ((xfer->cmdType == OSPI_OPERATION_WRITE) || (xfer->cmdType == OSPI_OPERATION_READ))
        {
            OSPI_HWA_SetFlashAddr(base, xfer->deviceAddress);
            OSPI_HWA_SetCmdIdSize(base, xfer->seqIndex, xfer->dataSize);
        }
        else
        {

        }

        return eRet;
#if OSPI_DEV_ERROR_REPORT == STD_ON
    }
#endif
}

void OSPI_DriverIRQHandler(OSPI_Type *base)
{
    (void)base;
}

#endif /* #if OSPI_INSTANCE_COUNT > 0U */
