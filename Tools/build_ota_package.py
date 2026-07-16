#!/usr/bin/env python3
"""Build one A/B variant and emit a version-consistent UART OTA package."""

from __future__ import annotations

import argparse
import sys
from pathlib import Path

from build_ab_demo import PROJECT, TOOLS_DIR, build_variant, find_tool, run


def main() -> int:
    parser = argparse.ArgumentParser()
    parser.add_argument("variant", choices=("A", "B"), type=str.upper)
    parser.add_argument("--output-dir", type=Path)
    parser.add_argument("--profile", help="version profile from Tools/ota_versions.json")
    args = parser.parse_args()

    label = args.variant
    output_dir = (args.output_dir or (PROJECT / "out" / "ota_package" / label.lower())).resolve()
    output_dir.mkdir(parents=True, exist_ok=True)
    generate_command = [sys.executable, str(TOOLS_DIR / "generate_ota_version.py")]
    if args.profile:
        generate_command.extend(["--profile", args.profile])
    run(generate_command, PROJECT)
    try:
        build_variant(
            label,
            find_tool("mingw32-make", "make"),
            find_tool("arm-none-eabi-objcopy"),
            find_tool("arm-none-eabi-readelf"),
            output_dir,
        )
    finally:
        if args.profile:
            run([sys.executable, str(TOOLS_DIR / "generate_ota_version.py")], PROJECT)
    package = output_dir / f"app_{label.lower()}.pkg"
    print(f"package={package}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
