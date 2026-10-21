// Ghidra pseudocode; not original source or compilable C.
// ev_334cc22f5c1bc259f8a5f1d534207b4752118bb2940c577377afb84c9779d100

void ExposureUnnoticed2_Object3D_InteractArea_InteractAreaController__OnDisable__06001185
               (longlong param_1)

{
  undefined4 uVar1;
  
  if (cRam0000000182eb77e2 == '\0') {
    FUN_1802f2810(0x182d5ab80);
    LOCK();
    UNLOCK();
    cRam0000000182eb77e2 = '\x01';
  }
  if (*(char *)(param_1 + 0x31) != '\0') {
    uVar1 = *(undefined4 *)(param_1 + 0x20);
    *(undefined1 *)(param_1 + 0x31) = 0;
    if (*(int *)(lRam0000000182d5ab80 + 0xe0) == 0) {
      FUN_18035c820();
    }
    ExposureUnnoticed2_Scripts_Base_InteractManager__Unregister__06001798(uVar1,param_1,0);
  }
  return;
}

