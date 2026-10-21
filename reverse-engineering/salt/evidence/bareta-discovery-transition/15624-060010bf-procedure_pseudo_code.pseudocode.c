// Ghidra pseudocode; not original source or compilable C.
// ev_70258f09577137495d4078b9d6657539e1bd0493d140b97a1d424b52f893cc0f

undefined4
ExposureUnnoticed2_Object3D_NPC_Script_NpcStrangenessManager__CalcCommonAddScale__060010bf
          (longlong param_1)

{
  int iVar1;
  longlong lVar2;
  longlong lVar3;
  longlong *plVar4;
  longlong lVar5;
  undefined4 uVar6;
  
  uVar6 = 0x3f800000;
  if (((*(longlong *)(param_1 + 0x28) == 0) ||
      (lVar5 = *(longlong *)(*(longlong *)(param_1 + 0x28) + 0x60), lVar5 == 0)) ||
     (lVar5 = *(longlong *)(lVar5 + 0x10), lVar5 == 0)) goto code_r0x000180435f36;
  lVar2 = *(longlong *)(*(longlong *)(param_1 + 0x28) + 0x40);
  if (lVar2 == 0) goto code_r0x000180435f36;
  if (*(int *)(lVar2 + 0x58) == 5) {
    uVar6 = *(undefined4 *)(lVar2 + 0x60);
  }
  lVar3 = *(longlong *)(*(longlong *)(param_1 + 0x28) + 0xf8);
  if (lVar3 == 0) goto code_r0x000180435f36;
  if (*(int *)(lVar3 + 0x18) == 1) {
    if ((*(longlong *)(lVar3 + 0x10) == 0) ||
       (lVar3 = *(longlong *)(*(longlong *)(lVar3 + 0x10) + 0x40), lVar3 == 0))
    goto code_r0x000180435f36;
    if (*(int *)(lVar3 + 0x80) == 1) {
      uVar6 = *(undefined4 *)(*(longlong *)(*(longlong *)(param_1 + 0x28) + 0x40) + 0x60);
    }
  }
  if (*(float *)(lVar2 + 0xd0) + 0.05 <= *(float *)(lVar5 + 0x14)) {
    return uVar6;
  }
  lVar5 = *(longlong *)(*(longlong *)(param_1 + 0x28) + 0x40);
  if ((*(int *)(lVar5 + 0x10) == 0) && (*(char *)(lVar5 + 200) != '\0')) {
    uVar6 = 0x3d4ccccd;
  }
  if (*(int *)(*(longlong *)(*(longlong *)(param_1 + 0x28) + 0x40) + 100) == 4) {
    uVar6 = 0x3d4ccccd;
  }
  if (*(int *)(*(longlong *)(*(longlong *)(param_1 + 0x28) + 0x40) + 100) == 6) {
    uVar6 = 0x3d4ccccd;
  }
  iVar1 = *(int *)(*(longlong *)(*(longlong *)(param_1 + 0x28) + 0x40) + 0x80);
  if ((iVar1 == 3) || (iVar1 == 2)) {
    uVar6 = 0x3d4ccccd;
  }
  if (*(int *)(*(longlong *)(*(longlong *)(param_1 + 0x28) + 0x40) + 0x10) == 5) {
    plVar4 = *(longlong **)(*(longlong *)(*(longlong *)(param_1 + 0x28) + 0x40) + 0x40);
    if ((plVar4 == (longlong *)0x0) ||
       (lVar5 = (**(code **)(*plVar4 + 0x188))(plVar4,*(undefined8 *)(*plVar4 + 400)), lVar5 == 0))
    goto code_r0x000180435f36;
    if (*(int *)(lVar5 + 0x24) != 3) goto code_r0x000180435ed3;
    if ((*(longlong *)(param_1 + 0x28) == 0) ||
       (lVar5 = *(longlong *)(*(longlong *)(param_1 + 0x28) + 0xf8), lVar5 == 0))
    goto code_r0x000180435f36;
    iVar1 = *(int *)(lVar5 + 0x18);
    if ((iVar1 != 0) && (iVar1 != 2)) goto code_r0x000180435ed3;
    lVar5 = *(longlong *)(param_1 + 0x28);
    uVar6 = 0x3d4ccccd;
  }
  else {
code_r0x000180435ed3:
    lVar5 = *(longlong *)(param_1 + 0x28);
    if (lVar5 == 0) goto code_r0x000180435f36;
  }
  if (*(longlong *)(lVar5 + 0x40) == 0) {
code_r0x000180435f36:
                    /* WARNING: Subroutine does not return */
    FUN_18031dad0();
  }
  if (*(int *)(*(longlong *)(lVar5 + 0x40) + 0x58) == 2) {
    uVar6 = 0x3dcccccd;
  }
  else if (*(longlong *)(param_1 + 0x28) == 0) goto code_r0x000180435f36;
  if (*(int *)(*(longlong *)(*(longlong *)(param_1 + 0x28) + 0x40) + 0x58) == 6) {
    uVar6 = 0x3d4ccccd;
  }
  else if (*(longlong *)(param_1 + 0x28) == 0) goto code_r0x000180435f36;
  if (*(int *)(*(longlong *)(*(longlong *)(param_1 + 0x28) + 0x40) + 0x58) == 7) {
    uVar6 = 0x3d4ccccd;
  }
  return uVar6;
}

