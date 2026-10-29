// Ghidra pseudocode; not original source or compilable C.
// ev_e7c574d8d8dd4d10dbffa99b328c7dcb6b2bb96f896bac6f8b6dece6cfaa3fcc

undefined8 Native_NpcRestore_FindElevator(void)

{
  if (DAT_182eb5490 == '\0') {
    FUN_1802f2810(&DAT_182d59260);
    LOCK();
    UNLOCK();
    DAT_182eb5490 = '\x01';
  }
  return **(undefined8 **)(DAT_182d59260 + 0xb8);
}

