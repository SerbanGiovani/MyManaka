"""Build an immutable REA script from reviewed shared API and one probe body."""
import argparse
import hashlib
import json
from pathlib import Path

HERE=Path(__file__).resolve().parent


def main():
    p=argparse.ArgumentParser(description=__doc__)
    p.add_argument('--body',default='proof.js');p.add_argument('--name',default='proof-v1.js')
    p.add_argument('--folder',default='baseline')
    a=p.parse_args();baseline=json.loads((HERE/'baseline.json').read_text(encoding='utf8'))
    output=Path(baseline['output_root'])/a.folder
    output.mkdir(parents=True,exist_ok=True)
    dest=HERE/a.name
    assert not dest.exists(),'Preserve loaded script fingerprints; choose a new name'
    code=(HERE/'api.js').read_text(encoding='utf8')+'\n'+(HERE/a.body).read_text(encoding='utf8').replace('__OUTPUT_ROOT__',json.dumps(output.as_posix()))
    dest.write_text(code,encoding='utf8')
    print(json.dumps(dict(path=str(dest),sha256=hashlib.sha256(dest.read_bytes()).hexdigest(),output=str(output))))


if __name__=='__main__':main()
