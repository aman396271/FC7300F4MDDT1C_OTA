#ifndef _DEVICE_FEATURES_FC7300F8MDT2P176T1B_H_
#define _DEVICE_FEATURES_FC7300F8MDT2P176T1B_H_

#include "FC7300F8MDTxxxxxT1B_feature.h"

/*********************** PORT Features ****************************/
#define PORT_INSTANCE_COUNT 5U

/** @brief PORTA0 Mode enumeration */
typedef enum
{
    PORTA_0_GPIO = 1U,
    PORTA_0_FTU4_CH6 = 2U,
    PORTA_0_FLEXCAN5_RX = 3U,
    PORTA_0_SENT1_RXD2 = 4U,
    PORTA_0_FTU2_QD_PHA = 5U,
    PORTA_0_FCUART0_CTS = 6U,
    PORTA_0_TRGSEL_OUT3 = 7U,
} PORT_A0MuxType;

/** @brief PORTA1 Mode enumeration */
typedef enum
{
    PORTA_1_GPIO = 1U,
    PORTA_1_FTU4_CH4 = 2U,
    PORTA_1_FCUART15_RX = 3U,
    PORTA_1_SENT1_RXD0 = 4U,
    PORTA_1_FTU1_QD_PHA = 5U,
    PORTA_1_FCUART0_RTS = 6U,
    PORTA_1_TRGSEL_OUT0 = 7U,
} PORT_A1MuxType;

/** @brief PORTA10 Mode enumeration */
typedef enum
{
    PORTA_10_GPIO = 1U,
    PORTA_10_FTU3_CH1 = 2U,
    PORTA_10_JTAG_TDO = 7U,
} PORT_A10MuxType;

/** @brief PORTA11 Mode enumeration */
typedef enum
{
    PORTA_11_GPIO = 1U,
    PORTA_11_FTU3_CH0 = 2U,
    PORTA_11_FLEXCAN1_TX = 3U,
    PORTA_11_FCSPI0_PCS3 = 5U,
    PORTA_11_NMI_b = 7U,
} PORT_A11MuxType;

/** @brief PORTA12 Mode enumeration */
typedef enum
{
    PORTA_12_ADC1_SE18 = 0U,
    PORTA_12_GPIO = 1U,
    PORTA_12_FTU0_CH7 = 2U,
    PORTA_12_FLEXCAN1_RX = 3U,
    PORTA_12_CMP2_OUT = 4U,
    PORTA_12_FCSPI0_SOUT = 5U,
    PORTA_12_FTU2_QD_PHB = 6U,
} PORT_A12MuxType;

/** @brief PORTA13 Mode enumeration */
typedef enum
{
    PORTA_13_GPIO = 1U,
    PORTA_13_FTU0_CH3 = 2U,
    PORTA_13_CMP1_OUT = 4U,
    PORTA_13_FCUART0_RX = 5U,
    PORTA_13_FTU2_QD_PHA = 6U,
} PORT_A13MuxType;

/** @brief PORTA14 Mode enumeration */
typedef enum
{
    PORTA_14_GPIO = 1U,
    PORTA_14_FTU_FLT17 = 2U,
    PORTA_14_AONTIMER0_CLK1 = 3U,
    PORTA_14_CMP1_OUT = 4U,
    PORTA_14_FCUART0_TX = 5U,
} PORT_A14MuxType;

/** @brief PORTA15 Mode enumeration */
typedef enum
{
    PORTA_15_ADC1_SE28 = 0U,
    PORTA_15_GPIO = 1U,
    PORTA_15_FTU6_CH4 = 2U,
    PORTA_15_FTU5_QD_PHB = 3U,
    PORTA_15_FCUART10_TX = 4U,
    PORTA_15_TRGSEL_OUT0 = 5U,
    PORTA_15_FLEXCAN3_RX = 6U,
} PORT_A15MuxType;

/** @brief PORTA16 Mode enumeration */
typedef enum
{
    PORTA_16_GPIO = 1U,
    PORTA_16_FTU6_CH2 = 2U,
    PORTA_16_FCSMU_PIN0 = 3U,
} PORT_A16MuxType;

/** @brief PORTA17 Mode enumeration */
typedef enum
{
    PORTA_17_ADC2_SE19 = 0U,
    PORTA_17_GPIO = 1U,
    PORTA_17_FTU5_CH5 = 2U,
    PORTA_17_FTU_FLT15 = 3U,
    PORTA_17_FCSPI1_PCS2 = 4U,
    PORTA_17_FLEXCAN4_TX = 5U,
} PORT_A17MuxType;

/** @brief PORTA18 Mode enumeration */
typedef enum
{
    PORTA_18_ADC1_SE7 = 0U,
    PORTA_18_GPIO = 1U,
    PORTA_18_FTU3_CH6 = 2U,
    PORTA_18_FCUART1_TX = 3U,
} PORT_A18MuxType;

/** @brief PORTA19 Mode enumeration */
typedef enum
{
    PORTA_19_ADC1_SE3 = 0U,
    PORTA_19_GPIO = 1U,
    PORTA_19_FCUART1_RX = 3U,
    PORTA_19_FTU6_CH7 = 4U,
} PORT_A19MuxType;

/** @brief PORTA2 Mode enumeration */
typedef enum
{
    PORTA_2_GPIO = 1U,
    PORTA_2_FTU2_CH3 = 2U,
    PORTA_2_FCIIC0_SDA = 3U,
    PORTA_2_MSC1_FCLP = 4U,
    PORTA_2_FCUART0_RX = 6U,
} PORT_A2MuxType;

/** @brief PORTA20 Mode enumeration */
typedef enum
{
    PORTA_20_ADC1_SE6 = 0U,
    PORTA_20_GPIO = 1U,
    PORTA_20_FTU3_CH7 = 2U,
    PORTA_20_FCUART3_RTS = 3U,
} PORT_A20MuxType;

/** @brief PORTA21 Mode enumeration */
typedef enum
{
    PORTA_21_ADC0_SE2 = 0U,
    PORTA_21_GPIO = 1U,
    PORTA_21_FCUART6_RX = 2U,
    PORTA_21_FCUART3_CTS = 3U,
    PORTA_21_FTU2_CH5 = 4U,
} PORT_A21MuxType;

/** @brief PORTA22 Mode enumeration */
typedef enum
{
    PORTA_22_ADC0_SE1 = 0U,
    PORTA_22_GPIO = 1U,
    PORTA_22_FTU2_CH3 = 2U,
    PORTA_22_FTU2_QD_PHA = 3U,
    PORTA_22_FCUART7_RX = 4U,
} PORT_A22MuxType;

/** @brief PORTA23 Mode enumeration */
typedef enum
{
    PORTA_23_ADC0_SE14_CMP0_IN6 = 0U,
    PORTA_23_GPIO = 1U,
    PORTA_23_FTU4_CH1 = 2U,
    PORTA_23_FCUART3_RX = 3U,
    PORTA_23_TRACE_D0 = 4U,
    PORTA_23_FTU4_QD_PHA = 5U,
} PORT_A23MuxType;

/** @brief PORTA24 Mode enumeration */
typedef enum
{
    PORTA_24_ADC0_SE15_CMP0_IN7 = 0U,
    PORTA_24_GPIO = 1U,
    PORTA_24_FTU4_CH0 = 2U,
    PORTA_24_FCUART3_TX = 3U,
    PORTA_24_TRACE_D1 = 4U,
    PORTA_24_FTU4_QD_PHB = 5U,
} PORT_A24MuxType;

/** @brief PORTA25 Mode enumeration */
typedef enum
{
    PORTA_25_ADC0_SE11 = 0U,
    PORTA_25_GPIO = 1U,
    PORTA_25_FTU4_CH3 = 2U,
    PORTA_25_FCSPI2_SOUT = 5U,
} PORT_A25MuxType;

