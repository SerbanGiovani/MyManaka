// Ghidra pseudocode; not original source or compilable C.
// ev_f4a84c54965dd7e464e78f2543e9e1989eb0c4858511516dc2ff85fc376f5948

float ExposureUnnoticed2_Object3D_Camera_TPCameraController__CalcCameraDistance__06001216
                (longlong param_1,undefined8 *param_2)

{
  undefined4 uVar1;
  uint uVar2;
  char cVar3;
  code *pcVar4;
  undefined8 uVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  float fVar12;
  float fVar13;
  float fVar14;
  float fVar15;
  float fVar16;
  float fVar17;
  float fVar18;
  float fVar19;
  float afStackX_20 [2];
  undefined8 uStack_108;
  float fStack_100;
  undefined8 uStack_f8;
  undefined8 uStack_f0;
  undefined8 uStack_e8;
  undefined8 uStack_e0;
  undefined8 uStack_d8;
  undefined8 uStack_d0;
  undefined8 uStack_c8;
  undefined4 uStack_c0;
  
  if (cRam0000000182eb7828 == '\0') {
    FUN_1802f2810(0x182d55a30);
    LOCK();
    UNLOCK();
    cRam0000000182eb7828 = '\x01';
  }
  uStack_c8 = 0;
  uStack_c0 = 0;
  uStack_e8 = 0;
  uStack_e0 = 0;
  uStack_d8 = 0;
  uStack_d0 = 0;
  fStack_100 = 0.0;
  uStack_108 = CONCAT44(*(float *)(param_1 + 0x2c) * 0.017453292,
                        *(float *)(param_1 + 0x30) * 0.017453292);
  uStack_f8 = 0;
  uStack_f0 = 0;
  pcVar4 = DAT_182ec0e88;
  if ((DAT_182ec0e88 == (code *)0x0) &&
     (pcVar4 = (code *)FUN_1802cf0c0(
                                    "UnityEngine.Quaternion::Internal_FromEulerRad_Injected(UnityEngine.Vector3&,UnityEngine.Quaternion&)"
                                    ), pcVar4 == (code *)0x0)) {
    uVar5 = FUN_1802ced60(
                         "UnityEngine.Quaternion::Internal_FromEulerRad_Injected(UnityEngine.Vector3&,UnityEngine.Quaternion&)"
                         );
                    /* WARNING: Subroutine does not return */
    FUN_1802cca90(uVar5,0);
  }
  DAT_182ec0e88 = pcVar4;
  (*DAT_182ec0e88)(&uStack_108,&uStack_f8);
  if (DAT_182eb547b == '\0') {
    FUN_1802f2810(&DAT_182d522a8);
    LOCK();
    UNLOCK();
    DAT_182eb547b = '\x01';
  }
  fVar6 = (float)uStack_f0 + (float)uStack_f0;
  fVar8 = uStack_f8._4_4_ + uStack_f8._4_4_;
  fVar16 = (float)uStack_f8 * ((float)uStack_f8 + (float)uStack_f8);
  afStackX_20[0] = (float)uStack_f8 * fVar6;
  fVar12 = (float)uStack_f0 * fVar6;
  uVar5 = *(undefined8 *)(*(longlong *)(DAT_182d522a8 + 0xb8) + 0x48);
  fVar18 = (float)uVar5;
  fVar15 = uStack_f8._4_4_ * fVar8;
  fVar10 = (float)uStack_f8 * fVar8;
  fVar17 = uStack_f8._4_4_ * fVar6;
  fVar13 = uStack_f0._4_4_ * ((float)uStack_f8 + (float)uStack_f8);
  fVar6 = uStack_f0._4_4_ * fVar6;
  fVar19 = *(float *)(*(longlong *)(DAT_182d522a8 + 0xb8) + 0x50);
  uStack_f8._4_4_ = (float)((ulonglong)uVar5 >> 0x20);
  fVar11 = afStackX_20[0] - uStack_f0._4_4_ * fVar8;
  fVar7 = (fVar10 - fVar6) * uStack_f8._4_4_;
  fVar8 = uStack_f0._4_4_ * fVar8 + afStackX_20[0];
  fVar9 = (1.0 - (fVar12 + fVar16)) * uStack_f8._4_4_;
  fVar14 = (fVar13 + fVar17) * uStack_f8._4_4_;
  uVar1 = *(undefined4 *)(param_1 + 0x28);
  uVar2 = *(uint *)(param_1 + 0x48);
  uStack_f8 = uVar5;
  if (*(int *)(lRam0000000182d55a30 + 0xe0) == 0) {
    FUN_18035c820();
  }
  if (cRam0000000182ec3721 == '\0') {
    FUN_1802f2810(0x182d55a30);
    LOCK();
    UNLOCK();
    cRam0000000182ec3721 = '\x01';
  }
  if (*(int *)(lRam0000000182d55a30 + 0xe0) == 0) {
    FUN_18035c820();
  }
  afStackX_20[0] = (float)FUN_181fb32b0(0);
  uStack_108 = CONCAT44((fVar9 + (fVar6 + fVar10) * fVar18 + (fVar17 - fVar13) * fVar19) * -1.0,
                        ((1.0 - (fVar12 + fVar15)) * fVar18 + fVar7 + fVar8 * fVar19) * -1.0);
  uStack_f8 = *param_2;
  uStack_f0 = CONCAT44(uStack_f0._4_4_,*(undefined4 *)(param_2 + 1));
  fStack_100 = (fVar11 * fVar18 + fVar14 + (1.0 - (fVar15 + fVar16)) * fVar19) * -1.0;
  cVar3 = FUN_181fbacd0(afStackX_20,&uStack_f8,0x3d4ccccd,&uStack_108,&uStack_e8,uVar1,~uVar2,1,0);
  fVar19 = 3.4028235e+38;
  if (cVar3 != '\0') {
    fVar19 = uStack_d0._4_4_;
  }
  if (*(float *)(param_1 + 0x28) <= fVar19) {
    fVar19 = *(float *)(param_1 + 0x28);
  }
  return fVar19;
}

