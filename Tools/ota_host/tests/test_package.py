from __future__ import annotations

import pytest

from ..package import OtaPackage, PackageError
from .helpers import make_package


def test_package_parses_and_exposes_version() -> None:
    package = make_package(0x1234, 257)
    assert package.header.version == 0x1234
    assert package.header.image_size == 257


def test_package_rejects_payload_crc_corruption() -> None:
    package = make_package()
    data = bytearray(package.header.raw + package.payload)
    data[-1] ^= 1
    with pytest.raises(PackageError, match="payload CRC"):
        OtaPackage.from_bytes(data)


def test_package_rejects_length_mismatch() -> None:
    package = make_package()
    with pytest.raises(PackageError, match="length"):
        OtaPackage.from_bytes(package.header.raw + package.payload[:-1])
