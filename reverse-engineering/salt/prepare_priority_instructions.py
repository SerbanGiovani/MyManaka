"""Bound the ambiguous NPC fixed-update distance guard to original bytes."""
import hashlib
import json
import sqlite3
from pathlib import Path

from metadata import HERE, DEFAULT_ROOT, PE


def main():
    path = DEFAULT_ROOT / 'GameAssembly.dll'
    native = path.read_bytes()
    identity = json.loads((HERE / 'evidence/artifact-identity.json').read_text(encoding='utf8'))
    assert hashlib.sha256(native).hexdigest() == identity['native_sha256']
    c = sqlite3.connect((HERE / '.cache/methods.sqlite').as_uri() + '?mode=ro', uri=True)
    assert c.execute('SELECT va FROM methods WHERE id=15557').fetchone()[0] == '0x18042e660'
    pe = PE(native)
    begin, end = 0x18042e660, 0x18042e740
    decoder = DEFAULT_ROOT / 'BepInEx/core/Iced.dll'
    result = dict(native=dict(path=str(path), sha256=identity['native_sha256']),
        decoder=dict(path=str(decoder), sha256=hashlib.sha256(decoder.read_bytes()).hexdigest()),
        preparer=dict(path=str(Path(__file__).resolve()), sha256=hashlib.sha256(Path(__file__).read_bytes()).hexdigest()),
        ranges=[dict(method_id=15557, requested_va=hex(begin), begin=hex(begin), end_exclusive=hex(end),
            file_offset=pe.offset(begin, end-begin, executable=True), size=end-begin,
            pdata_file_offset=None, pdata_raw_hex=None, unwind_chain=[])])
    (HERE / '.cache/priority-decoder-input.json').write_text(json.dumps(result, indent=2)+'\n', encoding='utf8')
    print('Prepared explicit entry-to-0x42e740 guard window; not complete method bounds')


if __name__ == '__main__':
    main()
