// Ghidra pseudocode; not original source or compilable C.
// ev_141759f2f42f22e6dcb4756318028dcc492fd2e1a3488fe377b68f1da2f35f46

longlong ExposureUnnoticed2_Object3D_NPC_Script_NpcManager__GetNearOtherNpc__060010a3
                   (longlong param_1,longlong param_2)

{
  ulonglong uVar1;
  longlong lVar2;
  longlong lVar3;
  char cVar4;
  ulonglong uVar5;
  longlong lVar6;
  uint uVar7;
  bool bVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  float fVar12;
  undefined8 local_48;
  undefined4 *puStack_40;
  undefined8 uStack_38;
  undefined4 local_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  longlong local_20;
  
  if (DAT_182eb7779 == '\0') {
    FUN_1802f2810(&DAT_182d595a0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d59598);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d59590);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d59580);
    LOCK();
    UNLOCK();
    DAT_182eb7779 = '\x01';
  }
  lVar6 = *(longlong *)(param_1 + 0x38);
  if (lVar6 == 0) {
                    /* WARNING: Subroutine does not return */
    FUN_18031dad0();
  }
  if (DAT_182eb5d50 != 0) {
    uVar7 = (uint)((ulonglong)&local_48 >> 0xc);
    uVar5 = (ulonglong)((uVar7 & 0x1fffff) >> 6);
    do {
      uVar1 = *(ulonglong *)(&DAT_182f0c920 + uVar5 * 8);
      LOCK();
      bVar8 = uVar1 == *(ulonglong *)(&DAT_182f0c920 + uVar5 * 8);
      if (bVar8) {
        *(ulonglong *)(&DAT_182f0c920 + uVar5 * 8) = uVar1 | 1L << (uVar7 & 0x3f);
      }
      UNLOCK();
    } while (!bVar8);
  }
  uStack_24 = *(undefined4 *)(lVar6 + 0x1c);
  uStack_38 = 0;
  local_48._0_4_ = (undefined4)lVar6;
  local_48._4_4_ = (undefined4)((ulonglong)lVar6 >> 0x20);
  local_30 = (undefined4)local_48;
  uStack_2c = local_48._4_4_;
  uStack_28 = 0;
  local_20 = 0;
  local_48 = 0;
  puStack_40 = &local_30;
  lVar6 = 0;
  fVar12 = 3.4028235e+38;
  while( true ) {
    do {
      cVar4 = FUN_180f72b70(&local_30,DAT_182d59598);
      if (cVar4 == '\0') {
        return lVar6;
      }
    } while (local_20 == param_2);
    if (local_20 == 0) {
                    /* WARNING: Subroutine does not return */
      FUN_18031dad0();
    }
    if (*(longlong *)(local_20 + 0x30) == 0) {
                    /* WARNING: Subroutine does not return */
      FUN_18031dad0();
    }
    lVar2 = *(longlong *)(*(longlong *)(local_20 + 0x30) + 0x40);
    if (lVar2 == 0) break;
    if (param_2 == 0) {
                    /* WARNING: Subroutine does not return */
      FUN_18031dad0();
    }
    if (*(longlong *)(param_2 + 0x30) == 0) {
                    /* WARNING: Subroutine does not return */
      FUN_18031dad0();
    }
    lVar3 = *(longlong *)(*(longlong *)(param_2 + 0x30) + 0x40);
    if (lVar3 == 0) {
                    /* WARNING: Subroutine does not return */
      FUN_18031dad0();
    }
    fVar10 = (float)*(undefined8 *)(lVar2 + 0xdc) - (float)*(undefined8 *)(lVar3 + 0xdc);
    fVar11 = (float)((ulonglong)*(undefined8 *)(lVar2 + 0xdc) >> 0x20) -
             (float)((ulonglong)*(undefined8 *)(lVar3 + 0xdc) >> 0x20);
    fVar9 = *(float *)(lVar2 + 0xe4) - *(float *)(lVar3 + 0xe4);
    fVar9 = fVar11 * fVar11 + fVar10 * fVar10 + fVar9 * fVar9;
    if (fVar9 < fVar12) {
      lVar6 = local_20;
      fVar12 = fVar9;
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

