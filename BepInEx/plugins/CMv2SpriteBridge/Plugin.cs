using System;
using System.Collections.Generic;
using System.Globalization;
using System.IO;
using BepInEx;
using BepInEx.Configuration;
using BepInEx.Logging;
using BepInEx.Unity.IL2CPP;
using SFM_custom_mission_v2.Script;
using UnityEngine;

namespace CMv2SpriteBridge
{
    [BepInPlugin(PluginGuid, PluginName, PluginVersion)]
    [BepInDependency("SFM_custom_mission_v2")]
    public sealed class Plugin : BasePlugin
    {
        public const string PluginGuid = "local.cmv2_sprite_bridge";
        public const string PluginName = "CMv2 Sprite Bridge";
        public const string PluginVersion = "0.1.0";

        internal static ManualLogSource Logger;
        internal static ConfigEntry<string> ImageDirectory;
        internal static ConfigEntry<bool> AddCollider;
        internal static ConfigEntry<string> DefaultShader;

        public override void Load()
        {
            Logger = Log;
            ImageDirectory = Config.Bind("General", "ImageDirectory", "BepInEx/config/CMv2Sprites", "Directory used for relative sprite image paths.");
            AddCollider = Config.Bind("General", "AddCollider", false, "Keep a MeshCollider on created sprites.");
            DefaultShader = Config.Bind("General", "DefaultShader", "Unlit/Transparent", "Shader used for sprite materials.");

            Directory.CreateDirectory(ResolveRootedPath(ImageDirectory.Value));
            SpriteScriptExtensions.Initialize();
            Log.LogInfo("CMv2 Sprite Bridge loaded.");
        }

        internal static string ResolveRootedPath(string path)
        {
            if (string.IsNullOrWhiteSpace(path))
            {
                return Paths.GameRootPath;
            }

            path = path.Replace('/', Path.DirectorySeparatorChar);
            return Path.IsPathRooted(path) ? path : Path.Combine(Paths.GameRootPath, path);
        }
    }

    internal static class SpriteScriptExtensions
    {
        private static bool registered;

        public static void Initialize()
        {
            if (registered)
            {
                return;
            }

            Engine.RegisterFunction("CreateSprite", CreateSprite);
            ProgramObject.RegisterFunction(typeof(Object_CMv2Sprite), "Remove", Remove);
            ProgramObject.RegisterFunction(typeof(Object_CMv2Sprite), "SetPosition", SetPosition);
            ProgramObject.RegisterFunction(typeof(Object_CMv2Sprite), "SetRotation", SetRotation);
            ProgramObject.RegisterFunction(typeof(Object_CMv2Sprite), "SetScale", SetScale);
            ProgramObject.RegisterFunction(typeof(Object_CMv2Sprite), "SetAlpha", SetAlpha);
            ProgramObject.RegisterFunction(typeof(Object_CMv2Sprite), "SetVisible", SetVisible);
            registered = true;
            Plugin.Logger?.LogInfo("Registered CMv2 function CreateSprite.");
        }

        public static ProgramValue CreateSprite(ProgramVariables parameters, ProgramThreadBase thread)
        {
            try
            {
                var filename = GetString(parameters, "filename", 0, string.Empty);
                if (string.IsNullOrWhiteSpace(filename))
                {
                    filename = GetString(parameters, "file", 0, string.Empty);
                }

                var imagePath = ResolveImagePath(filename);
                if (!File.Exists(imagePath))
                {
                    Plugin.Logger?.LogWarning("CreateSprite image not found: " + imagePath);
                    return ProgramValue.Null;
                }

                var position = GetVector(parameters, "position", new Vector3(
                    GetFloat(parameters, "x", 1, 0f),
                    GetFloat(parameters, "y", 2, 0f),
                    GetFloat(parameters, "z", 3, 0f)));
                var rotation = GetVector(parameters, "rotation", new Vector3(
                    GetFloat(parameters, "rx", -1, 0f),
                    GetFloat(parameters, "ry", -1, 0f),
                    GetFloat(parameters, "rz", -1, 0f)));
                var width = GetFloat(parameters, "width", -1, 1f);
                var height = GetFloat(parameters, "height", -1, 1f);
                var alpha = Mathf.Clamp01(GetFloat(parameters, "alpha", -1, 1f));
                var name = GetString(parameters, "name", -1, Path.GetFileNameWithoutExtension(imagePath));

                var sprite = Object_CMv2Sprite.Create(imagePath, name, position, rotation, width, height, alpha);
                return new ProgramValue(sprite);
            }
            catch (Exception ex)
            {
                Plugin.Logger?.LogError("CreateSprite failed: " + ex);
                return ProgramValue.Null;
            }
        }

