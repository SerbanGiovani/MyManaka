# 待运行的付费学习夹具

本目录只有已编译准备的夹具，尚未安装或运行。静态前置见../../paid-skill-boundary-plan.md。不能把编译通过当作UI或付费验证成功。

`build.ps1 -EmitOnly`（也是默认行为）只生成本目录.cache/PaidSkillBoundaryProbe.dll；显式-Install才复制到独立副本插件目录，且必须无测试进程、无旧同名/隐藏探针DLL。代理交付阶段仅执行EmitOnly，没有安装DLL或启动/附加进程。

运行时Root固定为独立游戏副本下PaidSkillBoundary/20261030-1。父线程应先建立未存在的本轮输出目录，将已保护自然profile复制为其working-profile，保持UserData和原profile只读；停游戏后按既有工作流归档NaturalLoadObserver、安装此探针。不要与自然采集插件争用SaveRoot。BepInEx依赖原NaturalObserver用于路径重定向，所有游戏调用只在Unity Update/LateUpdate执行；observe.js只读。

先发`ready`并确认AssetReferencer、MHair、MSkill和SkillPanel均就绪，然后`boot`、`continue`。进入初始化完成的Apartment后发`prepare`。prepare捕获原全局根、CurrentSaveSlot、Pca.PlayerState.CurrentRank、RP缓存、所有OtherBuff模型字段及计算器缓存，先原Save/Load脱离原GameStateData根，再允许配置矩阵。

按顺序各发一次，等待对应`case_result`后再发下一个：

- `case rp-low`：容量等级0、RP299，真实价格300，拒绝；容量仍5。
- `case rp-exact`：容量等级0、RP300，真实按钮消费300升1；随后打开真实InventoryPanel，读取原RefreshEquipCount文本、CalcEquipCount和CanEquipByMaxCount；分级记录MaxNum应10。
- `case max`：容量等级3、RP2000，视图max标志阻止，保持等级3/资金；容量30。
- `case prerequisite`：Slow0/AutoSlow0、RP250。同一面板中先点击被锁AutoSlow，再以50购买Slow，父回调自动UpdateMask，再以200购买AutoSlow。
- `case passive-absent`：NpcDirect0、100 RP且activation键缺失，购买应自动启用；实际Buff33由原RpBonusCalculator.OnUpdate处理。
- `case passive-false`：同样但预存false，购买应保留false。两个被动条件均随后打开真实SkillSwitchPanel，使用SetIsOnWithoutNotify配合一次原OnChangeToggle依次关、开，并恢复学习后状态；记录Buff33和最终RP倍率。

每组原Save before/after；关闭当前UI后再扰动钱包/等级并Load after，重新调用实际RP消费者，打开新的技能视图执行原Refresh/UpdateMask，记录`verified_ui`。最大等级和学习标志不手动清除，付费入口不替换为RiseSkillLevel helper。对UI的操作仍是明确受控回调，不能称为自然鼠标点击。

所有面板关闭后发`cleanup`。夹具回写原全局/等级引用、全部保存的Buff字段、RP与计算器缓存，并读回检查；正常退出、归档DLL、恢复原插件、校验原文件指纹由父线程统一执行。

注意：emit-only编译不会验证运行时字段可用、原Close动画是否完成或UI回调是否返回。每组首个runner_error都应停止后续矩阵、保留日志，不得重复写已加载DLL。rank guard本版暂未执行，候选AutoAddMoisture23的rank0/1和Perspective15的rank4/5另有静态方案。
