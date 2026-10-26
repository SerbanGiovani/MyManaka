// Ghidra pseudocode; not original source or compilable C.
// ev_db48080a4832e9dbd55ab8418e5dd76be68eb710e8893243968ed67b09363fa8

void ExposureUnnoticed2_Scripts_Base_SaveRapper__AfterProcess__060017b9(void)

{
  if (cRam0000000182eb7ad9 == '\0') {
    FUN_1802f2810(&DAT_182d60278);
    LOCK();
    UNLOCK();
    cRam0000000182eb7ad9 = '\x01';
  }
  if (*(int *)(DAT_182d60278 + 0xe0) == 0) {
    FUN_18035c820(DAT_182d60278);
  }
  *(undefined1 *)(*(longlong *)(DAT_182d60278 + 0xb8) + 4) = 0;
  return;
}

