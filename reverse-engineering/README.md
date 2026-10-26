# Manaka 资源解密与逆向入口

工作分支 `codex/rea-salt`。原始文件固定取自 `E:\SecretFlasherManakaREA`，输入指纹验证通过才继续分析。
早期分析仅执行离线解析、REA/Ghidra和本地解密；后续受控运行与完整启动均在独立副本进行，原始游戏文件保持不变。

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
