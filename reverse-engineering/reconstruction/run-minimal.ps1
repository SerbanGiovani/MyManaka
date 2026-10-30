param(
    [string]$BuildRun='minimal-20261031-1',
    [string]$RunName='minimal-acceptance-20261031-1',
    [ValidateSet('phase1','phase2','manual')][string]$Phase='phase1',
    [string]$ProfileRoot,
    [switch]$ShowWindow=$true
)
$ErrorActionPreference='Stop'
foreach($name in @($BuildRun,$RunName)){if($name -notmatch '^[a-z0-9-]+$'){throw 'Run names must be local simple names'}}
$cache=Join-Path $PSScriptRoot '.cache'
$build=Join-Path $cache ($BuildRun+'-build')
$exe=Join-Path $build 'ReconstructedManaka.exe'
$proof=Join-Path $cache ($RunName+'-'+$Phase)
if(Test-Path -LiteralPath $proof){throw 'Existing run evidence must be retained; choose another RunName'}
if(-not $ProfileRoot){$ProfileRoot=Join-Path $cache ($RunName+'-profile')}
$ProfileRoot=[IO.Path]::GetFullPath($ProfileRoot)
if($Phase -eq 'phase1' -and (Test-Path -LiteralPath (Join-Path $ProfileRoot 'save.v1.json'))){throw 'Phase1 requires an unused independent profile'}
if($Phase -eq 'phase2' -and -not (Test-Path -LiteralPath (Join-Path $ProfileRoot 'save.v1.json'))){throw 'Phase2 requires phase1 saved state'}
if(-not (Test-Path -LiteralPath $exe)){throw 'Build executable not found'}
New-Item -ItemType Directory -Path $proof -Force | Out-Null
$log=Join-Path $proof 'player.log'
$arguments=@('-screen-fullscreen','0','-screen-width','1280','-screen-height','720','--acceptance',$Phase,'--profile-root',('"'+$ProfileRoot+'"'),'--proof-dir',('"'+$proof+'"'),'-logFile',('"'+$log+'"'))
# The standalone batch-mode backbuffer was black in the first diagnostic run.
# Real acceptance keeps graphics/window presentation enabled and checks pixels.
$style=if($ShowWindow -or $Phase -eq 'manual'){'Normal'}else{'Hidden'}
$p=Start-Process -FilePath $exe -WorkingDirectory $build -ArgumentList $arguments -WindowStyle $style -PassThru
@{pid=$p.Id;executable=$exe;executable_sha256=(Get-FileHash -LiteralPath $exe -Algorithm SHA256).Hash.ToLowerInvariant();arguments=$arguments;phase=$Phase;profile_root=$ProfileRoot;proof_directory=$proof;input_scope='Automated phases supply simulated axes to the hardware PlayerMotor path; they do not prove physical keyboard input'} | ConvertTo-Json -Depth 5 | Set-Content -Encoding utf8 (Join-Path $proof 'process-start.json')
$p.Id
$p.WaitForExit()
@{pid=$p.Id;exit_code=$p.ExitCode;process_exited=$p.HasExited} | ConvertTo-Json | Set-Content -Encoding utf8 (Join-Path $proof 'process-exit.json')
