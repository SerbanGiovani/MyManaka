// Ghidra pseudocode; not original source or compilable C.
// ev_4f3342da766de9ad5559b156a7234b91dcb4cbfef403c545fce52137790c75a3

undefined8 __c___OnFoundStrangerEvent_b__39_2__06000d6e(void)

{
  longlong lVar1;
  
  if (cRam0000000182eb83eb == '\0') {
    FUN_1802f2810(0x182d5ff60);
    LOCK();
    UNLOCK();
    cRam0000000182eb83eb = '\x01';
  }
  if (*(int *)(lRam0000000182d5ff60 + 0xe0) == 0) {
    FUN_18035c820(lRam0000000182d5ff60);
  }
  lVar1 = **(longlong **)(lRam0000000182d5ff60 + 0xb8);
  if (lVar1 != 0) {
    return CONCAT71((int7)((ulonglong)*(longlong **)(lRam0000000182d5ff60 + 0xb8) >> 8),
                    *(int *)(lVar1 + 0x58) == 0);
  }
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

