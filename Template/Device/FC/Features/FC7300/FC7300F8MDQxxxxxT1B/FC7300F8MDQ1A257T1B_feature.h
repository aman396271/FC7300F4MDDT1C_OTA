#ifndef _DEVICE_FEATURES_FC7300F8MDQ1A257T1B_H_
#define _DEVICE_FEATURES_FC7300F8MDQ1A257T1B_H_

#include "FC7300F8MDQxxxxxT1B_feature.h"

/*********************** PORT Features ****************************/
#define PORT_INSTANCE_COUNT 9U

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
    PORTA_1_FLEXCAN11_RX = 3U,
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
    PORTA_11_eFTU0_OUT_S11 = 6U,
    PORTA_11_NMI_b = 7U,
} PORT_A11MuxType;

/** @brief PORTA12 Mode enumeration */
typedef enum
{
    PORTA_12_HSADC2_CH4 = 0U,
    PORTA_12_GPIO = 1U,
    PORTA_12_FTU0_CH7 = 2U,
    PORTA_12_FLEXCAN1_RX = 3U,
    PORTA_12_SENT0_RXD1 = 4U,
    PORTA_12_FCSPI0_SOUT = 5U,
    PORTA_12_FTU2_QD_PHB = 6U,
    PORTA_12_eFTU0_OUT_S10 = 7U,
} PORT_A12MuxType;

/** @brief PORTA13 Mode enumeration */
typedef enum
{
    PORTA_13_GPIO = 1U,
    PORTA_13_FTU0_CH3 = 2U,
    PORTA_13_eFTU1_IN6 = 4U,
    PORTA_13_FCUART0_RX = 5U,
    PORTA_13_FTU2_QD_PHA = 6U,
    PORTA_13_eFTU0_OUT_S5 = 7U,
} PORT_A13MuxType;

/** @brief PORTA14 Mode enumeration */
typedef enum
{
    PORTA_14_GPIO = 1U,
    PORTA_14_FTU_FLT17 = 2U,
    PORTA_14_AONTIMER0_CLK1 = 3U,
    PORTA_14_LP_WAKEUP2 = 4U,
    PORTA_14_FCUART0_TX = 5U,
    PORTA_14_eFTU1_IN3 = 6U,
    PORTA_14_eFTU0_OUT_S2 = 7U,
} PORT_A14MuxType;

/** @brief PORTA15 Mode enumeration */
typedef enum
{
    PORTA_15_ADC2_SE17 = 0U,
    PORTA_15_GPIO = 1U,
    PORTA_15_FTU6_CH4 = 2U,
    PORTA_15_QDT1_PHB = 3U,
    PORTA_15_FCUART10_TX = 4U,
    PORTA_15_TRGSEL_OUT0 = 5U,
    PORTA_15_FLEXCAN6_RX = 6U,
    PORTA_15_SDADC1_EXT_SIGN = 7U,
} PORT_A15MuxType;

/** @brief PORTA16 Mode enumeration */
typedef enum
{
    PORTA_16_GPIO = 1U,
    PORTA_16_FTU6_CH2 = 2U,
    PORTA_16_FCSMU_PIN0 = 3U,
    PORTA_16_eFTU1_IN1 = 4U,
    PORTA_16_eFTU2_OUT_S5 = 5U,
} PORT_A16MuxType;

/** @brief PORTA17 Mode enumeration */
typedef enum
{
    PORTA_17_ADC5_SE15 = 0U,
    PORTA_17_GPIO = 1U,
    PORTA_17_FTU5_CH5 = 2U,
    PORTA_17_FTU_FLT15 = 3U,
    PORTA_17_FCSPI1_PCS2 = 4U,
    PORTA_17_FLEXCAN4_TX = 5U,
    PORTA_17_eFTU2_OUT_S25 = 6U,
    PORTA_17_eFTU0_OUT_S30 = 7U,
} PORT_A17MuxType;

/** @brief PORTA18 Mode enumeration */
typedef enum
{
    PORTA_18_HSADC0_CH0 = 0U,
    PORTA_18_GPIO = 1U,
    PORTA_18_FTU3_CH6 = 2U,
    PORTA_18_FCUART1_TX = 3U,
    PORTA_18_eFTU_GTOM8 = 5U,
} PORT_A18MuxType;

/** @brief PORTA19 Mode enumeration */
typedef enum
{
    PORTA_19_HSADC0_CH1 = 0U,
    PORTA_19_GPIO = 1U,
    PORTA_19_FCUART1_RX = 3U,
    PORTA_19_FTU6_CH7 = 4U,
    PORTA_19_eFTU_GTOM9 = 5U,
    PORTA_19_FLEXCAN8_TX = 6U,
} PORT_A19MuxType;

/** @brief PORTA2 Mode enumeration */
typedef enum
{
    PORTA_2_ADC5_SE22 = 0U,
    PORTA_2_GPIO = 1U,
    PORTA_2_FTU2_CH3 = 2U,
    PORTA_2_FCIIC0_SDA = 3U,
    PORTA_2_MSC1_FCLP = 4U,
    PORTA_2_eFTU_GTOM15 = 5U,
    PORTA_2_FCUART0_RX = 6U,
    PORTA_2_FLEXCORE_TDO = 7U,
} PORT_A2MuxType;

/** @brief PORTA20 Mode enumeration */
typedef enum
{
    PORTA_20_HSADC1_CH0 = 0U,
    PORTA_20_GPIO = 1U,
    PORTA_20_FTU3_CH7 = 2U,
    PORTA_20_FCUART3_RTS = 3U,
    PORTA_20_eFTU_GTOM10 = 5U,
    PORTA_20_FLEXCAN8_RX = 6U,
} PORT_A20MuxType;

/** @brief PORTA21 Mode enumeration */
typedef enum
{
    PORTA_21_ADC1_SE4_ADC1_DIFF_N0 = 0U,
    PORTA_21_GPIO = 1U,
    PORTA_21_FCUART6_RX = 2U,
    PORTA_21_FCUART3_CTS = 3U,
    PORTA_21_FTU2_CH5 = 4U,
    PORTA_21_eFTU2_OUT_S8 = 5U,
    PORTA_21_FLEXCAN13_TX = 6U,
    PORTA_21_eFTU_GTOM10 = 7U,
} PORT_A21MuxType;

/** @brief PORTA22 Mode enumeration */
typedef enum
{
    PORTA_22_ADC1_SE0_ADC1_DIFF_P0 = 0U,
    PORTA_22_GPIO = 1U,
    PORTA_22_FTU2_CH3 = 2U,
    PORTA_22_FTU2_QD_PHA = 3U,
    PORTA_22_FCUART7_RX = 4U,
    PORTA_22_eFTU2_OUT_S6 = 5U,
    PORTA_22_eFTU_GTOM8 = 6U,
} PORT_A22MuxType;

/** @brief PORTA23 Mode enumeration */
typedef enum
{
    PORTA_23_ADC1_SE8_CMP0_IN0 = 0U,
    PORTA_23_GPIO = 1U,
    PORTA_23_FTU4_CH1 = 2U,
    PORTA_23_FCUART3_RX = 3U,
    PORTA_23_ETM_TRACE_D0 = 4U,
    PORTA_23_eFTU1_OUT_S11 = 5U,
    PORTA_23_QDT0_PHA = 6U,
    PORTA_23_TPU0_CH3 = 7U,
} PORT_A23MuxType;

/** @brief PORTA24 Mode enumeration */
typedef enum
{
    PORTA_24_ADC0_SE9_CMP0_IN1 = 0U,
    PORTA_24_GPIO = 1U,
    PORTA_24_FTU4_CH0 = 2U,
    PORTA_24_FCUART3_TX = 3U,
    PORTA_24_ETM_TRACE_D1 = 4U,
    PORTA_24_eFTU1_OUT_S12 = 5U,
    PORTA_24_QDT0_PHB = 6U,
    PORTA_24_TPU0_CH4 = 7U,
} PORT_A24MuxType;

/** @brief PORTA25 Mode enumeration */
typedef enum
{
    PORTA_25_ADC1_SE3_ADC1_DIFF_P3 = 0U,
    PORTA_25_GPIO = 1U,
    PORTA_25_FTU4_CH3 = 2U,
    PORTA_25_TPU0_CH22 = 3U,
    PORTA_25_HRPWM0_CH6 = 4U,
    PORTA_25_FCSPI2_SOUT = 5U,
    PORTA_25_eFTU1_OUT_S8 = 6U,
    PORTA_25_HSADC2_BFL = 7U,
} PORT_A25MuxType;

/** @brief PORTA26 Mode enumeration */
typedef enum
{
    PORTA_26_ADC0_SE2_ADC0_DIFF_P2 = 0U,
    PORTA_26_GPIO = 1U,
    PORTA_26_FTU2_CH2 = 2U,
    PORTA_26_TPU0_CH0 = 3U,
    PORTA_26_SSI0_DIG_14_CH3 = 4U,
    PORTA_26_eFTU2_OUT_S2 = 5U,
    PORTA_26_FLEXCAN12_TX = 6U,
    PORTA_26_eFTU1_OUT_S0 = 7U,
} PORT_A26MuxType;

/** @brief PORTA27 Mode enumeration */
typedef enum
{
    PORTA_27_ADC1_SE9 = 0U,
    PORTA_27_GPIO = 1U,
    PORTA_27_FTU5_CH7 = 2U,
    PORTA_27_FCUART0_TX = 3U,
    PORTA_27_ETM_TRACE_D2 = 4U,
    PORTA_27_FCSPI1_PCS0 = 5U,
    PORTA_27_TPU0_CH13 = 6U,
    PORTA_27_eFTU2_OUT_S16 = 7U,
} PORT_A27MuxType;

/** @brief PORTA28 Mode enumeration */
typedef enum
{
    PORTA_28_ADC1_SE10 = 0U,
    PORTA_28_GPIO = 1U,
    PORTA_28_FTU5_CH5 = 2U,
    PORTA_28_FCUART0_RX = 3U,
    PORTA_28_eFTU_GTOM12 = 4U,
    PORTA_28_FCSPI1_SCK = 5U,
    PORTA_28_TPU0_CH15 = 6U,
    PORTA_28_eFTU2_OUT_S18 = 7U,
} PORT_A28MuxType;

/** @brief PORTA29 Mode enumeration */
typedef enum
{
    PORTA_29_ADC0_SE11 = 0U,
    PORTA_29_GPIO = 1U,
    PORTA_29_FTU5_CH4 = 2U,
    PORTA_29_HSADC3_BFL = 3U,
    PORTA_29_eFTU_GTOM13 = 4U,
    PORTA_29_FCSPI1_SIN = 5U,
    PORTA_29_TPU0_CH16 = 6U,
    PORTA_29_eFTU2_OUT_S19 = 7U,
} PORT_A29MuxType;

/** @brief PORTA3 Mode enumeration */
typedef enum
{
    PORTA_3_ADC3_SE21 = 0U,
    PORTA_3_GPIO = 1U,
    PORTA_3_FTU2_CH2 = 2U,
    PORTA_3_FCIIC0_SCL = 3U,
    PORTA_3_TPU0_CH14 = 4U,
    PORTA_3_eFTU_GTOM14 = 5U,
    PORTA_3_FCUART0_TX = 6U,
    PORTA_3_FLEXCORE_TCLK = 7U,
} PORT_A3MuxType;

/** @brief PORTA30 Mode enumeration */
typedef enum
{
    PORTA_30_ADC0_SE15_CMP0_IN4 = 0U,
    PORTA_30_GPIO = 1U,
    PORTA_30_FTU5_CH2 = 2U,
    PORTA_30_FCUART2_RX = 3U,
    PORTA_30_ETM_TRACE_D5 = 4U,
    PORTA_30_FCSPI1_PCS2 = 5U,
    PORTA_30_eFTU0_OUT_S19 = 6U,
    PORTA_30_QDT1_PHB = 7U,
} PORT_A30MuxType;

/** @brief PORTA31 Mode enumeration */
typedef enum
{
    PORTA_31_ADC0_SE17_ADC1_SE17 = 0U,
    PORTA_31_GPIO = 1U,
    PORTA_31_FTU0_CH6 = 2U,
    PORTA_31_FCUART5_TX = 3U,
    PORTA_31_FTU_FLT3 = 4U,
    PORTA_31_FLEXCAN3_TX = 5U,
    PORTA_31_eFTU0_OUT_S21 = 6U,
    PORTA_31_eFTU1_OUT_S1 = 7U,
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
    PORTA_6_ADC5_SE13 = 0U,
    PORTA_6_GPIO = 1U,
    PORTA_6_FTU5_CH0 = 2U,
    PORTA_6_FTU_FLT13 = 3U,
    PORTA_6_FCUART1_CTS = 4U,
    PORTA_6_TRGSEL_OUT4 = 5U,
    PORTA_6_eFTU1_OUT_S30 = 6U,
    PORTA_6_FCSPI7_SIN = 7U,
} PORT_A6MuxType;

/** @brief PORTA7 Mode enumeration */
typedef enum
{
    PORTA_7_ADC4_SE12 = 0U,
    PORTA_7_GPIO = 1U,
    PORTA_7_FTU7_CH6 = 2U,
    PORTA_7_FTU_FLT12 = 3U,
    PORTA_7_FCUART1_RTS = 4U,
    PORTA_7_FCSPI4_SIN = 5U,
    PORTA_7_eFTU1_OUT_S28 = 6U,
    PORTA_7_TPU0_CH11 = 7U,
} PORT_A7MuxType;

/** @brief PORTA8 Mode enumeration */
typedef enum
{
    PORTA_8_HSADC3_CH0 = 0U,
    PORTA_8_GPIO = 1U,
    PORTA_8_FCUART2_RX = 2U,
    PORTA_8_eFTU2_IN5 = 5U,
    PORTA_8_FTU1_QD_PHB = 6U,
    PORTA_8_eFTU0_OUT_S13 = 7U,
} PORT_A8MuxType;

/** @brief PORTA9 Mode enumeration */
typedef enum
{
    PORTA_9_HSADC3_CH1 = 0U,
    PORTA_9_GPIO = 1U,
    PORTA_9_FCUART2_TX = 2U,
    PORTA_9_RTC_CLKOUT = 3U,
    PORTA_9_SENT0_RXD0 = 4U,
    PORTA_9_eFTU2_IN4 = 5U,
    PORTA_9_eFTU2_OUT_S30 = 6U,
} PORT_A9MuxType;

