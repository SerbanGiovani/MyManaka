// Ghidra pseudocode; not original source or compilable C.
// ev_fa05c3aa5ce13e062ec90dccd6f43c9f2c1f94d4a8eb5e410bbfdaa3b539bfe0

void ExposureUnnoticed2_ObjectUI_InGame_RingMenu_RingMenuView__AngleUpdate__06001ad2
               (longlong param_1)

{
  float fVar1;
  float fVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  longlong lVar5;
  undefined8 uVar6;
  code *pcVar7;
  bool bVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  float fVar12;
  undefined8 uStackX_18;
  undefined8 uStackX_20;
  undefined8 uStack_b8;
  undefined4 uStack_b0;
  undefined8 uStack_a8;
  undefined8 uStack_a0;
  undefined4 uStack_98;
  undefined4 uStack_94;
  undefined4 uStack_90;
  undefined4 uStack_8c;
  
  if (cRam0000000182eb7cc0 == '\0') {
    FUN_1802f2810(&DAT_182d5aa88);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d64918);
    LOCK();
    UNLOCK();
    cRam0000000182eb7cc0 = '\x01';
  }
  uStackX_18 = 0;
  if (*(int *)(DAT_182d5aa88 + 0xe0) == 0) {
    FUN_18035c820();
  }
  uStackX_18 = ExposureUnnoticed2_Scripts_Base_InputManager__GetVector2__06001704(1,0);
  uStackX_20._0_4_ = (float)uStackX_18;
  fVar11 = (float)uStackX_20;
  uStackX_20._4_4_ = (float)((ulonglong)uStackX_18 >> 0x20);
  fVar10 = uStackX_20._4_4_;
  uStackX_20 = uStackX_18;
  if (DAT_182eb54a5 == '\0') {
    FUN_1802f2810(&DAT_182d5aa88);
    LOCK();
    UNLOCK();
    DAT_182eb54a5 = '\x01';
  }
  if (*(int *)(DAT_182d5aa88 + 0xe0) == 0) {
    FUN_18035c820(DAT_182d5aa88);
  }
  if (*(char *)(*(longlong *)(DAT_182d5aa88 + 0xb8) + 8) != '\0') {
    fVar11 = fVar11 * 1000.0;
    fVar10 = fVar10 * 1000.0;
    uStackX_18 = CONCAT44(fVar10,fVar11);
  }
  if (0.01 <= fVar10 * fVar10 + fVar11 * fVar11) {
    uVar6 = FUN_180525090(&uStackX_18);
    uStackX_18._0_4_ = (float)uVar6;
    uStackX_18._4_4_ = (float)((ulonglong)uVar6 >> 0x20);
    fVar12 = -(uStackX_18._4_4_ * *(float *)(param_1 + 0x68) +
              (float)uStackX_18 * *(float *)(param_1 + 100)) + 1.0;
    if (fVar12 < 0.0) {
      fVar12 = 0.0;
    }
    else if (1.0 < fVar12) {
      fVar12 = 1.0;
    }
    fVar1 = *(float *)(param_1 + 100);
    fVar2 = *(float *)(param_1 + 0x68);
    pcVar7 = DAT_182ec14d0;
    uStackX_18 = uVar6;
    if ((DAT_182ec14d0 == (code *)0x0) &&
       (pcVar7 = (code *)FUN_1802cf0c0("UnityEngine.Time::get_deltaTime()"), pcVar7 == (code *)0x0))
    {
      uVar6 = FUN_1802ced60("UnityEngine.Time::get_deltaTime()");
                    /* WARNING: Subroutine does not return */
      FUN_1802cca90(uVar6,0);
    }
    DAT_182ec14d0 = pcVar7;
    fVar9 = (float)(*DAT_182ec14d0)();
    *(float *)(param_1 + 100) = fVar11 * 7.0 * fVar9 * fVar12 + fVar1;
    *(float *)(param_1 + 0x68) = fVar10 * 7.0 * fVar9 * fVar12 + fVar2;
    if (1.0 < fVar10 * fVar10 + fVar11 * fVar11) {
      FUN_1803fa080(param_1 + 100);
    }
    uVar3 = *(undefined4 *)(param_1 + 100);
    uVar4 = *(undefined4 *)(param_1 + 0x68);
    if (*(int *)(DAT_182d64918 + 0xe0) == 0) {
      FUN_18035c820();
    }
    fVar11 = (float)func_0x00018039e2b0(uVar4,uVar3);
    bVar8 = DAT_182eb547b == '\0';
    *(float *)(param_1 + 0x6c) = fVar11 * 57.29578;
    lVar5 = *(longlong *)(param_1 + 0x20);
    if (bVar8) {
      FUN_1802f2810(&DAT_182d522a8);
      LOCK();
      UNLOCK();
      DAT_182eb547b = '\x01';
    }
    uStack_b8 = *(undefined8 *)(*(longlong *)(DAT_182d522a8 + 0xb8) + 0x48);
    uStack_b0 = *(undefined4 *)(*(longlong *)(DAT_182d522a8 + 0xb8) + 0x50);
    uStack_a8 = 0;
    uStack_a0 = 0;
    pcVar7 = DAT_182ec0ea0;
    if ((DAT_182ec0ea0 == (code *)0x0) &&
       (pcVar7 = (code *)FUN_1802cf0c0(
                                      "UnityEngine.Quaternion::AngleAxis_Injected(System.Single,UnityEngine.Vector3&,UnityEngine.Quaternion&)"
                                      ), pcVar7 == (code *)0x0)) {
      uVar6 = FUN_1802ced60(
                           "UnityEngine.Quaternion::AngleAxis_Injected(System.Single,UnityEngine.Vector3&,UnityEngine.Quaternion&)"
                           );
                    /* WARNING: Subroutine does not return */
      FUN_1802cca90(uVar6,0);
    }
    DAT_182ec0ea0 = pcVar7;
    (*DAT_182ec0ea0)(fVar11 * 57.29578 - 90.0,&uStack_b8,&uStack_a8);
    if (lVar5 == 0) {
                    /* WARNING: Subroutine does not return */
      FUN_18031dad0();
    }
    uStack_98 = (undefined4)uStack_a8;
    uStack_94 = uStack_a8._4_4_;
    uStack_90 = (undefined4)uStack_a0;
    uStack_8c = uStack_a0._4_4_;
    pcVar7 = DAT_182ec16c0;
    if ((DAT_182ec16c0 == (code *)0x0) &&
       (pcVar7 = (code *)FUN_1802cf0c0(
                                      "UnityEngine.Transform::set_rotation_Injected(UnityEngine.Quaternion&)"
                                      ), pcVar7 == (code *)0x0)) {
      uVar6 = FUN_1802ced60("UnityEngine.Transform::set_rotation_Injected(UnityEngine.Quaternion&)")
      ;
                    /* WARNING: Subroutine does not return */
      FUN_1802cca90(uVar6,0);
    }
    DAT_182ec16c0 = pcVar7;
    (*DAT_182ec16c0)(lVar5,&uStack_98);
  }
  return;
}

