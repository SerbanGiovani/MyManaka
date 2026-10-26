// Ghidra pseudocode; not original source or compilable C.
// ev_0cb2b0b81448c988d0b2001bec966b0ed1e109cc9d050ed6212df29dace8ffa7

ulonglong ExposureUnnoticed2_Scripts_Mission_MissionExposeInSight__IsInCondition__06001451(void)

{
  longlong lVar1;
  ulonglong uVar2;
  ulonglong uVar3;
  byte bVar4;
  
  if (cRam0000000182eb7916 == '\0') {
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
    cRam0000000182eb7916 = '\x01';
  }
  if ((**(longlong **)(DAT_182d53c48 + 0xb8) != 0) &&
     (*(longlong *)(**(longlong **)(DAT_182d53c48 + 0xb8) + 0x28) != 0)) {
    uVar3 = *(ulonglong *)(*(longlong *)(DAT_182d58398 + 0xb8) + 0x48);
    if (uVar3 != 0) {
      if (*(char *)(uVar3 + 0x1dd) != '\0') {
code_r0x00018047bc3e:
        return uVar3 & 0xffffffffffffff00;
      }
      if (**(longlong **)(DAT_182d58230 + 0xb8) != 0) {
        uVar2 = ExposureUnnoticed2_Object3D_Player_Scripts_PlayerFacade__GetExposedBodyPartsByClothesAndCostume__06000d9f
                          ();
        uVar3 = uVar2;
        if (*(int *)(DAT_182d58288 + 0xe0) == 0) {
          uVar3 = FUN_18035c820();
        }
        bVar4 = 0;
        if ((int)uVar2 == 1) {
          bVar4 = (byte)uVar2 & 1;
        }
        if (bVar4 != 0) goto code_r0x00018047bc3e;
        if (DAT_182eb548c == '\0') {
          FUN_1802f2810(&DAT_182d57a70);
          LOCK();
          UNLOCK();
          DAT_182eb548c = '\x01';
        }
        lVar1 = **(longlong **)(DAT_182d57a70 + 0xb8);
        if (lVar1 != 0) {
          return CONCAT71((int7)((ulonglong)lVar1 >> 8),*(char *)(lVar1 + 0x5e) != '\0');
        }
      }
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

