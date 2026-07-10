#ifndef _DEVICE_FEATURES_FC7300F4MDS1A320T1B_H_
#define _DEVICE_FEATURES_FC7300F4MDS1A320T1B_H_

#include "FC7300F4MDSxxxxxT1B_feature.h"

/*********************** PORT Features ****************************/
#define PORT_INSTANCE_COUNT 9U

/** @brief PORTA0 Mode enumeration */
typedef enum
{
    PORTA_0_GPIO = 1U,
    PORTA_0_FTU4_CH6 = 2U,
    PORTA_0_FTU2_QD_PHA = 5U,
    PORTA_0_FCUART0_CTS = 6U,
    PORTA_0_TRGSEL_OUT3 = 7U,
} PORT_A0MuxType;

/** @brief PORTA1 Mode enumeration */
typedef enum
{
    PORTA_1_GPIO = 1U,
    PORTA_1_FTU4_CH4 = 2U,
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
    PORTA_15_GPIO = 1U,
    PORTA_15_FTU6_CH4 = 2U,
    PORTA_15_FTU5_QD_PHB = 3U,
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
    PORTA_23_ETM_TRACE_D0 = 4U,
    PORTA_23_FTU4_QD_PHA = 5U,
} PORT_A23MuxType;

/** @brief PORTA24 Mode enumeration */
typedef enum
{
    PORTA_24_ADC0_SE15_CMP0_IN7 = 0U,
    PORTA_24_GPIO = 1U,
    PORTA_24_FTU4_CH0 = 2U,
    PORTA_24_FCUART3_TX = 3U,
    PORTA_24_ETM_TRACE_D1 = 4U,
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
    PORTA_27_ETM_TRACE_D2 = 4U,
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
    PORTA_30_GPIO = 1U,
    PORTA_30_FTU5_CH2 = 2U,
    PORTA_30_FCUART2_RX = 3U,
    PORTA_30_ETM_TRACE_D5 = 4U,
    PORTA_30_FCSPI1_PCS2 = 5U,
    PORTA_30_FTU5_QD_PHB = 6U,
} PORT_A30MuxType;

/** @brief PORTA31 Mode enumeration */
typedef enum
{
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
    PORTB_0_GPIO = 1U,
    PORTB_0_FLEXCAN0_RX = 5U,
    PORTB_0_FTU3_CH6 = 6U,
} PORT_B0MuxType;

/** @brief PORTB1 Mode enumeration */
typedef enum
{
    PORTB_1_GPIO = 1U,
    PORTB_1_FTU_TCK0 = 3U,
    PORTB_1_FLEXCAN0_TX = 5U,
    PORTB_1_FTU3_CH5 = 6U,
} PORT_B1MuxType;

/** @brief PORTB10 Mode enumeration */
typedef enum
{
    PORTB_10_GPIO = 1U,
    PORTB_10_FTU2_CH5 = 2U,
    PORTB_10_TRGSEL_OUT2 = 3U,
} PORT_B10MuxType;

/** @brief PORTB12 Mode enumeration */
typedef enum
{
    PORTB_12_GPIO = 1U,
    PORTB_12_FLEXCAN2_RX = 5U,
} PORT_B12MuxType;

/** @brief PORTB13 Mode enumeration */
typedef enum
{
    PORTB_13_GPIO = 1U,
    PORTB_13_FTU3_CH2 = 2U,
} PORT_B13MuxType;

/** @brief PORTB14 Mode enumeration */
typedef enum
{
    PORTB_14_GPIO = 1U,
    PORTB_14_FTU3_CH1 = 2U,
    PORTB_14_FCUART4_RX = 3U,
} PORT_B14MuxType;

/** @brief PORTB15 Mode enumeration */
typedef enum
{
    PORTB_15_GPIO = 1U,
    PORTB_15_FTU3_CH0 = 2U,
    PORTB_15_FCUART4_TX = 3U,
} PORT_B15MuxType;

/** @brief PORTB16 Mode enumeration */
typedef enum
{
    PORTB_16_GPIO = 1U,
    PORTB_16_FTU5_CH7 = 2U,
    PORTB_16_FCUART5_CTS = 3U,
} PORT_B16MuxType;

/** @brief PORTB17 Mode enumeration */
typedef enum
{
    PORTB_17_ADC2_SE20 = 0U,
    PORTB_17_GPIO = 1U,
    PORTB_17_FTU5_CH6 = 2U,
    PORTB_17_FCSPI1_PCS3 = 4U,
} PORT_B17MuxType;

/** @brief PORTB18 Mode enumeration */
typedef enum
{
    PORTB_18_GPIO = 1U,
    PORTB_18_FTU0_CH5 = 2U,
    PORTB_18_FCUART5_RX = 3U,
    PORTB_18_FLEXCAN3_RX = 5U,
} PORT_B18MuxType;

/** @brief PORTB19 Mode enumeration */
typedef enum
{
    PORTB_19_GPIO = 1U,
    PORTB_19_FTU0_CH4 = 2U,
} PORT_B19MuxType;

/** @brief PORTB20 Mode enumeration */
typedef enum
{
    PORTB_20_GPIO = 1U,
    PORTB_20_FTU1_CH0 = 2U,
    PORTB_20_FCUART1_TX = 3U,
    PORTB_20_SCG_CLKOUT = 7U,
} PORT_B20MuxType;

/** @brief PORTB21 Mode enumeration */
typedef enum
{
    PORTB_21_GPIO = 1U,
    PORTB_21_FTU1_CH1 = 2U,
    PORTB_21_FCUART1_RX = 3U,
    PORTB_21_RTC_CLKOUT = 7U,
} PORT_B21MuxType;

/** @brief PORTB22 Mode enumeration */
typedef enum
{
    PORTB_22_GPIO = 1U,
    PORTB_22_FCUART1_TX = 3U,
    PORTB_22_ETM_TRACE_D5 = 4U,
    PORTB_22_FCSPI3_PCS2 = 7U,
} PORT_B22MuxType;

/** @brief PORTB23 Mode enumeration */
typedef enum
{
    PORTB_23_GPIO = 1U,
    PORTB_23_FTU_FLT9 = 2U,
    PORTB_23_FCSPI2_PCS0 = 3U,
    PORTB_23_FTU7_CH3 = 4U,
} PORT_B23MuxType;

/** @brief PORTB24 Mode enumeration */
typedef enum
{
    PORTB_24_GPIO = 1U,
    PORTB_24_FTU1_CH2 = 2U,
} PORT_B24MuxType;

/** @brief PORTB25 Mode enumeration */
typedef enum
{
    PORTB_25_GPIO = 1U,
    PORTB_25_FCSPI2_PCS0 = 4U,
    PORTB_25_FTU3_CH6 = 6U,
} PORT_B25MuxType;

/** @brief PORTB26 Mode enumeration */
typedef enum
{
    PORTB_26_GPIO = 1U,
    PORTB_26_FTU6_CH0 = 2U,
    PORTB_26_FCSPI3_SIN = 7U,
} PORT_B26MuxType;

/** @brief PORTB27 Mode enumeration */
typedef enum
{
    PORTB_27_GPIO = 1U,
    PORTB_27_FTU7_CH0 = 2U,
    PORTB_27_FTU1_QD_PHB = 3U,
    PORTB_27_FCSPI2_SOUT = 4U,
} PORT_B27MuxType;

/** @brief PORTB28 Mode enumeration */
typedef enum
{
    PORTB_28_GPIO = 1U,
    PORTB_28_FTU7_CH1 = 2U,
    PORTB_28_FCSPI2_SIN = 4U,
} PORT_B28MuxType;

/** @brief PORTB29 Mode enumeration */
typedef enum
{
    PORTB_29_GPIO = 1U,
    PORTB_29_FTU1_CH3 = 2U,
    PORTB_29_MSC0_FCLP = 7U,
} PORT_B29MuxType;

/** @brief PORTB3 Mode enumeration */
typedef enum
{
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
    PORTB_30_FCSPI3_SOUT = 7U,
} PORT_B30MuxType;

/** @brief PORTB31 Mode enumeration */
typedef enum
{
    PORTB_31_GPIO = 1U,
    PORTB_31_FTU7_CH1 = 2U,
    PORTB_31_FCSPI2_SCK = 3U,
} PORT_B31MuxType;

/** @brief PORTB4 Mode enumeration */
typedef enum
{
    PORTB_4_GPIO = 1U,
    PORTB_4_FTU7_CH7 = 2U,
} PORT_B4MuxType;

/** @brief PORTB5 Mode enumeration */
typedef enum
{
    PORTB_5_GPIO = 1U,
    PORTB_5_FTU6_CH2 = 2U,
    PORTB_5_FCIIC1_SDA = 3U,
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
    PORTB_8_FCUART1_CTS = 6U,
} PORT_B8MuxType;

/** @brief PORTB9 Mode enumeration */
typedef enum
{
    PORTB_9_GPIO = 1U,
    PORTB_9_FTU2_CH7 = 2U,
    PORTB_9_TRGSEL_OUT1 = 5U,
} PORT_B9MuxType;

/** @brief PORTC0 Mode enumeration */
typedef enum
{
    PORTC_0_GPIO = 1U,
    PORTC_0_ETM_TRACE_D6 = 4U,
    PORTC_0_FCSPI3_PCS1 = 7U,
} PORT_C0MuxType;

/** @brief PORTC1 Mode enumeration */
typedef enum
{
    PORTC_1_GPIO = 1U,
    PORTC_1_FTU7_CH5 = 2U,
    PORTC_1_FCSPI3_PCS0 = 7U,
} PORT_C1MuxType;

/** @brief PORTC10 Mode enumeration */
typedef enum
{
    PORTC_10_ADC2_SE3 = 0U,
    PORTC_10_GPIO = 1U,
    PORTC_10_FTU3_CH4 = 2U,
    PORTC_10_MSC0_EN1 = 7U,
} PORT_C10MuxType;

