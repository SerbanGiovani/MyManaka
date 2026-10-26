// Ghidra pseudocode; not original source or compilable C.
// ev_88705e50c892afee70c76b53743792cb34f6bb257e6c9d14418d3638cdc73160

void ExposureUnnoticed2_Object3D_NPC_Script_NpcLocomotion__OnFixedUpdate__0600107c(longlong param_1)

{
  float *pfVar1;
  longlong lVar2;
  longlong lVar3;
  int iVar4;
  code *pcVar5;
  undefined8 uVar6;
  bool bVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  undefined8 uStack_38;
  float fStack_30;
  undefined8 uStack_28;
  float fStack_20;
  
  if (cRam0000000182eb7768 == '\0') {
    FUN_1802f2810(&DAT_182d58288);
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
  lVar2 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
  if (lVar2 == 0) goto code_r0x00018042eac2;
  if (*(int *)(lVar2 + 0x10) == 0xb) {
    if ((*(longlong *)(param_1 + 0x10) == 0) ||
       (lVar2 = *(longlong *)(*(longlong *)(param_1 + 0x10) + 0x40), lVar2 == 0))
    goto code_r0x00018042eac2;
    fVar9 = *(float *)(lVar2 + 0xd8);
    if (20.0 < fVar9) {
      bVar7 = SBORROW4(*(int *)(param_1 + 0x4c),2);
      iVar4 = *(int *)(param_1 + 0x4c) + -2;
    }
    else {
      if (fVar9 <= 30.0) goto code_r0x00018042e740;
      bVar7 = SBORROW4(*(int *)(param_1 + 0x4c),4);
      iVar4 = *(int *)(param_1 + 0x4c) + -4;
    }
    if (bVar7 != iVar4 < 0) {
      *(int *)(param_1 + 0x4c) = *(int *)(param_1 + 0x4c) + 1;
      return;
    }
  }
code_r0x00018042e740:
  if (((*(longlong *)(param_1 + 0x10) == 0) ||
      (lVar2 = *(longlong *)(*(longlong *)(param_1 + 0x10) + 0x38), lVar2 == 0)) ||
     (lVar2 = *(longlong *)(lVar2 + 0x10), lVar2 == 0)) goto code_r0x00018042eac2;
  uStack_38 = 0;
  fStack_30 = 0.0;
  pcVar5 = DAT_182ec1698;
  if ((DAT_182ec1698 == (code *)0x0) &&
     (pcVar5 = (code *)FUN_1802cf0c0(
                                    "UnityEngine.Transform::get_position_Injected(UnityEngine.Vector3&)"
                                    ), pcVar5 == (code *)0x0)) {
    uVar6 = FUN_1802ced60("UnityEngine.Transform::get_position_Injected(UnityEngine.Vector3&)");
                    /* WARNING: Subroutine does not return */
    FUN_1802cca90(uVar6,0);
  }
  DAT_182ec1698 = pcVar5;
  (*DAT_182ec1698)(lVar2,&uStack_38);
  uStack_28 = *(undefined8 *)(param_1 + 0x1c);
  fVar9 = *(float *)(param_1 + 0x24);
  pcVar5 = pcRam0000000182ec14f8;
  if ((pcRam0000000182ec14f8 == (code *)0x0) &&
     (pcVar5 = (code *)FUN_1802cf0c0("UnityEngine.Time::get_fixedDeltaTime()"),
     pcVar5 == (code *)0x0)) {
    uVar6 = FUN_1802ced60("UnityEngine.Time::get_fixedDeltaTime()");
                    /* WARNING: Subroutine does not return */
    FUN_1802cca90(uVar6,0);
  }
  pcRam0000000182ec14f8 = pcVar5;
  fVar8 = (float)(*pcRam0000000182ec14f8)();
  fVar10 = (float)(*(int *)(param_1 + 0x4c) + 1);
  fStack_20 = fVar9 * fVar8 * fVar10 + fStack_30;
  uStack_28 = CONCAT44(uStack_28._4_4_ * fVar8 * fVar10 + uStack_38._4_4_,
                       (float)uStack_28 * fVar8 * fVar10 + (float)uStack_38);
  pcVar5 = DAT_182ec16a0;
  if ((DAT_182ec16a0 == (code *)0x0) &&
     (pcVar5 = (code *)FUN_1802cf0c0(
                                    "UnityEngine.Transform::set_position_Injected(UnityEngine.Vector3&)"
                                    ), pcVar5 == (code *)0x0)) {
    uVar6 = FUN_1802ced60("UnityEngine.Transform::set_position_Injected(UnityEngine.Vector3&)");
                    /* WARNING: Subroutine does not return */
    FUN_1802cca90(uVar6,0);
  }
  DAT_182ec16a0 = pcVar5;
  (*DAT_182ec16a0)(lVar2,&uStack_28);
  *(undefined4 *)(param_1 + 0x4c) = 0;
  if ((*(longlong *)(param_1 + 0x10) == 0) ||
     (lVar2 = *(longlong *)(*(longlong *)(param_1 + 0x10) + 0x80), lVar2 == 0)) {
code_r0x00018042eb52:
                    /* WARNING: Subroutine does not return */
    FUN_18031dad0();
  }
  pcVar5 = pcRam0000000182ec3a18;
  if ((pcRam0000000182ec3a18 == (code *)0x0) &&
     (pcVar5 = (code *)FUN_1802cf0c0("UnityEngine.CapsuleCollider::get_radius()"),
     pcVar5 == (code *)0x0)) {
    uVar6 = FUN_1802ced60("UnityEngine.CapsuleCollider::get_radius()");
                    /* WARNING: Subroutine does not return */
    FUN_1802cca90(uVar6,0);
  }
  pcRam0000000182ec3a18 = pcVar5;
  fVar9 = (float)(*pcRam0000000182ec3a18)(lVar2);
  *(undefined1 *)(param_1 + 0x28) = 0;
  fVar9 = fVar9 + fVar9;
  if ((*(longlong *)(param_1 + 0x10) == 0) ||
     (lVar2 = *(longlong *)(*(longlong *)(param_1 + 0x10) + 0x40), lVar2 == 0))
  goto code_r0x00018042eb52;
  pfVar1 = (float *)(lVar2 + 0xd8);
  if (*pfVar1 <= fVar9 && fVar9 != *pfVar1) {
code_r0x00018042ea93:
    *(undefined1 *)(param_1 + 0x28) = 1;
  }
  else {
    lVar2 = *(longlong *)(*(longlong *)(param_1 + 0x10) + 0x40);
    if (*(longlong *)(lVar2 + 0x38) != 0) {
      lVar2 = *(longlong *)(*(longlong *)(lVar2 + 0x38) + 0x28);
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
      if (lVar2 != 0) {
        if (*(int *)(DAT_182d53aa8 + 0xe0) == 0) {
          FUN_18035c820();
        }
        if (*(longlong *)(lVar2 + 0x10) != 0) {
          if (((*(longlong *)(param_1 + 0x10) == 0) ||
              (lVar2 = *(longlong *)(*(longlong *)(param_1 + 0x10) + 0x40), lVar2 == 0)) ||
             (lVar2 = *(longlong *)(lVar2 + 0x38), lVar2 == 0)) goto code_r0x00018042eac2;
          lVar2 = *(longlong *)(lVar2 + 0x10);
          lVar3 = *(longlong *)(*(longlong *)(param_1 + 0x10) + 0x10);
          if (*(int *)(DAT_182d58288 + 0xe0) == 0) {
            FUN_18035c820();
          }
          if (lVar2 == 0) goto code_r0x00018042eac2;
          uStack_38 = 0;
          fStack_30 = 0.0;
          pcVar5 = DAT_182ec1698;
          if ((DAT_182ec1698 == (code *)0x0) &&
             (pcVar5 = (code *)FUN_1802cf0c0(
                                            "UnityEngine.Transform::get_position_Injected(UnityEngine.Vector3&)"
                                            ), pcVar5 == (code *)0x0)) {
            uVar6 = FUN_1802ced60(
                                 "UnityEngine.Transform::get_position_Injected(UnityEngine.Vector3&)"
                                 );
                    /* WARNING: Subroutine does not return */
            FUN_1802cca90(uVar6,0);
          }
          DAT_182ec1698 = pcVar5;
          (*DAT_182ec1698)(lVar2,&uStack_38);
          if (lVar3 == 0) goto code_r0x00018042eac2;
          uStack_28 = 0;
          fStack_20 = 0.0;
          pcVar5 = DAT_182ec1698;
          if ((DAT_182ec1698 == (code *)0x0) &&
             (pcVar5 = (code *)FUN_1802cf0c0(
                                            "UnityEngine.Transform::get_position_Injected(UnityEngine.Vector3&)"
                                            ), pcVar5 == (code *)0x0)) {
            uVar6 = FUN_1802ced60(
                                 "UnityEngine.Transform::get_position_Injected(UnityEngine.Vector3&)"
                                 );
                    /* WARNING: Subroutine does not return */
            FUN_1802cca90(uVar6,0);
          }
          DAT_182ec1698 = pcVar5;
          (*DAT_182ec1698)(lVar3,&uStack_28);
          if ((uStack_38._4_4_ - uStack_28._4_4_) * (uStack_38._4_4_ - uStack_28._4_4_) +
              ((float)uStack_38 - (float)uStack_28) * ((float)uStack_38 - (float)uStack_28) +
              (fStack_30 - fStack_20) * (fStack_30 - fStack_20) < fVar9 * fVar9)
          goto code_r0x00018042ea93;
        }
      }
    }
  }
  if (*(char *)(param_1 + 0x28) != '\0') {
    if ((*(longlong *)(param_1 + 0x10) == 0) ||
       (lVar2 = *(longlong *)(*(longlong *)(param_1 + 0x10) + 200), lVar2 == 0)) {
code_r0x00018042eac2:
                    /* WARNING: Subroutine does not return */
      FUN_18031dad0();
    }
    ExposureUnnoticed2_Object3D_NPC_Script_NpcCollisionCorrecter__CollisionCorrect__0600100b
              (lVar2,0);
  }
  return;
}

