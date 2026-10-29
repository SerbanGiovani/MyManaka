// Ghidra pseudocode; not original source or compilable C.
// ev_e80d6dd92acf2bfe7eec760523c5e164b595558843203114d5ee6ce498ef94b7

void ExposureUnnoticed2_ObjectUI_SaveDataSelectPanel_SkillPanelView__OnClickReinforce__0600198d
               (longlong param_1,longlong param_2)

{
  ulonglong *puVar1;
  ulonglong uVar2;
  longlong lVar3;
  ulonglong uVar4;
  char cVar5;
  uint uVar6;
  undefined8 uStack_40;
  undefined4 *puStack_38;
  undefined8 uStack_30;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  longlong lStack_18;
  
  if (cRam0000000182eb7c1c == '\0') {
    FUN_1802f2810(0x182d63528);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d63520);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d63510);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d63508);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d58378);
    LOCK();
    UNLOCK();
    cRam0000000182eb7c1c = '\x01';
  }
  ExposureUnnoticed2_ObjectUI_SaveDataSelectPanel_SkillPanelView__OnClickItem__0600198e
            (param_1,param_2,0);
  lVar3 = *(longlong *)(param_1 + 0xa0);
  if (lVar3 != 0) {
    if (DAT_182eb5d50 != 0) {
      uVar6 = (uint)((ulonglong)&uStack_40 >> 0xc);
      puVar1 = (ulonglong *)(&DAT_182f0c920 + (ulonglong)((uVar6 & 0x1fffff) >> 6) * 8);
      do {
        uVar4 = *puVar1;
        LOCK();
        uVar2 = *puVar1;
        if (uVar4 == uVar2) {
          *puVar1 = uVar4 | 1L << (uVar6 & 0x3f);
        }
        UNLOCK();
      } while (uVar4 != uVar2);
    }
    uStack_1c = *(undefined4 *)(lVar3 + 0x1c);
    uStack_30 = 0;
    uStack_40._0_4_ = (undefined4)lVar3;
    uStack_40._4_4_ = (undefined4)((ulonglong)lVar3 >> 0x20);
    uStack_28 = (undefined4)uStack_40;
    uStack_24 = uStack_40._4_4_;
    uStack_20 = 0;
    lStack_18 = 0;
    uStack_40 = 0;
    puStack_38 = &uStack_28;
    while (cVar5 = FUN_180f72b70(&uStack_28,uRam0000000182d63520), cVar5 != '\0') {
      if (lStack_18 == 0) {
                    /* WARNING: Subroutine does not return */
        FUN_18031dad0();
      }
      ExposureUnnoticed2_ObjectUI_SkillPanel_SkillItemView__UpdateMask__0600182e(lStack_18,0);
    }
    if (param_2 != 0) {
      if (*(int *)(param_2 + 0x3c) == 0x18) {
        if (((**(longlong **)(DAT_182d58378 + 0xb8) == 0) ||
            (lVar3 = *(longlong *)(**(longlong **)(DAT_182d58378 + 0xb8) + 0x40), lVar3 == 0)) ||
           (lVar3 = *(longlong *)(lVar3 + 0x1b8), lVar3 == 0)) goto code_r0x0001804e7641;
        ExposureUnnoticed2_Object3D_Player_Scripts_PlayerCosplayManager__CalcCostumeEffect__06000d7a
                  (lVar3,0);
      }
      return;
    }
  }
code_r0x0001804e7641:
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

