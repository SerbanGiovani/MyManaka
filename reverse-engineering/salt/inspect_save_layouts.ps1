$ErrorActionPreference = 'Stop'
$taskOriginal = 'E:/SecretFlasherManakaREA'
$taskCecil = Join-Path $taskOriginal 'BepInEx/core/Mono.Cecil.dll'
$taskParser = Join-Path $taskOriginal 'BepInEx/core/LibCpp2IL.dll'
[void][Reflection.Assembly]::LoadFrom($taskCecil)
$taskAssembly = [Mono.Cecil.AssemblyDefinition]::ReadAssembly($taskParser)
$taskNames = @('Il2CppCodeRegistration','Il2CppGenericMethodFunctionsDefinitions','Il2CppGenericMethodIndices','Il2CppGenericClass','Il2CppGenericContext','Il2CppGlobalMetadataHeader','Il2CppCustomAttributeDataRange','Il2CppCustomAttributeTypeRange')
$taskTypes = foreach ($taskType in $taskAssembly.MainModule.Types) {
    if ($taskType.Name -notin $taskNames) { continue }
    [ordered]@{
        name = $taskType.FullName
        fields = @($taskType.Fields | ForEach-Object {
            [ordered]@{ name = $_.Name; type = $_.FieldType.FullName; attributes = @($_.CustomAttributes | ForEach-Object {
                [ordered]@{ type = $_.AttributeType.FullName; arguments = @($_.ConstructorArguments | ForEach-Object { "$($_.Value)" }); named_fields = @($_.Fields | ForEach-Object { "$($_.Name)=$($_.Argument.Value)" }); named_properties = @($_.Properties | ForEach-Object { "$($_.Name)=$($_.Argument.Value)" }) }
            }) }
        })
        read_il = @($taskType.Methods | Where-Object { $_.Name -eq 'Read' -and $_.HasBody } | ForEach-Object { $_.Body.Instructions | ForEach-Object {
            [ordered]@{ offset=$_.Offset; opcode=$_.OpCode.Name; operand=$(if ($null -eq $_.Operand) { $null } else { $_.Operand.ToString() }) }
        } })
    }
}
$taskSources = @($taskCecil,$taskParser,$PSCommandPath) | ForEach-Object { [ordered]@{ path=$_; sha256=(Get-FileHash -LiteralPath $_ -Algorithm SHA256).Hash.ToLowerInvariant() } }
$taskResult = [ordered]@{ schema_version=1; evidence_type='Cecil read-only parser declaration/IL corroboration; no parser or game methods executed'; sources=@($taskSources); types=@($taskTypes) }
$taskOutput = Join-Path $PSScriptRoot 'symbols/save-parser-layouts.json'
[IO.File]::WriteAllText($taskOutput, (($taskResult | ConvertTo-Json -Depth 14) + "`n"), [Text.UTF8Encoding]::new($false))
$taskAssembly.Dispose()
Write-Output "Saved $(@($taskTypes).Count) parser layouts"
