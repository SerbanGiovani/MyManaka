# Independent interaction acceptance

This is a new, read-only analysis stage. It does not edit the old
`locomotion-acceptance-tools`, `minimal-acceptance`, or `save-bridge` reports and
does not upgrade any previous simulated-input history.

The frozen result accepts the finite goal using explicitly separate natural and
controlled processes. The natural process's strict single-process gate remains
failed: the user supplied no movement input during its action lock.
`acceptance.json` therefore retains `passed=false` and
`full_chain_accepted=false`, while `scoped_composite_acceptance.accepted=true`
describes the supported combination below. No threshold was lowered.

`verify_interaction.py` never launches Unity or an executable, sends a key,
changes an action, or invokes a completion callback. It consumes new JSONL
runtime events, independently extracted original target/controller/action
identity, and external process/input receipts. Only an explicit `--output`
writes a new report. `--check` compares the existing report without writing.

The selected target is the original `droppedhandcuffkey.prefab`, placed as an
explicit fixture in reconstructed Apartment. This does not establish that the
original Apartment contained this target at that location. Its finite pickup
interaction uses original action `10025`, None `-1`, the original controller's
Action state hash `886742834`, and original `PickUpItem` clip. The original
`OnAnimEndPickUpItem` event is at `1.983333349` seconds in the two-second clip;
the original callback changes the action to None immediately. The independent
manifest supplies the exact identities. A next-frame replacement completion
cannot be reported as the original zero-frame end mechanism.

The verifier checks the following chain from observations, independently of a
runtime `passed` flag:

1. Exact original bundle/prefab identity, original controller/avatar reference
   equality, and the playing original controller clip's instance identity.
2. Original target/component/trigger geometry, actual player-CC
   `OnTriggerEnter`, a current overlapping candidate, and selected target.
3. Actual focused Unity `GetKeyDown(F)`, its held/release observations, one
   attempt per down edge, guard result, and PlayerAction start. Held F cannot
   generate repeated down edges; rejected busy attempts cannot restart action.
4. Original Action layer/state/clip at sufficient weight, advancing normalized
   time and changing local bones across consecutive frames.
5. At least three movement-input samples while CanMove is false. Both target
   speeds must be zero. Original smoothing may retain inertia: world/animation
   speeds must decay at the original rates, CC displacement must fit actual
   speed and delta time, and movement cannot continue after inertia is zero.
6. Actual Unity-dispatched original end AnimationEvent from the same original
   clip and Action state, at the original event time, then None with the exact
   original frame delay. A timeout, synthetic completion or manual replacement
   callback is rejected.
7. After natural None, at least three consecutive focused input-to-CC movement
   samples, with original locomotion playback. A restored enum/boolean alone
   does not prove movement resumed.
8. The selected pickup's original callback hides that target and adds exactly
   one item `10000`. Target collection and inventory before/delta/after must
   occur after the original event and before None in the same frame. This does
   not establish automatic key use or the complete original inventory system.

Every operation sample must be present in consecutive frame order. Unfocused
pure-idle frames are excluded and explicitly listed. Unfocused positive input
and unfocused residual movement are rejected. There must be no unexpected
engine error; the known original shader degradation remains disclosed.

Input origin is separate from Unity reception. Automated controlled input,
OS-injected keyboard input, undeclared origin, and explicit user physical-keyboard
attestation receive different classifications. Unity does not measure a
physical keyboard device identity. An OS injection receipt cannot become human
attestation, and absence of injection logs cannot establish hardware origin.

## Commands

```powershell
python -B -X utf8 -m unittest discover -s reverse-engineering/reconstruction/interaction-acceptance-tools -p 'test_*.py' -v
python -B -X utf8 reverse-engineering/reconstruction/interaction-acceptance-tools/verify_interaction.py --config reverse-engineering/reconstruction/interaction-acceptance-tools/acceptance-inputs.json --output reverse-engineering/reconstruction/interaction-acceptance-tools/acceptance.json --scoped-composite --check --inputs
python -B -X utf8 reverse-engineering/reconstruction/interaction-acceptance-tools/verify_interaction.py --config reverse-engineering/reconstruction/interaction-acceptance-tools/controlled-inputs.json --output reverse-engineering/reconstruction/interaction-acceptance-tools/controlled-diagnostic.json --controlled --check --inputs
python -B -X utf8 reverse-engineering/reconstruction/interaction-acceptance-tools/verify_interaction.py --config reverse-engineering/reconstruction/interaction-acceptance-tools/acceptance-inputs.json --output reverse-engineering/reconstruction/interaction-acceptance-tools/strict-natural-rejection.json --strict-rejection --check --inputs
```

The config names `events`, `identity`, `start`, `exit`, `proof`, optional
`input_receipt`, and optional `runtime_sources` (`path`/`sha256` entries).
Relative paths resolve against the config. Runtime and original identity
artifacts are SHA256-bound in the result. `--inputs` additionally rehashes the
actual launched executable and managed `Assembly-CSharp.dll` from the external
start receipt.

