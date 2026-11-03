"""Register the maintained Unity project's existing CLI/Pipeline with Codex.

Only the unity MCP entry is updated. Backups stay in an ignored private cache;
the optional receipt contains launch metadata and semantic digests, not secrets.
"""
import argparse
import datetime
import hashlib
import json
import os
from pathlib import Path
import re
import shutil
import subprocess
import tomllib
import uuid

HERE = Path(__file__).resolve().parent
RECONSTRUCTION = HERE.parent
PROJECT = RECONSTRUCTION / 'UnityProject'


def read_json(path):
    return json.loads(path.read_text('utf-8-sig'))


def require(condition, message):
    if not condition:
        raise RuntimeError(message)


def write_json(path, value):
    path.parent.mkdir(parents=True, exist_ok=True)
    path.write_text(json.dumps(value, ensure_ascii=False, indent=2) + '\n', 'utf-8')


def package_pins():
    rows = []
    for name in ('manifest.json', 'packages-lock.json'):
        path = PROJECT / 'Packages' / name
        rows.append(dict(path=str(path), bytes=path.stat().st_size,
                         sha256=hashlib.sha256(path.read_bytes()).hexdigest()))
    return rows


def client_state(path, cli):
    config = tomllib.loads(path.read_text('utf-8-sig')) if path.exists() else {}
    entry = config.get('mcp_servers', {}).get('unity', {})
    args = entry.get('args', [])
    matches = (entry.get('enabled', True) is True and
               Path(entry.get('command', '')).resolve() == cli.resolve() and
               isinstance(args, list) and len(args) == 3 and
               args[:2] == ['mcp', '--project-path'] and
               Path(args[2]).resolve() == PROJECT.resolve())
    other = json.loads(json.dumps(config, default=str))
    if isinstance(other.get('mcp_servers'), dict):
        other['mcp_servers'].pop('unity', None)
        if not other['mcp_servers']:
            other.pop('mcp_servers')
    digest = hashlib.sha256(json.dumps(other, sort_keys=True, ensure_ascii=False,
                                     separators=(',', ':')).encode()).hexdigest()
    return matches, digest


def unity_section(text):
    headers = list(re.finditer(r'(?m)^\[[^\r\n]+\][ \t]*(?:\r?\n|$)', text))
    matches = [i for i, match in enumerate(headers)
               if match.group().strip() == '[mcp_servers.unity]']
    require(len(matches) <= 1, 'Ambiguous Unity TOML section')
    if not matches:
        return None
    index = matches[0]
    start = headers[index].start()
    end = headers[index + 1].start() if index + 1 < len(headers) else len(text)
    return start, end


def merge_unity(original, registered):
    # Codex may normalize unrelated TOML defaults when serializing. Register in
    # a private CODEX_HOME and copy only this standalone launch table instead.
    generated = unity_section(registered)
    require(generated is not None, 'Codex did not produce a Unity launch table')
    table = registered[generated[0]:generated[1]]
    existing = unity_section(original)
    if existing is None:
        return original.rstrip() + '\n\n' + table
    return original[:existing[0]] + table + original[existing[1]:]


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--cli', default=shutil.which('unity'))
    parser.add_argument('--codex', default=shutil.which('codex'))
    parser.add_argument('--receipt', type=Path)
    args = parser.parse_args()
    require(args.cli and args.codex, 'Unity CLI and Codex CLI must already be installed')
    cli = Path(args.cli).resolve()
    active = read_json(RECONSTRUCTION / 'unity-active-settings.json')
    require(Path(active['editor_path']).is_file(), 'Selected Unity editor is unavailable')
    version = (PROJECT / 'ProjectSettings' / 'ProjectVersion.txt').read_text('utf-8-sig')
    require('m_EditorVersion: ' + active['editor_version'] in version,
            'Maintained project version differs from the selected editor')
    pipeline = read_json(PROJECT / 'Packages' / 'manifest.json')['dependencies'].get('com.unity.pipeline')
    require(pipeline == '0.9.1-exp.1', 'Expected the existing pinned Pipeline package; no package installation was attempted')
    before_packages = package_pins()
    config_root = Path(os.environ.get('CODEX_HOME', str(Path.home() / '.codex')))
    client_config = config_root / 'config.toml'
    matches, before_digest = client_state(client_config, cli)
    stamp = datetime.datetime.now(datetime.timezone.utc).strftime('%Y%m%dT%H%M%SZ')
    private = RECONSTRUCTION / '.cache' / ('unity-connection-' + stamp + '-' + uuid.uuid4().hex[:8])
    backup = private / 'before'
    backup.mkdir(parents=True)
    if client_config.exists():
        shutil.copy2(client_config, backup / 'codex-config.toml')
    for row in before_packages:
        shutil.copy2(row['path'], backup / Path(row['path']).name)
    version_run = subprocess.run([str(cli), '--version', '--no-banner'], capture_output=True,
                                 encoding='utf-8', check=True)
    cli_version = version_run.stdout.strip()
    changed = False
    if not matches:
        original = client_config.read_text('utf-8-sig') if client_config.exists() else ''
        staged_root = private / 'registration-client'
        staged_root.mkdir()
        staged_config = staged_root / 'config.toml'
        staged_config.write_text(original, 'utf-8')
        child_env = dict(os.environ, CODEX_HOME=str(staged_root))
        result = subprocess.run([args.codex, 'mcp', 'add', 'unity', '--', str(cli),
                                 'mcp', '--project-path', str(PROJECT)], capture_output=True,
                                encoding='utf-8', env=child_env)
        (private / 'codex-register.log').write_text(result.stdout + result.stderr, 'utf-8')
        require(result.returncode == 0, 'Codex registration failed; inspect private receipt ' + str(private))
        merged = merge_unity(original, staged_config.read_text('utf-8-sig'))
        candidate = private / 'candidate-config.toml'
        candidate.write_text(merged, 'utf-8')
        candidate_matches, candidate_digest = client_state(candidate, cli)
        require(candidate_matches and candidate_digest == before_digest,
                'Registration cannot preserve the existing non-Unity configuration')
        current = client_config.read_text('utf-8-sig') if client_config.exists() else ''
        require(current == original, 'Client configuration changed concurrently; registration was not applied')
        client_config.parent.mkdir(parents=True, exist_ok=True)
        with client_config.open('w', encoding='utf-8', newline='') as stream:
            stream.write(merged)
        changed = True
    matches, after_digest = client_state(client_config, cli)
    require(matches, 'Resulting Unity MCP entry does not target the maintained project')
    require(before_digest == after_digest,
            'Other client configuration changed; inspect private backup ' + str(private))
    require(before_packages == package_pins(), 'Project package inputs changed during registration')
    receipt = dict(schema_version=1, status='unity-formal-project-mcp-registered',
                   project_path=str(PROJECT), command=str(cli), server_name='unity',
                   transport='stdio', client_configuration=str(client_config),
                   cli_version_observed=cli_version, pipeline_version=pipeline,
                   unity_entry_written=changed, other_config_semantics_preserved=True,
                   before_other_config_sha256=before_digest,
                   after_other_config_sha256=after_digest, packages_unchanged=True,
                   current_chat_hot_reload_inferred=False)
    write_json(private / 'registration.json', receipt)
    if args.receipt:
        write_json(args.receipt, receipt)
    print(json.dumps(dict(status=receipt['status'], project_path=str(PROJECT),
                          unity_entry_written=changed, packages_unchanged=True,
                          other_config_semantics_preserved=True, private_record=str(private),
                          client_reconnect_required=True), ensure_ascii=False, indent=2))


if __name__ == '__main__':
    main()
