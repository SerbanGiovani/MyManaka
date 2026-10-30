# 付费学习边界：静态交付与受控运行方案

只读核对完成。新增9份非空REA查询，分别位于salt/evidence/paid-skill-boundary和paid-skill-boundary-consumers。未启动/附加游戏、未改原件/存档、未改总审计或提交。

## 已确认入口与重要区别

- SkillPanelView.Open(Il2CppSystem.Action onClose)，RVA4e7d10，id17881，静态。反射params helper须传(object)null或new object[]{null}；裸null会成为空args数组引用。Open通过AssetReferencer.SkillPanel+0x128和InGameUiManager.Open创建真实面板；OnClickTab(0)筛选Basic并创建/初始化真实SkillItemView。
- SkillPanelView.childViewList+0xa0；view.skill+0x80，necessaryRp(Int32)+0x78，isSomeMask(Boolean)+0x98，isLearned(Boolean)+0x99。
- Initialize17524和UpdateMask17527计算isSomeMask：PlayerState.CurrentRank.Rank低于record.ReleaseRank，或record.ReleaseOrderTarget!=-1且前置GetSkillLevel<1。isLearned实际是level>=MaxLevel。
- Refresh17528先算InitRp+level*IncrementRp，但MaxLevel!=1时改用Mental/Stamina/Slow/MaxAccessoryNum各分级主表的NextLevelUpRp。因此仅用MSkill.InitRp推算多级技能价格是错的。
- OnClickReinforce17530先拒绝mask/max，再IsEnoughRp(view.necessaryRp)，然后ConsumeRp→RiseSkillLevel→Refresh→父回调→Skill事件。IsEnoughRp16759确认为CurrentRp(double)>=cost(int)，不是待结算收益。
- 父回调17878会遍历全部childViewList调用UpdateMask。购买Slow后，应在同一真实面板内自动解除AutoSlow前置掩码；外部人工改rank/前置时则需重建视图或原UpdateMask。
- RiseSkillLevel16755不承担扣款/解锁/最高等级守卫，不能代替真实按钮测试；被动只在激活字典缺该键时自动设true，已有false键会保留false。

## 非成人Basic候选与真实分级表

SkillType值来自原metadata默认常量，原始字段/字节坐标见paid-skill-boundary-metadata.json。主表记录先前被运行采集观察到的值与当前离线主资源分级表明确分开。

| 技能 | enum | 特性 | 真实价格/上限 |
|---|---:|---|---|
| MaxAccessoryNum | 11 | rank0，无前置，MaxLevel3 | level0/1/2/3 MaxNum5/10/15/30，NextLevelUpRp300/1000/3000/2000；level3仍有价但max守卫拒绝 |
| Slow | 6 | rank0，无前置，MaxLevel5 | level0..5 NextLevelUpRp50/100/200/400/800/800；MaxTimeTank0/2/5/10/20/30 |
| AutoSlow | 9 | rank0，前置Slow，MaxLevel1，被动 | 200 RP；初次学习且激活键缺失时自动启用 |
| NpcDirect | 7 | rank0，无前置，MaxLevel1，被动 | 100 RP；可核对真实Buff消费者 |
| AutoAddMoisture | 23 | rank1，无前置，MaxLevel1 | 100 RP；适合rank0拒绝/rank1允许的后续受控rank指针边界 |
| Perspective | 15 | rank5，无前置，MaxLevel1 | 100 RP；适合rank4/5边界，但切换会触发VisibilityFogController副作用，不建议首轮 |

分级表的原始PPtr绑定、record字节、metadata/Cecil类型对应和EOF消费见paid-skill-boundary-assets.json；复现脚本paid-skill-boundary-assets.py只读原件。

## 推荐最小运行矩阵

1. 容量：11等级0、299 RP，真实view价300，点击拒绝；随后独立基线11等级0、300 RP，真实按钮扣到0并升1，实际容量由5变10。记录view activeInHierarchy、reinforceButtonObject、mask/max/cost和父回调存在/进入。
2. 最高：11等级3、2000 RP，确认isLearned=true，原方法拒绝，等级/RP不变。不能人为清max标志后测试。
3. 前置：Slow0/AutoSlow0、250 RP。AutoSlow先被掩码阻止；同一面板点击Slow消费50，父回调自动更新AutoSlow掩码，再点击AutoSlow消费200并升1。不得手写掩码。
4. 被动：NpcDirect0、100 RP，分别激活键缺失与已有false。真实付款学习后前者自动true、后者保留false。打开SkillSwitchPanelView.Open()，从itemList+0x88找record.Type=7的真实SkillSwitchItemView；toggle+0x28、record+0x38。可用Unity toggle.isOn触发原事件，或SetIsOnWithoutNotify后明确调用一次OnChangeToggle17641，不能两者并做导致双回调。
5. 每次消费后原Save、扰动、Load，再原Refresh/UpdateMask及实际消费者，核对文件和运行对象。

## 实际消费者

- InventoryPanelView.CanEquipByMaxCount17985调用CalcEquipCount17986，然后GetSkillLevel(11)→MSkillMaxAccessoryNum.Get(level).MaxNum(+0x1c)，比较count<MaxNum。空库存时新旧都true并不代表没生效；还需读取真正容量及原RefreshEquipCount生成的文本。
- PlayerRpBonusCalculator.OnUpdate14936在技能7等级>0且activation字典true时，置PlayerState.OtherBuffDict(+0x160)[BuffSourceType.NpcDirect=33].IsActive(+0x30)。该BuffModel的RpBonus100在+0x20、LastMult100在+0x24。它最终聚合到PlayerState.RpBonus(+0xe8)/RpBonusInt(+0xec)。建议直接记录该真实Buff与最终数值，不预设固定0.1差（还有难度/其他乘数）。
- SkillSwitchItemView.OnChangeToggle17641读取toggle.isOn(+0x120)，调用ChangeActivePassiveSkill。15会刷新雾视，24会重算服装；7无这两种特殊分支。

## 证据和未覆盖项

九个新增方法：17527、17528、17877、17881、17641、14936、17985、17650、16759。复用17524、17530、17878、16755、16760、16751。两个REA批次均success=true并已关闭。没有执行本方案，任何UI可见性、自然点击、rank自然升级、付费成功、存档重绑与实际Buff增量都不能因此宣布运行验证通过。低级层刷新/付费读取明确可测，真正自然任务所得资金购买还需主线程自然采集衔接。
