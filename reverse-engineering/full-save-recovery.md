# 系统档默认值、显式备份复制及原生读取接口

2026-10-30，优先级第3项第二批完成12个受控条件。干净轮保留315条未截断REA消息、42份加密捕获投影；10组各完成两遍原生Load/Save，第二遍游戏数据0变化，系统只增加第二手动槽保存时间。沿用[第一批256字段对照](full-save-restore.md)的类型保留解码器。

| 条件 | 结果 |
| --- | --- |
| 完整对照与既有进阶档 | 原生两遍成功，进阶档仅槽号0→1变化 |
| 整个游戏主档不存在 | 原生默认值可载入并稳定写回，与既有自然档有406个叶值差异 |
| 整个系统档不存在 | 默认系统对象可载入并稳定写回 |
| 系统缺OptionData、TutorialData、RankData或ManualSaveTime | 各自默认补齐，两遍稳定 |
| 缺OptionData.Language | 默认补齐，两遍稳定 |
| 系统密文截断7字节 | 原LoadSystem抛ArgumentException |
| 合法加密的系统明文语法损坏 | 原LoadSystem抛FormatException |
| 主档损坏→显式原SaveRapper.Copy(备份,主档)→再次Load | 初次FormatException；复制后两遍成功，游戏字段与备份基线0变化 |

显式恢复由测试程序调用原生`SaveRapper.Copy`，再调用原生`SaveManager.Load`。REA在复制入口直接读到一次性目录中的备份源与主档目标。没有把这个操作当作标题界面的自然恢复入口或自动回退；[第一批](full-save-restore.md)已确认选定Load入口在主档损坏且备份存在时仍抛异常。

10个成功条件另各核对12行原生读取结果，共180个标量：6个真实技能键的等级及被动激活、3个物品的持有判断、3个任务的完成次数。独立解码写回文件得到预期值，与原`GameStateFacade`方法结果全部一致。原生入口按同一线程的明确诊断标记限定到每个条件，保留调用ID和原生调用点；不靠游戏后台更新的同名调用充数。

原技能字典有49项，但键为0–24、10000–10022及-1，不能当作连续0–48。首版夹具误选48，10个条件在该读取处抛KeyNotFoundException，另2个系统损坏条件抛预期异常；这些诊断记录、203条REA消息和原DLL/源码独立保留，未计作干净往返。改为已存在的24后重新启动、完整补测全部12条件。

4项测试验证错误读取值、错误复制源和第二遍数据变化会被拒绝。最终副本正常退出，两个REA会话关闭，原插件恢复；9份UserData、4份前轮自然档及5项引擎/资源输入指纹未变。证据见[runtime/full-save-recovery](runtime/full-save-recovery)。

剩余边界仍是实际外观渲染/异步应用、库存消耗、技能效果和任务更新/奖励；读取接口与存储字段稳定不等于这些运行消费者已等价。引用别名、迁移、任意缺键组合和UI恢复未穷尽。本轮不宣布优先级第3项全部完成，也未开始以替代工程运行原游戏。

```powershell
python reverse-engineering/runtime/full-save-recovery/test_recovery.py
python reverse-engineering/runtime/full-save-recovery/analyze_recovery.py --check --inputs
python reverse-engineering/audit.py --inputs --write-index
```
