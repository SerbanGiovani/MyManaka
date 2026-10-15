# REA 逆向工作基线

最新完整工作流、独立密码恢复与解密结果见上级 `../README.md`。本页保留旧成果基线与最初的 GetSalt 单函数分析入口。

日期：2026-10-16（Asia/Hong_Kong）。分支：`codex/rea-salt`。

原始文件目录：`E:\SecretFlasherManakaREA`。
分析成果所在 Git 仓库：`E:\SecretFlasherManaka v1.1.3_Uncensored`。
起点提交：`c1a4f0fef84419e9a048357c55bca6bf8c775ef9`。

## 已有成果

`baseline.json` 保存用户提供的旧逆向成果，密码按原 Unicode 字符保存，不做规范化。
这份基线保持用户提供这一历史来源。后续已从原始资源与原生代码独立恢复对应值，结果另存为 `evidence/recovered-crypto.json`，不回写或混淆基线来源。

| 项目 | 值 |
| --- | --- |
| Salt 文本 | `-265379604` |
| Salt 字节 | `2D 32 36 35 33 37 39 36 30 34`（10 字节） |
| KeyData GUID | `add7ae9ef7e0477e9d0aeb6d43949b7a` |
| 密码 | 见 `baseline.json`；26 个码点，UTF-8 编码为 62 字节 |
| 派生算法 | PBKDF2-HMAC-SHA1，1000 次，32 字节密钥 |
| 加密算法 | AES-256 |

salt 是带负号的十进制字符串编码，不是整数的四字节内存表示。使用 UTF-8 密码编码的本地派生结果，已通过 Python `hashlib.pbkdf2_hmac` 与 .NET `Rfc2898DeriveBytes` 交叉核对。
结果见 `evidence/derivation.json` 和 `evidence/dotnet-verification.json`。
后续通过原生 Rfc2898DeriveBytes 构造函数和实际资源解密确认 UTF-8 路径。现已复现 AES-ECB 计数块密钥流、零 IV/无填充配置，并验证解密包全部 3819 个数据块，详见上级报告和 `evidence/decryption-verification.json`。

## 本轮 REA 证据

REA 6.5.0 已完成原有 `BepInEx/interop/IKA9nt.Encrypter.dll` 的托管静态检查：

- 包装 DLL SHA-256：`60efe344e94846b5d340b0ec0258b9c84e7b5108c447d35ef67f6247b0e51222`。
- MVID：`566a20f8-0e12-49d8-8827-270995120259`。
- `IKA9nt.Encrypter.EncrypterCore.GetSalt(string)` 的包装层 token 为 `0x0600017e`；该方法调用 IL2CPP 原生实现，包装层不是原始算法源码。
- 身份证据：`ev_16a409c7f4790734e3bb1398701fc920699857acc76b3c0b0d4b3a4fb7a1a756`。
- 聚焦成员证据：`ev_2a6fe4c8478dcc8d8201a2f626d7d839dbd0f5503685c2ddc9fe0a4263a140b4`。
- 完整可携带证据保存在 `evidence/rea-evidence.json`，包含 4 条 REA 记录。

`extract.py` 使用 Python 标准库从指定 Git 提交导出原有包装 DLL，并静态解析原始元数据及原生模块指针表；它没有执行游戏代码。
对本次文件的定位结果为：元数据 v31、原始 MethodDef token `0x060000ac`、原生地址 `0x18143e460`、文件偏移 `0x143cc60`。
包装层 token 和原始 token 分属不同产物，不可混用。输入指纹和定位结果见 `evidence/artifact-identity.json`。

## 原生分析超时修复

首次原生分析使用 Ghidra 默认配置，整个 DLL 的导入、自动分析和桥接就绪共用 330000 毫秒期限，最终返回 `provider_timeout`。
线程采样显示工作集中在全库入口点、非返回函数修复、指令/数据引用和地址表发现；不是本次 `GetSalt` 函数自身的反编译耗时。
仅延长期限的全库对照运行未验证完成，已停止。针对 `GetSalt` 的单函数配置已经成功，实测冷启动 **82.109 秒**。

`native.py --focused` 仍读取完整、指纹匹配的原始 DLL。它从元数据已定位的 `0x18143e460` 入口开始，关闭以下全库自动发现分析器：

```text
Disassemble Entry Points
Function Start Search
Subroutine References
Reference
Data Reference
Create Address Tables
Non-Returning Functions - Discovered
Decompiler Switch Analysis
```

入口和名称记录在 `native-getsalt.seeds.tsv`，属于分析者提供的种子，不能当作 Ghidra 自行发现的符号。
REA 输出的分析配置已包含这些开关及种子指纹。单函数模式的完整引用图、调用目标识别及全库函数发现仍有限，不能扩展为全库覆盖结论。
本次结果是 Ghidra 伪代码，未恢复的 IL2CPP 类型和 `0x18143e62a` 间接尾调用仍保留警告。
单函数伪代码本身不提供运行时 hash 数值；后续已经从原始 KeyData 对象恢复该值，并结合调用链完成离线解密，见上级报告。

成功证据：`ev_e1ebc5e626babc5f70df7b711746e81571fcb6844cddee5fb0cd0de2635a4c4e`。
结果文件：

- `evidence/native-getsalt-focused.json`：完整 REA 原生证据。
- `evidence/native-getsalt-focused.pseudocode.c`：便于查看的伪代码副本，不是可编译源码。
- `evidence/native-getsalt-focused.run.json`：退出码、耗时、目标指纹和实际调用参数。

脚本默认给单函数模式 600000 毫秒、全库默认模式 1800000 毫秒，设置只对子进程生效。
未修改 Codex 全局 MCP 配置；直接使用旧 MCP 默认分析设置仍可能超时。单函数命令保留兼容，整条资源链优先使用上级报告中的 `prepare_batch.py` / `run_batch.mjs`，共用一次导入。
Windows REA 快照重放实验在 5000 毫秒期限下仍启动 Ghidra并超时；该 CLI 生成的快照没有可重放的查询缓存条目。
因此脚本不默认启用快照，也不承诺快照加速。查看已经获得的结果可直接读取上述证据或伪代码文件。

## 复现

在 `E:\SecretFlasherManaka v1.1.3_Uncensored` 中运行：

```powershell
python reverse-engineering/salt/derive.py
python reverse-engineering/salt/native.py --focused
python reverse-engineering/salt/extract.py --repository 'E:\SecretFlasherManaka v1.1.3_Uncensored' --original-directory 'E:\SecretFlasherManakaREA' --output 'E:\SecretFlasherManakaREA\reverse-engineering\salt\extracted'
```

导出的包装 DLL 与原生字节窗口放在 Git 忽略的 `extracted/` 中；基线、脚本、文件身份记录及 REA 证据可纳入新分支。
原有未提交的配置、插件和存档修改保持原状。本轮未启动游戏，未提交或推送 Git 变更。
