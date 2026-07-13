#ifndef OTA_BOARD_CONFIG_H_
#define OTA_BOARD_CONFIG_H_

/* FC7300-EVB wiring, matched to the F4MDD SDK examples in this workspace. */
#define OTA_DEMO_UART_BAUD               (115200UL)
#define OTA_DEMO_UART_INSTANCE           UART_INSTANCE_1
#define OTA_DEMO_UART_PCC_CLOCK          PCC_CLK_FCUART1
#define OTA_DEMO_UART_TX_MUX             PORTA_18_FCUART1_TX
#define OTA_DEMO_UART_RX_MUX             PORTA_19_FCUART1_RX
#define OTA_DEMO_UART_TX_PIN             PORT_PIN_18
#define OTA_DEMO_UART_RX_PIN             PORT_PIN_19

#define OTA_DEMO_LED_A_GPIO              GPIO_A
#define OTA_DEMO_LED_A_PIN               PORT_PIN_26
#define OTA_DEMO_LED_B_GPIO              GPIO_D
#define OTA_DEMO_LED_B_PIN               PORT_PIN_31

#endif /* OTA_BOARD_CONFIG_H_ */
