# 完整玩法验证与输入/技能前置

后续已补齐本篇遗留情景的有限验证：自然16次事件/16次回调，另有用户授权的12条受控入队通知和五情景覆盖；天然事件生成与受控队列交付仍分开。详见 [排队、隐藏及距离切换报告](notification-scenarios.md)。本篇及其检查点保留当时的覆盖边界。

当前覆盖范围以 [可重算运行结果](runtime/natural-time-stop/results.json) 为准。已完成原始完整启动、真实输入、多个玩法场景、4组自然停止/恢复和2次NPC动画→延迟回调。4组缓存闭环均得到验证，其中前三组结合定时快照，第四组在原始生产者返回时读取。**通知队列暂停窗口、MeshParent隐藏和距离阈值切换仍未覆盖，不算通过。**

## 实际运行

独立目录 `E:\ManakaREA-NaturalGameplay` 仅加载本轮观察插件，保留原始 Title、密文资源加载、25请求、场景/玩家初始化及每帧输入。GameAssembly、metadata、data.unity3d、UnityPlayer和原始加密models的副本哈希全部匹配。未跳过bootstrap、强制技能/Animator/NPC状态、修改IsTimeStop或直接调用生产者/广播。

Application getter和SaveRapper路径被限于副本UserData；输入重绑定的保存入口被抑制。新REA11773确认ES3绝对路径直接返回；17371证明原生重绑定读取可绕过托管getter，因此不能仅凭该getter声称全局IO保护。源LocalLow的8个保存/绑定文件再次计算哈希，均未变化；这些文件的内容与游戏画面不提交。

真实鼠标操作经过“继续→已有存档”，进入Apartment：

- 槽0先出现 `PartsRecords ... id:8 records.Length:8` 异常，随后大量空引用。一次原生栈为 PlayerLocomotion.OnFixedUpdate(14900) → EventMethodManager.FixedUpdate(16736)。不能据此把时间停止缓存风险确认为自然故障；部件越界与后续空引用的直接因果仍待证。进程随后退出，未捕获可靠退出码/崩溃归因。
- 槽1完成玩家初始化，没有上述初始化异常。随后直接读取 `GetSkillLevel(17)=0`、`IsActivePassiveSkill(17)=false`，技能界面也显示1000RP“习得”。通过真实鼠标点击该按钮后，RP从54543变为53543，原生等级变为1且启用=true。该变更仅在测试副本，未直接写技能状态。此前用户确认的已解锁状态与这个被复制/载入的槽位存在差异，不能将此前两次轮盘分配记录视作技能生效证据。
- 原始InputResolver持续逐帧执行。自动Tab/2未产生有效输入；手动Tab和2均被Keyboard及原始InputAction捕获，其中2曾连续保持300帧。Tab打开时轮盘无响应是正常设置：`InGameUiManager.IsOpenSomeCancelInputUi(+0x21)` 让18146跳过长按开启分支。关闭Tab后捕获到两次真实轮盘开启/快捷项分配。不能把这个菜单门控判作游戏键盘故障。

真实玩法还经过Night_Demo 1及Fashion_shop。Fashion_shop中一次原生OnAnimBaretaSound发生于frame53192，延迟回调为frame53227，相隔35帧、约0.61096秒；最近的同NPC快照显示display=true、Animator.enabled=true、speed约0.964601、cache=1。该快照是事件后25帧采样，不是动画事件瞬间的精确FPS/距离证据。

Windows窗口截图多次超时。窗口可访问树、Unity只读UI文本/画面读回及REA用于确认状态，输入仍通过computer-use/sky发送。先前一次按旧分辨率点击未命中；切换到2560×1440并按读回位置点击后，实际打开存档面板。

## 新补的静态环菜单链

24次新REA查询及38个方法绑定见 [natural-chain.json](salt/evidence/natural-chain.json)，包含输入、路径、选择、普通暂停和技能执行的明确区别：

```text
长按 SkillRingMenu(InputType23，默认2/dpad左)
  → RingMenuParentView.LateUpdate(18146)
  → GetLongDown → OpenRingMenu(18149)
  → RingMenuView.AngleUpdate(18203)：CameraMove输入选择方向
  → 两种后续
      松开/选择：18181/18182更新lastInvokeModel及保存的快捷索引
      鼠标左键 Select(InputType15)：ShowUpdate(18202)直接执行
        当前页匹配 + currentSelectView.Model存在 + IsRelease
        → OnSelect为空：RingShortcutInput = Model.RingItemType(+0x14)
        → 否则调用OnSelect
        → parent.IsClickToAction(+0xe0)=true

之后短按对应快捷键：LateUpdate.GetShortUp
  → 选定lastInvokeModel → RingShortcutInput或OnSelect
  → 原始InputResolver → PlayerAction门 → TransAction
  → Player原片段OnChangeTimeStop → 标志反转 → 广播 → NPC接收
```

18181/18182只证明快捷项分配，不能当作命令已经执行。运行探针的历史标签 `ring_command_0/1` 应按此理解。鼠标左键才是这里的Select15；F是另外的交互键，不能由画面提示混同。

此前确认的生产者每次反转停止标志、NPC接收器不抵抗重复true的静态结论，本轮由自然输入进一步限定：8次实际调用严格交替停止与恢复，未出现连续true广播或同次广播对同NPC重复投递。该结论只覆盖已记录调用，不是全局不可重入证明。

