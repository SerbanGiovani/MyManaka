// Ghidra pseudocode; not original source or compilable C.
// ev_47c7439fe47d2e67b5829604247316c83aef82f1484d8cefb5728d1f0f1800b6

ulonglong ExposureUnnoticed2_Scripts_InGame_GameStateData___ctor__0600151c(longlong param_1)

{
  undefined4 *puVar1;
  longlong lVar2;
  ulonglong uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  longlong lVar8;
  undefined8 uVar9;
  longlong lVar10;
  ulonglong uVar11;
  ulonglong uVar12;
  int iVar13;
  uint uVar14;
  bool bVar15;
  
  if (cRam0000000182eb7984 == '\0') {
    FUN_1802f2810(0x182d5de70);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5de68);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5de60);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5de58);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5de50);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5de48);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5de40);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5de38);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5de30);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5de28);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5de20);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5de18);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5de10);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5de08);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5de00);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5ddf8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5ddf0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5dde8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5dde0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5ddd8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5ddd0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5ddc8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5ddc0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5ddb8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5ddb0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5dda8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5dda0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5dd98);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5dd90);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5dd88);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5dd80);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d5dd78);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d54a48);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5dd70);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5dd68);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5dd60);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d54b10);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5dd58);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5dd50);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5dd48);
    LOCK();
    UNLOCK();
    cRam0000000182eb7984 = '\x01';
  }
  *(undefined8 *)(param_1 + 0x1a0) = 0xffffffffffffffff;
  uVar9 = FUN_1802c43a0(uRam0000000182d5ddc0);
  FUN_180e686d0(uVar9,uRam0000000182d5de30);
  bVar15 = DAT_182eb5d50 != 0;
  *(undefined8 *)(param_1 + 0x1d0) = uVar9;
  if (bVar15) {
    uVar14 = (uint)(param_1 + 0x1d0U >> 0xc);
    uVar11 = (ulonglong)((uVar14 & 0x1fffff) >> 6);
    do {
      uVar12 = *(ulonglong *)(&DAT_182f0c920 + uVar11 * 8);
      LOCK();
      bVar15 = uVar12 == *(ulonglong *)(&DAT_182f0c920 + uVar11 * 8);
      if (bVar15) {
        *(ulonglong *)(&DAT_182f0c920 + uVar11 * 8) = uVar12 | 1L << (ulonglong)(uVar14 & 0x3f);
      }
      UNLOCK();
    } while (!bVar15);
  }
  uVar9 = FUN_1802c43a0(uRam0000000182d5ddd0);
  FUN_180e686d0(uVar9,uRam0000000182d5de58);
  bVar15 = DAT_182eb5d50 != 0;
  *(undefined8 *)(param_1 + 0x200) = uVar9;
  if (bVar15) {
    uVar14 = (uint)(param_1 + 0x200U >> 0xc);
    uVar11 = (ulonglong)((uVar14 & 0x1fffff) >> 6);
    do {
      uVar12 = *(ulonglong *)(&DAT_182f0c920 + uVar11 * 8);
      LOCK();
      bVar15 = uVar12 == *(ulonglong *)(&DAT_182f0c920 + uVar11 * 8);
      if (bVar15) {
        *(ulonglong *)(&DAT_182f0c920 + uVar11 * 8) = uVar12 | 1L << (ulonglong)(uVar14 & 0x3f);
      }
      UNLOCK();
    } while (!bVar15);
  }
  uVar9 = FUN_1802c43a0(uRam0000000182d5dde0);
  FUN_180e686d0(uVar9,uRam0000000182d5de28);
  bVar15 = DAT_182eb5d50 != 0;
  *(undefined8 *)(param_1 + 0x208) = uVar9;
  if (bVar15) {
    uVar14 = (uint)(param_1 + 0x208U >> 0xc);
    uVar11 = (ulonglong)((uVar14 & 0x1fffff) >> 6);
    do {
      uVar12 = *(ulonglong *)(&DAT_182f0c920 + uVar11 * 8);
      LOCK();
      bVar15 = uVar12 == *(ulonglong *)(&DAT_182f0c920 + uVar11 * 8);
      if (bVar15) {
        *(ulonglong *)(&DAT_182f0c920 + uVar11 * 8) = uVar12 | 1L << (ulonglong)(uVar14 & 0x3f);
      }
      UNLOCK();
    } while (!bVar15);
  }
  uVar9 = FUN_1802c43a0(uRam0000000182d5ddc8);
  FUN_180e686d0(uVar9,uRam0000000182d5de18);
  bVar15 = DAT_182eb5d50 != 0;
  *(undefined8 *)(param_1 + 0x210) = uVar9;
  if (bVar15) {
    uVar14 = (uint)(param_1 + 0x210U >> 0xc);
    uVar11 = (ulonglong)((uVar14 & 0x1fffff) >> 6);
    do {
      uVar12 = *(ulonglong *)(&DAT_182f0c920 + uVar11 * 8);
      LOCK();
      bVar15 = uVar12 == *(ulonglong *)(&DAT_182f0c920 + uVar11 * 8);
      if (bVar15) {
        *(ulonglong *)(&DAT_182f0c920 + uVar11 * 8) = uVar12 | 1L << (ulonglong)(uVar14 & 0x3f);
      }
      UNLOCK();
    } while (!bVar15);
  }
  uVar9 = FUN_1802c43a0(uRam0000000182d5ddb8);
  FUN_180e686d0(uVar9,uRam0000000182d5de70);
  bVar15 = DAT_182eb5d50 != 0;
  *(undefined8 *)(param_1 + 0x218) = uVar9;
  if (bVar15) {
    uVar14 = (uint)(param_1 + 0x218U >> 0xc);
    uVar11 = (ulonglong)((uVar14 & 0x1fffff) >> 6);
    do {
      uVar12 = *(ulonglong *)(&DAT_182f0c920 + uVar11 * 8);
      LOCK();
      bVar15 = uVar12 == *(ulonglong *)(&DAT_182f0c920 + uVar11 * 8);
      if (bVar15) {
        *(ulonglong *)(&DAT_182f0c920 + uVar11 * 8) = uVar12 | 1L << (ulonglong)(uVar14 & 0x3f);
      }
      UNLOCK();
    } while (!bVar15);
  }
  uVar9 = FUN_1802c43a0(uRam0000000182d5de00);
  FUN_180005e90(uVar9);
  bVar15 = DAT_182eb5d50 != 0;
  *(undefined8 *)(param_1 + 0x220) = uVar9;
  if (bVar15) {
    uVar14 = (uint)(param_1 + 0x220U >> 0xc);
    uVar11 = (ulonglong)((uVar14 & 0x1fffff) >> 6);
    do {
      uVar12 = *(ulonglong *)(&DAT_182f0c920 + uVar11 * 8);
      LOCK();
      bVar15 = uVar12 == *(ulonglong *)(&DAT_182f0c920 + uVar11 * 8);
      if (bVar15) {
        *(ulonglong *)(&DAT_182f0c920 + uVar11 * 8) = uVar12 | 1L << (ulonglong)(uVar14 & 0x3f);
      }
      UNLOCK();
    } while (!bVar15);
  }
  uVar9 = FUN_1802c43a0(uRam0000000182d5dda8);
  FUN_180e686d0(uVar9,uRam0000000182d5de10);
  bVar15 = DAT_182eb5d50 != 0;
  *(undefined8 *)(param_1 + 0x228) = uVar9;
  if (bVar15) {
    uVar14 = (uint)(param_1 + 0x228U >> 0xc);
    uVar11 = (ulonglong)((uVar14 & 0x1fffff) >> 6);
    do {
      uVar12 = *(ulonglong *)(&DAT_182f0c920 + uVar11 * 8);
      LOCK();
      bVar15 = uVar12 == *(ulonglong *)(&DAT_182f0c920 + uVar11 * 8);
      if (bVar15) {
        *(ulonglong *)(&DAT_182f0c920 + uVar11 * 8) = uVar12 | 1L << (ulonglong)(uVar14 & 0x3f);
      }
      UNLOCK();
    } while (!bVar15);
  }
  uVar9 = FUN_1802c43a0(uRam0000000182d5ddf8);
  FUN_180e2cdf0(uVar9,uRam0000000182d5de40);
  bVar15 = DAT_182eb5d50 != 0;
  *(undefined8 *)(param_1 + 0x230) = uVar9;
  if (bVar15) {
    uVar14 = (uint)(param_1 + 0x230U >> 0xc);
    uVar11 = (ulonglong)((uVar14 & 0x1fffff) >> 6);
    do {
      uVar12 = *(ulonglong *)(&DAT_182f0c920 + uVar11 * 8);
      LOCK();
      bVar15 = uVar12 == *(ulonglong *)(&DAT_182f0c920 + uVar11 * 8);
      if (bVar15) {
        *(ulonglong *)(&DAT_182f0c920 + uVar11 * 8) = uVar12 | 1L << (ulonglong)(uVar14 & 0x3f);
      }
      UNLOCK();
    } while (!bVar15);
  }
  uVar9 = FUN_1802c43a0(uRam0000000182d5dd98);
  FUN_180e686d0(uVar9,uRam0000000182d5de50);
  bVar15 = DAT_182eb5d50 != 0;
  *(undefined8 *)(param_1 + 0x238) = uVar9;
  if (bVar15) {
    uVar14 = (uint)(param_1 + 0x238U >> 0xc);
    uVar11 = (ulonglong)((uVar14 & 0x1fffff) >> 6);
    do {
      uVar12 = *(ulonglong *)(&DAT_182f0c920 + uVar11 * 8);
      LOCK();
      bVar15 = uVar12 == *(ulonglong *)(&DAT_182f0c920 + uVar11 * 8);
      if (bVar15) {
        *(ulonglong *)(&DAT_182f0c920 + uVar11 * 8) = uVar12 | 1L << (ulonglong)(uVar14 & 0x3f);
      }
      UNLOCK();
    } while (!bVar15);
  }
  *(undefined4 *)(param_1 + 0x34) = 2;
  *(undefined4 *)(param_1 + 0xbc) = 0xffffffff;
  uVar9 = FUN_1802c43a0(uRam0000000182d5dd48);
  FUN_1811cf4f0(uVar9,uRam0000000182d5dd60);
  bVar15 = DAT_182eb5d50 != 0;
  *(undefined8 *)(param_1 + 200) = uVar9;
  if (bVar15) {
    uVar14 = (uint)(param_1 + 200U >> 0xc);
    uVar11 = (ulonglong)((uVar14 & 0x1fffff) >> 6);
    do {
      uVar12 = *(ulonglong *)(&DAT_182f0c920 + uVar11 * 8);
      LOCK();
      bVar15 = uVar12 == *(ulonglong *)(&DAT_182f0c920 + uVar11 * 8);
      if (bVar15) {
        *(ulonglong *)(&DAT_182f0c920 + uVar11 * 8) = uVar12 | 1L << (ulonglong)(uVar14 & 0x3f);
      }
      UNLOCK();
    } while (!bVar15);
  }
  *(undefined8 *)(param_1 + 0x50) = 0xffffffffffffffff;
  *(undefined4 *)(param_1 + 0x10) = 0;
  *(undefined8 *)(param_1 + 0x58) = 0xffffffffffffffff;
  *(undefined8 *)(param_1 + 0x60) = 0xffffffffffffffff;
  *(undefined8 *)(param_1 + 0x68) = 0xffffffffffffffff;
  *(undefined4 *)(param_1 + 0x78) = 0xffffffff;
  uVar9 = ExposureUnnoticed2_Scripts_InGame_GameStateFacade__GetDefaultDropDataDict__06001543(0);
  bVar15 = DAT_182eb5d50 != 0;
  *(undefined8 *)(param_1 + 0x18) = uVar9;
  if (bVar15) {
    uVar14 = (uint)(param_1 + 0x18U >> 0xc);
    uVar11 = (ulonglong)((uVar14 & 0x1fffff) >> 6);
    do {
      uVar12 = *(ulonglong *)(&DAT_182f0c920 + uVar11 * 8);
      LOCK();
      bVar15 = uVar12 == *(ulonglong *)(&DAT_182f0c920 + uVar11 * 8);
      if (bVar15) {
        *(ulonglong *)(&DAT_182f0c920 + uVar11 * 8) = uVar12 | 1L << (ulonglong)(uVar14 & 0x3f);
      }
      UNLOCK();
    } while (!bVar15);
  }
  uVar9 = FUN_1802c43a0(uRam0000000182d5ddd8);
  FUN_180e2cdf0(uVar9,uRam0000000182d5de20);
  bVar15 = DAT_182eb5d50 != 0;
  *(undefined8 *)(param_1 + 0x88) = uVar9;
  if (bVar15) {
    uVar14 = (uint)(param_1 + 0x88U >> 0xc);
    uVar11 = (ulonglong)((uVar14 & 0x1fffff) >> 6);
    do {
      uVar12 = *(ulonglong *)(&DAT_182f0c920 + uVar11 * 8);
      LOCK();
      bVar15 = uVar12 == *(ulonglong *)(&DAT_182f0c920 + uVar11 * 8);
      if (bVar15) {
        *(ulonglong *)(&DAT_182f0c920 + uVar11 * 8) = uVar12 | 1L << (ulonglong)(uVar14 & 0x3f);
      }
      UNLOCK();
    } while (!bVar15);
  }
  uVar9 = FUN_1802c43a0(uRam0000000182d5dd88);
  FUN_180005f20(uVar9);
  bVar15 = DAT_182eb5d50 != 0;
  *(undefined8 *)(param_1 + 0x70) = uVar9;
  if (bVar15) {
    uVar14 = (uint)(param_1 + 0x70U >> 0xc);
    uVar11 = (ulonglong)((uVar14 & 0x1fffff) >> 6);
    do {
      uVar12 = *(ulonglong *)(&DAT_182f0c920 + uVar11 * 8);
      LOCK();
      bVar15 = uVar12 == *(ulonglong *)(&DAT_182f0c920 + uVar11 * 8);
      if (bVar15) {
        *(ulonglong *)(&DAT_182f0c920 + uVar11 * 8) = uVar12 | 1L << (ulonglong)(uVar14 & 0x3f);
      }
      UNLOCK();
    } while (!bVar15);
  }
  uVar9 = FUN_1802c43a0(uRam0000000182d5dd58);
  FUN_1811cf4f0(uVar9,uRam0000000182d5dd68);
  bVar15 = DAT_182eb5d50 != 0;
  *(undefined8 *)(param_1 + 0x28) = uVar9;
  if (bVar15) {
    uVar14 = (uint)(param_1 + 0x28U >> 0xc);
    uVar11 = (ulonglong)((uVar14 & 0x1fffff) >> 6);
    do {
      uVar12 = *(ulonglong *)(&DAT_182f0c920 + uVar11 * 8);
      LOCK();
      bVar15 = uVar12 == *(ulonglong *)(&DAT_182f0c920 + uVar11 * 8);
      if (bVar15) {
        *(ulonglong *)(&DAT_182f0c920 + uVar11 * 8) = uVar12 | 1L << (ulonglong)(uVar14 & 0x3f);
      }
      UNLOCK();
    } while (!bVar15);
  }
  uVar9 = FUN_1802c43a0(uRam0000000182d5dd50);
  FUN_1811cf4f0(uVar9,uRam0000000182d5dd70);
  bVar15 = DAT_182eb5d50 != 0;
  *(undefined8 *)(param_1 + 0x40) = uVar9;
  if (bVar15) {
    uVar14 = (uint)(param_1 + 0x40U >> 0xc);
    uVar11 = (ulonglong)((uVar14 & 0x1fffff) >> 6);
    do {
      uVar12 = *(ulonglong *)(&DAT_182f0c920 + uVar11 * 8);
      LOCK();
      bVar15 = uVar12 == *(ulonglong *)(&DAT_182f0c920 + uVar11 * 8);
      if (bVar15) {
        *(ulonglong *)(&DAT_182f0c920 + uVar11 * 8) = uVar12 | 1L << (ulonglong)(uVar14 & 0x3f);
      }
      UNLOCK();
    } while (!bVar15);
  }
  uVar9 = FUN_1802c43a0(DAT_182d54b10);
  FUN_180003c90(uVar9,DAT_182d54a48);
  bVar15 = DAT_182eb5d50 != 0;
  *(undefined8 *)(param_1 + 0x38) = uVar9;
  if (bVar15) {
    uVar14 = (uint)(param_1 + 0x38U >> 0xc);
    uVar11 = (ulonglong)((uVar14 & 0x1fffff) >> 6);
    do {
      uVar12 = *(ulonglong *)(&DAT_182f0c920 + uVar11 * 8);
      LOCK();
      bVar15 = uVar12 == *(ulonglong *)(&DAT_182f0c920 + uVar11 * 8);
      if (bVar15) {
        *(ulonglong *)(&DAT_182f0c920 + uVar11 * 8) = uVar12 | 1L << (ulonglong)(uVar14 & 0x3f);
      }
      UNLOCK();
    } while (!bVar15);
  }
  uVar9 = FUN_1802c43a0(uRam0000000182d5ddb0);
  FUN_180005fe0(uVar9,uRam0000000182d5de38);
  bVar15 = DAT_182eb5d50 != 0;
  *(undefined8 *)(param_1 + 0xf0) = uVar9;
  if (bVar15) {
    uVar14 = (uint)(param_1 + 0xf0U >> 0xc);
    uVar11 = (ulonglong)((uVar14 & 0x1fffff) >> 6);
    do {
      uVar12 = *(ulonglong *)(&DAT_182f0c920 + uVar11 * 8);
      LOCK();
      bVar15 = uVar12 == *(ulonglong *)(&DAT_182f0c920 + uVar11 * 8);
      if (bVar15) {
        *(ulonglong *)(&DAT_182f0c920 + uVar11 * 8) = uVar12 | 1L << (ulonglong)(uVar14 & 0x3f);
      }
      UNLOCK();
    } while (!bVar15);
  }
  uVar9 = FUN_1802c43a0(uRam0000000182d5dde8);
  FUN_180006070(uVar9);
  bVar15 = DAT_182eb5d50 != 0;
  *(undefined8 *)(param_1 + 0x100) = uVar9;
  if (bVar15) {
    uVar14 = (uint)(param_1 + 0x100U >> 0xc);
    uVar11 = (ulonglong)((uVar14 & 0x1fffff) >> 6);
    do {
      uVar12 = *(ulonglong *)(&DAT_182f0c920 + uVar11 * 8);
      LOCK();
      bVar15 = uVar12 == *(ulonglong *)(&DAT_182f0c920 + uVar11 * 8);
      if (bVar15) {
        *(ulonglong *)(&DAT_182f0c920 + uVar11 * 8) = uVar12 | 1L << (ulonglong)(uVar14 & 0x3f);
      }
      UNLOCK();
    } while (!bVar15);
  }
  uVar9 = FUN_1802c43a0(uRam0000000182d5ddb0);
  FUN_180005fe0(uVar9,uRam0000000182d5de38);
  bVar15 = DAT_182eb5d50 != 0;
  *(undefined8 *)(param_1 + 0x118) = uVar9;
  if (bVar15) {
    uVar14 = (uint)(param_1 + 0x118U >> 0xc);
    uVar11 = (ulonglong)((uVar14 & 0x1fffff) >> 6);
    do {
      uVar12 = *(ulonglong *)(&DAT_182f0c920 + uVar11 * 8);
      LOCK();
      bVar15 = uVar12 == *(ulonglong *)(&DAT_182f0c920 + uVar11 * 8);
      if (bVar15) {
        *(ulonglong *)(&DAT_182f0c920 + uVar11 * 8) = uVar12 | 1L << (ulonglong)(uVar14 & 0x3f);
      }
      UNLOCK();
    } while (!bVar15);
  }
  uVar9 = FUN_1802c43a0(uRam0000000182d5ddb0);
  FUN_180005fe0(uVar9,uRam0000000182d5de38);
  bVar15 = DAT_182eb5d50 != 0;
  *(undefined8 *)(param_1 + 0xf8) = uVar9;
  if (bVar15) {
    uVar14 = (uint)(param_1 + 0xf8U >> 0xc);
    uVar11 = (ulonglong)((uVar14 & 0x1fffff) >> 6);
    do {
      uVar12 = *(ulonglong *)(&DAT_182f0c920 + uVar11 * 8);
      LOCK();
      bVar15 = uVar12 == *(ulonglong *)(&DAT_182f0c920 + uVar11 * 8);
      if (bVar15) {
        *(ulonglong *)(&DAT_182f0c920 + uVar11 * 8) = uVar12 | 1L << (ulonglong)(uVar14 & 0x3f);
      }
      UNLOCK();
    } while (!bVar15);
  }
  uVar9 = FUN_1802c43a0(uRam0000000182d5dde8);
  FUN_180006070(uVar9);
  bVar15 = DAT_182eb5d50 != 0;
  *(undefined8 *)(param_1 + 0x108) = uVar9;
  if (bVar15) {
    uVar14 = (uint)(param_1 + 0x108U >> 0xc);
    uVar11 = (ulonglong)((uVar14 & 0x1fffff) >> 6);
    do {
      uVar12 = *(ulonglong *)(&DAT_182f0c920 + uVar11 * 8);
      LOCK();
      bVar15 = uVar12 == *(ulonglong *)(&DAT_182f0c920 + uVar11 * 8);
      if (bVar15) {
        *(ulonglong *)(&DAT_182f0c920 + uVar11 * 8) = uVar12 | 1L << (ulonglong)(uVar14 & 0x3f);
      }
      UNLOCK();
    } while (!bVar15);
  }
  uVar9 = FUN_1802c43a0(uRam0000000182d5dde8);
  FUN_180006070(uVar9);
  bVar15 = DAT_182eb5d50 != 0;
  *(undefined8 *)(param_1 + 0x110) = uVar9;
  if (bVar15) {
    uVar14 = (uint)(param_1 + 0x110U >> 0xc);
    uVar11 = (ulonglong)((uVar14 & 0x1fffff) >> 6);
    do {
      uVar12 = *(ulonglong *)(&DAT_182f0c920 + uVar11 * 8);
      LOCK();
      bVar15 = uVar12 == *(ulonglong *)(&DAT_182f0c920 + uVar11 * 8);
      if (bVar15) {
        *(ulonglong *)(&DAT_182f0c920 + uVar11 * 8) = uVar12 | 1L << (ulonglong)(uVar14 & 0x3f);
      }
      UNLOCK();
    } while (!bVar15);
  }
  uVar9 = FUN_1802c43a0(uRam0000000182d5ddb0);
  FUN_180005fe0(uVar9,uRam0000000182d5de38);
  bVar15 = DAT_182eb5d50 != 0;
  *(undefined8 *)(param_1 + 0xd0) = uVar9;
  if (bVar15) {
    uVar14 = (uint)(param_1 + 0xd0U >> 0xc);
    uVar11 = (ulonglong)((uVar14 & 0x1fffff) >> 6);
    do {
      uVar12 = *(ulonglong *)(&DAT_182f0c920 + uVar11 * 8);
      LOCK();
      bVar15 = uVar12 == *(ulonglong *)(&DAT_182f0c920 + uVar11 * 8);
      if (bVar15) {
        *(ulonglong *)(&DAT_182f0c920 + uVar11 * 8) = uVar12 | 1L << (ulonglong)(uVar14 & 0x3f);
      }
      UNLOCK();
    } while (!bVar15);
  }
  uVar9 = FUN_1802c43a0(uRam0000000182d5ddf0);
  FUN_180e686d0(uVar9,uRam0000000182d5de60);
  bVar15 = DAT_182eb5d50 != 0;
  *(undefined8 *)(param_1 + 0xd8) = uVar9;
  if (bVar15) {
    uVar14 = (uint)(param_1 + 0xd8U >> 0xc);
    uVar11 = (ulonglong)((uVar14 & 0x1fffff) >> 6);
    do {
      uVar12 = *(ulonglong *)(&DAT_182f0c920 + uVar11 * 8);
      LOCK();
      bVar15 = uVar12 == *(ulonglong *)(&DAT_182f0c920 + uVar11 * 8);
      if (bVar15) {
        *(ulonglong *)(&DAT_182f0c920 + uVar11 * 8) = uVar12 | 1L << (ulonglong)(uVar14 & 0x3f);
      }
      UNLOCK();
    } while (!bVar15);
  }
  uVar9 = FUN_1802c43a0(uRam0000000182d5ddf0);
  FUN_180e686d0(uVar9,uRam0000000182d5de60);
  bVar15 = DAT_182eb5d50 != 0;
  *(undefined8 *)(param_1 + 0xe0) = uVar9;
  if (bVar15) {
    uVar14 = (uint)(param_1 + 0xe0U >> 0xc);
    uVar11 = (ulonglong)((uVar14 & 0x1fffff) >> 6);
    do {
      uVar12 = *(ulonglong *)(&DAT_182f0c920 + uVar11 * 8);
      LOCK();
      bVar15 = uVar12 == *(ulonglong *)(&DAT_182f0c920 + uVar11 * 8);
      if (bVar15) {
        *(ulonglong *)(&DAT_182f0c920 + uVar11 * 8) = uVar12 | 1L << (ulonglong)(uVar14 & 0x3f);
      }
      UNLOCK();
    } while (!bVar15);
  }
  uVar9 = FUN_1802c43a0(uRam0000000182d5dda0);
  FUN_180e686d0(uVar9,uRam0000000182d5de08);
  bVar15 = DAT_182eb5d50 != 0;
  *(undefined8 *)(param_1 + 0xe8) = uVar9;
  if (bVar15) {
    uVar14 = (uint)(param_1 + 0xe8U >> 0xc);
    uVar11 = (ulonglong)((uVar14 & 0x1fffff) >> 6);
    do {
      uVar12 = *(ulonglong *)(&DAT_182f0c920 + uVar11 * 8);
      LOCK();
      bVar15 = uVar12 == *(ulonglong *)(&DAT_182f0c920 + uVar11 * 8);
      if (bVar15) {
        *(ulonglong *)(&DAT_182f0c920 + uVar11 * 8) = uVar12 | 1L << (ulonglong)(uVar14 & 0x3f);
      }
      UNLOCK();
    } while (!bVar15);
  }
  if (DAT_182eb547f == '\0') {
    FUN_1802f2810(&DAT_182d52290);
    LOCK();
    UNLOCK();
    DAT_182eb547f = '\x01';
  }
  bVar15 = cRam0000000182eb79a8 == '\0';
  puVar1 = *(undefined4 **)(DAT_182d52290 + 0xb8);
  uVar4 = *puVar1;
  uVar5 = puVar1[1];
  uVar6 = puVar1[2];
  uVar7 = puVar1[3];
  *(undefined4 *)(param_1 + 0x1b8) = 0;
  *(undefined4 *)(param_1 + 0x18c) = uVar4;
  *(undefined4 *)(param_1 + 400) = uVar5;
  *(undefined4 *)(param_1 + 0x194) = uVar6;
  *(undefined4 *)(param_1 + 0x198) = uVar7;
  if (bVar15) {
    FUN_1802f2810(0x182d5dcc8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5de58);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5ddd0);
    LOCK();
    UNLOCK();
    cRam0000000182eb79a8 = '\x01';
  }
  lVar10 = FUN_1802c43a0(uRam0000000182d5ddd0);
  FUN_180e686d0(lVar10,uRam0000000182d5de58);
  if (lVar10 != 0) {
    FUN_180e6cbf0(lVar10,0,1,2,
                  *(undefined8 *)
                   (*(longlong *)(*(longlong *)(lRam0000000182d5dcc8 + 0x20) + 0xc0) + 0x100));
    bVar15 = DAT_182eb5d50 != 0;
    *(longlong *)(param_1 + 0x200) = lVar10;
    if (bVar15) {
      uVar14 = (uint)(param_1 + 0x200U >> 0xc);
      uVar11 = (ulonglong)((uVar14 & 0x1fffff) >> 6);
      do {
        uVar12 = *(ulonglong *)(&DAT_182f0c920 + uVar11 * 8);
        LOCK();
        bVar15 = uVar12 == *(ulonglong *)(&DAT_182f0c920 + uVar11 * 8);
        if (bVar15) {
          *(ulonglong *)(&DAT_182f0c920 + uVar11 * 8) = uVar12 | 1L << (ulonglong)(uVar14 & 0x3f);
        }
        UNLOCK();
      } while (!bVar15);
    }
    uVar9 = FUN_1802c43a0(uRam0000000182d5dde0);
    FUN_180e686d0(uVar9,uRam0000000182d5de28);
    bVar15 = DAT_182eb5d50 != 0;
    *(undefined8 *)(param_1 + 0x208) = uVar9;
    if (bVar15) {
      uVar14 = (uint)(param_1 + 0x208U >> 0xc);
      uVar11 = (ulonglong)((uVar14 & 0x1fffff) >> 6);
      do {
        uVar12 = *(ulonglong *)(&DAT_182f0c920 + uVar11 * 8);
        LOCK();
        bVar15 = uVar12 == *(ulonglong *)(&DAT_182f0c920 + uVar11 * 8);
        if (bVar15) {
          *(ulonglong *)(&DAT_182f0c920 + uVar11 * 8) = uVar12 | 1L << (ulonglong)(uVar14 & 0x3f);
        }
        UNLOCK();
      } while (!bVar15);
    }
    if (cRam0000000182eb79a9 == '\0') {
      FUN_1802f2810(0x182d5de18);
      LOCK();
      UNLOCK();
      FUN_1802f2810(0x182d5ddc8);
      LOCK();
      UNLOCK();
      cRam0000000182eb79a9 = '\x01';
    }
    uVar9 = FUN_1802c43a0(uRam0000000182d5ddc8);
    FUN_180e686d0(uVar9,uRam0000000182d5de18);
    bVar15 = DAT_182eb5d50 != 0;
    *(undefined8 *)(param_1 + 0x210) = uVar9;
    if (bVar15) {
      uVar14 = (uint)(param_1 + 0x210U >> 0xc);
      uVar11 = (ulonglong)((uVar14 & 0x1fffff) >> 6);
      do {
        uVar12 = *(ulonglong *)(&DAT_182f0c920 + uVar11 * 8);
        LOCK();
        bVar15 = uVar12 == *(ulonglong *)(&DAT_182f0c920 + uVar11 * 8);
        if (bVar15) {
          *(ulonglong *)(&DAT_182f0c920 + uVar11 * 8) = uVar12 | 1L << (ulonglong)(uVar14 & 0x3f);
        }
        UNLOCK();
      } while (!bVar15);
    }
    uVar9 = FUN_1802c43a0(uRam0000000182d5ddb8);
    FUN_180e686d0(uVar9,uRam0000000182d5de70);
    bVar15 = DAT_182eb5d50 != 0;
    *(undefined8 *)(param_1 + 0x218) = uVar9;
    if (bVar15) {
      uVar14 = (uint)(param_1 + 0x218U >> 0xc);
      uVar11 = (ulonglong)((uVar14 & 0x1fffff) >> 6);
      do {
        uVar12 = *(ulonglong *)(&DAT_182f0c920 + uVar11 * 8);
        LOCK();
        bVar15 = uVar12 == *(ulonglong *)(&DAT_182f0c920 + uVar11 * 8);
        if (bVar15) {
          *(ulonglong *)(&DAT_182f0c920 + uVar11 * 8) = uVar12 | 1L << (ulonglong)(uVar14 & 0x3f);
        }
        UNLOCK();
      } while (!bVar15);
    }
    uVar9 = ExposureUnnoticed2_Scripts_InGame_GameStateFacade__GetDefaultSkillDict__06001542(0);
    bVar15 = DAT_182eb5d50 != 0;
    *(undefined8 *)(param_1 + 0x1f8) = uVar9;
    if (bVar15) {
      uVar14 = (uint)(param_1 + 0x1f8U >> 0xc);
      uVar11 = (ulonglong)((uVar14 & 0x1fffff) >> 6);
      do {
        uVar12 = *(ulonglong *)(&DAT_182f0c920 + uVar11 * 8);
        LOCK();
        bVar15 = uVar12 == *(ulonglong *)(&DAT_182f0c920 + uVar11 * 8);
        if (bVar15) {
          *(ulonglong *)(&DAT_182f0c920 + uVar11 * 8) = uVar12 | 1L << (ulonglong)(uVar14 & 0x3f);
        }
        UNLOCK();
      } while (!bVar15);
    }
    *(undefined4 *)(param_1 + 0x16c) = 0x43160000;
    *(undefined4 *)(param_1 + 0x19c) = 0;
    *(undefined4 *)(param_1 + 0x1c4) = 0;
    *(undefined4 *)(param_1 + 0x1c8) = 10;
    *(undefined4 *)(param_1 + 0x1ac) = 3;
    *(undefined4 *)(param_1 + 0x1bc) = 1;
    *(undefined4 *)(param_1 + 0x1c0) = 1;
    uVar9 = FUN_1802c43a0(uRam0000000182d5ddc0);
    FUN_180e686d0(uVar9,uRam0000000182d5de30);
    bVar15 = DAT_182eb5d50 != 0;
    *(undefined8 *)(param_1 + 0x1d0) = uVar9;
    if (bVar15) {
      uVar14 = (uint)(param_1 + 0x1d0U >> 0xc);
      uVar11 = (ulonglong)((uVar14 & 0x1fffff) >> 6);
      do {
        uVar12 = *(ulonglong *)(&DAT_182f0c920 + uVar11 * 8);
        LOCK();
        bVar15 = uVar12 == *(ulonglong *)(&DAT_182f0c920 + uVar11 * 8);
        if (bVar15) {
          *(ulonglong *)(&DAT_182f0c920 + uVar11 * 8) = uVar12 | 1L << (ulonglong)(uVar14 & 0x3f);
        }
        UNLOCK();
      } while (!bVar15);
    }
    if (cRam0000000182eb79aa == '\0') {
      FUN_1802f2810(&DAT_182d5dbc0);
      LOCK();
      UNLOCK();
      FUN_1802f2810(0x182d5de68);
      LOCK();
      UNLOCK();
      FUN_1802f2810(0x182d5de00);
      LOCK();
      UNLOCK();
      cRam0000000182eb79aa = '\x01';
    }
    lVar10 = FUN_1802c43a0(uRam0000000182d5de00);
    FUN_180005e90(lVar10);
    if (lVar10 != 0) {
      FUN_180e44740(lVar10,0x4e2b,1,2,
                    *(undefined8 *)
                     (*(longlong *)(*(longlong *)(DAT_182d5dbc0 + 0x20) + 0xc0) + 0x100));
      bVar15 = DAT_182eb5d50 != 0;
      *(longlong *)(param_1 + 0x220) = lVar10;
      if (bVar15) {
        uVar14 = (uint)(param_1 + 0x220U >> 0xc);
        uVar11 = (ulonglong)((uVar14 & 0x1fffff) >> 6);
        do {
          uVar12 = *(ulonglong *)(&DAT_182f0c920 + uVar11 * 8);
          LOCK();
          bVar15 = uVar12 == *(ulonglong *)(&DAT_182f0c920 + uVar11 * 8);
          if (bVar15) {
            *(ulonglong *)(&DAT_182f0c920 + uVar11 * 8) = uVar12 | 1L << (uVar14 & 0x3f);
          }
          UNLOCK();
        } while (!bVar15);
      }
      *(undefined4 *)(param_1 + 0x1d8) = 0;
      uVar9 = ExposureUnnoticed2_Scripts_InGame_GameStateFacade__CreateDefaultReinforceEffectAdultGoods__06001561
                        (0);
      bVar15 = DAT_182eb5d50 != 0;
      *(undefined8 *)(param_1 + 0x228) = uVar9;
      if (bVar15) {
        uVar14 = (uint)(param_1 + 0x228U >> 0xc);
        uVar11 = (ulonglong)((uVar14 & 0x1fffff) >> 6);
        do {
          uVar12 = *(ulonglong *)(&DAT_182f0c920 + uVar11 * 8);
          LOCK();
          bVar15 = uVar12 == *(ulonglong *)(&DAT_182f0c920 + uVar11 * 8);
          if (bVar15) {
            *(ulonglong *)(&DAT_182f0c920 + uVar11 * 8) = uVar12 | 1L << (uVar14 & 0x3f);
          }
          UNLOCK();
        } while (!bVar15);
      }
      uVar9 = ExposureUnnoticed2_Scripts_InGame_GameStateFacade__CreateDefaultReinforceEffectCosplayParts__06001562
                        (0);
      bVar15 = DAT_182eb5d50 != 0;
      *(undefined8 *)(param_1 + 0x230) = uVar9;
      if (bVar15) {
        uVar14 = (uint)(param_1 + 0x230U >> 0xc);
        uVar11 = (ulonglong)((uVar14 & 0x1fffff) >> 6);
        do {
          uVar12 = *(ulonglong *)(&DAT_182f0c920 + uVar11 * 8);
          LOCK();
          bVar15 = uVar12 == *(ulonglong *)(&DAT_182f0c920 + uVar11 * 8);
          if (bVar15) {
            *(ulonglong *)(&DAT_182f0c920 + uVar11 * 8) = uVar12 | 1L << (uVar14 & 0x3f);
          }
          UNLOCK();
        } while (!bVar15);
      }
      uVar9 = ExposureUnnoticed2_Scripts_InGame_GameStateFacade__CreateDefaultReinforceEffectCostume__06001563
                        (0);
      bVar15 = DAT_182eb5d50 != 0;
      *(undefined8 *)(param_1 + 0x238) = uVar9;
      if (bVar15) {
        uVar14 = (uint)(param_1 + 0x238U >> 0xc);
        uVar11 = (ulonglong)((uVar14 & 0x1fffff) >> 6);
        do {
          uVar12 = *(ulonglong *)(&DAT_182f0c920 + uVar11 * 8);
          LOCK();
          bVar15 = uVar12 == *(ulonglong *)(&DAT_182f0c920 + uVar11 * 8);
          if (bVar15) {
            *(ulonglong *)(&DAT_182f0c920 + uVar11 * 8) = uVar12 | 1L << (uVar14 & 0x3f);
          }
          UNLOCK();
        } while (!bVar15);
      }
      if (cRam0000000182eb79c7 == '\0') {
        FUN_1802f2810(0x182d5d940);
        LOCK();
        UNLOCK();
        FUN_1802f2810(0x182d5d938);
        LOCK();
        UNLOCK();
        FUN_1802f2810(0x182d5d930);
        LOCK();
        UNLOCK();
        FUN_1802f2810(0x182d5d928);
        LOCK();
        UNLOCK();
        cRam0000000182eb79c7 = '\x01';
      }
      lVar10 = FUN_1802c43a0(uRam0000000182d5d930);
      FUN_1811cf4f0(lVar10,uRam0000000182d5d938);
      iVar13 = 0;
      do {
        uVar9 = FUN_1802c43a0(uRam0000000182d5d928);
        ExposureUnnoticed2_ObjectUI_InventoryPanel_LoadoutData___ctor__060019e9(uVar9,0);
        lVar8 = lRam0000000182d5d940;
        if (lVar10 == 0) goto code_r0x00018048d3d2;
        *(int *)(lVar10 + 0x1c) = *(int *)(lVar10 + 0x1c) + 1;
        lVar2 = *(longlong *)(lVar10 + 0x10);
        if (lVar2 == 0) goto code_r0x00018048d3d2;
        uVar14 = *(uint *)(lVar10 + 0x18);
        if (uVar14 < *(uint *)(lVar2 + 0x18)) {
          *(uint *)(lVar10 + 0x18) = uVar14 + 1;
          FUN_180002cd0(lVar2,(longlong)(int)uVar14,uVar9);
        }
        else {
          FUN_1812741c0(lVar10,uVar9,
                        *(undefined8 *)(*(longlong *)(*(longlong *)(lVar8 + 0x20) + 0xc0) + 0x70));
        }
        iVar13 = iVar13 + 1;
      } while (iVar13 < 0x14);
      bVar15 = DAT_182eb5d50 != 0;
      *(longlong *)(param_1 + 0x248) = lVar10;
      if (bVar15) {
        uVar14 = (uint)(param_1 + 0x248U >> 0xc);
        uVar11 = (ulonglong)((uVar14 & 0x1fffff) >> 6);
        do {
          uVar12 = *(ulonglong *)(&DAT_182f0c920 + uVar11 * 8);
          LOCK();
          bVar15 = uVar12 == *(ulonglong *)(&DAT_182f0c920 + uVar11 * 8);
          if (bVar15) {
            *(ulonglong *)(&DAT_182f0c920 + uVar11 * 8) = uVar12 | 1L << (uVar14 & 0x3f);
          }
          UNLOCK();
        } while (!bVar15);
      }
      uVar9 = FUN_1802c43a0(DAT_182d54b10);
      FUN_180003c90(uVar9,DAT_182d54a48);
      uVar9 = ExposureUnnoticed2_Scripts_InGame_GameStateFacade__TransHairType__06001566(uVar9,0);
      bVar15 = DAT_182eb5d50 != 0;
      *(undefined8 *)(param_1 + 0x240) = uVar9;
      if (bVar15) {
        uVar14 = (uint)(param_1 + 0x240U >> 0xc);
        uVar11 = (ulonglong)((uVar14 & 0x1fffff) >> 6);
        do {
          uVar12 = *(ulonglong *)(&DAT_182f0c920 + uVar11 * 8);
          LOCK();
          bVar15 = uVar12 == *(ulonglong *)(&DAT_182f0c920 + uVar11 * 8);
          if (bVar15) {
            *(ulonglong *)(&DAT_182f0c920 + uVar11 * 8) = uVar12 | 1L << (uVar14 & 0x3f);
          }
          UNLOCK();
        } while (!bVar15);
      }
      lVar10 = *(longlong *)(param_1 + 0x240);
      if (lVar10 != 0) {
        if ((*(int *)(lVar10 + 0x18) == 0) ||
           (iVar13 = FUN_18010dec0(lVar10,0,*(undefined8 *)
                                             (*(longlong *)
                                               (*(longlong *)(DAT_182d5dd78 + 0x20) + 0xc0) + 0xd0))
           , iVar13 == -1)) {
          if (*(longlong *)(param_1 + 0x240) == 0) goto code_r0x00018048d3d2;
          FUN_180006140(*(longlong *)(param_1 + 0x240),0);
        }
        if (cRam0000000182eb79c8 == '\0') {
          FUN_1802f2810(0x182d5d910);
          LOCK();
          UNLOCK();
          FUN_1802f2810(0x182d5d908);
          LOCK();
          UNLOCK();
          FUN_1802f2810(0x182d5d900);
          LOCK();
          UNLOCK();
          FUN_1802f2810(0x182d5d8f8);
          LOCK();
          UNLOCK();
          cRam0000000182eb79c8 = '\x01';
        }
        lVar10 = FUN_1802c43a0(uRam0000000182d5d900);
        FUN_1811cf4f0(lVar10,uRam0000000182d5d908);
        iVar13 = 0;
        while( true ) {
          uVar9 = FUN_1802c43a0(uRam0000000182d5d8f8);
          ExposureUnnoticed2_ObjectUI_ClosetMenu_CustomizeMenu_LoadoutCustomizeData__SaveCurrentCustomize__06001cb8
                    (uVar9,0);
          lVar8 = lRam0000000182d5d910;
          if (lVar10 == 0) break;
          *(int *)(lVar10 + 0x1c) = *(int *)(lVar10 + 0x1c) + 1;
          lVar2 = *(longlong *)(lVar10 + 0x10);
          if (lVar2 == 0) break;
          uVar14 = *(uint *)(lVar10 + 0x18);
          if (uVar14 < *(uint *)(lVar2 + 0x18)) {
            *(uint *)(lVar10 + 0x18) = uVar14 + 1;
            uVar11 = FUN_180002cd0(lVar2,(longlong)(int)uVar14,uVar9);
          }
          else {
            uVar11 = FUN_1812741c0(lVar10,uVar9,
                                   *(undefined8 *)
                                    (*(longlong *)(*(longlong *)(lVar8 + 0x20) + 0xc0) + 0x70));
          }
          iVar13 = iVar13 + 1;
          if (0x13 < iVar13) {
            bVar15 = DAT_182eb5d50 != 0;
            *(longlong *)(param_1 + 0x250) = lVar10;
            if (bVar15) {
              uVar14 = (uint)(param_1 + 0x250U >> 0xc);
              uVar12 = (ulonglong)((uVar14 & 0x1fffff) >> 6);
              do {
                uVar3 = *(ulonglong *)(&DAT_182f0c920 + uVar12 * 8);
                LOCK();
                uVar11 = *(ulonglong *)(&DAT_182f0c920 + uVar12 * 8);
                bVar15 = uVar3 == uVar11;
                if (bVar15) {
                  *(ulonglong *)(&DAT_182f0c920 + uVar12 * 8) = uVar3 | 1L << (uVar14 & 0x3f);
                  uVar11 = uVar3;
                }
                UNLOCK();
              } while (!bVar15);
            }
            *(undefined4 *)(param_1 + 600) = 0;
            *(undefined4 *)(param_1 + 0x25c) = 1;
            *(undefined4 *)(param_1 + 0x260) = 2;
            *(undefined4 *)(param_1 + 0x264) = 3;
            *(undefined4 *)(param_1 + 0x268) = 4;
            *(undefined4 *)(param_1 + 0x26c) = 5;
            *(undefined8 *)(param_1 + 0x270) = 3;
            *(undefined4 *)(param_1 + 0x278) = 5;
            return uVar11;
          }
        }
      }
    }
  }
code_r0x00018048d3d2:
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

