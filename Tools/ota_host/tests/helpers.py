from __future__ import annotations

import struct

from ..package import HEADER_STRUCT, OtaPackage, crc32


def make_package(version: int = 2, size: int = 1300) -> OtaPackage:
    payload = bytes((index * 37 + 11) & 0xFF for index in range(size))
    fields = [
        version,
        (~version) & 0xFFFFFFFF,
        0x88886666,
        0xFC60FACE,
        0x46435441,
        0x00010000,
        len(payload),
        crc32(payload),
        0,
        0xA5A55A5A,
        0,
    ]
    fields.extend([0xFFFFFFFF] * 21)
    header = bytearray(HEADER_STRUCT.pack(*fields))
    struct.pack_into("<I", header, 40, crc32(header))
    return OtaPackage.from_bytes(bytes(header) + payload)
