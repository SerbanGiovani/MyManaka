# 发型、纹理、RGB与阴影恢复及已有模型的初始化边界

2026-10-30在全新隔离profile完成3组受控保存、扰动、加载及头发消费者对照。新增5份非空REA查询，连接UI换发入口、PlayerFacade、PlayerHairController.Initialize/ChangeHair和HairCustomAdjuster初始化。178条REA原生消息未截断，无脚本/引擎Error；8项反例校验通过。

## 数据与实际材质

从21条HairCustomizeDataDict记录选发型0/1，分别改变TextureId、R/G/B和ShadeColor。三个加密文件独立解码；CurrentHair、两条选定记录的所有字段与原生Load后对象一致，custom对象身份更新。纹理指针与实际MHairRecord.HairTextures[TextureId]逐项对应；每个当前发型的两个已初始化材质都实际应用。

| 条件 | 保存发型 | RGB | ShadeColor | 直接Load+Initialize后启用模型 | 显式协调后的模型 |
|---|---|---|---|---|---|
| negative-shade | 0 | 32/96/224 | -100 | 1，与保存值不符 | 0 |
| positive-shade | 0 | 210/60/100 | +100 | 1，与保存值不符 | 0 |
| alternate-hair | 1 | 32/96/224 | -35 | 1 | 1 |

纹理ID均为1；发型0有7项实际纹理引用，发型1有2项。实际基础色符合RGB/255，最大偏差小于4.9e-8。阴影结果既与保存前原生应用基准一致，也与独立HSV计算一致，最大偏差小于1.2e-7。独立计算按原查询中的饱和度增强、亮度乘0.9、正负固定色相及abs(ShadeColor)/100夹限混合执行；不从测试结果拟合系数。

## 为什么默认发型在已有对象上没有恢复

原`PlayerHairController.Initialize`14858先保存pca；当PlayerCustomData.CurrentHair为0时直接返回。非0时只关闭默认模型0，再调用ChangeHair。`ChangeHair`14859根据当前保存值选择要关闭的模型，然后启用next并更新CurrentHair。它没有独立跟踪“读档前实际启用模型”的字段。

本轮先把实际模型切到另一个发型，再Load。Load已将CurrentHair换为保存值，但不会同时切换已有模型；默认0条件下Initialize直接返回，因此启用模型仍为1。原Body广播即使更新了模型0的材质，也不能代替模型启用状态恢复。两次默认0条件都保留为不匹配结果，没有伪装为成功。

随后进行明确的受控协调：读取唯一实际启用模型，暂将CurrentHair协调到该模型ID，再调用原ChangeHair(保存目标)，最后调用原玩家初始化回调。三组均只启用一个正确模型；材质、纹理和数据与基准一致。这一步是额外前置，不是原Load的自动行为。

该现象说明已有对象重放必须满足初始化前提，不证明自然标题加载有缺陷。自然冷启动创建新玩家/默认预制体的生命周期没有在本批重放。UI方法只做静态追踪；运行夹具直接调用原控制器，没有声称用户自然换发或价格/购买流程已经验证。

## 证据与收尾

静态绑定见[appearance-hair-chain.json](salt/evidence/appearance-hair-chain.json)，包含5次新查询及4份复用查询、原始签名、CurrentHair+0x104、HairCustomizeDataDict+0x118和材质字段。运行证据、独立投影、HSV计算、反例校验见[runtime/appearance-hair](runtime/appearance-hair)。

REA会话`d3d33481-07d0-4568-9520-a61398a1a5ce`，PID48184；加载Evidence`ev_dc31f0e398854cfe790631166f138858b9ab35e508661f180c024753a8fba70a`，最终状态Evidence`ev_517cda307fd48f07be7b05bc8fa10e055ce1ccbe50165a7b3423f724e76a8993`。OnEnable延迟工作和显式Body广播都可能应用材质，因此相同消费者多次进入不能直接算重复事件。

原头发数据、启用模型、材质、全局引用和applier标志均已恢复；副本正常退出、REA关闭、原插件恢复。9份UserData、4份此前自然档、5项原件/副本输入哈希不变。未覆盖其他发型、附加发片、身体贴图、物理效果或自然冷读档；库存/技能/任务实际消费仍按工作队列推进。
