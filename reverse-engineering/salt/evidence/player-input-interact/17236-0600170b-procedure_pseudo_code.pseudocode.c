// Ghidra pseudocode; not original source or compilable C.
// ev_89a78b38dbc1b4aa0fbf353f8a6262c551f57856b96de0e4303d8537548d83ac

void ExposureUnnoticed2_Scripts_Base_InputManager__GetInputAction__0600170b(undefined4 param_1)

{
  longlong lVar1;
  longlong lVar2;
  undefined8 uVar3;
  
  if (DAT_182eb7a93 == '\0') {
    FUN_1802f2810(&DAT_182d5fa38);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d5aa88);
    LOCK();
    UNLOCK();
    DAT_182eb7a93 = '\x01';
  }
  if (*(int *)(DAT_182d5aa88 + 0xe0) == 0) {
    FUN_18035c820();
  }
  lVar1 = *(longlong *)(*(longlong *)(DAT_182d5aa88 + 0xb8) + 0x18);
  if (lVar1 != 0) {
    lVar2 = *(longlong *)(*(longlong *)(DAT_182d5aa88 + 0xb8) + 0x10);
    lVar1 = *(longlong *)(lVar1 + 0x90);
    if (lVar2 != 0) {
      uVar3 = FUN_180e75f20(lVar2,param_1,DAT_182d5fa38);
      if (lVar1 != 0) {
        FUN_181952d80(lVar1,uVar3,0);
        return;
      }
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

