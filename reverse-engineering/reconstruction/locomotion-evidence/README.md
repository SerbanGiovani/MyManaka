# 原玩家 Animator 与移动接线证据

本目录是新增的只读调查输出。原件固定为 `E:/SecretFlasherManakaREA`，models 采用已解密副本。没有启动编辑器、原游戏或独立游戏，也没有执行原脚本。运行验证由同轮独立工程证据另行提供。

`original-controller.json` 复用已完整解码的 `../../assets/animator-wiring.json`，并重新读取原 models 的 Transform/Avatar/clip 字节，沿父 PPtr 验证实际 prefab 归属。`acceptance_identity` 与 `locomotion` 是验收工具可读取的简表；完整字段、序列化坐标与限制仍保留。`native-contract.json` 把本轮 REA JSON 绑定到原 metadata 的方法/参数原始字节，并保留共享地址的全部 metadata 别名。

## 确认的资产接线

- 原玩家容器键 `assets/zzz-externalencryptasset/player.prefab`，根 pathID `-8406032082528140171`。
- 六个序列化 Animator 引用 Player controller，其中只有 `Player/Manustia` 是该 Player prefab 的子对象。其 Animator pathID `-4550091270844762613`，Avatar 为 `ManustiaAvatar`，pathID `-4334950846762833491`。
- Player controller pathID `-1824587515900773540`，对象 SHA256 `e1135eac992f564dcea388149032d88673e5b478fa135e70bc142e6494444b08`。容器没有该 controller 的独立键；运行时应从确切 prefab 的 Animator 引用取得。
- 实际模型 localPosition=(0,0,0)、localRotation=identity、localScale=(1.2,1.2,1.2)，applyRootMotion=false。原序列化 culling=1、updateMode=0。
- Controller 的 StateMachineBehaviour、behaviour ranges 和 indices 全部为空。clip AnimationEvent 仍存在，需要新工程自己的接收策略；空 behaviour 数组不等于无事件。

## 移动图与参数

Locomotion 为层0，默认状态 `Locomotion.LocomotionTree`，fullPathHash **686120411**。Idle、Walk、Jog 是同一状态内的一维混合，不能验收成三个不同 state。

| 参数 | 类型 | 原 controller ID | 作用 |
| --- | --- | --- | --- |
| Speed | float | 3471299058 | LocomotionTree 的一维输入 |
| LocomotionMotionSpeed | float | 2159952585 | Locomotion/Strafe/Crouch 状态的 speed 参数 |
| IsStrafe | bool | 2388943033 | 普通/横移树切换 |
| StrafeX / StrafeY | float | 772452860 / 1494057322 | 横移方向混合 |
| IsCrouch | bool | 3093863316 | 蹲姿树切换 |

| LocomotionTree Speed 阈值 | 原 clip | pathID |
| --- | --- | --- |
| 0 | Female_Idle_Base | -6146369417725401721 |
| 1 | Female_Walk_Forward | 6306824394767773239 |
| 2 | Female_Jog_Forward | 6299861715420163249 |

CrouchTree fullPathHash=1097057632，Speed 阈值0/0.5对应 `DogWalkIdle 1` / `Armature_DogWalkI 1`。StrafeCrouchTree 也使用0/0.5；原 native 的蹲姿目标动画速度仍可为1，0.5是树的饱和阈值。

LocomotionTree↔StrafeTree 用 IsStrafe/IfNot；LocomotionTree↔CrouchTree 用 IsCrouch/IfNot；普通切换固定0.25秒，HasExitTime=false。完整过渡 ID、fullPathID、条件、优先顺序和特殊分支均在 JSON 中，不能以摘要替代 Unity 实际的过渡求值。

所有序列化 float/int 参数默认0，bool/trigger false。原 PlayerAnimationManager 初始化内部 locomotionMotionSpeed.Current=1、baseMoveSpeed=1；独立工程需要显式设置 LocomotionMotionSpeed=1 才能播放。其他层并非全部默认 NoMotion：ClothActionArm 默认 Coat.CoatArm，Face 默认 IkuAfter.Face0_0_0，FaceAdd 默认 Blend Tree。新工程关闭这些层的权重属于隔离运行时选择，不能称为原游戏的默认初始化。

## 输入、物理速度与动画值

