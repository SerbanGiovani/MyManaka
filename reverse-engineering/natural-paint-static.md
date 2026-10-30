# 自然涂料物品：取得、使用与冷标题读档

本轮仅分析冻结原件。7条缺失UI方法在一个seeded REA/Ghidra批次完成（154.035秒，正常关闭），既有状态机/存读档/玩家初始化复用41条观察。另用原件附带Iced解码5个有限PE unwind范围，补使用守卫、rank门槛、静态property初始化、SexManager实例getter及部件启停引起的身体材质重建；这是单独标记的静态指令证据，不冒充REA或运行寄存器。没有操作游戏进程、存档、输入或全局配置。

`salt/natural_paint_evidence.py --check`核对`natural-paint-chain.json`；`natural-paint-assets.py --check`核对原MItem/MRankRelease资源记录。这里的可达条件尚需被动采集验证，不能将它算作自然使用或冷读档已经成功。

## 取得物品

自然入口是自宅电脑的网上商店。PcMenuPanelView.OnClickOnlineShop(17600，RVA0x4cb4e0，与OnlineShopPanelView.Open共享地址)打开AssetReferencer.OnlineShopPanel；OnClickTab(17742，0x4d8920)的道具页参数为0。非试玩版本才列入这些道具。

| MItem.Type / 原enum | NameKey | 原Price | 可重复使用 | 可网上购买 | 可丢弃 |
|---|---|---:|---|---|---|
| 5 BodyPaint | m_item_bodypaint | 500 | false | true | false |
| 8 BodyPaintReusable | m_item_bodypaint_reusable | 500 | true | true | false |
| 9 BodyPaintWasher | m_item_bodypaint_Washer | 0 | true | true | false |

三条IsDelayConsume均false。这里是MItem.Type库存键，不把未序列化的TypeId backing field猜成同一数值。原MItem表18条PPtr、AssetReferencer.MItem绑定及所选记录的九项存储字段均消费至对象EOF；末尾native TypeId字段在该blob没有存储bytes。脚本保留具体偏移、原bytes与getter类型。

原版名称来自`resources.assets`的TextAsset `dictionary`（path_id1484，原对象SHA256 `efe3c4ca9177503c0878da833f711b8adc571be529b314333bc020ba42f1057d`）。`natural-paint-assets.json`保留TSV表头、三条key的id、按LF计数的原物理行、UTF-8 payload/对象字节偏移、行原bytes及SHA；TextAsset长度和尾部对齐消费至EOF。三个名称行id分别为592、593、1142。下表是原翻译内容，不把静态提取说成运行中已渲染该语言。

| 类型 | 简体中文 | 繁体中文 | 英文 |
|---|---|---|---|
| 5 | 身体彩绘套装 | 身體彩繪套組 | Body Paint Kit |
| 8 | 身体彩绘套装（无限） | 身體彩繪套組（無限） | Body Paint Kit (Infinite) |
| 9 | 身体彩绘清洁套件 | 身體彩繪清潔套件 | Body Paint Cleaning Kit |

道具页对5/8/9统一检查GameStateFacade.IsRelease(109/0x6d，RankReleaseType.BodyPaint)。原MRankReleaseRecord该项ReleaseRank=5，原MRank.GetByRank(5).NeedRp=5000。16807 IsRelease(0x4921c0)实际比较的是`GameStateData.ExposeExp(+0x1e8)>=5000`，不是现有可花RP，也不是PlayerState.CurrentRank缓存。因此“现金足够”不能替代解锁条件；保存里已有库存与当前网上商店是否解锁也应分开记录。

OnlineShopItemView.Initialize(17725)对已带有的可重复道具标为持有；父Panel.OnClickPurchase(17747，0x4db560)首先拒绝isBring(+0x148)，再以记录Price检查IsEnoughRp。MItem库存已有99件时也拒绝；通过才ConsumeRp、ChangeItemNum(Type,+1)。购买5/8还可触发教程10。5可重复购买直到堆叠上限；8/9已拥有后无需再次购买。上述500/0是原记录值，实际自然支付仍应核对Native ConsumeRp和库存变化。

## 自然使用与三秒生产者

InventoryPanel.RefreshItemCategory(17981)只为ItemDict中正数库存建立条目；InventoryItemView.OnClickUse(17925，0x4ea4e0)使用view+0x60委托和view+0x70 MItemRecord进入17993回调。其共用17984守卫(0x4f2a40)要求：未戴手铐、PlayerState.IsCrouch=false、CurrentAction.Type=-1、CurrentState=0、IsEcstasyMotion=false、SexManager.IsSexMode=false。该守卫没有场景/Home比较；这说明Apartment未被此处明确禁止，不等于已验证自宅实际点击成功。

8进入CommonPopup确认后才执行UseProcess；5/9直接执行。UseProcess闭包18007(0x4f4350)根据`!IsReusable&&!IsDelayConsume`先扣库存，再调用MItem.UseItemProcess(16071，0x4679f0)。因此普通5在安排延迟时即减1；8/9不减库存。不要把MItem已进入等同于涂料效果已落地。

16071为5/8/9设置同一个动作10008(0x2718)：

