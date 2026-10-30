# Manaka 资源解密与逆向入口

本轮补齐临时身体涂料的自然物品与冷标题路径。用户通过原版网购、道具界面和确认弹窗使用普通、清洗、无限三种套装；原动作10008分别在游戏时间约3.018／3.012／3.003秒后调用完成委托，普通套装即时扣库存，清洗和无限型保留数量。自然保存后经标题重建玩家，并在退出、重启的新进程中，从118.798912／可重复true恢复为状态2、Current0.4及实际材质；无需人为调用Initialize。见[自然运行对照](runtime/natural-paint/natural-paint-runtime.md)、[界面与延迟调用链](natural-paint-static.md)。

最初复制的旧高级档含原版部件表之外的70008..70013，实际导致RCosplay.Get越界、玩家初始化中断与输入失效；完整日志及有截断的Frida诊断独立保留。正式使用逐项核对原版资源范围的第二槽，保持原档不变。观察器没有物品、状态或加载重放；一个元数据标记文件读取冲突已恢复，未将其写成全程无异常。新进程虽重用了PID，退出记录、创建时间、启动和新玩家证据已区分生命周期。

本轮补齐临时身体涂料的21组受控对照：初始化阈值、4档Dokidoki计时、跨60/24/0状态切换、清洗淡出、普通/可重复物品及暖Load重初始化。17份保存快照对应实际状态和材质；倒计时按`2*Clamp(Dokidoki,0,.5)*deltaTime`递减。原自动控制器与独立原生测试控制器按指针区分，不把applier标志当作更新暂停守卫。见[运行验证](runtime/timed-body-paint/timed-body-paint-runtime.md)、[原生调用链](timed-body-paint-static.md)。

所选暖路径中，Load恢复剩余时间/可重复标志，外观广播只重建材质，状态0仍需显式Initialize才能恢复涂料状态机。清洗也不会立即移除材质：先归零时间，再清标志并淡出，最后Setup移除。受控第三轮无脚本/引擎错误，完整公开快照及额外属性存在性恢复均通过，并经Unity线程正常退出；前两轮分别保留探针纹理读取错误/局部材质检查失败、声明属性检查通过但额外Tweak残留的诊断。材质清理不能只枚举shader声明属性。后续自然路径由上方报告补齐，不将暖重放的协调缺口称为自然标题读档缺陷。

2026-10-30补齐自然任务与返家结算：用户正常操作完成任务100000，经Residence返家确认后得到8 RP、8经验，完成计数0→1并保存。第二轮未完成任务往返曾产生约0.07218进度，返家后清零，奖励与计数均未再次增加。首轮10次观察器返回钩子异常保留为采集缺口；原生入口、被动快照与14份存档独立解码支持选定结论。见[自然任务与返家结算](natural-mission.md)。

此前受控外观恢复增加持久TattooDark、BodyOil及两者组合，以及free=false皮肤预设0/1。Load仅恢复数据，原玩家外观广播才恢复实际材质；身体和脸部预设颜色按原资源RGBA对照。临时涂料现由上方两轮报告覆盖，其余贴图及物理效果仍待验证。见[持久身体涂装](runtime/appearance-boundary/appearance-boundary-runtime.md)、[皮肤预设](runtime/skin-preset/skin-preset-runtime.md)。

付费学习七组受控验证经过原按钮方法：299 RP拒绝、300 RP升级容量5→10、最高等级和等级门槛拦截、Slow学习后解除AutoSlow前置遮罩，以及被动激活键缺失/预存false的不同结果。保存、扰动、加载后重新核对真实UI状态与Buff；这些是Unity主线程受控回调，尚非自然鼠标购买。两轮失败夹具与正式成功证据分开保留。见[付费学习边界](runtime/paid-skill-boundary/paid-skill-boundary-runtime.md)。

工作分支 `codex/rea-salt`。原始文件固定取自 `E:\SecretFlasherManakaREA`，输入指纹验证通过才继续分析。
早期分析仅执行离线解析、REA/Ghidra和本地解密；后续受控运行与完整启动均在独立副本进行，原始游戏文件保持不变。

