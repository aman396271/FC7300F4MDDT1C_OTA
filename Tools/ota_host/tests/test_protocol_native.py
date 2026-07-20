from __future__ import annotations

import shutil
import subprocess
from pathlib import Path

import pytest

from ..protocol import Command, Frame, encode_frame


def test_c_and_python_protocol_vectors_match(tmp_path: Path) -> None:
    gcc = shutil.which("gcc")
    if gcc is None:
        pytest.skip("native gcc is not installed")
    project = Path(__file__).resolve().parents[3]
    executable = tmp_path / "native_protocol_vector.exe"
    subprocess.run(
        [
            gcc,
            "-std=c11",
            "-Wall",
            "-Wextra",
            "-Werror",
            "-I",
            str(project / "Include"),
            str(project / "Sources" / "ota_protocol.c"),
            str(project / "Sources" / "ota_crc32.c"),
            str(Path(__file__).with_name("native_protocol_vector.c")),
            "-o",
            str(executable),
        ],
        check=True,
        cwd=project,
    )
    result = subprocess.run([str(executable)], check=True, capture_output=True, text=True)
    expected = encode_frame(Frame(Command.DATA, 0x12345678, 0x100, b"\x00\x01\x02\x00\xFF"))
    assert bytes.fromhex(result.stdout.strip()) == expected
