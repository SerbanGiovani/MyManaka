# 自然标题读档、场景归位与 NPC 保存守卫

2026-10-27，本轮通过真实界面操作、REA/Frida 被动观察与独立文件解码，确认了默认 NPC 保存/恢复路径的关键限制：**出厂 `IsForceCreateNpc=true`；标题启动走强制重生，`OnLoadData` 未执行，`isLoadedData` 保持 false，因此后续 NPC 快照生产者直接返回。**有活动 NPC 或存档里已有非空列表，均不能单独证明当前玩法正在产生和恢复 NPC 快照。

新增 **10 次非空 REA/Ghidra 查询**，补充 Debug 静态构造/初始化、NpcManager 构造/销毁、保存界面及退出回调。原始 PE/Iced 扫描覆盖 **139898 个 RUNTIME_FUNCTION 片段、8534275 条指令**。本轮完成两条实际界面流程：导入非空测试档并通过标题加载；自然新游戏、出入 Residence、回家保存后返回标题。**新档再次点击继续读回尚未执行，已按用户要求保留现场挂起。**

证据入口：[静态绑定](salt/evidence/natural-load-chain.json)、[运行结果](runtime/natural-load/results.json)、[REA 记录](runtime/natural-load/rea-runtime.json)、[存档字段投影](runtime/natural-load/save-projections.json)、[采集清单](runtime/natural-load/manifest.json)。3 份完成捕获的 runtime observations 与10份静态 observations 分别保留。

## 默认守卫与可达条件

`DebugController..cctor`（16693）在 **RVA 0x487a49** 写 `static_fields+0x0b = 1`，同一函数把 `IsDebug +0` 设为 false。`DebugController.Initialize`（16690）先检查 IsDebug，false 时直接返回，没有清除强制创建标志。

`InGameManager.<Start>b__52_0`（16868）的 **0x498b80** 比较该标志：false 分支在 **0x498b95** 调用 `NpcManager.OnLoadData`；true 分支清 fixedNpcCount，进入 `RepopNpc`。自然观察两次启动都捕获到强制分支的实际返回调用点 **0x498bb3**，不是由“NPC 列表为空”选择分支。

`OnLoadData`（15583）在 **0x42f3ea** 写 `manager+0x65 = true`；`ApplyGameState`（15598）先检查这个字段，为 false 就返回。选定 NpcManager 与其嵌套类型共 **46 条方法声明、32 个 unwind 片段**的字节扫描只找到这一处同形 byte MOV/SET 写入。全模块直接分支扫描找到一处到 OnLoadData 的 call，即上述启动 false 分支。

| 条件 | 本轮结论 |
| --- | --- |
| 标题启动时 force=true | 走 RepopNpc，不走保存记录恢复 |
| isLoadedData=false | ApplyGameState 不生成新的 NPC 记录 |
| 要启用该快照链 | 启动回调时 force=false，并实际执行 OnLoadData 设置 loaded=true |
| 后续产生非空有效快照 | 还需有可保存的动态 NPC，遵守固定 NPC 等筛选 |
| 按记录实例化 | 记录 IsExist=true，并通过电梯 Bounds 排除条件 |

在被测的默认界面流程中，没有观察到 force 变为 false 或 loaded 变为 true。扫描中25个片段引用 DebugController usage 槽，带位移0xb的候选只有默认写1和启动读取。**这是有界扫描与默认流程结论，不排除更宽的写入、间接别名、反射、外部代码或 Mod；本轮未通过修改守卫制造“自然正例”。**

退出处理16826/16866会清 `InGameManager.isExist`，并将持久对象移回场景；NpcManager销毁处理15581清理已有NPC。运行采样中，两次启动对应不同的NpcManager指针，而静态Debug构造只执行一次，force持续为true。`isLoadedData`必须结合这次管理器生命周期读取，不能当作已经从GameState存档恢复的标志。

## 含3条 NPC 记录的档案通过真实标题加载

输入为上一轮受控原生保存生成的固定加密文件，SHA-256 `7b572855d33725a6b2e9d45df63c051175c0ebb5de72ea32593485882c94f40d`。它不是自然玩法产出的非空样本。本轮用户真实点击“继续”和手动槽0；没有重放 Load、手动调用恢复消费者或覆盖游戏字段。

捕获的顺序为：

```text
标题槽按钮 → SaveManager.Load(3,0) → SpringboardLoadEmpty
→ Apartment / InGameManager.Start
→ DebugController..cctor: force 0→1、IsDebug=false
→ 延迟启动回调 → RepopNpc
```

