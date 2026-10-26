// Ghidra pseudocode; not original source or compilable C.
// ev_4a30f5853a6d080d6d3f0517abe381523ebd3f78bafe5737946913364f098c80

undefined8
ES3Writer__Create__06000280
          (longlong *param_1,longlong *param_2,undefined1 param_3,undefined1 param_4)

{
  longlong lVar1;
  longlong lVar2;
  undefined8 uVar3;
  
  if (DAT_182eb75b8 == '\0') {
    FUN_1802f2810(&DAT_182d55ef0);
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
  if (param_1 != (longlong *)0x0) {
    lVar1 = FUN_1802c5ac0(*param_1 + 0x20);
    lVar2 = DAT_182d55ee0;
    if (*(int *)(DAT_182d535d8 + 0xe0) == 0) {
      FUN_18035c820();
    }
    if (DAT_182ebb9aa == '\0') {
      FUN_1802f2810(&DAT_182d535d8);
      LOCK();
      UNLOCK();
      DAT_182ebb9aa = '\x01';
    }
    if (lVar2 == 0) {
      lVar2 = 0;
    }
    else {
      if (*(int *)(DAT_182d535d8 + 0xe0) == 0) {
        FUN_18035c820();
      }
      lVar2 = FUN_1803613f0(lVar2,1);
      lVar2 = FUN_1802c5ac0(lVar2 + 0x20);
    }
    if (lVar1 == lVar2) {
      if (param_2 != (longlong *)0x0) {
        param_2 = (longlong *)ES3Settings__Clone__060001bc(param_2,0);
        if (param_2 != (longlong *)0x0) {
          if ((*(byte *)(*param_2 + 0x130) < *(byte *)(DAT_182d534a8 + 0x130)) ||
             (*(longlong *)
               (*(longlong *)(*param_2 + 200) + -8 + (ulonglong)*(byte *)(DAT_182d534a8 + 0x130) * 8
               ) != DAT_182d534a8)) {
                    /* WARNING: Subroutine does not return */
            FUN_18031e210(param_2);
          }
          *(undefined4 *)(param_2 + 2) = 2;
          goto LAB_1803d8232;
        }
      }
    }
    else if (param_2 != (longlong *)0x0) {
LAB_1803d8232:
      if (*(int *)((longlong)param_2 + 0x34) == 0) {
        uVar3 = FUN_1802c43a0(DAT_182d55ef0);
        ES3Internal_ES3JSONWriter___ctor__0600072f(uVar3,param_1,param_2,param_3,param_4,0);
      }
      else {
        uVar3 = 0;
      }
      return uVar3;
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

