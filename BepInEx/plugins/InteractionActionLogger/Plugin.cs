using System;
using System.Collections.Generic;
using System.Globalization;
using System.IO;
using System.Linq;
using System.Reflection;
using System.Text;
using BepInEx;
using BepInEx.Configuration;
using BepInEx.Logging;
using BepInEx.Unity.IL2CPP;
using ExposureUnnoticed2.Scripts.InGame;
using HarmonyLib;
using UnityEngine;

namespace InteractionActionLogger
{
    [BepInPlugin(PluginGuid, PluginName, PluginVersion)]
    public sealed class Plugin : BasePlugin
    {
        public const string PluginGuid = "local.interaction_action_logger";
        public const string PluginName = "Interaction Action Logger";
        public const string PluginVersion = "1.1.1";

        internal static ManualLogSource Logger;
        internal static ConfigEntry<bool> LogToBepInEx;
        internal static ConfigEntry<bool> LogPlayerPosition;
        internal static ConfigEntry<bool> LogAreaEnterExit;
        internal static ConfigEntry<bool> LogMenuOpenClose;
        internal static ConfigEntry<bool> LogMethodResults;
        internal static ConfigEntry<int> MaxArgumentLength;

        private Harmony harmony;

        public override void Load()
        {
            Logger = Log;
            BindConfig();
            InteractionLog.Initialize();

            harmony = new Harmony(PluginGuid);
            PatchTargets.Register(harmony);

            Log.LogInfo("Interaction Action Logger loaded. File: " + InteractionLog.LogPath);
            InteractionLog.Write("Plugin", "Loaded", "targets=" + PatchTargets.PatchedCount);
        }

        public override bool Unload()
        {
            harmony?.UnpatchSelf();
            InteractionLog.Write("Plugin", "Unloaded", "");
            return true;
        }

        private void BindConfig()
        {
            LogToBepInEx = Config.Bind("Logging", "LogToBepInEx", false, "Also mirror interaction log lines to BepInEx LogOutput.log.");
            LogPlayerPosition = Config.Bind("Logging", "LogPlayerPosition", true, "Append current stage and player position to each event when available.");
            LogAreaEnterExit = Config.Bind("Coverage", "LogAreaEnterExit", false, "Log entering/leaving interact trigger areas. This can be noisy.");
            LogMenuOpenClose = Config.Bind("Coverage", "LogMenuOpenClose", true, "Log opening/closing interaction menus and ring menu state changes.");
            LogMethodResults = Config.Bind("Logging", "LogMethodResults", true, "Include method return values for hooked methods.");
            MaxArgumentLength = Config.Bind("Logging", "MaxArgumentLength", 220, "Maximum text length for one argument/result value.");
        }
    }

    internal static class PatchTargets
    {
        private static readonly Dictionary<MethodBase, TargetInfo> targets = new Dictionary<MethodBase, TargetInfo>();

        public static int PatchedCount { get; private set; }

        public static TargetInfo Get(MethodBase method)
        {
            if (method != null && targets.TryGetValue(method, out var info))
            {
                return info;
            }

            return new TargetInfo("Unknown", method?.DeclaringType?.FullName ?? "Unknown", method?.Name ?? "Unknown", false);
        }