/** @brief PORTC11 Mode enumeration */
typedef enum
{
    PORTC_11_ADC2_SE6 = 0U,
    PORTC_11_GPIO = 1U,
    PORTC_11_FTU3_CH3 = 2U,
    PORTC_11_MSC0_EN0 = 7U,
} PORT_C11MuxType;

/** @brief PORTC12 Mode enumeration */
typedef enum
{
    PORTC_12_GPIO = 1U,
    PORTC_12_FTU1_CH5 = 2U,
    PORTC_12_TRGSEL_OUT5 = 5U,
    PORTC_12_MSC0_EN2 = 7U,
} PORT_C12MuxType;

/** @brief PORTC13 Mode enumeration */
typedef enum
{
    PORTC_13_GPIO = 1U,
    PORTC_13_FTU1_CH4 = 2U,
    PORTC_13_TRGSEL_OUT6 = 5U,
    PORTC_13_MSC0_SOP = 7U,
} PORT_C13MuxType;

/** @brief PORTC14 Mode enumeration */
typedef enum
{
    PORTC_14_GPIO = 1U,
    PORTC_14_FTU7_CH4 = 2U,
    PORTC_14_FCUART1_RX = 3U,
    PORTC_14_FCIIC1_SDA = 4U,
} PORT_C14MuxType;

/** @brief PORTC15 Mode enumeration */
typedef enum
{
    PORTC_15_GPIO = 1U,
    PORTC_15_FCSPI2_PCS3 = 3U,
    PORTC_15_SCG_CLKOUT = 4U,
    PORTC_15_FCSPI3_PCS3 = 7U,
} PORT_C15MuxType;

/** @brief PORTC16 Mode enumeration */
typedef enum
{
    PORTC_16_GPIO = 1U,
    PORTC_16_FTU_FLT7 = 2U,
    PORTC_16_FCSPI2_SOUT = 3U,
    PORTC_16_TRGSEL_OUT7 = 4U,
    PORTC_16_FCUART5_RX = 7U,
} PORT_C16MuxType;

/** @brief PORTC17 Mode enumeration */
typedef enum
{
    PORTC_17_GPIO = 1U,
    PORTC_17_FTU_FLT6 = 2U,
    PORTC_17_TRGSEL_OUT6 = 4U,
    PORTC_17_FCUART5_TX = 7U,
} PORT_C17MuxType;

/** @brief PORTC18 Mode enumeration */
typedef enum
{
    PORTC_18_GPIO = 1U,
    PORTC_18_FTU7_CH2 = 2U,
    PORTC_18_FCSPI2_SIN = 3U,
} PORT_C18MuxType;

/** @brief PORTC19 Mode enumeration */
typedef enum
{
    PORTC_19_GPIO = 1U,
    PORTC_19_FTU1_CH6 = 2U,
    PORTC_19_MSC0_EN3 = 7U,
} PORT_C19MuxType;

/** @brief PORTC2 Mode enumeration */
typedef enum
{
    PORTC_2_GPIO = 1U,
    PORTC_2_FTU6_CH3 = 2U,
    PORTC_2_FCUART0_RX = 3U,
    PORTC_2_ETM_TRACE_CLKOUT = 4U,
} PORT_C2MuxType;

/** @brief PORTC20 Mode enumeration */
typedef enum
{
    PORTC_20_GPIO = 1U,
    PORTC_20_FTU1_CH7 = 2U,
    PORTC_20_MSC0_SDI2 = 7U,
} PORT_C20MuxType;

/** @brief PORTC21 Mode enumeration */
typedef enum
{
    PORTC_21_GPIO = 1U,
    PORTC_21_FTU3_CH0 = 2U,
    PORTC_21_MSC0_SDI3 = 7U,
} PORT_C21MuxType;

/** @brief PORTC22 Mode enumeration */
typedef enum
{
    PORTC_22_GPIO = 1U,
    PORTC_22_FTU3_CH1 = 2U,
    PORTC_22_MSC0_SDI1 = 7U,
} PORT_C22MuxType;

/** @brief PORTC23 Mode enumeration */
typedef enum
{
    PORTC_23_ADC2_SE0 = 0U,
    PORTC_23_GPIO = 1U,
    PORTC_23_FTU6_CH6 = 3U,
    PORTC_23_FCUART2_RTS = 4U,
    PORTC_23_MSC0_SDI0 = 7U,
} PORT_C23MuxType;

/** @brief PORTC24 Mode enumeration */
typedef enum
{
    PORTC_24_ADC2_SE2 = 0U,
    PORTC_24_GPIO = 1U,
    PORTC_24_FTU3_CH2 = 2U,
    PORTC_24_FCUART2_CTS = 4U,
} PORT_C24MuxType;

/** @brief PORTC25 Mode enumeration */
typedef enum
{
    PORTC_25_GPIO = 1U,
    PORTC_25_FTU3_CH3 = 2U,
    PORTC_25_FCUART5_RTS = 3U,
    PORTC_25_FLEXCAN2_TX = 5U,
} PORT_C25MuxType;

/** @brief PORTC26 Mode enumeration */
typedef enum
{
    PORTC_26_GPIO = 1U,
    PORTC_26_FLEXCAN2_TX = 4U,
} PORT_C26MuxType;

/** @brief PORTC27 Mode enumeration */
typedef enum
{
    PORTC_27_ADC2_SE7 = 0U,
    PORTC_27_GPIO = 1U,
    PORTC_27_FCSPI2_PCS1 = 4U,
    PORTC_27_FCUART5_RX = 6U,
} PORT_C27MuxType;

/** @brief PORTC28 Mode enumeration */
typedef enum
{
    PORTC_28_GPIO = 1U,
    PORTC_28_FTU7_CH2 = 2U,
    PORTC_28_FLEXCAN3_TX = 4U,
} PORT_C28MuxType;

/** @brief PORTC29 Mode enumeration */
typedef enum
{
    PORTC_29_ADC2_SE10 = 0U,
    PORTC_29_GPIO = 1U,
    PORTC_29_FTU7_CH5 = 2U,
    PORTC_29_FLEXCAN3_RX = 4U,
} PORT_C29MuxType;

/** @brief PORTC3 Mode enumeration */
typedef enum
{
    PORTC_3_GPIO = 1U,
    PORTC_3_FTU6_CH2 = 2U,
    PORTC_3_FCUART0_TX = 3U,
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
} PORT_D10MuxType;

/** @brief PORTD11 Mode enumeration */
typedef enum
{
    PORTD_11_GPIO = 1U,
    PORTD_11_FTU6_CH6 = 2U,
    PORTD_11_FTU2_QD_PHA = 3U,
    PORTD_11_ETM_TRACE_D4 = 4U,
} PORT_D11MuxType;

/** @brief PORTD12 Mode enumeration */
typedef enum
{
    PORTD_12_GPIO = 1U,
    PORTD_12_FTU6_CH5 = 2U,
    PORTD_12_FCUART2_RTS = 3U,
    PORTD_12_ETM_TRACE_D3 = 4U,
    PORTD_12_FCSPI3_SOUT = 7U,
} PORT_D12MuxType;

/** @brief PORTD15 Mode enumeration */
typedef enum
{
    PORTD_15_GPIO = 1U,
    PORTD_15_FTU5_CH0 = 2U,
    PORTD_15_FLEXCAN2_RX = 3U,
    PORTD_15_ETM_TRACE_D7 = 4U,
    PORTD_15_FCUART2_RTS = 6U,
} PORT_D15MuxType;

/** @brief PORTD16 Mode enumeration */
typedef enum
{
    PORTD_16_GPIO = 1U,
    PORTD_16_FTU5_CH1 = 2U,
    PORTD_16_FLEXCAN2_TX = 3U,
    PORTD_16_ETM_TRACE_D6 = 4U,
    PORTD_16_FCSPI1_PCS3 = 5U,
} PORT_D16MuxType;

/** @brief PORTD17 Mode enumeration */
typedef enum
{
    PORTD_17_GPIO = 1U,
    PORTD_17_FTU5_CH3 = 2U,
    PORTD_17_FCUART2_TX = 3U,
    PORTD_17_ETM_TRACE_D4 = 4U,
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
    PORTD_18_FCSPI7_PCS0 = 7U,
} PORT_D18MuxType;

/** @brief PORTD19 Mode enumeration */
typedef enum
{
    PORTD_19_ADC2_SE17 = 0U,
    PORTD_19_GPIO = 1U,
    PORTD_19_FTU5_CH4 = 2U,
    PORTD_19_FCIIC1_SCL = 4U,
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
} PORT_D21MuxType;

/** @brief PORTD22 Mode enumeration */
typedef enum
{
    PORTD_22_GPIO = 1U,
} PORT_D22MuxType;

/** @brief PORTD23 Mode enumeration */
typedef enum
{
    PORTD_23_GPIO = 1U,
    PORTD_23_FTU2_CH1 = 2U,
    PORTD_23_FCSPI1_PCS0 = 4U,
} PORT_D23MuxType;

/** @brief PORTD24 Mode enumeration */
typedef enum
{
    PORTD_24_GPIO = 1U,
    PORTD_24_FTU2_CH4 = 2U,
} PORT_D24MuxType;

/** @brief PORTD25 Mode enumeration */
typedef enum
{
    PORTD_25_GPIO = 1U,
    PORTD_25_FTU2_CH6 = 2U,
    PORTD_25_FCUART4_RTS = 4U,
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
} PORT_D27MuxType;

/** @brief PORTD28 Mode enumeration */
typedef enum
{
    PORTD_28_GPIO = 1U,
    PORTD_28_FTU4_CH3 = 2U,
} PORT_D28MuxType;

