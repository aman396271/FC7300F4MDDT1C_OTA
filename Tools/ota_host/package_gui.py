"""PySide6 GUI for converting an FCIDE HEX into FC7300 OTA artifacts."""

from __future__ import annotations

import sys
from pathlib import Path

from PySide6.QtCore import Qt, Signal
from PySide6.QtWidgets import (
    QApplication,
    QCheckBox,
    QFileDialog,
    QFormLayout,
    QGroupBox,
    QHBoxLayout,
    QLabel,
    QLineEdit,
    QMainWindow,
    QMessageBox,
    QPushButton,
    QPlainTextEdit,
    QVBoxLayout,
    QWidget,
)

from .ide_hex import IdeHexError, IdeHexInfo, inspect_ide_hex, pack_ide_hex


class PackageWidget(QWidget):
    package_created = Signal(object)

    def __init__(self) -> None:
        super().__init__()
        self._info: IdeHexInfo | None = None

        layout = QVBoxLayout(self)

        source_group = QGroupBox("FCIDE output")
        source_layout = QFormLayout(source_group)
        self.input_edit = QLineEdit()
        input_button = QPushButton("Browse...")
        input_button.clicked.connect(self._browse_input)
        input_row = QHBoxLayout()
        input_row.addWidget(self.input_edit, 1)
        input_row.addWidget(input_button)
        source_layout.addRow("IDE HEX", input_row)

        self.output_edit = QLineEdit(str((Path.cwd() / "out" / "ide_hex_package").resolve()))
        output_button = QPushButton("Browse...")
        output_button.clicked.connect(self._browse_output)
        output_row = QHBoxLayout()
        output_row.addWidget(self.output_edit, 1)
        output_row.addWidget(output_button)
        source_layout.addRow("Output folder", output_row)

        self.timestamp_edit = QLineEdit("0")
        self.timestamp_edit.setToolTip("Optional uint32 value; 0 gives reproducible output")
        source_layout.addRow("Build timestamp", self.timestamp_edit)
        self.dense_check = QCheckBox("Generate complete 2 MB Bank HEX (recommended)")
        self.dense_check.setChecked(True)
        self.dense_check.setToolTip(
            "Writes explicit FF records across the complete Bank so stale bytes cannot remain"
        )
        source_layout.addRow("JTAG HEX", self.dense_check)
        layout.addWidget(source_group)

        info_group = QGroupBox("Detected image")
        info_layout = QFormLayout(info_group)
        self.info_labels: dict[str, QLabel] = {}
        for key, title in (
            ("variant", "Variant / physical Bank"),
            ("physical", "Physical range"),
            ("vma", "Execution VMA"),
            ("version", "Embedded version"),
            ("header", "Header physical address"),
            ("reset", "Reset handler"),
        ):
            label = QLabel("-")
            label.setTextInteractionFlags(Qt.TextSelectableByMouse)
            self.info_labels[key] = label
            info_layout.addRow(title, label)
        layout.addWidget(info_group)

        button_row = QHBoxLayout()
        self.inspect_button = QPushButton("Inspect HEX")
        self.inspect_button.clicked.connect(self._inspect)
        self.pack_button = QPushButton("Generate OTA HEX + PKG")
        self.pack_button.setEnabled(False)
        self.pack_button.clicked.connect(self._pack)
        button_row.addStretch(1)
        button_row.addWidget(self.inspect_button)
        button_row.addWidget(self.pack_button)
        layout.addLayout(button_row)

        self.log = QPlainTextEdit()
        self.log.setReadOnly(True)
        self.log.setPlaceholderText(
            "The application reads the version from the linked OTA header; "
            "there is no independent version input."
        )
        layout.addWidget(self.log, 1)

    def _browse_input(self) -> None:
        path, _ = QFileDialog.getOpenFileName(self, "Select FCIDE Intel HEX", "", "Intel HEX (*.hex)")
        if path:
            self.input_edit.setText(path)
            self.output_edit.setText(str((Path(path).parent / "ota_output").resolve()))
            self._inspect()

    def _browse_output(self) -> None:
        path = QFileDialog.getExistingDirectory(self, "Select output folder", self.output_edit.text())
        if path:
            self.output_edit.setText(path)

    def _show_error(self, title: str, exc: BaseException) -> None:
        self.log.appendPlainText(f"ERROR: {exc}")
        QMessageBox.critical(self, title, str(exc))

    def _inspect(self) -> None:
        try:
            info = inspect_ide_hex(self.input_edit.text().strip())
        except (IdeHexError, OSError, ValueError) as exc:
            self._info = None
            self.pack_button.setEnabled(False)
            self._show_error("Invalid IDE HEX", exc)
            return
        self._info = info
        self.info_labels["variant"].setText(f"APP {info.variant} / Bank {info.variant}")
        self.info_labels["physical"].setText(
            f"0x{info.physical_base:08X} - 0x{info.physical_end:08X}"
        )
        self.info_labels["vma"].setText(f"0x{info.execution_vma:08X}")
        self.info_labels["version"].setText(f"0x{info.version:08X}")
        self.info_labels["header"].setText(f"0x{info.header_address:08X}")
        self.info_labels["reset"].setText(f"0x{info.reset_handler:08X}")
        self.pack_button.setEnabled(True)
        self.log.appendPlainText(
            f"Validated {info.source.name}: APP {info.variant}, version 0x{info.version:08X}, "
            f"physical 0x{info.physical_base:08X}"
        )

    def _pack(self) -> None:
        if self._info is None:
            self._inspect()
            if self._info is None:
                return
        try:
            timestamp = int(self.timestamp_edit.text().strip(), 0)
            result = pack_ide_hex(
                self.input_edit.text().strip(),
                self.output_edit.text().strip(),
                timestamp=timestamp,
                dense_hex=self.dense_check.isChecked(),
            )
        except (IdeHexError, OSError, ValueError) as exc:
            self._show_error("Packaging failed", exc)
            return
        self.log.appendPlainText(f"OTA HEX: {result.output_hex}")
        self.log.appendPlainText(f"UART package: {result.output_package}")
        self.log.appendPlainText(f"Report: {result.output_report}")
        self.log.appendPlainText(f"Payload CRC32: 0x{result.payload_crc32:08X}")
        self.log.appendPlainText(f"Header CRC32: 0x{result.header_crc32:08X}")
        self.package_created.emit(result)
        QMessageBox.information(
            self,
            "Packaging complete",
            "Generated a version-consistent JTAG HEX and UART .pkg.\n\n"
            f"{result.output_hex}\n{result.output_package}",
        )


class PackageWindow(QMainWindow):
    def __init__(self) -> None:
        super().__init__()
        self.setWindowTitle("FC7300F4MDDT1C IDE HEX OTA Packer")
        self.resize(850, 620)
        self.package_widget = PackageWidget()
        self.setCentralWidget(self.package_widget)


def main() -> int:
    app = QApplication.instance() or QApplication(sys.argv)
    window = PackageWindow()
    window.show()
    return app.exec()


if __name__ == "__main__":
    raise SystemExit(main())
