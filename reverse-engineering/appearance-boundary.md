# 剩余外观：两条 BodyPaint 链及受控验证方案

本文件只给出静态定位与测试方案。新增7次REA查询已完成，未附加/操作游戏进程、未修改原始存档、未执行材质或计时恢复测试。静态绑定见[salt/evidence/appearance-boundary-chain.json](salt/evidence/appearance-boundary-chain.json)，生成器为[salt/appearance-boundary-evidence.py](salt/appearance-boundary-evidence.py)。

## 覆盖口径

已有17字段的Configure始终令CustomIsSkinColorFree=true，包括扰动阶段；不能称已验证false/预设肤色切换。CustomizeSkinColor(+0x78)、CustomizeAdjustHeight(+0x110)未单独扰动。40个脸部通道只有少数实际改变，不等于40个外观参数独立覆盖。当前身高、17个指定字段、发型0/1及其材质不等于全部66字段的视觉/物理等价。

下一组优先选择BodyPaintTypeDict。随后补预设肤色分支、眼部贴图/眼型与其余体型；DynamicBone/碰撞/服饰物理仍需独立实际运行证据，骨骼逆缩放测试不能替代物理验证。

## 两条数据链不能混为一种

| 链 | 保存字段 | 原生消费者 | 核对对象 |
|---|---|---|---|
| 持久纹身、BodyOil、RubberSuit开关 | PlayerCustomData.BodyPaintTypeDict(+0x108)，键BodyPaintType、值bool | 14625 OnChangeBody → 14624 SetupBodyPaintFromGameState；14627 ApplyFromGameState | bodyMeshRenderer.sharedMaterials槽序、纹理、shader及MatCapColor |
| 临时物品涂料 | GameStateData.PlayerRemainBodyPaintTime(+0x17c)、IsActiveBodyPaintReusable(+0x1df) | 15011 Initialize、15012 OnUpdate、15015 OnUseItem、15016 OnUseWashItem | ClothesPaintMaterial、SmoothFloat.Current、currentState和剩余时间 |

PlayerBodyMaterialController：pca+0x10，SweatBodyMaterial+0x20，ClothesPaintMaterial+0x28，RubberSuitMaterial+0x30；静态shader ID为TweakTransparency+4、MatCapColor+8、BaseColor+0xc、FirstShadeColor+0x10、MainTex+0x14。实际renderer位于Pca.PlayerAvatarObjectReferencer.bodyMeshRenderer(+0x208)。

BodyPaintController：alpha为SmoothFloat引用(+0x10)，pca+0x18，currentState+0x20；SmoothFloat.Current+0x10、Target+0x1c。这些运行字段不属于PlayerCustomData的66个保存字段。

## 持久材质的最小三条件

BodyPaintType值已从原始metadata常量校验：Inmon0、Rakugaki1、TattooDark2、TattooFlower1/2为3/4、TattooLotus5、TattooSatanism6、TattooSlave7、BodyOil8、RubberSuit9。

1. 所有开关false、剩余时间0：记录原前两材质及末尾Sweat。
2. 只开TattooDark2：应在原前两材质与Sweat之间增加对应纹身材质。
3. TattooDark2与BodyOil8同时开启：槽数应与第2条件相同，但第2个基础材质的MatCapColor改为白色；关闭BodyOil则为黑色。两者alpha均1。

使用16769 GameStateFacade.SetActiveBodyPaint(BodyPaintType,bool)准备字段。它只写字典，不广播、不应用材质。每组执行原Save→实际扰动/原生应用→Load→记录仍旧材质→原PlayerController.Initialize_b__30_0广播→实际材质读取；不要重新调用14620 PlayerBodyMaterialController.Initialize，该方法注册事件，重复调用会重复订阅。

14625接收器同步调用14624，没有自身延迟。原骨骼订阅者可能在F+1/F+2运行，与身体材质同步应用分别计数。16305 RBodyPaint.SwitchVisible(int defaultType)先翻转IsEquip bool，再内联Setup逻辑；defaultType元数据参数在本体未使用。只观察0x637bc0入口可能遗漏内联路径，不能据此判漏调。若验证UI可达性，可直接记录SwitchVisible及最终效果，不能把SetActive当成自然点击。

读取sharedMaterials以免观测本身触发额外实例化；比较槽序、shader、主纹理及颜色。新实例材质不必与AssetReferencer原材质指针相等。14623 TransToMaterialAsset对8走抛异常分支，BodyOil应只经Setup特殊处理。初轮保持RubberSuitDummy inactive且剩余时间0；其active状态、限时ClothesPaint会额外插入材质，应另作条件。原前两个材质至少必须存在。

## 临时涂料的阈值及暖重建陷阱

15011 Initialize(Pca)不注册事件，按剩余时间设置：time<=0：state0/Current=-1；0<time<=24：state4/Current=0；24<time<=60：state3/Current=.25；time>60：state2/Current=.4。可选0、12、24、25、60、61、120作为边界，先由原Body广播建立材质，再单独调用Initialize重建alpha/state，随后OnUpdate核对实际TweakTransparency。

OnUpdate先按`remain -= 2*clamp(PlayerState.Dokidoki,0,.5)*Time.deltaTime`递减并夹限>=0；不是简单减deltaTime。Dokidoki位于PlayerStateModel+0x58，方法自身没有读取IsTimeStop。state2、3、4、1分别向alpha .4、.25、0、-1平滑；到达最后状态才再次Setup并转state0。OnUseItem把剩余时间设120、state2、Current1，且LastUseItemType(+0x228)==8时启用Reusable标志。OnUseWashItem只置time0/state4，材质移除仍由后续平滑过程完成。

若原controller为state0，直接Load正剩余时间再发Body广播，OnUpdate仍在state0提前return，不会自动进入painted状态。原Body广播只重建材质，不重建这个状态机。应分别保留直接暖路径结果和显式15011协调结果；自然冷创建的Initialize链需另测，不能称自然读档缺陷。

## 保护与清理建议

只在独立profile操作。先保留全局根引用，原Load出新对象后才改字典，避免原引用持有的字典也被污染。保存原renderer材质数组、MatCapColor、控制器三个材质引用、alpha/currentState及SmoothFloat字段；参考/扰动/恢复各读取实际效果。若限时测试跨帧，记录Dokidoki、deltaTime与实际减少量，或明确把Dokidoki=0作为受控前置，不能以静止不动代替计时为零假设。清理时恢复字典/根、材质、控制器引用和时间状态，再校验原UserData、前轮自然档及冻结输入指纹。
