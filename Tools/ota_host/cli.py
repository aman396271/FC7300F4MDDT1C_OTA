"""Command-line entry point for FC7300 UART OTA."""

from __future__ import annotations

import argparse
import sys

from .client import OtaClient
from .transport.serial import SerialTransport
from .upgrade_controller import UpgradeController, UpgradeProgress


def print_info(info) -> None:
    print(f"active_slot={'A' if info.active_slot == 0 else 'B'}")
    print(f"active_physical=0x{info.active_physical_base:08X}")
    print(f"active_access=0x{info.active_access_base:08X}")
    print(f"execution_vma=0x{info.execution_vma:08X}")
    print(f"target_slot={'A' if info.inactive_slot == 0 else 'B'}")
    print(f"target_physical=0x{info.inactive_physical_base:08X}")
    print(f"ota_enabled={int(info.ota_enabled)}")
    print(f"active_version=0x{info.active_version:08X}")
    print(f"A_version=0x{info.low_version:08X}")
    print(f"B_version=0x{info.high_version:08X}")


def main() -> int:
    parser = argparse.ArgumentParser(description="FC7300F4MDDT1C UART OTA host")
    parser.add_argument("--list-ports", action="store_true")
    parser.add_argument("--port")
    parser.add_argument("--baud", type=int, default=115200)
    subparsers = parser.add_subparsers(dest="command")
    subparsers.add_parser("info")
    upgrade_parser = subparsers.add_parser("upgrade")
    upgrade_parser.add_argument("package")
    args = parser.parse_args()

    if args.list_ports:
        for port in SerialTransport.list_ports():
            print(port)
        return 0
    if not args.port or not args.command:
        parser.error("--port and a command are required")

    transport = SerialTransport(args.port, args.baud)
    client = OtaClient(transport)
    controller = UpgradeController(client)
    try:
        info = controller.connect()
        if args.command == "info":
            print_info(info)
            return 0

        package = controller.load_package(args.package)
        print_info(info)
        print(f"package_version=0x{package.header.version:08X}")

        last_percent = -1

        def on_progress(value: UpgradeProgress) -> None:
            nonlocal last_percent
            current = int(value.percent)
            if current != last_percent:
                last_percent = current
                print(
                    f"\r{value.percent:6.2f}% {value.bytes_per_second / 1024:8.1f} KiB/s "
                    f"{value.elapsed_seconds:7.1f}s",
                    end="",
                    flush=True,
                )

        result = controller.upgrade(package, on_progress, lambda message: print(f"\n{message}"))
        print(
            f"\nWAIT_POR target={'A' if result.target_slot == 0 else 'B'} "
            f"physical=0x{result.target_physical_base:08X} "
            f"version=0x{result.package_version:08X}"
        )
        return 0
    except KeyboardInterrupt:
        controller.cancel()
        print("\nCancelled", file=sys.stderr)
        return 130
    except Exception as exc:
        print(f"ERROR: {exc}", file=sys.stderr)
        return 1
    finally:
        client.close()


if __name__ == "__main__":
    raise SystemExit(main())
