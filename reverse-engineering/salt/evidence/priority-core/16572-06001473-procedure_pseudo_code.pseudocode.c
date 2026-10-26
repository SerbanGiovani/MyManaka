// Ghidra pseudocode; not original source or compilable C.
// ev_7008b741f7acd4c59c4bafcdfc9967253406ecdb55a36ec6a678aaf28fdc6aa7

ulonglong ExposureUnnoticed2_Scripts_Mission_MissionMoveFromClothesInArea__IsRpPerSecCondition__06001473
                    (longlong *param_1)

{
  longlong lVar1;
  longlong lVar2;
  code *pcVar3;
  ulonglong uVar4;
  undefined8 uVar5;
  int iVar6;
  undefined4 uVar7;
  undefined8 uStack_38;
  undefined4 uStack_30;
  undefined8 uStack_28;
  undefined4 uStack_20;
  
  if (cRam0000000182eb792d == '\0') {
    FUN_1802f2810(&DAT_182d58288);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d53c48);
    LOCK();
    UNLOCK();
    cRam0000000182eb792d = '\x01';
  }
  iVar6 = (int)param_1[0xb] + 1;
  *(int *)(param_1 + 0xb) = iVar6;
  if (iVar6 % 10 == 9) {
    if (DAT_182eb54a2 == '\0') {
      FUN_1802f2810(&DAT_182d5bcb8);
      LOCK();
      UNLOCK();
      DAT_182eb54a2 = '\x01';
    }
    if (**(longlong **)(DAT_182d5bcb8 + 0xb8) == 0) goto code_r0x00018047f1a3;
    lVar2 = ExposureUnnoticed2_Scripts_InGame_DroppedItemManager__GetDropClothesInSameArea__0600150d
                      (**(longlong **)(DAT_182d5bcb8 + 0xb8),0);
    uVar4 = 0;
    if (lVar2 == 0) goto code_r0x00018047f175;
    if ((**(longlong **)(DAT_182d53c48 + 0xb8) == 0) ||
       (lVar1 = *(longlong *)(**(longlong **)(DAT_182d53c48 + 0xb8) + 0x28), lVar1 == 0))
    goto code_r0x00018047f1a3;
    uVar5 = *(undefined8 *)(lVar2 + 0x14);
    uVar7 = *(undefined4 *)(lVar2 + 0x1c);
    lVar2 = *(longlong *)(lVar1 + 0x30);
    if ((lVar2 == 0) ||
       ((lVar2 = *(longlong *)(lVar2 + 0x40), lVar2 == 0 ||
        (lVar2 = *(longlong *)(lVar2 + 0x18), lVar2 == 0)))) goto code_r0x00018047f1a3;
    uStack_38 = 0;
    uStack_30 = 0;
    pcVar3 = DAT_182ec1698;
    if ((DAT_182ec1698 == (code *)0x0) &&
       (pcVar3 = (code *)FUN_1802cf0c0(
                                      "UnityEngine.Transform::get_position_Injected(UnityEngine.Vector3&)"
                                      ), pcVar3 == (code *)0x0)) {
      uVar5 = FUN_1802ced60("UnityEngine.Transform::get_position_Injected(UnityEngine.Vector3&)");
                    /* WARNING: Subroutine does not return */
      FUN_1802cca90(uVar5,0);
    }
    DAT_182ec1698 = pcVar3;
    (*DAT_182ec1698)(lVar2,&uStack_38);
    if (*(int *)(DAT_182d58288 + 0xe0) == 0) {
      FUN_18035c820();
    }
    uStack_28 = uStack_38;
    uStack_20 = uStack_30;
    uStack_38 = uVar5;
    uStack_30 = uVar7;
    uVar7 = ExposureUnnoticed2_Scripts_Base_ExternalMethodManager__CalcPathLength__0600173f
                      (&uStack_38,&uStack_28,0);
    *(undefined4 *)(param_1 + 0xc) = uVar7;
  }
  uVar4 = (**(code **)(*param_1 + 0x1d8))(param_1,*(undefined8 *)(*param_1 + 0x1e0));
  if ((char)uVar4 != '\0') {
    lVar2 = param_1[5];
    if (lVar2 != 0) {
      return CONCAT71((int7)((ulonglong)lVar2 >> 8),
                      *(float *)(lVar2 + 0x38) <= *(float *)(param_1 + 0xc));
    }
code_r0x00018047f1a3:
                    /* WARNING: Subroutine does not return */
    FUN_18031dad0();
  }
code_r0x00018047f175:
  return uVar4 & 0xffffffffffffff00;
}

