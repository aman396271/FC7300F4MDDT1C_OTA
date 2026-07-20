#ifndef OTA_UART_H_
#define OTA_UART_H_

#include <stdbool.h>
#include <stdint.h>

#include "module_driver_fcuart.h"

bool ota_uart_init(FCUART_HandleType *handle, FCUART_InitType *config);
bool ota_uart_read_byte(uint8_t *byte);
bool ota_uart_write(const void *data, uint32_t len);
uint32_t ota_uart_overflow_count(void);

#endif /* OTA_UART_H_ */
