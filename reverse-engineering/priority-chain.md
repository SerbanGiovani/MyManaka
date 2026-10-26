# 六组关键方法：按重要性补齐

本轮按状态记录、NPC移动/转身、相机、保存恢复、任务、具体交互的顺序查询原始构建。核心清单165个方法声明去除6个重复原生地址后为159次REA/Ghidra查询；再补12个下层入口，共**171次非空原生查询、171个不同地址和Evidence ID**。复用19条旧观察，绑定391个metadata usage、130个类型的注册字段布局，并保留36个任务类型的静态vtable。两个REA会话均导出后关闭。

可重算绑定位于 `salt/evidence/priority-chain.json`；原始函数体在 `salt/evidence/priority-core/`、`priority-tail/`。这些是固定构建的静态方法证据，本轮没有执行游戏或生成替代GameAssembly。

## 1. GameStateApplier：实际是状态快照写回

`OnLateUpdate`（16744，RVA `0x48d5d0`）首先检查 `TemporaryInGameState.IsStopGameStateApplier +0x10`。普通调用在 `unscaledTime-lastApplyTime<1.0` 时返回；通过后更新lastApplyTime，读取玩家Transform，把位置写入 `GameStateData.PlayerPosition +0x180`，把旋转写入 `PlayerRotation +0x18c`，再调用 `NpcManager.ApplyGameState`（15598）。

`UpdateIgnoreWaitTime`（16745）只是传入force=true调用同一函数。它绕过1秒限频，仍受停止快照标志守卫。这个类不能被误实现为“把全部存档字段应用到角色外观和玩法”的统一入口；选定代码的主要方向是**运行对象→游戏状态数据**。

下层15598检查 `NpcManager.isLoadedData +0x65`，按活动NPC/固定NPC数量调整 `GameStateData` 的NPC保存列表；对选定普通NPC记录写激活标志、位置和旋转，余项可标记无效。它包含固定类型过滤与索引调整，不能简化成无条件保存全部NPC。

核心证据：16744 `ev_1bc841677e732f8c26c782bea6eb01ef36605bced2b97dd3f3f8f45b4b057ecc`；16745 `ev_7260c99445aede4f78dc91d67634c5d908a3a4e95ef87f710502ab53c8084703`。15598及其字段坐标见机器绑定。

## 2. NPC移动、转身及导航恢复

已补15553–15559及15685–15687，另读 `NpcCollisionCorrecter.CollisionCorrect`（15444）、`NpcManager.GetNearOtherNpc`（15596）与原生旋转辅助 `0x1804363f0`。

`NpcLocomotion.OnEnter` 重置上次目的地，再调用 `SetActiveNavAgent(true)`。后者把导航代理Warp到当前角色位置并恢复相关导航开关。`OnUpdate` 处理目标朝向、路径点/邻近NPC及目的地更新；主体可见0.1缩放秒的刷新守卫和随机偏移。`SimpleUpdateFromOtherState` 是供其他状态使用的另一入口，不能直接等同普通移动。

`OnFixedUpdate`（15557）将 `moveV × fixedDeltaTime × (skipFixedUpdateFrame+1)` 加到Transform.position，清除跳帧计数，再按玩家/邻近NPC的距离与胶囊半径条件调用碰撞修正。导航代理在此链中也有SetDestination、nextPosition及Warp同步，不能仅交给NavMeshAgent自动推进Transform。

补充原始指令核验发现：Stage数值11的距离守卫**先判断>20，成立后直接比较跳帧计数2**；只有不满足它才比较30。对有限正常距离，后面的“>30、计数4”分支被前面的条件遮住。原始 `COMISS/JA/JBE` 顺序、20/30的float32字节和50条指令保存在 `salt/symbols/priority-instructions.json`，范围仅RVA `0x42e660..0x42e740`。不能按看似合理的20/30三档重新排列原逻辑，也没有由静态代码推断实际帧率。

