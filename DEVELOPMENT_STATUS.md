# FC7300F4MDDT1C OTA 开发记录

更新时间：2026-07-16

## 1. 项目目标

本工程用于验证并逐步实现 FC7300F4MDDT1C 的 4 MB PFlash A/B Bank OTA：

1. Bank0 和 Bank1 各占 2 MB。
2. 两个镜像使用相同逻辑执行地址，由硬件 Bank Swap 完成映射。
3. NVR 开启硬件 OTA 后，POR 时比较两个 Bank 的 OTA Version。
4. 当前阶段已经验证 A -> B 的硬件选择和跳转。
5. 下一阶段接入 CAN/UDS 或 UART 通讯，实现完整在线升级。

## 2. 当前进度

| 状态 | 功能 | 说明 |
| --- | --- | --- |
| 已完成并上板验证 | 默认 NVR 启动 APP A | OTA 关闭时运行物理 Bank0 |
| 已完成并上板验证 | OTA NVR 启用 | `OTA_EN=0x0A`，NVR 可单独生成和烧录 |
| 已完成并上板验证 | 硬件 A/B Version 比较 | A=`0x00000001`，B=`0x00000002` |
| 已完成并上板验证 | POR 后跳转 APP B | `OTA_ACTIVE=1`，物理 Bank1 映射到低逻辑窗口 |
| 已完成 | A/B 独立 IDE 构建配置 | 两套对象、ELF、HEX 和调试符号，共用业务源码 |
| 已完成 | A/B 独立 linker script | A 使用 `FC7300_flash_A.ld`，B 使用 `FC7300_flash_B.ld` |
| 已完成 | A/B PFlash 打包工具 | 生成单 Bank HEX 和合并 PFlash HEX |
| 已完成 | NVR HEX 生成工具 | 支持 Default NVR 和 OTA Enabled NVR 单独输出 |
| 已完成 | UART 启动诊断 | 输出 APP、Version、Bank、FMC 和镜像有效性 |
| 已完成 | UART 心跳 | 非阻塞 1 ms tick 调度；进入二进制协议后暂停文本输出 |
| 已编译，待板级复验 | LED 指示 | 已按原理图改为 PTA26、PTD31、PTA14，高电平有效 |
| 已完成并通过构建/模拟测试 | 非活动 Bank 升级 Core | START 预校验、任意长度 staging、回读 CRC、16-byte indicator 最后提交 |
| 代码已有，未完整验证 | pending/confirm/rollback | 使用 DFlash 保存状态，仍需故障注入测试 |
| 已完成并通过构建/模拟测试 | UART 通讯升级 | FCUART1 RX ISR、2 KB ring、COBS/CRC32、sequence/offset、ACK/NACK、timeout |
| 已完成并通过自动化测试 | PC 升级工具 | package parser、SerialTransport、OtaClient、UpgradeController、CLI、PySide6 GUI、模拟设备 |
| 待板级验收 | A/B 串口实流升级 | 软件闭环、A/B 构建和 31 项测试已通过；START 擦除显示、180 秒等待和长擦除会话时间戳已修正，仍需按 `Tools/UART_OTA_HW_TEST.md` 执行 POR/掉电用例 |

## 3. 已确认的硬件与 Demo 板规则

### 3.1 BGA320 Demo 板接口

板级定义已按开发工作区 `../02_MD/FC7300F4MDDT1C_BGA320_Demo_Board_SCH_V1.1.pdf` 核对。文件名和变更记录标为 V1.1；各页标题栏仍保留 `FC600_BGA320_Demo_Board`、`Rev 0.1`，这是原理图自身的命名差异，本文按目标器件称为 FC7300F4MDDT1C BGA320 Demo 板。

| 功能 | MCU 管脚 | 原理图网络/电路 | 软件约定 |
| --- | --- | --- | --- |
| USB-UART1 TX | PTA18 / PD2 | `PTA18_PD2_UART1_to_USB_TX`，接 CH340C RX 通路 | `FCUART1_TX` |
| USB-UART1 RX | PTA19 / PD3 | `PTA19_PD3_UART1_to_USB_RX`，接 CH340C TX 通路 | `FCUART1_RX` |
| LED1 | PTA26 / PL5 | 1 kΩ 栅极串阻、31.6 kΩ 下拉、N-MOSFET 低边驱动 | MCU 高电平点亮 |
| LED2 | PTD31 / PE13 | 1 kΩ 栅极串阻、31.6 kΩ 下拉、N-MOSFET 低边驱动 | MCU 高电平点亮 |
| LED3 | PTA14 / PE10 | 1 kΩ 栅极串阻、31.6 kΩ 下拉、N-MOSFET 低边驱动 | MCU 高电平点亮 |

