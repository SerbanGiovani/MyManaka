# CMv2 Sprite Bridge

Adds `CreateSprite(...)` to Custom Mission v2 scripts. The function creates a textured Quad in the current Unity scene and returns a CMv2 object handle.

Default image folder:

```text
BepInEx/config/CMv2Sprites
```

Example:

```text
poster = CreateSprite(
    filename="poster.png",
    x=0.0, y=1.2, z=2.0,
    rx=0, ry=180, rz=0,
    width=0.7, height=1.0,
    alpha=1.0,
    name="poster_test"
)

poster.SetPosition(x=0.2, y=1.2, z=2.0)
poster.SetRotation(rx=0, ry=180, rz=0)
poster.SetScale(width=0.7, height=1.0)
poster.SetAlpha(alpha=0.85)
poster.SetVisible(visible=true)
poster.Remove()
```

Notes:

- Relative filenames are resolved from `BepInEx/config/CMv2Sprites` first, then the game root.
- Supported formats are Unity `ImageConversion.LoadImage` formats, typically PNG and JPG.
- The object is scene-local. Recreate it after changing maps if the scene unloads.
- `Remove()` is idempotent, so repeated cleanup calls should not throw on an already destroyed object.
