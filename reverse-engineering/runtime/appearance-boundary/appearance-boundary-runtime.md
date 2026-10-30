# 持久身体贴图：保存数据与实际材质恢复

2026-10-30独立副本完成TattooDark2、BodyOil8及组合3组受控保存/扰动/加载/原生应用对照。67条REA消息未截断，无脚本或引擎错误；3份密文独立解码出10项bool图及零/false的临时涂料字段。此处不将准备阶段的静态查询或自然UI可达性当作运行结果。

| 条件 | 保存参考 | 扰动 | 单独Load后 | 原回调后 |
|---|---|---|---|---|
| tattoo | 4槽、身体MatCap黑 | 3槽、白 | 保持扰动3槽、白 | 4槽、黑 |
| oil | 3槽、白 | 4槽、黑 | 保持扰动4槽、黑 | 3槽、白 |
| combined | 4槽、白 | 3槽、黑 | 保持扰动3槽、黑 | 4槽、白 |

每组先将bool字典配置并调用原PlayerController初始化回调30_0建立参考；原Save后，反转2/8并再次原生应用形成真实扰动；原Load恢复数据对象和字典，但材质仍保持扰动状态。随后原30_0→身体事件→SetupMaterials→ApplyOptions各进入1次，实际材质槽结构立即恢复。9次应用的即时snapshot中，末尾新建Sweat材质的tweak均为0，10帧后均为-1；其余所录shader、纹理和颜色与对应稳定状态相同。alpha字段始终-1，因此不能把字段值直接当作即时材质参数值。3组9次序列，加cleanup的1次共10次；每组reference仅1次Save、restore仅1次Load，没有把消费者进入笼统称为重复广播。

实际renderer/controller始终同一对象。材质顺序为两个基础槽、可选TattooDark、末尾Sweat；BodyOil只把第二基础材质MatCap变为白或黑，不增加槽。保存字典与独立解码一致；恢复后逐槽shader、主纹理指针/名称、颜色、透明参数及顺序与参考一致。基础两槽的Skin/Shade RGBA始终与初始状态相同，不能把油的MatCap变化当作肤色/alpha变化。动态材质指针只标识实例，不要求与原资源资产或上一次新建实例相同。

观察入口RVA：Save 0x49cdf0、Load 0x49d380、玩家30_0回调0x645ed0、身体事件0x638640、SetupMaterials 0x637bc0、ApplyOptions 0x638680。每段接收器与snapshot的materialController指针相符，进入次序及同帧条件均单独验证。它们只覆盖显式标记括起的受控调用；部分返回地址位于GameAssembly范围外，不将相对返回值误当作可用RVA，也不据此宣称完整调用边覆盖。

临时涂料remaining一直0、reusable一直false，BodyPaintController状态0、alpha -1。本批未进入120秒道具路径，没有计时器、物理或清洗行为的验证。其他8个持久图键在这些条件中均false，不构成其实际贴图覆盖。

cleanup明确核对全局根/槽位、stop=false和原sharedMaterials指针恢复。原shared数组中已观察到的shader、纹理、颜色和透明属性、控制器引用及记录的状态与原始snapshot一致。数组外RubberSuit材质属性没有单独观测，因此不宣称整个材质图完全等价；自然UI、冷标题重建、其他外观和物理仍待补。

会话2f47ca4b-64dc-4bfc-a5ee-6f2b957df81e，PID61804；加载Evidence为ev_fe8dabd9375d80b33db473ad9fbf1fc38043228b26951d52e564ce681c9f582e，最终状态为ev_2f8c36470678ff7d0dbd0d637a36613458d773440aae7f6ad4a3ef903980ea01。REA记录保留原provider authority/缺失subject限制；受控属性由夹具和输入指纹补充说明，未改写工具返回的权威级别。

本轮进程已正常退出、探针DLL归档。9份UserData、4份既往自然档及5项引擎/资源已独立核对不变。全部运行结束后已执行collect.py --finalize-plugins和analyze.py --inputs --require-finalized-plugins，两份原插件指纹恢复，无额外插件DLL。收集器默认保留pending供交错运行使用；最终状态以post-state.json为准。此脚本只读文件，不终止进程或移动插件。

离线入口为collect.py、analyze.py及test_analysis.py；14项反例/正例测试通过，覆盖缺失或重复事件、入口顺序/帧、保存图不一致、Load未应用材质、shader/颜色/槽位损坏、即时Sweat参数、cleanup属性损坏及新材质指针允许变化。47条存档路径重定向均位于本批working-profile下；场景为Apartment，时间停止为false，测试期间状态应用器受控冻结，cleanup后恢复false。manifest.json绑定冻结夹具与观察器、归档DLL、压缩日志、原始REA包/3份密文指纹及解码结果；results.json保留可重跑的结论与边界。旧compile-only.json和准备期README保留原始“待运行”状态，本报告和运行数据是后续完成记录。
