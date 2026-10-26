// Ghidra pseudocode; not original source or compilable C.
// ev_1823623d9fd500d0ae23f0c931169a497c3f7b3c48c95bfde6837f94acf5d10f

void ExposureUnnoticed2_Object3D_NPC_Script_NpcController__OnFixedUpdate__06001058(longlong param_1)

{
  float *pfVar1;
  int iVar2;
  longlong lVar3;
  longlong lVar4;
  longlong lVar5;
  code *pcVar6;
  undefined8 uVar7;
  bool bVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  undefined8 uStack_38;
  undefined *puStack_30;
  undefined8 uStack_28;
  float fStack_20;
  
  if (*(longlong *)(param_1 + 0x48) == 0) goto code_r0x0001804285e3;
  iVar2 = *(int *)(*(longlong *)(param_1 + 0x48) + 0x10);
  if (iVar2 < 3) {
    if (iVar2 == 0) {
      lVar5 = *(longlong *)(param_1 + 0x30);
    }
    else {
      if (iVar2 != 2) {
        return;
      }
      lVar5 = *(longlong *)(param_1 + 0x30);
    }
  }
  else {
    if (iVar2 == 5) {
      iVar2 = *(int *)(*(longlong *)(param_1 + 0x48) + 100);
      if ((iVar2 != 0xc) && (iVar2 != 0xd)) {
        bVar8 = iVar2 == 0xe;
        goto code_r0x0001804285a8;
      }
    }
    else {
      if (iVar2 != 7) {
        return;
      }
      puStack_30 = &UNK_18042859f;
      lVar5 = FUN_180436330();
      if (lVar5 == 0) goto code_r0x0001804285e3;
      bVar8 = *(char *)(lVar5 + 0x10) == '\0';
code_r0x0001804285a8:
      if (!bVar8) {
        return;
      }
    }
    lVar5 = *(longlong *)(param_1 + 0x30);
  }
  if ((lVar5 == 0) || (lVar5 = *(longlong *)(lVar5 + 0x20), lVar5 == 0)) {
code_r0x0001804285e3:
                    /* WARNING: Subroutine does not return */
    puStack_30 = &UNK_1804285e8;
    FUN_18031dad0();
  }
  if (cRam0000000182eb7768 == '\0') {
    FUN_1802f2810(&DAT_182d58288,0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d58398);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d53aa8);
    LOCK();
    UNLOCK();
    cRam0000000182eb7768 = '\x01';
  }
  lVar3 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
  if (lVar3 == 0) goto code_r0x00018042eac2;
  if (*(int *)(lVar3 + 0x10) == 0xb) {
    if ((*(longlong *)(lVar5 + 0x10) == 0) ||
       (lVar3 = *(longlong *)(*(longlong *)(lVar5 + 0x10) + 0x40), lVar3 == 0))
    goto code_r0x00018042eac2;
    fVar10 = *(float *)(lVar3 + 0xd8);
    if (20.0 < fVar10) {
      bVar8 = SBORROW4(*(int *)(lVar5 + 0x4c),2);
      iVar2 = *(int *)(lVar5 + 0x4c) + -2;
    }
    else {
      if (fVar10 <= 30.0) goto code_r0x00018042e740;
      bVar8 = SBORROW4(*(int *)(lVar5 + 0x4c),4);
      iVar2 = *(int *)(lVar5 + 0x4c) + -4;
    }
    if (bVar8 != iVar2 < 0) {
      *(int *)(lVar5 + 0x4c) = *(int *)(lVar5 + 0x4c) + 1;
      return;
    }
  }
