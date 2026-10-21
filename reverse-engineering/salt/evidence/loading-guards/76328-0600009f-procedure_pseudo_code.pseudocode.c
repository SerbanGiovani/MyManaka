// Ghidra pseudocode; not original source or compilable C.
// ev_93c4f564974c7b13967298a7fa041764d39b9a6490ab15a0d261edfbc2a18da4

void IKA9nt_Encrypter_EncrypterCore__ErrorCheck08__0600009f(undefined8 param_1,longlong param_2)

{
  undefined8 uVar1;
  int iVar2;
  undefined8 uVar3;
  
  if (param_2 == 0) {
                    /* WARNING: Subroutine does not return */
    FUN_18031dad0();
  }
  iVar2 = FUN_181630ca0(param_2 + 0x14,0x2f,*(undefined4 *)(param_2 + 0x10),0);
  if (-1 < iVar2) {
    iVar2 = FUN_181630ca0(param_2 + 0x14,0x2e,*(undefined4 *)(param_2 + 0x10),0);
    if (iVar2 < 0) {
      uVar1 = thunk_FUN_1802f2810(0x182d5bfb8);
      FUN_1800039e0(uVar1);
      uVar1 = thunk_FUN_1802f2810(0x182d64aa0);
      uVar3 = thunk_FUN_1802f2810(0x182d64a98);
      uVar1 = IKA9nt_Encrypter_EncrypterCore__MultiLangFormat__060000ba
                        (uVar3,uVar1,param_1,param_2,0);
      uVar3 = thunk_FUN_1802f2810(&DAT_182d53398);
      uVar3 = thunk_FUN_1802c43a0(uVar3);
      FUN_18165bfb0(uVar3,uVar1,0);
      uVar1 = thunk_FUN_1802f2810(0x182d64a90);
                    /* WARNING: Subroutine does not return */
      FUN_18031da90(uVar3,uVar1);
    }
  }
  return;
}

