// Ghidra pseudocode; not original source or compilable C.
// ev_a42f0a37f7d647cd3a3c6a73bb77897a23d4b1e2bfa3da899c6cc51f2b768180

ulonglong ExposureUnnoticed2_Object3D_ScenePlops_WasherMachine_WasherMachineController___ctor__06000a45
                    (longlong param_1)

{
  ulonglong uVar1;
  undefined8 uVar2;
  ulonglong uVar3;
  ulonglong uVar4;
  uint uVar5;
  bool bVar6;
  
  if (cRam0000000182eb8249 == '\0') {
    FUN_1802f2810(&DAT_182d583b8);
    LOCK();
    UNLOCK();
    cRam0000000182eb8249 = '\x01';
  }
  *(undefined4 *)(param_1 + 100) = 0x3f800000;
  uVar2 = FUN_1802c43a0(DAT_182d583b8);
  ExposureUnnoticed2_Scripts_Base_SmoothFloat___ctor__0600175b
            (uVar2,0x3e4ccccd,0x3f800000,0,0,0,0x3f800000,0);
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
  uVar2 = FUN_1802c43a0(DAT_182d583b8);
  uVar3 = ExposureUnnoticed2_Scripts_Base_SmoothFloat___ctor__0600175b
                    (uVar2,0x3f800000,0x3f800000,0,0,0,0xbf800000,0);
  bVar6 = DAT_182eb5d50 != 0;
  *(undefined8 *)(param_1 + 0x70) = uVar2;
  if (bVar6) {
    uVar5 = (uint)(param_1 + 0x70U >> 0xc);
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

