// Ghidra pseudocode; not original source or compilable C.
// ev_1940bc5c5b501851600672dc075047eac5bb168e1ac97a94113de19a8433cc18

void ExposureUnnoticed2_ObjectUI_FadeOutPanel_WaitSceneLoadTwiceStarter____ctor_g__OnSceneLoaded_2_0__06001b60
               (longlong param_1)

{
  int iVar1;
  undefined8 uVar2;
  
  if (cRam0000000182eb7d1e == '\0') {
    FUN_1802f2810(0x182d535b8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d645e0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d645b8);
    LOCK();
    UNLOCK();
    cRam0000000182eb7d1e = '\x01';
  }
  iVar1 = *(int *)(param_1 + 0x10) + 1;
  *(int *)(param_1 + 0x10) = iVar1;
  if (1 < iVar1) {
    uVar2 = FUN_1802c43a0(uRam0000000182d645e0);
    FUN_1800078e0(uVar2,param_1,uRam0000000182d645b8);
    if (*(int *)(lRam0000000182d535b8 + 0xe0) == 0) {
      FUN_18035c820();
    }
    FUN_181f58f50(uVar2,0);
    *(undefined1 *)(param_1 + 0x14) = 1;
  }
  return;
}