        public static void Register(Harmony harmony)
        {
            var prefix = new HarmonyMethod(typeof(GenericActionPatch), nameof(GenericActionPatch.Prefix));
            var postfix = new HarmonyMethod(typeof(GenericActionPatch), nameof(GenericActionPatch.Postfix));

            Add(harmony, prefix, postfix, "Interact", "ExposureUnnoticed2.Scripts.Base.InteractManager", "OnInteract");
            Add(harmony, prefix, postfix, "Interact", "ExposureUnnoticed2.Object3D.InteractArea.InteractAreaController", "OnInteract");
            Add(harmony, prefix, postfix, "Interact", "ExposureUnnoticed2.Object3D.InteractArea.InteractAreaController", "OnChangeOption");

            Add(harmony, prefix, postfix, "Area", "ExposureUnnoticed2.Scripts.Base.InteractManager", "Register", configGate: () => Plugin.LogAreaEnterExit.Value);
            Add(harmony, prefix, postfix, "Area", "ExposureUnnoticed2.Scripts.Base.InteractManager", "Unregister", configGate: () => Plugin.LogAreaEnterExit.Value);
            Add(harmony, prefix, postfix, "Area", "ExposureUnnoticed2.Object3D.InteractArea.InteractAreaController", "OnTriggerEnter", configGate: () => Plugin.LogAreaEnterExit.Value);
            Add(harmony, prefix, postfix, "Area", "ExposureUnnoticed2.Object3D.InteractArea.InteractAreaController", "OnTriggerExit", configGate: () => Plugin.LogAreaEnterExit.Value);

            Add(harmony, prefix, postfix, "Menu", "ExposureUnnoticed2.ObjectUI.InteractMenuPanel.InteractMenuPanelView", "Open", configGate: () => Plugin.LogMenuOpenClose.Value);
            Add(harmony, prefix, postfix, "Menu", "ExposureUnnoticed2.ObjectUI.InteractMenuPanel.InteractMenuPanelView", "OnClick");
            Add(harmony, prefix, postfix, "Menu", "ExposureUnnoticed2.ObjectUI.InteractMenuPanel.InteractMenuPanelView", "OnClickEmpty");
            Add(harmony, prefix, postfix, "RingMenu", "ExposureUnnoticed2.ObjectUI.InGame.RingMenu.RingMenuView", "OnLongPressActionSlot");
            Add(harmony, prefix, postfix, "RingMenu", "ExposureUnnoticed2.ObjectUI.InGame.RingMenu.RingMenuView", "ChangeState", configGate: () => Plugin.LogMenuOpenClose.Value);
            Add(harmony, prefix, postfix, "RingMenu", "ExposureUnnoticed2.ObjectUI.InGame.RingMenu.RingMenuView", "SetShow", configGate: () => Plugin.LogMenuOpenClose.Value);

            Add(harmony, prefix, postfix, "PlayerAction", "ExposureUnnoticed2.Object3D.Player.Scripts.PlayerAction", "ChangeAction");

            Add(harmony, prefix, postfix, "DroppedItem", "ExposureUnnoticed2.Scripts.InGame.DroppedItemManager", "Drop");
            Add(harmony, prefix, postfix, "DroppedItem", "ExposureUnnoticed2.Scripts.InGame.DroppedItemManager", "ReserveDrop");
            Add(harmony, prefix, postfix, "DroppedItem", "ExposureUnnoticed2.Scripts.InGame.DroppedItemManager", "Collect");
            Add(harmony, prefix, postfix, "DroppedItem", "ExposureUnnoticed2.Scripts.InGame.DroppedItemManager", "CollectAll");
            Add(harmony, prefix, postfix, "DroppedItem", "ExposureUnnoticed2.Scripts.InGame.DroppedItemManager", "CollectAllClothes");
            Add(harmony, prefix, postfix, "DroppedItem", "ExposureUnnoticed2.Scripts.InGame.DroppedItemManager", "SendToHome");
            Add(harmony, prefix, postfix, "DroppedItem", "ExposureUnnoticed2.Scripts.InGame.DroppedItemManager", "HideAllUnderwear");
            Add(harmony, prefix, postfix, "DroppedItem", "ExposureUnnoticed2.Scripts.InGame.DroppedItemManager", "DisposeAllPutDildo");

            Add(harmony, prefix, postfix, "Inventory", "ExposureUnnoticed2.ObjectUI.InventoryPanel.InventoryItemView", "OnClickUse");
            Add(harmony, prefix, postfix, "Inventory", "ExposureUnnoticed2.ObjectUI.InventoryPanel.InventoryItemView", "OnClickDrop");
            Add(harmony, prefix, postfix, "Inventory", "ExposureUnnoticed2.ObjectUI.InventoryPanel.InventoryItemView", "CommonOnClickByPad");

            Add(harmony, prefix, postfix, "Buy", "ExposureUnnoticed2.ObjectUI.BuyPanel.BuyPanelView", "Open", configGate: () => Plugin.LogMenuOpenClose.Value);
            Add(harmony, prefix, postfix, "Buy", "ExposureUnnoticed2.ObjectUI.BuyPanel.BuyPanelItemView", "OnClickButton");
            Add(harmony, prefix, postfix, "Buy", "ExposureUnnoticed2.ObjectUI.BuyPanel.BuyPanelItemView", "AddBasket");
            Add(harmony, prefix, postfix, "Buy", "ExposureUnnoticed2.ObjectUI.BuyPanel.BuyPanelItemView", "RemoveBasket");

            Add(harmony, prefix, postfix, "Reinforce", "ExposureUnnoticed2.ObjectUI.PcMenuPanel.ReinforcePanel.ReinforcePanelView", "OnClickTab");
            Add(harmony, prefix, postfix, "Reinforce", "ExposureUnnoticed2.ObjectUI.PcMenuPanel.ReinforcePanel.ReinforcePanelView", "OnClickItem");
            Add(harmony, prefix, postfix, "Reinforce", "ExposureUnnoticed2.ObjectUI.PcMenuPanel.ReinforcePanel.ReinforcePanelView", "OnClickSelectRank");
            Add(harmony, prefix, postfix, "Reinforce", "ExposureUnnoticed2.ObjectUI.PcMenuPanel.ReinforcePanel.ReinforcePanelView", "OnClickReinforce");
            Add(harmony, prefix, postfix, "Reinforce", "ExposureUnnoticed2.ObjectUI.PcMenuPanel.ReinforcePanel.ReinforcePanelView", "OnClickSetting");

            Add(harmony, prefix, postfix, "World", "ExposureUnnoticed2.Object3D.ScenePlops.CommonDoor.CommonDoorController", "OnInteract");
            Add(harmony, prefix, postfix, "World", "ExposureUnnoticed2.Object3D.ScenePlops.CommonDoor.CommonDoorController", "OpenClose");
            Add(harmony, prefix, postfix, "World", "ExposureUnnoticed2.Object3D.ScenePlops.BuyMachine.BuyMachineController", "OnInteract");
        }

