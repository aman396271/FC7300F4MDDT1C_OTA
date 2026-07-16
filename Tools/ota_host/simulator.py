"""In-memory FC7300 UART OTA device used by integration tests and demos."""

from __future__ import annotations

import struct
import time
from dataclasses import dataclass

from .package import (
    HEADER_SIZE,
    HEADER_STRUCT as PACKAGE_HEADER_STRUCT,
    HEADER_VERSION,
    IMAGE_MAGIC,
    VALID_CODE_HI,
    VALID_CODE_LO,
    VALID_FLAG,
    crc32,
)
from .protocol import (
    FLAG_ERROR,
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


@dataclass
class SimulatorConfig:
    ota_enabled: bool = True
    active_slot: int = 0
    low_version: int = 1
    high_version: int = 0
    finish_crc_failure: bool = False
    max_image_size: int = 0x001FF000


class SimulatedDevice:
    def __init__(self, config: SimulatorConfig | None = None) -> None:
        self.config = config or SimulatorConfig()
        self.decoder = FrameStreamDecoder()
        self.expected_sequence: int | None = None
        self.last_request: Frame | None = None
        self.last_response: bytes | None = None
        self.session = False
        self.target_slot = 1 - self.config.active_slot
        self.header = b""
        self.image_size = 0
        self.image_crc = 0
        self.target_version = 0
        self.received = bytearray()
        self.last_error = Status.OK

    def _response(
        self,
        request: Frame,
        status: Status = Status.OK,
        payload: bytes = b"",
        offset: int | None = None,
    ) -> bytes:
        flags = FLAG_RESPONSE | (FLAG_ERROR if status not in (Status.OK, Status.WAIT_POR) else 0)
        return encode_frame(
            Frame(
                command=request.command,
                sequence=request.sequence,
                offset=request.offset if offset is None else offset,
                payload=payload,
                status=status,
                flags=flags,
            )
        )

    def _active_version(self) -> int:
        return self.config.low_version if self.config.active_slot == 0 else self.config.high_version

    def _validate_start_header(self, raw: bytes) -> Status:
        if len(raw) != HEADER_SIZE:
            return Status.BAD_LENGTH
        fields = PACKAGE_HEADER_STRUCT.unpack(raw)
        version, inverted, valid_lo, valid_hi, magic, header_version = fields[:6]
        image_size, image_crc, _, valid_flag, header_crc = fields[6:11]
        header_for_crc = bytearray(raw)
        struct.pack_into("<I", header_for_crc, 40, 0)
        if (
            not 0 < version < 0xFFFFFFFF
            or inverted != ((~version) & 0xFFFFFFFF)
            or (valid_lo, valid_hi) != (VALID_CODE_LO, VALID_CODE_HI)
            or magic != IMAGE_MAGIC
            or header_version != HEADER_VERSION
            or valid_flag != VALID_FLAG
            or crc32(header_for_crc) != header_crc
            or not 0 < image_size <= self.config.max_image_size
        ):
            return Status.INVALID_PACKAGE
        if version <= self._active_version():
            return Status.VERSION_REJECTED
        self.header = raw
        self.image_size = image_size
        self.image_crc = image_crc
        self.target_version = version
        return Status.OK

    def _process(self, request: Frame) -> bytes:
        if request.command == Command.HELLO:
            self.expected_sequence = (request.sequence + 1) & 0xFFFFFFFF
            return self._response(request, payload=HELLO_STRUCT.pack(1, 1, MAX_PAYLOAD))

        if self.expected_sequence is None or request.sequence != self.expected_sequence:
            expected = 0 if self.expected_sequence is None else self.expected_sequence
            return self._response(request, Status.BAD_SEQUENCE, offset=expected)
        self.expected_sequence = (self.expected_sequence + 1) & 0xFFFFFFFF

        if request.command == Command.GET_INFO:
            valid_flags = 0
            if self.config.low_version:
                valid_flags |= 0x05
            if self.config.high_version:
                valid_flags |= 0x0A
            active_phys = 0x01000000 if self.config.active_slot == 0 else 0x01200000
            inactive_phys = 0x01200000 if self.config.active_slot == 0 else 0x01000000
            active_access = 0x01000000
            inactive_access = 0x01200000
            payload = INFO_STRUCT.pack(
                self.config.active_slot,
                1 - self.config.active_slot,
                int(self.config.ota_enabled),
                0,
                active_phys,
                inactive_phys,
                active_access,
                inactive_access,
                0x01000000,
                self.config.low_version,
                self.config.high_version,
                valid_flags,
                0x0A | (self.config.active_slot << 5),
                self._active_version(),
                self.config.max_image_size,
            )
            return self._response(request, payload=payload)

        if request.command == Command.START_UPDATE:
            if self.session:
                return self._response(request, Status.SESSION_BUSY)
            if not self.config.ota_enabled:
                return self._response(request, Status.OTA_NOT_ENABLED)
            status = self._validate_start_header(request.payload)
            if status != Status.OK:
                self.last_error = status
                return self._response(request, status)
            self.session = True
            self.target_slot = 1 - self.config.active_slot
            self.received.clear()
            target_phys = 0x01000000 if self.target_slot == 0 else 0x01200000
            payload = START_RESPONSE_STRUCT.pack(self.target_slot, target_phys, self.image_size)
            return self._response(request, payload=payload)

        if request.command == Command.DATA:
            if not self.session:
                return self._response(request, Status.SESSION_REQUIRED)
            if request.offset != len(self.received):
                return self._response(request, Status.BAD_OFFSET, offset=len(self.received))
            if len(self.received) + len(request.payload) > self.image_size:
                return self._response(request, Status.BAD_LENGTH, offset=len(self.received))
            self.received.extend(request.payload)
            return self._response(request, offset=len(self.received))

        if request.command == Command.FINISH:
            if not self.session:
                return self._response(request, Status.SESSION_REQUIRED)
            if len(self.received) != self.image_size:
                return self._response(request, Status.BAD_LENGTH, offset=len(self.received))
            if self.config.finish_crc_failure or crc32(self.received) != self.image_crc:
                self.last_error = Status.IMAGE_CRC_ERROR
                return self._response(request, Status.IMAGE_CRC_ERROR, offset=len(self.received))
            if self.target_slot == 0:
                self.config.low_version = self.target_version
            else:
                self.config.high_version = self.target_version
            self.session = False
            return self._response(
                request,
                Status.WAIT_POR,
                struct.pack("<B3xI", self.target_slot, self.target_version),
                len(self.received),
            )

        if request.command == Command.ABORT:
            self.session = False
            self.received.clear()
            self.last_error = Status.CANCELLED
            return self._response(request)

        if request.command == Command.GET_STATUS:
            state = 1 if self.session else 0
            payload = STATUS_STRUCT.pack(
                state,
                self.target_slot,
                0,
                len(self.received),
                self.image_size,
                self.expected_sequence or 0,
                int(self.last_error),
            )
            return self._response(request, payload=payload)

        return self._response(request, Status.UNSUPPORTED_COMMAND)

    def feed(self, data: bytes) -> bytes:
        output = bytearray()
        for request in self.decoder.feed(data):
            if self.last_request == request and self.last_response is not None:
                output.extend(self.last_response)
                continue
            response = self._process(request)
            self.last_request = request
            self.last_response = response
            output.extend(response)
        return bytes(output)


class SimulatorTransport(Transport):
    def __init__(self, device: SimulatedDevice | None = None) -> None:
        self.device = device or SimulatedDevice()
        self._open = False
        self._rx = bytearray()
        self.drop_responses = 0
        self.forced_nack: Status | None = None

    def open(self) -> None:
        self._open = True

    def close(self) -> None:
        self._open = False
        self._rx.clear()

    @property
    def is_open(self) -> bool:
        return self._open

    def write(self, data: bytes) -> None:
        if not self._open:
            raise IOError("simulator transport is not open")
        response = self.device.feed(data)
        if self.drop_responses > 0:
            self.drop_responses -= 1
            return
        if self.forced_nack is not None and response:
            frames = FrameStreamDecoder().feed(response)
            if frames:
                frame = frames[0]
                response = encode_frame(
                    Frame(frame.command, frame.sequence, frame.offset, status=self.forced_nack,
                          flags=FLAG_RESPONSE | FLAG_ERROR)
                )
            self.forced_nack = None
        self._rx.extend(response)

    def read(self, size: int, timeout: float) -> bytes:
        deadline = time.monotonic() + timeout
        while not self._rx and time.monotonic() < deadline:
            time.sleep(min(0.001, timeout))
        result = bytes(self._rx[:size])
        del self._rx[:size]
        return result