`NpcTurnAroundState.OnEnter`（15685）清移动量、覆盖Idle、停用导航，并保存进入时玩家位置。`OnUpdate`（15686）根据隐身/指定转身点等条件选择目标，进行朝向插值与LookAt处理；约 `Time.time-stateInTime >=2.8` 后，按BeforeState恢复数值5、6或0，随后把 `IgnorePlayerNoisyTime` 写为10。`OnExit`（15687）撤销Idle覆盖并清理指定转身点；回到普通移动时，由Locomotion.OnEnter恢复导航。

这补齐了之前发现→噪声转身后缺少的原生恢复链。自然玩法中事件前触发该转身的资格仍按[自然噪声报告](noise-return.md)保留边界，本轮没有新增自然取消样本。

## 3. 相机：输入、模式选择与碰撞距离

已补Base、TP、FP三组23个入口，再补Inventory相机初始化/更新、`GameStateFacade.GetCameraMoveX/Y`、滚轮缩放及Unity `PhysicsScene.SphereCast`。

- `BaseCameraController.OnLateUpdate`（15920）按玩家状态、Strafe和Inventory相机选择来源Transform，将位置/旋转写到实际相机；模式变化还影响FOV、剔除层和第三人称重置。
- `TPCameraController.OnLateUpdate`（15966）使用输入、选项缩放、光标锁及按键守卫更新Yaw/Pitch与距离，再调用15967。`CalcCameraDistance`按当前角度构造后向方向，使用半径float32 `0.05` 的SphereCast，掩码为配置ignoreLayerMask的按位取反，返回命中距离与cameraMaxDistance中较小值；未命中时取配置最大距离。相关原始枚举实参保留为1，未靠名称猜测碰撞体选择。
- `FPCameraController.OnLateUpdate`（15944）更新Yaw，Pitch夹在[-60,60]，并结合角色身体、颈部及移动相关偏移更新第一人称目标。`GetCameraMoveX/Y`区分鼠标/手柄、反向与灵敏度选项，不能把两种设备都简化成裸mouse delta。

代表证据：Base更新 `ev_45a1d3201d1b1ec50fefd48f2111f0e7bf260255512bb5d275e6d40d2ff67a66`；TP碰撞距离 `ev_f4a84c54965dd7e464e78f2543e9e1989eb0c4858511516dc2ff85fc376f5948`。姿态/遮挡/镜头手感及各MonoBehaviour实际顺序仍需运行对照。

## 4. 存档：写入主链与选定类型恢复

新增 `SaveManager.SaveSystem/Save`（16968/16970）、`SaveRapper.AfterProcess/Copy`、6个具名Save重载、5个此前缺失的Load重载，并查询共享泛型写入辅助 `0x1809ff300`；读取主链仍连接旧16969/16971。

`Save`先调用SaveSystem；分类4在系统保存后返回，分类3使用当前槽。分类1在选定路径中先把自动保存1复制到2，再把0复制到1。进入游戏状态写入前，它还把 `PlayerEcstasy +0x168` 上限压到0.99，并从当前玩家状态更新 `PlayerCurrentClothes +0x19c`。这是保存函数的实际内存副作用，不能当作纯文件拷贝。

系统键包括 `AutoSaveTime`、`ManualSaveTime`、`InterruptSaveTime`、`HomeSaveTime`、`RankData`、`OptionData`、`TutorialData`、`TotalPlayTimeData`、`DifficultData`；游戏写入键为 `SaveDataSlotIndex`、`GameStateData`、`IsTrial`、`PlayerCustomData`。每个原始字符串usage与所属方法保存在 `save_key_literals`，键出现本身不代表每次分类都无条件写入它。

共享辅助创建ES3Settings并使用SaveRapper当前路径，location=4分支进入ES3File缓存，其他分支创建流和ES3Writer并执行写入/收尾。AfterProcess清IsBackup标志。泛型methodSpec与选定重载的参数/默认值已绑定；全部反射对象schema、ES3泛型嵌套类型、迁移和崩溃中断后的恢复仍未穷尽，没有对用户存档进行写入实验。

