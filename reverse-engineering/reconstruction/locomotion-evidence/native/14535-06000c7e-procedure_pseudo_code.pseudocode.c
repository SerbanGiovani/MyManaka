// Ghidra pseudocode; not original source or compilable C.
// ev_c1c60d813207c13e06bb90ba39713df7276ae71d0fe777b2064ab6a19329aba1

void ExposureUnnoticed2_Object3D_Player_Scripts_PlayerAnimationManager__SetStrafe__06000c7e
               (longlong param_1,undefined1 param_2,uint param_3,float param_4,float param_5)

{
  longlong lVar1;
  
  if (cRam0000000182eb8390 == '\0') {
    FUN_1802f2810(0x182d6f340);
    LOCK();
    UNLOCK();
    cRam0000000182eb8390 = '\x01';
  }
  lVar1 = *(longlong *)(param_1 + 0x30);
  if (*(int *)(lRam0000000182d6f340 + 0xe0) == 0) {
    FUN_18035c820(lRam0000000182d6f340);
  }
  if (lVar1 != 0) {
    FUN_181eea680(lVar1,*(undefined4 *)(*(longlong *)(lRam0000000182d6f340 + 0xb8) + 0xc),param_2,0)
    ;
    if (*(longlong *)(param_1 + 0x88) != 0) {
      *(float *)(*(longlong *)(param_1 + 0x88) + 0x1c) = (float)((param_3 & 0xff) + 1) * param_4;
      if (*(longlong *)(param_1 + 0x90) != 0) {
        *(float *)(*(longlong *)(param_1 + 0x90) + 0x1c) = (float)((param_3 & 0xff) + 1) * param_5;
        return;
      }
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

