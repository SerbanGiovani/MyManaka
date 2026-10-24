// Ghidra pseudocode; not original source or compilable C.
// ev_1466cc3a73666511888196a9180bc1e79c67394d319ed27df44474dc774400af

ulonglong ExposureUnnoticed2_Object3D_NPC_Script_NpcStateModel___ctor__060010bb(longlong param_1)

{
  ulonglong uVar1;
  undefined8 uVar2;
  ulonglong uVar3;
  ulonglong uVar4;
  uint uVar5;
  bool bVar6;
  
  if (DAT_182eb7786 == '\0') {
    FUN_1802f2810(&DAT_182d59358);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d59350);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d59340);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d59330);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d583b8);
    LOCK();
    UNLOCK();
    DAT_182eb7786 = '\x01';
  }
  *(undefined1 *)(param_1 + 0x23) = 1;
  *(undefined4 *)(param_1 + 0x60) = 0x3f800000;
  uVar2 = FUN_1802c43a0(DAT_182d59330);
  FUN_1811cf4f0(uVar2,DAT_182d59340);
  bVar6 = DAT_182eb5d50 != 0;
  *(undefined8 *)(param_1 + 0x68) = uVar2;
  if (bVar6) {
    uVar5 = (uint)(param_1 + 0x68U >> 0xc);
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
  uVar2 = FUN_1802c43a0(DAT_182d59350);
  FUN_18110fc00(uVar2,DAT_182d59358);
  bVar6 = DAT_182eb5d50 != 0;
  *(undefined8 *)(param_1 + 0x78) = uVar2;
  if (bVar6) {
    uVar5 = (uint)(param_1 + 0x78U >> 0xc);
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
  uVar2 = FUN_1802c43a0(DAT_182d583b8);
  uVar3 = ExposureUnnoticed2_Scripts_Base_SmoothFloat___ctor__0600175b
                    (uVar2,0x3f800000,0x3f800000,0,0,0,0xbf800000,0);
  bVar6 = DAT_182eb5d50 != 0;
  *(undefined8 *)(param_1 + 0x98) = uVar2;
  if (bVar6) {
    uVar5 = (uint)(param_1 + 0x98U >> 0xc);
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
  *(undefined4 *)(param_1 + 0xd8) = 0x42c60000;
  return uVar3;
}

