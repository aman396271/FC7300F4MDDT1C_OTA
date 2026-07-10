#ifndef _DEVICE_FEATURES_FC7240F2MDS1P100T1A_H_
#define _DEVICE_FEATURES_FC7240F2MDS1P100T1A_H_

#include "FC7240F2MDS1xxxxT1A_feature.h"

/*********************** PORT Features ****************************/
#define PORT_INSTANCE_COUNT 5U

/** @brief PORTA0 Mode enumeration */
typedef enum
{
    PORTA_0_ADC1_SE30 = 0U,
    PORTA_0_GPIO = 1U,
    PORTA_0_FTU2_CH1 = 2U,
    PORTA_0_AONTIMER0_CLK1 = 3U,
    PORTA_0_SENT0_RXD3 = 4U,
    PORTA_0_TPU_CH1 = 5U,
    PORTA_0_FCUART0_CTS = 6U,
    PORTA_0_TRGSEL_OUT3 = 7U,
} PORT_A0MuxType;

/** @brief PORTA1 Mode enumeration */
typedef enum
{
    PORTA_1_ADC1_SE29 = 0U,
    PORTA_1_GPIO = 1U,
    PORTA_1_FTU1_CH1 = 2U,
    PORTA_1_AONTIMER0_CLK2 = 3U,
    PORTA_1_SENT0_RXD2 = 4U,
    PORTA_1_FTU1_QD_PHB = 5U,
    PORTA_1_FCUART0_RTS = 6U,
    PORTA_1_TRGSEL_OUT0 = 7U,
} PORT_A1MuxType;

/** @brief PORTA10 Mode enumeration */
typedef enum
{
    PORTA_10_GPIO = 1U,
    PORTA_10_FTU1_CH4 = 2U,
    PORTA_10_AONTIMER0_CLK0 = 3U,
    PORTA_10_TPU_CH30 = 4U,
    PORTA_10_FCIIC0_SCL = 5U,
    PORTA_10_JTAG_TDO = 7U,
} PORT_A10MuxType;

/** @brief PORTA11 Mode enumeration */
typedef enum
{
    PORTA_11_GPIO = 1U,
    PORTA_11_FTU1_CH5 = 2U,
    PORTA_11_LP_WAKEUP2 = 3U,
    PORTA_11_TPU_CH29 = 4U,
    PORTA_11_FCSPI0_PCS0 = 5U,
    PORTA_11_NMI_b = 7U,
} PORT_A11MuxType;

/** @brief PORTA12 Mode enumeration */
typedef enum
{
    PORTA_12_GPIO = 1U,
    PORTA_12_FTU1_CH6 = 2U,
    PORTA_12_FLEXCAN1_RX = 3U,
    PORTA_12_FCSPI0_SOUT = 5U,
    PORTA_12_FTU1_QD_PHB = 6U,
    PORTA_12_TPU_CH9 = 7U,
} PORT_A12MuxType;

/** @brief PORTA13 Mode enumeration */
typedef enum
{
    PORTA_13_ADC0_SE20 = 0U,
    PORTA_13_GPIO = 1U,
    PORTA_13_FTU1_CH7 = 2U,
    PORTA_13_FLEXCAN1_TX = 3U,
    PORTA_13_CMP1_OUT = 4U,
    PORTA_13_FCUART0_RX = 5U,
    PORTA_13_FTU1_QD_PHA = 6U,
    PORTA_13_TPU_CH8 = 7U,
} PORT_A13MuxType;

/** @brief PORTA14 Mode enumeration */
typedef enum
{
    PORTA_14_ADC0_SE21 = 0U,
    PORTA_14_GPIO = 1U,
    PORTA_14_FTU_FLT17 = 2U,
    PORTA_14_AONTIMER0_CLK1 = 3U,
    PORTA_14_FCUART0_TX = 5U,
    PORTA_14_TPU_CH7 = 6U,
} PORT_A14MuxType;

/** @brief PORTA15 Mode enumeration */
typedef enum
{
    PORTA_15_ADC0_SE26 = 0U,
    PORTA_15_GPIO = 1U,
    PORTA_15_FTU1_CH2 = 2U,
    PORTA_15_TRGSEL_OUT0 = 5U,
    PORTA_15_FLEXCAN3_RX = 6U,
    PORTA_15_TPU_CH5 = 7U,
} PORT_A15MuxType;

/** @brief PORTA16 Mode enumeration */
typedef enum
{
    PORTA_16_ADC0_SE28 = 0U,
    PORTA_16_GPIO = 1U,
    PORTA_16_FTU1_CH3 = 2U,
    PORTA_16_FCSPI1_PCS2 = 3U,
    PORTA_16_FTU1_QD_PHA = 4U,
    PORTA_16_SENT0_RXD1 = 5U,
    PORTA_16_FLEXCAN3_TX = 6U,
    PORTA_16_TPU_CH4 = 7U,
} PORT_A16MuxType;

/** @brief PORTA17 Mode enumeration */
typedef enum
{
    PORTA_17_GPIO = 1U,
    PORTA_17_FTU0_CH6 = 2U,
    PORTA_17_FTU7_CH0 = 3U,
    PORTA_17_FLEXCAN2_TX = 4U,
    PORTA_17_FCSPI5_PCS0 = 5U,
    PORTA_17_FTU_FLT15 = 6U,
    PORTA_17_FCUART3_RX = 7U,
} PORT_A17MuxType;

/** @brief PORTA2 Mode enumeration */
typedef enum
{
    PORTA_2_GPIO = 1U,
    PORTA_2_FTU3_CH0 = 2U,
    PORTA_2_FCIIC0_SDA = 3U,
    PORTA_2_TPU_CH1 = 4U,
    PORTA_2_FCSPI5_SOUT = 5U,
    PORTA_2_FCUART0_RX = 6U,
} PORT_A2MuxType;

