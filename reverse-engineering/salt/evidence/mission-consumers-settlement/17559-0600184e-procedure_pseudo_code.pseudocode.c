// Ghidra pseudocode; not original source or compilable C.
// ev_7443fe56f7c2b7d60096fe31118dcab58915cef563289ab35d049f6c520ee031

ulonglong ExposureUnnoticed2_ObjectUI_ResultPanel_ResultPanelView__Initialize__0600184e
                    (longlong param_1)

{
  int *piVar1;
  undefined1 uVar2;
  undefined4 uVar3;
  longlong *plVar4;
  undefined8 uVar5;
  ulonglong uVar6;
  char cVar7;
  int iVar8;
  int iVar9;
  uint uVar10;
  undefined8 uVar11;
  code *pcVar12;
  longlong lVar13;
  longlong lVar14;
  undefined8 uVar15;
  longlong lVar16;
  undefined8 uVar17;
  undefined1 *puVar18;
  ulonglong uVar19;
  ulonglong uVar20;
  bool bVar21;
  float fVar22;
  double dVar23;
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
     (lVar13 = *(longlong *)(**(longlong **)(DAT_182d53c48 + 0xb8) + 0x30), lVar13 == 0))
  goto code_r0x0001804c8186;
  if (*(char *)(lVar13 + 0x4c) != '\0') {
    lVar13 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
    if (lVar13 == 0) goto code_r0x0001804c8186;
    *(undefined8 *)(lVar13 + 0x1f0) = 0;
    lVar13 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
    if (lVar13 == 0) goto code_r0x0001804c8186;
    *(undefined4 *)(lVar13 + 0x120) = 0;
    if (((**(longlong **)(DAT_182d53c48 + 0xb8) == 0) ||
        (lVar13 = *(longlong *)(**(longlong **)(DAT_182d53c48 + 0xb8) + 0x30), lVar13 == 0)) ||
       (*(longlong *)(lVar13 + 0x28) == 0)) goto code_r0x0001804c8186;
    FUN_180005d70();
    if ((**(longlong **)(DAT_182d53c48 + 0xb8) == 0) ||
       (lVar13 = *(longlong *)(**(longlong **)(DAT_182d53c48 + 0xb8) + 0x30), lVar13 == 0))
    goto code_r0x0001804c8186;
    *(undefined1 *)(lVar13 + 0x4c) = 0;
  }
  lVar13 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
  if (lVar13 != 0) {
    uVar11 = ExposureUnnoticed2_Master_Rank_MRank__CalcCurrentRank__06001261
                       ((double)*(int *)(lVar13 + 0x1e8),0);
    *(undefined8 *)(param_1 + 0xd8) = uVar11;
    FUN_18031d480(param_1 + 0xd8);
    plVar4 = *(longlong **)(param_1 + 0x78);
    lVar13 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
    if ((lVar13 != 0) && (uVar11 = FUN_181618010(lVar13 + 0x1e8,0), plVar4 != (longlong *)0x0)) {
      (**(code **)(*plVar4 + 0x558))(plVar4,uVar11,*(undefined8 *)(*plVar4 + 0x560));
      plVar4 = *(longlong **)(param_1 + 0x88);
      lVar13 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
      if (lVar13 != 0) {
        uStackX_18 = CONCAT44(uStackX_18._4_4_,(int)*(double *)(lVar13 + 0x1e0));
        uVar11 = FUN_181618010(&uStackX_18,0);
        if (plVar4 != (longlong *)0x0) {
          (**(code **)(*plVar4 + 0x558))(plVar4,uVar11,*(undefined8 *)(*plVar4 + 0x560));
          lVar13 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
          if (lVar13 != 0) {
            *(int *)(lVar13 + 0x1e8) = *(int *)(lVar13 + 0x1e8) + (int)*(double *)(lVar13 + 0x1f0);
            lVar13 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
            if (lVar13 != 0) {
              *(double *)(lVar13 + 0x1e0) =
                   (double)(int)*(double *)(lVar13 + 0x1f0) + *(double *)(lVar13 + 0x1e0);
              if (*(int *)(DAT_182d5bfa0 + 0xe0) == 0) {
                FUN_18035c820(DAT_182d5bfa0);
              }
              if (**(char **)(DAT_182d5bfa0 + 0xb8) != '\0') {
                lVar13 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
                if (lVar13 == 0) goto code_r0x0001804c8186;
                iVar8 = *(int *)(lVar13 + 0x1e8);
                if (*(int *)(DAT_182d52288 + 0xe0) == 0) {
                  FUN_18035c820();
                }
                if (0xbd < iVar8) {
                  iVar8 = 0xbe;
                }
                *(int *)(lVar13 + 0x1e8) = iVar8;
                lVar13 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
                if (lVar13 == 0) goto code_r0x0001804c8186;
                dVar23 = *(double *)(lVar13 + 0x1e0);
                if (190.0 < dVar23) {
                  dVar23 = 190.0;
                }
                *(double *)(lVar13 + 0x1e0) = dVar23;
              }
              lVar13 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
              if (lVar13 != 0) {
                uVar11 = ExposureUnnoticed2_Master_Rank_MRank__CalcCurrentRank__06001261
                                   ((double)*(int *)(lVar13 + 0x1e8),0);
                *(undefined8 *)(param_1 + 0xe0) = uVar11;
                if (DAT_182eb5d50 != 0) {
                  uVar10 = (uint)(param_1 + 0xe0U >> 0xc);
                  uVar19 = (ulonglong)((uVar10 & 0x1fffff) >> 6);
                  do {
                    uVar20 = *(ulonglong *)(&DAT_182f0c920 + uVar19 * 8);
                    LOCK();
                    bVar21 = uVar20 == *(ulonglong *)(&DAT_182f0c920 + uVar19 * 8);
                    if (bVar21) {
                      *(ulonglong *)(&DAT_182f0c920 + uVar19 * 8) = uVar20 | 1L << (uVar10 & 0x3f);
                    }
                    UNLOCK();
                  } while (!bVar21);
                }
                lVar13 = *(longlong *)(param_1 + 0xd8);
                lVar14 = *(longlong *)(param_1 + 0xe0);
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
                if (lVar14 == 0 && lVar13 == 0) {
                  bVar21 = false;
                }
                else if (lVar14 == 0) {
                  if (*(int *)(DAT_182d53aa8 + 0xe0) == 0) {
                    FUN_18035c820();
                  }
                  if (lVar13 == 0) goto code_r0x0001804c8186;
                  bVar21 = *(longlong *)(lVar13 + 0x10) != 0;
                }
                else if (lVar13 == 0) {
                  if (*(int *)(DAT_182d53aa8 + 0xe0) == 0) {
                    FUN_18035c820();
                  }
                  bVar21 = *(longlong *)(lVar14 + 0x10) != 0;
                }
                else {
                  bVar21 = lVar13 != lVar14;
                }
                if (bVar21) {
                  *(undefined1 *)(param_1 + 0xd6) = 1;
                }
                if ((((**(longlong **)(DAT_182d53c48 + 0xb8) != 0) &&
                     (lVar13 = *(longlong *)(**(longlong **)(DAT_182d53c48 + 0xb8) + 0x28),
                     lVar13 != 0)) && (lVar13 = *(longlong *)(lVar13 + 0x30), lVar13 != 0)) &&
                   (lVar13 = *(longlong *)(lVar13 + 0x40), lVar13 != 0)) {
                  lVar13 = *(longlong *)(lVar13 + 0x60);
                  if (lVar13 != 0) {
                    *(undefined8 *)(lVar13 + 0x128) = *(undefined8 *)(param_1 + 0xe0);
                    if (DAT_182eb5d50 != 0) {
                      uVar10 = (uint)(lVar13 + 0x128U >> 0xc);
                      uVar19 = (ulonglong)((uVar10 & 0x1fffff) >> 6);
                      do {
                        uVar20 = *(ulonglong *)(&DAT_182f0c920 + uVar19 * 8);
                        LOCK();
                        bVar21 = uVar20 == *(ulonglong *)(&DAT_182f0c920 + uVar19 * 8);
                        if (bVar21) {
                          *(ulonglong *)(&DAT_182f0c920 + uVar19 * 8) =
                               uVar20 | 1L << (ulonglong)(uVar10 & 0x3f);
                        }
                        UNLOCK();
                      } while (!bVar21);
                    }
                    lVar13 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
                    if (lVar13 != 0) {
                      lVar14 = *(longlong *)(param_1 + 0xe0);
                      if (lVar14 != 0) {
                        iVar8 = *(int *)(lVar13 + 0x48);
                        if (*(int *)(lVar13 + 0x48) <= *(int *)(lVar14 + 0x18)) {
                          iVar8 = *(int *)(lVar14 + 0x18);
                        }
                        *(int *)(lVar13 + 0x48) = iVar8;
                        lVar13 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
                        if (lVar13 != 0) {
                          if (*(int *)(lVar13 + 0x134) < (int)*(double *)(lVar13 + 0x1f0)) {
                            *(undefined1 *)(param_1 + 0xd7) = 1;
                            lVar13 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
                            if (lVar13 == 0) goto code_r0x0001804c8186;
                            *(int *)(lVar13 + 0x134) = (int)*(double *)(lVar13 + 0x1f0);
                          }
                          lVar13 = *(longlong *)(param_1 + 0x58);
                          uVar2 = *(undefined1 *)(param_1 + 0xd7);
                          if (lVar13 != 0) {
                            pcVar12 = DAT_182ec1138;
                            if ((DAT_182ec1138 == (code *)0x0) &&
                               (pcVar12 = (code *)FUN_1802cf0c0(
                                                  "UnityEngine.GameObject::SetActive(System.Boolean)"
                                                  ), pcVar12 == (code *)0x0)) {
                              uVar11 = FUN_1802ced60(
                                                  "UnityEngine.GameObject::SetActive(System.Boolean)"
                                                  );
                    /* WARNING: Subroutine does not return */
                              FUN_1802cca90(uVar11,0);
                            }
                            DAT_182ec1138 = pcVar12;
                            (*DAT_182ec1138)(lVar13,uVar2);
                            plVar4 = *(longlong **)(param_1 + 0x60);
                            lVar13 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
                            if (lVar13 != 0) {
                              dVar23 = *(double *)(lVar13 + 0x1f0);
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
                              uVar11 = FUN_18161e8f0((int)dVar23,&lStack_e8,0,0);
                              uVar11 = System_String__Concat__0600021b(uVar11,DAT_182d5f2b0,0);
                              if (plVar4 != (longlong *)0x0) {
                                (**(code **)(*plVar4 + 0x558))
                                          (plVar4,uVar11,*(undefined8 *)(*plVar4 + 0x560));
                                plVar4 = *(longlong **)(param_1 + 0x70);
                                lVar13 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
                                if (lVar13 != 0) {
                                  uVar3 = *(undefined4 *)(lVar13 + 0x134);
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
                                  uVar11 = FUN_18161e8f0(uVar3,&lStack_e8,0,0);
                                  uVar11 = System_String__Concat__0600021b(uVar11,DAT_182d5f2b0,0);
                                  if (plVar4 != (longlong *)0x0) {
                                    (**(code **)(*plVar4 + 0x558))
                                              (plVar4,uVar11,*(undefined8 *)(*plVar4 + 0x560));
                                    plVar4 = *(longlong **)(param_1 + 0x80);
                                    lVar13 = *(longlong *)
                                              (*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
                                    if (lVar13 != 0) {
                                      uVar3 = *(undefined4 *)(lVar13 + 0x1e8);
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
                                      uVar11 = FUN_18161e8f0(uVar3,&lStack_e8,0,0);
                                      uVar11 = System_String__Concat__0600021b
                                                         (uVar11,uRam0000000182d61a68,0);
                                      if (plVar4 != (longlong *)0x0) {
                                        (**(code **)(*plVar4 + 0x558))
                                                  (plVar4,uVar11,*(undefined8 *)(*plVar4 + 0x560));
                                        plVar4 = *(longlong **)(param_1 + 0xa8);
                                        if ((*(longlong *)(param_1 + 0xd8) != 0) &&
                                           (uVar11 = 
                                                  ExposureUnnoticed2_Scripts_Base_Localizer__Trans__060017af
                                                            (*(undefined8 *)
                                                              (*(longlong *)(param_1 + 0xd8) + 0x20)
                                                             ,0), plVar4 != (longlong *)0x0)) {
                                          (**(code **)(*plVar4 + 0x558))
                                                    (plVar4,uVar11,*(undefined8 *)(*plVar4 + 0x560))
                                          ;
                                          plVar4 = *(longlong **)(param_1 + 0xb0);
                                          if ((*(longlong *)(param_1 + 0xe0) != 0) &&
                                             (uVar11 = 
                                                  ExposureUnnoticed2_Scripts_Base_Localizer__Trans__060017af
                                                            (*(undefined8 *)
                                                              (*(longlong *)(param_1 + 0xe0) + 0x20)
                                                             ,0), plVar4 != (longlong *)0x0)) {
                                            (**(code **)(*plVar4 + 0x558))
                                                      (plVar4,uVar11,
                                                       *(undefined8 *)(*plVar4 + 0x560));
                                            plVar4 = *(longlong **)(param_1 + 0x90);
                                            lVar13 = *(longlong *)
                                                      (*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
                                            if (lVar13 != 0) {
                                              dVar23 = *(double *)(lVar13 + 0x1e0);
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
                                              uVar11 = FUN_18161e8f0((int)dVar23,&lStack_e8,0,0);
                                              uVar11 = System_String__Concat__0600021b
                                                                 (uVar11,DAT_182d5f2b0,0);
                                              if (plVar4 != (longlong *)0x0) {
                                                (**(code **)(*plVar4 + 0x558))
                                                          (plVar4,uVar11,
                                                           *(undefined8 *)(*plVar4 + 0x560));
                                                uVar11 = *(undefined8 *)(param_1 + 0xc0);
                                                if (*(int *)(DAT_182d58288 + 0xe0) == 0) {
                                                  FUN_18035c820();
                                                }
                                                ExposureUnnoticed2_Scripts_Base_ExternalMethodManager__DestroyChildren__0600172c
                                                          (uVar11,0);
                                                if ((*(longlong *)(param_1 + 0xe0) != 0) &&
                                                   (lVar13 = 
                                                  ExposureUnnoticed2_Master_RankRelease_MRankRelease__GetByRank__0600125b
                                                            (*(undefined4 *)
                                                              (*(longlong *)(param_1 + 0xe0) + 0x18)
                                                             ,0), lVar13 != 0)) {
                                                  if (DAT_182eb5d50 != 0) {
                                                    uVar10 = (uint)((ulonglong)&lStack_e8 >> 0xc);
                                                    uVar19 = (ulonglong)((uVar10 & 0x1fffff) >> 6);
                                                    do {
                                                      uVar20 = *(ulonglong *)
                                                                (&DAT_182f0c920 + uVar19 * 8);
                                                      LOCK();
                                                      bVar21 = uVar20 == *(ulonglong *)
                                                                          (&DAT_182f0c920 +
                                                                          uVar19 * 8);
                                                      if (bVar21) {
                                                        *(ulonglong *)(&DAT_182f0c920 + uVar19 * 8)
                                                             = uVar20 | 1L << (uVar10 & 0x3f);
                                                      }
                                                      UNLOCK();
                                                    } while (!bVar21);
                                                  }
                                                  plStack_e0 = (longlong *)
                                                               ((ulonglong)*(uint *)(lVar13 + 0x1c)
                                                               << 0x20);
                                                  uStack_d8 = 0;
                                                  plStack_78 = plStack_e0;
                                                  lStack_70 = 0;
                                                  uStack_c8 = 0;
                                                  plStack_c0 = &lStack_80;
                                                  lStack_e8 = lVar13;
                                                  lStack_80 = lVar13;
                                                  while (cVar7 = FUN_180f72b70(&lStack_80,
                                                                               uRam0000000182d61ae0)
                                                        , lVar13 = lStack_70, cVar7 != '\0') {
                                                    uVar11 = *(undefined8 *)(param_1 + 0xb8);
                                                    uVar15 = *(undefined8 *)(param_1 + 0xc0);
                                                    if (*(int *)(DAT_182d53aa8 + 0xe0) == 0) {
                                                      FUN_18035c820();
                                                    }
                                                    lVar14 = FUN_1809f1050(uVar11,uVar15,
                                                                           DAT_182d54d90);
                                                    if (lVar14 == 0) {
                    /* WARNING: Subroutine does not return */
                                                      FUN_18031dad0();
                                                    }
                                                    lVar14 = FUN_1809a08f0(lVar14,
                                                  uRam0000000182d61ab0);
                                                  if (lVar14 == 0) {
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
                                                  if (lVar13 == 0) {
                    /* WARNING: Subroutine does not return */
                                                    FUN_18031dad0();
                                                  }
                                                  uVar11 = *(undefined8 *)(lVar13 + 0x20);
                                                  plVar4 = *(longlong **)(lVar14 + 0x20);
                                                  uVar15 = 
                                                  ExposureUnnoticed2_Scripts_Base_Localizer__Trans__060017af
                                                            (*(undefined8 *)(lVar13 + 0x30),0);
                                                  if (plVar4 == (longlong *)0x0) {
                    /* WARNING: Subroutine does not return */
                                                    FUN_18031dad0();
                                                  }
                                                  (**(code **)(*plVar4 + 0x558))
                                                            (plVar4,uVar15,
                                                             *(undefined8 *)(*plVar4 + 0x560));
                                                  plVar4 = *(longlong **)(lVar14 + 0x28);
                                                  uVar11 = 
                                                  ExposureUnnoticed2_Scripts_Base_Localizer__Trans__060017af
                                                            (uVar11,0);
                                                  if (plVar4 == (longlong *)0x0) {
                    /* WARNING: Subroutine does not return */
                                                    FUN_18031dad0();
                                                  }
                                                  (**(code **)(*plVar4 + 0x558))
                                                            (plVar4,uVar11,
                                                             *(undefined8 *)(*plVar4 + 0x560));
                                                  }
                                                  uVar11 = *(undefined8 *)(param_1 + 0xa0);
                                                  if (*(int *)(DAT_182d58288 + 0xe0) == 0) {
                                                    FUN_18035c820();
                                                  }
                                                  ExposureUnnoticed2_Scripts_Base_ExternalMethodManager__DestroyChildren__0600172c
                                                            (uVar11,0);
                                                  if ((**(longlong **)(lRam0000000182d5e190 + 0xb8)
                                                       != 0) &&
                                                     (lVar13 = *(longlong *)
                                                                (**(longlong **)
                                                                   (lRam0000000182d5e190 + 0xb8) +
                                                                0x10), lVar13 != 0)) {
                                                    if (DAT_182eb5d50 != 0) {
                                                      uVar10 = (uint)((ulonglong)&lStack_e8 >> 0xc);
                                                      uVar19 = (ulonglong)((uVar10 & 0x1fffff) >> 6)
                                                      ;
                                                      do {
                                                        uVar20 = *(ulonglong *)
                                                                  (&DAT_182f0c920 + uVar19 * 8);
                                                        LOCK();
                                                        bVar21 = uVar20 == *(ulonglong *)
                                                                            (&DAT_182f0c920 +
                                                                            uVar19 * 8);
                                                        if (bVar21) {
                                                          *(ulonglong *)
                                                           (&DAT_182f0c920 + uVar19 * 8) =
                                                               uVar20 | 1L << (uVar10 & 0x3f);
                                                        }
                                                        UNLOCK();
                                                      } while (!bVar21);
                                                    }
                                                    plStack_e0 = (longlong *)
                                                                 ((ulonglong)
                                                                  *(uint *)(lVar13 + 0x1c) << 0x20);
                                                    uStack_d8 = 0;
                                                    lStack_90 = (longlong)plStack_e0;
                                                    lStack_88 = 0;
                                                    lStack_e8 = 0;
                                                    plStack_e0 = &lStack_98;
                                                    lStack_98 = lVar13;
                                                    while (cVar7 = FUN_180f72b70(&lStack_98,
                                                                                                                                                                  
                                                  uRam0000000182d5e158), lVar13 = lStack_88,
                                                  cVar7 != '\0') {
                                                    if (**(longlong **)(DAT_182d53c48 + 0xb8) == 0)
                                                    {
                    /* WARNING: Subroutine does not return */
                                                      FUN_18031dad0();
                                                    }
                                                    lVar14 = *(longlong *)
                                                              (**(longlong **)(DAT_182d53c48 + 0xb8)
                                                              + 0x30);
                                                    if (lVar14 == 0) {
                    /* WARNING: Subroutine does not return */
                                                      FUN_18031dad0();
                                                    }
                                                    lVar14 = *(longlong *)(lVar14 + 0x28);
                                                    if (lStack_88 == 0) {
                    /* WARNING: Subroutine does not return */
                                                      FUN_18031dad0();
                                                    }
                                                    if (*(longlong *)(lStack_88 + 0x28) == 0) {
                    /* WARNING: Subroutine does not return */
                                                      FUN_18031dad0();
                                                    }
                                                    if (lVar14 == 0) {
                    /* WARNING: Subroutine does not return */
                                                      FUN_18031dad0();
                                                    }
                                                    cVar7 = FUN_181101310(lVar14,*(undefined4 *)
                                                                                  (*(longlong *)
                                                                                    (lStack_88 +
                                                                                    0x28) + 0x50),
                                                                          DAT_182d5c070);
                                                    if (cVar7 != '\0') {
                                                      if (*(longlong *)(lVar13 + 0x28) == 0) {
                    /* WARNING: Subroutine does not return */
                                                        FUN_18031dad0();
                                                      }
                                                      uVar3 = *(undefined4 *)
                                                               (*(longlong *)(lVar13 + 0x28) + 0x54)
                                                      ;
                                                      if (*(longlong *)(param_1 + 0xe8) == 0) {
                    /* WARNING: Subroutine does not return */
                                                        FUN_18031dad0();
                                                      }
                                                      cVar7 = FUN_181101310(*(longlong *)
                                                                             (param_1 + 0xe8),uVar3,
                                                                            uRam0000000182d61aa0);
                                                      if (cVar7 == '\0') {
                                                        if (*(longlong *)(param_1 + 0xe8) == 0) {
                    /* WARNING: Subroutine does not return */
                                                          FUN_18031dad0();
                                                        }
                                                        FUN_181108fb0(*(longlong *)(param_1 + 0xe8),
                                                                      uVar3,*(undefined8 *)
                                                                             (*(longlong *)
                                                                               (*(longlong *)
                                                                                 (
                                                  lRam0000000182d61aa8 + 0x20) + 0xc0) + 0xa8));
                                                  uVar11 = *(undefined8 *)(param_1 + 200);
                                                  uVar15 = *(undefined8 *)(param_1 + 0xa0);
                                                  if (*(int *)(DAT_182d53aa8 + 0xe0) == 0) {
                                                    FUN_18035c820();
                                                  }
                                                  lVar14 = FUN_1809f1050(uVar11,uVar15,DAT_182d54d90
                                                                        );
                                                  if (lVar14 == 0) {
                    /* WARNING: Subroutine does not return */
                                                    FUN_18031dad0();
                                                  }
                                                  lVar14 = FUN_1809a08f0(lVar14,uRam0000000182d61ac0
                                                                        );
                                                  if (*(int *)(DAT_182d594e8 + 0xe0) == 0) {
                                                    FUN_18035c820();
                                                  }
                                                  lVar16 = 
                                                  ExposureUnnoticed2_Master_Stage_MStage__Get__06001229
                                                            (uVar3,0);
                                                  if (lVar16 == 0) {
                    /* WARNING: Subroutine does not return */
                                                    FUN_18031dad0();
                                                  }
                                                  uVar11 = 
                                                  ExposureUnnoticed2_Scripts_Base_Localizer__Trans__060017af
                                                            (*(undefined8 *)(lVar16 + 0x28),0);
                                                  if (lVar14 == 0) {
                    /* WARNING: Subroutine does not return */
                                                    FUN_18031dad0();
                                                  }
                                                  ExposureUnnoticed2_ObjectUI_InventoryPanel_EffectBarItemView__Initialize__0600199c
                                                            (lVar14,uVar11,0);
                                                  }
                                                  if (*(longlong *)(lVar13 + 0x28) == 0) {
                    /* WARNING: Subroutine does not return */
                                                    FUN_18031dad0();
                                                  }
                                                  uStack_c8 = 
                                                  ExposureUnnoticed2_Master_Mission_MMissionOverrideRecord__GetMissionName__06001275
                                                            (*(longlong *)(lVar13 + 0x28),0);
                                                  lVar14 = *(longlong *)
                                                            (*(longlong *)(DAT_182d58398 + 0xb8) +
                                                            0x48);
                                                  if (lVar14 == 0) {
                    /* WARNING: Subroutine does not return */
                                                    FUN_18031dad0();
                                                  }
                                                  lVar14 = *(longlong *)(lVar14 + 0x110);
                                                  if (*(longlong *)(lVar13 + 0x28) == 0) {
                    /* WARNING: Subroutine does not return */
                                                    FUN_18031dad0();
                                                  }
                                                  if (lVar14 == 0) {
                    /* WARNING: Subroutine does not return */
                                                    FUN_18031dad0();
                                                  }
                                                  fVar22 = (float)FUN_180005b40(lVar14,*(undefined4
                                                                                         *)(*(
                                                  longlong *)(lVar13 + 0x28) + 0x50));
                                                  uStackX_18._0_4_ = (int)fVar22;
                                                  uVar11 = FUN_181618010(&uStackX_18,0);
                                                  uStackX_20 = System_String__Concat__0600021b
                                                                         (uVar11,DAT_182d5f2b0,0);
                                                  if (**(longlong **)(DAT_182d53c48 + 0xb8) == 0) {
                    /* WARNING: Subroutine does not return */
                                                    FUN_18031dad0();
                                                  }
                                                  lVar14 = *(longlong *)
                                                            (**(longlong **)(DAT_182d53c48 + 0xb8) +
                                                            0x30);
                                                  if (lVar14 == 0) {
                    /* WARNING: Subroutine does not return */
                                                    FUN_18031dad0();
                                                  }
                                                  lVar14 = *(longlong *)(lVar14 + 0x30);
                                                  if (*(longlong *)(lVar13 + 0x28) == 0) {
                    /* WARNING: Subroutine does not return */
                                                    FUN_18031dad0();
                                                  }
                                                  if (lVar14 == 0) {
                    /* WARNING: Subroutine does not return */
                                                    FUN_18031dad0();
                                                  }
                                                  iVar8 = FUN_180006390(lVar14,*(undefined4 *)
                                                                                (*(longlong *)
                                                                                  (lVar13 + 0x28) +
                                                                                0x50));
                                                  uStackX_18 = CONCAT44(uStackX_18._4_4_,
                                                                        (float)iVar8 * 0.01);
                                                  uVar11 = FUN_1802c3ff0(DAT_182d53cd0,&uStackX_18);
                                                  uStackX_18 = System_String__Format__0600021f
                                                                         (uRam0000000182d61a70,
                                                                          uVar11,0);
                                                  lVar14 = *(longlong *)
                                                            (*(longlong *)(DAT_182d58398 + 0xb8) +
                                                            0x48);
                                                  if (lVar14 == 0) {
                    /* WARNING: Subroutine does not return */
                                                    FUN_18031dad0();
                                                  }
                                                  lVar14 = *(longlong *)(lVar14 + 0x118);
                                                  if (*(longlong *)(lVar13 + 0x28) == 0) {
                    /* WARNING: Subroutine does not return */
                                                    FUN_18031dad0();
                                                  }
                                                  if (lVar14 == 0) {
                    /* WARNING: Subroutine does not return */
                                                    FUN_18031dad0();
                                                  }
                                                  iVar8 = FUN_180006390(lVar14,*(undefined4 *)
                                                                                (*(longlong *)
                                                                                  (lVar13 + 0x28) +
                                                                                0x50));
                                                  if (**(longlong **)(DAT_182d53c48 + 0xb8) == 0) {
                    /* WARNING: Subroutine does not return */
                                                    FUN_18031dad0();
                                                  }
                                                  lVar14 = *(longlong *)
                                                            (**(longlong **)(DAT_182d53c48 + 0xb8) +
                                                            0x30);
                                                  if (lVar14 == 0) {
                    /* WARNING: Subroutine does not return */
                                                    FUN_18031dad0();
                                                  }
                                                  lVar14 = *(longlong *)(lVar14 + 0x30);
                                                  if (*(longlong *)(lVar13 + 0x28) == 0) {
                    /* WARNING: Subroutine does not return */
                                                    FUN_18031dad0();
                                                  }
                                                  if (lVar14 == 0) {
                    /* WARNING: Subroutine does not return */
                                                    FUN_18031dad0();
                                                  }
                                                  iVar9 = FUN_180006390(lVar14,*(undefined4 *)
                                                                                (*(longlong *)
                                                                                  (lVar13 + 0x28) +
                                                                                0x50));
                                                  uVar11 = *(undefined8 *)(param_1 + 0x98);
                                                  uVar15 = *(undefined8 *)(param_1 + 0xa0);
                                                  if (*(int *)(DAT_182d53aa8 + 0xe0) == 0) {
                                                    FUN_18035c820();
                                                  }
                                                  lVar14 = FUN_1809f1050(uVar11,uVar15,DAT_182d54d90
                                                                        );
                                                  if (lVar14 == 0) {
                    /* WARNING: Subroutine does not return */
                                                    FUN_18031dad0();
                                                  }
                                                  lVar14 = FUN_1809a08f0(lVar14,uRam0000000182d61ab8
                                                                        );
                                                  if (lVar14 == 0) {
                    /* WARNING: Subroutine does not return */
                                                    FUN_18031dad0();
                                                  }
                                                  in_stack_ffffffffffffff08 =
                                                       CONCAT71((int7)(in_stack_ffffffffffffff08 >>
                                                                      8),iVar8 < iVar9);
                                                  ExposureUnnoticed2_ObjectUI_ResultPanel_CompletedMissionItem__Initialize__0600184c
                                                            (lVar14,uStack_c8,uStackX_20,uStackX_18,
                                                             in_stack_ffffffffffffff08,0);
                                                  if (*(longlong *)(lVar13 + 0x28) == 0) {
                    /* WARNING: Subroutine does not return */
                                                    FUN_18031dad0();
                                                  }
                                                  ExposureUnnoticed2_Scripts_InGame_GameStateFacade__AchieveMission__06001559
                                                            (*(undefined4 *)
                                                              (*(longlong *)(lVar13 + 0x28) + 0x50),
                                                             0);
                                                  lVar13 = *(longlong *)
                                                            (*(longlong *)(DAT_182d58398 + 0xb8) +
                                                            0x48);
                                                  if (lVar13 == 0) {
                    /* WARNING: Subroutine does not return */
                                                    FUN_18031dad0();
                                                  }
                                                  piVar1 = (int *)(lVar13 + 0x158);
                                                  *piVar1 = *piVar1 + 1;
                                                  }
                                                  }
                                                  lVar13 = *(longlong *)
                                                            (*(longlong *)(DAT_182d58398 + 0xb8) +
                                                            0x48);
                                                  if (lVar13 != 0) {
                                                    if (0.0 < *(float *)(lVar13 + 0x120)) {
                                                      uVar11 = 
                                                  ExposureUnnoticed2_Scripts_Base_Localizer__Trans__060017af
                                                            (uRam0000000182d61a60,0);
                                                  lVar13 = *(longlong *)
                                                            (*(longlong *)(DAT_182d58398 + 0xb8) +
                                                            0x48);
                                                  if (lVar13 == 0) goto code_r0x0001804c8186;
                                                  fVar22 = *(float *)(lVar13 + 0x120);
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
                                                  uVar15 = FUN_18161e8f0((int)fVar22,&lStack_e8,0,0)
                                                  ;
                                                  uVar17 = System_String__Concat__0600021b
                                                                     (uVar15,DAT_182d5f2b0,0);
                                                  uVar15 = *(undefined8 *)(param_1 + 0x98);
                                                  uVar5 = *(undefined8 *)(param_1 + 0xa0);
                                                  if (*(int *)(DAT_182d53aa8 + 0xe0) == 0) {
                                                    FUN_18035c820();
                                                  }
                                                  lVar13 = FUN_1809f1050(uVar15,uVar5,DAT_182d54d90)
                                                  ;
                                                  if ((lVar13 == 0) ||
                                                     (lVar13 = FUN_1809a08f0(lVar13,
                                                  uRam0000000182d61ab8), lVar13 == 0))
                                                  goto code_r0x0001804c8186;
                                                  ExposureUnnoticed2_ObjectUI_ResultPanel_CompletedMissionItem__Initialize__0600184c
                                                            (lVar13,uVar11,uVar17,DAT_182d52e20,
                                                             in_stack_ffffffffffffff08 &
                                                             0xffffffffffffff00,0);
                                                  }
                                                  if (**(longlong **)(lRam0000000182d5e190 + 0xb8)
                                                      != 0) {
                                                                                                        
                                                  ExposureUnnoticed2_Scripts_Mission_MissionManager__ResetMission__0600146a
                                                            (**(longlong **)
                                                               (lRam0000000182d5e190 + 0xb8),0);
                                                  lVar13 = *(longlong *)
                                                            (*(longlong *)(DAT_182d58398 + 0xb8) +
                                                            0x48);
                                                  if (lVar13 != 0) {
                                                    *(undefined8 *)(lVar13 + 0x1f0) = 0;
                                                    if ((**(longlong **)(DAT_182d53c48 + 0xb8) != 0)
                                                       && (lVar13 = *(longlong *)
                                                                     (**(longlong **)
                                                                        (DAT_182d53c48 + 0xb8) +
                                                                     0x30), lVar13 != 0)) {
                                                      *(undefined4 *)(lVar13 + 0x48) = 0;
                                                      lVar13 = *(longlong *)
                                                                (*(longlong *)(DAT_182d58398 + 0xb8)
                                                                + 0x48);
                                                      if (lVar13 != 0) {
                                                        *(undefined4 *)(lVar13 + 0x120) = 0;
                                                        if (((**(longlong **)(DAT_182d53c48 + 0xb8)
                                                              != 0) &&
                                                            (lVar13 = *(longlong *)
                                                                       (**(longlong **)
                                                                          (DAT_182d53c48 + 0xb8) +
                                                                       0x30), lVar13 != 0)) &&
                                                           (lVar13 = *(longlong *)(lVar13 + 0x28),
                                                           lVar13 != 0)) {
                                                          if (0 < *(int *)(lVar13 + 0x24)) {
                                                            FUN_181646f50(*(undefined8 *)
                                                                           (lVar13 + 0x18),0,
                                                                          *(undefined4 *)
                                                                           (lVar13 + 0x24),0);
                                                            if (*(longlong *)(lVar13 + 0x10) == 0)
                                                            goto code_r0x0001804c8186;
                                                            FUN_181646f50(*(undefined8 *)
                                                                           (lVar13 + 0x10),0,
                                                                          *(undefined4 *)
                                                                           (*(longlong *)
                                                                             (lVar13 + 0x10) + 0x18)
                                                                          ,0);
                                                            *(undefined8 *)(lVar13 + 0x20) = 0;
                                                            *(undefined4 *)(lVar13 + 0x28) =
                                                                 0xffffffff;
                                                          }
                                                          *(int *)(lVar13 + 0x38) =
                                                               *(int *)(lVar13 + 0x38) + 1;
                                                          if ((**(longlong **)(DAT_182d53c48 + 0xb8)
                                                               != 0) &&
                                                             (lVar13 = *(longlong *)
                                                                        (**(longlong **)
                                                                           (DAT_182d53c48 + 0xb8) +
                                                                        0x30), lVar13 != 0)) {
                                                            *(undefined1 *)(lVar13 + 0x38) = 0;
                                                            if ((**(longlong **)
                                                                   (DAT_182d53c48 + 0xb8) != 0) &&
                                                               ((lVar13 = *(longlong *)
                                                                           (**(longlong **)
                                                                              (DAT_182d53c48 + 0xb8)
                                                                           + 0x30), lVar13 != 0 &&
                                                                (lVar13 = *(longlong *)
                                                                           (lVar13 + 0x30),
                                                                lVar13 != 0)))) {
                                                              if (DAT_182eb5d50 != 0) {
                                                                uVar10 = (uint)((ulonglong)
                                                                                &lStack_e8 >> 0xc);
                                                                uVar19 = (ulonglong)
                                                                         ((uVar10 & 0x1fffff) >> 6);
                                                                do {
                                                                  uVar20 = *(ulonglong *)
                                                                            (&DAT_182f0c920 +
                                                                            uVar19 * 8);
                                                                  LOCK();
                                                                  bVar21 = uVar20 == *(ulonglong *)
                                                                                      (&
                                                  DAT_182f0c920 + uVar19 * 8);
                                                  if (bVar21) {
                                                    *(ulonglong *)(&DAT_182f0c920 + uVar19 * 8) =
                                                         uVar20 | 1L << (uVar10 & 0x3f);
                                                  }
                                                  UNLOCK();
                                                  } while (!bVar21);
                                                  }
                                                  plStack_e0 = (longlong *)
                                                               (ulonglong)*(uint *)(lVar13 + 0x2c);
                                                  uStack_d0 = 2;
                                                  uStack_d8 = 0;
                                                  uStack_b0 = (ulonglong)plStack_e0;
                                                  uStack_a8 = 0;
                                                  uStack_a0 = 2;
                                                  lStack_e8 = 0;
                                                  plStack_e0 = &lStack_b8;
                                                  lStack_b8 = lVar13;
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
                                                    uVar10 = uStack_b0._4_4_;
                                                    do {
                                                      if (lStack_b8 == 0) {
                    /* WARNING: Subroutine does not return */
                                                        FUN_18031dad0();
                                                      }
                                                      if (*(uint *)(lStack_b8 + 0x20) <= uVar10) {
                                                        uStack_b0 = CONCAT44(*(int *)(lStack_b8 +
                                                                                     0x20) + 1,
                                                                             (int)uStack_b0);
                                                        uStack_a8 = 0;
                                                        if (((**(longlong **)(DAT_182d53c48 + 0xb8)
                                                              == 0) ||
                                                            (lVar13 = *(longlong *)
                                                                       (**(longlong **)
                                                                          (DAT_182d53c48 + 0xb8) +
                                                                       0x30), lVar13 == 0)) ||
                                                           (*(longlong *)(lVar13 + 0x30) == 0))
                                                        goto code_r0x0001804c8186;
                                                        FUN_180004490();
                                                        if (((**(longlong **)(DAT_182d53c48 + 0xb8)
                                                              == 0) ||
                                                            (lVar13 = *(longlong *)
                                                                       (**(longlong **)
                                                                          (DAT_182d53c48 + 0xb8) +
                                                                       0x30), lVar13 == 0)) ||
                                                           (lVar13 = *(longlong *)(lVar13 + 0x40),
                                                           lVar13 == 0)) goto code_r0x0001804c8186;
                                                        iVar8 = *(int *)(lVar13 + 0x20);
                                                        if (0 < iVar8) {
                                                          if (*(longlong *)(lVar13 + 0x10) == 0)
                                                          goto code_r0x0001804c8186;
                                                          FUN_181646f50(*(undefined8 *)
                                                                         (lVar13 + 0x10),0,
                                                                        *(undefined4 *)
                                                                         (*(longlong *)
                                                                           (lVar13 + 0x10) + 0x18),0
                                                                       );
                                                          *(undefined4 *)(lVar13 + 0x20) = 0;
                                                          *(undefined4 *)(lVar13 + 0x24) =
                                                               0xffffffff;
                                                          *(undefined4 *)(lVar13 + 0x28) = 0;
                                                          FUN_181646f50(*(undefined8 *)
                                                                         (lVar13 + 0x18),0,iVar8,0);
                                                        }
                                                        *(int *)(lVar13 + 0x2c) =
                                                             *(int *)(lVar13 + 0x2c) + 1;
                                                        if (*(int *)(uRam0000000182d61a78 + 0xe0) ==
                                                            0) {
                                                          FUN_18035c820();
                                                        }
                                                        uVar19 = *(ulonglong *)
                                                                  (uRam0000000182d61a78 + 0xb8);
                                                        lVar13 = *(longlong *)(uVar19 + 0x10);
                                                        if (lVar13 == 0) {
                                                          if (*(int *)(uRam0000000182d61a78 + 0xe0)
                                                              == 0) {
                                                            FUN_18035c820();
                                                          }
                                                          lVar14 = **(longlong **)
                                                                     (uRam0000000182d61a78 + 0xb8);
                                                          lVar13 = FUN_1802c43a0(DAT_182d58368);
                                                          lVar16 = lRam0000000182d61a80;
                                                          *(undefined8 *)(lVar13 + 0x10) =
                                                               *(undefined8 *)
                                                                (lRam0000000182d61a80 + 8);
                                                          *(longlong *)(lVar13 + 0x28) = lVar16;
                                                          *(longlong *)(lVar13 + 0x20) = lVar14;
                                                          if (DAT_182eb5d50 != 0) {
                                                            uVar10 = (uint)(lVar13 + 0x20U >> 0xc);
                                                            uVar19 = (ulonglong)
                                                                     ((uVar10 & 0x1fffff) >> 6);
                                                            do {
                                                              uVar20 = *(ulonglong *)
                                                                        (&DAT_182f0c920 + uVar19 * 8
                                                                        );
                                                              LOCK();
                                                              bVar21 = uVar20 == *(ulonglong *)
                                                                                  (&DAT_182f0c920 +
                                                                                  uVar19 * 8);
                                                              if (bVar21) {
                                                                *(ulonglong *)
                                                                 (&DAT_182f0c920 + uVar19 * 8) =
                                                                     uVar20 | 1L << (uVar10 & 0x3f);
                                                              }
                                                              UNLOCK();
                                                            } while (!bVar21);
                                                          }
                                                          cVar7 = *(char *)(lVar16 + 0x52);
                                                          *(longlong *)(lVar13 + 0x40) = lVar13;
                                                          if ((*(byte *)(lVar16 + 0x4c) & 0x10) == 0
                                                             ) {
                                                            if (lVar14 == 0) {
                                                              uVar11 = FUN_18031daf0();
                    /* WARNING: Subroutine does not return */
                                                              FUN_18031da90(uVar11,0);
                                                            }
code_r0x0001804c8097:
                                                            *(undefined8 *)(lVar13 + 0x40) =
                                                                 *(undefined8 *)(lVar13 + 0x20);
                                                            puVar18 = *(undefined1 **)
                                                                       (lVar13 + 0x10);
                                                          }
                                                          else {
                                                            if (cVar7 != '\0')
                                                            goto code_r0x0001804c8097;
                                                            puVar18 = &LAB_1800c7840;
                                                          }
                                                          *(undefined1 **)(lVar13 + 0x18) = puVar18;
                                                          *(code **)(lVar13 + 0x38) = FUN_1801e91e0;
                                                          uVar19 = uRam0000000182d61a78;
                                                          *(longlong *)
                                                           (*(longlong *)
                                                             (uRam0000000182d61a78 + 0xb8) + 0x10) =
                                                               lVar13;
                                                          if (DAT_182eb5d50 != 0) {
                                                            uVar10 = (uint)(*(longlong *)
                                                                             (uRam0000000182d61a78 +
                                                                             0xb8) + 0x10U >> 0xc);
                                                            uVar20 = (ulonglong)
                                                                     ((uVar10 & 0x1fffff) >> 6);
                                                            do {
                                                              uVar6 = *(ulonglong *)
                                                                       (&DAT_182f0c920 + uVar20 * 8)
                                                              ;
                                                              LOCK();
                                                              uVar19 = *(ulonglong *)
                                                                        (&DAT_182f0c920 + uVar20 * 8
                                                                        );
                                                              bVar21 = uVar6 == uVar19;
                                                              if (bVar21) {
                                                                *(ulonglong *)
                                                                 (&DAT_182f0c920 + uVar20 * 8) =
                                                                     uVar6 | 1L << (uVar10 & 0x3f);
                                                                uVar19 = uVar6;
                                                              }
                                                              UNLOCK();
                                                            } while (!bVar21);
                                                          }
                                                        }
                                                        if (param_1 != 0) {
                                                          *(longlong *)(param_1 + 0x30) = lVar13;
                                                          if (DAT_182eb5d50 != 0) {
                                                            uVar10 = (uint)(param_1 + 0x30U >> 0xc);
                                                            uVar20 = (ulonglong)
                                                                     ((uVar10 & 0x1fffff) >> 6);
                                                            do {
                                                              uVar6 = *(ulonglong *)
                                                                       (&DAT_182f0c920 + uVar20 * 8)
                                                              ;
                                                              LOCK();
                                                              uVar19 = *(ulonglong *)
                                                                        (&DAT_182f0c920 + uVar20 * 8
                                                                        );
                                                              bVar21 = uVar6 == uVar19;
                                                              if (bVar21) {
                                                                *(ulonglong *)
                                                                 (&DAT_182f0c920 + uVar20 * 8) =
                                                                     uVar6 | 1L << (uVar10 & 0x3f);
                                                                uVar19 = uVar6;
                                                              }
                                                              UNLOCK();
                                                            } while (!bVar21);
                                                          }
                                                          return uVar19;
                                                        }
                                                        goto code_r0x0001804c8186;
                                                      }
                                                      lVar13 = *(longlong *)(lStack_b8 + 0x18);
                                                      lVar14 = (longlong)(int)uVar10;
                                                      uStack_b0 = CONCAT44(uVar10 + 1,(int)uStack_b0
                                                                          );
                                                      if (lVar13 == 0) {
                    /* WARNING: Subroutine does not return */
                                                        FUN_18031dad0();
                                                      }
                                                      if (*(uint *)(lVar13 + 0x18) <= uVar10) {
                    /* WARNING: Subroutine does not return */
                                                        FUN_18031dae0();
                                                      }
                                                      lVar16 = lVar14 + 2;
                                                      uVar10 = uVar10 + 1;
                                                    } while (*(int *)(lVar13 + (lVar14 + 2) * 0x10)
                                                             < 0);
                                                    uVar3 = *(undefined4 *)
                                                             (lVar13 + 8 + lVar16 * 0x10);
                                                    iVar8 = *(int *)(lVar13 + 0xc + lVar16 * 0x10);
                                                    uStackX_18 = 0;
                                                    if ((*(byte *)(*(longlong *)
                                                                    (lRam0000000182d61ad8 + 0x20) +
                                                                  0x135) & 1) == 0) {
                                                      FUN_180320470();
                                                    }
                                                    lVar14 = DAT_182d5db50;
                                                    uStackX_18 = CONCAT44(iVar8,uVar3);
                                                    uStack_a8 = uStackX_18;
                                                    lVar13 = *(longlong *)
                                                              (*(longlong *)(DAT_182d58398 + 0xb8) +
                                                              0x48);
                                                    if (lVar13 == 0) {
                    /* WARNING: Subroutine does not return */
                                                      FUN_18031dad0();
                                                    }
                                                    uStackX_18 = *(undefined8 *)(lVar13 + 0x118);
                                                    lVar13 = *(longlong *)
                                                              (*(longlong *)
                                                                (*(longlong *)(DAT_182d58398 + 0xb8)
                                                                + 0x48) + 0x118);
                                                    if (lVar13 == 0) {
                    /* WARNING: Subroutine does not return */
                                                      FUN_18031dad0();
                                                    }
                                                    uVar10 = FUN_180e44350(lVar13,uVar3,
                                                                           *(undefined8 *)
                                                                            (*(longlong *)
                                                                              (*(longlong *)
                                                                                (DAT_182d5db50 +
                                                                                0x20) + 0xc0) + 0xf8
                                                                            ));
                                                    if ((int)uVar10 < 0) {
                                                      uStackX_18 = CONCAT44(uStackX_18._4_4_,uVar3);
                                                      uVar11 = FUN_180003850(*(undefined8 *)
                                                                              (*(longlong *)
                                                                                (lVar14 + 0x20) +
                                                                              0xc0),0xe);
                                                      uVar11 = il2cpp_value_box(uVar11,&uStackX_18);
                    /* WARNING: Subroutine does not return */
                                                      FUN_181640310(uVar11,0);
                                                    }
                                                    lVar13 = *(longlong *)(lVar13 + 0x18);
                                                    if (lVar13 == 0) {
                    /* WARNING: Subroutine does not return */
                                                      FUN_18031dad0();
                                                    }
                                                    if (*(uint *)(lVar13 + 0x18) <= uVar10) {
                    /* WARNING: Subroutine does not return */
                                                      FUN_18031dae0();
                                                    }
                                                    iVar9 = *(int *)(lVar13 + 0x2c +
                                                                    (longlong)(int)uVar10 * 0x10);
                                                    if (iVar9 <= iVar8) {
                                                      iVar9 = iVar8;
                                                    }
                                                    FUN_180e4d6f0(uStackX_18,uVar3,iVar9,
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

