// Ghidra pseudocode; not original source or compilable C.
// ev_be4877edccb26b900d607f254543af5a0250bdde80bbfa9d88d65294b0105af5

void UnityEngine_SceneManagement_SceneManager__Internal_SceneLoaded__06000ca5
               (undefined4 param_1,undefined4 param_2)

{
  longlong lVar1;
  
  if (cRam0000000182ec19a6 == '\0') {
    FUN_1802f2810(&DAT_182d535b8);
    LOCK();
    UNLOCK();
    cRam0000000182ec19a6 = '\x01';
  }
  if (*(int *)(DAT_182d535b8 + 0xe0) == 0) {
    FUN_18035c820();
  }
  if (*(longlong *)(*(longlong *)(DAT_182d535b8 + 0xb8) + 8) != 0) {
    if (*(int *)(DAT_182d535b8 + 0xe0) == 0) {
      FUN_18035c820();
    }
    lVar1 = *(longlong *)(*(longlong *)(DAT_182d535b8 + 0xb8) + 8);
    if (lVar1 == 0) {
                    /* WARNING: Subroutine does not return */
      FUN_18031dad0();
    }
    (**(code **)(lVar1 + 0x18))
              (*(undefined8 *)(lVar1 + 0x40),param_1,param_2,*(undefined8 *)(lVar1 + 0x28));
  }
  return;
}

