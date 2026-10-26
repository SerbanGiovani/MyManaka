// Ghidra pseudocode; not original source or compilable C.
// ev_0c04fe5292add7b9b609fae8976e7f3cbffe2945f856c84352712d29a980252f

longlong ES3Internal_ES3Reflection__GetSerializableMembers__0600065f
                   (longlong param_1,undefined1 param_2,undefined8 param_3)

{
  int iVar1;
  longlong lVar2;
  ulonglong uVar3;
  undefined8 uVar4;
  longlong lVar5;
  longlong lVar6;
  longlong lVar7;
  ulonglong uVar8;
  uint uVar9;
  undefined4 *puVar10;
  uint uVar11;
  uint uVar12;
  longlong lVar13;
  longlong lVar14;
  bool bVar15;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  
  if (DAT_182eb808e == '\0') {
    FUN_1802f2810(&DAT_182d6a788);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d52c00);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d6a7a8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d6a7d0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d6a780);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d6a778);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d6a770);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d6a768);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d6a7c8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d6a7a0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d535d8);
    LOCK();
    UNLOCK();
    DAT_182eb808e = '\x01';
  }
  if (*(int *)(DAT_182d535d8 + 0xe0) == 0) {
    FUN_18035c820();
  }
  if (param_1 == 0) {
    lVar5 = FUN_1802c36c0(DAT_182d6a788,0);
    return lVar5;
  }
  uVar4 = FUN_1802c43a0(DAT_182d6a7c8);
  FUN_1811cf4f0(uVar4,DAT_182d6a7d0);
  if (*(int *)(DAT_182d52c00 + 0xe0) == 0) {
    FUN_18035c820();
  }
  uVar11 = 0;
  lVar5 = ES3Internal_ES3Reflection__GetSerializableFields__06000657
                    (param_1,uVar4,param_2,param_3,0x3e,0);
  uVar4 = FUN_1802c43a0(DAT_182d6a7a0);
  FUN_1811cf4f0(uVar4,DAT_182d6a7a8);
  lVar6 = ES3Internal_ES3Reflection__GetSerializableProperties__06000658
                    (param_1,uVar4,param_2,param_3,0x3e,0);
  if ((lVar5 == 0) || (lVar6 == 0)) {
                    /* WARNING: Subroutine does not return */
    FUN_18031dad0();
  }
  lVar7 = FUN_1802c36c0(DAT_182d6a788,*(int *)(lVar6 + 0x18) + *(int *)(lVar5 + 0x18));
  lVar13 = 0x20;
  lVar14 = 0x20;
  puVar10 = (undefined4 *)(lVar7 + 0x20);
  for (uVar9 = uVar11; (int)uVar9 < *(int *)(lVar5 + 0x18); uVar9 = uVar9 + 1) {
    if (*(uint *)(lVar5 + 0x18) <= uVar9) {
                    /* WARNING: Subroutine does not return */
      FUN_181640100(0);
    }
    lVar2 = *(longlong *)(lVar5 + 0x10);
    if (lVar2 == 0) {
LAB_18059bed0:
                    /* WARNING: Subroutine does not return */
      FUN_18031dad0();
    }
    if (*(uint *)(lVar2 + 0x18) <= uVar9) {
LAB_18059beca:
                    /* WARNING: Subroutine does not return */
      FUN_18031dae0();
    }
    local_38 = 0;
    local_48 = 0;
    uStack_40 = 0;
    ES3ReflectedMember___ctor__06000685(&local_48,*(undefined8 *)(lVar14 + lVar2),0);
    if (lVar7 == 0) goto LAB_18059bed0;
    if (*(uint *)(lVar7 + 0x18) <= uVar9) goto LAB_18059beca;
    bVar15 = DAT_182eb5d50 != 0;
    *puVar10 = (undefined4)local_48;
    puVar10[1] = local_48._4_4_;
    puVar10[2] = (undefined4)uStack_40;
    puVar10[3] = uStack_40._4_4_;
    *(undefined8 *)(puVar10 + 4) = local_38;
    if (bVar15) {
      uVar12 = (uint)((ulonglong)(lVar7 + (longlong)(int)uVar9 * 0x18 + 0x20) >> 0xc);
      lVar2 = (ulonglong)((uVar12 & 0x1fffff) >> 6) * 8;
      do {
        uVar8 = *(ulonglong *)(&DAT_182f0c920 + lVar2);
        LOCK();
        bVar15 = uVar8 == *(ulonglong *)(&DAT_182f0c920 + lVar2);
        if (bVar15) {
          *(ulonglong *)(&DAT_182f0c920 + lVar2) = uVar8 | 1L << (uVar12 & 0x3f);
        }
        UNLOCK();
      } while (!bVar15);
    }
    lVar14 = lVar14 + 8;
    puVar10 = puVar10 + 6;
  }
  while( true ) {
    if (*(int *)(lVar6 + 0x18) <= (int)uVar11) {
      return lVar7;
    }
    iVar1 = *(int *)(lVar5 + 0x18);
    if (*(uint *)(lVar6 + 0x18) <= uVar11) {
                    /* WARNING: Subroutine does not return */
      FUN_181640100(0);
    }
    lVar14 = *(longlong *)(lVar6 + 0x10);
    if (lVar14 == 0) break;
    if (*(uint *)(lVar14 + 0x18) <= uVar11) {
LAB_18059bede:
                    /* WARNING: Subroutine does not return */
      FUN_18031dae0();
    }
    local_38 = 0;
    local_48 = 0;
    uStack_40 = 0;
    ES3ReflectedMember___ctor__06000685(&local_48,*(undefined8 *)(lVar13 + lVar14),0);
    if (lVar7 == 0) break;
    lVar14 = (longlong)(int)(iVar1 + uVar11);
    if (*(uint *)(lVar7 + 0x18) <= iVar1 + uVar11) goto LAB_18059bede;
    bVar15 = DAT_182eb5d50 != 0;
    puVar10 = (undefined4 *)(lVar7 + 0x20 + lVar14 * 0x18);
    *puVar10 = (undefined4)local_48;
    puVar10[1] = local_48._4_4_;
    puVar10[2] = (undefined4)uStack_40;
    puVar10[3] = uStack_40._4_4_;
    *(undefined8 *)(lVar7 + 0x30 + lVar14 * 0x18) = local_38;
    if (bVar15) {
      uVar9 = (uint)((ulonglong)(lVar7 + lVar14 * 0x18 + 0x20) >> 0xc);
      uVar8 = (ulonglong)((uVar9 & 0x1fffff) >> 6);
      do {
        uVar3 = *(ulonglong *)(&DAT_182f0c920 + uVar8 * 8);
        LOCK();
        bVar15 = uVar3 == *(ulonglong *)(&DAT_182f0c920 + uVar8 * 8);
        if (bVar15) {
          *(ulonglong *)(&DAT_182f0c920 + uVar8 * 8) = uVar3 | 1L << (uVar9 & 0x3f);
        }
        UNLOCK();
      } while (!bVar15);
    }
    uVar11 = uVar11 + 1;
    lVar13 = lVar13 + 8;
  }
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