2026-10-30 补齐4组任务消费者及原生结算：未满足/暂停不增长；进度0.9999→1，区分一次性奖励和按秒增长。重建已完成对象会清掉运行标志并再次发一次性奖励，仅记受控暖重建边界；结算实际把约16.0071转成16 RP及16经验，完成计数0→1，进度/收益清零。14份新REA查询、98条无异常消息、13份独立解码快照、8项校验通过。早期崩溃和采集器失败独立留档。见[任务进度与结算](mission-consumers.md)。

2026-10-30 补齐3组物品及3组技能17原生消费：水2→1且再次读档保持1，可重复经验道具数量不变并增加1000/100经验；技能未学/关闭拒绝动作，启用后实际动作7和两次动画事件完成停止、恢复。19份新REA查询、63条未截断消息、7项校验通过。本轮是不可见物品视图的受控回调和显式InputData请求，未声称自然点击或付费学习。见[库存与技能实际消费](state-consumers.md)。

2026-10-30 继续补3组发型/纹理/RGB/阴影实际恢复：新增5份REA查询，独立解码与两个当前材质的纹理、颜色及HSV阴影一致。已有对象直接Load+Initialize在两组默认发型0条件仍启用旧发型1，符合初始化的冷启动前提；显式协调后的正确模型单独记录，不冒充自然恢复。8项校验及保护文件检查通过，178条消息未截断。见[头发恢复边界](appearance-hair.md)。

2026-10-30 外观恢复继续补3组颜色/脸部/非单位骨骼对照：17个指定字段独立读回，四种实际材质和40个脸部通道与原生应用基准一致。两套正常配置均产生5个非单位骨骼目标，显式12目标对照同样满足逆缩放。发现Update中延迟回调实测F+1、LateUpdate中F+2，不能统一称下一引擎帧；均单次执行。9项校验、337条未截断REA消息通过，原文件不变。其余外观及库存/技能/任务消费者仍待推进。见[详细外观恢复](appearance-detail.md)。

2026-10-30 授权后Tuanjie工具链已实际通过新建工程、脚本编译、Windows64 Mono构建和5帧生成程序启动检查，三个进程退出码0；这只验证工具链，原Unity资源/IL2CPP兼容性和替代游戏仍未完成。另补3组原生外观保存/加载：实际模型缩放、动画速度符合分段公式，12个骨骼接收器各在下一帧执行一次，只有2个已初始化头发组件接收事件。5项校验及保护文件检查通过。见[外观运行对照](appearance-restore.md)及[工具链结果](reconstruction/README.md)。

2026-10-30 完成系统档/备份第二批12条件：整个游戏/系统档缺失及5种系统缺键均可默认恢复，两种系统损坏抛原生异常；显式原生复制备份后游戏字段与基线一致。10组两遍往返稳定，180个库存/技能/任务读取标量与独立解码一致。无效技能键48导致的首版夹具错误独立留档并已重测。4项测试通过；实际外观、库存消耗、技能效果及任务更新仍待验证。见[系统档与备份验证](full-save-recovery.md)。

2026-10-30 完成完整存档恢复第一批12条件：256个显式存储字段纳入逐字段投影，完整/进阶档和7种缺键条件均完成两遍原生Load/Save；游戏数据第二遍0变化，系统仅手动保存时间更新。三种损坏主档在有效备份存在时仍抛原生异常，未自动回退。6项测试及保护文件指纹通过；后续系统档/备份结果见上方第二批，实际运行消费者仍待补齐。见[完整存储字段验证](full-save-restore.md)。

2026-10-30 补齐4组受控恢复队列生命周期：活对象创建一次；销毁、卸载及原生退出至标题后，任务仍保留到期，尝试一次且未进入克隆，然后出队。早期崩溃诊断与场景重载的20条独立栈异常保留，不计作自然恢复结论。5项校验测试及保护文件指纹通过。见[恢复队列与对象销毁](restore-interruption.md)。

2026-10-30 完成普通掉落物管理器冷/暖/失效缓存对照：47条未截断REA原生消息确认首次2次同步克隆、重复恢复0克隆、销毁后仅重建1对象，七个监测加载入口均未命中。源预制体属于已加载AssetReferencer，管理器冷缓存不能误作资源包异步冷加载。8项测试通过，原用户数据与前轮自然档不变。见[掉落物冷缓存报告](drop-cold-cache.md)。

