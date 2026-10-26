// Ghidra pseudocode; not original source or compilable C.
// ev_b3bc18e1707ee5ddd48ee7b8d94654b95990ba209bf4c9add46733ca2a6275fe

undefined8 ES3Internal_ES3Reflection__TypeIsSerializable__06000659(longlong *param_1)

{
  char cVar1;
  longlong *plVar2;
  longlong lVar3;
  undefined8 uVar4;
  uint uVar5;
  undefined8 *puVar6;
  
  if (DAT_182eb8089 == '\0') {
    FUN_1802f2810(&DAT_182d535e8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d52c00);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d52ec0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d6a798);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d535d8);
    LOCK();
    UNLOCK();
    DAT_182eb8089 = '\x01';
  }
  if (*(int *)(DAT_182d535d8 + 0xe0) == 0) {
    FUN_18035c820();
  }
  if (param_1 != (longlong *)0x0) {
    if (*(int *)(DAT_182d52c00 + 0xe0) == 0) {
      FUN_18035c820(DAT_182d52c00);
    }
    cVar1 = (**(code **)(*param_1 + 0x1e8))
                      (param_1,*(undefined8 *)(*(longlong *)(DAT_182d52c00 + 0xb8) + 0x30),1,
                       *(undefined8 *)(*param_1 + 0x1f0));
    if (cVar1 == '\0') {
      if (*(int *)(DAT_182d52c00 + 0xe0) == 0) {
        FUN_18035c820();
      }
      cVar1 = ES3Internal_ES3Reflection__IsPrimitive__06000677(param_1,0);
      if (cVar1 == '\0') {
        if (*(int *)(DAT_182d52c00 + 0xe0) == 0) {
          FUN_18035c820();
        }
        cVar1 = (**(code **)(*param_1 + 0x5f8))(param_1,*(undefined8 *)(*param_1 + 0x600));
        uVar4 = DAT_182d535e8;
        if (cVar1 == '\0') {
          if (*(int *)(DAT_182d535d8 + 0xe0) == 0) {
            FUN_18035c820();
          }
          plVar2 = (longlong *)FUN_181638ed0(uVar4,0);
          if (*(int *)(DAT_182d52c00 + 0xe0) == 0) {
            FUN_18035c820();
          }
          if (plVar2 == (longlong *)0x0) {
LAB_18059b4f5:
                    /* WARNING: Subroutine does not return */
            FUN_18031dad0();
          }
          cVar1 = (**(code **)(*plVar2 + 0x288))(plVar2,param_1,*(undefined8 *)(*plVar2 + 0x290));
          uVar4 = DAT_182d6a798;
          if (cVar1 == '\0') {
            if (*(int *)(DAT_182d535d8 + 0xe0) == 0) {
              FUN_18035c820();
            }
            plVar2 = (longlong *)FUN_181638ed0(uVar4,0);
            if (*(int *)(DAT_182d52c00 + 0xe0) == 0) {
              FUN_18035c820();
            }
            if (plVar2 == (longlong *)0x0) goto LAB_18059b4f5;
            cVar1 = (**(code **)(*plVar2 + 0x288))(plVar2,param_1,*(undefined8 *)(*plVar2 + 0x290));
            if (cVar1 == '\0') {
              if (*(int *)(DAT_182d52ec0 + 0xe0) == 0) {
                FUN_18035c820();
              }
              lVar3 = ES3Internal_ES3TypeMgr__GetOrCreateES3Type__060006ea(param_1,0,0);
              if ((lVar3 == 0) || (*(char *)(lVar3 + 0x28) != '\0')) {
                if (*(int *)(DAT_182d52c00 + 0xe0) == 0) {
                  FUN_18035c820();
                }
                cVar1 = (**(code **)(*param_1 + 0x328))(param_1,*(undefined8 *)(*param_1 + 0x330));
                lVar3 = *param_1;
                if (cVar1 != '\0') {
                  uVar4 = (**(code **)(lVar3 + 0x418))(param_1,*(undefined8 *)(lVar3 + 0x420));
                  if (*(int *)(DAT_182d52c00 + 0xe0) == 0) {
                    FUN_18035c820();
                  }
                  cVar1 = ES3Internal_ES3Reflection__TypeIsSerializable__06000659(uVar4,0);
                  if (cVar1 == '\0') {
                    return 0;
                  }
                  return 1;
                }
                lVar3 = (**(code **)(lVar3 + 0x458))(param_1,*(undefined8 *)(lVar3 + 0x460));
                uVar5 = 0;
                if (lVar3 != 0) {
                  puVar6 = (undefined8 *)(lVar3 + 0x20);
                  while( true ) {
                    if (*(int *)(lVar3 + 0x18) <= (int)uVar5) {
                      return 0;
                    }
                    if (*(uint *)(lVar3 + 0x18) <= uVar5) break;
                    uVar4 = *puVar6;
                    if (*(int *)(DAT_182d52c00 + 0xe0) == 0) {
                      FUN_18035c820();
                    }
                    cVar1 = ES3Internal_ES3Reflection__TypeIsSerializable__06000659(uVar4,0);
                    if (cVar1 == '\0') {
                      return 0;
                    }
                    uVar5 = uVar5 + 1;
                    puVar6 = puVar6 + 1;
                  }
                    /* WARNING: Subroutine does not return */
                  FUN_18031dae0();
                }
                goto LAB_18059b4f5;
              }
            }
          }
        }
      }
      return 1;
    }
  }
  return 0;
}

