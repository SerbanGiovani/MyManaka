using System;
using System.Reflection;
using BepInEx;
using BepInEx.Configuration;
using BepInEx.Logging;
using BepInEx.Unity.IL2CPP;
using ExposureUnnoticed2.Scripts.InGame;
using HarmonyLib;
using Il2CppInterop.Runtime.Injection;
using SFM_custom_mission_v2;
using SFM_custom_mission_v2.Script;
using UnityEngine;

namespace DropAndLocateRealtimeBridge
{
    [BepInPlugin(PluginGuid, PluginName, PluginVersion)]
    [BepInDependency("SFM_custom_mission_v2")]
    public sealed class Plugin : BasePlugin
    {
        public const string PluginGuid = "local.drop_and_locate_realtime_bridge";
        public const string PluginName = "Drop and Locate Realtime Bridge";
        public const string PluginVersion = "1.4.1";

        internal static ManualLogSource Logger;
        internal static ConfigEntry<bool> TrackPlayerMovementSamples;
        internal static ConfigEntry<float> PlayerMovementSampleInterval;
        internal static ConfigEntry<float> PlayerMovementMinDistance;
        internal static ConfigEntry<bool> DrawPluginHud;
        internal static ConfigEntry<float> HudX;
        internal static ConfigEntry<float> HudY;
        internal static ConfigEntry<int> HudFontSize;
        internal static ConfigEntry<float> HudPrintInterval;

        private Harmony harmony;

        public override void Load()
        {
            Logger = Log;
            BindConfig();
            ScriptExtensions.Initialize();
            try
            {
                ClassInjector.RegisterTypeInIl2Cpp<RealtimeHudBehaviour>();
            }
            catch
            {
                // The type can already be registered after a plugin reload.
            }

            harmony = new Harmony(PluginGuid);
            harmony.PatchAll(typeof(CMv2UpdatePatch));
            harmony.PatchAll(typeof(PlayerPositionSamplerPatch));
            AddComponent<RealtimeHudBehaviour>();

            Log.LogInfo("Drop and Locate Realtime Bridge loaded.");
        }

        public override bool Unload()
        {
            harmony?.UnpatchSelf();
            return true;
        }

        private void BindConfig()
        {
            TrackPlayerMovementSamples = Config.Bind("PlayerPosition", "TrackMovementSamples", true, "Track latest player position samples in memory while the player moves.");
            PlayerMovementSampleInterval = Config.Bind("PlayerPosition", "SampleIntervalSeconds", 0.25f, "Minimum seconds between player position samples.");
            PlayerMovementMinDistance = Config.Bind("PlayerPosition", "MinDistanceMeters", 0.05f, "Minimum movement distance before refreshing the in-memory player position sample.");
            DrawPluginHud = Config.Bind("HUD", "DrawPluginHud", true, "Draw Drop and Locate coordinates from the realtime bridge instead of the CMv2 state cache.");
            HudX = Config.Bind("HUD", "X", 0.185f, "Normalized horizontal HUD position.");
            HudY = Config.Bind("HUD", "Y", 0.03f, "Normalized vertical HUD position from the top of the screen.");
            HudFontSize = Config.Bind("HUD", "FontSize", 20, "Plugin HUD font size.");
            HudPrintInterval = Config.Bind("HUD", "PrintIntervalSeconds", 0.25f, "Seconds between rebuilding plugin HUD text.");
        }
    }

    [HarmonyPatch]
    internal static class CMv2UpdatePatch
    {
        private static float lastLogTime;
        private static float lastSyncLogTime;

        private static MethodBase TargetMethod()
        {
            return AccessTools.Method(typeof(SFM_custom_mission_v2.Plugin), "Update");
        }

        private static void Prefix()
        {
            try
            {
                ScriptExtensions.EnsureRegistered();
                DroppedItemPositionSync.SyncActiveDroppedItems();
                PlayerPositionStateSync.SyncFromLiveTransform();
                PlayerData.GatherData();
                PlayerPositionMemory.RefreshFromCurrent(force: true);
            }
            catch (Exception ex)
            {
                if (Time.realtimeSinceStartup - lastLogTime > 5f)
                {
                    lastLogTime = Time.realtimeSinceStartup;
                    Plugin.Logger?.LogWarning("Realtime GatherData failed: " + ex.Message);
                }
            }
        }

        internal static void LogSyncWarning(Exception ex)
        {
            if (Time.realtimeSinceStartup - lastSyncLogTime > 5f)
            {
                lastSyncLogTime = Time.realtimeSinceStartup;
                Plugin.Logger?.LogWarning("Dropped item position sync failed: " + ex.Message);
            }
        }
    }

