// Ghidra pseudocode; not original source or compilable C.
// ev_d42833a6bce9d40d91b31de5220d929d0ef891861dbe1a7521d62c6e85f85f52

void ExposureUnnoticed2_Object3D_NPC_Script_NpcManager__ApplyGameState__060010a5(longlong param_1)

{
  uint uVar1;
  longlong lVar2;
  undefined8 uVar3;
  longlong lVar4;
  longlong lVar5;
  code *pcVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  undefined8 local_38;
  undefined4 local_30;
  undefined8 local_28;
  undefined8 uStack_20;
  
  if (DAT_182eb777b == '\0') {
    FUN_1802f2810(&DAT_182d58398);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d59448);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d59488);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d59438);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d59428);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d59418);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d59410);
    LOCK();
    UNLOCK();
    DAT_182eb777b = '\x01';
  }
  if (*(char *)(param_1 + 0x65) == '\0') {
    return;
  }
  if (*(longlong *)(param_1 + 0x38) != 0) {
    iVar9 = *(int *)(*(longlong *)(param_1 + 0x38) + 0x18) - *(int *)(param_1 + 0x68);
    lVar4 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
    while( true ) {
      if ((lVar4 == 0) || (*(longlong *)(lVar4 + 0x40) == 0)) goto LAB_180432517;
      if (iVar9 <= *(int *)(*(longlong *)(lVar4 + 0x40) + 0x18)) break;
      lVar4 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
      if (lVar4 == 0) goto LAB_180432517;
      lVar4 = *(longlong *)(lVar4 + 0x40);
      uVar3 = FUN_1802c43a0(DAT_182d59410);
      lVar5 = DAT_182d59448;
      if (lVar4 == 0) goto LAB_180432517;
      *(int *)(lVar4 + 0x1c) = *(int *)(lVar4 + 0x1c) + 1;
      lVar2 = *(longlong *)(lVar4 + 0x10);
      if (lVar2 == 0) goto LAB_180432517;
      uVar1 = *(uint *)(lVar4 + 0x18);
      if (uVar1 < *(uint *)(lVar2 + 0x18)) {
        *(uint *)(lVar4 + 0x18) = uVar1 + 1;
        FUN_180002cd0(lVar2,(longlong)(int)uVar1,uVar3);
      }
      else {
        FUN_1812741c0(lVar4,uVar3,
                      *(undefined8 *)(*(longlong *)(*(longlong *)(lVar5 + 0x20) + 0xc0) + 0x70));
      }
      lVar4 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
    }
    lVar4 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
    iVar8 = 0;
    iVar7 = 0;
    if (lVar4 != 0) goto LAB_180432290;
  }