轮盘开启写入的 `InGameManager.InGameReferencer(+0x28).BaseCameraController(+0x38).IsLockCamera(+0x28)` 是相机锁；旁支native0x180477d40读取InputManager.IsGamePad。两者都不能解释为写IsTimeStop。普通暂停由TimeScaleManager.OnUpdate读取OpenPause/OpenTutorial两个模式，设置Time.timeScale和fixedDeltaTime。选定轮盘方法没有直接写时间倍率，但静态直接调用搜索不排除所有间接来源。运行探针同时记录相机锁、倍率和IsTimeStop以区分三者。

## 证据和待完成项

[运行目录](runtime/natural-time-stop/README.md)保留最终Probe/Frida源、准备与采集脚本、原生日志压缩件、未改写REA记录、输入指纹及可重算结果。临时诊断曾错误读取bool返回寄存器的32位；其100条 `input_positive` 全部排除，正式探针只读取AL低8位。早期两次启动属于历史诊断，不能从最终第三版Probe完整重放。

此前写“下游全部0”的早期检查点已由真实玩法数据更新。会话在MCP恢复时导出并重新attach同一PID，历史记录与新记录分开关联，禁止跨attach拼成停止/恢复闭环。

## 真实停止、恢复与发现动画

用户关闭Tab后在StationFront长按2开启技能轮盘，frame489980分配 `RingItemType=10 / m_skill_time_stop`，随后短按快捷键执行。8次InputResolver时间停止输入均进入ChangeAction(7)，再过34帧由OnChangeTimeStop反转标志；实际缩放时间差约0.56641–0.56738秒，与原片段事件约0.56667秒一致。轮盘相机锁与技能停止分开观察，时间倍率保持1。

| 组 | 停止帧→恢复帧 | 停止间隔（实时时间） | 同组NPC数 | 缓存与速度验证 |
| --- | --- | --- | --- | --- |
| 1 | 490112→490521 | 6.89355秒 | 42 | 原生接收入口＋随后定时快照 |
| 2 | 490792→491552 | 12.68164秒 | 44 | 原生接收入口＋随后定时快照 |
| 3 | 491788→492095 | 5.11719秒 | 45 | 原生接收入口＋随后定时快照 |
| 4 | 504164→504460 | 4.93555秒 | 45 | 原生接收入口＋同帧原生产者返回 |

共352次NPC接收入口（每组NPC数×停止/恢复），每次广播内无重复NPC。近距离样本60次、远距离292次，以控制器最后采样距离20为界；全部display=true。这证明近/远NPC均收到通知，不能证明隐藏模型或单个NPC跨距离阈值的精确切换。

前三组262次接收器入口均缺少Frida onLeave，原始REA记录无截断且无脚本错误。不能把缺少退出回调解释为游戏异常：恢复入口已读到speed=0、cache等于停止入口原速；随后第一份同标志快照（26–59帧滞后）补齐停止归零和恢复原速。分析器明确标注 `periodic-snapshot`，不伪造接收器退出记录。

第四组加载新增只读 `post-broadcast.js`，在每个NPC入口读取before，在原OnChangeTimeStop返回时读取after，不依赖NPC退出钩子。45个NPC的90份前后状态全部符合：停止时cache=原speed且speed=0，恢复时cache保持、speed=原speed。该组包含18份近距离、72份远距离记录。定时快照中另有一个恢复后的NPC未找到，标为unknown；同帧生产者返回记录已经覆盖它，不能用缺失快照误判缓存故障。

原始15536机器码的普通出口是RET@0x18042a96f；仅首次解析粒子暂停的旁支有尾跳@0x18042abaf，不能解释全部停止、恢复退出钩子缺失。最终Probe只补保存路径，没有给NPC函数打Harmony补丁；退出观测缺口的原因仍未确定。

用户再触发发现反应后，frame504589捕获OnAnimBaretaSound和关联DelayTimeModel（delay/remain约0.600000024、unscaled=false），frame504625执行原延迟回调。相隔36帧、约0.59961缩放秒；到期前剩余0.016654秒，随后减为约-0.00001345。连同此前商店样本，共2次事件、2次配对回调，未发现已记录事件的漏发或重复回调。

该发现事件发生在最后恢复后129帧、约2.17285秒，队列创建/到期期间stop=0。没有正剩余时间处于停止状态的样本，故不能声称自然玩法的队列冻结/恢复已验证。事件先于停止或停止期间隐藏的漏发条件仍未知。

缓存闭环要求同一会话、同组生产者、同一NPC的停止前speed→cache→恢复后speed；还检查相同NPC集合、重复接收、跨停止缓存覆盖和探针错误。回归检查覆盖不同NPC、跨会话、缓存覆盖为0、缺失NPC和跨下一次广播的采样。组合直接返回读取与定时快照后，`bounded_stop_restore_complete=true`；完整情景的 `natural_validation_complete=false`，未知项不会自动通过。`delay_pause_window_exercised=false` 单独标识队列冻结未覆盖，不能由普通0.6秒回调推出。

本次已完成自然快捷调用、停止/恢复缓存闭环与恢复后的发现通知。剩余为通知正处于0.6秒队列时停止、MeshParent隐藏及同一NPC跨距离阈值的组合场景；轮盘左键直接执行分支本轮仍只有静态证据。现有最小夹具矩阵不替代这些自然玩法数据。最终采集后已卸载REA会话，游戏进程没有被关闭；manifest的state是最后保留状态，closed_by_operator另记实际detach。
