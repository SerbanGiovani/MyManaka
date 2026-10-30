"""Bounded trace counterexamples; no Editor, game, or reconstructed player executes."""
import copy,json,math,tempfile,unittest
from pathlib import Path
from unittest.mock import patch
from PIL import Image
import verify_roundtrip as v

def fixture():
    seed=dict(sceneKey='Apartment',position=dict(x=0.,y=0.,z=0.),rotation=dict(x=0.,y=0.,z=0.,w=1.),sourceSaveSha256='a'*64,bodyPaintRemaining=118.5,bodyPaintReusable=True,inventory=[dict(id=5,count=0),dict(id=8,count=1)],customization=dict(hair=0))
    saved=dict(seed,schemaVersion=1,fileKind='ReconstructedManakaSave',position=dict(x=1.,y=0.,z=0.),savedProcessGuid='1'*32,revision=1)
    def proof(phase,guid,pid):
        return dict(phase=phase,completed=True,passed=True,processGuid=guid,processId=pid,startedUtc='2026-10-30T18:00:00Z',finishedUtc='2026-10-30T18:00:10Z',sceneKey='Apartment',originalGeometry=True,originalPlayerVisual=True,geometryMeshes=269,geometryColliders=33,visualRenderers=4,copiedGameBehaviours=0,engineErrorCount=0,engineWarningCount=0,knownCompatibilityErrors=0,unexpectedEngineErrors=0,missingScriptWarnings=0,playerShaderFallbacks=11,unresolvedBuiltinMeshes=5,geometryTextures=90,declaredTextures=90,degradedAssetCompatibility=True,originalShaderCompatibilityVerified=False,controlledInput=True,inputSamples=20,travelledDistance=1.,groundedSeen=True,belowCollisions=20,loadedPosition=seed['position'],loadedRotation=seed['rotation'],appliedPosition=seed['position'],appliedRotation=seed['rotation'],savedPosition=saved['position'],savedRotation=saved['rotation'],exactStoredPosition=True,exactStoredRotation=True,exactAppliedPosition=True,exactAppliedRotation=True,rotationErrorDegrees=0.,saveRevision=1,loadedSavedProcessGuid='')
    first=proof('phase1','1'*32,10);second=proof('phase2','2'*32,20)
    second.update(startedUtc='2026-10-30T18:00:20Z',finishedUtc='2026-10-30T18:00:30Z',loadedSavedProcessGuid=first['processGuid'],loadedPosition=saved['position'],appliedPosition=saved['position'])
    def row(proof,kind,data):return dict(processGuid=proof['processGuid'],kind=kind,data=data)
    def ends(proof):return [row(proof,'acceptance_complete',dict(passed=True)),row(proof,'process_quit',dict(passed=True))]
    a=[row(first,'seed_imported',dict(seed,revision=0)),row(first,'movement_observed',dict(start=seed['position'],end=saved['position'])),row(first,'save_completed',dict(saved))]+ends(first)
    b=[row(second,'saved_state_read',dict(saved)),row(second,'readback_verified_before_physics',dict(previousProcess=True,writerProcessGuid=first['processGuid'],readerProcessGuid=second['processGuid']))]+ends(second)
    return seed,first,second,saved,a,b

