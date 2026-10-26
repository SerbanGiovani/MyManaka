// Ghidra pseudocode; not original source or compilable C.
// ev_90480b41a5afb97fd591fb2140103a9dab9a09375a75f8653899ada99461ef5b

ulonglong ExposureUnnoticed2_Scripts_Mission_MissionManager__IsSuccessMission__06001467
                    (longlong param_1,longlong param_2)

{
  longlong lVar1;
  ulonglong uVar2;
  longlong lVar3;
  undefined7 uVar4;
  undefined7 extraout_var;
  undefined7 extraout_var_00;
  ulonglong uVar5;
  uint uVar6;
  bool bVar7;
  undefined8 uStack_40;
  undefined4 *puStack_38;
  undefined8 uStack_30;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  longlong lStack_18;
  
  if (cRam0000000182eb7923 == '\0') {
    FUN_1802f2810(0x182d5e160);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5e158);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5e150);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5e148);
    LOCK();
    UNLOCK();
    FUN_1802f2810();
    LOCK();
    UNLOCK();
    cRam0000000182eb7923 = '\x01';
  }
  lVar1 = *(longlong *)(param_1 + 0x10);
  if (lVar1 == 0) {
                    /* WARNING: Subroutine does not return */
    FUN_18031dad0();
  }
  if (DAT_182eb5d50 != 0) {
    uVar6 = (uint)((ulonglong)&uStack_40 >> 0xc);
    uVar5 = (ulonglong)((uVar6 & 0x1fffff) >> 6);
    do {
      uVar2 = *(ulonglong *)(&DAT_182f0c920 + uVar5 * 8);
      LOCK();
      bVar7 = uVar2 == *(ulonglong *)(&DAT_182f0c920 + uVar5 * 8);
      if (bVar7) {
        *(ulonglong *)(&DAT_182f0c920 + uVar5 * 8) = uVar2 | 1L << (uVar6 & 0x3f);
      }
      UNLOCK();
    } while (!bVar7);
  }
  uStack_1c = *(undefined4 *)(lVar1 + 0x1c);
  uStack_30 = 0;
  uStack_40._0_4_ = (undefined4)lVar1;
  uStack_40._4_4_ = (undefined4)((ulonglong)lVar1 >> 0x20);
  uStack_28 = (undefined4)uStack_40;
  uStack_24 = uStack_40._4_4_;
  uStack_20 = 0;
  lStack_18 = 0;
  uStack_40 = 0;
  puStack_38 = &uStack_28;
  do {
    uVar5 = FUN_180f72b70(&uStack_28,uRam0000000182d5e158);
    lVar1 = lStack_18;
    if ((char)uVar5 == '\0') {
      return uVar5 & 0xffffffffffffff00;
    }
    if (lStack_18 == 0) {
                    /* WARNING: Subroutine does not return */
      FUN_18031dad0();
    }
    lVar3 = *(longlong *)(lStack_18 + 0x28);
    if (*(int *)(DAT_182d53aa8 + 0xe0) == 0) {
      uVar5 = FUN_18035c820();
    }
    if (DAT_182ec12f3 == '\0') {
      uVar5 = FUN_1802f2810(&DAT_182d53aa8);
      LOCK();
      UNLOCK();
      DAT_182ec12f3 = '\x01';
    }
    if (*(int *)(DAT_182d53aa8 + 0xe0) == 0) {
      uVar5 = FUN_18035c820();
    }
    if (DAT_182ec129b == '\0') {
      uVar5 = FUN_1802f2810(&DAT_182d53aa8);
      LOCK();
      UNLOCK();
      DAT_182ec129b = '\x01';
    }
    uVar4 = (undefined7)(uVar5 >> 8);
    if (param_2 == 0 && lVar3 == 0) break;
    if (param_2 == 0) {
      if (*(int *)(DAT_182d53aa8 + 0xe0) == 0) {
        FUN_18035c820();
        uVar4 = extraout_var_00;
      }
      if (lVar3 == 0) {
                    /* WARNING: Subroutine does not return */
        FUN_18031dad0();
      }
      bVar7 = *(longlong *)(lVar3 + 0x10) == 0;
    }
    else if (lVar3 == 0) {
      if (*(int *)(DAT_182d53aa8 + 0xe0) == 0) {
        FUN_18035c820();
        uVar4 = extraout_var;
      }
      bVar7 = *(longlong *)(param_2 + 0x10) == 0;
    }
    else {
      bVar7 = lVar3 == param_2;
    }
  } while (!bVar7);
  return CONCAT71(uVar4,1.0 <= *(float *)(lVar1 + 0x30));
}

