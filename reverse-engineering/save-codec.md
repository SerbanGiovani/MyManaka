# 实际存档设置与独立只读解码

2026-10-27，继续优先补齐存档链。本轮新增56次非空 REA/Ghidra 查询：`save-codec-core` 34、`tail` 14、`format` 8。原始游戏目录仍只读；未启动游戏、未写回存档。

主要结果：已恢复原始 ES3Defaults、默认设置复制、路径/流/读取器选择和存档加密参数；独立解码测试副本的8份加密快照，37个顶层键均可解析。16个根对象字段与此前声明完全对应，并能在内存中按原 IV 重现8份原文件字节。这是编码和结构验证，尚未执行原生对象保存/加载往返。

原生绑定见 [save-codec-chain.json](salt/evidence/save-codec-chain.json)，资源字节及声明见 [save-settings.json](assets/save-settings.json)，样本结果见 [save-codec-validation.json](salt/evidence/save-codec-validation.json)。

## 1. 默认设置来自实际资源

`globalgamemanagers` 的 ResourceManager 前部包含82个资源条目。键 `es3/es3defaults` 经真实 external-reference 表解析到 `resources.assets` pathID **62524**，576字节；MonoScript 为 `ES3Defaults` / `Assembly-CSharp`，properties hash 与 serialized type 匹配。

`ES3Defaults.settings` 的声明类型为 `ES3SerializableSettings`，它继承 `ES3Settings` 且不声明新字段。选择布局按原始声明、独立 interop 属性类型、枚举值和原始字段偏移核对，完整消费576字节；该资源本身没有 type tree。私有 `_location` 的包含及 `Encoding` 的省略是本次已验证的特定布局，不当作通用 Unity 序列化规则。

关键配置如下；完整数组、原始字节、字段 ID 与三个坐标系的偏移均留在资源 JSON 中。

| 设置 | 原始值 |
| --- | --- |
| `_location` | 0 / File |
| path | `SaveFile.es3`，随后由 SaveRapper 当前路径覆盖 |
| encryptionType | 1 / AES |
| encryptionPassword | `unReRU821Drq83` |
| compressionType | 0 / None |
| directory | 0 / PersistentDataPath |
| format | 0 / JSON |
| prettyPrint / bufferSize | true / 2048 |
| typeChecking / safeReflection | true / true |
| memberReferenceMode / referenceMode | 0 / 2 |
| serializationDepthLimit | 64 |

`ES3Settings.get_defaultSettingsScriptableObject`（11768）传入的原始字符串 usage 为 `ES3/ES3Defaults`。MethodSpec 明确闭合为 `Resources.Load<ES3Defaults>`，共享方法体 `0x1809fce30` 已补查到 Resources.Load(Type) 与结果类型检查；不是用资源名字猜接线。

`get_defaultSettings`（11769）从该对象的 `settings +0x18` 缓存默认设置；`ES3Settings::.ctor(true)` 继而 `CopyInto`（11782）。上轮泛型保存辅助再将 path 改为 SaveRapper 当前路径。配置恢复为已知值后，仍保留其他消费者/Mod 在运行时修改设置的可能性，未执行穷尽排除。

## 2. 存档加密与资源包是两套参数

`AESEncryptionAlgorithm.Encrypt/Decrypt` 的流重载（12879/12880）明确使用16字节 IV、派生100次、取16字节 key。补查原始 mscorlib 的 Rfc2898DeriveBytes、SHA1 getter、AES 和 SymmetricAlgorithm 构造函数，连接得到：

```text
iv         = file[0:16]
password   = UTF8("unReRU821Drq83")
key        = PBKDF2-HMAC-SHA1(password, salt=iv, iterations=100, length=16)
ciphertext = file[16:]
plaintext  = AES-128-CBC-Decrypt(ciphertext, key, iv), remove PKCS7
```

加密侧生成 IV 并将它写在密文前，再使用同一个 IV 作为派生 salt。解密侧读取这16字节、赋 IV、派生 key，然后读取 CryptoStream。CBC=1、PKCS7=2 由原始枚举默认记录验证，虚方法槽声明另保留以核对间接调用。AES 类初始 key size 不等于本调用最终 key size；此处最终 `GetBytes(16)` 并设置 Key。

资源包原先恢复的 salt、长日文密码、1000次派生与 AES-256 仍属于资源包链；本次没有将其套到 `.sd`。

