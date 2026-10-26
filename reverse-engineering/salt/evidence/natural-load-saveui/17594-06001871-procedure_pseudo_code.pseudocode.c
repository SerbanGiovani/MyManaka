// Ghidra pseudocode; not original source or compilable C.
// ev_56afd6f99b1191d00614efeac8e5ddddadf02bfd05aa4c976fa6290d5abdd208

void ExposureUnnoticed2_ObjectUI_PcMenuPanel_PcMenuPanelView__OnClickManualSave__06001871(void)

{
  longlong lVar1;
  ulonglong uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  longlong lVar6;
  uint uVar7;
  bool bVar8;
  undefined8 uStack_40;
  longlong alStack_38 [2];
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  longlong lStack_18;
  
  if (cRam0000000182eb7b68 == '\0') {
    FUN_1802f2810(&DAT_182d58368);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d619b8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d619b0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d61a50);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d619a8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5f250);
    LOCK();
    UNLOCK();
    cRam0000000182eb7b68 = '\x01';
  }
  ExposureUnnoticed2_Scripts_InGame_SaveManager__Save__06001601(3,0xffffffff,0,0);
  uVar4 = ExposureUnnoticed2_Scripts_Base_Localizer__Trans__060017af(uRam0000000182d5f250,0);
  uVar5 = ExposureUnnoticed2_Scripts_Base_Localizer__Trans__060017af(uRam0000000182d61a50,0);
  alStack_38[0] = 0;
  uStack_40 = ExposureUnnoticed2_Scripts_Base_Localizer__Trans__060017af(uRam0000000182d619a8,0);
  if (DAT_182eb5d50 != 0) {
    uVar7 = (uint)((ulonglong)&uStack_40 >> 0xc);
    lVar6 = (ulonglong)((uVar7 & 0x1fffff) >> 6) * 8;
    do {
      uVar2 = *(ulonglong *)(&DAT_182f0c920 + lVar6);
      LOCK();
      bVar8 = uVar2 == *(ulonglong *)(&DAT_182f0c920 + lVar6);
      if (bVar8) {
        *(ulonglong *)(&DAT_182f0c920 + lVar6) = uVar2 | 1L << (uVar7 & 0x3f);
      }
      UNLOCK();
    } while (!bVar8);
  }
  if (*(int *)(lRam0000000182d619b0 + 0xe0) == 0) {
    FUN_18035c820();
  }
  lVar6 = *(longlong *)(*(longlong *)(lRam0000000182d619b0 + 0xb8) + 8);
  if (lVar6 == 0) {
    if (*(int *)(lRam0000000182d619b0 + 0xe0) == 0) {
      FUN_18035c820();
    }
    uVar3 = **(undefined8 **)(lRam0000000182d619b0 + 0xb8);
    lVar6 = FUN_1802c43a0(DAT_182d58368);
    FUN_1814df680(lVar6,uVar3,uRam0000000182d619b8,0);
    *(longlong *)(*(longlong *)(lRam0000000182d619b0 + 0xb8) + 8) = lVar6;
    if (DAT_182eb5d50 != 0) {
      uVar7 = (uint)(*(longlong *)(lRam0000000182d619b0 + 0xb8) + 8U >> 0xc);
      lVar1 = (ulonglong)((uVar7 & 0x1fffff) >> 6) * 8;
      do {
        uVar2 = *(ulonglong *)(&DAT_182f0c920 + lVar1);
        LOCK();
        bVar8 = uVar2 == *(ulonglong *)(&DAT_182f0c920 + lVar1);
        if (bVar8) {
          *(ulonglong *)(&DAT_182f0c920 + lVar1) = uVar2 | 1L << (uVar7 & 0x3f);
        }
        UNLOCK();
      } while (!bVar8);
    }
  }
  if (DAT_182eb5d50 != 0) {
    uVar7 = (uint)((ulonglong)alStack_38 >> 0xc);
    lVar1 = (ulonglong)((uVar7 & 0x1fffff) >> 6) * 8;
    do {
      uVar2 = *(ulonglong *)(&DAT_182f0c920 + lVar1);
      LOCK();
      bVar8 = uVar2 == *(ulonglong *)(&DAT_182f0c920 + lVar1);
      if (bVar8) {
        *(ulonglong *)(&DAT_182f0c920 + lVar1) = uVar2 | 1L << (uVar7 & 0x3f);
      }
      UNLOCK();
    } while (!bVar8);
  }
  uStack_28 = 0;
  uStack_24 = 0;
  uStack_20 = (undefined4)uStack_40;
  uStack_1c = uStack_40._4_4_;
  alStack_38[0] = lVar6;
  lStack_18 = lVar6;
  ExposureUnnoticed2_ObjectUI_CommonPopup_CommonPopupView__Open__06001dbf(uVar4,uVar5,&uStack_28,0);
  return;
}

