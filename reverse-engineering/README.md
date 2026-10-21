# Manaka 资源解密与逆向入口

工作分支 `codex/rea-salt`。原始文件固定取自 `E:\SecretFlasherManakaREA`，输入指纹验证通过才继续分析。
分析阶段仅执行离线解析、REA/Ghidra 分析和本地解密；未启动游戏或修改原始游戏文件。

2026-10-21 已补齐 Windows 上层加载链：初始化资源 → KeyData → 标题场景 `models` 请求 → 路径/密码 → 解密流 → Unity 包加载 → 完成缓存与 25 个资源请求。本轮新增 54 份原生观察，见 [上层调用链报告](loading-chain.md)；完整证据坐标及绑定见 `salt/evidence/loading-chain.json`。

后续已补齐 EncrypterBundle 槽 2 → BridgeAssetBundle → Unity LoadAssetAsync / GetResult → 25 个回调 → 缓存及实例化/应用消费者，新增 56 份非空 REA 观察；另 3 份空 Listing 响应明确保留为不可用结果。见 [资源请求后续链报告](asset-followup.md) 与 `salt/evidence/asset-followup.json`。实际分配的包桥接类型为 BridgeAssetBundle，旧伪代码中的 EncryptLabelData 构造函数名是共享地址种子别名。

已继续连接标题新游戏/继续 → 选项与存档槽 → 淡出 → SpringboardLoadEmpty → MStage 目标关卡 → InGameManager/StageController 初始化 → EventMethodManager 每帧接口分派，新增 109 次非空 REA 函数查询。标题动画等待 25 个回调的门槛、10 个构建场景、8 条真实关卡配置及 5 个标题按钮绑定均有静态证据。见 [场景与初始化报告](scene-chain.md)、`salt/evidence/scene-chain.json` 和 `assets/scene-inventory.json`。这些成果提供重建依据，尚未形成可独立运行的游戏或完成启动验证。

## 已完成

已继续建立 `PlayerController → InputResolver / PlayerLocomotion / PlayerAction → CharacterController.Move`，以及交互候选、事件广播与选定动作完成回调；新增 94 次非空 REA 查询。原始 PlayerAction 输入表（61 actions / 88 bindings）、14 组枚举、移动基础参数、78 条动作记录引用和玩家碰撞组件配置同步保留，见 [玩家玩法调用链](player-chain.md)、`salt/evidence/player-chain.json` 与 `assets/player-config.json`。跳跃存在未接通输入的代码分支，完整动画/交互/特殊状态与运行验证仍未完成。

| 项目 | 结果 | 证据 |
| --- | --- | --- |
| 全局定位索引 | 76 程序集、10,508 类型、79,095 方法；70,948 个方法有原生地址 | `salt/symbols/index-summary.json` |
| 未解析坐标 | 1,467 个泛型/未解析指针、6,680 个空指针保留未知；4,523 个原生地址有多个元数据别名 | 同上，完整索引在 `salt/.cache/methods.sqlite` |
| 原始 KeyData | `resources.assets` pathID 61594，164 字节，字段解析至 EOF，脚本身份与类型 hash 一致 | `assets/resources-keydata.json` |
| Salt/GUID | 从 KeyData 独立恢复，与用户提供的旧成果一致 | 同上及 `salt/evidence/recovered-crypto.json` |
| 密码 | 从原生字符池、26 个构造索引和 GUID 变换独立恢复，与旧成果一致 | `salt/evidence/recovered-crypto.json` |
| 原生加密调用链 | 一次导入查询 10 函数 / 12 观察，84.668 秒；补充 3 个初始化/库函数，83.508 秒 | `salt/evidence/crypto-batch/run.json`、`crypto-batch-helpers/run.json` |
| 解密副本 | 223,101,993 字节，SHA-256 `98621b2c4fa4f9de80f355fae5776ab17efc016bcc81c581bcd0917af4308367` | `salt/.cache/decrypted/models.unity3d` |
| 容器验证 | UnityFS v8 / Unity 2022.3.62f2，3 节点，全部 3,819 块可解码，总解压流 500,551,232 字节 | `salt/evidence/decryption-verification.json` |
| 对象目录 | 主 SerializedFile v22，2,650 类型、76,079 对象，带 type tree | `salt/evidence/decryption.json` |
| 标题进入游戏 | 新游戏/继续分支、两次场景切换、状态恢复及主要初始化/更新入口 | `scene-chain.md`、`salt/evidence/scene-chain.json` |
| 原始场景配置 | BuildSettings 10 场景、MStage 8 记录、入口组件与 5 个按钮持久调用 | `assets/scene-inventory.json` |
| 玩家移动与操作 | 输入帧语义、普通移动/跑步/蹲姿、自动移动取消、Unity 位移出口、交互广播及选定完成回调 | `player-chain.md`、`salt/evidence/player-chain.json` |
| 原始玩家配置 | 实际输入 map、默认键位、枚举数值、速度/动作前缀与 CharacterController 字段 | `assets/player-config.json` |

解密包主节点是 `CAB-2afa88b54ee4aa6beff98892b77cac4c`，另有 `.resS` 和 `.resource`。对象表已读通，不等于每个模型、材质或 MonoBehaviour 字段的业务含义均已恢复。

## 已建立的解密链

