// Ghidra pseudocode; not original source or compilable C.
// ev_a18d49e0e83c13b970afdd383950e4489348bb47ffb48d00628b9b28d86ff5e2

ulonglong IKA9nt_Encrypter_EncrypterCore___ctor__0600006c(longlong param_1)

{
  ulonglong *puVar1;
  undefined8 uVar2;
  ulonglong uVar3;
  ulonglong uVar4;
  uint uVar5;
  bool bVar6;
  
  if (cRam0000000182ebaa93 == '\0') {
    FUN_1802f2810(0x182d5bfb8);
    LOCK();
    UNLOCK();
    cRam0000000182ebaa93 = '\x01';
  }
  bVar6 = cRam0000000182ec10b0 == '\0';
  *(undefined4 *)(param_1 + 0x28) = 0x20;
  *(undefined4 *)(param_1 + 0x2c) = 2;
  if (bVar6) {
    FUN_1802f2810(0x182d53aa8);
    LOCK();
    UNLOCK();
    cRam0000000182ec10b0 = '\x01';
  }
  if (*(int *)(lRam0000000182d53aa8 + 0xe0) == 0) {
    FUN_18035c820();
  }
  uVar2 = *(undefined8 *)(param_1 + 0x20);
  if (*(int *)(lRam0000000182d5bfb8 + 0xe0) == 0) {
    FUN_18035c820(lRam0000000182d5bfb8);
  }
  uVar4 = *(ulonglong *)(lRam0000000182d5bfb8 + 0xb8);
  *(undefined8 *)(uVar4 + 0x18) = uVar2;
  if (DAT_182eb5d50 != 0) {
    uVar5 = (uint)(*(longlong *)(lRam0000000182d5bfb8 + 0xb8) + 0x18U >> 0xc);
    puVar1 = (ulonglong *)(&DAT_182f0c920 + (ulonglong)((uVar5 & 0x1fffff) >> 6) * 8);
    do {
      uVar3 = *puVar1;
      LOCK();
      uVar4 = *puVar1;
      bVar6 = uVar3 == uVar4;
      if (bVar6) {
        *puVar1 = uVar3 | 1L << (uVar5 & 0x3f);
        uVar4 = uVar3;
      }
      UNLOCK();
    } while (!bVar6);
  }
  return uVar4;
}

