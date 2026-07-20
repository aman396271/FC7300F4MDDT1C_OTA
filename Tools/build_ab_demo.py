#!/usr/bin/env python3
"""Build independent A/B targets and generate physical-bank PFlash HEX files."""

from __future__ import annotations

import argparse
import re
import shutil
import subprocess
import sys
from pathlib import Path


PROJECT = Path(__file__).resolve().parents[1]
BUILD_DIRS = {
    "A": PROJECT / "Debug_FLASH_A",
    "B": PROJECT / "Debug_FLASH_B",
}
TOOLS_DIR = PROJECT / "Tools"
ARTIFACTS_DIR = PROJECT / "Artifacts"
ELF_NAMES = {
    "A": "OTA_7300F4MDDT1C_260707_APP_A.elf",
    "B": "OTA_7300F4MDDT1C_260707_APP_B.elf",
}

PROGRAM_LOAD_RE = re.compile(
    r"^\s*LOAD\s+\S+\s+(0x[0-9a-fA-F]+)\s+(0x[0-9a-fA-F]+)\s+"
    r"(0x[0-9a-fA-F]+)\s+(0x[0-9a-fA-F]+)",
    re.MULTILINE,
)


def run(command: list[str], cwd: Path) -> None:
    print("+", " ".join(command), flush=True)
    subprocess.run(command, cwd=cwd, check=True)


def find_tool(*names: str) -> str:
    for name in names:
        result = shutil.which(name)
        if result:
            return result
    raise SystemExit(f"required tool not found: {' / '.join(names)}")


def verify_elf_layout(label: str, elf: Path, readelf: str) -> None:
    result = subprocess.run(
        [readelf, "-lW", str(elf)],
        cwd=PROJECT,
        check=True,
        capture_output=True,
        text=True,
    )
    entry_match = re.search(r"Entry point (0x[0-9a-fA-F]+)", result.stdout)
    if not entry_match:
        raise RuntimeError(f"cannot read entry point from {elf}")
    entry = int(entry_match.group(1), 16)
    if not 0x01000000 <= entry < 0x01200000:
        raise RuntimeError(f"APP {label} entry is not in the common low VMA: 0x{entry:08X}")

    segments = [
        tuple(int(value, 16) for value in match.groups())
        for match in PROGRAM_LOAD_RE.finditer(result.stdout)
    ]
    file_segments = [segment for segment in segments if segment[2] != 0]
    expected_base = 0x01000000 if label == "A" else 0x01200000
    expected_end = expected_base + 0x00200000
    physical_segments = [
        segment for segment in file_segments if expected_base <= segment[1] < expected_end
    ]
    if len(physical_segments) != len(file_segments):
        unexpected = ", ".join(f"0x{segment[1]:08X}" for segment in file_segments)
        raise RuntimeError(f"APP {label} has unexpected physical load addresses: {unexpected}")
    if label == "B" and not any(segment[0] == 0x21000000 for segment in file_segments):
        raise RuntimeError("APP B .data segment is missing its SRAM VMA / Bank1 LMA mapping")

    print(
        f"APP {label} ELF layout: entry/VMA=0x{entry:08X}, "
        f"physical loads=0x{expected_base:08X}-0x{expected_end - 1:08X}"
    )


def build_variant(
    label: str,
    make_tool: str,
    objcopy: str,
    readelf: str,
    output_dir: Path,
) -> Path:
    build_dir = BUILD_DIRS[label]
    run([make_tool, "-j4", "all"], build_dir)
    elf_source = build_dir / ELF_NAMES[label]
    if not elf_source.is_file():
        raise RuntimeError(f"FCIDE target did not produce {elf_source}")
    elf_output = output_dir / f"app_{label.lower()}.elf"
    raw_output = output_dir / f"app_{label.lower()}_linked.bin"
    shutil.copy2(elf_source, elf_output)
    verify_elf_layout(label, elf_output, readelf)
    run([objcopy, "--gap-fill", "0xFF", "-O", "binary", str(elf_output), str(raw_output)], PROJECT)
    prefix = output_dir / f"app_{label.lower()}"
    run(
        [
            sys.executable,
            str(TOOLS_DIR / "pack_hw_ota_image.py"),
            str(raw_output),
            "--out-prefix",
            str(prefix),
        ],
        PROJECT,
    )
    return prefix.with_name(prefix.name + "_low.bin")