code_r0x00018042e740:
  if (((*(longlong *)(lVar5 + 0x10) == 0) ||
      (lVar3 = *(longlong *)(*(longlong *)(lVar5 + 0x10) + 0x38), lVar3 == 0)) ||
     (lVar3 = *(longlong *)(lVar3 + 0x10), lVar3 == 0)) goto code_r0x00018042eac2;
  uStack_38 = 0;
  puStack_30 = (undefined *)((ulonglong)puStack_30 & 0xffffffff00000000);
  pcVar6 = DAT_182ec1698;
  if ((DAT_182ec1698 == (code *)0x0) &&
     (pcVar6 = (code *)FUN_1802cf0c0(
                                    "UnityEngine.Transform::get_position_Injected(UnityEngine.Vector3&)"
                                    ), pcVar6 == (code *)0x0)) {
    uVar7 = FUN_1802ced60("UnityEngine.Transform::get_position_Injected(UnityEngine.Vector3&)");
                    /* WARNING: Subroutine does not return */
    FUN_1802cca90(uVar7,0);
  }
  DAT_182ec1698 = pcVar6;
  (*DAT_182ec1698)(lVar3,&uStack_38);
  uStack_28 = *(undefined8 *)(lVar5 + 0x1c);
  fVar10 = *(float *)(lVar5 + 0x24);
  pcVar6 = pcRam0000000182ec14f8;
  if ((pcRam0000000182ec14f8 == (code *)0x0) &&
     (pcVar6 = (code *)FUN_1802cf0c0("UnityEngine.Time::get_fixedDeltaTime()"),
     pcVar6 == (code *)0x0)) {
    uVar7 = FUN_1802ced60("UnityEngine.Time::get_fixedDeltaTime()");
                    /* WARNING: Subroutine does not return */
    FUN_1802cca90(uVar7,0);
  }
  pcRam0000000182ec14f8 = pcVar6;
  fVar9 = (float)(*pcRam0000000182ec14f8)();
  fVar11 = (float)(*(int *)(lVar5 + 0x4c) + 1);
  fStack_20 = fVar10 * fVar9 * fVar11 + puStack_30._0_4_;
  uStack_28 = CONCAT44(uStack_28._4_4_ * fVar9 * fVar11 + uStack_38._4_4_,
                       (float)uStack_28 * fVar9 * fVar11 + (float)uStack_38);
  pcVar6 = DAT_182ec16a0;
  if ((DAT_182ec16a0 == (code *)0x0) &&
     (pcVar6 = (code *)FUN_1802cf0c0(
                                    "UnityEngine.Transform::set_position_Injected(UnityEngine.Vector3&)"
                                    ), pcVar6 == (code *)0x0)) {
    uVar7 = FUN_1802ced60("UnityEngine.Transform::set_position_Injected(UnityEngine.Vector3&)");
                    /* WARNING: Subroutine does not return */
    FUN_1802cca90(uVar7,0);
  }
  DAT_182ec16a0 = pcVar6;
  (*DAT_182ec16a0)(lVar3,&uStack_28);
  *(undefined4 *)(lVar5 + 0x4c) = 0;
  if ((*(longlong *)(lVar5 + 0x10) == 0) ||
     (lVar3 = *(longlong *)(*(longlong *)(lVar5 + 0x10) + 0x80), lVar3 == 0)) {
code_r0x00018042eb52:
                    /* WARNING: Subroutine does not return */
    FUN_18031dad0();
  }
  pcVar6 = pcRam0000000182ec3a18;
  if ((pcRam0000000182ec3a18 == (code *)0x0) &&
     (pcVar6 = (code *)FUN_1802cf0c0("UnityEngine.CapsuleCollider::get_radius()"),
     pcVar6 == (code *)0x0)) {
    uVar7 = FUN_1802ced60("UnityEngine.CapsuleCollider::get_radius()");
                    /* WARNING: Subroutine does not return */
    FUN_1802cca90(uVar7,0);
  }
  pcRam0000000182ec3a18 = pcVar6;
  fVar10 = (float)(*pcRam0000000182ec3a18)(lVar3);
  *(undefined1 *)(lVar5 + 0x28) = 0;
  fVar10 = fVar10 + fVar10;
  if ((*(longlong *)(lVar5 + 0x10) == 0) ||
     (lVar3 = *(longlong *)(*(longlong *)(lVar5 + 0x10) + 0x40), lVar3 == 0))
  goto code_r0x00018042eb52;
  pfVar1 = (float *)(lVar3 + 0xd8);
  if (*pfVar1 <= fVar10 && fVar10 != *pfVar1) {
code_r0x00018042ea93:
    *(undefined1 *)(lVar5 + 0x28) = 1;
  }
  else {
    lVar3 = *(longlong *)(*(longlong *)(lVar5 + 0x10) + 0x40);
    if (*(longlong *)(lVar3 + 0x38) != 0) {
      lVar3 = *(longlong *)(*(longlong *)(lVar3 + 0x38) + 0x28);
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
      if (lVar3 != 0) {
        if (*(int *)(DAT_182d53aa8 + 0xe0) == 0) {
          FUN_18035c820();
        }
        if (*(longlong *)(lVar3 + 0x10) != 0) {
          if (((*(longlong *)(lVar5 + 0x10) == 0) ||
              (lVar3 = *(longlong *)(*(longlong *)(lVar5 + 0x10) + 0x40), lVar3 == 0)) ||
             (lVar3 = *(longlong *)(lVar3 + 0x38), lVar3 == 0)) goto code_r0x00018042eac2;
          lVar3 = *(longlong *)(lVar3 + 0x10);
          lVar4 = *(longlong *)(*(longlong *)(lVar5 + 0x10) + 0x10);
          if (*(int *)(DAT_182d58288 + 0xe0) == 0) {
            FUN_18035c820();
          }
          if (lVar3 == 0) goto code_r0x00018042eac2;
          uStack_38 = 0;
          puStack_30 = (undefined *)((ulonglong)puStack_30 & 0xffffffff00000000);
          pcVar6 = DAT_182ec1698;
          if ((DAT_182ec1698 == (code *)0x0) &&
             (pcVar6 = (code *)FUN_1802cf0c0(
                                            "UnityEngine.Transform::get_position_Injected(UnityEngine.Vector3&)"
                                            ), pcVar6 == (code *)0x0)) {
            uVar7 = FUN_1802ced60(
                                 "UnityEngine.Transform::get_position_Injected(UnityEngine.Vector3&)"
                                 );
                    /* WARNING: Subroutine does not return */
            FUN_1802cca90(uVar7,0);
          }
          DAT_182ec1698 = pcVar6;
          (*DAT_182ec1698)(lVar3,&uStack_38);
          if (lVar4 == 0) goto code_r0x00018042eac2;
          uStack_28 = 0;
          fStack_20 = 0.0;
          pcVar6 = DAT_182ec1698;
          if ((DAT_182ec1698 == (code *)0x0) &&
             (pcVar6 = (code *)FUN_1802cf0c0(
                                            "UnityEngine.Transform::get_position_Injected(UnityEngine.Vector3&)"
                                            ), pcVar6 == (code *)0x0)) {
            uVar7 = FUN_1802ced60(
                                 "UnityEngine.Transform::get_position_Injected(UnityEngine.Vector3&)"
                                 );
                    /* WARNING: Subroutine does not return */
            FUN_1802cca90(uVar7,0);
          }
          DAT_182ec1698 = pcVar6;
          (*DAT_182ec1698)(lVar4,&uStack_28);
          if ((uStack_38._4_4_ - uStack_28._4_4_) * (uStack_38._4_4_ - uStack_28._4_4_) +
              ((float)uStack_38 - (float)uStack_28) * ((float)uStack_38 - (float)uStack_28) +
              (puStack_30._0_4_ - fStack_20) * (puStack_30._0_4_ - fStack_20) < fVar10 * fVar10)
          goto code_r0x00018042ea93;
        }
      }
    }
  }
  if (*(char *)(lVar5 + 0x28) != '\0') {
    if ((*(longlong *)(lVar5 + 0x10) == 0) ||
       (lVar5 = *(longlong *)(*(longlong *)(lVar5 + 0x10) + 200), lVar5 == 0)) {
code_r0x00018042eac2:
                    /* WARNING: Subroutine does not return */
      FUN_18031dad0();
    }
    ExposureUnnoticed2_Object3D_NPC_Script_NpcCollisionCorrecter__CollisionCorrect__0600100b
              (lVar5,0);
  }
  return;
}

