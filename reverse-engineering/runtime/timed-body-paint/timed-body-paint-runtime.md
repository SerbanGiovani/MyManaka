# 临时身体涂料：倒计时、清洗与暖加载

2026-10-31正式批次`20261031-3`完成21组受控原生调用、17份保存密文及独立baseline解码。1607条REA消息无截断、无脚本或引擎错误；311次BodyPaintController.OnUpdate均有成对原生入口/返回，其中299次来自未注册克隆、12次来自原自动控制器。逐调用使用真实deltaTime、Dokidoki与原生浮点值重算倒计时、平滑及状态切换，所选对照通过。前两轮分别存在采集错误/清理未确认和备份覆盖缺口，均独立保留，不合并为正式成功。

## 原生克隆与隔离方式

夹具通过原构造函数创建独立BodyPaintController及SmoothFloat，使用真实Pca，但不将克隆注册到Pca或更新列表。原Pca.BodyPaintController引用保留，原控制器临时设state0/Current=-1，真实PlayerState.Dokidoki在帧间保持0；仅同步调用克隆OnUpdate期间设置目标值，finally立即恢复0。初始正remain=120的五帧窗口直接记录6次原自动更新返回，数据、平滑及状态均未变化；cleanup窗口另有6次同类返回。

IsStopGameStateApplier=true只用于避免保存状态回写漂移，不是OnUpdate调度守卫；测试期间时间停止标志始终false。所有游戏方法在Unity线程执行，REA观察器只读入口/返回及字段。本批没有触发自然物品界面、三秒延迟生产者、动画事件或自然冷标题读档。原生入口与真实材质消费者可用于重建对照，不能把未注册克隆的显式调用说成自然更新路径已验证。

## 初始化、计率与真实跨界

| 保存剩余值 | Initialize后的state | Current |
|---|---:|---:|
| 0 | 0 | -1 |
| 12、24 | 4 | 0 |
| 25、60 | 3 | 0.25 |
| 61、120 | 2 | 0.4 |

七种值另加120/reusable=true组成8组初始化条件。Initialize只写pca、state与Current；没有把Target或平滑速率也算作初始化结果。随后显式OnUpdate才核对实际材质透明参数。SmoothFloat构造值Current/Target为0，上下速率约0.075，isLerp/isUnscaled为false。

独立计算使用`remain=max(0,remain-2*clamp(Dokidoki,0,0.5)*deltaTime)`，并逐步按float32舍入核对原生返回。Dokidoki0、0.25、0.5、0.75各实际调用一次，分别得到0、0.5、1、1倍deltaTime的减少量；例如0.25时deltaTime约0.0297500，120变为119.98512268066406。299次手调的实际deltaTime约0.0166653至0.1488993，没有假设60fps或用墙钟替代。120是受心跳速率控制的剩余值，不代表固定120秒现实时间；负Dokidoki夹限仍仅有静态依据。

另外三组先建立旧状态，再在同帧把remain设到边界加deltaTime/4，以Dokidoki0.5真实更新跨过边界：

| 条件 | 首次返回 | 下一次更新/终点 |
|---|---|---|
| cross-60 | 60.00416565→59.98749924，state2→3，Current仍约0.4 | 下一次Current约0.3918817，开始向0.25移动 |
| cross-24 | 24.00416756→23.98750114，state3→4，Current仍0.25 | 下一次Current约0.2376074，开始向0移动 |
| cross-0 | 0.004166825→0，state4→1，Current仍0，reusable清false | 随后逐步向-1移动，最终state1→0并移除身体涂料槽 |

每次先按旧state选择UpdateTo参数并计算Current，再按新remain改变state及后续速率；跨界当帧不能直接把Current跳成新目标。UpdateTo也不写SmoothFloat.Target。独立平滑模型使用原生raw words中的上/下速率及真实deltaTime执行MoveTowards，覆盖全部299次手调。新速率在后续更新使用，未用夹具expectedRemaining字段代替独立重算。

## 清洗、物品和三目标材质

wash从120/reusable=true开始。OnUseWashItem返回时只见remain0、state4，reusable仍true；下一次OnUpdate才进入state1并清false，随后平滑至Current=-1，state0且身体ClothesPaintMaterial=null。本轮wash共169次手调，cross-0共107次；次数取决实测帧时长，不作为固定玩法常量。

普通物品类型5在prior=false时保持false；可复用类型8置true；类型5在prior=true时保留true。三组均将remain设120、state2、Current1，并保存独立解码。普通物品不会主动清除已有reusable，清洗方法本身也没有提前清除它。

实际bodyMeshRenderer槽与ClothesPaintMaterial引用逐一对应；同时核对FutanariController.SaoClothesPaintMaterial、TamaClothesPaintMaterial及两个实际Renderer末槽。所有非零state的更新返回后，三目标Tweak值均等于当次Current。两个额外Renderer实际记录activeInHierarchy=true；没有采集renderer.enabled或像素可见性，材质读取不等于可见像素验证。最终state1→0先调用Setup重建并早退，不要求新绑定的额外材质参数恰好为-1。

