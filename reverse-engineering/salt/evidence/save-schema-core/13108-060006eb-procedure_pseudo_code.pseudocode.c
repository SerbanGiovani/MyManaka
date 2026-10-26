// Ghidra pseudocode; not original source or compilable C.
// ev_f4098fb744d7be46c10aad4c84784908c9af1b4feb54a7e07da5544932e7cf0b

undefined8 ES3Internal_ES3TypeMgr__GetES3Type__060006eb(undefined8 param_1)

{
  longlong lVar1;
  char cVar2;
  
  if (DAT_182eb80bb == '\0') {
    FUN_1802f2810(&DAT_182d6a2c8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d52ec0);
    LOCK();
    UNLOCK();
    DAT_182eb80bb = '\x01';
  }
  if (*(int *)(DAT_182d52ec0 + 0xe0) == 0) {
    FUN_18035c820(DAT_182d52ec0);
  }
  if (*(longlong *)(*(longlong *)(DAT_182d52ec0 + 0xb8) + 8) == 0) {
    if (*(int *)(DAT_182d52ec0 + 0xe0) == 0) {
      FUN_18035c820(DAT_182d52ec0);
    }
    ES3Internal_ES3TypeMgr__Init__060006ee(0);
  }
  if (*(int *)(DAT_182d52ec0 + 0xe0) == 0) {
    FUN_18035c820(DAT_182d52ec0);
  }
  lVar1 = *(longlong *)(*(longlong *)(DAT_182d52ec0 + 0xb8) + 8);
  if (lVar1 != 0) {
    cVar2 = FUN_180ebb4c0(lVar1,param_1,*(longlong *)(DAT_182d52ec0 + 0xb8) + 0x10,DAT_182d6a2c8);
    if (cVar2 == '\0') {
      return 0;
    }
    if (*(int *)(DAT_182d52ec0 + 0xe0) == 0) {
      FUN_18035c820(DAT_182d52ec0);
    }
    return *(undefined8 *)(*(longlong *)(DAT_182d52ec0 + 0xb8) + 0x10);
  }
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

