// Ghidra pseudocode; not original source or compilable C.
// ev_2f63dc8b449df2962c6b9396b446efae96d8b1b86c5069cfbc43804e1147ace4

ulonglong PasswordMap___cctor__06000003(void)

{
  ulonglong *puVar1;
  ulonglong uVar2;
  ulonglong uVar3;
  uint uVar4;
  bool bVar5;
  
  if (cRam0000000182ebaa7d == '\0') {
    FUN_1802f2810(0x182d64e78);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d64e88);
    LOCK();
    UNLOCK();
    cRam0000000182ebaa7d = '\x01';
  }
  uVar3 = uRam0000000182d64e88;
  **(ulonglong **)(lRam0000000182d64e78 + 0xb8) = uRam0000000182d64e88;
  if (iRam0000000182eb5d50 != 0) {
    uVar4 = (uint)(*(ulonglong *)(lRam0000000182d64e78 + 0xb8) >> 0xc);
    puVar1 = (ulonglong *)((ulonglong)((uVar4 & 0x1fffff) >> 6) * 8 + 0x182f0c920);
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

