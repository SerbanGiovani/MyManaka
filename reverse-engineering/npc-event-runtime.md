# OnAnimBaretaSound 实测：事件、排队与广播

后续已追踪生产者并追加32次对照：原始回调先切换状态再广播，相等委托注册会去重；尚未发现自然连续停止来源。本篇重复停止用例应继续理解为注入条件下的接收端风险，详见 [生产者与广播链](time-stop-chain.md)。

在原始 Unity 2022.3.62f2 / GameAssembly.dll 上完成 **60 次受控运行测试**：15种条件×站立男女模型×2轮。原生事件命中56次、原生延迟回调56次、测试监听器收到56次广播，逐次NPC身份一致；没有重复事件、重复广播或已入队任务丢失。另4次“事件前重复停止”用例恢复后速度仍为0，观察窗口内没有事件或入队，这是本轮确认的条件性漏发风险。

这是真实 Unity Animator 与原生方法的运行测量，范围是隔离夹具。它没有进入自然玩法场景，不能据此断言自然游戏必然出现重复停止，或所有NPC/Mod环境均无漏发。

## 输入与观测方法

测试副本位于 `E:\ManakaREA-RuntimeFixture`，从 `E:\SecretFlasherManakaREA` 复制游戏、BepInEx核心及interop，仅部署本轮探针。原目录及工作目录插件未部署改动。`GameAssembly.dll`、metadata、data.unity3d、UnityPlayer和两项interop依赖逐份比对SHA-256，见 [manifest](runtime/npc-event-timing/manifest.json)。本轮原生输入仍为 `60030330…62c18d`。

通过原始 `Resources.LoadAll<GameObject>("")` 使资源及依赖驻留，再在 `Resources.FindObjectsOfTypeAll` 中取得 `NpcFemale_Assemble` / `NpcMale`。**NPC来自原始 resources.assets，不是models加密包**。克隆后保留自带Animator、Npc控制器、Receiver、AvatarComponent、MeshParent及动画事件；cullingMode=1、fireEvents=true，不直接调用OnAnimBaretaSound或它的延迟回调。每次重绑后先保持IsFoundStranger=false，约0.25秒后设true，IsSit=false；每例至少观察4.5秒，隐藏远距观察7秒。

原生15404/15405运行实际距离与FPS选择；玩家位置为距NPC约1或60单位，使用默认关卡阈值。15536运行实际速度缓存/停止/恢复。17302/17304/17309运行实际延迟模型与原生Scheduler.Update；没有额外调用InvokeIfNeed推进时钟。原生15350和15358均保留完整实现。

为隔离上下文，探针跳过551个游戏MonoBehaviour生命周期/更新/OnAnimatorMove入口，以及存档写入口；音频分类/取clip/播放入口作替代，音频听感不在验证范围。普通对象以IL2CPP分配并绑定必要字段；组件由Unity克隆或AddComponent创建。完整NpcController.OnUpdate未运行，隐藏时的a%3放行由Driver按同一条件驱动，时间停止期间放行全部帧。首两次FPS入口仍由原生flame守卫处理。此处验证的是该入帧条件下真实动画与通知行为，完整玩法的外层早退及调用顺序仍保留未知。

REA Frida对两个原生入口作只读Interceptor观测，按模块基址加RVA定位：

| 方法 | 原始方法ID | RVA | 记录 |
| --- | --- | --- | --- |
| OnAnimBaretaSound | 15350 | 0x41a730 | Receiver、帧、Time.time、realtime |
| `<OnAnimBaretaSound>b__4_0` | 15358 | 0x41a870 | 同上 |

探针仅在DelayScaledTime入口记录Receiver所属任务入队，并以EventManager.AddListener登记真实FoundStrangerEvent测试监听器，记录FoundNpc身份。它没有在15350/15358入口安装Harmony包装，避免初测发现的Frida入口采集不完整。原生日志和探针日志独立计数，按帧范围与Receiver指针关联。

三个保留的原始REA Evidence记录为：

- 主观察脚本载入：`ev_a39347ad3c4958e1116646ec2f2e8c1b0dd73bd59f3eab977d7af1174a5f725a`。
- 倒计时/顺序观察脚本载入：`ev_7e48c9c495fe64ceadb8e68aadd29659b8c6f8e6224c637587c69a0cf7595823`。
- 完成后状态/352条未截断消息：`ev_4da29e02d08075f58aad823d6eeedfa2594486632bcc5c12e38ef55c89f9260f`。

REA原记录的subject/environment为空、authority=external-service，限制原样保存；manifest以PID44316、实际模块路径及独立文件哈希关联到构建，未把REA原记录改成shipped-artifact。原始选定记录见 [rea-runtime.json](runtime/npc-event-timing/rea-runtime.json)。进程已退出，Frida会话已关闭。

## 隐藏与距离切换

下表时间从IsFoundStranger设true算至**实际原生动画事件入口**，为两轮范围，单位秒。每行每种性别均为一次事件、一次广播。

