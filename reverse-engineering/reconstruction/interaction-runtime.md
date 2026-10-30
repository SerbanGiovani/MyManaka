# F交互、原动作层与移动恢复

2026-10-31已在独立Tuanjie工程接通真实F键→原钥匙交互→PlayerAction10025→原Animator动作层→原动画结束事件→入库及None→真实移动→F5/F6→新进程读回。人工运行、受控运行和新进程读回分别归档，独立分析不依赖程序的`passed`标志。

本机产物为`.cache/interaction-20261031-1-build/ManakaInteraction.exe`，窗口标题“Manaka Interaction REA”；源码在[interaction-project/Assets](interaction-project/Assets)。本轮构建Succeeded、0错误、1警告，三个运行进程退出码均为0。构建307个文件的指纹、95项打包输入及40份运行归档见[清单](interaction-runtime.json)。大型原资源、生成工程和可执行文件保留在本机忽略目录。

## 原件与接线

原Apartment的序列化交互区只有电脑14、床13、衣柜11，均进入UI菜单。本轮有限动作选用真实原`droppedhandcuffkey.prefab`，摆在独立Apartment的`(0.73,0,1.21904826)`；这个坐标是明确的重建测试夹具。完整原资源字节、原场景扫描和REA结果见[静态合同](interaction-evidence/README.md)。

| 环节 | 已接回的行为 |
| --- | --- |
| 候选与F | 复制原SphereCollider几何，实际Unity OnTriggerEnter登记候选，F GetKeyDown启动；已拾取／无目标拒绝 |
| 原callback15896 | LastPickUpItemType=5、跳过手铐检查、请求TransAction10025；原蹲姿守卫仍拒绝 |
| PlayerAction | None(-1)→PickUpItem10025；原MActionRecord.CanMove=false；忙碌时不重开 |
| Animator | 原Player controller、ManustiaAvatar与同一原clip引用，启用Locomotion0及Action1；OldActionId、ActionId、TransAction三写 |
| 原动作 | Action.PickUpItem，hash886742834，原2秒PickUpItem clip，骨骼及标准化时间实际变化 |
| 原结束 | OnAnimEndPickUpItem，事件时间1.9833333492279053，int0；校验isFiredByAnimator、原clip实例、原state与layer |
| 完成效果 | 同帧隐藏目标、item10000增加1、切回None；没有Scheduler等待或超时替代完成 |
| 移动 | CanMove关闭时两个目标速度归零，仍按原world10dt/anim5dt平滑减速；普通移动恢复后经CharacterController执行 |

ChangeAction(None)并不强制跳动画。原PickUpItem在exitTime1后按原图过渡到NoMotion；工程没有用Animator.Play/CrossFade或计时器跳过结束事件。新增事件来源校验属于重建防错措施，不冒充原接收器具备相同防伪守卫。

本轮REA两批共6次查询均成功关闭，含5份非空伪代码与1份空assembly响应；15896是新增函数，另4份非空伪代码是重查既有函数。空Listing保留为限制，不当作指令级佐证。新Assembly-CSharp经REA托管检查，SHA256为`1de70877fd056e883b0e54b62452bfbbba3c14d5bb96bc793c54fd1a0727efe6`；运行包不含原GameAssembly或BepInEx。

## 人工与受控证据

用户对“先F、D约4秒、再F、F5、F6”的操作要求回复“完成”。[外部输入回执](interaction-runtime/interaction/input-receipt.json)只提供人工来源声明，Unity本身不能识别物理键盘设备；实际输入接收与行为由连续帧另行核对。

| 进程 | 关键观察 | 验收范围 |
| --- | --- | --- |
| 真实键盘PID94856 | F2427；稳定原动作2442–2545；原事件2546→同帧None2546；库存1→2、目标隐藏；F2974/2990均无目标拒绝 | 真实F、原动画结束及之后的真实移动、单次效果 |
| 受控PID94672 | 明确模拟F/方向；CanMove锁内119帧有输入；原事件325→同帧None；CC恢复326–332 | 动作期间移动门、忙碌／按住／无目标守卫；不算真实键盘 |
| 冷读回PID97848 | 新processGuid加载人工进程写出的同SHA、revision2；物理更新前精确应用位置和Quaternion | 保存与新进程姿态恢复 |

