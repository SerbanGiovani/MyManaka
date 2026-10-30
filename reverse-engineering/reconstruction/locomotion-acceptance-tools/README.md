# Independent locomotion acceptance

This directory is a new acceptance stage. It does not rewrite or upgrade the
historical minimal-runtime/save-bridge result. In particular, the old simulated
axis run remains `hardware_keyboard_tested=false`.

The verifier is a read-only consumer of runtime evidence, OS lifecycle receipts,
the independently prepared original-controller identity, and the independent
version 1 JSON save. It never launches an editor/player, sends a key, reads or
writes the original encrypted save, or changes another acceptance result.

## Evidence contract

1. Each JSONL event has `processGuid`, strictly ordered `frame`/`real`, `kind`,
   `utc` and `data`. Every sample records actual Unity legacy input reads and
   the resulting CharacterController step; a proof-level boolean is insufficient.
2. `locomotion_sample` identifies `inputSource` (`unity-legacy` or
   `simulated-axes`) and `inputProvenance`. Record `simulated`, focus, axes,
   `keys`, `keyDown`, `keyUp` for WASD, Shift, C, F5 and F6; the actual `dt`,
   position before/after `CharacterController.Move`, collision flags and actual
   speed. Record both `Input.GetAxis` and raw axes if used differently.
3. The same frame's Animator evidence records enabled/active/initialized,
   root-motion policy, speed, every layer's weight/current and next hashes,
   normalized times and current clips/weights, actual parameter values, and at
   least hip/leg/foot local positions and rotations. Local bone changes prevent
   actor/root translation from masquerading as skeletal animation.
4. `animator_bound` records source bundle SHA256, exact original prefab and
   controller asset path, controller/avatar names and source PPtr/path IDs,
   instance IDs, valid/humanoid avatar flags and clip names. Independently match
   these against the static original-controller inventory. A same-name newly
   authored controller does not satisfy original-controller acceptance.
5. Observe initial Idle, keyboard down -> Walk, Shift down -> Run, key release
   -> Idle. The original three clips are children of **one**
   `Locomotion.LocomotionTree` state (full-path hash `686120411`), with Speed
   thresholds 0/1/2 and clips `Female_Idle_Base`, `Female_Walk_Forward`,
   `Female_Jog_Forward`. These are not three separate states. Require several
   stable non-transition samples with at least .9 matching clip weight and
   Speed within .075 of the original threshold, advancing animation
   time, changing non-root local bones, nonzero actual horizontal CC movement,
   and a grounded/Below collision. A screenshot is supporting visual evidence,
   not a substitute for these observations.
6. `keyboard_command` records the actual Unity `GetKeyDown(F5/F6)` read,
   requested action and actual pose. F5 and F6 each need an observed key-down
   event. F6 must finish saving and exit; delayed screenshots must not permit
   a different later pose to enter the save unnoticed.
7. `save_completed` records the actual Transform, revision, writer Guid and
   bytes SHA256. `save_pose_canonicalized` and `save_roundtrip_verified` record
   signed int32 bits for the seven pose components plus `bodyPaintRemaining`.
   The sole permitted change is `0x80000000` (-0) to `0x00000000` (+0), with
   the exact component list/count disclosed. Every nonzero source bit and every
   canonical/disk bit must remain strictly identical. The actor Transform must
   not be modified. Raw negative-zero signs are not preserved by this save
   policy; ordinary JSON numeric text cannot independently expose those signs.
   A new OS process must read the same bytes and apply the same
   float32 pose before enabling physics. Inventory, customization, paint data,
   original cipher SHA and schema/file kind remain compatible with old own JSON.
8. External process-start/exit receipts identify the visible executable, SHA,
   `assembly_path` and `assembly_sha256` for `Assembly-CSharp.dll`, profile, PID,
   arguments, clean exit, and launch/exit times. Both processes must use the same
   managed-assembly SHA; identical Unity launcher EXEs are insufficient. The
   `--inputs` check also rehashes that managed assembly. Runtime Guid is
   checked separately from PID because operating systems may reuse PIDs.

Unfocused pure Idle observations with zero axes, no held keys or key edges, and
no horizontal movement are counted and listed in excluded frame/UTC intervals.
They cannot contribute to keyboard-operation windows. Any unfocused positive
input is rejected. Focused clip windows retain the same consecutive-frame,
weight, Speed, animation-time and local-bone requirements; focus gaps cannot be
used to join otherwise-short windows.

## Input claims

`Input.GetAxis`/`GetKey` identify Unity's input path, not the keyboard's physical
origin. `--input-origin os-injected-keyboard`, a SendInput receipt, or a CUA key
operation can establish **OS-injected input observed by Unity**. It cannot
establish a physical keyboard. `undeclared_keyboard_device` remains unspecified.

Keep external input receipts separate from runtime evidence. A receipt should
name its backend, `source` (`os-sendinput`, `cua-sendinput`, `physical-user` or
`undeclared`), target PID/window and UTC key-down/up intervals, successful API
return counts, and all key releases. Physical-user claims additionally need the
user's explicit observation/attestation; lack of an injection log is not proof
of hardware. Even an attestation is reported as human evidence, not as a device
identity measured by Unity. Never fabricate this receipt from runtime keys.

