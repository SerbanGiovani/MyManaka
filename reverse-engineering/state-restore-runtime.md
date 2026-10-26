# 原生保存、加载与运行对象对照

2026-10-27，在完整独立副本 `E:\ManakaREA-NaturalGameplay` 中完成 **1 轮干净的受控原生往返**。原生 `SaveManager.Save/Load` 写入、读取真实加密文件；独立 Python 解码器核对磁盘字段；REA/Frida 记录恢复入口、闭包、Warp、Drop、Hide 和预留谓词返回；Unity 主线程读取最终对象。

后续 [自然标题与默认守卫验证](natural-load.md) 确认出厂force=true绕过OnLoadData，loaded保持false；本页的受控正例不能据此推广为自然非空NPC保存已可达。自然新档备份已生成，再次标题读回按用户要求留待下次。

结果覆盖 **3 名动态 NPC、1 项当前场景掉落物、1 项异场景掉落物、2 项不同场景的预留记录**。这是选定原生消费者的受控重放，**自然输入测试为 0 轮**。没有证明完整标题读档后自动回到商场，也没有生成替代游戏。

可复查结果：[results.json](runtime/state-restore/results.json)、[原生文件投影](runtime/state-restore/native-save.json)、[REA 原始记录](runtime/state-restore/rea-runtime.json)、[运行清单](runtime/state-restore/manifest.json)。本轮保留 **4 份完成轮的 canonical REA observations**；另以压缩档保存全部 36 份诊断/准备记录，失败或受污染的轮次不计入完成轮。

## 保存 → 加载 → 运行对象

完整初始化先走标题原生面板入口；以不存在的槽 19 调用 `Load(NewGame=5,19)` 取得默认状态，再经面板 `TransScene`、淡出与 Springboard 进入自宅。随后受控加载商场，原生场景流程生成 30 名 NPC。此次没有使用原始存档中导致部件索引越界的定制状态。

本实例原先 `isLoadedData=false`。显式对空 NPC 保存列表调用原生 `OnLoadData`，使保存生产者可执行；该前置本身属于受控操作，不能据此认定自然流程已经走到非空 NPC 保存。将管理器视图暂时缩为 3 名已有 NPC，并提供空的原生列表，再调用 `ApplyGameState`，由原生函数生成全部 3 条位置/旋转/IsExist 记录。

掉落物经原生 `Drop` 生成；预留记录经 `ReserveDrop` 生成。异场景掉落对照另将其 StageType 设为 0，这是明确的夹具条件。原生手动槽 `Save(3,0,false)` 保存后，测试清空当前工作列表并隐藏当前物品，再调用 `Load(3,0)`。

| 对照项 | 磁盘保存值 | 原生 Load 后 | 消费者执行后的对象/状态 |
| --- | --- | --- | --- |
| GameState 根 | 保存时实例 | 新实例，身份不同 | 对该新实例执行选定消费者 |
| 动态 NPC | 3 条，IsExist 均为真 | 3 条新记录，姿态与磁盘一致 | 3 次带记录 Instantiate、3 次 Warp、3 个活动对象 |
| Coat / Item 0 | IsDropped=true，Stage=11 | 字段与磁盘一致 | 当前场景 Drop，活动；Transform 与保存姿态一致 |
| Bra / Item 4 | IsDropped=true，Stage=0 | 字段与磁盘一致 | 商场中进入 Hide，非活动；IsDropped 仍为真 |
| Hoodie / Item 1 预留 | IsReserve=true，Stage=11 | 仍在预留列表 | 谓词清 IsReserve，调用随机位置 Drop，返回 true 并出队 |
| Pants / Item 3 预留 | IsReserve=true，Stage=0 | 仍在预留列表 | 谓词返回 false，保留；再次处理仍保留 |

保存文件 SHA-256 为 `7b572855d33725a6b2e9d45df63c051175c0ebb5de72ea32593485882c94f40d`。原始加密快照仅留在忽略的 `.cache/native-roundtrip.sd`；仓库保存选定字段投影，未保存完整明文。`--inputs` 会重新解码原始快照，并与投影逐项比较。

## 关键原生调用与身份连接

