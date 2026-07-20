"""Transport abstraction shared by serial now and CAN/UDS later."""

from __future__ import annotations

from abc import ABC, abstractmethod


class TransportError(IOError):
    pass


class Transport(ABC):
    @abstractmethod
    def open(self) -> None: ...

    @abstractmethod
    def close(self) -> None: ...

    @abstractmethod
    def write(self, data: bytes) -> None: ...

    @abstractmethod
    def read(self, size: int, timeout: float) -> bytes: ...

    @property
    @abstractmethod
    def is_open(self) -> bool: ...
