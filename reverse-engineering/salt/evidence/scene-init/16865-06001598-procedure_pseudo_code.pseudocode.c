// Ghidra pseudocode; not original source or compilable C.
// ev_7c6252c749a9ab1e3d93007a12ce67c551dc0c8838edb04bad2a8a9982580455

void ExposureUnnoticed2_Scripts_InGame_InGameManager__OnLateUpdate__06001598(longlong param_1)

{
  undefined4 uVar1;
  longlong lVar2;
  longlong lVar3;
  code *pcVar4;
  longlong lVar5;
  undefined8 uVar6;
  float fVar7;
  float fVar8;
  undefined8 uStack_68;
  ulonglong uStack_60;
  undefined8 uStack_58;
  float fStack_50;
  undefined8 uStack_48;
  undefined8 uStack_40;
  undefined8 uStack_38;
  undefined *puStack_30;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  
  if (*(longlong *)(param_1 + 0x38) != 0) {
    puStack_30 = &UNK_180498929;
    ExposureUnnoticed2_Scripts_Mission_MissionManager__OnLateUpdate__06001469
              (*(longlong *)(param_1 + 0x38),0);
    if (*(longlong *)(param_1 + 0x68) != 0) {
      puStack_30 = &UNK_18049893c;
      ExposureUnnoticed2_Scripts_InGame_GameStateApplier__OnLateUpdate__0600151f
                (*(longlong *)(param_1 + 0x68),0,0);
      if ((*(longlong *)(param_1 + 0x28) != 0) &&
         (lVar3 = *(longlong *)(*(longlong *)(param_1 + 0x28) + 0x60), lVar3 != 0)) {
        if (cRam0000000182eb7959 == '\0') {
          FUN_1802f2810(&DAT_182d53c48,0);
          LOCK();
          UNLOCK();
          cRam0000000182eb7959 = '\x01';
        }
        if (*(int *)(lVar3 + 0x48) != 2) {
          return;
        }
        if (((**(longlong **)(DAT_182d53c48 + 0xb8) != 0) &&
            (lVar2 = *(longlong *)(**(longlong **)(DAT_182d53c48 + 0xb8) + 0x28), lVar2 != 0)) &&
           (lVar2 = *(longlong *)(lVar2 + 0x38), lVar2 != 0)) {
          pcVar4 = DAT_182ec1080;
          if ((DAT_182ec1080 == (code *)0x0) &&
             (pcVar4 = (code *)FUN_1802cf0c0("UnityEngine.Component::get_transform()"),
             pcVar4 == (code *)0x0)) {
            uVar6 = FUN_1802ced60("UnityEngine.Component::get_transform()");
                    /* WARNING: Subroutine does not return */
            FUN_1802cca90(uVar6,0);
          }
          DAT_182ec1080 = pcVar4;
          lVar5 = (*DAT_182ec1080)(lVar2);
          lVar2 = *(longlong *)(lVar3 + 0x28);
          if (lVar2 != 0) {
            uStack_58 = 0;
            fStack_50 = 0.0;
            pcVar4 = DAT_182ec1698;
            if ((DAT_182ec1698 == (code *)0x0) &&
               (pcVar4 = (code *)FUN_1802cf0c0(
                                              "UnityEngine.Transform::get_position_Injected(UnityEngine.Vector3&)"
                                              ), pcVar4 == (code *)0x0)) {
              uVar6 = FUN_1802ced60(
                                   "UnityEngine.Transform::get_position_Injected(UnityEngine.Vector3&)"
                                   );
                    /* WARNING: Subroutine does not return */
              FUN_1802cca90(uVar6,0);
            }
            DAT_182ec1698 = pcVar4;
            (*DAT_182ec1698)(lVar2,&uStack_58);
            lVar2 = *(longlong *)(lVar3 + 0x30);
            if (lVar2 != 0) {
              uStack_68 = 0;
              uStack_60 = uStack_60 & 0xffffffff00000000;
              pcVar4 = DAT_182ec1698;
              if ((DAT_182ec1698 == (code *)0x0) &&
                 (pcVar4 = (code *)FUN_1802cf0c0(
                                                "UnityEngine.Transform::get_position_Injected(UnityEngine.Vector3&)"
                                                ), pcVar4 == (code *)0x0)) {
                uVar6 = FUN_1802ced60(
                                     "UnityEngine.Transform::get_position_Injected(UnityEngine.Vector3&)"
                                     );
                    /* WARNING: Subroutine does not return */
                FUN_1802cca90(uVar6,0);
              }
              DAT_182ec1698 = pcVar4;
              (*DAT_182ec1698)(lVar2,&uStack_68);
              fVar7 = *(float *)(lVar3 + 0x20);
              if (fVar7 < 0.0) {
                fVar7 = 0.0;
              }
              else if (1.0 < fVar7) {
                fVar7 = 1.0;
              }
              fVar8 = ((float)uStack_60 - fStack_50) * fVar7 + fStack_50;
              if (lVar5 != 0) {
                uStack_58 = CONCAT44((uStack_68._4_4_ - uStack_58._4_4_) * fVar7 + uStack_58._4_4_,
                                     ((float)uStack_68 - (float)uStack_58) * fVar7 +
                                     (float)uStack_58);
                pcVar4 = DAT_182ec16a0;
                fStack_50 = fVar8;
                if ((DAT_182ec16a0 == (code *)0x0) &&
                   (pcVar4 = (code *)FUN_1802cf0c0(
                                                  "UnityEngine.Transform::set_position_Injected(UnityEngine.Vector3&)"
                                                  ), pcVar4 == (code *)0x0)) {
                  uVar6 = FUN_1802ced60(
                                       "UnityEngine.Transform::set_position_Injected(UnityEngine.Vector3&)"
                                       );
                    /* WARNING: Subroutine does not return */
                  FUN_1802cca90(uVar6,0);
                }
                DAT_182ec16a0 = pcVar4;
                (*DAT_182ec16a0)(lVar5,&uStack_58);
                if (((**(longlong **)(DAT_182d53c48 + 0xb8) != 0) &&
                    (lVar2 = *(longlong *)(**(longlong **)(DAT_182d53c48 + 0xb8) + 0x28), lVar2 != 0
                    )) && (lVar2 = *(longlong *)(lVar2 + 0x38), lVar2 != 0)) {
                  pcVar4 = DAT_182ec1080;
                  if ((DAT_182ec1080 == (code *)0x0) &&
                     (pcVar4 = (code *)FUN_1802cf0c0("UnityEngine.Component::get_transform()"),
                     pcVar4 == (code *)0x0)) {
                    uVar6 = FUN_1802ced60("UnityEngine.Component::get_transform()");
                    /* WARNING: Subroutine does not return */
                    FUN_1802cca90(uVar6,0);
                  }
                  DAT_182ec1080 = pcVar4;
                  lVar5 = (*DAT_182ec1080)(lVar2);
                  lVar2 = *(longlong *)(lVar3 + 0x28);
                  if (lVar2 != 0) {
                    uStack_48 = 0;
                    uStack_40 = 0;
                    pcVar4 = DAT_182ec16b8;
                    if ((DAT_182ec16b8 == (code *)0x0) &&
                       (pcVar4 = (code *)FUN_1802cf0c0(
                                                  "UnityEngine.Transform::get_rotation_Injected(UnityEngine.Quaternion&)"
                                                  ), pcVar4 == (code *)0x0)) {
                      uVar6 = FUN_1802ced60(
                                           "UnityEngine.Transform::get_rotation_Injected(UnityEngine.Quaternion&)"
                                           );
                    /* WARNING: Subroutine does not return */
                      FUN_1802cca90(uVar6,0);
                    }
                    DAT_182ec16b8 = pcVar4;
                    (*DAT_182ec16b8)(lVar2,&uStack_48);
                    lVar2 = *(longlong *)(lVar3 + 0x30);
                    if (lVar2 != 0) {
                      uStack_68 = 0;
                      uStack_60 = 0;
                      pcVar4 = DAT_182ec16b8;
                      if ((DAT_182ec16b8 == (code *)0x0) &&
                         (pcVar4 = (code *)FUN_1802cf0c0(
                                                  "UnityEngine.Transform::get_rotation_Injected(UnityEngine.Quaternion&)"
                                                  ), pcVar4 == (code *)0x0)) {
                        uVar6 = FUN_1802ced60(
                                             "UnityEngine.Transform::get_rotation_Injected(UnityEngine.Quaternion&)"
                                             );
                    /* WARNING: Subroutine does not return */
                        FUN_1802cca90(uVar6,0);
                      }
                      DAT_182ec16b8 = pcVar4;
                      (*DAT_182ec16b8)(lVar2,&uStack_68);
                      uVar1 = *(undefined4 *)(lVar3 + 0x20);
                      uStack_38 = uStack_68;
                      puStack_30 = (undefined *)uStack_60;
                      uStack_28 = (undefined4)uStack_48;
                      uStack_24 = uStack_48._4_4_;
                      uStack_20 = (undefined4)uStack_40;
                      uStack_1c = uStack_40._4_4_;
                      uStack_48 = 0;
                      uStack_40 = 0;
                      pcVar4 = pcRam0000000182ec0e70;
                      if ((pcRam0000000182ec0e70 == (code *)0x0) &&
                         (pcVar4 = (code *)FUN_1802cf0c0(
                                                  "UnityEngine.Quaternion::Slerp_Injected(UnityEngine.Quaternion&,UnityEngine.Quaternion&,System.Single,UnityEngine.Quaternion&)"
                                                  ), pcVar4 == (code *)0x0)) {
                        uVar6 = FUN_1802ced60(
                                             "UnityEngine.Quaternion::Slerp_Injected(UnityEngine.Quaternion&,UnityEngine.Quaternion&,System.Single,UnityEngine.Quaternion&)"
                                             );
                    /* WARNING: Subroutine does not return */
                        FUN_1802cca90(uVar6,0);
                      }
                      pcRam0000000182ec0e70 = pcVar4;
                      (*pcRam0000000182ec0e70)(&uStack_28,&uStack_38,uVar1,&uStack_48);
                      if (lVar5 == 0) {
                    /* WARNING: Subroutine does not return */
                        FUN_18031dad0();
                      }
                      uStack_68 = uStack_48;
                      uStack_60 = uStack_40;
                      pcVar4 = DAT_182ec16c0;
                      if ((DAT_182ec16c0 == (code *)0x0) &&
                         (pcVar4 = (code *)FUN_1802cf0c0(
                                                  "UnityEngine.Transform::set_rotation_Injected(UnityEngine.Quaternion&)"
                                                  ), pcVar4 == (code *)0x0)) {
                        uVar6 = FUN_1802ced60(
                                             "UnityEngine.Transform::set_rotation_Injected(UnityEngine.Quaternion&)"
                                             );
                    /* WARNING: Subroutine does not return */
                        FUN_1802cca90(uVar6,0);
                      }
                      DAT_182ec16c0 = pcVar4;
                      (*DAT_182ec16c0)(lVar5,&uStack_68);
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
    }
  }
                    /* WARNING: Subroutine does not return */
  puStack_30 = &UNK_18049895f;
  FUN_18031dad0();
}

