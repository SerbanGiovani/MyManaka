// Ghidra pseudocode; not original source or compilable C.
// ev_3d83ce17054ef833e251f729b18fe1fb8e4bf7e8454090ae7afcca1c816cae88

undefined1 native_only_180477d40__00000000(void)

{
  if (DAT_182eb54a5 == '\0') {
    FUN_1802f2810(&DAT_182d5aa88);
    LOCK();
    UNLOCK();
    DAT_182eb54a5 = '\x01';
  }
  if (*(int *)(DAT_182d5aa88 + 0xe0) == 0) {
    FUN_18035c820(DAT_182d5aa88);
  }
  return *(undefined1 *)(*(longlong *)(DAT_182d5aa88 + 0xb8) + 8);
}

