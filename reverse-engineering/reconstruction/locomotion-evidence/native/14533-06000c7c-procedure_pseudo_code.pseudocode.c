// Ghidra pseudocode; not original source or compilable C.
// ev_ac5d85b77c9f52ea2e04870c2177b7d1e05856cc2d070584a697a5a14e2f6259

void ExposureUnnoticed2_Object3D_Player_Scripts_PlayerAnimationManager__SetMotionSpeedScale__06000c7c
               (longlong param_1,undefined4 param_2)

{
  undefined4 uVar1;
  longlong lVar2;
  code *pcVar3;
  undefined8 uVar4;
  
  if (cRam0000000182eb838e == '\0') {
    FUN_1802f2810(0x182d6f340);
    LOCK();
    UNLOCK();
    cRam0000000182eb838e = '\x01';
  }
  lVar2 = *(longlong *)(param_1 + 0x30);
  if (*(int *)(lRam0000000182d6f340 + 0xe0) == 0) {
    FUN_18035c820(lRam0000000182d6f340);
  }
  if (lVar2 == 0) {
                    /* WARNING: Subroutine does not return */
    FUN_18031dad0();
  }
  uVar1 = *(undefined4 *)(*(longlong *)(lRam0000000182d6f340 + 0xb8) + 0x80);
  pcVar3 = pcRam0000000182ebf338;
  if ((pcRam0000000182ebf338 == (code *)0x0) &&
     (pcVar3 = (code *)FUN_1802cf0c0("UnityEngine.Animator::SetFloatID(System.Int32,System.Single)")
     , pcVar3 == (code *)0x0)) {
    uVar4 = FUN_1802ced60("UnityEngine.Animator::SetFloatID(System.Int32,System.Single)");
                    /* WARNING: Subroutine does not return */
    FUN_1802cca90(uVar4,0);
  }
  pcRam0000000182ebf338 = pcVar3;
                    /* WARNING: Could not recover jumptable at 0x00018062ddf7. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*pcRam0000000182ebf338)(lVar2,uVar1,param_2);
  return;
}

