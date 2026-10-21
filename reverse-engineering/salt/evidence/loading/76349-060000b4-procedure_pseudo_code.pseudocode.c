// Ghidra pseudocode; not original source or compilable C.
// ev_dd9eb6a74006fdc4ac8d4321b5f8e67cfd15e7ea0437135f8a474a0f65c995db

longlong IKA9nt_Encrypter_EncrypterCore__GetAssetBundlePath__060000b4
                   (longlong param_1,longlong param_2)

{
  longlong lVar1;
  longlong lVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  longlong lVar5;
  longlong lVar6;
  int iVar7;
  ulonglong uVar8;
  
  if (cRam0000000182ebaad4 == '\0') {
    FUN_1802f2810(0x182d5bfb8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d52780);
    LOCK();
    UNLOCK();
    cRam0000000182ebaad4 = '\x01';
  }
  if (*(int *)(lRam0000000182d5bfb8 + 0xe0) == 0) {
    FUN_18035c820();
  }
  lVar1 = IKA9nt_Encrypter_EncrypterCore__GetPlatformPath__060000af(0);
  lVar6 = lRam0000000182d52780;
  lVar2 = *(longlong *)(*(longlong *)(lRam0000000182d5bfb8 + 0xb8) + 0x18);
  if (lVar2 != 0) {
    if (*(int *)(lVar2 + 0x20) == 0) {
      if (param_1 == 0) goto code_r0x00018143f047;
      param_2 = System_Int64__ToString__06000732(param_1 + 0x18,0);
    }
    if ((lVar1 == 0) || (*(int *)(lVar1 + 0x10) == 0)) {
      lVar2 = System_String__Concat__0600021b(lVar6,param_2,0,0);
      return lVar2;
    }
    if ((lVar6 == 0) || (*(int *)(lVar6 + 0x10) == 0)) {
      lVar2 = System_String__Concat__0600021b(lVar1,param_2,0,0);
      return lVar2;
    }
    if ((param_2 == 0) || (*(int *)(param_2 + 0x10) == 0)) {
      lVar2 = System_String__Concat__0600021b(lVar1,lVar6,0,0);
      return lVar2;
    }
    lVar2 = FUN_180320ed0(*(int *)(lVar1 + 0x10) + *(int *)(lVar6 + 0x10) + *(int *)(param_2 + 0x10)
                         );
    if (lVar2 == 0) {
                    /* WARNING: Subroutine does not return */
      FUN_18031dad0();
    }
    if (*(int *)(lVar1 + 0x10) <= *(int *)(lVar2 + 0x10)) {
      uVar8 = (ulonglong)(uint)(*(int *)(lVar1 + 0x10) * 2);
      if (((ulonglong)((lVar2 + 0x14) - (lVar1 + 0x14)) < uVar8) ||
         ((ulonglong)((lVar1 + 0x14) - (lVar2 + 0x14)) < uVar8)) {
        FUN_1803a8090();
      }
      else {
        FUN_18164e250();
      }
      if (*(int *)(lVar2 + 0x10) - *(int *)(lVar1 + 0x10) < *(int *)(lVar6 + 0x10)) {
        uVar3 = thunk_FUN_1802f2810(&DAT_182d52b48);
        uVar3 = thunk_FUN_1802c43a0(uVar3);
        FUN_181616e60(uVar3,0);
        uVar4 = thunk_FUN_1802f2810(&DAT_182d39fa0);
                    /* WARNING: Subroutine does not return */
        FUN_18031da90(uVar3,uVar4);
      }
      lVar5 = (longlong)*(int *)(lVar1 + 0x10) * 2 + 0x14 + lVar2;
      uVar8 = (ulonglong)(uint)(*(int *)(lVar6 + 0x10) * 2);
      if (((ulonglong)(lVar5 - (lVar6 + 0x14)) < uVar8) ||
         ((ulonglong)((lVar6 + 0x14) - lVar5) < uVar8)) {
        FUN_1803a8090();
      }
      else {
        FUN_18164e250();
      }
      iVar7 = *(int *)(lVar1 + 0x10) + *(int *)(lVar6 + 0x10);
      if (*(int *)(param_2 + 0x10) <= *(int *)(lVar2 + 0x10) - iVar7) {
        lVar6 = (longlong)iVar7 * 2 + 0x14 + lVar2;
        uVar8 = (ulonglong)(uint)(*(int *)(param_2 + 0x10) * 2);
        if (((ulonglong)(lVar6 - (param_2 + 0x14)) < uVar8) ||
           ((ulonglong)((param_2 + 0x14) - lVar6) < uVar8)) {
          FUN_1803a8090();
        }
        else {
          FUN_18164e250();
        }
        return lVar2;
      }
      uVar3 = thunk_FUN_1802f2810(&DAT_182d52b48);
      uVar3 = thunk_FUN_1802c43a0(uVar3);
      FUN_181616e60(uVar3,0);
      uVar4 = thunk_FUN_1802f2810(&DAT_182d39fa0);
                    /* WARNING: Subroutine does not return */
      FUN_18031da90(uVar3,uVar4);
    }
    uVar3 = thunk_FUN_1802f2810(&DAT_182d52b48);
    uVar3 = thunk_FUN_1802c43a0(uVar3);
    FUN_181616e60(uVar3,0);
    uVar4 = thunk_FUN_1802f2810(&DAT_182d39fa0);
                    /* WARNING: Subroutine does not return */
    FUN_18031da90(uVar3,uVar4);
  }
code_r0x00018143f047:
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

