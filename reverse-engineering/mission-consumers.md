# 任务进度、奖励、暖重建边界与原生结算

2026-10-30完成4组受控任务消费者对照和1次原生结算。14份新REA查询连接初始化、更新、奖励、管理器、结果面板及完成计数。正式会话98条消息未截断，0条脚本/引擎异常，13份加密快照独立解码，8项反例校验通过。

## 前置和适用范围

原自宅状态实际暴露标志为None，8个所选原任务均不满足条件。正例使用两份运行时ScriptableObject克隆，把所选任务要求从Front改为0；原资源文件及原主表对象不改。使用原MMissionOverrideRecord.Initialize(masterId,stage)，按stage*10000+masterId恢复正式任务键100000。Unity复制没有保留原运行时设置的Id/StageType，必须重新初始化。

实际Unity场景始终是Apartment。夹具仅在同帧的显式Update调用内将数据场景协调为Residence，然后恢复Apart；暂停负例同样仅暂设IsTimeStop。没有把它们称为自然场景切换、真实时间停止输入或原条件下任务完成。

各组均执行原Save、扰动、Load、MissionBase.Initialize、3次Update，再保存/加载、重建消费者并调用2次Update。每组的3份文件分别对应使用前、首次更新后、暖重建更新后；数据对象和消费者身份均核对改变。

| 条件 | 初始进度 | 首次3次Update | 暖重建后2次Update |
|---|---|---|---|
| unmet：保留Front要求 | 0.9999 | 不增长，不发奖励 | 不增长，不发奖励 |
| paused：要求0且暂设停止 | 0.9999 | 不增长，不发奖励 | 不增长，不发奖励 |
| near-complete：要求0 | 0.9999 | 达到1，再发一次性及按秒奖励 | 再发一次性及按秒奖励 |
| completed：要求0 | 1 | 发一次性及按秒奖励 | 再发一次性及按秒奖励 |

## 如何区分正常持续奖励与重复一次性奖励

MissionBase.Update的返回地址0x479178进入一次性奖励分支，0x4794f2进入按秒分支；二者均调用MissionBase.RiseRp，再从0x479753进入GameStateFacade.RiseEarnRp。没有把浮点寄存器误作arg1指针解析；金额由实际数据增量和静态数据流独立核对。

所选原奖励10，实际RpBonus约0.8，一次性部分约8。每次持续增长符合deltaTime*RpPerSec*RpBonus，本轮RpPerSec为0.1。near-complete第一步只达到1，下一步才处理一次性奖励；同一对象后续只增加按秒部分。多次显式Update位于同帧，不能把这种增长当作自然每帧采样，也不能误报为重复一次性奖励。

保存后的MissionSatisfyDict和MissionEarnRpDict恢复正确，但新建MissionBase的运行时IsDoneOneCompleteProcess重新为false。受控重建已完成任务并再次满足更新条件后，一次性分支确实再次执行。它说明重建必须考虑运行时完成标志和自然生命周期，不证明普通标题读档或自然往返场景能刷取奖励；正常结果结算会清理进度和收益，相关自然到达条件仍待验证。

## 待结算收益、钱包与完成计数是不同步骤

RiseEarnRp只增加CurrentEarnThisTimeRp和StatistisTotalEarnRp，同时MissionBase记录MissionEarnRpDict；它不会立即增加CurrentRp，也不会完成AchieveMission。四组更新中钱包及完成计数均为0，不能把“发奖励方法已进入”视为已结算。

最后沿用启动时创建的原MissionManager，重绑其中选定任务的保存进度，再调用原ResultPanelView.OpenIfNeed。原Initialize进入AchieveMission(100000)，调用返回地址0x4c7977；完成计数0→1。约16.0070974待结算收益按原生整数转换成为16 RP、16经验；进度、任务收益和待结算收益均清零，总累计收益保留。独立解码结算快照与上述运行数据一致。

这是原生结算初始化对照，未覆盖自然返家按钮、结果动画、玩家确认或重复打开结算面板。观测用的独立任务原型不在原管理器列表内，结算后仍保留其自身Satisfy=1；清零对照针对保存字典及原管理器处理流程，不能把原型字段也报告为已自动同步。

## 失败记录与收尾

前六轮分别保留：无满足条件候选；克隆未初始化导致Apart守卫阻止更新；使用错误层级ID的预检；替换整个管理器并批量钩住Reset后在结算重置中退出；空Nullable包装器快照异常；过早Continue引发的MHair初始化异常及2703条已保留HatOffset错误。崩溃Windows事件显示coreclr.dll、0xc0000409，根因未证实，不能据此判断原游戏有结算缺陷。

正式轮从新进程开始，先在Unity线程只读检查AssetReferencer和MHair已就绪，沿用原管理器、缩减批量钩子，全部对照与结算正常返回。原任务字段和临时状态执行回写；全局引用和applier标志核对恢复。进程正常退出、REA关闭、原插件恢复；9份UserData、4份前轮自然档及5项引擎/资源输入指纹不变。

静态绑定见[salt/evidence/mission-consumers-chain.json](salt/evidence/mission-consumers-chain.json)，脚本、独立投影、失败日志及校验见[runtime/mission-consumers](runtime/mission-consumers)。正式会话588dd000-6ec3-427a-81bb-2d0d275ecff0，PID75008；加载Evidence为ev_5e3f3a27fb9da50ed8de0fd3ec8991b4ea74a261483333be6dce9ac1ddf4ebcb，最终状态为ev_1b75b4499445bacf6e2e126c5c0ceba80ff9035b703dd03b2111417f702cb2aa。
