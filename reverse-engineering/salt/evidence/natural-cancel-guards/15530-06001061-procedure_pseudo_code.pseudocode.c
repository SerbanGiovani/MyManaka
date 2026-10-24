// Ghidra pseudocode; not original source or compilable C.
// ev_846f3796064a0e98eaa3e1a2e3e3f6ecbaf340d07eb324637129aba2bbeb94e3

void ExposureUnnoticed2_Object3D_NPC_Script_NpcController__OnGameOver__06001061(longlong param_1)

{
  longlong lVar1;
  code *pcVar2;
  undefined8 uVar3;
  
  if ((*(longlong *)(param_1 + 0x30) == 0) ||
     (lVar1 = *(longlong *)(*(longlong *)(param_1 + 0x30) + 0x90), lVar1 == 0)) {
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
                    /* WARNING: Could not recover jumptable at 0x000180429f7a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*DAT_182ebf2f0)(lVar1,0);
  return;
}

