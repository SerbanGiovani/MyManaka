// Ghidra pseudocode; not original source or compilable C.
// ev_1a903a10662e30a5c9a5499c81ca3de4808f706dca86ef22c8def1662bdcdc52

void ExposureUnnoticed2_Object3D_ScenePlops_CommonDoor_CommonDoorController___OpenClose_b__25_0__06000b32
               (longlong param_1)

{
  longlong lVar1;
  code *pcVar2;
  undefined8 uVar3;
  
  lVar1 = *(longlong *)(param_1 + 0x30);
  if (lVar1 == 0) {
                    /* WARNING: Subroutine does not return */
    FUN_18031dad0();
  }
  pcVar2 = DAT_182ec3970;
  if ((DAT_182ec3970 == (code *)0x0) &&
     (pcVar2 = (code *)FUN_1802cf0c0("UnityEngine.Collider::set_enabled(System.Boolean)"),
     pcVar2 == (code *)0x0)) {
    uVar3 = FUN_1802ced60("UnityEngine.Collider::set_enabled(System.Boolean)");
                    /* WARNING: Subroutine does not return */
    FUN_1802cca90(uVar3,0);
  }
  DAT_182ec3970 = pcVar2;
                    /* WARNING: Could not recover jumptable at 0x000180608bed. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*DAT_182ec3970)(lVar1,1);
  return;
}

