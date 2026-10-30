// Ghidra pseudocode; not original source or compilable C.
// ev_53b63293998d1f249b557feb71eddd55929c8546e90ca68188f404a2ec3a2d25

/* WARNING: Removing unreachable block (ram,0x00018062ecc1) */

ulonglong ExposureUnnoticed2_Object3D_Player_Scripts_PlayerAnimationManager___ctor__06000c8f
                    (longlong param_1)

{
  ulonglong uVar1;
  undefined8 uVar2;
  longlong lVar3;
  ulonglong uVar4;
  ulonglong uVar5;
  uint uVar6;
  bool bVar7;
  
  if (cRam0000000182eb839d == '\0') {
    FUN_1802f2810(&DAT_182d583b8);
    LOCK();
    UNLOCK();
    cRam0000000182eb839d = '\x01';
  }
  *(undefined4 *)(param_1 + 0x18) = 0x41200000;
  *(undefined4 *)(param_1 + 0x1c) = 0x3f800000;
  uVar2 = FUN_1802c43a0(DAT_182d583b8);
  ExposureUnnoticed2_Scripts_Base_SmoothFloat___ctor__0600175b
            (uVar2,0x3e4ccccd,0x3f800000,0,0,0,0xbf800000,0);
  bVar7 = DAT_182eb5d50 != 0;
  *(undefined8 *)(param_1 + 0x48) = uVar2;
  if (bVar7) {
    uVar6 = (uint)(param_1 + 0x48U >> 0xc);
    uVar4 = (ulonglong)((uVar6 & 0x1fffff) >> 6);
    do {
      uVar5 = *(ulonglong *)(&DAT_182f0c920 + uVar4 * 8);
      LOCK();
      bVar7 = uVar5 == *(ulonglong *)(&DAT_182f0c920 + uVar4 * 8);
      if (bVar7) {
        *(ulonglong *)(&DAT_182f0c920 + uVar4 * 8) = uVar5 | 1L << (uVar6 & 0x3f);
      }
      UNLOCK();
    } while (!bVar7);
  }
  uVar2 = FUN_1802c43a0(DAT_182d583b8);
  ExposureUnnoticed2_Scripts_Base_SmoothFloat___ctor__0600175b
            (uVar2,0x3e4ccccd,0x3f800000,0x41200000,0,0,0xbf800000,0);
  bVar7 = DAT_182eb5d50 != 0;
  *(undefined8 *)(param_1 + 0x50) = uVar2;
  if (bVar7) {
    uVar6 = (uint)(param_1 + 0x50U >> 0xc);
    uVar4 = (ulonglong)((uVar6 & 0x1fffff) >> 6);
    do {
      uVar5 = *(ulonglong *)(&DAT_182f0c920 + uVar4 * 8);
      LOCK();
      bVar7 = uVar5 == *(ulonglong *)(&DAT_182f0c920 + uVar4 * 8);
      if (bVar7) {
        *(ulonglong *)(&DAT_182f0c920 + uVar4 * 8) = uVar5 | 1L << (uVar6 & 0x3f);
      }
      UNLOCK();
    } while (!bVar7);
  }
  uVar2 = FUN_1802c43a0(DAT_182d583b8);
  ExposureUnnoticed2_Scripts_Base_SmoothFloat___ctor__0600175b
            (uVar2,0x3e4ccccd,0x3f800000,0,0,0,0xbf800000,0);
  bVar7 = DAT_182eb5d50 != 0;
  *(undefined8 *)(param_1 + 0x58) = uVar2;
  if (bVar7) {
    uVar6 = (uint)(param_1 + 0x58U >> 0xc);
    uVar4 = (ulonglong)((uVar6 & 0x1fffff) >> 6);
    do {
      uVar5 = *(ulonglong *)(&DAT_182f0c920 + uVar4 * 8);
      LOCK();
      bVar7 = uVar5 == *(ulonglong *)(&DAT_182f0c920 + uVar4 * 8);
      if (bVar7) {
        *(ulonglong *)(&DAT_182f0c920 + uVar4 * 8) = uVar5 | 1L << (uVar6 & 0x3f);
      }
      UNLOCK();
    } while (!bVar7);
  }
  lVar3 = FUN_1802c43a0(DAT_182d583b8);
  if (DAT_182eb7aa8 == '\0') {
    FUN_1802f2810(&DAT_182d52288);
    LOCK();
    UNLOCK();
    DAT_182eb7aa8 = '\x01';
  }
  *(undefined1 *)(lVar3 + 0x20) = 0;
  *(undefined4 *)(lVar3 + 0x24) = 0x3f800000;
  *(undefined4 *)(lVar3 + 0x28) = 0x3f000000;
  if (*(int *)(DAT_182d52288 + 0xe0) == 0) {
    FUN_18035c820();
  }
  bVar7 = DAT_182eb5d50 != 0;
  *(undefined4 *)(lVar3 + 0x2c) = 0x3f000000;
  *(undefined1 *)(lVar3 + 0x30) = 0;
  *(undefined4 *)(lVar3 + 0x14) = 0x40000000;
  *(undefined4 *)(lVar3 + 0x10) = 0;
  *(float *)(lVar3 + 0x18) = 1.0 / *(float *)(lVar3 + 0x2c);
  *(longlong *)(param_1 + 0x60) = lVar3;
  if (bVar7) {
    uVar6 = (uint)(param_1 + 0x60U >> 0xc);
    uVar4 = (ulonglong)((uVar6 & 0x1fffff) >> 6);
    do {
      uVar5 = *(ulonglong *)(&DAT_182f0c920 + uVar4 * 8);
      LOCK();
      bVar7 = uVar5 == *(ulonglong *)(&DAT_182f0c920 + uVar4 * 8);
      if (bVar7) {
        *(ulonglong *)(&DAT_182f0c920 + uVar4 * 8) = uVar5 | 1L << (uVar6 & 0x3f);
      }
      UNLOCK();
    } while (!bVar7);
  }
  uVar2 = FUN_1802c43a0(DAT_182d583b8);
  ExposureUnnoticed2_Scripts_Base_SmoothFloat___ctor__0600175b
            (uVar2,0x3e4ccccd,0x3f800000,0,0,0,0xbf800000,0);
  bVar7 = DAT_182eb5d50 != 0;
  *(undefined8 *)(param_1 + 0x68) = uVar2;
  if (bVar7) {
    uVar6 = (uint)(param_1 + 0x68U >> 0xc);
    uVar4 = (ulonglong)((uVar6 & 0x1fffff) >> 6);
    do {
      uVar5 = *(ulonglong *)(&DAT_182f0c920 + uVar4 * 8);
      LOCK();
      bVar7 = uVar5 == *(ulonglong *)(&DAT_182f0c920 + uVar4 * 8);
      if (bVar7) {
        *(ulonglong *)(&DAT_182f0c920 + uVar4 * 8) = uVar5 | 1L << (uVar6 & 0x3f);
      }
      UNLOCK();
    } while (!bVar7);
  }
  uVar2 = FUN_1802c43a0(DAT_182d583b8);
  ExposureUnnoticed2_Scripts_Base_SmoothFloat___ctor__0600175b
            (uVar2,0x3e4ccccd,0x3f800000,0,0,0,0xbf800000,0);
  bVar7 = DAT_182eb5d50 != 0;
  *(undefined8 *)(param_1 + 0x70) = uVar2;
  if (bVar7) {
    uVar6 = (uint)(param_1 + 0x70U >> 0xc);
    uVar4 = (ulonglong)((uVar6 & 0x1fffff) >> 6);
    do {
      uVar5 = *(ulonglong *)(&DAT_182f0c920 + uVar4 * 8);
      LOCK();
      bVar7 = uVar5 == *(ulonglong *)(&DAT_182f0c920 + uVar4 * 8);
      if (bVar7) {
        *(ulonglong *)(&DAT_182f0c920 + uVar4 * 8) = uVar5 | 1L << (uVar6 & 0x3f);
      }
      UNLOCK();
    } while (!bVar7);
  }
  uVar2 = FUN_1802c43a0(DAT_182d583b8);
  ExposureUnnoticed2_Scripts_Base_SmoothFloat___ctor__0600175b
            (uVar2,0x3e4ccccd,0x3f800000,0,0,0,0xbf800000,0);
  bVar7 = DAT_182eb5d50 != 0;
  *(undefined8 *)(param_1 + 0x78) = uVar2;
  if (bVar7) {
    uVar6 = (uint)(param_1 + 0x78U >> 0xc);
    uVar4 = (ulonglong)((uVar6 & 0x1fffff) >> 6);
    do {
      uVar5 = *(ulonglong *)(&DAT_182f0c920 + uVar4 * 8);
      LOCK();
      bVar7 = uVar5 == *(ulonglong *)(&DAT_182f0c920 + uVar4 * 8);
      if (bVar7) {
        *(ulonglong *)(&DAT_182f0c920 + uVar4 * 8) = uVar5 | 1L << (uVar6 & 0x3f);
      }
      UNLOCK();
    } while (!bVar7);
  }
  uVar2 = FUN_1802c43a0(DAT_182d583b8);
  ExposureUnnoticed2_Scripts_Base_SmoothFloat___ctor__0600175b
            (uVar2,0x3e4ccccd,0x3f800000,0,0,0,0xbf800000,0);
  bVar7 = DAT_182eb5d50 != 0;
  *(undefined8 *)(param_1 + 0x80) = uVar2;
  if (bVar7) {
    uVar6 = (uint)(param_1 + 0x80U >> 0xc);
    uVar4 = (ulonglong)((uVar6 & 0x1fffff) >> 6);
    do {
      uVar5 = *(ulonglong *)(&DAT_182f0c920 + uVar4 * 8);
      LOCK();
      bVar7 = uVar5 == *(ulonglong *)(&DAT_182f0c920 + uVar4 * 8);
      if (bVar7) {
        *(ulonglong *)(&DAT_182f0c920 + uVar4 * 8) = uVar5 | 1L << (uVar6 & 0x3f);
      }
      UNLOCK();
    } while (!bVar7);
  }
  uVar2 = FUN_1802c43a0(DAT_182d583b8);
  ExposureUnnoticed2_Scripts_Base_SmoothFloat___ctor__0600175b
            (uVar2,0x41200000,0x3f800000,0,1,0,0xbf800000,0);
  bVar7 = DAT_182eb5d50 != 0;
  *(undefined8 *)(param_1 + 0x88) = uVar2;
  if (bVar7) {
    uVar6 = (uint)(param_1 + 0x88U >> 0xc);
    uVar4 = (ulonglong)((uVar6 & 0x1fffff) >> 6);
    do {
      uVar5 = *(ulonglong *)(&DAT_182f0c920 + uVar4 * 8);
      LOCK();
      bVar7 = uVar5 == *(ulonglong *)(&DAT_182f0c920 + uVar4 * 8);
      if (bVar7) {
        *(ulonglong *)(&DAT_182f0c920 + uVar4 * 8) = uVar5 | 1L << (uVar6 & 0x3f);
      }
      UNLOCK();
    } while (!bVar7);
  }
  uVar2 = FUN_1802c43a0(DAT_182d583b8);
  ExposureUnnoticed2_Scripts_Base_SmoothFloat___ctor__0600175b
            (uVar2,0x41200000,0x3f800000,0,1,0,0xbf800000,0);
  bVar7 = DAT_182eb5d50 != 0;
  *(undefined8 *)(param_1 + 0x90) = uVar2;
  if (bVar7) {
    uVar6 = (uint)(param_1 + 0x90U >> 0xc);
    uVar4 = (ulonglong)((uVar6 & 0x1fffff) >> 6);
    do {
      uVar5 = *(ulonglong *)(&DAT_182f0c920 + uVar4 * 8);
      LOCK();
      bVar7 = uVar5 == *(ulonglong *)(&DAT_182f0c920 + uVar4 * 8);
      if (bVar7) {
        *(ulonglong *)(&DAT_182f0c920 + uVar4 * 8) = uVar5 | 1L << (uVar6 & 0x3f);
      }
      UNLOCK();
    } while (!bVar7);
  }
  uVar2 = FUN_1802c43a0(DAT_182d583b8);
  ExposureUnnoticed2_Scripts_Base_SmoothFloat___ctor__0600175b
            (uVar2,0x40a00000,0x3f800000,0,0,0,0xbf800000,0);
  bVar7 = DAT_182eb5d50 != 0;
  *(undefined8 *)(param_1 + 0x98) = uVar2;
  if (bVar7) {
    uVar6 = (uint)(param_1 + 0x98U >> 0xc);
    uVar4 = (ulonglong)((uVar6 & 0x1fffff) >> 6);
    do {
      uVar5 = *(ulonglong *)(&DAT_182f0c920 + uVar4 * 8);
      LOCK();
      bVar7 = uVar5 == *(ulonglong *)(&DAT_182f0c920 + uVar4 * 8);
      if (bVar7) {
        *(ulonglong *)(&DAT_182f0c920 + uVar4 * 8) = uVar5 | 1L << (uVar6 & 0x3f);
      }
      UNLOCK();
    } while (!bVar7);
  }
  uVar2 = FUN_1802c43a0(DAT_182d583b8);
  ExposureUnnoticed2_Scripts_Base_SmoothFloat___ctor__0600175b
            (uVar2,0x3e4ccccd,0x3f800000,0,0,0,0xbf800000,0);
  bVar7 = DAT_182eb5d50 != 0;
  *(undefined8 *)(param_1 + 0xa0) = uVar2;
  if (bVar7) {
    uVar6 = (uint)(param_1 + 0xa0U >> 0xc);
    uVar4 = (ulonglong)((uVar6 & 0x1fffff) >> 6);
    do {
      uVar5 = *(ulonglong *)(&DAT_182f0c920 + uVar4 * 8);
      LOCK();
      bVar7 = uVar5 == *(ulonglong *)(&DAT_182f0c920 + uVar4 * 8);
      if (bVar7) {
        *(ulonglong *)(&DAT_182f0c920 + uVar4 * 8) = uVar5 | 1L << (uVar6 & 0x3f);
      }
      UNLOCK();
    } while (!bVar7);
  }
  uVar2 = FUN_1802c43a0(DAT_182d583b8);
  ExposureUnnoticed2_Scripts_Base_SmoothFloat___ctor__0600175b
            (uVar2,0x3f800000,0x3f800000,0,0,0,0xbf800000,0);
  bVar7 = DAT_182eb5d50 != 0;
  *(undefined8 *)(param_1 + 0xa8) = uVar2;
  if (bVar7) {
    uVar6 = (uint)(param_1 + 0xa8U >> 0xc);
    uVar4 = (ulonglong)((uVar6 & 0x1fffff) >> 6);
    do {
      uVar5 = *(ulonglong *)(&DAT_182f0c920 + uVar4 * 8);
      LOCK();
      bVar7 = uVar5 == *(ulonglong *)(&DAT_182f0c920 + uVar4 * 8);
      if (bVar7) {
        *(ulonglong *)(&DAT_182f0c920 + uVar4 * 8) = uVar5 | 1L << (uVar6 & 0x3f);
      }
      UNLOCK();
    } while (!bVar7);
  }
  uVar2 = FUN_1802c43a0(DAT_182d583b8);
  ExposureUnnoticed2_Scripts_Base_SmoothFloat___ctor__0600175b
            (uVar2,0x3eb33333,0x3f800000,0,0,0,0xbf800000,0);
  bVar7 = DAT_182eb5d50 != 0;
  *(undefined8 *)(param_1 + 0xb0) = uVar2;
  if (bVar7) {
    uVar6 = (uint)(param_1 + 0xb0U >> 0xc);
    uVar4 = (ulonglong)((uVar6 & 0x1fffff) >> 6);
    do {
      uVar5 = *(ulonglong *)(&DAT_182f0c920 + uVar4 * 8);
      LOCK();
      bVar7 = uVar5 == *(ulonglong *)(&DAT_182f0c920 + uVar4 * 8);
      if (bVar7) {
        *(ulonglong *)(&DAT_182f0c920 + uVar4 * 8) = uVar5 | 1L << (uVar6 & 0x3f);
      }
      UNLOCK();
    } while (!bVar7);
  }
  uVar2 = FUN_1802c43a0(DAT_182d583b8);
  uVar4 = ExposureUnnoticed2_Scripts_Base_SmoothFloat___ctor__0600175b
                    (uVar2,0x3e4ccccd,0x3f800000,0,0,0,0xbf800000,0);
  bVar7 = DAT_182eb5d50 != 0;
  *(undefined8 *)(param_1 + 0xb8) = uVar2;
  if (bVar7) {
    uVar6 = (uint)(param_1 + 0xb8U >> 0xc);
    uVar5 = (ulonglong)((uVar6 & 0x1fffff) >> 6);
    do {
      uVar1 = *(ulonglong *)(&DAT_182f0c920 + uVar5 * 8);
      LOCK();
      uVar4 = *(ulonglong *)(&DAT_182f0c920 + uVar5 * 8);
      bVar7 = uVar1 == uVar4;
      if (bVar7) {
        *(ulonglong *)(&DAT_182f0c920 + uVar5 * 8) = uVar1 | 1L << (uVar6 & 0x3f);
        uVar4 = uVar1;
      }
      UNLOCK();
    } while (!bVar7);
  }
  return uVar4;
}

