#include <string.h>

#include "ota_demo.h"
#include "ota_partition.h"
#include "ota_protocol.h"
#include "ota_service.h"
#include "ota_time.h"
#include "ota_uart.h"
#include "ota_update.h"

#define OTA_SERVICE_SESSION_TIMEOUT_MS (5000UL)

typedef struct
{
    bool sequence_valid;
    bool binary_mode;
    bool update_session;
    bool have_cached_response;
    uint32_t expected_sequence;
    uint32_t last_activity_ms;
    uint32_t last_uart_overflow;
    ota_protocol_status_t last_error;
    ota_protocol_decoder_t decoder;
    ota_protocol_frame_t request;
    ota_protocol_frame_t last_request;
    uint8_t response_bytes[OTA_PROTOCOL_MAX_ENCODED_FRAME];
    uint32_t response_length;
} ota_service_context_t;

static ota_service_context_t s_service;

static void ota_put_le16(uint8_t *data, uint16_t value)
{
    data[0] = (uint8_t)value;
    data[1] = (uint8_t)(value >> 8U);
}

static void ota_put_le32(uint8_t *data, uint32_t value)
{
    data[0] = (uint8_t)value;
    data[1] = (uint8_t)(value >> 8U);
    data[2] = (uint8_t)(value >> 16U);
    data[3] = (uint8_t)(value >> 24U);
}

static ota_protocol_status_t ota_service_map_status(ota_status_t status)
{
    switch (status)
    {
        case OTA_OK:
            return OTA_PROTO_OK;
        case OTA_ERR_NOT_ENABLED:
            return OTA_PROTO_OTA_NOT_ENABLED;
        case OTA_ERR_ACTIVE_SLOT:
            return OTA_PROTO_ACTIVE_BANK_PROTECTED;
        case OTA_ERR_INVALID_IMAGE:
            return OTA_PROTO_INVALID_PACKAGE;
        case OTA_ERR_CRC:
            return OTA_PROTO_IMAGE_CRC_ERROR;
        case OTA_ERR_VERSION:
            return OTA_PROTO_VERSION_REJECTED;
        case OTA_ERR_BUSY:
            return OTA_PROTO_SESSION_BUSY;
        case OTA_ERR_TIMEOUT:
            return OTA_PROTO_TIMEOUT;
        case OTA_ERR_FLASH:
        case OTA_ERR_LOCKED:
            return OTA_PROTO_FLASH_ERROR;
        case OTA_ERR_PARAM:
        case OTA_ERR_RANGE:
            return OTA_PROTO_BAD_LENGTH;
        default:
            return OTA_PROTO_INTERNAL_ERROR;
    }
}

static void ota_service_send_response(
    const ota_protocol_frame_t *request,
    ota_protocol_status_t status,
    uint32_t offset,
    const void *payload,
    uint16_t length)
{
    ota_protocol_frame_t response;

    (void)memset(&response, 0, sizeof(response));
    response.version = OTA_PROTOCOL_VERSION;
    response.command = request->command;
    response.flags = OTA_PROTOCOL_FLAG_RESPONSE;
    if ((status != OTA_PROTO_OK) && (status != OTA_PROTO_WAIT_POR))
    {
        response.flags |= OTA_PROTOCOL_FLAG_ERROR;
        s_service.last_error = status;
    }
    response.sequence = request->sequence;
    response.offset = offset;
    response.status = (uint16_t)status;
    response.length = length;
    if ((payload != 0) && (length > 0U))
    {
        (void)memcpy(response.payload, payload, length);
    }

    if (ota_protocol_encode(&response,
                            s_service.response_bytes,
                            sizeof(s_service.response_bytes),
                            &s_service.response_length))
    {
        (void)ota_uart_write(s_service.response_bytes, s_service.response_length);
        s_service.last_request = *request;
        s_service.have_cached_response = true;
    }
}

static void ota_service_handle_hello(const ota_protocol_frame_t *request)
{
    uint8_t payload[8];

    s_service.binary_mode = true;
    s_service.sequence_valid = true;
    s_service.expected_sequence = request->sequence + 1UL;
    ota_put_le16(&payload[0], OTA_PROTOCOL_VERSION);
    ota_put_le16(&payload[2], OTA_PROTOCOL_VERSION);
    ota_put_le32(&payload[4], OTA_PROTOCOL_MAX_PAYLOAD);
    ota_service_send_response(request, OTA_PROTO_OK, request->offset, payload, sizeof(payload));
}

