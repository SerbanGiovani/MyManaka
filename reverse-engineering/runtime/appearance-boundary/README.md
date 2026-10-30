# 持久 BodyPaint 受控夹具，待主线程运行

当前仅编译，未安装或运行。不要把本目录视为运行成功证据。自然主线采集进程由主线程管理，此构建不得改写该进程已加载的DLL。

```powershell
& 'C:/Program Files/PowerShell/7/pwsh.exe' -NoProfile -File reverse-engineering/runtime/appearance-boundary/build.ps1 -EmitOnly
```

`-EmitOnly`只输出本目录`.cache/AppearanceBoundaryProbe.dll`；省略该参数的安装分支会拒绝活动测试进程、现有同名或隐藏旧DLL。安装与启动由主线程统一执行。

启动前准备全新`E:\ManakaREA-NaturalGameplay\AppearanceBoundary\<run-tag>\working-profile`，其中必须有`SaveData/1.sd`；私有槽应与该次新玩家的标量外观一致。默认run-tag为`20261030-1`，也可在新进程环境中设置`REA_APPEARANCE_BOUNDARY_RUN`。已有managed.jsonl会拒绝启动，日志不覆盖。

命令写入运行目录`command`：`ready`只读检查AssetReferencer/MHair与活动场景；确认ready及Title后才`boot`、再`continue`，进入Apartment后`prepare`。先确认prepared且无runner_error，再逐次执行`case tattoo`、`case oil`、`case combined`，每次等待result后再下一个；最后`cleanup`并等待cleanup事件。可复用主线程的原生只读REA观察器，标记前缀是`REA_APPEARANCE_BOUNDARY_BEGIN:`和`REA_APPEARANCE_BOUNDARY_END:`。

三个条件都先从私有baseline原Load，清空10种开关后设置TattooDark2/BodyOil8；其余颜色、头发及计时涂料不属本批改变范围。`prepare`要求RubberSuitDummy inactive、remain=0、reusable=false、计时controller state0；不满足应换新副本profile，不要临时把它们伪装成自然条件。

阶段为reference immediate→10帧结果/原Save→反转2/8开关并原广播扰动→10帧结果→原Load且先读取未应用表现→原30_0广播→10帧结果。只有字段恢复不算材质恢复；材料新实例指针不要求等于原资产指针。日志保留sharedMaterials槽序、shader、主纹理和MatCap/Base/Shadow颜色，实际保存副本位于captures。

原global根在任何字典写入前先经Load脱离；原共享材质数组、原材质颜色/主纹理/透明度、三个控制器材质引用、计时controller及SmoothFloat字段单独备份。cleanup先恢复原根并广播，等待10帧，再精确回写上述数组/值并核对根、槽位指针和applier标志。失败会记runner_error，不能继续把该轮作为成功样本。

自由肤色false/预设分支暂未混入这三个条件。独立小批可使用`MCustomizeColor.Instance.SkinPattern[index].BodyPrimary/BodySecondary`作为原生预设基准，设置CustomIsSkinColorFree=false、CustomizeSkinColor为合法索引0/1；用自由RGB作扰动，随后Save/Load/原广播对照。还需先独立核对Body与Face材质接收器，不能从本批BodyPaint结果外推其覆盖。
