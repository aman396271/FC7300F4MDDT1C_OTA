#!/usr/bin/env python3
"""Generate a complete FC7300 NVR Intel HEX from a known-good template.

The tool is intentionally conservative: it validates the 2 KB NVR template,
preserves every unmodified byte/reserved bit, and reports each changed 64-bit
configuration word. Field names and offsets come from Table 54 of the
FC7300F4MxxxT1C Reference Manual V0.3.1.
"""

from __future__ import annotations

import argparse
import hashlib
import json
import re
import struct
from dataclasses import dataclass
from pathlib import Path
from typing import Any, Dict, Iterable, List, Mapping, MutableMapping, Tuple


NVR_BASE = 0x04400000
NVR_SIZE = 0x800
WORD_SIZE = 8
PFLASH_HALF_SIZE = 0x100000
OTA_BLOCK_SIZE = 0x2000
OTA_ENABLE_CODE = 0x0A
OTA_SELECT_LOWER = 0xAA
OTA_SELECT_HIGH = 0x55


@dataclass(frozen=True)
class FieldDef:
    lsb: int
    width: int

    @property
    def mask(self) -> int:
        return ((1 << self.width) - 1) << self.lsb


@dataclass(frozen=True)
class RegisterDef:
    offset: int
    fields: Mapping[str, FieldDef]
    sensitive: bool = False


def field(lsb: int, width: int = 1) -> FieldDef:
    return FieldDef(lsb, width)


