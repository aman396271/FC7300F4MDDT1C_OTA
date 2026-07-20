#include <string.h>

#include "ota_crc32.h"
#include "ota_protocol.h"

static uint8_t s_encode_raw[OTA_PROTOCOL_MAX_RAW_FRAME];

static uint16_t ota_read_le16(const uint8_t *data)
{
    return (uint16_t)data[0] | ((uint16_t)data[1] << 8U);
}

static uint32_t ota_read_le32(const uint8_t *data)
{
    return (uint32_t)data[0] |
           ((uint32_t)data[1] << 8U) |
           ((uint32_t)data[2] << 16U) |
           ((uint32_t)data[3] << 24U);
}

static void ota_write_le16(uint8_t *data, uint16_t value)
{
    data[0] = (uint8_t)value;
    data[1] = (uint8_t)(value >> 8U);
}

static void ota_write_le32(uint8_t *data, uint32_t value)
{
    data[0] = (uint8_t)value;
    data[1] = (uint8_t)(value >> 8U);
    data[2] = (uint8_t)(value >> 16U);
    data[3] = (uint8_t)(value >> 24U);
}

static bool ota_command_known(uint8_t command)
{
    return (command == OTA_CMD_HELLO) ||
           (command == OTA_CMD_GET_INFO) ||
           (command == OTA_CMD_START_UPDATE) ||
           (command == OTA_CMD_DATA) ||
           (command == OTA_CMD_FINISH) ||
           (command == OTA_CMD_ABORT) ||
           (command == OTA_CMD_GET_STATUS);
}

static bool ota_cobs_decode(
    const uint8_t *input,
    uint32_t input_length,
    uint8_t *output,
    uint32_t capacity,
    uint32_t *output_length)
{
    uint32_t input_index = 0UL;
    uint32_t output_index = 0UL;

    while (input_index < input_length)
    {
        uint8_t code = input[input_index++];
        uint32_t count;
        if (code == 0U)
        {
            return false;
        }
        count = (uint32_t)code - 1UL;
        if ((count > (input_length - input_index)) ||
            (count > (capacity - output_index)))
        {
            return false;
        }
        (void)memcpy(&output[output_index], &input[input_index], count);
        input_index += count;
        output_index += count;
        if ((code != 0xFFU) && (input_index < input_length))
        {
            if (output_index >= capacity)
            {
                return false;
            }
            output[output_index++] = 0U;
        }
    }

    *output_length = output_index;
    return true;
}

static ota_decode_result_t ota_protocol_decode_current(
    ota_protocol_decoder_t *decoder,
    ota_protocol_frame_t *frame)
{
    uint32_t raw_length;
    uint32_t body_length;
    uint16_t payload_length;
    uint32_t received_crc;

    if (!ota_cobs_decode(decoder->encoded,
                         decoder->encoded_length,
                         decoder->raw,
                         sizeof(decoder->raw),
                         &raw_length))
    {
        decoder->last_error = OTA_PROTO_INVALID_FRAME;
        return OTA_DECODE_DROPPED;
    }
    if (raw_length < (OTA_PROTOCOL_HEADER_SIZE + OTA_PROTOCOL_CRC_SIZE))
    {
        decoder->last_error = OTA_PROTO_BAD_LENGTH;
        return OTA_DECODE_DROPPED;
    }

    body_length = raw_length - OTA_PROTOCOL_CRC_SIZE;
    received_crc = ota_read_le32(&decoder->raw[body_length]);
    if (ota_crc32_compute(decoder->raw, body_length) != received_crc)
    {
        decoder->last_error = OTA_PROTO_BAD_CRC;
        return OTA_DECODE_DROPPED;
    }
    if ((ota_read_le16(&decoder->raw[0]) != OTA_PROTOCOL_MAGIC) ||
        (decoder->raw[5] != 0U))
    {
        decoder->last_error = OTA_PROTO_INVALID_FRAME;
        return OTA_DECODE_DROPPED;
    }
    if (decoder->raw[2] != OTA_PROTOCOL_VERSION)
    {
        decoder->last_error = OTA_PROTO_UNSUPPORTED_VERSION;
        return OTA_DECODE_DROPPED;
    }
    if (!ota_command_known(decoder->raw[3]))
    {
        decoder->last_error = OTA_PROTO_UNSUPPORTED_COMMAND;
        return OTA_DECODE_DROPPED;
    }

    payload_length = ota_read_le16(&decoder->raw[14]);
    if ((payload_length > OTA_PROTOCOL_MAX_PAYLOAD) ||
        (body_length != (OTA_PROTOCOL_HEADER_SIZE + payload_length)))
    {
        decoder->last_error = OTA_PROTO_BAD_LENGTH;
        return OTA_DECODE_DROPPED;
    }

    frame->version = decoder->raw[2];
    frame->command = decoder->raw[3];
    frame->flags = decoder->raw[4];
    frame->sequence = ota_read_le32(&decoder->raw[6]);
    frame->offset = ota_read_le32(&decoder->raw[10]);
    frame->length = payload_length;
    frame->status = ota_read_le16(&decoder->raw[16]);
    if (payload_length > 0U)
    {
        (void)memcpy(frame->payload, &decoder->raw[OTA_PROTOCOL_HEADER_SIZE], payload_length);
    }
    decoder->last_error = OTA_PROTO_OK;
    return OTA_DECODE_FRAME;
}

