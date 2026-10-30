// Ghidra pseudocode; not original source or compilable C.
// ev_43cf2b16cc685b4f5d8fdaf75edf157bef5e134954a20a33a3b28d345e79bae2

void ExposureUnnoticed2_ObjectUI_PcMenuPanel_SkillSwitchPanel_SkillSwitchItemView__OnChangeToggle__060018a0
               (longlong param_1)

{
  longlong lVar1;
  
  if (cRam0000000182eb7b88 == '\0') {
    FUN_1802f2810(&DAT_182d58378);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d5aa70);
    LOCK();
    UNLOCK();
    cRam0000000182eb7b88 = '\x01';
  }
  if ((*(longlong *)(param_1 + 0x38) != 0) && (*(longlong *)(param_1 + 0x28) != 0)) {
    ExposureUnnoticed2_Scripts_InGame_GameStateFacade__ChangeActivePassiveSkill__06001526
              (*(undefined4 *)(*(longlong *)(param_1 + 0x38) + 0x3c),
               *(undefined1 *)(*(longlong *)(param_1 + 0x28) + 0x120),0);
    if (*(char *)(param_1 + 0x50) == '\0') {
      if (**(longlong **)(DAT_182d5aa70 + 0xb8) == 0) goto code_r0x0001804cee2a;
      ExposureUnnoticed2_Scripts_Sound_UiSoundPlayer__PlayOneShotAudioData__06001404
                (**(longlong **)(DAT_182d5aa70 + 0xb8),0x31,0xbf800000,0,0);
    }
    if (*(longlong *)(param_1 + 0x38) != 0) {
      if (*(int *)(*(longlong *)(param_1 + 0x38) + 0x3c) == 0xf) {
        if (DAT_182eb5496 == '\0') {
          FUN_1802f2810(&DAT_182d5a8f0);
          LOCK();
          UNLOCK();
          DAT_182eb5496 = '\x01';
        }
        if (**(longlong **)(DAT_182d5a8f0 + 0xb8) == 0) goto code_r0x0001804cee2a;
        ExposureUnnoticed2_Scripts_InGame_VisibilityFogController__UpdateEyeMask__0600168e
                  (**(longlong **)(DAT_182d5a8f0 + 0xb8),0);
      }
      if (*(longlong *)(param_1 + 0x38) != 0) {
        if (*(int *)(*(longlong *)(param_1 + 0x38) + 0x3c) == 0x18) {
          if (((**(longlong **)(DAT_182d58378 + 0xb8) == 0) ||
              (lVar1 = *(longlong *)(**(longlong **)(DAT_182d58378 + 0xb8) + 0x40), lVar1 == 0)) ||
             (lVar1 = *(longlong *)(lVar1 + 0x1b8), lVar1 == 0)) goto code_r0x0001804cee2a;
          ExposureUnnoticed2_Object3D_Player_Scripts_PlayerCosplayManager__CalcCostumeEffect__06000d7a
                    (lVar1,0);
        }
        lVar1 = *(longlong *)(param_1 + 0x48);
        if (lVar1 != 0) {
                    /* WARNING: Could not recover jumptable at 0x0001804cee21. Too many branches */
                    /* WARNING: Treating indirect jump as call */
          (**(code **)(lVar1 + 0x18))(*(undefined8 *)(lVar1 + 0x40),*(undefined8 *)(lVar1 + 0x28));
          return;
        }
        return;
      }
    }
  }
code_r0x0001804cee2a:
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

