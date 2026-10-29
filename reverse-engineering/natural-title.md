# 自然电脑保存、标题读档与自宅归位

2026-10-30完成。独立副本 `E:\ManakaREA-NaturalGameplay`，分支 `codex/rea-salt`。本轮闭合上轮U024：真实新游戏→自宅电脑保存→返回标题→继续第二个手动槽→自宅就绪。所有游戏操作由用户通过原界面完成；探针只隔离存档路径、读取原生入口/返回及Unity主线程状态，没有改守卫、重放OnLoadData或直接加载场景。

## 结论

1. 初始第二槽只有 `SaveDataBackup/1.sd`。真实点击该槽会检查 `SaveData/1.sd` 后直接返回，没有Load、场景切换或备份回退。用户报告界面无备份/恢复入口。本轮选定路径不能读该备份；不据此宣称整个游戏不存在其他恢复入口。
2. 新游戏选择第二槽后，自宅电脑按钮确实调用 `Save(Manual,-1,false)`，最终槽位解析为1，生成91,280字节的主档 `SaveData/1.sd`。这与上轮调度器触发的备份保存分别记录，不能互相替代。
3. 独立解码主档、原生Save返回、标题Load返回、新玩家Warp位置与四元数在float32精度逐项一致。标题读回创建新的GameStateData，随后经过Springboard、InGameStart、Warp及延迟启动，实际进入Apartment，逻辑场景为Apart。
4. 归位后的20个实际Transform位置样本覆盖约9.689秒；首样本偏差0.00459毫米，最大偏差0.15491毫米。物理落地后持续更新存储位置，这种微小变化不应判作读档错误。实际Transform旋转未采样，朝向结论限于文件、状态字段及原始Warp实参。
5. 新游戏和读回两次启动都保持 `force=true, IsDebug=false`，调用强制RepopNpc，`isLoadedData=false`，没有OnLoadData。本轮在自宅没有NPC，未新增非空NPC自然恢复的正例；此前Residence与受控恢复的证据仍分别保留。

## 原生时序

REA会话 `31b7857c-f690-4b31-b674-c3fa568bcd8f`，PID4276。单个脚本，无中途替换；最终状态包含71条消息，未截断、无脚本错误。地址均为GameAssembly相对RVA。

| 帧 | 原生事件 | 对照 |
|---|---|---|
| 3502 | OnClickItem(Manual,1)入口/返回 | 只有主档路径检查，没有Load |
| 6307 | Load(NewGame,1)，调用点`0x4e4331` | 创建自然新档，NPC列表为空 |
| 6755 | PcMenu.OnClickManualSave→Save | 调用点`0x4caf20`，type3/slot-1/isBackup=false |
| 6755 | PreProcess(false,1,false)→主档写入→Save返回 | 解码姿态与返回字段一致 |
| 10651 | 返回标题后的Load(System,-1) | 不算游戏槽读回 |
| 10751 | OnClickItem(Manual,1)→Load(Manual,1) | 调用点`0x4e5229`；PreProcess(false,1,false) |
| 10762 | Springboard | 原始生命周期 |
| 10763 | InGameStart→PlayerWarp | 调用点`0x4979ff`；文件位置/四元数一致 |
| 10765 | 延迟启动→RepopNpc | 调用点`0x498bb3`；force1/loaded0 |
| 10768起 | Apartment实际玩家采样 | 活跃管理器`0x2d392d7bcf0`，初始化完成 |

主档SHA-256：`5b90c9cebbc37810d2671ce2f42ce1ac2b6eb05505ba84f2a0ed6d759f75a5b0`。保存位置 `[0.343850672,0.0000582337379,1.1726408]`；读取后原生实参精度比文本更多，分析器先转float32再比较。返回标题与读回后主档哈希不变。

## 静态依据与范围

新增两份非空REA/Ghidra查询，复用已绑定的Save、Load、主路径、电脑按钮及标题入口；详见 [natural-title-chain.json](salt/evidence/natural-title-chain.json)。

- PreProcess，17409，`0x4ba110`，Evidence `ev_29ac5da0f24e0391bd9b562cf0c34038cc97b8fb31926c458a297fd31b707def`：三个形参由原始metadata命名为isSystem/slot/isBackUp，分别写静态字段0/8/4，再通过GetSaveDataPath生成当前路径。
- OnClickManualCategory，17863，`0x4e52b0`，Evidence `ev_5cdb97461d6ce079a153d54092b35b94b0f521f4bd8727b308086de67460656d`：生成手动分类槽项；与实际手动槽点击记录对应。它未提供本轮所需的备份恢复分支。
- 已有Load查询明确调用PreProcess(false,slot,false)，而Save将isBackup传入PreProcess。电脑按钮已有查询硬编码false；本轮首次同时采到按钮→Save第三实参→PreProcess第三实参→实际主档路径。

原生采集Evidence：脚本加载 `ev_06a36b7fbb27a6a89daf34587f31da1d3759ec10a5da4a87185349e2f7068db4`；最终状态 `ev_296597d5063ca4e2ba419a26cf96a23d1d23d61e473fa71c21016a413f03e969`。原始REA对Frida报告artifact identity unavailable；本地审计补充模块实际路径、PID、原DLL/metadata与副本指纹，而不改写REA原始authority。

目录仍有上轮受控来源的槽0，本轮从未加载它。自然结论只取本轮真实NewGame生成的槽1。加密输入/主档快照和临时DLL只保存在忽略的.cache中，仓库不保留游戏二进制或完整存档明文。

## 校验与收尾

[results.json](runtime/natural-title/results.json)由可重跑分析器生成。8项测试覆盖完整对照、备份混淆、错槽、解码位置错配、Warp朝向错配、主档缺失、错误NPC正例及活跃管理器错配。引擎Error/Fatal为0；9份原副本UserData、5项冻结原件/副本引擎资源指纹未变。

REA已卸载并分离；测试副本通过正常窗口关闭请求退出，未挂起、未强杀。临时NaturalLoadObserver替换前后均在进程不存在时操作，现已恢复上轮DLL，旧审计指纹保持有效。第二槽主档、原备份和新日志留在隔离目录。下一步参见[继续入口](runtime/natural-title/next-run.md)。
