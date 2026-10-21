// Ghidra pseudocode; not original source or compilable C.
// ev_cea6a06858507c34a9758d119bac457f12c09d16b3c247e9c3487bcb29f1e06c

void ExposureUnnoticed2_ObjectUI_OptionMenu_GraphicsOption_GraphicsOptionPanelView___AllReset_b__34_2__06001c6b
               (longlong param_1)

{
  ulonglong *puVar1;
  ulonglong uVar2;
  ulonglong uVar3;
  longlong lVar4;
  longlong lVar5;
  undefined8 uVar6;
  uint uVar7;
  bool bVar8;
  
  if (cRam0000000182eb7db2 == '\0') {
    FUN_1802f2810(&DAT_182d58368);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d583a0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d58080);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d58398);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d65d10);
    LOCK();
    UNLOCK();
    cRam0000000182eb7db2 = '\x01';
  }
  lVar4 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x38);
  if (lVar4 == 0) {
                    /* WARNING: Subroutine does not return */
    FUN_18031dad0();
  }
  *(undefined8 *)(lVar4 + 0x84) = 2;
  *(undefined4 *)(lVar4 + 0x80) = 0;
  *(undefined4 *)(lVar4 + 0x8c) = 0;
  *(undefined1 *)(lVar4 + 0xa4) = 0;
  *(undefined4 *)(lVar4 + 0xb8) = 0;
  *(undefined4 *)(lVar4 + 0x90) = 0x3c;
  *(undefined4 *)(lVar4 + 0x94) = 0x32;
  *(undefined4 *)(lVar4 + 0x98) = 0x32;
  *(undefined4 *)(lVar4 + 0xa5) = 0x1010101;
  *(undefined4 *)(lVar4 + 0xac) = 0x1e;
  *(undefined4 *)(lVar4 + 0xb4) = 100;
  *(undefined4 *)(lVar4 + 0xb0) = 100;
  *(undefined1 *)(lVar4 + 0xbc) = 1;
  *(undefined4 *)(lVar4 + 0x9c) = 0x5a;
  *(undefined4 *)(lVar4 + 0xa0) = 0x55;
  if (*(int *)(DAT_182d58080 + 0xe0) == 0) {
    FUN_18035c820(DAT_182d58080);
  }
  uVar6 = *(undefined8 *)(*(longlong *)(DAT_182d58080 + 0xb8) + 0xd8);
  if (*(int *)(DAT_182d583a0 + 0xe0) == 0) {
    FUN_18035c820();
  }
  ExposureUnnoticed2_Scripts_Base_EventManager__Broadcast__06001716(uVar6,0);
  ExposureUnnoticed2_ObjectUI_OptionMenu_GraphicsOption_GraphicsOptionPanelView__Initialize__06001c55
            (param_1,*(undefined8 *)(param_1 + 0x30),0);
  uVar6 = FUN_1802c43a0(DAT_182d58368);
  FUN_1814df680(uVar6,param_1,uRam0000000182d65d10,0);
  if (DAT_182eb7aa1 == '\0') {
    FUN_1802f2810(&DAT_182d5f910,1,0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d5f908);
    LOCK();
    UNLOCK();
    DAT_182eb7aa1 = '\x01';
  }
  lVar4 = ExposureUnnoticed2_Scripts_Base_Scheduler__get_Instance__0600174a(0);
  if (lVar4 != 0) {
    lVar4 = *(longlong *)(lVar4 + 0x20);
    lVar5 = FUN_1802c43a0(DAT_182d5f910);
    bVar8 = DAT_182eb5d50 != 0;
    *(undefined8 *)(lVar5 + 0x10) = uVar6;
    if (bVar8) {
      uVar7 = (uint)(lVar5 + 0x10U >> 0xc);
      puVar1 = (ulonglong *)(&DAT_182f0c920 + (ulonglong)((uVar7 & 0x1fffff) >> 6) * 8);
      do {
        uVar3 = *puVar1;
        LOCK();
        uVar2 = *puVar1;
        if (uVar3 == uVar2) {
          *puVar1 = uVar3 | 1L << (uVar7 & 0x3f);
        }
        UNLOCK();
      } while (uVar3 != uVar2);
    }
    *(undefined4 *)(lVar5 + 0x18) = 1;
    if (lVar4 != 0) {
      FUN_1800068f0(lVar4,lVar5);
      return;
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

