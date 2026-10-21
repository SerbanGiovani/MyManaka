// Ghidra pseudocode; not original source or compilable C.
// ev_7f0ba8527bae92db32426cab2d2cbed7ab4c684d10f40abdcbfd5ed2e58c600b

void ExposureUnnoticed2_Object3D_NPC_Script_NpcFoundStrangerState__OnExit__06001075
               (longlong param_1)

{
  longlong lVar1;
  
  if (((*(longlong *)(param_1 + 0x20) != 0) &&
      (lVar1 = *(longlong *)(*(longlong *)(param_1 + 0x20) + 0x60), lVar1 != 0)) &&
     (lVar1 = *(longlong *)(lVar1 + 0x10), lVar1 != 0)) {
    *(undefined4 *)(lVar1 + 0x14) = 0;
    *(undefined4 *)(lVar1 + 0x18) = 0x78;
    if ((*(longlong *)(param_1 + 0x20) != 0) &&
       (lVar1 = *(longlong *)(*(longlong *)(param_1 + 0x20) + 0xa0), lVar1 != 0)) {
      if (DAT_182eb7732 == '\0') {
        FUN_1802f2810(&DAT_182d59ea8,0,0);
        LOCK();
        UNLOCK();
        DAT_182eb7732 = '\x01';
      }
      lVar1 = *(longlong *)(lVar1 + 0x18);
      if (*(int *)(DAT_182d59ea8 + 0xe0) == 0) {
        FUN_18035c820(DAT_182d59ea8);
      }
      if (lVar1 != 0) {
        FUN_181eea680(lVar1,*(undefined4 *)(*(longlong *)(DAT_182d59ea8 + 0xb8) + 0x24),0,0);
        return;
      }
                    /* WARNING: Subroutine does not return */
      FUN_18031dad0();
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