/** @brief PORTB0 Mode enumeration */
typedef enum
{
    PORTB_0_ADC3_SE3_ADC3_DIFF_P3 = 0U,
    PORTB_0_GPIO = 1U,
    PORTB_0_QDT3_INDEX = 2U,
    PORTB_0_HSADC2_BFL = 3U,
    PORTB_0_eFTU0_OUT_S17 = 4U,
    PORTB_0_FLEXCAN0_RX = 5U,
    PORTB_0_FTU3_CH6 = 6U,
    PORTB_0_eFTU1_OUT_S23 = 7U,
} PORT_B0MuxType;

/** @brief PORTB1 Mode enumeration */
typedef enum
{
    PORTB_1_ADC4_SE7_ADC4_DIFF_N3 = 0U,
    PORTB_1_GPIO = 1U,
    PORTB_1_QDT3_HOME = 2U,
    PORTB_1_FTU_TCK0 = 3U,
    PORTB_1_eFTU0_OUT_S16 = 4U,
    PORTB_1_FLEXCAN0_TX = 5U,
    PORTB_1_FTU3_CH5 = 6U,
    PORTB_1_eFTU1_OUT_S31 = 7U,
} PORT_B1MuxType;

/** @brief PORTB10 Mode enumeration */
typedef enum
{
    PORTB_10_ADC4_SE23 = 0U,
    PORTB_10_GPIO = 1U,
    PORTB_10_FTU2_CH5 = 2U,
    PORTB_10_TRGSEL_OUT2 = 3U,
    PORTB_10_TPU0_CH12 = 4U,
    PORTB_10_FLEXCAN7_RX = 5U,
    PORTB_10_eFTU2_IN0 = 6U,
    PORTB_10_eFTU_GTOM12 = 7U,
} PORT_B10MuxType;

/** @brief PORTB11 Mode enumeration */
typedef enum
{
    PORTB_11_V11_BASE_DRIVER = 0U,
    PORTB_11_GPIO = 1U,
    PORTB_11_FTU6_CH0 = 2U,
    PORTB_11_eFTU2_IN0 = 3U,
    PORTB_11_TPU0_CH24 = 4U,
    PORTB_11_eFTU2_OUT_S15 = 5U,
} PORT_B11MuxType;

/** @brief PORTB12 Mode enumeration */
typedef enum
{
    PORTB_12_ADC4_SE18 = 0U,
    PORTB_12_GPIO = 1U,
    PORTB_12_eFTU1_IN3 = 3U,
    PORTB_12_FCSPI5_PCS1 = 4U,
    PORTB_12_FLEXCAN2_RX = 5U,
    PORTB_12_eFTU2_OUT_S30 = 6U,
    PORTB_12_eFTU0_OUT_S30 = 7U,
} PORT_B12MuxType;

/** @brief PORTB13 Mode enumeration */
typedef enum
{
    PORTB_13_ADC5_SE18 = 0U,
    PORTB_13_GPIO = 1U,
    PORTB_13_FTU3_CH2 = 2U,
    PORTB_13_MSC1_SDI3 = 4U,
    PORTB_13_QDT2_PHB = 5U,
    PORTB_13_eFTU0_OUT_S27 = 6U,
    PORTB_13_eFTU1_OUT_S19 = 7U,
} PORT_B13MuxType;

/** @brief PORTB14 Mode enumeration */
typedef enum
{
    PORTB_14_ADC3_SE17 = 0U,
    PORTB_14_GPIO = 1U,
    PORTB_14_FTU3_CH1 = 2U,
    PORTB_14_FCUART4_RX = 3U,
    PORTB_14_MSC1_EN3 = 4U,
    PORTB_14_QDT2_PHA = 5U,
    PORTB_14_eFTU0_OUT_S26 = 6U,
    PORTB_14_eFTU1_OUT_S18 = 7U,
} PORT_B14MuxType;

/** @brief PORTB15 Mode enumeration */
typedef enum
{
    PORTB_15_ADC4_SE17 = 0U,
    PORTB_15_GPIO = 1U,
    PORTB_15_FTU3_CH0 = 2U,
    PORTB_15_FCUART4_TX = 3U,
    PORTB_15_MSC1_SDI2 = 4U,
    PORTB_15_QDT2_INDEX = 5U,
    PORTB_15_FLEXCAN12_RX = 6U,
    PORTB_15_eFTU1_OUT_S17 = 7U,
} PORT_B15MuxType;

/** @brief PORTB16 Mode enumeration */
typedef enum
{
    PORTB_16_ADC5_SE17 = 0U,
    PORTB_16_GPIO = 1U,
    PORTB_16_FTU5_CH7 = 2U,
    PORTB_16_FCUART5_CTS = 3U,
    PORTB_16_MSC1_EN2 = 4U,
    PORTB_16_QDT2_HOME = 5U,
    PORTB_16_FLEXCAN12_TX = 6U,
    PORTB_16_eFTU1_OUT_S16 = 7U,
} PORT_B16MuxType;

/** @brief PORTB17 Mode enumeration */
typedef enum
{
    PORTB_17_ADC4_SE15 = 0U,
    PORTB_17_GPIO = 1U,
    PORTB_17_FTU5_CH6 = 2U,
    PORTB_17_eFTU0_OUT_S31 = 3U,
    PORTB_17_FCSPI1_PCS3 = 4U,
    PORTB_17_FLEXCAN4_RX = 5U,
    PORTB_17_eFTU0_OUT_S25 = 6U,
    PORTB_17_eFTU1_OUT_S26 = 7U,
} PORT_B17MuxType;

/** @brief PORTB18 Mode enumeration */
typedef enum
{
    PORTB_18_ADC0_SE18_ADC1_SE18 = 0U,
    PORTB_18_GPIO = 1U,
    PORTB_18_FTU0_CH5 = 2U,
    PORTB_18_FCUART5_RX = 3U,
    PORTB_18_SSI0_DIG_14_CH2 = 4U,
    PORTB_18_FLEXCAN3_RX = 5U,
    PORTB_18_eFTU0_OUT_S22 = 6U,
    PORTB_18_eFTU1_OUT_S2 = 7U,
} PORT_B18MuxType;

/** @brief PORTB19 Mode enumeration */
typedef enum
{
    PORTB_19_ADC0_SE19_ADC1_SE19 = 0U,
    PORTB_19_GPIO = 1U,
    PORTB_19_FTU0_CH4 = 2U,
    PORTB_19_TPU0_CH9 = 3U,
    PORTB_19_SSI0_DIG_28_CH2 = 4U,
    PORTB_19_eFTU2_OUT_S27 = 5U,
    PORTB_19_eFTU0_OUT_S23 = 6U,
    PORTB_19_eFTU1_OUT_S3 = 7U,
} PORT_B19MuxType;

/** @brief PORTB20 Mode enumeration */
typedef enum
{
    PORTB_20_ADC5_SE0_ADC5_DIFF_P0 = 0U,
    PORTB_20_GPIO = 1U,
    PORTB_20_FTU1_CH0 = 2U,
    PORTB_20_FCUART1_TX = 3U,
    PORTB_20_SDADC0_PWM_P = 4U,
    PORTB_20_ENET_PPS0 = 5U,
    PORTB_20_eFTU2_OUT_S0 = 6U,
    PORTB_20_SCG_CLKOUT = 7U,
} PORT_B20MuxType;

/** @brief PORTB21 Mode enumeration */
typedef enum
{
    PORTB_21_ADC5_SE4_ADC5_DIFF_N0 = 0U,
    PORTB_21_GPIO = 1U,
    PORTB_21_FTU1_CH1 = 2U,
    PORTB_21_FCUART1_RX = 3U,
    PORTB_21_SDADC0_PWM_N = 4U,
    PORTB_21_ENET_PPS1 = 5U,
    PORTB_21_eFTU2_OUT_S1 = 6U,
    PORTB_21_RTC_CLKOUT = 7U,
} PORT_B21MuxType;

/** @brief PORTB22 Mode enumeration */
typedef enum
{
    PORTB_22_GPIO = 1U,
    PORTB_22_eFTU0_IN3 = 2U,
    PORTB_22_FCUART1_TX = 3U,
    PORTB_22_ETM_TRACE_D5 = 4U,
    PORTB_22_HSADC1_IO2 = 5U,
    PORTB_22_eFTU0_OUT_S11 = 6U,
    PORTB_22_FCSPI3_PCS0 = 7U,
} PORT_B22MuxType;

/** @brief PORTB23 Mode enumeration */
typedef enum
{
    PORTB_23_GPIO = 1U,
    PORTB_23_FTU_FLT9 = 2U,
    PORTB_23_FCSPI2_PCS0 = 3U,
    PORTB_23_FTU7_CH3 = 4U,
    PORTB_23_ENET_RXD3 = 5U,
    PORTB_23_QDT2_INDEX = 6U,
    PORTB_23_eFTU1_OUT_S0 = 7U,
} PORT_B23MuxType;

/** @brief PORTB24 Mode enumeration */
typedef enum
{
    PORTB_24_ADC5_SE1_ADC5_DIFF_P1 = 0U,
    PORTB_24_GPIO = 1U,
    PORTB_24_FTU1_CH2 = 2U,
    PORTB_24_SDADC0_PWM_P = 3U,
    PORTB_24_MSC0_FCLP = 4U,
    PORTB_24_eFTU0_OUT_S24 = 5U,
    PORTB_24_eFTU2_OUT_S2 = 6U,
    PORTB_24_TPU0_CH25 = 7U,
} PORT_B24MuxType;

/** @brief PORTB25 Mode enumeration */
typedef enum
{
    PORTB_25_ADC3_SE7_ADC3_DIFF_N3 = 0U,
    PORTB_25_GPIO = 1U,
    PORTB_25_QDT3_PHA = 2U,
    PORTB_25_HSADC3_BFL = 3U,
    PORTB_25_FCSPI2_PCS0 = 4U,
    PORTB_25_eFTU0_OUT_S18 = 5U,
    PORTB_25_FTU3_CH6 = 6U,
    PORTB_25_TPU0_CH2 = 7U,
} PORT_B25MuxType;

/** @brief PORTB26 Mode enumeration */
typedef enum
{
    PORTB_26_GPIO = 1U,
    PORTB_26_FTU6_CH0 = 2U,
    PORTB_26_HSADC3_IO2 = 3U,
    PORTB_26_HSADC0_IO0 = 4U,
    PORTB_26_ENET_COL = 5U,
    PORTB_26_eFTU2_IN3 = 6U,
    PORTB_26_eFTU0_OUT_S3 = 7U,
} PORT_B26MuxType;

/** @brief PORTB27 Mode enumeration */
typedef enum
{
    PORTB_27_ADC4_SE8 = 0U,
    PORTB_27_GPIO = 1U,
    PORTB_27_FTU7_CH0 = 2U,
    PORTB_27_FTU1_QD_PHB = 3U,
    PORTB_27_FCSPI2_SOUT = 4U,
    PORTB_27_eFTU0_OUT_S20 = 5U,
    PORTB_27_eFTU1_OUT_S21 = 6U,
    PORTB_27_TPU0_CH4 = 7U,
} PORT_B27MuxType;

/** @brief PORTB28 Mode enumeration */
typedef enum
{
    PORTB_28_ADC3_SE8 = 0U,
    PORTB_28_GPIO = 1U,
    PORTB_28_FTU7_CH1 = 2U,
    PORTB_28_SDADC0_EXT_SIGN = 3U,
    PORTB_28_FCSPI2_SIN = 4U,
    PORTB_28_eFTU0_OUT_S21 = 5U,
    PORTB_28_eFTU1_OUT_S22 = 6U,
    PORTB_28_TPU0_CH5 = 7U,
} PORT_B28MuxType;

/** @brief PORTB29 Mode enumeration */
typedef enum
{
    PORTB_29_ADC3_SE0_ADC3_DIFF_P0 = 0U,
    PORTB_29_GPIO = 1U,
    PORTB_29_FTU1_CH3 = 2U,
    PORTB_29_SDADC0_PWM_N = 3U,
    PORTB_29_eFTU0_OUT_S28 = 4U,
    PORTB_29_FCUART12_RX = 5U,
    PORTB_29_eFTU2_OUT_S6 = 6U,
    PORTB_29_MSC0_FCLP = 7U,
} PORT_B29MuxType;

/** @brief PORTB3 Mode enumeration */
typedef enum
{
    PORTB_3_ADC5_SE8 = 0U,
    PORTB_3_GPIO = 1U,
    PORTB_3_QDT3_PHB = 2U,
    PORTB_3_FTU1_QD_PHA = 3U,
    PORTB_3_FCSPI2_SCK = 4U,
    PORTB_3_eFTU0_OUT_S19 = 5U,
    PORTB_3_FTU3_CH7 = 6U,
    PORTB_3_TPU0_CH3 = 7U,
} PORT_B3MuxType;

/** @brief PORTB30 Mode enumeration */
typedef enum
{
    PORTB_30_GPIO = 1U,
    PORTB_30_FTU6_CH1 = 2U,
    PORTB_30_FCIIC1_SCL = 3U,
    PORTB_30_FCUART12_TX = 4U,
    PORTB_30_ENET_CRS = 5U,
    PORTB_30_eFTU2_IN4 = 6U,
    PORTB_30_eFTU0_OUT_S4 = 7U,
} PORT_B30MuxType;

/** @brief PORTB31 Mode enumeration */
typedef enum
{
    PORTB_31_GPIO = 1U,
    PORTB_31_FTU7_CH1 = 2U,
    PORTB_31_FCSPI2_SCK = 3U,
    PORTB_31_TPU0_CH21 = 4U,
    PORTB_31_ENET_RXD1 = 5U,
    PORTB_31_HSADC3_IO0 = 6U,
    PORTB_31_eFTU1_OUT_S16 = 7U,
} PORT_B31MuxType;

/** @brief PORTB4 Mode enumeration */
typedef enum
{
    PORTB_4_GPIO = 1U,
    PORTB_4_FTU7_CH7 = 2U,
    PORTB_4_TPU0_CH6 = 3U,
    PORTB_4_FCUART9_RX = 4U,
    PORTB_4_ENET_MDIO = 5U,
    PORTB_4_eFTU2_IN2 = 6U,
    PORTB_4_eFTU0_OUT_S2 = 7U,
} PORT_B4MuxType;

