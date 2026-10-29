# 读档后的实际模型缩放、动画速度与下一帧接收器

2026-10-30，优先级第3项继续补运行消费者。独立完整副本完成3组受控原生Save→Load→原玩家初始化回调；各保存CustomizeHeight=120/160/200，再故意改成137后读回。独立解码3份实际加密档确认保存值；139条未截断REA消息连接原始保存、加载、广播、五类外观接收器和下一帧骨骼回调。没有将手工调用初始化回调当作自然标题/界面触发。

| 保存身高 | HeightScale | 实际avatar.localScale三轴 | MoveSpeed与动画baseMoveSpeed |
| --- | --- | --- | --- |
| 120 | 0.75 | 0.90000004 | 1.1764705 |
| 160 | 1 | 1.2 | 1 |
| 200 | 1.25 | 1.5 | 0.8333333 |

复用原REA查询：`OnChangeBody`14602以保存身高/160计算HeightScale，乘实际defaultBaseScale后写Transform；MoveSpeed按HeightScale≤1取0.6、否则0.8的分段公式计算。初始化回调14769先广播ChangeBodyEvent，再把该速度复制给PlayerAnimationManager。两侧实际值与逐步float32计算一致。加载返回时模型缩放仍是上一状态，原回调之后才改变，不能把恢复数据与恢复表现混为一步。

每组各有一次玩家原回调、广播、身体/材质/脸部接收器；12个实际PlayerBoneScaleAdjuster均有一次订阅接收及下一帧回调，指针集合一致，没有同帧执行或重复项。清理恢复原身高160时，另有12次下一帧回调。原14632将延迟帧数设为1；实际时序分别4353→4354、7043→7044、7050→7051。

模型下有22个HairCustomAdjuster，只有2个isInitialized=true；每轮原生调用恰好落到这两个对象。未初始化的20个组件没有回调，不能据此判断漏发。

边界：本轮只改变身高。虽然材质、脸部和头发接收器均实际执行，颜色、贴图、脸部权重及其余自定义字段没有做数值等价验证。12个骨骼target的localScale均为单位向量，因此非单位缩放的逆尺度分支仍待覆盖。没有完成全部66个外观字段、物理效果或自然读档入口的等价性。

5项校验测试通过；选定范围内无引擎Error。原外观、applier与全局引用恢复，副本正常退出、REA会话关闭、原插件恢复。9份UserData、4份前轮自然档及5项引擎/资源输入保持指纹。证据见[runtime/appearance-restore](runtime/appearance-restore)。

```powershell
python reverse-engineering/runtime/appearance-restore/test_analysis.py
python reverse-engineering/runtime/appearance-restore/analyze.py --check --inputs
python reverse-engineering/audit.py --inputs --write-index
```


后续[外观细项报告](appearance-detail.md)补齐了选定颜色/脸部与非单位骨骼目标，并实测LateUpdate发出时DelayFlame(1)可在F+2执行；本报告的F+1结论仍限于原Update阶段夹具。
