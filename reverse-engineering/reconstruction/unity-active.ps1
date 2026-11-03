param(
    [ValidateSet('Prepare','Validate','Build','Open')][string]$Action='Open',
    [string]$RunName,
    [string]$ProjectPath,
    [string]$Models
)
$ErrorActionPreference='Stop'
$parameters=@{Action=$Action;Settings=(Join-Path $PSScriptRoot 'unity-active-settings.json')}
if($RunName){$parameters.RunName=$RunName}
if($ProjectPath){$parameters.ProjectPath=$ProjectPath}
if($Models){$parameters.Models=$Models}
& (Join-Path $PSScriptRoot 'unity-project.ps1') @parameters
