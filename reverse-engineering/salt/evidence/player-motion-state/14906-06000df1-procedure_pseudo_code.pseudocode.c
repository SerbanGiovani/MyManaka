// Ghidra pseudocode; not original source or compilable C.
// ev_a91334817bba2d175cfeeb8b0b69d39cc5558ac2eb9b3258471bb866463d7804

ulonglong ExposureUnnoticed2_Object3D_Player_Scripts_PlayerLocomotion___ctor__06000df1
                    (longlong param_1)

{
  ulonglong uVar1;
  longlong lVar2;
  undefined8 uVar3;
  ulonglong uVar4;
  ulonglong uVar5;
  uint uVar6;
  bool bVar7;
  
  if (cRam0000000182eb8425 == '\0') {
    FUN_1802f2810(0x182d3ef68);
    LOCK();
    UNLOCK();
    cRam0000000182eb8425 = '\x01';
  }
  *(undefined4 *)(param_1 + 0x14) = 10;
  *(undefined4 *)(param_1 + 0x18) = 0x3f800000;
  lVar2 = FUN_1802c43a0(uRam0000000182d3ef68);
  if (cRam0000000182eb768c == '\0') {
    FUN_1802f2810(&DAT_182d58140);
    LOCK();
    UNLOCK();
    cRam0000000182eb768c = '\x01';
  }
  uVar3 = FUN_1802c36c0(DAT_182d58140,10);
  *(undefined8 *)(lVar2 + 0x18) = uVar3;
  if (DAT_182eb5d50 != 0) {
    uVar6 = (uint)(lVar2 + 0x18U >> 0xc);
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
  uVar6 = DAT_182eb5d50;
  uVar4 = (ulonglong)DAT_182eb5d50;
  *(longlong *)(param_1 + 0x88) = lVar2;
  if (uVar6 != 0) {
    uVar6 = (uint)(param_1 + 0x88U >> 0xc);
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

