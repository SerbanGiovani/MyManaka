// Ghidra pseudocode; not original source or compilable C.
// ev_eabfdd5690629c2aed19233462b3bef956dd579bcceda93440c274216a921f51

void ExposureUnnoticed2_ObjectTitle_IntroAnimationController__Update__060009b1(longlong param_1)

{
  int iVar1;
  char cVar2;
  longlong lVar3;
  code *pcVar4;
  undefined8 uVar5;
  
  if (cRam0000000182eb81f1 == '\0') {
    FUN_1802f2810(&DAT_182d5aa88);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d6c420);
    LOCK();
    UNLOCK();
    cRam0000000182eb81f1 = '\x01';
  }
  iVar1 = *(int *)(param_1 + 0x24);
  if (iVar1 != 0) {
    if (iVar1 == 1) {
      if (*(int *)(DAT_182d5aa88 + 0xe0) == 0) {
        FUN_18035c820();
      }
      cVar2 = ExposureUnnoticed2_Scripts_Base_InputManager__IsDownFrame__06001706(0xb,0);
      if (cVar2 == '\0') {
        if (*(int *)(DAT_182d5aa88 + 0xe0) == 0) {
          FUN_18035c820();
        }
        cVar2 = ExposureUnnoticed2_Scripts_Base_InputManager__IsDownFrame__06001706(10,0);
        if (cVar2 == '\0') {
          if (*(int *)(DAT_182d5aa88 + 0xe0) == 0) {
            FUN_18035c820();
          }
          cVar2 = ExposureUnnoticed2_Scripts_Base_InputManager__IsDownFrame__06001706(1000,0);
          if (cVar2 == '\0') {
            return;
          }
        }
      }
      if (cRam0000000182eb81f2 == '\0') {
        FUN_1802f2810(0x182d6c418);
        LOCK();
        UNLOCK();
        cRam0000000182eb81f2 = '\x01';
      }
      if (*(int *)(param_1 + 0x24) == 1) {
        *(undefined4 *)(param_1 + 0x24) = 2;
        uVar5 = uRam0000000182d6c418;
        lVar3 = *(longlong *)(param_1 + 0x28);
        if (lVar3 == 0) goto code_r0x0001805ea5aa;
        pcVar4 = pcRam0000000182ebf360;
        if ((pcRam0000000182ebf360 == (code *)0x0) &&
           (pcVar4 = (code *)FUN_1802cf0c0("UnityEngine.Animator::SetTriggerString(System.String)"),
           pcVar4 == (code *)0x0)) {
          uVar5 = FUN_1802ced60("UnityEngine.Animator::SetTriggerString(System.String)");
                    /* WARNING: Subroutine does not return */
          FUN_1802cca90(uVar5,0);
        }
        pcRam0000000182ebf360 = pcVar4;
        (*pcRam0000000182ebf360)(lVar3,uVar5);
      }
    }
    else if ((iVar1 != 2) && (iVar1 == 3)) {
      lVar3 = FUN_180478000();
      if (lVar3 != 0) {
        if (*(int *)(lVar3 + 0xb4) < 0x19) {
          return;
        }
        if (*(longlong *)(param_1 + 0x28) != 0) {
          FUN_181eea760(*(longlong *)(param_1 + 0x28),uRam0000000182d6c420,0);
          *(undefined4 *)(param_1 + 0x24) = 4;
          return;
        }
      }
code_r0x0001805ea5aa:
                    /* WARNING: Subroutine does not return */
      FUN_18031dad0();
    }
  }
  return;
}