/** @brief PORTA26 Mode enumeration */
typedef enum
{
    PORTA_26_CMP0_IN1 = 0U,
    PORTA_26_GPIO = 1U,
    PORTA_26_FTU2_CH2 = 2U,
} PORT_A26MuxType;

/** @brief PORTA27 Mode enumeration */
typedef enum
{
    PORTA_27_ADC0_SE16 = 0U,
    PORTA_27_GPIO = 1U,
    PORTA_27_FTU5_CH7 = 2U,
    PORTA_27_FCUART0_TX = 3U,
    PORTA_27_TRACE_D2 = 4U,
    PORTA_27_FCSPI1_PCS0 = 5U,
} PORT_A27MuxType;

/** @brief PORTA28 Mode enumeration */
typedef enum
{
    PORTA_28_ADC0_SE18 = 0U,
    PORTA_28_GPIO = 1U,
    PORTA_28_FTU5_CH5 = 2U,
    PORTA_28_FCUART0_RX = 3U,
    PORTA_28_FCSPI1_SCK = 5U,
} PORT_A28MuxType;

/** @brief PORTA29 Mode enumeration */
typedef enum
{
    PORTA_29_ADC0_SE19 = 0U,
    PORTA_29_GPIO = 1U,
    PORTA_29_FTU5_CH4 = 2U,
    PORTA_29_FCSPI1_SIN = 5U,
} PORT_A29MuxType;

/** @brief PORTA3 Mode enumeration */
typedef enum
{
    PORTA_3_GPIO = 1U,
    PORTA_3_FTU2_CH2 = 2U,
    PORTA_3_FCIIC0_SCL = 3U,
    PORTA_3_FCUART0_TX = 6U,
} PORT_A3MuxType;

/** @brief PORTA30 Mode enumeration */
typedef enum
{
    PORTA_30_ADC0_SE25 = 0U,
    PORTA_30_GPIO = 1U,
    PORTA_30_FTU5_CH2 = 2U,
    PORTA_30_FCUART2_RX = 3U,
    PORTA_30_TRACE_D5 = 4U,
    PORTA_30_FCSPI1_PCS2 = 5U,
    PORTA_30_FTU5_QD_PHB = 6U,
} PORT_A30MuxType;

/** @brief PORTA31 Mode enumeration */
typedef enum
{
    PORTA_31_ADC0_SE29 = 0U,
    PORTA_31_GPIO = 1U,
    PORTA_31_FTU0_CH6 = 2U,
    PORTA_31_FCUART5_TX = 3U,
    PORTA_31_FTU_FLT3 = 4U,
    PORTA_31_FLEXCAN3_TX = 5U,
} PORT_A31MuxType;

/** @brief PORTA4 Mode enumeration */
typedef enum
{
    PORTA_4_GPIO = 1U,
    PORTA_4_CMP0_OUT = 2U,
    PORTA_4_JTAG_TMS_SWD_DIO = 7U,
} PORT_A4MuxType;

/** @brief PORTA6 Mode enumeration */
typedef enum
{
    PORTA_6_ADC2_SE13 = 0U,
    PORTA_6_GPIO = 1U,
    PORTA_6_FTU5_CH0 = 2U,
    PORTA_6_FTU_FLT13 = 3U,
    PORTA_6_FCUART1_CTS = 4U,
    PORTA_6_TRGSEL_OUT4 = 5U,
    PORTA_6_SDDF0_CH0 = 6U,
    PORTA_6_FCSPI7_SIN = 7U,
} PORT_A6MuxType;

/** @brief PORTA7 Mode enumeration */
typedef enum
{
    PORTA_7_ADC2_SE11 = 0U,
    PORTA_7_GPIO = 1U,
    PORTA_7_FTU7_CH6 = 2U,
    PORTA_7_FTU_FLT12 = 3U,
    PORTA_7_FCUART1_RTS = 4U,
    PORTA_7_FCSPI4_SIN = 5U,
} PORT_A7MuxType;

/** @brief PORTA8 Mode enumeration */
typedef enum
{
    PORTA_8_ADC1_SE14 = 0U,
    PORTA_8_GPIO = 1U,
    PORTA_8_FCUART2_RX = 2U,
} PORT_A8MuxType;

/** @brief PORTA9 Mode enumeration */
typedef enum
{
    PORTA_9_ADC1_SE15 = 0U,
    PORTA_9_GPIO = 1U,
    PORTA_9_FCUART2_TX = 2U,
    PORTA_9_RTC_CLKOUT = 3U,
} PORT_A9MuxType;

/** @brief PORTB0 Mode enumeration */
typedef enum
{
    PORTB_0_ADC3_SE18 = 0U,
    PORTB_0_GPIO = 1U,
    PORTB_0_SDDF0_BREAK3 = 2U,
    PORTB_0_FCUART14_TX = 4U,
    PORTB_0_FLEXCAN0_RX = 5U,
    PORTB_0_FTU3_CH6 = 6U,
} PORT_B0MuxType;

/** @brief PORTB1 Mode enumeration */
typedef enum
{
    PORTB_1_ADC3_SE17 = 0U,
    PORTB_1_GPIO = 1U,
    PORTB_1_SDDF0_BREAK2 = 2U,
    PORTB_1_FTU_TCK0 = 3U,
    PORTB_1_FCUART14_RX = 4U,
    PORTB_1_FLEXCAN0_TX = 5U,
    PORTB_1_FTU3_CH5 = 6U,
} PORT_B1MuxType;

/** @brief PORTB10 Mode enumeration */
typedef enum
{
    PORTB_10_GPIO = 1U,
    PORTB_10_FTU2_CH5 = 2U,
    PORTB_10_TRGSEL_OUT2 = 3U,
    PORTB_10_FLEXCAN7_RX = 5U,
} PORT_B10MuxType;

/** @brief PORTB13 Mode enumeration */
typedef enum
{
    PORTB_13_ADC2_SE28 = 0U,
    PORTB_13_GPIO = 1U,
    PORTB_13_FTU3_CH2 = 2U,
    PORTB_13_MSC1_SDI3 = 4U,
    PORTB_13_FCUART16_TX = 5U,
} PORT_B13MuxType;

/** @brief PORTB14 Mode enumeration */
typedef enum
{
    PORTB_14_ADC2_SE27 = 0U,
    PORTB_14_GPIO = 1U,
    PORTB_14_FTU3_CH1 = 2U,
    PORTB_14_FCUART4_RX = 3U,
    PORTB_14_MSC1_EN3 = 4U,
} PORT_B14MuxType;

/** @brief PORTB15 Mode enumeration */
typedef enum
{
    PORTB_15_ADC2_SE26 = 0U,
    PORTB_15_GPIO = 1U,
    PORTB_15_FTU3_CH0 = 2U,
    PORTB_15_FCUART4_TX = 3U,
    PORTB_15_MSC1_SDI2 = 4U,
} PORT_B15MuxType;

/** @brief PORTB16 Mode enumeration */
typedef enum
{
    PORTB_16_ADC2_SE25 = 0U,
    PORTB_16_GPIO = 1U,
    PORTB_16_FTU5_CH7 = 2U,
    PORTB_16_FCUART5_CTS = 3U,
    PORTB_16_MSC1_EN2 = 4U,
} PORT_B16MuxType;

/** @brief PORTB17 Mode enumeration */
typedef enum
{
    PORTB_17_ADC2_SE20 = 0U,
    PORTB_17_GPIO = 1U,
    PORTB_17_FTU5_CH6 = 2U,
    PORTB_17_FCSPI1_PCS3 = 4U,
    PORTB_17_FLEXCAN4_RX = 5U,
    PORTB_17_SDDF0_CLK3 = 6U,
} PORT_B17MuxType;

/** @brief PORTB18 Mode enumeration */
typedef enum
{
    PORTB_18_ADC0_SE30 = 0U,
    PORTB_18_GPIO = 1U,
    PORTB_18_FTU0_CH5 = 2U,
    PORTB_18_FCUART5_RX = 3U,
    PORTB_18_FLEXCAN3_RX = 5U,
} PORT_B18MuxType;