# Table 54 fields that are useful for product configuration. Raw 64-bit word
# patches remain available for all other documented NVR words.
REGISTERS: Dict[str, RegisterDef] = {
    "NVRVLD": RegisterDef(0x000, {}, True),
    "FSC0_0": RegisterDef(0x010, {}, True),
    "FSC0_1": RegisterDef(0x018, {}, True),
    "FSC1_0": RegisterDef(0x020, {}, True),
    "FSC1_1": RegisterDef(0x028, {}, True),
    "DC0": RegisterDef(
        0x030,
        {
            "NEP": field(0, 4),
            "DBA": field(4, 4),
            "RWL": field(8, 4),
            "TME": field(12, 4),
            "TMBA": field(16, 4),
            "MED": field(20, 4),
            "NKRP": field(24, 4),
            "NWP": field(28, 4),
        },
        True,
    ),
    "DC1": RegisterDef(
        0x038,
        {
            "UKAE": field(0, 4),
            "UKUE": field(4, 4),
            "EUKAE": field(16, 4),
            "EUKUE": field(20, 4),
            "EUKRS": field(24, 6),
            "PFWP": field(32, 12),
        },
        True,
    ),
    "DC2": RegisterDef(0x040, {"HDEN": field(0, 4)}, True),
    "BC0": RegisterDef(
        0x050,
        {
            "FAST_BOOT_SELECT": field(0),
            "NMI_DISABLE": field(1),
            "BOOTROM": field(3),
            "FLEXHSM_WDG_RSTEN_DEFAULT": field(16),
            "INSTANCE_ID": field(60, 4),
        },
    ),
    "BC1": RegisterDef(0x058, {}),
    "BC2": RegisterDef(
        0x060,
        {
            "CPU0_BOOT_ADDR_FIELD": field(7, 25),
            "MAM_ECC_ENABLE": field(40, 2),
            "CPU0_ECC_ENABLE": field(42, 2),
            "CPU1_ECC_ENABLE": field(44, 2),
        },
    ),
    "BC3": RegisterDef(0x068, {"CPU1_BOOT_ADDR_FIELD": field(7, 25)}),
    "BRC0": RegisterDef(
        0x070,
        {
            "HOST_DEBUG_AUTH_EN": field(4, 4),
            "ISP_AUTH_EN": field(8, 4),
            "HSM_WDG_TIMEOUT_MS_FIELD": field(12, 10),
            "HSM_WDG_TIMEOUT_VALID": field(22),
            "ANTI_SCA_DISABLE": field(23),
            "FLEXHSM_SELFTEST_DISABLE": field(24),
        },
        True,
    ),
    "HFC": RegisterDef(
        0x078,
        {
            "HFWP": field(0, 4),
            "HFRP": field(4, 4),
            "HFUE": field(8, 4),
            "HFRS": field(16, 9),
            "SRAM_LCK_EN": field(28),
            "SRAM_LCK_SIZE": field(29, 3),
            "HSM_FW_ADDR_FIELD": field(40, 15),
            "HSM_FW_OTA_BLK_ID": field(60, 3),
            "HSM_FW_OTA_BLK_EN": field(63),
        },
        True,
    ),
    "BRC1": RegisterDef(
        0x080,
        {
            "VERIF_PASS_CHECK_DISABLE": field(0),
            "FCUART_BAUD": field(4, 2),
            "FLEXCAN_BAUD": field(6, 2),
            "OSC_FREQUENCY": field(8, 3),
            "OSC_NOT_AVAILABLE": field(11),
            "DBK_INPUT_ENABLE": field(12, 4),
            "SECURE_BOOT_DISABLE": field(16),
            "DBK_ENCRYPTION_ALGORITHM": field(17, 3),
            "ISP_PIN_DISABLE": field(20),
            "ISP_RECOVERY_ALLOW": field(21),
            "DECRYPTED_KEY_PROTECTION_DISABLE": field(22),
            "ROM_LOOP": field(23),
            "SOFTWARE_ISP_DISABLE": field(24),
            "ISP_PERMISSION_AUTH_DISABLE": field(25),
            "OTA_REG_LOCK": field(26),
            "ALT_IMAGE_ADDRESS_ENABLE": field(27),
            "DEBUG_INFO_TYPE": field(28, 4),
            "SCG_FOSCCFG_EOCV": field(32, 8),
            "SCG_FOSCCFG_EOCV_DISABLE": field(40),
        },
        True,
    ),
    "BRC3": RegisterDef(
        0x088,
        {
            "PRLL_BOOT_MASK": field(0, 25),
            "USRK_DECRYPTION_ALGORITHM": field(26, 2),
            "AUTHENTICATION_ALGORITHM": field(28, 4),
            "IMAGE_ALT_ADDRESS_FIELD": field(34, 30),
        },
        True,
    ),
    "BRC2": RegisterDef(
        0x090,
        {
            "IMAGE_VERIFICATION_MASK": field(0, 25),
            "ISP_INSTANCE_SELECTION": field(25, 3),
            "IMAGE_VERIFICATION_ALGORITHM": field(28, 4),
            "IMAGE_ADDRESS_FIELD": field(34, 30),
        },
        True,
    ),
    "NVR_VERSION": RegisterDef(0x098, {"NVR_VER": field(0, 24)}, True),
    "MAC": RegisterDef(0x0A0, {"ENET_MAC": field(0, 48)}),
    "ENET_OPT": RegisterDef(0x0A8, {"ENET_PHY_TYPE": field(0, 3)}),
    "LBIST_TEST_CTRL": RegisterDef(
        0x0B0, {"SELF_TEST_CTRL0": field(0, 32), "SELF_TEST_CTRL1": field(32, 32)}, True
    ),
    "MBIST_TEST_CTRL": RegisterDef(
        0x0B8, {"MBIST_SEL": field(0, 32), "MBIST_ALG": field(32, 32)}, True
    ),
    "LBIST_CTRL": RegisterDef(0x0C0, {"LBIST_CTRL0": field(0, 32), "LBIST_CTRL1": field(32, 32)}, True),
    "LBIST_MISR": RegisterDef(0x0C8, {"LBIST_MISR0": field(0, 32), "LBIST_MISR1": field(32, 32)}, True),
    "CPU0_DTCM_REMAP": RegisterDef(0x0D0, {"DTCM_SIZE_SELECT": field(0, 4)}),
    "CPU1_DTCM_REMAP": RegisterDef(0x0D8, {"DTCM_SIZE_SELECT": field(0, 4)}),
    "FLEXCORE_ENABLE": RegisterDef(
        0x0E0,
        {"FLEXCORE_EN": field(0, 4), "FLXC_BL_DIS": field(5), "CODE_ADDRESS": field(32, 32)},
    ),
    "SMP_MAP_ENABLE": RegisterDef(0x0F0, {"SMP_MEMORY_MAP_ENABLE": field(0, 4)}),
    "CPU0_SPLIT_LOCK": RegisterDef(0x0F8, {"CPU0_SPLIT_LOCK_ENABLE": field(0, 4)}),
    "OTAC0": RegisterDef(
        0x100,
        {
            "OTA0_ENABLE": field(0, 5),
            "OTA0_START_BLOCK": field(8, 7),
            "OTA0_END_BLOCK": field(24, 7),
            "OTA0_VERSION_OFFSET": field(32, 20),
        },
    ),
    "OTAC_HIGH0": RegisterDef(
        0x108,
        {
            "OTA0_VERSION_SELECT": field(0, 8),
            "OTA0_HIGH_START_BLOCK": field(8, 7),
            "OTA0_HIGH_END_BLOCK": field(24, 7),
        },
    ),
}