        private static ProgramValue Remove(ProgramObject obj, ProgramVariables parameters, ProgramThreadBase thread)
        {
            (obj as Object_CMv2Sprite)?.Remove();
            return ProgramValue.Null;
        }

        private static ProgramValue SetPosition(ProgramObject obj, ProgramVariables parameters, ProgramThreadBase thread)
        {
            if (obj is Object_CMv2Sprite sprite)
            {
                var position = GetVector(parameters, "position", new Vector3(
                    GetFloat(parameters, "x", 0, sprite.Position.x),
                    GetFloat(parameters, "y", 1, sprite.Position.y),
                    GetFloat(parameters, "z", 2, sprite.Position.z)));
                sprite.SetPosition(position);
            }

            return ProgramValue.Null;
        }

        private static ProgramValue SetRotation(ProgramObject obj, ProgramVariables parameters, ProgramThreadBase thread)
        {
            if (obj is Object_CMv2Sprite sprite)
            {
                var rotation = GetVector(parameters, "rotation", new Vector3(
                    GetFloat(parameters, "rx", 0, sprite.Rotation.x),
                    GetFloat(parameters, "ry", 1, sprite.Rotation.y),
                    GetFloat(parameters, "rz", 2, sprite.Rotation.z)));
                sprite.SetRotation(rotation);
            }

            return ProgramValue.Null;
        }

        private static ProgramValue SetScale(ProgramObject obj, ProgramVariables parameters, ProgramThreadBase thread)
        {
            if (obj is Object_CMv2Sprite sprite)
            {
                var width = GetFloat(parameters, "width", 0, sprite.Width);
                var height = GetFloat(parameters, "height", 1, sprite.Height);
                sprite.SetScale(width, height);
            }

            return ProgramValue.Null;
        }

        private static ProgramValue SetAlpha(ProgramObject obj, ProgramVariables parameters, ProgramThreadBase thread)
        {
            if (obj is Object_CMv2Sprite sprite)
            {
                sprite.SetAlpha(Mathf.Clamp01(GetFloat(parameters, "alpha", 0, sprite.Alpha)));
            }

            return ProgramValue.Null;
        }

        private static ProgramValue SetVisible(ProgramObject obj, ProgramVariables parameters, ProgramThreadBase thread)
        {
            if (obj is Object_CMv2Sprite sprite)
            {
                sprite.SetVisible(GetBool(parameters, "visible", 0, true));
            }

            return ProgramValue.Null;
        }

        private static string ResolveImagePath(string filename)
        {
            filename = (filename ?? string.Empty).Replace('/', Path.DirectorySeparatorChar);
            if (Path.IsPathRooted(filename))
            {
                return filename;
            }

            var fromImageDir = Path.Combine(Plugin.ResolveRootedPath(Plugin.ImageDirectory.Value), filename);
            if (File.Exists(fromImageDir))
            {
                return fromImageDir;
            }

            var fromGameRoot = Path.Combine(Paths.GameRootPath, filename);
            if (File.Exists(fromGameRoot))
            {
                return fromGameRoot;
            }

            return fromImageDir;
        }

        private static ProgramValue GetParam(ProgramVariables parameters, string name, int argIndex)
        {
            try
            {
                if (!string.IsNullOrEmpty(name) && parameters.HasVariable(name))
                {
                    return parameters.GetVariable(name);
                }
            }
            catch
            {
            }

            if (argIndex >= 0)
            {
                try
                {
                    var args = parameters.GetVariable("_args").ToList();
                    if (args != null && argIndex < args.Count())
                    {
                        return args[argIndex];
                    }
                }
                catch
                {
                }
            }

            return null;
        }

        private static string GetString(ProgramVariables parameters, string name, int argIndex, string fallback)
        {
            var value = GetParam(parameters, name, argIndex);
            return value == null || value.IsNull() ? fallback : value.ToString();
        }

        private static float GetFloat(ProgramVariables parameters, string name, int argIndex, float fallback)
        {
            var value = GetParam(parameters, name, argIndex);
            if (value == null || value.IsNull())
            {
                return fallback;
            }

            try
            {
                return (float)value.ToFloat();
            }
            catch
            {
                if (float.TryParse(value.ToString(), NumberStyles.Float, CultureInfo.InvariantCulture, out var parsed))
                {
                    return parsed;
                }

                return fallback;
            }
        }