/** @brief PORTB19 Mode enumeration */
typedef enum
{
    PORTB_19_ADC0_SE31 = 0U,
    PORTB_19_GPIO = 1U,
    PORTB_19_FTU0_CH4 = 2U,
} PORT_B19MuxType;

/** @brief PORTB20 Mode enumeration */
typedef enum
{
    PORTB_20_ADC3_SE31_CMP2_IN0 = 0U,
    PORTB_20_GPIO = 1U,
    PORTB_20_FTU1_CH0 = 2U,
    PORTB_20_FCUART1_TX = 3U,
    PORTB_20_ENET_PPS0 = 5U,
    PORTB_20_SCG_CLKOUT = 7U,
} PORT_B20MuxType;

/** @brief PORTB21 Mode enumeration */
typedef enum
{
    PORTB_21_ADC3_SE30_CMP2_IN1 = 0U,
    PORTB_21_GPIO = 1U,
    PORTB_21_FTU1_CH1 = 2U,
    PORTB_21_FCUART1_RX = 3U,
    PORTB_21_ENET_PPS1 = 5U,
    PORTB_21_RTC_CLKOUT = 7U,
} PORT_B21MuxType;

/** @brief PORTB22 Mode enumeration */
typedef enum
{
    PORTB_22_GPIO = 1U,
    PORTB_22_FTU8_CH3 = 2U,
    PORTB_22_FCUART1_TX = 3U,
    PORTB_22_TRACE_D5 = 4U,
    PORTB_22_OSPI_A_IO0 = 6U,
    PORTB_22_FCSPI3_PCS2 = 7U,
} PORT_B22MuxType;

/** @brief PORTB23 Mode enumeration */
typedef enum
{
    PORTB_23_GPIO = 1U,
    PORTB_23_FTU_FLT9 = 2U,
    PORTB_23_FCSPI2_PCS0 = 3U,
    PORTB_23_FTU7_CH3 = 4U,
    PORTB_23_ENET_RXD3 = 5U,
} PORT_B23MuxType;

/** @brief PORTB24 Mode enumeration */
typedef enum
{
    PORTB_24_ADC3_SE29_CMP2_IN2 = 0U,
    PORTB_24_GPIO = 1U,
    PORTB_24_FTU1_CH2 = 2U,
} PORT_B24MuxType;

/** @brief PORTB25 Mode enumeration */
typedef enum
{
    PORTB_25_ADC3_SE19 = 0U,
    PORTB_25_GPIO = 1U,
    PORTB_25_FCSPI2_PCS0 = 4U,
    PORTB_25_FTU3_CH6 = 6U,
} PORT_B25MuxType;

/** @brief PORTB26 Mode enumeration */
typedef enum
{
    PORTB_26_GPIO = 1U,
    PORTB_26_FTU6_CH0 = 2U,
    PORTB_26_ENET_COL = 5U,
    PORTB_26_FCSPI3_SIN = 7U,
} PORT_B26MuxType;

/** @brief PORTB27 Mode enumeration */
typedef enum
{
    PORTB_27_ADC3_SE21 = 0U,
    PORTB_27_GPIO = 1U,
    PORTB_27_FTU7_CH0 = 2U,
    PORTB_27_FTU1_QD_PHB = 3U,
    PORTB_27_FCSPI2_SOUT = 4U,
} PORT_B27MuxType;

/** @brief PORTB28 Mode enumeration */
typedef enum
{
    PORTB_28_ADC3_SE22 = 0U,
    PORTB_28_GPIO = 1U,
    PORTB_28_FTU7_CH1 = 2U,
    PORTB_28_FCSPI2_SIN = 4U,
} PORT_B28MuxType;

/** @brief PORTB29 Mode enumeration */
typedef enum
{
    PORTB_29_ADC3_SE0 = 0U,
    PORTB_29_GPIO = 1U,
    PORTB_29_FTU1_CH3 = 2U,
    PORTB_29_FCUART12_RX = 5U,
    PORTB_29_MSC0_FCLP = 7U,
} PORT_B29MuxType;

/** @brief PORTB3 Mode enumeration */
typedef enum
{
    PORTB_3_ADC3_SE20 = 0U,
    PORTB_3_GPIO = 1U,
    PORTB_3_FTU1_QD_PHA = 3U,
    PORTB_3_FCSPI2_SCK = 4U,
    PORTB_3_FTU3_CH7 = 6U,
} PORT_B3MuxType;

/** @brief PORTB30 Mode enumeration */
typedef enum
{
    PORTB_30_GPIO = 1U,
    PORTB_30_FTU6_CH1 = 2U,
    PORTB_30_FCIIC1_SCL = 3U,
    PORTB_30_FCUART12_TX = 4U,
    PORTB_30_ENET_CRS = 5U,
    PORTB_30_FCSPI3_SOUT = 7U,
} PORT_B30MuxType;

/** @brief PORTB31 Mode enumeration */
typedef enum
{
    PORTB_31_GPIO = 1U,
    PORTB_31_FTU7_CH1 = 2U,
    PORTB_31_FCSPI2_SCK = 3U,
    PORTB_31_ENET_RXD1 = 5U,
} PORT_B31MuxType;

/** @brief PORTB4 Mode enumeration */
typedef enum
{
    PORTB_4_GPIO = 1U,
    PORTB_4_FTU7_CH7 = 2U,
    PORTB_4_FCUART9_RX = 4U,
    PORTB_4_ENET_MDIO = 5U,
} PORT_B4MuxType;

/** @brief PORTB5 Mode enumeration */
typedef enum
{
    PORTB_5_GPIO = 1U,
    PORTB_5_FTU6_CH2 = 2U,
    PORTB_5_FCIIC1_SDA = 3U,
    PORTB_5_ENET_MDC = 5U,
} PORT_B5MuxType;

/** @brief PORTB6 Mode enumeration */
typedef enum
{
    PORTB_6_XTAL = 0U,
    PORTB_6_GPIO = 1U,
} PORT_B6MuxType;

/** @brief PORTB7 Mode enumeration */
typedef enum
{
    PORTB_7_EXTAL = 0U,
    PORTB_7_GPIO = 1U,
} PORT_B7MuxType;

/** @brief PORTB8 Mode enumeration */
typedef enum
{
    PORTB_8_GPIO = 1U,
    PORTB_8_FTU4_CH2 = 2U,
    PORTB_8_FLEXCAN4_TX = 3U,
    PORTB_8_FCUART11_RX = 4U,
    PORTB_8_MSC1_SDI0 = 5U,
    PORTB_8_FCUART1_CTS = 6U,
} PORT_B8MuxType;

/** @brief PORTB9 Mode enumeration */
typedef enum
{
    PORTB_9_GPIO = 1U,
    PORTB_9_FTU2_CH7 = 2U,
    PORTB_9_FCUART12_TX = 3U,
    PORTB_9_TRGSEL_OUT1 = 5U,
} PORT_B9MuxType;

/** @brief PORTC0 Mode enumeration */
typedef enum
{
    PORTC_0_GPIO = 1U,
    PORTC_0_FTU8_CH6 = 2U,
    PORTC_0_TRACE_D6 = 4U,
    PORTC_0_ENET_RXD1 = 5U,
    PORTC_0_OSPI_A_IO3 = 6U,
    PORTC_0_FCSPI3_PCS1 = 7U,
} PORT_C0MuxType;

/** @brief PORTC1 Mode enumeration */
typedef enum
{
    PORTC_1_GPIO = 1U,
    PORTC_1_FTU7_CH5 = 2U,
    PORTC_1_ENET_RXD0 = 5U,
    PORTC_1_OSPI_A_IO2  = 6U,
    PORTC_1_FCSPI3_PCS0 = 7U,
} PORT_C1MuxType;

