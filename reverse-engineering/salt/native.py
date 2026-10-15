"""Run REA native analysis with an explicit profile and large-binary deadline.

Uses the installed public REA launcher; does not change global MCP settings.
"""

import argparse
from datetime import datetime, timezone
import hashlib
import json
import os
from pathlib import Path
import shutil
import subprocess
import time


def main():
    here = Path(__file__).resolve().parent
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--target", type=Path, default=Path(r"E:\SecretFlasherManakaREA\GameAssembly.dll"))
    parser.add_argument("--procedure", default="0x18143e460")
    parser.add_argument("--timeout-ms", type=int)
    parser.add_argument("--focused", action="store_true", help="Seed GetSalt and omit expensive whole-image discovery passes")
    parser.add_argument("--output", type=Path)
    parser.add_argument("--snapshot", type=Path)
    args = parser.parse_args()
    if args.timeout_ms is None:
        args.timeout_ms = 600000 if args.focused else 1800000
    if not 1 <= args.timeout_ms <= 2147483647:
        parser.error("timeout-ms must be between 1 and 2147483647")
    target = args.target.resolve(strict=True)
    identity = json.loads((here / "evidence/artifact-identity.json").read_text(encoding="utf-8"))
    target_digest = hashlib.sha256(target.read_bytes()).hexdigest()
    if target_digest != identity["native_sha256"]:
        parser.error("Target differs from the recorded GameAssembly.dll; re-establish artifact identity first")
    node = shutil.which("node")
    launcher = Path(os.environ["APPDATA"]) / "npm/node_modules/rea-agents/scripts/rea.mjs"
    if not node or not launcher.is_file():
        parser.error("Installed Node.js and public REA launcher are required")
    env = os.environ.copy()
    env["REA_GHIDRA_STARTUP_TIMEOUT_MS"] = str(args.timeout_ms)
    env["GHIDRA_INSTALL_DIR"] = env.get("GHIDRA_INSTALL_DIR", str(
        Path(os.environ["LOCALAPPDATA"]) / "REA/tools/ghidra_12.1.4_PUBLIC"))
    env["JAVA_HOME"] = env.get("JAVA_HOME", r"C:\Program Files\Eclipse Adoptium\jdk-25.0.4.1-hotspot")
    # Only this script selects the analysis options committed into the evidence.
    for setting in ("REA_GHIDRA_DISABLED_ANALYZERS", "REA_GHIDRA_SEED_FILE"):
        if env.get(setting):
            parser.error(f"Unset {setting} so this script can select its recorded analysis profile")
    disabled = []
    if args.focused:
        if args.procedure.lower() != identity["native"]["method_va"]:
            parser.error("The focused seed is bound to the recorded GetSalt address")
        disabled = ["Disassemble Entry Points", "Function Start Search", "Subroutine References", "Reference", "Data Reference", "Create Address Tables",
                    "Non-Returning Functions - Discovered", "Decompiler Switch Analysis"]
        env["REA_GHIDRA_DISABLED_ANALYZERS"] = ",".join(disabled)
        env["REA_GHIDRA_SEED_FILE"] = str(here / "native-getsalt.seeds.tsv")
    suffix = "-focused" if args.focused else ""
    output = (args.output or here / f"evidence/native-getsalt{suffix}.json").resolve()
    snapshot = args.snapshot.resolve() if args.snapshot else None
    output.parent.mkdir(parents=True, exist_ok=True)
    if snapshot:
        snapshot.parent.mkdir(parents=True, exist_ok=True)
    pending = output.with_suffix(".pending.json")
    stderr = output.with_suffix(".stderr.log")
    command = [node, str(launcher), "decompile", str(target), args.procedure,
               "--provider=ghidra", "--json"]
    if snapshot:
        command.append(f"--snapshot={snapshot}")
    print(f"REA native analysis: {args.procedure}; startup deadline {args.timeout_ms} ms", flush=True)
    started_at = datetime.now(timezone.utc).isoformat()
    started = time.monotonic()
    with pending.open("wb") as stdout_file, stderr.open("wb") as stderr_file:
        result = subprocess.run(command, env=env, stdout=stdout_file, stderr=stderr_file)
    elapsed = round(time.monotonic() - started, 3)
    try:
        record = json.loads(pending.read_text(encoding="utf-8-sig"))
    except json.JSONDecodeError:
        record = {"error": "REA did not return JSON; inspect the stderr log"}
    evidence = record.get("data", record) if isinstance(record, dict) else record
    success = (result.returncode == 0 and isinstance(evidence, dict)
               and "error" not in evidence and bool(evidence.get("evidence_id"))
               and evidence.get("operation") == "procedure_pseudo_code"
               and isinstance(evidence.get("normalized_result"), str)
               and bool(evidence["normalized_result"].strip())
               and evidence.get("subject", {}).get("digest", {}).get("sha256") == target_digest
               and evidence.get("provider", {}).get("id") == "ghidra")
    destination = output if success else output.with_suffix(".failed.json")
    pending.replace(destination)
    diagnostics = {
        "started_at_utc": started_at, "elapsed_seconds": elapsed,
        "exit_code": result.returncode, "success": success,
        "target": str(target), "target_sha256": target_digest,
        "procedure": args.procedure, "provider_startup_timeout_ms": args.timeout_ms,
        "analyzer_preset": "ghidra-default" if not disabled else "ghidra-default+disabled:" + ",".join(disabled),
        "disabled_analyzers": disabled, "snapshot": str(snapshot) if snapshot else None,
        "seed_file": env.get("REA_GHIDRA_SEED_FILE"),
        "output": str(destination), "command": command,
        "ghidra_max_heap": env.get("GHIDRA_HEADLESS_MAXMEM", env.get("GHIDRA_MAXMEM", "2G")),
        "public_launcher_sha256": hashlib.sha256(launcher.read_bytes()).hexdigest(),
        "global_mcp_configuration_changed": False
    }
    output.with_suffix(".run.json").write_text(json.dumps(diagnostics, indent=2) + "\n", encoding="utf-8")
    if success:
        pseudocode = evidence["normalized_result"].replace("\r\r\n", "\n").replace("\r\n", "\n")
        output.with_suffix(".pseudocode.c").write_text(
            "// Ghidra pseudocode, not original source or compilable C.\n"
            f"// REA evidence: {evidence['evidence_id']}\n" + pseudocode,
            encoding="utf-8")
    print(json.dumps(diagnostics, indent=2), flush=True)
    if not success:
        raise SystemExit(result.returncode or 1)


if __name__ == "__main__":
    main()
