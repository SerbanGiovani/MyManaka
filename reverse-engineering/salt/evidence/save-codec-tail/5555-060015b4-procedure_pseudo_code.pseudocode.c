// Ghidra pseudocode; not original source or compilable C.
// ev_a90228c3f7cbf8f0a895236eef637a9bc4cf9a30c7d03a9422bb58ff6b0b139b

ulonglong System_Security_Cryptography_Aes___ctor__060015b4(longlong param_1)

{
  longlong lVar1;
  ulonglong uVar2;
  ulonglong uVar3;
  int iVar4;
  uint uVar5;
  bool bVar6;
  
  if (cRam0000000182ebae8c == '\0') {
    FUN_1802f2810(0x182d6ab48);
    LOCK();
    UNLOCK();
    cRam0000000182ebae8c = '\x01';
  }
  *(undefined4 *)(param_1 + 0x3c) = 1;
  *(undefined4 *)(param_1 + 0x40) = 2;
  if (*(int *)(lRam0000000182d6ab48 + 0xe0) == 0) {
    FUN_18035c820(lRam0000000182d6ab48);
  }
  iVar4 = DAT_182eb5d50;
  *(undefined8 *)(param_1 + 0x28) = **(undefined8 **)(lRam0000000182d6ab48 + 0xb8);
  if (iVar4 != 0) {
    uVar5 = (uint)(param_1 + 0x28U >> 0xc);
    lVar1 = (ulonglong)((uVar5 & 0x1fffff) >> 6) * 8;
    do {
      uVar3 = *(ulonglong *)(&DAT_182f0c920 + lVar1);
      LOCK();
      bVar6 = uVar3 == *(ulonglong *)(&DAT_182f0c920 + lVar1);
      if (bVar6) {
        *(ulonglong *)(&DAT_182f0c920 + lVar1) = uVar3 | 1L << (uVar5 & 0x3f);
      }
      UNLOCK();
      iVar4 = DAT_182eb5d50;
    } while (!bVar6);
  }
  uVar3 = *(ulonglong *)(*(longlong *)(lRam0000000182d6ab48 + 0xb8) + 8);
  *(ulonglong *)(param_1 + 0x30) = uVar3;
  if (iVar4 != 0) {
    uVar5 = (uint)(param_1 + 0x30U >> 0xc);
    lVar1 = (ulonglong)((uVar5 & 0x1fffff) >> 6) * 8;
    do {
      uVar2 = *(ulonglong *)(&DAT_182f0c920 + lVar1);
      LOCK();
      uVar3 = *(ulonglong *)(&DAT_182f0c920 + lVar1);
      bVar6 = uVar2 == uVar3;
      if (bVar6) {
        *(ulonglong *)(&DAT_182f0c920 + lVar1) = uVar2 | 1L << (uVar5 & 0x3f);
        uVar3 = uVar2;
      }
      UNLOCK();
    } while (!bVar6);
  }
  *(undefined4 *)(param_1 + 0x10) = 0x80;
  *(undefined4 *)(param_1 + 0x14) = 8;
  *(undefined4 *)(param_1 + 0x38) = 0x100;
  *(undefined4 *)(param_1 + 0x3c) = 1;
  return uVar3;
}

