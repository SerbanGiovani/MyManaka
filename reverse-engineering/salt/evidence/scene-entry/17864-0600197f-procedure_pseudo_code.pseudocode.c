// Ghidra pseudocode; not original source or compilable C.
// ev_63864f723c34bd15c7e58ae148f7cbd240e1dfe97525e63da82704750293721e

void ExposureUnnoticed2_ObjectUI_SaveDataSelectPanel_SaveDataSelectPanelView__OnClickBack__0600197f
               (longlong param_1)

{
  undefined4 uVar1;
  longlong lVar2;
  undefined8 uVar3;
  code *pcVar4;
  
  if (cRam0000000182eb7c12 == '\0') {
    FUN_1802f2810(0x182d5aa70);
    LOCK();
    UNLOCK();
    cRam0000000182eb7c12 = '\x01';
  }
  if (**(longlong **)(lRam0000000182d5aa70 + 0xb8) == 0) {
                    /* WARNING: Subroutine does not return */
    FUN_18031dad0();
  }
  FUN_180477a70(**(longlong **)(lRam0000000182d5aa70 + 0xb8),0x32,0xbf800000,0,0);
  if (cRam0000000182eb7fd7 == '\0') {
    FUN_1802f2810(&DAT_182d58368,0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d69200);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5f3b8);
    LOCK();
    UNLOCK();
    cRam0000000182eb7fd7 = '\x01';
  }
  if (*(char *)(param_1 + 0x40) == '\0') {
    *(undefined1 *)(param_1 + 0x40) = 1;
    uVar3 = FUN_1802c43a0(DAT_182d58368);
    FUN_1814df680(uVar3,param_1,uRam0000000182d69200,0);
    FUN_1804b3c60(uVar3,1,0);
    lVar2 = *(longlong *)(param_1 + 0x38);
    if (*(int *)(lRam0000000182d5f3b8 + 0xe0) == 0) {
      FUN_18035c820(lRam0000000182d5f3b8);
    }
    if (lVar2 == 0) {
                    /* WARNING: Subroutine does not return */
      FUN_18031dad0();
    }
    uVar1 = **(undefined4 **)(lRam0000000182d5f3b8 + 0xb8);
    pcVar4 = pcRam0000000182ebf368;
    if ((pcRam0000000182ebf368 == (code *)0x0) &&
       (pcVar4 = (code *)FUN_1802cf0c0("UnityEngine.Animator::SetTriggerID(System.Int32)"),
       pcVar4 == (code *)0x0)) {
      uVar3 = FUN_1802ced60("UnityEngine.Animator::SetTriggerID(System.Int32)");
                    /* WARNING: Subroutine does not return */
      FUN_1802cca90(uVar3,0);
    }
    pcRam0000000182ebf368 = pcVar4;
    (*pcRam0000000182ebf368)(lVar2,uVar1);
  }
  return;
}