/** @brief PORTB5 Mode enumeration */
typedef enum
{
    PORTB_5_GPIO = 1U,
    PORTB_5_FTU6_CH2 = 2U,
    PORTB_5_FCIIC1_SDA = 3U,
    PORTB_5_TPU0_CH5 = 4U,
    PORTB_5_ENET_MDC = 5U,
    PORTB_5_eFTU2_IN1 = 6U,
    PORTB_5_eFTU0_OUT_S1 = 7U,
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
    PORTB_8_QDT1_HOME = 3U,
    PORTB_8_FCUART11_RX = 4U,
    PORTB_8_MSC1_SDI0 = 5U,
    PORTB_8_FCUART1_CTS = 6U,
    PORTB_8_eFTU_GTOM0 = 7U,
} PORT_B8MuxType;

/** @brief PORTB9 Mode enumeration */
typedef enum
{
    PORTB_9_GPIO = 1U,
    PORTB_9_FTU2_CH7 = 2U,
    PORTB_9_FCUART12_RX = 3U,
    PORTB_9_TPU0_CH11 = 4U,
    PORTB_9_TRGSEL_OUT1 = 5U,
    PORTB_9_eFTU2_IN2 = 6U,
    PORTB_9_eFTU_GTOM7 = 7U,
} PORT_B9MuxType;

/** @brief PORTC0 Mode enumeration */
typedef enum
{
    PORTC_0_GPIO = 1U,
    PORTC_0_eFTU0_IN6 = 2U,
    PORTC_0_TPU0_CH18 = 3U,
    PORTC_0_ETM_TRACE_D6 = 4U,
    PORTC_0_ENET_RXD1 = 5U,
    PORTC_0_eFTU1_OUT_S20 = 6U,
    PORTC_0_FCSPI3_PCS3 = 7U,
} PORT_C0MuxType;

/** @brief PORTC1 Mode enumeration */
typedef enum
{
    PORTC_1_GPIO = 1U,
    PORTC_1_FTU7_CH5 = 2U,
    PORTC_1_TPU0_CH17 = 3U,
    PORTC_1_FCUART2_CTS = 4U,
    PORTC_1_ENET_RXD0 = 5U,
    PORTC_1_eFTU0_OUT_S15 = 6U,
    PORTC_1_FCSPI3_PCS2 = 7U,
} PORT_C1MuxType;

/** @brief PORTC10 Mode enumeration */
typedef enum
{
    PORTC_10_SDADC_CH_N3_ADC3_SE6_ADC3_DIFF_N2 = 0U,
    PORTC_10_GPIO = 1U,
    PORTC_10_FTU3_CH4 = 2U,
    PORTC_10_SDADC1_PWM_N = 3U,
    PORTC_10_FLEXCAN4_RX = 4U,
    PORTC_10_FCUART13_TX = 5U,
    PORTC_10_eFTU2_OUT_S13 = 6U,
    PORTC_10_MSC0_EN1 = 7U,
} PORT_C10MuxType;

/** @brief PORTC11 Mode enumeration */
typedef enum
{
    PORTC_11_SDADC_CH_P3_ADC3_SE2_ADC3_DIFF_P2 = 0U,
    PORTC_11_GPIO = 1U,
    PORTC_11_FTU3_CH3 = 2U,
    PORTC_11_SDADC1_PWM_P = 3U,
    PORTC_11_FLEXCAN4_TX = 4U,
    PORTC_11_FCUART13_RX = 5U,
    PORTC_11_eFTU2_OUT_S12 = 6U,
    PORTC_11_MSC0_EN0 = 7U,
} PORT_C11MuxType;

/** @brief PORTC12 Mode enumeration */
typedef enum
{
    PORTC_12_SDADC0_CH0_N0 = 0U,
    PORTC_12_GPIO = 1U,
    PORTC_12_FTU1_CH5 = 2U,
    PORTC_12_SDADC0_CLK0 = 3U,
    PORTC_12_eFTU1_OUT_S17 = 4U,
    PORTC_12_TRGSEL_OUT5 = 5U,
    PORTC_12_FLEXCAN5_RX = 6U,
    PORTC_12_MSC0_EN2 = 7U,
} PORT_C12MuxType;

/** @brief PORTC13 Mode enumeration */
typedef enum
{
    PORTC_13_SDADC0_CH0_P0 = 0U,
    PORTC_13_GPIO = 1U,
    PORTC_13_FTU1_CH4 = 2U,
    PORTC_13_SDADC0_BREAK0 = 3U,
    PORTC_13_eFTU1_OUT_S16 = 4U,
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
    PORTC_14_TPU0_CH23 = 5U,
    PORTC_14_QDT2_PHA = 6U,
    PORTC_14_eFTU1_OUT_S1 = 7U,
} PORT_C14MuxType;

/** @brief PORTC15 Mode enumeration */
typedef enum
{
    PORTC_15_GPIO = 1U,
    PORTC_15_eFTU0_IN4 = 2U,
    PORTC_15_FCSPI2_PCS3 = 3U,
    PORTC_15_SCG_CLKOUT = 4U,
    PORTC_15_ENET_RXD3 = 5U,
    PORTC_15_QDT3_PHA = 6U,
    PORTC_15_FCSPI3_PCS1 = 7U,
} PORT_C15MuxType;

/** @brief PORTC16 Mode enumeration */
typedef enum
{
    PORTC_16_GPIO = 1U,
    PORTC_16_FTU_FLT7 = 2U,
    PORTC_16_FCSPI2_SOUT = 3U,
    PORTC_16_TRGSEL_OUT7 = 4U,
    PORTC_16_ENET_RXD0 = 5U,
    PORTC_16_eFTU0_OUT_S12 = 6U,
    PORTC_16_FCUART5_RX = 7U,
} PORT_C16MuxType;

/** @brief PORTC17 Mode enumeration */
typedef enum
{
    PORTC_17_GPIO = 1U,
    PORTC_17_FTU_FLT6 = 2U,
    PORTC_17_TPU0_CH20 = 3U,
    PORTC_17_TRGSEL_OUT6 = 4U,
    PORTC_17_ENET_RX_ER = 5U,
    PORTC_17_eFTU0_OUT_S14 = 6U,
    PORTC_17_FCUART5_TX = 7U,
} PORT_C17MuxType;

/** @brief PORTC18 Mode enumeration */
typedef enum
{
    PORTC_18_GPIO = 1U,
    PORTC_18_FTU7_CH2 = 2U,
    PORTC_18_FCSPI2_SIN = 3U,
    PORTC_18_TPU0_CH22 = 4U,
    PORTC_18_ENET_RXD2 = 5U,
    PORTC_18_QDT2_HOME = 6U,
    PORTC_18_eFTU1_OUT_S17 = 7U,
} PORT_C18MuxType;

/** @brief PORTC19 Mode enumeration */
typedef enum
{
    PORTC_19_ADC3_SE4_ADC3_DIFF_N0 = 0U,
    PORTC_19_GPIO = 1U,
    PORTC_19_FTU1_CH6 = 2U,
    PORTC_19_FLEXCAN6_TX = 3U,
    PORTC_19_eFTU0_OUT_S29 = 4U,
    PORTC_19_SDADC0_CH2 = 5U,
    PORTC_19_eFTU2_OUT_S7 = 6U,
    PORTC_19_MSC0_EN3 = 7U,
} PORT_C19MuxType;

/** @brief PORTC2 Mode enumeration */
typedef enum
{
    PORTC_2_GPIO = 1U,
    PORTC_2_FTU6_CH3 = 2U,
    PORTC_2_FCUART0_RX = 3U,
    PORTC_2_ETM_TRACE_CLKOUT = 4U,
    PORTC_2_ENET_TXD0 = 5U,
    PORTC_2_eFTU2_IN6 = 6U,
    PORTC_2_eFTU0_OUT_S6 = 7U,
} PORT_C2MuxType;

/** @brief PORTC20 Mode enumeration */
typedef enum
{
    PORTC_20_SDADC0_CH1_P0 = 0U,
    PORTC_20_GPIO = 1U,
    PORTC_20_FTU1_CH7 = 2U,
    PORTC_20_eFTU1_OUT_S18 = 4U,
    PORTC_20_FLEXCAN9_TX = 5U,
    PORTC_20_TPU0_CH25 = 6U,
    PORTC_20_MSC0_SDI2 = 7U,
} PORT_C20MuxType;

/** @brief PORTC21 Mode enumeration */
typedef enum
{
    PORTC_21_SDADC0_CH1_N0 = 0U,
    PORTC_21_GPIO = 1U,
    PORTC_21_FTU3_CH0 = 2U,
    PORTC_21_SDADC0_BREAK1 = 3U,
    PORTC_21_eFTU1_OUT_S19 = 4U,
    PORTC_21_FLEXCAN9_RX = 5U,
    PORTC_21_TPU0_CH26 = 6U,
    PORTC_21_MSC0_SDI3 = 7U,
} PORT_C21MuxType;

/** @brief PORTC22 Mode enumeration */
typedef enum
{
    PORTC_22_SDADC_CH_P2_ADC5_SE6_ADC5_DIFF_N2 = 0U,
    PORTC_22_GPIO = 1U,
    PORTC_22_FTU3_CH1 = 2U,
    PORTC_22_eFTU0_OUT_S25 = 3U,
    PORTC_22_eFTU2_OUT_S11 = 4U,
    PORTC_22_SDADC1_CH0 = 5U,
    PORTC_22_FLEXCAN13_TX = 6U,
    PORTC_22_MSC0_SDI1 = 7U,
} PORT_C22MuxType;

/** @brief PORTC23 Mode enumeration */
typedef enum
{
    PORTC_23_SDADC_CH_N2_ADC4_SE6_ADC4_DIFF_N2 = 0U,
    PORTC_23_GPIO = 1U,
    PORTC_23_SDADC1_BREAK0 = 2U,
    PORTC_23_FTU6_CH6 = 3U,
    PORTC_23_FCUART2_RTS = 4U,
    PORTC_23_FCUART12_TX = 5U,
    PORTC_23_eFTU1_OUT_S21 = 6U,
    PORTC_23_MSC0_SDI0 = 7U,
} PORT_C23MuxType;

/** @brief PORTC24 Mode enumeration */
typedef enum
{
    PORTC_24_SDADC1_CH1_N0 = 0U,
    PORTC_24_GPIO = 1U,
    PORTC_24_FTU3_CH2 = 2U,
    PORTC_24_FLEXCAN6_RX = 3U,
    PORTC_24_FCUART2_CTS = 4U,
    PORTC_24_eFTU1_OUT_S25 = 5U,
    PORTC_24_TPU0_CH28 = 6U,
    PORTC_24_eFTU2_OUT_S3 = 7U,
} PORT_C24MuxType;

/** @brief PORTC25 Mode enumeration */
typedef enum
{
    PORTC_25_ADC3_SE19 = 0U,
    PORTC_25_GPIO = 1U,
    PORTC_25_FTU3_CH3 = 2U,
    PORTC_25_FCUART5_RTS = 3U,
    PORTC_25_FCSPI5_PCS0 = 4U,
    PORTC_25_FLEXCAN2_TX = 5U,
    PORTC_25_TPU0_CH21 = 6U,
    PORTC_25_eFTU1_OUT_S20 = 7U,
} PORT_C25MuxType;

/** @brief PORTC28 Mode enumeration */
typedef enum
{
    PORTC_28_ADC5_SE11 = 0U,
    PORTC_28_GPIO = 1U,
    PORTC_28_FTU7_CH2 = 2U,
    PORTC_28_QDT1_INDEX = 3U,
    PORTC_28_FLEXCAN3_TX = 4U,
    PORTC_28_eFTU0_OUT_S24 = 5U,
    PORTC_28_TPU0_CH9 = 6U,
    PORTC_28_eFTU2_OUT_S18 = 7U,
} PORT_C28MuxType;

/** @brief PORTC29 Mode enumeration */
typedef enum
{
    PORTC_29_ADC5_SE12 = 0U,
    PORTC_29_GPIO = 1U,
    PORTC_29_FTU7_CH5 = 2U,
    PORTC_29_QDT1_HOME = 3U,
    PORTC_29_FLEXCAN3_RX = 4U,
    PORTC_29_TPU0_CH31 = 5U,
    PORTC_29_eFTU1_OUT_S27 = 6U,
    PORTC_29_eFTU2_OUT_S21 = 7U,
} PORT_C29MuxType;

/** @brief PORTC3 Mode enumeration */
typedef enum
{
    PORTC_3_GPIO = 1U,
    PORTC_3_FTU6_CH2 = 2U,
    PORTC_3_FCUART0_TX = 3U,
    PORTC_3_HSADC0_IO1 = 4U,
    PORTC_3_eFTU2_IN5 = 6U,
    PORTC_3_eFTU0_OUT_S5 = 7U,
} PORT_C3MuxType;

/** @brief PORTC30 Mode enumeration */
typedef enum
{
    PORTC_30_ADC3_SE12 = 0U,
    PORTC_30_GPIO = 1U,
    PORTC_30_FTU7_CH7 = 2U,
    PORTC_30_QDT1_PHA = 3U,
    PORTC_30_SDADC1_EXT_SIGN = 4U,
    PORTC_30_FCSPI4_SOUT = 5U,
    PORTC_30_eFTU1_OUT_S29 = 6U,
    PORTC_30_TPU0_CH12 = 7U,
} PORT_C30MuxType;

/** @brief PORTC31 Mode enumeration */
typedef enum
{
    PORTC_31_ADC4_SE13 = 0U,
    PORTC_31_GPIO = 1U,
    PORTC_31_FTU5_CH1 = 2U,
    PORTC_31_QDT1_PHB = 3U,
    PORTC_31_eFTU0_OUT_S22 = 4U,
    PORTC_31_TRGSEL_OUT3 = 5U,
    PORTC_31_TPU0_CH10 = 6U,
    PORTC_31_FCSPI7_SCK = 7U,
} PORT_C31MuxType;

/** @brief PORTC4 Mode enumeration */
typedef enum
{
    PORTC_4_GPIO = 1U,
    PORTC_4_FTU3_CH4 = 2U,
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
    PORTC_6_TPU0_CH0 = 3U,
    PORTC_6_FTU3_CH2 = 4U,
    PORTC_6_eFTU0_IN4 = 5U,
    PORTC_6_FTU1_QD_PHB = 6U,
    PORTC_6_eFTU1_OUT_S5 = 7U,
} PORT_C6MuxType;

