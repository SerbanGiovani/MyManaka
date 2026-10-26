// Ghidra pseudocode; not original source or compilable C.
// ev_dfea025908fdb61e70c32c3d7dedc2efff667434897877d219d444c5659af450

longlong ES3Internal_ES3Reflection__GetSerializableProperties__06000658
                   (longlong *param_1,longlong param_2,char param_3,longlong param_4,uint param_5)

{
  longlong *plVar1;
  undefined8 uVar2;
  char cVar3;
  char cVar4;
  longlong lVar5;
  longlong *plVar6;
  longlong lVar7;
  longlong *plVar8;
  longlong *plVar9;
  longlong lVar10;
  uint uVar11;
  
  if (DAT_182eb8088 == '\0') {
    FUN_1802f2810(&DAT_182d535e8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d52c00);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d6a800);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d6a7b0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d6a7a8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d6a7a0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d561c0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d52e58);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d535d8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d67b28);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d67ed0);
    LOCK();
    UNLOCK();
    DAT_182eb8088 = '\x01';
  }
  lVar5 = DAT_182d535e8;
  if (*(int *)(DAT_182d535d8 + 0xe0) == 0) {
    FUN_18035c820();
  }
  if (DAT_182ebb9aa == '\0') {
    FUN_1802f2810(&DAT_182d535d8);
    LOCK();
    UNLOCK();
    DAT_182ebb9aa = '\x01';
  }
  plVar6 = (longlong *)0x0;
  if (lVar5 != 0) {
    if (*(int *)(DAT_182d535d8 + 0xe0) == 0) {
      FUN_18035c820();
    }
    lVar5 = FUN_1803613f0(lVar5,1);
    plVar6 = (longlong *)FUN_1802c5ac0(lVar5 + 0x20);
  }
  if (*(int *)(DAT_182d52c00 + 0xe0) == 0) {
    FUN_18035c820();
  }
  if ((plVar6 != (longlong *)0x0) &&
     (cVar3 = (**(code **)(*plVar6 + 0x288))(plVar6,param_1,*(undefined8 *)(*plVar6 + 0x290)),
     param_1 != (longlong *)0x0)) {
    uVar11 = param_5 | 0x20;
    if (param_3 != '\0') {
      uVar11 = param_5;
    }
    lVar5 = (**(code **)(*param_1 + 0x7e8))(param_1,uVar11,*(undefined8 *)(*param_1 + 0x7f0));
    if (param_2 == 0) {
      param_2 = FUN_1802c43a0(DAT_182d6a7a0);
      FUN_1811cf4f0(param_2,DAT_182d6a7a8);
    }
    uVar11 = 0;
    if (lVar5 != 0) {
      plVar6 = (longlong *)(lVar5 + 0x20);
      do {
        while( true ) {
          if (*(int *)(lVar5 + 0x18) <= (int)uVar11) {
            if (*(int *)(DAT_182d52c00 + 0xe0) == 0) {
              FUN_18035c820();
            }
            lVar5 = (**(code **)(*param_1 + 0x818))(param_1,*(undefined8 *)(*param_1 + 0x820));
            if (*(int *)(DAT_182d535d8 + 0xe0) == 0) {
              FUN_18035c820();
            }
            lVar7 = DAT_182d52e58;
            if (lVar5 != 0) {
              if (*(int *)(DAT_182d535d8 + 0xe0) == 0) {
                FUN_18035c820();
              }
              if (DAT_182ebb9aa == '\0') {
                FUN_1802f2810(&DAT_182d535d8);
                LOCK();
                UNLOCK();
                DAT_182ebb9aa = '\x01';
              }
              if (lVar7 != 0) {
                if (*(int *)(DAT_182d535d8 + 0xe0) == 0) {
                  FUN_18035c820();
                }
                lVar7 = FUN_1803613f0(lVar7,1);
                lVar7 = FUN_1802c5ac0(lVar7 + 0x20);
                if (lVar5 == lVar7) {
                  return param_2;
                }
              }
              if (*(int *)(DAT_182d52c00 + 0xe0) == 0) {
                FUN_18035c820();
              }
              ES3Internal_ES3Reflection__GetSerializableProperties__06000658
                        (lVar5,param_2,param_3,param_4,0x3e,0);
            }
            return param_2;
          }
          if (*(uint *)(lVar5 + 0x18) <= uVar11) {
                    /* WARNING: Subroutine does not return */
            FUN_18031dae0();
          }
          plVar1 = (longlong *)*plVar6;
          if (*(int *)(DAT_182d52c00 + 0xe0) == 0) {
            FUN_18035c820(DAT_182d52c00);
          }
          cVar4 = FUN_18164c970(plVar1,*(undefined8 *)(*(longlong *)(DAT_182d52c00 + 0xb8) + 0x28),1
                                ,0);
          if (cVar4 == '\0') break;
          if (param_2 == 0) goto LAB_18059b1a6;
          FUN_1800085f0(param_2,plVar1);
          uVar11 = uVar11 + 1;
          plVar6 = plVar6 + 1;
        }
        if (*(int *)(DAT_182d52c00 + 0xe0) == 0) {
          FUN_18035c820(DAT_182d52c00);
        }
        cVar4 = FUN_18164c970(plVar1,*(undefined8 *)(*(longlong *)(DAT_182d52c00 + 0xb8) + 0x30),1,0
                             );
        if (cVar4 == '\0') {
          if (plVar1 == (longlong *)0x0) break;
          lVar7 = (**(code **)(*plVar1 + 0x1a8))(plVar1,*(undefined8 *)(*plVar1 + 0x1b0));
          if (*(int *)(DAT_182d52c00 + 0xe0) == 0) {
            FUN_18035c820();
          }
          cVar4 = FUN_1809789e0(**(undefined8 **)(DAT_182d52c00 + 0xb8),lVar7,DAT_182d6a800);
          if ((cVar4 == '\0') &&
             ((param_4 == 0 || (cVar4 = FUN_1809789e0(param_4,lVar7,DAT_182d6a800), cVar4 != '\0')))
             ) {
            if (param_3 != '\0') {
              if (*(int *)(DAT_182d52c00 + 0xe0) == 0) {
                FUN_18035c820(DAT_182d52c00);
              }
              cVar4 = FUN_18164c970(plVar1,*(undefined8 *)
                                            (*(longlong *)(DAT_182d52c00 + 0xb8) + 0x10),1,0);
              if (cVar4 == '\0') {
                if (*(int *)(DAT_182d52c00 + 0xe0) == 0) {
                  FUN_18035c820(DAT_182d52c00);
                }
                cVar4 = FUN_18164c970(plVar1,*(undefined8 *)
                                              (*(longlong *)(DAT_182d52c00 + 0xb8) + 0x28),1,0);
                if (cVar4 == '\0') goto LAB_18059b04c;
              }
            }
            plVar8 = (longlong *)
                     (**(code **)(*plVar1 + 0x228))(plVar1,*(undefined8 *)(*plVar1 + 0x230));
            if (*(int *)(DAT_182d535d8 + 0xe0) == 0) {
              FUN_18035c820();
            }
            uVar2 = DAT_182d561c0;
            if (plVar8 == param_1) {
              if (*(int *)(DAT_182d535d8 + 0xe0) == 0) {
                FUN_18035c820();
              }
              plVar9 = (longlong *)FUN_181638ed0(uVar2,0);
              if (*(int *)(DAT_182d52c00 + 0xe0) == 0) {
                FUN_18035c820();
              }
              if (plVar9 == (longlong *)0x0) break;
              cVar4 = (**(code **)(*plVar9 + 0x288))(plVar9,plVar8,*(undefined8 *)(*plVar9 + 0x290))
              ;
              if (cVar4 == '\0') goto LAB_18059b04c;
            }
            cVar4 = (**(code **)(*plVar1 + 0x268))(plVar1,*(undefined8 *)(*plVar1 + 0x270));
            if ((cVar4 != '\0') &&
               (cVar4 = (**(code **)(*plVar1 + 0x278))(plVar1,*(undefined8 *)(*plVar1 + 0x280)),
               cVar4 != '\0')) {
              lVar10 = (**(code **)(*plVar1 + 0x238))(plVar1,*(undefined8 *)(*plVar1 + 0x240));
              if (lVar10 == 0) break;
              if (*(longlong *)(lVar10 + 0x18) != 0) {
                if (plVar8 == (longlong *)0x0) break;
                cVar4 = (**(code **)(*plVar8 + 0x328))(plVar8,*(undefined8 *)(*plVar8 + 0x330));
                if (cVar4 == '\0') goto LAB_18059b04c;
              }
              if (*(int *)(DAT_182d52c00 + 0xe0) == 0) {
                FUN_18035c820();
              }
              cVar4 = ES3Internal_ES3Reflection__TypeIsSerializable__06000659(plVar8,0);
              if ((cVar4 != '\0') &&
                 ((cVar3 == '\0' ||
                  ((lVar7 != DAT_182d67b28 &&
                   (((((lVar7 == 0 || (DAT_182d67b28 == 0)) ||
                      (*(int *)(lVar7 + 0x10) != *(int *)(DAT_182d67b28 + 0x10))) ||
                     (cVar4 = FUN_181630ad0(lVar7 + 0x14,DAT_182d67b28 + 0x14,
                                            (longlong)*(int *)(lVar7 + 0x10) * 2), cVar4 == '\0'))
                    && ((lVar7 != DAT_182d67ed0 &&
                        (((lVar7 == 0 || (DAT_182d67ed0 == 0)) ||
                         ((*(int *)(lVar7 + 0x10) != *(int *)(DAT_182d67ed0 + 0x10) ||
                          (cVar4 = FUN_181630ad0(lVar7 + 0x14,DAT_182d67ed0 + 0x14,
                                                 (longlong)*(int *)(lVar7 + 0x10) * 2),
                          cVar4 == '\0')))))))))))))) {
                if (*(int *)(DAT_182d52c00 + 0xe0) == 0) {
                  FUN_18035c820(DAT_182d52c00);
                }
                cVar4 = FUN_18164c970(plVar1,*(undefined8 *)
                                              (*(longlong *)(DAT_182d52c00 + 0xb8) + 0x18),1,0);
                if (cVar4 == '\0') {
                  if (*(int *)(DAT_182d52c00 + 0xe0) == 0) {
                    FUN_18035c820(DAT_182d52c00);
                  }
                  cVar4 = FUN_18164c970(plVar1,*(undefined8 *)
                                                (*(longlong *)(DAT_182d52c00 + 0xb8) + 0x20),1,0);
                  if (cVar4 == '\0') {
                    if (param_2 == 0) break;
                    FUN_1800085f0(param_2,plVar1);
                  }
                }
              }
            }
          }
        }
LAB_18059b04c:
        uVar11 = uVar11 + 1;
        plVar6 = plVar6 + 1;
      } while( true );
    }
  }
LAB_18059b1a6:
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