# Named raw words from the remainder of Table 54. These are deliberately raw:
# their peripheral bit layouts are defined in the corresponding module chapter.
RAW_REGISTER_OFFSETS = {
    "LC_EN": 0x140,
    "LC_EN_BK": 0x150,
    "LIFECYCLE_1_0": 0x160,
    "LIFECYCLE_1_1": 0x168,
    "LIFECYCLE_1_2": 0x170,
    "LIFECYCLE_1_3": 0x178,
    "LIFECYCLE_2_0": 0x180,
    "LIFECYCLE_2_1": 0x188,
    "LIFECYCLE_2_2": 0x190,
    "LIFECYCLE_2_3": 0x198,
    "LIFECYCLE_3_0": 0x1A0,
    "LIFECYCLE_3_1": 0x1A8,
    "LIFECYCLE_3_2": 0x1B0,
    "LIFECYCLE_3_3": 0x1B8,
    "LIFECYCLE_4_0": 0x1C0,
    "LIFECYCLE_4_1": 0x1C8,
    "LIFECYCLE_4_2": 0x1D0,
    "LIFECYCLE_4_3": 0x1D8,
    "UFM_DISABLE": 0x1E0,
    "MRK0_REVOKE": 0x200,
    "MRK1_REVOKE": 0x210,
    "MRK2_REVOKE": 0x220,
    "MRK3_REVOKE": 0x230,
    "UMRK0_REVOKE": 0x240,
    "UMRK1_REVOKE": 0x250,
    "UMRK2_REVOKE": 0x260,
    "UMRK3_REVOKE": 0x270,
    "LIFECYCLE_5_0": 0x280,
    "LIFECYCLE_5_1": 0x288,
    "LIFECYCLE_5_2": 0x290,
    "LIFECYCLE_5_3": 0x298,
    "CLOCK_RECONFIG_FLAG": 0x300,
    "CLOCK_RECONFIG_FLAG_MASK": 0x308,
    "SCG_CCR": 0x310,
    "SCG_FOSC0": 0x318,
    "SCG_FOSC1": 0x320,
    "SCG_FIRC0": 0x328,
    "SCG_FIRC1": 0x330,
    "SCG_SPLL0_0": 0x338,
    "SCG_SPLL0_1": 0x340,
    "SCG_SPLL1_0": 0x348,
    "SCG_SPLL1_1": 0x350,
    "PCC": 0x358,
    "CAN_CONFIG0": 0x360,
    "CAN_CONFIG1": 0x368,
    "UART_CONFIG": 0x370,
    "SYSTEM_CLOCK_FREQUENCY": 0x378,
    "PERIPHERAL_CLOCK_FREQUENCY": 0x380,
    "OSC_FREQUENCY": 0x388,
    "FLEXHSM_OVERLAY_VALID": 0x480,
    "FLEXHSM_OVERLAY_SIZE": 0x488,
    "FLEXHSM_PFLASH_OVERLAY_ADDR": 0x490,
    "FLEXHSM_DFLASH_OVERLAY_ADDR": 0x498,
    "FLEXHSM_SRAM_OVERLAY_ADDR": 0x4A0,
    "UFW_MAGIC_NUM0": 0x700,
    "UFW_MAGIC_NUM1": 0x708,
    "KEY_UPDATE_KEY_0_1": 0x7B0,
    "KEY_UPDATE_KEY_2_3": 0x7B8,
    "BLOCK_CIPHER_KEY_0_1": 0x7C0,
    "BLOCK_CIPHER_KEY_2_3": 0x7C8,
    "BLOCK_CIPHER_KEY_4_5": 0x7D0,
    "BLOCK_CIPHER_KEY_6_7": 0x7D8,
    "TESTMODE_OVERWRITE_KEY": 0x7E0,
    "DEBUG_BACKDOOR_KEY_0_1": 0x7F0,
}
for _name, _offset in RAW_REGISTER_OFFSETS.items():
    REGISTERS[_name] = RegisterDef(_offset, {}, True)


