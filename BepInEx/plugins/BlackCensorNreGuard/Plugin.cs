using System;
using System.Reflection;
using BepInEx;
using BepInEx.Logging;
using BepInEx.Unity.IL2CPP;
using HarmonyLib;

namespace BlackCensorNreGuard
{
    [BepInPlugin(PluginGuid, PluginName, PluginVersion)]
    public sealed class Plugin : BasePlugin
    {
        public const string PluginGuid = "local.black_censor_nre_guard";
        public const string PluginName = "Black Censor NRE Guard";
        public const string PluginVersion = "1.0.0";

        internal static ManualLogSource Logger;

        public override void Load()
        {
            Logger = Log;

            try
            {
                var type = TypeResolver.Find("ExposureUnnoticed2.Object3D.Player.Scripts.Other.BlackCensorController");
                var method = type?.GetMethod("OnChange", BindingFlags.Instance | BindingFlags.Public | BindingFlags.NonPublic);
                if (method == null)
                {
                    Log.LogWarning("BlackCensorController.OnChange was not found.");
                    return;
                }

                var harmony = new Harmony(PluginGuid);
                harmony.Patch(method, prefix: new HarmonyMethod(typeof(BlackCensorControllerPatch), nameof(BlackCensorControllerPatch.Prefix)));
                Log.LogInfo("BlackCensorController.OnChange disabled to suppress null-reference spam.");
            }
            catch (Exception ex)
            {
                Log.LogError("Failed to patch BlackCensorController.OnChange: " + ex);
            }
        }
    }

    internal static class BlackCensorControllerPatch
    {
        private static bool logged;

        public static bool Prefix()
        {
            if (!logged)
            {
                logged = true;
                Plugin.Logger.LogWarning("Suppressed BlackCensorController.OnChange.");
            }

            return false;
        }
    }

    internal static class TypeResolver
    {
        public static Type Find(string fullName)
        {
            var type = Type.GetType(fullName + ", Assembly-CSharp", false);
            if (type != null)
            {
                return type;
            }

            foreach (var assembly in AppDomain.CurrentDomain.GetAssemblies())
            {
                if (!string.Equals(assembly.GetName().Name, "Assembly-CSharp", StringComparison.Ordinal))
                {
                    continue;
                }

                return assembly.GetType(fullName, false);
            }

            return null;
        }
    }
}
