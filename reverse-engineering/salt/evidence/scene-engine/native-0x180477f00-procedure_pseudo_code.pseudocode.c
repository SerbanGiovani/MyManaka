// Ghidra pseudocode; not original source or compilable C.
// ev_9125e0367f1779b14bf56f37bf1b1664d2c13a54bd8fa3909d589f1c43bc1919

ulonglong native_only_180477f00__00000000(undefined8 param_1)

{
  ulonglong *puVar1;
  ulonglong uVar2;
  ulonglong uVar3;
  uint uVar4;
  bool bVar5;
  
  if (cRam0000000182eb78f3 == '\0') {
    FUN_1802f2810(&DAT_182d5bfd0);
    LOCK();
    UNLOCK();
    cRam0000000182eb78f3 = '\x01';
  }
  uVar3 = DAT_182d5bfd0;
  **(undefined8 **)(DAT_182d5bfd0 + 0xb8) = param_1;
  if (DAT_182eb5d50 != 0) {
    uVar4 = (uint)(*(ulonglong *)(DAT_182d5bfd0 + 0xb8) >> 0xc);
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

