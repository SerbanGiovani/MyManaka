// Ghidra pseudocode; not original source or compilable C.
// ev_cf27279657b4aeef25d635433421890fa8a0292072a34de292edc7a71e998b29

void ExposureUnnoticed2_ObjectUI_BarberMenu_ClosetMenuView__Initialize__06001c7d(longlong param_1)

{
  char cVar1;
  undefined4 uVar2;
  ulonglong uVar3;
  undefined8 uVar4;
  longlong lVar5;
  longlong *plVar6;
  undefined1 uVar7;
  longlong lVar8;
  undefined8 uVar9;
  undefined8 uVar10;
  longlong lVar11;
  longlong lVar12;
  undefined1 *puVar13;
  code *pcVar14;
  ulonglong uVar15;
  uint uVar16;
  bool bVar17;
  undefined8 uStack_50;
  undefined4 *puStack_48;
  undefined8 uStack_40;
  undefined4 uStack_38;
  undefined4 uStack_34;
  uint uStack_30;
  int iStack_2c;
  ulonglong uStack_28;
  
  if (cRam0000000182eb7dbe == '\0') {
    FUN_1802f2810(0x182d5f2a8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d58368);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d65cc0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d65cb8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d5aa20);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d65cd8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d65cb0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d65ca8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d58288);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d65ca0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d53c48);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d58380);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d65c98);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d65c90);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d54d90);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d53aa8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d58378);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5ff60);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d5aa70);
    LOCK();
    UNLOCK();
    cRam0000000182eb7dbe = '\x01';
  }
  **(longlong **)(DAT_182d5aa20 + 0xb8) = param_1;
  if (DAT_182eb5d50 != 0) {
    uVar16 = (uint)(*(ulonglong *)(DAT_182d5aa20 + 0xb8) >> 0xc);
    uVar15 = (ulonglong)((uVar16 & 0x1fffff) >> 6);
    do {
      uVar3 = *(ulonglong *)(&DAT_182f0c920 + uVar15 * 8);
      LOCK();
      bVar17 = uVar3 == *(ulonglong *)(&DAT_182f0c920 + uVar15 * 8);
      if (bVar17) {
        *(ulonglong *)(&DAT_182f0c920 + uVar15 * 8) = uVar3 | 1L << (uVar16 & 0x3f);
      }
      UNLOCK();
    } while (!bVar17);
  }
  if (((**(longlong **)(DAT_182d58378 + 0xb8) != 0) &&
      (lVar8 = *(longlong *)(**(longlong **)(DAT_182d58378 + 0xb8) + 0x40), lVar8 != 0)) &&
     (lVar8 = *(longlong *)(lVar8 + 0x48), lVar8 != 0)) {
    ExposureUnnoticed2_Object3D_Player_Scripts_PlayerAnimationManager__SetPreviewNakedArmPose__06000c83
              (lVar8,1,0);
    uVar10 = *(undefined8 *)(param_1 + 0x68);
    if (*(int *)(DAT_182d58288 + 0xe0) == 0) {
      FUN_18035c820();
    }
    ExposureUnnoticed2_Scripts_Base_ExternalMethodManager__DestroyChildren__0600172c(uVar10,0);
    if (*(int *)(DAT_182d58380 + 0xe0) == 0) {
      FUN_18035c820(DAT_182d58380);
    }
    if (**(longlong **)(DAT_182d58380 + 0xb8) != 0) {
      ExposureUnnoticed2_Object3D_IngameManager_InGameUiManager__SetVisibleRightDownInfo__060011a5
                (**(longlong **)(DAT_182d58380 + 0xb8),0,0);
      lVar8 = ExposureUnnoticed2_Scripts_InGame_GameStateFacade__GetPossessionClothes__06001553(0);
      if (lVar8 != 0) {
        if (DAT_182eb5d50 != 0) {
          uVar16 = (uint)((ulonglong)&uStack_50 >> 0xc);
          uVar15 = (ulonglong)((uVar16 & 0x1fffff) >> 6);
          do {
            uVar3 = *(ulonglong *)(&DAT_182f0c920 + uVar15 * 8);
            LOCK();
            bVar17 = uVar3 == *(ulonglong *)(&DAT_182f0c920 + uVar15 * 8);
            if (bVar17) {
              *(ulonglong *)(&DAT_182f0c920 + uVar15 * 8) = uVar3 | 1L << (uVar16 & 0x3f);
            }
            UNLOCK();
          } while (!bVar17);
        }
        iStack_2c = *(int *)(lVar8 + 0x1c);
        uStack_40 = 0;
        uStack_50._0_4_ = (undefined4)lVar8;
        uStack_50._4_4_ = (undefined4)((ulonglong)lVar8 >> 0x20);
        uStack_38 = (undefined4)uStack_50;
        uStack_34 = uStack_50._4_4_;
        uStack_30 = 0;
        uStack_28 = 0;
        uStack_50 = 0;
        puStack_48 = &uStack_38;
        while( true ) {
          lVar8 = CONCAT44(uStack_34,uStack_38);
          if (lVar8 == 0) {
                    /* WARNING: Subroutine does not return */
            FUN_18031dad0();
          }
          if ((iStack_2c != *(int *)(lVar8 + 0x1c)) || (*(uint *)(lVar8 + 0x18) <= uStack_30))
          break;
          lVar8 = *(longlong *)(lVar8 + 0x10);
          if (lVar8 == 0) {
                    /* WARNING: Subroutine does not return */
            FUN_18031dad0();
          }
          if (*(uint *)(lVar8 + 0x18) <= uStack_30) {
                    /* WARNING: Subroutine does not return */
            FUN_18031dae0();
          }
          uVar2 = *(undefined4 *)(lVar8 + 0x20 + (longlong)(int)uStack_30 * 4);
          uStack_28 = CONCAT44(uStack_28._4_4_,uVar2);
          uStack_30 = uStack_30 + 1;
          uVar9 = ExposureUnnoticed2_Master_Clothes_MClothes__Get__06001343(uVar2,0);
          uVar10 = *(undefined8 *)(param_1 + 0x60);
          uVar4 = *(undefined8 *)(param_1 + 0x68);
          if (*(int *)(DAT_182d53aa8 + 0xe0) == 0) {
            FUN_18035c820();
          }
          lVar8 = FUN_1809f1050(uVar10,uVar4,DAT_182d54d90);
          if (lVar8 == 0) {
                    /* WARNING: Subroutine does not return */
            FUN_18031dad0();
          }
          lVar8 = FUN_1809a08f0(lVar8,uRam0000000182d65ca0);
          uVar10 = FUN_1802c43a0(uRam0000000182d5f2a8);
          FUN_180665bb0(uVar10,param_1,uRam0000000182d65cc0,0);
          if (lVar8 == 0) {
                    /* WARNING: Subroutine does not return */
            FUN_18031dad0();
          }
          ExposureUnnoticed2_ObjectUI_ClosetMenu_ClosetMenuItemView__Initialize__06001c92
                    (lVar8,uVar9,uVar10,0);
          lVar12 = lRam0000000182d65c98;
          lVar11 = *(longlong *)(param_1 + 0x88);
          if (lVar11 == 0) {
                    /* WARNING: Subroutine does not return */
            FUN_18031dad0();
          }
          *(int *)(lVar11 + 0x1c) = *(int *)(lVar11 + 0x1c) + 1;
          lVar5 = *(longlong *)(lVar11 + 0x10);
          uVar16 = *(uint *)(lVar11 + 0x18);
          if (lVar5 == 0) {
                    /* WARNING: Subroutine does not return */
            FUN_18031dad0();
          }
          if (uVar16 < *(uint *)(lVar5 + 0x18)) {
            *(uint *)(lVar11 + 0x18) = uVar16 + 1;
            FUN_180002cd0(lVar5,(longlong)(int)uVar16,lVar8);
          }
          else {
            FUN_1812741c0(lVar11,lVar8,
                          *(undefined8 *)(*(longlong *)(*(longlong *)(lVar12 + 0x20) + 0xc0) + 0x70)
                         );
          }
        }
        if ((*(byte *)(*(longlong *)(lRam0000000182d65cb0 + 0x20) + 0x135) & 1) == 0) {
          FUN_180320470(*(longlong *)(lRam0000000182d65cb0 + 0x20));
          lVar8 = CONCAT44(uStack_34,uStack_38);
        }
        if (lVar8 == 0) {
                    /* WARNING: Subroutine does not return */
          FUN_18031dad0();
        }
        if (iStack_2c != *(int *)(lVar8 + 0x1c)) {
                    /* WARNING: Subroutine does not return */
          FUN_18163fef0(0);
        }
        uStack_30 = *(int *)(lVar8 + 0x18) + 1;
        uStack_28 = uStack_28 & 0xffffffff00000000;
        uVar10 = *(undefined8 *)(param_1 + 0x60);
        uVar4 = *(undefined8 *)(param_1 + 0x68);
        if (*(int *)(DAT_182d53aa8 + 0xe0) == 0) {
          FUN_18035c820();
        }
        lVar8 = FUN_1809f1050(uVar10,uVar4,DAT_182d54d90);
        if (lVar8 != 0) {
          lVar11 = FUN_1809a08f0(lVar8,uRam0000000182d65ca0);
          lVar12 = FUN_1802c43a0(DAT_182d58368);
          lVar8 = lRam0000000182d65cb8;
          *(undefined8 *)(lVar12 + 0x10) = *(undefined8 *)(lRam0000000182d65cb8 + 8);
          *(longlong *)(lVar12 + 0x28) = lVar8;
          *(longlong *)(lVar12 + 0x20) = param_1;
          if (DAT_182eb5d50 != 0) {
            uVar16 = (uint)(lVar12 + 0x20U >> 0xc);
            uVar15 = (ulonglong)((uVar16 & 0x1fffff) >> 6);
            do {
              uVar3 = *(ulonglong *)(&DAT_182f0c920 + uVar15 * 8);
              LOCK();
              bVar17 = uVar3 == *(ulonglong *)(&DAT_182f0c920 + uVar15 * 8);
              if (bVar17) {
                *(ulonglong *)(&DAT_182f0c920 + uVar15 * 8) = uVar3 | 1L << (uVar16 & 0x3f);
              }
              UNLOCK();
            } while (!bVar17);
          }
          cVar1 = *(char *)(lVar8 + 0x52);
          *(longlong *)(lVar12 + 0x40) = lVar12;
          if (((*(byte *)(lVar8 + 0x4c) & 0x10) == 0) || (cVar1 != '\0')) {
            *(undefined8 *)(lVar12 + 0x40) = *(undefined8 *)(lVar12 + 0x20);
            puVar13 = *(undefined1 **)(lVar12 + 0x10);
          }
          else {
            puVar13 = &LAB_1800c7840;
          }
          *(undefined1 **)(lVar12 + 0x18) = puVar13;
          *(code **)(lVar12 + 0x38) = FUN_1801e91e0;
          if (lVar11 != 0) {
            if (cRam0000000182eb7dd0 == '\0') {
              FUN_1802f2810(0x182d65be8);
              LOCK();
              UNLOCK();
              cRam0000000182eb7dd0 = '\x01';
            }
            *(longlong *)(lVar11 + 0x40) = lVar12;
            if (DAT_182eb5d50 != 0) {
              uVar16 = (uint)(lVar11 + 0x40U >> 0xc);
              uVar15 = (ulonglong)((uVar16 & 0x1fffff) >> 6);
              do {
                uVar3 = *(ulonglong *)(&DAT_182f0c920 + uVar15 * 8);
                LOCK();
                bVar17 = uVar3 == *(ulonglong *)(&DAT_182f0c920 + uVar15 * 8);
                if (bVar17) {
                  *(ulonglong *)(&DAT_182f0c920 + uVar15 * 8) = uVar3 | 1L << (uVar16 & 0x3f);
                }
                UNLOCK();
              } while (!bVar17);
            }
            plVar6 = *(longlong **)(lVar11 + 0x20);
            uVar10 = ExposureUnnoticed2_Scripts_Base_Localizer__Trans__060017af
                               (uRam0000000182d65be8,0);
            if (plVar6 != (longlong *)0x0) {
              (**(code **)(*plVar6 + 0x558))(plVar6,uVar10,*(undefined8 *)(*plVar6 + 0x560));
              lVar8 = *(longlong *)(lVar11 + 0x30);
              if (lVar8 != 0) {
                pcVar14 = DAT_182ec1138;
                if ((DAT_182ec1138 == (code *)0x0) &&
                   (pcVar14 = (code *)FUN_1802cf0c0(
                                                  "UnityEngine.GameObject::SetActive(System.Boolean)"
                                                  ), pcVar14 == (code *)0x0)) {
                  uVar10 = FUN_1802ced60("UnityEngine.GameObject::SetActive(System.Boolean)");
                    /* WARNING: Subroutine does not return */
                  FUN_1802cca90(uVar10,0);
                }
                DAT_182ec1138 = pcVar14;
                (*DAT_182ec1138)(lVar8,0);
                if (*(longlong *)(param_1 + 0x88) != 0) {
                  FUN_180007a70(*(longlong *)(param_1 + 0x88),lVar11);
                  if (*(longlong *)(param_1 + 0x78) != 0) {
                    ExposureUnnoticed2_ObjectUI_ClosetMenu_CustomizeMenu_CustomizeMenuView__Initialize__06001cc2
                              (*(longlong *)(param_1 + 0x78),0,param_1,0);
                    if ((((**(longlong **)(DAT_182d58378 + 0xb8) != 0) &&
                         (lVar8 = *(longlong *)(**(longlong **)(DAT_182d58378 + 0xb8) + 0x40),
                         lVar8 != 0)) && (lVar8 = *(longlong *)(lVar8 + 0x70), lVar8 != 0)) &&
                       (lVar8 = *(longlong *)(lVar8 + 0x238), lVar8 != 0)) {
                      pcVar14 = DAT_182ec1148;
                      if ((DAT_182ec1148 == (code *)0x0) &&
                         (pcVar14 = (code *)FUN_1802cf0c0(
                                                  "UnityEngine.GameObject::get_activeInHierarchy()")
                         , pcVar14 == (code *)0x0)) {
                        uVar10 = FUN_1802ced60("UnityEngine.GameObject::get_activeInHierarchy()");
                    /* WARNING: Subroutine does not return */
                        FUN_1802cca90(uVar10,0);
                      }
                      DAT_182ec1148 = pcVar14;
                      uVar7 = (*DAT_182ec1148)(lVar8);
                      *(undefined1 *)(param_1 + 0x90) = uVar7;
                      if (((**(longlong **)(DAT_182d58378 + 0xb8) != 0) &&
                          (lVar8 = *(longlong *)(**(longlong **)(DAT_182d58378 + 0xb8) + 0x40),
                          lVar8 != 0)) &&
                         ((lVar8 = *(longlong *)(lVar8 + 0x70), lVar8 != 0 &&
                          (lVar8 = *(longlong *)(lVar8 + 0x268), lVar8 != 0)))) {
                        pcVar14 = DAT_182ec1148;
                        if ((DAT_182ec1148 == (code *)0x0) &&
                           (pcVar14 = (code *)FUN_1802cf0c0(
                                                  "UnityEngine.GameObject::get_activeInHierarchy()")
                           , pcVar14 == (code *)0x0)) {
                          uVar10 = FUN_1802ced60("UnityEngine.GameObject::get_activeInHierarchy()");
                    /* WARNING: Subroutine does not return */
                          FUN_1802cca90(uVar10,0);
                        }
                        DAT_182ec1148 = pcVar14;
                        uVar7 = (*DAT_182ec1148)(lVar8);
                        *(undefined1 *)(param_1 + 0x91) = uVar7;
                        if ((((**(longlong **)(DAT_182d58378 + 0xb8) != 0) &&
                             (lVar8 = *(longlong *)(**(longlong **)(DAT_182d58378 + 0xb8) + 0x40),
                             lVar8 != 0)) && (lVar8 = *(longlong *)(lVar8 + 0x70), lVar8 != 0)) &&
                           (lVar8 = *(longlong *)(lVar8 + 0x260), lVar8 != 0)) {
                          pcVar14 = DAT_182ec1148;
                          if ((DAT_182ec1148 == (code *)0x0) &&
                             (pcVar14 = (code *)FUN_1802cf0c0(
                                                  "UnityEngine.GameObject::get_activeInHierarchy()")
                             , pcVar14 == (code *)0x0)) {
                            uVar10 = FUN_1802ced60("UnityEngine.GameObject::get_activeInHierarchy()"
                                                  );
                    /* WARNING: Subroutine does not return */
                            FUN_1802cca90(uVar10,0);
                          }
                          DAT_182ec1148 = pcVar14;
                          uVar7 = (*DAT_182ec1148)(lVar8);
                          *(undefined1 *)(param_1 + 0x92) = uVar7;
                          if (((**(longlong **)(DAT_182d58378 + 0xb8) != 0) &&
                              (lVar8 = *(longlong *)(**(longlong **)(DAT_182d58378 + 0xb8) + 0x40),
                              lVar8 != 0)) &&
                             ((lVar8 = *(longlong *)(lVar8 + 0x70), lVar8 != 0 &&
                              (lVar8 = *(longlong *)(lVar8 + 0x290), lVar8 != 0)))) {
                            pcVar14 = DAT_182ec1148;
                            if ((DAT_182ec1148 == (code *)0x0) &&
                               (pcVar14 = (code *)FUN_1802cf0c0(
                                                  "UnityEngine.GameObject::get_activeInHierarchy()")
                               , pcVar14 == (code *)0x0)) {
                              uVar10 = FUN_1802ced60(
                                                  "UnityEngine.GameObject::get_activeInHierarchy()")
                              ;
                    /* WARNING: Subroutine does not return */
                              FUN_1802cca90(uVar10,0);
                            }
                            DAT_182ec1148 = pcVar14;
                            uVar7 = (*DAT_182ec1148)(lVar8);
                            *(undefined1 *)(param_1 + 0x93) = uVar7;
                            if (((**(longlong **)(DAT_182d53c48 + 0xb8) != 0) &&
                                (lVar8 = *(longlong *)(**(longlong **)(DAT_182d53c48 + 0xb8) + 0x28)
                                , lVar8 != 0)) && (lVar8 = *(longlong *)(lVar8 + 0x38), lVar8 != 0))
                            {
                              ExposureUnnoticed2_Object3D_Camera_BaseCameraController__SetInventoryCamera__060011ec
                                        (lVar8,1,1,0);
                              ExposureUnnoticed2_ObjectUI_BarberMenu_ClosetMenuView__RefreshClothesView__06001c7e
                                        (param_1,0);
                              if (((**(longlong **)(DAT_182d53c48 + 0xb8) != 0) &&
                                  (lVar8 = *(longlong *)
                                            (**(longlong **)(DAT_182d53c48 + 0xb8) + 0x28),
                                  lVar8 != 0)) &&
                                 ((lVar8 = *(longlong *)(lVar8 + 0x30), lVar8 != 0 &&
                                  (lVar8 = *(longlong *)(lVar8 + 0x40), lVar8 != 0)))) {
                                lVar8 = *(longlong *)(lVar8 + 0x120);
                                if (cRam0000000182eb7e8a == '\0') {
                                  FUN_1802f2810(&DAT_182d65320);
                                  LOCK();
                                  UNLOCK();
                                  cRam0000000182eb7e8a = '\x01';
                                }
                                lVar11 = **(longlong **)(DAT_182d65320 + 0xb8);
                                if (lVar11 != 0) {
                                  pcVar14 = DAT_182ec1080;
                                  if ((DAT_182ec1080 == (code *)0x0) &&
                                     (pcVar14 = (code *)FUN_1802cf0c0(
                                                  "UnityEngine.Component::get_transform()"),
                                     pcVar14 == (code *)0x0)) {
                                    uVar10 = FUN_1802ced60("UnityEngine.Component::get_transform()")
                                    ;
                    /* WARNING: Subroutine does not return */
                                    FUN_1802cca90(uVar10,0);
                                  }
                                  DAT_182ec1080 = pcVar14;
                                  uVar10 = (*DAT_182ec1080)(lVar11);
                                  if (lVar8 != 0) {
                                    ExposureUnnoticed2_Object3D_Player_Scripts_LookAtController__EnableLookAt__06000c0f
                                              (lVar8,6,uVar10,1,0);
                                    if (cRam0000000182eb7e8b == '\0') {
                                      FUN_1802f2810(&DAT_182d65318);
                                      LOCK();
                                      UNLOCK();
                                      cRam0000000182eb7e8b = '\x01';
                                    }
                                    if (**(longlong **)(DAT_182d65318 + 0xb8) != 0) {
                                      ExposureUnnoticed2_Object3D_ScenePlops_ClosetLight_ClosetLightController__SetClosetLight__06000b38
                                                (**(longlong **)(DAT_182d65318 + 0xb8),1,0);
                                      ExposureUnnoticed2_ObjectUI_BarberMenu_ClosetMenuView__OnClickCategory__06001c82
                                                (param_1,3,0);
                                      if (**(longlong **)(DAT_182d5aa70 + 0xb8) != 0) {
                                        ExposureUnnoticed2_Scripts_Sound_UiSoundPlayer__PlayOneShotAudioData__06001404
                                                  (**(longlong **)(DAT_182d5aa70 + 0xb8),0x31,
                                                   0xbf800000,0,0);
                                        if (*(int *)(lRam0000000182d5ff60 + 0xe0) == 0) {
                                          FUN_18035c820(lRam0000000182d5ff60);
                                        }
                                        if (**(longlong **)(lRam0000000182d5ff60 + 0xb8) != 0) {
                                          *(undefined1 *)
                                           (**(longlong **)(lRam0000000182d5ff60 + 0xb8) + 0x60) = 1
                                          ;
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
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