/** @brief PORTC10 Mode enumeration */
typedef enum
{
    PORTC_10_ADC2_SE3 = 0U,
    PORTC_10_GPIO = 1U,
    PORTC_10_FTU3_CH4 = 2U,
    PORTC_10_FLEXCAN4_RX = 4U,
    PORTC_10_FCUART13_TX = 5U,
    PORTC_10_MSC0_EN1 = 7U,
} PORT_C10MuxType;

/** @brief PORTC11 Mode enumeration */
typedef enum
{
    PORTC_11_ADC2_SE6 = 0U,
    PORTC_11_GPIO = 1U,
    PORTC_11_FTU3_CH3 = 2U,
    PORTC_11_FLEXCAN4_TX = 4U,
    PORTC_11_FCUART13_RX = 5U,
    PORTC_11_MSC0_EN0 = 7U,
} PORT_C11MuxType;

/** @brief PORTC12 Mode enumeration */
typedef enum
{
    PORTC_12_ADC3_SE1 = 0U,
    PORTC_12_GPIO = 1U,
    PORTC_12_FTU1_CH5 = 2U,
    PORTC_12_TRGSEL_OUT5 = 5U,
    PORTC_12_FLEXCAN5_RX = 6U,
    PORTC_12_MSC0_EN2 = 7U,
} PORT_C12MuxType;

/** @brief PORTC13 Mode enumeration */
typedef enum
{
    PORTC_13_ADC3_SE4 = 0U,
    PORTC_13_GPIO = 1U,
    PORTC_13_FTU1_CH4 = 2U,
    PORTC_13_TRGSEL_OUT6 = 5U,
    PORTC_13_FLEXCAN5_TX = 6U,
    PORTC_13_MSC0_SOP = 7U,
} PORT_C13MuxType;

/** @brief PORTC14 Mode enumeration */
typedef enum
{
    PORTC_14_GPIO = 1U,
    PORTC_14_FTU7_CH4 = 2U,
    PORTC_14_FCUART1_RX = 3U,
    PORTC_14_FCIIC1_SDA = 4U,
    PORTC_14_OSPI_A_RWDS  = 6U,
} PORT_C14MuxType;

/** @brief PORTC15 Mode enumeration */
typedef enum
{
    PORTC_15_GPIO = 1U,
    PORTC_15_FTU8_CH4 = 2U,
    PORTC_15_FCSPI2_PCS3 = 3U,
    PORTC_15_SCG_CLKOUT = 4U,
    PORTC_15_ENET_RXD3 = 5U,
    PORTC_15_OSPI_A_IO1  = 6U,
    PORTC_15_FCSPI3_PCS3 = 7U,
} PORT_C15MuxType;

/** @brief PORTC16 Mode enumeration */
typedef enum
{
    PORTC_16_GPIO = 1U,
    PORTC_16_FTU_FLT7 = 2U,
    PORTC_16_FCSPI2_SOUT = 3U,
    PORTC_16_TRGSEL_OUT7 = 4U,
    PORTC_16_ENET_RXD0 = 5U,
    PORTC_16_FCUART5_RX = 7U,
} PORT_C16MuxType;

/** @brief PORTC17 Mode enumeration */
typedef enum
{
    PORTC_17_GPIO = 1U,
    PORTC_17_FTU_FLT6 = 2U,
    PORTC_17_TRGSEL_OUT6 = 4U,
    PORTC_17_ENET_RX_ER = 5U,
    PORTC_17_FCUART5_TX = 7U,
} PORT_C17MuxType;

/** @brief PORTC18 Mode enumeration */
typedef enum
{
    PORTC_18_GPIO = 1U,
    PORTC_18_FTU7_CH2 = 2U,
    PORTC_18_FCSPI2_SIN = 3U,
    PORTC_18_ENET_RXD2 = 5U,
} PORT_C18MuxType;

/** @brief PORTC19 Mode enumeration */
typedef enum
{
    PORTC_19_ADC3_SE5 = 0U,
    PORTC_19_GPIO = 1U,
    PORTC_19_FTU1_CH6 = 2U,
    PORTC_19_FLEXCAN6_TX = 3U,
    PORTC_19_MSC0_EN3 = 7U,
} PORT_C19MuxType;

/** @brief PORTC2 Mode enumeration */
typedef enum
{
    PORTC_2_GPIO = 1U,
    PORTC_2_FTU6_CH3 = 2U,
    PORTC_2_FCUART0_RX = 3U,
    PORTC_2_TRACE_CLKOUT = 4U,
    PORTC_2_ENET_TXD0 = 5U,
} PORT_C2MuxType;

/** @brief PORTC20 Mode enumeration */
typedef enum
{
    PORTC_20_ADC3_SE2 = 0U,
    PORTC_20_GPIO = 1U,
    PORTC_20_FTU1_CH7 = 2U,
    PORTC_20_FLEXCAN9_TX = 5U,
    PORTC_20_MSC0_SDI2 = 7U,
} PORT_C20MuxType;

/** @brief PORTC21 Mode enumeration */
typedef enum
{
    PORTC_21_ADC3_SE6 = 0U,
    PORTC_21_GPIO = 1U,
    PORTC_21_FTU3_CH0 = 2U,
    PORTC_21_FLEXCAN9_RX = 5U,
    PORTC_21_MSC0_SDI3 = 7U,
} PORT_C21MuxType;

/** @brief PORTC22 Mode enumeration */
typedef enum
{
    PORTC_22_ADC3_SE10 = 0U,
    PORTC_22_GPIO = 1U,
    PORTC_22_FTU3_CH1 = 2U,
    PORTC_22_FCUART17_RTS = 6U,
    PORTC_22_MSC0_SDI1 = 7U,
} PORT_C22MuxType;

/** @brief PORTC23 Mode enumeration */
typedef enum
{
    PORTC_23_ADC2_SE0 = 0U,
    PORTC_23_GPIO = 1U,
    PORTC_23_FTU6_CH6 = 3U,
    PORTC_23_FCUART2_RTS = 4U,
    PORTC_23_FCUART12_TX = 5U,
    PORTC_23_MSC0_SDI0 = 7U,
} PORT_C23MuxType;

/** @brief PORTC24 Mode enumeration */
typedef enum
{
    PORTC_24_ADC2_SE2 = 0U,
    PORTC_24_GPIO = 1U,
    PORTC_24_FTU3_CH2 = 2U,
    PORTC_24_FLEXCAN6_RX = 3U,
    PORTC_24_FCUART2_CTS = 4U,
} PORT_C24MuxType;

/** @brief PORTC25 Mode enumeration */
typedef enum
{
    PORTC_25_GPIO = 1U,
    PORTC_25_FTU3_CH3 = 2U,
    PORTC_25_FCUART5_RTS = 3U,
    PORTC_25_FCSPI5_PCS0 = 4U,
    PORTC_25_FLEXCAN2_TX = 5U,
} PORT_C25MuxType;

/** @brief PORTC28 Mode enumeration */
typedef enum
{
    PORTC_28_ADC3_SE23 = 0U,
    PORTC_28_GPIO = 1U,
    PORTC_28_FTU7_CH2 = 2U,
    PORTC_28_FLEXCAN3_TX = 4U,
    PORTC_28_SDDF0_CLK0 = 6U,
} PORT_C28MuxType;

/** @brief PORTC29 Mode enumeration */
typedef enum
{
    PORTC_29_ADC2_SE10 = 0U,
    PORTC_29_GPIO = 1U,
    PORTC_29_FTU7_CH5 = 2U,
    PORTC_29_FLEXCAN3_RX = 4U,
    PORTC_29_SDDF0_CLK1 = 6U,
} PORT_C29MuxType;

/** @brief PORTC3 Mode enumeration */
typedef enum
{
    PORTC_3_GPIO = 1U,
    PORTC_3_FTU6_CH2 = 2U,
    PORTC_3_FCUART0_TX = 3U,
    PORTC_3_ENET_TX_ER = 5U,
    PORTC_3_FCSPI3_PCS0 = 7U,
} PORT_C3MuxType;

