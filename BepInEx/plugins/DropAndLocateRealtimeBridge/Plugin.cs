using System;
using System.Reflection;
using BepInEx;
using BepInEx.Logging;
using BepInEx.Unity.IL2CPP;
using HarmonyLib;
using SFM_custom_mission_v2;

namespace DropAndLocateRealtimeBridge
{
    [BepInPlugin(PluginGuid, PluginName, PluginVersion)]
    [BepInDependency("SFM_custom_mission_v2")]
    public sealed class Plugin : BasePlugin
    {
        public const string PluginGuid = "local.drop_and_locate_realtime_bridge";
        public const string PluginName = "Drop and Locate Realtime Bridge";
        public const string PluginVersion = "1.0.0";

        internal static ManualLogSource Logger;
        private Harmony harmony;

        public override void Load()
        {
            Logger = Log;
            harmony = new Harmony(PluginGuid);
            harmony.PatchAll(typeof(CMv2UpdatePatch));
            Log.LogInfo("Drop and Locate Realtime Bridge loaded.");
        }

        public override bool Unload()
        {
            harmony?.UnpatchSelf();
            return true;
        }
    }

    [HarmonyPatch]
    internal static class CMv2UpdatePatch
    {
        private static float lastLogTime;

        private static MethodBase TargetMethod()
        {
            return AccessTools.Method(typeof(SFM_custom_mission_v2.Plugin), "Update");
        }

        private static void Prefix()
        {
            try
            {
                PlayerData.GatherData();
            }
            catch (Exception ex)
            {
                if (UnityEngine.Time.realtimeSinceStartup - lastLogTime > 5f)
                {
                    lastLogTime = UnityEngine.Time.realtimeSinceStartup;
                    Plugin.Logger?.LogWarning("Realtime GatherData failed: " + ex.Message);
                }
            }
        }
    }
}
