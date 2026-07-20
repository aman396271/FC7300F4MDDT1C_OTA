"""Parser for .pkg files emitted by pack_hw_ota_image.py."""

from __future__ import annotations

import binascii
import struct
from dataclasses import dataclass
from pathlib import Path


HEADER_SIZE = 0x80
HEADER_OFFSET = 0x001FF000
IMAGE_MAGIC = 0x46435441
HEADER_VERSION = 0x00010000
VALID_FLAG = 0xA5A55A5A
VALID_CODE_LO = 0x88886666
VALID_CODE_HI = 0xFC60FACE
HEADER_STRUCT = struct.Struct("<32I")


class PackageError(ValueError):
    pass


def crc32(data: bytes) -> int:
    return binascii.crc32(data) & 0xFFFFFFFF


@dataclass(frozen=True)
class PackageHeader:
    version: int
    image_size: int
    image_crc32: int
    build_timestamp: int
    header_crc32: int
    raw: bytes


@dataclass(frozen=True)
class OtaPackage:
    header: PackageHeader
    payload: bytes
    path: Path | None = None

    @classmethod
    def from_bytes(cls, data: bytes, path: Path | None = None) -> "OtaPackage":
        if len(data) < HEADER_SIZE:
            raise PackageError("package is shorter than its 128-byte header")
        raw_header = data[:HEADER_SIZE]
        fields = HEADER_STRUCT.unpack(raw_header)
        version, inverted, valid_lo, valid_hi, magic, header_version = fields[:6]
        image_size, image_crc, timestamp, valid_flag, header_crc = fields[6:11]
        if not 0 < version < 0xFFFFFFFF or inverted != ((~version) & 0xFFFFFFFF):
            raise PackageError("invalid version record")
        if (valid_lo, valid_hi) != (VALID_CODE_LO, VALID_CODE_HI):
            raise PackageError("invalid FC7300F4MDD hardware valid code")
        if magic != IMAGE_MAGIC or header_version != HEADER_VERSION or valid_flag != VALID_FLAG:
            raise PackageError("unsupported or invalid OTA header")
        if not 0 < image_size <= HEADER_OFFSET:
            raise PackageError("image size is outside the slot payload region")
        if len(data) != HEADER_SIZE + image_size:
            raise PackageError("package length does not match image_size")
        header_for_crc = bytearray(raw_header)
        struct.pack_into("<I", header_for_crc, 40, 0)
        if crc32(header_for_crc) != header_crc:
            raise PackageError("header CRC mismatch")
        payload = data[HEADER_SIZE:]
        if crc32(payload) != image_crc:
            raise PackageError("payload CRC mismatch")
        return cls(PackageHeader(version, image_size, image_crc, timestamp, header_crc, raw_header), payload, path)

    @classmethod
    def load(cls, path: str | Path) -> "OtaPackage":
        package_path = Path(path)
        return cls.from_bytes(package_path.read_bytes(), package_path)
