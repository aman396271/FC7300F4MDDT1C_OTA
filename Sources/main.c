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
#include "ota_service.h"
#include "ota_time.h"
#include "ota_uart.h"

static FCUART_HandleType s_uart_handle;
static PORT_HandleType s_port_a = { .eInstance = PORT_A };
static PORT_HandleType s_port_d = { .eInstance = PORT_D };
static uint32_t s_core_clock_hz;

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
    s_core_clock_hz = SCG_GetScgClockFreq(SCG_CORE_CLK);

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

    config.u32PortPins = OTA_DEMO_LED_3_PIN;
    PORT_InitPins(&s_port_a, &config);
}

static void board_uart_init(void)
{
    FCUART_InitType config = { 0 };
    uint32_t uart_clock = PCC_GetPccFunctionClock(OTA_DEMO_UART_PCC_CLOCK);

    s_uart_handle.eInstance = OTA_DEMO_UART_INSTANCE;
    config.u32Baudrate = OTA_DEMO_UART_BAUD;
    config.eBitMode = UART_BITMODE_8;
    config.bParityEnable = false;
    config.eStopBit = UART_STOPBIT_NUM_1;
    config.u32ClkSrcHz = uart_clock;
    config.u32TransmitTimeout = 0xFFFFFFFFUL;
    (void)ota_uart_init(&s_uart_handle, &config);
}

static void board_toggle_variant_led(void)
{
#if OTA_BUILD_VARIANT == OTA_BUILD_VARIANT_A
    GPIO_Toggle(OTA_DEMO_LED_A_GPIO, OTA_DEMO_LED_A_PIN);
#else
    GPIO_Toggle(OTA_DEMO_LED_B_GPIO, OTA_DEMO_LED_B_PIN);
#endif
}

static void board_format_hex32(uint32_t value, char output[9])
{
    static const char digits[] = "0123456789ABCDEF";
    uint32_t index;

    for (index = 0UL; index < 8UL; ++index)
    {
        output[7UL - index] = digits[value & 0xFUL];
        value >>= 4U;
    }
    output[8] = '\0';
}

static uint32_t board_read_pc(void)
{
    uint32_t pc;

    __asm volatile ("mov %0, pc" : "=r" (pc));
    return pc;
}

void ota_demo_log(const char *message)
{
    if (ota_service_text_enabled())
    {
        (void)FCUART_Printf(&s_uart_handle, "%s\r\n", message);
    }
}

int main(void)
{
    ota_demo_info_t info;
    char version_hex[9];
    char fmc_ctrl_hex[9];
    char ver_loc_hex[9];
    char act_ver_hex[9];
    char slot_a_version_hex[9];
    char slot_b_version_hex[9];
    char active_physical_hex[9];
    char inactive_physical_hex[9];
    char active_access_hex[9];
    char inactive_access_hex[9];
    char execution_vma_hex[9];
    char heartbeat_count_hex[9];
    char heartbeat_pc_hex[9];
    uint32_t heartbeat_count = 0UL;
    uint32_t last_heartbeat_ms;
    uint32_t last_led_ms;
    uint32_t now_ms;

    board_clock_init();
    board_port_init();
    board_uart_init();
    ota_time_init(s_core_clock_hz);
    ota_service_init();
    ota_demo_init_on_boot();

    (void)ota_demo_get_info(&info);
    /* FCUART_Printf has no width or unsigned formats, so pad hex values here. */
    board_format_hex32(OTA_DEMO_VERSION, version_hex);
    board_format_hex32(info.fmc_ota_ctrl, fmc_ctrl_hex);
    board_format_hex32(info.fmc_ota_ver_loc, ver_loc_hex);
    board_format_hex32(info.fmc_ota_act_ver, act_ver_hex);
    board_format_hex32(info.low_version, slot_a_version_hex);
    board_format_hex32(info.high_version, slot_b_version_hex);
    board_format_hex32(info.active_physical_base, active_physical_hex);
    board_format_hex32(info.inactive_physical_base, inactive_physical_hex);
    board_format_hex32(info.active_access_base, active_access_hex);
    board_format_hex32(info.inactive_access_base, inactive_access_hex);
    board_format_hex32(info.execution_vma, execution_vma_hex);
    (void)FCUART_Printf(
        &s_uart_handle,
        "\r\nFC7300 OTA %s version=0x%s active=%s OTA_EN=%d OTA_ACTIVE=%d\r\n",
        OTA_APP_LABEL,
        version_hex,
        (info.active_slot == OTA_SLOT_HIGH) ? "BANK1/B" : "BANK0/A",
        (int)info.ota_enabled,
        (int)((info.fmc_ota_ctrl >> 5U) & 1UL));
    (void)FCUART_Printf(
        &s_uart_handle,
        "ACTIVE_PHYSICAL=0x%s ACTIVE_ACCESS=0x%s EXEC_VMA=0x%s "
        "TARGET_PHYSICAL=0x%s TARGET_ACCESS=0x%s\r\n",
        active_physical_hex,
        active_access_hex,
        execution_vma_hex,
        inactive_physical_hex,
        inactive_access_hex);
    (void)FCUART_Printf(
        &s_uart_handle,
        "FMC_CTRL=0x%s VER_LOC=0x%s ACT_VER=0x%s\r\n",
        fmc_ctrl_hex,
        ver_loc_hex,
        act_ver_hex);
    (void)FCUART_Printf(
        &s_uart_handle,
        "SLOT_A version=0x%s hw_valid=%d image_valid=%d "
        "SLOT_B version=0x%s hw_valid=%d image_valid=%d\r\n",
        slot_a_version_hex,
        (int)info.low_hw_valid,
        (int)info.low_valid,
        slot_b_version_hex,
        (int)info.high_hw_valid,
        (int)info.high_valid);

#ifndef OTA_DEMO_AUTO_CONFIRM
#define OTA_DEMO_AUTO_CONFIRM 1
#endif

#if OTA_DEMO_AUTO_CONFIRM
    (void)ota_mark_confirmed();
#endif

    last_heartbeat_ms = ota_time_now_ms();
    last_led_ms = last_heartbeat_ms;

    while (1U)
    {
        now_ms = ota_time_now_ms();
        ota_service_poll(now_ms);

        if ((uint32_t)(now_ms - last_led_ms) >= OTA_LED_DELAY_MS)
        {
            last_led_ms = now_ms;
            board_toggle_variant_led();
        }
        if (ota_service_text_enabled() &&
            ((uint32_t)(now_ms - last_heartbeat_ms) >= 1000UL))
        {
            ++heartbeat_count;
            last_heartbeat_ms = now_ms;
            board_format_hex32(heartbeat_count, heartbeat_count_hex);
            board_format_hex32(board_read_pc(), heartbeat_pc_hex);
            (void)FCUART_Printf(
                &s_uart_handle,
                "HEARTBEAT %s count=0x%s PC=0x%s LED=%s\r\n",
                OTA_APP_LABEL,
                heartbeat_count_hex,
                heartbeat_pc_hex,
                OTA_LED_LABEL);
        }
    }
}
