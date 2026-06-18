using System;
using System.Reflection;
using BepInEx;
using BepInEx.Logging;
using BepInEx.Unity.IL2CPP;
using ExposureUnnoticed2.Scripts.Sound;
using HarmonyLib;
using UnityEngine;

namespace SoundNullGuard
{
    [BepInPlugin(PluginGuid, PluginName, PluginVersion)]
    public sealed class Plugin : BasePlugin
    {
        public const string PluginGuid = "local.sound_null_guard";
        public const string PluginName = "Sound Null Guard";
        public const string PluginVersion = "1.0.0";

        internal static ManualLogSource Logger;
        private Harmony harmony;

        public override void Load()
        {
            Logger = Log;
            harmony = new Harmony(PluginGuid);
            harmony.PatchAll(typeof(PlayOneShotAudioDataPatch));
            Log.LogInfo("Sound Null Guard loaded.");
        }

        public override bool Unload()
        {
            harmony?.UnpatchSelf();
            return true;
        }
    }

    [HarmonyPatch]
    internal static class PlayOneShotAudioDataPatch
    {
        private static MethodBase TargetMethod()
        {
            return AccessTools.Method(
                typeof(InGameSoundManager),
                "PlayOneShotAudioData",
                new[] { typeof(AudioSource), typeof(InGameSoundManager.SeType), typeof(float) });
        }

        private static bool Prefix(AudioSource audioSource, InGameSoundManager.SeType type)
        {
            if (audioSource != null)
            {
                return true;
            }

            Plugin.Logger?.LogDebug($"Skipped sound {type}: AudioSource is null.");
            return false;
        }
    }
}
