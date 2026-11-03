# H盘Unity正式构建与自宅闭环

2026-11-03，用户恢复并指定`H:\Unity Editor\6000.6.7f1\Editor\Unity.exe`后，已补齐前轮待完成的正式Unity构建及运行验证。后续使用[unity-active.ps1](unity-active.ps1)和[unity-active-settings.json](unity-active-settings.json)。它们将参数转给原非覆盖构建入口，不修改旧设置、历史构建或宿主档案。

## 正式构建

- 编辑器实际版本`6000.6.7f1_b22767f04f04`，程序279976字节，SHA256为`13c0162a848689b760be7cb4aaa9391d085d56e3f6e20a12f8736f63b3bd0540`。
- Build `formal-home-20261103-2`，进程42172退出0，BuildReport为Succeeded，**0错误、0警告**，256个文件，454124787字节。
- Title与Apartment均入包，Windows64 Mono、Built-in、Legacy Input0。1469个源码／资产／配置文件构建前后逐字节一致，没有模板同步、场景清空或设置重写。
- 完整输出复制到`E:\ManakaREA-HomeEditor-20261103-2`，256个文件与本次新构建逐项SHA相同；运行没有替换DLL或其他包内文件。包中不含原GameAssembly或BepInEx。

## 实际运行

受控进程22036与冷进程46020均正常退出0，独立GUID，两次意外引擎错误均为0。

| 检查 | 新构建实际结果 |
| --- | --- |
| 菜单与移动 | 5个周期经原PC／衣柜触发器、真实CC回调及共享模拟F分派；锁内有非零方向输入而不调用Move；关闭／取消后实际移动恢复 |
| 取消保存队列 | 203帧禁用菜单组件取消关闭，210帧复核，实测7帧无额外操作或写档，revision维持1；之后成功重开 |
| 衣柜自动保存 | 219→224、234→239，各精确5帧，revision2／3 |
| 最终电脑保存 | revision4，预设1，随后保持保存姿态，不将最后一次关闭写成额外移动证明 |
| 冷启动 | 位置／Quaternion在物理更新前按float32精确恢复；运行内存预设1和实际body1／face2主色与独立原主表一致 |

存档SHA256为`5a0b9493ac2879c7d49c1347023691abbdd2284d0481cdf9ce6ffe435f70819a`。[新正式清单](home-editor-runtime.json)及71份公开档案包括源码、场景、设置、前后快照、退出回执、日志和截图；授权／编辑器原日志留在私有目录，只发布指纹。

这次明确是**新Unity编辑器构建的完整输出**。[前轮宿主测试](home-runtime.md)中缺少授权、仅替换自有托管模块的事实和pending字段保持历史原样；新记录独立关闭当前构建待办。

## 路径与历史输入

H盘编辑器与两份历史记录中的C盘Unity.exe完全同SHA及长度。[显式迁移记录](editor-relocation.json)仅允许这一条原路径到实际路径的替代，外层审计会真实读取H盘字节，并在索引中同时记录actual path与original path。不做目录通配重写、不跳过未知缺失输入，也不把旧C路径伪造为仍存在。

正常使用：

```powershell
pwsh -NoProfile -File reverse-engineering/reconstruction/unity-active.ps1 -Action Validate
pwsh -NoProfile -File reverse-engineering/reconstruction/unity-active.ps1 -Action Open
# 关闭本工程编辑器后，以新名称构建：
pwsh -NoProfile -File reverse-engineering/reconstruction/unity-active.ps1 -Action Build -RunName formal-home-new
python -B -X utf8 reverse-engineering/reconstruction/verify-home-editor.py --inputs
python -B -X utf8 reverse-engineering/audit.py --inputs
```

仍为受控模拟输入，不声明实体键盘验收；床保持原inactive，完整睡眠副作用、原UI动画／相机、其余衣装及原shader继续按前轮边界待补。构建0警告不代表原资源完整兼容；模型加载仍有已知缺失脚本及Standard材质替代。
