param([string]$GameRoot='E:\ManakaREA-NaturalGameplay',[switch]$EmitOnly)
$ErrorActionPreference='Stop'
$root=(Resolve-Path (Join-Path $PSScriptRoot '../../..')).Path
$env:DOTNET_CLI_HOME=Join-Path $root '.dotnet_home'
$env:APPDATA=Join-Path $root '.appdata'
$env:NUGET_PACKAGES=Join-Path $root '.nuget_packages'
$env:DOTNET_SKIP_FIRST_TIME_EXPERIENCE='1'
$cache=Join-Path $PSScriptRoot '.cache'
New-Item -ItemType Directory -Path $cache -Force|Out-Null
$target=Join-Path $GameRoot 'BepInEx/plugins/AppearanceBoundaryProbe.dll'
if(-not $EmitOnly){
 $probeExe=[IO.Path]::GetFullPath((Join-Path $GameRoot 'SecretFlasherManaka.exe'))
 if(Get-Process -Name SecretFlasherManaka -ErrorAction SilentlyContinue|Where-Object {$_.Path -eq $probeExe}){throw 'Loaded test process present; use -EmitOnly or close it before installation'}
 if(Test-Path -LiteralPath $target){throw 'Archive the previous AppearanceBoundaryProbe.dll outside plugins before installing a new build'}
 $duplicates=Get-ChildItem (Join-Path $GameRoot 'BepInEx/plugins') -Force -Filter '*_AppearanceBoundaryProbe.dll'
 if($duplicates){throw 'Archive hidden AppearanceBoundaryProbe assemblies before installation'}
}
$refs=@()
foreach($dll in Get-ChildItem (Join-Path $root 'dotnet') -Filter '*.dll'){try{[Reflection.AssemblyName]::GetAssemblyName($dll.FullName)|Out-Null;$refs+="/reference:$($dll.FullName)"}catch{}}
foreach($dll in @('BepInEx.Core','BepInEx.Unity.IL2CPP','0Harmony','Il2CppInterop.Runtime')){$refs+="/reference:$(Join-Path $root "BepInEx/core/$dll.dll")"}
foreach($dll in Get-ChildItem (Join-Path $root 'BepInEx/interop') -Filter '*.dll'){$refs+="/reference:$($dll.FullName)"}
$out=Join-Path $cache 'AppearanceBoundaryProbe.dll'
$csc=Get-ChildItem 'C:/Program Files/dotnet/sdk/*/Roslyn/bincore/csc.dll'|Sort-Object FullName -Descending|Select-Object -First 1
dotnet $csc.FullName /noconfig /target:library /langversion:latest /nullable:disable "/out:$out" $refs (Join-Path $PSScriptRoot 'Probe.cs')
if($LASTEXITCODE -ne 0){throw 'Compile failed'}
if(-not $EmitOnly){Copy-Item -LiteralPath $out -Destination $target}
[pscustomobject]@{emit_only=[bool]$EmitOnly;emitted_path=$out;installed=(-not $EmitOnly);sha256=(Get-FileHash -LiteralPath $out -Algorithm SHA256).Hash.ToLowerInvariant()}