REA 观察到 NPC 恢复闭包调用点 **RVA 0x432e18** 进入 `InstantiateNpc(record,false,0)`。记录指针与加载后的记录逐项连接；初始化中的 **0x427c18** 调用 `NpcController.Warp`。Warp 返回后立即读取真实 Transform，3 名 NPC 的位置及旋转与独立解码值最大差异均为 **0**。约 **3.057 秒**后，管理器中的 3 个对象身份仍与 Warp 返回对象一致，均为活动状态，并已继续正常移动。不能把稍后移动后的坐标当作读档误差。

当前场景激活循环的 **0x48ac81 → Drop(Item 0)** 使用保存姿态；异场景分支的 **0x48ac9e → Hide(Item 4)** 保留 IsDropped。预留谓词 **0x48ad30** 接收加载后的同一条记录；匹配分支从 **0x48af4e → Drop(Item 1)** 选择原生随机位置，该位置继续与运行对象对照。

预留列表数量为 **保存 2 → Load 后 2 → 首次处理后 1 → 再次处理后 1**。Hoodie 的谓词只成功一次，Drop 总计一次；Pants 两次返回 false，没有 Drop。再次处理时 Hoodie 的缓存对象身份保持不变，没有重复投放。

## 场景字段的必要边界

实际观察到 **磁盘 Stage=11 → 原生 Load 后 Stage=0**。测试实例仍处于商场，因此在调用三个消费者前，显式把加载数据的 StageType 对齐为 11。这一步对应对“实际场景与保存状态”进行受控协调，**不能等同于观察到完整自然场景恢复**。

执行的消费者为 `NpcManager.OnLoadData`、`DroppedItemManager.ActiveDroppedItemIfNeed`、`ApplyReserveDropIfNeed`。当前物品通过已有、被隐藏的测试缓存重新激活；本轮没有证明该物品在空缓存时的重新实例化。NPC 则是新建控制器/运行对象，并通过原生记录进入 Warp。

## 准备失败、清理与文件保护

诊断档保留以下失败，均未计入干净完成轮：初版 Frida 引用回填错误造成副本退出、嵌套路径拦截未生效；隐藏的旧插件副本抢先加载；直接进入商场缺持久管理器；已有定制存档的部件 ID 越界；NPC 保存列表高水位复用；以及首轮清理旧 NPC 时的重复注册。

其中，高水位复用已与原始 `ApplyGameState` 核对：列表只增长，超出本次有效数量的记录设 IsExist=false，不直接缩短。完成轮改用空的原生工作列表，保留原列表用于清理。旧 NPC 始终保持原有激活状态，避免 OnEnable 重复注册；测试对象销毁后恢复管理器列表、字典、掉落缓存、保存列表、预留列表、修改过的掉落字段、spawnNum 和状态应用开关。

干净完成轮清理后恢复 **30 名原有 NPC / 30 条原有记录 / 0 条预留**，列表、字典、缓存引用一致，spawnNum 回到原值，状态应用重新启用。该轮完整引擎日志 **0 条 Error**。8 项分析器测试会拒绝姿态错配、根身份复用、缺少 Warp 返回、重复投放、异场景误出队、未激活对象或清理失败。

早期路径失败更新过独立副本的 `0.sd/s.sd`，已从完全匹配的加密缓存恢复。最终副本原有 **9 份 UserData 文件**均与本轮开始时哈希一致；GameAssembly、UnityPlayer、metadata、data.unity3d、models 包 **5 项输入**与冻结原始目录一致。完成后已关闭 REA 会话和独立测试进程，临时插件移出 plugins；原 NaturalObserver 插件哈希不变。会话关闭工具返回目标状态 unknown，未将它解释为已证明正常退出；进程退出另由操作系统核对。

## 复核与剩余覆盖

```powershell
python reverse-engineering/runtime/state-restore/analyze.py --check --inputs
python -m unittest discover -s reverse-engineering/runtime/state-restore -p test_analysis.py
python reverse-engineering/audit.py --inputs --write-index
```

`collect.py` 封装的是这次固定捕获，不是游戏操作自动化入口。`RestoreProbe.cs`、`build.ps1` 和三个 passive witness 是完成轮实现；`RestoreProbe-v1.cs`、prepare/inventory/proof 系列仅用于保留历史诊断，不计为成功配置。

下一优先项是自然标题读档与场景归位、isLoadedData/强制重生守卫的实际可达性；随后补 IsExist=false、固定 NPC、电梯 Bounds 排除，以及冷缓存掉落物和恢复中途切场景/销毁的情况。玩家外观全部字段、导航路径和跨版本兼容仍不在本轮结论内。