/** @brief PORTC7 Mode enumeration */
typedef enum
{
    PORTC_7_GPIO = 1U,
    PORTC_7_FCUART1_TX = 2U,
    PORTC_7_TPU0_CH1 = 3U,
    PORTC_7_FTU3_CH3 = 4U,
    PORTC_7_eFTU0_IN3 = 5U,
    PORTC_7_HSADC0_IO1 = 6U,
    PORTC_7_eFTU1_OUT_S4 = 7U,
} PORT_C7MuxType;

/** @brief PORTC8 Mode enumeration */
typedef enum
{
    PORTC_8_ADC3_SE11 = 0U,
    PORTC_8_GPIO = 1U,
    PORTC_8_FTU7_CH4 = 2U,
    PORTC_8_FTU_FLT11 = 3U,
    PORTC_8_QDT0_PHB = 4U,
    PORTC_8_FCSPI4_PCS0 = 5U,
    PORTC_8_FCUART0_CTS = 6U,
    PORTC_8_eFTU2_OUT_S20 = 7U,
} PORT_C8MuxType;

/** @brief PORTC9 Mode enumeration */
typedef enum
{
    PORTC_9_ADC4_SE11 = 0U,
    PORTC_9_GPIO = 1U,
    PORTC_9_FTU7_CH3 = 2U,
    PORTC_9_FTU_FLT10 = 3U,
    PORTC_9_QDT0_PHA = 4U,
    PORTC_9_FCSPI4_SCK = 5U,
    PORTC_9_FCUART0_RTS = 6U,
    PORTC_9_eFTU2_OUT_S19 = 7U,
} PORT_C9MuxType;

/** @brief PORTD0 Mode enumeration */
typedef enum
{
    PORTD_0_ADC0_SE8 = 0U,
    PORTD_0_GPIO = 1U,
    PORTD_0_FTU4_CH2 = 2U,
    PORTD_0_TPU0_CH2 = 3U,
    PORTD_0_HSADC0_BFL = 4U,
    PORTD_0_eFTU1_OUT_S10 = 5U,
    PORTD_0_FLEXCAN13_RX = 6U,
    PORTD_0_TRGSEL_OUT1 = 7U,
} PORT_D0MuxType;

/** @brief PORTD1 Mode enumeration */
typedef enum
{
    PORTD_1_HSADC0_CH4 = 0U,
    PORTD_1_GPIO = 1U,
    PORTD_1_FCUART6_TX = 2U,
    PORTD_1_TPU0_CH27 = 3U,
    PORTD_1_FTU2_CH4 = 4U,
    PORTD_1_eFTU2_OUT_S9 = 5U,
    PORTD_1_FLEXCAN13_RX = 6U,
    PORTD_1_TRGSEL_OUT2 = 7U,
} PORT_D1MuxType;

/** @brief PORTD10 Mode enumeration */
typedef enum
{
    PORTD_10_GPIO = 1U,
    PORTD_10_FTU6_CH7 = 2U,
    PORTD_10_FTU2_QD_PHB = 3U,
    PORTD_10_ETM_TRACE_D7 = 4U,
    PORTD_10_ENET_RX_CLK = 5U,
    PORTD_10_eFTU0_OUT_S10 = 6U,
    PORTD_10_FCSPI3_SOUT = 7U,
} PORT_D10MuxType;

/** @brief PORTD11 Mode enumeration */
typedef enum
{
    PORTD_11_GPIO = 1U,
    PORTD_11_FTU6_CH6 = 2U,
    PORTD_11_FTU2_QD_PHA = 3U,
    PORTD_11_ETM_TRACE_D4 = 4U,
    PORTD_11_ENET_TX_CLK = 5U,
    PORTD_11_eFTU0_OUT_S9 = 6U,
    PORTD_11_HSADC1_IO1 = 7U,
} PORT_D11MuxType;

/** @brief PORTD12 Mode enumeration */
typedef enum
{
    PORTD_12_GPIO = 1U,
    PORTD_12_FTU6_CH5 = 2U,
    PORTD_12_FCUART2_RTS = 3U,
    PORTD_12_ETM_TRACE_D3 = 4U,
    PORTD_12_ENET_TX_EN_CTL = 5U,
    PORTD_12_eFTU0_OUT_S8 = 6U,
    PORTD_12_HSADC1_IO0 = 7U,
} PORT_D12MuxType;

/** @brief PORTD15 Mode enumeration */
typedef enum
{
    PORTD_15_ADC0_SE16_CMP0_IN6 = 0U,
    PORTD_15_GPIO = 1U,
    PORTD_15_FTU5_CH0 = 2U,
    PORTD_15_FLEXCAN2_RX = 3U,
    PORTD_15_ETM_TRACE_D7 = 4U,
    PORTD_15_ENET_PPS2 = 5U,
    PORTD_15_FCUART2_RTS = 6U,
    PORTD_15_QDT1_HOME = 7U,
} PORT_D15MuxType;

/** @brief PORTD16 Mode enumeration */
typedef enum
{
    PORTD_16_ADC1_SE15_CMP0_IN5 = 0U,
    PORTD_16_GPIO = 1U,
    PORTD_16_FTU5_CH1 = 2U,
    PORTD_16_FLEXCAN2_TX = 3U,
    PORTD_16_ETM_TRACE_D6 = 4U,
    PORTD_16_FCSPI1_PCS3 = 5U,
    PORTD_16_eFTU0_OUT_S20 = 6U,
    PORTD_16_TPU0_CH7 = 7U,
} PORT_D16MuxType;

/** @brief PORTD17 Mode enumeration */
typedef enum
{
    PORTD_17_ADC1_SE14_CMP0_IN3 = 0U,
    PORTD_17_GPIO = 1U,
    PORTD_17_FTU5_CH3 = 2U,
    PORTD_17_FCUART2_TX = 3U,
    PORTD_17_ETM_TRACE_D4 = 4U,
    PORTD_17_FCSPI1_PCS1 = 5U,
    PORTD_17_eFTU0_OUT_S18 = 6U,
    PORTD_17_QDT1_PHA = 7U,
} PORT_D17MuxType;

/** @brief PORTD18 Mode enumeration */
typedef enum
{
    PORTD_18_ADC5_SE14 = 0U,
    PORTD_18_GPIO = 1U,
    PORTD_18_FTU5_CH3 = 2U,
    PORTD_18_SDADC1_PWM_P = 3U,
    PORTD_18_FCIIC1_SDA = 4U,
    PORTD_18_TPU0_CH29 = 5U,
    PORTD_18_eFTU2_OUT_S22 = 6U,
    PORTD_18_FCSPI7_PCS0 = 7U,
} PORT_D18MuxType;

/** @brief PORTD19 Mode enumeration */
typedef enum
{
    PORTD_19_ADC4_SE14 = 0U,
    PORTD_19_GPIO = 1U,
    PORTD_19_FTU5_CH4 = 2U,
    PORTD_19_SDADC1_PWM_N = 3U,
    PORTD_19_FCIIC1_SCL = 4U,
    PORTD_19_TPU0_TCRCLK = 5U,
    PORTD_19_eFTU2_OUT_S23 = 6U,
    PORTD_19_FCSPI7_PCS1 = 7U,
} PORT_D19MuxType;

/** @brief PORTD2 Mode enumeration */
typedef enum
{
    PORTD_2_ADC5_SE21 = 0U,
    PORTD_2_GPIO = 1U,
    PORTD_2_FTU2_CH0 = 2U,
    PORTD_2_TPU0_CH16 = 3U,
    PORTD_2_FCSPI1_SCK = 4U,
    PORTD_2_FLEXCAN7_RX = 5U,
    PORTD_2_eFTU1_OUT_S25 = 6U,
    PORTD_2_FLEXCORE_TMS = 7U,
} PORT_D2MuxType;

/** @brief PORTD20 Mode enumeration */
typedef enum
{
    PORTD_20_ADC5_SE20 = 0U,
    PORTD_20_GPIO = 1U,
    PORTD_20_FTU3_CH4 = 2U,
    PORTD_20_FCUART5_RX = 3U,
    PORTD_20_FCSPI1_PCS1 = 4U,
    PORTD_20_eFTU0_OUT_S28 = 5U,
    PORTD_20_TPU0_CH20 = 6U,
    PORTD_20_eFTU1_OUT_S21 = 7U,
} PORT_D20MuxType;

/** @brief PORTD21 Mode enumeration */
typedef enum
{
    PORTD_21_GPIO = 1U,
    PORTD_21_FTU3_CH5 = 2U,
    PORTD_21_FCUART5_TX = 3U,
    PORTD_21_eFTU1_IN7 = 4U,
    PORTD_21_HSADC2_IO2 = 5U,
    PORTD_21_TPU0_CH19 = 6U,
    PORTD_21_eFTU1_OUT_S22 = 7U,
} PORT_D21MuxType;

/** @brief PORTD22 Mode enumeration */
typedef enum
{
    PORTD_22_ADC3_SE18 = 0U,
    PORTD_22_GPIO = 1U,
    PORTD_22_eFTU1_IN4 = 3U,
    PORTD_22_FCSPI5_SCK = 4U,
    PORTD_22_TPU0_CH18 = 5U,
    PORTD_22_eFTU2_OUT_S31 = 6U,
    PORTD_22_eFTU0_OUT_S31 = 7U,
} PORT_D22MuxType;

/** @brief PORTD23 Mode enumeration */
typedef enum
{
    PORTD_23_ADC4_SE21 = 0U,
    PORTD_23_GPIO = 1U,
    PORTD_23_FTU2_CH1 = 2U,
    PORTD_23_TPU0_CH15 = 3U,
    PORTD_23_FCSPI1_PCS0 = 4U,
    PORTD_23_FLEXCAN7_TX = 5U,
    PORTD_23_eFTU1_OUT_S26 = 6U,
    PORTD_23_FLEXCORE_TDI = 7U,
} PORT_D23MuxType;

/** @brief PORTD24 Mode enumeration */
typedef enum
{
    PORTD_24_ADC4_SE22 = 0U,
    PORTD_24_GPIO = 1U,
    PORTD_24_FTU2_CH4 = 2U,
    PORTD_24_TPU0_CH13 = 3U,
    PORTD_24_MSC1_SOP = 4U,
    PORTD_24_eFTU2_OUT_S15 = 5U,
    PORTD_24_eFTU2_IN7 = 6U,
    PORTD_24_FLEXCORE_TRST = 7U,
} PORT_D24MuxType;

/** @brief PORTD25 Mode enumeration */
typedef enum
{
    PORTD_25_ADC3_SE23 = 0U,
    PORTD_25_GPIO = 1U,
    PORTD_25_FTU2_CH6 = 2U,
    PORTD_25_FCUART12_TX = 3U,
    PORTD_25_FCUART4_RTS = 4U,
    PORTD_25_FLEXCAN7_TX = 5U,
    PORTD_25_eFTU2_IN1 = 6U,
    PORTD_25_eFTU_GTOM13 = 7U,
} PORT_D25MuxType;

/** @brief PORTD26 Mode enumeration */
typedef enum
{
    PORTD_26_GPIO = 1U,
    PORTD_26_FTU4_CH0 = 2U,
    PORTD_26_FLEXCAN0_TX = 3U,
    PORTD_26_FCUART4_CTS = 4U,
    PORTD_26_TPU0_TCRCLK = 5U,
    PORTD_26_eFTU0_IN7 = 6U,
    PORTD_26_eFTU_GTOM2 = 7U,
} PORT_D26MuxType;

/** @brief PORTD27 Mode enumeration */
typedef enum
{
    PORTD_27_GPIO = 1U,
    PORTD_27_FTU4_CH1 = 2U,
    PORTD_27_FLEXCAN0_RX = 3U,
    PORTD_27_TPU0_CH8 = 4U,
    PORTD_27_MSC1_EN0 = 5U,
    PORTD_27_eFTU0_IN6 = 6U,
    PORTD_27_eFTU_GTOM1 = 7U,
} PORT_D27MuxType;

/** @brief PORTD28 Mode enumeration */
typedef enum
{
    PORTD_28_GPIO = 1U,
    PORTD_28_FTU4_CH3 = 2U,
    PORTD_28_QDT1_INDEX = 3U,
    PORTD_28_FCUART11_TX = 4U,
    PORTD_28_TPU0_CH7 = 5U,
    PORTD_28_eFTU0_IN5 = 6U,
    PORTD_28_eFTU_GTOM7 = 7U,
} PORT_D28MuxType;

/** @brief PORTD29 Mode enumeration */
typedef enum
{
    PORTD_29_GPIO = 1U,
    PORTD_29_FTU4_CH5 = 2U,
    PORTD_29_FLEXCAN11_TX = 3U,
    PORTD_29_SENT1_RXD1 = 4U,
    PORTD_29_FTU1_QD_PHB = 5U,
    PORTD_29_MSC1_EN1 = 6U,
    PORTD_29_eFTU_GTOM1 = 7U,
} PORT_D29MuxType;

/** @brief PORTD3 Mode enumeration */
typedef enum
{
    PORTD_3_ADC3_SE20 = 0U,
    PORTD_3_GPIO = 1U,
    PORTD_3_FTU3_CH7 = 2U,
    PORTD_3_TPU0_CH17 = 3U,
    PORTD_3_FCSPI1_SIN = 4U,
    PORTD_3_HSADC2_IO0 = 5U,
    PORTD_3_eFTU0_OUT_S29 = 6U,
    PORTD_3_eFTU1_OUT_S24 = 7U,
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
    PORTD_30_eFTU_GTOM0 = 7U,
} PORT_D30MuxType;

/** @brief PORTD31 Mode enumeration */
typedef enum
{
    PORTD_31_GPIO = 1U,
    PORTD_31_FTU6_CH0 = 2U,
    PORTD_31_TPU0_CH2 = 3U,
    PORTD_31_eFTU0_IN2 = 4U,
    PORTD_31_MSC1_SDI3 = 5U,
    PORTD_31_FTU1_QD_PHA = 6U,
    PORTD_31_eFTU1_OUT_S3 = 7U,
} PORT_D31MuxType;

