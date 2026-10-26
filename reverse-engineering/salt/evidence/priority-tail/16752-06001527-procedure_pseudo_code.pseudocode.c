// Ghidra pseudocode; not original source or compilable C.
// ev_a7df93930b981dae83bea3691db3f033bcf6ed90a14f7d8450426102b46bc13e

ulonglong ExposureUnnoticed2_Scripts_InGame_GameStateFacade__GetCameraMoveX__06001527(void)

{
  float fVar1;
  float fVar2;
  int iVar3;
  longlong lVar4;
  undefined1 auVar5 [16];
  undefined1 auVar6 [16];
  undefined8 extraout_XMM0_Qb;
  
  if (DAT_182eb798a == '\0') {
    FUN_1802f2810(&DAT_182d58398);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d5aa88);
    LOCK();
    UNLOCK();
    DAT_182eb798a = '\x01';
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
    fVar2 = (float)ExposureUnnoticed2_Scripts_Base_InputManager__GetVector2__06001704(1,0);
    lVar4 = ExposureUnnoticed2_Master_Common_MCommon__get_Instance__0600133e(0);
    if (lVar4 != 0) {
      fVar1 = *(float *)(lVar4 + 0x28);
      auVar5._0_8_ = ExposureUnnoticed2_Scripts_InGame_GameStateFacade__GetOptionMouseXScale__06001555
                               (0);
      auVar5._8_8_ = extraout_XMM0_Qb;
      auVar6._4_12_ = auVar5._4_12_;
      auVar6._0_4_ = (float)auVar5._0_8_ * fVar1 * fVar2;
      return auVar6._0_8_;
    }
  }
  else {
    if (*(int *)(DAT_182d5aa88 + 0xe0) == 0) {
      FUN_18035c820();
    }
    fVar2 = (float)ExposureUnnoticed2_Scripts_Base_InputManager__GetVector2__06001704(1,0);
    lVar4 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x38);
    if (lVar4 != 0) {
      iVar3 = -1;
      if (*(char *)(lVar4 + 0x6a) == '\0') {
        iVar3 = 1;
      }
      return (ulonglong)
             (uint)((float)iVar3 * fVar2 * 0.15 *
                   (float)*(int *)(*(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x38) + 0x78)
                   );
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