2026-10-30 补齐NPC恢复排除边界：新增3份REA查询及2组明确受控原生对照。两名真实固定NPC在快照生成时排除；移去普通NPC后高水位记录标为IsExist=false，原生保存/加载保持该标志。实际商场电梯的4条内外/存在矩阵只执行2次Bounds判断，只有存在且外部的一条进入队列、闭包、Instantiate/Warp。两组各1条排队/回调/实际对象，9项校验通过；9份UserData、4份前轮自然档及5项原件/副本输入未变。见[NPC恢复过滤报告](npc-restore-filter.md)及[继续入口](runtime/npc-restore-filter/next-run.md)。

2026-10-30 闭合自然电脑保存与标题读回：真实新游戏第二槽、电脑保存产生主档，随后标题继续。新增2份REA查询；71条未截断原生消息连接按钮、isBackup=false、实际路径与加载/Warp。解码文件、Save/Load状态及Warp姿态在float32精度一致；20个实际位置样本约9.7秒内最大偏差0.155毫米。8项校验通过，原9份UserData及5项输入未变。两次启动仍force=true/loaded=false，未新增非空NPC自然恢复正例。副本正常退出、临时插件恢复；见[自然标题读档闭环](natural-title.md)及[继续入口](runtime/natural-title/next-run.md)。

2026-10-27 补齐默认标题/NPC保存守卫：10份新增REA查询及原始PE扫描确认force默认true、IsDebug=false；真实标题加载含3条记录的受控来源档仍走强制重生，OnLoadData未执行。自然新游戏进入Residence时峰值25名NPC、fixed计数20，loaded仍false、列表始终空；自然保存实际落在备份1，未计作主槽再次读回。8项校验通过，9份原UserData未变。任务按用户要求暂停；进程挂起成功后出现AppHang关闭记录，内存现场未保留，下次从备份重新启动。见[自然标题读档与NPC保存守卫](natural-load.md)及[继续入口](runtime/natural-load/next-run.md)。

2026-10-27 完成一轮受控原生保存/加载及运行对象对照：独立解码新存档，3名动态NPC均进入记录恢复、Instantiate/Initialize/Warp并继续移动；当前场景掉落激活、异场景掉落隐藏；两项预留一项投放出队、一项跨场景保留，重放不重复投放。干净轮0条引擎Error、8项校验测试通过，9份原UserData文件及5项引擎/资源输入哈希保持一致。Load将场景11重置为0，消费者前显式协调回商场，因此不计作自然标题读档生命周期验证。见[原生保存、加载与对象对照](state-restore-runtime.md)。

2026-10-27 按优先级补齐选定状态恢复链：新增50次非空REA查询，连接NPC读档/重生及闭包、掉落物激活/预留投放、玩家保存位置和五类外观事件接收器。557条原始指令确认随机浮点延迟实参。7份游戏快照的196条掉落记录完成守卫输入检查，但NPC/预留列表均空、当前场景激活样本为0，未计作原生对象恢复验证。见[存档到运行对象恢复报告](state-restore.md)。

2026-10-27 补齐实际存档设置与独立读取：新增56次非空REA查询，完整解析576字节ES3Defaults，确认存档为独立密码、IV兼salt、PBKDF2-SHA1/100次及AES-128-CBC。测试副本8份加密快照均可独立解码，37个顶层键、16个根对象字段完整对应；按原IV内存重加密均逐字节一致。保留数字字典键类型，原生对象往返与迁移仍待验证。见[实际存档设置与解码报告](save-codec.md)。

2026-10-27 继续补齐存档反射与泛型读取：新增71次非空REA查询，恢复四个根对象256个显式ES3Serializable字段、27类型嵌套图，并确认外观预设65个非public字段同样参与显式标记。原始泛型注册解析出220条记录/57地址，本轮补查13个共享读取方法体；确认先创建对象再覆盖成员、两类缺键重载与上下文相关外观默认值。实际存档设置/密码、完整系统键及读写往返仍待补齐。见[存档结构与默认值报告](save-schema.md)。

