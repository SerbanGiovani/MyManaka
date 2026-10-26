// Ghidra pseudocode; not original source or compilable C.
// ev_fba38f94b8b633981d189c77ca47ed928850d70569b8a585e26625e8d9b1f27a

float * native_only_1804363f0__00000000(float *param_1,float *param_2,float *param_3,float param_4)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  code *pcVar8;
  undefined8 uVar9;
  float fVar10;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 uStack_40;
  float local_38;
  float fStack_34;
  float fStack_30;
  float fStack_2c;
  
  fVar10 = *param_3;
  fVar1 = param_3[1];
  fVar2 = param_3[2];
  fVar3 = param_3[3];
  fVar4 = *param_2;
  fVar5 = param_2[1];
  fVar6 = param_2[2];
  fVar7 = param_2[3];
  param_1[0] = 0.0;
  param_1[1] = 0.0;
  param_1[2] = 0.0;
  param_1[3] = 0.0;
  fVar10 = ABS(fVar1 * fVar5 + fVar10 * fVar4 + fVar2 * fVar6 + fVar3 * fVar7);
  if (1.0 <= fVar10) {
    fVar10 = 1.0;
  }
  if (fVar10 <= 0.999999) {
    fVar10 = (float)FUN_18039d510(fVar10);
    fVar10 = (fVar10 + fVar10) * 57.29578;
    if (fVar10 != 0.0) {
      param_4 = param_4 / fVar10;
      fVar10 = 1.0;
      if (param_4 <= 1.0) {
        fVar10 = param_4;
      }
      local_48 = *(undefined8 *)param_3;
      uStack_40 = *(undefined8 *)(param_3 + 2);
      local_38 = *param_2;
      fStack_34 = param_2[1];
      fStack_30 = param_2[2];
      fStack_2c = param_2[3];
      local_58 = 0;
      uStack_50 = 0;
      pcVar8 = DAT_182ec0e78;
      if ((DAT_182ec0e78 == (code *)0x0) &&
         (pcVar8 = (code *)FUN_1802cf0c0(
                                        "UnityEngine.Quaternion::SlerpUnclamped_Injected(UnityEngine.Quaternion&,UnityEngine.Quaternion&,System.Single,UnityEngine.Quaternion&)"
                                        ), pcVar8 == (code *)0x0)) {
        uVar9 = FUN_1802ced60(
                             "UnityEngine.Quaternion::SlerpUnclamped_Injected(UnityEngine.Quaternion&,UnityEngine.Quaternion&,System.Single,UnityEngine.Quaternion&)"
                             );
                    /* WARNING: Subroutine does not return */
        FUN_1802cca90(uVar9,0);
      }
      DAT_182ec0e78 = pcVar8;
      (*DAT_182ec0e78)(&local_38,&local_48,fVar10,&local_58);
      goto LAB_18043650d;
    }
  }
  local_58._0_4_ = *param_3;
  local_58._4_4_ = param_3[1];
  uStack_50._0_4_ = param_3[2];
  uStack_50._4_4_ = param_3[3];
LAB_18043650d:
  *param_1 = (float)local_58;
  param_1[1] = local_58._4_4_;
  param_1[2] = (float)uStack_50;
  param_1[3] = uStack_50._4_4_;
  return param_1;
}