/** @brief PORTA3 Mode enumeration */
typedef enum
{
    PORTA_3_GPIO = 1U,
    PORTA_3_FTU3_CH1 = 2U,
    PORTA_3_FCIIC0_SCL = 3U,
    PORTA_3_TPU_CH2 = 4U,
    PORTA_3_FCSPI5_SCK = 5U,
    PORTA_3_FCUART0_TX = 6U,
} PORT_A3MuxType;

/** @brief PORTA4 Mode enumeration */
typedef enum
{
    PORTA_4_GPIO = 1U,
    PORTA_4_FTU1_CH0 = 2U,
    PORTA_4_TRGSEL_OUT7 = 3U,
    PORTA_4_CMP0_OUT = 4U,
    PORTA_4_LP_WAKEUP4 = 5U,
    PORTA_4_JTAG_TMS_SWD_DIO = 7U,
} PORT_A4MuxType;

/** @brief PORTA6 Mode enumeration */
typedef enum
{
    PORTA_6_ADC1_SE9 = 0U,
    PORTA_6_GPIO = 1U,
    PORTA_6_FTU_FLT13 = 2U,
    PORTA_6_FCSPI1_PCS1 = 3U,
    PORTA_6_FTU5_CH5 = 4U,
    PORTA_6_TRGSEL_OUT4 = 5U,
    PORTA_6_FCUART1_CTS = 6U,
    PORTA_6_FTU4_CH7 = 7U,
} PORT_A6MuxType;

/** @brief PORTA7 Mode enumeration */
typedef enum
{
    PORTA_7_GPIO = 1U,
    PORTA_7_FTU_FLT12 = 2U,
    PORTA_7_FTU3_CH1 = 3U,
    PORTA_7_FTU5_CH3 = 4U,
    PORTA_7_FCSPI1_SCK = 5U,
    PORTA_7_FCUART1_RTS = 6U,
    PORTA_7_MSC0_EN0 = 7U,
} PORT_A7MuxType;

/** @brief PORTA8 Mode enumeration */
typedef enum
{
    PORTA_8_ADC1_SE3 = 0U,
    PORTA_8_GPIO = 1U,
    PORTA_8_FCUART2_RX = 2U,
    PORTA_8_FTU1_CH0 = 3U,
    PORTA_8_CMP0_OUT = 4U,
    PORTA_8_FTU_FLT21 = 5U,
    PORTA_8_FCUART0_RX = 6U,
    PORTA_8_TPU_CH13 = 7U,
} PORT_A8MuxType;

/** @brief PORTA9 Mode enumeration */
typedef enum
{
    PORTA_9_ADC1_SE7 = 0U,
    PORTA_9_GPIO = 1U,
    PORTA_9_FCUART2_TX = 2U,
    PORTA_9_FTU4_CH4 = 3U,
    PORTA_9_FTU_FLT20 = 5U,
    PORTA_9_FCUART0_TX = 6U,
    PORTA_9_TPU_CH12 = 7U,
} PORT_A9MuxType;

/** @brief PORTB0 Mode enumeration */
typedef enum
{
    PORTB_0_ADC1_SE10 = 0U,
    PORTB_0_GPIO = 1U,
    PORTB_0_FCUART0_RX = 2U,
    PORTB_0_FCSPI0_PCS0 = 3U,
    PORTB_0_FTU1_CH5 = 4U,
    PORTB_0_FLEXCAN0_RX = 5U,
    PORTB_0_FTU4_CH6 = 6U,
    PORTB_0_MSC0_SDI1 = 7U,
} PORT_B0MuxType;

/** @brief PORTB1 Mode enumeration */
typedef enum
{
    PORTB_1_ADC1_SE11 = 0U,
    PORTB_1_GPIO = 1U,
    PORTB_1_FCUART0_TX = 2U,
    PORTB_1_FCSPI0_SOUT = 3U,
    PORTB_1_FTU_TCK0 = 4U,
    PORTB_1_FLEXCAN0_TX = 5U,
    PORTB_1_FTU4_CH5 = 6U,
    PORTB_1_MSC0_EN1 = 7U,
} PORT_B1MuxType;

/** @brief PORTB10 Mode enumeration */
typedef enum
{
    PORTB_10_GPIO = 1U,
    PORTB_10_FTU3_CH2 = 2U,
    PORTB_10_FLEXCAN0_TX = 3U,
    PORTB_10_SENT0_RXD0 = 4U,
    PORTB_10_TRGSEL_OUT2 = 5U,
    PORTB_10_TPU_CH0 = 6U,
    PORTB_10_TPU_TCRCLK = 7U,
} PORT_B10MuxType;

/** @brief PORTB11 Mode enumeration */
typedef enum
{
    PORTB_11_V15_BASE_DRIVER = 0U,
    PORTB_11_GPIO = 1U,
    PORTB_11_FTU6_CH0 = 2U,
    PORTB_11_FCUART2_TX = 3U,
    PORTB_11_FLEXCAN0_TX = 4U,
} PORT_B11MuxType;

/** @brief PORTB12 Mode enumeration */
typedef enum
{
    PORTB_12_GPIO = 1U,
    PORTB_12_FTU0_CH0 = 2U,
    PORTB_12_TPU_CH26 = 5U,
    PORTB_12_FCSMU_PIN0 = 7U,
} PORT_B12MuxType;

/** @brief PORTB13 Mode enumeration */
typedef enum
{
    PORTB_13_GPIO = 1U,
    PORTB_13_FTU0_CH1 = 2U,
    PORTB_13_FCUART6_CTS = 4U,
    PORTB_13_TPU_CH25 = 5U,
    PORTB_13_FCSMU_PIN1 = 7U,
} PORT_B13MuxType;

/** @brief PORTB14 Mode enumeration */
typedef enum
{
    PORTB_14_ADC1_SE18 = 0U,
    PORTB_14_GPIO = 1U,
    PORTB_14_FTU0_CH2 = 2U,
    PORTB_14_FCSPI1_SCK = 3U,
    PORTB_14_TPU_CH5 = 4U,
    PORTB_14_FTU5_CH4 = 6U,
    PORTB_14_FLEXCAN2_RX = 7U,
} PORT_B14MuxType;

