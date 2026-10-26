// Ghidra pseudocode; not original source or compilable C.
// ev_432f0f8110a9f6fd9b83de60f4f8187d238b2f9c920336514ec2f9da64718194

longlong native_only_180755660__00000000(undefined8 param_1,longlong *param_2,longlong param_3)

{
  longlong lVar1;
  longlong lVar2;
  longlong lVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  
  if (*(longlong *)(param_3 + 0x38) == 0) {
    FUN_1802f2810(0x182d56230);
    LOCK();
    UNLOCK();
    FUN_1802f2810(&DAT_182d56220);
    LOCK();
    UNLOCK();
    if (*(longlong *)(param_3 + 0x38) == 0) {
      FUN_1803204f0(param_3);
    }
  }
  if (param_2 == (longlong *)0x0) {
    uVar4 = thunk_FUN_1802f2810(0x182d31de0);
    uVar5 = 0;
  }
  else {
    if ((char)param_2[5] == '\0') {
      if ((char)param_2[4] == '\0') {
        if (*(char *)((longlong)param_2 + 0x22) == '\0') {
          if (*(char *)((longlong)param_2 + 0x23) == '\0') {
            lVar1 = FUN_1800036a0(*(undefined8 *)(*(longlong *)(param_3 + 0x38) + 0x10),param_1,
                                  param_2);
            return lVar1;
          }
          if ((*(byte *)(*param_2 + 0x130) < *(byte *)(DAT_182d56220 + 0x130)) ||
             (*(longlong *)
               (*(longlong *)(*param_2 + 200) + -8 + (ulonglong)*(byte *)(DAT_182d56220 + 0x130) * 8
               ) != DAT_182d56220)) {
                    /* WARNING: Subroutine does not return */
            FUN_18031e210(param_2);
          }
          lVar2 = ES3Types_ES3DictionaryType__Read__060003f9(param_2,param_1,0);
          lVar1 = *(longlong *)(*(longlong *)(param_3 + 0x38) + 8);
          if ((*(byte *)(lVar1 + 0x135) & 1) == 0) {
            lVar1 = FUN_180320470(lVar1);
          }
          if (lVar2 != 0) {
            lVar3 = FUN_1802c42e0(lVar2,lVar1);
            if (lVar3 != 0) {
              return lVar3;
            }
                    /* WARNING: Subroutine does not return */
            FUN_18031e210(lVar2,lVar1);
          }
        }
        else {
          lVar1 = *param_2;
          if ((*(byte *)(lVar1 + 0x130) < *(byte *)(lRam0000000182d56230 + 0x130)) ||
             (*(longlong *)
               (*(longlong *)(lVar1 + 200) + -8 +
               (ulonglong)*(byte *)(lRam0000000182d56230 + 0x130) * 8) != lRam0000000182d56230)) {
                    /* WARNING: Subroutine does not return */
            FUN_18031e210(param_2);
          }
          lVar2 = (**(code **)(lVar1 + 0x1a8))(param_2,param_1,*(undefined8 *)(lVar1 + 0x1b0));
          lVar1 = *(longlong *)(*(longlong *)(param_3 + 0x38) + 8);
          if ((*(byte *)(lVar1 + 0x135) & 1) == 0) {
            lVar1 = FUN_180320470(lVar1);
          }
          if (lVar2 != 0) {
            lVar3 = FUN_1802c42e0(lVar2,lVar1);
            if (lVar3 != 0) {
              return lVar3;
            }
                    /* WARNING: Subroutine does not return */
            FUN_18031e210(lVar2,lVar1);
          }
        }
      }
      else {
        lVar2 = FUN_1800036a0(**(undefined8 **)(param_3 + 0x38),param_2,param_1);
        lVar1 = *(longlong *)(*(longlong *)(param_3 + 0x38) + 8);
        if ((*(byte *)(lVar1 + 0x135) & 1) == 0) {
          lVar1 = FUN_180320470(lVar1);
        }
        if (lVar2 != 0) {
          lVar3 = FUN_1802c42e0(lVar2,lVar1);
          if (lVar3 != 0) {
            return lVar3;
          }
                    /* WARNING: Subroutine does not return */
          FUN_18031e210(lVar2,lVar1);
        }
      }
      return 0;
    }
    uVar4 = thunk_FUN_1802f2810(0x182d31de0);
    FUN_1800039f0(param_2);
    uVar5 = FUN_180002bf0(3,param_2);
  }
  uVar6 = thunk_FUN_1802f2810(0x182d31df8);
  uVar5 = System_String__Concat__0600021c(uVar4,uVar5,uVar6,0);
  uVar4 = thunk_FUN_1802f2810(&DAT_182d53260);
  uVar4 = thunk_FUN_1802c43a0(uVar4);
  FUN_18161d3f0(uVar4,uVar5,0);
                    /* WARNING: Subroutine does not return */
  FUN_18031da90(uVar4,param_3);
}

