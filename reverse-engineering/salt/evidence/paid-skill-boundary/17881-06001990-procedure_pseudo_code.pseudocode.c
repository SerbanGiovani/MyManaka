// Ghidra pseudocode; not original source or compilable C.
// ev_39673f60a646faee147d4e3ae764bd467017eac081f1b0b9f22fddf7b8060cd6

void ExposureUnnoticed2_ObjectUI_SaveDataSelectPanel_SkillPanelView__Open__06001990
               (undefined8 param_1)

{
  ulonglong *puVar1;
  ulonglong uVar2;
  int iVar3;
  ulonglong uVar4;
  char cVar5;
  longlong lVar6;
  longlong lVar7;
  undefined8 *puVar8;
  longlong lVar9;
  undefined8 uVar10;
  undefined1 *puVar11;
  longlong *plVar12;
  longlong *plVar13;
  longlong lVar14;
  code *pcVar15;
  undefined8 uVar16;
  ushort uVar17;
  uint uVar18;
  bool bVar19;
  ulonglong in_stack_ffffffffffffff68;
  undefined8 uVar20;
  longlong lVar21;
  undefined1 auStack_48 [16];
  
  if (cRam0000000182eb7c1f == '\0') {
    FUN_1802f2810(&DAT_182d58238);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d63490);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d58380);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d63488);
    LOCK();
    UNLOCK();
    cRam0000000182eb7c1f = '\x01';
  }
  if (*(int *)(DAT_182d58380 + 0xe0) == 0) {
    FUN_18035c820(DAT_182d58380);
  }
  if (((**(longlong **)(DAT_182d58238 + 0xb8) != 0) && (**(longlong **)(DAT_182d58380 + 0xb8) != 0))
     && (plVar12 = (longlong *)
                   ExposureUnnoticed2_Object3D_IngameManager_InGameUiManager__Open__060011a0
                             (**(longlong **)(DAT_182d58380 + 0xb8),
                              *(undefined8 *)(**(longlong **)(DAT_182d58238 + 0xb8) + 0x128),0,0),
        plVar12 != (longlong *)0x0)) {
    if ((*(byte *)(lRam0000000182d63488 + 0x130) <= *(byte *)(*plVar12 + 0x130)) &&
       (lVar14 = *(longlong *)(*plVar12 + 200),
       *(longlong *)(lVar14 + -8 + (ulonglong)*(byte *)(lRam0000000182d63488 + 0x130) * 8) ==
       lRam0000000182d63488)) {
      plVar13 = (longlong *)0x0;
      if (*(longlong *)(lVar14 + -8 + (ulonglong)*(byte *)(lRam0000000182d63488 + 0x130) * 8) ==
          lRam0000000182d63488) {
        plVar13 = plVar12;
      }
      lVar14 = FUN_180735980(plVar13,uRam0000000182d63490);
      if (lVar14 != 0) {
        if (cRam0000000182eb7c18 == '\0') {
          FUN_1802f2810(0x182d61940);
          LOCK();
          UNLOCK();
          FUN_1802f2810(0x182d635b8);
          LOCK();
          UNLOCK();
          cRam0000000182eb7c18 = '\x01';
        }
        bVar19 = DAT_182eb5d50 != 0;
        *(undefined8 *)(lVar14 + 0x98) = param_1;
        if (bVar19) {
          uVar18 = (uint)(lVar14 + 0x98U >> 0xc);
          puVar1 = (ulonglong *)(&DAT_182f0c920 + (ulonglong)((uVar18 & 0x1fffff) >> 6) * 8);
          do {
            uVar4 = *puVar1;
            LOCK();
            uVar2 = *puVar1;
            if (uVar4 == uVar2) {
              *puVar1 = uVar4 | 1L << (uVar18 & 0x3f);
            }
            UNLOCK();
          } while (uVar4 != uVar2);
        }
        lVar21 = *(longlong *)(lVar14 + 0x80);
        if (lVar21 != 0) {
          pcVar15 = DAT_182ec1138;
          if ((DAT_182ec1138 == (code *)0x0) &&
             (pcVar15 = (code *)FUN_1802cf0c0("UnityEngine.GameObject::SetActive(System.Boolean)"),
             pcVar15 == (code *)0x0)) {
            uVar16 = FUN_1802ced60("UnityEngine.GameObject::SetActive(System.Boolean)");
                    /* WARNING: Subroutine does not return */
            FUN_1802cca90(uVar16,0);
          }
          DAT_182ec1138 = pcVar15;
          (*DAT_182ec1138)(lVar21,0);
          lVar21 = *(longlong *)(lVar14 + 0x68);
          uVar16 = FUN_1802c43a0(uRam0000000182d61940);
          FUN_180006cd0(uVar16,lVar14,uRam0000000182d635b8);
          if (lVar21 != 0) {
            ExposureUnnoticed2_ObjectUI_CommonUI_CommonTab_CommonTabView__Initialize__06001da6
                      (lVar21,uVar16,0,0);
            if (cRam0000000182eb7c1b == '\0') {
              FUN_1802f2810(0x182d61890,0,0);
              LOCK();
              UNLOCK();
              FUN_1802f2810(&DAT_182d58368);
              LOCK();
              UNLOCK();
              FUN_1802f2810(0x182d63590);
              LOCK();
              UNLOCK();
              FUN_1802f2810(&DAT_182d58288);
              LOCK();
              UNLOCK();
              FUN_1802f2810(0x182d63588);
              LOCK();
              UNLOCK();
              FUN_1802f2810(0x182d63580);
              LOCK();
              UNLOCK();
              FUN_1802f2810(&DAT_182d58398);
              LOCK();
              UNLOCK();
              FUN_1802f2810(&DAT_182d53498);
              LOCK();
              UNLOCK();
              FUN_1802f2810(0x182d63578);
              LOCK();
              UNLOCK();
              FUN_1802f2810(0x182d63570);
              LOCK();
              UNLOCK();
              FUN_1802f2810(&DAT_182d52f28);
              LOCK();
              UNLOCK();
              FUN_1802f2810(0x182d63568);
              LOCK();
              UNLOCK();
              FUN_1802f2810(0x182d63560);
              LOCK();
              UNLOCK();
              FUN_1802f2810(0x182d63558);
              LOCK();
              UNLOCK();
              FUN_1802f2810(&DAT_182d54d90);
              LOCK();
              UNLOCK();
              FUN_1802f2810(&DAT_182d53aa8);
              LOCK();
              UNLOCK();
              FUN_1802f2810(0x182d63550);
              LOCK();
              UNLOCK();
              FUN_1802f2810(0x182d63548);
              LOCK();
              UNLOCK();
              FUN_1802f2810(0x182d63540);
              LOCK();
              UNLOCK();
              FUN_1802f2810(&DAT_182d5bfa0);
              LOCK();
              UNLOCK();
              FUN_1802f2810(0x182d63538);
              LOCK();
              UNLOCK();
              FUN_1802f2810(0x182d63530);
              LOCK();
              UNLOCK();
              cRam0000000182eb7c1b = '\x01';
            }
            uVar16 = *(undefined8 *)(lVar14 + 0x58);
            if (*(int *)(DAT_182d58288 + 0xe0) == 0) {
              FUN_18035c820();
            }
            ExposureUnnoticed2_Scripts_Base_ExternalMethodManager__DestroyChildren__0600172c
                      (uVar16,0);
            lVar21 = *(longlong *)(lVar14 + 0xa0);
            if (lVar21 != 0) {
              *(int *)(lVar21 + 0x1c) = *(int *)(lVar21 + 0x1c) + 1;
              iVar3 = *(int *)(lVar21 + 0x18);
              *(undefined4 *)(lVar21 + 0x18) = 0;
              if (0 < iVar3) {
                FUN_181646f50(*(undefined8 *)(lVar21 + 0x10),0,iVar3,0);
              }
              lVar21 = 0;
              if (cRam0000000182eb783e == '\0') {
                FUN_1802f2810(0x182d5c668);
                LOCK();
                UNLOCK();
                cRam0000000182eb783e = '\x01';
              }
              ExposureUnnoticed2_Master_Skill_MSkill__CheckInitialize__06001231(0);
              uVar16 = **(undefined8 **)(lRam0000000182d5c668 + 0xb8);
              if (*(int *)(lRam0000000182d63530 + 0xe0) == 0) {
                FUN_18035c820();
              }
              lVar6 = *(longlong *)(*(longlong *)(lRam0000000182d63530 + 0xb8) + 8);
              if (lVar6 == 0) {
                if (*(int *)(lRam0000000182d63530 + 0xe0) == 0) {
                  FUN_18035c820();
                }
                uVar20 = **(undefined8 **)(lRam0000000182d63530 + 0xb8);
                lVar6 = FUN_1802c43a0(uRam0000000182d63588);
                FUN_1810cf720(lVar6,uVar20,uRam0000000182d63538,0);
                *(longlong *)(*(longlong *)(lRam0000000182d63530 + 0xb8) + 8) = lVar6;
                if (DAT_182eb5d50 != 0) {
                  uVar18 = (uint)(*(longlong *)(lRam0000000182d63530 + 0xb8) + 8U >> 0xc);
                  lVar9 = (ulonglong)((uVar18 & 0x1fffff) >> 6) * 8;
                  do {
                    uVar2 = *(ulonglong *)(&DAT_182f0c920 + lVar9);
                    LOCK();
                    bVar19 = uVar2 == *(ulonglong *)(&DAT_182f0c920 + lVar9);
                    if (bVar19) {
                      *(ulonglong *)(&DAT_182f0c920 + lVar9) = uVar2 | 1L << (uVar18 & 0x3f);
                    }
                    UNLOCK();
                  } while (!bVar19);
                }
              }
              lVar9 = lRam0000000182d63590;
              if (*(longlong *)(lRam0000000182d63590 + 0x38) == 0) {
                FUN_1803204f0(lRam0000000182d63590);
              }
              lVar7 = *(longlong *)(*(longlong *)(lVar9 + 0x38) + 0x10);
              if ((*(byte *)(lVar7 + 0x135) & 1) == 0) {
                lVar7 = FUN_180320470(lVar7);
              }
              lVar7 = FUN_1802c43a0(lVar7);
              uVar20 = *(undefined8 *)(*(longlong *)(lVar9 + 0x38) + 0x18);
              in_stack_ffffffffffffff68 = in_stack_ffffffffffffff68 & 0xffffffffffffff00;
              FUN_1813a47a0(lVar7,uVar16,lVar6,0,in_stack_ffffffffffffff68,uVar20);
              if (lVar7 != 0) {
                plVar12 = (longlong *)FUN_180002c20(0,uRam0000000182d63578,lVar7);
                lVar6 = 0;
code_r0x0001804e7025:
                if (plVar12 == (longlong *)0x0) {
                    /* WARNING: Subroutine does not return */
                  FUN_18031dad0();
                }
                cVar5 = FUN_180002c20(0,DAT_182d52f28);
                if (cVar5 != '\0') {
                  if (plVar12 == (longlong *)0x0) {
                    /* WARNING: Subroutine does not return */
                    FUN_18031dad0();
                  }
                  lVar9 = *plVar12;
                  uVar17 = 0;
                  if (*(ushort *)(lVar9 + 0x12e) != 0) {
                    do {
                      if (*(longlong *)(*(longlong *)(lVar9 + 0xb0) + (ulonglong)uVar17 * 0x10) ==
                          lRam0000000182d63570) {
                        puVar8 = (undefined8 *)
                                 ((longlong)
                                  *(int *)(*(longlong *)(lVar9 + 0xb0) + 8 +
                                          (ulonglong)uVar17 * 0x10) * 0x10 + 0x138 + lVar9);
                        goto code_r0x0001804e70a9;
                      }
                      uVar17 = uVar17 + 1;
                    } while (uVar17 < *(ushort *)(lVar9 + 0x12e));
                  }
                  puVar8 = (undefined8 *)FUN_180320910(plVar12,lRam0000000182d63570,0);
code_r0x0001804e70a9:
                  lVar9 = (*(code *)*puVar8)(auStack_48,plVar12,puVar8[1]);
                  lVar9 = *(longlong *)(lVar9 + 8);
                  if (*(int *)(DAT_182d5bfa0 + 0xe0) == 0) {
                    FUN_18035c820();
                  }
                  if (**(char **)(DAT_182d5bfa0 + 0xb8) != '\0') goto code_r0x0001804e70f7;
                  goto code_r0x0001804e7139;
                }
                if (plVar12 != (longlong *)0x0) {
                  FUN_180002c20(0,DAT_182d53498,plVar12);
                }
                ExposureUnnoticed2_ObjectUI_SaveDataSelectPanel_SkillPanelView__OnClickItem__0600198e
                          (lVar14,lVar6,0);
                if (*(longlong *)(lVar14 + 0x88) != 0) {
                  HadakaCoat_ObjectsUi_Common_Button_ButtonGroupManager__ReSearchButton__06001de5
                            (*(longlong *)(lVar14 + 0x88),0,0,0,in_stack_ffffffffffffff68,uVar20,
                             lVar21);
                  lVar6 = FUN_1802c43a0(DAT_182d58368);
                  lVar21 = lRam0000000182d63540;
                  *(undefined8 *)(lVar6 + 0x10) = *(undefined8 *)(lRam0000000182d63540 + 8);
                  *(longlong *)(lVar6 + 0x28) = lVar21;
                  *(longlong *)(lVar6 + 0x20) = lVar14;
                  if (DAT_182eb5d50 != 0) {
                    uVar18 = (uint)(lVar6 + 0x20U >> 0xc);
                    lVar14 = (ulonglong)((uVar18 & 0x1fffff) >> 6) * 8;
                    do {
                      uVar2 = *(ulonglong *)(&DAT_182f0c920 + lVar14);
                      LOCK();
                      bVar19 = uVar2 == *(ulonglong *)(&DAT_182f0c920 + lVar14);
                      if (bVar19) {
                        *(ulonglong *)(&DAT_182f0c920 + lVar14) = uVar2 | 1L << (uVar18 & 0x3f);
                      }
                      UNLOCK();
                    } while (!bVar19);
                  }
                  cVar5 = *(char *)(lVar21 + 0x52);
                  *(longlong *)(lVar6 + 0x40) = lVar6;
                  if (((*(byte *)(lVar21 + 0x4c) & 0x10) == 0) || (cVar5 != '\0')) {
                    *(undefined8 *)(lVar6 + 0x40) = *(undefined8 *)(lVar6 + 0x20);
                    puVar11 = *(undefined1 **)(lVar6 + 0x10);
                  }
                  else {
                    puVar11 = &LAB_1800c7840;
                  }
                  *(undefined1 **)(lVar6 + 0x18) = puVar11;
                  *(code **)(lVar6 + 0x38) = FUN_1801e91e0;
                  ExposureUnnoticed2_Scripts_Base_Scheduler__DelayFlame__0600174b(lVar6,1,0);
                  return;
                }
              }
            }
                    /* WARNING: Subroutine does not return */
            FUN_18031dad0();
          }
        }
      }
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
code_r0x0001804e70f7:
  if (lVar9 == 0) {
                    /* WARNING: Subroutine does not return */
    FUN_18031dad0();
  }
  if (*(int *)(lVar9 + 0x34) == 0) {
code_r0x0001804e7139:
    if (lVar9 == 0) {
                    /* WARNING: Subroutine does not return */
      FUN_18031dad0();
    }
    if (*(int *)(lVar9 + 0x40) == 0) {
      lVar7 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x38);
      if (lVar7 == 0) {
                    /* WARNING: Subroutine does not return */
        FUN_18031dad0();
      }
      if (((*(char *)(lVar7 + 0x10) == '\0') || (*(int *)(lVar9 + 0x3c) != 0x2723)) &&
         ((*(char *)(lVar7 + 0x12) == '\0' || (*(int *)(lVar9 + 0x3c) != 0x16)))) {
        uVar16 = *(undefined8 *)(lVar14 + 0x60);
        uVar10 = *(undefined8 *)(lVar14 + 0x58);
        if (*(int *)(DAT_182d53aa8 + 0xe0) == 0) {
          FUN_18035c820();
        }
        lVar7 = FUN_1809f1050(uVar16,uVar10,DAT_182d54d90);
        if (lVar7 == 0) {
                    /* WARNING: Subroutine does not return */
          FUN_18031dad0();
        }
        lVar7 = FUN_1809a08f0(lVar7,uRam0000000182d63580);
        uVar16 = FUN_1802c43a0(uRam0000000182d61890);
        FUN_180665bb0(uVar16,lVar14,uRam0000000182d63550,0);
        uVar10 = FUN_1802c43a0(uRam0000000182d61890);
        FUN_180665bb0(uVar10,lVar14,uRam0000000182d63548,0);
        if (lVar7 == 0) {
                    /* WARNING: Subroutine does not return */
          FUN_18031dad0();
        }
        in_stack_ffffffffffffff68 = 0;
        ExposureUnnoticed2_ObjectUI_SkillPanel_SkillItemView__Initialize__0600182b
                  (lVar7,lVar9,uVar16);
        if (*(longlong *)(lVar14 + 0xa0) == 0) {
                    /* WARNING: Subroutine does not return */
          FUN_18031dad0();
        }
        FUN_1803d4be0(*(longlong *)(lVar14 + 0xa0),lVar7,uRam0000000182d63560);
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
          FUN_1802f2810();
          LOCK();
          UNLOCK();
          DAT_182ec129b = '\x01';
        }
        if (lVar6 != 0) {
          if (*(int *)(DAT_182d53aa8 + 0xe0) == 0) {
            FUN_18035c820();
          }
          if (*(longlong *)(lVar6 + 0x10) != 0) goto code_r0x0001804e7025;
        }
        lVar6 = lVar9;
        lVar21 = lVar9;
      }
    }
  }
  goto code_r0x0001804e7025;
}

