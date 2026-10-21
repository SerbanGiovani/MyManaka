// Ghidra pseudocode; not original source or compilable C.
// ev_f918c3ffd2d6248c6d4fad5aa522b430a49d797af8cc7a56710b3300de16841b

void ExposureUnnoticed2_Object3D_Player_Scripts_Other_PlayerMoveCalculator__OnUpdate__06000ec5
               (longlong param_1)

{
  longlong lVar1;
  code *pcVar2;
  char cVar3;
  int iVar4;
  code *pcVar5;
  longlong lVar6;
  undefined8 *puVar7;
  undefined8 uVar8;
  uint uVar9;
  undefined8 *puVar10;
  float fVar11;
  undefined4 uVar12;
  float fVar13;
  float fVar14;
  float fVar15;
  float fVar16;
  float fVar17;
  undefined8 uVar18;
  float fVar19;
  float fVar20;
  float fVar21;
  float fVar22;
  float fVar23;
  float fVar24;
  float fVar25;
  float fVar26;
  float fVar27;
  undefined8 uStack_198;
  float fStack_190;
  undefined8 uStack_188;
  float fStack_180;
  undefined8 uStack_178;
  undefined4 uStack_170;
  undefined8 uStack_168;
  float fStack_160;
  undefined8 uStack_158;
  float fStack_150;
  undefined8 uStack_148;
  float fStack_140;
  undefined8 uStack_138;
  undefined1 auStack_118 [16];
  undefined8 uStack_108;
  undefined8 uStack_100;
  undefined8 uStack_f8;
  undefined8 uStack_f0;
  undefined4 uStack_e8;
  
  if (cRam0000000182eb768e == '\0') {
    FUN_1802f2810(&DAT_182d58398);
    LOCK();
    UNLOCK();
    cRam0000000182eb768e = '\x01';
  }
  fVar23 = *(float *)(param_1 + 0x48);
  uStack_e8 = 0;
  uStack_108 = 0;
  uStack_100 = 0;
  uStack_f8 = 0;
  uStack_f0 = 0;
  uStack_178 = *(undefined8 *)(param_1 + 0x40);
  if ((*(longlong *)(param_1 + 0x20) != 0) &&
     (lVar6 = *(longlong *)(*(longlong *)(param_1 + 0x20) + 0x18), lVar6 != 0)) {
    uStack_198 = 0;
    fStack_190 = 0.0;
    pcVar5 = DAT_182ec1698;
    if ((DAT_182ec1698 == (code *)0x0) &&
       (pcVar5 = (code *)FUN_1802cf0c0(
                                      "UnityEngine.Transform::get_position_Injected(UnityEngine.Vector3&)"
                                      ), pcVar5 == (code *)0x0)) {
      uVar8 = FUN_1802ced60("UnityEngine.Transform::get_position_Injected(UnityEngine.Vector3&)");
                    /* WARNING: Subroutine does not return */
      FUN_1802cca90(uVar8,0);
    }
    DAT_182ec1698 = pcVar5;
    (*DAT_182ec1698)(lVar6,&uStack_198);
    fStack_180 = fVar23 - fStack_190;
    uStack_188 = CONCAT44(uStack_178._4_4_ - uStack_198._4_4_,(float)uStack_178 - (float)uStack_198)
    ;
    uVar12 = FUN_1803d4630(&uStack_188);
    *(undefined4 *)(param_1 + 0x14) = uVar12;
    if ((*(longlong *)(param_1 + 0x20) != 0) &&
       (lVar6 = *(longlong *)(*(longlong *)(param_1 + 0x20) + 0x18), lVar6 != 0)) {
      uStack_198 = 0;
      fStack_190 = 0.0;
      pcVar5 = DAT_182ec1698;
      if ((DAT_182ec1698 == (code *)0x0) &&
         (pcVar5 = (code *)FUN_1802cf0c0(
                                        "UnityEngine.Transform::get_position_Injected(UnityEngine.Vector3&)"
                                        ), pcVar5 == (code *)0x0)) {
        uVar8 = FUN_1802ced60("UnityEngine.Transform::get_position_Injected(UnityEngine.Vector3&)");
                    /* WARNING: Subroutine does not return */
        FUN_1802cca90(uVar8,0);
      }
      DAT_182ec1698 = pcVar5;
      (*DAT_182ec1698)(lVar6,&uStack_198);
      *(undefined8 *)(param_1 + 0x40) = uStack_198;
      *(float *)(param_1 + 0x48) = fStack_190;
      if (5.0 < *(float *)(param_1 + 0x14)) {
        *(undefined4 *)(param_1 + 0x14) = 0;
      }
      pcVar5 = DAT_182ec14f0;
      fVar23 = *(float *)(param_1 + 0x34);
      *(undefined4 *)(param_1 + 0x10) = 0;
      pcVar2 = DAT_182ec14f0;
      if ((pcVar5 == (code *)0x0) &&
         (pcVar5 = (code *)FUN_1802cf0c0("UnityEngine.Time::get_unscaledDeltaTime()"),
         pcVar2 = pcVar5, pcVar5 == (code *)0x0)) {
        uVar8 = FUN_1802ced60("UnityEngine.Time::get_unscaledDeltaTime()");
                    /* WARNING: Subroutine does not return */
        FUN_1802cca90(uVar8,0);
      }
      DAT_182ec14f0 = pcVar2;
      fVar13 = (float)(*pcVar5)();
      fVar23 = fVar23 - fVar13;
      fVar13 = 0.0;
      *(float *)(param_1 + 0x34) = fVar23;
      if (0.0 < fVar23) {
        return;
      }
      *(undefined4 *)(param_1 + 0x34) = 0x3e4ccccd;
      lVar6 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
      if (lVar6 != 0) {
        iVar4 = *(int *)(lVar6 + 0x10);
        if ((iVar4 == 10) || (uVar12 = 0xffffffff, iVar4 - 0xbU < 2)) {
          uVar12 = 8;
        }
        uVar8 = *(undefined8 *)(param_1 + 0x28);
        fVar23 = *(float *)(param_1 + 0x30);
        if ((*(longlong *)(param_1 + 0x20) != 0) &&
           (lVar6 = *(longlong *)(*(longlong *)(param_1 + 0x20) + 0x18), lVar6 != 0)) {
          uStack_198 = 0;
          fStack_190 = 0.0;
          pcVar5 = DAT_182ec1698;
          if ((DAT_182ec1698 == (code *)0x0) &&
             (pcVar5 = (code *)FUN_1802cf0c0(
                                            "UnityEngine.Transform::get_position_Injected(UnityEngine.Vector3&)"
                                            ), pcVar5 == (code *)0x0)) {
            uVar8 = FUN_1802ced60(
                                 "UnityEngine.Transform::get_position_Injected(UnityEngine.Vector3&)"
                                 );
                    /* WARNING: Subroutine does not return */
            FUN_1802cca90(uVar8,0);
          }
          DAT_182ec1698 = pcVar5;
          (*DAT_182ec1698)(lVar6,&uStack_198);
          uStack_178 = uStack_198;
          uStack_170 = fStack_190;
          uStack_198 = uVar8;
          fStack_190 = fVar23;
          FUN_181eda000(&uStack_198,&uStack_178,uVar12,*(undefined8 *)(param_1 + 0x38),0);
          lVar6 = *(longlong *)(param_1 + 0x38);
          if (lVar6 != 0) {
            pcVar5 = pcRam0000000182ebef78;
            if ((pcRam0000000182ebef78 == (code *)0x0) &&
               (pcVar5 = (code *)FUN_1802cf0c0("UnityEngine.AI.NavMeshPath::get_status()"),
               pcVar5 == (code *)0x0)) {
              uVar8 = FUN_1802ced60("UnityEngine.AI.NavMeshPath::get_status()");
                    /* WARNING: Subroutine does not return */
              FUN_1802cca90(uVar8,0);
            }
            pcRam0000000182ebef78 = pcVar5;
            iVar4 = (*pcRam0000000182ebef78)(lVar6);
            if (iVar4 == 0) {
              if (*(longlong *)(param_1 + 0x38) != 0) {
                lVar6 = FUN_181edad80(*(longlong *)(param_1 + 0x38),0);
                fVar23 = *(float *)(param_1 + 0x30);
                uVar8 = *(undefined8 *)(param_1 + 0x28);
                if (((*(longlong *)(param_1 + 0x20) != 0) &&
                    (lVar1 = *(longlong *)(*(longlong *)(param_1 + 0x20) + 0x58), lVar1 != 0)) &&
                   (lVar1 = *(longlong *)(lVar1 + 0x28), lVar1 != 0)) {
                  fVar25 = *(float *)(lVar1 + 0x10) * 0.22;
                  if (DAT_182eb5480 == '\0') {
                    FUN_1802f2810(&DAT_182d522a8);
                    LOCK();
                    UNLOCK();
                    DAT_182eb5480 = '\x01';
                  }
                  uVar9 = 1;
                  uStack_198 = **(undefined8 **)(DAT_182d522a8 + 0xb8);
                  fVar15 = (float)uStack_198;
                  fVar17 = (float)((ulonglong)uStack_198 >> 0x20);
                  fVar20 = *(float *)(*(undefined8 **)(DAT_182d522a8 + 0xb8) + 1);
                  if (lVar6 != 0) {
                    puVar10 = (undefined8 *)(lVar6 + 0x2c);
                    fVar26 = fVar17;
                    fVar27 = fVar20;
                    fVar24 = fVar15;
                    while ((int)uVar9 < *(int *)(lVar6 + 0x18)) {
                      if (*(uint *)(lVar6 + 0x18) <= uVar9) {
code_r0x000180407351:
                    /* WARNING: Subroutine does not return */
                        FUN_18031dae0();
                      }
                      uStack_138 = *puVar10;
                      fVar22 = *(float *)(puVar10 + 1);
                      uVar18 = uVar8;
                      fVar11 = fVar23;
                      if (uVar9 != 1) {
                        if (*(uint *)(lVar6 + 0x18) <= uVar9 - 1) goto code_r0x000180407351;
                        uVar18 = *(undefined8 *)((longlong)puVar10 + -0xc);
                        fVar11 = *(float *)((longlong)puVar10 + -4);
                      }
                      uStack_148 = *puVar10;
                      uStack_178 = uVar18;
                      uStack_158 = uVar18;
                      fStack_150 = fVar11;
                      fStack_140 = fVar22;
                      fVar14 = (float)FUN_1803fa1b0(&uStack_148,&uStack_158);
                      fVar13 = fVar13 + fVar14;
                      if (fVar25 < fVar14) {
                        if (DAT_182eb5480 == '\0') {
                          FUN_1802f2810(&DAT_182d522a8);
                          LOCK();
                          UNLOCK();
                          DAT_182eb5480 = '\x01';
                        }
                        uVar18 = **(undefined8 **)(DAT_182d522a8 + 0xb8);
                        fVar21 = fVar24 - (float)uVar18;
                        fVar16 = fVar27 - *(float *)(*(undefined8 **)(DAT_182d522a8 + 0xb8) + 1);
                        fVar19 = fVar26 - (float)((ulonglong)uVar18 >> 0x20);
                        if (9.9999994e-11 <= fVar21 * fVar21 + fVar19 * fVar19 + fVar16 * fVar16)
                        goto code_r0x0001804070a8;
                        fStack_160 = fVar22 - fVar11;
                        uStack_168 = CONCAT44(uStack_138._4_4_ - uStack_178._4_4_,
                                              (float)uStack_138 - (float)uStack_178);
                        puVar7 = (undefined8 *)FUN_1803d4c40(auStack_118,&uStack_168);
                        fVar15 = (float)*puVar7 * fVar25 + (float)uStack_178;
                        fVar17 = *(float *)((longlong)puVar7 + 4) * fVar25 + uStack_178._4_4_;
                        fVar20 = *(float *)(puVar7 + 1) * fVar25 + fVar11;
                        uVar9 = uVar9 + 1;
                        puVar10 = (undefined8 *)((longlong)puVar10 + 0xc);
                        uStack_198 = CONCAT44(fVar17,fVar15);
                        fVar26 = fVar17;
                        fVar27 = fVar20;
                        fVar24 = fVar15;
                      }
                      else {
code_r0x0001804070a8:
                        fVar25 = fVar25 - fVar14;
                        uVar9 = uVar9 + 1;
                        puVar10 = (undefined8 *)((longlong)puVar10 + 0xc);
                      }
                    }
                    if (DAT_182eb5480 == '\0') {
                      FUN_1802f2810(&DAT_182d522a8);
                      LOCK();
                      UNLOCK();
                      DAT_182eb5480 = '\x01';
                    }
                    uVar8 = **(undefined8 **)(DAT_182d522a8 + 0xb8);
                    fVar25 = fVar24 - (float)uVar8;
                    fVar23 = fVar27 - *(float *)(*(undefined8 **)(DAT_182d522a8 + 0xb8) + 1);
                    fVar22 = fVar26 - (float)((ulonglong)uVar8 >> 0x20);
                    if (9.9999994e-11 <= fVar22 * fVar22 + fVar25 * fVar25 + fVar23 * fVar23) {
                      uStack_168 = CONCAT44(fVar17,fVar15);
                      pcVar5 = pcRam0000000182ebef30;
                      fStack_160 = fVar20;
                      if ((pcRam0000000182ebef30 == (code *)0x0) &&
                         (pcVar5 = (code *)FUN_1802cf0c0(
                                                  "UnityEngine.AI.NavMesh::SamplePosition_Injected(UnityEngine.Vector3&,UnityEngine.AI.NavMeshHit&,System.Single,System.Int32)"
                                                  ), pcVar5 == (code *)0x0)) {
                        uVar8 = FUN_1802ced60(
                                             "UnityEngine.AI.NavMesh::SamplePosition_Injected(UnityEngine.Vector3&,UnityEngine.AI.NavMeshHit&,System.Single,System.Int32)"
                                             );
                    /* WARNING: Subroutine does not return */
                        FUN_1802cca90(uVar8,0);
                      }
                      pcRam0000000182ebef30 = pcVar5;
                      cVar3 = (*pcRam0000000182ebef30)(&uStack_168,&uStack_108);
                      if (cVar3 != '\0') {
                        fVar15 = (float)uStack_108;
                        fVar17 = (float)((ulonglong)uStack_108 >> 0x20);
                        uStack_198 = uStack_108;
                        fVar26 = fVar17;
                        fVar20 = (float)uStack_100;
                        fVar27 = (float)uStack_100;
                        fVar24 = fVar15;
                      }
                    }
                    if ((*(longlong *)(param_1 + 0x20) != 0) &&
                       (lVar6 = *(longlong *)(*(longlong *)(param_1 + 0x20) + 0x60), lVar6 != 0)) {
                      if (*(char *)(lVar6 + 0x1b) == '\0') {
                        fVar23 = 5.0;
                      }
                      else {
                        fVar23 = 2.5;
                      }
                      if (fVar23 < fVar13) {
                        fStack_180 = fVar27 - *(float *)(param_1 + 0x30);
                        uStack_188 = CONCAT44(fVar26 - (float)((ulonglong)
                                                               *(undefined8 *)(param_1 + 0x28) >>
                                                              0x20),
                                              fVar24 - (float)*(undefined8 *)(param_1 + 0x28));
                        uVar12 = FUN_1803d4630(&uStack_188);
                        *(ulonglong *)(param_1 + 0x28) = CONCAT44(fVar17,fVar15);
                        *(undefined4 *)(param_1 + 0x10) = uVar12;
                        *(float *)(param_1 + 0x30) = fVar20;
                      }
                      goto code_r0x000180407230;
                    }
                  }
                }
              }
            }
            else if ((*(longlong *)(param_1 + 0x20) != 0) &&
                    (lVar6 = *(longlong *)(*(longlong *)(param_1 + 0x20) + 0x18), lVar6 != 0)) {
              uStack_188 = 0;
              fStack_180 = 0.0;
              pcVar5 = DAT_182ec1698;
              if ((DAT_182ec1698 == (code *)0x0) &&
                 (pcVar5 = (code *)FUN_1802cf0c0(
                                                "UnityEngine.Transform::get_position_Injected(UnityEngine.Vector3&)"
                                                ), pcVar5 == (code *)0x0)) {
                uVar8 = FUN_1802ced60(
                                     "UnityEngine.Transform::get_position_Injected(UnityEngine.Vector3&)"
                                     );
                    /* WARNING: Subroutine does not return */
                FUN_1802cca90(uVar8,0);
              }
              DAT_182ec1698 = pcVar5;
              (*DAT_182ec1698)(lVar6,&uStack_188);
              *(undefined8 *)(param_1 + 0x28) = uStack_188;
              *(float *)(param_1 + 0x30) = fStack_180;
code_r0x000180407230:
              *(undefined4 *)(param_1 + 0x18) = *(undefined4 *)(param_1 + 0x10);
              return;
            }
          }
        }
      }
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