The composite config additionally names `controlled_config`, `save`,
`save_backup`, `cold_events`, `cold_start`, `cold_exit`, and `cold_proof`.
Every config artifact path points to the frozen `interaction-runtime` archive
or independent `interaction-evidence`; the source hashes bind all ten archived
`build/Assets` C# files. Configs contain no cache input path. Historical start
receipts preserve the actual launched executable/assembly locations, which
`--inputs` rehashes. Remove `--check` only to regenerate a report intentionally.

The original identity manifest has `acceptance_identity` (the prior original
player/controller/avatar binding) and `interaction` with `id`, `noneId`,
`target`, `layer`, `end`, and `locomotion`. It also discloses
`limitations` and original guard scope. Runtime event contract follows the existing
`{kind,processGuid,frame,real,utc,data}` JSONL envelope. The analyzer's field
checks and test fixture document its exact accepted schema.

## Test scope and runtime status

The 86 current tests are synthetic analyzer fixtures and adversarial mutations.
They cover fake targets, missing/stale/manual triggers, wrong colliders,
simulated or unfocused input, missing F edges/releases, held/repeated F,
incorrect guards, timeout/manual/missing/wrong clip end events, wrong layers,
clip references and frame delays, early unlock/movement, legitimate decaying
inertia, missing frames, static skeleton/time, absent movement recovery, and
input-origin inflation, compressed archive binding, stale runtime source/binary,
old-process receipt/proof rejection, original pickup visibility/item/count/order,
unrelated-key/old-interval OS attribution rejection, IEEE32 geometry equivalence,
changed raw identity evidence, and original Animator parameter writes/values.
Additional cases prevent combining different assemblies/identity contracts,
excusing another failed natural gate, inflating controlled input, changing a
saved pickup quantity/pose, or claiming an unobserved cold inventory count.
The selected original crouch guard is checked separately. Its native handcuff
check is explicitly skipped for this pickup; other native subsystems are
restricted to the independently documented neutral-state scope.

The separately labelled `controlled-diagnostic.json` analyzes the actual new
controlled process PID 94672. It verifies original Action playback on frames
221–324, original callback and immediate None on frame 325, and CC recovery on
326–332. It retains simulated F/axes and unfocused operation, excludes the two
explicit setup teleports, and reports `full_chain_accepted=false`,
`actual_unity_f_accepted=false`, and no physical attestation. The same unchanged
evidence is rejected by formal mode. Its target pickup added item `10000` from
1 to 2 and hid the fixture; 1,232 missing-script warnings and 12 shader fallbacks
remain disclosed.

## Frozen scoped result: 2026-10-31

Natural process PID 94856 records actual Unity F on frame 2427, stable original
Action playback on 2442–2545, and the original AnimationEvent plus immediate
None on 2546. Its first nonzero Unity movement axis is frame 2599, 53 frames
after None. Consecutive actual-input CC recovery spans 2599–3009 and travels
7.3278203479 metres. Subsequent F attempts at 2974 and 2990 are correctly
rejected with `no-target`. The user explicitly replied “完成”; this is human
physical-keyboard attestation paired with Unity reception, not device identity
measured by Unity. The 2,103 unfocused pure-idle frames 208–2310 are excluded.

The natural lock contains **zero** nonzero-axis samples. Its strict rejection
is reproducible in `strict-natural-rejection.json`. The separate controlled
process PID 94672 supplies 119 movement-input samples during the CanMove lock,
including held/repeated F behavior and busy/no-target rejection. Both processes
use managed assembly SHA256
`1de70877fd056e883b0e54b62452bfbbba3c14d5bb96bc793c54fd1a0727efe6`
and the same independent original identity contract. The composite result does
not merge their input origins or turn either process into a complete physical
single-process test.

F5 on 3117 saves revision 1; F6 on 3189 saves revision 2 and exits. Both bit-map
roundtrips preserve every component and need zero signed-zero normalizations.
The retained backup independently matches revision 1. The final JSON has item
`10000` quantity 2 and SHA256
`f466eb7f14275ab12bef4821ec67d6f2389a8347ee45d5cf59ec7c4763baff20`.
Cold process PID 97848 verifies reading those exact bytes and applies the
component-exact saved pose before physics. Its trace emits no second in-memory
inventory count; only the independent persisted count and identical read bytes
are claimed.

The root operator owned every Editor, executable and keyboard operation. All
three processes exited with code 0. Each retains 1,232 missing-script warnings
and 12 player shader fallbacks; full shader/visual parity remains unverified.
The key is deliberately reconstructed once per process as an Apartment fixture,
not an original Apartment placement or natural respawn. The selected standing,
neutral-state pickup is bounded; simultaneous C+F scheduling and additional
native gameplay systems are outside this acceptance.
