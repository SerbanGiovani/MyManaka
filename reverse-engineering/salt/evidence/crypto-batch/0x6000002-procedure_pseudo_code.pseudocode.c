// Ghidra pseudocode; not original source or compilable C.
// ev_4c6eee946708e920568c896d443b3196675380c5b6920b93b9d95a521db923ad

/* WARNING: Removing unreachable block (ram,0x00018147cf59) */
/* WARNING: Removing unreachable block (ram,0x00018147d030) */

longlong PasswordMap__Substring__06000002(undefined8 param_1,int param_2)

{
  code *pcVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  longlong lVar5;
  longlong lVar6;
  undefined8 unaff_RDI;
  
  if (cRam0000000182ebaa7c == '\0') {
    FUN_1802f2810(0x182d64e78);
    LOCK();
    UNLOCK();
    cRam0000000182ebaa7c = '\x01';
  }
  if (*(int *)(lRam0000000182d64e78 + 0xe0) == 0) {
    FUN_18035c820();
  }
  if (**(longlong **)(lRam0000000182d64e78 + 0xb8) != 0) {
    if (param_2 < *(int *)(**(longlong **)(lRam0000000182d64e78 + 0xb8) + 0x10)) {
      if (*(int *)(lRam0000000182d64e78 + 0xe0) == 0) {
        FUN_18035c820();
      }
      lVar6 = **(longlong **)(lRam0000000182d64e78 + 0xb8);
      if (lVar6 != 0) {
FUN_18147cec0:
        if (cRam0000000182ebadb1 == '\0') {
          FUN_1802f2810(0x182d52f00);
          LOCK();
          UNLOCK();
          cRam0000000182ebadb1 = '\x01';
        }
        if (param_2 < 0) {
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
        if (*(int *)(lVar6 + 0x10) < param_2) {
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
        if (*(int *)(lVar6 + 0x10) + -1 < param_2) {
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
        if ((param_2 == 0) && (*(int *)(lVar6 + 0x10) == 1)) {
          return lVar6;
        }
        lVar5 = FUN_180320ed0(1,param_2,1,0,unaff_RDI);
        if (lVar5 != 0) {
          lVar6 = (longlong)param_2 * 2 + 0x14 + lVar6;
          if (((ulonglong)((lVar5 + 0x14) - lVar6) < 2) || ((ulonglong)(lVar6 - (lVar5 + 0x14)) < 2)
             ) {
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
    }
    else {
      if (*(int *)(lRam0000000182d64e78 + 0xe0) == 0) {
        FUN_18035c820();
      }
      lVar6 = **(longlong **)(lRam0000000182d64e78 + 0xb8);
      if (lVar6 != 0) {
        param_2 = param_2 - *(int *)(lVar6 + 0x10);
        lVar6 = **(longlong **)(lRam0000000182d64e78 + 0xb8);
        goto FUN_18147cec0;
      }
    }
  }
  FUN_18031dad0();
  pcVar1 = (code *)swi(3);
  lVar6 = (*pcVar1)();
  return lVar6;
}