Read-only capability inspection found the bundled computer-use skill documents
SendInput, UI Automation and Windows.Graphics.Capture. Its documented
`sky.press_key({key,window})` accepts a chord and targets/activates a window, but
does not expose a hold duration or independent key-down/up in that API. A brief
press may span too few Unity frames for Walk/Run acceptance. No CUA session or
window was controlled during this inspection.

## Verification

`verify_locomotion.py` contains pure analysis functions plus a file-based CLI.
`test_verify_locomotion.py` supplies synthetic tests only; test fixtures must not
be described as runtime acceptance. The final runtime input paths and original
identity manifest are supplied by the root operator after the new build runs.

The analysis reports movement, state playback, bone movement, save readback and
input-origin scope separately. It preserves known asset/shader degradation;
this stage makes no claim of original gameplay, shader or complete visual parity.

The config contains `phase1` and `phase2` objects, each naming `proof`, `events`,
`start` and `exit` files. It also names `save`, `seed_manifest`,
`animator_identity` and optionally `input_receipt`, `save_backup`, per-phase
`player_log`/`screenshot`/`title_screenshot` overrides, and `runtime_sources`
(`path`/`sha256` entries). Relative paths resolve against the config file.

`save_bridge_sources` names `old` and `new` source paths. Their SHAs are recorded
and `save_bridge_code_changed` explicitly reports a changed implementation;
equal source SHAs are no longer a compatibility requirement. An optional
`save_fix_probe` names `result`, `start`, `exit`, `source`, `old_save` and
`failed_save` artifacts. It verifies the final-source Editor's actual legacy
`SaveStore.TryRead`/validation and canonical roundtrip regression results. That
evidence is scoped separately from a new player's scene/pose readback, and does
not claim an unrecorded per-field comparison of the legacy decoded state.

```powershell
python -B -X utf8 -m unittest discover -s reverse-engineering/reconstruction/locomotion-acceptance-tools -p 'test_*.py' -v
python -B -X utf8 reverse-engineering/reconstruction/locomotion-acceptance-tools/verify_locomotion.py --config NEW_CONFIG --output NEW_REPORT --inputs
python -B -X utf8 reverse-engineering/reconstruction/locomotion-acceptance-tools/verify_locomotion.py --config NEW_CONFIG --output NEW_REPORT --check --inputs
```

The original serialized controller/avatar path IDs and object hashes are known
from the independently decoded bundle inventory. Unity's public API does not
expose those serialized IDs/hashes. Runtime identity is linked using the exact
bundle SHA, prefab/relative hierarchy path, controller/avatar names, observed
same-reference equality and source/copy instance IDs, and matching playing-clip
instance IDs from that controller. The report states this identity basis
explicitly. It does not pretend the runtime directly measured a serialized PPtr.

## Formal result: 2026-10-31

The frozen artifacts in `../locomotion-runtime` pass this stage's independent
checks. [acceptance-inputs.json](acceptance-inputs.json) binds the inputs and
[acceptance.json](acceptance.json) records the reproducible result. The keyboard
process PID 92812 and new readback process PID 31928 both exited with code 0 and
used `Assembly-CSharp.dll` SHA256
`3585f1862c3fae750fb167b5c56c086b61ef56ac603327c63993cf118104cbfe`.

There are 1,518 focused operation samples (frames 17400–18917) and 17,194
unfocused pure-Idle waiting samples, which are explicitly excluded from keyboard
operation evidence. No unfocused positive input or residual movement was seen
in this formal round. The unchanged thresholds establish focused Idle159 frames
→ Walk10 → Jog124 → released-input Idle67, with the original blend state's clip
weights, advancing normalized time and changing local bones. Independent CC
sample accumulation gives 17.19688854 metres of horizontal travel.

F5 commands produced revisions 1 and 2; F6 produced revision 4. Revision 3 has
no keyboard command event and is labelled **unattributed**, without assuming a
UI or keyboard cause. Every save's source/canonical/disk bit dictionaries agree;
this formal round needed zero signed-zero normalizations. The retained `.bak`
independently verifies revision 3 immediately before revision 4. It does **not**
retain F5 revisions 1 or 2, so independent rehashing of those F5 file bytes is
reported false; their actual command, Transform and runtime readback events
remain available.

The new process read revision 4, SHA256
`c4aba839937c1c02300b565e11b510dc3931f1c8f68bbb85062382f928545c92`,
and applied its position and quaternion component-exactly before physics.
Inventory, selected customization and paint data match the original-data seed.
The SaveBridge code changed; actual final-source Editor tests read the old
minimum and failed-round JSON and passed 362 write/read cases, including 66
negative-zero cases and 67 normalized components. This Editor compatibility
evidence is separately scoped from the formal player's scene readback.

The user explicitly confirmed completing the physical-keyboard instructions.
The report records that human attestation alongside actual Unity key edges;
Unity did not measure a physical device identity. Both processes retain 1,228
missing-script warnings and six raw unsupported-shader messages each. Screenshots
pass independent PNG decoding and pixel gates; original shader/full visual or
gameplay parity remains unverified. The earlier PID 90236 F5 failure and its
exit code 20 remain diagnostic evidence, without retroactive attribution of a
specific lost zero-sign component.
