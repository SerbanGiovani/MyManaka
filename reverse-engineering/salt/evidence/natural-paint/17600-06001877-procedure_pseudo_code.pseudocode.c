// Ghidra pseudocode; not original source or compilable C.
// ev_756cc1b3c01542516242db071036ca0e642d7efed8aceaf646eb88e4c84c36a1

void ExposureUnnoticed2_ObjectUI_PcMenuPanel_PcMenuPanelView__OnClickOnlineShop__06001877(void)

{
  ulonglong *puVar1;
  ulonglong uVar2;
  ulonglong uVar3;
  longlong lVar4;
  longlong *plVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  longlong lVar8;
  longlong *plVar9;
  uint uVar10;
  bool bVar11;
  
  if (cRam0000000182eb7bc6 == '\0') {
    FUN_1802f2810(&DAT_182d58238);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d58380);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d57ab8);
    LOCK();
    UNLOCK();
    cRam0000000182eb7bc6 = '\x01';
  }
  if (*(int *)(DAT_182d58380 + 0xe0) == 0) {
    FUN_18035c820(DAT_182d58380);
  }
  if (((**(longlong **)(DAT_182d58238 + 0xb8) != 0) && (**(longlong **)(DAT_182d58380 + 0xb8) != 0))
     && (plVar5 = (longlong *)
                  ExposureUnnoticed2_Object3D_IngameManager_InGameUiManager__Open__060011a0
                            (**(longlong **)(DAT_182d58380 + 0xb8),
                             *(undefined8 *)(**(longlong **)(DAT_182d58238 + 0xb8) + 0x1f8),0,0),
        plVar5 != (longlong *)0x0)) {
    if ((*(byte *)(DAT_182d57ab8 + 0x130) <= *(byte *)(*plVar5 + 0x130)) &&
       (lVar8 = *(longlong *)(*plVar5 + 200),
       *(longlong *)(lVar8 + -8 + (ulonglong)*(byte *)(DAT_182d57ab8 + 0x130) * 8) == DAT_182d57ab8)
       ) {
      plVar9 = (longlong *)0x0;
      if (*(longlong *)(lVar8 + -8 + (ulonglong)*(byte *)(DAT_182d57ab8 + 0x130) * 8) ==
          DAT_182d57ab8) {
        plVar9 = plVar5;
      }
      if (cRam0000000182eb7bbd == '\0') {
        FUN_1802f2810(0x182d61940,0);
        LOCK();
        UNLOCK();
        FUN_1802f2810(&DAT_182d58368);
        LOCK();
        UNLOCK();
        FUN_1802f2810(&DAT_182d61520);
        LOCK();
        UNLOCK();
        FUN_1802f2810(0x182d61518);
        LOCK();
        UNLOCK();
        FUN_1802f2810(0x182d61510);
        LOCK();
        UNLOCK();
        FUN_1802f2810(0x182d5de00);
        LOCK();
        UNLOCK();
        FUN_1802f2810(0x182d5ddc8);
        LOCK();
        UNLOCK();
        FUN_1802f2810(&DAT_182d5dd38);
        LOCK();
        UNLOCK();
        FUN_1802f2810(0x182d5e108);
        LOCK();
        UNLOCK();
        FUN_1802f2810(&DAT_182d58398);
        LOCK();
        UNLOCK();
        FUN_1802f2810(&DAT_182d53c48);
        LOCK();
        UNLOCK();
        FUN_1802f2810(&DAT_182d58380);
        LOCK();
        UNLOCK();
        FUN_1802f2810(0x182d61508);
        LOCK();
        UNLOCK();
        FUN_1802f2810(0x182d61500);
        LOCK();
        UNLOCK();
        FUN_1802f2810(0x182d614f8);
        LOCK();
        UNLOCK();
        FUN_1802f2810(0x182d614f0);
        LOCK();
        UNLOCK();
        FUN_1802f2810(0x182d614e8);
        LOCK();
        UNLOCK();
        FUN_1802f2810(&DAT_182d58378);
        LOCK();
        UNLOCK();
        cRam0000000182eb7bbd = '\x01';
      }
      FUN_1804e1230(plVar9);
      if (((**(longlong **)(DAT_182d58378 + 0xb8) != 0) &&
          (lVar8 = *(longlong *)(**(longlong **)(DAT_182d58378 + 0xb8) + 0x40), lVar8 != 0)) &&
         (lVar8 = *(longlong *)(lVar8 + 0x48), lVar8 != 0)) {
        ExposureUnnoticed2_Object3D_Player_Scripts_PlayerAnimationManager__SetPreviewNakedArmPose__06000c83
                  (lVar8,1,0);
        lVar8 = plVar9[0xf];
        uVar6 = FUN_1802c43a0(uRam0000000182d61940);
        FUN_180006cd0(uVar6,plVar9,uRam0000000182d61508);
        uVar7 = FUN_1802c43a0(uRam0000000182d5e108);
        FUN_180005c40(uVar7,plVar9,uRam0000000182d61500);
        if (lVar8 != 0) {
          ExposureUnnoticed2_ObjectUI_CommonUI_CommonTab_CommonTabView__Initialize__06001da6
                    (lVar8,uVar6,uVar7,0);
          if (((**(longlong **)(DAT_182d53c48 + 0xb8) != 0) &&
              (lVar8 = *(longlong *)(**(longlong **)(DAT_182d53c48 + 0xb8) + 0x28), lVar8 != 0)) &&
             (lVar8 = *(longlong *)(lVar8 + 0x38), lVar8 != 0)) {
            ExposureUnnoticed2_Object3D_Camera_BaseCameraController__SetInventoryCamera__060011ec
                      (lVar8,1,0,0);
            if (*(int *)(DAT_182d58380 + 0xe0) == 0) {
              FUN_18035c820(DAT_182d58380);
            }
            if (**(longlong **)(DAT_182d58380 + 0xb8) != 0) {
              ExposureUnnoticed2_Object3D_IngameManager_InGameUiManager__SetVisibleRightDownInfo__060011a5
                        (**(longlong **)(DAT_182d58380 + 0xb8),0,0);
              lVar8 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x60);
              if (lVar8 != 0) {
                lVar8 = ExposureUnnoticed2_Master_Hair_MHair__Get__0600128f
                                  (*(undefined4 *)(lVar8 + 0x104),0);
                bVar11 = DAT_182eb5d50 != 0;
                plVar9[0x27] = lVar8;
                if (bVar11) {
                  uVar10 = (uint)((ulonglong)(plVar9 + 0x27) >> 0xc);
                  lVar8 = (ulonglong)((uVar10 & 0x1fffff) >> 6) * 8;
                  do {
                    uVar3 = *(ulonglong *)(&DAT_182f0c920 + lVar8);
                    LOCK();
                    bVar11 = uVar3 == *(ulonglong *)(&DAT_182f0c920 + lVar8);
                    if (bVar11) {
                      *(ulonglong *)(&DAT_182f0c920 + lVar8) = uVar3 | 1L << (uVar10 & 0x3f);
                    }
                    UNLOCK();
                  } while (!bVar11);
                }
                lVar8 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
                if (lVar8 != 0) {
                  lVar8 = ExposureUnnoticed2_Master_Clothes_MClothes__Get__06001343
                                    (*(undefined4 *)(lVar8 + 0x19c),0);
                  bVar11 = DAT_182eb5d50 != 0;
                  plVar9[0x28] = lVar8;
                  if (bVar11) {
                    uVar10 = (uint)((ulonglong)(plVar9 + 0x28) >> 0xc);
                    lVar8 = (ulonglong)((uVar10 & 0x1fffff) >> 6) * 8;
                    do {
                      uVar3 = *(ulonglong *)(&DAT_182f0c920 + lVar8);
                      LOCK();
                      bVar11 = uVar3 == *(ulonglong *)(&DAT_182f0c920 + lVar8);
                      if (bVar11) {
                        *(ulonglong *)(&DAT_182f0c920 + lVar8) = uVar3 | 1L << (uVar10 & 0x3f);
                      }
                      UNLOCK();
                    } while (!bVar11);
                  }
                  if (plVar9[0x1e] != 0) {
                    ExposureUnnoticed2_ObjectUI_InventoryPanel_PartsOptionSetupPanel_PartsOptionSetupPanelView__Initialize__06001a10
                              (plVar9[0x1e],0);
                    lVar8 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
                    if (lVar8 != 0) {
                      uVar6 = *(undefined8 *)(lVar8 + 0x210);
                      lVar8 = FUN_1802c43a0(uRam0000000182d5ddc8);
                      FUN_180e6bd40(lVar8,uVar6,0,
                                    *(undefined8 *)
                                     (*(longlong *)
                                       (*(longlong *)(lRam0000000182d61518 + 0x20) + 0xc0) + 0x40));
                      bVar11 = DAT_182eb5d50 != 0;
                      plVar9[0x2b] = lVar8;
                      if (bVar11) {
                        uVar10 = (uint)((ulonglong)(plVar9 + 0x2b) >> 0xc);
                        lVar8 = (ulonglong)((uVar10 & 0x1fffff) >> 6) * 8;
                        do {
                          uVar3 = *(ulonglong *)(&DAT_182f0c920 + lVar8);
                          LOCK();
                          bVar11 = uVar3 == *(ulonglong *)(&DAT_182f0c920 + lVar8);
                          if (bVar11) {
                            *(ulonglong *)(&DAT_182f0c920 + lVar8) = uVar3 | 1L << (uVar10 & 0x3f);
                          }
                          UNLOCK();
                        } while (!bVar11);
                      }
                      lVar8 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
                      if (lVar8 != 0) {
                        uVar6 = *(undefined8 *)(lVar8 + 0x220);
                        lVar8 = FUN_1802c43a0(uRam0000000182d5de00);
                        FUN_180e43550(lVar8,uVar6,0,
                                      *(undefined8 *)
                                       (*(longlong *)
                                         (*(longlong *)(lRam0000000182d61510 + 0x20) + 0xc0) + 0x40)
                                     );
                        bVar11 = DAT_182eb5d50 != 0;
                        plVar9[0x2d] = lVar8;
                        if (bVar11) {
                          uVar10 = (uint)((ulonglong)(plVar9 + 0x2d) >> 0xc);
                          lVar8 = (ulonglong)((uVar10 & 0x1fffff) >> 6) * 8;
                          do {
                            uVar3 = *(ulonglong *)(&DAT_182f0c920 + lVar8);
                            LOCK();
                            bVar11 = uVar3 == *(ulonglong *)(&DAT_182f0c920 + lVar8);
                            if (bVar11) {
                              *(ulonglong *)(&DAT_182f0c920 + lVar8) = uVar3 | 1L << (uVar10 & 0x3f)
                              ;
                            }
                            UNLOCK();
                          } while (!bVar11);
                        }
                        lVar8 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x60);
                        if (lVar8 != 0) {
                          uVar6 = *(undefined8 *)(lVar8 + 0x108);
                          lVar8 = FUN_1802c43a0(DAT_182d5dd38);
                          FUN_180e6bd40(lVar8,uVar6,0,
                                        *(undefined8 *)
                                         (*(longlong *)(*(longlong *)(DAT_182d61520 + 0x20) + 0xc0)
                                         + 0x40));
                          bVar11 = DAT_182eb5d50 != 0;
                          plVar9[0x2c] = lVar8;
                          if (bVar11) {
                            uVar10 = (uint)((ulonglong)(plVar9 + 0x2c) >> 0xc);
                            lVar8 = (ulonglong)((uVar10 & 0x1fffff) >> 6) * 8;
                            do {
                              uVar3 = *(ulonglong *)(&DAT_182f0c920 + lVar8);
                              LOCK();
                              bVar11 = uVar3 == *(ulonglong *)(&DAT_182f0c920 + lVar8);
                              if (bVar11) {
                                *(ulonglong *)(&DAT_182f0c920 + lVar8) =
                                     uVar3 | 1L << (uVar10 & 0x3f);
                              }
                              UNLOCK();
                            } while (!bVar11);
                          }
                          ExposureUnnoticed2_ObjectUI_PcMenuPanel_OnlineShopPanel_OnlineShopPanelView__OnClickTab__06001905
                                    (plVar9,0,0,0);
                          lVar8 = FUN_1802c43a0(DAT_182d58368);
                          FUN_1814df680(lVar8,plVar9,uRam0000000182d614f8,0);
                          bVar11 = DAT_182eb5d50 != 0;
                          plVar9[6] = lVar8;
                          if (bVar11) {
                            uVar10 = (uint)((ulonglong)(plVar9 + 6) >> 0xc);
                            lVar8 = (ulonglong)((uVar10 & 0x1fffff) >> 6) * 8;
                            do {
                              uVar3 = *(ulonglong *)(&DAT_182f0c920 + lVar8);
                              LOCK();
                              bVar11 = uVar3 == *(ulonglong *)(&DAT_182f0c920 + lVar8);
                              if (bVar11) {
                                *(ulonglong *)(&DAT_182f0c920 + lVar8) =
                                     uVar3 | 1L << (uVar10 & 0x3f);
                              }
                              UNLOCK();
                            } while (!bVar11);
                          }
                          lVar8 = plVar9[0x1d];
                          uVar6 = FUN_1802c43a0(uRam0000000182d61940);
                          FUN_180006cd0(uVar6,plVar9,uRam0000000182d614f0);
                          if (lVar8 != 0) {
                            ExposureUnnoticed2_ObjectUI_InventoryPanel_CosplaySerieseSelectPanel_CosplaySeriesSelectPanelView__Initialize__06001a28
                                      (lVar8,uVar6,1,0);
                            uVar6 = FUN_1802c43a0(DAT_182d58368);
                            FUN_1814df680(uVar6,plVar9,uRam0000000182d614e8,0);
                            if (DAT_182eb7aa1 == '\0') {
                              FUN_1802f2810(&DAT_182d5f910,1,0);
                              LOCK();
                              UNLOCK();
                              FUN_1802f2810(&DAT_182d5f908);
                              LOCK();
                              UNLOCK();
                              DAT_182eb7aa1 = '\x01';
                            }
                            lVar8 = ExposureUnnoticed2_Scripts_Base_Scheduler__get_Instance__0600174a
                                              (0);
                            if (lVar8 != 0) {
                              lVar8 = *(longlong *)(lVar8 + 0x20);
                              lVar4 = FUN_1802c43a0(DAT_182d5f910);
                              bVar11 = DAT_182eb5d50 != 0;
                              *(undefined8 *)(lVar4 + 0x10) = uVar6;
                              if (bVar11) {
                                uVar10 = (uint)(lVar4 + 0x10U >> 0xc);
                                puVar1 = (ulonglong *)
                                         (&DAT_182f0c920 + (ulonglong)((uVar10 & 0x1fffff) >> 6) * 8
                                         );
                                do {
                                  uVar2 = *puVar1;
                                  LOCK();
                                  uVar3 = *puVar1;
                                  if (uVar2 == uVar3) {
                                    *puVar1 = uVar2 | 1L << (uVar10 & 0x3f);
                                  }
                                  UNLOCK();
                                } while (uVar2 != uVar3);
                              }
                              *(undefined4 *)(lVar4 + 0x18) = 1;
                              if (lVar8 != 0) {
                                FUN_1800068f0(lVar8,lVar4);
                                return;
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
      }
                    /* WARNING: Subroutine does not return */
      FUN_18031dad0();
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

