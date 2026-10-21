// Ghidra pseudocode; not original source or compilable C.
// ev_434902b52fa3b8763a35fb88bd89a3ae98f583928e2df5a1f8f5bb4c7360b222

void IKA9nt_Encrypter_BridgeAssetBundleRequest__LoadDataFromMemoryAsync__06000051
               (longlong param_1,ulonglong param_2)

{
  ulonglong uVar1;
  longlong *plVar2;
  int iVar3;
  undefined8 uVar4;
  ulonglong uVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  bool bVar9;
  
  if (cRam0000000182ebaa8f == '\0') {
    FUN_1802f2810(0x182d64d10);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d53428);
    LOCK();
    UNLOCK();
    cRam0000000182ebaa8f = '\x01';
  }
  iVar6 = *(int *)(param_1 + 0x50) << 10;
  uVar4 = FUN_1802c36c0(uRam0000000182d53428,param_2 & 0xffffffff);
  bVar9 = DAT_182eb5d50 != 0;
  *(undefined8 *)(param_1 + 0x58) = uVar4;
  if (bVar9) {
    uVar8 = (uint)(param_1 + 0x58U >> 0xc);
    uVar5 = (ulonglong)((uVar8 & 0x1fffff) >> 6);
    do {
      uVar1 = *(ulonglong *)(&DAT_182f0c920 + uVar5 * 8);
      LOCK();
      bVar9 = uVar1 == *(ulonglong *)(&DAT_182f0c920 + uVar5 * 8);
      if (bVar9) {
        *(ulonglong *)(&DAT_182f0c920 + uVar5 * 8) = uVar1 | 1L << (uVar8 & 0x3f);
      }
      UNLOCK();
    } while (!bVar9);
  }
  uVar4 = FUN_1802c36c0(uRam0000000182d53428,iVar6);
  plVar2 = *(longlong **)(param_1 + 0x20);
  iVar7 = 0;
  do {
    if (plVar2 == (longlong *)0x0) {
code_r0x000181434990:
                    /* WARNING: Subroutine does not return */
      FUN_18031dad0();
    }
    iVar3 = (**(code **)(*plVar2 + 0x2e8))(plVar2,uVar4,0,iVar6,*(undefined8 *)(*plVar2 + 0x2f0));
    if (iVar3 < 1) {
      plVar2 = *(longlong **)(param_1 + 0x20);
      *(undefined1 *)(param_1 + 0x38) = 1;
      if (plVar2 != (longlong *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x00018143498d. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        (**(code **)(*plVar2 + 0x218))(plVar2,*(undefined8 *)(*plVar2 + 0x220));
        return;
      }
      goto code_r0x000181434990;
    }
    FUN_181647280(uVar4,0,*(undefined8 *)(param_1 + 0x58),iVar7,iVar3,0);
    iVar7 = iVar7 + iVar3;
    *(float *)(param_1 + 0x3c) = (float)iVar7 / (float)(longlong)param_2;
    FUN_1816a4160(*(undefined4 *)(param_1 + 0x54),0);
    plVar2 = *(longlong **)(param_1 + 0x20);
  } while( true );
}

