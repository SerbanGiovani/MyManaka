param([string]$FixtureRoot='E:\ManakaREA-TimeStopFixture')
$ErrorActionPreference='Stop'
$root=(Resolve-Path (Join-Path $PSScriptRoot '..\..\..')).Path
$env:DOTNET_CLI_HOME=Join-Path $root '.dotnet_home'
$env:APPDATA=Join-Path $root '.appdata'
$env:NUGET_PACKAGES=Join-Path $root '.nuget_packages'
$env:DOTNET_SKIP_FIRST_TIME_EXPERIENCE='1'
$out=Join-Path $FixtureRoot 'BepInEx\plugins\TimeStopProducerFixture.dll'
$refs=@()
foreach($dll in Get-ChildItem -LiteralPath (Join-Path $root 'dotnet') -Filter '*.dll') {
 try { [Reflection.AssemblyName]::GetAssemblyName($dll.FullName)|Out-Null; $refs+="/reference:$($dll.FullName)" } catch {}
}
foreach($dll in @('BepInEx.Core','BepInEx.Unity.IL2CPP','0Harmony','Il2CppInterop.Runtime')) {$refs+="/reference:$(Join-Path $root "BepInEx\core\$dll.dll")"}
foreach($dll in @('Assembly-CSharp','Il2Cppmscorlib','UnityEngine.CoreModule','UnityEngine.AnimationModule','UnityEngine.AssetBundleModule','UnityEngine.AudioModule','UnityEngine.PhysicsModule','UnityEngine.ParticleSystemModule')) {$refs+="/reference:$(Join-Path $root "BepInEx\interop\$dll.dll")"}
$csc=Get-ChildItem 'C:\Program Files\dotnet\sdk\*\Roslyn\bincore\csc.dll' | Sort-Object FullName -Descending | Select-Object -First 1
if(!$csc){throw 'Roslyn compiler not found'}
dotnet $csc.FullName /noconfig /target:library /langversion:latest /nullable:disable "/out:$out" $refs (Join-Path $PSScriptRoot 'Probe.cs')
if($LASTEXITCODE -ne 0){throw 'Probe compilation failed'}
Get-FileHash -LiteralPath $out -Algorithm SHA256
