# 存档反射、泛型读取与构造默认值

2026-10-27；继续六组关键方法中的最高优先级存档缺口。输入仍为固定原始目录的 GameAssembly.dll / metadata v31。本轮仅离线 REA/Ghidra 与原始注册表解析，没有启动游戏或改写存档。

## 本轮补齐

新增四批共71次非空原生查询：`save-schema-core` 41、`tail` 22、`defaults` 2、`nested` 6，另复用7份 SaveManager/SaveRapper 观察。包括反射成员选择、成员读写、类型工厂、流包装、13个此前没有普通方法地址的共享泛型读取方法体、根对象与选定嵌套对象构造函数，以及外观预设双向复制。

机器可核验绑定为 [save-schema-chain.json](salt/evidence/save-schema-chain.json)，原始 REA 响应均原样保留；`.pseudocode.c` 是便于阅读的派生文本，不是原始 C# 或可编译实现。

## 1. 从原始字段恢复结构

[save-declarations.json](salt/symbols/save-declarations.json) 保存每个字段的名字、类型、token、元数据字节、原生偏移、访问标志和自定义特性坐标。

| 本轮根对象 | 字段数 | 属性数 | 显式 ES3Serializable |
| --- | ---: | ---: | ---: |
| GameStateData | 107 | 0 | 107 |
| PlayerCustomData | 66 | 0 | 66 |
| OptionData | 68 | 0 | 68 |
| TutorialData | 15 | 0 | 15 |

四根对象共256个字段。继续跟随数组、泛型参数和游戏程序集内的声明，得到27个类型、100个运行时类型记录，选定图中没有未解类型枚举。游戏程序集归属用于筛选，避免漏掉没有命名空间的 `HairCustomizeData`、`DropData`、`ClothesState` 等类型；系统 List/Dictionary/HashSet 的内部实现字段没有当作业务存档字段展开。

`LoadoutCustomizeData` 的65个字段均为非 public，并全部带有 `ES3Serializable`。只复制 public 字段会丢失这个对象的外观数据。

特性解析使用原始 metadata 的 image 范围、token→attribute range、选定单字节计数及32位构造函数索引。原始 blob 全部保留，特性参数负载没有泛化解码。构造函数索引校验为 `.ctor`，不是从字符串包含关系推测标记。

## 2. 字段如何进入 ES3

`ES3Reflection.GetSerializableFields`（12960）先检查可选成员名过滤，再检查显式标记。`ES3Serializable` 命中后立即加入列表；它在非 public、安全反射、readonly/literal、NonSerialized/Obsolete 等后续守卫之前。没有显式标记时，安全反射的非 public 字段需要 `SerializeField`，后续仍经过类型可序列化判断。

选定函数的反射 flags 为 `0x3e`，本身包含 static；该函数体没有独立的 IsStatic 排除。不能给重建实现凭空加一条“总是排除 static”的规则。本轮根对象字段是否进入实际写入，还受类型工厂、成员缓存及实际设置约束。

`GetSerializableMembers`（12968）先收集字段，再收集属性。`ES3ReflectedObjectType::.ctor`（12534）以 `safe=true` 提前建立成员缓存；`WriteProperties`（12429）只在缓存为空时按 writer 设置补建。重建时不能假定每次保存都重新按当前 safeReflection 设置筛选。

`WriteProperties` 逐成员取值、解析成员的 ES3Type，再调用 writer 写属性；`ReadProperties`（12430）按读到的名称查找成员、选择字典/集合/普通类型读取分支，最终经 `ES3ReflectedMember.SetValue`（13007）赋值。完整分支见对应原始响应，不能把它简化成固定偏移的二进制结构复制。

类型工厂 `CreateES3Type`（13110）的普通对象回退分支使用的 TypeInfo usage `0x182d6a268`，已由原始 metadata 绑定为 `ES3Types.ES3ReflectedObjectType`；不是靠反编译标签认类。工厂还包含枚举、数组、Unity对象、值类型及泛型集合分支。这里只确认选定静态路径，未观察实际运行中的类型缓存或外部 Mod 注册。

## 3. 补上 IL2CPP 泛型读取地址

普通方法表中为空的泛型声明，不能据此判断为不可逆。通过原始 CodeRegistration、genericMethodTable、methodSpecs 与 genericMethodPointers，解析出14个选定声明的220条具体注册记录，对应57个非空原生地址。

CodeRegistration 候选地址 `0x18246e080` 与全部76个模块名唯一完整匹配；同时保留原始注册字节。这里确认的是静态结构匹配，没有声称观察到注册调用。布局由随原始副本附带的 LibCpp2IL 声明/Read IL 只读核对，见 [save-parser-layouts.json](salt/symbols/save-parser-layouts.json)；该辅助读取不执行游戏或解析器方法。