Save证据：`ev_d9aa9268a111316ce0a28f1d8eb90bec3d6231b8ad0dc2e24414836e72e30374`；共享辅助 `ev_1ceff35a36115d5651c416423a4de4430807e197f597fdb6bcb834088733c762`。

## 5. 任务：从更新到具体条件和奖励提交

核心清单包含88个任务相关声明，6处与已有选定地址共享。除Manager/Base和随机任务管理器外，**34个具体任务类的IsInCondition均有独立查询**；36个任务类型的vtable原始槽位及目标定义另行保存，避免把抽象基类入口误当成全部条件实现。

`MissionManager.OnLateUpdate`（16562）遍历MissionList，调用MissionBase.Update。`IsSuccessMission`（16560）查找对应RMission，判断satisfy是否>=1；未找到返回false，不是只检查某个全局完成标志。ResetMission、Dispose及构造也已补齐。

`MissionBase.Update`（16491）包含GameOver、场景切换、停止、等级、随机任务互斥等守卫，随后调用具体类的条件/增量/每秒奖励虚方法。它维护并夹限satisfy，处理一次完成标志与持续奖励、记录字典和声效。`RiseRp`（16492）进入 `GameStateFacade.RiseEarnRp`（16761），后者把float奖励转换为double，加到 `CurrentEarnThisTimeRp +0x1f0` 与 `StatistisTotalEarnRp +0x138`；随后按任务ID累计统计。

随机任务OnUpdate读取当前任务的一次完成标志，推进步骤索引，更新保存记录和进度比例，并经一帧延迟安排结束。具体任务条件、计数/距离增量及Reset的共享地址均绑定至原始metadata；实际任务表数值、全部奖励浮点实参ABI和自然完成/失败组合仍未逐项运行对照。

核心证据：成功判定 `ev_90480b41a5afb97fd591fb2140103a9dab9a09375a75f8653899ada99461ef5b`；遍历更新 `ev_6749db51ebbc8bfc603abaca8c7cc00c9e52261c2c065d603ea5f042d344ef9b`；RP累计 `ev_3e32b64f89bcd52aad2873d33d5b9feca29f13b693a87139018ea50120d39781`。

## 6. 通用交互之后：门与洗衣机

`CommonDoorController`已补Awake、OnInteract、CanInteract、OpenClose及四个委托。注册的菜单动作分别执行开关门和上锁；交互受动画播放、手部/动作及门前后位置条件约束。OpenClose翻转IsCurrentOpen、设置动画参数并标记播放中；开门关闭指定门碰撞体，关门则经配置延迟恢复碰撞，声音另按开/关配置延迟播放。`OnEndDoorAnim`清播放标志。没有把函数存在当成已经验证实际clip接线。

`WasherMachineController`已补Start/Destroy、OnInteract、StartWash、Update、TakeClothes、OnAnimEndTake、时间变化、NPC占用和时间停止处理。菜单三项委托分别调用StartWash(1/3/5)，代码分别检查玩家/NPC使用、衣着/等级、动作和手部条件。StartWash可写玩家TransAction=10009并设置投放目标；TakeClothes的玩家路径写10010；OnAnimEndTake把状态清为0并清玩家/NPC占用标志。

洗衣机Update在技能时间停止时提前返回；停止事件还暂停声音、缓存并归零Animator速度，恢复时读缓存恢复并UnPause。这个接收器与NPC缓存相似，但本轮没有运行重复停止对照，不能套用NPC实测计数。动画事件的资源绑定、其他交互种类和通用UI嵌套路径仍是后续覆盖。

## 复核与剩余工作

```powershell
python reverse-engineering/salt/priority_evidence.py --check
python reverse-engineering/audit.py --inputs
```

六组本轮选定的关键方法体、字段和下层连接均已补充。剩余重点转为：完整ES3对象schema与往返测试、任务配置数值及实际完成/失败、相机/碰撞与导航的运行等价性、门/洗衣机动画资源接线，以及其他NPC子状态和交互消费者。`unknowns.json`更新当前状态；本轮没有把保存的静态函数体等同于可独立编译运行的实现。
