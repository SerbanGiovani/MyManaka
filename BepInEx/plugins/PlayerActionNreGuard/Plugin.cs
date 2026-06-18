using System;
using System.Reflection;
using BepInEx;
using BepInEx.Logging;
using BepInEx.Unity.IL2CPP;
using ExposureUnnoticed2.Master.Action;
using ExposureUnnoticed2.Object3D.Player.Scripts;
using HarmonyLib;
using Il2CppInterop.Runtime;
using UnityEngine;

namespace PlayerActionNreGuard
{
    [BepInPlugin(PluginGuid, PluginName, PluginVersion)]
    public sealed class Plugin : BasePlugin
    {
        public const string PluginGuid = "local.player_action_nre_guard";
        public const string PluginName = "Player Action NRE Guard";
        public const string PluginVersion = "1.0.0";

        internal static ManualLogSource Logger;
        private Harmony harmony;

        public override void Load()
        {
            Logger = Log;
            harmony = new Harmony(PluginGuid);
            harmony.PatchAll(typeof(PlayerActionOnUpdatePatch));
            Log.LogInfo("Player Action NRE Guard loaded.");
        }

        public override bool Unload()
        {
            harmony?.UnpatchSelf();
            return true;
        }
    }

    [HarmonyPatch]
    internal static class PlayerActionOnUpdatePatch
    {
        private static float lastLogTime;

        private static MethodBase TargetMethod()
        {
            return AccessTools.Method(typeof(PlayerAction), "OnUpdate");
        }

        private static Exception Finalizer(PlayerAction __instance, Exception __exception)
        {
            if (__exception == null)
            {
                return null;
            }

            if (!IsNullReference(__exception))
            {
                return __exception;
            }

            TryResetAction(__instance);

            if (Time.realtimeSinceStartup - lastLogTime > 2f)
            {
                lastLogTime = Time.realtimeSinceStartup;
                Plugin.Logger?.LogWarning("Suppressed PlayerAction.OnUpdate null reference and requested ActionType.None.");
            }

            return null;
        }

        private static bool IsNullReference(Exception ex)
        {
            if (ex is NullReferenceException)
            {
                return true;
            }

            if (ex is Il2CppException il2CppException)
            {
                return il2CppException.ToString().IndexOf("NullReferenceException", StringComparison.OrdinalIgnoreCase) >= 0;
            }

            return ex.ToString().IndexOf("NullReferenceException", StringComparison.OrdinalIgnoreCase) >= 0;
        }

        private static void TryResetAction(PlayerAction action)
        {
            try
            {
                action?.ChangeAction(ActionType.None);
                if (action != null)
                {
                    action.IsAlreadyChangeActionThisFrame = false;
                }
            }
            catch
            {
            }
        }
    }
}