def parse_int(value: Any, name: str) -> int:
    if isinstance(value, bool):
        return int(value)
    if isinstance(value, int):
        return value
    if not isinstance(value, str):
        raise ValueError(f"{name}: expected integer/string, got {type(value).__name__}")
    text = value.strip().replace("_", "")
    match = re.fullmatch(r"([0-9]+)([kKmM])?", text)
    if match:
        result = int(match.group(1), 10)
        if match.group(2) in ("k", "K"):
            result *= 1024
        elif match.group(2) in ("m", "M"):
            result *= 1024 * 1024
        return result
    return int(text, 0)


def hex_value(value: int, width: int = 16) -> str:
    return f"0x{value:0{width}X}"


def checksum(values: Iterable[int]) -> int:
    return (-sum(values)) & 0xFF


def ihex_record(address: int, record_type: int, data: bytes) -> str:
    body = [len(data), (address >> 8) & 0xFF, address & 0xFF, record_type, *data]
    return ":" + "".join(f"{value:02X}" for value in body) + f"{checksum(body):02X}"


def read_ihex(path: Path) -> Dict[int, int]:
    memory: Dict[int, int] = {}
    base = 0
    eof_seen = False
    for line_number, raw_line in enumerate(path.read_text(encoding="ascii").splitlines(), 1):
        line = raw_line.strip()
        if not line:
            continue
        if not line.startswith(":"):
            raise ValueError(f"{path}:{line_number}: invalid Intel HEX record")
        try:
            record = bytes.fromhex(line[1:])
        except ValueError as exc:
            raise ValueError(f"{path}:{line_number}: invalid hexadecimal data") from exc
        if len(record) < 5 or len(record) != record[0] + 5:
            raise ValueError(f"{path}:{line_number}: invalid record length")
        if sum(record) & 0xFF:
            raise ValueError(f"{path}:{line_number}: checksum mismatch")
        length = record[0]
        address = (record[1] << 8) | record[2]
        record_type = record[3]
        data = record[4 : 4 + length]
        if record_type == 0x00:
            for index, value in enumerate(data):
                absolute = base + address + index
                if absolute in memory and memory[absolute] != value:
                    raise ValueError(f"{path}:{line_number}: conflicting byte at {hex_value(absolute, 8)}")
                memory[absolute] = value
        elif record_type == 0x01:
            eof_seen = True
            break
        elif record_type == 0x02:
            if length != 2:
                raise ValueError(f"{path}:{line_number}: invalid extended segment record")
            base = int.from_bytes(data, "big") << 4
        elif record_type == 0x04:
            if length != 2:
                raise ValueError(f"{path}:{line_number}: invalid extended linear record")
            base = int.from_bytes(data, "big") << 16
        elif record_type not in (0x03, 0x05):
            raise ValueError(f"{path}:{line_number}: unsupported Intel HEX record type {record_type}")
    if not eof_seen:
        raise ValueError(f"{path}: missing Intel HEX EOF record")
    return memory


def write_ihex(memory: Mapping[int, int], path: Path, record_size: int = 32) -> None:
    if not memory:
        raise ValueError("cannot write an empty Intel HEX image")
    lines: List[str] = []
    addresses = sorted(memory)
    index = 0
    upper = None
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
    lines.append(ihex_record(0, 0x01, b""))
    path.write_text("\n".join(lines) + "\n", encoding="ascii")


def validate_nvr_image(memory: Mapping[int, int], base: int, size: int) -> None:
    expected = set(range(base, base + size))
    actual = set(memory)
    missing = expected - actual
    outside = actual - expected
    if missing:
        raise ValueError(f"template is missing {len(missing)} NVR byte(s), first {hex_value(min(missing), 8)}")
    if outside:
        raise ValueError(f"template contains {len(outside)} byte(s) outside NVR, first {hex_value(min(outside), 8)}")


