# NPC 动画通知运行夹具

结果与范围见 [实测报告](../../npc-event-runtime.md)，逐例数值见 [results.json](results.json)。原始逐帧数据、Unity和BepInEx日志以gzip保留，未包含游戏资源或插件DLL。

只复核已采集结果：

```powershell
python reverse-engineering/runtime/npc-event-timing/analyze.py --check
python reverse-engineering/audit.py --inputs
```

重新运行需要Windows、原始游戏及现有BepInEx/interop、PowerShell7、可用.NET Roslyn编译器和REA Frida。构建脚本使用仓库bundled .NET6引用，不执行NuGet还原。独立测试目录必须全新，约需原游戏副本大小的可用空间：

```powershell
pwsh -NoProfile -File reverse-engineering/runtime/npc-event-timing/prepare.ps1 -FixtureRoot E:\ManakaREA-RuntimeFixture-New
pwsh -NoProfile -File reverse-engineering/runtime/npc-event-timing/run.ps1 -FixtureRoot E:\ManakaREA-RuntimeFixture-New
```

`run.ps1`返回PID并继续等待，超时会清理它自己创建的进程。旧日志先移入该副本的runs目录。脚本按 `manaka-run-debug` 的启动/日志保留/退出规则实现；需为该副本使用本地日志路径，因此没有直接调用根目录固定的旧启动脚本。

在启动门前，通过REA依次执行：

1. `start_frida_session({mode:"attach",pid:实际PID})`。
2. `load_frida_script({session_id:返回ID,source_kind:"file",path:observe.js绝对路径})`。
3. 同样载入 `ordering.js`。若在测试开始后载入，日志将记录真实覆盖起点。
4. 在测试副本根目录创建空文件 `go`。探针自动执行60个用例并退出。
5. `frida_session_status`取得最终未截断消息，`export_evidence_bundle`保存完整REA bundle，然后`close_frida_session`关闭会话。另核对该PID已退出。
6. 采集时通过参数传入该次实际session、PID和最终Evidence ID；不会把初测或其他会话混入结果。

```powershell
python reverse-engineering/runtime/npc-event-timing/collect.py --fixture E:\ManakaREA-RuntimeFixture-New --export C:\path\rea-export.json --session SESSION_ID --final-evidence EVIDENCE_ID --pid PID
python reverse-engineering/runtime/npc-event-timing/analyze.py
```

`collect.py`将覆盖本目录中的结果文件，用于有意更新实验记录；原始副本日志不会被删除。当前提交的manifest记录了实际使用的源代码及插件二进制哈希。`rea-runtime.json`仅保留本次三个未改内容的Evidence记录，完整导出文件哈希同时留存；它不是可导入的REA bundle。

副本路径本身不会重定向Unity persistentDataPath。本夹具通过跳过游戏bootstrap、生命周期/移动回调与存档入口控制执行范围，并且替代音频功能；这不是任意游戏代码的全局写保护。不要将该探针部署到日常游玩的插件目录，也不要将此结果解释为完整场景的自然运行验证。