/** @brief PORTC30 Mode enumeration */
typedef enum
{
    PORTC_30_ADC2_SE12 = 0U,
    PORTC_30_GPIO = 1U,
    PORTC_30_FTU7_CH7 = 2U,
    PORTC_30_FTU5_QD_PHA = 4U,
    PORTC_30_FCSPI4_SOUT = 5U,
} PORT_C30MuxType;

/** @brief PORTC31 Mode enumeration */
typedef enum
{
    PORTC_31_ADC2_SE14 = 0U,
    PORTC_31_GPIO = 1U,
    PORTC_31_FTU5_CH1 = 2U,
    PORTC_31_FTU5_QD_PHB = 4U,
    PORTC_31_TRGSEL_OUT3 = 5U,
    PORTC_31_SDDF0_CH1 = 6U,
    PORTC_31_FCSPI7_SCK = 7U,
} PORT_C31MuxType;

/** @brief PORTC4 Mode enumeration */
typedef enum
{
    PORTC_4_GPIO = 1U,
    PORTC_4_FTU3_CH4 = 2U,
    PORTC_4_FTU1_QD_PHB = 6U,
    PORTC_4_JTAG_TCLK_SWD_CLK = 7U,
} PORT_C4MuxType;

/** @brief PORTC5 Mode enumeration */
typedef enum
{
    PORTC_5_GPIO = 1U,
    PORTC_5_FTU3_CH3 = 2U,
    PORTC_5_FTU1_QD_PHA = 6U,
    PORTC_5_JTAG_TDI = 7U,
} PORT_C5MuxType;

/** @brief PORTC6 Mode enumeration */
typedef enum
{
    PORTC_6_GPIO = 1U,
    PORTC_6_FCUART1_RX = 2U,
    PORTC_6_FTU3_CH2 = 4U,
    PORTC_6_FTU1_QD_PHB = 6U,
} PORT_C6MuxType;

/** @brief PORTC7 Mode enumeration */
typedef enum
{
    PORTC_7_ADC1_SE30 = 0U,
    PORTC_7_GPIO = 1U,
    PORTC_7_FCUART1_TX = 2U,
    PORTC_7_FTU3_CH3 = 4U,
} PORT_C7MuxType;

/** @brief PORTC8 Mode enumeration */
typedef enum
{
    PORTC_8_ADC2_SE9 = 0U,
    PORTC_8_GPIO = 1U,
    PORTC_8_FTU7_CH4 = 2U,
    PORTC_8_FTU_FLT11 = 3U,
    PORTC_8_FTU4_QD_PHB = 4U,
    PORTC_8_FCSPI4_PCS0 = 5U,
    PORTC_8_FCUART0_CTS = 6U,
} PORT_C8MuxType;

/** @brief PORTC9 Mode enumeration */
typedef enum
{
    PORTC_9_ADC2_SE8 = 0U,
    PORTC_9_GPIO = 1U,
    PORTC_9_FTU7_CH3 = 2U,
    PORTC_9_FTU_FLT10 = 3U,
    PORTC_9_FTU4_QD_PHA = 4U,
    PORTC_9_FCSPI4_SCK = 5U,
    PORTC_9_FCUART0_RTS = 6U,
} PORT_C9MuxType;

/** @brief PORTD0 Mode enumeration */
typedef enum
{
    PORTD_0_ADC0_SE13 = 0U,
    PORTD_0_GPIO = 1U,
    PORTD_0_FTU4_CH2 = 2U,
    PORTD_0_FCUART17_TX = 6U,
    PORTD_0_TRGSEL_OUT1 = 7U,
} PORT_D0MuxType;

/** @brief PORTD1 Mode enumeration */
typedef enum
{
    PORTD_1_ADC0_SE6 = 0U,
    PORTD_1_GPIO = 1U,
    PORTD_1_FCUART6_TX = 2U,
    PORTD_1_FTU2_CH4 = 4U,
    PORTD_1_TRGSEL_OUT2 = 7U,
} PORT_D1MuxType;

/** @brief PORTD10 Mode enumeration */
typedef enum
{
    PORTD_10_GPIO = 1U,
    PORTD_10_FTU6_CH7 = 2U,
    PORTD_10_FTU2_QD_PHB = 3U,
    PORTD_10_ENET_RX_CLK = 5U,
} PORT_D10MuxType;

/** @brief PORTD11 Mode enumeration */
typedef enum
{
    PORTD_11_GPIO = 1U,
    PORTD_11_FTU6_CH6 = 2U,
    PORTD_11_FTU2_QD_PHA = 3U,
    PORTD_11_TRACE_D4 = 4U,
    PORTD_11_ENET_TX_CLK = 5U,
    PORTD_11_OSPI_A_IO7 = 6U,
} PORT_D11MuxType;

/** @brief PORTD12 Mode enumeration */
typedef enum
{
    PORTD_12_GPIO = 1U,
    PORTD_12_FTU6_CH5 = 2U,
    PORTD_12_FCUART2_RTS = 3U,
    PORTD_12_TRACE_D3 = 4U,
    PORTD_12_ENET_TX_EN_CTL = 5U,
    PORTD_12_OSPI_A_IO6 = 6U,
    PORTD_12_FCSPI3_SOUT = 7U,
} PORT_D12MuxType;

/** @brief PORTD15 Mode enumeration */
typedef enum
{
    PORTD_15_ADC0_SE27 = 0U,
    PORTD_15_GPIO = 1U,
    PORTD_15_FTU5_CH0 = 2U,
    PORTD_15_FLEXCAN2_RX = 3U,
    PORTD_15_TRACE_D7 = 4U,
    PORTD_15_ENET_PPS2 = 5U,
    PORTD_15_FCUART2_RTS = 6U,
} PORT_D15MuxType;

/** @brief PORTD16 Mode enumeration */
typedef enum
{
    PORTD_16_ADC0_SE26 = 0U,
    PORTD_16_GPIO = 1U,
    PORTD_16_FTU5_CH1 = 2U,
    PORTD_16_FLEXCAN2_TX = 3U,
    PORTD_16_TRACE_D6 = 4U,
    PORTD_16_FCSPI1_PCS3 = 5U,
} PORT_D16MuxType;

/** @brief PORTD17 Mode enumeration */
typedef enum
{
    PORTD_17_ADC0_SE24 = 0U,
    PORTD_17_GPIO = 1U,
    PORTD_17_FTU5_CH3 = 2U,
    PORTD_17_FCUART2_TX = 3U,
    PORTD_17_TRACE_D4 = 4U,
    PORTD_17_FCSPI1_PCS1 = 5U,
    PORTD_17_FTU5_QD_PHA = 6U,
} PORT_D17MuxType;

/** @brief PORTD18 Mode enumeration */
typedef enum
{
    PORTD_18_ADC2_SE16 = 0U,
    PORTD_18_GPIO = 1U,
    PORTD_18_FTU5_CH3 = 2U,
    PORTD_18_FCIIC1_SDA = 4U,
    PORTD_18_SDDF0_CH3 = 6U,
    PORTD_18_FCSPI7_PCS0 = 7U,
} PORT_D18MuxType;

/** @brief PORTD19 Mode enumeration */
typedef enum
{
    PORTD_19_ADC2_SE17 = 0U,
    PORTD_19_GPIO = 1U,
    PORTD_19_FTU5_CH4 = 2U,
    PORTD_19_FCIIC1_SCL = 4U,
    PORTD_19_SDDF0_CLK2 = 6U,
} PORT_D19MuxType;

/** @brief PORTD2 Mode enumeration */
typedef enum
{
    PORTD_2_GPIO = 1U,
    PORTD_2_FTU2_CH0 = 2U,
    PORTD_2_FCSPI1_SCK = 4U,
} PORT_D2MuxType;

