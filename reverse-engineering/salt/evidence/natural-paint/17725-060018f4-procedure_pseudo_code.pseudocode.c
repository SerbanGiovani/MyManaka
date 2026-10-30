// Ghidra pseudocode; not original source or compilable C.
// ev_d01b0f237d4cae81babe26626d17c1f178cb23b2ae2a2f8c462e30b0b732c400

void ExposureUnnoticed2_ObjectUI_PcMenuPanel_OnlineShopPanel_OnlineShopItemView__Initialize__060018f4
               (longlong param_1,longlong *param_2,char param_3,undefined8 param_4,
               undefined8 param_5,undefined8 param_6)

{
  ulonglong uVar1;
  longlong *plVar2;
  longlong lVar3;
  undefined1 uVar4;
  char cVar5;
  char cVar6;
  undefined4 uVar7;
  undefined8 uVar8;
  code *pcVar9;
  longlong lVar10;
  int iVar11;
  int iVar12;
  uint uVar13;
  bool bVar14;
  undefined8 local_38;
  undefined8 uStack_30;
  
  if (DAT_182eb7bb8 == '\0') {
    FUN_1802f2810(&DAT_182d61538);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d61530);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d58378);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d5da48);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d61ba0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d5f2b0);
    LOCK();
    UNLOCK();
    DAT_182eb7bb8 = '\x01';
  }
  iVar11 = DAT_182eb5d50;
  *(undefined8 *)(param_1 + 0x90) = param_4;
  if (iVar11 != 0) {
    uVar13 = (uint)(param_1 + 0x90U >> 0xc);
    lVar10 = (ulonglong)((uVar13 & 0x1fffff) >> 6) * 8;
    do {
      uVar1 = *(ulonglong *)(&DAT_182f0c920 + lVar10);
      LOCK();
      bVar14 = uVar1 == *(ulonglong *)(&DAT_182f0c920 + lVar10);
      if (bVar14) {
        *(ulonglong *)(&DAT_182f0c920 + lVar10) = uVar1 | 1L << (uVar13 & 0x3f);
      }
      UNLOCK();
      iVar11 = DAT_182eb5d50;
    } while (!bVar14);
  }
  *(undefined8 *)(param_1 + 0x98) = param_5;
  iVar12 = 0;
  if (iVar11 != 0) {
    uVar13 = (uint)(param_1 + 0x98U >> 0xc);
    lVar10 = (ulonglong)((uVar13 & 0x1fffff) >> 6) * 8;
    do {
      uVar1 = *(ulonglong *)(&DAT_182f0c920 + lVar10);
      LOCK();
      bVar14 = uVar1 == *(ulonglong *)(&DAT_182f0c920 + lVar10);
      if (bVar14) {
        *(ulonglong *)(&DAT_182f0c920 + lVar10) = uVar1 | 1L << (uVar13 & 0x3f);
      }
      UNLOCK();
      iVar12 = DAT_182eb5d50;
    } while (!bVar14);
  }
  *(longlong **)(param_1 + 0xa8) = param_2;
  if (iVar12 != 0) {
    uVar13 = (uint)(param_1 + 0xa8U >> 0xc);
    lVar10 = (ulonglong)((uVar13 & 0x1fffff) >> 6) * 8;
    do {
      uVar1 = *(ulonglong *)(&DAT_182f0c920 + lVar10);
      LOCK();
      bVar14 = uVar1 == *(ulonglong *)(&DAT_182f0c920 + lVar10);
      if (bVar14) {
        *(ulonglong *)(&DAT_182f0c920 + lVar10) = uVar1 | 1L << (uVar13 & 0x3f);
      }
      UNLOCK();
    } while (!bVar14);
  }
  *(char *)(param_1 + 0xb0) = param_3;
  uVar8 = FUN_180735660(param_1,DAT_182d61538);
  bVar14 = DAT_182eb5d50 != 0;
  *(undefined8 *)(param_1 + 0xb8) = uVar8;
  if (bVar14) {
    uVar13 = (uint)(param_1 + 0xb8U >> 0xc);
    lVar10 = (ulonglong)((uVar13 & 0x1fffff) >> 6) * 8;
    do {
      uVar1 = *(ulonglong *)(&DAT_182f0c920 + lVar10);
      LOCK();
      bVar14 = uVar1 == *(ulonglong *)(&DAT_182f0c920 + lVar10);
      if (bVar14) {
        *(ulonglong *)(&DAT_182f0c920 + lVar10) = uVar1 | 1L << (uVar13 & 0x3f);
      }
      UNLOCK();
    } while (!bVar14);
  }
  plVar2 = *(longlong **)(param_1 + 0x20);
  if (param_2 != (longlong *)0x0) {
    uVar8 = FUN_180002c20(0,DAT_182d61530,param_2);
    uVar8 = ExposureUnnoticed2_Scripts_Base_Localizer__Trans__060017af(uVar8,0);
    if (plVar2 != (longlong *)0x0) {
      (**(code **)(*plVar2 + 0x558))(plVar2,uVar8,*(undefined8 *)(*plVar2 + 0x560));
      cVar6 = '\x01';
      plVar2 = *(longlong **)(param_1 + 0x28);
      uVar7 = FUN_180002c20(1,DAT_182d61530,param_2);
      if (DAT_182ebb869 == '\0') {
        FUN_1802f2810(&DAT_182d24690);
        LOCK();
        UNLOCK();
        FUN_1802f2810(&DAT_182d39ea8);
        LOCK();
        UNLOCK();
        DAT_182ebb869 = '\x01';
      }
      if ((*(byte *)(*(longlong *)(DAT_182d39ea8 + 0x20) + 0x135) & 1) == 0) {
        FUN_180320470();
      }
      if (*(int *)(DAT_182d24690 + 0xe0) == 0) {
        FUN_18035c820();
      }
      local_38 = 0;
      uStack_30 = 0;
      uVar8 = FUN_18161e8f0(uVar7,&local_38,0,0);
      uVar8 = System_String__Concat__0600021b(uVar8,DAT_182d5f2b0,0);
      if (plVar2 != (longlong *)0x0) {
        (**(code **)(*plVar2 + 0x558))(plVar2,uVar8,*(undefined8 *)(*plVar2 + 0x560));
        lVar10 = *(longlong *)(param_1 + 0x38);
        if (lVar10 != 0) {
          pcVar9 = DAT_182ec1138;
          if ((DAT_182ec1138 == (code *)0x0) &&
             (pcVar9 = (code *)FUN_1802cf0c0("UnityEngine.GameObject::SetActive(System.Boolean)"),
             pcVar9 == (code *)0x0)) {
            uVar8 = FUN_1802ced60("UnityEngine.GameObject::SetActive(System.Boolean)");
                    /* WARNING: Subroutine does not return */
            FUN_1802cca90(uVar8,0);
          }
          DAT_182ec1138 = pcVar9;
          (*DAT_182ec1138)(lVar10,param_3);
          lVar10 = FUN_180002c20(3,DAT_182d61530,param_2);
          if ((lVar10 == 0) || (*(int *)(lVar10 + 0x10) == 0)) {
            uVar4 = 0;
          }
          else {
            uVar4 = 1;
          }
          lVar10 = *(longlong *)(param_1 + 0x60);
          *(undefined1 *)(param_1 + 0xc1) = uVar4;
          if (lVar10 != 0) {
            pcVar9 = DAT_182ec1138;
            if ((DAT_182ec1138 == (code *)0x0) &&
               (pcVar9 = (code *)FUN_1802cf0c0("UnityEngine.GameObject::SetActive(System.Boolean)"),
               pcVar9 == (code *)0x0)) {
              uVar8 = FUN_1802ced60("UnityEngine.GameObject::SetActive(System.Boolean)");
                    /* WARNING: Subroutine does not return */
              FUN_1802cca90(uVar8,0);
            }
            DAT_182ec1138 = pcVar9;
            (*DAT_182ec1138)(lVar10,0);
            if (*(char *)(param_1 + 0xc1) == '\0') {
              lVar10 = *(longlong *)(param_1 + 0x70);
              if (lVar10 == 0) goto LAB_1804d7399;
              pcVar9 = DAT_182ec1138;
              if ((DAT_182ec1138 == (code *)0x0) &&
                 (pcVar9 = (code *)FUN_1802cf0c0("UnityEngine.GameObject::SetActive(System.Boolean)"
                                                ), pcVar9 == (code *)0x0)) {
                uVar8 = FUN_1802ced60("UnityEngine.GameObject::SetActive(System.Boolean)");
                    /* WARNING: Subroutine does not return */
                FUN_1802cca90(uVar8,0);
              }
              DAT_182ec1138 = pcVar9;
              uVar8 = 0;
            }
            else {
              plVar2 = *(longlong **)(param_1 + 0x68);
              uVar8 = FUN_180002c20(3,DAT_182d61530,param_2);
              uVar8 = ExposureUnnoticed2_Scripts_Base_Localizer__Trans__060017af(uVar8,0);
              if (plVar2 == (longlong *)0x0) goto LAB_1804d7399;
              (**(code **)(*plVar2 + 0x558))(plVar2,uVar8,*(undefined8 *)(*plVar2 + 0x560));
              lVar10 = *(longlong *)(param_1 + 0x70);
              if (lVar10 == 0) goto LAB_1804d7399;
              pcVar9 = DAT_182ec1138;
              if ((DAT_182ec1138 == (code *)0x0) &&
                 (pcVar9 = (code *)FUN_1802cf0c0("UnityEngine.GameObject::SetActive(System.Boolean)"
                                                ), pcVar9 == (code *)0x0)) {
                uVar8 = FUN_1802ced60("UnityEngine.GameObject::SetActive(System.Boolean)");
                    /* WARNING: Subroutine does not return */
                FUN_1802cca90(uVar8,0);
              }
              DAT_182ec1138 = pcVar9;
              uVar8 = 1;
            }
            (*DAT_182ec1138)(lVar10,uVar8);
            lVar10 = *(longlong *)(param_1 + 0x48);
            if (lVar10 != 0) {
              pcVar9 = DAT_182ec1138;
              if ((DAT_182ec1138 == (code *)0x0) &&
                 (pcVar9 = (code *)FUN_1802cf0c0("UnityEngine.GameObject::SetActive(System.Boolean)"
                                                ), pcVar9 == (code *)0x0)) {
                uVar8 = FUN_1802ced60("UnityEngine.GameObject::SetActive(System.Boolean)");
                    /* WARNING: Subroutine does not return */
                FUN_1802cca90(uVar8,0);
              }
              DAT_182ec1138 = pcVar9;
              (*DAT_182ec1138)(lVar10,0);
              lVar10 = *(longlong *)(param_1 + 0x40);
              if (lVar10 != 0) {
                pcVar9 = DAT_182ec1138;
                if ((DAT_182ec1138 == (code *)0x0) &&
                   (pcVar9 = (code *)FUN_1802cf0c0(
                                                  "UnityEngine.GameObject::SetActive(System.Boolean)"
                                                  ), pcVar9 == (code *)0x0)) {
                  uVar8 = FUN_1802ced60("UnityEngine.GameObject::SetActive(System.Boolean)");
                    /* WARNING: Subroutine does not return */
                  FUN_1802cca90(uVar8,0);
                }
                DAT_182ec1138 = pcVar9;
                (*DAT_182ec1138)(lVar10,0);
                if (*(longlong *)(param_1 + 0x58) != 0) {
                  HadakaCoat_ObjectsUi_Common_Button_ButtonView__SetMask__06001e04
                            (*(longlong *)(param_1 + 0x58),0,0,0);
                  if (param_3 == '\0') {
                    if ((*(byte *)(DAT_182d5da48 + 0x130) <= *(byte *)(*param_2 + 0x130)) &&
                       (*(longlong *)
                         (*(longlong *)(*param_2 + 200) + -8 +
                         (ulonglong)*(byte *)(DAT_182d5da48 + 0x130) * 8) == DAT_182d5da48)) {
                      cVar5 = ExposureUnnoticed2_Master_Achievement_MAchievement__IsRelease__06001392
                                        ((int)param_2[0x1a],0);
                      if (cVar5 == '\0') {
                        if (*(longlong *)(param_1 + 0x40) == 0) goto LAB_1804d7399;
                        FUN_181f3ea80(*(longlong *)(param_1 + 0x40),1,0);
                        if (*(longlong *)(param_1 + 0x58) == 0) goto LAB_1804d7399;
                        HadakaCoat_ObjectsUi_Common_Button_ButtonView__SetMask__06001e04
                                  (*(longlong *)(param_1 + 0x58),1,0,0);
                      }
                      else {
                        if ((((**(longlong **)(DAT_182d58378 + 0xb8) == 0) ||
                             (lVar10 = *(longlong *)(**(longlong **)(DAT_182d58378 + 0xb8) + 0x40),
                             lVar10 == 0)) || (lVar10 = *(longlong *)(lVar10 + 0x60), lVar10 == 0))
                           || (lVar10 = *(longlong *)(lVar10 + 0x128), lVar10 == 0))
                        goto LAB_1804d7399;
                        if (*(int *)(lVar10 + 0x18) < (int)param_2[0xf]) {
                          if (*(longlong *)(param_1 + 0x48) == 0) goto LAB_1804d7399;
                          FUN_181f3ea80(*(longlong *)(param_1 + 0x48),1,0);
                          plVar2 = *(longlong **)(param_1 + 0x50);
                          uVar8 = ExposureUnnoticed2_Scripts_InGame_GameStateFacade__GetRankNameAutoHide__06001568
                                            ((int)param_2[0xf],0);
                          uVar8 = ExposureUnnoticed2_Scripts_Base_Localizer__Trans__060017b0
                                            (DAT_182d61ba0,uVar8,0);
                          if (plVar2 == (longlong *)0x0) goto LAB_1804d7399;
                          (**(code **)(*plVar2 + 0x558))
                                    (plVar2,uVar8,*(undefined8 *)(*plVar2 + 0x560));
                        }
                      }
                    }
                  }
                  lVar10 = *(longlong *)(param_1 + 0x38);
                  if (lVar10 != 0) {
                    pcVar9 = DAT_182ec1148;
                    if ((DAT_182ec1148 == (code *)0x0) &&
                       (pcVar9 = (code *)FUN_1802cf0c0(
                                                  "UnityEngine.GameObject::get_activeInHierarchy()")
                       , pcVar9 == (code *)0x0)) {
                      uVar8 = FUN_1802ced60("UnityEngine.GameObject::get_activeInHierarchy()");
                    /* WARNING: Subroutine does not return */
                      FUN_1802cca90(uVar8,0);
                    }
                    DAT_182ec1148 = pcVar9;
                    cVar5 = (*DAT_182ec1148)(lVar10);
                    if (cVar5 == '\0') {
                      lVar10 = *(longlong *)(param_1 + 0x48);
                      if (lVar10 == 0) goto LAB_1804d7399;
                      pcVar9 = DAT_182ec1148;
                      if ((DAT_182ec1148 == (code *)0x0) &&
                         (pcVar9 = (code *)FUN_1802cf0c0(
                                                  "UnityEngine.GameObject::get_activeInHierarchy()")
                         , pcVar9 == (code *)0x0)) {
                        uVar8 = FUN_1802ced60("UnityEngine.GameObject::get_activeInHierarchy()");
                    /* WARNING: Subroutine does not return */
                        FUN_1802cca90(uVar8,0);
                      }
                      DAT_182ec1148 = pcVar9;
                      cVar5 = (*DAT_182ec1148)(lVar10);
                      if (cVar5 == '\0') {
                        lVar10 = *(longlong *)(param_1 + 0x40);
                        if (lVar10 == 0) goto LAB_1804d7399;
                        pcVar9 = DAT_182ec1148;
                        if ((DAT_182ec1148 == (code *)0x0) &&
                           (pcVar9 = (code *)FUN_1802cf0c0(
                                                  "UnityEngine.GameObject::get_activeInHierarchy()")
                           , pcVar9 == (code *)0x0)) {
                          uVar8 = FUN_1802ced60("UnityEngine.GameObject::get_activeInHierarchy()");
                    /* WARNING: Subroutine does not return */
                          FUN_1802cca90(uVar8,0);
                        }
                        DAT_182ec1148 = pcVar9;
                        cVar6 = (*DAT_182ec1148)(lVar10);
                      }
                    }
                    *(bool *)(param_1 + 0xc2) = cVar6 != '\0';
                    lVar10 = *(longlong *)(param_1 + 0x78);
                    if (lVar10 != 0) {
                      pcVar9 = DAT_182ec1138;
                      if ((DAT_182ec1138 == (code *)0x0) &&
                         (pcVar9 = (code *)FUN_1802cf0c0(
                                                  "UnityEngine.GameObject::SetActive(System.Boolean)"
                                                  ), pcVar9 == (code *)0x0)) {
                        uVar8 = FUN_1802ced60("UnityEngine.GameObject::SetActive(System.Boolean)");
                    /* WARNING: Subroutine does not return */
                        FUN_1802cca90(uVar8,0);
                      }
                      DAT_182ec1138 = pcVar9;
                      (*DAT_182ec1138)(lVar10,0);
                      lVar10 = *(longlong *)(param_1 + 0x80);
                      if (lVar10 != 0) {
                        pcVar9 = DAT_182ec1138;
                        if ((DAT_182ec1138 == (code *)0x0) &&
                           (pcVar9 = (code *)FUN_1802cf0c0(
                                                  "UnityEngine.GameObject::SetActive(System.Boolean)"
                                                  ), pcVar9 == (code *)0x0)) {
                          uVar8 = FUN_1802ced60("UnityEngine.GameObject::SetActive(System.Boolean)")
                          ;
                    /* WARNING: Subroutine does not return */
                          FUN_1802cca90(uVar8,0);
                        }
                        DAT_182ec1138 = pcVar9;
                        (*DAT_182ec1138)(lVar10,0);
                        if ((*(byte *)(*param_2 + 0x130) < *(byte *)(DAT_182d5da48 + 0x130)) ||
                           (*(longlong *)
                             (*(longlong *)(*param_2 + 200) + -8 +
                             (ulonglong)*(byte *)(DAT_182d5da48 + 0x130) * 8) != DAT_182d5da48)) {
                          return;
                        }
                        lVar10 = *(longlong *)(param_1 + 0x78);
                        lVar3 = param_2[0x11];
                        if (lVar10 != 0) {
                          pcVar9 = DAT_182ec1138;
                          if ((DAT_182ec1138 == (code *)0x0) &&
                             (pcVar9 = (code *)FUN_1802cf0c0(
                                                  "UnityEngine.GameObject::SetActive(System.Boolean)"
                                                  ), pcVar9 == (code *)0x0)) {
                            uVar8 = FUN_1802ced60(
                                                 "UnityEngine.GameObject::SetActive(System.Boolean)"
                                                 );
                    /* WARNING: Subroutine does not return */
                            FUN_1802cca90(uVar8,0);
                          }
                          DAT_182ec1138 = pcVar9;
                          (*DAT_182ec1138)(lVar10,(char)lVar3);
                          bVar14 = DAT_182eb5d50 != 0;
                          *(undefined8 *)(param_1 + 0xa0) = param_6;
                          if (bVar14) {
                            uVar13 = (uint)(param_1 + 0xa0U >> 0xc);
                            lVar10 = (ulonglong)((uVar13 & 0x1fffff) >> 6) * 8;
                            do {
                              uVar1 = *(ulonglong *)(&DAT_182f0c920 + lVar10);
                              LOCK();
                              bVar14 = uVar1 == *(ulonglong *)(&DAT_182f0c920 + lVar10);
                              if (bVar14) {
                                *(ulonglong *)(&DAT_182f0c920 + lVar10) =
                                     uVar1 | 1L << (uVar13 & 0x3f);
                              }
                              UNLOCK();
                            } while (!bVar14);
                          }
                          lVar10 = *(longlong *)(param_1 + 0x80);
                          iVar11 = *(int *)((longlong)param_2 + 0x54);
                          if (lVar10 != 0) {
                            pcVar9 = DAT_182ec1138;
                            if ((DAT_182ec1138 == (code *)0x0) &&
                               (pcVar9 = (code *)FUN_1802cf0c0(
                                                  "UnityEngine.GameObject::SetActive(System.Boolean)"
                                                  ), pcVar9 == (code *)0x0)) {
                              uVar8 = FUN_1802ced60(
                                                  "UnityEngine.GameObject::SetActive(System.Boolean)"
                                                  );
                    /* WARNING: Subroutine does not return */
                              FUN_1802cca90(uVar8,0);
                            }
                            DAT_182ec1138 = pcVar9;
                            (*DAT_182ec1138)(lVar10,iVar11 != 0);
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
LAB_1804d7399:
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

