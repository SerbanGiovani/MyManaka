// Ghidra pseudocode; not original source or compilable C.
// ev_f8b593fc826ddee81c7d3edaaf3cad898328dab9eda2d7fbbf37dbf3bb0dedd7

void ExposureUnnoticed2_ObjectUI_MissionFailedPanel_MissionFailedPanelView__OnClickLoad__06001955
               (void)

{
  undefined8 uVar1;
  ulonglong uVar2;
  undefined8 uVar3;
  longlong lVar4;
  longlong lVar5;
  ulonglong uVar6;
  uint uVar7;
  bool bVar8;
  
  if (cRam0000000182eb7bf7 == '\0') {
    FUN_1802f2810(&DAT_182d58368);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5aa40);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d63730);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d63728);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d63720);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d5aa70);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d63718);
    LOCK();
    UNLOCK();
    cRam0000000182eb7bf7 = '\x01';
  }
  lVar4 = **(longlong **)(DAT_182d5aa70 + 0xb8);
  if ((lVar4 != 0) && (*(longlong *)(lVar4 + 0x38) != 0)) {
    ExposureUnnoticed2_Scripts_Base_SmoothFloat__SetSecond__0600175e
              (*(longlong *)(lVar4 + 0x38),0x3f000000,0);
    *(undefined1 *)(lVar4 + 0x30) = 1;
    if (*(longlong *)(lVar4 + 0x38) != 0) {
      *(undefined4 *)(*(longlong *)(lVar4 + 0x38) + 0x10) = 0x3f800000;
      uVar3 = FUN_1802c43a0(uRam0000000182d63718);
      ExposureUnnoticed2_ObjectUI_FadeOutPanel_WaitSceneLoadTwiceStarter___ctor__06001b5e(uVar3,0);
      if (*(int *)(lRam0000000182d63720 + 0xe0) == 0) {
        FUN_18035c820(lRam0000000182d63720);
      }
      lVar4 = *(longlong *)(*(longlong *)(lRam0000000182d63720 + 0xb8) + 0x10);
      if (lVar4 == 0) {
        if (*(int *)(lRam0000000182d63720 + 0xe0) == 0) {
          FUN_18035c820(lRam0000000182d63720);
        }
        uVar1 = **(undefined8 **)(lRam0000000182d63720 + 0xb8);
        lVar4 = FUN_1802c43a0(DAT_182d58368);
        FUN_1814df680(lVar4,uVar1,uRam0000000182d63730,0);
        *(longlong *)(*(longlong *)(lRam0000000182d63720 + 0xb8) + 0x10) = lVar4;
        if (DAT_182eb5d50 != 0) {
          uVar7 = (uint)(*(longlong *)(lRam0000000182d63720 + 0xb8) + 0x10U >> 0xc);
          uVar6 = (ulonglong)((uVar7 & 0x1fffff) >> 6);
          do {
            uVar2 = *(ulonglong *)(&DAT_182f0c920 + uVar6 * 8);
            LOCK();
            bVar8 = uVar2 == *(ulonglong *)(&DAT_182f0c920 + uVar6 * 8);
            if (bVar8) {
              *(ulonglong *)(&DAT_182f0c920 + uVar6 * 8) = uVar2 | 1L << (uVar7 & 0x3f);
            }
            UNLOCK();
          } while (!bVar8);
        }
      }
      if (*(int *)(lRam0000000182d63720 + 0xe0) == 0) {
        FUN_18035c820(lRam0000000182d63720);
      }
      lVar5 = *(longlong *)(*(longlong *)(lRam0000000182d63720 + 0xb8) + 0x18);
      if (lVar5 == 0) {
        if (*(int *)(lRam0000000182d63720 + 0xe0) == 0) {
          FUN_18035c820(lRam0000000182d63720);
        }
        uVar1 = **(undefined8 **)(lRam0000000182d63720 + 0xb8);
        lVar5 = FUN_1802c43a0(DAT_182d58368);
        FUN_1814df680(lVar5,uVar1,uRam0000000182d63728,0);
        *(longlong *)(*(longlong *)(lRam0000000182d63720 + 0xb8) + 0x18) = lVar5;
        if (DAT_182eb5d50 != 0) {
          uVar7 = (uint)(*(longlong *)(lRam0000000182d63720 + 0xb8) + 0x18U >> 0xc);
          uVar6 = (ulonglong)((uVar7 & 0x1fffff) >> 6);
          do {
            uVar2 = *(ulonglong *)(&DAT_182f0c920 + uVar6 * 8);
            LOCK();
            bVar8 = uVar2 == *(ulonglong *)(&DAT_182f0c920 + uVar6 * 8);
            if (bVar8) {
              *(ulonglong *)(&DAT_182f0c920 + uVar6 * 8) = uVar2 | 1L << (uVar7 & 0x3f);
            }
            UNLOCK();
          } while (!bVar8);
        }
      }
      if (*(int *)(lRam0000000182d5aa40 + 0xe0) == 0) {
        FUN_18035c820();
      }
      ExposureUnnoticed2_ObjectUI_FadeOutPanel_FadePanelView__Open__06001b4c
                (uVar3,lVar4,0,lVar5,1,0);
      return;
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

