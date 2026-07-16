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
| 已完成 | UART 心跳 | 每约 1 秒输出 APP、计数、逻辑 PC 和 LED 名称 |
| 已编译，待板级复验 | LED 指示 | 已按原理图改为 PTA26、PTD31、PTA14，高电平有效 |
| 代码已有，未通讯集成 | 非活动 Bank 升级 Core | 支持擦除、流式写入、CRC、header 最后提交 |
| 代码已有，未完整验证 | pending/confirm/rollback | 使用 DFlash 保存状态，仍需故障注入测试 |
| 未完成 | 通讯升级 | 尚无 UART RX、CAN/ISO-TP 或 UDS 下载链路 |
| 未完成 | PC 升级工具 | 尚无在线传输、进度、重试和自动激活工具 |

## 3. 已确认的硬件规则

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
| `Sources/main.c` | 时钟、UART、LED、启动状态输出、心跳 |
| `Include/ota_board_config.h` | UART 和 LED 板级引脚 |
| `Include/ota_build_variant.h` | Demo A/B 标签、版本和 LED 周期 |
| `Include/ota_config.h` | Bank、header、indicator、DFlash 地址常量 |
| `Sources/ota_partition.c` | 读取 active/inactive Bank，处理硬件重映射 |
| `Sources/ota_flash.c` | PFlash/DFlash 擦除、写入、校验封装 |
| `Sources/ota_update.c` | 流式升级状态机和完整性检查 |
| `Sources/ota_image_header.c` | 当前镜像的 OTA indicator/header |
| `Sources/ota_boot_confirm.c` | pending、confirmed、boot attempt 状态 |
| `Sources/ota_rollback.c` | 版本提升回滚和工程诊断切换 |
| `Sources/ota_demo.c` | Demo 信息和命令接口，尚未连接 UART RX |
| `Tools/build_ab_demo.py` | 构建 A/B、检查 ELF VMA/LMA、生成统一产物 |
| `Tools/pack_hw_ota_image.py` | 生成带有效 indicator 和 CRC 的升级包 |
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
ota_status_t ota_begin_update(void);
ota_status_t ota_write_chunk(const void *data, uint32_t len);
ota_status_t ota_finish_update(void);
ota_status_t ota_abort_update(void);
```

当前行为：

1. 自动选择非活动 Bank。
2. 擦除目标 Bank。
3. 先接收 128-byte `ota_image_header_t`，再接收 payload。
4. payload 写入必须满足 8-byte Flash page 对齐。
5. 传输过程中计算 CRC32。
6. 检查新版本必须高于当前有效版本。
7. payload 完整后才写 header/indicator，避免半包被硬件选中。
8. 写后再次校验 CRC，并在 DFlash 标记 pending。

这部分目前只是代码实现，尚未经过真实通讯流、传输中断、掉电和反复 A/B 升级验证，不能作为量产完成状态。

## 8. 构建和产物

在项目根目录执行：

```powershell
python Tools\build_ab_demo.py
```

显式指定打包版本：

```powershell
python Tools\build_ab_demo.py --a-version 0x00000001 --b-version 0x00000002
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

注意：`ota_build_variant.h` 中的 Demo Version 和 Python 打包参数目前是两个来源。修改版本时必须保持一致。后续应由一个版本配置自动生成头文件和打包参数。

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

详细烧录注意事项见 `Tools/AB_POR_SWAP_TEST.md`。

## 10. 调试注意事项

1. 默认 NVR 下，调试 APP B ELF 仍可能看到 APP A 执行，因为 Bank1 尚未被映射到低逻辑执行窗口。
2. 调试 APP B 应先完成 OTA NVR 烧录和 POR，再使用 Ozone/IDE attach。
3. PC 在 APP B 运行时仍显示 `0x010xxxxx`，这是硬件映射结果，不表示运行了物理 Bank0。
4. Ozone 可正常调试而 IDE Run 后难以暂停时，应检查 IDE reset strategy、向量捕获、watchdog 和 Bank 映射，不应只继续降低 JTAG 频率。
5. 当前 heartbeat 的 PC 是执行 `mov reg, pc` 时的逻辑地址采样，用于证明 CPU 持续运行，不用于单独判断物理 Bank。

## 11. 已知问题和风险

1. LED 引脚刚按原理图修正，最新固件已编译，仍需在板上确认三路电平和实际丝印对应关系。
2. UART 当前只有 TX 日志和 heartbeat，没有 RX 命令解析。
3. `ota_demo_handle_command()` 已存在，但没有接入真实 transport shell。
4. Flash 升级 Core 尚未确认 FC7300 RWW 限制；必要时擦写函数必须放入 RAM/ITCM。
5. `OTA_DEMO_AUTO_CONFIRM` 当前默认开启，不适合验证失败启动和自动回滚。
6. 回滚通过重写另一个 Bank 的 Version 实现，必须做掉电和版本溢出测试。
7. 尚未验证 `NVIC_SystemReset()` 或 RGM reset 是否能触发与 POR 相同的 OTA 重选行为。
8. 当前只有 CRC32，能检测传输错误但不能防止恶意镜像。
9. NVR 属于敏感区域，烧录前必须检查工具的 erase 范围和生命周期/权限配置。

## 12. 下一阶段任务

### P0：通讯升级最小闭环

- [ ] 选择 UART 分包协议作为首个 bring-up transport。
- [ ] 为任意长度通讯数据增加 8-byte Flash 写入 staging buffer。
- [ ] 接入 `ota_begin/write/finish/abort`。
- [ ] PC Python CLI 支持握手、Manifest、分包、序号、ACK、超时和重试。
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
- [ ] 统一版本号来源，生成 `ota_version_autogen.h`。
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
