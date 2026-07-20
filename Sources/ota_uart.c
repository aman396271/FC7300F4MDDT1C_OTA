#include "ota_uart.h"

#define OTA_UART_RING_SIZE (2048UL)

static FCUART_HandleType *s_uart;
static FCUART_DataType s_rx_message;
static uint8_t s_rx_driver_buffer[FCUART_FIFO_DEPTH];
static volatile uint8_t s_ring[OTA_UART_RING_SIZE];
static volatile uint32_t s_head;
static volatile uint32_t s_tail;
static volatile uint32_t s_overflow_count;

_Static_assert((OTA_UART_RING_SIZE & (OTA_UART_RING_SIZE - 1UL)) == 0UL,
               "UART ring size must be a power of two");

static void ota_uart_rx_notify(FCUART_HandleType *handle, FCUART_DataType *message)
{
    uint32_t index;
    (void)handle;

    if ((message == 0) || (message->pDatas == 0))
    {
        return;
    }
    for (index = 0UL; index < message->u32DataLen; ++index)
    {
        uint32_t next = (s_head + 1UL) & (OTA_UART_RING_SIZE - 1UL);
        if (next == s_tail)
        {
            ++s_overflow_count;
            break;
        }
        s_ring[s_head] = message->pDatas[index];
        s_head = next;
    }
}

static void ota_uart_error_notify(FCUART_HandleType *handle, uint32_t error)
{
    (void)handle;
    (void)error;
    ++s_overflow_count;
}

bool ota_uart_init(FCUART_HandleType *handle, FCUART_InitType *config)
{
    if ((handle == 0) || (config == 0))
    {
        return false;
    }

    s_uart = handle;
    s_head = 0UL;
    s_tail = 0UL;
    s_overflow_count = 0UL;
    s_rx_message.pDatas = s_rx_driver_buffer;
    s_rx_message.u32DataLen = sizeof(s_rx_driver_buffer);

    FCUART_InitStructure(handle);
    config->bEnRxFifo = true;
    config->u8RxFifoWaterMark = 0U;
    config->eFifoRxIdleCharNum = FCUART_FIFO_RX_IDLE_DISABLE;
    config->tInterruptCfg.bEnRxInterrupt = true;
    config->tInterruptCfg.pRxBuf = &s_rx_message;
    config->tInterruptCfg.pRxNotify = ota_uart_rx_notify;
    config->tInterruptCfg.bEnErrorInterrupt = true;
    config->tInterruptCfg.pErrorNotify = ota_uart_error_notify;

    if (FCUART_Init(handle, config) != FCUART_ERROR_OK)
    {
        s_uart = 0;
        return false;
    }

    FCUART_StartReceive(handle);
    NVIC_ClearPendingIRQ(FCUART1_IRQn);
    NVIC_SetPriority(FCUART1_IRQn, 5U);
    NVIC_EnableIRQ(FCUART1_IRQn);
    return true;
}

bool ota_uart_read_byte(uint8_t *byte)
{
    if ((byte == 0) || (s_tail == s_head))
    {
        return false;
    }
    *byte = s_ring[s_tail];
    s_tail = (s_tail + 1UL) & (OTA_UART_RING_SIZE - 1UL);
    return true;
}

bool ota_uart_write(const void *data, uint32_t len)
{
    FCUART_DataType message;

    if ((s_uart == 0) || (data == 0) || (len == 0UL))
    {
        return false;
    }
    message.pDatas = (uint8_t *)data;
    message.u32DataLen = len;
    return (FCUART_Transmit(s_uart, &message) == FCUART_ERROR_OK);
}

uint32_t ota_uart_overflow_count(void)
{
    return s_overflow_count;
}

void FCUART1_RxTx_IRQHandler(void)
{
    if (s_uart != 0)
    {
        FCUARTN_RxTx_IRQHandler(s_uart);
    }
}
