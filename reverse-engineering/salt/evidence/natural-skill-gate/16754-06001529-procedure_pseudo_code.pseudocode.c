// Ghidra pseudocode; not original source or compilable C.
// ev_b0fe757ce7e459d59d17030c228b36664eb06b56fbbcea2f4a46165ba881c2c4

void ExposureUnnoticed2_Scripts_InGame_GameStateFacade__GetSkillLevel__06001529(undefined4 param_1)

{
  longlong lVar1;
  
  if (DAT_182eb798c == '\0') {
    FUN_1802f2810(&DAT_182d5e088);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d58398);
    LOCK();
    UNLOCK();
    DAT_182eb798c = '\x01';
  }
  lVar1 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
  if ((lVar1 != 0) && (lVar1 = *(longlong *)(lVar1 + 0x1f8), lVar1 != 0)) {
    FUN_180e71cd0(lVar1,param_1,DAT_182d5e088);
    return;
  }
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

