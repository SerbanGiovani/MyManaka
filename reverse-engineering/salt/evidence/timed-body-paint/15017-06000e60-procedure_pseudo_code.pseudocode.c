// Ghidra pseudocode; not original source or compilable C.
// ev_b7d866f49ebddd7a5a7bd1ae87a8e09fb1d3fe985c6a8817637efc7dcd71f16d

ulonglong ExposureUnnoticed2_Object3D_Player_Scripts_Other_BodyPaintController___ctor__06000e60
                    (longlong param_1)

{
  ulonglong uVar1;
  undefined8 uVar2;
  ulonglong uVar3;
  ulonglong uVar4;
  uint uVar5;
  bool bVar6;
  
  if (cRam0000000182eb765c == '\0') {
    FUN_1802f2810(&DAT_182d583b8);
    LOCK();
    UNLOCK();
    cRam0000000182eb765c = '\x01';
  }
  uVar2 = FUN_1802c43a0(DAT_182d583b8);
  uVar3 = ExposureUnnoticed2_Scripts_Base_SmoothFloat___ctor__0600175b
                    (uVar2,0x40000000,0x3e19999a,0,0,0,0xbf800000,0);
  bVar6 = DAT_182eb5d50 != 0;
  *(undefined8 *)(param_1 + 0x10) = uVar2;
  if (bVar6) {
    uVar5 = (uint)(param_1 + 0x10U >> 0xc);
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
  return uVar3;
}

