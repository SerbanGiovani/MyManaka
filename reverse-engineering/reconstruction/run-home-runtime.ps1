param(
    [string]$BuildRun='formal-home-20261103-1',
    [string]$RunName='home-20261103-1',
    [ValidateSet('home-controlled','home-resume','manual')][string]$Phase='home-controlled',
    [string]$ProfileRoot,
    [string]$BuildDirectory
)
$ErrorActionPreference='Stop'
if($BuildRun -notmatch '^formal-[a-z0-9-]+$'){throw 'Use a simple formal- prefixed BuildRun'}
if($RunName -notmatch '^[a-z0-9][a-z0-9-]*$'){throw 'Use a local simple RunName'}
$cache=Join-Path $PSScriptRoot '.cache'
if(-not $BuildDirectory){$BuildDirectory=Join-Path $cache ($BuildRun+'-build')}
$build=[IO.Path]::GetFullPath($BuildDirectory)
$exe=Join-Path $build 'ManakaInteraction.exe'
$assembly=Join-Path $build 'ManakaInteraction_Data/Managed/Assembly-CSharp.dll'
foreach($path in @($exe,$assembly)){if(-not (Test-Path -LiteralPath $path -PathType Leaf)){throw ('Runtime input is absent: '+$path)}}
$proof=Join-Path $cache ($RunName+'-'+$Phase)
if(Test-Path -LiteralPath $proof){throw 'Preserve earlier runtime evidence; choose a fresh RunName'}
if(-not $ProfileRoot){$ProfileRoot=Join-Path $cache ($RunName+'-profile')}
$ProfileRoot=[IO.Path]::GetFullPath($ProfileRoot)
if($Phase -eq 'home-resume' -and -not (Test-Path -LiteralPath (Join-Path $ProfileRoot 'save.v1.json') -PathType Leaf)){throw 'Home resume requires the preceding independent save'}
New-Item -ItemType Directory -Path $proof -Force | Out-Null
$inputOrigin=if($Phase -eq 'manual'){'undeclared'}else{'controlled-unity-input'}
$arguments=@('-screen-fullscreen','0','-screen-width','1280','-screen-height','720','--acceptance',$Phase,'--input-origin',$inputOrigin,'--profile-root',('"'+$ProfileRoot+'"'),'--proof-dir',('"'+$proof+'"'),'-logFile',('"'+(Join-Path $proof 'player.log')+'"'))
$p=Start-Process -FilePath $exe -WorkingDirectory $build -ArgumentList $arguments -WindowStyle Normal -PassThru
$handle=$p.Handle
@{
    pid=$p.Id
    started_utc=[DateTime]::UtcNow.ToString('o')
    executable=$exe
    executable_sha256=(Get-FileHash -LiteralPath $exe -Algorithm SHA256).Hash.ToLowerInvariant()
    assembly_path=$assembly
    assembly_sha256=(Get-FileHash -LiteralPath $assembly -Algorithm SHA256).Hash.ToLowerInvariant()
    arguments=$arguments
    phase=$Phase
    profile_root=$ProfileRoot
    proof_directory=$proof
    declared_input_origin=$inputOrigin
    working_directory=$build
    process_handle_retained=($handle -ne [IntPtr]::Zero)
    scope='Independent maintained Unity project. Home-controlled/home-resume use declared internal test input and do not establish physical keyboard reception. Runtime object consumers and save readback are independently checked from the emitted trace.'
} | ConvertTo-Json -Depth 5 | Set-Content -Encoding utf8 (Join-Path $proof 'process-start.json')
$p.Id
$p.WaitForExit()
$p.Refresh()
$code=$p.ExitCode
$receipt=@{pid=$p.Id;exit_code=$code;exit_code_observed=($null -ne $code);process_exited=$p.HasExited;exited_utc=[DateTime]::UtcNow.ToString('o')}
$receipt | ConvertTo-Json | Set-Content -Encoding utf8 (Join-Path $proof 'process-exit.json')
if(-not $receipt.process_exited -or $null -eq $code -or $code -ne 0){throw 'Home runtime lacked an observed successful OS exit; inspect preserved receipts'}
