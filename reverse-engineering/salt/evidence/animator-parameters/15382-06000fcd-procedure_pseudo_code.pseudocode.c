// Ghidra pseudocode; not original source or compilable C.
// ev_d726d1ee403cbd204955ddbe0f5a8f851572ded13b1599c14318612f6d74751e

void ExposureUnnoticed2_Object3D_NPC_Script_NpcAnimationManager__SetFoundStranger__06000fcd
               (longlong param_1,undefined1 param_2)

{
  longlong lVar1;
  
  if (DAT_182eb7732 == '\0') {
    FUN_1802f2810(&DAT_182d59ea8);
    LOCK();
    UNLOCK();
    DAT_182eb7732 = '\x01';
  }
  lVar1 = *(longlong *)(param_1 + 0x18);
  if (*(int *)(DAT_182d59ea8 + 0xe0) == 0) {
    FUN_18035c820(DAT_182d59ea8);
  }
  if (lVar1 != 0) {
    FUN_181eea680(lVar1,*(undefined4 *)(*(longlong *)(DAT_182d59ea8 + 0xb8) + 0x24),param_2,0);
    return;
  }
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

