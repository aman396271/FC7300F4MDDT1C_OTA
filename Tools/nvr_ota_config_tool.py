#!/usr/bin/env python3
"""Generate FC7300 hardware OTA NVR Intel HEX records.

The tool encodes OTAC0 and OTAC_HIGH0 from a small JSON config.  It writes only
the OTA NVR words by default; for production, merge the generated values into a
known-good full NVR image using the official Flagchip flow.
"""

from __future__ import annotations

import argparse
import json
import re
import struct
from dataclasses import dataclass
from pathlib import Path
from typing import Any, Dict, Iterable, List, Tuple


DEFAULT_CONFIG: Dict[str, Any] = {
    "chip": "FC7300F4MDDT1C",
    "rm_source": "FC7300F4MxxxT1C Reference Manual_V0.3.1_NVR.pdf, Table 54/Table 55",
    "nvr_base": "0x04400000",
    "otac0_offset": "0x100",
    "otac_high0_offset": "0x108",
    "bank0_base": "0x01000000",
    "bank1_base": "0x01200000",
    "bank_size": "0x00200000",
    "ota0": {
        "enabled": True,
        "enable_code": "0b01010",
        "low_start": "0x01000000",
        "low_end": "0x010FFFFF",
        "high_start": "0x01100000",
        "high_end": "0x011FFFFF",
        "version_offset": "0x000FF008",
        "version_select": "high",
    },
    "ota_indicator": {
        "enabled": True,
        "layout": "version_then_valid_code",
        "low_version": "0x00010000",
        "high_version": "0x00010100",
        "valid_code_f4mdd": "0xFC60FACE88886666",
        "valid_code_f4mds": "0xFC62FACE88886666",
    },
    "notes": [
        "F4MDD uses 2MB Bank0/1 swap. OTAC0[51:32] is a PFlash logical offset inside the selected 1MB half, not a full 2MB bank offset.",
        "With version_select=high, version_offset 0x000FF008 lands at effective bank offset 0x001FF008.",
        "Table 55 OTA content requires a valid code plus a 32-bit version with the upper 32 bits equal to bitwise NOT of the version.",
        "This tool writes OTAC0 at NVR offset 0x100 and OTAC_HIGH0 at 0x108 by default; verify these offsets against the RM/toolchain.",
    ],
}

OTA_HALF_SIZE = 0x100000
OTA_BANK_SIZE = 0x200000
OTA_ALIGN = 0x2000
OTAC_ENABLE_CODE = 0x0A
VERSION_SELECT_LOWER = 0xAA
VERSION_SELECT_HIGH = 0x55
VALID_CODE_F4MDD = 0xFC60_FACE_8888_6666
VALID_CODE_F4MDS = 0xFC62_FACE_8888_6666


def parse_int(value: Any, field_name: str) -> int:
    if isinstance(value, int):
        return value
    if not isinstance(value, str):
        raise ValueError(f"{field_name}: expected int or string, got {type(value).__name__}")

    text = value.strip().replace("_", "")
    match = re.fullmatch(r"([0-9]+)([kKmM])?", text)
    if match:
        number = int(match.group(1), 10)
        suffix = match.group(2)
        if suffix in ("k", "K"):
            number *= 1024
        elif suffix in ("m", "M"):
            number *= 1024 * 1024
        return number

    return int(text, 0)


def as_hex(value: int, width: int = 8) -> str:
    return f"0x{value:0{width}X}"


def bank_offset(address_or_offset: int) -> int:
    if address_or_offset < OTA_HALF_SIZE:
        return address_or_offset
    return address_or_offset & (OTA_HALF_SIZE - 1)


def block_index(address_or_offset: int, field_name: str) -> int:
    offset = bank_offset(address_or_offset)
    if (offset & (OTA_ALIGN - 1)) != 0:
        raise ValueError(f"{field_name}: {as_hex(address_or_offset)} is not 8KB aligned")
    index = offset >> 13
    if index > 0x7F:
        raise ValueError(f"{field_name}: 8KB block index {index} exceeds 7-bit OTAC field")
    return index


def end_block_index(address_or_offset: int, field_name: str) -> int:
    offset = bank_offset(address_or_offset)
    index = offset >> 13
    if index > 0x7F:
        raise ValueError(f"{field_name}: 8KB block index {index} exceeds 7-bit OTAC field")
    return index


