from __future__ import annotations

import os
from pathlib import Path
from types import SimpleNamespace

os.environ.setdefault("QT_QPA_PLATFORM", "offscreen")

from PySide6.QtWidgets import QApplication  # noqa: E402

from Tools.ota_host.gui import MainWindow  # noqa: E402
from Tools.ota_host.package_gui import PackageWidget, PackageWindow  # noqa: E402
from Tools.ota_host.tests.helpers import make_package  # noqa: E402


def get_app() -> QApplication:
    return QApplication.instance() or QApplication([])


def test_main_window_embeds_hex_packer_and_loads_generated_package(
    tmp_path: Path, monkeypatch
) -> None:
    app = get_app()
    monkeypatch.setattr("Tools.ota_host.gui.SerialTransport.list_ports", lambda: [])
    package = make_package(version=0x22, size=257)
    package_path = tmp_path / "generated.pkg"
    package_path.write_bytes(package.header.raw + package.payload)
    result = SimpleNamespace(
        output_package=package_path,
        info=SimpleNamespace(variant="B", version=0x22),
    )

    window = MainWindow()
    assert window.tabs.count() == 2
    assert isinstance(window.package_widget, PackageWidget)
    window.tabs.setCurrentIndex(1)
    window.package_widget.package_created.emit(result)
    app.processEvents()

    assert window.tabs.currentIndex() == 0
    assert window.package is not None
    assert window.package.header.version == 0x22
    assert window.package_path.text() == str(package_path)
    assert window.package_version.text() == "0x00000022"
    assert "Loaded package generated from IDE HEX" in window.log_view.toPlainText()
    window.close()


def test_standalone_package_window_reuses_package_widget() -> None:
    get_app()
    window = PackageWindow()
    assert isinstance(window.centralWidget(), PackageWidget)
    window.close()
