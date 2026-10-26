// Ghidra pseudocode; not original source or compilable C.
// ev_45a1d3201d1b1ec50fefd48f2111f0e7bf260255512bb5d275e6d40d2ff67a66

void ExposureUnnoticed2_Object3D_Camera_BaseCameraController__OnLateUpdate__060011e7
               (longlong param_1)

{
  int iVar1;
  code *pcVar2;
  longlong lVar3;
  longlong lVar4;
  undefined8 uVar5;
  undefined8 uStack_48;
  undefined4 uStack_40;
  undefined8 uStack_38;
  undefined4 uStack_30;
  undefined8 uStack_28;
  undefined8 uStack_20;
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  
  if (cRam0000000182eb7815 == '\0') {
    FUN_1802f2810(&DAT_182d53c48);
    LOCK();
    UNLOCK();
    cRam0000000182eb7815 = '\x01';
  }
  if (((**(longlong **)(DAT_182d53c48 + 0xb8) == 0) ||
      (lVar4 = *(longlong *)(**(longlong **)(DAT_182d53c48 + 0xb8) + 0x28), lVar4 == 0)) ||
     (lVar4 = *(longlong *)(lVar4 + 0x60), lVar4 == 0)) goto code_r0x00018045b80a;
  iVar1 = *(int *)(lVar4 + 0x48);
  if ((iVar1 == 0) || (iVar1 == 1)) {
    if (*(longlong *)(param_1 + 0x60) == 0) goto code_r0x00018045b80a;
    if (*(char *)(param_1 + 0x68) != *(char *)(*(longlong *)(param_1 + 0x60) + 0x1a)) {
      lVar4 = *(longlong *)(param_1 + 0x60);
      *(undefined1 *)(param_1 + 0x68) = *(undefined1 *)(lVar4 + 0x1a);
      if (lVar4 == 0) goto code_r0x00018045b80a;
      if (*(char *)(lVar4 + 0x1a) == '\0') {
        if (cRam0000000182eb7817 == '\0') {
          FUN_1802f2810(&DAT_182d58398);
          LOCK();
          UNLOCK();
          cRam0000000182eb7817 = '\x01';
        }
        if (((*(longlong *)(param_1 + 0x30) == 0) ||
            (ExposureUnnoticed2_Object3D_Camera_TPCameraController__OnChangeThirdPersonView__06001217
                       (*(longlong *)(param_1 + 0x30),0), *(longlong *)(param_1 + 0x30) == 0)) ||
           (lVar4 = *(longlong *)(param_1 + 0x58), lVar4 == 0)) goto code_r0x00018045b80a;
        pcVar2 = DAT_182ebfae0;
        if ((DAT_182ebfae0 == (code *)0x0) &&
           (pcVar2 = (code *)FUN_1802cf0c0("UnityEngine.Camera::set_cullingMask(System.Int32)"),
           pcVar2 == (code *)0x0)) {
          uVar5 = FUN_1802ced60("UnityEngine.Camera::set_cullingMask(System.Int32)");
                    /* WARNING: Subroutine does not return */
          FUN_1802cca90(uVar5,0);
        }
        DAT_182ebfae0 = pcVar2;
        (*DAT_182ebfae0)(lVar4);
        if ((*(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x38) == 0) ||
           (lVar4 = *(longlong *)(param_1 + 0x58), lVar4 == 0)) goto code_r0x00018045b80a;
        pcVar2 = DAT_182ebfa30;
        if ((DAT_182ebfa30 == (code *)0x0) &&
           (pcVar2 = (code *)FUN_1802cf0c0("UnityEngine.Camera::set_fieldOfView(System.Single)"),
           pcVar2 == (code *)0x0)) {
          uVar5 = FUN_1802ced60("UnityEngine.Camera::set_fieldOfView(System.Single)");
                    /* WARNING: Subroutine does not return */
          FUN_1802cca90(uVar5,0);
        }
        DAT_182ebfa30 = pcVar2;
        (*DAT_182ebfa30)(lVar4);
      }
      else {
        ExposureUnnoticed2_Object3D_Camera_BaseCameraController__TransStrafe__060011ea(param_1);
      }
    }
    if (*(char *)(param_1 + 0x69) == '\0') {
      if (*(longlong *)(param_1 + 0x60) == 0) goto code_r0x00018045b80a;
      if (*(char *)(*(longlong *)(param_1 + 0x60) + 0x1a) == '\0') {
        lVar3 = FUN_181d769d0(param_1);
        if ((*(longlong *)(param_1 + 0x30) == 0) ||
           (lVar4 = FUN_181d769d0(*(longlong *)(param_1 + 0x30),0), lVar4 == 0))
        goto code_r0x00018045b80a;
        uStack_48 = 0;
        uStack_40 = 0;
        pcVar2 = DAT_182ec1698;
        if ((DAT_182ec1698 == (code *)0x0) &&
           (pcVar2 = (code *)FUN_1802cf0c0(
                                          "UnityEngine.Transform::get_position_Injected(UnityEngine.Vector3&)"
                                          ), pcVar2 == (code *)0x0)) {
          uVar5 = FUN_1802ced60("UnityEngine.Transform::get_position_Injected(UnityEngine.Vector3&)"
                               );
                    /* WARNING: Subroutine does not return */
          FUN_1802cca90(uVar5,0);
        }
        DAT_182ec1698 = pcVar2;
        (*DAT_182ec1698)(lVar4,&uStack_48);
        if ((*(longlong *)(param_1 + 0x30) == 0) ||
           (lVar4 = FUN_181d769d0(*(longlong *)(param_1 + 0x30),0), lVar4 == 0))
        goto code_r0x00018045b80a;
        uStack_28 = 0;
        uStack_20 = 0;
        pcVar2 = DAT_182ec16b8;
        if ((DAT_182ec16b8 == (code *)0x0) &&
           (pcVar2 = (code *)FUN_1802cf0c0(
                                          "UnityEngine.Transform::get_rotation_Injected(UnityEngine.Quaternion&)"
                                          ), pcVar2 == (code *)0x0)) {
          uVar5 = FUN_1802ced60(
                               "UnityEngine.Transform::get_rotation_Injected(UnityEngine.Quaternion&)"
                               );
                    /* WARNING: Subroutine does not return */
          FUN_1802cca90(uVar5,0);
        }
        DAT_182ec16b8 = pcVar2;
        (*DAT_182ec16b8)(lVar4,&uStack_28);
        if (lVar3 == 0) {
                    /* WARNING: Subroutine does not return */
          FUN_18031dad0();
        }
        uStack_30 = uStack_40;
        uStack_18 = (undefined4)uStack_28;
        uStack_14 = uStack_28._4_4_;
        uStack_10 = (undefined4)uStack_20;
        uStack_c = uStack_20._4_4_;
        uStack_38 = uStack_48;
        pcVar2 = DAT_182ec16f8;
        if ((DAT_182ec16f8 == (code *)0x0) &&
           (pcVar2 = (code *)FUN_1802cf0c0(
                                          "UnityEngine.Transform::SetPositionAndRotation_Injected(UnityEngine.Vector3&,UnityEngine.Quaternion&)"
                                          ), pcVar2 == (code *)0x0)) {
          uVar5 = FUN_1802ced60(
                               "UnityEngine.Transform::SetPositionAndRotation_Injected(UnityEngine.Vector3&,UnityEngine.Quaternion&)"
                               );
                    /* WARNING: Subroutine does not return */
          FUN_1802cca90(uVar5,0);
        }
      }
      else {
        lVar3 = FUN_181d769d0(param_1);
        if ((*(longlong *)(param_1 + 0x38) == 0) ||
           (lVar4 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 0x38), lVar4 == 0))
        goto code_r0x00018045b80a;
        uStack_48 = 0;
        uStack_40 = 0;
        pcVar2 = DAT_182ec1698;
        if ((DAT_182ec1698 == (code *)0x0) &&
           (pcVar2 = (code *)FUN_1802cf0c0(
                                          "UnityEngine.Transform::get_position_Injected(UnityEngine.Vector3&)"
                                          ), pcVar2 == (code *)0x0)) {
          uVar5 = FUN_1802ced60("UnityEngine.Transform::get_position_Injected(UnityEngine.Vector3&)"
                               );
                    /* WARNING: Subroutine does not return */
          FUN_1802cca90(uVar5,0);
        }
        DAT_182ec1698 = pcVar2;
        (*DAT_182ec1698)(lVar4,&uStack_48);
        if ((*(longlong *)(param_1 + 0x38) == 0) ||
           (lVar4 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 0x38), lVar4 == 0))
        goto code_r0x00018045b80a;
        uStack_28 = 0;
        uStack_20 = 0;
        pcVar2 = DAT_182ec16b8;
        if ((DAT_182ec16b8 == (code *)0x0) &&
           (pcVar2 = (code *)FUN_1802cf0c0(
                                          "UnityEngine.Transform::get_rotation_Injected(UnityEngine.Quaternion&)"
                                          ), pcVar2 == (code *)0x0)) {
          uVar5 = FUN_1802ced60(
                               "UnityEngine.Transform::get_rotation_Injected(UnityEngine.Quaternion&)"
                               );
                    /* WARNING: Subroutine does not return */
          FUN_1802cca90(uVar5,0);
        }
        DAT_182ec16b8 = pcVar2;
        (*DAT_182ec16b8)(lVar4,&uStack_28);
        if (lVar3 == 0) {
                    /* WARNING: Subroutine does not return */
          FUN_18031dad0();
        }
        uStack_30 = uStack_40;
        uStack_18 = (undefined4)uStack_28;
        uStack_14 = uStack_28._4_4_;
        uStack_10 = (undefined4)uStack_20;
        uStack_c = uStack_20._4_4_;
        uStack_38 = uStack_48;
        pcVar2 = DAT_182ec16f8;
        if ((DAT_182ec16f8 == (code *)0x0) &&
           (pcVar2 = (code *)FUN_1802cf0c0(
                                          "UnityEngine.Transform::SetPositionAndRotation_Injected(UnityEngine.Vector3&,UnityEngine.Quaternion&)"
                                          ), pcVar2 == (code *)0x0)) {
          uVar5 = FUN_1802ced60(
                               "UnityEngine.Transform::SetPositionAndRotation_Injected(UnityEngine.Vector3&,UnityEngine.Quaternion&)"
                               );
                    /* WARNING: Subroutine does not return */
          FUN_1802cca90(uVar5,0);
        }
      }
    }
    else {
      if (*(longlong *)(param_1 + 0x40) == 0) {
code_r0x00018045b80a:
                    /* WARNING: Subroutine does not return */
        FUN_18031dad0();
      }
      ExposureUnnoticed2_Object3D_Camera_InventoryCameraController__OnLateUpdate__06001207
                (*(longlong *)(param_1 + 0x40),0);
      pcVar2 = DAT_182ec1080;
      if ((DAT_182ec1080 == (code *)0x0) &&
         (pcVar2 = (code *)FUN_1802cf0c0("UnityEngine.Component::get_transform()"),
         pcVar2 == (code *)0x0)) {
        uVar5 = FUN_1802ced60("UnityEngine.Component::get_transform()");
                    /* WARNING: Subroutine does not return */
        FUN_1802cca90(uVar5,0);
      }
      DAT_182ec1080 = pcVar2;
      lVar3 = (*DAT_182ec1080)(param_1);
      lVar4 = *(longlong *)(param_1 + 0x40);
      if (lVar4 == 0) goto code_r0x00018045b80a;
      pcVar2 = DAT_182ec1080;
      if ((DAT_182ec1080 == (code *)0x0) &&
         (pcVar2 = (code *)FUN_1802cf0c0("UnityEngine.Component::get_transform()"),
         pcVar2 == (code *)0x0)) {
        uVar5 = FUN_1802ced60("UnityEngine.Component::get_transform()");
                    /* WARNING: Subroutine does not return */
        FUN_1802cca90(uVar5,0);
      }
      DAT_182ec1080 = pcVar2;
      lVar4 = (*DAT_182ec1080)(lVar4);
      if (lVar4 == 0) goto code_r0x00018045b80a;
      uStack_48 = 0;
      uStack_40 = 0;
      pcVar2 = DAT_182ec1698;
      if ((DAT_182ec1698 == (code *)0x0) &&
         (pcVar2 = (code *)FUN_1802cf0c0(
                                        "UnityEngine.Transform::get_position_Injected(UnityEngine.Vector3&)"
                                        ), pcVar2 == (code *)0x0)) {
        uVar5 = FUN_1802ced60("UnityEngine.Transform::get_position_Injected(UnityEngine.Vector3&)");
                    /* WARNING: Subroutine does not return */
        FUN_1802cca90(uVar5,0);
      }
      DAT_182ec1698 = pcVar2;
      (*DAT_182ec1698)(lVar4,&uStack_48);
      lVar4 = *(longlong *)(param_1 + 0x40);
      if (lVar4 == 0) goto code_r0x00018045b80a;
      pcVar2 = DAT_182ec1080;
      if ((DAT_182ec1080 == (code *)0x0) &&
         (pcVar2 = (code *)FUN_1802cf0c0("UnityEngine.Component::get_transform()"),
         pcVar2 == (code *)0x0)) {
        uVar5 = FUN_1802ced60("UnityEngine.Component::get_transform()");
                    /* WARNING: Subroutine does not return */
        FUN_1802cca90(uVar5,0);
      }
      DAT_182ec1080 = pcVar2;
      lVar4 = (*DAT_182ec1080)(lVar4);
      if (lVar4 == 0) goto code_r0x00018045b80a;
      uStack_28 = 0;
      uStack_20 = 0;
      pcVar2 = DAT_182ec16b8;
      if ((DAT_182ec16b8 == (code *)0x0) &&
         (pcVar2 = (code *)FUN_1802cf0c0(
                                        "UnityEngine.Transform::get_rotation_Injected(UnityEngine.Quaternion&)"
                                        ), pcVar2 == (code *)0x0)) {
        uVar5 = FUN_1802ced60(
                             "UnityEngine.Transform::get_rotation_Injected(UnityEngine.Quaternion&)"
                             );
                    /* WARNING: Subroutine does not return */
        FUN_1802cca90(uVar5,0);
      }
      DAT_182ec16b8 = pcVar2;
      (*DAT_182ec16b8)(lVar4,&uStack_28);
      if (lVar3 == 0) {
                    /* WARNING: Subroutine does not return */
        FUN_18031dad0();
      }
      uStack_30 = uStack_40;
      uStack_18 = (undefined4)uStack_28;
      uStack_14 = uStack_28._4_4_;
      uStack_10 = (undefined4)uStack_20;
      uStack_c = uStack_20._4_4_;
      uStack_38 = uStack_48;
      pcVar2 = DAT_182ec16f8;
      if ((DAT_182ec16f8 == (code *)0x0) &&
         (pcVar2 = (code *)FUN_1802cf0c0(
                                        "UnityEngine.Transform::SetPositionAndRotation_Injected(UnityEngine.Vector3&,UnityEngine.Quaternion&)"
                                        ), pcVar2 == (code *)0x0)) {
        uVar5 = FUN_1802ced60(
                             "UnityEngine.Transform::SetPositionAndRotation_Injected(UnityEngine.Vector3&,UnityEngine.Quaternion&)"
                             );
                    /* WARNING: Subroutine does not return */
        FUN_1802cca90(uVar5,0);
      }
    }
    DAT_182ec16f8 = pcVar2;
    (*DAT_182ec16f8)(lVar3,&uStack_38,&uStack_18);
  }
  return;
}

