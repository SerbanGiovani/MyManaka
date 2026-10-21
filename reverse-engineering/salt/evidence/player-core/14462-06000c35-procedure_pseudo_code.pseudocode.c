// Ghidra pseudocode; not original source or compilable C.
// ev_4bc94d10b5ed1a8fecf0fef73c5d5d9a7fa437b2af271d71ae50ac96cd730d0d

void ExposureUnnoticed2_Object3D_Player_Scripts_PlayerAction__OnUpdate__06000c35
               (longlong param_1,longlong param_2)

{
  float *pfVar1;
  float fVar2;
  longlong lVar3;
  longlong lVar4;
  char cVar5;
  uint uVar6;
  code *pcVar7;
  longlong lVar8;
  undefined8 uVar9;
  undefined8 *puVar10;
  undefined4 uVar11;
  int iVar12;
  float fVar13;
  float fVar14;
  float fVar15;
  float fVar16;
  float fVar17;
  float fVar18;
  undefined8 uStack_e8;
  float fStack_e0;
  float fStack_dc;
  undefined8 uStack_d8;
  float fStack_d0;
  undefined8 uStack_c8;
  undefined8 uStack_c0;
  undefined8 uStack_b8;
  float fStack_b0;
  float fStack_ac;
  undefined8 uStack_a8;
  undefined8 uStack_a0;
  undefined8 uStack_98;
  undefined8 uStack_90;
  
  if (cRam0000000182eb836e == '\0') {
    FUN_1802f2810(&DAT_182d5dae0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d58288);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d58398);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5ab80);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d53aa8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d58230);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d6f698);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d62c48);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d62c40);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d6f688);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d6f678);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d6f668);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d6f658);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d6f648);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d6f638);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d6f628);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d6f618);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d6f608);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d5e118);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d6f5f8);
    LOCK();
    UNLOCK();
    cRam0000000182eb836e = '\x01';
  }
  if (((*(longlong *)(param_1 + 0x30) == 0) ||
      (lVar8 = *(longlong *)(*(longlong *)(param_1 + 0x30) + 0x60), lVar8 == 0)) ||
     (lVar8 = *(longlong *)(lVar8 + 0x48), lVar8 == 0)) goto code_r0x000180627983;
  iVar12 = *(int *)(lVar8 + 0x18);
  if ((iVar12 < 0x272e) || (0x2772 < iVar12)) {
    if (*(int *)(*(longlong *)(*(longlong *)(*(longlong *)(param_1 + 0x30) + 0x60) + 0x48) + 0x18)
        == 0x277a) {
      lVar8 = *(longlong *)(*(longlong *)(*(longlong *)(param_1 + 0x30) + 0x60) + 0x188);
      if (lVar8 == 0) goto code_r0x000180627983;
      pcVar7 = DAT_182ec1088;
      if ((DAT_182ec1088 == (code *)0x0) &&
         (pcVar7 = (code *)FUN_1802cf0c0("UnityEngine.Component::get_gameObject()"),
         pcVar7 == (code *)0x0)) {
        uVar9 = FUN_1802ced60("UnityEngine.Component::get_gameObject()");
                    /* WARNING: Subroutine does not return */
        FUN_1802cca90(uVar9,0);
      }
      DAT_182ec1088 = pcVar7;
      lVar8 = (*DAT_182ec1088)(lVar8);
      if (lVar8 == 0) goto code_r0x000180627983;
      pcVar7 = DAT_182ec1148;
      if ((DAT_182ec1148 == (code *)0x0) &&
         (pcVar7 = (code *)FUN_1802cf0c0("UnityEngine.GameObject::get_activeInHierarchy()"),
         pcVar7 == (code *)0x0)) {
        uVar9 = FUN_1802ced60("UnityEngine.GameObject::get_activeInHierarchy()");
                    /* WARNING: Subroutine does not return */
        FUN_1802cca90(uVar9,0);
      }
      DAT_182ec1148 = pcVar7;
      cVar5 = (*DAT_182ec1148)(lVar8);
      if (cVar5 != '\0') {
        if ((*(longlong *)(param_1 + 0x30) == 0) ||
           (lVar8 = *(longlong *)(*(longlong *)(param_1 + 0x30) + 0x60), lVar8 == 0))
        goto code_r0x000180627983;
        *(undefined1 *)(lVar8 + 0x1b9) = 1;
        lVar8 = *(longlong *)(param_1 + 0x30);
        if (lVar8 == 0) goto code_r0x000180627983;
        lVar3 = *(longlong *)(lVar8 + 0x60);
        if (((*(longlong *)(lVar8 + 0x60) == 0) ||
            (lVar8 = *(longlong *)(*(longlong *)(lVar8 + 0x60) + 0x188), lVar8 == 0)) ||
           (lVar8 = FUN_181d769d0(lVar8,0), lVar8 == 0)) goto code_r0x000180627983;
        uStack_e8 = 0;
        fStack_e0 = 0.0;
        pcVar7 = DAT_182ec1698;
        if ((DAT_182ec1698 == (code *)0x0) &&
           (pcVar7 = (code *)FUN_1802cf0c0(
                                          "UnityEngine.Transform::get_position_Injected(UnityEngine.Vector3&)"
                                          ), pcVar7 == (code *)0x0)) {
          uVar9 = FUN_1802ced60("UnityEngine.Transform::get_position_Injected(UnityEngine.Vector3&)"
                               );
                    /* WARNING: Subroutine does not return */
          FUN_1802cca90(uVar9,0);
        }
        DAT_182ec1698 = pcVar7;
        (*DAT_182ec1698)(lVar8,&uStack_e8);
        *(undefined8 *)(lVar3 + 0x1bc) = uStack_e8;
        *(float *)(lVar3 + 0x1c4) = fStack_e0;
        lVar8 = *(longlong *)(param_1 + 0x30);
        if (lVar8 == 0) goto code_r0x000180627983;
        lVar3 = *(longlong *)(lVar8 + 0x60);
        if (((*(longlong *)(lVar8 + 0x60) == 0) ||
            (lVar8 = *(longlong *)(*(longlong *)(lVar8 + 0x60) + 0x188), lVar8 == 0)) ||
           (lVar8 = FUN_181d769d0(lVar8,0), lVar8 == 0)) goto code_r0x000180627983;
        uStack_98 = 0;
        uStack_90 = 0;
        pcVar7 = DAT_182ec16b8;
        if ((DAT_182ec16b8 == (code *)0x0) &&
           (pcVar7 = (code *)FUN_1802cf0c0(
                                          "UnityEngine.Transform::get_rotation_Injected(UnityEngine.Quaternion&)"
                                          ), pcVar7 == (code *)0x0)) {
          uVar9 = FUN_1802ced60(
                               "UnityEngine.Transform::get_rotation_Injected(UnityEngine.Quaternion&)"
                               );
                    /* WARNING: Subroutine does not return */
          FUN_1802cca90(uVar9,0);
        }
        DAT_182ec16b8 = pcVar7;
        (*DAT_182ec16b8)(lVar8,&uStack_98);
        *(undefined8 *)(lVar3 + 0x1c8) = uStack_98;
        *(undefined8 *)(lVar3 + 0x1d0) = uStack_90;
      }
    }
  }
  else {
    lVar8 = *(longlong *)(*(longlong *)(param_1 + 0x30) + 0x60);
    if ((lVar8 == 0) || (lVar8 = *(longlong *)(lVar8 + 0x180), lVar8 == 0))
    goto code_r0x000180627983;
    lVar8 = *(longlong *)(lVar8 + 0x18);
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
    if (lVar8 == 0) {
code_r0x000180625ec7:
      uVar11 = 0xffffffff;
    }
    else {
      if (*(int *)(DAT_182d53aa8 + 0xe0) == 0) {
        FUN_18035c820();
      }
      if (*(longlong *)(lVar8 + 0x10) == 0) goto code_r0x000180625ec7;
      if ((*(longlong *)(param_1 + 0x30) == 0) ||
         (lVar8 = *(longlong *)(*(longlong *)(param_1 + 0x30) + 0x60), lVar8 == 0))
      goto code_r0x000180627983;
      *(undefined1 *)(lVar8 + 0x1b9) = 1;
      if ((*(longlong *)(param_1 + 0x30) == 0) ||
         (((lVar8 = *(longlong *)(*(longlong *)(param_1 + 0x30) + 0x60), lVar8 == 0 ||
           (lVar8 = *(longlong *)(lVar8 + 0x180), lVar8 == 0)) ||
          (lVar8 = *(longlong *)(lVar8 + 0x18), lVar8 == 0)))) goto code_r0x000180627983;
      uStack_c8 = *(undefined8 *)(lVar8 + 0x50);
      fVar13 = *(float *)(lVar8 + 0x58);
      if (((*(longlong *)(param_1 + 0x30) == 0) ||
          (lVar8 = *(longlong *)(*(longlong *)(param_1 + 0x30) + 0x60), lVar8 == 0)) ||
         (lVar8 = *(longlong *)(lVar8 + 0x48), lVar8 == 0)) goto code_r0x000180627983;
      uStack_d8 = *(undefined8 *)(lVar8 + 0x68);
      fStack_d0 = *(float *)(lVar8 + 0x70);
      if (((*(longlong *)(param_1 + 0x30) == 0) ||
          (lVar8 = *(longlong *)(*(longlong *)(param_1 + 0x30) + 0x60), lVar8 == 0)) ||
         (lVar8 = *(longlong *)(lVar8 + 0x48), lVar8 == 0)) goto code_r0x000180627983;
      fVar18 = *(float *)(lVar8 + 0x70);
      lVar8 = *(longlong *)(*(longlong *)(param_1 + 0x30) + 0x170);
      if (lVar8 == 0) goto code_r0x000180627983;
      fVar15 = *(float *)(lVar8 + 0x28);
      fVar14 = *(float *)(*(longlong *)(*(longlong *)(*(longlong *)(param_1 + 0x30) + 0x60) + 0x48)
                         + 100);
      if (*(int *)(DAT_182d58288 + 0xe0) == 0) {
        FUN_18035c820();
      }
      fVar17 = (float)uStack_c8 + (float)uStack_d8;
      fVar16 = uStack_c8._4_4_ + uStack_d8._4_4_;
      if ((((*(longlong *)(param_1 + 0x30) == 0) ||
           (lVar8 = *(longlong *)(*(longlong *)(param_1 + 0x30) + 0x60), lVar8 == 0)) ||
          (lVar8 = *(longlong *)(lVar8 + 0x180), lVar8 == 0)) ||
         (lVar8 = *(longlong *)(lVar8 + 0x18), lVar8 == 0)) goto code_r0x000180627983;
      pcVar7 = DAT_182ec1080;
      if ((DAT_182ec1080 == (code *)0x0) &&
         (pcVar7 = (code *)FUN_1802cf0c0("UnityEngine.Component::get_transform()"),
         pcVar7 == (code *)0x0)) {
        uVar9 = FUN_1802ced60("UnityEngine.Component::get_transform()");
                    /* WARNING: Subroutine does not return */
        FUN_1802cca90(uVar9,0);
      }
      DAT_182ec1080 = pcVar7;
      lVar8 = (*DAT_182ec1080)(lVar8);
      if (lVar8 == 0) goto code_r0x000180627983;
      uStack_e8 = 0;
      fStack_e0 = 0.0;
      pcVar7 = DAT_182ec1698;
      if ((DAT_182ec1698 == (code *)0x0) &&
         (pcVar7 = (code *)FUN_1802cf0c0(
                                        "UnityEngine.Transform::get_position_Injected(UnityEngine.Vector3&)"
                                        ), pcVar7 == (code *)0x0)) {
        uVar9 = FUN_1802ced60("UnityEngine.Transform::get_position_Injected(UnityEngine.Vector3&)");
                    /* WARNING: Subroutine does not return */
        FUN_1802cca90(uVar9,0);
      }
      DAT_182ec1698 = pcVar7;
      (*DAT_182ec1698)(lVar8,&uStack_e8);
      if ((((*(longlong *)(param_1 + 0x30) == 0) ||
           (lVar8 = *(longlong *)(*(longlong *)(param_1 + 0x30) + 0x60), lVar8 == 0)) ||
          (lVar8 = *(longlong *)(lVar8 + 0x180), lVar8 == 0)) ||
         (lVar8 = *(longlong *)(lVar8 + 0x18), lVar8 == 0)) goto code_r0x000180627983;
      pcVar7 = DAT_182ec1080;
      if ((DAT_182ec1080 == (code *)0x0) &&
         (pcVar7 = (code *)FUN_1802cf0c0("UnityEngine.Component::get_transform()"),
         pcVar7 == (code *)0x0)) {
        uVar9 = FUN_1802ced60("UnityEngine.Component::get_transform()");
                    /* WARNING: Subroutine does not return */
        FUN_1802cca90(uVar9,0);
      }
      DAT_182ec1080 = pcVar7;
      lVar8 = (*DAT_182ec1080)(lVar8);
      if (lVar8 == 0) goto code_r0x000180627983;
      puVar10 = (undefined8 *)FUN_181f4c360(&uStack_b8,lVar8,0);
      uVar9 = *puVar10;
      fVar2 = *(float *)(puVar10 + 1);
      if ((*(longlong *)(param_1 + 0x30) == 0) ||
         (lVar8 = *(longlong *)(*(longlong *)(param_1 + 0x30) + 0x18), lVar8 == 0))
      goto code_r0x000180627983;
      puVar10 = (undefined8 *)FUN_181f4c0e0(&uStack_b8,lVar8,0);
      uStack_c8 = *puVar10;
      uStack_98 = 0;
      uStack_90 = 0;
      pcVar7 = DAT_182ec0ea8;
      uStack_d8 = uVar9;
      fStack_d0 = fVar2;
      uStack_c0._0_4_ = *(undefined4 *)(puVar10 + 1);
      if ((DAT_182ec0ea8 == (code *)0x0) &&
         (pcVar7 = (code *)FUN_1802cf0c0(
                                        "UnityEngine.Quaternion::LookRotation_Injected(UnityEngine.Vector3&,UnityEngine.Vector3&,UnityEngine.Quaternion&)"
                                        ), pcVar7 == (code *)0x0)) {
        uVar9 = FUN_1802ced60(
                             "UnityEngine.Quaternion::LookRotation_Injected(UnityEngine.Vector3&,UnityEngine.Vector3&,UnityEngine.Quaternion&)"
                             );
                    /* WARNING: Subroutine does not return */
        FUN_1802cca90(uVar9,0);
      }
      DAT_182ec0ea8 = pcVar7;
      (*DAT_182ec0ea8)(&uStack_d8,&uStack_c8,&uStack_98);
      uStack_c0 = CONCAT44(uStack_c0._4_4_,fVar15 * fVar18 + fVar14 + fVar13);
      uStack_c8 = CONCAT44(fVar16,fVar17);
      puVar10 = (undefined8 *)FUN_181f31290(&uStack_b8,&uStack_98,&uStack_c8,0);
      uStack_c8 = *puVar10;
      fVar13 = *(float *)(puVar10 + 1);
      if ((*(longlong *)(param_1 + 0x30) == 0) ||
         (lVar8 = *(longlong *)(*(longlong *)(param_1 + 0x30) + 0x60), lVar8 == 0))
      goto code_r0x000180627983;
      *(ulonglong *)(lVar8 + 0x1bc) =
           CONCAT44(uStack_e8._4_4_ + (float)((ulonglong)uStack_c8 >> 0x20),
                    (float)uStack_e8 + (float)uStack_c8);
      *(float *)(lVar8 + 0x1c4) = fStack_e0 + fVar13;
      if ((*(longlong *)(param_1 + 0x30) == 0) ||
         (((lVar8 = *(longlong *)(*(longlong *)(param_1 + 0x30) + 0x60), lVar8 == 0 ||
           (lVar8 = *(longlong *)(lVar8 + 0x180), lVar8 == 0)) ||
          (lVar8 = *(longlong *)(lVar8 + 0x18), lVar8 == 0)))) goto code_r0x000180627983;
      pcVar7 = DAT_182ec1080;
      if ((DAT_182ec1080 == (code *)0x0) &&
         (pcVar7 = (code *)FUN_1802cf0c0("UnityEngine.Component::get_transform()"),
         pcVar7 == (code *)0x0)) {
        uVar9 = FUN_1802ced60("UnityEngine.Component::get_transform()");
                    /* WARNING: Subroutine does not return */
        FUN_1802cca90(uVar9,0);
      }
      DAT_182ec1080 = pcVar7;
      lVar8 = (*DAT_182ec1080)(lVar8);
      if (lVar8 == 0) goto code_r0x000180627983;
      uStack_98 = 0;
      uStack_90 = 0;
      pcVar7 = DAT_182ec16b8;
      if ((DAT_182ec16b8 == (code *)0x0) &&
         (pcVar7 = (code *)FUN_1802cf0c0(
                                        "UnityEngine.Transform::get_rotation_Injected(UnityEngine.Quaternion&)"
                                        ), pcVar7 == (code *)0x0)) {
        uVar9 = FUN_1802ced60(
                             "UnityEngine.Transform::get_rotation_Injected(UnityEngine.Quaternion&)"
                             );
                    /* WARNING: Subroutine does not return */
        FUN_1802cca90(uVar9,0);
      }
      DAT_182ec16b8 = pcVar7;
      (*DAT_182ec16b8)(lVar8,&uStack_98);
      puVar10 = (undefined8 *)FUN_1803fa4b0(&uStack_c8,&uStack_98);
      uStack_b8 = *puVar10;
      fVar13 = *(float *)(puVar10 + 1);
      if ((((*(longlong *)(param_1 + 0x30) == 0) ||
           (lVar8 = *(longlong *)(*(longlong *)(param_1 + 0x30) + 0x60), lVar8 == 0)) ||
          (lVar8 = *(longlong *)(lVar8 + 0x180), lVar8 == 0)) ||
         (lVar8 = *(longlong *)(lVar8 + 0x18), lVar8 == 0)) goto code_r0x000180627983;
      pcVar7 = DAT_182ec1080;
      if ((DAT_182ec1080 == (code *)0x0) &&
         (pcVar7 = (code *)FUN_1802cf0c0("UnityEngine.Component::get_transform()"),
         pcVar7 == (code *)0x0)) {
        uVar9 = FUN_1802ced60("UnityEngine.Component::get_transform()");
                    /* WARNING: Subroutine does not return */
        FUN_1802cca90(uVar9,0);
      }
      DAT_182ec1080 = pcVar7;
      lVar8 = (*DAT_182ec1080)(lVar8);
      if (lVar8 == 0) goto code_r0x000180627983;
      uStack_98 = 0;
      uStack_90 = 0;
      pcVar7 = DAT_182ec16b8;
      if ((DAT_182ec16b8 == (code *)0x0) &&
         (pcVar7 = (code *)FUN_1802cf0c0(
                                        "UnityEngine.Transform::get_rotation_Injected(UnityEngine.Quaternion&)"
                                        ), pcVar7 == (code *)0x0)) {
        uVar9 = FUN_1802ced60(
                             "UnityEngine.Transform::get_rotation_Injected(UnityEngine.Quaternion&)"
                             );
                    /* WARNING: Subroutine does not return */
        FUN_1802cca90(uVar9,0);
      }
      DAT_182ec16b8 = pcVar7;
      (*DAT_182ec16b8)(lVar8,&uStack_98);
      lVar8 = FUN_1803fa4b0(&uStack_c8,&uStack_98);
      if (((*(longlong *)(param_1 + 0x30) == 0) ||
          (lVar3 = *(longlong *)(*(longlong *)(param_1 + 0x30) + 0x60), lVar3 == 0)) ||
         (lVar3 = *(longlong *)(lVar3 + 0x48), lVar3 == 0)) goto code_r0x000180627983;
      lVar4 = *(longlong *)(*(longlong *)(param_1 + 0x30) + 0x60);
      fStack_d0 = fVar13 * 0.017453292;
      uStack_d8 = CONCAT44((*(float *)(lVar8 + 4) + *(float *)(lVar3 + 0x60)) * 0.017453292,
                           (float)uStack_b8 * 0.017453292);
      uStack_98 = 0;
      uStack_90 = 0;
      pcVar7 = DAT_182ec0e88;
      if ((DAT_182ec0e88 == (code *)0x0) &&
         (pcVar7 = (code *)FUN_1802cf0c0(
                                        "UnityEngine.Quaternion::Internal_FromEulerRad_Injected(UnityEngine.Vector3&,UnityEngine.Quaternion&)"
                                        ), pcVar7 == (code *)0x0)) {
        uVar9 = FUN_1802ced60(
                             "UnityEngine.Quaternion::Internal_FromEulerRad_Injected(UnityEngine.Vector3&,UnityEngine.Quaternion&)"
                             );
                    /* WARNING: Subroutine does not return */
        FUN_1802cca90(uVar9,0);
      }
      DAT_182ec0e88 = pcVar7;
      (*DAT_182ec0e88)(&uStack_d8,&uStack_98);
      *(undefined8 *)(lVar4 + 0x1c8) = uStack_98;
      *(undefined8 *)(lVar4 + 0x1d0) = uStack_90;
      if ((*(longlong *)(param_1 + 0x30) == 0) ||
         (lVar8 = *(longlong *)(*(longlong *)(param_1 + 0x30) + 0x60), lVar8 == 0))
      goto code_r0x000180627983;
      if ((*(int *)(lVar8 + 0x234) == -1) ||
         (*(char *)(*(longlong *)(*(longlong *)(param_1 + 0x30) + 0x60) + 0x50) != '\0'))
      goto code_r0x000180625ed7;
      uVar11 = *(undefined4 *)(*(longlong *)(*(longlong *)(param_1 + 0x30) + 0x60) + 0x234);
    }
    ExposureUnnoticed2_Object3D_Player_Scripts_PlayerAction__ChangeAction__06000c36
              (param_1,uVar11,0);
  }
