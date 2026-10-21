// Ghidra pseudocode; not original source or compilable C.
// ev_898717e3d7d57c525a3d3c8587476b2b1a42d33f8046398715567a6dd6bb5900

void native_only_180993250__00000000(undefined8 param_1,char param_2,longlong param_3)

{
  ulonglong *puVar1;
  ulonglong uVar2;
  ulonglong uVar3;
  char cVar4;
  int iVar5;
  longlong lVar6;
  longlong *plVar7;
  undefined8 uVar8;
  longlong lVar9;
  longlong lVar10;
  longlong *plVar11;
  longlong *plVar12;
  undefined8 uVar13;
  undefined8 uVar14;
  uint uVar15;
  bool bVar16;
  longlong *local_res8;
  
  if (*(longlong *)(param_3 + 0x38) == 0) {
    FUN_1802f2810(&DAT_182d36a90);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d36aa0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d5f9b8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d36a98);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d36a78);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d583a0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d535d8);
    LOCK();
    UNLOCK();
    if (*(longlong *)(param_3 + 0x38) == 0) {
      FUN_1803204f0(param_3);
    }
  }
  plVar11 = (longlong *)0x0;
  local_res8 = (longlong *)0x0;
  lVar6 = **(longlong **)(param_3 + 0x38);
  if ((*(byte *)(lVar6 + 0x135) & 1) == 0) {
    lVar6 = FUN_180320470(lVar6);
  }
  lVar6 = FUN_1802c43a0(lVar6);
  if (lVar6 == 0) goto LAB_1809937d8;
  bVar16 = DAT_182eb5d50 != 0;
  *(undefined8 *)(lVar6 + 0x10) = param_1;
  if (bVar16) {
    uVar15 = (uint)(lVar6 + 0x10U >> 0xc);
    puVar1 = (ulonglong *)(&DAT_182f0c920 + (ulonglong)((uVar15 & 0x1fffff) >> 6) * 8);
    do {
      uVar3 = *puVar1;
      LOCK();
      uVar2 = *puVar1;
      if (uVar3 == uVar2) {
        *puVar1 = uVar3 | 1L << (uVar15 & 0x3f);
      }
      UNLOCK();
    } while (uVar3 != uVar2);
  }
  if (*(int *)(DAT_182d583a0 + 0xe0) == 0) {
    FUN_18035c820(DAT_182d583a0);
  }
  lVar9 = *(longlong *)(*(longlong *)(DAT_182d583a0 + 0xb8) + 8);
  if (lVar9 == 0) goto LAB_1809937d8;
  iVar5 = FUN_180e9f040(lVar9,*(undefined8 *)(lVar6 + 0x10),
                        *(undefined8 *)
                         (*(longlong *)(*(longlong *)(DAT_182d36aa0 + 0x20) + 0xc0) + 0xf8));
  if (-1 < iVar5) {
    return;
  }
  plVar7 = (longlong *)FUN_1802c43a0(DAT_182d36a90);
  FUN_180665bb0(plVar7,lVar6,*(undefined8 *)(*(longlong *)(param_3 + 0x38) + 0x18),0);
  if (*(int *)(DAT_182d583a0 + 0xe0) == 0) {
    FUN_18035c820(DAT_182d583a0);
  }
  lVar9 = *(longlong *)(*(longlong *)(DAT_182d583a0 + 0xb8) + 8);
  if (lVar9 == 0) goto LAB_1809937d8;
  FUN_180eba640(lVar9,*(undefined8 *)(lVar6 + 0x10),plVar7,1,
                *(undefined8 *)(*(longlong *)(*(longlong *)(DAT_182d36a98 + 0x20) + 0xc0) + 0x100));
  uVar8 = *(undefined8 *)(*(longlong *)(param_3 + 0x38) + 0x20);
  lVar6 = **(longlong **)(DAT_182d583a0 + 0xb8);
  if (*(int *)(DAT_182d535d8 + 0xe0) == 0) {
    FUN_18035c820();
  }
  uVar8 = FUN_181638ed0(uVar8,0);
  if (lVar6 == 0) goto LAB_1809937d8;
  cVar4 = FUN_180ebb4c0(lVar6,uVar8,&local_res8,DAT_182d5f9b8);
  if (cVar4 == '\0') {
    if (*(int *)(DAT_182d583a0 + 0xe0) == 0) {
      FUN_18035c820(DAT_182d583a0);
    }
    lVar6 = **(longlong **)(DAT_182d583a0 + 0xb8);
    uVar8 = *(undefined8 *)(*(longlong *)(param_3 + 0x38) + 0x20);
    if (*(int *)(DAT_182d535d8 + 0xe0) == 0) {
      FUN_18035c820();
    }
    uVar8 = FUN_181638ed0(uVar8,0);
    if (lVar6 == 0) goto LAB_1809937d8;
    uVar13 = *(undefined8 *)(*(longlong *)(*(longlong *)(DAT_182d36a78 + 0x20) + 0xc0) + 0x100);
    plVar11 = plVar7;
    goto LAB_180993542;
  }
  if (param_2 != '\0') {
    if (*(int *)(DAT_182d583a0 + 0xe0) == 0) {
      FUN_18035c820(DAT_182d583a0);
    }
    lVar6 = **(longlong **)(DAT_182d583a0 + 0xb8);
    uVar8 = *(undefined8 *)(*(longlong *)(param_3 + 0x38) + 0x20);
    if (*(int *)(DAT_182d535d8 + 0xe0) == 0) {
      FUN_18035c820();
    }
    uVar8 = FUN_181638ed0(uVar8,0);
    plVar12 = local_res8;
    if (DAT_182ebbb85 == '\0') {
      FUN_1802f2810(&DAT_182d535d8);
      LOCK();
      UNLOCK();
      DAT_182ebbb85 = '\x01';
    }
    if (plVar7 == (longlong *)0x0) {
LAB_180993781:
      plVar7 = plVar12;
      if (plVar12 != (longlong *)0x0) goto LAB_18099378d;
    }
    else {
      if (plVar12 != (longlong *)0x0) {
        lVar9 = FUN_1802c5ac0(*plVar7 + 0x20);
        lVar10 = FUN_1802c5ac0(*plVar12 + 0x20);
        if (*(int *)(DAT_182d535d8 + 0xe0) == 0) {
          FUN_18035c820();
        }
        if (lVar9 != lVar10) {
          FUN_1800039f0(plVar7);
          uVar8 = FUN_181636e20(plVar7,0);
          FUN_1800039f0(uVar8);
          uVar8 = FUN_180002bf0(0x19,uVar8);
          FUN_1800039f0(plVar12);
          uVar13 = FUN_181636e20(plVar12,0);
          FUN_1800039f0(uVar13);
          uVar13 = FUN_180002bf0(0x19,uVar13);
          uVar14 = thunk_FUN_1802f2810(&DAT_182d29b90);
          uVar8 = System_String__Format__06000220(uVar14,uVar8,uVar13,0);
          uVar13 = thunk_FUN_1802f2810(&DAT_182d53468);
          uVar13 = thunk_FUN_1802c43a0(uVar13);
          FUN_1815c6590(uVar13,uVar8,0);
          uVar8 = thunk_FUN_1802f2810(&DAT_182d29b98);
                    /* WARNING: Subroutine does not return */
          FUN_18031da90(uVar13,uVar8);
        }
        plVar12 = (longlong *)
                  (**(code **)(*plVar7 + 0x1d8))(plVar7,plVar12,*(undefined8 *)(*plVar7 + 0x1e0));
        goto LAB_180993781;
      }
LAB_18099378d:
      uVar13 = DAT_182d36a90;
      plVar11 = (longlong *)FUN_1802c42e0(plVar7,DAT_182d36a90);
      if (plVar11 == (longlong *)0x0) {
                    /* WARNING: Subroutine does not return */
        FUN_18031e210(plVar7,uVar13);
      }
    }
    if (lVar6 == 0) goto LAB_1809937d8;
    uVar13 = *(undefined8 *)(*(longlong *)(*(longlong *)(DAT_182d36a78 + 0x20) + 0xc0) + 0x100);
    goto LAB_180993542;
  }
  if (*(int *)(DAT_182d583a0 + 0xe0) == 0) {
    FUN_18035c820(DAT_182d583a0);
  }
  lVar6 = **(longlong **)(DAT_182d583a0 + 0xb8);
  uVar8 = *(undefined8 *)(*(longlong *)(param_3 + 0x38) + 0x20);
  if (*(int *)(DAT_182d535d8 + 0xe0) == 0) {
    FUN_18035c820();
  }
  uVar8 = FUN_181638ed0(uVar8,0);
  plVar12 = local_res8;
  if (DAT_182ebbb85 == '\0') {
    FUN_1802f2810(&DAT_182d535d8);
    LOCK();
    UNLOCK();
    DAT_182ebbb85 = '\x01';
  }
  if (plVar12 == (longlong *)0x0) {
LAB_180993643:
    plVar12 = plVar7;
    if (plVar7 != (longlong *)0x0) goto LAB_18099364f;
  }
  else {
    if (plVar7 != (longlong *)0x0) {
      lVar9 = FUN_1802c5ac0(*plVar12 + 0x20);
      lVar10 = FUN_1802c5ac0(*plVar7 + 0x20);
      if (*(int *)(DAT_182d535d8 + 0xe0) == 0) {
        FUN_18035c820();
      }
      if (lVar9 != lVar10) {
        FUN_1800039f0(plVar12);
        uVar8 = FUN_181636e20(plVar12,0);
        FUN_1800039f0(uVar8);
        uVar8 = FUN_180002bf0(0x19,uVar8);
        FUN_1800039f0(plVar7);
        uVar13 = FUN_181636e20(plVar7,0);
        FUN_1800039f0(uVar13);
        uVar13 = FUN_180002bf0(0x19,uVar13);
        uVar14 = thunk_FUN_1802f2810(&DAT_182d29b90);
        uVar8 = System_String__Format__06000220(uVar14,uVar8,uVar13,0);
        uVar13 = thunk_FUN_1802f2810(&DAT_182d53468);
        uVar13 = thunk_FUN_1802c43a0(uVar13);
        FUN_1815c6590(uVar13,uVar8,0);
        uVar8 = thunk_FUN_1802f2810(&DAT_182d29b98);
                    /* WARNING: Subroutine does not return */
        FUN_18031da90(uVar13,uVar8);
      }
      plVar7 = (longlong *)
               (**(code **)(*plVar12 + 0x1d8))(plVar12,plVar7,*(undefined8 *)(*plVar12 + 0x1e0));
      goto LAB_180993643;
    }
LAB_18099364f:
    uVar13 = DAT_182d36a90;
    plVar11 = (longlong *)FUN_1802c42e0(plVar12,DAT_182d36a90);
    if (plVar11 == (longlong *)0x0) {
                    /* WARNING: Subroutine does not return */
      FUN_18031e210(plVar12,uVar13);
    }
  }
  local_res8 = plVar11;
  if (lVar6 == 0) {
LAB_1809937d8:
                    /* WARNING: Subroutine does not return */
    FUN_18031dad0();
  }
  uVar13 = *(undefined8 *)(*(longlong *)(*(longlong *)(DAT_182d36a78 + 0x20) + 0xc0) + 0x100);
LAB_180993542:
  FUN_180eba640(lVar6,uVar8,plVar11,1,uVar13);
  return;
}

