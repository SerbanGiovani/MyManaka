// Ghidra pseudocode; not original source or compilable C.
// ev_5b808099e835a21508b4d809bf67dfeb7992dedfb48181f36971aa2aae34a966

void ExposureUnnoticed2_Object3D_NPC_Script_NpcComponentAccessor__Initialize__06001038
               (longlong param_1)

{
  longlong lVar1;
  ulonglong uVar2;
  byte bVar3;
  int iVar4;
  int iVar5;
  code *pcVar6;
  undefined8 uVar7;
  ulonglong uVar8;
  uint uVar9;
  bool bVar10;
  undefined4 uVar11;
  
  iVar4 = DAT_182eb5d50;
  lVar1 = *(longlong *)(param_1 + 0x20);
  if (lVar1 != 0) {
    *(longlong *)(lVar1 + 0x10) = param_1;
    if (iVar4 != 0) {
      uVar9 = (uint)(lVar1 + 0x10U >> 0xc);
      uVar8 = (ulonglong)((uVar9 & 0x1fffff) >> 6);
      do {
        uVar2 = *(ulonglong *)(&DAT_182f0c920 + uVar8 * 8);
        LOCK();
        bVar10 = uVar2 == *(ulonglong *)(&DAT_182f0c920 + uVar8 * 8);
        if (bVar10) {
          *(ulonglong *)(&DAT_182f0c920 + uVar8 * 8) = uVar2 | 1L << (uVar9 & 0x3f);
        }
        UNLOCK();
        iVar4 = DAT_182eb5d50;
      } while (!bVar10);
    }
    lVar1 = *(longlong *)(param_1 + 0x58);
    if (lVar1 != 0) {
      *(longlong *)(lVar1 + 0x10) = param_1;
      if (iVar4 != 0) {
        uVar9 = (uint)(lVar1 + 0x10U >> 0xc);
        uVar8 = (ulonglong)((uVar9 & 0x1fffff) >> 6);
        do {
          uVar2 = *(ulonglong *)(&DAT_182f0c920 + uVar8 * 8);
          LOCK();
          bVar10 = uVar2 == *(ulonglong *)(&DAT_182f0c920 + uVar8 * 8);
          if (bVar10) {
            *(ulonglong *)(&DAT_182f0c920 + uVar8 * 8) = uVar2 | 1L << (uVar9 & 0x3f);
          }
          UNLOCK();
        } while (!bVar10);
      }
      if (*(longlong *)(param_1 + 0x60) != 0) {
        ExposureUnnoticed2_Object3D_NPC_Script_NpcStrangenessManager__Initialize__060010bc
                  (*(longlong *)(param_1 + 0x60),param_1,0);
        if (*(longlong *)(param_1 + 0x68) != 0) {
          ExposureUnnoticed2_Object3D_NPC_Script_PlayerSearcher__Initialize__060010d1
                    (*(longlong *)(param_1 + 0x68),param_1,0);
          lVar1 = *(longlong *)(param_1 + 0x78);
          if (lVar1 != 0) {
            bVar10 = DAT_182eb5d50 != 0;
            *(longlong *)(lVar1 + 0x10) = param_1;
            if (bVar10) {
              uVar9 = (uint)(lVar1 + 0x10U >> 0xc);
              uVar8 = (ulonglong)((uVar9 & 0x1fffff) >> 6);
              do {
                uVar2 = *(ulonglong *)(&DAT_182f0c920 + uVar8 * 8);
                LOCK();
                bVar10 = uVar2 == *(ulonglong *)(&DAT_182f0c920 + uVar8 * 8);
                if (bVar10) {
                  *(ulonglong *)(&DAT_182f0c920 + uVar8 * 8) = uVar2 | 1L << (uVar9 & 0x3f);
                }
                UNLOCK();
              } while (!bVar10);
            }
            if (*(longlong *)(param_1 + 0x88) != 0) {
              ExposureUnnoticed2_Object3D_NPC_Script_NpcAnimatorFpsController__Initialize__06000fe3
                        (*(longlong *)(param_1 + 0x88),param_1,0);
              if (*(longlong *)(param_1 + 0xa0) != 0) {
                ExposureUnnoticed2_Object3D_NPC_Script_NpcAnimationManager__Initialize__06000fb6
                          (*(longlong *)(param_1 + 0xa0),param_1,0);
                lVar1 = *(longlong *)(param_1 + 0xb8);
                if (lVar1 != 0) {
                  bVar10 = DAT_182eb5d50 != 0;
                  *(longlong *)(lVar1 + 0x10) = param_1;
                  if (bVar10) {
                    uVar9 = (uint)(lVar1 + 0x10U >> 0xc);
                    uVar8 = (ulonglong)((uVar9 & 0x1fffff) >> 6);
                    do {
                      uVar2 = *(ulonglong *)(&DAT_182f0c920 + uVar8 * 8);
                      LOCK();
                      bVar10 = uVar2 == *(ulonglong *)(&DAT_182f0c920 + uVar8 * 8);
                      if (bVar10) {
                        *(ulonglong *)(&DAT_182f0c920 + uVar8 * 8) = uVar2 | 1L << (uVar9 & 0x3f);
                      }
                      UNLOCK();
                    } while (!bVar10);
                  }
                  if (*(longlong *)(param_1 + 0xc0) != 0) {
                    ExposureUnnoticed2_Object3D_NPC_Script_NpcAvatarComponent__Initialize__06000ff8
                              (*(longlong *)(param_1 + 0xc0),param_1,0);
                    lVar1 = *(longlong *)(param_1 + 200);
                    if (lVar1 != 0) {
                      if (DAT_182eb7751 == '\0') {
                        FUN_1802f2810(&DAT_182d58290);
                        LOCK();
                        UNLOCK();
                        DAT_182eb7751 = '\x01';
                      }
                      bVar10 = DAT_182eb5d50 != 0;
                      *(longlong *)(lVar1 + 0x10) = param_1;
                      if (bVar10) {
                        uVar9 = (uint)(lVar1 + 0x10U >> 0xc);
                        uVar8 = (ulonglong)((uVar9 & 0x1fffff) >> 6);
                        do {
                          uVar2 = *(ulonglong *)(&DAT_182f0c920 + uVar8 * 8);
                          LOCK();
                          bVar10 = uVar2 == *(ulonglong *)(&DAT_182f0c920 + uVar8 * 8);
                          if (bVar10) {
                            *(ulonglong *)(&DAT_182f0c920 + uVar8 * 8) =
                                 uVar2 | 1L << (uVar9 & 0x3f);
                          }
                          UNLOCK();
                        } while (!bVar10);
                      }
                      uVar7 = DAT_182d58290;
                      pcVar6 = DAT_182ec1198;
                      if ((DAT_182ec1198 == (code *)0x0) &&
                         (pcVar6 = (code *)FUN_1802cf0c0(
                                                  "UnityEngine.LayerMask::NameToLayer(System.String)"
                                                  ), pcVar6 == (code *)0x0)) {
                        uVar7 = FUN_1802ced60("UnityEngine.LayerMask::NameToLayer(System.String)");
                    /* WARNING: Subroutine does not return */
                        FUN_1802cca90(uVar7,0);
                      }
                      DAT_182ec1198 = pcVar6;
                      bVar3 = (*DAT_182ec1198)(uVar7);
                      *(int *)(lVar1 + 0x20) = 1 << (bVar3 & 0x1f);
                      iVar4 = DAT_182eb5d50;
                      lVar1 = *(longlong *)(param_1 + 0xd0);
                      if (lVar1 != 0) {
                        *(longlong *)(lVar1 + 0x10) = param_1;
                        if (iVar4 != 0) {
                          uVar9 = (uint)(lVar1 + 0x10U >> 0xc);
                          uVar8 = (ulonglong)((uVar9 & 0x1fffff) >> 6);
                          do {
                            uVar2 = *(ulonglong *)(&DAT_182f0c920 + uVar8 * 8);
                            LOCK();
                            bVar10 = uVar2 == *(ulonglong *)(&DAT_182f0c920 + uVar8 * 8);
                            if (bVar10) {
                              *(ulonglong *)(&DAT_182f0c920 + uVar8 * 8) =
                                   uVar2 | 1L << (uVar9 & 0x3f);
                            }
                            UNLOCK();
                            iVar4 = DAT_182eb5d50;
                          } while (!bVar10);
                        }
                        lVar1 = *(longlong *)(param_1 + 0xd8);
                        if (lVar1 != 0) {
                          *(longlong *)(lVar1 + 0x10) = param_1;
                          iVar5 = 0;
                          if (iVar4 != 0) {
                            uVar9 = (uint)(lVar1 + 0x10U >> 0xc);
                            uVar8 = (ulonglong)((uVar9 & 0x1fffff) >> 6);
                            do {
                              uVar2 = *(ulonglong *)(&DAT_182f0c920 + uVar8 * 8);
                              LOCK();
                              bVar10 = uVar2 == *(ulonglong *)(&DAT_182f0c920 + uVar8 * 8);
                              if (bVar10) {
                                *(ulonglong *)(&DAT_182f0c920 + uVar8 * 8) =
                                     uVar2 | 1L << (uVar9 & 0x3f);
                              }
                              UNLOCK();
                              iVar5 = DAT_182eb5d50;
                            } while (!bVar10);
                          }
                          lVar1 = *(longlong *)(param_1 + 0xe0);
                          if (lVar1 != 0) {
                            *(longlong *)(lVar1 + 0x10) = param_1;
                            iVar4 = 0;
                            if (iVar5 != 0) {
                              uVar9 = (uint)(lVar1 + 0x10U >> 0xc);
                              uVar8 = (ulonglong)((uVar9 & 0x1fffff) >> 6);
                              do {
                                uVar2 = *(ulonglong *)(&DAT_182f0c920 + uVar8 * 8);
                                LOCK();
                                bVar10 = uVar2 == *(ulonglong *)(&DAT_182f0c920 + uVar8 * 8);
                                if (bVar10) {
                                  *(ulonglong *)(&DAT_182f0c920 + uVar8 * 8) =
                                       uVar2 | 1L << (ulonglong)(uVar9 & 0x3f);
                                }
                                UNLOCK();
                                iVar4 = DAT_182eb5d50;
                              } while (!bVar10);
                            }
                            lVar1 = *(longlong *)(param_1 + 0xf0);
                            if (lVar1 != 0) {
                              *(longlong *)(lVar1 + 0x10) = param_1;
                              if (iVar4 != 0) {
                                uVar9 = (uint)(lVar1 + 0x10U >> 0xc);
                                uVar8 = (ulonglong)((uVar9 & 0x1fffff) >> 6);
                                do {
                                  uVar2 = *(ulonglong *)(&DAT_182f0c920 + uVar8 * 8);
                                  LOCK();
                                  bVar10 = uVar2 == *(ulonglong *)(&DAT_182f0c920 + uVar8 * 8);
                                  if (bVar10) {
                                    *(ulonglong *)(&DAT_182f0c920 + uVar8 * 8) =
                                         uVar2 | 1L << (ulonglong)(uVar9 & 0x3f);
                                  }
                                  UNLOCK();
                                } while (!bVar10);
                              }
                              uVar11 = ExposureUnnoticed2_Object3D_NPC_Script_State_NpcSleepFixState__CalcSleepLength__06001131
                                                 (lVar1,0);
                              *(undefined4 *)(lVar1 + 0x18) = uVar11;
                              lVar1 = *(longlong *)(param_1 + 0xf8);
                              if (lVar1 != 0) {
                                bVar10 = DAT_182eb5d50 != 0;
                                *(longlong *)(lVar1 + 0x10) = param_1;
                                if (bVar10) {
                                  uVar9 = (uint)(lVar1 + 0x10U >> 0xc);
                                  uVar8 = (ulonglong)((uVar9 & 0x1fffff) >> 6);
                                  do {
                                    uVar2 = *(ulonglong *)(&DAT_182f0c920 + uVar8 * 8);
                                    LOCK();
                                    bVar10 = uVar2 == *(ulonglong *)(&DAT_182f0c920 + uVar8 * 8);
                                    if (bVar10) {
                                      *(ulonglong *)(&DAT_182f0c920 + uVar8 * 8) =
                                           uVar2 | 1L << (uVar9 & 0x3f);
                                    }
                                    UNLOCK();
                                  } while (!bVar10);
                                }
                                if (*(longlong *)(param_1 + 0x100) != 0) {
                                  ExposureUnnoticed2_Object3D_NPC_Script_State_Toilet_NpcToiletSubState__Initialize__0600115d
                                            (*(longlong *)(param_1 + 0x100),param_1,0);
                                  lVar1 = *(longlong *)(param_1 + 0x108);
                                  if (lVar1 != 0) {
                                    bVar10 = DAT_182eb5d50 != 0;
                                    *(longlong *)(lVar1 + 0x10) = param_1;
                                    if (bVar10) {
                                      uVar9 = (uint)(lVar1 + 0x10U >> 0xc);
                                      uVar8 = (ulonglong)((uVar9 & 0x1fffff) >> 6);
                                      do {
                                        uVar2 = *(ulonglong *)(&DAT_182f0c920 + uVar8 * 8);
                                        LOCK();
                                        bVar10 = uVar2 == *(ulonglong *)(&DAT_182f0c920 + uVar8 * 8)
                                        ;
                                        if (bVar10) {
                                          *(ulonglong *)(&DAT_182f0c920 + uVar8 * 8) =
                                               uVar2 | 1L << (uVar9 & 0x3f);
                                        }
                                        UNLOCK();
                                      } while (!bVar10);
                                    }
                                    if (DAT_182eb5490 == '\0') {
                                      FUN_1802f2810(&DAT_182d59260);
                                      LOCK();
                                      UNLOCK();
                                      DAT_182eb5490 = '\x01';
                                    }
                                    bVar10 = DAT_182eb5d50 != 0;
                                    *(undefined8 *)(lVar1 + 0x20) =
                                         **(undefined8 **)(DAT_182d59260 + 0xb8);
                                    if (bVar10) {
                                      uVar9 = (uint)(lVar1 + 0x20U >> 0xc);
                                      uVar8 = (ulonglong)((uVar9 & 0x1fffff) >> 6);
                                      do {
                                        uVar2 = *(ulonglong *)(&DAT_182f0c920 + uVar8 * 8);
                                        LOCK();
                                        bVar10 = uVar2 == *(ulonglong *)(&DAT_182f0c920 + uVar8 * 8)
                                        ;
                                        if (bVar10) {
                                          *(ulonglong *)(&DAT_182f0c920 + uVar8 * 8) =
                                               uVar2 | 1L << (uVar9 & 0x3f);
                                        }
                                        UNLOCK();
                                      } while (!bVar10);
                                    }
                                    lVar1 = *(longlong *)(param_1 + 0x110);
                                    if (lVar1 != 0) {
                                      bVar10 = DAT_182eb5d50 != 0;
                                      *(longlong *)(lVar1 + 0x18) = param_1;
                                      if (bVar10) {
                                        uVar9 = (uint)(lVar1 + 0x18U >> 0xc);
                                        uVar8 = (ulonglong)((uVar9 & 0x1fffff) >> 6);
                                        do {
                                          uVar2 = *(ulonglong *)(&DAT_182f0c920 + uVar8 * 8);
                                          LOCK();
                                          bVar10 = uVar2 == *(ulonglong *)
                                                             (&DAT_182f0c920 + uVar8 * 8);
                                          if (bVar10) {
                                            *(ulonglong *)(&DAT_182f0c920 + uVar8 * 8) =
                                                 uVar2 | 1L << (uVar9 & 0x3f);
                                          }
                                          UNLOCK();
                                        } while (!bVar10);
                                      }
                                      lVar1 = *(longlong *)(param_1 + 0x118);
                                      if (lVar1 != 0) {
                                        bVar10 = DAT_182eb5d50 != 0;
                                        *(longlong *)(lVar1 + 0x10) = param_1;
                                        if (bVar10) {
                                          uVar9 = (uint)(lVar1 + 0x10U >> 0xc);
                                          uVar8 = (ulonglong)((uVar9 & 0x1fffff) >> 6);
                                          do {
                                            uVar2 = *(ulonglong *)(&DAT_182f0c920 + uVar8 * 8);
                                            LOCK();
                                            bVar10 = uVar2 == *(ulonglong *)
                                                               (&DAT_182f0c920 + uVar8 * 8);
                                            if (bVar10) {
                                              *(ulonglong *)(&DAT_182f0c920 + uVar8 * 8) =
                                                   uVar2 | 1L << (ulonglong)(uVar9 & 0x3f);
                                            }
                                            UNLOCK();
                                          } while (!bVar10);
                                        }
                                        lVar1 = *(longlong *)(param_1 + 0x120);
                                        if (lVar1 != 0) {
                                          bVar10 = DAT_182eb5d50 != 0;
                                          *(longlong *)(lVar1 + 0x10) = param_1;
                                          if (bVar10) {
                                            uVar9 = (uint)(lVar1 + 0x10U >> 0xc);
                                            uVar8 = (ulonglong)((uVar9 & 0x1fffff) >> 6);
                                            do {
                                              uVar2 = *(ulonglong *)(&DAT_182f0c920 + uVar8 * 8);
                                              LOCK();
                                              bVar10 = uVar2 == *(ulonglong *)
                                                                 (&DAT_182f0c920 + uVar8 * 8);
                                              if (bVar10) {
                                                *(ulonglong *)(&DAT_182f0c920 + uVar8 * 8) =
                                                     uVar2 | 1L << (ulonglong)(uVar9 & 0x3f);
                                              }
                                              UNLOCK();
                                            } while (!bVar10);
                                          }
                                          if (DAT_182eb5498 == '\0') {
                                            FUN_1802f2810(&DAT_182d5a900);
                                            LOCK();
                                            UNLOCK();
                                            DAT_182eb5498 = '\x01';
                                          }
                                          bVar10 = DAT_182eb5d50 != 0;
                                          *(undefined8 *)(lVar1 + 0x28) =
                                               **(undefined8 **)(DAT_182d5a900 + 0xb8);
                                          if (bVar10) {
                                            uVar9 = (uint)(lVar1 + 0x28U >> 0xc);
                                            uVar8 = (ulonglong)((uVar9 & 0x1fffff) >> 6);
                                            do {
                                              uVar2 = *(ulonglong *)(&DAT_182f0c920 + uVar8 * 8);
                                              LOCK();
                                              bVar10 = uVar2 == *(ulonglong *)
                                                                 (&DAT_182f0c920 + uVar8 * 8);
                                              if (bVar10) {
                                                *(ulonglong *)(&DAT_182f0c920 + uVar8 * 8) =
                                                     uVar2 | 1L << (uVar9 & 0x3f);
                                              }
                                              UNLOCK();
                                            } while (!bVar10);
                                          }
                                          if (*(longlong *)(param_1 + 0x128) != 0) {
                                            ExposureUnnoticed2_Object3D_NPC_Script_State_NpcTraceSexPlayerState__Initialize__06001134
                                                      (*(longlong *)(param_1 + 0x128),param_1,0);
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
          }
        }
      }
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

