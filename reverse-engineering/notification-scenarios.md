# 排队通知、模型隐藏与距离切换

2026-10-22，继续使用REA观察完整启动的独立副本 `E:\ManakaREA-NaturalGameplay`。原始GameAssembly、metadata、UnityPlayer、data.unity3d、密文models及观察插件指纹均复核；源LocalLow的8个保存/绑定文件未变化。沿用分支 `codex/rea-salt`。本轮没有改游戏二进制或原始存档。

结论分两层：**16次自然动画入口均有一次延迟回调；另12条受控入队通知均有一次回调和相应广播入口，未发现所测队列丢失或额外交付。** 用户明确同意精确受控验证后，才进行临时位置、MeshParent显隐与原始生产者调用。受控通知入口是直接调用OnAnimBaretaSound，不能作为Unity实际生成AnimationEvent的次数。

可重算结果见 [results.json](runtime/natural-notification/results.json)，原始REA记录、源哈希、异常诊断与三次attach边界见 [运行目录](runtime/natural-notification/README.md)。前一轮检查点保持原样。

## 自然观察

正常UI启用被动技能21后，原生查询确认技能17/21启用、22未启用。之前一次OnChangeTimeStop在发现过程中未反转标志、未投递NPC通知；与14479中“IsMaxStrangeSomeOne且21/22均未启用就返回”的守卫一致，不能当作队列漏发。

真实游玩经过StationFront、自宅、白天Mall：记录16次原生OnAnimBaretaSound、16次关联DelayTimeModel创建、16次原延迟回调与队列移除。实时时间差约0.58789–0.61914秒；其中3条通知的采样处于手动Animator模式。自然队列采样内没有暂停、MeshParent隐藏或近远跨界，因此这些16条不能证明那些组合情景无故障。

独立于通知队列，还记录到245次MeshParent层级激活状态变化、835次手动模式变化；191次相邻状态记录同时跨过10/20距离边界并改变手动模式。这里是已记录状态变化，不是191次通知穿越边界。观察器最多保存2500条actor状态变化，不能把未记录到的变化当成不存在。距离来自双方GameObject的真实世界坐标，不使用可能停留在旧值的NpcController.PlayerDistance。

## 精确受控验证

完整游戏bootstrap、NPC工厂、Scheduler和监听器保留运行。控制器对现场NPC调用原始OnAnimBaretaSound，使原代码创建0.6秒scaled通知，再约0.06秒后安排条件：

| 条件 | 原矩阵次数 | 达到计划条件且通知闭环 | 补测 |
| --- | --- | --- | --- |
| 排队后时间停止，约2.8秒后恢复 | 2 | 2 | 无 |
| 排队后隐藏MeshParent | 2 | 2 | 无 |
| 排队后远移，再移回近处 | 2 | 2 | 无 |
| 排队后隐藏并保持远处 | 2 | 2 | 无 |
| 排队后隐藏、远移并时间停止 | 2 | 1 | 增加2条，均达到条件并送达 |

原矩阵第10组的预定远距离没有保持：实际采样回到约1单位，故保留为条件未满足；该条通知本身仍正常送达。补测在InputResolver和原FPS入口保持远处位置，直接读回距离、manual、FPS、实际手动Update步长及隐藏状态。**12条正式通知全部满足交付数量约束，11条达到其完整计划条件，五种情景均有正向覆盖。**

控制器结束时恢复其改变的人物位置、显隐与停止状态。12条正式记录的即时位置误差均为0、停止标志均恢复false；明确隐藏的模型均恢复原activeSelf。两条远近测试在结束时的自然显隐与起点不同，它们没有留下控制器强制隐藏标志，原生剔除继续决定显隐。这里不宣称这些临时操作没有影响完整游戏的其他自然状态。

## 暂停与同帧广播

队列模型只有仍在Scheduler.timeModelList时才读裸指针；移除后停止读取。以相邻帧、队列成员仍在、剩余时间为正的样本比较，正式记录有759个模型相邻帧比较，剩余时间变化违例0；同帧多模型会分别计数。其中428次timeScale=1，可独立支持IsTimeStop冻结scaled通知；331次同时timeScale=0，单独分类，不用于隔离归因。

补测两条通知进入同一普通暂停窗口：remain约0.600000024、Time.time不动；frame618934恢复倍率，frame618953两模型同帧到期。两个callback入口、两个身份匹配的PlayerController.OnFoundStrangerEvent入口、两模型随后移出队列，构成**2模型→2回调→2广播监听入口**的组级闭环。墙钟间隔分别约8.529/5.109秒，缩放时间均约0.621秒。它们不是两次独立的完整时钟实验，也不是一次通知重复广播。

已排队的控制组在隐藏/远档下仍送达；没有发现已测正剩余通知被清除、暂停时提前广播或恢复后额外广播。不能由此保证任意场景、NPC销毁、重入、Mod、Animator过渡或事件产生之前隐藏都无漏发。

## 原生显隐来源与ABI

新增10次REA查询并绑定24个方法，见 [notification-chain.json](salt/evidence/notification-chain.json)。批次成功完成且关闭。

- ObjectCullCollider只在触发器对象等于BaseCameraController.gameObject时改变IsInArea；ObjectCuller将子区域状态做OR，再结合NpcCullArea中的NPC成员关系判断剔除。这不是仅按摄像机朝向或墙体遮挡判定。
- NpcController约每0.5非缩放秒刷新isDisplay。白天ShoppingMall另有玩家缓存位置与NPC当前位置距离≥40就隐藏的分支；Pinpon固定NPC还有专门覆盖。实际模型状态仍以MeshParent.activeInHierarchy为准。
- 时间停止路径绕过普通隐藏三帧门。默认近档20、商场近档10；远档且MeshParent不激活时强制2 FPS。手动Update实参从原始call前的CommonFPS.skippedTime读取。
- DelayTimeModel暂停门在InvokeIfNeed内部；已保存Scheduler.Update没有整体IsTimeStop早退。冻结证据来自独立心跳的队列成员与剩余时间，不依赖原生onLeave是否回调。
- 14765@0x180645a60接收的是NpcController引用，参数名foundNpc；FoundStrangerEvent本身是继承GameEvent的class。旧监听探针误读a[1]+0x10，仅保留唯一帧时间关联；新版直接读取a[1]，payload里的“value-type”文字是旧误标，未作为ABI依据。补测的NPC身份与队列actor匹配。同帧多模型按数量及NPC分组关联，不强行指定组内单条对应。

监听入口到达后，技能21会让玩家处理函数提前返回。广播送达不等于发现惩罚、声音或后续玩法副作用全部执行。

保留的诊断包括：过短指令位置无法挂钩，换到有效指令起点；Frida bool实参需要整数，预检隐藏步骤失败后已恢复并卸载。预检不计入正式矩阵。原函数由NativeFunction直接调用时，入口Interceptor未形成可用记录，因此受控模型由实际队列扫描发现，起点比显式调用晚一帧左右；约0.55秒的扫描后间隔不能误称为原0.6秒延迟缩短。

12项关联/冻结回归测试覆盖重复、缺失、同帧批量送达和未知采样。所有REA attach均已detach，测试游戏没有被关闭。以上是本构建、本次窗口的有限验证，不是重建游戏已独立运行的证明。

后续已把观察前移到动画参数写入和来源状态，补充真实Unity事件的隐藏/近远精确测试，见[事件生成与取消报告](event-generation.md)。该轮仍保留自然前置条件未命中、错误0事件预期和模型回收的边界，不能用本页排队后结果替代。
