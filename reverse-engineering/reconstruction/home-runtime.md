# 自宅菜单、自动保存与实际外观恢复

2026-11-03继续正式UnityProject，接入原电脑与衣柜交互、选定肤色消费者、关闭恢复及延迟保存取消。新增[原生合同](home-interaction-evidence/README.md)包含23条完整REA查询，两会话均正常关闭；原场景三处SphereCollider的对象范围、原始字节、类型哈希、Transform来源ID及启用状态独立解码。

## 已接入

- 原电脑1395／类型14与衣柜1396／类型11保持原节点位置、缩放和active状态。根据原合同补回半径约0.4、中心(0,0.45,0)的Sphere触发器；电脑原缩放约0.63保留。F复用现有候选／CharacterController触发分派，动作忙碌、菜单打开及同帧重开均有守卫。
- [HomeMenuController](UnityProject/Assets/Runtime/HomeMenuController.cs)提供替代菜单。电脑按钮通过SaveCurrent写独立JSON；衣柜接入已证实SkinPattern0/1的主色，在原body槽1／face槽2的替代Standard材质上实际应用，并在冷加载重新应用。
- 衣柜退出根据原18641委托保留5帧后自动保存；保存失败保留菜单和输入锁以便重试。组件禁用／销毁会取消协程、清关闭状态并恢复原输入；代次校验防止旧回调保存或关闭新菜单。菜单打开及关闭队列期间禁止F5／F6绕过菜单守卫。
- 菜单期间非零移动输入不调用CharacterController.Move，关闭后普通移动恢复，Animator移动参数归零。正常manual／home流程排除刻意摆放的钥匙测试夹具；专用interaction测试阶段仍可使用它。

原床1397／类型13的GameObject为**inactive**，保持原状态。REA已确认睡眠的Morning／Night选择及纯黑点IsDaytime变更，还涉及任务、生命、掉落、NPC与广播；自然启用生产者未证明，当前不创建虚构小时／日期，也不启用一个不完整的睡眠消费者。

## 验证范围

本机新Unity构建在进入编译前退出198，明确提示`No valid Unity Editor license found`；随后指定的6000.6.7f1编辑器目录也不再存在。已向用户请求恢复安装及授权。**本轮没有完成新的Unity编辑器构建。**

为继续验证自有代码，[prepare-home-host.py](prepare-home-host.py)使用本机.NET Roslyn对归档Unity6播放器引用编译，复制之前已验证的formal-20261103-1独立播放器。256个文件中只替换自有Assembly-CSharp.dll和自有interactions.json；原生播放器、资源和其余文件逐项SHA保持一致。没有修改Editor授权代码或原GameAssembly。包内旧build-proof仅代表宿主历史构建，不能当作本次Editor构建。

| 最终Host3实际验证 | 结果 |
| --- | --- |
| 受控进程10360、冷进程35448 | 各自GUID，两进程退出码0，意外引擎错误0 |
| 电脑／衣柜 | 5个菜单周期均由真实CC触发及共享模拟F进入；锁内有非零方向输入；前四个菜单关闭／取消后观察到实际CC位移，最终电脑保存后明确保持姿态 |
| 中断关闭 | 258帧取消衣柜保存队列，265帧复核，实测7帧无保存／自动保存／操作，revision维持1；之后可重新打开 |
| 正常衣柜退出 | 274→279、289→294，均精确5帧，revision分别2／3 |
| 最终电脑保存 | revision4，预设1；保存SHA `861a240e847ca554d25133bf30d0676a6e8ce90c14a9e28d8ba064d0bbb86cab` |
| 冷恢复 | float32位置和Quaternion逐项精确；运行内存预设1及实际身体／脸部材质主色与独立原主表一致 |

[最终生命周期档案](home-lifecycle-runtime.json)与46份公开回执由独立校验器核对；[前一轮Host2](home-host-runtime.json)保持历史原样。单独钥匙回归进程47428正常退出且自身原动画事件／恢复自检通过；原分析器因新增多个注册目标仍按旧单目标门槛拒绝，拒绝记录保留在`home-key-regression/strict-rejection.json`，未将其写成完整独立接受。

首个宿主尝试抓到JsonUtility将缺省visual创建为空对象、旧分支误把原交互节点位置归零的问题，修复后以非空bundle明确识别夹具；失败日志和退出码另列。随后审查发现禁用组件会留下延迟协程，修复并增加上述真实取消／重开验证。11项合成反例只验证分析器，不冒充运行证据。

## 保留边界与后续

替代OnGUI菜单没有恢复原UI素材、PC关闭动画、BasePanel一帧委托／动画结束销毁或衣柜预览相机。衣柜本轮只接肤色0/1主色，不等于所有衣装、所有权、阴影色、纹理、体型、骨骼和物理图已恢复。原shader、5处未解析builtin、物品／技能／NPC／完整任务及场景往返仍待补齐。全部按键为明确的受控输入，未证明实体键盘；床自然可达及完整睡眠效果继续待验证。

恢复指定Unity版本及授权后，优先运行正式工程新构建，再对该构建执行相同菜单／冷恢复验收；新的正式构建collector保持原硬门槛，没有用宿主结果替代。

```powershell
python -B -X utf8 reverse-engineering/reconstruction/verify-home-lifecycle.py --inputs
python -B -X utf8 reverse-engineering/reconstruction/test_home_runtime.py
python -B -X utf8 reverse-engineering/audit.py
# 恢复Unity安装与授权后，关闭该工程编辑器，使用新名字：
pwsh -NoProfile -File reverse-engineering/reconstruction/unity-project.ps1 -Action Build -RunName formal-home-new
```

正式构建后的入口为`run-home-runtime.ps1`、`collect-home-runtime.py`和`verify-home-runtime.py`。当前Host模式由独立的host／lifecycle工具记录，两个范围不混合。原加密`.sd`及BepInEx没有被本轮运行修改；保存使用独立profile。