/** @brief PORTD29 Mode enumeration */
typedef enum
{
    PORTD_29_GPIO = 1U,
    PORTD_29_FTU4_CH5 = 2U,
    PORTD_29_FTU1_QD_PHB = 5U,
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
    PORTD_30_FTU2_QD_PHB = 5U,
} PORT_D30MuxType;

/** @brief PORTD31 Mode enumeration */
typedef enum
{
    PORTD_31_GPIO = 1U,
    PORTD_31_FTU6_CH0 = 2U,
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
    PORTD_5_ETM_TRACE_D2 = 4U,
    PORTD_5_FCSPI3_SIN = 7U,
} PORT_D5MuxType;

/** @brief PORTD6 Mode enumeration */
typedef enum
{
    PORTD_6_GPIO = 1U,
    PORTD_6_FCUART2_RX = 2U,
    PORTD_6_FLEXCAN3_RX = 3U,
    PORTD_6_ETM_TRACE_D1 = 4U,
    PORTD_6_FCSPI3_SCK = 7U,
} PORT_D6MuxType;

/** @brief PORTD7 Mode enumeration */
typedef enum
{
    PORTD_7_GPIO = 1U,
    PORTD_7_FCUART2_TX = 2U,
    PORTD_7_FLEXCAN3_TX = 3U,
    PORTD_7_ETM_TRACE_D0 = 4U,
} PORT_D7MuxType;

/** @brief PORTD8 Mode enumeration */
typedef enum
{
    PORTD_8_GPIO = 1U,
    PORTD_8_FTU7_CH0 = 2U,
    PORTD_8_FCSPI2_PCS2 = 3U,
    PORTD_8_FTU1_CH6 = 4U,
    PORTD_8_FCUART4_RX = 7U,
} PORT_D8MuxType;

/** @brief PORTD9 Mode enumeration */
typedef enum
{
    PORTD_9_GPIO = 1U,
    PORTD_9_FCSPI2_PCS1 = 3U,
    PORTD_9_ETM_TRACE_D7 = 4U,
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
    PORTE_12_ETM_TRACE_D3 = 4U,
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
    PORTE_15_FTU2_CH6 = 4U,
    PORTE_15_TRGSEL_OUT6 = 7U,
} PORT_E15MuxType;

/** @brief PORTE16 Mode enumeration */
typedef enum
{
    PORTE_16_ADC1_SE2 = 0U,
    PORTE_16_GPIO = 1U,
    PORTE_16_FCUART1_RTS = 2U,
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
    PORTE_18_GPIO = 1U,
    PORTE_18_FTU6_CH3 = 2U,
    PORTE_18_FTU5_QD_PHA = 3U,
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
} PORT_E5MuxType;

/** @brief PORTE6 Mode enumeration */
typedef enum
{
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
    PORTE_7_FCSPI7_SOUT = 7U,
} PORT_E7MuxType;

/** @brief PORTE8 Mode enumeration */
typedef enum
{
    PORTE_8_GPIO = 1U,
    PORTE_8_FTU6_CH1 = 2U,
    PORTE_8_FCSPI3_SCK = 7U,
} PORT_E8MuxType;

/** @brief PORTE9 Mode enumeration */
typedef enum
{
    PORTE_9_GPIO = 1U,
    PORTE_9_FTU0_CH7 = 2U,
    PORTE_9_ETM_TRACE_CLKOUT = 4U,
    PORTE_9_FCUART2_CTS = 6U,
} PORT_E9MuxType;

/** @brief PORTF0 Mode enumeration */
typedef enum
{
    PORTF_0_ADC1_SE13 = 0U,
    PORTF_0_GPIO = 1U,
    PORTF_0_FCUART6_RX = 2U,
    PORTF_0_FTU2_QD_PHA = 3U,
} PORT_F0MuxType;

/** @brief PORTF1 Mode enumeration */
typedef enum
{
    PORTF_1_ADC1_SE12 = 0U,
    PORTF_1_GPIO = 1U,
    PORTF_1_FCUART6_TX = 2U,
    PORTF_1_FTU2_QD_PHB = 3U,
} PORT_F1MuxType;

/** @brief PORTF10 Mode enumeration */
typedef enum
{
    PORTF_10_GPIO = 1U,
    PORTF_10_FTU0_CH4 = 3U,
    PORTF_10_MSC0_SDI1 = 4U,
} PORT_F10MuxType;

/** @brief PORTF11 Mode enumeration */
typedef enum
{
    PORTF_11_GPIO = 1U,
    PORTF_11_FTU0_CH5 = 3U,
    PORTF_11_MSC0_SDI2 = 4U,
} PORT_F11MuxType;

/** @brief PORTF12 Mode enumeration */
typedef enum
{
    PORTF_12_GPIO = 1U,
} PORT_F12MuxType;

/** @brief PORTF13 Mode enumeration */
typedef enum
{
    PORTF_13_GPIO = 1U,
    PORTF_13_FCSPI2_PCS2 = 4U,
} PORT_F13MuxType;

/** @brief PORTF14 Mode enumeration */
typedef enum
{
    PORTF_14_GPIO = 1U,
    PORTF_14_FCSPI2_PCS3 = 4U,
    PORTF_14_FCUART5_TX = 6U,
} PORT_F14MuxType;

/** @brief PORTF15 Mode enumeration */
typedef enum
{
    PORTF_15_ADC2_SE18 = 0U,
    PORTF_15_GPIO = 1U,
} PORT_F15MuxType;

/** @brief PORTF16 Mode enumeration */
typedef enum
{
    PORTF_16_GPIO = 1U,
} PORT_F16MuxType;

/** @brief PORTF17 Mode enumeration */
typedef enum
{
    PORTF_17_GPIO = 1U,
    PORTF_17_FTU_FLT21 = 2U,
} PORT_F17MuxType;

/** @brief PORTF18 Mode enumeration */
typedef enum
{
    PORTF_18_GPIO = 1U,
    PORTF_18_FCSPI4_PCS3 = 2U,
    PORTF_18_FCUART1_TX = 4U,
} PORT_F18MuxType;

/** @brief PORTF19 Mode enumeration */
typedef enum
{
    PORTF_19_GPIO = 1U,
    PORTF_19_FCSPI4_PCS2 = 2U,
    PORTF_19_FTU6_CH1 = 3U,
    PORTF_19_FCUART1_RX = 4U,
} PORT_F19MuxType;

/** @brief PORTF2 Mode enumeration */
typedef enum
{
    PORTF_2_GPIO = 1U,
    PORTF_2_FCUART6_RTS = 2U,
} PORT_F2MuxType;

/** @brief PORTF20 Mode enumeration */
typedef enum
{
    PORTF_20_GPIO = 1U,
    PORTF_20_FCSPI4_PCS1 = 2U,
    PORTF_20_FTU6_CH2 = 3U,
    PORTF_20_FLEXCAN2_RX = 4U,
} PORT_F20MuxType;

/** @brief PORTF21 Mode enumeration */
typedef enum
{
    PORTF_21_GPIO = 1U,
    PORTF_21_FTU3_CH6 = 2U,
    PORTF_21_FCIIC1_SCL = 3U,
    PORTF_21_CMP0_OUT = 4U,
    PORTF_21_RTC_CLKOUT = 5U,
} PORT_F21MuxType;

/** @brief PORTF22 Mode enumeration */
typedef enum
{
    PORTF_22_GPIO = 1U,
    PORTF_22_FTU3_CH7 = 2U,
    PORTF_22_FCIIC1_SDA = 3U,
    PORTF_22_CMP1_OUT = 4U,
} PORT_F22MuxType;

/** @brief PORTF23 Mode enumeration */
typedef enum
{
    PORTF_23_ADC1_SE11_CMP1_IN3 = 0U,
    PORTF_23_GPIO = 1U,
    PORTF_23_SENT0_RXD0 = 2U,
    PORTF_23_FCUART0_TX = 3U,
    PORTF_23_FCSPI0_SOUT = 4U,
} PORT_F23MuxType;

/** @brief PORTF24 Mode enumeration */
typedef enum
{
    PORTF_24_CMP0_IN3 = 0U,
    PORTF_24_GPIO = 1U,
    PORTF_24_FTU4_CH6 = 2U,
    PORTF_24_FCSPI2_PCS3 = 5U,
} PORT_F24MuxType;

/** @brief PORTF3 Mode enumeration */
typedef enum
{
    PORTF_3_ADC0_SE7 = 0U,
    PORTF_3_GPIO = 1U,
} PORT_F3MuxType;

/** @brief PORTF4 Mode enumeration */
typedef enum
{
    PORTF_4_GPIO = 1U,
} PORT_F4MuxType;

/** @brief PORTF5 Mode enumeration */
typedef enum
{
    PORTF_5_GPIO = 1U,
} PORT_F5MuxType;

/** @brief PORTF6 Mode enumeration */
typedef enum
{
    PORTF_6_GPIO = 1U,
    PORTF_6_FTU6_CH4 = 3U,
} PORT_F6MuxType;

/** @brief PORTF7 Mode enumeration */
typedef enum
{
    PORTF_7_ADC2_SE4 = 0U,
    PORTF_7_GPIO = 1U,
    PORTF_7_FTU6_CH5 = 3U,
    PORTF_7_FTU1_QD_PHA = 5U,
} PORT_F7MuxType;

/** @brief PORTF8 Mode enumeration */
typedef enum
{
    PORTF_8_GPIO = 1U,
    PORTF_8_FCSPI3_SIN = 4U,
    PORTF_8_FTU_FLT5 = 5U,
    PORTF_8_TRGSEL_OUT4 = 6U,
} PORT_F8MuxType;

/** @brief PORTF9 Mode enumeration */
typedef enum
{
    PORTF_9_GPIO = 1U,
    PORTF_9_FTU0_CH3 = 3U,
    PORTF_9_MSC0_SDI0 = 4U,
} PORT_F9MuxType;

