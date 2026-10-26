// Ghidra pseudocode; not original source or compilable C.
// ev_5e67be1fc8f7b04eb173fabc7fab1afbf64be788b47feec6be0453aaa3478f5f

bool ExposureUnnoticed2_Scripts_Mission_MissionExposeHandcuffs__IsInCondition__0600144a(void)

{
  longlong lVar1;
  char cVar2;
  int iVar3;
  
  if (cRam0000000182eb7911 == '\0') {
    FUN_1802f2810(&DAT_182d58288);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d53c48);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d58230);
    LOCK();
    UNLOCK();
    cRam0000000182eb7911 = '\x01';
  }
  if (((**(longlong **)(DAT_182d53c48 + 0xb8) != 0) &&
      (lVar1 = *(longlong *)(**(longlong **)(DAT_182d53c48 + 0xb8) + 0x28), lVar1 != 0)) &&
     (lVar1 = *(longlong *)(lVar1 + 0x30), **(longlong **)(DAT_182d58230 + 0xb8) != 0)) {
    iVar3 = ExposureUnnoticed2_Object3D_Player_Scripts_PlayerFacade__GetExposedBodyPartsByClothesAndCostume__06000d9f
                      ();
    if (*(int *)(DAT_182d58288 + 0xe0) == 0) {
      FUN_18035c820();
    }
    if (iVar3 == 1) {
      return false;
    }
    if (((lVar1 != 0) && (lVar1 = *(longlong *)(lVar1 + 0x40), lVar1 != 0)) &&
       (lVar1 = *(longlong *)(lVar1 + 0xf0), lVar1 != 0)) {
      cVar2 = ExposureUnnoticed2_Object3D_Player_Scripts_PlayerHandcuffsController__IsConditionMission__06000dc8
                        (lVar1,0);
      return cVar2 != '\0';
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

