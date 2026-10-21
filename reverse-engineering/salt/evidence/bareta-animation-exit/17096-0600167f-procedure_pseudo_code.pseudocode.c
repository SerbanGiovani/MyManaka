// Ghidra pseudocode; not original source or compilable C.
// ev_ffd5a17d46369dfa2f2114bf520d6ed972caf3989030b18589309e79ca9fc1bc

ulonglong ExposureUnnoticed2_Scripts_InGame_TemporaryInGameState___ctor__0600167f(longlong param_1)

{
  longlong lVar1;
  ulonglong uVar2;
  undefined8 uVar3;
  ulonglong uVar4;
  uint uVar5;
  bool bVar6;
  
  if (cRam0000000182eb7a48 == '\0') {
    FUN_1802f2810(0x182d5de38);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5de08);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5ddb0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5dda0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5dd90);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5dd88);
    LOCK();
    UNLOCK();
    cRam0000000182eb7a48 = '\x01';
  }
  *(undefined1 *)(param_1 + 0x12) = 1;
  uVar3 = FUN_1802c43a0(uRam0000000182d5dd88);
  FUN_180005f20(uVar3);
  bVar6 = DAT_182eb5d50 != 0;
  *(undefined8 *)(param_1 + 0x28) = uVar3;
  if (bVar6) {
    uVar5 = (uint)(param_1 + 0x28U >> 0xc);
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
  uVar3 = FUN_1802c43a0(uRam0000000182d5ddb0);
  FUN_180005fe0(uVar3,uRam0000000182d5de38);
  bVar6 = DAT_182eb5d50 != 0;
  *(undefined8 *)(param_1 + 0x30) = uVar3;
  if (bVar6) {
    uVar5 = (uint)(param_1 + 0x30U >> 0xc);
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
  uVar3 = FUN_1802c43a0(uRam0000000182d5dda0);
  uVar4 = FUN_180e686d0(uVar3,uRam0000000182d5de08);
  bVar6 = DAT_182eb5d50 != 0;
  *(undefined8 *)(param_1 + 0x40) = uVar3;
  if (bVar6) {
    uVar5 = (uint)(param_1 + 0x40U >> 0xc);
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

