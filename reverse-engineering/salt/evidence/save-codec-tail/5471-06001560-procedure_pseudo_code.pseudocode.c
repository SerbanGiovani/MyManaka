// Ghidra pseudocode; not original source or compilable C.
// ev_d0c30985ac4973a04eab3153335a9b917e53a13fb842bf603be3c65ac1287ca3

void System_Security_Cryptography_Rfc2898DeriveBytes___ctor__06001560
               (longlong param_1,longlong param_2,longlong param_3,int param_4,undefined8 param_5)

{
  ulonglong *puVar1;
  ulonglong uVar2;
  longlong *plVar3;
  ulonglong uVar4;
  int iVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  uint uVar9;
  bool bVar10;
  
  if (param_3 == 0) {
    uVar6 = thunk_FUN_1802f2810(&DAT_182d528c8);
    uVar6 = thunk_FUN_1802c43a0(uVar6);
    uVar7 = thunk_FUN_1802f2810(0x182d3b378);
    FUN_1815c6a10(uVar6,uVar7,0);
    uVar7 = thunk_FUN_1802f2810(0x182d3b370);
                    /* WARNING: Subroutine does not return */
    FUN_18031da90(uVar6,uVar7);
  }
  if (*(int *)(param_3 + 0x18) < 8) {
    uVar6 = thunk_FUN_1802f2810(&DAT_182d53468);
    uVar6 = thunk_FUN_1802c43a0(uVar6);
    uVar7 = thunk_FUN_1802f2810(0x182d3b378);
    uVar8 = thunk_FUN_1802f2810(0x182d3b388);
    FUN_1815c65d0(uVar6,uVar8,uVar7,0);
    uVar7 = thunk_FUN_1802f2810(0x182d3b370);
                    /* WARNING: Subroutine does not return */
    FUN_18031da90(uVar6,uVar7);
  }
  if (param_4 < 1) {
    uVar6 = thunk_FUN_1802f2810(&DAT_182d54bf8);
    uVar6 = thunk_FUN_1802c43a0(uVar6);
    uVar7 = thunk_FUN_1802f2810(&DAT_182d3b380);
    uVar8 = thunk_FUN_1802f2810(0x182d3b390);
    FUN_1815c6b70(uVar6,uVar8,uVar7,0);
    uVar7 = thunk_FUN_1802f2810(0x182d3b370);
                    /* WARNING: Subroutine does not return */
    FUN_18031da90(uVar6,uVar7);
  }
  if (param_2 == 0) {
    uVar6 = thunk_FUN_1802f2810(&DAT_182d52778);
    uVar6 = thunk_FUN_1802c43a0(uVar6);
    FUN_18161d410(uVar6,0);
    uVar7 = thunk_FUN_1802f2810(0x182d3b370);
                    /* WARNING: Subroutine does not return */
    FUN_18031da90(uVar6,uVar7);
  }
  uVar6 = FUN_1814760b0(param_3,0);
  *(undefined8 *)(param_1 + 0x18) = uVar6;
  FUN_18031d480(param_1 + 0x18);
  *(int *)(param_1 + 0x20) = param_4;
  uVar6 = FUN_1814760b0(param_2,0);
  *(undefined8 *)(param_1 + 0x10) = uVar6;
  FUN_18031d480(param_1 + 0x10);
  *(undefined8 *)(param_1 + 0x50) = param_5;
  FUN_18031d480(param_1 + 0x50);
  uVar6 = System_Security_Cryptography_Rfc2898DeriveBytes__OpenHmac__06001566(param_1,0);
  *(undefined8 *)(param_1 + 0x28) = uVar6;
  FUN_18031d480(param_1 + 0x28);
  plVar3 = *(longlong **)(param_1 + 0x28);
  if (plVar3 == (longlong *)0x0) {
                    /* WARNING: Subroutine does not return */
    FUN_18031dad0();
  }
  iVar5 = (**(code **)(*plVar3 + 0x1d8))(plVar3,*(undefined8 *)(*plVar3 + 0x1e0));
  bVar10 = cRam0000000182ebae66 == '\0';
  *(int *)(param_1 + 0x30) = iVar5 >> 3;
  if (bVar10) {
    FUN_1802f2810(&DAT_182d53428);
    LOCK();
    UNLOCK();
    cRam0000000182ebae66 = '\x01';
  }
  if (*(longlong *)(param_1 + 0x38) != 0) {
    FUN_181646f50(*(undefined8 *)(param_1 + 0x38),0,
                  *(undefined4 *)(*(longlong *)(param_1 + 0x38) + 0x18),0);
  }
  uVar6 = FUN_1802c36c0(DAT_182d53428,*(undefined4 *)(param_1 + 0x30));
  bVar10 = DAT_182eb5d50 != 0;
  *(undefined8 *)(param_1 + 0x38) = uVar6;
  if (bVar10) {
    uVar9 = (uint)(param_1 + 0x38U >> 0xc);
    puVar1 = (ulonglong *)(&DAT_182f0c920 + (ulonglong)((uVar9 & 0x1fffff) >> 6) * 8);
    do {
      uVar4 = *puVar1;
      LOCK();
      uVar2 = *puVar1;
      if (uVar4 == uVar2) {
        *puVar1 = uVar4 | 1L << (uVar9 & 0x3f);
      }
      UNLOCK();
    } while (uVar4 != uVar2);
  }
  *(undefined4 *)(param_1 + 0x48) = 0;
  *(undefined8 *)(param_1 + 0x40) = 1;
  return;
}

