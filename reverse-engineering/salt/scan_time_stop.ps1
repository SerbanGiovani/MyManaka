param([string]$OutputPath="$PSScriptRoot/symbols/time-stop-xrefs.json")
$ErrorActionPreference='Stop'
$nativePath='E:\SecretFlasherManakaREA\GameAssembly.dll'
$decoderPath='E:\SecretFlasherManakaREA\BepInEx\core\Iced.dll'
[void][Reflection.Assembly]::LoadFrom($decoderPath)
$code=@'
using System;
using System.Collections.Generic;
using Iced.Intel;
public class StopScanRow {
 public string begin {get;set;} public string end {get;set;}
 public string[] event_slot_refs {get;set;} public string[] game_slot_refs {get;set;}
 public string[] event_field_candidates {get;set;} public string[] stop_field_write_candidates {get;set;}
}
public class StopScanResult {public int unwind_ranges {get;set;} public long instructions {get;set;} public StopScanRow[] candidates {get;set;}}
public static class StopScanner {
 public static StopScanResult Scan(byte[] b) {
  int opt=BitConverter.ToInt32(b,0x3c)+24;
  ulong image=BitConverter.ToUInt64(b,opt+24);
  int sec=opt+BitConverter.ToUInt16(b,opt-4),count=BitConverter.ToUInt16(b,opt-18);
  Func<uint,int> offset=(rva)=>{for(int j=0;j<count;j++){int s=sec+j*40;uint a=BitConverter.ToUInt32(b,s+12), n=BitConverter.ToUInt32(b,s+16);if(rva>=a&&rva<a+n)return checked((int)(rva-a+BitConverter.ToUInt32(b,s+20)));}throw new Exception("Unbacked RVA");};
  int p=offset(BitConverter.ToUInt32(b,opt+136)), size=BitConverter.ToInt32(b,opt+140);
  var rows=new List<StopScanRow>();long instructions=0;
  for(int j=0;j<size;j+=12) {
   uint a=BitConverter.ToUInt32(b,p+j),z=BitConverter.ToUInt32(b,p+j+4);if(z<=a)continue;
   byte[] bytes=new byte[z-a];Array.Copy(b,offset(a),bytes,0,bytes.Length);
   var d=Decoder.Create(64,bytes,image+a);var er=new List<string>();var gr=new List<string>();var ef=new List<string>();var sw=new List<string>();
   while(d.IP<image+z) {
    var i=d.Decode();instructions++;if(i.Length==0)break;
    string t="0x"+i.IP.ToString("x")+" "+i.ToString();
    if(i.IsIPRelativeMemoryOperand&&i.IPRelativeMemoryAddress==0x182d58080UL)er.Add(t);
    if(i.IsIPRelativeMemoryOperand&&i.IPRelativeMemoryAddress==0x182d53c48UL)gr.Add(t);
    if(!i.IsIPRelativeMemoryOperand&&i.MemoryDisplacement64==0xa0UL&&i.OpCount>0)ef.Add(t);
    if(!i.IsIPRelativeMemoryOperand&&i.MemoryDisplacement64==0x14UL&&i.Op0Kind==OpKind.Memory&&i.MemorySize==MemorySize.UInt8&&(i.Mnemonic==Mnemonic.Mov||i.Mnemonic.ToString().StartsWith("Set")))sw.Add(t);
   }
   if((er.Count>0&&ef.Count>0)||(gr.Count>0&&sw.Count>0))rows.Add(new StopScanRow{begin="0x"+(image+a).ToString("x"),end="0x"+(image+z).ToString("x"),event_slot_refs=er.ToArray(),game_slot_refs=gr.ToArray(),event_field_candidates=ef.ToArray(),stop_field_write_candidates=sw.ToArray()});
  }
  return new StopScanResult{unwind_ranges=size/12,instructions=instructions,candidates=rows.ToArray()};
 }
}
'@
$refs=@($decoderPath)+@(Get-ChildItem -LiteralPath (Join-Path $PSHOME 'ref') -Filter '*.dll' | ForEach-Object FullName)
Add-Type -TypeDefinition $code -ReferencedAssemblies $refs
$result=[ordered]@{schema_version=1;evidence_type='Supplemental Iced static candidate scan, not REA or a complete data-flow proof';native=@{path=$nativePath;sha256=(Get-FileHash -LiteralPath $nativePath).Hash.ToLowerInvariant()};decoder=@{path=$decoderPath;sha256=(Get-FileHash -LiteralPath $decoderPath).Hash.ToLowerInvariant()};parser=@{path=$PSCommandPath;sha256=(Get-FileHash -LiteralPath $PSCommandPath).Hash.ToLowerInvariant()};scope='Linear decoding of every PE RUNTIME_FUNCTION fragment; candidate intersection within each fragment only. Events class slot 182d58080 plus displacement a0; InGameManager slot182d53c48 plus byte MOV/SET store displacement14. Other aliases, split fragments, register/indirect paths remain unknown.';scan=[StopScanner]::Scan([IO.File]::ReadAllBytes($nativePath))}
[IO.File]::WriteAllText($OutputPath,(($result|ConvertTo-Json -Depth 10)+"`n"),[Text.UTF8Encoding]::new($false))
Write-Output "Saved $($result.scan.candidates.Count) candidates from $($result.scan.unwind_ranges) ranges"