def parse_version_select(value: Any) -> int:
    if isinstance(value, str):
        normalized = value.strip().lower()
        if normalized in ("lower", "low", "low_bank", "0xaa"):
            return VERSION_SELECT_LOWER
        if normalized in ("high", "high_bank", "upper"):
            return VERSION_SELECT_HIGH
    return parse_int(value, "ota0.version_select") & 0xFF


@dataclass
class OtaNvrValues:
    otac0: int
    otac_high0: int
    otac0_addr: int
    otac_high0_addr: int
    low_start_field: int
    low_end_field: int
    high_start_field: int
    high_end_field: int
    version_offset: int
    version_select: int
    effective_version_offset: int
    low_start_addr: int
    high_start_addr: int
    bank0_base: int
    bank1_base: int


@dataclass
class OtaIndicatorValues:
    low_addr: int
    high_addr: int
    low_version: int
    high_version: int
    low_data: bytes
    high_data: bytes
    layout: str
    valid_code: int


def build_values(config: Dict[str, Any]) -> OtaNvrValues:
    ota = config.get("ota0", {})
    nvr_base = parse_int(config.get("nvr_base", DEFAULT_CONFIG["nvr_base"]), "nvr_base")
    otac0_offset = parse_int(config.get("otac0_offset", DEFAULT_CONFIG["otac0_offset"]), "otac0_offset")
    otac_high0_offset = parse_int(
        config.get("otac_high0_offset", DEFAULT_CONFIG["otac_high0_offset"]),
        "otac_high0_offset",
    )
    bank0_base = parse_int(config.get("bank0_base", DEFAULT_CONFIG["bank0_base"]), "bank0_base")
    bank1_base = parse_int(config.get("bank1_base", DEFAULT_CONFIG["bank1_base"]), "bank1_base")
    bank_size = parse_int(config.get("bank_size", DEFAULT_CONFIG["bank_size"]), "bank_size")
    if bank_size != OTA_BANK_SIZE:
        raise ValueError("bank_size must be 0x00200000 for the F4MDD Bank0/1 OTA swap demo")

    enabled = bool(ota.get("enabled", True))
    enable_code = parse_int(ota.get("enable_code", OTAC_ENABLE_CODE), "ota0.enable_code")
    if not enabled:
        enable_code = 0
    if enable_code != OTAC_ENABLE_CODE and enabled:
        raise ValueError("ota0.enable_code must be 0b01010 / 0x0A when OTA is enabled")

    low_start = parse_int(ota.get("low_start", DEFAULT_CONFIG["ota0"]["low_start"]), "ota0.low_start")
    low_end = parse_int(ota.get("low_end", DEFAULT_CONFIG["ota0"]["low_end"]), "ota0.low_end")
    high_start = parse_int(ota.get("high_start", DEFAULT_CONFIG["ota0"]["high_start"]), "ota0.high_start")
    high_end = parse_int(ota.get("high_end", DEFAULT_CONFIG["ota0"]["high_end"]), "ota0.high_end")
    version_offset = parse_int(ota.get("version_offset", DEFAULT_CONFIG["ota0"]["version_offset"]), "ota0.version_offset")
    version_select = parse_version_select(ota.get("version_select", DEFAULT_CONFIG["ota0"]["version_select"]))

    if version_offset >= OTA_HALF_SIZE:
        raise ValueError("ota0.version_offset must be a logical offset inside the selected 1MB half")
    if (version_offset & 0x3) != 0:
        raise ValueError("ota0.version_offset should be word aligned")
    if version_offset + 16 > OTA_HALF_SIZE:
        raise ValueError("ota0.version_offset must leave room for the 16-byte OTA indicator")
    effective_version_offset = version_offset
    if version_select != VERSION_SELECT_LOWER:
        effective_version_offset += OTA_HALF_SIZE
    if effective_version_offset + 16 > OTA_BANK_SIZE:
        raise ValueError("effective OTA indicator offset must fit inside the 2MB bank")

    low_start_field = block_index(low_start, "ota0.low_start")
    low_end_field = end_block_index(low_end, "ota0.low_end")
    high_start_field = block_index(high_start, "ota0.high_start")
    high_end_field = end_block_index(high_end, "ota0.high_end")

    if low_end_field < low_start_field:
        raise ValueError("low_end must be >= low_start within the selected 1MB bank")
    if high_end_field < high_start_field:
        raise ValueError("high_end must be >= high_start within the selected 1MB bank")

    otac0 = (
        (enable_code & 0x1F)
        | ((low_start_field & 0x7F) << 8)
        | ((low_end_field & 0x7F) << 24)
        | ((version_offset & 0xFFFFF) << 32)
    )
    otac_high0 = (
        (version_select & 0xFF)
        | ((high_start_field & 0x7F) << 8)
        | ((high_end_field & 0x7F) << 24)
    )

    return OtaNvrValues(
        otac0=otac0,
        otac_high0=otac_high0,
        otac0_addr=nvr_base + otac0_offset,
        otac_high0_addr=nvr_base + otac_high0_offset,
        low_start_field=low_start_field,
        low_end_field=low_end_field,
        high_start_field=high_start_field,
        high_end_field=high_end_field,
        version_offset=version_offset,
        version_select=version_select,
        effective_version_offset=effective_version_offset,
        low_start_addr=low_start,
        high_start_addr=high_start,
        bank0_base=bank0_base,
        bank1_base=bank1_base,
    )


