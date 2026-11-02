param(
    [string]$ProjectPath,
    [string]$RunName,
    [string]$Cli,
    [string]$Python='python',
    [string]$Codex='codex',
    [switch]$ReplaceTarget,
    [ValidateRange(1,60)][int]$ReadyTimeoutSeconds=45
)
$ErrorActionPreference='Stop'
$reconstruction=[IO.Path]::GetFullPath((Join-Path $PSScriptRoot '..'))
$setup=Get-Content -LiteralPath (Join-Path $PSScriptRoot 'setup.json') -Raw | ConvertFrom-Json
$settingsPath=Join-Path $PSScriptRoot $setup.editor.settings
$settings=Get-Content -LiteralPath $settingsPath -Raw | ConvertFrom-Json
if($setup.schema_version -ne 1 -or $setup.mcp.transport -ne 'stdio' -or $setup.mcp.server_name -ne 'unity'){throw 'Unsupported Unity MCP setup description'}
if(-not $ProjectPath){
    if(-not $RunName){$RunName=$settings.default_run_name}
    if($RunName -notmatch '^unity6-[a-z0-9-]+$'){throw 'Use a simple unity6- project run name'}
    $ProjectPath=Join-Path $reconstruction ('.cache/'+$RunName)
}
$ProjectPath=[IO.Path]::GetFullPath($ProjectPath)
$packages=Join-Path $ProjectPath 'Packages'
$projectVersion=Join-Path $ProjectPath 'ProjectSettings/ProjectVersion.txt'
foreach($required in @($projectVersion,(Join-Path $packages 'manifest.json'))){if(-not (Test-Path -LiteralPath $required -PathType Leaf)){throw ('Unity project input missing: '+$required)}}
if((Get-Content -LiteralPath $projectVersion -Raw) -notmatch ('(?m)^m_EditorVersion: '+[regex]::Escape($settings.editor_version)+'\r?$')){throw 'Project version differs from the selected reconstruction editor'}
if(-not $Cli){
    if(Test-Path -LiteralPath $setup.cli.command -PathType Leaf){$Cli=$setup.cli.command}
    else{$Cli=(Get-Command unity -CommandType Application -ErrorAction Stop | Select-Object -First 1).Source}
}
$Cli=[IO.Path]::GetFullPath($Cli)
$pythonCommand=(Get-Command $Python -CommandType Application -ErrorAction Stop | Select-Object -First 1).Source
$codexCommand=(Get-Command $Codex -CommandType Application -ErrorAction Stop | Select-Object -First 1).Source
$taskConfigRoot=if($env:CODEX_HOME){[IO.Path]::GetFullPath($env:CODEX_HOME)}else{Join-Path ([Environment]::GetFolderPath('UserProfile')) '.codex'}
$clientConfig=Join-Path $taskConfigRoot 'config.toml'

# Probe only the Unity launch target and a semantic digest of all other keys.
# Full client configuration is backed up privately and is never printed.
$probe=@'
import hashlib,json,pathlib,sys,tomllib
path=pathlib.Path(sys.argv[1])
config=tomllib.loads(path.read_text(encoding='utf-8-sig')) if path.exists() else {}
servers=config.get('mcp_servers',{})
entry=servers.get('unity')
def same_path(a,b):
    return isinstance(a,str) and pathlib.Path(a).resolve()==pathlib.Path(b).resolve()
matches=False
if isinstance(entry,dict):
    args=entry.get('args')
    matches=(same_path(entry.get('command'),sys.argv[2]) and isinstance(args,list)
             and len(args)==3 and args[:2]==['mcp','--project-path']
             and same_path(args[2],sys.argv[3]) and entry.get('enabled',True) is True)
other=json.loads(json.dumps(config,default=str))
if isinstance(other.get('mcp_servers'),dict):
    other['mcp_servers'].pop('unity',None)
    if not other['mcp_servers']:
        other.pop('mcp_servers')
digest=hashlib.sha256(json.dumps(other,sort_keys=True,ensure_ascii=False,separators=(',',':')).encode()).hexdigest()
print(json.dumps({'unity_present':entry is not None,'same_launch_target':matches,'other_config_sha256':digest}))
'@
function ProbeClient {
    $output=& $pythonCommand -B -X utf8 -c $probe $clientConfig $Cli $ProjectPath
    if($LASTEXITCODE -ne 0){throw 'Could not parse the current Codex configuration safely'}
    $output | ConvertFrom-Json
}
$before=ProbeClient
if($before.unity_present -and -not $before.same_launch_target -and -not $ReplaceTarget){throw 'The Unity MCP entry already targets a different launch configuration. Use -ReplaceTarget only when replacing that target is intended.'}

