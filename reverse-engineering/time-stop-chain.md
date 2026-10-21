# 时间停止生产者、广播与速度缓存覆盖条件

**在已确认的原始自然调用链中，没有找到连续派发两次“停止”的路径。** 原始玩家动画回调每次先反转IsTimeStop再广播；同一NPC相等委托的重复注册会被拒绝。新32次受控测试中，24次原生产者路径没有覆盖速度缓存，8次注入对照才复现缓存归零及动画事件未产生。因此上轮发现应定位为“接收端不抵抗重复停止”的条件性风险，尚不能称为已证实的自然玩法故障。

本轮新增16次REA原生查询，复用8个观察，另对原始PE的139,898个RUNTIME_FUNCTION片段作Iced候选扫描，共8,534,275条指令。原生、metadata和资源仍绑定同一构建。静态汇总为 [time-stop-chain.json](salt/evidence/time-stop-chain.json)，运行结果为 [results.json](runtime/time-stop-producer/results.json)。

## 1. 自然入口到动画事件

已证调用链：

```text
环菜单/快捷项 TimeStop(10)
  → InputResolver.Resolve(14421): RingShortcutInput → JustTimeStop(+0x36)，消费后清快捷项
  → PlayerAction.OnUpdate(14462)
      当前Action.Id != 7、CanUseHand通过、TimeStop技能17启用
  → ChangeAction(14463, ActionType7)
  → PlayerAnimationManager.TransAction(14536)
      写ActionId，设置TransAction触发器
  → Player控制器 layer7 / OverrideRightArmHand.SwitchTimeStop
  → clip事件 OnChangeTimeStop @ 0.566666663秒
  → PlayerAnimationReceiver.OnChangeTimeStop(14479)
```

原始输入配置没有独立TimeStop输入动作；T键属于SlowSkill，不能将其当作时间停止键。环菜单具体槽位与玩家重绑定仍由配置决定。输入门会拒绝当前Action.Id已为7时再次选择这一动作；ChangeAction另有同帧更新门。控制器AnyState允许自过渡，并不能单独证明自然输入会重入。

原始Player控制器machine7/state6的入口要求TransAction和ActionId=7，过渡0.25秒、无exit-time等待；片段不循环，出边exitTime=0.75、过渡0.25秒。原始models容器的可加载入口是 `assets/zzz-externalencryptasset/manustia.prefab`，其同根Animator使用Player控制器并自带PlayerAnimationReceiver。实测读取到片段长1秒及三事件：OnPlaySe约0.433333、OnChangeTimeStop约0.566667、CommonOnEndAnim约0.983333。

资源图、片段表和独立原metadata枚举值均随静态汇总保留依赖指纹。运行时确实从该key加载并使用原Animator/Receiver；没有猜测一个名为Player的独立LoadAsset路径。

## 2. 真正的生产者与广播

14479原生VA `0x1806292f0`，新REA `ev_9f214ac55619ac5992c9a845ce69187057c92445b19d2edc9d0063161bfc1335`：

1. 读取NpcManager.IsMaxStrangeSomeOne（+0x5a）。若为真，须启用SkillType.Exhibitionism(21)或Sex(22)，否则直接返回。
2. 取InGameManager.Instance.TempInGameState（manager+0x30）。
3. 执行 `IsTimeStop = !IsTimeStop`（temp+0x14）。
4. 取静态Events.TimeStopEvent（Events静态区+0xa0），按事件类型调用EventManager中登记的组合委托。

TimeStopEvent不携带停止/恢复bool。NPC接收器15536重新读取全局IsTimeStop，实参事件对象不决定停止方向。生产者包含内联的Broadcast字典查找/委托调用，因此仅Hook公开EventManager.Broadcast地址会漏记这一生产路径；本轮直接观测14479和15536，并用调用ID关联。

从初始false连续允许调用时，广播可见状态为true→false→true→false。重复触发原动画事件会多切换一次状态，但不会单靠这一生产者产生true→true。生产者守卫若拒绝恢复请求，则标志仍为true、也没有新广播；这是仍处于停止态，不能归因于缓存再次被覆盖。

## 3. 注册、去重与注销

NpcController.Initialize（15518）成功路径创建原生Action<TimeStopEvent>，目标为该NpcController，方法为15536，再调用 `AddListener(evt,false)`。bool原名为 **isHead**，不是“立即调用”选项。

共享AddListener入口 `0x180993250`，新REA `ev_898717e3d7d57c525a3d3c8587476b2b1a42d33f8046398715567a6dd6bb5900`：先在s_EventLookups查找该委托；找到则返回。仅未找到时添加包装委托，再按isHead决定放在组合委托前/后。去重发生在这一步顺序选择之前。

Destroy（15532）先调用NpcComponentAccessor.Dispose（15490），再创建相同目标/方法的委托并调用共享RemoveListener `0x180993960`，最后销毁NPC物体。RemoveListener从原委托查到包装委托，再移除组合及查找表条目；不需要同一个Action分配地址。相关新REA分别见 `ev_a8bc01f3a18c25da8005c3e0ef758e3a0cebc1966165965c461b4938aac3d6dd`、`ev_c67e26ae7925db9dbadd9332856d3cd0d0a62c105c494420a89c73eedd778191`。