def make_ota_indicator(version: int, valid_code: int, layout: str) -> bytes:
    version_word = version & 0xFFFFFFFF
    version_pair = ((~version_word & 0xFFFFFFFF) << 32) | version_word
    if layout == "version_then_valid_code":
        return struct.pack("<QQ", version_pair, valid_code)
    if layout == "valid_code_then_version":
        return struct.pack("<QQ", valid_code, version_pair)
    raise ValueError("ota_indicator.layout must be version_then_valid_code or valid_code_then_version")


def build_indicator_values(config: Dict[str, Any], values: OtaNvrValues) -> OtaIndicatorValues | None:
    indicator = config.get("ota_indicator", {})
    if not bool(indicator.get("enabled", False)):
        return None

    layout = str(indicator.get("layout", DEFAULT_CONFIG["ota_indicator"]["layout"]))
    chip = str(config.get("chip", DEFAULT_CONFIG["chip"])).upper()
    default_valid_code = VALID_CODE_F4MDS if "F4MDS" in chip else VALID_CODE_F4MDD
    valid_code_key = "valid_code_f4mds" if "F4MDS" in chip else "valid_code_f4mdd"
    valid_code = parse_int(indicator.get(valid_code_key, default_valid_code), f"ota_indicator.{valid_code_key}")
    low_version = parse_int(indicator.get("low_version", DEFAULT_CONFIG["ota_indicator"]["low_version"]), "ota_indicator.low_version")
    high_version = parse_int(indicator.get("high_version", DEFAULT_CONFIG["ota_indicator"]["high_version"]), "ota_indicator.high_version")

    low_addr = values.bank0_base + values.effective_version_offset
    high_addr = values.bank1_base + values.effective_version_offset

    return OtaIndicatorValues(
        low_addr=low_addr,
        high_addr=high_addr,
        low_version=low_version,
        high_version=high_version,
        low_data=make_ota_indicator(low_version, valid_code, layout),
        high_data=make_ota_indicator(high_version, valid_code, layout),
        layout=layout,
        valid_code=valid_code,
    )


def effective_version_offset(raw_offset: int, version_select: int) -> int:
    if version_select == VERSION_SELECT_LOWER:
        return raw_offset
    return OTA_HALF_SIZE + raw_offset


def decode_values(otac0: int, otac_high0: int) -> Dict[str, Any]:
    raw_offset = (otac0 >> 32) & 0xFFFFF
    version_select = otac_high0 & 0xFF
    return {
        "otac0": as_hex(otac0, 16),
        "otac_high0": as_hex(otac_high0, 16),
        "ota_enabled": (otac0 & 0x1F) == OTAC_ENABLE_CODE,
        "enable_code": as_hex(otac0 & 0x1F, 2),
        "low_start_field": (otac0 >> 8) & 0x7F,
        "low_end_field": (otac0 >> 24) & 0x7F,
        "version_offset": as_hex(raw_offset, 5),
        "version_select_raw": as_hex(version_select, 2),
        "version_select_meaning": "lower" if version_select == VERSION_SELECT_LOWER else "high",
        "effective_bank_offset": as_hex(effective_version_offset(raw_offset, version_select), 6),
        "high_start_field": (otac_high0 >> 8) & 0x7F,
        "high_end_field": (otac_high0 >> 24) & 0x7F,
    }


