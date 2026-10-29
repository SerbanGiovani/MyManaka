param([string]$RunName='authorized-20261030-1')
$ErrorActionPreference='Stop'
if($RunName -notmatch '^[a-z0-9-]+$'){throw 'RunName must be a local simple name'}
$cache=Join-Path $PSScriptRoot '.cache'
$start=Get-Content -LiteralPath (Join-Path $cache ($RunName+'-start.json')) -Raw | ConvertFrom-Json
$exit=Get-Content -LiteralPath (Join-Path $cache ($RunName+'-exit.json')) -Raw | ConvertFrom-Json
if(-not $exit.process_exited -or $exit.exit_code -ne 0){throw 'Editor creation did not succeed'}
if(Get-Process -Id $start.pid -ErrorAction SilentlyContinue){throw 'Creation editor PID still present; inspect before building'}
$project=$start.project
New-Item -ItemType Directory -Force -Path (Join-Path $project 'Assets/Editor') | Out-Null
Copy-Item -LiteralPath (Join-Path $PSScriptRoot 'toolchain-smoke/Assets/RuntimeSmoke.cs') -Destination (Join-Path $project 'Assets/RuntimeSmoke.cs')
Copy-Item -LiteralPath (Join-Path $PSScriptRoot 'toolchain-smoke/Assets/Editor/BuildSmoke.cs') -Destination (Join-Path $project 'Assets/Editor/BuildSmoke.cs')
$output=Join-Path $cache ($RunName+'-build')
if(Test-Path -LiteralPath $output){throw 'Build output exists; preserve the prior build'}
$log=Join-Path $cache ($RunName+'-build.log')
$arguments=@('-batchmode','-nographics','-quit','-projectPath',('"'+$project+'"'),'-executeMethod','REAToolchain.BuildSmoke.Run','-reaBuildRoot',('"'+$output+'"'),'-logFile',('"'+$log+'"'))
$p=Start-Process -FilePath $start.editor -ArgumentList $arguments -WindowStyle Hidden -RedirectStandardOutput (Join-Path $cache ($RunName+'-build-stdout.log')) -RedirectStandardError (Join-Path $cache ($RunName+'-build-stderr.log')) -PassThru
@{pid=$p.Id;editor=$start.editor;project=$project;output=$output;log=$log;arguments=$arguments} | ConvertTo-Json -Depth 4 | Set-Content -Encoding utf8 (Join-Path $cache ($RunName+'-build-start.json'))
$p.Id
$p.WaitForExit()
@{pid=$p.Id;exit_code=$p.ExitCode;process_exited=$p.HasExited} | ConvertTo-Json | Set-Content -Encoding utf8 (Join-Path $cache ($RunName+'-build-exit.json'))