def read_word(memory: Mapping[int, int], address: int) -> int:
    return int.from_bytes(bytes(memory[address + index] for index in range(WORD_SIZE)), "little")


def write_word(memory: MutableMapping[int, int], address: int, value: int) -> None:
    if not 0 <= value <= 0xFFFFFFFFFFFFFFFF:
        raise ValueError(f"64-bit word at {hex_value(address, 8)} is out of range")
    for index, byte in enumerate(value.to_bytes(WORD_SIZE, "little")):
        memory[address + index] = byte


def set_field(word: int, definition: FieldDef, value: int, name: str) -> int:
    if not 0 <= value < (1 << definition.width):
        raise ValueError(f"{name}: value {value} does not fit in {definition.width} bit(s)")
    return (word & ~definition.mask) | (value << definition.lsb)


def resolve_register(name: str, base: int) -> Tuple[str, RegisterDef]:
    normalized = name.strip().upper()
    if normalized in REGISTERS:
        return normalized, REGISTERS[normalized]
    try:
        offset = parse_int(name, f"register {name}")
    except (TypeError, ValueError) as exc:
        raise ValueError(f"unknown register {name!r}; use list-registers to inspect names") from exc
    if offset >= base:
        offset -= base
    if offset % WORD_SIZE or not 0 <= offset <= NVR_SIZE - WORD_SIZE:
        raise ValueError(f"register {name!r}: offset must be 8-byte aligned inside NVR")
    return f"OFFSET_{offset:03X}", RegisterDef(offset, {}, True)


def parse_ota_select(value: Any) -> int:
    if isinstance(value, str):
        normalized = value.strip().lower()
        if normalized in ("lower", "low", "0xaa"):
            return OTA_SELECT_LOWER
        if normalized in ("high", "upper", "0x55"):
            return OTA_SELECT_HIGH
    return parse_int(value, "ota0.version_select")


def ota_block(value: Any, name: str, is_end: bool = False) -> int:
    address = parse_int(value, name)
    offset = address & (PFLASH_HALF_SIZE - 1)
    expected_low = OTA_BLOCK_SIZE - 1 if is_end else 0
    if (offset & (OTA_BLOCK_SIZE - 1)) != expected_low:
        alignment = "end on" if is_end else "start at"
        raise ValueError(f"{name}: must {alignment} an 8 KB block boundary")
    return offset >> 13


def apply_ota_config(memory: MutableMapping[int, int], base: int, ota: Mapping[str, Any]) -> Dict[str, Any]:
    enabled = bool(ota.get("enabled", True))
    enable_code = parse_int(ota.get("enable_code", OTA_ENABLE_CODE), "ota0.enable_code") if enabled else 0
    if enabled and enable_code != OTA_ENABLE_CODE:
        raise ValueError("ota0.enable_code must be 0x0A when OTA is enabled")
    low_start = ota_block(ota.get("low_start", "0x01000000"), "ota0.low_start")
    low_end = ota_block(ota.get("low_end", "0x010FFFFF"), "ota0.low_end", True)
    high_start = ota_block(ota.get("high_start", "0x01100000"), "ota0.high_start")
    high_end = ota_block(ota.get("high_end", "0x011FFFFF"), "ota0.high_end", True)
    if low_end < low_start or high_end < high_start:
        raise ValueError("ota0 end block must be greater than or equal to its start block")
    version_offset = parse_int(ota.get("version_offset", "0x000FF000"), "ota0.version_offset")
    if version_offset < 0 or version_offset + 16 > PFLASH_HALF_SIZE or version_offset & 0xF:
        raise ValueError("ota0.version_offset must be 16-byte aligned and leave 16 bytes inside the selected 1 MB half")
    version_select = parse_ota_select(ota.get("version_select", "high"))
    if not 0 <= version_select <= 0xFF:
        raise ValueError("ota0.version_select must fit in 8 bits")

    otac0_def = REGISTERS["OTAC0"]
    otac_high_def = REGISTERS["OTAC_HIGH0"]
    otac0_addr = base + otac0_def.offset
    otac_high_addr = base + otac_high_def.offset
    otac0 = read_word(memory, otac0_addr)
    otac_high = read_word(memory, otac_high_addr)
    for field_name, value in (
        ("OTA0_ENABLE", enable_code),
        ("OTA0_START_BLOCK", low_start),
        ("OTA0_END_BLOCK", low_end),
        ("OTA0_VERSION_OFFSET", version_offset),
    ):
        otac0 = set_field(otac0, otac0_def.fields[field_name], value, f"OTAC0.{field_name}")
    for field_name, value in (
        ("OTA0_VERSION_SELECT", version_select),
        ("OTA0_HIGH_START_BLOCK", high_start),
        ("OTA0_HIGH_END_BLOCK", high_end),
    ):
        otac_high = set_field(otac_high, otac_high_def.fields[field_name], value, f"OTAC_HIGH0.{field_name}")
    write_word(memory, otac0_addr, otac0)
    write_word(memory, otac_high_addr, otac_high)
    effective_offset = version_offset + (0 if version_select == OTA_SELECT_LOWER else PFLASH_HALF_SIZE)
    return {
        "enabled": enabled,
        "version_select_raw": hex_value(version_select, 2),
        "version_select_meaning": "lower" if version_select == OTA_SELECT_LOWER else "high",
        "raw_version_offset": hex_value(version_offset, 5),
        "effective_bank_offset": hex_value(effective_offset, 6),
        "otac0": hex_value(otac0),
        "otac_high0": hex_value(otac_high),
    }


