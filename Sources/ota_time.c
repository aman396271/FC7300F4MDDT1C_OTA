#include "device_header.h"
#include "ota_time.h"

static volatile uint32_t s_milliseconds;

void ota_time_init(uint32_t core_clock_hz)
{
    uint32_t reload = core_clock_hz / 1000UL;

    s_milliseconds = 0UL;
    if ((reload == 0UL) || (reload > (SysTick_LOAD_RELOAD_Msk + 1UL)))
    {
        return;
    }
    SysTick->LOAD = reload - 1UL;
    SysTick->VAL = 0UL;
    SysTick->CTRL = SysTick_CTRL_CLKSOURCE_Msk |
                    SysTick_CTRL_TICKINT_Msk |
                    SysTick_CTRL_ENABLE_Msk;
}

uint32_t ota_time_now_ms(void)
{
    return s_milliseconds;
}

void SysTick_Handler(void)
{
    ++s_milliseconds;
}
