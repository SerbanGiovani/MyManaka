// Ghidra pseudocode; not original source or compilable C.
// ev_21f36581441e374f0efbecb1760995a8f74f251ba0ef40835690c1ec635f0a73

void __c___UseItemProcess_b__5_2__06001284(void)

{
  longlong lVar1;
  
  if (cRam0000000182eb7868 == '\0') {
    FUN_1802f2810(&DAT_182d58378);
    LOCK();
    UNLOCK();
    cRam0000000182eb7868 = '\x01';
  }
  if (((**(longlong **)(DAT_182d58378 + 0xb8) != 0) &&
      (lVar1 = *(longlong *)(**(longlong **)(DAT_182d58378 + 0xb8) + 0x40), lVar1 != 0)) &&
     (lVar1 = *(longlong *)(lVar1 + 0x1e8), lVar1 != 0)) {
    if (cRam0000000182eb765b == '\0') {
      FUN_1802f2810(&DAT_182d58398);
      LOCK();
      UNLOCK();
      cRam0000000182eb765b = '\x01';
    }
    *(undefined4 *)(lVar1 + 0x20) = 4;
    lVar1 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
    if (lVar1 != 0) {
      *(undefined4 *)(lVar1 + 0x17c) = 0;
      return;
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

