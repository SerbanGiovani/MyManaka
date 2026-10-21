param([string]$OriginalRoot='E:\SecretFlasherManakaREA', [Parameter(Mandatory=$true)][string]$FixtureRoot, [string]$ModelsPath=(Join-Path $PSScriptRoot "../../salt/.cache/decrypted/models.unity3d"))
$ErrorActionPreference='Stop'
if((Get-FileHash -LiteralPath $ModelsPath).Hash -ne '98621b2c4fa4f9de80f355fae5776ab17efc016bcc81c581bcd0917af4308367'){throw 'Use the pinned decrypted models bundle'}
$original=(Resolve-Path -LiteralPath $OriginalRoot).Path.TrimEnd('\')
$fixture=[IO.Path]::GetFullPath($FixtureRoot).TrimEnd('\')
if(Test-Path -LiteralPath $fixture){throw 'Choose a new fixture directory; existing directories are preserved'}
if($fixture.StartsWith($original+'\',[StringComparison]::OrdinalIgnoreCase)){throw 'Fixture must be outside the original snapshot'}
$expected='6003033049ac32e8712dc4101382534e21d65b97100c167ebec6bbca1462c18d'
if((Get-FileHash -LiteralPath (Join-Path $original 'GameAssembly.dll')).Hash -ne $expected){throw 'Unexpected native build'}
New-Item -ItemType Directory -Path $fixture | Out-Null
foreach($f in @('SecretFlasherManaka.exe','UnityPlayer.dll','GameAssembly.dll','baselib.dll','winhttp.dll','doorstop_config.ini','.doorstop_version')) {
    $source=Join-Path $original $f
    if(Test-Path -LiteralPath $source){Copy-Item -LiteralPath $source -Destination $fixture}
}
foreach($dir in @('SecretFlasherManaka_Data','dotnet','BepInEx\core','BepInEx\interop','BepInEx\unity-libs')) {
    & robocopy (Join-Path $original $dir) (Join-Path $fixture $dir) /E /NFL /NDL /NJH /NJS /R:1 /W:1 | Out-Null
    if($LASTEXITCODE -ge 8){throw "Failed to copy $dir"}
}
New-Item -ItemType Directory -Path (Join-Path $fixture 'BepInEx\plugins'),(Join-Path $fixture 'BepInEx\config') | Out-Null
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
'@ | Set-Content -LiteralPath (Join-Path $fixture 'BepInEx\config\BepInEx.cfg')
Copy-Item -LiteralPath $ModelsPath -Destination (Join-Path $fixture 'models.unity3d')
& (Join-Path $PSScriptRoot 'build.ps1') -FixtureRoot $fixture
if($LASTEXITCODE -ne 0){throw 'Build failed'}
Write-Output "Prepared $fixture"
