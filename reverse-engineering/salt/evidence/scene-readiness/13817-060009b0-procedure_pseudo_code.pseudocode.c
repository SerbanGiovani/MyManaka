// Ghidra pseudocode; not original source or compilable C.
// ev_2642248b20947581a20f7f2a1877d93313604945e73c447aebef71eaa0d88fa3

ulonglong ExposureUnnoticed2_ObjectTitle_IntroAnimationController__Awake__060009b0(longlong param_1)

{
  ulonglong *puVar1;
  ulonglong uVar2;
  ulonglong uVar3;
  uint uVar4;
  bool bVar5;
  
  if (cRam0000000182eb81f0 == '\0') {
    FUN_1802f2810(&DAT_182d53c58);
    LOCK();
    UNLOCK();
    cRam0000000182eb81f0 = '\x01';
  }
  uVar3 = FUN_180735660(param_1,DAT_182d53c58);
  bVar5 = DAT_182eb5d50 != 0;
  *(ulonglong *)(param_1 + 0x28) = uVar3;
  if (bVar5) {
    uVar4 = (uint)(param_1 + 0x28U >> 0xc);
    puVar1 = (ulonglong *)(&DAT_182f0c920 + (ulonglong)((uVar4 & 0x1fffff) >> 6) * 8);
    do {
      uVar2 = *puVar1;
      LOCK();
      uVar3 = *puVar1;
      bVar5 = uVar2 == uVar3;
      if (bVar5) {
        *puVar1 = uVar2 | 1L << (uVar4 & 0x3f);
        uVar3 = uVar2;
      }
      UNLOCK();
    } while (!bVar5);
  }
  return uVar3;
}

