// Ghidra pseudocode; not original source or compilable C.
// ev_99090fd5be891f8cbb8832fc3c2c34172a62f0059361a41955a271c9d8a6017e

void UnityEngine_SceneManagement_SceneManager__LoadSceneAsync__06000ca3
               (undefined8 param_1,undefined4 param_2)

{
  if (cRam0000000182ec19a4 == '\0') {
    FUN_1802f2810(&DAT_182d535b8);
    LOCK();
    UNLOCK();
    cRam0000000182ec19a4 = '\x01';
  }
  if (*(int *)(DAT_182d535b8 + 0xe0) == 0) {
    FUN_18035c820();
  }
  if (cRam0000000182ec19a5 == '\0') {
    FUN_1802f2810(&DAT_182d535b8);
    LOCK();
    UNLOCK();
    cRam0000000182ec19a5 = '\x01';
  }
  if (*(int *)(DAT_182d535b8 + 0xe0) == 0) {
    FUN_18035c820();
  }
  FUN_181f58bf0(param_1,0xffffffff,param_2,0,0);
  return;
}

