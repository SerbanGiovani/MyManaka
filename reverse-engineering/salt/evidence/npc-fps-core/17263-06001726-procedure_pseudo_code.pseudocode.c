// Ghidra pseudocode; not original source or compilable C.
// ev_3aa2c3b49f4c232a60298740b38f386bfd3b434a726344de2cad763c00490ac4

void ExposureUnnoticed2_Scripts_Base_ExternalMethodManager__DistSqrt__06001726
               (longlong param_1,longlong param_2)

{
  code *pcVar1;
  longlong lVar2;
  undefined8 uVar3;
  undefined8 uStack_28;
  float fStack_20;
  undefined8 uStack_18;
  float fStack_10;
  
  if (param_1 != 0) {
    pcVar1 = DAT_182ec1120;
    if ((DAT_182ec1120 == (code *)0x0) &&
       (pcVar1 = (code *)FUN_1802cf0c0("UnityEngine.GameObject::get_transform()"),
       pcVar1 == (code *)0x0)) {
      uVar3 = FUN_1802ced60("UnityEngine.GameObject::get_transform()");
                    /* WARNING: Subroutine does not return */
      FUN_1802cca90(uVar3,0);
    }
    DAT_182ec1120 = pcVar1;
    lVar2 = (*DAT_182ec1120)(param_1);
    if (lVar2 != 0) {
      uStack_28 = 0;
      fStack_20 = 0.0;
      pcVar1 = DAT_182ec1698;
      if ((DAT_182ec1698 == (code *)0x0) &&
         (pcVar1 = (code *)FUN_1802cf0c0(
                                        "UnityEngine.Transform::get_position_Injected(UnityEngine.Vector3&)"
                                        ), pcVar1 == (code *)0x0)) {
        uVar3 = FUN_1802ced60("UnityEngine.Transform::get_position_Injected(UnityEngine.Vector3&)");
                    /* WARNING: Subroutine does not return */
        FUN_1802cca90(uVar3,0);
      }
      DAT_182ec1698 = pcVar1;
      (*DAT_182ec1698)(lVar2,&uStack_28);
      if (param_2 != 0) {
        pcVar1 = DAT_182ec1120;
        if ((DAT_182ec1120 == (code *)0x0) &&
           (pcVar1 = (code *)FUN_1802cf0c0("UnityEngine.GameObject::get_transform()"),
           pcVar1 == (code *)0x0)) {
          uVar3 = FUN_1802ced60("UnityEngine.GameObject::get_transform()");
                    /* WARNING: Subroutine does not return */
          FUN_1802cca90(uVar3,0);
        }
        DAT_182ec1120 = pcVar1;
        lVar2 = (*DAT_182ec1120)(param_2);
        if (lVar2 != 0) {
          uStack_18 = 0;
          fStack_10 = 0.0;
          pcVar1 = DAT_182ec1698;
          if ((DAT_182ec1698 == (code *)0x0) &&
             (pcVar1 = (code *)FUN_1802cf0c0(
                                            "UnityEngine.Transform::get_position_Injected(UnityEngine.Vector3&)"
                                            ), pcVar1 == (code *)0x0)) {
            uVar3 = FUN_1802ced60(
                                 "UnityEngine.Transform::get_position_Injected(UnityEngine.Vector3&)"
                                 );
                    /* WARNING: Subroutine does not return */
            FUN_1802cca90(uVar3,0);
          }
          DAT_182ec1698 = pcVar1;
          (*DAT_182ec1698)(lVar2,&uStack_18);
          fStack_10 = fStack_20 - fStack_10;
          uStack_18 = CONCAT44(uStack_28._4_4_ - uStack_18._4_4_,(float)uStack_28 - (float)uStack_18
                              );
          FUN_1803d4630(&uStack_18);
          return;
        }
      }
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

