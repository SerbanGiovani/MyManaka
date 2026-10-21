// Ghidra pseudocode; not original source or compilable C.
// ev_161000723ed3087be5a3afbe466bb727ff417b42483a303c53380195e2e03ddd

void ExposureUnnoticed2_Object3D_Player_Scripts_PlayerController__OnUpdate__06000d5c
               (longlong param_1)

{
  float fVar1;
  longlong lVar2;
  longlong lVar3;
  ulonglong uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  longlong lVar7;
  char cVar8;
  char cVar9;
  undefined8 uVar10;
  ulonglong *puVar11;
  longlong lVar12;
  code *pcVar13;
  undefined8 *puVar14;
  int iVar15;
  ulonglong uVar16;
  uint uVar17;
  bool bVar18;
  undefined4 uVar19;
  float fVar20;
  float fVar21;
  undefined1 auVar22 [16];
  undefined1 auVar23 [16];
  float fVar24;
  undefined8 uStack_b8;
  float fStack_b0;
  undefined8 uStack_a8;
  ulonglong uStack_a0;
  ulonglong uStack_98;
  undefined8 uStack_88;
  undefined8 uStack_80;
  ulonglong uStack_78;
  undefined1 auStack_70 [88];
  
  if (cRam0000000182eb83e1 == '\0') {
    FUN_1802f2810(&DAT_182d58288);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d53c48);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d53aa8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d58230);
    LOCK();
    UNLOCK();
    cRam0000000182eb83e1 = '\x01';
  }
  if (*(longlong *)(param_1 + 0x38) == 0) goto code_r0x000180644ead;
  uVar10 = ExposureUnnoticed2_Object3D_Player_Scripts_InputResolver__Resolve__06000c0c
                     (*(longlong *)(param_1 + 0x38),0);
  if ((*(longlong *)(param_1 + 0x40) == 0) ||
     (lVar12 = *(longlong *)(*(longlong *)(param_1 + 0x40) + 0x60), lVar12 == 0))
  goto code_r0x000180644ead;
  *(undefined1 *)(lVar12 + 0x1b9) = 0;
  if ((*(longlong *)(param_1 + 0x40) == 0) ||
     (lVar12 = *(longlong *)(*(longlong *)(param_1 + 0x40) + 0x60), lVar12 == 0))
  goto code_r0x000180644ead;
  *(undefined1 *)(lVar12 + 0x1d8) = 0;
  lVar12 = *(longlong *)(param_1 + 0x40);
  if (lVar12 == 0) goto code_r0x000180644ead;
  lVar2 = *(longlong *)(lVar12 + 0x60);
  lVar12 = *(longlong *)(lVar12 + 0x60);
  if ((**(longlong **)(DAT_182d53c48 + 0xb8) == 0) ||
     (lVar3 = *(longlong *)(**(longlong **)(DAT_182d53c48 + 0xb8) + 0x28), lVar3 == 0))
  goto code_r0x000180644ead;
  lVar3 = *(longlong *)(lVar3 + 0x50);
  if (lVar3 == 0) goto code_r0x000180644ead;
  puVar11 = (ulonglong *)
            ExposureUnnoticed2_Object3D_NPC_Script_NpcManager__GetNearNpcDistance__060010a0
                      (auStack_70,lVar3,*(undefined8 *)(*(longlong *)(param_1 + 0x40) + 0x18),0);
  iVar15 = DAT_182eb5d50;
  uStack_98 = puVar11[2];
  uStack_a8 = *puVar11;
  uStack_a0 = puVar11[1];
  uStack_78 = uStack_98;
  if (lVar2 == 0) goto code_r0x000180644ead;
  *(ulonglong *)(lVar2 + 0x20) = uStack_a0;
  if (iVar15 != 0) {
    uVar17 = (uint)(lVar2 + 0x20U >> 0xc);
    uVar16 = (ulonglong)((uVar17 & 0x1fffff) >> 6);
    do {
      uVar4 = *(ulonglong *)(&DAT_182f0c920 + uVar16 * 8);
      LOCK();
      bVar18 = uVar4 == *(ulonglong *)(&DAT_182f0c920 + uVar16 * 8);
      if (bVar18) {
        *(ulonglong *)(&DAT_182f0c920 + uVar16 * 8) = uVar4 | 1L << (uVar17 & 0x3f);
      }
      UNLOCK();
      iVar15 = DAT_182eb5d50;
    } while (!bVar18);
  }
  *(ulonglong *)(lVar12 + 0x28) = uStack_98;
  if (iVar15 != 0) {
    uVar17 = (uint)(lVar12 + 0x28U >> 0xc);
    uVar16 = (ulonglong)((uVar17 & 0x1fffff) >> 6);
    do {
      uVar4 = *(ulonglong *)(&DAT_182f0c920 + uVar16 * 8);
      LOCK();
      bVar18 = uVar4 == *(ulonglong *)(&DAT_182f0c920 + uVar16 * 8);
      if (bVar18) {
        *(ulonglong *)(&DAT_182f0c920 + uVar16 * 8) = uVar4 | 1L << (uVar17 & 0x3f);
      }
      UNLOCK();
    } while (!bVar18);
  }
  lVar12 = *(longlong *)(param_1 + 0x40);
  if (lVar12 == 0) goto code_r0x000180644ead;
  lVar2 = *(longlong *)(lVar12 + 0x60);
  if (*(longlong *)(lVar12 + 0x60) == 0) goto code_r0x000180644ead;
  if (*(longlong *)(*(longlong *)(lVar12 + 0x60) + 0x20) == 0) {
    uVar19 = 0x7f7fffff;
  }
  else {
    uVar5 = *(undefined8 *)(*(longlong *)(*(longlong *)(lVar12 + 0x60) + 0x20) + 0x18);
    uVar6 = *(undefined8 *)(*(longlong *)(param_1 + 0x40) + 0x28);
    if (*(int *)(DAT_182d58288 + 0xe0) == 0) {
      FUN_18035c820();
    }
    uVar19 = ExposureUnnoticed2_Scripts_Base_ExternalMethodManager__DistSqrt__06001726
                       (uVar5,uVar6,0);
  }
  lVar12 = *(longlong *)(param_1 + 0x40);
  *(undefined4 *)(lVar2 + 0x84) = uVar19;
  if ((lVar12 == 0) || (lVar12 = *(longlong *)(lVar12 + 0x60), lVar12 == 0))
  goto code_r0x000180644ead;
  if (*(longlong *)(lVar12 + 0x20) == 0) {
    *(undefined1 *)(*(longlong *)(*(longlong *)(param_1 + 0x40) + 0x60) + 0x88) = 0;
    if ((*(longlong *)(param_1 + 0x40) == 0) ||
       (lVar12 = *(longlong *)(*(longlong *)(param_1 + 0x40) + 0x60), lVar12 == 0))
    goto code_r0x000180644ead;
    *(undefined1 *)(lVar12 + 0x89) = 0;
  }
  else {
    if (DAT_182eb5490 == '\0') {
      FUN_1802f2810(&DAT_182d59260);
      LOCK();
      UNLOCK();
      DAT_182eb5490 = '\x01';
    }
    lVar12 = **(longlong **)(DAT_182d59260 + 0xb8);
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
    if (lVar12 != 0) {
      if (*(int *)(DAT_182d53aa8 + 0xe0) == 0) {
        FUN_18035c820();
      }
      if (*(longlong *)(lVar12 + 0x10) != 0) {
        if (DAT_182eb5490 == '\0') {
          FUN_1802f2810(&DAT_182d59260);
          LOCK();
          UNLOCK();
          DAT_182eb5490 = '\x01';
        }
        if (**(longlong **)(DAT_182d59260 + 0xb8) == 0) goto code_r0x000180644ead;
        iVar15 = *(int *)(**(longlong **)(DAT_182d59260 + 0xb8) + 0x88);
        if ((iVar15 == 4) || (iVar15 == 0)) {
          if (DAT_182eb5490 == '\0') {
            FUN_1802f2810(&DAT_182d59260);
            LOCK();
            UNLOCK();
            DAT_182eb5490 = '\x01';
          }
          lVar12 = **(longlong **)(DAT_182d59260 + 0xb8);
          if ((*(longlong *)(param_1 + 0x40) == 0) ||
             (lVar2 = *(longlong *)(*(longlong *)(param_1 + 0x40) + 0x18), lVar2 == 0))
          goto code_r0x000180644ead;
          uStack_b8 = 0;
          fStack_b0 = 0.0;
          pcVar13 = DAT_182ec1698;
          if ((DAT_182ec1698 == (code *)0x0) &&
             (pcVar13 = (code *)FUN_1802cf0c0(
                                             "UnityEngine.Transform::get_position_Injected(UnityEngine.Vector3&)"
                                             ), pcVar13 == (code *)0x0)) {
            uVar10 = FUN_1802ced60(
                                  "UnityEngine.Transform::get_position_Injected(UnityEngine.Vector3&)"
                                  );
                    /* WARNING: Subroutine does not return */
            FUN_1802cca90(uVar10,0);
          }
          DAT_182ec1698 = pcVar13;
          (*DAT_182ec1698)(lVar2,&uStack_b8);
          if (lVar12 == 0) goto code_r0x000180644ead;
          uStack_88 = *(undefined8 *)(lVar12 + 0x5c);
          uStack_80 = *(undefined8 *)(lVar12 + 100);
          uStack_78 = *(ulonglong *)(lVar12 + 0x6c);
          uStack_a0 = CONCAT44(uStack_a0._4_4_,fStack_b0);
          uStack_a8 = uStack_b8;
          pcVar13 = pcRam0000000182ebfdb8;
          if ((pcRam0000000182ebfdb8 == (code *)0x0) &&
             (pcVar13 = (code *)FUN_1802cf0c0(
                                             "UnityEngine.Bounds::Contains_Injected(UnityEngine.Bounds&,UnityEngine.Vector3&)"
                                             ), pcVar13 == (code *)0x0)) {
            uVar10 = FUN_1802ced60(
                                  "UnityEngine.Bounds::Contains_Injected(UnityEngine.Bounds&,UnityEngine.Vector3&)"
                                  );
                    /* WARNING: Subroutine does not return */
            FUN_1802cca90(uVar10,0);
          }
          pcRam0000000182ebfdb8 = pcVar13;
          cVar8 = (*pcRam0000000182ebfdb8)(&uStack_88,&uStack_a8);
          if (DAT_182eb5490 == '\0') {
            FUN_1802f2810(&DAT_182d59260);
            LOCK();
            UNLOCK();
            DAT_182eb5490 = '\x01';
          }
          lVar12 = **(longlong **)(DAT_182d59260 + 0xb8);
          if ((((*(longlong *)(param_1 + 0x40) == 0) ||
               (lVar2 = *(longlong *)(*(longlong *)(param_1 + 0x40) + 0x60), lVar2 == 0)) ||
              (lVar2 = *(longlong *)(lVar2 + 0x20), lVar2 == 0)) ||
             (lVar2 = *(longlong *)(lVar2 + 0x10), lVar2 == 0)) goto code_r0x000180644ead;
          uStack_b8 = 0;
          fStack_b0 = 0.0;
          pcVar13 = DAT_182ec1698;
          if ((DAT_182ec1698 == (code *)0x0) &&
             (pcVar13 = (code *)FUN_1802cf0c0(
                                             "UnityEngine.Transform::get_position_Injected(UnityEngine.Vector3&)"
                                             ), pcVar13 == (code *)0x0)) {
            uVar10 = FUN_1802ced60(
                                  "UnityEngine.Transform::get_position_Injected(UnityEngine.Vector3&)"
                                  );
                    /* WARNING: Subroutine does not return */
            FUN_1802cca90(uVar10,0);
          }
          DAT_182ec1698 = pcVar13;
          (*DAT_182ec1698)(lVar2,&uStack_b8);
          if (lVar12 == 0) goto code_r0x000180644ead;
          uStack_88 = *(undefined8 *)(lVar12 + 0x5c);
          uStack_80 = *(undefined8 *)(lVar12 + 100);
          uStack_78 = *(ulonglong *)(lVar12 + 0x6c);
          uStack_a0 = CONCAT44(uStack_a0._4_4_,fStack_b0);
          uStack_a8 = uStack_b8;
          pcVar13 = pcRam0000000182ebfdb8;
          if ((pcRam0000000182ebfdb8 == (code *)0x0) &&
             (pcVar13 = (code *)FUN_1802cf0c0(
                                             "UnityEngine.Bounds::Contains_Injected(UnityEngine.Bounds&,UnityEngine.Vector3&)"
                                             ), pcVar13 == (code *)0x0)) {
            uVar10 = FUN_1802ced60(
                                  "UnityEngine.Bounds::Contains_Injected(UnityEngine.Bounds&,UnityEngine.Vector3&)"
                                  );
                    /* WARNING: Subroutine does not return */
            FUN_1802cca90(uVar10,0);
          }
          pcRam0000000182ebfdb8 = pcVar13;
          cVar9 = (*pcRam0000000182ebfdb8)(&uStack_88,&uStack_a8);
          if (cVar8 != cVar9) {
            if ((*(longlong *)(param_1 + 0x40) == 0) ||
               (lVar12 = *(longlong *)(*(longlong *)(param_1 + 0x40) + 0x60), lVar12 == 0))
            goto code_r0x000180644ead;
            *(undefined1 *)(lVar12 + 0x88) = 0;
            if ((*(longlong *)(param_1 + 0x40) == 0) ||
               (lVar12 = *(longlong *)(*(longlong *)(param_1 + 0x40) + 0x60), lVar12 == 0))
            goto code_r0x000180644ead;
            *(undefined1 *)(lVar12 + 0x89) = 0;
            goto code_r0x0001806442ed;
          }
        }
      }
    }
    lVar12 = *(longlong *)(param_1 + 0x40);
    if ((lVar12 == 0) || (*(longlong *)(lVar12 + 0x60) == 0)) goto code_r0x000180644ead;
    if (*(longlong *)(*(longlong *)(lVar12 + 0x60) + 0x28) == 0) {
      *(undefined1 *)(*(longlong *)(lVar12 + 0x60) + 0x88) = 0;
      if ((*(longlong *)(param_1 + 0x40) == 0) ||
         (lVar12 = *(longlong *)(*(longlong *)(param_1 + 0x40) + 0x60), lVar12 == 0))
      goto code_r0x000180644ead;
      *(undefined1 *)(lVar12 + 0x89) = 0;
    }
    else {
      lVar12 = *(longlong *)(lVar12 + 0x18);
      if (lVar12 == 0) goto code_r0x000180644ead;
      uStack_b8 = 0;
      fStack_b0 = 0.0;
      pcVar13 = DAT_182ec1698;
      if ((DAT_182ec1698 == (code *)0x0) &&
         (pcVar13 = (code *)FUN_1802cf0c0(
                                         "UnityEngine.Transform::get_position_Injected(UnityEngine.Vector3&)"
                                         ), pcVar13 == (code *)0x0)) {
        uVar10 = FUN_1802ced60("UnityEngine.Transform::get_position_Injected(UnityEngine.Vector3&)")
        ;
                    /* WARNING: Subroutine does not return */
        FUN_1802cca90(uVar10,0);
      }
      DAT_182ec1698 = pcVar13;
      (*DAT_182ec1698)(lVar12,&uStack_b8);
      if ((((*(longlong *)(param_1 + 0x40) == 0) ||
           (lVar12 = *(longlong *)(*(longlong *)(param_1 + 0x40) + 0x60), lVar12 == 0)) ||
          (lVar12 = *(longlong *)(lVar12 + 0x28), lVar12 == 0)) ||
         (lVar12 = *(longlong *)(lVar12 + 0x10), lVar12 == 0)) goto code_r0x000180644ead;
      uStack_a8 = 0;
      uStack_a0 = uStack_a0 & 0xffffffff00000000;
      pcVar13 = DAT_182ec1698;
      if ((DAT_182ec1698 == (code *)0x0) &&
         (pcVar13 = (code *)FUN_1802cf0c0(
                                         "UnityEngine.Transform::get_position_Injected(UnityEngine.Vector3&)"
                                         ), pcVar13 == (code *)0x0)) {
        uVar10 = FUN_1802ced60("UnityEngine.Transform::get_position_Injected(UnityEngine.Vector3&)")
        ;
                    /* WARNING: Subroutine does not return */
        FUN_1802cca90(uVar10,0);
      }
      DAT_182ec1698 = pcVar13;
      (*DAT_182ec1698)(lVar12,&uStack_a8);
      fVar24 = (float)uStack_b8 - (float)uStack_a8;
      fVar20 = fStack_b0 - (float)uStack_a0;
      if (*(int *)(DAT_182d58288 + 0xe0) == 0) {
        FUN_18035c820();
      }
      uStack_a8 = (ulonglong)(uint)fVar24;
      uStack_a0 = CONCAT44(uStack_a0._4_4_,fVar20);
      fVar24 = (float)FUN_1803d4630(&uStack_a8);
      if ((*(longlong *)(param_1 + 0x40) == 0) ||
         (lVar12 = *(longlong *)(*(longlong *)(param_1 + 0x40) + 0x18), lVar12 == 0))
      goto code_r0x000180644ead;
      uStack_a8 = 0;
      uStack_a0 = uStack_a0 & 0xffffffff00000000;
      pcVar13 = DAT_182ec1698;
      if ((DAT_182ec1698 == (code *)0x0) &&
         (pcVar13 = (code *)FUN_1802cf0c0(
                                         "UnityEngine.Transform::get_position_Injected(UnityEngine.Vector3&)"
                                         ), pcVar13 == (code *)0x0)) {
        uVar10 = FUN_1802ced60("UnityEngine.Transform::get_position_Injected(UnityEngine.Vector3&)")
        ;
                    /* WARNING: Subroutine does not return */
        FUN_1802cca90(uVar10,0);
      }
      DAT_182ec1698 = pcVar13;
      (*DAT_182ec1698)(lVar12,&uStack_a8);
      if ((((*(longlong *)(param_1 + 0x40) == 0) ||
           (lVar12 = *(longlong *)(*(longlong *)(param_1 + 0x40) + 0x60), lVar12 == 0)) ||
          (lVar12 = *(longlong *)(lVar12 + 0x28), lVar12 == 0)) ||
         (lVar12 = *(longlong *)(lVar12 + 0x10), lVar12 == 0)) goto code_r0x000180644ead;
      uStack_b8 = 0;
      fStack_b0 = 0.0;
      pcVar13 = DAT_182ec1698;
      if ((DAT_182ec1698 == (code *)0x0) &&
         (pcVar13 = (code *)FUN_1802cf0c0(
                                         "UnityEngine.Transform::get_position_Injected(UnityEngine.Vector3&)"
                                         ), pcVar13 == (code *)0x0)) {
        uVar10 = FUN_1802ced60("UnityEngine.Transform::get_position_Injected(UnityEngine.Vector3&)")
        ;
                    /* WARNING: Subroutine does not return */
        FUN_1802cca90(uVar10,0);
      }
      DAT_182ec1698 = pcVar13;
      (*DAT_182ec1698)(lVar12,&uStack_b8);
      if (*(longlong *)(param_1 + 0x40) == 0) goto code_r0x000180644ead;
      lVar12 = *(longlong *)(*(longlong *)(param_1 + 0x40) + 0x60);
      if (lVar12 == 0) goto code_r0x000180644ead;
      *(bool *)(lVar12 + 0x88) = fVar24 < 1.5 && ABS(uStack_a8._4_4_ - uStack_b8._4_4_) < 2.0;
      if (*(longlong *)(param_1 + 0x40) == 0) goto code_r0x000180644ead;
      lVar12 = *(longlong *)(*(longlong *)(param_1 + 0x40) + 0x60);
      if (lVar12 == 0) goto code_r0x000180644ead;
      *(bool *)(lVar12 + 0x89) = fVar24 < 3.0 && ABS(uStack_a8._4_4_ - uStack_b8._4_4_) < 2.0;
    }
  }
