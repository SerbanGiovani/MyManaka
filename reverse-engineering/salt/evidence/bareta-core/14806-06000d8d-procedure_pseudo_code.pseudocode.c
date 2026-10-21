// Ghidra pseudocode; not original source or compilable C.
// ev_af3ef93a5e1c920cd2fcacace01d3d85bdd861bb070ed6fa74fc21e9d4ac6117

undefined8
ExposureUnnoticed2_Object3D_Player_Scripts_PlayerFacade__IsIgnoreBaretaState__06000d8d(void)

{
  longlong lVar1;
  char cVar2;
  int iVar3;
  undefined8 uVar4;
  
  cVar2 = ExposureUnnoticed2_Scripts_InGame_GameStateFacade__IsActivePassiveSkill__06001525(0x15,0);
  if (cVar2 != '\0') {
    return 1;
  }
  if (DAT_182eb7988 == '\0') {
    FUN_1802f2810(&DAT_182d5dd30);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d58398);
    LOCK();
    UNLOCK();
    DAT_182eb7988 = '\x01';
  }
  iVar3 = ExposureUnnoticed2_Scripts_InGame_GameStateFacade__GetSkillLevel__06001529(0x16,0);
  if (iVar3 < 1) {
    return 0;
  }
  lVar1 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
  if ((lVar1 != 0) && (lVar1 = *(longlong *)(lVar1 + 0x1d0), lVar1 != 0)) {
    uVar4 = FUN_180e6c190(lVar1,0x16,DAT_182d5dd30);
    return uVar4;
  }
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

