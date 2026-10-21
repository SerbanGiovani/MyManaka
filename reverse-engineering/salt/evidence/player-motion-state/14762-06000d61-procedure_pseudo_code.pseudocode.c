// Ghidra pseudocode; not original source or compilable C.
// ev_d40b806fab082772b8f3a53852b397f670494b5678b8ae7ce3a4760187c63d1d

void ExposureUnnoticed2_Object3D_Player_Scripts_PlayerController__OnGameOverEvent__06000d61
               (longlong param_1)

{
  longlong lVar1;
  code *pcVar2;
  undefined8 uVar3;
  
  if ((*(longlong *)(param_1 + 0x40) == 0) ||
     (lVar1 = *(longlong *)(*(longlong *)(param_1 + 0x40) + 0x10), lVar1 == 0)) {
                    /* WARNING: Subroutine does not return */
    FUN_18031dad0();
  }
  pcVar2 = DAT_182ebf2f0;
  if ((DAT_182ebf2f0 == (code *)0x0) &&
     (pcVar2 = (code *)FUN_1802cf0c0("UnityEngine.Animator::set_speed(System.Single)"),
     pcVar2 == (code *)0x0)) {
    uVar3 = FUN_1802ced60("UnityEngine.Animator::set_speed(System.Single)");
                    /* WARNING: Subroutine does not return */
    FUN_1802cca90(uVar3,0);
  }
  DAT_182ebf2f0 = pcVar2;
                    /* WARNING: Could not recover jumptable at 0x0001806455c7. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*DAT_182ebf2f0)(lVar1,0);
  return;
}

