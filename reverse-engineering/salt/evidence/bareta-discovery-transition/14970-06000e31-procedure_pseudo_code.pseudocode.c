// Ghidra pseudocode; not original source or compilable C.
// ev_4742666b13c722ecce226b19e0b75ca6de30eb3413fede0a1d2dcad7d142ece2

void ExposureUnnoticed2_Object3D_Player_Scripts_PlayerStrangenessController__OnUpdate__06000e31
               (longlong param_1)

{
  undefined4 uVar1;
  longlong lVar2;
  ulonglong uVar3;
  char cVar4;
  longlong lVar5;
  ulonglong uVar6;
  uint uVar7;
  bool bVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  undefined8 uStack_70;
  longlong *plStack_68;
  undefined8 uStack_60;
  longlong lStack_58;
  longlong lStack_50;
  longlong lStack_48;
  
  if (cRam0000000182eb844a == '\0') {
    FUN_1802f2810(0x182d3ee80);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d3ee70);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d3ee58);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d58398);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d3ee50);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d594e8);
    LOCK();
    UNLOCK();
    cRam0000000182eb844a = '\x01';
  }
  lVar5 = *(longlong *)(param_1 + 0x10);
  if ((lVar5 != 0) && (lVar2 = *(longlong *)(lVar5 + 0x60), lVar2 != 0)) {
    fVar11 = (float)*(int *)(lVar2 + 0xb0) / 100.0 + *(float *)(lVar2 + 0xa0) + 1.0;
    *(undefined4 *)(lVar2 + 0x9c) = 0;
    if ((lVar5 != 0) && ((lVar2 != 0 && (lVar5 = *(longlong *)(lVar2 + 0x138), lVar5 != 0)))) {
      if (DAT_182eb5d50 != 0) {
        uVar7 = (uint)((ulonglong)&uStack_70 >> 0xc);
        uVar6 = (ulonglong)((uVar7 & 0x1fffff) >> 6);
        do {
          uVar3 = *(ulonglong *)(&DAT_182f0c920 + uVar6 * 8);
          LOCK();
          bVar8 = uVar3 == *(ulonglong *)(&DAT_182f0c920 + uVar6 * 8);
          if (bVar8) {
            *(ulonglong *)(&DAT_182f0c920 + uVar6 * 8) = uVar3 | 1L << (uVar7 & 0x3f);
          }
          UNLOCK();
        } while (!bVar8);
      }
      plStack_68 = (longlong *)((ulonglong)*(uint *)(lVar5 + 0x1c) << 0x20);
      uStack_60 = 0;
      lStack_50 = (longlong)plStack_68;
      lStack_48 = 0;
      uStack_70 = 0;
      plStack_68 = &lStack_58;
      lStack_58 = lVar5;
      while (cVar4 = FUN_180f72b70(&lStack_58,uRam0000000182d3ee70), cVar4 != '\0') {
        if (*(longlong *)(param_1 + 0x10) == 0) {
                    /* WARNING: Subroutine does not return */
          FUN_18031dad0();
        }
        lVar5 = *(longlong *)(*(longlong *)(param_1 + 0x10) + 0x60);
        if (lVar5 == 0) {
                    /* WARNING: Subroutine does not return */
          FUN_18031dad0();
        }
        fVar10 = *(float *)(lVar5 + 0x9c);
        if (lStack_48 == 0) {
                    /* WARNING: Subroutine does not return */
          FUN_18031dad0();
        }
        fVar9 = (float)ExposureUnnoticed2_Object3D_Light_StreetLightController__CalcBareyasusa__06001171
                                 (lStack_48,*(undefined8 *)(*(longlong *)(param_1 + 0x10) + 0x28),0)
        ;
        *(float *)(lVar5 + 0x9c) = fVar9 + fVar10;
      }
      lVar5 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
      if (lVar5 != 0) {
        if (*(char *)(lVar5 + 0x20) == '\0') {
          if ((*(longlong *)(param_1 + 0x10) == 0) ||
             (lVar5 = *(longlong *)(*(longlong *)(param_1 + 0x10) + 0x60), lVar5 == 0))
          goto code_r0x00018065fb69;
          fVar10 = *(float *)(lVar5 + 0x9c);
          uVar1 = *(undefined4 *)(*(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48) + 0x10);
          if (*(int *)(DAT_182d594e8 + 0xe0) == 0) {
            FUN_18035c820();
          }
          lVar5 = ExposureUnnoticed2_Master_Stage_MStage__Get__06001229(uVar1,0);
          if (lVar5 == 0) goto code_r0x00018065fb69;
          fVar9 = (float)*(int *)(lVar5 + 0x48) * 0.01;
          if (fVar10 <= fVar9) {
            fVar10 = fVar9;
          }
        }
        else {
          fVar10 = 1.0;
        }
        if (fVar10 < 0.0) {
          fVar10 = 0.0;
        }
        else if (1.0 < fVar10) {
          fVar10 = 1.0;
        }
        lVar5 = *(longlong *)(param_1 + 0x10);
        if (lVar5 != 0) {
          fVar9 = 0.1;
          if ((fVar11 < 0.1) || (fVar9 = 3.0, 3.0 < fVar11)) {
            fVar11 = fVar9;
          }
          if (((*(longlong *)(lVar5 + 0x60) != 0) &&
              (*(float *)(*(longlong *)(lVar5 + 0x60) + 0x98) = fVar11, lVar5 != 0)) &&
             (lVar5 = *(longlong *)(lVar5 + 0x60), lVar5 != 0)) {
            *(float *)(lVar5 + 0x94) = fVar10 * *(float *)(lVar5 + 0x98);
            ExposureUnnoticed2_Object3D_Player_Scripts_PlayerStrangenessController__CalcCacheMaxDiscomfort__06000e37
                      (param_1,0);
            return;
          }
        }
      }
    }
  }
code_r0x00018065fb69:
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

