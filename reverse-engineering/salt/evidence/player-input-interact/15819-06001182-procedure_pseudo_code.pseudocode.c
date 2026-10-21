// Ghidra pseudocode; not original source or compilable C.
// ev_b3e9f80780e303591df45e3ece8afe0f1514a7b45f1136f58be8b9e38cebcc1b

void ExposureUnnoticed2_Object3D_InteractArea_InteractAreaController__Dispose__06001182
               (longlong param_1)

{
  undefined8 uVar1;
  
  if (DAT_182eb77df == '\0') {
    FUN_1802f2810(&DAT_182d58370);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d5abb0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d5ab88);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d58338);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d583a0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d5aba0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d5ab98);
    LOCK();
    UNLOCK();
    DAT_182eb77df = '\x01';
  }
  if (*(char *)(param_1 + 0x79) == '\0') {
    *(undefined1 *)(param_1 + 0x79) = 1;
    uVar1 = FUN_1802c43a0(DAT_182d5abb0);
    FUN_180665bb0(uVar1,param_1,DAT_182d5ab98,0);
    if (*(int *)(DAT_182d583a0 + 0xe0) == 0) {
      FUN_18035c820();
    }
    FUN_180993960(uVar1,DAT_182d5ab88);
    uVar1 = FUN_1802c43a0(DAT_182d58370);
    FUN_180665bb0(uVar1,param_1,DAT_182d5aba0,0);
    FUN_180993960(uVar1,DAT_182d58338);
  }
  return;
}