Load 后确实存在 **3 条新读取的有效记录**，位置/旋转与独立解码值一致；随后 **OnLoadData=0次、按保存记录 Instantiate=0次**。自宅中 loaded=false，记录仍留在状态数据中。因此“读入字段成功”和“选择按记录恢复对象”在此路径上是不同阶段。

场景字段从磁盘 **11 → Load 后0 → 实际Apartment**，本轮没有做场景字段协调。此受控来源档的商场玩家坐标仍进入了原生 Player.Warp；没有证据支持把它当作正常自宅出生点。**该输入是在商场中受控保存的，不能据此判定自然保存/读档的位置恢复有缺陷。**

## 自然新游戏、场景切换与快照生产

用户经正常界面选择空的手动槽1，实际调用为 `Load(5,1)`，得到空 NPC 列表；新启动仍走 force=true 分支。随后用户通过普通出口进入 `Night_Demo 1`，与原始配置对应 **Residence=10**，再正常返回自宅。

Residence 中峰值观察到 **25名活动NPC、fixedNpcCount=20**，差额5。此时 loaded=false，保存列表始终为空。四组逐次 Native ApplyGameState 入口/返回样本均保持 **loaded 0→0、保存数量0→0**；不是仅在没有 NPC 的自宅检查了空列表。

还记录到正常场景就绪的先后差异：帧27716场景名已是 `Night_Demo 1`，状态字段仍为 Apart；随后完成切换回调更新为 Residence。分析器区分加载中的暂态和稳定场景，不把这一帧视为恢复失败。返回自宅后状态重新为0。

## 实际保存落在备份，而非主槽

帧48305捕获 `SaveManager.Save(3,-1,...)` 的原生入口及返回；路径记录明确为 **`SaveDataBackup/1.sd`**。本次没有读取到第三个布尔实参，备份分类来自实际路径与文件，不倒推为已经捕获到该实参。

独立解码这份真实新文件得到：Stage=0、NPC列表为空、玩家位置/旋转与原生保存返回时一致。当前独立目录有输入主档0、系统档s和备份1，**没有 `SaveData/1.sd` 主档**。普通电脑保存处理17594的静态代码传 `Save(3,-1,false)`；本次观察到的备份不能代替普通主槽保存的验证。

随后用户返回标题并要求挂起。记录中只有标题的 System Load(4,-1)，没有新档的 `OnClickItem/Load(3,1)`，因此不声称自然新档已经完整“保存→再次加载→玩家姿态”往返。初始非空档的标题加载和后续自然备份保存分别成立，不能拼接成同一份自然非空档的往返。

## 文件保护、暂停与下一次入口

整轮游戏状态探针只读；附加插件只将存档路径及日志导向独立目录。8项分析器测试覆盖守卫、恢复入口、自然/导入来源、主档/备份、玩家姿态及未发生读回的反例。记录窗口 **0条引擎Error、0条状态采样异常**；副本原有9份UserData文件与5项引擎/资源输入哈希保持一致。

REA 已导出并断开。独立进程 **PID49736** 的挂起返回NTSTATUS=0；但收尾时进程已不存在，Windows随后记录了该进程的1002/AppHangB1关闭事件。**此次挂起未能持久保留内存现场，具体关闭发起方未确认。**暂停凭据与后续退出观察分别保存，不把先前的成功返回解释为进程仍存活。附加插件与独立备份保留在磁盘。

下次操作见 [继续工作入口](runtime/natural-load/next-run.md)。需要重新启动独立副本并连接 REA；先核对原生备份恢复入口，或通过正常电脑保存建立主槽1，再验证该自然新档的标题读回及玩家姿态。固定 NPC、电梯过滤、恢复中断及 force=false 下的完整启动仍属于后续覆盖。

```powershell
python reverse-engineering/salt/natural_load_evidence.py --check
python reverse-engineering/runtime/natural-load/analyze.py --check --inputs
python -m unittest discover -s reverse-engineering/runtime/natural-load -p test_analysis.py
python reverse-engineering/audit.py --inputs --write-index
```

记录窗口零引擎Error与暂停后出现AppHang是两个不同时段的观察。


2026-10-30后续：[自然标题读档闭环](natural-title.md)已通过真实新游戏、电脑保存和标题继续第二槽完成主档/玩家姿态对照。此处的“备份1、未再次读回”为本轮历史边界，不再代表最新状态；非空NPC默认守卫结论仍保留。
