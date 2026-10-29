param([string]$Editor='H:\Unity Editor\2022.3.62t7\Editor\Tuanjie.exe')
$ErrorActionPreference='Stop'
$cache=Join-Path $PSScriptRoot '.cache'
New-Item -ItemType Directory -Path $cache -Force | Out-Null
$project=Join-Path $cache 'editor-smoke'
if(Test-Path -LiteralPath $project){throw 'Existing smoke project: inspect the prior receipt before choosing a new destination'}
$log=Join-Path $cache 'editor-create.log'
$arguments=@('-batchmode','-nographics','-quit','-createProject',('"'+$project+'"'),'-logFile',('"'+$log+'"'))
$p=Start-Process -FilePath $Editor -ArgumentList $arguments -WindowStyle Hidden -PassThru
@{pid=$p.Id;editor=$Editor;product_version=(Get-Item -LiteralPath $Editor).VersionInfo.ProductVersion;project=$project;log=$log;arguments=$arguments;scope='Isolated editor/license startup prerequisite; no original assets or game assembly copied'} | ConvertTo-Json -Depth 4 | Set-Content -Encoding utf8 (Join-Path $cache 'editor-start.json')
$p.Id
