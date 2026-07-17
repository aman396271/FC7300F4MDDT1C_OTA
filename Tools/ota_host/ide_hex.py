"""Finalize an FCIDE Intel HEX as an FC7300 hardware-OTA image and package."""

from __future__ import annotations

import hashlib
import json
import struct
from dataclasses import dataclass
from pathlib import Path

from .package import OtaPackage, crc32


BANK_A_BASE = 0x01000000
BANK_B_BASE = 0x01200000
SLOT_SIZE = 0x00200000
HEADER_OFFSET = 0x001FF000
HEADER_SIZE = 0x80
EXECUTION_VMA = BANK_A_BASE
IMAGE_MAGIC = 0x46435441
HEADER_VERSION = 0x00010000
VALID_FLAG = 0xA5A55A5A
VALID_CODE_LO = 0x88886666
VALID_CODE_HI = 0xFC60FACE
SRAM_START = 0x20000000
SRAM_END = 0x22000000


class IdeHexError(ValueError):
    """Raised when an IDE HEX cannot be safely finalized for OTA."""


@dataclass(frozen=True)
class IdeHexInfo:
    source: Path
    variant: str
    physical_base: int
    physical_end: int
    execution_vma: int
    header_address: int
    version: int
    stack_pointer: int
    reset_handler: int
    explicit_bytes: int


@dataclass(frozen=True)
class IdeHexPackResult:
    info: IdeHexInfo
    output_hex: Path
    output_package: Path
    output_report: Path
    payload_crc32: int
    header_crc32: int
    dense_hex: bool


def _checksum(values: bytes | bytearray | list[int]) -> int:
    return (-sum(values)) & 0xFF


def _record(address: int, record_type: int, data: bytes) -> str:
    body = bytes([len(data), address >> 8, address & 0xFF, record_type]) + data
    return ":" + body.hex().upper() + f"{_checksum(body):02X}"


def read_ihex(path: str | Path) -> dict[int, int]:
    """Read common Intel HEX records, preserving every explicitly supplied byte."""

    source = Path(path)
    memory: dict[int, int] = {}
    base = 0
    eof_seen = False
    for line_number, text in enumerate(source.read_text(encoding="ascii").splitlines(), 1):
        line = text.strip()
        if not line:
            continue
        if not line.startswith(":"):
            raise IdeHexError(f"{source}:{line_number}: missing ':' record prefix")
        try:
            record = bytes.fromhex(line[1:])
        except ValueError as exc:
            raise IdeHexError(f"{source}:{line_number}: invalid hexadecimal text") from exc
        if len(record) < 5 or len(record) != record[0] + 5 or (sum(record) & 0xFF):
            raise IdeHexError(f"{source}:{line_number}: invalid Intel HEX record/checksum")
        length = record[0]
        address = (record[1] << 8) | record[2]
        record_type = record[3]
        data = record[4 : 4 + length]
        if record_type == 0x00:
            absolute = base + address
            for index, value in enumerate(data):
                location = absolute + index
                previous = memory.get(location)
                if previous is not None and previous != value:
                    raise IdeHexError(
                        f"{source}:{line_number}: conflicting data at 0x{location:08X}"
                    )
                memory[location] = value
        elif record_type == 0x01:
            eof_seen = True
            break
        elif record_type == 0x02 and length == 2:
            base = int.from_bytes(data, "big") << 4
        elif record_type == 0x04 and length == 2:
            base = int.from_bytes(data, "big") << 16
        elif record_type in (0x03, 0x05):
            # Optional start-address records do not contribute programmable data.
            continue
        else:
            raise IdeHexError(
                f"{source}:{line_number}: unsupported Intel HEX record type 0x{record_type:02X}"
            )
    if not eof_seen:
        raise IdeHexError(f"{source}: missing Intel HEX EOF record")
    if not memory:
        raise IdeHexError(f"{source}: Intel HEX contains no data")
    return memory


def _read_range(memory: dict[int, int], address: int, length: int) -> bytes:
    return bytes(memory.get(address + offset, 0xFF) for offset in range(length))


