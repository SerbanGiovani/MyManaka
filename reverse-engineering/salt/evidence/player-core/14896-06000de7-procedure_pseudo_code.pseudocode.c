// Ghidra pseudocode; not original source or compilable C.
// ev_ba6d519892576bade2850b98bafd4fe07c8fb835bbf1880d5e55fdc75b2ecf84

void ExposureUnnoticed2_Object3D_Player_Scripts_PlayerLocomotion__OnWarp__06000de7(longlong param_1)

{
  undefined4 uVar1;
  longlong lVar2;
  
  *(undefined4 *)(param_1 + 0x20) = 0;
  if (*(longlong *)(param_1 + 0x28) != 0) {
    *(undefined4 *)(*(longlong *)(param_1 + 0x28) + 0x10) = 0;
    if (*(longlong *)(param_1 + 0x78) != 0) {
      lVar2 = *(longlong *)(*(longlong *)(param_1 + 0x78) + 0x60);
      if (DAT_182eb5480 == '\0') {
        FUN_1802f2810(&DAT_182d522a8);
        LOCK();
        UNLOCK();
        DAT_182eb5480 = '\x01';
      }
      uVar1 = *(undefined4 *)(*(undefined8 **)(DAT_182d522a8 + 0xb8) + 1);
      if (lVar2 != 0) {
        *(undefined8 *)(lVar2 + 400) = **(undefined8 **)(DAT_182d522a8 + 0xb8);
        *(undefined4 *)(lVar2 + 0x198) = uVar1;
        return;
      }
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