def apply_register_patches(
    memory: MutableMapping[int, int],
    base: int,
    patches: Mapping[str, Any],
    allow_sensitive: bool,
) -> List[Dict[str, Any]]:
    applied: List[Dict[str, Any]] = []
    for requested_name, patch in patches.items():
        register_name, definition = resolve_register(requested_name, base)
        if not isinstance(patch, Mapping):
            raise ValueError(f"registers.{requested_name}: expected an object")
        if definition.sensitive and not allow_sensitive:
            raise ValueError(
                f"registers.{requested_name}: sensitive NVR word; review the RM and pass --allow-sensitive"
            )
        address = base + definition.offset
        before = read_word(memory, address)
        after = before
        changed_fields: List[Dict[str, Any]] = []
        if "value" in patch:
            if "fields" in patch:
                raise ValueError(f"registers.{requested_name}: use either value or fields, not both")
            after = parse_int(patch["value"], f"registers.{requested_name}.value")
        else:
            fields = patch.get("fields", patch)
            if not isinstance(fields, Mapping):
                raise ValueError(f"registers.{requested_name}.fields: expected an object")
            for requested_field, raw_value in fields.items():
                field_name = requested_field.strip().upper()
                if field_name not in definition.fields:
                    raise ValueError(f"{register_name}: unknown field {requested_field!r}")
                field_def = definition.fields[field_name]
                value = parse_int(raw_value, f"{register_name}.{field_name}")
                field_before = (after & field_def.mask) >> field_def.lsb
                after = set_field(after, field_def, value, f"{register_name}.{field_name}")
                changed_fields.append(
                    {"field": field_name, "before": hex_value(field_before, 1), "after": hex_value(value, 1)}
                )
        write_word(memory, address, after)
        applied.append(
            {
                "register": register_name,
                "offset": hex_value(definition.offset, 3),
                "address": hex_value(address, 8),
                "before": hex_value(before),
                "after": hex_value(after),
                "fields": changed_fields,
            }
        )
    return applied


def memory_bytes(memory: Mapping[int, int], base: int, size: int) -> bytes:
    return bytes(memory[base + index] for index in range(size))


def sha256_bytes(data: bytes) -> str:
    return hashlib.sha256(data).hexdigest().upper()


def word_diff(before: Mapping[int, int], after: Mapping[int, int], base: int, size: int) -> List[Dict[str, Any]]:
    result: List[Dict[str, Any]] = []
    for offset in range(0, size, WORD_SIZE):
        address = base + offset
        old = read_word(before, address)
        new = read_word(after, address)
        if old != new:
            name = next((key for key, definition in REGISTERS.items() if definition.offset == offset), None)
            result.append(
                {
                    "register": name or f"OFFSET_{offset:03X}",
                    "offset": hex_value(offset, 3),
                    "address": hex_value(address, 8),
                    "before": hex_value(old),
                    "after": hex_value(new),
                    "bytes_before": old.to_bytes(8, "little").hex(" ").upper(),
                    "bytes_after": new.to_bytes(8, "little").hex(" ").upper(),
                }
            )
    return result


