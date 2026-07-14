#!/usr/bin/env python3
"""Patch FC7300 hardware-OTA demo binary headers.

Input is a raw binary linked at the Low-bank VMA (0x01000000).  The script
computes the payload CRC from offset 0 to OTA_HEADER_OFFSET, writes a software
header at OTA_HEADER_OFFSET, and emits:

  * <prefix>_low.bin  - program at 0x01000000
  * <prefix>_high.bin - same bytes, program at 0x01200000
  * <prefix>.pkg      - transport package: header + payload

Use objcopy or the IDE to convert ELF to a raw binary before running this tool.
"""

import argparse
import binascii
import struct
from pathlib import Path


SLOT_SIZE = 0x00200000
HEADER_OFFSET = 0x001FF000
NVR_VERSION_OFFSET = 0x000FF008
HEADER_SIZE = 0x80
IMAGE_MAGIC = 0x46435441
HEADER_VERSION = 0x00010000
VALID_FLAG = 0xA5A55A5A
VALID_CODE_F4MDD = 0xFC60_FACE_8888_6666


def align_up(value: int, alignment: int) -> int:
    return (value + alignment - 1) & ~(alignment - 1)


def crc32(data: bytes) -> int:
    return binascii.crc32(data) & 0xFFFFFFFF


def make_header(version: int, payload: bytes, timestamp: int) -> bytes:
    version_word = version & 0xFFFFFFFF
    valid_code_lo = VALID_CODE_F4MDD & 0xFFFFFFFF
    valid_code_hi = (VALID_CODE_F4MDD >> 32) & 0xFFFFFFFF
    fields = [
        IMAGE_MAGIC,
        HEADER_VERSION,
        version_word,
        (~version_word) & 0xFFFFFFFF,
        valid_code_lo,
        valid_code_hi,
        len(payload),
        crc32(payload),
        timestamp,
        VALID_FLAG,
        0,
    ]
    fields.extend([0xFFFFFFFF] * 21)
    header = bytearray(struct.pack("<32I", *fields))
    struct.pack_into("<I", header, 40, crc32(header))
    return bytes(header)


def main() -> int:
    parser = argparse.ArgumentParser()
    parser.add_argument("input_bin", type=Path)
    parser.add_argument("--version", required=True, help="32-bit version, e.g. 0x00020000")
    parser.add_argument("--timestamp", default="0", help="optional 32-bit build timestamp")
    parser.add_argument("--out-prefix", type=Path)
    args = parser.parse_args()

    image = bytearray(args.input_bin.read_bytes())
    if len(image) > HEADER_OFFSET:
        existing_header = image[HEADER_OFFSET:]
        if len(existing_header) != HEADER_SIZE:
            raise SystemExit(
                "image contains loadable data beyond the reserved OTA header: "
                f"tail size {len(existing_header)} != {HEADER_SIZE}"
            )
        if existing_header[:4] != struct.pack("<I", IMAGE_MAGIC):
            raise SystemExit("image tail is not the expected linked OTA header")
        del image[HEADER_OFFSET:]

    image.extend(b"\xFF" * (HEADER_OFFSET - len(image)))
    payload = bytes(image[:HEADER_OFFSET])
    header = make_header(int(args.version, 0), payload, int(args.timestamp, 0))
    if len(header) != HEADER_SIZE:
        raise SystemExit("internal header size mismatch")

    image.extend(header)
    image.extend(b"\xFF" * (SLOT_SIZE - len(image)))

    prefix = args.out_prefix or args.input_bin.with_suffix("")
    prefix.parent.mkdir(parents=True, exist_ok=True)
    low_path = prefix.with_name(prefix.name + "_low.bin")
    high_path = prefix.with_name(prefix.name + "_high.bin")
    pkg_path = prefix.with_name(prefix.name + ".pkg")

    low_path.write_bytes(image)
    high_path.write_bytes(image)
    pkg_path.write_bytes(header + payload)

    print(f"low_bin={low_path}")
    print(f"high_bin={high_path}")
    print(f"package={pkg_path}")
    print(f"version=0x{int(args.version, 0):08X}")
    print(f"header_offset=0x{HEADER_OFFSET:08X}")
    print(f"nvr_version_offset=0x{NVR_VERSION_OFFSET:08X}")
    print(f"payload_crc=0x{crc32(payload):08X}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
