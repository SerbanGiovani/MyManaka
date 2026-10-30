param(
    [string]$ProjectRun='locomotion-20261031-1',
    [string]$BuildRun='locomotion-20261031-1',
    [string]$BridgeRoot=(Join-Path $PSScriptRoot 'asset-bridge/.cache'),
    [string]$Models=(Join-Path $PSScriptRoot '../salt/.cache/decrypted/models.unity3d'),
    [string]$Seed=(Join-Path $PSScriptRoot 'save-bridge/.cache/seed.json')
)
$ErrorActionPreference='Stop'
foreach($name in @($ProjectRun,$BuildRun)){if($name -notmatch '^[a-z0-9-]+$'){throw 'Run names must be local simple names'}}
$cache=Join-Path $PSScriptRoot '.cache'
$created=Get-Content -LiteralPath (Join-Path $cache ($ProjectRun+'-start.json')) -Raw | ConvertFrom-Json
$creationExit=Get-Content -LiteralPath (Join-Path $cache ($ProjectRun+'-exit.json')) -Raw | ConvertFrom-Json
if(-not $creationExit.process_exited -or $creationExit.exit_code -ne 0){throw 'Project creation did not succeed'}
$project=$created.project
$active=Get-CimInstance Win32_Process | Where-Object {$_.Name -eq 'Tuanjie.exe' -and $_.CommandLine -like ('*'+$project+'*')}
if($active){throw 'Project editor is still running; preserve its result before rebuilding'}
$output=Join-Path $cache ($BuildRun+'-build')
$record=Join-Path $cache ($BuildRun+'-build-record')
if((Test-Path -LiteralPath $output) -or (Test-Path -LiteralPath $record)){throw 'Build output/record exists; choose a fresh BuildRun'}
$template=Join-Path $PSScriptRoot 'locomotion-project/Assets'
if(-not (Test-Path -LiteralPath (Join-Path $template 'Editor/BuildMinimal.cs'))){throw 'Runtime template is not ready'}
foreach($required in @($Models,$Seed,(Join-Path $BridgeRoot 'roombridge.json'),(Join-Path $BridgeRoot 'Apartment.geometry.json'))){if(-not (Test-Path -LiteralPath $required)){throw ('Missing prepared input: '+$required)}}
New-Item -ItemType Directory -Path $record -Force | Out-Null
Copy-Item -LiteralPath $template -Destination (Join-Path $record 'Assets') -Recurse
Copy-Item -Path (Join-Path $template '*') -Destination (Join-Path $project 'Assets') -Recurse -Force
$stream=Join-Path $project 'Assets/StreamingAssets'
$original=Join-Path $stream 'Original'
New-Item -ItemType Directory -Path $original -Force | Out-Null
foreach($name in @('roombridge.json','Apartment.geometry.json')){Copy-Item -LiteralPath (Join-Path $BridgeRoot $name) -Destination (Join-Path $original $name)}
$textureDestination=Join-Path $original 'Textures'
New-Item -ItemType Directory -Path $textureDestination -Force | Out-Null
Get-ChildItem -LiteralPath (Join-Path $BridgeRoot 'Textures') -File | ForEach-Object {Copy-Item -LiteralPath $_.FullName -Destination $textureDestination -Force}
Copy-Item -LiteralPath $Models -Destination (Join-Path $original 'models.unity3d')
Copy-Item -LiteralPath $Seed -Destination (Join-Path $stream 'seed.json')
$fingerprints=Get-ChildItem -LiteralPath (Join-Path $record 'Assets') -Recurse -File | ForEach-Object {@{path=$_.FullName;sha256=(Get-FileHash -LiteralPath $_.FullName -Algorithm SHA256).Hash.ToLowerInvariant();bytes=$_.Length}}
$inputs=Get-ChildItem -LiteralPath $stream -Recurse -File | Where-Object {$_.Extension -ne '.meta'} | ForEach-Object {@{path=$_.FullName;sha256=(Get-FileHash -LiteralPath $_.FullName -Algorithm SHA256).Hash.ToLowerInvariant();bytes=$_.Length}}
$exe=Join-Path $output 'ManakaLocomotion.exe'
$log=Join-Path $record 'editor.log'
$arguments=@('-batchmode','-nographics','-quit','-projectPath',('"'+$project+'"'),'-executeMethod','ReconstructedManaka.Editor.BuildMinimal.Build','--output',('"'+$exe+'"'),'-logFile',('"'+$log+'"'))
$p=Start-Process -FilePath $created.editor -ArgumentList $arguments -WindowStyle Hidden -RedirectStandardOutput (Join-Path $record 'stdout.log') -RedirectStandardError (Join-Path $record 'stderr.log') -PassThru
@{pid=$p.Id;editor=$created.editor;project=$project;output=$output;executable=$exe;log=$log;arguments=$arguments;sources=$fingerprints;inputs=$inputs;scope='Independent reconstructed runtime; original native gameplay assembly and BepInEx are not copied'} | ConvertTo-Json -Depth 6 | Set-Content -Encoding utf8 (Join-Path $record 'start.json')
$p.Id
$p.WaitForExit()
@{pid=$p.Id;exit_code=$p.ExitCode;process_exited=$p.HasExited;executable_exists=(Test-Path -LiteralPath $exe)} | ConvertTo-Json | Set-Content -Encoding utf8 (Join-Path $record 'exit.json')
