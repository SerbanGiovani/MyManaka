// Ghidra pseudocode; not original source or compilable C.
// ev_10bacb236b340cd57599f97ed2983a18431026c5e7dcf2836e0444862c5893cc

void System_Security_Cryptography_Rfc2898DeriveBytes___ctor__06001563
               (longlong param_1,undefined8 param_2,longlong param_3,int param_4,undefined8 param_5)

{
  ulonglong *puVar1;
  ulonglong uVar2;
  ulonglong uVar3;
  int iVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  longlong *plVar8;
  longlong lVar9;
  undefined8 unaff_RDI;
  uint uVar10;
  bool bVar11;
  
  plVar8 = (longlong *)System_Text_Encoding__get_UTF8__060014ff(0);
  if (plVar8 == (longlong *)0x0) {
                    /* WARNING: Subroutine does not return */
    FUN_18031dad0();
  }
  lVar9 = (**(code **)(*plVar8 + 600))(plVar8,param_2,*(undefined8 *)(*plVar8 + 0x260));
  if (param_3 == 0) {
    uVar5 = thunk_FUN_1802f2810(&DAT_182d528c8);
    uVar5 = thunk_FUN_1802c43a0(uVar5);
    uVar6 = thunk_FUN_1802f2810(0x182d3b378);
    FUN_1815c6a10(uVar5,uVar6,0);
    uVar6 = thunk_FUN_1802f2810(0x182d3b370);
                    /* WARNING: Subroutine does not return */
    FUN_18031da90(uVar5,uVar6);
  }
  if (*(int *)(param_3 + 0x18) < 8) {
    uVar5 = thunk_FUN_1802f2810(&DAT_182d53468);
    uVar5 = thunk_FUN_1802c43a0(uVar5);
    uVar6 = thunk_FUN_1802f2810(0x182d3b378);
    uVar7 = thunk_FUN_1802f2810(0x182d3b388);
    FUN_1815c65d0(uVar5,uVar7,uVar6,0);
    uVar6 = thunk_FUN_1802f2810(0x182d3b370);
                    /* WARNING: Subroutine does not return */
    FUN_18031da90(uVar5,uVar6);
  }
  if (param_4 < 1) {
    uVar5 = thunk_FUN_1802f2810(&DAT_182d54bf8);
    uVar5 = thunk_FUN_1802c43a0(uVar5);
    uVar6 = thunk_FUN_1802f2810(&DAT_182d3b380);
    uVar7 = thunk_FUN_1802f2810(0x182d3b390);
    FUN_1815c6b70(uVar5,uVar7,uVar6,0);
    uVar6 = thunk_FUN_1802f2810(0x182d3b370);
                    /* WARNING: Subroutine does not return */
    FUN_18031da90(uVar5,uVar6);
  }
  if (lVar9 == 0) {
    uVar5 = thunk_FUN_1802f2810(&DAT_182d52778);
    uVar5 = thunk_FUN_1802c43a0(uVar5);
    FUN_18161d410(uVar5,0);
    uVar6 = thunk_FUN_1802f2810(0x182d3b370);
                    /* WARNING: Subroutine does not return */
    FUN_18031da90(uVar5,uVar6);
  }
  uVar5 = FUN_1814760b0(param_3,0,param_3,param_4,unaff_RDI);
  *(undefined8 *)(param_1 + 0x18) = uVar5;
  FUN_18031d480(param_1 + 0x18);
  *(int *)(param_1 + 0x20) = param_4;
  uVar5 = FUN_1814760b0(lVar9,0);
  *(undefined8 *)(param_1 + 0x10) = uVar5;
  FUN_18031d480(param_1 + 0x10);
  *(undefined8 *)(param_1 + 0x50) = param_5;
  FUN_18031d480(param_1 + 0x50);
  uVar5 = System_Security_Cryptography_Rfc2898DeriveBytes__OpenHmac__06001566(param_1,0);
  *(undefined8 *)(param_1 + 0x28) = uVar5;
  FUN_18031d480(param_1 + 0x28);
  plVar8 = *(longlong **)(param_1 + 0x28);
  if (plVar8 == (longlong *)0x0) {
                    /* WARNING: Subroutine does not return */
    FUN_18031dad0();
  }
  iVar4 = (**(code **)(*plVar8 + 0x1d8))(plVar8,*(undefined8 *)(*plVar8 + 0x1e0));
  bVar11 = cRam0000000182ebae66 == '\0';
  *(int *)(param_1 + 0x30) = iVar4 >> 3;
  if (bVar11) {
    FUN_1802f2810(&DAT_182d53428);
    LOCK();
    UNLOCK();
    cRam0000000182ebae66 = '\x01';
  }
  if (*(longlong *)(param_1 + 0x38) != 0) {
    FUN_181646f50(*(undefined8 *)(param_1 + 0x38),0,
                  *(undefined4 *)(*(longlong *)(param_1 + 0x38) + 0x18),0);
  }
  uVar5 = FUN_1802c36c0(DAT_182d53428,*(undefined4 *)(param_1 + 0x30));
  bVar11 = DAT_182eb5d50 != 0;
  *(undefined8 *)(param_1 + 0x38) = uVar5;
  if (bVar11) {
    uVar10 = (uint)(param_1 + 0x38U >> 0xc);
    puVar1 = (ulonglong *)(&DAT_182f0c920 + (ulonglong)((uVar10 & 0x1fffff) >> 6) * 8);
    do {
      uVar3 = *puVar1;
      LOCK();
      uVar2 = *puVar1;
      if (uVar3 == uVar2) {
        *puVar1 = uVar3 | 1L << (uVar10 & 0x3f);
      }
      UNLOCK();
    } while (uVar3 != uVar2);
  }
  *(undefined4 *)(param_1 + 0x48) = 0;
  *(undefined8 *)(param_1 + 0x40) = 1;
  return;
}

