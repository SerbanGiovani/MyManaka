// Ghidra pseudocode; not original source or compilable C.
// ev_6f644410e34ce81bee88de8c4a24194540a6dad882da44515def32ea2b800f97

void System_Security_Cryptography_AesManaged___ctor__06000025(longlong *param_1)

{
  ulonglong *puVar1;
  ulonglong uVar2;
  ulonglong uVar3;
  longlong *plVar4;
  code *UNRECOVERED_JUMPTABLE;
  undefined4 uVar5;
  longlong lVar6;
  uint uVar7;
  bool bVar8;
  
  if (cRam0000000182ebbeb8 == '\0') {
    FUN_1802f2810(0x182d6ab48);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d37a98);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d64e58);
    LOCK();
    UNLOCK();
    cRam0000000182ebbeb8 = '\x01';
  }
  if (*(int *)(lRam0000000182d6ab48 + 0xe0) == 0) {
    FUN_18035c820();
  }
  System_Security_Cryptography_Aes___ctor__060015b4(param_1,0);
  if (*(int *)(lRam0000000182d37a98 + 0xe0) == 0) {
    FUN_18035c820();
  }
  lVar6 = FUN_1802c43a0(uRam0000000182d64e58);
  FUN_1814a3920(lVar6,0);
  bVar8 = DAT_182eb5d50 != 0;
  param_1[9] = lVar6;
  if (bVar8) {
    uVar7 = (uint)((ulonglong)(param_1 + 9) >> 0xc);
    puVar1 = (ulonglong *)(&DAT_182f0c920 + (ulonglong)((uVar7 & 0x1fffff) >> 6) * 8);
    do {
      uVar3 = *puVar1;
      LOCK();
      uVar2 = *puVar1;
      if (uVar3 == uVar2) {
        *puVar1 = uVar3 | 1L << (uVar7 & 0x3f);
      }
      UNLOCK();
    } while (uVar3 != uVar2);
  }
  plVar4 = (longlong *)param_1[9];
  uVar5 = (**(code **)(*param_1 + 0x198))(param_1,*(undefined8 *)(*param_1 + 0x1a0));
  if (plVar4 != (longlong *)0x0) {
    (**(code **)(*plVar4 + 0x1a8))(plVar4,uVar5,*(undefined8 *)(*plVar4 + 0x1b0));
    plVar4 = (longlong *)param_1[9];
    uVar5 = (**(code **)(*param_1 + 0x218))(param_1,*(undefined8 *)(*param_1 + 0x220));
    if (plVar4 != (longlong *)0x0) {
      UNRECOVERED_JUMPTABLE = *(code **)(*plVar4 + 0x228);
                    /* WARNING: Could not recover jumptable at 0x0001816e1d48. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*UNRECOVERED_JUMPTABLE)(plVar4,uVar5,*(undefined8 *)(*plVar4 + 0x230),UNRECOVERED_JUMPTABLE);
      return;
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_18031dad0();
}