/** @brief PORTB15 Mode enumeration */
typedef enum
{
    PORTB_15_ADC1_SE17 = 0U,
    PORTB_15_GPIO = 1U,
    PORTB_15_FTU0_CH3 = 2U,
    PORTB_15_FCSPI1_SIN = 3U,
    PORTB_15_TPU_CH6 = 4U,
    PORTB_15_FTU5_CH5 = 6U,
    PORTB_15_FLEXCAN2_TX = 7U,
} PORT_B15MuxType;

/** @brief PORTB16 Mode enumeration */
typedef enum
{
    PORTB_16_ADC1_SE16 = 0U,
    PORTB_16_GPIO = 1U,
    PORTB_16_FTU0_CH4 = 2U,
    PORTB_16_FCSPI1_SOUT = 3U,
    PORTB_16_TPU_CH7 = 4U,
    PORTB_16_FTU5_CH6 = 6U,
} PORT_B16MuxType;

/** @brief PORTB17 Mode enumeration */
typedef enum
{
    PORTB_17_GPIO = 1U,
    PORTB_17_FTU0_CH5 = 2U,
    PORTB_17_FCSPI1_PCS3 = 3U,
    PORTB_17_FLEXCAN2_RX = 4U,
    PORTB_17_TRGSEL_OUT3 = 5U,
    PORTB_17_FTU5_CH7 = 6U,
    PORTB_17_FCUART3_TX = 7U,
} PORT_B17MuxType;

/** @brief PORTB3 Mode enumeration */
typedef enum
{
    PORTB_3_GPIO = 1U,
    PORTB_3_FTU1_CH1 = 2U,
    PORTB_3_FCSPI0_SIN = 3U,
    PORTB_3_FTU1_QD_PHA = 4U,
    PORTB_3_FTU7_CH3 = 5U,
    PORTB_3_TPU_CH10 = 6U,
    PORTB_3_FCUART5_RX = 7U,
} PORT_B3MuxType;

/** @brief PORTB4 Mode enumeration */
typedef enum
{
    PORTB_4_GPIO = 1U,
    PORTB_4_FTU0_CH4 = 2U,
    PORTB_4_FCIIC1_SDA = 3U,
    PORTB_4_FCSPI4_SOUT = 4U,
    PORTB_4_FTU7_CH6 = 5U,
    PORTB_4_TRACE_D6 = 6U,
    PORTB_4_TRGSEL_OUT4 = 7U,
} PORT_B4MuxType;

/** @brief PORTB5 Mode enumeration */
typedef enum
{
    PORTB_5_GPIO = 1U,
    PORTB_5_FTU0_CH5 = 2U,
    PORTB_5_FCIIC1_SCL = 3U,
    PORTB_5_FCSPI4_PCS0 = 4U,
    PORTB_5_SCG_CLKOUT = 5U,
    PORTB_5_TRACE_D5 = 6U,
    PORTB_5_TRGSEL_OUT5 = 7U,
} PORT_B5MuxType;

/** @brief PORTB6 Mode enumeration */
typedef enum
{
    PORTB_6_XTAL = 0U,
    PORTB_6_GPIO = 1U,
    PORTB_6_FCIIC0_SDA = 2U,
} PORT_B6MuxType;

/** @brief PORTB7 Mode enumeration */
typedef enum
{
    PORTB_7_EXTAL = 0U,
    PORTB_7_GPIO = 1U,
    PORTB_7_FCIIC0_SCL = 2U,
} PORT_B7MuxType;

/** @brief PORTB8 Mode enumeration */
typedef enum
{
    PORTB_8_ADC1_SE28 = 0U,
    PORTB_8_GPIO = 1U,
    PORTB_8_FTU3_CH0 = 2U,
    PORTB_8_FLEXCAN0_RX = 3U,
    PORTB_8_SENT0_RXD1 = 4U,
    PORTB_8_TPU_CH0 = 5U,
    PORTB_8_FCUART1_CTS = 6U,
} PORT_B8MuxType;

/** @brief PORTC0 Mode enumeration */
typedef enum
{
    PORTC_0_GPIO = 1U,
    PORTC_0_FTU0_CH0 = 2U,
    PORTC_0_FLEXCAN2_RX = 3U,
    PORTC_0_TPU_CH15 = 4U,
    PORTC_0_FlexCore_TCLK = 5U,
    PORTC_0_FTU1_CH6 = 6U,
    PORTC_0_FCSPI3_PCS2 = 7U,
} PORT_C0MuxType;

/** @brief PORTC1 Mode enumeration */
typedef enum
{
    PORTC_1_GPIO = 1U,
    PORTC_1_FTU0_CH1 = 2U,
    PORTC_1_TPU_CH16 = 3U,
    PORTC_1_FCSPI2_SOUT = 4U,
    PORTC_1_FlexCore_TDI = 5U,
    PORTC_1_FTU1_CH7 = 6U,
    PORTC_1_FCUART3_TX = 7U,
} PORT_C1MuxType;

/** @brief PORTC10 Mode enumeration */
typedef enum
{
    PORTC_10_ADC1_SE12 = 0U,
    PORTC_10_GPIO = 1U,
    PORTC_10_FTU3_CH4 = 2U,
    PORTC_10_FTU0_CH5 = 3U,
    PORTC_10_FCUART6_RX = 4U,
    PORTC_10_FTU7_CH1 = 6U,
    PORTC_10_TPU_CH8 = 7U,
} PORT_C10MuxType;

/** @brief PORTC11 Mode enumeration */
typedef enum
{
    PORTC_11_ADC1_SE13 = 0U,
    PORTC_11_GPIO = 1U,
    PORTC_11_FTU3_CH5 = 2U,
    PORTC_11_FTU4_CH2 = 3U,
    PORTC_11_FCUART6_TX = 4U,
    PORTC_11_FCSPI1_PCS0 = 5U,
    PORTC_11_FTU7_CH2 = 6U,
    PORTC_11_TPU_CH9 = 7U,
} PORT_C11MuxType;

