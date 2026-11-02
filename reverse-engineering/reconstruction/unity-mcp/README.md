# Unity MCP 本机接入

本轮按用户要求接入当前Unity编辑器，采用官方Unity CLI与`com.unity.pipeline`，不另外安装第三方桥接。当前工程是`.cache/unity6-20261103-2`，Unity版本6000.6.7f1；本机配置与版本见[setup.json](setup.json)。

连接链为：Codex通过stdio启动`unity mcp --project-path <工程>`，CLI发现指定工程的Pipeline服务，再使用该实例的认证信息访问本地HTTP API。Pipeline绑定本机回环地址并使用每实例Bearer token；这里不记录token，不读取或提交实例的端口描述文件，也不启用Player端服务。

已安装的CLI版本为`1.0.0-beta.15`（winget包`Unity.CLI`版本`1.0.0.20015`），工程组件固定为`com.unity.pipeline@0.9.1-exp.1`。CLI属于本机工具，MSIX或Unity Hub后续可能自动更新；这里的版本是安装时观察值。

## 当前客户端配置

Codex的全局`config.toml`中新增`mcp_servers.unity`，命令为本机Windows应用别名：

```toml
[mcp_servers.unity]
command = 'C:\Users\for_j\AppData\Local\Microsoft\WindowsApps\unity.exe'
args = ['mcp', '--project-path', 'E:\SecretFlasherManaka v1.1.3_Uncensored\reverse-engineering\reconstruction\.cache\unity6-20261103-2']
```

该条目只选择当前工程。原REA和Node REPL条目继续保留；未使用会额外修改客户端sandbox网络策略的`unity mcp configure codex`。全局配置、认证材料与私有备份不进入仓库。

工程组件与客户端条目已完成安装配置，编辑器已被实际发现为ready。配置成功不表示现有聊天已经加载新增工具：需要重载客户端的MCP连接，或开始新会话，再检查Unity工具目录。

## 实际连接验证

2026-11-03的[连接记录](connection-proof.json)由独立stdio客户端实际发起：initialize协商协议`2025-03-26`，服务返回`unity-mcp/1.0.0-beta.15`；tools/list发现169个工具；只读`editor_status`调用成功，目标为当前工程和Unity6000.6.7f1，编辑器ready、未编译、Play Mode停止。该探测没有改场景或启动Play。

验证入口[probe.py](probe.py)读取客户端实际配置，并测试MCP握手、工具目录及只读状态；新输出路径才能重新运行，已有记录不会覆盖。它证明服务器与指定Editor已经连通，不代表本聊天的工具目录已热加载。当前会话仍需重载Unity MCP连接或开始新会话后，才能在聊天工具列表中使用这些能力。

## 后续工程复用

本机已有CLI时，用新的[configure.ps1](configure.ps1)安装锁版组件并注册指定工程：

```powershell
./reverse-engineering/reconstruction/unity-mcp/configure.ps1
# 新建的其他Unity6工程：
./reverse-engineering/reconstruction/unity-mcp/configure.ps1 -RunName unity6-new -ReplaceTarget
```

默认工程名从既有`editor-settings.json`读取，也可显式传`-ProjectPath`。脚本只对指定的有效Unity工程操作，并要求项目版本匹配当前编辑器选择。若本机没有CLI，先按官方方式安装：

```powershell
winget install --id Unity.CLI --exact --source winget
```

每次配置会在新的忽略目录`.cache/unity-mcp-configure-*`保留原Packages清单、锁文件和Codex配置；这些文件可能含本机敏感信息，不应公开。相同CLI与工程目标已配置时，脚本保留原条目及其工具策略。若条目不同，必须明确传入`-ReplaceTarget`；注册仍通过`codex mcp add`完成，其他配置的语义摘要会前后核对。发现并发变化时脚本停止，避免用旧备份覆盖其他修改。

Pipeline包写入后需要Unity刷新并重新编译。若显示`STATUS_PIPELINE_LOAD_PENDING`，先切换至该Unity窗口，等待包导入，再执行：

```powershell
unity status --until-ready --timeout 45 --project-path 'E:\SecretFlasherManaka v1.1.3_Uncensored\reverse-engineering\reconstruction\.cache\unity6-20261103-2' --format json
```

这些步骤安装Editor组件、配置stdio目标并检查就绪，不自动执行Play、编辑场景、创建账号或变更原游戏。此前Unity与Tuanjie的构建及玩法验收仍保留原历史范围。

一手参考：[官方Pipeline安装说明](https://docs.unity.com/en-us/unity-cli/unity-pipeline/unity-pipeline-package)、[官方Unity MCP命令参考](https://github.com/Unity-Technologies/unity-agent-plugin/blob/main/skills/unity-cli/references/integration-advanced.md)、[Codex MCP配置说明](https://developers.openai.com/codex/mcp)。