板载 USB Type-C 通过 CH340C 接 UART1。本文中的 TX/RX 始终以 MCU 为参照，不能按 CH340C 引脚名反向理解。LED 不是 MCU 直接灌拉 LED 电流；GPIO 拉高使 N-MOSFET 导通并点亮。上述连接已由原理图确认，串口收发和三颗 LED 的最终丝印/实物对应仍按硬件验收记录复核。

### 3.2 Flash/OTA 规则

```text
PFlash:              0x01000000 - 0x013FFFFF
Bank0 / APP A:       0x01000000 - 0x011FFFFF
Bank1 / APP B:       0x01200000 - 0x013FFFFF
单 Bank 大小:        0x00200000 (2 MB)
OTA header 偏移:     0x001FF000
Bank0 indicator:     0x011FF000
Bank1 indicator:     0x013FF000
NVR 原始 Version 偏移: 0x000FF000
DFlash OTA 状态区:   0x0403F800 - 0x0403FFFF
```

4M T1C OTA Version 需要满足：

1. `OTAC0[51:32]` 保存的是所选 1 MB 范围内的 20-bit 偏移。
2. A、B 的 OTA Version 必须使用相同的 Bank 内有效偏移。
3. OTA indicator 必须位于同一条 128-bit 对齐记录中。
4. 本工程通过 `OTAC_HIGH0` 选择 Bank 的高 1 MB，因此有效 Bank 内偏移为 `0x001FF000`。
5. `FMC_OTA_ACT_VER` 实际为完整 32-bit；旧版寄存器文档的 16-bit 描述已由 FAE 确认有误。
6. NVR 或 OTA indicator 修改后必须执行 POR，不能默认软件复位等价于 POR。

硬件选择 Bank1 后，CPU 仍从公共逻辑窗口 `0x01000000` 执行。因此 APP B 的 PC 显示为 `0x010xxxxx` 是正常现象，物理位置由 `OTA_ACTIVE` 判断。

## 4. A/B 构建机制

工程共用一套 `Sources`、`Include`、SDK 和 Startup 源文件，不复制业务代码。

| 配置 | 编译宏 | Linker script | ELF 物理装载位置 | 执行 VMA |
| --- | --- | --- | --- | --- |
| `Debug_FLASH_A` | `OTA_BUILD_VARIANT=0` | `Startup/FC7300_flash_A.ld` | Bank0 `0x01000000` | `0x01000000` |
| `Debug_FLASH_B` | `OTA_BUILD_VARIANT=1` | `Startup/FC7300_flash_B.ld` | Bank1 `0x01200000` | `0x01000000` |

APP B 的代码执行地址仍链接为低逻辑窗口，但 load address 位于物理 Bank1。这样 J-Link/FCIDE 可以把 B 下载到 `0x01200000`，硬件 Swap 后代码仍在正确的 `0x010xxxxx` 逻辑地址执行。

不要手动修改 `ota_build_selection.h` 切换 A/B。应在 IDE 中选择 `Debug_FLASH_A` 或 `Debug_FLASH_B`，因为编译宏和 linker script 必须同时切换。

## 5. 当前 Demo 的 A/B 标志

| 项目 | APP A | APP B |
| --- | --- | --- |
| 串口标签 | `APP A` | `APP B` |
| OTA Demo Version | `0x00000001` | `0x00000002` |
| LED | LED1 / PTA26 | LED2 / PTD31 |
| GPIO 有效电平 | 高电平点亮 | 高电平点亮 |
| 翻转间隔 | 1000 ms | 200 ms |

LED3 为 PTA14，目前仅初始化为低电平关闭。建议后续用作升级状态灯。

当前 LED 和 UART 差异只用于观察 Demo。产品业务代码应保持共用，不能依赖这些标志实现升级逻辑。

