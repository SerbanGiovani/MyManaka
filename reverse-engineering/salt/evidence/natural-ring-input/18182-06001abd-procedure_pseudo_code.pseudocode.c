// Ghidra pseudocode; not original source or compilable C.
// ev_7022697a0a5bf0a2cc418667f8da6f08be2294fd499b80adf79f6d20e137b4e9

void __c__DisplayClass79_0___OpenRingMenu_b__1__06001abd(longlong param_1,longlong param_2)

{
  longlong lVar1;
  longlong *plVar2;
  uint uVar3;
  undefined8 uVar4;
  longlong lVar5;
  undefined4 auStackX_8 [2];
  
  if (cRam0000000182eb7cbb == '\0') {
    FUN_1802f2810(&DAT_182d58398);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d64928);
    LOCK();
    UNLOCK();
    cRam0000000182eb7cbb = '\x01';
  }
  switch(*(undefined4 *)(param_1 + 0x18)) {
  case 1:
    uVar3 = 1;
    lVar5 = 0x28;
    break;
  case 2:
    uVar3 = 2;
    lVar5 = 0x30;
    break;
  case 3:
    uVar3 = 3;
    lVar5 = 0x38;
    break;
  case 4:
    uVar3 = 4;
    lVar5 = 0x40;
    break;
  case 5:
    uVar3 = 5;
    lVar5 = 0x48;
    break;
  case 6:
    uVar3 = 6;
    lVar5 = 0x50;
    break;
  case 7:
    uVar3 = 7;
    lVar5 = 0x58;
    break;
  default:
    auStackX_8[0] = *(undefined4 *)(param_1 + 0x18);
    uVar4 = il2cpp_value_box(uRam0000000182d64928,auStackX_8);
                    /* WARNING: Subroutine does not return */
    _PrivateImplementationDetails___ThrowSwitchExpressionException__06001e66(uVar4,0);
  }
  if ((*(longlong *)(param_1 + 0x10) != 0) &&
     (lVar1 = *(longlong *)(*(longlong *)(param_1 + 0x10) + 0x60), lVar1 != 0)) {
    if (*(uint *)(lVar1 + 0x18) <= uVar3) {
                    /* WARNING: Subroutine does not return */
      FUN_18031dae0();
    }
    lVar5 = *(longlong *)(lVar5 + lVar1);
    if (lVar5 != 0) {
      if (cRam0000000182eb7cc5 == '\0') {
        FUN_1802f2810(&DAT_182d61798);
        LOCK();
        UNLOCK();
        cRam0000000182eb7cc5 = '\x01';
      }
      plVar2 = *(longlong **)(lVar5 + 0x20);
      uVar4 = DAT_182d61798;
      if (param_2 != 0) {
        uVar4 = ExposureUnnoticed2_Scripts_Base_Localizer__Trans__060017af
                          (*(undefined8 *)(param_2 + 0x20),0);
      }
      if (plVar2 != (longlong *)0x0) {
        (**(code **)(*plVar2 + 0x558))(plVar2,uVar4,*(undefined8 *)(*plVar2 + 0x560));
        switch(*(undefined4 *)(param_1 + 0x18)) {
        case 1:
          lVar5 = *(longlong *)(param_1 + 0x10);
          if (lVar5 == 0) goto code_r0x000180504835;
          *(longlong *)(lVar5 + 0x90) = param_2;
          FUN_18031d480(lVar5 + 0x90);
          if (param_2 != 0) {
            lVar5 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
            if (lVar5 == 0) goto code_r0x000180504835;
            *(undefined4 *)(lVar5 + 0x54) = *(undefined4 *)(param_2 + 0x30);
          }
          break;
        case 2:
          lVar5 = *(longlong *)(param_1 + 0x10);
          if (lVar5 == 0) goto code_r0x000180504835;
          *(longlong *)(lVar5 + 0x98) = param_2;
          FUN_18031d480(lVar5 + 0x98);
          if (param_2 != 0) {
            lVar5 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
            if (lVar5 == 0) goto code_r0x000180504835;
            *(undefined4 *)(lVar5 + 0x58) = *(undefined4 *)(param_2 + 0x30);
          }
          break;
        case 3:
          lVar5 = *(longlong *)(param_1 + 0x10);
          if (lVar5 == 0) goto code_r0x000180504835;
          *(longlong *)(lVar5 + 0xa0) = param_2;
          FUN_18031d480(lVar5 + 0xa0);
          if (param_2 != 0) {
            lVar5 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
            if (lVar5 == 0) goto code_r0x000180504835;
            *(undefined4 *)(lVar5 + 0x5c) = *(undefined4 *)(param_2 + 0x30);
          }
          break;
        case 4:
          lVar5 = *(longlong *)(param_1 + 0x10);
          if (lVar5 == 0) goto code_r0x000180504835;
          *(longlong *)(lVar5 + 0xa8) = param_2;
          FUN_18031d480(lVar5 + 0xa8);
          if (param_2 != 0) {
            lVar5 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
            if (lVar5 == 0) goto code_r0x000180504835;
            *(undefined4 *)(lVar5 + 0x60) = *(undefined4 *)(param_2 + 0x30);
          }
          break;
        case 5:
          lVar5 = *(longlong *)(param_1 + 0x10);
          if (lVar5 == 0) goto code_r0x000180504835;
          *(longlong *)(lVar5 + 0xb0) = param_2;
          FUN_18031d480(lVar5 + 0xb0);
          if (param_2 != 0) {
            lVar5 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
            if (lVar5 == 0) goto code_r0x000180504835;
            *(undefined4 *)(lVar5 + 100) = *(undefined4 *)(param_2 + 0x30);
          }
          break;
        case 6:
          lVar5 = *(longlong *)(param_1 + 0x10);
          if (lVar5 == 0) goto code_r0x000180504835;
          *(longlong *)(lVar5 + 0xb8) = param_2;
          FUN_18031d480(lVar5 + 0xb8);
          if (param_2 != 0) {
            lVar5 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
            if (lVar5 == 0) goto code_r0x000180504835;
            *(undefined4 *)(lVar5 + 0x68) = *(undefined4 *)(param_2 + 0x30);
          }
          break;
        case 7:
          lVar5 = *(longlong *)(param_1 + 0x10);
          if (lVar5 == 0) goto code_r0x000180504835;
          *(longlong *)(lVar5 + 0xc0) = param_2;
          FUN_18031d480(lVar5 + 0xc0);
          if (param_2 != 0) {
            lVar5 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
            if (lVar5 == 0) goto code_r0x000180504835;
            *(undefined4 *)(lVar5 + 0x6c) = *(undefined4 *)(param_2 + 0x30);
          }
        }
        return;
      }
    }
  }
code_r0x000180504835:
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