/** @brief PORTC12 Mode enumeration */
typedef enum
{
    PORTC_12_ADC1_SE14 = 0U,
    PORTC_12_GPIO = 1U,
    PORTC_12_FTU3_CH6 = 2U,
    PORTC_12_FTU2_CH6 = 3U,
    PORTC_12_FCUART2_CTS = 4U,
    PORTC_12_TRGSEL_OUT5 = 5U,
    PORTC_12_FCUART7_RX = 6U,
    PORTC_12_MSC0_SOP = 7U,
} PORT_C12MuxType;

/** @brief PORTC13 Mode enumeration */
typedef enum
{
    PORTC_13_ADC1_SE15 = 0U,
    PORTC_13_GPIO = 1U,
    PORTC_13_FTU3_CH7 = 2U,
    PORTC_13_FTU2_CH7 = 3U,
    PORTC_13_FCUART2_RTS = 4U,
    PORTC_13_TRGSEL_OUT6 = 5U,
    PORTC_13_FCUART7_TX = 6U,
    PORTC_13_MSC0_FCLP = 7U,
} PORT_C13MuxType;

/** @brief PORTC14 Mode enumeration */
typedef enum
{
    PORTC_14_CMP1_IN7 = 0U,
    PORTC_14_GPIO = 1U,
    PORTC_14_FTU1_CH2 = 2U,
    PORTC_14_TPU_CH11 = 3U,
    PORTC_14_FCSPI2_PCS0 = 4U,
    PORTC_14_FTU1_QD_PHA = 5U,
    PORTC_14_TRGSEL_OUT6 = 6U,
} PORT_C14MuxType;

/** @brief PORTC15 Mode enumeration */
typedef enum
{
    PORTC_15_CMP1_IN5 = 0U,
    PORTC_15_GPIO = 1U,
    PORTC_15_FTU1_CH3 = 2U,
    PORTC_15_TPU_CH12 = 3U,
    PORTC_15_FCSPI2_SCK = 4U,
    PORTC_15_FTU6_CH1 = 5U,
    PORTC_15_TRGSEL_OUT7 = 6U,
    PORTC_15_FCUART5_TX = 7U,
} PORT_C15MuxType;

/** @brief PORTC16 Mode enumeration */
typedef enum
{
    PORTC_16_CMP1_IN4 = 0U,
    PORTC_16_GPIO = 1U,
    PORTC_16_FTU_FLT7 = 2U,
    PORTC_16_FTU4_CH0 = 3U,
    PORTC_16_FCSPI2_SIN = 4U,
    PORTC_16_FTU7_CH4 = 5U,
    PORTC_16_TPU_CH13 = 6U,
    PORTC_16_FCUART5_RX = 7U,
} PORT_C16MuxType;

/** @brief PORTC17 Mode enumeration */
typedef enum
{
    PORTC_17_DEBUGMUX_P1 = 0U,
    PORTC_17_GPIO = 1U,
    PORTC_17_FTU_FLT6 = 2U,
    PORTC_17_FTU4_CH1 = 3U,
    PORTC_17_FCSPI2_PCS3 = 4U,
    PORTC_17_FTU6_CH2 = 5U,
    PORTC_17_TPU_CH14 = 6U,
    PORTC_17_FCUART4_TX = 7U,
} PORT_C17MuxType;

/** @brief PORTC2 Mode enumeration */
typedef enum
{
    PORTC_2_DEBUGMUX_P2 = 0U,
    PORTC_2_GPIO = 1U,
    PORTC_2_FTU0_CH2 = 2U,
    PORTC_2_FLEXCAN0_RX = 3U,
    PORTC_2_FCUART0_RX = 4U,
    PORTC_2_FTU5_CH4 = 5U,
    PORTC_2_TRACE_CLKOUT = 6U,
    PORTC_2_FCSPI0_PCS2 = 7U,
} PORT_C2MuxType;

/** @brief PORTC3 Mode enumeration */
typedef enum
{
    PORTC_3_GPIO = 1U,
    PORTC_3_FTU0_CH3 = 2U,
    PORTC_3_FLEXCAN0_TX = 3U,
    PORTC_3_FCUART0_TX = 4U,
    PORTC_3_FTU5_CH2 = 5U,
    PORTC_3_TRACE_D7 = 6U,
    PORTC_3_FCSPI0_SOUT = 7U,
} PORT_C3MuxType;

/** @brief PORTC4 Mode enumeration */
typedef enum
{
    PORTC_4_GPIO = 1U,
    PORTC_4_JTAG_TCLK_SWD_CLK = 7U,
} PORT_C4MuxType;

/** @brief PORTC5 Mode enumeration */
typedef enum
{
    PORTC_5_GPIO = 1U,
    PORTC_5_FTU2_CH0 = 2U,
    PORTC_5_RTC_CLKOUT = 3U,
    PORTC_5_CMP1_OUT = 4U,
    PORTC_5_FCIIC0_SDA = 5U,
    PORTC_5_FTU2_QD_PHB = 6U,
    PORTC_5_JTAG_TDI = 7U,
} PORT_C5MuxType;

/** @brief PORTC6 Mode enumeration */
typedef enum
{
    PORTC_6_ADC0_SE29 = 0U,
    PORTC_6_GPIO = 1U,
    PORTC_6_FCUART1_RX = 2U,
    PORTC_6_FLEXCAN1_RX = 3U,
    PORTC_6_FTU3_CH2 = 4U,
    PORTC_6_SENT0_RXD0 = 5U,
    PORTC_6_TPU_CH3 = 6U,
} PORT_C6MuxType;

