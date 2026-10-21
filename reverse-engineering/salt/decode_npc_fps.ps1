param(
    [string]$InputPath = "$PSScriptRoot/.cache/npc-fps-decoder-input.json",
    [string]$OutputPath = "$PSScriptRoot/symbols/npc-fps-instructions.json"
)
$ErrorActionPreference = 'Stop'
$inputRecord = Get-Content -Raw -LiteralPath $InputPath | ConvertFrom-Json
$nativePath = $inputRecord.native.path
$decoderPath = $inputRecord.decoder.path
if ((Get-FileHash -LiteralPath $nativePath -Algorithm SHA256).Hash.ToLowerInvariant() -ne $inputRecord.native.sha256) { throw 'Native fingerprint differs' }
if ((Get-FileHash -LiteralPath $decoderPath -Algorithm SHA256).Hash.ToLowerInvariant() -ne $inputRecord.decoder.sha256) { throw 'Decoder fingerprint differs' }
[void][Reflection.Assembly]::LoadFrom($decoderPath)
$nativeBytes = [IO.File]::ReadAllBytes($nativePath)
$decoded = foreach ($range in $inputRecord.ranges) {
    $bytes = [byte[]]::new([int]$range.size)
    [Array]::Copy($nativeBytes, [long]$range.file_offset, $bytes, 0, $bytes.Length)
    $startVa = [Convert]::ToUInt64($range.begin.Substring(2), 16)
    $decoder = [Iced.Intel.Decoder]::Create(64, $bytes, $startVa, [Iced.Intel.DecoderOptions]::None)
    $rows = while ($decoder.IP -lt ($startVa + $bytes.Length)) {
        $instruction = $decoder.Decode()
        if ($instruction.IsInvalid -or $instruction.Length -eq 0) { throw "Invalid instruction at $($decoder.IP)" }
        $position = [int]($instruction.IP - $startVa)
        if ($position + $instruction.Length -gt $bytes.Length) { throw 'Instruction exceeds range' }
        $raw = [byte[]]::new($instruction.Length)
        [Array]::Copy($bytes, $position, $raw, 0, $raw.Length)
        [ordered]@{
            va = ('0x{0:x}' -f $instruction.IP)
            file_offset = [long]$range.file_offset + $position
            raw_hex = [Convert]::ToHexString($raw).ToLowerInvariant()
            length = $instruction.Length
            text = $instruction.ToString()
            mnemonic = $instruction.Mnemonic.ToString()
            flow_control = $instruction.FlowControl.ToString()
            ip_relative_memory_address = $(if ($instruction.IsIPRelativeMemoryOperand) { '0x{0:x}' -f $instruction.IPRelativeMemoryAddress } else { $null })
            direct_branch_target = $(if ($instruction.IsCallNear -or $instruction.IsJmpShortOrNear -or $instruction.IsJccShortOrNear) { '0x{0:x}' -f $instruction.NearBranchTarget } else { $null })
        }
    }
    [ordered]@{ method_id = $range.method_id; requested_va = $range.requested_va; begin = $range.begin
        end_exclusive = $range.end_exclusive; pdata_file_offset = $range.pdata_file_offset
        pdata_raw_hex = $range.pdata_raw_hex; unwind_chain = $range.unwind_chain; instructions = @($rows) }
}
$result = [ordered]@{
    schema_version = 1
    evidence_type = 'Supplemental Iced static x64 decoding of original PE unwind ranges; not REA output or runtime registers'
    native = $inputRecord.native
    decoder = $inputRecord.decoder
    preparer = $inputRecord.preparer
    parser = [ordered]@{ path = $PSCommandPath; sha256 = (Get-FileHash -LiteralPath $PSCommandPath -Algorithm SHA256).Hash.ToLowerInvariant() }
    ranges = @($decoded)
    boundary = 'Linear instruction decoding within pinned PE unwind ranges, not execution, data-flow emulation or a complete call graph. Register arguments require manual ABI/value-flow interpretation.'
}
[IO.File]::WriteAllText($OutputPath, (($result | ConvertTo-Json -Depth 12) + "`n"), [Text.UTF8Encoding]::new($false))
Write-Output "Saved $(@($decoded).Count) instruction ranges"
