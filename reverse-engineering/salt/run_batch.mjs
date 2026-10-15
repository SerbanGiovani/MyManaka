// One public REA MCP subprocess, one native import, multiple static function queries.
import { createRequire } from 'node:module';
import { readFile, writeFile, mkdir } from 'node:fs/promises';
import { createHash } from 'node:crypto';
import { join, dirname, resolve } from 'node:path';
import { fileURLToPath } from 'node:url';

const here = dirname(fileURLToPath(import.meta.url));
const planPath = resolve(process.argv[2] ?? join(here, 'symbols/crypto.plan.json'));
const plan = JSON.parse(await readFile(planPath, 'utf8'));
const packageRoot = join(process.env.APPDATA, 'npm/node_modules/rea-agents');
const requireREA = createRequire(join(packageRoot, 'package.json'));
const { Client } = requireREA('@modelcontextprotocol/client');
const { StdioClientTransport } = requireREA('@modelcontextprotocol/client/stdio');
const hash = bytes => createHash('sha256').update(bytes).digest('hex');
if (hash(await readFile(plan.target)) !== plan.native_sha256) throw Error('Native input fingerprint differs');
if (hash(await readFile(plan.seed_file)) !== plan.seed_sha256) throw Error('Seed file differs from the reviewed plan');
if (plan.functions.some(f => f.operations.some(op => !['procedure_pseudo_code', 'analyze_function'].includes(op)))) {
  throw Error('Only static function queries are accepted');
}
await mkdir(plan.output_directory, { recursive: true });
const env = { ...process.env,
  GHIDRA_INSTALL_DIR: process.env.GHIDRA_INSTALL_DIR ?? join(process.env.LOCALAPPDATA, 'REA/tools/ghidra_12.1.4_PUBLIC'),
  JAVA_HOME: process.env.JAVA_HOME ?? 'C:/Program Files/Eclipse Adoptium/jdk-25.0.4.1-hotspot',
  REA_ANALYSIS_PROVIDER: 'ghidra', REA_GHIDRA_STARTUP_TIMEOUT_MS: String(plan.timeout_ms),
  REA_GHIDRA_SEED_FILE: plan.seed_file, REA_GHIDRA_DISABLED_ANALYZERS: plan.disabled_analyzers.join(',') };
const transport = new StdioClientTransport({ command: process.execPath,
  args: [join(packageRoot, 'scripts/rea.mjs'), 'mcp'], env, stderr: 'pipe' });
let stderr = '';
transport.stderr?.on('data', chunk => { stderr = (stderr + chunk).slice(-65536); });
const client = new Client({ name: 'manaka-resource-crypto', version: '1.0.0' }, { capabilities: {} });
const report = { plan: planPath, native_sha256: plan.native_sha256, started_at_utc: new Date().toISOString(),
  seed_sha256: plan.seed_sha256, functions: [], success: false, global_mcp_configuration_changed: false };
const start = performance.now();
let opened = false;
function unpack(result) {
  if (result.structuredContent) return result.structuredContent;
  const text = result.content?.find(item => item.type === 'text')?.text;
  if (!text) throw Error('REA result has no structured content');
  return JSON.parse(text);
}
async function call(name, args) {
  const result = await client.callTool({ name, arguments: args }, { timeout: plan.timeout_ms + 30000 });
  const value = unpack(result);
  if (result.isError || value.error) {
    await writeFile(join(plan.output_directory, `${name}.failed.json`), JSON.stringify(result, null, 2) + '\n');
    throw Error(`REA ${name} failed; original response saved`);
  }
  return value;
}
try {
  await client.connect(transport, { timeout: 30000 });
  // SDK needs the advertised output contracts for tool-result validation.
  const catalog = await client.listTools();
  const names = new Set(catalog.tools.map(t => t.name));
  for (const tool of ['open_binary','close_binary','procedure_pseudo_code','analyze_function','export_evidence_bundle']) {
    if (!names.has(tool)) throw Error(`REA does not advertise ${tool}`);
  }
  const openedResult = await call('open_binary', { path: plan.target, provider_id: 'ghidra' });
  opened = true;
  if (openedResult.result?.sha256 !== plan.native_sha256) throw Error('REA opened a different target');
  for (const fn of plan.functions) {
    for (const operation of fn.operations) {
      const queryStart = performance.now();
      console.log(`Analyzing ${fn.qualified_name} ${fn.token}: ${operation}`);
      const evidence = await call(operation, { procedure: fn.va });
      if (evidence.subject?.digest?.sha256 !== plan.native_sha256 || evidence.provider?.id !== 'ghidra' || !evidence.evidence_id) {
        throw Error('Function evidence identity mismatch');
      }
      const stem = `${fn.token}-${operation}`;
      await writeFile(join(plan.output_directory, stem + '.json'), JSON.stringify(evidence, null, 2) + '\n');
      if (operation === 'procedure_pseudo_code') {
        if (typeof evidence.normalized_result !== 'string' || !evidence.normalized_result.trim()) throw Error('No pseudocode body');
        await writeFile(join(plan.output_directory, stem + '.pseudocode.c'),
          '// Ghidra pseudocode; not original source or compilable C.\n// ' + evidence.evidence_id + '\n' +
          evidence.normalized_result.replaceAll('\r\r\n', '\n').replaceAll('\r\n', '\n'));
      }
      const seconds = Math.round((performance.now() - queryStart) / 1000 * 1000) / 1000;
      report.functions.push({ ...fn, operation, evidence_id: evidence.evidence_id, elapsed_seconds: seconds });
      console.log(`Saved ${stem} (${seconds}s)`);
    }
  }
  await call('export_evidence_bundle', { path: join(plan.output_directory, 'rea-evidence.json'), overwrite: true });
  report.success = true;
} catch (error) {
  report.error = String(error?.stack ?? error);
  process.exitCode = 1;
} finally {
  if (opened) {
    if (!report.success) {
      try { await call('export_evidence_bundle', { path: join(plan.output_directory, 'rea-evidence.json'), overwrite: true }); }
      catch (error) { report.export_error = String(error); }
    }
    try { await call('close_binary', {}); } catch (error) { report.close_error = String(error); report.success = false; process.exitCode = 1; }
  }
  try { await client.close(); } catch (error) { report.transport_close_error = String(error); report.success = false; process.exitCode = 1; }
  report.elapsed_seconds = Math.round((performance.now() - start) / 1000 * 1000) / 1000;
  report.finished_at_utc = new Date().toISOString();
  await writeFile(join(plan.output_directory, 'run.json'), JSON.stringify(report, null, 2) + '\n');
  await writeFile(join(plan.output_directory, 'server.stderr.log'), stderr);
  console.log(JSON.stringify({ success: report.success, elapsed_seconds: report.elapsed_seconds,
    observations: report.functions.length, error: report.error ?? null }));
}