1. 原始 UnityFS 的块/节点表 → `resources.assets` 对象表 → KeyData 对象与关联 MonoScript。
2. `models` 对应 `Assets/ZZZ-ExternalEncryptAsset`，其 `hash` 是 signed int64 `-265379604`。GUID 是 `add7ae9ef7e0477e9d0aeb6d43949b7a`。
3. `PasswordMap::.cctor` 绑定 195 字符的池（metadata string literal 883）；构造函数用 26 个索引构成 `map["models"]`。
4. `GetPasswordFromMap` 逐字符查池索引，减去 GUID 对应字符的十六进制数，负数加池长度，再取字符。所得密码与旧成果逐码点一致。
5. `GetSalt` 把资源 hash 转十进制字符串，若短于 8 字符则在右侧追加 `0`，再 UTF-8 编码。本资源得到 10 字节 `-265379604`。
6. `GetStream` 以 keySize=256、CipherMode=2（ECB）、PaddingMode=1（None）创建 `SeekableAesStream`。枚举元数据见 `salt/symbols/crypto-enums.json`。
7. 流构造函数用 PBKDF2-HMAC-SHA1 / 1000 次派生 32 字节 key；库构造函数的 UTF-8 路径与 `HashAlgorithmName.get_SHA1` 坐标也已核对。原生密码会经过 `TrimWhiteSpaceHelper(2)`；本密码无边缘空白，因此结果不变。它不是删去前两个字符。
8. `Cipher` 使用 AES-256-ECB 加密计数块产生密钥流，再与文件字节 XOR。计数块是 `LE64(floor(fileOffset/16)+1) || 8个零字节`，从 1 开始。构造函数分配零 IV，但 ECB 不用它作为变化中的 CTR IV。

因此这里不能直接套默认大端计数器的 AES-CTR API。`salt/crypto.py` 按实际的小端计数布局实现，并验证了跨 AES 块边界的非对齐随机读。原始密文 SHA-256 是 `bb3a495d023a00ff95c110955a436e4d4dd2eea0598919401eb236d3e132ade9`。

## 复现与继续分析

在仓库根目录执行。依赖当前已安装的 Python `cryptography`、Node、REA 6.5.0、Ghidra 12.1.4 和现有 JDK；没有新增安装。

```powershell
# 原始资源对象证据与符号索引
python reverse-engineering/assets/inspect_resources.py --output reverse-engineering/assets/resources-keydata.json
python reverse-engineering/salt/metadata.py index
python reverse-engineering/salt/metadata.py find --assembly IKA9nt.Encrypter --method GetStream

# 一次原生导入，顺序查询整条加密链；使用独立公共 REA MCP 子进程
python reverse-engineering/salt/prepare_batch.py
node reverse-engineering/salt/run_batch.mjs
python reverse-engineering/salt/prepare_batch.py --phase helpers
node reverse-engineering/salt/run_batch.mjs reverse-engineering/salt/symbols/crypto-helpers.plan.json

# 从原始对象和原生证据恢复参数，再检查/解密资源包
python reverse-engineering/salt/crypto.py recover
python reverse-engineering/salt/crypto.py inspect
python reverse-engineering/salt/crypto.py decrypt
python reverse-engineering/salt/crypto.py verify

# 复核已保存证据，并校验原始文件与解密副本的指纹
python reverse-engineering/audit.py --inputs

# 上层加载链：选择入口并复用同一 REA 批次会话
python reverse-engineering/salt/prepare_loading.py
node reverse-engineering/salt/run_batch.mjs reverse-engineering/salt/symbols/loading.plan.json
python reverse-engineering/salt/loading_evidence.py --check
python reverse-engineering/salt/asset_evidence.py --check
python reverse-engineering/assets/inspect_scenes.py --check
python reverse-engineering/salt/scene_evidence.py --check
python reverse-engineering/assets/inspect_player.py --check
python reverse-engineering/salt/player_evidence.py --check

# 按选定程序集增加元数据名称种子；选中方法的别名优先
python reverse-engineering/salt/prepare_loading.py --name scene-example --seed-assembly Assembly-CSharp.dll --method-id 16862

# find 的 id 可用于选择其他方法，生成独立种子和计划，不必改脚本
python reverse-engineering/salt/prepare_batch.py --method-id 76342 --name getstream
node reverse-engineering/salt/run_batch.mjs reverse-engineering/salt/symbols/crypto-getstream.plan.json
```

`decrypt` 要求输出不存在，默认保存到 `.cache/decrypted/models.unity3d`。若副本已经存在，直接运行 `verify`；或用 `--output` 指定另一个新路径。原始密文不会被覆盖。

所有函数地址、原始 token、参数计数、共享地址别名和文字字节均绑定到构建指纹。全量 SQLite 与大解密副本在 Git 忽略的 `.cache` 中，可由脚本重建；可复查的原始观察、选定符号、计划和脚本在普通目录中。此目录通过 `.gitattributes` 禁用 Git 换行转换，保证克隆后的证据文件字节与指纹索引一致。

## 证据使用边界

REA 输出保留 `evidence_id`、输入 SHA-256、分析 profile、种子承诺和已关闭的自动发现器。种子名称是从元数据提供给 Ghidra 的分析者断言，不是反编译器自行恢复的原始 C# 源码。

批量入口使用同一 Ghidra 会话避免重复导入，导出证据后关闭。未修改 Codex 全局 MCP 配置。直接用旧默认全库模式仍可能很慢，快照也未提供本机 5 秒重放；后续使用批量入口，读取既有结果则直接打开保存的伪代码/JSON。

资源解密验证限于本构建的 `models` 包；另已静态追踪标题进入游戏的场景、状态与主要初始化入口。其他包、动态补丁、实际运行时顺序、其余泛型实例和所有对象语义仍未完成。完整引用图、部分间接调用/类型签名、动画事件/状态机、ES3 全序列化和玩法子状态尚未恢复；关闭的全库发现选项会限制这类结论。未知项见 `unknowns.json`，证据文件指纹见 `evidence-index.json`。