/** @brief PORTD20 Mode enumeration */
typedef enum
{
    PORTD_20_ADC2_SE30 = 0U,
    PORTD_20_GPIO = 1U,
    PORTD_20_FTU3_CH4 = 2U,
    PORTD_20_FCUART5_RX = 3U,
    PORTD_20_FCSPI1_PCS1 = 4U,
} PORT_D20MuxType;

/** @brief PORTD21 Mode enumeration */
typedef enum
{
    PORTD_21_GPIO = 1U,
    PORTD_21_FTU3_CH5 = 2U,
    PORTD_21_FCUART5_TX = 3U,
    PORTD_21_FTU9_CH7 = 4U,
} PORT_D21MuxType;

/** @brief PORTD23 Mode enumeration */
typedef enum
{
    PORTD_23_ADC2_SE31 = 0U,
    PORTD_23_GPIO = 1U,
    PORTD_23_FTU2_CH1 = 2U,
    PORTD_23_FCSPI1_PCS0 = 4U,
} PORT_D23MuxType;

/** @brief PORTD24 Mode enumeration */
typedef enum
{
    PORTD_24_GPIO = 1U,
    PORTD_24_FTU2_CH4 = 2U,
    PORTD_24_MSC1_SOP = 4U,
    PORTD_24_FCUART16_RX = 5U,
} PORT_D24MuxType;

/** @brief PORTD25 Mode enumeration */
typedef enum
{
    PORTD_25_GPIO = 1U,
    PORTD_25_FTU2_CH6 = 2U,
    PORTD_25_FCUART12_TX = 3U,
    PORTD_25_FCUART4_RTS = 4U,
    PORTD_25_FLEXCAN7_TX = 5U,
} PORT_D25MuxType;

/** @brief PORTD26 Mode enumeration */
typedef enum
{
    PORTD_26_GPIO = 1U,
    PORTD_26_FTU4_CH0 = 2U,
    PORTD_26_FLEXCAN0_TX = 3U,
    PORTD_26_FCUART4_CTS = 4U,
} PORT_D26MuxType;

/** @brief PORTD27 Mode enumeration */
typedef enum
{
    PORTD_27_GPIO = 1U,
    PORTD_27_FTU4_CH1 = 2U,
    PORTD_27_FLEXCAN0_RX = 3U,
    PORTD_27_MSC1_EN0 = 5U,
} PORT_D27MuxType;

/** @brief PORTD28 Mode enumeration */
typedef enum
{
    PORTD_28_GPIO = 1U,
    PORTD_28_FTU4_CH3 = 2U,
    PORTD_28_FLEXCAN4_RX = 3U,
    PORTD_28_FCUART11_TX = 4U,
} PORT_D28MuxType;

/** @brief PORTD29 Mode enumeration */
typedef enum
{
    PORTD_29_GPIO = 1U,
    PORTD_29_FTU4_CH5 = 2U,
    PORTD_29_FCUART15_TX = 3U,
    PORTD_29_SENT1_RXD1 = 4U,
    PORTD_29_FTU1_QD_PHB = 5U,
    PORTD_29_MSC1_EN1 = 6U,
} PORT_D29MuxType;

/** @brief PORTD3 Mode enumeration */
typedef enum
{
    PORTD_3_GPIO = 1U,
    PORTD_3_FTU3_CH7 = 2U,
    PORTD_3_FCSPI1_SIN = 4U,
} PORT_D3MuxType;

/** @brief PORTD30 Mode enumeration */
typedef enum
{
    PORTD_30_GPIO = 1U,
    PORTD_30_FTU4_CH7 = 2U,
    PORTD_30_FLEXCAN5_TX = 3U,
    PORTD_30_SENT1_RXD3 = 4U,
    PORTD_30_FTU2_QD_PHB = 5U,
    PORTD_30_MSC1_SDI1 = 6U,
} PORT_D30MuxType;

/** @brief PORTD31 Mode enumeration */
typedef enum
{
    PORTD_31_ADC1_SE31 = 0U,
    PORTD_31_GPIO = 1U,
    PORTD_31_FTU6_CH0 = 2U,
    PORTD_31_MSC1_SDI3 = 5U,
    PORTD_31_FTU1_QD_PHA = 6U,
} PORT_D31MuxType;

/** @brief PORTD4 Mode enumeration */
typedef enum
{
    PORTD_4_GPIO = 1U,
    PORTD_4_FTU3_CH6 = 2U,
    PORTD_4_FCSPI1_SOUT = 4U,
    PORTD_4_FTU_FLT16 = 5U,
} PORT_D4MuxType;

/** @brief PORTD5 Mode enumeration */
typedef enum
{
    PORTD_5_GPIO = 1U,
    PORTD_5_FTU6_CH4 = 2U,
    PORTD_5_FCUART2_CTS = 3U,
    PORTD_5_TRACE_D2 = 4U,
    PORTD_5_ENET_TXD3 = 5U,
    PORTD_5_OSPI_A_IO5 = 6U,
    PORTD_5_FCSPI3_SIN = 7U,
} PORT_D5MuxType;

/** @brief PORTD6 Mode enumeration */
typedef enum
{
    PORTD_6_GPIO = 1U,
    PORTD_6_FCUART2_RX = 2U,
    PORTD_6_FLEXCAN3_RX = 3U,
    PORTD_6_TRACE_D1 = 4U,
    PORTD_6_ENET_TXD2 = 5U,
    PORTD_6_OSPI_A_IO4  = 6U,
    PORTD_6_FCSPI3_SCK = 7U,
} PORT_D6MuxType;

/** @brief PORTD7 Mode enumeration */
typedef enum
{
    PORTD_7_GPIO = 1U,
    PORTD_7_FCUART2_TX = 2U,
    PORTD_7_FLEXCAN3_TX = 3U,
    PORTD_7_TRACE_D0 = 4U,
    PORTD_7_ENET_TXD1 = 5U,
} PORT_D7MuxType;

/** @brief PORTD8 Mode enumeration */
typedef enum
{
    PORTD_8_GPIO = 1U,
    PORTD_8_FTU7_CH0 = 2U,
    PORTD_8_FCSPI2_PCS2 = 3U,
    PORTD_8_FTU1_CH6 = 4U,
    PORTD_8_ENET_RX_DV_CTL = 5U,
    PORTD_8_FCUART4_RX = 7U,
} PORT_D8MuxType;

/** @brief PORTD9 Mode enumeration */
typedef enum
{
    PORTD_9_GPIO = 1U,
    PORTD_9_FTU8_CH7 = 2U,
    PORTD_9_FCSPI2_PCS1 = 3U,
    PORTD_9_TRACE_D7 = 4U,
    PORTD_9_ENET_RXD2 = 5U,
    PORTD_9_OSPI_A_SCK  = 6U,
    PORTD_9_FCUART4_TX = 7U,
} PORT_D9MuxType;

/** @brief PORTE0 Mode enumeration */
typedef enum
{
    PORTE_0_CMP1_IN4 = 0U,
    PORTE_0_GPIO = 1U,
    PORTE_0_FCUART0_CTS = 2U,
    PORTE_0_FTU_TCK1 = 3U,
    PORTE_0_FCIIC1_SDA = 4U,
    PORTE_0_FCSPI0_SCK = 5U,
    PORTE_0_FTU_FLT19 = 6U,
} PORT_E0MuxType;

/** @brief PORTE1 Mode enumeration */
typedef enum
{
    PORTE_1_CMP1_IN5 = 0U,
    PORTE_1_GPIO = 1U,
    PORTE_1_FCUART0_RTS = 2U,
    PORTE_1_FCIIC1_SCL = 4U,
    PORTE_1_FCSPI0_SIN = 5U,
    PORTE_1_FTU_FLT18 = 6U,
} PORT_E1MuxType;

