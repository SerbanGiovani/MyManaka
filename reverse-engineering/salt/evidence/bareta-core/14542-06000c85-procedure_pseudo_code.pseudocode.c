// Ghidra pseudocode; not original source or compilable C.
// ev_06bd1cfd27ffe1424b747475b17773ef73345661dac10373243619cebc4e1264

void ExposureUnnoticed2_Object3D_Player_Scripts_PlayerAnimationManager__SetBareta__06000c85
               (longlong param_1,undefined1 param_2)

{
  undefined4 uVar1;
  longlong lVar2;
  code *pcVar3;
  undefined8 uVar4;
  undefined8 unaff_RDI;
  
  if (cRam0000000182eb8396 == '\0') {
    FUN_1802f2810(0x182d6f340);
    LOCK();
    UNLOCK();
    cRam0000000182eb8396 = '\x01';
  }
  lVar2 = *(longlong *)(param_1 + 0x30);
  if (*(int *)(lRam0000000182d6f340 + 0xe0) == 0) {
    FUN_18035c820(lRam0000000182d6f340);
  }
  if (lVar2 == 0) {
                    /* WARNING: Subroutine does not return */
    FUN_18031dad0();
  }
  uVar1 = *(undefined4 *)(*(longlong *)(lRam0000000182d6f340 + 0xb8) + 0x28);
  pcVar3 = DAT_182ebf348;
  if ((DAT_182ebf348 == (code *)0x0) &&
     (pcVar3 = (code *)FUN_1802cf0c0("UnityEngine.Animator::SetBoolID(System.Int32,System.Boolean)",
                                     uVar1,param_2,0,unaff_RDI), pcVar3 == (code *)0x0)) {
    uVar4 = FUN_1802ced60("UnityEngine.Animator::SetBoolID(System.Int32,System.Boolean)");
                    /* WARNING: Subroutine does not return */
    FUN_1802cca90(uVar4,0);
  }
  DAT_182ebf348 = pcVar3;
                    /* WARNING: Could not recover jumptable at 0x000181eea6d4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*DAT_182ebf348)(lVar2,uVar1,param_2);
  return;
}

