// Ghidra pseudocode; not original source or compilable C.
// ev_57dabdc03f6978c1664e3f956b9a3a38f690e09469fe6a9c1065da98b4e34cb7

void ExposureUnnoticed2_Scripts_Base_TimeScaleManager__RequestTimeScale__060017db
               (longlong param_1,undefined4 param_2)

{
  longlong lVar1;
  
  if (cRam0000000182eb7aef == '\0') {
    FUN_1802f2810(0x182d5f410);
    LOCK();
    UNLOCK();
    cRam0000000182eb7aef = '\x01';
  }
  lVar1 = *(longlong *)(param_1 + 0x10);
  if (lVar1 != 0) {
    if (*(int *)(lVar1 + 0x18) == 0) {
                    /* WARNING: Subroutine does not return */
      FUN_181640100(0);
    }
    lVar1 = *(longlong *)(lVar1 + 0x10);
    if (lVar1 != 0) {
      if (*(int *)(lVar1 + 0x18) != 0) {
        if (*(char *)(lVar1 + 0x20) == '\0') {
          *(undefined4 *)(param_1 + 0x18) = param_2;
        }
        return;
      }
                    /* WARNING: Subroutine does not return */
      FUN_18031dae0();
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

