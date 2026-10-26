// Ghidra pseudocode; not original source or compilable C.
// ev_3708480cc7290d6a800e20d439e003f349e1ad8134cc5cd6988884ad06fec690

void ExposureUnnoticed2_Object3D_Camera_TPCameraController__OnChangeThirdPersonView__06001217
               (longlong param_1)

{
  code *pcVar1;
  longlong lVar2;
  undefined8 uVar3;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined4 local_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  
  lVar2 = *(longlong *)(param_1 + 0x38);
  if (lVar2 != 0) {
    pcVar1 = DAT_182ec1080;
    if ((DAT_182ec1080 == (code *)0x0) &&
       (pcVar1 = (code *)FUN_1802cf0c0("UnityEngine.Component::get_transform()"),
       pcVar1 == (code *)0x0)) {
      uVar3 = FUN_1802ced60("UnityEngine.Component::get_transform()");
                    /* WARNING: Subroutine does not return */
      FUN_1802cca90(uVar3,0);
    }
    DAT_182ec1080 = pcVar1;
    lVar2 = (*DAT_182ec1080)(lVar2);
    if (lVar2 != 0) {
      local_28 = 0;
      uStack_20 = 0;
      pcVar1 = DAT_182ec16b8;
      if ((DAT_182ec16b8 == (code *)0x0) &&
         (pcVar1 = (code *)FUN_1802cf0c0(
                                        "UnityEngine.Transform::get_rotation_Injected(UnityEngine.Quaternion&)"
                                        ), pcVar1 == (code *)0x0)) {
        uVar3 = FUN_1802ced60(
                             "UnityEngine.Transform::get_rotation_Injected(UnityEngine.Quaternion&)"
                             );
                    /* WARNING: Subroutine does not return */
        FUN_1802cca90(uVar3,0);
      }
      DAT_182ec16b8 = pcVar1;
      (*DAT_182ec16b8)(lVar2,&local_28);
      local_18 = (undefined4)local_28;
      uStack_14 = local_28._4_4_;
      uStack_10 = (undefined4)uStack_20;
      uStack_c = uStack_20._4_4_;
      lVar2 = FUN_1803fa4b0(&local_28,&local_18);
      *(undefined4 *)(param_1 + 0x2c) = *(undefined4 *)(lVar2 + 4);
      *(undefined4 *)(param_1 + 0x30) = 0;
      return;
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

