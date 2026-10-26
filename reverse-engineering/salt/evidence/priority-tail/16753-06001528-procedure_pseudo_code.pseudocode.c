// Ghidra pseudocode; not original source or compilable C.
// ev_dd73ccbe4853efd56a6e49134bdd247c7b3da8516814a3fe89227aff8dc9788f

float ExposureUnnoticed2_Scripts_InGame_GameStateFacade__GetCameraMoveY__06001528(void)

{
  float fVar1;
  int iVar2;
  float extraout_var;
  longlong lVar3;
  float extraout_var_00;
  
  if (DAT_182eb798b == '\0') {
    FUN_1802f2810(&DAT_182d58398);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d5aa88);
    LOCK();
    UNLOCK();
    DAT_182eb798b = '\x01';
  }
  if (*(int *)(DAT_182d5aa88 + 0xe0) == 0) {
    FUN_18035c820();
  }
  if (DAT_182eb54a5 == '\0') {
    FUN_1802f2810(&DAT_182d5aa88);
    LOCK();
    UNLOCK();
    DAT_182eb54a5 = '\x01';
  }
  if (*(int *)(DAT_182d5aa88 + 0xe0) == 0) {
    FUN_18035c820();
  }
  if (*(char *)(*(longlong *)(DAT_182d5aa88 + 0xb8) + 8) == '\0') {
    if (*(int *)(DAT_182d5aa88 + 0xe0) == 0) {
      FUN_18035c820();
    }
    ExposureUnnoticed2_Scripts_Base_InputManager__GetVector2__06001704(1,0);
    lVar3 = ExposureUnnoticed2_Master_Common_MCommon__get_Instance__0600133e(0);
    if (lVar3 != 0) {
      fVar1 = *(float *)(lVar3 + 0x28);
      if (DAT_182eb79b9 == '\0') {
        FUN_1802f2810(&DAT_182d58398);
        LOCK();
        UNLOCK();
        DAT_182eb79b9 = '\x01';
      }
      lVar3 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x38);
      if (lVar3 != 0) {
        iVar2 = -*(int *)(lVar3 + 0x70);
        if (*(char *)(lVar3 + 0x69) == '\0') {
          iVar2 = *(int *)(lVar3 + 0x70);
        }
        return (float)iVar2 * 0.01 * extraout_var * fVar1;
      }
    }
  }
  else {
    if (*(int *)(DAT_182d5aa88 + 0xe0) == 0) {
      FUN_18035c820();
    }
    ExposureUnnoticed2_Scripts_Base_InputManager__GetVector2__06001704(1,0);
    lVar3 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x38);
    if (lVar3 != 0) {
      iVar2 = -1;
      if (*(char *)(lVar3 + 0x6b) == '\0') {
        iVar2 = 1;
      }
      return (float)iVar2 * extraout_var_00 * 0.15 *
             (float)*(int *)(*(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x38) + 0x78);
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

