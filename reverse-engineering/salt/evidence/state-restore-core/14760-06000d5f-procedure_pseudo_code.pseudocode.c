// Ghidra pseudocode; not original source or compilable C.
// ev_64ae707c34b60793d5094b503cb5d6f02056dab26cdab614cb085fd750229309

void ExposureUnnoticed2_Object3D_Player_Scripts_PlayerController__Dispose__06000d5f
               (longlong param_1)

{
  longlong lVar1;
  bool bVar2;
  
  if (cRam0000000182eb83e4 == '\0') {
    FUN_1802f2810(&DAT_182d53aa8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d58378);
    LOCK();
    UNLOCK();
    cRam0000000182eb83e4 = '\x01';
  }
  lVar1 = **(longlong **)(DAT_182d58378 + 0xb8);
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
  if (param_1 != 0 || lVar1 != 0) {
    if (param_1 == 0) {
      if (*(int *)(DAT_182d53aa8 + 0xe0) == 0) {
        FUN_18035c820();
      }
      if (lVar1 == 0) {
                    /* WARNING: Subroutine does not return */
        FUN_18031dad0();
      }
      bVar2 = *(longlong *)(lVar1 + 0x10) == 0;
    }
    else if (lVar1 == 0) {
      if (*(int *)(DAT_182d53aa8 + 0xe0) == 0) {
        FUN_18035c820();
      }
      bVar2 = *(longlong *)(param_1 + 0x10) == 0;
    }
    else {
      bVar2 = lVar1 == param_1;
    }
    if (!bVar2) {
      return;
    }
  }
  if (*(longlong *)(param_1 + 0x40) != 0) {
    ExposureUnnoticed2_Object3D_Player_Scripts_PlayerClassAccessor__Dispose__06000d33
              (*(longlong *)(param_1 + 0x40),0);
  }
  return;
}

