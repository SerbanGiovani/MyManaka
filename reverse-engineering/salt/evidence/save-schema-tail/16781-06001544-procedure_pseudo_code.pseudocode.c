// Ghidra pseudocode; not original source or compilable C.
// ev_5eb8ee47e95a0b5e871e6335bbf12f86eff9e5daab0a037ab63554720f3a8865

longlong ExposureUnnoticed2_Scripts_InGame_GameStateFacade__GetDefaultHairCustomDataDict__06001544
                   (void)

{
  ulonglong *puVar1;
  ulonglong uVar2;
  undefined4 uVar3;
  ulonglong uVar4;
  char cVar5;
  longlong lVar6;
  longlong lVar7;
  longlong lVar8;
  uint uVar9;
  longlong lStack_60;
  ulonglong uStack_58;
  undefined8 uStack_50;
  undefined8 uStack_48;
  undefined8 uStack_40;
  longlong lStack_38;
  ulonglong uStack_30;
  undefined8 uStack_28;
  longlong lStack_20;
  undefined8 uStack_18;
  
  if (cRam0000000182eb79a7 == '\0') {
    FUN_1802f2810(0x182d5dc08);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d5dc00);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5dbf8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d58190);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5dbf0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d5dc10);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d5dbe8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d5dbe0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d5dbd8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d5dbc8);
    LOCK();
    UNLOCK();
    cRam0000000182eb79a7 = '\x01';
  }
  lVar6 = FUN_1802c43a0(uRam0000000182d5dbf0);
  FUN_180e686d0(lVar6,uRam0000000182d5dbf8);
  if (DAT_182eb786b == '\0') {
    FUN_1802f2810(&DAT_182d5c370);
    LOCK();
    UNLOCK();
    DAT_182eb786b = '\x01';
  }
  ExposureUnnoticed2_Master_Hair_MHair__CheckInitialize__0600128e(0);
  lStack_60 = **(longlong **)(DAT_182d5c370 + 0xb8);
  if (lStack_60 == 0) {
                    /* WARNING: Subroutine does not return */
    FUN_18031dad0();
  }
  uStack_50 = 0;
  uStack_48 = 0;
  if (DAT_182eb5d50 != 0) {
    uVar9 = (uint)((ulonglong)&lStack_60 >> 0xc);
    puVar1 = (ulonglong *)(&DAT_182f0c920 + (ulonglong)((uVar9 & 0x1fffff) >> 6) * 8);
    do {
      uVar4 = *puVar1;
      LOCK();
      uVar2 = *puVar1;
      if (uVar4 == uVar2) {
        *puVar1 = uVar4 | 1L << (uVar9 & 0x3f);
      }
      UNLOCK();
    } while (uVar4 != uVar2);
  }
  uStack_58 = (ulonglong)*(uint *)(lStack_60 + 0x2c);
  uStack_40 = 2;
  uStack_30 = uStack_58;
  uStack_28 = 0;
  lStack_20 = 0;
  uStack_18 = 2;
  lStack_38 = lStack_60;
  while( true ) {
    cVar5 = FUN_180f89450(&lStack_38,DAT_182d5dbe8);
    lVar8 = lStack_20;
    if (cVar5 == '\0') {
      return lVar6;
    }
    if (lStack_20 == 0) {
                    /* WARNING: Subroutine does not return */
      FUN_18031dad0();
    }
    uVar3 = *(undefined4 *)(lStack_20 + 0x18);
    lVar7 = FUN_1802c43a0(DAT_182d5dbd8);
    *(undefined4 *)(lVar7 + 0x10) = uVar3;
    if (lVar6 == 0) {
                    /* WARNING: Subroutine does not return */
      FUN_18031dad0();
    }
    FUN_180e76960(lVar6,uVar3,lVar7,2,
                  *(undefined8 *)
                   (*(longlong *)(*(longlong *)(lRam0000000182d5dc08 + 0x20) + 0xc0) + 0x100));
    lVar7 = FUN_180e75f20(lVar6,*(undefined4 *)(lVar8 + 0x18),DAT_182d58190);
    if (*(longlong *)(lVar8 + 0x40) == 0) {
                    /* WARNING: Subroutine does not return */
      FUN_18031dad0();
    }
    if (lVar7 == 0) {
                    /* WARNING: Subroutine does not return */
      FUN_18031dad0();
    }
    *(undefined4 *)(lVar7 + 0x14) = *(undefined4 *)(*(longlong *)(lVar8 + 0x40) + 0x14);
    lVar7 = FUN_180e75f20(lVar6,*(undefined4 *)(lVar8 + 0x18),DAT_182d58190);
    if (*(longlong *)(lVar8 + 0x40) == 0) {
                    /* WARNING: Subroutine does not return */
      FUN_18031dad0();
    }
    if (lVar7 == 0) {
                    /* WARNING: Subroutine does not return */
      FUN_18031dad0();
    }
    *(undefined4 *)(lVar7 + 0x18) = *(undefined4 *)(*(longlong *)(lVar8 + 0x40) + 0x18);
    lVar7 = FUN_180e75f20(lVar6,*(undefined4 *)(lVar8 + 0x18),DAT_182d58190);
    if (*(longlong *)(lVar8 + 0x40) == 0) break;
    if (lVar7 == 0) {
                    /* WARNING: Subroutine does not return */
      FUN_18031dad0();
    }
    *(undefined4 *)(lVar7 + 0x1c) = *(undefined4 *)(*(longlong *)(lVar8 + 0x40) + 0x1c);
    lVar7 = FUN_180e75f20(lVar6,*(undefined4 *)(lVar8 + 0x18),DAT_182d58190);
    if (*(longlong *)(lVar8 + 0x40) == 0) {
                    /* WARNING: Subroutine does not return */
      FUN_18031dad0();
    }
    if (lVar7 == 0) {
                    /* WARNING: Subroutine does not return */
      FUN_18031dad0();
    }
    *(undefined4 *)(lVar7 + 0x20) = *(undefined4 *)(*(longlong *)(lVar8 + 0x40) + 0x20);
    if (*(int *)(lVar8 + 0x18) == 0) {
      lVar7 = FUN_180e75f20(lVar6,*(undefined4 *)(lVar8 + 0x18),DAT_182d58190);
      if (lVar7 == 0) {
                    /* WARNING: Subroutine does not return */
        FUN_18031dad0();
      }
      *(undefined4 *)(lVar7 + 0x14) = 4;
      lVar7 = FUN_180e75f20(lVar6,*(undefined4 *)(lVar8 + 0x18),DAT_182d58190);
      if (lVar7 == 0) {
                    /* WARNING: Subroutine does not return */
        FUN_18031dad0();
      }
      *(undefined4 *)(lVar7 + 0x18) = 0x9f;
      lVar7 = FUN_180e75f20(lVar6,*(undefined4 *)(lVar8 + 0x18),DAT_182d58190);
      if (lVar7 == 0) {
                    /* WARNING: Subroutine does not return */
        FUN_18031dad0();
      }
      *(undefined4 *)(lVar7 + 0x1c) = 0x83;
      lVar8 = FUN_180e75f20(lVar6,*(undefined4 *)(lVar8 + 0x18),DAT_182d58190);
      if (lVar8 == 0) {
                    /* WARNING: Subroutine does not return */
        FUN_18031dad0();
      }
      *(undefined4 *)(lVar8 + 0x20) = 0x71;
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

