from pathlib import Path

import pytest

from Tools.generate_ota_version import load_versions, render_header


PROJECT = Path(__file__).resolve().parents[3]
MANIFEST = PROJECT / "Tools" / "ota_versions.json"


def test_default_version_profile_matches_demo() -> None:
    assert load_versions(MANIFEST) == {"A": 1, "B": 2}


def test_return_a_profile_uses_v3_without_changing_b() -> None:
    assert load_versions(MANIFEST, "return_a_v3") == {"A": 3, "B": 2}


def test_generated_header_contains_both_selected_versions() -> None:
    header = render_header(load_versions(MANIFEST, "return_a_v3"))
    assert "OTA_VERSION_A                    (0x00000003UL)" in header
    assert "OTA_VERSION_B                    (0x00000002UL)" in header


def test_unknown_version_profile_is_rejected() -> None:
    with pytest.raises(ValueError, match="unknown OTA version profile"):
        load_versions(MANIFEST, "missing")
