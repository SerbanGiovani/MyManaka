// Ghidra pseudocode; not original source or compilable C.
// ev_cf6af90c2c7f461d54f7559a9d1a31eac0f1e013c43f1233097c6f92b1f710e6

void ExposureUnnoticed2_Object3D_NPC_Script_NpcManager__OnUpdate__0600109d(longlong param_1)

{
  float fVar1;
  int iVar2;
  longlong lVar3;
  ulonglong uVar4;
  longlong lVar5;
  char cVar6;
  char cVar7;
  code *pcVar8;
  undefined8 uVar9;
  ulonglong uVar10;
  uint uVar11;
  bool bVar12;
  undefined8 uStack_98;
  longlong *plStack_90;
  undefined8 uStack_88;
  longlong lStack_80;
  longlong lStack_78;
  longlong lStack_70;
  
  if (cRam0000000182eb7773 == '\0') {
    FUN_1802f2810(0x182d59528);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d595a0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d59598);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d59590);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d53c48);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d58380);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d594c0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d594f8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d59580);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d59520);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d59488);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d53aa8);
    LOCK();
    UNLOCK();
    cRam0000000182eb7773 = '\x01';
  }
  lStack_80 = 0;
  lStack_78 = 0;
  lStack_70 = 0;
  lVar3 = *(longlong *)(param_1 + 0x70);
  if (*(int *)(DAT_182d53aa8 + 0xe0) == 0) {
    FUN_18035c820();
  }
  if (DAT_182ec12f3 == '\0') {
    FUN_1802f2810(&DAT_182d53aa8);
    LOCK();
    UNLOCK();
    DAT_182ec12f3 = '\x01';
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
  if (lVar3 != 0) {
    if (*(int *)(DAT_182d53aa8 + 0xe0) == 0) {
      FUN_18035c820();
    }
    if (*(longlong *)(lVar3 + 0x10) != 0) {
      *(undefined1 *)(param_1 + 0x5a) = 0;
      *(undefined2 *)(param_1 + 0x5e) = 0;
      *(undefined4 *)(param_1 + 0x60) = 0;
      if ((**(longlong **)(DAT_182d53c48 + 0xb8) != 0) &&
         (lVar3 = *(longlong *)(**(longlong **)(DAT_182d53c48 + 0xb8) + 0x30), lVar3 != 0)) {
        if (*(char *)(lVar3 + 0x14) != '\0') {
          lVar3 = *(longlong *)(param_1 + 0x38);
          if (lVar3 == 0) goto code_r0x000180431253;
          if (DAT_182eb5d50 != 0) {
            uVar11 = (uint)((ulonglong)&uStack_98 >> 0xc);
            uVar10 = (ulonglong)((uVar11 & 0x1fffff) >> 6);
            do {
              uVar4 = *(ulonglong *)(&DAT_182f0c920 + uVar10 * 8);
              LOCK();
              bVar12 = uVar4 == *(ulonglong *)(&DAT_182f0c920 + uVar10 * 8);
              if (bVar12) {
                *(ulonglong *)(&DAT_182f0c920 + uVar10 * 8) =
                     uVar4 | 1L << (ulonglong)(uVar11 & 0x3f);
              }
              UNLOCK();
            } while (!bVar12);
          }
          uStack_88 = 0;
          lStack_78 = (ulonglong)*(uint *)(lVar3 + 0x1c) << 0x20;
          lStack_70 = 0;
          uStack_98 = 0;
          plStack_90 = &lStack_80;
          lStack_80 = lVar3;
          while (cVar6 = FUN_180f72b70(&lStack_80,DAT_182d59598), lVar3 = lStack_70, cVar6 != '\0')
          {
            if (lStack_70 == 0) {
                    /* WARNING: Subroutine does not return */
              FUN_18031dad0();
            }
            if (*(longlong *)(lStack_70 + 0x58) == 0) {
                    /* WARNING: Subroutine does not return */
              FUN_18031dad0();
            }
            ExposureUnnoticed2_Object3D_NPC_Script_NpcFadeOutState__UpdateFadeIn__060010ef
                      (*(longlong *)(lStack_70 + 0x58),0);
            if (*(longlong *)(lVar3 + 0x30) == 0) {
                    /* WARNING: Subroutine does not return */
              FUN_18031dad0();
            }
            lVar3 = *(longlong *)(*(longlong *)(lVar3 + 0x30) + 0x88);
            if (lVar3 == 0) {
                    /* WARNING: Subroutine does not return */
              FUN_18031dad0();
            }
            ExposureUnnoticed2_Object3D_NPC_Script_NpcAnimatorFpsController__OnUpdate__06000fe4
                      (lVar3,0);
          }
        }
        if ((**(longlong **)(DAT_182d53c48 + 0xb8) != 0) &&
           (lVar3 = *(longlong *)(**(longlong **)(DAT_182d53c48 + 0xb8) + 0x30), lVar3 != 0)) {
          if (*(char *)(lVar3 + 0x14) != '\0') {
            return;
          }
          if (*(char *)(*(longlong *)(**(longlong **)(DAT_182d53c48 + 0xb8) + 0x30) + 0x13) != '\0')
          {
            return;
          }
          if (*(int *)(DAT_182d58380 + 0xe0) == 0) {
            FUN_18035c820(DAT_182d58380);
          }
          if (**(longlong **)(DAT_182d58380 + 0xb8) != 0) {
            if (*(char *)(**(longlong **)(DAT_182d58380 + 0xb8) + 0x20) != '\0') {
              return;
            }
            if (cRam0000000182eb548f == '\0') {
              FUN_1802f2810(&DAT_182d59250);
              LOCK();
              UNLOCK();
              cRam0000000182eb548f = '\x01';
            }
            if (**(char **)(DAT_182d59250 + 0xb8) != '\0') {
              return;
            }
            if ((**(longlong **)(DAT_182d53c48 + 0xb8) != 0) &&
               (lVar3 = *(longlong *)(**(longlong **)(DAT_182d53c48 + 0xb8) + 0x30), lVar3 != 0)) {
              if (*(char *)(lVar3 + 0x11) != '\0') {
                return;
              }
              if (*(longlong *)(param_1 + 0x70) != 0) {
                if (*(char *)(*(longlong *)(param_1 + 0x70) + 0x3c) == '\0') {
                  if (0 < *(int *)(param_1 + 0x6c)) {
                    ExposureUnnoticed2_Object3D_NPC_Script_NpcManager__InstantiateNpc__0600109a
                              (param_1,0,0,0,0);
                    *(int *)(param_1 + 0x6c) = *(int *)(param_1 + 0x6c) + -1;
                  }
                }
                else {
                  if ((*(longlong *)(param_1 + 0x38) == 0) || (*(longlong *)(param_1 + 0x50) == 0))
                  goto code_r0x000180431253;
                  cVar6 = ExposureUnnoticed2_Object3D_NPC_Script_NpcSpawnInterval__IsSpawn__060010b8
                                    (*(longlong *)(param_1 + 0x50),
                                     *(int *)(*(longlong *)(param_1 + 0x38) + 0x18) -
                                     *(int *)(param_1 + 0x68),0);
                  if (cVar6 != '\0') {
                    ExposureUnnoticed2_Object3D_NPC_Script_NpcManager__InstantiateNpc__0600109a
                              (param_1,0,0,0,0);
                  }
                }
                lVar3 = *(longlong *)(param_1 + 0x78);
                if (lVar3 != 0) {
                  *(int *)(lVar3 + 0x1c) = *(int *)(lVar3 + 0x1c) + 1;
                  iVar2 = *(int *)(lVar3 + 0x18);
                  *(undefined4 *)(lVar3 + 0x18) = 0;
                  if (0 < iVar2) {
                    FUN_181646f50(*(undefined8 *)(lVar3 + 0x10),0,iVar2,0);
                  }
                  lVar3 = *(longlong *)(param_1 + 0x38);
                  if (lVar3 != 0) {
                    if (DAT_182eb5d50 != 0) {
                      uVar11 = (uint)((ulonglong)&uStack_98 >> 0xc);
                      uVar10 = (ulonglong)((uVar11 & 0x1fffff) >> 6);
                      do {
                        uVar4 = *(ulonglong *)(&DAT_182f0c920 + uVar10 * 8);
                        LOCK();
                        bVar12 = uVar4 == *(ulonglong *)(&DAT_182f0c920 + uVar10 * 8);
                        if (bVar12) {
                          *(ulonglong *)(&DAT_182f0c920 + uVar10 * 8) =
                               uVar4 | 1L << (uVar11 & 0x3f);
                        }
                        UNLOCK();
                      } while (!bVar12);
                    }
                    uStack_88 = 0;
                    lStack_78 = (ulonglong)*(uint *)(lVar3 + 0x1c) << 0x20;
                    lStack_70 = 0;
                    uStack_98 = 0;
                    plStack_90 = &lStack_80;
                    lStack_80 = lVar3;
                    while (cVar6 = FUN_180f72b70(&lStack_80,DAT_182d59598), lVar3 = lStack_70,
                          cVar6 != '\0') {
                      if (lStack_70 == 0) {
                    /* WARNING: Subroutine does not return */
                        FUN_18031dad0();
                      }
                      lVar5 = *(longlong *)(lStack_70 + 0x18);
                      if (lVar5 == 0) {
                    /* WARNING: Subroutine does not return */
                        FUN_18031dad0();
                      }
                      pcVar8 = DAT_182ec1148;
                      if ((DAT_182ec1148 == (code *)0x0) &&
                         (pcVar8 = (code *)FUN_1802cf0c0(
                                                  "UnityEngine.GameObject::get_activeInHierarchy()")
                         , pcVar8 == (code *)0x0)) {
                        uVar9 = FUN_1802ced60("UnityEngine.GameObject::get_activeInHierarchy()");
                    /* WARNING: Subroutine does not return */
                        FUN_1802cca90(uVar9,0);
                      }
                      DAT_182ec1148 = pcVar8;
                      cVar6 = (*DAT_182ec1148)(lVar5);
                      if (cVar6 == '\0') {
                        if (*(longlong *)(param_1 + 0x78) == 0) {
                    /* WARNING: Subroutine does not return */
                          FUN_18031dad0();
                        }
                        FUN_1800055c0(*(longlong *)(param_1 + 0x78),lVar3);
                      }
                      else {
                        ExposureUnnoticed2_Object3D_NPC_Script_NpcController__OnUpdateEarly__0600105a
                                  (lVar3,0);
                      }
                    }
                    lVar3 = *(longlong *)(param_1 + 0x38);
                    if (lVar3 != 0) {
                      if (DAT_182eb5d50 != 0) {
                        uVar11 = (uint)((ulonglong)&uStack_98 >> 0xc);
                        uVar10 = (ulonglong)((uVar11 & 0x1fffff) >> 6);
                        do {
                          uVar4 = *(ulonglong *)(&DAT_182f0c920 + uVar10 * 8);
                          LOCK();
                          bVar12 = uVar4 == *(ulonglong *)(&DAT_182f0c920 + uVar10 * 8);
                          if (bVar12) {
                            *(ulonglong *)(&DAT_182f0c920 + uVar10 * 8) =
                                 uVar4 | 1L << (uVar11 & 0x3f);
                          }
                          UNLOCK();
                        } while (!bVar12);
                      }
                      uStack_88 = 0;
                      lStack_78 = (ulonglong)*(uint *)(lVar3 + 0x1c) << 0x20;
                      lStack_70 = 0;
                      uStack_98 = 0;
                      plStack_90 = &lStack_80;
                      lStack_80 = lVar3;
                      while (cVar6 = FUN_180f72b70(&lStack_80,DAT_182d59598), lVar3 = lStack_70,
                            cVar6 != '\0') {
                        if (lStack_70 == 0) {
                    /* WARNING: Subroutine does not return */
                          FUN_18031dad0();
                        }
                        lVar5 = *(longlong *)(lStack_70 + 0x18);
                        if (lVar5 == 0) {
                    /* WARNING: Subroutine does not return */
                          FUN_18031dad0();
                        }
                        pcVar8 = DAT_182ec1148;
                        if ((DAT_182ec1148 == (code *)0x0) &&
                           (pcVar8 = (code *)FUN_1802cf0c0(
                                                  "UnityEngine.GameObject::get_activeInHierarchy()")
                           , pcVar8 == (code *)0x0)) {
                          uVar9 = FUN_1802ced60("UnityEngine.GameObject::get_activeInHierarchy()");
                    /* WARNING: Subroutine does not return */
                          FUN_1802cca90(uVar9,0);
                        }
                        DAT_182ec1148 = pcVar8;
                        cVar6 = (*DAT_182ec1148)(lVar5);
                        if (cVar6 != '\0') {
                          ExposureUnnoticed2_Object3D_NPC_Script_NpcController__OnUpdateAlsoGameOver__06001057
                                    (lVar3,0);
                          if (**(longlong **)(DAT_182d53c48 + 0xb8) == 0) {
                    /* WARNING: Subroutine does not return */
                            FUN_18031dad0();
                          }
                          lVar5 = *(longlong *)(**(longlong **)(DAT_182d53c48 + 0xb8) + 0x30);
                          if (lVar5 == 0) {
                    /* WARNING: Subroutine does not return */
                            FUN_18031dad0();
                          }
                          if (*(char *)(lVar5 + 0x11) == '\0') {
                            ExposureUnnoticed2_Object3D_NPC_Script_NpcController__OnUpdate__0600105b
                                      (lVar3,0);
                            if (*(longlong *)(lVar3 + 0x30) == 0) {
                    /* WARNING: Subroutine does not return */
                              FUN_18031dad0();
                            }
                            lVar5 = *(longlong *)(*(longlong *)(lVar3 + 0x30) + 0x60);
                            if (lVar5 == 0) {
                    /* WARNING: Subroutine does not return */
                              FUN_18031dad0();
                            }
                            lVar5 = *(longlong *)(lVar5 + 0x10);
                            if (lVar5 == 0) {
                    /* WARNING: Subroutine does not return */
                              FUN_18031dad0();
                            }
                            *(bool *)(param_1 + 0x5a) =
                                 1.0 <= *(float *)(lVar5 + 0x14) ||
                                 *(char *)(param_1 + 0x5a) != '\0';
                            cVar6 = *(char *)(param_1 + 0x5f);
                            cVar7 = ExposureUnnoticed2_Object3D_NPC_Script_NpcController__get_IsWatchingStranger__0600104d
                                              (lVar3,0);
                            *(bool *)(param_1 + 0x5f) = cVar6 != '\0' || cVar7 != '\0';
                            cVar6 = *(char *)(param_1 + 0x5e);
                            if (*(longlong *)(lVar3 + 0x30) == 0) {
                    /* WARNING: Subroutine does not return */
                              FUN_18031dad0();
                            }
                            lVar5 = *(longlong *)(*(longlong *)(lVar3 + 0x30) + 0x68);
                            if (lVar5 == 0) {
                    /* WARNING: Subroutine does not return */
                              FUN_18031dad0();
                            }
                            bVar12 = false;
                            if (*(char *)(lVar5 + 0x68) != '\0') {
                              lVar5 = *(longlong *)(*(longlong *)(lVar3 + 0x30) + 0xf8);
                              if (lVar5 == 0) {
                    /* WARNING: Subroutine does not return */
                                FUN_18031dad0();
                              }
                              cVar7 = ExposureUnnoticed2_Object3D_NPC_Script_State_NpcChairSubState__get_IsCurrentChairSleep__06001106
                                                (lVar5,0);
                              if (cVar7 == '\0') {
                                bVar12 = true;
                              }
                              else {
                                if (*(longlong *)(lVar3 + 0x30) == 0) {
                    /* WARNING: Subroutine does not return */
                                  FUN_18031dad0();
                                }
                                lVar5 = *(longlong *)(*(longlong *)(lVar3 + 0x30) + 0x40);
                                if (lVar5 == 0) {
                    /* WARNING: Subroutine does not return */
                                  FUN_18031dad0();
                                }
                                bVar12 = 0.0 < *(float *)(lVar5 + 0x60);
                              }
                            }
                            *(bool *)(param_1 + 0x5e) = cVar6 != '\0' || bVar12;
                            if (*(char *)(param_1 + 0x5f) != '\0') {
                              if (*(longlong *)(lVar3 + 0x30) == 0) {
                    /* WARNING: Subroutine does not return */
                                FUN_18031dad0();
                              }
                              lVar5 = *(longlong *)(*(longlong *)(lVar3 + 0x30) + 0x60);
                              if (lVar5 == 0) {
                    /* WARNING: Subroutine does not return */
                                FUN_18031dad0();
                              }
                              lVar5 = *(longlong *)(lVar5 + 0x10);
                              if (lVar5 == 0) {
                    /* WARNING: Subroutine does not return */
                                FUN_18031dad0();
                              }
                              fVar1 = *(float *)(lVar5 + 0x14);
                              if (*(float *)(param_1 + 0x60) <= fVar1 &&
                                  fVar1 != *(float *)(param_1 + 0x60)) {
                                *(undefined4 *)(param_1 + 0x60) =
                                     *(undefined4 *)
                                      (*(longlong *)
                                        (*(longlong *)(*(longlong *)(lVar3 + 0x30) + 0x60) + 0x10) +
                                      0x14);
                              }
                            }
                          }
                        }
                      }
                      lVar3 = *(longlong *)(param_1 + 0x78);
                      if (lVar3 != 0) {
                        if (DAT_182eb5d50 != 0) {
                          uVar11 = (uint)((ulonglong)&uStack_98 >> 0xc);
                          uVar10 = (ulonglong)((uVar11 & 0x1fffff) >> 6);
                          do {
                            uVar4 = *(ulonglong *)(&DAT_182f0c920 + uVar10 * 8);
                            LOCK();
                            bVar12 = uVar4 == *(ulonglong *)(&DAT_182f0c920 + uVar10 * 8);
                            if (bVar12) {
                              *(ulonglong *)(&DAT_182f0c920 + uVar10 * 8) =
                                   uVar4 | 1L << (uVar11 & 0x3f);
                            }
                            UNLOCK();
                          } while (!bVar12);
                        }
                        uStack_88 = 0;
                        lStack_78 = (ulonglong)*(uint *)(lVar3 + 0x1c) << 0x20;
                        lStack_70 = 0;
                        uStack_98 = 0;
                        plStack_90 = &lStack_80;
                        lStack_80 = lVar3;
                        while (cVar6 = FUN_180f72b70(&lStack_80,DAT_182d59598), lVar3 = lStack_70,
                              cVar6 != '\0') {
                          if (*(longlong *)(param_1 + 0x38) == 0) {
                    /* WARNING: Subroutine does not return */
                            FUN_18031dad0();
                          }
                          FUN_181274e50(*(longlong *)(param_1 + 0x38),lStack_70,uRam0000000182d59520
                                       );
                          if (lVar3 == 0) {
                    /* WARNING: Subroutine does not return */
                            FUN_18031dad0();
                          }
                          if (*(longlong *)(param_1 + 0x40) == 0) {
                    /* WARNING: Subroutine does not return */
                            FUN_18031dad0();
                          }
                          FUN_180ebb270(*(longlong *)(param_1 + 0x40),*(undefined8 *)(lVar3 + 0x18),
                                        uRam0000000182d59528);
                          ExposureUnnoticed2_Object3D_NPC_Script_NpcController__Destroy__06001063
                                    (lVar3,0);
                          *(int *)(param_1 + 0x6c) = *(int *)(param_1 + 0x6c) + 1;
                        }
                        *(undefined2 *)(param_1 + 0x58) = 0;
                        *(undefined2 *)(param_1 + 0x5b) = 0;
                        *(undefined1 *)(param_1 + 0x5d) = 0;
                        lVar3 = *(longlong *)(param_1 + 0x38);
                        if (lVar3 != 0) {
                          if (DAT_182eb5d50 != 0) {
                            uVar11 = (uint)((ulonglong)&uStack_98 >> 0xc);
                            uVar10 = (ulonglong)((uVar11 & 0x1fffff) >> 6);
                            do {
                              uVar4 = *(ulonglong *)(&DAT_182f0c920 + uVar10 * 8);
                              LOCK();
                              bVar12 = uVar4 == *(ulonglong *)(&DAT_182f0c920 + uVar10 * 8);
                              if (bVar12) {
                                *(ulonglong *)(&DAT_182f0c920 + uVar10 * 8) =
                                     uVar4 | 1L << (uVar11 & 0x3f);
                              }
                              UNLOCK();
                            } while (!bVar12);
                          }
                          uStack_88 = 0;
                          lStack_78 = (ulonglong)*(uint *)(lVar3 + 0x1c) << 0x20;
                          lStack_70 = 0;
                          uStack_98 = 0;
                          plStack_90 = &lStack_80;
                          lStack_80 = lVar3;
                          while( true ) {
                            cVar6 = FUN_180f72b70(&lStack_80,DAT_182d59598);
                            lVar3 = lStack_70;
                            if (cVar6 == '\0') {
                              return;
                            }
                            if (lStack_70 == 0) {
                    /* WARNING: Subroutine does not return */
                              FUN_18031dad0();
                            }
                            cVar6 = ExposureUnnoticed2_Object3D_NPC_Script_NpcController__get_IsVisible__06001047
                                              (lStack_70,0);
                            if (cVar6 != '\0') {
                              if (*(longlong *)(lVar3 + 0x30) == 0) {
                    /* WARNING: Subroutine does not return */
                                FUN_18031dad0();
                              }
                              lVar5 = *(longlong *)(*(longlong *)(lVar3 + 0x30) + 0x68);
                              if (lVar5 == 0) {
                    /* WARNING: Subroutine does not return */
                                FUN_18031dad0();
                              }
                              if (*(char *)(lVar5 + 0x68) != '\0') {
                                *(undefined1 *)(param_1 + 0x5d) = 1;
                              }
                            }
                            if (*(char *)(lVar3 + 0x20) != '\0') {
                              cVar6 = ExposureUnnoticed2_Object3D_NPC_Script_NpcController__get_IsVisible__06001047
                                                (lVar3,0);
                              if (cVar6 != '\0') {
                                if (*(longlong *)(lVar3 + 0x30) == 0) {
                    /* WARNING: Subroutine does not return */
                                  FUN_18031dad0();
                                }
                                lVar5 = *(longlong *)(*(longlong *)(lVar3 + 0x30) + 0x40);
                                if (lVar5 == 0) {
                    /* WARNING: Subroutine does not return */
                                  FUN_18031dad0();
                                }
                                if (*(char *)(lVar5 + 0x30) == '\0') {
                                  *(undefined1 *)(param_1 + 0x5b) = 1;
                                }
                              }
                              if (*(char *)(lVar3 + 0x20) != '\0') {
                                if (*(longlong *)(lVar3 + 0x30) == 0) {
                    /* WARNING: Subroutine does not return */
                                  FUN_18031dad0();
                                }
                                lVar5 = *(longlong *)(*(longlong *)(lVar3 + 0x30) + 0x40);
                                if (lVar5 == 0) {
                    /* WARNING: Subroutine does not return */
                                  FUN_18031dad0();
                                }
                                if (*(char *)(lVar5 + 0x30) == '\0') {
                                  *(undefined1 *)(param_1 + 0x5c) = 1;
                                }
                              }
                            }
                            if (*(longlong *)(lVar3 + 0x30) == 0) {
                    /* WARNING: Subroutine does not return */
                              FUN_18031dad0();
                            }
                            lVar5 = *(longlong *)(*(longlong *)(lVar3 + 0x30) + 0x60);
                            if (lVar5 == 0) {
                    /* WARNING: Subroutine does not return */
                              FUN_18031dad0();
                            }
                            lVar5 = *(longlong *)(lVar5 + 0x10);
                            if (lVar5 == 0) {
                    /* WARNING: Subroutine does not return */
                              FUN_18031dad0();
                            }
                            if ((0.7 <= *(float *)(lVar5 + 0x14)) &&
                               (*(char *)(lVar3 + 0x20) != '\0')) {
                              lVar5 = *(longlong *)(*(longlong *)(lVar3 + 0x30) + 0x40);
                              if (lVar5 == 0) {
                    /* WARNING: Subroutine does not return */
                                FUN_18031dad0();
                              }
                              if (*(char *)(lVar5 + 0x30) == '\0') {
                                *(undefined1 *)(param_1 + 0x58) = 1;
                              }
                            }
                            if (*(longlong *)(lVar3 + 0x30) == 0) {
                    /* WARNING: Subroutine does not return */
                              FUN_18031dad0();
                            }
                            lVar3 = *(longlong *)(*(longlong *)(lVar3 + 0x30) + 0x60);
                            if (lVar3 == 0) {
                    /* WARNING: Subroutine does not return */
                              FUN_18031dad0();
                            }
                            lVar3 = *(longlong *)(lVar3 + 0x10);
                            if (lVar3 == 0) break;
                            if (1.0 <= *(float *)(lVar3 + 0x14)) {
                              *(undefined2 *)(param_1 + 0x58) = 0x101;
                            }
                          }
                    /* WARNING: Subroutine does not return */
                          FUN_18031dad0();
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
code_r0x000180431253:
                    /* WARNING: Subroutine does not return */
      FUN_18031dad0();
    }
  }
  return;
}

