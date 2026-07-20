"""COBS-framed FC7300 UART OTA protocol primitives."""

from __future__ import annotations

import binascii
import enum
import struct
from dataclasses import dataclass


MAGIC = 0x544F
PROTOCOL_VERSION = 1
MAX_PAYLOAD = 512
HEADER_STRUCT = struct.Struct("<HBBBBIIHH")
CRC_STRUCT = struct.Struct("<I")
MAX_RAW_FRAME = HEADER_STRUCT.size + MAX_PAYLOAD + CRC_STRUCT.size
MAX_ENCODED_FRAME = MAX_RAW_FRAME + (MAX_RAW_FRAME // 254) + 2
INFO_STRUCT = struct.Struct("<BBBBIIIIIIIIIII")
HELLO_STRUCT = struct.Struct("<HHI")
START_RESPONSE_STRUCT = struct.Struct("<B3xII")
STATUS_STRUCT = struct.Struct("<BBHIIIi")


class Command(enum.IntEnum):
    HELLO = 0x01
    GET_INFO = 0x02
    START_UPDATE = 0x10
    DATA = 0x11
    FINISH = 0x12
    ABORT = 0x13
    GET_STATUS = 0x14


class Status(enum.IntEnum):
    OK = 0
    WAIT_POR = 1
    INVALID_FRAME = 0x100
    BAD_CRC = 0x101
    BAD_LENGTH = 0x102
    UNSUPPORTED_VERSION = 0x103
    UNSUPPORTED_COMMAND = 0x104
    BAD_SEQUENCE = 0x105
    BAD_OFFSET = 0x106
    SESSION_REQUIRED = 0x107
    SESSION_BUSY = 0x108
    OTA_NOT_ENABLED = 0x109
    ACTIVE_BANK_PROTECTED = 0x10A
    INVALID_PACKAGE = 0x10B
    VERSION_REJECTED = 0x10C
    FLASH_ERROR = 0x10D
    IMAGE_CRC_ERROR = 0x10E
    TIMEOUT = 0x10F
    CANCELLED = 0x110
    INTERNAL_ERROR = 0x1FF


FLAG_RESPONSE = 0x01
FLAG_ERROR = 0x02


class ProtocolError(ValueError):
    def __init__(self, message: str, status: Status = Status.INVALID_FRAME):
        super().__init__(message)
        self.status = status


@dataclass(frozen=True)
class Frame:
    command: Command
    sequence: int
    offset: int = 0
    payload: bytes = b""
    status: Status = Status.OK
    flags: int = 0
    version: int = PROTOCOL_VERSION

    @property
    def is_response(self) -> bool:
        return bool(self.flags & FLAG_RESPONSE)


def crc32(data: bytes) -> int:
    return binascii.crc32(data) & 0xFFFFFFFF


def cobs_encode(data: bytes) -> bytes:
    output = bytearray(b"\x00")
    code_index = 0
    code = 1
    for value in data:
        if value == 0:
            output[code_index] = code
            code_index = len(output)
            output.append(0)
            code = 1
        else:
            output.append(value)
            code += 1
            if code == 0xFF:
                output[code_index] = code
                code_index = len(output)
                output.append(0)
                code = 1
    output[code_index] = code
    return bytes(output)


def cobs_decode(data: bytes) -> bytes:
    if not data:
        raise ProtocolError("empty COBS frame", Status.BAD_LENGTH)
    output = bytearray()
    index = 0
    while index < len(data):
        code = data[index]
        if code == 0:
            raise ProtocolError("zero byte inside COBS frame")
        index += 1
        end = index + code - 1
        if end > len(data):
            raise ProtocolError("truncated COBS block", Status.BAD_LENGTH)
        output.extend(data[index:end])
        index = end
        if code != 0xFF and index < len(data):
            output.append(0)
    return bytes(output)


def encode_frame(frame: Frame) -> bytes:
    payload = bytes(frame.payload)
    if len(payload) > MAX_PAYLOAD:
        raise ProtocolError("payload exceeds protocol maximum", Status.BAD_LENGTH)
    raw = HEADER_STRUCT.pack(
        MAGIC,
        frame.version,
        int(frame.command),
        frame.flags,
        0,
        frame.sequence & 0xFFFFFFFF,
        frame.offset & 0xFFFFFFFF,
        len(payload),
        int(frame.status),
    ) + payload
    return cobs_encode(raw + CRC_STRUCT.pack(crc32(raw))) + b"\x00"


def decode_frame(encoded: bytes) -> Frame:
    raw = cobs_decode(encoded)
    if len(raw) < HEADER_STRUCT.size + CRC_STRUCT.size:
        raise ProtocolError("frame shorter than fixed header", Status.BAD_LENGTH)
    body, crc_bytes = raw[:-CRC_STRUCT.size], raw[-CRC_STRUCT.size:]
    received_crc = CRC_STRUCT.unpack(crc_bytes)[0]
    if crc32(body) != received_crc:
        raise ProtocolError("frame CRC mismatch", Status.BAD_CRC)
    magic, version, command, flags, reserved, sequence, offset, length, status = HEADER_STRUCT.unpack_from(body)
    if magic != MAGIC or reserved != 0:
        raise ProtocolError("invalid frame header")
    if version != PROTOCOL_VERSION:
        raise ProtocolError("unsupported protocol version", Status.UNSUPPORTED_VERSION)
    if length > MAX_PAYLOAD or len(body) != HEADER_STRUCT.size + length:
        raise ProtocolError("payload length mismatch", Status.BAD_LENGTH)
    try:
        command_value = Command(command)
        status_value = Status(status)
    except ValueError as exc:
        raise ProtocolError("unknown command or status") from exc
    return Frame(
        command=command_value,
        sequence=sequence,
        offset=offset,
        payload=body[HEADER_STRUCT.size:],
        status=status_value,
        flags=flags,
        version=version,
    )


class FrameStreamDecoder:
    def __init__(self) -> None:
        self._buffer = bytearray()
        self.dropped_frames = 0

    def feed(self, data: bytes) -> list[Frame]:
        frames: list[Frame] = []
        for value in data:
            if value == 0:
                if self._buffer:
                    try:
                        frames.append(decode_frame(bytes(self._buffer)))
                    except ProtocolError:
                        self.dropped_frames += 1
                    self._buffer.clear()
                continue
            if len(self._buffer) >= MAX_ENCODED_FRAME:
                self._buffer.clear()
                self.dropped_frames += 1
            else:
                self._buffer.append(value)
        return frames
