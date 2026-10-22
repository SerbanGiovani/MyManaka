// Ghidra pseudocode; not original source or compilable C.
// ev_5a181be8ec8a7bfa537c3653bd4bed52c61b2e8e328c0f56a17ce61a1796abac

ulonglong __c___cctor__06001994(void)

{
  ulonglong *puVar1;
  ulonglong uVar2;
  ulonglong uVar3;
  uint uVar4;
  bool bVar5;
  
  if (cRam0000000182eb7c21 == '\0') {
    FUN_1802f2810(0x182d63530);
    LOCK();
    UNLOCK();
    cRam0000000182eb7c21 = '\x01';
  }
  uVar3 = FUN_1802c43a0(lRam0000000182d63530);
  **(ulonglong **)(lRam0000000182d63530 + 0xb8) = uVar3;
  if (DAT_182eb5d50 != 0) {
    uVar4 = (uint)(*(ulonglong *)(lRam0000000182d63530 + 0xb8) >> 0xc);
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

