# 原始资源证据

来源固定为 `E:\SecretFlasherManakaREA`。本目录仅离线读原始文件，不启动游戏，不安装依赖，不导出整个资源包。

## 已建立的证据

- `save-settings.json` / `inspect_save_settings.py`：从ResourceManager真实映射解析ES3Defaults pathID62524，脚本身份/hash核对，完整消费576字节；保留原始设置、密码、枚举、字段及各类偏移。`--check`可复现；原生默认设置复制、加密链及8份加密快照独立读取见[存档解码报告](../save-codec.md)。
- `input-inventory.json` 保存四个实际输入的大小、SHA-256、头部、GUID 搜索边界及结果和本地工具的限定盘点。
- `npc-model-wiring.json` / `inspect_npc_models.py`：完整解析当前NpcManager与NpcComponent模板，保留九候选模型的Animator/Receiver/Avatar组件身份、AvatarType原始枚举、Casual1限定引用候选及models脚本指针盘点。`--check`可复现；它与 [NPC模型初始化报告](../npc-model-chain.md) 的原生选择链共同确认Receiver由模型prefab克隆继承，Casual1不在当前工厂候选中。全局运行添加/覆盖仍未证明或排除。
- `npc-animation-events.json` / `inspect_npc_animation.py`：使用同构建、同class/hash/engine的models donor schema，完整消费原始357个clip、48个controller与1246个Animator；保留四个NPC发现事件、时长/循环字段、Npc控制器clip表引用及10个Animator接线。`animator-wiring.json` / `inspect_animator.py` / `animator_tree.py`另完整解析选定Player/Npc控制器图和6个玩家Animator。复查脚本均支持`--check`；原生参数/接收器及边界见 [动画接线报告](../animator-wiring.md)。
- `resources-keydata.json` 保存 UnityFS 块/节点表、SerializedFile 元数据摘要、KeyData 对象及关联 MonoScript 的原始字节、SHA-256、字段跨度、原始 IL2CPP 字段记录。
- `inspect_resources.py` 使用 Python 标准库读取所需目录、元数据和少量块，支持本构建观察到的 UnityFS v8 / flags `0x243`、LZ4 或未压缩数据块、little-endian SerializedFile v22、IL2CPP metadata v31。运行实测约 3 秒（包括 2.44 GB 输入的流式 SHA-256），不加载或执行目标程序集。
- `scene-inventory.json` 与 `inspect_scenes.py` 补充原始 BuildSettings 的 10 个路径、17 个场景入口组件/脚本身份/父链、SystemManager 资源 prefab→AssetReferencer→MStage、8 条关卡记录前缀与 5 个标题 Button 的完整 PersistentCall。复查：`python reverse-engineering/assets/inspect_scenes.py --check`。脚本复用标准库解析器，并通过已有 Mono.Cecil 仅读取 interop 枚举/字段声明；不会执行游戏 DLL。Animator→Controller PPtr 与事件名字节命中单独保留，未冒充完整动画事件解析。原生调用链见 `../scene-chain.md`。
- `player-config.json` 与 `inspect_player.py` 补充实际 PlayerAction 输入资源（pathID 61593，61 actions / 88 bindings）、PlayerInput 引用、14 组原始 metadata 枚举数值、MCommon 移动参数、MAction 的 78 条记录指针及字段前缀，以及已验证解密 models 中 Player prefab/AvatarReferencer/CharacterController。复查：`python reverse-engineering/assets/inspect_player.py --check`。输入资产与 CharacterController 等已声明完整解析的对象消费至 EOF，MCommon/MActionRecord 等只解析所列前缀并保留原始尾部。默认绑定不代表运行时重绑定，原生调用证据见 `../player-chain.md`。
- `bareta-config.json` 与 `inspect_bareta.py` 补充被发现/逃跑相关声明、7组原始枚举、精神等级/等级/关卡表及MCommon精神参数前缀。6条精神等级、8条等级、8条关卡记录及各父表均完整消费至EOF；表内PPtr与目标记录使用独立来源坐标。复查：`python reverse-engineering/assets/inspect_bareta.py --check`。字段或配置存在本身不证明某状态路径使用它；原生链与models的真实Sad事件解析见 `../bareta-chain.md`。

```powershell
python reverse-engineering/assets/inspect_resources.py --original-directory E:\SecretFlasherManakaREA --output reverse-engineering/assets/resources-keydata.json
```

原始 `data.unity3d` 为 UnityFS v8，版本串 `2022.3.62f2`，大小 2,444,180,156 字节；37,407 个数据块、69 个节点。`resources.assets` 节点位于解压流 4,140,799,526，大小 260,427,616。其对象表有 88,285 个对象、371 个类型；`enableTypeTree=false`，因此不能从该资源自带的 type tree 恢复字段名。

