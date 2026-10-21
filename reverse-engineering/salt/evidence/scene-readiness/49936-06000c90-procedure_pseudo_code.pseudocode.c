// Ghidra pseudocode; not original source or compilable C.
// ev_0854c632ea8a613e90574a2b0ca483f431a615b3d2cf448074443c0b0cb861bd

longlong UnityEngine_SceneManagement_SceneManagerAPI__get_ActiveAPI__06000c90(void)

{
  longlong lVar1;
  
  if (cRam0000000182ec1988 == '\0') {
    FUN_1802f2810(0x182d650f8);
    LOCK();
    UNLOCK();
    cRam0000000182ec1988 = '\x01';
  }
  if (*(int *)(lRam0000000182d650f8 + 0xe0) == 0) {
    FUN_18035c820();
  }
  if (cRam0000000182ec19e3 == '\0') {
    FUN_1802f2810(0x182d650f8);
    LOCK();
    UNLOCK();
    cRam0000000182ec19e3 = '\x01';
  }
  if (*(int *)(lRam0000000182d650f8 + 0xe0) == 0) {
    FUN_18035c820();
  }
  lVar1 = *(longlong *)(*(longlong *)(lRam0000000182d650f8 + 0xb8) + 8);
  if (lVar1 == 0) {
    if (*(int *)(lRam0000000182d650f8 + 0xe0) == 0) {
      FUN_18035c820();
    }
    lVar1 = **(longlong **)(lRam0000000182d650f8 + 0xb8);
  }
  return lVar1;
}

