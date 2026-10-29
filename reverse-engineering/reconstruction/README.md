# 独立运行工程工具链检查

用户提供`H:\Unity Editor`后，已确认实际编辑器为`2022.3.62t7\Editor\Tuanjie.exe`，产品版本`2022.3.62t7_139712ad4655`。原游戏引擎标记为`2022.3.62f2`，二者兼容性尚未验证。

2026-10-30首轮隐藏批处理新建工程返回：

```text
No valid Unity Editor license found. Please activate your license.
```

用户完成授权后，在新的`.cache/authorized-20261030-1`重新验证成功：新建工程、编译两份脚本并构建Windows64 Mono程序，随后生成程序运行5帧、写出通过回执并正常退出。三个进程退出码均为0；构建0错误、1条构建警告。实际产物使用`TuanjiePlayer.dll`，不把它当成原游戏的UnityPlayer二进制。版本文件另标记TuanjieEditorVersion=1.8.5。

原始日志、缓存工程和105366967字节构建内容保留在忽略目录；仓库仅提交源脚本、结果和指纹。原授权失败日志哈希保留，未改登录或授权设置。

本目录的可运行程序只验证编译、构建和启动，尚无可运行替代游戏。没有导入原资源、场景或GameAssembly，原2022.3.62f2资源/IL2CPP兼容性仍未验证。继续入口为[工作队列](../work-queue.json)的第3项剩余运行消费者和第4项独立工程。

复现时用新的RunName保留旧回执：

```powershell
./check-editor.ps1 -RunName authorized-new
./build-smoke.ps1 -RunName authorized-new
./run-smoke.ps1 -RunName authorized-new
python inspect-editor-result.py --run-name authorized-new
```
