// Ghidra pseudocode; not original source or compilable C.
// ev_254885c2b3206e538aadbc4f391110a0a44d65c96c9d5e1b18338fdb11cd6a33

void ExposureUnnoticed2_ObjectUI_SelectSexOptionPanel_SelectSexOptionPanelView__OnClickDecide__06001838
               (longlong param_1)

{
  undefined4 uVar1;
  longlong lVar2;
  undefined8 uVar3;
  code *pcVar4;
  undefined8 unaff_RDI;
  
  if (cRam0000000182eb7b3c == '\0') {
    FUN_1802f2810(&DAT_182d58368);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d58398);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d61b48);
    LOCK();
    UNLOCK();
    cRam0000000182eb7b3c = '\x01';
  }
  lVar2 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x38);
  if (lVar2 == 0) {
                    /* WARNING: Subroutine does not return */
    FUN_18031dad0();
  }
  *(undefined1 *)(lVar2 + 0xbd) = 1;
  uVar3 = FUN_1802c43a0(DAT_182d58368);
  FUN_1814df680(uVar3,param_1,uRam0000000182d61b48,0);
  FUN_1804b3c60(uVar3,1,0);
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
    FUN_1814df680(uVar3,param_1,uRam0000000182d69200,0,unaff_RDI);
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

