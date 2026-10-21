// Ghidra pseudocode; not original source or compilable C.
// ev_7b51fb265082d2ba570ed27a56eba3142e695177628e4b442f6c630fde6b0437

undefined8 UnityEngine_SceneManagement_SceneManagerAPI__get_overrideAPI__06000c91(void)

{
  if (cRam0000000182ec1989 == '\0') {
    FUN_1802f2810(0x182d650f8);
    LOCK();
    UNLOCK();
    cRam0000000182ec1989 = '\x01';
  }
  if (*(int *)(lRam0000000182d650f8 + 0xe0) == 0) {
    FUN_18035c820(lRam0000000182d650f8);
  }
  return *(undefined8 *)(*(longlong *)(lRam0000000182d650f8 + 0xb8) + 8);
}

