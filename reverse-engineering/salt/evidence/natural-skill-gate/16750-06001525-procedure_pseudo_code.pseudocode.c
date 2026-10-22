// Ghidra pseudocode; not original source or compilable C.
// ev_68da8a9f38c8eae6d7e8eeb944a32d4a341e1b0c7213a1b781924aeebc94e6f2

ulonglong ExposureUnnoticed2_Scripts_InGame_GameStateFacade__IsActivePassiveSkill__06001525
                    (undefined4 param_1)

{
  longlong lVar1;
  ulonglong uVar2;
  
  if (DAT_182eb7988 == '\0') {
    FUN_1802f2810(&DAT_182d5dd30);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d58398);
    LOCK();
    UNLOCK();
    DAT_182eb7988 = '\x01';
  }
  uVar2 = ExposureUnnoticed2_Scripts_InGame_GameStateFacade__GetSkillLevel__06001529(param_1,0);
  if ((int)uVar2 < 1) {
    return uVar2 & 0xffffffffffffff00;
  }
  lVar1 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
  if ((lVar1 != 0) && (lVar1 = *(longlong *)(lVar1 + 0x1d0), lVar1 != 0)) {
    uVar2 = FUN_180e6c190(lVar1,param_1,DAT_182d5dd30);
    return uVar2;
  }
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

