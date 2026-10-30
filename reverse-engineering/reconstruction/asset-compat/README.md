# 原资源与Tuanjie兼容性实测

编辑器为已授权的Tuanjie `2022.3.62t7`，原资源标记 `2022.3.62f2`。两次真实隐藏批处理均使用Direct3D11，正常退出码0；原模型、材质及纹理从已校验的原解密资源包读取，没有导入原GameAssembly或BepInEx。

`AssetBundle.LoadFromFile`接受原models，返回1948个资源名；原玩家预制体可解码、实例化。包含4003个Transform、32个MeshRenderer、348个SkinnedMeshRenderer。原128×128 DXT1Crunched纹理经GPU读取成PNG；第二轮角色实际渲染有51037个非背景像素。第一轮相机受大范围特效包围盒影响，只有199个非背景像素，该诊断及原脚本单独保留，不能计作充分的角色画面验证。

这些结果只证明所测原生资源可用。596个原MonoBehaviour槽没有脚本，7个材质的shader不受支持，加载玩家时两次出现`_MainTex`常量缓冲错误，完整错误和日志均归档。不能将“预制体加载成功”称为原角色逻辑已经运行，也不能将材质主贴图可读称为原着色效果等价。

原`data.unity3d`不是独立的场景AssetBundle；直接加载失败，并报告序列化版本不匹配：预期2022.3.62t7、实际2022.3.62f2。最小工程因此采用[原几何桥接](../asset-bridge/README.md)重建Apartment。这个路径验证的是原资源可复用范围，没有修改原文件版本头。

正式结果为[第二轮回执](accepted-assets/result.json)，首次失败范围为[第一轮回执](diagnostics/first-probe/result.json)。`manifest.json`绑定源脚本、输入SHA、日志、图像和两个进程回执。

Unity API参考：[LoadFromFile](https://docs.unity.cn/2022.3/Documentation/ScriptReference/AssetBundle.LoadFromFile.html)、[官方AssetBundle格式](https://github.com/Unity-Technologies/UnityDataTools/blob/main/Documentation/assetbundle-format.md)。兼容性结论来自上述本机实测。
