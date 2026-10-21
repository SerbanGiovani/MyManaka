// Ghidra pseudocode; not original source or compilable C.
// ev_409b7ad287d4d1c48a8a9267e12ddaa419f659838fadc87461883c72dc19c888

undefined8 __c___OnCompleteTransitionStageEvent_b__3_1__06001577(void)

{
  longlong lVar1;
  
  if (cRam0000000182eb79d5 == '\0') {
    FUN_1802f2810(&DAT_182d58380);
    LOCK();
    UNLOCK();
    cRam0000000182eb79d5 = '\x01';
  }
  if (*(int *)(DAT_182d58380 + 0xe0) == 0) {
    FUN_18035c820(DAT_182d58380);
  }
  lVar1 = **(longlong **)(DAT_182d58380 + 0xb8);
  if (lVar1 != 0) {
    return CONCAT71((int7)((ulonglong)*(longlong **)(DAT_182d58380 + 0xb8) >> 8),
                    *(char *)(lVar1 + 0x20) == '\0');
  }
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