void ota_protocol_decoder_init(ota_protocol_decoder_t *decoder)
{
    if (decoder != 0)
    {
        (void)memset(decoder, 0, sizeof(*decoder));
    }
}

ota_decode_result_t ota_protocol_decoder_push(
    ota_protocol_decoder_t *decoder,
    uint8_t byte,
    ota_protocol_frame_t *frame)
{
    ota_decode_result_t result;

    if ((decoder == 0) || (frame == 0))
    {
        return OTA_DECODE_DROPPED;
    }
    if (byte != 0U)
    {
        if (decoder->encoded_length >= sizeof(decoder->encoded))
        {
            decoder->encoded_length = 0U;
            decoder->dropped_frames++;
            decoder->last_error = OTA_PROTO_BAD_LENGTH;
            return OTA_DECODE_DROPPED;
        }
        decoder->encoded[decoder->encoded_length++] = byte;
        return OTA_DECODE_NONE;
    }
    if (decoder->encoded_length == 0U)
    {
        return OTA_DECODE_NONE;
    }

    result = ota_protocol_decode_current(decoder, frame);
    decoder->encoded_length = 0U;
    if (result == OTA_DECODE_DROPPED)
    {
        decoder->dropped_frames++;
    }
    return result;
}

bool ota_protocol_encode(
    const ota_protocol_frame_t *frame,
    uint8_t *output,
    uint32_t capacity,
    uint32_t *output_length)
{
    uint32_t raw_length;
    uint32_t raw_index;
    uint32_t output_index = 1UL;
    uint32_t code_index = 0UL;
    uint8_t code = 1U;

    if ((frame == 0) || (output == 0) || (output_length == 0) ||
        (frame->length > OTA_PROTOCOL_MAX_PAYLOAD))
    {
        return false;
    }

    ota_write_le16(&s_encode_raw[0], OTA_PROTOCOL_MAGIC);
    s_encode_raw[2] = OTA_PROTOCOL_VERSION;
    s_encode_raw[3] = frame->command;
    s_encode_raw[4] = frame->flags;
    s_encode_raw[5] = 0U;
    ota_write_le32(&s_encode_raw[6], frame->sequence);
    ota_write_le32(&s_encode_raw[10], frame->offset);
    ota_write_le16(&s_encode_raw[14], frame->length);
    ota_write_le16(&s_encode_raw[16], frame->status);
    if (frame->length > 0U)
    {
        (void)memcpy(&s_encode_raw[OTA_PROTOCOL_HEADER_SIZE], frame->payload, frame->length);
    }
    raw_length = OTA_PROTOCOL_HEADER_SIZE + frame->length;
    ota_write_le32(&s_encode_raw[raw_length], ota_crc32_compute(s_encode_raw, raw_length));
    raw_length += OTA_PROTOCOL_CRC_SIZE;

    if (capacity < 2UL)
    {
        return false;
    }
    output[0] = 0U;
    for (raw_index = 0UL; raw_index < raw_length; ++raw_index)
    {
        if (s_encode_raw[raw_index] == 0U)
        {
            output[code_index] = code;
            code_index = output_index++;
            code = 1U;
        }
        else
        {
            if (output_index >= capacity)
            {
                return false;
            }
            output[output_index++] = s_encode_raw[raw_index];
            ++code;
            if (code == 0xFFU)
            {
                if (output_index >= capacity)
                {
                    return false;
                }
                output[code_index] = code;
                code_index = output_index++;
                code = 1U;
            }
        }
    }
    if (output_index >= capacity)
    {
        return false;
    }
    output[code_index] = code;
    output[output_index++] = 0U;
    *output_length = output_index;
    return true;
}

bool ota_protocol_frame_equal(const ota_protocol_frame_t *a, const ota_protocol_frame_t *b)
{
    if ((a == 0) || (b == 0) ||
        (a->version != b->version) ||
        (a->command != b->command) ||
        (a->flags != b->flags) ||
        (a->sequence != b->sequence) ||
        (a->offset != b->offset) ||
        (a->length != b->length) ||
        (a->status != b->status))
    {
        return false;
    }
    return (a->length == 0U) || (memcmp(a->payload, b->payload, a->length) == 0);
}