/** @brief PORTD4 Mode enumeration */
typedef enum
{
    PORTD_4_ADC4_SE20 = 0U,
    PORTD_4_GPIO = 1U,
    PORTD_4_FTU3_CH6 = 2U,
    PORTD_4_TPU0_CH18 = 3U,
    PORTD_4_FCSPI1_SOUT = 4U,
    PORTD_4_FTU_FLT16 = 5U,
    PORTD_4_HSADC2_IO1 = 6U,
    PORTD_4_eFTU1_OUT_S23 = 7U,
} PORT_D4MuxType;

/** @brief PORTD5 Mode enumeration */
typedef enum
{
    PORTD_5_GPIO = 1U,
    PORTD_5_FTU6_CH4 = 2U,
    PORTD_5_FLEXCAN3_TX = 3U,
    PORTD_5_ETM_TRACE_D2 = 4U,
    PORTD_5_ENET_TXD3 = 5U,
    PORTD_5_QDT3_INDEX = 6U,
    PORTD_5_FCSPI3_SIN = 7U,
} PORT_D5MuxType;

/** @brief PORTD6 Mode enumeration */
typedef enum
{
    PORTD_6_GPIO = 1U,
    PORTD_6_FCUART2_RX = 2U,
    PORTD_6_FLEXCAN3_RX = 3U,
    PORTD_6_ETM_TRACE_D1 = 4U,
    PORTD_6_ENET_TXD2 = 5U,
    PORTD_6_QDT3_HOME = 6U,
    PORTD_6_FCSPI3_SCK = 7U,
} PORT_D6MuxType;

/** @brief PORTD7 Mode enumeration */
typedef enum
{
    PORTD_7_GPIO = 1U,
    PORTD_7_FCUART2_TX = 2U,
    PORTD_7_HSADC3_IO1 = 3U,
    PORTD_7_ETM_TRACE_D0 = 4U,
    PORTD_7_ENET_TXD1 = 5U,
    PORTD_7_eFTU2_IN7 = 6U,
    PORTD_7_eFTU0_OUT_S7 = 7U,
} PORT_D7MuxType;

/** @brief PORTD8 Mode enumeration */
typedef enum
{
    PORTD_8_GPIO = 1U,
    PORTD_8_FTU7_CH0 = 2U,
    PORTD_8_FCSPI2_PCS2 = 3U,
    PORTD_8_FTU1_CH6 = 4U,
    PORTD_8_ENET_RX_DV_CTL = 5U,
    PORTD_8_eFTU0_OUT_S13 = 6U,
    PORTD_8_FCUART4_RX = 7U,
} PORT_D8MuxType;

/** @brief PORTD9 Mode enumeration */
typedef enum
{
    PORTD_9_GPIO = 1U,
    PORTD_9_eFTU0_IN7 = 2U,
    PORTD_9_FCSPI2_PCS1 = 3U,
    PORTD_9_TPU0_CH19 = 4U,
    PORTD_9_ENET_RXD2 = 5U,
    PORTD_9_QDT3_PHB = 6U,
    PORTD_9_FCUART4_TX = 7U,
} PORT_D9MuxType;

/** @brief PORTE0 Mode enumeration */
typedef enum
{
    PORTE_0_HSADC3_CH2 = 0U,
    PORTE_0_GPIO = 1U,
    PORTE_0_FCUART0_CTS = 2U,
    PORTE_0_FTU_TCK1 = 3U,
    PORTE_0_FCIIC1_SDA = 4U,
    PORTE_0_FCSPI0_SCK = 5U,
    PORTE_0_FTU_FLT19 = 6U,
    PORTE_0_eFTU0_OUT_S12 = 7U,
} PORT_E0MuxType;

/** @brief PORTE1 Mode enumeration */
typedef enum
{
    PORTE_1_HSADC3_CH3 = 0U,
    PORTE_1_GPIO = 1U,
    PORTE_1_FCUART0_RTS = 2U,
    PORTE_1_LP_GOOD = 3U,
    PORTE_1_FCIIC1_SCL = 4U,
    PORTE_1_FCSPI0_SIN = 5U,
    PORTE_1_FTU_FLT18 = 6U,
    PORTE_1_eFTU0_OUT_S11 = 7U,
} PORT_E1MuxType;

/** @brief PORTE10 Mode enumeration */
typedef enum
{
    PORTE_10_ADC0_SE3_ADC0_DIFF_P3 = 0U,
    PORTE_10_GPIO = 1U,
    PORTE_10_SCG_CLKOUT = 2U,
    PORTE_10_FTU6_CH0 = 3U,
    PORTE_10_HRPWM0_CH4 = 4U,
    PORTE_10_FCSPI2_SIN = 5U,
    PORTE_10_eFTU1_OUT_S6 = 6U,
    PORTE_10_TRGSEL_OUT4 = 7U,
} PORT_E10MuxType;

/** @brief PORTE11 Mode enumeration */
typedef enum
{
    PORTE_11_ADC1_SE6_ADC1_DIFF_N2 = 0U,
    PORTE_11_GPIO = 1U,
    PORTE_11_FTU2_CH1 = 2U,
    PORTE_11_TPU0_CH20 = 3U,
    PORTE_11_HRPWM0_CH3 = 4U,
    PORTE_11_FCSPI2_PCS0 = 5U,
    PORTE_11_eFTU1_OUT_S5 = 6U,
    PORTE_11_TRGSEL_OUT5 = 7U,
} PORT_E11MuxType;

/** @brief PORTE12 Mode enumeration */
typedef enum
{
    PORTE_12_ADC0_SE10 = 0U,
    PORTE_12_GPIO = 1U,
    PORTE_12_FTU5_CH6 = 2U,
    PORTE_12_FTU_FLT2 = 3U,
    PORTE_12_ETM_TRACE_D3 = 4U,
    PORTE_12_FCSPI1_SOUT = 5U,
    PORTE_12_TPU0_CH14 = 6U,
    PORTE_12_eFTU2_OUT_S17 = 7U,
} PORT_E12MuxType;

/** @brief PORTE13 Mode enumeration */
typedef enum
{
    PORTE_13_ADC0_SE7_ADC0_DIFF_N3 = 0U,
    PORTE_13_GPIO = 1U,
    PORTE_13_FTU2_CH0 = 2U,
    PORTE_13_TPU0_CH21 = 3U,
    PORTE_13_HRPWM0_CH5 = 4U,
    PORTE_13_FCSPI2_SCK = 5U,
    PORTE_13_eFTU1_OUT_S7 = 6U,
    PORTE_13_HSADC1_BFL = 7U,
} PORT_E13MuxType;

/** @brief PORTE14 Mode enumeration */
typedef enum
{
    PORTE_14_OSC32K_XTAL = 0U,
    PORTE_14_GPIO = 1U,
    PORTE_14_FTU0_CH3 = 2U,
    PORTE_14_eFTU0_IN1 = 3U,
    PORTE_14_FTU_FLT0 = 4U,
    PORTE_14_FLEXCAN10_RX = 6U,
} PORT_E14MuxType;

/** @brief PORTE15 Mode enumeration */
typedef enum
{
    PORTE_15_HSADC1_CH3 = 0U,
    PORTE_15_GPIO = 1U,
    PORTE_15_FCUART1_CTS = 2U,
    PORTE_15_FLEXCAN5_RX = 3U,
    PORTE_15_FTU2_CH6 = 4U,
    PORTE_15_eFTU2_OUT_S7 = 5U,
    PORTE_15_eFTU_GTOM9 = 6U,
    PORTE_15_TRGSEL_OUT6 = 7U,
} PORT_E15MuxType;

/** @brief PORTE16 Mode enumeration */
typedef enum
{
    PORTE_16_HSADC1_CH1 = 0U,
    PORTE_16_GPIO = 1U,
    PORTE_16_FCUART1_RTS = 2U,
    PORTE_16_FLEXCAN5_TX = 3U,
    PORTE_16_FTU2_CH7 = 4U,
    PORTE_16_eFTU_GTOM11 = 5U,
    PORTE_16_TRGSEL_OUT7 = 7U,
} PORT_E16MuxType;

/** @brief PORTE17 Mode enumeration */
typedef enum
{
    PORTE_17_GPIO = 1U,
    PORTE_17_FTU6_CH1 = 2U,
    PORTE_17_FCSMU_PIN1 = 3U,
    PORTE_17_eFTU1_IN0 = 4U,
    PORTE_17_eFTU2_OUT_S4 = 5U,
    PORTE_17_HSADC0_IO2 = 6U,
} PORT_E17MuxType;

/** @brief PORTE18 Mode enumeration */
typedef enum
{
    PORTE_18_ADC2_SE18 = 0U,
    PORTE_18_GPIO = 1U,
    PORTE_18_FTU6_CH3 = 2U,
    PORTE_18_QDT1_PHA = 3U,
    PORTE_18_FCUART10_RX = 4U,
    PORTE_18_eFTU2_OUT_S8 = 5U,
    PORTE_18_FLEXCAN6_TX = 6U,
    PORTE_18_eFTU1_OUT_S12 = 7U,
} PORT_E18MuxType;

/** @brief PORTE19 Mode enumeration */
typedef enum
{
    PORTE_19_ADC2_SE9 = 0U,
    PORTE_19_GPIO = 1U,
    PORTE_19_SCG_CLKOUT = 2U,
    PORTE_19_FCIIC0_SCL = 3U,
    PORTE_19_SENT0_RXD2 = 4U,
    PORTE_19_CMP0_OUT = 5U,
    PORTE_19_eFTU1_IN2 = 6U,
    PORTE_19_eFTU0_OUT_S0 = 7U,
} PORT_E19MuxType;

/** @brief PORTE2 Mode enumeration */
typedef enum
{
    PORTE_2_ADC2_SE11 = 0U,
    PORTE_2_GPIO = 1U,
    PORTE_2_FTU6_CH6 = 2U,
    PORTE_2_SDADC0_EXT_SIGN = 3U,
    PORTE_2_eFTU1_IN1 = 4U,
    PORTE_2_FLEXCAN1_RX = 5U,
    PORTE_2_FCUART1_CTS = 6U,
    PORTE_2_eFTU1_OUT_S14 = 7U,
} PORT_E2MuxType;

/** @brief PORTE20 Mode enumeration */
typedef enum
{
    PORTE_20_ADC2_SE8 = 0U,
    PORTE_20_GPIO = 1U,
    PORTE_20_FTU0_CH0 = 2U,
    PORTE_20_FCIIC0_SDA = 3U,
    PORTE_20_SENT0_RXD3 = 4U,
    PORTE_20_eFTU2_OUT_S14 = 5U,
    PORTE_20_LP_GOOD = 6U,
    PORTE_20_eFTU0_OUT_S1 = 7U,
} PORT_E20MuxType;

/** @brief PORTE21 Mode enumeration */
typedef enum
{
    PORTE_21_GPIO = 1U,
    PORTE_21_FTU0_CH1 = 2U,
    PORTE_21_LP_WAKEUP0 = 3U,
    PORTE_21_FLEXCAN0_TX = 4U,
    PORTE_21_FCUART0_RTS = 5U,
    PORTE_21_eFTU1_IN4 = 6U,
    PORTE_21_eFTU0_OUT_S3 = 7U,
} PORT_E21MuxType;

/** @brief PORTE22 Mode enumeration */
typedef enum
{
    PORTE_22_GPIO = 1U,
    PORTE_22_FTU0_CH2 = 2U,
    PORTE_22_LP_GOOD = 3U,
    PORTE_22_FLEXCAN0_RX = 4U,
    PORTE_22_FCUART0_CTS = 5U,
    PORTE_22_eFTU1_IN5 = 6U,
    PORTE_22_eFTU0_OUT_S4 = 7U,
} PORT_E22MuxType;

/** @brief PORTE23 Mode enumeration */
typedef enum
{
    PORTE_23_ADC2_SE7_ADC2_DIFF_N3 = 0U,
    PORTE_23_GPIO = 1U,
    PORTE_23_FTU0_CH4 = 2U,
    PORTE_23_FLEXCAN1_RX = 3U,
    PORTE_23_eFTU2_IN1 = 4U,
    PORTE_23_FCSPI0_PCS2 = 5U,
    PORTE_23_eFTU0_OUT_S8 = 7U,
} PORT_E23MuxType;

/** @brief PORTE24 Mode enumeration */
typedef enum
{
    PORTE_24_ADC2_SE3_ADC2_DIFF_P3 = 0U,
    PORTE_24_GPIO = 1U,
    PORTE_24_FTU0_CH5 = 2U,
    PORTE_24_FLEXCAN1_TX = 3U,
    PORTE_24_eFTU2_IN6 = 4U,
    PORTE_24_FCSPI0_PCS1 = 5U,
    PORTE_24_LP_WAKEUP1 = 6U,
    PORTE_24_eFTU0_OUT_S9 = 7U,
} PORT_E24MuxType;

/** @brief PORTE25 Mode enumeration */
typedef enum
{
    PORTE_25_HSADC2_CH5 = 0U,
    PORTE_25_GPIO = 1U,
    PORTE_25_FTU0_CH6 = 2U,
    PORTE_25_AONTIMER0_CLK0 = 3U,
    PORTE_25_FCSPI0_PCS0 = 5U,
    PORTE_25_eFTU0_OUT_S10 = 6U,
    PORTE_25_TRGSEL_OUT7 = 7U,
} PORT_E25MuxType;

/** @brief PORTE26 Mode enumeration */
typedef enum
{
    PORTE_26_HSADC2_CH1 = 0U,
    PORTE_26_GPIO = 1U,
    PORTE_26_FTU3_CH2 = 2U,
    PORTE_26_AONTIMER0_CLK2 = 3U,
    PORTE_26_SENT0_RXD0 = 4U,
    PORTE_26_LP_WAKEUP3 = 5U,
    PORTE_26_eFTU0_OUT_S12 = 7U,
} PORT_E26MuxType;

/** @brief PORTE27 Mode enumeration */
typedef enum
{
    PORTE_27_HSADC2_CH0 = 0U,
    PORTE_27_GPIO = 1U,
    PORTE_27_FTU3_CH5 = 2U,
    PORTE_27_SENT0_RXD1 = 4U,
    PORTE_27_eFTU2_IN3 = 5U,
    PORTE_27_eFTU2_OUT_S31 = 6U,
} PORT_E27MuxType;

