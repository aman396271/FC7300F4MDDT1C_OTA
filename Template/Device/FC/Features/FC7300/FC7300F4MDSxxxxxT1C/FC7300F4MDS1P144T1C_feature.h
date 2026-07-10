#ifndef _DEVICE_FEATURES_FC7300F4MDS1P144T1C_H_
#define _DEVICE_FEATURES_FC7300F4MDS1P144T1C_H_

#include "FC7300F4MDSxxxxxT1C_feature.h"

/*********************** PORT Features ****************************/
/** Number of instances of the PORT module. */
#define PORT_INSTANCE_COUNT 5U

/** @brief PORTA0 Mode enumeration */
typedef enum
{
    PORTA_0_ADC1_SE23   = 0U,
    PORTA_0_GPIO        = 1U,
    PORTA_0_FTU4_CH6    = 2U,
    PORTA_0_FLEXCAN5_RX = 3U,
    PORTA_0_SENT1_RXD2  = 4U,
    PORTA_0_FTU2_QD_PHA = 5U,
    PORTA_0_FCUART0_CTS = 6U,
    PORTA_0_TRGSEL_OUT3 = 7U,
} PORT_A0MuxType;

/** @brief PORTA1 Mode enumeration */
typedef enum
{
    PORTA_1_GPIO          = 1U,
    PORTA_1_FTU4_CH4      = 2U,
    PORTA_1_eFTU0_OUT_S22 = 3U,
    PORTA_1_SENT1_RXD0    = 4U,
    PORTA_1_FTU1_QD_PHA   = 5U,
    PORTA_1_FCUART0_RTS   = 6U,
    PORTA_1_TRGSEL_OUT0   = 7U,
} PORT_A1MuxType;

/** @brief PORTA2 Mode enumeration */
typedef enum
{
    PORTA_2_GPIO          = 1U,
    PORTA_2_FTU2_CH3      = 2U,
    PORTA_2_FCIIC0_SDA    = 3U,
    PORTA_2_eFTU0_OUT_S28 = 4U,
    PORTA_2_SENT1_RXD1    = 5U,
    PORTA_2_FCUART0_RX    = 6U,
    PORTA_2_FLEXCORE_TDO  = 7U,
} PORT_A2MuxType;

/** @brief PORTA3 Mode enumeration */
typedef enum
{
    PORTA_3_GPIO          = 1U,
    PORTA_3_FTU2_CH2      = 2U,
    PORTA_3_FCIIC0_SCL    = 3U,
    PORTA_3_eFTU0_OUT_S27 = 4U,
    PORTA_3_SENT1_RXD0    = 5U,
    PORTA_3_FCUART0_TX    = 6U,
    PORTA_3_FLEXCORE_TCLK = 7U,
} PORT_A3MuxType;

/** @brief PORTA4 Mode enumeration */
typedef enum
{
    PORTA_4_GPIO             = 1U,
    PORTA_4_JTAG_TMS_SWD_DIO = 7U,
} PORT_A4MuxType;

/** @brief PORTA6 Mode enumeration */
typedef enum
{
    PORTA_6_ADC2_SE13   = 0U,
    PORTA_6_GPIO        = 1U,
    PORTA_6_FTU5_CH0    = 2U,
    PORTA_6_FTU_FLT13   = 3U,
    PORTA_6_FCUART1_CTS = 4U,
    PORTA_6_TRGSEL_OUT4 = 5U,
    PORTA_6_eFTU_GTOM7  = 6U,
    PORTA_6_FCSPI5_SIN  = 7U,
} PORT_A6MuxType;

/** @brief PORTA7 Mode enumeration */
typedef enum
{
    PORTA_7_ADC2_SE11     = 0U,
    PORTA_7_GPIO          = 1U,
    PORTA_7_FTU1_CH1      = 2U,
    PORTA_7_FTU_FLT12     = 3U,
    PORTA_7_FCUART1_RTS   = 4U,
    PORTA_7_FCSPI4_SIN    = 5U,
    PORTA_7_FCUART4_TX    = 6U,
    PORTA_7_eFTU0_OUT_S29 = 7U,
} PORT_A7MuxType;

/** @brief PORTA10 Mode enumeration */
typedef enum
{
    PORTA_10_GPIO     = 1U,
    PORTA_10_FTU3_CH1 = 2U,
    PORTA_10_JTAG_TDO = 7U,
} PORT_A10MuxType;

/** @brief PORTA11 Mode enumeration */
typedef enum
{
    PORTA_11_GPIO        = 1U,
    PORTA_11_FTU3_CH0    = 2U,
    PORTA_11_FLEXCAN1_TX = 3U,
    PORTA_11_FCSPI0_PCS3 = 5U,
    PORTA_11_NMI_b       = 7U,
} PORT_A11MuxType;

/** @brief PORTA12 Mode enumeration */
typedef enum
{
    PORTA_12_ADC1_SE10   = 0U,
    PORTA_12_GPIO        = 1U,
    PORTA_12_FTU0_CH7    = 2U,
    PORTA_12_FLEXCAN1_RX = 3U,
    PORTA_12_FCSPI0_SOUT = 5U,
    PORTA_12_FTU2_QD_PHB = 6U,
} PORT_A12MuxType;

/** @brief PORTA13 Mode enumeration */
typedef enum
{
    PORTA_13_GPIO        = 1U,
    PORTA_13_FTU0_CH3    = 2U,
    PORTA_13_FCIIC1_SCL  = 4U,
    PORTA_13_FCUART0_RX  = 5U,
    PORTA_13_FTU2_QD_PHA = 6U,
    PORTA_13_eFTU_GTOM5  = 7U,
} PORT_A13MuxType;

/** @brief PORTA14 Mode enumeration */
typedef enum
{
    PORTA_14_GPIO           = 1U,
    PORTA_14_FTU_FLT17      = 2U,
    PORTA_14_AONTIMER0_CLK1 = 3U,
    PORTA_14_LP_WAKEUP2     = 4U,
    PORTA_14_FCUART0_TX     = 5U,
    PORTA_14_FCIIC1_SDA     = 6U,
    PORTA_14_eFTU_GTOM2     = 7U,
} PORT_A14MuxType;

/** @brief PORTA15 Mode enumeration */
typedef enum
{
    PORTA_15_ADC1_SE18   = 0U,
    PORTA_15_GPIO        = 1U,
    PORTA_15_FCSPI4_PCS2 = 2U,
    PORTA_15_FTU5_QD_PHB = 3U,
    PORTA_15_FCUART2_RX  = 4U,
    PORTA_15_TRGSEL_OUT0 = 5U,
    PORTA_15_FLEXCAN3_RX = 6U,
    PORTA_15_eFTU_GTOM11 = 7U,
} PORT_A15MuxType;

/** @brief PORTA16 Mode enumeration */
typedef enum
{
    PORTA_16_GPIO       = 1U,
    PORTA_16_FCSMU_PIN0 = 3U,
    PORTA_16_FCUART4_RX = 5U,
} PORT_A16MuxType;

/** @brief PORTA17 Mode enumeration */
typedef enum
{
    PORTA_17_ADC2_SE18   = 0U,
    PORTA_17_GPIO        = 1U,
    PORTA_17_FTU5_CH5    = 2U,
    PORTA_17_FTU_FLT15   = 3U,
    PORTA_17_FCSPI1_PCS2 = 4U,
    PORTA_17_FLEXCAN4_TX = 5U,
    PORTA_17_FCUART5_RTS = 6U,
    PORTA_17_eFTU_GTOM5  = 7U,
} PORT_A17MuxType;

/** @brief PORTA18 Mode enumeration */
typedef enum
{
    PORTA_18_ADC1_SE5_ADC1_DIFF_N1 = 0U,
    PORTA_18_GPIO                  = 1U,
    PORTA_18_FTU3_CH6              = 2U,
    PORTA_18_FCUART1_TX            = 3U,
    PORTA_18_FLEXCAN4_TX           = 5U,
    PORTA_18_eFTU_GTOM12           = 6U,
} PORT_A18MuxType;

/** @brief PORTA19 Mode enumeration */
typedef enum
{
    PORTA_19_ADC1_SE1_ADC1_DIFF_P1 = 0U,
    PORTA_19_GPIO                  = 1U,
    PORTA_19_FCUART1_RX            = 3U,
    PORTA_19_FLEXCAN4_RX           = 5U,
    PORTA_19_eFTU_GTOM15           = 6U,
} PORT_A19MuxType;

