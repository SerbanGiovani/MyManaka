// Ghidra pseudocode; not original source or compilable C.
// ev_81ace773f4f55223fa355915c0dc06796208b04fa20b847f08daa92f65d2c159

undefined8
ExposureUnnoticed2_Scripts_InGame_StageRandomPositionManager__GetRandomPosition__06001662
          (longlong param_1,undefined8 *param_2)

{
  int iVar1;
  undefined4 uVar2;
  longlong lVar3;
  ulonglong uVar4;
  char cVar5;
  uint uVar6;
  undefined8 uVar7;
  code *pcVar8;
  undefined8 uVar9;
  ulonglong uVar10;
  bool bVar11;
  float fVar12;
  undefined8 uStack_58;
  undefined4 uStack_50;
  undefined8 uStack_48;
  undefined4 *puStack_40;
  undefined8 uStack_38;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  longlong lStack_20;
  
  if (cRam0000000182eb7a37 == '\0') {
    FUN_1802f2810(&DAT_182d53a28);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d53a08);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d539f8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d58288);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d539e8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d5fef8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d539d0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d539c0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d539b8);
    LOCK();
    UNLOCK();
    cRam0000000182eb7a37 = '\x01';
  }
  lVar3 = *(longlong *)(param_1 + 0x30);
  if (lVar3 != 0) {
    *(int *)(lVar3 + 0x1c) = *(int *)(lVar3 + 0x1c) + 1;
    iVar1 = *(int *)(lVar3 + 0x18);
    *(undefined4 *)(lVar3 + 0x18) = 0;
    if (0 < iVar1) {
      FUN_181646f50(*(undefined8 *)(lVar3 + 0x10),0,iVar1,0);
    }
    lVar3 = *(longlong *)(param_1 + 0x28);
    if (lVar3 != 0) {
      if (DAT_182eb5d50 != 0) {
        uVar6 = (uint)((ulonglong)&uStack_48 >> 0xc);
        uVar10 = (ulonglong)((uVar6 & 0x1fffff) >> 6);
        do {
          uVar4 = *(ulonglong *)(&DAT_182f0c920 + uVar10 * 8);
          LOCK();
          bVar11 = uVar4 == *(ulonglong *)(&DAT_182f0c920 + uVar10 * 8);
          if (bVar11) {
            *(ulonglong *)(&DAT_182f0c920 + uVar10 * 8) = uVar4 | 1L << (ulonglong)(uVar6 & 0x3f);
          }
          UNLOCK();
        } while (!bVar11);
      }
      uStack_24 = *(undefined4 *)(lVar3 + 0x1c);
      uStack_38 = 0;
      uStack_48._0_4_ = (undefined4)lVar3;
      uStack_48._4_4_ = (undefined4)((ulonglong)lVar3 >> 0x20);
      uStack_30 = (undefined4)uStack_48;
      uStack_2c = uStack_48._4_4_;
      uStack_28 = 0;
      lStack_20 = 0;
      uStack_48 = 0;
      puStack_40 = &uStack_30;
code_r0x0001804a67a0:
      cVar5 = FUN_180f72b70(&uStack_30,DAT_182d53a08);
      lVar3 = lStack_20;
      if (cVar5 != '\0') {
        if (*(float *)(param_1 + 0x20) != 0.0) goto code_r0x0001804a67c6;
        goto code_r0x0001804a681a;
      }
      lVar3 = *(longlong *)(param_1 + 0x30);
      if (lVar3 != 0) {
        if (*(int *)(lVar3 + 0x18) == 0) {
          uVar7 = thunk_FUN_1802f2810(&DAT_182d53398);
          uVar7 = thunk_FUN_1802c43a0(uVar7);
          uVar9 = thunk_FUN_1802f2810(0x182d5fef0);
          FUN_18165bfb0(uVar7,uVar9,0);
          uVar9 = thunk_FUN_1802f2810(0x182d5fee8);
                    /* WARNING: Subroutine does not return */
          FUN_18031da90(uVar7,uVar9);
        }
        uVar2 = *(undefined4 *)(lVar3 + 0x18);
        pcVar8 = DAT_182ec0fd0;
        if ((DAT_182ec0fd0 == (code *)0x0) &&
           (pcVar8 = (code *)FUN_1802cf0c0(
                                          "UnityEngine.Random::RandomRangeInt(System.Int32,System.Int32)"
                                          ), pcVar8 == (code *)0x0)) {
          uVar7 = FUN_1802ced60("UnityEngine.Random::RandomRangeInt(System.Int32,System.Int32)");
                    /* WARNING: Subroutine does not return */
          FUN_1802cca90(uVar7,0);
        }
        DAT_182ec0fd0 = pcVar8;
        uVar6 = (*DAT_182ec0fd0)(0,uVar2);
        if (*(uint *)(lVar3 + 0x18) <= uVar6) {
                    /* WARNING: Subroutine does not return */
          FUN_181640100(0);
        }
        lVar3 = *(longlong *)(lVar3 + 0x10);
        if (lVar3 != 0) {
          if (uVar6 < *(uint *)(lVar3 + 0x18)) {
            return *(undefined8 *)(lVar3 + 0x20 + (longlong)(int)uVar6 * 8);
          }
                    /* WARNING: Subroutine does not return */
          FUN_18031dae0();
        }
      }
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
code_r0x0001804a67c6:
  if (lStack_20 == 0) {
                    /* WARNING: Subroutine does not return */
    FUN_18031dad0();
  }
  uVar7 = ExposureUnnoticed2_Scripts_InGame_Util_ColliderTriggerController__get_CenterObject__0600169c
                    (lStack_20,0);
  if (*(int *)(DAT_182d58288 + 0xe0) == 0) {
    FUN_18035c820();
  }
  uStack_58 = *param_2;
  uStack_50 = *(undefined4 *)(param_2 + 1);
  fVar12 = (float)ExposureUnnoticed2_Scripts_Base_ExternalMethodManager__DistSqrt__0600172a
                            (uVar7,&uStack_58);
  if (*(float *)(param_1 + 0x20) <= fVar12 && fVar12 != *(float *)(param_1 + 0x20)) {
code_r0x0001804a681a:
    if (*(longlong *)(param_1 + 0x30) == 0) {
                    /* WARNING: Subroutine does not return */
      FUN_18031dad0();
    }
    FUN_180002da0(*(longlong *)(param_1 + 0x30),lVar3);
  }
  goto code_r0x0001804a67a0;
}

