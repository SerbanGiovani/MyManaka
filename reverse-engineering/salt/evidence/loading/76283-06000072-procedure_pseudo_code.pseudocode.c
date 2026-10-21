// Ghidra pseudocode; not original source or compilable C.
// ev_4103874920e079344c8e7c50f42e7e893c99f67bdd78b64620c83ffb1100c77e

ulonglong IKA9nt_Encrypter_EncrypterCore__SetKeyData__06000072(undefined8 param_1)

{
  ulonglong *puVar1;
  ulonglong uVar2;
  ulonglong uVar3;
  uint uVar4;
  bool bVar5;
  
  if (cRam0000000182ebaa99 == '\0') {
    FUN_1802f2810(0x182d5bfb8);
    LOCK();
    UNLOCK();
    cRam0000000182ebaa99 = '\x01';
  }
  if (*(int *)(lRam0000000182d5bfb8 + 0xe0) == 0) {
    FUN_18035c820(lRam0000000182d5bfb8);
  }
  uVar3 = *(ulonglong *)(lRam0000000182d5bfb8 + 0xb8);
  *(undefined8 *)(uVar3 + 0x18) = param_1;
  if (DAT_182eb5d50 != 0) {
    uVar4 = (uint)(*(longlong *)(lRam0000000182d5bfb8 + 0xb8) + 0x18U >> 0xc);
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

