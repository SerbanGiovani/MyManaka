// Ghidra pseudocode; not original source or compilable C.
// ev_1906ba1b6b0d603870ae4e6945b674716e50c3723c933fcc61cea2db56201c70

void __c___OnClickSaveAndGoToTitle_b__18_1__06001820(void)

{
  ulonglong *puVar1;
  ulonglong uVar2;
  undefined8 uVar3;
  ulonglong uVar4;
  undefined8 uVar5;
  longlong lVar6;
  uint uVar7;
  
  if (cRam0000000182eb7b2c == '\0') {
    FUN_1802f2810(&DAT_182d58368);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d583a0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d58080);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5aa40);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d61bc0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5f260);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5bf18);
    LOCK();
    UNLOCK();
    cRam0000000182eb7b2c = '\x01';
  }
  if (*(int *)(DAT_182d58080 + 0xe0) == 0) {
    FUN_18035c820(DAT_182d58080);
  }
  uVar5 = *(undefined8 *)(*(longlong *)(DAT_182d58080 + 0xb8) + 0x18);
  if (*(int *)(DAT_182d583a0 + 0xe0) == 0) {
    FUN_18035c820();
  }
  ExposureUnnoticed2_Scripts_Base_EventManager__Broadcast__06001716(uVar5,0);
  uVar5 = FUN_1802c43a0(uRam0000000182d5bf18);
  ExposureUnnoticed2_ObjectUI_FadeOutPanel_WaitSceneLoadStarter___ctor__06001b56(uVar5,0);
  if (*(int *)(lRam0000000182d5f260 + 0xe0) == 0) {
    FUN_18035c820(lRam0000000182d5f260);
  }
  lVar6 = *(longlong *)(*(longlong *)(lRam0000000182d5f260 + 0xb8) + 0x30);
  if (lVar6 == 0) {
    if (*(int *)(lRam0000000182d5f260 + 0xe0) == 0) {
      FUN_18035c820(lRam0000000182d5f260);
    }
    uVar3 = **(undefined8 **)(lRam0000000182d5f260 + 0xb8);
    lVar6 = FUN_1802c43a0(DAT_182d58368);
    FUN_1814df680(lVar6,uVar3,uRam0000000182d61bc0,0);
    *(longlong *)(*(longlong *)(lRam0000000182d5f260 + 0xb8) + 0x30) = lVar6;
    if (DAT_182eb5d50 != 0) {
      uVar7 = (uint)(*(longlong *)(lRam0000000182d5f260 + 0xb8) + 0x30U >> 0xc);
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

