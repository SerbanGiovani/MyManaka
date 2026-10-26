// Ghidra pseudocode; not original source or compilable C.
// ev_6384f397124d95cb8d0603c7581ae529fb285b57a7fd466a3482ddf4d9acae79

ulonglong ES3Internal_ES3Reflection___cctor__0600067e(void)

{
  ulonglong uVar1;
  longlong lVar2;
  undefined8 uVar3;
  ulonglong uVar4;
  uint uVar5;
  bool bVar6;
  
  if (cRam0000000182eb809c == '\0') {
    FUN_1802f2810(0x182d6a5e0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d52c00);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d6a5d8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d6a5d0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d6a5c8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d6a5c0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d6a5b8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d531f8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d54db0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d535d8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d6a5b0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d68578);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d68460);
    LOCK();
    UNLOCK();
    cRam0000000182eb809c = '\x01';
  }
  lVar2 = FUN_1802c36c0(DAT_182d531f8,3);
  if (lVar2 == 0) {
                    /* WARNING: Subroutine does not return */
    FUN_18031dad0();
  }
  FUN_180002cd0(lVar2,0,uRam0000000182d6a5b0);
  FUN_180002cd0(lVar2,1,uRam0000000182d68460);
  FUN_180002cd0(lVar2,2,uRam0000000182d68578);
  bVar6 = DAT_182eb5d50 != 0;
  **(longlong **)(DAT_182d52c00 + 0xb8) = lVar2;
  if (bVar6) {
    uVar5 = (uint)(*(ulonglong *)(DAT_182d52c00 + 0xb8) >> 0xc);
    lVar2 = (ulonglong)((uVar5 & 0x1fffff) >> 6) * 8;
    do {
      uVar4 = *(ulonglong *)(&DAT_182f0c920 + lVar2);
      LOCK();
      bVar6 = uVar4 == *(ulonglong *)(&DAT_182f0c920 + lVar2);
      if (bVar6) {
        *(ulonglong *)(&DAT_182f0c920 + lVar2) = uVar4 | 1L << (uVar5 & 0x3f);
      }
      UNLOCK();
    } while (!bVar6);
  }
  lVar2 = lRam0000000182d6a5c0;
  if (*(int *)(DAT_182d535d8 + 0xe0) == 0) {
    FUN_18035c820();
  }
  if (DAT_182ebb9aa == '\0') {
    FUN_1802f2810(&DAT_182d535d8);
    LOCK();
    UNLOCK();
    DAT_182ebb9aa = '\x01';
  }
  if (lVar2 == 0) {
    uVar3 = 0;
  }
  else {
    if (*(int *)(DAT_182d535d8 + 0xe0) == 0) {
      FUN_18035c820();
    }
    lVar2 = FUN_1803613f0(lVar2,1);
    uVar3 = FUN_1802c5ac0(lVar2 + 0x20);
  }
  *(undefined8 *)(*(longlong *)(DAT_182d52c00 + 0xb8) + 8) = uVar3;
  if (DAT_182eb5d50 != 0) {
    uVar5 = (uint)(*(longlong *)(DAT_182d52c00 + 0xb8) + 8U >> 0xc);
    lVar2 = (ulonglong)((uVar5 & 0x1fffff) >> 6) * 8;
    do {
      uVar4 = *(ulonglong *)(&DAT_182f0c920 + lVar2);
      LOCK();
      bVar6 = uVar4 == *(ulonglong *)(&DAT_182f0c920 + lVar2);
      if (bVar6) {
        *(ulonglong *)(&DAT_182f0c920 + lVar2) = uVar4 | 1L << (uVar5 & 0x3f);
      }
      UNLOCK();
    } while (!bVar6);
  }
  lVar2 = lRam0000000182d6a5b8;
  if (DAT_182ebb9aa == '\0') {
    FUN_1802f2810(&DAT_182d535d8);
    LOCK();
    UNLOCK();
    DAT_182ebb9aa = '\x01';
  }
  if (lVar2 == 0) {
    uVar3 = 0;
  }
  else {
    if (*(int *)(DAT_182d535d8 + 0xe0) == 0) {
      FUN_18035c820();
    }
    lVar2 = FUN_1803613f0(lVar2,1);
    uVar3 = FUN_1802c5ac0(lVar2 + 0x20);
  }
  *(undefined8 *)(*(longlong *)(DAT_182d52c00 + 0xb8) + 0x10) = uVar3;
  if (DAT_182eb5d50 != 0) {
    uVar5 = (uint)(*(longlong *)(DAT_182d52c00 + 0xb8) + 0x10U >> 0xc);
    lVar2 = (ulonglong)((uVar5 & 0x1fffff) >> 6) * 8;
    do {
      uVar4 = *(ulonglong *)(&DAT_182f0c920 + lVar2);
      LOCK();
      bVar6 = uVar4 == *(ulonglong *)(&DAT_182f0c920 + lVar2);
      if (bVar6) {
        *(ulonglong *)(&DAT_182f0c920 + lVar2) = uVar4 | 1L << (uVar5 & 0x3f);
      }
      UNLOCK();
    } while (!bVar6);
  }
  lVar2 = lRam0000000182d6a5c8;
  if (DAT_182ebb9aa == '\0') {
    FUN_1802f2810(&DAT_182d535d8);
    LOCK();
    UNLOCK();
    DAT_182ebb9aa = '\x01';
  }
  if (lVar2 == 0) {
    uVar3 = 0;
  }
  else {
    if (*(int *)(DAT_182d535d8 + 0xe0) == 0) {
      FUN_18035c820();
    }
    lVar2 = FUN_1803613f0(lVar2,1);
    uVar3 = FUN_1802c5ac0(lVar2 + 0x20);
  }
  *(undefined8 *)(*(longlong *)(DAT_182d52c00 + 0xb8) + 0x18) = uVar3;
  if (DAT_182eb5d50 != 0) {
    uVar5 = (uint)(*(longlong *)(DAT_182d52c00 + 0xb8) + 0x18U >> 0xc);
    lVar2 = (ulonglong)((uVar5 & 0x1fffff) >> 6) * 8;
    do {
      uVar4 = *(ulonglong *)(&DAT_182f0c920 + lVar2);
      LOCK();
      bVar6 = uVar4 == *(ulonglong *)(&DAT_182f0c920 + lVar2);
      if (bVar6) {
        *(ulonglong *)(&DAT_182f0c920 + lVar2) = uVar4 | 1L << (uVar5 & 0x3f);
      }
      UNLOCK();
    } while (!bVar6);
  }
  lVar2 = lRam0000000182d6a5d0;
  if (DAT_182ebb9aa == '\0') {
    FUN_1802f2810(&DAT_182d535d8);
    LOCK();
    UNLOCK();
    DAT_182ebb9aa = '\x01';
  }
  if (lVar2 == 0) {
    uVar3 = 0;
  }
  else {
    if (*(int *)(DAT_182d535d8 + 0xe0) == 0) {
      FUN_18035c820();
    }
    lVar2 = FUN_1803613f0(lVar2,1);
    uVar3 = FUN_1802c5ac0(lVar2 + 0x20);
  }
  *(undefined8 *)(*(longlong *)(DAT_182d52c00 + 0xb8) + 0x20) = uVar3;
  if (DAT_182eb5d50 != 0) {
    uVar5 = (uint)(*(longlong *)(DAT_182d52c00 + 0xb8) + 0x20U >> 0xc);
    lVar2 = (ulonglong)((uVar5 & 0x1fffff) >> 6) * 8;
    do {
      uVar4 = *(ulonglong *)(&DAT_182f0c920 + lVar2);
      LOCK();
      bVar6 = uVar4 == *(ulonglong *)(&DAT_182f0c920 + lVar2);
      if (bVar6) {
        *(ulonglong *)(&DAT_182f0c920 + lVar2) = uVar4 | 1L << (uVar5 & 0x3f);
      }
      UNLOCK();
    } while (!bVar6);
  }
  lVar2 = lRam0000000182d6a5d8;
  if (DAT_182ebb9aa == '\0') {
    FUN_1802f2810(&DAT_182d535d8);
    LOCK();
    UNLOCK();
    DAT_182ebb9aa = '\x01';
  }
  if (lVar2 == 0) {
    uVar3 = 0;
  }
  else {
    if (*(int *)(DAT_182d535d8 + 0xe0) == 0) {
      FUN_18035c820();
    }
    lVar2 = FUN_1803613f0(lVar2,1);
    uVar3 = FUN_1802c5ac0(lVar2 + 0x20);
  }
  *(undefined8 *)(*(longlong *)(DAT_182d52c00 + 0xb8) + 0x28) = uVar3;
  if (DAT_182eb5d50 != 0) {
    uVar5 = (uint)(*(longlong *)(DAT_182d52c00 + 0xb8) + 0x28U >> 0xc);
    lVar2 = (ulonglong)((uVar5 & 0x1fffff) >> 6) * 8;
    do {
      uVar4 = *(ulonglong *)(&DAT_182f0c920 + lVar2);
      LOCK();
      bVar6 = uVar4 == *(ulonglong *)(&DAT_182f0c920 + lVar2);
      if (bVar6) {
        *(ulonglong *)(&DAT_182f0c920 + lVar2) = uVar4 | 1L << (uVar5 & 0x3f);
      }
      UNLOCK();
    } while (!bVar6);
  }
  lVar2 = lRam0000000182d6a5e0;
  if (DAT_182ebb9aa == '\0') {
    FUN_1802f2810(&DAT_182d535d8);
    LOCK();
    UNLOCK();
    DAT_182ebb9aa = '\x01';
  }
  if (lVar2 == 0) {
    uVar3 = 0;
  }
  else {
    if (*(int *)(DAT_182d535d8 + 0xe0) == 0) {
      FUN_18035c820();
    }
    lVar2 = FUN_1803613f0(lVar2,1);
    uVar3 = FUN_1802c5ac0(lVar2 + 0x20);
  }
  *(undefined8 *)(*(longlong *)(DAT_182d52c00 + 0xb8) + 0x30) = uVar3;
  if (DAT_182eb5d50 != 0) {
    uVar5 = (uint)(*(longlong *)(DAT_182d52c00 + 0xb8) + 0x30U >> 0xc);
    lVar2 = (ulonglong)((uVar5 & 0x1fffff) >> 6) * 8;
    do {
      uVar4 = *(ulonglong *)(&DAT_182f0c920 + lVar2);
      LOCK();
      bVar6 = uVar4 == *(ulonglong *)(&DAT_182f0c920 + lVar2);
      if (bVar6) {
        *(ulonglong *)(&DAT_182f0c920 + lVar2) = uVar4 | 1L << (uVar5 & 0x3f);
      }
      UNLOCK();
    } while (!bVar6);
  }
  uVar3 = FUN_1802c36c0(DAT_182d54db0,0);
  *(undefined8 *)(*(longlong *)(DAT_182d52c00 + 0xb8) + 0x38) = uVar3;
  if (DAT_182eb5d50 != 0) {
    uVar5 = (uint)(*(longlong *)(DAT_182d52c00 + 0xb8) + 0x38U >> 0xc);
    lVar2 = (ulonglong)((uVar5 & 0x1fffff) >> 6) * 8;
    do {
      uVar4 = *(ulonglong *)(&DAT_182f0c920 + lVar2);
      LOCK();
      bVar6 = uVar4 == *(ulonglong *)(&DAT_182f0c920 + lVar2);
      if (bVar6) {
        *(ulonglong *)(&DAT_182f0c920 + lVar2) = uVar4 | 1L << (uVar5 & 0x3f);
      }
      UNLOCK();
    } while (!bVar6);
  }
  uVar4 = DAT_182d52c00;
  *(undefined8 *)(*(longlong *)(DAT_182d52c00 + 0xb8) + 0x40) = 0;
  if (DAT_182eb5d50 != 0) {
    uVar5 = (uint)(*(longlong *)(DAT_182d52c00 + 0xb8) + 0x40U >> 0xc);
    lVar2 = (ulonglong)((uVar5 & 0x1fffff) >> 6) * 8;
    do {
      uVar1 = *(ulonglong *)(&DAT_182f0c920 + lVar2);
      LOCK();
      uVar4 = *(ulonglong *)(&DAT_182f0c920 + lVar2);
      bVar6 = uVar1 == uVar4;
      if (bVar6) {
        *(ulonglong *)(&DAT_182f0c920 + lVar2) = uVar1 | 1L << (uVar5 & 0x3f);
        uVar4 = uVar1;
      }
      UNLOCK();
    } while (!bVar6);
  }
  return uVar4;
}

