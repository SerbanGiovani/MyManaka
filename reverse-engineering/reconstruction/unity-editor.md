# Unity编辑器入口

2026-11-03起，后续独立工程默认使用用户指定的Unity `6000.6.7f1`：

```text
C:\Program Files\Unity\Hub\Editor\6000.6.7f1\Editor\Unity.exe
```

[editor-settings.json](editor-settings.json)记录编辑器与模板选择，[unity-editor.ps1](unity-editor.ps1)提供Create、Build、Open入口。正式编辑工程为`.cache/unity6-20261103-2`，生成程序为`.cache/unity6-20261103-3-build/ManakaInteraction.exe`。旧Tuanjie工程、源代码、存档和验收记录保持历史版本；新的Unity证据单独归档。

打开当前工程：

```powershell
./reverse-engineering/reconstruction/unity-editor.ps1 -Action Open
```

进入Unity后点击Play运行标题界面。Apartment几何、原模型和Animator在运行时加载；编辑状态的Title场景为空属于当前重建方式。后续全新构建使用新名称保留旧回执，例如：

```powershell
./reverse-engineering/reconstruction/unity-editor.ps1 -Action Create -RunName unity6-new
./reverse-engineering/reconstruction/unity-editor.ps1 -Action Build -RunName unity6-new -BuildRun unity6-new
./reverse-engineering/reconstruction/unity-editor.ps1 -Action Open -RunName unity6-new
```

构建采用Windows64 Mono、Built-in渲染管线、Legacy Input Manager（activeInputHandler=0）。当前源代码使用UnityEngine.Input，因此输入模式在启动批处理编辑器前写入新工程并验证。入口检查同工程的Unity／Tuanjie进程，保留进程Handle和真实退出码，已有日志或构建目录会要求使用新名称。

## Unity6适配与历史诊断

原Runtime在Unity `6000.6.7f1`中首次编译失败：`GetInstanceID()`为CS0619禁用API。新的[Runtime副本](unity-project/Assets/Runtime)仅将27处调用改为`EvidenceId()`，该扩展使用`EntityId.ToULong(GetEntityId())`保留完整64位值；两个缓存对象身份字段改为ulong。其余5份Runtime源码逐字节不变，输入、PlayerAction、动画与保存逻辑没有另行改写。

[迁移合同](unity-project/runtime-migration.json)固定9组原／新源码SHA及精确替换规则。日志保留instanceId等旧字段名，但Unity6值为完整EntityId，仅用于同一进程内的引用与事件关联；它不等于原游戏对象身份，也不与旧进程的数字比较。现有JsonText与Python JSON分析保持完整整数，不经过JavaScript Number、散列或32位截断。

新Editor构建适配使用NamedBuildTarget.Standalone、NET_Standard及显式Built-in／输入检查。第一次启动的旧脚本只留下null退出码，虽然私有引擎日志报告成功，仍作为不可确认OS退出码的诊断保留。正式重新创建观察到退出码0；首构建的CS0619与退出码1另存，随后成功构建0错误、2警告。

## 验证范围

本轮使用新的Unity程序进行受控动作与冷读档验证，结果见[运行清单](unity-editor-runtime.json)与[独立受控分析](unity-editor-runtime/controlled-acceptance.json)。旧Tuanjie的人工键盘验收仍属于旧引擎；本轮没有重新观察实体键盘。

| 项目 | 本轮实际结果 |
| --- | --- |
| 创建／构建 | Unity6000.6.7f1；创建与构建进程退出码0，构建0错误、2警告，341个构建文件指纹 |
| 受控进程46836 | 原Player／ManustiaAvatar、269绘制／33碰撞／90纹理；真实原AnimationEvent330帧→同帧None；锁内119帧模拟输入，331–337帧CC恢复 |
| 拾取／保存 | 原钥匙夹具隐藏，库存10000从1到2，自动保存revision1，float32位读回一致；不声称F5／F6实键验收 |
| 冷进程46056 | 加载同一SHA存档，物理更新前位置与Quaternion精确恢复；库存2由文件独立解析，没有第二份运行内存数量快照 |
| 限制 | 1232条缺失脚本警告、12处材质替代、5个builtin mesh未解析；回调记录的意外引擎错误0，原shader与完整画面等价未证明 |

两个运行进程均正常退出，50份公开归档由独立校验器核对。存档SHA256为`c46b14e8700e1ba04e37cd996f2b2950e3c3db94946dfd9a6212454bfe49d3b8`。冷启动时钥匙夹具仍按每进程重建，不代表原世界掉落持久化。

原资源仍通过既有Apartment几何桥与解密模型包载入，有限范围为原钥匙夹具、Locomotion及Action层。原shader／材质、缺失脚本、builtin mesh及完整玩法兼容性继续按实际结果披露，不能将编译成功称为完整原游戏兼容。

```powershell
python -B -X utf8 reverse-engineering/reconstruction/verify-unity-editor.py --inputs
python -B -X utf8 reverse-engineering/audit.py --inputs
```

授权及原始编辑器日志保留在本机`.cache`，仓库只记录安全回执与日志指纹；运行事件、截图、构建源码快照和独立JSON存档单独归档。后续重新验证应新建运行目录。
