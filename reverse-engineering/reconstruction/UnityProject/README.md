# 正式 Unity 工程

此目录是后续编辑的唯一源码与场景入口，使用 Unity **6000.6.7f1**、Built-in、Legacy Input Manager、Windows64 Mono。`Assets`、`.meta`、`Packages` 和 `ProjectSettings`受版本管理；Library、Temp、Logs、UserSettings和构建产物不入库。

在 Unity 中打开本目录，双击 `Assets/Scenes/Apartment.unity` 即可在编辑状态查看、选择和修改自宅。房间引用 `Assets/Apartment/Environment.prefab`，网格、材质与纹理均是持久化原生资产。Title仍使用现有运行时标题UI；玩家与原Animator继续从准备好的模型包加载。

从仓库根目录准备、验证和打开：

```powershell
pwsh -NoProfile -File reverse-engineering/reconstruction/unity-project.ps1 -Action Prepare
python -B -X utf8 reverse-engineering/reconstruction/verify-formal-project.py --inputs
pwsh -NoProfile -File reverse-engineering/reconstruction/unity-project.ps1 -Action Open
```

新机器需提供原模型资源，`Prepare -Models <已解密models.unity3d的路径>`只复制通过223101993字节及SHA256校验的资源。它不复制源码、场景或设置；已有不同内容拒绝覆盖。模型本体忽略，稳定的`.meta`入库。常规打开和构建无需旧几何JSON、raw纹理缓存或重新Import。

关闭本工程的编辑器后构建，使用全新运行名称：

```powershell
pwsh -NoProfile -File reverse-engineering/reconstruction/unity-project.ps1 -Action Build -RunName formal-new
```

构建只使用已保存且已启用的场景，要求Title在首位、Apartment启用。不会执行模板同步、创建或保存场景，也不重写设置；构建前后对维护文件的字节哈希做对照，变化即拒绝通过。结果输出到工程外的 `../.cache/formal-new-build`，旧输出不会覆盖。

`Reconstruction/Import Apartment (new assets only)`是显式一次性导入命令，已有Apartment资产或场景即拒绝；不得用它刷新手工修改。`Reconstruction/Validate saved Apartment (read only)`核对初始冻结导入合同，手工修改后可能按预期报告差异，不会修复或覆盖编辑。

本轮范围、来源、实际运行及保留缺口见[正式工程报告](../formal-project.md)。历史`unity-project`模板与`.cache/unity6-*`属于旧验收记录，不会自动同步到这里。
