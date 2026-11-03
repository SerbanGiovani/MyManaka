# 原自宅交互与菜单合同

本轮静态合同复用已有REA交互／保存证据，补充冻结Apartment原始触发器解码和23条REA/Ghidra查询。没有启动原游戏，没有写原件或原存档。`contract.json`可供独立工程消费；界面文字是重建标签，未声称恢复原本地化文本。

| 交互 | 原类型 | GameObject ID | Transform／重建sourcePathId | Collider ID | 原路径 | 原activeSelf |
| --- | --- | --- | --- | --- | --- | --- |
| 电脑 | 14 | 391 | 1395 | 2185 | Level/InteractArea (2) | true |
| 衣柜 | 11 | 392 | 1396 | 2187 | Level/InteractArea | true |
| 床 | 13 | 393 | 1397 | 2186 | Level/InteractArea (1) | **false** |

三处为同哈希SphereCollider类型，半径float32约0.4、中心`(0,0.45,0)`、enabled／isTrigger为true、Layer0、include／excludeLayers0。电脑局部缩放约0.63，其余1。合同保留精确float32转double值、原局部变换、父Transform1086、三个组件的原始字节／对象范围／SHA及类型哈希。`sourcePathId`是Transform身份，不能拿GameObject391／392／393代替。

## 派发与关闭

已有`InGameUiManager.OnInteract`方法15848，Evidence `ev_134aba30b9e251964ead8406bec81bc989e90bd1546e85d47828a1ee5c345139`，明确11→Closet.Initialize、13→SleepSelect.Open、14→PC.Initialize。已有`PlayerMiscProcess.OnUpdate`14908及原InteractManager合同表明：按键边沿、当前候选、动作可交互守卫成立后广播；三处序列化`CanInteractWithAction=false`。

新15849 `InGameUiManager.Open`克隆原UI prefab、设置关闭委托，置管理器`+0x23`并延迟2帧处理后续；原生UI动画、全部焦点及输入恢复不能仅凭一个bool替代。

PC的17593 `OnClickClose`（`ev_41accad3d80b7b45f9720487937d028dbcc87b1b5a791e47de3598a5026b8cb6`）检查`BasePanel.isAlreadyClose@0x40`，安排1帧关闭委托并置原UI Animator trigger。19049关闭委托（`ev_522fa5e9afae051163118bac18c8707ad257229e09a62f0b081dd3160ae43d1e`）调用onCloseBase及onClose；19043 `OnAnimCloseEnd`另行Destroy GameObject。逻辑关闭与UI对象销毁是不同时间点。

电脑17594 `OnClickManualSave`复用证据`ev_56afd6f99b1191d00614efeac8e5ddddadf02bfd05aa4c976fa6290d5abdd208`：原参数为`Save(3,-1,false)`。该原调用与独立工程JSON保存必须区分，合同不授权重建程序写原`.sd`。

## 衣柜

18630 `Initialize`构建原衣装记录与菜单项，并初始化CustomizeMenu。18632 `OnClickItem`（`ev_62f856cac0795c80ffab586493d223d058f9c9319985301712eb94ba9e69e879`）比较当前衣装记录，不同才调用PlayerFacade.ChangeClothes，随后刷新衣装UI，并在相关条件下Collect对应掉落。此合同未导出完整衣装所有权／类别、全部外观应用、界面素材或相机行为。

18638 `OnClickBack`先隐藏子面板，延迟5帧执行18641（`ev_b422a4808b0592222599695a36d8962fe601877651e87c2fbd7578f51a1de6f5`）。该委托恢复HUD／衣柜灯／LookAt等，**调用`Save(3,-1,false)`自动保存**，恢复相机／骨骼与外观，然后请求BasePanel.Close。因此独立实现若即时关闭、没有相机预览或省略自动保存，必须明确列为替代／缺口。

## 睡眠

字段名由原metadata及已校验native字段偏移表交叉绑定：GameStateData.IsDaytime@0x20；SleepSelect.currentUntil@0x70；SleepBlack.is24h@0x60、isKillTime@0x61。

18838／18839分别将currentUntil设为0（Morning）／1（Night）。18840确认睡眠时计算is24h并设isKillTime=false：

| 当前IsDaytime | 选择 | is24h | 纯黑阶段后的IsDaytime |
| --- | --- | --- | --- |
| false | Morning(0) | false | true |
| true | Morning(0) | true | true |
| false | Night(1) | true | false |
| true | Night(1) | false | false |

实际变更在17519 `OnEnterPureBlack`（`ev_1795ad7c4722bdf1b99156796e76eaeee240fc025ef25d0a7128c5a87f103d78`）：只有is24h=false才取反IsDaytime，随后ChangeLighting、StageController.UpdateByDaytimeNight。该函数还清理选定掉落、清IsDroneNeedCharge；普通睡眠重置任务、恢复生命、重生NPC并广播。**没有据此虚构原游戏的小时或日期计数字段。**17520动画结束再广播恢复、清IsOpen及输入状态并安排1帧延迟回调。

床的原GameObject当前为inactive。对level1全部MonoBehaviour原始字节的PPtr形候选扫描只命中ES3引用管理器与该对象自身所属脚本；它不排除字符串查找、跨场景或其他运行时引用，**未证明床的自然启用生产者／自然可达条件**。独立工程应保留原inactive；若为受控测试临时启用，须与自然玩法明确区分。

## 文件与复查

- `extract_contract.py`：从冻结原件按匹配类型哈希解码，生成合同及选定metadata字段布局，不执行原程序。
- `contract.json`：三处目标、原始对象与字节来源、复用证据、新23条Evidence、关闭／衣柜／睡眠调用范围与unknown。
- `../../salt/evidence/home-ui`：15条查询，131.636秒，导出成功且会话关闭。
- `../../salt/evidence/home-ui-tail`：8条查询，126.258秒，导出成功且会话关闭。

```powershell
python -B -X utf8 reverse-engineering/reconstruction/home-interaction-evidence/extract_contract.py
```

这里只建立静态合同；原UI素材／Animator事件接线、完整动作守卫、所有衣装和外观消费者、床自然可达及完整睡眠副作用均不能因此宣称已在独立工程实现或验证。
