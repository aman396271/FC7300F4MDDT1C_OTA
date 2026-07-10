#include "ota_boot_confirm.h"
#include "ota_demo.h"

void IntMgr_Init(void)
{
	/* initial something like interrupt and vector table */
}


int main(void)
{
    ota_demo_init_on_boot();

    /*
     * Demo default: immediately confirm the running image.  To exercise the
     * failed-first-boot rollback scenario, build with OTA_DEMO_AUTO_CONFIRM=0
     * or remove this call and reset once after the new image starts.
     */
#ifndef OTA_DEMO_AUTO_CONFIRM
#define OTA_DEMO_AUTO_CONFIRM 1
#endif

#if OTA_DEMO_AUTO_CONFIRM
    (void)ota_mark_confirmed();
#endif

    while (1U)
    {
    }

    return 0;
}
