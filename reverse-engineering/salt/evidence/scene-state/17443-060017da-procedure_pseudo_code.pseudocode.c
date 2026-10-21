// Ghidra pseudocode; not original source or compilable C.
// ev_7b6354ddd1411dcf5c17cea1c61f2e1ef5e8d6af6cd2eacbe72a813d8e14de86

void ExposureUnnoticed2_Scripts_Base_TimeScaleManager__SwitchMode__060017da
               (longlong param_1,uint param_2,undefined1 param_3)

{
  longlong lVar1;
  longlong lVar2;
  
  if (DAT_182eb7aee == '\0') {
    FUN_1802f2810(&DAT_182d5f408);
    LOCK();
    UNLOCK();
    DAT_182eb7aee = '\x01';
  }
  lVar1 = *(longlong *)(param_1 + 0x10);
  if (lVar1 != 0) {
    if (*(uint *)(lVar1 + 0x18) <= param_2) {
                    /* WARNING: Subroutine does not return */
      FUN_181640100(0);
    }
    lVar2 = *(longlong *)(lVar1 + 0x10);
    if (lVar2 != 0) {
      if (param_2 < *(uint *)(lVar2 + 0x18)) {
        *(undefined1 *)((longlong)(int)param_2 + 0x20 + lVar2) = param_3;
        *(int *)(lVar1 + 0x1c) = *(int *)(lVar1 + 0x1c) + 1;
        return;
      }
                    /* WARNING: Subroutine does not return */
      FUN_18031dae0();
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

