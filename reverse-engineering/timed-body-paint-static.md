# 临时身体涂料：状态机、计时与原生入口

本轮只读原GameAssembly和元数据，复用27条既有观察，并在单个seeded REA/Ghidra批次补8条伪代码；172.589秒完成，原生会话及transport正常关闭。绑定为`salt/evidence/timed-body-paint-chain.json`，可由`salt/timed_body_paint_evidence.py --check`重新核对。没有启动、附加或操作游戏进程。本报告只说明静态行为，运行验证另记。

| 方法 | 原metadata ID / RVA | 准确托管签名 |
|---|---|---|
| Initialize | 15011 / 0x3fc940 | void Initialize(PlayerClassAccessor pca) |
| OnUpdate | 15012 / 0x3fca90 | void OnUpdate() |
| GetMaxDeltaAdd | 15013 / 0x3fd090 | float GetMaxDeltaAdd() |
| IsPainted | 15014 / 0x3fd130 | bool IsPainted() |
| OnUseItem | 15015 / 0x3fd150 | void OnUseItem() |
| OnUseWashItem | 15016 / 0x3fd230 | void OnUseWashItem() |
| BodyPaint构造 | 15017 / 0x3fd290 | BodyPaintController() |
| SmoothFloat构造 | 17316 / 0x4b5410 | SmoothFloat(float second,float baseValue,float defaultValue,bool isLerp,bool isUnscaled,float downSecond) |
| SmoothFloat更新 | 17317 / 0x4b54f0 | void UpdateTo(float target) |

BodyPaint字段为alpha(+0x10)、pca(+0x18)、currentState(+0x20)。Pca.PlayerState是PlayerStateModel(+0x60)，互操作名称为`Dokidoki`（System.Single，+0x58）和`LastUseItemType`（ItemType，+0x228），均有可写property。不能把后者拼为小写lastUseItemType。剩余时间`GameStateData.PlayerRemainBodyPaintTime`为+0x17c，可重复标志`IsActiveBodyPaintReusable`为+0x1df。

初始化与每次更新有不同含义：

| 初始化剩余时间 | 状态及原enum名称 | alpha.Current |
|---|---|---|
| <=0 | 0 NoActiveNoMaterial | -1 |
| 0<t<=24 | 4 SecondReduce | 0 |
| 24<t<=60 | 3 FirstReduce | .25 |
| >60 | 2 Start | .4 |

Initialize只写pca、currentState与SmoothFloat.Current，没有重置Target或任何速率字段，也不调用Setup重建材质。连续做阈值夹具时，前一组改过的速率会继承，必须明确保存/恢复或记录这一前提。冷创建的PlayerClassAccessor.Initialize(14715)内联相同阈值，之后建立Body材质；暖Load未重建控制器，不能与该冷初始化混同。

15012首先计算`remaining=max(0,remaining-2*Clamp(Dokidoki,0,.5)*Time.deltaTime)`，之后才按状态分支。状态0仍递减剩余时间；Dokidoki=0时不递减并不代表更新停止。该方法不检查IsStopGameStateApplier或IsTimeStop。

| 更新前状态 | 先执行的alpha目标 | 随后转移条件与动作 |
|---|---|---|
| 2 Start | .4 | 新remaining<=60：改为3，base=.15，up/down速率=.15/second、.15/downSecond，并发消息 |
| 3 FirstReduce | .25 | 新remaining<=24：改为4，base=.25，速率改为.25/second、.25/downSecond，并发消息 |
| 4 SecondReduce | 0 | 新remaining<=0：base=1，速率1/second、1/downSecond，发消息，改为1并清reusable |
| 1 NoActive | -1 | Current<=-1：先SetupBodyPaintFromGameState，改为0；随后提前return，不再写三项材质 |
| 0 NoActiveNoMaterial | 无 | 提前return材质段；timer已更新 |

一次更新只按旧状态执行一个分支；例如从state2跨越到剩余0，这次只进入state3，下次才向state4推进。状态转移先用旧目标和旧速率更新alpha，再改下一状态及速率，最后在非0状态将Current写入材质。

BodyPaint构造使用`SmoothFloat(2,.15,0,false,false,-1)`，所以second/downSecond均2，maxDelta/downMaxDelta均约.075。Smooth构造唯一的epsilon为`abs(downSecond-(-1))<.001`时以second替代downSecond；UpdateTo是有限速率MoveTowards，差值不大于本次dt*rate时精确吸附目标，完成判定没有epsilon。2→3、3→4、4→1后的默认速率依次约.075、.125、.5。UpdateTo不写Target(+0x1c)，只写Current(+0x10)；isLerp分支是另一路径，BodyPaint原构造为false；原isUnscaled=false，读取deltaTime。

