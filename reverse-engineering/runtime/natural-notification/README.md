# 完整游戏环境中的通知情景验证

主报告：[notification-scenarios.md](../../notification-scenarios.md)。`results.json`可由 `python analyze.py`重算，`rea-runtime.json`保留未改写的选定REA记录。

- e56ad9fb：纯观察，16次自然动画入口和16次回调；用户正常UI启用技能21。首次无效挂钩保留为已卸载诊断。
- 39f7977c：用户同意后的受控阶段。control.js预检1次停止/恢复和1次参数错误；control-v2在自宅无NPC时未启动；control-v3执行五情景×两轮。9条达到完整条件，10条均交付一次。
- a273ff37：control-v4保持远距离补测2条。两条与普通timeScale=0暂停叠加，恢复后同帧2→2广播，按组关联；二者都达到隐藏/远处条件。

直接受控调用原始OnAnimBaretaSound不是自然AnimationEvent。`observe.js`用于自然阶段；`observe-scan.js`在受控阶段直接扫描Scheduler中指向NpcAnimationEventReceiver的Action，检查队列membership后读取模型。它弥补NativeFunction调用下没有可用入口钩子记录的限制，扫描发现时间不当作精确入队时间。

`control-v3/v4`临时修改现场玩家位置、MeshParent激活状态，并调用原始OnChangeTimeStop，不直接写IsTimeStop。它们验证已排队的通知，不保证事件产生前的所有动画组合。源文件各版本按加载时哈希保留，不改写历史失败探针。`found-observe`旧版本的NPC字段不作为身份；v2直接取NpcController参数，其描述中的value-type是误标。

`collect.py`接收完整REA导出及显式session ID，保存每会话最完整且未截断的状态、文件加载记录、原生日志压缩件、输入/源码哈希。原始存档只校验哈希，不复制其内容到仓库。原REA工具卸载返回不进入证据账本；最终状态中的scripts列表独立显示诊断脚本已卸载。manifest的state是最后保留状态，closed_by_operator标记之后的实际detach。

actor状态变化上限2500条；单模型心跳上限2400条。已保存的状态变化计数不是全时段总数。预检错误、正式条件覆盖失败及补测都保留；`notification_contract_passed_trials`与`passed_formal_trials`分别表示交付数量约束和完整条件覆盖，不得混用。补测同帧广播只作组级数量对应。

复核：`python -m unittest discover -s reverse-engineering/runtime/natural-notification -p test_analysis.py`，再执行仓库 `audit.py --inputs`。本次12项回归测试，旧自然停止/恢复目录的9项测试继续保留。所有会话已detach，游戏保持运行。
