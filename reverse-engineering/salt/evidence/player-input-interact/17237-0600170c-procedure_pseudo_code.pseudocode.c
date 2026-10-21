// Ghidra pseudocode; not original source or compilable C.
// ev_095404fc529f5eb23814302f1e9d86d99736b2b37426a3e20496d1e7b1262e2c

void ExposureUnnoticed2_Scripts_Base_InputManager__GetString__0600170c(undefined4 param_1)

{
  longlong lVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined8 local_res18;
  undefined8 local_res20;
  
  if (DAT_182eb7a94 == '\0') {
    FUN_1802f2810(&DAT_182d5aa88);
    LOCK();
    UNLOCK();
    DAT_182eb7a94 = '\x01';
  }
  if (*(int *)(DAT_182d5aa88 + 0xe0) == 0) {
    FUN_18035c820();
  }
  lVar1 = ExposureUnnoticed2_Scripts_Base_InputManager__GetInputAction__0600170b(param_1,0);
  local_res20 = 0;
  local_res18 = 0;
  if (lVar1 != 0) {
    FUN_18195e7b0(lVar1,0,&local_res20,&local_res18,0,0);
    return;
  }
  uVar2 = thunk_FUN_1802f2810(&DAT_182d528c8);
  uVar2 = thunk_FUN_1802c43a0(uVar2);
  uVar3 = thunk_FUN_1802f2810(&DAT_182d33490);
  FUN_1815c6a10(uVar2,uVar3,0);
  uVar3 = thunk_FUN_1802f2810(&DAT_182d40f50);
                    /* WARNING: Subroutine does not return */
  FUN_18031da90(uVar2,uVar3);
}

