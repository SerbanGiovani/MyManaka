// Ghidra pseudocode; not original source or compilable C.
// ev_9374653e28a86b5de96730db60db72947528f6990ad95881f0ba36e754ff205a

void ES3Types_ES3ReflectedType__Write__060004b6
               (longlong param_1,longlong *param_2,longlong *param_3)

{
  undefined8 uVar1;
  char cVar2;
  longlong lVar3;
  longlong lVar4;
  longlong lVar5;
  longlong *plVar6;
  uint uVar7;
  bool bVar8;
  
  if (cRam0000000182eb7f17 == '\0') {
    FUN_1802f2810(&DAT_182d52c00);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d52ec0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d561c0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d53aa8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d535d8);
    LOCK();
    UNLOCK();
    cRam0000000182eb7f17 = '\x01';
  }
  if (param_2 == (longlong *)0x0) {
    if (param_3 != (longlong *)0x0) {
      (**(code **)(*param_3 + 0x188))(param_3,*(undefined8 *)(*param_3 + 400));
      return;
    }
  }
  else {
    if ((*(byte *)(*param_2 + 0x130) < *(byte *)(DAT_182d53aa8 + 0x130)) ||
       (*(longlong *)
         (*(longlong *)(*param_2 + 200) + -8 + (ulonglong)*(byte *)(DAT_182d53aa8 + 0x130) * 8) !=
        DAT_182d53aa8)) {
      bVar8 = false;
    }
    else {
      bVar8 = true;
    }
    plVar6 = (longlong *)0x0;
    if (bVar8) {
      plVar6 = param_2;
    }
    if (*(int *)(DAT_182d53aa8 + 0xe0) == 0) {
      FUN_18035c820(DAT_182d53aa8);
    }
    if (DAT_182ec12f4 == '\0') {
      FUN_1802f2810(&DAT_182d53aa8);
      LOCK();
      UNLOCK();
      DAT_182ec12f4 = '\x01';
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
    if (plVar6 == (longlong *)0x0) {
      bVar8 = false;
    }
    else {
      if (*(int *)(DAT_182d53aa8 + 0xe0) == 0) {
        FUN_18035c820(DAT_182d53aa8);
      }
      bVar8 = plVar6[2] != 0;
    }
    lVar3 = FUN_1802c5ac0(*param_2 + 0x20);
    lVar4 = *(longlong *)(param_1 + 0x18);
    if (*(int *)(DAT_182d535d8 + 0xe0) == 0) {
      FUN_18035c820();
    }
    if (lVar3 == lVar4) {
      if (bVar8) {
        if (param_3 == (longlong *)0x0) goto code_r0x0001805599ce;
        (**(code **)(*param_3 + 0x3f8))(param_3,plVar6,*(undefined8 *)(*param_3 + 0x400));
      }
      if (*(longlong *)(param_1 + 0x10) == 0) {
        if ((param_3 == (longlong *)0x0) || (param_3[2] == 0)) goto code_r0x0001805599ce;
        ES3Types_ES3Type__GetMembers__06000447(param_1,*(undefined1 *)(param_3[2] + 0x4b),0,0);
      }
      lVar4 = *(longlong *)(param_1 + 0x10);
      uVar7 = 0;
      if (lVar4 != 0) {
        lVar3 = 0x20;
        do {
          lVar5 = DAT_182d561c0;
          if (*(int *)(lVar4 + 0x18) <= (int)uVar7) {
            return;
          }
          lVar4 = *(longlong *)(param_1 + 0x10);
          if (lVar4 == 0) break;
          if (*(uint *)(lVar4 + 0x18) <= uVar7) {
                    /* WARNING: Subroutine does not return */
            FUN_18031dae0();
          }
          lVar4 = *(longlong *)(lVar3 + lVar4);
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
          if (lVar4 == 0) break;
          uVar1 = *(undefined8 *)(lVar4 + 0x18);
          if (*(int *)(DAT_182d52c00 + 0xe0) == 0) {
            FUN_18035c820();
          }
          if (plVar6 == (longlong *)0x0) break;
          cVar2 = (**(code **)(*plVar6 + 0x288))(plVar6,uVar1,*(undefined8 *)(*plVar6 + 0x290));
          if (cVar2 == '\0') {
            ES3ReflectedMember__GetValue__06000687(lVar4 + 0x28,param_2,0);
            uVar1 = *(undefined8 *)(lVar4 + 0x18);
            if (*(int *)(DAT_182d52ec0 + 0xe0) == 0) {
              FUN_18035c820();
            }
            ES3Internal_ES3TypeMgr__GetOrCreateES3Type__060006ea(uVar1,1,0);
            if (param_3 == (longlong *)0x0) break;
            FUN_1800051a0();
          }
          else {
            plVar6 = (longlong *)ES3ReflectedMember__GetValue__06000687(lVar4 + 0x28,param_2,0);
            if (plVar6 != (longlong *)0x0) {
              if ((*(byte *)(*plVar6 + 0x130) < *(byte *)(DAT_182d53aa8 + 0x130)) ||
                 (*(longlong *)
                   (*(longlong *)(*plVar6 + 200) + -8 +
                   (ulonglong)*(byte *)(DAT_182d53aa8 + 0x130) * 8) != DAT_182d53aa8)) {
                    /* WARNING: Subroutine does not return */
                FUN_18031e210(plVar6);
              }
            }
            if (param_3 == (longlong *)0x0) break;
            (**(code **)(*param_3 + 0x458))
                      (param_3,*(undefined8 *)(lVar4 + 0x10),plVar6,
                       *(undefined8 *)(*param_3 + 0x460));
          }
          lVar4 = *(longlong *)(param_1 + 0x10);
          uVar7 = uVar7 + 1;
          lVar3 = lVar3 + 8;
        } while (lVar4 != 0);
      }
    }
    else if (param_3 != (longlong *)0x0) {
      ES3Writer__WriteType__0600027c(param_3,lVar3,0);
      if (*(int *)(DAT_182d52ec0 + 0xe0) == 0) {
        FUN_18035c820();
      }
      plVar6 = (longlong *)ES3Internal_ES3TypeMgr__GetOrCreateES3Type__060006ea(lVar3,1,0);
      if (plVar6 != (longlong *)0x0) {
        (**(code **)(*plVar6 + 0x178))(plVar6,param_2,param_3,*(undefined8 *)(*plVar6 + 0x180));
        return;
      }
    }
  }
code_r0x0001805599ce:
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

