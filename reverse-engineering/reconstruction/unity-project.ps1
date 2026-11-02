param(
    [ValidateSet('Prepare','Validate','Build','Open')][string]$Action='Open',
    [string]$RunName,
    [string]$ProjectPath=(Join-Path $PSScriptRoot 'UnityProject'),
    [string]$Settings=(Join-Path $PSScriptRoot 'formal-editor-settings.json'),
    [string]$Models=(Join-Path $PSScriptRoot '../salt/.cache/decrypted/models.unity3d')
)
$ErrorActionPreference='Stop'
$expectedModels='98621b2c4fa4f9de80f355fae5776ab17efc016bcc81c581bcd0917af4308367'
$expectedModelBytes=223101993
$configuration=Get-Content -LiteralPath $Settings -Raw | ConvertFrom-Json
$editor=[IO.Path]::GetFullPath($configuration.editor_path)
$project=[IO.Path]::GetFullPath($ProjectPath).TrimEnd('\','/')
$cache=Join-Path $PSScriptRoot '.cache'
if(-not $RunName){$RunName=[DateTime]::UtcNow.ToString('yyyyMMdd-HHmmssfffffff')}
if($RunName.StartsWith('formal-',[StringComparison]::Ordinal)){$RunName=$RunName.Substring(7)}
if($RunName -notmatch '^[a-z0-9][a-z0-9-]*$'){throw 'RunName must contain only lower-case letters, numbers and hyphens'}
$runPrefix='formal-'+$RunName
$modelTarget=Join-Path $project 'Assets/StreamingAssets/Original/models.unity3d'

function Fingerprint([string]$Path){
    $item=Get-Item -LiteralPath $Path
    [pscustomobject]@{path=$item.FullName;bytes=$item.Length;sha256=(Get-FileHash -LiteralPath $item.FullName -Algorithm SHA256).Hash.ToLowerInvariant()}
}

function AssertModels([string]$Path){
    if(-not (Test-Path -LiteralPath $Path -PathType Leaf)){throw ('Original model bundle is absent: '+$Path+'. Run -Action Prepare with a verified -Models source.')}
    $identity=Fingerprint $Path
    if($identity.bytes -ne $expectedModelBytes -or $identity.sha256 -ne $expectedModels){throw ('Original model bundle fingerprint differs; existing file retained: '+$Path)}
    $identity
}

function ProjectEditors {
    foreach($candidate in @(Get-CimInstance Win32_Process -Filter "Name='Unity.exe' OR Name='Tuanjie.exe'")){
        $match=[regex]::Match([string]$candidate.CommandLine,'(?i)(?:^|\s)-projectPath(?:\s+|=)(?:"([^"]+)"|(\S+))')
        if(-not $match.Success){continue}
        $claimed=if($match.Groups[1].Success){$match.Groups[1].Value}else{$match.Groups[2].Value}
        if([string]::Equals([IO.Path]::GetFullPath($claimed).TrimEnd('\','/'),$project,[StringComparison]::OrdinalIgnoreCase)){$candidate}
    }
}

function AssertProject {
    foreach($relative in @('Assets','Packages/manifest.json','Packages/packages-lock.json','ProjectSettings/ProjectVersion.txt','ProjectSettings/ProjectSettings.asset')){
        if(-not (Test-Path -LiteralPath (Join-Path $project $relative))){throw ('Incomplete version-controlled Unity project: '+$relative)}
    }
    if($configuration.product -ne 'Unity' -or $configuration.editor_version -ne '6000.6.7f1'){throw 'The formal project requires the selected Unity 6000.6.7f1 editor'}
    if(-not (Test-Path -LiteralPath $editor -PathType Leaf)){throw ('Unity editor is absent: '+$editor)}
    $productVersion=(Get-Item -LiteralPath $editor).VersionInfo.ProductVersion
    if(-not $productVersion.StartsWith($configuration.editor_version+'_',[StringComparison]::Ordinal)){throw 'Installed and selected Unity editor versions differ'}
    $version=Get-Content -LiteralPath (Join-Path $project 'ProjectSettings/ProjectVersion.txt') -Raw
    if($version -notmatch ('(?m)^m_EditorVersion: '+[regex]::Escape($configuration.editor_version)+'\r?$')){throw 'Formal project version differs from the selected editor'}
    $playerSettings=Get-Content -LiteralPath (Join-Path $project 'ProjectSettings/ProjectSettings.asset') -Raw
    if($playerSettings -notmatch '(?m)^\s*activeInputHandler:\s*0\s*\r?$'){throw 'Legacy Input Manager (activeInputHandler=0) is required; settings were not rewritten'}
}

function SourceSnapshot {
    $files=@(foreach($tree in @('Assets','Packages','ProjectSettings')){
        foreach($item in @(Get-ChildItem -LiteralPath (Join-Path $project $tree) -Recurse -File)){
            # The large, ignored original model bundle is independently pinned.
            # Its .meta remains in this snapshot so its GUID cannot change silently.
            if([string]::Equals($item.FullName,$modelTarget,[StringComparison]::OrdinalIgnoreCase)){continue}
            $identity=Fingerprint $item.FullName
            [pscustomobject]@{path=$item.FullName.Substring($project.Length+1).Replace('\','/');bytes=$identity.bytes;sha256=$identity.sha256}
        }
    })
    $files=@($files | Sort-Object path)
    [pscustomobject]@{schema_version=1;project=$project;excluded_file='Assets/StreamingAssets/Original/models.unity3d';file_count=$files.Count;files=$files}
}

function SnapshotDifferences($Before,$After){
    $previous=@{}; $current=@{}
    foreach($row in $Before.files){$previous[$row.path]=$row.sha256+':'+$row.bytes}
    foreach($row in $After.files){$current[$row.path]=$row.sha256+':'+$row.bytes}
    foreach($path in @(@($previous.Keys)+@($current.Keys) | Sort-Object -Unique)){
        if(-not $previous.ContainsKey($path)){[pscustomobject]@{path=$path;change='added'}}
        elseif(-not $current.ContainsKey($path)){[pscustomobject]@{path=$path;change='removed'}}
        elseif($previous[$path] -ne $current[$path]){[pscustomobject]@{path=$path;change='modified'}}
    }
}

AssertProject
if($Action -eq 'Prepare'){
    if(Test-Path -LiteralPath $modelTarget -PathType Leaf){
        $verified=AssertModels $modelTarget
        [pscustomobject]@{status='already-prepared';project=$project;copied=$false;model=$verified} | ConvertTo-Json -Depth 5
        return
    }
    $source=[IO.Path]::GetFullPath($Models)
    $sourceIdentity=AssertModels $source
    New-Item -ItemType Directory -Path ([IO.Path]::GetDirectoryName($modelTarget)) -Force | Out-Null
    # CreateNew makes even a concurrently-created target an error, never an overwrite.
    $modelStream=[IO.File]::OpenRead($source)
    try{
        $outputStream=New-Object IO.FileStream($modelTarget,[IO.FileMode]::CreateNew,[IO.FileAccess]::Write,[IO.FileShare]::None)
        try{$modelStream.CopyTo($outputStream);$outputStream.Flush($true)}finally{$outputStream.Dispose()}
    }finally{$modelStream.Dispose()}
    $verified=AssertModels $modelTarget
    [pscustomobject]@{status='prepared';project=$project;copied=$true;source=$sourceIdentity;model=$verified;scope='Only the ignored original model bundle was supplied; version-controlled scenes, source and settings were not copied or modified'} | ConvertTo-Json -Depth 5
    return
}
$modelIdentity=AssertModels $modelTarget
if($Action -eq 'Validate'){
    $snapshot=SourceSnapshot
    [pscustomobject]@{status='formal-project-inputs-verified';project=$project;editor=$editor;editor_version=$configuration.editor_version;source_file_count=$snapshot.file_count;model=$modelIdentity;scope='Disk prerequisites only; Unity compilation and build settings are validated inside ProjectBuild.Build'} | ConvertTo-Json -Depth 5
    return
}
$active=@(ProjectEditors)
if($Action -eq 'Open'){
    if($active.Count){
        if(@($active | Where-Object {-not [string]::Equals($_.ExecutablePath,$editor,[StringComparison]::OrdinalIgnoreCase)}).Count){throw 'This project is already open in a different editor'}
        $active | ForEach-Object {$_.ProcessId}
        return
    }
    $record=Join-Path $cache ($runPrefix+'-open-'+[DateTime]::UtcNow.ToString('yyyyMMddTHHmmssfffffffZ'))
    New-Item -ItemType Directory -Path $record -Force | Out-Null
    $arguments=@('-projectPath',('"'+$project+'"'),'-logFile',('"'+(Join-Path $record 'editor.log')+'"'))
    $opened=Start-Process -FilePath $editor -ArgumentList $arguments -WindowStyle Normal -PassThru
    [pscustomobject]@{pid=$opened.Id;started_utc=[DateTime]::UtcNow.ToString('o');editor=$editor;project=$project;arguments=$arguments;scope='Open the formal version-controlled project; no source synchronization or automatic Play'} | ConvertTo-Json -Depth 4 | Set-Content -Encoding utf8 (Join-Path $record 'start.json')
    $opened.Id
    return
}
if($active.Count){throw 'Close the formal project editor normally before a batch build; other Unity projects may remain open'}
$output=Join-Path $cache ($runPrefix+'-build')
$record=Join-Path $cache ($runPrefix+'-build-record')
if((Test-Path -LiteralPath $output) -or (Test-Path -LiteralPath $record)){throw 'Build output or receipt already exists; choose a fresh RunName'}
$before=SourceSnapshot
New-Item -ItemType Directory -Path $record -Force | Out-Null
$before | ConvertTo-Json -Depth 5 | Set-Content -Encoding utf8 (Join-Path $record 'sources-before.json')
$exe=Join-Path $output 'ManakaInteraction.exe'
$log=Join-Path $record 'editor.log'
$arguments=@('-batchmode','-nographics','-quit','-projectPath',('"'+$project+'"'),'-executeMethod','ReconstructedManaka.Editor.ProjectBuild.Build','--output',('"'+$exe+'"'),'-logFile',('"'+$log+'"'))
$buildProcess=Start-Process -FilePath $editor -ArgumentList $arguments -WindowStyle Hidden -RedirectStandardOutput (Join-Path $record 'stdout.log') -RedirectStandardError (Join-Path $record 'stderr.log') -PassThru
$buildHandle=$buildProcess.Handle
[pscustomobject]@{pid=$buildProcess.Id;started_utc=[DateTime]::UtcNow.ToString('o');editor=$editor;editor_identity=(Fingerprint $editor);project=$project;output=$output;executable=$exe;arguments=$arguments;model=$modelIdentity;process_handle_retained=($buildHandle -ne [IntPtr]::Zero);source_file_count=$before.file_count;scope='Build saved version-controlled scenes in place; never copy template sources, create scenes, save scenes or rewrite settings'} | ConvertTo-Json -Depth 5 | Set-Content -Encoding utf8 (Join-Path $record 'start.json')
$buildProcess.Id
$buildProcess.WaitForExit()
$buildProcess.Refresh()
$observedExit=$buildProcess.ExitCode
$after=SourceSnapshot
$after | ConvertTo-Json -Depth 5 | Set-Content -Encoding utf8 (Join-Path $record 'sources-after.json')
$differences=@(SnapshotDifferences $before $after)
$receipt=[pscustomobject]@{pid=$buildProcess.Id;exited_utc=[DateTime]::UtcNow.ToString('o');exit_code=$observedExit;exit_code_observed=($null -ne $observedExit);process_exited=$buildProcess.HasExited;executable_exists=(Test-Path -LiteralPath $exe);source_file_count_before=$before.file_count;source_file_count_after=$after.file_count;sources_unchanged=($differences.Count -eq 0);source_differences=$differences;scope='Byte hashes cover all Assets, Packages and ProjectSettings files except the independently verified model bundle; no automatic rollback over user edits'}
$receipt | ConvertTo-Json -Depth 5 | Set-Content -Encoding utf8 (Join-Path $record 'exit.json')
if($differences.Count){throw ('Build changed version-controlled project content; inspect preserved snapshots and exit receipt: '+$record)}
if($null -eq $observedExit -or -not $buildProcess.HasExited -or $observedExit -ne 0 -or -not $receipt.executable_exists){throw ('Build did not produce an observed OS exit code 0 and executable: '+$record)}
$receipt | ConvertTo-Json -Depth 5
