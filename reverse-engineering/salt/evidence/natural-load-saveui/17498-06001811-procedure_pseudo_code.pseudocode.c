// Ghidra pseudocode; not original source or compilable C.
// ev_f7fffa8f1235b1ab925887681a3adc0e2a33d339d2abced03125cb0eb85b0546

void ExposureUnnoticed2_ObjectUI_SystemMenu_SystemMenuView__OnClickSaveAndGoToTitle__06001811(void)

{
  ulonglong uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  longlong lVar6;
  ulonglong uVar7;
  uint uVar8;
  bool bVar9;
  undefined8 uStack_90;
  longlong lStack_88;
  undefined8 uStack_80;
  undefined8 uStack_78;
  longlong lStack_70;
  undefined8 uStack_68;
  undefined8 uStack_60;
  longlong lStack_58;
  undefined4 uStack_48;
  undefined4 uStack_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  longlong lStack_38;
  
  if (cRam0000000182eb7b15 == '\0') {
    FUN_1802f2810(&DAT_182d58368);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5f238);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5f230);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5f260);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d5aa70);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5f250);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5f228);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5f248);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5f240);
    LOCK();
    UNLOCK();
    cRam0000000182eb7b15 = '\x01';
  }
  if (**(longlong **)(DAT_182d5aa70 + 0xb8) == 0) {
                    /* WARNING: Subroutine does not return */
    FUN_18031dad0();
  }
  ExposureUnnoticed2_Scripts_Sound_UiSoundPlayer__PlayOneShotAudioData__06001404
            (**(longlong **)(DAT_182d5aa70 + 0xb8),0x31,0xbf800000,0,0);
  uVar4 = ExposureUnnoticed2_Scripts_Base_Localizer__Trans__060017af(uRam0000000182d5f250,0);
  uVar5 = ExposureUnnoticed2_Scripts_Base_Localizer__Trans__060017af(uRam0000000182d5f228,0);
  lStack_88 = 0;
  uStack_90 = ExposureUnnoticed2_Scripts_Base_Localizer__Trans__060017af(uRam0000000182d5f248,0);
  if (DAT_182eb5d50 != 0) {
    uVar8 = (uint)((ulonglong)&uStack_90 >> 0xc);
    uVar7 = (ulonglong)((uVar8 & 0x1fffff) >> 6);
    do {
      uVar1 = *(ulonglong *)(&DAT_182f0c920 + uVar7 * 8);
      LOCK();
      bVar9 = uVar1 == *(ulonglong *)(&DAT_182f0c920 + uVar7 * 8);
      if (bVar9) {
        *(ulonglong *)(&DAT_182f0c920 + uVar7 * 8) = uVar1 | 1L << (uVar8 & 0x3f);
      }
      UNLOCK();
    } while (!bVar9);
  }
  if (*(int *)(lRam0000000182d5f260 + 0xe0) == 0) {
    FUN_18035c820();
  }
  lVar6 = *(longlong *)(*(longlong *)(lRam0000000182d5f260 + 0xb8) + 0x28);
  if (lVar6 == 0) {
    if (*(int *)(lRam0000000182d5f260 + 0xe0) == 0) {
      FUN_18035c820();
    }
    uVar2 = **(undefined8 **)(lRam0000000182d5f260 + 0xb8);
    lVar6 = FUN_1802c43a0(DAT_182d58368);
    FUN_1814df680(lVar6,uVar2,uRam0000000182d5f238,0);
    *(longlong *)(*(longlong *)(lRam0000000182d5f260 + 0xb8) + 0x28) = lVar6;
    if (DAT_182eb5d50 != 0) {
      uVar8 = (uint)(*(longlong *)(lRam0000000182d5f260 + 0xb8) + 0x28U >> 0xc);
      uVar7 = (ulonglong)((uVar8 & 0x1fffff) >> 6);
      do {
        uVar1 = *(ulonglong *)(&DAT_182f0c920 + uVar7 * 8);
        LOCK();
        bVar9 = uVar1 == *(ulonglong *)(&DAT_182f0c920 + uVar7 * 8);
        if (bVar9) {
          *(ulonglong *)(&DAT_182f0c920 + uVar7 * 8) = uVar1 | 1L << (uVar8 & 0x3f);
        }
        UNLOCK();
      } while (!bVar9);
    }
  }
  uVar2 = uStack_90;
  if (DAT_182eb5d50 != 0) {
    uVar8 = (uint)((ulonglong)&lStack_88 >> 0xc);
    uVar7 = (ulonglong)((uVar8 & 0x1fffff) >> 6);
    do {
      uVar1 = *(ulonglong *)(&DAT_182f0c920 + uVar7 * 8);
      LOCK();
      bVar9 = uVar1 == *(ulonglong *)(&DAT_182f0c920 + uVar7 * 8);
      if (bVar9) {
        *(ulonglong *)(&DAT_182f0c920 + uVar7 * 8) = uVar1 | 1L << (uVar8 & 0x3f);
      }
      UNLOCK();
    } while (!bVar9);
  }
  uStack_68 = 0;
  uStack_60 = uStack_90;
  lStack_88 = 0;
  uStack_90 = 0;
  lStack_58 = lVar6;
  uStack_90 = ExposureUnnoticed2_Scripts_Base_Localizer__Trans__060017af(uRam0000000182d5f240,0);
  if (DAT_182eb5d50 != 0) {
    uVar8 = (uint)((ulonglong)&uStack_90 >> 0xc);
    uVar7 = (ulonglong)((uVar8 & 0x1fffff) >> 6);
    do {
      uVar1 = *(ulonglong *)(&DAT_182f0c920 + uVar7 * 8);
      LOCK();
      bVar9 = uVar1 == *(ulonglong *)(&DAT_182f0c920 + uVar7 * 8);
      if (bVar9) {
        *(ulonglong *)(&DAT_182f0c920 + uVar7 * 8) = uVar1 | 1L << (uVar8 & 0x3f);
      }
      UNLOCK();
    } while (!bVar9);
  }
  if (*(int *)(lRam0000000182d5f260 + 0xe0) == 0) {
    FUN_18035c820();
  }
  lVar6 = *(longlong *)(*(longlong *)(lRam0000000182d5f260 + 0xb8) + 0x38);
  if (lVar6 == 0) {
    if (*(int *)(lRam0000000182d5f260 + 0xe0) == 0) {
      FUN_18035c820();
    }
    uVar3 = **(undefined8 **)(lRam0000000182d5f260 + 0xb8);
    lVar6 = FUN_1802c43a0(DAT_182d58368);
    FUN_1814df680(lVar6,uVar3,uRam0000000182d5f230,0);
    *(longlong *)(*(longlong *)(lRam0000000182d5f260 + 0xb8) + 0x38) = lVar6;
    if (DAT_182eb5d50 != 0) {
      uVar8 = (uint)(*(longlong *)(lRam0000000182d5f260 + 0xb8) + 0x38U >> 0xc);
      uVar7 = (ulonglong)((uVar8 & 0x1fffff) >> 6);
      do {
        uVar1 = *(ulonglong *)(&DAT_182f0c920 + uVar7 * 8);
        LOCK();
        bVar9 = uVar1 == *(ulonglong *)(&DAT_182f0c920 + uVar7 * 8);
        if (bVar9) {
          *(ulonglong *)(&DAT_182f0c920 + uVar7 * 8) = uVar1 | 1L << (uVar8 & 0x3f);
        }
        UNLOCK();
      } while (!bVar9);
    }
  }
  uVar3 = uStack_68;
  uStack_80 = uStack_68;
  lStack_70 = lStack_58;
  uStack_78 = uVar2;
  if (DAT_182eb5d50 != 0) {
    uVar8 = (uint)((ulonglong)&lStack_88 >> 0xc);
    uVar7 = (ulonglong)((uVar8 & 0x1fffff) >> 6);
    do {
      uVar1 = *(ulonglong *)(&DAT_182f0c920 + uVar7 * 8);
      LOCK();
      bVar9 = uVar1 == *(ulonglong *)(&DAT_182f0c920 + uVar7 * 8);
      if (bVar9) {
        *(ulonglong *)(&DAT_182f0c920 + uVar7 * 8) = uVar1 | 1L << (uVar8 & 0x3f);
      }
      UNLOCK();
    } while (!bVar9);
  }
  uStack_68 = 0;
  uStack_60 = uStack_90;
  uStack_80._0_4_ = (undefined4)uVar3;
  uStack_80._4_4_ = (undefined4)((ulonglong)uVar3 >> 0x20);
  uStack_78._0_4_ = (undefined4)uVar2;
  uStack_78._4_4_ = (undefined4)((ulonglong)uVar2 >> 0x20);
  uStack_48 = (undefined4)uStack_80;
  uStack_44 = uStack_80._4_4_;
  uStack_40 = (undefined4)uStack_78;
  uStack_3c = uStack_78._4_4_;
  lStack_38 = lStack_58;
  lStack_88 = lVar6;
  uStack_80 = uVar3;
  uStack_78 = uVar2;
  lStack_58 = lVar6;
  ExposureUnnoticed2_ObjectUI_CommonPopup_CommonPopupView__Open__06001dc2
            (uVar4,uVar5,&uStack_48,&uStack_68,1,0);
  return;
}

