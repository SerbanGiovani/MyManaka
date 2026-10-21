// Ghidra pseudocode; not original source or compilable C.
// ev_e90b13cd5cc86cf24705dec52416b2980ed50b63302ffe68a9fd9ae2ce6beb75

void ExposureUnnoticed2_Object3D_Player_Scripts_Other_PlayerMoveCalculator__OnWarp__06000ec4
               (longlong param_1)

{
  longlong lVar1;
  code *pcVar2;
  undefined8 uVar3;
  undefined8 uStack_18;
  undefined4 uStack_10;
  
  if ((*(longlong *)(param_1 + 0x20) == 0) ||
     (lVar1 = *(longlong *)(*(longlong *)(param_1 + 0x20) + 0x18), lVar1 == 0)) {
                    /* WARNING: Subroutine does not return */
    FUN_18031dad0();
  }
  uStack_18 = 0;
  uStack_10 = 0;
  pcVar2 = DAT_182ec1698;
  if ((DAT_182ec1698 == (code *)0x0) &&
     (pcVar2 = (code *)FUN_1802cf0c0(
                                    "UnityEngine.Transform::get_position_Injected(UnityEngine.Vector3&)"
                                    ), pcVar2 == (code *)0x0)) {
    uVar3 = FUN_1802ced60("UnityEngine.Transform::get_position_Injected(UnityEngine.Vector3&)");
                    /* WARNING: Subroutine does not return */
    FUN_1802cca90(uVar3,0);
  }
  DAT_182ec1698 = pcVar2;
  (*DAT_182ec1698)(lVar1,&uStack_18);
  *(undefined8 *)(param_1 + 0x28) = uStack_18;
  *(undefined8 *)(param_1 + 0x40) = uStack_18;
  *(undefined4 *)(param_1 + 0x30) = uStack_10;
  *(undefined4 *)(param_1 + 0x48) = uStack_10;
  return;
}

