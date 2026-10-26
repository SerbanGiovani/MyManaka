// Ghidra pseudocode; not original source or compilable C.
// ev_86972c91087940065d53c3cc70025595a4611f8c7cbd4543a6d30a2a9c38a33a

undefined8
System_Security_Cryptography_Rfc2898DeriveBytes__GetBytes__06001565(longlong param_1,int param_2)

{
  undefined8 uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  int iVar4;
  int iVar5;
  
  if (cRam0000000182ebae64 == '\0') {
    FUN_1802f2810(&DAT_182d53428);
    LOCK();
    UNLOCK();
    cRam0000000182ebae64 = '\x01';
  }
  if (param_2 < 1) {
    uVar1 = thunk_FUN_1802f2810(&DAT_182d54bf8);
    uVar1 = thunk_FUN_1802c43a0(uVar1);
    uVar2 = thunk_FUN_1802f2810(&DAT_182d3b380);
    uVar3 = thunk_FUN_1802f2810(0x182d3b3a0);
    FUN_1815c6b70(uVar1,uVar3,uVar2,0);
    uVar2 = thunk_FUN_1802f2810(0x182d3b398);
                    /* WARNING: Subroutine does not return */
    FUN_18031da90(uVar1,uVar2);
  }
  uVar1 = FUN_1802c36c0(DAT_182d53428,param_2);
  iVar4 = *(int *)(param_1 + 0x48) - *(int *)(param_1 + 0x44);
  iVar5 = 0;
  if (0 < iVar4) {
    if (param_2 < iVar4) {
      FUN_18164dcb0(*(undefined8 *)(param_1 + 0x38),*(undefined4 *)(param_1 + 0x44),uVar1,0,param_2,
                    0);
      *(int *)(param_1 + 0x44) = *(int *)(param_1 + 0x44) + param_2;
      return uVar1;
    }
    FUN_18164dcb0(*(undefined8 *)(param_1 + 0x38),*(undefined4 *)(param_1 + 0x44),uVar1,0,iVar4,0);
    *(undefined8 *)(param_1 + 0x44) = 0;
    iVar5 = iVar4;
    if (param_2 <= iVar4) {
      return uVar1;
    }
  }
  do {
    uVar2 = System_Security_Cryptography_Rfc2898DeriveBytes__Func__06001568(param_1,0);
    iVar4 = param_2 - iVar5;
    if (iVar4 <= *(int *)(param_1 + 0x30)) {
      FUN_18164dcb0(uVar2,0,uVar1,iVar5,iVar4,0);
      FUN_18164dcb0(uVar2,iVar4,*(undefined8 *)(param_1 + 0x38),*(undefined4 *)(param_1 + 0x44),
                    *(int *)(param_1 + 0x30) - iVar4,0);
      *(int *)(param_1 + 0x48) = (*(int *)(param_1 + 0x48) - iVar4) + *(int *)(param_1 + 0x30);
      return uVar1;
    }
    FUN_18164dcb0(uVar2,0,uVar1,iVar5,*(undefined4 *)(param_1 + 0x30),0);
    iVar5 = iVar5 + *(int *)(param_1 + 0x30);
  } while (iVar5 < param_2);
  return uVar1;
}

