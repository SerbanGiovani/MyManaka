// Ghidra pseudocode; not original source or compilable C.
// ev_952fe55f5f8ab5c9f3a8a8c72808fabc54a1c3bf234576c9d78cc77eae0a0c67

void IKA9nt_Encrypter_EncrypterCore__ErrorCheck04__0600009b(undefined8 param_1)

{
  int iVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  
  if (cRam0000000182ebaabc == '\0') {
    FUN_1802f2810(0x182d64ae0);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5bfb8);
    LOCK();
    UNLOCK();
    cRam0000000182ebaabc = '\x01';
  }
  if (*(int *)(lRam0000000182d5bfb8 + 0xe0) == 0) {
    FUN_18035c820(lRam0000000182d5bfb8);
  }
  if (**(longlong **)(lRam0000000182d5bfb8 + 0xb8) != 0) {
    iVar1 = FUN_180e9f040(**(longlong **)(lRam0000000182d5bfb8 + 0xb8),param_1,
                          *(undefined8 *)
                           (*(longlong *)(*(longlong *)(lRam0000000182d64ae0 + 0x20) + 0xc0) + 0xf8)
                         );
    if (-1 < iVar1) {
      return;
    }
    uVar2 = thunk_FUN_1802f2810(0x182d64ae8);
    uVar2 = System_String__Format__0600021f(uVar2,param_1,0);
    uVar3 = thunk_FUN_1802f2810(0x182d64a68);
    uVar3 = System_String__Format__0600021f(uVar3,param_1,0);
    uVar4 = thunk_FUN_1802f2810(0x182d5bfb8);
    FUN_1800039e0(uVar4);
    uVar2 = IKA9nt_Encrypter_EncrypterCore__MultiLang__060000b8(uVar2,uVar3,0);
    uVar3 = thunk_FUN_1802f2810(&DAT_182d53398);
    uVar3 = thunk_FUN_1802c43a0(uVar3);
    FUN_18165bfb0(uVar3,uVar2,0);
    uVar2 = thunk_FUN_1802f2810(0x182d64a60);
                    /* WARNING: Subroutine does not return */
    FUN_18031da90(uVar3,uVar2);
  }
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

