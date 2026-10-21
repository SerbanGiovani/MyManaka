// Ghidra pseudocode; not original source or compilable C.
// ev_bb6c7736094b8eac2a8d0f64b91a1a7894411c5e32d9037788f0f42fca540299

void ExposureUnnoticed2_ObjectUI_MissionFailedPanel_MissionFailedPanelView__OnClickGoToTitle__06001957
               (void)

{
  ulonglong *puVar1;
  ulonglong uVar2;
  undefined8 uVar3;
  ulonglong uVar4;
  undefined8 uVar5;
  longlong lVar6;
  uint uVar7;
  
  if (cRam0000000182eb7bf9 == '\0') {
    FUN_1802f2810(&DAT_182d58368);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5aa40);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d63710);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d63720);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5bf18);
    LOCK();
    UNLOCK();
    cRam0000000182eb7bf9 = '\x01';
  }
  uVar5 = FUN_1802c43a0(uRam0000000182d5bf18);
  ExposureUnnoticed2_ObjectUI_FadeOutPanel_WaitSceneLoadStarter___ctor__06001b56(uVar5,0);
  if (*(int *)(lRam0000000182d63720 + 0xe0) == 0) {
    FUN_18035c820(lRam0000000182d63720);
  }
  lVar6 = *(longlong *)(*(longlong *)(lRam0000000182d63720 + 0xb8) + 0x20);
  if (lVar6 == 0) {
    if (*(int *)(lRam0000000182d63720 + 0xe0) == 0) {
      FUN_18035c820(lRam0000000182d63720);
    }
    uVar3 = **(undefined8 **)(lRam0000000182d63720 + 0xb8);
    lVar6 = FUN_1802c43a0(DAT_182d58368);
    FUN_1814df680(lVar6,uVar3,uRam0000000182d63710,0);
    *(longlong *)(*(longlong *)(lRam0000000182d63720 + 0xb8) + 0x20) = lVar6;
    if (DAT_182eb5d50 != 0) {
      uVar7 = (uint)(*(longlong *)(lRam0000000182d63720 + 0xb8) + 0x20U >> 0xc);
      puVar1 = (ulonglong *)(&DAT_182f0c920 + (ulonglong)((uVar7 & 0x1fffff) >> 6) * 8);
      do {
        uVar4 = *puVar1;
        LOCK();
        uVar2 = *puVar1;
        if (uVar4 == uVar2) {
          *puVar1 = uVar4 | 1L << (uVar7 & 0x3f);
        }
        UNLOCK();
      } while (uVar4 != uVar2);
    }
  }
  if (*(int *)(lRam0000000182d5aa40 + 0xe0) == 0) {
    FUN_18035c820();
  }
  ExposureUnnoticed2_ObjectUI_FadeOutPanel_FadePanelView__Open__06001b4c(uVar5,lVar6,0,0,1,0);
  return;
}

