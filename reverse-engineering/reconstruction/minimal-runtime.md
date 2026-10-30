# 最小独立运行闭环

2026-10-31已在Tuanjie 2022.3.62t7构建独立Windows64 Mono程序，完成“标题→原存档投影读入→原自宅→移动→独立保存→关闭→新进程继续”。正式构建0错误、0警告，两个可见运行进程退出码0。标题与场景图像均通过非黑、非单色检查，并已人工查看。

标题、初始化、相机、移动和保存是本仓库新写的实现；原角色、自宅网格、首材质贴图及选定碰撞来自冻结原件。包内没有原GameAssembly或BepInEx。原Animator、NPC、任务、交互、技能和完整外观效果尚未实现；该结果只证明最小独立闭环。

## 兼容性与资源

原models资源包、玩家预制体和压缩纹理可被新引擎加载；原构建data.unity3d不能直接作为场景AssetBundle加载，保留了版本不匹配错误。没有修改原版本头。见[兼容测试](asset-compat/README.md)。

[自宅桥接](asset-bridge/README.md)实际加载269个绘制、31个箱体派生碰撞、2个原网格碰撞及90张DXT1/DXT5纹理。箱体用导出的静态网格重建；5个缺源的内建网格引用明确跳过。原触发器、NavMesh、光照贴图、透明及多材质效果未完整恢复。

玩家仅复制身体、脸、默认头发和外套共4个Renderer，保留骨架与蒙皮，按BakeMesh包围盒对齐足部；11个材质使用Standard替代，不复制原Animator或596个行为槽。每个正式进程有1228条缺脚本警告，原生日志另有6条不受支持的Shader错误。回调采集的engineErrorCount=0不代表原资源没有错误；proof明确标记degradedAssetCompatibility=true、originalShaderCompatibilityVerified=false。

## 两进程对照

|阶段|实测结果|
|---|---|
|标题与初次读入|标题图像有效；只读导入已验证自然存档的选定字段，Apartment位置与Quaternion在物理步进前逐位一致|
|自宅与移动|269绘制／33碰撞／90纹理；401次同Motor输入采样，400次Below、175次Sides碰撞；水平路程2.24486232米，净位移0.989499032米|
|保存|从实际Transform写独立save.v1.json，revision1；位置及四元数经JSON往返逐位相同|
|关闭与重启|PID89908关闭后，新的PID92192读取同一SHA存档，Guid不同；场景、位置与Quaternion再次逐位相同|
|画面|两个标题及移动后／重启后自宅，均为1280×720、Direct3D11；像素检查和人工查看通过|

保存位置为`(1.198428, 0.0249998569, 0.73992157)`，Quaternion为`(0, 0.8283075, 0, -0.5602737)`，存档SHA256为`c66ab968c85f45cf864ea7b7e8fa4d1c2de63af961e8a91636261dfbcc3aaf6d`。原档y约-0.000463，接地后约0.025；原值应用、物理矫正与移动后的保存分开记录。

验收使用模拟轴，进入与键盘相同的PlayerMotor.Update→StepFromInput→CharacterController.Move，没有直接改位置冒充移动。尚未测试真实键盘或鼠标点击；自动入口与标题按钮共用Open方法。

原ES3仅离线读取。运行时读入随包seed，后续写独立version1 JSON；12项库存、涂料计时／可重复标志和选定外观数据跨保存与重启保留。数据保留不等于对应效果已实现。见[独立保存验收](save-bridge/README.md)。

## 产物与操作

正式工程：`reconstruction/.cache/minimal-20261031-1`。

程序：`reconstruction/.cache/minimal-20261031-3-build/ReconstructedManaka.exe`。构建回执434364556字节，共306个包文件。依赖、选定资源和seed随包提供，运行无需原游戏目录。大资源、程序和生成工程放本机忽略目录；仓库保存源码、生成器、指纹、回执和截图。

双击程序进入标题。首次点“新建进度”读取随包seed，已有独立档则点“继续”。WASD移动，Shift跑步，右键拖动视角；界面提供保存及保存并退出。默认档位于Tuanjie持久目录下ReconstructedManaka/profiles/default，也可传--profile-root。正式自动验收另用.cache/minimal-acceptance-20261031-2-profile，不与手动体验混用。

## 复现

从仓库根目录执行，使用未占用名称保留旧结果：

```powershell
python -X utf8 reverse-engineering/reconstruction/asset-bridge/bridge_assets.py --geometry
python -X utf8 reverse-engineering/reconstruction/asset-bridge/make_manifest.py
python -X utf8 reverse-engineering/reconstruction/save-bridge/prepare_seed.py
./reverse-engineering/reconstruction/check-editor.ps1 -RunName minimal-new
./reverse-engineering/reconstruction/build-minimal.ps1 -ProjectRun minimal-new -BuildRun minimal-new
./reverse-engineering/reconstruction/run-minimal.ps1 -BuildRun minimal-new -RunName acceptance-new -Phase phase1
./reverse-engineering/reconstruction/run-minimal.ps1 -BuildRun minimal-new -RunName acceptance-new -Phase phase2
```

正式画面验收使用可见窗口。第一轮-batchmode逻辑通过但截图全黑，单独留作诊断；随后可见模式确认，再加像素门槛重跑完整正式闭环。复用缓存工程时还曾因目标Textures已存在而在启动编辑器前中止，失败记录保留，复制逻辑已修复。

[运行清单](minimal-runtime.json)绑定源码、输入、306个构建文件和51个归档输出；[独立保存检查](save-bridge/acceptance.json)重新核对投影、真实Transform、存档和新进程。REA对两版实际Assembly-CSharp做PE/CLI检查，确认Unity Mono CIL，引用仅为netstandard及UnityEngine模块，不依赖原游戏程序集。

```powershell
python -X utf8 reverse-engineering/reconstruction/verify-minimal.py --inputs
python -X utf8 reverse-engineering/reconstruction/save-bridge/verify_roundtrip.py --check --inputs
python -X utf8 reverse-engineering/audit.py --inputs
```
