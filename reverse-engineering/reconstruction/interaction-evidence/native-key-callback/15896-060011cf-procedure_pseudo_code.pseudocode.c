// Ghidra pseudocode; not original source or compilable C.
// ev_ccbca03a6aa0502551c012af9358ed3b0e3a016b7c4d64ca1c4b43ff4c087505

void __c___Initialize_b__5_2__060011cf(void)

{
  longlong lVar1;
  
  if (cRam0000000182eb7807 == '\0') {
    FUN_1802f2810(&DAT_182d53c48);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d58230);
    LOCK();
    UNLOCK();
    cRam0000000182eb7807 = '\x01';
  }
  if ((((**(longlong **)(DAT_182d53c48 + 0xb8) != 0) &&
       (lVar1 = *(longlong *)(**(longlong **)(DAT_182d53c48 + 0xb8) + 0x28), lVar1 != 0)) &&
      (lVar1 = *(longlong *)(lVar1 + 0x30), lVar1 != 0)) &&
     ((lVar1 = *(longlong *)(lVar1 + 0x40), lVar1 != 0 &&
      (lVar1 = *(longlong *)(lVar1 + 0x60), lVar1 != 0)))) {
    *(undefined4 *)(lVar1 + 0x224) = 5;
    if (((**(longlong **)(DAT_182d53c48 + 0xb8) != 0) &&
        ((lVar1 = *(longlong *)(**(longlong **)(DAT_182d53c48 + 0xb8) + 0x28), lVar1 != 0 &&
         (lVar1 = *(longlong *)(lVar1 + 0x30), lVar1 != 0)))) &&
       ((lVar1 = *(longlong *)(lVar1 + 0x40), lVar1 != 0 &&
        (lVar1 = *(longlong *)(lVar1 + 0x60), lVar1 != 0)))) {
      *(undefined1 *)(lVar1 + 0x238) = 1;
      if (((**(longlong **)(DAT_182d58230 + 0xb8) != 0) &&
          (lVar1 = *(longlong *)(**(longlong **)(DAT_182d58230 + 0xb8) + 0x10), lVar1 != 0)) &&
         (lVar1 = *(longlong *)(lVar1 + 0x60), lVar1 != 0)) {
        *(undefined4 *)(lVar1 + 0x234) = 0x2729;
        return;
      }
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

