# FC7300 UART OTA protocol v1

## Transport framing

The wire format is COBS encoded binary followed by a `0x00` delimiter. The
decoded frame is little-endian and ends with an IEEE CRC-32 (polynomial
`0xEDB88320`, initial/final XOR `0xFFFFFFFF`). CRC covers the fixed header and
payload, but not the CRC field or COBS delimiter.

| Offset | Size | Field |
| ---: | ---: | --- |
| 0 | 2 | Magic `0x544F` |
| 2 | 1 | Protocol version, currently `1` |
| 3 | 1 | Command |
| 4 | 1 | Flags: bit0 response, bit1 error |
| 5 | 1 | Reserved, must be zero |
| 6 | 4 | Sequence |
| 10 | 4 | Payload/image offset |
| 14 | 2 | Payload length, maximum 512 |
| 16 | 2 | Status/error code |
| 18 | N | Payload |
| 18+N | 4 | CRC-32 |

Text boot logs may precede the first binary frame. The host flushes old input
and COBS framing resynchronizes on `0x00`. Once a valid `HELLO` is received,
the MCU suppresses heartbeat and text logs until the next POR.

## Commands

| Value | Command | Request payload | Successful response |
| ---: | --- | --- | --- |
| `0x01` | HELLO | Empty | min protocol `u16`, max protocol `u16`, max payload `u32` |
| `0x02` | GET_INFO | Empty | Fixed device information record below |
| `0x10` | START_UPDATE | Complete 128-byte package header | target slot `u8`, padding, physical target base `u32`, image size `u32` |
| `0x11` | DATA | Payload bytes | ACK with offset set to next required image offset |
| `0x12` | FINISH | Empty | `WAIT_POR`, target slot and committed version |
| `0x13` | ABORT | Empty | OK |
| `0x14` | GET_STATUS | Empty | State, target, received size, total size, expected sequence, last error |

`START_UPDATE` validates `OTA_EN`, header CRC, header version, image size and
monotonic firmware version before erasing the inactive Bank. NVR is never
written by the OTA service.

## GET_INFO payload

The response deliberately distinguishes fixed physical Flash placement from
the CPU-visible remapped address:

| Field | Type | Meaning |
| --- | --- | --- |
| active_slot / inactive_slot | `u8`, `u8` | 0=A/Bank0, 1=B/Bank1 |
| ota_enabled / ota_locked | `u8`, `u8` | FMC state |
| active_physical_base | `u32` | `0x01000000` for A or `0x01200000` for B |
| inactive_physical_base | `u32` | Fixed physical target address |
| active_access_base | `u32` | CPU access address after hardware remap |
| inactive_access_base | `u32` | CPU/Flash-driver access window |
| execution_vma | `u32` | Always `0x01000000` |
| low_version / high_version | `u32`, `u32` | A/B header versions |
| validity_flags | `u32` | low/high hardware and software-valid bits |
| fmc_ota_ctrl | `u32` | Raw FMC control register |
| fmc_active_version | `u32` | Full active hardware version |
| max_image_size | `u32` | Maximum package payload |

Example while physical B is active:

```text
active_slot          = B
active_physical_base = 0x01200000
active_access_base   = 0x01000000
execution_vma        = 0x01000000
inactive_physical    = 0x01000000
inactive_access      = 0x01200000
```

## Sequence, duplicate and retry rules

`HELLO` establishes the next expected sequence. Every subsequent request uses
exactly that value and increments modulo 32 bits. A missing or future sequence
returns `BAD_SEQUENCE` with the expected sequence in the response offset.

The MCU caches the last complete request and encoded response. If an ACK is
lost and the host repeats the identical request, the cached response is sent
without executing the command again. Therefore a duplicate DATA frame never
causes a second Flash write. DATA offset must equal the next unreceived image
offset; otherwise `BAD_OFFSET` returns the required offset.

The host uses stop-and-wait DATA, a one-second normal response timeout, three
retries, a 180-second START erase timeout for the synchronous 2 MB Bank erase,
and a longer FINISH verification timeout. GUI/CLI display START as an
indeterminate erase phase until the MCU returns its response; payload percentage
begins only after the first DATA ACK.
An active update session is aborted after five seconds without a valid frame.

## Commit and power-fail boundary

FINISH performs the following order:

1. Flush the 8-byte aligned staging buffer.
2. Compare the streaming payload CRC.
3. Read the inactive Bank payload back and verify CRC again.
4. Write the DFlash pending record.
5. Erase the inactive header sector and program header bytes `0x10..0x7F`.
6. Read the header body back.
7. Program the final aligned 16-byte `version/~version/valid-code` record.

Step 7 is the hardware validity commit. Before it, power loss leaves the
inactive Bank without a valid indicator and the old Bank remains selected.
After success the response is `WAIT_POR`; firmware never claims that a software
reset has completed hardware Bank selection.

## Status values

Important values are `OK=0`, `WAIT_POR=1`, `BAD_CRC=0x101`,
`BAD_LENGTH=0x102`, `BAD_SEQUENCE=0x105`, `BAD_OFFSET=0x106`,
`OTA_NOT_ENABLED=0x109`, `ACTIVE_BANK_PROTECTED=0x10A`,
`INVALID_PACKAGE=0x10B`, `VERSION_REJECTED=0x10C`,
`FLASH_ERROR=0x10D`, `IMAGE_CRC_ERROR=0x10E`, `TIMEOUT=0x10F` and
`CANCELLED=0x110`.

Malformed COBS, illegal length and CRC-corrupted frames are discarded because
their command/sequence cannot be trusted. The host timeout retry then sends the
same request again.

CAN/ISO-TP/UDS are intentionally outside protocol v1 implementation. The host
`Transport` abstraction and shared `UpgradeController` are the extension
points for later transports.
