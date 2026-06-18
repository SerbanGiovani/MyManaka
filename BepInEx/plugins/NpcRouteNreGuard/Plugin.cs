using System;
using System.Reflection;
using BepInEx;
using BepInEx.Logging;
using BepInEx.Unity.IL2CPP;
using Common.CommonUI.MultiPfButtonUi;
using ExposureUnnoticed2.Object3D.NPC.Script;
using HarmonyLib;
using Il2CppInterop.Runtime;
using UnityEngine;

namespace NpcRouteNreGuard
{
    [BepInPlugin(PluginGuid, PluginName, PluginVersion)]
    public sealed class Plugin : BasePlugin
    {
        public const string PluginGuid = "local.npc_route_nre_guard";
        public const string PluginName = "NPC Route NRE Guard";
        public const string PluginVersion = "1.0.0";

        internal static ManualLogSource Logger;
        private Harmony harmony;

        public override void Load()
        {
            Logger = Log;
            harmony = new Harmony(PluginGuid);
            harmony.PatchAll(typeof(NpcControllerPatch));
            harmony.PatchAll(typeof(NpcLocomotionPatch));
            harmony.PatchAll(typeof(MultiPfButtonPatch));
            Log.LogInfo("NPC Route NRE Guard loaded.");
        }

        public override bool Unload()
        {
            harmony?.UnpatchSelf();
            return true;
        }
    }

    internal static class Guard
    {
        private static float lastNpcLogTime;
        private static float lastUiLogTime;

        internal static Exception SuppressNpcRoute(Exception exception)
        {
            if (exception == null)
            {
                return null;
            }

            if (!IsNullReference(exception))
            {
                return exception;
            }

            if (Time.realtimeSinceStartup - lastNpcLogTime > 5f)
            {
                lastNpcLogTime = Time.realtimeSinceStartup;
                Plugin.Logger?.LogWarning("Suppressed NPC route null reference.");
            }

            return null;
        }

        internal static Exception SuppressUi(Exception exception)
        {
            if (exception == null)
            {
                return null;
            }

            if (!IsNullReference(exception))
            {
                return exception;
            }

            if (Time.realtimeSinceStartup - lastUiLogTime > 5f)
            {
                lastUiLogTime = Time.realtimeSinceStartup;
                Plugin.Logger?.LogWarning("Suppressed MultiPfButtonUi.RefreshView null reference.");
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
    }

    [HarmonyPatch]
    internal static class NpcControllerPatch
    {
        private static MethodBase TargetMethod()
        {
            return AccessTools.Method(typeof(NpcController), "OnUpdate");
        }

        private static Exception Finalizer(Exception __exception)
        {
            return Guard.SuppressNpcRoute(__exception);
        }
    }

    [HarmonyPatch]
    internal static class NpcLocomotionPatch
    {
        private static MethodBase TargetMethod()
        {
            return AccessTools.Method(typeof(NpcLocomotion), "OnUpdate");
        }

        private static Exception Finalizer(Exception __exception)
        {
            return Guard.SuppressNpcRoute(__exception);
        }
    }

    [HarmonyPatch]
    internal static class MultiPfButtonPatch
    {
        private static MethodBase TargetMethod()
        {
            return AccessTools.Method(typeof(MultiPfButtonUiView), "RefreshView");
        }

        private static Exception Finalizer(Exception __exception)
        {
            return Guard.SuppressUi(__exception);
        }
    }
}