        private static void Add(
            Harmony harmony,
            HarmonyMethod prefix,
            HarmonyMethod postfix,
            string category,
            string typeName,
            string methodName,
            Func<bool> configGate = null)
        {
            try
            {
                var type = AccessTools.TypeByName(typeName);
                if (type == null)
                {
                    Plugin.Logger?.LogWarning("[InteractionLogger] Type not found: " + typeName);
                    return;
                }

                var methods = type.GetMethods(BindingFlags.Instance | BindingFlags.Static | BindingFlags.Public | BindingFlags.NonPublic)
                    .Where(method => method.Name == methodName && !method.IsAbstract && !method.ContainsGenericParameters)
                    .ToArray();

                if (methods.Length == 0)
                {
                    Plugin.Logger?.LogWarning("[InteractionLogger] Method not found: " + typeName + "." + methodName);
                    return;
                }

                foreach (var method in methods)
                {
                    var hasResult = method.ReturnType != typeof(void);
                    targets[method] = new TargetInfo(category, typeName, methodName, hasResult, configGate);
                    harmony.Patch(method, prefix, hasResult ? postfix : null);
                    PatchedCount++;
                }
            }
            catch (Exception ex)
            {
                Plugin.Logger?.LogWarning("[InteractionLogger] Failed to patch " + typeName + "." + methodName + ": " + ex.Message);
            }
        }
    }

    internal sealed class TargetInfo
    {
        public readonly string Category;
        public readonly string TypeName;
        public readonly string MethodName;
        public readonly bool HasResult;
        private readonly Func<bool> configGate;

        public TargetInfo(string category, string typeName, string methodName, bool hasResult, Func<bool> configGate = null)
        {
            Category = category;
            TypeName = typeName;
            MethodName = methodName;
            HasResult = hasResult;
            this.configGate = configGate;
        }

        public bool Enabled => configGate == null || configGate();
    }

