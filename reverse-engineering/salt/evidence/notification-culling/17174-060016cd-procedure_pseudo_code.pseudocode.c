// Ghidra pseudocode; not original source or compilable C.
// ev_86dc935c254ab27d713f4149530f09fd8a0750db795261a8f21f11854d63d348

bool ExposureUnnoticed2_Scripts_InGame_ObjectCulling_ObjectCuller__IsCulling__060016cd
               (longlong param_1,undefined8 param_2)

{
  longlong lVar1;
  int iVar2;
  
  if (cRam0000000182eb7a6f == '\0') {
    FUN_1802f2810(&DAT_182d53aa8);
    LOCK();
    UNLOCK();
    cRam0000000182eb7a6f = '\x01';
  }
  lVar1 = *(longlong *)(param_1 + 0x28);
  if (*(int *)(DAT_182d53aa8 + 0xe0) == 0) {
    FUN_18035c820();
  }
  if (DAT_182ec12f3 == '\0') {
    FUN_1802f2810(&DAT_182d53aa8);
    LOCK();
    UNLOCK();
    DAT_182ec12f3 = '\x01';
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
      lVar1 = *(longlong *)(param_1 + 0x28);
      if (lVar1 != 0) {
        if (cRam0000000182eb7a6a == '\0') {
          FUN_1802f2810(0x182d5fca0);
          LOCK();
          UNLOCK();
          cRam0000000182eb7a6a = '\x01';
        }
        lVar1 = *(longlong *)(lVar1 + 0x20);
        if (lVar1 != 0) {
          iVar2 = FUN_180e9f040(lVar1,param_2,
                                *(undefined8 *)
                                 (*(longlong *)(*(longlong *)(lRam0000000182d5fca0 + 0x20) + 0xc0) +
                                 0xf8));
          if (iVar2 < 0) {
            return false;
          }
          return *(char *)(param_1 + 0x38) == '\0';
        }
      }
                    /* WARNING: Subroutine does not return */
      FUN_18031dad0();
    }
  }
  return false;
}

