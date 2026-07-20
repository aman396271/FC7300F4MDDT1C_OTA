# FC7300 F4MDD A/B POR swap test

This test proves the hardware behavior requested for the demo:

1. With the default NVR, hardware OTA is disabled and the MCU runs physical Bank0 / APP A.
2. Program only the OTA-enabled NVR and perform POR.
3. Hardware compares the A/B indicators, selects the higher B version, remaps physical Bank1 to the low logical VMA, and runs APP B.

## Board wiring used by the demo

The defaults are taken from
`../02_MD/FC7300F4MDDT1C_BGA320_Demo_Board_SCH_V1.1.pdf` in the development
workspace. The onboard USB
Type-C port uses a CH340C USB-UART. TX and RX below are named from the MCU
point of view:

```text
FCUART1 TX: PTA18 / PD2 -> CH340C RX path
FCUART1 RX: PTA19 / PD3 <- CH340C TX path
Baud:       115200, 8-N-1
APP A LED:  LED1 / PTA26 / PL5, active-high N-MOSFET gate, slow toggle
APP B LED:  LED2 / PTD31 / PE13, active-high N-MOSFET gate, fast toggle
Unused LED: LED3 / PTA14 / PE10, initialized low (off)
```

The three discrete LEDs are powered from `VDD_HV_A_misc` and switched by
low-side N-MOSFETs; GPIO high turns the corresponding LED on. Change
`Include/ota_board_config.h` only if the actual target is a different board
revision or wiring variant.

## Generated artifacts

```text
Artifacts/FC7300_AB_PFlash_Demo.hex
    Sparse PFlash-only Intel HEX.
    Bank0 contains APP A, hardware version 0x00000001.
    Bank1 contains APP B, hardware version 0x00000002.
    It does not contain NVR records.

Artifacts/FC7300_NVR_Default.hex
    Complete default NVR. OTA disabled.

Artifacts/FC7300_NVR_OTA_Enabled.hex
    Complete OTA-enabled NVR.

Artifacts/FC7300_AB_PFlash_Demo.report.json
    Addresses, vectors, versions, payload/header CRCs and SHA-256.
```

Regenerate everything from source:

```powershell
python Tools\build_ab_demo.py
```

On a clean checkout, import the Eclipse project into FCIDE and build both
`Debug_FLASH_A` and `Debug_FLASH_B` once so their managed makefiles are
generated. The configurations share all source files, but select different
linker scripts and build macros:

```text
Debug_FLASH_A: Startup/FC7300_flash_A.ld, OTA_BUILD_VARIANT=0
Debug_FLASH_B: Startup/FC7300_flash_B.ld, OTA_BUILD_VARIANT=1
```

APP A uses VMA=LMA in physical Bank0. APP B uses a low execution VMA and a
physical Bank1 LMA. Therefore FCIDE/J-Link downloads the B ELF/HEX to
`0x01200000`, while symbols and the reset handler remain in `0x010xxxxx` for
correct execution after hardware bank swap. The B startup `.data` source is
also translated back to the low logical mapping at runtime.

The build script checks these ELF VMA/LMA rules, consumes the independent A/B
ELF files, packs valid headers, and generates individual Bank HEX files plus
one combined PFlash HEX. It never rewrites a source header during the build.

## FCIDE download behavior

- `Debug_FLASH_A` can be downloaded and run directly with default NVR.
- `Debug_FLASH_B` now downloads only to physical Bank1; it no longer overwrites APP A.
- Do not expect B to run immediately while OTA is disabled. Its entry symbol is
  intentionally the shared low VMA, which still maps to APP A before bank swap.
- To run B, first program both banks, program the OTA-enabled NVR, then perform
  POR. For source debugging, attach Ozone/IDE after POR or start a B debug session
  only when the hardware mapping is already active.

## Test procedure

1. Back up the device NVR.
2. Restore/program the complete default NVR if the board is not already using it.
3. Erase physical PFlash `0x01000000-0x013FFFFF`.
4. Program `Artifacts/FC7300_AB_PFlash_Demo.hex`.
5. Perform POR.

Expected UART and LED:

```text
FC7300 OTA APP A version=0x00000001 active=BANK0/A OTA_EN=0 OTA_ACTIVE=0
ACTIVE_PHYSICAL=0x01000000 ACTIVE_ACCESS=0x01000000 EXEC_VMA=0x01000000 TARGET_PHYSICAL=0x01200000 TARGET_ACCESS=0x01200000
SLOT_A version=0x00000001 hw_valid=1 image_valid=1 SLOT_B version=0x00000002 hw_valid=1 image_valid=1
LED1 / PTA26 toggles slowly.
```

6. Program only `Artifacts/FC7300_NVR_OTA_Enabled.hex` as NVR. Do not mass erase and do not erase PFlash.
7. Perform POR again so the NVR is reloaded and hardware compares both indicators.

Expected UART and LED:

```text
FC7300 OTA APP B version=0x00000002 active=BANK1/B OTA_EN=1 OTA_ACTIVE=1
ACTIVE_PHYSICAL=0x01200000 ACTIVE_ACCESS=0x01000000 EXEC_VMA=0x01000000 TARGET_PHYSICAL=0x01000000 TARGET_ACCESS=0x01200000
SLOT_A version=0x00000001 hw_valid=1 image_valid=1 SLOT_B version=0x00000002 hw_valid=1 image_valid=1
LED2 / PTD31 toggles quickly.
```

The PC still executes in `0x010xxxxx`. That is expected: physical Bank1 has
been remapped to the common low logical VMA.

## Debugger checks

```text
FMC_OTA_CTRL    0x4001E500: OTA_EN[4:0] = 0x0A, OTA_ACTIVE[5] = 1
FMC_OTA_VER_LOC 0x4001E50C: low 20 bits = 0xFF000
FMC_OTA_ACT_VER 0x4001E518: full 32 bits = 0x00000002
APP B indicator 0x013FF000 before swap / 0x011FF000 through active mapping
```

To demonstrate the reverse transition, program the default NVR again without
erasing PFlash and perform POR. OTA becomes disabled and APP A runs again.

## Programming precautions

- The combined PFlash HEX is sparse. Erase both PFlash banks before its first programming.
- Program NVR with an NVR-only operation. A chip-wide erase would destroy the A/B images and invalidate the test.
- Use POR for both observations; a debugger restart or software reset may not reproduce the NVR load sequence.
- The current UART integration includes package reception and binary command parsing. After a valid HELLO, text heartbeat/log output pauses so it cannot corrupt COBS-framed OTA traffic.
