// Ghidra pseudocode; not original source or compilable C.
// ev_61a982795be46f90c2bc51fd9c0d9d5301c334451213e6ea69c0041a36607fe1

longlong System_String__TrimWhiteSpaceHelper__06000255(longlong param_1,int param_2)

{
  int iVar1;
  undefined2 uVar2;
  code *pcVar3;
  char cVar4;
  longlong lVar5;
  uint uVar6;
  uint uVar7;
  undefined2 *puVar8;
  
  if (cRam0000000182ebadb6 == '\0') {
    FUN_1802f2810(0x182d52ad0);
    LOCK();
    UNLOCK();
    cRam0000000182ebadb6 = '\x01';
  }
  uVar7 = 0;
  uVar6 = *(int *)(param_1 + 0x10) - 1;
  if (param_2 != 1) {
    if (0 < *(int *)(param_1 + 0x10)) {
      puVar8 = (undefined2 *)(param_1 + 0x14);
      do {
        if ((longlong)*(int *)(param_1 + 0x10) <= (longlong)(ulonglong)uVar7)
        goto code_r0x00018147d8fa;
        uVar2 = *puVar8;
        if (*(int *)(lRam0000000182d52ad0 + 0xe0) == 0) {
          FUN_18035c820();
        }
        cVar4 = FUN_1815cac60(uVar2,0);
        if (cVar4 == '\0') break;
        uVar7 = uVar7 + 1;
        puVar8 = puVar8 + 1;
      } while ((int)uVar7 < *(int *)(param_1 + 0x10));
    }
    if (param_2 == 0) goto code_r0x00018147d885;
  }
  uVar6 = *(int *)(param_1 + 0x10) - 1;
  lVar5 = (longlong)(int)uVar6;
  if ((int)uVar7 <= lVar5) {
    puVar8 = (undefined2 *)(param_1 + 0x14 + lVar5 * 2);
    do {
      if ((longlong)*(int *)(param_1 + 0x10) <= (longlong)(ulonglong)uVar6) {
code_r0x00018147d8fa:
        FUN_18163f740(0);
        pcVar3 = (code *)swi(3);
        lVar5 = (*pcVar3)();
        return lVar5;
      }
      uVar2 = *puVar8;
      if (*(int *)(lRam0000000182d52ad0 + 0xe0) == 0) {
        FUN_18035c820();
      }
      cVar4 = FUN_1815cac60(uVar2,0);
      if (cVar4 == '\0') break;
      uVar6 = uVar6 - 1;
      lVar5 = lVar5 + -1;
      puVar8 = puVar8 + -1;
    } while ((int)uVar7 <= lVar5);
  }
code_r0x00018147d885:
  if (cRam0000000182ebadb7 == '\0') {
    FUN_1802f2810(0x182d52f00);
    LOCK();
    UNLOCK();
    cRam0000000182ebadb7 = '\x01';
  }
  iVar1 = (uVar6 - uVar7) + 1;
  if (iVar1 != *(int *)(param_1 + 0x10)) {
    if (iVar1 == 0) {
      param_1 = **(longlong **)(lRam0000000182d52f00 + 0xb8);
    }
    else {
      param_1 = FUN_18147d0f0(param_1,uVar7,iVar1,0);
    }
  }
  return param_1;
}

