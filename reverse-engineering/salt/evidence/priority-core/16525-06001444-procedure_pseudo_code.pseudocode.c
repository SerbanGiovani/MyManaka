// Ghidra pseudocode; not original source or compilable C.
// ev_ea812862142f1ecba20763bdf3ec8cc19faa475d36138e94f4f3bf776c04bf6e

float ExposureUnnoticed2_Scripts_Mission_MissionExposeBlindMove__GetAddSatisfy__06001444
                (longlong param_1)

{
  longlong lVar1;
  
  if (cRam0000000182eb790e == '\0') {
    FUN_1802f2810(&DAT_182d58378);
    LOCK();
    UNLOCK();
    cRam0000000182eb790e = '\x01';
  }
  if (*(longlong *)(param_1 + 0x28) != 0) {
    lVar1 = **(longlong **)(DAT_182d58378 + 0xb8);
    if (*(float *)(*(longlong *)(param_1 + 0x28) + 0x38) * *(float *)(param_1 + 0x30) < 10.0) {
      if (((lVar1 != 0) && (*(longlong *)(lVar1 + 0x40) != 0)) &&
         (lVar1 = *(longlong *)(*(longlong *)(lVar1 + 0x40) + 0x1f8), lVar1 != 0)) {
        return *(float *)(lVar1 + 0x14) / *(float *)(*(longlong *)(param_1 + 0x28) + 0x38);
      }
    }
    else if (((lVar1 != 0) && (*(longlong *)(lVar1 + 0x40) != 0)) &&
            (lVar1 = *(longlong *)(*(longlong *)(lVar1 + 0x40) + 0x1f8), lVar1 != 0)) {
      return *(float *)(lVar1 + 0x10) / *(float *)(*(longlong *)(param_1 + 0x28) + 0x38);
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

