# NPC 距离调帧、手动 Animator.Update 与发现通知时钟

已确认手动 `Animator.Update` 的浮点实参是**本次已获准调用中累计的 Time.deltaTime**，包含超过1/FPS阈值的余量；调用后才清零。距离调帧本身并非暂停动画，但上层隐藏NPC节流会减少被累计的帧，时间停止还分别影响Animator速度与发现通知计时。因此不能把目标FPS、动画事件片段时间或0.6延迟直接换算成一次确定的墙钟触发时刻。

输入仍固定为 `E:\SecretFlasherManakaREA` 的原始构建，没有运行游戏。原生和metadata指纹沿用artifact-identity.json。报告区分原生/资源观察、结合Unity文档的解释与条件算例；不将算例或静态寄存器设置称为运行测量。

## 1. 距离指标与两组分档

NpcAnimatorFpsController.Initialize（15404，复用）取得 nca.Animator，创建普通 AnimatorFPSController，并按关卡初始化 CullingData。`DistSqrt`（17263，新REA）取玩家与NPC GameObject的世界位置之差，调用0x1803d4630。后者原始指令先平方求和，再于0x1803d46d5执行sqrt，返回欧氏距离D，**不是距离平方**。单位是Unity世界坐标单位。

StageType=11在原始枚举中为ShoppingMall，使用较近的一组阈值；其他关卡使用默认组。数组字段偏移、原始参数存储语句及其证据ID见 `salt/evidence/npc-fps-chain.json`。

| 模式 | 默认关卡D | ShoppingMall D | 行为 |
| --- | --- | --- | --- |
| 近距离 | D≤20 | D≤10 | 退出手动模式，恢复Animator.enabled=true |
| 第一远档 | 20<D<30 | 10<D<20 | 目标30 FPS |
| 第二远档 | 30≤D<40 | 20≤D<25 | 目标10 FPS |
| 第三远档 | 40≤D<50 | 25≤D<35 | 目标5 FPS |
| 最远档 | D≥50 | D≥35 | 目标2 FPS |

仅在远档分支，还检查 `nca.AvatarComponent.MeshParent.activeInHierarchy`；若为假则强制目标2 FPS。这个对象是MeshParent，不是统一NPC根激活状态；近档分支不经过此强制2 FPS检查。所有分支还需满足保存函数中的非空守卫。

15405自身的flame计数每次加1，前两次调用返回；保存体中没有周期重置。它是启动守卫，不是“每三帧更新一次”。初始模型Animator序列化enabled=1，因此也不能说最初两次必然停动画。

## 2. 手动模式的启停和精确浮点实参

Common.AnimatorFPSController字段：isActive=`+0x10`、_fps=`+0x14`、_animator=`+0x18`、_thresholdTime=`+0x20`、_skippedTime=`+0x24`。这里isActive表示**手动降帧模式正在运行**，与Animator.enabled相反。

- `Active(fps)`（19025）：fps!=-1时更新fps和float32的1/fps；首次进入手动模式设置isActive=true、Animator.enabled=false、skippedTime=0，再计算阈值。已经在手动模式时改档不清累计量。
- `DeActive()`（19026）：仅在原本手动时设置isActive=false并恢复Animator.enabled=true；不在此函数补一次手动Update。
- `OnUpdate()`（19028）与15405的内联部分：取当前Time.deltaTime，与旧skippedTime相加；未达到阈值就保存并返回，达到后调用Animator.Update(累计量)，随后skippedTime=0。一次入口最多调用一次，没有固定步长补多次的循环。

15405的关键原始指令：

```text
18041ee21  movss xmm7,[rbx+24h]     ; 旧累计量
18041ee47  call rax                 ; Time.get_deltaTime，float返回XMM0
18041ee49  movaps xmm6,xmm0
18041ee51  addss xmm6,xmm7          ; 本次累计量
18041ee58  movss [rbx+24h],xmm6
...                                 ; 阈值比较、取得Animator和ICall地址
18041ee90  movaps xmm1,xmm6
18041ee93  mov rcx,rdi              ; Animator
18041ee96  call rax                 ; Animator.Update(System.Single)
18041ee98  mov dword ptr [rbx+24h],0
```

