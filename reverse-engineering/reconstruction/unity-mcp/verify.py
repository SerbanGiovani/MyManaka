"""Verify recorded Unity MCP installation and its independent read-only probe."""
import argparse
import hashlib
import json
import tomllib
from pathlib import Path

HERE = Path(__file__).resolve().parent


def read(path):
    return json.loads(path.read_text(encoding='utf-8-sig'))


def sha(path):
    with path.open('rb') as stream:
        return hashlib.file_digest(stream, 'sha256').hexdigest()


def build(inputs=False):
    manifest, setup = read(HERE / 'manifest.json'), read(HERE / 'setup.json')
    for row in manifest['files']:
        path = HERE / row['path']
        assert path.stat().st_size == row['bytes'] and sha(path) == row['sha256'], 'MCP artifact differs: ' + str(path)
    proof = read(HERE / 'connection-proof.json')
    assert proof['status'] == 'mcp-initialize-tools-list-editor-status-verified' and proof['transport'] == 'stdio'
    assert proof['server_name'] == setup['mcp']['server_name'] == 'unity'
    assert proof['server_info'] == dict(name='unity-mcp', version=setup['cli']['installed_version_observed'])
    assert proof['protocol_version'] == '2025-03-26' and proof['tools_count'] == len(proof['tool_names']) == 169
    assert len(set(proof['tool_names'])) == 169 and proof['invoked_tool'] == 'editor_status'
    assert proof['mutation_performed'] is False and 'editor_status' in proof['tool_names']
    assert Path(proof['command']) == Path(setup['mcp']['command'])
    assert proof['args'][:2] == setup['mcp']['args'][:2] == ['mcp', '--project-path']
    project = Path(setup['editor']['project_path'])
    assert Path(proof['args'][2]) == Path(setup['mcp']['args'][2]) == project
    observed = proof['editor_status']
    assert Path(observed['projectPath']) == project and observed['unityVersion'] == setup['editor']['version']
    assert observed['status'] == 'ready' and observed['compiling'] is False and observed['playMode'] == 'stopped'
    packages = read(HERE / 'packages-manifest.json')
    lock = read(HERE / 'packages-lock.json')['dependencies'][setup['pipeline']['package_id']]
    assert packages['dependencies'][setup['pipeline']['package_id']] == lock['version'] == setup['pipeline']['version']
    assert lock['source'] == 'registry' and lock['url'] == setup['pipeline']['registry']
    receipt = read(HERE / 'setup-verification.json')
    assert receipt['status'] == 'unity-mcp-configured-editor-ready' and not receipt['unity_entry_written']
    assert receipt['other_config_semantics_preserved'] and receipt['current_chat_tools_verified'] is False
    assert receipt['client_catalog_reload_required'] and manifest['client_catalog_loaded_in_installation_chat'] is False
    assert manifest['listener_observed'] == dict(address='127.0.0.1', port=7800, owner_pid=45240)
    if inputs:
        for row in manifest['package_inputs']:
            path = Path(row['path'])
            assert path.stat().st_size == row['bytes'] and sha(path) == row['sha256'], 'Live Unity package input changed'
        current = tomllib.loads(Path(setup['mcp']['client_configuration']).read_text(encoding='utf-8-sig'))['mcp_servers']['unity']
        assert Path(current['command']) == Path(proof['command']) and current.get('enabled', True)
        assert current['args'][:2] == ['mcp', '--project-path'] and Path(current['args'][2]) == project
        assert Path(current['command']).exists()
    return dict(status=manifest['status'], tools_count=169, stdio_verified=True, readonly_editor_status_verified=True,
                client_catalog_loaded_in_installation_chat=False, package_version=lock['version'], new_native_queries=0)


if __name__ == '__main__':
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--inputs', action='store_true')
    args = parser.parse_args()
    print(json.dumps(build(args.inputs), indent=2))