def _detect_bank(memory: dict[int, int], source: Path) -> tuple[str, int]:
    banks = []
    for label, base in (("A", BANK_A_BASE), ("B", BANK_B_BASE)):
        if any(base <= address < base + SLOT_SIZE for address in memory):
            banks.append((label, base))
    if len(banks) != 1:
        raise IdeHexError(
            f"{source}: expected exactly one PFlash Bank, found {len(banks)}; "
            "do not include A+B or NVR data"
        )
    label, base = banks[0]
    outside = [address for address in memory if not base <= address < base + SLOT_SIZE]
    if outside:
        raise IdeHexError(
            f"{source}: data outside Bank {label} at 0x{min(outside):08X}; "
            "NVR and other address ranges are forbidden"
        )
    return label, base


def inspect_ide_hex(path: str | Path) -> IdeHexInfo:
    source = Path(path).resolve()
    memory = read_ihex(source)
    variant, base = _detect_bank(memory, source)

    vector = _read_range(memory, base, 8)
    stack_pointer, reset_handler = struct.unpack("<II", vector)
    if not SRAM_START <= stack_pointer < SRAM_END or (stack_pointer & 0x7):
        raise IdeHexError(f"{source}: invalid initial stack pointer 0x{stack_pointer:08X}")
    reset_address = reset_handler & ~1
    if not (reset_handler & 1) or not EXECUTION_VMA <= reset_address < EXECUTION_VMA + SLOT_SIZE:
        raise IdeHexError(
            f"{source}: reset handler 0x{reset_handler:08X} is not linked to common "
            f"VMA 0x{EXECUTION_VMA:08X}"
        )

    header_address = base + HEADER_OFFSET
    if not all(header_address + offset in memory for offset in range(44)):
        raise IdeHexError(f"{source}: linked .ota_header template is missing or incomplete")
    header = _read_range(memory, header_address, HEADER_SIZE)
    fields = struct.unpack("<32I", header)
    version, inverted, valid_lo, valid_hi, magic, header_version = fields[:6]
    valid_flag = fields[9]
    if not 0 < version < 0xFFFFFFFF:
        raise IdeHexError(f"{source}: OTA version must be 0x00000001..0xFFFFFFFE")
    if inverted != ((~version) & 0xFFFFFFFF):
        raise IdeHexError(f"{source}: OTA version complement mismatch")
    if (valid_lo, valid_hi) != (VALID_CODE_LO, VALID_CODE_HI):
        raise IdeHexError(f"{source}: FC7300F4MDD hardware valid code is missing")
    if magic != IMAGE_MAGIC or header_version != HEADER_VERSION or valid_flag != VALID_FLAG:
        raise IdeHexError(f"{source}: linked .ota_header template is missing or incompatible")

    reserved_start = base + HEADER_OFFSET + HEADER_SIZE
    occupied_reserved = [
        address for address, value in memory.items()
        if reserved_start <= address < base + SLOT_SIZE and value != 0xFF
    ]
    if occupied_reserved:
        raise IdeHexError(
            f"{source}: loadable data occupies reserved header sector at "
            f"0x{min(occupied_reserved):08X}"
        )

    return IdeHexInfo(
        source=source,
        variant=variant,
        physical_base=base,
        physical_end=base + SLOT_SIZE - 1,
        execution_vma=EXECUTION_VMA,
        header_address=base + HEADER_OFFSET,
        version=version,
        stack_pointer=stack_pointer,
        reset_handler=reset_handler,
        explicit_bytes=len(memory),
    )


def _make_header(version: int, payload: bytes, timestamp: int) -> bytes:
    fields = [
        version,
        (~version) & 0xFFFFFFFF,
        VALID_CODE_LO,
        VALID_CODE_HI,
        IMAGE_MAGIC,
        HEADER_VERSION,
        len(payload),
        crc32(payload),
        timestamp,
        VALID_FLAG,
        0,
        *([0xFFFFFFFF] * 21),
    ]
    header = bytearray(struct.pack("<32I", *fields))
    struct.pack_into("<I", header, 40, crc32(header))
    return bytes(header)


