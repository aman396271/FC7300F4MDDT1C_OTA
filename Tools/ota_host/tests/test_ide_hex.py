from __future__ import annotations

import struct
from pathlib import Path

import pytest

from Tools.ota_host.ide_hex import (
    BANK_A_BASE,
    BANK_B_BASE,
    HEADER_OFFSET,
    HEADER_SIZE,
    HEADER_VERSION,
    IMAGE_MAGIC,
    VALID_CODE_HI,
    VALID_CODE_LO,
    VALID_FLAG,
    IdeHexError,
    _record,
    inspect_ide_hex,
    pack_ide_hex,
    read_ihex,
)
from Tools.ota_host.package import OtaPackage


def write_ide_hex(path: Path, base: int, version: int, *, extra: dict[int, int] | None = None) -> None:
    memory: dict[int, int] = {}
    vector = struct.pack("<II", 0x21010000, 0x01000101)
    code = vector + b"\x00\xBF\x00\xBF\x70\x47"
    for offset, value in enumerate(code):
        memory[base + offset] = value
    fields = [
        version,
        (~version) & 0xFFFFFFFF,
        VALID_CODE_LO,
        VALID_CODE_HI,
        IMAGE_MAGIC,
        HEADER_VERSION,
        HEADER_OFFSET,
        0xFFFFFFFF,
        0,
        VALID_FLAG,
        0xFFFFFFFF,
        *([0xFFFFFFFF] * 21),
    ]
    header = struct.pack("<32I", *fields)
    for offset, value in enumerate(header):
        memory[base + HEADER_OFFSET + offset] = value
    if extra:
        memory.update(extra)

    lines: list[str] = []
    upper = None
    addresses = sorted(memory)
    index = 0
    while index < len(addresses):
        start = addresses[index]
        current_upper = start >> 16
        if current_upper != upper:
            lines.append(_record(0, 0x04, struct.pack(">H", current_upper)))
            upper = current_upper
        chunk = bytearray([memory[start]])
        index += 1
        while index < len(addresses) and len(chunk) < 32:
            if addresses[index] != start + len(chunk) or addresses[index] >> 16 != upper:
                break
            chunk.append(memory[addresses[index]])
            index += 1
        lines.append(_record(start & 0xFFFF, 0x00, bytes(chunk)))
    lines.append(_record(0, 0x05, struct.pack(">I", 0x01000101)))
    lines.append(_record(0, 0x01, b""))
    path.write_text("\n".join(lines) + "\n", encoding="ascii")


@pytest.mark.parametrize(
    ("base", "variant", "version"),
    ((BANK_A_BASE, "A", 1), (BANK_B_BASE, "B", 2)),
)
def test_inspect_and_pack_ide_hex(tmp_path: Path, base: int, variant: str, version: int) -> None:
    source = tmp_path / f"ide_app_{variant}.hex"
    write_ide_hex(source, base, version)

    info = inspect_ide_hex(source)
    assert info.variant == variant
    assert info.physical_base == base
    assert info.execution_vma == BANK_A_BASE
    assert info.version == version

    result = pack_ide_hex(source, tmp_path / "output", dense_hex=False)
    package = OtaPackage.load(result.output_package)
    assert package.header.version == version
    assert package.header.image_size == HEADER_OFFSET
    assert result.output_hex.is_file()
    output_memory = read_ihex(result.output_hex)
    assert struct.unpack(
        "<I", bytes(output_memory[base + HEADER_OFFSET + i] for i in range(4))
    )[0] == version
    assert not any(address < base or address >= base + 0x00200000 for address in output_memory)


def test_dense_hex_covers_complete_bank(tmp_path: Path) -> None:
    source = tmp_path / "ide_app_a.hex"
    write_ide_hex(source, BANK_A_BASE, 1)
    result = pack_ide_hex(source, tmp_path / "output", dense_hex=True)
    text = result.output_hex.read_text(encoding="ascii")
    assert result.output_hex.stat().st_size > 4_900_000
    assert ":02000004011F" in text
    assert ":20FFE000" in text


def test_rejects_hex_with_nvr_or_second_bank_data(tmp_path: Path) -> None:
    source = tmp_path / "mixed.hex"
    write_ide_hex(source, BANK_A_BASE, 1, extra={BANK_B_BASE: 0x12})
    with pytest.raises(IdeHexError, match="exactly one PFlash Bank"):
        inspect_ide_hex(source)


def test_rejects_missing_ota_header(tmp_path: Path) -> None:
    source = tmp_path / "invalid.hex"
    source.write_text(
        "\n".join(
            [
                _record(0, 0x04, struct.pack(">H", BANK_A_BASE >> 16)),
                _record(0, 0x00, struct.pack("<II", 0x21010000, 0x01000101)),
                _record(0, 0x01, b""),
            ]
        )
        + "\n",
        encoding="ascii",
    )
    with pytest.raises(IdeHexError, match="ota_header"):
        inspect_ide_hex(source)