/** @brief PORTG0 Mode enumeration */
typedef enum
{
    PORTG_0_GPIO = 1U,
    PORTG_0_FCUART6_CTS = 2U,
} PORT_G0MuxType;

/** @brief PORTG1 Mode enumeration */
typedef enum
{
    PORTG_1_ADC0_SE0 = 0U,
    PORTG_1_GPIO = 1U,
} PORT_G1MuxType;

/** @brief PORTG10 Mode enumeration */
typedef enum
{
    PORTG_10_GPIO = 1U,
    PORTG_10_FTU0_CH7 = 3U,
    PORTG_10_FTU2_QD_PHA = 5U,
} PORT_G10MuxType;

/** @brief PORTG11 Mode enumeration */
typedef enum
{
    PORTG_11_GPIO = 1U,
    PORTG_11_FTU2_QD_PHB = 5U,
} PORT_G11MuxType;

/** @brief PORTG12 Mode enumeration */
typedef enum
{
    PORTG_12_GPIO = 1U,
    PORTG_12_FTU6_CH7 = 4U,
} PORT_G12MuxType;

/** @brief PORTG13 Mode enumeration */
typedef enum
{
    PORTG_13_GPIO = 1U,
} PORT_G13MuxType;

/** @brief PORTG14 Mode enumeration */
typedef enum
{
    PORTG_14_GPIO = 1U,
} PORT_G14MuxType;

/** @brief PORTG15 Mode enumeration */
typedef enum
{
    PORTG_15_GPIO = 1U,
    PORTG_15_FCIIC0_SCL = 3U,
    PORTG_15_TRGSEL_OUT2 = 5U,
} PORT_G15MuxType;

/** @brief PORTG16 Mode enumeration */
typedef enum
{
    PORTG_16_GPIO = 1U,
    PORTG_16_FCIIC0_SDA = 3U,
    PORTG_16_TRGSEL_OUT3 = 5U,
} PORT_G16MuxType;

/** @brief PORTG17 Mode enumeration */
typedef enum
{
    PORTG_17_GPIO = 1U,
    PORTG_17_FTU5_QD_PHA = 5U,
} PORT_G17MuxType;

/** @brief PORTG18 Mode enumeration */
typedef enum
{
    PORTG_18_GPIO = 1U,
    PORTG_18_FCSPI4_PCS0 = 2U,
    PORTG_18_FTU1_CH0 = 3U,
} PORT_G18MuxType;

/** @brief PORTG19 Mode enumeration */
typedef enum
{
    PORTG_19_GPIO = 1U,
    PORTG_19_FCSPI4_SCK = 2U,
    PORTG_19_FTU1_CH1 = 3U,
} PORT_G19MuxType;

/** @brief PORTG2 Mode enumeration */
typedef enum
{
    PORTG_2_ADC0_SE4 = 0U,
    PORTG_2_GPIO = 1U,
} PORT_G2MuxType;

/** @brief PORTG20 Mode enumeration */
typedef enum
{
    PORTG_20_GPIO = 1U,
    PORTG_20_FCSPI4_SIN = 2U,
    PORTG_20_FTU1_CH2 = 3U,
    PORTG_20_FLEXCAN3_TX = 5U,
} PORT_G20MuxType;

/** @brief PORTG21 Mode enumeration */
typedef enum
{
    PORTG_21_ADC1_SE10_CMP1_IN2 = 0U,
    PORTG_21_GPIO = 1U,
    PORTG_21_SENT0_RXD1 = 2U,
    PORTG_21_FCUART0_RX = 3U,
    PORTG_21_FCSPI0_PCS0 = 4U,
} PORT_G21MuxType;

/** @brief PORTG22 Mode enumeration */
typedef enum
{
    PORTG_22_ADC1_SE9_CMP1_IN1 = 0U,
    PORTG_22_GPIO = 1U,
    PORTG_22_SENT0_RXD2 = 2U,
    PORTG_22_FTU1_QD_PHA = 3U,
    PORTG_22_FCSPI0_SIN = 4U,
} PORT_G22MuxType;

/** @brief PORTG23 Mode enumeration */
typedef enum
{
    PORTG_23_ADC1_SE8_CMP1_IN0 = 0U,
    PORTG_23_GPIO = 1U,
    PORTG_23_SENT0_RXD3 = 2U,
    PORTG_23_FTU1_QD_PHB = 3U,
    PORTG_23_FCSPI0_SCK = 4U,
} PORT_G23MuxType;

/** @brief PORTG3 Mode enumeration */
typedef enum
{
    PORTG_3_ADC0_SE20 = 0U,
    PORTG_3_GPIO = 1U,
    PORTG_3_ETM_TRACE_D8 = 5U,
} PORT_G3MuxType;

/** @brief PORTG4 Mode enumeration */
typedef enum
{
    PORTG_4_ADC0_SE21 = 0U,
    PORTG_4_GPIO = 1U,
    PORTG_4_ETM_TRACE_D9 = 5U,
} PORT_G4MuxType;

/** @brief PORTG5 Mode enumeration */
typedef enum
{
    PORTG_5_ADC0_SE22 = 0U,
    PORTG_5_GPIO = 1U,
    PORTG_5_ETM_TRACE_D10 = 5U,
} PORT_G5MuxType;

/** @brief PORTG6 Mode enumeration */
typedef enum
{
    PORTG_6_GPIO = 1U,
    PORTG_6_FCSPI3_SOUT = 4U,
    PORTG_6_TRGSEL_OUT3 = 6U,
} PORT_G6MuxType;

/** @brief PORTG7 Mode enumeration */
typedef enum
{
    PORTG_7_GPIO = 1U,
    PORTG_7_FCSPI3_PCS0 = 4U,
    PORTG_7_TRGSEL_OUT2 = 6U,
} PORT_G7MuxType;

/** @brief PORTG8 Mode enumeration */
typedef enum
{
    PORTG_8_GPIO = 1U,
    PORTG_8_FCUART3_TX = 4U,
} PORT_G8MuxType;

/** @brief PORTG9 Mode enumeration */
typedef enum
{
    PORTG_9_GPIO = 1U,
    PORTG_9_FTU0_CH6 = 3U,
    PORTG_9_MSC0_SDI3 = 4U,
} PORT_G9MuxType;

/** @brief PORTH0 Mode enumeration */
typedef enum
{
    PORTH_0_ADC1_SE5 = 0U,
    PORTH_0_GPIO = 1U,
    PORTH_0_FCUART7_RTS = 2U,
} PORT_H0MuxType;

/** @brief PORTH1 Mode enumeration */
typedef enum
{
    PORTH_1_ADC1_SE1 = 0U,
    PORTH_1_GPIO = 1U,
    PORTH_1_FCUART7_CTS = 2U,
} PORT_H1MuxType;

/** @brief PORTH10 Mode enumeration */
typedef enum
{
    PORTH_10_ADC2_SE5 = 0U,
    PORTH_10_GPIO = 1U,
    PORTH_10_MSC0_SOP = 4U,
} PORT_H10MuxType;

/** @brief PORTH11 Mode enumeration */
typedef enum
{
    PORTH_11_GPIO = 1U,
    PORTH_11_FCSPI7_SIN = 5U,
    PORTH_11_MSC0_FCLP = 6U,
} PORT_H11MuxType;

/** @brief PORTH12 Mode enumeration */
typedef enum
{
    PORTH_12_ADC2_SE21 = 0U,
    PORTH_12_GPIO = 1U,
    PORTH_12_FCUART1_TX = 4U,
} PORT_H12MuxType;

/** @brief PORTH13 Mode enumeration */
typedef enum
{
    PORTH_13_ADC2_SE22 = 0U,
    PORTH_13_GPIO = 1U,
    PORTH_13_FCUART1_RX = 4U,
} PORT_H13MuxType;

/** @brief PORTH14 Mode enumeration */
typedef enum
{
    PORTH_14_ADC2_SE23 = 0U,
    PORTH_14_GPIO = 1U,
    PORTH_14_FCUART3_TX = 4U,
} PORT_H14MuxType;

/** @brief PORTH15 Mode enumeration */
typedef enum
{
    PORTH_15_GPIO = 1U,
    PORTH_15_FTU5_QD_PHB = 5U,
} PORT_H15MuxType;

/** @brief PORTH16 Mode enumeration */
typedef enum
{
    PORTH_16_GPIO = 1U,
} PORT_H16MuxType;

/** @brief PORTH17 Mode enumeration */
typedef enum
{
    PORTH_17_GPIO = 1U,
} PORT_H17MuxType;

/** @brief PORTH18 Mode enumeration */
typedef enum
{
    PORTH_18_GPIO = 1U,
    PORTH_18_FCSPI4_SOUT = 2U,
    PORTH_18_FTU1_CH3 = 3U,
    PORTH_18_FLEXCAN3_RX = 5U,
} PORT_H18MuxType;

/** @brief PORTH19 Mode enumeration */
typedef enum
{
    PORTH_19_GPIO = 1U,
    PORTH_19_FTU1_CH4 = 3U,
    PORTH_19_TRGSEL_OUT0 = 6U,
} PORT_H19MuxType;

/** @brief PORTH2 Mode enumeration */
typedef enum
{
    PORTH_2_ADC1_SE4 = 0U,
    PORTH_2_GPIO = 1U,
    PORTH_2_FCUART7_RX = 2U,
} PORT_H2MuxType;

/** @brief PORTH20 Mode enumeration */
typedef enum
{
    PORTH_20_GPIO = 1U,
    PORTH_20_FTU1_CH5 = 3U,
    PORTH_20_TRGSEL_OUT1 = 6U,
} PORT_H20MuxType;

/** @brief PORTH21 Mode enumeration */
typedef enum
{
    PORTH_21_GPIO = 1U,
    PORTH_21_FCSPI3_SCK = 4U,
    PORTH_21_FTU_FLT4 = 5U,
    PORTH_21_TRGSEL_OUT5 = 6U,
} PORT_H21MuxType;