/** @brief PORTA21 Mode enumeration */
typedef enum
{
    PORTA_21_ADC0_SE2_ADC0_DIFF_P2 = 0U,
    PORTA_21_GPIO                  = 1U,
    PORTA_21_FCUART6_RX            = 2U,
    PORTA_21_FCUART3_CTS           = 3U,
    PORTA_21_FTU2_CH5              = 4U,
    PORTA_21_SENT0_RXD1            = 5U,
    PORTA_21_FLEXCAN2_TX           = 6U,
} PORT_A21MuxType;

/** @brief PORTA23 Mode enumeration */
typedef enum
{
    PORTA_23_ADC0_SE14       = 0U,
    PORTA_23_GPIO            = 1U,
    PORTA_23_FTU4_CH1        = 2U,
    PORTA_23_FCUART3_RX      = 3U,
    PORTA_23_ETM_TRACE_D0    = 4U,
    PORTA_23_FTU4_QD_PHA     = 5U,
    PORTA_23_eFTU0_OUT_S5    = 6U,
    PORTA_23_SSI0_DIG_28_CH2 = 7U,
} PORT_A23MuxType;

/** @brief PORTA24 Mode enumeration */
typedef enum
{
    PORTA_24_ADC0_SE15       = 0U,
    PORTA_24_GPIO            = 1U,
    PORTA_24_FTU4_CH0        = 2U,
    PORTA_24_FCUART3_TX      = 3U,
    PORTA_24_ETM_TRACE_D1    = 4U,
    PORTA_24_FTU4_QD_PHB     = 5U,
    PORTA_24_eFTU0_OUT_S6    = 6U,
    PORTA_24_SSI0_DIG_14_CH2 = 7U,
} PORT_A24MuxType;

/** @brief PORTA25 Mode enumeration */
typedef enum
{
    PORTA_25_ADC0_SE11       = 0U,
    PORTA_25_GPIO            = 1U,
    PORTA_25_FTU4_CH3        = 2U,
    PORTA_25_SSI0_DIG_14_CH1 = 3U,
    PORTA_25_FCSPI2_SOUT     = 5U,
    PORTA_25_ETM_TRACE_D11   = 6U,
    PORTA_25_eFTU0_OUT_S7    = 7U,
} PORT_A25MuxType;

/** @brief PORTA26 Mode enumeration */
typedef enum
{
    PORTA_26_ADC0_SE7_ADC0_DIFF_N3 = 0U,
    PORTA_26_GPIO                  = 1U,
    PORTA_26_FTU2_CH2              = 2U,
    PORTA_26_SSI0_DIG_28_CH0       = 3U,
    PORTA_26_eFTU0_IN4             = 4U,
    PORTA_26_FCUART7_RTS           = 5U,
    PORTA_26_eFTU0_OUT_S0          = 6U,
} PORT_A26MuxType;

/** @brief PORTA27 Mode enumeration */
typedef enum
{
    PORTA_27_ADC0_SE16     = 0U,
    PORTA_27_GPIO          = 1U,
    PORTA_27_FTU5_CH7      = 2U,
    PORTA_27_FCUART0_TX    = 3U,
    PORTA_27_ETM_TRACE_D2  = 4U,
    PORTA_27_FCSPI1_PCS0   = 5U,
    PORTA_27_eFTU0_IN7     = 6U,
    PORTA_27_eFTU0_OUT_S31 = 7U,
} PORT_A27MuxType;

/** @brief PORTA28 Mode enumeration */
typedef enum
{
    PORTA_28_ADC0_SE18       = 0U,
    PORTA_28_GPIO            = 1U,
    PORTA_28_FTU5_CH5        = 2U,
    PORTA_28_FCUART0_RX      = 3U,
    PORTA_28_ETM_TRACE_D4    = 4U,
    PORTA_28_FCSPI1_SCK      = 5U,
    PORTA_28_eFTU0_OUT_S8    = 6U,
    PORTA_28_SSI0_DIG_28_CH3 = 7U,
} PORT_A28MuxType;

/** @brief PORTA29 Mode enumeration */
typedef enum
{
    PORTA_29_ADC0_SE19       = 0U,
    PORTA_29_GPIO            = 1U,
    PORTA_29_FTU5_CH4        = 2U,
    PORTA_29_FCUART4_RTS     = 3U,
    PORTA_29_ETM_TRACE_D5    = 4U,
    PORTA_29_FCSPI1_SIN      = 5U,
    PORTA_29_eFTU0_OUT_S9    = 6U,
    PORTA_29_SSI0_DIG_14_CH3 = 7U,
} PORT_A29MuxType;

/** @brief PORTA31 Mode enumeration */
typedef enum
{
    PORTA_31_ADC0_SE23         = 0U,
    PORTA_31_GPIO              = 1U,
    PORTA_31_FTU0_CH6          = 2U,
    PORTA_31_FCUART5_TX        = 3U,
    PORTA_31_FTU_FLT3          = 4U,
    PORTA_31_FLEXCAN3_TX       = 5U,
    PORTA_31_eFTU0_OUT_S13     = 6U,
    PORTA_31_eFTU0_BLDC0_HALLC = 7U,
} PORT_A31MuxType;

/** @brief PORTB3 Mode enumeration */
typedef enum
{
    PORTB_3_GPIO          = 1U,
    PORTB_3_FTU0_CH6      = 2U,
    PORTB_3_FTU1_QD_PHA   = 3U,
    PORTB_3_FCSPI2_SCK    = 4U,
    PORTB_3_eFTU0_OUT_S25 = 5U,
    PORTB_3_FTU3_CH7      = 6U,
    PORTB_3_eFTU0_OUT_S15 = 7U,
} PORT_B3MuxType;

/** @brief PORTB4 Mode enumeration */
typedef enum
{
    PORTB_4_GPIO              = 1U,
    PORTB_4_FCSPI0_SCK        = 2U,
    PORTB_4_FTU_FLT4          = 3U,
    PORTB_4_eFTU0_BLDC1_HALLB = 4U,
    PORTB_4_FTU4_CH5          = 5U,
    PORTB_4_eFTU0_OUT_S2      = 6U,
    PORTB_4_FCUART3_RTS       = 7U,
} PORT_B4MuxType;

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
    PORTB_7_GPIO  = 1U,
} PORT_B7MuxType;

/** @brief PORTB8 Mode enumeration */
typedef enum
{
    PORTB_8_GPIO        = 1U,
    PORTB_8_FTU4_CH2    = 2U,
    PORTB_8_FLEXCAN4_TX = 3U,
    PORTB_8_SENT1_RXD1  = 4U,
    PORTB_8_FCUART1_CTS = 6U,
    PORTB_8_eFTU_GTOM0  = 7U,
} PORT_B8MuxType;

/** @brief PORTB9 Mode enumeration */
typedef enum
{
    PORTB_9_GPIO          = 1U,
    PORTB_9_FTU2_CH7      = 2U,
    PORTB_9_SENT1_RXD3    = 3U,
    PORTB_9_FCUART6_CTS   = 4U,
    PORTB_9_TRGSEL_OUT1   = 5U,
    PORTB_9_FCUART1_TX    = 6U,
    PORTB_9_eFTU0_OUT_S30 = 7U,
} PORT_B9MuxType;

/** @brief PORTB11 Mode enumeration */
typedef enum
{
    PORTB_11_V15_BASE_DRIVER = 0U,
    PORTB_11_GPIO            = 1U,
    PORTB_11_eFTU_GTOM0      = 2U,
    PORTB_11_FCUART7_CTS     = 5U,
} PORT_B11MuxType;

/** @brief PORTB13 Mode enumeration */
typedef enum
{
    PORTB_13_ADC2_SE23    = 0U,
    PORTB_13_GPIO         = 1U,
    PORTB_13_FTU3_CH2     = 2U,
    PORTB_13_TCR_CLK      = 3U,
    PORTB_13_FTU5_CH7     = 6U,
    PORTB_13_eFTU0_OUT_S3 = 7U,
} PORT_B13MuxType;

/** @brief PORTB14 Mode enumeration */
typedef enum
{
    PORTB_14_ADC2_SE22         = 0U,
    PORTB_14_GPIO              = 1U,
    PORTB_14_FTU3_CH1          = 2U,
    PORTB_14_FCUART4_RX        = 3U,
    PORTB_14_eFTU0_BLDC0_HALLB = 4U,
    PORTB_14_FTU5_CH3          = 6U,
    PORTB_14_eFTU0_OUT_S2      = 7U,
} PORT_B14MuxType;

/** @brief PORTB15 Mode enumeration */
typedef enum
{
    PORTB_15_ADC2_SE21        = 0U,
    PORTB_15_GPIO             = 1U,
    PORTB_15_FTU3_CH0         = 2U,
    PORTB_15_FCUART4_TX       = 3U,
    PORTB_15_eFTU0_BLDC0_PWM1 = 4U,
    PORTB_15_FTU5_CH2         = 6U,
    PORTB_15_eFTU0_OUT_S1     = 7U,
} PORT_B15MuxType;

