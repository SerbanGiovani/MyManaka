// Ghidra pseudocode; not original source or compilable C.
// ev_9bfb2b981650a8aaa88ef3a8eff98d7a8d2f937182b372fea2e5d213d5742c46

bool ExposureUnnoticed2_Scripts_Mission_MissionEcstasyByNearNpc__IsInCondition__06001438(void)

{
  longlong lVar1;
  uint uVar2;
  
  if (cRam0000000182eb7907 == '\0') {
    FUN_1802f2810(&DAT_182d58288);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d53c48);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d58230);
    LOCK();
    UNLOCK();
    cRam0000000182eb7907 = '\x01';
  }
  if ((((**(longlong **)(DAT_182d53c48 + 0xb8) != 0) &&
       (lVar1 = *(longlong *)(**(longlong **)(DAT_182d53c48 + 0xb8) + 0x28), lVar1 != 0)) &&
      (lVar1 = *(longlong *)(lVar1 + 0x30), lVar1 != 0)) &&
     ((lVar1 = *(longlong *)(lVar1 + 0x40), lVar1 != 0 &&
      (lVar1 = *(longlong *)(lVar1 + 0x60), lVar1 != 0)))) {
    if ((*(char *)(lVar1 + 0x50) == '\0') || (*(char *)(lVar1 + 0x89) == '\0')) {
      return false;
    }
    if (**(longlong **)(DAT_182d58230 + 0xb8) != 0) {
      uVar2 = ExposureUnnoticed2_Object3D_Player_Scripts_PlayerFacade__GetExposedBodyPartsByClothesAndCostume__06000d9f
                        (**(longlong **)(DAT_182d58230 + 0xb8),0);
      if (*(int *)(DAT_182d58288 + 0xe0) == 0) {
        FUN_18035c820();
      }
      return (uVar2 & uVar2 == 1) == 0;
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