2026-10-27 按重要性补齐六组关键方法：状态快照、NPC移动/转身、相机、保存恢复、任务、门/洗衣机交互。新增171次非空REA查询，绑定391个usage、130个类型字段及36个任务类型vtable；34个具体任务条件均有查询。确认GameStateApplier方向为运行对象→状态数据，NPC转身约2.8秒恢复并设置10秒噪声忽略，且原始固定更新的20/30距离判断顺序经50条指令核验。ES3全schema、自然任务/相机等价性及其他消费者仍保留边界。见[六组关键方法报告](priority-chain.md)。

2026-10-27 补齐本轮自然噪声更新返回：458次逐次记录均有入口、onLeave和上层原生续行配对，其中446次位于4个发现周期内。4次均单次产生并交付事件；事件前54条值更新虽将计数120→119，同次噪声更新返回时已回到120，值保持1，仍未达到普通噪声打断前置。旧多脚本采集缺口及其原因仍保留未知。见[自然返回与帧内计数恢复](noise-return.md)。

2026-10-25 已补齐原生噪声调用点：改为在游戏真实噪声更新入口设置受控前置并返回，4组均捕获同线程/对象/更新区间内的发现1→转身2，实际返回`0x435abf`，上层调用方返回`0x428bf3`。其中1组正常退出无事件，3组各有一次事件/模型/回调/监听。自然7次均正常交付；后4次事件前26条值更新显示值1、计数119–120，尚缺自然低值前置。未配对的自然噪声更新返回另列为采集缺口。见[原生调用点与自然可达条件](noise-callsite.md)。

2026-10-25 补齐普通噪声与混合取消：3次自然发现各有一次事件、模型、回调和监听；另捕获普通状态0→转身2的真实噪声分支。发现入口值1高于转身阈值，PlayerFound等更早守卫也可拒绝噪声接收，本批自然玩法未命中发现打断。隔离副本10组受控接收重放中5组发出一次事件/回调，5组在低于事件点的连续轨迹后退出无事件，支持正常取消；不当作自然覆盖或真正漏发。新增8份静态查询、592条指令字节核验，保留受控嵌套钩子未捕获的限制。见[普通噪声与动画混合取消](noise-cancellation.md)。

2026-10-24 新增自然终止与转场守卫：19次发现入口中17条各有一次事件、模型、回调和监听，另外2条在事件点前正常穿过出口，场景切换并销毁旧NPC，未产生事件，支持正常生命周期终止。真实菜单停止拒绝2次，与警戒/衣着拒绝明确区分；新增15份原生查询及669条原始指令字节核验。普通噪声/混合取消、同一对象重入及不暂停跨档仍未证明。见[自然取消与转场守卫报告](natural-cancellation.md)。

2026-10-22 补上自然事件前覆盖：5个发现周期均各有1事件、入队、回调和监听；技能停止辅助下，两组实际双向跨10米档位切换，另确认54.5米处先自然隐藏，再由原始手动Animator.Update跨事件点触发一次。还捕获自然通知排队停止约99.81秒、恢复约0.40秒后单次交付。记录器分段与冻结等待没有误算成取消或漏发；停止期间界面拒绝切场景，普通不暂停跑动与自然取消仍有边界。见[自然事件前覆盖报告](natural-event-coverage.md)。

上一检查点的事件产生前观察：7次自然事件均有回调，其中4组有完整进入周期，但当时自然事件前隐藏/距离切换未命中。独立完整副本16组受控参数测试产生15条真实Unity事件，均有一次入队、回调及监听；另1组记录到普通过渡退出后模型回收。5种前置条件均有有效样本，并保留4条条件未达标记录。提前关闭参数仍可在退出混合中触发事件，不能直接当取消或重复。见[事件生成与取消报告](event-generation.md)。

