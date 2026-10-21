// Ghidra pseudocode; not original source or compilable C.
// ev_6daba0c4859ba8787825c5b19c7acdfb46668eff85e22d2789d108b0fc24bfd7

void __c__DisplayClass54_0___Initialize_b__0__06000fe2(longlong param_1)

{
  int iVar1;
  undefined4 uVar2;
  longlong lVar3;
  longlong lVar4;
  code *pcVar5;
  undefined8 uVar6;
  undefined8 unaff_RDI;
  bool bVar7;
  
  if (cRam0000000182eb7743 == '\0') {
    FUN_1802f2810(&DAT_182d59ea8);
    LOCK();
    UNLOCK();
    cRam0000000182eb7743 = '\x01';
  }
  if ((*(longlong *)(param_1 + 0x10) != 0) &&
     (lVar3 = *(longlong *)(*(longlong *)(param_1 + 0x10) + 0x90), lVar3 != 0)) {
    pcVar5 = pcRam0000000182ebf380;
    if ((pcRam0000000182ebf380 == (code *)0x0) &&
       (pcVar5 = (code *)FUN_1802cf0c0("UnityEngine.Animator::Rebind(System.Boolean)"),
       pcVar5 == (code *)0x0)) {
      uVar6 = FUN_1802ced60("UnityEngine.Animator::Rebind(System.Boolean)");
                    /* WARNING: Subroutine does not return */
      FUN_1802cca90(uVar6,0);
    }
    pcRam0000000182ebf380 = pcVar5;
    (*pcRam0000000182ebf380)(lVar3,1);
    if (*(longlong *)(param_1 + 0x10) != 0) {
      lVar3 = *(longlong *)(*(longlong *)(param_1 + 0x10) + 0x90);
      if (*(int *)(DAT_182d59ea8 + 0xe0) == 0) {
        FUN_18035c820(DAT_182d59ea8);
      }
      if (((*(longlong *)(param_1 + 0x10) != 0) &&
          (lVar4 = *(longlong *)(*(longlong *)(param_1 + 0x10) + 0x40), lVar4 != 0)) &&
         (iVar1 = *(int *)(lVar4 + 0x4c), bVar7 = iVar1 == 0 || iVar1 == 4, lVar3 != 0)) {
        uVar2 = *(undefined4 *)(*(longlong *)(DAT_182d59ea8 + 0xb8) + 0x14);
        pcVar5 = DAT_182ebf348;
        if ((DAT_182ebf348 == (code *)0x0) &&
           (pcVar5 = (code *)FUN_1802cf0c0("UnityEngine.Animator::SetBoolID(System.Int32,System.Boolean)"
                                           ,uVar2,bVar7,0,unaff_RDI), pcVar5 == (code *)0x0)) {
          uVar6 = FUN_1802ced60("UnityEngine.Animator::SetBoolID(System.Int32,System.Boolean)");
                    /* WARNING: Subroutine does not return */
          FUN_1802cca90(uVar6,0);
        }
        DAT_182ebf348 = pcVar5;
                    /* WARNING: Could not recover jumptable at 0x000181eea6d4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        (*DAT_182ebf348)(lVar3,uVar2,bVar7);
        return;
      }
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