code_r0x0001806442ed:
  if ((*(longlong *)(param_1 + 0x40) == 0) ||
     (lVar12 = *(longlong *)(*(longlong *)(param_1 + 0x40) + 0xd0), lVar12 == 0))
  goto code_r0x000180644ead;
  ExposureUnnoticed2_Object3D_Player_Scripts_StaminaManager__OnUpdate__06000e50(lVar12,0);
  if ((*(longlong *)(param_1 + 0x40) == 0) ||
     (lVar12 = *(longlong *)(*(longlong *)(param_1 + 0x40) + 0xa8), lVar12 == 0))
  goto code_r0x000180644ead;
  ExposureUnnoticed2_Object3D_Player_Scripts_PlayerMoistureManager__OnUpdate__06000df9(lVar12,0);
  if ((*(longlong *)(param_1 + 0x40) == 0) ||
     (lVar12 = *(longlong *)(*(longlong *)(param_1 + 0x40) + 0x130), lVar12 == 0))
  goto code_r0x000180644ead;
  ExposureUnnoticed2_Object3D_Player_Scripts_PlayerEcstasyController__OnUpdate__06000d88(lVar12,0);
  if ((*(longlong *)(param_1 + 0x40) == 0) ||
     (lVar12 = *(longlong *)(*(longlong *)(param_1 + 0x40) + 0x148), lVar12 == 0))
  goto code_r0x000180644ead;
  ExposureUnnoticed2_Object3D_Player_Scripts_PlayerStrangenessController__OnUpdate__06000e31
            (lVar12,0);
  if ((*(longlong *)(param_1 + 0x40) == 0) ||
     (lVar12 = *(longlong *)(*(longlong *)(param_1 + 0x40) + 0x160), lVar12 == 0))
  goto code_r0x000180644ead;
  ExposureUnnoticed2_Object3D_Player_Scripts_PlayerMiscProcess__OnUpdate__06000df3(lVar12,uVar10,0);
  if ((*(longlong *)(param_1 + 0x40) == 0) ||
     (lVar12 = *(longlong *)(*(longlong *)(param_1 + 0x40) + 0x60), lVar12 == 0))
  goto code_r0x000180644ead;
  iVar15 = *(int *)(lVar12 + 0x5c);
  if (iVar15 == 0) {
    if ((**(longlong **)(DAT_182d53c48 + 0xb8) == 0) ||
       (lVar12 = *(longlong *)(**(longlong **)(DAT_182d53c48 + 0xb8) + 0x30), lVar12 == 0))
    goto code_r0x000180644ead;
    if (*(char *)(lVar12 + 0x11) == '\0') {
      if ((*(longlong *)(param_1 + 0x40) == 0) ||
         (lVar12 = *(longlong *)(*(longlong *)(param_1 + 0x40) + 0x58), lVar12 == 0))
      goto code_r0x000180644ead;
      ExposureUnnoticed2_Object3D_Player_Scripts_PlayerLocomotion__OnUpdate__06000dea
                (lVar12,uVar10,0);
      if ((*(longlong *)(param_1 + 0x40) == 0) ||
         (lVar12 = *(longlong *)(*(longlong *)(param_1 + 0x40) + 0xb8), lVar12 == 0))
      goto code_r0x000180644ead;
      ExposureUnnoticed2_Object3D_Player_Scripts_PlayerPeeController__OnUpdate__06000e02
                (lVar12,uVar10,0);
      if ((*(longlong *)(param_1 + 0x40) == 0) ||
         (lVar12 = *(longlong *)(*(longlong *)(param_1 + 0x40) + 0xc0), lVar12 == 0))
      goto code_r0x000180644ead;
      ExposureUnnoticed2_Object3D_Player_Scripts_PlayerClothesAction__OnUpdate__06000d48
                (lVar12,uVar10,0);
      if ((*(longlong *)(param_1 + 0x40) == 0) ||
         (lVar12 = *(longlong *)(*(longlong *)(param_1 + 0x40) + 0xf0), lVar12 == 0))
      goto code_r0x000180644ead;
      if (cRam0000000182eb8411 == '\0') {
        FUN_1802f2810(&DAT_182d58398);
        LOCK();
        UNLOCK();
        FUN_1802f2810(&DAT_182d53c48);
        LOCK();
        UNLOCK();
        cRam0000000182eb8411 = '\x01';
      }
      if ((**(longlong **)(DAT_182d53c48 + 0xb8) == 0) ||
         (lVar2 = *(longlong *)(**(longlong **)(DAT_182d53c48 + 0xb8) + 0x30), lVar2 == 0))
      goto code_r0x000180644ead;
      if (*(char *)(lVar2 + 0x11) == '\0') {
        if ((*(char *)(lVar12 + 0x2c) == '\0') && (*(char *)(lVar12 + 0x2d) == '\0')) {
          lVar2 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
          if (lVar2 == 0) goto code_r0x000180644ead;
          if ((*(char *)(lVar2 + 0x1a8) != '\0') || (*(char *)(lVar2 + 0x1a9) != '\0')) {
            ExposureUnnoticed2_Object3D_Player_Scripts_PlayerHandcuffsController__OnAttachProcess__06000dcc
                      (lVar12,uVar10,0);
            goto code_r0x0001806445bb;
          }
        }
        ExposureUnnoticed2_Object3D_Player_Scripts_PlayerHandcuffsController__OnNoAttachProcess__06000dcf
                  (lVar12,0);
      }
      else {
        if ((*(longlong *)(lVar12 + 0x10) == 0) ||
           (lVar12 = *(longlong *)(*(longlong *)(lVar12 + 0x10) + 0xb0), lVar12 == 0))
        goto code_r0x000180644ead;
        ExposureUnnoticed2_Object3D_Player_Scripts_PlayerSoundManager__SetPickingSeSoundIfNeed__06000e24
                  (lVar12,0,0);
      }
code_r0x0001806445bb:
      if ((*(longlong *)(param_1 + 0x40) == 0) ||
         (lVar12 = *(longlong *)(*(longlong *)(param_1 + 0x40) + 0x100), lVar12 == 0))
      goto code_r0x000180644ead;
      ExposureUnnoticed2_Object3D_Player_Scripts_PlayerAdultGoodsController__OnUpdate__06000c3f
                (lVar12,0);
    }
    if ((*(longlong *)(param_1 + 0x40) == 0) ||
       (lVar12 = *(longlong *)(*(longlong *)(param_1 + 0x40) + 0x68), lVar12 == 0))
    goto code_r0x000180644ead;
    ExposureUnnoticed2_Object3D_Player_Scripts_PlayerAction__OnUpdate__06000c35(lVar12,uVar10,0);
  }
  else if (iVar15 == 1) {
    if ((*(longlong *)(param_1 + 0x40) == 0) ||
       (lVar12 = *(longlong *)(*(longlong *)(param_1 + 0x40) + 0xe0), lVar12 == 0))
    goto code_r0x000180644ead;
    ExposureUnnoticed2_Object3D_Player_Scripts_PlayerBaretaState__OnUpdate__06000ca1(lVar12,0);
  }
  else if (iVar15 == 2) {
    lVar12 = *(longlong *)(*(longlong *)(param_1 + 0x40) + 0xe8);
    if (lVar12 == 0) goto code_r0x000180644ead;
    ExposureUnnoticed2_Object3D_Player_Scripts_PlayerBaretaEscapeState__OnUpdate__06000c9a(lVar12,0)
    ;
  }
  lVar12 = *(longlong *)(param_1 + 0x40);
  if (((lVar12 != 0) && (*(longlong *)(lVar12 + 0x1c8) != 0)) &&
     (lVar12 = *(longlong *)(lVar12 + 0x80), lVar12 != 0)) {
    if (cRam0000000182eb83cc == '\0') {
      FUN_1802f2810(0x182d3e758);
      LOCK();
      UNLOCK();
      cRam0000000182eb83cc = '\x01';
    }
    if (((*(longlong *)(lVar12 + 0x18) != 0) &&
        (lVar2 = *(longlong *)(*(longlong *)(lVar12 + 0x18) + 0x60), lVar2 != 0)) &&
       (lVar2 = *(longlong *)(lVar2 + 0x10), lVar2 != 0)) {
      lVar12 = ExposureUnnoticed2_Object3D_Player_Scripts_PlayerClothes__TransController__06000d3f
                         (lVar12,*(undefined4 *)(lVar2 + 0x30),0);
      if (lVar12 != 0) {
        FUN_180002c20(1,uRam0000000182d3e758,lVar12);
      }
      if ((*(longlong *)(param_1 + 0x40) != 0) &&
         (lVar12 = *(longlong *)(*(longlong *)(param_1 + 0x40) + 0x188), lVar12 != 0)) {
        if (cRam0000000182eb8416 == '\0') {
          FUN_1802f2810(&DAT_182d58398);
          LOCK();
          UNLOCK();
          cRam0000000182eb8416 = '\x01';
        }
        lVar2 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
        if (lVar2 != 0) {
          if (*(int *)(lVar2 + 0x10) == 0) {
            fVar24 = 0.0;
          }
          else {
            if (*(longlong *)(lVar12 + 0x18) == 0) goto code_r0x000180644ead;
            fVar24 = *(float *)(*(longlong *)(lVar12 + 0x18) + 0x58);
          }
          fVar24 = fVar24 * 57.0 + 95.0;
          if (fVar24 < *(float *)(lVar12 + 0x10) || fVar24 == *(float *)(lVar12 + 0x10)) {
            fVar20 = 0.1;
          }
          else {
            fVar20 = 0.2;
          }
          fVar20 = ABS(fVar24 - *(float *)(lVar12 + 0x10)) * fVar20;
          if (10000.0 <= fVar20) {
            fVar20 = 10000.0;
          }
          fVar1 = *(float *)(lVar12 + 0x10);
          pcVar13 = DAT_182ec14d0;
          if ((DAT_182ec14d0 == (code *)0x0) &&
             (pcVar13 = (code *)FUN_1802cf0c0("UnityEngine.Time::get_deltaTime()"),
             pcVar13 == (code *)0x0)) {
            uVar10 = FUN_1802ced60("UnityEngine.Time::get_deltaTime()");
                    /* WARNING: Subroutine does not return */
            FUN_1802cca90(uVar10,0);
          }
          DAT_182ec14d0 = pcVar13;
          fVar21 = (float)(*DAT_182ec14d0)();
          if (fVar21 * fVar20 < ABS(fVar24 - fVar1)) {
            if (fVar24 - fVar1 < 0.0) {
              fVar24 = -1.0;
            }
            else {
              fVar24 = 1.0;
            }
            fVar24 = fVar24 * fVar21 * fVar20 + fVar1;
          }
          *(float *)(lVar12 + 0x10) = fVar24;
          if ((*(longlong *)(param_1 + 0x40) != 0) &&
             (lVar12 = *(longlong *)(*(longlong *)(param_1 + 0x40) + 0x128), lVar12 != 0)) {
            ExposureUnnoticed2_Object3D_Player_Scripts_PlayerFaceController__OnUpdate__06000db1
                      (lVar12,0);
            if ((*(longlong *)(param_1 + 0x40) != 0) &&
               (lVar12 = *(longlong *)(*(longlong *)(param_1 + 0x40) + 0x138), lVar12 != 0)) {
              ExposureUnnoticed2_Object3D_Player_Scripts_PlayerTitController__OnUpdate__06000e3e
                        (lVar12,0);
              if ((*(longlong *)(param_1 + 0x40) != 0) &&
                 (lVar12 = *(longlong *)(*(longlong *)(param_1 + 0x40) + 0x140), lVar12 != 0)) {
                ExposureUnnoticed2_Object3D_Player_Scripts_PlayerFaceShadowOnlyController__OnUpdate__06000dba
                          (lVar12,0);
                if ((*(longlong *)(param_1 + 0x40) != 0) &&
                   ((((((lVar12 = *(longlong *)(*(longlong *)(param_1 + 0x40) + 0x150), lVar12 != 0
                        && (lVar2 = *(longlong *)(lVar12 + 0x10), lVar2 != 0)) &&
                       (*(longlong *)(lVar2 + 0x60) != 0)) &&
                      ((lVar3 = *(longlong *)(*(longlong *)(lVar2 + 0x60) + 0x48), lVar3 != 0 &&
                       (*(longlong *)(lVar2 + 0x100) != 0)))) && (*(longlong *)(lVar2 + 0x118) != 0)
                     ) && ((*(longlong *)(lVar2 + 0x1b8) != 0 && (*(longlong *)(lVar12 + 0x20) != 0)
                           ))))) {
                  ExposureUnnoticed2_Scripts_Base_SmoothFloat__UpdateTo__0600175c
                            (*(longlong *)(lVar12 + 0x20),lVar3,0);
                  if ((*(longlong *)(lVar12 + 0x10) != 0) &&
                     (lVar2 = *(longlong *)(*(longlong *)(lVar12 + 0x10) + 0x100), lVar2 != 0)) {
                    lVar3 = *(longlong *)(*(longlong *)(lVar12 + 0x10) + 0x118);
                    if ((lVar3 != 0) &&
                       (lVar7 = *(longlong *)(*(longlong *)(lVar12 + 0x10) + 0x1b8), lVar7 != 0)) {
                      if (*(longlong *)(lVar12 + 0x28) != 0) {
                        ExposureUnnoticed2_Scripts_Base_SmoothFloat__UpdateTo__0600175c
                                  (*(longlong *)(lVar12 + 0x28),
                                   CONCAT71((int7)((ulonglong)lVar3 >> 8),
                                            -((*(char *)(lVar2 + 0x11) != '\0' ||
                                              *(char *)(lVar3 + 0x19) != '\0') |
                                             *(byte *)(lVar7 + 0x19))),0);
                        if ((*(longlong *)(param_1 + 0x40) != 0) &&
                           (lVar12 = *(longlong *)(*(longlong *)(param_1 + 0x40) + 0x180),
                           lVar12 != 0)) {
                          fVar24 = *(float *)(lVar12 + 0x18);
                          pcVar13 = DAT_182ec14d0;
                          if ((DAT_182ec14d0 == (code *)0x0) &&
                             (pcVar13 = (code *)FUN_1802cf0c0("UnityEngine.Time::get_deltaTime()"),
                             pcVar13 == (code *)0x0)) {
                            uVar10 = FUN_1802ced60("UnityEngine.Time::get_deltaTime()");
                    /* WARNING: Subroutine does not return */
                            FUN_1802cca90(uVar10,0);
                          }
                          DAT_182ec14d0 = pcVar13;
                          fVar20 = (float)(*DAT_182ec14d0)();
                          fVar24 = fVar24 - fVar20 * 0.35;
                          *(float *)(lVar12 + 0x18) = fVar24;
                          if (*(longlong *)(lVar12 + 0x10) != 0) {
                            lVar2 = *(longlong *)(*(longlong *)(lVar12 + 0x10) + 0x60);
                            if (fVar24 < 0.0) {
                              fVar24 = 0.0;
                            }
                            else if (*(float *)(lVar12 + 0x1c) < fVar24) {
                              fVar24 = *(float *)(lVar12 + 0x1c);
                            }
                            if (lVar2 != 0) {
                              *(float *)(lVar2 + 0x140) = fVar24;
                              if ((*(longlong *)(param_1 + 0x40) != 0) &&
                                 (lVar12 = *(longlong *)(*(longlong *)(param_1 + 0x40) + 0x1a0),
                                 lVar12 != 0)) {
                                ExposureUnnoticed2_Object3D_Player_Scripts_PlayerShrinkWakiController__OnUpdate__06000e1a
                                          (lVar12,0);
                                if ((*(longlong *)(param_1 + 0x40) != 0) &&
                                   (lVar12 = *(longlong *)(*(longlong *)(param_1 + 0x40) + 0x1a8),
                                   lVar12 != 0)) {
                                  ExposureUnnoticed2_Object3D_Player_Scripts_PlayerBreathController__OnUpdate__06000ced
                                            (lVar12,0);
                                  if ((*(longlong *)(param_1 + 0x40) != 0) &&
                                     (lVar12 = *(longlong *)(*(longlong *)(param_1 + 0x40) + 0x1b0),
                                     lVar12 != 0)) {
                                    if (cRam0000000182eb83b3 == '\0') {
                                      FUN_1802f2810(&DAT_182d3e9d0);
                                      LOCK();
                                      UNLOCK();
                                      cRam0000000182eb83b3 = '\x01';
                                    }
                                    if ((*(longlong *)(lVar12 + 0x10) != 0) &&
                                       (lVar2 = *(longlong *)(*(longlong *)(lVar12 + 0x10) + 0x60),
                                       lVar2 != 0)) {
                                      fVar24 = *(float *)(lVar2 + 0x58);
                                      auVar22 = ZEXT416((uint)fVar24);
                                      if (fVar24 < 0.0) {
                                        auVar22 = ZEXT816(0);
                                      }
                                      else if (0.5 < fVar24) {
                                        auVar22._0_12_ = ZEXT812(0x3f000000);
                                        auVar22._12_4_ = 0;
                                      }
                                      if (*(longlong *)(lVar12 + 0x18) != 0) {
                                        auVar23._4_12_ = auVar22._4_12_;
                                        auVar23._0_4_ = (auVar22._0_4_ + auVar22._0_4_) - 1.0;
                                        ExposureUnnoticed2_Scripts_Base_SmoothFloat__UpdateTo__0600175c
                                                  (*(longlong *)(lVar12 + 0x18),auVar23._0_8_,0);
                                        lVar2 = *(longlong *)(lVar12 + 0x20);
                                        if (*(int *)(DAT_182d3e9d0 + 0xe0) == 0) {
                                          FUN_18035c820(DAT_182d3e9d0);
                                        }
                                        if ((*(longlong *)(lVar12 + 0x18) != 0) && (lVar2 != 0)) {
                                          uVar19 = *(undefined4 *)
                                                    (*(longlong *)(DAT_182d3e9d0 + 0xb8) + 4);
                                          pcVar13 = DAT_182ec04d8;
                                          if ((DAT_182ec04d8 == (code *)0x0) &&
                                             (pcVar13 = (code *)FUN_1802cf0c0(
                                                  "UnityEngine.Material::SetFloatImpl(System.Int32,System.Single)"
                                                  ), pcVar13 == (code *)0x0)) {
                                            uVar10 = FUN_1802ced60(
                                                  "UnityEngine.Material::SetFloatImpl(System.Int32,System.Single)"
                                                  );
                    /* WARNING: Subroutine does not return */
                                            FUN_1802cca90(uVar10,0);
                                          }
                                          DAT_182ec04d8 = pcVar13;
                                          (*DAT_182ec04d8)(lVar2,uVar19);
                                          if ((*(longlong *)(param_1 + 0x40) != 0) &&
                                             (lVar12 = *(longlong *)
                                                        (*(longlong *)(param_1 + 0x40) + 0x1d8),
                                             lVar12 != 0)) {
                                            ExposureUnnoticed2_Object3D_Player_Scripts_Other_FutanariController__OnUpdate__06000e8b
                                                      (lVar12,0);
                                            if ((*(longlong *)(param_1 + 0x40) != 0) &&
                                               (lVar12 = *(longlong *)
                                                          (*(longlong *)(param_1 + 0x40) + 0x1e0),
                                               lVar12 != 0)) {
                                              fVar24 = *(float *)(lVar12 + 0x20);
                                              pcVar13 = DAT_182ec14d0;
                                              if ((DAT_182ec14d0 == (code *)0x0) &&
                                                 (pcVar13 = (code *)FUN_1802cf0c0(
                                                  "UnityEngine.Time::get_deltaTime()"),
                                                 pcVar13 == (code *)0x0)) {
                                                uVar10 = FUN_1802ced60(
                                                  "UnityEngine.Time::get_deltaTime()");
                    /* WARNING: Subroutine does not return */
                                                FUN_1802cca90(uVar10,0);
                                              }
                                              DAT_182ec14d0 = pcVar13;
                                              fVar20 = (float)(*DAT_182ec14d0)();
                                              lVar2 = *(longlong *)(param_1 + 0x40);
                                              *(float *)(lVar12 + 0x20) = fVar24 - fVar20;
                                              if ((lVar2 != 0) &&
                                                 (lVar12 = *(longlong *)(lVar2 + 0x1e8), lVar12 != 0
                                                 )) {
                                                ExposureUnnoticed2_Object3D_Player_Scripts_Other_BodyPaintController__OnUpdate__06000e5b
                                                          (lVar12,0);
                                                if ((*(longlong *)(param_1 + 0x40) != 0) &&
                                                   (lVar12 = *(longlong *)
                                                              (*(longlong *)(param_1 + 0x40) + 0x1f0
                                                              ), lVar12 != 0)) {
                                                  ExposureUnnoticed2_Object3D_Player_Scripts_Costume_PistonMachineController__OnUpdate__06000ef6
                                                            (lVar12,0);
                                                  if ((*(longlong *)(param_1 + 0x40) != 0) &&
                                                     (lVar12 = *(longlong *)
                                                                (*(longlong *)(param_1 + 0x40) +
                                                                0x1f8), lVar12 != 0)) {
                                                                                                        
                                                  ExposureUnnoticed2_Object3D_Player_Scripts_Other_PlayerMoveCalculator__OnUpdate__06000ec5
                                                            (lVar12,0);
                                                  if ((*(longlong *)(param_1 + 0x40) != 0) &&
                                                     (lVar12 = *(longlong *)
                                                                (*(longlong *)(param_1 + 0x40) + 400
                                                                ), lVar12 != 0)) {
                                                                                                        
                                                  ExposureUnnoticed2_Object3D_Player_Scripts_PlayerRpBonusCalculator__OnUpdate__06000e0f
                                                            (lVar12,0);
                                                  lVar12 = *(longlong *)(param_1 + 0x40);
                                                  if (((lVar12 != 0) &&
                                                      (*(longlong *)(lVar12 + 0x178) != 0)) &&
                                                     (lVar12 = *(longlong *)(lVar12 + 0x60),
                                                     lVar12 != 0)) {
                                                    *(undefined2 *)(lVar12 + 0x230) = 0;
                                                    *(undefined4 *)(lVar12 + 0x234) = 0xffffffff;
                                                    if ((*(longlong *)(param_1 + 0x40) != 0) &&
                                                       (lVar12 = *(longlong *)
                                                                  (*(longlong *)(param_1 + 0x40) +
                                                                  0x48), lVar12 != 0)) {
                                                                                                            
                                                  ExposureUnnoticed2_Object3D_Player_Scripts_PlayerAnimationManager__OnUpdate__06000c75
                                                            (lVar12,uVar10,0);
                                                  if ((*(longlong *)(param_1 + 0x40) != 0) &&
                                                     (lVar12 = *(longlong *)
                                                                (*(longlong *)(param_1 + 0x40) +
                                                                0x68), lVar12 != 0)) {
                                                    *(undefined1 *)(lVar12 + 0x38) = 0;
                                                    if ((*(longlong *)(lVar12 + 0x30) != 0) &&
                                                       (lVar12 = *(longlong *)
                                                                  (*(longlong *)(lVar12 + 0x30) +
                                                                  0x60), lVar12 != 0)) {
                                                      fVar24 = *(float *)(lVar12 + 0x204);
                                                      pcVar13 = DAT_182ec14d0;
                                                      if ((DAT_182ec14d0 == (code *)0x0) &&
                                                         (pcVar13 = (code *)FUN_1802cf0c0(
                                                  "UnityEngine.Time::get_deltaTime()"),
                                                  pcVar13 == (code *)0x0)) {
                                                    uVar10 = FUN_1802ced60(
                                                  "UnityEngine.Time::get_deltaTime()");
                    /* WARNING: Subroutine does not return */
                                                  FUN_1802cca90(uVar10,0);
                                                  }
                                                  DAT_182ec14d0 = pcVar13;
                                                  fVar20 = (float)(*DAT_182ec14d0)();
                                                  *(float *)(lVar12 + 0x204) = fVar24 - fVar20;
                                                  if (*(longlong *)(param_1 + 0x40) != 0) {
                                                    lVar12 = *(longlong *)
                                                              (*(longlong *)(param_1 + 0x40) + 0x60)
                                                    ;
                                                    lVar2 = *(longlong *)
                                                             (*(longlong *)(param_1 + 0x40) + 0x18);
                                                    if (lVar2 != 0) {
                                                      uStack_a8 = 0;
                                                      uStack_a0 = uStack_a0 & 0xffffffff00000000;
                                                      pcVar13 = DAT_182ec1698;
                                                      if ((DAT_182ec1698 == (code *)0x0) &&
                                                         (pcVar13 = (code *)FUN_1802cf0c0(
                                                  "UnityEngine.Transform::get_position_Injected(UnityEngine.Vector3&)"
                                                  ), pcVar13 == (code *)0x0)) {
                                                    uVar10 = FUN_1802ced60(
                                                  "UnityEngine.Transform::get_position_Injected(UnityEngine.Vector3&)"
                                                  );
                    /* WARNING: Subroutine does not return */
                                                  FUN_1802cca90(uVar10,0);
                                                  }
                                                  DAT_182ec1698 = pcVar13;
                                                  (*DAT_182ec1698)(lVar2,&uStack_a8);
                                                  if (lVar12 != 0) {
                                                    *(ulonglong *)(lVar12 + 0x264) = uStack_a8;
                                                    *(float *)(lVar12 + 0x26c) = (float)uStack_a0;
                                                    if (*(longlong *)(param_1 + 0x40) != 0) {
                                                      lVar12 = *(longlong *)
                                                                (*(longlong *)(param_1 + 0x40) +
                                                                0x60);
                                                      lVar2 = *(longlong *)
                                                               (*(longlong *)(param_1 + 0x40) + 0x18
                                                               );
                                                      if (lVar2 != 0) {
                                                        puVar14 = (undefined8 *)
                                                                  FUN_181f4c360(&uStack_a8,lVar2,0);
                                                        uVar19 = *(undefined4 *)(puVar14 + 1);
                                                        if (lVar12 != 0) {
                                                          *(undefined8 *)(lVar12 + 0x270) = *puVar14
                                                          ;
                                                          *(undefined4 *)(lVar12 + 0x278) = uVar19;
                                                          if (*(longlong *)(param_1 + 0x40) != 0) {
                                                            lVar12 = *(longlong *)
                                                                      (*(longlong *)(param_1 + 0x40)
                                                                      + 0x60);
                                                            if ((**(longlong **)
                                                                   (DAT_182d58230 + 0xb8) != 0) &&
                                                               (uVar19 = 
                                                  ExposureUnnoticed2_Object3D_Player_Scripts_PlayerFacade__GetExposedBodyPartsByClothesAndCostume__06000d9f
                                                            (**(longlong **)(DAT_182d58230 + 0xb8),0
                                                            ), lVar12 != 0)) {
                                                    *(undefined4 *)(lVar12 + 0x27c) = uVar19;
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
          }
        }
      }
    }
  }
code_r0x000180644ead:
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

