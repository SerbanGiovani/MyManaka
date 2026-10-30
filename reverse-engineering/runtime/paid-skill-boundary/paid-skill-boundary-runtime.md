# 付费学习边界：真实活动视图、消费者与存档

2026-10-30正式批次20261030-3完成7组Unity主线程受控调用。实际创建SkillPanelView，使用Open((object)null)、OnClickTab(0)取得活动SkillItemView，再进入原OnClickReinforce；保存前后14份密文独立解码。161条REA消息无截断、无脚本/引擎异常。此处验证真实视图回调及其消费者，没有模拟自然鼠标操作，也没有证明自然等级解锁或时间停止教程成功。

| 条件 | 原UI与结果 | 保存后消费者 |
|---|---|---|
| RP不足 | 容量11、0级，显示300；299拒绝，无扣款/升级 | 容量5，库存实际计数1、显示1/5 |
| RP恰好 | 300扣至0、累计消耗300、容量升1级；UI下级价格1000 | 容量10，实际1/10；被动effective=false不影响容量生效 |
| 最高等级 | 容量3级、RP2000，max=true、按钮对象隐藏；强制调用原按钮仍拒绝 | 容量30，实际1/30 |
| 等级不足 | 原rank0、TimeStop17未学、RP1000，mask=true；原按钮拒绝 | 等级/RP不变；没有进入rank7成功路径 |
| 前置未满足→满足 | AutoSlow9被Slow6=0掩码拒绝；同一面板先50购买Slow，原父回调立即清除同一AutoSlow视图掩码，再200购买 | RP250→200→0、两技能各1级、AutoSlow缺键自动启用；消费者后本档RP倍率约0.64 |
| 被动缺键 | NpcDirect7花100升1级，新增true键 | 实际OtherBuffDict[33].IsActive=true；切关/开后同步false/true |
| 被动预存false | NpcDirect7花100升1级，保留原false键 | 实际buff保持禁用；关/开/恢复false均与存档和重载一致 |

容量与Slow价格使用原资产MSkillMaxAccessoryNum/MSkillSlow记录的NextLevelUpRp；容量0级价格300，不能用通用MSkill.InitRp=10推断。本批同时核对活动视图的necessaryRp和原ConsumeRp实参。AutoSlow学满后界面necessaryRp=220且按钮隐藏，这是通用价格公式刷新结果，不代表实际支付220；实际支付为200。rank与通用前置记录沿用已标记为历史受控观察的元数据文件，正式运行再核对其掩码和支付结果，没有将历史观察改称本批原始资产字节。

原入口RVA：SkillPanel.Open 0x4e7d10、OnClickTab 0x4e6c70、Item.OnClickReinforce 0x4c4740、ConsumeRp 0x48ea20、RiseSkillLevel 0x48e1f0、父回调0x4e7490、切换回调0x4cecd0、被动变更0x48dae0、库存容量消费者0x4f2b60、RP消费者0x65ae60。9次按钮中5次成功，扣款/升级/父回调各5次；实际native顺序、价格、技能ID和按钮接收器均验证。父回调使前置视图直接刷新，无需重建面板。

开关共6次回调：5次由夹具在SetIsOnWithoutNotify后明确调用，另1次来自passive-false面板初始化（caller 0xb8d8be，早于夹具操作）。不能把初始化事件当作重复用户切换。自动启用2次，加开关6次，共8次被动变更。NpcDirect实际flat=-10、lastMultiplier=0，本档最终RP倍率约0.80→0.72；不同难度、装备和其他buff可以改变结果，不能外推恒定减0.1。

每组保存before/after后，合法扰动5种技能等级、补齐所有learned>0技能的false字典键、改变RP并重新运行消费者；原Load更换GameStateData根，再由消费者和真实面板读回。7组都恢复原目标等级、RP/累计消耗、字典键presence与bool值、容量以及buff/RP缓存；14份解码还核对全部技能键，排除未选技能被改写。Active辅助函数仅在键存在时调用原IsActivePassiveSkill；Slow/容量是非toggle技能，其effective=false不是能力无效判据。

prepare先Save/Load脱离原全局根，保留原CurrentRank引用。cleanup记录全局根、rank引用、玩家字段、计算器缓存与43个buff字段均已恢复，stop=false。9份UserData、4份既往自然档、5项引擎/资源保持原指纹；存档路径限于本批working-profile。全部批次退出后统一复核两份原插件指纹，且无额外插件DLL；最终状态见post-state.json的plugins_finalized/plugins_restored。

失败诊断独立留存，不计入7组成功：20261030-1在prepare前触发case，夹具守卫拒绝；20261030-2的非法扰动让已学习NpcDirect缺开关键，原消费者抛KeyNotFoundException，捕获3439条引擎异常，随后cleanup成功并正常退出。该轮Frida关闭迟滞，没有最终返回结果，进程退出界定采集结束。正式v3增加合法字典前提和安全Active读取后才成功。diagnostics.json及diagnostics-rea.json绑定这些失败数据及原错误源码。

正式会话dfe861aa-0082-4de9-be89-7e8e006e1b71、PID72824；load Evidence ev_ce7d5401050ae2fead9f88e7a3ac36cb4a9a8b24c7480ed969e556bfa67899d0，status ev_6a159de54c712a31a08cf3623fbfa0dc99d373c6b811808fdd7a2bc6167f0610。保留REA返回的provider authority和subject缺失限制；受控来源由夹具、活动视图、编排日志及文件指纹补充，不改写工具权威级别。入口钩子仅覆盖标记区间，数量不代表进程全生命周期调用次数。

离线重跑：collect.py → analyze.py --inputs → unittest discover。25项测试包含计数、原生嵌套顺序/实参/真实view接收器、资产tier价格、字典键presence与false区别、实际库存/buff、存档恢复及失败批次隔离。待全部批次退出，执行collect.py --finalize-plugins，再analyze.py --inputs --require-finalized-plugins更新results，最后重跑测试；首次finalize会将pending改成true，不应立即用旧results作--check。自然鼠标、自然升rank7、库存恰好达到上限时的拒绝和冷标题重建仍待验证。