运行夹具按15518的方式使用原生Action构造器：相同NPC目标、同一原始15536 MethodInfo，创建两个不同分配地址的Action。第二次AddListener无论isHead为false或true，查找表Count均保持2（一个测试Found监听器和一个NPC监听器）；每次生产者广播均只命中一次该NPC。这里验证了原生委托相等去重，没有用两个不同托管闭包冒充相同原生委托。

## 4. 其他生产者候选的扫描范围

先以原始metadata usage确认Events槽 `0x182d58080` 和InGameManager槽 `0x182d53c48`；对应8字节编码在整个原生文件中各出现一次。扫描所有PE unwind片段，筛选同片段中Events槽引用与内存位移0xa0的交集，以及InGameManager槽引用与byte MOV/SET位移0x14的交集。得到9个候选，再以REA和原始字段布局核对。

| 候选 | 核对结果 |
| --- | --- |
| OnChangeTimeStop冷片段0x1806293bf | 真实TimeStopEvent生产者 |
| Events..cctor(17335) | 创建静态事件对象并赋字段，未广播 |
| InGameManager.Start冷片段 / OnUpdate(16864) | +0xa0属于StatisticsManager，其他事件广播，不是TimeStop字段 |
| InGameEventListener.OnCompleteTransitionStageEvent(16825) / InGameManager启动回调(16868) | 清零对象是MentalManager，不是TempInGameState |
| GraphicsOption的18609 / 18612 | Events偏移0xc8 / 0xd8，不是0xa0 |
| PlayerAdultGoodsController.Initialize(14471) | Events偏移0x80，不是0xa0 |

尤其两处清零的真实链为 `InGameManager→InGameReferencer(+0x28)→Player(+0x30)→pca(+0x40)→Mental(+0xc8)`；写+0x14=IsRedBlinkGauge、+0x30=isPlayedAlert，不能将它们描述成“无广播重置IsTimeStop”。

因此本轮未从这些候选发现第二个自然TimeStop广播者或无广播清除该标志的入口。扫描是逐unwind片段的语法交集，未完成全程序指针/跨片段数据流，也不覆盖反射、外部Mod或任意运行时改写，**不能据此宣称全游戏绝无其他来源**。

## 5. 32次实际运行对照

在新副本 `E:\ManakaREA-TimeStopFixture` 中，8条件×男女NPC×2轮，每例4.5秒。原生二进制与上一轮输入逐份匹配，models解密副本哈希也验证一致。原始14479、15536、15350、15358及EventManager/Scheduler保持执行，旁支bootstrap、移动、音频/片段结束处理由夹具隔离。

| 条件 | 次数 | 生产者后的标志 | NPC收到的标志 | 最终速度 / NPC事件与广播 |
| --- | ---: | --- | --- | --- |
| 直接调用原始生产者两次 | 4 | T,F | T,F | 1；各1 |
| 快速连续四次调用 | 4 | T,F,T,F | 相同 | 1；各1 |
| 相等原生委托重复订阅，isHead=false | 4 | T,F | T,F，各仅一次 | 1；各1 |
| 相等原生委托重复订阅，isHead=true | 4 | T,F | T,F，各仅一次 | 1；各1 |
| 原始玩家动画片段两次 | 4 | T,F | T,F | 1；各1 |
| 显式重触发原玩家控制器，再恢复 | 4 | T,F | T,F | 1；各1 |
| **注入额外同状态广播** | 4 | T,F | **T,T,F** | **0；事件/入队/广播均0** |
| **人工清标志后再次调用生产者** | 4 | **T,T,F** | **T,T,F** | **0；事件/入队/广播均0** |

合计76次原生生产者调用、80次原生NPC时间停止处理、24次原生NPC发现事件、24次原生延迟回调/测试广播。没有在原生产者路径观察到一对相同状态的连续NPC处理。

负对照直接显示覆盖条件：该NPC第一次处理true后cache=1/speed=0；在未恢复速度时又处理true，cache变0；随后false只恢复0，发现动画没有经过事件点。无广播修改标志的对照是为了证明逻辑必要条件，**不是已经发现的自然场景路径**。

玩家片段用例显式设置ActionId/TransAction，绕过完整输入与PlayerAction上下文；重触发实验也有意绕过自然当前动作门。它们检验的是原始控制器→原事件→原生产者→原注册NPC链，不能称为已经实际游玩并按环菜单触发。

## 6. 证据与结论边界

REA Frida最终未截断361条消息：`ev_5d3012e7b64b4674f74935083345b9e3da15989b76e68870ec5f90ba0ade835e`。脚本载入记录为 `ev_94e738f268e48c38291c7af199a4dfffd9f9a0b32bbc8e4ad43b2797a4e3f281`。原始subject/environment为空及其限制原样保留，独立manifest关联PID44056、模块路径、源代码及文件哈希。进程已退出，会话已关闭。

逐帧日志、原生日志、计数对账、静态方法/泛型/字段/枚举和候选分类均已留存。完整自然场景游玩、所有监听器之间的重入、反射/Mod生产者和异常清理路径仍未实测。现有证据支持：**常规切换或重复相等订阅不能复现上轮缓存覆盖；要触发该覆盖，必须让同一NPC在速度仍为0时再次处理true，而本轮未找到满足该条件的自然来源。**

复核及重新运行步骤见 [夹具说明](runtime/time-stop-producer/README.md)。本轮未修改游戏DLL或用户插件来修复这一防御性缺口。
