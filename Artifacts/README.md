# FC7300 OTA demo artifacts

This directory contains the final HEX files for programming and inspection.
Intermediate ELF, BIN and package files are generated under `out/ab_demo`.

| File | Address range | Purpose |
|---|---|---|
| `FC7300_AB_PFlash_Demo.hex` | `0x01000000-0x013FFFFF` | Combined APP A hardware version `0x00010000` and APP B hardware version `0x00020000` |
| `FC7300_NVR_Default.hex` | `0x04400000-0x044007FF` | Complete 2 KB default NVR with hardware OTA disabled |
| `FC7300_NVR_OTA_Enabled.hex` | `0x04400000-0x044007FF` | Complete 2 KB NVR with hardware OTA enabled |

The two NVR files are standalone NVR images. They contain no PFlash records and
can be imported directly into a programming or HEX inspection tool.

For the POR swap test, program `FC7300_AB_PFlash_Demo.hex` with the default NVR,
observe APP A, then program only `FC7300_NVR_OTA_Enabled.hex` without erasing
PFlash and perform POR to observe APP B.

Regenerate all artifacts from the project directory:

```powershell
python Tools\build_ab_demo.py
```
