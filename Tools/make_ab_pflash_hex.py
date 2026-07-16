#!/usr/bin/env python3
"""Validate two packed FC7300 OTA slot binaries and merge them into one HEX."""

from __future__ import annotations

import argparse
import binascii
import hashlib
import json
import struct
from pathlib import Path
from typing import Dict, Iterable, Mapping


BANK0_BASE = 0x01000000
BANK1_BASE = 0x01200000
SLOT_SIZE = 0x00200000
HEADER_OFFSET = 0x001FF000
HEADER_SIZE = 0x80
IMAGE_MAGIC = 0x46435441
VALID_FLAG = 0xA5A55A5A
VALID_CODE = 0xFC60FACE88886666


def checksum(values: Iterable[int]) -> int:
    return (-sum(values)) & 0xFF


def ihex_record(address: int, record_type: int, data: bytes) -> str:
    body = [len(data), (address >> 8) & 0xFF, address & 0xFF, record_type, *data]
    return ":" + "".join(f"{value:02X}" for value in body) + f"{checksum(body):02X}"


def sparse_slot_memory(image: bytes, base: int, record_size: int = 32) -> Dict[int, int]:
    memory: Dict[int, int] = {}
    for offset in range(0, len(image), record_size):
        chunk = image[offset : offset + record_size]
        if any(value != 0xFF for value in chunk):
            for index, value in enumerate(chunk):
                memory[base + offset + index] = value
    return memory


def write_ihex(memory: Mapping[int, int], path: Path, record_size: int = 32) -> int:
    lines = []
    addresses = sorted(memory)
    index = 0
    upper = None
    data_record_count = 0
    while index < len(addresses):
        start = addresses[index]
        current_upper = start >> 16
        if current_upper != upper:
            lines.append(ihex_record(0, 0x04, struct.pack(">H", current_upper)))
            upper = current_upper
        chunk = bytearray([memory[start]])
        index += 1
        while index < len(addresses) and len(chunk) < record_size:
            expected = start + len(chunk)
            if addresses[index] != expected or (addresses[index] >> 16) != upper:
                break
            chunk.append(memory[addresses[index]])
            index += 1
        lines.append(ihex_record(start & 0xFFFF, 0x00, bytes(chunk)))
        data_record_count += 1
    lines.append(ihex_record(0, 0x01, b""))
    path.write_text("\n".join(lines) + "\n", encoding="ascii")
    return data_record_count


def read_ihex(path: Path) -> Dict[int, int]:
    memory: Dict[int, int] = {}
    base = 0
    eof_seen = False
    for line_number, line in enumerate(path.read_text(encoding="ascii").splitlines(), 1):
        record = bytes.fromhex(line[1:]) if line.startswith(":") else b""
        if len(record) < 5 or len(record) != record[0] + 5 or (sum(record) & 0xFF):
            raise ValueError(f"{path}:{line_number}: invalid Intel HEX record")
        length = record[0]
        address = (record[1] << 8) | record[2]
        record_type = record[3]
        data = record[4 : 4 + length]
        if record_type == 0x00:
            for index, value in enumerate(data):
                memory[base + address + index] = value
        elif record_type == 0x01:
            eof_seen = True
            break
        elif record_type == 0x04 and length == 2:
            base = int.from_bytes(data, "big") << 16
        else:
            raise ValueError(f"{path}:{line_number}: unsupported Intel HEX record type {record_type}")
    if not eof_seen:
        raise ValueError(f"{path}: missing Intel HEX EOF record")
    return memory


def crc32(data: bytes) -> int:
    return binascii.crc32(data) & 0xFFFFFFFF


def inspect_slot(path: Path, expected_base: int) -> tuple[bytes, dict]:
    image = path.read_bytes()
    if len(image) != SLOT_SIZE:
        raise ValueError(f"{path}: slot image must be {SLOT_SIZE} bytes, got {len(image)}")
    words = struct.unpack("<11I", image[HEADER_OFFSET : HEADER_OFFSET + 44])
    (
        version,
        version_inverted,
        valid_code_lo,
        valid_code_hi,
        magic,
        header_version,
        image_size,
        image_crc,
        timestamp,
        valid_flag,
        header_crc,
    ) = words
    valid_code = (valid_code_hi << 32) | valid_code_lo
    if magic != IMAGE_MAGIC:
        raise ValueError(f"{path}: invalid image magic 0x{magic:08X}")
    if version_inverted != ((~version) & 0xFFFFFFFF):
        raise ValueError(f"{path}: version complement mismatch")
    if valid_code != VALID_CODE:
        raise ValueError(f"{path}: invalid F4MDD OTA valid code 0x{valid_code:016X}")
    if valid_flag != VALID_FLAG:
        raise ValueError(f"{path}: invalid software valid flag 0x{valid_flag:08X}")
    if image_size != HEADER_OFFSET:
        raise ValueError(f"{path}: expected payload size 0x{HEADER_OFFSET:X}, got 0x{image_size:X}")
    if crc32(image[:image_size]) != image_crc:
        raise ValueError(f"{path}: payload CRC mismatch")
    header = bytearray(image[HEADER_OFFSET : HEADER_OFFSET + HEADER_SIZE])
    header[40:44] = b"\x00\x00\x00\x00"
    if crc32(header) != header_crc:
        raise ValueError(f"{path}: header CRC mismatch")
    stack_pointer, reset_handler = struct.unpack_from("<II", image, 0)
    reset_address = reset_handler & ~1
    if not BANK0_BASE <= reset_address < BANK0_BASE + SLOT_SIZE:
        raise ValueError(
            f"{path}: reset vector 0x{reset_handler:08X} is not linked to the common low VMA"
        )
    return image, {
        "source": path.name,
        "physical_base": f"0x{expected_base:08X}",
        "logical_vma": f"0x{BANK0_BASE:08X}",
        "version": f"0x{version:08X}",
        "version_value": version,
        "header_version": f"0x{header_version:08X}",
        "stack_pointer": f"0x{stack_pointer:08X}",
        "reset_handler": f"0x{reset_handler:08X}",
        "header_address": f"0x{expected_base + HEADER_OFFSET:08X}",
        "indicator_address": f"0x{expected_base + HEADER_OFFSET:08X}",
        "payload_crc32": f"0x{image_crc:08X}",
        "header_crc32": f"0x{header_crc:08X}",
        "sha256": hashlib.sha256(image).hexdigest().upper(),
    }


