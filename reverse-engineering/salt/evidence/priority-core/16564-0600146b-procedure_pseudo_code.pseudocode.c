// Ghidra pseudocode; not original source or compilable C.
// ev_30402fcf71bac1aa39308bd3a2eb3d6f658d66607a8445ca112666602c8b8df0

ulonglong ExposureUnnoticed2_Scripts_Mission_MissionManager___ctor__0600146b(longlong param_1)

{
  longlong lVar1;
  ulonglong uVar2;
  undefined8 uVar3;
  ulonglong uVar4;
  uint uVar5;
  bool bVar6;
  
  if (cRam0000000182eb7927 == '\0') {
    FUN_1802f2810(0x182d5e140);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5e138);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5e1b0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5e1a8);
    LOCK();
    UNLOCK();
    cRam0000000182eb7927 = '\x01';
  }
  uVar3 = FUN_1802c43a0(uRam0000000182d5e1a8);
  FUN_1811cf4f0(uVar3,uRam0000000182d5e1b0);
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
  uVar3 = FUN_1802c43a0(uRam0000000182d5e138);
  uVar4 = FUN_180e686d0(uVar3,uRam0000000182d5e140);
  bVar6 = DAT_182eb5d50 != 0;
  *(undefined8 *)(param_1 + 0x18) = uVar3;
  if (bVar6) {
    uVar5 = (uint)(param_1 + 0x18U >> 0xc);
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

