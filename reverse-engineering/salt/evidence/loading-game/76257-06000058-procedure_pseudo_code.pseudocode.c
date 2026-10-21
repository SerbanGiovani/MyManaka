// Ghidra pseudocode; not original source or compilable C.
// ev_a5eda87fc4d54fe59c6dc34d61869d1c9d30d9770de6cb911847b86c80c9f7b9

void __c__DisplayClass33_0___Mode2_b__0__06000058(longlong param_1)

{
  longlong lVar1;
  ulonglong uVar2;
  ulonglong uVar3;
  longlong *plVar4;
  int iVar5;
  undefined8 uVar6;
  ulonglong uVar7;
  int iVar8;
  int iVar9;
  uint uVar10;
  bool bVar11;
  
  lVar1 = *(longlong *)(param_1 + 0x10);
  uVar2 = *(ulonglong *)(param_1 + 0x18);
  if (lVar1 != 0) {
    if (cRam0000000182ebaa8f == '\0') {
      FUN_1802f2810(0x182d64d10);
      LOCK();
      UNLOCK();
      FUN_1802f2810(0x182d53428);
      LOCK();
      UNLOCK();
      cRam0000000182ebaa8f = '\x01';
    }
    iVar8 = *(int *)(lVar1 + 0x50) << 10;
    uVar6 = FUN_1802c36c0(uRam0000000182d53428,uVar2 & 0xffffffff);
    bVar11 = DAT_182eb5d50 != 0;
    *(undefined8 *)(lVar1 + 0x58) = uVar6;
    if (bVar11) {
      uVar10 = (uint)(lVar1 + 0x58U >> 0xc);
      uVar7 = (ulonglong)((uVar10 & 0x1fffff) >> 6);
      do {
        uVar3 = *(ulonglong *)(&DAT_182f0c920 + uVar7 * 8);
        LOCK();
        bVar11 = uVar3 == *(ulonglong *)(&DAT_182f0c920 + uVar7 * 8);
        if (bVar11) {
          *(ulonglong *)(&DAT_182f0c920 + uVar7 * 8) = uVar3 | 1L << (uVar10 & 0x3f);
        }
        UNLOCK();
      } while (!bVar11);
    }
    uVar6 = FUN_1802c36c0(uRam0000000182d53428,iVar8);
    iVar9 = 0;
    plVar4 = *(longlong **)(lVar1 + 0x20);
    while (plVar4 != (longlong *)0x0) {
      iVar5 = (**(code **)(*plVar4 + 0x2e8))(plVar4,uVar6,0,iVar8,*(undefined8 *)(*plVar4 + 0x2f0));
      if (iVar5 < 1) {
        plVar4 = *(longlong **)(lVar1 + 0x20);
        *(undefined1 *)(lVar1 + 0x38) = 1;
        if (plVar4 != (longlong *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x000181434d2d. Too many branches */
                    /* WARNING: Treating indirect jump as call */
          (**(code **)(*plVar4 + 0x218))(plVar4,*(undefined8 *)(*plVar4 + 0x220));
          return;
        }
        break;
      }
      FUN_181647280(uVar6,0,*(undefined8 *)(lVar1 + 0x58),iVar9,iVar5,0);
      iVar9 = iVar9 + iVar5;
      *(float *)(lVar1 + 0x3c) = (float)iVar9 / (float)(longlong)uVar2;
      FUN_1816a4160(*(undefined4 *)(lVar1 + 0x54),0);
      plVar4 = *(longlong **)(lVar1 + 0x20);
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

