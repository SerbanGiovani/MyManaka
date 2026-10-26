// Ghidra pseudocode; not original source or compilable C.
// ev_79cb39a4a67537e140efb87819cd72ad01c53d452d760310508992e8432baaae

void ES3Types_ES3ObjectType__Write__06000433(longlong *param_1,longlong *param_2,longlong *param_3)

{
  undefined8 uVar1;
  char cVar2;
  longlong *plVar3;
  longlong lVar4;
  longlong lVar5;
  
  if (cRam0000000182eb7ecc == '\0') {
    FUN_1802f2810(&DAT_182d52c00);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d52ec0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d52e58);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d535d8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d68ab8);
    LOCK();
    UNLOCK();
    cRam0000000182eb7ecc = '\x01';
  }
  cVar2 = ES3Types_ES3Type__WriteUsingDerivedType__06000441(param_1,param_2,param_3,0);
  if (cVar2 != '\0') {
    return;
  }
  if (param_2 != (longlong *)0x0) {
    plVar3 = (longlong *)FUN_1802c5ac0(*param_2 + 0x20);
    if (*(int *)(DAT_182d52c00 + 0xe0) == 0) {
      FUN_18035c820();
    }
    if (plVar3 != (longlong *)0x0) {
      lVar4 = (**(code **)(*plVar3 + 0x818))(plVar3,*(undefined8 *)(*plVar3 + 0x820));
      uVar1 = DAT_182d52e58;
      if (*(int *)(DAT_182d535d8 + 0xe0) == 0) {
        FUN_18035c820();
      }
      lVar5 = FUN_181638ed0(uVar1,0);
      if (lVar4 != lVar5) {
        if (*(int *)(DAT_182d52ec0 + 0xe0) == 0) {
          FUN_18035c820();
        }
        lVar4 = ES3Internal_ES3TypeMgr__GetOrCreateES3Type__060006ea(lVar4,0,0);
        if ((lVar4 != 0) && ((*(char *)(lVar4 + 0x23) != '\0' || (*(char *)(lVar4 + 0x22) != '\0')))
           ) {
          if (param_3 == (longlong *)0x0) goto DAT_180551e34;
          (**(code **)(*param_3 + 0x438))
                    (param_3,uRam0000000182d68ab8,param_2,lVar4,*(undefined8 *)(*param_3 + 0x440));
        }
      }
      (**(code **)(*param_1 + 0x1a8))(param_1,param_2,param_3,*(undefined8 *)(*param_1 + 0x1b0));
      return;
    }
  }
DAT_180551e34:
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

