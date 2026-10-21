// Ghidra pseudocode; not original source or compilable C.
// ev_99fefbb425e6170192e48de996b1ee6acb2312f72a3ac6e0d21d74db435d7e56

void ExposureUnnoticed2_Scripts_Base_SystemManager___cctor__060017d5(void)

{
  if (cRam0000000182eb7aea == '\0') {
    FUN_1802f2810(&DAT_182d5bfa0);
    LOCK();
    UNLOCK();
    cRam0000000182eb7aea = '\x01';
  }
  **(undefined1 **)(DAT_182d5bfa0 + 0xb8) = 0;
  *(undefined1 *)(*(longlong *)(DAT_182d5bfa0 + 0xb8) + 1) = 1;
  *(undefined1 *)(*(longlong *)(DAT_182d5bfa0 + 0xb8) + 2) = 1;
  *(undefined1 *)(*(longlong *)(DAT_182d5bfa0 + 0xb8) + 3) = 0;
  return;
}

