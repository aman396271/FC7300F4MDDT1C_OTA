from __future__ import annotations

import pytest

from ..client import OtaClient, OtaNackError, OtaTimeoutError
from ..protocol import Command, Frame, FrameStreamDecoder, Status, encode_frame
from ..simulator import SimulatedDevice, SimulatorConfig, SimulatorTransport
from ..upgrade_controller import UpgradeCancelled, UpgradeController, UpgradePhase
from .helpers import make_package


def connected_controller(config: SimulatorConfig | None = None, **client_args):
    transport = SimulatorTransport(SimulatedDevice(config))
    client = OtaClient(transport, timeout=0.01, **client_args)
    controller = UpgradeController(client)
    controller.connect()
    return controller, transport


def test_retry_after_lost_ack_is_idempotent() -> None:
    controller, transport = connected_controller(retries=2)
    transport.drop_responses = 1
    info = controller.get_info()
    assert info.active_physical_base == 0x01000000
    assert transport.device.expected_sequence == controller.client.sequence


def test_duplicate_data_retry_does_not_append_twice() -> None:
    controller, transport = connected_controller(retries=2)
    package = make_package(version=2, size=900)
    controller.client.start_update(package.header)
    chunk = package.payload[:controller.client.max_payload]
    transport.drop_responses = 1
    assert controller.client.write_data(0, chunk) == len(chunk)
    assert bytes(transport.device.received) == chunk


def test_bad_data_offset_is_nacked_with_no_write() -> None:
    controller, transport = connected_controller(retries=0)
    package = make_package(version=2, size=900)
    controller.client.start_update(package.header)
    with pytest.raises(OtaNackError) as exc:
        controller.client.write_data(8, package.payload[:32])
    assert exc.value.status == Status.BAD_OFFSET
    assert transport.device.received == b""
    controller.client.abort()


def test_timeout_after_all_retries() -> None:
    controller, transport = connected_controller(retries=1)
    transport.drop_responses = 2
    with pytest.raises(OtaTimeoutError):
        controller.get_info()


def test_nack_is_reported() -> None:
    controller, transport = connected_controller(retries=0)
    transport.forced_nack = Status.FLASH_ERROR
    with pytest.raises(OtaNackError) as exc:
        controller.get_info()
    assert exc.value.status == Status.FLASH_ERROR


def test_missing_sequence_is_rejected() -> None:
    device = SimulatedDevice()
    device.feed(encode_frame(Frame(Command.HELLO, 0)))
    response = device.feed(encode_frame(Frame(Command.GET_INFO, 2)))
    frame = FrameStreamDecoder().feed(response)[0]
    assert frame.status == Status.BAD_SEQUENCE
    assert frame.offset == 1


def test_complete_simulated_upgrade() -> None:
    controller, transport = connected_controller()
    package = make_package(version=2, size=1301)
    progress = []
    result = controller.upgrade(package, progress.append)
    assert result.wait_por
    assert result.target_slot == 1
    assert result.target_physical_base == 0x01200000
    assert transport.device.config.high_version == 2
    assert progress[-1].transferred == len(package.payload)
    assert progress[-1].phase == UpgradePhase.COMPLETE
    assert UpgradePhase.ERASING in {item.phase for item in progress}
    assert UpgradePhase.TRANSFERRING in {item.phase for item in progress}
    assert UpgradePhase.VERIFYING in {item.phase for item in progress}


def test_start_wait_callback_reports_retry_wait() -> None:
    controller, transport = connected_controller(retries=1)
    package = make_package(version=2, size=900)
    waits = []
    transport.drop_responses = 1
    controller.client.start_update(package.header, timeout=0.01, wait_callback=waits.append)
    assert waits


def test_transfer_interruption_keeps_old_version() -> None:
    controller, transport = connected_controller()
    package = make_package(version=2, size=1500)

    def cancel_after_first(progress) -> None:
        controller.cancel()

    with pytest.raises(UpgradeCancelled):
        controller.upgrade(package, cancel_after_first)
    assert not transport.device.session
    assert transport.device.config.high_version == 0


def test_finish_crc_failure_does_not_commit_version() -> None:
    config = SimulatorConfig(finish_crc_failure=True)
    controller, transport = connected_controller(config)
    with pytest.raises(OtaNackError) as exc:
        controller.upgrade(make_package(version=2, size=700))
    assert exc.value.status == Status.IMAGE_CRC_ERROR
    assert transport.device.config.high_version == 0


def test_older_version_is_rejected_before_start() -> None:
    controller, transport = connected_controller(SimulatorConfig(low_version=5))
    with pytest.raises(RuntimeError, match="not newer"):
        controller.upgrade(make_package(version=4))
    assert not transport.device.session


def test_device_also_rejects_older_version() -> None:
    controller, transport = connected_controller(SimulatorConfig(low_version=5))
    with pytest.raises(OtaNackError) as exc:
        controller.client.start_update(make_package(version=4).header)
    assert exc.value.status == Status.VERSION_REJECTED
    assert not transport.device.session


def test_ota_disabled_is_rejected_clearly() -> None:
    controller, _ = connected_controller(SimulatorConfig(ota_enabled=False))
    with pytest.raises(RuntimeError, match="OTA_EN"):
        controller.upgrade(make_package(version=2))
