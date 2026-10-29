// Ghidra pseudocode; not original source or compilable C.
// ev_03351fb1b36fce832c814901ca2e5476e435e71e62ec502d601156c99eb4fe24

ulonglong ExposureUnnoticed2_ObjectUI_ResultPanel_ResultPanelView__OpenIfNeed__06001855(void)

{
  int *piVar1;
  undefined1 uVar2;
  undefined4 uVar3;
  ulonglong uVar4;
  char cVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  longlong lVar9;
  undefined8 uVar10;
  code *pcVar11;
  longlong lVar12;
  undefined8 uVar13;
  longlong lVar14;
  undefined1 *puVar15;
  longlong *plVar16;
  longlong *plVar17;
  ulonglong uVar18;
  ulonglong uVar19;
  bool bVar20;
  float fVar21;
  double dVar22;
  undefined8 uStackX_18;
  undefined8 uStackX_20;
  ulonglong in_stack_ffffffffffffff08;
  longlong lStack_e8;
  longlong *plStack_e0;
  undefined8 uStack_d8;
  undefined8 uStack_d0;
  undefined8 uStack_c8;
  longlong *plStack_c0;
  longlong lStack_b8;
  undefined8 uStack_b0;
  undefined8 uStack_a8;
  undefined8 uStack_a0;
  longlong lStack_98;
  longlong lStack_90;
  longlong lStack_88;
  longlong lStack_80;
  longlong *plStack_78;
  longlong lStack_70;
  
  if (cRam0000000182eb7b53 == '\0') {
    FUN_1802f2810(&DAT_182d58238);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5e058);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d53c48);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d58380);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d61a48);
    LOCK();
    UNLOCK();
    cRam0000000182eb7b53 = '\x01';
  }
  if (((**(longlong **)(DAT_182d53c48 + 0xb8) == 0) ||
      (lVar9 = *(longlong *)(**(longlong **)(DAT_182d53c48 + 0xb8) + 0x30), lVar9 == 0)) ||
     (lVar9 = *(longlong *)(lVar9 + 0x28), lVar9 == 0)) {
code_r0x0001804c88f1:
                    /* WARNING: Subroutine does not return */
    FUN_18031dad0();
  }
  if ((*(int *)(lVar9 + 0x20) == 0) &&
     (*(char *)(*(longlong *)(**(longlong **)(DAT_182d53c48 + 0xb8) + 0x30) + 0x38) == '\0')) {
    if (**(longlong **)(DAT_182d53c48 + 0xb8) != 0) {
      uVar18 = *(ulonglong *)(**(longlong **)(DAT_182d53c48 + 0xb8) + 0x30);
      if (uVar18 != 0) {
        *(undefined1 *)(uVar18 + 0x4c) = 0;
        return uVar18;
      }
    }
    goto code_r0x0001804c88f1;
  }
  if (*(int *)(DAT_182d58380 + 0xe0) == 0) {
    FUN_18035c820(DAT_182d58380);
  }
  if (((**(longlong **)(DAT_182d58238 + 0xb8) == 0) || (**(longlong **)(DAT_182d58380 + 0xb8) == 0))
     || (plVar16 = (longlong *)
                   ExposureUnnoticed2_Object3D_IngameManager_InGameUiManager__Open__060011a0
                             (**(longlong **)(DAT_182d58380 + 0xb8),
                              *(undefined8 *)(**(longlong **)(DAT_182d58238 + 0xb8) + 0x238),0,0),
        plVar16 == (longlong *)0x0)) goto code_r0x0001804c88f1;
  if ((*(byte *)(*plVar16 + 0x130) < *(byte *)(lRam0000000182d61a48 + 0x130)) ||
     (lVar9 = *(longlong *)(*plVar16 + 200),
     *(longlong *)(lVar9 + -8 + (ulonglong)*(byte *)(lRam0000000182d61a48 + 0x130) * 8) !=
     lRam0000000182d61a48)) goto code_r0x0001804c88f1;
  plVar17 = (longlong *)0x0;
  if (*(longlong *)(lVar9 + -8 + (ulonglong)*(byte *)(lRam0000000182d61a48 + 0x130) * 8) ==
      lRam0000000182d61a48) {
    plVar17 = plVar16;
  }
  if (cRam0000000182eb7b4d == '\0') {
    FUN_1802f2810(&DAT_182d58368);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d61af8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d61af0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d61ae8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5e218);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d5db50);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5e238);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5e160);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d61b08);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d61b00);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d61ae0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d61ad8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5e158);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5e150);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d61ad0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d61ac8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d58288);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d61ac0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d61ab8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d61ab0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d58398);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d61aa8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5e060);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d61aa0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d5c070);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d53c48);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d61a98);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d61a90);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5e148);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d61a88);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d594e8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d52288);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5e190);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d54d90);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d53aa8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d53cd0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d5bfa0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d61a80);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d61a78);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d61a70);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d61a68);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d5f2b0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d61a60);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d52e20);
    LOCK();
    UNLOCK();
    cRam0000000182eb7b4d = '\x01';
  }
  lStack_98 = 0;
  lStack_90 = 0;
  lStack_88 = 0;
  lStack_b8 = 0;
  uStack_b0 = 0;
  uStack_a8 = 0;
  uStack_a0 = 0;
  if ((**(longlong **)(DAT_182d53c48 + 0xb8) == 0) ||
     (lVar9 = *(longlong *)(**(longlong **)(DAT_182d53c48 + 0xb8) + 0x30), lVar9 == 0))
  goto code_r0x0001804c8186;
  if (*(char *)(lVar9 + 0x4c) != '\0') {
    lVar9 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
    if (lVar9 == 0) goto code_r0x0001804c8186;
    *(undefined8 *)(lVar9 + 0x1f0) = 0;
    lVar9 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
    if (lVar9 == 0) goto code_r0x0001804c8186;
    *(undefined4 *)(lVar9 + 0x120) = 0;
    if (((**(longlong **)(DAT_182d53c48 + 0xb8) == 0) ||
        (lVar9 = *(longlong *)(**(longlong **)(DAT_182d53c48 + 0xb8) + 0x30), lVar9 == 0)) ||
       (*(longlong *)(lVar9 + 0x28) == 0)) goto code_r0x0001804c8186;
    FUN_180005d70();
    if ((**(longlong **)(DAT_182d53c48 + 0xb8) == 0) ||
       (lVar9 = *(longlong *)(**(longlong **)(DAT_182d53c48 + 0xb8) + 0x30), lVar9 == 0))
    goto code_r0x0001804c8186;
    *(undefined1 *)(lVar9 + 0x4c) = 0;
  }
  lVar9 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
  if (lVar9 != 0) {
    lVar9 = ExposureUnnoticed2_Master_Rank_MRank__CalcCurrentRank__06001261
                      ((double)*(int *)(lVar9 + 0x1e8),0);
    plVar17[0x1b] = lVar9;
    FUN_18031d480(plVar17 + 0x1b);
    plVar16 = (longlong *)plVar17[0xf];
    lVar9 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
    if ((lVar9 != 0) && (uVar10 = FUN_181618010(lVar9 + 0x1e8,0), plVar16 != (longlong *)0x0)) {
      (**(code **)(*plVar16 + 0x558))(plVar16,uVar10,*(undefined8 *)(*plVar16 + 0x560));
      plVar16 = (longlong *)plVar17[0x11];
      lVar9 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
      if (lVar9 != 0) {
        uStackX_18 = CONCAT44(uStackX_18._4_4_,(int)*(double *)(lVar9 + 0x1e0));
        uVar10 = FUN_181618010(&uStackX_18,0);
        if (plVar16 != (longlong *)0x0) {
          (**(code **)(*plVar16 + 0x558))(plVar16,uVar10,*(undefined8 *)(*plVar16 + 0x560));
          lVar9 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
          if (lVar9 != 0) {
            *(int *)(lVar9 + 0x1e8) = *(int *)(lVar9 + 0x1e8) + (int)*(double *)(lVar9 + 0x1f0);
            lVar9 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
            if (lVar9 != 0) {
              *(double *)(lVar9 + 0x1e0) =
                   (double)(int)*(double *)(lVar9 + 0x1f0) + *(double *)(lVar9 + 0x1e0);
              if (*(int *)(DAT_182d5bfa0 + 0xe0) == 0) {
                FUN_18035c820(DAT_182d5bfa0);
              }
              if (**(char **)(DAT_182d5bfa0 + 0xb8) != '\0') {
                lVar9 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
                if (lVar9 == 0) goto code_r0x0001804c8186;
                iVar6 = *(int *)(lVar9 + 0x1e8);
                if (*(int *)(DAT_182d52288 + 0xe0) == 0) {
                  FUN_18035c820();
                }
                if (0xbd < iVar6) {
                  iVar6 = 0xbe;
                }
                *(int *)(lVar9 + 0x1e8) = iVar6;
                lVar9 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
                if (lVar9 == 0) goto code_r0x0001804c8186;
                dVar22 = *(double *)(lVar9 + 0x1e0);
                if (190.0 < dVar22) {
                  dVar22 = 190.0;
                }
                *(double *)(lVar9 + 0x1e0) = dVar22;
              }
              lVar9 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
              if (lVar9 != 0) {
                lVar9 = ExposureUnnoticed2_Master_Rank_MRank__CalcCurrentRank__06001261
                                  ((double)*(int *)(lVar9 + 0x1e8),0);
                plVar17[0x1c] = lVar9;
                if (DAT_182eb5d50 != 0) {
                  uVar8 = (uint)((ulonglong)(plVar17 + 0x1c) >> 0xc);
                  uVar18 = (ulonglong)((uVar8 & 0x1fffff) >> 6);
                  do {
                    uVar19 = *(ulonglong *)(&DAT_182f0c920 + uVar18 * 8);
                    LOCK();
                    bVar20 = uVar19 == *(ulonglong *)(&DAT_182f0c920 + uVar18 * 8);
                    if (bVar20) {
                      *(ulonglong *)(&DAT_182f0c920 + uVar18 * 8) = uVar19 | 1L << (uVar8 & 0x3f);
                    }
                    UNLOCK();
                  } while (!bVar20);
                }
                lVar9 = plVar17[0x1b];
                lVar12 = plVar17[0x1c];
                if (*(int *)(DAT_182d53aa8 + 0xe0) == 0) {
                  FUN_18035c820();
                }
                if (DAT_182ec12f4 == '\0') {
                  FUN_1802f2810(&DAT_182d53aa8);
                  LOCK();
                  UNLOCK();
                  DAT_182ec12f4 = '\x01';
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
                if (lVar12 == 0 && lVar9 == 0) {
                  bVar20 = false;
                }
                else if (lVar12 == 0) {
                  if (*(int *)(DAT_182d53aa8 + 0xe0) == 0) {
                    FUN_18035c820();
                  }
                  if (lVar9 == 0) goto code_r0x0001804c8186;
                  bVar20 = *(longlong *)(lVar9 + 0x10) != 0;
                }
                else if (lVar9 == 0) {
                  if (*(int *)(DAT_182d53aa8 + 0xe0) == 0) {
                    FUN_18035c820();
                  }
                  bVar20 = *(longlong *)(lVar12 + 0x10) != 0;
                }
                else {
                  bVar20 = lVar9 != lVar12;
                }
                if (bVar20) {
                  *(undefined1 *)((longlong)plVar17 + 0xd6) = 1;
                }
                if ((((**(longlong **)(DAT_182d53c48 + 0xb8) != 0) &&
                     (lVar9 = *(longlong *)(**(longlong **)(DAT_182d53c48 + 0xb8) + 0x28),
                     lVar9 != 0)) && (lVar9 = *(longlong *)(lVar9 + 0x30), lVar9 != 0)) &&
                   (lVar9 = *(longlong *)(lVar9 + 0x40), lVar9 != 0)) {
                  lVar9 = *(longlong *)(lVar9 + 0x60);
                  if (lVar9 != 0) {
                    *(longlong *)(lVar9 + 0x128) = plVar17[0x1c];
                    if (DAT_182eb5d50 != 0) {
                      uVar8 = (uint)(lVar9 + 0x128U >> 0xc);
                      uVar18 = (ulonglong)((uVar8 & 0x1fffff) >> 6);
                      do {
                        uVar19 = *(ulonglong *)(&DAT_182f0c920 + uVar18 * 8);
                        LOCK();
                        bVar20 = uVar19 == *(ulonglong *)(&DAT_182f0c920 + uVar18 * 8);
                        if (bVar20) {
                          *(ulonglong *)(&DAT_182f0c920 + uVar18 * 8) =
                               uVar19 | 1L << (ulonglong)(uVar8 & 0x3f);
                        }
                        UNLOCK();
                      } while (!bVar20);
                    }
                    lVar9 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
                    if (lVar9 != 0) {
                      lVar12 = plVar17[0x1c];
                      if (lVar12 != 0) {
                        iVar6 = *(int *)(lVar9 + 0x48);
                        if (*(int *)(lVar9 + 0x48) <= *(int *)(lVar12 + 0x18)) {
                          iVar6 = *(int *)(lVar12 + 0x18);
                        }
                        *(int *)(lVar9 + 0x48) = iVar6;
                        lVar9 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
                        if (lVar9 != 0) {
                          if (*(int *)(lVar9 + 0x134) < (int)*(double *)(lVar9 + 0x1f0)) {
                            *(undefined1 *)((longlong)plVar17 + 0xd7) = 1;
                            lVar9 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
                            if (lVar9 == 0) goto code_r0x0001804c8186;
                            *(int *)(lVar9 + 0x134) = (int)*(double *)(lVar9 + 0x1f0);
                          }
                          lVar9 = plVar17[0xb];
                          uVar2 = *(undefined1 *)((longlong)plVar17 + 0xd7);
                          if (lVar9 != 0) {
                            pcVar11 = DAT_182ec1138;
                            if ((DAT_182ec1138 == (code *)0x0) &&
                               (pcVar11 = (code *)FUN_1802cf0c0(
                                                  "UnityEngine.GameObject::SetActive(System.Boolean)"
                                                  ), pcVar11 == (code *)0x0)) {
                              uVar10 = FUN_1802ced60(
                                                  "UnityEngine.GameObject::SetActive(System.Boolean)"
                                                  );
                    /* WARNING: Subroutine does not return */
                              FUN_1802cca90(uVar10,0);
                            }
                            DAT_182ec1138 = pcVar11;
                            (*DAT_182ec1138)(lVar9,uVar2);
                            plVar16 = (longlong *)plVar17[0xc];
                            lVar9 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
                            if (lVar9 != 0) {
                              dVar22 = *(double *)(lVar9 + 0x1f0);
                              if (DAT_182ebb869 == '\0') {
                                FUN_1802f2810(&DAT_182d24690);
                                LOCK();
                                UNLOCK();
                                FUN_1802f2810(&DAT_182d39ea8);
                                LOCK();
                                UNLOCK();
                                DAT_182ebb869 = '\x01';
                              }
                              if ((*(byte *)(*(longlong *)(DAT_182d39ea8 + 0x20) + 0x135) & 1) == 0)
                              {
                                FUN_180320470();
                              }
                              if (*(int *)(DAT_182d24690 + 0xe0) == 0) {
                                FUN_18035c820();
                              }
                              lStack_e8 = 0;
                              plStack_e0 = (longlong *)0x0;
                              uVar10 = FUN_18161e8f0((int)dVar22,&lStack_e8,0,0);
                              uVar10 = System_String__Concat__0600021b(uVar10,DAT_182d5f2b0,0);
                              if (plVar16 != (longlong *)0x0) {
                                (**(code **)(*plVar16 + 0x558))
                                          (plVar16,uVar10,*(undefined8 *)(*plVar16 + 0x560));
                                plVar16 = (longlong *)plVar17[0xe];
                                lVar9 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
                                if (lVar9 != 0) {
                                  uVar3 = *(undefined4 *)(lVar9 + 0x134);
                                  if (DAT_182ebb869 == '\0') {
                                    FUN_1802f2810(&DAT_182d24690);
                                    LOCK();
                                    UNLOCK();
                                    FUN_1802f2810(&DAT_182d39ea8);
                                    LOCK();
                                    UNLOCK();
                                    DAT_182ebb869 = '\x01';
                                  }
                                  if ((*(byte *)(*(longlong *)(DAT_182d39ea8 + 0x20) + 0x135) & 1)
                                      == 0) {
                                    FUN_180320470();
                                  }
                                  if (*(int *)(DAT_182d24690 + 0xe0) == 0) {
                                    FUN_18035c820();
                                  }
                                  lStack_e8 = 0;
                                  plStack_e0 = (longlong *)0x0;
                                  uVar10 = FUN_18161e8f0(uVar3,&lStack_e8,0,0);
                                  uVar10 = System_String__Concat__0600021b(uVar10,DAT_182d5f2b0,0);
                                  if (plVar16 != (longlong *)0x0) {
                                    (**(code **)(*plVar16 + 0x558))
                                              (plVar16,uVar10,*(undefined8 *)(*plVar16 + 0x560));
                                    plVar16 = (longlong *)plVar17[0x10];
                                    lVar9 = *(longlong *)
                                             (*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
                                    if (lVar9 != 0) {
                                      uVar3 = *(undefined4 *)(lVar9 + 0x1e8);
                                      if (DAT_182ebb869 == '\0') {
                                        FUN_1802f2810(&DAT_182d24690);
                                        LOCK();
                                        UNLOCK();
                                        FUN_1802f2810(&DAT_182d39ea8);
                                        LOCK();
                                        UNLOCK();
                                        DAT_182ebb869 = '\x01';
                                      }
                                      if ((*(byte *)(*(longlong *)(DAT_182d39ea8 + 0x20) + 0x135) &
                                          1) == 0) {
                                        FUN_180320470();
                                      }
                                      if (*(int *)(DAT_182d24690 + 0xe0) == 0) {
                                        FUN_18035c820();
                                      }
                                      lStack_e8 = 0;
                                      plStack_e0 = (longlong *)0x0;
                                      uVar10 = FUN_18161e8f0(uVar3,&lStack_e8,0,0);
                                      uVar10 = System_String__Concat__0600021b
                                                         (uVar10,uRam0000000182d61a68,0);
                                      if (plVar16 != (longlong *)0x0) {
                                        (**(code **)(*plVar16 + 0x558))
                                                  (plVar16,uVar10,*(undefined8 *)(*plVar16 + 0x560))
                                        ;
                                        plVar16 = (longlong *)plVar17[0x15];
                                        if ((plVar17[0x1b] != 0) &&
                                           (uVar10 = 
                                                  ExposureUnnoticed2_Scripts_Base_Localizer__Trans__060017af
                                                            (*(undefined8 *)(plVar17[0x1b] + 0x20),0
                                                            ), plVar16 != (longlong *)0x0)) {
                                          (**(code **)(*plVar16 + 0x558))
                                                    (plVar16,uVar10,
                                                     *(undefined8 *)(*plVar16 + 0x560));
                                          plVar16 = (longlong *)plVar17[0x16];
                                          if ((plVar17[0x1c] != 0) &&
                                             (uVar10 = 
                                                  ExposureUnnoticed2_Scripts_Base_Localizer__Trans__060017af
                                                            (*(undefined8 *)(plVar17[0x1c] + 0x20),0
                                                            ), plVar16 != (longlong *)0x0)) {
                                            (**(code **)(*plVar16 + 0x558))
                                                      (plVar16,uVar10,
                                                       *(undefined8 *)(*plVar16 + 0x560));
                                            plVar16 = (longlong *)plVar17[0x12];
                                            lVar9 = *(longlong *)
                                                     (*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
                                            if (lVar9 != 0) {
                                              dVar22 = *(double *)(lVar9 + 0x1e0);
                                              if (DAT_182ebb869 == '\0') {
                                                FUN_1802f2810(&DAT_182d24690);
                                                LOCK();
                                                UNLOCK();
                                                FUN_1802f2810(&DAT_182d39ea8);
                                                LOCK();
                                                UNLOCK();
                                                DAT_182ebb869 = '\x01';
                                              }
                                              if ((*(byte *)(*(longlong *)(DAT_182d39ea8 + 0x20) +
                                                            0x135) & 1) == 0) {
                                                FUN_180320470();
                                              }
                                              if (*(int *)(DAT_182d24690 + 0xe0) == 0) {
                                                FUN_18035c820();
                                              }
                                              lStack_e8 = 0;
                                              plStack_e0 = (longlong *)0x0;
                                              uVar10 = FUN_18161e8f0((int)dVar22,&lStack_e8,0,0);
                                              uVar10 = System_String__Concat__0600021b
                                                                 (uVar10,DAT_182d5f2b0,0);
                                              if (plVar16 != (longlong *)0x0) {
                                                (**(code **)(*plVar16 + 0x558))
                                                          (plVar16,uVar10,
                                                           *(undefined8 *)(*plVar16 + 0x560));
                                                lVar9 = plVar17[0x18];
                                                if (*(int *)(DAT_182d58288 + 0xe0) == 0) {
                                                  FUN_18035c820();
                                                }
                                                ExposureUnnoticed2_Scripts_Base_ExternalMethodManager__DestroyChildren__0600172c
                                                          (lVar9,0);
                                                if ((plVar17[0x1c] != 0) &&
                                                   (lVar9 = 
                                                  ExposureUnnoticed2_Master_RankRelease_MRankRelease__GetByRank__0600125b
                                                            (*(undefined4 *)(plVar17[0x1c] + 0x18),0
                                                            ), lVar9 != 0)) {
                                                  if (DAT_182eb5d50 != 0) {
                                                    uVar8 = (uint)((ulonglong)&lStack_e8 >> 0xc);
                                                    uVar18 = (ulonglong)((uVar8 & 0x1fffff) >> 6);
                                                    do {
                                                      uVar19 = *(ulonglong *)
                                                                (&DAT_182f0c920 + uVar18 * 8);
                                                      LOCK();
                                                      bVar20 = uVar19 == *(ulonglong *)
                                                                          (&DAT_182f0c920 +
                                                                          uVar18 * 8);
                                                      if (bVar20) {
                                                        *(ulonglong *)(&DAT_182f0c920 + uVar18 * 8)
                                                             = uVar19 | 1L << (uVar8 & 0x3f);
                                                      }
                                                      UNLOCK();
                                                    } while (!bVar20);
                                                  }
                                                  plStack_e0 = (longlong *)
                                                               ((ulonglong)*(uint *)(lVar9 + 0x1c)
                                                               << 0x20);
                                                  uStack_d8 = 0;
                                                  plStack_78 = plStack_e0;
                                                  lStack_70 = 0;
                                                  uStack_c8 = 0;
                                                  plStack_c0 = &lStack_80;
                                                  lStack_e8 = lVar9;
                                                  lStack_80 = lVar9;
                                                  while (cVar5 = FUN_180f72b70(&lStack_80,
                                                                               uRam0000000182d61ae0)
                                                        , lVar9 = lStack_70, cVar5 != '\0') {
                                                    lVar12 = plVar17[0x17];
                                                    lVar14 = plVar17[0x18];
                                                    if (*(int *)(DAT_182d53aa8 + 0xe0) == 0) {
                                                      FUN_18035c820();
                                                    }
                                                    lVar12 = FUN_1809f1050(lVar12,lVar14,
                                                                           DAT_182d54d90);
                                                    if (lVar12 == 0) {
                    /* WARNING: Subroutine does not return */
                                                      FUN_18031dad0();
                                                    }
                                                    lVar12 = FUN_1809a08f0(lVar12,
                                                  uRam0000000182d61ab0);
                                                  if (lVar12 == 0) {
                    /* WARNING: Subroutine does not return */
                                                    FUN_18031dad0();
                                                  }
                                                  if (cRam0000000182eb7bf5 == '\0') {
                                                    FUN_1802f2810(&DAT_182d58398);
                                                    LOCK();
                                                    UNLOCK();
                                                    cRam0000000182eb7bf5 = '\x01';
                                                  }
                                                  if (*(longlong *)
                                                       (*(longlong *)(DAT_182d58398 + 0xb8) + 0x48)
                                                      == 0) {
                    /* WARNING: Subroutine does not return */
                                                    FUN_18031dad0();
                                                  }
                                                  if (lVar9 == 0) {
                    /* WARNING: Subroutine does not return */
                                                    FUN_18031dad0();
                                                  }
                                                  uVar10 = *(undefined8 *)(lVar9 + 0x20);
                                                  plVar16 = *(longlong **)(lVar12 + 0x20);
                                                  uVar13 = 
                                                  ExposureUnnoticed2_Scripts_Base_Localizer__Trans__060017af
                                                            (*(undefined8 *)(lVar9 + 0x30),0);
                                                  if (plVar16 == (longlong *)0x0) {
                    /* WARNING: Subroutine does not return */
                                                    FUN_18031dad0();
                                                  }
                                                  (**(code **)(*plVar16 + 0x558))
                                                            (plVar16,uVar13,
                                                             *(undefined8 *)(*plVar16 + 0x560));
                                                  plVar16 = *(longlong **)(lVar12 + 0x28);
                                                  uVar10 = 
                                                  ExposureUnnoticed2_Scripts_Base_Localizer__Trans__060017af
                                                            (uVar10,0);
                                                  if (plVar16 == (longlong *)0x0) {
                    /* WARNING: Subroutine does not return */
                                                    FUN_18031dad0();
                                                  }
                                                  (**(code **)(*plVar16 + 0x558))
                                                            (plVar16,uVar10,
                                                             *(undefined8 *)(*plVar16 + 0x560));
                                                  }
                                                  lVar9 = plVar17[0x14];
                                                  if (*(int *)(DAT_182d58288 + 0xe0) == 0) {
                                                    FUN_18035c820();
                                                  }
                                                  ExposureUnnoticed2_Scripts_Base_ExternalMethodManager__DestroyChildren__0600172c
                                                            (lVar9,0);
                                                  if ((**(longlong **)(lRam0000000182d5e190 + 0xb8)
                                                       != 0) &&
                                                     (lVar9 = *(longlong *)
                                                               (**(longlong **)
                                                                  (lRam0000000182d5e190 + 0xb8) +
                                                               0x10), lVar9 != 0)) {
                                                    if (DAT_182eb5d50 != 0) {
                                                      uVar8 = (uint)((ulonglong)&lStack_e8 >> 0xc);
                                                      uVar18 = (ulonglong)((uVar8 & 0x1fffff) >> 6);
                                                      do {
                                                        uVar19 = *(ulonglong *)
                                                                  (&DAT_182f0c920 + uVar18 * 8);
                                                        LOCK();
                                                        bVar20 = uVar19 == *(ulonglong *)
                                                                            (&DAT_182f0c920 +
                                                                            uVar18 * 8);
                                                        if (bVar20) {
                                                          *(ulonglong *)
                                                           (&DAT_182f0c920 + uVar18 * 8) =
                                                               uVar19 | 1L << (uVar8 & 0x3f);
                                                        }
                                                        UNLOCK();
                                                      } while (!bVar20);
                                                    }
                                                    plStack_e0 = (longlong *)
                                                                 ((ulonglong)*(uint *)(lVar9 + 0x1c)
                                                                 << 0x20);
                                                    uStack_d8 = 0;
                                                    lStack_90 = (longlong)plStack_e0;
                                                    lStack_88 = 0;
                                                    lStack_e8 = 0;
                                                    plStack_e0 = &lStack_98;
                                                    lStack_98 = lVar9;
                                                    while (cVar5 = FUN_180f72b70(&lStack_98,
                                                                                                                                                                  
                                                  uRam0000000182d5e158), lVar9 = lStack_88,
                                                  cVar5 != '\0') {
                                                    if (**(longlong **)(DAT_182d53c48 + 0xb8) == 0)
                                                    {
                    /* WARNING: Subroutine does not return */
                                                      FUN_18031dad0();
                                                    }
                                                    lVar12 = *(longlong *)
                                                              (**(longlong **)(DAT_182d53c48 + 0xb8)
                                                              + 0x30);
                                                    if (lVar12 == 0) {
                    /* WARNING: Subroutine does not return */
                                                      FUN_18031dad0();
                                                    }
                                                    lVar12 = *(longlong *)(lVar12 + 0x28);
                                                    if (lStack_88 == 0) {
                    /* WARNING: Subroutine does not return */
                                                      FUN_18031dad0();
                                                    }
                                                    if (*(longlong *)(lStack_88 + 0x28) == 0) {
                    /* WARNING: Subroutine does not return */
                                                      FUN_18031dad0();
                                                    }
                                                    if (lVar12 == 0) {
                    /* WARNING: Subroutine does not return */
                                                      FUN_18031dad0();
                                                    }
                                                    cVar5 = FUN_181101310(lVar12,*(undefined4 *)
                                                                                  (*(longlong *)
                                                                                    (lStack_88 +
                                                                                    0x28) + 0x50),
                                                                          DAT_182d5c070);
                                                    if (cVar5 != '\0') {
                                                      if (*(longlong *)(lVar9 + 0x28) == 0) {
                    /* WARNING: Subroutine does not return */
                                                        FUN_18031dad0();
                                                      }
                                                      uVar3 = *(undefined4 *)
                                                               (*(longlong *)(lVar9 + 0x28) + 0x54);
                                                      if (plVar17[0x1d] == 0) {
                    /* WARNING: Subroutine does not return */
                                                        FUN_18031dad0();
                                                      }
                                                      cVar5 = FUN_181101310(plVar17[0x1d],uVar3,
                                                                            uRam0000000182d61aa0);
                                                      if (cVar5 == '\0') {
                                                        if (plVar17[0x1d] == 0) {
                    /* WARNING: Subroutine does not return */
                                                          FUN_18031dad0();
                                                        }
                                                        FUN_181108fb0(plVar17[0x1d],uVar3,
                                                                      *(undefined8 *)
                                                                       (*(longlong *)
                                                                         (*(longlong *)
                                                                           (lRam0000000182d61aa8 +
                                                                           0x20) + 0xc0) + 0xa8));
                                                        lVar12 = plVar17[0x19];
                                                        lVar14 = plVar17[0x14];
                                                        if (*(int *)(DAT_182d53aa8 + 0xe0) == 0) {
                                                          FUN_18035c820();
                                                        }
                                                        lVar12 = FUN_1809f1050(lVar12,lVar14,
                                                                               DAT_182d54d90);
                                                        if (lVar12 == 0) {
                    /* WARNING: Subroutine does not return */
                                                          FUN_18031dad0();
                                                        }
                                                        lVar12 = FUN_1809a08f0(lVar12,
                                                  uRam0000000182d61ac0);
                                                  if (*(int *)(DAT_182d594e8 + 0xe0) == 0) {
                                                    FUN_18035c820();
                                                  }
                                                  lVar14 = 
                                                  ExposureUnnoticed2_Master_Stage_MStage__Get__06001229
                                                            (uVar3,0);
                                                  if (lVar14 == 0) {
                    /* WARNING: Subroutine does not return */
                                                    FUN_18031dad0();
                                                  }
                                                  uVar10 = 
                                                  ExposureUnnoticed2_Scripts_Base_Localizer__Trans__060017af
                                                            (*(undefined8 *)(lVar14 + 0x28),0);
                                                  if (lVar12 == 0) {
                    /* WARNING: Subroutine does not return */
                                                    FUN_18031dad0();
                                                  }
                                                  ExposureUnnoticed2_ObjectUI_InventoryPanel_EffectBarItemView__Initialize__0600199c
                                                            (lVar12,uVar10,0);
                                                  }
                                                  if (*(longlong *)(lVar9 + 0x28) == 0) {
                    /* WARNING: Subroutine does not return */
                                                    FUN_18031dad0();
                                                  }
                                                  uStack_c8 = 
                                                  ExposureUnnoticed2_Master_Mission_MMissionOverrideRecord__GetMissionName__06001275
                                                            (*(longlong *)(lVar9 + 0x28),0);
                                                  lVar12 = *(longlong *)
                                                            (*(longlong *)(DAT_182d58398 + 0xb8) +
                                                            0x48);
                                                  if (lVar12 == 0) {
                    /* WARNING: Subroutine does not return */
                                                    FUN_18031dad0();
                                                  }
                                                  lVar12 = *(longlong *)(lVar12 + 0x110);
                                                  if (*(longlong *)(lVar9 + 0x28) == 0) {
                    /* WARNING: Subroutine does not return */
                                                    FUN_18031dad0();
                                                  }
                                                  if (lVar12 == 0) {
                    /* WARNING: Subroutine does not return */
                                                    FUN_18031dad0();
                                                  }
                                                  fVar21 = (float)FUN_180005b40(lVar12,*(undefined4
                                                                                         *)(*(
                                                  longlong *)(lVar9 + 0x28) + 0x50));
                                                  uStackX_18._0_4_ = (int)fVar21;
                                                  uVar10 = FUN_181618010(&uStackX_18,0);
                                                  uStackX_20 = System_String__Concat__0600021b
                                                                         (uVar10,DAT_182d5f2b0,0);
                                                  if (**(longlong **)(DAT_182d53c48 + 0xb8) == 0) {
                    /* WARNING: Subroutine does not return */
                                                    FUN_18031dad0();
                                                  }
                                                  lVar12 = *(longlong *)
                                                            (**(longlong **)(DAT_182d53c48 + 0xb8) +
                                                            0x30);
                                                  if (lVar12 == 0) {
                    /* WARNING: Subroutine does not return */
                                                    FUN_18031dad0();
                                                  }
                                                  lVar12 = *(longlong *)(lVar12 + 0x30);
                                                  if (*(longlong *)(lVar9 + 0x28) == 0) {
                    /* WARNING: Subroutine does not return */
                                                    FUN_18031dad0();
                                                  }
                                                  if (lVar12 == 0) {
                    /* WARNING: Subroutine does not return */
                                                    FUN_18031dad0();
                                                  }
                                                  iVar6 = FUN_180006390(lVar12,*(undefined4 *)
                                                                                (*(longlong *)
                                                                                  (lVar9 + 0x28) +
                                                                                0x50));
                                                  uStackX_18 = CONCAT44(uStackX_18._4_4_,
                                                                        (float)iVar6 * 0.01);
                                                  uVar10 = FUN_1802c3ff0(DAT_182d53cd0,&uStackX_18);
                                                  uStackX_18 = System_String__Format__0600021f
                                                                         (uRam0000000182d61a70,
                                                                          uVar10,0);
                                                  lVar12 = *(longlong *)
                                                            (*(longlong *)(DAT_182d58398 + 0xb8) +
                                                            0x48);
                                                  if (lVar12 == 0) {
                    /* WARNING: Subroutine does not return */
                                                    FUN_18031dad0();
                                                  }
                                                  lVar12 = *(longlong *)(lVar12 + 0x118);
                                                  if (*(longlong *)(lVar9 + 0x28) == 0) {
                    /* WARNING: Subroutine does not return */
                                                    FUN_18031dad0();
                                                  }
                                                  if (lVar12 == 0) {
                    /* WARNING: Subroutine does not return */
                                                    FUN_18031dad0();
                                                  }
                                                  iVar6 = FUN_180006390(lVar12,*(undefined4 *)
                                                                                (*(longlong *)
                                                                                  (lVar9 + 0x28) +
                                                                                0x50));
                                                  if (**(longlong **)(DAT_182d53c48 + 0xb8) == 0) {
                    /* WARNING: Subroutine does not return */
                                                    FUN_18031dad0();
                                                  }
                                                  lVar12 = *(longlong *)
                                                            (**(longlong **)(DAT_182d53c48 + 0xb8) +
                                                            0x30);
                                                  if (lVar12 == 0) {
                    /* WARNING: Subroutine does not return */
                                                    FUN_18031dad0();
                                                  }
                                                  lVar12 = *(longlong *)(lVar12 + 0x30);
                                                  if (*(longlong *)(lVar9 + 0x28) == 0) {
                    /* WARNING: Subroutine does not return */
                                                    FUN_18031dad0();
                                                  }
                                                  if (lVar12 == 0) {
                    /* WARNING: Subroutine does not return */
                                                    FUN_18031dad0();
                                                  }
                                                  iVar7 = FUN_180006390(lVar12,*(undefined4 *)
                                                                                (*(longlong *)
                                                                                  (lVar9 + 0x28) +
                                                                                0x50));
                                                  lVar12 = plVar17[0x13];
                                                  lVar14 = plVar17[0x14];
                                                  if (*(int *)(DAT_182d53aa8 + 0xe0) == 0) {
                                                    FUN_18035c820();
                                                  }
                                                  lVar12 = FUN_1809f1050(lVar12,lVar14,DAT_182d54d90
                                                                        );
                                                  if (lVar12 == 0) {
                    /* WARNING: Subroutine does not return */
                                                    FUN_18031dad0();
                                                  }
                                                  lVar12 = FUN_1809a08f0(lVar12,uRam0000000182d61ab8
                                                                        );
                                                  if (lVar12 == 0) {
                    /* WARNING: Subroutine does not return */
                                                    FUN_18031dad0();
                                                  }
                                                  in_stack_ffffffffffffff08 =
                                                       CONCAT71((int7)(in_stack_ffffffffffffff08 >>
                                                                      8),iVar6 < iVar7);
                                                  ExposureUnnoticed2_ObjectUI_ResultPanel_CompletedMissionItem__Initialize__0600184c
                                                            (lVar12,uStack_c8,uStackX_20,uStackX_18,
                                                             in_stack_ffffffffffffff08,0);
                                                  if (*(longlong *)(lVar9 + 0x28) == 0) {
                    /* WARNING: Subroutine does not return */
                                                    FUN_18031dad0();
                                                  }
                                                  ExposureUnnoticed2_Scripts_InGame_GameStateFacade__AchieveMission__06001559
                                                            (*(undefined4 *)
                                                              (*(longlong *)(lVar9 + 0x28) + 0x50),0
                                                            );
                                                  lVar9 = *(longlong *)
                                                           (*(longlong *)(DAT_182d58398 + 0xb8) +
                                                           0x48);
                                                  if (lVar9 == 0) {
                    /* WARNING: Subroutine does not return */
                                                    FUN_18031dad0();
                                                  }
                                                  piVar1 = (int *)(lVar9 + 0x158);
                                                  *piVar1 = *piVar1 + 1;
                                                  }
                                                  }
                                                  lVar9 = *(longlong *)
                                                           (*(longlong *)(DAT_182d58398 + 0xb8) +
                                                           0x48);
                                                  if (lVar9 != 0) {
                                                    if (0.0 < *(float *)(lVar9 + 0x120)) {
                                                      uVar10 = 
                                                  ExposureUnnoticed2_Scripts_Base_Localizer__Trans__060017af
                                                            (uRam0000000182d61a60,0);
                                                  lVar9 = *(longlong *)
                                                           (*(longlong *)(DAT_182d58398 + 0xb8) +
                                                           0x48);
                                                  if (lVar9 == 0) goto code_r0x0001804c8186;
                                                  fVar21 = *(float *)(lVar9 + 0x120);
                                                  if (DAT_182ebb869 == '\0') {
                                                    FUN_1802f2810(&DAT_182d24690);
                                                    LOCK();
                                                    UNLOCK();
                                                    FUN_1802f2810(&DAT_182d39ea8);
                                                    LOCK();
                                                    UNLOCK();
                                                    DAT_182ebb869 = '\x01';
                                                  }
                                                  if ((*(byte *)(*(longlong *)(DAT_182d39ea8 + 0x20)
                                                                + 0x135) & 1) == 0) {
                                                    FUN_180320470();
                                                  }
                                                  if (*(int *)(DAT_182d24690 + 0xe0) == 0) {
                                                    FUN_18035c820();
                                                  }
                                                  lStack_e8 = 0;
                                                  plStack_e0 = (longlong *)0x0;
                                                  uVar13 = FUN_18161e8f0((int)fVar21,&lStack_e8,0,0)
                                                  ;
                                                  uVar13 = System_String__Concat__0600021b
                                                                     (uVar13,DAT_182d5f2b0,0);
                                                  lVar9 = plVar17[0x13];
                                                  lVar12 = plVar17[0x14];
                                                  if (*(int *)(DAT_182d53aa8 + 0xe0) == 0) {
                                                    FUN_18035c820();
                                                  }
                                                  lVar9 = FUN_1809f1050(lVar9,lVar12,DAT_182d54d90);
                                                  if ((lVar9 == 0) ||
                                                     (lVar9 = FUN_1809a08f0(lVar9,
                                                  uRam0000000182d61ab8), lVar9 == 0))
                                                  goto code_r0x0001804c8186;
                                                  ExposureUnnoticed2_ObjectUI_ResultPanel_CompletedMissionItem__Initialize__0600184c
                                                            (lVar9,uVar10,uVar13,DAT_182d52e20,
                                                             in_stack_ffffffffffffff08 &
                                                             0xffffffffffffff00,0);
                                                  }
                                                  if (**(longlong **)(lRam0000000182d5e190 + 0xb8)
                                                      != 0) {
                                                                                                        
                                                  ExposureUnnoticed2_Scripts_Mission_MissionManager__ResetMission__0600146a
                                                            (**(longlong **)
                                                               (lRam0000000182d5e190 + 0xb8),0);
                                                  lVar9 = *(longlong *)
                                                           (*(longlong *)(DAT_182d58398 + 0xb8) +
                                                           0x48);
                                                  if (lVar9 != 0) {
                                                    *(undefined8 *)(lVar9 + 0x1f0) = 0;
                                                    if ((**(longlong **)(DAT_182d53c48 + 0xb8) != 0)
                                                       && (lVar9 = *(longlong *)
                                                                    (**(longlong **)
                                                                       (DAT_182d53c48 + 0xb8) + 0x30
                                                                    ), lVar9 != 0)) {
                                                      *(undefined4 *)(lVar9 + 0x48) = 0;
                                                      lVar9 = *(longlong *)
                                                               (*(longlong *)(DAT_182d58398 + 0xb8)
                                                               + 0x48);
                                                      if (lVar9 != 0) {
                                                        *(undefined4 *)(lVar9 + 0x120) = 0;
                                                        if (((**(longlong **)(DAT_182d53c48 + 0xb8)
                                                              != 0) &&
                                                            (lVar9 = *(longlong *)
                                                                      (**(longlong **)
                                                                         (DAT_182d53c48 + 0xb8) +
                                                                      0x30), lVar9 != 0)) &&
                                                           (lVar9 = *(longlong *)(lVar9 + 0x28),
                                                           lVar9 != 0)) {
                                                          if (0 < *(int *)(lVar9 + 0x24)) {
                                                            FUN_181646f50(*(undefined8 *)
                                                                           (lVar9 + 0x18),0,
                                                                          *(undefined4 *)
                                                                           (lVar9 + 0x24),0);
                                                            if (*(longlong *)(lVar9 + 0x10) == 0)
                                                            goto code_r0x0001804c8186;
                                                            FUN_181646f50(*(undefined8 *)
                                                                           (lVar9 + 0x10),0,
                                                                          *(undefined4 *)
                                                                           (*(longlong *)
                                                                             (lVar9 + 0x10) + 0x18),
                                                                          0);
                                                            *(undefined8 *)(lVar9 + 0x20) = 0;
                                                            *(undefined4 *)(lVar9 + 0x28) =
                                                                 0xffffffff;
                                                          }
                                                          *(int *)(lVar9 + 0x38) =
                                                               *(int *)(lVar9 + 0x38) + 1;
                                                          if ((**(longlong **)(DAT_182d53c48 + 0xb8)
                                                               != 0) &&
                                                             (lVar9 = *(longlong *)
                                                                       (**(longlong **)
                                                                          (DAT_182d53c48 + 0xb8) +
                                                                       0x30), lVar9 != 0)) {
                                                            *(undefined1 *)(lVar9 + 0x38) = 0;
                                                            if ((**(longlong **)
                                                                   (DAT_182d53c48 + 0xb8) != 0) &&
                                                               ((lVar9 = *(longlong *)
                                                                          (**(longlong **)
                                                                             (DAT_182d53c48 + 0xb8)
                                                                          + 0x30), lVar9 != 0 &&
                                                                (lVar9 = *(longlong *)(lVar9 + 0x30)
                                                                , lVar9 != 0)))) {
                                                              if (DAT_182eb5d50 != 0) {
                                                                uVar8 = (uint)((ulonglong)&lStack_e8
                                                                              >> 0xc);
                                                                uVar18 = (ulonglong)
                                                                         ((uVar8 & 0x1fffff) >> 6);
                                                                do {
                                                                  uVar19 = *(ulonglong *)
                                                                            (&DAT_182f0c920 +
                                                                            uVar18 * 8);
                                                                  LOCK();
                                                                  bVar20 = uVar19 == *(ulonglong *)
                                                                                      (&
                                                  DAT_182f0c920 + uVar18 * 8);
                                                  if (bVar20) {
                                                    *(ulonglong *)(&DAT_182f0c920 + uVar18 * 8) =
                                                         uVar19 | 1L << (uVar8 & 0x3f);
                                                  }
                                                  UNLOCK();
                                                  } while (!bVar20);
                                                  }
                                                  plStack_e0 = (longlong *)
                                                               (ulonglong)*(uint *)(lVar9 + 0x2c);
                                                  uStack_d0 = 2;
                                                  uStack_d8 = 0;
                                                  uStack_b0 = (ulonglong)plStack_e0;
                                                  uStack_a8 = 0;
                                                  uStack_a0 = 2;
                                                  lStack_e8 = 0;
                                                  plStack_e0 = &lStack_b8;
                                                  lStack_b8 = lVar9;
                                                  do {
                                                    if (lStack_b8 == 0) {
                    /* WARNING: Subroutine does not return */
                                                      FUN_18031dad0();
                                                    }
                                                    if ((int)uStack_b0 != *(int *)(lStack_b8 + 0x2c)
                                                       ) {
                    /* WARNING: Subroutine does not return */
                                                      FUN_18163fef0(0);
                                                    }
                                                    uVar8 = uStack_b0._4_4_;
                                                    do {
                                                      if (lStack_b8 == 0) {
                    /* WARNING: Subroutine does not return */
                                                        FUN_18031dad0();
                                                      }
                                                      if (*(uint *)(lStack_b8 + 0x20) <= uVar8) {
                                                        uStack_b0 = CONCAT44(*(int *)(lStack_b8 +
                                                                                     0x20) + 1,
                                                                             (int)uStack_b0);
                                                        uStack_a8 = 0;
                                                        if (((**(longlong **)(DAT_182d53c48 + 0xb8)
                                                              == 0) ||
                                                            (lVar9 = *(longlong *)
                                                                      (**(longlong **)
                                                                         (DAT_182d53c48 + 0xb8) +
                                                                      0x30), lVar9 == 0)) ||
                                                           (*(longlong *)(lVar9 + 0x30) == 0))
                                                        goto code_r0x0001804c8186;
                                                        FUN_180004490();
                                                        if (((**(longlong **)(DAT_182d53c48 + 0xb8)
                                                              == 0) ||
                                                            (lVar9 = *(longlong *)
                                                                      (**(longlong **)
                                                                         (DAT_182d53c48 + 0xb8) +
                                                                      0x30), lVar9 == 0)) ||
                                                           (lVar9 = *(longlong *)(lVar9 + 0x40),
                                                           lVar9 == 0)) goto code_r0x0001804c8186;
                                                        iVar6 = *(int *)(lVar9 + 0x20);
                                                        if (0 < iVar6) {
                                                          if (*(longlong *)(lVar9 + 0x10) == 0)
                                                          goto code_r0x0001804c8186;
                                                          FUN_181646f50(*(undefined8 *)
                                                                         (lVar9 + 0x10),0,
                                                                        *(undefined4 *)
                                                                         (*(longlong *)
                                                                           (lVar9 + 0x10) + 0x18),0)
                                                          ;
                                                          *(undefined4 *)(lVar9 + 0x20) = 0;
                                                          *(undefined4 *)(lVar9 + 0x24) = 0xffffffff
                                                          ;
                                                          *(undefined4 *)(lVar9 + 0x28) = 0;
                                                          FUN_181646f50(*(undefined8 *)
                                                                         (lVar9 + 0x18),0,iVar6,0);
                                                        }
                                                        *(int *)(lVar9 + 0x2c) =
                                                             *(int *)(lVar9 + 0x2c) + 1;
                                                        if (*(int *)(uRam0000000182d61a78 + 0xe0) ==
                                                            0) {
                                                          FUN_18035c820();
                                                        }
                                                        uVar18 = *(ulonglong *)
                                                                  (uRam0000000182d61a78 + 0xb8);
                                                        lVar9 = *(longlong *)(uVar18 + 0x10);
                                                        if (lVar9 == 0) {
                                                          if (*(int *)(uRam0000000182d61a78 + 0xe0)
                                                              == 0) {
                                                            FUN_18035c820();
                                                          }
                                                          lVar12 = **(longlong **)
                                                                     (uRam0000000182d61a78 + 0xb8);
                                                          lVar9 = FUN_1802c43a0(DAT_182d58368);
                                                          lVar14 = lRam0000000182d61a80;
                                                          *(undefined8 *)(lVar9 + 0x10) =
                                                               *(undefined8 *)
                                                                (lRam0000000182d61a80 + 8);
                                                          *(longlong *)(lVar9 + 0x28) = lVar14;
                                                          *(longlong *)(lVar9 + 0x20) = lVar12;
                                                          if (DAT_182eb5d50 != 0) {
                                                            uVar8 = (uint)(lVar9 + 0x20U >> 0xc);
                                                            uVar18 = (ulonglong)
                                                                     ((uVar8 & 0x1fffff) >> 6);
                                                            do {
                                                              uVar19 = *(ulonglong *)
                                                                        (&DAT_182f0c920 + uVar18 * 8
                                                                        );
                                                              LOCK();
                                                              bVar20 = uVar19 == *(ulonglong *)
                                                                                  (&DAT_182f0c920 +
                                                                                  uVar18 * 8);
                                                              if (bVar20) {
                                                                *(ulonglong *)
                                                                 (&DAT_182f0c920 + uVar18 * 8) =
                                                                     uVar19 | 1L << (uVar8 & 0x3f);
                                                              }
                                                              UNLOCK();
                                                            } while (!bVar20);
                                                          }
                                                          cVar5 = *(char *)(lVar14 + 0x52);
                                                          *(longlong *)(lVar9 + 0x40) = lVar9;
                                                          if ((*(byte *)(lVar14 + 0x4c) & 0x10) == 0
                                                             ) {
                                                            if (lVar12 == 0) {
                                                              uVar10 = FUN_18031daf0();
                    /* WARNING: Subroutine does not return */
                                                              FUN_18031da90(uVar10,0);
                                                            }
code_r0x0001804c8097:
                                                            *(undefined8 *)(lVar9 + 0x40) =
                                                                 *(undefined8 *)(lVar9 + 0x20);
                                                            puVar15 = *(undefined1 **)(lVar9 + 0x10)
                                                            ;
                                                          }
                                                          else {
                                                            if (cVar5 != '\0')
                                                            goto code_r0x0001804c8097;
                                                            puVar15 = &LAB_1800c7840;
                                                          }
                                                          *(undefined1 **)(lVar9 + 0x18) = puVar15;
                                                          *(code **)(lVar9 + 0x38) = FUN_1801e91e0;
                                                          uVar18 = uRam0000000182d61a78;
                                                          *(longlong *)
                                                           (*(longlong *)
                                                             (uRam0000000182d61a78 + 0xb8) + 0x10) =
                                                               lVar9;
                                                          if (DAT_182eb5d50 != 0) {
                                                            uVar8 = (uint)(*(longlong *)
                                                                            (uRam0000000182d61a78 +
                                                                            0xb8) + 0x10U >> 0xc);
                                                            uVar19 = (ulonglong)
                                                                     ((uVar8 & 0x1fffff) >> 6);
                                                            do {
                                                              uVar4 = *(ulonglong *)
                                                                       (&DAT_182f0c920 + uVar19 * 8)
                                                              ;
                                                              LOCK();
                                                              uVar18 = *(ulonglong *)
                                                                        (&DAT_182f0c920 + uVar19 * 8
                                                                        );
                                                              bVar20 = uVar4 == uVar18;
                                                              if (bVar20) {
                                                                *(ulonglong *)
                                                                 (&DAT_182f0c920 + uVar19 * 8) =
                                                                     uVar4 | 1L << (uVar8 & 0x3f);
                                                                uVar18 = uVar4;
                                                              }
                                                              UNLOCK();
                                                            } while (!bVar20);
                                                          }
                                                        }
                                                        if (plVar17 != (longlong *)0x0) {
                                                          plVar17[6] = lVar9;
                                                          if (DAT_182eb5d50 != 0) {
                                                            uVar8 = (uint)((ulonglong)(plVar17 + 6)
                                                                          >> 0xc);
                                                            uVar19 = (ulonglong)
                                                                     ((uVar8 & 0x1fffff) >> 6);
                                                            do {
                                                              uVar4 = *(ulonglong *)
                                                                       (&DAT_182f0c920 + uVar19 * 8)
                                                              ;
                                                              LOCK();
                                                              uVar18 = *(ulonglong *)
                                                                        (&DAT_182f0c920 + uVar19 * 8
                                                                        );
                                                              bVar20 = uVar4 == uVar18;
                                                              if (bVar20) {
                                                                *(ulonglong *)
                                                                 (&DAT_182f0c920 + uVar19 * 8) =
                                                                     uVar4 | 1L << (uVar8 & 0x3f);
                                                                uVar18 = uVar4;
                                                              }
                                                              UNLOCK();
                                                            } while (!bVar20);
                                                          }
                                                          return uVar18;
                                                        }
                                                        goto code_r0x0001804c8186;
                                                      }
                                                      lVar9 = *(longlong *)(lStack_b8 + 0x18);
                                                      lVar12 = (longlong)(int)uVar8;
                                                      uStack_b0 = CONCAT44(uVar8 + 1,(int)uStack_b0)
                                                      ;
                                                      if (lVar9 == 0) {
                    /* WARNING: Subroutine does not return */
                                                        FUN_18031dad0();
                                                      }
                                                      if (*(uint *)(lVar9 + 0x18) <= uVar8) {
                    /* WARNING: Subroutine does not return */
                                                        FUN_18031dae0();
                                                      }
                                                      lVar14 = lVar12 + 2;
                                                      uVar8 = uVar8 + 1;
                                                    } while (*(int *)(lVar9 + (lVar12 + 2) * 0x10) <
                                                             0);
                                                    uVar3 = *(undefined4 *)
                                                             (lVar9 + 8 + lVar14 * 0x10);
                                                    iVar6 = *(int *)(lVar9 + 0xc + lVar14 * 0x10);
                                                    uStackX_18 = 0;
                                                    if ((*(byte *)(*(longlong *)
                                                                    (lRam0000000182d61ad8 + 0x20) +
                                                                  0x135) & 1) == 0) {
                                                      FUN_180320470();
                                                    }
                                                    lVar12 = DAT_182d5db50;
                                                    uStackX_18 = CONCAT44(iVar6,uVar3);
                                                    uStack_a8 = uStackX_18;
                                                    lVar9 = *(longlong *)
                                                             (*(longlong *)(DAT_182d58398 + 0xb8) +
                                                             0x48);
                                                    if (lVar9 == 0) {
                    /* WARNING: Subroutine does not return */
                                                      FUN_18031dad0();
                                                    }
                                                    uStackX_18 = *(undefined8 *)(lVar9 + 0x118);
                                                    lVar9 = *(longlong *)
                                                             (*(longlong *)
                                                               (*(longlong *)(DAT_182d58398 + 0xb8)
                                                               + 0x48) + 0x118);
                                                    if (lVar9 == 0) {
                    /* WARNING: Subroutine does not return */
                                                      FUN_18031dad0();
                                                    }
                                                    uVar8 = FUN_180e44350(lVar9,uVar3,
                                                                          *(undefined8 *)
                                                                           (*(longlong *)
                                                                             (*(longlong *)
                                                                               (DAT_182d5db50 + 0x20
                                                                               ) + 0xc0) + 0xf8));
                                                    if ((int)uVar8 < 0) {
                                                      uStackX_18 = CONCAT44(uStackX_18._4_4_,uVar3);
                                                      uVar10 = FUN_180003850(*(undefined8 *)
                                                                              (*(longlong *)
                                                                                (lVar12 + 0x20) +
                                                                              0xc0),0xe);
                                                      uVar10 = il2cpp_value_box(uVar10,&uStackX_18);
                    /* WARNING: Subroutine does not return */
                                                      FUN_181640310(uVar10,0);
                                                    }
                                                    lVar9 = *(longlong *)(lVar9 + 0x18);
                                                    if (lVar9 == 0) {
                    /* WARNING: Subroutine does not return */
                                                      FUN_18031dad0();
                                                    }
                                                    if (*(uint *)(lVar9 + 0x18) <= uVar8) {
                    /* WARNING: Subroutine does not return */
                                                      FUN_18031dae0();
                                                    }
                                                    iVar7 = *(int *)(lVar9 + 0x2c +
                                                                    (longlong)(int)uVar8 * 0x10);
                                                    if (iVar7 <= iVar6) {
                                                      iVar7 = iVar6;
                                                    }
                                                    FUN_180e4d6f0(uStackX_18,uVar3,iVar7,
                                                                  CONCAT71((int7)((ulonglong)
                                                                                  *(longlong *)
                                                                                   (
                                                  lRam0000000182d5e238 + 0x20) >> 8),1),
                                                  *(undefined8 *)
                                                   (*(longlong *)
                                                     (*(longlong *)(lRam0000000182d5e238 + 0x20) +
                                                     0xc0) + 0x100));
                                                  } while( true );
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
      }
    }
  }
code_r0x0001804c8186:
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

