// Ghidra pseudocode; not original source or compilable C.
// ev_484192574b68a74e22ed34b3e00e39a5a9bfdacd57c3ddc4b2bfa95fad98191b

void __c___OnClickEmergencyEscape_b__15_4__0600181e(void)

{
  longlong lVar1;
  
  if (cRam0000000182eb7b2b == '\0') {
    FUN_1802f2810(&DAT_182d53c48);
    LOCK();
    UNLOCK();
    cRam0000000182eb7b2b = '\x01';
  }
  if ((**(longlong **)(DAT_182d53c48 + 0xb8) != 0) &&
     (lVar1 = *(longlong *)(**(longlong **)(DAT_182d53c48 + 0xb8) + 0x30), lVar1 != 0)) {
    *(undefined1 *)(lVar1 + 0x13) = 0;
    return;
  }
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

