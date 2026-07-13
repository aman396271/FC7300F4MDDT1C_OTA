#include <stdint.h>

#include "module_driver_fcuart.h"
#include "module_driver_gpio.h"
#include "module_driver_pcc.h"
#include "module_driver_port.h"
#include "module_driver_scg.h"

#include "ota_board_config.h"
#include "ota_boot_confirm.h"
#include "ota_build_variant.h"
#include "ota_demo.h"

static FCUART_HandleType s_uart_handle;
static PORT_HandleType s_port_a = { .eInstance = PORT_A };
static PORT_HandleType s_port_d = { .eInstance = PORT_D };

static void board_clock_init(void)
{
    SCG_StatusType status;
    PCC_CtrlType pcc;
    SCG_FoscType fosc = {
        .bLock = false,
        .bCm = false,
        .bCmre = false,
        .bSten = false,
        .bBypass = false,
        .eDivH = SCG_ASYNCCLOCKDIV_BY1,
        .eDivM = SCG_ASYNCCLOCKDIV_BY1,
        .eDivL = SCG_ASYNCCLOCKDIV_BY2,
        .u8Eocv = 50U
    };
    SCG_PllType pll0 = {
        .bLock = false,
        .bCm = false,
        .bCmre = false,
        .bSten = false,
        .eSrc = SCG_PLLSOURCE_FOSC,
        .eDivH = SCG_ASYNCCLOCKDIV_BY2,
        .eDivM = SCG_ASYNCCLOCKDIV_BY2,
        .eDivL = SCG_ASYNCCLOCKDIV_BY4,
        .ePrediv = SCG_PLLPREDIV_BY12,
        .ePstDiv = SCG_PLLPSTDIV_BY2,
        .u16Mult = 299U
    };
    SCG_ClockCtrlType clock = {
        .bSysClkMonitor = true,
        .eSrc = SCG_CLOCK_SRC_PLL0,
        .eDivSlow = SCG_CLOCK_DIV_BY2,
        .eDivBus = SCG_CLOCK_DIV_BY2,
        .eDivCore = SCG_CLOCK_DIV_BY1
    };

    SCG_Deinit();
    status = SCG_EnableFOSC(&fosc);
    status = SCG_EnablePLL(SCG_PLL0, &pll0);
    status = SCG_SetClkCtrl(&clock);
    status = SCG_SetNvmClk(SCG_NVMCLK_SRC_FIRC);
    (void)status;

    pcc.eClockName = OTA_DEMO_UART_PCC_CLOCK;
    pcc.bEn = true;
    pcc.eClkSrc = PCC_CLKGATE_SRC_PLL0DIV;
    pcc.eDivider = PCC_CLK_UNINVOLVED;
    PCC_SetPcc(&pcc);
}

static void board_port_init(void)
{
    PORT_InitType config = { 0 };

    config.u32PortPins = OTA_DEMO_UART_RX_PIN;
    config.uPortPinMux.u32PortPinMode = OTA_DEMO_UART_RX_MUX;
    PORT_InitPins(&s_port_a, &config);

    config.u32PortPins = OTA_DEMO_UART_TX_PIN;
    config.uPortPinMux.u32PortPinMode = OTA_DEMO_UART_TX_MUX;
    PORT_InitPins(&s_port_a, &config);

    config.u32PortPins = OTA_DEMO_LED_A_PIN;
    config.uPortPinMux.u32PortPinMode = PORT_GPIO_MODE;
    config.ePortGpioDir = PORT_GPIO_OUT;
    config.ePortGpioLevel = PORT_GPIO_LOW;
    PORT_InitPins(&s_port_a, &config);

    config.u32PortPins = OTA_DEMO_LED_B_PIN;
    PORT_InitPins(&s_port_d, &config);
}

static void board_uart_init(void)
{
    FCUART_InitType config = { 0 };
    uint32_t uart_clock = PCC_GetPccFunctionClock(OTA_DEMO_UART_PCC_CLOCK);

    s_uart_handle.eInstance = OTA_DEMO_UART_INSTANCE;
    config.bEnRxFifo = false;
    config.u32Baudrate = OTA_DEMO_UART_BAUD;
    config.eBitMode = UART_BITMODE_8;
    config.bParityEnable = false;
    config.eStopBit = UART_STOPBIT_NUM_1;
    config.u32ClkSrcHz = uart_clock;
    config.u32TransmitTimeout = 0xFFFFFFFFUL;
    (void)FCUART_Init(&s_uart_handle, &config);
}

static void board_delay_ms(uint32_t milliseconds)
{
    volatile uint32_t outer;
    volatile uint32_t inner;

    for (outer = 0UL; outer < milliseconds; ++outer)
    {
        for (inner = 0UL; inner < 5000UL; ++inner)
        {
            __asm volatile ("nop");
        }
    }
}

static void board_toggle_variant_led(void)
{
#if OTA_BUILD_VARIANT == OTA_BUILD_VARIANT_A
    GPIO_Toggle(OTA_DEMO_LED_A_GPIO, OTA_DEMO_LED_A_PIN);
#else
    GPIO_Toggle(OTA_DEMO_LED_B_GPIO, OTA_DEMO_LED_B_PIN);
#endif
}

void ota_demo_log(const char *message)
{
    (void)FCUART_Printf(&s_uart_handle, "%s\r\n", message);
}

int main(void)
{
    ota_demo_info_t info;

    board_clock_init();
    board_port_init();
    board_uart_init();
    ota_demo_init_on_boot();

    (void)ota_demo_get_info(&info);
    (void)FCUART_Printf(
        &s_uart_handle,
        "\r\nFC7300 OTA %s version=0x%08X active=%s OTA_EN=%u OTA_ACTIVE=%u\r\n",
        OTA_APP_LABEL,
        (unsigned int)OTA_DEMO_VERSION,
        (info.active_slot == OTA_SLOT_HIGH) ? "BANK1/B" : "BANK0/A",
        (unsigned int)info.ota_enabled,
        (unsigned int)((info.fmc_ota_ctrl >> 5U) & 1UL));
    (void)FCUART_Printf(
        &s_uart_handle,
        "FMC_CTRL=0x%08X VER_LOC=0x%08X ACT_VER=0x%08X\r\n",
        (unsigned int)info.fmc_ota_ctrl,
        (unsigned int)info.fmc_ota_ver_loc,
        (unsigned int)info.fmc_ota_act_ver);

#ifndef OTA_DEMO_AUTO_CONFIRM
#define OTA_DEMO_AUTO_CONFIRM 1
#endif

#if OTA_DEMO_AUTO_CONFIRM
    (void)ota_mark_confirmed();
#endif

    while (1U)
    {
        board_toggle_variant_led();
        board_delay_ms(OTA_LED_DELAY_MS);
    }
}
