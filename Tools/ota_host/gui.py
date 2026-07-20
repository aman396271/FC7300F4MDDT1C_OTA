"""PySide6 GUI for the shared FC7300 UpgradeController."""

from __future__ import annotations

import sys
from pathlib import Path

from PySide6.QtCore import QObject, QThread, Signal, Slot
from PySide6.QtWidgets import (
    QApplication,
    QComboBox,
    QFileDialog,
    QFormLayout,
    QGridLayout,
    QGroupBox,
    QHBoxLayout,
    QLabel,
    QLineEdit,
    QMainWindow,
    QMessageBox,
    QPlainTextEdit,
    QProgressBar,
    QPushButton,
    QTabWidget,
    QVBoxLayout,
    QWidget,
)

from .client import OtaClient
from .package import OtaPackage
from .package_gui import PackageWidget
from .transport.serial import SerialTransport
from .upgrade_controller import UpgradeController, UpgradeProgress, UpgradeResult


class UpgradeWorker(QObject):
    progress = Signal(object)
    log = Signal(str)
    succeeded = Signal(object)
    failed = Signal(str)
    finished = Signal()

    def __init__(self, controller: UpgradeController, package: OtaPackage) -> None:
        super().__init__()
        self.controller = controller
        self.package = package

    @Slot()
    def run(self) -> None:
        try:
            result = self.controller.upgrade(self.package, self.progress.emit, self.log.emit)
            self.succeeded.emit(result)
        except Exception as exc:
            self.failed.emit(str(exc))
        finally:
            self.finished.emit()


