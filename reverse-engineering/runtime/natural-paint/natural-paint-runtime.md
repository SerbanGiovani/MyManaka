# 自然涂料使用、保存与新进程标题读档

2026-10-31在隔离副本以用户真实界面完成普通涂料5、清洗剂9、无限涂料8，并闭合自然保存、同进程标题重建和真正新进程读档。使用阶段6596条、冷启动阶段248条REA消息均无provider截断、脚本或游戏引擎错误。托管退出命令有一次文件共享冲突，原样保留，随后重试退出成功；不能将整个采集称为完全无异常。

观察器只隔离SaveRoot、读取原对象与材质、复制密文、记录标签及最终正常退出，没有改库存、钱、技能、心跳、剩余值或调用游戏操作方法，也没有克隆控制器或强制BodyPaint类初始化。原生自然动作与用户输入共同支持来源；原9份UserData、4份前轮自然档、5项引擎/资源及原插件均受指纹保护。

## 兼容档与自然取得

最初按库存选择的原UserData第1槽不兼容冻结资源：激活配件70008至70013映射RCosplay分类7的索引8至13，原表只有8项，真实初始化抛RCosplay.Get索引8异常，随后输入/相机空引用。主PlayerCostumeDict为空，不能把它归因于主服装ID或体型必然错误。这轮完整引擎日志和原生保留历史独立作为失败诊断；provider ring确有截断，导出完整保留内容不能恢复早先丢失消息。工具inline超过10MB的显示限制是另一层问题，正式导出没有因此丢失。

正式重新复制原第2手动槽`UserData/SaveData/1.sd`，SHA256 `d69bcd2a1ff6f229c2698eedfa895416a4f5b3f87dbb9d8357e40dc1c6f803f6`，未修补存档。其原存款53043、经验72833、目标库存全缺；用户通过正常电脑商店取得物品。42个已有配件、112个配置键、188个强化/锁键、21套配装及当前发型/眼/肤色索引都按原资源预检，随后完整原生初始化及实际控制通过。库存和兼容性细项见profile-inventory.json；这不是新角色自然成长或解锁升级验证。

原物品记录确认5/8/9分别是普通涂料、无限涂料和清洗剂；8/9可重复使用，三者IsDelayConsume=false。原商店解锁条件为ExposeExp>=5000，不能拿现金替代经验。本观察器没有完整钩住单笔支付入口，原资产价格与自然取得数量分别表述。

## 按钮、三秒动作与真实效果

| 类型 | 调度GameTime | 完成GameTime | 实际结果 |
|---|---:|---:|---|
| 普通5 | 117.6992798 | 120.7172546 | 在UseProcess中先扣1，调度时库存已0；约3.017975游戏秒后remain120、state2、Current1、reusable=false |
| 清洗9 | 244.5164337 | 247.5281982 | 库存保持1；约3.011765游戏秒后remain0、state4、Current约0.4，随后自然淡出 |
| 无限8 | 471.8092651 | 474.8127441 | 库存保持1；约3.003479游戏秒后remain120、state2、Current1、reusable=true |

三条均经过真实Inventory按钮、UseProcess和MItem.UseItemProcess，设置动作10008、Time.time+3截止及对应委托；原PlayerAction.OnUpdate在游戏时间严格超过截止后调用委托，再回到动作-1。没有用墙钟三秒或“已进入MItem”代替实际效果。无限版确认弹窗可跨按钮方法返回，不强造同步嵌套关系。清洗回调内联状态赋值，未命中独立OnUseWashItem入口不算漏发。

使用阶段1687个精选原生paint更新返回按真实deltaTime/Dokidoki重算float32计时、MoveTowards和状态切换，实际身体涂料材质/Renderer绑定及透明值也被采到。原生更新只在事件窗口、状态变更和每秒采样处展开，完整计数/累计dt另有汇总；不声称全部逐帧更新都展开验证。Body.Setup的大量进入包含原服装变更路径，不能计为重复物品效果。

## 普通标题重建与真正冷启动

普通涂料自然保存后，同进程回标题再继续，新的Pca返回remain109.57879638671875、reusable=false、state2/Current约0.4；这只算场景/玩家重建。

无限涂料自然保存文件独立解码为remain118.79891204833984、reusable=true、库存5/8/9=0/1/1，SHA256 `c71c2bf5861903ccae6700dbfe6df5783804334df8582d13d7f2de5921ba3fa7`。旧进程正常退出并确认不存在后，将工作profile四文件逐字节复制到新输出目录，再启动游戏，由用户正常标题继续第2槽。

Windows复用了PID85172，不能用PID不同作为唯一冷启动标准。旧关闭时间2026-10-30 16:59:56.2260583 UTC，新创建时间17:00:44.8123423 UTC，另有不同REA session、启动帧和对象身份，证明为新进程。读取同一密文后，原Pca.Initialize返回118.79891204833984/true、state2、Current约0.4、Target0及原速率约0.075，实际材质Tweak随后约0.4；LastItem、截止和委托从新对象默认值开始，没有重放使用物品来恢复效果。

冷路径将BodyPaint协调内联在Pca.Initialize中，不能因独立15011入口为0判恢复缺失。冷进程221个精选更新返回也符合模型；原生窗内观察到60边界state2→3，脱离后托管采样还观察到state4/Current0、最后remain约17.471851/true。没有自然耗尽至0的原生或托管证据，不宣称本批覆盖完整自然到期链。材质读取与activeInHierarchy不证明renderer.enabled或实际像素可见性。

## 证据与复核边界

使用会话`023e144b-89eb-4503-9fb6-ae684c2dc3f4`，最终status `ev_7b8e88bd6126709a6638defd364b8c8fd035043817c73ff8323be6b37d901531`；新进程会话`39175936-d69c-4919-a40e-c6f38d464082`，最终status `ev_28e1f1bb39dd194cab97585a418226a1a82a794053a3af01ec9eeebb6533a992`。按精确Evidence ID选取，不能把按ID排序的bundle最后一条当最新时间。REA保留原provider authority及subject限制，不改写工具记录。

旧失败诊断3条记录完整无损压缩为diagnostics-rea.json.gz，含原始provider截断标志；原JS源路径后被新版本占用，manifest按原Evidence ID/SHA绑定归档旧源码。完整引擎日志、最初异常栈及两阶段原始导出均保留。第一次Frida关闭迟滞未确认脱离，不补造确认；两次正式进程则均确认脱离、Unity线程正常退出，原插件最终恢复。冷关闭前操作方一次DateTime/字符串比较误报与退出后Process.Path为空仅是操作方核对过程，不是游戏异常，原关闭观测凭据保留。

使用进程唯一command_error位于退出命令读取，文件共享IOException；humancomplete此前已记录，三帧后quit_requested成功，状态/文件采集未报错。存档操作均留在独立profile；自然运行对象会随游戏变化，不声称它们在退出前回滚为原世界。复核入口为collect.py --finalize-plugins、analyze.py --inputs --require-finalized-plugins --check及test_analysis.py。未发布完整存档明文。
