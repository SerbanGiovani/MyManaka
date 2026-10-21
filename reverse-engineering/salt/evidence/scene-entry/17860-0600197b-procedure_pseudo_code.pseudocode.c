// Ghidra pseudocode; not original source or compilable C.
// ev_77bed417e472e9f7ee7be20b6fc2f6b7362e8c4c928a40859ff6d03eaff10f0a

void ExposureUnnoticed2_ObjectUI_SaveDataSelectPanel_SaveDataSelectPanelView__TransScene__0600197b
               (void)

{
  ulonglong *puVar1;
  ulonglong uVar2;
  undefined8 uVar3;
  ulonglong uVar4;
  undefined8 uVar5;
  longlong lVar6;
  uint uVar7;
  
  if (cRam0000000182eb7c0e == '\0') {
    FUN_1802f2810(&DAT_182d58368);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5aa40);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d53c48);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d53aa8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d63668);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d63660);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d63718);
    LOCK();
    UNLOCK();
    cRam0000000182eb7c0e = '\x01';
  }
  lVar6 = **(longlong **)(lRam0000000182d53c48 + 0xb8);
  if (*(int *)(DAT_182d53aa8 + 0xe0) == 0) {
    FUN_18035c820();
  }
  if (DAT_182ec12f4 == '\0') {
    FUN_1802f2810(&DAT_182d53aa8);
    LOCK();
    UNLOCK();
    DAT_182ec12f4 = '\x01';
  }
  if (*(int *)(DAT_182d53aa8 + 0xe0) == 0) {
    FUN_18035c820();
  }
  if (DAT_182ec129b == '\0') {
    FUN_1802f2810(&DAT_182d53aa8);
    LOCK();
    UNLOCK();
    DAT_182ec129b = '\x01';
  }
  if (lVar6 != 0) {
    if (*(int *)(DAT_182d53aa8 + 0xe0) == 0) {
      FUN_18035c820();
    }
    if (*(longlong *)(lVar6 + 0x10) != 0) {
      if ((**(longlong **)(lRam0000000182d53c48 + 0xb8) == 0) ||
         (lVar6 = *(longlong *)(**(longlong **)(lRam0000000182d53c48 + 0xb8) + 0x30), lVar6 == 0)) {
                    /* WARNING: Subroutine does not return */
        FUN_18031dad0();
      }
      *(undefined1 *)(lVar6 + 0x10) = 1;
    }
  }
  uVar5 = FUN_1802c43a0(uRam0000000182d63718);
  ExposureUnnoticed2_ObjectUI_FadeOutPanel_WaitSceneLoadTwiceStarter___ctor__06001b5e(uVar5,0);
  if (*(int *)(lRam0000000182d63660 + 0xe0) == 0) {
    FUN_18035c820(lRam0000000182d63660);
  }
  lVar6 = *(longlong *)(*(longlong *)(lRam0000000182d63660 + 0xb8) + 8);
  if (lVar6 == 0) {
    if (*(int *)(lRam0000000182d63660 + 0xe0) == 0) {
      FUN_18035c820(lRam0000000182d63660);
    }
    uVar3 = **(undefined8 **)(lRam0000000182d63660 + 0xb8);
    lVar6 = FUN_1802c43a0(DAT_182d58368);
    FUN_1814df680(lVar6,uVar3,uRam0000000182d63668,0);
    *(longlong *)(*(longlong *)(lRam0000000182d63660 + 0xb8) + 8) = lVar6;
    if (DAT_182eb5d50 != 0) {
      uVar7 = (uint)(*(longlong *)(lRam0000000182d63660 + 0xb8) + 8U >> 0xc);
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

