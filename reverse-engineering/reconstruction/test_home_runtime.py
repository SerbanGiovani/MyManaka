"""Synthetic analyzer counterexamples, never game or keyboard evidence."""
import copy
import runpy
import unittest
from pathlib import Path

ANALYZE = runpy.run_path(str(Path(__file__).with_name('verify-home-runtime.py')))['analyze_menus']


def fixture():
    targets = [dict(id=kind, kind=kind, sourcePathId=index) for index, kind in enumerate(['pc', 'bed', 'closet'], 1)]
    rows = []
    def emit(event_kind, frame, **data):
        rows.append(dict(kind=event_kind, frame=frame, data=data))
    for serial, kind in enumerate(['pc', 'closet', 'closet', 'pc'], 1):
        frame = serial * 10
        source = next(target for target in targets if target['kind'] == kind)
        emit('interaction_trigger', frame, targetId=kind, phase='enter', via='OnTriggerEnter', actualOverlap=True, otherIsPlayerController=True)
        emit('home_menu_opened', frame+1, kind=kind, serial=serial, inputEnabledBefore=True, inputEnabledAfter=False)
        emit('home_interaction_dispatched', frame+1, targetId=kind, kind=kind, sourcePathId=source['sourcePathId'], simulated=True, menuOpened=True)
        emit('interaction_attempt', frame+1, selectedTargetId=kind, accepted=True, fDown=True, simulated=True)
        emit('home_lock_sample', frame+2, kind=kind, sequence=serial, axes={'x':1,'y':0}, positionBefore={'x':0,'y':0,'z':0}, positionAfter={'x':0,'y':0,'z':0}, inputEnabled=False, controllerMoveCalled=False)
        if kind == 'pc':
            emit('home_menu_operation_started', frame+3, kind=kind, operation='save', serial=serial)
            emit('save_completed', frame+3)
            emit('home_menu_operation_completed', frame+3, kind=kind, operation='save', serial=serial, success=True)
        emit('home_menu_closed', frame+4, kind=kind, serial=serial, inputEnabledAfter=True)
        emit('home_movement_restored', frame+5, kind=kind, sequence=serial, axes={'x':1,'y':0}, positionBefore={'x':0,'y':0,'z':0}, positionAfter={'x':.01,'y':0,'z':0}, inputEnabled=True, controllerMoveCalled=True)
    return rows, targets


class MenuTraceChecks(unittest.TestCase):
    def setUp(self):
        self.rows, self.targets = fixture()

    def row(self, kind):
        return next(row for row in self.rows if row['kind'] == kind)

    def rejects(self):
        with self.assertRaises(ValueError):
            ANALYZE(self.rows, self.targets)

    def test_valid_synthetic_trace(self):
        self.assertEqual(ANALYZE(self.rows, self.targets)['pc_menu_saves'], 2)

    def test_callback_injection_is_rejected(self):
        self.row('interaction_trigger')['data']['via'] = 'test-injection'
        self.rejects()

    def test_wrong_source_node_is_rejected(self):
        self.row('home_interaction_dispatched')['data']['sourcePathId'] = 999
        self.rejects()

    def test_without_f_edge_is_rejected(self):
        self.row('interaction_attempt')['data']['fDown'] = False
        self.rejects()

    def test_unmeasured_lock_input_is_rejected(self):
        self.row('home_lock_sample')['data']['axes'] = {'x':0,'y':0}
        self.rejects()

    def test_movement_inside_menu_is_rejected(self):
        self.row('home_lock_sample')['data']['positionAfter']['x'] = .1
        self.rejects()

    def test_controller_called_inside_menu_is_rejected(self):
        self.row('home_lock_sample')['data']['controllerMoveCalled'] = True
        self.rejects()

    def test_unrestored_input_is_rejected(self):
        self.row('home_menu_closed')['data']['inputEnabledAfter'] = False
        self.rejects()

    def test_no_real_recovery_motion_is_rejected(self):
        self.row('home_movement_restored')['data']['positionAfter']['x'] = 0
        self.rejects()

    def test_unmatched_close_is_rejected(self):
        row = copy.deepcopy(self.row('home_menu_closed'))
        row['data']['serial'] = 999
        self.rows.append(row)
        self.rejects()

    def test_pc_operation_without_save_consumer_is_rejected(self):
        self.rows.remove(self.row('save_completed'))
        self.rejects()


if __name__ == '__main__':
    unittest.main()
