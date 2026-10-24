// Ghidra pseudocode; not original source or compilable C.
// ev_48fa3b26538eafc8605d7dfaa012f547bf80b308d37fe8101ba7171af86e7f01

void ExposureUnnoticed2_Object3D_Player_Scripts_PlayerFootStepController__OnFootStep__06000dbf
               (longlong param_1,longlong param_2)

{
  longlong *plVar1;
  longlong lVar2;
  longlong lVar3;
  bool bVar4;
  int iVar5;
  undefined4 uVar6;
  longlong *plVar7;
  bool bVar8;
  bool bVar9;
  float fVar10;
  float fVar11;
  
  if (cRam0000000182eb840c == '\0') {
    FUN_1802f2810(0x182d583c0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d3efb0);
    LOCK();
    UNLOCK();
    cRam0000000182eb840c = '\x01';
  }
  if (param_2 == 0) goto code_r0x00018064e0ed;
  plVar1 = *(longlong **)(param_2 + 0x28);
  plVar7 = (longlong *)0x0;
  bVar9 = false;
  if (plVar1 != (longlong *)0x0) {
    if ((*(byte *)(*plVar1 + 0x130) < *(byte *)(lRam0000000182d3efb0 + 0x130)) ||
       (plVar7 = plVar1,
       *(longlong *)
        (*(longlong *)(*plVar1 + 200) + -8 + (ulonglong)*(byte *)(lRam0000000182d3efb0 + 0x130) * 8)
       != lRam0000000182d3efb0)) {
                    /* WARNING: Subroutine does not return */
      FUN_18031e210(plVar1);
    }
  }
  lVar2 = *(longlong *)(param_1 + 0x10);
  if ((lVar2 == 0) || (lVar3 = *(longlong *)(lVar2 + 0x60), lVar3 == 0)) goto code_r0x00018064e0ed;
  bVar8 = false;
  if ((*(char *)(lVar3 + 0x1b) == '\0') &&
     ((*(char *)(lVar3 + 0x120) == '\0' && (*(char *)(lVar3 + 0x1a) != '\0')))) {
    lVar2 = *(longlong *)(lVar2 + 0x48);
    if ((lVar2 == 0) || ((*(longlong *)(lVar2 + 0x88) == 0 || (*(longlong *)(lVar2 + 0x90) == 0))))
    goto code_r0x00018064e0ed;
    fVar10 = (float)func_0x00018039e2b0(*(undefined4 *)(*(longlong *)(lVar2 + 0x88) + 0x10),
                                        *(undefined4 *)(*(longlong *)(lVar2 + 0x90) + 0x10));
    fVar11 = ABS(fVar10 * 57.29578);
    bVar4 = 0.0 <= fVar10 * 57.29578;
    if (fVar11 <= 22.5) {
      iVar5 = 0;
    }
    else if (fVar11 <= 67.5) {
      iVar5 = bVar4 + 4;
    }
    else if (fVar11 <= 112.5) {
      iVar5 = bVar4 + 2;
    }
    else if (fVar11 <= 157.5) {
      iVar5 = bVar4 + 6;
    }
    else {
      iVar5 = 1;
    }
    if (plVar7 == (longlong *)0x0) goto code_r0x00018064e0ed;
    if (iVar5 != *(int *)((longlong)plVar7 + 0x1c)) {
      return;
    }
  }
  lVar2 = *(longlong *)(*(longlong *)(*(longlong *)(param_1 + 0x10) + 0x60) + 0x48);
  if (lVar2 == 0) goto code_r0x00018064e0ed;
  if ((*(char *)(lVar2 + 0x1c) != '\0') &&
     (*(float *)(*(longlong *)(*(longlong *)(*(longlong *)(param_1 + 0x10) + 0x60) + 0x48) + 100) !=
      0.0)) {
    if (plVar7 == (longlong *)0x0) goto code_r0x00018064e0ed;
    if ((char)plVar7[4] == '\0') {
      return;
    }
  }
  lVar2 = *(longlong *)(*(longlong *)(param_1 + 0x10) + 0x60);
  if (*(longlong *)(lVar2 + 0x118) != 0) {
    iVar5 = FUN_180002c20(1,uRam0000000182d583c0,*(undefined8 *)(lVar2 + 0x118));
    bVar8 = iVar5 == 1;
  }
  if ((*(longlong *)(param_1 + 0x10) == 0) ||
     (lVar2 = *(longlong *)(*(longlong *)(param_1 + 0x10) + 0x60), lVar2 == 0))
  goto code_r0x00018064e0ed;
  if (*(longlong *)(lVar2 + 0x118) != 0) {
    iVar5 = FUN_180002c20(1,uRam0000000182d583c0,
                          *(undefined8 *)
                           (*(longlong *)(*(longlong *)(param_1 + 0x10) + 0x60) + 0x118));
    bVar9 = iVar5 == 2;
  }
  if (((plVar7 == (longlong *)0x0) || (*(longlong *)(param_1 + 0x10) == 0)) ||
     (lVar2 = *(longlong *)(*(longlong *)(param_1 + 0x10) + 0x60), lVar2 == 0))
  goto code_r0x00018064e0ed;
  if (*(char *)(lVar2 + 0x1b) == '\0') {
    if (bVar8) {
      uVar6 = (undefined4)plVar7[3];
    }
    else {
      if (!bVar9) goto code_r0x00018064e06f;
      uVar6 = 0x5f;
      if (*(char *)(lVar2 + 0x19) == '\0') {
        uVar6 = 0x1f;
      }
    }
  }
  else {
code_r0x00018064e06f:
    uVar6 = 0x1e;
  }
  lVar2 = *(longlong *)(*(longlong *)(param_1 + 0x10) + 0xb0);
  if (lVar2 == 0) {
code_r0x00018064e0ed:
                    /* WARNING: Subroutine does not return */
    FUN_18031dad0();
  }
  ExposureUnnoticed2_Object3D_Player_Scripts_PlayerSoundManager__PlaySe__06000e21(lVar2,uVar6,0);
  if (bVar8) {
    if ((*(longlong *)(param_1 + 0x10) == 0) ||
       (lVar2 = *(longlong *)(*(longlong *)(param_1 + 0x10) + 0x60), lVar2 == 0))
    goto code_r0x00018064e0ed;
    if (*(char *)(lVar2 + 0x1b) == '\0') {
      if (*(char *)(lVar2 + 0x19) == '\0') {
        fVar10 = 0.201;
      }
      else {
        fVar10 = 0.301;
      }
      *(float *)(param_1 + 0x1c) = fVar10;
      *(float *)(param_1 + 0x18) = fVar10 + 0.1;
    }
  }
  return;
}