2026-10-22 继续补齐排队通知、模型隐藏和距离切换：16次自然事件均有回调；经用户同意，完整游戏环境内12条受控通知全部有一次回调及广播入口，五种组合均覆盖。倍率1下428个相邻停止区间未见剩余时间下降；叠加普通暂停的两模型恢复后同帧2→2交付，未当成重复。保留一次远距未保持的条件失败及补测，不把受控入口当成自然AnimationEvent。新增10次REA查询，见 [通知情景报告](notification-scenarios.md)。

2026-10-22 新增完整自然玩法观察：经标题进入Apartment、街道、商店及StationFront；源8个保存/绑定文件哈希保持不变。正常UI启用技能17后，真实轮盘快捷输入产生4组停止/恢复、8次原生产者、352次NPC接收，未见同组重复投递或缓存覆盖。前三组结合定时快照，第四组45个NPC在广播返回时直接确认归零及原速恢复；2次发现动画均对应一次约0.6秒回调。队列中途停止、隐藏与距离阈值切换仍未覆盖。新增24次REA查询，见 [完整玩法报告](natural-gameplay.md)。

2026-10-21 已补齐 Windows 上层加载链：初始化资源 → KeyData → 标题场景 `models` 请求 → 路径/密码 → 解密流 → Unity 包加载 → 完成缓存与 25 个资源请求。本轮新增 54 份原生观察，见 [上层调用链报告](loading-chain.md)；完整证据坐标及绑定见 `salt/evidence/loading-chain.json`。

后续已补齐 EncrypterBundle 槽 2 → BridgeAssetBundle → Unity LoadAssetAsync / GetResult → 25 个回调 → 缓存及实例化/应用消费者，新增 56 份非空 REA 观察；另 3 份空 Listing 响应明确保留为不可用结果。见 [资源请求后续链报告](asset-followup.md) 与 `salt/evidence/asset-followup.json`。实际分配的包桥接类型为 BridgeAssetBundle，旧伪代码中的 EncryptLabelData 构造函数名是共享地址种子别名。

已继续连接标题新游戏/继续 → 选项与存档槽 → 淡出 → SpringboardLoadEmpty → MStage 目标关卡 → InGameManager/StageController 初始化 → EventMethodManager 每帧接口分派，新增 109 次非空 REA 函数查询。标题动画等待 25 个回调的门槛、10 个构建场景、8 条真实关卡配置及 5 个标题按钮绑定均有静态证据。见 [场景与初始化报告](scene-chain.md)、`salt/evidence/scene-chain.json` 和 `assets/scene-inventory.json`。这些成果提供重建依据，尚未形成可独立运行的游戏或完成启动验证。

## 已完成

已继续建立 `PlayerController → InputResolver / PlayerLocomotion / PlayerAction → CharacterController.Move`，以及交互候选、事件广播与选定动作完成回调；新增 94 次非空 REA 查询。原始 PlayerAction 输入表（61 actions / 88 bindings）、14 组枚举、移动基础参数、78 条动作记录引用和玩家碰撞组件配置同步保留，见 [玩家玩法调用链](player-chain.md)、`salt/evidence/player-chain.json` 与 `assets/player-config.json`。跳跃存在未接通输入的代码分支，完整动画/交互/特殊状态与运行验证仍未完成。

已继续追踪 Bareta/BaretaEscape，新增 77 次非空 REA 查询：NPC 发现动画回调→事件广播→玩家反应/技能等待→约2秒普通恢复，以及扣生命/GameOver→Sad结束→自动逃跑→失败加载。真实 Sad AnimationEvent 已按 type tree 解析，时间约2.267秒；自动逃跑不能直接解释为逃脱成功或恢复控制。见 [被发现与逃脱状态链](bareta-chain.md)、`salt/evidence/bareta-chain.json`、`assets/bareta-config.json` 与 `salt/symbols/bareta-producer-candidates.json`。NPC 动画接线和实际运行仍有明确边界。

已补齐选定 AnimatorController 与动画事件接线，新增13次非空REA查询：NPC四个发现动作的性别/坐姿条件、OnAnimBaretaSound事件与延迟广播，以及玩家Action.Sad→OnEndSad→Upper.BaretaEscape。原始357个clip、48个controller与1246个Animator完成对象边界校验，选定Player/Npc控制器图完整解析。见 [动画接线报告](animator-wiring.md)、`assets/animator-wiring.json`、`assets/npc-animation-events.json` 与 `salt/evidence/animator-chain.json`；仍未运行验证，Casual1接收器来源保留未知。

