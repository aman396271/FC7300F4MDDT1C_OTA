"""Transport-independent OTA upgrade workflow shared by CLI and GUI."""

from __future__ import annotations

import threading
import time
from dataclasses import dataclass
from pathlib import Path
from typing import Callable

from .client import DeviceInfo, OtaClient
from .package import OtaPackage


class UpgradeCancelled(RuntimeError):
    pass


@dataclass(frozen=True)
class UpgradeProgress:
    transferred: int
    total: int
    elapsed_seconds: float
    bytes_per_second: float

    @property
    def percent(self) -> float:
        return 100.0 if self.total == 0 else self.transferred * 100.0 / self.total


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
        try:
            if log:
                log("Validating package and erasing inactive bank")
            target_slot, target_physical_base, image_size = self.client.start_update(package.header)
            started = True
            if image_size != len(package.payload):
                raise RuntimeError("device START_UPDATE size does not match package")
            if target_slot != info.inactive_slot or target_physical_base != info.inactive_physical_base:
                raise RuntimeError("device selected an unexpected target bank")

            offset = 0
            while offset < len(package.payload):
                if self._cancel.is_set():
                    raise UpgradeCancelled("upgrade cancelled")
                chunk = package.payload[offset:offset + self.client.max_payload]
                offset = self.client.write_data(offset, chunk)
                elapsed = max(time.monotonic() - start_time, 1e-9)
                if progress:
                    progress(UpgradeProgress(offset, len(package.payload), elapsed, offset / elapsed))

            if log:
                log("Verifying programmed image and committing version indicator")
            self.client.finish(offset)
            elapsed = time.monotonic() - start_time
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
