# 原始资源与最小运行工程之间的桥接

本目录只读取冻结原件和已解密的原`models.unity3d`，不运行GameAssembly、BepInEx、游戏或编辑器，也不修改原文件。原资源的Tuanjie加载、材质替换、碰撞和画面验收由最小工程的原生测试另行记录；这里的离线导出不等同于完整游戏已经兼容。

`inventory.json`保存原models的2599项容器键、对象类型、pathID和原序列化坐标。原玩家的精确键为`assets/zzz-externalencryptasset/player.prefab`。同一FBX键可对应多个子资源，不能将容器条目数当作不同资源名数。models没有Apartment场景或房间预制体；原Apartment为构建索引1的`level1`，原路径`Assets/ZZZ-ExternalAsset/MapAsset/JP_Apartment/Scenes/Apartment.unity`。原`data.unity3d`的构建节点没有AssetBundle对象，不能凭UnityFS外壳推定可用AssetBundle.LoadFromFile加载。

复现命令从仓库根目录执行：

```powershell
python -X utf8 reverse-engineering/reconstruction/asset-bridge/bridge_assets.py
python -X utf8 reverse-engineering/reconstruction/asset-bridge/bridge_assets.py --geometry
python -X utf8 reverse-engineering/reconstruction/asset-bridge/make_manifest.py
```

生成的大资源保留在忽略目录`.cache`；跟踪的`export-manifest.json`绑定每个输出文件及原输入的SHA256。打包时复制以下内容到最小工程的`StreamingAssets/Original`，不要复制GameAssembly或原脚本：

- `.cache/roombridge.json`：相对路径运行清单。
- `.cache/Apartment.geometry.json`：原场景几何数据。
- `.cache/Textures/*.raw`：90个原首材质MainTex的完整压缩图像字节。
- `../../salt/.cache/decrypted/models.unity3d`：原玩家所在的已解密资源包。

复查不重写输出：

```powershell
python -X utf8 reverse-engineering/reconstruction/asset-bridge/bridge_assets.py --check
python -X utf8 reverse-engineering/reconstruction/asset-bridge/bridge_assets.py --geometry --check
python -X utf8 reverse-engineering/reconstruction/asset-bridge/make_manifest.py --check
```

## 几何合同

`schemaVersion=1`。`nodes`含局部`position{x,y,z}`、`rotation{x,y,z,w}`、`scale{x,y,z}`、`parent`（-1为输出根）、`mesh`（-1为没有已导出网格）、`active`、`rendererEnabled`、`collider`。先建立全部节点，再设置父级和局部变换。只在`mesh>=0`时使用对应网格；`rendererEnabled=false,collider=true`是纯碰撞节点，不能额外创建可见Renderer。

266个静态批次绘制使用原`firstSubMesh/subMeshCount`截取的三角形。原`m_StaticBatchRoot`均为null，合并顶点已经位于世界坐标；这些独立绘制节点因此直接挂输出根、局部变换为identity。不得再乘原家具GameObject的局部变换。未合批的网格仍使用原节点层级。

`meshes`保存去重子集的`vertices`、`triangles`、可选`normals/uv`，以及原首材质`materialName/materialNames/color`。可选`texture`为`textures`索引，缺省必须为-1；`textureScale/textureOffset`为原MainTex UV变换。纯碰撞箱没有texture字段，JsonUtility的默认整数0不能被误当作纹理索引。

每个`textures`条目含`file,width,height,format,mipCount,byteLength,sha256,colorSpace,settings`。本批87项原TextureFormat10（DXT1）、3项12（DXT5），总65012952字节。最小运行时使用对应Texture2D尺寸、格式及mipmap设置，交原生LoadRawTextureData解码；失败须记录并回退基础色。保存的colorSpace是原始整数，离线导出没有证明新材质的颜色空间、原shader或最终像素等价。

## 原始数据的范围与限制

实际导出459个3D Transform、269个启用的原网格绘制、111346个三角形、97041个子网格顶点、31个原BoxCollider和2个原MeshCollider。后两者为原floor和table01网格。原材质名、主色和首材质MainTex均来自原对象；最小工程仍需新建材质，不宣称原shader、透明性、附加材质槽、光照或烘焙贴图已经复现。

除单独标记的MeshCollider后缀外，所有原生对象仅使用models中同classID且原序列化typeHash完全相同的类型树解码，每个对象消费至EOF。4个原MeshCollider恰为64字节：共用Collider前缀由原BoxCollider类型树佐证，专属后缀以convex@44、cookingOptions@48、mesh PPtr@52结构解码并验证引用和EOF；没有虚构一个原件中不存在的MeshCollider类型树。

另有3个绘制和2个MeshCollider引用`Library/unity default resources`，原包没有相应文件。JSON只保留`builtinMeshId`（10202/10209）和原引用，网格索引为-1；本批不凭ID猜测或用新平面冒充已提取原资源。唯一未导出的3D父级是无网格的EventSystem RectTransform，不属于房间几何。

原spawn取父调查提供的Apartment位置`[0.33,-0.00046,1.219]`，朝向identity为重建工程选择。离线竖直相交核对命中该位置下方的原floor顶面约y=-1e-7；实际CharacterController接地、碰撞与移动仍须由新运行时验证。触发器、球体碰撞、刚体行为、NavMesh、原动画事件、交互和玩法脚本均未从本导出中重建。