已继续确认NPC模型选择与初始化，新增14次非空REA查询：当前工厂克隆Npc模板，再从9个自带Receiver的模型中选择；Casual1不在其候选字段中。AvaterObject赋值、GetComponent及接收器nca初始化连接到原有发现事件；CreateController是业务对象分配，选定路径未见补Receiver或替换RuntimeAnimatorController。见 [NPC模型与接收器来源](npc-model-chain.md)、`assets/npc-model-wiring.json`、`salt/evidence/npc-model-chain.json`。保留反射/外部Mod/其他消费者和实际播放边界。

已继续补齐NPC距离调帧与手动Animator.Update：确认欧氏距离阈值、XMM1中的累计delta实参、近远启停/外层隐藏三倍数门，以及IsTimeStop的Animator速度缓存/归零和0.6通知剩余时间挂起。新增16次REA查询（12非空、4空Listing保留）并补充原始机器码1142条静态指令核对。见 [NPC调帧与发现通知时序](npc-fps-chain.md)、`salt/evidence/npc-fps-chain.json`、`salt/symbols/npc-fps-instructions.json`；条件算例不代表实际运行事件日志。

已补充REA Frida受控运行验证：15条件×男女站立模型×2轮，共60次，原生动画事件、入队、原生回调及测试广播监听计数为56/56/56/56，无重复或已入队任务丢失。另4次事件前重复停止会把速度恢复缓存覆盖为0，观察窗口内未产生事件。还实测区分了自动动画下一帧首次扣减与手动动画同帧首次扣减，解释约0.600/0.583秒的通知间隔。见 [动画通知实测](npc-event-runtime.md) 与 `runtime/npc-event-timing/`。该夹具替代bootstrap、移动和音频上下文，完整玩法中的重复通知来源及外层调用顺序仍待验证。

已继续追踪时间停止生产者：新增16次REA查询、原始输入/枚举/控制器与9个扫描候选核对，确认OnChangeTimeStop先反转标志再广播，AddListener按相等委托去重，Destroy注销监听器。新32次受控实验中24次原生产者路径正常，8次注入同状态广播/人工清标志的对照才复现缓存覆盖；未找到自然链连续派发停止的证据。见 [时间停止生产与广播](time-stop-chain.md)、`salt/evidence/time-stop-chain.json` 和 `runtime/time-stop-producer/`。完整自然游玩及任意重入/Mod仍未验证。

| 项目 | 结果 | 证据 |
| --- | --- | --- |
| 全局定位索引 | 76 程序集、10,508 类型、79,095 方法；70,948 个方法有原生地址 | `salt/symbols/index-summary.json` |
| 未解析坐标 | 1,467 个泛型/未解析指针、6,680 个空指针保留未知；4,523 个原生地址有多个元数据别名 | 同上，完整索引在 `salt/.cache/methods.sqlite` |
| 原始 KeyData | `resources.assets` pathID 61594，164 字节，字段解析至 EOF，脚本身份与类型 hash 一致 | `assets/resources-keydata.json` |
| Salt/GUID | 从 KeyData 独立恢复，与用户提供的旧成果一致 | 同上及 `salt/evidence/recovered-crypto.json` |
| 密码 | 从原生字符池、26 个构造索引和 GUID 变换独立恢复，与旧成果一致 | `salt/evidence/recovered-crypto.json` |
| 原生加密调用链 | 一次导入查询 10 函数 / 12 观察，84.668 秒；补充 3 个初始化/库函数，83.508 秒 | `salt/evidence/crypto-batch/run.json`、`crypto-batch-helpers/run.json` |
| 解密副本 | 223,101,993 字节，SHA-256 `98621b2c4fa4f9de80f355fae5776ab17efc016bcc81c581bcd0917af4308367` | `salt/.cache/decrypted/models.unity3d` |
| 容器验证 | UnityFS v8 / Unity 2022.3.62f2，3 节点，全部 3,819 块可解码，总解压流 500,551,232 字节 | `salt/evidence/decryption-verification.json` |
| 对象目录 | 主 SerializedFile v22，2,650 类型、76,079 对象，带 type tree | `salt/evidence/decryption.json` |
| 标题进入游戏 | 新游戏/继续分支、两次场景切换、状态恢复及主要初始化/更新入口 | `scene-chain.md`、`salt/evidence/scene-chain.json` |
| 原始场景配置 | BuildSettings 10 场景、MStage 8 记录、入口组件与 5 个按钮持久调用 | `assets/scene-inventory.json` |
| 玩家移动与操作 | 输入帧语义、普通移动/跑步/蹲姿、自动移动取消、Unity 位移出口、交互广播及选定完成回调 | `player-chain.md`、`salt/evidence/player-chain.json` |
| 原始玩家配置 | 实际输入 map、默认键位、枚举数值、速度/动作前缀与 CharacterController 字段 | `assets/player-config.json` |
| 被发现及状态恢复 | Bareta的进入/退出与技能守卫、Sad到BaretaEscape的条件、自动导航副作用及失败加载 | `bareta-chain.md`、`salt/evidence/bareta-chain.json` |
| 真实 Sad 动画事件 | models的260个clip完整事件区解析；Sad中OnEndSad约2.267秒，NPC回调在此范围未命中 | `salt/symbols/bareta-producer-candidates.json` |

