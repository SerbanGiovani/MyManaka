param(
    [ValidateSet('Import','Validate')][string]$Action='Validate',
    [Parameter(Mandatory=$true)][string]$RecordName,
    [string]$BridgeRoot=(Join-Path $PSScriptRoot 'asset-bridge/.cache')
)
$ErrorActionPreference='Stop'
if($RecordName -notmatch '^formal-[a-z0-9-]+$'){throw 'Use a fresh formal- prefixed record name'}
$configuration=Get-Content -LiteralPath (Join-Path $PSScriptRoot 'formal-editor-settings.json') -Raw | ConvertFrom-Json
$project=[IO.Path]::GetFullPath((Join-Path $PSScriptRoot $configuration.project))
$record=Join-Path $PSScriptRoot ('.cache/'+$RecordName)
if(Test-Path -LiteralPath $record){throw 'Preserve prior authoring receipts; choose a fresh RecordName'}
foreach($candidate in @(Get-CimInstance Win32_Process -Filter "Name='Unity.exe'")){
    $match=[regex]::Match([string]$candidate.CommandLine,'(?i)(?:^|\s)-projectPath(?:\s+|=)(?:"([^"]+)"|(\S+))')
    if(-not $match.Success){continue}
    $claimed=if($match.Groups[1].Success){$match.Groups[1].Value}else{$match.Groups[2].Value}
    if([string]::Equals([IO.Path]::GetFullPath($claimed).TrimEnd('\','/'),$project.TrimEnd('\','/'),[StringComparison]::OrdinalIgnoreCase)){throw 'Close the formal project editor before a batch authoring check'}
}
New-Item -ItemType Directory -Path $record | Out-Null
$method='ReconstructedManaka.Editor.ApartmentImporter.'+$Action
$arguments=@('-batchmode','-nographics','-quit','-projectPath',('"'+$project+'"'),'-executeMethod',$method,'--bridge-root',('"'+[IO.Path]::GetFullPath($BridgeRoot)+'"'),'--assetization-proof',('"'+(Join-Path $record 'assetization.json')+'"'),'-logFile',('"'+(Join-Path $record 'editor.log')+'"'))
$p=Start-Process -FilePath $configuration.editor_path -ArgumentList $arguments -WindowStyle Hidden -PassThru -RedirectStandardOutput (Join-Path $record 'stdout.log') -RedirectStandardError (Join-Path $record 'stderr.log')
$handle=$p.Handle
@{pid=$p.Id;process_handle_retained=($handle -ne [IntPtr]::Zero);editor=$configuration.editor_path;project=$project;method=$method;arguments=$arguments;started_utc=[DateTime]::UtcNow.ToString('o')} | ConvertTo-Json -Depth 4 | Set-Content -Encoding utf8 (Join-Path $record 'start.json')
$p.Id
$p.WaitForExit()
$p.Refresh()
$receipt=@{pid=$p.Id;exit_code=$p.ExitCode;exit_code_observed=($null -ne $p.ExitCode);process_exited=$p.HasExited;exited_utc=[DateTime]::UtcNow.ToString('o')}
$receipt | ConvertTo-Json | Set-Content -Encoding utf8 (Join-Path $record 'exit.json')
$receipt | ConvertTo-Json
if($null -eq $p.ExitCode -or $p.ExitCode -ne 0){throw ('Apartment authoring check failed; inspect preserved record: '+$record)}
