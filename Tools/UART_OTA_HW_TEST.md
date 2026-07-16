# FC7300F4MDDT1C UART OTA 硬件验收

本文只验收第一阶段 UART OTA。CAN、ISO-TP 和 UDS 本阶段不执行。

## 1. 安全边界

- 上位机只发送 `pack_hw_ota_image.py` 生成的 `.pkg`，不发送 Intel HEX。
- 上位机不写 NVR。若 `GET_INFO` 返回 `OTA_EN=0`，必须停止并提示离线配置 NVR。
- A 固定物理地址为 `0x01000000`，B 固定物理地址为 `0x01200000`；两者执行 VMA 均为 `0x01000000`。
- 所有擦除和编程必须指向 `GET_INFO` 返回的 inactive Bank。测试过程中保存串口日志和目标地址。
- FINISH 成功只表示镜像和 indicator 已提交，状态必须为 `WAIT_POR`。Bank Swap 必须通过真实 POR 验证。
- 中断或失败测试后，不要用全片擦除恢复；先 POR 验证旧 active Bank 仍可启动。

## 2. 环境准备

目标板使用 BGA320 Demo Board V1.1 原理图中的板载 USB Type-C/CH340C 通路：MCU `FCUART1_TX=PTA18/PD2`，`FCUART1_RX=PTA19/PD3`，115200 8-N-1。TX/RX 名称均以 MCU 为参照；使用板载 USB 口时无需再把两根信号线手工交叉连接。三颗独立 LED 均为 N-MOSFET 低边驱动，GPIO 高电平点亮。

在开发工程根目录安装依赖并执行回归测试：

```powershell
python -m pip install -r Tools\ota_host\requirements.txt
python -m pytest Tools\ota_host\tests Tools\test_fc7300_nvr_config_tool.py -q
python Tools\build_ab_demo.py
```

默认 profile 生成 A v1 和 B v2。生成 B 运行后回写 A 所需的 A v3 包：

```powershell
python Tools\build_ota_package.py A --profile return_a_v3
```

该命令输出 `out\ota_package\a\app_a.pkg`，版本必须为 `0x00000003`；命令结束后自动恢复默认生成头，不会改变默认 A v1/B v2 profile。

初始烧录只使用离线编程器：

1. 备份目标板 NVR。
2. 擦除两个 PFlash Bank。
3. 烧录 `Artifacts\FC7300_APP_A_Bank0.hex`，使 A v1 成为初始应用。
4. 按 `Tools\AB_POR_SWAP_TEST.md` 的限制烧录 `Artifacts\FC7300_NVR_OTA_Enabled.hex`，禁止会连带擦除 PFlash 的全片操作。
5. 执行真实 POR，确认 A v1 运行且 `OTA_ACTIVE=0`。

## 3. 地址与设备信息检查

```powershell
python -m Tools.ota_host.cli --list-ports
python -m Tools.ota_host.cli --port COM7 info
```

初始 A v1 的关键结果应为：

```text
active_slot=A
active_physical=0x01000000
active_access=0x01000000
execution_vma=0x01000000
target_slot=B
target_physical=0x01200000
ota_enabled=1
active_version=0x00000001
```

设备启动日志还应同时打印 `ACTIVE_PHYSICAL`、`ACTIVE_ACCESS`、`EXEC_VMA`、`TARGET_PHYSICAL` 和 `TARGET_ACCESS`。不能仅凭 PC/VMA 判断物理 Bank。

## 4. A v1 下载 B v2

```powershell
python -m Tools.ota_host.cli --port COM7 upgrade out\ab_demo\app_b.pkg
```

验收点：

1. HELLO 后文本 heartbeat 停止，不与二进制帧混发。
2. START 前上位机显示 active=A、target=B、target physical=`0x01200000`、package v2。
3. 每个 DATA 都有 ACK；进度、速率和耗时持续更新。
4. FINISH 返回 `WAIT_POR`，不能显示已完成软件复位或已切换 Bank。
5. 在 POR 前再次查询时 active 仍为 A；inactive B 的 version/validity 已为 v2/valid。
6. 执行真实 POR 后，B v2 运行：`active_physical=0x01200000`、`active_access=0x01000000`、`execution_vma=0x01000000`、`OTA_ACTIVE=1`。

## 5. B v2 下载 A v3

确认第 2 节生成的 A v3 package 仍存在，然后执行：

```powershell
python -m Tools.ota_host.cli --port COM7 upgrade out\ota_package\a\app_a.pkg
```

验收点：

