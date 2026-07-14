#!/usr/bin/env python3
"""Build observable A/B apps and generate one combined PFlash HEX."""

from __future__ import annotations

import argparse
import shutil
import subprocess
import sys
from pathlib import Path


PROJECT = Path(__file__).resolve().parents[1]
BUILD_DIR = PROJECT / "Debug_FLASH"
TOOLS_DIR = PROJECT / "Tools"
SELECTION = PROJECT / "Include" / "ota_build_selection.h"
ELF_NAME = "OTA_7300F4MDDT1C_260707.elf"


def selection_text(variant: int) -> str:
    return (
        "#ifndef OTA_BUILD_SELECTION_H_\n"
        "#define OTA_BUILD_SELECTION_H_\n\n"
        "/* Rewritten temporarily by Tools/build_ab_demo.py. Keep the checked-in default as A. */\n"
        f"#define OTA_BUILD_VARIANT {variant}\n\n"
        "#endif /* OTA_BUILD_SELECTION_H_ */\n"
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


def build_variant(
    variant: int,
    label: str,
    version: str,
    make_tool: str,
    objcopy: str,
    output_dir: Path,
) -> Path:
    SELECTION.write_text(selection_text(variant), encoding="ascii")
    run([make_tool, "-j4", "all"], BUILD_DIR)
    elf_source = BUILD_DIR / ELF_NAME
    elf_output = output_dir / f"app_{label.lower()}.elf"
    raw_output = output_dir / f"app_{label.lower()}_linked.bin"
    shutil.copy2(elf_source, elf_output)
    run([objcopy, "--gap-fill", "0xFF", "-O", "binary", str(elf_output), str(raw_output)], PROJECT)
    prefix = output_dir / f"app_{label.lower()}"
    run(
        [
            sys.executable,
            str(TOOLS_DIR / "pack_hw_ota_image.py"),
            str(raw_output),
            "--version",
            version,
            "--out-prefix",
            str(prefix),
        ],
        PROJECT,
    )
    return prefix.with_name(prefix.name + "_low.bin")


def main() -> int:
    parser = argparse.ArgumentParser(description="Build FC7300 observable A/B POR swap demo")
    parser.add_argument("--output-dir", type=Path, default=PROJECT / "out" / "ab_demo")
    parser.add_argument("--a-version", default="0x00000001")
    parser.add_argument("--b-version", default="0x00000002")
    args = parser.parse_args()

    if not (BUILD_DIR / "makefile").is_file():
        raise SystemExit(
            "Debug_FLASH/makefile is missing; import the project in FCIDE and build "
            "Debug_FLASH once before running this script"
        )
    output_dir = args.output_dir.resolve()
    output_dir.mkdir(parents=True, exist_ok=True)
    make_tool = find_tool("mingw32-make", "make")
    objcopy = find_tool("arm-none-eabi-objcopy")
    original_selection = SELECTION.read_bytes()
    build_error: BaseException | None = None
    try:
        a_bin = build_variant(0, "A", args.a_version, make_tool, objcopy, output_dir)
        b_bin = build_variant(1, "B", args.b_version, make_tool, objcopy, output_dir)
        run(
            [
                sys.executable,
                str(TOOLS_DIR / "make_ab_pflash_hex.py"),
                "--a-bin",
                str(a_bin),
                "--b-bin",
                str(b_bin),
                "--output-hex",
                str(TOOLS_DIR / "fc7300_ab_pflash_demo.hex"),
                "--report",
                str(TOOLS_DIR / "fc7300_ab_pflash_demo.report.json"),
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
                str(TOOLS_DIR / "fc7300_nvr_f4mdd_ota.hex"),
                "--output-bin",
                str(TOOLS_DIR / "fc7300_nvr_f4mdd_ota.bin"),
                "--report",
                str(TOOLS_DIR / "fc7300_nvr_f4mdd_ota.report.json"),
            ],
            PROJECT,
        )
    except BaseException as exc:  # Restore the checked-in A selection even on a failed build.
        build_error = exc
    finally:
        SELECTION.write_bytes(original_selection)
        try:
            run([make_tool, "-j4", "all"], BUILD_DIR)
        except BaseException:
            if build_error is None:
                raise
    if build_error is not None:
        raise build_error

    print("\nGenerated test artifacts:")
    print(TOOLS_DIR / "fc7300_ab_pflash_demo.hex")
    print(TOOLS_DIR / "fc7300_ab_pflash_demo.report.json")
    print(TOOLS_DIR / "reference" / "FC73000F4MDDT1C_Default.hex")
    print(TOOLS_DIR / "fc7300_nvr_f4mdd_ota.hex")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
