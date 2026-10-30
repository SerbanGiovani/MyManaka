# 原钥匙 F 交互 → Action → 原事件 → None

本目录仅作静态证据提取。原件固定 `E:/SecretFlasherManakaREA`，未启动原游戏、Editor、Frida 或原脚本。独立工程的构建和运行由同轮其他目录记录。原生查询使用 REA 6.5.0 / Ghidra 12.1.4，两批均成功导出并关闭；两份运行输入 `interactions.json`、`original-interaction.json` 已冻结。

## 目标与摆放边界

原 Apartment 是 `data.unity3d/level1`。该场景完整的序列化 InteractArea 集合只有 PC14、Bed13、Closet11，组件 pathID 分别为3777/3778/3779。既有原 `InGameUiManager.OnInteract` (15848) 分别打开相应菜单；它们不是本轮有限拾取动作。`target-assets.json.apartment` 保留该有界扫描及原对象原始字节。

本轮选用真实 `assets/zzz-externalencryptasset/droppedhandcuffkey.prefab`，root pathID `1236904147823038301`。独立 Apartment 中的 `(0.73,0,1.21904826)` 是 root 明确选择的重建 fixture 坐标，rotation=identity、scale=1，不来自原场景。`sourceScene=null` 有意表示没有原固定场景绑定，也不宣称自然掉落/重生已经验证。

| 项 | 原资源证据 |
| --- | --- |
| 模型包 SHA256 | `98621b2c4fa4f9de80f355fae5776ab17efc016bcc81c581bcd0917af4308367` |
| 原触发对象 | `DroppedHandcuffKey/InteractArea (3)`，GO `-7929292301847529429` |
| 原交互组件 | `InteractAreaController` `-6085138761259602439`，type15 HandcuffKey，CanInteractWithAction=false |
| 原碰撞组件 | SphereCollider `-8433096308245661234`，isTrigger=true，radius原float32约0.4，center=(0,原float32约0.45,0) |
| 触发器局部变换 | position0、identity rotation、scale1 |
| 原动作记录 | resources.assets path61662，PickUpItem10025，canMove=false；None(-1) path61658，canMove=true |

原精确float位值、容器key/PPtr、对象SHA/压缩块坐标、匹配type tree和EOF验证均在 `target-assets.json`；此表的约数不能替代机器值。

## 原始调用与守卫

1. InputType.Interact8 的默认键为F。`MiscProcess.OnUpdate`14908在JustInteract时取候选。原Register追加列表、GetHead取末项；没有普通候选时是None0哨兵，并非最近距离选择器。
2. 原MiscProcess拒绝None候选、ecstasy；当前动作非None时要求目标CanInteractWithAction。此钥匙该标志false，因此重复F不重开动作。Area只处理事件中Controller等于自己的目标；除洗衣机例外，手持衣物会拒绝。
3. `DroppedItemController.Initialize`15889的type15分支通过原usage地址 `0x182d5ca10` 绑定15896 `<>c::<Initialize>b__5_2`，并非新造通用按钮。新回调证据为 `ev_ccbca03a6aa0502551c012af9358ed3b0e3a016b7c4d64ca1c4b43ff4c087505`。
4. 该回调依次写LastPickUpItemType=5、ForceSkipHandcuffCheckTransAction=true、TransAction=10025。原metadata压缩默认值另确认DropItemType.HandcuffKey=5。回调自身只有这些状态写入，没有传送、朝向对齐或要求玩家受缚的分支。
5. 原PlayerAction.OnUpdate14462消费外部请求前检查IsPlayingAction，再调用CanUseHand14831，参数为 `(isSendMessage:true, isSkipHandcuff:true, isSkipBasket:false, isSkipPlayingAction:false, isSkipCrouch:false)`。因此手铐检查被明确跳过，但蹲姿、非None动作、非Idle、ecstasy或全局SexManager活动会拒绝。新工程范围为其他子系统中性值，并非完整实现这些子系统。
6. 原ChangeAction14463受`isUpdatedThisFrame(+0x38)`守卫；非None切换后置锁，原OnFrameEnd14461解锁。ChangeAction取得MAction记录，保存LastInteractModel，写CurrentAction，再调用原TransAction14536。

原控制器先MiscProcess、再Locomotion/蹲姿更新、最后PlayerAction。F与C同帧的完整调度属于额外边界，不应仅根据当前蹲姿读数宣称复刻全部调度。

## 原 Animator 与完成效果

原Player controller的Action层index1/machine1、默认weight1。进入状态17 `Action.PickUpItem`，fullPathHash `886742834`；入口要求ActionId=10025与TransAction，过渡0.25秒，无exit-time等待。原TransAction三写顺序为OldActionId←前动作、ActionId←新动作、SetTrigger(TransAction)，之后更新manager自身前动作值。

状态速度1、SpeedParamID=0；不依赖额外动作速度参数。clip表index53 `PickUpItem`，pathID `-8816799273270535533`，对象SHA `db10f66660c550fb9d17be438a641e50d3e8986abd89a8b85f4f6f721a249940`。它长2秒、不循环，只有一个事件：1.9833333492279053秒 `OnAnimEndPickUpItem`，intParameter=0。

原接收器14489（`ev_94fb1d7bcea10ce8efff244b6424f27374b95d6eb463993001d3bf31a51267dc`）在LastPickUpItemType5时Collect(5)、ChangeItemNum(10000,+1)，随后内联ChangeAction(None)路径。Collect隐藏缓存目标并清DropData.IsDropped；它不直接解除手铐。该结束路径即时，**不经过CommonOnEndAnim的Scheduler2帧**；仍保留原同帧切换锁。None记录CanMove=true解除普通目标速度门，速度本身仍按既有原移动平滑恢复。

写None参数不等于强制Animator.Play(NoMotion)：原PickUpItem状态自己的无条件出口在exitTime=1.0开始，固定过渡约0.25秒到state0 `Action.NoMotion`（hash3750866857）。原事件时刻与动画图退出时刻是两个观察。

## 输出与复核

- `native-contract.json`：本轮6项REA记录、metadata字节、别名、usage和原枚举值。5项非空伪代码、1项空assembly Listing；仅15896是新增反编译函数，其余4项重查既有初始化/缓存/Drop/Collect记录。
- `reused-native-contract.json`：通过既有字节绑定器只读复用的原输入/交互/动作/CanMove/结束/Animator证据，保留原Evidence IDs与限制。
- `original-interaction.json`：独立验收authority，含原对象/clip/event/effects/参数、源SHA及fixture标记。`interactions.json`是运行时同一有限链的操作输入。
- `manifest.json`：原件身份、本目录输出SHA和查询关闭状态。

```powershell
python reverse-engineering/reconstruction/interaction-evidence/make_manifest.py --check
```

重做资产或绑定时可显式运行 `inspect_interaction.py`、`bind_reused.py`、`bind_native.py`；这些会改写对应的新调查输出。`build_contract.py` 会重新生成两份已冻结输入，不应在运行验收中途执行。上述脚本不启动游戏。

空或一字节Listing不能证明函数空，也不能作为指令级验证。本轮15896的assembly实际返回空字符串，保留原响应而不伪造反汇编；函数控制流依据是非空Ghidra伪代码与原metadata/usage。新工程额外验证真实AnimationEvent来源、拒绝伪造完成属于重建防错措施，不冒充原接收器对手动调用的守卫。静态调查没有观察原按键、动画播放、自然掉落、完整任务或全游戏行为。
