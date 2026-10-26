// Ghidra pseudocode; not original source or compilable C.
// ev_86562ada3e82fbfefe6e4c71bb0860477d64dd5d3855ea6629534fa8713f156f

ulonglong ExposureUnnoticed2_Scripts_Mission_MissionSitExpose__IsInCondition__06001482
                    (longlong param_1)

{
  uint uVar1;
  int iVar2;
  longlong lVar3;
  ulonglong uVar4;
  ulonglong uVar5;
  
  if (cRam0000000182eb7934 == '\0') {
    FUN_1802f2810(&DAT_182d58288);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d53c48);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d58378);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d58230);
    LOCK();
    UNLOCK();
    cRam0000000182eb7934 = '\x01';
  }
  if (((**(longlong **)(DAT_182d53c48 + 0xb8) != 0) &&
      (*(longlong *)(**(longlong **)(DAT_182d53c48 + 0xb8) + 0x28) != 0)) &&
     (**(longlong **)(DAT_182d58230 + 0xb8) != 0)) {
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
      if (((**(longlong **)(DAT_182d58378 + 0xb8) != 0) &&
          (uVar4 = *(ulonglong *)(**(longlong **)(DAT_182d58378 + 0xb8) + 0x40), uVar4 != 0)) &&
         ((*(longlong *)(uVar4 + 0x60) != 0 &&
          (lVar3 = *(longlong *)(*(longlong *)(uVar4 + 0x60) + 0x48), lVar3 != 0)))) {
        iVar2 = *(int *)(lVar3 + 0x18);
        if ((iVar2 != 0x272a) && (iVar2 != 0x272b)) {
          uVar1 = iVar2 - 0x2775;
          uVar4 = (ulonglong)uVar1;
          if (3 < uVar1) {
            return (ulonglong)CONCAT31((int3)(uVar1 >> 8),iVar2 == 0x2779);
          }
        }
        return CONCAT71((int7)(uVar4 >> 8),1);
      }
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

