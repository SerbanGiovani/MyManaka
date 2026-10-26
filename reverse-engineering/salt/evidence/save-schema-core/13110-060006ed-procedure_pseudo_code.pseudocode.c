// Ghidra pseudocode; not original source or compilable C.
// ev_920c064f0a8d79387fa64adadc8f5b14348c5955a9b8ca743018695b1d439a6c

longlong ES3Internal_ES3TypeMgr__CreateES3Type__060006ed(longlong *param_1,char param_2)

{
  longlong lVar1;
  ulonglong uVar2;
  char cVar3;
  int iVar4;
  longlong *plVar5;
  undefined8 uVar6;
  longlong lVar7;
  longlong lVar8;
  undefined8 uVar9;
  undefined8 uVar10;
  uint uVar11;
  bool bVar12;
  
  if (DAT_182eb80bd == '\0') {
    FUN_1802f2810(&DAT_182d535e8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d6a2b8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d6a2b0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d6a2a8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d6a2a0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d56220);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d6a298);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d6a290);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d6a280);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d6a278);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d6a270);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d6a268);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d6a258);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d6a248);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d6a238);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d52c00);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d6a228);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d6a220);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d52ec0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d688f0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d6a218);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d6a210);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d68b98);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d6a208);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d561c0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d6a200);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d6a798);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d6a1f8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d535d8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d6a1f0);
    LOCK();
    UNLOCK();
    DAT_182eb80bd = '\x01';
  }
  if (*(int *)(DAT_182d52c00 + 0xe0) == 0) {
    FUN_18035c820();
  }
  if (param_1 == (longlong *)0x0) goto LAB_1805a5788;
  cVar3 = (**(code **)(*param_1 + 0x598))(param_1,*(undefined8 *)(*param_1 + 0x5a0));
  if (cVar3 != '\0') {
    lVar7 = FUN_1802c43a0(DAT_182d688f0);
    ES3Types_ES3Type_enum___ctor__06000473(lVar7,param_1,0);
    return lVar7;
  }
  if (*(int *)(DAT_182d52c00 + 0xe0) == 0) {
    FUN_18035c820();
  }
  cVar3 = (**(code **)(*param_1 + 0x328))(param_1,*(undefined8 *)(*param_1 + 0x330));
  if (cVar3 != '\0') {
    if (*(int *)(DAT_182d52c00 + 0xe0) == 0) {
      FUN_18035c820();
    }
    iVar4 = (**(code **)(*param_1 + 0x428))(param_1,*(undefined8 *)(*param_1 + 0x430));
    uVar6 = DAT_182d6a2a0;
    if (((iVar4 != 1) && (uVar6 = DAT_182d6a2b0, iVar4 != 2)) && (uVar6 = DAT_182d6a2a8, iVar4 != 3)
       ) {
      if (param_2 == '\0') {
        return 0;
      }
      uVar6 = thunk_FUN_1802f2810(&DAT_182d53260);
      uVar6 = thunk_FUN_1802c43a0(uVar6);
      uVar9 = thunk_FUN_1802f2810(&DAT_182d6a1e8);
      FUN_18161d3f0(uVar6,uVar9,0);
      uVar9 = thunk_FUN_1802f2810(&DAT_182d6a1e0);
                    /* WARNING: Subroutine does not return */
      FUN_18031da90(uVar6,uVar9);
    }
    goto LAB_1805a56d7;
  }
  if (*(int *)(DAT_182d52c00 + 0xe0) == 0) {
    FUN_18035c820();
  }
  cVar3 = (**(code **)(*param_1 + 0x3a8))(param_1,*(undefined8 *)(*param_1 + 0x3b0));
  uVar6 = DAT_182d6a210;
  if (cVar3 == '\0') {
LAB_1805a5380:
    if (*(int *)(DAT_182d52c00 + 0xe0) == 0) {
      FUN_18035c820();
    }
    cVar3 = ES3Internal_ES3Reflection__IsPrimitive__06000677(param_1,0);
    uVar6 = DAT_182d535e8;
    if (cVar3 != '\0') {
      lVar7 = FUN_1802f2810(&DAT_182d52ec0);
      if (*(int *)(lVar7 + 0xe0) == 0) {
        FUN_18035c820(lVar7);
      }
      lVar7 = FUN_1802f2810(&DAT_182d52ec0);
      if (*(longlong *)(*(longlong *)(lVar7 + 0xb8) + 8) != 0) {
        lVar7 = FUN_1802f2810(&DAT_182d52ec0);
        if (*(int *)(lVar7 + 0xe0) == 0) {
          FUN_18035c820(lVar7);
        }
        lVar7 = FUN_1802f2810(&DAT_182d52ec0);
        lVar7 = *(longlong *)(*(longlong *)(lVar7 + 0xb8) + 8);
        if (lVar7 == 0) goto LAB_1805a5788;
        FUN_1802f2810(&DAT_182d6a1c8);
        if (*(int *)(lVar7 + 0x20) != *(int *)(lVar7 + 0x28)) {
          uVar6 = thunk_FUN_1802f2810(&DAT_182d6a1c0);
          uVar6 = thunk_FUN_1802c43a0(uVar6);
          uVar9 = thunk_FUN_1802f2810(&DAT_182d6a1b0);
          FUN_18166e8e0(uVar6,uVar9,0);
          uVar9 = thunk_FUN_1802f2810(&DAT_182d6a1e0);
                    /* WARNING: Subroutine does not return */
          FUN_18031da90(uVar6,uVar9);
        }
      }
      uVar6 = thunk_FUN_1802f2810(&DAT_182d6a1c0);
      uVar6 = thunk_FUN_1802c43a0(uVar6);
      uVar9 = thunk_FUN_1802f2810(&DAT_182d6a1b8);
      FUN_18166e8e0(uVar6,uVar9,0);
      uVar9 = thunk_FUN_1802f2810(&DAT_182d6a1e0);
                    /* WARNING: Subroutine does not return */
      FUN_18031da90(uVar6,uVar9);
    }
    if (*(int *)(DAT_182d535d8 + 0xe0) == 0) {
      FUN_18035c820();
    }
    plVar5 = (longlong *)FUN_181638ed0(uVar6,0);
    if (*(int *)(DAT_182d52c00 + 0xe0) == 0) {
      FUN_18035c820();
    }
    if (plVar5 == (longlong *)0x0) goto LAB_1805a5788;
    cVar3 = (**(code **)(*plVar5 + 0x288))(plVar5,param_1,*(undefined8 *)(*plVar5 + 0x290));
    uVar6 = DAT_182d6a270;
    if (cVar3 == '\0') {
      if (*(int *)(DAT_182d52c00 + 0xe0) == 0) {
        FUN_18035c820();
      }
      cVar3 = (**(code **)(*param_1 + 0x5f8))(param_1,*(undefined8 *)(*param_1 + 0x600));
      uVar6 = DAT_182d6a798;
      uVar9 = DAT_182d6a238;
      if (cVar3 == '\0') {
        if (*(int *)(DAT_182d535d8 + 0xe0) == 0) {
          FUN_18035c820();
        }
        plVar5 = (longlong *)FUN_181638ed0(uVar6,0);
        if (*(int *)(DAT_182d52c00 + 0xe0) == 0) {
          FUN_18035c820();
        }
        if (plVar5 == (longlong *)0x0) goto LAB_1805a5788;
        cVar3 = (**(code **)(*plVar5 + 0x288))(plVar5,param_1,*(undefined8 *)(*plVar5 + 0x290));
        uVar9 = DAT_182d561c0;
        uVar6 = DAT_182d6a258;
        if (cVar3 == '\0') {
          if (*(int *)(DAT_182d535d8 + 0xe0) == 0) {
            FUN_18035c820();
          }
          plVar5 = (longlong *)FUN_181638ed0(uVar9,0);
          if (*(int *)(DAT_182d52c00 + 0xe0) == 0) {
            FUN_18035c820();
          }
          if (plVar5 == (longlong *)0x0) goto LAB_1805a5788;
          cVar3 = (**(code **)(*plVar5 + 0x288))(plVar5,param_1,*(undefined8 *)(*plVar5 + 0x290));
          uVar6 = DAT_182d6a248;
          if (cVar3 == '\0') {
            lVar7 = (**(code **)(*param_1 + 0x1a8))(param_1,*(undefined8 *)(*param_1 + 0x1b0));
            if (lVar7 == 0) goto LAB_1805a5788;
            cVar3 = System_String__StartsWith__06000214(lVar7,DAT_182d6a1f0,0);
            uVar9 = DAT_182d6a268;
            if (cVar3 != '\0') {
              lVar7 = FUN_1802c43a0(DAT_182d6a220);
              ES3Types_ES3TupleType___ctor__06000422(lVar7,param_1,0);
              goto LAB_1805a56ed;
            }
            goto LAB_1805a5551;
          }
        }
        goto LAB_1805a55c4;
      }
LAB_1805a5551:
      lVar7 = FUN_1802c43a0(uVar9);
      ES3Types_ES3Type___ctor__0600043d(lVar7,param_1,0);
      *(undefined1 *)(lVar7 + 0x27) = 1;
    }
    else {
LAB_1805a55c4:
      lVar7 = FUN_1802c43a0(uVar6);
      ES3Types_ES3Type___ctor__0600043d(lVar7,param_1,0);
      *(undefined1 *)(lVar7 + 0x21) = 0;
      *(undefined2 *)(lVar7 + 0x26) = 0x101;
    }
    ES3Types_ES3Type__GetMembers__06000447(lVar7,1,0,0);
  }
  else {
    if (*(int *)(DAT_182d535d8 + 0xe0) == 0) {
      FUN_18035c820();
    }
    plVar5 = (longlong *)FUN_181638ed0(uVar6,0);
    if (*(int *)(DAT_182d52c00 + 0xe0) == 0) {
      FUN_18035c820();
    }
    if (DAT_182eb8099 == '\0') {
      FUN_1802f2810(&DAT_182d535d8);
      LOCK();
      UNLOCK();
      DAT_182eb8099 = '\x01';
    }
    if (plVar5 == (longlong *)0x0) goto LAB_1805a5788;
    uVar6 = (**(code **)(*plVar5 + 0x1a8))(plVar5,*(undefined8 *)(*plVar5 + 0x1b0));
    lVar7 = (**(code **)(*param_1 + 0x848))(param_1,uVar6,0,*(undefined8 *)(*param_1 + 0x850));
    if (*(int *)(DAT_182d535d8 + 0xe0) == 0) {
      FUN_18035c820();
    }
    if (lVar7 == 0) goto LAB_1805a5380;
    if (*(int *)(DAT_182d52c00 + 0xe0) == 0) {
      FUN_18035c820();
    }
    lVar7 = (**(code **)(*param_1 + 0x438))(param_1,*(undefined8 *)(*param_1 + 0x440));
    uVar6 = DAT_182d68b98;
    if (*(int *)(DAT_182d535d8 + 0xe0) == 0) {
      FUN_18035c820();
    }
    plVar5 = (longlong *)FUN_181638ed0(uVar6,0);
    if (plVar5 == (longlong *)0x0) goto LAB_1805a5788;
    cVar3 = (**(code **)(*plVar5 + 0x288))(plVar5,lVar7,*(undefined8 *)(*plVar5 + 0x290));
    uVar9 = DAT_182d6a2b8;
    uVar6 = DAT_182d6a290;
    if (cVar3 == '\0') {
      if (*(int *)(DAT_182d535d8 + 0xe0) == 0) {
        FUN_18035c820();
      }
      plVar5 = (longlong *)FUN_181638ed0(uVar9,0);
      if (plVar5 == (longlong *)0x0) goto LAB_1805a5788;
      cVar3 = (**(code **)(*plVar5 + 0x288))(plVar5,lVar7,*(undefined8 *)(*plVar5 + 0x290));
      uVar6 = DAT_182d6a200;
      if (cVar3 == '\0') {
        if (*(int *)(DAT_182d535d8 + 0xe0) == 0) {
          FUN_18035c820();
        }
        lVar8 = FUN_181638ed0(uVar6,0);
        uVar9 = DAT_182d6a1f8;
        uVar6 = DAT_182d6a278;
        if (lVar7 != lVar8) {
          if (*(int *)(DAT_182d535d8 + 0xe0) == 0) {
            FUN_18035c820();
          }
          lVar8 = FUN_181638ed0(uVar9,0);
          uVar9 = DAT_182d6a218;
          uVar6 = DAT_182d6a228;
          if (lVar7 != lVar8) {
            if (*(int *)(DAT_182d535d8 + 0xe0) == 0) {
              FUN_18035c820();
            }
            lVar8 = FUN_181638ed0(uVar9,0);
            uVar9 = DAT_182d6a208;
            uVar6 = DAT_182d6a298;
            if (lVar7 != lVar8) {
              if (*(int *)(DAT_182d535d8 + 0xe0) == 0) {
                FUN_18035c820();
              }
              lVar8 = FUN_181638ed0(uVar9,0);
              uVar6 = DAT_182d6a280;
              if (lVar7 != lVar8) {
                if (param_2 == '\0') {
                  return 0;
                }
                FUN_1800039f0(param_1);
                uVar6 = FUN_180002bf0(3,param_1);
                uVar9 = thunk_FUN_1802f2810(&DAT_182d6a1d8);
                uVar10 = thunk_FUN_1802f2810(&DAT_182d6a1d0);
                uVar6 = System_String__Concat__0600021c(uVar10,uVar6,uVar9,0);
                uVar9 = thunk_FUN_1802f2810(&DAT_182d53260);
                uVar9 = thunk_FUN_1802c43a0(uVar9);
                FUN_18161d3f0(uVar9,uVar6,0);
                uVar6 = thunk_FUN_1802f2810(&DAT_182d6a1e0);
                    /* WARNING: Subroutine does not return */
                FUN_18031da90(uVar9,uVar6);
              }
            }
          }
        }
        goto LAB_1805a56d7;
      }
      lVar7 = FUN_1802c43a0(DAT_182d56220);
      if (DAT_182eb7eb1 == '\0') {
        FUN_1802f2810(&DAT_182d52c00);
        LOCK();
        UNLOCK();
        FUN_1802f2810(&DAT_182d52ec0);
        LOCK();
        UNLOCK();
        DAT_182eb7eb1 = '\x01';
      }
      ES3Types_ES3Type___ctor__0600043d(lVar7,param_1,0);
      if (*(int *)(DAT_182d52c00 + 0xe0) == 0) {
        FUN_18035c820();
      }
      lVar8 = ES3Internal_ES3Reflection__GetElementTypes__06000656(param_1,0);
      if (lVar8 == 0) goto LAB_1805a5788;
      if (*(int *)(lVar8 + 0x18) == 0) {
LAB_1805a5812:
                    /* WARNING: Subroutine does not return */
        FUN_18031dae0();
      }
      uVar6 = *(undefined8 *)(lVar8 + 0x20);
      if (*(int *)(DAT_182d52ec0 + 0xe0) == 0) {
        FUN_18035c820();
      }
      uVar6 = ES3Internal_ES3TypeMgr__GetOrCreateES3Type__060006ea(uVar6,0,0);
      bVar12 = DAT_182eb5d50 != 0;
      *(undefined8 *)(lVar7 + 0x30) = uVar6;
      if (bVar12) {
        uVar11 = (uint)(lVar7 + 0x30U >> 0xc);
        lVar1 = (ulonglong)((uVar11 & 0x1fffff) >> 6) * 8;
        do {
          uVar2 = *(ulonglong *)(&DAT_182f0c920 + lVar1);
          LOCK();
          bVar12 = uVar2 == *(ulonglong *)(&DAT_182f0c920 + lVar1);
          if (bVar12) {
            *(ulonglong *)(&DAT_182f0c920 + lVar1) = uVar2 | 1L << (uVar11 & 0x3f);
          }
          UNLOCK();
        } while (!bVar12);
      }
      if (*(uint *)(lVar8 + 0x18) < 2) goto LAB_1805a5812;
      uVar6 = ES3Internal_ES3TypeMgr__GetOrCreateES3Type__060006ea
                        (*(undefined8 *)(lVar8 + 0x28),0,0);
      bVar12 = DAT_182eb5d50 != 0;
      *(undefined8 *)(lVar7 + 0x38) = uVar6;
      if (bVar12) {
        uVar11 = (uint)(lVar7 + 0x38U >> 0xc);
        lVar8 = (ulonglong)((uVar11 & 0x1fffff) >> 6) * 8;
        do {
          uVar2 = *(ulonglong *)(&DAT_182f0c920 + lVar8);
          LOCK();
          bVar12 = uVar2 == *(ulonglong *)(&DAT_182f0c920 + lVar8);
          if (bVar12) {
            *(ulonglong *)(&DAT_182f0c920 + lVar8) = uVar2 | 1L << (uVar11 & 0x3f);
          }
          UNLOCK();
        } while (!bVar12);
      }
      if ((*(longlong *)(lVar7 + 0x30) == 0) || (*(longlong *)(lVar7 + 0x38) == 0)) {
        *(undefined1 *)(lVar7 + 0x28) = 1;
      }
      *(undefined1 *)(lVar7 + 0x23) = 1;
    }
    else {
LAB_1805a56d7:
      lVar7 = FUN_1802c43a0(uVar6);
      ES3Types_ES3CollectionType___ctor__060003e5(lVar7,param_1,0);
    }
  }
LAB_1805a56ed:
  if (lVar7 != 0) {
    lVar8 = *(longlong *)(lVar7 + 0x18);
    if (*(int *)(DAT_182d535d8 + 0xe0) == 0) {
      FUN_18035c820();
    }
    if ((lVar8 != 0) && (*(char *)(lVar7 + 0x28) == '\0')) {
      if (*(int *)(DAT_182d52ec0 + 0xe0) == 0) {
        FUN_18035c820();
      }
      ES3Internal_ES3TypeMgr__Add__060006ec(param_1,lVar7,0);
      return lVar7;
    }
    if (param_2 == '\0') {
      return 0;
    }
    uVar6 = thunk_FUN_1802f2810(&DAT_182d6a1a8);
    uVar6 = System_String__Format__0600021f(uVar6,param_1,0);
    uVar9 = thunk_FUN_1802f2810(&DAT_182d53260);
    uVar9 = thunk_FUN_1802c43a0(uVar9);
    FUN_18161d3f0(uVar9,uVar6,0);
    uVar6 = thunk_FUN_1802f2810(&DAT_182d6a1e0);
                    /* WARNING: Subroutine does not return */
    FUN_18031da90(uVar9,uVar6);
  }
LAB_1805a5788:
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

