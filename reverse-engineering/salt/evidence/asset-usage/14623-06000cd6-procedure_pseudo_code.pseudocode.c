// Ghidra pseudocode; not original source or compilable C.
// ev_4dd40386a8706045a6e1d6b089a477f6f03f2f7b774a344ae368c606458a2c79

undefined8
ExposureUnnoticed2_Object3D_Player_Scripts_PlayerBodyMaterialController__TransToMaterialAsset__06000cd6
          (undefined8 param_1,undefined4 param_2)

{
  undefined8 uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined4 auStackX_10 [6];
  
  if (cRam0000000182eb83b4 == '\0') {
    FUN_1802f2810(0x182d58238);
    LOCK();
    UNLOCK();
    cRam0000000182eb83b4 = '\x01';
  }
  switch(param_2) {
  case 0:
    if (**(longlong **)(lRam0000000182d58238 + 0xb8) != 0) {
      return *(undefined8 *)(**(longlong **)(lRam0000000182d58238 + 0xb8) + 0x288);
    }
    break;
  case 1:
    if (**(longlong **)(lRam0000000182d58238 + 0xb8) != 0) {
      return *(undefined8 *)(**(longlong **)(lRam0000000182d58238 + 0xb8) + 0x290);
    }
    break;
  case 2:
    if (**(longlong **)(lRam0000000182d58238 + 0xb8) != 0) {
      return *(undefined8 *)(**(longlong **)(lRam0000000182d58238 + 0xb8) + 0x2a0);
    }
    break;
  case 3:
    if (**(longlong **)(lRam0000000182d58238 + 0xb8) != 0) {
      return *(undefined8 *)(**(longlong **)(lRam0000000182d58238 + 0xb8) + 0x2a8);
    }
    break;
  case 4:
    if (**(longlong **)(lRam0000000182d58238 + 0xb8) != 0) {
      return *(undefined8 *)(**(longlong **)(lRam0000000182d58238 + 0xb8) + 0x2b0);
    }
    break;
  case 5:
    if (**(longlong **)(lRam0000000182d58238 + 0xb8) != 0) {
      return *(undefined8 *)(**(longlong **)(lRam0000000182d58238 + 0xb8) + 0x2b8);
    }
    break;
  case 6:
    if (**(longlong **)(lRam0000000182d58238 + 0xb8) != 0) {
      return *(undefined8 *)(**(longlong **)(lRam0000000182d58238 + 0xb8) + 0x2c0);
    }
    break;
  case 7:
    if (**(longlong **)(lRam0000000182d58238 + 0xb8) != 0) {
      return *(undefined8 *)(**(longlong **)(lRam0000000182d58238 + 0xb8) + 0x2c8);
    }
    break;
  default:
    auStackX_10[0] = param_2;
    uVar1 = thunk_FUN_1802f2810(0x182d3e9c0);
    uVar1 = il2cpp_value_box(uVar1,auStackX_10);
    uVar2 = thunk_FUN_1802f2810(&DAT_182d54bf8);
    uVar2 = thunk_FUN_1802c43a0(uVar2);
    uVar3 = thunk_FUN_1802f2810(0x182d5c530);
    FUN_1815c6ba0(uVar2,uVar3,uVar1,0,0);
    uVar1 = thunk_FUN_1802f2810(0x182d3e9c8);
                    /* WARNING: Subroutine does not return */
    FUN_18031da90(uVar2,uVar1);
  case 9:
    if (**(longlong **)(lRam0000000182d58238 + 0xb8) != 0) {
      return *(undefined8 *)(**(longlong **)(lRam0000000182d58238 + 0xb8) + 0x2d0);
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

