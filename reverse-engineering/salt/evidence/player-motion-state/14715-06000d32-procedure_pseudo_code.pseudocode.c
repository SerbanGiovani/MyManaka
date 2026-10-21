// Ghidra pseudocode; not original source or compilable C.
// ev_0e48932100d4a276d61e62a1a9f4798af32fb9c4dae206072c968ed67e6572fa

void ExposureUnnoticed2_Object3D_Player_Scripts_PlayerClassAccessor__Initialize__06000d32
               (longlong param_1)

{
  ulonglong uVar1;
  longlong lVar2;
  undefined8 uVar3;
  longlong lVar4;
  code *pcVar5;
  int iVar6;
  int iVar7;
  ulonglong uVar8;
  uint uVar9;
  longlong lVar10;
  bool bVar11;
  undefined8 uStack_18;
  undefined4 uStack_10;
  
  iVar6 = DAT_182eb5d50;
  lVar10 = *(longlong *)(param_1 + 0x48);
  if (lVar10 != 0) {
    *(undefined8 *)(lVar10 + 0x38) = *(undefined8 *)(param_1 + 0x60);
    if (iVar6 != 0) {
      uVar9 = (uint)(lVar10 + 0x38U >> 0xc);
      uVar8 = (ulonglong)((uVar9 & 0x1fffff) >> 6);
      do {
        uVar1 = *(ulonglong *)(&DAT_182f0c920 + uVar8 * 8);
        LOCK();
        bVar11 = uVar1 == *(ulonglong *)(&DAT_182f0c920 + uVar8 * 8);
        if (bVar11) {
          *(ulonglong *)(&DAT_182f0c920 + uVar8 * 8) = uVar1 | 1L << (uVar9 & 0x3f);
        }
        UNLOCK();
        iVar6 = DAT_182eb5d50;
      } while (!bVar11);
    }
    *(undefined8 *)(lVar10 + 0x30) = *(undefined8 *)(param_1 + 0x10);
    iVar7 = 0;
    if (iVar6 != 0) {
      uVar9 = (uint)(lVar10 + 0x30U >> 0xc);
      uVar8 = (ulonglong)((uVar9 & 0x1fffff) >> 6);
      do {
        uVar1 = *(ulonglong *)(&DAT_182f0c920 + uVar8 * 8);
        LOCK();
        bVar11 = uVar1 == *(ulonglong *)(&DAT_182f0c920 + uVar8 * 8);
        if (bVar11) {
          *(ulonglong *)(&DAT_182f0c920 + uVar8 * 8) = uVar1 | 1L << (uVar9 & 0x3f);
        }
        UNLOCK();
        iVar7 = DAT_182eb5d50;
      } while (!bVar11);
    }
    if (*(longlong *)(lVar10 + 0x60) != 0) {
      *(undefined4 *)(*(longlong *)(lVar10 + 0x60) + 0x1c) = 0x3f800000;
      if (*(longlong *)(lVar10 + 0xb8) != 0) {
        *(undefined4 *)(*(longlong *)(lVar10 + 0xb8) + 0x10) = 0x3f800000;
        *(undefined4 *)(lVar10 + 0x24) = 0x3f800000;
        *(longlong *)(lVar10 + 0x40) = param_1;
        iVar6 = 0;
        if (iVar7 != 0) {
          uVar9 = (uint)(lVar10 + 0x40U >> 0xc);
          uVar8 = (ulonglong)((uVar9 & 0x1fffff) >> 6);
          do {
            uVar1 = *(ulonglong *)(&DAT_182f0c920 + uVar8 * 8);
            LOCK();
            bVar11 = uVar1 == *(ulonglong *)(&DAT_182f0c920 + uVar8 * 8);
            if (bVar11) {
              *(ulonglong *)(&DAT_182f0c920 + uVar8 * 8) = uVar1 | 1L << (uVar9 & 0x3f);
            }
            UNLOCK();
            iVar6 = DAT_182eb5d50;
          } while (!bVar11);
        }
        lVar10 = *(longlong *)(param_1 + 0xa8);
        if (lVar10 != 0) {
          *(longlong *)(lVar10 + 0x10) = param_1;
          if (iVar6 != 0) {
            uVar9 = (uint)(lVar10 + 0x10U >> 0xc);
            uVar8 = (ulonglong)((uVar9 & 0x1fffff) >> 6);
            do {
              uVar1 = *(ulonglong *)(&DAT_182f0c920 + uVar8 * 8);
              LOCK();
              bVar11 = uVar1 == *(ulonglong *)(&DAT_182f0c920 + uVar8 * 8);
              if (bVar11) {
                *(ulonglong *)(&DAT_182f0c920 + uVar8 * 8) = uVar1 | 1L << (uVar9 & 0x3f);
              }
              UNLOCK();
            } while (!bVar11);
          }
          if (*(longlong *)(param_1 + 0xb0) != 0) {
            ExposureUnnoticed2_Object3D_Player_Scripts_PlayerSoundManager__Initialize__06000e1e
                      (*(longlong *)(param_1 + 0xb0),*(undefined8 *)(param_1 + 0x40),
                       *(undefined8 *)(param_1 + 0x28),param_1,0);
            lVar10 = *(longlong *)(param_1 + 0xb8);
            if (lVar10 != 0) {
              bVar11 = DAT_182eb5d50 != 0;
              *(longlong *)(lVar10 + 0x10) = param_1;
              if (bVar11) {
                uVar9 = (uint)(lVar10 + 0x10U >> 0xc);
                uVar8 = (ulonglong)((uVar9 & 0x1fffff) >> 6);
                do {
                  uVar1 = *(ulonglong *)(&DAT_182f0c920 + uVar8 * 8);
                  LOCK();
                  bVar11 = uVar1 == *(ulonglong *)(&DAT_182f0c920 + uVar8 * 8);
                  if (bVar11) {
                    *(ulonglong *)(&DAT_182f0c920 + uVar8 * 8) =
                         uVar1 | 1L << (ulonglong)(uVar9 & 0x3f);
                  }
                  UNLOCK();
                } while (!bVar11);
              }
              lVar10 = *(longlong *)(param_1 + 0xc0);
              if (lVar10 != 0) {
                if (cRam0000000182eb83db == '\0') {
                  FUN_1802f2810(&DAT_182d58398);
                  LOCK();
                  UNLOCK();
                  cRam0000000182eb83db = '\x01';
                }
                bVar11 = DAT_182eb5d50 != 0;
                *(undefined8 *)(lVar10 + 0x10) = *(undefined8 *)(param_1 + 0x48);
                if (bVar11) {
                  uVar9 = (uint)(lVar10 + 0x10U >> 0xc);
                  uVar8 = (ulonglong)((uVar9 & 0x1fffff) >> 6);
                  do {
                    uVar1 = *(ulonglong *)(&DAT_182f0c920 + uVar8 * 8);
                    LOCK();
                    bVar11 = uVar1 == *(ulonglong *)(&DAT_182f0c920 + uVar8 * 8);
                    if (bVar11) {
                      *(ulonglong *)(&DAT_182f0c920 + uVar8 * 8) = uVar1 | 1L << (uVar9 & 0x3f);
                    }
                    UNLOCK();
                  } while (!bVar11);
                }
                bVar11 = DAT_182eb5d50 != 0;
                *(undefined8 *)(lVar10 + 0x18) = *(undefined8 *)(param_1 + 0xb0);
                if (bVar11) {
                  uVar9 = (uint)(lVar10 + 0x18U >> 0xc);
                  uVar8 = (ulonglong)((uVar9 & 0x1fffff) >> 6);
                  do {
                    uVar1 = *(ulonglong *)(&DAT_182f0c920 + uVar8 * 8);
                    LOCK();
                    bVar11 = uVar1 == *(ulonglong *)(&DAT_182f0c920 + uVar8 * 8);
                    if (bVar11) {
                      *(ulonglong *)(&DAT_182f0c920 + uVar8 * 8) = uVar1 | 1L << (uVar9 & 0x3f);
                    }
                    UNLOCK();
                  } while (!bVar11);
                }
                bVar11 = DAT_182eb5d50 != 0;
                *(longlong *)(lVar10 + 0x20) = param_1;
                if (bVar11) {
                  uVar9 = (uint)(lVar10 + 0x20U >> 0xc);
                  uVar8 = (ulonglong)((uVar9 & 0x1fffff) >> 6);
                  do {
                    uVar1 = *(ulonglong *)(&DAT_182f0c920 + uVar8 * 8);
                    LOCK();
                    bVar11 = uVar1 == *(ulonglong *)(&DAT_182f0c920 + uVar8 * 8);
                    if (bVar11) {
                      *(ulonglong *)(&DAT_182f0c920 + uVar8 * 8) = uVar1 | 1L << (uVar9 & 0x3f);
                    }
                    UNLOCK();
                  } while (!bVar11);
                }
                lVar10 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
                if ((lVar10 != 0) && (*(longlong *)(param_1 + 0x60) != 0)) {
                  *(undefined4 *)(*(longlong *)(param_1 + 0x60) + 0x20c) =
                       *(undefined4 *)(lVar10 + 0x1c8);
                  if (*(longlong *)(param_1 + 200) != 0) {
                    ExposureUnnoticed2_Object3D_Player_Scripts_MentalManager__Initialize__06000c23
                              (*(longlong *)(param_1 + 200),*(undefined8 *)(param_1 + 0x60),0);
                    lVar10 = *(longlong *)(param_1 + 0xe0);
                    if (lVar10 != 0) {
                      bVar11 = DAT_182eb5d50 != 0;
                      *(longlong *)(lVar10 + 0x20) = param_1;
                      if (bVar11) {
                        uVar9 = (uint)(lVar10 + 0x20U >> 0xc);
                        uVar8 = (ulonglong)((uVar9 & 0x1fffff) >> 6);
                        do {
                          uVar1 = *(ulonglong *)(&DAT_182f0c920 + uVar8 * 8);
                          LOCK();
                          bVar11 = uVar1 == *(ulonglong *)(&DAT_182f0c920 + uVar8 * 8);
                          if (bVar11) {
                            *(ulonglong *)(&DAT_182f0c920 + uVar8 * 8) =
                                 uVar1 | 1L << (uVar9 & 0x3f);
                          }
                          UNLOCK();
                        } while (!bVar11);
                      }
                      lVar10 = *(longlong *)(param_1 + 0xe8);
                      if (lVar10 != 0) {
                        bVar11 = DAT_182eb5d50 != 0;
                        *(longlong *)(lVar10 + 0x10) = param_1;
                        if (bVar11) {
                          uVar9 = (uint)(lVar10 + 0x10U >> 0xc);
                          uVar8 = (ulonglong)((uVar9 & 0x1fffff) >> 6);
                          do {
                            uVar1 = *(ulonglong *)(&DAT_182f0c920 + uVar8 * 8);
                            LOCK();
                            bVar11 = uVar1 == *(ulonglong *)(&DAT_182f0c920 + uVar8 * 8);
                            if (bVar11) {
                              *(ulonglong *)(&DAT_182f0c920 + uVar8 * 8) =
                                   uVar1 | 1L << (ulonglong)(uVar9 & 0x3f);
                            }
                            UNLOCK();
                          } while (!bVar11);
                        }
                        lVar10 = *(longlong *)(param_1 + 0xf0);
                        if (lVar10 != 0) {
                          if (cRam0000000182eb8410 == '\0') {
                            FUN_1802f2810(&DAT_182d58398);
                            LOCK();
                            UNLOCK();
                            cRam0000000182eb8410 = '\x01';
                          }
                          bVar11 = DAT_182eb5d50 != 0;
                          *(longlong *)(lVar10 + 0x10) = param_1;
                          if (bVar11) {
                            uVar9 = (uint)(lVar10 + 0x10U >> 0xc);
                            uVar8 = (ulonglong)((uVar9 & 0x1fffff) >> 6);
                            do {
                              uVar1 = *(ulonglong *)(&DAT_182f0c920 + uVar8 * 8);
                              LOCK();
                              bVar11 = uVar1 == *(ulonglong *)(&DAT_182f0c920 + uVar8 * 8);
                              if (bVar11) {
                                *(ulonglong *)(&DAT_182f0c920 + uVar8 * 8) =
                                     uVar1 | 1L << (uVar9 & 0x3f);
                              }
                              UNLOCK();
                            } while (!bVar11);
                          }
                          lVar4 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
                          if ((lVar4 != 0) && (*(longlong *)(param_1 + 0x48) != 0)) {
                            ExposureUnnoticed2_Object3D_Player_Scripts_PlayerAnimationManager__SetHandcuffs__06000c89
                                      (*(longlong *)(param_1 + 0x48),*(undefined1 *)(lVar4 + 0x1a8),
                                       0);
                            lVar4 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
                            if (lVar4 != 0) {
                              if (*(char *)(lVar4 + 0x1a8) != '\0') {
                                *(undefined1 *)(lVar10 + 0x2c) = 1;
                              }
                              lVar4 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
                              if (lVar4 != 0) {
                                if (*(char *)(lVar4 + 0x1a9) != '\0') {
                                  *(undefined1 *)(lVar10 + 0x2d) = 1;
                                }
                                if (*(longlong *)(param_1 + 0xf8) != 0) {
                                  ExposureUnnoticed2_Object3D_Player_Scripts_PlayerReceiveShadowChanger__Initialize__06000e06
                                            (*(longlong *)(param_1 + 0xf8),param_1,0);
                                  lVar10 = *(longlong *)(param_1 + 0x1c8);
                                  if (lVar10 != 0) {
                                    bVar11 = DAT_182eb5d50 != 0;
                                    *(longlong *)(lVar10 + 0x10) = param_1;
                                    if (bVar11) {
                                      uVar9 = (uint)(lVar10 + 0x10U >> 0xc);
                                      uVar8 = (ulonglong)((uVar9 & 0x1fffff) >> 6);
                                      do {
                                        uVar1 = *(ulonglong *)(&DAT_182f0c920 + uVar8 * 8);
                                        LOCK();
                                        bVar11 = uVar1 == *(ulonglong *)(&DAT_182f0c920 + uVar8 * 8)
                                        ;
                                        if (bVar11) {
                                          *(ulonglong *)(&DAT_182f0c920 + uVar8 * 8) =
                                               uVar1 | 1L << (uVar9 & 0x3f);
                                        }
                                        UNLOCK();
                                      } while (!bVar11);
                                    }
                                    if (*(longlong *)(param_1 + 0x100) != 0) {
                                      ExposureUnnoticed2_Object3D_Player_Scripts_PlayerAdultGoodsController__Initialize__06000c3e
                                                (*(longlong *)(param_1 + 0x100),param_1,0);
                                      if (*(longlong *)(param_1 + 0x108) != 0) {
                                        ExposureUnnoticed2_Object3D_Player_Scripts_PlayerToeHeelController__Initialize__06000e45
                                                  (*(longlong *)(param_1 + 0x108),param_1,0);
                                        if (*(longlong *)(param_1 + 0x120) != 0) {
                                          ExposureUnnoticed2_Object3D_Player_Scripts_LookAtController__InitializeForPlayer__06000c13
                                                    (*(longlong *)(param_1 + 0x120),param_1,0);
                                          lVar10 = *(longlong *)(param_1 + 0x128);
                                          if (lVar10 != 0) {
                                            if (cRam0000000182eb8400 == '\0') {
                                              FUN_1802f2810(&DAT_182d58300);
                                              LOCK();
                                              UNLOCK();
                                              FUN_1802f2810(&DAT_182d582e8);
                                              LOCK();
                                              UNLOCK();
                                              FUN_1802f2810(&DAT_182d583a0);
                                              LOCK();
                                              UNLOCK();
                                              FUN_1802f2810(0x182d3e648);
                                              LOCK();
                                              UNLOCK();
                                              cRam0000000182eb8400 = '\x01';
                                            }
                                            bVar11 = DAT_182eb5d50 != 0;
                                            *(longlong *)(lVar10 + 0x10) = param_1;
                                            if (bVar11) {
                                              uVar9 = (uint)(lVar10 + 0x10U >> 0xc);
                                              uVar8 = (ulonglong)((uVar9 & 0x1fffff) >> 6);
                                              do {
                                                uVar1 = *(ulonglong *)(&DAT_182f0c920 + uVar8 * 8);
                                                LOCK();
                                                bVar11 = uVar1 == *(ulonglong *)
                                                                   (&DAT_182f0c920 + uVar8 * 8);
                                                if (bVar11) {
                                                  *(ulonglong *)(&DAT_182f0c920 + uVar8 * 8) =
                                                       uVar1 | 1L << (uVar9 & 0x3f);
                                                }
                                                UNLOCK();
                                              } while (!bVar11);
                                            }
                                            uVar3 = FUN_1802c43a0(DAT_182d58300);
                                            FUN_180665bb0(uVar3,lVar10,uRam0000000182d3e648,0);
                                            if (*(int *)(DAT_182d583a0 + 0xe0) == 0) {
                                              FUN_18035c820();
                                            }
                                            FUN_180993250(uVar3,0,DAT_182d582e8);
                                            lVar10 = *(longlong *)(param_1 + 0x130);
                                            if (lVar10 != 0) {
                                              bVar11 = DAT_182eb5d50 != 0;
                                              *(longlong *)(lVar10 + 0x10) = param_1;
                                              if (bVar11) {
                                                uVar9 = (uint)(lVar10 + 0x10U >> 0xc);
                                                uVar8 = (ulonglong)((uVar9 & 0x1fffff) >> 6);
                                                do {
                                                  uVar1 = *(ulonglong *)(&DAT_182f0c920 + uVar8 * 8)
                                                  ;
                                                  LOCK();
                                                  bVar11 = uVar1 == *(ulonglong *)
                                                                     (&DAT_182f0c920 + uVar8 * 8);
                                                  if (bVar11) {
                                                    *(ulonglong *)(&DAT_182f0c920 + uVar8 * 8) =
                                                         uVar1 | 1L << (ulonglong)(uVar9 & 0x3f);
                                                  }
                                                  UNLOCK();
                                                } while (!bVar11);
                                              }
                                              lVar10 = *(longlong *)(param_1 + 0x138);
                                              if (lVar10 != 0) {
                                                if (cRam0000000182eb8452 == '\0') {
                                                  FUN_1802f2810(0x182d582c0);
                                                  LOCK();
                                                  UNLOCK();
                                                  FUN_1802f2810(0x182d582b0);
                                                  LOCK();
                                                  UNLOCK();
                                                  FUN_1802f2810(&DAT_182d583a0);
                                                  LOCK();
                                                  UNLOCK();
                                                  FUN_1802f2810(0x182d3edc0);
                                                  LOCK();
                                                  UNLOCK();
                                                  cRam0000000182eb8452 = '\x01';
                                                }
                                                bVar11 = DAT_182eb5d50 != 0;
                                                *(longlong *)(lVar10 + 0x10) = param_1;
                                                if (bVar11) {
                                                  uVar9 = (uint)(lVar10 + 0x10U >> 0xc);
                                                  uVar8 = (ulonglong)((uVar9 & 0x1fffff) >> 6);
                                                  do {
                                                    uVar1 = *(ulonglong *)
                                                             (&DAT_182f0c920 + uVar8 * 8);
                                                    LOCK();
                                                    bVar11 = uVar1 == *(ulonglong *)
                                                                       (&DAT_182f0c920 + uVar8 * 8);
                                                    if (bVar11) {
                                                      *(ulonglong *)(&DAT_182f0c920 + uVar8 * 8) =
                                                           uVar1 | 1L << (uVar9 & 0x3f);
                                                    }
                                                    UNLOCK();
                                                  } while (!bVar11);
                                                }
                                                lVar4 = 
                                                  ExposureUnnoticed2_Master_Common_MCommon__get_Instance__0600133e
                                                            (0);
                                                if (lVar4 != 0) {
                                                  *(undefined1 *)(lVar4 + 0xd4) = 0;
                                                  uVar3 = FUN_1802c43a0(uRam0000000182d582c0);
                                                  FUN_180665bb0(uVar3,lVar10,uRam0000000182d3edc0,0)
                                                  ;
                                                  if (*(int *)(DAT_182d583a0 + 0xe0) == 0) {
                                                    FUN_18035c820();
                                                  }
                                                  FUN_180993250(uVar3,0,uRam0000000182d582b0);
                                                  if (*(longlong *)(param_1 + 0x140) != 0) {
                                                                                                        
                                                  ExposureUnnoticed2_Object3D_Player_Scripts_PlayerFaceShadowOnlyController__Initialize__06000db9
                                                            (*(longlong *)(param_1 + 0x140),param_1,
                                                             0);
                                                  iVar6 = DAT_182eb5d50;
                                                  lVar10 = *(longlong *)(param_1 + 0x148);
                                                  if (lVar10 != 0) {
                                                    *(longlong *)(lVar10 + 0x10) = param_1;
                                                    if (iVar6 != 0) {
                                                      uVar9 = (uint)(lVar10 + 0x10U >> 0xc);
                                                      uVar8 = (ulonglong)((uVar9 & 0x1fffff) >> 6);
                                                      do {
                                                        uVar1 = *(ulonglong *)
                                                                 (&DAT_182f0c920 + uVar8 * 8);
                                                        LOCK();
                                                        bVar11 = uVar1 == *(ulonglong *)
                                                                           (&DAT_182f0c920 +
                                                                           uVar8 * 8);
                                                        if (bVar11) {
                                                          *(ulonglong *)(&DAT_182f0c920 + uVar8 * 8)
                                                               = uVar1 | 1L << (uVar9 & 0x3f);
                                                        }
                                                        UNLOCK();
                                                        iVar6 = DAT_182eb5d50;
                                                      } while (!bVar11);
                                                    }
                                                    lVar10 = *(longlong *)(param_1 + 0x150);
                                                    if (lVar10 != 0) {
                                                      *(longlong *)(lVar10 + 0x10) = param_1;
                                                      if (iVar6 != 0) {
                                                        uVar9 = (uint)(lVar10 + 0x10U >> 0xc);
                                                        uVar8 = (ulonglong)((uVar9 & 0x1fffff) >> 6)
                                                        ;
                                                        do {
                                                          uVar1 = *(ulonglong *)
                                                                   (&DAT_182f0c920 + uVar8 * 8);
                                                          LOCK();
                                                          bVar11 = uVar1 == *(ulonglong *)
                                                                             (&DAT_182f0c920 +
                                                                             uVar8 * 8);
                                                          if (bVar11) {
                                                            *(ulonglong *)
                                                             (&DAT_182f0c920 + uVar8 * 8) =
                                                                 uVar1 | 1L << (ulonglong)
                                                                               (uVar9 & 0x3f);
                                                          }
                                                          UNLOCK();
                                                        } while (!bVar11);
                                                      }
                                                      lVar10 = *(longlong *)(param_1 + 0x158);
                                                      if (lVar10 != 0) {
                                                        if (cRam0000000182eb83f3 == '\0') {
                                                          FUN_1802f2810(&DAT_182d58230);
                                                          LOCK();
                                                          UNLOCK();
                                                          cRam0000000182eb83f3 = '\x01';
                                                        }
                                                        **(longlong **)(DAT_182d58230 + 0xb8) =
                                                             lVar10;
                                                        if (DAT_182eb5d50 != 0) {
                                                          uVar9 = (uint)(*(ulonglong *)
                                                                          (DAT_182d58230 + 0xb8) >>
                                                                        0xc);
                                                          uVar8 = (ulonglong)
                                                                  ((uVar9 & 0x1fffff) >> 6);
                                                          do {
                                                            uVar1 = *(ulonglong *)
                                                                     (&DAT_182f0c920 + uVar8 * 8);
                                                            LOCK();
                                                            bVar11 = uVar1 == *(ulonglong *)
                                                                               (&DAT_182f0c920 +
                                                                               uVar8 * 8);
                                                            if (bVar11) {
                                                              *(ulonglong *)
                                                               (&DAT_182f0c920 + uVar8 * 8) =
                                                                   uVar1 | 1L << (ulonglong)
                                                                                 (uVar9 & 0x3f);
                                                            }
                                                            UNLOCK();
                                                          } while (!bVar11);
                                                        }
                                                        bVar11 = DAT_182eb5d50 != 0;
                                                        *(longlong *)(lVar10 + 0x10) = param_1;
                                                        if (bVar11) {
                                                          uVar9 = (uint)(lVar10 + 0x10U >> 0xc);
                                                          uVar8 = (ulonglong)
                                                                  ((uVar9 & 0x1fffff) >> 6);
                                                          do {
                                                            uVar1 = *(ulonglong *)
                                                                     (&DAT_182f0c920 + uVar8 * 8);
                                                            LOCK();
                                                            bVar11 = uVar1 == *(ulonglong *)
                                                                               (&DAT_182f0c920 +
                                                                               uVar8 * 8);
                                                            if (bVar11) {
                                                              *(ulonglong *)
                                                               (&DAT_182f0c920 + uVar8 * 8) =
                                                                   uVar1 | 1L << (ulonglong)
                                                                                 (uVar9 & 0x3f);
                                                            }
                                                            UNLOCK();
                                                          } while (!bVar11);
                                                        }
                                                        lVar10 = *(longlong *)(param_1 + 0x98);
                                                        if (lVar10 != 0) {
                                                          if (cRam0000000182eb8418 == '\0') {
                                                            FUN_1802f2810(&DAT_182d58398);
                                                            LOCK();
                                                            UNLOCK();
                                                            cRam0000000182eb8418 = '\x01';
                                                          }
                                                          bVar11 = DAT_182eb5d50 != 0;
                                                          *(longlong *)(lVar10 + 0x10) = param_1;
                                                          if (bVar11) {
                                                            uVar9 = (uint)(lVar10 + 0x10U >> 0xc);
                                                            uVar8 = (ulonglong)
                                                                    ((uVar9 & 0x1fffff) >> 6);
                                                            do {
                                                              uVar1 = *(ulonglong *)
                                                                       (&DAT_182f0c920 + uVar8 * 8);
                                                              LOCK();
                                                              bVar11 = uVar1 == *(ulonglong *)
                                                                                 (&DAT_182f0c920 +
                                                                                 uVar8 * 8);
                                                              if (bVar11) {
                                                                *(ulonglong *)
                                                                 (&DAT_182f0c920 + uVar8 * 8) =
                                                                     uVar1 | 1L << (ulonglong)
                                                                                   (uVar9 & 0x3f);
                                                              }
                                                              UNLOCK();
                                                            } while (!bVar11);
                                                          }
                                                          lVar4 = *(longlong *)
                                                                   (*(longlong *)
                                                                     (DAT_182d58398 + 0xb8) + 0x48);
                                                          if (lVar4 != 0) {
                                                            if (*(int *)(lVar4 + 0x1a4) != -1) {
                                                                                                                            
                                                  ExposureUnnoticed2_Object3D_Player_Scripts_PlayerHoldInHand__Hold__06000ddb
                                                            (lVar10,*(undefined4 *)(lVar4 + 0x1a4),1
                                                             ,0);
                                                  }
                                                  lVar10 = *(longlong *)(param_1 + 0x90);
                                                  if (lVar10 != 0) {
                                                    if (cRam0000000182eb840d == '\0') {
                                                      FUN_1802f2810(&DAT_182d58398);
                                                      LOCK();
                                                      UNLOCK();
                                                      cRam0000000182eb840d = '\x01';
                                                    }
                                                    bVar11 = DAT_182eb5d50 != 0;
                                                    *(longlong *)(lVar10 + 0x10) = param_1;
                                                    if (bVar11) {
                                                      uVar9 = (uint)(lVar10 + 0x10U >> 0xc);
                                                      uVar8 = (ulonglong)((uVar9 & 0x1fffff) >> 6);
                                                      do {
                                                        uVar1 = *(ulonglong *)
                                                                 (&DAT_182f0c920 + uVar8 * 8);
                                                        LOCK();
                                                        bVar11 = uVar1 == *(ulonglong *)
                                                                           (&DAT_182f0c920 +
                                                                           uVar8 * 8);
                                                        if (bVar11) {
                                                          *(ulonglong *)(&DAT_182f0c920 + uVar8 * 8)
                                                               = uVar1 | 1L << (uVar9 & 0x3f);
                                                        }
                                                        UNLOCK();
                                                      } while (!bVar11);
                                                    }
                                                    lVar4 = *(longlong *)
                                                             (*(longlong *)(DAT_182d58398 + 0xb8) +
                                                             0x60);
                                                    if (lVar4 != 0) {
                                                      if (*(int *)(lVar4 + 0x104) != 0) {
                                                        if ((*(longlong *)(param_1 + 0x70) == 0) ||
                                                           (lVar4 = *(longlong *)
                                                                     (*(longlong *)(param_1 + 0x70)
                                                                     + 0x280), lVar4 == 0))
                                                        goto code_r0x00018063f6be;
                                                        if (*(int *)(lVar4 + 0x18) == 0) {
                    /* WARNING: Subroutine does not return */
                                                          FUN_18031dae0();
                                                        }
                                                        lVar4 = *(longlong *)(lVar4 + 0x20);
                                                        if (lVar4 == 0) goto code_r0x00018063f6be;
                                                        pcVar5 = DAT_182ec1138;
                                                        if ((DAT_182ec1138 == (code *)0x0) &&
                                                           (pcVar5 = (code *)FUN_1802cf0c0(
                                                  "UnityEngine.GameObject::SetActive(System.Boolean)"
                                                  ), pcVar5 == (code *)0x0)) {
                                                    uVar3 = FUN_1802ced60(
                                                  "UnityEngine.GameObject::SetActive(System.Boolean)"
                                                  );
                    /* WARNING: Subroutine does not return */
                                                  FUN_1802cca90(uVar3,0);
                                                  }
                                                  DAT_182ec1138 = pcVar5;
                                                  (*DAT_182ec1138)(lVar4,0);
                                                  lVar4 = *(longlong *)
                                                           (*(longlong *)(DAT_182d58398 + 0xb8) +
                                                           0x60);
                                                  if (lVar4 == 0) goto code_r0x00018063f6be;
                                                  ExposureUnnoticed2_Object3D_Player_Scripts_PlayerHairController__ChangeHair__06000dc2
                                                            (lVar10,*(undefined4 *)(lVar4 + 0x104),0
                                                            );
                                                  }
                                                  lVar10 = *(longlong *)(param_1 + 0x160);
                                                  if (lVar10 != 0) {
                                                    bVar11 = DAT_182eb5d50 != 0;
                                                    *(longlong *)(lVar10 + 0x18) = param_1;
                                                    if (bVar11) {
                                                      uVar9 = (uint)(lVar10 + 0x18U >> 0xc);
                                                      uVar8 = (ulonglong)((uVar9 & 0x1fffff) >> 6);
                                                      do {
                                                        uVar1 = *(ulonglong *)
                                                                 (&DAT_182f0c920 + uVar8 * 8);
                                                        LOCK();
                                                        bVar11 = uVar1 == *(ulonglong *)
                                                                           (&DAT_182f0c920 +
                                                                           uVar8 * 8);
                                                        if (bVar11) {
                                                          *(ulonglong *)(&DAT_182f0c920 + uVar8 * 8)
                                                               = uVar1 | 1L << (uVar9 & 0x3f);
                                                        }
                                                        UNLOCK();
                                                      } while (!bVar11);
                                                    }
                                                    bVar11 = DAT_182eb5d50 != 0;
                                                    *(undefined8 *)(lVar10 + 0x10) =
                                                         *(undefined8 *)(param_1 + 0x60);
                                                    if (bVar11) {
                                                      uVar9 = (uint)(lVar10 + 0x10U >> 0xc);
                                                      uVar8 = (ulonglong)((uVar9 & 0x1fffff) >> 6);
                                                      do {
                                                        uVar1 = *(ulonglong *)
                                                                 (&DAT_182f0c920 + uVar8 * 8);
                                                        LOCK();
                                                        bVar11 = uVar1 == *(ulonglong *)
                                                                           (&DAT_182f0c920 +
                                                                           uVar8 * 8);
                                                        if (bVar11) {
                                                          *(ulonglong *)(&DAT_182f0c920 + uVar8 * 8)
                                                               = uVar1 | 1L << (uVar9 & 0x3f);
                                                        }
                                                        UNLOCK();
                                                      } while (!bVar11);
                                                    }
                                                    if (*(longlong *)(param_1 + 0x80) != 0) {
                                                                                                            
                                                  ExposureUnnoticed2_Object3D_Player_Scripts_PlayerClothes__Initialize__06000d36
                                                            (*(longlong *)(param_1 + 0x80),param_1,0
                                                            );
                                                  if (*(longlong *)(param_1 + 0x168) != 0) {
                                                                                                        
                                                  ExposureUnnoticed2_Object3D_Player_Scripts_PlayerAnimationReceiver__Initialize__06000c44
                                                            (*(longlong *)(param_1 + 0x168),param_1,
                                                             0);
                                                  iVar6 = DAT_182eb5d50;
                                                  lVar10 = *(longlong *)(param_1 + 0x68);
                                                  if (lVar10 != 0) {
                                                    *(longlong *)(lVar10 + 0x30) = param_1;
                                                    if (iVar6 != 0) {
                                                      uVar9 = (uint)(lVar10 + 0x30U >> 0xc);
                                                      uVar8 = (ulonglong)((uVar9 & 0x1fffff) >> 6);
                                                      do {
                                                        uVar1 = *(ulonglong *)
                                                                 (&DAT_182f0c920 + uVar8 * 8);
                                                        LOCK();
                                                        bVar11 = uVar1 == *(ulonglong *)
                                                                           (&DAT_182f0c920 +
                                                                           uVar8 * 8);
                                                        if (bVar11) {
                                                          *(ulonglong *)(&DAT_182f0c920 + uVar8 * 8)
                                                               = uVar1 | 1L << (uVar9 & 0x3f);
                                                        }
                                                        UNLOCK();
                                                        iVar6 = DAT_182eb5d50;
                                                      } while (!bVar11);
                                                    }
                                                    *(undefined8 *)(lVar10 + 0x20) =
                                                         *(undefined8 *)(param_1 + 0x48);
                                                    iVar7 = 0;
                                                    if (iVar6 != 0) {
                                                      uVar9 = (uint)(lVar10 + 0x20U >> 0xc);
                                                      uVar8 = (ulonglong)((uVar9 & 0x1fffff) >> 6);
                                                      do {
                                                        uVar1 = *(ulonglong *)
                                                                 (&DAT_182f0c920 + uVar8 * 8);
                                                        LOCK();
                                                        bVar11 = uVar1 == *(ulonglong *)
                                                                           (&DAT_182f0c920 +
                                                                           uVar8 * 8);
                                                        if (bVar11) {
                                                          *(ulonglong *)(&DAT_182f0c920 + uVar8 * 8)
                                                               = uVar1 | 1L << (uVar9 & 0x3f);
                                                        }
                                                        UNLOCK();
                                                        iVar7 = DAT_182eb5d50;
                                                      } while (!bVar11);
                                                    }
                                                    *(undefined8 *)(lVar10 + 0x28) =
                                                         *(undefined8 *)(param_1 + 0x60);
                                                    if (iVar7 != 0) {
                                                      uVar9 = (uint)(lVar10 + 0x28U >> 0xc);
                                                      uVar8 = (ulonglong)((uVar9 & 0x1fffff) >> 6);
                                                      do {
                                                        uVar1 = *(ulonglong *)
                                                                 (&DAT_182f0c920 + uVar8 * 8);
                                                        LOCK();
                                                        bVar11 = uVar1 == *(ulonglong *)
                                                                           (&DAT_182f0c920 +
                                                                           uVar8 * 8);
                                                        if (bVar11) {
                                                          *(ulonglong *)(&DAT_182f0c920 + uVar8 * 8)
                                                               = uVar1 | 1L << (uVar9 & 0x3f);
                                                        }
                                                        UNLOCK();
                                                      } while (!bVar11);
                                                    }
                                                    lVar10 = *(longlong *)(param_1 + 0x60);
                                                    if (lVar10 != 0) {
                                                      if (cRam0000000182eb8448 == '\0') {
                                                        FUN_1802f2810(&DAT_182d58398);
                                                        LOCK();
                                                        UNLOCK();
                                                        cRam0000000182eb8448 = '\x01';
                                                      }
                                                      lVar4 = *(longlong *)
                                                               (*(longlong *)(DAT_182d58398 + 0xb8)
                                                               + 0x48);
                                                      if (lVar4 != 0) {
                                                        uVar3 = 
                                                  ExposureUnnoticed2_Master_Clothes_MClothes__Get__06001343
                                                            (*(undefined4 *)(lVar4 + 0x19c),0);
                                                  bVar11 = DAT_182eb5d50 != 0;
                                                  *(undefined8 *)(lVar10 + 0x10) = uVar3;
                                                  if (bVar11) {
                                                    uVar9 = (uint)(lVar10 + 0x10U >> 0xc);
                                                    uVar8 = (ulonglong)((uVar9 & 0x1fffff) >> 6);
                                                    do {
                                                      uVar1 = *(ulonglong *)
                                                               (&DAT_182f0c920 + uVar8 * 8);
                                                      LOCK();
                                                      bVar11 = uVar1 == *(ulonglong *)
                                                                         (&DAT_182f0c920 + uVar8 * 8
                                                                         );
                                                      if (bVar11) {
                                                        *(ulonglong *)(&DAT_182f0c920 + uVar8 * 8) =
                                                             uVar1 | 1L << (uVar9 & 0x3f);
                                                      }
                                                      UNLOCK();
                                                    } while (!bVar11);
                                                  }
                                                  lVar4 = *(longlong *)
                                                           (*(longlong *)(DAT_182d58398 + 0xb8) +
                                                           0x48);
                                                  if (lVar4 != 0) {
                                                    uVar3 = 
                                                  ExposureUnnoticed2_Master_Rank_MRank__CalcCurrentRank__06001261
                                                            ((double)*(int *)(lVar4 + 0x1e8),0);
                                                  iVar6 = DAT_182eb5d50;
                                                  *(undefined8 *)(lVar10 + 0x128) = uVar3;
                                                  if (iVar6 != 0) {
                                                    uVar9 = (uint)(lVar10 + 0x128U >> 0xc);
                                                    uVar8 = (ulonglong)((uVar9 & 0x1fffff) >> 6);
                                                    do {
                                                      uVar1 = *(ulonglong *)
                                                               (&DAT_182f0c920 + uVar8 * 8);
                                                      LOCK();
                                                      bVar11 = uVar1 == *(ulonglong *)
                                                                         (&DAT_182f0c920 + uVar8 * 8
                                                                         );
                                                      if (bVar11) {
                                                        *(ulonglong *)(&DAT_182f0c920 + uVar8 * 8) =
                                                             uVar1 | 1L << (uVar9 & 0x3f);
                                                      }
                                                      UNLOCK();
                                                      iVar6 = DAT_182eb5d50;
                                                    } while (!bVar11);
                                                  }
                                                  lVar10 = *(longlong *)(param_1 + 0x188);
                                                  if (lVar10 != 0) {
                                                    *(undefined8 *)(lVar10 + 0x18) =
                                                         *(undefined8 *)(param_1 + 0x60);
                                                    if (iVar6 != 0) {
                                                      uVar9 = (uint)(lVar10 + 0x18U >> 0xc);
                                                      uVar8 = (ulonglong)((uVar9 & 0x1fffff) >> 6);
                                                      do {
                                                        uVar1 = *(ulonglong *)
                                                                 (&DAT_182f0c920 + uVar8 * 8);
                                                        LOCK();
                                                        bVar11 = uVar1 == *(ulonglong *)
                                                                           (&DAT_182f0c920 +
                                                                           uVar8 * 8);
                                                        if (bVar11) {
                                                          *(ulonglong *)(&DAT_182f0c920 + uVar8 * 8)
                                                               = uVar1 | 1L << (ulonglong)
                                                                               (uVar9 & 0x3f);
                                                        }
                                                        UNLOCK();
                                                      } while (!bVar11);
                                                    }
                                                    lVar10 = *(longlong *)(param_1 + 0x1d0);
                                                    if (lVar10 != 0) {
                                                      if (cRam0000000182eb83bf == '\0') {
                                                        FUN_1802f2810(&DAT_182d58368);
                                                        LOCK();
                                                        UNLOCK();
                                                        FUN_1802f2810(0x182d3e990);
                                                        LOCK();
                                                        UNLOCK();
                                                        FUN_1802f2810(0x182d3e988);
                                                        LOCK();
                                                        UNLOCK();
                                                        cRam0000000182eb83bf = '\x01';
                                                      }
                                                      lVar4 = FUN_1802c43a0(uRam0000000182d3e988);
                                                      iVar6 = DAT_182eb5d50;
                                                      if (lVar4 != 0) {
                                                        *(longlong *)(lVar4 + 0x10) = lVar10;
                                                        if (iVar6 != 0) {
                                                          uVar9 = (uint)(lVar4 + 0x10U >> 0xc);
                                                          uVar8 = (ulonglong)
                                                                  ((uVar9 & 0x1fffff) >> 6);
                                                          do {
                                                            uVar1 = *(ulonglong *)
                                                                     (&DAT_182f0c920 + uVar8 * 8);
                                                            LOCK();
                                                            bVar11 = uVar1 == *(ulonglong *)
                                                                               (&DAT_182f0c920 +
                                                                               uVar8 * 8);
                                                            if (bVar11) {
                                                              *(ulonglong *)
                                                               (&DAT_182f0c920 + uVar8 * 8) =
                                                                   uVar1 | 1L << (uVar9 & 0x3f);
                                                            }
                                                            UNLOCK();
                                                            iVar6 = DAT_182eb5d50;
                                                          } while (!bVar11);
                                                        }
                                                        *(longlong *)(lVar4 + 0x18) = param_1;
                                                        iVar7 = 0;
                                                        if (iVar6 != 0) {
                                                          uVar9 = (uint)(lVar4 + 0x18U >> 0xc);
                                                          uVar8 = (ulonglong)
                                                                  ((uVar9 & 0x1fffff) >> 6);
                                                          do {
                                                            uVar1 = *(ulonglong *)
                                                                     (&DAT_182f0c920 + uVar8 * 8);
                                                            LOCK();
                                                            bVar11 = uVar1 == *(ulonglong *)
                                                                               (&DAT_182f0c920 +
                                                                               uVar8 * 8);
                                                            if (bVar11) {
                                                              *(ulonglong *)
                                                               (&DAT_182f0c920 + uVar8 * 8) =
                                                                   uVar1 | 1L << (uVar9 & 0x3f);
                                                            }
                                                            UNLOCK();
                                                            iVar7 = DAT_182eb5d50;
                                                          } while (!bVar11);
                                                        }
                                                        *(undefined8 *)(lVar10 + 0x10) =
                                                             *(undefined8 *)(lVar4 + 0x18);
                                                        if (iVar7 != 0) {
                                                          uVar9 = (uint)(lVar10 + 0x10U >> 0xc);
                                                          uVar8 = (ulonglong)
                                                                  ((uVar9 & 0x1fffff) >> 6);
                                                          do {
                                                            uVar1 = *(ulonglong *)
                                                                     (&DAT_182f0c920 + uVar8 * 8);
                                                            LOCK();
                                                            bVar11 = uVar1 == *(ulonglong *)
                                                                               (&DAT_182f0c920 +
                                                                               uVar8 * 8);
                                                            if (bVar11) {
                                                              *(ulonglong *)
                                                               (&DAT_182f0c920 + uVar8 * 8) =
                                                                   uVar1 | 1L << (uVar9 & 0x3f);
                                                            }
                                                            UNLOCK();
                                                          } while (!bVar11);
                                                        }
                                                        uVar3 = FUN_1802c43a0(DAT_182d58368);
                                                        FUN_1814df680(uVar3,lVar4,
                                                                      uRam0000000182d3e990,0);
                                                                                                                
                                                  ExposureUnnoticed2_Scripts_Base_Scheduler__DelayFlame__0600174b
                                                            (uVar3,1,0);
                                                  if (*(longlong *)(param_1 + 0x1d8) != 0) {
                                                                                                        
                                                  ExposureUnnoticed2_Object3D_Player_Scripts_Other_FutanariController__Initialize__06000e87
                                                            (*(longlong *)(param_1 + 0x1d8),param_1,
                                                             0);
                                                  lVar10 = *(longlong *)(param_1 + 0x1e8);
                                                  if (lVar10 != 0) {
                                                    if (cRam0000000182eb7657 == '\0') {
                                                      FUN_1802f2810(&DAT_182d58398);
                                                      LOCK();
                                                      UNLOCK();
                                                      cRam0000000182eb7657 = '\x01';
                                                    }
                                                    bVar11 = DAT_182eb5d50 != 0;
                                                    *(longlong *)(lVar10 + 0x18) = param_1;
                                                    if (bVar11) {
                                                      uVar9 = (uint)(lVar10 + 0x18U >> 0xc);
                                                      uVar8 = (ulonglong)((uVar9 & 0x1fffff) >> 6);
                                                      do {
                                                        uVar1 = *(ulonglong *)
                                                                 (&DAT_182f0c920 + uVar8 * 8);
                                                        LOCK();
                                                        bVar11 = uVar1 == *(ulonglong *)
                                                                           (&DAT_182f0c920 +
                                                                           uVar8 * 8);
                                                        if (bVar11) {
                                                          *(ulonglong *)(&DAT_182f0c920 + uVar8 * 8)
                                                               = uVar1 | 1L << (uVar9 & 0x3f);
                                                        }
                                                        UNLOCK();
                                                      } while (!bVar11);
                                                    }
                                                    lVar4 = *(longlong *)
                                                             (*(longlong *)(DAT_182d58398 + 0xb8) +
                                                             0x48);
                                                    if (lVar4 != 0) {
                                                      if (*(float *)(lVar4 + 0x17c) <= 0.0) {
                                                        *(undefined4 *)(lVar10 + 0x20) = 0;
                                                        if (*(longlong *)(lVar10 + 0x10) == 0)
                                                        goto code_r0x00018063f6be;
                                                        *(undefined4 *)
                                                         (*(longlong *)(lVar10 + 0x10) + 0x10) =
                                                             0xbf800000;
                                                      }
                                                      else if (*(float *)(lVar4 + 0x17c) <= 24.0) {
                                                        *(undefined4 *)(lVar10 + 0x20) = 4;
                                                        if (*(longlong *)(lVar10 + 0x10) == 0)
                                                        goto code_r0x00018063f6be;
                                                        *(undefined4 *)
                                                         (*(longlong *)(lVar10 + 0x10) + 0x10) = 0;
                                                      }
                                                      else {
                                                        lVar2 = *(longlong *)(lVar10 + 0x10);
                                                        if (*(float *)(lVar4 + 0x17c) <= 60.0) {
                                                          *(undefined4 *)(lVar10 + 0x20) = 3;
                                                          if (lVar2 == 0) goto code_r0x00018063f6be;
                                                          *(undefined4 *)(lVar2 + 0x10) = 0x3e800000
                                                          ;
                                                        }
                                                        else {
                                                          *(undefined4 *)(lVar10 + 0x20) = 2;
                                                          if (lVar2 == 0) goto code_r0x00018063f6be;
                                                          *(undefined4 *)(lVar2 + 0x10) = 0x3ecccccd
                                                          ;
                                                        }
                                                      }
                                                      lVar10 = *(longlong *)(param_1 + 0x1b0);
                                                      if (lVar10 != 0) {
                                                        if (cRam0000000182eb83b1 == '\0') {
                                                          FUN_1802f2810(&DAT_182d58300);
                                                          LOCK();
                                                          UNLOCK();
                                                          FUN_1802f2810(0x182d58000);
                                                          LOCK();
                                                          UNLOCK();
                                                          FUN_1802f2810(&DAT_182d582e8);
                                                          LOCK();
                                                          UNLOCK();
                                                          FUN_1802f2810(0x182d57ff8);
                                                          LOCK();
                                                          UNLOCK();
                                                          FUN_1802f2810(&DAT_182d583a0);
                                                          LOCK();
                                                          UNLOCK();
                                                          FUN_1802f2810(0x182d3e9e0);
                                                          LOCK();
                                                          UNLOCK();
                                                          FUN_1802f2810(0x182d3e9d8);
                                                          LOCK();
                                                          UNLOCK();
                                                          cRam0000000182eb83b1 = '\x01';
                                                        }
                                                        bVar11 = DAT_182eb5d50 != 0;
                                                        *(longlong *)(lVar10 + 0x10) = param_1;
                                                        if (bVar11) {
                                                          uVar9 = (uint)(lVar10 + 0x10U >> 0xc);
                                                          uVar8 = (ulonglong)
                                                                  ((uVar9 & 0x1fffff) >> 6);
                                                          do {
                                                            uVar1 = *(ulonglong *)
                                                                     (&DAT_182f0c920 + uVar8 * 8);
                                                            LOCK();
                                                            bVar11 = uVar1 == *(ulonglong *)
                                                                               (&DAT_182f0c920 +
                                                                               uVar8 * 8);
                                                            if (bVar11) {
                                                              *(ulonglong *)
                                                               (&DAT_182f0c920 + uVar8 * 8) =
                                                                   uVar1 | 1L << (uVar9 & 0x3f);
                                                            }
                                                            UNLOCK();
                                                          } while (!bVar11);
                                                        }
                                                        uVar3 = FUN_1802c43a0(DAT_182d58300);
                                                        FUN_180665bb0(uVar3,lVar10,
                                                                      uRam0000000182d3e9e0,0);
                                                        if (*(int *)(DAT_182d583a0 + 0xe0) == 0) {
                                                          FUN_18035c820();
                                                        }
                                                        FUN_180993250(uVar3,0,DAT_182d582e8);
                                                        uVar3 = FUN_1802c43a0(uRam0000000182d58000);
                                                        FUN_180665bb0(uVar3,lVar10,
                                                                      uRam0000000182d3e9d8,0);
                                                        FUN_180993250(uVar3,0,uRam0000000182d57ff8);
                                                                                                                
                                                  ExposureUnnoticed2_Object3D_Player_Scripts_PlayerBodyMaterialController__SetupBodyPaintFromGameState__06000cd7
                                                            (lVar10,0);
                                                  ExposureUnnoticed2_Object3D_Player_Scripts_PlayerBodyMaterialController__ApplyFromGameState__06000cda
                                                            (lVar10,0);
                                                  if (*(longlong *)(param_1 + 0x170) != 0) {
                                                                                                        
                                                  ExposureUnnoticed2_Object3D_Player_Scripts_PlayerBodyCustomizeAdjuster__Initialize__06000cbd
                                                            (*(longlong *)(param_1 + 0x170),param_1,
                                                             0);
                                                  lVar10 = *(longlong *)(param_1 + 0x178);
                                                  if (lVar10 != 0) {
                                                    *(longlong *)(lVar10 + 0x18) = param_1;
                                                    FUN_18031d480(lVar10 + 0x18);
                                                    lVar10 = *(longlong *)(param_1 + 0x180);
                                                    if (lVar10 != 0) {
                                                      *(longlong *)(lVar10 + 0x10) = param_1;
                                                      FUN_18031d480(lVar10 + 0x10);
                                                      if (*(longlong *)(param_1 + 400) != 0) {
                                                                                                                
                                                  ExposureUnnoticed2_Object3D_Player_Scripts_PlayerRpBonusCalculator__Initialize__06000e0e
                                                            (*(longlong *)(param_1 + 400),param_1,0)
                                                  ;
                                                  lVar10 = *(longlong *)(param_1 + 0x198);
                                                  if (lVar10 != 0) {
                                                    *(longlong *)(lVar10 + 0x18) = param_1;
                                                    FUN_18031d480(lVar10 + 0x18);
                                                    lVar10 = *(longlong *)(param_1 + 0x1a0);
                                                    if (lVar10 != 0) {
                                                      *(longlong *)(lVar10 + 0x10) = param_1;
                                                      FUN_18031d480(lVar10 + 0x10);
                                                      if (*(longlong *)(param_1 + 0x1a8) != 0) {
                                                                                                                
                                                  ExposureUnnoticed2_Object3D_Player_Scripts_PlayerBreathController__Initialize__06000cec
                                                            (*(longlong *)(param_1 + 0x1a8),param_1,
                                                             0);
                                                  lVar10 = *(longlong *)(param_1 + 0x1c0);
                                                  if (lVar10 != 0) {
                                                    *(longlong *)(lVar10 + 0x10) = param_1;
                                                    FUN_18031d480(lVar10 + 0x10);
                                                    lVar10 = *(longlong *)(param_1 + 0x1b8);
                                                    if (lVar10 != 0) {
                                                      *(longlong *)(lVar10 + 0x10) = param_1;
                                                      FUN_18031d480(lVar10 + 0x10);
                                                                                                            
                                                  ExposureUnnoticed2_Object3D_Player_Scripts_PlayerCosplayManager__SetupCostumeFromGameState__06000d76
                                                            (lVar10,0);
                                                  lVar10 = *(longlong *)(param_1 + 0x118);
                                                  if (lVar10 != 0) {
                                                    *(longlong *)(lVar10 + 0x10) = param_1;
                                                    FUN_18031d480(lVar10 + 0x10);
                                                    lVar10 = *(longlong *)(param_1 + 0x1e0);
                                                    if (lVar10 != 0) {
                                                      *(longlong *)(lVar10 + 0x10) = param_1;
                                                      FUN_18031d480(lVar10 + 0x10);
                                                      *(undefined8 *)(lVar10 + 0x18) =
                                                           *(undefined8 *)(param_1 + 0x70);
                                                      FUN_18031d480(lVar10 + 0x18);
                                                      if ((*(longlong *)(lVar10 + 0x18) != 0) &&
                                                         (lVar10 = *(longlong *)
                                                                    (*(longlong *)(lVar10 + 0x18) +
                                                                    0x1f0), lVar10 != 0)) {
                                                        FUN_181fa1260(lVar10,0);
                                                        if (*(longlong *)(param_1 + 0x1f0) != 0) {
                                                                                                                    
                                                  ExposureUnnoticed2_Object3D_Player_Scripts_Costume_PistonMachineController__Initialize__06000ef5
                                                            (*(longlong *)(param_1 + 0x1f0),param_1,
                                                             0);
                                                  lVar10 = *(longlong *)(param_1 + 0x1f8);
                                                  if (lVar10 != 0) {
                                                    if (cRam0000000182eb768d == '\0') {
                                                      FUN_1802f2810(0x182d552f0);
                                                      LOCK();
                                                      UNLOCK();
                                                      cRam0000000182eb768d = '\x01';
                                                    }
                                                    *(longlong *)(lVar10 + 0x20) = param_1;
                                                    FUN_18031d480(lVar10 + 0x20);
                                                    uVar3 = FUN_1802c43a0(uRam0000000182d552f0);
                                                    FUN_181edaa20(uVar3,0);
                                                    *(undefined8 *)(lVar10 + 0x38) = uVar3;
                                                    FUN_18031d480(lVar10 + 0x38);
                                                    lVar4 = *(longlong *)(param_1 + 0x18);
                                                    if (lVar4 != 0) {
                                                      uStack_18 = 0;
                                                      uStack_10 = 0;
                                                      pcVar5 = DAT_182ec1698;
                                                      if ((DAT_182ec1698 == (code *)0x0) &&
                                                         (pcVar5 = (code *)FUN_1802cf0c0(
                                                  "UnityEngine.Transform::get_position_Injected(UnityEngine.Vector3&)"
                                                  ), pcVar5 == (code *)0x0)) {
                                                    uVar3 = FUN_1802ced60(
                                                  "UnityEngine.Transform::get_position_Injected(UnityEngine.Vector3&)"
                                                  );
                    /* WARNING: Subroutine does not return */
                                                  FUN_1802cca90(uVar3,0);
                                                  }
                                                  DAT_182ec1698 = pcVar5;
                                                  (*DAT_182ec1698)(lVar4,&uStack_18);
                                                  *(undefined8 *)(lVar10 + 0x28) = uStack_18;
                                                  *(undefined4 *)(lVar10 + 0x30) = uStack_10;
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
              }
            }
          }
        }
      }
    }
  }
code_r0x00018063f6be:
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

