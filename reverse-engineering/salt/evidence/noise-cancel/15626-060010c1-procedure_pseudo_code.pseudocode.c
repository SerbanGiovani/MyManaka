// Ghidra pseudocode; not original source or compilable C.
// ev_3889ecf006966bc8627169a51acdf18200b12b166467c3483c28de304aa0b53b

void ExposureUnnoticed2_Object3D_NPC_Script_NpcStrangenessManager__OnPlayerSound__060010c1
               (longlong param_1,longlong param_2)

{
  int iVar1;
  longlong lVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  
  if (cRam0000000182eb778a == '\0') {
    FUN_1802f2810(&DAT_182d58288);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d53c48);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d58378);
    LOCK();
    UNLOCK();
    cRam0000000182eb778a = '\x01';
  }
  if ((*(longlong *)(param_1 + 0x28) == 0) ||
     (lVar2 = *(longlong *)(*(longlong *)(param_1 + 0x28) + 0x40), lVar2 == 0))
  goto code_r0x0001804362b7;
  if (*(int *)(lVar2 + 0x10) == 7) {
    return;
  }
  if (*(char *)(lVar2 + 0x54) != '\0') {
    return;
  }
  if (*(char *)(lVar2 + 0x84) != '\0') {
    return;
  }
  if (0.0 < *(float *)(lVar2 + 0x24)) {
    return;
  }
  if (*(longlong *)(param_1 + 0x18) == 0) goto code_r0x0001804362b7;
  if (*(char *)(*(longlong *)(param_1 + 0x18) + 0x68) != '\0') {
    return;
  }
  if ((**(longlong **)(DAT_182d53c48 + 0xb8) == 0) ||
     (lVar2 = *(longlong *)(**(longlong **)(DAT_182d53c48 + 0xb8) + 0x30), lVar2 == 0))
  goto code_r0x0001804362b7;
  if (*(char *)(lVar2 + 0x11) != '\0') {
    return;
  }
  if (*(longlong *)(param_1 + 0x10) == 0) goto code_r0x0001804362b7;
  if (*(float *)(*(longlong *)(*(longlong *)(param_1 + 0x28) + 0x40) + 0xcc) <=
      *(float *)(*(longlong *)(param_1 + 0x10) + 0x14)) {
    return;
  }
  if (*(longlong *)(param_1 + 0x20) == 0) goto code_r0x0001804362b7;
  uVar4 = ExposureUnnoticed2_Scripts_InGame_Util_ColliderTriggerController__get_CenterObject__0600169c
                    (*(longlong *)(param_1 + 0x20),0);
  if (*(longlong *)(param_1 + 0x28) == 0) goto code_r0x0001804362b7;
  uVar3 = *(undefined8 *)(*(longlong *)(param_1 + 0x28) + 0x18);
  if (*(int *)(DAT_182d58288 + 0xe0) == 0) {
    FUN_18035c820();
  }
  fVar5 = (float)ExposureUnnoticed2_Scripts_Base_ExternalMethodManager__DistSqrt__06001726
                           (uVar4,uVar3,0);
  fVar6 = (float)ExposureUnnoticed2_Object3D_NPC_Script_NpcStrangenessManager__CalcCommonAddScale__060010bf
                           (param_1,0);
  fVar5 = (2.0 - fVar5) * 0.5;
  if (fVar5 < 0.0) {
    fVar5 = 0.0;
  }
  else if (1.0 < fVar5) {
    fVar5 = 1.0;
  }
  if (fVar5 * fVar6 <= 0.0) {
    return;
  }
  fVar9 = 0.0;
  if (((**(longlong **)(DAT_182d58378 + 0xb8) == 0) ||
      (lVar2 = *(longlong *)(**(longlong **)(DAT_182d58378 + 0xb8) + 0x40), lVar2 == 0)) ||
     (lVar2 = *(longlong *)(lVar2 + 0x60), lVar2 == 0)) goto code_r0x0001804362b7;
  fVar7 = (float)*(int *)(lVar2 + 0xe0) * 0.01 + 1.0;
  fVar8 = 0.0;
  if (0.0 <= fVar7) {
    fVar8 = fVar7;
  }
  if (param_2 == 0) goto code_r0x0001804362b7;
  iVar1 = *(int *)(param_2 + 0x10);
  if (iVar1 < 0x1f) {
    switch(iVar1) {
    case 1:
    case 2:
    case 6:
      goto code_r0x0001804361fc;
    case 3:
    case 4:
    case 5:
      break;
    case 7:
    case 8:
      fVar9 = 0.1;
      break;
    default:
      if (iVar1 == 0x1e) {
        fVar9 = fVar8 * 0.02;
      }
    }
  }
  else if (iVar1 == 0x1f) {
code_r0x0001804361fc:
    fVar9 = fVar8 * 0.05;
  }
  else if (iVar1 == 0x2c) {
    fVar9 = 0.1;
    if (*(char *)(param_2 + 0x14) != '\0') {
      fVar9 = 0.02;
    }
  }
  else if (iVar1 == 0x5f) goto code_r0x0001804361fc;
  if ((*(longlong *)(param_1 + 0x28) != 0) &&
     (lVar2 = *(longlong *)(*(longlong *)(param_1 + 0x28) + 0x40), lVar2 != 0)) {
    *(undefined1 *)(lVar2 + 0x30) = 0;
    if ((*(longlong *)(param_1 + 0x28) != 0) &&
       ((lVar2 = *(longlong *)(*(longlong *)(param_1 + 0x28) + 0x40), lVar2 != 0 &&
        (*(longlong *)(param_1 + 0x10) != 0)))) {
      fVar8 = *(float *)(lVar2 + 0xcc) - *(float *)(*(longlong *)(param_1 + 0x10) + 0x14);
      fVar9 = fVar9 * fVar5 * fVar6;
      if (fVar8 <= fVar9) {
        fVar9 = fVar8;
      }
      if (fVar9 < 0.0) {
        fVar9 = 0.0;
      }
      else if (1.0 < fVar9) {
        fVar9 = 1.0;
      }
      *(float *)(param_1 + 0x30) = fVar9;
      return;
    }
  }
code_r0x0001804362b7:
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

