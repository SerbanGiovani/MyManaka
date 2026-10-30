param([switch]$EmitOnly)
$ErrorActionPreference='Stop'
# Emit-only: never installs or overwrites a loaded plugin.
$root=(Resolve-Path (Join-Path $PSScriptRoot '../../..')).Path
$cache=Join-Path $PSScriptRoot '.cache'
New-Item -ItemType Directory -Path $cache -Force|Out-Null
$env:DOTNET_CLI_HOME=Join-Path $cache 'dotnet-home'
$env:APPDATA=Join-Path $cache 'appdata'
$env:NUGET_PACKAGES=Join-Path $cache 'nuget'
$env:DOTNET_SKIP_FIRST_TIME_EXPERIENCE='1'
$refs=@()
foreach($dll in Get-ChildItem (Join-Path $root 'dotnet') -Filter '*.dll'){try{[Reflection.AssemblyName]::GetAssemblyName($dll.FullName)|Out-Null;$refs+="/reference:$($dll.FullName)"}catch{}}
foreach($dll in @('BepInEx.Core','BepInEx.Unity.IL2CPP','0Harmony','Il2CppInterop.Runtime')){$refs+="/reference:$(Join-Path $root "BepInEx/core/$dll.dll")"}
foreach($dll in Get-ChildItem (Join-Path $root 'BepInEx/interop') -Filter '*.dll'){$refs+="/reference:$($dll.FullName)"}
$out=Join-Path $cache 'TimedBodyPaintProbe.dll'
$csc=Get-ChildItem 'C:/Program Files/dotnet/sdk/*/Roslyn/bincore/csc.dll'|Sort-Object FullName -Descending|Select-Object -First 1
dotnet $csc.FullName /noconfig /target:library /langversion:latest /nullable:disable "/out:$out" $refs (Join-Path $PSScriptRoot 'Probe.cs')
if($LASTEXITCODE -ne 0){throw 'Compile failed'}
[pscustomobject]@{emit_only=$true;installed=$false;emitted_path=$out;sha256=(Get-FileHash -LiteralPath $out -Algorithm SHA256).Hash.ToLowerInvariant()}|ConvertTo-Json -Compress