解密包主节点是 `CAB-2afa88b54ee4aa6beff98892b77cac4c`，另有 `.resS` 和 `.resource`。对象表已读通，不等于每个模型、材质或 MonoBehaviour 字段的业务含义均已恢复。

## 已建立的解密链

1. 原始 UnityFS 的块/节点表 → `resources.assets` 对象表 → KeyData 对象与关联 MonoScript。
2. `models` 对应 `Assets/ZZZ-ExternalEncryptAsset`，其 `hash` 是 signed int64 `-265379604`。GUID 是 `add7ae9ef7e0477e9d0aeb6d43949b7a`。
3. `PasswordMap::.cctor` 绑定 195 字符的池（metadata string literal 883）；构造函数用 26 个索引构成 `map["models"]`。
4. `GetPasswordFromMap` 逐字符查池索引，减去 GUID 对应字符的十六进制数，负数加池长度，再取字符。所得密码与旧成果逐码点一致。
5. `GetSalt` 把资源 hash 转十进制字符串，若短于 8 字符则在右侧追加 `0`，再 UTF-8 编码。本资源得到 10 字节 `-265379604`。
6. `GetStream` 以 keySize=256、CipherMode=2（ECB）、PaddingMode=1（None）创建 `SeekableAesStream`。枚举元数据见 `salt/symbols/crypto-enums.json`。
7. 流构造函数用 PBKDF2-HMAC-SHA1 / 1000 次派生 32 字节 key；库构造函数的 UTF-8 路径与 `HashAlgorithmName.get_SHA1` 坐标也已核对。原生密码会经过 `TrimWhiteSpaceHelper(2)`；本密码无边缘空白，因此结果不变。它不是删去前两个字符。
8. `Cipher` 使用 AES-256-ECB 加密计数块产生密钥流，再与文件字节 XOR。计数块是 `LE64(floor(fileOffset/16)+1) || 8个零字节`，从 1 开始。构造函数分配零 IV，但 ECB 不用它作为变化中的 CTR IV。

因此这里不能直接套默认大端计数器的 AES-CTR API。`salt/crypto.py` 按实际的小端计数布局实现，并验证了跨 AES 块边界的非对齐随机读。原始密文 SHA-256 是 `bb3a495d023a00ff95c110955a436e4d4dd2eea0598919401eb236d3e132ade9`。

## 复现与继续分析

在仓库根目录执行。依赖当前已安装的 Python `cryptography`、Node、REA 6.5.0、Ghidra 12.1.4 和现有 JDK；没有新增安装。