def checksum(record_bytes: Iterable[int]) -> int:
    return ((~sum(record_bytes) + 1) & 0xFF)


def ihex_record(addr: int, record_type: int, data: bytes) -> str:
    length = len(data)
    body = [length, (addr >> 8) & 0xFF, addr & 0xFF, record_type] + list(data)
    return ":" + "".join(f"{byte:02X}" for byte in body) + f"{checksum(body):02X}"


def write_ihex(records: List[Tuple[int, bytes]], path: Path) -> None:
    lines: List[str] = []
    current_upper = None
    for addr, data in sorted(records, key=lambda item: item[0]):
        offset = 0
        while offset < len(data):
            absolute = addr + offset
            upper = absolute >> 16
            if upper != current_upper:
                lines.append(ihex_record(0, 0x04, struct.pack(">H", upper)))
                current_upper = upper
            chunk = data[offset : offset + 16]
            lines.append(ihex_record(absolute & 0xFFFF, 0x00, chunk))
            offset += len(chunk)
    lines.append(ihex_record(0, 0x01, b""))
    path.write_text("\n".join(lines) + "\n", encoding="ascii")


def values_to_records(values: OtaNvrValues) -> List[Tuple[int, bytes]]:
    return [
        (values.otac0_addr, struct.pack("<Q", values.otac0)),
        (values.otac_high0_addr, struct.pack("<Q", values.otac_high0)),
    ]


def indicator_to_records(indicator: OtaIndicatorValues | None) -> List[Tuple[int, bytes]]:
    if indicator is None:
        return []
    return [
        (indicator.low_addr, indicator.low_data),
        (indicator.high_addr, indicator.high_data),
    ]


def make_report(config: Dict[str, Any], values: OtaNvrValues, indicator: OtaIndicatorValues | None) -> Dict[str, Any]:
    report = {
        "chip": config.get("chip", DEFAULT_CONFIG["chip"]),
        "rm_source": config.get("rm_source", DEFAULT_CONFIG["rm_source"]),
        "nvr_records": [
            {
                "name": "OTAC0",
                "address": as_hex(values.otac0_addr),
                "value_le64": as_hex(values.otac0, 16),
                "bytes_little_endian": struct.pack("<Q", values.otac0).hex(" ").upper(),
            },
            {
                "name": "OTAC_HIGH0",
                "address": as_hex(values.otac_high0_addr),
                "value_le64": as_hex(values.otac_high0, 16),
                "bytes_little_endian": struct.pack("<Q", values.otac_high0).hex(" ").upper(),
            },
        ],
        "decoded": decode_values(values.otac0, values.otac_high0),
        "ota_indicator_records": [],
        "warnings": [
            "Verify NVR offsets 0x100/0x108 with the FC7300F4MDDT1C RM and programming tool before production use.",
            "Generated HEX writes only OTAC0/OTAC_HIGH0 records; do not erase unrelated NVR contents accidentally.",
            "OTA indicator HEX writes PFlash content, not NVR content. Program or merge it with the application image at the same relative offset in both OTA banks.",
        ],
    }
    if indicator is not None:
        report["ota_indicator_records"] = [
            {
                "name": "PFLASH0_OTA_INDICATOR",
                "address": as_hex(indicator.low_addr),
                "version": as_hex(indicator.low_version),
                "valid_code": as_hex(indicator.valid_code, 16),
                "layout": indicator.layout,
                "bytes_little_endian": indicator.low_data.hex(" ").upper(),
            },
            {
                "name": "PFLASH1_OTA_INDICATOR",
                "address": as_hex(indicator.high_addr),
                "version": as_hex(indicator.high_version),
                "valid_code": as_hex(indicator.valid_code, 16),
                "layout": indicator.layout,
                "bytes_little_endian": indicator.high_data.hex(" ").upper(),
            },
        ]
    return report