/** @brief PORTB17 Mode enumeration */
typedef enum
{
    PORTB_17_ADC2_SE19   = 0U,
    PORTB_17_GPIO        = 1U,
    PORTB_17_FTU5_CH6    = 2U,
    PORTB_17_FTU0_CH1    = 3U,
    PORTB_17_FCSPI1_PCS3 = 4U,
    PORTB_17_FLEXCAN4_RX = 5U,
    PORTB_17_FCUART5_CTS = 6U,
    PORTB_17_eFTU_GTOM10 = 7U,
} PORT_B17MuxType;

/** @brief PORTB20 Mode enumeration */
typedef enum
{
    PORTB_20_ADC3_SE0_ADC3_DIFF_P0 = 0U,
    PORTB_20_GPIO                  = 1U,
    PORTB_20_FTU1_CH0              = 2U,
    PORTB_20_FCUART1_TX            = 3U,
    PORTB_20_FCSPI5_SCK            = 4U,
    PORTB_20_SSI0_DIG_28_CH0       = 5U,
    PORTB_20_eFTU_GTOM13           = 6U,
    PORTB_20_SCG_CLKOUT            = 7U,
} PORT_B20MuxType;

/** @brief PORTB21 Mode enumeration */
typedef enum
{
    PORTB_21_ADC3_SE4_ADC3_DIFF_N0 = 0U,
    PORTB_21_GPIO                  = 1U,
    PORTB_21_FTU1_CH1              = 2U,
    PORTB_21_FCUART1_RX            = 3U,
    PORTB_21_FCSPI5_SIN            = 4U,
    PORTB_21_SSI0_DIG_14_CH0       = 5U,
    PORTB_21_eFTU_GTOM14           = 6U,
    PORTB_21_RTC_CLKOUT            = 7U,
} PORT_B21MuxType;

/** @brief PORTB24 Mode enumeration */
typedef enum
{
    PORTB_24_ADC3_SE1_ADC3_DIFF_P1 = 0U,
    PORTB_24_GPIO                  = 1U,
    PORTB_24_FTU1_CH2              = 2U,
    PORTB_24_FCSPI5_SOUT           = 4U,
    PORTB_24_eFTU0_OUT_S24         = 5U,
    PORTB_24_eFTU0_BLDC1_PWM2      = 6U,
} PORT_B24MuxType;

/** @brief PORTB25 Mode enumeration */
typedef enum
{
    PORTB_25_GPIO          = 1U,
    PORTB_25_FTU0_CH5      = 2U,
    PORTB_25_FCSPI2_PCS0   = 4U,
    PORTB_25_eFTU0_OUT_S24 = 5U,
    PORTB_25_FTU3_CH6      = 6U,
    PORTB_25_eFTU0_OUT_S14 = 7U,
} PORT_B25MuxType;

/** @brief PORTB26 Mode enumeration */
typedef enum
{
    PORTB_26_GPIO              = 1U,
    PORTB_26_eFTU0_BLDC1_HALLC = 2U,
    PORTB_26_FTU_FLT5          = 3U,
    PORTB_26_eFTU0_IN5         = 4U,
    PORTB_26_FTU1_CH6          = 5U,
    PORTB_26_eFTU0_OUT_S3      = 6U,
    PORTB_26_FCSPI3_SIN        = 7U,
} PORT_B26MuxType;

/** @brief PORTB27 Mode enumeration */
typedef enum
{
    PORTB_27_GPIO          = 1U,
    PORTB_27_FTU0_CH7      = 2U,
    PORTB_27_FTU1_QD_PHB   = 3U,
    PORTB_27_FCSPI2_SOUT   = 4U,
    PORTB_27_eFTU0_OUT_S26 = 5U,
    PORTB_27_FTU1_CH4      = 6U,
    PORTB_27_eFTU0_OUT_S22 = 7U,
} PORT_B27MuxType;

/** @brief PORTB28 Mode enumeration */
typedef enum
{
    PORTB_28_GPIO          = 1U,
    PORTB_28_FTU1_CH0      = 2U,
    PORTB_28_ADC3_BFL      = 3U,
    PORTB_28_FCSPI2_SIN    = 4U,
    PORTB_28_eFTU0_OUT_S27 = 5U,
    PORTB_28_FTU1_CH5      = 6U,
    PORTB_28_eFTU0_OUT_S23 = 7U,
} PORT_B28MuxType;

/** @brief PORTB29 Mode enumeration */
typedef enum
{
    PORTB_29_ADC3_SE5_ADC3_DIFF_N1 = 0U,
    PORTB_29_GPIO                  = 1U,
    PORTB_29_FTU1_CH3              = 2U,
    PORTB_29_eFTU0_IN0             = 3U,
    PORTB_29_SSI0_DIG_14_CH0       = 4U,
    PORTB_29_eFTU0_OUT_S27         = 5U,
    PORTB_29_eFTU0_BLDC1_PWM3      = 6U,
    PORTB_29_MSC0_FCLP             = 7U,
} PORT_B29MuxType;

/** @brief PORTB30 Mode enumeration */
typedef enum
{
    PORTB_30_GPIO         = 1U,
    PORTB_30_FCIIC1_SCL   = 3U,
    PORTB_30_eFTU0_IN6    = 4U,
    PORTB_30_FTU1_CH7     = 5U,
    PORTB_30_eFTU0_OUT_S4 = 6U,
    PORTB_30_FCSPI3_SOUT  = 7U,
} PORT_B30MuxType;

/** @brief PORTB31 Mode enumeration */
typedef enum
{
    PORTB_31_ADC3_SE24       = 0U,
    PORTB_31_GPIO            = 1U,
    PORTB_31_SSI0_DIG_28_CH1 = 2U,
    PORTB_31_FCSPI2_SCK      = 3U,
    PORTB_31_eFTU0_IN5       = 4U,
    PORTB_31_FTU1_CH3        = 5U,
    PORTB_31_TRGSEL_OUT5     = 6U,
    PORTB_31_eFTU0_OUT_S12   = 7U,
} PORT_B31MuxType;

/** @brief PORTC0 Mode enumeration */
typedef enum
{
    PORTC_0_GPIO            = 1U,
    PORTC_0_eFTU0_IN6       = 2U,
    PORTC_0_eFTU_GTOM2      = 3U,
    PORTC_0_ETM_TRACE_D6    = 4U,
    PORTC_0_SSI0_DIG_28_CH3 = 5U,
    PORTC_0_eFTU0_OUT_S8    = 6U,
    PORTC_0_FCSPI3_PCS1     = 7U,
} PORT_C0MuxType;

/** @brief PORTC1 Mode enumeration */
typedef enum
{
    PORTC_1_GPIO            = 1U,
    PORTC_1_SSI0_DIG_14_CH3 = 2U,
    PORTC_1_eFTU0_IN3       = 3U,
    PORTC_1_eFTU0_OUT_S5    = 4U,
    PORTC_1_FTU4_CH7        = 5U,
    PORTC_1_eFTU_GTOM14     = 6U,
    PORTC_1_FCSPI3_PCS0     = 7U,
} PORT_C1MuxType;

/** @brief PORTC2 Mode enumeration */
typedef enum
{
    PORTC_2_GPIO             = 1U,
    PORTC_2_FCSPI0_SIN       = 2U,
    PORTC_2_FCUART0_RX       = 3U,
    PORTC_2_ETM_TRACE_CLKOUT = 4U,
    PORTC_2_SSI0_DIG_28_CH0  = 5U,
    PORTC_2_eFTU0_OUT_S6     = 6U,
    PORTC_2_FCUART3_TX       = 7U,
} PORT_C2MuxType;

/** @brief PORTC4 Mode enumeration */
typedef enum
{
    PORTC_4_GPIO              = 1U,
    PORTC_4_FTU3_CH4          = 2U,
    PORTC_4_FTU1_QD_PHB       = 6U,
    PORTC_4_JTAG_TCLK_SWD_CLK = 7U,
} PORT_C4MuxType;

/** @brief PORTC5 Mode enumeration */
typedef enum
{
    PORTC_5_GPIO        = 1U,
    PORTC_5_FTU3_CH3    = 2U,
    PORTC_5_FTU1_QD_PHA = 6U,
    PORTC_5_JTAG_TDI    = 7U,
} PORT_C5MuxType;

/** @brief PORTC7 Mode enumeration */
typedef enum
{
    PORTC_7_ADC1_SE20    = 0U,
    PORTC_7_GPIO         = 1U,
    PORTC_7_FCUART1_TX   = 2U,
    PORTC_7_SENT1_RXD2   = 3U,
    PORTC_7_FTU3_CH3     = 4U,
    PORTC_7_eFTU0_IN3    = 5U,
    PORTC_7_eFTU0_OUT_S7 = 7U,
} PORT_C7MuxType;