    internal static class GenericActionPatch
    {
        public static void Prefix(MethodBase __originalMethod, object __instance, object[] __args)
        {
            var info = PatchTargets.Get(__originalMethod);
            if (!info.Enabled)
            {
                return;
            }

            InteractionLog.Write(info.Category, info.MethodName, InteractionLog.DescribeCall(__originalMethod, __instance, __args, null, false));
        }

        public static void Postfix(MethodBase __originalMethod, object __result)
        {
            var info = PatchTargets.Get(__originalMethod);
            if (!info.Enabled || !info.HasResult || !Plugin.LogMethodResults.Value)
            {
                return;
            }

            InteractionLog.Write(info.Category, info.MethodName + ".Result", InteractionLog.DescribeValue(__result));
        }
    }

    internal static class InteractionLog
    {
        private static readonly object Sync = new object();

        public static string LogPath { get; private set; }

        public static void Initialize()
        {
            LogPath = Path.Combine(Paths.BepInExRootPath, "InteractionActionLog.log");
            var directory = Path.GetDirectoryName(LogPath);
            if (!string.IsNullOrEmpty(directory))
            {
                Directory.CreateDirectory(directory);
            }

            WriteRaw("");
            WriteRaw("==== Interaction Action Logger session " + DateTime.Now.ToString("yyyy-MM-dd HH:mm:ss.fff", CultureInfo.InvariantCulture) + " ====");
        }

        public static void Write(string category, string action, string detail, bool appendPlayer = true)
        {
            var line = BuildLine(category, action, detail, appendPlayer);
            WriteRaw(line);
            if (Plugin.LogToBepInEx.Value)
            {
                Plugin.Logger?.LogInfo(line);
            }
        }

        private static string BuildLine(string category, string action, string detail, bool appendPlayer)
        {
            var builder = new StringBuilder();
            builder.Append('[')
                .Append(DateTime.Now.ToString("yyyy-MM-dd HH:mm:ss.fff", CultureInfo.InvariantCulture))
                .Append("] [")
                .Append(category)
                .Append("] ")
                .Append(action);

            if (!string.IsNullOrEmpty(detail))
            {
                builder.Append(" | ").Append(detail);
            }

            if (appendPlayer && Plugin.LogPlayerPosition.Value)
            {
                var position = CurrentPlayerPosition();
                if (!string.IsNullOrEmpty(position))
                {
                    builder.Append(" | player=").Append(position);
                }
            }

            return builder.ToString();
        }

        private static void WriteRaw(string line)
        {
            lock (Sync)
            {
                File.AppendAllText(LogPath, line + Environment.NewLine, Encoding.UTF8);
            }
        }

        public static string DescribeCall(MethodBase method, object instance, object[] args, object result, bool includeResult)
        {
            var builder = new StringBuilder();
            builder.Append("method=").Append(method?.DeclaringType?.Name).Append('.').Append(method?.Name);

            if (instance != null)
            {
                builder.Append(" instance=").Append(DescribeValue(instance));
            }

            if (args != null && args.Length > 0)
            {
                builder.Append(" args=[");
                for (var i = 0; i < args.Length; i++)
                {
                    if (i > 0)
                    {
                        builder.Append(", ");
                    }

                    builder.Append(i).Append(':').Append(DescribeValue(args[i]));
                }

                builder.Append(']');
            }

            if (includeResult)
            {
                builder.Append(" result=").Append(DescribeValue(result));
            }

            return builder.ToString();
        }