def _write_slot_hex(path: Path, image: bytes, base: int, dense: bool) -> int:
    lines: list[str] = []
    upper: int | None = None
    records = 0
    for offset in range(0, len(image), 32):
        chunk = image[offset : offset + 32]
        if not dense and all(value == 0xFF for value in chunk):
            continue
        absolute = base + offset
        current_upper = absolute >> 16
        if current_upper != upper:
            lines.append(_record(0, 0x04, struct.pack(">H", current_upper)))
            upper = current_upper
        lines.append(_record(absolute & 0xFFFF, 0x00, chunk))
        records += 1
    lines.append(_record(0, 0x01, b""))
    path.write_text("\n".join(lines) + "\n", encoding="ascii", newline="\n")
    return records


def pack_ide_hex(
    input_hex: str | Path,
    output_dir: str | Path,
    *,
    timestamp: int = 0,
    dense_hex: bool = True,
) -> IdeHexPackResult:
    """Finalize one IDE HEX and emit a bank-correct HEX, UART package and report."""

    if not 0 <= timestamp <= 0xFFFFFFFF:
        raise IdeHexError("build timestamp must fit in uint32")
    info = inspect_ide_hex(input_hex)
    memory = read_ihex(info.source)
    payload = bytearray(b"\xFF" * HEADER_OFFSET)
    for address, value in memory.items():
        offset = address - info.physical_base
        if 0 <= offset < HEADER_OFFSET:
            payload[offset] = value
    payload_bytes = bytes(payload)
    header = _make_header(info.version, payload_bytes, timestamp)
    image = payload_bytes + header + b"\xFF" * (SLOT_SIZE - HEADER_OFFSET - HEADER_SIZE)

    destination = Path(output_dir).resolve()
    destination.mkdir(parents=True, exist_ok=True)
    stem = info.source.stem
    output_hex = destination / f"{stem}_OTA_Bank{info.variant}.hex"
    output_package = destination / f"{stem}_v{info.version:08X}.pkg"
    output_report = destination / f"{stem}_OTA_report.json"

    record_count = _write_slot_hex(output_hex, image, info.physical_base, dense_hex)
    package_bytes = header + payload_bytes
    output_package.write_bytes(package_bytes)
    OtaPackage.from_bytes(package_bytes, output_package)

    header_crc = struct.unpack_from("<I", header, 40)[0]
    report = {
        "schema_version": 1,
        "chip": "FC7300F4MDDT1C",
        "source_ide_hex": str(info.source),
        "source_sha256": hashlib.sha256(info.source.read_bytes()).hexdigest().upper(),
        "variant": info.variant,
        "physical_base": f"0x{info.physical_base:08X}",
        "physical_end": f"0x{info.physical_end:08X}",
        "execution_vma": f"0x{info.execution_vma:08X}",
        "header_address": f"0x{info.header_address:08X}",
        "version": f"0x{info.version:08X}",
        "stack_pointer": f"0x{info.stack_pointer:08X}",
        "reset_handler": f"0x{info.reset_handler:08X}",
        "payload_size": HEADER_OFFSET,
        "payload_crc32": f"0x{crc32(payload_bytes):08X}",
        "header_crc32": f"0x{header_crc:08X}",
        "build_timestamp": f"0x{timestamp:08X}",
        "contains_nvr": False,
        "hex_mode": "dense full 2 MB bank" if dense_hex else "sparse; erase full bank first",
        "hex_data_records": record_count,
        "output_hex": output_hex.name,
        "output_hex_sha256": hashlib.sha256(output_hex.read_bytes()).hexdigest().upper(),
        "output_package": output_package.name,
        "output_package_sha256": hashlib.sha256(package_bytes).hexdigest().upper(),
    }
    output_report.write_text(json.dumps(report, indent=2) + "\n", encoding="utf-8")
    return IdeHexPackResult(
        info=info,
        output_hex=output_hex,
        output_package=output_package,
        output_report=output_report,
        payload_crc32=crc32(payload_bytes),
        header_crc32=header_crc,
        dense_hex=dense_hex,
    )
