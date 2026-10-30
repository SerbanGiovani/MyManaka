// Ghidra pseudocode; not original source or compilable C.
// ev_a961f15995d41f769bbf20d33d2a49abe18e054bbc12196ab2774d98e9661d8d

undefined8
ExposureUnnoticed2_Object3D_Player_Scripts_Other_BodyPaintController__GetMaxDeltaAdd__06000e5c
          (longlong param_1)

{
  undefined8 uVar1;
  int aiStackX_8 [8];
  
  if (cRam0000000182eb7659 == '\0') {
    FUN_1802f2810(0x182d58310);
    LOCK();
    UNLOCK();
    cRam0000000182eb7659 = '\x01';
  }
  aiStackX_8[0] = *(int *)(param_1 + 0x20);
  if ((aiStackX_8[0] == 0) || (aiStackX_8[0] == 1)) {
    return 0x40400000;
  }
  if (aiStackX_8[0] == 2) {
    return 0x3cf5c28f;
  }
  if (aiStackX_8[0] != 3) {
    if (aiStackX_8[0] == 4) {
      return 0x3e99999a;
    }
    uVar1 = il2cpp_value_box(uRam0000000182d58310,aiStackX_8);
                    /* WARNING: Subroutine does not return */
    _PrivateImplementationDetails___ThrowSwitchExpressionException__06001e66(uVar1,0);
  }
  return 0x3dcccccd;
}