        public static string DescribeValue(object value)
        {
            try
            {
                if (value == null)
                {
                    return "null";
                }

                if (value is string text)
                {
                    return Quote(Trim(text));
                }

                if (value is bool || value is byte || value is sbyte || value is short || value is ushort ||
                    value is int || value is uint || value is long || value is ulong ||
                    value is float || value is double || value is decimal || value.GetType().IsEnum)
                {
                    return Convert.ToString(value, CultureInfo.InvariantCulture);
                }

                if (value is Vector2 vector2)
                {
                    return FormatVector(vector2.x, vector2.y);
                }

                if (value is Vector3 vector3)
                {
                    return FormatVector(vector3.x, vector3.y, vector3.z);
                }

                if (value is Quaternion quaternion)
                {
                    return FormatVector(quaternion.x, quaternion.y, quaternion.z, quaternion.w);
                }

                if (value is GameObject gameObject)
                {
                    return "GameObject(" + SafeName(gameObject) + " " + FormatTransform(gameObject.transform) + ")";
                }

                if (value is Component component)
                {
                    return value.GetType().Name + "(" + SafeName(component.gameObject) + " " + FormatTransform(component.transform) + ")";
                }

                var reflected = DescribeKnownProperties(value);
                if (!string.IsNullOrEmpty(reflected))
                {
                    return reflected;
                }

                return Trim(value.GetType().Name + "(" + value + ")");
            }
            catch (Exception ex)
            {
                return "<describe failed: " + ex.GetType().Name + ">";
            }
        }

        private static string DescribeKnownProperties(object value)
        {
            var type = value.GetType();
            var pieces = new List<string>();
            var interesting = new[] { "Type", "Model", "Controller", "DropItemType", "VectorParam", "IntParam", "BoolParam", "ItemType", "StageType", "Position", "Rotation", "CurrentAction" };

            foreach (var name in interesting)
            {
                try
                {
                    var property = AccessTools.Property(type, name);
                    if (property == null || property.GetIndexParameters().Length != 0)
                    {
                        continue;
                    }

                    var propertyValue = property.GetValue(value, null);
                    pieces.Add(name + "=" + DescribeValue(propertyValue));
                }
                catch
                {
                    // Some IL2CPP properties throw while an object is being destroyed; skip them.
                }
            }

            if (pieces.Count == 0)
            {
                return null;
            }

            return Trim(type.Name + "{" + string.Join(", ", pieces) + "}");
        }

        public static bool TryCurrentPlayerPosition(out string stage, out Vector3 position)
        {
            stage = null;
            position = default;

            try
            {
                var state = GameState.GameStateData;
                if (state != null)
                {
                    position = state.PlayerPosition;
                    stage = state.CurrentStageType.ToString();
                    return true;
                }
            }
            catch
            {
                // Fall back to the live player transform below.
            }

            try
            {
                var playerType = AccessTools.TypeByName("ExposureUnnoticed2.Object3D.Player.Scripts.PlayerController");
                var instanceProperty = AccessTools.Property(playerType, "Instance");
                var player = instanceProperty?.GetValue(null, null) as Component;
                if (player != null)
                {
                    position = player.transform.position;
                    stage = "Transform";
                    return true;
                }
            }
            catch
            {
                // The player may not exist yet.
            }

            return false;
        }

        private static string CurrentPlayerPosition()
        {
            if (TryCurrentPlayerPosition(out var stage, out var position))
            {
                return stage + " " + FormatVector(position.x, position.y, position.z);
            }

            return null;
        }

        private static string FormatTransform(Transform transform)
        {
            if (transform == null)
            {
                return "pos=<none>";
            }

            var p = transform.position;
            return "pos=" + FormatVector(p.x, p.y, p.z);
        }

        public static string FormatVector(params float[] values)
        {
            return "(" + string.Join(",", values.Select(v => v.ToString("0.###", CultureInfo.InvariantCulture))) + ")";
        }

        private static string Quote(string text)
        {
            return "\"" + text.Replace("\"", "\\\"") + "\"";
        }

        private static string SafeName(GameObject gameObject)
        {
            try
            {
                return gameObject != null ? Quote(gameObject.name) : "null";
            }
            catch
            {
                return "<name unavailable>";
            }
        }

        private static string Trim(string text)
        {
            if (string.IsNullOrEmpty(text))
            {
                return text;
            }

            text = text.Replace("\r", "\\r").Replace("\n", "\\n");
            var max = Math.Max(40, Plugin.MaxArgumentLength.Value);
            return text.Length <= max ? text : text.Substring(0, max) + "...";
        }
    }
}
