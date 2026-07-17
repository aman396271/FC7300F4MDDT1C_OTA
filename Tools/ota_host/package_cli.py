"""CLI for finalizing an FCIDE-generated HEX for FC7300 UART OTA."""

from __future__ import annotations

import argparse
from pathlib import Path

from .ide_hex import IdeHexError, inspect_ide_hex, pack_ide_hex


def main() -> int:
    parser = argparse.ArgumentParser(description="Finalize an FCIDE HEX for FC7300F4MDDT1C OTA")
    parser.add_argument("input_hex", type=Path)
    parser.add_argument("--output-dir", type=Path, default=Path("out") / "ide_hex_package")
    parser.add_argument("--timestamp", default="0", help="optional uint32 build timestamp")
    parser.add_argument(
        "--sparse-hex",
        action="store_true",
        help="omit FF-only records; the complete target bank must be erased before JTAG programming",
    )
    parser.add_argument("--inspect", action="store_true", help="validate and print input information only")
    args = parser.parse_args()
    try:
        info = inspect_ide_hex(args.input_hex)
        print(f"variant={info.variant}")
        print(f"physical=0x{info.physical_base:08X}-0x{info.physical_end:08X}")
        print(f"execution_vma=0x{info.execution_vma:08X}")
        print(f"version=0x{info.version:08X}")
        print(f"header=0x{info.header_address:08X}")
        if args.inspect:
            return 0
        result = pack_ide_hex(
            args.input_hex,
            args.output_dir,
            timestamp=int(args.timestamp, 0),
            dense_hex=not args.sparse_hex,
        )
    except (IdeHexError, OSError, ValueError) as exc:
        parser.error(str(exc))
    print(f"ota_hex={result.output_hex}")
    print(f"package={result.output_package}")
    print(f"report={result.output_report}")
    print(f"payload_crc32=0x{result.payload_crc32:08X}")
    print(f"header_crc32=0x{result.header_crc32:08X}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