1. START 前 active=B、target=A、target physical=`0x01000000`、package v3。
2. 升级期间对 A 的 CPU 访问地址应为 remap 后的 `0x01200000`，但 GUI/CLI 始终把固定物理目标显示为 `0x01000000`。
3. FINISH 返回 `WAIT_POR`。
4. 真实 POR 后 A v3 运行：`active_physical=0x01000000`、`active_access=0x01000000`、`execution_vma=0x01000000`、`OTA_ACTIVE=0`。

## 6. 故障与保护用例

每项用例都从一个已确认可启动的 active Bank 开始，并记录 START 前后的 `GET_INFO`。

### 6.1 OTA_EN 未启用

使用离线编程器恢复 Default NVR 并 POR。CLI/GUI 必须在 START 前拒绝升级，明确提示离线启用 NVR；PFlash 不应被擦除或写入。恢复 OTA Enabled NVR 后再继续其他测试。

### 6.2 低版本拒绝

当 B v2 active 时尝试发送 A v1/B v2 package，或当 A v3 active 时发送 v1/v2 package。上位机预检查应拒绝；绕过上位机预检查时，MCU START 也必须返回 `VERSION_REJECTED`。inactive Bank 不得开始擦除。

### 6.3 传输中断

开始一次升级，在 10%–90% 任意进度拔掉 UART 或取消。等待设备 5 秒会话超时，随后真实 POR：

- 旧 active Bank 必须正常启动；
- 传输目标 Bank 的 indicator 必须无效；
- 恢复串口后可以从 START 重新完整升级。

### 6.4 下载或写入期间掉电

分别在擦除、DATA 下载以及 FINISH 校验开始前断电。重新上电后只能启动原 active Bank。重复测试时覆盖几个不同进度点。

### 6.5 帧 CRC 错误

使用协议测试工具发送 CRC32 被修改的 HELLO/DATA 帧。设备应丢弃该帧，主机超时后重发相同 sequence；重复包不得造成重复写入或 offset 增加两次。若在 START 后立即 ABORT/POR，目标 indicator 必须保持无效。

### 6.6 FINISH 镜像 CRC 错误

在专用故障注入脚本或串口代理中，保持 128-byte package header 不变，只翻转一个 DATA payload 字节并重新计算该通讯帧 CRC。这样 framing CRC 正确，但最终 payload CRC 错误。FINISH 必须返回 `IMAGE_CRC_ERROR`；目标 Bank 的 16-byte indicator 不得写入，POR 后仍运行旧版本。

### 6.7 sequence、offset 和重复 ACK

- 跳过一个 sequence：返回 `BAD_SEQUENCE` 和期望 sequence。
- 使用错误 offset：返回 `BAD_OFFSET` 和已接收字节数。
- 丢弃一个 DATA ACK，使主机发送完全相同的帧：设备重放缓存 ACK，不重复写 Flash。
- 发送超过 512 字节 payload 或声明长度不符的帧：拒绝或丢弃，不改变升级 offset。

### 6.8 FINISH 提交边界

在 Flash 回读 CRC 完成前、header body 写入期间以及最终 16-byte indicator 写入前分别掉电。除非完整 indicator 已成功写入，否则硬件不得选择目标 Bank。indicator 写入成功后的正常结果仍是 `WAIT_POR`，需 POR 后才切换。

## 7. 不擦除 active Bank 的证据

对每次 START 保存以下四项：

| active physical | target physical | 允许擦除 | 禁止擦除 |
| --- | --- | --- | --- |
| `0x01000000` | `0x01200000` | Bank1/B | Bank0/A |
| `0x01200000` | `0x01000000` | Bank0/A | Bank1/B |

建议在调试器中给 `FLASHDRIVER_SyncErase` 设置断点，记录其 `u32Address/u32Length`。长度应为 `0x00200000`，地址必须等于 inactive Bank 的当前 CPU access base；同时用 `GET_INFO` 的 fixed physical 字段标记实际目标。任何一次 active Bank 擦除都判定验收失败。

## 8. 验收记录

| 用例 | 结果 | 日志/日期 |
| --- | --- | --- |
| A v1 → B v2，POR 后运行 B | 待执行 | |
| B v2 → A v3，POR 后运行 A | 待执行 | |
| OTA_EN=0 明确拒绝 | 待执行 | |
| 低版本拒绝且未擦除 | 待执行 | |
| UART 中断后旧版本启动 | 待执行 | |
| 下载/写入掉电后旧版本启动 | 待执行 | |
| framing CRC 错误可重试 | 待执行 | |
| FINISH CRC 错误不写 indicator | 待执行 | |
| 重复 DATA 不重复写入 | 待执行 | |
| 所有擦除均只命中 inactive Bank | 待执行 | |

只有上述板级项目全部留下证据后，才能把“UART 实流 OTA”从“待板级验收”改为“已完成”。
