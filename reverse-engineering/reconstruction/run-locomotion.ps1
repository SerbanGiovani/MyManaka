param(
    [string]$BuildRun='locomotion-20261031-1',
    [string]$RunName='keyboard-20261031-1',
    [ValidateSet('keyboard','keyboard-resume','phase1','phase2')][string]$Phase='keyboard',
    [ValidateSet('physical-keyboard','os-injected-keyboard','simulated-axes')][string]$InputOrigin='physical-keyboard',
    [string]$ProfileRoot
)
$ErrorActionPreference='Stop'
foreach($name in @($BuildRun,$RunName)){if($name -notmatch '^[a-z0-9-]+$'){throw 'Run names must be local simple names'}}
$cache=Join-Path $PSScriptRoot '.cache'
$build=Join-Path $cache ($BuildRun+'-build')
$exe=Join-Path $build 'ManakaLocomotion.exe'
$proof=Join-Path $cache ($RunName+'-'+$Phase)
if(Test-Path -LiteralPath $proof){throw 'Existing run evidence must be retained; choose a new RunName'}
if(-not $ProfileRoot){$ProfileRoot=Join-Path $cache ($RunName+'-profile')}
$ProfileRoot=[IO.Path]::GetFullPath($ProfileRoot)
if($Phase -in @('keyboard-resume','phase2') -and -not (Test-Path -LiteralPath (Join-Path $ProfileRoot 'save.v1.json'))){throw 'Resume requires a preceding independent save'}
if(-not (Test-Path -LiteralPath $exe)){throw 'Build executable not found'}
New-Item -ItemType Directory -Path $proof -Force | Out-Null
$arguments=@('-screen-fullscreen','0','-screen-width','1280','-screen-height','720','--acceptance',$Phase,'--input-origin',$InputOrigin,'--profile-root',('"'+$ProfileRoot+'"'),'--proof-dir',('"'+$proof+'"'),'-logFile',('"'+(Join-Path $proof 'player.log')+'"'))
$p=Start-Process -FilePath $exe -WorkingDirectory $build -ArgumentList $arguments -WindowStyle Normal -PassThru
$assembly=Join-Path $build 'ManakaLocomotion_Data/Managed/Assembly-CSharp.dll'
@{pid=$p.Id;started_utc=[DateTime]::UtcNow.ToString('o');executable=$exe;executable_sha256=(Get-FileHash -LiteralPath $exe).Hash.ToLowerInvariant();assembly_path=$assembly;assembly_sha256=(Get-FileHash -LiteralPath $assembly).Hash.ToLowerInvariant();arguments=$arguments;phase=$Phase;profile_root=$ProfileRoot;proof_directory=$proof;declared_input_origin=$InputOrigin;scope='Origin is an operator declaration; actual Unity key/axis and motor/Animator samples must establish reception. OS injection does not prove physical hardware.'} | ConvertTo-Json -Depth 5 | Set-Content -Encoding utf8 (Join-Path $proof 'process-start.json')
$p.Id
$p.WaitForExit()
@{pid=$p.Id;exit_code=$p.ExitCode;process_exited=$p.HasExited;exited_utc=[DateTime]::UtcNow.ToString('o')} | ConvertTo-Json | Set-Content -Encoding utf8 (Join-Path $proof 'process-exit.json')
