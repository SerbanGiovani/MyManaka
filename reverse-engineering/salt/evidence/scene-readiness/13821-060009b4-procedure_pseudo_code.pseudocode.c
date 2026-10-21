// Ghidra pseudocode; not original source or compilable C.
// ev_752dc6ef84781235f2bf084df2ec6e644337942c864b652a44af3897c9bfdda0

void ExposureUnnoticed2_ObjectTitle_IntroAnimationController__OnStartFadeOut__060009b4
               (longlong param_1)

{
  longlong lVar1;
  code *pcVar2;
  undefined8 uVar3;
  
  if (cRam0000000182eb81f2 == '\0') {
    FUN_1802f2810(0x182d6c418);
    LOCK();
    UNLOCK();
    cRam0000000182eb81f2 = '\x01';
  }
  if (*(int *)(param_1 + 0x24) == 1) {
    *(undefined4 *)(param_1 + 0x24) = 2;
    uVar3 = uRam0000000182d6c418;
    lVar1 = *(longlong *)(param_1 + 0x28);
    if (lVar1 == 0) {
                    /* WARNING: Subroutine does not return */
      FUN_18031dad0();
    }
    pcVar2 = pcRam0000000182ebf360;
    if ((pcRam0000000182ebf360 == (code *)0x0) &&
       (pcVar2 = (code *)FUN_1802cf0c0("UnityEngine.Animator::SetTriggerString(System.String)"),
       pcVar2 == (code *)0x0)) {
      uVar3 = FUN_1802ced60("UnityEngine.Animator::SetTriggerString(System.String)");
                    /* WARNING: Subroutine does not return */
      FUN_1802cca90(uVar3,0);
    }
    pcRam0000000182ebf360 = pcVar2;
    (*pcRam0000000182ebf360)(lVar1,uVar3);
  }
  return;
}

