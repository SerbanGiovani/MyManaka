// Ghidra pseudocode; not original source or compilable C.
// ev_a19fc917b5d13e860241f78dd6018c03294af460dd28ff0bf9fa1cd4a193f191

void ExposureUnnoticed2_Object3D_Player_Scripts_PlayerLocomotion__OnUpdate__06000dea
               (longlong param_1,longlong param_2)

{
  undefined8 uVar1;
  char cVar2;
  char cVar3;
  int iVar4;
  longlong lVar5;
  ulonglong *puVar6;
  undefined8 *puVar7;
  code *pcVar8;
  undefined8 *puVar9;
  longlong lVar10;
  undefined8 uVar11;
  ulonglong uVar12;
  int iVar13;
  undefined4 uVar14;
  float fVar15;
  float fVar16;
  undefined4 uVar17;
  float fVar18;
  float fVar19;
  undefined4 uVar20;
  float fVar21;
  float fVar22;
  float fVar23;
  float fVar24;
  float fVar25;
  float fVar26;
  float fVar27;
  float fVar28;
  float fStackX_10;
  float fStackX_20;
  undefined8 in_stack_fffffffffffffe88;
  undefined4 uVar29;
  undefined8 uStack_168;
  float fStack_160;
  undefined4 uStack_15c;
  ulonglong uStack_158;
  float fStack_150;
  undefined8 uStack_148;
  undefined8 uStack_140;
  undefined8 uStack_138;
  undefined8 uStack_130;
  float fStack_128;
  undefined8 uStack_118;
  ulonglong uStack_110;
  float fStack_108;
  undefined4 uStack_f8;
  undefined4 uStack_f4;
  undefined4 uStack_f0;
  undefined4 uStack_ec;
  undefined1 auStack_e8 [176];
  
  uVar29 = (undefined4)((ulonglong)in_stack_fffffffffffffe88 >> 0x20);
  if (cRam0000000182eb8420 == '\0') {
    FUN_1802f2810(&DAT_182d59ac8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d58288);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d58398);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d53c48);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d5aa88);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d53aa8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d58378);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d58230);
    LOCK();
    UNLOCK();
    cRam0000000182eb8420 = '\x01';
  }
  *(int *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) + -1;
  puVar7 = (undefined8 *)0x0;
  ExposureUnnoticed2_Object3D_Player_Scripts_PlayerLocomotion__StateUpdate__06000dec
            (param_1,param_2,0);
  if ((*(longlong *)(param_1 + 0x78) == 0) ||
     (lVar5 = *(longlong *)(*(longlong *)(param_1 + 0x78) + 0x60), lVar5 == 0))
  goto code_r0x0001806538d3;
  if (*(char *)(lVar5 + 0x1b0) == '\0') {
    if (*(char *)(*(longlong *)(*(longlong *)(param_1 + 0x78) + 0x60) + 0x1b1) != '\0') {
      if (*(int *)(DAT_182d5aa88 + 0xe0) == 0) {
        FUN_18035c820();
      }
      cVar2 = ExposureUnnoticed2_Scripts_Base_InputManager__IsDown__06001708(0xd,0);
      if (cVar2 == '\0') {
        if ((*(longlong *)(param_1 + 0x78) == 0) ||
           (lVar5 = *(longlong *)(*(longlong *)(param_1 + 0x78) + 0x60), lVar5 == 0))
        goto code_r0x0001806538d3;
        if (*(char *)(lVar5 + 0x1a) != '\0') goto code_r0x000180651e47;
        if ((*(longlong *)(param_1 + 0x60) == 0) ||
           (lVar5 = FUN_181f3e980(*(longlong *)(param_1 + 0x60),0), lVar5 == 0))
        goto code_r0x0001806538d3;
        puVar6 = (ulonglong *)FUN_181f4b9a0(&uStack_168,lVar5,0);
        uStack_158 = *puVar6;
        fVar19 = *(float *)(puVar6 + 1);
        if ((*(longlong *)(param_1 + 0x38) == 0) ||
           (lVar5 = FUN_181d769d0(*(longlong *)(param_1 + 0x38),0), lVar5 == 0))
        goto code_r0x0001806538d3;
        puVar6 = (ulonglong *)FUN_181f4b9a0(&uStack_168,lVar5,0);
        uVar12 = *puVar6;
        fStack_160 = fVar19 - *(float *)(puVar6 + 1);
        fVar19 = (float)uStack_158 - (float)uVar12;
        uStack_158 = uVar12;
        if (*(int *)(DAT_182d58288 + 0xe0) == 0) {
          FUN_18035c820();
        }
        uStack_168 = (ulonglong)(uint)fVar19;
        puVar7 = (undefined8 *)FUN_181f31160(&uStack_f8,&uStack_168,0);
        uStack_148 = 0;
        uStack_140 = 0;
        uStack_138 = *puVar7;
        uStack_130 = puVar7[1];
        pcVar8 = DAT_182ec0e68;
        if ((DAT_182ec0e68 == (code *)0x0) &&
           (pcVar8 = (code *)FUN_1802cf0c0(
                                          "UnityEngine.Quaternion::Inverse_Injected(UnityEngine.Quaternion&,UnityEngine.Quaternion&)"
                                          ), pcVar8 == (code *)0x0)) {
          uVar11 = FUN_1802ced60(
                                "UnityEngine.Quaternion::Inverse_Injected(UnityEngine.Quaternion&,UnityEngine.Quaternion&)"
                                );
                    /* WARNING: Subroutine does not return */
          FUN_1802cca90(uVar11,0);
        }
        DAT_182ec0e68 = pcVar8;
        (*DAT_182ec0e68)(&uStack_138,&uStack_148);
        if ((*(longlong *)(param_1 + 0x78) == 0) ||
           (lVar5 = *(longlong *)(*(longlong *)(param_1 + 0x78) + 0x18), lVar5 == 0))
        goto code_r0x0001806538d3;
        puVar6 = (ulonglong *)FUN_181f4c360(&uStack_158,lVar5,0);
        puVar7 = &uStack_168;
        uStack_168 = *puVar6;
        fStack_160 = *(float *)(puVar6 + 1);
        puVar9 = (undefined8 *)FUN_181f31290(&uStack_158,&uStack_148,puVar7,0);
        uVar14 = (undefined4)*puVar9;
        uVar17 = (undefined4)((ulonglong)*puVar9 >> 0x20);
        uVar20 = *(undefined4 *)(puVar9 + 1);
      }
      else {
code_r0x000180651e47:
        if (DAT_182eb547b == '\0') {
          FUN_1802f2810(&DAT_182d522a8);
          LOCK();
          UNLOCK();
          DAT_182eb547b = '\x01';
        }
        uVar11 = *(undefined8 *)(*(longlong *)(DAT_182d522a8 + 0xb8) + 0x48);
        uVar14 = (undefined4)uVar11;
        uVar17 = (undefined4)((ulonglong)uVar11 >> 0x20);
        uVar20 = *(undefined4 *)(*(longlong *)(DAT_182d522a8 + 0xb8) + 0x50);
      }
      if (param_2 == 0) goto code_r0x0001806538d3;
      goto code_r0x0001806521b7;
    }
    if (param_2 == 0) goto code_r0x0001806538d3;
    if (*(char *)(param_2 + 0x28) != '\0') {
      if (*(int *)(DAT_182d5aa88 + 0xe0) == 0) {
        FUN_18035c820();
      }
      cVar2 = ExposureUnnoticed2_Scripts_Base_InputManager__IsDown__06001708(0xd,0);
      if (cVar2 == '\0') {
        if ((*(longlong *)(param_1 + 0x78) == 0) ||
           (lVar5 = *(longlong *)(*(longlong *)(param_1 + 0x78) + 0x60), lVar5 == 0))
        goto code_r0x0001806538d3;
        if (*(char *)(lVar5 + 0x1a) == '\0') {
          if ((*(longlong *)(param_1 + 0x60) == 0) ||
             (lVar5 = FUN_181f3e980(*(longlong *)(param_1 + 0x60),0), lVar5 == 0))
          goto code_r0x0001806538d3;
          puVar6 = (ulonglong *)FUN_181f4b9a0(&uStack_168,lVar5,0);
          uStack_158 = *puVar6;
          fVar19 = *(float *)(puVar6 + 1);
          if ((*(longlong *)(param_1 + 0x38) == 0) ||
             (lVar5 = FUN_181d769d0(*(longlong *)(param_1 + 0x38),0), lVar5 == 0))
          goto code_r0x0001806538d3;
          puVar6 = (ulonglong *)FUN_181f4b9a0(&uStack_168,lVar5,0);
          uVar12 = *puVar6;
          fStack_160 = fVar19 - *(float *)(puVar6 + 1);
          fVar19 = (float)uStack_158 - (float)uVar12;
          uStack_158 = uVar12;
          if (*(int *)(DAT_182d58288 + 0xe0) == 0) {
            FUN_18035c820();
          }
          uStack_168 = (ulonglong)(uint)fVar19;
          puVar7 = (undefined8 *)FUN_181f31160(&uStack_f8,&uStack_168,0);
          uStack_148 = 0;
          uStack_140 = 0;
          uStack_138 = *puVar7;
          uStack_130 = puVar7[1];
          pcVar8 = DAT_182ec0e68;
          if ((DAT_182ec0e68 == (code *)0x0) &&
             (pcVar8 = (code *)FUN_1802cf0c0(
                                            "UnityEngine.Quaternion::Inverse_Injected(UnityEngine.Quaternion&,UnityEngine.Quaternion&)"
                                            ), pcVar8 == (code *)0x0)) {
            uVar11 = FUN_1802ced60(
                                  "UnityEngine.Quaternion::Inverse_Injected(UnityEngine.Quaternion&,UnityEngine.Quaternion&)"
                                  );
                    /* WARNING: Subroutine does not return */
            FUN_1802cca90(uVar11,0);
          }
          DAT_182ec0e68 = pcVar8;
          (*DAT_182ec0e68)(&uStack_138,&uStack_148);
          if ((*(longlong *)(param_1 + 0x78) == 0) ||
             (lVar5 = *(longlong *)(*(longlong *)(param_1 + 0x78) + 0x18), lVar5 == 0))
          goto code_r0x0001806538d3;
          puVar6 = (ulonglong *)FUN_181f4c360(&uStack_158,lVar5,0);
          puVar7 = &uStack_168;
          uStack_168 = *puVar6;
          fStack_160 = *(float *)(puVar6 + 1);
          puVar9 = (undefined8 *)FUN_181f31290(&uStack_158,&uStack_148,puVar7,0);
          uVar20 = *(undefined4 *)(puVar9 + 1);
          goto code_r0x0001806521b3;
        }
      }
      puVar9 = (undefined8 *)FUN_1803d4a40(&uStack_158);
      uVar20 = *(undefined4 *)(puVar9 + 1);
      goto code_r0x0001806521b3;
    }
  }
  else {
    lVar5 = *(longlong *)(param_1 + 0x68);
    if (lVar5 == 0) goto code_r0x0001806538d3;
    if (*(longlong *)(lVar5 + 0x30) == 0) {
      if ((*(longlong *)(param_1 + 0x78) == 0) ||
         (lVar5 = *(longlong *)(*(longlong *)(param_1 + 0x78) + 0x60), lVar5 == 0))
      goto code_r0x0001806538d3;
      if ((*(longlong *)(lVar5 + 0x20) != 0) &&
         (*(float *)(*(longlong *)(*(longlong *)(param_1 + 0x78) + 0x60) + 0x84) <= 5.0)) {
        lVar5 = *(longlong *)(param_1 + 0x68);
        if (lVar5 == 0) goto code_r0x0001806538d3;
        *(undefined8 *)(lVar5 + 0x30) =
             *(undefined8 *)(*(longlong *)(*(longlong *)(param_1 + 0x78) + 0x60) + 0x20);
        goto code_r0x000180651f3f;
      }
    }
    else {
      uVar11 = *(undefined8 *)(*(longlong *)(lVar5 + 0x30) + 0x10);
      if (*(longlong *)(param_1 + 0x78) == 0) goto code_r0x0001806538d3;
      uVar1 = *(undefined8 *)(*(longlong *)(param_1 + 0x78) + 0x18);
      if (*(int *)(DAT_182d58288 + 0xe0) == 0) {
        FUN_18035c820();
      }
      puVar7 = (undefined8 *)0x0;
      fVar19 = (float)ExposureUnnoticed2_Scripts_Base_ExternalMethodManager__DistSqrt__06001728
                                (uVar11,uVar1,0);
      if (5.0 < fVar19) {
        lVar5 = *(longlong *)(param_1 + 0x68);
        if (lVar5 == 0) goto code_r0x0001806538d3;
        *(undefined8 *)(lVar5 + 0x30) = 0;
code_r0x000180651f3f:
        FUN_18031d480(lVar5 + 0x30);
      }
    }
    lVar5 = *(longlong *)(param_1 + 0x68);
    if (lVar5 == 0) goto code_r0x0001806538d3;
    if (*(longlong *)(lVar5 + 0x30) == 0) goto code_r0x0001806521bf;
    if (*(char *)(lVar5 + 0x1a) == '\0') {
      if ((*(longlong *)(param_1 + 0x60) == 0) ||
         (lVar5 = FUN_181f3e980(*(longlong *)(param_1 + 0x60),0), lVar5 == 0))
      goto code_r0x0001806538d3;
      puVar6 = (ulonglong *)FUN_181f4b9a0(&uStack_168,lVar5,0);
      uStack_158 = *puVar6;
      fVar19 = *(float *)(puVar6 + 1);
      if ((*(longlong *)(param_1 + 0x38) == 0) ||
         (lVar5 = FUN_181d769d0(*(longlong *)(param_1 + 0x38),0), lVar5 == 0))
      goto code_r0x0001806538d3;
      uStack_118 = 0;
      uStack_110 = uStack_110 & 0xffffffff00000000;
      pcVar8 = DAT_182ec1698;
      if ((DAT_182ec1698 == (code *)0x0) &&
         (pcVar8 = (code *)FUN_1802cf0c0(
                                        "UnityEngine.Transform::get_position_Injected(UnityEngine.Vector3&)"
                                        ), pcVar8 == (code *)0x0)) {
        uVar11 = FUN_1802ced60("UnityEngine.Transform::get_position_Injected(UnityEngine.Vector3&)")
        ;
                    /* WARNING: Subroutine does not return */
        FUN_1802cca90(uVar11,0);
      }
      DAT_182ec1698 = pcVar8;
      (*DAT_182ec1698)(lVar5,&uStack_118);
      fVar15 = (float)uStack_158 - (float)uStack_118;
      fStack_160 = fVar19 - (float)uStack_110;
      if (*(int *)(DAT_182d58288 + 0xe0) == 0) {
        FUN_18035c820();
      }
      uStack_168 = (ulonglong)(uint)fVar15;
      puVar7 = (undefined8 *)FUN_181f31160(&uStack_f8,&uStack_168,0);
      uStack_148 = 0;
      uStack_140 = 0;
      uStack_138 = *puVar7;
      uStack_130 = puVar7[1];
      pcVar8 = DAT_182ec0e68;
      if ((DAT_182ec0e68 == (code *)0x0) &&
         (pcVar8 = (code *)FUN_1802cf0c0(
                                        "UnityEngine.Quaternion::Inverse_Injected(UnityEngine.Quaternion&,UnityEngine.Quaternion&)"
                                        ), pcVar8 == (code *)0x0)) {
        uVar11 = FUN_1802ced60(
                              "UnityEngine.Quaternion::Inverse_Injected(UnityEngine.Quaternion&,UnityEngine.Quaternion&)"
                              );
                    /* WARNING: Subroutine does not return */
        FUN_1802cca90(uVar11,0);
      }
    }
    else {
      if ((*(longlong *)(param_1 + 0x78) == 0) ||
         (lVar5 = *(longlong *)(*(longlong *)(param_1 + 0x78) + 0x18), lVar5 == 0))
      goto code_r0x0001806538d3;
      puVar6 = (ulonglong *)FUN_181f4c360(&uStack_158,lVar5,0);
      uStack_168 = *puVar6;
      fStack_160 = *(float *)(puVar6 + 1);
      puVar7 = (undefined8 *)FUN_181f31160(&uStack_f8,&uStack_168,0);
      uStack_148 = 0;
      uStack_140 = 0;
      uStack_138 = *puVar7;
      uStack_130 = puVar7[1];
      pcVar8 = DAT_182ec0e68;
      if ((DAT_182ec0e68 == (code *)0x0) &&
         (pcVar8 = (code *)FUN_1802cf0c0(
                                        "UnityEngine.Quaternion::Inverse_Injected(UnityEngine.Quaternion&,UnityEngine.Quaternion&)"
                                        ), pcVar8 == (code *)0x0)) {
        uVar11 = FUN_1802ced60(
                              "UnityEngine.Quaternion::Inverse_Injected(UnityEngine.Quaternion&,UnityEngine.Quaternion&)"
                              );
                    /* WARNING: Subroutine does not return */
        FUN_1802cca90(uVar11,0);
      }
    }
    DAT_182ec0e68 = pcVar8;
    (*DAT_182ec0e68)(&uStack_138,&uStack_148);
    if ((((*(longlong *)(param_1 + 0x78) == 0) ||
         (lVar5 = *(longlong *)(*(longlong *)(param_1 + 0x78) + 0x60), lVar5 == 0)) ||
        (lVar5 = *(longlong *)(lVar5 + 0x30), lVar5 == 0)) ||
       (lVar5 = *(longlong *)(lVar5 + 0x10), lVar5 == 0)) goto code_r0x0001806538d3;
    puVar7 = (undefined8 *)FUN_181f4b9a0(&uStack_158,lVar5,0);
    uStack_168 = *puVar7;
    fStack_160 = *(float *)(puVar7 + 1);
    puVar6 = (ulonglong *)
             ExposureUnnoticed2_Object3D_Player_Scripts_PlayerLocomotion__CalcAutoChaseDirect__06000de8
                       (&uStack_158,param_1,&uStack_168,0);
    puVar7 = &uStack_168;
    uStack_168 = *puVar6;
    fStack_160 = *(float *)(puVar6 + 1);
    puVar9 = (undefined8 *)FUN_181f31290(&uStack_158,&uStack_148,puVar7,0);
    uVar20 = *(undefined4 *)(puVar9 + 1);
    if (param_2 == 0) goto code_r0x0001806538d3;
code_r0x0001806521b3:
    uVar14 = (undefined4)*puVar9;
    uVar17 = (undefined4)((ulonglong)*puVar9 >> 0x20);
code_r0x0001806521b7:
    *(ulonglong *)(param_2 + 0x10) = CONCAT44(uVar17,uVar14);
    *(undefined4 *)(param_2 + 0x18) = uVar20;
  }