人工运行首个非零方向输入在2599帧，晚于结束事件53帧；2599–3009连续CC恢复区间独立累计约7.32782035米。它证明动作结束后真实移动可用，但没有覆盖“动作期间按住方向”。因此严格单进程全链仍拒绝该项，`full_chain_accepted=false`；本轮功能对照由明确分进程的自然子链与受控移动锁证据组成。不会将模拟锁内输入提升成人工输入，也不要求用户重复已被其余证据证明的步骤。

逐项机器结果分别为[自然与受控组合](interaction-acceptance-tools/acceptance.json)、[受控子链](interaction-acceptance-tools/controlled-diagnostic.json)和[严格单进程未覆盖项](interaction-acceptance-tools/strict-natural-rejection.json)。

F5和F6各记录一次。F5保存后继续运行，F6保存并退出；最终revision2的位置为`(0.9195809960365295,0.00009971857070922852,1.2981866598129273)`，Quaternion为`(0,0.9680323600769043,0,-0.25082552433013918)`。冷进程在物理更新前逐float32位恢复；存档SHA256为`f466eb7f14275ab12bef4821ec67d6f2389a8347ee45d5cf59ec7c4763baff20`。

独立解析最终及备份JSON均确认item10000=2。冷进程加载同一完整存档字节，但本轮冷日志没有第二份内存库存数量快照；不把文件数量校验写成额外运行时库存观测。钥匙夹具每次启动会重建，其自然掉落、场景持久化和自动用钥匙均未接回。

## 范围与下一步

原Apartment的269个绘制、33个碰撞、90张纹理和玩家4个渲染器继续使用。当前仅启用Locomotion、Action两层，其余10层权重0。每个进程均有1232条已记录的原脚本缺失警告；玩家与钥匙共12处材质替代、5个builtin mesh未解析。回调记录内意外引擎错误为0，完整player.log另行保留；原shader兼容性仍未证明。

工程InteractionManager直接启动PlayerAction，再更新motor；原callback先写TransAction，原Locomotion更新后由PlayerAction.OnUpdate消费。因此同帧C+F会有明确差异：工程先拾取再抑制蹲姿，原顺序可能拒绝。这一轮没有宣称完整帧内调度等价。手持衣物、非Idle、ecstasy及全局活动子系统限制为中性值，转向／重力／Update积分继续属于重建。

下一步优先接回原电脑、床、衣柜的UI交互与保存／睡眠入口，再扩展其他有限动作的原完成回调和打断守卫；随后补齐同帧输入调度及其余动作层。原任务、NPC、物品世界持久化和完整玩法还需逐项迁移。

## 复现与只读校验

```powershell
python -B -X utf8 reverse-engineering/reconstruction/interaction-evidence/make_manifest.py --check
python -B -X utf8 reverse-engineering/reconstruction/verify-interaction-runtime.py --inputs
python -B -X utf8 reverse-engineering/reconstruction/interaction-acceptance-tools/verify_interaction.py --help
python -B -X utf8 -m unittest discover -s reverse-engineering/reconstruction/interaction-acceptance-tools -p 'test_*.py'
python -B -X utf8 reverse-engineering/audit.py --inputs
```

验收命令及自然／受控配置见[独立分析器](interaction-acceptance-tools/README.md)。重建使用新RunName保留历史回执：

```powershell
./reverse-engineering/reconstruction/check-editor.ps1 -RunName interaction-new
./reverse-engineering/reconstruction/build-interaction.ps1 -ProjectRun interaction-new -BuildRun interaction-new
./reverse-engineering/reconstruction/run-interaction.ps1 -BuildRun interaction-new -RunName interaction-new -Phase interaction
# 首轮F6退出后，只读冷读回同一独立profile：
./reverse-engineering/reconstruction/run-interaction.ps1 -BuildRun interaction-new -RunName interaction-new -Phase phase2
```

启动新profile时通过标题导入选定原档投影；运行期间只写独立JSON。旧minimum／locomotion工程、诊断、存档与验收报告保持历史原样。
