"""Request/response client for the FC7300 UART OTA protocol."""

from __future__ import annotations

import time
from dataclasses import dataclass
from typing import Callable

from .package import PackageHeader
from .protocol import (
    FLAG_RESPONSE,
    MAX_PAYLOAD,
    Command,
    Frame,
    FrameStreamDecoder,
    HELLO_STRUCT,
    INFO_STRUCT,
    Status,
    START_RESPONSE_STRUCT,
    STATUS_STRUCT,
    encode_frame,
)
from .transport.base import Transport


class OtaClientError(RuntimeError):
    pass


class OtaTimeoutError(OtaClientError):
    pass


class OtaNackError(OtaClientError):
    def __init__(self, status: Status, message: str | None = None):
        super().__init__(message or f"device rejected request: {status.name}")
        self.status = status


@dataclass(frozen=True)
class DeviceInfo:
    active_slot: int
    inactive_slot: int
    ota_enabled: bool
    ota_locked: bool
    active_physical_base: int
    inactive_physical_base: int
    active_access_base: int
    inactive_access_base: int
    execution_vma: int
    low_version: int
    high_version: int
    validity_flags: int
    fmc_ota_ctrl: int
    fmc_active_version: int
    max_image_size: int

    @property
    def active_version(self) -> int:
        return self.low_version if self.active_slot == 0 else self.high_version


@dataclass(frozen=True)
class UpdateStatus:
    state: int
    target_slot: int
    received_bytes: int
    image_size: int
    expected_sequence: int
    last_error: int


class OtaClient:
    def __init__(self, transport: Transport, timeout: float = 1.0, retries: int = 3) -> None:
        self.transport = transport
        self.timeout = timeout
        self.retries = retries
        self.sequence = 0
        self.decoder = FrameStreamDecoder()
        self.max_payload = MAX_PAYLOAD

    def connect(self) -> None:
        if not self.transport.is_open:
            self.transport.open()
        self.hello()

    def close(self) -> None:
        self.transport.close()

    def _request(
        self,
        command: Command,
        *,
        offset: int = 0,
        payload: bytes = b"",
        timeout: float | None = None,
        wait_callback: Callable[[float], None] | None = None,
    ) -> Frame:
        request = Frame(command=command, sequence=self.sequence, offset=offset, payload=payload)
        encoded = encode_frame(request)
        wait_time = self.timeout if timeout is None else timeout
        request_started = time.monotonic()
        next_wait_update = request_started
        for attempt in range(self.retries + 1):
            self.transport.write(encoded)
            deadline = time.monotonic() + wait_time
            while time.monotonic() < deadline:
                chunk = self.transport.read(256, min(0.05, max(0.0, deadline - time.monotonic())))
                if not chunk:
                    now = time.monotonic()
                    if wait_callback is not None and now >= next_wait_update:
                        wait_callback(now - request_started)
                        next_wait_update = now + 0.2
                    continue
                for response in self.decoder.feed(chunk):
                    if (
                        response.is_response
                        and response.command == command
                        and response.sequence == self.sequence
                    ):
                        self.sequence = (self.sequence + 1) & 0xFFFFFFFF
                        if response.status not in (Status.OK, Status.WAIT_POR):
                            raise OtaNackError(response.status)
                        return response
            if attempt == self.retries:
                break
        raise OtaTimeoutError(f"timeout waiting for {command.name} after {self.retries + 1} attempts")

    def hello(self) -> None:
        response = self._request(Command.HELLO)
        if len(response.payload) != HELLO_STRUCT.size:
            raise OtaClientError("invalid HELLO response")
        minimum, maximum, max_payload = HELLO_STRUCT.unpack(response.payload)
        if not minimum <= 1 <= maximum:
            raise OtaClientError("device does not support host protocol version")
        self.max_payload = min(MAX_PAYLOAD, max_payload)

    def get_info(self) -> DeviceInfo:
        response = self._request(Command.GET_INFO)
        if len(response.payload) != INFO_STRUCT.size:
            raise OtaClientError("invalid GET_INFO response")
        values = INFO_STRUCT.unpack(response.payload)
        return DeviceInfo(values[0], values[1], bool(values[2]), bool(values[3]), *values[4:])

    def start_update(
        self,
        header: PackageHeader,
        timeout: float = 180.0,
        wait_callback: Callable[[float], None] | None = None,
    ) -> tuple[int, int, int]:
        response = self._request(
            Command.START_UPDATE,
            payload=header.raw,
            timeout=timeout,
            wait_callback=wait_callback,
        )
        if len(response.payload) != START_RESPONSE_STRUCT.size:
            raise OtaClientError("invalid START_UPDATE response")
        return START_RESPONSE_STRUCT.unpack(response.payload)

    def write_data(self, offset: int, data: bytes) -> int:
        if not data or len(data) > self.max_payload:
            raise ValueError("DATA payload length is outside negotiated limits")
        response = self._request(Command.DATA, offset=offset, payload=data)
        expected = offset + len(data)
        if response.offset != expected:
            raise OtaClientError(f"device ACK offset {response.offset} does not match {expected}")
        return response.offset

    def finish(
        self,
        offset: int,
        timeout: float = 30.0,
        wait_callback: Callable[[float], None] | None = None,
    ) -> Frame:
        response = self._request(
            Command.FINISH,
            offset=offset,
            timeout=timeout,
            wait_callback=wait_callback,
        )
        if response.status != Status.WAIT_POR:
            raise OtaClientError("FINISH did not return WAIT_POR")
        return response

    def abort(self) -> None:
        self._request(Command.ABORT)

    def get_status(self) -> UpdateStatus:
        response = self._request(Command.GET_STATUS)
        if len(response.payload) != STATUS_STRUCT.size:
            raise OtaClientError("invalid GET_STATUS response")
        state, target, _, received, image_size, expected_seq, last_error = STATUS_STRUCT.unpack(response.payload)
        return UpdateStatus(state, target, received, image_size, expected_seq, last_error)