def main() -> int:
    parser = argparse.ArgumentParser(description="Build FC7300 observable A/B POR swap demo")
    parser.add_argument("--output-dir", type=Path, default=PROJECT / "out" / "ab_demo")
    parser.add_argument("--artifacts-dir", type=Path, default=ARTIFACTS_DIR)
    args = parser.parse_args()

    missing_build_dirs = [
        str(path) for path in BUILD_DIRS.values() if not (path / "makefile").is_file()
    ]
    if missing_build_dirs:
        raise SystemExit(
            "FCIDE A/B generated makefiles are missing. Refresh the project and build "
            "Debug_FLASH_A and Debug_FLASH_B once before running this script:\n"
            + "\n".join(missing_build_dirs)
        )
    output_dir = args.output_dir.resolve()
    output_dir.mkdir(parents=True, exist_ok=True)
    artifacts_dir = args.artifacts_dir.resolve()
    artifacts_dir.mkdir(parents=True, exist_ok=True)
    pflash_hex = artifacts_dir / "FC7300_AB_PFlash_Demo.hex"
    app_a_hex = artifacts_dir / "FC7300_APP_A_Bank0.hex"
    app_b_hex = artifacts_dir / "FC7300_APP_B_Bank1.hex"
    pflash_report = artifacts_dir / "FC7300_AB_PFlash_Demo.report.json"
    default_nvr_hex = artifacts_dir / "FC7300_NVR_Default.hex"
    ota_nvr_hex = artifacts_dir / "FC7300_NVR_OTA_Enabled.hex"
    ota_nvr_report = artifacts_dir / "FC7300_NVR_OTA_Enabled.report.json"
    ota_nvr_bin = output_dir / "FC7300_NVR_OTA_Enabled.bin"
    make_tool = find_tool("mingw32-make", "make")
    objcopy = find_tool("arm-none-eabi-objcopy")
    readelf = find_tool("arm-none-eabi-readelf")
    run(
        [sys.executable, str(TOOLS_DIR / "generate_ota_version.py")],
        PROJECT,
    )
    a_bin = build_variant("A", make_tool, objcopy, readelf, output_dir)
    b_bin = build_variant("B", make_tool, objcopy, readelf, output_dir)
    run(
        [
            sys.executable,
            str(TOOLS_DIR / "make_ab_pflash_hex.py"),
            "--a-bin",
            str(a_bin),
            "--b-bin",
            str(b_bin),
            "--a-output-hex",
            str(app_a_hex),
            "--b-output-hex",
            str(app_b_hex),
            "--output-hex",
            str(pflash_hex),
            "--report",
            str(pflash_report),
        ],
        PROJECT,
    )
    run(
        [
            sys.executable,
            str(TOOLS_DIR / "fc7300_nvr_config_tool.py"),
            "generate",
            "--config",
            str(TOOLS_DIR / "fc7300_nvr_config.example.json"),
            "--output-hex",
            str(ota_nvr_hex),
            "--output-bin",
            str(ota_nvr_bin),
            "--report",
            str(ota_nvr_report),
        ],
        PROJECT,
    )
    shutil.copy2(
        TOOLS_DIR / "reference" / "FC73000F4MDDT1C_Default.hex",
        default_nvr_hex,
    )

    print("\nGenerated test artifacts:")
    print(app_a_hex)
    print(app_b_hex)
    print(pflash_hex)
    print(default_nvr_hex)
    print(ota_nvr_hex)
    print(pflash_report)
    print(ota_nvr_report)
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
