// Ghidra pseudocode; not original source or compilable C.
// ev_539c180e6526868750d23a292cc648232706912b570aec677cbc2e270b7e72e6

void ExposureUnnoticed2_Object3D_Player_Scripts_PlayerAnimationManager__TransBaretaEscape__06000c80
               (longlong param_1)

{
  undefined4 uVar1;
  longlong lVar2;
  code *pcVar3;
  undefined8 uVar4;
  
  if (cRam0000000182eb8392 == '\0') {
    FUN_1802f2810(0x182d6f340);
    LOCK();
    UNLOCK();
    cRam0000000182eb8392 = '\x01';
  }
  lVar2 = *(longlong *)(param_1 + 0x30);
  if (*(int *)(lRam0000000182d6f340 + 0xe0) == 0) {
    FUN_18035c820(lRam0000000182d6f340);
  }
  if (lVar2 == 0) {
                    /* WARNING: Subroutine does not return */
    FUN_18031dad0();
  }
  uVar1 = *(undefined4 *)(*(longlong *)(lRam0000000182d6f340 + 0xb8) + 0x44);
  pcVar3 = DAT_182ebf368;
  if ((DAT_182ebf368 == (code *)0x0) &&
     (pcVar3 = (code *)FUN_1802cf0c0("UnityEngine.Animator::SetTriggerID(System.Int32)"),
     pcVar3 == (code *)0x0)) {
    uVar4 = FUN_1802ced60("UnityEngine.Animator::SetTriggerID(System.Int32)");
                    /* WARNING: Subroutine does not return */
    FUN_1802cca90(uVar4,0);
  }
  DAT_182ebf368 = pcVar3;
                    /* WARNING: Could not recover jumptable at 0x00018062e224. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*DAT_182ebf368)(lVar2,uVar1);
  return;
}

