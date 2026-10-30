# 真实键盘、原移动Animator及保存重启

2026-10-31已在独立Tuanjie工程接回原Player控制器、ManustiaAvatar和Locomotion移动层。正式人工输入经过Unity键盘读取、CharacterController与原动画混合树；F5保存后继续运行，F6保存并退出，再由新进程读回同一份独立JSON。正式构建0错误、0警告，两个进程退出码0。

本机程序为`.cache/locomotion-20261031-3-build/ManakaLocomotion.exe`，编辑工程为`.cache/locomotion-20261031-1`。源模板位于`locomotion-project/Assets`。旧minimum工程和历史模拟轴结论保持原样，本轮结果单独归档。

## 原控制器及接线依据

[原资源与原生证据](locomotion-evidence/README.md)包含23次新REA查询、metadata绑定及原PE小窗口字节验证。大函数Ghidra listing的一字节覆盖限制和空结果明确保留；最后的浮点参数接线由实际指令字节补证，不以空listing推断运算。

- 精确节点为Player预制体的`Manustia`，原控制器Player、原Avatar为ManustiaAvatar，175个片段、40个参数、12层。运行时保留原控制器／Avatar引用，记录source与copy实例ID相等。没有复制原游戏行为脚本；原控制器的StateMachineBehaviour集合为空。
- Idle／Walk／Jog是同一个`Locomotion.LocomotionTree`，fullPathHash为686120411。原Speed阈值0／1／2分别混合Female_Idle_Base、Female_Walk_Forward、Female_Jog_Forward，不能写成三个独立状态。
- 动画目标为解析输入模长乘以普通1／跑步2，动画Speed按5×dt趋近；世界基础速度为walk1.1、jog2.4、crouch0.6，按10×dt趋近。LocomotionMotionSpeed设为1。原蹲姿动画目标仍为1，其混合树在0.5处已饱和。
- 新FootL(int)／FootR(int)接收器记录原片段事件，尚未重建原脚步音效。RootMotion关闭，世界位移由CharacterController负责。

本轮只启用原Locomotion层，其他11个动作、衣服、手臂及脸部层权重设为0；C切蹲已接线，正式人工验收主要覆盖普通移动和跑步。原横移、自动追踪、体力、特殊动作及完整状态守卫未恢复。转向、重力、Update积分及相机仍有明确的重建取舍，不能外推为原玩法等价。

## 正式人工记录

用户在窗口Manaka Locomotion REA完成WASD、左Shift跑步、松键、F5及F6操作，并回复“完成”。Unity只能记录键与轴，物理来源另由用户确认；没有把系统注入或旧模拟轴冒充实体键盘。人工回执和逐帧数据见[运行目录](locomotion-runtime/keyboard/input-receipt.json)。Computer Use的窗口控制曾被用户Escape停止，之后未再用它发送按键。

|项目|正式结果|
|---|---|
|键盘与实际位移|PID92812，670个有移动轴的采样；CharacterController水平路程约17.19689米，没有模拟轴帧|
|原动画|同一原混合状态内观察Idle→Walk→Jog→松键Idle；原clip实例、权重、Speed、动画时间和非root局部骨骼变化共同核对|
|等待区间|失焦的纯Idle等待单独排除，不计入实体键盘证据；有效操作区间保持焦点|
|保存|两次F5命令，另一次无键盘命令的保存，最后F6保存；共4次成功提交。额外保存不冒充F5，备份只证明相邻revision3|
|重启|PID31928及新Guid读取同SHA的revision4，场景、位置与Quaternion一致；在物理启用前核对，随后原Animator继续初始化|

最终位置`(1.06375253, 0.00009971857, 0.580546)`，Quaternion`(0, -0.287608564, 0, 0.957748055)`，存档SHA256为`c4aba839937c1c02300b565e11b510dc3931f1c8f68bbb85062382f928545c92`。库存12项、选定外观及涂料字段仍保留；它们的原效果没有在本独立循环中实现。

## F5误退出与修复

首轮人工测试PID90236确实在F5后退出码20：JSON已经生成，随后的严格往返校验失败，测试模式将它当致命失败退出。该轮没有F6和成功保存回执，作为失败保留，不能合并为正式通过。

引擎probe先对失败文件及9974个有限浮点值逐项读取，未见非零精度损失。加入显式负零后，JSON将位模式80000000写为普通零；连续360次逐步转向又复现65次同类零符号变化。原失败轮没有记录源位模式，因此不能追溯断言具体哪个分量含负零；控制重放和该诊断限制均保留。

修复只在存档数据中规范化-0为+0，不改变角色Transform或数值。其他浮点位继续严格相等，并在写临时文件、原子替换前完成校验；保存事件记录源／规范化／磁盘8字段位图及修改次数。362组实际写读回归全部通过，其中66组含负零、规范化67个分量；原minimum和失败轮JSON均由新版TryRead实际读取。正式人工这4次保存的零符号修改数均为0，不能声称它们本身覆盖了负零条件。

F5失败现在保留窗口并显示错误；F6失败会解除退出锁并恢复操作，便于重试。本轮F5成功后继续操作、最终F6正常退出的记录闭合了用户反馈的问题。

## 验证、范围及复现

[完整清单](locomotion-runtime.json)绑定源码、原始输入、构建306个文件和归档；[独立验收](locomotion-acceptance-tools/acceptance.json)重新核对输入、原引用身份、动画、位图、存档及进程生命周期。REA还检查了实际构建的Mono CIL程序集。

原资源仍部分兼容：269个绘制、33个碰撞、90张纹理和4个玩家Renderer；每进程1228条缺脚本警告、11个Standard玩家替代材质、5处未解析内建网格，原生日志另有6条Shader错误。回调error0不代表完整兼容。原GameAssembly和BepInEx不在独立程序包内，完整动作、NPC、任务、交互与外观逻辑仍待补齐。

```powershell
./reverse-engineering/reconstruction/check-editor.ps1 -RunName locomotion-new
./reverse-engineering/reconstruction/build-locomotion.ps1 -ProjectRun locomotion-new -BuildRun locomotion-new
./reverse-engineering/reconstruction/run-locomotion.ps1 -BuildRun locomotion-new -RunName keyboard-new -Phase keyboard -InputOrigin physical-keyboard
# 正常完成键盘测试、F5与F6后再启动新进程：
./reverse-engineering/reconstruction/run-locomotion.ps1 -BuildRun locomotion-new -RunName keyboard-new -Phase phase2 -InputOrigin physical-keyboard
python -B -X utf8 reverse-engineering/reconstruction/verify-locomotion-runtime.py --inputs
```

手动常规运行可直接双击程序，新建或继续独立进度。WASD移动、左Shift跑步、C切蹲、右键拖镜头、F5保存、F6保存退出。使用新的RunName／BuildRun保留已有日志；原数据从已校验桥接资源与seed打包，不改原游戏文件。
