// Ghidra pseudocode; not original source or compilable C.
// ev_9902886007d59925cba65c6b5d4315a28a41a1faca4bf7bcd08b2e701aee7043

void ExposureUnnoticed2_ObjectUI_SaveDataSelectPanel_SkillPanelView__OnClickTab__0600198c
               (longlong param_1,int param_2)

{
  int iVar1;
  ulonglong uVar2;
  char cVar3;
  longlong lVar4;
  longlong lVar5;
  longlong *plVar6;
  undefined8 *puVar7;
  longlong lVar8;
  undefined8 uVar9;
  undefined8 uVar10;
  undefined1 *puVar11;
  ushort uVar12;
  uint uVar13;
  bool bVar14;
  ulonglong in_stack_ffffffffffffff68;
  undefined8 uVar15;
  longlong lVar16;
  undefined1 auStack_48 [16];
  
  if (cRam0000000182eb7c1b == '\0') {
    FUN_1802f2810(0x182d61890);
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
  uVar9 = *(undefined8 *)(param_1 + 0x58);
  if (*(int *)(DAT_182d58288 + 0xe0) == 0) {
    FUN_18035c820();
  }
  ExposureUnnoticed2_Scripts_Base_ExternalMethodManager__DestroyChildren__0600172c(uVar9,0);
  lVar16 = *(longlong *)(param_1 + 0xa0);
  if (lVar16 != 0) {
    *(int *)(lVar16 + 0x1c) = *(int *)(lVar16 + 0x1c) + 1;
    iVar1 = *(int *)(lVar16 + 0x18);
    *(undefined4 *)(lVar16 + 0x18) = 0;
    if (0 < iVar1) {
      FUN_181646f50(*(undefined8 *)(lVar16 + 0x10),0,iVar1,0);
    }
    lVar16 = 0;
    if (cRam0000000182eb783e == '\0') {
      FUN_1802f2810(0x182d5c668);
      LOCK();
      UNLOCK();
      cRam0000000182eb783e = '\x01';
    }
    ExposureUnnoticed2_Master_Skill_MSkill__CheckInitialize__06001231(0);
    uVar9 = **(undefined8 **)(lRam0000000182d5c668 + 0xb8);
    if (*(int *)(lRam0000000182d63530 + 0xe0) == 0) {
      FUN_18035c820();
    }
    lVar4 = *(longlong *)(*(longlong *)(lRam0000000182d63530 + 0xb8) + 8);
    if (lVar4 == 0) {
      if (*(int *)(lRam0000000182d63530 + 0xe0) == 0) {
        FUN_18035c820();
      }
      uVar15 = **(undefined8 **)(lRam0000000182d63530 + 0xb8);
      lVar4 = FUN_1802c43a0(uRam0000000182d63588);
      FUN_1810cf720(lVar4,uVar15,uRam0000000182d63538,0);
      *(longlong *)(*(longlong *)(lRam0000000182d63530 + 0xb8) + 8) = lVar4;
      if (DAT_182eb5d50 != 0) {
        uVar13 = (uint)(*(longlong *)(lRam0000000182d63530 + 0xb8) + 8U >> 0xc);
        lVar8 = (ulonglong)((uVar13 & 0x1fffff) >> 6) * 8;
        do {
          uVar2 = *(ulonglong *)(&DAT_182f0c920 + lVar8);
          LOCK();
          bVar14 = uVar2 == *(ulonglong *)(&DAT_182f0c920 + lVar8);
          if (bVar14) {
            *(ulonglong *)(&DAT_182f0c920 + lVar8) = uVar2 | 1L << (uVar13 & 0x3f);
          }
          UNLOCK();
        } while (!bVar14);
      }
    }
    lVar8 = lRam0000000182d63590;
    if (*(longlong *)(lRam0000000182d63590 + 0x38) == 0) {
      FUN_1803204f0(lRam0000000182d63590);
    }
    lVar5 = *(longlong *)(*(longlong *)(lVar8 + 0x38) + 0x10);
    if ((*(byte *)(lVar5 + 0x135) & 1) == 0) {
      lVar5 = FUN_180320470(lVar5);
    }
    lVar5 = FUN_1802c43a0(lVar5);
    uVar15 = *(undefined8 *)(*(longlong *)(lVar8 + 0x38) + 0x18);
    in_stack_ffffffffffffff68 = in_stack_ffffffffffffff68 & 0xffffffffffffff00;
    FUN_1813a47a0(lVar5,uVar9,lVar4,0,in_stack_ffffffffffffff68,uVar15);
    if (lVar5 != 0) {
      plVar6 = (longlong *)FUN_180002c20(0,uRam0000000182d63578,lVar5);
      lVar4 = 0;
code_r0x0001804e7025:
      if (plVar6 == (longlong *)0x0) {
                    /* WARNING: Subroutine does not return */
        FUN_18031dad0();
      }
      cVar3 = FUN_180002c20(0,DAT_182d52f28);
      if (cVar3 != '\0') {
        if (plVar6 == (longlong *)0x0) {
                    /* WARNING: Subroutine does not return */
          FUN_18031dad0();
        }
        lVar8 = *plVar6;
        uVar12 = 0;
        if (*(ushort *)(lVar8 + 0x12e) != 0) {
          do {
            if (*(longlong *)(*(longlong *)(lVar8 + 0xb0) + (ulonglong)uVar12 * 0x10) ==
                lRam0000000182d63570) {
              puVar7 = (undefined8 *)
                       ((longlong)
                        *(int *)(*(longlong *)(lVar8 + 0xb0) + 8 + (ulonglong)uVar12 * 0x10) * 0x10
                        + 0x138 + lVar8);
              goto code_r0x0001804e70a9;
            }
            uVar12 = uVar12 + 1;
          } while (uVar12 < *(ushort *)(lVar8 + 0x12e));
        }
        puVar7 = (undefined8 *)FUN_180320910(plVar6,lRam0000000182d63570,0);
code_r0x0001804e70a9:
        lVar8 = (*(code *)*puVar7)(auStack_48,plVar6,puVar7[1]);
        lVar8 = *(longlong *)(lVar8 + 8);
        if (*(int *)(DAT_182d5bfa0 + 0xe0) == 0) {
          FUN_18035c820();
        }
        if (**(char **)(DAT_182d5bfa0 + 0xb8) != '\0') goto code_r0x0001804e70f7;
        goto code_r0x0001804e7139;
      }
      if (plVar6 != (longlong *)0x0) {
        FUN_180002c20(0,DAT_182d53498,plVar6);
      }
      ExposureUnnoticed2_ObjectUI_SaveDataSelectPanel_SkillPanelView__OnClickItem__0600198e
                (param_1,lVar4,0);
      if (*(longlong *)(param_1 + 0x88) != 0) {
        HadakaCoat_ObjectsUi_Common_Button_ButtonGroupManager__ReSearchButton__06001de5
                  (*(longlong *)(param_1 + 0x88),0,0,0,in_stack_ffffffffffffff68,uVar15,lVar16);
        lVar4 = FUN_1802c43a0(DAT_182d58368);
        lVar16 = lRam0000000182d63540;
        *(undefined8 *)(lVar4 + 0x10) = *(undefined8 *)(lRam0000000182d63540 + 8);
        *(longlong *)(lVar4 + 0x28) = lVar16;
        *(longlong *)(lVar4 + 0x20) = param_1;
        if (DAT_182eb5d50 != 0) {
          uVar13 = (uint)(lVar4 + 0x20U >> 0xc);
          lVar8 = (ulonglong)((uVar13 & 0x1fffff) >> 6) * 8;
          do {
            uVar2 = *(ulonglong *)(&DAT_182f0c920 + lVar8);
            LOCK();
            bVar14 = uVar2 == *(ulonglong *)(&DAT_182f0c920 + lVar8);
            if (bVar14) {
              *(ulonglong *)(&DAT_182f0c920 + lVar8) = uVar2 | 1L << (uVar13 & 0x3f);
            }
            UNLOCK();
          } while (!bVar14);
        }
        cVar3 = *(char *)(lVar16 + 0x52);
        *(longlong *)(lVar4 + 0x40) = lVar4;
        if (((*(byte *)(lVar16 + 0x4c) & 0x10) == 0) || (cVar3 != '\0')) {
          *(undefined8 *)(lVar4 + 0x40) = *(undefined8 *)(lVar4 + 0x20);
          puVar11 = *(undefined1 **)(lVar4 + 0x10);
        }
        else {
          puVar11 = &LAB_1800c7840;
        }
        *(undefined1 **)(lVar4 + 0x18) = puVar11;
        *(code **)(lVar4 + 0x38) = FUN_1801e91e0;
        ExposureUnnoticed2_Scripts_Base_Scheduler__DelayFlame__0600174b(lVar4,1,0);
        return;
      }
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
code_r0x0001804e70f7:
  if (lVar8 == 0) {
                    /* WARNING: Subroutine does not return */
    FUN_18031dad0();
  }
  if (*(int *)(lVar8 + 0x34) == 0) {
code_r0x0001804e7139:
    if (lVar8 == 0) {
                    /* WARNING: Subroutine does not return */
      FUN_18031dad0();
    }
    if (*(int *)(lVar8 + 0x40) == param_2) {
      lVar5 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x38);
      if (lVar5 == 0) {
                    /* WARNING: Subroutine does not return */
        FUN_18031dad0();
      }
      if (((*(char *)(lVar5 + 0x10) == '\0') || (*(int *)(lVar8 + 0x3c) != 0x2723)) &&
         ((*(char *)(lVar5 + 0x12) == '\0' || (*(int *)(lVar8 + 0x3c) != 0x16)))) {
        uVar9 = *(undefined8 *)(param_1 + 0x60);
        uVar10 = *(undefined8 *)(param_1 + 0x58);
        if (*(int *)(DAT_182d53aa8 + 0xe0) == 0) {
          FUN_18035c820();
        }
        lVar5 = FUN_1809f1050(uVar9,uVar10,DAT_182d54d90);
        if (lVar5 == 0) {
                    /* WARNING: Subroutine does not return */
          FUN_18031dad0();
        }
        lVar5 = FUN_1809a08f0(lVar5,uRam0000000182d63580);
        uVar9 = FUN_1802c43a0(uRam0000000182d61890);
        FUN_180665bb0(uVar9,param_1,uRam0000000182d63550,0);
        uVar10 = FUN_1802c43a0(uRam0000000182d61890);
        FUN_180665bb0(uVar10,param_1,uRam0000000182d63548,0);
        if (lVar5 == 0) {
                    /* WARNING: Subroutine does not return */
          FUN_18031dad0();
        }
        in_stack_ffffffffffffff68 = 0;
        ExposureUnnoticed2_ObjectUI_SkillPanel_SkillItemView__Initialize__0600182b
                  (lVar5,lVar8,uVar9);
        if (*(longlong *)(param_1 + 0xa0) == 0) {
                    /* WARNING: Subroutine does not return */
          FUN_18031dad0();
        }
        FUN_1803d4be0(*(longlong *)(param_1 + 0xa0),lVar5,uRam0000000182d63560);
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
        if (lVar4 != 0) {
          if (*(int *)(DAT_182d53aa8 + 0xe0) == 0) {
            FUN_18035c820();
          }
          if (*(longlong *)(lVar4 + 0x10) != 0) goto code_r0x0001804e7025;
        }
        lVar4 = lVar8;
        lVar16 = lVar8;
      }
    }
  }
  goto code_r0x0001804e7025;
}