/** @brief PORTC8 Mode enumeration */
typedef enum
{
    PORTC_8_ADC2_SE9      = 0U,
    PORTC_8_GPIO          = 1U,
    PORTC_8_FTU0_CH4      = 2U,
    PORTC_8_FTU_FLT11     = 3U,
    PORTC_8_FTU4_QD_PHB   = 4U,
    PORTC_8_FCSPI4_PCS0   = 5U,
    PORTC_8_FCUART0_CTS   = 6U,
    PORTC_8_eFTU0_OUT_S31 = 7U,
} PORT_C8MuxType;

/** @brief PORTC9 Mode enumeration */
typedef enum
{
    PORTC_9_ADC2_SE8      = 0U,
    PORTC_9_GPIO          = 1U,
    PORTC_9_eFTU0_OUT_S14 = 2U,
    PORTC_9_FTU_FLT10     = 3U,
    PORTC_9_FTU4_QD_PHA   = 4U,
    PORTC_9_FCSPI4_SCK    = 5U,
    PORTC_9_FCUART0_RTS   = 6U,
    PORTC_9_FTU1_CH7      = 7U,
} PORT_C9MuxType;

/** @brief PORTC10 Mode enumeration */
typedef enum
{
    PORTC_10_ADC2_SE3_ADC2_DIFF_P3 = 0U,
    PORTC_10_GPIO                  = 1U,
    PORTC_10_FTU3_CH4              = 2U,
    PORTC_10_FLEXCAN4_RX           = 4U,
    PORTC_10_eFTU0_OUT_S21         = 5U,
    PORTC_10_FCSPI4_SIN            = 6U,
    PORTC_10_MSC0_EN1              = 7U,
} PORT_C10MuxType;

/** @brief PORTC11 Mode enumeration */
typedef enum
{
    PORTC_11_ADC2_SE6_ADC2_DIFF_N2 = 0U,
    PORTC_11_GPIO                  = 1U,
    PORTC_11_FTU3_CH3              = 2U,
    PORTC_11_eFTU0_IN7             = 3U,
    PORTC_11_FLEXCAN4_TX           = 4U,
    PORTC_11_eFTU0_OUT_S20         = 5U,
    PORTC_11_FCSPI4_SOUT           = 6U,
    PORTC_11_MSC0_EN0              = 7U,
} PORT_C11MuxType;

/** @brief PORTC12 Mode enumeration */
typedef enum
{
    PORTC_12_ADC3_SE6_ADC3_DIFF_N2 = 0U,
    PORTC_12_GPIO                  = 1U,
    PORTC_12_FTU1_CH5              = 2U,
    PORTC_12_eFTU0_IN2             = 3U,
    PORTC_12_eFTU0_OUT_S29         = 4U,
    PORTC_12_TRGSEL_OUT5           = 5U,
    PORTC_12_FLEXCAN5_RX           = 6U,
    PORTC_12_MSC0_EN2              = 7U,
} PORT_C12MuxType;

/** @brief PORTC13 Mode enumeration */
typedef enum
{
    PORTC_13_ADC3_SE2_ADC3_DIFF_P2 = 0U,
    PORTC_13_GPIO                  = 1U,
    PORTC_13_FTU1_CH4              = 2U,
    PORTC_13_eFTU0_IN1             = 3U,
    PORTC_13_FCSPI5_PCS0           = 4U,
    PORTC_13_TRGSEL_OUT6           = 5U,
    PORTC_13_FLEXCAN5_TX           = 6U,
    PORTC_13_MSC0_SOP              = 7U,
} PORT_C13MuxType;

/** @brief PORTC15 Mode enumeration */
typedef enum
{
    PORTC_15_GPIO            = 1U,
    PORTC_15_eFTU_GTOM6      = 2U,
    PORTC_15_FCSPI2_PCS3     = 3U,
    PORTC_15_SCG_CLKOUT      = 4U,
    PORTC_15_SSI0_DIG_28_CH3 = 5U,
    PORTC_15_eFTU0_IN4       = 6U,
    PORTC_15_FCSPI3_PCS3     = 7U,
} PORT_C15MuxType;

/** @brief PORTC16 Mode enumeration */
typedef enum
{
    PORTC_16_ADC3_SE16       = 0U,
    PORTC_16_GPIO            = 1U,
    PORTC_16_FTU_FLT7        = 2U,
    PORTC_16_FCSPI2_SOUT     = 3U,
    PORTC_16_TRGSEL_OUT7     = 4U,
    PORTC_16_SSI0_DIG_14_CH2 = 5U,
    PORTC_16_eFTU0_OUT_S11   = 6U,
    PORTC_16_FCUART5_RX      = 7U,
} PORT_C16MuxType;

/** @brief PORTC17 Mode enumeration */
typedef enum
{
    PORTC_17_ADC3_SE8        = 0U,
    PORTC_17_GPIO            = 1U,
    PORTC_17_FTU_FLT6        = 2U,
    PORTC_17_FTU0_CH2        = 3U,
    PORTC_17_TRGSEL_OUT6     = 4U,
    PORTC_17_SSI0_DIG_28_CH2 = 5U,
    PORTC_17_eFTU0_OUT_S10   = 6U,
    PORTC_17_FCUART5_TX      = 7U,
} PORT_C17MuxType;

/** @brief PORTC18 Mode enumeration */
typedef enum
{
    PORTC_18_ADC3_SE32       = 0U,
    PORTC_18_GPIO            = 1U,
    PORTC_18_SSI0_DIG_14_CH1 = 2U,
    PORTC_18_FCSPI2_SIN      = 3U,
    PORTC_18_eFTU0_IN6       = 4U,
    PORTC_18_FTU1_CH4        = 5U,
    PORTC_18_TRGSEL_OUT4     = 6U,
    PORTC_18_eFTU0_OUT_S13   = 7U,
} PORT_C18MuxType;

/** @brief PORTC22 Mode enumeration */
typedef enum
{
    PORTC_22_ADC3_SE35     = 0U,
    PORTC_22_GPIO          = 1U,
    PORTC_22_FTU3_CH1      = 2U,
    PORTC_22_eFTU0_OUT_S16 = 3U,
    PORTC_22_eFTU0_IN4     = 4U,
    PORTC_22_ADC3_BFL      = 5U,
    PORTC_22_FCSPI4_PCS0   = 6U,
    PORTC_22_MSC0_SDI1     = 7U,
} PORT_C22MuxType;

/** @brief PORTC23 Mode enumeration */
typedef enum
{
    PORTC_23_ADC2_SE0_ADC2_DIFF_P0 = 0U,
    PORTC_23_GPIO                  = 1U,
    PORTC_23_FTU0_CH0              = 2U,
    PORTC_23_eFTU0_IN5             = 3U,
    PORTC_23_FCUART2_RTS           = 4U,
    PORTC_23_eFTU0_OUT_S18         = 5U,
    PORTC_23_FTU1_QD_PHB           = 6U,
    PORTC_23_MSC0_SDI0             = 7U,
} PORT_C23MuxType;

/** @brief PORTC24 Mode enumeration */
typedef enum
{
    PORTC_24_ADC2_SE2_ADC2_DIFF_P2 = 0U,
    PORTC_24_GPIO                  = 1U,
    PORTC_24_FTU3_CH2              = 2U,
    PORTC_24_eFTU0_IN6             = 3U,
    PORTC_24_FCUART2_CTS           = 4U,
    PORTC_24_eFTU0_OUT_S19         = 5U,
    PORTC_24_FCSPI4_SCK            = 6U,
} PORT_C24MuxType;

/** @brief PORTC25 Mode enumeration */
typedef enum
{
    PORTC_25_GPIO          = 1U,
    PORTC_25_FTU3_CH3      = 2U,
    PORTC_25_FCUART5_RTS   = 3U,
    PORTC_25_FCSPI5_PCS0   = 4U,
    PORTC_25_FLEXCAN2_TX   = 5U,
    PORTC_25_FTU4_CH4      = 6U,
    PORTC_25_eFTU0_OUT_S17 = 7U,
} PORT_C25MuxType;

/** @brief PORTC30 Mode enumeration */
typedef enum
{
    PORTC_30_ADC2_SE12     = 0U,
    PORTC_30_GPIO          = 1U,
    PORTC_30_FTU1_CH2      = 2U,
    PORTC_30_FTU5_QD_PHA   = 4U,
    PORTC_30_FCSPI4_SOUT   = 5U,
    PORTC_30_eFTU0_OUT_S30 = 7U,
} PORT_C30MuxType;

