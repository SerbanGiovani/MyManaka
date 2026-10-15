// Ghidra pseudocode; not original source or compilable C.
// ev_c59272d613d3d1c26976416061e617a9cf739cc574b0469f234fb37440d7bff2

longlong IKA9nt_Encrypter_EncrypterCore__GetPasswordFromAdditionalMap__060000aa(undefined8 param_1)

{
  code *pcVar1;
  int iVar2;
  int iVar3;
  longlong lVar4;
  undefined8 uVar5;
  longlong lVar6;
  longlong lVar7;
  undefined8 uVar8;
  undefined8 uVar9;
  int iVar10;
  undefined4 auStackX_18 [4];
  ulonglong in_stack_ffffffffffffff88;
  undefined8 uStack_48;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined4 uStack_30;
  
  if (cRam0000000182ebaaca == '\0') {
    FUN_1802f2810(0x182d53300);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d64a10);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d5bfb8);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d64e78);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d52f00);
    LOCK();
    UNLOCK();
    FUN_1802f2810(0x182d64a40);
    LOCK();
    UNLOCK();
    cRam0000000182ebaaca = '\x01';
  }
  iVar10 = 0;
  uStack_30 = 0;
  if (*(int *)(lRam0000000182d5bfb8 + 0xe0) == 0) {
    FUN_18035c820(lRam0000000182d5bfb8);
  }
  lVar7 = *(longlong *)(*(longlong *)(lRam0000000182d5bfb8 + 0xb8) + 0x20);
  if (lVar7 != 0) {
    lVar7 = *(longlong *)(lVar7 + 0x18);
    if (lVar7 != 0) {
      lVar4 = FUN_180eb45b0(lVar7,param_1,uRam0000000182d64a10);
      lVar7 = **(longlong **)(lRam0000000182d52f00 + 0xb8);
      if (lVar4 != 0) {
        for (; iVar10 < *(int *)(lVar4 + 0x10); iVar10 = iVar10 + 1) {
          if (*(int *)(lRam0000000182d64e78 + 0xe0) == 0) {
            FUN_18035c820(lRam0000000182d64e78);
          }
          lVar6 = **(longlong **)(lRam0000000182d64e78 + 0xb8);
          uVar5 = FUN_18147cec0(lVar4,iVar10,1,0);
          if (lVar6 == 0) {
code_r0x00018143e2c0:
            FUN_18031dad0();
            goto code_r0x00018143e2c6;
          }
          in_stack_ffffffffffffff88 = in_stack_ffffffffffffff88 & 0xffffffff00000000;
          iVar2 = FUN_18147e670(lVar6,uVar5,0,*(undefined4 *)(lVar6 + 0x10),
                                in_stack_ffffffffffffff88,0);
          if (*(int *)(lRam0000000182d5bfb8 + 0xe0) == 0) {
            FUN_18035c820(lRam0000000182d5bfb8);
          }
          lVar6 = *(longlong *)(*(longlong *)(lRam0000000182d5bfb8 + 0xb8) + 0x18);
          if (lVar6 == 0) {
code_r0x00018143e2bb:
            FUN_18031dad0();
            goto code_r0x00018143e2c0;
          }
          lVar6 = *(longlong *)(lVar6 + 0x18);
          if (lVar6 == 0) {
            FUN_18031dad0();
            goto code_r0x00018143e2bb;
          }
          lVar6 = FUN_18147cec0(lVar6,iVar10);
          if (*(int *)(lRam0000000182d53300 + 0xe0) == 0) {
            FUN_18035c820();
          }
          iVar3 = 0;
          if (lVar6 != 0) {
            if (cRam0000000182eb54e8 == '\0') {
              FUN_1802f2810(0x182d30368);
              LOCK();
              UNLOCK();
              cRam0000000182eb54e8 = '\x01';
            }
            uStack_48 = lVar6 + 0x14;
            uStack_40 = *(undefined4 *)(lVar6 + 0x10);
            auStackX_18[0] = 0;
            uStack_3c = 0;
            in_stack_ffffffffffffff88 = 0;
            iVar3 = FUN_18162c4f0(&uStack_48,0x10,0x1000,auStackX_18,0);
          }
          uVar5 = IKA9nt_Encrypter_EncrypterCore__PasswordCharacterSubstring__060000ab
                            (iVar2 - iVar3,0);
          lVar7 = FUN_181478910(lVar7,uVar5);
        }
        if (lVar7 != 0) {
          iVar10 = FUN_18147e670(lVar7,uRam0000000182d64a40,0,*(undefined4 *)(lVar7 + 0x10),
                                 in_stack_ffffffffffffff88 & 0xffffffff00000000,0);
          if (iVar10 < 0) {
            return lVar7;
          }
code_r0x00018143e2c6:
          uVar5 = func_0x00018031d720(0x182d531f8);
          uVar5 = func_0x00018031d8c0(uVar5,1);
          FUN_1800039f0(uVar5);
          FUN_180002cd0(uVar5,0,param_1);
          uVar8 = func_0x00018031d720(0x182d5bfb8);
          func_0x0001800039e0(uVar8);
          uVar8 = func_0x00018031d720(0x182d64a38);
          uVar9 = func_0x00018031d720(0x182d64a30);
          uVar5 = FUN_18143f3a0(uVar9,uVar8,uVar5,0);
          uVar8 = func_0x00018031d720(0x182d53398);
          uVar8 = func_0x00018031da80(uVar8);
          FUN_18165bfb0(uVar8,uVar5,0);
          uVar5 = func_0x00018031d720(0x182d649e8);
          FUN_18031da90(uVar8,uVar5);
          pcVar1 = (code *)swi(3);
          lVar7 = (*pcVar1)();
          return lVar7;
        }
        FUN_18031dad0();
      }
      FUN_18031dad0();
    }
    FUN_18031dad0();
  }
  FUN_18031dad0();
  pcVar1 = (code *)swi(3);
  lVar7 = (*pcVar1)();
  return lVar7;
}

