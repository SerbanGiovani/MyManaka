// Ghidra pseudocode; not original source or compilable C.
// ev_59acc076ef5473da3924a3072f814e52dbcc3aef562f690ac596b4d87bda35ec

void ExposureUnnoticed2_Object3D_NPC_Script_NpcController__OnUpdateEarly__0600105a(longlong param_1)

{
  longlong lVar1;
  longlong lVar2;
  code *pcVar3;
  undefined8 uVar4;
  undefined8 uStack_18;
  undefined4 uStack_10;
  
  lVar1 = *(longlong *)(param_1 + 0x48);
  if ((*(longlong *)(param_1 + 0x30) != 0) &&
     (lVar2 = *(longlong *)(*(longlong *)(param_1 + 0x30) + 0x10), lVar2 != 0)) {
    uStack_18 = 0;
    uStack_10 = 0;
    pcVar3 = DAT_182ec1698;
    if ((DAT_182ec1698 == (code *)0x0) &&
       (pcVar3 = (code *)FUN_1802cf0c0(
                                      "UnityEngine.Transform::get_position_Injected(UnityEngine.Vector3&)"
                                      ), pcVar3 == (code *)0x0)) {
      uVar4 = FUN_1802ced60("UnityEngine.Transform::get_position_Injected(UnityEngine.Vector3&)");
                    /* WARNING: Subroutine does not return */
      FUN_1802cca90(uVar4,0);
    }
    DAT_182ec1698 = pcVar3;
    (*DAT_182ec1698)(lVar2,&uStack_18);
    if (lVar1 != 0) {
      *(undefined8 *)(lVar1 + 0xdc) = uStack_18;
      *(undefined4 *)(lVar1 + 0xe4) = uStack_10;
      return;
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

