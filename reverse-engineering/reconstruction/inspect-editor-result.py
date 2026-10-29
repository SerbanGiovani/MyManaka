"""Publish only the toolchain outcome; keep raw license logs private in .cache."""
import argparse,hashlib,json
from pathlib import Path
HERE=Path(__file__).resolve().parent
def sha(p):return hashlib.sha256(Path(p).read_bytes()).hexdigest()
def read(p):return json.loads(Path(p).read_text(encoding='utf-8-sig'))
def main():
    parser=argparse.ArgumentParser();parser.add_argument('--run-name');args=parser.parse_args();run=args.run_name
    if run and (not all(c.islower() or c.isdigit() or c=='-' for c in run)):raise ValueError('simple run name required')
    start=read(HERE/'.cache'/((run+'-start.json') if run else 'editor-start.json'));log=Path(start['log']);raw=log.read_bytes();text=raw.decode('utf8',errors='replace');editor=Path(start['editor']);version=Path(start['project'])/'ProjectSettings/ProjectVersion.txt'
    result=dict(editor_path=str(editor),product='Tuanjie',product_version=start['product_version'],editor_sha256=hashlib.sha256(editor.read_bytes()).hexdigest(),original_game_engine_version='2022.3.62f2',smoke_pid=start['pid'],raw_log_sha256=hashlib.sha256(raw).hexdigest(),raw_log_bytes=len(raw),raw_log_retained_locally=str(log),license_message='No valid Unity Editor license found. Please activate your license.' if 'No valid Unity Editor license found.' in text else None,project_version_generated=version.exists(),status='blocked-editor-license' if 'No valid Unity Editor license found.' in text else 'inspect-log-before-concluding',compilation_verified=False,build_verified=False,original_asset_compatibility_verified=False,scope='Isolated project creation prerequisite only; no login, activation or license configuration changed.')
    if run:
        created=read(HERE/'.cache'/(run+'-exit.json'));built=read(HERE/'.cache'/(run+'-build-exit.json'));runtime=read(HERE/'.cache'/(run+'-runtime-exit.json'));proof=read(HERE/'.cache'/(run+'-runtime-proof.json'));build=read(HERE/'.cache'/(run+'-build')/'build-receipt.json')
        assert all(v['process_exited'] and v['exit_code']==0 for v in [created,built,runtime]);assert build['result']=='Succeeded' and build['errors']==0 and proof['passed'] and proof['frames']==5 and proof['scene']=='ToolchainSmoke'
        output=Path(runtime['executable']).parent
        player_library=next(p for p in [output/'UnityPlayer.dll',output/'TuanjiePlayer.dll'] if p.is_file())
        sources=sorted(HERE.glob('toolchain-smoke/Assets/**/*.cs'))+[HERE/n for n in ['check-editor.ps1','build-smoke.ps1','run-smoke.ps1','inspect-editor-result.py']]
        result.update(status='editor-build-and-player-smoke-verified',project_version_text=version.read_text(encoding='utf8'),compilation_verified=True,build_verified=True,player_startup_verified=True,build_receipt=build,runtime_proof=proof,process_receipts=dict(create=created,build=built,runtime=runtime),build_outputs=[dict(path=str(p),sha256=sha(p),bytes=p.stat().st_size) for p in [output/'ToolchainSmoke.exe',player_library,output/'ToolchainSmoke_Data/Managed/Assembly-CSharp.dll']],sources=[dict(path=str(p.relative_to(HERE)),sha256=sha(p)) for p in sources],scope='Isolated compiler, Windows64 Mono build and headless player startup. Original IL2CPP binding, assets/scenes and complete game reconstruction remain unverified.',previous_license_failure_log_sha256=sha(HERE/'.cache/editor-create.log'))
    (HERE/'editor-toolchain.json').write_text(json.dumps(result,ensure_ascii=False,indent=2)+'\n',encoding='utf8');print(json.dumps(dict(status=result['status'],project_generated=result['project_version_generated'])))
if __name__=='__main__':main()