code_r0x000180625ed7:
  if (((*(longlong *)(param_1 + 0x30) == 0) ||
      (lVar8 = *(longlong *)(*(longlong *)(param_1 + 0x30) + 0x60), lVar8 == 0)) ||
     (lVar8 = *(longlong *)(lVar8 + 0x48), lVar8 == 0)) goto code_r0x000180627983;
  if (*(int *)(lVar8 + 0x18) == 0x2718) {
    pcVar7 = DAT_182ec14c0;
    if ((DAT_182ec14c0 == (code *)0x0) &&
       (pcVar7 = (code *)FUN_1802cf0c0("UnityEngine.Time::get_time()"), pcVar7 == (code *)0x0)) {
      uVar9 = FUN_1802ced60("UnityEngine.Time::get_time()");
                    /* WARNING: Subroutine does not return */
      FUN_1802cca90(uVar9,0);
    }
    DAT_182ec14c0 = pcVar7;
    fVar13 = (float)(*DAT_182ec14c0)();
    if ((*(longlong *)(param_1 + 0x30) == 0) ||
       (lVar8 = *(longlong *)(*(longlong *)(param_1 + 0x30) + 0x60), lVar8 == 0))
    goto code_r0x000180627983;
    pfVar1 = (float *)(lVar8 + 0x178);
    if (fVar13 < *pfVar1 || fVar13 == *pfVar1) {
      return;
    }
    lVar8 = *(longlong *)(*(longlong *)(*(longlong *)(param_1 + 0x30) + 0x60) + 0x170);
    if (lVar8 != 0) {
      (**(code **)(lVar8 + 0x18))(*(undefined8 *)(lVar8 + 0x40),*(undefined8 *)(lVar8 + 0x28));
    }
    goto code_r0x00018062784b;
  }
  iVar12 = *(int *)(*(longlong *)(*(longlong *)(*(longlong *)(param_1 + 0x30) + 0x60) + 0x48) + 0x18
                   );
  if ((((iVar12 == 0x272a) || (iVar12 == 0x272b)) || (iVar12 - 0x2775U < 4)) || (iVar12 == 0x2779))
  {
    if (((*(longlong *)(param_1 + 0x30) == 0) ||
        (lVar8 = *(longlong *)(*(longlong *)(param_1 + 0x30) + 0x60), lVar8 == 0)) ||
       ((lVar8 = *(longlong *)(lVar8 + 0x180), lVar8 == 0 ||
        (lVar8 = *(longlong *)(lVar8 + 0x18), lVar8 == 0)))) goto code_r0x000180627983;
    uStack_e8 = *(undefined8 *)(lVar8 + 0x50);
    fVar13 = *(float *)(lVar8 + 0x58);
    if ((*(longlong *)(param_1 + 0x30) == 0) ||
       (lVar8 = *(longlong *)(*(longlong *)(param_1 + 0x30) + 0x18), lVar8 == 0))
    goto code_r0x000180627983;
    puVar10 = (undefined8 *)FUN_181f4c360(&uStack_b8,lVar8,0);
    uVar9 = *puVar10;
    fVar18 = *(float *)(puVar10 + 1);
    if (DAT_182eb547c == '\0') {
      FUN_1802f2810(&DAT_182d522a8);
      LOCK();
      UNLOCK();
      DAT_182eb547c = '\x01';
    }
    uStack_c8 = *(undefined8 *)(*(longlong *)(DAT_182d522a8 + 0xb8) + 0x18);
    uStack_c0 = CONCAT44(uStack_c0._4_4_,*(undefined4 *)(*(longlong *)(DAT_182d522a8 + 0xb8) + 0x20)
                        );
    uStack_98 = 0;
    uStack_90 = 0;
    pcVar7 = DAT_182ec0ea8;
    uStack_d8 = uVar9;
    fStack_d0 = fVar18;
    if ((DAT_182ec0ea8 == (code *)0x0) &&
       (pcVar7 = (code *)FUN_1802cf0c0(
                                      "UnityEngine.Quaternion::LookRotation_Injected(UnityEngine.Vector3&,UnityEngine.Vector3&,UnityEngine.Quaternion&)"
                                      ), pcVar7 == (code *)0x0)) {
      uVar9 = FUN_1802ced60(
                           "UnityEngine.Quaternion::LookRotation_Injected(UnityEngine.Vector3&,UnityEngine.Vector3&,UnityEngine.Quaternion&)"
                           );
                    /* WARNING: Subroutine does not return */
      FUN_1802cca90(uVar9,0);
    }
    DAT_182ec0ea8 = pcVar7;
    (*DAT_182ec0ea8)(&uStack_d8,&uStack_c8,&uStack_98);
    lVar8 = *(longlong *)(param_1 + 0x30);
    if ((lVar8 == 0) || (*(longlong *)(lVar8 + 0x170) == 0)) goto code_r0x000180627983;
    uStack_c8 = (ulonglong)(uint)((*(float *)(*(longlong *)(lVar8 + 0x170) + 0x28) - 1.0) * -0.47)
                << 0x20;
    uStack_c0 = CONCAT44(uStack_c0._4_4_,
                         (*(float *)(*(longlong *)(lVar8 + 0x170) + 0x28) - 1.0) * 0.19);
    puVar10 = (undefined8 *)FUN_181f31290(&uStack_b8,&uStack_98,&uStack_c8,0);
    uStack_c8 = *puVar10;
    fVar18 = *(float *)(puVar10 + 1);
    *(ulonglong *)(param_1 + 0x10) =
         CONCAT44(uStack_e8._4_4_ + (float)((ulonglong)uStack_c8 >> 0x20),
                  (float)uStack_e8 + (float)uStack_c8);
    *(float *)(param_1 + 0x18) = fVar13 + fVar18;
    if ((*(longlong *)(param_1 + 0x30) == 0) ||
       (((lVar8 = *(longlong *)(*(longlong *)(param_1 + 0x30) + 0x60), lVar8 == 0 ||
         (lVar8 = *(longlong *)(lVar8 + 0x180), lVar8 == 0)) ||
        (lVar8 = *(longlong *)(lVar8 + 0x18), lVar8 == 0)))) goto code_r0x000180627983;
    pcVar7 = DAT_182ec1080;
    if ((DAT_182ec1080 == (code *)0x0) &&
       (pcVar7 = (code *)FUN_1802cf0c0("UnityEngine.Component::get_transform()"),
       pcVar7 == (code *)0x0)) {
      uVar9 = FUN_1802ced60("UnityEngine.Component::get_transform()");
                    /* WARNING: Subroutine does not return */
      FUN_1802cca90(uVar9,0);
    }
    DAT_182ec1080 = pcVar7;
    lVar8 = (*DAT_182ec1080)(lVar8);
    if (lVar8 == 0) goto code_r0x000180627983;
    uStack_e8 = 0;
    fStack_e0 = 0.0;
    pcVar7 = DAT_182ec1698;
    if ((DAT_182ec1698 == (code *)0x0) &&
       (pcVar7 = (code *)FUN_1802cf0c0(
                                      "UnityEngine.Transform::get_position_Injected(UnityEngine.Vector3&)"
                                      ), pcVar7 == (code *)0x0)) {
      uVar9 = FUN_1802ced60("UnityEngine.Transform::get_position_Injected(UnityEngine.Vector3&)");
                    /* WARNING: Subroutine does not return */
      FUN_1802cca90(uVar9,0);
    }
    DAT_182ec1698 = pcVar7;
    (*DAT_182ec1698)(lVar8,&uStack_e8);
    uStack_b8 = *(undefined8 *)(param_1 + 0x10);
    fVar13 = fStack_e0 + *(float *)(param_1 + 0x18);
    uStack_c8 = CONCAT44(uStack_e8._4_4_ + (float)((ulonglong)uStack_b8 >> 0x20),
                         (float)uStack_e8 + (float)uStack_b8);
    if ((((*(longlong *)(param_1 + 0x30) == 0) ||
         (lVar8 = *(longlong *)(*(longlong *)(param_1 + 0x30) + 0x60), lVar8 == 0)) ||
        (lVar8 = *(longlong *)(lVar8 + 0x180), lVar8 == 0)) ||
       (lVar8 = *(longlong *)(lVar8 + 0x18), lVar8 == 0)) goto code_r0x000180627983;
    pcVar7 = DAT_182ec1080;
    if ((DAT_182ec1080 == (code *)0x0) &&
       (pcVar7 = (code *)FUN_1802cf0c0("UnityEngine.Component::get_transform()"),
       pcVar7 == (code *)0x0)) {
      uVar9 = FUN_1802ced60("UnityEngine.Component::get_transform()");
                    /* WARNING: Subroutine does not return */
      FUN_1802cca90(uVar9,0);
    }
    DAT_182ec1080 = pcVar7;
    lVar8 = (*DAT_182ec1080)(lVar8);
    if (lVar8 == 0) goto code_r0x000180627983;
    uStack_a8 = 0;
    uStack_a0 = 0;
    pcVar7 = DAT_182ec16b8;
    if ((DAT_182ec16b8 == (code *)0x0) &&
       (pcVar7 = (code *)FUN_1802cf0c0(
                                      "UnityEngine.Transform::get_rotation_Injected(UnityEngine.Quaternion&)"
                                      ), pcVar7 == (code *)0x0)) {
      uVar9 = FUN_1802ced60("UnityEngine.Transform::get_rotation_Injected(UnityEngine.Quaternion&)")
      ;
                    /* WARNING: Subroutine does not return */
      FUN_1802cca90(uVar9,0);
    }
    DAT_182ec16b8 = pcVar7;
    (*DAT_182ec16b8)(lVar8,&uStack_a8);
    fVar18 = (float)uStack_a8;
    fVar15 = uStack_a8._4_4_;
    fVar14 = (float)uStack_a0;
    fVar17 = uStack_a0._4_4_;
    if (((*(longlong *)(param_1 + 0x30) == 0) ||
        (lVar8 = *(longlong *)(*(longlong *)(param_1 + 0x30) + 0x60), lVar8 == 0)) ||
       (lVar8 = *(longlong *)(lVar8 + 0x48), lVar8 == 0)) goto code_r0x000180627983;
    if (*(int *)(lVar8 + 0x18) == 0x272b) {
      lVar8 = *(longlong *)(*(longlong *)(*(longlong *)(param_1 + 0x30) + 0x60) + 0x180);
      if (((lVar8 == 0) || (lVar8 = *(longlong *)(lVar8 + 0x18), lVar8 == 0)) ||
         (lVar8 = FUN_181d769d0(lVar8,0), lVar8 == 0)) goto code_r0x000180627983;
      uStack_d8 = 0;
      fStack_d0 = 0.0;
      pcVar7 = DAT_182ec1698;
      if ((DAT_182ec1698 == (code *)0x0) &&
         (pcVar7 = (code *)FUN_1802cf0c0(
                                        "UnityEngine.Transform::get_position_Injected(UnityEngine.Vector3&)"
                                        ), pcVar7 == (code *)0x0)) {
        uVar9 = FUN_1802ced60("UnityEngine.Transform::get_position_Injected(UnityEngine.Vector3&)");
                    /* WARNING: Subroutine does not return */
        FUN_1802cca90(uVar9,0);
      }
      DAT_182ec1698 = pcVar7;
      (*DAT_182ec1698)(lVar8,&uStack_d8);
      fVar13 = fStack_d0;
      uStack_c8 = uStack_d8;
      if ((((*(longlong *)(param_1 + 0x30) == 0) ||
           (lVar8 = *(longlong *)(*(longlong *)(param_1 + 0x30) + 0x60), lVar8 == 0)) ||
          (lVar8 = *(longlong *)(lVar8 + 0x180), lVar8 == 0)) ||
         (lVar8 = *(longlong *)(lVar8 + 0x18), lVar8 == 0)) goto code_r0x000180627983;
      if (*(char *)(lVar8 + 0x60) != '\0') {
        if (DAT_182eb547c == '\0') {
          FUN_1802f2810(&DAT_182d522a8);
          LOCK();
          UNLOCK();
          DAT_182eb547c = '\x01';
        }
        uStack_b8 = *(undefined8 *)(*(longlong *)(DAT_182d522a8 + 0xb8) + 0x18);
        fStack_b0 = *(float *)(*(longlong *)(DAT_182d522a8 + 0xb8) + 0x20);
        uStack_98 = 0;
        uStack_90 = 0;
        pcVar7 = DAT_182ec0ea0;
        if ((DAT_182ec0ea0 == (code *)0x0) &&
           (pcVar7 = (code *)FUN_1802cf0c0(
                                          "UnityEngine.Quaternion::AngleAxis_Injected(System.Single,UnityEngine.Vector3&,UnityEngine.Quaternion&)"
                                          ), pcVar7 == (code *)0x0)) {
          uVar9 = FUN_1802ced60(
                               "UnityEngine.Quaternion::AngleAxis_Injected(System.Single,UnityEngine.Vector3&,UnityEngine.Quaternion&)"
                               );
                    /* WARNING: Subroutine does not return */
          FUN_1802cca90(uVar9,0);
        }
        DAT_182ec0ea0 = pcVar7;
        (*DAT_182ec0ea0)();
        fVar18 = ((float)uStack_98 * uStack_a0._4_4_ + uStack_90._4_4_ * (float)uStack_a8 +
                 (float)uStack_90 * uStack_a8._4_4_) - uStack_98._4_4_ * (float)uStack_a0;
        fVar15 = (uStack_98._4_4_ * uStack_a0._4_4_ + uStack_90._4_4_ * uStack_a8._4_4_ +
                 (float)uStack_98 * (float)uStack_a0) - (float)uStack_90 * (float)uStack_a8;
        fVar14 = ((float)uStack_90 * uStack_a0._4_4_ + uStack_90._4_4_ * (float)uStack_a0 +
                 uStack_98._4_4_ * (float)uStack_a8) - (float)uStack_98 * uStack_a8._4_4_;
        fVar17 = ((uStack_90._4_4_ * uStack_a0._4_4_ - (float)uStack_98 * (float)uStack_a8) -
                 uStack_98._4_4_ * uStack_a8._4_4_) - (float)uStack_90 * (float)uStack_a0;
        uStack_e8 = CONCAT44(fVar15,fVar18);
        fStack_e0 = fVar14;
        fStack_dc = fVar17;
      }
    }
    if ((*(longlong *)(param_1 + 0x30) == 0) ||
       (lVar8 = *(longlong *)(*(longlong *)(param_1 + 0x30) + 0x60), lVar8 == 0))
    goto code_r0x000180627983;
    *(undefined1 *)(lVar8 + 0x1d8) = 1;
    if (*(longlong *)(param_1 + 0x30) == 0) goto code_r0x000180627983;
    lVar8 = *(longlong *)(*(longlong *)(param_1 + 0x30) + 0x60);
    lVar3 = *(longlong *)(*(longlong *)(param_1 + 0x30) + 0x18);
    if (lVar3 == 0) goto code_r0x000180627983;
    uStack_e8 = 0;
    fStack_e0 = 0.0;
    pcVar7 = DAT_182ec1698;
    if ((DAT_182ec1698 == (code *)0x0) &&
       (pcVar7 = (code *)FUN_1802cf0c0(
                                      "UnityEngine.Transform::get_position_Injected(UnityEngine.Vector3&)"
                                      ), pcVar7 == (code *)0x0)) {
      uVar9 = FUN_1802ced60("UnityEngine.Transform::get_position_Injected(UnityEngine.Vector3&)");
                    /* WARNING: Subroutine does not return */
      FUN_1802cca90(uVar9,0);
    }
    DAT_182ec1698 = pcVar7;
    (*DAT_182ec1698)(lVar3,&uStack_e8);
    if (lVar8 == 0) goto code_r0x000180627983;
    *(ulonglong *)(lVar8 + 0x1dc) =
         CONCAT44((uStack_c8._4_4_ - uStack_e8._4_4_) * 0.1 + uStack_e8._4_4_,
                  ((float)uStack_c8 - (float)uStack_e8) * 0.1 + (float)uStack_e8);
    *(float *)(lVar8 + 0x1e4) = (fVar13 - fStack_e0) * 0.1 + fStack_e0;
    if (*(longlong *)(param_1 + 0x30) == 0) goto code_r0x000180627983;
    lVar8 = *(longlong *)(*(longlong *)(param_1 + 0x30) + 0x60);
    lVar3 = *(longlong *)(*(longlong *)(param_1 + 0x30) + 0x18);
    if (lVar3 == 0) goto code_r0x000180627983;
    uStack_98 = 0;
    uStack_90 = 0;
    pcVar7 = DAT_182ec16b8;
    if ((DAT_182ec16b8 == (code *)0x0) &&
       (pcVar7 = (code *)FUN_1802cf0c0(
                                      "UnityEngine.Transform::get_rotation_Injected(UnityEngine.Quaternion&)"
                                      ), pcVar7 == (code *)0x0)) {
      uVar9 = FUN_1802ced60("UnityEngine.Transform::get_rotation_Injected(UnityEngine.Quaternion&)")
      ;
                    /* WARNING: Subroutine does not return */
      FUN_1802cca90(uVar9,0);
    }
    DAT_182ec16b8 = pcVar7;
    (*DAT_182ec16b8)(lVar3,&uStack_98);
    uStack_b8 = CONCAT44(fVar15,fVar18);
    uStack_c8 = uStack_98;
    uStack_c0 = uStack_90;
    uStack_a8 = 0;
    uStack_a0 = 0;
    pcVar7 = DAT_182ec0e80;
    fStack_b0 = fVar14;
    fStack_ac = fVar17;
    if ((DAT_182ec0e80 == (code *)0x0) &&
       (pcVar7 = (code *)FUN_1802cf0c0(
                                      "UnityEngine.Quaternion::Lerp_Injected(UnityEngine.Quaternion&,UnityEngine.Quaternion&,System.Single,UnityEngine.Quaternion&)"
                                      ), pcVar7 == (code *)0x0)) {
      uVar9 = FUN_1802ced60(
                           "UnityEngine.Quaternion::Lerp_Injected(UnityEngine.Quaternion&,UnityEngine.Quaternion&,System.Single,UnityEngine.Quaternion&)"
                           );
                    /* WARNING: Subroutine does not return */
      FUN_1802cca90(uVar9,0);
    }
    DAT_182ec0e80 = pcVar7;
    (*DAT_182ec0e80)(&uStack_c8,&uStack_b8);
    if (lVar8 == 0) goto code_r0x000180627983;
    *(undefined8 *)(lVar8 + 0x1e8) = uStack_a8;
    *(undefined8 *)(lVar8 + 0x1f0) = uStack_a0;
    if ((*(longlong *)(param_1 + 0x30) == 0) ||
       (lVar8 = *(longlong *)(*(longlong *)(param_1 + 0x30) + 0x60), lVar8 == 0))
    goto code_r0x000180627983;
    if (*(char *)(lVar8 + 0x23a) != '\0') {
      if (param_2 == 0) goto code_r0x000180627983;
      if ((*(char *)(param_2 + 0x2e) != '\0') &&
         (*(char *)(*(longlong *)(*(longlong *)(param_1 + 0x30) + 0x60) + 0x50) == '\0')) {
        lVar8 = *(longlong *)(*(longlong *)(*(longlong *)(param_1 + 0x30) + 0x60) + 0x48);
        if (lVar8 == 0) goto code_r0x000180627983;
        iVar12 = *(int *)(lVar8 + 0x18);
        if ((iVar12 == 0x272a) || (iVar12 == 0x2775)) {
          iVar12 = 0x272b;
          goto code_r0x00018062607b;
        }
      }
    }
    lVar8 = *(longlong *)(param_1 + 0x30);
    if (*(int *)(*(longlong *)(lVar8 + 0x60) + 0x234) == -1) {
      return;
    }
    if (*(char *)(*(longlong *)(lVar8 + 0x60) + 0x50) != '\0') {
      return;
    }
    lVar8 = *(longlong *)(lVar8 + 0x60);
code_r0x0001806277ca:
    iVar12 = *(int *)(lVar8 + 0x234);
  }
  else {
    if (param_2 == 0) goto code_r0x000180627983;
    if (*(char *)(param_2 + 0x50) != '\0') {
      if (*(longlong *)(param_1 + 0x28) == 0) goto code_r0x000180627983;
      if (*(char *)(*(longlong *)(param_1 + 0x28) + 0x50) == '\0') {
        lVar8 = **(longlong **)(DAT_182d58230 + 0xb8);
        if (lVar8 == 0) goto code_r0x000180627983;
        if (DAT_182eb83fe == '\0') {
          FUN_1802f2810(&DAT_182d3e668);
          LOCK();
          UNLOCK();
          FUN_1802f2810(&DAT_182d3e660);
          LOCK();
          UNLOCK();
          FUN_1802f2810(&DAT_182d5e118);
          LOCK();
          UNLOCK();
          DAT_182eb83fe = '\x01';
        }
        cVar5 = ExposureUnnoticed2_Scripts_InGame_GameStateFacade__IsAttachSomeHandcuffs__0600155d
                          (0);
        uVar9 = DAT_182d3e660;
        if (cVar5 == '\0') {
          if ((*(longlong *)(lVar8 + 0x10) == 0) ||
             (lVar3 = *(longlong *)(*(longlong *)(lVar8 + 0x10) + 0x60), lVar3 == 0))
          goto code_r0x000180627983;
          uVar9 = DAT_182d3e668;
          if (*(char *)(lVar3 + 0x1b) == '\0') {
            if (*(longlong *)(lVar3 + 0x48) == 0) goto code_r0x000180627983;
            uVar9 = DAT_182d5e118;
            if (((*(int *)(*(longlong *)(lVar3 + 0x48) + 0x18) == -1) &&
                (lVar8 = *(longlong *)(*(longlong *)(lVar8 + 0x10) + 0x60),
                *(int *)(lVar8 + 0x5c) == 0)) && (*(char *)(lVar8 + 0x50) == '\0')) {
              lVar8 = FUN_180436330();
              if (lVar8 == 0) goto code_r0x000180627983;
              uVar9 = DAT_182d5e118;
              if (*(char *)(lVar8 + 0x10) == '\0') {
                if ((*(longlong *)(param_1 + 0x28) == 0) ||
                   (lVar8 = *(longlong *)(*(longlong *)(param_1 + 0x28) + 0x48), lVar8 == 0))
                goto code_r0x000180627983;
                if (*(int *)(lVar8 + 0x18) != 0) {
                  iVar12 = 0;
                  goto code_r0x00018062607b;
                }
                goto code_r0x00018062784b;
              }
            }
          }
        }
        uVar9 = ExposureUnnoticed2_Scripts_Base_Localizer__Trans__060017af(uVar9,0);
        ExposureUnnoticed2_ObjectUI_InGame_MessagePanel_MessagePanelView__AddMessage__06001b14
                  (uVar9,0,0);
      }
    }
    if (*(int *)(param_2 + 0x4c) == 0) {
code_r0x000180626367:
      if ((*(longlong *)(param_1 + 0x28) == 0) ||
         (lVar8 = *(longlong *)(*(longlong *)(param_1 + 0x28) + 0x48), lVar8 == 0))
      goto code_r0x000180627983;
      if (*(int *)(lVar8 + 0x18) != 0xc363) {
code_r0x0001806263f3:
        if ((*(longlong *)(param_1 + 0x28) == 0) ||
           (lVar8 = *(longlong *)(*(longlong *)(param_1 + 0x28) + 0x48), lVar8 == 0))
        goto code_r0x000180627983;
        if (*(int *)(lVar8 + 0x18) == 0xc35d) {
          if (**(longlong **)(DAT_182d58230 + 0xb8) == 0) goto code_r0x000180627983;
          uVar6 = ExposureUnnoticed2_Object3D_Player_Scripts_PlayerFacade__GetExposedBodyPartsByClothesAndCostume__06000d9f
                            (**(longlong **)(DAT_182d58230 + 0xb8),0);
          if (*(int *)(DAT_182d58288 + 0xe0) == 0) {
            FUN_18035c820();
          }
          if ((uVar6 & 0x2a) == 0) goto code_r0x00018062784b;
        }
        if (0.0 < *(float *)(param_2 + 0x10) * *(float *)(param_2 + 0x10) +
                  *(float *)(param_2 + 0x14) * *(float *)(param_2 + 0x14) +
                  *(float *)(param_2 + 0x18) * *(float *)(param_2 + 0x18)) {
          lVar8 = *(longlong *)(param_1 + 0x28);
          if (lVar8 == 0) goto code_r0x000180627983;
          if (*(char *)(lVar8 + 0x50) == '\0') {
            if (*(longlong *)(lVar8 + 0x48) == 0) goto code_r0x000180627983;
            if (*(char *)(*(longlong *)(lVar8 + 0x48) + 0x1f) != '\0') {
              if ((*(longlong *)(param_1 + 0x30) == 0) ||
                 (lVar8 = *(longlong *)(*(longlong *)(param_1 + 0x30) + 0x60), lVar8 == 0))
              goto code_r0x000180627983;
              fVar13 = *(float *)(lVar8 + 0x204);
              goto joined_r0x0001806264ca;
            }
          }
        }
        if ((*(char *)(param_2 + 0x26) != '\0') &&
           (0.0 < *(float *)(param_2 + 0x10) * *(float *)(param_2 + 0x10) +
                  *(float *)(param_2 + 0x14) * *(float *)(param_2 + 0x14) +
                  *(float *)(param_2 + 0x18) * *(float *)(param_2 + 0x18))) {
          lVar8 = *(longlong *)(param_1 + 0x28);
          if (lVar8 == 0) goto code_r0x000180627983;
          if (*(char *)(lVar8 + 0x50) == '\0') {
            if (*(longlong *)(lVar8 + 0x48) == 0) goto code_r0x000180627983;
            if (((*(char *)(*(longlong *)(lVar8 + 0x48) + 0x1c) != '\0') &&
                (*(char *)(*(longlong *)(lVar8 + 0x48) + 0x1d) == '\0')) &&
               (*(int *)(*(longlong *)(lVar8 + 0x48) + 0x18) != -1)) goto code_r0x00018062784b;
          }
        }
        if (*(char *)(param_2 + 0x31) != '\0') {
          if ((*(longlong *)(param_1 + 0x28) == 0) ||
             (lVar8 = *(longlong *)(*(longlong *)(param_1 + 0x28) + 0x48), lVar8 == 0))
          goto code_r0x000180627983;
          if (*(int *)(lVar8 + 0x18) == -1) {
            lVar8 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
            if (lVar8 == 0) goto code_r0x000180627983;
            if (*(int *)(lVar8 + 0x1a0) != -1) {
              if (((*(longlong *)(param_1 + 0x30) == 0) ||
                  (lVar8 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48), lVar8 == 0))
                 || (lVar3 = *(longlong *)(*(longlong *)(param_1 + 0x30) + 0x60), lVar3 == 0))
              goto code_r0x000180627983;
              *(undefined4 *)(lVar3 + 0x214) = *(undefined4 *)(lVar8 + 0x1a0);
              iVar12 = 0x2712;
              goto code_r0x00018062607b;
            }
          }
        }
        if (*(char *)(param_2 + 0x32) != '\0') {
          if (*(longlong *)(param_1 + 0x28) == 0) goto code_r0x000180627983;
          cVar5 = ExposureUnnoticed2_Object3D_Player_Scripts_PlayerStateModel__get_IsPlayingAction__06000e29
                            (*(longlong *)(param_1 + 0x28),0);
          if (cVar5 == '\0') {
            cVar5 = ExposureUnnoticed2_Scripts_InGame_GameStateFacade__IsAttachSomeHandcuffs__0600155d
                              (0);
            uVar9 = uRam0000000182d6f5f8;
            if (cVar5 == '\0') goto code_r0x000180626350;
            lVar8 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
            if (lVar8 == 0) goto code_r0x000180627983;
            if (*(int *)(lVar8 + 0x1ac) != 4) goto code_r0x000180626350;
            if (*(longlong *)(lVar8 + 0x218) == 0) goto code_r0x000180627983;
            iVar12 = FUN_180e71cd0(*(longlong *)(lVar8 + 0x218),10000,DAT_182d5dae0);
            uVar9 = uRam0000000182d62c48;
            if (iVar12 == 0) goto code_r0x000180626350;
            if ((*(longlong *)(param_1 + 0x30) == 0) ||
               (lVar8 = *(longlong *)(*(longlong *)(param_1 + 0x30) + 0x60), lVar8 == 0))
            goto code_r0x000180627983;
            *(undefined4 *)(lVar8 + 0x218) = 5;
            iVar12 = 0x2712;
            goto code_r0x00018062607b;
          }
        }
        if (*(char *)(param_2 + 0x33) != '\0') {
          if (*(longlong *)(param_1 + 0x28) == 0) goto code_r0x000180627983;
          cVar5 = ExposureUnnoticed2_Object3D_Player_Scripts_PlayerStateModel__get_IsPlayingAction__06000e29
                            (*(longlong *)(param_1 + 0x28),0);
          if (cVar5 == '\0') {
            lVar8 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
            if ((lVar8 == 0) || (lVar8 = *(longlong *)(lVar8 + 0x218), lVar8 == 0))
            goto code_r0x000180627983;
            iVar12 = FUN_180e71cd0(lVar8,0x2711,DAT_182d5dae0);
            uVar9 = uRam0000000182d62c40;
            if (iVar12 == 0) goto code_r0x000180626350;
            if ((*(longlong *)(param_1 + 0x30) == 0) ||
               (lVar8 = *(longlong *)(*(longlong *)(param_1 + 0x30) + 0x60), lVar8 == 0))
            goto code_r0x000180627983;
            *(undefined4 *)(lVar8 + 0x218) = 6;
            iVar12 = 0x2712;
            goto code_r0x00018062607b;
          }
        }
        if (*(char *)(param_2 + 0x30) != '\0') {
          if ((*(longlong *)(param_1 + 0x28) == 0) ||
             (lVar8 = *(longlong *)(*(longlong *)(param_1 + 0x28) + 0x48), lVar8 == 0))
          goto code_r0x000180627983;
          if (0 < *(int *)(lVar8 + 0x34)) {
            if ((*(longlong *)(param_1 + 0x30) != 0) &&
               (lVar8 = *(longlong *)(*(longlong *)(param_1 + 0x30) + 0x48), lVar8 != 0)) {
              ExposureUnnoticed2_Object3D_Player_Scripts_PlayerAnimationManager__RotateAnotherMotionIndex__06000c8d
                        (lVar8,0,0);
              return;
            }
            goto code_r0x000180627983;
          }
        }
        if (*(char *)(param_2 + 0x3a) != '\0') {
          if (*(longlong *)(param_1 + 0x28) == 0) goto code_r0x000180627983;
          cVar5 = ExposureUnnoticed2_Object3D_Player_Scripts_PlayerStateModel__get_IsPlayingAction__06000e29
                            (*(longlong *)(param_1 + 0x28),0);
          if (cVar5 == '\0') {
            if (((*(longlong *)(param_1 + 0x30) == 0) ||
                (lVar8 = *(longlong *)(*(longlong *)(param_1 + 0x30) + 0x70), lVar8 == 0)) ||
               (lVar8 = *(longlong *)(lVar8 + 0x260), lVar8 == 0)) goto code_r0x000180627983;
            cVar5 = FUN_181f3eb30(lVar8,0);
            if (cVar5 != '\0') {
              if (**(longlong **)(DAT_182d58230 + 0xb8) == 0) goto code_r0x000180627983;
              cVar5 = ExposureUnnoticed2_Object3D_Player_Scripts_PlayerFacade__CanUseHand__06000da6
                                (**(longlong **)(DAT_182d58230 + 0xb8),1,0,0,0,0,0);
              if (cVar5 == '\0') {
                return;
              }
              cVar5 = ExposureUnnoticed2_Scripts_InGame_GameStateFacade__IsRelease__0600155e(0,0);
              uVar9 = uRam0000000182d6f608;
              if (cVar5 == '\0') goto code_r0x000180626350;
              iVar12 = 0x271e;
              goto code_r0x00018062607b;
            }
          }
        }
        if (*(char *)(param_2 + 0x39) != '\0') {
          if (*(longlong *)(param_1 + 0x28) == 0) goto code_r0x000180627983;
          cVar5 = ExposureUnnoticed2_Object3D_Player_Scripts_PlayerStateModel__get_IsPlayingAction__06000e29
                            (*(longlong *)(param_1 + 0x28),0);
          if (cVar5 == '\0') {
            if (((*(longlong *)(param_1 + 0x30) == 0) ||
                (lVar8 = *(longlong *)(*(longlong *)(param_1 + 0x30) + 0x70), lVar8 == 0)) ||
               (lVar8 = *(longlong *)(lVar8 + 0x268), lVar8 == 0)) goto code_r0x000180627983;
            cVar5 = FUN_181f3eb30(lVar8,0);
            if (cVar5 != '\0') {
              if (**(longlong **)(DAT_182d58230 + 0xb8) == 0) goto code_r0x000180627983;
              cVar5 = ExposureUnnoticed2_Object3D_Player_Scripts_PlayerFacade__CanUseHand__06000da6
                                (**(longlong **)(DAT_182d58230 + 0xb8),1,0,0,0,0,0);
              if (cVar5 == '\0') {
                return;
              }
              cVar5 = ExposureUnnoticed2_Scripts_InGame_GameStateFacade__IsRelease__0600155e(0,0);
              uVar9 = uRam0000000182d6f608;
              if (cVar5 == '\0') goto code_r0x000180626350;
              iVar12 = 0x2720;
              goto code_r0x00018062607b;
            }
          }
        }
        if (*(longlong *)(param_1 + 0x28) == 0) {
code_r0x000180627983:
                    /* WARNING: Subroutine does not return */
          FUN_18031dad0();
        }
        cVar5 = ExposureUnnoticed2_Object3D_Player_Scripts_PlayerStateModel__get_IsPlayingAction__06000e29
                          (*(longlong *)(param_1 + 0x28),0);
        if (cVar5 == '\0') {
          if ((*(longlong *)(param_1 + 0x30) == 0) ||
             (lVar8 = *(longlong *)(*(longlong *)(param_1 + 0x30) + 0x60), lVar8 == 0))
          goto code_r0x000180627983;
          if (*(char *)(lVar8 + 0x230) != '\0') {
            iVar12 = 0x2711;
            goto code_r0x00018062607b;
          }
        }
        if (*(char *)(param_2 + 0x3e) != '\0') {
          if (((*(longlong *)(param_1 + 0x30) == 0) ||
              (lVar8 = *(longlong *)(*(longlong *)(param_1 + 0x30) + 0x60), lVar8 == 0)) ||
             (lVar8 = *(longlong *)(lVar8 + 0x48), lVar8 == 0)) goto code_r0x000180627983;
          if (*(int *)(lVar8 + 0x18) != 0x2728) {
            if (**(longlong **)(DAT_182d58230 + 0xb8) == 0) goto code_r0x000180627983;
            cVar5 = ExposureUnnoticed2_Object3D_Player_Scripts_PlayerFacade__CanUseHand__06000da6
                              (**(longlong **)(DAT_182d58230 + 0xb8),1,0,0,0,0,0);
            if (cVar5 != '\0') {
              lVar8 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
              if ((lVar8 == 0) || (lVar8 = *(longlong *)(lVar8 + 0x218), lVar8 == 0))
              goto code_r0x000180627983;
              iVar12 = FUN_180e71cd0(lVar8,0x2711,DAT_182d5dae0);
              uVar9 = uRam0000000182d62c40;
              if (iVar12 != 0) {
                if ((*(longlong *)(param_1 + 0x30) == 0) ||
                   (lVar8 = *(longlong *)(*(longlong *)(param_1 + 0x30) + 0x60), lVar8 == 0))
                goto code_r0x000180627983;
                uVar9 = uRam0000000182d6f658;
                if (0.0 < *(float *)(lVar8 + 0xf8)) {
                  iVar12 = 0x2728;
                  goto code_r0x00018062607b;
                }
              }
              uVar9 = ExposureUnnoticed2_Scripts_Base_Localizer__Trans__060017af(uVar9,0);
              ExposureUnnoticed2_ObjectUI_InGame_MessagePanel_MessagePanelView__AddMessage__06001b14
                        (uVar9,0,0);
            }
          }
        }
        if (*(char *)(param_2 + 0x3f) != '\0') {
          if (((*(longlong *)(param_1 + 0x30) == 0) ||
              (lVar8 = *(longlong *)(*(longlong *)(param_1 + 0x30) + 0x60), lVar8 == 0)) ||
             (lVar8 = *(longlong *)(lVar8 + 0x48), lVar8 == 0)) goto code_r0x000180627983;
          if (*(int *)(lVar8 + 0x18) != 8) {
            if (**(longlong **)(DAT_182d58230 + 0xb8) == 0) goto code_r0x000180627983;
            cVar5 = ExposureUnnoticed2_Object3D_Player_Scripts_PlayerFacade__CanUseHand__06000da6
                              (**(longlong **)(DAT_182d58230 + 0xb8),1,0,0,0,0,0);
            if (cVar5 != '\0') {
              cVar5 = ExposureUnnoticed2_Scripts_InGame_GameStateFacade__IsBringAdultGoods__0600153b
                                (8,0);
              if (((cVar5 != '\0') ||
                  (cVar5 = ExposureUnnoticed2_Scripts_InGame_GameStateFacade__IsBringAdultGoods__0600153b
                                     (9,0), cVar5 != '\0')) ||
                 (cVar5 = ExposureUnnoticed2_Scripts_InGame_GameStateFacade__IsBringAdultGoods__0600153b
                                    (10,0), cVar5 != '\0')) {
                iVar12 = 8;
                goto code_r0x00018062607b;
              }
              uVar9 = ExposureUnnoticed2_Scripts_Base_Localizer__Trans__060017af
                                (uRam0000000182d6f698,0);
              ExposureUnnoticed2_ObjectUI_InGame_MessagePanel_MessagePanelView__AddMessage__06001b14
                        (uVar9,0,0);
            }
          }
        }
        if (*(char *)(param_2 + 0x36) != '\0') {
          if (((*(longlong *)(param_1 + 0x30) == 0) ||
              (lVar8 = *(longlong *)(*(longlong *)(param_1 + 0x30) + 0x60), lVar8 == 0)) ||
             (lVar8 = *(longlong *)(lVar8 + 0x48), lVar8 == 0)) goto code_r0x000180627983;
          if (*(int *)(lVar8 + 0x18) != 7) {
            if (**(longlong **)(DAT_182d58230 + 0xb8) == 0) goto code_r0x000180627983;
            cVar5 = ExposureUnnoticed2_Object3D_Player_Scripts_PlayerFacade__CanUseHand__06000da6
                              (**(longlong **)(DAT_182d58230 + 0xb8),1,0,0,0,0,0);
            if (cVar5 != '\0') {
              cVar5 = ExposureUnnoticed2_Scripts_InGame_GameStateFacade__IsActivePassiveSkill__06001525
                                (0x11,0);
              uVar9 = uRam0000000182d6f688;
              if (cVar5 == '\0') goto code_r0x000180626350;
              iVar12 = 7;
              goto code_r0x00018062607b;
            }
          }
        }
        if (*(char *)(param_2 + 0x40) != '\0') {
          if (**(longlong **)(DAT_182d58230 + 0xb8) == 0) goto code_r0x000180627983;
          cVar5 = ExposureUnnoticed2_Object3D_Player_Scripts_PlayerFacade__CanUseHand__06000da6
                            (**(longlong **)(DAT_182d58230 + 0xb8),1,0,0,0,0,0);
          if (cVar5 != '\0') {
            cVar5 = ExposureUnnoticed2_Scripts_InGame_GameStateFacade__IsBringItem__06001552(1,0);
            uVar9 = uRam0000000182d6f638;
            if (cVar5 != '\0') {
              uVar9 = ExposureUnnoticed2_Master_Item_MItem__Get__0600127c(1,0);
              ExposureUnnoticed2_Master_Item_MItem__UseItemProcess__0600127e(uVar9,0);
              return;
            }
            goto code_r0x000180626350;
          }
        }
        if (*(char *)(param_2 + 0x41) != '\0') {
          if (**(longlong **)(DAT_182d58230 + 0xb8) == 0) goto code_r0x000180627983;
          cVar5 = ExposureUnnoticed2_Object3D_Player_Scripts_PlayerFacade__CanUseHand__06000da6
                            (**(longlong **)(DAT_182d58230 + 0xb8),1,0,0,0,0,0);
          if (cVar5 != '\0') {
            uVar9 = ExposureUnnoticed2_Master_AdultGoods_MAdultGoods__Get__06001380(3,0);
            ExposureUnnoticed2_Master_AdultGoods_MAdultGoods__UseItemProcess__06001382(uVar9,0);
            return;
          }
        }
        if (*(char *)(param_2 + 0x42) != '\0') {
          if (**(longlong **)(DAT_182d58230 + 0xb8) == 0) goto code_r0x000180627983;
          cVar5 = ExposureUnnoticed2_Object3D_Player_Scripts_PlayerFacade__CanUseHand__06000da6
                            (**(longlong **)(DAT_182d58230 + 0xb8),1,0,0,0,0,0);
          if (cVar5 != '\0') {
            uVar9 = ExposureUnnoticed2_Master_AdultGoods_MAdultGoods__Get__06001380(2,0);
            ExposureUnnoticed2_Master_AdultGoods_MAdultGoods__UseItemProcess__06001382(uVar9,0);
          }
        }
        if (*(char *)(param_2 + 0x3c) != '\0') {
          if (**(longlong **)(DAT_182d58230 + 0xb8) == 0) goto code_r0x000180627983;
          cVar5 = ExposureUnnoticed2_Object3D_Player_Scripts_PlayerFacade__CanUseHand__06000da6
                            (**(longlong **)(DAT_182d58230 + 0xb8),1,0,0,0,0,0);
          if (cVar5 != '\0') {
            cVar5 = ExposureUnnoticed2_Scripts_InGame_GameStateFacade__IsBringItem__06001552(0,0);
            uVar9 = uRam0000000182d6f648;
            if (cVar5 == '\0') goto code_r0x000180626350;
            uVar9 = ExposureUnnoticed2_Master_Item_MItem__Get__0600127c(0,0);
            ExposureUnnoticed2_Master_Item_MItem__UseItemProcess__0600127e(uVar9,0);
          }
        }
        if (*(char *)(param_2 + 0x3d) != '\0') {
          if (**(longlong **)(DAT_182d58230 + 0xb8) == 0) goto code_r0x000180627983;
          cVar5 = ExposureUnnoticed2_Object3D_Player_Scripts_PlayerFacade__CanUseHand__06000da6
                            (**(longlong **)(DAT_182d58230 + 0xb8),1,0,0,0,0,0);
          if (cVar5 != '\0') {
            cVar5 = ExposureUnnoticed2_Scripts_InGame_GameStateFacade__IsBringAdultGoods__0600153b
                              (2,0);
            uVar9 = uRam0000000182d6f678;
            if (cVar5 == '\0') {
code_r0x000180626350:
              uVar9 = ExposureUnnoticed2_Scripts_Base_Localizer__Trans__060017af(uVar9,0);
              ExposureUnnoticed2_ObjectUI_InGame_MessagePanel_MessagePanelView__AddMessage__06001b14
                        (uVar9,0,0);
              return;
            }
            uVar9 = ExposureUnnoticed2_Master_AdultGoods_MAdultGoods__Get__06001380(2,0);
            ExposureUnnoticed2_Master_AdultGoods_MAdultGoods__UseItemProcess__06001382(uVar9,0);
          }
        }
        if (*(int *)(lRam0000000182d5ab80 + 0xe0) == 0) {
          FUN_18035c820();
        }
        lVar8 = ExposureUnnoticed2_Scripts_Base_InteractManager__GetHead__06001796(0);
        if (lVar8 == 0) goto code_r0x000180627983;
        if (*(int *)(lVar8 + 0x10) == 4) {
          if ((*(longlong *)(param_1 + 0x30) == 0) ||
             (lVar8 = *(longlong *)(*(longlong *)(param_1 + 0x30) + 0x60), lVar8 == 0))
          goto code_r0x000180627983;
          if (*(char *)(lVar8 + 0x231) != '\0') {
            if (**(longlong **)(DAT_182d58230 + 0xb8) == 0) goto code_r0x000180627983;
            cVar5 = ExposureUnnoticed2_Object3D_Player_Scripts_PlayerFacade__CanUseHand__06000da6
                              (**(longlong **)(DAT_182d58230 + 0xb8),1,0,0,0,0,0);
            if (cVar5 != '\0') {
              lVar8 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
              if (lVar8 == 0) goto code_r0x000180627983;
              if (*(int *)(lVar8 + 0x1c4) == 5) {
                if ((*(longlong *)(param_1 + 0x30) == 0) ||
                   (lVar8 = *(longlong *)(*(longlong *)(param_1 + 0x30) + 0x68), lVar8 == 0))
                goto code_r0x000180627983;
                ExposureUnnoticed2_Object3D_Player_Scripts_PlayerAction__ChangeAction__06000c36
                          (lVar8,10000,0);
              }
              else {
                uVar9 = ExposureUnnoticed2_Scripts_Base_Localizer__Trans__060017af
                                  (uRam0000000182d6f628,0);
                ExposureUnnoticed2_ObjectUI_InGame_MessagePanel_MessagePanelView__AddMessage__06001b14
                          (uVar9,0,0);
              }
            }
          }
        }
        if (*(longlong *)(param_1 + 0x28) == 0) goto code_r0x000180627983;
        cVar5 = ExposureUnnoticed2_Object3D_Player_Scripts_PlayerStateModel__get_IsPlayingAction__06000e29
                          (*(longlong *)(param_1 + 0x28),0);
        if (cVar5 != '\0') {
          return;
        }
        if ((*(longlong *)(param_1 + 0x30) == 0) ||
           (lVar8 = *(longlong *)(*(longlong *)(param_1 + 0x30) + 0x60), lVar8 == 0))
        goto code_r0x000180627983;
        if (*(int *)(lVar8 + 0x234) == -1) {
          return;
        }
        if (**(longlong **)(DAT_182d58230 + 0xb8) == 0) goto code_r0x000180627983;
        cVar5 = ExposureUnnoticed2_Object3D_Player_Scripts_PlayerFacade__CanUseHand__06000da6
                          (**(longlong **)(DAT_182d58230 + 0xb8),1,
                           *(undefined1 *)
                            (*(longlong *)(*(longlong *)(param_1 + 0x30) + 0x60) + 0x238),0,0,0,0);
        if (cVar5 == '\0') {
          return;
        }
        if ((*(longlong *)(param_1 + 0x30) == 0) ||
           (lVar8 = *(longlong *)(*(longlong *)(param_1 + 0x30) + 0x60), lVar8 == 0))
        goto code_r0x000180627983;
        *(undefined1 *)(lVar8 + 0x238) = 0;
        if ((*(longlong *)(param_1 + 0x30) == 0) ||
           (lVar8 = *(longlong *)(*(longlong *)(param_1 + 0x30) + 0x60), lVar8 == 0))
        goto code_r0x000180627983;
        goto code_r0x0001806277ca;
      }
      if (**(longlong **)(DAT_182d58230 + 0xb8) == 0) goto code_r0x000180627983;
      uVar6 = ExposureUnnoticed2_Object3D_Player_Scripts_PlayerFacade__GetExposedBodyPartsByClothesAndCostume__06000d9f
                        (**(longlong **)(DAT_182d58230 + 0xb8),0);
      if (*(int *)(DAT_182d58288 + 0xe0) == 0) {
        FUN_18035c820();
      }
      if ((uVar6 & 0x2a) != 0) {
        if ((*(longlong *)(param_1 + 0x30) == 0) ||
           (lVar8 = *(longlong *)(*(longlong *)(param_1 + 0x30) + 0x60), lVar8 == 0))
        goto code_r0x000180627983;
        if (*(char *)(lVar8 + 0x1b2) == '\0') goto code_r0x0001806263f3;
      }
    }
    else {
      if (((*(longlong *)(param_1 + 0x30) == 0) ||
          (lVar8 = *(longlong *)(*(longlong *)(param_1 + 0x30) + 0x60), lVar8 == 0)) ||
         ((lVar8 = *(longlong *)(lVar8 + 0x48), lVar8 == 0 ||
          (iVar12 = *(int *)(lVar8 + 0x18), **(longlong **)(DAT_182d58230 + 0xb8) == 0))))
      goto code_r0x000180627983;
      cVar5 = ExposureUnnoticed2_Object3D_Player_Scripts_PlayerFacade__CanUseHand__06000da6
                        (**(longlong **)(DAT_182d58230 + 0xb8),1,0,0,
                         49999 < iVar12 && iVar12 < 0xea61,0,0);
      if (cVar5 == '\0') goto code_r0x000180626367;
      if ((*(longlong *)(param_1 + 0x30) == 0) ||
         (lVar8 = *(longlong *)(*(longlong *)(param_1 + 0x30) + 0x60), lVar8 == 0))
      goto code_r0x000180627983;
      uVar9 = DAT_182d5e118;
      if (*(char *)(lVar8 + 0x120) != '\0') goto code_r0x000180626350;
      lVar8 = ExposureUnnoticed2_Master_Skill_MSkill__GetByIndex__06001233
                        (*(int *)(param_2 + 0x4c) + -10000,0);
      if (lVar8 == 0) goto code_r0x000180627983;
      iVar12 = *(int *)(lVar8 + 0x3c) + 40000;
      if (iVar12 == 0xc363) {
        if (**(longlong **)(DAT_182d58230 + 0xb8) == 0) goto code_r0x000180627983;
        uVar6 = ExposureUnnoticed2_Object3D_Player_Scripts_PlayerFacade__GetExposedBodyPartsByClothesAndCostume__06000d9f
                          (**(longlong **)(DAT_182d58230 + 0xb8),0);
        if (*(int *)(DAT_182d58288 + 0xe0) == 0) {
          FUN_18035c820();
        }
        uVar9 = uRam0000000182d6f618;
        if ((uVar6 & 0x2a) == 0) goto code_r0x000180626350;
        if ((*(longlong *)(param_1 + 0x30) == 0) ||
           (lVar8 = *(longlong *)(*(longlong *)(param_1 + 0x30) + 0x60), lVar8 == 0))
        goto code_r0x000180627983;
        if (*(char *)(lVar8 + 0x1b2) != '\0') goto code_r0x000180626350;
        lVar8 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
        if (lVar8 == 0) goto code_r0x000180627983;
        uVar9 = uRam0000000182d6f668;
        if (*(char *)(lVar8 + 0x1dc) == '\0') goto code_r0x000180626350;
      }
      else if (iVar12 == 0xc35d) {
        if (**(longlong **)(DAT_182d58230 + 0xb8) == 0) goto code_r0x000180627983;
        uVar6 = ExposureUnnoticed2_Object3D_Player_Scripts_PlayerFacade__GetExposedBodyPartsByClothesAndCostume__06000d9f
                          (**(longlong **)(DAT_182d58230 + 0xb8),0);
        if (*(int *)(DAT_182d58288 + 0xe0) == 0) {
          FUN_18035c820();
        }
        uVar9 = uRam0000000182d6f618;
        if ((uVar6 & 0x2a) == 0) goto code_r0x000180626350;
      }
      if (((*(longlong *)(param_1 + 0x28) == 0) ||
          (lVar8 = *(longlong *)(*(longlong *)(param_1 + 0x28) + 0x48), lVar8 == 0)) ||
         (lVar3 = *(longlong *)(param_1 + 0x30), lVar3 == 0)) goto code_r0x000180627983;
      lVar4 = *(longlong *)(lVar3 + 0x60);
      if (*(int *)(lVar8 + 0x18) != iVar12) {
        if (lVar4 == 0) goto code_r0x000180627983;
        if (0.0 < *(float *)(lVar4 + 0x204)) {
          return;
        }
        *(undefined4 *)(*(longlong *)(lVar3 + 0x60) + 0x204) = 0x3f000000;
        goto code_r0x00018062607b;
      }
      if (lVar4 == 0) goto code_r0x000180627983;
      fVar13 = *(float *)(lVar4 + 0x204);
joined_r0x0001806264ca:
      if (0.0 < fVar13) {
        return;
      }
    }
code_r0x00018062784b:
    iVar12 = -1;
  }
code_r0x00018062607b:
  ExposureUnnoticed2_Object3D_Player_Scripts_PlayerAction__ChangeAction__06000c36(param_1,iVar12,0);
  return;
}

