"""pyserial implementation of the OTA transport."""

from __future__ import annotations

import serial
from serial.tools import list_ports

from .base import Transport, TransportError


class SerialTransport(Transport):
    def __init__(self, port: str, baudrate: int = 115200) -> None:
        self.port = port
        self.baudrate = baudrate
        self._serial: serial.Serial | None = None

    @staticmethod
    def list_ports() -> list[str]:
        return [item.device for item in list_ports.comports()]

    def open(self) -> None:
        try:
            self._serial = serial.Serial(self.port, self.baudrate, timeout=0, write_timeout=2)
            self._serial.reset_input_buffer()
        except serial.SerialException as exc:
            raise TransportError(str(exc)) from exc

    def close(self) -> None:
        if self._serial is not None:
            self._serial.close()
            self._serial = None

    @property
    def is_open(self) -> bool:
        return self._serial is not None and self._serial.is_open

    def write(self, data: bytes) -> None:
        if not self.is_open:
            raise TransportError("serial port is not open")
        try:
            assert self._serial is not None
            self._serial.write(data)
            self._serial.flush()
        except serial.SerialException as exc:
            raise TransportError(str(exc)) from exc

    def read(self, size: int, timeout: float) -> bytes:
        if not self.is_open:
            raise TransportError("serial port is not open")
        assert self._serial is not None
        previous = self._serial.timeout
        try:
            self._serial.timeout = timeout
            return self._serial.read(size)
        except serial.SerialException as exc:
            raise TransportError(str(exc)) from exc
        finally:
            self._serial.timeout = previous
