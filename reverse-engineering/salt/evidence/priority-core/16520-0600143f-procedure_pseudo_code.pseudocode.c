// Ghidra pseudocode; not original source or compilable C.
// ev_ea7ca3df68cced28b99975cb68fcaddcd6206f8cb5164eabdcf0c19dd0ad2434

char ExposureUnnoticed2_Scripts_Mission_MissionEscalatorMove__IsInCondition__0600143f
               (longlong param_1)

{
  uint uVar1;
  longlong lVar2;
  longlong lVar3;
  char cVar4;
  char cVar5;
  uint uVar6;
  code *pcVar7;
  undefined8 uVar8;
  undefined8 uStack_18;
  undefined4 uStack_10;
  
  if (cRam0000000182eb790b == '\0') {
    FUN_1802f2810(&DAT_182d58288);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d53c48);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d53aa8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d58378);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d58230);
    LOCK();
    UNLOCK();
    cRam0000000182eb790b = '\x01';
  }
  if ((**(longlong **)(DAT_182d53c48 + 0xb8) == 0) ||
     (lVar2 = *(longlong *)(**(longlong **)(DAT_182d53c48 + 0xb8) + 0x28), lVar2 == 0))
  goto code_r0x00018047afb3;
  lVar2 = *(longlong *)(lVar2 + 0x30);
  if (**(longlong **)(DAT_182d58230 + 0xb8) == 0) goto code_r0x00018047afb3;
  uVar6 = ExposureUnnoticed2_Object3D_Player_Scripts_PlayerFacade__GetExposedBodyPartsByClothesAndCostume__06000d9f
                    (**(longlong **)(DAT_182d58230 + 0xb8),0);
  if ((*(longlong *)(param_1 + 0x28) == 0) ||
     (lVar3 = *(longlong *)(*(longlong *)(param_1 + 0x28) + 0x20), lVar3 == 0))
  goto code_r0x00018047afb3;
  uVar1 = *(uint *)(lVar3 + 0x34);
  if (*(int *)(DAT_182d58288 + 0xe0) == 0) {
    FUN_18035c820();
  }
  if ((uVar6 & uVar1) == 0) {
code_r0x00018047af1e:
    cVar4 = '\0';
  }
  else {
    if (cRam0000000182eb54a0 == '\0') {
      FUN_1802f2810(0x182d5bca8);
      LOCK();
      UNLOCK();
      cRam0000000182eb54a0 = '\x01';
    }
    lVar3 = **(longlong **)(lRam0000000182d5bca8 + 0xb8);
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
    if (lVar3 == 0) goto code_r0x00018047af1e;
    if (*(int *)(DAT_182d53aa8 + 0xe0) == 0) {
      FUN_18035c820();
    }
    if (*(longlong *)(lVar3 + 0x10) == 0) goto code_r0x00018047af1e;
    if (cRam0000000182eb54a0 == '\0') {
      FUN_1802f2810(0x182d5bca8);
      LOCK();
      UNLOCK();
      cRam0000000182eb54a0 = '\x01';
    }
    if (((**(longlong **)(DAT_182d58378 + 0xb8) == 0) ||
        (lVar3 = *(longlong *)(**(longlong **)(DAT_182d58378 + 0xb8) + 0x40), lVar3 == 0)) ||
       (**(longlong **)(lRam0000000182d5bca8 + 0xb8) == 0)) goto code_r0x00018047afb3;
    cVar4 = ExposureUnnoticed2_Object3D_ScenePlops_Escalator_EscalatorManager__IsPushed__06000ab4
                      (**(longlong **)(lRam0000000182d5bca8 + 0xb8),*(undefined8 *)(lVar3 + 0x28),0)
    ;
  }
  cVar5 = '\0';
  if (*(char *)(param_1 + 0x54) == '\0') {
    cVar5 = cVar4;
  }
  if (cVar5 != '\0') {
    if (((lVar2 == 0) || (lVar2 = *(longlong *)(lVar2 + 0x40), lVar2 == 0)) ||
       (lVar2 = *(longlong *)(lVar2 + 0x18), lVar2 == 0)) {
code_r0x00018047afb3:
                    /* WARNING: Subroutine does not return */
      FUN_18031dad0();
    }
    uStack_18 = 0;
    uStack_10 = 0;
    pcVar7 = DAT_182ec1698;
    if ((DAT_182ec1698 == (code *)0x0) &&
       (pcVar7 = (code *)FUN_1802cf0c0(
                                      "UnityEngine.Transform::get_position_Injected(UnityEngine.Vector3&)"
                                      ), pcVar7 == (code *)0x0)) {
      uVar8 = FUN_1802ced60("UnityEngine.Transform::get_position_Injected(UnityEngine.Vector3&)");
                    /* WARNING: Subroutine does not return */
      FUN_1802cca90(uVar8,0);
    }
    DAT_182ec1698 = pcVar7;
    (*DAT_182ec1698)(lVar2,&uStack_18);
    *(undefined8 *)(param_1 + 0x48) = uStack_18;
    *(undefined4 *)(param_1 + 0x50) = uStack_10;
    *(undefined4 *)(param_1 + 0x58) = 0;
  }
  *(char *)(param_1 + 0x54) = cVar4;
  return cVar4;
}