## 6. 代码结构

| 文件 | 职责 |
| --- | --- |
| `Sources/main.c` | 板级初始化、启动状态、非阻塞 LED/heartbeat 和模块调度 |
| `Include/ota_board_config.h` | UART 和 LED 板级引脚 |
| `Tools/ota_versions.json` | A/B 固件版本的唯一人工维护来源 |
| `Include/ota_version_autogen.h` | 从版本 manifest 自动生成，供运行时和 ELF header 使用 |
| `Include/ota_build_variant.h` | Demo A/B 标签、自动生成版本和 LED 周期 |
| `Include/ota_config.h` | Bank、header、indicator、DFlash 地址常量 |
| `Sources/ota_partition.c` | 读取 active/inactive Bank，处理硬件重映射 |
| `Sources/ota_flash.c` | PFlash/DFlash 擦除、写入、校验封装 |
| `Sources/ota_update.c` | START 预校验、staging、流式升级和提交状态机 |
| `Sources/ota_image_header.c` | 当前镜像的 OTA indicator/header |
| `Sources/ota_boot_confirm.c` | pending、confirmed、boot attempt 状态 |
| `Sources/ota_rollback.c` | 版本提升回滚和工程诊断切换 |
| `Sources/ota_uart.c` | FCUART1 RX中断、ring buffer和二进制发送 |
| `Sources/ota_protocol.c` | COBS framing、帧字段和CRC32解析/编码 |
| `Sources/ota_service.c` | 命令、sequence/offset、会话、ACK/NACK和ota_update适配 |
| `Sources/ota_time.c` | 非阻塞1 ms SysTick时基 |
| `Sources/ota_demo.c` | Demo/GET_INFO数据，包括物理、访问和VMA地址 |
| `Tools/build_ab_demo.py` | 构建 A/B、检查 ELF VMA/LMA、生成统一产物 |
| `Tools/pack_hw_ota_image.py` | 生成带有效 indicator 和 CRC 的升级包 |
| `Tools/build_ota_package.py` | 根据版本manifest构建单个A或B升级包 |
| `Tools/ota_host` | 共用Host协议、SerialTransport、CLI、GUI、模拟设备和测试 |
| `Tools/make_ab_pflash_hex.py` | 生成 A、B 和合并 PFlash HEX |
| `Tools/fc7300_nvr_config_tool.py` | 根据配置生成完整 NVR HEX |

保持代码简洁的约束：

1. `main.c` 只负责板级初始化、可观测输出和调度。
2. 通讯层不能直接访问 Flash，只调用 `ota_begin_update()`、`ota_write_chunk()`、`ota_finish_update()`。
3. 所有 Bank 映射由 `ota_partition.c` 处理，业务层不得散落物理地址判断。
4. A/B 共用业务源码，差异集中在构建配置和少量 Demo 宏中。
5. `Artifacts` 是生成目录，不能手工修改其中的 HEX。

## 7. 现有升级 Core

当前已经提供以下接口：

```c
ota_status_t ota_begin_update(const ota_image_header_t *header);
ota_status_t ota_write_chunk(const void *data, uint32_t len);
ota_status_t ota_finish_update(void);
ota_status_t ota_abort_update(void);
```

当前行为：

1. 自动选择非活动 Bank。
2. 在擦除前检查 `OTA_EN=0x0A`、完整 128-byte header、header CRC、版本和大小。
3. 校验通过后才擦除目标 Bank。
4. 128-byte staging 接受任意通讯长度，内部按 Flash 8-byte 最小页写入。
5. 传输过程中计算 CRC32，并在 FINISH 前回读目标 payload 再计算 CRC32。
6. 回读完整性成功后写 DFlash pending。
7. 先写 header 的 `0x10..0x7F` 并回读，再最后写 16-byte hardware indicator。
8. 最后的 `version/~version/valid-code` 记录是硬件有效性和掉电提交边界。

该逻辑已经通过 A/B 编译、C/Python协议向量和模拟通讯测试；真实PFlash串口流、传输中断、掉电和反复A/B升级仍须板级验收，不能作为量产完成状态。

## 8. 构建和产物

在项目根目录执行：

```powershell
python Tools\build_ab_demo.py
```

