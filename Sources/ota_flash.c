#include <string.h>

#include "module_driver_flash.h"
#include "ota_config.h"
#include "ota_crc32.h"
#include "ota_flash.h"
#include "ota_partition.h"

static FLASH_HandleType s_flash_handle;
static bool s_flash_initialized;

static ota_status_t ota_flash_status_to_ota(FLASH_StatusType status)
{
    return (status == FLASH_ERROR_OK) ? OTA_OK : OTA_ERR_FLASH;
}

static bool ota_is_aligned(uint32_t value, uint32_t alignment)
{
    return ((value & (alignment - 1UL)) == 0UL);
}

static bool ota_slot_is_known(ota_slot_t slot)
{
    return (slot == OTA_SLOT_LOW) || (slot == OTA_SLOT_HIGH);
}

static bool ota_slot_range_ok(ota_slot_t slot, uint32_t offset, uint32_t len)
{
    if (!ota_slot_is_known(slot))
    {
        return false;
    }

    if (len == 0UL)
    {
        return true;
    }

    if (offset >= OTA_SLOT_SIZE)
    {
        return false;
    }

    if (len > (OTA_SLOT_SIZE - offset))
    {
        return false;
    }

    return true;
}

static ota_status_t ota_flash_unlock_range(uint32_t addr, uint32_t len, FLASH_TYPE type)
{
    FLASH_Lock_ParamType lock_param;

    lock_param.u32Address = addr;
    lock_param.u32Length = len;
    lock_param.bLock = FLASH_UNLOCK;
    lock_param.bFlash = type;
    return ota_flash_status_to_ota(FLASHDRIVER_Lock(&lock_param));
}

static ota_status_t ota_flash_erase_absolute(uint32_t addr, uint32_t len, FLASH_TYPE type)
{
    FLASH_DRIVER_ParamType param;
    ota_status_t status;
    uint32_t primask;

    status = ota_flash_unlock_range(addr, len, type);
    if (status != OTA_OK)
    {
        return status;
    }

    param.u32Address = addr;
    param.u32Length = len;
    param.pData = 0;
    param.wdTriggerFct = 0;
    param.u32ErrorAddress = 0UL;

    primask = __get_PRIMASK();
    __disable_irq();
    status = ota_flash_status_to_ota(FLASHDRIVER_SyncErase(&s_flash_handle, &param));
    if (primask == 0UL)
    {
        __enable_irq();
    }

    SCB_InvalidateICache();
    SCB_CleanInvalidateDCache();

    return status;
}

static ota_status_t ota_flash_program_absolute(uint32_t addr, const void *data, uint32_t len)
{
    FLASH_DRIVER_ParamType param;
    ota_status_t status;
    uint32_t primask;

    if ((data == 0) || (len == 0UL))
    {
        return OTA_ERR_PARAM;
    }

    if ((!ota_is_aligned(addr, PFLASH_PROGRAM_PAGE_MIN_SIZE)) ||
        (!ota_is_aligned(len, PFLASH_PROGRAM_PAGE_MIN_SIZE)))
    {
        return OTA_ERR_RANGE;
    }

    status = ota_flash_unlock_range(addr, len, PFlash);
    if (status != OTA_OK)
    {
        return status;
    }

    param.u32Address = addr;
    param.u32Length = len;
    param.pData = (uint8_t *)data;
    param.wdTriggerFct = 0;
    param.u32ErrorAddress = 0UL;

    /*
     * The SDK ROM API performs the program operation, but interrupts are kept
     * masked so an ISR cannot fetch from a PFlash bank while it is being
     * programmed.  If the final product enables flash RWW/hold constraints,
     * place this wrapper in RAM and add the RM-mandated hold configuration.
     */
    primask = __get_PRIMASK();
    __disable_irq();
    status = ota_flash_status_to_ota(FLASHDRIVER_SyncWrite(&s_flash_handle, &param));
    if (primask == 0UL)
    {
        __enable_irq();
    }

    SCB_InvalidateICache();
    SCB_CleanInvalidateDCache();

    return status;
}

ota_status_t ota_flash_init(void)
{
    if (!s_flash_initialized)
    {
        (void)memset(&s_flash_handle, 0, sizeof(s_flash_handle));
        s_flash_handle.eInstance = FLASH_INSTANCE_0;
        FLASHDRIVER_Init();
        s_flash_initialized = true;
    }

    return OTA_OK;
}

ota_status_t ota_flash_erase_slot(ota_slot_t slot)
{
    if (!ota_slot_is_known(slot))
    {
        return OTA_ERR_PARAM;
    }

    if (slot == ota_get_active_slot())
    {
        return OTA_ERR_ACTIVE_SLOT;
    }

    if (!ota_is_aligned(ota_get_slot_base(slot), PFLASH_ERASE_SECTOR_SIZE) ||
        !ota_is_aligned(OTA_SLOT_SIZE, PFLASH_ERASE_SECTOR_SIZE))
    {
        return OTA_ERR_RANGE;
    }

    (void)ota_flash_init();
    return ota_flash_erase_absolute(ota_get_slot_base(slot), OTA_SLOT_SIZE, PFlash);
}

ota_status_t ota_flash_program(ota_slot_t slot, uint32_t offset, const void *data, uint32_t len)
{
    uint32_t addr;

    if (!ota_slot_range_ok(slot, offset, len) || (data == 0))
    {
        return OTA_ERR_PARAM;
    }

    if (slot == ota_get_active_slot())
    {
        return OTA_ERR_ACTIVE_SLOT;
    }

    if ((!ota_is_aligned(offset, PFLASH_PROGRAM_PAGE_MIN_SIZE)) ||
        (!ota_is_aligned(len, PFLASH_PROGRAM_PAGE_MIN_SIZE)))
    {
        return OTA_ERR_RANGE;
    }

    addr = ota_get_slot_base(slot) + offset;
    (void)ota_flash_init();
    return ota_flash_program_absolute(addr, data, len);
}

