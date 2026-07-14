# FC7300F4MDDT1C Hardware OTA Demo

## Existing Code Confirmed

| Path | Symbol | Role | Reuse |
| --- | --- | --- | --- |
| `Template/Device/FC/Modules/FC7300F4MDDxxxxxT1C/module_fmc_regs.h` | `FMC0_BASE=0x4001e000`, `FMC->OTA_CTRL[0]` offset `0x500`, `OTA_VER_LOC[0]` offset `0x50c`, `OTA_ACT_VER[0]` offset `0x518` | Runtime FMC OTA status/control registers | Yes |
| same | `FMC_OTA_CTRL_OTA_LOCK_MASK=0x40`, `OTA_ACTIVE_MASK=0x20`, `OTA_EN_MASK=0x1f` | Lock, active-slot, enable bits | Yes |
| same | `FMC_OTA_VER_LOC_MASK=0x000fffff` | Hardware version logical offset in PFlash | Yes |
| same | `OTA_START_ADDR`, `OTA_START_ADDR_HIGH`, `OTA_END_ADDR`, `OTA_END_ADDR_HIGH` | Runtime mirror of NVR OTAC low/high ranges | Read-only diagnostics in demo |
| `Template/Device/FC/Features/FC7300/FC7300F4MDDxxxxxT1C/modules/flash_feature.h` | `PFLASH_ADDR_START=0x01000000`, `PFLASH_ADDR_END=0x013fffff`, `PFLASH_ERASE_SECTOR_SIZE=0x1000`, `PFLASH_PROGRAM_PAGE_MIN_SIZE=0x08` | PFlash range/alignment | Yes |
| same | `DFLASH_ADDR_START=0x04000000`, `DFLASH_ADDR_END=0x0403ffff`, `DFLASH_ERASE_SECTOR_SIZE=0x800`, `DFLASH_PROGRAM_PAGE_MIN_SIZE=0x08` | DFlash state sector | Yes |
| `Template/Driver/Include/module_driver_flash.h` | `FLASHDRIVER_Init`, `FLASHDRIVER_SyncErase`, `FLASHDRIVER_SyncWrite`, `FLASHDRIVER_Lock` | Flash erase/program API | Yes |
| `Template/Driver/Source/module_driver_flash.c` | `FLASHDRIVER_EraseCheck`, `FLASHDRIVER_WriteCheck`, `NVRDRIVER_*` | SDK range/alignment checks | Yes |
| `Template/HwA/Include/HwA_sec.h` | `SEC_HWA_EnReadB0NVR`, `SEC_HWA_EnWriteB0NVR`, `SEC_HWA_EnEraseB0NVR` | NVR permission helpers | Not used by runtime demo |
| `Startup/FC7300_flash.ld` | `PFLASH_0`, `.isr_vector`, `.text` | Linker layout | Modified |
| `Startup/startup_FC7300.S` | `cpsid i`, `cpsie i` | Interrupt mask pattern | SDK/CMSIS reused |

No FC7300 runtime NVR OTAC programming API was found in this project. The offline tool in `Tools/fc7300_nvr_config_tool.py` generates a complete NVR image from the reviewed default HEX; program it with the official device programming flow before using hardware swap.

## Demo Layout

Low bank / Bank0: `0x01000000 .. 0x011fffff`

High bank / Bank1: `0x01200000 .. 0x013fffff`

Bank size: `0x00200000`

Header sector offset inside each 2 MB bank: `0x001ff000`

Effective OTA indicator offset inside each 2 MB bank: `0x001ff008`

NVR raw version offset for OTAC0[51:32]: `0x000ff008`

OTAC_HIGH0 version select: high 1 MB (`OTAC_HIGH0[7:0] != 0xAA`)

Bank0 version address: `0x011ff008`

Bank1 version address: `0x013ff008`

DFlash state sector: `0x0403f800 .. 0x0403ffff`

The source constants describe the physical Bank0/Bank1 images.  Runtime access is remap-aware: if Bank1 is active, Bank1 is read through the low logical boot window and the inactive Bank0 is accessed through the high logical window.

The DFlash state records `pending/confirmed/boot_attempts`; it never replaces the PFlash OTA indicator used by hardware OTA selection.

## Image Format

Transport package:

1. `ota_image_header_t` (`0x80` bytes)
2. Payload bytes, starting with the vector table linked at `0x01000000`

Flash slot:

1. Payload at slot base
2. Header at `slot_base + 0x001ff000`
3. RM Table 55 OTA indicator at `slot_base + 0x001ff008`

The first 16 bytes at `slot_base + 0x001ff008` are hardware-visible:

1. `version`
2. `~version`
3. F4MDD valid code `0xFC60FACE88886666`

