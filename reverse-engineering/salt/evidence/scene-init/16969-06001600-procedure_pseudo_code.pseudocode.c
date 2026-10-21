// Ghidra pseudocode; not original source or compilable C.
// ev_19a4318f65cc5aca466a401378a48f2172001425a022dc51e2f06310cd925cb8

ulonglong ExposureUnnoticed2_Scripts_InGame_SaveManager__LoadSystem__06001600(void)

{
  longlong lVar1;
  ulonglong uVar2;
  undefined8 uVar3;
  longlong lVar4;
  ulonglong uVar5;
  uint uVar6;
  bool bVar7;
  
  if (cRam0000000182eb79fd == '\0') {
    FUN_1802f2810(0x182d601f0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d601e8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d58398);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d53690);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d601e0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d601d8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d601d0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d601c8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d601c0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d601b8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d601b0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d601a8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d60278);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d601a0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d60198);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d60238);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d60230);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d60228);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d60220);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d60218);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d60210);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d60208);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d60200);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d601f8);
    LOCK();
    UNLOCK();
    cRam0000000182eb79fd = '\x01';
  }
  if (*(int *)(DAT_182d60278 + 0xe0) == 0) {
    FUN_18035c820();
  }
  ExposureUnnoticed2_Scripts_Base_SaveRapper__PreProcess__060017b8(1,0xffffffff,0,0);
  uVar3 = FUN_1802c36c0(uRam0000000182d601f0,3);
  uVar3 = FUN_1809fef00(uRam0000000182d60220,uVar3,uRam0000000182d601d8);
  **(undefined8 **)(DAT_182d58398 + 0xb8) = uVar3;
  if (DAT_182eb5d50 != 0) {
    uVar6 = (uint)(*(ulonglong *)(DAT_182d58398 + 0xb8) >> 0xc);
    lVar4 = (ulonglong)((uVar6 & 0x1fffff) >> 6) * 8;
    do {
      uVar5 = *(ulonglong *)(&DAT_182f0c920 + lVar4);
      LOCK();
      bVar7 = uVar5 == *(ulonglong *)(&DAT_182f0c920 + lVar4);
      if (bVar7) {
        *(ulonglong *)(&DAT_182f0c920 + lVar4) = uVar5 | 1L << (uVar6 & 0x3f);
      }
      UNLOCK();
    } while (!bVar7);
  }
  uVar3 = FUN_1802c36c0(uRam0000000182d601f0,0x14);
  uVar3 = FUN_1809fef00(uRam0000000182d60230,uVar3,uRam0000000182d601d8);
  *(undefined8 *)(*(longlong *)(DAT_182d58398 + 0xb8) + 8) = uVar3;
  if (DAT_182eb5d50 != 0) {
    uVar6 = (uint)(*(longlong *)(DAT_182d58398 + 0xb8) + 8U >> 0xc);
    lVar4 = (ulonglong)((uVar6 & 0x1fffff) >> 6) * 8;
    do {
      uVar5 = *(ulonglong *)(&DAT_182f0c920 + lVar4);
      LOCK();
      bVar7 = uVar5 == *(ulonglong *)(&DAT_182f0c920 + lVar4);
      if (bVar7) {
        *(ulonglong *)(&DAT_182f0c920 + lVar4) = uVar5 | 1L << (uVar6 & 0x3f);
      }
      UNLOCK();
    } while (!bVar7);
  }
  uVar3 = FUN_1802c36c0(uRam0000000182d601e8,0x14);
  uVar3 = FUN_1809fef00(uRam0000000182d601f8,uVar3,uRam0000000182d601c8);
  *(undefined8 *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x20) = uVar3;
  if (DAT_182eb5d50 != 0) {
    uVar6 = (uint)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x20U >> 0xc);
    lVar4 = (ulonglong)((uVar6 & 0x1fffff) >> 6) * 8;
    do {
      uVar5 = *(ulonglong *)(&DAT_182f0c920 + lVar4);
      LOCK();
      bVar7 = uVar5 == *(ulonglong *)(&DAT_182f0c920 + lVar4);
      if (bVar7) {
        *(ulonglong *)(&DAT_182f0c920 + lVar4) = uVar5 | 1L << (uVar6 & 0x3f);
      }
      UNLOCK();
    } while (!bVar7);
  }
  uVar3 = FUN_1802c36c0(DAT_182d53690,0x14);
  uVar3 = FUN_1809fef00(uRam0000000182d60218,uVar3,uRam0000000182d601c0);
  *(undefined8 *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x28) = uVar3;
  if (DAT_182eb5d50 != 0) {
    uVar6 = (uint)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x28U >> 0xc);
    lVar4 = (ulonglong)((uVar6 & 0x1fffff) >> 6) * 8;
    do {
      uVar5 = *(ulonglong *)(&DAT_182f0c920 + lVar4);
      LOCK();
      bVar7 = uVar5 == *(ulonglong *)(&DAT_182f0c920 + lVar4);
      if (bVar7) {
        *(ulonglong *)(&DAT_182f0c920 + lVar4) = uVar5 | 1L << (uVar6 & 0x3f);
      }
      UNLOCK();
    } while (!bVar7);
  }
  uVar3 = FUN_1802c36c0(DAT_182d60198,0x14);
  uVar3 = FUN_1809fef00(uRam0000000182d60208,uVar3,uRam0000000182d601a8);
  *(undefined8 *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x30) = uVar3;
  if (DAT_182eb5d50 != 0) {
    uVar6 = (uint)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x30U >> 0xc);
    lVar4 = (ulonglong)((uVar6 & 0x1fffff) >> 6) * 8;
    do {
      uVar5 = *(ulonglong *)(&DAT_182f0c920 + lVar4);
      LOCK();
      bVar7 = uVar5 == *(ulonglong *)(&DAT_182f0c920 + lVar4);
      if (bVar7) {
        *(ulonglong *)(&DAT_182f0c920 + lVar4) = uVar5 | 1L << (uVar6 & 0x3f);
      }
      UNLOCK();
    } while (!bVar7);
  }
  uVar3 = FUN_180006620(uRam0000000182d60238,0);
  *(undefined8 *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x10) = uVar3;
  uVar3 = FUN_180006620(uRam0000000182d60200,0);
  *(undefined8 *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x18) = uVar3;
  lVar4 = FUN_1802c43a0(uRam0000000182d601a0);
  if (cRam0000000182eb7b04 == '\0') {
    FUN_1802f2810(0x182d5dd90);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5dd88);
    LOCK();
    UNLOCK();
    cRam0000000182eb7b04 = '\x01';
  }
  uVar3 = FUN_1802c43a0(uRam0000000182d5dd88);
  FUN_180005f20(uVar3);
  bVar7 = DAT_182eb5d50 != 0;
  *(undefined8 *)(lVar4 + 0x20) = uVar3;
  if (bVar7) {
    uVar6 = (uint)(lVar4 + 0x20U >> 0xc);
    lVar1 = (ulonglong)((uVar6 & 0x1fffff) >> 6) * 8;
    do {
      uVar5 = *(ulonglong *)(&DAT_182f0c920 + lVar1);
      LOCK();
      bVar7 = uVar5 == *(ulonglong *)(&DAT_182f0c920 + lVar1);
      if (bVar7) {
        *(ulonglong *)(&DAT_182f0c920 + lVar1) = uVar5 | 1L << (uVar6 & 0x3f);
      }
      UNLOCK();
    } while (!bVar7);
  }
  uVar3 = FUN_1809fef00(uRam0000000182d60228,lVar4,uRam0000000182d601b0);
  *(undefined8 *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x40) = uVar3;
  if (DAT_182eb5d50 != 0) {
    uVar6 = (uint)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x40U >> 0xc);
    lVar4 = (ulonglong)((uVar6 & 0x1fffff) >> 6) * 8;
    do {
      uVar5 = *(ulonglong *)(&DAT_182f0c920 + lVar4);
      LOCK();
      bVar7 = uVar5 == *(ulonglong *)(&DAT_182f0c920 + lVar4);
      if (bVar7) {
        *(ulonglong *)(&DAT_182f0c920 + lVar4) = uVar5 | 1L << (uVar6 & 0x3f);
      }
      UNLOCK();
    } while (!bVar7);
  }
  lVar4 = FUN_1802c43a0(uRam0000000182d601e0);
  *(undefined4 *)(lVar4 + 0x10) = 0x10000;
  *(undefined1 *)(lVar4 + 0x20) = 0;
  *(undefined2 *)(lVar4 + 0x33) = 0x100;
  *(undefined1 *)(lVar4 + 0x28) = 0;
  *(undefined4 *)(lVar4 + 0x2c) = 100;
  *(undefined4 *)(lVar4 + 0x24) = 100;
  *(undefined2 *)(lVar4 + 0x30) = 0;
  *(undefined4 *)(lVar4 + 0x14) = 0x32;
  *(undefined4 *)(lVar4 + 0x18) = 10;
  *(undefined4 *)(lVar4 + 0x35) = 0x1010101;
  *(undefined4 *)(lVar4 + 0x39) = 0x1010101;
  *(undefined2 *)(lVar4 + 0x3d) = 0x101;
  *(undefined4 *)(lVar4 + 0x40) = 100;
  *(undefined4 *)(lVar4 + 0x44) = 100;
  *(undefined1 *)(lVar4 + 0x48) = 1;
  *(undefined4 *)(lVar4 + 0x4c) = 0;
  *(undefined4 *)(lVar4 + 0x50) = 0x32;
  *(undefined4 *)(lVar4 + 0x54) = 0x32;
  *(undefined4 *)(lVar4 + 0x58) = 0x32;
  *(undefined4 *)(lVar4 + 0x5c) = 0x32;
  *(undefined4 *)(lVar4 + 0x60) = 100;
  *(undefined8 *)(lVar4 + 100) = 100;
  *(undefined2 *)(lVar4 + 0x6c) = 0;
  *(undefined4 *)(lVar4 + 0x70) = 0x14;
  *(undefined4 *)(lVar4 + 0x74) = 0x14;
  *(undefined4 *)(lVar4 + 0x78) = 0x1e;
  *(undefined8 *)(lVar4 + 0x7c) = 10;
  *(undefined8 *)(lVar4 + 0x84) = 2;
  *(undefined4 *)(lVar4 + 0x8c) = 0;
  *(undefined4 *)(lVar4 + 0x90) = 0x3c;
  *(undefined4 *)(lVar4 + 0x94) = 0x32;
  *(undefined4 *)(lVar4 + 0x98) = 0x32;
  *(undefined4 *)(lVar4 + 0xa5) = 0x1010101;
  *(undefined4 *)(lVar4 + 0xac) = 0x1e;
  *(undefined4 *)(lVar4 + 0xb4) = 100;
  *(undefined4 *)(lVar4 + 0xb0) = 100;
  *(undefined1 *)(lVar4 + 0xbc) = 1;
  *(undefined1 *)(lVar4 + 0xa4) = 0;
  *(undefined4 *)(lVar4 + 0xb8) = 0;
  *(undefined4 *)(lVar4 + 0x9c) = 0x5a;
  *(undefined4 *)(lVar4 + 0xa0) = 0x55;
  uVar5 = FUN_1809fef00(uRam0000000182d60210,lVar4,uRam0000000182d601b8);
  *(ulonglong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x38) = uVar5;
  if (DAT_182eb5d50 != 0) {
    uVar6 = (uint)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x38U >> 0xc);
    lVar4 = (ulonglong)((uVar6 & 0x1fffff) >> 6) * 8;
    do {
      uVar2 = *(ulonglong *)(&DAT_182f0c920 + lVar4);
      LOCK();
      uVar5 = *(ulonglong *)(&DAT_182f0c920 + lVar4);
      bVar7 = uVar2 == uVar5;
      if (bVar7) {
        *(ulonglong *)(&DAT_182f0c920 + lVar4) = uVar2 | 1L << (uVar6 & 0x3f);
        uVar5 = uVar2;
      }
      UNLOCK();
    } while (!bVar7);
  }
  return uVar5;
}

