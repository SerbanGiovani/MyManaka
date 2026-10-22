"""Bind the full-bootstrap checkpoint's new static queries; no execution claims."""
import argparse
import json
from scene_evidence import build as bind
from metadata import HERE


def build():
    result = bind(batch_prefix='natural-',
        reuse_method_ids={14421,14462,14536,14479,15536,15350,15358,17304,17309,17231,17232,17233,17236},
        extra_type_names=('RingMenuParentView','RingMenuView','RingMenuItemModel','RingItemView',
                          'InputResolver','InputManager','InputType','GameStateData','SkillItemView',
                          'SaveRapper','ES3Settings','NpcController','TemporaryInGameState','InGameUiManager','SexManager',
                          'BaseCameraController','TimeScaleManager','TimeScaleMode','DelayTimeModel','SkillType'),
        dispatch_targets=[],resource_boundary='Static ring/input/save-path evidence; runtime coverage is separately bounded in natural-time-stop/manifest.json.')
    assert result['new_observations'] == 24
    result['scope'] = 'Full-bootstrap observations and static input/menu/skill boundaries. Natural runtime coverage is measured separately, never inferred from absent messages.'
    result['confirmed_ring_paths'] = {
        'open': [18146,18149],
        'selection_assignment_only': [18181,18182],
        'direct_execute': [18202,14421,14462,14536,14479],
        'selection_camera_input': 18203,
        'short_press_execute': 18146,
        'limits': ['18181/18182 update selected shortcut models/indices; their occurrence alone does not prove command execution.',
                   'ShowUpdate uses InputType15, a released item and the current page before setting RingShortcutInput or invoking OnSelect.',
                   'Original OnChangeTimeStop toggles before broadcast; NPC cache risk still requires repeated true notifications or another corrupting path.']}
    result['distinct_gates'] = {
        'ring_camera_lock': 'InGameManager.InGameReferencer(+0x28).BaseCameraController(+0x38).IsLockCamera(+0x28)',
        'ordinary_pause': 'TimeScaleManager.OnUpdate checks OpenPause/OpenTutorial and writes timeScale/fixedDeltaTime; no TimeStopEvent inferred.',
        'skill_active': 'IsActivePassiveSkill requires GetSkillLevel>=1, then reads PlayerPassiveSkillActiveDict.',
        'native_477d40': 'Reads InputManager.IsGamePad; not a time-scale setter.',
        'limits': 'No direct time-scale write in the selected ring method does not exclude all indirect callers.'}
    return result


if __name__ == '__main__':
    p=argparse.ArgumentParser(description=__doc__);p.add_argument('--check',action='store_true');args=p.parse_args()
    path=HERE/'evidence/natural-chain.json';result=build()
    if args.check:
        assert json.loads(path.read_text(encoding='utf8')) == result
    else:
        path.write_text(json.dumps(result,ensure_ascii=False,indent=2)+'\n',encoding='utf8')
    print(json.dumps({'new_observations':result['new_observations'],'methods':len(result['methods'])}))
