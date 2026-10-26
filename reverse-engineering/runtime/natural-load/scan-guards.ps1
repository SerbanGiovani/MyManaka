param([string]$OutputPath="$PSScriptRoot/guard-scan.json")
$ErrorActionPreference='Stop'
$nativePath='E:\SecretFlasherManakaREA\GameAssembly.dll';$decoderPath='E:\SecretFlasherManakaREA\BepInEx\core\Iced.dll'
$inputPath=Join-Path $PSScriptRoot '.cache/guard-scan-input.json';$selection=Get-Content -LiteralPath $inputPath -Raw|ConvertFrom-Json
if((Get-FileHash -LiteralPath $nativePath).Hash.ToLowerInvariant() -ne $selection.native_sha256){throw 'native identity'}
[void][Reflection.Assembly]::LoadFrom($decoderPath)
$code=@'
using System;
using System.Collections.Generic;
using Iced.Intel;
public class GuardFragment {public string begin{get;set;} public string end{get;set;} public string[] slotRefs{get;set;} public string[] fieldB{get;set;} public string[] byteWrites65{get;set;} public string[] rawWrites65{get;set;}}
public class GuardResult {public int unwind_ranges{get;set;} public long instructions{get;set;} public GuardFragment[] debugCandidates{get;set;} public GuardFragment[] npcWrites{get;set;} public string[] restoreDirectBranches{get;set;}}
public static class NaturalGuardScanner {
 public static GuardResult Scan(byte[] b,ulong[] npcStarts){
  int opt=BitConverter.ToInt32(b,0x3c)+24;ulong image=BitConverter.ToUInt64(b,opt+24);
  int sec=opt+BitConverter.ToUInt16(b,opt-4),count=BitConverter.ToUInt16(b,opt-18);
  Func<uint,int> offset=(rva)=>{for(int j=0;j<count;j++){int s=sec+j*40;uint a=BitConverter.ToUInt32(b,s+12),n=BitConverter.ToUInt32(b,s+16);if(rva>=a&&rva<a+n)return checked((int)(rva-a+BitConverter.ToUInt32(b,s+20)));}throw new Exception("unbacked RVA");};
  int p=offset(BitConverter.ToUInt32(b,opt+136)),size=BitConverter.ToInt32(b,opt+140);var starts=new HashSet<ulong>(npcStarts);var debug=new List<GuardFragment>();var npc=new List<GuardFragment>();var branches=new List<string>();long total=0;
  for(int j=0;j<size;j+=12){uint a=BitConverter.ToUInt32(b,p+j),z=BitConverter.ToUInt32(b,p+j+4);if(z<=a)continue;byte[] bytes=new byte[z-a];Array.Copy(b,offset(a),bytes,0,bytes.Length);var d=Decoder.Create(64,bytes,image+a);var refs=new List<string>();var fb=new List<string>();var w=new List<string>();var raw=new List<string>();
   while(d.IP<image+z){var i=d.Decode();total++;if(i.Length==0)break;string text="0x"+i.IP.ToString("x")+" "+i.ToString();
    if(i.IsIPRelativeMemoryOperand&&i.IPRelativeMemoryAddress==0x182d59ac8UL)refs.Add(text);
    if(i.Op0Kind==OpKind.NearBranch64&&i.NearBranchTarget==0x18042f310UL&&(i.Mnemonic==Mnemonic.Call||i.Mnemonic==Mnemonic.Jmp))branches.Add(text);
    if(!i.IsIPRelativeMemoryOperand&&i.MemoryDisplacement64==0xbUL)fb.Add(text);
    if(starts.Contains(image+a)&&!i.IsIPRelativeMemoryOperand&&i.MemoryDisplacement64==0x65UL&&i.Op0Kind==OpKind.Memory&&i.MemorySize==MemorySize.UInt8&&(i.Mnemonic==Mnemonic.Mov||i.Mnemonic.ToString().StartsWith("Set"))){w.Add(text);byte[] v=new byte[i.Length];Array.Copy(bytes,(int)(i.IP-image-a),v,0,i.Length);raw.Add(BitConverter.ToString(v).Replace("-","").ToLowerInvariant());}
   }
   var row=new GuardFragment{begin="0x"+(image+a).ToString("x"),end="0x"+(image+z).ToString("x"),slotRefs=refs.ToArray(),fieldB=fb.ToArray(),byteWrites65=w.ToArray(),rawWrites65=raw.ToArray()};
   if(refs.Count>0)debug.Add(row);if(w.Count>0)npc.Add(row);
  }
  return new GuardResult{unwind_ranges=size/12,instructions=total,debugCandidates=debug.ToArray(),npcWrites=npc.ToArray(),restoreDirectBranches=branches.ToArray()};
 }
}
'@
$refs=@($decoderPath)+@(Get-ChildItem -LiteralPath (Join-Path $PSHOME 'ref') -Filter '*.dll'|ForEach-Object FullName)
Add-Type -TypeDefinition $code -ReferencedAssemblies $refs
$starts=@($selection.npc_ranges|ForEach-Object {[Convert]::ToUInt64($_.begin.Substring(2),16)})
$result=[ordered]@{schema_version=1;evidence_type='Supplemental original-byte Iced scan; candidate intersection, not a global data-flow proof';native=@{path=$nativePath;sha256=$selection.native_sha256};decoder=@{path=$decoderPath;sha256=(Get-FileHash -LiteralPath $decoderPath).Hash.ToLowerInvariant()};parser=@{path=$PSCommandPath;sha256=(Get-FileHash -LiteralPath $PSCommandPath).Hash.ToLowerInvariant()};methods=$selection.methods;npc_ranges=$selection.npc_ranges;scope='All PE RUNTIME_FUNCTION fragments decoded linearly. Debug candidates reference the known class usage slot; displacement b alone does not prove receiver identity. NPC byte MOV/SET displacement65 is checked within parent and declared nested-type unwind fragments. Wider stores, aliases, split data flow, reflection and external code are not excluded.';scan=[NaturalGuardScanner]::Scan([IO.File]::ReadAllBytes($nativePath),$starts)}
[IO.File]::WriteAllText($OutputPath,(($result|ConvertTo-Json -Depth 14)+"`n"),[Text.UTF8Encoding]::new($false))
Write-Output "Scanned $($result.scan.unwind_ranges) fragments / $($result.scan.instructions) instructions; debug refs $($result.scan.debugCandidates.Count), NPC write candidates $($result.scan.npcWrites.Count)"
