// Ghidra pseudocode; not original source or compilable C.
// ev_34974e3cd001bba973b1242743b89d8b5f15c4040ddb53b10364fe4854bf37f8

ulonglong ExposureUnnoticed2_Object3D_NPC_Script_NpcManager___ctor__060010a9(longlong param_1)

{
  longlong lVar1;
  ulonglong uVar2;
  undefined8 uVar3;
  ulonglong uVar4;
  uint uVar5;
  bool bVar6;
  
  if (cRam0000000182eb777f == '\0') {
    FUN_1802f2810(0x182d593e8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d593e0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d593d8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d593d0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d593c8);
    LOCK();
    UNLOCK();
    cRam0000000182eb777f = '\x01';
  }
  uVar3 = FUN_1802c43a0(uRam0000000182d593d0);
  FUN_1811cf4f0(uVar3,uRam0000000182d593d8);
  bVar6 = DAT_182eb5d50 != 0;
  *(undefined8 *)(param_1 + 0x38) = uVar3;
  if (bVar6) {
    uVar5 = (uint)(param_1 + 0x38U >> 0xc);
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
  uVar3 = FUN_1802c43a0(uRam0000000182d593e0);
  FUN_180e95b10(uVar3,uRam0000000182d593e8);
  bVar6 = DAT_182eb5d50 != 0;
  *(undefined8 *)(param_1 + 0x40) = uVar3;
  if (bVar6) {
    uVar5 = (uint)(param_1 + 0x40U >> 0xc);
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
  uVar3 = FUN_1802c43a0(uRam0000000182d593c8);
  bVar6 = DAT_182eb5d50 != 0;
  *(undefined8 *)(param_1 + 0x50) = uVar3;
  if (bVar6) {
    uVar5 = (uint)(param_1 + 0x50U >> 0xc);
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
  uVar3 = FUN_1802c43a0(uRam0000000182d593d0);
  uVar4 = FUN_1811cf4f0(uVar3,uRam0000000182d593d8);
  bVar6 = DAT_182eb5d50 != 0;
  *(undefined8 *)(param_1 + 0x78) = uVar3;
  if (bVar6) {
    uVar5 = (uint)(param_1 + 0x78U >> 0xc);
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
  if (DAT_182ec10b0 == '\0') {
    uVar4 = FUN_1802f2810(&DAT_182d53aa8);
    LOCK();
    UNLOCK();
    DAT_182ec10b0 = '\x01';
  }
  if (*(int *)(DAT_182d53aa8 + 0xe0) == 0) {
    uVar4 = FUN_18035c820();
  }
  return uVar4;
}

