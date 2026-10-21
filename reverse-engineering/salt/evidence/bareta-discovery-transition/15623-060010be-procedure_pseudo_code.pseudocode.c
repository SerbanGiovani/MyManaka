// Ghidra pseudocode; not original source or compilable C.
// ev_ca2c86a3e444ec9f7b5e0bce2fd87b8387f11ff682995dcb6a2a599ab7720721

void ExposureUnnoticed2_Object3D_NPC_Script_NpcStrangenessManager__OnUpdate__060010be
               (longlong param_1)

{
  int iVar1;
  uint uVar2;
  longlong lVar3;
  longlong lVar4;
  longlong lVar5;
  float fVar6;
  char cVar7;
  float *pfVar8;
  code *pcVar9;
  undefined8 uVar10;
  float fVar11;
  float fVar12;
  float fVar13;
  float fVar14;
  float fVar15;
  float fVar16;
  float fVar17;
  float fVar18;
  float fVar19;
  float afStackX_8 [2];
  float fStackX_18;
  undefined1 auStack_b8 [176];
  
  if (cRam0000000182eb7789 == '\0') {
    FUN_1802f2810(&DAT_182d59ac8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d58398);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d58378);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d58230);
    LOCK();
    UNLOCK();
    cRam0000000182eb7789 = '\x01';
  }
  lVar3 = *(longlong *)(param_1 + 0x28);
  if ((lVar3 != 0) && (lVar4 = *(longlong *)(lVar3 + 0x40), lVar4 != 0)) {
    if (*(char *)(lVar4 + 0x23) != '\0') {
      return;
    }
    if (*(char *)(lVar4 + 0x85) != '\0') {
      return;
    }
    if (*(longlong *)(lVar3 + 0x38) != 0) {
      *(undefined1 *)(*(longlong *)(lVar3 + 0x38) + 0x20) = 0;
      if ((*(longlong *)(param_1 + 0x28) != 0) &&
         (lVar3 = *(longlong *)(*(longlong *)(param_1 + 0x28) + 0x40), lVar3 != 0)) {
        iVar1 = *(int *)(lVar3 + 0x10);
        if (*(longlong *)(param_1 + 0x10) != 0) {
          ExposureUnnoticed2_Object3D_NPC_Script_StrangenessValueManager__OnUpdate__06001104
                    (*(longlong *)(param_1 + 0x10),iVar1 == 4 || iVar1 == 2,0);
          if ((((*(longlong *)(param_1 + 0x28) != 0) &&
               (lVar3 = *(longlong *)(*(longlong *)(param_1 + 0x28) + 0x38), lVar3 != 0)) &&
              (lVar4 = *(longlong *)(*(longlong *)(param_1 + 0x28) + 0x48), lVar4 != 0)) &&
             ((**(longlong **)(DAT_182d58230 + 0xb8) != 0 &&
              (lVar5 = *(longlong *)(**(longlong **)(DAT_182d58230 + 0xb8) + 0x10), lVar5 != 0)))) {
            lVar5 = *(longlong *)(lVar5 + 0x148);
            if (lVar5 != 0) {
              pfVar8 = (float *)ExposureUnnoticed2_Object3D_Player_Scripts_PlayerStrangenessController__CalcStrangerDegreeFrom__06000e32
                                          (auStack_b8,lVar5,*(undefined8 *)(lVar3 + 0x10),
                                           *(undefined8 *)(lVar4 + 0x10),
                                           *(undefined8 *)(param_1 + 0x28),0);
              fVar17 = 0.0;
              fVar16 = *pfVar8;
              fVar15 = pfVar8[1];
              fVar13 = pfVar8[2];
              fVar6 = pfVar8[3];
              fVar14 = pfVar8[4];
              if (((**(longlong **)(DAT_182d58378 + 0xb8) != 0) &&
                  (lVar3 = *(longlong *)(**(longlong **)(DAT_182d58378 + 0xb8) + 0x40), lVar3 != 0))
                 && (lVar3 = *(longlong *)(lVar3 + 0x1e8), lVar3 != 0)) {
                if (cRam0000000182eb7659 == '\0') {
                  FUN_1802f2810(0x182d58310);
                  LOCK();
                  UNLOCK();
                  cRam0000000182eb7659 = '\x01';
                }
                fVar18 = *(float *)(lVar3 + 0x20);
                fStackX_18 = 0.3;
                if ((fVar18 == 0.0) || (fVar18 == 1.4013e-45)) {
                  fVar18 = 3.0;
                }
                else if (fVar18 == 2.8026e-45) {
                  fVar18 = 0.03;
                }
                else if (fVar18 == 4.2039e-45) {
                  fVar18 = 0.1;
                }
                else {
                  if (fVar18 != 5.60519e-45) {
                    afStackX_8[0] = fVar18;
                    uVar10 = il2cpp_value_box(uRam0000000182d58310,afStackX_8);
                    /* WARNING: Subroutine does not return */
                    _PrivateImplementationDetails___ThrowSwitchExpressionException__06001e66
                              (uVar10,0);
                  }
                  fVar18 = 0.3;
                }
                lVar3 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
                if (lVar3 != 0) {
                  if (*(int *)(lVar3 + 0x34) == 2) {
                    fVar19 = 4.0;
                    fStackX_18 = 1.0;
                  }
                  else {
                    fVar19 = 1.5;
                  }
                  fVar11 = (float)ExposureUnnoticed2_Object3D_NPC_Script_NpcStrangenessManager__CalcCommonAddScale__060010bf
                                            (param_1,0);
                  pcVar9 = DAT_182ec14d0;
                  afStackX_8[0] = fVar11;
                  if ((DAT_182ec14d0 == (code *)0x0) &&
                     (pcVar9 = (code *)FUN_1802cf0c0("UnityEngine.Time::get_deltaTime()"),
                     pcVar9 == (code *)0x0)) {
                    uVar10 = FUN_1802ced60("UnityEngine.Time::get_deltaTime()");
                    /* WARNING: Subroutine does not return */
                    FUN_1802cca90(uVar10,0);
                  }
                  DAT_182ec14d0 = pcVar9;
                  fVar12 = (float)(*DAT_182ec14d0)();
                  if (*(longlong *)(param_1 + 0x10) != 0) {
                    fVar13 = fVar13 - *(float *)(*(longlong *)(param_1 + 0x10) + 0x14);
                    fVar11 = fVar15 * fVar12 * fVar19 * fVar11;
                    if (fVar13 <= fVar11) {
                      fVar11 = fVar13;
                    }
                    if (fVar11 < 0.0) {
                      fVar11 = 0.0;
                    }
                    else if (1.0 < fVar11) {
                      fVar11 = 1.0;
                    }
                    if (*(longlong *)(param_1 + 0x18) != 0) {
                      if ((*(char *)(*(longlong *)(param_1 + 0x18) + 0x68) == '\0') ||
                         ((fVar16 <= 0.0 && (fVar15 <= 0.0)))) {
                        if ((*(longlong *)(param_1 + 0x28) == 0) ||
                           (lVar3 = *(longlong *)(*(longlong *)(param_1 + 0x28) + 0x40), lVar3 == 0)
                           ) goto code_r0x000180435cf5;
                        if ((*(char *)(lVar3 + 0x1d) == '\0') ||
                           (*(char *)(*(longlong *)(param_1 + 0x18) + 0x68) == '\0')) {
                          if ((*(int *)(*(longlong *)(*(longlong *)(param_1 + 0x28) + 0x40) + 0x58)
                               == 9) && (*(char *)(*(longlong *)(param_1 + 0x18) + 0x68) != '\0')) {
                            *(undefined1 *)
                             (*(longlong *)(*(longlong *)(param_1 + 0x28) + 0x40) + 0x30) = 1;
                            fVar14 = (float)FUN_181f47ce0(0);
                            if (*(longlong *)(param_1 + 0x10) == 0) goto code_r0x000180435cf5;
                            fVar16 = 0.5 - *(float *)(*(longlong *)(param_1 + 0x10) + 0x14);
                            fVar17 = fVar14 * 0.1 * fVar19 * afStackX_8[0];
                            if (fVar16 <= fVar17) {
                              fVar17 = fVar16;
                            }
                            if (fVar17 < 0.0) {
                              fVar17 = 0.0;
                            }
                            else if (1.0 < fVar17) {
                              fVar17 = 1.0;
                            }
                          }
                        }
                        else {
                          fVar17 = fVar14 * 0.1;
                        }
                      }
                      else {
                        fVar14 = (float)FUN_181f47ce0(0);
                        fVar17 = fVar14 * fVar16 * fVar19 * afStackX_8[0];
                        if (fVar17 <= fVar11) {
                          fVar17 = fVar11;
                        }
                        if (*(longlong *)(param_1 + 0x28) == 0) goto code_r0x000180435cf5;
                        lVar3 = *(longlong *)(*(longlong *)(param_1 + 0x28) + 0x40);
                        if (lVar3 == 0) goto code_r0x000180435cf5;
                        *(bool *)(lVar3 + 0x30) = fVar16 <= 0.0 && 0.0 < fVar15;
                      }
                      fVar14 = afStackX_8[0];
                      if ((*(longlong *)(param_1 + 0x28) != 0) &&
                         (lVar3 = *(longlong *)(*(longlong *)(param_1 + 0x28) + 0x48), lVar3 != 0))
                      {
                        cVar7 = ExposureUnnoticed2_Object3D_Player_Scripts_LookAtController__IsEnable__06000c12
                                          (lVar3,2,0);
                        if (cVar7 != '\0') {
                          if ((*(longlong *)(param_1 + 0x28) == 0) ||
                             (lVar3 = *(longlong *)(*(longlong *)(param_1 + 0x28) + 0x48),
                             lVar3 == 0)) goto code_r0x000180435cf5;
                          cVar7 = ExposureUnnoticed2_Object3D_Player_Scripts_LookAtController__IsEnable__06000c12
                                            (lVar3,3,0);
                          if (cVar7 == '\0') {
                            fVar17 = fVar17 * 0.5;
                          }
                        }
                        if (0.0 < fVar17) {
                          if (*(int *)(DAT_182d59ac8 + 0xe0) == 0) {
                            FUN_18035c820(DAT_182d59ac8);
                          }
                          if (*(char *)(*(longlong *)(DAT_182d59ac8 + 0xb8) + 0x11) == '\0') {
                            if ((*(longlong *)(param_1 + 0x28) == 0) ||
                               (lVar3 = *(longlong *)(*(longlong *)(param_1 + 0x28) + 0x38),
                               lVar3 == 0)) goto code_r0x000180435cf5;
                            *(undefined1 *)(lVar3 + 0x20) = 1;
                            lVar3 = *(longlong *)(param_1 + 0x10);
                            if (lVar3 == 0) goto code_r0x000180435cf5;
                            fVar16 = *(float *)(lVar3 + 0x14);
                            fVar15 = (float)FUN_181f47ce0(0);
                            fVar15 = fVar15 * fVar18 * fStackX_18;
                            if (fVar17 < 0.0) {
                              fVar17 = 0.0;
                            }
                            else if (fVar15 < fVar17) {
                              fVar17 = fVar15;
                            }
                            fVar17 = fVar17 + fVar16;
                            if (fVar17 < 0.0) {
                              fVar17 = 0.0;
                            }
                            else if (1.0 < fVar17) {
                              fVar17 = 1.0;
                            }
                            *(float *)(lVar3 + 0x14) = fVar17;
                            *(undefined4 *)(lVar3 + 0x18) = 0x78;
                            lVar3 = *(longlong *)(param_1 + 0x10);
                            if (lVar3 == 0) goto code_r0x000180435cf5;
                            fVar16 = *(float *)(lVar3 + 0x14);
                            if (fVar16 < 0.0) {
                              fVar16 = 0.0;
                            }
                            else if (1.0 < fVar16) {
                              fVar16 = 1.0;
                            }
                            if (fVar16 < 0.0) {
                              fVar16 = 0.0;
                            }
                            else if (1.0 < fVar16) {
                              fVar16 = 1.0;
                            }
                            *(float *)(lVar3 + 0x14) = fVar16;
                            *(undefined4 *)(lVar3 + 0x18) = 0x78;
                          }
                        }
                        if ((*(longlong *)(param_1 + 0x28) != 0) &&
                           (lVar3 = *(longlong *)(*(longlong *)(param_1 + 0x28) + 0x40), lVar3 != 0)
                           ) {
                          if (*(char *)(lVar3 + 0xa0) == '\0') {
                            if ((*(char *)(lVar3 + 0x54) != '\0') || (fVar14 <= 0.0)) {
                              return;
                            }
                            fVar16 = *(float *)(lVar3 + 0x24);
                            fVar15 = (float)FUN_181f47ce0(0);
                            *(float *)(lVar3 + 0x24) = fVar16 - fVar15;
                            if ((*(longlong *)(param_1 + 0x28) != 0) &&
                               (lVar3 = *(longlong *)(*(longlong *)(param_1 + 0x28) + 0x40),
                               lVar3 != 0)) {
                              pfVar8 = (float *)(lVar3 + 0x24);
                              if (0.0 < *pfVar8 || *pfVar8 == 0.0) {
                                return;
                              }
                              if ((fVar6 <= 0.0) && (*(float *)(param_1 + 0x30) <= 0.0)) {
                                return;
                              }
                              fVar16 = (float)FUN_181f47ce0(0);
                              if (((*(longlong *)(param_1 + 0x28) != 0) &&
                                  (lVar3 = *(longlong *)(*(longlong *)(param_1 + 0x28) + 0x40),
                                  lVar3 != 0)) &&
                                 (lVar4 = *(longlong *)(param_1 + 0x10), lVar4 != 0)) {
                                fVar15 = *(float *)(lVar3 + 0xcc) - *(float *)(lVar4 + 0x14);
                                fVar16 = fVar16 * fVar6;
                                if (fVar15 <= fVar16) {
                                  fVar16 = fVar15;
                                }
                                if (fVar16 < 0.0) {
                                  fVar16 = 0.0;
                                }
                                else if (1.0 < fVar16) {
                                  fVar16 = 1.0;
                                }
                                fVar16 = fVar14 * *(float *)(param_1 + 0x30) + fVar16 * fVar14;
                                fVar14 = fVar16 + *(float *)(lVar4 + 0x14);
                                if (fVar14 < 0.0) {
                                  fVar14 = 0.0;
                                }
                                else if (1.0 < fVar14) {
                                  fVar14 = 1.0;
                                }
                                *(float *)(lVar4 + 0x14) = fVar14;
                                *(undefined4 *)(lVar4 + 0x18) = 0x78;
                                if ((*(longlong *)(param_1 + 0x28) != 0) &&
                                   (lVar3 = *(longlong *)(*(longlong *)(param_1 + 0x28) + 0x40),
                                   lVar3 != 0)) {
                                  *(undefined1 *)(lVar3 + 0x30) = 0;
                                  if ((*(longlong *)(param_1 + 0x28) != 0) &&
                                     (lVar3 = *(longlong *)(*(longlong *)(param_1 + 0x28) + 0x68),
                                     lVar3 != 0)) {
                                    if ((*(char *)(lVar3 + 0x68) != '\0') || (fVar16 <= 0.0))
                                    goto code_r0x000180435abf;
                                    if (*(longlong *)(param_1 + 0x10) != 0) {
                                      lVar3 = *(longlong *)(*(longlong *)(param_1 + 0x28) + 0x40);
                                      if (lVar3 != 0) {
                                        if (*(float *)(lVar3 + 0xcc) <=
                                            *(float *)(*(longlong *)(param_1 + 0x10) + 0x14)) {
                                          lVar3 = *(longlong *)
                                                   (*(longlong *)(param_1 + 0x28) + 0x38);
                                          if (lVar3 == 0) goto code_r0x000180435cf5;
                                          ExposureUnnoticed2_Object3D_NPC_Script_NpcController__ChangeState__0600105f
                                                    (lVar3,2,0);
                                        }
code_r0x000180435abf:
                                        *(undefined4 *)(param_1 + 0x30) = 0;
                                        return;
                                      }
                                    }
                                  }
                                }
                              }
                            }
                          }
                          else if (lVar3 != 0) {
                            *(undefined1 *)(lVar3 + 0xa0) = 0;
                            if ((*(longlong *)(param_1 + 0x28) != 0) &&
                               (lVar3 = *(longlong *)(*(longlong *)(param_1 + 0x28) + 0x40),
                               lVar3 != 0)) {
                              if (*(char *)(lVar3 + 0x1f) == '\0') {
                                if (((*(int *)(lVar3 + 0x58) != 2) && (*(int *)(lVar3 + 0x58) != 10)
                                    ) || (*(char *)(*(longlong *)
                                                     (*(longlong *)(param_1 + 0x28) + 0x40) + 0xb4)
                                          != '\0')) {
                                  lVar3 = *(longlong *)(*(longlong *)(param_1 + 0x28) + 0x40);
                                  if (((*(int *)(lVar3 + 0x10) != 0) ||
                                      (*(char *)(lVar3 + 0xb4) != '\0')) &&
                                     (lVar3 = *(longlong *)(*(longlong *)(param_1 + 0x28) + 0x40),
                                     *(int *)(lVar3 + 0x10) != 6)) {
                                    if (*(int *)(lVar3 + 0x10) != 5) {
                                      return;
                                    }
                                    if (*(char *)(lVar3 + 0xb4) != '\0') {
                                      return;
                                    }
                                    uVar2 = *(uint *)(lVar3 + 100);
                                    if ((uVar2 != 2) &&
                                       (((0xe < uVar2 || ((0x6fb2U >> (uVar2 & 0x1f) & 1) == 0)) &&
                                        (uVar2 != 0xc)))) {
                                      return;
                                    }
                                  }
                                }
                                lVar3 = *(longlong *)(param_1 + 0x10);
                                if (lVar3 != 0) {
                                  lVar4 = *(longlong *)(*(longlong *)(param_1 + 0x28) + 0x40);
                                  if (*(float *)(lVar3 + 0x14) < *(float *)(lVar4 + 0xcc)) {
                                    fVar16 = *(float *)(lVar4 + 0xcc) + *(float *)(lVar3 + 0x14);
                                    fVar14 = *(float *)(lVar4 + 0xcc);
                                    if (fVar16 <= *(float *)(lVar4 + 0xcc)) {
                                      fVar14 = fVar16;
                                    }
                                    if (fVar14 < 0.0) {
                                      fVar14 = 0.0;
                                    }
                                    else if (1.0 < fVar14) {
                                      fVar14 = 1.0;
                                    }
                                    *(float *)(lVar3 + 0x14) = fVar14;
                                    *(undefined4 *)(lVar3 + 0x18) = 0x78;
                                  }
                                  if (((*(longlong *)(param_1 + 0x10) != 0) &&
                                      (lVar3 = *(longlong *)(param_1 + 0x28), lVar3 != 0)) &&
                                     (*(longlong *)(lVar3 + 0x40) != 0)) {
                                    if (*(float *)(*(longlong *)(param_1 + 0x10) + 0x14) <
                                        *(float *)(*(longlong *)(lVar3 + 0x40) + 0xcc)) {
                                      return;
                                    }
                                    if (*(longlong *)(lVar3 + 0x38) != 0) {
                                      ExposureUnnoticed2_Object3D_NPC_Script_NpcController__ChangeState__0600105f
                                                (*(longlong *)(lVar3 + 0x38),2,0);
                                      return;
                                    }
                                  }
                                }
                              }
                              else if (lVar3 != 0) {
                                if (*(float *)(lVar3 + 0x60) <= 0.0) {
                                  return;
                                }
                                lVar3 = *(longlong *)(param_1 + 0x10);
                                if (((*(longlong *)(param_1 + 0x28) != 0) &&
                                    (lVar4 = *(longlong *)(*(longlong *)(param_1 + 0x28) + 0x40),
                                    lVar4 != 0)) && (lVar3 != 0)) {
                                  fVar14 = *(float *)(lVar4 + 0xcc) + 0.01;
                                  if (fVar14 < 0.0) {
                                    fVar14 = 0.0;
                                  }
                                  else if (1.0 < fVar14) {
                                    *(undefined4 *)(lVar3 + 0x18) = 0x78;
                                    *(undefined4 *)(lVar3 + 0x14) = 0x3f800000;
                                    return;
                                  }
                                  *(float *)(lVar3 + 0x14) = fVar14;
                                  *(undefined4 *)(lVar3 + 0x18) = 0x78;
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
            }
          }
        }
      }
    }
  }
code_r0x000180435cf5:
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