class MainWindow(QMainWindow):
    def __init__(self) -> None:
        super().__init__()
        self.setWindowTitle("FC7300F4MDDT1C OTA Tool")
        self.resize(900, 760)
        self.client: OtaClient | None = None
        self.controller: UpgradeController | None = None
        self.package: OtaPackage | None = None
        self.worker_thread: QThread | None = None
        self.worker: UpgradeWorker | None = None

        root = QWidget()
        root_layout = QVBoxLayout(root)
        self.tabs = QTabWidget()
        upgrade_page = QWidget()
        layout = QVBoxLayout(upgrade_page)
        self.package_widget = PackageWidget()
        self.tabs.addTab(upgrade_page, "UART OTA")
        self.tabs.addTab(self.package_widget, "IDE HEX Packer")
        root_layout.addWidget(self.tabs)
        self.setCentralWidget(root)

        self.connection_group = QGroupBox("Serial connection")
        connection_layout = QHBoxLayout(self.connection_group)
        self.port_combo = QComboBox()
        self.refresh_button = QPushButton("Refresh")
        self.connect_button = QPushButton("Connect")
        self.connection_status = QLabel("● Disconnected")
        self.connection_status.setStyleSheet("color: #8a8a8a; font-weight: 600;")
        connection_layout.addWidget(QLabel("Port"))
        connection_layout.addWidget(self.port_combo, 1)
        connection_layout.addWidget(self.refresh_button)
        connection_layout.addWidget(self.connect_button)
        connection_layout.addWidget(self.connection_status)
        layout.addWidget(self.connection_group)

        self.info_group = QGroupBox("Device information")
        info_layout = QGridLayout(self.info_group)
        self.info_labels: dict[str, QLabel] = {}
        fields = [
            ("ota", "OTA_EN"),
            ("active", "Active Bank"),
            ("active_phys", "Active physical"),
            ("active_access", "Active access"),
            ("vma", "Execution VMA"),
            ("target", "Target Bank"),
            ("target_phys", "Target physical"),
            ("current_version", "Current version"),
            ("a_version", "A version"),
            ("b_version", "B version"),
        ]
        for index, (key, title) in enumerate(fields):
            label = QLabel("-")
            self.info_labels[key] = label
            row, column = divmod(index, 2)
            info_layout.addWidget(QLabel(title), row, column * 2)
            info_layout.addWidget(label, row, column * 2 + 1)
        self.info_group.setEnabled(False)
        layout.addWidget(self.info_group)

        package_group = QGroupBox("OTA package")
        package_layout = QFormLayout(package_group)
        path_row = QHBoxLayout()
        self.package_path = QLineEdit()
        self.package_path.setReadOnly(True)
        self.browse_button = QPushButton("Browse…")
        path_row.addWidget(self.package_path, 1)
        path_row.addWidget(self.browse_button)
        self.package_version = QLabel("-")
        self.package_size = QLabel("-")
        package_layout.addRow("File", path_row)
        package_layout.addRow("Target version", self.package_version)
        package_layout.addRow("Payload size", self.package_size)
        layout.addWidget(package_group)

        progress_group = QGroupBox("Upgrade")
        progress_layout = QVBoxLayout(progress_group)
        self.progress_bar = QProgressBar()
        self.progress_bar.setRange(0, 10000)
        stats = QHBoxLayout()
        self.speed_label = QLabel("0 KiB/s")
        self.elapsed_label = QLabel("0.0 s")
        self.wait_por_label = QLabel("")
        self.phase_label = QLabel("Ready")
        self.phase_label.setStyleSheet("color: #235c9b; font-weight: 600;")
        stats.addWidget(self.speed_label)
        stats.addWidget(self.elapsed_label)
        stats.addWidget(self.phase_label)
        stats.addStretch(1)
        stats.addWidget(self.wait_por_label)
        buttons = QHBoxLayout()
        self.upgrade_button = QPushButton("Start upgrade")
        self.upgrade_button.setEnabled(False)
        self.cancel_button = QPushButton("Cancel")
        self.cancel_button.setEnabled(False)
        buttons.addWidget(self.upgrade_button)
        buttons.addWidget(self.cancel_button)
        progress_layout.addWidget(self.progress_bar)
        progress_layout.addLayout(stats)
        progress_layout.addLayout(buttons)
        layout.addWidget(progress_group)

        self.log_view = QPlainTextEdit()
        self.log_view.setReadOnly(True)
        layout.addWidget(self.log_view, 1)

        self.refresh_button.clicked.connect(self.refresh_ports)
        self.connect_button.clicked.connect(self.connect_device)
        self.browse_button.clicked.connect(self.select_package)
        self.upgrade_button.clicked.connect(self.start_upgrade)
        self.cancel_button.clicked.connect(self.cancel_upgrade)
        self.package_widget.package_created.connect(self.on_package_created)
        self.refresh_ports()

    def append_log(self, message: str) -> None:
        self.log_view.appendPlainText(message)

    def refresh_ports(self) -> None:
        current = self.port_combo.currentText()
        self.port_combo.clear()
        self.port_combo.addItems(SerialTransport.list_ports())
        index = self.port_combo.findText(current)
        if index >= 0:
            self.port_combo.setCurrentIndex(index)

    def connect_device(self) -> None:
        if self.client is not None:
            self.disconnect_device()
            return
        port = self.port_combo.currentText()
        if not port:
            QMessageBox.warning(self, "Serial", "No serial port selected")
            return
        try:
            self.client = OtaClient(SerialTransport(port))
            self.controller = UpgradeController(self.client)
            info = self.controller.connect()
            self.info_labels["ota"].setText("enabled" if info.ota_enabled else "DISABLED")
            self.info_labels["active"].setText("A / Bank0" if info.active_slot == 0 else "B / Bank1")
            self.info_labels["active_phys"].setText(f"0x{info.active_physical_base:08X}")
            self.info_labels["active_access"].setText(f"0x{info.active_access_base:08X}")
            self.info_labels["vma"].setText(f"0x{info.execution_vma:08X}")
            self.info_labels["target"].setText("A / Bank0" if info.inactive_slot == 0 else "B / Bank1")
            self.info_labels["target_phys"].setText(f"0x{info.inactive_physical_base:08X}")
            self.info_labels["current_version"].setText(f"0x{info.active_version:08X}")
            self.info_labels["a_version"].setText(f"0x{info.low_version:08X}")
            self.info_labels["b_version"].setText(f"0x{info.high_version:08X}")
            self.set_connection_state(True, port)
            self.append_log(f"Connected to {port}")
        except Exception as exc:
            if self.client is not None:
                self.client.close()
            self.client = None
            self.controller = None
            self.set_connection_state(False)
            QMessageBox.critical(self, "Connection failed", str(exc))

    def disconnect_device(self) -> None:
        if self.worker_thread is not None:
            QMessageBox.warning(self, "Serial", "Cancel the active upgrade before disconnecting")
            return
        if self.client is not None:
            self.client.close()
        self.client = None
        self.controller = None
        self.set_connection_state(False)
        self.append_log("Disconnected")

    def set_connection_state(self, connected: bool, port: str = "") -> None:
        self.info_group.setEnabled(connected)
        self.port_combo.setEnabled(not connected)
        self.refresh_button.setEnabled(not connected)
        self.connect_button.setText("Disconnect" if connected else "Connect")
        if connected:
            self.connection_status.setText(f"● Connected · {port}")
            self.connection_status.setStyleSheet("color: #138a36; font-weight: 700;")
            self.connection_group.setStyleSheet(
                "QGroupBox { border: 1px solid #39a75a; border-radius: 5px; margin-top: 8px; }"
                "QGroupBox::title { subcontrol-origin: margin; left: 10px; padding: 0 4px; color: #138a36; }"
            )
        else:
            self.connection_status.setText("● Disconnected")
            self.connection_status.setStyleSheet("color: #8a8a8a; font-weight: 600;")
            self.connection_group.setStyleSheet("")
            for label in self.info_labels.values():
                label.setText("-")
        self.update_upgrade_enabled()

    def update_upgrade_enabled(self) -> None:
        self.upgrade_button.setEnabled(
            self.controller is not None and self.package is not None and self.worker_thread is None
        )

    def select_package(self) -> None:
        path, _ = QFileDialog.getOpenFileName(self, "Select OTA package", "", "OTA package (*.pkg)")
        if not path:
            return
        self.load_package(path)

    def load_package(self, path: str | Path) -> bool:
        try:
            self.package = OtaPackage.load(path)
            self.package_path.setText(str(Path(path)))
            self.package_version.setText(f"0x{self.package.header.version:08X}")
            self.package_size.setText(f"{self.package.header.image_size:,} bytes")
            self.append_log("Package parsed and CRC verified")
            self.update_upgrade_enabled()
            return True
        except Exception as exc:
            self.package = None
            self.update_upgrade_enabled()
            QMessageBox.critical(self, "Invalid package", str(exc))
            return False

    @Slot(object)
    def on_package_created(self, result) -> None:
        if self.load_package(result.output_package):
            self.tabs.setCurrentIndex(0)
            self.append_log(
                f"Loaded package generated from IDE HEX: APP {result.info.variant}, "
                f"version 0x{result.info.version:08X}"
            )

    def start_upgrade(self) -> None:
        if self.controller is None or self.package is None:
            QMessageBox.warning(self, "Upgrade", "Connect the device and select a valid package first")
            return
        self.progress_bar.setValue(0)
        self.progress_bar.setRange(0, 0)
        self.wait_por_label.clear()
        self.phase_label.setText("Preparing...")
        self.upgrade_button.setEnabled(False)
        self.cancel_button.setEnabled(True)
        self.connect_button.setEnabled(False)

        thread = QThread(self)
        worker = UpgradeWorker(self.controller, self.package)
        worker.moveToThread(thread)
        thread.started.connect(worker.run)
        worker.progress.connect(self.on_progress)
        worker.log.connect(self.append_log)
        worker.succeeded.connect(self.on_success)
        worker.failed.connect(self.on_failure)
        worker.finished.connect(thread.quit)
        worker.finished.connect(worker.deleteLater)
        thread.finished.connect(thread.deleteLater)
        thread.finished.connect(self.on_worker_finished)
        self.worker_thread = thread
        self.worker = worker
        thread.start()

    @Slot(object)
    def on_progress(self, value: UpgradeProgress) -> None:
        if value.indeterminate:
            self.progress_bar.setRange(0, 0)
        else:
            self.progress_bar.setRange(0, 10000)
            self.progress_bar.setValue(round(value.percent * 100))
        self.speed_label.setText(f"{value.bytes_per_second / 1024:.1f} KiB/s")
        self.elapsed_label.setText(f"{value.elapsed_seconds:.1f} s")
        self.phase_label.setText(value.message or value.phase.value.title())
        self.cancel_button.setEnabled(value.phase.value in ("erasing", "transferring"))

    @Slot(object)
    def on_success(self, result: UpgradeResult) -> None:
        self.progress_bar.setRange(0, 10000)
        self.progress_bar.setValue(10000)
        message = (
            f"WAIT_POR: target {'A' if result.target_slot == 0 else 'B'} "
            f"physical 0x{result.target_physical_base:08X}, version 0x{result.package_version:08X}"
        )
        self.wait_por_label.setText("WAIT_POR")
        self.wait_por_label.setStyleSheet("color: #b06000; font-weight: 700;")
        self.phase_label.setText("Complete — physical POR required")
        self.append_log(message)
        QMessageBox.information(self, "Upgrade complete", message + "\nPerform a physical POR to switch banks.")

    @Slot(str)
    def on_failure(self, message: str) -> None:
        self.progress_bar.setRange(0, 10000)
        self.phase_label.setText("Failed")
        self.append_log("ERROR: " + message)
        QMessageBox.critical(self, "Upgrade failed", message)

    def cancel_upgrade(self) -> None:
        if self.controller is not None:
            self.controller.cancel()
            self.append_log("Cancellation requested")

    def on_worker_finished(self) -> None:
        self.worker_thread = None
        self.worker = None
        self.update_upgrade_enabled()
        self.cancel_button.setEnabled(False)
        self.connect_button.setEnabled(True)

    def closeEvent(self, event) -> None:  # noqa: N802 - Qt API
        if self.controller is not None:
            self.controller.cancel()
        if self.client is not None:
            self.client.close()
        super().closeEvent(event)


def main() -> int:
    app = QApplication(sys.argv)
    window = MainWindow()
    window.show()
    return app.exec()


if __name__ == "__main__":
    raise SystemExit(main())