版本只在 `Tools/ota_versions.json` 中维护。构建脚本生成头文件，ELF和packer不再接受独立版本参数：

```powershell
python Tools\generate_ota_version.py
python Tools\build_ab_demo.py
python Tools\build_ota_package.py B
```

主要产物：

```text
Artifacts/FC7300_APP_A_Bank0.hex
Artifacts/FC7300_APP_B_Bank1.hex
Artifacts/FC7300_AB_PFlash_Demo.hex
Artifacts/FC7300_NVR_Default.hex
Artifacts/FC7300_NVR_OTA_Enabled.hex
Artifacts/FC7300_AB_PFlash_Demo.report.json
Artifacts/FC7300_NVR_OTA_Enabled.report.json
```

`pack_hw_ota_image.py` 从链接后的ELF header读取版本并完成CRC，不提供覆盖版本参数，因此运行时打印、ELF header、package和硬件indicator不能再由不同参数生成。

## 9. 已验证测试流程

1. 备份 MCU NVR。
2. 烧录 `FC7300_NVR_Default.hex` 并 POR。
3. 擦除两个物理 PFlash Bank。
4. 烧录 `FC7300_AB_PFlash_Demo.hex` 并 POR。
5. 预期 APP A、`OTA_ACTIVE=0`、LED1/PTA26 慢闪。
6. 只烧录 `FC7300_NVR_OTA_Enabled.hex`，不能执行会擦除 PFlash 的全片操作。
7. 再次 POR。
8. 预期 APP B、`OTA_ACTIVE=1`、LED2/PTD31 快闪。

典型 APP B 输出：

```text
FC7300 OTA APP B version=0x00000002 active=BANK1/B OTA_EN=1 OTA_ACTIVE=1
FMC_CTRL=0x0000002A VER_LOC=0x000FF000 ACT_VER=0x00000002
SLOT_A version=0x00000001 hw_valid=1 image_valid=1 SLOT_B version=0x00000002 hw_valid=1 image_valid=1
HEARTBEAT APP B count=0x00000001 PC=0x010xxxxx LED=LED2/PTD31
```

详细烧录注意事项见 `Tools/AB_POR_SWAP_TEST.md`；UART 全流程和故障注入验收见 `Tools/UART_OTA_HW_TEST.md`。

## 10. 调试注意事项

1. 默认 NVR 下，调试 APP B ELF 仍可能看到 APP A 执行，因为 Bank1 尚未被映射到低逻辑执行窗口。
2. 调试 APP B 应先完成 OTA NVR 烧录和 POR，再使用 Ozone/IDE attach。
3. PC 在 APP B 运行时仍显示 `0x010xxxxx`，这是硬件映射结果，不表示运行了物理 Bank0。
4. Ozone 可正常调试而 IDE Run 后难以暂停时，应检查 IDE reset strategy、向量捕获、watchdog 和 Bank 映射，不应只继续降低 JTAG 频率。
5. 当前 heartbeat 的 PC 是执行 `mov reg, pc` 时的逻辑地址采样，用于证明 CPU 持续运行，不用于单独判断物理 Bank。

## 11. 已知问题和风险

1. LED 管脚和高电平有效已由 BGA320 Demo Board V1.1 原理图确认；最新固件已编译，仍需在板上确认三路实际丝印对应关系和闪烁现象。
2. UART RX、协议和Host已经实现并编译/模拟测试，但尚未在当前板上完成真实 `.pkg` 全量传输。
3. 4MDDT1C按两个独立Bank处理：一个Bank执行、另一个Bank读写；当前不增加跨Bank RAM/ITCM搬移约束。
4. Flash API继续使用硬件remap后的CPU访问地址；GET_INFO和启动日志另行报告固定物理Bank地址，板测需重点核对B运行时写A的反向路径。
5. `OTA_DEMO_AUTO_CONFIRM` 当前默认开启，不适合验证失败启动和自动回滚。
6. 回滚通过重写另一个 Bank 的 Version 实现，必须做掉电和版本溢出测试。
7. 尚未验证 `NVIC_SystemReset()` 或 RGM reset 是否能触发与 POR 相同的 OTA 重选行为。
8. 当前只有 CRC32，能检测传输错误但不能防止恶意镜像。
9. NVR 属于敏感区域，烧录前必须检查工具的 erase 范围和生命周期/权限配置。

