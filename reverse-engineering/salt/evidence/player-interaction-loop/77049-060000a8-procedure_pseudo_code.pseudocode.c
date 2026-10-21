// Ghidra pseudocode; not original source or compilable C.
// ev_d5af181cf2287157979e1eda92cde598a110dbf2b42f8e4373f73ebfd35c1bb5

void UnityEngine_CharacterController__Move__060000a8(undefined8 param_1,undefined8 param_2)

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
  (*pcRam0000000182ec39e8)(param_1,param_2);
  return;
}