本轮选择13个 `System.Object` 实例化代表地址进行 REA 查询，所有别名与指针来源保存在 [save-generic-methods.json](salt/symbols/save-generic-methods.json)。部分关键连接：

| 方法声明 | 代表共享方法体 VA | 已确认连接 |
| --- | --- | --- |
| ES3ObjectType.Read | `0x1807525e0` | 类型头 `__type` 与下层类型读取分派 |
| ES3Reader.Read | `0x1807537f0` | 类型工厂与泛型虚方法读取 |
| ES3Reader.Read(key) | `0x180755940` | 键不存在时抛出异常 |
| ES3Reader.Read(key, defaultValue) | `0x180757180` | 键不存在时返回传入默认值 |
| ES3ReflectedObjectType.ReadObject | `0x1807598d0` | CreateInstance → ReadProperties |
| ES3ReflectedType.Read | `0x1807599d0` | 类型/引用头分支及对象成员恢复 |

`__type` 字符串来自原始 usage `0x182d55f40`。上述地址是注册表里的共享代码代表，不等于实际运行时 GameStateData 等根类型的 MethodInfo 已被观察；13个查询也不代表57个共享地址全部逐一查询。

## 4. 默认值与外观预设的副作用

`ReadObject<System.Object>`（`ev_cb4e90943aca3ba316df51d1cd7df1e0e05f369c6648fb46c7b45b5554ff05e8`）明确先调用 `ES3Reflection.CreateInstance`，再调用 `ReadProperties`。普通类有无参构造函数时走默认构造路径，然后才覆盖存档内出现的成员。因此：

- 整个键缺失：必须区分抛异常的重载与传入 defaultValue 的重载。
- 对象存在、成员缺失：本次追踪的逐成员恢复路径不赋该成员，保留创建后的状态；执行无参构造函数时可能含有上下文副作用。

嵌套类型不能照搬这一条默认构造规则。原始声明中 `HairCustomizeData`、`CosplayPartsOptionData`、`DropData` 只有带参构造函数；`CreateInstance`（12963）在 `HasParameterlessConstructor`（12986）返回 false 后，走类型解析/初始化及对象分配分支，没有调用这些业务构造函数。已补查的带参构造函数和复制构造函数提供新建/复制行为，但其中显式默认值不能直接当作反射读档默认值。绑定文件保留每个构造函数的参数个数，以区分这两条路径。

根构造函数与选定嵌套构造函数已经查询。例如 `PlayerCustomData` 明确写 `CustomizeHeight=-999`，创建 BodyPaint 字典，并经 `GetDefaultHairCustomDataDict`（16781）创建头发定制字典；不能用“全部清零”等价替代。`GameStateData` 还有快捷项/任务索引的负值哨兵、生命、精神值等显式默认值。

`OptionData` 构造函数含合并写入，例如 `undefined4 @+0x10 = 0x10000` 覆盖多个相邻 bool 字段。按小端字节投影，FutanariDisable=false、PeeDisable=false、SexDisable=true；不能把整条32位常量当作一个 bool。绑定文件同时保留写入宽度、原始字节和字段投影。投影仅提取直接整数常量写入，不是完整符号执行，也不把未提取部分默认成零。

`LoadoutCustomizeData::.ctor`（18687）直接调用 `SaveCurrentCustomize`（18689）：从静态 `GameState.PlayerCustomData`（偏移`+0x60`）读取当前外观。`ApplyToGameState`（18688）反向写回该对象；字典有独立处理，完整代码已保留。因此加载外观预设对象时，即使随后覆盖多数存储字段，构造函数仍依赖当前 PlayerCustomData 已初始化。该实例创建顺序与缺失字段的兼容性，应在独立读写实现及实际往返中单独验证。

## 5. 尚未完成的边界

`ES3Stream.CreateStream` 的两个选定重载（13102/13103）已接到按 ES3Settings 条件创建加密流、再处理压缩包装的路径。它证明存在配置分支，没有恢复游戏实际默认设置资源、存档密码或完整 `.sd` 编码；资源包的 salt/密码不能直接认作存档密码。

本轮也没有完成 RankData、TotalPlayTimeData 等所有系统键的对象图、历史迁移、所有 Unity 自定义序列化器或真实存档读写往返，没有生成独立游戏或完整 ES3 替代品。后续仍按优先级补实际设置与独立读取验证，再推进任务配置/运行条件和相机、导航、具体交互的等价验证。

## 复核

```powershell
python reverse-engineering/salt/save_declarations.py --check
python reverse-engineering/salt/resolve_save_generics.py --check
python reverse-engineering/salt/save_evidence.py --check
python reverse-engineering/audit.py --inputs
```

查询、原始注册与字段坐标分别验证；完整审计同时检查旧运行记录、原始输入指纹及新依赖。静态查询不计作自然玩法或存档往返测试。