```powershell
# 原始资源对象证据与符号索引
python reverse-engineering/assets/inspect_resources.py --output reverse-engineering/assets/resources-keydata.json
python reverse-engineering/salt/metadata.py index
python reverse-engineering/salt/metadata.py find --assembly IKA9nt.Encrypter --method GetStream

# 一次原生导入，顺序查询整条加密链；使用独立公共 REA MCP 子进程
python reverse-engineering/salt/prepare_batch.py
node reverse-engineering/salt/run_batch.mjs
python reverse-engineering/salt/prepare_batch.py --phase helpers
node reverse-engineering/salt/run_batch.mjs reverse-engineering/salt/symbols/crypto-helpers.plan.json

# 从原始对象和原生证据恢复参数，再检查/解密资源包
python reverse-engineering/salt/crypto.py recover
python reverse-engineering/salt/crypto.py inspect
python reverse-engineering/salt/crypto.py decrypt
python reverse-engineering/salt/crypto.py verify

# 复核已保存证据，并校验原始文件与解密副本的指纹
python reverse-engineering/audit.py --inputs

# 上层加载链：选择入口并复用同一 REA 批次会话
python reverse-engineering/salt/prepare_loading.py
node reverse-engineering/salt/run_batch.mjs reverse-engineering/salt/symbols/loading.plan.json
python reverse-engineering/salt/loading_evidence.py --check
python reverse-engineering/salt/asset_evidence.py --check
python reverse-engineering/assets/inspect_scenes.py --check
python reverse-engineering/salt/scene_evidence.py --check
python reverse-engineering/assets/inspect_player.py --check
python reverse-engineering/salt/player_evidence.py --check
python reverse-engineering/assets/inspect_bareta.py --check
python reverse-engineering/salt/bareta_producer_evidence.py --check
python reverse-engineering/salt/bareta_evidence.py --check
python reverse-engineering/assets/inspect_npc_animation.py --check
python reverse-engineering/assets/inspect_animator.py --check
python reverse-engineering/salt/animator_evidence.py --check
python reverse-engineering/assets/inspect_npc_models.py --check
python reverse-engineering/salt/npc_model_evidence.py --check
python reverse-engineering/salt/npc_fps_evidence.py --check

# 按选定程序集增加元数据名称种子；选中方法的别名优先
python reverse-engineering/salt/prepare_loading.py --name scene-example --seed-assembly Assembly-CSharp.dll --method-id 16862

# find 的 id 可用于选择其他方法，生成独立种子和计划，不必改脚本
python reverse-engineering/salt/prepare_batch.py --method-id 76342 --name getstream
node reverse-engineering/salt/run_batch.mjs reverse-engineering/salt/symbols/crypto-getstream.plan.json
```

`decrypt` 要求输出不存在，默认保存到 `.cache/decrypted/models.unity3d`。若副本已经存在，直接运行 `verify`；或用 `--output` 指定另一个新路径。原始密文不会被覆盖。

所有函数地址、原始 token、参数计数、共享地址别名和文字字节均绑定到构建指纹。全量 SQLite 与大解密副本在 Git 忽略的 `.cache` 中，可由脚本重建；可复查的原始观察、选定符号、计划和脚本在普通目录中。此目录通过 `.gitattributes` 禁用 Git 换行转换，保证克隆后的证据文件字节与指纹索引一致。

## 证据使用边界

REA 输出保留 `evidence_id`、输入 SHA-256、分析 profile、种子承诺和已关闭的自动发现器。种子名称是从元数据提供给 Ghidra 的分析者断言，不是反编译器自行恢复的原始 C# 源码。

批量入口使用同一 Ghidra 会话避免重复导入，导出证据后关闭。未修改 Codex 全局 MCP 配置。直接用旧默认全库模式仍可能很慢，快照也未提供本机 5 秒重放；后续使用批量入口，读取既有结果则直接打开保存的伪代码/JSON。

资源解密验证限于本构建的 `models` 包；另已静态追踪标题进入游戏的场景、状态与主要初始化入口。其他包、动态补丁、实际运行时顺序、其余泛型实例和所有对象语义仍未完成。完整引用图、部分间接调用/类型签名、动画事件/状态机、ES3 全序列化和玩法子状态尚未恢复；关闭的全库发现选项会限制这类结论。未知项见 `unknowns.json`，证据文件指纹见 `evidence-index.json`。
