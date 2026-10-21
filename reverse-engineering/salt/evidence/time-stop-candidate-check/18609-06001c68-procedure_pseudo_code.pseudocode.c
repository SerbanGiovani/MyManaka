// Ghidra pseudocode; not original source or compilable C.
// ev_c526eb24315b027d7dfa26d36df9ed377c68f8c119b33b61c8d97c86557f5b7a

/* WARNING: Removing unreachable block (ram,0x0001804b201c) */

void ExposureUnnoticed2_ObjectUI_OptionMenu_GraphicsOption_GraphicsOptionPanelView___InitializeFov_b__32_1__06001c68
               (longlong param_1,undefined4 param_2)

{
  longlong lVar1;
  longlong *plVar2;
  char cVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined4 auStackX_10 [6];
  undefined8 uStack_48;
  undefined8 uStack_40;
  undefined8 uStack_38;
  undefined8 uStack_30;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  
  if (cRam0000000182eb7db0 == '\0') {
    FUN_1802f2810(&DAT_182d583a0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d58080);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d58398);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d55000);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d5f4f0);
    LOCK();
    UNLOCK();
    cRam0000000182eb7db0 = '\x01';
  }
  lVar1 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x38);
  if (lVar1 != 0) {
    *(undefined4 *)(lVar1 + 0xa0) = param_2;
    lVar1 = *(longlong *)(param_1 + 0xa0);
    auStackX_10[0] = param_2;
    uVar4 = FUN_1802c3ff0(DAT_182d55000,auStackX_10);
    uVar5 = DAT_182d5f4f0;
    uStack_48 = 0;
    uStack_40 = 0;
    uStack_38 = 0;
    uStack_30 = (undefined *)0x0;
    FUN_18162b5c0(&uStack_48,uVar4,0);
    uStack_28 = (undefined4)uStack_48;
    uStack_24 = uStack_48._4_4_;
    uStack_20 = (undefined4)uStack_40;
    uStack_1c = uStack_40._4_4_;
    uStack_18 = (undefined4)uStack_38;
    uStack_14 = uStack_38._4_4_;
    uStack_10 = (undefined4)uStack_30;
    uStack_c = uStack_30._4_4_;
    uVar5 = System_String__FormatHelper__06000227(0,uVar5,&uStack_28,0);
    if ((lVar1 != 0) && (plVar2 = *(longlong **)(lVar1 + 0x20), plVar2 != (longlong *)0x0)) {
      (**(code **)(*plVar2 + 0x558))(plVar2,uVar5,*(undefined8 *)(*plVar2 + 0x560));
      if (*(int *)(DAT_182d58080 + 0xe0) == 0) {
        FUN_18035c820(DAT_182d58080);
      }
      plVar2 = *(longlong **)(*(longlong *)(DAT_182d58080 + 0xb8) + 200);
      if (*(int *)(DAT_182d583a0 + 0xe0) == 0) {
        FUN_18035c820();
      }
      if (DAT_182eb7a98 == '\0') {
        uStack_30 = (undefined *)0x1804b1f92;
        FUN_1802f2810(&DAT_182d5f9b8,0);
        LOCK();
        UNLOCK();
        uStack_30 = (undefined *)0x1804b1fa3;
        FUN_1802f2810(&DAT_182d583a0);
        LOCK();
        UNLOCK();
        DAT_182eb7a98 = '\x01';
      }
      if (*(int *)(DAT_182d583a0 + 0xe0) == 0) {
        uStack_30 = (undefined *)0x1804b1fd0;
        FUN_18035c820(DAT_182d583a0);
      }
      lVar1 = **(longlong **)(DAT_182d583a0 + 0xb8);
      if (plVar2 != (longlong *)0x0) {
        uStack_30 = (undefined *)0x1804b1ff2;
        uVar5 = FUN_1802c5ac0(*plVar2 + 0x20);
        if (lVar1 != 0) {
          uStack_30 = (undefined *)0x1804b200e;
          cVar3 = FUN_180ebb4c0(lVar1,uVar5,&stack0x00000008,DAT_182d5f9b8);
          if (cVar3 == '\0') {
            return;
          }
        }
      }
                    /* WARNING: Subroutine does not return */
      uStack_30 = &UNK_1804b203d;
      FUN_18031dad0();
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