code_r0x0001806521bf:
  if (((*(longlong *)(param_1 + 0x78) == 0) || (param_2 == 0)) ||
     (lVar5 = *(longlong *)(*(longlong *)(param_1 + 0x78) + 0x60), lVar5 == 0))
  goto code_r0x0001806538d3;
  *(undefined1 *)(lVar5 + 0x260) = *(undefined1 *)(param_2 + 0x28);
  if (*(longlong *)(param_1 + 0x68) == 0) goto code_r0x0001806538d3;
  if (*(char *)(*(longlong *)(param_1 + 0x68) + 0x1a) == '\0') {
    if (*(char *)(param_1 + 0x80) != '\0') {
      lVar5 = *(longlong *)(param_1 + 0x78);
      *(undefined1 *)(param_1 + 0x80) = 0;
      if (lVar5 == 0) goto code_r0x0001806538d3;
      if ((*(longlong *)(lVar5 + 0x170) == 0) || (*(longlong *)(lVar5 + 0x48) == 0))
      goto code_r0x0001806538d3;
      *(undefined4 *)(*(longlong *)(lVar5 + 0x48) + 0x24) =
           *(undefined4 *)(*(longlong *)(lVar5 + 0x170) + 0xb0);
    }
  }
  else {
    if (*(longlong *)(param_1 + 0x68) == 0) goto code_r0x0001806538d3;
    if (*(char *)(*(longlong *)(param_1 + 0x68) + 0x1b) == '\0') {
      if (*(char *)(param_1 + 0x80) != '\0') {
        lVar5 = *(longlong *)(param_1 + 0x78);
        *(undefined1 *)(param_1 + 0x80) = 0;
        if (lVar5 == 0) goto code_r0x0001806538d3;
        if ((*(longlong *)(lVar5 + 0x170) == 0) || (*(longlong *)(lVar5 + 0x48) == 0))
        goto code_r0x0001806538d3;
        *(undefined4 *)(*(longlong *)(lVar5 + 0x48) + 0x24) =
             *(undefined4 *)(*(longlong *)(lVar5 + 0x170) + 0xb0);
      }
    }
    else {
      *(undefined4 *)(param_2 + 0x10) = 0;
      puVar7 = (undefined8 *)0x0;
      ExposureUnnoticed2_Object3D_Player_Scripts_PlayerLocomotion__SetMoveSpeedInverse__06000de9
                (param_1,*(float *)(param_2 + 0x18) <= 0.0 && *(float *)(param_2 + 0x18) != 0.0,0);
    }
    if ((*(longlong *)(param_1 + 0x68) == 0) ||
       (lVar5 = *(longlong *)(*(longlong *)(param_1 + 0x68) + 0x48), lVar5 == 0))
    goto code_r0x0001806538d3;
    if (*(char *)(lVar5 + 0x1e) != '\0') {
      *(undefined4 *)(param_2 + 0x10) = 0;
      fVar19 = *(float *)(param_2 + 0x18);
      if (fVar19 < 0.0) {
        fVar19 = 0.0;
      }
      *(float *)(param_2 + 0x18) = fVar19;
    }
  }
  if (*(longlong *)(param_1 + 0x68) == 0) goto code_r0x0001806538d3;
  cVar2 = *(char *)(*(longlong *)(param_1 + 0x68) + 0x1a);
  cVar3 = ExposureUnnoticed2_Scripts_InGame_GameStateFacade__IsActivePassiveSkill__06001525(10,0);
  if (cVar3 == '\0') {
    cVar3 = ExposureUnnoticed2_Scripts_InGame_GameStateFacade__IsActivePassiveSkill__06001525
                      (0x14,0);
    if (cVar3 == '\0') {
      if (*(char *)(param_2 + 0x2d) != '\0') {
        lVar5 = *(longlong *)(param_1 + 0x68);
        if (lVar5 == 0) goto code_r0x0001806538d3;
        *(bool *)(lVar5 + 0x1a) = *(char *)(lVar5 + 0x1a) == '\0';
      }
    }
    else {
      if (*(longlong *)(param_1 + 0x68) == 0) goto code_r0x0001806538d3;
      *(undefined1 *)(*(longlong *)(param_1 + 0x68) + 0x1a) = 0;
    }
  }
  else {
    if (*(longlong *)(param_1 + 0x68) == 0) goto code_r0x0001806538d3;
    *(undefined1 *)(*(longlong *)(param_1 + 0x68) + 0x1a) = 1;
  }
  if (*(longlong *)(param_1 + 0x68) == 0) goto code_r0x0001806538d3;
  if (cVar2 != *(char *)(*(longlong *)(param_1 + 0x68) + 0x1a)) {
    if (DAT_182eb5496 == '\0') {
      FUN_1802f2810(&DAT_182d5a8f0);
      LOCK();
      UNLOCK();
      DAT_182eb5496 = '\x01';
    }
    if (**(longlong **)(DAT_182d5a8f0 + 0xb8) == 0) goto code_r0x0001806538d3;
    *(undefined1 *)(**(longlong **)(DAT_182d5a8f0 + 0xb8) + 0x19) = 1;
  }
  iVar13 = 0;
  if (*(longlong *)(param_1 + 0x68) == 0) goto code_r0x0001806538d3;
  if (*(char *)(*(longlong *)(param_1 + 0x68) + 0x19) == '\0') {
code_r0x00018065251d:
    if (*(char *)(*(longlong *)(param_1 + 0x68) + 0x1b) == '\0') {
      if ((*(longlong *)(param_1 + 0x78) == 0) ||
         (lVar5 = *(longlong *)(*(longlong *)(param_1 + 0x78) + 0x60), lVar5 == 0))
      goto code_r0x0001806538d3;
      if (*(char *)(lVar5 + 0x120) == '\0') {
        lVar5 = ExposureUnnoticed2_Master_Common_MCommon__get_Instance__0600133e(0);
        if ((lVar5 == 0) ||
           (lVar10 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48), lVar10 == 0))
        goto code_r0x0001806538d3;
        fVar19 = ((float)*(int *)(lVar10 + 0x80) * 0.05 + 1.0) * *(float *)(lVar5 + 0x58);
      }
      else {
        lVar5 = ExposureUnnoticed2_Master_Common_MCommon__get_Instance__0600133e(0);
        if (lVar5 == 0) goto code_r0x0001806538d3;
        fVar19 = *(float *)(lVar5 + 0x5c);
      }
    }
    else {
      lVar5 = ExposureUnnoticed2_Master_Common_MCommon__get_Instance__0600133e(0);
      if ((lVar5 == 0) ||
         (lVar10 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48), lVar10 == 0))
      goto code_r0x0001806538d3;
      fVar19 = ((float)*(int *)(lVar10 + 0x80) * 0.05 + 1.0) * *(float *)(lVar5 + 0x54);
    }
  }
  else {
    lVar5 = *(longlong *)(param_1 + 0x78);
    if ((lVar5 == 0) || (*(longlong *)(lVar5 + 0x60) == 0)) goto code_r0x0001806538d3;
    if (*(char *)(*(longlong *)(lVar5 + 0x60) + 0x120) != '\0') goto code_r0x00018065251d;
    iVar13 = 1;
    if ((lVar5 == 0) || (*(longlong *)(lVar5 + 0x60) == 0)) goto code_r0x0001806538d3;
    iVar4 = *(int *)(*(longlong *)(lVar5 + 0x60) + 0xc0);
    lVar5 = ExposureUnnoticed2_Master_Common_MCommon__get_Instance__0600133e(0);
    if (lVar5 == 0) goto code_r0x0001806538d3;
    fVar19 = ((float)iVar4 / 100.0 + 1.0) * *(float *)(lVar5 + 0x60);
    if (*(int *)(DAT_182d59ac8 + 0xe0) == 0) {
      FUN_18035c820(DAT_182d59ac8);
    }
    if (*(char *)(*(longlong *)(DAT_182d59ac8 + 0xb8) + 0x10) == '\0') {
      fVar15 = 1.0;
    }
    else {
      fVar15 = 0.0;
    }
    fVar16 = 1.0;
    if (**(longlong **)(DAT_182d58230 + 0xb8) == 0) goto code_r0x0001806538d3;
    iVar4 = ExposureUnnoticed2_Object3D_Player_Scripts_PlayerFacade__GetExposedBodyPartsByClothesAndCostume__06000d9f
                      (**(longlong **)(DAT_182d58230 + 0xb8),0);
    if (*(int *)(DAT_182d58288 + 0xe0) == 0) {
      FUN_18035c820();
    }
    if (iVar4 == 1) {
      fVar16 = 0.0;
    }
    if (*(longlong *)(param_1 + 0x78) == 0) goto code_r0x0001806538d3;
    lVar5 = *(longlong *)(*(longlong *)(param_1 + 0x78) + 0xd0);
    lVar10 = ExposureUnnoticed2_Master_Common_MCommon__get_Instance__0600133e(0);
    if ((lVar10 == 0) || (lVar5 == 0)) goto code_r0x0001806538d3;
    puVar7 = (undefined8 *)0x0;
    ExposureUnnoticed2_Object3D_Player_Scripts_StaminaManager__ConsumePerSecond__06000e4f
              (lVar5,fVar15 * *(float *)(lVar10 + 0x70) * fVar16,0);
  }
  fStackX_10 = (float)FUN_1803d4630(param_2 + 0x10);
  fStackX_10 = fStackX_10 * fVar19;
  if ((*(longlong *)(param_1 + 0x68) == 0) ||
     (lVar5 = *(longlong *)(*(longlong *)(param_1 + 0x68) + 0x48), lVar5 == 0))
  goto code_r0x0001806538d3;
  if ((*(char *)(lVar5 + 0x1c) != '\0') &&
     (*(float *)(*(longlong *)(*(longlong *)(param_1 + 0x68) + 0x48) + 100) != 0.0)) {
    fStackX_10 = *(float *)(*(longlong *)(*(longlong *)(param_1 + 0x68) + 0x48) + 100);
  }
  fStackX_20 = (float)FUN_1803d4630(param_2 + 0x10);
  fStackX_20 = (float)(iVar13 + 1) * fStackX_20;
  if ((*(longlong *)(param_1 + 0x68) == 0) ||
     (lVar5 = *(longlong *)(*(longlong *)(param_1 + 0x68) + 0x48), lVar5 == 0))
  goto code_r0x0001806538d3;
  if ((*(char *)(lVar5 + 0x1c) == '\0') || (*(char *)(*(longlong *)(param_1 + 0x68) + 0x50) != '\0')
     ) {
code_r0x000180652719:
    fStackX_20 = 0.0;
    fStackX_10 = 0.0;
  }
  else {
    if ((*(longlong *)(param_1 + 0x78) == 0) ||
       (lVar5 = *(longlong *)(*(longlong *)(param_1 + 0x78) + 0x60), lVar5 == 0))
    goto code_r0x0001806538d3;
    fVar19 = *(float *)(lVar5 + 0x124);
    pcVar8 = DAT_182ec14c0;
    if ((DAT_182ec14c0 == (code *)0x0) &&
       (pcVar8 = (code *)FUN_1802cf0c0("UnityEngine.Time::get_time()"), pcVar8 == (code *)0x0)) {
      uVar11 = FUN_1802ced60("UnityEngine.Time::get_time()");
                    /* WARNING: Subroutine does not return */
      FUN_1802cca90(uVar11,0);
    }
    DAT_182ec14c0 = pcVar8;
    fVar15 = (float)(*DAT_182ec14c0)();
    if (fVar15 < fVar19) goto code_r0x000180652719;
  }
  if (((*(longlong *)(param_1 + 0x78) == 0) ||
      (lVar5 = *(longlong *)(*(longlong *)(param_1 + 0x78) + 0x78), lVar5 == 0)) ||
     (lVar5 = *(longlong *)(lVar5 + 0x30), lVar5 == 0)) goto code_r0x0001806538d3;
  if (*(char *)(lVar5 + 0x24) == '\0') {
    if (*(int *)(param_1 + 0x14) < 0) {
      *(float *)(param_1 + 0x20) = *(float *)(param_1 + 0x20) - *(float *)(param_1 + 0x18);
    }
  }
  else {
    if (*(char *)(param_2 + 0x24) == '\0') {
      fVar19 = 0.0;
    }
    else {
      fVar19 = *(float *)(param_1 + 0x1c);
    }
    *(float *)(param_1 + 0x20) = fVar19;
    if (((*(longlong *)(param_1 + 0x78) == 0) ||
        (lVar5 = *(longlong *)(*(longlong *)(param_1 + 0x78) + 0x78), lVar5 == 0)) ||
       (lVar5 = *(longlong *)(lVar5 + 0x28), lVar5 == 0)) goto code_r0x0001806538d3;
    if ((*(char *)(lVar5 + 0x24) == '\0') && (*(int *)(param_1 + 0x14) < 0)) {
      *(float *)(param_1 + 0x20) =
           fVar19 - (*(float *)(param_1 + 0x18) + *(float *)(param_1 + 0x18));
    }
  }
  if (DAT_182eb5480 == '\0') {
    FUN_1802f2810(&DAT_182d522a8);
    LOCK();
    UNLOCK();
    DAT_182eb5480 = '\x01';
  }
  if (*(longlong *)(param_1 + 0x68) == 0) goto code_r0x0001806538d3;
  if (*(char *)(*(longlong *)(param_1 + 0x68) + 0x1a) == '\0') {
    lVar5 = *(longlong *)(param_1 + 0x60);
    if (lVar5 == 0) goto code_r0x0001806538d3;
    pcVar8 = DAT_182ec1120;
    if ((DAT_182ec1120 == (code *)0x0) &&
       (pcVar8 = (code *)FUN_1802cf0c0("UnityEngine.GameObject::get_transform()"),
       pcVar8 == (code *)0x0)) {
      uVar11 = FUN_1802ced60("UnityEngine.GameObject::get_transform()");
                    /* WARNING: Subroutine does not return */
      FUN_1802cca90(uVar11,0);
    }
    DAT_182ec1120 = pcVar8;
    lVar5 = (*DAT_182ec1120)(lVar5);
    if (lVar5 == 0) goto code_r0x0001806538d3;
    uStack_118 = 0;
    uStack_110 = uStack_110 & 0xffffffff00000000;
    pcVar8 = DAT_182ec1698;
    if ((DAT_182ec1698 == (code *)0x0) &&
       (pcVar8 = (code *)FUN_1802cf0c0(
                                      "UnityEngine.Transform::get_position_Injected(UnityEngine.Vector3&)"
                                      ), pcVar8 == (code *)0x0)) {
      uVar11 = FUN_1802ced60("UnityEngine.Transform::get_position_Injected(UnityEngine.Vector3&)");
                    /* WARNING: Subroutine does not return */
      FUN_1802cca90(uVar11,0);
    }
    DAT_182ec1698 = pcVar8;
    (*DAT_182ec1698)(lVar5,&uStack_118);
    lVar5 = *(longlong *)(param_1 + 0x38);
    if (lVar5 == 0) goto code_r0x0001806538d3;
    pcVar8 = DAT_182ec1080;
    if ((DAT_182ec1080 == (code *)0x0) &&
       (pcVar8 = (code *)FUN_1802cf0c0("UnityEngine.Component::get_transform()"),
       pcVar8 == (code *)0x0)) {
      uVar11 = FUN_1802ced60("UnityEngine.Component::get_transform()");
                    /* WARNING: Subroutine does not return */
      FUN_1802cca90(uVar11,0);
    }
    DAT_182ec1080 = pcVar8;
    lVar5 = (*DAT_182ec1080)(lVar5);
    if (lVar5 == 0) goto code_r0x0001806538d3;
    uStack_168 = 0;
    fStack_160 = 0.0;
    pcVar8 = DAT_182ec1698;
    if ((DAT_182ec1698 == (code *)0x0) &&
       (pcVar8 = (code *)FUN_1802cf0c0(
                                      "UnityEngine.Transform::get_position_Injected(UnityEngine.Vector3&)"
                                      ), pcVar8 == (code *)0x0)) {
      uVar11 = FUN_1802ced60("UnityEngine.Transform::get_position_Injected(UnityEngine.Vector3&)");
                    /* WARNING: Subroutine does not return */
      FUN_1802cca90(uVar11,0);
    }
    DAT_182ec1698 = pcVar8;
    (*DAT_182ec1698)(lVar5,&uStack_168);
    fVar15 = (float)uStack_118 - (float)uStack_168;
    fVar19 = (float)uStack_110 - fStack_160;
    if (*(int *)(DAT_182d58288 + 0xe0) == 0) {
      FUN_18035c820();
    }
    uVar20 = 0;
    if (0.0 < fStackX_10) {
      if (DAT_182eb547c == '\0') {
        FUN_1802f2810(&DAT_182d522a8);
        LOCK();
        UNLOCK();
        DAT_182eb547c = '\x01';
      }
      uStack_118 = *(undefined8 *)(*(longlong *)(DAT_182d522a8 + 0xb8) + 0x18);
      uStack_110 = CONCAT44(uStack_110._4_4_,
                            *(undefined4 *)(*(longlong *)(DAT_182d522a8 + 0xb8) + 0x20));
      uStack_148 = 0;
      uStack_140 = 0;
      pcVar8 = DAT_182ec0ea8;
      uStack_158 = (ulonglong)(uint)fVar15;
      fStack_150 = fVar19;
      if ((DAT_182ec0ea8 == (code *)0x0) &&
         (pcVar8 = (code *)FUN_1802cf0c0(
                                        "UnityEngine.Quaternion::LookRotation_Injected(UnityEngine.Vector3&,UnityEngine.Vector3&,UnityEngine.Quaternion&)"
                                        ), pcVar8 == (code *)0x0)) {
        uVar11 = FUN_1802ced60(
                              "UnityEngine.Quaternion::LookRotation_Injected(UnityEngine.Vector3&,UnityEngine.Vector3&,UnityEngine.Quaternion&)"
                              );
                    /* WARNING: Subroutine does not return */
        FUN_1802cca90(uVar11,0);
      }
      DAT_182ec0ea8 = pcVar8;
      (*DAT_182ec0ea8)(&uStack_158,&uStack_118,&uStack_148);
      uStack_158 = *(ulonglong *)(param_2 + 0x10);
      fStack_150 = *(float *)(param_2 + 0x18);
      puVar6 = (ulonglong *)FUN_181f31290(&uStack_168,&uStack_148,&uStack_158,0);
      uVar12 = *puVar6;
      fVar16 = *(float *)(puVar6 + 1);
      if ((*(longlong *)(param_1 + 0x78) == 0) ||
         (lVar5 = *(longlong *)(*(longlong *)(param_1 + 0x78) + 0x60), lVar5 == 0))
      goto code_r0x0001806538d3;
      if (*(char *)(lVar5 + 0x120) == '\0') {
        fVar21 = 15.0;
      }
      else {
        fVar21 = 5.0;
      }
      lVar5 = *(longlong *)(param_1 + 0x60);
      if (lVar5 == 0) goto code_r0x0001806538d3;
      pcVar8 = DAT_182ec1120;
      if ((DAT_182ec1120 == (code *)0x0) &&
         (pcVar8 = (code *)FUN_1802cf0c0("UnityEngine.GameObject::get_transform()"),
         pcVar8 == (code *)0x0)) {
        uVar11 = FUN_1802ced60("UnityEngine.GameObject::get_transform()");
                    /* WARNING: Subroutine does not return */
        FUN_1802cca90(uVar11,0);
      }
      DAT_182ec1120 = pcVar8;
      lVar5 = (*DAT_182ec1120)(lVar5);
      if (lVar5 == 0) goto code_r0x0001806538d3;
      puVar7 = (undefined8 *)0x0;
      puVar9 = (undefined8 *)FUN_181f4c360(&uStack_138,lVar5,0);
      uVar11 = *puVar9;
      uVar29 = *(undefined4 *)(puVar9 + 1);
      pcVar8 = DAT_182ec14d0;
      if ((DAT_182ec14d0 == (code *)0x0) &&
         (pcVar8 = (code *)FUN_1802cf0c0(), pcVar8 == (code *)0x0)) {
        uVar11 = FUN_1802ced60("UnityEngine.Time::get_deltaTime()");
                    /* WARNING: Subroutine does not return */
        FUN_1802cca90(uVar11,0);
      }
      DAT_182ec14d0 = pcVar8;
      uStack_168 = 0;
      fStack_160 = 0.0;
      uStack_110 = CONCAT44(uStack_110._4_4_,uVar29);
      uStack_158 = uVar12;
      fStack_150 = fVar16;
      uStack_118 = uVar11;
      fVar16 = (float)(*DAT_182ec14d0)();
      pcVar8 = pcRam0000000182ec0e50;
      if ((pcRam0000000182ec0e50 == (code *)0x0) &&
         (pcVar8 = (code *)FUN_1802cf0c0(
                                        "UnityEngine.Vector3::RotateTowards_Injected(UnityEngine.Vector3&,UnityEngine.Vector3&,System.Single,System.Single,UnityEngine.Vector3&)"
                                        ), pcVar8 == (code *)0x0)) {
        uVar11 = FUN_1802ced60(
                              "UnityEngine.Vector3::RotateTowards_Injected(UnityEngine.Vector3&,UnityEngine.Vector3&,System.Single,System.Single,UnityEngine.Vector3&)"
                              );
                    /* WARNING: Subroutine does not return */
        FUN_1802cca90(uVar11,0);
      }
      pcRam0000000182ec0e50 = pcVar8;
      puVar9 = &uStack_168;
      (*pcRam0000000182ec0e50)(&uStack_118,&uStack_158,fVar16 * fVar21,0,puVar9);
      uVar29 = (undefined4)((ulonglong)puVar9 >> 0x20);
      if ((*(longlong *)(param_1 + 0x68) == 0) ||
         (lVar5 = *(longlong *)(*(longlong *)(param_1 + 0x68) + 0x48), lVar5 == 0))
      goto code_r0x0001806538d3;
      if (*(char *)(lVar5 + 0x1c) != '\0') {
        if (*(longlong *)(param_1 + 0x60) == 0) goto code_r0x0001806538d3;
        lVar5 = FUN_181f3e980(*(longlong *)(param_1 + 0x60),0);
        puVar7 = (undefined8 *)0x0;
        fStack_150 = fStack_160;
        uStack_158 = uStack_168;
        puVar9 = (undefined8 *)FUN_181f31160(&uStack_f8,&uStack_158,0);
        if (lVar5 == 0) {
                    /* WARNING: Subroutine does not return */
          FUN_18031dad0();
        }
        uStack_148 = *puVar9;
        uStack_140 = puVar9[1];
        pcVar8 = DAT_182ec16c0;
        if ((DAT_182ec16c0 == (code *)0x0) &&
           (pcVar8 = (code *)FUN_1802cf0c0(
                                          "UnityEngine.Transform::set_rotation_Injected(UnityEngine.Quaternion&)"
                                          ), pcVar8 == (code *)0x0)) {
          uVar11 = FUN_1802ced60(
                                "UnityEngine.Transform::set_rotation_Injected(UnityEngine.Quaternion&)"
                                );
                    /* WARNING: Subroutine does not return */
          FUN_1802cca90(uVar11,0);
        }
        DAT_182ec16c0 = pcVar8;
        (*DAT_182ec16c0)(lVar5,&uStack_148);
      }
    }
    if (*(longlong *)(param_1 + 0x50) == 0) goto code_r0x0001806538d3;
    uVar11 = 0;
    uVar12 = (ulonglong)puVar7 & 0xffffffffffffff00;
  }
  else {
    fVar19 = (float)ExposureUnnoticed2_Scripts_InGame_GameStateFacade__GetCameraMoveX__06001527(0);
    lVar5 = ExposureUnnoticed2_Scripts_Base_CursorController__get_Instance__06001766(0);
    if (lVar5 == 0) goto code_r0x0001806538d3;
    if (*(char *)(lVar5 + 0x10) != '\0') goto code_r0x000180652c6d;
    if (((**(longlong **)(DAT_182d53c48 + 0xb8) == 0) ||
        (lVar5 = *(longlong *)(**(longlong **)(DAT_182d53c48 + 0xb8) + 0x28), lVar5 == 0)) ||
       (lVar5 = *(longlong *)(lVar5 + 0x38), lVar5 == 0)) goto code_r0x0001806538d3;
    if (*(char *)(lVar5 + 0x28) == '\0') {
      uVar11 = FUN_18041a4f0();
      if (*(int *)(DAT_182d53aa8 + 0xe0) == 0) {
        FUN_18035c820();
      }
      cVar2 = FUN_181f44560(uVar11,0,0);
      if (cVar2 != '\0') goto code_r0x000180652c6d;
    }
    else {
code_r0x000180652c6d:
      fVar19 = 0.0;
      *(undefined4 *)(param_1 + 0x10) = 4;
    }
    if ((0 < *(int *)(param_1 + 0x10)) &&
       (0.0 < *(float *)(param_2 + 0x1c) * *(float *)(param_2 + 0x1c) +
              *(float *)(param_2 + 0x20) * *(float *)(param_2 + 0x20))) {
      *(int *)(param_1 + 0x10) = *(int *)(param_1 + 0x10) + -1;
      fVar19 = 0.0;
    }
    if (((**(longlong **)(DAT_182d58378 + 0xb8) == 0) ||
        (lVar5 = *(longlong *)(**(longlong **)(DAT_182d58378 + 0xb8) + 0x40), lVar5 == 0)) ||
       (lVar5 = *(longlong *)(lVar5 + 0x60), lVar5 == 0)) goto code_r0x0001806538d3;
    if (*(char *)(lVar5 + 0x50) != '\0') {
      fVar19 = 0.0;
    }
    lVar5 = *(longlong *)(param_1 + 0x78);
    if ((lVar5 == 0) || (*(longlong *)(lVar5 + 0x60) == 0)) goto code_r0x0001806538d3;
    if ((*(char *)(*(longlong *)(lVar5 + 0x60) + 0x1b0) != '\0') &&
       ((*(longlong *)(*(longlong *)(lVar5 + 0x60) + 0x20) != 0 &&
        (*(float *)(*(longlong *)(lVar5 + 0x60) + 0x84) <= 5.0)))) {
      fVar19 = 0.0;
    }
    lVar5 = *(longlong *)(param_1 + 0x60);
    if (lVar5 == 0) goto code_r0x0001806538d3;
    pcVar8 = DAT_182ec1120;
    if ((DAT_182ec1120 == (code *)0x0) &&
       (pcVar8 = (code *)FUN_1802cf0c0("UnityEngine.GameObject::get_transform()"),
       pcVar8 == (code *)0x0)) {
      uVar11 = FUN_1802ced60("UnityEngine.GameObject::get_transform()");
                    /* WARNING: Subroutine does not return */
      FUN_1802cca90(uVar11,0);
    }
    DAT_182ec1120 = pcVar8;
    lVar5 = (*DAT_182ec1120)(lVar5);
    if (lVar5 == 0) goto code_r0x0001806538d3;
    uStack_138 = 0;
    uStack_130 = 0;
    pcVar8 = DAT_182ec16b8;
    if ((DAT_182ec16b8 == (code *)0x0) &&
       (pcVar8 = (code *)FUN_1802cf0c0(
                                      "UnityEngine.Transform::get_rotation_Injected(UnityEngine.Quaternion&)"
                                      ), pcVar8 == (code *)0x0)) {
      uVar11 = FUN_1802ced60("UnityEngine.Transform::get_rotation_Injected(UnityEngine.Quaternion&)"
                            );
                    /* WARNING: Subroutine does not return */
      FUN_1802cca90(uVar11,0);
    }
    DAT_182ec16b8 = pcVar8;
    (*DAT_182ec16b8)(lVar5,&uStack_138);
    uStack_158 = (ulonglong)(uint)(fVar19 * 0.017453292) << 0x20;
    fStack_150 = 0.0;
    uStack_148 = 0;
    uStack_140 = 0;
    pcVar8 = DAT_182ec0e88;
    if ((DAT_182ec0e88 == (code *)0x0) &&
       (pcVar8 = (code *)FUN_1802cf0c0(
                                      "UnityEngine.Quaternion::Internal_FromEulerRad_Injected(UnityEngine.Vector3&,UnityEngine.Quaternion&)"
                                      ), pcVar8 == (code *)0x0)) {
      uVar11 = FUN_1802ced60(
                            "UnityEngine.Quaternion::Internal_FromEulerRad_Injected(UnityEngine.Vector3&,UnityEngine.Quaternion&)"
                            );
                    /* WARNING: Subroutine does not return */
      FUN_1802cca90(uVar11,0);
    }
    DAT_182ec0e88 = pcVar8;
    (*DAT_182ec0e88)(&uStack_158,&uStack_148);
    fVar15 = ((float)uStack_148 * uStack_130._4_4_ + uStack_140._4_4_ * (float)uStack_138 +
             (float)uStack_140 * uStack_138._4_4_) - uStack_148._4_4_ * (float)uStack_130;
    fVar19 = (uStack_148._4_4_ * uStack_130._4_4_ + uStack_140._4_4_ * uStack_138._4_4_ +
             (float)uStack_148 * (float)uStack_130) - (float)uStack_140 * (float)uStack_138;
    fVar16 = ((float)uStack_140 * uStack_130._4_4_ + uStack_140._4_4_ * (float)uStack_130 +
             uStack_148._4_4_ * (float)uStack_138) - (float)uStack_148 * uStack_138._4_4_;
    fVar21 = ((uStack_140._4_4_ * uStack_130._4_4_ - (float)uStack_148 * (float)uStack_138) -
             uStack_148._4_4_ * uStack_138._4_4_) - (float)uStack_140 * (float)uStack_130;
    fStack_128 = fVar15;
    fStack_108 = fVar19;
    if (DAT_182eb547b == '\0') {
      FUN_1802f2810(&DAT_182d522a8);
      LOCK();
      UNLOCK();
      DAT_182eb547b = '\x01';
    }
    fVar19 = fVar19 + fVar19;
    fVar18 = fVar16 + fVar16;
    uVar12 = *(ulonglong *)(*(longlong *)(DAT_182d522a8 + 0xb8) + 0x48);
    fVar25 = (float)uVar12;
    fVar22 = *(float *)(*(longlong *)(DAT_182d522a8 + 0xb8) + 0x50);
    fVar24 = fVar18 * fStack_128;
    fVar26 = (fVar15 + fVar15) * fVar21;
    fVar15 = (fVar15 + fVar15) * fVar15;
    fVar28 = fVar19 * fStack_108;
    uStack_168._4_4_ = (float)(uVar12 >> 0x20);
    fVar23 = (fVar19 * fStack_128 - fVar18 * fVar21) * uStack_168._4_4_;
    fVar27 = (fVar26 + fVar18 * fStack_108) * uStack_168._4_4_;
    fStack_128 = (1.0 - (fVar18 * fVar16 + fVar15)) * uStack_168._4_4_ +
                 (fVar18 * fVar21 + fVar19 * fStack_128) * fVar25 +
                 (fVar18 * fStack_108 - fVar26) * fVar22;
    uStack_168 = uVar12;
    if ((*(longlong *)(param_1 + 0x68) == 0) ||
       (lVar5 = *(longlong *)(*(longlong *)(param_1 + 0x68) + 0x48), lVar5 == 0))
    goto code_r0x0001806538d3;
    if (*(char *)(lVar5 + 0x1c) != '\0') {
      lVar5 = *(longlong *)(param_1 + 0x60);
      if (lVar5 == 0) goto code_r0x0001806538d3;
      pcVar8 = DAT_182ec1120;
      if ((DAT_182ec1120 == (code *)0x0) &&
         (pcVar8 = (code *)FUN_1802cf0c0("UnityEngine.GameObject::get_transform()"),
         pcVar8 == (code *)0x0)) {
        uVar11 = FUN_1802ced60("UnityEngine.GameObject::get_transform()");
                    /* WARNING: Subroutine does not return */
        FUN_1802cca90(uVar11,0);
      }
      DAT_182ec1120 = pcVar8;
      lVar5 = (*DAT_182ec1120)(lVar5);
      if (DAT_182eb547c == '\0') {
        FUN_1802f2810(&DAT_182d522a8);
        LOCK();
        UNLOCK();
        DAT_182eb547c = '\x01';
      }
      uStack_110 = CONCAT44(uStack_110._4_4_,
                            (fVar24 - fVar19 * fVar21) * fVar25 + fVar27 +
                            (1.0 - (fVar28 + fVar15)) * fVar22);
      uStack_168 = *(ulonglong *)(*(longlong *)(DAT_182d522a8 + 0xb8) + 0x18);
      fStack_160 = *(float *)(*(longlong *)(DAT_182d522a8 + 0xb8) + 0x20);
      uStack_118 = CONCAT44(fStack_128,
                            (1.0 - (fVar18 * fVar16 + fVar28)) * fVar25 + fVar23 +
                            (fVar19 * fVar21 + fVar24) * fVar22);
      uStack_138 = 0;
      uStack_130 = 0;
      pcVar8 = DAT_182ec0ea8;
      if ((DAT_182ec0ea8 == (code *)0x0) &&
         (pcVar8 = (code *)FUN_1802cf0c0(
                                        "UnityEngine.Quaternion::LookRotation_Injected(UnityEngine.Vector3&,UnityEngine.Vector3&,UnityEngine.Quaternion&)"
                                        ), pcVar8 == (code *)0x0)) {
        uVar11 = FUN_1802ced60(
                              "UnityEngine.Quaternion::LookRotation_Injected(UnityEngine.Vector3&,UnityEngine.Vector3&,UnityEngine.Quaternion&)"
                              );
                    /* WARNING: Subroutine does not return */
        FUN_1802cca90(uVar11,0);
      }
      DAT_182ec0ea8 = pcVar8;
      (*DAT_182ec0ea8)(&uStack_118,&uStack_168,&uStack_138);
      if (lVar5 == 0) {
                    /* WARNING: Subroutine does not return */
        FUN_18031dad0();
      }
      uStack_f8 = (float)uStack_138;
      uStack_f4 = uStack_138._4_4_;
      uStack_f0 = (float)uStack_130;
      uStack_ec = uStack_130._4_4_;
      pcVar8 = DAT_182ec16c0;
      if ((DAT_182ec16c0 == (code *)0x0) &&
         (pcVar8 = (code *)FUN_1802cf0c0(
                                        "UnityEngine.Transform::set_rotation_Injected(UnityEngine.Quaternion&)"
                                        ), pcVar8 == (code *)0x0)) {
        uVar11 = FUN_1802ced60(
                              "UnityEngine.Transform::set_rotation_Injected(UnityEngine.Quaternion&)"
                              );
                    /* WARNING: Subroutine does not return */
        FUN_1802cca90(uVar11,0);
      }
      DAT_182ec16c0 = pcVar8;
      (*DAT_182ec16c0)(lVar5,&uStack_f8);
    }
    lVar5 = *(longlong *)(param_1 + 0x78);
    if ((lVar5 == 0) || (*(longlong *)(lVar5 + 0x60) == 0)) goto code_r0x0001806538d3;
    if ((*(char *)(*(longlong *)(lVar5 + 0x60) + 0x1b0) != '\0') &&
       ((*(longlong *)(*(longlong *)(lVar5 + 0x60) + 0x20) != 0 &&
        (*(float *)(*(longlong *)(lVar5 + 0x60) + 0x84) <= 5.0)))) {
      lVar5 = *(longlong *)(*(longlong *)(*(longlong *)(lVar5 + 0x60) + 0x20) + 0x10);
      if (lVar5 == 0) goto code_r0x0001806538d3;
      puVar6 = (ulonglong *)FUN_181f4b9a0(&uStack_138,lVar5,0);
      uStack_168 = *puVar6;
      fVar19 = *(float *)(puVar6 + 1);
      if ((*(longlong *)(param_1 + 0x78) == 0) ||
         (lVar5 = *(longlong *)(*(longlong *)(param_1 + 0x78) + 0x18), lVar5 == 0))
      goto code_r0x0001806538d3;
      puVar6 = (ulonglong *)FUN_181f4b9a0(&uStack_138,lVar5,0);
      uVar12 = *puVar6;
      fVar15 = *(float *)(puVar6 + 1);
      fVar16 = (float)uStack_168 - (float)uVar12;
      uStack_168 = uVar12;
      if (*(int *)(DAT_182d58288 + 0xe0) == 0) {
        FUN_18035c820();
      }
      if (*(longlong *)(param_1 + 0x60) == 0) goto code_r0x0001806538d3;
      lVar5 = FUN_181f3e980(*(longlong *)(param_1 + 0x60),0);
      if ((*(longlong *)(param_1 + 0x60) == 0) ||
         (lVar10 = FUN_181f3e980(*(longlong *)(param_1 + 0x60),0), lVar10 == 0))
      goto code_r0x0001806538d3;
      puVar7 = (undefined8 *)FUN_181f4c700(&uStack_138,lVar10,0);
      uStack_168 = (ulonglong)(uint)fVar16;
      uVar11 = *puVar7;
      uVar12 = puVar7[1];
      fStack_160 = fVar19 - fVar15;
      puVar6 = (ulonglong *)FUN_181f31160(auStack_e8,&uStack_168,0);
      uStack_138 = 0;
      uStack_130 = 0;
      uStack_168 = *puVar6;
      fStack_160 = *(float *)(puVar6 + 1);
      uStack_15c = *(undefined4 *)((longlong)puVar6 + 0xc);
      pcVar8 = DAT_182ec0e80;
      uStack_118 = uVar11;
      uStack_110 = uVar12;
      if ((DAT_182ec0e80 == (code *)0x0) &&
         (pcVar8 = (code *)FUN_1802cf0c0(
                                        "UnityEngine.Quaternion::Lerp_Injected(UnityEngine.Quaternion&,UnityEngine.Quaternion&,System.Single,UnityEngine.Quaternion&)"
                                        ), pcVar8 == (code *)0x0)) {
        uVar11 = FUN_1802ced60(
                              "UnityEngine.Quaternion::Lerp_Injected(UnityEngine.Quaternion&,UnityEngine.Quaternion&,System.Single,UnityEngine.Quaternion&)"
                              );
                    /* WARNING: Subroutine does not return */
        FUN_1802cca90(uVar11,0);
      }
      DAT_182ec0e80 = pcVar8;
      (*DAT_182ec0e80)(&uStack_118,&uStack_168,0x3f000000,&uStack_138);
      if (lVar5 == 0) {
                    /* WARNING: Subroutine does not return */
        FUN_18031dad0();
      }
      FUN_181f4c770(lVar5,&uStack_138,0);
    }
    lVar5 = *(longlong *)(param_1 + 0x60);
    if (lVar5 == 0) goto code_r0x0001806538d3;
    pcVar8 = DAT_182ec1120;
    if ((DAT_182ec1120 == (code *)0x0) &&
       (pcVar8 = (code *)FUN_1802cf0c0("UnityEngine.GameObject::get_transform()"),
       pcVar8 == (code *)0x0)) {
      uVar11 = FUN_1802ced60("UnityEngine.GameObject::get_transform()");
                    /* WARNING: Subroutine does not return */
      FUN_1802cca90(uVar11,0);
    }
    DAT_182ec1120 = pcVar8;
    lVar5 = (*DAT_182ec1120)(lVar5);
    if (lVar5 == 0) goto code_r0x0001806538d3;
    puVar7 = (undefined8 *)FUN_181f4c360(&uStack_138,lVar5,0);
    fVar15 = (float)*puVar7;
    uVar20 = (undefined4)((ulonglong)*puVar7 >> 0x20);
    fVar19 = *(float *)(puVar7 + 1);
    if (*(longlong *)(param_1 + 0x50) == 0) goto code_r0x0001806538d3;
    uVar12 = (ulonglong)*(byte *)(param_2 + 0x26);
    uVar11 = 1;
  }
  ExposureUnnoticed2_Object3D_Player_Scripts_PlayerAnimationManager__SetStrafe__06000c7e
            (*(undefined4 *)(param_2 + 0x18),uVar11,uVar12,*(undefined4 *)(param_2 + 0x10),
             CONCAT44(uVar29,*(undefined4 *)(param_2 + 0x18)),0);
  if (DAT_182eb547c == '\0') {
    FUN_1802f2810(&DAT_182d522a8);
    LOCK();
    UNLOCK();
    DAT_182eb547c = '\x01';
  }
  uStack_168 = CONCAT44(uVar20,fVar15);
  uStack_158 = *(ulonglong *)(*(longlong *)(DAT_182d522a8 + 0xb8) + 0x18);
  fStack_150 = *(float *)(*(longlong *)(DAT_182d522a8 + 0xb8) + 0x20);
  uStack_148 = 0;
  uStack_140 = 0;
  pcVar8 = DAT_182ec0ea8;
  fStack_160 = fVar19;
  if ((DAT_182ec0ea8 == (code *)0x0) &&
     (pcVar8 = (code *)FUN_1802cf0c0(
                                    "UnityEngine.Quaternion::LookRotation_Injected(UnityEngine.Vector3&,UnityEngine.Vector3&,UnityEngine.Quaternion&)"
                                    ), pcVar8 == (code *)0x0)) {
    uVar11 = FUN_1802ced60(
                          "UnityEngine.Quaternion::LookRotation_Injected(UnityEngine.Vector3&,UnityEngine.Vector3&,UnityEngine.Quaternion&)"
                          );
                    /* WARNING: Subroutine does not return */
    FUN_1802cca90(uVar11,0);
  }
  DAT_182ec0ea8 = pcVar8;
  (*DAT_182ec0ea8)(&uStack_168,&uStack_158,&uStack_148);
  fVar15 = (float)uStack_140 + (float)uStack_140;
  uVar11 = *(undefined8 *)(param_2 + 0x10);
  fVar18 = (float)uVar11;
  fVar19 = *(float *)(param_2 + 0x18);
  fVar16 = uStack_148._4_4_ + uStack_148._4_4_;
  fVar22 = uStack_140._4_4_ * ((float)uStack_148 + (float)uStack_148);
  fVar24 = (float)uStack_148 * ((float)uStack_148 + (float)uStack_148);
  uStack_118._4_4_ = (float)((ulonglong)uVar11 >> 0x20);
  fVar28 = (1.0 - ((float)uStack_140 * fVar15 + uStack_148._4_4_ * fVar16)) * fVar18 +
           ((float)uStack_148 * fVar16 - uStack_140._4_4_ * fVar15) * uStack_118._4_4_ +
           (uStack_140._4_4_ * fVar16 + (float)uStack_148 * fVar15) * fVar19;
  fVar21 = (1.0 - ((float)uStack_140 * fVar15 + fVar24)) * uStack_118._4_4_ +
           (uStack_140._4_4_ * fVar15 + (float)uStack_148 * fVar16) * fVar18 +
           (uStack_148._4_4_ * fVar15 - fVar22) * fVar19;
  fVar23 = 1.0;
  fVar19 = ((float)uStack_148 * fVar15 - uStack_140._4_4_ * fVar16) * fVar18 +
           (fVar22 + uStack_148._4_4_ * fVar15) * uStack_118._4_4_ +
           (1.0 - (uStack_148._4_4_ * fVar16 + fVar24)) * fVar19;
  lVar5 = *(longlong *)(param_1 + 0x60);
  uStack_118 = uVar11;
  if (lVar5 != 0) {
    pcVar8 = DAT_182ec1120;
    if ((DAT_182ec1120 == (code *)0x0) &&
       (pcVar8 = (code *)FUN_1802cf0c0("UnityEngine.GameObject::get_transform()"),
       pcVar8 == (code *)0x0)) {
      uVar11 = FUN_1802ced60("UnityEngine.GameObject::get_transform()");
                    /* WARNING: Subroutine does not return */
      FUN_1802cca90(uVar11,0);
    }
    DAT_182ec1120 = pcVar8;
    lVar5 = (*DAT_182ec1120)(lVar5);
    if (lVar5 != 0) {
      puVar6 = (ulonglong *)FUN_181f4c360(&uStack_138,lVar5,0);
      uStack_158 = *puVar6;
      fVar15 = (float)(uStack_158 >> 0x20) * fVar21 + (float)uStack_158 * fVar28 +
               *(float *)(puVar6 + 1) * fVar19;
      if (fVar15 <= 0.0) {
        fVar15 = 0.0;
      }
      if (*(longlong *)(param_1 + 0x68) != 0) {
        if (*(char *)(*(longlong *)(param_1 + 0x68) + 0x1a) != '\0') {
          fVar15 = 1.0;
        }
        if (*(longlong *)(param_1 + 0x28) != 0) {
          ExposureUnnoticed2_Scripts_Base_SmoothFloat__UpdateTo__0600175c
                    (*(longlong *)(param_1 + 0x28),fStackX_10,0);
          if (*(longlong *)(param_1 + 0x50) != 0) {
            *(float *)(*(longlong *)(param_1 + 0x50) + 0x10) = fStackX_20;
            if (*(longlong *)(param_1 + 0x68) != 0) {
              if (*(char *)(*(longlong *)(param_1 + 0x68) + 0x19) != '\0') {
                if (*(int *)(DAT_182d59ac8 + 0xe0) == 0) {
                  FUN_18035c820(DAT_182d59ac8);
                }
                if (*(char *)(*(longlong *)(DAT_182d59ac8 + 0xb8) + 0x10) != '\0') {
                  fVar23 = 5.0;
                }
              }
              fVar16 = (float)FUN_1803d4630(param_2 + 0x10);
              if (*(longlong *)(param_1 + 0x28) != 0) {
                fVar22 = *(float *)(*(longlong *)(param_1 + 0x28) + 0x10);
                if ((*(longlong *)(param_1 + 0x68) != 0) &&
                   (lVar5 = *(longlong *)(*(longlong *)(param_1 + 0x68) + 0x48), lVar5 != 0)) {
                  if (*(longlong *)(param_1 + 0x78) != 0) {
                    lVar10 = *(longlong *)(*(longlong *)(param_1 + 0x78) + 0x60);
                    if (*(char *)(lVar5 + 0x1c) == '\0') {
                      if (DAT_182eb547c == '\0') {
                        FUN_1802f2810(&DAT_182d522a8);
                        LOCK();
                        UNLOCK();
                        DAT_182eb547c = '\x01';
                      }
                      fVar19 = *(float *)(param_1 + 0x20);
                      uVar11 = *(undefined8 *)(*(longlong *)(DAT_182d522a8 + 0xb8) + 0x18);
                      fVar18 = fVar19 * *(float *)(*(longlong *)(DAT_182d522a8 + 0xb8) + 0x20);
                      fVar21 = fVar19 * (float)((ulonglong)uVar11 >> 0x20);
                      fVar19 = fVar19 * (float)uVar11;
                    }
                    else {
                      if (DAT_182eb547c == '\0') {
                        FUN_1802f2810(&DAT_182d522a8);
                        LOCK();
                        UNLOCK();
                        DAT_182eb547c = '\x01';
                      }
                      fVar24 = *(float *)(param_1 + 0x20);
                      uVar11 = *(undefined8 *)(*(longlong *)(DAT_182d522a8 + 0xb8) + 0x18);
                      fVar18 = fVar24 * *(float *)(*(longlong *)(DAT_182d522a8 + 0xb8) + 0x20) +
                               fVar22 * fVar19 * fVar15 * fVar16 * fVar23;
                      fVar21 = fVar24 * (float)((ulonglong)uVar11 >> 0x20) +
                               fVar22 * fVar21 * fVar15 * fVar16 * fVar23;
                      fVar19 = fVar24 * (float)uVar11 + fVar22 * fVar28 * fVar15 * fVar16 * fVar23;
                    }
                    if (lVar10 != 0) {
                      *(ulonglong *)(lVar10 + 400) = CONCAT44(fVar21,fVar19);
                      *(float *)(lVar10 + 0x198) = fVar18;
                      return;
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
code_r0x0001806538d3:
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