/** @brief PORTE3 Mode enumeration */
typedef enum
{
    PORTE_3_OSC32K_EXTAL = 0U,
    PORTE_3_GPIO = 1U,
    PORTE_3_FTU0_CH2 = 2U,
    PORTE_3_eFTU0_IN0 = 3U,
    PORTE_3_FTU_FLT1 = 4U,
    PORTE_3_FTU_TCK0 = 6U,
} PORT_E3MuxType;

/** @brief PORTE4 Mode enumeration */
typedef enum
{
    PORTE_4_ADC0_SE5_ADC0_DIFF_N1 = 0U,
    PORTE_4_GPIO = 1U,
    PORTE_4_FTU2_QD_PHB = 2U,
    PORTE_4_eFTU2_IN7 = 3U,
    PORTE_4_FCUART7_TX = 4U,
    PORTE_4_eFTU2_OUT_S14 = 5U,
    PORTE_4_FLEXCAN9_RX = 6U,
    PORTE_4_eFTU_GTOM11 = 7U,
} PORT_E4MuxType;

/** @brief PORTE5 Mode enumeration */
typedef enum
{
    PORTE_5_ADC1_SE7_ADC1_DIFF_N3 = 0U,
    PORTE_5_GPIO = 1U,
    PORTE_5_FTU_TCK2 = 2U,
    PORTE_5_FTU4_CH3 = 3U,
    PORTE_5_HRPWM0_CH7 = 4U,
    PORTE_5_FCSPI2_PCS1 = 5U,
    PORTE_5_FLEXCAN13_TX = 6U,
    PORTE_5_eFTU1_OUT_S9 = 7U,
} PORT_E5MuxType;

/** @brief PORTE6 Mode enumeration */
typedef enum
{
    PORTE_6_ADC2_SE12 = 0U,
    PORTE_6_GPIO = 1U,
    PORTE_6_FTU6_CH5 = 2U,
    PORTE_6_TPU0_TCRCLK = 3U,
    PORTE_6_eFTU1_IN0 = 4U,
    PORTE_6_FLEXCAN1_TX = 5U,
    PORTE_6_FCUART1_RTS = 6U,
    PORTE_6_eFTU1_OUT_S13 = 7U,
} PORT_E6MuxType;

/** @brief PORTE7 Mode enumeration */
typedef enum
{
    PORTE_7_ADC3_SE13 = 0U,
    PORTE_7_GPIO = 1U,
    PORTE_7_FTU5_CH2 = 2U,
    PORTE_7_FTU_FLT14 = 3U,
    PORTE_7_eFTU0_OUT_S23 = 4U,
    PORTE_7_TPU0_CH30 = 5U,
    PORTE_7_eFTU1_OUT_S31 = 6U,
    PORTE_7_FCSPI7_SOUT = 7U,
} PORT_E7MuxType;

/** @brief PORTE8 Mode enumeration */
typedef enum
{
    PORTE_8_GPIO = 1U,
    PORTE_8_FTU6_CH1 = 2U,
    PORTE_8_HSADC0_IO2 = 3U,
    PORTE_8_FCUART9_TX = 4U,
    PORTE_8_ENET_MDC = 5U,
    PORTE_8_eFTU2_IN0 = 6U,
    PORTE_8_eFTU0_OUT_S0 = 7U,
} PORT_E8MuxType;

/** @brief PORTE9 Mode enumeration */
typedef enum
{
    PORTE_9_ADC1_SE16_CMP0_IN7 = 0U,
    PORTE_9_GPIO = 1U,
    PORTE_9_FTU0_CH7 = 2U,
    PORTE_9_TPU0_CH8 = 3U,
    PORTE_9_ETM_TRACE_CLKOUT = 4U,
    PORTE_9_ENET_PPS3 = 5U,
    PORTE_9_FCUART2_CTS = 6U,
    PORTE_9_QDT1_INDEX = 7U,
} PORT_E9MuxType;

/** @brief PORTF11 Mode enumeration */
typedef enum
{
    PORTF_11_SDADC_CH_P1_ADC5_SE2_ADC5_DIFF_P2 = 0U,
    PORTF_11_GPIO = 1U,
    PORTF_11_FLEXCAN6_TX = 2U,
    PORTF_11_FTU0_CH5 = 3U,
    PORTF_11_MSC0_SDI2 = 4U,
    PORTF_11_SDADC0_CH0 = 5U,
    PORTF_11_eFTU2_OUT_S8 = 6U,
    PORTF_11_eFTU0_OUT_S30 = 7U,
} PORT_F11MuxType;

/** @brief PORTF12 Mode enumeration */
typedef enum
{
    PORTF_12_ADC5_SE7_ADC5_DIFF_N3 = 0U,
    PORTF_12_GPIO = 1U,
    PORTF_12_SDADC0_PWM_P = 2U,
    PORTF_12_eFTU0_OUT_S30 = 3U,
    PORTF_12_QDT3_PHA = 5U,
    PORTF_12_TPU0_CH30 = 6U,
    PORTF_12_eFTU1_OUT_S28 = 7U,
} PORT_F12MuxType;

/** @brief PORTF13 Mode enumeration */
typedef enum
{
    PORTF_13_SDADC1_CH2_P0 = 0U,
    PORTF_13_GPIO = 1U,
    PORTF_13_SDADC1_BREAK2 = 2U,
    PORTF_13_eFTU0_OUT_S29 = 3U,
    PORTF_13_FCSPI2_PCS2 = 4U,
    PORTF_13_QDT3_INDEX = 5U,
    PORTF_13_TPU0_CH29 = 6U,
    PORTF_13_eFTU1_OUT_S27 = 7U,
} PORT_F13MuxType;

/** @brief PORTF14 Mode enumeration */
typedef enum
{
    PORTF_14_SDADC1_CH2_N0 = 0U,
    PORTF_14_GPIO = 1U,
    PORTF_14_TPU0_CH31 = 2U,
    PORTF_14_FLEXCAN9_TX = 3U,
    PORTF_14_FCSPI2_PCS3 = 4U,
    PORTF_14_QDT3_PHB = 5U,
    PORTF_14_FCUART5_TX = 6U,
    PORTF_14_eFTU1_OUT_S29 = 7U,
} PORT_F14MuxType;

/** @brief PORTF15 Mode enumeration */
typedef enum
{
    PORTF_15_ADC3_SE14 = 0U,
    PORTF_15_GPIO = 1U,
    PORTF_15_TPU0_CH28 = 2U,
    PORTF_15_eFTU1_IN6 = 3U,
    PORTF_15_eFTU2_OUT_S24 = 6U,
    PORTF_15_FCSPI7_PCS2 = 7U,
} PORT_F15MuxType;

/** @brief PORTF16 Mode enumeration */
typedef enum
{
    PORTF_16_ADC5_SE19 = 0U,
    PORTF_16_GPIO = 1U,
    PORTF_16_eFTU1_IN5 = 3U,
    PORTF_16_FCSPI5_SIN = 4U,
    PORTF_16_eFTU2_OUT_S11 = 5U,
    PORTF_16_TPU0_CH23 = 6U,
    PORTF_16_eFTU1_OUT_S29 = 7U,
} PORT_F16MuxType;

/** @brief PORTF17 Mode enumeration */
typedef enum
{
    PORTF_17_ADC4_SE19 = 0U,
    PORTF_17_GPIO = 1U,
    PORTF_17_FTU_FLT21 = 2U,
    PORTF_17_eFTU1_IN6 = 3U,
    PORTF_17_FCSPI5_SOUT = 4U,
    PORTF_17_eFTU2_OUT_S12 = 5U,
    PORTF_17_TPU0_CH22 = 6U,
    PORTF_17_eFTU1_OUT_S30 = 7U,
} PORT_F17MuxType;

/** @brief PORTF2 Mode enumeration */
typedef enum
{
    PORTF_2_ADC3_SE22 = 0U,
    PORTF_2_GPIO = 1U,
    PORTF_2_FCUART6_RTS = 2U,
    PORTF_2_eFTU0_IN0 = 3U,
    PORTF_2_FCUART8_RX = 4U,
    PORTF_2_FLEXCAN12_TX = 5U,
    PORTF_2_HSADC2_IO0 = 6U,
    PORTF_2_eFTU1_OUT_S27 = 7U,
} PORT_F2MuxType;

/** @brief PORTF20 Mode enumeration */
typedef enum
{
    PORTF_20_GPIO = 1U,
    PORTF_20_FCSPI4_PCS1 = 2U,
    PORTF_20_FTU6_CH2 = 3U,
    PORTF_20_FLEXCAN2_RX = 4U,
    PORTF_20_MSC1_EN3 = 5U,
    PORTF_20_eFTU0_IN1 = 6U,
    PORTF_20_eFTU1_OUT_S2 = 7U,
} PORT_F20MuxType;

/** @brief PORTF23 Mode enumeration */
typedef enum
{
    PORTF_23_ADC2_SE6_ADC2_DIFF_N2 = 0U,
    PORTF_23_GPIO = 1U,
    PORTF_23_SENT0_RXD0 = 2U,
    PORTF_23_FCUART0_TX = 3U,
    PORTF_23_FCSPI0_SOUT = 4U,
    PORTF_23_LP_WAKEUP4 = 5U,
    PORTF_23_eFTU2_OUT_S28 = 6U,
} PORT_F23MuxType;

/** @brief PORTF24 Mode enumeration */
typedef enum
{
    PORTF_24_ADC1_SE1_ADC1_DIFF_P1 = 0U,
    PORTF_24_GPIO = 1U,
    PORTF_24_FTU4_CH6 = 2U,
    PORTF_24_QDT0_HOME = 3U,
    PORTF_24_HRPWM0_CH0 = 4U,
    PORTF_24_FCSPI2_PCS3 = 5U,
    PORTF_24_HSADC0_BFL = 6U,
    PORTF_24_eFTU1_OUT_S2 = 7U,
} PORT_F24MuxType;

/** @brief PORTF3 Mode enumeration */
typedef enum
{
    PORTF_3_ADC0_SE1_ADC0_DIFF_P1 = 0U,
    PORTF_3_GPIO = 1U,
    PORTF_3_FCUART8_RTS = 2U,
    PORTF_3_eFTU2_IN4 = 3U,
    PORTF_3_FCSPI6_SIN = 4U,
    PORTF_3_eFTU2_OUT_S11 = 5U,
} PORT_F3MuxType;

/** @brief PORTF4 Mode enumeration */
typedef enum
{
    PORTF_4_HSADC1_CH4 = 0U,
    PORTF_4_GPIO = 1U,
    PORTF_4_FCUART8_CTS = 2U,
    PORTF_4_eFTU2_IN5 = 3U,
    PORTF_4_FCSPI6_SCK = 4U,
    PORTF_4_eFTU2_OUT_S12 = 5U,
} PORT_F4MuxType;

/** @brief PORTF5 Mode enumeration */
typedef enum
{
    PORTF_5_HSADC1_CH5 = 0U,
    PORTF_5_GPIO = 1U,
    PORTF_5_eFTU2_IN6 = 3U,
    PORTF_5_FCSPI6_SOUT = 4U,
    PORTF_5_eFTU2_OUT_S13 = 5U,
} PORT_F5MuxType;

/** @brief PORTF7 Mode enumeration */
typedef enum
{
    PORTF_7_SDADC1_CH0_N0 = 0U,
    PORTF_7_GPIO = 1U,
    PORTF_7_SDADC1_CLK0 = 2U,
    PORTF_7_FTU6_CH5 = 3U,
    PORTF_7_FTU1_QD_PHA = 5U,
    PORTF_7_eFTU1_OUT_S22 = 6U,
    PORTF_7_eFTU2_OUT_S0 = 7U,
} PORT_F7MuxType;

/** @brief PORTF9 Mode enumeration */
typedef enum
{
    PORTF_9_ADC4_SE1_ADC4_DIFF_P1 = 0U,
    PORTF_9_GPIO = 1U,
    PORTF_9_FCUART13_RTS = 2U,
    PORTF_9_FTU0_CH3 = 3U,
    PORTF_9_MSC0_SDI0 = 4U,
    PORTF_9_FLEXCAN9_RX = 5U,
    PORTF_9_eFTU2_OUT_S5 = 6U,
    PORTF_9_TPU0_CH29 = 7U,
} PORT_F9MuxType;

/** @brief PORTG0 Mode enumeration */
typedef enum
{
    PORTG_0_ADC5_SE23 = 0U,
    PORTG_0_GPIO = 1U,
    PORTG_0_FCUART6_CTS = 2U,
    PORTG_0_eFTU0_IN1 = 3U,
    PORTG_0_FCUART8_TX = 4U,
    PORTG_0_FLEXCAN12_RX = 5U,
    PORTG_0_HSADC2_IO1 = 6U,
    PORTG_0_eFTU1_OUT_S28 = 7U,
} PORT_G0MuxType;

/** @brief PORTG1 Mode enumeration */
typedef enum
{
    PORTG_1_ADC0_SE0_ADC0_DIFF_P0 = 0U,
    PORTG_1_GPIO = 1U,
    PORTG_1_eFTU2_IN0 = 3U,
    PORTG_1_FLEXCAN5_TX = 4U,
    PORTG_1_eFTU2_OUT_S4 = 5U,
} PORT_G1MuxType;

/** @brief PORTG10 Mode enumeration */
typedef enum
{
    PORTG_10_SDADC0_CH2_P0 = 0U,
    PORTG_10_GPIO = 1U,
    PORTG_10_SDADC0_BREAK2 = 2U,
    PORTG_10_FTU0_CH7 = 3U,
    PORTG_10_FTU2_QD_PHA = 5U,
    PORTG_10_eFTU2_OUT_S10 = 6U,
} PORT_G10MuxType;

/** @brief PORTG11 Mode enumeration */
typedef enum
{
    PORTG_11_SDADC0_CH2_N0 = 0U,
    PORTG_11_GPIO = 1U,
    PORTG_11_eFTU0_OUT_S24 = 3U,
    PORTG_11_eFTU1_OUT_S20 = 4U,
    PORTG_11_FTU2_QD_PHB = 5U,
    PORTG_11_TPU0_CH27 = 6U,
} PORT_G11MuxType;