/** @brief PORTC7 Mode enumeration */
typedef enum
{
    PORTC_7_ADC0_SE30 = 0U,
    PORTC_7_GPIO = 1U,
    PORTC_7_FCUART1_TX = 2U,
    PORTC_7_FLEXCAN1_TX = 3U,
    PORTC_7_FTU3_CH3 = 4U,
    PORTC_7_TPU_CH2 = 6U,
} PORT_C7MuxType;

/** @brief PORTC8 Mode enumeration */
typedef enum
{
    PORTC_8_GPIO = 1U,
    PORTC_8_FCUART1_RX = 2U,
    PORTC_8_FTU_FLT11 = 3U,
    PORTC_8_FTU5_CH1 = 4U,
    PORTC_8_FCSPI1_SIN = 5U,
    PORTC_8_FCUART0_CTS = 6U,
    PORTC_8_MSC0_EN1 = 7U,
} PORT_C8MuxType;

/** @brief PORTC9 Mode enumeration */
typedef enum
{
    PORTC_9_GPIO = 1U,
    PORTC_9_FCUART1_TX = 2U,
    PORTC_9_FTU_FLT10 = 3U,
    PORTC_9_FTU5_CH0 = 4U,
    PORTC_9_FCSPI1_SOUT = 5U,
    PORTC_9_FCUART0_RTS = 6U,
    PORTC_9_FCUART5_TX = 7U,
} PORT_C9MuxType;

/** @brief PORTD0 Mode enumeration */
typedef enum
{
    PORTD_0_ADC1_SE1 = 0U,
    PORTD_0_GPIO = 1U,
    PORTD_0_FTU0_CH2 = 2U,
    PORTD_0_FTU2_CH0 = 3U,
    PORTD_0_FCSPI1_SCK = 4U,
    PORTD_0_TPU_CH28 = 5U,
    PORTD_0_TRACE_D0 = 6U,
    PORTD_0_TRGSEL_OUT1 = 7U,
} PORT_D0MuxType;

/** @brief PORTD1 Mode enumeration */
typedef enum
{
    PORTD_1_ADC1_SE5 = 0U,
    PORTD_1_GPIO = 1U,
    PORTD_1_FTU0_CH3 = 2U,
    PORTD_1_FTU2_CH1 = 3U,
    PORTD_1_FCSPI1_SIN = 4U,
    PORTD_1_TPU_CH29 = 5U,
    PORTD_1_TRGSEL_OUT2 = 7U,
} PORT_D1MuxType;

/** @brief PORTD10 Mode enumeration */
typedef enum
{
    PORTD_10_GPIO = 1U,
    PORTD_10_FTU2_CH0 = 2U,
    PORTD_10_FTU2_QD_PHB = 3U,
    PORTD_10_SCG_CLKOUT = 4U,
    PORTD_10_FlexCore_TMS = 5U,
    PORTD_10_TRACE_D3 = 6U,
    PORTD_10_FCSPI3_PCS3 = 7U,
} PORT_D10MuxType;

/** @brief PORTD11 Mode enumeration */
typedef enum
{
    PORTD_11_GPIO = 1U,
    PORTD_11_FTU2_CH1 = 2U,
    PORTD_11_FTU2_QD_PHA = 3U,
    PORTD_11_FCSPI4_PCS1 = 4U,
    PORTD_11_FCUART2_CTS = 5U,
    PORTD_11_TRACE_D2 = 6U,
    PORTD_11_FCSPI3_PCS0 = 7U,
} PORT_D11MuxType;

/** @brief PORTD12 Mode enumeration */
typedef enum
{
    PORTD_12_GPIO = 1U,
    PORTD_12_FTU2_CH2 = 2U,
    PORTD_12_FCUART4_RX = 3U,
    PORTD_12_FTU6_CH7 = 4U,
    PORTD_12_FCUART2_RTS = 5U,
    PORTD_12_TRACE_D1 = 6U,
    PORTD_12_FCSPI3_SOUT = 7U,
} PORT_D12MuxType;

/** @brief PORTD15 Mode enumeration */
typedef enum
{
    PORTD_15_ADC0_SE11_CMP0_IN1 = 0U,
    PORTD_15_GPIO = 1U,
    PORTD_15_FTU0_CH0 = 2U,
    PORTD_15_FCUART2_RTS = 3U,
    PORTD_15_TPU_CH18 = 4U,
    PORTD_15_TRACE_D3 = 6U,
    PORTD_15_FCSPI0_SCK = 7U,
} PORT_D15MuxType;

/** @brief PORTD16 Mode enumeration */
typedef enum
{
    PORTD_16_ADC0_SE10_CMP0_IN0 = 0U,
    PORTD_16_GPIO = 1U,
    PORTD_16_FTU0_CH1 = 2U,
    PORTD_16_TPU_CH19 = 4U,
    PORTD_16_TRACE_D2 = 6U,
    PORTD_16_FCSPI0_SIN = 7U,
} PORT_D16MuxType;

/** @brief PORTD2 Mode enumeration */
typedef enum
{
    PORTD_2_GPIO = 1U,
    PORTD_2_FTU3_CH4 = 2U,
    PORTD_2_FTU6_CH5 = 3U,
    PORTD_2_FCUART6_RX = 4U,
    PORTD_2_FCSPI5_PCS2 = 5U,
    PORTD_2_FTU1_CH1 = 6U,
    PORTD_2_ISP_EN_B = 7U,
} PORT_D2MuxType;

/** @brief PORTD3 Mode enumeration */
typedef enum
{
    PORTD_3_GPIO = 1U,
    PORTD_3_FTU3_CH5 = 2U,
    PORTD_3_FCSPI1_PCS0 = 3U,
    PORTD_3_FCSPI5_PCS0 = 5U,
    PORTD_3_FTU1_CH2 = 6U,
    PORTD_3_TPU_CH3 = 7U,
} PORT_D3MuxType;

