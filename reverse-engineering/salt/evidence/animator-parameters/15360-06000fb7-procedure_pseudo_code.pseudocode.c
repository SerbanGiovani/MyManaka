// Ghidra pseudocode; not original source or compilable C.
// ev_9e854cb962ed57eb68e0e8a355aa1960ab7941f318d5cf2498c1d339e919be45

void ExposureUnnoticed2_Object3D_NPC_Script_NpcAnimationManager__OnUpdate__06000fb7
               (longlong param_1)

{
  float fVar1;
  float fVar2;
  undefined4 uVar3;
  longlong lVar4;
  longlong lVar5;
  ulonglong uVar6;
  char cVar7;
  code *pcVar8;
  undefined8 uVar9;
  ulonglong uVar10;
  uint uVar11;
  bool bVar12;
  bool bVar13;
  bool bVar14;
  undefined8 uStack_80;
  longlong *plStack_78;
  undefined8 uStack_70;
  undefined8 uStack_68;
  longlong lStack_60;
  ulonglong uStack_58;
  undefined8 uStack_50;
  undefined8 uStack_48;
  
  if (cRam0000000182eb771e == '\0') {
    FUN_1802f2810(0x182d59ed0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d59ed8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d59ec8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d59ec0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d59eb8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d52288);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d59ea8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d58378);
    LOCK();
    UNLOCK();
    cRam0000000182eb771e = '\x01';
  }
  lStack_60 = 0;
  uStack_58 = 0;
  uStack_50 = 0;
  uStack_48 = 0;
  if (*(longlong *)(param_1 + 0x20) != 0) {
    ExposureUnnoticed2_Scripts_Base_SmoothFloat__UpdateTo__0600175c();
    fVar1 = *(float *)(param_1 + 0x30);
    if (*(longlong *)(param_1 + 0x20) != 0) {
      fVar2 = *(float *)(*(longlong *)(param_1 + 0x20) + 0x10);
      if (*(int *)(DAT_182d52288 + 0xe0) == 0) {
        FUN_18035c820();
      }
      if (0.001 < ABS(fVar1 - fVar2)) {
        if (*(longlong *)(param_1 + 0x10) == 0) goto code_r0x00018041b620;
        lVar4 = *(longlong *)(*(longlong *)(param_1 + 0x10) + 0x90);
        if (*(int *)(DAT_182d59ea8 + 0xe0) == 0) {
          FUN_18035c820(DAT_182d59ea8);
        }
        if ((*(longlong *)(param_1 + 0x20) == 0) || (lVar4 == 0)) goto code_r0x00018041b620;
        FUN_181eea540(lVar4,**(undefined4 **)(DAT_182d59ea8 + 0xb8),
                      *(undefined4 *)(*(longlong *)(param_1 + 0x20) + 0x10),0);
        if (*(longlong *)(param_1 + 0x20) == 0) goto code_r0x00018041b620;
        *(undefined4 *)(param_1 + 0x30) = *(undefined4 *)(*(longlong *)(param_1 + 0x20) + 0x10);
      }
      if (((*(longlong *)(param_1 + 0x10) != 0) &&
          (*(longlong *)(*(longlong *)(param_1 + 0x10) + 0x40) != 0)) &&
         (bVar14 = false, *(longlong *)(param_1 + 0x28) != 0)) {
        ExposureUnnoticed2_Scripts_Base_SmoothFloat__UpdateTo__0600175c();
        lVar4 = *(longlong *)(param_1 + 0x18);
        if ((*(longlong *)(param_1 + 0x28) != 0) &&
           (uVar3 = *(undefined4 *)(*(longlong *)(param_1 + 0x28) + 0x10), lVar4 != 0)) {
          pcVar8 = pcRam0000000182ebf2d8;
          if ((pcRam0000000182ebf2d8 == (code *)0x0) &&
             (pcVar8 = (code *)FUN_1802cf0c0(
                                            "UnityEngine.Animator::SetLayerWeight(System.Int32,System.Single)"
                                            ), pcVar8 == (code *)0x0)) {
            uVar9 = FUN_1802ced60("UnityEngine.Animator::SetLayerWeight(System.Int32,System.Single)"
                                 );
                    /* WARNING: Subroutine does not return */
            FUN_1802cca90(uVar9,0);
          }
          pcRam0000000182ebf2d8 = pcVar8;
          (*pcRam0000000182ebf2d8)(lVar4,2,uVar3);
          lVar4 = *(longlong *)(param_1 + 0x18);
          if (*(int *)(DAT_182d59ea8 + 0xe0) == 0) {
            FUN_18035c820(DAT_182d59ea8);
          }
          if ((*(longlong *)(param_1 + 0x10) != 0) &&
             (lVar5 = *(longlong *)(*(longlong *)(param_1 + 0x10) + 0x40), lVar5 != 0)) {
            bVar13 = bVar14;
            if ((*(int *)(lVar5 + 0x10) == 0) &&
               (*(char *)(*(longlong *)(*(longlong *)(param_1 + 0x10) + 0x40) + 200) != '\0')) {
              if (*(longlong *)(param_1 + 0x20) == 0) goto code_r0x00018041b620;
              bVar13 = 0.5 <= *(float *)(*(longlong *)(param_1 + 0x20) + 0x10);
            }
            if (lVar4 != 0) {
              FUN_181eea680(lVar4,*(undefined4 *)(*(longlong *)(DAT_182d59ea8 + 0xb8) + 0xa0),bVar13
                            ,0);
              bVar13 = false;
              if ((*(longlong *)(param_1 + 0x10) != 0) &&
                 (lVar4 = *(longlong *)(*(longlong *)(param_1 + 0x10) + 0x40), lVar4 != 0)) {
                if (*(int *)(lVar4 + 0x10) != 1) {
                  if (DAT_182eb5493 == '\0') {
                    FUN_1802f2810(&DAT_182d592c0);
                    LOCK();
                    UNLOCK();
                    DAT_182eb5493 = '\x01';
                  }
                  if (**(longlong **)(DAT_182d592c0 + 0xb8) == 0) goto code_r0x00018041b620;
                  if (*(longlong *)(param_1 + 0x10) == 0) goto code_r0x00018041b620;
                  if (*(longlong *)(**(longlong **)(DAT_182d592c0 + 0xb8) + 0x18) !=
                      *(longlong *)(*(longlong *)(param_1 + 0x10) + 0x38)) {
                    lVar4 = *(longlong *)(param_1 + 0x38);
                    if (lVar4 == 0) goto code_r0x00018041b620;
                    if (DAT_182eb5d50 != 0) {
                      uVar11 = (uint)((ulonglong)&uStack_80 >> 0xc);
                      uVar10 = (ulonglong)((uVar11 & 0x1fffff) >> 6);
                      do {
                        uVar6 = *(ulonglong *)(&DAT_182f0c920 + uVar10 * 8);
                        LOCK();
                        bVar12 = uVar6 == *(ulonglong *)(&DAT_182f0c920 + uVar10 * 8);
                        if (bVar12) {
                          *(ulonglong *)(&DAT_182f0c920 + uVar10 * 8) =
                               uVar6 | 1L << (uVar11 & 0x3f);
                        }
                        UNLOCK();
                      } while (!bVar12);
                    }
                    uStack_68 = 2;
                    uStack_70 = 0;
                    uStack_58 = (ulonglong)*(uint *)(lVar4 + 0x2c);
                    uStack_50 = 0;
                    uStack_48 = 2;
                    uStack_80 = 0;
                    plStack_78 = &lStack_60;
                    lStack_60 = lVar4;
                    while (cVar7 = FUN_180f878c0(&lStack_60,uRam0000000182d59ec8), cVar7 != '\0') {
                      bVar13 = (char)((ulonglong)uStack_50 >> 0x20) != '\0' || bVar13 != false;
                    }
                  }
                }
                lVar4 = *(longlong *)(param_1 + 0x18);
                if (*(int *)(DAT_182d59ea8 + 0xe0) == 0) {
                  FUN_18035c820(DAT_182d59ea8);
                }
                if (lVar4 != 0) {
                  uVar3 = *(undefined4 *)(*(longlong *)(DAT_182d59ea8 + 0xb8) + 0x4c);
                  pcVar8 = DAT_182ebf348;
                  if ((DAT_182ebf348 == (code *)0x0) &&
                     (pcVar8 = (code *)FUN_1802cf0c0(
                                                  "UnityEngine.Animator::SetBoolID(System.Int32,System.Boolean)"
                                                  ), pcVar8 == (code *)0x0)) {
                    uVar9 = FUN_1802ced60(
                                         "UnityEngine.Animator::SetBoolID(System.Int32,System.Boolean)"
                                         );
                    /* WARNING: Subroutine does not return */
                    FUN_1802cca90(uVar9,0);
                  }
                  DAT_182ebf348 = pcVar8;
                  (*DAT_182ebf348)(lVar4,uVar3,bVar13);
                  lVar4 = *(longlong *)(param_1 + 0x18);
                  uVar3 = *(undefined4 *)(*(longlong *)(DAT_182d59ea8 + 0xb8) + 0xac);
                  if (DAT_182eb5493 == '\0') {
                    FUN_1802f2810(&DAT_182d592c0);
                    LOCK();
                    UNLOCK();
                    DAT_182eb5493 = '\x01';
                  }
                  if ((**(longlong **)(DAT_182d592c0 + 0xb8) != 0) &&
                     (*(longlong *)(param_1 + 0x10) != 0)) {
                    if (*(longlong *)(**(longlong **)(DAT_182d592c0 + 0xb8) + 0x18) ==
                        *(longlong *)(*(longlong *)(param_1 + 0x10) + 0x38)) {
                      if (((**(longlong **)(DAT_182d58378 + 0xb8) == 0) ||
                          (lVar5 = *(longlong *)(**(longlong **)(DAT_182d58378 + 0xb8) + 0x40),
                          lVar5 == 0)) || (lVar5 = *(longlong *)(lVar5 + 0x60), lVar5 == 0))
                      goto code_r0x00018041b620;
                      bVar14 = *(char *)(lVar5 + 0x50) == '\0';
                    }
                    if (lVar4 != 0) {
                      pcVar8 = DAT_182ebf348;
                      if ((DAT_182ebf348 == (code *)0x0) &&
                         (pcVar8 = (code *)FUN_1802cf0c0(
                                                  "UnityEngine.Animator::SetBoolID(System.Int32,System.Boolean)"
                                                  ), pcVar8 == (code *)0x0)) {
                        uVar9 = FUN_1802ced60(
                                             "UnityEngine.Animator::SetBoolID(System.Int32,System.Boolean)"
                                             );
                    /* WARNING: Subroutine does not return */
                        FUN_1802cca90(uVar9,0);
                      }
                      DAT_182ebf348 = pcVar8;
                      (*DAT_182ebf348)(lVar4,uVar3,bVar14);
                      return;
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
code_r0x00018041b620:
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

