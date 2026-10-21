// Ghidra pseudocode; not original source or compilable C.
// ev_7b5f9b2317b2f106ba77a1ae42d3ca3af6242e32d2a1f944c13bda42e903b720

void UnityEngine_SceneManagement_SceneManager__LoadSceneAsync__06000ca4
               (undefined8 param_1,undefined8 param_2)

{
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

