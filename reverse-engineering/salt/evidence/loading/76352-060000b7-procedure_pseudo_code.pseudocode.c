// Ghidra pseudocode; not original source or compilable C.
// ev_1a532c092724e16fce29377893d163673a33cc68a1f1ea410789ade28095db6b

longlong IKA9nt_Encrypter_EncrypterCore__GetFullAssetPath__060000b7
                   (longlong param_1,undefined8 param_2,longlong param_3)

{
  longlong lVar1;
  int iVar2;
  longlong lVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  longlong lVar6;
  longlong lVar7;
  ulonglong uVar8;
  
  if (cRam0000000182ebaad7 == '\0') {
    FUN_1802f2810(0x182d52780);
    LOCK();
    UNLOCK();
    cRam0000000182ebaad7 = '\x01';
  }
  if (param_3 != 0) {
    iVar2 = FUN_181630ca0(param_3 + 0x14,0x2f,*(undefined4 *)(param_3 + 0x10),0);
    lVar7 = lRam0000000182d52780;
    if (iVar2 < 0) {
      return param_3;
    }
    if (param_1 != 0) {
      lVar1 = *(longlong *)(param_1 + 0x10);
      if ((lVar1 == 0) || (*(int *)(lVar1 + 0x10) == 0)) {
        lVar7 = System_String__Concat__0600021b(lRam0000000182d52780,param_3,0,0);
        return lVar7;
      }
      if ((lRam0000000182d52780 == 0) || (*(int *)(lRam0000000182d52780 + 0x10) == 0)) {
        lVar7 = System_String__Concat__0600021b(lVar1,param_3,0,0);
        return lVar7;
      }
      if ((param_3 == 0) || (*(int *)(param_3 + 0x10) == 0)) {
        lVar7 = System_String__Concat__0600021b(lVar1,lRam0000000182d52780,0,0);
        return lVar7;
      }
      lVar3 = FUN_180320ed0(*(int *)(lVar1 + 0x10) + *(int *)(lRam0000000182d52780 + 0x10) +
                            *(int *)(param_3 + 0x10));
      if (lVar3 == 0) {
                    /* WARNING: Subroutine does not return */
        FUN_18031dad0();
      }
      if (*(int *)(lVar1 + 0x10) <= *(int *)(lVar3 + 0x10)) {
        uVar8 = (ulonglong)(uint)(*(int *)(lVar1 + 0x10) * 2);
        if (((ulonglong)((lVar3 + 0x14) - (lVar1 + 0x14)) < uVar8) ||
           ((ulonglong)((lVar1 + 0x14) - (lVar3 + 0x14)) < uVar8)) {
          FUN_1803a8090();
        }
        else {
          FUN_18164e250();
        }
        if (*(int *)(lVar3 + 0x10) - *(int *)(lVar1 + 0x10) < *(int *)(lVar7 + 0x10)) {
          uVar4 = thunk_FUN_1802f2810(&DAT_182d52b48);
          uVar4 = thunk_FUN_1802c43a0(uVar4);
          FUN_181616e60(uVar4,0);
          uVar5 = thunk_FUN_1802f2810(&DAT_182d39fa0);
                    /* WARNING: Subroutine does not return */
          FUN_18031da90(uVar4,uVar5);
        }
        lVar6 = (longlong)*(int *)(lVar1 + 0x10) * 2 + 0x14 + lVar3;
        uVar8 = (ulonglong)(uint)(*(int *)(lVar7 + 0x10) * 2);
        if (((ulonglong)(lVar6 - (lVar7 + 0x14)) < uVar8) ||
           ((ulonglong)((lVar7 + 0x14) - lVar6) < uVar8)) {
          FUN_1803a8090();
        }
        else {
          FUN_18164e250();
        }
        iVar2 = *(int *)(lVar1 + 0x10) + *(int *)(lVar7 + 0x10);
        if (*(int *)(param_3 + 0x10) <= *(int *)(lVar3 + 0x10) - iVar2) {
          lVar7 = (longlong)iVar2 * 2 + 0x14 + lVar3;
          uVar8 = (ulonglong)(uint)(*(int *)(param_3 + 0x10) * 2);
          if (((ulonglong)(lVar7 - (param_3 + 0x14)) < uVar8) ||
             ((ulonglong)((param_3 + 0x14) - lVar7) < uVar8)) {
            FUN_1803a8090();
          }
          else {
            FUN_18164e250();
          }
          return lVar3;
        }
        uVar4 = thunk_FUN_1802f2810(&DAT_182d52b48);
        uVar4 = thunk_FUN_1802c43a0(uVar4);
        FUN_181616e60(uVar4,0);
        uVar5 = thunk_FUN_1802f2810(&DAT_182d39fa0);
                    /* WARNING: Subroutine does not return */
        FUN_18031da90(uVar4,uVar5);
      }
      uVar4 = thunk_FUN_1802f2810(&DAT_182d52b48);
      uVar4 = thunk_FUN_1802c43a0(uVar4);
      FUN_181616e60(uVar4,0);
      uVar5 = thunk_FUN_1802f2810(&DAT_182d39fa0);
                    /* WARNING: Subroutine does not return */
      FUN_18031da90(uVar4,uVar5);
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