The final header write is the validity boundary. If power is lost before the header sector is programmed, the inactive slot has no valid header/version and the old active slot remains bootable.

## Link And Generate Images

Both A and B apps use the same VMA: `0x01000000`. Hardware remap makes the selected physical slot appear at the same logical boot address.

For the default-NVR-to-OTA-NVR POR demonstration, generate the observable A/B
applications and one combined PFlash HEX:

```sh
python Tools/build_ab_demo.py
```

This produces `Artifacts/FC7300_AB_PFlash_Demo.hex`: APP A is placed in physical
Bank0 with version `0x00000001`; APP B is placed in physical Bank1 with version
`0x00000002`. See `Tools/AB_POR_SWAP_TEST.md` for the exact programming order.

Build the project normally in `Debug_FLASH`, then convert ELF to binary and patch:

```sh
arm-none-eabi-objcopy --gap-fill 0xFF -O binary OTA_7300F4MDDT1C_260707.elf app.bin
python Tools/pack_hw_ota_image.py app.bin --version 0x00000001 --out-prefix out/app_v1
python Tools/pack_hw_ota_image.py app.bin --version 0x00000002 --out-prefix out/app_v2
```

Program `out/app_v1_low.bin` at `0x01000000` for Bank0 version 1.

Program `out/app_v2_high.bin` at `0x01200000` for Bank1 version 2, or send `out/app_v2.pkg` to `ota_demo_install_package()`.

## Required NVR OTA Configuration

Confirm in RM/tooling and program NVR so that:

`OTA_EN` is enabled.

Bank0/1 swap is 2 MB, but `OTAC0[51:32]` is a 20-bit offset inside a selected 1 MB half.

Configure the lower 1 MB start/end as `0x01000000 .. 0x010fffff`.

Configure the upper 1 MB start/end as `0x01100000 .. 0x011fffff`.

`OTAC0[51:32] = 0x000ff008`.

`OTAC_HIGH0[7:0]` selects the high 1 MB, so the effective version offset inside each 2 MB bank is `0x001ff008`.

The same effective version offset is used in Bank0 and Bank1.

Do not put the hardware OTA indicator in DFlash.

Use `Tools/fc7300_nvr_config_tool.py` for a complete 2 KB NVR HEX based on the known-good default image; see `Tools/NVR_CONFIG_TOOL.md`. The older `Tools/nvr_ota_config_tool.py` remains available for OTA-only 16-byte patches and PFlash indicator records.

## Commands

`info`: capture active slot, versions, FMC OTA registers.

`confirm`: mark current boot confirmed.

`pending`: mark current boot pending.

`rollback`: bump non-active valid slot version to active+1.

`invalidate_active`: engineering-only; requires `OTA_ALLOW_ACTIVE_INVALIDATE=1`.

`force_low` / `force_high`: write `FMC->OTA_CTRL[OTA_ACTIVE]` only if OTA is enabled, target is valid, and OTA lock is clear.

The EVB demo now transmits boot identity and FMC OTA status through FCUART1
(PTA18/PTA19, 115200) and uses PTA26/PTD31 for A/B LED behavior. UART receive
and command parsing are not wired yet; call `ota_demo_handle_command()` from a
future transport shell or invoke the module APIs directly in a test function.

## Expected Logs

Normal upgrade:

```text
boot: active=LOW version=0x00000001
update: erase HIGH
update: write payload
update: verify CRC OK
update: write HIGH header/version last
reset
boot: active=HIGH version=0x00000002 pending attempt 1
app: self-test OK, confirm
```

Power loss during upgrade:

```text
boot: active=LOW version=0x00000001
update: write half payload to HIGH
reset
boot: active=LOW version=0x00000001
HIGH: invalid header/version
```

Failed new boot rollback:

```text
boot: active=HIGH version=0x00000002 pending attempt 1
reset without confirm
boot: pending attempt exceeded, bump LOW version to HIGH+1
reset
boot: active=LOW
```

Manual rollback:

```text
boot: active=HIGH
cmd rollback
LOW header version rewritten to active+1
reset
boot: active=LOW
```

## Risks And TODO

Confirm the exact NVR OTAC0/OTAC_HIGH0 bit layout in the FC7300F4MDDT1C RM/tool before production use.

Confirm whether runtime reads of `FMC->OTA_START/END_ADDR(_HIGH)` are full logical addresses or encoded register fields.

Place flash erase/program wrappers in RAM if the final memory map violates FC7300 RWW requirements.

Add UART/CAN/UDS receive and command parsing for streamed App OTA packages.

Add authentication/signature checks before accepting update packages in a real bootloader.

Avoid `force_low/force_high` in production when OTA lock or NVR policy is enabled.