static void ota_service_handle_get_info(const ota_protocol_frame_t *request)
{
    ota_demo_info_t info;
    uint32_t flags = 0UL;
    uint8_t payload[48];

    if (ota_demo_get_info(&info) != OTA_OK)
    {
        ota_service_send_response(request, OTA_PROTO_INTERNAL_ERROR, 0UL, 0, 0U);
        return;
    }
    if (info.low_hw_valid != 0U) { flags |= 0x01UL; }
    if (info.high_hw_valid != 0U) { flags |= 0x02UL; }
    if (info.low_valid != 0U) { flags |= 0x04UL; }
    if (info.high_valid != 0U) { flags |= 0x08UL; }

    payload[0] = (uint8_t)info.active_slot;
    payload[1] = (uint8_t)info.inactive_slot;
    payload[2] = info.ota_enabled;
    payload[3] = info.ota_locked;
    ota_put_le32(&payload[4], info.active_physical_base);
    ota_put_le32(&payload[8], info.inactive_physical_base);
    ota_put_le32(&payload[12], info.active_access_base);
    ota_put_le32(&payload[16], info.inactive_access_base);
    ota_put_le32(&payload[20], info.execution_vma);
    ota_put_le32(&payload[24], info.low_version);
    ota_put_le32(&payload[28], info.high_version);
    ota_put_le32(&payload[32], flags);
    ota_put_le32(&payload[36], info.fmc_ota_ctrl);
    ota_put_le32(&payload[40], info.fmc_ota_act_ver);
    ota_put_le32(&payload[44], info.max_image_size);
    ota_service_send_response(request, OTA_PROTO_OK, request->offset, payload, sizeof(payload));
}

static void ota_service_handle_start(const ota_protocol_frame_t *request)
{
    ota_image_header_t header;
    ota_status_t status;
    ota_slot_t target;
    uint8_t payload[12] = {0};

    if (s_service.update_session)
    {
        ota_service_send_response(request, OTA_PROTO_SESSION_BUSY, 0UL, 0, 0U);
        return;
    }
    if (request->length != sizeof(header))
    {
        ota_service_send_response(request, OTA_PROTO_BAD_LENGTH, 0UL, 0, 0U);
        return;
    }

    (void)memcpy(&header, request->payload, sizeof(header));
    status = ota_begin_update(&header);
    if (status != OTA_OK)
    {
        ota_service_send_response(request, ota_service_map_status(status), 0UL, 0, 0U);
        return;
    }

    s_service.update_session = true;
    target = ota_update_target_slot();
    payload[0] = (uint8_t)target;
    ota_put_le32(&payload[4], ota_get_slot_physical_base(target));
    ota_put_le32(&payload[8], header.image_size);
    ota_service_send_response(request, OTA_PROTO_OK, 0UL, payload, sizeof(payload));
}

static void ota_service_handle_data(const ota_protocol_frame_t *request)
{
    ota_update_progress_t progress;
    ota_status_t status;

    if (!s_service.update_session)
    {
        ota_service_send_response(request, OTA_PROTO_SESSION_REQUIRED, 0UL, 0, 0U);
        return;
    }
    ota_update_get_progress(&progress);
    if (request->offset != progress.received_bytes)
    {
        ota_service_send_response(request, OTA_PROTO_BAD_OFFSET, progress.received_bytes, 0, 0U);
        return;
    }
    if (request->length == 0U)
    {
        ota_service_send_response(request, OTA_PROTO_BAD_LENGTH, progress.received_bytes, 0, 0U);
        return;
    }

    status = ota_write_chunk(request->payload, request->length);
    ota_update_get_progress(&progress);
    ota_service_send_response(
        request,
        ota_service_map_status(status),
        progress.received_bytes,
        0,
        0U);
}

static void ota_service_handle_finish(const ota_protocol_frame_t *request)
{
    ota_update_progress_t progress;
    ota_image_header_t target_header;
    ota_slot_t target;
    ota_status_t status;
    uint32_t version = 0UL;
    uint8_t payload[8] = {0};

    if (!s_service.update_session)
    {
        ota_service_send_response(request, OTA_PROTO_SESSION_REQUIRED, 0UL, 0, 0U);
        return;
    }
    ota_update_get_progress(&progress);
    if (request->offset != progress.received_bytes)
    {
        ota_service_send_response(request, OTA_PROTO_BAD_OFFSET, progress.received_bytes, 0, 0U);
        return;
    }

    target = progress.target_slot;
    status = ota_finish_update();
    if (status != OTA_OK)
    {
        ota_service_send_response(request, ota_service_map_status(status), progress.received_bytes, 0, 0U);
        return;
    }
    if (ota_read_slot_header(target, &target_header) == OTA_OK)
    {
        version = target_header.version;
    }
    s_service.update_session = false;
    payload[0] = (uint8_t)target;
    ota_put_le32(&payload[4], version);
    ota_service_send_response(request, OTA_PROTO_WAIT_POR, progress.received_bytes, payload, sizeof(payload));
}

