#ifndef OTA_BOARD_CONFIG_H_
#define OTA_BOARD_CONFIG_H_

/*
 * FC7300F4MDDT1C BGA320 Demo Board wiring, checked against
 * FC7300F4MDDT1C_BGA320_Demo_Board_SCH_V1.1.pdf.
 * UART directions below are from the MCU point of view: PTA18 drives the
 * CH340C RX path and PTA19 receives from the CH340C TX path.
 * LED1/2/3 drive N-MOSFET gates and are therefore active-high at the MCU.
 */
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
#define OTA_DEMO_LED_3_GPIO              GPIO_A
#define OTA_DEMO_LED_3_PIN               PORT_PIN_14

#endif /* OTA_BOARD_CONFIG_H_ */
