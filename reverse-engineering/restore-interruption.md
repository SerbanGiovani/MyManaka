# NPC恢复队列与对象销毁

2026-10-30，四组明确受控原生重放补齐选定恢复任务的生命周期。REA保留7份规范证据：干净轮84及9条未截断消息，另有187条早期崩溃诊断消息。新增1份静态查询并复用9份既有查询。结论限于本构建选定NPC恢复闭包，未证明自然玩法可达概率或所有调度任务的行为。

| 对照 | 排队/闭包/Instantiate入口 | 克隆入口 | 最终队列 |
| --- | --- | --- | --- |
| 活着的临时管理器 | 各1 | 1，得到实际NPC | 到期移除 |
| 排队后销毁临时管理器 | 各1 | 0 | 到期尝试后移除 |
| Residence→Mall卸载临时管理器 | 各1 | 0 | 到期尝试后移除 |
| 已初始化原管理器经原生退出回调返回Title | 各1 | 0 | 到期尝试后移除 |

`Scheduler`位于DontDestroyOnLoad对象，时间模型持有Action。管理器销毁没有立即取消本次排队任务；保留的托管包装对象与Unity原生对象存活不是同一判断。调度恢复后，旧闭包仍调用`InstantiateNpc`，销毁对象的原生指针已为0。监测到入口、没有克隆、最后出队；入口探针不能单独确定具体提前返回分支，不能推断恢复创建成功。

本轮通过禁用/恢复Scheduler组件精确保持原时间模型；没有修改剩余时间。三组临时管理器未注册为全局管理器，initialized=false。第四组使用真实initialized=true的原管理器，并调用原确认回调`_OnClickSaveAndGoToTitle_b__18_1`，由其原生退出广播、淡出和完成回调切到Title。原管理器销毁后任务仍在队列，随后仅尝试一次并移除。此为受控原生回放，不是用户自然点击或自然时间窗口覆盖。

直接场景重载保留20条异常：17条SplineContainer终结器、3条NPC交互更新；完整栈不属于选定恢复闭包上下文。另一早期带返回钩子的采集在4个局部对照后以Windows异常e06d7363结束，后两项未完成；原因未定，不能归因于游戏缺陷或钩子。其源码、独立日志及Windows回执均保留。后续采用仅入口探针，两轮正常退出，探针和原插件已恢复。

5项分析器测试检查重复回调、销毁后克隆、过早移除和回调异常不能被掩盖。9份UserData、4份前轮自然存档及5项引擎/资源文件与原始指纹一致。原始完整证据见[runtime/restore-interruption](runtime/restore-interruption)，静态绑定见[salt/evidence/restore-interruption-chain.json](salt/evidence/restore-interruption-chain.json)。

下一项为完整存档状态及缺键、损坏、备份验证。本报告不替代自然非空NPC恢复、任意调度任务取消、全状态往返或独立游戏工程。

```powershell
python reverse-engineering/runtime/restore-interruption/test_analysis.py
python reverse-engineering/runtime/restore-interruption/analyze.py --check --inputs
python reverse-engineering/salt/restore_interruption_evidence.py --check
python reverse-engineering/audit.py --inputs --write-index
```
