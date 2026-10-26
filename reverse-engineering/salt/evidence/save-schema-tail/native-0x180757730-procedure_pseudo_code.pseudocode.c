// Ghidra pseudocode; not original source or compilable C.
// ev_675af73ec8da4ed67c9fc4b45e81fab78d51a327e83012606cf72978fdbee3fc

void native_only_180757730__00000000
               (undefined8 param_1,undefined8 param_2,longlong *param_3,longlong param_4)

{
  longlong lVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  
  if (*(longlong *)(param_4 + 0x38) == 0) {
    FUN_1802f2810(0x182d56230);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d56220);
    LOCK();
    UNLOCK();
    if (*(longlong *)(param_4 + 0x38) == 0) {
      FUN_1803204f0(param_4);
    }
  }
  if ((param_3 != (longlong *)0x0) && ((char)param_3[5] == '\0')) {
    if (*(char *)((longlong)param_3 + 0x22) == '\0') {
      if (*(char *)((longlong)param_3 + 0x23) == '\0') {
        FUN_180007d40(**(undefined8 **)(param_4 + 0x38),param_1,param_2,param_3);
      }
      else {
        if ((*(byte *)(*param_3 + 0x130) < *(byte *)(DAT_182d56220 + 0x130)) ||
           (*(longlong *)
             (*(longlong *)(*param_3 + 200) + -8 + (ulonglong)*(byte *)(DAT_182d56220 + 0x130) * 8)
            != DAT_182d56220)) {
                    /* WARNING: Subroutine does not return */
          FUN_18031e210(param_3);
        }
        ES3Types_ES3DictionaryType__ReadInto__060003fa(param_3,param_1,param_2,0);
      }
    }
    else {
      lVar1 = *param_3;
      if ((*(byte *)(lVar1 + 0x130) < *(byte *)(lRam0000000182d56230 + 0x130)) ||
         (*(longlong *)
           (*(longlong *)(lVar1 + 200) + -8 + (ulonglong)*(byte *)(lRam0000000182d56230 + 0x130) * 8
           ) != lRam0000000182d56230)) {
                    /* WARNING: Subroutine does not return */
        FUN_18031e210(param_3);
      }
      (**(code **)(lVar1 + 0x1b8))(param_3,param_1,param_2,*(undefined8 *)(lVar1 + 0x1c0));
    }
    return;
  }
  FUN_1800039f0(param_2);
  lVar1 = FUN_181636e20(param_2,0);
  if (lVar1 == 0) {
    uVar3 = 0;
    uVar2 = thunk_FUN_1802f2810(0x182d31de0);
  }
  else {
    uVar2 = thunk_FUN_1802f2810(0x182d31de0);
    FUN_1800039f0(lVar1);
    uVar3 = FUN_180002bf0(3,lVar1);
  }
  uVar4 = thunk_FUN_1802f2810(0x182d31df8);
  uVar2 = System_String__Concat__0600021c(uVar2,uVar3,uVar4,0);
  uVar3 = thunk_FUN_1802f2810(&DAT_182d53260);
  uVar3 = thunk_FUN_1802c43a0(uVar3);
  FUN_18161d3f0(uVar3,uVar2,0);
                    /* WARNING: Subroutine does not return */
  FUN_18031da90(uVar3,param_4);
}

