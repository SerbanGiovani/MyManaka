// Ghidra pseudocode; not original source or compilable C.
// ev_d96c0beb5ac1970b1368f173dffc1b94bf075e976750f259198aeebf50686d7a

undefined8 native_only_180478000__00000000(void)

{
  if (DAT_182eb549e == '\0') {
    FUN_1802f2810(&DAT_182d5bfd0);
    LOCK();
    UNLOCK();
    DAT_182eb549e = '\x01';
  }
  return **(undefined8 **)(DAT_182d5bfd0 + 0xb8);
}