/** @brief PORTH22 Mode enumeration */
typedef enum
{
    PORTH_22_GPIO = 1U,
    PORTH_22_FTU7_CH6 = 2U,
    PORTH_22_FCIIC1_SCL = 4U,
} PORT_H22MuxType;

/** @brief PORTH23 Mode enumeration */
typedef enum
{
    PORTH_23_GPIO = 1U,
    PORTH_23_FLEXCAN2_RX = 4U,
} PORT_H23MuxType;

/** @brief PORTH3 Mode enumeration */
typedef enum
{
    PORTH_3_ADC0_SE23 = 0U,
    PORTH_3_GPIO = 1U,
    PORTH_3_ETM_TRACE_D11 = 5U,
} PORT_H3MuxType;

/** @brief PORTH4 Mode enumeration */
typedef enum
{
    PORTH_4_GPIO = 1U,
    PORTH_4_FTU4_QD_PHA = 2U,
    PORTH_4_ETM_TRACE_D12 = 5U,
} PORT_H4MuxType;

/** @brief PORTH5 Mode enumeration */
typedef enum
{
    PORTH_5_GPIO = 1U,
    PORTH_5_FTU4_QD_PHB = 2U,
    PORTH_5_ETM_TRACE_D13 = 5U,
} PORT_H5MuxType;

/** @brief PORTH6 Mode enumeration */
typedef enum
{
    PORTH_6_GPIO = 1U,
    PORTH_6_FCUART3_RX = 4U,
} PORT_H6MuxType;

/** @brief PORTH7 Mode enumeration */
typedef enum
{
    PORTH_7_GPIO = 1U,
    PORTH_7_FTU_FLT8 = 2U,
} PORT_H7MuxType;

/** @brief PORTH8 Mode enumeration */
typedef enum
{
    PORTH_8_GPIO = 1U,
} PORT_H8MuxType;

/** @brief PORTH9 Mode enumeration */
typedef enum
{
    PORTH_9_ADC2_SE1 = 0U,
    PORTH_9_GPIO = 1U,
    PORTH_9_MSC0_FCLP = 4U,
    PORTH_9_FTU1_QD_PHB = 5U,
} PORT_H9MuxType;

/** @brief PORTI0 Mode enumeration */
typedef enum
{
    PORTI_0_ADC1_SE0 = 0U,
    PORTI_0_GPIO = 1U,
    PORTI_0_FCUART7_TX = 2U,
} PORT_I0MuxType;

/** @brief PORTI1 Mode enumeration */
typedef enum
{
    PORTI_1_GPIO = 1U,
} PORT_I1MuxType;

/** @brief PORTI10 Mode enumeration */
typedef enum
{
    PORTI_10_GPIO = 1U,
    PORTI_10_FCUART4_TX = 4U,
    PORTI_10_FCSPI7_SOUT = 5U,
} PORT_I10MuxType;

/** @brief PORTI11 Mode enumeration */
typedef enum
{
    PORTI_11_GPIO = 1U,
    PORTI_11_FCUART4_RX = 4U,
    PORTI_11_FCSPI7_PCS0 = 5U,
} PORT_I11MuxType;

/** @brief PORTI12 Mode enumeration */
typedef enum
{
    PORTI_12_GPIO = 1U,
    PORTI_12_FCUART3_RX = 4U,
} PORT_I12MuxType;

/** @brief PORTI13 Mode enumeration */
typedef enum
{
    PORTI_13_GPIO = 1U,
} PORT_I13MuxType;

/** @brief PORTI14 Mode enumeration */
typedef enum
{
    PORTI_14_GPIO = 1U,
} PORT_I14MuxType;

/** @brief PORTI15 Mode enumeration */
typedef enum
{
    PORTI_15_GPIO = 1U,
    PORTI_15_FLEXCAN1_TX = 5U,
} PORT_I15MuxType;

/** @brief PORTI16 Mode enumeration */
typedef enum
{
    PORTI_16_GPIO = 1U,
    PORTI_16_FLEXCAN1_RX = 5U,
} PORT_I16MuxType;

/** @brief PORTI17 Mode enumeration */
typedef enum
{
    PORTI_17_GPIO = 1U,
    PORTI_17_FLEXCAN2_TX = 4U,
} PORT_I17MuxType;

/** @brief PORTI18 Mode enumeration */
typedef enum
{
    PORTI_18_GPIO = 1U,
    PORTI_18_FTU1_CH6 = 3U,
    PORTI_18_FCUART2_TX = 4U,
} PORT_I18MuxType;

/** @brief PORTI19 Mode enumeration */
typedef enum
{
    PORTI_19_GPIO = 1U,
    PORTI_19_FTU1_CH7 = 3U,
    PORTI_19_FCUART2_RX = 4U,
} PORT_I19MuxType;

/** @brief PORTI2 Mode enumeration */
typedef enum
{
    PORTI_2_ADC0_SE3 = 0U,
    PORTI_2_GPIO = 1U,
} PORT_I2MuxType;

/** @brief PORTI20 Mode enumeration */
typedef enum
{
    PORTI_20_GPIO = 1U,
    PORTI_20_FTU_TCK2 = 2U,
    PORTI_20_FTU_FLT20 = 3U,
    PORTI_20_FTU6_CH7 = 4U,
} PORT_I20MuxType;

/** @brief PORTI21 Mode enumeration */
typedef enum
{
    PORTI_21_CMP0_IN4 = 0U,
    PORTI_21_GPIO = 1U,
    PORTI_21_FTU4_CH5 = 2U,
    PORTI_21_FCSPI2_PCS2 = 5U,
} PORT_I21MuxType;

/** @brief PORTI22 Mode enumeration */
typedef enum
{
    PORTI_22_CMP0_IN5 = 0U,
    PORTI_22_GPIO = 1U,
    PORTI_22_FTU4_CH4 = 2U,
} PORT_I22MuxType;

/** @brief PORTI23 Mode enumeration */
typedef enum
{
    PORTI_23_CMP0_IN2 = 0U,
    PORTI_23_GPIO = 1U,
    PORTI_23_FTU4_CH7 = 2U,
} PORT_I23MuxType;

/** @brief PORTI3 Mode enumeration */
typedef enum
{
    PORTI_3_GPIO = 1U,
    PORTI_3_ETM_TRACE_D14 = 5U,
} PORT_I3MuxType;

/** @brief PORTI4 Mode enumeration */
typedef enum
{
    PORTI_4_GPIO = 1U,
    PORTI_4_ETM_TRACE_D15 = 5U,
} PORT_I4MuxType;

/** @brief PORTI5 Mode enumeration */
typedef enum
{
    PORTI_5_GPIO = 1U,
    PORTI_5_FTU6_CH3 = 3U,
} PORT_I5MuxType;

/** @brief PORTI6 Mode enumeration */
typedef enum
{
    PORTI_6_GPIO = 1U,
    PORTI_6_FTU0_CH0 = 3U,
} PORT_I6MuxType;

/** @brief PORTI7 Mode enumeration */
typedef enum
{
    PORTI_7_GPIO = 1U,
    PORTI_7_FTU0_CH1 = 3U,
    PORTI_7_MSC0_EN0 = 4U,
} PORT_I7MuxType;

/** @brief PORTI8 Mode enumeration */
typedef enum
{
    PORTI_8_GPIO = 1U,
    PORTI_8_FTU0_CH2 = 3U,
    PORTI_8_MSC0_EN1 = 4U,
} PORT_I8MuxType;

