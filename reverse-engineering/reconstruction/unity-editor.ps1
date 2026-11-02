param(
    [ValidateSet('Create','Build','Open')][string]$Action='Open',
    [string]$RunName='unity6-20261103-2',
    [string]$BuildRun,
    [string]$Settings=(Join-Path $PSScriptRoot 'editor-settings.json'),
    [string]$BridgeRoot=(Join-Path $PSScriptRoot 'asset-bridge/.cache'),
    [string]$Models=(Join-Path $PSScriptRoot '../salt/.cache/decrypted/models.unity3d'),
    [string]$Seed=(Join-Path $PSScriptRoot 'save-bridge/.cache/seed.json'),
    [string]$Interactions=(Join-Path $PSScriptRoot 'interaction-evidence/interactions.json')
)
$ErrorActionPreference='Stop'
if(-not $BuildRun){$BuildRun=$RunName}
foreach($name in @($RunName,$BuildRun)){if($name -notmatch '^unity6-[a-z0-9-]+$'){throw 'Use a fresh unity6- prefixed run name; historical projects are not migration targets'}}
$configuration=Get-Content -LiteralPath $Settings -Raw | ConvertFrom-Json
if($configuration.schema_version -ne 1 -or $configuration.product -ne 'Unity' -or $configuration.render_pipeline -ne 'Built-in' -or $configuration.scripting_backend -ne 'Mono2x' -or $configuration.active_input_handler -ne 0){throw 'Unsupported or incomplete Unity editor configuration'}
$editor=[IO.Path]::GetFullPath($configuration.editor_path)
if(-not (Test-Path -LiteralPath $editor -PathType Leaf)){throw ('Unity editor not found: '+$editor)}
$productVersion=(Get-Item -LiteralPath $editor).VersionInfo.ProductVersion
if(-not $productVersion.StartsWith($configuration.editor_version+'_',[StringComparison]::Ordinal)){throw ('Configured and installed Unity versions differ: '+$productVersion)}
$cache=Join-Path $PSScriptRoot '.cache'
$project=[IO.Path]::GetFullPath((Join-Path $cache $RunName))

function Fingerprint([string]$Path){
    $item=Get-Item -LiteralPath $Path
    @{path=$item.FullName;bytes=$item.Length;sha256=(Get-FileHash -LiteralPath $item.FullName -Algorithm SHA256).Hash.ToLowerInvariant()}
}

