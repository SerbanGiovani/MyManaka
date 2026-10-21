// Ghidra pseudocode; not original source or compilable C.
// ev_61d13f902c0c3c5c7ddd4c6747f3c2397f8f84738636f2db90a6177f1a88ce0f

ulonglong ExposureUnnoticed2_Object3D_Player_Scripts_PlayerStateModel___ctor__06000e2f
                    (longlong param_1)

{
  ulonglong uVar1;
  undefined8 uVar2;
  ulonglong uVar3;
  ulonglong uVar4;
  uint uVar5;
  bool bVar6;
  
  if (cRam0000000182eb8449 == '\0') {
    FUN_1802f2810(0x182d3ee00);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d3ee08);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d3edf0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d593d8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d3edf8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d3ede0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d3ede8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d593d0);
    LOCK();
    UNLOCK();
    cRam0000000182eb8449 = '\x01';
  }
  uVar2 = ExposureUnnoticed2_Master_Clothes_MClothes__Get__06001343(0,0);
  bVar6 = DAT_182eb5d50 != 0;
  *(undefined8 *)(param_1 + 0x10) = uVar2;
  if (bVar6) {
    uVar5 = (uint)(param_1 + 0x10U >> 0xc);
    uVar3 = (ulonglong)((uVar5 & 0x1fffff) >> 6);
    do {
      uVar4 = *(ulonglong *)(&DAT_182f0c920 + uVar3 * 8);
      LOCK();
      bVar6 = uVar4 == *(ulonglong *)(&DAT_182f0c920 + uVar3 * 8);
      if (bVar6) {
        *(ulonglong *)(&DAT_182f0c920 + uVar3 * 8) = uVar4 | 1L << (uVar5 & 0x3f);
      }
      UNLOCK();
    } while (!bVar6);
  }
  uVar2 = ExposureUnnoticed2_Master_Action_MAction__Get__06001385(0xffffffff,0);
  bVar6 = DAT_182eb5d50 != 0;
  *(undefined8 *)(param_1 + 0x48) = uVar2;
  if (bVar6) {
    uVar5 = (uint)(param_1 + 0x48U >> 0xc);
    uVar3 = (ulonglong)((uVar5 & 0x1fffff) >> 6);
    do {
      uVar4 = *(ulonglong *)(&DAT_182f0c920 + uVar3 * 8);
      LOCK();
      bVar6 = uVar4 == *(ulonglong *)(&DAT_182f0c920 + uVar3 * 8);
      if (bVar6) {
        *(ulonglong *)(&DAT_182f0c920 + uVar3 * 8) = uVar4 | 1L << (uVar5 & 0x3f);
      }
      UNLOCK();
    } while (!bVar6);
  }
  *(undefined4 *)(param_1 + 0x80) = 0x7f7fffff;
  uVar2 = FUN_1802c43a0(uRam0000000182d3ede0);
  FUN_1811cf4f0(uVar2,uRam0000000182d3edf8);
  bVar6 = DAT_182eb5d50 != 0;
  *(undefined8 *)(param_1 + 0x138) = uVar2;
  if (bVar6) {
    uVar5 = (uint)(param_1 + 0x138U >> 0xc);
    uVar3 = (ulonglong)((uVar5 & 0x1fffff) >> 6);
    do {
      uVar4 = *(ulonglong *)(&DAT_182f0c920 + uVar3 * 8);
      LOCK();
      bVar6 = uVar4 == *(ulonglong *)(&DAT_182f0c920 + uVar3 * 8);
      if (bVar6) {
        *(ulonglong *)(&DAT_182f0c920 + uVar3 * 8) = uVar4 | 1L << (uVar5 & 0x3f);
      }
      UNLOCK();
    } while (!bVar6);
  }
  uVar2 = FUN_1802c43a0(uRam0000000182d3ede8);
  FUN_1811cf4f0(uVar2,uRam0000000182d3edf0);
  bVar6 = DAT_182eb5d50 != 0;
  *(undefined8 *)(param_1 + 0x148) = uVar2;
  if (bVar6) {
    uVar5 = (uint)(param_1 + 0x148U >> 0xc);
    uVar3 = (ulonglong)((uVar5 & 0x1fffff) >> 6);
    do {
      uVar4 = *(ulonglong *)(&DAT_182f0c920 + uVar3 * 8);
      LOCK();
      bVar6 = uVar4 == *(ulonglong *)(&DAT_182f0c920 + uVar3 * 8);
      if (bVar6) {
        *(ulonglong *)(&DAT_182f0c920 + uVar3 * 8) = uVar4 | 1L << (uVar5 & 0x3f);
      }
      UNLOCK();
    } while (!bVar6);
  }
  uVar2 = FUN_1802c43a0(uRam0000000182d3ede8);
  FUN_1811cf4f0(uVar2,uRam0000000182d3edf0);
  bVar6 = DAT_182eb5d50 != 0;
  *(undefined8 *)(param_1 + 0x150) = uVar2;
  if (bVar6) {
    uVar5 = (uint)(param_1 + 0x150U >> 0xc);
    uVar3 = (ulonglong)((uVar5 & 0x1fffff) >> 6);
    do {
      uVar4 = *(ulonglong *)(&DAT_182f0c920 + uVar3 * 8);
      LOCK();
      bVar6 = uVar4 == *(ulonglong *)(&DAT_182f0c920 + uVar3 * 8);
      if (bVar6) {
        *(ulonglong *)(&DAT_182f0c920 + uVar3 * 8) = uVar4 | 1L << (uVar5 & 0x3f);
      }
      UNLOCK();
    } while (!bVar6);
  }
  uVar2 = FUN_1802c43a0(uRam0000000182d3ede8);
  FUN_1811cf4f0(uVar2,uRam0000000182d3edf0);
  bVar6 = DAT_182eb5d50 != 0;
  *(undefined8 *)(param_1 + 0x158) = uVar2;
  if (bVar6) {
    uVar5 = (uint)(param_1 + 0x158U >> 0xc);
    uVar3 = (ulonglong)((uVar5 & 0x1fffff) >> 6);
    do {
      uVar4 = *(ulonglong *)(&DAT_182f0c920 + uVar3 * 8);
      LOCK();
      bVar6 = uVar4 == *(ulonglong *)(&DAT_182f0c920 + uVar3 * 8);
      if (bVar6) {
        *(ulonglong *)(&DAT_182f0c920 + uVar3 * 8) = uVar4 | 1L << (uVar5 & 0x3f);
      }
      UNLOCK();
    } while (!bVar6);
  }
  uVar2 = FUN_1802c43a0(uRam0000000182d3ee08);
  FUN_180e686d0(uVar2,uRam0000000182d3ee00);
  bVar6 = DAT_182eb5d50 != 0;
  *(undefined8 *)(param_1 + 0x160) = uVar2;
  if (bVar6) {
    uVar5 = (uint)(param_1 + 0x160U >> 0xc);
    uVar3 = (ulonglong)((uVar5 & 0x1fffff) >> 6);
    do {
      uVar4 = *(ulonglong *)(&DAT_182f0c920 + uVar3 * 8);
      LOCK();
      bVar6 = uVar4 == *(ulonglong *)(&DAT_182f0c920 + uVar3 * 8);
      if (bVar6) {
        *(ulonglong *)(&DAT_182f0c920 + uVar3 * 8) = uVar4 | 1L << (uVar5 & 0x3f);
      }
      UNLOCK();
    } while (!bVar6);
  }
  uVar2 = FUN_1802c43a0(uRam0000000182d593d0);
  uVar3 = FUN_1811cf4f0(uVar2,uRam0000000182d593d8);
  bVar6 = DAT_182eb5d50 != 0;
  *(undefined8 *)(param_1 + 0x1f8) = uVar2;
  if (bVar6) {
    uVar5 = (uint)(param_1 + 0x1f8U >> 0xc);
    uVar4 = (ulonglong)((uVar5 & 0x1fffff) >> 6);
    do {
      uVar1 = *(ulonglong *)(&DAT_182f0c920 + uVar4 * 8);
      LOCK();
      uVar3 = *(ulonglong *)(&DAT_182f0c920 + uVar4 * 8);
      bVar6 = uVar1 == uVar3;
      if (bVar6) {
        *(ulonglong *)(&DAT_182f0c920 + uVar4 * 8) = uVar1 | 1L << (uVar5 & 0x3f);
        uVar3 = uVar1;
      }
      UNLOCK();
    } while (!bVar6);
  }
  *(undefined4 *)(param_1 + 0x20c) = 10;
  *(undefined8 *)(param_1 + 0x210) = 0xffffffffffffffff;
  *(undefined8 *)(param_1 + 0x218) = 0xffffffffffffffff;
  *(undefined4 *)(param_1 + 0x234) = 0xffffffff;
  return uVar3;
}

