// Ghidra pseudocode; not original source or compilable C.
// ev_ca64578c8e8d6f796bc03fe7abd37bdac57f0246c280d5655f8f22a4464eb7a8

/* WARNING: Removing unreachable block (ram,0x00018147cf59) */
/* WARNING: Removing unreachable block (ram,0x00018147d030) */

longlong IKA9nt_Encrypter_EncrypterCore__PasswordCharacterSubstring__060000ab(int param_1)

{
  code *pcVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  longlong lVar5;
  longlong lVar6;
  undefined8 unaff_RDI;
  
  if (cRam0000000182ebaacb == '\0') {
    FUN_1802f2810(0x182d64e78);
    LOCK();
    UNLOCK();
    cRam0000000182ebaacb = '\x01';
  }
  if (param_1 < 0) {
    if (*(int *)(lRam0000000182d64e78 + 0xe0) == 0) {
      FUN_18035c820();
    }
    if (**(longlong **)(lRam0000000182d64e78 + 0xb8) == 0) goto code_r0x00018143e44d;
    param_1 = *(int *)(**(longlong **)(lRam0000000182d64e78 + 0xb8) + 0x10) + param_1;
    lVar6 = **(longlong **)(lRam0000000182d64e78 + 0xb8);
  }
  else {
    if (*(int *)(lRam0000000182d64e78 + 0xe0) == 0) {
      FUN_18035c820(lRam0000000182d64e78);
    }
    lVar6 = **(longlong **)(lRam0000000182d64e78 + 0xb8);
    if (lVar6 == 0) {
code_r0x00018143e44d:
      FUN_18031dad0();
      pcVar1 = (code *)swi(3);
      lVar6 = (*pcVar1)();
      return lVar6;
    }
  }
  if (cRam0000000182ebadb1 == '\0') {
    FUN_1802f2810(0x182d52f00);
    LOCK();
    UNLOCK();
    cRam0000000182ebadb1 = '\x01';
  }
  if (param_1 < 0) {
    uVar2 = func_0x00018031d720(0x182d54bf8);
    uVar2 = func_0x00018031da80(uVar2);
    uVar3 = func_0x00018031d720(0x182d39f38);
    uVar4 = func_0x00018031d720(0x182d438b0);
    FUN_1815c6b70(uVar2,uVar4,uVar3,0);
    uVar3 = func_0x00018031d720(0x182d39e50);
    FUN_18031da90(uVar2,uVar3);
    pcVar1 = (code *)swi(3);
    lVar6 = (*pcVar1)();
    return lVar6;
  }
  if (*(int *)(lVar6 + 0x10) < param_1) {
    uVar2 = func_0x00018031d720(0x182d54bf8);
    uVar2 = func_0x00018031da80(uVar2);
    uVar3 = func_0x00018031d720(0x182d39e60);
    uVar4 = func_0x00018031d720(0x182d438b0);
    FUN_1815c6b70(uVar2,uVar4,uVar3,0);
    uVar3 = func_0x00018031d720(0x182d39e50);
    FUN_18031da90(uVar2,uVar3);
    pcVar1 = (code *)swi(3);
    lVar6 = (*pcVar1)();
    return lVar6;
  }
  if (*(int *)(lVar6 + 0x10) + -1 < param_1) {
    uVar2 = func_0x00018031d720(0x182d54bf8);
    uVar2 = func_0x00018031da80(uVar2);
    uVar3 = func_0x00018031d720(0x182d39e58);
    uVar4 = func_0x00018031d720(0x182d6b188);
    FUN_1815c6b70(uVar2,uVar4,uVar3,0);
    uVar3 = func_0x00018031d720(0x182d39e50);
    FUN_18031da90(uVar2,uVar3);
    pcVar1 = (code *)swi(3);
    lVar6 = (*pcVar1)();
    return lVar6;
  }
  if ((param_1 == 0) && (*(int *)(lVar6 + 0x10) == 1)) {
    return lVar6;
  }
  lVar5 = FUN_180320ed0(1,param_1,1,0,unaff_RDI);
  if (lVar5 != 0) {
    lVar6 = (longlong)param_1 * 2 + 0x14 + lVar6;
    if (((ulonglong)((lVar5 + 0x14) - lVar6) < 2) || ((ulonglong)(lVar6 - (lVar5 + 0x14)) < 2)) {
      FUN_1803a8090();
    }
    else {
      FUN_18164e250();
    }
    return lVar5;
  }
  FUN_18031dad0();
  pcVar1 = (code *)swi(3);
  lVar6 = (*pcVar1)();
  return lVar6;
}

