#include <stdio.h>
#include <string.h>

#include "ota_protocol.h"

int main(void)
{
    ota_protocol_frame_t frame;
    ota_protocol_frame_t decoded;
    ota_protocol_decoder_t decoder;
    uint8_t output[OTA_PROTOCOL_MAX_ENCODED_FRAME];
    uint32_t length = 0U;
    uint32_t index;
    int decoded_count = 0;

    (void)memset(&frame, 0, sizeof(frame));
    frame.version = OTA_PROTOCOL_VERSION;
    frame.command = OTA_CMD_DATA;
    frame.sequence = 0x12345678UL;
    frame.offset = 0x100UL;
    frame.length = 5U;
    frame.payload[0] = 0U;
    frame.payload[1] = 1U;
    frame.payload[2] = 2U;
    frame.payload[3] = 0U;
    frame.payload[4] = 0xFFU;

    if (!ota_protocol_encode(&frame, output, sizeof(output), &length))
    {
        return 1;
    }
    ota_protocol_decoder_init(&decoder);
    for (index = 0U; index < length; ++index)
    {
        if (ota_protocol_decoder_push(&decoder, output[index], &decoded) == OTA_DECODE_FRAME)
        {
            ++decoded_count;
        }
    }
    if ((decoded_count != 1) || (!ota_protocol_frame_equal(&frame, &decoded)))
    {
        return 2;
    }
    for (index = 0U; index < length; ++index)
    {
        (void)printf("%02X", output[index]);
    }
    (void)printf("\n");
    return 0;
}
