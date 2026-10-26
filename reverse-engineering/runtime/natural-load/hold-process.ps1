param([ValidateSet('Suspend','Resume')][string]$Mode='Resume',[int]$TaskProcessId=0)
$ErrorActionPreference='Stop'
$checkpoint='E:\ManakaREA-NaturalGameplay\NaturalLoad\20261027-2\process-checkpoint.json'
$expectedExe='E:\ManakaREA-NaturalGameplay\SecretFlasherManaka.exe'
if($Mode -eq 'Resume'){
 $saved=Get-Content -LiteralPath $checkpoint -Raw|ConvertFrom-Json
 if($saved.status -ne 'suspended' -or $saved.ntstatus -ne 0){throw 'No successful suspend receipt'}
 $TaskProcessId=$saved.pid
}elseif(Test-Path -LiteralPath $checkpoint){throw 'Preserve the existing checkpoint; do not increment its suspend count'}
$target=Get-Process -Id $TaskProcessId
if(-not $target.Path.Equals($expectedExe,[StringComparison]::OrdinalIgnoreCase)){throw 'Executable path mismatch'}
$started=$target.StartTime.ToUniversalTime().ToString('o')
if($Mode -eq 'Resume' -and $started -ne $saved.started_utc){throw 'PID has been reused; do not resume a different process'}
Add-Type @'
using System;
using System.Runtime.InteropServices;
public static class REAProcessHold {
 [DllImport("kernel32.dll",SetLastError=true)] public static extern IntPtr OpenProcess(uint access,bool inherit,int id);
 [DllImport("kernel32.dll")] public static extern bool CloseHandle(IntPtr handle);
 [DllImport("ntdll.dll")] public static extern int NtSuspendProcess(IntPtr handle);
 [DllImport("ntdll.dll")] public static extern int NtResumeProcess(IntPtr handle);
}
'@
$handle=[REAProcessHold]::OpenProcess(0x0800,$false,$TaskProcessId)
if($handle -eq [IntPtr]::Zero){throw 'Cannot obtain suspend/resume handle'}
try{if($Mode -eq 'Suspend'){$status=[REAProcessHold]::NtSuspendProcess($handle)}else{$status=[REAProcessHold]::NtResumeProcess($handle)}}finally{[void][REAProcessHold]::CloseHandle($handle)}
if($status -ne 0){throw "NT process operation failed: $status"}
$result=[ordered]@{status=if($Mode -eq 'Suspend'){'suspended'}else{'resumed'};pid=$TaskProcessId;path=$target.Path;started_utc=$started;observed_utc=[DateTime]::UtcNow.ToString('o');ntstatus=$status;scope='Only the independently launched game process; no application fields or user saves changed'}
$output=if($Mode -eq 'Suspend'){$checkpoint}else{Join-Path (Split-Path $checkpoint) ('process-resume-'+[DateTime]::UtcNow.ToString('yyyyMMdd-HHmmss')+'.json')}
[IO.File]::WriteAllText($output,(($result|ConvertTo-Json)+"`n"),[Text.UTF8Encoding]::new($false))
$result|ConvertTo-Json
