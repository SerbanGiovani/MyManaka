// Ghidra pseudocode, not original source or compilable C.
// REA evidence: ev_e1ebc5e626babc5f70df7b711746e81571fcb6844cddee5fb0cd0de2635a4c4e

void EncrypterCore_GetSalt(undefined8 param_1)

{
  code *UNRECOVERED_JUMPTABLE;
  undefined8 uVar1;
  int iVar2;
  longlong lVar3;
  longlong *plVar4;
  
  if (cRam0000000182ebaacc == '\0') {
    FUN_1802f2810(0x182d64be8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d34310);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d64c08);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5bfb8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d52e20);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d52ec8);
    LOCK();
    UNLOCK();
    cRam0000000182ebaacc = '\x01';
  }
  if (*(int *)(lRam0000000182d5bfb8 + 0xe0) == 0) {
    FUN_18035c820(lRam0000000182d5bfb8);
  }
  lVar3 = *(longlong *)(*(longlong *)(lRam0000000182d5bfb8 + 0xb8) + 0x18);
  if ((lVar3 != 0) && (lVar3 = *(longlong *)(lVar3 + 0x28), lVar3 != 0)) {
    iVar2 = FUN_180e9f040(lVar3,param_1,
                          *(undefined8 *)
                           (*(longlong *)(*(longlong *)(lRam0000000182d64be8 + 0x20) + 0xc0) + 0xf8)
                         );
    if (iVar2 < 0) {
      if (*(int *)(lRam0000000182d5bfb8 + 0xe0) == 0) {
        FUN_18035c820(lRam0000000182d5bfb8);
      }
      lVar3 = *(longlong *)(*(longlong *)(lRam0000000182d5bfb8 + 0xb8) + 0x10);
      uVar1 = uRam0000000182d34310;
    }
    else {
      if (*(int *)(lRam0000000182d5bfb8 + 0xe0) == 0) {
        FUN_18035c820(lRam0000000182d5bfb8);
      }
      lVar3 = *(longlong *)(*(longlong *)(lRam0000000182d5bfb8 + 0xb8) + 0x18);
      if (lVar3 == 0) goto code_r0x00018143e62d;
      lVar3 = *(longlong *)(lVar3 + 0x28);
      uVar1 = uRam0000000182d64c08;
    }
    if ((lVar3 != 0) && (lVar3 = FUN_180eb45b0(lVar3,param_1,uVar1), lVar3 != 0)) {
      for (lVar3 = FUN_1816192e0(lVar3 + 0x18,0); lVar3 != 0;
          lVar3 = FUN_181478910(lVar3,uRam0000000182d52ec8,0)) {
        if (7 < *(int *)(lVar3 + 0x10)) {
          plVar4 = (longlong *)FUN_1816df430(0);
          if (plVar4 != (longlong *)0x0) {
            UNRECOVERED_JUMPTABLE = *(code **)(*plVar4 + 600);
                    /* WARNING: Could not recover jumptable at 0x00018143e62a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
            (*UNRECOVERED_JUMPTABLE)
                      (plVar4,lVar3,*(undefined8 *)(*plVar4 + 0x260),UNRECOVERED_JUMPTABLE);
            return;
          }
          break;
        }
      }
    }
  }
code_r0x00018143e62d:
  FUN_18031dad0();
  UNRECOVERED_JUMPTABLE = (code *)swi(3);
  (*UNRECOVERED_JUMPTABLE)();
  return;
}

