// Ghidra pseudocode; not original source or compilable C.
// ev_1c7d1f4faeaf94c816f8909c0bb9d47d304051fa30f8f58b28d9be772c361544

ulonglong ExposureUnnoticed2_Scripts_InGame_PlayerCustomData___ctor__0600151d(longlong param_1)

{
  longlong lVar1;
  ulonglong uVar2;
  undefined8 uVar3;
  ulonglong uVar4;
  uint uVar5;
  bool bVar6;
  
  if (cRam0000000182eb7985 == '\0') {
    FUN_1802f2810(0x182d5dd40);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d5dd38);
    LOCK();
    UNLOCK();
    cRam0000000182eb7985 = '\x01';
  }
  *(undefined4 *)(param_1 + 0x10) = 0xfffffc19;
  *(undefined4 *)(param_1 + 0x104) = 0;
  uVar3 = FUN_1802c43a0(DAT_182d5dd38);
  FUN_180e686d0(uVar3,uRam0000000182d5dd40);
  bVar6 = DAT_182eb5d50 != 0;
  *(undefined8 *)(param_1 + 0x108) = uVar3;
  if (bVar6) {
    uVar5 = (uint)(param_1 + 0x108U >> 0xc);
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
  uVar4 = ExposureUnnoticed2_Scripts_InGame_GameStateFacade__GetDefaultHairCustomDataDict__06001544
                    (0);
  bVar6 = DAT_182eb5d50 != 0;
  *(ulonglong *)(param_1 + 0x118) = uVar4;
  if (bVar6) {
    uVar5 = (uint)(param_1 + 0x118U >> 0xc);
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

