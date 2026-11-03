"""Verify the formal project's current CLI/MCP connection without launching it.

Captured replies establish the recorded connection. --inputs also verifies the
live client launch target and package bytes; it never reads Pipeline port/token
descriptors and never infers hot-loading into the current chat.
"""
import argparse
import hashlib
import json
import tomllib
from pathlib import Path

HERE = Path(__file__).resolve().parent
CONNECTION = HERE / 'unity-connection'
STATUS = 'unity-formal-project-cli-mcp-connection-verified'


def read(path):
    return json.loads(Path(path).read_text('utf-8-sig'))


def sha(path):
    with Path(path).open('rb') as stream:
        return hashlib.file_digest(stream, 'sha256').hexdigest()


def require(condition, message):
    if not condition:
        raise ValueError(message)


def verify_files(rows, base):
    for row in rows:
        path = Path(row['path'])
        if not path.is_absolute():
            path = base / path
        require(path.is_file() and path.stat().st_size == row['bytes'] and sha(path) == row['sha256'], 'Unity connection input differs: ' + str(path))


def objects(value):
    if isinstance(value, dict):
        yield value
        for item in value.values():
            yield from objects(item)
    elif isinstance(value, list):
        for item in value:
            yield from objects(item)


def editor_state(value, project):
    matches = [row for row in objects(value) if row.get('unityVersion') == '6000.6.7f1' and row.get('projectPath') and Path(row['projectPath']) == project and row.get('status') == 'ready']
    require(matches, 'No recorded ready Unity editor matches the formal project')
    state = matches[0]
    require(state.get('compiling') is False and state.get('playMode') == 'stopped', 'Connection was not checked in idle edit mode')
    return state


def verify_probe(proof, project, cli):
    require(proof['status'] == 'mcp-initialize-tools-list-editor-status-verified' and proof['transport'] == 'stdio', 'MCP handshake/status proof is incomplete')
    require(proof['server_name'] == 'unity' and Path(proof['command']) == cli, 'Probe did not use the registered Unity CLI')
    require(len(proof['args']) == 3 and proof['args'][:2] == ['mcp', '--project-path'] and Path(proof['args'][2]) == project, 'Probe targets a different project or launch configuration')
    names = proof['tool_names']
    require(isinstance(names, list) and len(names) == len(set(names)) == proof['tools_count'] and {'editor_status', 'scene_list_open'} <= set(names), 'Unity MCP tool catalogue is incomplete or duplicated')
    require(proof['server_info']['name'] == 'unity-mcp' and proof['server_info']['version'], 'Unexpected MCP server identity')
    require(isinstance(proof['protocol_version'], str) and proof['protocol_version'], 'MCP protocol negotiation is absent')
    require(proof['invoked_tool'] == 'editor_status' and proof['mutation_performed'] is False, 'Probe claims a mutating or unexpected invocation')
    return editor_state(proof['editor_status'], project)


def verify_cli(payload, project, scene_path=None):
    require(payload.get('success') is True and not payload.get('errors'), 'Unity CLI command failed')
    target = payload.get('data', {}).get('target', {}).get('projectPath')
    require(target and Path(target) == project, 'Unity CLI reply targets a different project')
    if scene_path is None:
        return editor_state(payload, project)
    candidates = [row for row in objects(payload) if isinstance(row.get('scenes'), list)]
    require(candidates, 'CLI scene response contains no scene inventory')
    scenes = candidates[0]['scenes']
    require(any(row.get('path') == scene_path and row.get('isLoaded') is True and row.get('isActive') is True and row.get('isDirty') is False for row in scenes), 'CLI did not observe the intended saved active scene')
    return scenes


def verify_live_entry(setup, proof):
    config = tomllib.loads(Path(setup['client_configuration']).read_text('utf-8-sig'))
    entry = config['mcp_servers']['unity']
    require(entry.get('enabled', True) is True and Path(entry['command']) == Path(proof['command']), 'Live Unity MCP command is disabled or changed')
    require(entry['args'][:2] == ['mcp', '--project-path'] and len(entry['args']) == 3 and Path(entry['args'][2]) == Path(setup['project_path']), 'Live Unity MCP launch target is not the formal project')
    require(Path(entry['command']).is_file(), 'Registered Unity CLI command is unavailable')


def build(inputs=False):
    manifest = read(CONNECTION / 'manifest.json')
    require(manifest['schema_version'] == 1 and manifest['status'] == STATUS, 'Formal Unity connection manifest is incomplete')
    verify_files(manifest['files'], CONNECTION)
    setup = read(CONNECTION / 'setup.json')
    require(setup['schema_version'] == 1 and setup['current_chat_hot_reload_inferred'] is False, 'Unity connection setup is incomplete or infers chat hot reload')
    project, cli = Path(setup['project_path']), Path(setup['command'])
    require(project == HERE / 'UnityProject' and setup['server_name'] == 'unity' and setup['transport'] == 'stdio', 'Connection is not pinned to the maintained project')
    active = read(HERE / 'unity-active-settings.json')
    require(Path(setup['editor_path']) == Path(active['editor_path']) and setup['editor_version'] == active['editor_version'] == '6000.6.7f1', 'Connection uses a different selected editor')
    proof = read(CONNECTION / 'mcp-proof.json')
    state = verify_probe(proof, project, cli)
    cli_state = verify_cli(read(CONNECTION / 'cli-editor-status.json'), project)
    scenes = verify_cli(read(CONNECTION / 'cli-scenes.json'), project, setup['scene_path'])
    registration = read(CONNECTION / 'registration.json')
    require(registration['schema_version'] == 1 and registration['server_name'] == 'unity' and registration['transport'] == 'stdio' and registration['current_chat_hot_reload_inferred'] is False, 'Unity registration metadata is inconsistent')
    require(registration['status'] == 'unity-formal-project-mcp-registered' and registration['other_config_semantics_preserved'] is True, 'Unity registration changed other client configuration')
    require(registration['before_other_config_sha256'] == registration['after_other_config_sha256'], 'Non-Unity configuration preservation digest differs')
    require(registration['packages_unchanged'] is True and manifest['current_chat_hot_reload_inferred'] is False, 'Connection changed project packages or inferred chat hot reload')
    require(registration['project_path'] == setup['project_path'] and Path(registration['command']) == cli, 'Registration target differs from the probe')
    if inputs:
        verify_files(manifest['package_inputs'], Path())
        verify_live_entry(setup, proof)
    return dict(status=STATUS, project_path=str(project), editor_version=state['unityVersion'], tools_count=proof['tools_count'], stdio_verified=True, cli_editor_status_verified=True, cli_saved_scene_verified=True, active_scene=setup['scene_path'], other_config_semantics_preserved=True, packages_unchanged=True, current_chat_hot_reload_inferred=False, current_client_target_verified=inputs, new_native_queries=0)


if __name__ == '__main__':
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--inputs', action='store_true')
    args = parser.parse_args()
    print(json.dumps(build(args.inputs), ensure_ascii=False, indent=2))