LAB_180432517:
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
LAB_180432290:
  if (*(longlong *)(lVar4 + 0x40) == 0) goto LAB_180432517;
  if (*(int *)(*(longlong *)(lVar4 + 0x40) + 0x18) <= iVar7) {
    return;
  }
  if (iVar7 < iVar9) {
    if ((((*(longlong *)(param_1 + 0x38) == 0) ||
         (lVar4 = FUN_180002d60(*(longlong *)(param_1 + 0x38),iVar7), lVar4 == 0)) ||
        ((*(longlong *)(lVar4 + 0x28) == 0 ||
         ((lVar4 = *(longlong *)(*(longlong *)(lVar4 + 0x28) + 0x98), lVar4 == 0 ||
          (lVar4 = *(longlong *)(lVar4 + 0x30), lVar4 == 0)))))) ||
       (lVar4 = *(longlong *)(lVar4 + 0x40), lVar4 == 0)) goto LAB_180432517;
    if (*(int *)(lVar4 + 0x58) == 0) {
      lVar4 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
      if (((lVar4 == 0) || (lVar4 = *(longlong *)(lVar4 + 0x40), lVar4 == 0)) ||
         (lVar4 = FUN_180002d60(lVar4,iVar7), lVar4 == 0)) goto LAB_180432517;
      *(undefined1 *)(lVar4 + 0x2c) = 1;
      lVar4 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
      if ((lVar4 == 0) || (lVar4 = *(longlong *)(lVar4 + 0x40), lVar4 == 0)) goto LAB_180432517;
      lVar4 = FUN_180002d60(lVar4,iVar7);
      if ((*(longlong *)(param_1 + 0x38) == 0) ||
         ((lVar5 = FUN_180002d60(*(longlong *)(param_1 + 0x38),iVar7 - iVar8), lVar5 == 0 ||
          (lVar5 = *(longlong *)(lVar5 + 0x10), lVar5 == 0)))) goto LAB_180432517;
      local_38 = 0;
      local_30 = 0;
      pcVar6 = DAT_182ec1698;
      if ((DAT_182ec1698 == (code *)0x0) &&
         (pcVar6 = (code *)FUN_1802cf0c0(
                                        "UnityEngine.Transform::get_position_Injected(UnityEngine.Vector3&)"
                                        ), pcVar6 == (code *)0x0)) {
        uVar3 = FUN_1802ced60("UnityEngine.Transform::get_position_Injected(UnityEngine.Vector3&)");
                    /* WARNING: Subroutine does not return */
        FUN_1802cca90(uVar3,0);
      }
      DAT_182ec1698 = pcVar6;
      (*DAT_182ec1698)(lVar5,&local_38);
      if (lVar4 == 0) goto LAB_180432517;
      *(undefined8 *)(lVar4 + 0x10) = local_38;
      *(undefined4 *)(lVar4 + 0x18) = local_30;
      lVar4 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
      if ((lVar4 == 0) || (lVar4 = *(longlong *)(lVar4 + 0x40), lVar4 == 0)) goto LAB_180432517;
      lVar4 = FUN_180002d60(lVar4,iVar7);
      if ((*(longlong *)(param_1 + 0x38) == 0) ||
         ((lVar5 = FUN_180002d60(*(longlong *)(param_1 + 0x38),iVar7 - iVar8), lVar5 == 0 ||
          (lVar5 = *(longlong *)(lVar5 + 0x10), lVar5 == 0)))) goto LAB_180432517;
      local_28 = 0;
      uStack_20 = 0;
      pcVar6 = DAT_182ec16b8;
      if ((DAT_182ec16b8 == (code *)0x0) &&
         (pcVar6 = (code *)FUN_1802cf0c0(
                                        "UnityEngine.Transform::get_rotation_Injected(UnityEngine.Quaternion&)"
                                        ), pcVar6 == (code *)0x0)) {
        uVar3 = FUN_1802ced60(
                             "UnityEngine.Transform::get_rotation_Injected(UnityEngine.Quaternion&)"
                             );
                    /* WARNING: Subroutine does not return */
        FUN_1802cca90(uVar3,0);
      }
      DAT_182ec16b8 = pcVar6;
      (*DAT_182ec16b8)(lVar5,&local_28);
      if (lVar4 == 0) goto LAB_180432517;
      *(undefined4 *)(lVar4 + 0x1c) = (undefined4)local_28;
      *(undefined4 *)(lVar4 + 0x20) = local_28._4_4_;
      *(undefined4 *)(lVar4 + 0x24) = (undefined4)uStack_20;
      *(undefined4 *)(lVar4 + 0x28) = uStack_20._4_4_;
    }
    else {
      iVar8 = iVar8 + 1;
    }
  }
  else {
    lVar4 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
    if (((lVar4 == 0) || (lVar4 = *(longlong *)(lVar4 + 0x40), lVar4 == 0)) ||
       (lVar4 = FUN_180002d60(lVar4,iVar7), lVar4 == 0)) goto LAB_180432517;
    *(undefined1 *)(lVar4 + 0x2c) = 0;
  }
  iVar7 = iVar7 + 1;
  lVar4 = *(longlong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
  if (lVar4 == 0) goto LAB_180432517;
  goto LAB_180432290;
}