/** @brief PORTE10 Mode enumeration */
typedef enum
{
    PORTE_10_ADC0_SE9 = 0U,
    PORTE_10_GPIO = 1U,
    PORTE_10_SCG_CLKOUT = 2U,
    PORTE_10_FTU6_CH0 = 3U,
    PORTE_10_FCSPI2_SIN = 5U,
    PORTE_10_TRGSEL_OUT4 = 7U,
} PORT_E10MuxType;

/** @brief PORTE11 Mode enumeration */
typedef enum
{
    PORTE_11_ADC0_SE8 = 0U,
    PORTE_11_GPIO = 1U,
    PORTE_11_FTU2_CH1 = 2U,
    PORTE_11_FCSPI2_PCS0 = 5U,
    PORTE_11_TRGSEL_OUT5 = 7U,
} PORT_E11MuxType;

/** @brief PORTE12 Mode enumeration */
typedef enum
{
    PORTE_12_ADC0_SE17 = 0U,
    PORTE_12_GPIO = 1U,
    PORTE_12_FTU5_CH6 = 2U,
    PORTE_12_FTU_FLT2 = 3U,
    PORTE_12_TRACE_D3 = 4U,
    PORTE_12_FCSPI1_SOUT = 5U,
} PORT_E12MuxType;

/** @brief PORTE13 Mode enumeration */
typedef enum
{
    PORTE_13_ADC0_SE10 = 0U,
    PORTE_13_GPIO = 1U,
    PORTE_13_FTU2_CH0 = 2U,
    PORTE_13_FCSPI2_SCK = 5U,
} PORT_E13MuxType;

/** @brief PORTE14 Mode enumeration */
typedef enum
{
    PORTE_14_OSC32K_XTAL = 0U,
    PORTE_14_GPIO = 1U,
    PORTE_14_FTU0_CH3 = 2U,
    PORTE_14_FTU_FLT0 = 4U,
} PORT_E14MuxType;

/** @brief PORTE15 Mode enumeration */
typedef enum
{
    PORTE_15_ADC0_SE5 = 0U,
    PORTE_15_GPIO = 1U,
    PORTE_15_FCUART1_CTS = 2U,
    PORTE_15_FLEXCAN5_RX = 3U,
    PORTE_15_FTU2_CH6 = 4U,
    PORTE_15_TRGSEL_OUT6 = 7U,
} PORT_E15MuxType;

/** @brief PORTE16 Mode enumeration */
typedef enum
{
    PORTE_16_ADC1_SE2 = 0U,
    PORTE_16_GPIO = 1U,
    PORTE_16_FCUART1_RTS = 2U,
    PORTE_16_FLEXCAN5_TX = 3U,
    PORTE_16_FTU2_CH7 = 4U,
    PORTE_16_TRGSEL_OUT7 = 7U,
} PORT_E16MuxType;

/** @brief PORTE17 Mode enumeration */
typedef enum
{
    PORTE_17_GPIO = 1U,
    PORTE_17_FTU6_CH1 = 2U,
    PORTE_17_FCSMU_PIN1 = 3U,
} PORT_E17MuxType;

/** @brief PORTE18 Mode enumeration */
typedef enum
{
    PORTE_18_ADC1_SE29 = 0U,
    PORTE_18_GPIO = 1U,
    PORTE_18_FTU6_CH3 = 2U,
    PORTE_18_FTU5_QD_PHA = 3U,
    PORTE_18_FCUART10_RX = 4U,
    PORTE_18_FLEXCAN3_TX = 6U,
} PORT_E18MuxType;

/** @brief PORTE19 Mode enumeration */
typedef enum
{
    PORTE_19_ADC1_SE23 = 0U,
    PORTE_19_GPIO = 1U,
    PORTE_19_SCG_CLKOUT = 2U,
    PORTE_19_FCIIC0_SCL = 3U,
    PORTE_19_SENT0_RXD2 = 4U,
    PORTE_19_CMP0_OUT = 5U,
} PORT_E19MuxType;

/** @brief PORTE2 Mode enumeration */
typedef enum
{
    PORTE_2_ADC1_SE24 = 0U,
    PORTE_2_GPIO = 1U,
    PORTE_2_FTU6_CH6 = 2U,
    PORTE_2_FLEXCAN1_RX = 5U,
    PORTE_2_FCUART1_CTS = 6U,
} PORT_E2MuxType;

/** @brief PORTE20 Mode enumeration */
typedef enum
{
    PORTE_20_ADC1_SE22 = 0U,
    PORTE_20_GPIO = 1U,
    PORTE_20_FTU0_CH0 = 2U,
    PORTE_20_FCIIC0_SDA = 3U,
    PORTE_20_SENT0_RXD3 = 4U,
} PORT_E20MuxType;

/** @brief PORTE21 Mode enumeration */
typedef enum
{
    PORTE_21_ADC1_SE21 = 0U,
    PORTE_21_GPIO = 1U,
    PORTE_21_FTU0_CH1 = 2U,
    PORTE_21_FLEXCAN0_TX = 4U,
    PORTE_21_FCUART0_RTS = 5U,
} PORT_E21MuxType;

/** @brief PORTE22 Mode enumeration */
typedef enum
{
    PORTE_22_ADC1_SE20 = 0U,
    PORTE_22_GPIO = 1U,
    PORTE_22_FTU0_CH2 = 2U,
    PORTE_22_FLEXCAN0_RX = 4U,
    PORTE_22_FCUART0_CTS = 5U,
} PORT_E22MuxType;

/** @brief PORTE23 Mode enumeration */
typedef enum
{
    PORTE_23_CMP1_IN6 = 0U,
    PORTE_23_GPIO = 1U,
    PORTE_23_FTU0_CH4 = 2U,
    PORTE_23_FLEXCAN1_RX = 3U,
    PORTE_23_CMP2_OUT = 4U,
    PORTE_23_FCSPI0_PCS2 = 5U,
} PORT_E23MuxType;

/** @brief PORTE24 Mode enumeration */
typedef enum
{
    PORTE_24_CMP1_IN7 = 0U,
    PORTE_24_GPIO = 1U,
    PORTE_24_FTU0_CH5 = 2U,
    PORTE_24_FLEXCAN1_TX = 3U,
    PORTE_24_FCSPI0_PCS1 = 5U,
} PORT_E24MuxType;

/** @brief PORTE25 Mode enumeration */
typedef enum
{
    PORTE_25_ADC1_SE19 = 0U,
    PORTE_25_GPIO = 1U,
    PORTE_25_FTU0_CH6 = 2U,
    PORTE_25_AONTIMER0_CLK0 = 3U,
    PORTE_25_FCSPI0_PCS0 = 5U,
    PORTE_25_TRGSEL_OUT7 = 7U,
} PORT_E25MuxType;

/** @brief PORTE26 Mode enumeration */
typedef enum
{
    PORTE_26_ADC1_SE17 = 0U,
    PORTE_26_GPIO = 1U,
    PORTE_26_FTU3_CH2 = 2U,
    PORTE_26_AONTIMER0_CLK2 = 3U,
    PORTE_26_SENT0_RXD0 = 4U,
} PORT_E26MuxType;

/** @brief PORTE27 Mode enumeration */
typedef enum
{
    PORTE_27_ADC1_SE16 = 0U,
    PORTE_27_GPIO = 1U,
    PORTE_27_FTU3_CH5 = 2U,
    PORTE_27_SENT0_RXD1 = 4U,
} PORT_E27MuxType;

/** @brief PORTE3 Mode enumeration */
typedef enum
{
    PORTE_3_OSC32K_EXTAL = 0U,
    PORTE_3_GPIO = 1U,
    PORTE_3_FTU0_CH2 = 2U,
    PORTE_3_FTU_FLT1 = 4U,
    PORTE_3_FTU_TCK0 = 6U,
} PORT_E3MuxType;

/** @brief PORTE4 Mode enumeration */
typedef enum
{
    PORTE_4_CMP0_IN0 = 0U,
    PORTE_4_GPIO = 1U,
    PORTE_4_FTU2_QD_PHB = 2U,
    PORTE_4_FTU10_CH7 = 3U,
    PORTE_4_FCUART7_TX = 4U,
} PORT_E4MuxType;