$stamp=[DateTime]::UtcNow.ToString('yyyyMMddTHHmmssfffffffZ')+'-'+[Guid]::NewGuid().ToString('N').Substring(0,8)
$record=Join-Path $reconstruction ('.cache/unity-mcp-configure-'+$stamp)
$backup=Join-Path $record 'before'
New-Item -ItemType Directory -Path $backup | Out-Null
foreach($name in @('manifest.json','packages-lock.json')){
    $path=Join-Path $packages $name
    if(Test-Path -LiteralPath $path -PathType Leaf){Copy-Item -LiteralPath $path -Destination (Join-Path $backup $name)}
}
if(Test-Path -LiteralPath $clientConfig -PathType Leaf){Copy-Item -LiteralPath $clientConfig -Destination (Join-Path $backup 'codex-config.toml')}
$versionOutput=@(& $Cli --version --no-banner)
if($LASTEXITCODE -ne 0){throw 'The selected Unity CLI could not run; install Unity.CLI from the official winget source'}
$cliVersion=($versionOutput | Where-Object {$_ -match '^\d+\.\d+\.\d+(?:-[\w.-]+)?$'} | Select-Object -Last 1)
if(-not $cliVersion){throw 'The Unity CLI did not return an identifiable version'}
$installOutput=& $Cli pipeline install --project-path $ProjectPath --version $setup.pipeline.version --non-interactive --format json --no-banner
$installExit=$LASTEXITCODE
$installOutput | Set-Content -LiteralPath (Join-Path $record 'pipeline-install.json') -Encoding utf8
if($installExit -ne 0){throw ('Pipeline install failed; inspect private receipt '+$record)}
$manifest=Get-Content -LiteralPath (Join-Path $packages 'manifest.json') -Raw | ConvertFrom-Json
if($manifest.dependencies.'com.unity.pipeline' -ne $setup.pipeline.version){throw 'Installed Pipeline version differs from the explicit package pin'}
$registered=$false
if(-not $before.same_launch_target){
    $registerOutput=& $codexCommand mcp add unity -- $Cli mcp --project-path $ProjectPath
    $registerExit=$LASTEXITCODE
    $registerOutput | Set-Content -LiteralPath (Join-Path $record 'codex-register.log') -Encoding utf8
    if($registerExit -ne 0){throw ('Codex MCP registration failed; inspect private receipt '+$record)}
    $registered=$true
}
$after=ProbeClient
if(-not $after.same_launch_target){throw 'The resulting Unity MCP entry does not match the selected CLI and project'}
if($before.other_config_sha256 -ne $after.other_config_sha256){throw ('Non-Unity client configuration changed during setup. No automatic rollback was attempted; inspect private before snapshot '+$record)}
$statusOutput=& $Cli status --until-ready --timeout $ReadyTimeoutSeconds --project-path $ProjectPath --format json --no-banner
$statusExit=$LASTEXITCODE
$statusOutput | Set-Content -LiteralPath (Join-Path $record 'editor-status.json') -Encoding utf8
if($statusExit -ne 0){throw ('MCP is configured but the Editor is not ready. Focus Unity to refresh the package, then inspect '+$record)}
@{status='unity-mcp-configured-editor-ready';cli=$Cli;cli_version_observed=$cliVersion;pipeline=$setup.pipeline.package_id;pipeline_version=$setup.pipeline.version;project=$ProjectPath;client_config=$clientConfig;unity_entry_written=$registered;other_config_semantics_preserved=$true;current_chat_tools_verified=$false;client_catalog_reload_required=$true;private_record=$record;scope='Package installation and project-pinned MCP configuration only; no scene, Play Mode, runtime server, sandbox policy or other MCP entry is changed intentionally'} | ConvertTo-Json -Depth 5 | Set-Content -LiteralPath (Join-Path $record 'configured.json') -Encoding utf8
Write-Output ('Configured Unity MCP for '+$ProjectPath)
Write-Output ('Private backups and receipts: '+$record)
Write-Output 'Reload the client MCP connection or start a new session; configuration alone does not prove that this chat loaded its tools.'
