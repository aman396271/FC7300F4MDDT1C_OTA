from __future__ import annotations

import struct

import pytest

from ..protocol import (
    CRC_STRUCT,
    HEADER_STRUCT,
    MAGIC,
    Command,
    Frame,
    FrameStreamDecoder,
    ProtocolError,
    Status,
    cobs_encode,
    crc32,
    decode_frame,
    encode_frame,
)


def test_frame_roundtrip_and_zero_payload_bytes() -> None:
    frame = Frame(Command.DATA, 7, 128, b"a\x00b\x00c")
    encoded = encode_frame(frame)
    assert encoded.endswith(b"\x00")
    assert decode_frame(encoded[:-1]) == frame


def test_stream_handles_split_and_glued_frames() -> None:
    encoded = encode_frame(Frame(Command.HELLO, 0)) + encode_frame(Frame(Command.GET_INFO, 1))
    decoder = FrameStreamDecoder()
    frames = []
    for split in (encoded[:3], encoded[3:11], encoded[11:]):
        frames.extend(decoder.feed(split))
    assert [frame.command for frame in frames] == [Command.HELLO, Command.GET_INFO]


def test_crc_error_is_detected() -> None:
    encoded = bytearray(encode_frame(Frame(Command.GET_INFO, 3)))
    encoded[-3] ^= 0x55
    with pytest.raises(ProtocolError) as exc:
        decode_frame(bytes(encoded[:-1]))
    assert exc.value.status == Status.BAD_CRC


def test_declared_length_is_validated() -> None:
    body = HEADER_STRUCT.pack(MAGIC, 1, Command.DATA, 0, 0, 1, 0, 10, 0) + b"abc"
    encoded = cobs_encode(body + CRC_STRUCT.pack(crc32(body)))
    with pytest.raises(ProtocolError) as exc:
        decode_frame(encoded)
    assert exc.value.status == Status.BAD_LENGTH
