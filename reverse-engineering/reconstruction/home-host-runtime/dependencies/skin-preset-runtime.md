# 原生肤色预设0/1、自由色扰动与材质应用

2026-10-30在独立副本完成两组受控保存→自由色扰动→加载→原玩家初始化回调。原`MCustomizeColor.Instance`与`AssetReferencer.MCustomizeColor`核对为同一资源；先读取`SkinPattern[0/1]`的`BodyPrimary/BodySecondary`作为独立期望，再核对真实body与face材质的基础色、阴影色及Renderer槽位。没有把原生基准材质本身当作期望值来源。

| 预设 | 原资源Primary RGBA | 原资源Secondary RGBA |
|---|---|---|
| 0 | `[1,1,1,0]` | `[1,0.8745098,0.8784314,0]` |
| 1 | `[1,0.9957806,0.93670887,1]` | `[0.9528302,0.94414085,0.8224902,1]` |

预设0的alpha确为0，预设1为1，均保留原始值。预设分支实际位于既有REA反编译的`PlayerBodyCustomizeAdjuster.OnChangeBody`（方法14602，RVA`0x632dc0`），没有独立的SetSkinColor方法。`CustomIsSkinColorFree=false`直接使用主表的两种RGBA；`true`才按RGB/255生成主色并计算阴影。原实现先索引SkinPattern，再判断free，故自由色扰动也保持合法索引0/1，没有用非法索引绕过守卫。

每组保存`free=false`、所选索引以及被预设分支忽略的RGB`[13,71,199]`，随后设为`free=true`、RGB`[17,203,91]`并调用原广播。实际body/face主色变为约`[0.06666665,0.79607844,0.35686272,1]`，阴影也改变。原生Load返回时，数据重新成为false/原索引/`[13,71,199]`，但材质仍完整保持扰动图；显式调用原玩家`<Initialize>b__30_0`后，颜色立即恢复，并在十帧后仍与主表RGBA一致。没有重复Initialize或新增事件订阅。

实际缓存接收器与Renderer引用逐一对应：body位于身体Renderer槽1，face位于脸部Renderer槽2；原生同段还写Sweat（身体槽2）及face-option（脸部槽6），四个Renderer材质目标均核对基础色和阴影色。两组最大RGBA偏差分别为0和约1e-7。身体/脸部Renderer保持原实例，Sweat等新实例的指针不要求等于上次材质或资源资产。两份加密capture及一份独立baseline重新解码，分别核对五个选定字段、手动槽1和未选定标量外观字段稳定；未发布完整明文。

REA共33条未截断消息，无脚本或引擎错误：7次标记、7次原玩家回调、7次body消费者、7次结束，Save与Load各2次，ready1条。七组消费者为两组各reference/disturb/restore，加一次cleanup；均在Unity主线程同帧进入所选消费者，十帧后结束。进程会话`cba4cc57-1948-4d3b-abe8-81d7e9ba8b74`、PID21048；load Evidence `ev_3e31896e2e2af1feb18d12d21bcf13169bec57b92fe8cdbdfba5a1d56b851c22`，status `ev_dcea3db349f2ca41f850b7f0cf2d486c22563b0e9e8bac5c90e014bf813d6310`。这些是入口钩子，没有补造未采集的返回。

托管日志保留6次readiness：Title4次，其中前三次MHair尚未就绪；Apartment2次均就绪。启动编排曾因读取旧readiness触发root Python断言，随后run_cases按新记录游标修正；Probe、build及observer未改，游戏无runner_error。完整日志保留，不能把这个编排断言说成游戏异常或删除旧记录营造单轮成功。

本轮先Load脱离原全局数据根，再改变夹具字段，全部保存路径指向独立working-profile。测试阶段显式设置`IsStopGameStateApplier=true`隔离自动状态应用，实际`IsTimeStop=false`；这属于受控夹具，未模拟自然暂停。结束时回写15个全局根、槽位和原applier标志（false）；原Renderer的sharedMaterials、8个body缓存材质引用、3个材质控制器引用及所备份材质的全部shader Color属性均执行恢复，托管检查全部为true，公开body/face/Renderer快照也与原始相等。原主表、预设数组和两项RGBA保持不变。此处的全材质颜色恢复由夹具内部逐项比较，外部快照只展开上述body/face/Renderer目标，不宣称完整shader/纹理/物理图等价。

原生cleanup及REA脱离完成后，隐藏测试窗口的MainWindowHandle为0，CloseMainWindow返回false，等待20秒仍未退出；操作方核对精确PID和路径后停止进程。关闭凭据如实记录`forced_after_close_timeout=true`，这次不是正常退出，也没有观察到游戏崩溃。最后导出的REA状态仍为running，后续脱离由操作方确认，未伪造追加状态Evidence。原插件与9份UserData、4份前轮自然档、5项引擎/资源输入的最终指纹以post-state和严格复核为准。

范围仅为free=false预设0/1和一次明确自由色扰动。其余外观字段、物理、冷启动重建及自然UI读档分派仍在范围外。`collect.py --finalize-plugins`收集最终指纹，`analyze.py --inputs --require-finalized-plugins --check`重新解码密文、核对完整原始导出/日志、固定源码、归档DLL、原件和当前插件清单；`test_analysis.py`的22项校验包含颜色alpha、实际槽绑定、额外接收器、Load未应用、消费者、清理、手动槽和轮询历史等反例。