ota_status_t ota_flash_read(ota_slot_t slot, uint32_t offset, void *data, uint32_t len)
{
    if (!ota_slot_range_ok(slot, offset, len) || (data == 0))
    {
        return OTA_ERR_PARAM;
    }

    (void)memcpy(data, (const void *)(ota_get_slot_base(slot) + offset), len);
    return OTA_OK;
}

ota_status_t ota_flash_verify_crc(ota_slot_t slot)
{
    ota_image_header_t header;
    uint32_t crc;
    uint32_t offset;
    uint32_t chunk_len;
    const uint8_t *slot_ptr;

    if (ota_read_slot_header(slot, &header) != OTA_OK)
    {
        return OTA_ERR_PARAM;
    }

    if (!ota_is_slot_valid(slot))
    {
        return OTA_ERR_INVALID_IMAGE;
    }

    slot_ptr = (const uint8_t *)ota_get_slot_base(slot);
    crc = ota_crc32_init();
    offset = 0UL;
    while (offset < header.image_size)
    {
        chunk_len = header.image_size - offset;
        if (chunk_len > 1024UL)
        {
            chunk_len = 1024UL;
        }
        crc = ota_crc32_update(crc, &slot_ptr[offset], chunk_len);
        offset += chunk_len;
    }

    return (ota_crc32_finish(crc) == header.image_crc32) ? OTA_OK : OTA_ERR_CRC;
}

ota_status_t ota_flash_erase_header_sector(ota_slot_t slot, bool allow_active_slot)
{
    uint32_t addr;

    if (!ota_slot_is_known(slot))
    {
        return OTA_ERR_PARAM;
    }

    if ((!allow_active_slot) && (slot == ota_get_active_slot()))
    {
        return OTA_ERR_ACTIVE_SLOT;
    }

    addr = ota_get_slot_header_addr(slot);
    if (!ota_is_aligned(addr, PFLASH_ERASE_SECTOR_SIZE))
    {
        return OTA_ERR_RANGE;
    }

    (void)ota_flash_init();
    return ota_flash_erase_absolute(addr, PFLASH_ERASE_SECTOR_SIZE, PFlash);
}

ota_status_t ota_flash_program_header(ota_slot_t slot, const ota_image_header_t *header)
{
    ota_status_t status;

    if (header == 0)
    {
        return OTA_ERR_PARAM;
    }

    if ((sizeof(*header) > OTA_HEADER_SIZE) ||
        ((sizeof(*header) & (PFLASH_PROGRAM_PAGE_MIN_SIZE - 1UL)) != 0UL))
    {
        return OTA_ERR_RANGE;
    }

    status = ota_flash_erase_header_sector(slot, false);
    if (status != OTA_OK)
    {
        return status;
    }

    return ota_flash_program(slot, OTA_HEADER_OFFSET, header, sizeof(*header));
}

ota_status_t ota_dflash_read_state(void *data, uint32_t len)
{
    if ((data == 0) || (len > OTA_STATE_FLASH_SIZE))
    {
        return OTA_ERR_PARAM;
    }

    (void)memcpy(data, (const void *)OTA_STATE_FLASH_ADDR, len);
    return OTA_OK;
}

ota_status_t ota_dflash_write_state(const void *data, uint32_t len)
{
    FLASH_DRIVER_ParamType param;
    ota_status_t status;
    uint32_t aligned_len;
    uint8_t page[FLASH_PROGRAM_PAGE_MAX_SIZE];
    uint32_t offset;

    if ((data == 0) || (len > OTA_STATE_FLASH_SIZE))
    {
        return OTA_ERR_PARAM;
    }

    if (!ota_is_aligned(OTA_STATE_FLASH_ADDR, DFLASH_ERASE_SECTOR_SIZE))
    {
        return OTA_ERR_RANGE;
    }

    (void)ota_flash_init();
    status = ota_flash_erase_absolute(OTA_STATE_FLASH_ADDR, OTA_STATE_FLASH_SIZE, DFlash);
    if (status != OTA_OK)
    {
        return status;
    }

    aligned_len = (len + (DFLASH_PROGRAM_PAGE_MIN_SIZE - 1UL)) & ~(DFLASH_PROGRAM_PAGE_MIN_SIZE - 1UL);
    offset = 0UL;
    while (offset < aligned_len)
    {
        uint32_t copy_len = aligned_len - offset;
        if (copy_len > sizeof(page))
        {
            copy_len = sizeof(page);
        }

        (void)memset(page, 0xFF, sizeof(page));
        if (offset < len)
        {
            uint32_t available = len - offset;
            if (available > copy_len)
            {
                available = copy_len;
            }
            (void)memcpy(page, &((const uint8_t *)data)[offset], available);
        }

        status = ota_flash_unlock_range(OTA_STATE_FLASH_ADDR + offset, copy_len, DFlash);
        if (status != OTA_OK)
        {
            return status;
        }

        param.u32Address = OTA_STATE_FLASH_ADDR + offset;
        param.u32Length = copy_len;
        param.pData = page;
        param.wdTriggerFct = 0;
        param.u32ErrorAddress = 0UL;
        status = ota_flash_status_to_ota(FLASHDRIVER_SyncWrite(&s_flash_handle, &param));
        if (status != OTA_OK)
        {
            return status;
        }

        offset += copy_len;
    }

    SCB_CleanInvalidateDCache();
    return OTA_OK;
}
