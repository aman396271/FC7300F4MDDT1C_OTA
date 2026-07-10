#include <string.h>

#include "ota_config.h"
#include "ota_crc32.h"
#include "ota_partition.h"

static bool ota_slot_is_known(ota_slot_t slot)
{
    return (slot == OTA_SLOT_LOW) || (slot == OTA_SLOT_HIGH);
}

uint32_t ota_get_fmc_ota_ctrl(void)
{
    return FMC0->OTA_CTRL[0];
}

uint32_t ota_get_fmc_ota_version_location(void)
{
    return FMC0->OTA_VER_LOC[0] & FMC_OTA_VER_LOC_MASK;
}

uint32_t ota_get_fmc_ota_active_version(void)
{
    return FMC0->OTA_ACT_VER[0] & FMC_OTA_ACT_VER_MASK;
}

bool ota_is_hardware_ota_enabled(void)
{
    return ((ota_get_fmc_ota_ctrl() & FMC_OTA_CTRL_OTA_EN_MASK) != 0UL);
}

bool ota_is_hardware_ota_locked(void)
{
    return ((ota_get_fmc_ota_ctrl() & FMC_OTA_CTRL_OTA_LOCK_MASK) != 0UL);
}

ota_slot_t ota_get_active_slot(void)
{
    if (!ota_is_hardware_ota_enabled())
    {
        /*
         * When OTA is disabled, the remap decision is not active.  Treat low as
         * the running slot so erase/program protection remains conservative.
         */
        return OTA_SLOT_LOW;
    }

    return ((ota_get_fmc_ota_ctrl() & FMC_OTA_CTRL_OTA_ACTIVE_MASK) != 0UL) ? OTA_SLOT_HIGH : OTA_SLOT_LOW;
}

ota_slot_t ota_get_inactive_slot(void)
{
    return (ota_get_active_slot() == OTA_SLOT_HIGH) ? OTA_SLOT_LOW : OTA_SLOT_HIGH;
}

uint32_t ota_get_slot_base(ota_slot_t slot)
{
    ota_slot_t active;

    if (!ota_slot_is_known(slot))
    {
        return 0UL;
    }

    active = ota_get_active_slot();

    /*
     * Hardware OTA remaps the selected physical slot to the low logical boot
     * window.  Therefore the CPU-visible address of a slot changes when High
     * is active:
     *   active Low  : Low->LOW_BASE,  High->HIGH_BASE
     *   active High : High->LOW_BASE, Low ->HIGH_BASE
     *
     * Flash APIs in this demo receive CPU-visible logical addresses, so every
     * read/program/erase goes through this mapping.
     */
    if (active == OTA_SLOT_HIGH)
    {
        return (slot == OTA_SLOT_HIGH) ? OTA_SLOT_LOW_BASE : OTA_SLOT_HIGH_BASE;
    }

    return (slot == OTA_SLOT_LOW) ? OTA_SLOT_LOW_BASE : OTA_SLOT_HIGH_BASE;
}

uint32_t ota_get_slot_end(ota_slot_t slot)
{
    uint32_t base = ota_get_slot_base(slot);

    if (base == 0UL)
    {
        return 0UL;
    }

    return base + OTA_SLOT_SIZE - 1UL;
}

uint32_t ota_get_slot_header_addr(ota_slot_t slot)
{
    return ota_get_slot_base(slot) + OTA_HEADER_OFFSET;
}

uint32_t ota_get_slot_version_addr(ota_slot_t slot)
{
    return ota_get_slot_base(slot) + OTA_VERSION_LOGICAL_OFFSET;
}

ota_status_t ota_read_slot_header(ota_slot_t slot, ota_image_header_t *header)
{
    if ((!ota_slot_is_known(slot)) || (header == 0))
    {
        return OTA_ERR_PARAM;
    }

    (void)memcpy(header, (const void *)ota_get_slot_header_addr(slot), sizeof(*header));
    return OTA_OK;
}

bool ota_is_slot_valid(ota_slot_t slot)
{
    ota_image_header_t header;
    uint32_t saved_header_crc;

    if (ota_read_slot_header(slot, &header) != OTA_OK)
    {
        return false;
    }

    if ((header.magic != OTA_IMAGE_MAGIC) ||
        (header.header_version != OTA_IMAGE_HEADER_VERSION) ||
        (header.version_inverted != (~header.version)) ||
        (header.valid_code_lo != OTA_IMAGE_VALID_CODE_LO) ||
        (header.valid_code_hi != OTA_IMAGE_VALID_CODE_HI) ||
        (header.valid_flag != OTA_IMAGE_VALID_FLAG) ||
        (header.image_size == 0UL) ||
        (header.image_size > OTA_IMAGE_PAYLOAD_MAX_SIZE))
    {
        return false;
    }

    saved_header_crc = header.header_crc32;
    header.header_crc32 = 0UL;
    return (saved_header_crc == ota_crc32_compute(&header, sizeof(header)));
}

int ota_compare_version(uint32_t v1, uint32_t v2)
{
    if (v1 > v2)
    {
        return 1;
    }
    if (v1 < v2)
    {
        return -1;
    }
    return 0;
}
