// Ghidra pseudocode; not original source or compilable C.
// ev_4686a89bf82d7c11983f420724f604daae5a1ab296af6d5c65df9f3e62bd4620

bool ExposureUnnoticed2_Scripts_Mission_MissionVibeExposeMove__IsInCondition__06001494
               (longlong param_1)

{
  uint uVar1;
  int iVar2;
  longlong lVar3;
  longlong lVar4;
  bool bVar5;
  uint uVar6;
  code *pcVar7;
  undefined8 uVar8;
  bool bVar9;
  undefined8 uStack_18;
  undefined4 uStack_10;
  
  if (cRam0000000182eb793d == '\0') {
    FUN_1802f2810(&DAT_182d58288);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d58398);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d53c48);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d58230);
    LOCK();
    UNLOCK();
    cRam0000000182eb793d = '\x01';
  }
  if ((**(longlong **)(DAT_182d53c48 + 0xb8) == 0) ||
     (lVar3 = *(longlong *)(**(longlong **)(DAT_182d53c48 + 0xb8) + 0x28), lVar3 == 0))
  goto DAT_180481504;
  lVar3 = *(longlong *)(lVar3 + 0x30);
  if (**(longlong **)(DAT_182d58230 + 0xb8) == 0) goto DAT_180481504;
  uVar6 = ExposureUnnoticed2_Object3D_Player_Scripts_PlayerFacade__GetExposedBodyPartsByClothesAndCostume__06000d9f
                    (**(longlong **)(DAT_182d58230 + 0xb8),0);
  if ((*(longlong *)(param_1 + 0x28) == 0) ||
     (lVar4 = *(longlong *)(*(longlong *)(param_1 + 0x28) + 0x20), lVar4 == 0)) goto DAT_180481504;
  uVar1 = *(uint *)(lVar4 + 0x34);
  if (*(int *)(DAT_182d58288 + 0xe0) == 0) {
    FUN_18035c820();
  }
  if ((uVar6 & uVar1) == 0) {
code_r0x000180481468:
    bVar9 = false;
  }
  else {
    if (((lVar3 == 0) || (*(longlong *)(lVar3 + 0x40) == 0)) ||
       (lVar4 = *(longlong *)(*(longlong *)(lVar3 + 0x40) + 0x60), lVar4 == 0)) goto DAT_180481504;
    if (*(float *)(lVar4 + 0xf8) <= 0.0) goto code_r0x000180481468;
    lVar4 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
    if (lVar4 == 0) goto DAT_180481504;
    iVar2 = *(int *)(lVar4 + 0x1b8);
    if (iVar2 == 2) {
      bVar9 = true;
    }
    else {
      bVar9 = iVar2 == 3;
    }
  }
  bVar5 = false;
  if (*(char *)(param_1 + 0x54) == '\0') {
    bVar5 = bVar9;
  }
  if (bVar5 != false) {
    if (((lVar3 == 0) || (*(longlong *)(lVar3 + 0x40) == 0)) ||
       (lVar3 = *(longlong *)(*(longlong *)(lVar3 + 0x40) + 0x18), lVar3 == 0)) {
DAT_180481504:
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
    (*DAT_182ec1698)(lVar3,&uStack_18);
    *(undefined8 *)(param_1 + 0x48) = uStack_18;
    *(undefined4 *)(param_1 + 0x50) = uStack_10;
    *(undefined8 *)(param_1 + 0x58) = 0;
  }
  *(bool *)(param_1 + 0x54) = bVar9;
  return bVar9;
}