/** @brief PORTD4 Mode enumeration */
typedef enum
{
    PORTD_4_ADC1_SE23 = 0U,
    PORTD_4_GPIO = 1U,
    PORTD_4_FTU_FLT16 = 2U,
    PORTD_4_FTU6_CH4 = 3U,
    PORTD_4_FCUART6_TX = 4U,
    PORTD_4_FCSPI5_SIN = 5U,
    PORTD_4_FTU1_CH3 = 6U,
    PORTD_4_TPU_CH4 = 7U,
} PORT_D4MuxType;

/** @brief PORTD5 Mode enumeration */
typedef enum
{
    PORTD_5_GPIO = 1U,
    PORTD_5_FTU2_CH3 = 2U,
    PORTD_5_FCUART4_TX = 3U,
    PORTD_5_FTU_FLT5 = 4U,
    PORTD_5_FTU7_CH5 = 5U,
    PORTD_5_TPU_CH20 = 6U,
    PORTD_5_FCSPI3_SIN = 7U,
} PORT_D5MuxType;

/** @brief PORTD6 Mode enumeration */
typedef enum
{
    PORTD_6_GPIO = 1U,
    PORTD_6_FCUART2_RX = 2U,
    PORTD_6_FLEXCAN3_RX = 3U,
    PORTD_6_FTU_FLT4 = 4U,
    PORTD_6_FTU2_CH4 = 5U,
    PORTD_6_TPU_CH21 = 6U,
    PORTD_6_FCSPI3_SCK = 7U,
} PORT_D6MuxType;

/** @brief PORTD7 Mode enumeration */
typedef enum
{
    PORTD_7_GPIO = 1U,
    PORTD_7_FCUART2_TX = 2U,
    PORTD_7_FLEXCAN3_TX = 3U,
    PORTD_7_FCSPI4_SIN = 4U,
    PORTD_7_FTU2_CH5 = 5U,
    PORTD_7_TRACE_D0 = 6U,
} PORT_D7MuxType;

/** @brief PORTD8 Mode enumeration */
typedef enum
{
    PORTD_8_CMP1_IN3 = 0U,
    PORTD_8_GPIO = 1U,
    PORTD_8_FCIIC1_SDA = 2U,
    PORTD_8_FTU4_CH2 = 3U,
    PORTD_8_FCSPI2_PCS2 = 4U,
    PORTD_8_FlexCore_TRST = 5U,
    PORTD_8_FTU1_CH4 = 6U,
    PORTD_8_FCUART4_RX = 7U,
} PORT_D8MuxType;

/** @brief PORTD9 Mode enumeration */
typedef enum
{
    PORTD_9_CMP1_IN2 = 0U,
    PORTD_9_GPIO = 1U,
    PORTD_9_FCIIC1_SCL = 2U,
    PORTD_9_FTU4_CH3 = 3U,
    PORTD_9_FCSPI2_PCS1 = 4U,
    PORTD_9_FlexCore_TDO = 5U,
    PORTD_9_FTU1_CH5 = 6U,
    PORTD_9_FCUART3_RX = 7U,
} PORT_D9MuxType;

/** @brief PORTE0 Mode enumeration */
typedef enum
{
    PORTE_0_ADC0_SE16 = 0U,
    PORTE_0_GPIO = 1U,
    PORTE_0_FCUART0_CTS = 2U,
    PORTE_0_FTU_TCK1 = 3U,
    PORTE_0_FCIIC1_SDA = 4U,
    PORTE_0_FCSPI0_SCK = 5U,
    PORTE_0_FTU_FLT19 = 6U,
    PORTE_0_TPU_CH11 = 7U,
} PORT_E0MuxType;

/** @brief PORTE1 Mode enumeration */
typedef enum
{
    PORTE_1_ADC0_SE17 = 0U,
    PORTE_1_GPIO = 1U,
    PORTE_1_FCUART0_RTS = 2U,
    PORTE_1_FCIIC1_SCL = 4U,
    PORTE_1_FCSPI0_SIN = 5U,
    PORTE_1_FTU_FLT18 = 6U,
    PORTE_1_TPU_CH10 = 7U,
} PORT_E1MuxType;

/** @brief PORTE10 Mode enumeration */
typedef enum
{
    PORTE_10_ADC1_SE0 = 0U,
    PORTE_10_GPIO = 1U,
    PORTE_10_FTU2_CH4 = 2U,
    PORTE_10_FCSPI2_PCS1 = 3U,
    PORTE_10_TPU_CH26 = 4U,
    PORTE_10_FCUART2_TX = 5U,
    PORTE_10_SCG_CLKOUT = 6U,
    PORTE_10_TRGSEL_OUT4 = 7U,
} PORT_E10MuxType;

/** @brief PORTE11 Mode enumeration */
typedef enum
{
    PORTE_11_ADC1_SE4 = 0U,
    PORTE_11_GPIO = 1U,
    PORTE_11_FTU2_CH5 = 2U,
    PORTE_11_FCSPI2_PCS0 = 3U,
    PORTE_11_TPU_CH27 = 5U,
    PORTE_11_TRGSEL_OUT5 = 7U,
} PORT_E11MuxType;

/** @brief PORTE13 Mode enumeration */
typedef enum
{
    PORTE_13_ADC0_SE5 = 0U,
    PORTE_13_GPIO = 1U,
    PORTE_13_FTU4_CH5 = 2U,
    PORTE_13_FCSPI2_SOUT = 3U,
    PORTE_13_TPU_CH24 = 4U,
    PORTE_13_FTU3_CH3 = 5U,
} PORT_E13MuxType;

/** @brief PORTE14 Mode enumeration */
typedef enum
{
    PORTE_14_OSC32K_XTAL = 0U,
    PORTE_14_GPIO = 1U,
    PORTE_14_FTU2_CH7 = 2U,
    PORTE_14_FTU2_QD_PHA = 3U,
    PORTE_14_FTU_FLT0 = 4U,
    PORTE_14_FLEXCAN0_RX = 5U,
    PORTE_14_TPU_TCRCLK = 6U,
} PORT_E14MuxType;

