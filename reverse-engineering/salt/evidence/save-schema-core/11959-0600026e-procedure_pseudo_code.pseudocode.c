// Ghidra pseudocode; not original source or compilable C.
// ev_6dabc380e9a8e958a110e2fa2abb7c03d8d26eddc66e9d489719564d52466cb3

void ES3Writer__Write__0600026e
               (longlong *param_1,longlong *param_2,longlong *param_3,undefined4 param_4)

{
  bool bVar1;
  char cVar2;
  longlong *plVar3;
  undefined8 uVar4;
  longlong lVar5;
  longlong lVar6;
  code *pcVar7;
  undefined8 uVar8;
  longlong *plVar9;
  undefined8 in_stack_ffffffffffffffd8;
  undefined4 uVar10;
  
  uVar10 = (undefined4)((ulonglong)in_stack_ffffffffffffffd8 >> 0x20);
  if (cRam0000000182eb75ad == '\0') {
    FUN_1802f2810(0x182d56230);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d56220);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d52c00);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d52ec0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d56208);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d561f0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d561d8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d561c0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d53aa8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d52e58);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d535d8);
    LOCK();
    UNLOCK();
    cRam0000000182eb75ad = '\x01';
  }
  uVar4 = DAT_182d561c0;
  if (param_2 == (longlong *)0x0) goto code_r0x0001803d674c;
  if (*(int *)(DAT_182d535d8 + 0xe0) == 0) {
    FUN_18035c820();
  }
  plVar3 = (longlong *)FUN_181638ed0(uVar4,0);
  uVar4 = FUN_1802c5ac0(*param_2 + 0x20);
  if (*(int *)(DAT_182d52c00 + 0xe0) == 0) {
    FUN_18035c820();
  }
  if (plVar3 == (longlong *)0x0) goto code_r0x0001803d6989;
  cVar2 = (**(code **)(*plVar3 + 0x288))(plVar3,uVar4,*(undefined8 *)(*plVar3 + 0x290));
  plVar3 = (longlong *)0x0;
  if (cVar2 != '\0') {
    if (*(int *)(DAT_182d53aa8 + 0xe0) == 0) {
      FUN_18035c820(DAT_182d53aa8);
    }
    if ((*(byte *)(*param_2 + 0x130) < *(byte *)(DAT_182d53aa8 + 0x130)) ||
       (bVar1 = true,
       *(longlong *)
        (*(longlong *)(*param_2 + 200) + -8 + (ulonglong)*(byte *)(DAT_182d53aa8 + 0x130) * 8) !=
       DAT_182d53aa8)) {
      bVar1 = false;
    }
    plVar9 = plVar3;
    if (bVar1) {
      plVar9 = param_2;
    }
    if (DAT_182ec12f3 == '\0') {
      FUN_1802f2810(&DAT_182d53aa8);
      LOCK();
      UNLOCK();
      DAT_182ec12f3 = '\x01';
    }
    if (*(int *)(DAT_182d53aa8 + 0xe0) == 0) {
      FUN_18035c820(DAT_182d53aa8);
    }
    if (DAT_182ec129b == '\0') {
      FUN_1802f2810(&DAT_182d53aa8);
      LOCK();
      UNLOCK();
      DAT_182ec129b = '\x01';
    }
    if (plVar9 != (longlong *)0x0) {
      if (*(int *)(DAT_182d53aa8 + 0xe0) == 0) {
        FUN_18035c820(DAT_182d53aa8);
      }
      if (plVar9[2] != 0) goto code_r0x0001803d63f0;
    }
code_r0x0001803d674c:
    pcVar7 = *(code **)(*param_1 + 0x188);
    uVar4 = *(undefined8 *)(*param_1 + 400);
    goto code_r0x0001803d675d;
  }
