"""Publish only the toolchain outcome; keep raw license logs private in .cache."""
import hashlib,json
from pathlib import Path
HERE=Path(__file__).resolve().parent
def main():
    start=json.loads((HERE/'.cache/editor-start.json').read_text(encoding='utf-8-sig'));log=Path(start['log']);raw=log.read_bytes();text=raw.decode('utf8',errors='replace');editor=Path(start['editor']);version=Path(start['project'])/'ProjectSettings/ProjectVersion.txt'
    result=dict(editor_path=str(editor),product='Tuanjie',product_version=start['product_version'],editor_sha256=hashlib.sha256(editor.read_bytes()).hexdigest(),original_game_engine_version='2022.3.62f2',smoke_pid=start['pid'],raw_log_sha256=hashlib.sha256(raw).hexdigest(),raw_log_bytes=len(raw),raw_log_retained_locally=str(log),license_message='No valid Unity Editor license found. Please activate your license.' if 'No valid Unity Editor license found.' in text else None,project_version_generated=version.exists(),status='blocked-editor-license' if 'No valid Unity Editor license found.' in text else 'inspect-log-before-concluding',compilation_verified=False,build_verified=False,original_asset_compatibility_verified=False,scope='Isolated project creation prerequisite only; no login, activation or license configuration changed.')
    (HERE/'editor-toolchain.json').write_text(json.dumps(result,ensure_ascii=False,indent=2)+'\n',encoding='utf8');print(json.dumps(dict(status=result['status'],project_generated=result['project_version_generated'])))
if __name__=='__main__':main()