| 对象/字段 | 原偏移/类型 | 含义 |
|---|---|---|
| Pca.PlayerState | +0x60 / PlayerStateModel | 以下字段宿主 |
| LastUseItemType | +0x228 / ItemType | 5、8或9 |
| TransAction | +0x234 / ActionType | 待切换动作10008；不是名为InputActionType的字段 |
| CurrentAction | +0x48 / MActionRecord | 当前执行动作；Type在该record+0x18 |
| CommonEquipEndTime | +0x178 / float | Time.time+3 |
| OnEndCommonEquip | +0x170 / System.Action | 5→16075、8→16076、9→16077 |

PlayerAction.OnUpdate(14462，0x625440)仅在当前动作仍为10008且`Time.time`严格大于截止值时Invoke委托，之后ChangeAction(-1)。这是游戏时间截止，并非固定墙钟三秒，也不是通用JustEffectItem动画事件。实际测试可正常使用后关闭背包/Tab并等待动作完成，观察原委托及remain变化；不要另行调用回调。

16075(0x468c40)、16076(0x468cb0)尾跳到15015 OnUseItem(0x3fd150)，原E9点分别在0x468c96、0x468d06，已有bytes佐证。16077(0x468d20)内联15016清洗状态赋值，没有义务进入独立0x3fd230入口。一次效果可被委托入口和15015入口共同看到，不能计成两次使用；清洗缺15016入口也不能判漏发。

## 正剩余时间的自然保存与真正冷启动

先自然完成一次普通或可重复涂料使用，确认实际remain已变120、reusable与物品一致。随后在自宅电脑正常保存，通过实际Save返回和独立密文解码确认剩余值，而不是从按钮点击或预期值推断。若希望验证state2，可优先保留remain>60的自然快照；若真实值已在24<t<=60或0<t<=24，则按实际区间验证state3/4。Dokidoki0时timer不减少，不能以等墙钟时间保证跨界；也不应为了命中区间写remaining或心跳。

真正冷路径需要旧进程结束，再启动新进程，通过标题“继续”选择刚才保存的同一槽。回标题但保留进程能检查场景重建，不能单独称进程冷启动。关键入口如下：

| 原方法ID / 名称 | RVA |
|---|---|
| 16370 Title.OnClickContinue | 0x46fef0 |
| 17861 SaveDataSelectPanel.OnClickItem | 0x4e5180 |
| SaveManager.Load（16971） | 0x49d380 |
| 17860 SaveDataSelectPanel.TransScene | 0x4e4ed0 |
| 16862 InGameManager.Start | 0x495dc0 |
| 14756 PlayerController.Initialize | 0x643550 |
| 14715 PlayerClassAccessor.Initialize | 0x63e030 |
| 14624 BodyMaterial.SetupBodyPaintFromGameState | 0x637bc0 |
| 14627 BodyMaterial.ApplyFromGameState | 0x638680 |
| 14757 PlayerController.OnUpdate | 0x643a10 |
| 15012 BodyPaintController.OnUpdate | 0x3fca90 |

14715直接内联15011的协调逻辑：把真实Pca写进原BodyPaintController，再按加载的remain写state/Current（<=0→0/-1，0<t<=24→4/0，24<t<=60→3/.25，>60→2/.4）。然后初始化BodyMaterial并Setup/Apply，再初始化BodyCustomize。故冷读档可以没有15011入口，必须看14715返回的原controller、state/alpha、材质绑定和首次自动更新，而不是拿“15011调用数为0”判恢复缺失。前一轮克隆暖Load的state0现象不能外推到这条完整玩家初始化路径。

被动取原实例可使用PlayerController TypeInfo槽RVA0x2d58378→klass.static_fields(+0xb8)+0.Instance→player.pca(+0x40)。BodyPaint TypeInfo槽RVA0x2d58330→static_fields+0为property ID。未解析的usage仍是tag编码，不可当指针解引用；raw+0xe0只标本build class-init guard，不擅自命名具体Il2CppClass位域。观察器不要为读取静态字段提前触发BodyPaint wrapper类初始化。

原15018静态构造使用的确切shader字符串是`_Tweak_transparency`。它与BodyPaintController.TweakTransparency字段名不同。自然原生流程已初始化后才可比较原static ID与独立属性ID；读取材质也需按HasProperty保护，并区分声明属性、运行写入的额外presence和实际Renderer槽。字段读取不证明像素可见性。

身体材质重建不等于再次使用涂料。补充原指令确认14786 `PlayerCosplayManager.SetCosplayActive`（RVA0x646af0）在0x646c82直接调用14624，返回地址为0x646c87。跳过效果计算的参数只使0x646c57越过`CalcCostumeEffect`，仍会经过这次重建；该完整有限范围没有“原活跃值相同就早退”的分支。它不写BodyPaintController的state或Smooth.Current。另两处直接call返回地址0x646643、0x63f454分别属于14783 `SetupCostumeFromGameState`及14715 `PlayerClassAccessor.Initialize`，binding保留三个E8原bytes和目标校验。14624既有REA已显示按当前remain重组Renderer材质槽、重新绑定ClothesPaint并调用Futa.SetupPaint，所以不能要求自然采样中的材质指针及其属性跨重建持续不变。仅凭这些入口不能判定每次调用都实际换了装备，也不能确定SetCosplayActive更上层生产者或将其次数当作物品完成次数。

这里未证明自然点击已通过、三秒效果实际发生、自然存档字段已写入或冷标题重建成功。共享原方法/内联路径、初始化前后时间区间和新对象身份，都应由本轮被动日志闭合。
