"""Test the configured Unity MCP stdio transport with a read-only editor query."""
import argparse
import hashlib
import json
import queue
import subprocess
import threading
import time
import tomllib
from pathlib import Path


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--config', default=str(Path.home() / '.codex/config.toml'))
    parser.add_argument('--server', default='unity')
    parser.add_argument('--output', required=True)
    args = parser.parse_args()
    config = tomllib.loads(Path(args.config).read_text(encoding='utf-8-sig'))
    server = config['mcp_servers'][args.server]
    assert server['args'][0] == 'mcp' and '--project-path' in server['args']
    project = server['args'][server['args'].index('--project-path') + 1]
    output = Path(args.output)
    if output.exists():
        raise ValueError('Preserve the previous probe; choose a new output path')
    process = subprocess.Popen([server['command'], *server['args']], stdin=subprocess.PIPE,
                               stdout=subprocess.PIPE, stderr=subprocess.PIPE,
                               text=True, encoding='utf-8', bufsize=1)
    replies = queue.Queue()
    stderr_digest = hashlib.sha256()
    stderr_bytes = [0]

    def receive():
        for line in process.stdout:
            try:
                replies.put(json.loads(line))
            except ValueError:
                replies.put({'transport_error': 'Non-JSON stdout from MCP server'})
        replies.put({'transport_error': 'Server stdout closed'})

    def drain_stderr():
        for line in process.stderr:
            raw = line.encode('utf8')
            stderr_digest.update(raw)
            stderr_bytes[0] += len(raw)

    reader = threading.Thread(target=receive, daemon=True)
    errors = threading.Thread(target=drain_stderr, daemon=True)
    reader.start()
    errors.start()

    def send(value):
        process.stdin.write(json.dumps(value) + '\n')
        process.stdin.flush()

    def request(identifier, method, params):
        send(dict(jsonrpc='2.0', id=identifier, method=method, params=params))
        deadline = time.monotonic() + 45
        while time.monotonic() < deadline:
            value = replies.get(timeout=max(.01, deadline - time.monotonic()))
            if 'transport_error' in value:
                raise RuntimeError(value['transport_error'])
            if value.get('id') == identifier:
                if 'error' in value:
                    raise RuntimeError('MCP request failed: ' + json.dumps(value['error']))
                return value['result']
        raise TimeoutError(method)

    try:
        initialized = request(1, 'initialize', dict(protocolVersion='2025-03-26', capabilities={},
                              clientInfo=dict(name='ManakaUnityMcpReadOnlyProbe', version='1')))
        send(dict(jsonrpc='2.0', method='notifications/initialized'))
        catalog = request(2, 'tools/list', {})
        tools = catalog['tools']
        names = [tool['name'] for tool in tools]
        if 'editor_status' not in names:
            raise RuntimeError('Expected editor_status unavailable; exposed tools: ' + ', '.join(names))
        status = request(3, 'tools/call', dict(name='editor_status', arguments={}))
        if status.get('isError'):
            raise RuntimeError('editor_status returned an MCP error')
        # Status contains only the documented editor state. Do not collect a
        # Pipeline port descriptor, credentials or the complete client config.
        texts = [json.loads(item['text']) for item in status.get('content', []) if item.get('type') == 'text']
        structured = status.get('structuredContent')

        def states(value):
            if isinstance(value, dict):
                if value.get('unityVersion') and value.get('projectPath'):
                    yield value
                for item in value.values():
                    yield from states(item)
            elif isinstance(value, list):
                for item in value:
                    yield from states(item)

        observed = list(states([texts, structured]))
        match = next((row for row in observed if Path(row['projectPath']) == Path(project)
                      and row['unityVersion'] == '6000.6.7f1' and row.get('status') == 'ready'), None)
        if not match:
            raise RuntimeError('MCP status did not confirm the intended ready Unity6 project')
        safe_status = {key: match[key] for key in ['status', 'compiling', 'playMode', 'projectPath', 'unityVersion', 'role', 'instanceName'] if key in match}
        result = dict(schema_version=1, status='mcp-initialize-tools-list-editor-status-verified',
                      transport='stdio', server_name=args.server, command=server['command'], args=server['args'],
                      protocol_version=initialized['protocolVersion'], server_info=initialized.get('serverInfo'),
                      tools_count=len(names), tool_names=names, tools_catalog_sha256=hashlib.sha256(json.dumps(catalog, sort_keys=True).encode('utf8')).hexdigest(),
                      invoked_tool='editor_status', editor_status=safe_status, mutation_performed=False,
                      client_scope='Independent stdio probe using the saved Codex entry; current chat hot-reload is not inferred.')
        output.parent.mkdir(parents=True, exist_ok=True)
        output.write_text(json.dumps(result, ensure_ascii=False, indent=2) + '\n', encoding='utf8')
        print(json.dumps({key: result[key] for key in ['status', 'transport', 'tools_count', 'invoked_tool', 'editor_status']}, ensure_ascii=False, indent=2))
    finally:
        process.stdin.close()
        try:
            process.wait(timeout=5)
        except subprocess.TimeoutExpired:
            process.terminate()
            process.wait(timeout=5)


if __name__ == '__main__':
    main()
