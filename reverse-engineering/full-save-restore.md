# 完整存储字段与缺键、损坏主档

2026-10-30，优先级第3项第一批完成12个受控条件，保留42条未截断REA原生入口消息、38份加密捕获的逐字段投影和完整托管日志。调用来自Unity主线程，存档路径限定为一次性目录；没有修改原始游戏或既有存档。

四个根对象的256个显式存储字段全部纳入投影：GameStateData107、PlayerCustomData66、OptionData68、TutorialData15。游戏档4个顶层键、系统档9个顶层键均保留类型与指纹；数字键与字符串键不混同，浮点按float32比较。完整档第一次和第二次原生加载/保存的游戏数据均无变化；既有进阶档只有槽号0→1变化，第二遍无变化。系统档每次只有第二手动槽保存时间ticks更新。

| 输入条件 | 原生Load/Save结果 |
| --- | --- |
| 完整原生档、既有进阶档 | 各两遍成功，游戏第二遍0变化 |
| 缺GameStateData根 | 默认补齐，第二遍稳定 |
| 缺PlayerCustomData根 | 默认补齐，第二遍稳定 |
| 缺ItemDict、被动技能字典或任务完成字典 | 对应字段写为空字典，第二遍稳定 |
| 缺SkillLevel | 补49个技能条目，第二遍稳定 |
| 缺CurrentStageType | 补为0，第二遍稳定 |
| 密文截断7字节 | 原生ArgumentException |
| 首个密文块异或损坏 | 原生FormatException |
| 合法加密但明文语法损坏 | 原生FormatException |

三种异常条件均放置有效备份后调用原`SaveManager.Load(Manual,1)`；各只进入一次Load，没有成功返回或后续Save。调用未自动切换至备份。这个结论仅适用于选定入口，不能扩展为所有标题/UI异常处理均无恢复能力。显式原生复制备份、整个文件缺失及系统档异常仍待下一批。

每个条件结束后，15项全局值/引用及选定状态均与该条件开始一致；最后恢复applier。6项测试通过。9份UserData、4份前轮自然档及5项引擎/资源输入哈希未变。游戏正常响应并经CloseMainWindow正常退出，临时DLL归档、原插件恢复。REA关闭请求未在等待期返回，等待执行已终止；未宣称确认detach。退出前的完整REA证据已先导出。

这证明选定存档在原生对象构造与再次序列化后的数据稳定性，尚未证明库存使用、外观渲染、任务更新或技能效果等所有运行消费者等价。引用别名、版本迁移、任意字段缺失及独立工程仍保留边界。

证据目录：[runtime/full-save-restore](runtime/full-save-restore)。`projection.json`保留全部根字段哈希及变化路径；完整加密档留在测试目录，未提交游戏存档。重新验证：

```powershell
python reverse-engineering/runtime/full-save-restore/test_analysis.py
python reverse-engineering/runtime/full-save-restore/analyze.py --check --inputs
python reverse-engineering/audit.py --inputs --write-index
```
