// Ghidra pseudocode; not original source or compilable C.
// ev_42b8567602c49810b5b6963f7ded1ce5e0c089acf5ec89586da180e0c56f946c

void ExposureUnnoticed2_ObjectUI_SystemMenu_SystemMenuView__OnClickEmergencyEscape__0600180e
               (undefined8 param_1)

{
  longlong lVar1;
  ulonglong uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  longlong lVar5;
  undefined8 uVar6;
  uint uVar7;
  bool bVar8;
  undefined8 uStack_78;
  undefined8 uStack_70;
  longlong lStack_68;
  undefined8 uStack_58;
  undefined8 uStack_50;
  undefined8 auStack_48 [2];
  undefined8 uStack_38;
  undefined8 uStack_30;
  undefined8 uStack_28;
  
  if (cRam0000000182eb7b14 == '\0') {
    FUN_1802f2810(&DAT_182d58368);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5f270);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5f268);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5f260);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5f258);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5f250);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5f248);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5f240);
    LOCK();
    UNLOCK();
    cRam0000000182eb7b14 = '\x01';
  }
  uVar3 = ExposureUnnoticed2_Scripts_Base_Localizer__Trans__060017af(uRam0000000182d5f250,0);
  uVar4 = ExposureUnnoticed2_Scripts_Base_Localizer__Trans__060017af(uRam0000000182d5f258,0);
  uStack_58 = 0;
  auStack_48[0] = 0;
  uStack_50 = ExposureUnnoticed2_Scripts_Base_Localizer__Trans__060017af(uRam0000000182d5f248,0);
  if (DAT_182eb5d50 != 0) {
    uVar7 = (uint)((ulonglong)&uStack_50 >> 0xc);
    lVar5 = (ulonglong)((uVar7 & 0x1fffff) >> 6) * 8;
    do {
      uVar2 = *(ulonglong *)(&DAT_182f0c920 + lVar5);
      LOCK();
      bVar8 = uVar2 == *(ulonglong *)(&DAT_182f0c920 + lVar5);
      if (bVar8) {
        *(ulonglong *)(&DAT_182f0c920 + lVar5) = uVar2 | 1L << (uVar7 & 0x3f);
      }
      UNLOCK();
    } while (!bVar8);
  }
  if (*(int *)(lRam0000000182d5f260 + 0xe0) == 0) {
    FUN_18035c820();
  }
  lVar5 = *(longlong *)(*(longlong *)(lRam0000000182d5f260 + 0xb8) + 8);
  if (lVar5 == 0) {
    if (*(int *)(lRam0000000182d5f260 + 0xe0) == 0) {
      FUN_18035c820();
    }
    uVar6 = **(undefined8 **)(lRam0000000182d5f260 + 0xb8);
    lVar5 = FUN_1802c43a0(DAT_182d58368);
    FUN_1814df680(lVar5,uVar6,uRam0000000182d5f268,0);
    *(longlong *)(*(longlong *)(lRam0000000182d5f260 + 0xb8) + 8) = lVar5;
    if (DAT_182eb5d50 != 0) {
      uVar7 = (uint)(*(longlong *)(lRam0000000182d5f260 + 0xb8) + 8U >> 0xc);
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
    uVar7 = (uint)((ulonglong)auStack_48 >> 0xc);
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
  uStack_78 = uStack_58;
  uStack_70 = uStack_50;
  uStack_58 = 0;
  uStack_50 = 0;
  auStack_48[0] = 0;
  uStack_50 = ExposureUnnoticed2_Scripts_Base_Localizer__Trans__060017af(uRam0000000182d5f240,0);
  if (DAT_182eb5d50 != 0) {
    uVar7 = (uint)((ulonglong)&uStack_50 >> 0xc);
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
  uVar6 = FUN_1802c43a0(DAT_182d58368);
  FUN_1814df680(uVar6,param_1,uRam0000000182d5f270,0);
  if (DAT_182eb5d50 != 0) {
    uVar7 = (uint)((ulonglong)auStack_48 >> 0xc);
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
  uStack_38 = uStack_58;
  uStack_30 = uStack_50;
  lStack_68 = lVar5;
  auStack_48[0] = uVar6;
  uStack_28 = uVar6;
  ExposureUnnoticed2_ObjectUI_CommonPopup_CommonPopupView__Open__06001dc2
            (uVar3,uVar4,&uStack_78,&uStack_38,1,0);
  return;
}

