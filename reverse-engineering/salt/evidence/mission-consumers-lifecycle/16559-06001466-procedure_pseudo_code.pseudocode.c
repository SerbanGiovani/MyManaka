// Ghidra pseudocode; not original source or compilable C.
// ev_02ba04e940aa7f86dc2e281fbdb5a75fef3c22abe54310135f2cd3ae11b90441

void ExposureUnnoticed2_Scripts_Mission_MissionManager__Initialize__06001466(longlong param_1)

{
  ulonglong uVar1;
  longlong lVar2;
  ulonglong uVar3;
  char cVar4;
  undefined8 uVar5;
  longlong *plVar6;
  longlong lVar7;
  undefined8 uVar8;
  uint uVar9;
  bool bVar10;
  int aiStackX_18 [4];
  longlong lStack_e8;
  ulonglong uStack_e0;
  undefined8 uStack_d8;
  undefined8 uStack_d0;
  undefined8 uStack_c8;
  undefined8 uStack_c0;
  longlong *plStack_b8;
  undefined8 uStack_b0;
  longlong *plStack_a8;
  longlong lStack_a0;
  ulonglong uStack_98;
  undefined8 uStack_90;
  longlong lStack_88;
  undefined8 uStack_80;
  longlong lStack_78;
  ulonglong uStack_70;
  ulonglong uStack_68;
  longlong lStack_60;
  undefined8 uStack_58;
  
  if (cRam0000000182eb7922 == '\0') {
    FUN_1802f2810(0x182d5e1e8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d5c050);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5e1e0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5e1d8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d5c060);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5e1f0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5e1d0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d5c030);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d5c028);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5e1c8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5e1c0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d5c000);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d5bff0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5e1b8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5e1b0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5e1a8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5e1a0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5e198);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5e190);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5e188);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5e180);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d535d8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5e178);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d52e20);
    LOCK();
    UNLOCK();
    cRam0000000182eb7922 = '\x01';
  }
  lStack_a0 = 0;
  uStack_98 = 0;
  uStack_90 = 0;
  lStack_88 = 0;
  uStack_80 = 0;
  **(longlong **)(lRam0000000182d5e190 + 0xb8) = param_1;
  if (DAT_182eb5d50 != 0) {
    uVar9 = (uint)(*(ulonglong *)(lRam0000000182d5e190 + 0xb8) >> 0xc);
    lVar7 = (ulonglong)((uVar9 & 0x1fffff) >> 6) * 8;
    do {
      uVar1 = *(ulonglong *)(&DAT_182f0c920 + lVar7);
      LOCK();
      bVar10 = uVar1 == *(ulonglong *)(&DAT_182f0c920 + lVar7);
      if (bVar10) {
        *(ulonglong *)(&DAT_182f0c920 + lVar7) = uVar1 | 1L << (ulonglong)(uVar9 & 0x3f);
      }
      UNLOCK();
    } while (!bVar10);
  }
  if (DAT_182eb785d == '\0') {
    FUN_1802f2810(&DAT_182d5c448);
    LOCK();
    UNLOCK();
    DAT_182eb785d = '\x01';
  }
  ExposureUnnoticed2_Master_Mission_MMission__CheckInitialize__06001266(0);
  lStack_e8 = **(longlong **)(DAT_182d5c448 + 0xb8);
  if (lStack_e8 == 0) {
                    /* WARNING: Subroutine does not return */
    FUN_18031dad0();
  }
  if (DAT_182eb5d50 != 0) {
    uVar9 = (uint)((ulonglong)&lStack_e8 >> 0xc);
    lVar7 = (ulonglong)((uVar9 & 0x1fffff) >> 6) * 8;
    do {
      uVar1 = *(ulonglong *)(&DAT_182f0c920 + lVar7);
      LOCK();
      bVar10 = uVar1 == *(ulonglong *)(&DAT_182f0c920 + lVar7);
      if (bVar10) {
        *(ulonglong *)(&DAT_182f0c920 + lVar7) = uVar1 | 1L << (uVar9 & 0x3f);
      }
      UNLOCK();
    } while (!bVar10);
  }
  uStack_e0 = (ulonglong)*(uint *)(lStack_e8 + 0x2c);
  uStack_c8 = 2;
  uStack_d8 = 0;
  uStack_d0 = 0;
  uStack_70 = uStack_e0;
  uStack_68 = 0;
  lStack_60 = 0;
  uStack_58 = 2;
  uStack_b0 = 0;
  plStack_a8 = &lStack_78;
  lStack_78 = lStack_e8;
  do {
    cVar4 = FUN_180f89450(&lStack_78,DAT_182d5c030);
    lVar7 = lStack_60;
    uVar1 = uStack_68;
    if (cVar4 == '\0') {
      return;
    }
    lVar2 = *(longlong *)(param_1 + 0x18);
    uVar5 = FUN_1802c43a0(uRam0000000182d5e1a8);
    FUN_1811cf4f0(uVar5,uRam0000000182d5e1b0);
    if (lVar2 == 0) {
                    /* WARNING: Subroutine does not return */
      FUN_18031dad0();
    }
    FUN_180e76960(lVar2,uVar1 & 0xffffffff,uVar5,2,
                  *(undefined8 *)
                   (*(longlong *)(*(longlong *)(lRam0000000182d5e1e8 + 0x20) + 0xc0) + 0x100));
    if (lVar7 == 0) {
                    /* WARNING: Subroutine does not return */
      FUN_18031dad0();
    }
    lVar7 = *(longlong *)(lVar7 + 0x28);
    if (lVar7 == 0) {
                    /* WARNING: Subroutine does not return */
      FUN_18031dad0();
    }
    uStack_d8 = 0;
    uStack_d0 = 0;
    if (DAT_182eb5d50 != 0) {
      uVar9 = (uint)((ulonglong)&lStack_e8 >> 0xc);
      lVar2 = (ulonglong)((uVar9 & 0x1fffff) >> 6) * 8;
      do {
        uVar3 = *(ulonglong *)(&DAT_182f0c920 + lVar2);
        LOCK();
        bVar10 = uVar3 == *(ulonglong *)(&DAT_182f0c920 + lVar2);
        if (bVar10) {
          *(ulonglong *)(&DAT_182f0c920 + lVar2) = uVar3 | 1L << (uVar9 & 0x3f);
        }
        UNLOCK();
      } while (!bVar10);
    }
    uStack_e0 = (ulonglong)*(uint *)(lVar7 + 0x2c);
    uStack_c8 = 2;
    uStack_98 = uStack_e0;
    uStack_90 = 0;
    lStack_88 = 0;
    uStack_80 = 2;
    uStack_c0 = 0;
    plStack_b8 = &lStack_a0;
    lStack_e8 = lVar7;
    lStack_a0 = lVar7;
    while (cVar4 = FUN_180f89450(&lStack_a0,uRam0000000182d5e1d0), lVar7 = lStack_88, cVar4 != '\0')
    {
      if (lStack_88 == 0) {
                    /* WARNING: Subroutine does not return */
        FUN_18031dad0();
      }
      if (*(longlong *)(lStack_88 + 0x20) == 0) {
                    /* WARNING: Subroutine does not return */
        FUN_18031dad0();
      }
      aiStackX_18[0] = *(int *)(*(longlong *)(lStack_88 + 0x20) + 0x28);
      uVar5 = uRam0000000182d5e178;
      if (((aiStackX_18[0] != 0) && (aiStackX_18[0] != 1)) &&
         (uVar5 = DAT_182d52e20, aiStackX_18[0] != 2)) {
        uVar5 = il2cpp_value_box(uRam0000000182d5e188,aiStackX_18);
                    /* WARNING: Subroutine does not return */
        _PrivateImplementationDetails___ThrowSwitchExpressionException__06001e66(uVar5,0);
      }
      if (*(longlong *)(lStack_88 + 0x20) == 0) {
                    /* WARNING: Subroutine does not return */
        FUN_18031dad0(uVar5);
      }
      uVar5 = System_String__Concat__0600021b
                        (uVar5,*(undefined8 *)(*(longlong *)(lStack_88 + 0x20) + 0x20),0);
      if (*(int *)(DAT_182d535d8 + 0xe0) == 0) {
        FUN_18035c820();
      }
      uVar5 = FUN_18031e0e0(uVar5);
      plVar6 = (longlong *)FUN_18164ba10(uVar5,0,1,0);
      if (plVar6 == (longlong *)0x0) {
        FUN_1800039f0(lVar7);
        lVar7 = *(longlong *)(lVar7 + 0x20);
        FUN_1800039f0(lVar7);
        uVar5 = *(undefined8 *)(lVar7 + 0x20);
        uVar8 = thunk_FUN_1802f2810(0x182d5e170);
        uVar5 = System_String__Concat__0600021b(uVar8,uVar5,0);
        uVar8 = thunk_FUN_1802f2810(&DAT_182d5e168);
        uVar8 = thunk_FUN_1802c43a0(uVar8);
        FUN_181f41b50(uVar8,uVar5,0);
        uVar5 = thunk_FUN_1802f2810(0x182d5e198);
                    /* WARNING: Subroutine does not return */
        FUN_18031da90(uVar8,uVar5);
      }
      lVar2 = *plVar6;
      if ((*(byte *)(lVar2 + 0x130) < *(byte *)(lRam0000000182d5e1a0 + 0x130)) ||
         (*(longlong *)
           (*(longlong *)(lVar2 + 200) + -8 + (ulonglong)*(byte *)(lRam0000000182d5e1a0 + 0x130) * 8
           ) != lRam0000000182d5e1a0)) {
                    /* WARNING: Subroutine does not return */
        FUN_18031e210(plVar6);
      }
      (**(code **)(lVar2 + 0x1f8))(plVar6,lVar7,*(undefined8 *)(lVar2 + 0x200));
      if (*(longlong *)(param_1 + 0x10) == 0) {
                    /* WARNING: Subroutine does not return */
        FUN_18031dad0();
      }
      FUN_180005be0(*(longlong *)(param_1 + 0x10),plVar6);
      if (*(longlong *)(param_1 + 0x18) == 0) {
                    /* WARNING: Subroutine does not return */
        FUN_18031dad0();
      }
      lVar7 = FUN_180e75f20(*(longlong *)(param_1 + 0x18),uVar1 & 0xffffffff);
      if (lVar7 == 0) {
                    /* WARNING: Subroutine does not return */
        FUN_18031dad0();
      }
      FUN_180005be0(lVar7,plVar6);
    }
  } while( true );
}