## 3. 路径、流和文本分派

`SaveRapper.GetSaveDataPath/GetSpecifiedSaveDataPath`（17406/17407）保留系统、打断、自动/手动及备份路径分支，随后 PreProcess 设置当前路径。原始字符串 usage 与条件对应存放在绑定文件；它们不是当前磁盘绝对路径的运行快照。

`ES3Settings.FullPath` 对绝对路径直接返回，文件位置/相对路径按 directory 拼接；`ES3IO::.cctor`（12904）初始化 Unity persistentDataPath 和 dataPath。绝对路径、默认路径根及外部启动环境应分别处理。

复用 `ES3Stream.CreateStream`（13102/13103）后，可连到 FileStream → 按设置解密 → 无压缩分支；`ES3Reader.Create` 的选定重载通过 format=0 创建 ES3JSONReader。写侧对应 ES3JSONWriter。`ReadKeyPrefix`（13034）按 `__type` 与 `value` 两段恢复键的类型和内容。

普通字典键直接经过其键类型读写；`StartWriteDictionary/StartWriteDictionaryKey/EndWriteDictionaryKey` 与读侧对应方法已补查。实际游戏档中存在 `{8:false,0:true,...}`，属于 ES3 的数字键字典表示，Python 标准 JSON 解析器会拒绝。不能用全局文本替换或把所有键转成字符串掩盖这个区别。

## 4. 独立读取覆盖

从独立测试副本 `UserData/SaveData` 读取 `0/1/2/3/s.sd`，并读取 `SaveDataBackup` 的 `0/1/3.sd`。捕获前后源文件哈希一致；加密快照仅保存在忽略目录 `salt/.cache/save-codec/`，后续核验读取固定快照。明文只在内存中使用，仓库保存哈希、类型、字段覆盖和统计。

| 检查 | 结果 |
| --- | --- |
| 加密快照 / 完整解码 | 8 / 8 |
| 顶层类型/值包头 | 37 |
| 数字字典键 | 12,895 |
| 原 IV 内存重加密逐字节一致 | 8 / 8 |
| 根对象字段完整对应 | 16 / 16 |
| GameStateData / PlayerCustomData | 每份游戏/备份档分别107 / 66字段 |
| OptionData / TutorialData | 系统档68 / 15字段 |
| 标准 JSON 可直接解析 | 仅系统档；其余7份含数字字典键 |

本轮存储类型头还直接确认系统键：`RankData` 为 Int32[]、`TotalPlayTimeData` 为 UInt32[]、`DifficultData` 为 DifficultType[]、Home/InterruptSaveTime 为 DateTime、Manual/AutoSaveTime 为 DateTime[]。它们的对象恢复、日期编码语义、版本迁移及长度规则未因此全部完成。

[save_codec.py](salt/save_codec.py) 提供解密及保留键类型/顺序/重复项的结构读取。字符串按 JSON 转义解析，数字键与字符串键保持区分；只覆盖本轮观察到的字符串/数字键语法，未恢复所有 ES3 引用、对象构造或 Unity 实体。8项专项测试验证 UTF-8/PBKDF2、转义字符串、键类型、重复项保留、错误语法、深度上限、填充及截断/错误密码拒绝。

## 5. 下一步边界

本轮关闭了实际默认配置、存档密码、选定加密封装及真实样本独立读取的缺口。仍缺原生对象往返、引用/默认值/迁移的全面恢复、其他保存来源及 Mod 格式。内存重加密复现字节只证明本编码路径兼容，不能当作游戏已成功载入重建对象，也未生成可独立运行的游戏。

下一优先级可推进游戏逻辑层的存储值恢复/初始化验证及任务配置与完成条件；此前相机/导航和具体交互的运行等价性继续保留未知。

复核命令：

```powershell
python reverse-engineering/assets/inspect_save_settings.py --check
python reverse-engineering/salt/test_save_codec.py
python reverse-engineering/salt/validate_saves.py --check
python reverse-engineering/salt/save_codec_evidence.py --check
python reverse-engineering/audit.py --inputs
```

`--inputs` 需要当前原始输入和本机固定加密快照。重新采集使用 `validate_saves.py --capture-root <独立副本UserData目录>`，仅创建缓存快照并更新结果，不写回游戏文件。
