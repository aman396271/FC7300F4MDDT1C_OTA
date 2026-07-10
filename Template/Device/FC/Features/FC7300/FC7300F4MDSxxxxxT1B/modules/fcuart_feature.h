#ifndef _DEVICE_FEATURES_FC7300F4MDSxxxxxT1B_FCUART_COMMON_H_
#define _DEVICE_FEATURES_FC7300F4MDSxxxxxT1B_FCUART_COMMON_H_

/** Number of instances of the FCUART module. */
#define FCUART_INSTANCE_COUNT                    (8u)

/** Array initializer of FCUART peripheral base addresses */
#define FCUART_BASE_ADDRS                        {FCUART0_BASE, FCUART1_BASE, FCUART2_BASE, FCUART3_BASE, FCUART4_BASE, FCUART5_BASE, FCUART6_BASE, FCUART7_BASE}
/** Array initializer of FCUART peripheral base pointers */
#define FCUART_BASE_PTRS                         {FCUART0, FCUART1, FCUART2, FCUART3, FCUART4, FCUART5, FCUART6, FCUART7}
/** Interrupt vectors for the FCUART peripheral type */
#define FCUART_IRQS                              {FCUART0_IRQn, FCUART1_IRQn, FCUART2_IRQn, FCUART3_IRQn, FCUART4_IRQn, FCUART5_IRQn, FCUART6_IRQn, FCUART7_IRQn}

typedef enum
{
    UART_INSTANCE_0 = 0U,
    UART_INSTANCE_1,
    UART_INSTANCE_2,
    UART_INSTANCE_3,
    UART_INSTANCE_4,
    UART_INSTANCE_5,
    UART_INSTANCE_6,
    UART_INSTANCE_7
} FCUART_InstanceType;

#endif /* _DEVICE_FEATURES_FC7300F4MDSxxxxxT1B_FCUART_COMMON_H_ */
