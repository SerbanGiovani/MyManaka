using System;
using System.IO;
using System.Reflection;
using BepInEx;
using BepInEx.Configuration;
using BepInEx.Logging;
using BepInEx.Unity.IL2CPP;
using HarmonyLib;
using Il2CppInput = BepInEx.Unity.IL2CPP.UnityEngine.Input;
using Il2CppKeyCode = BepInEx.Unity.IL2CPP.UnityEngine.KeyCode;

[assembly: System.Runtime.Versioning.TargetFramework(".NETCoreApp,Version=v6.0", FrameworkDisplayName = ".NET 6.0")]

namespace ReloadAllHotkey
{
    [BepInPlugin(PluginGuid, PluginName, PluginVersion)]
    public sealed class Plugin : BasePlugin
    {
        public const string PluginGuid = "local.reload_all_hotkey";
        public const string PluginName = "Reload All Hotkey";
        public const string PluginVersion = "1.0.0";

        internal static ConfigEntry<bool> EnableHotkey;
        internal static ConfigEntry<int> ReloadKeyCode;
        internal static ConfigEntry<bool> RequireCtrl;
        internal static ConfigEntry<bool> RequireShift;
        internal static ConfigEntry<bool> ReloadBepInExConfigs;
        internal static ConfigEntry<bool> ReloadCustomMissions2;
        internal static ManualLogSource Logger;

        private Harmony harmony;

        public override void Load()
        {
            Logger = Log;

            EnableHotkey = Config.Bind("Hotkey", "EnableHotkey", true, "Enable the reload hotkey.");
            ReloadKeyCode = Config.Bind("Hotkey", "ReloadKeyCode", 291, "Unity KeyCode number for the reload key. 291 = F10.");
            RequireCtrl = Config.Bind("Hotkey", "RequireCtrl", true, "Require LeftCtrl or RightCtrl.");
            RequireShift = Config.Bind("Hotkey", "RequireShift", false, "Require LeftShift or RightShift.");
            ReloadBepInExConfigs = Config.Bind("Reload", "ReloadBepInExConfigs", true, "Reload loaded BepInEx plugin config files. This does not unload/reload plugin DLL code.");
            ReloadCustomMissions2 = Config.Bind("Reload", "ReloadCustomMissions2", false, "Call Custom Missions v2 Engine.Reload() to reload CustomMissions2 code. This is unsafe with active zones/areas; restart the game for CMv2 changes.");

            try
            {
                harmony = new Harmony(PluginGuid);
                harmony.PatchAll(typeof(InputManagerUpdatePatch));
                Log.LogInfo("Reload All Hotkey loaded. Default hotkey: Ctrl+F10.");
            }
            catch (Exception ex)
            {
                Log.LogError("Reload All Hotkey failed to patch InputManager.Update: " + ex);
            }
        }
    }

    [HarmonyPatch]
    internal static class InputManagerUpdatePatch
    {
        private static MethodBase TargetMethod()
        {
            var type = TypeResolver.Find("ExposureUnnoticed2.Scripts.Base.InputManager");
            var method = type == null ? null : type.GetMethod("Update", BindingFlags.Instance | BindingFlags.Public | BindingFlags.NonPublic);
            if (method == null)
            {
                throw new MissingMethodException("ExposureUnnoticed2.Scripts.Base.InputManager", "Update");
            }

            return method;
        }

        private static void Postfix()
        {
            ReloadController.Tick();
        }
    }

    internal static class ReloadController
    {
        private static bool wasPressed;
        private static bool reloading;

        public static void Tick()
        {
            if (Plugin.EnableHotkey == null || !Plugin.EnableHotkey.Value)
            {
                wasPressed = false;
                return;
            }

            var keyDown = GetKey(Plugin.ReloadKeyCode.Value);
            var ctrlOk = !Plugin.RequireCtrl.Value || GetKey(306) || GetKey(305);
            var shiftOk = !Plugin.RequireShift.Value || GetKey(304) || GetKey(303);
            var pressed = keyDown && ctrlOk && shiftOk;

            if (pressed && !wasPressed && !reloading)
            {
                ReloadAll();
            }

            wasPressed = pressed;
        }

        private static bool GetKey(int keyCode)
        {
            return Il2CppInput.GetKeyInt((Il2CppKeyCode)keyCode);
        }

        private static void ReloadAll()
        {
            reloading = true;
            try
            {
                Plugin.Logger.LogInfo("[ReloadAll] Reload requested.");

                if (Plugin.ReloadBepInExConfigs.Value)
                {
                    ReloadLoadedPluginConfigs();
                }

                if (Plugin.ReloadCustomMissions2.Value)
                {
                    ReloadCustomMissions();
                }

                Plugin.Logger.LogInfo("[ReloadAll] Done.");
            }
            finally
            {
                reloading = false;
            }
        }

        private static void ReloadLoadedPluginConfigs()
        {
            var reloaded = 0;
            var skippedMissing = 0;
            foreach (var pair in IL2CPPChainloader.Instance.Plugins)
            {
                try
                {
                    var plugin = pair.Value.Instance as BasePlugin;
                    if (plugin == null || plugin.Config == null)
                    {
                        continue;
                    }

                    if (string.IsNullOrEmpty(plugin.Config.ConfigFilePath) || !File.Exists(plugin.Config.ConfigFilePath))
                    {
                        skippedMissing++;
                        continue;
                    }

                    plugin.Config.Reload();
                    reloaded++;
                }
                catch (Exception ex)
                {
                    Plugin.Logger.LogWarning("[ReloadAll] Config reload failed for " + pair.Key + ": " + ex.Message);
                }
            }

            Plugin.Logger.LogInfo("[ReloadAll] Reloaded BepInEx config files: " + reloaded + " (skipped missing: " + skippedMissing + ")");
        }

        private static void ReloadCustomMissions()
        {
            try
            {
                var engineType = Type.GetType("SFM_custom_mission_v2.Script.Engine, SFM_custom_mission_v2");
                if (engineType == null)
                {
                    Plugin.Logger.LogWarning("[ReloadAll] Custom Missions v2 Engine type was not found.");
                    return;
                }

                var reload = engineType.GetMethod("Reload", BindingFlags.Public | BindingFlags.Static);
                if (reload == null)
                {
                    Plugin.Logger.LogWarning("[ReloadAll] Custom Missions v2 Engine.Reload() was not found.");
                    return;
                }

                reload.Invoke(null, null);
                Plugin.Logger.LogInfo("[ReloadAll] Custom Missions v2 Engine.Reload() called.");
            }
            catch (Exception ex)
            {
                Plugin.Logger.LogError("[ReloadAll] Custom Missions v2 reload failed: " + ex);
            }
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