    internal static class DroppedItemPositionSync
    {
        public static void SyncActiveDroppedItems()
        {
            try
            {
                var gameState = GameState.GameStateData;
                var manager = DroppedItemManager.Instance;
                if (gameState == null || manager == null || gameState.DropDataDict == null)
                {
                    return;
                }

                foreach (var pair in gameState.DropDataDict)
                {
                    var dropData = pair.Value;
                    if (dropData == null || !dropData.IsDropped)
                    {
                        continue;
                    }

                    var controller = manager.GetCache(dropData.ItemType);
                    if (controller == null || controller.gameObject == null || !controller.gameObject.activeInHierarchy)
                    {
                        continue;
                    }

                    var transform = controller.transform;
                    dropData.Position = transform.position;
                    dropData.Rotation = transform.rotation;
                    dropData.StageType = gameState.CurrentStageType;
                }
            }
            catch (Exception ex)
            {
                CMv2UpdatePatch.LogSyncWarning(ex);
            }
        }
    }

    internal static class PlayerPositionStateSync
    {
        public static void SyncFromLiveTransform()
        {
            if (!PlayerPositionReader.TryLivePlayerTransform(out var stage, out var position, out _))
            {
                return;
            }

            try
            {
                var state = GameState.GameStateData;
                if (state != null)
                {
                    state.PlayerPosition = position;
                    PlayerPositionMemory.Update(stage, position, 0f);
                }
            }
            catch (Exception ex)
            {
                Plugin.Logger?.LogWarning("Player position state sync failed: " + ex.Message);
            }
        }
    }

    internal static class ScriptExtensions
    {
        private static bool loggedRegistered;
        private static float lastRegisterWarningTime;

        public static void Initialize()
        {
            EnsureRegistered();
        }

        public static void EnsureRegistered()
        {
            try
            {
                if (Engine.HasFunction("DALRealtimePlayerPosition"))
                {
                    if (!Engine.HasFunction("DALPluginHudActive"))
                    {
                        Engine.RegisterFunction("DALPluginHudActive", PluginHudActive);
                    }

                    return;
                }

                Register();
            }
            catch
            {
                Register();
            }
        }

        private static void Register()
        {
            Engine.RegisterFunction("DALRealtimePlayerPosition", RealtimePlayerPosition);
            Engine.RegisterFunction("DALPluginHudActive", PluginHudActive);
            if (!loggedRegistered)
            {
                loggedRegistered = true;
                Plugin.Logger?.LogInfo("Registered CMv2 function DALRealtimePlayerPosition.");
            }
        }

        public static ProgramValue PluginHudActive(ProgramVariables parameters, ProgramThreadBase thread)
        {
            return Plugin.DrawPluginHud.Value ? ProgramValue.True : ProgramValue.False;
        }

        public static ProgramValue RealtimePlayerPosition(ProgramVariables parameters, ProgramThreadBase thread)
        {
            if (PlayerPositionMemory.TryGet(out var cachedStage, out var cachedPosition, out _, out var lastUpdateTime) &&
                Time.realtimeSinceStartup - lastUpdateTime < 2f)
            {
                return BuildPositionValue(cachedStage, cachedPosition);
            }

            if (!PlayerPositionReader.TryCurrentPlayerPosition(out var stage, out var position))
            {
                return ProgramValue.Null;
            }

            return BuildPositionValue(stage, position);
        }

        private static ProgramValue BuildPositionValue(string stage, Vector3 position)
        {
            var result = new ProgramValueList(0);
            result["stage"] = new ProgramValue(stage);
            result["x"] = new ProgramValue((double)position.x);
            result["y"] = new ProgramValue((double)position.y);
            result["z"] = new ProgramValue((double)position.z);
            return new ProgramValue(result);
        }

        public static void LogRegisterWarning(Exception ex)
        {
            if (Time.realtimeSinceStartup - lastRegisterWarningTime > 5f)
            {
                lastRegisterWarningTime = Time.realtimeSinceStartup;
                Plugin.Logger?.LogWarning("DALRealtimePlayerPosition registration failed: " + ex.Message);
            }
        }
    }

    public sealed class RealtimeHudBehaviour : MonoBehaviour
    {
        private string cachedText = string.Empty;
        private float nextTextTime;
        private GUIStyle textStyle;
        private GUIStyle shadowStyle;

        public RealtimeHudBehaviour(IntPtr ptr) : base(ptr)
        {
        }