原生字符串0x1824aa840绑定该ICall；Common helper在0x18057e634/63a有相同XMM1设置/调用。按 [Microsoft x64 ABI](https://learn.microsoft.com/en-us/cpp/build/x64-calling-convention?view=msvc-170)，第一个指针参数使用RCX，第二个位置的float使用XMM1。故实参既不是0，也不是固定1/FPS，更不是全局Animator.speed。

例如目标2 FPS、两次获准调用的delta都是float32约0.3时，实际传入约0.600000024，而非0.5；清零没有丢弃这部分已传给引擎的余量。但近→远首次激活会清累计，远→近又不补评估，不能据此保证模式切换时完整追补自动/手动两侧的时间。

## 3. 上层调用入口会改变累计速度

普通路径为 NpcManager.OnUpdate（15590，复用）→NpcController.OnUpdate（15524，复用）→15405。15524先增加自身a计数，并按isDisplay设置MeshParent与PlayerSearcher物体的显隐；当 `isDisplay=false && a%3!=0` 时，在到达FPS前就返回。

因此：**15405内部没有周期三帧门，但普通隐藏NPC的上层确有该门**。此时FPS每次只加当前帧的deltaTime，保存代码没有把漏过的两次delta补入累计。即使手动Update每次传递全部已有累计，也不能推出其进度自动等于墙钟进度。外层其他早退/实际调用次数还会进一步影响结果。

TemporaryInGameState.IsTimeStop=true时，15590走独立遍历：UpdateFadeIn+FPS，之后返回；这条路径绕过15524的a%3门。新REA15522（OnUpdateOnTimeStop）也显示内联FPS逻辑，但不能仅因有该方法就断言每帧一定经此方法或重复计算两次。

## 4. 时间停止、Animator速度与通知延迟

NpcController.OnTimeStopEvent（15536，新REA）读取临时状态IsTimeStop：为真时先读Animator.speed保存到controller.animatorSpeedCache(`+0x74`)，再设speed=0，并暂停相应音源/粒子；退出时从该缓存恢复速度，不是强制恢复1。

Iced原始字节进一步确认：0x18042a9f7将XMM1清零后调用set_speed；恢复路径0x18042a7b0把缓存float装入XMM1。时间停止不是FPS禁用开关，也不能等同Unity.timeScale=0；该事件处理成功且速度仍为0时，不能从手动Update收到正delta推导片段正常向前播放。重复事件、其他速度写入或实际事件顺序仍须另外观察。

发现通知有另一套时钟：

1. 四个发现clip在片段时间约0.383333325（站立男性）或0.666666687（其他三种）记录OnAnimBaretaSound；接线见 [动画报告](animator-wiring.md)。
2. 接收器15350先安排15358，原始0x18041a793加载float32 **0.6000000238418579**到XMM1，传给DelayScaledTime；其后还有声音侧处理。动画回调/声音侧与延迟发现广播不能合并成一个时刻。
3. DelayScaledTime（17302）创建DelayTimeModel，isUnscaled=false。ctor17308记录startTime=Time.time，但InvokeIfNeed（17309）**没有用startTime计算绝对deadline**，而是从remainTime逐次扣Time.deltaTime。
4. IsTimeStop=true且isUnscaled=false时跳过扣减；否则使用相应deltaTime/unscaledDeltaTime。到期检查remainTime<=0在暂停门外，因此已经非正的模型仍可能执行；对本次初值正0.6的模型，暂停期间正剩余不会自行减少。
5. 到期后15358读取receiver.nca并广播；保存体没有重新检查距离、Animator.enabled、MeshParent显隐或NPC当前状态。事件排入后再次远离，不等于取消队列。

Scheduler.Update（17304，复用）在timeModel阶段复制列表再检查模型。若新通知在快照前排入，可能在该轮扣减；快照后则至少等后续轮。不同MonoBehaviour、手动Update与Scheduler快照的实际先后没有运行测量。因此“动画片段事件时间+恰好0.6墙钟秒”不成立。

## 5. 对OnAnimBaretaSound时序的结论

Unity的 [Animator.Update](https://docs.unity3d.com/2022.3/Documentation/ScriptReference/Animator.Update.html) 按传入delta评估动画；[动画Profiler说明](https://docs.unity3d.com/2022.3/Documentation/Manual/profiler-markers.html#animation)区分事件收集与事件派发；[fireEvents](https://docs.unity3d.com/2022.3/Documentation/ScriptReference/Animator-fireEvents.html)还是独立开关。这支持“实际评估调用与有效步长影响事件触发机会”的解释，不能由此保证本游戏disabled/culling/过渡中的每个事件必然送达。

代码层面可确认三种影响：

- 远档将评估机会集中到阈值到达的调用；完整累计量会一次推进，长帧可跨过事件位置。保存代码并没有主动按事件点分割步长或手工调用OnAnimBaretaSound。
- 普通隐藏入口的三倍数门会减少被纳入累计的delta；不能只根据配置2/5/10/30 FPS报告实际事件频率。
- IsTimeStop的速度归零与通知模型暂停扣减分别影响“片段能否继续经过事件点”和“已排通知何时广播”；恢复/排队并不等同取消或立即补发。

`npc_fps_timing.py`提供可复现的float32**算术反例**。假设已在手动模式、60Hz宿主、速度1、无状态切换/剔除/暂停：

| 目标FPS / 调用放行 | 男性事件阈值首次跨越的假想宿主时间 | 其他三种阈值 |
| --- | ---: | ---: |
| 2 / 每次 | 0.5秒 | 1.0秒 |
| 2 / 每三次 | 1.5秒 | 3.0秒 |

这些值仅表示源代码算术模型的累计进度跨阈值，**不是实际AnimationEvent日志或游戏保证**。真实状态进入偏移、0.25过渡、速度、caller门、销毁/模型选择、剔除和Scheduler阶段可改变结果；本轮没有验证所有发动条件下是否漏发、重复或在何帧送达。

## 6. 证据与复核

新增16次REA查询：11份非空伪代码、1份非空assembly和4份空Listing。空结果保留为不可用，不用于ABI结论。三个批次均成功导出并关闭；旧初始化、caller和事件函数复用已有观察。

补充Iced证据使用原始PE的20个unwind片段/1,142条指令。按显式CHAININFO链接归组，避免只解码15405的76B入口或19028的19B入口而遗漏真正调用。每条指令、pdata与链条原始字节、Iced DLL及解析脚本指纹均可复核。它是静态指令补证，不是REA提供的空Listing内容，更不是运行寄存器捕获。

| 重点 | 证据 |
| --- | --- |
| 距离调帧原生函数 | 15405 / `ev_97a5f467b5fe41a31191d90cc914342b543f98113597314c4fbdf3be62aa482e`（复用）；原始ABI字节另见symbols/npc-fps-instructions.json |
| 通用手动更新 | 19028 / `ev_110cad2604b1d32c5fb9065f45ca96db56dea02bcec1bc14cef6de92c8d53210` |
| scaled队列入口 | 17302 / `ev_83021781acf0707d2f90650f84a4ba6fd97411a8f151e0966f732704fb12e9dd` |
| 剩余时间与挂起门 | 17309 / `ev_7ac6fa41def4be12fadc4d2cdfb8358e706c08dc1dedb868e13c4a37fb645000` |
| 时间停止速度缓存/恢复 | 15536 / `ev_5539594bd72be40dd76d8b51714109715cdbdd3466aafda9948653a8e4c25e31` |

```powershell
# 重建静态指令观察（仅读原始文件）
python reverse-engineering/salt/prepare_npc_fps_instructions.py
& reverse-engineering/salt/decode_npc_fps.ps1
python reverse-engineering/salt/npc_fps_evidence.py --check
python reverse-engineering/audit.py --inputs
```

已回答选定距离指标/阈值、浮点实参、启停/外层放行、IsTimeStop速度和通知计时规则；时序影响具有以上静态依据。实际UnityPlayer事件派发、自动/手动评估相对帧序和完整运行行为仍未验证，尚不能据此宣称独立游戏运行完成。
