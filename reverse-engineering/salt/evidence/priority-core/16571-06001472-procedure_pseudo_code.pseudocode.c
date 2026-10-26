// Ghidra pseudocode; not original source or compilable C.
// ev_1b96044c1569076ca92a0619948310b0376620674d5d1492329597401cfc3530

ulonglong ExposureUnnoticed2_Scripts_Mission_MissionMoveFromClothesInArea__GetAddSatisfy__06001472
                    (ulonglong param_1)

{
  undefined4 uVar1;
  longlong lVar2;
  longlong lVar3;
  code *pcVar4;
  undefined8 uVar5;
  int iVar6;
  longlong in_RCX;
  float fVar7;
  ulonglong extraout_XMM0_Qa;
  undefined8 uStack_38;
  undefined4 uStack_30;
  undefined8 uStack_28;
  undefined4 uStack_20;
  
  if (cRam0000000182eb792c == '\0') {
    FUN_1802f2810(&DAT_182d58288);
    LOCK();
    UNLOCK();
    param_1 = FUN_1802f2810(&DAT_182d53c48);
    LOCK();
    UNLOCK();
    cRam0000000182eb792c = '\x01';
  }
  iVar6 = *(int *)(in_RCX + 0x58) + 1;
  *(int *)(in_RCX + 0x58) = iVar6;
  if ((iVar6 % 10 != 9) || (*(char *)(in_RCX + 0x54) == '\0')) {
    return 0;
  }
  if (DAT_182eb54a2 == '\0') {
    param_1 = FUN_1802f2810(&DAT_182d5bcb8);
    LOCK();
    UNLOCK();
    DAT_182eb54a2 = '\x01';
  }
  if (**(longlong **)(DAT_182d5bcb8 + 0xb8) != 0) {
    lVar3 = ExposureUnnoticed2_Scripts_InGame_DroppedItemManager__GetDropClothesInSameArea__0600150d
                      (**(longlong **)(DAT_182d5bcb8 + 0xb8),0);
    if (lVar3 == 0) {
      return 0;
    }
    param_1 = extraout_XMM0_Qa;
    if ((**(longlong **)(DAT_182d53c48 + 0xb8) != 0) &&
       (lVar2 = *(longlong *)(**(longlong **)(DAT_182d53c48 + 0xb8) + 0x28), lVar2 != 0)) {
      uVar5 = *(undefined8 *)(lVar3 + 0x14);
      uVar1 = *(undefined4 *)(lVar3 + 0x1c);
      lVar3 = *(longlong *)(lVar2 + 0x30);
      if ((lVar3 != 0) &&
         ((lVar3 = *(longlong *)(lVar3 + 0x40), lVar3 != 0 &&
          (lVar3 = *(longlong *)(lVar3 + 0x18), lVar3 != 0)))) {
        uStack_38 = 0;
        uStack_30 = 0;
        pcVar4 = DAT_182ec1698;
        if ((DAT_182ec1698 == (code *)0x0) &&
           (pcVar4 = (code *)FUN_1802cf0c0(
                                          "UnityEngine.Transform::get_position_Injected(UnityEngine.Vector3&)"
                                          ), pcVar4 == (code *)0x0)) {
          uVar5 = FUN_1802ced60("UnityEngine.Transform::get_position_Injected(UnityEngine.Vector3&)"
                               );
                    /* WARNING: Subroutine does not return */
          FUN_1802cca90(uVar5,0);
        }
        DAT_182ec1698 = pcVar4;
        (*DAT_182ec1698)(lVar3,&uStack_38);
        if (*(int *)(DAT_182d58288 + 0xe0) == 0) {
          FUN_18035c820();
        }
        uStack_28 = uStack_38;
        uStack_20 = uStack_30;
        uStack_38 = uVar5;
        uStack_30 = uVar1;
        fVar7 = (float)ExposureUnnoticed2_Scripts_Base_ExternalMethodManager__CalcPathLength__0600173f
                                 (&uStack_38,&uStack_28,0);
        param_1 = 0;
        if (*(float *)(in_RCX + 0x5c) <= fVar7 && fVar7 != *(float *)(in_RCX + 0x5c)) {
          if (*(longlong *)(in_RCX + 0x28) == 0) goto code_r0x00018047efad;
          param_1 = (ulonglong)
                    (uint)((fVar7 - *(float *)(in_RCX + 0x5c)) /
                          *(float *)(*(longlong *)(in_RCX + 0x28) + 0x38));
          *(float *)(in_RCX + 0x5c) = fVar7;
        }
        *(float *)(in_RCX + 0x60) = fVar7;
        return param_1;
      }
    }
  }
code_r0x00018047efad:
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0(param_1);
}

