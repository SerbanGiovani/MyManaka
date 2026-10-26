// Ghidra pseudocode; not original source or compilable C.
// ev_e2f3dcb802c1ff0fc57f21739a8d4a37570ca2ffea33b4e0e752bca5d4c71b4b

byte ExposureUnnoticed2_Scripts_Mission_MissionElevatorMoveWithOutsideClothes__IsInCondition__0600143a
               (longlong param_1)

{
  longlong lVar1;
  longlong lVar2;
  char cVar3;
  byte bVar4;
  byte bVar5;
  longlong lVar6;
  ulonglong uVar7;
  code *pcVar8;
  undefined8 uVar9;
  bool bVar10;
  undefined8 uStack_58;
  undefined4 uStack_50;
  undefined8 uStack_48;
  undefined8 uStack_40;
  undefined8 uStack_38;
  undefined8 uStack_28;
  undefined8 uStack_20;
  undefined8 uStack_18;
  
  if (cRam0000000182eb7908 == '\0') {
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
    cRam0000000182eb7908 = '\x01';
  }
  if ((**(longlong **)(DAT_182d53c48 + 0xb8) == 0) ||
     (lVar1 = *(longlong *)(**(longlong **)(DAT_182d53c48 + 0xb8) + 0x28), lVar1 == 0))
  goto code_r0x00018047a9e3;
  lVar1 = *(longlong *)(lVar1 + 0x30);
  if (DAT_182eb54a2 == '\0') {
    FUN_1802f2810(&DAT_182d5bcb8);
    LOCK();
    UNLOCK();
    DAT_182eb54a2 = '\x01';
  }
  if (**(longlong **)(DAT_182d5bcb8 + 0xb8) == 0) goto code_r0x00018047a9e3;
  lVar6 = ExposureUnnoticed2_Scripts_InGame_DroppedItemManager__GetDropClothesInSameArea__0600150d
                    (**(longlong **)(DAT_182d5bcb8 + 0xb8),0);
  if (lVar6 == 0) {
    bVar10 = true;
  }
  else {
    if (DAT_182eb5490 == '\0') {
      FUN_1802f2810(&DAT_182d59260);
      LOCK();
      UNLOCK();
      DAT_182eb5490 = '\x01';
    }
    lVar2 = **(longlong **)(DAT_182d59260 + 0xb8);
    if (lVar2 == 0) goto code_r0x00018047a9e3;
    uStack_48 = *(undefined8 *)(lVar2 + 0x5c);
    uStack_40 = *(undefined8 *)(lVar2 + 100);
    uStack_38 = *(undefined8 *)(lVar2 + 0x6c);
    uStack_50 = *(undefined4 *)(lVar6 + 0x1c);
    uStack_58 = *(undefined8 *)(lVar6 + 0x14);
    pcVar8 = pcRam0000000182ebfdb8;
    if ((pcRam0000000182ebfdb8 == (code *)0x0) &&
       (pcVar8 = (code *)FUN_1802cf0c0(
                                      "UnityEngine.Bounds::Contains_Injected(UnityEngine.Bounds&,UnityEngine.Vector3&)"
                                      ), pcVar8 == (code *)0x0)) {
      uVar9 = FUN_1802ced60(
                           "UnityEngine.Bounds::Contains_Injected(UnityEngine.Bounds&,UnityEngine.Vector3&)"
                           );
                    /* WARNING: Subroutine does not return */
      FUN_1802cca90(uVar9,0);
    }
    pcRam0000000182ebfdb8 = pcVar8;
    cVar3 = (*pcRam0000000182ebfdb8)(&uStack_48,&uStack_58);
    bVar10 = cVar3 == '\0';
  }
  if (**(longlong **)(DAT_182d58230 + 0xb8) == 0) goto code_r0x00018047a9e3;
  uVar7 = ExposureUnnoticed2_Object3D_Player_Scripts_PlayerFacade__GetExposedBodyPartsByClothesAndCostume__06000d9f
                    (**(longlong **)(DAT_182d58230 + 0xb8),0);
  if (*(int *)(DAT_182d58288 + 0xe0) == 0) {
    FUN_18035c820();
  }
  if ((uVar7 & 0x20) == 0) {
code_r0x00018047a929:
    bVar4 = 0;
  }
  else {
    if (DAT_182eb5490 == '\0') {
      FUN_1802f2810(&DAT_182d59260);
      LOCK();
      UNLOCK();
      DAT_182eb5490 = '\x01';
    }
    lVar6 = **(longlong **)(DAT_182d59260 + 0xb8);
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
    if (lVar6 == 0) goto code_r0x00018047a929;
    if (*(int *)(DAT_182d53aa8 + 0xe0) == 0) {
      FUN_18035c820();
    }
    if (*(longlong *)(lVar6 + 0x10) == 0) goto code_r0x00018047a929;
    if (DAT_182eb5490 == '\0') {
      FUN_1802f2810(&DAT_182d59260);
      LOCK();
      UNLOCK();
      DAT_182eb5490 = '\x01';
    }
    lVar6 = **(longlong **)(DAT_182d59260 + 0xb8);
    if (((lVar1 == 0) || (*(longlong *)(lVar1 + 0x40) == 0)) ||
       (lVar2 = *(longlong *)(*(longlong *)(lVar1 + 0x40) + 0x18), lVar2 == 0))
    goto code_r0x00018047a9e3;
    uStack_58 = 0;
    uStack_50 = 0;
    pcVar8 = DAT_182ec1698;
    if ((DAT_182ec1698 == (code *)0x0) &&
       (pcVar8 = (code *)FUN_1802cf0c0(
                                      "UnityEngine.Transform::get_position_Injected(UnityEngine.Vector3&)"
                                      ), pcVar8 == (code *)0x0)) {
      uVar9 = FUN_1802ced60("UnityEngine.Transform::get_position_Injected(UnityEngine.Vector3&)");
                    /* WARNING: Subroutine does not return */
      FUN_1802cca90(uVar9,0);
    }
    DAT_182ec1698 = pcVar8;
    (*DAT_182ec1698)(lVar2,&uStack_58);
    if (lVar6 == 0) goto code_r0x00018047a9e3;
    uStack_28 = *(undefined8 *)(lVar6 + 0x5c);
    uStack_20 = *(undefined8 *)(lVar6 + 100);
    uStack_18 = *(undefined8 *)(lVar6 + 0x6c);
    uStack_40 = CONCAT44(uStack_40._4_4_,uStack_50);
    uStack_48 = uStack_58;
    pcVar8 = pcRam0000000182ebfdb8;
    if ((pcRam0000000182ebfdb8 == (code *)0x0) &&
       (pcVar8 = (code *)FUN_1802cf0c0(
                                      "UnityEngine.Bounds::Contains_Injected(UnityEngine.Bounds&,UnityEngine.Vector3&)"
                                      ), pcVar8 == (code *)0x0)) {
      uVar9 = FUN_1802ced60(
                           "UnityEngine.Bounds::Contains_Injected(UnityEngine.Bounds&,UnityEngine.Vector3&)"
                           );
                    /* WARNING: Subroutine does not return */
      FUN_1802cca90(uVar9,0);
    }
    pcRam0000000182ebfdb8 = pcVar8;
    bVar4 = (*pcRam0000000182ebfdb8)(&uStack_28,&uStack_48);
  }
  bVar4 = bVar10 & bVar4;
  bVar5 = 0;
  if (*(char *)(param_1 + 0x54) == '\0') {
    bVar5 = bVar4;
  }
  if (bVar5 != 0) {
    if (((lVar1 == 0) || (*(longlong *)(lVar1 + 0x40) == 0)) ||
       (lVar1 = *(longlong *)(*(longlong *)(lVar1 + 0x40) + 0x18), lVar1 == 0)) {
code_r0x00018047a9e3:
                    /* WARNING: Subroutine does not return */
      FUN_18031dad0();
    }
    uStack_58 = 0;
    uStack_50 = 0;
    pcVar8 = DAT_182ec1698;
    if ((DAT_182ec1698 == (code *)0x0) &&
       (pcVar8 = (code *)FUN_1802cf0c0(
                                      "UnityEngine.Transform::get_position_Injected(UnityEngine.Vector3&)"
                                      ), pcVar8 == (code *)0x0)) {
      uVar9 = FUN_1802ced60("UnityEngine.Transform::get_position_Injected(UnityEngine.Vector3&)");
                    /* WARNING: Subroutine does not return */
      FUN_1802cca90(uVar9,0);
    }
    DAT_182ec1698 = pcVar8;
    (*DAT_182ec1698)(lVar1,&uStack_58);
    *(undefined8 *)(param_1 + 0x48) = uStack_58;
    *(undefined4 *)(param_1 + 0x50) = uStack_50;
    *(undefined4 *)(param_1 + 0x58) = 0;
  }
  *(byte *)(param_1 + 0x54) = bVar4;
  return bVar4;
}