def main() -> int:
    parser = argparse.ArgumentParser(description="Create one sparse FC7300 A+B PFlash Intel HEX")
    parser.add_argument("--a-bin", type=Path, required=True)
    parser.add_argument("--b-bin", type=Path, required=True)
    parser.add_argument("--a-output-hex", type=Path)
    parser.add_argument("--b-output-hex", type=Path)
    parser.add_argument("--output-hex", type=Path, required=True)
    parser.add_argument("--report", type=Path, required=True)
    args = parser.parse_args()

    a_image, a_report = inspect_slot(args.a_bin, BANK0_BASE)
    b_image, b_report = inspect_slot(args.b_bin, BANK1_BASE)
    if a_report["version_value"] >= b_report["version_value"]:
        raise SystemExit("A version must be lower than B version for the POR swap demo")
    if a_image == b_image:
        raise SystemExit("A and B slot images are identical; observable application variants are required")

    a_memory = sparse_slot_memory(a_image, BANK0_BASE)
    b_memory = sparse_slot_memory(b_image, BANK1_BASE)
    overlap = set(a_memory).intersection(b_memory)
    if overlap:
        raise SystemExit(f"A/B HEX overlap at 0x{min(overlap):08X}")
    if args.a_output_hex:
        args.a_output_hex.parent.mkdir(parents=True, exist_ok=True)
        write_ihex(a_memory, args.a_output_hex)
        if read_ihex(args.a_output_hex) != a_memory:
            raise SystemExit("generated APP A Bank0 HEX readback mismatch")
        a_report["slot_hex"] = args.a_output_hex.name
        a_report["slot_hex_sha256"] = hashlib.sha256(args.a_output_hex.read_bytes()).hexdigest().upper()
    if args.b_output_hex:
        args.b_output_hex.parent.mkdir(parents=True, exist_ok=True)
        write_ihex(b_memory, args.b_output_hex)
        if read_ihex(args.b_output_hex) != b_memory:
            raise SystemExit("generated APP B Bank1 HEX readback mismatch")
        b_report["slot_hex"] = args.b_output_hex.name
        b_report["slot_hex_sha256"] = hashlib.sha256(args.b_output_hex.read_bytes()).hexdigest().upper()
    memory = dict(a_memory)
    memory.update(b_memory)
    args.output_hex.parent.mkdir(parents=True, exist_ok=True)
    data_records = write_ihex(memory, args.output_hex)
    if read_ihex(args.output_hex) != memory:
        raise SystemExit("generated Intel HEX readback does not match A/B source memory")
    a_report.pop("version_value")
    b_report.pop("version_value")
    report = {
        "chip": "FC7300F4MDDT1C",
        "artifact": args.output_hex.name,
        "format": "sparse Intel HEX; erase both 2 MB PFlash banks before programming",
        "contains_nvr": False,
        "bank0": a_report,
        "bank1": b_report,
        "hex_data_records": data_records,
        "hex_sha256": hashlib.sha256(args.output_hex.read_bytes()).hexdigest().upper(),
        "test_sequence": [
            "Program this A+B PFlash HEX while NVR is still default/OTA-disabled.",
            "POR and observe APP A / LED1 slow blink.",
            "Program only the complete OTA NVR HEX without mass-erasing PFlash.",
            "POR and observe APP B / LED2 fast blink.",
        ],
    }
    args.report.write_text(json.dumps(report, indent=2) + "\n", encoding="utf-8")
    print(f"ab_hex={args.output_hex}")
    print(f"report={args.report}")
    print(f"A={a_report['version']} @ 0x{BANK0_BASE:08X}")
    print(f"B={b_report['version']} @ 0x{BANK1_BASE:08X}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
