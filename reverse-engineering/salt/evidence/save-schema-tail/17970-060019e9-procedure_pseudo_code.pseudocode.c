// Ghidra pseudocode; not original source or compilable C.
// ev_b0ef6fce4d1cf2c9e48fdd68ef9bd2ac812382e2451205097f6481a1666cb881

ulonglong ExposureUnnoticed2_ObjectUI_InventoryPanel_LoadoutData___ctor__060019e9(longlong param_1)

{
  longlong lVar1;
  ulonglong uVar2;
  undefined8 uVar3;
  ulonglong uVar4;
  uint uVar5;
  bool bVar6;
  
  if (cRam0000000182eb7c47 == '\0') {
    FUN_1802f2810(0x182d5de20);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5ddd8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d54a48);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d62e80);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d54b10);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d62e70);
    LOCK();
    UNLOCK();
    cRam0000000182eb7c47 = '\x01';
  }
  uVar3 = FUN_1802c43a0(DAT_182d54b10);
  FUN_180003c90(uVar3,DAT_182d54a48);
  bVar6 = DAT_182eb5d50 != 0;
  *(undefined8 *)(param_1 + 0x10) = uVar3;
  if (bVar6) {
    uVar5 = (uint)(param_1 + 0x10U >> 0xc);
    lVar1 = (ulonglong)((uVar5 & 0x1fffff) >> 6) * 8;
    do {
      uVar4 = *(ulonglong *)(&DAT_182f0c920 + lVar1);
      LOCK();
      bVar6 = uVar4 == *(ulonglong *)(&DAT_182f0c920 + lVar1);
      if (bVar6) {
        *(ulonglong *)(&DAT_182f0c920 + lVar1) = uVar4 | 1L << (uVar5 & 0x3f);
      }
      UNLOCK();
    } while (!bVar6);
  }
  uVar3 = FUN_1802c43a0(uRam0000000182d62e70);
  FUN_1811cf4f0(uVar3,uRam0000000182d62e80);
  bVar6 = DAT_182eb5d50 != 0;
  *(undefined8 *)(param_1 + 0x18) = uVar3;
  if (bVar6) {
    uVar5 = (uint)(param_1 + 0x18U >> 0xc);
    lVar1 = (ulonglong)((uVar5 & 0x1fffff) >> 6) * 8;
    do {
      uVar4 = *(ulonglong *)(&DAT_182f0c920 + lVar1);
      LOCK();
      bVar6 = uVar4 == *(ulonglong *)(&DAT_182f0c920 + lVar1);
      if (bVar6) {
        *(ulonglong *)(&DAT_182f0c920 + lVar1) = uVar4 | 1L << (uVar5 & 0x3f);
      }
      UNLOCK();
    } while (!bVar6);
  }
  uVar3 = FUN_1802c43a0(uRam0000000182d5ddd8);
  uVar4 = FUN_180e2cdf0(uVar3,uRam0000000182d5de20);
  bVar6 = DAT_182eb5d50 != 0;
  *(undefined8 *)(param_1 + 0x20) = uVar3;
  if (bVar6) {
    uVar5 = (uint)(param_1 + 0x20U >> 0xc);
    lVar1 = (ulonglong)((uVar5 & 0x1fffff) >> 6) * 8;
    do {
      uVar2 = *(ulonglong *)(&DAT_182f0c920 + lVar1);
      LOCK();
      uVar4 = *(ulonglong *)(&DAT_182f0c920 + lVar1);
      bVar6 = uVar2 == uVar4;
      if (bVar6) {
        *(ulonglong *)(&DAT_182f0c920 + lVar1) = uVar2 | 1L << (uVar5 & 0x3f);
        uVar4 = uVar2;
      }
      UNLOCK();
    } while (!bVar6);
  }
  return uVar4;
}

