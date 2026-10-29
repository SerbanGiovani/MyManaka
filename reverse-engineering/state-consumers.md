# 存档恢复后的库存与技能实际消费

2026-10-30在独立副本完成3组物品回调和3组技能17条件。19份新增REA静态查询连接库存按钮、闭包、效果、数量修改及技能学习入口；63条原生消息未截断，无脚本/引擎Error。7项完整性与反例校验通过。任务更新/奖励查询仅作下一批准备，不计入本轮运行结论。

## 库存回调、消耗与再次读档

每组先设数量2、经验0，原生Save；随后扰动为数量9、经验7777，原生Load恢复基准；调用实际创建的InventoryItemView.OnClickUse，等待30帧，再Save/Load。6份加密文件独立解码，数量和经验与原生对象一致，加载对象身份改变。

| 道具 | 原生标志 | 数量 | 经验 | 使用后运行等级 |
|---|---|---|---|---|
| 100002 DebugEarnExp | IsReusable=true | 2→2 | 0→1000 | 2 |
| 100003 DebugEarnExp2 | IsReusable=true | 2→2 | 0→100 | 0 |
| 0 Water | IsReusable=false、IsDelayConsume=true | 2→1 | 0→0 | 0 |

原生栈连接17925 OnClickUse → 库存委托 → 18007 UseProcess → 16071 UseItemProcess。效果调用返回地址为0x4f4389。UseProcess仅在非重复、非延迟消耗时先扣数量；Water跳过这一层扣减，由效果内部16794 ChangeItemNum(0,-1)扣一次，返回地址0x467bdf。没有双扣。可重复经验道具没有数量修改调用，并实际重算运行等级。Load本身未重算上一组遗留运行等级，因此表中只报告使用后的等级，不把加载数据视为全部运行状态已应用。

本轮Open使用标签索引1，物品视图实际activeInHierarchy=false；夹具从Unity LateUpdate直接调用其原生按钮方法。这证明绑定后的回调及保存状态消费，不验证可见菜单、自然鼠标点击、物品获得或确认窗口守卫。视图不可见这一事实已写入结果和反例检查，未隐去。

## 技能17从保存字段进入实际动作与动画事件

三组均保存等级/启用字段，扰动等级为7并反转启用，Load后再创建InputData，仅置JustTimeStop=true，调用原PlayerAction.OnUpdate。未直接调用ChangeAction或OnChangeTimeStop绕过动作守卫。

| 条件 | 读回等级/启用 | 原生动作7 | 动画事件 | 结果 |
|---|---|---|---|---|
| unlearned | 0/false | 0次 | 0次 | 请求被拒绝 |
| disabled | 1/false | 0次 | 0次 | 请求被拒绝 |
| enabled | 1/true | 2次 | 2次 | 首次停止、第二次恢复 |

启用组原生动作依次7→-1→7→-1；请求返回时状态仍未切换，实际动画事件之后IsTimeStop才改变。两个事件分别落在请求后的28、35帧，约0.4553、0.5817秒；这是两次采样，不能推广为固定延迟，也不能用请求时刻代替动画事件时刻。结束时已恢复false。

本轮学习通过RiseSkillLevel helper准备，CurrentRp一直为0。静态查询17530 SkillItemView.OnClickReinforce确认真正UI先检查RP、ConsumeRp，再RiseSkillLevel，并包含遮罩/解锁守卫。helper本身不收费，本轮没有把它当作自然付费学习成功，也未验证等级7解锁、轮盘/键盘自然输入。

## 证据与边界

静态绑定见[salt/evidence/state-consumers-chain.json](salt/evidence/state-consumers-chain.json)，运行投影、原生记录、夹具和校验见[runtime/state-consumers](runtime/state-consumers)。会话52ab9776-c9ce-43ea-94ec-a5d70b411133、PID51012；加载Evidence为ev_cbc145c04ebb49c93edca2a681d95353651e7dd1d90d1a9484709099b2c1b7ce，最终状态为ev_72545f6c857e03ae8b92f1dfe24f7604321dfe33a9b81dea5a07a86361d071f3。

前两次采集器试运行因字典枚举和MRankRecord字段名错误中止在消费前，完整诊断与归档DLL指纹保留，不混入成功统计。正式6组无runner_error。全局根引用、原运行等级引用和applier标志恢复；独立副本正常退出、REA关闭、原插件恢复。9份UserData、4份前轮自然档及5项引擎/资源输入均未变。其他物品/技能、可见UI及自然学习、任务更新/奖励与其存档消费者继续按工作队列推进。
