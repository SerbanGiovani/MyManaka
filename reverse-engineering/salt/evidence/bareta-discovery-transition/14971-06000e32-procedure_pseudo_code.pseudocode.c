// Ghidra pseudocode; not original source or compilable C.
// ev_b36db89b142619d20a17ee87d6c4a7cc98183fe6b1494561e592636fbd086f12

float * ExposureUnnoticed2_Object3D_Player_Scripts_PlayerStrangenessController__CalcStrangerDegreeFrom__06000e32
                  (float *param_1,longlong param_2,longlong param_3,undefined8 param_4,
                  undefined8 param_5)

{
  float fVar1;
  longlong lVar2;
  longlong lVar3;
  code *pcVar4;
  code *pcVar5;
  undefined8 uVar6;
  char cVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  undefined8 uStack_68;
  undefined4 uStack_60;
  undefined8 uStack_58;
  undefined4 uStack_50;
  float fStack_48;
  
  if (cRam0000000182eb844b == '\0') {
    FUN_1802f2810(&DAT_182d58398);
    LOCK();
    UNLOCK();
    cRam0000000182eb844b = '\x01';
  }
  param_1[0] = 0.0;
  param_1[1] = 0.0;
  param_1[2] = 0.0;
  param_1[3] = 0.0;
  param_1[4] = 0.0;
  if (param_3 != 0) {
    uStack_68 = 0;
    uStack_60 = 0;
    pcVar5 = DAT_182ec1698;
    if ((DAT_182ec1698 == (code *)0x0) &&
       (pcVar5 = (code *)FUN_1802cf0c0(
                                      "UnityEngine.Transform::get_position_Injected(UnityEngine.Vector3&)"
                                      ), pcVar5 == (code *)0x0)) {
      uVar6 = FUN_1802ced60("UnityEngine.Transform::get_position_Injected(UnityEngine.Vector3&)");
                    /* WARNING: Subroutine does not return */
      FUN_1802cca90(uVar6,0);
    }
    DAT_182ec1698 = pcVar5;
    (*DAT_182ec1698)(param_3,&uStack_68);
    uStack_58 = uStack_68;
    uStack_50 = uStack_60;
    fVar8 = (float)ExposureUnnoticed2_Object3D_Player_Scripts_PlayerStrangenessController__CalcExposeStrange__06000e39
                             (param_2,&uStack_58,0);
    if (((*(longlong *)(param_2 + 0x10) != 0) &&
        (lVar2 = *(longlong *)(*(longlong *)(param_2 + 0x10) + 0x60), lVar2 != 0)) &&
       (lVar2 = *(longlong *)(lVar2 + 0x48), lVar2 != 0)) {
      if (*(int *)(lVar2 + 0x18) == -1) {
        fVar10 = 1.0;
      }
      else {
        fVar10 = *(float *)(*(longlong *)
                             (*(longlong *)(*(longlong *)(param_2 + 0x10) + 0x60) + 0x48) + 0x58);
      }
      fVar1 = *(float *)(*(longlong *)(*(longlong *)(*(longlong *)(param_2 + 0x10) + 0x60) + 0x48) +
                        0x44);
      fVar9 = (float)ExposureUnnoticed2_Object3D_Player_Scripts_PlayerStrangenessController__CalcSightScale__06000e35
                               (param_2,param_3,param_4,param_5,0);
      pcVar5 = DAT_182ec1698;
      if ((*(longlong *)(param_2 + 0x10) != 0) &&
         (lVar2 = *(longlong *)(*(longlong *)(param_2 + 0x10) + 0x60), lVar2 != 0)) {
        uStack_68 = 0;
        uStack_60 = 0;
        *param_1 = (fVar10 * fVar8 + fVar1) * *(float *)(lVar2 + 0x94) * fVar9;
        pcVar4 = DAT_182ec1698;
        if ((pcVar5 == (code *)0x0) &&
           (pcVar5 = (code *)FUN_1802cf0c0(
                                          "UnityEngine.Transform::get_position_Injected(UnityEngine.Vector3&)"
                                          ), pcVar4 = pcVar5, pcVar5 == (code *)0x0)) {
          uVar6 = FUN_1802ced60("UnityEngine.Transform::get_position_Injected(UnityEngine.Vector3&)"
                               );
                    /* WARNING: Subroutine does not return */
          FUN_1802cca90(uVar6,0);
        }
        DAT_182ec1698 = pcVar4;
        (*pcVar5)(param_3,&uStack_68);
        uStack_58 = uStack_68;
        uStack_50 = uStack_60;
        fVar8 = (float)ExposureUnnoticed2_Object3D_Player_Scripts_PlayerStrangenessController__CalcMaxDiscomfort__06000e36
                                 (param_2,&uStack_58,0);
        *param_1 = *param_1;
        param_1[1] = param_1[1];
        param_1[2] = fVar8;
        param_1[3] = param_1[3];
        pcVar5 = DAT_182ec1698;
        fStack_48 = param_1[4];
        if ((*(longlong *)(param_2 + 0x10) != 0) &&
           (lVar2 = *(longlong *)(*(longlong *)(param_2 + 0x10) + 0x60), lVar2 != 0)) {
          uStack_68 = 0;
          uStack_60 = 0;
          param_1[1] = fVar8 * *(float *)(lVar2 + 0x94) * fVar9;
          pcVar4 = DAT_182ec1698;
          if ((pcVar5 == (code *)0x0) &&
             (pcVar5 = (code *)FUN_1802cf0c0(
                                            "UnityEngine.Transform::get_position_Injected(UnityEngine.Vector3&)"
                                            ), pcVar4 = pcVar5, pcVar5 == (code *)0x0)) {
            uVar6 = FUN_1802ced60(
                                 "UnityEngine.Transform::get_position_Injected(UnityEngine.Vector3&)"
                                 );
                    /* WARNING: Subroutine does not return */
            FUN_1802cca90(uVar6,0);
          }
          DAT_182ec1698 = pcVar4;
          (*pcVar5)(param_3,&uStack_68);
          uStack_58 = uStack_68;
          uStack_50 = uStack_60;
          fVar8 = (float)ExposureUnnoticed2_Object3D_Player_Scripts_PlayerStrangenessController__CalcNoisy__06000e34
                                   (param_2,&uStack_58,0);
          lVar2 = DAT_182d58398;
          param_1[3] = fVar8;
          param_1[4] = fVar9;
          lVar2 = *(longlong *)(*(longlong *)(lVar2 + 0xb8) + 0x48);
          if (lVar2 != 0) {
            if (*(char *)(lVar2 + 0x1dd) != '\0') {
              param_1[1] = 0.0;
              param_1[2] = 0.0;
              *param_1 = 0.0;
            }
            if ((*(longlong *)(param_2 + 0x10) != 0) &&
               (lVar2 = *(longlong *)(*(longlong *)(param_2 + 0x10) + 0x60), lVar2 != 0)) {
              lVar3 = *(longlong *)(*(longlong *)(param_2 + 0x10) + 0x60);
              if (*(char *)(lVar3 + 0x8b) == '\0') {
                cVar7 = *(char *)(lVar3 + 0x8a);
              }
              else {
                cVar7 = '\x01';
              }
              *(bool *)(lVar2 + 0x8c) = *(char *)(lVar2 + 0x8c) != '\0' || cVar7 != '\0';
              return param_1;
            }
          }
        }
      }
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