/** @brief PORTC31 Mode enumeration */
typedef enum
{
    PORTC_31_ADC2_SE14     = 0U,
    PORTC_31_GPIO          = 1U,
    PORTC_31_FTU5_CH1      = 2U,
    PORTC_31_eFTU0_OUT_S15 = 3U,
    PORTC_31_FTU5_QD_PHB   = 4U,
    PORTC_31_TRGSEL_OUT3   = 5U,
    PORTC_31_FCSPI5_SCK    = 7U,
} PORT_C31MuxType;

/** @brief PORTD0 Mode enumeration */
typedef enum
{
    PORTD_0_ADC0_SE13     = 0U,
    PORTD_0_GPIO          = 1U,
    PORTD_0_FTU4_CH2      = 2U,
    PORTD_0_FCUART4_CTS   = 3U,
    PORTD_0_eFTU0_OUT_S18 = 4U,
    PORTD_0_FCUART7_RX    = 5U,
    PORTD_0_eFTU0_IN6     = 6U,
    PORTD_0_TRGSEL_OUT1   = 7U,
} PORT_D0MuxType;

/** @brief PORTD1 Mode enumeration */
typedef enum
{
    PORTD_1_ADC0_SE6_ADC0_DIFF_N2 = 0U,
    PORTD_1_GPIO                  = 1U,
    PORTD_1_FCUART6_TX            = 2U,
    PORTD_1_FTU2_CH4              = 4U,
    PORTD_1_SENT0_RXD2            = 5U,
    PORTD_1_FLEXCAN2_RX           = 6U,
    PORTD_1_TRGSEL_OUT2           = 7U,
} PORT_D1MuxType;

/** @brief PORTD2 Mode enumeration */
typedef enum
{
    PORTD_2_GPIO         = 1U,
    PORTD_2_FTU2_CH0     = 2U,
    PORTD_2_SENT0_RXD2   = 3U,
    PORTD_2_FCSPI1_SCK   = 4U,
    PORTD_2_FCUART1_TX   = 5U,
    PORTD_2_eFTU_GTOM11  = 6U,
    PORTD_2_FLEXCORE_TMS = 7U,
} PORT_D2MuxType;

/** @brief PORTD3 Mode enumeration */
typedef enum
{
    PORTD_3_GPIO          = 1U,
    PORTD_3_FTU3_CH7      = 2U,
    PORTD_3_SENT0_RXD1    = 3U,
    PORTD_3_FCSPI1_SIN    = 4U,
    PORTD_3_FCUART6_RX    = 5U,
    PORTD_3_FTU4_CH7      = 6U,
    PORTD_3_eFTU0_OUT_S21 = 7U,
} PORT_D3MuxType;

/** @brief PORTD4 Mode enumeration */
typedef enum
{
    PORTD_4_GPIO          = 1U,
    PORTD_4_FTU3_CH6      = 2U,
    PORTD_4_SENT0_RXD0    = 3U,
    PORTD_4_FCSPI1_SOUT   = 4U,
    PORTD_4_FTU_FLT16     = 5U,
    PORTD_4_FTU4_CH6      = 6U,
    PORTD_4_eFTU0_OUT_S20 = 7U,
} PORT_D4MuxType;

/** @brief PORTD5 Mode enumeration */
typedef enum
{
    PORTD_5_GPIO            = 1U,
    PORTD_5_FCSPI0_SOUT     = 2U,
    PORTD_5_FCUART2_CTS     = 3U,
    PORTD_5_ETM_TRACE_D2    = 4U,
    PORTD_5_SSI0_DIG_14_CH1 = 5U,
    PORTD_5_eFTU_GTOM13     = 6U,
    PORTD_5_FCSPI3_SIN      = 7U,
} PORT_D5MuxType;

/** @brief PORTD6 Mode enumeration */
typedef enum
{
    PORTD_6_GPIO            = 1U,
    PORTD_6_FCUART2_RX      = 2U,
    PORTD_6_FLEXCAN3_RX     = 3U,
    PORTD_6_ETM_TRACE_D1    = 4U,
    PORTD_6_SSI0_DIG_28_CH1 = 5U,
    PORTD_6_eFTU_GTOM12     = 6U,
    PORTD_6_FCSPI3_SCK      = 7U,
} PORT_D6MuxType;

/** @brief PORTD7 Mode enumeration */
typedef enum
{
    PORTD_7_GPIO            = 1U,
    PORTD_7_FCUART2_TX      = 2U,
    PORTD_7_FLEXCAN3_TX     = 3U,
    PORTD_7_ETM_TRACE_D0    = 4U,
    PORTD_7_SSI0_DIG_14_CH0 = 5U,
    PORTD_7_eFTU0_OUT_S7    = 6U,
    PORTD_7_FCUART3_RX      = 7U,
} PORT_D7MuxType;

/** @brief PORTD8 Mode enumeration */
typedef enum
{
    PORTD_8_GPIO         = 1U,
    PORTD_8_ETM_TRACE_D5 = 2U,
    PORTD_8_FCSPI2_PCS2  = 3U,
    PORTD_8_FTU1_CH6     = 4U,
    PORTD_8_FTU1_CH0     = 5U,
    PORTD_8_eFTU_GTOM15  = 6U,
    PORTD_8_FCUART4_RX   = 7U,
} PORT_D8MuxType;

/** @brief PORTD9 Mode enumeration */
typedef enum
{
    PORTD_9_GPIO            = 1U,
    PORTD_9_eFTU0_IN7       = 2U,
    PORTD_9_FCSPI2_PCS1     = 3U,
    PORTD_9_ETM_TRACE_D7    = 4U,
    PORTD_9_SSI0_DIG_14_CH3 = 5U,
    PORTD_9_eFTU0_OUT_S9    = 6U,
    PORTD_9_FCUART4_TX      = 7U,
} PORT_D9MuxType;

/** @brief PORTD10 Mode enumeration */
typedef enum
{
    PORTD_10_GPIO         = 1U,
    PORTD_10_FCSPI0_PCS0  = 2U,
    PORTD_10_FTU2_QD_PHB  = 3U,
    PORTD_10_FTU2_CH6     = 4U,
    PORTD_10_FTU1_CH3     = 5U,
    PORTD_10_FCSPI3_PCS2  = 6U,
    PORTD_10_eFTU0_OUT_S9 = 7U,
} PORT_D10MuxType;

/** @brief PORTD11 Mode enumeration */
typedef enum
{
    PORTD_11_GPIO            = 1U,
    PORTD_11_SSI0_DIG_14_CH2 = 2U,
    PORTD_11_FTU2_QD_PHA     = 3U,
    PORTD_11_ETM_TRACE_D4    = 4U,
    PORTD_11_FTU1_CH2        = 5U,
    PORTD_11_eFTU0_IN2       = 6U,
    PORTD_11_eFTU0_OUT_S8    = 7U,
} PORT_D11MuxType;

/** @brief PORTD12 Mode enumeration */
typedef enum
{
    PORTD_12_GPIO            = 1U,
    PORTD_12_SSI0_DIG_28_CH2 = 2U,
    PORTD_12_FCUART2_RTS     = 3U,
    PORTD_12_ETM_TRACE_D3    = 4U,
    PORTD_12_FTU1_CH1        = 5U,
    PORTD_12_eFTU0_OUT_S1    = 6U,
    PORTD_12_FCSPI3_SOUT     = 7U,
} PORT_D12MuxType;

/** @brief PORTD15 Mode enumeration */
typedef enum
{
    PORTD_15_ADC0_SE21         = 0U,
    PORTD_15_GPIO              = 1U,
    PORTD_15_FTU5_CH0          = 2U,
    PORTD_15_FLEXCAN2_RX       = 3U,
    PORTD_15_ETM_TRACE_D7      = 4U,
    PORTD_15_eFTU0_BLDC0_HALLA = 5U,
    PORTD_15_FCUART2_RTS       = 6U,
    PORTD_15_eFTU0_OUT_S11     = 7U,
} PORT_D15MuxType;

/** @brief PORTD16 Mode enumeration */
typedef enum
{
    PORTD_16_ADC0_SE20    = 0U,
    PORTD_16_GPIO         = 1U,
    PORTD_16_FTU5_CH1     = 2U,
    PORTD_16_FLEXCAN2_TX  = 3U,
    PORTD_16_ETM_TRACE_D6 = 4U,
    PORTD_16_FCSPI1_PCS3  = 5U,
    PORTD_16_FTU2_CH1     = 6U,
    PORTD_16_eFTU0_OUT_S4 = 7U,
} PORT_D16MuxType;