class RoundtripTests(unittest.TestCase):
    def bad(self,mutate):
        args=copy.deepcopy(fixture());mutate(args)
        with self.assertRaises(ValueError):v.analyze(*args)
    def test_valid_bounded_trace(self):
        result=v.analyze(*fixture());self.assertTrue(result['paint_data_preserved']);self.assertFalse(result['hardware_keyboard_tested']);self.assertTrue(result['resource_scene_fidelity_unverified'])
    def test_actual_archived_visible_process_roundtrip(self):
        without=v.build(inputs=False);with_inputs=v.build(inputs=True);self.assertEqual(without,with_inputs);self.assertEqual(without,v.read(v.HERE/'acceptance.json'));self.assertTrue(without['position_applied_bit_exact']);self.assertTrue(without['rotation_applied_bit_exact']);self.assertEqual(len(without['screenshots']),4);self.assertTrue(all(x['raw_shader_error_lines']==6 for x in without['player_logs']))
    def test_same_process_is_not_a_restart(self):self.bad(lambda x:x[2].update(processGuid=x[1]['processGuid']))
    def test_overlapping_lifetimes_rejected(self):self.bad(lambda x:x[2].update(startedUtc=x[1]['startedUtc']))
    def test_missing_engine_error_does_not_pass_by_counter(self):self.bad(lambda x:x[4].append(dict(kind='engine_error',processGuid=x[1]['processGuid'],data=dict(message='unexpected',classification='unexpected'))))
    def test_known_label_cannot_hide_arbitrary_error(self):
        def change(x):
            x[1].update(engineErrorCount=1,knownCompatibilityErrors=1);x[4].append(dict(kind='engine_error',processGuid=x[1]['processGuid'],data=dict(message='unexpected',classification='known-original-shader-constant-buffer')))
        self.bad(change)
    def test_exact_known_shader_warning_remains_degraded(self):
        x=list(fixture());x[1].update(engineErrorCount=1,knownCompatibilityErrors=1);x[4].append(dict(kind='engine_error',processGuid=x[1]['processGuid'],data=dict(message="Struct '_MainTex' is not in any constant buffer.",classification='known-original-shader-constant-buffer')));self.assertEqual(v.analyze(*x)['compatibility'][0]['callback_errors'],1)
    def test_cannot_conceal_fallbacks(self):self.bad(lambda x:x[1].update(degradedAssetCompatibility=False))
    def test_source_import_cannot_be_replaced_with_spawn_default(self):self.bad(lambda x:x[1].update(appliedPosition=dict(x=0,y=1,z=0)))
    def test_actual_net_movement_required(self):
        def change(x):x[4][1]['data']['start']=dict(x[3]['position'])
        self.bad(change)
    def test_persisted_pose_must_equal_movement_return(self):self.bad(lambda x:x[4][1]['data'].update(end=dict(x=5,y=0,z=0)))
    def test_actual_quaternion_checked_even_with_zero_claim(self):self.bad(lambda x:x[2].update(appliedRotation=dict(x=0,y=math.sqrt(.5),z=0,w=math.sqrt(.5)),rotationErrorDegrees=0))
    def test_quaternion_sign_equivalence_is_not_bit_identity(self):
        self.assertEqual(v.quaternion_error(dict(x=0,y=0,z=0,w=1),dict(x=0,y=0,z=0,w=-1)),0)
    def test_zero_inventory_key_is_preserved(self):self.bad(lambda x:x[3].update(inventory=[dict(id=8,count=1)]))
    def test_reusable_paint_flag_preserved(self):self.bad(lambda x:x[3].update(bodyPaintReusable=False))
    def test_duplicate_seed_event_is_rejected(self):self.bad(lambda x:x[4].append(copy.deepcopy(x[4][0])))
    def test_cross_session_event_rejected(self):self.bad(lambda x:x[5][0].update(processGuid=x[1]['processGuid']))
    def test_hash_summary_matches_selected_fields_without_plain_seed(self):
        x=list(fixture());seed=copy.deepcopy(x[0]);seed['inventory_sha256']=v.value_sha(seed.pop('inventory'));seed['customization_sha256']=v.value_sha(seed.pop('customization'));x[0]=seed;self.assertTrue(v.analyze(*x)['selected_custom_preserved'])
    def test_nonfinite_pose_rejected(self):self.bad(lambda x:x[2].update(appliedRotation=dict(x=0,y=0,z=0,w=float('nan'))))
    def test_black_png_independently_rejected(self):
        with tempfile.TemporaryDirectory() as t:
            path=Path(t)/'black.png';Image.new('RGB',(100,100)).save(path);proof=dict(screenshotValidated=True,screenshotSha256=v.sha(path));rows=[dict(kind='screenshot_validation',data=dict(sha256=v.sha(path))) ]
            with self.assertRaises(ValueError):v.screenshot(path,proof,rows)
    def test_archived_inputs_false_never_reads_original_cipher_seed_or_exe(self):
        with tempfile.TemporaryDirectory() as t:
            root=Path(t);seed,first,second,saved,a,b=fixture();save=root/'save.v1.json';save.write_text(json.dumps(saved));save_sha=v.sha(save)
            manifest=root/'seed-manifest.json';summary={k:val for k,val in seed.items() if k not in ['inventory','customization']};summary.update(inventory_sha256=v.value_sha(seed['inventory']),customization_sha256=v.value_sha(seed['customization']));manifest.write_text(json.dumps(dict(selected_summary=summary,source=dict(source_path='absent-cipher.sd'),seed=dict(path='absent-seed.json'),sources=[])))
            paths=[]
            for phase,proof,rows in [('phase1',first,a),('phase2',second,b)]:
                directory=root/phase;directory.mkdir();proof.update(savePath=str(save),saveSha256=save_sha,profileRoot=str(root),eventPath=str(directory/'events.jsonl'))
                for title in [True,False]:
                    path=directory/('title.png' if title else 'room.png');image=Image.new('RGB',(100,100),(10,20,31 if title else 30));image.putpixel((99,99),(40,50,60));image.paste((40,50,60),(0,0,25,25));image.save(path)
                    key='titleScreenshot' if title else 'screenshot';proof.update({key+'Path':str(path),key+'Sha256':v.sha(path),key+'Validated':True})
                    rows.append(dict(kind='screenshot_validation',processGuid=proof['processGuid'],data=dict(sha256=v.sha(path),width=100,height=100,pixels=10000,nonBlackPixels=10000,differentFromFirstPixel=626,validated=True,cameraActive=True,cameraEnabled=True,afterReadyFrames=2,bytes=path.stat().st_size)))
                (directory/'events.jsonl').write_text(''.join(json.dumps(r)+'\n' for r in rows));(directory/'proof.json').write_text(json.dumps(proof));(directory/'process-start.json').write_text(json.dumps(dict(phase=phase,arguments=[],profile_root=str(root),pid=proof['processId'],executable='absent.exe',executable_sha256='b'*64)));(directory/'process-exit.json').write_text(json.dumps(dict(process_exited=True,exit_code=0,pid=proof['processId'])));(directory/'player.log').write_text('ERROR: Shader unsupported fixture\n');paths.append(directory/'proof.json')
            with patch.object(v,'project',side_effect=AssertionError('Original input read in no-input mode')):
                result=v.build(*paths,save,manifest,inputs=False)
            self.assertEqual(result['player_logs'][0]['raw_shader_error_lines'],1);self.assertEqual(len(result['screenshots']),4)

if __name__=='__main__':unittest.main()