Smooth必须保留9个运行字段：Current(+10)、maxDelta(+14)、downMaxDelta(+18)、Target(+1c)、isLerp(+20)、baseValue(+24)、second(+28)、downSecond(+2c)、isUnscaled(+30)。alpha尚未降到-1前，临时材质槽可继续存在；到state1完成时，Setup按remaining<=0移除该槽并将Body.ClothesPaintMaterial置null。不能要求已重新绑定的两个Futa材料的最终TweakTransparency恰好为-1，因为完成分支在重建后提前return。

原物品enum为BodyPaint=5、BodyPaintReusable=8、BodyPaintWasher=9；7是InvisiblePotionReusable。15015先将remaining设120，旧remaining<=0时才立即Setup；然后设state2、Current=1，LastUseItemType==8时置reusable=true。普通5不主动清除已存在的reusable。15016只设state4及remaining=0，不直接清reusable或移除材质，下一次4→1才清标志，后续1→0才实际Setup移除。

自然物品效果由16071 MItem.UseItemProcess在5/8/9分支设LastUseItemType、CommonEquipEndTime(+0x178)=Time.time+3、输入动作10008(0x2718)，并将16075/16076/16077委托写入PlayerStateModel.OnEndCommonEquip(+0x170)。14462 PlayerAction.OnUpdate在当前动作仍为10008且`Time.time>截止值`时调用委托，随后ChangeAction(-1)。5/8委托尾调用/内联15015，9委托内联15016。它是逐帧截止时间路径；新增核对的14492 JustEffectItem不承担这条BodyPaint效果，case5走异常，不能以该通用动画方法替代真正生产者。

自动更新由EventMethodManager.Update(16737)遍历`updaterList(+0x28)`分派IUpdater，元数据接口槽指向PlayerController.OnUpdate(14757)，再经Pca.BodyPaintController(+0x1e8)调用15012。InGameManager.Instance.eventMethodManager为+0x78；列表真实类型是`Il2CppSystem.Collections.Generic.List<IUpdater>`，原Initialize只列入一次Player。IsStopGameStateApplier(+0x10)只让GameStateApplier.OnLateUpdate(16744)跳过位置/NPC状态回写，不能用它保证手动OnUpdate不与自动更新叠加。独立clone还共享global remaining；若采用原controller停在state0、Dokidoki常0而仅同步clone调用期间暂设非0的受控方案，仍须按receiver指针与逐帧计数证明实际隔离，不能只看状态字段。

三个shader写目标是Body.ClothesPaintMaterial，以及Pca.FutanariController(+0x1d8)的SaoClothesPaintMaterial(+0xa8)/TamaClothesPaintMaterial(+0xa0)。Setup还调用FutanariController.SetupPaint(15066，RVA0x401350)，实际重建`PlayerAvatarObjectReferencer.FutanariMeshSao(+0x1b8)`和`FutanariMeshTama(+0x1c0)`两Renderer材质数组，严格remaining>0且RubberSuitDummy inactive才加临时槽，然后将最后槽绑定上述属性，即使没有临时槽也保留末槽引用。0x402090另属于15067 SetupCosplayOption，是ApplyFromGameState末尾配置路径，不能误当作SetupPaint。受控恢复需要这些Renderer原shared数组、绑定引用和记录的属性；仅备份BodyRenderer不足。

暖加载陷阱是：原controller为state0，Load正剩余时间并广播Body后，材质虽然可重建，状态仍0，更新只递减timer而不推进alpha。显式Initialize才依据时间重建state/Current。这个受控暖路径现象不能单独证明自然标题冷读档存在缺陷。

GetMaxDeltaAdd按状态返回3、3、.03、.1、.3；IsPainted对0/1为false，2/3/4为true。GetMaxDeltaAdd伪代码错误显示整数返回，原metadata与interop返回float，绑定另核对4条原字节`MOVSS XMM0,[RIP+...]`及紧随的函数尾和浮点常量，确认XMM0承载float。IsPainted用AL返回bool，另保留原字节。此为少量已知opcode的有界佐证，不宣称完整独立反汇编或由函数名推导物理效果。