def load_config(path: Path) -> Dict[str, Any]:
    config = json.loads(path.read_text(encoding="utf-8"))
    if not isinstance(config, dict):
        raise ValueError("configuration root must be a JSON object")
    return config


def resolve_from_config(config_path: Path, value: str) -> Path:
    path = Path(value)
    return path if path.is_absolute() else (config_path.parent / path).resolve()


def command_generate(args: argparse.Namespace) -> int:
    config_path = Path(args.config).resolve()
    config = load_config(config_path)
    base = parse_int(config.get("nvr_base", NVR_BASE), "nvr_base")
    size = parse_int(config.get("nvr_size", NVR_SIZE), "nvr_size")
    if base != NVR_BASE or size != NVR_SIZE:
        raise ValueError("FC7300F4MDDT1C NVR must use base 0x04400000 and size 0x800")
    base_hex_value = args.base_hex or config.get("base_hex")
    if not base_hex_value:
        raise ValueError("base_hex is required in config or through --base-hex")
    base_hex = Path(args.base_hex).resolve() if args.base_hex else resolve_from_config(config_path, base_hex_value)
    source_text_hash = sha256_bytes(base_hex.read_bytes())
    expected_hash = str(config.get("expected_base_hex_sha256", "")).replace(" ", "").upper()
    if expected_hash and source_text_hash != expected_hash:
        raise ValueError(
            f"base HEX SHA-256 mismatch: expected {expected_hash}, got {source_text_hash}"
        )
    original = read_ihex(base_hex)
    validate_nvr_image(original, base, size)
    output = dict(original)

    register_patches = config.get("registers", {})
    if not isinstance(register_patches, Mapping):
        raise ValueError("registers must be a JSON object")
    if "ota0" in config and any(str(name).upper() in ("OTAC0", "OTAC_HIGH0") for name in register_patches):
        raise ValueError("do not combine ota0 with explicit OTAC0/OTAC_HIGH0 register patches")
    applied = apply_register_patches(output, base, register_patches, args.allow_sensitive)
    ota_report = None
    if "ota0" in config:
        ota = config["ota0"]
        if not isinstance(ota, Mapping):
            raise ValueError("ota0 must be a JSON object")
        ota_report = apply_ota_config(output, base, ota)

    output_data = memory_bytes(output, base, size)
    differences = word_diff(original, output, base, size)
    report = {
        "chip": config.get("chip", "FC7300F4MDDT1C"),
        "reference": "FC7300F4MxxxT1C Reference Manual V0.3.1, Table 54",
        "base_hex": str(base_hex_value),
        "base_hex_file_sha256": source_text_hash,
        "nvr_base": hex_value(base, 8),
        "nvr_size": hex_value(size, 3),
        "output_binary_sha256": sha256_bytes(output_data),
        "changed_word_count": len(differences),
        "changed_words": differences,
        "requested_register_patches": applied,
        "ota0": ota_report,
        "warnings": [
            "The output is a complete 2 KB NVR image based on the supplied known-good default HEX.",
            "Unmodified bytes and reserved bits are preserved from the template.",
            "Review changed_words before programming hardware; NVR security/lifecycle changes may be irreversible.",
            "The OTA PFlash indicator is not part of this NVR HEX and must be generated/programmed separately.",
        ],
    }

    if args.output_hex:
        write_ihex(output, Path(args.output_hex))
    if args.output_bin:
        Path(args.output_bin).write_bytes(output_data)
    if args.report:
        Path(args.report).write_text(json.dumps(report, indent=2) + "\n", encoding="utf-8")
    if args.stdout_json or not (args.output_hex or args.output_bin or args.report):
        print(json.dumps(report, indent=2))
    else:
        print(f"base={hex_value(base, 8)} size={hex_value(size, 3)} changed_words={len(differences)}")
        for item in differences:
            print(f"{item['register']} {item['before']} -> {item['after']}")
    return 0


