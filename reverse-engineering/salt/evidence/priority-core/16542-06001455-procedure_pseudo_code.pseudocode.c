// Ghidra pseudocode; not original source or compilable C.
// ev_156e295c2514a7777e6edd42bc27c25498663f128d7b1d7d14f49abc736f41e6

ulonglong ExposureUnnoticed2_Scripts_Mission_MissionExposeRiseStrangeness__IsInCondition__06001455
                    (longlong param_1)

{
  uint uVar1;
  longlong lVar2;
  ulonglong uVar3;
  ulonglong uVar4;
  
  if (cRam0000000182eb7918 == '\0') {
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
    cRam0000000182eb7918 = '\x01';
  }
  if ((**(longlong **)(DAT_182d53c48 + 0xb8) != 0) &&
     (*(longlong *)(**(longlong **)(DAT_182d53c48 + 0xb8) + 0x28) != 0)) {
    uVar4 = *(ulonglong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
    if (uVar4 != 0) {
      if (*(char *)(uVar4 + 0x1dd) != '\0') {
code_r0x00018047bf99:
        return uVar4 & 0xffffffffffffff00;
      }
      if (**(longlong **)(DAT_182d58230 + 0xb8) != 0) {
        uVar3 = ExposureUnnoticed2_Object3D_Player_Scripts_PlayerFacade__GetExposedBodyPartsByClothesAndCostume__06000d9f
                          (**(longlong **)(DAT_182d58230 + 0xb8),0);
        if ((*(longlong *)(param_1 + 0x28) != 0) &&
           (lVar2 = *(longlong *)(*(longlong *)(param_1 + 0x28) + 0x20), lVar2 != 0)) {
          uVar1 = *(uint *)(lVar2 + 0x34);
          uVar4 = uVar3;
          if (*(int *)(DAT_182d58288 + 0xe0) == 0) {
            uVar4 = FUN_18035c820();
          }
          if (((uint)uVar3 & uVar1) == 0) goto code_r0x00018047bf99;
          if (DAT_182eb548c == '\0') {
            FUN_1802f2810(&DAT_182d57a70);
            LOCK();
            UNLOCK();
            DAT_182eb548c = '\x01';
          }
          lVar2 = **(longlong **)(DAT_182d57a70 + 0xb8);
          if (lVar2 != 0) {
            return CONCAT71((int7)((ulonglong)lVar2 >> 8),*(char *)(lVar2 + 0x5c) != '\0');
          }
        }
      }
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

