// Ghidra pseudocode; not original source or compilable C.
// ev_2e067eb4d938639fdc6414965f398db1fd1199b07b08969d697742e0dca8fc2d

void ExposureUnnoticed2_Scripts_Base_SystemManager___cctor__060017d5(void)

{
  if (cRam0000000182eb7aea == '\0') {
    FUN_1802f2810(0x182d5bfa0);
    LOCK();
    UNLOCK();
    cRam0000000182eb7aea = '\x01';
  }
  **(undefined1 **)(lRam0000000182d5bfa0 + 0xb8) = 0;
  *(undefined1 *)(*(longlong *)(lRam0000000182d5bfa0 + 0xb8) + 1) = 1;
  *(undefined1 *)(*(longlong *)(lRam0000000182d5bfa0 + 0xb8) + 2) = 1;
  *(undefined1 *)(*(longlong *)(lRam0000000182d5bfa0 + 0xb8) + 3) = 0;
  return;
}