        private void OnGUI()
        {
            if (!Plugin.DrawPluginHud.Value)
            {
                return;
            }

            if (Time.realtimeSinceStartup >= nextTextTime)
            {
                nextTextTime = Time.realtimeSinceStartup + Math.Max(0.05f, Plugin.HudPrintInterval.Value);
                cachedText = BuildHudText();
            }

            if (string.IsNullOrEmpty(cachedText))
            {
                return;
            }

            EnsureStyles();
            var x = Mathf.Clamp01(Plugin.HudX.Value) * Screen.width;
            var y = Mathf.Clamp01(Plugin.HudY.Value) * Screen.height;
            var rect = new Rect(x, y, Math.Max(360, Screen.width - x - 20), 160);
            GUI.Label(new Rect(rect.x + 1, rect.y + 1, rect.width, rect.height), cachedText, shadowStyle);
            GUI.Label(rect, cachedText, textStyle);
        }

        private void EnsureStyles()
        {
            var size = Math.Max(10, Plugin.HudFontSize.Value);
            if (textStyle != null && textStyle.fontSize == size)
            {
                return;
            }

            textStyle = new GUIStyle()
            {
                fontSize = size,
                richText = false,
                wordWrap = false
            };
            textStyle.normal.textColor = new Color(0f, 0.9f, 0.9f, 1f);

            shadowStyle = new GUIStyle()
            {
                fontSize = size,
                richText = false,
                wordWrap = false
            };
            shadowStyle.normal.textColor = new Color(0f, 0f, 0f, 0.9f);
        }

        private static string BuildHudText()
        {
            if (!PlayerPositionReader.TryCurrentPlayerPosition(out var stage, out var player))
            {
                return string.Empty;
            }

            PlayerPositionMemory.Update(stage, player, 0f);
            var playerPos = new HudPosition(stage, player);
            return "Player: " + FormatStage(playerPos.Stage) + FormatPos(playerPos.Position) +
                "\n" + BuildItemLine("Coat", "Coat", "worn", playerPos) +
                "\n" + BuildItemLine("Key", "HandcuffKey", "held", playerPos) +
                "\n" + BuildItemLine("Remote", "VibeRemocon", "held", playerPos);
        }

        private static string BuildItemLine(string label, string itemType, string heldText, HudPosition player)
        {
            if (TryDroppedItem(itemType, out var dropped))
            {
                return label + ": " + FormatStage(dropped.Stage) + FormatPos(dropped.Position) + DistanceSuffix(player, dropped);
            }

            return label + ": " + FormatStage(player.Stage) + FormatPos(player.Position) + " d=0.00 " + heldText;
        }

        private static bool TryDroppedItem(string itemType, out HudPosition position)
        {
            position = default;

            try
            {
                var state = GameState.GameStateData;
                if (state == null || state.DropDataDict == null)
                {
                    return false;
                }

                foreach (var pair in state.DropDataDict)
                {
                    var dropData = pair.Value;
                    if (dropData == null || !dropData.IsDropped)
                    {
                        continue;
                    }

                    if (!string.Equals(dropData.ItemType.ToString(), itemType, StringComparison.OrdinalIgnoreCase))
                    {
                        continue;
                    }

                    position = new HudPosition(dropData.StageType.ToString(), dropData.Position);
                    return true;
                }
            }
            catch
            {
                // If the game state is not ready, draw the item as held for now.
            }

            return false;
        }

        private static string DistanceSuffix(HudPosition player, HudPosition target)
        {
            if (!string.Equals(player.Stage, target.Stage, StringComparison.Ordinal))
            {
                return " d=--";
            }

            var distance = Vector3.Distance(player.Position, target.Position);
            return " d=" + distance.ToString("0.00", System.Globalization.CultureInfo.InvariantCulture);
        }

        private static string FormatPos(Vector3 position)
        {
            return "(" +
                position.x.ToString("0.000", System.Globalization.CultureInfo.InvariantCulture) + "," +
                position.y.ToString("0.000", System.Globalization.CultureInfo.InvariantCulture) + "," +
                position.z.ToString("0.000", System.Globalization.CultureInfo.InvariantCulture) + ")";
        }

        private static string FormatStage(string stage)
        {
            return stage == "Apart" ? "自宅" : stage;
        }

        private readonly struct HudPosition
        {
            public readonly string Stage;
            public readonly Vector3 Position;

            public HudPosition(string stage, Vector3 position)
            {
                Stage = stage;
                Position = position;
            }
        }
    }

    [HarmonyPatch]
    internal static class PlayerPositionSamplerPatch
    {
        private static MethodBase TargetMethod()
        {
            return AccessTools.Method(
                AccessTools.TypeByName("ExposureUnnoticed2.Object3D.Player.Scripts.PlayerAction"),
                "OnUpdate");
        }