code_r0x0001803d63f0:
  uVar4 = DAT_182d52e58;
  if (param_3 == (longlong *)0x0) {
DAT_1803d6431:
    lVar6 = FUN_1802c5ac0(*param_2 + 0x20);
    if (*(int *)(DAT_182d52ec0 + 0xe0) == 0) {
      FUN_18035c820();
    }
    param_3 = (longlong *)ES3Internal_ES3TypeMgr__GetOrCreateES3Type__060006ea(lVar6,1,0);
    if (param_3 == (longlong *)0x0) {
      uVar4 = thunk_FUN_1802f2810(0x182d56198);
      if (lVar6 != 0) {
        FUN_1800039f0(lVar6);
        plVar3 = (longlong *)FUN_180002bf0(3,lVar6);
      }
      uVar8 = thunk_FUN_1802f2810(0x182d56180);
      uVar4 = System_String__Concat__0600021c(uVar4,plVar3,uVar8,0);
      uVar8 = thunk_FUN_1802f2810(&DAT_182d53260);
      uVar8 = thunk_FUN_1802c43a0(uVar8);
      FUN_18161d3f0(uVar8,uVar4,0);
      uVar4 = thunk_FUN_1802f2810(0x182d56168);
                    /* WARNING: Subroutine does not return */
      FUN_18031da90(uVar8,uVar4);
    }
    if ((*(char *)((longlong)param_3 + 0x22) == '\0') &&
       (*(char *)((longlong)param_3 + 0x23) == '\0')) {
      (**(code **)(*param_1 + 0x1b8))(param_1,0,*(undefined8 *)(*param_1 + 0x1c0));
      ES3Writer__WriteType__0600027c(param_1,lVar6,0);
      (**(code **)(*param_3 + 0x178))(param_3,param_2,param_1,*(undefined8 *)(*param_3 + 0x180));
      (**(code **)(*param_1 + 0x1c8))(param_1,0,*(undefined8 *)(*param_1 + 0x1d0));
      return;
    }
  }
  else {
    lVar6 = param_3[3];
    if (*(int *)(DAT_182d535d8 + 0xe0) == 0) {
      FUN_18035c820();
    }
    lVar5 = FUN_181638ed0(uVar4,0);
    if (lVar6 == lVar5) goto DAT_1803d6431;
  }
  uVar4 = uRam0000000182d561d8;
  if (param_3 == (longlong *)0x0) {
    uVar4 = thunk_FUN_1802f2810(&DAT_182d528c8);
    uVar4 = thunk_FUN_1802c43a0(uVar4);
    uVar8 = thunk_FUN_1802f2810(0x182d56150);
    FUN_1815c6a10(uVar4,uVar8,0);
    uVar8 = thunk_FUN_1802f2810(0x182d56168);
                    /* WARNING: Subroutine does not return */
    FUN_18031da90(uVar4,uVar8);
  }
  if ((char)param_3[5] != '\0') {
    if ((*(char *)((longlong)param_3 + 0x22) == '\0') &&
       (*(char *)((longlong)param_3 + 0x23) == '\0')) {
      FUN_1800039f0(param_3);
      lVar6 = param_3[3];
      uVar4 = thunk_FUN_1802f2810(0x182d56198);
      if (lVar6 != 0) {
        FUN_1800039f0(lVar6);
        plVar3 = (longlong *)FUN_180002bf0(3,lVar6);
      }
      uVar8 = thunk_FUN_1802f2810(0x182d56180);
      uVar4 = System_String__Concat__0600021c(uVar4,plVar3,uVar8,0);
      uVar8 = thunk_FUN_1802f2810(&DAT_182d53260);
      uVar8 = thunk_FUN_1802c43a0(uVar8);
      FUN_18161d3f0(uVar8,uVar4,0);
      uVar4 = thunk_FUN_1802f2810(0x182d56168);
                    /* WARNING: Subroutine does not return */
      FUN_18031da90(uVar8,uVar4);
    }
    FUN_1800039f0(param_3);
    lVar6 = param_3[3];
    if (lVar6 != 0) {
      FUN_1800039f0(lVar6);
      plVar3 = (longlong *)FUN_180002bf0(3,lVar6);
    }
    uVar4 = thunk_FUN_1802f2810(0x182d56140);
    uVar4 = System_String__Concat__0600021b(plVar3,uVar4,0);
    uVar8 = thunk_FUN_1802f2810(&DAT_182d53260);
    uVar8 = thunk_FUN_1802c43a0(uVar8);
    FUN_18161d3f0(uVar8,uVar4,0);
    uVar4 = thunk_FUN_1802f2810(0x182d56168);
                    /* WARNING: Subroutine does not return */
    FUN_18031da90(uVar8,uVar4);
  }
  if (((char)param_3[4] != '\0') || (*(char *)((longlong)param_3 + 0x25) != '\0')) {
    (**(code **)(*param_3 + 0x178))(param_3,param_2,param_1,*(undefined8 *)(*param_3 + 0x180));
    return;
  }
  if (*(char *)((longlong)param_3 + 0x22) == '\0') {
    if (*(char *)((longlong)param_3 + 0x23) == '\0') {
      lVar6 = param_3[3];
      if (*(int *)(DAT_182d535d8 + 0xe0) == 0) {
        FUN_18035c820();
      }
      lVar5 = FUN_181638ed0(uVar4,0);
      if (lVar6 == lVar5) {
        if (param_1[2] == 0) {
code_r0x0001803d6989:
                    /* WARNING: Subroutine does not return */
          FUN_18031dad0();
        }
        if ((*(byte *)(*param_3 + 0x130) < *(byte *)(lRam0000000182d56208 + 0x130)) ||
           (*(longlong *)
             (*(longlong *)(*param_3 + 200) + -8 +
             (ulonglong)*(byte *)(lRam0000000182d56208 + 0x130) * 8) != lRam0000000182d56208)) {
                    /* WARNING: Subroutine does not return */
          FUN_18031e210(param_3);
        }
        *(undefined1 *)(param_3 + 6) = *(undefined1 *)(param_1[2] + 0x48);
      }
      (**(code **)(*param_1 + 0x1b8))(param_1,0,*(undefined8 *)(*param_1 + 0x1c0));
      if (*(char *)((longlong)param_3 + 0x26) == '\0') {
        (**(code **)(*param_3 + 0x178))(param_3,param_2,param_1,*(undefined8 *)(*param_3 + 0x180));
      }
      else {
        if ((*(byte *)(*param_3 + 0x130) < *(byte *)(lRam0000000182d561f0 + 0x130)) ||
           (*(longlong *)
             (*(longlong *)(*param_3 + 200) + -8 +
             (ulonglong)*(byte *)(lRam0000000182d561f0 + 0x130) * 8) != lRam0000000182d561f0)) {
                    /* WARNING: Subroutine does not return */
          FUN_18031e210(param_3);
        }
        FUN_1800051e0(0xd,param_3,param_2,param_1,CONCAT44(uVar10,param_4));
      }
      (**(code **)(*param_1 + 0x1c8))(param_1,0,*(undefined8 *)(*param_1 + 0x1d0));
      return;
    }
    (**(code **)(*param_1 + 0x238))(param_1,*(undefined8 *)(*param_1 + 0x240));
    if ((*(byte *)(*param_3 + 0x130) < *(byte *)(DAT_182d56220 + 0x130)) ||
       (*(longlong *)
         (*(longlong *)(*param_3 + 200) + -8 + (ulonglong)*(byte *)(DAT_182d56220 + 0x130) * 8) !=
        DAT_182d56220)) {
                    /* WARNING: Subroutine does not return */
      FUN_18031e210(param_3);
    }
    ES3Types_ES3DictionaryType__Write__060003f6(param_3,param_2,param_1,param_4,0);
    pcVar7 = *(code **)(*param_1 + 0x248);
    uVar4 = *(undefined8 *)(*param_1 + 0x250);
  }
  else {
    (**(code **)(*param_1 + 0x1f8))(param_1,*(undefined8 *)(*param_1 + 0x200));
    if ((*(byte *)(*param_3 + 0x130) < *(byte *)(lRam0000000182d56230 + 0x130)) ||
       (*(longlong *)
         (*(longlong *)(*param_3 + 200) + -8 +
         (ulonglong)*(byte *)(lRam0000000182d56230 + 0x130) * 8) != lRam0000000182d56230)) {
                    /* WARNING: Subroutine does not return */
      FUN_18031e210(param_3);
    }
    FUN_1800051e0(9,param_3,param_2,param_1,CONCAT44(uVar10,param_4));
    pcVar7 = *(code **)(*param_1 + 0x208);
    uVar4 = *(undefined8 *)(*param_1 + 0x210);
  }
code_r0x0001803d675d:
  (*pcVar7)(param_1,uVar4);
  return;
}

