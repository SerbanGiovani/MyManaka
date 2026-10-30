# 独立运行工程

最新阶段已接回原Player控制器、ManustiaAvatar和原Locomotion层，真实键盘移动／跑步、F5保存、F6退出和新进程读回通过。F5误退出问题已修复，符号零规范化及362组实际写读回归独立保留。当前程序为`.cache/locomotion-20261031-3-build/ManakaLocomotion.exe`，源码在`locomotion-project/Assets`；见[本轮运行报告](locomotion-runtime.md)和[清单](locomotion-runtime.json)。其他11个原动画层、原转向／重力积分及完整玩法仍有边界。下方旧minimum结果保持历史范围，不将其模拟输入升级为真实键盘证明。

2026-10-31已完成“标题→原档选定字段读入→原自宅→移动→独立保存→关闭→新进程继续”，正式构建0错误、0警告，两个可见进程正常退出，位置和Quaternion逐位读回，标题与场景图像有效。见[最小闭环报告](minimal-runtime.md)及[运行清单](minimal-runtime.json)。

本机程序为`.cache/minimal-20261031-3-build/ReconstructedManaka.exe`，完整编辑工程为`.cache/minimal-20261031-1`。原模型、269个自宅绘制、33个碰撞及90张纹理已接入；玩家材质采用Standard替代，原脚本、完整动画和玩法尚未实现。原资源仅部分兼容，不能把最小闭环称为完整替代游戏。

源码与重建入口位于`minimal-project/Assets`、`asset-bridge`、`save-bridge`、`build-minimal.ps1`和`run-minimal.ps1`。大型资源和生成程序在忽略目录，仓库保留源代码、回执、指纹及截图。复现和手动操作方法见上述报告。

## 先前工具链检查

用户提供`H:\Unity Editor`后，已确认实际编辑器为`2022.3.62t7\Editor\Tuanjie.exe`，产品版本`2022.3.62t7_139712ad4655`。原游戏引擎标记为`2022.3.62f2`。下方旧冒烟未验证二者兼容性，本轮实际资源测试见[兼容报告](asset-compat/README.md)。

2026-10-30首轮隐藏批处理新建工程返回：

```text
No valid Unity Editor license found. Please activate your license.
```

用户完成授权后，在新的`.cache/authorized-20261030-1`重新验证成功：新建工程、编译两份脚本并构建Windows64 Mono程序，随后生成程序运行5帧、写出通过回执并正常退出。三个进程退出码均为0；构建0错误、1条构建警告。实际产物使用`TuanjiePlayer.dll`，不把它当成原游戏的UnityPlayer二进制。版本文件另标记TuanjieEditorVersion=1.8.5。

原始日志、缓存工程和105366967字节构建内容保留在忽略目录；仓库仅提交源脚本、结果和指纹。原授权失败日志哈希保留，未改登录或授权设置。

旧ToolchainSmoke只验证编译、构建和启动，没有导入原资源、场景或GameAssembly；历史回执保持原样。最新进展以上方最小闭环报告为准，后续见[工作队列](../work-queue.json)。

复现时用新的RunName保留旧回执：

```powershell
./check-editor.ps1 -RunName authorized-new
./build-smoke.ps1 -RunName authorized-new
./run-smoke.ps1 -RunName authorized-new
python inspect-editor-result.py --run-name authorized-new
```
