// Ghidra pseudocode; not original source or compilable C.
// ev_245709dab79e97d6024d0b0038a98db99f5879cacc1afe4a05e8ec876bfd6626

void ExposureUnnoticed2_Object3D_NPC_Script_NpcLocomotion__OnUpdate__06001079(longlong param_1)

{
  undefined4 uVar1;
  longlong *plVar2;
  ulonglong uVar3;
  code *pcVar4;
  int iVar5;
  code *pcVar6;
  longlong lVar7;
  longlong lVar8;
  undefined8 *puVar9;
  undefined8 uVar10;
  int iVar11;
  undefined8 uVar12;
  ulonglong uVar13;
  uint uVar14;
  bool bVar15;
  float fVar16;
  float fVar17;
  float fVar18;
  float fVar19;
  undefined8 uStack_a8;
  ulonglong uStack_a0;
  undefined8 uStack_98;
  float fStack_90;
  undefined8 uStack_88;
  undefined8 uStack_80;
  undefined8 uStack_78;
  undefined8 uStack_70;
  
  if (cRam0000000182eb7766 == '\0') {
    FUN_1802f2810(0x182d59620);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d58288);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d53aa8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d58378);
    LOCK();
    UNLOCK();
    cRam0000000182eb7766 = '\x01';
  }
  if ((*(longlong *)(param_1 + 0x10) == 0) ||
     (lVar7 = *(longlong *)(*(longlong *)(param_1 + 0x10) + 0xc0), lVar7 == 0))
  goto code_r0x00018042dad6;
  pcVar6 = DAT_182ec1080;
  if ((DAT_182ec1080 == (code *)0x0) &&
     (pcVar6 = (code *)FUN_1802cf0c0("UnityEngine.Component::get_transform()"),
     pcVar6 == (code *)0x0)) {
    uVar12 = FUN_1802ced60("UnityEngine.Component::get_transform()");
                    /* WARNING: Subroutine does not return */
    FUN_1802cca90(uVar12,0);
  }
  DAT_182ec1080 = pcVar6;
  lVar7 = (*DAT_182ec1080)(lVar7);
  if ((*(longlong *)(param_1 + 0x10) == 0) ||
     (lVar8 = *(longlong *)(*(longlong *)(param_1 + 0x10) + 0xc0), lVar8 == 0))
  goto code_r0x00018042dad6;
  pcVar6 = DAT_182ec1080;
  if ((DAT_182ec1080 == (code *)0x0) &&
     (pcVar6 = (code *)FUN_1802cf0c0("UnityEngine.Component::get_transform()"),
     pcVar6 == (code *)0x0)) {
    uVar12 = FUN_1802ced60("UnityEngine.Component::get_transform()");
                    /* WARNING: Subroutine does not return */
    FUN_1802cca90(uVar12,0);
  }
  DAT_182ec1080 = pcVar6;
  lVar8 = (*DAT_182ec1080)(lVar8);
  if (lVar8 == 0) goto code_r0x00018042dad6;
  uStack_a8 = 0;
  uStack_a0 = uStack_a0 & 0xffffffff00000000;
  pcVar6 = DAT_182ec16a8;
  if ((DAT_182ec16a8 == (code *)0x0) &&
     (pcVar6 = (code *)FUN_1802cf0c0(
                                    "UnityEngine.Transform::get_localPosition_Injected(UnityEngine.Vector3&)"
                                    ), pcVar6 == (code *)0x0)) {
    uVar12 = FUN_1802ced60("UnityEngine.Transform::get_localPosition_Injected(UnityEngine.Vector3&)"
                          );
                    /* WARNING: Subroutine does not return */
    FUN_1802cca90(uVar12,0);
  }
  DAT_182ec16a8 = pcVar6;
  (*DAT_182ec16a8)(lVar8,&uStack_a8);
  if (DAT_182eb5480 == '\0') {
    FUN_1802f2810(&DAT_182d522a8);
    LOCK();
    UNLOCK();
    DAT_182eb5480 = '\x01';
  }
  uStack_88 = **(undefined8 **)(DAT_182d522a8 + 0xb8);
  fVar17 = (*(float *)(*(undefined8 **)(DAT_182d522a8 + 0xb8) + 1) - (float)uStack_a0) * 0.1 +
           (float)uStack_a0;
  if (lVar7 == 0) {
code_r0x00018042dcc0:
                    /* WARNING: Subroutine does not return */
    FUN_18031dad0();
  }
  uStack_98 = CONCAT44(((float)((ulonglong)uStack_88 >> 0x20) - uStack_a8._4_4_) * 0.1 +
                       uStack_a8._4_4_,
                       ((float)uStack_88 - (float)uStack_a8) * 0.1 + (float)uStack_a8);
  pcVar6 = DAT_182ec16b0;
  fStack_90 = fVar17;
  if ((DAT_182ec16b0 == (code *)0x0) &&
     (pcVar6 = (code *)FUN_1802cf0c0(
                                    "UnityEngine.Transform::set_localPosition_Injected(UnityEngine.Vector3&)"
                                    ), pcVar6 == (code *)0x0)) {
    uVar12 = FUN_1802ced60("UnityEngine.Transform::set_localPosition_Injected(UnityEngine.Vector3&)"
                          );
                    /* WARNING: Subroutine does not return */
    FUN_1802cca90(uVar12,0);
  }
  DAT_182ec16b0 = pcVar6;
  (*DAT_182ec16b0)(lVar7,&uStack_98);
  if ((*(longlong *)(param_1 + 0x10) == 0) ||
     (lVar7 = *(longlong *)(*(longlong *)(param_1 + 0x10) + 0x38), lVar7 == 0))
  goto code_r0x00018042dcc0;
  uVar12 = *(undefined8 *)(lVar7 + 0x10);
  lVar7 = *(longlong *)(*(longlong *)(*(longlong *)(param_1 + 0x10) + 0x38) + 0x10);
  if (lVar7 == 0) goto code_r0x00018042dcc0;
  uStack_88 = 0;
  uStack_80 = 0;
  pcVar6 = DAT_182ec16b8;
  if ((DAT_182ec16b8 == (code *)0x0) &&
     (pcVar6 = (code *)FUN_1802cf0c0(
                                    "UnityEngine.Transform::get_rotation_Injected(UnityEngine.Quaternion&)"
                                    ), pcVar6 == (code *)0x0)) {
    uVar12 = FUN_1802ced60("UnityEngine.Transform::get_rotation_Injected(UnityEngine.Quaternion&)");
                    /* WARNING: Subroutine does not return */
    FUN_1802cca90(uVar12,0);
  }
  DAT_182ec16b8 = pcVar6;
  (*DAT_182ec16b8)(lVar7,&uStack_88);
  uVar10 = *(undefined8 *)(param_1 + 0x38);
  uVar13 = *(ulonglong *)(param_1 + 0x40);
  pcVar6 = DAT_182ec14d0;
  if ((DAT_182ec14d0 == (code *)0x0) &&
     (pcVar6 = (code *)FUN_1802cf0c0("UnityEngine.Time::get_deltaTime()"), pcVar6 == (code *)0x0)) {
    uVar12 = FUN_1802ced60("UnityEngine.Time::get_deltaTime()");
                    /* WARNING: Subroutine does not return */
    FUN_1802cca90(uVar12,0);
  }
  DAT_182ec14d0 = pcVar6;
  uStack_78 = uStack_88;
  uStack_70 = uStack_80;
  uStack_a8 = uVar10;
  uStack_a0 = uVar13;
  fVar17 = (float)(*DAT_182ec14d0)();
  puVar9 = (undefined8 *)FUN_1804363f0(&uStack_88,&uStack_78,&uStack_a8,fVar17 * 90.0);
  uStack_78 = *puVar9;
  uStack_70 = puVar9[1];
  pcVar6 = DAT_182ec16c0;
  if ((DAT_182ec16c0 == (code *)0x0) &&
     (pcVar6 = (code *)FUN_1802cf0c0(
                                    "UnityEngine.Transform::set_rotation_Injected(UnityEngine.Quaternion&)"
                                    ), pcVar6 == (code *)0x0)) {
    uVar12 = FUN_1802ced60("UnityEngine.Transform::set_rotation_Injected(UnityEngine.Quaternion&)");
                    /* WARNING: Subroutine does not return */
    FUN_1802cca90(uVar12,0);
  }
  DAT_182ec16c0 = pcVar6;
  (*DAT_182ec16c0)(uVar12,&uStack_78);
  pcVar6 = DAT_182ec14c0;
  if ((DAT_182ec14c0 == (code *)0x0) &&
     (pcVar6 = (code *)FUN_1802cf0c0("UnityEngine.Time::get_time()"), pcVar6 == (code *)0x0)) {
    uVar12 = FUN_1802ced60("UnityEngine.Time::get_time()");
                    /* WARNING: Subroutine does not return */
    FUN_1802cca90(uVar12,0);
  }
  DAT_182ec14c0 = pcVar6;
  fVar17 = (float)(*DAT_182ec14c0)();
  if (fVar17 - *(float *)(param_1 + 0x48) < 0.1) {
    return;
  }
  pcVar6 = DAT_182ec14c0;
  if ((DAT_182ec14c0 == (code *)0x0) &&
     (pcVar6 = (code *)FUN_1802cf0c0("UnityEngine.Time::get_time()"), pcVar6 == (code *)0x0)) {
    uVar12 = FUN_1802ced60("UnityEngine.Time::get_time()");
                    /* WARNING: Subroutine does not return */
    FUN_1802cca90(uVar12,0);
  }
  DAT_182ec14c0 = pcVar6;
  fVar17 = (float)(*DAT_182ec14c0)();
  pcVar6 = DAT_182ec0fd8;
  if ((DAT_182ec0fd8 == (code *)0x0) &&
     (pcVar6 = (code *)FUN_1802cf0c0("UnityEngine.Random::get_value()"), pcVar6 == (code *)0x0)) {
    uVar12 = FUN_1802ced60("UnityEngine.Random::get_value()");
                    /* WARNING: Subroutine does not return */
    FUN_1802cca90(uVar12,0);
  }
  DAT_182ec0fd8 = pcVar6;
  fVar16 = (float)(*DAT_182ec0fd8)();
  bVar15 = DAT_182eb5480 == '\0';
  *(float *)(param_1 + 0x48) = fVar16 * 0.05 + fVar17;
  if (bVar15) {
    FUN_1802f2810(&DAT_182d522a8);
    LOCK();
    UNLOCK();
    DAT_182eb5480 = '\x01';
  }
  if ((*(longlong *)(param_1 + 0x10) == 0) ||
     (lVar7 = *(longlong *)(*(longlong *)(param_1 + 0x10) + 0x40), lVar7 == 0))
  goto code_r0x00018042dad6;
  if (*(int *)(lVar7 + 0x10) == 7) {
    if (((**(longlong **)(DAT_182d58378 + 0xb8) == 0) ||
        (lVar7 = *(longlong *)(**(longlong **)(DAT_182d58378 + 0xb8) + 0x40), lVar7 == 0)) ||
       (lVar7 = *(longlong *)(lVar7 + 0x60), lVar7 == 0)) goto code_r0x00018042dad6;
    lVar8 = *(longlong *)(param_1 + 0x10);
    uVar12 = *(undefined8 *)(lVar7 + 0x264);
    fVar17 = *(float *)(lVar7 + 0x26c);
    if (lVar8 == 0) goto code_r0x00018042dad6;
    lVar7 = *(longlong *)(lVar8 + 0x10);
    lVar8 = *(longlong *)(lVar8 + 0xa0);
    uStack_98 = uVar12;
    if (lVar7 == 0) goto code_r0x00018042dad6;
    uStack_a8 = 0;
    uStack_a0 = uStack_a0 & 0xffffffff00000000;
    pcVar6 = DAT_182ec1698;
    if ((DAT_182ec1698 == (code *)0x0) &&
       (pcVar6 = (code *)FUN_1802cf0c0(
                                      "UnityEngine.Transform::get_position_Injected(UnityEngine.Vector3&)"
                                      ), pcVar6 == (code *)0x0)) {
      uVar12 = FUN_1802ced60("UnityEngine.Transform::get_position_Injected(UnityEngine.Vector3&)");
                    /* WARNING: Subroutine does not return */
      FUN_1802cca90(uVar12,0);
    }
    DAT_182ec1698 = pcVar6;
    (*DAT_182ec1698)(lVar7,&uStack_a8);
    if ((lVar8 == 0) || (lVar7 = *(longlong *)(lVar8 + 0x20), lVar7 == 0)) {
code_r0x00018042dcba:
                    /* WARNING: Subroutine does not return */
      FUN_18031dad0();
    }
    *(float *)(lVar7 + 0x1c) =
         (float)(0.5 < (uStack_98._4_4_ - uStack_a8._4_4_) * (uStack_98._4_4_ - uStack_a8._4_4_) +
                       ((float)uStack_98 - (float)uStack_a8) * ((float)uStack_98 - (float)uStack_a8)
                       + (fVar17 - (float)uStack_a0) * (fVar17 - (float)uStack_a0));
    if ((*(longlong *)(param_1 + 0x10) == 0) ||
       (lVar7 = *(longlong *)(*(longlong *)(param_1 + 0x10) + 0x28), lVar7 == 0))
    goto code_r0x00018042dcba;
    pcVar6 = DAT_182ebeeb0;
    uStack_98 = uVar12;
    fStack_90 = fVar17;
    if ((DAT_182ebeeb0 == (code *)0x0) &&
       (pcVar6 = (code *)FUN_1802cf0c0(
                                      "UnityEngine.AI.NavMeshAgent::SetDestination_Injected(UnityEngine.Vector3&)"
                                      ), pcVar6 == (code *)0x0)) {
      uVar12 = FUN_1802ced60(
                            "UnityEngine.AI.NavMeshAgent::SetDestination_Injected(UnityEngine.Vector3&)"
                            );
                    /* WARNING: Subroutine does not return */
      FUN_1802cca90(uVar12,0);
    }
code_r0x00018042d475:
    DAT_182ebeeb0 = pcVar6;
    (*DAT_182ebeeb0)(lVar7,&uStack_98);
  }
  else {
    plVar2 = *(longlong **)(lVar7 + 0x40);
    if (plVar2 == (longlong *)0x0) goto code_r0x00018042dad6;
    lVar7 = (**(code **)(*plVar2 + 0x188))(plVar2,*(undefined8 *)(*plVar2 + 400));
    if ((((*(longlong *)(param_1 + 0x10) == 0) ||
         (lVar8 = *(longlong *)(*(longlong *)(param_1 + 0x10) + 0x40), lVar8 == 0)) ||
        (lVar8 = *(longlong *)(lVar8 + 0x40), lVar8 == 0)) || (lVar7 == 0))
    goto code_r0x00018042dad6;
    puVar9 = (undefined8 *)
             ExposureUnnoticed2_Object3D_RoutePoint_RoutePoint__get_Position__06000be9
                       (&uStack_88,lVar7,0);
    fVar17 = *(float *)(lVar8 + 0x38);
    fVar16 = *(float *)(lVar7 + 0x40);
    uStack_98 = *puVar9;
    lVar8 = *(longlong *)(lVar7 + 0x28);
    fVar18 = fVar17 * (float)*(undefined8 *)(lVar7 + 0x48) * fVar16 + (float)uStack_98;
    fVar19 = fVar17 * (float)((ulonglong)*(undefined8 *)(lVar7 + 0x48) >> 0x20) * fVar16 +
             (float)((ulonglong)uStack_98 >> 0x20);
    fVar17 = fVar17 * *(float *)(lVar7 + 0x50) * fVar16 + *(float *)(puVar9 + 1);
    if (*(int *)(DAT_182d53aa8 + 0xe0) == 0) {
      FUN_18035c820();
    }
    if (DAT_182ec12f4 == '\0') {
      FUN_1802f2810(&DAT_182d53aa8);
      LOCK();
      UNLOCK();
      DAT_182ec12f4 = '\x01';
    }
    if (*(int *)(DAT_182d53aa8 + 0xe0) == 0) {
      FUN_18035c820();
    }
    if (DAT_182ec129b == '\0') {
      FUN_1802f2810(&DAT_182d53aa8);
      LOCK();
      UNLOCK();
      DAT_182ec129b = '\x01';
    }
    if (lVar8 != 0) {
      if (*(int *)(DAT_182d53aa8 + 0xe0) == 0) {
        FUN_18035c820();
      }
      if (*(longlong *)(lVar8 + 0x10) != 0) {
        lVar8 = *(longlong *)(param_1 + 0x10);
        if ((lVar8 == 0) || (*(longlong *)(lVar8 + 0x40) == 0)) goto code_r0x00018042dad6;
        if (*(char *)(*(longlong *)(lVar8 + 0x40) + 0x48) == '\0') {
          if (*(longlong *)(lVar8 + 0x38) == 0) goto code_r0x00018042dad6;
          uVar12 = *(undefined8 *)(*(longlong *)(lVar8 + 0x38) + 0x18);
          uVar10 = ExposureUnnoticed2_Scripts_InGame_Util_ColliderTriggerController__get_CenterObject__0600169c
                             (lVar7,0);
          if (*(int *)(DAT_182d58288 + 0xe0) == 0) {
            FUN_18035c820();
          }
          fVar16 = (float)ExposureUnnoticed2_Scripts_Base_ExternalMethodManager__DistSqrt__06001726
                                    (uVar12,uVar10,0);
          if (fVar16 < 1.0) {
            if ((*(longlong *)(param_1 + 0x10) == 0) ||
               (lVar7 = *(longlong *)(*(longlong *)(param_1 + 0x10) + 0x38), lVar7 == 0))
            goto code_r0x00018042dad6;
            uVar12 = 6;
            goto code_r0x00018042cf0f;
          }
        }
      }
    }
    if ((*(longlong *)(param_1 + 0x10) == 0) ||
       (lVar8 = *(longlong *)(*(longlong *)(param_1 + 0x10) + 0x38), lVar8 == 0))
    goto code_r0x00018042dad6;
    uVar12 = *(undefined8 *)(lVar8 + 0x18);
    pcVar6 = DAT_182ec1088;
    if ((DAT_182ec1088 == (code *)0x0) &&
       (pcVar6 = (code *)FUN_1802cf0c0("UnityEngine.Component::get_gameObject()"),
       pcVar6 == (code *)0x0)) {
      uVar12 = FUN_1802ced60("UnityEngine.Component::get_gameObject()");
                    /* WARNING: Subroutine does not return */
      FUN_1802cca90(uVar12,0);
    }
    DAT_182ec1088 = pcVar6;
    uVar10 = (*DAT_182ec1088)(lVar7);
    if (*(int *)(DAT_182d58288 + 0xe0) == 0) {
      FUN_18035c820();
    }
    fVar16 = (float)ExposureUnnoticed2_Scripts_Base_ExternalMethodManager__DistSqrt__06001726
                              (uVar12,uVar10,0);
    if (fVar16 < 1.0) {
      lVar8 = *(longlong *)(lVar7 + 0x28);
      if (*(int *)(DAT_182d53aa8 + 0xe0) == 0) {
        FUN_18035c820();
      }
      if (DAT_182ec12f4 == '\0') {
        FUN_1802f2810(&DAT_182d53aa8);
        LOCK();
        UNLOCK();
        DAT_182ec12f4 = '\x01';
      }
      if (*(int *)(DAT_182d53aa8 + 0xe0) == 0) {
        FUN_18035c820();
      }
      if (DAT_182ec129b == '\0') {
        FUN_1802f2810(&DAT_182d53aa8);
        LOCK();
        UNLOCK();
        DAT_182ec129b = '\x01';
      }
      if (lVar8 != 0) {
        if (*(int *)(DAT_182d53aa8 + 0xe0) == 0) {
          FUN_18035c820();
        }
        if (((*(longlong *)(lVar8 + 0x10) != 0) && (*(int *)(lVar7 + 0x24) == 3)) &&
           (plVar2 = *(longlong **)(lVar7 + 0x28), plVar2 != (longlong *)0x0)) {
          if (((*(byte *)(lRam0000000182d59620 + 0x130) <= *(byte *)(*plVar2 + 0x130)) &&
              (*(longlong *)
                (*(longlong *)(*plVar2 + 200) + -8 +
                (ulonglong)*(byte *)(lRam0000000182d59620 + 0x130) * 8) == lRam0000000182d59620)) &&
             (*(int *)((longlong)plVar2 + 0x7c) != 0)) {
            iVar11 = (int)plVar2[4] + 1;
            iVar5 = *(int *)((longlong)plVar2 + 0x24);
            if (iVar11 <= *(int *)((longlong)plVar2 + 0x24)) {
              iVar5 = iVar11;
            }
            *(int *)(plVar2 + 4) = iVar5;
            if (((*(longlong *)(param_1 + 0x10) == 0) ||
                (lVar8 = *(longlong *)(*(longlong *)(param_1 + 0x10) + 0x40), lVar8 == 0)) ||
               (plVar2 = *(longlong **)(lVar8 + 0x40), plVar2 == (longlong *)0x0))
            goto code_r0x00018042dad6;
            (**(code **)(*plVar2 + 0x198))(plVar2,*(undefined8 *)(*plVar2 + 0x1a0));
            lVar8 = FUN_180436550();
            if (lVar8 == 0) goto code_r0x00018042dad6;
            ExposureUnnoticed2_Object3D_NPC_Script_SitNpcManager__UseEndByNpcByFloor__060010e6
                      (lVar8,lVar7,0);
            if ((*(longlong *)(param_1 + 0x10) == 0) ||
               (lVar8 = *(longlong *)(*(longlong *)(param_1 + 0x10) + 0x38), lVar8 == 0))
            goto code_r0x00018042dad6;
            ExposureUnnoticed2_Object3D_NPC_Script_NpcController__ChangeState__0600105f(lVar8,0,0);
          }
        }
      }
    }
    if ((*(longlong *)(param_1 + 0x10) == 0) ||
       (lVar8 = *(longlong *)(*(longlong *)(param_1 + 0x10) + 0x38), lVar8 == 0))
    goto code_r0x00018042dad6;
    uVar12 = *(undefined8 *)(lVar8 + 0x18);
    if (*(int *)(DAT_182d58288 + 0xe0) == 0) {
      FUN_18035c820();
    }
    uStack_98 = CONCAT44(fVar19,fVar18);
    fStack_90 = fVar17;
    fVar16 = (float)ExposureUnnoticed2_Scripts_Base_ExternalMethodManager__DistSqrt__0600172a
                              (uVar12,&uStack_98,0);
    if (fVar16 < 0.2) {
      lVar8 = *(longlong *)(param_1 + 0x10);
      if (lVar8 == 0) goto code_r0x00018042dad6;
      if (*(int *)(lVar7 + 0x24) != 0) {
        lVar7 = *(longlong *)(lVar8 + 0x38);
        if (lVar7 == 0) goto code_r0x00018042dad6;
        uVar12 = 5;
        goto code_r0x00018042cf0f;
      }
      if ((*(longlong *)(lVar8 + 0x40) == 0) ||
         (plVar2 = *(longlong **)(*(longlong *)(lVar8 + 0x40) + 0x40), plVar2 == (longlong *)0x0))
      goto code_r0x00018042dad6;
      lVar7 = (**(code **)(*plVar2 + 0x198))(plVar2,*(undefined8 *)(*plVar2 + 0x1a0));
      if (*(int *)(DAT_182d53aa8 + 0xe0) == 0) {
        FUN_18035c820();
      }
      if (DAT_182ec12f3 == '\0') {
        FUN_1802f2810(&DAT_182d53aa8);
        LOCK();
        UNLOCK();
        DAT_182ec12f3 = '\x01';
      }
      if (*(int *)(DAT_182d53aa8 + 0xe0) == 0) {
        FUN_18035c820();
      }
      if (DAT_182ec129b == '\0') {
        FUN_1802f2810(&DAT_182d53aa8);
        LOCK();
        UNLOCK();
        DAT_182ec129b = '\x01';
      }
      if (lVar7 == 0) {
        lVar8 = *(longlong *)(param_1 + 0x10);
      }
      else {
        if (*(int *)(DAT_182d53aa8 + 0xe0) == 0) {
          FUN_18035c820();
        }
        lVar8 = *(longlong *)(param_1 + 0x10);
        if (*(longlong *)(lVar7 + 0x10) != 0) {
          if ((lVar8 == 0) || (lVar7 = *(longlong *)(lVar8 + 0x28), lVar7 == 0)) {
                    /* WARNING: Subroutine does not return */
            FUN_18031dad0();
          }
          uStack_98 = CONCAT44(fVar19,fVar18);
          pcVar6 = DAT_182ebeeb0;
          fStack_90 = fVar17;
          if ((DAT_182ebeeb0 == (code *)0x0) &&
             (pcVar6 = (code *)FUN_1802cf0c0(
                                            "UnityEngine.AI.NavMeshAgent::SetDestination_Injected(UnityEngine.Vector3&)"
                                            ), pcVar6 == (code *)0x0)) {
            uVar12 = FUN_1802ced60(
                                  "UnityEngine.AI.NavMeshAgent::SetDestination_Injected(UnityEngine.Vector3&)"
                                  );
                    /* WARNING: Subroutine does not return */
            FUN_1802cca90(uVar12,0);
          }
          goto code_r0x00018042d475;
        }
      }
      if ((lVar8 != 0) && (lVar7 = *(longlong *)(lVar8 + 0x38), lVar7 != 0)) {
        uVar12 = 3;
code_r0x00018042cf0f:
        ExposureUnnoticed2_Object3D_NPC_Script_NpcController__ChangeState__0600105f(lVar7,uVar12,0);
        return;
      }
      goto code_r0x00018042dad6;
    }
  }
  if ((*(longlong *)(param_1 + 0x10) != 0) &&
     (lVar7 = *(longlong *)(*(longlong *)(param_1 + 0x10) + 0x28), lVar7 != 0)) {
    uStack_a8 = 0;
    uStack_a0 = uStack_a0 & 0xffffffff00000000;
    pcVar6 = DAT_182ebeec0;
    if ((DAT_182ebeec0 == (code *)0x0) &&
       (pcVar6 = (code *)FUN_1802cf0c0(
                                      "UnityEngine.AI.NavMeshAgent::get_steeringTarget_Injected(UnityEngine.Vector3&)"
                                      ), pcVar6 == (code *)0x0)) {
      uVar12 = FUN_1802ced60(
                            "UnityEngine.AI.NavMeshAgent::get_steeringTarget_Injected(UnityEngine.Vector3&)"
                            );
                    /* WARNING: Subroutine does not return */
      FUN_1802cca90(uVar12,0);
    }
    DAT_182ebeec0 = pcVar6;
    (*DAT_182ebeec0)(lVar7,&uStack_a8);
    if (((*(longlong *)(param_1 + 0x10) != 0) &&
        (lVar7 = *(longlong *)(*(longlong *)(param_1 + 0x10) + 0x38), lVar7 != 0)) &&
       (lVar7 = *(longlong *)(lVar7 + 0x10), lVar7 != 0)) {
      uStack_98 = 0;
      fStack_90 = 0.0;
      pcVar6 = DAT_182ec1698;
      if ((DAT_182ec1698 == (code *)0x0) &&
         (pcVar6 = (code *)FUN_1802cf0c0(
                                        "UnityEngine.Transform::get_position_Injected(UnityEngine.Vector3&)"
                                        ), pcVar6 == (code *)0x0)) {
        uVar12 = FUN_1802ced60("UnityEngine.Transform::get_position_Injected(UnityEngine.Vector3&)")
        ;
                    /* WARNING: Subroutine does not return */
        FUN_1802cca90(uVar12,0);
      }
      DAT_182ec1698 = pcVar6;
      (*DAT_182ec1698)(lVar7,&uStack_98);
      fVar16 = uStack_a8._4_4_ - uStack_98._4_4_;
      fVar17 = (float)uStack_a0 - fStack_90;
      fVar18 = (float)uStack_a8 - (float)uStack_98;
      uStack_80 = CONCAT44(uStack_80._4_4_,fVar17);
      uStack_88 = CONCAT44(fVar16,fVar18);
      if (0.001 < fVar16 * fVar16 + fVar18 * fVar18 + fVar17 * fVar17) {
        uStack_98 = CONCAT44(fVar16,fVar18);
        fStack_90 = fVar17;
        puVar9 = (undefined8 *)FUN_181f31160(&uStack_78,&uStack_98,0);
        uVar12 = *puVar9;
        uVar10 = puVar9[1];
      }
      else {
        if (DAT_182eb547f == '\0') {
          FUN_1802f2810(&DAT_182d52290);
          LOCK();
          UNLOCK();
          DAT_182eb547f = '\x01';
        }
        uVar12 = **(undefined8 **)(DAT_182d52290 + 0xb8);
        uVar10 = (*(undefined8 **)(DAT_182d52290 + 0xb8))[1];
      }
      *(undefined8 *)(param_1 + 0x38) = uVar12;
      *(undefined8 *)(param_1 + 0x40) = uVar10;
      lVar7 = ExposureUnnoticed2_Master_Common_MCommon__get_Instance__0600133e(0);
      if (lVar7 != 0) {
        fVar19 = *(float *)(lVar7 + 0x58) * 0.9;
        if (((*(longlong *)(param_1 + 0x10) != 0) &&
            (lVar7 = *(longlong *)(*(longlong *)(param_1 + 0x10) + 0x38), lVar7 != 0)) &&
           (lVar7 = *(longlong *)(lVar7 + 0x10), lVar7 != 0)) {
          puVar9 = (undefined8 *)FUN_181f4c360(&uStack_a8,lVar7,0);
          uStack_98 = *puVar9;
          fStack_90 = *(float *)(puVar9 + 1);
          uStack_a8 = CONCAT44(fVar16,fVar18);
          uStack_a0 = CONCAT44(uStack_a0._4_4_,fVar17);
          fVar17 = (float)FUN_1803fa290(&uStack_a8,&uStack_98);
          fVar16 = (float)FUN_1803d4630(&uStack_88);
          if (fVar16 < 4.0) {
            if (60.0 < fVar17) {
              fVar19 = fVar19 * 0.3;
            }
            else if (90.0 <= fVar17) {
              fVar19 = fVar19 * 0.1;
            }
          }
          if (((*(longlong *)(param_1 + 0x10) != 0) &&
              (lVar7 = *(longlong *)(*(longlong *)(param_1 + 0x10) + 0x38), lVar7 != 0)) &&
             (lVar7 = *(longlong *)(lVar7 + 0x10), lVar7 != 0)) {
            puVar9 = (undefined8 *)FUN_181f4c360(&uStack_88,lVar7,0);
            pcVar6 = DAT_182ec14e0;
            uStack_98 = *puVar9;
            fVar17 = *(float *)(puVar9 + 1);
            if ((*(longlong *)(param_1 + 0x10) != 0) &&
               (lVar7 = *(longlong *)(*(longlong *)(param_1 + 0x10) + 0x40), lVar7 != 0)) {
              fVar16 = *(float *)(lVar7 + 0x2c);
              lVar7 = *(longlong *)(*(longlong *)(param_1 + 0x10) + 0xa0);
              if ((lVar7 != 0) && (lVar7 = *(longlong *)(lVar7 + 0x20), lVar7 != 0)) {
                fVar18 = *(float *)(lVar7 + 0x10);
                *(ulonglong *)(param_1 + 0x1c) =
                     CONCAT44((float)((ulonglong)uStack_98 >> 0x20) * fVar19 * fVar16 * fVar18,
                              (float)uStack_98 * fVar19 * fVar16 * fVar18);
                *(float *)(param_1 + 0x24) = fVar17 * fVar19 * fVar16 * fVar18;
                pcVar4 = DAT_182ec14e0;
                if ((pcVar6 == (code *)0x0) &&
                   (pcVar6 = (code *)FUN_1802cf0c0("UnityEngine.Time::get_unscaledTime()"),
                   pcVar4 = pcVar6, pcVar6 == (code *)0x0)) {
                  uVar12 = FUN_1802ced60("UnityEngine.Time::get_unscaledTime()");
                    /* WARNING: Subroutine does not return */
                  FUN_1802cca90(uVar12,0);
                }
                DAT_182ec14e0 = pcVar4;
                fVar17 = (float)(*pcVar6)();
                if (0.5 < fVar17 - *(float *)(param_1 + 0x18)) {
                  if (*(longlong *)(param_1 + 0x10) == 0) goto code_r0x00018042dad6;
                  lVar7 = *(longlong *)(*(longlong *)(param_1 + 0x10) + 0x40);
                  if (DAT_182eb548c == '\0') {
                    FUN_1802f2810(&DAT_182d57a70);
                    LOCK();
                    UNLOCK();
                    DAT_182eb548c = '\x01';
                  }
                  if (((*(longlong *)(param_1 + 0x10) == 0) ||
                      (**(longlong **)(DAT_182d57a70 + 0xb8) == 0)) ||
                     (uVar12 = ExposureUnnoticed2_Object3D_NPC_Script_NpcManager__GetNearOtherNpc__060010a3
                                         (**(longlong **)(DAT_182d57a70 + 0xb8),
                                          *(undefined8 *)(*(longlong *)(param_1 + 0x10) + 0x38),0),
                     lVar7 == 0)) goto code_r0x00018042dad6;
                  bVar15 = DAT_182eb5d50 != 0;
                  *(undefined8 *)(lVar7 + 0x38) = uVar12;
                  if (bVar15) {
                    uVar14 = (uint)(lVar7 + 0x38U >> 0xc);
                    uVar13 = (ulonglong)((uVar14 & 0x1fffff) >> 6);
                    do {
                      uVar3 = *(ulonglong *)(&DAT_182f0c920 + uVar13 * 8);
                      LOCK();
                      bVar15 = uVar3 == *(ulonglong *)(&DAT_182f0c920 + uVar13 * 8);
                      if (bVar15) {
                        *(ulonglong *)(&DAT_182f0c920 + uVar13 * 8) = uVar3 | 1L << (uVar14 & 0x3f);
                      }
                      UNLOCK();
                    } while (!bVar15);
                  }
                  fVar17 = (float)FUN_181449130(0);
                  fVar16 = (float)FUN_181f373e0(0);
                  *(float *)(param_1 + 0x18) = fVar16 * 0.1 + fVar17;
                }
                if (((*(longlong *)(param_1 + 0x10) != 0) &&
                    (lVar7 = *(longlong *)(*(longlong *)(param_1 + 0x10) + 0x40), lVar7 != 0)) &&
                   (plVar2 = *(longlong **)(lVar7 + 0x40), plVar2 != (longlong *)0x0)) {
                  lVar7 = (**(code **)(*plVar2 + 0x188))(plVar2,*(undefined8 *)(*plVar2 + 400));
                  uStack_88 = *(undefined8 *)(param_1 + 0x2c);
                  fVar17 = *(float *)(param_1 + 0x34);
                  if (lVar7 != 0) {
                    puVar9 = (undefined8 *)
                             ExposureUnnoticed2_Object3D_RoutePoint_RoutePoint__get_Position__06000be9
                                       (&uStack_a8,lVar7,0);
                    uVar12 = *puVar9;
                    fVar16 = (float)uStack_88 - (float)uVar12;
                    fVar18 = uStack_88._4_4_ - (float)((ulonglong)uVar12 >> 0x20);
                    fVar17 = fVar17 - *(float *)(puVar9 + 1);
                    uStack_88 = uVar12;
                    if (9.9999994e-11 <= fVar18 * fVar18 + fVar16 * fVar16 + fVar17 * fVar17) {
                      if (((*(longlong *)(param_1 + 0x10) == 0) ||
                          (lVar8 = *(longlong *)(*(longlong *)(param_1 + 0x10) + 0x40), lVar8 == 0))
                         || (lVar8 = *(longlong *)(lVar8 + 0x40), lVar8 == 0))
                      goto code_r0x00018042dad6;
                      puVar9 = (undefined8 *)
                               ExposureUnnoticed2_Object3D_RoutePoint_RoutePoint__get_Position__06000be9
                                         (&uStack_98,lVar7,0);
                      fVar17 = *(float *)(lVar8 + 0x38);
                      fVar16 = *(float *)(lVar7 + 0x40);
                      uStack_88 = *puVar9;
                      if ((*(longlong *)(param_1 + 0x10) == 0) ||
                         (lVar8 = *(longlong *)(*(longlong *)(param_1 + 0x10) + 0x28), lVar8 == 0))
                      {
                    /* WARNING: Subroutine does not return */
                        FUN_18031dad0();
                      }
                      uStack_88 = CONCAT44((float)((ulonglong)*(undefined8 *)(lVar7 + 0x48) >> 0x20)
                                           * fVar17 * fVar16 + (float)((ulonglong)uStack_88 >> 0x20)
                                           ,(float)*(undefined8 *)(lVar7 + 0x48) * fVar17 * fVar16 +
                                            (float)uStack_88);
                      uStack_80 = CONCAT44(uStack_80._4_4_,
                                           *(float *)(lVar7 + 0x50) * fVar17 * fVar16 +
                                           *(float *)(puVar9 + 1));
                      pcVar6 = DAT_182ebeeb0;
                      if ((DAT_182ebeeb0 == (code *)0x0) &&
                         (pcVar6 = (code *)FUN_1802cf0c0(
                                                  "UnityEngine.AI.NavMeshAgent::SetDestination_Injected(UnityEngine.Vector3&)"
                                                  ), pcVar6 == (code *)0x0)) {
                        uVar12 = FUN_1802ced60(
                                              "UnityEngine.AI.NavMeshAgent::SetDestination_Injected(UnityEngine.Vector3&)"
                                              );
                    /* WARNING: Subroutine does not return */
                        FUN_1802cca90(uVar12,0);
                      }
                      DAT_182ebeeb0 = pcVar6;
                      (*DAT_182ebeeb0)(lVar8,&uStack_88);
                      puVar9 = (undefined8 *)
                               ExposureUnnoticed2_Object3D_RoutePoint_RoutePoint__get_Position__06000be9
                                         (&uStack_88,lVar7,0);
                      uVar1 = *(undefined4 *)(puVar9 + 1);
                      *(undefined8 *)(param_1 + 0x2c) = *puVar9;
                      *(undefined4 *)(param_1 + 0x34) = uVar1;
                    }
                    lVar7 = *(longlong *)(param_1 + 0x10);
                    if (lVar7 != 0) {
                      lVar8 = *(longlong *)(lVar7 + 0x28);
                      if ((*(longlong *)(lVar7 + 0x38) != 0) &&
                         (lVar7 = *(longlong *)(*(longlong *)(lVar7 + 0x38) + 0x10), lVar7 != 0)) {
                        uStack_98 = 0;
                        fStack_90 = 0.0;
                        pcVar6 = DAT_182ec1698;
                        if ((DAT_182ec1698 == (code *)0x0) &&
                           (pcVar6 = (code *)FUN_1802cf0c0(
                                                  "UnityEngine.Transform::get_position_Injected(UnityEngine.Vector3&)"
                                                  ), pcVar6 == (code *)0x0)) {
                          uVar12 = FUN_1802ced60(
                                                "UnityEngine.Transform::get_position_Injected(UnityEngine.Vector3&)"
                                                );
                    /* WARNING: Subroutine does not return */
                          FUN_1802cca90(uVar12,0);
                        }
                        DAT_182ec1698 = pcVar6;
                        (*DAT_182ec1698)(lVar7,&uStack_98);
                        if (lVar8 == 0) {
                    /* WARNING: Subroutine does not return */
                          FUN_18031dad0();
                        }
                        uStack_80 = CONCAT44(uStack_80._4_4_,fStack_90);
                        uStack_88 = uStack_98;
                        pcVar6 = DAT_182ebeeb8;
                        if ((DAT_182ebeeb8 == (code *)0x0) &&
                           (pcVar6 = (code *)FUN_1802cf0c0(
                                                  "UnityEngine.AI.NavMeshAgent::set_nextPosition_Injected(UnityEngine.Vector3&)"
                                                  ), pcVar6 == (code *)0x0)) {
                          uVar12 = FUN_1802ced60(
                                                "UnityEngine.AI.NavMeshAgent::set_nextPosition_Injected(UnityEngine.Vector3&)"
                                                );
                    /* WARNING: Subroutine does not return */
                          FUN_1802cca90(uVar12,0);
                        }
                        DAT_182ebeeb8 = pcVar6;
                        (*DAT_182ebeeb8)(lVar8,&uStack_88);
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
  }
code_r0x00018042dad6:
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

