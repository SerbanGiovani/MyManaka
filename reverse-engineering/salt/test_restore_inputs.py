"""Synthetic structural guard examples; no native/runtime execution."""
import unittest
from save_codec import SaveTextReader
from restore_inputs import summarize


def fixture():
    return SaveTextReader('''{
      "CurrentStageType":1,"PlayerPosition":{"x":0,"y":1,"z":2},
      "PlayerRotation":{"x":0,"y":0,"z":0,"w":1},
      "NpcSaveDataList":[],"ReserveDropList":[],"DropDataDict":{},
      "LoadoutDatas":[],"LoadoutCustomizeDatas":[]
    }''').parse()


class RestoreInputTests(unittest.TestCase):
    def test_three_drop_branches_and_numeric_identity(self):
        state=fixture();s=state.strings()
        for key,stage,dropped in [(1,1,True),(2,2,True),(3,1,False)]:
            row=SaveTextReader('{"IsDropped":false,"IsReserve":false,"IsViewCompassInDroneMission":false,"Position":{"x":0,"y":0,"z":0},"Rotation":{"x":0,"y":0,"z":0,"w":0},"StageType":0,"ItemType":0}').parse()
            row.entries=[(k,{'StageType':stage,'ItemType':key,'IsDropped':dropped}.get(k,v)) for k,v in row.entries]
            s['DropDataDict'].entries.append((key,row))
        q=summarize(state)['drop_activation_guards']
        self.assertEqual(q,dict(records=3,not_dropped_untouched=1,current_stage_drop_calls=1,other_stage_hide_calls=1))
        s['DropDataDict'].entries[0]=(99,s['DropDataDict'].entries[0][1])
        with self.assertRaises(AssertionError):summarize(state)

    def test_nonempty_npc_retains_unresolved_elevator_filter(self):
        state=fixture();s=state.strings()
        s['NpcSaveDataList'].append(SaveTextReader('{"Position":{"x":0,"y":0,"z":0},"Rotation":{"x":0,"y":0,"z":0,"w":1},"IsExist":true}').parse())
        q=summarize(state)
        self.assertEqual(q['npc_existing_before_elevator_filter'],1)
        self.assertTrue(q['npc_elevator_filter_not_evaluated'])

    def test_pose_shape_and_overflow_are_rejected(self):
        state=fixture();s=state.strings()
        s['PlayerPosition'].entries[0]=('x',1e300)
        with self.assertRaises(OverflowError):summarize(state)
        s['PlayerPosition'].entries.pop()
        with self.assertRaises(AssertionError):summarize(state)


if __name__=='__main__':unittest.main()
