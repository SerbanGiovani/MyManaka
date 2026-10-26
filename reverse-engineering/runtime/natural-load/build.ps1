param([string]$GameRoot='E:\ManakaREA-NaturalGameplay')
$ErrorActionPreference='Stop'
$root=(Resolve-Path (Join-Path $PSScriptRoot '../../..')).Path
$env:DOTNET_CLI_HOME=Join-Path $root '.dotnet_home';$env:APPDATA=Join-Path $root '.appdata'
$env:NUGET_PACKAGES=Join-Path $root '.nuget_packages';$env:DOTNET_SKIP_FIRST_TIME_EXPERIENCE='1'
if(Get-Process -Name SecretFlasherManaka -ErrorAction SilentlyContinue|Where-Object {$_.Path -eq (Join-Path $GameRoot 'SecretFlasherManaka.exe')}){throw 'Close test instance before compiling'}
if(Get-ChildItem (Join-Path $GameRoot 'BepInEx/plugins') -Force -Filter '*_NaturalLoadObserver.dll'){throw 'Hidden duplicate assembly'}
$refs=@()
foreach($dll in Get-ChildItem (Join-Path $root 'dotnet') -Filter '*.dll'){try{[Reflection.AssemblyName]::GetAssemblyName($dll.FullName)|Out-Null;$refs+="/reference:$($dll.FullName)"}catch{}}
foreach($dll in @('BepInEx.Core','BepInEx.Unity.IL2CPP','0Harmony','Il2CppInterop.Runtime')){$refs+="/reference:$(Join-Path $root "BepInEx/core/$dll.dll")"}
foreach($dll in Get-ChildItem (Join-Path $root 'BepInEx/interop') -Filter '*.dll'){$refs+="/reference:$($dll.FullName)"}
$out=Join-Path $GameRoot 'BepInEx/plugins/NaturalLoadObserver.dll'
$csc=Get-ChildItem 'C:/Program Files/dotnet/sdk/*/Roslyn/bincore/csc.dll'|Sort-Object FullName -Descending|Select-Object -First 1
dotnet $csc.FullName /noconfig /target:library /langversion:latest /nullable:disable "/out:$out" $refs (Join-Path $PSScriptRoot 'Observe.cs')
if($LASTEXITCODE -ne 0){throw 'Compile failed'}
$bin=Join-Path $PSScriptRoot '.cache/bin/Release/net6.0';New-Item -ItemType Directory -Path $bin -Force|Out-Null
Copy-Item -LiteralPath $out -Destination (Join-Path $bin 'NaturalLoadObserver.dll');Get-FileHash -LiteralPath $out
