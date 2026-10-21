// Ghidra pseudocode; not original source or compilable C.
// ev_c03019b212e9eaad62f8832ab607a670a9c266aa7ef6f73cdc8bcbb104f143e8

void IKA9nt_Encrypter_EncrypterCore__ErrorCheck01__06000097(undefined8 param_1)

{
  longlong lVar1;
  int iVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  
  if (cRam0000000182ebaab9 == '\0') {
    FUN_1802f2810(0x182d64be8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d64c10);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5bfb8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d53aa8);
    LOCK();
    UNLOCK();
    cRam0000000182ebaab9 = '\x01';
  }
  if (*(int *)(lRam0000000182d5bfb8 + 0xe0) == 0) {
    FUN_18035c820();
  }
  IKA9nt_Encrypter_EncrypterCore__SetStaticVariants__06000070(0);
  lVar1 = *(longlong *)(*(longlong *)(lRam0000000182d5bfb8 + 0xb8) + 0x18);
  if (*(int *)(lRam0000000182d53aa8 + 0xe0) == 0) {
    FUN_18035c820();
  }
  if (cRam0000000182ec12f3 == '\0') {
    FUN_1802f2810(0x182d53aa8);
    LOCK();
    UNLOCK();
    cRam0000000182ec12f3 = '\x01';
  }
  if (*(int *)(lRam0000000182d53aa8 + 0xe0) == 0) {
    FUN_18035c820();
  }
  if (cRam0000000182ec129b == '\0') {
    FUN_1802f2810(0x182d53aa8);
    LOCK();
    UNLOCK();
    cRam0000000182ec129b = '\x01';
  }
  if (lVar1 != 0) {
    if (*(int *)(lRam0000000182d53aa8 + 0xe0) == 0) {
      FUN_18035c820();
    }
    if (*(longlong *)(lVar1 + 0x10) != 0) {
      if (*(int *)(lRam0000000182d5bfb8 + 0xe0) == 0) {
        FUN_18035c820();
      }
      lVar1 = *(longlong *)(*(longlong *)(lRam0000000182d5bfb8 + 0xb8) + 0x18);
      if ((lVar1 != 0) && (lVar1 = *(longlong *)(lVar1 + 0x28), lVar1 != 0)) {
        iVar2 = FUN_180e9f040(lVar1,param_1,
                              *(undefined8 *)
                               (*(longlong *)(*(longlong *)(lRam0000000182d64be8 + 0x20) + 0xc0) +
                               0xf8));
        if (iVar2 < 0) {
          if (*(int *)(lRam0000000182d5bfb8 + 0xe0) == 0) {
            FUN_18035c820(lRam0000000182d5bfb8);
          }
          lVar1 = *(longlong *)(*(longlong *)(lRam0000000182d5bfb8 + 0xb8) + 0x10);
          if (lVar1 == 0) goto code_r0x00018143c2df;
          iVar2 = FUN_180e9f040(lVar1,param_1,
                                *(undefined8 *)
                                 (*(longlong *)(*(longlong *)(lRam0000000182d64c10 + 0x20) + 0xc0) +
                                 0xf8));
          if (iVar2 < 0) {
            uVar3 = thunk_FUN_1802f2810(0x182d64ab0);
            uVar3 = System_String__Format__0600021f(uVar3,param_1,0);
            uVar4 = thunk_FUN_1802f2810(0x182d64aa8);
            uVar4 = System_String__Format__0600021f(uVar4,param_1,0);
            uVar5 = thunk_FUN_1802f2810(0x182d5bfb8);
            FUN_1800039e0(uVar5);
            uVar3 = IKA9nt_Encrypter_EncrypterCore__MultiLang__060000b8(uVar3,uVar4,0);
            uVar4 = thunk_FUN_1802f2810(&DAT_182d53398);
            uVar4 = thunk_FUN_1802c43a0(uVar4);
            FUN_18165bfb0(uVar4,uVar3,0);
            uVar3 = thunk_FUN_1802f2810(0x182d64ab8);
                    /* WARNING: Subroutine does not return */
            FUN_18031da90(uVar4,uVar3);
          }
        }
        return;
      }
code_r0x00018143c2df:
                    /* WARNING: Subroutine does not return */
      FUN_18031dad0();
    }
  }
  uVar3 = thunk_FUN_1802f2810(0x182d5bfb8);
  FUN_1800039e0(uVar3);
  uVar3 = thunk_FUN_1802f2810(0x182d64b20);
  uVar4 = thunk_FUN_1802f2810(0x182d64b18);
  uVar3 = IKA9nt_Encrypter_EncrypterCore__MultiLang__060000b8(uVar4,uVar3,0);
  uVar4 = thunk_FUN_1802f2810(&DAT_182d53398);
  uVar4 = thunk_FUN_1802c43a0(uVar4);
  FUN_18165bfb0(uVar4,uVar3,0);
  uVar3 = thunk_FUN_1802f2810(0x182d64ab8);
                    /* WARNING: Subroutine does not return */
  FUN_18031da90(uVar4,uVar3);
}

