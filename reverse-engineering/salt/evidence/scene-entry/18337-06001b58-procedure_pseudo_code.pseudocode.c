// Ghidra pseudocode; not original source or compilable C.
// ev_73b34317d3c50b9660c059787c3d99ba6af0907af9e80e84ac02b638b3a7e3bb

void ExposureUnnoticed2_ObjectUI_FadeOutPanel_WaitSceneLoadStarter____ctor_g__OnSceneLoaded_1_0__06001b58
               (longlong param_1)

{
  undefined8 uVar1;
  
  if (cRam0000000182eb7d1a == '\0') {
    FUN_1802f2810(0x182d535b8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d645e0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d645d8);
    LOCK();
    UNLOCK();
    cRam0000000182eb7d1a = '\x01';
  }
  uVar1 = FUN_1802c43a0(uRam0000000182d645e0);
  FUN_1800078e0(uVar1,param_1,uRam0000000182d645d8);
  if (*(int *)(lRam0000000182d535b8 + 0xe0) == 0) {
    FUN_18035c820();
  }
  FUN_181f58f50(uVar1,0);
  *(undefined1 *)(param_1 + 0x10) = 1;
  return;
}

