using System;
using System.Reflection;
using BepInEx;
using BepInEx.Configuration;
using BepInEx.Logging;
using BepInEx.Unity.IL2CPP;
using HarmonyLib;

namespace DumbRendererDemosaicGuard
{
    [BepInPlugin(PluginGuid, PluginName, PluginVersion)]
    public sealed class Plugin : BasePlugin
    {
        public const string PluginGuid = "local.dumb_renderer_demosaic_guard";
        public const string PluginName = "DumbRendererDemosaic Guard";
        public const string PluginVersion = "1.0.0";

        internal static ManualLogSource Logger;
        internal static ConfigEntry<bool> SkipOnGui;

        private Harmony harmony;

        public override void Load()
        {
            Logger = Log;
            SkipOnGui = Config.Bind("General", "SkipOnGui", true, "Skip DumbRendererDemosaic.OnGUI to avoid IL2CPP trampoline NullReferenceException.");

            try
            {
                harmony = new Harmony(PluginGuid);
                harmony.PatchAll(typeof(DumbRendererDemosaicOnGuiPatch));
                Log.LogInfo("DumbRendererDemosaic Guard loaded.");
            }
            catch (Exception ex)
            {
                Log.LogError("DumbRendererDemosaic Guard failed to load: " + ex);
            }
        }

        public override bool Unload()
        {
            harmony?.UnpatchSelf();
            return true;
        }
    }

    [HarmonyPatch]
    internal static class DumbRendererDemosaicOnGuiPatch
    {
        private static MethodBase TargetMethod()
        {
            var type = AccessTools.TypeByName("DumbRendererDemosaic.DumbRendererDemosaic");
            return type == null ? null : AccessTools.Method(type, "OnGUI");
        }

        private static bool Prefix()
        {
            return Plugin.SkipOnGui == null || !Plugin.SkipOnGui.Value;
        }
    }
}
