// Ghidra pseudocode; not original source or compilable C.
// ev_a5ac9d0d38a027ce40e2acfc54d28fe1f42a18bacc4068e4ca4dc73e6f1ccc54

void UnityEngine_InputSystem_InputActionMap__get_Item__060001ca(longlong param_1,longlong param_2)

{
  longlong lVar1;
  uint uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  
  if (param_2 == 0) {
    uVar3 = thunk_FUN_1802f2810(&DAT_182d528c8);
    uVar3 = thunk_FUN_1802c43a0(uVar3);
    uVar4 = thunk_FUN_1802f2810(&DAT_182d41680);
    FUN_1815c6a10(uVar3,uVar4,0);
    uVar4 = thunk_FUN_1802f2810(&DAT_182d412b0);
                    /* WARNING: Subroutine does not return */
    FUN_18031da90(uVar3,uVar4);
  }
  uVar2 = FUN_1819530a0(param_1,param_2,0);
  if (uVar2 != 0xffffffff) {
    lVar1 = *(longlong *)(param_1 + 0x28);
    if (lVar1 == 0) {
                    /* WARNING: Subroutine does not return */
      FUN_18031dad0();
    }
    if (*(uint *)(lVar1 + 0x18) <= uVar2) {
                    /* WARNING: Subroutine does not return */
      FUN_18031dae0();
    }
    if (*(longlong *)(lVar1 + 0x20 + (longlong)(int)uVar2 * 8) != 0) {
      return;
    }
  }
  uVar3 = thunk_FUN_1802f2810(&DAT_182d6a100);
  uVar4 = thunk_FUN_1802f2810(&DAT_182d412a0);
  uVar3 = System_String__Concat__0600021c(uVar4,param_2,uVar3,0);
  uVar4 = thunk_FUN_1802f2810(&DAT_182d52df0);
  uVar4 = thunk_FUN_1802c43a0(uVar4);
  FUN_1815b4070(uVar4,uVar3,0);
  uVar3 = thunk_FUN_1802f2810(&DAT_182d412b0);
                    /* WARNING: Subroutine does not return */
  FUN_18031da90(uVar4,uVar3);
}

