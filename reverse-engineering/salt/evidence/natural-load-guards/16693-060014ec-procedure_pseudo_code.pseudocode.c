// Ghidra pseudocode; not original source or compilable C.
// ev_9c7cc3164f90215087dbaa4bb832818994cb703e51df88bb7242007a3b599e16

void ExposureUnnoticed2_Scripts_InGame_DebugController___cctor__060014ec(void)

{
  if (cRam0000000182eb7961 == '\0') {
    FUN_1802f2810(&DAT_182d59ac8);
    LOCK();
    UNLOCK();
    cRam0000000182eb7961 = '\x01';
  }
  **(undefined1 **)(DAT_182d59ac8 + 0xb8) = 0;
  *(undefined4 *)(*(longlong *)(DAT_182d59ac8 + 0xb8) + 4) = 0x3f800000;
  *(undefined1 *)(*(longlong *)(DAT_182d59ac8 + 0xb8) + 0xb) = 1;
  return;
}

