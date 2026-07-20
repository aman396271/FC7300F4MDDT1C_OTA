#ifndef OTA_PROTOCOL_H_
#define OTA_PROTOCOL_H_

#include <stdbool.h>
#include <stdint.h>

#define OTA_PROTOCOL_MAGIC               (0x544FU)
#define OTA_PROTOCOL_VERSION             (1U)
#define OTA_PROTOCOL_MAX_PAYLOAD         (512U)
#define OTA_PROTOCOL_HEADER_SIZE         (18U)
#define OTA_PROTOCOL_CRC_SIZE            (4U)
#define OTA_PROTOCOL_MAX_RAW_FRAME       (OTA_PROTOCOL_HEADER_SIZE + OTA_PROTOCOL_MAX_PAYLOAD + OTA_PROTOCOL_CRC_SIZE)
#define OTA_PROTOCOL_MAX_ENCODED_FRAME   (OTA_PROTOCOL_MAX_RAW_FRAME + (OTA_PROTOCOL_MAX_RAW_FRAME / 254U) + 2U)

#define OTA_PROTOCOL_FLAG_RESPONSE       (0x01U)
#define OTA_PROTOCOL_FLAG_ERROR          (0x02U)

typedef enum
{
    OTA_CMD_HELLO = 0x01,
    OTA_CMD_GET_INFO = 0x02,
    OTA_CMD_START_UPDATE = 0x10,
    OTA_CMD_DATA = 0x11,
    OTA_CMD_FINISH = 0x12,
    OTA_CMD_ABORT = 0x13,
    OTA_CMD_GET_STATUS = 0x14
} ota_protocol_command_t;

typedef enum
{
    OTA_PROTO_OK = 0,
    OTA_PROTO_WAIT_POR = 1,
    OTA_PROTO_INVALID_FRAME = 0x100,
    OTA_PROTO_BAD_CRC = 0x101,
    OTA_PROTO_BAD_LENGTH = 0x102,
    OTA_PROTO_UNSUPPORTED_VERSION = 0x103,
    OTA_PROTO_UNSUPPORTED_COMMAND = 0x104,
    OTA_PROTO_BAD_SEQUENCE = 0x105,
    OTA_PROTO_BAD_OFFSET = 0x106,
    OTA_PROTO_SESSION_REQUIRED = 0x107,
    OTA_PROTO_SESSION_BUSY = 0x108,
    OTA_PROTO_OTA_NOT_ENABLED = 0x109,
    OTA_PROTO_ACTIVE_BANK_PROTECTED = 0x10A,
    OTA_PROTO_INVALID_PACKAGE = 0x10B,
    OTA_PROTO_VERSION_REJECTED = 0x10C,
    OTA_PROTO_FLASH_ERROR = 0x10D,
    OTA_PROTO_IMAGE_CRC_ERROR = 0x10E,
    OTA_PROTO_TIMEOUT = 0x10F,
    OTA_PROTO_CANCELLED = 0x110,
    OTA_PROTO_INTERNAL_ERROR = 0x1FF
} ota_protocol_status_t;

typedef struct
{
    uint8_t version;
    uint8_t command;
    uint8_t flags;
    uint32_t sequence;
    uint32_t offset;
    uint16_t length;
    uint16_t status;
    uint8_t payload[OTA_PROTOCOL_MAX_PAYLOAD];
} ota_protocol_frame_t;

typedef enum
{
    OTA_DECODE_NONE = 0,
    OTA_DECODE_FRAME = 1,
    OTA_DECODE_DROPPED = -1
} ota_decode_result_t;

typedef struct
{
    uint16_t encoded_length;
    uint32_t dropped_frames;
    ota_protocol_status_t last_error;
    uint8_t encoded[OTA_PROTOCOL_MAX_ENCODED_FRAME];
    uint8_t raw[OTA_PROTOCOL_MAX_RAW_FRAME];
} ota_protocol_decoder_t;

void ota_protocol_decoder_init(ota_protocol_decoder_t *decoder);
ota_decode_result_t ota_protocol_decoder_push(
    ota_protocol_decoder_t *decoder,
    uint8_t byte,
    ota_protocol_frame_t *frame);
bool ota_protocol_encode(
    const ota_protocol_frame_t *frame,
    uint8_t *output,
    uint32_t capacity,
    uint32_t *output_length);
bool ota_protocol_frame_equal(const ota_protocol_frame_t *a, const ota_protocol_frame_t *b);

#endif /* OTA_PROTOCOL_H_ */
