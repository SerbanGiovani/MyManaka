# 掉落物管理器冷缓存、复用及失效对象重建

2026-10-30，依优先级第1项。独立副本`E:\ManakaREA-NaturalGameplay`，工作目录`DropColdCache/20261030-1`，全新working-profile从自然第二槽复制。原UserData与前轮自然档均不参与写入。

## 结论

冷缓存指DroppedItemManager自己的实例缓存为空，并不表示资源包或预制体尚未加载。原生GetCache从AssetReferencer的DroppedPrefabs（+0x320）或MultipleDroppedPrefabs（+0x328）选择现有预制体，经同步Instantiate、GetComponent、DroppedItemController.Initialize后缓存并返回。本轮普通物品0/4的观察与该路径一致，不存在等待资源异步完成回调的阶段。

| 场景 | GetCache次数 | 实际克隆/Initialize | 原生消费者返回 |
|---|---:|---:|---|
| 管理器空缓存 | 2 | 2：物品0、4 | 同帧完成；当前场景0激活，异场景4隐藏 |
| 再次恢复 | 2 | 0 | 同帧复用完全相同的组件与GameObject |
| 销毁缓存物品0后再恢复 | 2 | 1：仅物品0 | 原生删除失效项并重建；物品4保持原对象 |

异场景Hide也会调用GetCache，因此它可能创建随后保持隐藏的缓存对象。这种创建不能误计为异场景错误激活。未掉落物品3始终没有进入实例缓存。

## 保存与对象对照

在自宅冻结GameStateApplier，以明确受控的记录配置建立：物品0已掉落、场景Apart；物品4已掉落、场景Residence。管理器缓存替换为空容器，配置前未调用Drop/GetCache。原生Manual Save/Load读回新状态根，独立解码91,360字节文件，与记录位置/四元数和场景逐项对应。SHA-256：`4be9fb64ed79287e4409435e5284ec86a483c56df862f7ca009dfc005c7f48fe`。该文件是本轮工作档，不是原用户档。

帧2338的首次ActiveDroppedItemIfNeed和紧接着的重复调用均同步完成，首轮缓存0→2；第二轮不新增对象。主动销毁物品0后，帧2348确认字典仍有旧键和旧组件包装器，但Unity对象已失效；第三次原生消费者返回新组件/GameObject，缓存总数仍为2。其余缓存对象保持相同指针。后续一秒采样保持当前对象激活、异场景对象隐藏、姿态与文件一致，最后恢复原缓存和停止标志。

47条未截断原生消息连接六次GetCache入口/返回、三次原始克隆、三次Initialize及三次恢复。每次新对象的克隆source与AssetReferencer相应预制体指针一致；克隆返回GameObject、初始化组件、缓存返回及运行对象逐项连接。七个选定加载入口在受控窗口内均未命中：BridgeAssetBundle与EncrypterCore的同步/异步入口，以及三个Unity AssetBundle异步入口。该负证据限于这些入口和本轮窗口，不代表穷尽引擎内部所有资源访问。

## 证据与边界

静态使用[既有GetCache、Drop、Hide、激活、Save/Load和克隆辅助证据](salt/evidence/drop-cache-chain.json)，不重复运行已完成的反编译。AssetReferencer身份由usage`0x182d58238`绑定，不能凭全局指针位置把它误称SystemManager或GlobalData。

REA会话`39457486-1a0a-441d-81b2-75cd0f364450`、PID32812。脚本加载Evidence`ev_e59ee703c703add736b672777a6843fb889564a5a4f30d2a7e2d9d380495d2d8`；最终状态Evidence`ev_e4ac7d6679a0dd9f738a26207a7bdaa60af21a36eb9bbe60a6aa0abf6a165f1b`。模块路径、磁盘指纹及PID另行验证，不改写REA对Frida的空subject边界。

[results.json](runtime/drop-cold-cache/results.json)由分析器生成；8项测试覆盖非空缓存伪装冷启动、重复克隆、意外加载调用、异场景错误激活、无真实销毁、错配存档姿态及清理失败。引擎Error/Fatal0，9份UserData、4份前轮自然档及5项引擎/资源输入不变。进程正常退出、REA分离、原插件恢复。

本轮完成普通掉落物管理器冷/暖/失效缓存覆盖；不宣称资源包冷加载、预制体缺失恢复、高物品ID、多实例模型族或完整自然玩法已验证。接下来进行优先级第2项：场景退出/对象销毁期间的排队回调与清理。