static void ota_service_handle_abort(const ota_protocol_frame_t *request)
{
    (void)ota_abort_update();
    s_service.update_session = false;
    s_service.last_error = OTA_PROTO_CANCELLED;
    ota_service_send_response(request, OTA_PROTO_OK, 0UL, 0, 0U);
}

static void ota_service_handle_status(const ota_protocol_frame_t *request)
{
    ota_update_progress_t progress;
    uint8_t payload[20] = {0};

    ota_update_get_progress(&progress);
    payload[0] = s_service.update_session ? 1U : 0U;
    payload[1] = (uint8_t)progress.target_slot;
    ota_put_le32(&payload[4], progress.received_bytes);
    ota_put_le32(&payload[8], progress.image_size);
    ota_put_le32(&payload[12], s_service.expected_sequence);
    ota_put_le32(&payload[16], (uint32_t)s_service.last_error);
    ota_service_send_response(request, OTA_PROTO_OK, request->offset, payload, sizeof(payload));
}

static void ota_service_handle_frame(const ota_protocol_frame_t *request)
{
    if (s_service.have_cached_response &&
        ota_protocol_frame_equal(request, &s_service.last_request))
    {
        (void)ota_uart_write(s_service.response_bytes, s_service.response_length);
        return;
    }

    if ((request->flags != 0U) || (request->status != OTA_PROTO_OK))
    {
        ota_service_send_response(request, OTA_PROTO_INVALID_FRAME, 0UL, 0, 0U);
        return;
    }
    if (request->command == OTA_CMD_HELLO)
    {
        ota_service_handle_hello(request);
        return;
    }
    if ((!s_service.sequence_valid) || (request->sequence != s_service.expected_sequence))
    {
        ota_service_send_response(
            request,
            OTA_PROTO_BAD_SEQUENCE,
            s_service.sequence_valid ? s_service.expected_sequence : 0UL,
            0,
            0U);
        return;
    }
    ++s_service.expected_sequence;

    switch (request->command)
    {
        case OTA_CMD_GET_INFO:
            ota_service_handle_get_info(request);
            break;
        case OTA_CMD_START_UPDATE:
            ota_service_handle_start(request);
            break;
        case OTA_CMD_DATA:
            ota_service_handle_data(request);
            break;
        case OTA_CMD_FINISH:
            ota_service_handle_finish(request);
            break;
        case OTA_CMD_ABORT:
            ota_service_handle_abort(request);
            break;
        case OTA_CMD_GET_STATUS:
            ota_service_handle_status(request);
            break;
        default:
            ota_service_send_response(request, OTA_PROTO_UNSUPPORTED_COMMAND, 0UL, 0, 0U);
            break;
    }
}

void ota_service_init(void)
{
    (void)memset(&s_service, 0, sizeof(s_service));
    ota_protocol_decoder_init(&s_service.decoder);
    s_service.last_error = OTA_PROTO_OK;
}

void ota_service_poll(uint32_t now_ms)
{
    uint8_t byte;
    uint32_t overflow_count = ota_uart_overflow_count();

    if (overflow_count != s_service.last_uart_overflow)
    {
        s_service.last_uart_overflow = overflow_count;
        s_service.last_error = OTA_PROTO_BAD_LENGTH;
    }
    while (ota_uart_read_byte(&byte))
    {
        ota_decode_result_t result = ota_protocol_decoder_push(
            &s_service.decoder,
            byte,
            &s_service.request);
        if (result == OTA_DECODE_FRAME)
        {
            s_service.last_activity_ms = now_ms;
            ota_service_handle_frame(&s_service.request);
            /*
             * START_UPDATE and FINISH may spend a long time in synchronous
             * Flash operations. Refresh both values after the handler so a
             * successful long erase is not immediately mistaken for a
             * five-second idle session timeout.
             */
            now_ms = ota_time_now_ms();
            s_service.last_activity_ms = now_ms;
        }
        else if (result == OTA_DECODE_DROPPED)
        {
            s_service.last_error = s_service.decoder.last_error;
        }
    }

    if (s_service.update_session &&
        ((uint32_t)(now_ms - s_service.last_activity_ms) > OTA_SERVICE_SESSION_TIMEOUT_MS))
    {
        (void)ota_abort_update();
        s_service.update_session = false;
        s_service.last_error = OTA_PROTO_TIMEOUT;
    }
}

bool ota_service_text_enabled(void)
{
    return !s_service.binary_mode;
}