/** @brief PORTG13 Mode enumeration */
typedef enum
{
    PORTG_13_ADC4_SE10 = 0U,
    PORTG_13_GPIO = 1U,
    PORTG_13_TPU0_CH7 = 2U,
    PORTG_13_eFTU1_IN4 = 3U,
    PORTG_13_FLEXCAN4_TX = 4U,
    PORTG_13_SDADC0_PWM_P = 5U,
    PORTG_13_QDT0_HOME = 6U,
    PORTG_13_eFTU2_OUT_S16 = 7U,
} PORT_G13MuxType;

/** @brief PORTG14 Mode enumeration */
typedef enum
{
    PORTG_14_ADC3_SE10 = 0U,
    PORTG_14_GPIO = 1U,
    PORTG_14_TPU0_CH8 = 2U,
    PORTG_14_eFTU1_IN5 = 3U,
    PORTG_14_FLEXCAN4_RX = 4U,
    PORTG_14_SDADC0_PWM_N = 5U,
    PORTG_14_QDT0_INDEX = 6U,
    PORTG_14_eFTU2_OUT_S17 = 7U,
} PORT_G14MuxType;

/** @brief PORTG15 Mode enumeration */
typedef enum
{
    PORTG_15_GPIO = 1U,
    PORTG_15_FLEXCAN10_TX = 2U,
    PORTG_15_FCIIC0_SCL = 3U,
    PORTG_15_MSC1_EN0 = 4U,
    PORTG_15_TRGSEL_OUT2 = 5U,
    PORTG_15_eFTU2_IN3 = 6U,
    PORTG_15_eFTU_GTOM6 = 7U,
} PORT_G15MuxType;

/** @brief PORTG16 Mode enumeration */
typedef enum
{
    PORTG_16_GPIO = 1U,
    PORTG_16_FLEXCAN10_RX = 2U,
    PORTG_16_FCIIC0_SDA = 3U,
    PORTG_16_MSC1_SDI0 = 4U,
    PORTG_16_TRGSEL_OUT3 = 5U,
    PORTG_16_eFTU2_IN4 = 6U,
    PORTG_16_eFTU_GTOM5 = 7U,
} PORT_G16MuxType;

/** @brief PORTG17 Mode enumeration */
typedef enum
{
    PORTG_17_GPIO = 1U,
    PORTG_17_TPU0_CH10 = 2U,
    PORTG_17_FLEXCAN7_TX = 3U,
    PORTG_17_MSC1_EN1 = 4U,
    PORTG_17_QDT1_PHA = 5U,
    PORTG_17_eFTU2_IN5 = 6U,
    PORTG_17_eFTU_GTOM4 = 7U,
} PORT_G17MuxType;

/** @brief PORTG18 Mode enumeration */
typedef enum
{
    PORTG_18_GPIO = 1U,
    PORTG_18_FCSPI4_PCS0 = 2U,
    PORTG_18_FTU1_CH0 = 3U,
    PORTG_18_FCUART10_RX = 4U,
    PORTG_18_FLEXCAN7_RX = 5U,
    PORTG_18_SENT1_RXD0 = 6U,
    PORTG_18_eFTU1_OUT_S6 = 7U,
} PORT_G18MuxType;

/** @brief PORTG19 Mode enumeration */
typedef enum
{
    PORTG_19_ADC2_SE23 = 0U,
    PORTG_19_GPIO = 1U,
    PORTG_19_FCSPI4_SCK = 2U,
    PORTG_19_FTU1_CH1 = 3U,
    PORTG_19_FCUART10_TX = 4U,
    PORTG_19_FLEXCAN7_TX = 5U,
    PORTG_19_SENT1_RXD1 = 6U,
    PORTG_19_eFTU1_OUT_S7 = 7U,
} PORT_G19MuxType;

/** @brief PORTG2 Mode enumeration */
typedef enum
{
    PORTG_2_ADC0_SE4_ADC0_DIFF_N0 = 0U,
    PORTG_2_GPIO = 1U,
    PORTG_2_eFTU2_IN1 = 3U,
    PORTG_2_FLEXCAN5_RX = 4U,
    PORTG_2_eFTU2_OUT_S5 = 5U,
} PORT_G2MuxType;

/** @brief PORTG20 Mode enumeration */
typedef enum
{
    PORTG_20_ADC2_SE22 = 0U,
    PORTG_20_GPIO = 1U,
    PORTG_20_FCSPI4_SIN = 2U,
    PORTG_20_FTU1_CH2 = 3U,
    PORTG_20_FCUART10_CTS = 4U,
    PORTG_20_FLEXCAN3_TX = 5U,
    PORTG_20_SENT1_RXD2 = 6U,
    PORTG_20_eFTU1_OUT_S8 = 7U,
} PORT_G20MuxType;

/** @brief PORTG21 Mode enumeration */
typedef enum
{
    PORTG_21_ADC2_SE2_ADC2_DIFF_P2 = 0U,
    PORTG_21_GPIO = 1U,
    PORTG_21_SENT0_RXD1 = 2U,
    PORTG_21_FCUART0_RX = 3U,
    PORTG_21_FCSPI0_PCS0 = 4U,
    PORTG_21_eFTU2_OUT_S29 = 6U,
} PORT_G21MuxType;

/** @brief PORTG22 Mode enumeration */
typedef enum
{
    PORTG_22_ADC2_SE5_ADC2_DIFF_N1 = 0U,
    PORTG_22_GPIO = 1U,
    PORTG_22_SENT0_RXD2 = 2U,
    PORTG_22_FTU1_QD_PHA = 3U,
    PORTG_22_FCSPI0_SIN = 4U,
    PORTG_22_eFTU2_OUT_S27 = 5U,
    PORTG_22_eFTU2_OUT_S0 = 6U,
} PORT_G22MuxType;

/** @brief PORTG23 Mode enumeration */
typedef enum
{
    PORTG_23_ADC2_SE1_ADC2_DIFF_P1 = 0U,
    PORTG_23_GPIO = 1U,
    PORTG_23_SENT0_RXD3 = 2U,
    PORTG_23_FTU1_QD_PHB = 3U,
    PORTG_23_FCSPI0_SCK = 4U,
    PORTG_23_eFTU2_OUT_S26 = 5U,
    PORTG_23_eFTU2_OUT_S1 = 6U,
} PORT_G23MuxType;

/** @brief PORTG3 Mode enumeration */
typedef enum
{
    PORTG_3_ADC1_SE11 = 0U,
    PORTG_3_GPIO = 1U,
    PORTG_3_FCUART9_RX = 2U,
    PORTG_3_eFTU1_IN3 = 3U,
    PORTG_3_eFTU_GTOM14 = 4U,
    PORTG_3_ETM_TRACE_D8 = 5U,
    PORTG_3_TPU0_CH17 = 6U,
    PORTG_3_eFTU2_OUT_S20 = 7U,
} PORT_G3MuxType;

/** @brief PORTG4 Mode enumeration */
typedef enum
{
    PORTG_4_ADC0_SE12_CMP0_IN2 = 0U,
    PORTG_4_GPIO = 1U,
    PORTG_4_FCUART9_TX = 2U,
    PORTG_4_eFTU1_IN2 = 3U,
    PORTG_4_eFTU_GTOM15 = 4U,
    PORTG_4_ETM_TRACE_D9 = 5U,
    PORTG_4_TPU0_CH18 = 6U,
    PORTG_4_eFTU2_OUT_S21 = 7U,
} PORT_G4MuxType;

/** @brief PORTG5 Mode enumeration */
typedef enum
{
    PORTG_5_ADC1_SE12 = 0U,
    PORTG_5_GPIO = 1U,
    PORTG_5_FCUART9_RTS = 2U,
    PORTG_5_eFTU1_IN1 = 3U,
    PORTG_5_SSI0_DIG_14_CH0 = 4U,
    PORTG_5_ETM_TRACE_D10 = 5U,
    PORTG_5_QDT0_HOME = 6U,
    PORTG_5_eFTU2_OUT_S22 = 7U,
} PORT_G5MuxType;

/** @brief PORTG8 Mode enumeration */
typedef enum
{
    PORTG_8_GPIO = 1U,
    PORTG_8_FCUART12_CTS = 2U,
    PORTG_8_eFTU0_IN0 = 3U,
    PORTG_8_FCUART3_TX = 4U,
    PORTG_8_ENET_REF_CLK = 5U,
    PORTG_8_TPU0_CH14 = 6U,
    PORTG_8_FLEXCAN6_TX = 7U,
} PORT_G8MuxType;

/** @brief PORTG9 Mode enumeration */
typedef enum
{
    PORTG_9_SDADC_CH_N1_ADC4_SE2_ADC4_DIFF_P2 = 0U,
    PORTG_9_GPIO = 1U,
    PORTG_9_FLEXCAN6_RX = 2U,
    PORTG_9_FTU0_CH6 = 3U,
    PORTG_9_MSC0_SDI3 = 4U,
    PORTG_9_SDADC0_CH1 = 5U,
    PORTG_9_eFTU2_OUT_S9 = 6U,
    PORTG_9_eFTU0_OUT_S31 = 7U,
} PORT_G9MuxType;

/** @brief PORTH10 Mode enumeration */
typedef enum
{
    PORTH_10_SDADC1_CH1_P0 = 0U,
    PORTH_10_GPIO = 1U,
    PORTH_10_SDADC1_BREAK1 = 2U,
    PORTH_10_eFTU2_IN2 = 3U,
    PORTH_10_eFTU1_OUT_S24 = 5U,
    PORTH_10_FLEXCAN13_RX = 6U,
    PORTH_10_eFTU2_OUT_S2 = 7U,
} PORT_H10MuxType;

/** @brief PORTH11 Mode enumeration */
typedef enum
{
    PORTH_11_ADC5_SE9 = 0U,
    PORTH_11_GPIO = 1U,
    PORTH_11_FLEXCAN10_TX = 2U,
    PORTH_11_eFTU1_IN0 = 3U,
    PORTH_11_TPU0_TCRCLK = 4U,
    PORTH_11_FCSPI7_SIN = 5U,
    PORTH_11_MSC0_FCLP = 6U,
    PORTH_11_TPU0_CH0 = 7U,
} PORT_H11MuxType;

/** @brief PORTH15 Mode enumeration */
typedef enum
{
    PORTH_15_GPIO = 1U,
    PORTH_15_TPU0_CH9 = 2U,
    PORTH_15_FLEXCAN7_RX = 3U,
    PORTH_15_MSC1_SDI1 = 4U,
    PORTH_15_QDT1_PHB = 5U,
    PORTH_15_eFTU2_IN6 = 6U,
    PORTH_15_eFTU_GTOM3 = 7U,
} PORT_H15MuxType;

/** @brief PORTH16 Mode enumeration */
typedef enum
{
    PORTH_16_GPIO = 1U,
    PORTH_16_FCSPI5_PCS0 = 2U,
    PORTH_16_eFTU0_IN2 = 3U,
    PORTH_16_MSC1_FCLP = 4U,
    PORTH_16_TPU0_CH6 = 5U,
    PORTH_16_QDT3_HOME = 6U,
    PORTH_16_eFTU_GTOM6 = 7U,
} PORT_H16MuxType;

/** @brief PORTH17 Mode enumeration */
typedef enum
{
    PORTH_17_GPIO = 1U,
    PORTH_17_FCSPI5_SCK = 2U,
    PORTH_17_eFTU0_IN3 = 3U,
    PORTH_17_MSC1_SOP = 4U,
    PORTH_17_TPU0_CH5 = 5U,
    PORTH_17_QDT3_INDEX = 6U,
    PORTH_17_eFTU_GTOM5 = 7U,
} PORT_H17MuxType;

/** @brief PORTH18 Mode enumeration */
typedef enum
{
    PORTH_18_ADC2_SE21 = 0U,
    PORTH_18_GPIO = 1U,
    PORTH_18_FCSPI4_SOUT = 2U,
    PORTH_18_FTU1_CH3 = 3U,
    PORTH_18_FCUART10_RTS = 4U,
    PORTH_18_FLEXCAN3_RX = 5U,
    PORTH_18_SENT1_RXD3 = 6U,
    PORTH_18_eFTU1_OUT_S9 = 7U,
} PORT_H18MuxType;

/** @brief PORTH19 Mode enumeration */
typedef enum
{
    PORTH_19_ADC2_SE16 = 0U,
    PORTH_19_GPIO = 1U,
    PORTH_19_SENT1_RXD0 = 2U,
    PORTH_19_FTU1_CH4 = 3U,
    PORTH_19_FCUART10_RX = 4U,
    PORTH_19_eFTU2_OUT_S9 = 5U,
    PORTH_19_TRGSEL_OUT0 = 6U,
    PORTH_19_eFTU1_OUT_S10 = 7U,
} PORT_H19MuxType;

/** @brief PORTH20 Mode enumeration */
typedef enum
{
    PORTH_20_ADC2_SE15 = 0U,
    PORTH_20_GPIO = 1U,
    PORTH_20_SENT1_RXD1 = 2U,
    PORTH_20_FTU1_CH5 = 3U,
    PORTH_20_FCUART10_TX = 4U,
    PORTH_20_eFTU2_OUT_S10 = 5U,
    PORTH_20_TRGSEL_OUT1 = 6U,
    PORTH_20_eFTU1_OUT_S11 = 7U,
} PORT_H20MuxType;

/** @brief PORTH22 Mode enumeration */
typedef enum
{
    PORTH_22_GPIO = 1U,
    PORTH_22_FTU7_CH6 = 2U,
    PORTH_22_eFTU1_OUT_S19 = 3U,
    PORTH_22_FCIIC1_SCL = 4U,
    PORTH_22_TPU0_CH25 = 5U,
    PORTH_22_HSADC1_IO2 = 6U,
    PORTH_22_eFTU1_OUT_S3 = 7U,
} PORT_H22MuxType;

/** @brief PORTH3 Mode enumeration */
typedef enum
{
    PORTH_3_ADC0_SE13 = 0U,
    PORTH_3_GPIO = 1U,
    PORTH_3_FCUART9_CTS = 2U,
    PORTH_3_eFTU1_IN0 = 3U,
    PORTH_3_SSI0_DIG_28_CH0 = 4U,
    PORTH_3_ETM_TRACE_D11 = 5U,
    PORTH_3_QDT0_INDEX = 6U,
    PORTH_3_eFTU2_OUT_S23 = 7U,
} PORT_H3MuxType;

