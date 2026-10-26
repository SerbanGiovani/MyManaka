// Ghidra pseudocode; not original source or compilable C.
// ev_a33c7cca63231d7aa3e6fb711e0389dc267332de1b059a7b2273d69768246e38

byte ExposureUnnoticed2_Scripts_Mission_MissionStopElevatorNaked__IsInCondition__0600148a
               (longlong *param_1)

{
  float fVar1;
  longlong lVar2;
  longlong lVar3;
  byte bVar4;
  char cVar5;
  uint uVar6;
  longlong lVar7;
  ulonglong uVar8;
  code *pcVar9;
  undefined8 uVar10;
  bool bVar11;
  float fVar12;
  undefined8 uStack_88;
  undefined4 uStack_80;
  undefined8 uStack_78;
  undefined4 uStack_70;
  undefined8 uStack_68;
  undefined4 uStack_60;
  undefined8 uStack_58;
  undefined8 uStack_50;
  undefined8 uStack_48;
  undefined8 uStack_40;
  undefined8 uStack_38;
  undefined8 uStack_30;
  
  if (cRam0000000182eb7938 == '\0') {
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
    cRam0000000182eb7938 = '\x01';
  }
  if ((**(longlong **)(DAT_182d53c48 + 0xb8) == 0) ||
     (lVar2 = *(longlong *)(**(longlong **)(DAT_182d53c48 + 0xb8) + 0x28), lVar2 == 0))
  goto code_r0x0001804809c8;
  lVar2 = *(longlong *)(lVar2 + 0x30);
  if (DAT_182eb54a2 == '\0') {
    FUN_1802f2810(&DAT_182d5bcb8);
    LOCK();
    UNLOCK();
    DAT_182eb54a2 = '\x01';
  }
  if (**(longlong **)(DAT_182d5bcb8 + 0xb8) == 0) goto code_r0x0001804809c8;
  lVar7 = ExposureUnnoticed2_Scripts_InGame_DroppedItemManager__GetDropClothesInSameArea__0600150d
                    (**(longlong **)(DAT_182d5bcb8 + 0xb8),0);
  if (lVar7 == 0) {
    bVar11 = true;
  }
  else {
    if (DAT_182eb5490 == '\0') {
      FUN_1802f2810(&DAT_182d59260);
      LOCK();
      UNLOCK();
      DAT_182eb5490 = '\x01';
    }
    lVar3 = **(longlong **)(DAT_182d59260 + 0xb8);
    if (lVar3 == 0) goto code_r0x0001804809c8;
    uStack_58 = *(undefined8 *)(lVar3 + 0x5c);
    uStack_50 = *(undefined8 *)(lVar3 + 100);
    uStack_48 = *(undefined8 *)(lVar3 + 0x6c);
    uStack_70 = *(undefined4 *)(lVar7 + 0x1c);
    uStack_78 = *(undefined8 *)(lVar7 + 0x14);
    pcVar9 = pcRam0000000182ebfdb8;
    if ((pcRam0000000182ebfdb8 == (code *)0x0) &&
       (pcVar9 = (code *)FUN_1802cf0c0(
                                      "UnityEngine.Bounds::Contains_Injected(UnityEngine.Bounds&,UnityEngine.Vector3&)"
                                      ), pcVar9 == (code *)0x0)) {
      uVar10 = FUN_1802ced60(
                            "UnityEngine.Bounds::Contains_Injected(UnityEngine.Bounds&,UnityEngine.Vector3&)"
                            );
                    /* WARNING: Subroutine does not return */
      FUN_1802cca90(uVar10,0);
    }
    pcRam0000000182ebfdb8 = pcVar9;
    cVar5 = (*pcRam0000000182ebfdb8)(&uStack_58,&uStack_78);
    bVar11 = cVar5 == '\0';
  }
  if ((int)param_1[9] == -1) goto code_r0x00018048070f;
  lVar7 = param_1[0xb];
  if (lVar7 == 0) goto code_r0x0001804809c8;
  if (*(uint *)(lVar7 + 0x18) <= *(uint *)(param_1 + 9)) {
                    /* WARNING: Subroutine does not return */
    FUN_18031dae0();
  }
  if (*(char *)((longlong)(int)*(uint *)(param_1 + 9) + 0x20 + lVar7) != '\0')
  goto code_r0x00018048070f;
  if (**(longlong **)(DAT_182d58230 + 0xb8) == 0) goto code_r0x0001804809c8;
  uVar8 = ExposureUnnoticed2_Object3D_Player_Scripts_PlayerFacade__GetExposedBodyPartsByClothesAndCostume__06000d9f
                    (**(longlong **)(DAT_182d58230 + 0xb8),0);
  if (*(int *)(DAT_182d58288 + 0xe0) == 0) {
    FUN_18035c820();
  }
  if ((uVar8 & 0x20) == 0) {
code_r0x00018048070f:
    bVar4 = 0;
  }
  else {
    lVar7 = FUN_180436630();
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
    if (lVar7 == 0) goto code_r0x00018048070f;
    if (*(int *)(DAT_182d53aa8 + 0xe0) == 0) {
      FUN_18035c820();
    }
    if (*(longlong *)(lVar7 + 0x10) == 0) goto code_r0x00018048070f;
    lVar7 = FUN_180436630();
    if (((lVar2 == 0) || (*(longlong *)(lVar2 + 0x40) == 0)) ||
       (lVar3 = *(longlong *)(*(longlong *)(lVar2 + 0x40) + 0x18), lVar3 == 0))
    goto code_r0x0001804809c8;
    uStack_88 = 0;
    uStack_80 = 0;
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
    (*DAT_182ec1698)(lVar3,&uStack_88);
    if (lVar7 == 0) goto code_r0x0001804809c8;
    uStack_40 = *(undefined8 *)(lVar7 + 0x5c);
    uStack_38 = *(undefined8 *)(lVar7 + 100);
    uStack_30 = *(undefined8 *)(lVar7 + 0x6c);
    uStack_60 = uStack_80;
    uStack_68 = uStack_88;
    pcVar9 = pcRam0000000182ebfdb8;
    if ((pcRam0000000182ebfdb8 == (code *)0x0) &&
       (pcVar9 = (code *)FUN_1802cf0c0(
                                      "UnityEngine.Bounds::Contains_Injected(UnityEngine.Bounds&,UnityEngine.Vector3&)"
                                      ), pcVar9 == (code *)0x0)) {
      uVar10 = FUN_1802ced60(
                            "UnityEngine.Bounds::Contains_Injected(UnityEngine.Bounds&,UnityEngine.Vector3&)"
                            );
                    /* WARNING: Subroutine does not return */
      FUN_1802cca90(uVar10,0);
    }
    pcRam0000000182ebfdb8 = pcVar9;
    bVar4 = (*pcRam0000000182ebfdb8)(&uStack_40,&uStack_68);
  }
  bVar4 = bVar11 & bVar4;
  if (bVar4 == 0) {
    *(undefined4 *)(param_1 + 9) = 0xffffffff;
  }
  fVar1 = *(float *)((longlong)param_1 + 0x4c);
  pcVar9 = DAT_182ec14c0;
  if ((DAT_182ec14c0 == (code *)0x0) &&
     (pcVar9 = (code *)FUN_1802cf0c0("UnityEngine.Time::get_time()"), pcVar9 == (code *)0x0)) {
    uVar10 = FUN_1802ced60("UnityEngine.Time::get_time()");
                    /* WARNING: Subroutine does not return */
    FUN_1802cca90(uVar10,0);
  }
  DAT_182ec14c0 = pcVar9;
  fVar12 = (float)(*DAT_182ec14c0)();
  if (fVar12 < fVar1) {
    bVar4 = 1;
  }
  cVar5 = ExposureUnnoticed2_Scripts_InGame_GameStateFacade__IsActivePassiveSkill__06001525(5,0);
  if (cVar5 != '\0') {
    if (DAT_182eb5490 == '\0') {
      FUN_1802f2810(&DAT_182d59260);
      LOCK();
      UNLOCK();
      DAT_182eb5490 = '\x01';
    }
    lVar7 = **(longlong **)(DAT_182d59260 + 0xb8);
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
    if (lVar7 != 0) {
      if (*(int *)(DAT_182d53aa8 + 0xe0) == 0) {
        FUN_18035c820();
      }
      if (*(longlong *)(lVar7 + 0x10) != 0) {
        if (DAT_182eb5490 == '\0') {
          FUN_1802f2810(&DAT_182d59260);
          LOCK();
          UNLOCK();
          DAT_182eb5490 = '\x01';
        }
        lVar7 = **(longlong **)(DAT_182d59260 + 0xb8);
        if (((lVar2 == 0) || (*(longlong *)(lVar2 + 0x40) == 0)) ||
           (lVar2 = *(longlong *)(*(longlong *)(lVar2 + 0x40) + 0x18), lVar2 == 0)) {
code_r0x0001804809c8:
                    /* WARNING: Subroutine does not return */
          FUN_18031dad0();
        }
        uStack_88 = 0;
        uStack_80 = 0;
        pcVar9 = DAT_182ec1698;
        if ((DAT_182ec1698 == (code *)0x0) &&
           (pcVar9 = (code *)FUN_1802cf0c0(
                                          "UnityEngine.Transform::get_position_Injected(UnityEngine.Vector3&)"
                                          ), pcVar9 == (code *)0x0)) {
          uVar10 = FUN_1802ced60(
                                "UnityEngine.Transform::get_position_Injected(UnityEngine.Vector3&)"
                                );
                    /* WARNING: Subroutine does not return */
          FUN_1802cca90(uVar10,0);
        }
        DAT_182ec1698 = pcVar9;
        (*DAT_182ec1698)(lVar2,&uStack_88);
        if (lVar7 == 0) goto code_r0x0001804809c8;
        uStack_40 = *(undefined8 *)(lVar7 + 0x5c);
        uStack_38 = *(undefined8 *)(lVar7 + 100);
        uStack_30 = *(undefined8 *)(lVar7 + 0x6c);
        uStack_60 = uStack_80;
        uStack_68 = uStack_88;
        pcVar9 = pcRam0000000182ebfdb8;
        if ((pcRam0000000182ebfdb8 == (code *)0x0) &&
           (pcVar9 = (code *)FUN_1802cf0c0(
                                          "UnityEngine.Bounds::Contains_Injected(UnityEngine.Bounds&,UnityEngine.Vector3&)"
                                          ), pcVar9 == (code *)0x0)) {
          uVar10 = FUN_1802ced60(
                                "UnityEngine.Bounds::Contains_Injected(UnityEngine.Bounds&,UnityEngine.Vector3&)"
                                );
                    /* WARNING: Subroutine does not return */
          FUN_1802cca90(uVar10,0);
        }
        pcRam0000000182ebfdb8 = pcVar9;
        cVar5 = (*pcRam0000000182ebfdb8)(&uStack_40,&uStack_68);
        if (cVar5 != '\0') {
          if (**(longlong **)(DAT_182d58230 + 0xb8) == 0) goto code_r0x0001804809c8;
          uVar6 = ExposureUnnoticed2_Object3D_Player_Scripts_PlayerFacade__GetExposedBodyPartsByClothesAndCostume__06000d9f
                            (**(longlong **)(DAT_182d58230 + 0xb8),0);
          if (*(int *)(DAT_182d58288 + 0xe0) == 0) {
            FUN_18035c820();
          }
          if ((uVar6 & 0x20) != 0) {
            return 1;
          }
        }
      }
    }
    if (*(float *)(param_1 + 6) <= 1.0 && *(float *)(param_1 + 6) != 1.0) {
      (**(code **)(*param_1 + 0x238))(param_1,*(undefined8 *)(*param_1 + 0x240));
    }
  }
  return bVar4;
}

