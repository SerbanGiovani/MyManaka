"""Compile own managed code into a fresh copy of the archived player host.

This is not a Unity Editor build. No Editor licensing code or original game
binary is patched. Native assets/player bytes retain the prior build identity.
"""
import argparse
import hashlib
import json
import shutil
import subprocess
from pathlib import Path

HERE = Path(__file__).resolve().parent


def sha(path):
    with path.open('rb') as stream:
        return hashlib.file_digest(stream, 'sha256').hexdigest()


def pin(path):
    return dict(path=str(path.resolve()), bytes=path.stat().st_size, sha256=sha(path))


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--name', default='formal-home-host-20261103-1')
    args = parser.parse_args()
    if not args.name.startswith('formal-home-host-') or any(c not in 'abcdefghijklmnopqrstuvwxyz0123456789-' for c in args.name):
        raise ValueError('Use a fresh simple formal-home-host- name')
    cache = HERE / '.cache'
    base = cache / 'formal-20261103-1-build'
    package = cache / (args.name + '-build')
    record = cache / (args.name + '-record')
    if package.exists() or record.exists():
        raise ValueError('Preserve earlier host attempts; choose a fresh name')
    baseline = json.loads((HERE / 'formal-project-runtime.json').read_text('utf-8-sig'))
    expected = {Path(row['path']).relative_to(base).as_posix(): row for row in baseline['build']['files']}
    for relative, row in expected.items():
        if (base / relative).stat().st_size != row['bytes'] or sha(base / relative) != row['sha256']:
            raise ValueError('Archived baseline host differs: ' + relative)
    dotnet = Path(shutil.which('dotnet'))
    sdk_output = subprocess.check_output([str(dotnet), '--list-sdks'], text=True).splitlines()
    candidates = [Path(line.split('[', 1)[1].rstrip(']')) / line.split()[0] / 'Roslyn/bincore/csc.dll' for line in sdk_output if '[' in line]
    csc = next(path for path in reversed(candidates) if path.is_file())
    sources = sorted((HERE / 'UnityProject/Assets/Runtime').glob('*.cs'))
    source_inputs = [pin(path) for path in sources]
    refs = sorted(path for path in (base / 'ManakaInteraction_Data/Managed').glob('*.dll') if path.name != 'Assembly-CSharp.dll')
    record.mkdir(); shutil.copytree(base, package)
    dll = package / 'ManakaInteraction_Data/Managed/Assembly-CSharp.dll'
    rsp = record / 'runtime.rsp'
    lines = ['-target:library', '-nostdlib+', '-langversion:9.0', '-nologo', '-out:"' + str(dll) + '"']
    lines += ['-r:"' + str(path) + '"' for path in refs] + ['"' + str(path) + '"' for path in sources]
    rsp.write_text('\n'.join(lines) + '\n', encoding='utf8')
    compiled = subprocess.run([str(dotnet), str(csc), '-noconfig', '@' + str(rsp)], text=True, encoding='utf8', capture_output=True)
    (record / 'compiler.stdout.txt').write_text(compiled.stdout, encoding='utf8')
    (record / 'compiler.stderr.txt').write_text(compiled.stderr, encoding='utf8')
    if compiled.returncode:
        raise ValueError('Own managed compile failed: ' + compiled.stdout + compiled.stderr)
    if source_inputs != [pin(path) for path in sources]:
        raise ValueError('Source changed during compilation')
    relative_manifest = 'ManakaInteraction_Data/StreamingAssets/Original/interactions.json'
    manifest = HERE / 'UnityProject/Assets/StreamingAssets/Original/interactions.json'
    shutil.copyfile(manifest, package / relative_manifest)
    changed = {'ManakaInteraction_Data/Managed/Assembly-CSharp.dll', relative_manifest}
    actual = {path.relative_to(package).as_posix(): pin(path) for path in sorted(package.rglob('*')) if path.is_file()}
    if set(actual) != set(expected):
        raise ValueError('Unexpected files added to or removed from player host')
    for relative, row in actual.items():
        if relative not in changed and (row['bytes'], row['sha256']) != (expected[relative]['bytes'], expected[relative]['sha256']):
            raise ValueError('Native/baseline host file changed: ' + relative)
    receipt = dict(schema_version=1, status='archived-player-host-own-managed-module-prepared', unity_editor_build_performed=False,
                   scope='Own managed module compiled against archived Unity6 player references; native player/assets unchanged. Fresh Unity Editor build remains pending authorization/install prerequisites.',
                   base=str(base), package=str(package), baseline_manifest=pin(HERE / 'formal-project-runtime.json'),
                   compiler=pin(csc), dotnet=pin(dotnet), compile_exit_code=compiled.returncode, compiler_stdout=pin(record / 'compiler.stdout.txt'), compiler_stderr=pin(record / 'compiler.stderr.txt'),
                   sources=source_inputs, references=[pin(path) for path in refs], changed_paths=sorted(changed), replacement_inputs=[pin(manifest)],
                   base_files=[dict(relative_path=key, **value) for key, value in expected.items()], files=[dict(relative_path=key, **value) for key, value in actual.items()])
    (record / 'host.json').write_text(json.dumps(receipt, indent=2) + '\n', encoding='utf8')
    print(json.dumps(dict(status=receipt['status'], compile_exit_code=compiled.returncode, native_host_unchanged=True, unity_editor_build_performed=False, files=len(actual), record=str(record))))


if __name__ == '__main__':
    main()
