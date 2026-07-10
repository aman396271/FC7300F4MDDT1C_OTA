#include "ota_crc32.h"

uint32_t ota_crc32_init(void)
{
    return 0xFFFFFFFFUL;
}

uint32_t ota_crc32_update(uint32_t crc, const void *data, size_t len)
{
    const uint8_t *bytes = (const uint8_t *)data;
    size_t i;
    uint8_t bit;

    if (bytes == 0)
    {
        return crc;
    }

    for (i = 0U; i < len; i++)
    {
        crc ^= (uint32_t)bytes[i];
        for (bit = 0U; bit < 8U; bit++)
        {
            if ((crc & 1UL) != 0UL)
            {
                crc = (crc >> 1U) ^ 0xEDB88320UL;
            }
            else
            {
                crc >>= 1U;
            }
        }
    }

    return crc;
}

uint32_t ota_crc32_finish(uint32_t crc)
{
    return crc ^ 0xFFFFFFFFUL;
}

uint32_t ota_crc32_compute(const void *data, size_t len)
{
    return ota_crc32_finish(ota_crc32_update(ota_crc32_init(), data, len));
}