GUID 原始字节命中 `data.unity3d` 的文件偏移 2,255,601,871 (`0x8671c0cf`)。对应块 #33515 的压缩文件范围从 2,255,595,889 开始、长 32,455；解压后 GUID 在该块偏移 10,794。资源节点内 GUID 偏移为 252,089,348。

包含 GUID 的对象是 `resources.assets` 的 pathID `61594`，classID `114`，节点内偏移 `252089296`，长度 `164`，SHA-256 `fdf6ef399d4181b1972a39ceaa6a98f73efc52add9d83c040619f58c9a339119`。其脚本引用 `(fileID=1,pathID=1570)` 经资源 external 表解析到 `globalgamemanagers.assets` 的 classID `115` 对象。MonoScript 明确记录类名 `EncrypterKeyData`、命名空间 `IKA9nt.Encrypter`、程序集 `IKA9nt.Encrypter`；该 MonoScript 的 properties hash 与对象类型 hash 一致。

按原始 metadata 中字段声明顺序与托管 interop 中字段类型进行结构解析，完整消费该对象至 EOF：

| 字段 | 对象内偏移 | 值 |
| --- | ---: | --- |
| `keydataGUID` | 48 | `add7ae9ef7e0477e9d0aeb6d43949b7a` |
| `fileName` | 84 | `0` |
| `_keys.Count` | 88 | `1` |
| `_keys[0]` | 92 | `models` |
| `_values.Count` | 104 | `1` |
| `_values[0].assetPath` | 108 | `Assets/ZZZ-ExternalEncryptAsset` |
| `_values[0].hash` | 144 | signed int64 `-265379604` |
| `allBundleList_Key.Count` | 152 | `1` |
| `allBundleList_Key[0]` | 156 | `Main` |

这是“结构解析 + 原始元数据一致性”证据；字典字段 `reference` / `allBundleList` 在该解释中不占序列化字节。原始字段表记录的 token、全局 field ID、字段表文件偏移和 runtime type index 全部保存在 JSON；runtime type index **不是**运行时原生字段偏移。这里只确证资源中的 hash 与既有 salt 数值相同；hash 如何进入运行时 salt 的结论还需结合原生 `GetSalt` 调用链。

`StreamingAssets` 实际仅有 `StandaloneWindows64\-265379604`，大小 223,101,993 字节，头部 `98 1a a4 a5 ca 6e 3f 4d ...`，不是明文 `UnityFS` 头。本目录提供原始输入证据；结合原生代码完成的密码恢复、解密及全部块验证见 `../salt/evidence/recovered-crypto.json`、`../salt/evidence/decryption-verification.json` 与上级 `README.md`。

## PasswordMap 搜索边界与未知项

已解析 `globalgamemanagers.assets` 的全部 3,320 个 MonoScript。`PasswordMap` 对应 pathID `2330`、节点内偏移 `359960`、大小 `76`，命名空间为空，程序集为 `IKA9nt.Encrypter`。原始 metadata 中类型 ID `9763`，字段顺序为 `passCharacter`、`map`、`additionalMap`。

`resources.assets` 的 330 条 script references 没有指向该 PasswordMap；唯一未指定 script type 的 MonoBehaviour 对象 pathID `83450` 的脚本指针是 `(0,0)`。因此当前限定资源范围内没有 PasswordMap 实例的证据。KeyData 的 164 字节也不含密码。密码随后通过 `PasswordMap::.cctor` 的字符池、构造函数索引及 `GetPasswordFromMap` 的 GUID 变换独立恢复，见 `../salt/evidence/crypto-batch/` 与 `../salt/evidence/crypto-batch-helpers/`；这与资源实例搜索的有界否定结果不冲突。

GUID 搜索只覆盖 `GameAssembly.dll`、`global-metadata.dat`、上述 StreamingAssets 文件及原始压缩 `data.unity3d`，分别测试精确小写 ASCII、UTF-16LE、UUID 16 字节和 GUID 小端 16 字节。除 `data.unity3d` 的一个 ASCII 命中外均无命中。这不是对所有解压后对象或整机文件的否定结论。

工具盘点在当前 Python 3.11 环境中发现 `cryptography`，没有发现 UnityPy / lz4 / Crypto / pefile / capstone / dnfile / lief；项目 BepInEx 包含 `Cpp2IL.Core.dll`、`LibCpp2IL.dll`、`AssetRipper.CIL.dll`、`AssetRipper.Primitives.dll` 库。限定目录/PATH 搜索没有建立独立 AssetRipper / Il2CppDumper / dnSpy CLI 可用性，其他位置或环境仍未知。
