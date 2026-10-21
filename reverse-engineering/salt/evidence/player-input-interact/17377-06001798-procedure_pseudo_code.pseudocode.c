// Ghidra pseudocode; not original source or compilable C.
// ev_116375159eff3c459919a8b82f8abe48818707eefac2b0b95c13e3955af0ab65

void ExposureUnnoticed2_Scripts_Base_InteractManager__Unregister__06001798
               (int param_1,longlong param_2)

{
  ulonglong *puVar1;
  ulonglong uVar2;
  longlong lVar3;
  ulonglong uVar4;
  longlong lVar5;
  char cVar6;
  uint uVar7;
  bool bVar8;
  undefined8 uStack_40;
  undefined4 *puStack_38;
  undefined8 uStack_30;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  longlong lStack_18;
  
  if (cRam0000000182eb7abd == '\0') {
    FUN_1802f2810(0x182d5f5d8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5f5d0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5f5c8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5ab80);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5f5c0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5f5b8);
    LOCK();
    UNLOCK();
    FUN_1802f2810();
    LOCK();
    UNLOCK();
    cRam0000000182eb7abd = '\x01';
  }
  if (*(int *)(lRam0000000182d5ab80 + 0xe0) == 0) {
    FUN_18035c820();
  }
  lVar3 = **(longlong **)(lRam0000000182d5ab80 + 0xb8);
  if (lVar3 == 0) {
                    /* WARNING: Subroutine does not return */
    FUN_18031dad0();
  }
  if (DAT_182eb5d50 != 0) {
    uVar7 = (uint)((ulonglong)&uStack_40 >> 0xc);
    puVar1 = (ulonglong *)(&DAT_182f0c920 + (ulonglong)((uVar7 & 0x1fffff) >> 6) * 8);
    do {
      uVar4 = *puVar1;
      LOCK();
      uVar2 = *puVar1;
      if (uVar4 == uVar2) {
        *puVar1 = uVar4 | 1L << (uVar7 & 0x3f);
      }
      UNLOCK();
    } while (uVar4 != uVar2);
  }
  uStack_1c = *(undefined4 *)(lVar3 + 0x1c);
  uStack_30 = 0;
  uStack_40._0_4_ = (undefined4)lVar3;
  uStack_40._4_4_ = (undefined4)((ulonglong)lVar3 >> 0x20);
  uStack_28 = (undefined4)uStack_40;
  uStack_24 = uStack_40._4_4_;
  uStack_20 = 0;
  lStack_18 = 0;
  uStack_40 = 0;
  puStack_38 = &uStack_28;
  do {
    do {
      cVar6 = FUN_180f72b70(&uStack_28,uRam0000000182d5f5d0);
      lVar3 = lStack_18;
      if (cVar6 == '\0') {
        return;
      }
      if (lStack_18 == 0) {
                    /* WARNING: Subroutine does not return */
        FUN_18031dad0();
      }
    } while (*(int *)(lStack_18 + 0x10) != param_1);
    lVar5 = *(longlong *)(lStack_18 + 0x18);
    if (*(int *)(DAT_182d53aa8 + 0xe0) == 0) {
      FUN_18035c820();
    }
    if (DAT_182ec12f3 == '\0') {
      FUN_1802f2810(&DAT_182d53aa8);
      LOCK();
      UNLOCK();
      DAT_182ec12f3 = '\x01';
    }
    if (*(int *)(DAT_182d53aa8 + 0xe0) == 0) {
      FUN_18035c820();
    }
    if (DAT_182ec129b == '\0') {
      FUN_1802f2810(&DAT_182d53aa8);
      LOCK();
      UNLOCK();
      DAT_182ec129b = '\x01';
    }
    if (param_2 == 0 && lVar5 == 0) break;
    if (param_2 == 0) {
      if (*(int *)(DAT_182d53aa8 + 0xe0) == 0) {
        FUN_18035c820();
      }
      if (lVar5 == 0) {
                    /* WARNING: Subroutine does not return */
        FUN_18031dad0();
      }
      bVar8 = *(longlong *)(lVar5 + 0x10) == 0;
    }
    else if (lVar5 == 0) {
      if (*(int *)(DAT_182d53aa8 + 0xe0) == 0) {
        FUN_18035c820();
      }
      bVar8 = *(longlong *)(param_2 + 0x10) == 0;
    }
    else {
      bVar8 = lVar5 == param_2;
    }
  } while (!bVar8);
  if (*(int *)(lRam0000000182d5ab80 + 0xe0) == 0) {
    FUN_18035c820(lRam0000000182d5ab80);
  }
  if (**(longlong **)(lRam0000000182d5ab80 + 0xb8) != 0) {
    FUN_181274e50(**(longlong **)(lRam0000000182d5ab80 + 0xb8),lVar3,uRam0000000182d5f5b8);
    return;
  }
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

