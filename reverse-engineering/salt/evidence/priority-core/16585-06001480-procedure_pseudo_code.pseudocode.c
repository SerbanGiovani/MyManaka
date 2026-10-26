// Ghidra pseudocode; not original source or compilable C.
// ev_2e555fb7bc43df9d3908c1bccc3dfd20715af3da28a9015093004faed4f0d8f2

bool ExposureUnnoticed2_Scripts_Mission_MissionSimpleBodyExpose__IsInCondition__06001480
               (longlong param_1)

{
  uint uVar1;
  longlong lVar2;
  uint uVar3;
  
  if (cRam0000000182eb7933 == '\0') {
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
    cRam0000000182eb7933 = '\x01';
  }
  if (((**(longlong **)(DAT_182d53c48 + 0xb8) != 0) &&
      (*(longlong *)(**(longlong **)(DAT_182d53c48 + 0xb8) + 0x28) != 0)) &&
     (**(longlong **)(DAT_182d58230 + 0xb8) != 0)) {
    uVar3 = ExposureUnnoticed2_Object3D_Player_Scripts_PlayerFacade__GetExposedBodyPartsByClothesAndCostume__06000d9f
                      (**(longlong **)(DAT_182d58230 + 0xb8),0);
    if ((*(longlong *)(param_1 + 0x28) != 0) &&
       (lVar2 = *(longlong *)(*(longlong *)(param_1 + 0x28) + 0x20), lVar2 != 0)) {
      uVar1 = *(uint *)(lVar2 + 0x34);
      if (*(int *)(DAT_182d58288 + 0xe0) == 0) {
        FUN_18035c820();
      }
      if ((uVar1 & uVar3) != uVar1) {
        return false;
      }
      if (cRam0000000182eb54aa == '\0') {
        FUN_1802f2810(0x182d5d568);
        LOCK();
        UNLOCK();
        cRam0000000182eb54aa = '\x01';
      }
      lVar2 = **(longlong **)(lRam0000000182d5d568 + 0xb8);
      if (*(int *)(DAT_182d53aa8 + 0xe0) == 0) {
        FUN_18035c820();
      }
      if (DAT_182ec12f3 == '\0') {
        FUN_1802f2810(&DAT_182d53aa8);
        LOCK();
        UNLOCK();
        DAT_182ec12f3 = '\x01';
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
      if (lVar2 != 0) {
        if (*(int *)(DAT_182d53aa8 + 0xe0) == 0) {
          FUN_18035c820();
        }
        if (*(longlong *)(lVar2 + 0x10) != 0) {
          if (cRam0000000182eb54aa == '\0') {
            FUN_1802f2810(0x182d5d568);
            LOCK();
            UNLOCK();
            cRam0000000182eb54aa = '\x01';
          }
          if (**(longlong **)(lRam0000000182d5d568 + 0xb8) != 0) {
            return *(char *)(**(longlong **)(lRam0000000182d5d568 + 0xb8) + 0x20) != '\0';
          }
          goto code_r0x00018047ffea;
        }
      }
      return true;
    }
  }
code_r0x00018047ffea:
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

