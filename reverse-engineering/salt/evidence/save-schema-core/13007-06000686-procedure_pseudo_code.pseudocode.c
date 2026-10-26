// Ghidra pseudocode; not original source or compilable C.
// ev_25365dbcab6b766efe6b6227a3b7e744712bf0b0ca28a9c271f28ebb181eb286

void ES3ReflectedMember__SetValue__06000686(longlong *param_1,undefined8 param_2,undefined8 param_3)

{
  undefined8 uVar1;
  
  if ((char)param_1[2] == '\0') {
    param_1 = (longlong *)*param_1;
    if (param_1 != (longlong *)0x0) {
      if (DAT_182ebb264 == '\0') {
        FUN_1802f2810(&DAT_182d535d8,param_2,param_3,0);
        LOCK();
        UNLOCK();
        DAT_182ebb264 = '\x01';
      }
      if (*(int *)(DAT_182d535d8 + 0xe0) == 0) {
        FUN_18035c820();
      }
      uVar1 = FUN_181638da0(0);
      (**(code **)(*param_1 + 0x2e8))
                (param_1,param_2,param_3,0,uVar1,0,*(undefined8 *)(*param_1 + 0x2f0));
      return;
    }
  }
  else if ((longlong *)param_1[1] != (longlong *)0x0) {
    (**(code **)(*(longlong *)param_1[1] + 0x2f8))();
    return;
  }
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