        private static void Postfix(object __instance)
        {
            PlayerPositionSampler.Tick(__instance);
        }
    }

    internal static class PlayerPositionSampler
    {
        private static bool hasLast;
        private static string lastStage;
        private static Vector3 lastPosition;
        private static float nextSampleTime;

        public static void Tick(object instance)
        {
            if (!Plugin.TrackPlayerMovementSamples.Value)
            {
                return;
            }

            var now = Time.realtimeSinceStartup;
            if (now < nextSampleTime)
            {
                return;
            }

            nextSampleTime = now + Math.Max(0.05f, Plugin.PlayerMovementSampleInterval.Value);

            if (!PlayerPositionReader.TryPositionFromInstance(instance, out var stage, out var position) &&
                !PlayerPositionReader.TryCurrentPlayerPosition(out stage, out position))
            {
                return;
            }

            var distance = hasLast && stage == lastStage ? Distance(lastPosition, position) : 0f;
            var moved = !hasLast || stage != lastStage || distance >= Math.Max(0.001f, Plugin.PlayerMovementMinDistance.Value);
            if (!moved)
            {
                return;
            }

            PlayerPositionMemory.Update(stage, position, distance);
            hasLast = true;
            lastStage = stage;
            lastPosition = position;
        }

        private static float Distance(Vector3 a, Vector3 b)
        {
            var dx = a.x - b.x;
            var dy = a.y - b.y;
            var dz = a.z - b.z;
            return (float)Math.Sqrt((dx * dx) + (dy * dy) + (dz * dz));
        }
    }

    internal static class PlayerPositionMemory
    {
        private static readonly object Sync = new object();

        public static bool HasPosition { get; private set; }
        public static string Stage { get; private set; }
        public static Vector3 Position { get; private set; }
        public static float LastDelta { get; private set; }
        public static float LastUpdateTime { get; private set; }

        public static void RefreshFromCurrent(bool force)
        {
            if (!Plugin.TrackPlayerMovementSamples.Value && !force)
            {
                return;
            }

            if (PlayerPositionReader.TryCurrentPlayerPosition(out var stage, out var position))
            {
                Update(stage, position, 0f);
            }
        }

        public static void Update(string stage, Vector3 position, float delta)
        {
            lock (Sync)
            {
                HasPosition = true;
                Stage = stage;
                Position = position;
                LastDelta = delta;
                LastUpdateTime = Time.realtimeSinceStartup;
            }
        }

        public static bool TryGet(out string stage, out Vector3 position, out float lastDelta, out float lastUpdateTime)
        {
            lock (Sync)
            {
                stage = Stage;
                position = Position;
                lastDelta = LastDelta;
                lastUpdateTime = LastUpdateTime;
                return HasPosition;
            }
        }
    }

    internal static class PlayerPositionReader
    {
        private static Type playerControllerType;
        private static PropertyInfo playerControllerInstanceProperty;

        public static bool TryCurrentPlayerPosition(out string stage, out Vector3 position)
        {
            stage = null;
            position = default;

            if (TryLivePlayerTransform(out stage, out position, out _))
            {
                return true;
            }

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
                // The game state may not exist yet.
            }

            return false;
        }

        public static bool TryPositionFromInstance(object instance, out string stage, out Vector3 position)
        {
            stage = null;
            position = default;

            try
            {
                if (instance is Component component && component.transform != null)
                {
                    position = component.transform.position;
                    stage = CurrentStageName();
                    return true;
                }
            }
            catch
            {
                // The component may be destroyed while Unity updates.
            }

            return false;
        }

        public static bool TryLivePlayerTransform(out string stage, out Vector3 position, out Quaternion rotation)
        {
            stage = null;
            position = default;
            rotation = default;

            try
            {
                playerControllerType ??= AccessTools.TypeByName("ExposureUnnoticed2.Object3D.Player.Scripts.PlayerController");
                playerControllerInstanceProperty ??= AccessTools.Property(playerControllerType, "Instance");

                var player = playerControllerInstanceProperty?.GetValue(null, null) as Component;
                if (player != null)
                {
                    position = player.transform.position;
                    rotation = player.transform.rotation;
                    stage = CurrentStageName();
                    return true;
                }
            }
            catch
            {
                // The player may not exist yet.
            }

            return false;
        }

        private static string CurrentStageName()
        {
            try
            {
                var state = GameState.GameStateData;
                if (state != null)
                {
                    return state.CurrentStageType.ToString();
                }
            }
            catch
            {
                // The stage may not be initialized yet.
            }

            return "Transform";
        }
    }
}
