// Ghidra pseudocode; not original source or compilable C.
// ev_5fb829cb3877254d19333544fb925c4e29eff2b621b1dd480a867037a13a2c34

void IKA9nt_Encrypter_EncrypterCore__SetStaticVariants__06000071
               (undefined8 param_1,undefined4 param_2,undefined4 param_3)

{
  ulonglong *puVar1;
  ulonglong uVar2;
  longlong lVar3;
  ulonglong uVar4;
  uint uVar5;
  
  if (cRam0000000182ebaa98 == '\0') {
    FUN_1802f2810(0x182d5bfb8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d53aa8);
    LOCK();
    UNLOCK();
    cRam0000000182ebaa98 = '\x01';
  }
  if (*(int *)(lRam0000000182d5bfb8 + 0xe0) == 0) {
    FUN_18035c820();
  }
  lVar3 = *(longlong *)(*(longlong *)(lRam0000000182d5bfb8 + 0xb8) + 0x18);
  if (*(int *)(lRam0000000182d53aa8 + 0xe0) == 0) {
    FUN_18035c820();
  }
  if (cRam0000000182ec12f3 == '\0') {
    FUN_1802f2810(0x182d53aa8);
    LOCK();
    UNLOCK();
    cRam0000000182ec12f3 = '\x01';
  }
  if (*(int *)(lRam0000000182d53aa8 + 0xe0) == 0) {
    FUN_18035c820();
  }
  if (cRam0000000182ec129b == '\0') {
    FUN_1802f2810(0x182d53aa8);
    LOCK();
    UNLOCK();
    cRam0000000182ec129b = '\x01';
  }
  if (lVar3 != 0) {
    if (*(int *)(lRam0000000182d53aa8 + 0xe0) == 0) {
      FUN_18035c820();
    }
    if (*(longlong *)(lVar3 + 0x10) != 0) {
      return;
    }
  }
  if (*(int *)(lRam0000000182d5bfb8 + 0xe0) == 0) {
    FUN_18035c820();
  }
  *(undefined8 *)(*(longlong *)(lRam0000000182d5bfb8 + 0xb8) + 0x18) = param_1;
  if (DAT_182eb5d50 != 0) {
    uVar5 = (uint)(*(longlong *)(lRam0000000182d5bfb8 + 0xb8) + 0x18U >> 0xc);
    puVar1 = (ulonglong *)(&DAT_182f0c920 + (ulonglong)((uVar5 & 0x1fffff) >> 6) * 8);
    do {
      uVar4 = *puVar1;
      LOCK();
      uVar2 = *puVar1;
      if (uVar4 == uVar2) {
        *puVar1 = uVar4 | 1L << (uVar5 & 0x3f);
      }
      UNLOCK();
    } while (uVar4 != uVar2);
  }
  *(undefined4 *)(*(longlong *)(lRam0000000182d5bfb8 + 0xb8) + 0x28) = param_2;
  *(undefined4 *)(*(longlong *)(lRam0000000182d5bfb8 + 0xb8) + 0x2c) = param_3;
  return;
}

