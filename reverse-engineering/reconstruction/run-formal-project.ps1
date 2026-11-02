param(
    [string]$BuildRun='formal-20261103-1',
    [string]$RunName='formal-controlled-20261103-1',
    [ValidateSet('interaction-controlled','phase2','manual')][string]$Phase='interaction-controlled',
    [string]$ProfileRoot,
    [string]$BuildDirectory
)
$ErrorActionPreference='Stop'
if($BuildRun -notmatch '^formal-[a-z0-9-]+$'){throw 'BuildRun must be a simple formal- prefixed name'}
if($RunName -notmatch '^[a-z0-9][a-z0-9-]*$'){throw 'RunName must be a local simple name'}
$cache=Join-Path $PSScriptRoot '.cache'
if(-not $BuildDirectory){$BuildDirectory=Join-Path $cache ($BuildRun+'-build')}
$build=[IO.Path]::GetFullPath($BuildDirectory)
if(-not (Test-Path -LiteralPath $build -PathType Container)){throw 'Build directory not found'}
$exe=Join-Path $build 'ManakaInteraction.exe'
$assembly=Join-Path $build 'ManakaInteraction_Data/Managed/Assembly-CSharp.dll'
foreach($required in @($exe,$assembly)){if(-not (Test-Path -LiteralPath $required -PathType Leaf)){throw ('Build input not found: '+$required)}}
$proof=Join-Path $cache ($RunName+'-'+$Phase)
if(Test-Path -LiteralPath $proof){throw 'Preserve existing runtime evidence; choose a fresh RunName'}
if(-not $ProfileRoot){$ProfileRoot=Join-Path $cache ($RunName+'-profile')}
$ProfileRoot=[IO.Path]::GetFullPath($ProfileRoot)
if($Phase -eq 'phase2' -and -not (Test-Path -LiteralPath (Join-Path $ProfileRoot 'save.v1.json') -PathType Leaf)){throw 'Cold readback requires a preceding independent save'}
New-Item -ItemType Directory -Path $proof -Force | Out-Null
$arguments=@('-screen-fullscreen','0','-screen-width','1280','-screen-height','720','--acceptance',$Phase,'--input-origin','controlled-unity-input','--profile-root',('"'+$ProfileRoot+'"'),'--proof-dir',('"'+$proof+'"'),'-logFile',('"'+(Join-Path $proof 'player.log')+'"'))
$p=Start-Process -FilePath $exe -WorkingDirectory $build -ArgumentList $arguments -WindowStyle Normal -PassThru
# Retain the operating-system handle before a short test process can exit.
# A successful engine log is never substituted for an unavailable OS exit code.
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
    declared_input_origin='controlled-unity-input'
    working_directory=$build
    process_handle_retained=($handle -ne [IntPtr]::Zero)
    scope='Independent maintained Unity reconstruction. Controlled phases use internal simulated input and do not establish physical keyboard reception. The optional build directory launches a standalone copy without referencing project Assets.'
} | ConvertTo-Json -Depth 5 | Set-Content -Encoding utf8 (Join-Path $proof 'process-start.json')
$p.Id
$p.WaitForExit()
$p.Refresh()
$observedExit=$p.ExitCode
$receipt=@{
    pid=$p.Id
    exit_code=$observedExit
    exit_code_observed=($null -ne $observedExit)
    process_exited=$p.HasExited
    exited_utc=[DateTime]::UtcNow.ToString('o')
}
$receipt | ConvertTo-Json | Set-Content -Encoding utf8 (Join-Path $proof 'process-exit.json')
if(-not $receipt.process_exited -or $null -eq $observedExit -or $observedExit -ne 0){throw 'Runtime did not produce an observed OS exit code 0; inspect the preserved run receipts'}
