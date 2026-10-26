// Ghidra pseudocode; not original source or compilable C.
// ev_bf4736580e4f1e849280970a558277d21c5fa56b738041139e7b062659f4e7c5

void ExposureUnnoticed2_Scripts_Mission_MissionBase__Update__06001422(longlong *param_1)

{
  longlong lVar1;
  char cVar2;
  char cVar3;
  int iVar4;
  longlong *plVar5;
  longlong lVar6;
  int iVar7;
  float fVar8;
  undefined4 uVar9;
  float fVar10;
  undefined8 uVar11;
  undefined8 extraout_XMM0_Qb;
  undefined1 auVar12 [16];
  undefined1 auVar13 [16];
  float fVar14;
  float fVar15;
  
  if (cRam0000000182eb78fb == '\0') {
    FUN_1802f2810(&DAT_182d59ac8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5e250);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5e248);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d5e240);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5e238);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5e230);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5e228);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d58398);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d5e220);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d53c48);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d58380);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d58378);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5e260);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d5bfa0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d5aa70);
    LOCK();
    UNLOCK();
    cRam0000000182eb78fb = '\x01';
  }
  if ((**(longlong **)(DAT_182d53c48 + 0xb8) != 0) &&
     (lVar6 = *(longlong *)(**(longlong **)(DAT_182d53c48 + 0xb8) + 0x30), lVar6 != 0)) {
    if (*(char *)(lVar6 + 0x11) != '\0') {
      return;
    }
    lVar6 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
    if (lVar6 != 0) {
      if (*(int *)(lVar6 + 0x10) == 0) {
        return;
      }
      if (*(char *)(*(longlong *)(**(longlong **)(DAT_182d53c48 + 0xb8) + 0x30) + 0x13) != '\0') {
        return;
      }
      if (*(int *)(DAT_182d58380 + 0xe0) == 0) {
        FUN_18035c820(DAT_182d58380);
      }
      if (**(longlong **)(DAT_182d58380 + 0xb8) != 0) {
        if (*(char *)(**(longlong **)(DAT_182d58380 + 0xb8) + 0x20) != '\0') {
          return;
        }
        cVar2 = FUN_180436670();
        if (cVar2 != '\0') {
          return;
        }
        if ((((param_1[5] != 0) && (**(longlong **)(DAT_182d58378 + 0xb8) != 0)) &&
            (lVar6 = *(longlong *)(**(longlong **)(DAT_182d58378 + 0xb8) + 0x40), lVar6 != 0)) &&
           ((lVar6 = *(longlong *)(lVar6 + 0x60), lVar6 != 0 &&
            (lVar6 = *(longlong *)(lVar6 + 0x128), lVar6 != 0)))) {
          if (*(int *)(lVar6 + 0x18) < *(int *)(param_1[5] + 0x2c)) {
            return;
          }
          lVar6 = **(longlong **)(lRam0000000182d5e260 + 0xb8);
          if (lVar6 != 0) {
            if (((*(char *)(lVar6 + 0x10) != '\0') &&
                (plVar5 = (longlong *)
                          ExposureUnnoticed2_Scripts_InGame_RandomMissionManager__get_CurrentMission__060015ea
                                    (lVar6,0), plVar5 != param_1)) &&
               (*(float *)(param_1 + 6) < 1.0)) {
              return;
            }
            if (*(int *)(DAT_182d5bfa0 + 0xe0) == 0) {
              FUN_18035c820(DAT_182d5bfa0);
            }
            if (**(char **)(DAT_182d5bfa0 + 0xb8) != '\0') {
              if (param_1[5] == 0) goto code_r0x0001804796e7;
              if (*(char *)(param_1[5] + 0x48) == '\0') {
                return;
              }
            }
            if ((**(longlong **)(DAT_182d53c48 + 0xb8) != 0) &&
               (lVar6 = *(longlong *)(**(longlong **)(DAT_182d53c48 + 0xb8) + 0x30), lVar6 != 0)) {
              cVar2 = *(char *)(lVar6 + 0x14);
              lVar6 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
              if ((lVar6 != 0) && (param_1[5] != 0)) {
                if (((*(int *)(lVar6 + 0x10) == *(int *)(param_1[5] + 0x54)) &&
                    (cVar3 = (**(code **)(*param_1 + 0x1d8))
                                       (param_1,*(undefined8 *)(*param_1 + 0x1e0)), cVar3 != '\0'))
                   && (cVar2 == '\0')) {
                  if (((**(longlong **)(DAT_182d53c48 + 0xb8) != 0) &&
                      (lVar6 = *(longlong *)(**(longlong **)(DAT_182d53c48 + 0xb8) + 0x28),
                      lVar6 != 0)) &&
                     ((lVar6 = *(longlong *)(lVar6 + 0x30), lVar6 != 0 &&
                      ((lVar6 = *(longlong *)(lVar6 + 0x40), lVar6 != 0 &&
                       (lVar6 = *(longlong *)(lVar6 + 0x60), lVar6 != 0)))))) {
                    fVar14 = *(float *)(lVar6 + 0xe8);
                    if (param_1[5] != 0) {
                      if ((*(float *)(param_1[5] + 0x34) <= 0.0) ||
                         (cVar2 = ExposureUnnoticed2_Scripts_InGame_GameStateFacade__IsActivePassiveSkill__06001525
                                            (5,0), cVar2 == '\0')) {
                        if (param_1[5] == 0) goto code_r0x0001804796e7;
                        fVar8 = *(float *)(param_1[5] + 0x30);
                      }
                      else {
                        if (param_1[5] == 0) goto code_r0x0001804796e7;
                        fVar8 = *(float *)(param_1[5] + 0x34);
                      }
                      if (fVar8 <= 1.0) {
                        lVar6 = ExposureUnnoticed2_Master_Common_MCommon__get_Instance__0600133e(0);
                        if (lVar6 == 0) goto code_r0x0001804796e7;
                        fVar15 = *(float *)(lVar6 + 0x1ac);
                      }
                      else {
                        fVar15 = 0.05;
                      }
                      fVar15 = fVar15 * fVar8;
                      if ((param_1[5] != 0) &&
                         (lVar6 = *(longlong *)(param_1[5] + 0x20), lVar6 != 0)) {
                        if (*(char *)(lVar6 + 0x2c) == '\0') {
                          fVar8 = (float)FUN_181f47ce0(0);
                        }
                        else {
                          fVar8 = (float)(**(code **)(*param_1 + 0x1e8))
                                                   (param_1,*(undefined8 *)(*param_1 + 0x1f0));
                          if (param_1[5] == 0) goto code_r0x0001804796e7;
                          fVar15 = *(float *)(param_1[5] + 0x30);
                        }
                        if (*(int *)(DAT_182d59ac8 + 0xe0) == 0) {
                          FUN_18035c820(DAT_182d59ac8);
                        }
                        fVar8 = fVar15 * fVar8 * *(float *)(*(longlong *)(DAT_182d59ac8 + 0xb8) + 4)
                        ;
                        if ((param_1[5] != 0) &&
                           (lVar6 = *(longlong *)(param_1[5] + 0x20), lVar6 != 0)) {
                          if (*(char *)(lVar6 + 0x2c) == '\0') {
                            if (((**(longlong **)(DAT_182d58378 + 0xb8) == 0) ||
                                (lVar6 = *(longlong *)(**(longlong **)(DAT_182d58378 + 0xb8) + 0x40)
                                , lVar6 == 0)) || (lVar6 = *(longlong *)(lVar6 + 0x60), lVar6 == 0))
                            goto code_r0x0001804796e7;
                            iVar7 = *(int *)(lVar6 + 0xcc) + 100;
                            iVar4 = 0;
                            if (-1 < iVar7) {
                              iVar4 = iVar7;
                            }
                            fVar8 = (float)iVar4 * 0.01 * fVar8;
                          }
                          if (1.0 <= *(float *)(param_1 + 6)) {
                            if (*(char *)((longlong)param_1 + 0x3d) == '\0') {
                              *(undefined1 *)((longlong)param_1 + 0x3d) = 1;
                              if (**(longlong **)(DAT_182d5aa70 + 0xb8) == 0)
                              goto code_r0x0001804796e7;
                              ExposureUnnoticed2_Scripts_Sound_UiSoundPlayer__PlayOneShotAudioData__06001404
                                        (**(longlong **)(DAT_182d5aa70 + 0xb8),0x61,0xbf800000,0,0);
                              if ((param_1[5] == 0) ||
                                 (lVar6 = *(longlong *)(param_1[5] + 0x20), lVar6 == 0))
                              goto code_r0x0001804796e7;
                              if (*(int *)(lVar6 + 0x28) == 1) {
                                ExposureUnnoticed2_Scripts_Mission_MissionBase__RiseRp__06001423
                                          (param_1,(float)*(int *)(param_1[5] + 0x28) * fVar14,0);
                                if (((**(longlong **)(DAT_182d53c48 + 0xb8) == 0) ||
                                    (lVar6 = *(longlong *)
                                              (**(longlong **)(DAT_182d53c48 + 0xb8) + 0x30),
                                    lVar6 == 0)) ||
                                   ((param_1[5] == 0 ||
                                    (lVar6 = *(longlong *)(lVar6 + 0x30), lVar6 == 0))))
                                goto code_r0x0001804796e7;
                                FUN_180e4d6f0(lVar6,*(undefined4 *)(param_1[5] + 0x50),0,0,
                                              *(undefined8 *)
                                               (*(longlong *)
                                                 (*(longlong *)(lRam0000000182d5e248 + 0x20) + 0xc0)
                                               + 0x100));
                                if ((((((**(longlong **)(DAT_182d53c48 + 0xb8) == 0) ||
                                       (lVar6 = *(longlong *)
                                                 (**(longlong **)(DAT_182d53c48 + 0xb8) + 0x30),
                                       lVar6 == 0)) || (param_1[5] == 0)) ||
                                     ((**(longlong **)(DAT_182d58378 + 0xb8) == 0 ||
                                      (lVar1 = *(longlong *)
                                                (**(longlong **)(DAT_182d58378 + 0xb8) + 0x40),
                                      lVar1 == 0)))) ||
                                    (lVar1 = *(longlong *)(lVar1 + 0x60), lVar1 == 0)) ||
                                   (lVar6 = *(longlong *)(lVar6 + 0x30), lVar6 == 0))
                                goto code_r0x0001804796e7;
                                FUN_180e4d6f0(lVar6,*(undefined4 *)(param_1[5] + 0x50),
                                              (int)*(float *)(lVar1 + 0xec),
                                              CONCAT71((int7)((ulonglong)lVar1 >> 8),1),
                                              *(undefined8 *)
                                               (*(longlong *)
                                                 (*(longlong *)(lRam0000000182d5e238 + 0x20) + 0xc0)
                                               + 0x100));
                                if (((**(longlong **)(DAT_182d53c48 + 0xb8) == 0) ||
                                    (lVar6 = *(longlong *)
                                              (**(longlong **)(DAT_182d53c48 + 0xb8) + 0x30),
                                    lVar6 == 0)) ||
                                   ((param_1[5] == 0 ||
                                    (lVar6 = *(longlong *)(lVar6 + 0x28), lVar6 == 0))))
                                goto code_r0x0001804796e7;
                                FUN_181104300(lVar6,*(undefined4 *)(param_1[5] + 0x50),
                                              *(undefined8 *)
                                               (*(longlong *)
                                                 (*(longlong *)(DAT_182d5e220 + 0x20) + 0xc0) + 0xa8
                                               ));
                                if ((((**(longlong **)(DAT_182d53c48 + 0xb8) == 0) ||
                                     (lVar6 = *(longlong *)
                                               (**(longlong **)(DAT_182d53c48 + 0xb8) + 0x30),
                                     lVar6 == 0)) || (param_1[5] == 0)) ||
                                   (lVar6 = *(longlong *)(lVar6 + 0x40), lVar6 == 0))
                                goto code_r0x0001804796e7;
                                FUN_180e72490(lVar6,*(undefined4 *)(param_1[5] + 0x54),0,0,
                                              *(undefined8 *)
                                               (*(longlong *)
                                                 (*(longlong *)(lRam0000000182d5e250 + 0x20) + 0xc0)
                                               + 0x100));
                                if (((**(longlong **)(DAT_182d53c48 + 0xb8) == 0) ||
                                    (lVar6 = *(longlong *)
                                              (**(longlong **)(DAT_182d53c48 + 0xb8) + 0x30),
                                    lVar6 == 0)) ||
                                   ((param_1[5] == 0 ||
                                    (lVar6 = *(longlong *)(lVar6 + 0x40), lVar6 == 0))))
                                goto code_r0x0001804796e7;
                                uVar9 = *(undefined4 *)(param_1[5] + 0x54);
                                iVar4 = FUN_180e71cd0(lVar6,uVar9,DAT_182d5e240);
                                FUN_180e72490(lVar6,uVar9,iVar4 + 1,
                                              CONCAT71((int7)((ulonglong)
                                                              *(longlong *)
                                                               (lRam0000000182d5e228 + 0x20) >> 8),1
                                                      ),
                                              *(undefined8 *)
                                               (*(longlong *)
                                                 (*(longlong *)(lRam0000000182d5e228 + 0x20) + 0xc0)
                                               + 0x100));
                              }
                              *(float *)((longlong)param_1 + 0x34) =
                                   *(float *)((longlong)param_1 + 0x34) + 1.0;
                            }
                            if ((param_1[5] == 0) ||
                               (lVar6 = *(longlong *)(param_1[5] + 0x20), lVar6 == 0))
                            goto code_r0x0001804796e7;
                            if ((*(char *)(lVar6 + 0x3c) != '\0') &&
                               (cVar2 = (**(code **)(*param_1 + 0x218))
                                                  (param_1,*(undefined8 *)(*param_1 + 0x220)),
                               cVar2 != '\0')) {
                              fVar8 = *(float *)((longlong)param_1 + 0x1c);
                              fVar15 = (float)FUN_181f47dd0(0);
                              *(float *)((longlong)param_1 + 0x1c) = fVar8 - fVar15;
                              uVar9 = FUN_181dc1970(0);
                              lVar6 = param_1[5];
                              *(undefined4 *)((longlong)param_1 + 0x34) = uVar9;
                              if (lVar6 == 0) goto code_r0x0001804796e7;
                              fVar15 = *(float *)(lVar6 + 0x4c);
                              iVar4 = *(int *)(lVar6 + 0x28);
                              fVar8 = *(float *)((longlong)param_1 + 0x14);
                              if (fVar15 <= 0.0) {
                                if (*(longlong *)(lVar6 + 0x20) == 0) goto code_r0x0001804796e7;
                                fVar15 = *(float *)(*(longlong *)(lVar6 + 0x20) + 0x40);
                              }
                              fVar10 = (float)(**(code **)(*param_1 + 0x228))
                                                        (param_1,*(undefined8 *)(*param_1 + 0x230));
                              fVar10 = fVar10 * (float)iVar4 * 0.04 * fVar8 * fVar15;
                              fVar8 = 0.1;
                              if (0.1 <= fVar10) {
                                fVar8 = fVar10;
                              }
                              *(float *)(param_1 + 2) = fVar8;
                              fVar15 = (float)FUN_181f47ce0(0);
                              ExposureUnnoticed2_Scripts_Mission_MissionBase__RiseRp__06001423
                                        (param_1);
                              if ((**(longlong **)(DAT_182d53c48 + 0xb8) == 0) ||
                                 (lVar6 = *(longlong *)
                                           (**(longlong **)(DAT_182d53c48 + 0xb8) + 0x30),
                                 lVar6 == 0)) goto code_r0x0001804796e7;
                              *(float *)(lVar6 + 0x48) =
                                   fVar15 * fVar8 * fVar14 + *(float *)(lVar6 + 0x48);
                              fVar14 = *(float *)(param_1 + 3);
                              fVar8 = (float)FUN_181f47ce0(0);
                              lVar6 = param_1[5];
                              if (lVar6 == 0) goto code_r0x0001804796e7;
                              fVar15 = *(float *)(lVar6 + 0x4c);
                              if (fVar15 <= 0.0) {
                                if (*(longlong *)(lVar6 + 0x20) == 0) goto code_r0x0001804796e7;
                                fVar15 = *(float *)(*(longlong *)(lVar6 + 0x20) + 0x40);
                              }
                              fVar14 = fVar14 - fVar15 * fVar8;
                              *(float *)(param_1 + 3) = fVar14;
                              if ((fVar14 <= 0.0) && (0.0 < *(float *)((longlong)param_1 + 0x14))) {
                                fVar14 = *(float *)((longlong)param_1 + 0x14) - 0.05;
                                *(float *)((longlong)param_1 + 0x14) = fVar14;
                                if (fVar14 <= 0.01) {
                                  *(undefined4 *)((longlong)param_1 + 0x14) = 0;
                                }
                                if (0.0 < *(float *)((longlong)param_1 + 0x14)) {
                                  *(float *)(param_1 + 3) =
                                       1.0 / (*(float *)((longlong)param_1 + 0x14) * 0.04);
                                }
                              }
                            }
                          }
                          else {
                            if (*(int *)(*(longlong *)(param_1[5] + 0x20) + 0x28) == 0) {
                              iVar4 = *(int *)(param_1[5] + 0x28);
                              uVar11 = FUN_181f47ce0(0);
                              auVar12._8_4_ = (int)extraout_XMM0_Qb;
                              auVar12._0_8_ = uVar11;
                              auVar12._12_4_ = (int)((ulonglong)extraout_XMM0_Qb >> 0x20);
                              auVar13._4_12_ = auVar12._4_12_;
                              auVar13._0_4_ = (float)uVar11 * (float)iVar4 * fVar14;
                              ExposureUnnoticed2_Scripts_Mission_MissionBase__RiseRp__06001423
                                        (param_1,auVar13._0_8_,0);
                            }
                            *(float *)(param_1 + 6) = fVar8 + *(float *)(param_1 + 6);
                            uVar9 = FUN_181dc1970(0);
                            *(undefined4 *)((longlong)param_1 + 0x34) = uVar9;
                          }
                          fVar14 = *(float *)(param_1 + 6);
                          if (fVar14 < 0.0) {
                            fVar14 = 0.0;
                          }
                          else if (1.0 < fVar14) {
                            fVar14 = 1.0;
                          }
                          *(float *)(param_1 + 6) = fVar14;
                          lVar6 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
                          if (((lVar6 != 0) && (param_1[5] != 0)) &&
                             (lVar6 = *(longlong *)(lVar6 + 0x100), lVar6 != 0)) {
                            uVar11 = *(undefined8 *)
                                      (*(longlong *)
                                        (*(longlong *)(lRam0000000182d5e230 + 0x20) + 0xc0) + 0x100)
                            ;
                            FUN_180e59ff0(lVar6,*(undefined4 *)(param_1[5] + 0x50),uVar11,1,uVar11);
                            return;
                          }
                        }
                      }
                    }
                  }
                }
                else {
                  cVar2 = ExposureUnnoticed2_Scripts_InGame_GameStateFacade__IsActivePassiveSkill__06001525
                                    (5,0);
                  if ((cVar2 != '\0') &&
                     (*(float *)(param_1 + 6) <= 1.0 && *(float *)(param_1 + 6) != 1.0)) {
                    *(undefined4 *)(param_1 + 6) = 0;
                  }
                  if ((param_1[5] != 0) && (lVar6 = *(longlong *)(param_1[5] + 0x20), lVar6 != 0)) {
                    if ((*(int *)(lVar6 + 0x28) == 0) && (1.0 <= *(float *)(param_1 + 6))) {
                      return;
                    }
                    if (((*(int *)(*(longlong *)(param_1[5] + 0x20) + 0x28) == 1) &&
                        (1.0 <= *(float *)(param_1 + 6))) && (1.0 <= *(float *)(param_1 + 4))) {
                      return;
                    }
                    uVar9 = FUN_181dc1970(0);
                    *(undefined4 *)(param_1 + 7) = uVar9;
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
code_r0x0001804796e7:
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

