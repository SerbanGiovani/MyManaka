// Ghidra pseudocode; not original source or compilable C.
// ev_0dd2dd972582a2a38af72afa17a970ec9db27624c4bdc46293b381bdaf6eaf49

void ExposureUnnoticed2_Scripts_InGame_GameStateFacade__AchieveMission__06001559(undefined4 param_1)

{
  longlong lVar1;
  int iVar2;
  
  if (cRam0000000182eb79bc == '\0') {
    FUN_1802f2810(&DAT_182d5db60);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d5db58);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d5db50);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5e238);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d58398);
    LOCK();
    UNLOCK();
    cRam0000000182eb79bc = '\x01';
  }
  lVar1 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
  if ((lVar1 != 0) && (lVar1 = *(longlong *)(lVar1 + 0xf0), lVar1 != 0)) {
    iVar2 = FUN_180e44350(lVar1,param_1,
                          *(undefined8 *)
                           (*(longlong *)(*(longlong *)(DAT_182d5db58 + 0x20) + 0xc0) + 0xf8));
    if (iVar2 < 0) {
      lVar1 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
      if ((lVar1 == 0) || (lVar1 = *(longlong *)(lVar1 + 0xf0), lVar1 == 0))
      goto code_r0x000180491d61;
      FUN_180e4d6f0(lVar1,param_1,0,2,
                    *(undefined8 *)
                     (*(longlong *)(*(longlong *)(DAT_182d5db60 + 0x20) + 0xc0) + 0x100));
    }
    lVar1 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
    if ((lVar1 != 0) && (lVar1 = *(longlong *)(lVar1 + 0xf0), lVar1 != 0)) {
      iVar2 = FUN_180006390(lVar1,param_1);
      FUN_180e4d6f0(lVar1,param_1,iVar2 + 1,CONCAT71((uint7)(uint3)((uint)iVar2 >> 8),1),
                    *(undefined8 *)
                     (*(longlong *)(*(longlong *)(lRam0000000182d5e238 + 0x20) + 0xc0) + 0x100));
      return;
    }
  }
code_r0x000180491d61:
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

