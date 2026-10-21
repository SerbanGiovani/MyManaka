// Ghidra pseudocode; not original source or compilable C.
// ev_64434762095790de2577841fe659cac8fd230f45effd5a1f990137d213e6852e

undefined8
UnityEngine_SceneManagement_SceneManager__LoadSceneAsyncNameIndexInternal__06000c99
          (undefined8 param_1,undefined4 param_2,undefined8 param_3,undefined1 param_4)

{
  longlong *plVar1;
  undefined8 uVar2;
  
  if (cRam0000000182ec199a == '\0') {
    FUN_1802f2810(0x182d650f8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d535b8);
    LOCK();
    UNLOCK();
    cRam0000000182ec199a = '\x01';
  }
  if (*(int *)(DAT_182d535b8 + 0xe0) == 0) {
    FUN_18035c820(DAT_182d535b8);
  }
  if (**(char **)(DAT_182d535b8 + 0xb8) == '\0') {
    uVar2 = 0;
  }
  else {
    if (*(int *)(lRam0000000182d650f8 + 0xe0) == 0) {
      FUN_18035c820();
    }
    plVar1 = (longlong *)FUN_181f58840(0);
    if (plVar1 == (longlong *)0x0) {
                    /* WARNING: Subroutine does not return */
      FUN_18031dad0();
    }
    uVar2 = (**(code **)(*plVar1 + 0x178))
                      (plVar1,param_1,param_2,param_3,param_4,*(undefined8 *)(*plVar1 + 0x180));
  }
  return uVar2;
}