/** @brief PORTI9 Mode enumeration */
typedef enum
{
    PORTI_9_GPIO = 1U,
    PORTI_9_FCSPI7_SCK = 5U,
    PORTI_9_MSC0_SOP = 6U,
} PORT_I9MuxType;

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
    PORT_B12MuxType      ePortB12Mode;
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
    PORT_C26MuxType      ePortC26Mode;
    PORT_C27MuxType      ePortC27Mode;
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
    PORT_D22MuxType      ePortD22Mode;
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
    PORT_F0MuxType       ePortF0Mode;
    PORT_F1MuxType       ePortF1Mode;
    PORT_F2MuxType       ePortF2Mode;
    PORT_F3MuxType       ePortF3Mode;
    PORT_F4MuxType       ePortF4Mode;
    PORT_F5MuxType       ePortF5Mode;
    PORT_F6MuxType       ePortF6Mode;
    PORT_F7MuxType       ePortF7Mode;
    PORT_F8MuxType       ePortF8Mode;
    PORT_F9MuxType       ePortF9Mode;
    PORT_F10MuxType      ePortF10Mode;
    PORT_F11MuxType      ePortF11Mode;
    PORT_F12MuxType      ePortF12Mode;
    PORT_F13MuxType      ePortF13Mode;
    PORT_F14MuxType      ePortF14Mode;
    PORT_F15MuxType      ePortF15Mode;
    PORT_F16MuxType      ePortF16Mode;
    PORT_F17MuxType      ePortF17Mode;
    PORT_F18MuxType      ePortF18Mode;
    PORT_F19MuxType      ePortF19Mode;
    PORT_F20MuxType      ePortF20Mode;
    PORT_F21MuxType      ePortF21Mode;
    PORT_F22MuxType      ePortF22Mode;
    PORT_F23MuxType      ePortF23Mode;
    PORT_F24MuxType      ePortF24Mode;
    PORT_G0MuxType       ePortG0Mode;
    PORT_G1MuxType       ePortG1Mode;
    PORT_G2MuxType       ePortG2Mode;
    PORT_G3MuxType       ePortG3Mode;
    PORT_G4MuxType       ePortG4Mode;
    PORT_G5MuxType       ePortG5Mode;
    PORT_G6MuxType       ePortG6Mode;
    PORT_G7MuxType       ePortG7Mode;
    PORT_G8MuxType       ePortG8Mode;
    PORT_G9MuxType       ePortG9Mode;
    PORT_G10MuxType      ePortG10Mode;
    PORT_G11MuxType      ePortG11Mode;
    PORT_G12MuxType      ePortG12Mode;
    PORT_G13MuxType      ePortG13Mode;
    PORT_G14MuxType      ePortG14Mode;
    PORT_G15MuxType      ePortG15Mode;
    PORT_G16MuxType      ePortG16Mode;
    PORT_G17MuxType      ePortG17Mode;
    PORT_G18MuxType      ePortG18Mode;
    PORT_G19MuxType      ePortG19Mode;
    PORT_G20MuxType      ePortG20Mode;
    PORT_G21MuxType      ePortG21Mode;
    PORT_G22MuxType      ePortG22Mode;
    PORT_G23MuxType      ePortG23Mode;
    PORT_H0MuxType       ePortH0Mode;
    PORT_H1MuxType       ePortH1Mode;
    PORT_H2MuxType       ePortH2Mode;
    PORT_H3MuxType       ePortH3Mode;
    PORT_H4MuxType       ePortH4Mode;
    PORT_H5MuxType       ePortH5Mode;
    PORT_H6MuxType       ePortH6Mode;
    PORT_H7MuxType       ePortH7Mode;
    PORT_H8MuxType       ePortH8Mode;
    PORT_H9MuxType       ePortH9Mode;
    PORT_H10MuxType      ePortH10Mode;
    PORT_H11MuxType      ePortH11Mode;
    PORT_H12MuxType      ePortH12Mode;
    PORT_H13MuxType      ePortH13Mode;
    PORT_H14MuxType      ePortH14Mode;
    PORT_H15MuxType      ePortH15Mode;
    PORT_H16MuxType      ePortH16Mode;
    PORT_H17MuxType      ePortH17Mode;
    PORT_H18MuxType      ePortH18Mode;
    PORT_H19MuxType      ePortH19Mode;
    PORT_H20MuxType      ePortH20Mode;
    PORT_H21MuxType      ePortH21Mode;
    PORT_H22MuxType      ePortH22Mode;
    PORT_H23MuxType      ePortH23Mode;
    PORT_I0MuxType       ePortI0Mode;
    PORT_I1MuxType       ePortI1Mode;
    PORT_I2MuxType       ePortI2Mode;
    PORT_I3MuxType       ePortI3Mode;
    PORT_I4MuxType       ePortI4Mode;
    PORT_I5MuxType       ePortI5Mode;
    PORT_I6MuxType       ePortI6Mode;
    PORT_I7MuxType       ePortI7Mode;
    PORT_I8MuxType       ePortI8Mode;
    PORT_I9MuxType       ePortI9Mode;
    PORT_I10MuxType      ePortI10Mode;
    PORT_I11MuxType      ePortI11Mode;
    PORT_I12MuxType      ePortI12Mode;
    PORT_I13MuxType      ePortI13Mode;
    PORT_I14MuxType      ePortI14Mode;
    PORT_I15MuxType      ePortI15Mode;
    PORT_I16MuxType      ePortI16Mode;
    PORT_I17MuxType      ePortI17Mode;
    PORT_I18MuxType      ePortI18Mode;
    PORT_I19MuxType      ePortI19Mode;
    PORT_I20MuxType      ePortI20Mode;
    PORT_I21MuxType      ePortI21Mode;
    PORT_I22MuxType      ePortI22Mode;
    PORT_I23MuxType      ePortI23Mode;
    Port_PinModeType     u32PortPinMode;
} Port_PinMuxType;

/** Array initializer of PORT peripheral base addresses */
#define PORT_BASE_ADDRS                          {PORTA_BASE, PORTB_BASE, PORTC_BASE, PORTD_BASE, PORTE_BASE, PORTF_BASE, PORTG_BASE, PORTH_BASE, PORTI_BASE}
/** Array initializer of PORT peripheral base pointers */
#define PORT_BASE_PTRS                           {PORTA, PORTB, PORTC, PORTD, PORTE, PORTF, PORTG, PORTH, PORTI}

/*********************** GPIO Features ****************************/
#define GPIO_INSTANCE_COUNT 9U

/** Array initializer of GPIO peripheral base addresses */
#define GPIO_BASE_ADDRS                          {GPIOA_BASE, GPIOB_BASE, GPIOC_BASE, GPIOD_BASE, GPIOE_BASE, GPIOF_BASE, GPIOG_BASE, GPIOH_BASE, GPIOI_BASE}
/** Array initializer of GPIO peripheral base pointers */
#define GPIO_BASE_PTRS                           {GPIOA, GPIOB, GPIOC, GPIOD, GPIOE, GPIOF, GPIOG, GPIOH, GPIOI}

/** @brief GpioA Pin MASK structure */
#define GPIOA_PIN_MASK     (uint32_t)(0xffffffdfu)
/** @brief GpioB Pin MASK structure */
#define GPIOB_PIN_MASK     (uint32_t)(0xfffff7fbu)
/** @brief GpioC Pin MASK structure */
#define GPIOC_PIN_MASK     (uint32_t)(0xffffffffu)
/** @brief GpioD Pin MASK structure */
#define GPIOD_PIN_MASK     (uint32_t)(0xffff9fffu)
/** @brief GpioE Pin MASK structure */
#define GPIOE_PIN_MASK     (uint32_t)(0xfffffffu)
/** @brief GpioF Pin MASK structure */
#define GPIOF_PIN_MASK     (uint32_t)(0x1ffffffu)
/** @brief GpioG Pin MASK structure */
#define GPIOG_PIN_MASK     (uint32_t)(0xffffffu)
/** @brief GpioH Pin MASK structure */
#define GPIOH_PIN_MASK     (uint32_t)(0xffffffu)
/** @brief GpioI Pin MASK structure */
#define GPIOI_PIN_MASK     (uint32_t)(0xffffffu)

/** @brief Gpio Pin MASK structure */
#define GPIO_PIN_MASK      {GPIOA_PIN_MASK, GPIOB_PIN_MASK, GPIOC_PIN_MASK, GPIOD_PIN_MASK, GPIOE_PIN_MASK, GPIOF_PIN_MASK, GPIOG_PIN_MASK, GPIOH_PIN_MASK, GPIOI_PIN_MASK}

