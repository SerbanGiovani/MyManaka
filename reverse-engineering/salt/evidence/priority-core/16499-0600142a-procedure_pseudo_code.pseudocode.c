// Ghidra pseudocode; not original source or compilable C.
// ev_343ec4da89af2617d13b17aebbbcbb693626edc4cef061a4110888b20967d5b6

ulonglong ExposureUnnoticed2_Scripts_Mission_MissionBuyMachineExpose__IsInCondition__0600142a
                    (longlong param_1)

{
  uint uVar1;
  longlong lVar2;
  longlong lVar3;
  ulonglong uVar4;
  ulonglong uVar5;
  
  if (cRam0000000182eb78ff == '\0') {
    FUN_1802f2810(&DAT_182d58288);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d53c48);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d58230);
    LOCK();
    UNLOCK();
    cRam0000000182eb78ff = '\x01';
  }
  if ((**(longlong **)(DAT_182d53c48 + 0xb8) != 0) &&
     (lVar2 = *(longlong *)(**(longlong **)(DAT_182d53c48 + 0xb8) + 0x28), lVar2 != 0)) {
    lVar2 = *(longlong *)(lVar2 + 0x30);
    if (**(longlong **)(DAT_182d58230 + 0xb8) != 0) {
      uVar4 = ExposureUnnoticed2_Object3D_Player_Scripts_PlayerFacade__GetExposedBodyPartsByClothesAndCostume__06000d9f
                        (**(longlong **)(DAT_182d58230 + 0xb8),0);
      if ((*(longlong *)(param_1 + 0x28) != 0) &&
         (lVar3 = *(longlong *)(*(longlong *)(param_1 + 0x28) + 0x20), lVar3 != 0)) {
        uVar1 = *(uint *)(lVar3 + 0x34);
        uVar5 = uVar4;
        if (*(int *)(DAT_182d58288 + 0xe0) == 0) {
          uVar5 = FUN_18035c820();
        }
        if (((uint)uVar4 & uVar1) == 0) {
          return uVar5 & 0xffffffffffffff00;
        }
        if ((((lVar2 != 0) && (lVar2 = *(longlong *)(lVar2 + 0x40), lVar2 != 0)) &&
            (lVar2 = *(longlong *)(lVar2 + 0x60), lVar2 != 0)) &&
           (lVar2 = *(longlong *)(lVar2 + 0x48), lVar2 != 0)) {
          return CONCAT71((int7)((ulonglong)lVar2 >> 8),*(int *)(lVar2 + 0x18) == 0x271b);
        }
      }
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

