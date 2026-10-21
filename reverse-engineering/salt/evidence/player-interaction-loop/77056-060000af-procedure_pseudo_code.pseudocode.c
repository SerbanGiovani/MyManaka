// Ghidra pseudocode; not original source or compilable C.
// ev_8f9b592ef11e500427e10183902650a2d52da70df95ccf4b3f21ebd392a55d12

void UnityEngine_CharacterController__Move_Injected__060000af(undefined8 param_1,undefined8 param_2)

{
  code *pcVar1;
  undefined8 uVar2;
  
  pcVar1 = pcRam0000000182ec39e8;
  if ((pcRam0000000182ec39e8 == (code *)0x0) &&
     (pcVar1 = (code *)FUN_1802cf0c0(
                                    "UnityEngine.CharacterController::Move_Injected(UnityEngine.Vector3&)"
                                    ), pcVar1 == (code *)0x0)) {
    uVar2 = FUN_1802ced60("UnityEngine.CharacterController::Move_Injected(UnityEngine.Vector3&)");
                    /* WARNING: Subroutine does not return */
    FUN_1802cca90(uVar2,0);
  }
  pcRam0000000182ec39e8 = pcVar1;
                    /* WARNING: Could not recover jumptable at 0x000181fb9554. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*pcRam0000000182ec39e8)(param_1,param_2);
  return;
}

