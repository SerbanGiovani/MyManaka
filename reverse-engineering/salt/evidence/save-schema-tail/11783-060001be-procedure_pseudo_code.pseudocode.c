// Ghidra pseudocode; not original source or compilable C.
// ev_209fffcba648f91ffc1950c2d20c8a2af902d8933a471ea495f1d155202a220f

ulonglong ES3Settings___cctor__060001be(void)

{
  ulonglong uVar1;
  longlong lVar2;
  ulonglong uVar3;
  uint uVar4;
  bool bVar5;
  
  if (cRam0000000182eb7558 == '\0') {
    FUN_1802f2810(&DAT_182d534a8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d531f8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d52708);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d52700);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d526f8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d526f0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d526e8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d526e0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d526d8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d526d0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d526c8);
    LOCK();
    UNLOCK();
    cRam0000000182eb7558 = '\x01';
  }
  **(undefined8 **)(DAT_182d534a8 + 0xb8) = 0;
  if (DAT_182eb5d50 != 0) {
    uVar4 = (uint)(*(ulonglong *)(DAT_182d534a8 + 0xb8) >> 0xc);
    lVar2 = (ulonglong)((uVar4 & 0x1fffff) >> 6) * 8;
    do {
      uVar3 = *(ulonglong *)(&DAT_182f0c920 + lVar2);
      LOCK();
      bVar5 = uVar3 == *(ulonglong *)(&DAT_182f0c920 + lVar2);
      if (bVar5) {
        *(ulonglong *)(&DAT_182f0c920 + lVar2) = uVar3 | 1L << (uVar4 & 0x3f);
      }
      UNLOCK();
    } while (!bVar5);
  }
  *(undefined8 *)(*(longlong *)(DAT_182d534a8 + 0xb8) + 0x10) = 0;
  if (DAT_182eb5d50 != 0) {
    uVar4 = (uint)(*(longlong *)(DAT_182d534a8 + 0xb8) + 0x10U >> 0xc);
    lVar2 = (ulonglong)((uVar4 & 0x1fffff) >> 6) * 8;
    do {
      uVar3 = *(ulonglong *)(&DAT_182f0c920 + lVar2);
      LOCK();
      bVar5 = uVar3 == *(ulonglong *)(&DAT_182f0c920 + lVar2);
      if (bVar5) {
        *(ulonglong *)(&DAT_182f0c920 + lVar2) = uVar3 | 1L << (uVar4 & 0x3f);
      }
      UNLOCK();
    } while (!bVar5);
  }
  lVar2 = FUN_1802c36c0(DAT_182d531f8,9);
  if (lVar2 == 0) {
                    /* WARNING: Subroutine does not return */
    FUN_18031dad0();
  }
  FUN_180002cd0(lVar2,0,uRam0000000182d526e0);
  FUN_180002cd0(lVar2,1,uRam0000000182d526f0);
  FUN_180002cd0(lVar2,2,uRam0000000182d526d0);
  FUN_180002cd0(lVar2,3,uRam0000000182d52700);
  FUN_180002cd0(lVar2,4,uRam0000000182d526c8);
  FUN_180002cd0(lVar2,5,uRam0000000182d52708);
  FUN_180002cd0(lVar2,6,uRam0000000182d526f8);
  FUN_180002cd0(lVar2,7,uRam0000000182d526e8);
  FUN_180002cd0(lVar2,8,uRam0000000182d526d8);
  uVar3 = DAT_182d534a8;
  bVar5 = DAT_182eb5d50 != 0;
  *(longlong *)(*(longlong *)(DAT_182d534a8 + 0xb8) + 0x18) = lVar2;
  if (bVar5) {
    uVar4 = (uint)(*(longlong *)(DAT_182d534a8 + 0xb8) + 0x18U >> 0xc);
    lVar2 = (ulonglong)((uVar4 & 0x1fffff) >> 6) * 8;
    do {
      uVar1 = *(ulonglong *)(&DAT_182f0c920 + lVar2);
      LOCK();
      uVar3 = *(ulonglong *)(&DAT_182f0c920 + lVar2);
      bVar5 = uVar1 == uVar3;
      if (bVar5) {
        *(ulonglong *)(&DAT_182f0c920 + lVar2) = uVar1 | 1L << (uVar4 & 0x3f);
        uVar3 = uVar1;
      }
      UNLOCK();
    } while (!bVar5);
  }
  return uVar3;
}

