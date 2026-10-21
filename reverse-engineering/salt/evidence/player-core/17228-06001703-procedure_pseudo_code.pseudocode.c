// Ghidra pseudocode; not original source or compilable C.
// ev_0597fb68fb3739905b7df78d5c206a2bcdf942eeb3568d272c7cc3f3f04b2d1c

ulonglong *
ExposureUnnoticed2_Scripts_Base_InputManager__GetVector3__06001703(ulonglong *param_1,int param_2)

{
  longlong lVar1;
  ulonglong uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined4 uStackX_c;
  int local_res10 [2];
  
  if (DAT_182eb7a8b == '\0') {
    FUN_1802f2810(&DAT_182d58288);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d5fac8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d5aa88);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d5fa98);
    LOCK();
    UNLOCK();
    DAT_182eb7a8b = '\x01';
  }
  if (param_2 == 0) {
    if (*(int *)(DAT_182d5aa88 + 0xe0) == 0) {
      FUN_18035c820(DAT_182d5aa88);
    }
    lVar1 = *(longlong *)(*(longlong *)(DAT_182d5aa88 + 0xb8) + 0x18);
    if ((lVar1 != 0) && (lVar1 = *(longlong *)(lVar1 + 0x90), lVar1 != 0)) {
      lVar1 = FUN_181952d80(lVar1,DAT_182d5fa98,0);
      if (lVar1 != 0) {
        uVar2 = FUN_1800067d0(lVar1);
        if (*(int *)(DAT_182d58288 + 0xe0) == 0) {
          FUN_18035c820();
        }
        uStackX_c = (undefined4)(uVar2 >> 0x20);
        *param_1 = uVar2 & 0xffffffff;
        *(undefined4 *)(param_1 + 1) = uStackX_c;
        return param_1;
      }
    }
                    /* WARNING: Subroutine does not return */
    FUN_18031dad0();
  }
  local_res10[0] = param_2;
  uVar3 = thunk_FUN_1802f2810(&DAT_182d5fa80);
  uVar3 = il2cpp_value_box(uVar3,local_res10);
  uVar4 = thunk_FUN_1802f2810(&DAT_182d54bf8);
  uVar4 = thunk_FUN_1802c43a0(uVar4);
  uVar5 = thunk_FUN_1802f2810(&DAT_182d5c530);
  FUN_1815c6ba0(uVar4,uVar5,uVar3,0,0);
  uVar3 = thunk_FUN_1802f2810(&DAT_182d5fa78);
                    /* WARNING: Subroutine does not return */
  FUN_18031da90(uVar4,uVar3);
}

