#ifndef _DEVICE_FEATURES_FC7300F4MDSxxxxxT1B_PCC_COMMON_H_
#define _DEVICE_FEATURES_FC7300F4MDSxxxxxT1B_PCC_COMMON_H_


#define PCC_DWP_SUPPORT          (0u)
#define PCC_DWPLK_SUPPORT        (1u)
#define PCC_PLLX_CLK1_SUPPORT    (0u)
#define PCC_PLLX_CLK2_SUPPORT    (0u)
#define PCC_PLL1_CLK_SUPPORT     (1u)

/************ PCC Clock Limits **************/
#define PCC_FUNCTION_CLOCK_MAX   160000000U

/* PCC property MACRO, defines every peripheral clock system architecture */
#define PCC_CLK_NOT_APPLY               (0U)
#define PCC_CGC_AVAILABLE               (1U << 0U)
#define PCC_FUNCCLK_MUXDIVH_USED        (1U << 1U)
#define PCC_FUNCCLK_MUXDIVM_USED        (1U << 2U)
#define PCC_FUNCCLK_MUXDIVL_USED        (1U << 3U)
#define PCC_FUNCCLK_MUXDIVHPIN_USED     (1U << 4U)
#define PCC_MOUDULE_DIV_USED            (1U << 5U)
#define PCC_CLK_DOMAIN_CORE             (1U << 6U)
#define PCC_CLK_DOMAIN_BUS              (1U << 7U)
#define PCC_CLK_DOMAIN_SLOW             (1U << 8U)
#define PCC_DWP_SWR_AVAILABLE           (1U << 9U)

#define PCC_PROPERTY_MUXDIV_MASK           (PCC_FUNCCLK_MUXDIVH_USED | PCC_FUNCCLK_MUXDIVM_USED | PCC_FUNCCLK_MUXDIVL_USED)
#define PCC_PROPERTY_MUXDIV_ALL_MASK       (PCC_FUNCCLK_MUXDIVH_USED | PCC_FUNCCLK_MUXDIVM_USED | PCC_FUNCCLK_MUXDIVL_USED | PCC_FUNCCLK_MUXDIVHPIN_USED)

#endif /* _DEVICE_FEATURES_FC7300F4MDSxxxxxT1B_PCC_COMMON_H_ */
