// Ghidra pseudocode; not original source or compilable C.
// ev_820339970ee944999364b1cdffbf50ca540f8be112f29e5c84f37e6d81a8822a

void ExposureUnnoticed2_Scripts_InGame_GameOverController__OnLateUpdate__060014df(longlong param_1)

{
  undefined4 uVar1;
  longlong lVar2;
  code *pcVar3;
  longlong lVar4;
  undefined8 uVar5;
  float fVar6;
  float fVar7;
  undefined8 uStack_68;
  ulonglong uStack_60;
  undefined8 uStack_58;
  float fStack_50;
  undefined8 uStack_48;
  undefined8 uStack_40;
  undefined8 uStack_38;
  undefined8 uStack_30;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  
  if (cRam0000000182eb7959 == '\0') {
    FUN_1802f2810(&DAT_182d53c48);
    LOCK();
    UNLOCK();
    cRam0000000182eb7959 = '\x01';
  }
  if (*(int *)(param_1 + 0x48) != 2) {
    return;
  }
  if (((**(longlong **)(DAT_182d53c48 + 0xb8) != 0) &&
      (lVar2 = *(longlong *)(**(longlong **)(DAT_182d53c48 + 0xb8) + 0x28), lVar2 != 0)) &&
     (lVar2 = *(longlong *)(lVar2 + 0x38), lVar2 != 0)) {
    pcVar3 = DAT_182ec1080;
    if ((DAT_182ec1080 == (code *)0x0) &&
       (pcVar3 = (code *)FUN_1802cf0c0("UnityEngine.Component::get_transform()"),
       pcVar3 == (code *)0x0)) {
      uVar5 = FUN_1802ced60("UnityEngine.Component::get_transform()");
                    /* WARNING: Subroutine does not return */
      FUN_1802cca90(uVar5,0);
    }
    DAT_182ec1080 = pcVar3;
    lVar4 = (*DAT_182ec1080)(lVar2);
    lVar2 = *(longlong *)(param_1 + 0x28);
    if (lVar2 != 0) {
      uStack_58 = 0;
      fStack_50 = 0.0;
      pcVar3 = DAT_182ec1698;
      if ((DAT_182ec1698 == (code *)0x0) &&
         (pcVar3 = (code *)FUN_1802cf0c0(
                                        "UnityEngine.Transform::get_position_Injected(UnityEngine.Vector3&)"
                                        ), pcVar3 == (code *)0x0)) {
        uVar5 = FUN_1802ced60("UnityEngine.Transform::get_position_Injected(UnityEngine.Vector3&)");
                    /* WARNING: Subroutine does not return */
        FUN_1802cca90(uVar5,0);
      }
      DAT_182ec1698 = pcVar3;
      (*DAT_182ec1698)(lVar2,&uStack_58);
      lVar2 = *(longlong *)(param_1 + 0x30);
      if (lVar2 != 0) {
        uStack_68 = 0;
        uStack_60 = uStack_60 & 0xffffffff00000000;
        pcVar3 = DAT_182ec1698;
        if ((DAT_182ec1698 == (code *)0x0) &&
           (pcVar3 = (code *)FUN_1802cf0c0(
                                          "UnityEngine.Transform::get_position_Injected(UnityEngine.Vector3&)"
                                          ), pcVar3 == (code *)0x0)) {
          uVar5 = FUN_1802ced60("UnityEngine.Transform::get_position_Injected(UnityEngine.Vector3&)"
                               );
                    /* WARNING: Subroutine does not return */
          FUN_1802cca90(uVar5,0);
        }
        DAT_182ec1698 = pcVar3;
        (*DAT_182ec1698)(lVar2,&uStack_68);
        fVar6 = *(float *)(param_1 + 0x20);
        if (fVar6 < 0.0) {
          fVar6 = 0.0;
        }
        else if (1.0 < fVar6) {
          fVar6 = 1.0;
        }
        fVar7 = ((float)uStack_60 - fStack_50) * fVar6 + fStack_50;
        if (lVar4 != 0) {
          uStack_58 = CONCAT44((uStack_68._4_4_ - uStack_58._4_4_) * fVar6 + uStack_58._4_4_,
                               ((float)uStack_68 - (float)uStack_58) * fVar6 + (float)uStack_58);
          pcVar3 = DAT_182ec16a0;
          fStack_50 = fVar7;
          if ((DAT_182ec16a0 == (code *)0x0) &&
             (pcVar3 = (code *)FUN_1802cf0c0(
                                            "UnityEngine.Transform::set_position_Injected(UnityEngine.Vector3&)"
                                            ), pcVar3 == (code *)0x0)) {
            uVar5 = FUN_1802ced60(
                                 "UnityEngine.Transform::set_position_Injected(UnityEngine.Vector3&)"
                                 );
                    /* WARNING: Subroutine does not return */
            FUN_1802cca90(uVar5,0);
          }
          DAT_182ec16a0 = pcVar3;
          (*DAT_182ec16a0)(lVar4,&uStack_58);
          if (((**(longlong **)(DAT_182d53c48 + 0xb8) != 0) &&
              (lVar2 = *(longlong *)(**(longlong **)(DAT_182d53c48 + 0xb8) + 0x28), lVar2 != 0)) &&
             (lVar2 = *(longlong *)(lVar2 + 0x38), lVar2 != 0)) {
            pcVar3 = DAT_182ec1080;
            if ((DAT_182ec1080 == (code *)0x0) &&
               (pcVar3 = (code *)FUN_1802cf0c0("UnityEngine.Component::get_transform()"),
               pcVar3 == (code *)0x0)) {
              uVar5 = FUN_1802ced60("UnityEngine.Component::get_transform()");
                    /* WARNING: Subroutine does not return */
              FUN_1802cca90(uVar5,0);
            }
            DAT_182ec1080 = pcVar3;
            lVar4 = (*DAT_182ec1080)(lVar2);
            lVar2 = *(longlong *)(param_1 + 0x28);
            if (lVar2 != 0) {
              uStack_48 = 0;
              uStack_40 = 0;
              pcVar3 = DAT_182ec16b8;
              if ((DAT_182ec16b8 == (code *)0x0) &&
                 (pcVar3 = (code *)FUN_1802cf0c0(
                                                "UnityEngine.Transform::get_rotation_Injected(UnityEngine.Quaternion&)"
                                                ), pcVar3 == (code *)0x0)) {
                uVar5 = FUN_1802ced60(
                                     "UnityEngine.Transform::get_rotation_Injected(UnityEngine.Quaternion&)"
                                     );
                    /* WARNING: Subroutine does not return */
                FUN_1802cca90(uVar5,0);
              }
              DAT_182ec16b8 = pcVar3;
              (*DAT_182ec16b8)(lVar2,&uStack_48);
              lVar2 = *(longlong *)(param_1 + 0x30);
              if (lVar2 != 0) {
                uStack_68 = 0;
                uStack_60 = 0;
                pcVar3 = DAT_182ec16b8;
                if ((DAT_182ec16b8 == (code *)0x0) &&
                   (pcVar3 = (code *)FUN_1802cf0c0(
                                                  "UnityEngine.Transform::get_rotation_Injected(UnityEngine.Quaternion&)"
                                                  ), pcVar3 == (code *)0x0)) {
                  uVar5 = FUN_1802ced60(
                                       "UnityEngine.Transform::get_rotation_Injected(UnityEngine.Quaternion&)"
                                       );
                    /* WARNING: Subroutine does not return */
                  FUN_1802cca90(uVar5,0);
                }
                DAT_182ec16b8 = pcVar3;
                (*DAT_182ec16b8)(lVar2,&uStack_68);
                uVar1 = *(undefined4 *)(param_1 + 0x20);
                uStack_38 = uStack_68;
                uStack_30 = uStack_60;
                uStack_28 = (undefined4)uStack_48;
                uStack_24 = uStack_48._4_4_;
                uStack_20 = (undefined4)uStack_40;
                uStack_1c = uStack_40._4_4_;
                uStack_48 = 0;
                uStack_40 = 0;
                pcVar3 = pcRam0000000182ec0e70;
                if ((pcRam0000000182ec0e70 == (code *)0x0) &&
                   (pcVar3 = (code *)FUN_1802cf0c0(
                                                  "UnityEngine.Quaternion::Slerp_Injected(UnityEngine.Quaternion&,UnityEngine.Quaternion&,System.Single,UnityEngine.Quaternion&)"
                                                  ), pcVar3 == (code *)0x0)) {
                  uVar5 = FUN_1802ced60(
                                       "UnityEngine.Quaternion::Slerp_Injected(UnityEngine.Quaternion&,UnityEngine.Quaternion&,System.Single,UnityEngine.Quaternion&)"
                                       );
                    /* WARNING: Subroutine does not return */
                  FUN_1802cca90(uVar5,0);
                }
                pcRam0000000182ec0e70 = pcVar3;
                (*pcRam0000000182ec0e70)(&uStack_28,&uStack_38,uVar1,&uStack_48);
                if (lVar4 == 0) {
                    /* WARNING: Subroutine does not return */
                  FUN_18031dad0();
                }
                uStack_68 = uStack_48;
                uStack_60 = uStack_40;
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
                (*DAT_182ec16c0)(lVar4,&uStack_68);
                return;
              }
              goto DAT_180484d15;
            }
          }
        }
                    /* WARNING: Subroutine does not return */
        FUN_18031dad0();
      }
    }
  }
DAT_180484d15:
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

