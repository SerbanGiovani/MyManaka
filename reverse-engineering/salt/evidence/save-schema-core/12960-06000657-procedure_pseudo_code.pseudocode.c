// Ghidra pseudocode; not original source or compilable C.
// ev_92bcf6c136d3473503598ef6fe1ee523a846d9f8efa0b34691d9d4ea04157838

longlong ES3Internal_ES3Reflection__GetSerializableFields__06000657
                   (longlong *param_1,longlong param_2,char param_3,longlong param_4,
                   undefined4 param_5)

{
  longlong *plVar1;
  longlong lVar2;
  char cVar3;
  byte bVar4;
  longlong lVar5;
  longlong lVar6;
  longlong *plVar7;
  ulonglong uVar8;
  longlong *plVar9;
  undefined8 uVar10;
  longlong *plVar11;
  uint uVar12;
  
  if (DAT_182eb8087 == '\0') {
    FUN_1802f2810(&DAT_182d52c00);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d6a800);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d6a7d8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d6a7d0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d6a7c8);
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
    FUN_1802f2810(&DAT_182d6a7c0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d6a7b8);
    LOCK();
    UNLOCK();
    DAT_182eb8087 = '\x01';
  }
  if (*(int *)(DAT_182d535d8 + 0xe0) == 0) {
    FUN_18035c820();
  }
  if (param_1 == (longlong *)0x0) {
    lVar5 = FUN_1802c43a0(DAT_182d6a7c8);
    FUN_1811cf4f0(lVar5,DAT_182d6a7d0);
    return lVar5;
  }
  lVar5 = (**(code **)(*param_1 + 0x698))(param_1,param_5,*(undefined8 *)(*param_1 + 0x6a0));
  if (param_2 == 0) {
    param_2 = FUN_1802c43a0(DAT_182d6a7c8);
    FUN_1811cf4f0(param_2,DAT_182d6a7d0);
  }
  uVar12 = 0;
  if (lVar5 != 0) {
    plVar11 = (longlong *)(lVar5 + 0x20);
    while( true ) {
      if (*(int *)(lVar5 + 0x18) <= (int)uVar12) {
        if (*(int *)(DAT_182d52c00 + 0xe0) == 0) {
          FUN_18035c820();
        }
        lVar5 = (**(code **)(*param_1 + 0x818))(param_1,*(undefined8 *)(*param_1 + 0x820));
        if (*(int *)(DAT_182d535d8 + 0xe0) == 0) {
          FUN_18035c820();
        }
        lVar6 = DAT_182d52e58;
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
          if (lVar6 != 0) {
            if (*(int *)(DAT_182d535d8 + 0xe0) == 0) {
              FUN_18035c820();
            }
            lVar6 = FUN_1803613f0(lVar6,1);
            lVar6 = FUN_1802c5ac0(lVar6 + 0x20);
            if (lVar5 == lVar6) {
              return param_2;
            }
          }
          lVar6 = DAT_182d561c0;
          if (*(int *)(DAT_182d535d8 + 0xe0) == 0) {
            FUN_18035c820();
          }
          if (DAT_182ebb9aa == '\0') {
            FUN_1802f2810(&DAT_182d535d8);
            LOCK();
            UNLOCK();
            DAT_182ebb9aa = '\x01';
          }
          if (lVar6 != 0) {
            if (*(int *)(DAT_182d535d8 + 0xe0) == 0) {
              FUN_18035c820();
            }
            lVar6 = FUN_1803613f0(lVar6,1);
            lVar6 = FUN_1802c5ac0(lVar6 + 0x20);
            if (lVar5 == lVar6) {
              return param_2;
            }
          }
          if (*(int *)(DAT_182d52c00 + 0xe0) == 0) {
            FUN_18035c820();
          }
          uVar10 = (**(code **)(*param_1 + 0x818))(param_1,*(undefined8 *)(*param_1 + 0x820));
          ES3Internal_ES3Reflection__GetSerializableFields__06000657
                    (uVar10,param_2,param_3,param_4,0x3e,0);
        }
        return param_2;
      }
      if (*(uint *)(lVar5 + 0x18) <= uVar12) {
                    /* WARNING: Subroutine does not return */
        FUN_18031dae0();
      }
      plVar1 = (longlong *)*plVar11;
      if (plVar1 == (longlong *)0x0) break;
      lVar6 = (**(code **)(*plVar1 + 0x1a8))(plVar1,*(undefined8 *)(*plVar1 + 0x1b0));
      if ((param_4 == 0) || (cVar3 = FUN_1809789e0(param_4,lVar6,DAT_182d6a800), cVar3 != '\0')) {
        plVar7 = (longlong *)(**(code **)(*plVar1 + 0x238))(plVar1,*(undefined8 *)(*plVar1 + 0x240))
        ;
        if (*(int *)(DAT_182d52c00 + 0xe0) == 0) {
          FUN_18035c820(DAT_182d52c00);
        }
        cVar3 = FUN_18164c970(plVar1,*(undefined8 *)(*(longlong *)(DAT_182d52c00 + 0xb8) + 0x28),1,0
                             );
        if (cVar3 != '\0') {
          if (param_2 != 0) {
            FUN_180008590(param_2,plVar1);
            goto LAB_18059a827;
          }
          break;
        }
        if (*(int *)(DAT_182d52c00 + 0xe0) == 0) {
          FUN_18035c820(DAT_182d52c00);
        }
        cVar3 = FUN_18164c970(plVar1,*(undefined8 *)(*(longlong *)(DAT_182d52c00 + 0xb8) + 0x30),1,0
                             );
        if (cVar3 != '\0') goto LAB_18059a827;
        if ((param_3 != '\0') &&
           (bVar4 = (**(code **)(*plVar1 + 0x228))(plVar1,*(undefined8 *)(*plVar1 + 0x230)),
           (bVar4 & 7) != 6)) {
          if (*(int *)(DAT_182d52c00 + 0xe0) == 0) {
            FUN_18035c820(DAT_182d52c00);
          }
          cVar3 = FUN_18164c970(plVar1,*(undefined8 *)(*(longlong *)(DAT_182d52c00 + 0xb8) + 0x10),1
                                ,0);
          if (cVar3 == '\0') goto LAB_18059a827;
        }
        uVar8 = (**(code **)(*plVar1 + 0x228))(plVar1,*(undefined8 *)(*plVar1 + 0x230));
        if (((uVar8 & 0x40) != 0) ||
           (uVar8 = (**(code **)(*plVar1 + 0x228))(plVar1,*(undefined8 *)(*plVar1 + 0x230)),
           (uVar8 & 0x20) != 0)) goto LAB_18059a827;
        if (*(int *)(DAT_182d535d8 + 0xe0) == 0) {
          FUN_18035c820();
        }
        lVar2 = DAT_182d561c0;
        if (plVar7 == param_1) {
          if (*(int *)(DAT_182d535d8 + 0xe0) == 0) {
            FUN_18035c820();
          }
          plVar9 = (longlong *)FUN_181638ed0(lVar2,0);
          if (*(int *)(DAT_182d52c00 + 0xe0) == 0) {
            FUN_18035c820();
          }
          if (plVar9 == (longlong *)0x0) break;
          cVar3 = (**(code **)(*plVar9 + 0x288))(plVar9,plVar7,*(undefined8 *)(*plVar9 + 0x290));
          if (cVar3 == '\0') goto LAB_18059a827;
        }
        if (*(int *)(DAT_182d52c00 + 0xe0) == 0) {
          FUN_18035c820(DAT_182d52c00);
        }
        cVar3 = FUN_18164c970(plVar1,*(undefined8 *)(*(longlong *)(DAT_182d52c00 + 0xb8) + 0x20),1,0
                             );
        if (cVar3 != '\0') goto LAB_18059a827;
        if (*(int *)(DAT_182d52c00 + 0xe0) == 0) {
          FUN_18035c820(DAT_182d52c00);
        }
        cVar3 = FUN_18164c970(plVar1,*(undefined8 *)(*(longlong *)(DAT_182d52c00 + 0xb8) + 0x18),1,0
                             );
        if (cVar3 != '\0') goto LAB_18059a827;
        uVar10 = (**(code **)(*plVar1 + 0x238))(plVar1,*(undefined8 *)(*plVar1 + 0x240));
        if (*(int *)(DAT_182d52c00 + 0xe0) == 0) {
          FUN_18035c820();
        }
        cVar3 = ES3Internal_ES3Reflection__TypeIsSerializable__06000659(uVar10,0);
        if (cVar3 == '\0') goto LAB_18059a827;
        if (param_3 != '\0') {
          if (lVar6 == 0) break;
          cVar3 = System_String__StartsWith__06000214(lVar6,DAT_182d6a7b8,0);
          if (cVar3 != '\0') {
            plVar7 = (longlong *)
                     (**(code **)(*plVar1 + 0x1b8))(plVar1,*(undefined8 *)(*plVar1 + 0x1c0));
            if (plVar7 == (longlong *)0x0) break;
            lVar6 = (**(code **)(*plVar7 + 0x2a8))(plVar7,*(undefined8 *)(*plVar7 + 0x2b0));
            if (lVar6 != 0) {
              plVar7 = (longlong *)
                       (**(code **)(*plVar1 + 0x1b8))(plVar1,*(undefined8 *)(*plVar1 + 0x1c0));
              if ((plVar7 == (longlong *)0x0) ||
                 (lVar6 = (**(code **)(*plVar7 + 0x2a8))(plVar7,*(undefined8 *)(*plVar7 + 0x2b0)),
                 lVar6 == 0)) break;
              cVar3 = System_String__Contains__06000258(lVar6,DAT_182d6a7c0,0);
              if (cVar3 != '\0') goto LAB_18059a827;
            }
          }
        }
        if (param_2 == 0) break;
        FUN_180008590(param_2,plVar1);
        uVar12 = uVar12 + 1;
        plVar11 = plVar11 + 1;
      }
      else {
LAB_18059a827:
        uVar12 = uVar12 + 1;
        plVar11 = plVar11 + 1;
      }
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

