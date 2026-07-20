#!/usr/bin/env python3

from __future__ import annotations

import tempfile
import unittest
from pathlib import Path
import sys

sys.path.insert(0, str(Path(__file__).resolve().parent))
import fc7300_nvr_config_tool as tool


DEFAULT_HEX = Path(__file__).resolve().parent / "reference" / "FC73000F4MDDT1C_Default.hex"


class NvrConfigToolTests(unittest.TestCase):
    def setUp(self) -> None:
        self.memory = tool.read_ihex(DEFAULT_HEX)
        tool.validate_nvr_image(self.memory, tool.NVR_BASE, tool.NVR_SIZE)

    def test_default_hex_is_complete_2kb_image(self) -> None:
        self.assertEqual(len(self.memory), 0x800)
        self.assertEqual(min(self.memory), 0x04400000)
        self.assertEqual(max(self.memory), 0x044007FF)

    def test_ihex_round_trip(self) -> None:
        with tempfile.TemporaryDirectory() as temp_dir:
            output = Path(temp_dir) / "roundtrip.hex"
            tool.write_ihex(self.memory, output)
            self.assertEqual(tool.read_ihex(output), self.memory)

    def test_ota_patch_changes_only_two_words_and_preserves_reserved_bits(self) -> None:
        output = dict(self.memory)
        report = tool.apply_ota_config(
            output,
            tool.NVR_BASE,
            {
                "enabled": True,
                "low_start": "0x01000000",
                "low_end": "0x010FFFFF",
                "high_start": "0x01100000",
                "high_end": "0x011FFFFF",
                "version_offset": "0x000FF000",
                "version_select": "high",
            },
        )
        differences = tool.word_diff(self.memory, output, tool.NVR_BASE, tool.NVR_SIZE)
        self.assertEqual([item["register"] for item in differences], ["OTAC0", "OTAC_HIGH0"])
        self.assertEqual(tool.read_word(output, 0x04400100), 0xFFFFF000FFFF80EA)
        self.assertEqual(tool.read_word(output, 0x04400108), 0xFFFFFFFFFFFF8055)
        self.assertEqual(report["effective_bank_offset"], "0x1FF000")

    def test_ota_indicator_offset_requires_16_byte_alignment(self) -> None:
        with self.assertRaisesRegex(ValueError, "16-byte aligned"):
            tool.apply_ota_config(
                dict(self.memory),
                tool.NVR_BASE,
                {"version_offset": "0x000FF008", "version_select": "high"},
            )

    def test_sensitive_register_requires_explicit_acknowledgement(self) -> None:
        with self.assertRaisesRegex(ValueError, "sensitive NVR word"):
            tool.apply_register_patches(
                dict(self.memory),
                tool.NVR_BASE,
                {"DC1": {"fields": {"PFWP": "0xFFF"}}},
                allow_sensitive=False,
            )

    def test_field_overflow_is_rejected(self) -> None:
        with self.assertRaisesRegex(ValueError, "does not fit"):
            tool.apply_register_patches(
                dict(self.memory),
                tool.NVR_BASE,
                {"BC0": {"fields": {"BOOTROM": 2}}},
                allow_sensitive=False,
            )


if __name__ == "__main__":
    unittest.main()
