param([string]$GameRoot='E:\ManakaREA-NaturalGameplay',[switch]$EmitOnly,[switch]$Install)
$ErrorActionPreference='Stop'
if($EmitOnly -and $Install){throw 'Choose EmitOnly or Install'}
$root=(Resolve-Path (Join-Path $PSScriptRoot '../../..')).Path
$env:DOTNET_CLI_HOME=Join-Path $root '.dotnet_home'
$env:APPDATA=Join-Path $root '.appdata'
$env:NUGET_PACKAGES=Join-Path $root '.nuget_packages'
$env:DOTNET_SKIP_FIRST_TIME_EXPERIENCE='1'
# Emission is the default; never install or replace a loaded DLL implicitly.
$bin=Join-Path $PSScriptRoot '.cache'
New-Item -ItemType Directory -Path $bin -Force|Out-Null
$out=Join-Path $bin 'PaidSkillBoundaryProbe.dll'
if($Install){
 $probeExe=Join-Path $GameRoot 'SecretFlasherManaka.exe'
 if(Get-Process -Name SecretFlasherManaka -ErrorAction SilentlyContinue | Where-Object {$_.Path -eq $probeExe}){throw 'Close the independent test instance before installing'}
 $duplicates=Get-ChildItem (Join-Path $GameRoot 'BepInEx/plugins') -Force -Filter '*PaidSkillBoundaryProbe*.dll'
 if($duplicates){throw 'Archive all prior paid-skill probe DLLs outside plugins before installing'}
}
$refs=@()
foreach($dll in Get-ChildItem (Join-Path $root 'dotnet') -Filter '*.dll'){try{[Reflection.AssemblyName]::GetAssemblyName($dll.FullName)|Out-Null;$refs+="/reference:$($dll.FullName)"}catch{}}
foreach($dll in @('BepInEx.Core','BepInEx.Unity.IL2CPP','0Harmony','Il2CppInterop.Runtime')){$refs+="/reference:$(Join-Path $root "BepInEx/core/$dll.dll")"}
foreach($dll in Get-ChildItem (Join-Path $root 'BepInEx/interop') -Filter '*.dll'){$refs+="/reference:$($dll.FullName)"}
$csc=Get-ChildItem 'C:/Program Files/dotnet/sdk/*/Roslyn/bincore/csc.dll'|Sort-Object FullName -Descending|Select-Object -First 1
dotnet $csc.FullName /noconfig /target:library /langversion:latest /nullable:disable "/out:$out" $refs (Join-Path $PSScriptRoot 'Probe.cs')
if($LASTEXITCODE -ne 0){throw 'Compile failed'}
if($Install){Copy-Item -LiteralPath $out -Destination (Join-Path $GameRoot 'BepInEx/plugins/PaidSkillBoundaryProbe.dll')}
Get-FileHash -LiteralPath $out