复用 `../../player-chain.md` / `../../salt/evidence/player-chain.json` 的真实链：InputManager.GetVector3(0)→InputResolver.Resolve→PlayerController.OnUpdate→PlayerLocomotion.StateUpdate/OnUpdate→PlayerAnimationManager.TargetMoveSpeed→PlayerAnimationManager.OnUpdate→Animator.SetFloatID。固定物理出口是 PlayerLocomotion.OnFixedUpdate→CharacterController.Move_Injected。

Resolve 在 Move.sqrMagnitude>=0.5 时归一化，小输入保留模拟量。普通分支的世界目标速度为 Move.magnitude 乘基础速度及状态/技能/选项修正；原 MCommon 基础值 crouch=.6、walk=1.1、jog=2.4。Animator 目标值独立为 `(dashBranch ? 2 : 1) * Move.magnitude`；CanMove=false、IsEcstasyMotion、InvalidLocomotionTime 未到期会清零两类目标。

SmoothFloat.UpdateTo 的普通分支与 MoveTowards 等价，使用 deltaTime 或 isUnscaled 选择的 unscaledDeltaTime，下降时可有独立 downMaxDelta。isLerp 分支是 `Current += (target-Current)*clamp01(maxDelta)`，没有乘 deltaTime。构造证据给出世界 moveSpeed 的 second=.1/baseValue=1（maxDelta=10），动画 moveSpeedBlend 的 second=.2/baseValue=1（maxDelta=5）；两者初值0且下降时间沿用上升时间。横移 X/Y 用 isLerp=true、second=10/baseValue=1，因而每次调用插值系数.1。

SetMoveSpeed(14527) 只写 manager.baseMoveSpeed(+0x24)，该地址与 CameraSettings.set_FOV 等方法共享；REA 标签不构成接收类型证据。SetStrafe(14535) 写 IsStrafe，并将 X/Y 平滑目标设为 `(InputData.Dash ? 2 : 1)*inputX/Z`。

最后的 float 参数用 `abi-windows.json` 核对：0x18062ccdb 的 MOVSS XMM1,[RBX+0x10] 直接把 TargetMoveSpeed 传入 moveSpeedBlend.UpdateTo；Speed 输出从 manager+0xa0 取 SmoothFloat.Current(+0x10)，在0x18062d08b将其复制到 XMM2，0x18062d093调用 SetFloatID。两处有限路径均未乘 baseMoveSpeed。JSON 给出两个完整原件字节窗口、14条逐条断言的 x64 指令解释、PE 文件偏移和 REA dossier 引用；指令解释明确标为分析者推导。

## 片段事件与验收边界

Walk 的 FootL/FootR 分别为0.433333/1.066667秒、int1；Jog 为0.3/0.7秒、int2；蹲走为0.25/1.083333秒、int29。Idle 与蹲姿 Idle 无事件。这里是 clip 时间域，不能解释成墙钟或必然被调用的时间。JSON 中保存每个事件的原字节、范围、对象身份和 EOF 验证。

只有 root 位移、参数变化或 controller 同名都不足以证明动画工作。独立验收应同时核对原 bundle/controller/Avatar 引用、对应 clip、state fullPathHash、normalizedTime 推进，以及骨骼相对父对象的变换变化。静态证据不证明原游戏的运行手感、层竞争、原业务接收器行为或整个游戏已经重建。

## 复查

```powershell
python -X utf8 reverse-engineering/reconstruction/locomotion-evidence/collect.py --check
python -X utf8 reverse-engineering/reconstruction/locomotion-evidence/bind_native.py --check
python -X utf8 reverse-engineering/reconstruction/locomotion-evidence/abi_windows.py --check
```

`native.plan.json` / `native-decoded-code.plan.json` 可交现有 `../../salt/run_batch.mjs` 复查；输出仅在本目录。两批共23次静态查询均成功并正常关闭。完整 REA 记录及 provider 限制位于各批次 `rea-evidence.json`、逐查询 JSON 和 run.json。首批七份空 assembly listing 明确保留为覆盖缺口；第二批增加显式 code seeds 后，SetStrafe得到完整listing，但大函数OnUpdate的Ghidra body仍仅一字节。dossier的未截断high-p-code给出调用站点，却仍丢失float绑定，因此最后的有限float路径采用原件字节窗口复核，不宣称Ghidra已恢复完整反汇编。