/** @brief PORTE15 Mode enumeration */
typedef enum
{
    PORTE_15_ADC1_SE2 = 0U,
    PORTE_15_GPIO = 1U,
    PORTE_15_FTU2_CH6 = 2U,
    PORTE_15_FCSPI2_SCK = 3U,
    PORTE_15_TPU_CH30 = 4U,
    PORTE_15_FCUART1_CTS = 6U,
    PORTE_15_TRGSEL_OUT6 = 7U,
} PORT_E15MuxType;

/** @brief PORTE16 Mode enumeration */
typedef enum
{
    PORTE_16_ADC1_SE6 = 0U,
    PORTE_16_GPIO = 1U,
    PORTE_16_FTU2_CH7 = 2U,
    PORTE_16_FCSPI2_SIN = 3U,
    PORTE_16_TPU_CH31 = 4U,
    PORTE_16_FCUART1_RTS = 6U,
    PORTE_16_TRGSEL_OUT7 = 7U,
} PORT_E16MuxType;

/** @brief PORTE2 Mode enumeration */
typedef enum
{
    PORTE_2_ADC0_SE24 = 0U,
    PORTE_2_GPIO = 1U,
    PORTE_2_FTU6_CH6 = 2U,
    PORTE_2_AONTIMER0_CLK2 = 3U,
    PORTE_2_FTU3_CH6 = 4U,
    PORTE_2_SENT0_RXD3 = 5U,
    PORTE_2_FCUART1_CTS = 6U,
    PORTE_2_FTU1_CH7 = 7U,
} PORT_E2MuxType;

/** @brief PORTE3 Mode enumeration */
typedef enum
{
    PORTE_3_OSC32K_EXTAL = 0U,
    PORTE_3_GPIO = 1U,
    PORTE_3_FTU2_CH6 = 2U,
    PORTE_3_FCUART2_RX = 3U,
    PORTE_3_FTU_FLT1 = 4U,
    PORTE_3_FTU2_QD_PHB = 5U,
    PORTE_3_FTU_TCK0 = 6U,
} PORT_E3MuxType;

/** @brief PORTE4 Mode enumeration */
typedef enum
{
    PORTE_4_ADC0_SE4 = 0U,
    PORTE_4_GPIO = 1U,
    PORTE_4_FTU6_CH0 = 2U,
    PORTE_4_FTU2_QD_PHB = 3U,
    PORTE_4_FCSPI1_PCS0 = 4U,
    PORTE_4_FTU2_CH2 = 5U,
    PORTE_4_TRACE_D1 = 6U,
    PORTE_4_TPU_CH22 = 7U,
} PORT_E4MuxType;

/** @brief PORTE5 Mode enumeration */
typedef enum
{
    PORTE_5_ADC0_SE1 = 0U,
    PORTE_5_GPIO = 1U,
    PORTE_5_FTU_TCK2 = 2U,
    PORTE_5_FTU2_QD_PHA = 3U,
    PORTE_5_FCSPI1_SOUT = 4U,
    PORTE_5_FTU2_CH3 = 5U,
    PORTE_5_TPU_CH23 = 6U,
} PORT_E5MuxType;

/** @brief PORTE6 Mode enumeration */
typedef enum
{
    PORTE_6_ADC0_SE25 = 0U,
    PORTE_6_GPIO = 1U,
    PORTE_6_FTU7_CH7 = 2U,
    PORTE_6_FTU6_CH3 = 3U,
    PORTE_6_FTU3_CH7 = 4U,
    PORTE_6_SENT0_RXD2 = 5U,
    PORTE_6_FCUART1_RTS = 6U,
    PORTE_6_TPU_CH6 = 7U,
} PORT_E6MuxType;

/** @brief PORTE7 Mode enumeration */
typedef enum
{
    PORTE_7_ADC1_SE8 = 0U,
    PORTE_7_GPIO = 1U,
    PORTE_7_FTU0_CH7 = 2U,
    PORTE_7_FTU_FLT14 = 3U,
    PORTE_7_FTU5_CH6 = 4U,
    PORTE_7_TRGSEL_OUT3 = 5U,
    PORTE_7_SENT0_RXD3 = 6U,
    PORTE_7_MSC0_SDI3 = 7U,
} PORT_E7MuxType;

/** @brief PORTE8 Mode enumeration */
typedef enum
{
    PORTE_8_GPIO = 1U,
    PORTE_8_FTU0_CH6 = 2U,
    PORTE_8_FCSPI4_SCK = 4U,
    PORTE_8_FTU7_CH7 = 5U,
    PORTE_8_TRACE_D4 = 6U,
    PORTE_8_FCSPI0_PCS3 = 7U,
} PORT_E8MuxType;

/** @brief PORTE9 Mode enumeration */
typedef enum
{
    PORTE_9_ADC0_SE12_CMP0_IN2 = 0U,
    PORTE_9_GPIO = 1U,
    PORTE_9_FTU0_CH7 = 2U,
    PORTE_9_FCUART2_CTS = 3U,
    PORTE_9_TPU_CH17 = 4U,
    PORTE_9_TRACE_CLKOUT = 6U,
    PORTE_9_FCSPI0_PCS0 = 7U,
} PORT_E9MuxType;