/** @brief PORTH4 Mode enumeration */
typedef enum
{
    PORTH_4_SSI0_ANA_CH0 = 0U,
    PORTH_4_GPIO = 1U,
    PORTH_4_QDT0_PHA = 2U,
    PORTH_4_eFTU0_IN0 = 3U,
    PORTH_4_ENET_PPS0 = 4U,
    PORTH_4_ETM_TRACE_D12 = 5U,
    PORTH_4_FCSPI6_SIN = 6U,
    PORTH_4_eFTU1_OUT_S13 = 7U,
} PORT_H4MuxType;

/** @brief PORTH5 Mode enumeration */
typedef enum
{
    PORTH_5_SSI0_ANA_CH1 = 0U,
    PORTH_5_GPIO = 1U,
    PORTH_5_QDT0_PHB = 2U,
    PORTH_5_eFTU0_IN1 = 3U,
    PORTH_5_ENET_PPS1 = 4U,
    PORTH_5_ETM_TRACE_D13 = 5U,
    PORTH_5_FCSPI6_SCK = 6U,
    PORTH_5_eFTU1_OUT_S14 = 7U,
} PORT_H5MuxType;

/** @brief PORTH6 Mode enumeration */
typedef enum
{
    PORTH_6_GPIO = 1U,
    PORTH_6_FCUART12_RTS = 2U,
    PORTH_6_eFTU0_IN1 = 3U,
    PORTH_6_FCUART3_RX = 4U,
    PORTH_6_HSADC3_IO0 = 5U,
    PORTH_6_TPU0_CH15 = 6U,
    PORTH_6_FLEXCAN6_RX = 7U,
} PORT_H6MuxType;

/** @brief PORTH7 Mode enumeration */
typedef enum
{
    PORTH_7_GPIO = 1U,
    PORTH_7_FTU_FLT8 = 2U,
    PORTH_7_eFTU0_IN2 = 3U,
    PORTH_7_FCUART12_RX = 4U,
    PORTH_7_ENET_COL = 5U,
    PORTH_7_TPU0_CH16 = 6U,
    PORTH_7_HSADC0_IO2 = 7U,
} PORT_H7MuxType;

/** @brief PORTH8 Mode enumeration */
typedef enum
{
    PORTH_8_GPIO = 1U,
    PORTH_8_eFTU0_IN5 = 2U,
    PORTH_8_eFTU1_OUT_S18 = 3U,
    PORTH_8_TPU0_CH24 = 4U,
    PORTH_8_ENET_CRS = 5U,
    PORTH_8_QDT2_PHB = 6U,
    PORTH_8_eFTU1_OUT_S2 = 7U,
} PORT_H8MuxType;

/** @brief PORTI1 Mode enumeration */
typedef enum
{
    PORTI_1_HSADC1_CH2 = 0U,
    PORTI_1_GPIO = 1U,
    PORTI_1_FCUART8_RX = 2U,
    PORTI_1_eFTU2_IN2 = 3U,
    PORTI_1_FCSPI6_PCS0 = 4U,
    PORTI_1_eFTU2_OUT_S19 = 5U,
} PORT_I1MuxType;

/** @brief PORTI10 Mode enumeration */
typedef enum
{
    PORTI_10_ADC3_SE9 = 0U,
    PORTI_10_GPIO = 1U,
    PORTI_10_FLEXCAN11_TX = 2U,
    PORTI_10_eFTU1_IN2 = 3U,
    PORTI_10_FCUART4_TX = 4U,
    PORTI_10_FCSPI7_SOUT = 5U,
    PORTI_10_eFTU1_OUT_S24 = 6U,
    PORTI_10_TPU0_CH6 = 7U,
} PORT_I10MuxType;

/** @brief PORTI11 Mode enumeration */
typedef enum
{
    PORTI_11_ADC5_SE10 = 0U,
    PORTI_11_GPIO = 1U,
    PORTI_11_FLEXCAN11_RX = 2U,
    PORTI_11_eFTU1_IN3 = 3U,
    PORTI_11_FCUART4_RX = 4U,
    PORTI_11_FCSPI7_PCS0 = 5U,
    PORTI_11_eFTU1_OUT_S25 = 6U,
} PORT_I11MuxType;

/** @brief PORTI13 Mode enumeration */
typedef enum
{
    PORTI_13_SDADC1_CH0_P0 = 0U,
    PORTI_13_GPIO = 1U,
    PORTI_13_eFTU0_OUT_S26 = 3U,
    PORTI_13_FLEXCAN8_TX = 4U,
    PORTI_13_SDADC1_CH1 = 5U,
    PORTI_13_eFTU2_OUT_S14 = 6U,
} PORT_I13MuxType;

/** @brief PORTI15 Mode enumeration */
typedef enum
{
    PORTI_15_GPIO = 1U,
    PORTI_15_FCSPI5_SIN = 2U,
    PORTI_15_eFTU0_IN4 = 3U,
    PORTI_15_MSC1_EN0 = 4U,
    PORTI_15_FLEXCAN1_TX = 5U,
    PORTI_15_QDT3_PHA = 6U,
    PORTI_15_eFTU_GTOM4 = 7U,
} PORT_I15MuxType;

/** @brief PORTI16 Mode enumeration */
typedef enum
{
    PORTI_16_GPIO = 1U,
    PORTI_16_FCSPI5_SOUT = 2U,
    PORTI_16_eFTU0_IN5 = 3U,
    PORTI_16_MSC1_EN1 = 4U,
    PORTI_16_FLEXCAN1_RX = 5U,
    PORTI_16_QDT3_PHB = 6U,
    PORTI_16_eFTU_GTOM3 = 7U,
} PORT_I16MuxType;

/** @brief PORTI17 Mode enumeration */
typedef enum
{
    PORTI_17_GPIO = 1U,
    PORTI_17_FCSPI5_PCS1 = 2U,
    PORTI_17_eFTU0_IN6 = 3U,
    PORTI_17_FLEXCAN2_TX = 4U,
    PORTI_17_TPU0_CH4 = 5U,
    PORTI_17_HSADC0_IO0 = 6U,
    PORTI_17_eFTU_GTOM2 = 7U,
} PORT_I17MuxType;

/** @brief PORTI18 Mode enumeration */
typedef enum
{
    PORTI_18_ADC2_SE14 = 0U,
    PORTI_18_GPIO = 1U,
    PORTI_18_SENT1_RXD2 = 2U,
    PORTI_18_FTU1_CH6 = 3U,
    PORTI_18_FCUART2_TX = 4U,
    PORTI_18_FLEXCAN11_TX = 5U,
} PORT_I18MuxType;

/** @brief PORTI19 Mode enumeration */
typedef enum
{
    PORTI_19_ADC2_SE13 = 0U,
    PORTI_19_GPIO = 1U,
    PORTI_19_SENT1_RXD3 = 2U,
    PORTI_19_FTU1_CH7 = 3U,
    PORTI_19_FCUART2_RX = 4U,
    PORTI_19_FLEXCAN11_RX = 5U,
} PORT_I19MuxType;

/** @brief PORTI2 Mode enumeration */
typedef enum
{
    PORTI_2_HSADC0_CH5 = 0U,
    PORTI_2_GPIO = 1U,
    PORTI_2_FCUART8_TX = 2U,
    PORTI_2_eFTU2_IN3 = 3U,
    PORTI_2_FCSPI6_PCS1 = 4U,
    PORTI_2_eFTU2_OUT_S10 = 5U,
    PORTI_2_FLEXCAN9_TX = 6U,
} PORT_I2MuxType;

/** @brief PORTI20 Mode enumeration */
typedef enum
{
    PORTI_20_ADC2_SE10 = 0U,
    PORTI_20_GPIO = 1U,
    PORTI_20_FTU_TCK2 = 2U,
    PORTI_20_FTU_FLT20 = 3U,
    PORTI_20_FTU6_CH7 = 4U,
    PORTI_20_eFTU2_OUT_S13 = 5U,
    PORTI_20_LP_GOOD = 6U,
    PORTI_20_eFTU1_OUT_S15 = 7U,
} PORT_I20MuxType;

/** @brief PORTI21 Mode enumeration */
typedef enum
{
    PORTI_21_ADC1_SE5_ADC1_DIFF_N1 = 0U,
    PORTI_21_GPIO = 1U,
    PORTI_21_FTU4_CH5 = 2U,
    PORTI_21_QDT0_INDEX = 3U,
    PORTI_21_HRPWM0_CH1 = 4U,
    PORTI_21_FCSPI2_PCS2 = 5U,
    PORTI_21_FLEXCAN13_TX = 6U,
    PORTI_21_eFTU1_OUT_S3 = 7U,
} PORT_I21MuxType;

/** @brief PORTI22 Mode enumeration */
typedef enum
{
    PORTI_22_ADC1_SE2_ADC1_DIFF_P2 = 0U,
    PORTI_22_GPIO = 1U,
    PORTI_22_FTU4_CH4 = 2U,
    PORTI_22_TPU0_CH19 = 3U,
    PORTI_22_HRPWM0_CH2 = 4U,
    PORTI_22_HSADC1_BFL = 5U,
    PORTI_22_FLEXCAN13_RX = 6U,
    PORTI_22_eFTU1_OUT_S4 = 7U,
} PORT_I22MuxType;

/** @brief PORTI23 Mode enumeration */
typedef enum
{
    PORTI_23_ADC0_SE6_ADC0_DIFF_N2 = 0U,
    PORTI_23_GPIO = 1U,
    PORTI_23_FTU4_CH7 = 2U,
    PORTI_23_TPU0_CH1 = 3U,
    PORTI_23_SSI0_DIG_28_CH3 = 4U,
    PORTI_23_eFTU2_OUT_S3 = 5U,
    PORTI_23_FLEXCAN12_RX = 6U,
    PORTI_23_eFTU1_OUT_S1 = 7U,
} PORT_I23MuxType;

/** @brief PORTI9 Mode enumeration */
typedef enum
{
    PORTI_9_ADC4_SE9 = 0U,
    PORTI_9_GPIO = 1U,
    PORTI_9_FLEXCAN10_RX = 2U,
    PORTI_9_eFTU1_IN1 = 3U,
    PORTI_9_eFTU0_OUT_S31 = 4U,
    PORTI_9_FCSPI7_SCK = 5U,
    PORTI_9_MSC0_SOP = 6U,
    PORTI_9_TPU0_CH1 = 7U,
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
    PORT_B11MuxType      ePortB11Mode;
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
    PORT_F2MuxType       ePortF2Mode;
    PORT_F3MuxType       ePortF3Mode;
    PORT_F4MuxType       ePortF4Mode;
    PORT_F5MuxType       ePortF5Mode;
    PORT_F7MuxType       ePortF7Mode;
    PORT_F9MuxType       ePortF9Mode;
    PORT_F11MuxType      ePortF11Mode;
    PORT_F12MuxType      ePortF12Mode;
    PORT_F13MuxType      ePortF13Mode;
    PORT_F14MuxType      ePortF14Mode;
    PORT_F15MuxType      ePortF15Mode;
    PORT_F16MuxType      ePortF16Mode;
    PORT_F17MuxType      ePortF17Mode;
    PORT_F20MuxType      ePortF20Mode;
    PORT_F23MuxType      ePortF23Mode;
    PORT_F24MuxType      ePortF24Mode;
    PORT_G0MuxType       ePortG0Mode;
    PORT_G1MuxType       ePortG1Mode;
    PORT_G2MuxType       ePortG2Mode;
    PORT_G3MuxType       ePortG3Mode;
    PORT_G4MuxType       ePortG4Mode;
    PORT_G5MuxType       ePortG5Mode;
    PORT_G8MuxType       ePortG8Mode;
    PORT_G9MuxType       ePortG9Mode;
    PORT_G10MuxType      ePortG10Mode;
    PORT_G11MuxType      ePortG11Mode;
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
    PORT_H3MuxType       ePortH3Mode;
    PORT_H4MuxType       ePortH4Mode;
    PORT_H5MuxType       ePortH5Mode;
    PORT_H6MuxType       ePortH6Mode;
    PORT_H7MuxType       ePortH7Mode;
    PORT_H8MuxType       ePortH8Mode;
    PORT_H10MuxType      ePortH10Mode;
    PORT_H11MuxType      ePortH11Mode;
    PORT_H15MuxType      ePortH15Mode;
    PORT_H16MuxType      ePortH16Mode;
    PORT_H17MuxType      ePortH17Mode;
    PORT_H18MuxType      ePortH18Mode;
    PORT_H19MuxType      ePortH19Mode;
    PORT_H20MuxType      ePortH20Mode;
    PORT_H22MuxType      ePortH22Mode;
    PORT_I1MuxType       ePortI1Mode;
    PORT_I2MuxType       ePortI2Mode;
    PORT_I9MuxType       ePortI9Mode;
    PORT_I10MuxType      ePortI10Mode;
    PORT_I11MuxType      ePortI11Mode;
    PORT_I13MuxType      ePortI13Mode;
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
#define GPIOB_PIN_MASK     (uint32_t)(0xfffffffbu)
/** @brief GpioC Pin MASK structure */
#define GPIOC_PIN_MASK     (uint32_t)(0xf3ffffffu)
/** @brief GpioD Pin MASK structure */
#define GPIOD_PIN_MASK     (uint32_t)(0xffff9fffu)
/** @brief GpioE Pin MASK structure */
#define GPIOE_PIN_MASK     (uint32_t)(0xfffffffu)
/** @brief GpioF Pin MASK structure */
#define GPIOF_PIN_MASK     (uint32_t)(0x193fabcu)
/** @brief GpioG Pin MASK structure */
#define GPIOG_PIN_MASK     (uint32_t)(0xffef3fu)
/** @brief GpioH Pin MASK structure */
#define GPIOH_PIN_MASK     (uint32_t)(0x5f8df8u)
/** @brief GpioI Pin MASK structure */
#define GPIOI_PIN_MASK     (uint32_t)(0xffae06u)


/** @brief Gpio Pin MASK structure */
#define GPIO_PIN_MASK      {GPIOA_PIN_MASK, GPIOB_PIN_MASK, GPIOC_PIN_MASK, GPIOD_PIN_MASK, GPIOE_PIN_MASK, GPIOF_PIN_MASK, GPIOG_PIN_MASK, GPIOH_PIN_MASK, GPIOI_PIN_MASK}

#endif /* _DEVICE_FEATURES_FC7300F8MDQ1A257T1B_H_ */