/************ PCC Peripheral Features **************/
#define PCC_CLOCK_MAP_INFO \
    { \
        {0x20, PCC_CGC_AVAILABLE | PCC_CLK_DOMAIN_BUS | PCC_DWP_SWR_AVAILABLE},   /* DMA0 */      \
        {0x28, PCC_CGC_AVAILABLE | PCC_CLK_DOMAIN_BUS | PCC_DWP_SWR_AVAILABLE},   /* DMAMUX0 */   \
        {0x4C, PCC_CGC_AVAILABLE | PCC_CLK_DOMAIN_BUS | PCC_DWP_SWR_AVAILABLE},   /* ROMC */      \
        {0x60, PCC_CGC_AVAILABLE | PCC_CLK_DOMAIN_BUS | PCC_DWP_SWR_AVAILABLE},   /* ERM0 */      \
        {0x64, PCC_CGC_AVAILABLE | PCC_CLK_DOMAIN_SLOW | PCC_DWP_SWR_AVAILABLE},  /* EIM0 */      \
        {0x68, PCC_CGC_AVAILABLE | PCC_CLK_DOMAIN_SLOW | PCC_DWP_SWR_AVAILABLE},  /* INTM0 */     \
        {0x6C, PCC_CGC_AVAILABLE | PCC_CLK_DOMAIN_BUS | PCC_DWP_SWR_AVAILABLE},   /* ISM0 */      \
        {0x88, PCC_CLK_DOMAIN_SLOW | PCC_DWP_SWR_AVAILABLE},                      /* WDOG0 */     \
        {0x98, PCC_CGC_AVAILABLE | PCC_CLK_DOMAIN_SLOW | PCC_DWP_SWR_AVAILABLE},  /* TRGSEL0 */   \
        {0x9C, PCC_CGC_AVAILABLE | PCC_CLK_DOMAIN_SLOW | PCC_DWP_SWR_AVAILABLE},  /* TRGSEL1 */   \
        {0xA0, PCC_CGC_AVAILABLE | PCC_CLK_DOMAIN_SLOW | PCC_DWP_SWR_AVAILABLE},  /* TRGSEL2 */   \
        {0xA4, PCC_CGC_AVAILABLE | PCC_CLK_DOMAIN_SLOW | PCC_DWP_SWR_AVAILABLE},  /* TRGSEL3 */   \
        {0xA8, PCC_CGC_AVAILABLE | PCC_CLK_DOMAIN_BUS | PCC_DWP_SWR_AVAILABLE},   /* CRC0 */      \
        {0xAC, PCC_CGC_AVAILABLE | PCC_CLK_DOMAIN_BUS | PCC_DWP_SWR_AVAILABLE},   /* CORDIC */    \
        {0xB0, PCC_CGC_AVAILABLE | PCC_CLK_DOMAIN_BUS | PCC_DWP_SWR_AVAILABLE},   /* TSTMP0 */    \
        {0xB4, PCC_CGC_AVAILABLE | PCC_CLK_DOMAIN_BUS | PCC_DWP_SWR_AVAILABLE},   /* TSTMP1 */    \
        {0xB8, PCC_CGC_AVAILABLE | PCC_CLK_DOMAIN_BUS | PCC_FUNCCLK_MUXDIVH_USED | PCC_DWP_SWR_AVAILABLE},                          /* FCPIT0 */     \
        {0xBC, PCC_CGC_AVAILABLE | PCC_CLK_DOMAIN_SLOW | PCC_FUNCCLK_MUXDIVL_USED | PCC_MOUDULE_DIV_USED | PCC_DWP_SWR_AVAILABLE},  /* AONTIMER0 */  \
        {0xC0, PCC_CLK_DOMAIN_SLOW | PCC_DWP_SWR_AVAILABLE},                      /* RTC */       \
        {0xC4, PCC_CGC_AVAILABLE | PCC_CLK_DOMAIN_SLOW | PCC_DWP_SWR_AVAILABLE},  /* CMU0 */      \
        {0xC8, PCC_CGC_AVAILABLE | PCC_CLK_DOMAIN_SLOW | PCC_DWP_SWR_AVAILABLE},  /* CMU1 */      \
        {0xCC, PCC_CGC_AVAILABLE | PCC_CLK_DOMAIN_SLOW | PCC_DWP_SWR_AVAILABLE},  /* CMU2 */      \
        {0xD0, PCC_CGC_AVAILABLE | PCC_CLK_DOMAIN_SLOW | PCC_DWP_SWR_AVAILABLE},  /* CMU3 */      \
        {0xD4, PCC_CGC_AVAILABLE | PCC_CLK_DOMAIN_SLOW | PCC_DWP_SWR_AVAILABLE},  /* CMU4 */      \
        {0xDC, PCC_CGC_AVAILABLE | PCC_CLK_DOMAIN_BUS | PCC_DWP_SWR_AVAILABLE},   /* PTIMER0 */   \
        {0xE0, PCC_CGC_AVAILABLE | PCC_CLK_DOMAIN_BUS | PCC_DWP_SWR_AVAILABLE},   /* PTIMER1 */   \
        {0xEC, PCC_CGC_AVAILABLE | PCC_CLK_DOMAIN_BUS | PCC_FUNCCLK_MUXDIVH_USED | PCC_MOUDULE_DIV_USED | PCC_DWP_SWR_AVAILABLE},    /* ADC0 */  \
        {0xF0, PCC_CGC_AVAILABLE | PCC_CLK_DOMAIN_BUS | PCC_FUNCCLK_MUXDIVH_USED | PCC_MOUDULE_DIV_USED | PCC_DWP_SWR_AVAILABLE},    /* ADC1 */  \
        {0xFC, PCC_CGC_AVAILABLE | PCC_CLK_DOMAIN_SLOW | PCC_DWP_SWR_AVAILABLE},  /* WKU0 */      \
        {0x100, PCC_CGC_AVAILABLE | PCC_CLK_DOMAIN_SLOW | PCC_DWP_SWR_AVAILABLE}, /* CMP0 */      \
        {0x104, PCC_CGC_AVAILABLE | PCC_CLK_DOMAIN_SLOW | PCC_DWP_SWR_AVAILABLE}, /* CMP1 */      \
        {0x10C, PCC_CGC_AVAILABLE | PCC_CLK_DOMAIN_SLOW | PCC_FUNCCLK_MUXDIVL_USED | PCC_DWP_SWR_AVAILABLE},                       /* TMU0 */  \
        {0x150, PCC_CGC_AVAILABLE | PCC_CLK_DOMAIN_BUS | PCC_FUNCCLK_MUXDIVL_USED | PCC_MOUDULE_DIV_USED | PCC_DWP_SWR_AVAILABLE}, /* SENT0 */ \
        {0x160, PCC_CLK_DOMAIN_BUS | PCC_DWP_SWR_AVAILABLE},                                                                       /* MB0 */   \
        {0x170, PCC_CGC_AVAILABLE | PCC_CLK_DOMAIN_BUS | PCC_FUNCCLK_MUXDIVH_USED | PCC_FUNCCLK_MUXDIVHPIN_USED | PCC_DWP_SWR_AVAILABLE},  /* FTU0 */ \
        {0x174, PCC_CGC_AVAILABLE | PCC_CLK_DOMAIN_BUS | PCC_FUNCCLK_MUXDIVH_USED | PCC_FUNCCLK_MUXDIVHPIN_USED | PCC_DWP_SWR_AVAILABLE},  /* FTU1 */ \
        {0x178, PCC_CGC_AVAILABLE | PCC_CLK_DOMAIN_BUS | PCC_FUNCCLK_MUXDIVH_USED | PCC_FUNCCLK_MUXDIVHPIN_USED | PCC_DWP_SWR_AVAILABLE},  /* FTU2 */ \
        {0x17C, PCC_CGC_AVAILABLE | PCC_CLK_DOMAIN_BUS | PCC_FUNCCLK_MUXDIVH_USED | PCC_FUNCCLK_MUXDIVHPIN_USED | PCC_DWP_SWR_AVAILABLE},  /* FTU3 */ \
        {0x180, PCC_CGC_AVAILABLE | PCC_CLK_DOMAIN_BUS | PCC_FUNCCLK_MUXDIVH_USED | PCC_FUNCCLK_MUXDIVHPIN_USED | PCC_DWP_SWR_AVAILABLE},  /* FTU4 */ \
        {0x184, PCC_CGC_AVAILABLE | PCC_CLK_DOMAIN_BUS | PCC_FUNCCLK_MUXDIVH_USED | PCC_FUNCCLK_MUXDIVHPIN_USED | PCC_DWP_SWR_AVAILABLE},  /* FTU5 */ \
        {0x188, PCC_CGC_AVAILABLE | PCC_CLK_DOMAIN_BUS | PCC_FUNCCLK_MUXDIVM_USED | PCC_DWP_SWR_AVAILABLE},     /* FCSPI0 */  \
        {0x18C, PCC_CGC_AVAILABLE | PCC_CLK_DOMAIN_BUS | PCC_FUNCCLK_MUXDIVM_USED | PCC_DWP_SWR_AVAILABLE},     /* FCSPI1 */  \
        {0x190, PCC_CGC_AVAILABLE | PCC_CLK_DOMAIN_BUS | PCC_FUNCCLK_MUXDIVM_USED | PCC_DWP_SWR_AVAILABLE},     /* FCSPI2 */  \
        {0x194, PCC_CGC_AVAILABLE | PCC_CLK_DOMAIN_BUS | PCC_FUNCCLK_MUXDIVM_USED | PCC_DWP_SWR_AVAILABLE},     /* FCSPI3 */  \
        {0x198, PCC_CGC_AVAILABLE | PCC_CLK_DOMAIN_BUS | PCC_FUNCCLK_MUXDIVM_USED | PCC_DWP_SWR_AVAILABLE},     /* FCIIC0 */  \
        {0x1A0, PCC_CGC_AVAILABLE | PCC_CLK_DOMAIN_BUS | PCC_FUNCCLK_MUXDIVM_USED | PCC_DWP_SWR_AVAILABLE},     /* FCUART0 */ \
        {0x1A4, PCC_CGC_AVAILABLE | PCC_CLK_DOMAIN_BUS | PCC_FUNCCLK_MUXDIVM_USED | PCC_DWP_SWR_AVAILABLE},     /* FCUART1 */ \
        {0x1A8, PCC_CGC_AVAILABLE | PCC_CLK_DOMAIN_BUS | PCC_FUNCCLK_MUXDIVM_USED | PCC_DWP_SWR_AVAILABLE},     /* FCUART2 */ \
        {0x1AC, PCC_CGC_AVAILABLE | PCC_CLK_DOMAIN_BUS | PCC_FUNCCLK_MUXDIVM_USED | PCC_DWP_SWR_AVAILABLE},     /* FCUART3 */ \
        {0x1B0, PCC_CGC_AVAILABLE | PCC_CLK_DOMAIN_BUS | PCC_FUNCCLK_MUXDIVM_USED | PCC_DWP_SWR_AVAILABLE},     /* FCUART4 */ \
        {0x1B4, PCC_CGC_AVAILABLE | PCC_CLK_DOMAIN_BUS | PCC_FUNCCLK_MUXDIVM_USED | PCC_DWP_SWR_AVAILABLE},     /* FCUART5 */ \
        {0x1B8, PCC_CGC_AVAILABLE | PCC_CLK_DOMAIN_BUS | PCC_FUNCCLK_MUXDIVM_USED | PCC_DWP_SWR_AVAILABLE},     /* FCUART6 */ \
        {0x1BC, PCC_CGC_AVAILABLE | PCC_CLK_DOMAIN_BUS | PCC_FUNCCLK_MUXDIVM_USED | PCC_DWP_SWR_AVAILABLE},     /* FCUART7 */ \
        {0x1C0, PCC_CGC_AVAILABLE | PCC_CLK_DOMAIN_SLOW | PCC_DWP_SWR_AVAILABLE},      /* LU0 */  \
        {0x1C4, PCC_CGC_AVAILABLE | PCC_CLK_DOMAIN_SLOW | PCC_DWP_SWR_AVAILABLE},      /* LU1 */  \
        {0x1E0, PCC_CGC_AVAILABLE | PCC_CLK_DOMAIN_BUS | PCC_DWP_SWR_AVAILABLE},       /* FREQM */\
        {0x1FC, PCC_CGC_AVAILABLE | PCC_CLK_DOMAIN_SLOW},                              /* STCU */ \
        {0x200, PCC_CGC_AVAILABLE | PCC_CLK_DOMAIN_BUS | PCC_FUNCCLK_MUXDIVH_USED | PCC_MOUDULE_DIV_USED | PCC_DWP_SWR_AVAILABLE},     /* FLEXCAN0 */  \
        {0x210, PCC_CGC_AVAILABLE | PCC_CLK_DOMAIN_BUS | PCC_FUNCCLK_MUXDIVH_USED | PCC_MOUDULE_DIV_USED | PCC_DWP_SWR_AVAILABLE},     /* FLEXCAN1 */  \
        {0x220, PCC_CGC_AVAILABLE | PCC_CLK_DOMAIN_BUS | PCC_FUNCCLK_MUXDIVH_USED | PCC_MOUDULE_DIV_USED | PCC_DWP_SWR_AVAILABLE},     /* FLEXCAN2 */  \
        {0x230, PCC_CGC_AVAILABLE | PCC_CLK_DOMAIN_BUS | PCC_FUNCCLK_MUXDIVH_USED | PCC_MOUDULE_DIV_USED | PCC_DWP_SWR_AVAILABLE},     /* FLEXCAN3 */  \
        {0x308, PCC_CGC_AVAILABLE | PCC_CLK_DOMAIN_BUS | PCC_DWP_SWR_AVAILABLE},     /* PTIMER2 */\
        {0x30C, PCC_CGC_AVAILABLE | PCC_CLK_DOMAIN_BUS | PCC_DWP_SWR_AVAILABLE},     /* PTIMER3 */\
        {0x318, PCC_CGC_AVAILABLE | PCC_CLK_DOMAIN_BUS | PCC_FUNCCLK_MUXDIVH_USED | PCC_MOUDULE_DIV_USED | PCC_DWP_SWR_AVAILABLE},     /* ADC2 */  \
        {0x34C, PCC_CLK_DOMAIN_SLOW | PCC_DWP_SWR_AVAILABLE},                        /* WDOG1 */  \
        {0x350, PCC_CLK_DOMAIN_SLOW | PCC_DWP_SWR_AVAILABLE},                        /* WDOG2 */  \
        {0x35C, PCC_CGC_AVAILABLE | PCC_CLK_DOMAIN_BUS | PCC_FUNCCLK_MUXDIVH_USED | PCC_DWP_SWR_AVAILABLE},     /* FCPIT1 */  \
        {0x3A4, PCC_CGC_AVAILABLE | PCC_CLK_DOMAIN_BUS | PCC_FUNCCLK_MUXDIVM_USED | PCC_DWP_SWR_AVAILABLE},     /* FCSPI7 */  \
        {0x3FC, PCC_CGC_AVAILABLE | PCC_CLK_DOMAIN_BUS | PCC_FUNCCLK_MUXDIVH_USED | PCC_FUNCCLK_MUXDIVHPIN_USED | PCC_DWP_SWR_AVAILABLE},  /* FTU6 */  \
        {0x400, PCC_CGC_AVAILABLE | PCC_CLK_DOMAIN_BUS | PCC_FUNCCLK_MUXDIVH_USED | PCC_FUNCCLK_MUXDIVHPIN_USED | PCC_DWP_SWR_AVAILABLE},  /* FTU7 */  \
        {0x41C, PCC_CGC_AVAILABLE | PCC_CLK_DOMAIN_BUS | PCC_FUNCCLK_MUXDIVM_USED | PCC_DWP_SWR_AVAILABLE},       /* FCIIC1 */  \
        {0x440, PCC_CGC_AVAILABLE | PCC_CLK_DOMAIN_BUS | PCC_FUNCCLK_MUXDIVM_USED | PCC_DWP_SWR_AVAILABLE},       /* FCSPI4 */  \
        {0x450, PCC_CGC_AVAILABLE | PCC_CLK_DOMAIN_BUS | PCC_FUNCCLK_MUXDIVM_USED | PCC_MOUDULE_DIV_USED | PCC_DWP_SWR_AVAILABLE}    /* MSC0 */  \
    };


