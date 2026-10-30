# 原档只读导入与独立版存档

最小运行链采用离线导入：prepare_seed.py只读已验证的自然涂料存档，使用现有ES3解码器生成有效JSON seed；独立Tuanjie程序只读取seed，并将后续进度写入专用profile的save.v1.json。运行时没有ES3写回、GameAssembly依赖或原对象/引用重建，原始.sd不会被写入。

默认来源为NaturalPaint/20261031-2的自然保存1.sd，SHA256 c71c2bf5861903ccae6700dbfe6df5783804334df8582d13d7f2de5921ba3fa7。导入scene0为Apartment、原Unity世界位置、四分量Quaternion，以及库存全部12项、所选身高/发型/肤色数据和118.798912/true的涂料字段。原坐标y约-0.000463，独立碰撞体接地可能稍作矫正；读取前/后及移动后的实际Transform应分别记录，不能以地面矫正伪称源数据丢失。旋转不是Euler角，投影明确舍入为运行时float32。

SaveBridge.cs提供SaveState与SaveStore。TryImportSeed读取revision0的ReconstructedManakaSeed；TryRead读取ReconstructedManakaSave；Write保留业务字段，更新revision/UTC，并原子替换独立JSON及保留前一版本.bak。调用方提供当前进程Guid。已存在但损坏或版本不符的独立存档会返回错误并阻止覆盖，不静默重置为seed。

scene/pose真正参与最小闭环。库存、涂料和选定外观数据被保留，不代表本轮已经实现对应原版效果、骨骼、配色或完整玩法；其余原保存字段不在导入范围内。完整原存档明文不落盘；选定seed只放忽略的.cache目录，仓库记录来源/源码/投影指纹。若随构建提供seed，应复制到.cache生成工程的StreamingAssets/seed.json，或传--seed绝对路径。--profile-root指定独立存档目录。

复现：python reverse-engineering/reconstruction/save-bridge/prepare_seed.py；python -m unittest discover -s reverse-engineering/reconstruction/save-bridge -p test_seed.py。seed-manifest.json绑定原cipher、解码器、字段投影及运行时存储源；生成器拒绝seed或manifest覆盖输入源。最终“标题→加载→自宅→同一Motor移动→保存→关闭→新进程恢复”须由编译后的独立程序两阶段回执另行证明，离线投影测试不能代替它。

可见模式正式验收已闭合上述最小链：minimal-20261031-3构建的两个独立进程89908、92192均正常退出（exit0），两次运行Guid不同。第一进程通过标题加载seed，使用与实际输入相同的PlayerMotor路径注入测试轴，记录接地、碰撞和约0.9895米净位移，写入revision1；第二进程经标题读取该独立JSON，在物理启用前恢复位置(1.19842803,0.024999857,0.73992157)和Quaternion。离线逐分量float32比较位置与旋转均完全一致，独立计算的位置/旋转误差均为0。独立保存SHA256为c66ab968c85f45cf864ea7b7e8fa4d1c2de63af961e8a91636261dfbcc3aaf6d；库存12项（含物品5的零数量键）、选定外观与涂料字段保持不变。该输入验收没有测试实体键盘。

acceptance-inputs.json仅指向跟踪归档，verify_roundtrip.build(inputs=False)重算验收并独立解码四张PNG，核对标题及场景图均非黑、非单色；inputs=True额外只读重解原cipher并核对seed、原源码和实际exe。两种结果完全相同，结果保存在acceptance.json。四张图证明画面已渲染，不证明与原版像素一致。每进程仍有1228条缺失脚本警告、11个玩家材质采用Standard替代、5个内建mesh未解析，原始player.log各有6条不支持Shader的ERROR行；degradedAssetCompatibility明确为true。回调Error为0不能表述为资源完全兼容或原玩法完整运行。首轮batchmode虽通过逻辑但截图全黑，被保留为诊断，不参与本次正式验收。

离线复查：python reverse-engineering/reconstruction/save-bridge/verify_roundtrip.py --check；加--inputs核对本机原输入。测试：python -m unittest discover -s reverse-engineering/reconstruction/save-bridge -p "test_*.py"。本目录只实现并验证版本1单一Apartment保存；涂料时间在独立最小循环中仅保留，未声称复现原倒计时、资源加载、动画或完整场景玩法。
