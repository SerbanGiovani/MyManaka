// Ghidra pseudocode; not original source or compilable C.
// ev_41fe137795041fbbb87deaea8294bfe2656d62c2b85896251c799ab05ec1cb83

void ExposureUnnoticed2_ObjectUI_SystemMenu_SystemMenuView___OnClickEmergencyEscape_b__15_2__06001817
               (undefined8 param_1)

{
  undefined8 uVar1;
  ulonglong uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  longlong lVar5;
  ulonglong uVar6;
  uint uVar7;
  bool bVar8;
  
  if (cRam0000000182eb7b19 == '\0') {
    FUN_1802f2810(&DAT_182d58368);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5aa40);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d53c48);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5f210);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5ffc8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5f208);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5f260);
    LOCK();
    UNLOCK();
    cRam0000000182eb7b19 = '\x01';
  }
  ExposureUnnoticed2_ObjectUI_SystemMenu_SystemMenuView__OnClickResume__0600180a(param_1,0);
  if ((**(longlong **)(DAT_182d53c48 + 0xb8) != 0) &&
     (lVar5 = *(longlong *)(**(longlong **)(DAT_182d53c48 + 0xb8) + 0x30), lVar5 != 0)) {
    *(undefined1 *)(lVar5 + 0x13) = 1;
    uVar3 = FUN_1802c43a0(uRam0000000182d5ffc8);
    ExposureUnnoticed2_ObjectUI_FadeOutPanel_TimeWaitStarter___ctor__06001b53(uVar3,0x3f800000,0);
    uVar4 = FUN_1802c43a0(DAT_182d58368);
    FUN_1814df680(uVar4,param_1,uRam0000000182d5f210,0);
    if (*(int *)(lRam0000000182d5f260 + 0xe0) == 0) {
      FUN_18035c820();
    }
    lVar5 = *(longlong *)(*(longlong *)(lRam0000000182d5f260 + 0xb8) + 0x20);
    if (lVar5 == 0) {
      if (*(int *)(lRam0000000182d5f260 + 0xe0) == 0) {
        FUN_18035c820();
      }
      uVar1 = **(undefined8 **)(lRam0000000182d5f260 + 0xb8);
      lVar5 = FUN_1802c43a0(DAT_182d58368);
      FUN_1814df680(lVar5,uVar1,uRam0000000182d5f208,0);
      *(longlong *)(*(longlong *)(lRam0000000182d5f260 + 0xb8) + 0x20) = lVar5;
      if (DAT_182eb5d50 != 0) {
        uVar7 = (uint)(*(longlong *)(lRam0000000182d5f260 + 0xb8) + 0x20U >> 0xc);
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
    ExposureUnnoticed2_ObjectUI_FadeOutPanel_FadePanelView__Open__06001b4c(uVar3,uVar4,0,lVar5,0,0);
    return;
  }
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

