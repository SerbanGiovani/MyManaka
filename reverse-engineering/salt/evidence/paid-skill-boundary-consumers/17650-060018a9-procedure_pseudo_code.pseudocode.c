// Ghidra pseudocode; not original source or compilable C.
// ev_3eb78e1d9a83427e0306a5215e3c3ab531c308d8650abf9769fdba448ddd0133

void ExposureUnnoticed2_ObjectUI_PcMenuPanel_SkillSwitchPanel_SkillSwitchPanelView__Open__060018a9
               (void)

{
  longlong lVar1;
  ulonglong uVar2;
  char cVar3;
  int iVar4;
  longlong lVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  longlong *plVar9;
  longlong *plVar10;
  uint uVar11;
  bool bVar12;
  bool bVar13;
  longlong lStack_90;
  ulonglong uStack_88;
  undefined8 uStack_80;
  undefined8 uStack_78;
  undefined8 uStack_70;
  longlong lStack_68;
  ulonglong uStack_60;
  ulonglong uStack_58;
  undefined8 uStack_50;
  undefined8 uStack_48;
  undefined *puStack_30;
  
  if (cRam0000000182eb7b8f == '\0') {
    puStack_30 = &UNK_1804cfc89;
    FUN_1802f2810(&DAT_182d58238);
    LOCK();
    UNLOCK();
    puStack_30 = &UNK_1804cfc9a;
    FUN_1802f2810(&DAT_182d58380);
    LOCK();
    UNLOCK();
    puStack_30 = &UNK_1804cfcab;
    FUN_1802f2810(0x182d61830);
    LOCK();
    UNLOCK();
    cRam0000000182eb7b8f = '\x01';
  }
  if (*(int *)(DAT_182d58380 + 0xe0) == 0) {
    puStack_30 = &UNK_1804cfccf;
    FUN_18035c820(DAT_182d58380);
  }
  if ((**(longlong **)(DAT_182d58238 + 0xb8) != 0) && (**(longlong **)(DAT_182d58380 + 0xb8) != 0))
  {
    puStack_30 = &UNK_1804cfd0d;
    plVar9 = (longlong *)
             ExposureUnnoticed2_Object3D_IngameManager_InGameUiManager__Open__060011a0
                       (**(longlong **)(DAT_182d58380 + 0xb8),
                        *(undefined8 *)(**(longlong **)(DAT_182d58238 + 0xb8) + 0x1f0),0,0);
    if (plVar9 != (longlong *)0x0) {
      if ((*(byte *)(lRam0000000182d61830 + 0x130) <= *(byte *)(*plVar9 + 0x130)) &&
         (lVar5 = *(longlong *)(*plVar9 + 200),
         *(longlong *)(lVar5 + -8 + (ulonglong)*(byte *)(lRam0000000182d61830 + 0x130) * 8) ==
         lRam0000000182d61830)) {
        plVar10 = (longlong *)0x0;
        if (*(longlong *)(lVar5 + -8 + (ulonglong)*(byte *)(lRam0000000182d61830 + 0x130) * 8) ==
            lRam0000000182d61830) {
          plVar10 = plVar9;
        }
        if (cRam0000000182eb7b89 == '\0') {
          FUN_1802f2810(0x182d61890,0);
          LOCK();
          UNLOCK();
          FUN_1802f2810(&DAT_182d58368);
          LOCK();
          UNLOCK();
          FUN_1802f2810(0x182d5dd28);
          LOCK();
          UNLOCK();
          FUN_1802f2810(0x182d5e090);
          LOCK();
          UNLOCK();
          FUN_1802f2810(0x182d5e0a0);
          LOCK();
          UNLOCK();
          FUN_1802f2810(0x182d5e080);
          LOCK();
          UNLOCK();
          FUN_1802f2810(0x182d5e068);
          LOCK();
          UNLOCK();
          FUN_1802f2810(&DAT_182d58288);
          LOCK();
          UNLOCK();
          FUN_1802f2810(0x182d61888);
          LOCK();
          UNLOCK();
          FUN_1802f2810(&DAT_182d58398);
          LOCK();
          UNLOCK();
          FUN_1802f2810(0x182d5e050);
          LOCK();
          UNLOCK();
          FUN_1802f2810(0x182d61880);
          LOCK();
          UNLOCK();
          FUN_1802f2810(&DAT_182d54d90);
          LOCK();
          UNLOCK();
          FUN_1802f2810(&DAT_182d53aa8);
          LOCK();
          UNLOCK();
          FUN_1802f2810(0x182d61878);
          LOCK();
          UNLOCK();
          FUN_1802f2810(0x182d61870);
          LOCK();
          UNLOCK();
          FUN_1802f2810(0x182d61868);
          LOCK();
          UNLOCK();
          cRam0000000182eb7b89 = '\x01';
        }
        lVar5 = FUN_1802c43a0(DAT_182d58368);
        FUN_1814df680(lVar5,plVar10,uRam0000000182d61870,0);
        plVar10[6] = lVar5;
        if (DAT_182eb5d50 != 0) {
          uVar11 = (uint)((ulonglong)(plVar10 + 6) >> 0xc);
          lVar5 = (ulonglong)((uVar11 & 0x1fffff) >> 6) * 8;
          do {
            uVar2 = *(ulonglong *)(&DAT_182f0c920 + lVar5);
            LOCK();
            bVar12 = uVar2 == *(ulonglong *)(&DAT_182f0c920 + lVar5);
            if (bVar12) {
              *(ulonglong *)(&DAT_182f0c920 + lVar5) = uVar2 | 1L << (ulonglong)(uVar11 & 0x3f);
            }
            UNLOCK();
          } while (!bVar12);
        }
        lVar5 = plVar10[0xb];
        if (*(int *)(DAT_182d58288 + 0xe0) == 0) {
          FUN_18035c820();
        }
        ExposureUnnoticed2_Scripts_Base_ExternalMethodManager__DestroyChildren__0600172c(lVar5,0);
        bVar12 = true;
        if (cRam0000000182eb783e == '\0') {
          FUN_1802f2810(0x182d5c668);
          LOCK();
          UNLOCK();
          cRam0000000182eb783e = '\x01';
        }
        ExposureUnnoticed2_Master_Skill_MSkill__CheckInitialize__06001231(0);
        lVar5 = **(longlong **)(lRam0000000182d5c668 + 0xb8);
        if (lVar5 != 0) {
          if (DAT_182eb5d50 != 0) {
            uVar11 = (uint)((ulonglong)&lStack_90 >> 0xc);
            lVar1 = (ulonglong)((uVar11 & 0x1fffff) >> 6) * 8;
            do {
              uVar2 = *(ulonglong *)(&DAT_182f0c920 + lVar1);
              LOCK();
              bVar13 = uVar2 == *(ulonglong *)(&DAT_182f0c920 + lVar1);
              if (bVar13) {
                *(ulonglong *)(&DAT_182f0c920 + lVar1) = uVar2 | 1L << (ulonglong)(uVar11 & 0x3f);
              }
              UNLOCK();
            } while (!bVar13);
          }
          uStack_88 = (ulonglong)*(uint *)(lVar5 + 0x2c);
          uStack_70 = 2;
          uStack_80 = 0;
          uStack_78 = 0;
          uStack_60 = uStack_88;
          uStack_58 = 0;
          uStack_50 = 0;
          uStack_48 = 2;
          lStack_90 = lVar5;
          lStack_68 = lVar5;
          while (cVar3 = FUN_180f89450(&lStack_68,uRam0000000182d5e080), uVar2 = uStack_58,
                cVar3 != '\0') {
            lVar5 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
            if (lVar5 == 0) {
                    /* WARNING: Subroutine does not return */
              FUN_18031dad0();
            }
            lVar5 = *(longlong *)(lVar5 + 0x1d0);
            if (lVar5 == 0) {
                    /* WARNING: Subroutine does not return */
              FUN_18031dad0();
            }
            iVar4 = FUN_180e6c800(lVar5,uStack_58 & 0xffffffff,
                                  *(undefined8 *)
                                   (*(longlong *)(*(longlong *)(lRam0000000182d5dd28 + 0x20) + 0xc0)
                                   + 0xf8));
            if (-1 < iVar4) {
              lVar5 = plVar10[0xc];
              lVar1 = plVar10[0xb];
              if (*(int *)(DAT_182d53aa8 + 0xe0) == 0) {
                FUN_18035c820();
              }
              lVar5 = FUN_1809f1050(lVar5,lVar1,DAT_182d54d90);
              if (lVar5 == 0) {
                    /* WARNING: Subroutine does not return */
                FUN_18031dad0();
              }
              lVar5 = FUN_1809a08f0(lVar5,uRam0000000182d61888);
              uVar6 = ExposureUnnoticed2_Master_Skill_MSkill__Get__06001232(uVar2 & 0xffffffff,0);
              uVar7 = FUN_1802c43a0(uRam0000000182d61890);
              FUN_180665bb0(uVar7,plVar10,uRam0000000182d61878,0);
              uVar8 = FUN_1802c43a0(DAT_182d58368);
              FUN_1814df680(uVar8,plVar10,uRam0000000182d61868,0);
              if (lVar5 == 0) {
                    /* WARNING: Subroutine does not return */
                FUN_18031dad0();
              }
              ExposureUnnoticed2_ObjectUI_PcMenuPanel_SkillSwitchPanel_SkillSwitchItemView__Initialize__0600189c
                        (lVar5,uVar6,uVar7,uVar8,0);
              if (plVar10[0x11] == 0) {
                    /* WARNING: Subroutine does not return */
                FUN_18031dad0();
              }
              FUN_1803d4be0(plVar10[0x11],lVar5,uRam0000000182d61880);
              if (bVar12) {
                uVar6 = ExposureUnnoticed2_Master_Skill_MSkill__Get__06001232(uVar2 & 0xffffffff,0);
                ExposureUnnoticed2_ObjectUI_PcMenuPanel_SkillSwitchPanel_SkillSwitchPanelView__OnClickItem__060018a7
                          (plVar10,uVar6,0);
              }
              bVar12 = false;
            }
          }
          if (plVar10[0xf] != 0) {
            HadakaCoat_ObjectsUi_Common_Button_ButtonGroupManager__ReSearchButton__06001de5
                      (plVar10[0xf],0,1,0);
            if (cRam0000000182eb7b8a == '\0') {
              FUN_1802f2810(&DAT_182d5aa88);
              LOCK();
              UNLOCK();
              cRam0000000182eb7b8a = '\x01';
            }
            Common_Scripts_UI_BasePanelView__IsActivePanel__06001e1c(plVar10,0);
            if (*(int *)(DAT_182d5aa88 + 0xe0) == 0) {
              FUN_18035c820();
            }
            cVar3 = FUN_180477d40();
            if (cVar3 != '\0') {
              lVar5 = plVar10[0xf];
              if ((lVar5 == 0) || (lVar1 = *(longlong *)(lVar5 + 0x38), lVar1 == 0))
              goto code_r0x0001804cf438;
              if (*(uint *)(lVar1 + 0x18) <= *(uint *)(plVar10 + 0x12)) {
                    /* WARNING: Subroutine does not return */
                FUN_18031dae0();
              }
              HadakaCoat_ObjectsUi_Common_Button_ButtonGroupManager__ReceiveOnClickNotify__06001de6
                        (lVar5,*(undefined8 *)
                                (lVar1 + 0x20 + (longlong)(int)*(uint *)(plVar10 + 0x12) * 8),0);
            }
            return;
          }
        }
code_r0x0001804cf438:
                    /* WARNING: Subroutine does not return */
        FUN_18031dad0();
      }
    }
  }
                    /* WARNING: Subroutine does not return */
  puStack_30 = &UNK_1804cfd6d;
  FUN_18031dad0();
}

