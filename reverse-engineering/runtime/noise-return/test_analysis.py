import copy
from pathlib import Path
import runpy
import unittest

m = runpy.run_path(str(Path(__file__).with_name('analyze.py')))


def fixture():
    at = dict(value=1., count=120, threshold=.6, playerFound=1)
    base = dict(call=4, thread=9, nca='0x123', id=2, entryCaller='0x428bf3')
    def row(kind, order, **kw):
        return dict(kind=kind, order=order, script='s', frame=10, data=copy.deepcopy({**base, **kw}))
    after = {**at, 'count': 119}
    return [row('return_entry', 2, at=at), row('return_decay', 3, before=at, after=after),
            row('return_onleave', 4, at=after), row('return_continuation', 5, at=after, onLeaveSeen=True)]


class ReturnValidation(unittest.TestCase):
    def test_valid_independent_continuation(self):
        self.assertTrue(m['validate_call'](fixture())['valid'])

    def test_missing_leave_cannot_be_proved_by_continuation(self):
        self.assertFalse(m['validate_call']([p for p in fixture() if p['kind'] != 'return_onleave'])['valid'])

    def test_duplicate_continuation(self):
        rows = fixture(); rows.append(copy.deepcopy(rows[-1]))
        self.assertFalse(m['validate_call'](rows)['valid'])

    def test_identity_mismatch(self):
        for key in ['thread', 'nca', 'id', 'entryCaller']:
            rows = fixture(); rows[-1]['data'][key] = 'wrong'
            self.assertFalse(m['validate_call'](rows)['valid'], key)

    def test_order_inversion(self):
        rows = fixture(); rows[-1]['order'] = 1
        self.assertFalse(m['validate_call'](rows)['valid'])

    def test_different_readback(self):
        rows = copy.deepcopy(fixture()); rows[-1]['data']['at']['value'] = .2
        self.assertFalse(m['validate_call'](rows)['valid'])

    def test_decay_after_return(self):
        rows = fixture(); rows[1]['order'] = 6
        self.assertFalse(m['validate_call'](rows)['valid'])

    def test_missing_or_duplicate_decay_is_not_complete(self):
        rows = fixture()
        self.assertFalse(m['validate_call']([p for p in rows if p['kind'] != 'return_decay'])['valid'])
        rows.append(copy.deepcopy(rows[1]))
        self.assertFalse(m['validate_call'](rows)['valid'])

    def test_same_call_different_scripts_never_joined(self):
        rows = fixture(); rows[-1]['script'] = 'other'
        result = m['summarize_calls'](rows)
        self.assertEqual(result['valid_calls'], 0)

    def test_event_before_continuation_excluded(self):
        row = m['validate_call'](fixture())
        self.assertEqual(m['summarize_pre_event']([row], 's', 2, 5)['calls'], 0)
        self.assertEqual(m['summarize_pre_event']([row], 's', 2, 6)['calls'], 1)

    def test_count_reset_inside_original_body(self):
        rows = fixture()
        rows[-2]['data']['at']['count'] = 120
        rows[-1]['data']['at']['count'] = 120
        row = m['validate_call'](rows)
        self.assertTrue(row['valid'])
        result = m['summarize_pre_event']([row], 's', 2, 6)
        self.assertEqual(result['within_call_count_increases'], 1)
        self.assertEqual(result['interval_count_increases'], 0)


if __name__ == '__main__':
    unittest.main()
