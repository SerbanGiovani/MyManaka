// Ghidra pseudocode; not original source or compilable C.
// ev_502f25c461b54db0a03d1c243e0b713908aee98acb560a44a66f73433902c3ee

void ExposureUnnoticed2_ObjectUI_SaveDataSelectPanel_ManualSavePanelView__OnClickSlot__06001969
               (longlong param_1,undefined4 param_2,undefined4 param_3)

{
  ulonglong uVar1;
  undefined8 uVar2;
  code *pcVar3;
  char cVar4;
  longlong lVar5;
  code *pcVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  undefined8 uVar9;
  undefined8 uVar10;
  undefined8 uVar11;
  ulonglong uVar12;
  uint uVar13;
  bool bVar14;
  undefined8 uStack_90;
  undefined8 auStack_88 [2];
  undefined4 uStack_78;
  undefined4 uStack_74;
  undefined4 uStack_70;
  undefined4 uStack_6c;
  undefined8 uStack_68;
  undefined8 uStack_58;
  undefined8 uStack_50;
  undefined8 uStack_48;
  
  if (cRam0000000182eb7c02 == '\0') {
    FUN_1802f2810(&DAT_182d58368);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d636f0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d636e8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d636e0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d5aa70);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d636d8);
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
    cRam0000000182eb7c02 = '\x01';
  }
  lVar5 = FUN_1802c43a0(uRam0000000182d636e0);
  if (lVar5 != 0) {
    bVar14 = DAT_182eb5d50 != 0;
    *(undefined4 *)(lVar5 + 0x10) = param_3;
    *(longlong *)(lVar5 + 0x18) = param_1;
    if (bVar14) {
      uVar13 = (uint)(lVar5 + 0x18U >> 0xc);
      uVar12 = (ulonglong)((uVar13 & 0x1fffff) >> 6);
      do {
        uVar1 = *(ulonglong *)(&DAT_182f0c920 + uVar12 * 8);
        LOCK();
        bVar14 = uVar1 == *(ulonglong *)(&DAT_182f0c920 + uVar12 * 8);
        if (bVar14) {
          *(ulonglong *)(&DAT_182f0c920 + uVar12 * 8) = uVar1 | 1L << (uVar13 & 0x3f);
        }
        UNLOCK();
      } while (!bVar14);
    }
    if (**(longlong **)(DAT_182d5aa70 + 0xb8) != 0) {
      ExposureUnnoticed2_Scripts_Sound_UiSoundPlayer__PlayOneShotAudioData__06001404
                (**(longlong **)(DAT_182d5aa70 + 0xb8),0x31,0xbf800000,0,0);
      cVar4 = ExposureUnnoticed2_Scripts_InGame_SaveManager__IsExistSaveData__060015fe
                        (param_2,*(undefined4 *)(lVar5 + 0x10),0);
      pcVar6 = DAT_182ec1080;
      if (cVar4 == '\0') {
        __c__DisplayClass11_0___OnClickSlot_g__OnSelect_0__06001974(lVar5,0);
      }
      else {
        *(undefined1 *)(param_1 + 0x8c) = 1;
        pcVar3 = DAT_182ec1080;
        if ((pcVar6 == (code *)0x0) &&
           (pcVar6 = (code *)FUN_1802cf0c0("UnityEngine.Component::get_transform()"),
           pcVar3 = pcVar6, pcVar6 == (code *)0x0)) {
          uVar7 = FUN_1802ced60("UnityEngine.Component::get_transform()");
                    /* WARNING: Subroutine does not return */
          FUN_1802cca90(uVar7,0);
        }
        DAT_182ec1080 = pcVar3;
        uVar7 = (*pcVar6)(param_1);
        uVar8 = ExposureUnnoticed2_Scripts_Base_Localizer__Trans__060017af(uRam0000000182d5f250,0);
        uVar9 = ExposureUnnoticed2_Scripts_Base_Localizer__Trans__060017af(uRam0000000182d636d8,0);
        auStack_88[0] = 0;
        uStack_90 = ExposureUnnoticed2_Scripts_Base_Localizer__Trans__060017af
                              (uRam0000000182d5f248,0);
        if (DAT_182eb5d50 != 0) {
          uVar13 = (uint)((ulonglong)&uStack_90 >> 0xc);
          uVar12 = (ulonglong)((uVar13 & 0x1fffff) >> 6);
          do {
            uVar1 = *(ulonglong *)(&DAT_182f0c920 + uVar12 * 8);
            LOCK();
            bVar14 = uVar1 == *(ulonglong *)(&DAT_182f0c920 + uVar12 * 8);
            if (bVar14) {
              *(ulonglong *)(&DAT_182f0c920 + uVar12 * 8) = uVar1 | 1L << (uVar13 & 0x3f);
            }
            UNLOCK();
          } while (!bVar14);
        }
        uVar10 = FUN_1802c43a0(DAT_182d58368);
        FUN_1814df680(uVar10,lVar5,uRam0000000182d636f0,0);
        uVar2 = uStack_90;
        if (DAT_182eb5d50 != 0) {
          uVar13 = (uint)((ulonglong)auStack_88 >> 0xc);
          uVar12 = (ulonglong)((uVar13 & 0x1fffff) >> 6);
          do {
            uVar1 = *(ulonglong *)(&DAT_182f0c920 + uVar12 * 8);
            LOCK();
            bVar14 = uVar1 == *(ulonglong *)(&DAT_182f0c920 + uVar12 * 8);
            if (bVar14) {
              *(ulonglong *)(&DAT_182f0c920 + uVar12 * 8) = uVar1 | 1L << (uVar13 & 0x3f);
            }
            UNLOCK();
          } while (!bVar14);
        }
        auStack_88[0] = 0;
        uStack_90 = 0;
        uStack_90 = ExposureUnnoticed2_Scripts_Base_Localizer__Trans__060017af
                              (uRam0000000182d5f240,0);
        if (DAT_182eb5d50 != 0) {
          uVar13 = (uint)((ulonglong)&uStack_90 >> 0xc);
          uVar12 = (ulonglong)((uVar13 & 0x1fffff) >> 6);
          do {
            uVar1 = *(ulonglong *)(&DAT_182f0c920 + uVar12 * 8);
            LOCK();
            bVar14 = uVar1 == *(ulonglong *)(&DAT_182f0c920 + uVar12 * 8);
            if (bVar14) {
              *(ulonglong *)(&DAT_182f0c920 + uVar12 * 8) = uVar1 | 1L << (uVar13 & 0x3f);
            }
            UNLOCK();
          } while (!bVar14);
        }
        uVar11 = FUN_1802c43a0(DAT_182d58368);
        FUN_1814df680(uVar11,lVar5,uRam0000000182d636e8,0);
        if (DAT_182eb5d50 != 0) {
          uVar13 = (uint)((ulonglong)auStack_88 >> 0xc);
          uVar12 = (ulonglong)((uVar13 & 0x1fffff) >> 6);
          do {
            uVar1 = *(ulonglong *)(&DAT_182f0c920 + uVar12 * 8);
            LOCK();
            bVar14 = uVar1 == *(ulonglong *)(&DAT_182f0c920 + uVar12 * 8);
            if (bVar14) {
              *(ulonglong *)(&DAT_182f0c920 + uVar12 * 8) = uVar1 | 1L << (uVar13 & 0x3f);
            }
            UNLOCK();
          } while (!bVar14);
        }
        uStack_78 = 0;
        uStack_74 = 0;
        uStack_70 = (undefined4)uStack_90;
        uStack_6c = uStack_90._4_4_;
        uStack_58 = 0;
        uStack_50 = uVar2;
        auStack_88[0] = uVar11;
        uStack_68 = uVar11;
        uStack_48 = uVar10;
        ExposureUnnoticed2_ObjectUI_CommonPopup_CommonPopupView__Open__06001dc3
                  (uVar7,uVar8,uVar9,&uStack_58,&uStack_78,0);
      }
      return;
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