/** @brief PORTD18 Mode enumeration */
typedef enum
{
    PORTD_18_ADC2_SE16     = 0U,
    PORTD_18_GPIO          = 1U,
    PORTD_18_FTU5_CH3      = 2U,
    PORTD_18_FCUART5_RX    = 3U,
    PORTD_18_FCIIC1_SDA    = 4U,
    PORTD_18_eFTU0_OUT_S17 = 5U,
    PORTD_18_FCSPI5_PCS0   = 7U,
} PORT_D18MuxType;

/** @brief PORTD19 Mode enumeration */
typedef enum
{
    PORTD_19_ADC2_SE17         = 0U,
    PORTD_19_GPIO              = 1U,
    PORTD_19_FTU5_CH4          = 2U,
    PORTD_19_FCUART5_TX        = 3U,
    PORTD_19_FCIIC1_SCL        = 4U,
    PORTD_19_eFTU0_BLDC0_HALLC = 5U,
    PORTD_19_eFTU0_OUT_S27     = 7U,
} PORT_D19MuxType;

/** @brief PORTD21 Mode enumeration */
typedef enum
{
    PORTD_21_GPIO             = 1U,
    PORTD_21_FTU3_CH5         = 2U,
    PORTD_21_FCUART5_TX       = 3U,
    PORTD_21_eFTU0_IN0        = 4U,
    PORTD_21_eFTU0_BLDC0_PWM4 = 5U,
    PORTD_21_FTU4_CH5         = 6U,
    PORTD_21_eFTU0_OUT_S19    = 7U,
} PORT_D21MuxType;

/** @brief PORTD23 Mode enumeration */
typedef enum
{
    PORTD_23_GPIO         = 1U,
    PORTD_23_FTU2_CH1     = 2U,
    PORTD_23_SENT0_RXD3   = 3U,
    PORTD_23_FCSPI1_PCS0  = 4U,
    PORTD_23_FCUART1_RX   = 5U,
    PORTD_23_eFTU_GTOM13  = 6U,
    PORTD_23_FLEXCORE_TDI = 7U,
} PORT_D23MuxType;

/** @brief PORTD24 Mode enumeration */
typedef enum
{
    PORTD_24_GPIO          = 1U,
    PORTD_24_FTU2_CH4      = 2U,
    PORTD_24_TCR_CLK       = 3U,
    PORTD_24_eFTU0_IN1     = 4U,
    PORTD_24_SENT1_RXD2    = 5U,
    PORTD_24_FLEXCORE_TRST = 7U,
} PORT_D24MuxType;

/** @brief PORTD26 Mode enumeration */
typedef enum
{
    PORTD_26_GPIO          = 1U,
    PORTD_26_FTU4_CH0      = 2U,
    PORTD_26_FLEXCAN0_TX   = 3U,
    PORTD_26_FCUART4_CTS   = 4U,
    PORTD_26_FCUART6_TX    = 5U,
    PORTD_26_eFTU0_IN7     = 6U,
    PORTD_26_eFTU0_OUT_S25 = 7U,
} PORT_D26MuxType;

/** @brief PORTD27 Mode enumeration */
typedef enum
{
    PORTD_27_GPIO          = 1U,
    PORTD_27_FTU4_CH1      = 2U,
    PORTD_27_FLEXCAN0_RX   = 3U,
    PORTD_27_SENT1_RXD0    = 4U,
    PORTD_27_FCUART6_RTS   = 5U,
    PORTD_27_eFTU0_IN6     = 6U,
    PORTD_27_eFTU0_OUT_S26 = 7U,
} PORT_D27MuxType;

/** @brief PORTD29 Mode enumeration */
typedef enum
{
    PORTD_29_GPIO        = 1U,
    PORTD_29_FTU4_CH5    = 2U,
    PORTD_29_SENT1_RXD1  = 4U,
    PORTD_29_FTU1_QD_PHB = 5U,
    PORTD_29_FCIIC1_SCL  = 6U,
    PORTD_29_eFTU_GTOM2  = 7U,
} PORT_D29MuxType;

/** @brief PORTD30 Mode enumeration */
typedef enum
{
    PORTD_30_ADC1_SE22   = 0U,
    PORTD_30_GPIO        = 1U,
    PORTD_30_FTU4_CH7    = 2U,
    PORTD_30_FLEXCAN5_TX = 3U,
    PORTD_30_SENT1_RXD3  = 4U,
    PORTD_30_FTU2_QD_PHB = 5U,
    PORTD_30_FCIIC1_SDA  = 6U,
    PORTD_30_eFTU_GTOM3  = 7U,
} PORT_D30MuxType;

/** @brief PORTE0 Mode enumeration */
typedef enum
{
    PORTE_0_GPIO        = 1U,
    PORTE_0_FCUART0_CTS = 2U,
    PORTE_0_FTU_TCK1    = 3U,
    PORTE_0_FCIIC1_SDA  = 4U,
    PORTE_0_FCSPI0_SCK  = 5U,
    PORTE_0_FTU_FLT19   = 6U,
    PORTE_0_eFTU_GTOM9  = 7U,
} PORT_E0MuxType;

/** @brief PORTE1 Mode enumeration */
typedef enum
{
    PORTE_1_GPIO        = 1U,
    PORTE_1_FCUART0_RTS = 2U,
    PORTE_1_FCIIC1_SCL  = 4U,
    PORTE_1_FCSPI0_SIN  = 5U,
    PORTE_1_FTU_FLT18   = 6U,
    PORTE_1_eFTU_GTOM8  = 7U,
} PORT_E1MuxType;

/** @brief PORTE3 Mode enumeration */
typedef enum
{
    PORTE_3_OSC32K_EXTAL = 0U,
    PORTE_3_GPIO         = 1U,
    PORTE_3_FTU0_CH2     = 2U,
    PORTE_3_eFTU0_IN1    = 3U,
    PORTE_3_FTU_FLT1     = 4U,
    PORTE_3_FTU_TCK0     = 6U,
} PORT_E3MuxType;

/** @brief PORTE5 Mode enumeration */
typedef enum
{
    PORTE_5_ADC0_SE12     = 0U,
    PORTE_5_GPIO          = 1U,
    PORTE_5_FTU_TCK2      = 2U,
    PORTE_5_FTU4_CH3      = 3U,
    PORTE_5_FCUART7_TX    = 4U,
    PORTE_5_FCSPI2_PCS1   = 5U,
    PORTE_5_eFTU0_IN5     = 6U,
    PORTE_5_eFTU0_OUT_S10 = 7U,
} PORT_E5MuxType;

/** @brief PORTE7 Mode enumeration */
typedef enum
{
    PORTE_7_ADC2_SE15     = 0U,
    PORTE_7_GPIO          = 1U,
    PORTE_7_FTU5_CH2      = 2U,
    PORTE_7_FTU_FLT14     = 3U,
    PORTE_7_eFTU0_OUT_S16 = 5U,
    PORTE_7_FCUART4_RX    = 6U,
    PORTE_7_FCSPI5_SOUT   = 7U,
} PORT_E7MuxType;

/** @brief PORTE8 Mode enumeration */
typedef enum
{
    PORTE_8_GPIO              = 1U,
    PORTE_8_eFTU0_BLDC1_HALLA = 2U,
    PORTE_8_eFTU_GTOM8        = 3U,
    PORTE_8_eFTU0_IN4         = 4U,
    PORTE_8_FTU2_CH5          = 5U,
    PORTE_8_eFTU0_OUT_S0      = 6U,
    PORTE_8_FCSPI3_SCK        = 7U,
} PORT_E8MuxType;

/** @brief PORTE9 Mode enumeration */
typedef enum
{
    PORTE_9_ADC0_SE22         = 0U,
    PORTE_9_GPIO              = 1U,
    PORTE_9_FTU0_CH7          = 2U,
    PORTE_9_FTU2_CH3          = 3U,
    PORTE_9_ETM_TRACE_CLKOUT  = 4U,
    PORTE_9_eFTU0_BLDC0_HALLB = 5U,
    PORTE_9_FCUART2_CTS       = 6U,
    PORTE_9_eFTU0_OUT_S12     = 7U,
} PORT_E9MuxType;

/** @brief PORTE10 Mode enumeration */
typedef enum
{
    PORTE_10_ADC0_SE9         = 0U,
    PORTE_10_GPIO             = 1U,
    PORTE_10_SCG_CLKOUT       = 2U,
    PORTE_10_SSI0_DIG_14_CH0  = 3U,
    PORTE_10_eFTU0_OUT_S23    = 4U,
    PORTE_10_FCSPI2_SIN       = 5U,
    PORTE_10_eFTU0_BLDC0_PWM0 = 6U,
    PORTE_10_TRGSEL_OUT4      = 7U,
} PORT_E10MuxType;