## 保存、Load、仅广播与显式Initialize

17份capture包含8个初始化条件、wash-return、3个物品条件、2个加载条件和3个跨界后状态，另独立解码baseline。remaining与reusable均同实际保存快照一致，保存槽为1；完整PlayerCustomData树哈希保持基线值，BodyPaintTypeDict保留空字典，不补写十个false键。存储层整数形式的0/120与浮点值均保留实际类型投影；这不是验证全部66字段视觉消费者。

普通加载保存61/false，可复用加载保存120/true；随后在真实材质上扰动为remain0、克隆state0/Current=-1，再调用原Load。Load恢复数据根和所存字段，控制器与材质仍保持扰动状态。下一帧只发原玩家30_0外观广播，身体涂料槽重建，但克隆仍state0/Current=-1，随后Dokidoki0的OnUpdate不协调透明度。再显式Initialize后恢复state2/Current约0.4，下一次原更新写入三材质。

这区分了数据恢复、材质建图与控制器重建。暖state0的这两次实测Dokidoki为0，不能说观察到它继续减时；“state0仍先执行计时再早退材质”来自静态方法及通用更新模型。自然完整玩家初始化是否已自动协调，不在本批证明范围内，不能据此宣布自然读档缺陷。静态入口、额外材质重建及延迟物品生产者见[静态调用链](../../timed-body-paint-static.md)。

## 两轮诊断与最终清理

首轮`20261030-1`虽有21个result和17份capture，但MaterialInfo对FX/Censor错误读取mainTexture，产生334条未带统一Error前缀的引擎消息；objectsRestored=false并抛runner_error。旧清理没有逐属性差异，根因保持未知，不能断言是比较误报、装箱或游戏加载故障。该轮脱离后因隐藏窗口没有可用关闭句柄而强制结束。

次轮`20261031-2`没有引擎/脚本错误，夹具所有清理标志、31003项shader枚举属性检查均通过，但独立完整公开快照发现10处差异：原Sao/Tama及对应Renderer槽hasTweak=false/tweak=null，恢复后却为true/约-0.99527454。因此它也不计完整成功；局部green标志不足以证明属性存在性恢复。其旧completed.dll仅是归档文件名，不代表最终验证通过。

第三轮先强制类初始化，首次快照前独立`Shader.PropertyToID("_Tweak_transparency")`与原static ID均为631，每次快照再次核对。除枚举属性外，另备份247份材质的Tweak存在性和值。清理时两份原本无Tweak的材质实际呈有值约-0.9929204，强制重设同一shader后HasProperty变回false，随后恢复原声明属性；两条shader_reset日志的absenceRestored均true。这直接验证了所选未声明属性写入/清除机制；不把第三轮结果追溯为首轮未知失败的唯一原因。

最终388个Renderer、247份材质、31003项声明属性和247项额外Tweak存在性检查通过，差异列表及旧比较分歧均为空。15个全局根、保存槽、原控制器及9个SmoothFloat字段、PlayerState.Dokidoki/LastUseItemType、applier标志及所录材质引用/属性恢复；公开原始/恢复快照除未注册克隆本身外严格一致。Color/Vector/纹理坐标及额外Tweak值要求分量位相同，Float/Range保留有限1e-5容差并报告每个非精确值。本批实际差异为零。原生状态切换产生的MessagePanel队列没有备份，不宣称整个运行世界或UI完全等价。

原9份UserData、前轮4份自然档、5项引擎/资源与两份原插件指纹均复核一致，插件目录无额外DLL。REA最终导出保留采集时running状态，之后脱离由操作方确认；通过Unity线程Application.Quit正常结束隔离进程，未强制终止。关闭凭据exit_code为null，不补称退出码0。

正式会话`92301c60-c265-4790-962d-5f2f7a6159f1`，PID83220；load Evidence `ev_527ea73a090bf4b22fb587e60b9fc95f32418227a672354f740b667dbccc1973`，status `ev_f243755f47041881d751901fb1a801f17cde586ce9b9d6440c183bd7b5fb08f2`。两次诊断的4条REA记录独立放在diagnostics-rea.json，原源码、DLL、编译/关闭凭据、全部日志及原始导出保留。未改写REA provider authority或缺失subject的原始限制。

离线复核入口为`collect.py --finalize-plugins`、`analyze.py --inputs --require-finalized-plugins --check`及`python -m unittest discover -s reverse-engineering/runtime/timed-body-paint -p test_analysis.py`。反例覆盖独立shader ID、原/克隆隔离、原生返回缺失、真实dt/Dokidoki、float32数值、阈值/跨界顺序、字典缺键、实际三材质绑定、Load分层、后置cleanup_done及枚举外属性恢复；完整加密档未发布明文。
