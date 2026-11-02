# 正式工程与自宅资产化

2026-11-03完成受版本管理的[UnityProject](UnityProject/README.md)，并将已验证的Apartment几何桥接保存为原生资产。当前默认入口为[unity-project.ps1](unity-project.ps1)与[formal-editor-settings.json](formal-editor-settings.json)。旧Tuanjie及Unity6缓存工程、源模板、回执和逆向证据保持历史范围。

## 工程与构建

正式工程固定Unity6000.6.7f1、Built-in、Legacy Input0、Windows64 Mono，维护Assets及meta、锁定Packages、ProjectSettings。Library等本机目录及大型原模型包本体忽略；模型meta、输入SHA和Prepare校验入库。

新[ProjectBuild](UnityProject/Assets/Editor/ProjectBuild.cs)只构建已有场景。它没有模板复制、NewScene、SaveScene或PlayerSettings写入；场景未保存、Title不是首场景、Apartment未启用或目标输出非空时拒绝。PowerShell入口额外比较构建前后维护文件的路径、长度及SHA，不回滚覆盖并发用户编辑。

正式Build `formal-20261103-1`：进程18364退出0，0错误、3警告，256个构建文件、454096998字节。Title与Apartment均已入包；**1465个Assets／Packages／ProjectSettings文件在构建前后逐字节一致**。Title中明确保留了`Title Scene Root`编辑对象，构建未重新写为空场景。大型模型包另按SHA校验，不在该1465项重复计数中。

## 自宅持久资产

[ApartmentImporter](UnityProject/Assets/Editor/ApartmentImporter.cs)仅显式执行，先校验冻结的export-manifest、geometry、roombridge及每张raw纹理，目标存在即拒绝。普通编辑器要求打开的场景已保存；批处理的干净默认场景先切换到已保存Title，再新增场景。构建不调用导入器。

| 产物 | 已验证数量／性质 |
| --- | --- |
| 原生Mesh／Material | 各302个，持久引用可解析 |
| 原生Texture2D | 90张，保留原DXT1／DXT5压缩内容，重开后逐张raw SHA一致 |
| 贴图材质 | 258处实际贴图绑定，余44个材质无主贴图 |
| Prefab与场景 | `Assets/Apartment/Environment.prefab`、`Assets/Scenes/Apartment.unity` |
| 节点映射 | 760个导出节点，包含原Transform和独立静态批次／碰撞节点；signed64位sourcePathId完整保存 |
| 绘制／碰撞 | 269个MeshRenderer、33个MeshCollider |
| 已知降级 | 5处builtin mesh仍未解析，逐项保留来源ID及用途 |

Import进程53412与独立Validate进程16640均退出0。后者重新打开保存场景，核对节点父级、局部变换、原始网格顶点／三角形／法线／UV、材质与纹理引用、Prefab连接及原压缩纹理字节，未保存或改写资产。1396个导入输出指纹在Import、重开验证与实际构建输入之间一致。文本引用检查另确认725个唯一meta GUID、663个本地被引用GUID闭合。

运行时[SceneAssets](UnityProject/Assets/Runtime/SceneAssets.cs)新增`project-scene`路径，按需加载或复用已打开的Apartment，读取[ApartmentSceneRoot](UnityProject/Assets/Runtime/ApartmentSceneRoot.cs)来源映射。房间不再在运行时重建Mesh／Texture／Material；原玩家、Avatar、Animator和钥匙夹具仍使用原模型包。纹理数量字段是导入合同值，不能单独证明后续人工编辑后的实际使用数量。

## 独立运行

完整输出复制至仓库外 `E:\ManakaREA-FormalStandalone-20261103-1`，256个文件与构建内容逐项哈希一致。两个测试进程均从该目录启动，WorkingDirectory也为该目录；运行所需资源来自包内原生场景与StreamingAssets，不读取工程几何JSON／raw缓存。

| 阶段 | 实际观察 |
| --- | --- |
| 受控进程56728 | `authored_scene_loaded`记录运行时未生成几何，760来源节点、269绘制／33碰撞／90纹理；原Player控制器和ManustiaAvatar保留 |
| 动作 | 模拟F192帧；原动画事件311帧→同帧None；119帧方向输入受移动锁约束；312–318帧恢复CC移动约0.076664米 |
| 保存 | 原钥匙夹具隐藏，库存10000从1到2；自动保存revision1，规范化float32值写读一致 |
| 冷进程57224 | 独立GUID读取同一SHA存档，物理更新前位置与Quaternion精确恢复；正常退出0 |

存档SHA256为`ffc7a8a78592a57cb2be00fcf4ff4038da4c6e0f3e8e3a8b50b586452ff1c6e8`。本轮是明确的受控输入证明，未声称Unity6实体键盘F／F5／F6已验证；冷库存2由文件独立解析，未补采第二份运行内存数量。钥匙仍是每进程重建的测试夹具，不代表世界掉落持久化。

原模型加载仍产生已记录的1232条缺失脚本警告、12处玩家材质替代；未恢复原shader、完整光照、遗漏碰撞／触发器或完整玩法。自宅电脑／床／衣柜、其他地图、NPC与任务仍待后续接入。

## 诊断与复现

失败诊断单独保留，未升级为正式通过：首次Receipt的int／uint编译错误；未保存默认场景阻止叠加创建；首份已持久化纹理没有接入材质数组，独立重开检测到258处缺失引用。修复后使用全新输出生成，并在Import末尾增加持久材质绑定断言。失败中间资产和原引擎日志留在私有忽略目录，公开记录安全回执、摘要及日志指纹。

交互式启动最初遇到管理员权限提示；Computer Use截图超时、点击返回`coordinate input geometry is unavailable`，用户报告普通权限重启不可用，提示留给用户手动处理。随后CLI实际检测到正式工程ready，并成功打开Apartment；[编辑器只读回执](formal-editor-open.json)确认单一Prefab根、269绘制／33碰撞／760映射节点、网格与材质全部持久化，场景无未保存修改且未进入Play。Unity MCP原安装连接仍指向历史工程；本次正式工程CLI操作显式指定`--project-path`。

正常使用按照[工程README](UnityProject/README.md)执行Prepare→Validate→Open／Build。只有从冻结桥重新创建新资产时才需要旧geometry／raw缓存；已有正式资产无需重新导入。

```powershell
python -B -X utf8 reverse-engineering/reconstruction/verify-formal-project.py --inputs
python -B -X utf8 reverse-engineering/reconstruction/verify-formal-runtime.py --inputs
python -B -X utf8 reverse-engineering/audit.py --inputs
```

[formal-project-runtime.json](formal-project-runtime.json)及[公开档案](formal-project-runtime)保存46份回执、构建源码、受控／冷读档记录和截图。默认历史验收读取归档合同；`--inputs`额外要求当前可编辑工程与本轮快照一致，后续修改后应建立新运行记录。
