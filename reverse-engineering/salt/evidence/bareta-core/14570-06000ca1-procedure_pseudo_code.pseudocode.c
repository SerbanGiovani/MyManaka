// Ghidra pseudocode; not original source or compilable C.
// ev_97e443f6501b427afe1e4bbda46aa166762f8f47afc50d3f67248563c1488843

void ExposureUnnoticed2_Object3D_Player_Scripts_PlayerBaretaState__OnUpdate__06000ca1
               (longlong param_1)

{
  longlong lVar1;
  code *pcVar2;
  undefined8 *puVar3;
  undefined8 uVar4;
  longlong lVar5;
  undefined4 uVar6;
  float fVar7;
  undefined8 uStack_58;
  float fStack_50;
  ulonglong uStack_48;
  float fStack_40;
  undefined4 uStack_3c;
  ulonglong uStack_38;
  undefined8 uStack_30;
  undefined8 uStack_28;
  undefined8 uStack_20;
  
  if (cRam0000000182eb83a5 == '\0') {
    FUN_1802f2810(&DAT_182d58288);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d53c48);
    LOCK();
    UNLOCK();
    cRam0000000182eb83a5 = '\x01';
  }
  lVar1 = *(longlong *)(param_1 + 0x20);
  if ((lVar1 != 0) && (*(longlong *)(lVar1 + 0x60) != 0)) {
    if (*(int *)(*(longlong *)(lVar1 + 0x60) + 0x234) == 0x2722) {
      if (((lVar1 != 0) && (*(longlong *)(lVar1 + 0x48) != 0)) &&
         (lVar1 = *(longlong *)(*(longlong *)(lVar1 + 0x48) + 0x60), lVar1 != 0)) {
        *(undefined4 *)(lVar1 + 0x1c) = 0;
        if ((*(longlong *)(param_1 + 0x20) != 0) &&
           (lVar1 = *(longlong *)(*(longlong *)(param_1 + 0x20) + 0x48), lVar1 != 0)) {
          ExposureUnnoticed2_Object3D_Player_Scripts_PlayerAnimationManager__SetBareta__06000c85
                    (lVar1,0,0);
          if ((*(longlong *)(param_1 + 0x20) != 0) &&
             (lVar1 = *(longlong *)(*(longlong *)(param_1 + 0x20) + 0x48), lVar1 != 0)) {
            ExposureUnnoticed2_Object3D_Player_Scripts_PlayerAnimationManager__SetBaretaFace__06000c86
                      (lVar1,0,0);
            lVar1 = *(longlong *)(param_1 + 0x20);
            if (lVar1 != 0) {
              if (*(char *)(param_1 + 0x18) == '\0') {
                if ((*(longlong *)(lVar1 + 0x60) == 0) ||
                   (lVar5 = *(longlong *)(lVar1 + 0x68), lVar5 == 0)) goto code_r0x00018063177a;
                uVar6 = *(undefined4 *)(*(longlong *)(lVar1 + 0x60) + 0x234);
              }
              else {
                lVar5 = *(longlong *)(lVar1 + 0x68);
                if (lVar5 == 0) goto code_r0x00018063177a;
                uVar6 = 6;
              }
              ExposureUnnoticed2_Object3D_Player_Scripts_PlayerAction__ChangeAction__06000c36
                        (lVar5,uVar6,0);
              if ((*(longlong *)(param_1 + 0x20) != 0) &&
                 (lVar1 = *(longlong *)(*(longlong *)(param_1 + 0x20) + 0x120), lVar1 != 0)) {
                ExposureUnnoticed2_Object3D_Player_Scripts_LookAtController__DisableLookAt__06000c10
                          (lVar1,7,0);
                return;
              }
            }
          }
        }
      }
    }
    else {
      pcVar2 = DAT_182ec14c0;
      if ((DAT_182ec14c0 == (code *)0x0) &&
         (pcVar2 = (code *)FUN_1802cf0c0("UnityEngine.Time::get_time()"), pcVar2 == (code *)0x0)) {
        uVar4 = FUN_1802ced60("UnityEngine.Time::get_time()");
                    /* WARNING: Subroutine does not return */
        FUN_1802cca90(uVar4,0);
      }
      DAT_182ec14c0 = pcVar2;
      fVar7 = (float)(*DAT_182ec14c0)();
      if (2.0 <= fVar7 - *(float *)(param_1 + 0x28)) {
        if ((**(longlong **)(DAT_182d53c48 + 0xb8) == 0) ||
           (lVar1 = *(longlong *)(**(longlong **)(DAT_182d53c48 + 0xb8) + 0x30), lVar1 == 0))
        goto code_r0x00018063177a;
        if (*(char *)(lVar1 + 0x11) == '\0') {
          if ((*(longlong *)(param_1 + 0x20) == 0) ||
             (lVar1 = *(longlong *)(*(longlong *)(param_1 + 0x20) + 0x50), lVar1 == 0))
          goto code_r0x00018063177a;
          ExposureUnnoticed2_Object3D_Player_Scripts_PlayerController__ChangeState__06000d5e
                    (lVar1,0,0);
        }
      }
      if (*(char *)(param_1 + 0x18) != '\0') {
        return;
      }
      uStack_48 = 0;
      fStack_40 = 0.0;
      uStack_28 = 0;
      uStack_20 = 0;
      pcVar2 = DAT_182ec0e88;
      if ((DAT_182ec0e88 == (code *)0x0) &&
         (pcVar2 = (code *)FUN_1802cf0c0(
                                        "UnityEngine.Quaternion::Internal_FromEulerRad_Injected(UnityEngine.Vector3&,UnityEngine.Quaternion&)"
                                        ), pcVar2 == (code *)0x0)) {
        uVar4 = FUN_1802ced60(
                             "UnityEngine.Quaternion::Internal_FromEulerRad_Injected(UnityEngine.Vector3&,UnityEngine.Quaternion&)"
                             );
                    /* WARNING: Subroutine does not return */
        FUN_1802cca90(uVar4,0);
      }
      DAT_182ec0e88 = pcVar2;
      (*DAT_182ec0e88)(&uStack_48,&uStack_28);
      if ((*(longlong *)(param_1 + 0x10) != 0) &&
         (lVar1 = *(longlong *)(*(longlong *)(param_1 + 0x10) + 0x10), lVar1 != 0)) {
        uStack_58 = 0;
        fStack_50 = 0.0;
        pcVar2 = DAT_182ec1698;
        if ((DAT_182ec1698 == (code *)0x0) &&
           (pcVar2 = (code *)FUN_1802cf0c0(
                                          "UnityEngine.Transform::get_position_Injected(UnityEngine.Vector3&)"
                                          ), pcVar2 == (code *)0x0)) {
          uVar4 = FUN_1802ced60("UnityEngine.Transform::get_position_Injected(UnityEngine.Vector3&)"
                               );
                    /* WARNING: Subroutine does not return */
          FUN_1802cca90(uVar4,0);
        }
        DAT_182ec1698 = pcVar2;
        (*DAT_182ec1698)(lVar1,&uStack_58);
        if (*(int *)(DAT_182d58288 + 0xe0) == 0) {
          FUN_18035c820();
        }
        if ((*(longlong *)(param_1 + 0x20) != 0) &&
           (lVar1 = *(longlong *)(*(longlong *)(param_1 + 0x20) + 0x18), lVar1 != 0)) {
          uStack_48 = 0;
          fStack_40 = 0.0;
          pcVar2 = DAT_182ec1698;
          if ((DAT_182ec1698 == (code *)0x0) &&
             (pcVar2 = (code *)FUN_1802cf0c0(
                                            "UnityEngine.Transform::get_position_Injected(UnityEngine.Vector3&)"
                                            ), pcVar2 == (code *)0x0)) {
            uVar4 = FUN_1802ced60(
                                 "UnityEngine.Transform::get_position_Injected(UnityEngine.Vector3&)"
                                 );
                    /* WARNING: Subroutine does not return */
            FUN_1802cca90(uVar4,0);
          }
          DAT_182ec1698 = pcVar2;
          (*DAT_182ec1698)(lVar1,&uStack_48);
          fStack_40 = fStack_50 - fStack_40;
          uStack_38 = uStack_48;
          uStack_48 = (ulonglong)(uint)((float)uStack_58 - (float)uStack_48);
          puVar3 = (undefined8 *)FUN_181f31290(&uStack_38,&uStack_28,&uStack_48,0);
          uVar4 = *puVar3;
          fVar7 = *(float *)(puVar3 + 1);
          if (DAT_182eb547c == '\0') {
            FUN_1802f2810(&DAT_182d522a8);
            LOCK();
            UNLOCK();
            DAT_182eb547c = '\x01';
          }
          uStack_48 = *(ulonglong *)(*(longlong *)(DAT_182d522a8 + 0xb8) + 0x18);
          fStack_40 = *(float *)(*(longlong *)(DAT_182d522a8 + 0xb8) + 0x20);
          uStack_28 = 0;
          uStack_20 = 0;
          pcVar2 = DAT_182ec0ea8;
          uStack_58 = uVar4;
          fStack_50 = fVar7;
          if ((DAT_182ec0ea8 == (code *)0x0) &&
             (pcVar2 = (code *)FUN_1802cf0c0(
                                            "UnityEngine.Quaternion::LookRotation_Injected(UnityEngine.Vector3&,UnityEngine.Vector3&,UnityEngine.Quaternion&)"
                                            ), pcVar2 == (code *)0x0)) {
            uVar4 = FUN_1802ced60(
                                 "UnityEngine.Quaternion::LookRotation_Injected(UnityEngine.Vector3&,UnityEngine.Vector3&,UnityEngine.Quaternion&)"
                                 );
                    /* WARNING: Subroutine does not return */
            FUN_1802cca90(uVar4,0);
          }
          DAT_182ec0ea8 = pcVar2;
          (*DAT_182ec0ea8)(&uStack_58,&uStack_48,&uStack_28);
          if ((*(longlong *)(param_1 + 0x20) != 0) &&
             (lVar1 = *(longlong *)(*(longlong *)(param_1 + 0x20) + 0x18), lVar1 != 0)) {
            uStack_38 = 0;
            uStack_30 = 0;
            pcVar2 = DAT_182ec16b8;
            if ((DAT_182ec16b8 == (code *)0x0) &&
               (pcVar2 = (code *)FUN_1802cf0c0(
                                              "UnityEngine.Transform::get_rotation_Injected(UnityEngine.Quaternion&)"
                                              ), pcVar2 == (code *)0x0)) {
              uVar4 = FUN_1802ced60(
                                   "UnityEngine.Transform::get_rotation_Injected(UnityEngine.Quaternion&)"
                                   );
                    /* WARNING: Subroutine does not return */
              FUN_1802cca90(uVar4,0);
            }
            DAT_182ec16b8 = pcVar2;
            (*DAT_182ec16b8)(lVar1,&uStack_38);
            pcVar2 = DAT_182ec14d0;
            if ((DAT_182ec14d0 == (code *)0x0) &&
               (pcVar2 = (code *)FUN_1802cf0c0("UnityEngine.Time::get_deltaTime()"),
               pcVar2 == (code *)0x0)) {
              uVar4 = FUN_1802ced60("UnityEngine.Time::get_deltaTime()");
                    /* WARNING: Subroutine does not return */
              FUN_1802cca90(uVar4,0);
            }
            DAT_182ec14d0 = pcVar2;
            uStack_48 = uStack_38;
            fStack_40 = (float)(undefined4)uStack_30;
            uStack_3c = uStack_30._4_4_;
            fVar7 = (float)(*DAT_182ec14d0)();
            puVar3 = (undefined8 *)FUN_1804363f0(&uStack_38,&uStack_48,&uStack_28,fVar7 * 400.0);
            uStack_28 = *puVar3;
            uStack_20 = puVar3[1];
            pcVar2 = DAT_182ec16c0;
            if ((DAT_182ec16c0 == (code *)0x0) &&
               (pcVar2 = (code *)FUN_1802cf0c0(
                                              "UnityEngine.Transform::set_rotation_Injected(UnityEngine.Quaternion&)"
                                              ), pcVar2 == (code *)0x0)) {
              uVar4 = FUN_1802ced60(
                                   "UnityEngine.Transform::set_rotation_Injected(UnityEngine.Quaternion&)"
                                   );
                    /* WARNING: Subroutine does not return */
              FUN_1802cca90(uVar4,0);
            }
            DAT_182ec16c0 = pcVar2;
            (*DAT_182ec16c0)(lVar1,&uStack_28);
            return;
          }
        }
      }
    }
  }
code_r0x00018063177a:
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

