// Ghidra pseudocode; not original source or compilable C.
// ev_8a4a60175a9cba3d8126568447e74441679090f55be2968f3e1116da33618b3b

void ExposureUnnoticed2_Object3D_Player_Scripts_PlayerController__Warp__06000d62
               (longlong param_1,undefined8 *param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  longlong lVar2;
  code *pcVar3;
  longlong lVar4;
  undefined8 uVar5;
  undefined8 uStack_38;
  undefined4 uStack_30;
  undefined8 uStack_28;
  undefined4 uStack_20;
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  
  if ((*(longlong *)(param_1 + 0x40) != 0) &&
     (lVar4 = *(longlong *)(*(longlong *)(param_1 + 0x40) + 0x30), lVar4 != 0)) {
    pcVar3 = DAT_182ec3970;
    if ((DAT_182ec3970 == (code *)0x0) &&
       (pcVar3 = (code *)FUN_1802cf0c0("UnityEngine.Collider::set_enabled(System.Boolean)"),
       pcVar3 == (code *)0x0)) {
      uVar5 = FUN_1802ced60("UnityEngine.Collider::set_enabled(System.Boolean)");
                    /* WARNING: Subroutine does not return */
      FUN_1802cca90(uVar5,0);
    }
    DAT_182ec3970 = pcVar3;
    (*DAT_182ec3970)(lVar4,0);
    pcVar3 = DAT_182ec1080;
    if ((DAT_182ec1080 == (code *)0x0) &&
       (pcVar3 = (code *)FUN_1802cf0c0("UnityEngine.Component::get_transform()"),
       pcVar3 == (code *)0x0)) {
      uVar5 = FUN_1802ced60("UnityEngine.Component::get_transform()");
                    /* WARNING: Subroutine does not return */
      FUN_1802cca90(uVar5,0);
    }
    DAT_182ec1080 = pcVar3;
    lVar4 = (*DAT_182ec1080)(param_1);
    if (lVar4 != 0) {
      uStack_38 = *param_2;
      uStack_30 = *(undefined4 *)(param_2 + 1);
      pcVar3 = DAT_182ec16a0;
      if ((DAT_182ec16a0 == (code *)0x0) &&
         (pcVar3 = (code *)FUN_1802cf0c0(
                                        "UnityEngine.Transform::set_position_Injected(UnityEngine.Vector3&)"
                                        ), pcVar3 == (code *)0x0)) {
        uVar5 = FUN_1802ced60("UnityEngine.Transform::set_position_Injected(UnityEngine.Vector3&)");
                    /* WARNING: Subroutine does not return */
        FUN_1802cca90(uVar5,0);
      }
      DAT_182ec16a0 = pcVar3;
      (*DAT_182ec16a0)(lVar4,&uStack_38);
      pcVar3 = DAT_182ec1080;
      if ((DAT_182ec1080 == (code *)0x0) &&
         (pcVar3 = (code *)FUN_1802cf0c0("UnityEngine.Component::get_transform()"),
         pcVar3 == (code *)0x0)) {
        uVar5 = FUN_1802ced60("UnityEngine.Component::get_transform()");
                    /* WARNING: Subroutine does not return */
        FUN_1802cca90(uVar5,0);
      }
      DAT_182ec1080 = pcVar3;
      lVar4 = (*DAT_182ec1080)(param_1);
      if (lVar4 != 0) {
        uStack_18 = *param_3;
        uStack_14 = param_3[1];
        uStack_10 = param_3[2];
        uStack_c = param_3[3];
        pcVar3 = DAT_182ec16c0;
        if ((DAT_182ec16c0 == (code *)0x0) &&
           (pcVar3 = (code *)FUN_1802cf0c0(
                                          "UnityEngine.Transform::set_rotation_Injected(UnityEngine.Quaternion&)"
                                          ), pcVar3 == (code *)0x0)) {
          uVar5 = FUN_1802ced60(
                               "UnityEngine.Transform::set_rotation_Injected(UnityEngine.Quaternion&)"
                               );
                    /* WARNING: Subroutine does not return */
          FUN_1802cca90(uVar5,0);
        }
        DAT_182ec16c0 = pcVar3;
        (*DAT_182ec16c0)(lVar4,&uStack_18);
        if ((*(longlong *)(param_1 + 0x40) != 0) &&
           (lVar4 = *(longlong *)(*(longlong *)(param_1 + 0x40) + 0x30), lVar4 != 0)) {
          pcVar3 = DAT_182ec3970;
          if ((DAT_182ec3970 == (code *)0x0) &&
             (pcVar3 = (code *)FUN_1802cf0c0("UnityEngine.Collider::set_enabled(System.Boolean)"),
             pcVar3 == (code *)0x0)) {
            uVar5 = FUN_1802ced60("UnityEngine.Collider::set_enabled(System.Boolean)");
                    /* WARNING: Subroutine does not return */
            FUN_1802cca90(uVar5,0);
          }
          DAT_182ec3970 = pcVar3;
          (*DAT_182ec3970)(lVar4,1);
          if (*(longlong *)(param_1 + 0x40) != 0) {
            lVar4 = *(longlong *)(*(longlong *)(param_1 + 0x40) + 0x38);
            if (DAT_182eb5480 == '\0') {
              FUN_1802f2810(&DAT_182d522a8);
              LOCK();
              UNLOCK();
              DAT_182eb5480 = '\x01';
            }
            if (lVar4 != 0) {
              uStack_28 = **(undefined8 **)(DAT_182d522a8 + 0xb8);
              uStack_20 = *(undefined4 *)(*(undefined8 **)(DAT_182d522a8 + 0xb8) + 1);
              pcVar3 = pcRam0000000182ec3908;
              if ((pcRam0000000182ec3908 == (code *)0x0) &&
                 (pcVar3 = (code *)FUN_1802cf0c0(
                                                "UnityEngine.Rigidbody::set_velocity_Injected(UnityEngine.Vector3&)"
                                                ), pcVar3 == (code *)0x0)) {
                uVar5 = FUN_1802ced60(
                                     "UnityEngine.Rigidbody::set_velocity_Injected(UnityEngine.Vector3&)"
                                     );
                    /* WARNING: Subroutine does not return */
                FUN_1802cca90(uVar5,0);
              }
              pcRam0000000182ec3908 = pcVar3;
              (*pcRam0000000182ec3908)(lVar4,&uStack_28);
              if ((*(longlong *)(param_1 + 0x40) != 0) &&
                 (lVar4 = *(longlong *)(*(longlong *)(param_1 + 0x40) + 0x58), lVar4 != 0)) {
                *(undefined4 *)(lVar4 + 0x20) = 0;
                if (*(longlong *)(lVar4 + 0x28) != 0) {
                  *(undefined4 *)(*(longlong *)(lVar4 + 0x28) + 0x10) = 0;
                  if (*(longlong *)(lVar4 + 0x78) != 0) {
                    lVar4 = *(longlong *)(*(longlong *)(lVar4 + 0x78) + 0x60);
                    if (DAT_182eb5480 == '\0') {
                      FUN_1802f2810(&DAT_182d522a8);
                      LOCK();
                      UNLOCK();
                      DAT_182eb5480 = '\x01';
                    }
                    uVar1 = *(undefined4 *)(*(undefined8 **)(DAT_182d522a8 + 0xb8) + 1);
                    if (lVar4 != 0) {
                      *(undefined8 *)(lVar4 + 400) = **(undefined8 **)(DAT_182d522a8 + 0xb8);
                      *(undefined4 *)(lVar4 + 0x198) = uVar1;
                      if ((((*(longlong *)(param_1 + 0x40) != 0) &&
                           (lVar4 = *(longlong *)(*(longlong *)(param_1 + 0x40) + 0x1f8), lVar4 != 0
                           )) && (*(longlong *)(lVar4 + 0x20) != 0)) &&
                         (lVar2 = *(longlong *)(*(longlong *)(lVar4 + 0x20) + 0x18), lVar2 != 0)) {
                        uStack_38 = 0;
                        uStack_30 = 0;
                        pcVar3 = DAT_182ec1698;
                        if ((DAT_182ec1698 == (code *)0x0) &&
                           (pcVar3 = (code *)FUN_1802cf0c0(
                                                  "UnityEngine.Transform::get_position_Injected(UnityEngine.Vector3&)"
                                                  ), pcVar3 == (code *)0x0)) {
                          uVar5 = FUN_1802ced60(
                                               "UnityEngine.Transform::get_position_Injected(UnityEngine.Vector3&)"
                                               );
                    /* WARNING: Subroutine does not return */
                          FUN_1802cca90(uVar5,0);
                        }
                        DAT_182ec1698 = pcVar3;
                        (*DAT_182ec1698)(lVar2,&uStack_38);
                        *(undefined8 *)(lVar4 + 0x28) = uStack_38;
                        *(undefined8 *)(lVar4 + 0x40) = uStack_38;
                        *(undefined4 *)(lVar4 + 0x30) = uStack_30;
                        *(undefined4 *)(lVar4 + 0x48) = uStack_30;
                        return;
                      }
                    }
                  }
                }
              }
            }
                    /* WARNING: Subroutine does not return */
            FUN_18031dad0();
          }
        }
      }
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

