# FC7300 OTA NVR Config Tool

This small app generates Intel HEX records for FC7300 hardware OTA settings from a JSON description. It is intentionally separate from the firmware so an Agent or test engineer can regenerate NVR settings without touching C code.

Reference used for the field definitions: `02_MD/FC7300F4MxxxT1C Reference Manual_V0.3.1_NVR.pdf`.

- Table 54: `OTAC0` and `OTAC_HIGH0` NVR layout.
- Table 55: PFlash OTA content/indicator layout.

The tool can generate two independent artifacts:

- NVR HEX: writes `OTAC0` at NVR offset `0x100` and `OTAC_HIGH0` at `0x108`.
- OTA indicator HEX: writes the 16-byte PFlash OTA content at the effective Bank0/Bank1 indicator address.

## Default Demo Values

Input:

```json
{
  "nvr_base": "0x04400000",
  "otac0_offset": "0x100",
  "otac_high0_offset": "0x108",
  "bank0_base": "0x01000000",
  "bank1_base": "0x01200000",
  "bank_size": "0x00200000",
  "ota0": {
    "enabled": true,
    "low_start": "0x01000000",
    "low_end": "0x010FFFFF",
    "high_start": "0x01100000",
    "high_end": "0x011FFFFF",
    "version_offset": "0x000FF008",
    "version_select": "high"
  },
  "ota_indicator": {
    "enabled": true,
    "layout": "version_then_valid_code",
    "low_version": "0x00010000",
    "high_version": "0x00010100"
  }
}
```

Encoded fields:

```text
OTAC0[4:0]   = 0b01010
OTAC0[14:8]  = lower 1MB start 8KB block index
OTAC0[30:24] = lower 1MB end 8KB block index
OTAC0[51:32] = raw version logical offset inside the selected 1MB half

OTAC_HIGH0[7:0]   = version select, 0xAA means lower 1MB, other values mean high 1MB
OTAC_HIGH0[14:8]  = upper 1MB start 8KB block index
OTAC_HIGH0[30:24] = upper 1MB end 8KB block index
```

For the F4MDD 2 MB Bank0/1 swap demo, the NVR raw version offset remains
`0x000FF008`.  Because `version_select` is `high`, the effective bank offset is
`0x001FF008`, so the generated PFlash OTA indicators are:

```text
Bank0: 0x011FF008
Bank1: 0x013FF008
```

PFlash OTA content generated from RM Table 55:

```text
lower 64 bits = { bitwise_not(version[31:0]), version[31:0] }
upper 64 bits = valid code

F4MDDxxxT1C valid code = 0xFC60FACE88886666
F4MDSxxxT1C valid code = 0xFC62FACE88886666
```

With the default little-endian `version_then_valid_code` layout, version `0x00010100` is emitted as:

```text
00 01 01 00 FF FE FE FF 66 66 88 88 CE FA 60 FC
```

## Usage

Generate a starting config:

```sh
python Tools/nvr_ota_config_tool.py init --output Tools/my_ota_nvr.json
```

Generate HEX, binary patch and JSON report:

```sh
python Tools/nvr_ota_config_tool.py generate ^
  --config Tools/my_ota_nvr.json ^
  --output-hex Tools/fc7300_ota_nvr.hex ^
  --output-ota-indicator-hex Tools/fc7300_ota_indicator.hex ^
  --output-bin Tools/fc7300_ota_nvr.bin ^
  --output-ota-indicator-bin Tools/fc7300_ota_indicator.bin ^
  --report Tools/fc7300_ota_nvr.report.json
```

Agent-friendly call:

```sh
python Tools/nvr_ota_config_tool.py generate --config Tools/my_ota_nvr.json --stdout-json
```

For Agent integration, prefer `--stdout-json` and read these report fields:

```text
nvr_records[]             absolute NVR addresses, values, and little-endian bytes
decoded                   decoded OTAC0/OTAC_HIGH0 fields
ota_indicator_records[]   absolute PFlash addresses and bytes for the OTA content
warnings                  merge/programming risks
```

Decode existing values:

```sh
python Tools/nvr_ota_config_tool.py decode --otac0 0x000FF0087F00000A --otac-high0 0x000000007F000055
```

## Important Notes

The generated HEX writes only 16 bytes by default: 8 bytes at `NVR_BASE + 0x100` and 8 bytes at `NVR_BASE + 0x108`.

Do not erase the whole NVR sector with this partial HEX unless your programmer merges it with an existing known-good NVR image.  NVR contains more than OTA configuration and a wrong erase can brick the device.

`version_offset` must be the PFlash logical offset inside the selected 1MB half.  For the current F4MDD 2 MB Bank0/1 demo it is still `0x000FF008`, not `0x001FF008`, not a full PFlash address, and not a DFlash address.  `version_select=high` is what moves the effective bank offset to `0x001FF008`.

`OTAC0[51:32]` only tells the hardware where to read the PFlash OTA content inside the selected 1MB half. It does not store the version in NVR. For a valid hardware OTA image, each 2 MB bank must place the Table 55 OTA content at the same effective bank offset.

If later FAEs confirm the 16-byte Table 55 order is valid-code first for this toolchain/programming flow, change `"layout"` to `"valid_code_then_version"` in JSON. The default is based on the RM wording that describes lower 64 bits as the version/check field and upper 64 bits as the valid code.
