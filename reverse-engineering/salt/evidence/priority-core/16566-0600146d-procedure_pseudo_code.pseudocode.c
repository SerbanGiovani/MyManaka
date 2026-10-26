// Ghidra pseudocode; not original source or compilable C.
// ev_3aec159ea5664dc167d3b239438fa2a9022c184cbf91f5add7af0444675d1d9f

ulonglong ExposureUnnoticed2_Scripts_Mission_MissionMoveFromClothes__GetAddSatisfy__0600146d
                    (ulonglong param_1)

{
  longlong lVar1;
  code *pcVar2;
  undefined8 uVar3;
  int iVar4;
  longlong in_RCX;
  undefined4 uVar5;
  float fVar6;
  ulonglong extraout_XMM0_Qa;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined8 uStack_38;
  undefined4 uStack_30;
  undefined8 uStack_28;
  undefined4 uStack_20;
  
  if (cRam0000000182eb7929 == '\0') {
    FUN_1802f2810(&DAT_182d58288);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d53c48);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5acd0);
    LOCK();
    UNLOCK();
    param_1 = FUN_1802f2810(0x182d5acc8);
    LOCK();
    UNLOCK();
    cRam0000000182eb7929 = '\x01';
  }
  iVar4 = *(int *)(in_RCX + 0x58) + 1;
  *(int *)(in_RCX + 0x58) = iVar4;
  if ((iVar4 % 10 == 9) && (*(char *)(in_RCX + 0x54) != '\0')) {
    if (DAT_182eb5480 == '\0') {
      param_1 = FUN_1802f2810(&DAT_182d522a8);
      LOCK();
      UNLOCK();
      DAT_182eb5480 = '\x01';
    }
    if (DAT_182eb54a2 == '\0') {
      param_1 = FUN_1802f2810(&DAT_182d5bcb8);
      LOCK();
      UNLOCK();
      DAT_182eb54a2 = '\x01';
    }
    if (**(longlong **)(DAT_182d5bcb8 + 0xb8) == 0) goto code_r0x00018047e868;
    lVar1 = ExposureUnnoticed2_Scripts_InGame_DroppedItemManager__GetDropClothesInSameArea__0600150d
                      (**(longlong **)(DAT_182d5bcb8 + 0xb8),0);
    param_1 = extraout_XMM0_Qa;
    if (lVar1 == 0) {
      if ((**(longlong **)(DAT_182d53c48 + 0xb8) == 0) ||
         (lVar1 = *(longlong *)(**(longlong **)(DAT_182d53c48 + 0xb8) + 0x30), lVar1 == 0))
      goto code_r0x00018047e868;
      if (*(char *)(lVar1 + 0x54) == '\0') goto code_r0x00018047e850;
      lVar1 = *(longlong *)(**(longlong **)(DAT_182d53c48 + 0xb8) + 0x30);
      uVar3 = *(undefined8 *)(lVar1 + 0x58);
      uVar7 = (undefined4)uVar3;
      uVar8 = (undefined4)((ulonglong)uVar3 >> 0x20);
      uVar5 = *(undefined4 *)(lVar1 + 0x60);
      lVar1 = **(longlong **)(DAT_182d53c48 + 0xb8);
    }
    else {
      uVar7 = (undefined4)*(undefined8 *)(lVar1 + 0x14);
      uVar8 = (undefined4)((ulonglong)*(undefined8 *)(lVar1 + 0x14) >> 0x20);
      uVar5 = *(undefined4 *)(lVar1 + 0x1c);
      lVar1 = **(longlong **)(DAT_182d53c48 + 0xb8);
      if (lVar1 == 0) goto code_r0x00018047e868;
    }
    if ((((*(longlong *)(lVar1 + 0x28) == 0) ||
         (lVar1 = *(longlong *)(*(longlong *)(lVar1 + 0x28) + 0x30), lVar1 == 0)) ||
        (lVar1 = *(longlong *)(lVar1 + 0x40), lVar1 == 0)) ||
       (lVar1 = *(longlong *)(lVar1 + 0x18), lVar1 == 0)) {
code_r0x00018047e868:
                    /* WARNING: Subroutine does not return */
      FUN_18031dad0(param_1);
    }
    uStack_38 = 0;
    uStack_30 = 0;
    pcVar2 = DAT_182ec1698;
    if ((DAT_182ec1698 == (code *)0x0) &&
       (pcVar2 = (code *)FUN_1802cf0c0(
                                      "UnityEngine.Transform::get_position_Injected(UnityEngine.Vector3&)"
                                      ), pcVar2 == (code *)0x0)) {
      uVar3 = FUN_1802ced60("UnityEngine.Transform::get_position_Injected(UnityEngine.Vector3&)");
                    /* WARNING: Subroutine does not return */
      FUN_1802cca90(uVar3,0);
    }
    DAT_182ec1698 = pcVar2;
    (*DAT_182ec1698)(lVar1,&uStack_38);
    if (*(int *)(DAT_182d58288 + 0xe0) == 0) {
      FUN_18035c820();
    }
    uStack_28 = uStack_38;
    uStack_20 = uStack_30;
    uStack_38 = CONCAT44(uVar8,uVar7);
    uStack_30 = uVar5;
    fVar6 = (float)ExposureUnnoticed2_Scripts_Base_ExternalMethodManager__CalcPathLength__0600173f
                             (&uStack_38,&uStack_28,0);
    param_1 = 0;
    if (*(float *)(in_RCX + 0x5c) <= fVar6 && fVar6 != *(float *)(in_RCX + 0x5c)) {
      if (*(longlong *)(in_RCX + 0x28) == 0) goto code_r0x00018047e868;
      param_1 = (ulonglong)
                (uint)((fVar6 - *(float *)(in_RCX + 0x5c)) /
                      *(float *)(*(longlong *)(in_RCX + 0x28) + 0x38));
      *(float *)(in_RCX + 0x5c) = fVar6;
    }
    *(float *)(in_RCX + 0x60) = fVar6;
  }
  else {
code_r0x00018047e850:
    param_1 = 0;
  }
  return param_1;
}