        private static bool GetBool(ProgramVariables parameters, string name, int argIndex, bool fallback)
        {
            var value = GetParam(parameters, name, argIndex);
            if (value == null || value.IsNull())
            {
                return fallback;
            }

            try
            {
                return value.ToBool();
            }
            catch
            {
                return fallback;
            }
        }

        private static Vector3 GetVector(ProgramVariables parameters, string name, Vector3 fallback)
        {
            try
            {
                if (parameters.HasVariable(name))
                {
                    return FunctionsMath.VectorFromList(parameters.GetVariable(name).ToList());
                }
            }
            catch
            {
            }

            return fallback;
        }
    }

    public sealed class Object_CMv2Sprite : ProgramObject
    {
        private readonly Texture2D texture;
        private readonly Material material;
        private GameObject gameObject;
        private MeshRenderer renderer;

        public Vector3 Position { get; private set; }
        public Vector3 Rotation { get; private set; }
        public float Width { get; private set; }
        public float Height { get; private set; }
        public float Alpha { get; private set; }

        private Object_CMv2Sprite(GameObject gameObject, Texture2D texture, Material material, MeshRenderer renderer)
        {
            this.gameObject = gameObject;
            this.texture = texture;
            this.material = material;
            this.renderer = renderer;
        }

        public static Object_CMv2Sprite Create(string imagePath, string name, Vector3 position, Vector3 rotation, float width, float height, float alpha)
        {
            var texture = new Texture2D(2, 2, TextureFormat.RGBA32, false);
            if (!ImageConversion.LoadImage(texture, File.ReadAllBytes(imagePath)))
            {
                UnityEngine.Object.Destroy(texture);
                throw new InvalidOperationException("Unity could not load image: " + imagePath);
            }

            texture.wrapMode = TextureWrapMode.Clamp;
            texture.filterMode = FilterMode.Bilinear;

            var shader = Shader.Find(Plugin.DefaultShader.Value);
            if (shader == null)
            {
                shader = Shader.Find("Unlit/Texture");
            }

            var material = new Material(shader);
            material.mainTexture = texture;
            material.color = new Color(1f, 1f, 1f, alpha);

            var go = GameObject.CreatePrimitive(PrimitiveType.Quad);
            go.name = "CMv2Sprite_" + SanitizeName(name);

            var collider = go.GetComponent<MeshCollider>();
            if (collider != null && !Plugin.AddCollider.Value)
            {
                UnityEngine.Object.Destroy(collider);
            }

            var renderer = go.GetComponent<MeshRenderer>();
            renderer.material = material;

            var sprite = new Object_CMv2Sprite(go, texture, material, renderer);
            sprite.SetPosition(position);
            sprite.SetRotation(rotation);
            sprite.SetScale(width, height);
            sprite.SetAlpha(alpha);
            return sprite;
        }

        public override void OnDestroy()
        {
            Remove();
        }

        public void Remove()
        {
            if (gameObject == null)
            {
                return;
            }

            try
            {
                UnityEngine.Object.Destroy(gameObject);
                if (material != null)
                {
                    UnityEngine.Object.Destroy(material);
                }

                if (texture != null)
                {
                    UnityEngine.Object.Destroy(texture);
                }
            }
            catch (Exception ex)
            {
                Plugin.Logger?.LogWarning("Sprite remove failed: " + ex.Message);
            }
            finally
            {
                gameObject = null;
                renderer = null;
            }
        }

        public void SetPosition(Vector3 position)
        {
            Position = position;
            if (gameObject != null)
            {
                gameObject.transform.position = position;
            }
        }

        public void SetRotation(Vector3 rotation)
        {
            Rotation = rotation;
            if (gameObject != null)
            {
                gameObject.transform.rotation = Quaternion.Euler(rotation);
            }
        }

        public void SetScale(float width, float height)
        {
            Width = Mathf.Max(0.001f, width);
            Height = Mathf.Max(0.001f, height);
            if (gameObject != null)
            {
                gameObject.transform.localScale = new Vector3(Width, Height, 1f);
            }
        }

        public void SetAlpha(float alpha)
        {
            Alpha = Mathf.Clamp01(alpha);
            if (material != null)
            {
                material.color = new Color(1f, 1f, 1f, Alpha);
            }
        }

        public void SetVisible(bool visible)
        {
            if (renderer != null)
            {
                renderer.enabled = visible;
            }
        }

        private static string SanitizeName(string value)
        {
            if (string.IsNullOrWhiteSpace(value))
            {
                return "sprite";
            }

            foreach (var c in Path.GetInvalidFileNameChars())
            {
                value = value.Replace(c, '_');
            }

            return value;
        }
    }
}