def inspect_report(path: Path, base: int, size: int) -> Dict[str, Any]:
    memory = read_ihex(path)
    validate_nvr_image(memory, base, size)
    registers = []
    for name, definition in sorted(REGISTERS.items(), key=lambda item: (item[1].offset, item[0])):
        value = read_word(memory, base + definition.offset)
        decoded = {
            field_name: hex_value((value & field_def.mask) >> field_def.lsb, 1)
            for field_name, field_def in definition.fields.items()
        }
        registers.append(
            {
                "register": name,
                "offset": hex_value(definition.offset, 3),
                "value": hex_value(value),
                "fields": decoded,
                "sensitive": definition.sensitive,
            }
        )
    return {
        "input_hex": str(path.resolve()),
        "nvr_base": hex_value(base, 8),
        "nvr_size": hex_value(size, 3),
        "binary_sha256": sha256_bytes(memory_bytes(memory, base, size)),
        "registers": registers,
    }


def command_inspect(args: argparse.Namespace) -> int:
    report = inspect_report(Path(args.input_hex), NVR_BASE, NVR_SIZE)
    text = json.dumps(report, indent=2)
    if args.report:
        Path(args.report).write_text(text + "\n", encoding="utf-8")
    print(text)
    return 0


def command_list_registers(_args: argparse.Namespace) -> int:
    for name, definition in sorted(REGISTERS.items(), key=lambda item: (item[1].offset, item[0])):
        fields = ", ".join(definition.fields) or "raw 64-bit value"
        marker = " [sensitive]" if definition.sensitive else ""
        print(f"0x{definition.offset:03X} {name}{marker}: {fields}")
    return 0


def command_init(args: argparse.Namespace) -> int:
    output = Path(args.output)
    base_hex = Path(args.base_hex).resolve()
    config = {
        "chip": "FC7300F4MDDT1C",
        "reference": "FC7300F4MxxxT1C Reference Manual V0.3.1, Table 54/Table 55",
        "base_hex": str(base_hex),
        "expected_base_hex_sha256": sha256_bytes(base_hex.read_bytes()),
        "nvr_base": "0x04400000",
        "nvr_size": "0x800",
        "registers": {},
        "ota0": {
            "enabled": True,
            "low_start": "0x01000000",
            "low_end": "0x010FFFFF",
            "high_start": "0x01100000",
            "high_end": "0x011FFFFF",
            "version_offset": "0x000FF000",
            "version_select": "high",
        },
    }
    output.write_text(json.dumps(config, indent=2) + "\n", encoding="utf-8")
    print(f"wrote {output}")
    return 0


def build_parser() -> argparse.ArgumentParser:
    parser = argparse.ArgumentParser(description="FC7300 complete NVR Intel HEX generator")
    sub = parser.add_subparsers(dest="command", required=True)

    init = sub.add_parser("init", help="create a config bound to a known-good base HEX")
    init.add_argument("--base-hex", required=True)
    init.add_argument("--output", default="fc7300_nvr_config.json")
    init.set_defaults(func=command_init)

    generate = sub.add_parser("generate", help="patch a base HEX and write a complete 2 KB NVR image")
    generate.add_argument("--config", required=True)
    generate.add_argument("--base-hex", help="override config base_hex")
    generate.add_argument("--output-hex")
    generate.add_argument("--output-bin")
    generate.add_argument("--report")
    generate.add_argument("--stdout-json", action="store_true")
    generate.add_argument(
        "--allow-sensitive",
        action="store_true",
        help="allow security/lifecycle/key/raw-offset patches after manual RM review",
    )
    generate.set_defaults(func=command_generate)

    inspect = sub.add_parser("inspect", help="validate and decode a complete NVR HEX")
    inspect.add_argument("--input-hex", required=True)
    inspect.add_argument("--report")
    inspect.set_defaults(func=command_inspect)

    listing = sub.add_parser("list-registers", help="list supported register and field names")
    listing.set_defaults(func=command_list_registers)
    return parser


def main() -> int:
    parser = build_parser()
    args = parser.parse_args()
    try:
        return args.func(args)
    except Exception as exc:  # noqa: BLE001 - concise CLI error reporting.
        parser.exit(2, f"error: {exc}\n")


if __name__ == "__main__":
    raise SystemExit(main())
