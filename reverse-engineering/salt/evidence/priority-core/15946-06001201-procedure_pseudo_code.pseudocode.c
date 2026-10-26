// Ghidra pseudocode; not original source or compilable C.
// ev_1ce5fc673d4cda41ce454ebc36698fa3819aa791874a3bca50c9799c3f7400b6

ulonglong ExposureUnnoticed2_Object3D_Camera_FPCameraController___ctor__06001201(longlong param_1)

{
  ulonglong uVar1;
  undefined8 uVar2;
  ulonglong uVar3;
  ulonglong uVar4;
  uint uVar5;
  bool bVar6;
  
  if (cRam0000000182eb7820 == '\0') {
    FUN_1802f2810(&DAT_182d583b8);
    LOCK();
    UNLOCK();
    cRam0000000182eb7820 = '\x01';
  }
  uVar2 = FUN_1802c43a0(DAT_182d583b8);
  uVar3 = ExposureUnnoticed2_Scripts_Base_SmoothFloat___ctor__0600175b
                    (uVar2,0x3e4ccccd,0x3cf5c28f,0,0,0,0xbf800000,0);
  bVar6 = DAT_182eb5d50 != 0;
  *(undefined8 *)(param_1 + 0x60) = uVar2;
  if (bVar6) {
    uVar5 = (uint)(param_1 + 0x60U >> 0xc);
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
  if (DAT_182ec10b0 == '\0') {
    uVar3 = FUN_1802f2810(&DAT_182d53aa8);
    LOCK();
    UNLOCK();
    DAT_182ec10b0 = '\x01';
  }
  if (*(int *)(DAT_182d53aa8 + 0xe0) == 0) {
    uVar3 = FUN_18035c820();
  }
  return uVar3;
}