/** @brief PORTE12 Mode enumeration */
typedef enum
{
    PORTE_12_ADC0_SE17    = 0U,
    PORTE_12_GPIO         = 1U,
    PORTE_12_FTU5_CH6     = 2U,
    PORTE_12_FTU_FLT2     = 3U,
    PORTE_12_ETM_TRACE_D3 = 4U,
    PORTE_12_FCSPI1_SOUT  = 5U,
    PORTE_12_eFTU0_IN3    = 6U,
    PORTE_12_eFTU_GTOM1   = 7U,
} PORT_E12MuxType;

/** @brief PORTE13 Mode enumeration */
typedef enum
{
    PORTE_13_ADC0_SE10        = 0U,
    PORTE_13_GPIO             = 1U,
    PORTE_13_FTU2_CH0         = 2U,
    PORTE_13_SSI0_DIG_28_CH1  = 3U,
    PORTE_13_eFTU0_OUT_S28    = 4U,
    PORTE_13_FCSPI2_SCK       = 5U,
    PORTE_13_ETM_TRACE_D10    = 6U,
    PORTE_13_eFTU0_BLDC0_PWM1 = 7U,
} PORT_E13MuxType;

/** @brief PORTE14 Mode enumeration */
typedef enum
{
    PORTE_14_OSC32K_XTAL = 0U,
    PORTE_14_GPIO        = 1U,
    PORTE_14_FTU0_CH3    = 2U,
    PORTE_14_eFTU0_IN0   = 3U,
    PORTE_14_FTU_FLT0    = 4U,
    PORTE_14_FCUART7_RX  = 5U,
} PORT_E14MuxType;

/** @brief PORTE15 Mode enumeration */
typedef enum
{
    PORTE_15_ADC0_SE5_ADC0_DIFF_N1 = 0U,
    PORTE_15_GPIO                  = 1U,
    PORTE_15_FCUART1_CTS           = 2U,
    PORTE_15_FLEXCAN5_RX           = 3U,
    PORTE_15_FTU2_CH6              = 4U,
    PORTE_15_SENT0_RXD0            = 5U,
    PORTE_15_eFTU0_IN2             = 6U,
    PORTE_15_TRGSEL_OUT6           = 7U,
} PORT_E15MuxType;

/** @brief PORTE16 Mode enumeration */
typedef enum
{
    PORTE_16_ADC1_SE0_ADC1_DIFF_P0 = 0U,
    PORTE_16_GPIO                  = 1U,
    PORTE_16_FCUART1_RTS           = 2U,
    PORTE_16_FLEXCAN5_TX           = 3U,
    PORTE_16_FTU2_CH7              = 4U,
    PORTE_16_FCUART7_TX            = 5U,
    PORTE_16_eFTU_GTOM4            = 6U,
    PORTE_16_TRGSEL_OUT7           = 7U,
} PORT_E16MuxType;

/** @brief PORTE17 Mode enumeration */
typedef enum
{
    PORTE_17_GPIO       = 1U,
    PORTE_17_FCSMU_PIN1 = 3U,
    PORTE_17_FTU_FLT20  = 4U,
    PORTE_17_FCUART4_TX = 5U,
    PORTE_17_eFTU_GTOM9 = 7U,
} PORT_E17MuxType;

/** @brief PORTE18 Mode enumeration */
typedef enum
{
    PORTE_18_ADC1_SE19   = 0U,
    PORTE_18_GPIO        = 1U,
    PORTE_18_FCSPI4_PCS3 = 2U,
    PORTE_18_FTU5_QD_PHA = 3U,
    PORTE_18_FCUART2_TX  = 4U,
    PORTE_18_FTU3_CH7    = 5U,
    PORTE_18_FLEXCAN3_TX = 6U,
    PORTE_18_eFTU_GTOM10 = 7U,
} PORT_E18MuxType;

/** @brief PORTE19 Mode enumeration */
typedef enum
{
    PORTE_19_ADC1_SE15  = 0U,
    PORTE_19_GPIO       = 1U,
    PORTE_19_SCG_CLKOUT = 2U,
    PORTE_19_FCIIC0_SCL = 3U,
    PORTE_19_SENT0_RXD2 = 4U,
    PORTE_19_eFTU_GTOM0 = 7U,
} PORT_E19MuxType;

/** @brief PORTE20 Mode enumeration */
typedef enum
{
    PORTE_20_ADC1_SE14  = 0U,
    PORTE_20_GPIO       = 1U,
    PORTE_20_FTU0_CH0   = 2U,
    PORTE_20_FCIIC0_SDA = 3U,
    PORTE_20_SENT0_RXD3 = 4U,
    PORTE_20_eFTU_GTOM1 = 7U,
} PORT_E20MuxType;

/** @brief PORTE21 Mode enumeration */
typedef enum
{
    PORTE_21_ADC1_SE13   = 0U,
    PORTE_21_GPIO        = 1U,
    PORTE_21_FTU0_CH1    = 2U,
    PORTE_21_LP_WAKEUP0  = 3U,
    PORTE_21_FLEXCAN0_TX = 4U,
    PORTE_21_FCUART0_RTS = 5U,
    PORTE_21_eFTU_GTOM3  = 7U,
} PORT_E21MuxType;

/** @brief PORTE22 Mode enumeration */
typedef enum
{
    PORTE_22_ADC1_SE12   = 0U,
    PORTE_22_GPIO        = 1U,
    PORTE_22_FTU0_CH2    = 2U,
    PORTE_22_FLEXCAN0_RX = 4U,
    PORTE_22_FCUART0_CTS = 5U,
    PORTE_22_eFTU_GTOM4  = 7U,
} PORT_E22MuxType;

/** @brief PORTE23 Mode enumeration */
typedef enum
{
    PORTE_23_GPIO        = 1U,
    PORTE_23_FTU0_CH4    = 2U,
    PORTE_23_FLEXCAN1_RX = 3U,
    PORTE_23_FCSPI0_PCS2 = 5U,
    PORTE_23_eFTU_GTOM6  = 7U,
} PORT_E23MuxType;

/** @brief PORTE24 Mode enumeration */
typedef enum
{
    PORTE_24_GPIO        = 1U,
    PORTE_24_FTU0_CH5    = 2U,
    PORTE_24_FLEXCAN1_TX = 3U,
    PORTE_24_FCSPI0_PCS1 = 5U,
    PORTE_24_LP_WAKEUP1  = 6U,
    PORTE_24_eFTU_GTOM7  = 7U,
} PORT_E24MuxType;

/** @brief PORTE26 Mode enumeration */
typedef enum
{
    PORTE_26_ADC1_SE9       = 0U,
    PORTE_26_GPIO           = 1U,
    PORTE_26_FTU3_CH2       = 2U,
    PORTE_26_AONTIMER0_CLK2 = 3U,
    PORTE_26_SENT0_RXD0     = 4U,
    PORTE_26_LP_WAKEUP3     = 5U,
    PORTE_26_FTU2_QD_PHA    = 6U,
    PORTE_26_eFTU_GTOM10    = 7U,
} PORT_E26MuxType;

/** @brief PORTE27 Mode enumeration */
typedef enum
{
    PORTE_27_ADC1_SE8    = 0U,
    PORTE_27_GPIO        = 1U,
    PORTE_27_FTU3_CH5    = 2U,
    PORTE_27_RTC_CLKOUT  = 3U,
    PORTE_27_SENT0_RXD1  = 4U,
    PORTE_27_FTU2_QD_PHB = 6U,
    PORTE_27_eFTU_GTOM11 = 7U,
} PORT_E27MuxType;

