// Ghidra pseudocode; not original source or compilable C.
// ev_283630b2bcc5c349511387f35d7692840a1bfc51509abe252372b53650c32a4e

ulonglong SeekableAesAssetBundle_Scripts_SeekableAesStream__Read__06000013
                    (longlong *param_1,undefined8 param_2,undefined4 param_3,undefined4 param_4)

{
  longlong *plVar1;
  code *pcVar2;
  uint uVar3;
  undefined8 uVar4;
  ulonglong uVar5;
  
  uVar4 = (**(code **)(*param_1 + 0x1e8))(param_1,*(undefined8 *)(*param_1 + 0x1f0));
  plVar1 = (longlong *)param_1[5];
  if (plVar1 != (longlong *)0x0) {
    uVar3 = (**(code **)(*plVar1 + 0x2e8))
                      (plVar1,param_2,param_3,param_4,*(undefined8 *)(*plVar1 + 0x2f0));
    SeekableAesAssetBundle_Scripts_SeekableAesStream__Cipher__06000009
              (param_1,param_2,param_3,param_4,uVar4,0);
    return (ulonglong)uVar3;
  }
  FUN_18031dad0();
  pcVar2 = (code *)swi(3);
  uVar5 = (*pcVar2)();
  return uVar5;
}