function ProjectEditors([string]$ProjectPath){
    foreach($candidate in @(Get-CimInstance Win32_Process -Filter "Name='Unity.exe' OR Name='Tuanjie.exe'")){
        $match=[regex]::Match([string]$candidate.CommandLine,'(?i)(?:^|\s)-projectPath(?:\s+|=)(?:"([^"]+)"|(\S+))')
        if(-not $match.Success){continue}
        $claimed=if($match.Groups[1].Success){$match.Groups[1].Value}else{$match.Groups[2].Value}
        if([string]::Equals([IO.Path]::GetFullPath($claimed).TrimEnd('\','/'),$ProjectPath.TrimEnd('\','/'),[StringComparison]::OrdinalIgnoreCase)){$candidate}
    }
}

if($Action -eq 'Create'){
    New-Item -ItemType Directory -Path $cache -Force | Out-Null
    $createLog=Join-Path $cache ($RunName+'-create.log')
    $createStart=Join-Path $cache ($RunName+'-start.json')
    $createExit=Join-Path $cache ($RunName+'-exit.json')
    $createStdout=Join-Path $cache ($RunName+'-stdout.log')
    $createStderr=Join-Path $cache ($RunName+'-stderr.log')
    foreach($reserved in @($project,$createLog,$createStart,$createExit,$createStdout,$createStderr)){if(Test-Path -LiteralPath $reserved){throw 'Existing creation project or receipt: use a fresh RunName'}}
    $arguments=@('-batchmode','-nographics','-quit','-createProject',('"'+$project+'"'),'-logFile',('"'+$createLog+'"'))
    $createProcess=Start-Process -FilePath $editor -ArgumentList $arguments -WindowStyle Hidden -RedirectStandardOutput $createStdout -RedirectStandardError $createStderr -PassThru
    # Retain the launch handle before a short-lived editor can exit. This is an
    # OS exit observation; a log's "return code 0" does not substitute for it.
    $createHandle=$createProcess.Handle
    @{pid=$createProcess.Id;started_utc=[DateTime]::UtcNow.ToString('o');editor=$editor;editor_identity=(Fingerprint $editor);product_version=$productVersion;project=$project;log=$createLog;arguments=$arguments;settings=(Fingerprint $Settings);process_handle_retained=($createHandle -ne [IntPtr]::Zero);scope='New isolated Unity6 editor/license prerequisite; no original assets, login or activation settings changed'} | ConvertTo-Json -Depth 5 | Set-Content -Encoding utf8 $createStart
    $createProcess.Id
    $createProcess.WaitForExit()
    $createProcess.Refresh()
    $observedExit=$createProcess.ExitCode
    $createdExit=@{pid=$createProcess.Id;exited_utc=[DateTime]::UtcNow.ToString('o');exit_code=$observedExit;exit_code_observed=($null -ne $observedExit);process_exited=$createProcess.HasExited;project_version_generated=(Test-Path -LiteralPath (Join-Path $project 'ProjectSettings/ProjectVersion.txt'))}
    $createdExit | ConvertTo-Json | Set-Content -Encoding utf8 $createExit
    if($null -eq $observedExit -or -not $createdExit.process_exited -or $observedExit -ne 0 -or -not $createdExit.project_version_generated){throw 'Unity project creation did not produce an observed OS exit code 0; inspect the preserved create receipt and log'}
    return
}

$created=Get-Content -LiteralPath (Join-Path $cache ($RunName+'-start.json')) -Raw | ConvertFrom-Json
$creationExit=Get-Content -LiteralPath (Join-Path $cache ($RunName+'-exit.json')) -Raw | ConvertFrom-Json
if($null -eq $creationExit.exit_code -or -not $creationExit.process_exited -or $creationExit.exit_code -ne 0 -or -not $creationExit.project_version_generated){throw 'Unity project creation did not produce an observed OS exit code 0'}
if(-not [string]::Equals([IO.Path]::GetFullPath($created.project),$project,[StringComparison]::OrdinalIgnoreCase) -or -not [string]::Equals([IO.Path]::GetFullPath($created.editor),$editor,[StringComparison]::OrdinalIgnoreCase)){throw 'Creation receipt is not for this isolated project and selected Unity editor'}
$version=Get-Content -LiteralPath (Join-Path $project 'ProjectSettings/ProjectVersion.txt') -Raw
if($version -notmatch ('(?m)^m_EditorVersion: '+[regex]::Escape($configuration.editor_version)+'\r?$')){throw 'Project version does not match the selected Unity editor'}
$active=@(ProjectEditors $project)
if($Action -eq 'Open'){
    if($active.Count){
        if(@($active | Where-Object {-not [string]::Equals($_.ExecutablePath,$editor,[StringComparison]::OrdinalIgnoreCase)}).Count){throw 'This project is open in a different editor'}
        $active | ForEach-Object {$_.ProcessId}
        return
    }
    $openRecord=Join-Path $cache ($RunName+'-open-'+[DateTime]::UtcNow.ToString('yyyyMMddTHHmmssfffffffZ'))
    New-Item -ItemType Directory -Path $openRecord | Out-Null
    $openLog=Join-Path $openRecord 'editor.log'
    $arguments=@('-projectPath',('"'+$project+'"'),'-logFile',('"'+$openLog+'"'))
    $opened=Start-Process -FilePath $editor -ArgumentList $arguments -WindowStyle Normal -PassThru
    @{pid=$opened.Id;started_utc=[DateTime]::UtcNow.ToString('o');editor=$editor;product_version=$productVersion;project=$project;log=$openLog;arguments=$arguments;settings=(Fingerprint $Settings);scope='Interactive Unity editor requested by the user; no batch mode or automatic Play invocation'} | ConvertTo-Json -Depth 5 | Set-Content -Encoding utf8 (Join-Path $openRecord 'start.json')
    $opened.Id
    return
}
if($active.Count){throw 'Project editor is still running; close it normally before a batch build'}
$output=Join-Path $cache ($BuildRun+'-build')
$record=Join-Path $cache ($BuildRun+'-build-record')
if((Test-Path -LiteralPath $output) -or (Test-Path -LiteralPath $record)){throw 'Build output/record exists; choose a fresh BuildRun'}
$runtime=Join-Path $PSScriptRoot $configuration.runtime_template
$editorSource=Join-Path $PSScriptRoot $configuration.editor_template
foreach($required in @($runtime,$editorSource,$Models,$Seed,$Interactions,(Join-Path $BridgeRoot 'roombridge.json'),(Join-Path $BridgeRoot 'Apartment.geometry.json'))){if(-not (Test-Path -LiteralPath $required)){throw ('Missing prepared input: '+$required)}}
$projectSettings=Join-Path $project 'ProjectSettings/ProjectSettings.asset'
$settingsText=[IO.File]::ReadAllText($projectSettings)
$inputPattern='(?m)^([ \t]*activeInputHandler:[ \t]*)([0-2])([ \t]*\r?)$'
$handlers=[regex]::Matches($settingsText,$inputPattern)
if($handlers.Count -ne 1){throw 'Expected exactly one Unity activeInputHandler setting'}
$before=Fingerprint $projectSettings
$priorHandler=[int]$handlers[0].Groups[2].Value
New-Item -ItemType Directory -Path (Join-Path $record 'Assets/Editor') -Force | Out-Null
if($priorHandler -ne 0){
    $settingsText=[regex]::Replace($settingsText,$inputPattern,'${1}0${3}')
    [IO.File]::WriteAllText($projectSettings,$settingsText,(New-Object System.Text.UTF8Encoding($false)))
}
@{setting='activeInputHandler';before_value=$priorHandler;after_value=0;changed=($priorHandler -ne 0);before=$before;after=(Fingerprint $projectSettings);scope='Only this newly created Unity6 project; original Runtime uses UnityEngine.Input'} | ConvertTo-Json -Depth 4 | Set-Content -Encoding utf8 (Join-Path $record 'input-settings.json')
Copy-Item -LiteralPath $runtime -Destination (Join-Path $record 'Assets/Runtime') -Recurse
Copy-Item -LiteralPath $editorSource -Destination (Join-Path $record 'Assets/Editor/BuildMinimal.cs')
Get-ChildItem -LiteralPath (Join-Path $record 'Assets') | ForEach-Object {Copy-Item -LiteralPath $_.FullName -Destination (Join-Path $project 'Assets') -Recurse -Force}
$stream=Join-Path $project 'Assets/StreamingAssets'
$original=Join-Path $stream 'Original'
New-Item -ItemType Directory -Path $original -Force | Out-Null
foreach($name in @('roombridge.json','Apartment.geometry.json')){Copy-Item -LiteralPath (Join-Path $BridgeRoot $name) -Destination (Join-Path $original $name)}
$textureDestination=Join-Path $original 'Textures'
New-Item -ItemType Directory -Path $textureDestination -Force | Out-Null
Get-ChildItem -LiteralPath (Join-Path $BridgeRoot 'Textures') -File | ForEach-Object {Copy-Item -LiteralPath $_.FullName -Destination $textureDestination -Force}
Copy-Item -LiteralPath $Models -Destination (Join-Path $original 'models.unity3d')
Copy-Item -LiteralPath $Interactions -Destination (Join-Path $original 'interactions.json')
Copy-Item -LiteralPath $Seed -Destination (Join-Path $stream 'seed.json')
$fingerprints=@(Get-ChildItem -LiteralPath (Join-Path $record 'Assets') -Recurse -File | ForEach-Object {Fingerprint $_.FullName})
$inputs=@(Get-ChildItem -LiteralPath $stream -Recurse -File | Where-Object {$_.Extension -ne '.meta'} | ForEach-Object {Fingerprint $_.FullName})
$exe=Join-Path $output 'ManakaInteraction.exe'
$log=Join-Path $record 'editor.log'
$arguments=@('-batchmode','-nographics','-quit','-projectPath',('"'+$project+'"'),'-executeMethod','ReconstructedManaka.Editor.BuildMinimal.Build','--output',('"'+$exe+'"'),'-logFile',('"'+$log+'"'))
$buildProcess=Start-Process -FilePath $editor -ArgumentList $arguments -WindowStyle Hidden -RedirectStandardOutput (Join-Path $record 'stdout.log') -RedirectStandardError (Join-Path $record 'stderr.log') -PassThru
$buildHandle=$buildProcess.Handle
@{pid=$buildProcess.Id;started_utc=[DateTime]::UtcNow.ToString('o');editor=$editor;editor_identity=(Fingerprint $editor);product_version=$productVersion;project=$project;output=$output;executable=$exe;log=$log;arguments=$arguments;settings=(Fingerprint $Settings);runtime_migration=(Fingerprint (Join-Path $PSScriptRoot 'unity-project/runtime-migration.json'));sources=$fingerprints;inputs=$inputs;process_handle_retained=($buildHandle -ne [IntPtr]::Zero);scope='Unity6 Windows64 Mono build with a bounded GetInstanceID-to-complete-EntityId compile adaptation; original native gameplay assembly and BepInEx are absent'} | ConvertTo-Json -Depth 6 | Set-Content -Encoding utf8 (Join-Path $record 'start.json')
$buildProcess.Id
$buildProcess.WaitForExit()
$buildProcess.Refresh()
$observedExit=$buildProcess.ExitCode
$buildReceipt=@{pid=$buildProcess.Id;exited_utc=[DateTime]::UtcNow.ToString('o');exit_code=$observedExit;exit_code_observed=($null -ne $observedExit);process_exited=$buildProcess.HasExited;executable_exists=(Test-Path -LiteralPath $exe)}
$buildReceipt | ConvertTo-Json | Set-Content -Encoding utf8 (Join-Path $record 'exit.json')
if($null -eq $observedExit -or $observedExit -ne 0 -or -not $buildReceipt.executable_exists){throw 'Unity build failed or lacks an observed OS exit code; inspect the preserved build record'}