def load_config(path: Path | None) -> Dict[str, Any]:
    if path is None:
        return json.loads(json.dumps(DEFAULT_CONFIG))
    return json.loads(path.read_text(encoding="utf-8"))


def command_init(args: argparse.Namespace) -> int:
    output = Path(args.output)
    output.write_text(json.dumps(DEFAULT_CONFIG, indent=2) + "\n", encoding="utf-8")
    print(f"wrote {output}")
    return 0


def command_generate(args: argparse.Namespace) -> int:
    config = load_config(Path(args.config) if args.config else None)
    values = build_values(config)
    indicator = build_indicator_values(config, values)
    report = make_report(config, values, indicator)

    if args.output_hex:
        write_ihex(values_to_records(values), Path(args.output_hex))
    if args.output_ota_indicator_hex:
        if indicator is None:
            raise ValueError("ota_indicator.enabled must be true when --output-ota-indicator-hex is used")
        write_ihex(indicator_to_records(indicator), Path(args.output_ota_indicator_hex))
    if args.output_bin:
        Path(args.output_bin).write_bytes(struct.pack("<QQ", values.otac0, values.otac_high0))
    if args.output_ota_indicator_bin:
        if indicator is None:
            raise ValueError("ota_indicator.enabled must be true when --output-ota-indicator-bin is used")
        Path(args.output_ota_indicator_bin).write_bytes(indicator.low_data + indicator.high_data)
    if args.report:
        Path(args.report).write_text(json.dumps(report, indent=2) + "\n", encoding="utf-8")

    if args.stdout_json or (not args.output_hex and not args.output_bin and not args.report):
        print(json.dumps(report, indent=2))
    else:
        print(f"OTAC0={as_hex(values.otac0, 16)} @ {as_hex(values.otac0_addr)}")
        print(f"OTAC_HIGH0={as_hex(values.otac_high0, 16)} @ {as_hex(values.otac_high0_addr)}")
        if indicator is not None:
            print(f"PFLASH0_OTA_INDICATOR @ {as_hex(indicator.low_addr)}")
            print(f"PFLASH1_OTA_INDICATOR @ {as_hex(indicator.high_addr)}")
    return 0


def command_decode(args: argparse.Namespace) -> int:
    otac0 = parse_int(args.otac0, "otac0")
    otac_high0 = parse_int(args.otac_high0, "otac_high0")
    print(json.dumps(decode_values(otac0, otac_high0), indent=2))
    return 0


def build_parser() -> argparse.ArgumentParser:
    parser = argparse.ArgumentParser(description="FC7300 hardware OTA NVR HEX generator")
    sub = parser.add_subparsers(dest="command", required=True)

    init = sub.add_parser("init", help="write a default JSON config")
    init.add_argument("--output", default="fc7300_ota_nvr_config.json")
    init.set_defaults(func=command_init)

    gen = sub.add_parser("generate", help="generate OTAC0/OTAC_HIGH0 HEX from JSON")
    gen.add_argument("--config", help="input JSON config; omit to use defaults")
    gen.add_argument("--output-hex", help="output Intel HEX path")
    gen.add_argument("--output-ota-indicator-hex", help="output PFlash OTA indicator Intel HEX path")
    gen.add_argument("--output-bin", help="output 16-byte binary patch path")
    gen.add_argument("--output-ota-indicator-bin", help="output 32-byte binary patch: low indicator + high indicator")
    gen.add_argument("--report", help="output JSON report path")
    gen.add_argument("--stdout-json", action="store_true", help="print machine-readable JSON report")
    gen.set_defaults(func=command_generate)

    dec = sub.add_parser("decode", help="decode OTAC0/OTAC_HIGH0 values")
    dec.add_argument("--otac0", required=True)
    dec.add_argument("--otac-high0", required=True)
    dec.set_defaults(func=command_decode)

    return parser


def main() -> int:
    parser = build_parser()
    args = parser.parse_args()
    try:
        return args.func(args)
    except Exception as exc:  # noqa: BLE001 - CLI error reporting.
        parser.exit(2, f"error: {exc}\n")


if __name__ == "__main__":
    raise SystemExit(main())
