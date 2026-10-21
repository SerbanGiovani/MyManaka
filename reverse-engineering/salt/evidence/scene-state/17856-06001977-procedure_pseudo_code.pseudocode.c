// Ghidra pseudocode; not original source or compilable C.
// ev_958c8166761810cc01cda6d26ef44057bd6a016d138eb9dd4c67d2d4401375de

void __c__DisplayClass11_0___OnClickSlot_b__5__06001977(longlong param_1)

{
  longlong lVar1;
  ulonglong *puVar2;
  ulonglong uVar3;
  undefined4 uVar4;
  undefined8 uVar5;
  ulonglong uVar6;
  undefined8 uVar7;
  longlong lVar8;
  longlong lVar9;
  uint uVar10;
  bool bVar11;
  
  if (cRam0000000182eb7c0b == '\0') {
    FUN_1802f2810(&DAT_182d60278);
    LOCK();
    UNLOCK();
    cRam0000000182eb7c0b = '\x01';
  }
  uVar4 = *(undefined4 *)(param_1 + 0x10);
  if (*(int *)(DAT_182d60278 + 0xe0) == 0) {
    FUN_18035c820();
  }
  ExposureUnnoticed2_Scripts_Base_SaveRapper__PreProcess__060017b8(0,uVar4,0,0);
  lVar8 = ExposureUnnoticed2_Scripts_Base_SaveRapper__GetSaveDataPath__060017b5(0);
  if (cRam0000000182eb74c4 == '\0') {
    FUN_1802f2810(&DAT_182d534a8);
    LOCK();
    UNLOCK();
    cRam0000000182eb74c4 = '\x01';
  }
  lVar9 = FUN_1802c43a0(DAT_182d534a8);
  ES3Settings___ctor__060001ba(lVar9,1,0);
  if ((lVar8 != 0) && (bVar11 = DAT_182eb5d50 != 0, *(longlong *)(lVar9 + 0x18) = lVar8, bVar11)) {
    uVar10 = (uint)(lVar9 + 0x18U >> 0xc);
    puVar2 = (ulonglong *)(&DAT_182f0c920 + (ulonglong)((uVar10 & 0x1fffff) >> 6) * 8);
    do {
      uVar6 = *puVar2;
      LOCK();
      uVar3 = *puVar2;
      if (uVar6 == uVar3) {
        *puVar2 = uVar6 | 1L << (uVar10 & 0x3f);
      }
      UNLOCK();
    } while (uVar6 != uVar3);
  }
  ES3__DeleteFile__060000d8(lVar9,0);
  if (cRam0000000182eb7c09 == '\0') {
    FUN_1802f2810(&DAT_182d58368,0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5aa40);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d58398);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d60190);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d63680);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d63678);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d63688);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d63718);
    LOCK();
    UNLOCK();
    cRam0000000182eb7c09 = '\x01';
  }
  uVar7 = *(undefined8 *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x38);
  **(undefined4 **)(lRam0000000182d60190 + 0xb8) = *(undefined4 *)(param_1 + 0x10);
  ExposureUnnoticed2_Scripts_InGame_SaveManager__Load__06001602
            (5,**(undefined4 **)(lRam0000000182d60190 + 0xb8),0);
  bVar11 = DAT_182eb5d50 != 0;
  *(undefined8 *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x38) = uVar7;
  if (bVar11) {
    uVar10 = (uint)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x38U >> 0xc);
    lVar8 = (ulonglong)((uVar10 & 0x1fffff) >> 6) * 8;
    do {
      uVar3 = *(ulonglong *)(&DAT_182f0c920 + lVar8);
      LOCK();
      bVar11 = uVar3 == *(ulonglong *)(&DAT_182f0c920 + lVar8);
      if (bVar11) {
        *(ulonglong *)(&DAT_182f0c920 + lVar8) = uVar3 | 1L << (uVar10 & 0x3f);
      }
      UNLOCK();
    } while (!bVar11);
  }
  lVar8 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
  if ((*(longlong *)(param_1 + 0x18) != 0) && (lVar8 != 0)) {
    *(undefined4 *)(lVar8 + 0x34) = *(undefined4 *)(*(longlong *)(param_1 + 0x18) + 0x78);
    uVar7 = FUN_1802c43a0(uRam0000000182d63718);
    ExposureUnnoticed2_ObjectUI_FadeOutPanel_WaitSceneLoadTwiceStarter___ctor__06001b5e(uVar7,0);
    if (*(int *)(lRam0000000182d63688 + 0xe0) == 0) {
      FUN_18035c820(lRam0000000182d63688);
    }
    lVar8 = *(longlong *)(*(longlong *)(lRam0000000182d63688 + 0xb8) + 8);
    if (lVar8 == 0) {
      if (*(int *)(lRam0000000182d63688 + 0xe0) == 0) {
        FUN_18035c820(lRam0000000182d63688);
      }
      uVar5 = **(undefined8 **)(lRam0000000182d63688 + 0xb8);
      lVar8 = FUN_1802c43a0(DAT_182d58368);
      FUN_1814df680(lVar8,uVar5,uRam0000000182d63680,0);
      *(longlong *)(*(longlong *)(lRam0000000182d63688 + 0xb8) + 8) = lVar8;
      if (DAT_182eb5d50 != 0) {
        uVar10 = (uint)(*(longlong *)(lRam0000000182d63688 + 0xb8) + 8U >> 0xc);
        lVar9 = (ulonglong)((uVar10 & 0x1fffff) >> 6) * 8;
        do {
          uVar3 = *(ulonglong *)(&DAT_182f0c920 + lVar9);
          LOCK();
          bVar11 = uVar3 == *(ulonglong *)(&DAT_182f0c920 + lVar9);
          if (bVar11) {
            *(ulonglong *)(&DAT_182f0c920 + lVar9) = uVar3 | 1L << (uVar10 & 0x3f);
          }
          UNLOCK();
        } while (!bVar11);
      }
    }
    if (*(int *)(lRam0000000182d63688 + 0xe0) == 0) {
      FUN_18035c820(lRam0000000182d63688);
    }
    lVar9 = *(longlong *)(*(longlong *)(lRam0000000182d63688 + 0xb8) + 0x10);
    if (lVar9 == 0) {
      if (*(int *)(lRam0000000182d63688 + 0xe0) == 0) {
        FUN_18035c820(lRam0000000182d63688);
      }
      uVar5 = **(undefined8 **)(lRam0000000182d63688 + 0xb8);
      lVar9 = FUN_1802c43a0(DAT_182d58368);
      FUN_1814df680(lVar9,uVar5,uRam0000000182d63678,0);
      *(longlong *)(*(longlong *)(lRam0000000182d63688 + 0xb8) + 0x10) = lVar9;
      if (DAT_182eb5d50 != 0) {
        uVar10 = (uint)(*(longlong *)(lRam0000000182d63688 + 0xb8) + 0x10U >> 0xc);
        lVar1 = (ulonglong)((uVar10 & 0x1fffff) >> 6) * 8;
        do {
          uVar3 = *(ulonglong *)(&DAT_182f0c920 + lVar1);
          LOCK();
          bVar11 = uVar3 == *(ulonglong *)(&DAT_182f0c920 + lVar1);
          if (bVar11) {
            *(ulonglong *)(&DAT_182f0c920 + lVar1) = uVar3 | 1L << (uVar10 & 0x3f);
          }
          UNLOCK();
        } while (!bVar11);
      }
    }
    if (*(int *)(lRam0000000182d5aa40 + 0xe0) == 0) {
      FUN_18035c820();
    }
    ExposureUnnoticed2_ObjectUI_FadeOutPanel_FadePanelView__Open__06001b4c(uVar7,lVar8,0,lVar9,1,0);
    return;
  }
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

