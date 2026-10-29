# 固定、失效与电梯范围NPC记录的原生恢复对照

2026-10-30完成。仅在独立副本`E:\ManakaREA-NaturalGameplay`进行两组受控验证，工作目录`NpcRestoreFilter/20261030-1`，全新working-profile从上一轮自然第二槽复制。原UserData及上轮自然测试档不参与写入。

## 结论

固定NPC、失效NPC记录和电梯内记录分别在不同阶段排除，不能将最终未出现对象一概视为漏恢复：

| 情况 | 原生处理阶段 | 本轮观察 |
|---|---|---|
| 两名真实Pinpon固定NPC | ApplyGameState生成快照 | 4个运行对象减去fixedCount2，只生成两名普通NPC的记录 |
| 移去一名普通NPC | ApplyGameState更新高水位列表 | 两条记录仍保留，第二条IsExist变false，位置/朝向保留 |
| IsExist=false | OnLoadData迭代 | 在Bounds判断及Scheduler排队之前跳过；没有该记录回调/实例化 |
| IsExist=true、实际电梯PushBounds内 | OnLoadData调用Bounds.Contains | 返回true后跳过排队；没有该记录回调/实例化 |
| IsExist=true、电梯外或场景无电梯 | OnLoadData→Scheduler→闭包→Instantiate→Initialize/Warp | 各组单条有效记录对应一个队列、一个回调和一个实际对象 |

“固定NPC排除”是生产者契约：NpcSaveData只有Position/Rotation/IsExist，并不存固定类型。不能将本轮结论扩写为“读档消费者按固定类型过滤”。本轮没有改force，也没有验证force=false的自然可达性。

## 组一：真实固定NPC、原生保存与失效记录

受控进入Residence，初始22个运行NPC、fixedCount19、loaded=false。选择其中两名普通NPC和两名真实Pinpon固定NPC，保留原对象；原生读取的CurrentFixedType分别为0、0、9、9，托管名称与指针逐项对应。固定类型是枚举，原方法测试零/非零，不能把它当bool值1。

在冻结GameStateApplier期间，以空列表调用原生OnLoadData明确建立loaded前置，然后用临时容器和fixedCount2调用ApplyGameState。帧4836生成两条有效普通NPC记录；移去一名普通NPC后再次调用，列表不缩短，输出`[true,false]`。随后原生Save(Manual,1,false)写全新工作档，原生Load再次读入新记录对象。独立解码91,776字节加密文件确认场景10及两条记录、姿态与IsExist值。SHA-256为`bc3aa64c790ce2c1ea4ab3767dc8986aaf4cf383acfe9da99193f6c71398b0ba`。

原生Load将场景归为Apart，本组明确将消费者场景字段协调回Residence后调用OnLoadData，因此不计作自然标题生命周期。帧4836只为第一条排队，帧4839执行对应闭包、Instantiate及Warp，实际排队至回调约42.656毫秒。记录→闭包→回调→实例化返回对象→Warp→四秒后的运行对象按指针连接；Warp返回的位置/四元数与记录在float32精度一致。失效第二条没有排队。四秒观察结束只有一个新对象；随后销毁临时对象、恢复原22对象容器、fixedCount19、loaded=false及applier停止标志。

## 组二：真实商场电梯与存在性矩阵

受控进入Mall，使用实际ElevatorController单例的PushBounds，不替换Bounds或Contains结果：中心`[49.29,-6.045,-18.448]`，extents`[0.6627575,13.044352,1.2208333]`。外部位置取自当前NPC有效位置，内部位置取Bounds中心。

构造四条内存记录，组合为`(存在,外部)、(存在,内部)、(不存在,外部)、(不存在,内部)`。帧10495原生OnLoadData只对前两条调用Contains，返回false/true；调用点均为`0x42f6b6`。仅第一条经调用点`0x42f6f7`进入原Scheduler。帧10498执行回调，约39.581毫秒后进入原Instantiate（调用点`0x432e18`）及Warp（调用点`0x427c18`）。四秒后仅一个实际对象，姿态与指针连接成立；内侧存在记录及两个失效记录都未排队。

本组矩阵直接在内存构造，没有另行执行原生Save/Load，不冒充第二组文件往返。完成后恢复商场原21个NPC容器、fixedCount0、loaded=false和applier标志。

## 静态与运行证据

新增三份非空REA/Ghidra查询，复用OnLoadData、ApplyGameState、闭包、Instantiate、Save/Load与Scheduler；[静态绑定](salt/evidence/npc-restore-filter-chain.json)核对原metadata、usage及字段偏移。

- ElevatorController.Awake，14108：原生初始化与场景组件接线，Evidence`ev_1c2f90224ced994714cb5b2a4e5eba4c3292239c7399d06fdbd5dd9a38917a3c`。
- get_PushBounds，14102，Evidence`ev_2b5e8a1b081b46293e926365de458681da6555cab555bb1af666a7821354b0fc`：复制实例+0x5c的Bounds值。
- `0x180436630`辅助函数，Evidence`ev_e7c574d8d8dd4d10dbffa99b328c7dcb6b2bb96f896bac6f8b6dece6cfaa3fcc`：读取`0x182d59260`绑定的ElevatorController静态单例。函数显示名为分析者标签，不是原始符号。

REA会话`e2ca3c7c-d18f-46cd-8536-a5eb6f30974c`、PID40460。最终29条原生消息未截断，无脚本错误；native hook只采集applier冻结时的显式测试，启动期自然NPC创建不属于该采集窗口。脚本加载Evidence`ev_cd95af868b62478fa170201298a87e020a2c342151d05d8d055956e4f060bed1`，最终状态Evidence`ev_9b4c3b3decdae411842ec938360f3d3b82a81a7661f8605f5981ee978aa78779`。

[结果](runtime/npc-restore-filter/results.json)与分析器保留了完整文件、原生入口/返回、Bounds、排队、闭包、对象对照。9项测试覆盖固定对象误存、失效标志错配、失效/内部记录误排队、对失效记录执行Bounds、错误Warp、重复回调及清理失败。引擎Error/Fatal0；9份原UserData、4份上一轮隔离自然档、5项冻结原件/副本输入哈希不变。

REA已分离，测试进程正常关闭退出。临时Probe移出plugins，NaturalLoadObserver与NaturalObserver恢复原指纹。完整加密工作档和临时DLL仅留在忽略.cache或独立输出目录，不提交存档明文/游戏DLL。未覆盖Bounds边界面、非法位置、单例失效、延迟队列被中断和自然非空NPC恢复；下一步见[继续入口](runtime/npc-restore-filter/next-run.md)。
