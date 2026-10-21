// Ghidra pseudocode; not original source or compilable C.
// ev_206ada0670b627bd4582e1eb7d0f2d04ad3739d1c7e49475974ff8b0e19571c4

ulonglong ExposureUnnoticed2_Scripts_InGame_GameOverController__Initialize__060014dd
                    (longlong param_1)

{
  ulonglong *puVar1;
  ulonglong uVar2;
  undefined8 uVar3;
  ulonglong uVar4;
  uint uVar5;
  bool bVar6;
  
  if (cRam0000000182eb7957 == '\0') {
    FUN_1802f2810(0x182d5e0d0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d53c58);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5e0c8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d583a0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5e0c0);
    LOCK();
    UNLOCK();
    cRam0000000182eb7957 = '\x01';
  }
  uVar3 = FUN_1802c43a0(uRam0000000182d5e0d0);
  FUN_180665bb0(uVar3,param_1,uRam0000000182d5e0c0,0);
  if (*(int *)(DAT_182d583a0 + 0xe0) == 0) {
    FUN_18035c820();
  }
  FUN_180993250(uVar3,0,uRam0000000182d5e0c8);
  uVar4 = FUN_180735660(param_1,DAT_182d53c58);
  bVar6 = DAT_182eb5d50 != 0;
  *(ulonglong *)(param_1 + 0x50) = uVar4;
  if (bVar6) {
    uVar5 = (uint)(param_1 + 0x50U >> 0xc);
    puVar1 = (ulonglong *)(&DAT_182f0c920 + (ulonglong)((uVar5 & 0x1fffff) >> 6) * 8);
    do {
      uVar2 = *puVar1;
      LOCK();
      uVar4 = *puVar1;
      bVar6 = uVar2 == uVar4;
      if (bVar6) {
        *puVar1 = uVar2 | 1L << (uVar5 & 0x3f);
        uVar4 = uVar2;
      }
      UNLOCK();
    } while (!bVar6);
  }
  return uVar4;
}