/** @brief PCC clock list */
typedef enum
{
    PCC_CLK_DMA0 = 0U,
    PCC_CLK_DMAMUX0,
    PCC_CLK_ROMC,
    PCC_CLK_ERM0,
    PCC_CLK_EIM0,
    PCC_CLK_INTM0,
    PCC_CLK_ISM0,
    PCC_CLK_WDOG0,
    PCC_CLK_TRGSEL0,
    PCC_CLK_TRGSEL1,
    PCC_CLK_TRGSEL2,
    PCC_CLK_TRGSEL3,
    PCC_CLK_CRC0,
    PCC_CLK_CORDIC,
    PCC_CLK_TSTMP0,
    PCC_CLK_TSTMP1,
    PCC_CLK_FCPIT0,
    PCC_CLK_AONTIMER0,
    PCC_CLK_RTC,
    PCC_CLK_CMU0,
    PCC_CLK_CMU1,
    PCC_CLK_CMU2,
    PCC_CLK_CMU3,
    PCC_CLK_CMU4,
    PCC_CLK_PTIMER0,
    PCC_CLK_PTIMER1,
    PCC_CLK_ADC0,
    PCC_CLK_ADC1,
    PCC_CLK_WKU0,
    PCC_CLK_CMP0,
    PCC_CLK_CMP1,
    PCC_CLK_TMU0,
    PCC_CLK_SENT0,
    PCC_CLK_MB0,
    PCC_CLK_FTU0,
    PCC_CLK_FTU1,
    PCC_CLK_FTU2,
    PCC_CLK_FTU3,
    PCC_CLK_FTU4,
    PCC_CLK_FTU5,
    PCC_CLK_FCSPI0,
    PCC_CLK_FCSPI1,
    PCC_CLK_FCSPI2,
    PCC_CLK_FCSPI3,
    PCC_CLK_FCIIC0,
    PCC_CLK_FCUART0,
    PCC_CLK_FCUART1,
    PCC_CLK_FCUART2,
    PCC_CLK_FCUART3,
    PCC_CLK_FCUART4,
    PCC_CLK_FCUART5,
    PCC_CLK_FCUART6,
    PCC_CLK_FCUART7,
    PCC_CLK_LU0,
    PCC_CLK_LU1,
    PCC_CLK_FREQM,
    PCC_CLK_STCU,
    PCC_CLK_FLEXCAN0,
    PCC_CLK_FLEXCAN1,
    PCC_CLK_FLEXCAN2,
    PCC_CLK_FLEXCAN3,
    PCC_CLK_PTIMER2,
    PCC_CLK_PTIMER3,
    PCC_CLK_ADC2,
    PCC_CLK_WDOG1,
    PCC_CLK_WDOG2,
    PCC_CLK_FCPIT1,
    PCC_CLK_FCSPI7,
    PCC_CLK_FTU6,
    PCC_CLK_FTU7,
    PCC_CLK_FCIIC1,
    PCC_CLK_FCSPI4,
    PCC_CLK_MSC0,
    PCC_END_OF_CLOCKS
} PCC_ClkSrcType;

/*********************** CMP Features ****************************/

/** Number of instances of the CMP module. */
#define CMP_INSTANCE_COUNT                       (2u)

/** Array initializer of CMP peripheral base addresses */
#define CMP_BASE_ADDRS                           {CMP0_BASE, CMP1_BASE}
/** Array initializer of CMP peripheral base pointers */
#define CMP_BASE_PTRS                            {CMP0, CMP1}

/*********************** CMP Features End ****************************/

/*********************** FCSPI Features ****************************/
/** Number of instances of the FCSPI module. */
#define FCSPI_INSTANCE_COUNT                     (6u)

/* FCSPI - Peripheral instance base addresses */
/** Peripheral FCSPI0 base address */
#define FCSPI0_BASE                              (0x40062000u)
/** Peripheral FCSPI0 base pointer */
#define FCSPI0                                   ((FCSPI_Type *)FCSPI0_BASE)
/** Peripheral FCSPI1 base address */
#define FCSPI1_BASE                              (0x40063000u)
/** Peripheral FCSPI1 base pointer */
#define FCSPI1                                   ((FCSPI_Type *)FCSPI1_BASE)
/** Peripheral FCSPI2 base address */
#define FCSPI2_BASE                              (0x40064000u)
/** Peripheral FCSPI2 base pointer */
#define FCSPI2                                   ((FCSPI_Type *)FCSPI2_BASE)
/** Peripheral FCSPI3 base address */
#define FCSPI3_BASE                              (0x40065000u)
/** Peripheral FCSPI3 base pointer */
#define FCSPI3                                   ((FCSPI_Type *)FCSPI3_BASE)
/** Peripheral FCSPI4 base address */
#define FCSPI4_BASE                              (0x40470000u)
/** Peripheral FCSPI4 base pointer */
#define FCSPI4                                   ((FCSPI_Type *)FCSPI4_BASE)
/** Peripheral FCSPI7 base address */
#define FCSPI7_BASE                              (0x40449000u)
/** Peripheral FCSPI7 base pointer */
#define FCSPI7                                   ((FCSPI_Type *)FCSPI7_BASE)

/** Array initializer of FCSPI peripheral base addresses */
#define FCSPI_BASE_ADDRS                         {FCSPI0_BASE, FCSPI1_BASE, FCSPI2_BASE, FCSPI3_BASE, FCSPI4_BASE, FCSPI7_BASE}
/** Array initializer of FCSPI peripheral base pointers */
#define FCSPI_BASE_PTRS                          {FCSPI0, FCSPI1, FCSPI2, FCSPI3, FCSPI4, FCSPI7}


/**
 * @name FCSPI_InstanceType
 * @brief FCSpi hardware instances
 *
 * FCSpi consist of multiple hardware instances, for example, FCSPI0, FCSPI1...
 * Just as the enumeration type "FCSPI_InstanceType" definition shows.
 * We use variables of this type to indicate which hardware instance to use.
 * @{
 */
typedef enum {
    FCSPI_INSTANCE_0 = 0, /**< Select FCSPI0 */
    FCSPI_INSTANCE_1 = 1, /**< Select FCSPI1 */
    FCSPI_INSTANCE_2 = 2, /**< Select FCSPI2 */
    FCSPI_INSTANCE_3 = 3, /**< Select FCSPI3 */
    FCSPI_INSTANCE_4 = 4, /**< Select FCSPI4 */
    FCSPI_INSTANCE_7 = 5, /**< Select FCSPI5 */
} FCSPI_InstanceType;
/** @}*/

/*********************** FCSPI Features End ****************************/

#endif /* _DEVICE_FEATURES_FC7300F4MDS1A320T1A_H_ */