/** @brief Port Pin Mux structure */
typedef union
{
    PORT_A0MuxType       ePortA0Mode;
    PORT_A1MuxType       ePortA1Mode;
    PORT_A2MuxType       ePortA2Mode;
    PORT_A3MuxType       ePortA3Mode;
    PORT_A4MuxType       ePortA4Mode;
    PORT_A6MuxType       ePortA6Mode;
    PORT_A7MuxType       ePortA7Mode;
    PORT_A8MuxType       ePortA8Mode;
    PORT_A9MuxType       ePortA9Mode;
    PORT_A10MuxType      ePortA10Mode;
    PORT_A11MuxType      ePortA11Mode;
    PORT_A12MuxType      ePortA12Mode;
    PORT_A13MuxType      ePortA13Mode;
    PORT_A14MuxType      ePortA14Mode;
    PORT_A15MuxType      ePortA15Mode;
    PORT_A16MuxType      ePortA16Mode;
    PORT_A17MuxType      ePortA17Mode;
    PORT_B0MuxType       ePortB0Mode;
    PORT_B1MuxType       ePortB1Mode;
    PORT_B3MuxType       ePortB3Mode;
    PORT_B4MuxType       ePortB4Mode;
    PORT_B5MuxType       ePortB5Mode;
    PORT_B6MuxType       ePortB6Mode;
    PORT_B7MuxType       ePortB7Mode;
    PORT_B8MuxType       ePortB8Mode;
    PORT_B10MuxType      ePortB10Mode;
    PORT_B11MuxType      ePortB11Mode;
    PORT_B12MuxType      ePortB12Mode;
    PORT_B13MuxType      ePortB13Mode;
    PORT_B14MuxType      ePortB14Mode;
    PORT_B15MuxType      ePortB15Mode;
    PORT_B16MuxType      ePortB16Mode;
    PORT_B17MuxType      ePortB17Mode;
    PORT_C0MuxType       ePortC0Mode;
    PORT_C1MuxType       ePortC1Mode;
    PORT_C2MuxType       ePortC2Mode;
    PORT_C3MuxType       ePortC3Mode;
    PORT_C4MuxType       ePortC4Mode;
    PORT_C5MuxType       ePortC5Mode;
    PORT_C6MuxType       ePortC6Mode;
    PORT_C7MuxType       ePortC7Mode;
    PORT_C8MuxType       ePortC8Mode;
    PORT_C9MuxType       ePortC9Mode;
    PORT_C10MuxType      ePortC10Mode;
    PORT_C11MuxType      ePortC11Mode;
    PORT_C12MuxType      ePortC12Mode;
    PORT_C13MuxType      ePortC13Mode;
    PORT_C14MuxType      ePortC14Mode;
    PORT_C15MuxType      ePortC15Mode;
    PORT_C16MuxType      ePortC16Mode;
    PORT_C17MuxType      ePortC17Mode;
    PORT_D0MuxType       ePortD0Mode;
    PORT_D1MuxType       ePortD1Mode;
    PORT_D2MuxType       ePortD2Mode;
    PORT_D3MuxType       ePortD3Mode;
    PORT_D4MuxType       ePortD4Mode;
    PORT_D5MuxType       ePortD5Mode;
    PORT_D6MuxType       ePortD6Mode;
    PORT_D7MuxType       ePortD7Mode;
    PORT_D8MuxType       ePortD8Mode;
    PORT_D9MuxType       ePortD9Mode;
    PORT_D10MuxType      ePortD10Mode;
    PORT_D11MuxType      ePortD11Mode;
    PORT_D12MuxType      ePortD12Mode;
    PORT_D15MuxType      ePortD15Mode;
    PORT_D16MuxType      ePortD16Mode;
    PORT_E0MuxType       ePortE0Mode;
    PORT_E1MuxType       ePortE1Mode;
    PORT_E2MuxType       ePortE2Mode;
    PORT_E3MuxType       ePortE3Mode;
    PORT_E4MuxType       ePortE4Mode;
    PORT_E5MuxType       ePortE5Mode;
    PORT_E6MuxType       ePortE6Mode;
    PORT_E7MuxType       ePortE7Mode;
    PORT_E8MuxType       ePortE8Mode;
    PORT_E9MuxType       ePortE9Mode;
    PORT_E10MuxType      ePortE10Mode;
    PORT_E11MuxType      ePortE11Mode;
    PORT_E13MuxType      ePortE13Mode;
    PORT_E14MuxType      ePortE14Mode;
    PORT_E15MuxType      ePortE15Mode;
    PORT_E16MuxType      ePortE16Mode;
    Port_PinModeType     u32PortPinMode;
} Port_PinMuxType;

/** Array initializer of PORT peripheral base addresses */
#define PORT_BASE_ADDRS                          {PORTA_BASE, PORTB_BASE, PORTC_BASE, PORTD_BASE, PORTE_BASE}
/** Array initializer of PORT peripheral base pointers */
#define PORT_BASE_PTRS                           {PORTA, PORTB, PORTC, PORTD, PORTE}

/*********************** GPIO Features ****************************/
#define GPIO_INSTANCE_COUNT 5U

/** Array initializer of GPIO peripheral base addresses */
#define GPIO_BASE_ADDRS                          {GPIOA_BASE, GPIOB_BASE, GPIOC_BASE, GPIOD_BASE, GPIOE_BASE}
/** Array initializer of GPIO peripheral base pointers */
#define GPIO_BASE_PTRS                           {GPIOA, GPIOB, GPIOC, GPIOD, GPIOE}

/** @brief GPIOA Pin MASK structure */
#define GPIOA_PIN_MASK     (uint32_t)(0x3ffdfu)
/** @brief GPIOB Pin MASK structure */
#define GPIOB_PIN_MASK     (uint32_t)(0x3fdfbu)
/** @brief GPIOC Pin MASK structure */
#define GPIOC_PIN_MASK     (uint32_t)(0x3ffffu)
/** @brief GPIOD Pin MASK structure */
#define GPIOD_PIN_MASK     (uint32_t)(0x19fffu)
/** @brief GPIOE Pin MASK structure */
#define GPIOE_PIN_MASK     (uint32_t)(0x1efffu)

/** @brief Gpio Pin MASK structure */
#define GPIO_PIN_MASK      {GPIOA_PIN_MASK, GPIOB_PIN_MASK, GPIOC_PIN_MASK, GPIOD_PIN_MASK, GPIOE_PIN_MASK}

/** @}*/

#endif /* _DEVICE_FEATURES_FC7240F2MDS1P100T1A_H_ */
