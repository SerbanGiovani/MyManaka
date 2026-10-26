// Ghidra pseudocode; not original source or compilable C.
// ev_b26a3de2329aee8f1982e6ba482279f4ee85b65034a36d23aea4c086b26a43d3

undefined8 native_only_180436630__00000000(void)

{
  if (DAT_182eb5490 == '\0') {
    FUN_1802f2810(&DAT_182d59260);
    LOCK();
    UNLOCK();
    DAT_182eb5490 = '\x01';
  }
  return **(undefined8 **)(DAT_182d59260 + 0xb8);
}

