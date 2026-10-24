// Ghidra pseudocode; not original source or compilable C.
// ev_4841d0ebd8ab96602d5590508524f6d9c8a94551fd427e5974ebc956b2999550

void ExposureUnnoticed2_Object3D_Portal_PortalController__OnTriggerEnter__06000bf5
               (longlong param_1,longlong param_2)

{
  undefined4 uVar1;
  int iVar2;
  longlong lVar3;
  char cVar4;
  code *pcVar5;
  longlong lVar6;
  longlong lVar7;
  undefined8 uVar8;
  bool bVar9;
  
  if (cRam0000000182eb8345 == '\0') {
    FUN_1802f2810(0x182d5e258);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d58398);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d53c48);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d594e8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d53aa8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d58378);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5e260);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d6fc50);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d6fc40);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d6fc30);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d6fc20);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d6fc10);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d6fc00);
    LOCK();
    UNLOCK();
    cRam0000000182eb8345 = '\x01';
  }
  if (*(char *)(param_1 + 0x51) != '\0') {
    return;
  }
  if (param_2 == 0) goto code_r0x00018061de37;
  pcVar5 = DAT_182ec1088;
  if ((DAT_182ec1088 == (code *)0x0) &&
     (pcVar5 = (code *)FUN_1802cf0c0("UnityEngine.Component::get_gameObject()"),
     pcVar5 == (code *)0x0)) {
    uVar8 = FUN_1802ced60("UnityEngine.Component::get_gameObject()");
                    /* WARNING: Subroutine does not return */
    FUN_1802cca90(uVar8,0);
  }
  DAT_182ec1088 = pcVar5;
  lVar6 = (*DAT_182ec1088)(param_2);
  if ((**(longlong **)(DAT_182d58378 + 0xb8) == 0) ||
     (lVar7 = *(longlong *)(**(longlong **)(DAT_182d58378 + 0xb8) + 0x40), lVar7 == 0))
  goto code_r0x00018061de37;
  lVar7 = *(longlong *)(lVar7 + 0x28);
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
  if (lVar6 != 0 || lVar7 != 0) {
    if (lVar7 == 0) {
      if (*(int *)(DAT_182d53aa8 + 0xe0) == 0) {
        FUN_18035c820();
      }
      if (lVar6 == 0) goto code_r0x00018061de37;
      bVar9 = *(longlong *)(lVar6 + 0x10) == 0;
    }
    else if (lVar6 == 0) {
      if (*(int *)(DAT_182d53aa8 + 0xe0) == 0) {
        FUN_18035c820();
      }
      bVar9 = *(longlong *)(lVar7 + 0x10) == 0;
    }
    else {
      bVar9 = lVar6 == lVar7;
    }
    if (!bVar9) {
      return;
    }
  }
  if ((**(longlong **)(DAT_182d53c48 + 0xb8) == 0) ||
     (lVar6 = *(longlong *)(**(longlong **)(DAT_182d53c48 + 0xb8) + 0x30), lVar6 == 0))
  goto code_r0x00018061de37;
  if (*(char *)(lVar6 + 0x11) != '\0') {
    return;
  }
  lVar6 = FUN_180436330();
  if (lVar6 == 0) goto code_r0x00018061de37;
  if (*(char *)(lVar6 + 0x10) != '\0') {
    return;
  }
  uVar1 = *(undefined4 *)(param_1 + 0x20);
  *(undefined1 *)(param_1 + 0x51) = 1;
  if (*(int *)(DAT_182d594e8 + 0xe0) == 0) {
    FUN_18035c820();
  }
  lVar6 = ExposureUnnoticed2_Master_Stage_MStage__Get__06001229(uVar1,0);
  if ((((**(longlong **)(DAT_182d58378 + 0xb8) == 0) ||
       (lVar7 = *(longlong *)(**(longlong **)(DAT_182d58378 + 0xb8) + 0x40), lVar7 == 0)) ||
      (lVar7 = *(longlong *)(lVar7 + 0x60), lVar7 == 0)) ||
     (lVar7 = *(longlong *)(lVar7 + 0x48), lVar7 == 0)) goto code_r0x00018061de37;
  iVar2 = *(int *)(lVar7 + 0x18);
  if ((0x272d < iVar2) && (iVar2 < 0x2773)) {
    return;
  }
  lVar7 = FUN_180458b20();
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
  if (lVar7 == 0) {
code_r0x00018061dc18:
    if (((lVar6 == 0) || (**(longlong **)(DAT_182d58378 + 0xb8) == 0)) ||
       ((lVar7 = *(longlong *)(**(longlong **)(DAT_182d58378 + 0xb8) + 0x40), lVar7 == 0 ||
        ((lVar7 = *(longlong *)(lVar7 + 0x60), lVar7 == 0 ||
         (lVar7 = *(longlong *)(lVar7 + 0x128), lVar7 == 0)))))) goto code_r0x00018061de37;
    if (*(int *)(lVar7 + 0x18) < *(int *)(lVar6 + 0x54)) {
      uVar8 = ExposureUnnoticed2_Scripts_Base_Localizer__Trans__060017af
                        (*(undefined8 *)(lVar6 + 0x28),0);
      uVar8 = ExposureUnnoticed2_Scripts_Base_Localizer__Trans__060017b0
                        (uRam0000000182d6fc20,uVar8,0);
      goto code_r0x00018061ddf6;
    }
    lVar6 = *(longlong *)
             (*(longlong *)(*(longlong *)(**(longlong **)(DAT_182d58378 + 0xb8) + 0x40) + 0x60) +
             0x10);
    if (lVar6 == 0) goto code_r0x00018061de37;
    if (*(int *)(lVar6 + 0x30) == -1) {
      if (DAT_182eb54a2 == '\0') {
        FUN_1802f2810(&DAT_182d5bcb8);
        LOCK();
        UNLOCK();
        DAT_182eb54a2 = '\x01';
      }
      if (**(longlong **)(DAT_182d5bcb8 + 0xb8) == 0) goto code_r0x00018061de37;
      lVar6 = ExposureUnnoticed2_Scripts_InGame_DroppedItemManager__GetDropClothesInSameArea__0600150d
                        (**(longlong **)(DAT_182d5bcb8 + 0xb8),0);
      if (lVar6 == 0) {
        lVar6 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
        if (lVar6 == 0) goto code_r0x00018061de37;
        uVar8 = uRam0000000182d6fc00;
        if (*(int *)(lVar6 + 0x10) == 0) goto code_r0x00018061ddef;
      }
    }
    if (**(longlong **)(lRam0000000182d5e258 + 0xb8) == 0) goto code_r0x00018061de37;
    cVar4 = ExposureUnnoticed2_Scripts_InGame_DroneManager__get_IsActiveMission__060014ed
                      (**(longlong **)(lRam0000000182d5e258 + 0xb8),0);
    uVar8 = uRam0000000182d6fc50;
    if (cVar4 == '\0') {
      if ((**(longlong **)(DAT_182d53c48 + 0xb8) == 0) ||
         (lVar6 = *(longlong *)(**(longlong **)(DAT_182d53c48 + 0xb8) + 0x30), lVar6 == 0))
      goto code_r0x00018061de37;
      uVar8 = uRam0000000182d6fc40;
      if (*(char *)(lVar6 + 0x14) == '\0') {
        if (**(longlong **)(lRam0000000182d5e260 + 0xb8) == 0) {
code_r0x00018061de37:
                    /* WARNING: Subroutine does not return */
          FUN_18031dad0();
        }
        uVar8 = uRam0000000182d6fc10;
        if (*(char *)(**(longlong **)(lRam0000000182d5e260 + 0xb8) + 0x10) == '\0') {
          lVar6 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
          if ((lVar6 != 0) &&
             (lVar7 = *(longlong *)(**(longlong **)(DAT_182d53c48 + 0xb8) + 0x60), lVar7 != 0)) {
            ExposureUnnoticed2_Scripts_InGame_StageTransController__TransStageIfInCondition__06001668
                      (lVar7,*(undefined4 *)(lVar6 + 0x10),*(undefined4 *)(param_1 + 0x20),
                       *(undefined4 *)(param_1 + 0x30),0,0);
            return;
          }
          goto code_r0x00018061de37;
        }
      }
    }
  }
  else {
    if (*(int *)(DAT_182d53aa8 + 0xe0) == 0) {
      FUN_18035c820();
    }
    if (*(longlong *)(lVar7 + 0x10) == 0) goto code_r0x00018061dc18;
    lVar7 = FUN_180458b20();
    if (lVar7 == 0) goto code_r0x00018061de37;
    if (cRam0000000182eb7a62 == '\0') {
      FUN_1802f2810(&DAT_182d53aa8);
      LOCK();
      UNLOCK();
      cRam0000000182eb7a62 = '\x01';
    }
    lVar3 = *(longlong *)(lVar7 + 0x38);
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
    if (lVar3 == 0) goto code_r0x00018061dc18;
    if (*(int *)(DAT_182d53aa8 + 0xe0) == 0) {
      FUN_18035c820();
    }
    if (*(longlong *)(lVar3 + 0x10) == 0) goto code_r0x00018061dc18;
    if (*(longlong *)(lVar7 + 0x38) == 0) goto code_r0x00018061de37;
    uVar8 = uRam0000000182d6fc30;
    if (*(int *)(*(longlong *)(lVar7 + 0x38) + 0x4c) == 0) goto code_r0x00018061dc18;
  }
code_r0x00018061ddef:
  uVar8 = ExposureUnnoticed2_Scripts_Base_Localizer__Trans__060017af(uVar8,0);
code_r0x00018061ddf6:
  ExposureUnnoticed2_ObjectUI_InGame_MessagePanel_MessagePanelView__AddMessage__06001b14(uVar8,0,0);
  return;
}

