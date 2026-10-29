# 下次继续

2026-10-30更新：下述为上轮暂停时的历史状态。第二槽现已通过正常电脑保存产生主档并完成自然标题读回；测试进程已正常退出。当前继续入口改为[下一轮说明](../natural-title/next-run.md)，本轮结果见[自然标题读档闭环](../../natural-title.md)。

用户于2026-10-27要求验证后暂停等待下次运行。独立游戏PID49736曾成功挂起，随后有AppHang关闭记录，收尾时进程已不存在。内存现场没有持久保留；暂停凭据为历史记录，不要对旧PID执行恢复。hold-process.ps1保留为操作记录，启动时间校验会拒绝被复用的PID。

下次需重新启动 E:\ManakaREA-NaturalGameplay\SecretFlasherManaka.exe，连接新的REA会话，不复用旧session_id。附加插件NaturalLoadObserver.dll与原NaturalObserver.dll保留在副本。隔离配置为NaturalLoad/20261027-2/profile.txt，存档根仍是E:\ManakaREA-NaturalGameplay\NaturalLoad\20261027-2\nonempty-A。原UserData未变。

自然新游戏选择手动槽1；实际文件为SaveDataBackup/1.sd，没有SaveData/1.sd。优先核对原生备份恢复入口，或通过正常自宅电脑“保存”创建主槽，再记录标题继续、场景就绪与玩家姿态。不要把不存在的主槽当作已成功读回。

新采集使用新的脚本版本和输出文件，保留本轮证据与指纹。默认force=true、IsDebug=false，两个启动均强制重生，loaded=false；Residence有5名非固定NPC时保存列表仍空。不要手动OnLoadData或改force补造自然正例；条件对照须另列受控测试。备份和证据已保存，本轮工作等待用户下次继续。
