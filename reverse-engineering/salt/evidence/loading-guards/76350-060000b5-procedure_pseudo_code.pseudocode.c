// Ghidra pseudocode; not original source or compilable C.
// ev_dfd8b56f4c0225920ca0db6bc172b60c068739d6d26895678067ee3c0540fa5c

longlong IKA9nt_Encrypter_EncrypterCore__GetAssetBundlePathWinx86__060000b5(longlong param_1)

{
  longlong lVar1;
  longlong lVar2;
  longlong lVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  longlong lVar6;
  longlong lVar7;
  int iVar8;
  ulonglong uVar9;
  
  if (cRam0000000182ebaad5 == '\0') {
    FUN_1802f2810(0x182d5bfb8);
    LOCK();
    UNLOCK();
    cRam0000000182ebaad5 = '\x01';
  }
  if (param_1 == 0) {
                    /* WARNING: Subroutine does not return */
    FUN_18031dad0();
  }
  lVar2 = System_Int64__ToString__06000732(param_1 + 0x18,0);
  if (*(int *)(lRam0000000182d5bfb8 + 0xe0) == 0) {
    FUN_18035c820();
  }
  if (cRam0000000182ebaad6 == '\0') {
    FUN_1802f2810(0x182d5bfb8,0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d52780);
    LOCK();
    UNLOCK();
    cRam0000000182ebaad6 = '\x01';
  }
  if (*(int *)(lRam0000000182d5bfb8 + 0xe0) == 0) {
    FUN_18035c820();
  }
  if (cRam0000000182ebaad0 == '\0') {
    FUN_1802f2810(0x182d5bfb8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d52780);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d649d8);
    LOCK();
    UNLOCK();
    cRam0000000182ebaad0 = '\x01';
  }
  if (*(int *)(lRam0000000182d5bfb8 + 0xe0) == 0) {
    FUN_18035c820();
  }
  lVar7 = *(longlong *)(*(longlong *)(lRam0000000182d5bfb8 + 0xb8) + 0x38);
  if ((lVar7 == 0) || (*(int *)(lVar7 + 0x10) == 0)) {
    if (*(int *)(lRam0000000182d5bfb8 + 0xe0) == 0) {
      FUN_18035c820();
    }
    uVar4 = IKA9nt_Encrypter_EncrypterCore__GetBasePath__060000ae(0);
    lVar7 = System_String__Concat__0600021c(uVar4,lRam0000000182d52780,uRam0000000182d649d8,0);
  }
  else {
    if (*(int *)(lRam0000000182d5bfb8 + 0xe0) == 0) {
      FUN_18035c820();
    }
    lVar7 = *(longlong *)(*(longlong *)(lRam0000000182d5bfb8 + 0xb8) + 0x38);
  }
  lVar1 = lRam0000000182d52780;
  if ((lVar7 == 0) || (*(int *)(lVar7 + 0x10) == 0)) {
    lVar2 = System_String__Concat__0600021b(lRam0000000182d52780,lVar2,0,0);
    return lVar2;
  }
  if ((lRam0000000182d52780 == 0) || (*(int *)(lRam0000000182d52780 + 0x10) == 0)) {
    lVar2 = System_String__Concat__0600021b(lVar7,lVar2,0,0);
    return lVar2;
  }
  if ((lVar2 == 0) || (*(int *)(lVar2 + 0x10) == 0)) {
    lVar2 = System_String__Concat__0600021b(lVar7,lRam0000000182d52780,0,0);
    return lVar2;
  }
  lVar3 = FUN_180320ed0(*(int *)(lVar7 + 0x10) + *(int *)(lRam0000000182d52780 + 0x10) +
                        *(int *)(lVar2 + 0x10));
  if (lVar3 == 0) {
                    /* WARNING: Subroutine does not return */
    FUN_18031dad0();
  }
  if (*(int *)(lVar3 + 0x10) < *(int *)(lVar7 + 0x10)) {
    uVar4 = thunk_FUN_1802f2810(&DAT_182d52b48);
    uVar4 = thunk_FUN_1802c43a0(uVar4);
    FUN_181616e60(uVar4,0);
    uVar5 = thunk_FUN_1802f2810(&DAT_182d39fa0);
                    /* WARNING: Subroutine does not return */
    FUN_18031da90(uVar4,uVar5);
  }
  uVar9 = (ulonglong)(uint)(*(int *)(lVar7 + 0x10) * 2);
  if (((ulonglong)((lVar3 + 0x14) - (lVar7 + 0x14)) < uVar9) ||
     ((ulonglong)((lVar7 + 0x14) - (lVar3 + 0x14)) < uVar9)) {
    FUN_1803a8090();
  }
  else {
    FUN_18164e250();
  }
  if (*(int *)(lVar3 + 0x10) - *(int *)(lVar7 + 0x10) < *(int *)(lVar1 + 0x10)) {
    uVar4 = thunk_FUN_1802f2810(&DAT_182d52b48);
    uVar4 = thunk_FUN_1802c43a0(uVar4);
    FUN_181616e60(uVar4,0);
    uVar5 = thunk_FUN_1802f2810(&DAT_182d39fa0);
                    /* WARNING: Subroutine does not return */
    FUN_18031da90(uVar4,uVar5);
  }
  lVar6 = (longlong)*(int *)(lVar7 + 0x10) * 2 + 0x14 + lVar3;
  uVar9 = (ulonglong)(uint)(*(int *)(lVar1 + 0x10) * 2);
  if (((ulonglong)(lVar6 - (lVar1 + 0x14)) < uVar9) || ((ulonglong)((lVar1 + 0x14) - lVar6) < uVar9)
     ) {
    FUN_1803a8090();
  }
  else {
    FUN_18164e250();
  }
  iVar8 = *(int *)(lVar7 + 0x10) + *(int *)(lVar1 + 0x10);
  if (*(int *)(lVar2 + 0x10) <= *(int *)(lVar3 + 0x10) - iVar8) {
    lVar7 = (longlong)iVar8 * 2 + 0x14 + lVar3;
    uVar9 = (ulonglong)(uint)(*(int *)(lVar2 + 0x10) * 2);
    if (((ulonglong)(lVar7 - (lVar2 + 0x14)) < uVar9) ||
       ((ulonglong)((lVar2 + 0x14) - lVar7) < uVar9)) {
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

