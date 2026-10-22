# 完整玩法验证与输入/技能前置

当前覆盖范围以 [可重算运行结果](runtime/natural-time-stop/results.json) 为准。已完成原始完整启动、真实输入、多个玩法场景和一次NPC动画→延迟回调；已通过正常界面补齐副本的时间停止技能前置。**没有记录到的停止/恢复或暂停倒计时窗口，不算通过。**

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

此前确认的生产者每次反转停止标志、NPC接收器不抵抗重复true的结论保持原有证据等级。本轮没有触发该生产者，未新增任何“自然重发停止”“速度缓存被覆盖”或“自然输入不会重复”的运行结论。

轮盘开启写入的 `InGameManager.InGameReferencer(+0x28).BaseCameraController(+0x38).IsLockCamera(+0x28)` 是相机锁；旁支native0x180477d40读取InputManager.IsGamePad。两者都不能解释为写IsTimeStop。普通暂停由TimeScaleManager.OnUpdate读取OpenPause/OpenTutorial两个模式，设置Time.timeScale和fixedDeltaTime。选定轮盘方法没有直接写时间倍率，但静态直接调用搜索不排除所有间接来源。运行探针同时记录相机锁、倍率和IsTimeStop以区分三者。

## 证据和待完成项

[运行目录](runtime/natural-time-stop/README.md)保留最终Probe/Frida源、准备与采集脚本、原生日志压缩件、未改写REA记录、输入指纹及可重算结果。临时诊断曾错误读取bool返回寄存器的32位；其100条 `input_positive` 全部排除，正式探针只读取AL低8位。早期两次启动属于历史诊断，不能从最终第三版Probe完整重放。

此前写“下游全部0”的早期检查点已由真实玩法数据更新。动画及延迟回调各1次，但它们发生于未停止时；尚不能证明暂停窗口内的冻结/恢复。会话在MCP恢复时导出并重新attach同一PID，历史记录与新记录分开关联，禁止跨attach拼成停止/恢复闭环。

完整通过判定要求同一会话、同组生产者、同一NPC的停止前speed→cache→恢复后speed闭环；还检查相同NPC集合、重复接收、跨停止缓存覆盖和探针错误。回归检查覆盖不同NPC、跨会话及缓存被覆盖为0时不得误通过。`delay_pause_window_exercised` 单独标识是否实际覆盖队列冻结，不能由普通0.6秒回调推出。

技能17已通过正常UI启用；仍需进入有NPC的场景，实际执行轮盘直接调用/快捷调用的停止与恢复，再分别覆盖近/远、隐藏、发现动画事件前后停止及恢复。必须按输入帧、生产者调用ID、NPC缓存/速度、动画事件和Scheduler通知关联，才能判断漏发/重复；现有最小夹具矩阵不能代替这些自然玩法数据。
