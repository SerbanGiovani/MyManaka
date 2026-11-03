# 正式工程 Unity CLI／MCP 连接

本目录单独记录当前正式工程`UnityProject`的CLI与MCP接入。原`unity-mcp`目录保存先前缓存工程的安装事实，不应改写成新的目标。当前配置、版本与实际结果分别以`setup.json`、`registration.json`、`mcp-proof.json`、CLI回执及`manifest.json`为准。

本轮实际验证使用Unity CLI `1.0.0-beta.15`与Pipeline `0.9.1-exp.1`：独立stdio连接列出169个工具，`editor_status`确认正式工程在Unity `6000.6.7f1`中就绪、未编译且处于编辑模式；CLI确认`Assets/Scenes/Apartment.unity`已加载、为活动场景且没有未保存修改。

连接采用官方Unity CLI与工程已锁定的Pipeline包。Codex的`unity` stdio条目应启动：

```text
unity mcp --project-path "E:\SecretFlasherManaka v1.1.3_Uncensored\reverse-engineering\reconstruction\UnityProject"
```

在仓库根目录可重复执行注册脚本。它复用已安装的CLI和锁定的Pipeline包，仅更新客户端的`unity`启动表，并校验其余配置的语义摘要及Packages文件未变。默认备份与新回执写入被忽略的私有缓存，不覆盖本目录的本轮档案：

```powershell
python -B -X utf8 reverse-engineering/reconstruction/unity-connection/configure.py
```

CLI操作也应显式提供该正式工程路径。编辑器使用用户指定的`H:\Unity Editor\6000.6.7f1\Editor\Unity.exe`，可从仓库执行：

```powershell
pwsh -NoProfile -File reverse-engineering/reconstruction/unity-active.ps1 -Action Open
unity command editor status --project-path "E:\SecretFlasherManaka v1.1.3_Uncensored\reverse-engineering\reconstruction\UnityProject" --format json --no-banner
```

独立stdio探针证明MCP握手、工具目录和只读Editor状态；CLI回执证明正式工程的编辑器状态及保存场景。配置或独立探针成功不代表已有聊天自动热加载，应重载客户端的Unity MCP连接或开始新会话后，再检查工具可用性。

全局客户端配置备份保留在私有忽略目录；公开回执只记录Unity启动目标与其余配置的语义摘要，不提交完整配置、认证信息、Pipeline实例端口描述或Bearer token。Player端服务没有由本配置启用。

```powershell
python -B -X utf8 reverse-engineering/reconstruction/verify-unity-connection.py --inputs
```

历史`unity-mcp/verify.py`应继续验证原安装档案。全局审计在历史模式读该记录，并对其固定Packages输入另行真实哈希；当前客户端目标由本轮校验独立确认。
