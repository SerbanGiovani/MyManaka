param([Parameter(Mandatory=$true)][string]$GameRoot,[string]$OriginalRoot='E:\SecretFlasherManakaREA',[Parameter(Mandatory=$true)][string]$SourceSaveRoot)
$ErrorActionPreference='Stop'
$dest=[IO.Path]::GetFullPath($GameRoot).TrimEnd('\')
$source=(Resolve-Path -LiteralPath $OriginalRoot).Path.TrimEnd('\')
if(Test-Path -LiteralPath $dest){throw 'Use a new directory; preserve prior runs'}
if($dest.StartsWith($source+'\',[StringComparison]::OrdinalIgnoreCase)){throw 'Choose a directory outside the original snapshot'}
if((Get-FileHash -LiteralPath (Join-Path $source 'GameAssembly.dll')).Hash -ne '6003033049ac32e8712dc4101382534e21d65b97100c167ebec6bbca1462c18d'){throw 'Native build differs'}
New-Item -ItemType Directory -Path $dest | Out-Null
foreach($f in @('SecretFlasherManaka.exe','UnityPlayer.dll','GameAssembly.dll','baselib.dll','winhttp.dll','doorstop_config.ini','.doorstop_version')){Copy-Item -LiteralPath (Join-Path $source $f) -Destination $dest}
foreach($d in @('SecretFlasherManaka_Data','dotnet','BepInEx/core','BepInEx/interop','BepInEx/unity-libs')){
 robocopy (Join-Path $source $d) (Join-Path $dest $d) /E /NFL /NDL /NJH /NJS /R:1 /W:1 | Out-Null
 if($LASTEXITCODE -ge 8){throw "Copy failed: $d"}
}
foreach($d in @('BepInEx/plugins','BepInEx/config','UserData')){New-Item -ItemType Directory -Path (Join-Path $dest $d)|Out-Null}
@'
[Logging.Console]
Enabled = false
[Logging]
UnityLogListening = true
[Logging.Disk]
WriteUnityLog = true
[IL2CPP]
UpdateInteropAssemblies = false
PreloadIL2CPPInteropAssemblies = true
'@ | Set-Content -LiteralPath (Join-Path $dest 'BepInEx/config/BepInEx.cfg')
foreach($d in @('SaveData','SaveDataBackup','InputActionOverrides.json')){
 $p=Join-Path $SourceSaveRoot $d
 if(Test-Path -LiteralPath $p){Copy-Item -LiteralPath $p -Destination (Join-Path $dest 'UserData') -Recurse}
}
Get-ChildItem -LiteralPath $SourceSaveRoot -File -Recurse|ForEach-Object{[ordered]@{path=$_.FullName;sha256=(Get-FileHash -LiteralPath $_.FullName).Hash}}|ConvertTo-Json|Set-Content -LiteralPath (Join-Path $dest 'source-save-hashes.json')
& (Join-Path $PSScriptRoot 'build.ps1') -GameRoot $dest
