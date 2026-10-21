# 时间停止生产者与重复通知夹具

本目录保留32次受控实验，详见 [调用链报告](../../time-stop-chain.md)。`Probe.cs`与`observe.js`对应manifest中的真实运行源代码；测试没有改写上轮 `npc-event-timing` 的探针或日志。

仅复核已测数据：

```powershell
python reverse-engineering/runtime/time-stop-producer/analyze.py --check
python reverse-engineering/salt/time_stop_evidence.py --check
python reverse-engineering/audit.py --inputs
```

重新运行：使用现有.NET编译器、BepInEx核心/interop和REA Frida，不需安装依赖。prepare要求全新目录及已验证的解密models副本：

```powershell
pwsh -NoProfile -File reverse-engineering/runtime/time-stop-producer/prepare.ps1 -FixtureRoot E:\ManakaREA-TimeStop-New
pwsh -NoProfile -File reverse-engineering/runtime/time-stop-producer/run.ps1 -FixtureRoot E:\ManakaREA-TimeStop-New
```

启动后以返回PID调用REA `start_frida_session(mode=attach)`，在该session载入本目录observe.js的绝对路径。确认observer_ready后，在测试副本创建空文件go。探针执行8条件×男女NPC×2轮并退出；run脚本会对其拥有的进程作超时清理，保留旧日志。

退出后取得未截断的 `frida_session_status`，导出完整REA Evidence bundle，关闭会话并确认PID退出，再传入该次实际信息：

```powershell
python reverse-engineering/runtime/time-stop-producer/collect.py --fixture E:\ManakaREA-TimeStop-New --export C:\path\rea-export.json --session SESSION_ID --evidence FINAL_STATUS_EVIDENCE_ID --pid PID
python reverse-engineering/runtime/time-stop-producer/analyze.py
```

采集命令用于有意更新本目录的记录，会覆盖这里的结果文件；副本原始日志保留。新脚本在实际运行后整理，已验证语法；当前留存实验以等价的显式启动、日志归档、构建及REA命令执行，并非声称已经完整重跑自动化脚本。

实验跳过bootstrap、原生根移动回调以及玩家片段的音效/结束旁支，构造必要的单例上下文。24次原生产者路径包含直接调用和显式触发原始玩家控制器，未执行完整自然输入或NpcController.Initialize。8次负对照有意额外广播或无广播修改标志，不能称为自然玩法触发。Unity persistentDataPath也不会因为换副本而重定向；该探针只用于此隔离夹具。

日志保留两条启动头：第一次仅等待启动门，未执行用例。最终32次用例由manifest记录的PID44056及Frida session关联，未把旧启动头计为测试。原始Light缺失脚本警告保留；最终运行未观察到Exception/Error。