## 12. 下一阶段任务

### P0：通讯升级最小闭环

- [x] COBS + `0x00` + CRC32 UART framing。
- [x] 任意长度通讯数据的8-byte Flash写入staging。
- [x] ota_service接入 `ota_begin/write/finish/abort`。
- [x] Python CLI支持握手、package、分包、序号、offset、ACK、超时和重试。
- [x] CLI和PySide6 GUI共用UpgradeController。
- [x] Python模拟设备及拆包/粘包、CRC、重复、丢包、timeout、NACK、版本和完整升级测试。
- [ ] LED3 显示下载、写入、校验成功和错误状态。
- [ ] 完成 APP A -> APP B 的在线下载和 POR 切换。

### P1：工程化 CAN/UDS

- [ ] 复用工作区 `P01_UDS_CAN_2M` 的 CAN/ISO-TP 基础。
- [ ] 实现 UDS `0x10/0x27/0x34/0x36/0x37/0x31/0x11`。
- [ ] 增加硬件型号、版本、长度、CRC 和目标兼容性检查。
- [ ] 支持断包、重复包、错误序号和通讯恢复。
- [ ] 完成连续 A -> B -> A 多版本升级。

### P2：可靠性和安全

- [ ] 掉电点覆盖：擦除前、擦除中、下载中、校验前、indicator 写入前后。
- [ ] watchdog、自检、pending、confirm 和自动 rollback 联调。
- [ ] 确认并实现可触发硬件 OTA 重选的复位/掉电方案。
- [x] 统一版本号来源，生成 `ota_version_autogen.h`，packer从ELF继承版本。
- [ ] 增加 SHA-256 和签名验证，公钥固化在受保护区域。
- [ ] 增加 anti-rollback 和生产 NVR/生命周期策略审查。

## 13. 推荐完整 OTA 演示

1. APP A v1 运行，LED1 慢闪，UART heartbeat 正常。
2. PC 工具通过 CAN/UDS 或 UART 下载 v2 到非活动 Bank1。
3. LED3 在下载和 Flash 写入期间显示进度状态。
4. 校验成功后最后写入 v2 indicator，并提示需要 POR。
5. POR 后硬件选择 Bank1，APP B v2 运行，LED2 快闪。
6. 新软件自检成功后写 confirmed。
7. 再下载 v3 到非活动 Bank0，完成 B -> A 回切演示。

该闭环同时证明通讯传输、Flash 写入、断电安全、硬件 Version 选择、Bank Swap 和新版本确认，不只是证明两个预烧录 HEX 之间可以跳转。

## 14. IDE HEX OTA 打包器与当前板测故障

已增加 `Tools/ota_host/ide_hex.py`、`package_cli.py` 和 `package_gui.py`，以及可双击启动的
`Tools/run_ide_hex_ota_packer.bat`。该工具直接读取 FCIDE 本次编译生成的单 Bank Intel HEX，
从链接后的 `.ota_header` 模板继承版本号，自动检测 A/B 物理 Bank，补齐 `0xFF`，计算 payload/header
CRC，并同时生成 JTAG HEX、UART `.pkg` 和 JSON 报告。工具拒绝混合 A+B、NVR、错误 VMA、错误
version complement 和占用 header 保留区的输入。默认生成覆盖完整 2 MB Bank 的 HEX，以避免稀疏
HEX 未触发完整 Bank 擦除而残留旧字节。

2026-07-17 板测确认：打包 APP A 可正常打印 `image_valid=1`，但打印启动信息后 MCU 进入
HardFault，导致 LED 停止且 Host HELLO 超时。J-Link 只读现场为 `CFSR=0x00000400`
（BusFault IMPRECISERR）、`HFSR=0x40000000`，异常堆栈 PC `0x01003C34` 位于
`ota_flash_erase_absolute()` 返回后的 cache maintenance 路径。原始 IDE HEX 因
`image_valid=0` 使 `ota_mark_confirmed()` 提前返回，所以未暴露该问题。当前结论是正式 HEX 的
入口、程序区、FCUART1 向量和 OTA header 均正确；P0 阻塞项是自动 confirmed DFlash 写入及
Flash/cache 故障，不能通过退回无效 header 规避。
