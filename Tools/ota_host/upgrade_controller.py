"""Transport-independent OTA upgrade workflow shared by CLI and GUI."""

from __future__ import annotations

import threading
import time
from dataclasses import dataclass
from enum import Enum
from pathlib import Path
from typing import Callable

from .client import DeviceInfo, OtaClient
from .package import OtaPackage


class UpgradeCancelled(RuntimeError):
    pass


class UpgradePhase(str, Enum):
    PREPARING = "preparing"
    ERASING = "erasing"
    TRANSFERRING = "transferring"
    VERIFYING = "verifying"
    COMPLETE = "complete"


@dataclass(frozen=True)
class UpgradeProgress:
    transferred: int
    total: int
    elapsed_seconds: float
    bytes_per_second: float
    phase: UpgradePhase = UpgradePhase.TRANSFERRING
    message: str = ""

    @property
    def percent(self) -> float:
        return 100.0 if self.total == 0 else self.transferred * 100.0 / self.total

    @property
    def indeterminate(self) -> bool:
        return self.phase in (UpgradePhase.PREPARING, UpgradePhase.ERASING, UpgradePhase.VERIFYING)


@dataclass(frozen=True)
class UpgradeResult:
    package_version: int
    target_slot: int
    target_physical_base: int
    elapsed_seconds: float
    wait_por: bool


ProgressCallback = Callable[[UpgradeProgress], None]
LogCallback = Callable[[str], None]


class UpgradeController:
    def __init__(self, client: OtaClient) -> None:
        self.client = client
        self._cancel = threading.Event()

    def cancel(self) -> None:
        self._cancel.set()

    def connect(self) -> DeviceInfo:
        self.client.connect()
        return self.client.get_info()

    def get_info(self) -> DeviceInfo:
        return self.client.get_info()

    @staticmethod
    def load_package(path: str | Path) -> OtaPackage:
        return OtaPackage.load(path)

    def upgrade(
        self,
        package: OtaPackage,
        progress: ProgressCallback | None = None,
        log: LogCallback | None = None,
    ) -> UpgradeResult:
        self._cancel.clear()
        info = self.client.get_info()
        if not info.ota_enabled:
            raise RuntimeError("device OTA_EN is not enabled; NVR must be configured offline")
        if package.header.image_size > info.max_image_size:
            raise RuntimeError("package exceeds device maximum image size")
        if package.header.version <= info.active_version:
            raise RuntimeError(
                f"package version 0x{package.header.version:08X} is not newer than "
                f"active 0x{info.active_version:08X}"
            )

        started = False
        start_time = time.monotonic()
        total = len(package.payload)

        def report(
            phase: UpgradePhase,
            transferred: int = 0,
            bytes_per_second: float = 0.0,
            message: str = "",
        ) -> None:
            if progress:
                progress(
                    UpgradeProgress(
                        transferred,
                        total,
                        time.monotonic() - start_time,
                        bytes_per_second,
                        phase,
                        message,
                    )
                )

        def check_cancel() -> None:
            if self._cancel.is_set():
                raise UpgradeCancelled("upgrade cancelled")

        try:
            report(UpgradePhase.PREPARING, message="Checking device and package")
            if log:
                log("Package accepted; erasing the inactive 2 MB bank (this can take up to several minutes)")

            def on_erase_wait(waited: float) -> None:
                cancelling = self._cancel.is_set()
                report(
                    UpgradePhase.ERASING,
                    message=(
                        f"Cancellation requested; waiting for device erase to finish... {waited:.0f} s"
                        if cancelling
                        else f"Erasing inactive bank... {waited:.0f} s"
                    ),
                )

            report(UpgradePhase.ERASING, message="Erasing inactive bank...")
            target_slot, target_physical_base, image_size = self.client.start_update(
                package.header,
                wait_callback=on_erase_wait,
            )
            started = True
            if image_size != len(package.payload):
                raise RuntimeError("device START_UPDATE size does not match package")
            if target_slot != info.inactive_slot or target_physical_base != info.inactive_physical_base:
                raise RuntimeError("device selected an unexpected target bank")
            check_cancel()

            if log:
                log("Inactive bank erase complete; transferring image")
            transfer_started = time.monotonic()
            offset = 0
            report(UpgradePhase.TRANSFERRING, message="Transferring image")
            while offset < total:
                check_cancel()
                chunk = package.payload[offset:offset + self.client.max_payload]
                offset = self.client.write_data(offset, chunk)
                transfer_elapsed = max(time.monotonic() - transfer_started, 1e-9)
                report(
                    UpgradePhase.TRANSFERRING,
                    offset,
                    offset / transfer_elapsed,
                    "Transferring image",
                )

            if log:
                log("Verifying programmed image and committing version indicator")
            report(UpgradePhase.VERIFYING, offset, message="Verifying image and committing indicator...")

            def on_verify_wait(waited: float) -> None:
                report(
                    UpgradePhase.VERIFYING,
                    offset,
                    message=f"Verifying image and committing indicator... {waited:.0f} s",
                )

            self.client.finish(offset, wait_callback=on_verify_wait)
            elapsed = time.monotonic() - start_time
            report(UpgradePhase.COMPLETE, total, message="Upgrade committed; physical POR required")
            if log:
                log("Upgrade committed; physical POR is required")
            return UpgradeResult(package.header.version, target_slot, target_physical_base, elapsed, True)
        except BaseException:
            # KeyboardInterrupt is not an Exception, but the device still
            # needs an explicit ABORT whenever START_UPDATE succeeded.
            if started:
                try:
                    self.client.abort()
                except BaseException:
                    pass
            raise
