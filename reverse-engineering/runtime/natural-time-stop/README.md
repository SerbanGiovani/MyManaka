# 完整启动与自然停止/恢复记录

原始Title、资源解密/25请求、存档选择、Apartment、玩家创建和输入循环实际执行。已观察4组自然轮盘快捷停止/恢复、8次生产者和352次NPC接收，缓存闭环验证通过；2次NPC动画均有配对延迟回调。**队列中途暂停、隐藏和距离阈值切换仍未知，完整情景标志保持false。**

测试目录 `E:\ManakaREA-NaturalGameplay`，只部署 `NaturalObserver.dll`，无原日常插件。原始 GameAssembly、metadata、data.unity3d、UnityPlayer、加密 models 文件逐份匹配。未设置 Animator 参数、技能启用值、全局停止标志、NPC状态或调用生产者/广播。

`Probe.cs` 的执行改动限于：

- Application.persistentDataPath 托管入口改为副本 UserData；SaveRapper 两个路径方法的结果改为该目录下的绝对路径。
- 输入重绑定 Save 被抑制，因为其原生实现可内联绕过已挂钩的 Application getter。不会改变读取到的绑定或动作状态。它也意味着本探针不测试“保存重绑定”。
- 增加只读观察组件和异常日志栈设置；按副本内 inspect 标记可读属性/UI文本、生成 Unity 自身画面读回。窗口工具截图失败时以此确认布局；画面文件不发布到仓库。

SaveRapper 绝对路径由新 REA `ES3Settings.get_FullPath` 验证。完整运行期间源 LocalLow 的8个保存/绑定文件均再次校验，未变化。getter 挂钩本身不构成任意未知IO的全局保护。

真实鼠标完成“继续→已有槽位”，后续用户的真实键盘进入街道/商店并开启轮盘。自动Tab/2未产生输入；手动按键有效。Tab打开时2被正常UI门控拦住，不能将其解释成游戏输入缺陷。副本技能17最初原生等级0，后经正常鼠标“习得”花费1000RP，变为等级1/启用；之后在StationFront捕获4组真实切换。

`observe.js` 只挂原始生产者、NPC接收器、动画事件、延迟回调和输入/轮盘函数，额外读取原生 Animator.speed。历史标签 `ring_command_0/1` 实际对应18181/18182的快捷项分配，不能计作执行。`input-state.js` 只读Keyboard、InputAction及原始bool返回，使用AL低8位。

`observe-v2.js` 保留这些钩子并修正路径比较的分隔符和目录边界。`runtime-state.js` 同步记录相机锁、普通倍率、技能/轮盘门控，按原生OnAnimBaretaSound栈关联DelayTimeModel创建及倒计时。`npc-state.js` 精确记录接收前后cache/speed、控制器距离样本和display字段；display=false不等于已证明MeshParent被隐藏。`ui-readback.js`避开早期Probe对已销毁selectedGameObject.name的读取异常，只读活动UI文本与Unity画面，画面不提交。

实际NPC onLeave没有回调，故 `npc-state.js` 仅保留入口，不把计划中的退出当成观测。前三组42/44/45个NPC用入口与26–59帧后的定时快照验证；新增 `post-broadcast.js` 在第四组原始生产者返回时读取45个NPC，90份状态直接确认停止归零及恢复原速。分析器分别标注 `npc-callback-exit`、`outer-producer-return`、`periodic-snapshot`，不混淆精度。第一种本次0份，第二种90份；352份第三种中1份NPC缺失，组合时由第二种记录覆盖。

新增发现事件frame504589，DelayTimeModel约0.6秒且使用缩放时间；frame504625到期回调。发生在恢复后129帧，不是暂停队列测试。总计2次事件/2次回调，队列暂停窗口仍未覆盖。退出钩子缺失原因未知，不能归因为游戏异常。

一个早期临时诊断错误地把整个32位返回寄存器当bool，产生100条 `input_positive`。它们被明确排除；只有 `input_true_bool8` 才可用于输入结论。inline临时诊断不是可复现正式探针，最终文件版本另行加载并记录源哈希。

重建副本：使用 PowerShell7 执行 prepare.ps1，显式提供新的 GameRoot 和只读复制来源 SourceSaveRoot。准备脚本不得覆盖已有目录。它使用原始密文包，未加载上一轮手工解密的 models 文件。

运行/后续步骤：正常启动副本，REA attach后加载observe-v2.js、input-state.js、runtime-state.js、npc-state.js及post-broadcast.js；ui-readback.js按需单次加载。分别记录剩余的队列暂停、MeshParent隐藏、距离阈值切换组合，不允许强制状态替代自然玩法。每次结果按输入帧、生产者ID、NPC缓存/速度、动画事件和Scheduler通知关联。9项回归测试防止缺失捕获、不同NPC、跨会话或采样跨下一次广播被误判为通过。最后采集后已detach，游戏没有被关闭。
