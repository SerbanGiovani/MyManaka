param([string]$Editor='H:\Unity Editor\2022.3.62t7\Editor\Tuanjie.exe',[string]$RunName='editor-smoke')
$ErrorActionPreference='Stop'
if($RunName -notmatch '^[a-z0-9-]+$'){throw 'RunName must be a simple local directory name'}
$cache=Join-Path $PSScriptRoot '.cache'
New-Item -ItemType Directory -Path $cache -Force | Out-Null
$project=Join-Path $cache $RunName
if(Test-Path -LiteralPath $project){throw 'Existing smoke project: inspect the prior receipt before choosing a new destination'}
$log=Join-Path $cache ($RunName+'-create.log')
$arguments=@('-batchmode','-nographics','-quit','-createProject',('"'+$project+'"'),'-logFile',('"'+$log+'"'))
$p=Start-Process -FilePath $Editor -ArgumentList $arguments -WindowStyle Hidden -RedirectStandardOutput (Join-Path $cache ($RunName+'-stdout.log')) -RedirectStandardError (Join-Path $cache ($RunName+'-stderr.log')) -PassThru
@{pid=$p.Id;editor=$Editor;product_version=(Get-Item -LiteralPath $Editor).VersionInfo.ProductVersion;project=$project;log=$log;arguments=$arguments;scope='Isolated editor/license startup prerequisite; no original assets or game assembly copied'} | ConvertTo-Json -Depth 4 | Set-Content -Encoding utf8 (Join-Path $cache ($RunName+'-start.json'))
$p.Id
$p.WaitForExit()
@{pid=$p.Id;exit_code=$p.ExitCode;process_exited=$p.HasExited;project_version_generated=(Test-Path -LiteralPath (Join-Path $project 'ProjectSettings/ProjectVersion.txt'))} | ConvertTo-Json | Set-Content -Encoding utf8 (Join-Path $cache ($RunName+'-exit.json'))
