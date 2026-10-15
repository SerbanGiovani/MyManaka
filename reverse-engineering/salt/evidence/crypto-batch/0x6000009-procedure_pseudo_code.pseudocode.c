// Ghidra pseudocode; not original source or compilable C.
// ev_da8ab7c4df73b20cbd377aec5a7327830772b14dbc91b5e2df47d1b15763c1ab

/* WARNING: Removing unreachable block (ram,0x000181431473) */

void SeekableAesAssetBundle_Scripts_SeekableAesStream__Cipher__06000009
               (longlong param_1,longlong param_2,int param_3,int param_4,longlong param_5)

{
  longlong *plVar1;
  code *pcVar2;
  bool bVar3;
  int iVar4;
  longlong lVar5;
  longlong lVar6;
  longlong lVar7;
  longlong lVar8;
  ulonglong uVar9;
  byte *pbVar10;
  longlong lVar11;
  
  uVar9 = (ulonglong)param_3;
  if (cRam0000000182ebaa81 == '\0') {
    FUN_1802f2810(0x182d53428);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d64e70);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d64e68);
    LOCK();
    UNLOCK();
    cRam0000000182ebaa81 = '\x01';
  }
  plVar1 = *(longlong **)(param_1 + 0x30);
  if (plVar1 == (longlong *)0x0) {
code_r0x00018143146d:
    FUN_18031dad0();
    pcVar2 = (code *)swi(3);
    (*pcVar2)();
    return;
  }
  iVar4 = (**(code **)(*plVar1 + 0x198))(plVar1,*(undefined8 *)(*plVar1 + 0x1a0));
  iVar4 = (int)(iVar4 + (iVar4 >> 0x1f & 7U)) >> 3;
  lVar8 = param_5 % (longlong)iVar4;
  lVar11 = param_5 / (longlong)iVar4 + 1;
  lVar5 = FUN_1802c36c0(uRam0000000182d53428,iVar4);
  lVar6 = FUN_1802c36c0(uRam0000000182d53428,iVar4);
  bVar3 = false;
  if (param_3 < param_4) {
    pbVar10 = (byte *)(uVar9 + 0x20 + param_2);
    do {
      if ((!bVar3) || (lVar7 = lVar8, lVar8 % (longlong)iVar4 == 0)) {
        lVar7 = FUN_1815c7cb0(lVar11,0);
        if ((lVar7 == 0) ||
           ((FUN_181642a50(lVar7,lVar6,0,0), lVar6 == 0 || (*(longlong *)(param_1 + 0x38) == 0))))
        goto code_r0x00018143146d;
        FUN_180154b70();
        lVar7 = 0;
        if (!bVar3) {
          lVar7 = lVar8;
        }
        lVar11 = lVar11 + 1;
        bVar3 = true;
      }
      if (param_2 == 0) goto code_r0x00018143146d;
      if (*(uint *)(param_2 + 0x18) <= (uint)uVar9) {
code_r0x00018143148b:
        FUN_18031dae0();
        pcVar2 = (code *)swi(3);
        (*pcVar2)();
        return;
      }
      if (lVar5 == 0) goto code_r0x00018143146d;
      if (*(uint *)(lVar5 + 0x18) <= (uint)lVar7) goto code_r0x00018143148b;
      uVar9 = (ulonglong)((uint)uVar9 + 1);
      *pbVar10 = *pbVar10 ^ *(byte *)(lVar5 + 0x20 + lVar7);
      lVar8 = lVar7 + 1;
      pbVar10 = pbVar10 + 1;
    } while ((longlong)(pbVar10 + (-0x20 - param_2)) < (longlong)param_4);
  }
  return;
}

