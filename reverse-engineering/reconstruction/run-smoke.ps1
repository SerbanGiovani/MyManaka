param([string]$RunName='authorized-20261030-1')
$ErrorActionPreference='Stop'
if($RunName -notmatch '^[a-z0-9-]+$'){throw 'RunName must be a local simple name'}
$cache=Join-Path $PSScriptRoot '.cache'
$output=Join-Path $cache ($RunName+'-build')
$receipt=Get-Content -LiteralPath (Join-Path $output 'build-receipt.json') -Raw | ConvertFrom-Json
if($receipt.result -ne 'Succeeded' -or $receipt.errors -ne 0){throw 'No successful build'}
$proof=Join-Path $cache ($RunName+'-runtime-proof.json')
if(Test-Path -LiteralPath $proof){throw 'Preserve the existing runtime proof'}
$exe=Join-Path $output 'ToolchainSmoke.exe'
$arguments=@('-batchmode','-nographics','-reaProof',('"'+$proof+'"'),'-logFile',('"'+(Join-Path $cache ($RunName+'-runtime.log'))+'"'))
$p=Start-Process -FilePath $exe -WorkingDirectory $output -ArgumentList $arguments -WindowStyle Hidden -RedirectStandardOutput (Join-Path $cache ($RunName+'-runtime-stdout.log')) -RedirectStandardError (Join-Path $cache ($RunName+'-runtime-stderr.log')) -PassThru
$p.Id
$p.WaitForExit()
@{pid=$p.Id;exit_code=$p.ExitCode;process_exited=$p.HasExited;executable=$exe;sha256=(Get-FileHash -LiteralPath $exe).Hash.ToLowerInvariant();arguments=$arguments} | ConvertTo-Json -Depth 4 | Set-Content -Encoding utf8 (Join-Path $cache ($RunName+'-runtime-exit.json'))