| 条件 | 女性 | 男性 | 说明 |
| --- | --- | --- | --- |
| 近距 | 0.6670 | 0.3836–0.3838 | 自动Animator |
| 远距60 / 2FPS | 1.2667–1.2668 | 0.7669–0.7670 | 手动评估聚合步长 |
| 隐藏MeshParent且远距 / 三帧放行 | 4.3335–4.3669 | 2.8168–2.8335 | 明显延后，7秒窗口内均完成 |
| 隐藏MeshParent且近距 | 0.6670–0.6672 | 0.3837 | 本夹具中事件仍送达 |
| 事件前近→远 | 1.1334–1.1335 | 0.6335–0.6337 | 参数后约0.13秒切换 |
| 事件前远→近 | 0.8167–0.8170 | 0.5335 | 同上 |
| 每约0.1秒近远反复切换 | 1.3170–1.3171 | 0.7338 | 累计频繁重置，未重复或漏发 |

事件入队后再变远、隐藏MeshParent，也都各广播一次；没有取消或重复排队。这里的“隐藏”明确指实际MeshParent.SetActive(false)，没有关闭NPC根GameObject、销毁Receiver或换控制器。不能将结果扩展到这些操作。

## 实际延迟为什么会是35或36帧

无时间停止时，近距自动动画的事件至广播为36帧，约0.600秒；远距手动评估为35帧，约0.583秒。两者原始任务初值都是float32的0.60000002384，没有更改延迟常量。

第二轮的原生顺序观察直接区分了原因：

| 条件 | 动画事件帧 | 首次扣减帧 | 回调帧 | 扣减次数 |
| --- | ---: | ---: | ---: | ---: |
| r2/female/near | 117532 | 117533 | 117568 | 36 |
| r2/female/far2 | 117839 | 117839 | 117874 | 36 |

近距首步从0.600000024扣到0.583332896，在下一帧发生；远距首步从0.600000024扣到0.583333313，在事件同帧发生。远距该帧的记录顺序为事件入口→Scheduler.Update入口→首个InvokeIfNeed扣减→Scheduler.Update返回。第36次扣减跨到负值时，15358在Scheduler.Update内部运行，测试监听器同帧收到相同NPC的广播。因此**35帧间隔不等于少扣一次，也不构成重复或漏发**。

附加顺序脚本于帧115171载入，覆盖后续用例；没有给此前用例补造首次扣减顺序。自动/手动原生事件入口观察则覆盖全部60次。具体首步帧和覆盖标志已写入 [results.json](runtime/npc-event-timing/results.json)。这是本夹具中Driver与Scheduler的实测顺序，其他场景的MonoBehaviour顺序仍不可直接套用。

## 时间停止与重复通知

正常停止在事件前约0.13秒或事件排队后的下一次Driver更新进入，约1秒后恢复。分别测试近距、远距以及隐藏组合。

- 事件前正常停止：暂停段没有动画事件或广播，恢复速度为1，后续各触发一次。近距女性参数至事件约1.667秒，男性约1.384秒。
- 已入队后停止：暂停段的任务剩余时间保持float32约0.6；暂停段未广播。恢复后只广播一次，事件至回调约1.600–1.617秒（96或97帧）。Unity Time.time在该测试中继续增加；冻结的是游戏IsTimeStop控制的剩余量扣减。
- 隐藏且已入队后停止：同样保留任务、暂停扣减，恢复后广播一次。
- 事件前重复停止：在第一次停止约0.25秒后再次调用原生OnTimeStopEvent，保持IsTimeStop=true。第一次把speed=1存入cache并归零；第二次把speed=0存入cache；恢复后speed仍为0。男女模型各两轮共4次，4.5秒观察窗口内均为0事件、0入队、0广播。
- 已入队后重复停止：同样恢复为speed=0，但四次已入队任务都在恢复后广播一次。通知时钟继续扣减不依赖Animator恢复速度。

最后两项说明“动画进度被冻结而根本未产生事件”和“已经产生的通知被队列丢弃”是不同问题。本轮没有观察到后者。前者由原生15536的重复调用复现；目前只证明**重复停止通知缺少保存原速度的幂等保护**，自然玩法中是否可能重复派发这种通知仍需追踪时间停止事件生产者。

重建时可在首次进入停止态时缓存速度、重复停止时保留缓存；恢复只消费已保存的速度。本轮仅保存分析和夹具，没有修改GameAssembly或游戏插件来修复这一行为。

## 留存、复核与边界

[fixture.jsonl.gz](runtime/npc-event-timing/fixture.jsonl.gz) 留存6,545,543字节原始逐帧数据的无损压缩副本；Unity/BepInEx原日志也完整压缩保留。`analyze.py --check`校验60个用例闭合、事件/入队和回调/监听器逐项计数、NPC身份、暂停段无触发与剩余时间不减、预期重复停止的冻结结果，并比对结果与输入指纹。

最终运行保留一次夹具启动阶段的IntroAnimationController.OnStartFadeOut空引用，以及原始Light缺失脚本警告；日志未删改。首次问题发生在探针等待启动门时，位于测试ready之前；用例阶段未观察到异常。初测的模型来源选择错误、OnAnimatorMove上下文不足和入口包装采集不完整已修正后重跑，未将这些失败运行混入60次结果。

仍未覆盖坐姿两种发现clip、其余七模型、NPC根隐藏/销毁、控制器替换、全局timeScale=0、真正NpcController.OnUpdate全部早退、自然场景的渲染/动画/Scheduler顺序及Mod环境。有限两轮结果不构成这些情况下的无漏发保证。

复查与重新运行步骤见 [夹具说明](runtime/npc-event-timing/README.md)。当前日志验证不需要运行游戏：

```powershell
python reverse-engineering/runtime/npc-event-timing/analyze.py --check
python reverse-engineering/audit.py --inputs
```
