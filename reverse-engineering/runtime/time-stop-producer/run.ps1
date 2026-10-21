param([string]$FixtureRoot='E:\ManakaREA-TimeStopFixture',[int]$TimeoutSeconds=360)
$ErrorActionPreference='Stop'
$fixture=(Resolve-Path -LiteralPath $FixtureRoot).Path
$exe=Join-Path $fixture 'SecretFlasherManaka.exe'
if(!(Test-Path -LiteralPath (Join-Path $fixture 'BepInEx\plugins\TimeStopProducerFixture.dll'))){throw 'Build the fixture first'}
if(Get-Process SecretFlasherManaka -ErrorAction SilentlyContinue | Where-Object Path -eq $exe){throw 'This fixture is already running'}
$stamp=Get-Date -Format 'yyyyMMdd-HHmmss-fff'
$archive=Join-Path $fixture "runs\$stamp"
New-Item -ItemType Directory -Force -Path $archive | Out-Null
foreach($name in @('go','fixture.jsonl','Player-fixture.log','BepInEx\LogOutput.log')) {
    $path=Join-Path $fixture $name
    if(Test-Path -LiteralPath $path){Move-Item -LiteralPath $path -Destination (Join-Path $archive ([IO.Path]::GetFileName($name)))}
}
$playerLog=Join-Path $fixture 'Player-fixture.log'
$launchArgs=@('-screen-fullscreen','0','-screen-width','640','-screen-height','480','-logFile',('"'+$playerLog+'"'))
$p=Start-Process -FilePath $exe -WorkingDirectory $fixture -WindowStyle Hidden -ArgumentList $launchArgs -PassThru
Write-Output "PID=$($p.Id); attach REA scripts, then create $(Join-Path $fixture 'go')"
$started=Get-Date
try {
    while(!$p.WaitForExit(1000)) {
        if(((Get-Date)-$started).TotalSeconds -ge $TimeoutSeconds){throw 'Fixture timeout'}
    }
    [ordered]@{pid=$p.Id;exit_code=$p.ExitCode;start=$started.ToString('o');end=(Get-Date).ToString('o')} |
        ConvertTo-Json | Set-Content -LiteralPath (Join-Path $archive 'process.json')
} finally {
    if(!$p.HasExited){$p.CloseMainWindow()|Out-Null;if(!$p.WaitForExit(5000)){Stop-Process -Id $p.Id;$p.WaitForExit(5000)|Out-Null}}
}
