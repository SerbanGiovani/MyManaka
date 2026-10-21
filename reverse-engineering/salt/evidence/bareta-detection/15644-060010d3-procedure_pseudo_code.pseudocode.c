// Ghidra pseudocode; not original source or compilable C.
// ev_6d4d86c66edc6cf87267f305ae1e379a11ddf325a661dd2c8efeea170fc6cf36

void ExposureUnnoticed2_Object3D_NPC_Script_PlayerSearcher__ForPlayerUpdate__060010d3
               (longlong param_1)

{
  undefined4 uVar1;
  longlong lVar2;
  longlong lVar3;
  ulonglong uVar4;
  char cVar5;
  uint uVar6;
  undefined8 *puVar7;
  longlong lVar8;
  code *pcVar9;
  undefined8 uVar10;
  byte bVar11;
  longlong *plVar12;
  bool bVar13;
  float fVar14;
  float fVar15;
  float fVar16;
  float fVar17;
  float fVar18;
  float fVar19;
  undefined4 auStackX_8 [2];
  undefined8 uStack_e8;
  float fStack_e0;
  undefined8 uStack_d8;
  float fStack_d0;
  undefined8 uStack_c8;
  float fStack_c0;
  undefined8 uStack_b8;
  undefined8 uStack_b0;
  undefined8 uStack_a8;
  undefined8 uStack_a0;
  undefined8 uStack_98;
  undefined4 uStack_90;
  
  if (cRam0000000182eb7798 == '\0') {
    FUN_1802f2810(&DAT_182d58288);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d53aa8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d55a30);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d58378);
    LOCK();
    UNLOCK();
    cRam0000000182eb7798 = '\x01';
  }
  lVar8 = *(longlong *)(param_1 + 0x50);
  bVar13 = false;
  uVar6 = 0;
  uStack_98 = 0;
  uStack_90 = 0;
  *(undefined1 *)(param_1 + 0x68) = 0;
  uStack_b8 = 0;
  uStack_b0 = 0;
  uStack_a8 = 0;
  uStack_a0 = 0;
  if (lVar8 == 0) goto code_r0x0001804388f9;
  plVar12 = (longlong *)(lVar8 + 0x20);
  for (; (int)uVar6 < (int)*(uint *)(lVar8 + 0x18); uVar6 = uVar6 + 1) {
    if (*(uint *)(lVar8 + 0x18) <= uVar6) {
                    /* WARNING: Subroutine does not return */
      FUN_18031dae0();
    }
    if (*plVar12 == 0) goto code_r0x0001804388f9;
    if (*(char *)(*plVar12 + 0x20) != '\0') {
      bVar13 = true;
      break;
    }
    plVar12 = plVar12 + 1;
  }
  if ((((**(longlong **)(DAT_182d58378 + 0xb8) == 0) ||
       (lVar8 = *(longlong *)(**(longlong **)(DAT_182d58378 + 0xb8) + 0x40), lVar8 == 0)) ||
      (lVar8 = *(longlong *)(lVar8 + 0x60), lVar8 == 0)) ||
     ((lVar2 = *(longlong *)(param_1 + 0x88), lVar2 == 0 ||
      (lVar3 = *(longlong *)(lVar2 + 0x40), lVar3 == 0)))) goto code_r0x0001804388f9;
  uVar10 = *(undefined8 *)(lVar8 + 0x264);
  uStack_c8 = *(undefined8 *)(lVar3 + 0xdc);
  fVar17 = *(float *)(lVar8 + 0x26c);
  fVar14 = (float)uStack_c8;
  fVar15 = *(float *)(lVar3 + 0xe4);
  uVar4 = (ulonglong)uStack_c8 >> 0x20;
  if ((lVar2 == 0) || (*(longlong *)(lVar2 + 0x10) == 0)) goto code_r0x0001804388f9;
  puVar7 = (undefined8 *)FUN_181f4c360(&uStack_c8,*(longlong *)(lVar2 + 0x10),0);
  uStack_d8 = *puVar7;
  if (bVar13) {
    if (*(longlong *)(param_1 + 0x58) == 0) goto code_r0x0001804388f9;
    bVar11 = *(byte *)(*(longlong *)(param_1 + 0x58) + 0x20);
  }
  else {
    bVar11 = 0;
  }
  if ((bVar11 & 0.0 < (float)((ulonglong)uStack_d8 >> 0x20) *
                      ((float)((ulonglong)uVar10 >> 0x20) - (float)uVar4) +
                      (float)uStack_d8 * ((float)uVar10 - fVar14) +
                      *(float *)(puVar7 + 1) * (fVar17 - fVar15)) == 0) {
    return;
  }
  lVar8 = ExposureUnnoticed2_Master_Common_MCommon__get_Instance__0600133e(0);
  if (lVar8 == 0) goto code_r0x0001804388f9;
  lVar2 = *(longlong *)(param_1 + 0x60);
  uVar1 = *(undefined4 *)(lVar8 + 0x154);
  if (lVar2 == 0) goto code_r0x0001804388f9;
  uStack_e8 = 0;
  fStack_e0 = 0.0;
  pcVar9 = DAT_182ec1698;
  if ((DAT_182ec1698 == (code *)0x0) &&
     (pcVar9 = (code *)FUN_1802cf0c0(
                                    "UnityEngine.Transform::get_position_Injected(UnityEngine.Vector3&)"
                                    ), pcVar9 == (code *)0x0)) {
    uVar10 = FUN_1802ced60("UnityEngine.Transform::get_position_Injected(UnityEngine.Vector3&)");
                    /* WARNING: Subroutine does not return */
    FUN_1802cca90(uVar10,0);
  }
  DAT_182ec1698 = pcVar9;
  (*DAT_182ec1698)(lVar2,&uStack_e8);
  if (((**(longlong **)(DAT_182d58378 + 0xb8) == 0) ||
      (lVar8 = *(longlong *)(**(longlong **)(DAT_182d58378 + 0xb8) + 0x40), lVar8 == 0)) ||
     (lVar8 = *(longlong *)(lVar8 + 0x60), lVar8 == 0)) goto code_r0x0001804388f9;
  uVar6 = *(uint *)(lVar8 + 0x27c);
  if (*(int *)(DAT_182d58288 + 0xe0) == 0) {
    FUN_18035c820();
  }
  if ((uVar6 & 2) == 0) {
    if (*(int *)(DAT_182d58288 + 0xe0) == 0) {
      FUN_18035c820();
    }
    if ((uVar6 & 8) != 0) goto code_r0x000180438326;
    if (*(int *)(DAT_182d58288 + 0xe0) == 0) {
      FUN_18035c820();
    }
    if ((uVar6 & 0x20) != 0) goto code_r0x000180438326;
    fVar14 = fStack_e0;
    fVar17 = (float)uStack_e8;
    fVar15 = uStack_e8._4_4_;
  }
  else {
code_r0x000180438326:
    if (((*(longlong *)(param_1 + 0x70) == 0) ||
        (lVar8 = *(longlong *)(*(longlong *)(param_1 + 0x70) + 0x40), lVar8 == 0)) ||
       ((lVar8 = *(longlong *)(lVar8 + 0x70), lVar8 == 0 ||
        (lVar8 = *(longlong *)(lVar8 + 0x20), lVar8 == 0)))) goto code_r0x0001804388f9;
    uStack_d8 = 0;
    fStack_d0 = 0.0;
    pcVar9 = DAT_182ec1698;
    if ((DAT_182ec1698 == (code *)0x0) &&
       (pcVar9 = (code *)FUN_1802cf0c0(
                                      "UnityEngine.Transform::get_position_Injected(UnityEngine.Vector3&)"
                                      ), pcVar9 == (code *)0x0)) {
      uVar10 = FUN_1802ced60("UnityEngine.Transform::get_position_Injected(UnityEngine.Vector3&)");
                    /* WARNING: Subroutine does not return */
      FUN_1802cca90(uVar10,0);
    }
    DAT_182ec1698 = pcVar9;
    (*DAT_182ec1698)(lVar8,&uStack_d8);
    fVar14 = fStack_e0;
    fVar17 = (float)uStack_e8;
    fVar16 = (float)uStack_d8 - (float)uStack_e8;
    fVar15 = uStack_e8._4_4_;
    fVar18 = uStack_d8._4_4_ - uStack_e8._4_4_;
    fVar19 = fStack_d0 - fStack_e0;
    uVar6 = *(uint *)(param_1 + 0x78);
    if (*(int *)(lRam0000000182d55a30 + 0xe0) == 0) {
      FUN_18035c820();
    }
    if (cRam0000000182ec3715 == '\0') {
      FUN_1802f2810(0x182d55a30);
      LOCK();
      UNLOCK();
      cRam0000000182ec3715 = '\x01';
      fVar14 = fStack_e0;
      fVar15 = uStack_e8._4_4_;
      fVar17 = (float)uStack_e8;
    }
    if (*(int *)(lRam0000000182d55a30 + 0xe0) == 0) {
      FUN_18035c820();
    }
    auStackX_8[0] = FUN_181fb32b0(0);
    uStack_d8 = CONCAT44(fVar18,fVar16);
    uStack_e8 = CONCAT44(fVar15,fVar17);
    uStack_c8 = CONCAT44(fVar15,fVar17);
    fStack_d0 = fVar19;
    fStack_c0 = fVar14;
    cVar5 = FUN_181fba480(auStackX_8,&uStack_c8,&uStack_d8,&uStack_b8,uVar1,~uVar6,1,0);
    if (cVar5 != '\0') {
      lVar8 = FUN_181fb7480(&uStack_b8,0);
      if (lVar8 == 0) goto code_r0x0001804388f9;
      lVar8 = ExposureUnnoticed2_Scripts_InGame_Util_ColliderTriggerController__get_CenterObject__0600169c
                        (lVar8,0);
      if ((**(longlong **)(DAT_182d58378 + 0xb8) == 0) ||
         (lVar2 = *(longlong *)(**(longlong **)(DAT_182d58378 + 0xb8) + 0x40), lVar2 == 0))
      goto code_r0x0001804388f9;
      lVar2 = *(longlong *)(lVar2 + 0x28);
      if (*(int *)(DAT_182d53aa8 + 0xe0) == 0) {
        FUN_18035c820();
      }
      if (DAT_182ec12f3 == '\0') {
        FUN_1802f2810(&DAT_182d53aa8);
        LOCK();
        UNLOCK();
        DAT_182ec12f3 = '\x01';
        fVar14 = fStack_e0;
        fVar15 = uStack_e8._4_4_;
        fVar17 = (float)uStack_e8;
      }
      if (*(int *)(DAT_182d53aa8 + 0xe0) == 0) {
        FUN_18035c820();
      }
      if (DAT_182ec129b == '\0') {
        FUN_1802f2810(&DAT_182d53aa8);
        LOCK();
        UNLOCK();
        DAT_182ec129b = '\x01';
        fVar14 = fStack_e0;
        fVar17 = (float)uStack_e8;
        fVar15 = uStack_e8._4_4_;
      }
      if (lVar8 == 0 && lVar2 == 0) goto code_r0x0001804388a6;
      if (lVar2 == 0) {
        if (*(int *)(DAT_182d53aa8 + 0xe0) == 0) {
          FUN_18035c820();
        }
        if (lVar8 == 0) goto code_r0x0001804388f9;
        bVar13 = *(longlong *)(lVar8 + 0x10) == 0;
      }
      else if (lVar8 == 0) {
        if (*(int *)(DAT_182d53aa8 + 0xe0) == 0) {
          FUN_18035c820();
        }
        bVar13 = *(longlong *)(lVar2 + 0x10) == 0;
      }
      else {
        bVar13 = lVar8 == lVar2;
      }
      if (bVar13) goto code_r0x0001804388a6;
    }
  }
  if ((((*(longlong *)(param_1 + 0x70) != 0) &&
       (lVar8 = *(longlong *)(*(longlong *)(param_1 + 0x70) + 0x40), lVar8 != 0)) &&
      (lVar8 = *(longlong *)(lVar8 + 0x70), lVar8 != 0)) &&
     (lVar8 = *(longlong *)(lVar8 + 0x138), lVar8 != 0)) {
    uStack_d8 = 0;
    fStack_d0 = 0.0;
    pcVar9 = DAT_182ec1698;
    if ((DAT_182ec1698 == (code *)0x0) &&
       (pcVar9 = (code *)FUN_1802cf0c0(
                                      "UnityEngine.Transform::get_position_Injected(UnityEngine.Vector3&)"
                                      ), pcVar9 == (code *)0x0)) {
      uVar10 = FUN_1802ced60("UnityEngine.Transform::get_position_Injected(UnityEngine.Vector3&)");
                    /* WARNING: Subroutine does not return */
      FUN_1802cca90(uVar10,0);
    }
    DAT_182ec1698 = pcVar9;
    (*DAT_182ec1698)(lVar8,&uStack_d8);
    fVar19 = (float)uStack_d8 - fVar17;
    fVar18 = uStack_d8._4_4_ - fVar15;
    fVar16 = fStack_d0 - fVar14;
    uVar6 = *(uint *)(param_1 + 0x78);
    if (*(int *)(lRam0000000182d55a30 + 0xe0) == 0) {
      FUN_18035c820();
    }
    if (cRam0000000182ec3715 == '\0') {
      FUN_1802f2810(0x182d55a30);
      LOCK();
      UNLOCK();
      fVar17 = (float)uStack_e8;
      fVar15 = (float)((ulonglong)uStack_e8 >> 0x20);
      cRam0000000182ec3715 = '\x01';
      fVar14 = fStack_e0;
    }
    if (*(int *)(lRam0000000182d55a30 + 0xe0) == 0) {
      FUN_18035c820();
    }
    auStackX_8[0] = FUN_181fb32b0(0);
    uStack_c8 = CONCAT44(fVar18,fVar19);
    uStack_d8 = CONCAT44(fVar15,fVar17);
    fStack_d0 = fVar14;
    fStack_c0 = fVar16;
    cVar5 = FUN_181fba480(auStackX_8,&uStack_d8,&uStack_c8,&uStack_b8,uVar1,~uVar6,1,0);
    if (cVar5 == '\0') {
      return;
    }
    lVar8 = FUN_181fb7480(&uStack_b8,0);
    if (lVar8 != 0) {
      lVar8 = ExposureUnnoticed2_Scripts_InGame_Util_ColliderTriggerController__get_CenterObject__0600169c
                        (lVar8,0);
      if ((**(longlong **)(DAT_182d58378 + 0xb8) != 0) &&
         (lVar2 = *(longlong *)(**(longlong **)(DAT_182d58378 + 0xb8) + 0x40), lVar2 != 0)) {
        lVar2 = *(longlong *)(lVar2 + 0x28);
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
        if (lVar8 != 0 || lVar2 != 0) {
          if (lVar2 == 0) {
            if (*(int *)(DAT_182d53aa8 + 0xe0) == 0) {
              FUN_18035c820();
            }
            if (lVar8 == 0) goto code_r0x0001804388f9;
            bVar13 = *(longlong *)(lVar8 + 0x10) == 0;
          }
          else if (lVar8 == 0) {
            if (*(int *)(DAT_182d53aa8 + 0xe0) == 0) {
              FUN_18035c820();
            }
            bVar13 = *(longlong *)(lVar2 + 0x10) == 0;
          }
          else {
            bVar13 = lVar8 == lVar2;
          }
          if (!bVar13) {
            return;
          }
        }
code_r0x0001804388a6:
        *(undefined1 *)(param_1 + 0x68) = 1;
        return;
      }
    }
  }
code_r0x0001804388f9:
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