/** @brief PORTE5 Mode enumeration */
typedef enum
{
    PORTE_5_ADC0_SE12 = 0U,
    PORTE_5_GPIO = 1U,
    PORTE_5_FTU_TCK2 = 2U,
    PORTE_5_FTU4_CH3 = 3U,
    PORTE_5_FCSPI2_PCS1 = 5U,
    PORTE_5_FCUART17_RX = 6U,
} PORT_E5MuxType;

/** @brief PORTE6 Mode enumeration */
typedef enum
{
    PORTE_6_ADC1_SE25 = 0U,
    PORTE_6_GPIO = 1U,
    PORTE_6_FTU6_CH5 = 2U,
    PORTE_6_FLEXCAN1_TX = 5U,
    PORTE_6_FCUART1_RTS = 6U,
} PORT_E6MuxType;

/** @brief PORTE7 Mode enumeration */
typedef enum
{
    PORTE_7_ADC2_SE15 = 0U,
    PORTE_7_GPIO = 1U,
    PORTE_7_FTU5_CH2 = 2U,
    PORTE_7_FTU_FLT14 = 3U,
    PORTE_7_SDDF0_CH2 = 6U,
    PORTE_7_FCSPI7_SOUT = 7U,
} PORT_E7MuxType;

/** @brief PORTE8 Mode enumeration */
typedef enum
{
    PORTE_8_GPIO = 1U,
    PORTE_8_FTU6_CH1 = 2U,
    PORTE_8_FCUART9_RX = 4U,
    PORTE_8_ENET_MDC = 5U,
    PORTE_8_FCSPI3_SCK = 7U,
} PORT_E8MuxType;

/** @brief PORTE9 Mode enumeration */
typedef enum
{
    PORTE_9_ADC0_SE28 = 0U,
    PORTE_9_GPIO = 1U,
    PORTE_9_FTU0_CH7 = 2U,
    PORTE_9_TRACE_CLKOUT = 4U,
    PORTE_9_ENET_PPS3 = 5U,
    PORTE_9_FCUART2_CTS = 6U,
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
    PORT_A18MuxType      ePortA18Mode;
    PORT_A19MuxType      ePortA19Mode;
    PORT_A20MuxType      ePortA20Mode;
    PORT_A21MuxType      ePortA21Mode;
    PORT_A22MuxType      ePortA22Mode;
    PORT_A23MuxType      ePortA23Mode;
    PORT_A24MuxType      ePortA24Mode;
    PORT_A25MuxType      ePortA25Mode;
    PORT_A26MuxType      ePortA26Mode;
    PORT_A27MuxType      ePortA27Mode;
    PORT_A28MuxType      ePortA28Mode;
    PORT_A29MuxType      ePortA29Mode;
    PORT_A30MuxType      ePortA30Mode;
    PORT_A31MuxType      ePortA31Mode;
    PORT_B0MuxType       ePortB0Mode;
    PORT_B1MuxType       ePortB1Mode;
    PORT_B3MuxType       ePortB3Mode;
    PORT_B4MuxType       ePortB4Mode;
    PORT_B5MuxType       ePortB5Mode;
    PORT_B6MuxType       ePortB6Mode;
    PORT_B7MuxType       ePortB7Mode;
    PORT_B8MuxType       ePortB8Mode;
    PORT_B9MuxType       ePortB9Mode;
    PORT_B10MuxType      ePortB10Mode;
    PORT_B13MuxType      ePortB13Mode;
    PORT_B14MuxType      ePortB14Mode;
    PORT_B15MuxType      ePortB15Mode;
    PORT_B16MuxType      ePortB16Mode;
    PORT_B17MuxType      ePortB17Mode;
    PORT_B18MuxType      ePortB18Mode;
    PORT_B19MuxType      ePortB19Mode;
    PORT_B20MuxType      ePortB20Mode;
    PORT_B21MuxType      ePortB21Mode;
    PORT_B22MuxType      ePortB22Mode;
    PORT_B23MuxType      ePortB23Mode;
    PORT_B24MuxType      ePortB24Mode;
    PORT_B25MuxType      ePortB25Mode;
    PORT_B26MuxType      ePortB26Mode;
    PORT_B27MuxType      ePortB27Mode;
    PORT_B28MuxType      ePortB28Mode;
    PORT_B29MuxType      ePortB29Mode;
    PORT_B30MuxType      ePortB30Mode;
    PORT_B31MuxType      ePortB31Mode;
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
    PORT_C18MuxType      ePortC18Mode;
    PORT_C19MuxType      ePortC19Mode;
    PORT_C20MuxType      ePortC20Mode;
    PORT_C21MuxType      ePortC21Mode;
    PORT_C22MuxType      ePortC22Mode;
    PORT_C23MuxType      ePortC23Mode;
    PORT_C24MuxType      ePortC24Mode;
    PORT_C25MuxType      ePortC25Mode;
    PORT_C28MuxType      ePortC28Mode;
    PORT_C29MuxType      ePortC29Mode;
    PORT_C30MuxType      ePortC30Mode;
    PORT_C31MuxType      ePortC31Mode;
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
    PORT_D17MuxType      ePortD17Mode;
    PORT_D18MuxType      ePortD18Mode;
    PORT_D19MuxType      ePortD19Mode;
    PORT_D20MuxType      ePortD20Mode;
    PORT_D21MuxType      ePortD21Mode;
    PORT_D23MuxType      ePortD23Mode;
    PORT_D24MuxType      ePortD24Mode;
    PORT_D25MuxType      ePortD25Mode;
    PORT_D26MuxType      ePortD26Mode;
    PORT_D27MuxType      ePortD27Mode;
    PORT_D28MuxType      ePortD28Mode;
    PORT_D29MuxType      ePortD29Mode;
    PORT_D30MuxType      ePortD30Mode;
    PORT_D31MuxType      ePortD31Mode;
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
    PORT_E12MuxType      ePortE12Mode;
    PORT_E13MuxType      ePortE13Mode;
    PORT_E14MuxType      ePortE14Mode;
    PORT_E15MuxType      ePortE15Mode;
    PORT_E16MuxType      ePortE16Mode;
    PORT_E17MuxType      ePortE17Mode;
    PORT_E18MuxType      ePortE18Mode;
    PORT_E19MuxType      ePortE19Mode;
    PORT_E20MuxType      ePortE20Mode;
    PORT_E21MuxType      ePortE21Mode;
    PORT_E22MuxType      ePortE22Mode;
    PORT_E23MuxType      ePortE23Mode;
    PORT_E24MuxType      ePortE24Mode;
    PORT_E25MuxType      ePortE25Mode;
    PORT_E26MuxType      ePortE26Mode;
    PORT_E27MuxType      ePortE27Mode;
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

/** @brief GpioA Pin MASK structure */
#define GPIOA_PIN_MASK     (uint32_t)(0xffffffdfu)
/** @brief GpioB Pin MASK structure */
#define GPIOB_PIN_MASK     (uint32_t)(0xffffe7fbu)
/** @brief GpioC Pin MASK structure */
#define GPIOC_PIN_MASK     (uint32_t)(0xf3ffffffu)
/** @brief GpioD Pin MASK structure */
#define GPIOD_PIN_MASK     (uint32_t)(0xffbf9fffu)
/** @brief GpioE Pin MASK structure */
#define GPIOE_PIN_MASK     (uint32_t)(0xfffffffu)

/** @brief Gpio Pin MASK structure */
#define GPIO_PIN_MASK      {GPIOA_PIN_MASK, GPIOB_PIN_MASK, GPIOC_PIN_MASK, GPIOD_PIN_MASK, GPIOE_PIN_MASK}

#endif /* _DEVICE_FEATURES_FC7300F8MDT2P176T1A_H_ */
