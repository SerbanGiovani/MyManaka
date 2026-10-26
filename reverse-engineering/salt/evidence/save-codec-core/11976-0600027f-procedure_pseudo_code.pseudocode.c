// Ghidra pseudocode; not original source or compilable C.
// ev_411b9ee43f5ff2e8db3cfa5417d80271442a3a43ebf1fc8d261899965d86e150

undefined8
ES3Writer__Create__0600027f(longlong *param_1,undefined1 param_2,undefined1 param_3,uint param_4)

{
  longlong *plVar1;
  longlong lVar2;
  longlong lVar3;
  undefined8 uVar4;
  
  plVar1 = (longlong *)ES3Internal_ES3Stream__CreateStream__060006e5(param_1,(param_4 & 0xff) + 1,0)
  ;
  if (plVar1 == (longlong *)0x0) {
    return 0;
  }
  if (DAT_182eb75b8 == '\0') {
    FUN_1802f2810(&DAT_182d55ef0,param_1,param_2);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d534a8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d55ee0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d535d8);
    LOCK();
    UNLOCK();
    DAT_182eb75b8 = '\x01';
  }
  if (plVar1 != (longlong *)0x0) {
    lVar2 = FUN_1802c5ac0(*plVar1 + 0x20);
    lVar3 = DAT_182d55ee0;
    if (*(int *)(DAT_182d535d8 + 0xe0) == 0) {
      FUN_18035c820();
    }
    if (DAT_182ebb9aa == '\0') {
      FUN_1802f2810(&DAT_182d535d8);
      LOCK();
      UNLOCK();
      DAT_182ebb9aa = '\x01';
    }
    if (lVar3 == 0) {
      lVar3 = 0;
    }
    else {
      if (*(int *)(DAT_182d535d8 + 0xe0) == 0) {
        FUN_18035c820();
      }
      lVar3 = FUN_1803613f0(lVar3,1);
      lVar3 = FUN_1802c5ac0(lVar3 + 0x20);
    }
    if (lVar2 == lVar3) {
      if (param_1 != (longlong *)0x0) {
        param_1 = (longlong *)ES3Settings__Clone__060001bc(param_1,0);
        if (param_1 != (longlong *)0x0) {
          if ((*(byte *)(*param_1 + 0x130) < *(byte *)(DAT_182d534a8 + 0x130)) ||
             (*(longlong *)
               (*(longlong *)(*param_1 + 200) + -8 + (ulonglong)*(byte *)(DAT_182d534a8 + 0x130) * 8
               ) != DAT_182d534a8)) {
                    /* WARNING: Subroutine does not return */
            FUN_18031e210(param_1);
          }
          *(undefined4 *)(param_1 + 2) = 2;
          goto LAB_1803d8232;
        }
      }
    }
    else if (param_1 != (longlong *)0x0) {
LAB_1803d8232:
      if (*(int *)((longlong)param_1 + 0x34) == 0) {
        uVar4 = FUN_1802c43a0(DAT_182d55ef0);
        ES3Internal_ES3JSONWriter___ctor__0600072f(uVar4,plVar1,param_1,param_2,param_3,0);
      }
      else {
        uVar4 = 0;
      }
      return uVar4;
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

