// Ghidra pseudocode; not original source or compilable C.
// ev_517b8e827f1b539d60177e8e1f7366953b6cfde1e9fe14de7e4804dcacfd8e50

void ExposureUnnoticed2_Scripts_InGame_GameStateFacade__RiseSkillLevel__0600152a(undefined4 param_1)

{
  int iVar1;
  longlong lVar2;
  
  if (cRam0000000182eb798d == '\0') {
    FUN_1802f2810(0x182d5dd28);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d5e088);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5dd10);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d58398);
    LOCK();
    UNLOCK();
    cRam0000000182eb798d = '\x01';
  }
  lVar2 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
  if ((lVar2 != 0) && (lVar2 = *(longlong *)(lVar2 + 0x1f8), lVar2 != 0)) {
    iVar1 = FUN_180e71cd0(lVar2,param_1,DAT_182d5e088);
    FUN_180e72490(lVar2,param_1,iVar1 + 1,CONCAT71((uint7)(uint3)((uint)iVar1 >> 8),1),
                  *(undefined8 *)
                   (*(longlong *)(*(longlong *)(lRam0000000182d5dd10 + 0x20) + 0xc0) + 0x100));
    lVar2 = ExposureUnnoticed2_Master_Skill_MSkill__Get__06001232(param_1,0);
    if (lVar2 != 0) {
      if (*(char *)(lVar2 + 0x38) != '\0') {
        lVar2 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
        if ((lVar2 == 0) || (lVar2 = *(longlong *)(lVar2 + 0x1d0), lVar2 == 0))
        goto code_r0x00018048e331;
        iVar1 = FUN_180e6c800(lVar2,param_1,
                              *(undefined8 *)
                               (*(longlong *)(*(longlong *)(lRam0000000182d5dd28 + 0x20) + 0xc0) +
                               0xf8));
        if (iVar1 < 0) {
          ExposureUnnoticed2_Scripts_InGame_GameStateFacade__ChangeActivePassiveSkill__06001526
                    (param_1,1,0);
        }
      }
      return;
    }
  }
code_r0x00018048e331:
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

