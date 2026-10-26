// Ghidra pseudocode; not original source or compilable C.
// ev_79c6665456a6f4e9bc71b9891f4d3b38484bb9dd84843a7c807280f56f3d9caa

ulonglong ExposureUnnoticed2_Scripts_Mission_MissionBukkake__IsInCondition__06001428(void)

{
  ulonglong uVar1;
  longlong lVar2;
  
  if (cRam0000000182eb78fe == '\0') {
    FUN_1802f2810(&DAT_182d58398);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d53c48);
    LOCK();
    UNLOCK();
    cRam0000000182eb78fe = '\x01';
  }
  if ((**(longlong **)(DAT_182d53c48 + 0xb8) != 0) &&
     (*(longlong *)(**(longlong **)(DAT_182d53c48 + 0xb8) + 0x28) != 0)) {
    if (cRam0000000182eb54ab == '\0') {
      FUN_1802f2810(0x182d5d6b8);
      LOCK();
      UNLOCK();
      cRam0000000182eb54ab = '\x01';
    }
    uVar1 = **(ulonglong **)(lRam0000000182d5d6b8 + 0xb8);
    if (uVar1 != 0) {
      if (*(char *)(uVar1 + 0x18) == '\0') {
        return uVar1 & 0xffffffffffffff00;
      }
      lVar2 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x38);
      if (lVar2 != 0) {
        return CONCAT71((int7)((ulonglong)lVar2 >> 8),*(char *)(lVar2 + 0x10) == '\0');
      }
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

