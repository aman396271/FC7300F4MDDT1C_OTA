#!/usr/bin/env python3
"""Generate the firmware version header from the single OTA version manifest."""

from __future__ import annotations

import argparse
import json
from pathlib import Path


PROJECT = Path(__file__).resolve().parents[1]
DEFAULT_MANIFEST = PROJECT / "Tools" / "ota_versions.json"
DEFAULT_OUTPUT = PROJECT / "Include" / "ota_version_autogen.h"


def parse_version(value: object, label: str) -> int:
    if isinstance(value, int):
        version = value
    elif isinstance(value, str):
        version = int(value, 0)
    else:
        raise ValueError(f"{label} must be an integer or numeric string")
    if not 0 < version < 0xFFFFFFFF:
        raise ValueError(f"{label} must be in range 0x00000001..0xFFFFFFFE")
    return version


def load_versions(path: Path, profile: str | None = None) -> dict[str, int]:
    document = json.loads(path.read_text(encoding="utf-8"))
    if document.get("schema_version") != 1:
        raise ValueError("unsupported OTA version manifest schema")
    profiles = document.get("profiles")
    if not isinstance(profiles, dict):
        raise ValueError("profiles must be an object")
    selected_profile = profile or document.get("default_profile")
    if not isinstance(selected_profile, str) or selected_profile not in profiles:
        raise ValueError(f"unknown OTA version profile: {selected_profile}")
    variants = profiles[selected_profile]
    if not isinstance(variants, dict):
        raise ValueError("variants must be an object")
    return {
        label: parse_version(variants.get(label, {}).get("version"), f"variants.{label}.version")
        for label in ("A", "B")
    }


def render_header(versions: dict[str, int]) -> str:
    return f"""#ifndef OTA_VERSION_AUTOGEN_H_\n#define OTA_VERSION_AUTOGEN_H_\n\n/* Generated from Tools/ota_versions.json. Do not edit by hand. */\n#define OTA_VERSION_A                    (0x{versions['A']:08X}UL)\n#define OTA_VERSION_B                    (0x{versions['B']:08X}UL)\n\n#endif /* OTA_VERSION_AUTOGEN_H_ */\n"""


def main() -> int:
    parser = argparse.ArgumentParser()
    parser.add_argument("--manifest", type=Path, default=DEFAULT_MANIFEST)
    parser.add_argument("--output", type=Path, default=DEFAULT_OUTPUT)
    parser.add_argument("--profile")
    parser.add_argument("--check", action="store_true")
    args = parser.parse_args()

    expected = render_header(load_versions(args.manifest, args.profile))
    if args.check:
        if not args.output.is_file() or args.output.read_text(encoding="utf-8") != expected:
            raise SystemExit(f"generated version header is stale: {args.output}")
        print(f"version_header_ok={args.output}")
        return 0

    args.output.parent.mkdir(parents=True, exist_ok=True)
    args.output.write_text(expected, encoding="utf-8", newline="\n")
    print(f"version_header={args.output}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
