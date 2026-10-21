// Ghidra pseudocode; not original source or compilable C.
// ev_0c201164068e9e8cf2a27a1381bc97e837ddd7c1fc6b2c6bfb4f370d27f4e903

void ExposureUnnoticed2_Object3D_InteractArea_InteractAreaController__Update__06001189
               (longlong param_1)

{
  longlong lVar1;
  
  if (cRam0000000182eb77e6 == '\0') {
    FUN_1802f2810(&DAT_182d58398);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d53aa8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d58378);
    LOCK();
    UNLOCK();
    cRam0000000182eb77e6 = '\x01';
  }
  if (*(char *)(param_1 + 0x68) == '\0') {
    return;
  }
  if (cRam0000000182eb5495 == '\0') {
    FUN_1802f2810(&DAT_182d5a8e8);
    LOCK();
    UNLOCK();
    cRam0000000182eb5495 = '\x01';
  }
  lVar1 = **(longlong **)(DAT_182d5a8e8 + 0xb8);
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
  if (lVar1 != 0) {
    if (*(int *)(DAT_182d53aa8 + 0xe0) == 0) {
      FUN_18035c820();
    }
    if (*(longlong *)(lVar1 + 0x10) != 0) {
      *(undefined4 *)(param_1 + 0x7c) = 2;
      return;
    }
  }
  if ((((**(longlong **)(DAT_182d58378 + 0xb8) != 0) &&
       (lVar1 = *(longlong *)(**(longlong **)(DAT_182d58378 + 0xb8) + 0x40), lVar1 != 0)) &&
      (lVar1 = *(longlong *)(lVar1 + 0x60), lVar1 != 0)) &&
     (lVar1 = *(longlong *)(lVar1 + 0x48), lVar1 != 0)) {
    if (((*(int *)(lVar1 + 0x18) == -1) || (*(char *)(param_1 + 0x30) != '\0')) &&
       (*(int *)(param_1 + 0x7c) < 1)) {
      *(undefined1 *)(param_1 + 0x68) = 0;
      lVar1 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x38);
      if ((lVar1 == 0) || (*(longlong *)(param_1 + 0x28) == 0)) goto DAT_180454070;
      FUN_181f3ea80(*(longlong *)(param_1 + 0x28),*(char *)(lVar1 + 0x13) == '\0',0);
    }
    *(int *)(param_1 + 0x7c) = *(int *)(param_1 + 0x7c) + -1;
    return;
  }
DAT_180454070:
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

