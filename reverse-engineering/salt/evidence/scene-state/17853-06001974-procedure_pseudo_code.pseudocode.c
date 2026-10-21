// Ghidra pseudocode; not original source or compilable C.
// ev_380da12fc55f41c635d5db70880507b219eeecb7c11ebe354f89fabc667254bc

void __c__DisplayClass11_0___OnClickSlot_g__OnSelect_0__06001974(longlong param_1)

{
  longlong lVar1;
  ulonglong uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  longlong lVar5;
  longlong lVar6;
  uint uVar7;
  bool bVar8;
  
  if (cRam0000000182eb7c09 == '\0') {
    FUN_1802f2810(&DAT_182d58368);
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
  uVar4 = *(undefined8 *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x38);
  **(undefined4 **)(lRam0000000182d60190 + 0xb8) = *(undefined4 *)(param_1 + 0x10);
  ExposureUnnoticed2_Scripts_InGame_SaveManager__Load__06001602
            (5,**(undefined4 **)(lRam0000000182d60190 + 0xb8),0);
  bVar8 = DAT_182eb5d50 != 0;
  *(undefined8 *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x38) = uVar4;
  if (bVar8) {
    uVar7 = (uint)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x38U >> 0xc);
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
  lVar5 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
  if ((*(longlong *)(param_1 + 0x18) != 0) && (lVar5 != 0)) {
    *(undefined4 *)(lVar5 + 0x34) = *(undefined4 *)(*(longlong *)(param_1 + 0x18) + 0x78);
    uVar4 = FUN_1802c43a0(uRam0000000182d63718);
    ExposureUnnoticed2_ObjectUI_FadeOutPanel_WaitSceneLoadTwiceStarter___ctor__06001b5e(uVar4,0);
    if (*(int *)(lRam0000000182d63688 + 0xe0) == 0) {
      FUN_18035c820(lRam0000000182d63688);
    }
    lVar5 = *(longlong *)(*(longlong *)(lRam0000000182d63688 + 0xb8) + 8);
    if (lVar5 == 0) {
      if (*(int *)(lRam0000000182d63688 + 0xe0) == 0) {
        FUN_18035c820(lRam0000000182d63688);
      }
      uVar3 = **(undefined8 **)(lRam0000000182d63688 + 0xb8);
      lVar5 = FUN_1802c43a0(DAT_182d58368);
      FUN_1814df680(lVar5,uVar3,uRam0000000182d63680,0);
      *(longlong *)(*(longlong *)(lRam0000000182d63688 + 0xb8) + 8) = lVar5;
      if (DAT_182eb5d50 != 0) {
        uVar7 = (uint)(*(longlong *)(lRam0000000182d63688 + 0xb8) + 8U >> 0xc);
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
    }
    if (*(int *)(lRam0000000182d63688 + 0xe0) == 0) {
      FUN_18035c820(lRam0000000182d63688);
    }
    lVar6 = *(longlong *)(*(longlong *)(lRam0000000182d63688 + 0xb8) + 0x10);
    if (lVar6 == 0) {
      if (*(int *)(lRam0000000182d63688 + 0xe0) == 0) {
        FUN_18035c820(lRam0000000182d63688);
      }
      uVar3 = **(undefined8 **)(lRam0000000182d63688 + 0xb8);
      lVar6 = FUN_1802c43a0(DAT_182d58368);
      FUN_1814df680(lVar6,uVar3,uRam0000000182d63678,0);
      *(longlong *)(*(longlong *)(lRam0000000182d63688 + 0xb8) + 0x10) = lVar6;
      if (DAT_182eb5d50 != 0) {
        uVar7 = (uint)(*(longlong *)(lRam0000000182d63688 + 0xb8) + 0x10U >> 0xc);
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
    if (*(int *)(lRam0000000182d5aa40 + 0xe0) == 0) {
      FUN_18035c820();
    }
    ExposureUnnoticed2_ObjectUI_FadeOutPanel_FadePanelView__Open__06001b4c(uVar4,lVar5,0,lVar6,1,0);
    return;
  }
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