/** @brief Port Pin Mux structure */
typedef union
{
    PORT_A0MuxType   ePortA0Mode;
    PORT_A1MuxType   ePortA1Mode;
    PORT_A2MuxType   ePortA2Mode;
    PORT_A3MuxType   ePortA3Mode;
    PORT_A4MuxType   ePortA4Mode;
    PORT_A6MuxType   ePortA6Mode;
    PORT_A7MuxType   ePortA7Mode;
    PORT_A10MuxType  ePortA10Mode;
    PORT_A11MuxType  ePortA11Mode;
    PORT_A12MuxType  ePortA12Mode;
    PORT_A13MuxType  ePortA13Mode;
    PORT_A14MuxType  ePortA14Mode;
    PORT_A15MuxType  ePortA15Mode;
    PORT_A16MuxType  ePortA16Mode;
    PORT_A17MuxType  ePortA17Mode;
    PORT_A18MuxType  ePortA18Mode;
    PORT_A19MuxType  ePortA19Mode;
    PORT_A21MuxType  ePortA21Mode;
    PORT_A23MuxType  ePortA23Mode;
    PORT_A24MuxType  ePortA24Mode;
    PORT_A25MuxType  ePortA25Mode;
    PORT_A26MuxType  ePortA26Mode;
    PORT_A27MuxType  ePortA27Mode;
    PORT_A28MuxType  ePortA28Mode;
    PORT_A29MuxType  ePortA29Mode;
    PORT_A31MuxType  ePortA31Mode;
    PORT_B3MuxType   ePortB3Mode;
    PORT_B4MuxType   ePortB4Mode;
    PORT_B6MuxType   ePortB6Mode;
    PORT_B7MuxType   ePortB7Mode;
    PORT_B8MuxType   ePortB8Mode;
    PORT_B9MuxType   ePortB9Mode;
    PORT_B11MuxType  ePortB11Mode;
    PORT_B13MuxType  ePortB13Mode;
    PORT_B14MuxType  ePortB14Mode;
    PORT_B15MuxType  ePortB15Mode;
    PORT_B17MuxType  ePortB17Mode;
    PORT_B20MuxType  ePortB20Mode;
    PORT_B21MuxType  ePortB21Mode;
    PORT_B24MuxType  ePortB24Mode;
    PORT_B25MuxType  ePortB25Mode;
    PORT_B26MuxType  ePortB26Mode;
    PORT_B27MuxType  ePortB27Mode;
    PORT_B28MuxType  ePortB28Mode;
    PORT_B29MuxType  ePortB29Mode;
    PORT_B30MuxType  ePortB30Mode;
    PORT_B31MuxType  ePortB31Mode;
    PORT_C0MuxType   ePortC0Mode;
    PORT_C1MuxType   ePortC1Mode;
    PORT_C2MuxType   ePortC2Mode;
    PORT_C4MuxType   ePortC4Mode;
    PORT_C5MuxType   ePortC5Mode;
    PORT_C7MuxType   ePortC7Mode;
    PORT_C8MuxType   ePortC8Mode;
    PORT_C9MuxType   ePortC9Mode;
    PORT_C10MuxType  ePortC10Mode;
    PORT_C11MuxType  ePortC11Mode;
    PORT_C12MuxType  ePortC12Mode;
    PORT_C13MuxType  ePortC13Mode;
    PORT_C15MuxType  ePortC15Mode;
    PORT_C16MuxType  ePortC16Mode;
    PORT_C17MuxType  ePortC17Mode;
    PORT_C18MuxType  ePortC18Mode;
    PORT_C22MuxType  ePortC22Mode;
    PORT_C23MuxType  ePortC23Mode;
    PORT_C24MuxType  ePortC24Mode;
    PORT_C25MuxType  ePortC25Mode;
    PORT_C30MuxType  ePortC30Mode;
    PORT_C31MuxType  ePortC31Mode;
    PORT_D0MuxType   ePortD0Mode;
    PORT_D1MuxType   ePortD1Mode;
    PORT_D2MuxType   ePortD2Mode;
    PORT_D3MuxType   ePortD3Mode;
    PORT_D4MuxType   ePortD4Mode;
    PORT_D5MuxType   ePortD5Mode;
    PORT_D6MuxType   ePortD6Mode;
    PORT_D7MuxType   ePortD7Mode;
    PORT_D8MuxType   ePortD8Mode;
    PORT_D9MuxType   ePortD9Mode;
    PORT_D10MuxType  ePortD10Mode;
    PORT_D11MuxType  ePortD11Mode;
    PORT_D12MuxType  ePortD12Mode;
    PORT_D15MuxType  ePortD15Mode;
    PORT_D16MuxType  ePortD16Mode;
    PORT_D18MuxType  ePortD18Mode;
    PORT_D19MuxType  ePortD19Mode;
    PORT_D21MuxType  ePortD21Mode;
    PORT_D23MuxType  ePortD23Mode;
    PORT_D24MuxType  ePortD24Mode;
    PORT_D26MuxType  ePortD26Mode;
    PORT_D27MuxType  ePortD27Mode;
    PORT_D29MuxType  ePortD29Mode;
    PORT_D30MuxType  ePortD30Mode;
    PORT_E0MuxType   ePortE0Mode;
    PORT_E1MuxType   ePortE1Mode;
    PORT_E3MuxType   ePortE3Mode;
    PORT_E5MuxType   ePortE5Mode;
    PORT_E7MuxType   ePortE7Mode;
    PORT_E8MuxType   ePortE8Mode;
    PORT_E9MuxType   ePortE9Mode;
    PORT_E10MuxType  ePortE10Mode;
    PORT_E12MuxType  ePortE12Mode;
    PORT_E13MuxType  ePortE13Mode;
    PORT_E14MuxType  ePortE14Mode;
    PORT_E15MuxType  ePortE15Mode;
    PORT_E16MuxType  ePortE16Mode;
    PORT_E17MuxType  ePortE17Mode;
    PORT_E18MuxType  ePortE18Mode;
    PORT_E19MuxType  ePortE19Mode;
    PORT_E20MuxType  ePortE20Mode;
    PORT_E21MuxType  ePortE21Mode;
    PORT_E22MuxType  ePortE22Mode;
    PORT_E23MuxType  ePortE23Mode;
    PORT_E24MuxType  ePortE24Mode;
    PORT_E26MuxType  ePortE26Mode;
    PORT_E27MuxType  ePortE27Mode;
    Port_PinModeType u32PortPinMode;
} Port_PinMuxType;

/** Array initializer of PORT peripheral base addresses */
#define PORT_BASE_ADDRS     { PORTA_BASE, PORTB_BASE, PORTC_BASE, PORTD_BASE, PORTE_BASE }
/** Array initializer of PORT peripheral base pointers */
#define PORT_BASE_PTRS      { PORTA, PORTB, PORTC, PORTD, PORTE }

/*********************** GPIO Features ****************************/
/** Number of instances of the GPIO module. */
#define GPIO_INSTANCE_COUNT 5U

/** Array initializer of GPIO peripheral base addresses */
#define GPIO_BASE_ADDRS     { GPIOA_BASE, GPIOB_BASE, GPIOC_BASE, GPIOD_BASE, GPIOE_BASE }
/** Array initializer of GPIO peripheral base pointers */
#define GPIO_BASE_PTRS      { GPIOA, GPIOB, GPIOC, GPIOD, GPIOE }

/** @brief GpioA Pin MASK structure */
#define GPIOA_PIN_MASK      (uint32_t)(0xBFAFFCDFu)
/** @brief GpioB Pin MASK structure */
#define GPIOB_PIN_MASK      (uint32_t)(0xFF32EBD8u)
/** @brief GpioC Pin MASK structure */
#define GPIOC_PIN_MASK      (uint32_t)(0xC3C7BFB7u)
/** @brief GpioD Pin MASK structure */
#define GPIOD_PIN_MASK      (uint32_t)(0x6DAD9FFFu)
/** @brief GpioE Pin MASK structure */
#define GPIOE_PIN_MASK      (uint32_t)(0x0DFFF7ABu)

/** @brief Gpio Pin MASK structure */
#define GPIO_PIN_MASK \
    { GPIOA_PIN_MASK, GPIOB_PIN_MASK, GPIOC_PIN_MASK, GPIOD_PIN_MASK, GPIOE_PIN_MASK }

/*********************** FCUART Features Start ****************************/
/** Number of instances of the FCUART module. */
#define FCUART_INSTANCE_COUNT (10u)

/** Array initializer of FCUART peripheral base addresses */
#define FCUART_BASE_ADDRS                                                    \
    { FCUART0_BASE, FCUART1_BASE, FCUART2_BASE, FCUART3_BASE,  FCUART4_BASE, \
      FCUART5_BASE, FCUART6_BASE, FCUART7_BASE, FCUART10_BASE, FCUART12_BASE }
/** Array initializer of FCUART peripheral base pointers */
#define FCUART_BASE_PTRS \
    { FCUART0, FCUART1, FCUART2, FCUART3, FCUART4, FCUART5, FCUART6, FCUART7, FCUART10, FCUART12 }
/** Interrupt vectors for the FCUART peripheral type */
#define FCUART_IRQS                                                          \
    { FCUART0_IRQn, FCUART1_IRQn, FCUART2_IRQn, FCUART3_IRQn,  FCUART4_IRQn, \
      FCUART5_IRQn, FCUART6_IRQn, FCUART7_IRQn, FCUART10_IRQn, FCUART12_IRQn }

typedef enum
{
    UART_INSTANCE_0 = 0U,
    UART_INSTANCE_1,
    UART_INSTANCE_2,
    UART_INSTANCE_3,
    UART_INSTANCE_4,
    UART_INSTANCE_5,
    UART_INSTANCE_6,
    UART_INSTANCE_7,
    UART_INSTANCE_10,
    UART_INSTANCE_12
} FCUART_InstanceType;
/*********************** FCUART Features End ****************************/

#endif /* _DEVICE_FEATURES_FC7300F4MDS1P1441C_H_ */
