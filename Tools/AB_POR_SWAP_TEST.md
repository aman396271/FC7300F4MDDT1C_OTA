# FC7300 F4MDD A/B POR swap test

This test proves the hardware behavior requested for the demo:

1. With the default NVR, hardware OTA is disabled and the MCU runs physical Bank0 / APP A.
2. Program only the OTA-enabled NVR and perform POR.
3. Hardware compares the A/B indicators, selects the higher B version, remaps physical Bank1 to the low logical VMA, and runs APP B.

## Board wiring used by the demo

The defaults match the FC7300F4MDD EVB examples in this workspace:

```text
FCUART1 TX: PTA18
FCUART1 RX: PTA19
Baud:       115200, 8-N-1
APP A LED:  PTA26, slow toggle
APP B LED:  PTD31, fast toggle
```

Change `Include/ota_board_config.h` if the target board uses other pins.

## Generated artifacts

```text
Tools/fc7300_ab_pflash_demo.hex
    Sparse PFlash-only Intel HEX.
    Bank0 contains APP A, version 0x00010000.
    Bank1 contains APP B, version 0x00010100.
    It does not contain NVR records.

Tools/reference/FC73000F4MDDT1C_Default.hex
    Complete default NVR. OTA disabled.

Tools/fc7300_nvr_f4mdd_ota.hex
    Complete OTA-enabled NVR.

Tools/fc7300_ab_pflash_demo.report.json
    Addresses, vectors, versions, payload/header CRCs and SHA-256.
```

Regenerate everything from source:

```powershell
python Tools\build_ab_demo.py
```

On a clean checkout, import the Eclipse project into FCIDE and build
`Debug_FLASH` once first so its managed makefiles are generated.

The build script temporarily selects A and B, builds both with the same
`0x01000000` VMA, packs valid headers, places B at physical `0x01200000`, merges
one PFlash HEX, then restores the checked-in A build selection.

## Test procedure

1. Back up the device NVR.
2. Restore/program the complete default NVR if the board is not already using it.
3. Erase physical PFlash `0x01000000-0x013FFFFF`.
4. Program `Tools/fc7300_ab_pflash_demo.hex`.
5. Perform POR.

Expected UART and LED:

```text
FC7300 OTA APP A version=0x00010000 active=BANK0/A OTA_EN=0 OTA_ACTIVE=0
PTA26 toggles slowly.
```

6. Program only `Tools/fc7300_nvr_f4mdd_ota.hex` as NVR. Do not mass erase and do not erase PFlash.
7. Perform POR again so the NVR is reloaded and hardware compares both indicators.

Expected UART and LED:

```text
FC7300 OTA APP B version=0x00010100 active=BANK1/B OTA_EN=1 OTA_ACTIVE=1
PTD31 toggles quickly.
```

The PC still executes in `0x010xxxxx`. That is expected: physical Bank1 has
been remapped to the common low logical VMA.

## Debugger checks

```text
FMC_OTA_CTRL    0x4001E500: OTA_EN[4:0] = 0x0A, OTA_ACTIVE[5] = 1
FMC_OTA_VER_LOC 0x4001E50C: low 20 bits = 0xFF008
APP B indicator 0x013FF008 before swap / 0x011FF008 through active mapping
```

To demonstrate the reverse transition, program the default NVR again without
erasing PFlash and perform POR. OTA becomes disabled and APP A runs again.

## Programming precautions

- The combined PFlash HEX is sparse. Erase both PFlash banks before its first programming.
- Program NVR with an NVR-only operation. A chip-wide erase would destroy the A/B images and invalidate the test.
- Use POR for both observations; a debugger restart or software reset may not reproduce the NVR load sequence.
- The current UART integration transmits boot status only. UART package reception/command parsing is a separate App OTA transport task.
