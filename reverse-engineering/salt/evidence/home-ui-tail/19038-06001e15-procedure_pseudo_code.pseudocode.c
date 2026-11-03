// Ghidra pseudocode; not original source or compilable C.
// ev_d92549e7ed98c8ce5beda1514e709be5a0f310aab57e10e23ce32fbe2093021c

void Common_Scripts_UI_BasePanelView__Close__06001e15(longlong param_1)

{
  undefined4 uVar1;
  longlong lVar2;
  undefined8 uVar3;
  code *pcVar4;
  
  if (DAT_182eb7fd7 == '\0') {
    FUN_1802f2810(&DAT_182d58368);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d69200);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d5f3b8);
    LOCK();
    UNLOCK();
    DAT_182eb7fd7 = '\x01';
  }
  if (*(char *)(param_1 + 0x40) == '\0') {
    *(undefined1 *)(param_1 + 0x40) = 1;
    uVar3 = FUN_1802c43a0(DAT_182d58368);
    FUN_1814df680(uVar3,param_1,DAT_182d69200,0);
    ExposureUnnoticed2_Scripts_Base_Scheduler__DelayFlame__0600174b(uVar3,1,0);
    lVar2 = *(longlong *)(param_1 + 0x38);
    if (*(int *)(DAT_182d5f3b8 + 0xe0) == 0) {
      FUN_18035c820(DAT_182d5f3b8);
    }
    if (lVar2 == 0) {
                    /* WARNING: Subroutine does not return */
      FUN_18031dad0();
    }
    uVar1 = **(undefined4 **)(DAT_182d5f3b8 + 0xb8);
    pcVar4 = DAT_182ebf368;
    if ((DAT_182ebf368 == (code *)0x0) &&
       (pcVar4 = (code *)FUN_1802cf0c0("UnityEngine.Animator::SetTriggerID(System.Int32)"),
       pcVar4 == (code *)0x0)) {
      uVar3 = FUN_1802ced60("UnityEngine.Animator::SetTriggerID(System.Int32)");
                    /* WARNING: Subroutine does not return */
      FUN_1802cca90(uVar3,0);
    }
    DAT_182ebf368 = pcVar4;
    (*DAT_182ebf368)(lVar2,uVar1);
  }
  return;
}

